# Animal Husbandry native prototype

This separate RE_Kenshi plugin owns Animal Husbandry's task definition, factory interception, worker-thread queue, and temporary delivery goals. It registers the mod-local `AnimalHusbandryNative` Lua module through the [KenshiLua C++ extension interface](../../../../docs/CppExtensionAPI.md). The mod's Lua scripts handle the engine events that KenshiLua exposes.

Source layout:

| File | Responsibility |
|---|---|
| [AnimalHusbandryNative.cpp](AnimalHusbandryNative.cpp) | Plugin startup, engine hooks, task instances, queued Lua requests, job label storage, and delivery-goal ownership |
| [Storage.cpp](Storage.cpp) | Food-reserve checks and storage capacity simulation |
| [Storage.h](Storage.h) | The two main-thread storage queries shared with the plugin |

Hooks are split between the DLL and KenshiLua events handled in [jobs.lua](../scripts/ah/jobs.lua):

| Engine function | Handled by | Reason |
|---|---|---|
| `GameWorld::charsUpdate` | Lua event handler calling `native.update()` | Runs `pump()` on the Lua thread after the original update |
| `OrderData::updateText` | Lua event handler calling `native.getJobLabel()` | Replaces the row description after the engine formats it |
| `OrdersReceiver::_NV_serialise` | DLL | Rewrites each Husbandry `pjobT<i>` handle on whichever thread saves; KenshiLua's event of the same name dispatches only on the Lua thread |
| Task factory (`TaskRepertoire::getTask`) | DLL | Constructs `HusbandryTask`, a native `Tasker` subclass |
| `Tasker::score` | DLL | Called on AI threads, where Lua cannot run |
| `OrdersReceiver::addJob`, `OrdersReceiver::_NV_loadFromSerialise` | DLL | Register the task definition before the engine dereferences it, including while a save loads |
| `TitleScreen::_NV_update` | DLL | Registers the Lua module before scripts can require it |
| `OrdersReceiver::getPermajobName` | DLL | Returns a reference to a string the task instance must own |

The main-thread update in `pump()` follows the processing order: clean up deliveries, take a snapshot of queued work, process score requests, then process action events. `takePendingWork()` releases the shared-state lock before callbacks run. Named `JobEvent` values describe the score/start/run/stop protocol; they are internal to the DLL and do not add engine `TaskType` values. `ActionState` survives its executing task while an event still holds a reference.

Build from the KenshiLua repository root with the MSVC2010 / Windows 7.1 SDK toolchain:

```powershell
msbuild examples/example_mods/Animal_Husbandry-Lua/native/AnimalHusbandryNative.vcxproj -p:Configuration=Release -p:Platform=x64
```

The project uses the repository's `extern/KenshiLib` SDK and writes `plugin/AnimalHusbandryNative.dll` in the mod folder. It links KenshiLib, Ogre, and KenshiLua's LuaJIT `lua51` runtime. Module functions use LuaJIT's stack API for argument/return handling, including coroutine calls. The delivery function requires the main Lua state. Module registration, typed engine objects, logging, and main-thread event dispatch use KenshiLua's extension interface. Install the built DLL alongside this mod's `RE_Kenshi.json`, scripts, FCS records, and assets.

Only these Kenshi 1.0.65 executables have validated native entry points:

| Platform | Executable SHA-256 | Definition registration RVA | Task factory RVA |
|---|---|---|---|
| GOG | `2DEFC287C813798B9682B93ACF68D340DA895CF5164D342145BA0FAEB9024681` | `0x60E280` | `0x32E720` |
| Steam | `504B362CDE850D56AFB1CEA6F5B7B0EE014D9DD7B47E188599D91C804502CD3E` | `0x60DF70` | `0x32EB90` |

The DLL checks KenshiLib's detected version/platform and both native entry-point instruction prefixes before installation. Other hooks resolve SDK declarations through KenshiLib. The fixed mod task ID is `0x41480001`; stock task IDs pass through unchanged. Remove saved Husbandry jobs before removing the DLL.

`Tasker.h` must precede `AI.h`: the game's AI member pointers occupy 24 bytes. Compile-time checks verify `TaskData`, its score-function offset, and `Tasker` against the observed layouts. Kenshi allocates the shared task definition; executing tasks use Ogre allocation and native virtual destruction.

AI workers enqueue score/action requests using copied handles. Only the main game thread resolves those handles and dispatches `AnimalHusbandry_JobScore`, `AnimalHusbandry_JobStart`, `AnimalHusbandry_JobRun`, and `AnimalHusbandry_JobStop`. Request tokens accept a synchronous score/completion response from the mod's Lua handlers. Missing handlers yield zero score or complete the current action. Script reload invalidates earlier requests without retaining Lua closures or engine Tasker pointers in Lua.

Delivery uses the stock `FILL_MACHINE` temporary goal, allowing the native planner to choose movement and transfer actions. The DLL tracks only goals it inserted and removes them after delivery, cancellation of that assignment, missing storage, or a script-generation change. An equivalent pre-existing temporary goal remains owned by its original caller.

The food-reserve check matches `AI::haveSomeResourcesFor`: a food product is not deliverable when the worker has exactly one edible food stack across their inventory and backpack. That item is excluded from pending cargo, and any owned delivery goal that becomes ineligible is removed.

Collection and hauling are separate phases. The saved cargo manifest can contain several products, and hauling drains the manifest before collection resumes. Capacity checks pack accepted carried items and one additional product into local copies of the storage inventory grids, accounting for footprints, stacking compatibility, section limits, and backpack contents. No engine inventory is mutated by the capacity query. `InventorySection::hasRoomForItem` alone cannot validate a batch: its quantity argument does not reserve multiple footprints. These local checks do not reserve capacity against other workers filling the same container concurrently.

Jobs share the fixed task ID but use distinct copied animal handles as assignment identities. Group/outpost/cargo metadata lives in the worker's appearance save data, keyed by that identity. The saved group snapshot drives eligibility; the original animal does not have to remain alive or in the player faction. The engine saves each `pjobT<i>` handle with redirection, which can replace it with a different squad handle; the DLL's `OrdersReceiver::_NV_serialise` hook stores the raw identity again without redirection.

Each native task instance owns its group label. The DLL returns it from `OrdersReceiver::getPermajobName`, and the mod's `OrderData::updateText` handler substitutes it for the task description in the OrdersPanel row. The row retains its native colour/row-number prefix and shows the group label instead of an individual target name. Stock tasks pass through unchanged. Lua refreshes labels after loading or reloading scripts. Score caches, action plans, and delivery cleanup distinguish individual assignments on the same worker.