-- LuaLS regression fixture: global and nested enums.

local character = getSelectedCharacter()
if character then
    -- Global enums
    local currentState = character:getProneState()
    character:setProneState(currentState)
    character:setProneState(ProneState.PS_NORMAL)
    character:setProneState(ProneState.PS_STAYING_LOW)
    character:setProneState(ProneState.PS_CRIPPLED)

    local crime = CrimeEnum.CRIME_STEALING
    local weaponCat = WeaponCategory.SKILL_KATANAS
    local attachSlot = AttachSlot.ATTACH_WEAPON

    -- Nested enums
    local appGender = AppearanceManager.Gender.Enum.FEMALE
    local kenshiPlatform = KenshiLib.BinaryVersion.KenshiPlatform.GOG
    local charMessage = Character.CharMessage.CHARMESSAGE_NONE
    local meshDir = MeshDataLookup.Dir.FRONT
    local dialogueMsg = Dialogue.DT_MSG.DT_END_DIALOG
    local factionEv = FactionRelations.FactionEvent.AIDED_US_IN_BATTLE

    if crime == CrimeEnum.CRIME_MURDER then
        KenshiLua.logDebug("Murder reported")
    end

    if appGender == AppearanceManager.Gender.Enum.MALE then
        KenshiLua.logDebug("Male appearance")
    end

    if kenshiPlatform == KenshiLib.BinaryVersion.KenshiPlatform.STEAM then
        KenshiLua.logDebug("Steam platform")
    end

    if weaponCat == WeaponCategory.SKILL_SABRES then
        KenshiLua.logDebug("Sabres")
    end

    if attachSlot == AttachSlot.ATTACH_BACK then
        KenshiLua.logDebug("Back slot")
    end

    if dialogueMsg == Dialogue.DT_MSG.DT_NONE then
        KenshiLua.logDebug("No dialogue message")
    end

    if factionEv == FactionRelations.FactionEvent.ATTACKED_US_AGGRESSIVELY then
        KenshiLua.logDebug("Faction attacked aggressively")
    end

    if meshDir == MeshDataLookup.Dir.BACK then
        KenshiLua.logDebug("Mesh dir back")
    end

    if charMessage == Character.CharMessage.CHARMESSAGE_NONE then
        KenshiLua.logDebug("No char message")
    end

    local water = WaterState.Enum.DEEP_WATER
    local ragdoll = RagdollPart.Enum.HEAD
    local statGroup = CharacterStatsWindow.StatGroup.Group.COMBAT
    local effect = EffectType.Enum.CAMERA
    local trade = InventoryGUI.TradeResult.Enum.OK
    local attack = AttackDirection.Enum.FRONT
    local bodyPart = MedicalSystem.HealthPartStatus.PartType.PART_HEAD
    local physicsFile = NXU.NXU_FileType.FT_BINARY
    local answer = YesNoMaybe.ynm.MAYBE
    local mask = hkVector4ComparisonMask.Mask.MASK_XY
    local result = hkResultEnum.HK_SUCCESS
    local navMessage = NavMesh.MessageType.CREATE
    local navTask = NavMeshGenerator.TaskType.GENERATE_ZONE
    local memory = hkMemoryAllocator.MemoryState.MEMORY_STATE_OK
    local vectorConstant = hkVectorConstant.HK_QUADREAL_PI

    KenshiLua.logDebug(water, ragdoll, statGroup, effect, trade, attack, bodyPart,
        physicsFile, answer, mask, result, navMessage, navTask, memory, vectorConstant)
end
