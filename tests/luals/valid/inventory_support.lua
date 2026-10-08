-- LuaLS regression fixture: supporting inventory values and containers.

---@param sectionItem SectionItem
---@param items OgreVector<SectionItem>
---@param cache Inventory_HasRoomCache
---@param states StdMap<GameData, boolean>
---@param item Item
---@param gameData GameData
---@param pair StringPair
---@param otherPair StringPair
---@param position iVector2
---@param otherPosition iVector2
local function checkInventorySupport(sectionItem, items, cache, states, item, gameData,
                                     pair, otherPair, position, otherPosition)
    sectionItem.item = item
    sectionItem.x = 0
    sectionItem.y = 0
    sectionItem.w = 1
    sectionItem.h = 1

    items:push(sectionItem)
    assert(items:size() >= 0)
    local values = items:toTable()
    if values then
        local first = values[1]
        if first then
            first.item = item
        end
    end
    local popped = items:pop()
    assert(popped == nil or popped.w >= 0)
    items:push(sectionItem)
    items:removeAt(1)
    items:clear()

    cache.itemStates = states
    cache:remember(gameData, true)
    assert(type(cache:knowsAbout(gameData)) == "boolean")
    assert(type(cache:hasRoomFor(gameData)) == "boolean")
    cache:modified()

    assert(type(states:has(gameData)) == "boolean")
    assert(type(states:remove(gameData)) == "boolean")
    assert(states:size() >= 0)
    local stateTable = states:toTable()
    if stateTable then
        local state = stateTable[gameData]
        assert(state == nil or type(state) == "boolean")
    end
    states:clear()

    pair.s1 = "first"
    pair.s2 = "second"
    pair.val1 = 1.0
    pair:operator_assign(otherPair)

    position.x = 1
    position.y = 2
    assert(position:getLinearValue() >= 0 and type(position:getAsString()) == "string")
    assert(type(position:operator_eq(otherPosition)) == "boolean")
    assert(type(position:operator_ne(otherPosition)) == "boolean")
    assert(type(position:operator_lt(otherPosition)) == "boolean")
    local added = position:operator_add(otherPosition)
    local nativeAdded = position + otherPosition
    assert(added.x == nativeAdded.x)
end

return checkInventorySupport
