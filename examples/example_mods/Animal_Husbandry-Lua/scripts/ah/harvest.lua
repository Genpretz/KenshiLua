-- harvest.lua
-- Husbandry context-menu action, product harvesting, and animal details window.
-- Product references use val0 for quantity, val1 for cooldown days, and val2 for sex.
-- Cooldowns are saved on each animal as AH_NextHarvest_<item string ID>.
-- Incomplete harvests save remaining items as AH_RemainingHarvest_<item string ID>.

local AH = require("ah.core")

local ROW_NAME = "AH_HusbandryRow"
local BUTTON_NAME = "AH_HusbandryButton"
local WINDOW_NAME = "AH_HusbandryWindow"
local NEXT_HARVEST_PREFIX = "NextHarvest_"
local REMAINING_HARVEST_PREFIX = "RemainingHarvest_"

local LAYOUT_FILE = "AH_HusbandryWindow.layout"
local ROW_HEIGHT = 32
local ROW_STEP = 36
local BUTTON_WIDTH = 96
local SCROLLBAR_WIDTH = 20
local BUTTON_MARGIN = 8
local BUTTON_GAP = 8
local DEFAULT_LEFT, DEFAULT_TOP = 220, 160

AH.husbandrySerial = AH.husbandrySerial or 0

local function hcfg()
    return AH.config.harvest
end

-- State of the open window: handles rather than characters, so a character that
-- despawns while the window is open resolves to nil instead of a dangling pointer.
---@class AnimalHusbandryLuaWindowState
---@field target hand
---@field harvester hand|nil
---@field prefix string
---@field layout MyGUI.Widget[]|nil
---@field root MyGUI.Widget|nil
---@field rows table[]
---@field generalPanel DatapanelGUI|nil
---@field husbandryPanel DatapanelGUI|nil
---@field infoPanels DatapanelGUI[]
---@field infoText table<string, string>
---@field portrait MyGUI.ImageBox|nil
---@field nameText MyGUI.Widget|nil
---@field productsArea MyGUI.ScrollView|nil
---@type AnimalHusbandryLuaWindowState|nil
local windowState = nil

local menuState = { target = nil, harvester = nil, focused = false }

-- Rules

local function nextHarvestKey(product)
    return NEXT_HARVEST_PREFIX .. tostring(product.itemID)
end

local function remainingHarvestKey(product)
    return REMAINING_HARVEST_PREFIX .. tostring(product.itemID)
end

local function productName(product)
    return tostring(product.name), product.data
end

-- Returns true if an animal of this sex gives the product, or false and a reason.
local function sexAllows(product, female)
    if product.sex == "female" and not female then
        return false, "females only"
    elseif product.sex == "male" and female then
        return false, "males only"
    elseif product.sex ~= "female" and product.sex ~= "male" and product.sex ~= "both" then
        return false, "invalid sex value in FCS"
    end
    return true
end

-- Animals cannot perform husbandry work. Skeletons and other non-animal player characters remain valid
local function isEligibleHarvester(c)
    return c and c:isPlayerCharacter() and not c:isAnimal()
end

local function formatHarvestCooldown(days)
    if days < 0.96 then
        local hrs = math.max(1, math.ceil(days * 24))
        return hrs .. (hrs == 1 and " hr" or " hrs")
    end
    return string.format("%.1f days", days)
end

-- Returns true, or false and the reason the product cannot be harvested now.
local function canHarvest(entry, harvester, product, now)
    local c = entry.char
    if c:isDead() then
        return false, "dead"
    end
    if c:isInCombatMode(true, true) then
        return false, "in combat"
    end
    if not product.data then
        return false, "item unavailable"
    end
    if AH.age(entry.animal) < hcfg().minAge then
        return false, "too young"
    end
    local sexOk, sexReason = sexAllows(product, AH.isFemale(c))
    if not sexOk then
        return false, sexReason
    end
    local remaining = AH.getValue(c, remainingHarvestKey(product))
    if not (remaining and remaining > 0) then
        local nextAt = AH.getValue(c, nextHarvestKey(product))
        if nextAt and now < nextAt then
            return false, formatHarvestCooldown(nextAt - now)
        end
    end
    if not harvester then
        return false, "no person"
    end
    if not isEligibleHarvester(harvester) then
        return false, "need humanoid"
    end
    if harvester:isDead() or harvester:isUnconcious() then
        return false, "harvester down"
    end
    if AH.distance(harvester, c) > hcfg().maxDistance then
        return false, "too far"
    end
    if not harvester:hasRoomForItem(product.data) then
        return false, "no inventory space"
    end
    return true
