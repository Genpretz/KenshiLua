-- LuaLS regression fixture: registered game-root accessors and selected handles.

local world = getGameWorld()
if world and world.player then
    world:togglePause(world:isPaused())
end

local playerInterface = getPlayerInterface()
if playerInterface then
    for handle, _ in pairs(playerInterface.selectedCharacters:toTable()) do
        if not handle:isNull() then
            local character = handle:getCharacter()
            if character then
                character:setProneState(character:getProneState())
            end
        end
    end
end

local forgottenGui = getForgottenGUI()
if forgottenGui and not forgottenGui.selectedObject:isNull() then
    local selectedCharacter = forgottenGui.selectedObject:getCharacter()
    if selectedCharacter then
        KenshiLua.logDebug(selectedCharacter:getName())
    end
end
