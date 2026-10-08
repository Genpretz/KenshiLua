-- EXPECT-DIAGNOSTIC: undefined-field
-- Map iterators return ContainerIterator<K, V> because LuaLS does not
-- substitute class type parameters inside an inline fun(): K, V.

---@param byId OgreUnorderedMap<integer, GameData>
local function misspelledMapValueMethod(byId)
    for _, data in byId:pairs() do
        data:isValidd()
    end
end

return misspelledMapValueMethod
