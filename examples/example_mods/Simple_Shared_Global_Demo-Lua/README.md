# Simple Shared Global Table Demo

Minimal example demonstrating three scripts running automatically from `scripts/init/` on game startup and sharing data through `_G.SimpleDemo`.

## File Execution Flow

1. **`scripts/init/01_init_state.lua`**
   - Creates global table `_G.SimpleDemo`.
   - Initializes `messages` table, `counter = 0`, and `addMessage()` helper.

2. **`scripts/init/02_producer.lua`**
   - Attaches `increment()` method to `_G.SimpleDemo`.
   - Increments counter by 5.
   - Logs action into `SimpleDemo.messages`.

3. **`scripts/init/03_consumer.lua`**
   - Uses `increment()` method attached by script 02.
   - Reads final counter value.
   - Iterates and prints all shared messages accumulated across all 3 scripts.
