# MyGUI Character Inspector (KenshiLua GUI Plugin)

An example mod demonstrating how to use KenshiLua's MyGUI bindings to create custom, interactive window overlays that update dynamically in response to game events.

## How it Works

This mod listens for character selection events and overlays a custom status panel on the screen.

- **Information Panel**: Renders the name, strength, dexterity, and toughness of the currently selected character.
- **Interactive Actions**:
  - **Heal Completely**: Invokes `inspectingChar:healCompletely()` to instantly heal the character.
  - **Set Strength 100**: Direct mutation of the character's base stats, setting their Strength to `100.0`.
- **Dynamic Visibility**: The inspector window automatically opens when you select a character and closes when you unselect them.

## Technical Details

1. **Event Listeners**: Registers callbacks for `onCharacterSelect`, `onCharacterUnselect`, and `onCharsUpdate` (which handles real-time updates).
2. **UI Construction**: Calls `KenshiLua.createWidget` to create the inspector window (`Kenshi_WindowCX` template) on the GUI "Window" layer. Labels and action buttons are child widgets added under the window client area.
3. **Focus & Cleanup**: Closes cleanly via callback when the standard window close button is pressed, resetting keyboard focus using `KenshiLua.resetKeyFocus()`. Includes safety cleanup code to destroy any residual windows from previous runs.
