-- 00_ah_startup.lua
-- Entry point for Animal_Husbandry-Lua. Loads all modules and registers event handlers.
-- One sandbox owns all Animal_Husbandry-Lua modules and their shared local state.
local previous = _G.AnimalHusbandryLua
if previous and previous._shutdown then
    previous._shutdown()
end
_G.AnimalHusbandryLua = nil

local AH = require("ah.core")
require("ah.breeding")
local harvest = require("ah.harvest")
local sales = require("ah.sales")

local eventIds = {}
local function shutdown()
    for i = 1, #eventIds do
        Events.off(eventIds[i])
    end
    eventIds = {}
    sales.shutdown()
    harvest.shutdown()
end

math.randomseed(os.time())
AH.syncConstantsFromFCS()

-- Register here so loader cleanup attributes every handler to this startup file.
local ok, err = pcall(function()
    for _, spec in pairs(AH.eventSpecs) do
        eventIds[#eventIds + 1] = Events.on(spec.event, spec.fn)
    end
end)
if not ok then
    shutdown()
    error(err)
end

-- Only dialogue and documented console entry points cross sandbox boundaries.
-- _shutdown is internal lifecycle plumbing for the next startup invocation.
_G.AnimalHusbandryLua = {
    printConstants = AH.printConstants,
    listDefs = AH.listDefs,
    status = AH.status,
    debugPairs = AH.debugPairs,
    setDebug = AH.setDebug,
    forcePregnant = AH.forcePregnant,
    clearBreedingState = AH.clearBreedingState,
    clearDefCache = AH.clearDefCache,
    sales = { open = sales.open },
    _shutdown = shutdown,
}

AH.log("loaded")
