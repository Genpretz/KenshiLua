local runner = require("kltest.runner")

local DIALOGUE_SCRIPT_PATH = "./mods/KenshiLua Tests/scripts/kltest/fixtures/dialogue_bridge_probe.lua"
local WORLD_STATE_SCRIPT_PATH = "./mods/KenshiLua Tests/scripts/kltest/fixtures/world_state_bridge_probe.lua"
local ID_SUFFIX = "-KenshiLua Tests.mod"

local function create_data(manager, item_type, string_id, name)
    local existing = manager:getData(string_id)
    if existing ~= nil then
        return existing
    end
    return manager:createNewData(item_type, string_id, name)
end

local function create_dialogue_fixture(suffix)
    local world = getGameWorld()
    assert(world ~= nil, "getGameWorld() returned nil")

    local manager = world.gamedata
    assert(manager ~= nil, "GameWorld.gamedata returned nil")

    local script_id = "#KLTEST-" .. suffix .. "-SCRIPT" .. ID_SUFFIX
    local line_id = "#KLTEST-" .. suffix .. "-LINE" .. ID_SUFFIX

    local script_data = create_data(manager, itemType.LUA_SCRIPT, script_id,
        "KLTest " .. suffix .. " Lua script")
    assert(script_data ~= nil, "could not create LUA_SCRIPT GameData")
    script_data:addFileName("file", DIALOGUE_SCRIPT_PATH, "Lua script|*.lua", "", true)

    local line_data = create_data(manager, itemType.DIALOGUE_LINE, line_id,
        "KLTest " .. suffix .. " dialogue line")
    assert(line_data ~= nil, "could not create DIALOGUE_LINE GameData")
    if not line_data:findInList("run lua script", script_id) then
        line_data:addToList("run lua script", script_id, 0, 0, 0)
    end

    local registry = debug.getregistry()
    local dialog_data_manager = registry["KenshiLua.DialogDataManager"]
    assert(type(dialog_data_manager) == "table", "DialogDataManager metatable not registered")
    assert(type(dialog_data_manager._createData) == "function",
        "DialogDataManager._createData not registered")

    local line = dialog_data_manager._createData(line_data)
    assert(line ~= nil, "DialogDataManager._createData returned nil")

    local player = getPlayerInterface()
    assert(player ~= nil, "getPlayerInterface() returned nil")
    local characters = player.playerCharacters
    assert(characters ~= nil and characters:size() > 0, "no player character available")

    local character = characters[1] or player:getAnyPlayerCharacter()
    assert(character ~= nil, "could not get a player character")
    local dialogue = character.dialogue
    assert(dialogue ~= nil, "player character has no Dialogue object")

    return dialogue, line, line_id
end

local function create_world_state_fixture()
    local world = getGameWorld()
    assert(world ~= nil, "getGameWorld() returned nil")

    local manager = world.gamedata
    assert(manager ~= nil, "GameWorld.gamedata returned nil")

    local script_id = "#KLTEST-WORLD-STATE-SCRIPT" .. ID_SUFFIX
    local state_id = "#KLTEST-WORLD-STATE" .. ID_SUFFIX

    local script_data = create_data(manager, itemType.LUA_SCRIPT, script_id,
        "KLTest world-state Lua script")
    assert(script_data ~= nil, "could not create world-state LUA_SCRIPT GameData")
    script_data:addFileName("file", WORLD_STATE_SCRIPT_PATH, "Lua script|*.lua", "", true)

    local state_data = create_data(manager, itemType.WORLD_EVENT_STATE, state_id,
        "KLTest true world state")
    assert(state_data ~= nil, "could not create WORLD_EVENT_STATE GameData")
    if not state_data:findInList("run lua script", script_id) then
        state_data:addToList("run lua script", script_id, 1, 0, 0)
    end

    local query = WorldEventStateQuery.getFromData(state_data)
    assert(query ~= nil, "WorldEventStateQuery.getFromData returned nil")
    assert(query:isTrue(), "empty KLTest WORLD_EVENT_STATE was not true")

    _G.KLTestWorldStateBridgeProbe = {
        expected_state_id = state_id,
        runs = 0,
    }
end

local function clear_probe_handlers()
    local probe = _G.KLTestDialogueBridgeProbe
    if type(probe) == "table" and type(probe.handler_ids) == "table" then
        for i = 1, #probe.handler_ids do
            Events.off(probe.handler_ids[i])
        end
    end
    _G.KLTestDialogueBridgeProbe = nil
end

local function clear_probe_widgets()
    local probe = _G.KLTestDialogueBridgeProbe
    if type(probe) == "table" and type(probe.widget_names) == "table" then
        for i = 1, #probe.widget_names do
            local widget = MyGUI.findWidget(probe.widget_names[i])
            if widget ~= nil then
                MyGUI.destroyWidget(widget)
            end
        end
    end
end

runner.register_menu_suite("script-bridges", function(ctx)
    ctx.test("world-state script fixture is prepared before loading", function(t)
        create_world_state_fixture()
        t.assert_not_nil(_G.KLTestWorldStateBridgeProbe, "world-state probe")
    end)
end, { default_enable = true })

