local json = require("kltest.json")
local assertions = require("kltest.assertions")

local M = {}

local state = {
    config = nil,
    phase = "UNINITIALIZED",
    boot_clock = os.clock(),
    frame_index = 0,
    world_frame_index = 0,
    first_title_show_clock = nil,
    first_title_update_clock = nil,
    first_frame_title_clock = nil,
    title_ticks = 0,
    first_world_update_clock = nil,
    world_ready_clock = nil,
    world_ready_consecutive = 0,
    world_total_ticks = 0,
    world_request_clock = nil,
    observed_loading_busy = false,
    last_world_status = nil,
    menu_suites = {},
    game_suites = {},
    active_scheduler_co = nil,
    active_scheduler_kind = nil,
    cases = {},
    passed = 0,
    failed = 0,
    skipped = 0,
    completed = false,
    title_handlers_installed = false,
    frame_handler_installed = false,
    world_handler_installed = false,
}

local function now_seconds()
    return tonumber(string.format("%.4f", os.clock() - state.boot_clock))
end

local function append_event(record)
    if not state.config or not state.config.events_path then
        return
    end
    record.run_id = state.config.run_id
    record.elapsed_s = now_seconds()
    record.timestamp = os.time()
    record.frame = state.frame_index
    record.world_frame = state.world_frame_index
    local line = json.encode(record) .. "\n"
    local f, err = io.open(state.config.events_path, "ab")
    if f then
        f:write(line)
        f:flush()
        f:close()
    else
        KenshiLua.logError("[KLTest] Failed to write events.ndjson: " .. tostring(err))
    end
end

local function write_atomic_result(summary)
    if not state.config or not state.config.result_path then
        return
    end
    local final_path = state.config.result_path
    local tmp_path = final_path .. ".tmp"
    local payload = json.encode(summary) .. "\n"

    local f, err = io.open(tmp_path, "wb")
    if not f then
        KenshiLua.logError("[KLTest] Failed to open temp result file: " .. tostring(err))
        return
    end
    f:write(payload)
    f:flush()
    f:close()

    os.remove(final_path)
    local ok, rename_err = os.rename(tmp_path, final_path)
    if not ok then
        KenshiLua.logWarn("[KLTest] os.rename failed (" .. tostring(rename_err) .. "), writing result.json directly")
        local direct, direct_err = io.open(final_path, "wb")
        if direct then
            direct:write(payload)
            direct:flush()
            direct:close()
        else
            KenshiLua.logError("[KLTest] Direct write of result.json failed: " .. tostring(direct_err))
        end
        os.remove(tmp_path)
    end
end

local function set_phase(new_phase, extra)
    state.phase = new_phase
    local ev = {
        type = "phase",
        phase = new_phase,
    }
    if extra then
        for k, v in pairs(extra) do
            ev[k] = v
        end
    end
    append_event(ev)
end

local function suite_enabled(entry)
    local name = entry.name
    local opts = entry.opts or {}
    local default_enable = (opts.default_enable ~= false)
    if not state.config or type(state.config.suites) ~= "table" or #state.config.suites == 0 then
        return default_enable
    end
    for i = 1, #state.config.suites do
        local s = state.config.suites[i]
        if s == name then
            return true
        end
        if default_enable and (s == "all" or s == "smoke") then
            if s == "smoke" and opts.phase == "GAME_TESTS" and not state.config.save_name and not opts.smoke_default then
                -- Keep menu-only smoke fast unless save_name or world-smoke is requested
            else
                return true
            end
        end
    end
    return false
end

local function has_enabled_suites(list)
    for i = 1, #list do
        if suite_enabled(list[i]) then
            return true
        end
    end
    return false
end

local function test_matches_filter(suite_name, case_name)
    local filter = state.config and state.config.filter or nil
    if type(filter) ~= "string" or filter == "" then
        return true
    end
    local full = tostring(suite_name) .. "/" .. tostring(case_name)
    local f_lower = filter:lower()
    if full:lower():find(f_lower, 1, true) ~= nil then
        return true
    end
    if tostring(case_name):lower():find(f_lower, 1, true) ~= nil then
        return true
    end
    local ok_pat, matched = pcall(function()
        return full:find(filter) ~= nil or tostring(case_name):find(filter) ~= nil
    end)
    return ok_pat and matched or false
end

function M.wait_frames(count)
    local frames = tonumber(count) or 1
    if frames < 1 then
        frames = 1
    end
    for i = 1, frames do
        coroutine.yield({
            kind = "wait_frames",
            step = i,
            total = frames,
        })
    end
