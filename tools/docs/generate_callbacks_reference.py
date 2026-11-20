# generate_callbacks_reference.py
"""
Generates docs/CallbacksReference.md by scanning src/Callbacks.h and src/Hooks/Hooks_Registry.cpp.

Usage:
    python tools/docs/generate_callbacks_reference.py
"""

import os
import re
import pathlib

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
CALLBACKS_HEADER = PROJECT_ROOT / "src" / "Callbacks.h"
HOOKS_REGISTRY_CPP = PROJECT_ROOT / "src" / "Hooks" / "Hooks_Registry.cpp"
OUTPUT_MD = PROJECT_ROOT / "docs" / "CallbacksReference.md"

TYPE_MAP = {
    'int': 'integer',
    'short': 'integer',
    'long': 'integer',
    'unsigned int': 'integer',
    'size_t': 'integer',
    'int64_t': 'integer',
    'float': 'number',
    'double': 'number',
    'bool': 'boolean',
    'std::string': 'string',
    'const std::string&': 'string',
    'const std::string &': 'string',
    'const char*': 'string',
    'const char *': 'string',
    'const Ogre::Vector3&': 'Vector3',
    'const Ogre::Vector3 &': 'Vector3',
    'Ogre::Vector3': 'Vector3',
    'const hand&': 'hand',
    'const hand &': 'hand',
    'hand': 'hand',
    'void*': 'lightuserdata',
    'void *': 'lightuserdata',
}

def clean_cpp_type(raw_type):
    t = raw_type.strip()
    t = re.sub(r'=\s*[^,)]+', '', t).strip()
    if t in TYPE_MAP:
        return TYPE_MAP[t]
    
    t_clean = re.sub(r'\bconst\s+', '', t).strip()
    t_clean = t_clean.replace('wraps::', '').replace('MyGUI::', '').replace('Ogre::', '')
    
    m_lek = re.match(r'lektor<([^>]+)>\s*&?', t_clean)
    if m_lek:
        inner = clean_cpp_type(m_lek.group(1))
        return f"lektor<{inner}>"
        
    base = t_clean.replace('*', '').replace('&', '').strip()
    
    if base in TYPE_MAP:
        return TYPE_MAP[base]
    if base:
        return base
    return raw_type

def parse_params(params_str):
    if not params_str or params_str.strip() == 'void':
        return []
    
    parts = []
    current = []
    depth = 0
    for char in params_str:
        if char in '<(':
            depth += 1
            current.append(char)
        elif char in '>)':
            depth -= 1
            current.append(char)
        elif char == ',' and depth == 0:
            parts.append(''.join(current).strip())
            current = []
        else:
            current.append(char)
    if current:
        parts.append(''.join(current).strip())
    
    parsed = []
    for p in parts:
        p = p.strip()
        if '=' in p:
            p = p.split('=')[0].strip()
        
        m = re.match(r'^(.*?)([\*\&\s])([A-Za-z0-9_]+)$', p)
        if m:
            raw_type = (m.group(1) + m.group(2)).strip()
            name = m.group(3).strip()
            lua_type = clean_cpp_type(raw_type)
            parsed.append((name, lua_type, raw_type))
        else:
            parsed.append((p, clean_cpp_type(p), p))
    return parsed

def get_typed_lua_sig(lua_sig, params_list, ret_type_clean):
    m = re.match(r'function\s*\((.*?)\)(?:\s*->\s*(.*))?', lua_sig) if lua_sig else None
    if m:
        lua_param_names = [x.strip() for x in m.group(1).split(',') if x.strip()]
        typed_parts = []
        for i, pname in enumerate(lua_param_names):
            if i < len(params_list):
                ptype = params_list[i][1]
            else:
                ptype = "any"
            typed_parts.append(f"{pname}: {ptype}")
        sig_str = f"function({', '.join(typed_parts)})"
    else:
        typed_parts = [f"{name}: {ptype}" for name, ptype, _ in params_list]
        sig_str = f"function({', '.join(typed_parts)})"

    if ret_type_clean and ret_type_clean != 'void':
        sig_str += f" -> {ret_type_clean}"
    return sig_str

