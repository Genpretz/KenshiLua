-- EXPECT-DIAGNOSTIC: undefined-field
-- Set iterators return ContainerIterator<T, boolean>; the element stays typed.

---@param set OgreUnorderedSet<GameData>
local function misspelledSetElementMethod(set)
    for data in set:items() do
        data:isValidd()
    end
end

return misspelledSetElementMethod