end

function M.wait_until(predicate, timeout_frames, description)
    if type(predicate) ~= "function" then
        error("wait_until: predicate must be a function", 2)
    end
    local max_frames = tonumber(timeout_frames) or 60
    if max_frames < 1 then
        max_frames = 1
    end
    local desc = description or "condition"
    for waited = 0, max_frames do
        local ok, res = pcall(predicate)
        if not ok then
            error(string.format("wait_until(%s) predicate raised error: %s", tostring(desc), tostring(res)), 2)
        end
        if res then
            return waited
        end
        if waited < max_frames then
            coroutine.yield({
                kind = "wait_until",
                description = desc,
                waited = waited + 1,
                max_frames = max_frames,
            })
        end
    end
    error(string.format("wait_until timed out after %d frames waiting for %s", max_frames, tostring(desc)), 2)
end

function M.register_menu_suite(suite_name, fn, opts)
    local suite_opts = opts or {}
    suite_opts.phase = "MENU_TESTS"
    state.menu_suites[#state.menu_suites + 1] = {
        name = suite_name,
        fn = fn,
        opts = suite_opts,
    }
    append_event({
        type = "suite_registered",
        suite = suite_name,
        phase = "MENU_TESTS",
    })
end

function M.register_game_suite(suite_name, fn, opts)
    local suite_opts = opts or {}
    suite_opts.phase = "GAME_TESTS"
    state.game_suites[#state.game_suites + 1] = {
        name = suite_name,
        fn = fn,
        opts = suite_opts,
    }
    append_event({
        type = "suite_registered",
        suite = suite_name,
        phase = "GAME_TESTS",
    })
end

local function format_co_traceback(co, err_val)
    local msg = tostring(err_val)
    if debug and type(debug.traceback) == "function" then
        local ok, trace = pcall(debug.traceback, co, msg)
        if ok and type(trace) == "string" then
            return trace
        end
    end
    return msg
end

local function run_hook_coroutine(hook_fn, timeout_s, label)
    if type(hook_fn) ~= "function" then
        return true, nil
    end
    local start_clock = os.clock()
    local deadline = start_clock + (timeout_s or 5.0)
    local co = coroutine.create(hook_fn)
    while coroutine.status(co) ~= "dead" do
        local ok, yielded = coroutine.resume(co)
        if not ok then
            return false, format_co_traceback(co, yielded)
        end
        if coroutine.status(co) == "dead" then
            break
        end
        if coroutine.running() == nil then
            return false, tostring(label or "hook") .. " attempted to yield outside active scheduler coroutine"
        end
        coroutine.yield(yielded)
        if os.clock() > deadline then
            return false, format_co_traceback(co, string.format("%s timed out after %.2fs", tostring(label or "hook"), os.clock() - start_clock))
        end
    end
    return true, nil
end

