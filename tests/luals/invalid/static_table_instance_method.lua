-- EXPECT-DIAGNOSTIC: undefined-field
-- Global static tables hold only the static functions; instance methods such
-- as CombatClass:isAI are not on the CombatClass global.

local function callsInstanceMethodOnStaticTable()
    CombatClass.setup()
    return CombatClass.isAI
end

return callsInstanceMethodOnStaticTable
