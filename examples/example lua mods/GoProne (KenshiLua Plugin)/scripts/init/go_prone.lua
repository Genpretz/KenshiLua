-- go_prone.lua
local logDebug = KenshiLua.logDebug
local KC_V = 47

local function toggle_prone()
    logDebug("[Go Prone] toggle_prone called")

    local world = getGameWorld()
    if not world then
        logDebug("[Go Prone] No world")
        return
    end

    local selected = getPlayerInterface().selectedCharacters
    if not selected then
        logDebug("[Go Prone] No selected characters set found")
        return
    end

    local count = 0
    for h, _ in pairs(selected:toTable()) do
        local c = h:getCharacter()
        if c then
            count = count + 1
            local prone_state = c:getProneState()
            logDebug("[Go Prone] Character " .. tostring(count) .. " current prone state: " .. tostring(prone_state))

            if prone_state == ProneState.PS_NORMAL then
                logDebug("[Go Prone] Going prone")
                c:setProneState(ProneState.PS_STAYING_LOW)
            else
                logDebug("[Go Prone] Leaving prone")
                c:setProneState(ProneState.PS_NORMAL)
            end
        end
    end
    
    if count == 0 then
        logDebug("[Go Prone] No valid selected characters")
    else
        logDebug("[Go Prone] Toggled prone state for " .. tostring(count) .. " characters")
    end
end

local function on_key_down(key_code)
    logDebug("[Go Prone] Key pressed: " .. tostring(key_code))
    if key_code == KC_V then
        logDebug("[Go Prone] V key detected, toggling prone")
        toggle_prone()
    end
end

logDebug("[Go Prone] Registering key callback")
registerHandler("onKeyDown", on_key_down)
logDebug("[Go Prone] Callback registered")