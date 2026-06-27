-- go_prone.lua
local log = KenshiLua.log
local KC_V = 47

local function toggle_prone()
    log("[Go Prone] toggle_prone called")

    local world = getGameWorld()
    if not world then
        log("[Go Prone] No world")
        return
    end

    local c = getPlayerInterface().selectedCharacter:getCharacter()
    if not c then
        log("[Go Prone] No selected character")
        return
    end

    local prone_state = c:getProneState()
    log("[Go Prone] Current prone state: " .. tostring(prone_state))

    local prone_state = c:getProneState()

    if prone_state == ProneState.PS_NORMAL then
        log("[Go Prone] Going prone")
        c:setProneState(ProneState.PS_STAYING_LOW)
    else
        log("[Go Prone] Leaving prone")
        c:setProneState(ProneState.PS_NORMAL)
    end
end

local function on_key_down(key_code)
    log("[Go Prone] Key pressed: " .. tostring(key_code))
    if key_code == KC_V then
        log("[Go Prone] V key detected, toggling prone")
        toggle_prone()
    end
end

log("[Go Prone] Registering key callback")
registerHandler("onKeyDown", on_key_down)
log("[Go Prone] Callback registered")