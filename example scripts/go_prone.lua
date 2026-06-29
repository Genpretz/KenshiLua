-- go_prone.lua
local KC_V = 47

local function toggle_prone()
    KenshiLua.log("[Go Prone] toggle_prone called")

    local world = getGameWorld()
    if not world then
        KenshiLua.log("[Go Prone] No world")
        return
    end

    local c = world:getPlayer():getSelectedCharacterHandle():getCharacter()
    if not c then
        KenshiLua.log("[Go Prone] No selected character")
        return
    end

    local prone_state = c:getProneState()
    KenshiLua.log("[Go Prone] Current prone state: " .. tostring(prone_state))

    local prone_state = c:getProneState()

    if prone_state == ProneState.PS_NORMAL then
        KenshiLua.log("[Go Prone] Going prone")
        c:setProneState(ProneState.PS_STAYING_LOW)
    else
        KenshiLua.log("[Go Prone] Leaving prone")
        c:setProneState(ProneState.PS_NORMAL)
    end
end

local function on_key_down(key_code)
    KenshiLua.log("[Go Prone] Key pressed: " .. tostring(key_code))
    if key_code == KC_V then
        KenshiLua.log("[Go Prone] V key detected, toggling prone")
        toggle_prone()
    end
end

KenshiLua.log("[Go Prone] Registering key callback")
KenshiLua.registerHandler("onKeyDown", on_key_down)
KenshiLua.log("[Go Prone] Callback registered")