-- sales.lua
-- Animal sale window opened by the FCS dialogue scripts.

local AH = require("ah.core")
AH.sales = AH.sales or {}
local S = AH.sales

local WINDOW_LAYOUT = "Kenshi_CharacterSelectionWindow.layout"
local BOX_LAYOUT = "Kenshi_CharacterSelectionBox.layout"
-- Height of a row in the vanilla layout, as a fraction of the screen height.
local BOX_REAL_HEIGHT = 0.180556
local BOX_GAP = 4
local OVER_BUDGET_COLOUR = { r = 1.0, g = 0.35, b = 0.35 }

local function scfg()
    return AH.config.sales
end

S.serial = S.serial or 0

-- Rules

local function moneyText(n)
    return AH.moneyText and AH.moneyText(n) or ("c." .. tostring(math.floor(n)))
end

-- Returns the animal price using Kenshi's (age + 0.1) x base price formula.
function S.priceOf(entry)
    if AH.priceOf then
        return AH.priceOf(entry)
    end
    local base = (entry.def and entry.def.basePrice) or scfg().defaultBasePrice
    local mult = scfg().resaleMultiplier or 0.50
    return math.floor((AH.age(entry.animal) + 0.1) * base * mult)
end

-- Returns the buyer (the NPC) and the seller (the player character) of a
-- conversation, or nil when the conversation is not between the player and an NPC.
local function participants(dialogue)
    local owner = dialogue:getCharacter()
    local targetHandle = dialogue:getConversationTarget()
    local target = targetHandle and targetHandle:getCharacter()
    if not owner or not target then
        return nil, nil
    end
    local ownerIsPlayer = owner:isPlayerCharacter() and true or false
    local targetIsPlayer = target:isPlayerCharacter() and true or false
    if ownerIsPlayer and not targetIsPlayer then
        return target, owner
    elseif targetIsPlayer and not ownerIsPlayer then
        return owner, target
    end
    return nil, nil
end

-- The point the buyer's distance is measured from: the building the buyer is inside,
-- such as a farm shop, so animals waiting outside count; otherwise the buyer.
local function buyerAnchor(buyer)
    local inside = buyer:isIndoors()
    local building = inside and not inside:isNull() and inside:getBuilding()
    return building or buyer
end

