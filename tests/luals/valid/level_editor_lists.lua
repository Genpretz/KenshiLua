-- LuaLS regression fixture: level-editor game-data selection lists.

---@param faction FactionListWindow
---@param itemList ItemListWindow
---@param npc NpcListWindow
---@param town TownListWindow
---@param data GameData
local function checkLevelEditorLists(faction, itemList, npc, town, data)
    faction:itemSelected(data)
    faction:_NV_itemSelected(data)
    itemList:itemSelected(data)
    itemList:_NV_itemSelected(data)
    npc:itemSelected(data)
    npc:_NV_itemSelected(data)
    assert(type(town:formatItem(data)) == "string")
    assert(type(town:_NV_formatItem(data)) == "string")
end

return checkLevelEditorLists
