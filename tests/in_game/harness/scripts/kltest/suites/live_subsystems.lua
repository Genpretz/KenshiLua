local runner = require("kltest.runner")

-- =========================================================================
-- Live Game Subsystem Query Suite (Save-Dependent, Real World Execution)
-- =========================================================================

runner.register_game_suite("live-subsystems", function(ctx)

    -- ---------------------------------------------------------------------
    -- Test 1: GameWorld and Core Subsystem Singletons
    -- ---------------------------------------------------------------------
    ctx.test("GameWorld and core subsystem singletons query safely", function(t)
        local gw = getGameWorld()
        t.assert_not_nil(gw, "getGameWorld()")
        ---@cast gw -nil

        t.assert_equal(gw.initialized, true, "gw.initialized")
        t.assert_equal(gw.paused, false, "gw.paused in running world")
        t.assert_equal(gw.gameResetting, false, "gw.gameResetting")
        t.assert_true(type(gw.tempSpawnsDisableTimer) == "number", "gw.tempSpawnsDisableTimer is number")
        t.assert_true(type(gw.frameSpeedMult) == "number" and gw.frameSpeedMult >= 0, "gw.frameSpeedMult is non-negative")

        -- Subsystems on GameWorld
        t.assert_not_nil(gw.render, "gw.render (Renderer)")
        t.assert_not_nil(gw.physics, "gw.physics (Havok)")
        t.assert_not_nil(gw.gamedata, "gw.gamedata (GameDataManager)")
        t.assert_not_nil(gw.savedata, "gw.savedata (GameDataManager)")
        t.assert_not_nil(gw.theFactory, "gw.theFactory (GameDataFactory)")
        t.assert_not_nil(gw.factionMgr, "gw.factionMgr (FactionManager)")
        t.assert_not_nil(gw.zoneMgr, "gw.zoneMgr (ZoneManager)")
        t.assert_not_nil(gw.player, "gw.player (PlayerInterface)")

        -- FactionManager queries
        local fm = gw.factionMgr
        t.assert_not_nil(fm.participants, "fm.participants container")
        t.assert_true(#fm.participants > 0, "fm.participants has registered factions")

        -- Active mods list
        local active_mods = gw.activeMods
        t.assert_not_nil(active_mods, "gw.activeMods")
        ---@cast active_mods -nil
        t.assert_true(active_mods:size() >= 2, "at least provider and consumer mods active")
    end)

    -- ---------------------------------------------------------------------
    -- Test 2: PlayerInterface, Player Faction, and Camera Class
    -- ---------------------------------------------------------------------
    ctx.test("PlayerInterface, player faction, and CameraClass queries", function(t)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")
        ---@cast player -nil

        -- Player faction
        local faction = player:getFaction() or player.participant
        t.assert_not_nil(faction, "player faction")
        ---@cast faction -nil
        t.assert_true(type(faction.name) == "string" and #faction.name > 0, "player faction name is valid")
        t.assert_not_nil(faction.isPlayer, "faction.isPlayer points to PlayerInterface")
        t.assert_true(faction.isAI == nil or tostring(faction.isAI) == "userdata: NULL", "faction.isAI is NULL for player faction")

        local prosperity = faction:getProsperityMultiplier()
        t.assert_true(type(prosperity) == "number", "faction:getProsperityMultiplier() returns number")

        -- Technology / Research
        local tech = player.technology
        t.assert_not_nil(tech, "player.technology")
        ---@cast tech -nil
        t.assert_true(type(tech:getResearchDeskLevel()) == "number", "tech:getResearchDeskLevel() is number")
        t.assert_true(type(tech.theoreticalTechLevel) == "number", "tech.theoreticalTechLevel is number")

        -- CameraClass
        local cam = player.camera or player:getCamera()
        t.assert_not_nil(cam, "player.camera")
        ---@cast cam -nil
        t.assert_equal(cam.initialised, true, "cam.initialised is true")
        t.assert_true(type(cam.yaw) == "number", "cam.yaw is number")
        t.assert_true(type(cam.pitch) == "number", "cam.pitch is number")
        t.assert_true(type(cam.altitude) == "number", "cam.altitude is number")
        t.assert_true(type(cam.freeCameraMode) == "boolean", "cam.freeCameraMode is boolean")
        t.assert_true(type(cam.timeInGame) == "number", "cam.timeInGame is number")

        local center = cam.center
        t.assert_not_nil(center, "cam.center is Ogre::SceneNode* pointer")
        t.assert_equal(type(center), "userdata", "cam.center is userdata pointer")
    end)

    -- ---------------------------------------------------------------------
    -- Test 3: Live Character Identity, Stats, and Medical Subsystems
    -- ---------------------------------------------------------------------
    ctx.test("Live Character identity, CharStats, and MedicalSystem queries", function(t)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")
        ---@cast player -nil

        local chars = player.playerCharacters
        t.assert_not_nil(chars, "player.playerCharacters")
        ---@cast chars -nil
        t.assert_true(chars:size() >= 1, "at least one character in player squad")

        local char = chars[1] or player:getAnyPlayerCharacter()
        t.assert_not_nil(char, "first player character")
        ---@cast char -nil

        -- Character Identity & State
        local name = char:getName()
        t.assert_true(type(name) == "string" and #name > 0, "char:getName() is non-empty")
        t.assert_equal(char:isPlayerCharacter(), true, "char:isPlayerCharacter()")
        t.assert_equal(char:isDead(), false, "char:isDead() is false in loaded save")
        t.assert_equal(char:isUnconcious(), false, "char:isUnconcious() is false in loaded save")
        t.assert_equal(char:isBeingCarried(), false, "char:isBeingCarried() is false")
        t.assert_true(type(char:isFemale()) == "boolean", "char:isFemale() returns boolean")

        local pos = char:getPosition()
        t.assert_not_nil(pos, "char:getPosition()")
        t.assert_true(type(pos.x) == "number" and type(pos.y) == "number" and type(pos.z) == "number",
            "character position coordinates are numbers")

        -- CharStats
        local stats = char.stats
        t.assert_not_nil(stats, "char.stats")
        ---@cast stats -nil
        t.assert_true(type(stats._strength) == "number" and stats._strength >= 0, "stats._strength")
        t.assert_true(type(stats._dexterity) == "number" and stats._dexterity >= 0, "stats._dexterity")
        t.assert_true(type(stats._toughness) == "number" and stats._toughness >= 0, "stats._toughness")
        t.assert_true(type(stats.perception) == "number" and stats.perception >= 0, "stats.perception")
        t.assert_true(type(stats._athletics) == "number" and stats._athletics >= 0, "stats._athletics")
        t.assert_true(type(stats.moveSpeed) == "number" and stats.moveSpeed >= 0, "stats.moveSpeed")
        t.assert_true(type(stats.attackSpeed) == "number" and stats.attackSpeed >= 0, "stats.attackSpeed")
        t.assert_true(type(stats.blockSpeed) == "number" and stats.blockSpeed >= 0, "stats.blockSpeed")
        t.assert_true(type(stats.encumbranceMult) == "number", "stats.encumbranceMult")

        -- MedicalSystem
        local med = char.medical
        t.assert_not_nil(med, "char.medical")
        ---@cast med -nil
        t.assert_true(type(med.blood) == "number" and med.blood > 0, "med.blood > 0")
        t.assert_true(type(med.currentBleedRate) == "number" and med.currentBleedRate >= 0, "med.currentBleedRate >= 0")
        t.assert_true(type(med.hunger) == "number" and med.hunger >= 0, "med.hunger >= 0")
        t.assert_true(type(med.fed) == "number", "med.fed is number")
        t.assert_equal(med.dead, false, "med.dead is false")
        t.assert_equal(med.unconcious, false, "med.unconcious is false")
        t.assert_true(type(med.crippled) == "boolean", "med.crippled is boolean")
        t.assert_true(type(med.rightArmOk) == "boolean", "med.rightArmOk is boolean")
        t.assert_true(type(med.leftArmOk) == "boolean", "med.leftArmOk is boolean")

        -- CharMovement
        local move = char.movement
        t.assert_not_nil(move, "char.movement")
        ---@cast move -nil
        t.assert_true(type(move.currentSpeed) == "number" and move.currentSpeed >= 0, "move.currentSpeed is non-negative")
        t.assert_true(type(move.walkSpeed) == "number" and move.walkSpeed >= 0, "move.walkSpeed is non-negative")
        t.assert_true(type(move.currentlyMoving) == "boolean", "move.currentlyMoving is boolean")
        t.assert_true(type(move.officiallyStopped) == "boolean", "move.officiallyStopped is boolean")

        -- Inventory
        local inv = char.inventory or char:getInventory()
        t.assert_not_nil(inv, "char.inventory")
        local bp = char:hasABackpackOn()
        t.assert_true(bp == nil or type(bp) == "userdata", "char:hasABackpackOn() returns ContainerItem or nil")
        t.assert_true(type(char:isInventoryVisible()) == "boolean", "char:isInventoryVisible() is boolean")
    end)

    -- ---------------------------------------------------------------------
    -- Test 4: Live Platoon, Squad Orders, and Member Traversal
    -- ---------------------------------------------------------------------
    ctx.test("Live Platoon member list traversal and squad state", function(t)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")
        ---@cast player -nil

        local chars = player.playerCharacters
        t.assert_true(chars:size() >= 1, "at least one character")
        local char = chars[1]

        local activePlat = char:getPlatoon() or player.currentPlatoon
        t.assert_not_nil(activePlat, "char:getPlatoon() returns ActivePlatoon")
        ---@cast activePlat -nil

        t.assert_not_nil(activePlat.isPlayer, "activePlat.isPlayer points to PlayerInterface")
        t.assert_true(type(activePlat.isAnimalsOnly) == "boolean", "activePlat.isAnimalsOnly is boolean")

        local handles = activePlat.characterHandles
        t.assert_not_nil(handles, "activePlat.characterHandles is HandleList pointer")
        t.assert_equal(type(handles), "userdata", "activePlat.characterHandles is lightuserdata")

        local leader = activePlat.squadleader
        t.assert_not_nil(leader, "activePlat.squadleader")

        local platoon = activePlat.me
        t.assert_not_nil(platoon, "activePlat.me is parent Platoon")
        ---@cast platoon -nil

        t.assert_not_nil(platoon.activePlatoon, "platoon.activePlatoon points to ActivePlatoon")
        t.assert_true(type(platoon.stringID) == "string", "platoon.stringID is string")
        t.assert_true(type(platoon:getCharacterCount()) == "number" and platoon:getCharacterCount() >= 1,
            "platoon:getCharacterCount() >= 1")
        t.assert_true(type(platoon:isPersistentSquad()) == "boolean", "platoon:isPersistentSquad() is boolean")
        t.assert_true(type(platoon:isIntact()) == "boolean", "platoon:isIntact() is boolean")
    end)

    -- ---------------------------------------------------------------------
    -- Test 5: ZoneManager and Weather Live Environment Queries
    -- ---------------------------------------------------------------------
    ctx.test("ZoneManager and WeatherSystem live environment queries", function(t)
        local gw = getGameWorld()
        t.assert_not_nil(gw, "getGameWorld()")
        ---@cast gw -nil

        local zm = gw.zoneMgr
        t.assert_not_nil(zm, "gw.zoneMgr")
        ---@cast zm -nil

        t.assert_true(type(zm.loadingPhase) == "number", "zm.loadingPhase is number")

        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")
        local chars = player.playerCharacters
        t.assert_true(#chars >= 1, "at least one character")
        local pos = chars[1]:getPosition()
        t.assert_not_nil(pos, "character position")

        -- Test ZoneManager ground sound query with real world position
        local sound_short = zm:getGroundSound(pos, SoundRange.SOUNDRANGE_SHORT)
        t.assert_true(type(sound_short) == "string", "zm:getGroundSound short range returns string")

        local sound_long = zm:getGroundSound(pos, SoundRange.SOUNDRANGE_LONG)
        t.assert_true(type(sound_long) == "string", "zm:getGroundSound long range returns string")

        -- WeatherSystem singleton queries
        local ws = WeatherSystem.getInstance()
        t.assert_not_nil(ws, "WeatherSystem.getInstance()")
        ---@cast ws -nil

        t.assert_true(type(ws.currentWindValue) == "number", "ws.currentWindValue is number")
        t.assert_true(type(ws.currentRainValue) == "number", "ws.currentRainValue is number")
        t.assert_true(type(ws.globalWetness) == "number", "ws.globalWetness is number")

        local dust = ws.currentDustAmount
        t.assert_not_nil(dust, "ws.currentDustAmount is Vector3")
        t.assert_true(type(dust.x) == "number" and type(dust.y) == "number" and type(dust.z) == "number",
            "ws.currentDustAmount coordinates are numbers")
    end)

    -- ---------------------------------------------------------------------
    -- Test 6: TownList and Global World Settlements
    -- ---------------------------------------------------------------------
    ctx.test("TownList settlements and global world settlements query safely", function(t)
        local shou = getSharedKing()
        t.assert_not_nil(shou, "getSharedKing()")
        ---@cast shou -nil

        local townList = shou.townList
        t.assert_not_nil(townList, "shou.townList")
        ---@cast townList -nil

        local allTowns = townList:getAllTowns()
        t.assert_not_nil(allTowns, "townList:getAllTowns()")
        ---@cast allTowns -nil
        t.assert_true(#allTowns > 0, "at least one town in live world")

        local town = allTowns[1]
        t.assert_not_nil(town, "allTowns[1]")
        ---@cast town -nil

        local townName = town:getName()
        t.assert_true(type(townName) == "string", "town:getName() is string")

        local townPos = town:getPosition()
        t.assert_not_nil(townPos, "town:getPosition()")
        t.assert_true(type(townPos.x) == "number" and type(townPos.y) == "number" and type(townPos.z) == "number",
            "town position coordinates are numbers")

        local nullTown = townList:getNullTown()
        t.assert_not_nil(nullTown, "townList:getNullTown()")

        KenshiLua.log(string.format(
            "[KLTest][live-subsystems] first_town=%q pos=(%.1f, %.1f, %.1f) total_towns=%d",
            tostring(townName), townPos.x, townPos.y, townPos.z, #allTowns
        ))
    end)

end)

