# KenshiLua C++ Extension SDK

The KenshiLua C++ Extension SDK lets native KenshiLib DLL mods use KenshiLua's
Lua runtime without linking to `KenshiLua.lib` or `lua51.lib`. Consumers copy a
single `KenshiLua.h` header, which discovers `KenshiLua.dll` and negotiates a
versioned function table at runtime.

## Goals

- Safe runtime discovery when KenshiLua is absent or not initialized.
- A versioned C ABI with no C++ standard-library objects crossing DLL bounds.
- On-demand execution of private mod scripts and Lua source strings.
- Custom named event dispatch to handlers registered by Lua scripts.
- Registration of native functions and `require()`-able native modules.
- Marshalling of KenshiLib pointers using KenshiLua's existing metatables.
- Logging and active-mod script-path resolution.
- Compatibility with the compiler and Windows SDK used by KenshiLua.

## Runtime contract

### Availability and lifetime

`KenshiLua::IsAvailable()` is true only after `KenshiLua.dll` is loaded, the
requested SDK ABI has been negotiated, and the Lua runtime is initialized.
Calls made before initialization fail with `STATUS_NOT_INITIALIZED`. Function
pointers and the `lua_State*` become invalid when KenshiLua shuts down or its
DLL unloads.

### Threading

The Lua runtime is single-threaded. Every function that reads or changes the
Lua state must run on the thread that initialized KenshiLua. Calls from another
thread fail with `STATUS_WRONG_THREAD`. Logging and ABI discovery are the only
operations that do not require the Lua thread.

### Errors

Operations returning `KenshiLua::Status` optionally populate a `std::string`.
The string is cleared before every call and remains empty on success. The C ABI
uses caller-owned UTF-8 buffers; a supplied buffer is always NUL-terminated,
even when the message is truncated. No C++ exception is allowed to cross the C
ABI.

### Lua stack ownership

- `RunScript`, `DoString`, registration, and path operations leave the stack at
  its original height.
- `DispatchEvent(name, nargs)` consumes exactly the top `nargs` values after it
  has validated the state, event name, and argument count. It consumes them on
  both handler success and handler failure.
- `Push` and `PushObject` add exactly one value on success. A null object pointer
  pushes `nil`.
- `Check` is intended for use inside a Lua C callback and raises a Lua argument
  error on mismatch. Native code outside a Lua callback should use `Test`.

### Event errors

Event dispatch invokes a snapshot of the handlers registered when dispatch
begins. A handler may unregister itself safely. Dispatch continues after a
handler throws so other mods still receive the event, logs every handler error,
and returns the first error to the native caller. A handler returning `false`
consumes the event and stops subsequent handlers without producing an error.

### Script isolation and paths

On-demand files use the same per-script environment as startup scripts. This is
namespace isolation, not a security boundary; scripts can access the standard
libraries and KenshiLua bindings inherited by that environment.

Relative paths are normalized and searched in active-mod order. Paths may be
qualified as `<mod name>/scripts/...` to avoid collisions. Unqualified paths
return the first active-mod match. Resolution rejects traversal outside the
selected mod root. Absolute paths are accepted only when they identify a file
inside an active mod directory.

Files under `scripts/init/` are executed on startup unless their filename begins
with `_`. Files elsewhere under `scripts/` and underscore-prefixed files are
available for explicit execution without being automatically started.

### Native registrations

Registering a global function or module with an existing name replaces the
previous registration. The DLL that owns a registered callback must remain
loaded as long as the Lua state can call it. Module registration fails if
`package.preload` is unavailable or is not a table.

## Status codes

Numeric values are part of the stable ABI and must never be renumbered.

| Status | Value | Meaning |
| --- | ---: | --- |
| `STATUS_OK` | 0 | Operation completed successfully. |
| `STATUS_NOT_INITIALIZED` | 1 | KenshiLua is absent or not initialized. |
| `STATUS_INVALID_ARGUMENT` | 2 | An argument or stack count is invalid. |
| `STATUS_FILE_NOT_FOUND` | 3 | A script could not be resolved, opened, or read. |
| `STATUS_LUA_SYNTAX_ERROR` | 4 | Lua compilation failed. |
| `STATUS_LUA_RUNTIME_ERROR` | 5 | Lua execution or an event handler failed. |
| `STATUS_LUA_MEMORY_ERROR` | 6 | Lua reported an allocation failure. |
| `STATUS_UNSUPPORTED_VERSION` | 7 | The requested SDK ABI is unsupported. |
| `STATUS_WRONG_THREAD` | 8 | A Lua operation ran on the wrong thread. |
| `STATUS_UNKNOWN_ERROR` | 99 | An unexpected native failure occurred. |

