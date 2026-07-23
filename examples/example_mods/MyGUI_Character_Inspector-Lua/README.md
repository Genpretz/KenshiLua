# MyGUI Character Inspector (KenshiLua GUI Plugin)

An example mod demonstrating how to use KenshiLua's MyGUI bindings to create custom, interactive window overlays that update dynamically in response to game events.

## How it Works

This mod listens for character selection events and overlays a custom status panel on the screen.

- **Information Panel**: Renders the name, strength, dexterity, and toughness of the currently selected character.
- **Interactive Actions**:
  - **Heal Completely**: Invokes `inspectingChar:healCompletely()` to instantly heal the character.
  - **Set Strength 100**: Direct mutation of the character's base stats, setting their Strength to `100.0`.
- **Dynamic Visibility**: The inspector window automatically opens when you select a character. Since there isn't a way to have 0 characters selected, the mod will only close the window when another character is selected and the 2nd character's window opens instead.

## Technical Details

1. **Script Loader**: KenshiLua looks for .lua files in `./scripts/init` directory and executes these on startup
2. **Event Listeners**: Registers callbacks for `onCharacterSelect`, `onCharacterUnselect`, and `onCharsUpdate` (which handles real-time updates).
3. **UI Construction**: Calls `MyGUI.createWidget` to create the inspector window (`Kenshi_WindowCX` template) on the GUI "Window" layer. Labels and action buttons are child widgets added under the window client area.
4. **Focus & Cleanup**: Closes cleanly via callback when the standard window close button is pressed, resetting keyboard focus using `MyGUI.resetKeyFocus()`. Includes safety cleanup code to destroy any residual windows from previous runs.
