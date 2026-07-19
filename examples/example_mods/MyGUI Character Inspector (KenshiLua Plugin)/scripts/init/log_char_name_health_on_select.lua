-- log_char_name_health_on_select.lua
-- onCharacterSelect fires when a character is selected
-- Logs the selected character's name and health info when they are selected
local function onSelect(character)
    KenshiLua.log("[onSelect] handler fired")
    if not character then
        KenshiLua.log("[onSelect] character is nil")
        return
    end
    KenshiLua.log("[onSelect] name: " .. character:getName())
    local med = character:getMedical()
    KenshiLua.log("[onSelect] blood: " .. tostring(med.blood))
    KenshiLua.log("[onSelect] overall health: " .. tostring(med:getOverallHealthRating()))
end

KenshiLua.log("[onSelect] Registering onCharacterSelect handler")
KenshiLua.registerHandler("onCharacterSelect", onSelect)
KenshiLua.log("[onSelect] Done")