def parse_hooks_registry():
    """Extract eventName -> {installer, worker_dispatch} from g_eventHookRegistry in Hooks_Registry.cpp."""
    event_map = {}
    if not HOOKS_REGISTRY_CPP.exists():
        return event_map

    content = HOOKS_REGISTRY_CPP.read_text(encoding="utf-8", errors="ignore")
    match = re.search(r"g_eventHookRegistry\[\]\s*=\s*\{(.*?)\n\s*\};", content, re.DOTALL)
    if match:
        # Commented-out registry entries are not subscribable.
        body = re.sub(r"//[^\n]*", "", match.group(1))
        entries = re.findall(r'\{\s*"([^"]+)"\s*,\s*([^\s,\}]+)\s*(?:,\s*(\w+)\s*)?\}', body)
        for event_name, installer, threading in entries:
            event_map[event_name] = {
                "installer": installer,
                "worker_dispatch": threading == "WorkerDispatch",
            }
    return event_map

def parse_callbacks_header():
    """Parse src/Callbacks.h for callback dispatcher functions and their comment metadata."""
    if not CALLBACKS_HEADER.exists():
        return []

    content = CALLBACKS_HEADER.read_text(encoding="utf-8", errors="ignore")
    lines = content.splitlines()

    callbacks = []
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        
        # Look for dispatcher function declaration
        if line.endswith(';') and ('Call' in line) and ('Callbacks(' in line):
            # Parse function signature
            func_sig = line
            
            # Extract return type and function name
            match = re.match(r"^([\w<>:\*\&\s]+?)\s+(Call\w+Callbacks)\s*\((.*)\);$", func_sig)
            if match:
                ret_type = match.group(1).strip()
                func_name = match.group(2).strip()
                params = match.group(3).strip()

                # Gather preceding comments
                comments = []
                j = i - 1
                while j >= 0 and lines[j].strip().startswith('//'):
                    comments.insert(0, lines[j].strip()[2:].strip())
                    j -= 1

                fired_by = ""
                lua_event = ""
                lua_sig = ""
                extra_notes = []

                for c in comments:
                    if c.startswith("Fired by"):
                        fired_by = c.replace("Fired by", "").strip().rstrip('.')
                    elif c.startswith("Lua event name:"):
                        ev = c.replace("Lua event name:", "").strip().strip('"')
                        if ev:
                            lua_event = ev
                    elif c.startswith("Lua signature:"):
                        lua_sig = c.replace("Lua signature:", "").strip()
                    else:
                        extra_notes.append(c)

                parsed_params = parse_params(params)
                ret_clean = clean_cpp_type(ret_type)

                # Use parameter names from lua_sig if available and parameter count matches
                m_sig = re.match(r'function\s*\((.*?)\)', lua_sig) if lua_sig else None
                if m_sig:
                    sig_names = [x.strip() for x in m_sig.group(1).split(',') if x.strip()]
                    if len(sig_names) == len(parsed_params):
                        effective_params = [(sig_names[idx], p[1]) for idx, p in enumerate(parsed_params)]
                    else:
                        effective_params = [(p[0], p[1]) for p in parsed_params]
                else:
                    effective_params = [(p[0], p[1]) for p in parsed_params]

                typed_parts = [f"{pname}: {ptype}" for pname, ptype in effective_params]
                typed_sig = f"function({', '.join(typed_parts)})"
                if ret_clean != 'void':
                    typed_sig += f" -> {ret_clean}"

                callbacks.append({
                    'func_name': func_name,
                    'ret_type': ret_type,
                    'ret_type_clean': ret_clean,
                    'params': params,
                    'parsed_params': effective_params,
                    'fired_by': fired_by,
                    'lua_event': lua_event,
                    'lua_sig': lua_sig,
                    'typed_sig': typed_sig,
                    'notes': " ".join(extra_notes).strip()
                })
        i += 1

    return callbacks

