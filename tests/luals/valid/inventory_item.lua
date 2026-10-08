-- LuaLS regression fixture: InventoryItemBase methods and properties.

---@param base InventoryItemBase
---@param other InventoryItemBase
---@param item Item
---@param inventory Inventory
---@param section InventorySection
---@param data GameData
---@param container GameDataContainer
---@param state GameSaveState
---@param datapanel DatapanelGUI
---@param lines OgreVector<StringPair>
---@param position iVector2
---@param owner hand
---@param rawPointer lightuserdata
local function checkInventoryItem(base, other, item, inventory, section, data, container, state,
                                  datapanel, lines, position, owner, rawPointer)
    base:deactivate()
    base:resetAfterCopy()
    base:resetCharges(true)
    assert(base:getItemType() >= 0)
    assert(base:getItemWeightSingle() >= 0 and base:_NV_getItemWeightSingle() >= 0)
    assert(base:getItemWeight() >= 0 and base:_NV_getItemWeight() >= 0)
    local serialisedData = base:_serialise(container, 0)
    if serialisedData then
        base:_loadFromSerialise(container, serialisedData)
    end
    base:loadFromSerialise(state)
    local inventoryData = base:serialiseInInventory(container, data)
    if inventoryData then
        base:loadFromSerialiseInInventory(container, inventoryData)
    end
    base:getGUIData(datapanel, 0)
    base:_NV_getGUIData(datapanel, 0)
    assert(base:getAvgPrice() >= 0)
    assert(base:getValueSingle(true) >= 0 and base:_NV_getValueSingle(true) >= 0)
    assert(base:getValueAll(true) >= 0 and base:_NV_getValueAll(true) >= 0)
    assert(base:getMaxAffordableNum(100, true) >= 0)
    assert(base:_NV_getMaxAffordableNum(100, true) >= 0)
    assert(base:isStackable(section) >= 0)
    assert(type(base:canStackWith(other)) == "boolean")
    local owningInventory = base:getInventory()
    local nativeInventory = base:_NV_getInventory()
    assert(owningInventory == nil or owningInventory == inventory)
    assert(nativeInventory == nil or nativeInventory == inventory)
    assert(type(base:isSameAs(other)) == "boolean" and type(base:_NV_isSameAs(other)) == "boolean")
    assert(type(base:onGround()) == "boolean" and type(base:isResearchArtifact()) == "boolean")
    assert(base:getLevel() >= 0 and base:_NV_getLevel() >= 0)
    assert(base:getItemSound() ~= nil)
    assert(type(base:isStolen(true)) == "boolean" and base:merchantPriceMod() >= 0)
    base:activate(true, 0)
    base:activate(true, { 0, 0, 0 }, { 1, 0, 0, 0 }, false, 0, false)
    base:getStolenItemGUIInfo(lines)
    base:getBuyBackGUIInfo(lines)
    local saved = base:serialise(container, data, rawPointer)
    base:loadFromSerialise(saved)
    base:getTooltipData1(lines)
    base:_NV_getTooltipData1(lines)
    base:getTooltipData2(lines)
    base:_NV_getTooltipData2(lines)
    assert(base:addQuantity(1, item, section) >= 0)
    base:setProperOwner(owner)
    base:_NV_setProperOwner(owner)
    base.properOwner = base:getProperOwner()
    base._whosInventoryWeAreIn = base:_NV_getProperOwner()
    base:getTooltipTradeValue(lines)

    base.manufacturerData = data
    base.materialData = data
    base.coloriseData = data
    base.isInInventory = true
    base.inventoryPos = position
    base.inventorySection = "fixture"
    base.slotType = 0
    base.originalFullChargeAmount = 1.0
    base.chargesLeft = 1.0
    base.quality = 1.0
    base.weight = 1.0
    base.itemFunction = 0
    base.isTradeItem = false
    base.isEquipped = false
    base.isUnique = false
    base.quantity = 1
    base.itemWidth = 1
    base.itemHeight = 1
    base.deathItem = false
    base.objectType = 0
    base._isResearchArtifact = false
    base.itemGroup = rawPointer
end

return checkInventoryItem
