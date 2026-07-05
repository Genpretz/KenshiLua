-- extra_inventory_sections.lua
-- Port of the Extra Inventory Sections C++ plugin to Lua using KenshiLuaJIT.

local function log(msg)
    KenshiLua.log("[ExtraInventorySections] " .. msg)
end

local function errorLog(msg)
    KenshiLua.error("[ExtraInventorySections] " .. msg)
end

-- hardcoded section info for our extra inventory sections
local sections = {
    { name = "eyes_eyes",  width = 3, height = 1, slot = AttachSlot.ATTACH_EYES,   equipCallbacks = true, limit = 1 },
    { name = "eyes_belts", width = 3, height = 1, slot = AttachSlot.ATTACH_BELT,   equipCallbacks = true, limit = 1 },
    { name = "eyes_hats",  width = 3, height = 1, slot = AttachSlot.ATTACH_HAT,    equipCallbacks = true, limit = 1 },
    { name = "neck",       width = 2, height = 2, slot = AttachSlot.ATTACH_NECK,   equipCallbacks = true, limit = 1 },
    { name = "gloves",     width = 2, height = 2, slot = AttachSlot.ATTACH_GLOVES, equipCallbacks = true, limit = 4 }
}

-- Ensure extra inventory sections exist in inventory
local function ensureExtraInventorySections(inv)
    if not inv then
        errorLog("ensureExtraInventorySections: Inventory pointer missing or null")
        return
    end

    for _, s in ipairs(sections) do
        local section = inv:getSection(s.name)
        if not section then
            -- Create section
            local newSection = inv:_NV_initialiseNewSection(
                s.name, s.width, s.height,
                s.slot, s.equipCallbacks,
                false, true, s.limit
            )

            if not newSection then
                errorLog("ensureExtraInventorySections: failed to create section " .. s.name)
            else
                -- If the created section does not match expected dims, resize it.
                if newSection.width ~= s.width or newSection.height ~= s.height then
                    log("ensureExtraInventorySections: section '" .. s.name
                        .. "' created with unexpected size (got " .. newSection.width .. " x " .. newSection.height
                        .. ", expected " .. s.width .. " x " .. s.height .. "). Resizing.")
                    inv:resizeSection(newSection, s.width, s.height, true)
                end
            end
        end
    end
end

-- Hook Character Init
KenshiLua.registerHandler("onCharacterInit", function(character)
    if character and character.inventory then
        ensureExtraInventorySections(character.inventory)
    end
end)

-- Hook Choose My Clothing
KenshiLua.registerHandler("onChooseMyClothing", function(gear, dataList, listName, race, noShoes)
    if listName ~= "clothing" then
        return
    end

    local extraSlots = {
        AttachSlot.ATTACH_EYES,   -- eyes_eyes
        AttachSlot.ATTACH_GLOVES, -- gloves
        AttachSlot.ATTACH_NECK    -- neck
    }

    for _, slot in ipairs(extraSlots) do
        local item = RootObjectFactory.chooseClothingItemFromList(dataList, listName, slot, race)
        if item then
            gear:push(item) -- lektor:push(item) pushes the GameData* object to the lektor array
        end
    end
end)

-- Hook BaseLayout Initialise
KenshiLua.registerHandler("onBaseLayoutInitialise", function(layout)
    if layout == "Kenshi_InventoryCharacterWindow.layout" then
        log("Redirecting inventory character window layout to custom version")
        return "Custom_InventoryCharacterWindow.layout"
    end
end)

-- Hook Inventory getSectionOfType
KenshiLua.registerHandler("onInventoryGetSectionOfType", function(inv, type)
    if not inv then return nil end

    if type == AttachSlot.ATTACH_HAT then
        local head = inv:getSection("head")
        if head then return head end
    elseif type == AttachSlot.ATTACH_BELT then
        local belt = inv:getSection("belt")
        if belt then return belt end
    end
    
    return nil
end)

log("Extra Inventory Sections Lua Mod Loaded successfully.")
