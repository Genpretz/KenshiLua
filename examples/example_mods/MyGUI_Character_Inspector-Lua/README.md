# MyGUI Character Inspector (Lua Example Mod)

An example mod demonstrating how to use KenshiLua's MyGUI bindings to create custom, interactive window overlays that update dynamically in response to game events.

## Features

This mod listens for character selection events and displays a status panel on screen:

- **Information Display**: Renders the name, strength, dexterity, and toughness of the currently selected character.
- **Interactive Actions**:
  - **Heal Completely**: Invokes `inspectingChar:healCompletely()` to restore the character to full health.
  - **Set Strength 100**: Mutates the character's base stats, setting Strength to `100.0`.
- **Dynamic Visibility**: Automatically opens when a character is selected. Selecting another character updates the window with the new character's information.

## Technical Details

1. **Startup Execution**: Loaded automatically on game startup via `scripts/init/mygui_character_inspector.lua`.
2. **Event Listeners**: Registers callbacks for `Character::_NV_select`, `Character::_NV_unselect`, and `GameWorld::charsUpdate` (which handles continuous real-time updates).
3. **UI Construction**: Uses `MyGUI.createWidget` to create the inspector window (`Kenshi_WindowCX` template) on the GUI `"Window"` layer. Labels and action buttons are added as child widgets inside the window's client area.
4. **Focus & Cleanup**: Closes cleanly when the window close button is pressed, resetting keyboard focus via `MyGUI.InputManager.getInstance():resetKeyFocusWidget()`. Cleans up existing windows from previous runs on script reload to prevent duplicate widgets. For full MyGUI API details, see the [MyGUI Reference](../../../docs/MyGUIReference.md).

