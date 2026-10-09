-- Animal Husbandry: Husbandry button and window.
--
-- When the right-click context menu opens on an animal in the player faction while a
-- non-animal character in the player faction is selected, a "Husbandry" row is added
-- to the bottom of the menu. The row is not available while the animal is in combat.
-- Clicking it, or releasing right-click over it, opens the Husbandry window. The
-- window shows the animal's sex, life stage, and breeding state, and lists the products
-- in its record's "animal products" list, each with a Harvest button. The selected
-- person harvests: they must stand near the animal, and the items go into their
-- inventory.
--
-- Each product reference sets the items per harvest (val0), the days between harvests
-- (val1), and which sex gives it (val2: 0 male, 1 female, 2 both); harvest.minAge in
-- the config applies to all. The time of the next allowed harvest is stored on the
-- animal as AH_NextHarvest_<item string ID>, so it survives saving and travels with a
-- sold animal.

local AH = _G.AnimalHusbandry

local ROW_NAME = "AH_HusbandryRow"
local BUTTON_NAME = "AH_HusbandryButton"
local WINDOW_NAME = "AH_HusbandryWindow"
local NEXT_HARVEST_PREFIX = "NextHarvest_"

-- Window layout, in pixels, modelled on a row of the vanilla character trading window:
-- a portrait with the name across its bottom, then a framed box split into two
-- columns. The left column is a datapanel of the animal's details; the right column
-- lists its products, each with a Harvest button. The window's height is fitted to
-- its contents.
local WINDOW_WIDTH = 680
local MARGIN = 14
local PORTRAIT_SIZE = 136
local NAME_HEIGHT = 22
local FRAME_PADDING = 8
local INFO_LINES = 5
local INFO_LINE_HEIGHT = 26
local ROW_HEIGHT = 30
local ROW_STEP = 34
local BUTTON_WIDTH = 110
local DEFAULT_LEFT, DEFAULT_TOP = 220, 160

local function hcfg()
    return AH.config.harvest
end

-- Reloading this script destroyed the window it had created. KenshiLua destroys the
-- window's widgets before the reload, including those under its datapanel, so the
-- datapanel itself is left behind; close the window before reloading this script.
AH.husbandryWindow = nil

-- State of the open window: handles rather than characters, so a character that
-- despawns while the window is open resolves to nil instead of a dangling pointer.
local windowState = nil

-- State of the context menu row currently shown.
local menuState = { target = nil, harvester = nil, focused = false }

-- ---------------------------------------------------------------------------
-- Rules
-- ---------------------------------------------------------------------------

local function nextHarvestKey(product)
    return NEXT_HARVEST_PREFIX .. tostring(product.itemID)
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

-- Animals cannot perform husbandry work. Skeletons and other non-animal player
-- characters remain valid because they use the same humanoid interaction model.
local function isEligibleHarvester(c)
    return c and c:isPlayerCharacter() and not c:isAnimal()
end

-- Returns true, or false and the reason the product cannot be harvested now.
local function canHarvest(entry, harvester, product, now)
    local c = entry.char
    if c:isDead() then
        return false, "dead"
    end
    if c:isInCombatMode(true, true) then
        return false, "animal is in combat"
    end
    if not product.data then
        return false, "item not available"
    end
    if AH.age(entry.animal) < hcfg().minAge then
        return false, "too young"
    end
    local sexOk, sexReason = sexAllows(product, AH.isFemale(c))
    if not sexOk then
        return false, sexReason
    end
    local nextAt = AH.getValue(c, nextHarvestKey(product))
    if nextAt and now < nextAt then
        return false, string.format("ready in %.1f days", nextAt - now)
    end
    if not harvester then
        return false, "no one selected"
    end
    if not isEligibleHarvester(harvester) then
        return false, "select a player humanoid"
    end
    if harvester:isDead() or harvester:isUnconcious() then
        return false, "harvester cannot act"
    end
    if AH.distance(harvester, c) > hcfg().maxDistance then
        return false, "too far away"
    end
    return true
end

