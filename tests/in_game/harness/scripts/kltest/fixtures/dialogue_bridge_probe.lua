local probe = _G.KLTestDialogueBridgeProbe
if type(probe) ~= "table" then
    error("KLTestDialogueBridgeProbe was not configured")
end

probe.runs = (probe.runs or 0) + 1
probe.saw_dialogue = currentDialogue ~= nil
probe.saw_line = currentDialogueLine ~= nil
probe.line_id = currentDialogueLine and currentDialogueLine:getStringID() or nil

if probe.mode == "nested" and not probe.inside_nested_call then
    local outer_dialogue = currentDialogue
    local outer_line = currentDialogueLine
    local outer_line_id = probe.line_id

    probe.inside_nested_call = true
    outer_dialogue:_doActions(outer_line)
    probe.inside_nested_call = false

    probe.context_restored = currentDialogue ~= nil
        and currentDialogueLine ~= nil
        and currentDialogueLine:getStringID() == outer_line_id
elseif probe.mode == "handlers" then
    probe.handler_ids = probe.handler_ids or {}
    probe.handler_ticks = probe.handler_ticks or {}

    local slot = #probe.handler_ids + 1
    probe.handler_ticks[slot] = 0
    probe.handler_ids[slot] = Events.on("Dialogue::_doActions", function()
        probe.handler_ticks[slot] = probe.handler_ticks[slot] + 1
    end)
elseif probe.mode == "widgets" then
    probe.widget_names = probe.widget_names or {}

    local name = "KLTestDialogueBridgeWidget" .. tostring(probe.runs)
    probe.widget_names[#probe.widget_names + 1] = name
    local widget = MyGUI.createWindow("WindowCS", -10000, -10000, 1, 1, name, "Window")
    if widget == nil then
        error("could not create dialogue bridge test widget")
    end
end
