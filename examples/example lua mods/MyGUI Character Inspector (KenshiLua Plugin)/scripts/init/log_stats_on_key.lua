--log_stats_on_key.lua
-- Press F key (keycode 33) to log the selected character's combat stats
local KC_F = 33

local function printSelectedCharStats()
    local gw = getGameWorld()
    if not gw then KenshiLua.log("[stats] no gameworld"); return end

    local p = gw:getPlayer()
    if not p then KenshiLua.log("[stats] no player"); return end

    local h = p:getSelectedCharacterHandle()
    if not h then KenshiLua.log("[stats] no handle"); return end
    if not h:isValid() then KenshiLua.log("[stats] handle not valid"); return end

    local c = h:getCharacter()
    if not c then KenshiLua.log("[stats] no character"); return end

    KenshiLua.log("[stats] --- " .. c:getName() .. " ---")
    local stats = c:getStats()
    KenshiLua.log("[stats] melee attack: " .. tostring(stats:getMeleeAttack()))
    KenshiLua.log("[stats] melee defence: " .. tostring(stats:getMeleeDefence()))
    KenshiLua.log("[stats] strength: " .. tostring(stats:getStrength()))
    KenshiLua.log("[stats] toughness: " .. tostring(stats:getToughness()))
    KenshiLua.log("[stats] stealth: " .. tostring(stats:getStealth()))
end

local function onKey(keyCode)
    if keyCode == KC_F then
        printSelectedCharStats()
    end
end

KenshiLua.log("[stats] Registering onKeyDown handler")
KenshiLua.registerHandler("onKeyDown", onKey)
KenshiLua.log("[stats] Done")