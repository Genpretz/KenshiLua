local runner = require("kltest.runner")

-- =========================================================================
-- Menu Phase Tests (Stand-alone, Zero-World Dependent)
-- =========================================================================

runner.register_menu_suite("binding-smoke", function(ctx)
    ctx.test("lektor.new string container push, pop, index, toTable, and iteration", function(t)
        local lek = lektor.new("string")
        t.assert_not_nil(lek, "lektor.new('string')")
        t.assert_equal(#lek, 0, "initial #lek")
        t.assert_equal(lek:size(), 0, "initial lek:size()")

        lek:push("alpha")
        lek:push("beta")
        lek:push("gamma")

        t.assert_equal(#lek, 3, "size after 3 pushes")
        t.assert_equal(lek[1], "alpha", "1-based index [1]")
        t.assert_equal(lek[2], "beta", "1-based index [2]")
        t.assert_equal(lek[3], "gamma", "1-based index [3]")

        -- Test 1-based index assignment
        lek[2] = "bravo"
        t.assert_equal(lek[2], "bravo", "assigned index [2]")

        -- Test pop
        local popped = lek:pop()
        t.assert_equal(popped, "gamma", "popped value")
        t.assert_equal(#lek, 2, "size after pop")

        -- Test toTable
        local tbl = lek:toTable()
        t.assert_equal(#tbl, 2, "toTable length")
        t.assert_equal(tbl[1], "alpha", "tbl[1]")
        t.assert_equal(tbl[2], "bravo", "tbl[2]")

        -- Test ipairs iteration
        local collected = {}
        for idx, val in ipairs(lek) do
            collected[idx] = val
        end
        t.assert_equal(#collected, 2, "ipairs collected count")
        t.assert_equal(collected[1], "alpha", "ipairs collected [1]")
        t.assert_equal(collected[2], "bravo", "ipairs collected [2]")

        -- Test removeAt
        lek:removeAt(1)
        t.assert_equal(#lek, 1, "size after removeAt(1)")
        t.assert_equal(lek[1], "bravo", "element after removeAt(1)")

        -- Test clear
        lek:clear()
        t.assert_equal(#lek, 0, "size after clear()")
        t.assert_nil(lek[1], "lek[1] after clear is nil")
    end)

    ctx.test("lektor.new int container numeric operations and boundaries", function(t)
        local lek = lektor.new("int")
        t.assert_not_nil(lek, "lektor.new('int')")
        t.assert_equal(#lek, 0, "initial int lektor size")

        lek:push(10)
        lek:push(20)
        lek:push(30)
        t.assert_equal(#lek, 3, "size after 3 pushes")
        t.assert_equal(lek[1], 10, "int [1]")
        t.assert_equal(lek[2], 20, "int [2]")
        t.assert_equal(lek[3], 30, "int [3]")

        -- Read out of range returns nil
        t.assert_nil(lek[0], "index 0 returns nil")
        t.assert_nil(lek[4], "index 4 returns nil")
        t.assert_nil(lek[-1], "index -1 returns nil")

        -- Assigning to count + 1 appends
        lek[4] = 40
        t.assert_equal(#lek, 4, "size after appending at count+1")
        t.assert_equal(lek[4], 40, "appended element at [4]")

        -- Assigning out of range raises error
        local ok_assign = pcall(function()
            lek[10] = 999
        end)
        t.assert_equal(ok_assign, false, "assigning out of bounds (10) must error")

        -- removeAt out of range raises error
        local ok_rem = pcall(function()
            lek:removeAt(10)
        end)
        t.assert_equal(ok_rem, false, "removeAt out of bounds (10) must error")

        -- popping until empty
        lek:clear()
        local ok_pop = pcall(function()
            lek:pop()
        end)
        t.assert_equal(ok_pop, false, "pop on empty lektor must error")
    end)

    ctx.test("registered enums have integer representation and expected constant values", function(t)
        t.assert_not_nil(itemType, "itemType global enum table")
        t.assert_true(type(itemType.NEW_GAME_STARTOFF) == "number", "itemType.NEW_GAME_STARTOFF is number")
        t.assert_equal(itemType.NEW_GAME_STARTOFF, 64, "itemType.NEW_GAME_STARTOFF == 0x40 (64)")
        t.assert_true(type(itemType.WEAPON) == "number", "itemType.WEAPON is number")
        t.assert_true(type(itemType.ARMOUR) == "number", "itemType.ARMOUR is number")
        t.assert_true(type(itemType.BUILDING) == "number", "itemType.BUILDING is number")

        t.assert_not_nil(BuildingFunction, "BuildingFunction global enum table")
        t.assert_true(type(BuildingFunction.BF_RESEARCH) == "number", "BuildingFunction.BF_RESEARCH is number")
        t.assert_true(type(BuildingFunction.BF_BED) == "number", "BuildingFunction.BF_BED is number")

        t.assert_not_nil(CutDirection, "CutDirection global enum table")
        t.assert_true(type(CutDirection.CUT_DEFAULT) == "number", "CutDirection.CUT_DEFAULT is number")
        t.assert_true(type(CutDirection.CUT_DOWNWARD) == "number", "CutDirection.CUT_DOWNWARD is number")

        t.assert_not_nil(TownType, "TownType global enum table")
    end)

    ctx.test("dynamic event callback registration, unregistration, and ID ordering", function(t)
        local calls_a = 0
        local calls_b = 0
        local function fn_a() calls_a = calls_a + 1 end
        local function fn_b() calls_b = calls_b + 1 end

        local id_a = KenshiLua.registerHandler("MyGUI::Gui::eventFrameStart", fn_a)
        local id_b = KenshiLua.registerHandler("MyGUI::Gui::eventFrameStart", fn_b)

        t.assert_true(type(id_a) == "number" and id_a > 0, "id_a is positive integer")
        t.assert_true(type(id_b) == "number" and id_b > id_a, "id_b is greater than id_a")

        -- Wait 3 frames to let both handlers fire
        t.wait_frames(3)
        t.assert_true(calls_a >= 2, "handler A fired while registered")
        t.assert_true(calls_b >= 2, "handler B fired while registered")

        -- Unregister handler A and yield 1 frame past current dispatch iteration
        KenshiLua.unregisterHandler(id_a)
        t.wait_frames(1)
        local a_after_unreg = calls_a

        t.wait_frames(3)
        t.assert_equal(calls_a, a_after_unreg, "handler A stopped firing after unregisterHandler")
        t.assert_true(calls_b > a_after_unreg, "handler B continued firing")

        -- Unregister handler B and yield 1 frame
        KenshiLua.unregisterHandler(id_b)
        t.wait_frames(1)
        local b_after_unreg = calls_b

        t.wait_frames(2)
        t.assert_equal(calls_b, b_after_unreg, "handler B stopped firing after unregisterHandler")
    end)
end)

-- =========================================================================
-- Game Phase Tests (Loaded Save World State)
-- =========================================================================

runner.register_game_suite("binding-smoke", function(ctx)
    ctx.test("borrowed engine lektors preserve container identity and safe GC", function(t)
        local gw = getGameWorld()
        t.assert_not_nil(gw, "getGameWorld()")

        local mods = gw.activeMods
        t.assert_not_nil(mods, "gw.activeMods")
        t.assert_true(#mods >= 2, "activeMods has at least 2 mods")
        t.assert_equal(#mods, mods:size(), "#mods matches mods:size()")

        local first_mod = mods[1]
        t.assert_not_nil(first_mod, "first_mod is non-nil")
        t.assert_true(type(first_mod.name) == "string" and #first_mod.name > 0, "first_mod.name is non-empty")

        -- Convert to table
        local mod_table = mods:toTable()
        t.assert_equal(#mod_table, #mods, "mod_table size matches #mods")
        t.assert_equal(mod_table[1].name, first_mod.name, "mod_table[1].name matches first_mod.name")

        -- Trigger Lua GC pass; borrowed engine container must not be collected or destroyed
        collectgarbage("collect")
        t.assert_equal(#mods, #mod_table, "activeMods intact after full collectgarbage()")
    end)

    ctx.test("Vector3 coordinate table marshaling and character position reading", function(t)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")

        local chars = player.playerCharacters
        t.assert_not_nil(chars, "player.playerCharacters")
        t.assert_true(#chars >= 1, "at least one player character")

        local char = chars[1]
        t.assert_not_nil(char, "first player character")

        local pos0 = char:getPosition()
        t.assert_not_nil(pos0, "char:getPosition()")
        t.assert_true(type(pos0.x) == "number", "pos0.x is number")
        t.assert_true(type(pos0.y) == "number", "pos0.y is number")
        t.assert_true(type(pos0.z) == "number", "pos0.z is number")

        local raw_pos = char:getRawEntityPosition()
        t.assert_not_nil(raw_pos, "char:getRawEntityPosition()")
        t.assert_true(type(raw_pos.x) == "number", "raw_pos.x is number")

        -- Test read and write of Vector3 property (ragdollNavmeshPosition)
        local ragdoll_pos = char.ragdollNavmeshPosition
        t.assert_not_nil(ragdoll_pos, "char.ragdollNavmeshPosition")
        t.assert_true(type(ragdoll_pos.x) == "number", "ragdoll_pos.x is number")

        local test_ragdoll = { x = ragdoll_pos.x + 1.0, y = ragdoll_pos.y + 0.5, z = ragdoll_pos.z + 1.0 }
        char.ragdollNavmeshPosition = test_ragdoll
        local updated_ragdoll = char.ragdollNavmeshPosition
        t.assert_near(updated_ragdoll.x, test_ragdoll.x, 0.01, "updated ragdollNavmeshPosition.x")
        t.assert_near(updated_ragdoll.y, test_ragdoll.y, 0.01, "updated ragdollNavmeshPosition.y")
        t.assert_near(updated_ragdoll.z, test_ragdoll.z, 0.01, "updated ragdollNavmeshPosition.z")

        -- Restore ragdollNavmeshPosition
        char.ragdollNavmeshPosition = ragdoll_pos

        -- Test Vector3 marshaling in method call (lookatPosition)
        local look_target = { x = pos0.x + 10.0, y = pos0.y, z = pos0.z + 10.0 }
        local ok_look = pcall(function()
            char:lookatPosition(look_target, false)
        end)
        t.assert_equal(ok_look, true, "char:lookatPosition with table Vector3 succeeded")
    end)

    ctx.test("hand entity handle operators and strict 1:1 SDK method fidelity", function(t)
        local player = getPlayerInterface()
        local chars = player.playerCharacters
        local char = chars[1]

        local h = char.handle
        t.assert_not_nil(h, "char.handle")

        -- hand:operator_bool() exists and returns true for valid character handle
        t.assert_true(type(h.operator_bool) == "function", "h:operator_bool is function")
        t.assert_true(h:operator_bool(), "h:operator_bool() returns true")

        -- hand:isValid() exists because hand explicitly declares bool isValid() const in C++
        t.assert_true(type(h.isValid) == "function", "h:isValid is function")
        t.assert_true(h:isValid(), "h:isValid() returns true")

        -- hand:isNull() returns false
        t.assert_equal(h:isNull(), false, "h:isNull() is false")

        -- hand fields match character identity
        t.assert_true(type(h.serial) == "number" and h.serial > 0, "h.serial is positive")
        t.assert_true(type(h.index) == "number", "h.index is number")
        t.assert_true(type(h.container) == "number", "h.container is number")
        t.assert_equal(h.type, itemType.CHARACTER, "h.type == itemType.CHARACTER")

        -- String conversion
        local str = h:toString()
        t.assert_true(type(str) == "string" and #str > 0, "h:toString() returns non-empty string")

        -- Entity resolution
        local resolved = h:getCharacter()
        t.assert_not_nil(resolved, "h:getCharacter()")
        t.assert_equal(resolved:getName(), char:getName(), "resolved character matches name")

        -- Strict 1:1 rule check:
        -- Character class inherits isValid() from RootObjectBase
        t.assert_true(type(char.isValid) == "function", "char:isValid is function (inherited from RootObjectBase)")
        t.assert_true(char:isValid(), "char:isValid() returns true")
        -- Neither Character nor RootObjectBase declares operator_bool in C++
        t.assert_nil(char.operator_bool, "char.operator_bool must be nil (1:1 SDK rule)")
    end)

    ctx.test("GameData query by enum and record string ID verification", function(t)
        local gw = getGameWorld()
        t.assert_not_nil(gw.gamedata, "gw.gamedata")

        local start_obj = gw.gamedata:getDataByName("Wanderer", itemType.NEW_GAME_STARTOFF)
        t.assert_not_nil(start_obj, "gw.gamedata:getDataByName('Wanderer', NEW_GAME_STARTOFF)")
        t.assert_equal(start_obj.name, "Wanderer", "record name matches")
        t.assert_equal(start_obj.stringID, "1980-gamedata.base", "record stringID matches 1980-gamedata.base")
        t.assert_equal(start_obj.type, itemType.NEW_GAME_STARTOFF, "record type matches enum")
    end)
end)

