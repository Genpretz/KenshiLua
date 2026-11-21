# Lua operator bindings

## What Lua compares

**Object identity** asks whether two Lua values refer to the same underlying
game object. **Value equality** asks whether their contents count as equal.
For example, two separate vectors with the same coordinates compare equal.

```lua
local a = NxVec3(1, 2, 3)
local b = NxVec3(1, 2, 3)
local c = NxVec3(4, 5, 6)

assert(a == b)
assert(a:operator_eq(b))
assert(a ~= c)
```

For `NxVec3`, both forms use the game's C++ equality rule. That is **SDK
equality**. `TaskRequest` also uses SDK equality for both forms. Some bindings
compare selected fields themselves. Most engine object wrappers use identity
equality by default.

**Ordering** asks which of two values comes first, such as `a < b`.
**Lua truthiness** asks whether one value passes an `if` condition. Only
`false` and `nil` fail that check. If you want the game's true-or-false answer
for an object that supports C++ boolean conversion, call `obj:operator_bool()`.

## Operator inventory

This inventory follows the class and container registration paths in
[RegisterBindings.cpp](../src/Lua/RegisterBindings.cpp). See the
[bindings reference](BindingsReference.md) for the corresponding types.

### Boolean conversion

`GameSaveState`, `hand`, `hkBool`, `physHit`, `TargetInfo`, `TaskMatch`, and
`YesNoMaybe` expose their C++ `operator bool()` as `operator_bool()` in Lua.

```lua
local result = state:operator_bool()
local sameResult = state.operator_bool(state)
```

Each call returns one Lua boolean and takes exactly one stack argument,
a receiver of the bound type. In colon syntax, call `state:operator_bool()`
with empty parentheses.

Lua treats userdata as truthy. Use `if state:operator_bool() then` to branch on
the SDK conversion. `if state then`, `not state`, and `state and other` use Lua
truthiness.

`GameData`, `RootObjectBase`, `hand`, and `InventoryGUI::InventoryTradeData`
expose the SDK method `isValid()`, which derived types can inherit. On
`hand`, `operator_bool()` and `isValid()` call separate SDK operations.

`YesNoMaybe:operator_ynm()` returns the SDK's `YesNoMaybe::ynm` conversion as a
Lua integer and takes only `self`.

### Equality and ordering

[registerClass](../src/Lua/BindingHelpers.h) defaults to comparing wrapped
C++ addresses when Lua dispatches `__eq`. A class can register a different
comparison. Lua evaluates `a ~= b` by negating `a == b`. Use
`a:operator_ne(b)` to invoke a registered inequality method directly.

| Comparison | Types and behavior |
| --- | --- |
| `a == b` and `a:operator_eq(b)` use SDK equality | `Character::RagdollMsg`, `GameWorld::SysMessage`, `hand`, `InstanceID`, `InventoryGUI::TradeResult`, `iVector2`, `KenshiLib::BinaryVersion`, `NxVec3`, `TaskRequest`, `TimeOfDay`, and `YesNoMaybe` |
| `a == b` and `a:operator_eq(b)` compare selected fields | `CombatClass::EffectData`, `EdgePathNode`, `hkResult`, `InputHandler::Command`, `NavMesh::BuildingInfo`, `SaveFileSystem::FileMessage`, `SaveInfo`, `Town::NestSpot`, and `TownBase::ResidentData` |
| `a == b` compares selected fields with no explicit equality method | `AkVector`, `AppearanceManager::Gender`, `Character::CarryMsg`, `CombatClass::AttackSlotManager::SlotData`, `Faction::CharacteristicsData`, `FarmBuilding::PlantSource`, `InventoryGUI::FenceCallbackData`, `ManagementScreen::TechItemViewData`, `MessageForB`, `Nx9Real::S`, `Terrain::BloodQueue`, `Terrain::Box`, `Terrain::Hit`, `Terrain::Info`, `TownBuildingsManager::BuildingInfo`, and `ZoneSpacialGrid::ZoneCell` |
| `a == b` and `a:operator_eq(b)` compare wrapped addresses | `AppearanceManager::AppearanceData`, `AppearanceManager::DataCategory`, `AppearanceManager::DataRange`, `AppearanceManager::DataRangePose`, `AppearanceManager::DataRangeVector`, and `FarmBuilding::Plant` |
| `a == b` explicitly compares wrapped addresses | `AkSoundPosition`, `EdgeCache`, `EdgeCache::Edge`, `FactionsScreen::FactionRelationsLine::LessSort`, `FarmBuilding::SubPlant`, `GameDataEditorWindow::DataItem`, `hkContainerHeapAllocator`, `hkContainerHeapAllocator::Allocator`, `hkMemoryAllocator::ExtendedInterface`, `hkMemoryAllocator::MemoryStatistics`, `hkTrait::TraitBool`, `MapScreen::MapRoad`, `MessageQueue::Node`, `NavInstance`, `NavMesh::NavMeshMessage`, `NavMeshGenerator::Task`, `NavMeshGenerator::TaskQueue`, `ParticlePool::ParticleData`, `Research::BuildingUpgrades`, `ZoneManager::BiomeGroundEffects`, and `ZoneSmell::SmellMsg` |
| `a == b` compares the stored `m_bool` field. `a:operator_eq(b)` calls the SDK comparison with a Lua boolean or the converted value of another `hkBool`. | `hkBool`. Stored values `1` and `2` compare unequal with `==`. Both convert to true for the SDK comparison. |
| `a:operator_eq(b)` uses SDK equality. Lua `==` uses the default pointer comparison. | `TaskMatch` takes a `Tasker` or `nil`. |
| `a:operator_ne(b)` | `hand`, `hkBool`, `hkResult`, `iVector2`, `NxVec3`, `TaskMatch`, and `YesNoMaybe`. `hkResult` compares `m_enum`. With a boolean argument, `hand` negates SDK equality. |

