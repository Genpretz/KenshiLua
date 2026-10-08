-- LuaLS regression fixture: DialogLineData and its directly registered containers.

---@param line DialogLineData
---@param other DialogLineData
---@param data GameData
---@param dataList Lektor<GameData>
---@param pairs LektorReadOnly<GameDataValuePair>
---@param campaign FitnessSelectorCampaignTriggerData
---@param faction Faction
---@param states WorldEventStateQueryList
---@param choices DialogChoiceList
---@param conditions Lektor<DialogCondition>
---@param actions Lektor<DialogAction>
---@param lines Lektor<DialogLineData>
---@param effects OgreUnorderedMap<GameData, integer>
---@param owner hand
---@param time TimeOfDay
---@param dialogue Dialogue
---@param character Character
local function checkDialogLineData(line, other, data, dataList, pairs, campaign, faction, states, choices, conditions, actions, lines, effects, owner, time, dialogue, character)
    assert(line:getParent() == nil or line:getParent() == other)
    assert(type(line:isForSpecificCharacter(data)) == "boolean")
    assert(type(line:hasSpecificCharacterRequirement()) == "boolean")
    line:setupChildren()
    assert(type(line:checkRepeatLimits()) == "boolean")
    assert(type(line:checkTags(character, character)) == "boolean")
    assert(type(line:getName()) == "string" and type(line:saidItBefore()) == "boolean")
    assert(type(line:willTalkToEnemies()) == "boolean")
    assert(type(line:isEmptyNode()) == "boolean" and type(line:_NV_isEmptyNode()) == "boolean")
    assert(type(line:isAnnouncement()) == "boolean")
    line:stampLastTimeSaid()
    assert(type(line:getScore(character)) == "number")
    assert(type(line:getScorePlusChildrenIfEmpty(character)) == "number")
    assert(type(line:hasChildren()) == "boolean")
    assert(type(line:checkConditions(dialogue, character, false)) == "boolean")
    assert(line:chooseAChild(dialogue, character, false) == nil or line:chooseAChild(dialogue, character, false) == other)
    assert(type(line:getStringID()) == "string" and (line:getGameData() == nil or line:getGameData() == data))
    assert(line:getChildByStringID("fixture") == nil or line:getChildByStringID("fixture") == other)
    line:setParent(other)
    assert(type(line:getMoneyCostForLine()) == "number" and type(line:getText(false)) == "string")
    line:getPlayerReplies(lines, dialogue, character)
    assert(line:getActions() == nil or line:getActions() == actions)

    line.targetFlagsNeeded = 0
    line.targetFlagsNotWanted = 0
    line.personalityNeeded = 0
    line.personalityNotWanted = 0
    line.campaignTriggers = campaign
    line.isTargetRace = dataList
    line.isTargetSubRace_specificallyTheTarget = dataList
    line.givesItem = pairs
    line.inTownOf = { faction }
    line.isTargetFaction = { faction }
    line.isMyFaction = { faction }
    line.isCharacter = dataList
    line.isTargetCarryingCharacter = dataList
    line.hasPackage = dataList
    line.isMyRace = dataList
    line.isMySubRace = dataList
    line.hasItemType = ItemFunction.ITEM_NO_FUNCTION
    line.hasItem = dataList
    line.worldState = states
    line.data = data
    line.onceOnly = false
    line.isMonologue = false
    line.forCertainType = CharacterTypeEnum.OT_NONE
    line.children = choices
    line.conditions = conditions
    line.actions = actions
    line.lineCount = 1
    line.texts = { "fixture" }
    line.parent = other
    line.chancePermanent = 1
    line.chanceTemporary = 1
    line.unique = false
    line.uniqueOwner = owner
    line.dialogRepeatMinTimeInHours = 1
    line.lastTimeSaid = time
    line.score = 1
    line.oneAtATime = false
    line.isLocked = false
    line.locks = lines
    line.unlocks_lockMe = lines
    line.unlocks_dontLockMe = lines
    line.crowdTrigger = other
    line.factionRelationEffects = effects
    line.playerInterruptionDialog = other
    line.isInterjection = false
    line.speaker = TalkerEnum.T_ME

    assert(type(pairs:size()) == "number" and pairs:toTable() ~= nil)
    campaign.totalScore = 0
    campaign.highestScore = 0
    assert(campaign.highestItem == nil or campaign.highestItem ~= nil)
    assert(campaign.list == nil and campaign.itemsScores == nil)
    assert(type(effects:has(data)) == "boolean" and type(effects:contains(data)) == "boolean")
    assert(type(effects:remove(data)) == "boolean" and type(effects:erase(data)) == "boolean")
    assert(effects:size() >= 0 and effects:toTable() ~= nil)
    local iterator, state, control = effects:pairs()
    assert(type(iterator) == "function" and state == effects and control == nil)
    effects:clear()
end

return checkDialogLineData
