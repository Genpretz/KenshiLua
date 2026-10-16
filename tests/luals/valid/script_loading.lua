local settings = require("config.settings")
local values = dofile("config/values.lua")
local localChunk, localError = loadfile("config/task.lua")

if localChunk then
    localChunk()
else
    print(localError)
end

local shared = KenshiLua.requireFromMod("Shared Framework.mod", "api.shared")
local first, second = KenshiLua.dofileFromMod("Shared Framework.mod", "api/values.lua")
local providerChunk, providerError = KenshiLua.loadfileFromMod(
    "Shared Framework.mod",
    "api/task.lua"
)

if providerChunk then
    providerChunk()
else
    KenshiLua.logWarn(providerError)
end

print(settings, values, shared, first, second)