For comparisons across Lua types, call the method directly. `hand` accepts a
`RootObjectBase` or a boolean in both comparison methods. `hkResult` accepts a
numeric `hkResultEnum` in both methods. `InstanceID:operator_eq` accepts a string.
`YesNoMaybe:operator_eq` and `operator_ne` accept a numeric
`YesNoMaybe::ynm`, and `operator_ne` also accepts a boolean.
`TaskMatch:operator_ne` takes the same operand as its equality method.

`hkResult` compares the stored enum because the checked-out KenshiLib
headers declare the C++ operators and the import library lacks their symbols.

`TaskRequest` equality compares the task `key` and uses SDK handle equality
for the `subject`.

`NavMesh::BuildingInfo` and `SaveInfo` include the address of a member in their
comparison. `NavMesh::BuildingInfo` compares the address of `bounds` and
`SaveInfo` compares the address of `advanced`.

`NxVec3` equality is exact. Use `v:equals(other, epsilon)` for an approximate
comparison.

| Types | Explicit methods | Lua ordering |
| --- | --- | --- |
| `BuildModeWindow::BuildingCategory`, `BuildModeWindow::BuildingGroup`, `hand`, `iVector2`, `KenshiLib::BinaryVersion`, `TaskMatch` | `operator_lt(other)` | `__lt`. Lua can derive `<=` from `not (b < a)` for comparable operands. |
| `CPerfTimer`, `TimeOfDay` | `operator_lt(other)`, `operator_le(other)`, `operator_gt(other)`, `operator_ge(other)` | `__lt` and `__le` |

Lua evaluates `a > b` as `b < a` and `a >= b` as `b <= a`.
Use `table.sort(matches)` to sort a Lua table of `TaskMatch` values using the
SDK comparison.

`CPerfTimer` comparison methods accept another timer or a number of seconds
on the right. For a greater-than comparison against seconds, use
`timer:operator_gt(seconds)` or `timer:operator_ge(seconds)` to keep the timer
as the receiver. `CPerfTimerT` inherits the explicit timer comparison,
arithmetic, and assignment methods.

### Arithmetic and mutation

Arithmetic returns a new value. Compound assignment mutates the receiver
and returns it.

| Type | Lua syntax and methods |
| --- | --- |
| `CPerfTimer` | `a + b` (`operator_add`), `a - b` (`operator_sub`), `a:operator_add_assign(b)`, and `a:operator_sub_assign(b)`. The right operand can be a timer or a number of seconds. |
| `iVector2` | `a + b` (`operator_add`) adds two `iVector2` values. |
| `NxVec3` | `a + b` (`operator_add`), `a - b` (`operator_sub`), and `-a` (`operator_unm`). `a * s`, `s * a`, and `a:operator_mul(s)` scale a vector by a number. `operator_add_assign` and `operator_sub_assign` take a vector. `operator_mul_assign` takes a scalar. |
| `NxVec3` cross product | `a:operator_xor(b)` calls C++ `operator^` and returns an `NxVec3`. Lua reserves `^` for exponentiation. |
| `NxMat33` | `m * v`, `m * n`, and `m:operator_mul(rhs)` take an `NxVec3` or `NxMat33` and return the corresponding type. The vector path calls SDK `operator*` and the matrix path calls SDK `multiply`. `m:operator_mul_assign(n)` takes an `NxMat33`. |
| `SenseItr` | `it:operator_inc()` calls C++ prefix `operator++` and returns the same iterator. |

`NxVec3` subtraction and scalar multiplication calculate the result component
by component in the binding.

#### Assignment

`obj:operator_assign(value)` writes to the wrapped C++ object. Ordinary Lua
assignment such as `obj = value` rebinds the variable.

The following bindings accept an object of the same type and return the
receiver. `EdgePathNode` and `CombatTechniqueData::ImpactPoint` copy fields in
the binding. The other bindings below use C++ assignment.

