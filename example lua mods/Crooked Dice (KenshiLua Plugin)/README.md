# Crooked Dice (KenshiLua Dialogue Action Plugin)

An example mod demonstrating how to use KenshiLua to run scripts triggered by dialogue choices in Kenshi's Forgotten Construction Set (FCS).

## How it Works

The mod registers Lua scripts as sandbox actions on dialogue lines. When a player selects a specific dialogue option (e.g., placing a bet of 1,000 cats on a game of dice), Kenshi's engine executes the corresponding script.

The scripts use the global `currentDialogue` object to inspect conversation participants and perform calculations.

### Honest Gambling (`dialogue/gambling_honest.lua`)
- **Action**: Plays a fair game of dice between the player and the NPC.
- **Logic**: 
  - Rolls a random number (1 to 6) for both the player and the NPC.
  - If the player rolls higher, they win and are paid 2,000 cats (refund + 1,000 cats winnings).
  - If it's a tie, the player's 1,000 cats bet is refunded.
  - If the player rolls lower, they lose the bet and receive nothing.

### Crooked Gambling (`dialogue/gambling_crooked.lua`)
- **Action**: The player attempts to cheat at the dice game.
- **Logic**:
  - Compares the player's thieving stats (averaging `Thieving` and `Dexterity`) against the NPC's `Perception` stat to calculate a success chance (clamped between 5% and 95%).
  - Payout is processed if the cheat succeeds (payouts 2,000 cats).
  - If the cheat fails, the player is caught! The NPC shouts a warning line, marks the player character as a criminal via `npc:rememberCharacter(playerChar, "criminal")`, and immediately attacks them via `npc:attackTarget(playerChar)`.

### Deferred State Execution
Dialogue actions in Kenshi occur while characters are locked in dialogue states. To prevent state synchronization issues, both scripts call `dialogue:endDialogue(true)` immediately and defer the state modifications (giving cats, spawning lines, or initiating combat) to the next frame. This is achieved by temporarily subscribing to the `onCharsUpdate` event and unregistering the handler as soon as it executes.
