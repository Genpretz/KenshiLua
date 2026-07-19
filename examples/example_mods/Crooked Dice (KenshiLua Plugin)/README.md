# Crooked Dice (KenshiLua Dialogue Action Plugin)

An example mod demonstrating how to use KenshiLua to run scripts triggered by dialogue choices in Kenshi's Forgotten Construction Set (FCS).

## How it Works

### Mod File Setup
In the FCS, we add LUA_SRIPT items to the dialogue lines by choosing the run scripts option from the dropdown menu in the dialogue window. This way the chosen script runs when the player selects the dialogue line.

### Scripts
When the dialogue hook runs the script, it passes the active dialogue context via a temporary global variable named `currentDialogue`. 

Because this variable is cleared as soon as the hook finishes executing, scripts must capture it immediately (e.g., `local dialogue = currentDialogue`) to inspect conversation participants and perform calculations.


#### Honest Gambling (`dialogue/gambling_honest.lua`)
- **Action**: Plays a fair game of dice between the player and the NPC.
- **Logic**: 
  - Rolls a random number (1 to 6) for both the player and the NPC.
  - If the player rolls higher, they win and are paid 2,000 cats (refund + 1,000 cats winnings).
  - If it's a tie, the player's 1,000 cats bet is refunded.
  - If the player rolls lower, they lose the bet and receive nothing.

#### Crooked Gambling (`dialogue/gambling_crooked.lua`)
- **Action**: The player attempts to cheat at the dice game.
- **Logic**:
  - Compares the player's thieving stats (averaging `Thieving` and `Dexterity`) against the NPC's `Perception` stat to calculate a success chance (clamped between 5% and 95%).
  - Payout is processed if the cheat succeeds (payouts 2,000 cats).
  - If the cheat fails, the player is caught! The NPC shouts a warning line, marks the player character as a criminal via `npc:rememberCharacter(playerChar, CharacterPerceptionTags_LongTerm.STOLE_FROM_ME)`.
