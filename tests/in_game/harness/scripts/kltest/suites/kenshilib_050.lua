local runner = require("kltest.runner")

-- =========================================================================
-- Menu Phase Tests (Stand-alone, Zero-World Dependent)
-- =========================================================================

runner.register_menu_suite("kenshilib-050", function(ctx)
    ctx.test("kenshilib-050: enum bindings and constant values", function(t)
        -- RagdollPart::Enum
        t.assert_not_nil(RagdollPart, "RagdollPart global table")
        t.assert_not_nil(RagdollPart.Enum, "RagdollPart.Enum table")
        t.assert_equal(RagdollPart.Enum.NONE, 0, "RagdollPart.Enum.NONE")
        t.assert_equal(RagdollPart.Enum.WHOLE, 1, "RagdollPart.Enum.WHOLE")
        t.assert_equal(RagdollPart.Enum.RIGHT_ARM, 2, "RagdollPart.Enum.RIGHT_ARM")
        t.assert_equal(RagdollPart.Enum.LEFT_ARM, 4, "RagdollPart.Enum.LEFT_ARM")
        t.assert_equal(RagdollPart.Enum.HEAD, 8, "RagdollPart.Enum.HEAD")
        t.assert_equal(RagdollPart.Enum.RIGHT_LEG, 16, "RagdollPart.Enum.RIGHT_LEG")
        t.assert_equal(RagdollPart.Enum.LEFT_LEG, 32, "RagdollPart.Enum.LEFT_LEG")
        t.assert_equal(RagdollPart.Enum.CARRY_MODE, 0x800, "RagdollPart.Enum.CARRY_MODE")
        t.assert_equal(RagdollPart.Enum.ARMS, 6, "RagdollPart.Enum.ARMS")
        t.assert_equal(RagdollPart.Enum.LEGS, 0x30, "RagdollPart.Enum.LEGS")

        -- StateType
        t.assert_not_nil(StateType, "StateType global table")
        t.assert_equal(StateType.NONE_RESULT, 0, "StateType.NONE_RESULT")
        t.assert_equal(StateType.AT_LOCATION, 1, "StateType.AT_LOCATION")
        t.assert_equal(StateType.BUILDING_COMPLETE, 2, "StateType.BUILDING_COMPLETE")
        t.assert_true(type(StateType.DESTINATION_IS_ACCESSIBLE_ANIMAL) == "number", "StateType.DESTINATION_IS_ACCESSIBLE_ANIMAL")
        t.assert_true(type(StateType.MACHINE_HAS_INVALID_INPUTS) == "number", "StateType.MACHINE_HAS_INVALID_INPUTS")

        -- SquadMemberType
        t.assert_not_nil(SquadMemberType, "SquadMemberType global table")
        t.assert_equal(SquadMemberType.SQUAD_1, 0, "SquadMemberType.SQUAD_1")
        t.assert_equal(SquadMemberType.SQUAD_2, 1, "SquadMemberType.SQUAD_2")
        t.assert_equal(SquadMemberType.SQUAD_LEADER, 2, "SquadMemberType.SQUAD_LEADER")
        t.assert_equal(SquadMemberType.SQUAD_SIGNALS_PLAN, 3, "SquadMemberType.SQUAD_SIGNALS_PLAN")
        t.assert_equal(SquadMemberType.SQUAD_SLAVE, 4, "SquadMemberType.SQUAD_SLAVE")

        -- UnloadedPlatoonJob
        t.assert_not_nil(UnloadedPlatoonJob, "UnloadedPlatoonJob global table")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_NONE, 0, "UnloadedPlatoonJob.UPJOB_NONE")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_PATROL_TOWN, 1, "UnloadedPlatoonJob.UPJOB_PATROL_TOWN")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_PATROL_SHORTRANGE, 2, "UnloadedPlatoonJob.UPJOB_PATROL_SHORTRANGE")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_PATROL_LONGRANGE, 3, "UnloadedPlatoonJob.UPJOB_PATROL_LONGRANGE")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_GOHOME, 4, "UnloadedPlatoonJob.UPJOB_GOHOME")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_TRAVEL_TARGET, 5, "UnloadedPlatoonJob.UPJOB_TRAVEL_TARGET")
        t.assert_equal(UnloadedPlatoonJob.UPJOB_TRAVEL_TARGET_FAST, 6, "UnloadedPlatoonJob.UPJOB_TRAVEL_TARGET_FAST")

        -- taskPriority
        t.assert_not_nil(taskPriority, "taskPriority global table")
        t.assert_equal(taskPriority.TP_JUST_ACTION, 0, "taskPriority.TP_JUST_ACTION")
        t.assert_equal(taskPriority.TP_FLUFF, 1, "taskPriority.TP_FLUFF")
        t.assert_equal(taskPriority.TP_NON_URGENT, 2, "taskPriority.TP_NON_URGENT")
        t.assert_equal(taskPriority.TP_URGENT, 3, "taskPriority.TP_URGENT")
        t.assert_equal(taskPriority.TP_OBEDIENCE, 4, "taskPriority.TP_OBEDIENCE")
        t.assert_equal(taskPriority.TP_MAX_SIZE, 5, "taskPriority.TP_MAX_SIZE")

        -- BuildingDesignation
        t.assert_not_nil(BuildingDesignation, "BuildingDesignation global table")
        t.assert_equal(BuildingDesignation.BD_NONE, 0, "BuildingDesignation.BD_NONE")
        t.assert_equal(BuildingDesignation.BD_SHOP, 1, "BuildingDesignation.BD_SHOP")
        t.assert_equal(BuildingDesignation.BD_BARRACKS, 2, "BuildingDesignation.BD_BARRACKS")
        t.assert_equal(BuildingDesignation.BD_BAR, 3, "BuildingDesignation.BD_BAR")
        t.assert_equal(BuildingDesignation.BD_HOSPITAL, 4, "BuildingDesignation.BD_HOSPITAL")
        t.assert_equal(BuildingDesignation.BD_ARMOURY, 5, "BuildingDesignation.BD_ARMOURY")
        t.assert_equal(BuildingDesignation.BD_TREASURE, 6, "BuildingDesignation.BD_TREASURE")
        t.assert_equal(BuildingDesignation.BD_PRISON, 7, "BuildingDesignation.BD_PRISON")
        t.assert_equal(BuildingDesignation.BD_HQ, 8, "BuildingDesignation.BD_HQ")
        t.assert_equal(BuildingDesignation.BD_RESIDENTIAL, 9, "BuildingDesignation.BD_RESIDENTIAL")
        t.assert_equal(BuildingDesignation.BD_SLAVE_STORAGE, 10, "BuildingDesignation.BD_SLAVE_STORAGE")
        t.assert_equal(BuildingDesignation.BD_RESIDENTIAL_SMALL, 11, "BuildingDesignation.BD_RESIDENTIAL_SMALL")

        -- CharacterMessage
        t.assert_not_nil(CharacterMessage, "CharacterMessage global table")
        t.assert_equal(CharacterMessage.ATTACKING_MELEE, 0, "CharacterMessage.ATTACKING_MELEE")
    end)

    ctx.test("kenshilib-050: metatable registry and inheritance links", function(t)
        local reg = debug.getregistry()

        -- Verify all 0.5.0 metatables exist in registry
        local expected = {
            -- AI
            "KenshiLua.AI",
            "KenshiLua.StateBroadcastData",
            "KenshiLua.AITaskSytem",
            "KenshiLua.AITaskSytem_ActionsListMgr",
            "KenshiLua.AITaskSytem_FailedTask",
            "KenshiLua.Blackboard",
            "KenshiLua.Blackboard_TaskInfo",
            "KenshiLua.AIPackage",
            "KenshiLua.CampaignData",
            "KenshiLua.CampaignInstance",
            "KenshiLua.Contract_DefendPlayerBase",
            "KenshiLua.Contract_HiredAlly",
            "KenshiLua.Contract_Timed",
            "KenshiLua.Contract_UntilExSlave",
            "KenshiLua.Contract_UntilOutOfDanger",
            "KenshiLua.TargetInfo",
            "KenshiLua.TargetWithScore",
            "KenshiLua.TaskMatch",
            "KenshiLua.TaskRequest",
            "KenshiLua.StateFunctionList",
            -- Animation
            "KenshiLua.AnimationChoices",
            "KenshiLua.AnimationEvents",
            "KenshiLua.AnimationRequirement",
            "KenshiLua.AnimationClassBase.SingleAnimation",
            "KenshiLua.AnimationClassBase.AnimationLayer",
            "KenshiLua.AnimsListsManager",
            "KenshiLua.AnimsListsManager.AnimList",
            "KenshiLua.AnimationClassAnimal",
            "KenshiLua.AnimationClassHuman",
            "KenshiLua.AnimationEvent",
            "KenshiLua.AnimationGroundEvent",
            "KenshiLua.AnimationReloadEvent",
            "KenshiLua.AnimationSFXEvent",
            "KenshiLua.RagdollAnimation",
            "KenshiLua.RagdollAnimation.RagdollAnimationTrack",
            -- Combat
            "KenshiLua.CombatState",
            "KenshiLua.AttackState",
            "KenshiLua.CircleStateAI",
            "KenshiLua.WaitingStateAI",
            "KenshiLua.RangedCombatClass",
            -- Weather
            "KenshiLua.Weather",
            "KenshiLua.WeatherInstance",
            "KenshiLua.WeatherSystem",
            "KenshiLua.WeatherSystem_FogValues",
            "KenshiLua.WeatherRegion",
            "KenshiLua.Season",
            "KenshiLua.WeatherSystem_ZoneFog",
            -- Town, Movement & Items
            "KenshiLua.TownList",
            "KenshiLua.Formation",
            "KenshiLua.GameDataScoredList",
            "KenshiLua.BlueprintItem",
            "KenshiLua.MapItem",
            "KenshiLua.MoneyItem",
            "KenshiLua.NestItem",
            "KenshiLua.SeveredLimbItem",
            "KenshiLua.RobotLimbItem",
            -- Render, World & Management
            "KenshiLua.KingOfRenderThread",
            "KenshiLua.Renderer",
            "KenshiLua.RendererT",
            "KenshiLua.RenderToTextureotron",
            "KenshiLua.SharedKing",
            "KenshiLua.ZoneMapContent",
            "KenshiLua.ZoneMapContent.HandleDummy",
            "KenshiLua.ZoneMapContent.ZoneMapContentOrderLoader",
            "KenshiLua.ZoneSmell",
            "KenshiLua.ZoneSmell_Smell",
            "KenshiLua.ZoneSmell_SmellMsg",
            "KenshiLua.GunClass",
            "KenshiLua.GunClassPersonal",
            "KenshiLua.GunClassTurret",
            "KenshiLua.Research",
            "KenshiLua.ResearchItem",
            "KenshiLua.HandleManager",
            "KenshiLua.HandleList",
            "KenshiLua.HandleListBase",
            "KenshiLua.HandleContainerList",
            "KenshiLua.ItemHandleList",
            "KenshiLua.PlatoonHandleContainerList",
            "KenshiLua.TownHandleContainerList",
            "KenshiLua.ZoneMapHandleContainerList",
            "KenshiLua.LocaleInfo",
            "KenshiLua.LocaleManager"
        }

        for _, name in ipairs(expected) do
            t.assert_not_nil(reg[name], "metatable " .. name)
        end

        -- Check inheritance chains
        local function check_parent(child_name, expected_parent_name)
            local child_mt = reg[child_name]
            t.assert_not_nil(child_mt, child_name .. " metatable exists")
            local parent_mt = reg[expected_parent_name]
            t.assert_not_nil(parent_mt, expected_parent_name .. " parent metatable exists")
            local meta = getmetatable(child_mt)
            t.assert_not_nil(meta, child_name .. " has meta-metatable")
            t.assert_equal(meta.__index, parent_mt, child_name .. " inherits from " .. expected_parent_name)
        end

        check_parent("KenshiLua.RobotLimbItem", "KenshiLua.Gear")
        check_parent("KenshiLua.BlueprintItem", "KenshiLua.Item")
        check_parent("KenshiLua.MapItem", "KenshiLua.Item")
        check_parent("KenshiLua.MoneyItem", "KenshiLua.Item")
        check_parent("KenshiLua.NestItem", "KenshiLua.Item")
        check_parent("KenshiLua.SeveredLimbItem", "KenshiLua.Item")
        check_parent("KenshiLua.TownList", "KenshiLua.RootObjectContainer")
        check_parent("KenshiLua.GunClassPersonal", "KenshiLua.GunClass")
        check_parent("KenshiLua.GunClassTurret", "KenshiLua.GunClass")
        check_parent("KenshiLua.AnimationClassAnimal", "KenshiLua.AnimationClass")
        check_parent("KenshiLua.AnimationClassHuman", "KenshiLua.AnimationClass")
        check_parent("KenshiLua.AnimationGroundEvent", "KenshiLua.AnimationEvent")
        check_parent("KenshiLua.AnimationReloadEvent", "KenshiLua.AnimationEvent")
        check_parent("KenshiLua.AnimationSFXEvent", "KenshiLua.AnimationEvent")
        check_parent("KenshiLua.AttackState", "KenshiLua.CombatState")
        check_parent("KenshiLua.CircleStateAI", "KenshiLua.CombatState")
        check_parent("KenshiLua.WaitingStateAI", "KenshiLua.CombatState")
        check_parent("KenshiLua.Renderer", "KenshiLua.RendererT")
        check_parent("KenshiLua.HandleListBase", "KenshiLua.Serialisable")
        check_parent("KenshiLua.HandleList", "KenshiLua.HandleListBase")
        check_parent("KenshiLua.ItemHandleList", "KenshiLua.HandleList")
        check_parent("KenshiLua.HandleContainerList", "KenshiLua.HandleListBase")
        check_parent("KenshiLua.PlatoonHandleContainerList", "KenshiLua.HandleContainerList")
        check_parent("KenshiLua.TownHandleContainerList", "KenshiLua.HandleContainerList")
        check_parent("KenshiLua.ZoneMapHandleContainerList", "KenshiLua.HandleContainerList")
    end)
