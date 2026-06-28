# GoProne (KenshiLua Key Event Plugin)

An example mod showing how to bind keyboard shortcuts to execute in-game character actions using the KenshiLua API.

## How it Works

The mod runs on game startup and sets up a global keyboard listener to toggle the stance of the selected character.

- **Stance Toggle**: Automatically transitions a character between normal stance (`ProneState.PS_NORMAL`) and staying low/crawling (`ProneState.PS_STAYING_LOW`).
- **Hotkey**: Listens for the `V` key (virtual key code `47`).

## Implementation Details

1. **Key Registration**: Calls `registerHandler("onKeyDown", on_key_down)` to intercept keystrokes.
2. **Character Detection**: When `V` is pressed, the script fetches the `PlayerInterface` object, retrieves the `selectedCharacter` handle, and checks if a character is currently selected.
3. **Stance Change**: Queries the character's current prone state with `c:getProneState()`, then calls `c:setProneState(...)` with the opposite state to toggle it.
