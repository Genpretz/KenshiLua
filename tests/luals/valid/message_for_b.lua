-- LuaLS regression fixture: MessageForB value factory.

local function checkMessageForB()
    local defaultMessage = MessageForB.new()
    local typedMessage = MessageForB.new(1, 2)
    typedMessage.messageType = 3
    typedMessage.messageInt = 4
    assert(defaultMessage ~= nil and typedMessage.messageType == 3 and typedMessage.messageInt == 4)
end

return checkMessageForB
