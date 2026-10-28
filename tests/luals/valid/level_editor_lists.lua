-- LuaLS regression fixture: level-editor game-data selection lists.

---@param faction FactionListWindow
---@param itemList ItemListWindow
---@param npc NpcListWindow
---@param town TownListWindow
---@param data GameData
local function checkLevelEditorLists(faction, itemList, npc, town, data)
    faction:itemSelected(data)
    itemList:itemSelected(data)
    npc:itemSelected(data)
    assert(type(town:formatItem(data)) == "string")
end

return checkLevelEditorLists
