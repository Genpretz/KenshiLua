-- LuaLS regression fixture: small callback, physics, state, and utility bindings.

---@param callback FactoryCallbackInterface
---@param rootObject RootObject
---@param box NxBox
---@param otherBox NxBox
---@param trigger TriggerCallback
---@param group StatGroup
---@param state StateT
---@param cell ZoneSpacialGrid_ZoneCell
---@param zone ZoneMap
---@param hit rendHit
---@param limb RobotLimbItem
---@param ptr lightuserdata
---@param point table
local function checkSmallAuxiliaryTypes(callback, rootObject, box, otherBox, trigger, group, state, cell, zone, hit, limb, ptr, point)
    callback:factoryObjectCreatedCallback(rootObject)
    assert(box:operator_assign(otherBox) == box)
    trigger:updateFrameEndMT()

    group.group = 1
    group.name = "fixture"
    state._zoneBeingLoaded = true
    state._zoneIsLoaded = false
    cell.zone = zone
    cell.cells = ptr
    hit.data = 1
    hit.hit = point

    assert(group.group == 1 and group.name == "fixture")
    assert(state._zoneBeingLoaded and not state._zoneIsLoaded)
    assert(cell.zone == zone and cell.cells == ptr)
    assert(hit.data == 1 and hit.hit ~= nil)
    assert(limb ~= nil)
end

return checkSmallAuxiliaryTypes