- `AppearanceManager::AppearanceData`, `AppearanceManager::DataCategory`,
  `AppearanceManager::DataRange`, `AppearanceManager::DataRangePose`,
  `AppearanceManager::DataRangeVector`
- `Blackboard::TaskInfo`, `BuildModeWindow::BuildingCategory`,
  `BuildModeWindow::BuildingGroup`, `CharacterStatsWindow::Stat`,
  `CombatClass::EffectData`, `CPerfTimer`, `EdgePathNode`
- `CombatTechniqueData::ImpactPoint`, `Faction::BuildingSwaps`,
  `FactionRelations::RelationData`, `FarmBuilding::Plant`,
  `FoliageSystem::TreeData`, `GameData::ObjectInstance`, `GameDataHeader`,
  `GameDataReference`
- `InputHandler::Command`, `InstanceID`,
  `InventoryGUI::InventoryTradeData`, `ModInfo`, `NavMesh::BuildingInfo`
- `NxBox`, `NxMat33`, `NxVec3`, `OrderData`, `physHit`,
  `PreviewBuilding::Footprint`, `PreviewBuilding::FootprintNode`,
  `SaveFileSystem::FileMessage`, `SaveInfo`, `StringPair`
- `TargetWithScore`, `TaskRequest`, `TimeOfDay`, `Town::NestSpot`,
  `TownBase::ResidentData`, `VisibleObjectInfo`

| Type | Argument and return value |
| --- | --- |
| `hand` | A `hand`, a `RootObjectBase`, or an integer. Returns the receiver. |
| `hkVector4f` | An `hkVector4f`. Copies all four components and returns zero Lua values, matching the SDK's `void` assignment. |
| `LocaleInfo` | A `LocaleInfo`. Returns fresh borrowed userdata for the same C++ object. |
| `TargetInfo` | A `hand`. Returns the receiver. |
| `TaskMatch` | A `Tasker`, `nil`, or an integer. Returns the receiver. |
| `TripleInt` | A `TripleInt` or an `{x, y, z}` table. Returns the receiver. |

### Subscripts and callable instances

| Type | Read and write forms |
| --- | --- |
| `TripleInt` | `t[i]` and `t[i] = value` use indices 1–3. An out-of-range read returns `nil` and an out-of-range write raises an error. `t:operator_subscript(i[, value])` and `t:operator_index(i[, value])` use indices 0–2. |
| `NxVec3` | `v:operator_subscript(i[, value])` uses indices 0–2. Named fields `x`, `y`, and `z` are also available. Numeric bracket reads return `nil`. |
| `NxMat33` | `m(row, col[, value])` or `m:operator_call(row, col[, value])` uses row and column indices 0–2. |
| `hkVector4f` | `v(i[, value])` or `v:operator_call(i[, value])` uses component indices 0–3. |

`TripleInt` bracket access follows Lua's 1-based sequence convention.
For example, `t[1]` and `t:operator_subscript(0)` read the same element.

The explicit subscript and call forms return the element when the value
argument is omitted and return zero Lua values when writing. They raise an
error for out-of-range indices.

See the [containers reference](ContainersReference.md) for the registered
containers that support `#c` and bracket access. Sequence wrappers use
1-based indices and associative wrappers use keys or membership values.

### Raw allocation

| Type | Allocate | Free |
| --- | --- | --- |
| `HavokCharacter` | `HavokCharacter.operator_new([nbytes])` | `HavokCharacter.operator_delete(ptr)` |
| `hkVector4f` | `hkVector4f.operator_new([nbytes])` | `hkVector4f.operator_delete(ptr[, nbytes])` |

`operator_new` returns raw lightuserdata and defaults to the size of the
class. `hkVector4f.operator_delete` also defaults its size argument to the
class size. Both delete wrappers accept lightuserdata or userdata of their
bound class and return zero Lua values. Use the matching class's
`operator_delete` for the raw allocation, and pass the original size for a
custom-sized `hkVector4f` allocation.

## Verifying binding changes

Build Release x64 with `msbuild KenshiLua.vcxproj -p:Configuration=Release -p:Platform=x64`.
Exercise the affected bindings with the [in-game harness](../tools/README.md#in-game-automated-testing).
For boolean-conversion changes, cover the following cases.

1. Exercise true and false SDK conversion results where applicable.
2. Check that colon and explicit-self calls return the same single boolean.
3. Check that missing, nil, and wrong-type receivers raise Lua errors. Check
   extra arguments against the class's argument handling described above.
4. Check that method lookup exposes `operator_bool()` and the actual SDK
   `isValid()` methods where applicable.
5. Confirm that a false-converting userdata remains truthy in `if obj then`.

For changed hooks or address-dependent bindings, exercise the affected behavior
on both supported executables. Record the executable SHA-256, KenshiLib
platform and version, steps, and results.
