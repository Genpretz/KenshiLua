-- LuaLS regression fixture: NavMeshGenerator task records and hand lektor.

---@param task NavMeshGenerator_Task
---@param nextTask NavMeshGenerator_Task
---@param zone ZoneMap
---@param buildings Lektor<hand>
---@param output NavInstance
---@param owner hand
---@param ptr lightuserdata
local function checkNavMeshGeneratorTask(task, nextTask, zone, buildings, output, owner, ptr)
    task.zone = zone
    task.buildings = buildings
    task.hash = 1
    task.offset = { 0, 0, 0 }
    task.bounds = ptr
    task.mesh = ptr
    task.output = output
    task.flags = 1
    task.next = nextTask
    assert(task.zone == zone and task.buildings == buildings)
    assert(task.hash == 1 and task.bounds == ptr and task.mesh == ptr)
    assert(task.output == output and task.flags == 1 and task.next == nextTask)

    -- lektor<hand> is registered read-only: indexing, size, and toTable.
    local first = buildings[1]
    assert(first == nil or first == owner)
    assert(buildings:size() >= 0 and buildings:toTable() ~= nil)
end

return checkNavMeshGeneratorTask