-- Living player animals within sales.maxDistance of the buyer (or the buyer's
-- building) or of the seller, sorted by name. Animals elsewhere, such as at a base
-- the seller left, are not offered. An optional predicate further limits the list.
local function candidates(buyer, seller, filter)
    local out = {}
    local maxDistance = scfg().maxDistance
    local anchor = buyerAnchor(buyer)
    local animals = AH.playerAnimals()
    for i = 1, #animals do
        local e = animals[i]
        if not e.char:isDead() then
            local d = math.min(AH.distance(e.char, anchor), AH.distance(e.char, seller))
            local near = d <= maxDistance
            if near and (not filter or filter(e)) then
                out[#out + 1] = e
            end
            AH.debugLog(string.format("sale candidate %s: distance %.1f of %s%s", tostring(e.char:getName()), d,
                tostring(maxDistance), near and "" or " (too far)"))
        end
    end
    table.sort(out, function(a, b)
        return tostring(a.char:getName()) < tostring(b.char:getName())
    end)
    return out
end

local function statText(c, stat)
    local stats = c:getStats()
    if not stats then
        return "?"
    end
    return tostring(math.floor(stats:getStat(stat, false)))
end

-- Layout helpers

local function startsWith(s, prefix)
    return s and string.sub(s, 1, #prefix) == prefix
end

-- Records the relative coordinates of every widget that the layout named with prefix.
-- Widgets created by skins are skipped; they follow their own alignment.
local function captureLayoutCoords(widget, prefix, out)
    for i = 0, widget:getChildCount() - 1 do
        local child = widget:getChildAt(i)
        if startsWith(child:getName(), prefix) then
            local l, t, w, h = child:getRealCoord()
            out[#out + 1] = { widget = child, l = l, t = t, w = w, h = h }
        end
        captureLayoutCoords(child, prefix, out)
    end
end

-- A layout loaded inside a parent sizes its root relative to that parent, and
-- alignment does not keep proportions when the root is resized afterwards. Resize the
-- root, then restore each widget's relative coordinates, parents first.
local function resizeLayoutRoot(root, prefix, left, top, width, height)
    local coords = {}
    captureLayoutCoords(root, prefix, coords)
    root:setCoord(left, top, width, height)
    for i = 1, #coords do
        local c = coords[i]
        c.widget:setRealCoord(c.l, c.t, c.w, c.h)
    end
end

-- Window

local function removeModal(st)
    if not st or not st.modal then
        return
    end
    st.modal = false
    local im = MyGUI.InputManager.getInstance()
    if im and st.root then
        local ok, err = pcall(im.removeWidgetModal, im, st.root)
        if not ok then
            AH.log("could not remove sale window modal state: " .. tostring(err))
        end
    end
end

local function destroyState(st)
    -- Keep this defensive cleanup here as well as in close(): an open sale window can
    -- be discarded during reload or replaced by another one without using close().
    removeModal(st)
    local gui = assert(getForgottenGUI(), "ForgottenGUI is unavailable")
    -- Datapanels own widgets inside the layout, so destroy them before the layout.
    for i = 1, #st.panels do
        local ok, err = pcall(gui.destroy, gui, st.panels[i])
        if not ok then
            AH.log("could not destroy sale window datapanel: " .. tostring(err))
        end
    end
    st.panels = {}
    local ok, err = pcall(function()
        MyGUI.LayoutManager.getInstance():unloadLayout(st.layout)
    end)
    if not ok then
        AH.log("could not unload sale window: " .. tostring(err))
    end
end

-- Destroys a closed window. A button cannot destroy its own window from inside its
-- click handler, so closing hides the window and this runs later.
local function destroyClosedWindow()
    local st = S.state
    if st and st.closed then
        S.state = nil
        destroyState(st)
    end
end

-- Destroys the window, open or closed, without ending the conversation.
local function discardWindow()
    local st = S.state
    if st then
        S.state = nil
        st.closed = true
        destroyState(st)
    end
end

-- Ends the conversation that opened the window, so the player returns to the game.
local function endConversation(st)
    local owner = st.dialogueOwner and st.dialogueOwner:getCharacter()
    local dlg = owner and owner.dialogue
    if dlg then
        local ok, err = pcall(dlg.endDialogue, dlg, true)
        if not ok then
            AH.log("could not end the conversation: " .. tostring(err))
        end
    end
end

local function hideWindow(st)
    st.closed = true
    removeModal(st)
    pcall(st.root.setVisible, st.root, false)
    local im = MyGUI.InputManager.getInstance()
    if im then
        im:resetKeyFocusWidget()
    end
end

function S.close()
    local st = S.state
    if not st or st.closed then
        return
    end
    hideWindow(st)
    endConversation(st)
end

-- Kenshi's 3D-world clicks bypass MyGUI's modal-widget routing. If the player
-- clicks the trader again while this custom window is open, the engine can start
-- and display a new dialogue anyway. Dismiss the sale window without ending that
-- newly started conversation; deferred destruction keeps this safe inside the
-- DialogueWindow::show callback.
local function onDialogueWindowShow()
    local st = S.state
    if not st or st.closed then
        return
    end
    AH.debugLog("dismissing sale window because a new dialogue window opened")
    hideWindow(st)
end

local function selectedRows(st)
    local out = {}
    for i = 1, #st.rows do
        if st.rows[i].selected then
            out[#out + 1] = st.rows[i]
        end
    end
    return out
end

local function updateTotals(st)
    local selected = selectedRows(st)
    local total = 0
    for i = 1, #selected do
        total = total + selected[i].price
    end
    local overBudget = total > st.buyerMoney
    st.totalText:setCaption(moneyText(total))
    st.totalText:setTextColour(overBudget and OVER_BUDGET_COLOUR or st.totalColour)
    st.countText:setCaption(#selected .. " / " .. #st.rows)
    st.confirm:setEnabled(#selected > 0 and not overBudget)
end

local function toggleRow(st, row)
    if st.closed then
        return
    end
    row.selected = not row.selected
    row.check:setStateSelected(row.selected)
    updateTotals(st)
end

local function confirmSale(st)
    if st.closed then
        return
    end
    local buyer = st.buyer:getCharacter()
    local seller = st.seller:getCharacter()
    if not buyer or not seller or buyer:isDead() then
        AH.notify("The sale was cancelled: the buyer is no longer available.")
        S.close()
        return
    end

    local sold, total = {}, 0
    local selected = selectedRows(st)
    for i = 1, #selected do
        local c = selected[i].handle:getCharacter()
        if c and not c:isDead() and c:isPlayerCharacter() then
            sold[#sold + 1] = c
            total = total + selected[i].price
        end
    end
    if #sold == 0 then
        S.close()
        return
    end
    if total > buyer:getMoney() then
        AH.notify(tostring(buyer:getName()) .. " cannot afford " .. moneyText(total) .. ".")
        return
    end

    if total > 0 then
        if buyer:takeMoney(total) == false then
            AH.notify(tostring(buyer:getName()) .. " cannot afford " .. moneyText(total) .. ".")
            return
        end
        seller:takeMoney(-total)
    end
    local faction, platoon = buyer:getFaction(), buyer:getPlatoon()
    for i = 1, #sold do
        sold[i]:setFaction(faction, platoon)
    end
    AH.notify(string.format("Sold %d animal%s to %s for %s.", #sold, #sold == 1 and "" or "s",
        tostring(buyer:getName()), moneyText(total)))
    S.close()
end

local function fillPanels(st, entry, prefix, box)
    local gui = assert(getForgottenGUI(), "ForgottenGUI is unavailable")
    local c = entry.char

    local p1Widget = box:findWidget(prefix .. "DataPanel1")
    local p1 = p1Widget and gui:createDatapanel(prefix .. "Panel1", p1Widget, false)
    if p1 then
        st.panels[#st.panels + 1] = p1
        p1:setLine("Strength", statText(c, StatsEnumerated.STAT_STRENGTH), 0, false, true)
        p1:setLine("Melee Attack", statText(c, StatsEnumerated.STAT_MELEE_ATTACK), 0, false, true)
        p1:setLine("Gender", AH.isFemale(c) and "Female" or "Male", 0, false, true)
        p1:show(true)
    end

    local p2Widget = box:findWidget(prefix .. "DataPanel2")
    local p2 = p2Widget and gui:createDatapanel(prefix .. "Panel2", p2Widget, false)
    if p2 then
        st.panels[#st.panels + 1] = p2
        p2:setLine(tostring(entry.raceName or "?"), "", 0, false, true)
        p2:setLine("Age", AH.ageText(entry), 0, false, true)
        p2:show(true)
    end
end

local function addRow(st, entry, index, scrollView, rowWidth, rowHeight)
    local prefix = st.prefix .. "Box" .. index .. "_"
    local widgets = MyGUI.LayoutManager.getInstance():loadLayout(BOX_LAYOUT, prefix, scrollView)
    local box = assert(widgets[1], "sale row layout has no root widget")
    local rowTop = (index - 1) * (rowHeight + BOX_GAP)
    resizeLayoutRoot(box, prefix, 0, rowTop, rowWidth, rowHeight)

    local c = entry.char
    local check = assert(box:findWidget(prefix .. "CheckBox"), "sale row has no checkbox")
    ---@cast check MyGUI.Button
    local row = {
        handle = c.handle,
        price = S.priceOf(entry),
        selected = false,
        check = check,
    }
    assert(box:findWidget(prefix .. "NameTextBox")):setCaption(tostring(c:getName()))
    assert(box:findWidget(prefix .. "PriceTextBox")):setCaption(moneyText(row.price))
    row.check:setStateSelected(false)
    row.check:on("eventMouseButtonClick", function()
        toggleRow(st, row)
    end)
    box:on("eventMouseButtonClick", function()
        toggleRow(st, row)
    end)
    local portraits = PortraitManager.getInstance()
    local portrait = box:findWidget(prefix .. "Portrait")
    if portraits and portrait then
        ---@cast portrait MyGUI.ImageBox
        portraits:setImageWidget(c.handle, portrait, true)
    end

    -- A datapanel created outside the visible part of the scroll view never shows its
    -- lines, even after scrolling, so scroll the row into view while filling it.
    scrollView:setViewOffset(0, -rowTop)
    fillPanels(st, entry, prefix, box)
    st.rows[#st.rows + 1] = row
end

-- Opens the sale window for the conversation in dialogue. Returns true on success.
-- Optional filter(entry) returns true for animals this buyer accepts. Entries are
-- described by animalEntry in ah/core.lua; omitting the filter accepts all animals.
function S.open(dialogue, filter)
    if AH.syncConstantsFromFCS then
        AH.syncConstantsFromFCS()
    end
    -- Replacing a window must not end the conversation that is opening the new one.
    discardWindow()
    if not dialogue then
        AH.log("sale window: no dialogue")
        return false
    end
    local buyer, seller = participants(dialogue)
    if not buyer or not seller then
        AH.log("sale window: the conversation is not between the player and an NPC")
        return false
    end

    S.serial = S.serial + 1
    local prefix = "AH_Sale" .. S.serial .. "_"
    local layout = MyGUI.LayoutManager.getInstance():loadLayout(WINDOW_LAYOUT, prefix, nil)
    local root = layout and layout[1]
    if not root then
        AH.log("sale window: could not load " .. WINDOW_LAYOUT)
        return false
    end
    local function find(name)
        return root:findWidget(prefix .. name)
    end

    local totalText = assert(find("MoneyAmountTextBox"), "sale window has no total text")
    ---@cast totalText MyGUI.TextBox
    local countText = assert(find("SelectedTotalTextBox"), "sale window has no selection count")
    local confirm = assert(find("ConfirmButton"), "sale window has no confirm button")
    ---@cast confirm MyGUI.Button

    local st = {
        prefix = prefix,
        layout = layout,
        root = root,
        panels = {},
        rows = {},
        buyer = buyer.handle,
        seller = seller.handle,
        dialogueOwner = dialogue:getHandle(),
        buyerMoney = buyer:getMoney() or 0,
        totalText = totalText,
        countText = countText,
        confirm = confirm,
        closed = false,
        modal = false,
    }
    S.state = st

    local ok, err = pcall(function()
        st.totalColour = st.totalText:getTextColour()
        find("CaptionTextBox"):setCaption("Sell Animals")
        find("TotalMoneyBuyer"):setCaption(moneyText(st.buyerMoney))
        st.confirm:on("eventMouseButtonClick", function()
            local okSale, errSale = pcall(confirmSale, st)
            if not okSale then
                AH.log("sale failed: " .. tostring(errSale))
                S.close()
            end
        end)
        find("CancelButton"):on("eventMouseButtonClick", function()
            S.close()
        end)

        local scrollView = assert(find("CharacterSelectionItemBox"), "sale window has no item list")
        ---@cast scrollView MyGUI.ScrollView
        scrollView:setVisibleHScroll(false)
        local _, _, _, screenH = root:getCoord()
        local _, _, viewW = scrollView:getViewCoord()
        local rowWidth = math.max(viewW, 1)
        local rowHeight = math.floor(BOX_REAL_HEIGHT * screenH)
        local entries = candidates(buyer, seller, filter)
        -- Size the canvas first: the view can only scroll within it while rows are added.
        scrollView:setCanvasSize(rowWidth, math.max(#entries * (rowHeight + BOX_GAP), 1))
        for i = 1, #entries do
            addRow(st, entries[i], i, scrollView, rowWidth, rowHeight)
        end
        scrollView:setViewOffset(0, 0)
        if #entries == 0 then
            find("CaptionTextBox"):setCaption(filter and "No matching animals nearby to sell" or "No animals nearby to sell")
        end
        updateTotals(st)
        root:upLayerItem()
        local im = assert(MyGUI.InputManager.getInstance(), "MyGUI InputManager is unavailable")
        im:addWidgetModal(root)
        st.modal = true
    end)
    if not ok then
        AH.log("sale window failed: " .. tostring(err))
        discardWindow()
        return false
    end
    AH.debugLog("sale window opened for buyer " .. tostring(buyer:getName()) .. " with " .. #st.rows .. " animal(s)")
    return true
end

AH.onEvent("sales_destroyClosed", "GameWorld::charsUpdate", destroyClosedWindow)
AH.onEvent("sales_dialogueWindowShow", "DialogueWindow::show", onDialogueWindowShow)

S.shutdown = discardWindow

return S
