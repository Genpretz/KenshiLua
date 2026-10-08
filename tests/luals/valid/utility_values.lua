---@param triple TripleInt
---@param booleanValue hkBool
---@param trade TradeResult
local function check(triple, booleanValue, trade)
 triple.value = { 1, 2, 3 }; triple:operator_subscript(0, 1); assert(triple:operator_subscript(0) == 1)
 assert(booleanValue:operator_eq(true) or booleanValue:operator_ne(true)); trade.value = 1; trade:showMessage(); TradeResult.ShowMessage(1)
end
return check