-- Creates the product's items in the harvester's inventory and starts its cooldown.
-- Returns true, or false and a reason.
local function harvest(entry, harvester, product)
    local now = AH.currentDay()
    local ok, reason = canHarvest(entry, harvester, product, now)
    if not ok then
        return false, reason
    end

    local name, data = productName(product)
    local inventory = harvester:getInventory()
    local factory = getRootObjectFactory()
    local given = 0
    for i = 1, math.max(1, product.amount or 1) do
        local item = factory:createItem(data, nil, nil, nil, -1, nil)
        if item then
            -- dropOnFail puts the item on the ground beside the harvester if the
            -- inventory is full.
            inventory:addItem(item, 1, true, false)
            given = given + 1
        end
    end
    if given == 0 then
        return false, "could not create the item"
    end

    AH.setValue(entry.char, nextHarvestKey(product), now + math.max(0, product.days or 1))
    local count = given > 1 and (given .. " x ") or ""
    AH.notify(string.format("%s harvested %s%s from %s.", harvester:getName(), count, name, entry.char:getName()))
    return true
end

-- ---------------------------------------------------------------------------
-- Husbandry window
-- ---------------------------------------------------------------------------

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
        return { { "Animal", "no longer available" } }
    end
    return {
        { "Race", tostring(entry.raceName) },
        { "Sex", AH.isFemale(animal) and "Female" or "Male" },
        { "Age", AH.ageText(entry) },
        { "Breeding", AH.describeBreeding and AH.describeBreeding(entry, now) or "" },
        { "Harvester", harvester and tostring(harvester:getName()) or "select a person" },
    }
end

