---@param line DataPanelLine_Text
---@param panel DatapanelGUI
local function check(line, panel)
 line.wordWrap = true; line:createMe(panel, 0, false); line:_NV_createMe(panel, 0, true); assert(line.wordWrap)
end
return check
