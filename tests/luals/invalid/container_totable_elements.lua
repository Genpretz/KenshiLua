-- EXPECT-DIAGNOSTIC: undefined-field
-- Generic container toTable() is declared as table<integer, T> because LuaLS
-- does not substitute class type parameters inside T[]; elements stay typed.

---@param characters Lektor<Character>
local function misspelledTableElementMethod(characters)
    for _, character in ipairs(characters:toTable() or {}) do
        character:isImmuneToOffscreenModee()
    end
end

return misspelledTableElementMethod
