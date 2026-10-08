---@param mesh MeshLoadData
---@param particle ParticlePool_ParticleData
---@param data GameData
---@param ptr lightuserdata
local function check(mesh, particle, data, ptr)
 mesh.skeletonName, mesh.materialName, mesh.renderQueue = "s", "m", 1
 particle.particle, particle.effectData, particle.node = ptr, data, ptr
 assert(mesh.renderQueue == 1 and particle.effectData == data)
end
return check
