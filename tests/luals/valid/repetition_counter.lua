---@param counter RepetitionCounter
local function check(counter)
 counter:setup(); assert(type(counter:count(1)) == "boolean" and counter:getTimeSinceLastTrigger(1) >= 0 and counter:getCount(1) >= 0)
end
return check
