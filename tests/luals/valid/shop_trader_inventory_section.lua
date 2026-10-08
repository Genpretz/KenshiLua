---@param section ShopTraderInventorySection
---@param item Item
local function check(section, item)
 section:autoArrange(); section:_NV_autoArrange(); assert(type(section:addItem(item, 1)) == "boolean" and type(section:_NV_addItem(item, 1)) == "boolean")
end
return check
