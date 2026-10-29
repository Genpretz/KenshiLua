---@param line DataPanelLine_Text
---@param panel DatapanelGUI
local function check(line, panel)
 line.wordWrap = true; line:createMe(panel, 0, false); assert(line.wordWrap)
end
return check