end

-- Creates the product's items in the harvester's inventory or backpack and starts its cooldown.
-- Returns true, or false and a reason.
local function harvest(entry, harvester, product)
    local now = AH.currentDay()
    local ok, reason = canHarvest(entry, harvester, product, now)
    if not ok then
        return false, reason
    end

    local name, data = productName(product)
    local factory = getRootObjectFactory()
    if not factory then
        return false, "object factory is unavailable"
    end

    local rem = AH.getValue(entry.char, remainingHarvestKey(product))
    local total = math.max(1, product.amount or 1)
    local available = (rem and rem > 0) and math.min(math.floor(rem), total) or total

    local given = 0
    for i = 1, available do
        if not harvester:hasRoomForItem(data) then
            break
        end
        local item = factory:createItem(data, nil, nil, nil, -1, nil)
        if not item then
            break
        end
        -- giveItem attempts to place the item in the character's inventory first,
        -- and if full, in their equipped backpack. destroyOnFail cleans up the
        -- temporary item if neither has space.
        local gave = harvester:giveItem(item, false, true)
        if not gave then
            break
        end
        given = given + 1
    end

    if given == 0 then
        return false, "no inventory space"
    end

    local left = available - given
    if left <= 0 then
        AH.clearValue(entry.char, remainingHarvestKey(product))
        AH.setValue(entry.char, nextHarvestKey(product), now + math.max(0, product.days or 1))
    else
        AH.setValue(entry.char, remainingHarvestKey(product), left)
    end

    local count = given > 1 and (given .. " x ") or ""
    if left > 0 then
        AH.notify(string.format("%s harvested %s%s from %s (%d remaining - inventory full).",
            harvester:getName(), count, name, entry.char:getName(), left))
    else
        AH.notify(string.format("%s harvested %s%s from %s.",
            harvester:getName(), count, name, entry.char:getName()))
    end
    return true
end

-- Husbandry window

local function resolveWindowCharacters()
    if not windowState then
        return nil, nil
    end
    local animal = windowState.target:getCharacter()
    local harvester = windowState.harvester and windowState.harvester:getCharacter() or nil
    return animal, harvester
end

