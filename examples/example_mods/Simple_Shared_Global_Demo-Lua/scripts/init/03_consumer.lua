-- 03_consumer.lua
-- Reads shared table, calls method defined in 02, and logs final results

local SimpleDemo = _G.SimpleDemo
if not SimpleDemo then
    KenshiLua.logError("[SimpleDemo] ERROR: _G.SimpleDemo missing! 01_init_state.lua must run first.")
    return
end

-- Call helper method defined by 02_producer.lua
if SimpleDemo.increment then
    SimpleDemo.increment(1)
end

SimpleDemo.addMessage("03_consumer.lua", "Final counter value is " .. tostring(SimpleDemo.counter) .. ".")

-- Dump complete history of messages shared across all 3 scripts
KenshiLua.log("=== [SimpleDemo: Initialization Summary] ===")
for i, msg in ipairs(SimpleDemo.messages) do
    KenshiLua.log(string.format("  [%d] %s", i, msg))
end
KenshiLua.log("============================================")
