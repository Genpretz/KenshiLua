---@param handle hand
---@param other hand
---@param object RootObjectBase
local function check(handle, other, object)
    local sameHandle = handle:operator_eq(other)
    local sameObject = handle:operator_eq(object)
    local matchesTrue = handle:operator_eq(true)
    local differsHandle = handle:operator_ne(other)
    local differsObject = handle:operator_ne(object)
    local matchesFalse = handle:operator_ne(false)
    return sameHandle, sameObject, matchesTrue, differsHandle, differsObject, matchesFalse
end
return check