runner.register_game_suite("script-bridges", function(ctx)
    ctx.after_each(function()
        clear_probe_widgets()
        clear_probe_handlers()
        _G.currentDialogue = nil
        _G.currentDialogueLine = nil
    end)

    ctx.test("true world state runs its mode-1 script after loading", function(t)
        t.wait_until(function()
            local probe = _G.KLTestWorldStateBridgeProbe
            return type(probe) == "table" and probe.runs >= 1
        end, 120, "world-state mode-1 script execution")

        local probe = _G.KLTestWorldStateBridgeProbe
        t.assert_equal(probe.runs, 1, "world-state script execution count")
        t.assert_equal(probe.saw_state, true, "currentWorldEventState was available")
        t.assert_equal(probe.saw_query, true, "currentWorldEventStateQuery was available")
        t.assert_equal(probe.state_id, probe.expected_state_id,
            "currentWorldEventState string ID")
        t.assert_equal(probe.query_value, true, "currentWorldEventStateQuery:isTrue()")
        t.assert_nil(_G.currentWorldEventState, "currentWorldEventState after script")
        t.assert_nil(_G.currentWorldEventStateQuery, "currentWorldEventStateQuery after script")
    end)

    ctx.test("dialogue script receives its dialogue and line context", function(t)
        local dialogue, line, line_id = create_dialogue_fixture("BASIC")
        _G.KLTestDialogueBridgeProbe = { mode = "basic" }

        dialogue:_doActions(line)

        local probe = _G.KLTestDialogueBridgeProbe
        t.assert_equal(probe.runs, 1, "script execution count")
        t.assert_equal(probe.saw_dialogue, true, "currentDialogue was available")
        t.assert_equal(probe.saw_line, true, "currentDialogueLine was available")
        t.assert_equal(probe.line_id, line_id, "currentDialogueLine string ID")
        t.assert_nil(_G.currentDialogue, "currentDialogue after script")
        t.assert_nil(_G.currentDialogueLine, "currentDialogueLine after script")
    end)

    ctx.test("nested dialogue script restores the outer dialogue context", function(t)
        local dialogue, line = create_dialogue_fixture("NESTED")
        _G.KLTestDialogueBridgeProbe = { mode = "nested" }

        dialogue:_doActions(line)

        local probe = _G.KLTestDialogueBridgeProbe
        t.assert_equal(probe.runs, 2, "outer and nested script execution count")
        t.assert_equal(probe.context_restored, true,
            "outer currentDialogue and currentDialogueLine after nested execution")
    end)

    ctx.test("repeated dialogue script executions replace prior registered handlers", function(t)
        local dialogue, line = create_dialogue_fixture("HANDLERS")
        _G.KLTestDialogueBridgeProbe = { mode = "handlers" }

        dialogue:_doActions(line)
        dialogue:_doActions(line)

        local probe = _G.KLTestDialogueBridgeProbe
        t.assert_equal(probe.runs, 2, "script execution count")
        t.assert_equal(#probe.handler_ids, 2, "registered handler count")
        t.assert_equal(probe.handler_ticks[1], 1, "first handler was removed before the second run")
        t.assert_equal(probe.handler_ticks[2], 1, "second handler became active")
    end)

    ctx.test("repeated dialogue script executions replace prior created widgets", function(t)
        local dialogue, line = create_dialogue_fixture("WIDGETS")
        _G.KLTestDialogueBridgeProbe = { mode = "widgets" }

        dialogue:_doActions(line)
        dialogue:_doActions(line)

        local probe = _G.KLTestDialogueBridgeProbe
        t.assert_equal(probe.runs, 2, "script execution count")
        t.assert_equal(#probe.widget_names, 2, "created widget count")
        t.assert_nil(MyGUI.findWidget(probe.widget_names[1]),
            "first widget after the second run")
        t.assert_not_nil(MyGUI.findWidget(probe.widget_names[2]),
            "second widget after the second run")
    end)

    ctx.test("diagnostics do not label a non-LUA_SCRIPT target as a Lua script", function(t)
        local world = getGameWorld()
        t.assert_not_nil(world, "getGameWorld()")
        local manager = world.gamedata

        local target_id = "#KLTEST-DIAGNOSTIC-TARGET" .. ID_SUFFIX
        local owner_id = "#KLTEST-DIAGNOSTIC-OWNER" .. ID_SUFFIX
        local fake_path = "./mods/KenshiLua Tests/scripts/kltest/fixtures/not-a-lua-script.lua"

        local target = create_data(manager, itemType.DIALOGUE_LINE, target_id,
            "KLTest non-LUA_SCRIPT target")
        target:addFileName("file", fake_path, "Lua script|*.lua", "", true)

        local owner = create_data(manager, itemType.DIALOGUE_LINE, owner_id,
            "KLTest diagnostic owner")
        if not owner:findInList("run lua script", target_id) then
            owner:addToList("run lua script", target_id, 0, 0, 0)
        end

        local report = KenshiLua.checkLuaScriptReferences()
        t.assert_match(report, owner_id, "diagnostic fixture was scanned")
        t.assert_match(report, "reference target is not a LUA_SCRIPT",
            "diagnostic explains the invalid item type")
        t.assert_true(report:find(fake_path, 1, true) == nil,
            "diagnostic must not report a non-LUA_SCRIPT target as a Lua script")
    end)
end, { default_enable = true })
