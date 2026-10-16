local runner = require("kltest.runner")

runner.register_game_suite("world-smoke", function(ctx)
    ctx.test("GameWorld and SaveManager readiness conjunction holds in loaded world", function(t)
        local gw = getGameWorld()
        local sm = SaveManager.getSingleton()
        local sfs = SaveFileSystem.getSingleton()

        t.assert_not_nil(gw, "getGameWorld()")
        t.assert_equal(gw.initialized, true, "gw.initialized")
        t.assert_equal(gw.gameResetting, false, "gw.gameResetting")
        t.assert_equal(gw:isLoadingFromASaveGame(), false, "gw:isLoadingFromASaveGame()")

        t.assert_not_nil(sm, "SaveManager.getSingleton()")
        t.assert_not_nil(sfs, "SaveFileSystem.getSingleton()")
        t.assert_equal(sfs:busy(), false, "SaveFileSystem:busy()")

        local current_game = sm:getCurrentGame()
        local active_save = sfs:getActiveSave()
        t.assert_true((type(current_game) == "string" and #current_game > 0) or (type(active_save) == "string" and #active_save > 0),
            "SaveManager currentGame or SaveFileSystem activeSave is populated")
    end)

    ctx.test("GameWorld core subsystems and active mods are accessible", function(t)
        local gw = getGameWorld()
        t.assert_not_nil(gw.gamedata, "gw.gamedata")
        t.assert_not_nil(gw.savedata, "gw.savedata")
        t.assert_not_nil(gw.theFactory, "gw.theFactory")
        t.assert_not_nil(gw.factionMgr, "gw.factionMgr")
        t.assert_not_nil(gw.zoneMgr, "gw.zoneMgr")

        local active_mods = gw.activeMods
        t.assert_not_nil(active_mods, "gw.activeMods")
        t.assert_true(active_mods:size() >= 2, "at least provider and consumer mods active")
    end)

    ctx.test("PlayerInterface, player faction, and player characters are populated", function(t)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")

        local faction = player:getFaction() or player.participant
        t.assert_not_nil(faction, "player faction")
        t.assert_true(type(faction.name) == "string" and #faction.name > 0, "player faction name")

        local chars = player.playerCharacters
        t.assert_not_nil(chars, "player.playerCharacters")
        t.assert_true(chars:size() >= 1, "at least one player character in save fixture")

        local first_char = chars[1] or player:getAnyPlayerCharacter()
        t.assert_not_nil(first_char, "first player character")
        local char_name = first_char:getName()
        t.assert_true(type(char_name) == "string" and #char_name > 0, "character name is non-empty")

        local pos = first_char:getPosition()
        t.assert_not_nil(pos, "character position")
        t.assert_true(type(pos.x) == "number" and type(pos.y) == "number" and type(pos.z) == "number", "position coordinates")
        KenshiLua.log(string.format(
            "[KLTest][world-smoke] faction=%q chars=%d first_char=%q pos=(%.1f, %.1f, %.1f)",
            tostring(faction.name), chars:size(), tostring(char_name), pos.x, pos.y, pos.z
        ))
    end)

    ctx.test("multi-frame GameWorld::charsUpdate ticks and handler lifecycle", function(t)
        local w0 = t.world_frame_index()
        local hook_ticks = 0
        local function on_world_tick(world)
            if world ~= nil then
                hook_ticks = hook_ticks + 1
            end
        end

        local hook_id = KenshiLua.registerHandler("GameWorld::charsUpdate", on_world_tick)
        t.wait_until(function()
            return hook_ticks >= 3
        end, 120, "GameWorld::charsUpdate ticks >= 3")
        KenshiLua.unregisterHandler(hook_id)

        local w1 = t.world_frame_index()
        local after_unreg_ticks = hook_ticks
        t.wait_frames(5)

        t.assert_true(w1 > w0, "world_frame_index advanced while handler was registered")
        t.assert_true(after_unreg_ticks >= 3, "GameWorld::charsUpdate handler fired while registered")
        t.assert_equal(hook_ticks, after_unreg_ticks, "GameWorld::charsUpdate handler stopped firing after unregisterHandler")
    end)
end)