def callback_class(callback):
    event_name = callback['lua_event']
    if not event_name:
        return "Unmapped"
    if '::' not in event_name:
        return "Global Events"
    return event_name.rsplit('::', 1)[0]

def group_callbacks_by_class(callbacks):
    groups = {}
    for callback in callbacks:
        class_name = callback_class(callback)
        groups.setdefault(class_name, []).append(callback)

    grouped = []
    for class_name in sorted(groups, key=str.casefold):
        class_callbacks = groups[class_name]
        class_callbacks.sort(key=lambda cb: (cb['lua_event'] or cb['func_name']).casefold())
        grouped.append((class_name, class_callbacks))
    return grouped

def append_callback_tables(output, callbacks, signature_heading):
    for class_name, class_callbacks in group_callbacks_by_class(callbacks):
        output.append(f"### {class_name} ({len(class_callbacks)})")
        output.append("")
        output.append(f"| Event Name | {signature_heading} |")
        output.append("| :--- | :--- |")
        for callback in class_callbacks:
            event_name = f"`{callback['lua_event']}`" if callback['lua_event'] else "*(Unmapped)*"
            signature = f"`{callback['typed_sig']}`"
            output.append(f"| {event_name} | {signature} |")
        output.append("")

def generate_markdown(callbacks, registry_map):
    output = []
    output.append("# Callbacks Reference")
    output.append("")
    output.append("> This document is automatically generated by `tools/docs/generate_callbacks_reference.py` based on `src/Callbacks.h` and `src/Hooks/Hooks_Registry.cpp`. Do not edit directly.")
    output.append("")
    output.append("## Overview")
    output.append("")
    output.append("KenshiLua provides an event-driven callback system allowing Lua scripts to subscribe to in-game events using `Events.on` and `Events.off`.")
    output.append("")
    output.append("```lua")
    output.append("-- Registering an event handler")
    output.append("local handlerId = Events.on(\"Character::declareDead\", function(self)")
    output.append("    print(\"Character died: \", self)")
    output.append("end)")
    output.append("")
    output.append("-- Unregistering when done")
    output.append("Events.off(handlerId)")
    output.append("```")
    output.append("")
    output.append("### Handler Lifetime and Cleanup")
    output.append("")
    output.append("`Events.on` returns a handler ID. Keep that ID and pass it to `Events.off` as soon as the handler is no longer needed. A handler otherwise remains active and continues receiving events.")
    output.append("")
    output.append("Register handlers that should remain active for the game session once from a `scripts/init/` file. KenshiLua removes handlers recorded for a script before running that script through the startup loader, reload commands, or Script Manager. The dialogue and world-state bridges perform the same cleanup before repeating a triggered script.")
    output.append("")
    output.append("Automatic cleanup does not happen merely because Lua code runs again through `dofile`, a chunk returned by `loadfile`, or a module function. Code using those paths must keep its handler IDs and remove them explicitly with `Events.off`.")
    output.append("")
    output.append("Handler ownership follows the file that calls `Events.on`. If a dialogue or world-state script calls a module and that module registers the handler, the handler belongs to the module, not the triggering script. The triggering script's automatic cleanup will not remove it.")
    output.append("")
    output.append("### Two Types of Callbacks")
    output.append("")
    output.append("1. **Notification Callbacks (Observer Pattern)**: Fired when an event occurs in the game. Handlers observe the event with typed arguments. Returning `false` from a handler suppresses execution of subsequent Lua handlers for that event, but does not interrupt C++ engine logic.")
    output.append("2. **Override Callbacks (Interceptor Pattern)**: Fired when the engine queries a value or object pointer (e.g. food selection, stat calculation, building availability). Handlers receive arguments (and default values). If a handler returns a non-nil value matching the expected return type, the C++ hook uses the returned value to override the engine's original calculation.")
    output.append("")
    output.append("```text")
    output.append("+------------------+      Engine function call      +-------------------------------+")
    output.append("| Kenshi Engine    | -----------------------------> | KenshiLua Hook & Dispatcher   |")
    output.append("+------------------+                                +-------------------------------+")
    output.append("                                                                    |")
    output.append("                                                   Checks thread &  | acquires Lua lock")
    output.append("                                                                    v")
    output.append("                                                    +-------------------------------+")
    output.append("                                                    | Selects matching handlers     |")
    output.append("                                                    | (Main thread: all handlers;   |")
    output.append("                                                    |  Worker: workerThread = true) |")
    output.append("                                                    +-------------------------------+")
    output.append("                                                          /                   \\")
    output.append("                                           (Notification)                      (Override)")
    output.append("                                                        v                       v")
    output.append("                                    +--------------------------+   +--------------------------+")
    output.append("                                    | Lua Observer Handlers    |   | Lua Interceptor Handlers |")
    output.append("                                    | (return false stops      |   | (non-nil return replaces |")
    output.append("                                    |  later Lua handlers)     |   |  engine return value)    |")
    output.append("                                    +--------------------------+   +--------------------------+")
    output.append("```")
    output.append("")
    output.append("### Threading")
    output.append("")
    output.append("Kenshi does several jobs at once. The **main thread** draws the screen, runs the interface and moves the game forward. **Worker threads** run in the background at the same time; the busiest one makes AI decisions, such as what a character does next, whether it may use a building, or which attack it picks.")
    output.append("")
    output.append("Your scripts run on the main thread. Most events are raised there too, and for those there is nothing more to know. Some events are raised from a worker thread, and those behave differently. Other pages call the main thread the Lua owner thread.")
    output.append("")
    output.append("#### What happens by default")
    output.append("")
    output.append("A handler registered the usual way runs only when Kenshi raises the event from the main thread. When Kenshi raises it from a worker thread, the handler is skipped:")
    output.append("")
    output.append("- a notification handler is not called;")
    output.append("- an override handler is not asked, and the game keeps its own result.")
    output.append("")
    output.append("For some events, nearly every call comes from a worker thread. `Ownerships::canIUseThisBuilding` is one: a handler registered the usual way almost never runs for it. The first time KenshiLua skips an event's handlers like this, it writes a warning naming the event to the log. If a handler seems to do nothing, look for that warning.")
    output.append("")
    output.append("#### Running a handler on a worker thread")
    output.append("")
    output.append("An event whose entry below says **Worker threads: supported** can also call your handler from the worker thread. Ask for that with a third argument to `Events.on`:")
    output.append("")
    output.append("```lua")
    output.append("Events.on(\"Ownerships::canIUseThisBuilding\", function(self, building, character, defaultVal)")
    output.append("    -- Return true or false to override, or nothing to keep the game's answer.")
    output.append("end, { workerThread = true })")
    output.append("```")
    output.append("")
    output.append("A handler registered this way runs for calls from both threads.")
    output.append("")
    output.append("#### What a worker-thread handler may do")
    output.append("")
    output.append("While your handler runs on a worker thread, the main thread does not stop. It keeps drawing the screen and updating the game at that same moment. If your handler changes something the main thread is using right then, the game can crash or its data can be damaged. This happens at random, which makes it very hard to track down. So a worker-thread handler should only look and record:")
    output.append("")
    output.append("- **Fine:** reading the handler's arguments, doing calculations, storing values in your own Lua tables, `print` and logging, and returning an override value.")
    output.append("- **Not safe:** changing the game (spawning, moving or removing characters and items; changing stats, inventories, factions or orders) and anything to do with the interface (creating, changing or removing windows and other widgets).")
    output.append("")
    output.append("To change the game in response to a worker-thread event, record what happened and act on it from a handler that runs on the main thread:")
    output.append("")
    output.append("```lua")
    output.append("local deaths = {}")
    output.append("")
    output.append("-- May run on a worker thread: only record what happened.")
    output.append("Events.on(\"Character::declareDead\", function(self)")
    output.append("    deaths[#deaths + 1] = self:getName()")
    output.append("end, { workerThread = true })")
    output.append("")
    output.append("-- Runs on the main thread: a safe place to change the game or the interface.")
    output.append("Events.on(\"GameWorld::charsUpdate\", function()")
    output.append("    for i = 1, #deaths do")
    output.append("        -- Change the game or the interface here, for example show a message.")
    output.append("        print(deaths[i] .. \" died\")")
    output.append("    end")
    output.append("    deaths = {}")
    output.append("end)")
    output.append("```")
    output.append("")
    output.append("Record plain values such as names and numbers, not the objects themselves. An object from the arguments may no longer exist by the time the main-thread handler runs.")
    output.append("")
    output.append("Your own Lua variables need no special care. KenshiLua never runs two handlers at the same moment, even on different threads, so the two handlers above cannot interfere with each other.")
    output.append("")
    output.append("Keep a worker-thread handler fast. The game waits for it to finish, and some of these events are raised hundreds or thousands of times a second, so a slow handler slows the AI down.")
    output.append("")
    output.append("#### Other details")
    output.append("")
    output.append("- When Kenshi raises an event from the main thread, all of its handlers run. From a worker thread, only the handlers registered with `workerThread` run. An override handler registered the usual way therefore changes only the main-thread calls.")
    output.append("- The same event can come from either thread, and Kenshi decides call by call. Treat every `workerThread` handler as if it always runs on a worker thread.")
    output.append("- `workerThread` on an event that does not support it logs a warning, and the handler then works like one registered the usual way.")
    output.append("- If Lua is busy on the main thread for more than 2 seconds, a waiting worker-thread call gives up and skips its handlers that one time, and a warning is logged.")
    output.append("")

    # Split into Notifications and Overrides
    notifications = []
    overrides = []

    for cb in callbacks:
        is_override = cb['ret_type'] != 'void'
        if is_override:
            overrides.append(cb)
        else:
            notifications.append(cb)

    output.append(f"## Notification Callbacks ({len(notifications)})")
    output.append("")
    append_callback_tables(output, notifications, "Lua Signature")

    output.append(f"## Override Callbacks ({len(overrides)})")
    output.append("")
    append_callback_tables(output, overrides, "Lua Signature & Expected Return")

    output.append("## Detailed Callback Documentation")
    output.append("")

    all_cbs = notifications + overrides
    for class_name, class_callbacks in group_callbacks_by_class(all_cbs):
        output.append(f"### {class_name}")
        output.append("")

        for cb in class_callbacks:
            ev_title = cb['lua_event'] if cb['lua_event'] else cb['func_name']
            plain_sig = f"function({', '.join([pname for pname, _ in cb['parsed_params']])})"
            output.append(f"#### `{ev_title}`")
            output.append("")
            output.append(f"- **Category**: {'Override / Interceptor' if cb['ret_type'] != 'void' else 'Notification / Observer'}")
            fired_clean = cb['fired_by'].removesuffix(' hook').strip() if cb['fired_by'] else ""
            if fired_clean and fired_clean != ev_title:
                output.append(f"- **Engine Hook**: `{fired_clean}`")
            output.append(f"- **Lua Signature**: `{plain_sig}`")

            if cb['parsed_params']:
                output.append("- **Parameters**:")
                for pname, ptype in cb['parsed_params']:
                    output.append(f"  - `{pname}`: `{ptype}`")
            else:
                output.append("- **Parameters**: None")

            if cb['ret_type_clean'] != 'void':
                output.append(f"- **Returns**: `{cb['ret_type_clean']}`")

            registry_entry = registry_map.get(cb['lua_event'])
            if registry_entry and registry_entry["worker_dispatch"]:
                output.append("- **Worker threads**: supported. Handlers registered with `{ workerThread = true }` also run when Kenshi calls this function on a game worker thread; see [Threading](#threading).")

            if cb['notes']:
                output.append(f"- **Notes**: {cb['notes']}")
            output.append("")

    OUTPUT_MD.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT_MD.write_text("\n".join(output), encoding="utf-8")
    print(f"Successfully generated {OUTPUT_MD} with {len(callbacks)} callbacks.")

def main():
    registry_map = parse_hooks_registry()
    callbacks = parse_callbacks_header()
    generate_markdown(callbacks, registry_map)

if __name__ == "__main__":
    main()