## Quick start

```cpp
#include <kenshi/Character.h>
#include <KenshiLua.h>

void RunMyScript()
{
    if (!KenshiLua::IsAvailable())
        return;

    std::string error;
    KenshiLua::Status status = KenshiLua::RunScript(
        "My Mod/scripts/modules/my_logic.lua", &error);
    if (status != KenshiLua::STATUS_OK)
        KenshiLua::LogError(error);
}
```

## Custom events

Push arguments onto the shared state immediately before dispatch. Do not retain
the state or leave unrelated temporary values above the arguments.

```cpp
lua_State* L = KenshiLua::GetState();
KenshiLua::Push(L, sourceCharacter);
KenshiLua::Push(L, targetCharacter);
KenshiLua::Push(L, 75.0);

std::string error;
KenshiLua::Status status =
    KenshiLua::DispatchEvent("MyMod_OnCustomCombatAction", 3, &error);
```

```lua
Events.on("MyMod_OnCustomCombatAction", function(source, target, damage)
    print(source:getName(), target:getName(), damage)
end)
```

## Native functions and modules

The SDK exposes namespaced Lua helpers backed by the negotiated function table,
so the consumer does not link against Lua.

```cpp
static int CalculateBonus(lua_State* L)
{
    Character* character = KenshiLua::Check<Character>(L, 1);
    KenshiLua::Push(L, character ? 42.0 : 0.0);
    return 1;
}

void RegisterNativeCode()
{
    std::string error;
    KenshiLua::RegisterFunction("MyMod_CalculateBonus", CalculateBonus, &error);
}
```

```cpp
static int DoSomething(lua_State* L)
{
    KenshiLua::Push(L, "Result from native C++");
    return 1;
}

static const KenshiLua::Reg MyModuleFunctions[] = {
    { "doSomething", DoSomething },
    { NULL, NULL }
};

static int OpenMyModule(lua_State* L)
{
    KenshiLua::NewTable(L);
    KenshiLua::RegisterFunctions(L, MyModuleFunctions);
    return 1;
}

void RegisterMyModule()
{
    KenshiLua::RegisterModule("MyNativeMod", OpenMyModule);
}
```

## Public C++ API

### Lifecycle and version

- `bool IsAvailable()`
- `lua_State* GetState()`
- `std::string GetVersion()`
- `int GetVersionMajor()`
- `int GetVersionMinor()`
- `int GetVersionPatch()`

### Execution and events

- `Status RunScript(const std::string&, std::string* error = NULL)`
- `Status DoString(const std::string&, const std::string& chunk = "eval", std::string* error = NULL)`
- `Status DispatchEvent(const std::string&, int nargs = 0, std::string* error = NULL)`

### Registration

- `Status RegisterFunction(const std::string&, lua_CFunction, std::string* error = NULL)`
- `Status RegisterModule(const std::string&, lua_CFunction, std::string* error = NULL)`

### Paths and logging

- `std::string ResolveScriptPath(const std::string&)`
- `void LogInfo(const std::string&)`
- `void LogWarning(const std::string&)`
- `void LogError(const std::string&)`
- `void LogDebug(const std::string&)`

### Values and objects

- `void PushNil(lua_State*)`
- `void Push(lua_State*, double|float|int|bool|const char*|const std::string&)`
- `double GetNumber(lua_State*, int)`
- `int GetInteger(lua_State*, int)`
- `bool GetBoolean(lua_State*, int)`
- `std::string GetString(lua_State*, int)`
- `Status PushObject(lua_State*, void*, const char*)`
- `void* CheckObject(lua_State*, int, const char*)`
- `void* TestObject(lua_State*, int, const char*)`
- `Push<T>`, `Check<T>`, and `Test<T>` use `TypeTraits<T>`.

### Custom traits

Declare custom or nested types after their class definition is visible:

```cpp
KENSHILUA_REGISTER_TYPE_TRAIT(MyCustomClass, "KenshiLua.MyCustomClass")
KENSHILUA_REGISTER_TYPE_TRAIT(
    MedicalSystem::HealthPartStatus,
    "KenshiLua.MedicalSystem_HealthPartStatus")
```

The shipped traits are generated from KenshiLua's binding inventory. They must
not be maintained as a second handwritten type list.

## ABI evolution

The only symbol the header resolves directly is `KenshiLua_GetApi`. Consumers
request an ABI version and pass the size of their function-table structure.
KenshiLua validates both before copying the table. New fields may be appended
in a later ABI; existing fields and status values cannot change meaning.
