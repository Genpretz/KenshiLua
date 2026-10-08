-- LuaLS regression fixture: compact records with raw-pointer fields.

---@param tech ManagementScreen_TechItemViewData
---@param road MapScreen_MapRoad
---@param queue NavMeshGenerator_TaskQueue
---@param task NavMeshGenerator_Task
---@param building TownBuildingsManager_BuildingInfo
---@param node MessageQueue_Node
---@param nextNode MessageQueue_Node
---@param mesh MeshDataLookup
---@param ptr lightuserdata
local function checkSmallRecordTypes(tech, road, queue, task, building, node, nextNode, mesh, ptr)
    tech.item = ptr
    road.widget = ptr
    queue.front = task
    building.visibleFloor = 2
    node.value = ptr
    node.next = nextNode
    mesh.verts = ptr
    mesh.uvs = ptr

    assert(tech.item == ptr and road.widget == ptr)
    assert(queue.front == task and building.visibleFloor == 2)
    assert(node.value == ptr and node.next == nextNode)
    assert(mesh.verts == ptr and mesh.uvs == ptr)
end

return checkSmallRecordTypes
