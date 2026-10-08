-- LuaLS regression fixture: resource UI and loading requests.

---@param line ResourceLinePanel
---@param mesh ResourceLoadRequestMesh
---@param texture ResourceLoadRequestTexture
local function checkResourceLoadRequests(line, mesh, texture)
    local widget = line:getWidget()
    assert(widget == nil or line.button ~= nil)
    mesh:finish()
    assert(mesh.entity == nil or type(mesh.entity) == "userdata")
    assert(type(texture:isMaterialValid()) == "boolean")
    assert(texture.textureUnitState == nil or type(texture.textureUnitState) == "userdata")
end

return checkResourceLoadRequests
