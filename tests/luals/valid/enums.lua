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
    local appGender = AppearanceManager.Gender.FEMALE
    local kenshiPlatform = BinaryVersion.KenshiPlatform.GOG
    local charMessage = Character.CharMessage.CHARMESSAGE_NONE
    local meshDir = MeshDataLookup.Dir.FRONT
    local dialogueMsg = Dialogue.DT_MSG.DT_END_DIALOG
    local factionEv = FactionRelations.FactionEvent.AIDED_US_IN_BATTLE

    if crime == CrimeEnum.CRIME_MURDER then
        KenshiLua.logDebug("Murder reported")
    end

    if appGender == AppearanceManager.Gender.MALE then
        KenshiLua.logDebug("Male appearance")
    end

    if kenshiPlatform == BinaryVersion.KenshiPlatform.STEAM then
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
end
