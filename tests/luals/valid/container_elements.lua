-- LuaLS regression fixture: container element, key, and value types.

---@param players PlayerInterface
---@param byId OgreUnorderedMap<integer, GameData>
---@param set OgreUnorderedSet<GameData>
---@param names Lektor<string>
local function checkContainerElements(players, byId, set, names)
    local characters = players:getAllPlayerCharacters()
    if characters then
        local first = characters[1]
        if first then
            assert(first:isImmuneToOffscreenMode() ~= nil)
        end
        for _, character in ipairs(characters:toTable() or {}) do
            assert(character:isImmuneToOffscreenMode() ~= nil)
        end
        assert(characters:size() >= 0)
    end

    local data = byId[1]
    if data then
        assert(data:isValid() ~= nil)
        assert(set:has(data) == set[data])
    end
    for id, record in byId:pairs() do
        assert(id >= 0 and record:isValid() ~= nil)
    end

    names:push("name")
    local name = names:pop()
    assert(name == nil or #name >= 0)

    -- Factories return the registered instance type for literal type names.
    local ints = lektor.new("int")
    ints:push(1)
    local handles = ogre_unordered_set.new("hand")
    local weights = ogre_unordered_map.new("hand", "float")
    for h in handles:items() do
        weights[h] = (weights[h] or 0) + ints:size()
    end
    local any = lektor(Character)
    assert(any:size() >= 0)
end

return checkContainerElements
