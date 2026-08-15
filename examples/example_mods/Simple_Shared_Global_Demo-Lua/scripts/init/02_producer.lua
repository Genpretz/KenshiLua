-- 02_producer.lua
-- Accesses shared table, adds function to it, and modifies state

local SimpleDemo = _G.SimpleDemo
if not SimpleDemo then
    KenshiLua.logError("[SimpleDemo] ERROR: _G.SimpleDemo missing! 01_init_state.lua must run first.")
    return
end

-- Attach a reusable helper method to the shared table
function SimpleDemo.increment(amount)
    local step = amount or 1
    SimpleDemo.counter = SimpleDemo.counter + step
    return SimpleDemo.counter
end

-- Use shared methods to modify state
SimpleDemo.increment(5)
SimpleDemo.addMessage("02_producer.lua", "Incremented counter by 5. Counter is now " .. tostring(SimpleDemo.counter) .. ".")
