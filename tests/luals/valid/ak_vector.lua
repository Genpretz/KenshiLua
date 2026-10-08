-- LuaLS regression fixture: AkVector.

---@param vector AkVector
local function checkAkVector(vector)
    vector.X = 1
    vector.Y = 2
    vector.Z = 3
    assert(vector.X < vector.Y and vector.Y < vector.Z)
end

return checkAkVector
