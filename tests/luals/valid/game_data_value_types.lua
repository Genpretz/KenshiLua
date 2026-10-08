-- LuaLS regression fixture: small GameData aggregate value types.

---@param group GameDataGroup
---@param pair GameDataValuePair
---@param data GameData
local function checkGameDataValueTypes(group, pair, data)
    group.g1 = data
    group.g2 = nil
    assert(group.g1 == data and group.g2 == nil)

    pair.data = data
    pair.val0 = 1
    assert(pair.data == data and pair.val0 == 1)
end

return checkGameDataValueTypes
