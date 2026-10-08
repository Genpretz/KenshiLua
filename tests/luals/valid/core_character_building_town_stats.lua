-- LuaLS regression fixture: core character, building, town, and stat bindings.
local character = getSelectedCharacter()
if character then
    local _animal = character:isAnimal()
    local stats = character:getStats()
    if stats then
        local _strength = stats:getStrength()
        local _dexterity = stats:getDexterity()
    end
end

---@type lightuserdata
local movableObject
local _material = Building.getEntityMaterialName(movableObject)
local _spawning = TownBase.delayedSpawningChecks()
local _stat_name = CharStats.getStatName(0)
