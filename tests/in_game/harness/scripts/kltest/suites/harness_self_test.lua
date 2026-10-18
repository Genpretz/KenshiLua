local runner = require("kltest.runner")

runner.register_menu_suite("harness-self-test", function(ctx)
    local lifecycle_log = {}
    local before_count = 0
    local after_count = 0

    ctx.before_each(function(t)
        before_count = before_count + 1
        lifecycle_log[#lifecycle_log + 1] = "before:" .. t.name
    end)

    ctx.after_each(function(t)
        after_count = after_count + 1
        lifecycle_log[#lifecycle_log + 1] = "after:" .. t.name
    end)

    ctx.test("assertion helpers validate primitives and formatting", function(t)
        t.assert_true(true, "boolean true")
        t.assert_equal(40 + 2, 42, "integer addition")
        t.assert_equal("kenshi", "kenshi", "string equality")
        t.assert_nil(nil, "nil check")
        t.assert_not_nil(KenshiLua.version(), "version string")
        t.assert_near(3.14159, 3.1416, 1e-3, "float proximity")
        t.assert_match(BinaryVersion.getKenshiVersion():toString(), "1.0.65", "engine version substring")
    end)

    ctx.test("wait_frames yields across live engine frames", function(t)
        local f0 = t.frame_index()
        t.wait_frames(3)
        local f1 = t.frame_index()
        t.assert_equal(f1 - f0, 3, "frames advanced during wait_frames(3)")
    end)

    ctx.test("wait_until polls across frames and returns waited frame count", function(t)
        local f0 = t.frame_index()
        local polls = 0
        local waited = t.wait_until(function()
            polls = polls + 1
            return polls >= 3
        end, 10, "three predicate polls")
        t.assert_equal(waited, 2, "frames waited for 3rd poll")
        t.assert_equal(t.frame_index() - f0, 2, "frame_index delta")
    end)

    local hook_trace = {}
    ctx.test("per-test setup and cleanup hooks execute around coroutine yields", function(t)
        hook_trace[#hook_trace + 1] = "body_start"
        t.wait_frames(1)
        hook_trace[#hook_trace + 1] = "body_after_wait"
    end, {
        setup = function(_t)
            hook_trace[#hook_trace + 1] = "setup"
        end,
        cleanup = function(_t)
            hook_trace[#hook_trace + 1] = "cleanup"
        end,
    })

    ctx.test("verify previous test setup and cleanup hook order", function(t)
        t.assert_equal(table.concat(hook_trace, "->"), "setup->body_start->body_after_wait->cleanup", "hook execution order")
        t.assert_true(before_count >= 5, "before_each counter")
        t.assert_true(after_count >= 4, "after_each counter")
    end)

    ctx.test("isolated assertion failure captures traceback and runs cleanup", function(t)
        local custom_cleaned = false
        local pre_after = after_count
        local outcome = ctx.run_isolated("deliberate_assert_fail", function(inner)
            inner.wait_frames(1)
            inner.assert_equal("actual_val", "expected_val", "deliberate mismatch")
        end, {
            cleanup = function()
                custom_cleaned = true
            end,
        })
        t.assert_equal(outcome.ok, false, "isolated failure ok")
        t.assert_equal(outcome.status, "failed", "isolated failure status")
        t.assert_equal(outcome.frames, 1, "isolated failure waited 1 frame")
        t.assert_true(custom_cleaned, "custom cleanup ran on failure")
        t.assert_equal(after_count, pre_after + 1, "after_each ran on failure")
        t.assert_match(outcome.error, "deliberate mismatch", "failure message")
        t.assert_match(outcome.error, "stack traceback", "failure traceback")
    end)

    ctx.test("isolated Lua runtime error captures traceback and runs cleanup", function(t)
        local cleaned = false
        local outcome = ctx.run_isolated("deliberate_lua_error", function(inner)
            inner.wait_frames(1)
            local nil_table = nil
            ---@diagnostic disable-next-line: need-check-nil, undefined-field
            return nil_table.non_existent_field
        end, {
            cleanup = function()
                cleaned = true
            end,
        })
        t.assert_equal(outcome.ok, false, "runtime error ok")
        t.assert_equal(outcome.status, "failed", "runtime error status")
        t.assert_true(cleaned, "cleanup ran after runtime error")
        t.assert_match(outcome.error, "stack traceback", "runtime error traceback")
    end)

    ctx.test("isolated wait_until frame timeout reports condition and runs cleanup", function(t)
        local cleaned = false
        local outcome = ctx.run_isolated("deliberate_wait_until_timeout", function(inner)
            inner.wait_until(function()
                return false
            end, 2, "never-satisfied condition")
        end, {
            cleanup = function()
                cleaned = true
            end,
        })
        t.assert_equal(outcome.ok, false, "wait_until timeout ok")
        t.assert_equal(outcome.status, "timeout", "wait_until timeout status")
        t.assert_equal(outcome.frames, 2, "wait_until timeout frames")
        t.assert_true(cleaned, "cleanup ran after wait_until timeout")
        t.assert_match(outcome.error, "wait_until timed out after 2 frames waiting for never-satisfied condition", "timeout message")
    end)

    ctx.test("isolated real-time test deadline aborts stalled coroutine and runs cleanup", function(t)
        local cleaned = false
        local outcome = ctx.run_isolated("deliberate_realtime_timeout", function(inner)
            inner.wait_frames(600)
        end, {
            timeout_s = 0.03,
            cleanup = function()
                cleaned = true
            end,
        })
        t.assert_equal(outcome.ok, false, "realtime timeout ok")
        t.assert_equal(outcome.status, "timeout", "realtime timeout status")
        t.assert_true(cleaned, "cleanup ran after realtime timeout")
        t.assert_match(outcome.error, "Test timed out after", "realtime timeout message")
    end)
end)

runner.register_menu_suite("harness-intentional-fail", function(ctx)
    ctx.test("passing baseline case before failure", function(t)
        t.assert_equal(2 + 2, 4, "baseline math")
    end)

    ctx.test("intentional failing case for exit code verification", function(t)
        t.wait_frames(1)
        t.assert_equal("broken_value", "expected_value", "intentional failure sentinel")
    end)
end, { default_enable = false })

