---@param input InputHandler
local function checkInputEnums(input)
    ---@type OIS.KeyCode
    local key = OIS.KeyCode.KC_F8
    input:keyDownEvent(key)
    input:keyUpEvent(OIS.KeyCode.KC_NUMPADENTER)

    ---@type OIS.Keyboard.Modifier
    local modifier = OIS.Keyboard.Modifier.Ctrl
    ---@type OIS.Keyboard.TextTranslationMode
    local translation = OIS.Keyboard.TextTranslationMode.Unicode
    return modifier, translation
end

Events.on("InputHandler::keyDownEvent", function(input, keyCode)
    if keyCode == OIS.KeyCode.KC_ESCAPE then
        print(input, "Escape pressed")
    end
end)

assert(OIS.MouseButtonID.MB_Left == 0)
assert(OIS.Type.OISKeyboard == 1)
assert(OIS.ComponentType.OIS_Vector3 == 5)
assert(OIS.OIS_ERROR.E_General == 8)
assert(OIS.Interface.IType.ForceFeedback == 0)
assert(OIS.InputManager.AddOnFactories.AddOn_WiiMote == 2)
assert(OIS.Effect.EForce.CustomForce == 5)
assert(OIS.Effect.EType.Custom == 12)
assert(OIS.Effect.EDirection.West == 7)

return checkInputEnums
