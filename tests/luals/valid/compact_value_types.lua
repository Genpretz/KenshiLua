-- LuaLS regression fixture: compact, writable value bindings.

---@param sound AkSoundPosition
---@param slot CombatClass_AttackSlotManager_SlotData
---@param edge EdgeCache_Edge
---@param characteristics Faction_CharacteristicsData
---@param vector AkVector
---@param hkVector hkVector4f
---@param owner hand
local function checkCompactValueTypes(sound, slot, edge, characteristics, vector, hkVector, owner)
    sound.Position = vector
    sound.Orientation = vector
    assert(sound.Position == vector and sound.Orientation == vector)

    slot.who = owner
    slot.time = 1
    assert(slot.who == owner and slot.time == 1)

    edge.a = hkVector
    edge.b = hkVector
    assert(edge.a == hkVector and edge.b == hkVector)

    characteristics.fleeRatio_squadSize = 1
    characteristics.fleeRatio_relativeEnemy = 2
    assert(characteristics.fleeRatio_squadSize < characteristics.fleeRatio_relativeEnemy)
end

return checkCompactValueTypes
