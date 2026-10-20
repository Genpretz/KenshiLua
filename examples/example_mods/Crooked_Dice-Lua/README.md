# Crooked Dice (Lua Example Mod)

An example mod demonstrating how to use KenshiLua to run scripts triggered by dialogue choices in Kenshi's Forgotten Construction Set (FCS).

## Gameplay & Location

The mod places a gambler NPC named **Dice Player** in the Bar inside the town of **The Hub**. Speaking to her offers the player two gambling options to test dialogue scripting features: playing an honest game of dice or attempting to cheat with crooked dice.

## How It Works

### FCS Setup

In the FCS, `LUA_SCRIPT` items are attached to dialogue lines by selecting **run lua script** from the reference dropdown in the dialogue window. When the player chooses that dialogue line in-game, KenshiLua intercepts the event and executes the designated `.lua` file.

### Dialogue Context

When the dialogue hook triggers a script, it provides the active dialogue context via transient global variables:

- `currentDialogue`: Pointer to the active [`Dialogue`](../../../docs/BindingsReference.md#dialogue) instance.
- `currentDialogueLine`: Pointer to the active [`DialogLineData`](../../../docs/BindingsReference.md#dialoglinedata) being processed.

Scripts capture `currentDialogue` immediately to inspect the speaker and conversation target, retrieve characters, and manipulate currency or stats.

## Scripts

### Honest Gambling (`scripts/dialogue/gambling_honest.lua`)

- **Action**: Plays a fair game of dice between the player and the NPC.
- **Logic**:
  - Rolls a random number (1 to 6) for both the player and the NPC.
  - Closes the dialogue window via `dialogue:endDialogue(true)` so characters exit the dialogue animation lock.
  - Defers payout to the next frame via a `GameWorld::charsUpdate` event listener.
  - If the player rolls higher, they win 2,000 cats (original 1,000 cat bet + 1,000 cat winnings).
  - If it is a tie, the player's 1,000 cat bet is refunded.
  - If the player rolls lower, the NPC keeps the bet.

### Crooked Gambling (`scripts/dialogue/gambling_crooked.lua`)

- **Action**: The player attempts to cheat at the dice game.
- **Logic**:
  - Compares the player's thieving capability (average of `Thieving` and `Dexterity`) against the NPC's `Perception` stat to calculate a success chance (clamped between 5% and 95%).
  - Rolls a random number between 1 and 100.
  - If the cheat succeeds, the player wins 2,000 cats.
  - If the cheat fails, the NPC catches the player, shouts a warning, and marks the player as a thief using `npc:rememberCharacter(playerChar, CharacterPerceptionTags_LongTerm.LT_STOLE_FROM_ME)`.