function M.execute_case_internal(suite_ctx, case_name, case_fn, case_opts, record_result)
    local suite_name = suite_ctx.suite
    local opts = case_opts or {}

    if record_result and not test_matches_filter(suite_name, case_name) then
        state.skipped = state.skipped + 1
        local skipped_entry = {
            suite = suite_name,
            name = case_name,
            phase = state.phase,
            status = "skipped",
            duration_s = 0,
            frames = 0,
        }
        state.cases[#state.cases + 1] = skipped_entry
        append_event({
            type = "test_skipped",
            suite = suite_name,
            name = case_name,
            phase = state.phase,
        })
        return {
            ok = true,
            status = "skipped",
            duration_s = 0,
            frames = 0,
            error = nil,
            cleanup_ran = false,
        }
    end

    local start_clock = os.clock()
    local start_frame = state.frame_index
    local timeout_s = tonumber(opts.timeout_s)
        or (state.config and tonumber(state.config.test_timeout_s))
        or 10.0
    local deadline = start_clock + timeout_s

    if record_result then
        append_event({
            type = "test_start",
            suite = suite_name,
            name = case_name,
            phase = state.phase,
            timeout_s = timeout_s,
        })
    end

    local test_status = "passed"
    local test_error = nil
    local cleanup_ran = false

    local t_ctx = {
        suite = suite_name,
        name = case_name,
        phase = state.phase,
        wait_frames = M.wait_frames,
        wait_until = M.wait_until,
        frame_index = function() return state.frame_index end,
        world_frame_index = function() return state.world_frame_index end,
        assert_true = assertions.assert_true,
        assert_equal = assertions.assert_equal,
        assert_nil = assertions.assert_nil,
        assert_not_nil = assertions.assert_not_nil,
        assert_near = assertions.assert_near,
        assert_match = assertions.assert_match,
    }

    -- 1. before_each and per-test setup
    if suite_ctx._before_each then
        local ok_pre, err_pre = run_hook_coroutine(function()
            suite_ctx._before_each(t_ctx)
        end, timeout_s, "before_each")
        if not ok_pre then
            test_status = "failed"
            test_error = "before_each failed: " .. tostring(err_pre)
        end
    end

    if test_status == "passed" and type(opts.setup) == "function" then
        local ok_setup, err_setup = run_hook_coroutine(function()
            opts.setup(t_ctx)
        end, timeout_s, "setup")
        if not ok_setup then
            test_status = "failed"
            test_error = "setup failed: " .. tostring(err_setup)
        end
    end

    -- 2. Main test coroutine
    if test_status == "passed" then
        local co = coroutine.create(function()
            case_fn(t_ctx)
        end)

        while coroutine.status(co) ~= "dead" do
            local ok, yielded = coroutine.resume(co)
            if not ok then
                local raw_msg = tostring(yielded)
                if raw_msg:find("timed out", 1, true) ~= nil then
                    test_status = "timeout"
                else
                    test_status = "failed"
                end
                test_error = format_co_traceback(co, yielded)
                break
            end
            if coroutine.status(co) == "dead" then
                break
            end
            if coroutine.running() == nil then
                test_status = "failed"
                test_error = format_co_traceback(co, "Test yielded outside active frame scheduler coroutine")
                break
            end
            coroutine.yield(yielded)
            if os.clock() > deadline then
                test_status = "timeout"
                local elapsed = os.clock() - start_clock
                test_error = format_co_traceback(
                    co,
                    string.format("Test timed out after %.3fs (limit %.3fs)", elapsed, timeout_s)
                )
                break
            end
        end
    end

    -- 3. Per-test cleanup and suite after_each (always run)
    if type(opts.cleanup) == "function" then
        cleanup_ran = true
        local ok_clean, err_clean = run_hook_coroutine(function()
            opts.cleanup(t_ctx)
        end, timeout_s, "cleanup")
        if not ok_clean then
            if test_status == "passed" then
                test_status = "failed"
                test_error = "cleanup failed: " .. tostring(err_clean)
            else
                test_error = tostring(test_error) .. "\n[cleanup error]: " .. tostring(err_clean)
            end
        end
    end

    if suite_ctx._after_each then
        cleanup_ran = true
        local ok_post, err_post = run_hook_coroutine(function()
            suite_ctx._after_each(t_ctx)
        end, timeout_s, "after_each")
        if not ok_post then
            if test_status == "passed" then
                test_status = "failed"
                test_error = "after_each failed: " .. tostring(err_post)
            else
                test_error = tostring(test_error) .. "\n[after_each error]: " .. tostring(err_post)
            end
        end
    end

    local duration_s = tonumber(string.format("%.4f", os.clock() - start_clock))
    local frames_elapsed = state.frame_index - start_frame
    local passed = (test_status == "passed")

    if record_result then
        if passed then
            state.passed = state.passed + 1
        else
            state.failed = state.failed + 1
        end

        local case_record = {
            suite = suite_name,
            name = case_name,
            phase = state.phase,
            status = test_status,
            duration_s = duration_s,
            frames = frames_elapsed,
        }
        if not passed then
            case_record.error = tostring(test_error)
        end
        state.cases[#state.cases + 1] = case_record

        local ev = {
            type = "test_result",
            suite = suite_name,
            name = case_name,
            phase = state.phase,
            status = test_status,
            duration_s = duration_s,
            frames = frames_elapsed,
        }
        if not passed then
            ev.error = tostring(test_error)
        end
        append_event(ev)
    end

    return {
        ok = passed,
        status = test_status,
        duration_s = duration_s,
        frames = frames_elapsed,
        error = test_error,
        cleanup_ran = cleanup_ran,
    }
end

function M.run_case(suite_name, case_name, fn, opts)
    local dummy_ctx = { suite = suite_name }
    local outcome = M.execute_case_internal(dummy_ctx, case_name, fn, opts, true)
    return outcome.ok, outcome.error
end

local detach_all_handlers

local function finish_run(fatal_error)
    if state.completed then
        return
    end
    state.completed = true
    detach_all_handlers()

    local ver = BinaryVersion.getKenshiVersion()
    local status = "passed"
    if fatal_error ~= nil then
        status = "error"
        set_phase("FAILED", { error = tostring(fatal_error) })
    elseif state.failed > 0 then
        status = "failed"
        set_phase("WRITE_RESULT", { status = status })
    else
        set_phase("WRITE_RESULT", { status = status })
    end

    local summary = {
        run_id = state.config and state.config.run_id or "unknown",
        status = status,
        passed = state.passed,
        failed = state.failed,
        skipped = state.skipped,
        total = state.passed + state.failed,
        elapsed_s = now_seconds(),
        frames_observed = state.frame_index,
        world_frames_observed = state.world_frame_index,
        kenshilua_version = KenshiLua.version(),
        kenshi_version = ver and ver:toString() or "unknown",
        kenshi_platform = ver and ver:getPlatformStr() or "unknown",
        kenshi_binary = ver and ver:getBinaryName() or "unknown",
        provider_mod = state.config and state.config.provider_mod or "KenshiLua.mod",
        save_name = state.config and state.config.save_name or false,
        title_signals = {
            first_show_s = state.first_title_show_clock or false,
            first_update_s = state.first_title_update_clock or false,
            first_frame_s = state.first_frame_title_clock or false,
            ticks_observed = state.title_ticks,
        },
        world_signals = {
            first_chars_update_s = state.first_world_update_clock or false,
            world_ready_s = state.world_ready_clock or false,
            ready_consecutive_ticks = state.world_ready_consecutive,
            total_chars_update_ticks = state.world_total_ticks,
            observed_loading_busy = state.observed_loading_busy,
            last_status = state.last_world_status or false,
        },
        fatal_error = fatal_error or false,
        cases = state.cases,
    }

    append_event({
        type = "run_complete",
        status = status,
        passed = state.passed,
        failed = state.failed,
        skipped = state.skipped,
        total = state.passed + state.failed,
    })
    write_atomic_result(summary)
    KenshiLua.log(string.format("[KLTest] Run %s complete: status=%s passed=%d failed=%d skipped=%d",
        tostring(summary.run_id), status, state.passed, state.failed, state.skipped))

    if state.config and state.config.request_exit then
        local ok_exit, exit_err = pcall(function()
            local ts = TitleScreen.getSingleton()
            if ts ~= nil then
                append_event({ type = "exit_requested", method = "TitleScreen:exitGame" })
                ts:exitGame(nil)
            end
        end)
        if not ok_exit then
            KenshiLua.logWarn("[KLTest] TitleScreen:exitGame error: " .. tostring(exit_err))
        end
    end
end

local function build_suite_context(suite_name)
    local ctx = {
        suite = suite_name,
        _before_each = nil,
        _after_each = nil,
        wait_frames = M.wait_frames,
        wait_until = M.wait_until,
        frame_index = function() return state.frame_index end,
        world_frame_index = function() return state.world_frame_index end,
        assert_true = assertions.assert_true,
        assert_equal = assertions.assert_equal,
        assert_nil = assertions.assert_nil,
        assert_not_nil = assertions.assert_not_nil,
        assert_near = assertions.assert_near,
        assert_match = assertions.assert_match,
    }
    ctx.before_each = function(fn)
        ctx._before_each = fn
    end
    ctx.after_each = function(fn)
        ctx._after_each = fn
    end
    ctx.test = function(case_name, case_fn, case_opts)
        local outcome = M.execute_case_internal(ctx, case_name, case_fn, case_opts, true)
        return outcome.ok, outcome.error
    end
    ctx.run_isolated = function(case_name, case_fn, case_opts)
        local iso_ctx = {
            suite = suite_name,
            _before_each = ctx._before_each,
            _after_each = ctx._after_each,
        }
        return M.execute_case_internal(iso_ctx, case_name, case_fn, case_opts, false)
    end
    return ctx
end

local function create_suites_scheduler(suite_list, on_complete)
    return coroutine.create(function()
        local executed_any = false
        for i = 1, #suite_list do
            local entry = suite_list[i]
            if suite_enabled(entry) then
                executed_any = true
                append_event({
                    type = "suite_start",
                    suite = entry.name,
                    phase = state.phase,
                })
                local ctx = build_suite_context(entry.name)
                local suite_co = coroutine.create(function()
                    entry.fn(ctx)
                end)
                local suite_ok = true
                local suite_err = nil
                while coroutine.status(suite_co) ~= "dead" do
                    local ok, yielded = coroutine.resume(suite_co)
                    if not ok then
                        suite_ok = false
                        suite_err = format_co_traceback(suite_co, yielded)
                        break
                    end
                    if coroutine.status(suite_co) == "dead" then
                        break
                    end
                    coroutine.yield(yielded)
                end
                append_event({
                    type = "suite_end",
                    suite = entry.name,
                    phase = state.phase,
                    ok = suite_ok,
                    error = (not suite_ok) and tostring(suite_err) or false,
                })
                if not suite_ok then
                    finish_run("Suite '" .. tostring(entry.name) .. "' aborted: " .. tostring(suite_err))
                    return
                end
            end
        end
        on_complete(executed_any)
    end)
end

local function step_active_scheduler()
    local co = state.active_scheduler_co
    if not co then
        return
    end
    if state.last_stepped_frame == state.frame_index then
        return
    end
    state.last_stepped_frame = state.frame_index

    if coroutine.status(co) == "dead" then
        state.active_scheduler_co = nil
        return
    end
    local ok, err = coroutine.resume(co)
    if not ok then
        state.active_scheduler_co = nil
        finish_run("Scheduler coroutine error: " .. format_co_traceback(co, err))
        return
    end
    if coroutine.status(co) == "dead" then
        state.active_scheduler_co = nil
    end
end

local function trim_slashes(s)
    return (tostring(s or ""):gsub("[/\\]+$", ""))
end

local function basename_of(path_str)
    local cleaned = trim_slashes(path_str)
    local base = cleaned:match("([^/\\]+)$")
    return base or cleaned
end

local function save_matches_requested(current_game, active_save, requested_save)
    if type(requested_save) ~= "string" or requested_save == "" or requested_save:sub(1, 8) == "@newgame" then
        return true
    end
    local req_lower = basename_of(requested_save):lower()
    local cur_base = basename_of(current_game or ""):lower()
    local act_base = basename_of(active_save or ""):lower()
    return (cur_base ~= "" and cur_base == req_lower) or (act_base ~= "" and act_base == req_lower)
end

local function evaluate_world_readiness()
    local requested_save = state.config and state.config.save_name or nil
    local gw = getGameWorld()
    local sm = SaveManager.getSingleton()
    local sfs = SaveFileSystem.getSingleton()
    local player = getPlayerInterface()

    local gw_init = (gw ~= nil and gw.initialized == true)
    local gw_not_resetting = (gw ~= nil and gw.gameResetting == false)
    local gw_not_loading = (gw ~= nil and gw:isLoadingFromASaveGame() == false)
    local gw_paused = (gw ~= nil and gw:isPaused() == true)
    local sfs_busy = (sfs ~= nil and sfs:busy() == true)
    local sfs_not_busy = (sfs ~= nil and not sfs_busy)
    local current_game = (sm ~= nil and sm:getCurrentGame()) or ""
    local active_save = (sfs ~= nil and sfs:getActiveSave()) or ""
    local save_path = (sm ~= nil and sm:getSavePath()) or ""
    local local_save_path = (sm ~= nil and sm.localSavePath) or ""
    local user_save_path = (sm ~= nil and sm.userSavePath) or ""
    local save_matched = save_matches_requested(current_game, active_save, requested_save)
    local player_ok = (player ~= nil)
    local char_edit_mode = (player ~= nil and player:getCharacterEditMode() == true)

    if sfs_busy or (gw ~= nil and gw:isLoadingFromASaveGame()) then
        state.observed_loading_busy = true
    end

    local status = {
        gw_initialized = gw_init,
        gw_not_resetting = gw_not_resetting,
        gw_not_loading = gw_not_loading,
        gw_paused = gw_paused,
        sfs_not_busy = sfs_not_busy,
        save_matched = save_matched,
        player_present = player_ok,
        char_edit_mode = char_edit_mode,
        current_game = current_game,
        active_save = active_save,
        save_path = save_path,
        local_save_path = local_save_path,
        user_save_path = user_save_path,
        requested_save = requested_save or "",
    }
    state.last_world_status = status

    local all_ready = gw_init
        and gw_not_resetting
        and gw_not_loading
        and sfs_not_busy
        and save_matched
        and player_ok
        and (not char_edit_mode)

    return all_ready, status
end

local on_title_show
local on_title_update
local on_frame_start
local on_chars_update

local function detach_title_only_handlers()
    if not state.title_handlers_installed then
        return
    end
    state.title_handlers_installed = false
    if state.title_show_id then
        pcall(KenshiLua.unregisterHandler, state.title_show_id)
        state.title_show_id = nil
    end
    if state.title_update_id then
        pcall(KenshiLua.unregisterHandler, state.title_update_id)
        state.title_update_id = nil
    end
end

detach_all_handlers = function()
    detach_title_only_handlers()
    if state.frame_handler_installed then
        state.frame_handler_installed = false
        if state.frame_handler_id then
            pcall(KenshiLua.unregisterHandler, state.frame_handler_id)
            state.frame_handler_id = nil
        end
    end
    if state.world_handler_installed then
        state.world_handler_installed = false
        if state.world_handler_id then
            pcall(KenshiLua.unregisterHandler, state.world_handler_id)
            state.world_handler_id = nil
        end
    end
end

local function resolve_newgame_start_id(spec)
    local explicit = tostring(spec or ""):match("^@newgame:(.+)$")
    if explicit and #explicit > 0 then
        return explicit
    end
    local gw = getGameWorld()
    if gw ~= nil and gw.gamedata ~= nil then
        for _, candidate_name in ipairs({ "Wanderer", "The Wanderer", "Guy with a dog", "Cannibal Hunters" }) do
            local ok_name, by_name = pcall(function()
                return gw.gamedata:getDataByName(candidate_name, itemType.NEW_GAME_STARTOFF)
            end)
            if ok_name and by_name ~= nil and type(by_name.stringID) == "string" and #by_name.stringID > 0 then
                return by_name.stringID
            end
        end
        local ok_sid, by_sid = pcall(function()
            return gw.gamedata:getData("1980-gamedata.base")
        end)
        if ok_sid and by_sid ~= nil and type(by_sid.stringID) == "string" and #by_sid.stringID > 0 then
            return by_sid.stringID
        end
    end
    return "1980-gamedata.base"
end

local function start_world_phase_or_finish(executed_menu_suites)
    local need_world = has_enabled_suites(state.game_suites)
        or (state.config and type(state.config.save_name) == "string" and state.config.save_name ~= "")

    if not need_world then
        if not executed_menu_suites then
            finish_run("No matching test suites were registered or enabled for run")
            return
        end
        finish_run(nil)
        return
    end

    local save_name = state.config and state.config.save_name or "kltest_vanilla_1065"
    state.config.save_name = save_name

    set_phase("REQUEST_SAVE", { save_name = save_name })

    local sm = SaveManager.getSingleton()
    if sm == nil then
        finish_run("SaveManager.getSingleton() returned nil during REQUEST_SAVE")
        return
    end

    if not state.world_handler_installed then
        state.world_handler_installed = true
        state.world_handler_id = KenshiLua.registerHandler("GameWorld::charsUpdate", on_chars_update)
    end

    state.world_request_clock = os.clock()
    state.world_post_load_frames = 0
    state.dismissed_char_edit = false
    state.unpaused_world = false

    if save_name:sub(1, 8) == "@newgame" then
        local start_id = resolve_newgame_start_id(save_name)
        append_event({
            type = "new_game_request",
            save_name = save_name,
            start_id = start_id,
        })
        set_phase("WAIT_FOR_WORLD", { save_name = save_name, start_id = start_id })
        local ok_new, new_err = pcall(function()
            sm:newGame(start_id)
        end)
        if not ok_new then
            finish_run("SaveManager:newGame failed: " .. tostring(new_err))
        end
        return
    end

    local save_path = sm:getSavePath()
    local local_path = sm.localSavePath
    local user_path = sm.userSavePath
    local exists_in_active = sm:saveExists(save_path, save_name)
    local exists_in_local = sm:saveExists(local_path, save_name)
    local exists_in_user = sm:saveExists(user_path, save_name)

    append_event({
        type = "save_load_request",
        save_name = save_name,
        save_path = save_path,
        local_save_path = local_path,
        user_save_path = user_path,
        exists_in_active = exists_in_active,
        exists_in_local = exists_in_local,
        exists_in_user = exists_in_user,
    })

    if not exists_in_active and not exists_in_local and not exists_in_user then
        finish_run(string.format(
            "Requested save fixture %q does not exist in active (%s), local (%s), or user (%s) save paths",
            tostring(save_name), tostring(save_path), tostring(local_path), tostring(user_path)
        ))
        return
    end

    set_phase("WAIT_FOR_WORLD", { save_name = save_name })

    local ok_load, load_err = pcall(function()
        if exists_in_active then
            sm:load(save_name)
        elseif exists_in_user then
            sm:loadGame(user_path, save_name)
        else
            sm:loadGame(local_path, save_name)
        end
    end)
    if not ok_load then
        finish_run("SaveManager:load failed: " .. tostring(load_err))
        return
    end
end

local function begin_menu_tests()
    detach_title_only_handlers()
    set_phase("MENU_TESTS")

    if not has_enabled_suites(state.menu_suites) then
        start_world_phase_or_finish(false)
        return
    end

    state.active_scheduler_kind = "MENU_TESTS"
    state.active_scheduler_co = create_suites_scheduler(state.menu_suites, function(executed_any)
        state.active_scheduler_co = nil
        state.active_scheduler_kind = nil
        start_world_phase_or_finish(executed_any)
    end)
    step_active_scheduler()
end

local function perform_save_snapshot(snapshot_name)
    if type(snapshot_name) ~= "string" or snapshot_name == "" then
        return
    end
    append_event({
        type = "save_snapshot_start",
        snapshot_name = snapshot_name,
    })
    local sm = SaveManager.getSingleton()
    local sfs = SaveFileSystem.getSingleton()
    if sm ~= nil then
        local target_loc = sm:getSavePath()
        if type(target_loc) ~= "string" or target_loc == "" then
            target_loc = sm.userSavePath
        end
        local ok_sg, res_sg = pcall(function()
            return sm:saveGame(target_loc, snapshot_name)
        end)
        append_event({
            type = "save_game_direct",
            ok = ok_sg,
            result = res_sg,
            target_loc = target_loc,
            signal_before = sm.signal,
        })
        if not ok_sg or res_sg == 0 then
            sm:save(snapshot_name, false)
        end
        M.wait_frames(5)
        M.wait_until(function()
            local not_busy = (sfs == nil) or (not sfs:busy())
            local exists = sm:saveExists(target_loc, snapshot_name)
                or sm:saveExists(sm.userSavePath, snapshot_name)
                or sm:saveExists(sm.localSavePath, snapshot_name)
            return not_busy and exists
        end, 600, "SaveManager/SaveFileSystem snapshot completion")
        M.wait_frames(3)
    end
    append_event({
        type = "save_snapshot_complete",
        snapshot_name = snapshot_name,
        save_path = sm and sm:getSavePath() or "",
        current_game = sm and sm:getCurrentGame() or "",
        active_save = sfs and sfs:getActiveSave() or "",
    })
end

local function begin_game_tests()
    set_phase("GAME_TESTS", {
        save_name = state.config and state.config.save_name or "",
        world_status = state.last_world_status,
    })

    local snapshot_name = state.config and state.config.save_snapshot_as or nil
    local is_newgame = state.config and type(state.config.save_name) == "string" and state.config.save_name:sub(1, 8) == "@newgame"

    state.active_scheduler_kind = "GAME_TESTS"
    state.active_scheduler_co = coroutine.create(function()
        if is_newgame and snapshot_name then
            perform_save_snapshot(snapshot_name)
        end

        local inner_done = false
        local executed_any = false
        local inner_co = create_suites_scheduler(state.game_suites, function(ran_any)
            inner_done = true
            executed_any = ran_any
        end)
        while coroutine.status(inner_co) ~= "dead" do
            local ok, yielded = coroutine.resume(inner_co)
            if not ok then
                finish_run("Game suite scheduler error: " .. format_co_traceback(inner_co, yielded))
                return
            end
            if coroutine.status(inner_co) == "dead" then
                break
            end
            coroutine.yield(yielded)
        end
        if state.completed then
            return
        end

        if (not is_newgame) and snapshot_name then
            perform_save_snapshot(snapshot_name)
        end

        state.active_scheduler_co = nil
        state.active_scheduler_kind = nil
        if not executed_any and #state.cases == 0 and not snapshot_name then
            finish_run("No matching menu or game test suites were executed")
            return
        end
        finish_run(nil)
    end)
    step_active_scheduler()
end

local function record_title_ready_tick(source)
    if state.completed or state.phase ~= "WAIT_FOR_TITLE" then
        return
    end
    state.title_ticks = state.title_ticks + 1
    if state.title_ticks == 1 then
        append_event({
            type = "title_first_tick",
            source = source,
        })
    end
end

on_title_show = function(_thisptr, on)
    if on and not state.first_title_show_clock then
        state.first_title_show_clock = now_seconds()
        append_event({
            type = "signal",
            signal = "TitleScreen::_NV_show",
            on = true,
        })
    end
end

on_title_update = function(_thisptr)
    if not state.first_title_update_clock then
        state.first_title_update_clock = now_seconds()
        append_event({
            type = "signal",
            signal = "TitleScreen::_NV_update",
        })
    end
    record_title_ready_tick("TitleScreen::_NV_update")
end

on_frame_start = function(_thisptr, _time_delta)
    if state.completed then
        return
    end
    state.frame_index = state.frame_index + 1

    if state.phase == "WAIT_FOR_TITLE" then
        local ok, ts = pcall(TitleScreen.getSingleton)
        if ok and ts ~= nil then
            if not state.first_frame_title_clock then
                state.first_frame_title_clock = now_seconds()
                append_event({
                    type = "signal",
                    signal = "MyGUI::Gui::eventFrameStart+TitleScreen.getSingleton",
                })
            end
            record_title_ready_tick("MyGUI::Gui::eventFrameStart")
            if state.title_ticks >= 2 then
                begin_menu_tests()
            end
        end
    elseif (state.phase == "MENU_TESTS" or state.phase == "GAME_TESTS") and state.active_scheduler_co ~= nil then
        step_active_scheduler()
    elseif state.phase == "WAIT_FOR_WORLD" then
        local gw = getGameWorld()
        local sfs = SaveFileSystem.getSingleton()
        local player = getPlayerInterface()
        if gw ~= nil and gw.initialized == true and gw.gameResetting == false and gw:isLoadingFromASaveGame() == false
            and sfs ~= nil and not sfs:busy() and player ~= nil then
            state.world_post_load_frames = (state.world_post_load_frames or 0) + 1
            if state.world_post_load_frames >= 3 and player:getCharacterEditMode() == true and not state.dismissed_char_edit then
                state.dismissed_char_edit = true
                append_event({
                    type = "character_editor_dismissed",
                    post_load_frames = state.world_post_load_frames,
                })
                pcall(function()
                    player:setCharacterEditMode(false)
                end)
            end
            if state.world_post_load_frames >= 5 and gw:isPaused() == true and not state.unpaused_world then
                state.unpaused_world = true
                append_event({
                    type = "world_unpaused",
                    post_load_frames = state.world_post_load_frames,
                })
                pcall(function()
                    gw:userPause(false)
                    gw:togglePause(false)
                end)
            end
        end

        local world_timeout = (state.config and tonumber(state.config.world_timeout_s)) or 45.0
        if state.world_request_clock and (os.clock() - state.world_request_clock) > world_timeout then
            local _, status = evaluate_world_readiness()
            finish_run(string.format(
                "Timed out after %.2fs waiting for world readiness: %s",
                os.clock() - state.world_request_clock,
                json.encode(status)
            ))
        end
    end
end

on_chars_update = function(_world)
    if state.completed then
        return
    end
    state.world_frame_index = state.world_frame_index + 1
    state.world_total_ticks = state.world_total_ticks + 1

    if not state.first_world_update_clock then
        state.first_world_update_clock = now_seconds()
        append_event({
            type = "signal",
            signal = "GameWorld::charsUpdate",
        })
    end

    if state.phase == "WAIT_FOR_WORLD" then
        local ready, status = evaluate_world_readiness()
        if ready then
            state.world_ready_consecutive = state.world_ready_consecutive + 1
            if state.world_ready_consecutive == 1 then
                append_event({
                    type = "world_first_ready_tick",
                    status = status,
                })
            end
            if state.world_ready_consecutive >= 3 then
                state.world_ready_clock = now_seconds()
                begin_game_tests()
            end
        else
            state.world_ready_consecutive = 0
        end
    elseif state.phase == "GAME_TESTS" and state.active_scheduler_kind == "GAME_TESTS" then
        step_active_scheduler()
    end
end

function M.bootstrap(config)
    state.config = config
    state.boot_clock = os.clock()
    local ver = BinaryVersion.getKenshiVersion()

    set_phase("BOOTSTRAP", {
        kenshilua_version = KenshiLua.version(),
        kenshi_version = ver and ver:toString() or "unknown",
        kenshi_platform = ver and ver:getPlatformStr() or "unknown",
        kenshi_binary = ver and ver:getBinaryName() or "unknown",
        provider_mod = config.provider_mod or "KenshiLua.mod",
        suites = config.suites or {},
        filter = config.filter or "",
        save_name = config.save_name or false,
    })

    set_phase("WAIT_FOR_TITLE")
    state.title_handlers_installed = true
    state.frame_handler_installed = true
    state.title_show_id = KenshiLua.registerHandler("TitleScreen::_NV_show", on_title_show)
    state.title_update_id = KenshiLua.registerHandler("TitleScreen::_NV_update", on_title_update)
    state.frame_handler_id = KenshiLua.registerHandler("MyGUI::Gui::eventFrameStart", on_frame_start)
end

return M
