local probe = _G.KLTestWorldStateBridgeProbe
if type(probe) ~= "table" then
    error("KLTestWorldStateBridgeProbe was not configured")
end

probe.runs = (probe.runs or 0) + 1
probe.saw_state = currentWorldEventState ~= nil
probe.saw_query = currentWorldEventStateQuery ~= nil
probe.state_id = currentWorldEventState and currentWorldEventState.stringID or nil
probe.query_value = currentWorldEventStateQuery and currentWorldEventStateQuery:isTrue() or nil
