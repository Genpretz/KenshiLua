-- 01_init_state.lua
-- Creates and initializes the shared global table on start

_G.SimpleDemo = _G.SimpleDemo or {}
local SimpleDemo = _G.SimpleDemo

SimpleDemo.messages = {}
SimpleDemo.counter = 0

function SimpleDemo.addMessage(sender, text)
    local entry = string.format("[%s] %s", sender, text)
    table.insert(SimpleDemo.messages, entry)
    KenshiLua.log("[SimpleDemo] " .. entry)
end

SimpleDemo.addMessage("01_init_state.lua", "Shared global table _G.SimpleDemo initialized.")
