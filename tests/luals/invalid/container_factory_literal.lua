-- EXPECT-DIAGNOSTIC: undefined-field
-- Factory overloads map each registered type name to its instance type, so
-- elements of lektor.new("Character") are typed as Character.

local function misspelledFactoryElementMethod()
    local characters = lektor.new("Character")
    local first = characters[1]
    if first then
        first:isImmuneToOffscreenModee()
    end
end

return misspelledFactoryElementMethod
