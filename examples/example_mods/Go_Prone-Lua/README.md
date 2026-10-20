# Go Prone (Lua Example Mod)

An example mod demonstrating how to bind keyboard shortcuts to execute in-game character actions using the KenshiLua event system.

## Gameplay & Features

The mod runs automatically upon game startup and listens for key presses to toggle the stance of all currently selected characters:

- **Stance Toggle**: Transitions selected characters between normal standing posture ([`ProneState.PS_NORMAL`](../../../docs/EnumsReference.md#characterh)) and staying low/crawling ([`ProneState.PS_STAYING_LOW`](../../../docs/EnumsReference.md#characterh)).
- **Hotkey**: Listens for the `V` key (virtual key code `47`).
- **Multi-Character Selection**: Supports toggling stance for multiple characters selected simultaneously using `PlayerInterface.selectedCharacters` (a [`lektor<hand>`](../../../docs/ContainersReference.md#lektort) container).

## Implementation Details

1. **Startup Loading**: KenshiLua automatically loads and executes all `.lua` files placed in a mod's `scripts/init/` directory during startup.
2. **Key Event Registration**: Calls `Events.on("InputHandler::keyDownEvent", on_key_down)` to intercept keystrokes.
3. **Character Iteration**: When the `V` key is pressed, the script retrieves `getPlayerInterface().selectedCharacters` and converts the container to a Lua table via `:toTable()` to iterate through all selected character handles.
4. **Stance Mutation**: Reads each character's current state with `c:getProneState()`, then applies the toggled stance with `c:setProneState(...)`.

