-- LuaLS regression fixture: inventory-layout base types and static API.

---@param base BaseLayout
---@param layout InventoryLayout
---@param gui InventoryGUI
---@param sections StdMap<string, InventorySectionGUI>
---@param inventory Inventory
---@param section InventorySection
---@param sectionGui InventorySectionGUI
---@param widget MyGUI.Widget
---@param item Item
---@param fixed GenericFixedInventoryLayout
---@param backpack BackpackInventoryLayout
---@param generic GenericInventoryLayout
---@param container BuildingContainerInventoryLayout
---@param research ResearchBuildingInventoryLayout
---@param animal AnimalInventoryLayout
---@param characterLayout CharacterInventoryLayout
---@param limbs LimbsInventoryLayout
---@param character Character
---@param trader TraderInventoryLayout
---@param furnace FurnaceInventoryLayout
---@param production ProductionInventoryLayout
---@param build BuildInventoryLayout
---@param crafting CraftingInventoryLayout
local function checkInventoryLayout(base, layout, gui, sections, inventory, section, sectionGui, widget, item,
                                    fixed, backpack, generic, container, research, animal, characterLayout,
                                    limbs, character, trader, furnace, production, build, crafting)
    base.mPrefix = base.mPrefix
    base.mLayoutName = base.mLayoutName
    assert(base.mMainWidget ~= nil)

    layout.window = layout:getWindow()
    layout.datapanel = layout:getDatapanel()
    layout.datapanel = layout:_NV_getDatapanel()
    layout.dataPanelInfos = layout.dataPanelInfos
    layout:setupDataPanelInfos("fixture")
    local widget = layout:getWidget("fixture")
    if widget then
        local resizedWidget = layout:resizeSectionWidget(100, 100, widget)
        assert(resizedWidget.width >= 0 and resizedWidget.height >= 0)
    end
    local createdSection = layout:createSectionGUI(section)
    assert(createdSection == nil or type(createdSection) == "userdata")
    layout:setSectionGUIDisabled("fixture", 100, 100)
    local resizedSection = layout:resizeSection(section, sectionGui)
    assert(resizedSection.width >= 0 and resizedSection.height >= 0)
    layout:setupSections(gui, sections, inventory)
    InventoryLayout.notifyCellSizeChanged()

    assert(type(sections:has("fixture")) == "boolean")
    assert(type(sections:remove("fixture")) == "boolean" and sections:size() >= 0)
    local sectionTable = sections:toTable()
    if sectionTable then
        local fixtureSection = sectionTable.fixture
        if fixtureSection then
            fixtureSection:update()
        end
    end
    sections:clear()

    assert(type(sectionGui:hasMouse()) == "boolean")
    local absolutePosition = sectionGui:getItemAbsolutePosition(0, 0)
    local slot = sectionGui:getPositionSlot(absolutePosition, section, true)
    local foundSlot, bestSlot = sectionGui:getBestPositionSlot(slot, section, item)
    assert(type(foundSlot) == "boolean" and bestSlot.left >= 0)
    sectionGui.widget = widget
    assert(sectionGui:getWidget() ~= nil and sectionGui.widget ~= nil)
    sectionGui:setEnabled(true)
    sectionGui:refreshIcons(section)
    sectionGui:update()

    fixed:setSize(10, 10)
    fixed:_NV_setSize(10, 10)
    backpack:setupSections(gui, sections, inventory)
    generic:setSize(10, 10, true, true)
    generic:_NV_setSize(10, 10, true, true)
    generic.arrangeButton = widget
    container:setCapacity(100, false)
    container:setupSections(gui, sections, inventory)
    container.capacityText = widget
    research.researchButton = research:getResearchButton()
    research:setupSections(gui, sections, inventory)
    animal:setupSections(gui, sections, inventory)
    characterLayout:setupSections(gui, sections, inventory)
    limbs.character = character
    limbs:setupSections(gui, sections, inventory)
    trader:setupSections(gui, sections, inventory)
    trader:notifyMouseWheel(widget, 1)
    assert(trader.scrollBackpack ~= nil)
    furnace:setupSections(gui, sections, inventory)
    assert(production ~= nil)

    build:setupSections(gui, sections, inventory)
    build:_NV_setupSections(gui, sections, inventory)
    build:setInput(0, "input", "ready")
    build:setOutput("output")
    build:setInputProgress(0, 0.5)
    build:setInputEnabled(0, true)
    build:setOutputProgress(0.5)
    build:setInputItem(0, item, true)
    build:setOutputItem(item, true)
    build.input1Item = item
    build.input2Item = item
    build.outputItem = item
    build.input1ItemIcon = widget
    build.input1NameText = widget
    build.input1Panel = widget
    build.input1Progress = widget
    build.input1StatusText = widget
    build.input2ItemIcon = widget
    build.input2NameText = widget
    build.input2Panel = widget
    build.input2Progress = widget
    build.input2StatusText = widget
    build.outputItemIcon = widget
    build.outputNameText = widget
    build.outputProgress = widget
    build.inputs = 2
    build.outputs = 1

    crafting:setupSections(gui, sections, inventory)
    crafting:_NV_setupSections(gui, sections, inventory)
    crafting:refresh()
    crafting:setOutputType(0)
    crafting:setCraftingName("fixture")
    crafting.queueBtn = crafting:getQueueButton()
    crafting.craftingName = widget
    crafting.outputType = 0
end

return checkInventoryLayout
