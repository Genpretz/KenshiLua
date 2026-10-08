---@param queue Terrain_BloodQueue
local function check(queue)
 queue.patch, queue.sector, queue.depth = 1, 2, 3
 assert(queue.patch == 1 and queue.sector == 2 and queue.depth == 3)
end
return check