end)

-- =========================================================================
-- Game Phase Tests (Loaded Save World State)
-- =========================================================================

runner.register_game_suite("kenshilib-050", function(ctx)
    ctx.test("kenshilib-050: live world systems (SharedKing, TownList, KingOfRenderThread, Weather, Tech)", function(t)
        -- 1. SharedKing & TownList
        local shou = getSharedKing()
        t.assert_not_nil(shou, "getSharedKing()")
        ---@cast shou -nil
        t.assert_true(type(shou.isLevelEditMode) == "function", "shou:isLevelEditMode is function")
        local isEdit = shou:isLevelEditMode()
        t.assert_true(type(isEdit) == "boolean", "shou:isLevelEditMode() returns boolean")

        local townList = shou.townList
        t.assert_not_nil(townList, "shou.townList is TownList")
        ---@cast townList -nil
        t.assert_true(type(townList.getAllTowns) == "function", "townList:getAllTowns is function")
        local allTowns = townList:getAllTowns()
        t.assert_not_nil(allTowns, "allTowns lektor")
        t.assert_true(#allTowns > 0, "allTowns has elements in live world (count=" .. tostring(#allTowns) .. ")")

        local nullTown = townList:getNullTown()
        t.assert_not_nil(nullTown, "townList:getNullTown()")

        local uniqueTowns = townList.uniqueTowns
        t.assert_not_nil(uniqueTowns, "townList.uniqueTowns")

        local nests = townList.nests
        t.assert_not_nil(nests, "townList.nests")

        -- 2. KingOfRenderThread
        local au = getKingOfRenderThread()
        t.assert_not_nil(au, "getKingOfRenderThread()")

        -- 3. WeatherSystem
        t.assert_not_nil(WeatherSystem, "WeatherSystem global table")
        t.assert_true(type(WeatherSystem.getInstance) == "function", "WeatherSystem.getInstance is function")
        local ws = WeatherSystem.getInstance()
        t.assert_not_nil(ws, "WeatherSystem.getInstance()")
        ---@cast ws -nil
        t.assert_true(type(ws.currentWindValue) == "number", "ws.currentWindValue is number")
        t.assert_true(type(ws.currentRainValue) == "number", "ws.currentRainValue is number")
        t.assert_true(type(ws.globalWetness) == "number", "ws.globalWetness is number")
        t.assert_true(type(ws.currentDustAmount) == "table", "ws.currentDustAmount is table (Vector3)")
        t.assert_true(type(ws.currentDustAmount.x) == "number", "ws.currentDustAmount.x is number")

        -- 4. Player Technology (Research)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")
        ---@cast player -nil
        local tech = player.technology
        t.assert_not_nil(tech, "player.technology (Research)")
        ---@cast tech -nil
        local deskLevel = tech:getResearchDeskLevel()
        t.assert_true(type(deskLevel) == "number", "tech:getResearchDeskLevel() returns number")
        local theoretical = tech.theoreticalTechLevel
        t.assert_true(type(theoretical) == "number", "tech.theoreticalTechLevel is number")
        local rate = tech:getCurrentResearchRate()
        t.assert_true(type(rate) == "number", "tech:getCurrentResearchRate() returns number")
    end)

    ctx.test("kenshilib-050: live character systems (Animation, AI, Formations, Combat)", function(t)
        local player = getPlayerInterface()
        t.assert_not_nil(player, "getPlayerInterface()")
        ---@cast player -nil
        local chars = player.playerCharacters
        t.assert_true(#chars >= 1, "at least one player character")
        local char = chars[1]
        ---@cast char -nil

        -- 1. Animation System
        local anim = char.animation
        t.assert_not_nil(anim, "char.animation")
        ---@cast anim -nil

        local animList = anim:getAnimationDatasList()
        t.assert_not_nil(animList, "anim:getAnimationDatasList()")

        local animReq = anim.animationRequirements
        t.assert_not_nil(animReq, "anim.animationRequirements")

        -- getEvents safety: non-existent animation returns nil without crashing engine
        local events = anim:getEvents("nonexistent_anim_test")
        t.assert_nil(events, "anim:getEvents('nonexistent_anim_test') returns nil")

        local isHuman = anim:isHuman()
        t.assert_not_nil(isHuman, "anim:isHuman()")

        local waterPos = anim:calculatePositionWithWaterHeight()
        t.assert_true(type(waterPos) == "number", "anim:calculatePositionWithWaterHeight() returns number")

        -- 2. Formations
        local form = char:getFormation()
        local enemy_form = char:getEnemyFormation()
        local move_form = char.movement.formation
        local move_enemy_form = char.movement.enemyFormation

        -- 3. AI System
        local ai = char.ai
        t.assert_not_nil(ai, "char.ai")
        ---@cast ai -nil

        local taskSys = ai:getTaskSystem()
        t.assert_not_nil(taskSys, "ai:getTaskSystem()")
        ---@cast taskSys -nil
        t.assert_not_nil(taskSys.orderedGoals, "taskSys.orderedGoals is map container")

        local bb = ai:getBlackboard()
        t.assert_not_nil(bb, "ai:getBlackboard()")

        local broadcast = ai:getStateBroadcast()
        t.assert_not_nil(broadcast, "ai:getStateBroadcast()")

        local aiChar = ai:getCharacter()
        t.assert_not_nil(aiChar, "ai:getCharacter() returns Character")

        local aiPos = ai:getPosition()
        t.assert_true(type(aiPos) == "table", "ai:getPosition() returns table")
        t.assert_true(type(aiPos.x) == "number", "aiPos.x is number")

        t.assert_true(type(ai:amMoving()) == "boolean", "ai:amMoving() is boolean")

        local isIdle = ai:amIdle(char:getHandle(), aiPos)
        t.assert_true(type(isIdle) == "boolean", "ai:amIdle(char:getHandle(), aiPos) is boolean")

        t.assert_true(type(char:shouldIHelpThisGuy(char)) == "boolean", "char:shouldIHelpThisGuy(char) is boolean")

        -- 4. Combat Controller
        local combat = char:getCombatClass()
        if combat ~= nil then
            t.assert_true(type(combat:isAI()) == "boolean", "combat:isAI() is boolean")
            t.assert_true(type(combat:getNumOpponents()) == "number", "combat:getNumOpponents() is number")
        end
    end)
end)

