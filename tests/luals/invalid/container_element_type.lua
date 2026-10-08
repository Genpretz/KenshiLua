-- EXPECT-DIAGNOSTIC: undefined-field
-- Container elements are typed, so a misspelled element method is reported
-- instead of being accepted as `any`.

---@param characters Lektor<Character>
local function misspelledElementMethod(characters)
    local first = characters[1]
    if first then
        first:isImmuneToOffscreenModee()
    end
end

return misspelledElementMethod
