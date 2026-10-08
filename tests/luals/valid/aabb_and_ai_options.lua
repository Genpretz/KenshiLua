-- LuaLS regression fixture: AABB2D geometry and AI options.

---@param bounds AABB2D
---@param other AABB2D
---@param options AIOptions
---@param data GameData
---@param point3 table
---@param end3 table
---@param rayOrigin table
---@param rayDirection table
local function checkAabbAndAiOptions(bounds, other, options, data, point3, end3, rayOrigin, rayDirection)
    bounds.x = 1
    bounds.y = 2
    bounds.x2 = 3
    bounds.y2 = 4
    bounds:setNull()
    bounds:inflate(2)
    assert(bounds:sizeX() >= 0 and bounds:sizeY() >= 0)
    assert(type(bounds:pointWithin(point3)) == "boolean")
    assert(type(bounds:intersects(other)) == "boolean")
    assert(type(bounds:intersects(point3, 1)) == "boolean")
    assert(type(bounds:intersects(point3, end3)) == "boolean")
    local point = bounds:intersects2(rayOrigin, rayDirection)
    assert(point ~= nil)

    options.healAllies = true
    options.helpAllies = true
    options.rescueAllies = false
    options.stayInBase = false
    options.feedAnimals = true
    options.shareFood = true
    options.autoSleep = false
    options.autoDitchItems = false
    options.autoSit = true
    options.ejectEnemies = false
    options.shootFirst = true
    options:load(data)
    options:save(data)
end

return checkAabbAndAiOptions
