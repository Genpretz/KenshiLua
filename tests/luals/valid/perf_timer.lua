-- LuaLS regression fixture: CPerfTimer timing and arithmetic API.

---@param timer CPerfTimer
---@param other CPerfTimer
---@param derived CPerfTimerT
local function checkPerfTimer(timer, other, derived)
    timer:Start(true)
    timer:Stop()
    assert(type(timer:IsRunning()) == "boolean")
    assert(type(timer:IsSupported()) == "boolean")
    assert(timer:Resolution() >= 0 and timer:Resolutionms() >= 0 and timer:Resolutionus() >= 0)
    assert(timer:Elapsed() >= 0 and timer:Elapsedms() >= 0 and timer:Elapsedus() >= 0)

    timer:operator_assign(other)
    timer:operator_add(other)
    timer:operator_sub(1)
    timer:operator_add_assign(other)
    timer:operator_sub_assign(1)
    assert(timer:operator_lt(other) == (timer < other))
    assert(timer:operator_le(1) == (timer <= 1))
    assert(timer:operator_gt(other) and timer:operator_ge(1) or true)
    local sum = timer + other
    local difference = timer - 1
    assert(sum ~= nil and difference ~= nil and derived ~= nil)
end

return checkPerfTimer