-- Rebuilds the details datapanel only when its text changed, so it does not flicker.
local function fillInfoPanel(lines)
    local panel = windowState.infoPanel
    if not panel then
        return
    end
    local parts = {}
    for i = 1, #lines do
        parts[#parts + 1] = lines[i][1] .. "=" .. lines[i][2]
    end
    local text = table.concat(parts, "\n")
    if text == windowState.infoText then
        return
    end
    windowState.infoText = text
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

    windowState.nameText:setCaption(animal and tostring(animal:getName()) or "")
    fillInfoPanel(infoLines(entry, animal, harvester, now))

    for i = 1, #windowState.rows do
        local row = windowState.rows[i]
        if entry then
            local ok, reason = canHarvest(entry, harvester, row.product, now)
            row.status:setCaption(row.name .. ": " .. (ok and "ready" or reason))
            row.button:setEnabled(ok and true or false)
        else
            row.status:setCaption(row.name)
            row.button:setEnabled(false)
        end
    end
end

local function createLabel(parent, x, y, w, h, name)
    local lbl = parent:createWidget("TextBox", "Kenshi_TextboxStandardText", x, y, w, h, MyGUI.Align.Default, name)
    lbl:setProperty("TextAlign", "Left VCenter")
    return lbl
end

local function destroyWindow()
    if windowState and windowState.infoPanel then
        -- The datapanel owns widgets inside the window, so destroy it first.
        local gui = getForgottenGUI()
        local ok, err = pcall(gui.destroy, gui, windowState.infoPanel)
        if not ok then
            AH.log("Husbandry window: could not destroy the datapanel: " .. tostring(err))
        end
        windowState.infoPanel = nil
    end
    if AH.husbandryWindow then
        local l, t = AH.husbandryWindow:getCoord()
        AH.husbandryWindowPos = { left = l, top = t }
        pcall(function() AH.husbandryWindow:destroy() end)
        AH.husbandryWindow = nil
    end
    windowState = nil
end

-- Opens the Husbandry window for an animal. targetHandle and harvesterHandle are hand
-- values; harvesterHandle can be nil when no person is selected.
function AH.openHusbandryWindow(targetHandle, harvesterHandle)
    local animal = targetHandle and targetHandle:getCharacter()
    local entry = animal and AH.animalEntry(animal)
    if not entry then
        AH.log("Husbandry window: the target is not an animal")
        return
    end

    destroyWindow()

    local products = (entry.def and entry.def.products) or {}
    local rowCount = math.max(1, #products)
    local columnHeight = math.max(INFO_LINES * INFO_LINE_HEIGHT, rowCount * ROW_STEP)
    local frameHeight = math.max(PORTRAIT_SIZE, columnHeight + 2 * FRAME_PADDING)
    local contentHeight = 8 + frameHeight + MARGIN
    local height = contentHeight + 80
    local pos = AH.husbandryWindowPos or { left = DEFAULT_LEFT, top = DEFAULT_TOP }

    -- MiddleFront is below the Esc menu's layer, so the menu's dark overlay covers this
    -- window. Unlike the shared Middle layer, it is an overlapped layer, so this window
    -- draws whole above windows on Middle, such as the character trading window,
    -- instead of mixing with their text.
    local w = MyGUI.createWidget("Window", "Kenshi_WindowCX", pos.left, pos.top, WINDOW_WIDTH, height, 0, "MiddleFront", WINDOW_NAME)
    if not w then
        AH.log("Husbandry window: could not create the window")
        return
    end
    AH.husbandryWindow = w
    w:setCaption("HUSBANDRY")
    w:on("eventWindowButtonPressed", function(window, buttonName)
        if buttonName == "close" then
            -- Hide rather than destroy inside the window's own event; the next window
            -- that opens destroys this one.
            window:setVisible(false)
            local im = MyGUI.InputManager.getInstance()
            if im then
                im:resetKeyFocusWidget()
            end
        end
    end)

    local client = w:getClientWidget() or w
    -- Fit the window so its client area holds the contents; the frame and caption
    -- take the difference between the window and client heights.
    local _, _, clientWidth, clientHeight = client:getCoord()
    if client ~= w and clientHeight ~= contentHeight then
        w:setSize(WINDOW_WIDTH, height + contentHeight - clientHeight)
    end
    local inner = clientWidth - 2 * MARGIN
    local align = MyGUI.Align.Default
    local state = {
        target = targetHandle,
        harvester = harvesterHandle,
        rows = {},
    }
    windowState = state

    -- Portrait, with the name across its bottom as in the vanilla trading window.
    local portrait = client:createWidget("ImageBox", "ImageBox", MARGIN, 8, PORTRAIT_SIZE, PORTRAIT_SIZE,
        align, "AH_Portrait")
    local portraits = PortraitManager.getInstance()
    if portraits then
        local ok, err = pcall(portraits.setImageWidget, portraits, targetHandle, portrait, true)
        if not ok then
            AH.log("Husbandry window: could not set the portrait: " .. tostring(err))
        end
    end
    state.nameText = portrait:createWidget("TextBox", "Kenshi_TextboxStandardText", 0,
        PORTRAIT_SIZE - NAME_HEIGHT, PORTRAIT_SIZE, NAME_HEIGHT, align, "AH_Name")
    state.nameText:setProperty("TextAlign", "Center")

    -- Framed box with the two columns.
    local frameLeft = MARGIN + PORTRAIT_SIZE + 10
    local frame = client:createWidget("Widget", "Kenshi_GenericTextBox", frameLeft, 8, inner - PORTRAIT_SIZE - 10,
        frameHeight, align, "AH_Frame")
    local _, _, frameWidth = frame:getCoord()
    local columnWidth = math.floor((frameWidth - 3 * FRAME_PADDING) / 2)
    local infoArea = frame:createWidget("Widget", "PanelEmpty", FRAME_PADDING, FRAME_PADDING, columnWidth,
        frameHeight - 2 * FRAME_PADDING, align, "AH_InfoArea")
    local productLeft = 2 * FRAME_PADDING + columnWidth

    state.infoPanel = getForgottenGUI():createDatapanel("AH_HusbandryInfo", infoArea, false)
    if not state.infoPanel then
        AH.log("Husbandry window: could not create the details datapanel")
    end

    if #products == 0 then
        createLabel(frame, productLeft, FRAME_PADDING, columnWidth, ROW_HEIGHT, "AH_NoProducts")
            :setCaption("This animal gives no products.")
    end
    for i = 1, #products do
        local product = products[i]
        local name = productName(product)
        local rowTop = FRAME_PADDING + (i - 1) * ROW_STEP
        local status = createLabel(frame, productLeft, rowTop, columnWidth - BUTTON_WIDTH - 6, ROW_HEIGHT,
            "AH_ProductStatus" .. i)
        local button = frame:createWidget("Button", "Kenshi_Button1", productLeft + columnWidth - BUTTON_WIDTH, rowTop,
            BUTTON_WIDTH, ROW_HEIGHT, align, "AH_ProductHarvest" .. i)
        button:setCaption("Harvest")
        button:on("eventMouseButtonClick", function()
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

    refreshWindow()
    w:setVisible(true)
    w:upLayerItem()
end

-- ---------------------------------------------------------------------------
-- Context menu row
-- ---------------------------------------------------------------------------

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
        if not isEligibleHarvester(harvester) then
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
AH.onEvent("harvest_refresh", "GameWorld::charsUpdate", onFrame)

AH.log("harvest loaded")

-- Loading this file made KenshiLua remove the event handlers of every Animal
-- Husbandry script; register them again. See the note in 01_ah_core.lua.
if _G.AnimalHusbandry and _G.AnimalHusbandry.rearmEvents then
    _G.AnimalHusbandry.rearmEvents()
end
