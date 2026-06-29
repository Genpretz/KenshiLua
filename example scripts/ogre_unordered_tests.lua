-- 1. Retrieve the selected character's race GameData
local world = getGameWorld()
if not world then
    log("[Ogre Unordered Tests] Error: No active GameWorld.")
    return
end

local player = world:getPlayer()
if not player then
    log("[Ogre Unordered Tests] Error: No PlayerInterface.")
    return
end

local charHandle = player:getSelectedCharacterHandle()
if not charHandle then
    log("[Ogre Unordered Tests] Error: No selected character handle. Please select a character first.")
    return
end

local c = charHandle:getCharacter()
if not c then
    log("[Ogre Unordered Tests] Error: No selected character. Please select a character first.")
    return
end

local race = c.race
if not race then
    log("[Ogre Unordered Tests] Error: Selected character has no race.")
    return
end

local gamedata = race.data
if not gamedata then
    log("[Ogre Unordered Tests] Error: Selected character's race has no template data.")
    return
end

-- Retrieve the map reference wrapper
local bdata = gamedata.bdata

-- 2. Check size and has/exists
print("Size of bdata:", bdata:size()) -- or #bdata
print("Has 'my_boolean_flag'?", bdata:has("my_boolean_flag"))

-- 3. Write / Insert a new key-value pair
bdata["my_boolean_flag"] = true

-- 4. Read / Lookup a value
local flag = bdata["my_boolean_flag"]
print("Value is:", flag) -- Output: true

-- 5. Update an existing key-value pair
bdata["my_boolean_flag"] = false

-- 6. Remove a key-value pair
-- Option A: Assigning nil removes it (standard Lua behavior)
bdata["my_boolean_flag"] = nil

-- Option B: Calling the remove method
bdata:remove("my_boolean_flag")

-- 7. Snapshot and Iteration
-- Since boost::unordered_map does not have stable Lua-native __pairs,
-- toTable() creates a snapshot table that you can iterate normally:
for key, value in pairs(bdata:toTable()) do
    print(key, value)
end

-- 8. Clear the map
bdata:clear()
print("Size after clear:", bdata:size()) -- Output: 0