local function infoLines(entry, animal, harvester, now)
    if not entry then
        return { { "Animal", "no longer available" } }, {}
    end
    local price = (AH.priceOf and AH.priceOf(entry))
        or (AH.sales and AH.sales.priceOf and AH.sales.priceOf(entry))
        or 0
    local valText = (AH.moneyText and AH.moneyText(price))
        or ("c." .. tostring(math.floor(price)))
    local general = {
        { "Race", tostring(entry.raceName) },
        { "Sex", AH.isFemale(animal) and "Female" or "Male" },
        { "Age", AH.ageText(entry) },
        { "Value", valText },
    }
    local husbandry = {}
    if entry.def and entry.def.matingGroup and entry.def.matingGroup ~= "" then
        husbandry[#husbandry + 1] = { "Group", tostring(entry.def.matingGroup) }
    end
    husbandry[#husbandry + 1] = { "Breeding", AH.describeBreeding and AH.describeBreeding(entry, now) or "" }
    husbandry[#husbandry + 1] = { "Harvester", harvester and tostring(harvester:getName()) or "unavailable" }
    return general, husbandry
end

-- Rebuilds the details datapanel only when its text changed, so it does not flicker.
local function fillInfoPanel(panel, cacheKey, lines)
    local state = windowState
    if not state or not panel then
        return
    end
    local parts = {}
    for i = 1, #lines do
        parts[#parts + 1] = lines[i][1] .. "=" .. lines[i][2]
    end
    local text = table.concat(parts, "\n")
    if text == state.infoText[cacheKey] then
        return
    end
    state.infoText[cacheKey] = text
    panel:clear()
    for i = 1, #lines do
        panel:setLine(lines[i][1], lines[i][2], 0, false, true)
    end
    panel:show(true)
end

local function refreshWindow()
    local w = AH.husbandryWindow
    if not w or not windowState then
        return
    end
    local animal, harvester = resolveWindowCharacters()
    local entry = animal and AH.animalEntry(animal)
    local now = AH.currentDay()

    if windowState.nameText then
        windowState.nameText:setCaption(animal and tostring(animal:getName()) or "")
    end
    local general, husbandry = infoLines(entry, animal, harvester, now)
    fillInfoPanel(windowState.generalPanel, "general", general)
    fillInfoPanel(windowState.husbandryPanel, "husbandry", husbandry)

    for i = 1, #windowState.rows do
        local row = windowState.rows[i]
        if entry then
            local ok, reason = canHarvest(entry, harvester, row.product, now)
            local rem = AH.getValue(entry.char, remainingHarvestKey(row.product))
            local label = row.name
            if rem and rem > 0 then
                label = string.format("%s (%d left)", row.name, math.floor(rem))
            end
            row.status:setCaption(label .. ": " .. (ok and "ready" or reason))
            row.button:setEnabled(ok and true or false)
        else
            row.status:setCaption(row.name)
            row.button:setEnabled(false)
        end
    end
end

local function destroyWindow()
    if windowState and windowState.root then
        local l, t = windowState.root:getPosition()
        AH.husbandryWindowPos = { left = l, top = t }
    elseif AH.husbandryWindow then
        local l, t = AH.husbandryWindow:getPosition()
        AH.husbandryWindowPos = { left = l, top = t }
    end
    if windowState and windowState.infoPanels then
        local gui = getForgottenGUI()
        if gui then
            for i = 1, #windowState.infoPanels do
                local ok, err = pcall(gui.destroy, gui, windowState.infoPanels[i])
                if not ok then
                    AH.log("Husbandry window: could not destroy a datapanel: " .. tostring(err))
                end
            end
        end
        windowState.infoPanels = {}
    end
    if windowState and windowState.layout then
        local ok, err = pcall(function()
            MyGUI.LayoutManager.getInstance():unloadLayout(windowState.layout)
        end)
        if not ok then
            AH.log("Husbandry window: could not unload layout: " .. tostring(err))
        end
        windowState.layout = nil
    elseif AH.husbandryWindow then
        pcall(function() AH.husbandryWindow:destroy() end)
    end
    AH.husbandryWindow = nil
    windowState = nil
end

local function createLabel(parent, x, y, w, h, name)
    local lbl = assert(parent:createWidget(
        "TextBox", "Kenshi_TextboxStandardText", x, y, w, h, MyGUI.Align.Default, name))
    lbl:setProperty("TextAlign", "Left VCenter")
    return lbl
end

local function rebuildProducts(entry)
    local state = windowState
    if state == nil or state.target == nil or state.target:isNull() then
        -- The target despawned while the window was open.
        destroyWindow()
        return
    end

    local productsArea = state.productsArea
    if not productsArea then
        AH.log("Husbandry window: products area is missing")
        return
    end

    local targetHandle = state.target
    state.rows = {}

    -- Replace product rows when switching animals, including any layout previews.
    while productsArea:getChildCount() > 0 do
        local child = productsArea:getChildAt(0)
        -- The child count above guarantees that index 0 exists.
        ---@cast child -nil
        child:destroy()
    end

    local products = (entry.def and entry.def.products) or {}
    local maxVisible = (hcfg() and hcfg().maxVisibleProducts) or 4
    local rowCount = #products

    local _, _, productsWidth, viewHeight = productsArea:getCoord()
    if productsWidth <= 0 then productsWidth = 292 end
    if viewHeight <= 0 then viewHeight = 168 end

    local needsScroll = (rowCount > maxVisible) or (rowCount * ROW_STEP > viewHeight)
    local scrollbarMargin = needsScroll and (SCROLLBAR_WIDTH + BUTTON_MARGIN) or BUTTON_MARGIN
    local buttonLeft = productsWidth - BUTTON_WIDTH - scrollbarMargin
    local statusWidth = buttonLeft - BUTTON_GAP

    local canvasWidth = needsScroll and (productsWidth - SCROLLBAR_WIDTH) or productsWidth
    local canvasHeight = math.max(viewHeight, rowCount * ROW_STEP)
    if productsArea.setCanvasSize then
        productsArea:setCanvasSize(canvasWidth, canvasHeight)
        productsArea:setVisibleHScroll(false)
        productsArea:setVisibleVScroll(needsScroll)
        productsArea:setViewOffset(0, 0)
    end

    local align = MyGUI.Align.Default
    if #products == 0 then
        createLabel(productsArea, 0, 0, canvasWidth, ROW_HEIGHT, "AH_NoProducts")
            :setCaption("This animal gives no products.")
    end
    for i = 1, #products do
        local product = products[i]
        local name = productName(product)
        local rowTop = (i - 1) * ROW_STEP
        local status = createLabel(productsArea, 0, rowTop, statusWidth, ROW_HEIGHT,
            "AH_ProductStatus" .. i)
        local button = assert(productsArea:createWidget(
            "Button", "Kenshi_Button2", buttonLeft, rowTop,
            BUTTON_WIDTH, ROW_HEIGHT, align, "AH_ProductHarvest" .. i))
        button:setCaption("Harvest")
        button:on("eventMouseButtonClick", function()
            if windowState ~= state or state.target ~= targetHandle then
                return
            end
            local a, h = resolveWindowCharacters()
            local e = a and AH.animalEntry(a)
            if not e then
                refreshWindow()
                return
            end
            local ok, reason = harvest(e, h, product)
            if not ok then
                AH.notify("Cannot harvest " .. name .. ": " .. tostring(reason) .. ".")
            end
            refreshWindow()
        end)
        state.rows[#state.rows + 1] = { product = product, name = name, status = status, button = button }
    end
end

local function showAnimal(targetHandle, entry)
    local state = windowState
    if not state then
        AH.log("Husbandry window: no window state")
        return
    end
    state.target = targetHandle
    if state.portrait then
        local portraits = PortraitManager.getInstance()
        if portraits then
            local ok, err = pcall(portraits.setImageWidget, portraits, targetHandle, state.portrait, true)
            if not ok then
                AH.log("Husbandry window: could not set the portrait: " .. tostring(err))
            end
        end
    end
    rebuildProducts(entry)
    refreshWindow()
end

-- Opens the Husbandry window for an animal. targetHandle and harvesterHandle are hand
-- values; harvesterHandle can be nil when no person is selected.
function AH.openHusbandryWindow(targetHandle, harvesterHandle)
    if AH.syncConstantsFromFCS then
        AH.syncConstantsFromFCS()
    end
    local animal = targetHandle and targetHandle:getCharacter()
    local entry = animal and AH.animalEntry(animal)
    if not entry then
        AH.log("Husbandry window: the target is not an animal")
        return
    end

    if windowState and AH.husbandryWindow and AH.husbandryWindow:getVisible() then
        showAnimal(targetHandle, entry)
        AH.husbandryWindow:upLayerItem()
        return
    end

    destroyWindow()

    AH.husbandrySerial = (AH.husbandrySerial or 0) + 1
    local prefix = "AH_Husbandry_" .. AH.husbandrySerial .. "_"

    local layout = MyGUI.LayoutManager.getInstance():loadLayout(LAYOUT_FILE, prefix, nil)
    local root = layout and layout[1]
    if not root then
        AH.log("Husbandry window: could not load layout " .. LAYOUT_FILE)
        return
    end

    AH.husbandryWindow = root

    local function find(name)
        return root:findWidget(prefix .. name)
    end

    local pos = AH.husbandryWindowPos or { left = DEFAULT_LEFT, top = DEFAULT_TOP }
    root:setPosition(pos.left, pos.top)

    root:on("eventWindowButtonPressed", function(window, buttonName)
        if buttonName == "close" then
            local l, t = window:getPosition()
            AH.husbandryWindowPos = { left = l, top = t }
            window:setVisible(false)
            local im = MyGUI.InputManager.getInstance()
            if im then
                im:resetKeyFocusWidget()
            end
        end
    end)

    local state = {
        target = targetHandle,
        harvester = harvesterHandle,
        prefix = prefix,
        layout = layout,
        root = root,
        rows = {},
        infoPanels = {},
        infoText = {},
    }
    windowState = state

    local portrait = find("AH_Portrait")
    ---@cast portrait MyGUI.ImageBox|nil
    state.portrait = portrait
    state.nameText = find("AH_Name")

    local guiObj = assert(getForgottenGUI(), "ForgottenGUI is unavailable")
    local function createInfoPanel(name, area)
        local panel = assert(guiObj:createDatapanel(prefix .. name, area, false),
            "Husbandry window: could not create the " .. name .. " datapanel")
        state.infoPanels[#state.infoPanels + 1] = panel
        return panel
    end

    local generalArea = assert(find("AH_GeneralInfoArea"),
        "Husbandry layout missing AH_GeneralInfoArea")
    local husbandryArea = assert(find("AH_BreedingInfoArea"),
        "Husbandry layout missing AH_BreedingInfoArea")
    state.generalPanel = createInfoPanel("GeneralInfo", generalArea)
    state.husbandryPanel = createInfoPanel("HusbandryInfo", husbandryArea)

    local productsArea = assert(find("AH_ProductsScrollView"),
        "Husbandry layout missing AH_ProductsScrollView")
    ---@cast productsArea MyGUI.ScrollView
    state.productsArea = productsArea

    showAnimal(targetHandle, entry)
    root:setVisible(true)
    root:upLayerItem()
end

local function onSelectionChanged(guiObj)
    local state = windowState
    if not state or not state.root or not state.root:getVisible() then
        return
    end
    local target = guiObj.selectedObject
    if not target or target:isNull() or target == state.target then
        return
    end
    local animal = target:getCharacter()
    if not animal or not animal:isPlayerCharacter() then
        return
    end
    local entry = AH.animalEntry(animal)
    if entry then
        -- Selection changes the animal; the harvester belongs to this window session.
        showAnimal(target, entry)
    end
end

-- Context menu row

local function menuHasRow(optionsList)
    for i = 0, optionsList:getChildCount() - 1 do
        if optionsList:getChildAt(i):getName() == ROW_NAME then
            return true
        end
    end
    return false
end

local function addMenuRow(menuGUI, targetHandle, harvesterHandle)
    local ol = menuGUI.optionsList
    local main = menuGUI:getMainWidget()
    -- The engine also shows a hidden copy of the menu with no options and reuses it
    -- without rebuilding its rows, so add the row only to the visible menu, once.
    if not ol or not main or not main:getVisible() or menuHasRow(ol) then
        return
    end

    local count = ol:getChildCount()
    local oc, bc = menuGUI.optionCoords, menuGUI.buttonCoords
    local _, _, olw, olh = ol:getCoord()
    local rowTop, rowH = 0, oc.height
    -- Match the engine's own buttons by copying the first row's button coordinates;
    -- rows without a value column stretch the button wider than buttonCoords.
    local bl, bt, bw, bh = bc.left, bc.top, olw - 2 * bc.left, bc.height
    if count > 0 then
        local _, t, _, h = ol:getChildAt(count - 1):getCoord()
        rowTop, rowH = t + h, h
        local first = ol:getChildAt(0)
        if first:getChildCount() > 0 then
            bl, bt, bw, bh = first:getChildAt(0):getCoord()
        end
    end

    local align = MyGUI.Align.Default
    local row = ol:createWidget("Widget", "PanelEmpty", 0, rowTop, olw, rowH, align, ROW_NAME)
    local button = row:createWidget("Button", "Kenshi_Button1", bl, bt, bw, bh, align, BUTTON_NAME)
    button:setCaption("Husbandry")

    local _, _, mw, mh = main:getCoord()
    main:setSize(mw, mh + rowH)
    local _, _, _, olh2 = ol:getCoord()
    if olh2 < olh + rowH then
        ol:setSize(olw, olh + rowH)
    end

    menuState.target = targetHandle
    menuState.harvester = harvesterHandle
    menuState.focused = false
    button:on("eventMouseSetFocus", function()
        menuState.focused = true
    end)
    button:on("eventMouseLostFocus", function()
        menuState.focused = false
    end)
    button:on("eventMouseButtonClick", function()
        local t, h = menuState.target, menuState.harvester
        -- Clear first, so the close event below does not open the window a second time.
        menuState.target = nil
        menuState.focused = false
        if t then
            AH.openHusbandryWindow(t, h)
        end
        -- The engine does not know about this button, so close the menu ourselves,
        -- as the engine's own option buttons do from their click handlers.
        getGameWorld():hideContextMenu()
    end)
end

local function onMenuShow(menuGUI, orders, name, offset)
    local ok, err = pcall(function()
        local target = menuGUI.contextMenuTarget:getCharacter()
        if not target or not target:isAnimal() or not target:isPlayerCharacter() then
            return
        end
        if target:isInCombatMode(true, true) then
            return
        end
        local harvester = AH.selectedCharacter()
        if not harvester or not isEligibleHarvester(harvester) then
            return
        end
        addMenuRow(menuGUI, target.handle, harvester.handle)
    end)
    if not ok then
        AH.log("context menu row failed: " .. tostring(err))
    end
end

-- Releasing right-click over the row closes the menu with the row still focused.
-- The engine sends several close events in a row, so this acts once.
local function onMenuShowOrHide(menu, on, what)
    if on then
        return
    end
    local t, h, focused = menuState.target, menuState.harvester, menuState.focused
    menuState.target = nil
    menuState.harvester = nil
    menuState.focused = false
    if t and focused then
        local ok, err = pcall(AH.openHusbandryWindow, t, h)
        if not ok then
            AH.log("Husbandry window failed: " .. tostring(err))
        end
    end
end

-- Refresh the open window about once a second so cooldowns and distances stay current.
local REFRESH_FRAMES = 30
local refreshCounter = 0
local function onFrame()
    refreshCounter = refreshCounter + 1
    if refreshCounter < REFRESH_FRAMES then
        return
    end
    refreshCounter = 0
    local w = AH.husbandryWindow
    if w and windowState and w:getVisible() then
        local ok, err = pcall(refreshWindow)
        if not ok then
            AH.log("Husbandry window refresh failed: " .. tostring(err))
        end
    end
end

AH.onEvent("harvest_menuShow", "ContextMenuGUI::show", onMenuShow)
AH.onEvent("harvest_menuShowOrHide", "ContextMenu::showContextMenu", onMenuShowOrHide)
AH.onEvent("harvest_selection", "ForgottenGUI::selectedObjectsChanged", onSelectionChanged)
AH.onEvent("harvest_refresh", "GameWorld::charsUpdate", onFrame)

local function shutdown()
    menuState.target = nil
    menuState.harvester = nil
    menuState.focused = false
    -- Look up the row again: the engine may already have destroyed the menu.
    local row = MyGUI.findWidget(ROW_NAME)
    if row then
        row:destroy()
    end
    destroyWindow()
end

return { shutdown = shutdown }
