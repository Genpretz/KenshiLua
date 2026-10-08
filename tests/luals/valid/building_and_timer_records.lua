---@param category BuildingCategory
---@param group BuildingGroup
---@param result hkResult
---@param stamp SimpleTimeStamper
---@param timer CPerfTimer
local function check(category, group, result, stamp, timer)
 category.name, group.name = "a", "b"
 category:operator_assign(category); group:operator_assign(group)
 assert(category < category or true); assert(group < group or true)
 result.m_enum = 1; assert(result:operator_eq(1) and not result:operator_ne(1))
 stamp.timer = timer; assert(stamp:getTime(0) >= 0 and stamp:stampTime() >= 0)
end
return check
