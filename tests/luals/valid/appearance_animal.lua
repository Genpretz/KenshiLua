---@param appearance AppearanceAnimal
local function check(appearance)
 appearance:createBody(); appearance:_NV_createBody(); appearance:updateCharaterTexture(); appearance:_NV_updateCharaterTexture()
end
return check
