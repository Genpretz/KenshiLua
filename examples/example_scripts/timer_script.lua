local log = KenshiLua.log

local counter = 0

local function timer_test()
    if counter ==0 then
        log("starting timer")
    end
    counter = counter + 1
    log("timer_test: " .. counter)

    if counter >= 1000 then
        log("stopping timer")
        unregisterHandle(handlerId)
    end
end

local handlerId = registerHandler("onCharsUpdate", timer_test)