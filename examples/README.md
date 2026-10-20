# KenshiLua Examples

This directory contains reference implementations and working example mods demonstrating the core features of KenshiLua.

## Example Mods (`example_mods/`)

Complete, loadable Kenshi mods that can be placed in Kenshi's `mods/` directory and enabled via the game launcher.

| Mod | Primary Features Demonstrated |
|---|---|
| [`Animal_Husbandry-Lua`](example_mods/Animal_Husbandry-Lua/README.md) | Comprehensive gameplay system featuring breeding timers, inventory harvesting, MyGUI custom interface windows, FCS Extended data integration, and dialogue sales. |
| [`Cpp_KenshiLib_Integration_Demo`](example_mods/Cpp_KenshiLib_Integration_Demo/README.md) | Native C++ DLL plugin interacting with KenshiLua via the header-only C++ Extension SDK (`KenshiLua.h`), native function registration, module export, and custom event dispatch. |
| [`Crooked_Dice-Lua`](example_mods/Crooked_Dice-Lua/README.md) | FCS dialogue-triggered script actions via `currentDialogue`, stat-based chance rolls, currency manipulation, and crime perception tagging. |
| [`Faction_Relations_Change_Dialogue-Lua`](example_mods/Faction_Relations_Change_Dialogue-Lua/README.md) | Manipulating bidirectional faction relationship standings through dialogue choices using `getGameWorld().factionMgr`. |
| [`Go_Prone-Lua`](example_mods/Go_Prone-Lua/README.md) | Intercepting keyboard input via `InputHandler::keyDownEvent` and toggling character posture across `PlayerInterface.selectedCharacters`. |
| [`MyGUI_Character_Inspector-Lua`](example_mods/MyGUI_Character_Inspector-Lua/README.md) | Creating responsive, interactive UI windows using MyGUI widgets (`Window`, `Button`, `TextBox`), listening to character selection events, and modifying live character stats. |

## Example Scripts (`example_scripts/`)

Self-contained Lua scripts demonstrating specific API workflows:

| Script | Description |
|---|---|
| [`mygui_example_script.lua`](example_scripts/mygui_example_script.lua) | Building custom MyGUI windows, buttons, text inputs, listboxes, and event callbacks using responsive relative coordinates (`position_real`). |
| [`recruit_npc.lua`](example_scripts/recruit_npc.lua) | Fetching the currently targeted NPC through `ForgottenGUI.selectedObject` and transferring them into the player faction and active squad. |

