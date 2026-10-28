---@param section ShopTraderInventorySection
---@param item Item
local function check(section, item)
 section:autoArrange(); assert(type(section:addItem(item, 1)) == "boolean")
end
return check
