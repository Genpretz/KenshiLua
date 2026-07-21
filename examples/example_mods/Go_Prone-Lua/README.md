# GoProne (KenshiLua Key Event Plugin)

An example mod showing how to bind keyboard shortcuts to execute in-game character actions using the KenshiLua API.

## How it Works

The mod runs on game startup and sets up a global keyboard listener to toggle the stance of all currently selected characters.

- **Stance Toggle**: Automatically transitions all selected characters between normal stance (`ProneState.PS_NORMAL`) and staying low/crawling (`ProneState.PS_STAYING_LOW`).
- **Hotkey**: Listens for the `V` key (virtual key code `47`).
- **Multi-Character Selection**: Supports toggling stance for multiple characters selected at the same time using `PlayerInterface.selectedCharacters` (a `lektor<hand>` container).

## Implementation Details

1. **Mod Loader**: KenshiLua looks for `.lua` files in `./scripts/init` directory and executes these on startup.
2. **Key Registration**: Calls `registerHandler("onKeyDown", on_key_down)` to intercept keystrokes.
3. **Character Detection**: When `V` is pressed, the script fetches `getPlayerInterface().selectedCharacters` (a `lektor<hand>` container of character handles) and converts it to a table via `:toTable()` to iterate over all selected characters.
4. **Stance Change**: Queries each character's current prone state with `c:getProneState()`, then calls `c:setProneState(...)` with the opposite state to toggle it.

