# Lua Bindings Reference

## Table of Contents
- [AIOptions](#aioptions)
- [AbstractMovementBase](#abstractmovementbase)
- [ActivePlatoon](#activeplatoon)
- [AnimalInventoryLayout](#animalinventorylayout)
- [AppearanceAnimal](#appearanceanimal)
- [AppearanceBase](#appearancebase)
- [AppearanceHuman](#appearancehuman)
- [Armour](#armour)
- [AttachedArrowManager](#attachedarrowmanager)
- [Bounty](#bounty)
- [BountyManager](#bountymanager)
- [BuildingSwaps](#buildingswaps)
- [CameraClass](#cameraclass)
- [CampaignTriggerData](#campaigntriggerdata)
- [CharBody](#charbody)
- [CharMovement](#charmovement)
- [CharStats](#charstats)
- [Character](#character)
- [CharacterAnimal](#characteranimal)
- [CharacterHuman](#characterhuman)
- [CharacterInventoryLayout](#characterinventorylayout)
- [CombatMovementController](#combatmovementcontroller)
- [CombatTechniqueData](#combattechniquedata)
- [ContainerItem](#containeritem)
- [ContextMenu](#contextmenu)
- [CreatelistItem](#createlistitem)
- [Crossbow](#crossbow)
- [Damages](#damages)
- [DataObjectContainer](#dataobjectcontainer)
- [DelayedSpawnMsg](#delayedspawnmsg)
- [DialogAction](#dialogaction)
- [DialogChoiceList](#dialogchoicelist)
- [DialogCondition](#dialogcondition)
- [DialogDataManager](#dialogdatamanager)
- [DialogLineData](#dialoglinedata)
- [DialogState](#dialogstate)
- [Dialogue](#dialogue)
- [DialogueSpeechBubble](#dialoguespeechbubble)
- [Faction](#faction)
- [FactionLeader](#factionleader)
- [FactionManager](#factionmanager)
- [FactionRelations](#factionrelations)
- [FactoryCallbackInterface](#factorycallbackinterface)
- [FlagCondition](#flagcondition)
- [FlockingTools](#flockingtools)
- [FormationMover](#formationmover)
- [GameData](#gamedata)
- [GameDataContainer](#gamedatacontainer)
- [GameDataCopyStandalone](#gamedatacopystandalone)
- [GameDataHeader](#gamedataheader)
- [GameDataManager](#gamedatamanager)
- [GameDataReference](#gamedatareference)
- [GameDataValuePair](#gamedatavaluepair)
- [GameSaveState](#gamesavestate)
- [GameWorld](#gameworld)
- [GameplayOptions](#gameplayoptions)
- [Gear](#gear)
- [Global](#global)
- [HasRoomCache](#hasroomcache)
- [HealthPartStatus](#healthpartstatus)
- [ImpactPoint](#impactpoint)
- [InputHandler](#inputhandler)
- [Inventory](#inventory)
- [InventoryItemBase](#inventoryitembase)
- [InventorySection](#inventorysection)
- [Item](#item)
- [ItemData](#itemdata)
- [LimbsInventoryLayout](#limbsinventorylayout)
- [Limiter](#limiter)
- [LockedArmour](#lockedarmour)
- [MedianFilter](#medianfilter)
- [MedianFilter2DVector](#medianfilter2dvector)
- [MedicalSystem](#medicalsystem)
- [MeshDataLookup](#meshdatalookup)
- [ModInfo](#modinfo)
- [MotionFilter](#motionfilter)
- [MyGui](#mygui)
- [NxUserControllerHitReport](#nxusercontrollerhitreport)
- [ObjectInstance](#objectinstance)
- [OptionsHolder](#optionsholder)
- [Ownerships](#ownerships)
- [Platoon](#platoon)
- [PlayerInterface](#playerinterface)
- [RaceData](#racedata)
- [RaceLimiter](#racelimiter)
- [RelationData](#relationdata)
- [RepetitionCounter](#repetitioncounter)
- [RobotLimbs](#robotlimbs)
- [RootObject](#rootobject)
- [RootObjectBase](#rootobjectbase)
- [RootObjectContainer](#rootobjectcontainer)
- [RootObjectFactory](#rootobjectfactory)
- [SectionItem](#sectionitem)
- [SeenSomeone](#seensomeone)
- [SelectionBox](#selectionbox)
- [SenseItr](#senseitr)
- [SensoryData](#sensorydata)
- [ShopTrader](#shoptrader)
- [ShopTraderInventory](#shoptraderinventory)
- [ShopTraderInventorySection](#shoptraderinventorysection)
- [SimpleTimeStamper](#simpletimestamper)
- [SpecificItemLoadFirst](#specificitemloadfirst)
- [SpeedGroup](#speedgroup)
- [Spot](#spot)
- [SpottingPeopleMgr](#spottingpeoplemgr)
- [Sword](#sword)
- [SysMessage](#sysmessage)
- [TaskData](#taskdata)
- [TaskStateData](#taskstatedata)
- [Tasker](#tasker)
- [Town](#town)
- [TownBase](#townbase)
- [TownBuildingsManager](#townbuildingsmanager)
- [TownPositionCacher](#townpositioncacher)
- [VisibleObjectInfo](#visibleobjectinfo)
- [Weapon](#weapon)
- [WhoSeesMe](#whoseesme)
- [WorldEventStateQuery](#worldeventstatequery)
- [WorldEventStateQueryList](#worldeventstatequerylist)
- [physHit](#physhit)

## AIOptions
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| healAllies | healAllies | boolean | RW | `obj.healAllies = <value>` |
| helpAllies | helpAllies | boolean | RW | `obj.helpAllies = <value>` |
| rescueAllies | rescueAllies | boolean | RW | `obj.rescueAllies = <value>` |
| stayInBase | stayInBase | boolean | RW | `obj.stayInBase = <value>` |
| feedAnimals | feedAnimals | boolean | RW | `obj.feedAnimals = <value>` |
| shareFood | shareFood | boolean | RW | `obj.shareFood = <value>` |
| autoSleep | autoSleep | boolean | RW | `obj.autoSleep = <value>` |
| autoDitchItems | autoDitchItems | boolean | RW | `obj.autoDitchItems = <value>` |
| autoSit | autoSit | boolean | RW | `obj.autoSit = <value>` |
| ejectEnemies | ejectEnemies | boolean | RW | `obj.ejectEnemies = <value>` |
| shootFirst | shootFirst | boolean | RW | `obj.shootFirst = <value>` |

## AbstractMovementBase
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| officiallyStopped | officiallyStopped | boolean | RW | `obj.officiallyStopped = <value>` |
| speedGroup | speedGroup | SpeedGroup | RW | `obj.speedGroup = <value>` |
| speedOrders | (lua_Integer | integer | RW | `obj.speedOrders = <value>` |
| currentlyMoving | currentlyMoving | boolean | RW | `obj.currentlyMoving = <value>` |
| positionSmoother | positionSmoother | MedianFilter2DVector | RW | `obj.positionSmoother = <value>` |
| currentMotion | currentMotion | Vector3 | RW | `obj.currentMotion = <value>` |
| maxSpeed | maxSpeed | number | RW | `obj.maxSpeed = <value>` |
| currentSpeed | currentSpeed | number | RW | `obj.currentSpeed = <value>` |
| desiredSpeed | desiredSpeed | number | RW | `obj.desiredSpeed = <value>` |
| walkSpeed | walkSpeed | number | RW | `obj.walkSpeed = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| direction | direction | Vector3 | RW | `obj.direction = <value>` |
| destination | destination | Vector3 | RW | `obj.destination = <value>` |
| pathDestination | pathDestination | Vector3 | RW | `obj.pathDestination = <value>` |
| roadFollower | roadFollower | RoadFollower* | R | `obj.roadFollower` |
| roadWeight | roadWeight | number | RW | `obj.roadWeight = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| create | create | `obj:create(...)` |
| _setPositionAndTeleport | _setPositionAndTeleport | `obj:_setPositionAndTeleport(...)` |
| _NV__setPositionAndTeleport | _NV__setPositionAndTeleport | `obj:_NV__setPositionAndTeleport(...)` |
| _setPositionSimple | _setPositionSimple | `obj:_setPositionSimple(...)` |
| _NV__setPositionSimple | _NV__setPositionSimple | `obj:_NV__setPositionSimple(...)` |
| faceDirection | faceDirection | `obj:faceDirection(...)` |
| _NV_faceDirection | _NV_faceDirection | `obj:_NV_faceDirection(...)` |
| lookatPosition | lookatPosition | `obj:lookatPosition(...)` |
| _NV_lookatPosition | _NV_lookatPosition | `obj:_NV_lookatPosition(...)` |
| getDestination | getDestination | `obj:getDestination(...)` |
| isProbablyStuck | isProbablyStuck | `obj:isProbablyStuck(...)` |
| pathOk | pathOk | `obj:pathOk(...)` |
| _NV_pathOk | _NV_pathOk | `obj:_NV_pathOk(...)` |
| pathFailed | pathFailed | `obj:pathFailed(...)` |
| _NV_pathFailed | _NV_pathFailed | `obj:_NV_pathFailed(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| isDestinationReached | isDestinationReached | `obj:isDestinationReached(...)` |
| _NV_isDestinationReached | _NV_isDestinationReached | `obj:_NV_isDestinationReached(...)` |
| amInsideTownWalls | amInsideTownWalls | `obj:amInsideTownWalls(...)` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `obj:_NV_amInsideTownWalls(...)` |
| manualMovement | manualMovement | `obj:manualMovement(...)` |
| _NV_manualMovement | _NV_manualMovement | `obj:_NV_manualMovement(...)` |
| halt | halt | `obj:halt(...)` |
| _NV_halt | _NV_halt | `obj:_NV_halt(...)` |
| setRoadDestination | setRoadDestination | `obj:setRoadDestination(...)` |
| setRoadPreference | setRoadPreference | `obj:setRoadPreference(...)` |
| setDestination | setDestination | `obj:setDestination(...)` |
| _NV_setDestination | _NV_setDestination | `obj:_NV_setDestination(...)` |
| setDesiredSpeed | setDesiredSpeed | `obj:setDesiredSpeed(...)` |
| setDesiredSpeedOrders | setDesiredSpeedOrders | `obj:setDesiredSpeedOrders(...)` |
| _NV_setDesiredSpeed | _NV_setDesiredSpeed | `obj:_NV_setDesiredSpeed(...)` |
| setStandardWalkSpeed | setStandardWalkSpeed | `obj:setStandardWalkSpeed(...)` |
| getStandardWalkSpeed | getStandardWalkSpeed | `obj:getStandardWalkSpeed(...)` |
| restoreDesiredSpeed | restoreDesiredSpeed | `obj:restoreDesiredSpeed(...)` |
| setMaxSpeed | setMaxSpeed | `obj:setMaxSpeed(...)` |
| getMaxSpeed | getMaxSpeed | `obj:getMaxSpeed(...)` |
| isCurrentlyMoving | isCurrentlyMoving | `obj:isCurrentlyMoving(...)` |
| getCurrentSpeed | getCurrentSpeed | `obj:getCurrentSpeed(...)` |
| getCurrentMotion | getCurrentMotion | `obj:getCurrentMotion(...)` |
| getCurrentSpeedRelativeToMax01 | getCurrentSpeedRelativeToMax01 | `obj:getCurrentSpeedRelativeToMax01(...)` |
| getSpeedOrders | getSpeedOrders | `obj:getSpeedOrders(...)` |
| leaveSpeedGroup | leaveSpeedGroup | `obj:leaveSpeedGroup(...)` |
| getHandle | AbstractMovementBase_getHandle | `obj:getHandle(...)` |
| _NV_getHandle | AbstractMovementBase__NV_getHandle | `obj:_NV_getHandle(...)` |
| getPosition | AbstractMovementBase_getPosition | `obj:getPosition(...)` |
| _NV_getPosition | AbstractMovementBase__NV_getPosition | `obj:_NV_getPosition(...)` |
| getFacingDirection | AbstractMovementBase_getFacingDirection | `obj:getFacingDirection(...)` |

## ActivePlatoon
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _groupSense | _groupSense | GroupSense* | R | `obj._groupSense` |
| isAnimalsOnly | isAnimalsOnly | boolean | RW | `obj.isAnimalsOnly = <value>` |
| me | me | Platoon | R | `obj.me` |
| characterHandles | characterHandles | HandleList* | R | `obj.characterHandles` |
| p_TIME | p_TIME | number | RW | `obj.p_TIME = <value>` |
| lastActiveZone | lastActiveZone | ZoneMap* | R | `obj.lastActiveZone` |
| _myMemory | _myMemory | CharacterMemory* | R | `obj._myMemory` |
| squadleader | squadleader | Character | R | `obj.squadleader` |
| backupLeader | backupLeader | Character | R | `obj.backupLeader` |
| deactivationTimer | deactivationTimer | number | RW | `obj.deactivationTimer = <value>` |
| workingPos | workingPos | Vector3 | RW | `obj.workingPos = <value>` |
| currentGoal | currentGoal | Tasker | RW | `obj.currentGoal = <value>` |
| positionMoved | positionMoved | Vector3 | RW | `obj.positionMoved = <value>` |
| teleportTo | teleportTo | Vector3 | RW | `obj.teleportTo = <value>` |
| teleportMessage | teleportMessage | boolean | RW | `obj.teleportMessage = <value>` |
| isPlayer | isPlayer | PlayerInterface | R | `obj.isPlayer` |
| isPhysical | isPhysical | boolean | RW | `obj.isPhysical = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _recalculateIsIntact | _recalculateIsIntact | `obj:_recalculateIsIntact(...)` |
| isAnyoneCaptured | isAnyoneCaptured | `obj:isAnyoneCaptured(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| swapCharacters | swapCharacters | `obj:swapCharacters(...)` |
| emptySquadCheck | emptySquadCheck | `obj:emptySquadCheck(...)` |
| clearAllTheUniqueNPCStates | clearAllTheUniqueNPCStates | `obj:clearAllTheUniqueNPCStates(...)` |
| isIntact | isIntact | `obj:isIntact(...)` |
| getSquadLeader_theRealOne | getSquadLeader_theRealOne | `obj:getSquadLeader_theRealOne(...)` |
| getNearestActiveCharacter | getNearestActiveCharacter | `obj:getNearestActiveCharacter(...)` |
| getSquadLeader | getSquadLeader | `obj:getSquadLeader(...)` |
| getSquadSize | getSquadSize | `obj:getSquadSize(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| refreshInventory | refreshInventory | `obj:refreshInventory(...)` |
| _forceRefreshInventory | _forceRefreshInventory | `obj:_forceRefreshInventory(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| serialiseEverythingToDisk | serialiseEverythingToDisk | `obj:serialiseEverythingToDisk(...)` |
| isWholeSquadDown | isWholeSquadDown | `obj:isWholeSquadDown(...)` |
| setDataFilename | setDataFilename | `obj:setDataFilename(...)` |
| setupLeaderDialogues | setupLeaderDialogues | `obj:setupLeaderDialogues(...)` |
| isLoaded | isLoaded | `obj:isLoaded(...)` |
| teleport | teleport | `obj:teleport(...)` |
| setName | setName | `obj:setName(...)` |
| getIsTrader | getIsTrader | `obj:getIsTrader(...)` |
| getHasVendorList | getHasVendorList | `obj:getHasVendorList(...)` |
| getHasSpecialItemsList | getHasSpecialItemsList | `obj:getHasSpecialItemsList(...)` |
| setupTraderBuildings | setupTraderBuildings | `obj:setupTraderBuildings(...)` |
| putTheSpecialCharactersInNewSquads_captured | putTheSpecialCharactersInNewSquads_captured | `obj:putTheSpecialCharactersInNewSquads_captured(...)` |
| checkForCharactersBeingCarried | checkForCharactersBeingCarried | `obj:checkForCharactersBeingCarried(...)` |
| restoreSquad | restoreSquad | `obj:restoreSquad(...)` |
| unloadCheck | unloadCheck | `obj:unloadCheck(...)` |
| destroyCharacters | destroyCharacters | `obj:destroyCharacters(...)` |
| serialiseCharacterData | serialiseCharacterData | `obj:serialiseCharacterData(...)` |
| saveToDisk | saveToDisk | `obj:saveToDisk(...)` |
| calculateCurrentPos | calculateCurrentPos | `obj:calculateCurrentPos(...)` |
| _checkForUniqueCharactersOnUnload | _checkForUniqueCharactersOnUnload | `obj:_checkForUniqueCharactersOnUnload(...)` |
| removeObject | ActivePlatoon_removeObject | `obj:removeObject(...)` |
| _NV_removeObject | ActivePlatoon__NV_removeObject | `obj:_NV_removeObject(...)` |
| addActiveObject | ActivePlatoon_addActiveObject | `obj:addActiveObject(...)` |
| _NV_addActiveObject | ActivePlatoon__NV_addActiveObject | `obj:_NV_addActiveObject(...)` |
| addCharacterAt | ActivePlatoon_addCharacterAt | `obj:addCharacterAt(...)` |
| setSquadLeader | ActivePlatoon_setSquadLeader | `obj:setSquadLeader(...)` |
| getName | ActivePlatoon_getName | `obj:getName(...)` |
| loadFromDisk | ActivePlatoon_loadFromDisk | `obj:loadFromDisk(...)` |
| _NV_loadFromDisk | ActivePlatoon__NV_loadFromDisk | `obj:_NV_loadFromDisk(...)` |
| getGroupSense | ActivePlatoon_getGroupSense | `obj:getGroupSense(...)` |
| getMemory | ActivePlatoon_getMemory | `obj:getMemory(...)` |
| getCharactersInArea | ActivePlatoon_getCharactersInArea | `obj:getCharactersInArea(...)` |
| setupCheck | ActivePlatoon_setupCheck | `obj:setupCheck(...)` |
| loadCharacters | ActivePlatoon_loadCharacters | `obj:loadCharacters(...)` |
| _NV_loadCharacters | ActivePlatoon__NV_loadCharacters | `obj:_NV_loadCharacters(...)` |
| loadInstance | ActivePlatoon_loadInstance | `obj:loadInstance(...)` |
| _NV_loadInstance | ActivePlatoon__NV_loadInstance | `obj:_NV_loadInstance(...)` |

## AnimalInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## AppearanceAnimal
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| createBody | createBody | `obj:createBody(...)` |
| _NV_createBody | _NV_createBody | `obj:_NV_createBody(...)` |
| updateCharaterTexture | updateCharaterTexture | `obj:updateCharaterTexture(...)` |
| _NV_updateCharaterTexture | _NV_updateCharaterTexture | `obj:_NV_updateCharaterTexture(...)` |

## AppearanceBase
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| slots | slots | const boost::unordered::unordered_map<std::string, AttachmentData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachmentData*>, Ogre::GeneralAllocPolicy > >* | R | `obj.slots` |
| attachedObjects | attachedObjects | boost::unordered::unordered_map<std::string, AttachedEntity*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachedEntity*>, Ogre::GeneralAllocPolicy > > | R | `obj.attachedObjects` |
| attachedHarpoons | attachedHarpoons | Ogre::FastArray<Harpoon*> | R | `obj.attachedHarpoons` |
| msgClearHarpoons | msgClearHarpoons | boolean | RW | `obj.msgClearHarpoons = <value>` |
| attachedEffects | attachedEffects | Ogre::FastArray<AttachedEffect*> | R | `obj.attachedEffects` |
| attachedEffectsToRemove | attachedEffectsToRemove | Ogre::FastArray<AttachedEffect*> | R | `obj.attachedEffectsToRemove` |
| woundsList | woundsList | Ogre::FastArray<Wound*> | R | `obj.woundsList` |
| woundsListMutex | woundsListMutex | unknown | R | `obj.woundsListMutex` |
| body | body | Ogre::Entity* | R | `obj.body` |
| bodyLoader | bodyLoader | Ogre::Entity* | R | `obj.bodyLoader` |
| isCreatingBody | isCreatingBody | boolean | RW | `obj.isCreatingBody = <value>` |
| bodyRadius | bodyRadius | number | RW | `obj.bodyRadius = <value>` |
| me | me | Character | R | `obj.me` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| bodyFilename | bodyFilename | string | RW | `obj.bodyFilename = <value>` |
| bodyMaterial | bodyMaterial | Ogre::SharedPtr<Ogre::Material> | R | `obj.bodyMaterial` |
| animation | animation | AnimationClass* | R | `obj.animation` |
| female | female | boolean | RW | `obj.female = <value>` |
| updatedAttachments | updatedAttachments | boolean | RW | `obj.updatedAttachments = <value>` |
| updatedAppearanceData | updatedAppearanceData | boolean | RW | `obj.updatedAppearanceData = <value>` |
| updateBody | updateBody | boolean | RW | `obj.updateBody = <value>` |
| suid | suid | integer | RW | `obj.suid = <value>` |
| appearanceData | appearanceData | GameDataCopyStandalone* | R | `obj.appearanceData` |
| raceData | raceData | GameData | R | `obj.raceData` |
| factionColor | factionColor | GameData | R | `obj.factionColor` |
| hairStyle | hairStyle | GameData | R | `obj.hairStyle` |
| shaved | shaved | boolean | RW | `obj.shaved = <value>` |
| waterline | waterline | Ogre::Vector4 | R | `obj.waterline` |
| waterLineFadeTimer | waterLineFadeTimer | number | RW | `obj.waterLineFadeTimer = <value>` |
| barefoot | barefoot | boolean | RW | `obj.barefoot = <value>` |
| hideAttachments | hideAttachments | boolean | RW | `obj.hideAttachments = <value>` |
| characterHeight | characterHeight | number | RW | `obj.characterHeight = <value>` |
| characterHeightSpeedMultiplier | characterHeightSpeedMultiplier | number | RW | `obj.characterHeightSpeedMultiplier = <value>` |
| characterHeight_0to1 | characterHeight_0to1 | number | RW | `obj.characterHeight_0to1 = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| updateAnimationTransforms | updateAnimationTransforms | `obj:updateAnimationTransforms(...)` |
| forceUpdateAnimationTransforms | forceUpdateAnimationTransforms | `obj:forceUpdateAnimationTransforms(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| activate | activate | `obj:activate(...)` |
| _NV_activate | _NV_activate | `obj:_NV_activate(...)` |
| deactivate | deactivate | `obj:deactivate(...)` |
| _NV_deactivate | _NV_deactivate | `obj:_NV_deactivate(...)` |
| isFemale | isFemale | `obj:isFemale(...)` |
| setGender | setGender | `obj:setGender(...)` |
| _NV_setGender | _NV_setGender | `obj:_NV_setGender(...)` |
| getRace | getRace | `obj:getRace(...)` |
| detachAllHarpoonsT | detachAllHarpoonsT | `obj:detachAllHarpoonsT(...)` |
| _detachAllHarpoons | _detachAllHarpoons | `obj:_detachAllHarpoons(...)` |
| updateWetness | updateWetness | `obj:updateWetness(...)` |
| updateBloodyness | updateBloodyness | `obj:updateBloodyness(...)` |
| getAttachmentPosition | getAttachmentPosition | `obj:getAttachmentPosition(...)` |
| hasSlot | hasSlot | `obj:hasSlot(...)` |
| getNormalisedCharacterHeight | getNormalisedCharacterHeight | `obj:getNormalisedCharacterHeight(...)` |
| getCharacterHeight | getCharacterHeight | `obj:getCharacterHeight(...)` |
| getBodyRadius | getBodyRadius | `obj:getBodyRadius(...)` |
| failedToLoad | failedToLoad | `obj:failedToLoad(...)` |
| getBonePosition | getBonePosition | `obj:getBonePosition(...)` |
| getBoneOrientation | getBoneOrientation | `obj:getBoneOrientation(...)` |
| getVertexWorldPosition | getVertexWorldPosition | `obj:getVertexWorldPosition(...)` |
| getRandomVertex | getRandomVertex | `obj:getRandomVertex(...)` |
| notifyDirty | notifyDirty | `obj:notifyDirty(...)` |
| reload | reload | `obj:reload(...)` |
| updateAppearance | updateAppearance | `obj:updateAppearance(...)` |
| _NV_updateAppearance | _NV_updateAppearance | `obj:_NV_updateAppearance(...)` |
| updatePortrait | updatePortrait | `obj:updatePortrait(...)` |
| updateMovementScale | updateMovementScale | `obj:updateMovementScale(...)` |
| switchLights | switchLights | `obj:switchLights(...)` |
| hasLights | hasLights | `obj:hasLights(...)` |
| shaveHead | shaveHead | `obj:shaveHead(...)` |
| isShaved | isShaved | `obj:isShaved(...)` |
| setFlayed | setFlayed | `obj:setFlayed(...)` |
| _NV_setFlayed | _NV_setFlayed | `obj:_NV_setFlayed(...)` |
| isFlayed | isFlayed | `obj:isFlayed(...)` |
| _NV_isFlayed | _NV_isFlayed | `obj:_NV_isFlayed(...)` |
| isBarefoot | isBarefoot | `obj:isBarefoot(...)` |
| _NV_isBarefoot | _NV_isBarefoot | `obj:_NV_isBarefoot(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| getAttachmentsLoaded | getAttachmentsLoaded | `obj:getAttachmentsLoaded(...)` |
| setAttachmentsVisible | setAttachmentsVisible | `obj:setAttachmentsVisible(...)` |
| _NV_setAttachmentsVisible | _NV_setAttachmentsVisible | `obj:_NV_setAttachmentsVisible(...)` |
| createBody | createBody | `obj:createBody(...)` |
| buildAttachments | buildAttachments | `obj:buildAttachments(...)` |
| setHairTexture | setHairTexture | `obj:setHairTexture(...)` |
| updateOverlap | updateOverlap | `obj:updateOverlap(...)` |
| updateCharaterTexture | updateCharaterTexture | `obj:updateCharaterTexture(...)` |
| getCharacterHeightSpeedMultiplier | getCharacterHeightSpeedMultiplier | `obj:getCharacterHeightSpeedMultiplier(...)` |

## AppearanceHuman
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| robotLegScale | robotLegScale | number | RW | `obj.robotLegScale = <value>` |
| lastPhysiqueStats | lastPhysiqueStats | Vector3 | RW | `obj.lastPhysiqueStats = <value>` |
| bulkMult | bulkMult | number | RW | `obj.bulkMult = <value>` |
| muscleMult | muscleMult | number | RW | `obj.muscleMult = <value>` |
| skinnyMult | skinnyMult | number | RW | `obj.skinnyMult = <value>` |
| flayed | flayed | boolean | RW | `obj.flayed = <value>` |
| beard | beard | GameData | R | `obj.beard` |
| hiddenPartsEnabled | hiddenPartsEnabled | boolean | RW | `obj.hiddenPartsEnabled = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| setGender | setGender | `obj:setGender(...)` |
| _NV_setGender | _NV_setGender | `obj:_NV_setGender(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| setAttachmentsVisible | setAttachmentsVisible | `obj:setAttachmentsVisible(...)` |
| _NV_setAttachmentsVisible | _NV_setAttachmentsVisible | `obj:_NV_setAttachmentsVisible(...)` |
| setHiddenPartsEnabled | setHiddenPartsEnabled | `obj:setHiddenPartsEnabled(...)` |
| showFace | showFace | `obj:showFace(...)` |
| setFlayed | setFlayed | `obj:setFlayed(...)` |
| _NV_setFlayed | _NV_setFlayed | `obj:_NV_setFlayed(...)` |
| isFlayed | isFlayed | `obj:isFlayed(...)` |
| _NV_isFlayed | _NV_isFlayed | `obj:_NV_isFlayed(...)` |
| updateProportions | updateProportions | `obj:updateProportions(...)` |
| createBody | createBody | `obj:createBody(...)` |
| _NV_createBody | _NV_createBody | `obj:_NV_createBody(...)` |
| updateAppearance | updateAppearance | `obj:updateAppearance(...)` |
| _NV_updateAppearance | _NV_updateAppearance | `obj:_NV_updateAppearance(...)` |
| updateHiddenParts | updateHiddenParts | `obj:updateHiddenParts(...)` |
| updatePysiqueFromStats | updatePysiqueFromStats | `obj:updatePysiqueFromStats(...)` |
| updatePhysiqueMuscleMults | updatePhysiqueMuscleMults | `obj:updatePhysiqueMuscleMults(...)` |
| updateCharaterTexture | updateCharaterTexture | `obj:updateCharaterTexture(...)` |
| _NV_updateCharaterTexture | _NV_updateCharaterTexture | `obj:_NV_updateCharaterTexture(...)` |
| setPosture | setPosture | `obj:setPosture(...)` |

## Armour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| cutResistance | cutResistance | number | RW | `obj.cutResistance = <value>` |
| bluntResistance | bluntResistance | number | RW | `obj.bluntResistance = <value>` |
| pierceResistance | pierceResistance | number | RW | `obj.pierceResistance = <value>` |
| minCutResistance | minCutResistance | number | RW | `obj.minCutResistance = <value>` |
| cutToStun | cutToStun | number | RW | `obj.cutToStun = <value>` |
| materialType | (lua_Integer | integer | RW | `obj.materialType = <value>` |
| armourClassEnum | (lua_Integer | integer | RW | `obj.armourClassEnum = <value>` |
| stigma | (lua_Integer | integer | RW | `obj.stigma = <value>` |
| athleticsMult | athleticsMult | number | RW | `obj.athleticsMult = <value>` |
| combatSkillBonusAttk | combatSkillBonusAttk | integer | RW | `obj.combatSkillBonusAttk = <value>` |
| combatSkillBonusDef | combatSkillBonusDef | integer | RW | `obj.combatSkillBonusDef = <value>` |
| perceptionBonus | perceptionBonus | integer | RW | `obj.perceptionBonus = <value>` |
| combatSpeedMult | combatSpeedMult | number | RW | `obj.combatSpeedMult = <value>` |
| stealthMult | stealthMult | number | RW | `obj.stealthMult = <value>` |
| assassinMult | assassinMult | number | RW | `obj.assassinMult = <value>` |
| dexterityMult | dexterityMult | number | RW | `obj.dexterityMult = <value>` |
| damageMult | damageMult | number | RW | `obj.damageMult = <value>` |
| dodgeMult | dodgeMult | number | RW | `obj.dodgeMult = <value>` |
| unarmedBonus | unarmedBonus | integer | RW | `obj.unarmedBonus = <value>` |
| fistInjuryMult | fistInjuryMult | number | RW | `obj.fistInjuryMult = <value>` |
| weatherProtectionAmount | weatherProtectionAmount | number | RW | `obj.weatherProtectionAmount = <value>` |
| rangedSkillMult | rangedSkillMult | number | RW | `obj.rangedSkillMult = <value>` |
| weatherProtections | weatherProtections | std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > > | R | `obj.weatherProtections` |
| bodypartCoverage | bodypartCoverage | ogre_unordered_map<GameData*, float>::type | R | `obj.bodypartCoverage` |
| craftTime | craftTime | number | RW | `obj.craftTime = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getClassType | getClassType | `obj:getClassType(...)` |
| _NV_getClassType | _NV_getClassType | `obj:_NV_getClassType(...)` |
| isArmour | isArmour | `obj:isArmour(...)` |
| _NV_isArmour | _NV_isArmour | `obj:_NV_isArmour(...)` |
| getItemWeight | getItemWeight | `obj:getItemWeight(...)` |
| _NV_getItemWeight | _NV_getItemWeight | `obj:_NV_getItemWeight(...)` |
| getValueSingle | getValueSingle | `obj:getValueSingle(...)` |
| _NV_getValueSingle | _NV_getValueSingle | `obj:_NV_getValueSingle(...)` |
| hasArmourCoverage | hasArmourCoverage | `obj:hasArmourCoverage(...)` |
| getCraftTime | getCraftTime | `obj:getCraftTime(...)` |
| _NV_getCraftTime | _NV_getCraftTime | `obj:_NV_getCraftTime(...)` |
| getWeatherProtection_simple | getWeatherProtection_simple | `obj:getWeatherProtection_simple(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| didIHitFlesh | didIHitFlesh | `obj:didIHitFlesh(...)` |
| getArmourCraftingMaterialConsumptionRate | getArmourCraftingMaterialConsumptionRate | `obj:getArmourCraftingMaterialConsumptionRate(...)` |

## AttachedArrowManager
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| ents | ents | lektor<Ogre::Entity*> | R | `obj.ents` |
| index | index | integer | RW | `obj.index = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| clearAll | clearAll | `obj:clearAll(...)` |
| updateStart | updateStart | `obj:updateStart(...)` |
| addArrow | addArrow | `obj:addArrow(...)` |
| updateEnd | updateEnd | `obj:updateEnd(...)` |

## Bounty
**Header:** `extern/KenshiLib/Include/kenshi/Bounty.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| amount | amount | integer | RW | `obj.amount = <value>` |
| crimes | crimes | integer | RW | `obj.crimes = <value>` |
| bountyHasBeenClaimedOnce | bountyHasBeenClaimedOnce | boolean | RW | `obj.bountyHasBeenClaimedOnce = <value>` |
| bountyAssignmentStartedTime | bountyAssignmentStartedTime | TimeOfDay | R | `obj.bountyAssignmentStartedTime` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| addCrime | addCrime | `obj:addCrime(...)` |
| hasCrime | hasCrime | `obj:hasCrime(...)` |

## BountyManager
**Header:** `extern/KenshiLib/Include/kenshi/BountyManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| bounties | bounties | unknown | R | `obj.bounties` |
| me | me | Character | R | `obj.me` |
| _hasAccessPass | _hasAccessPass | Faction | R | `obj._hasAccessPass` |
| accessPassExpirationTime | accessPassExpirationTime | TimeOfDay | R | `obj.accessPassExpirationTime` |
| committingCrime | (int | integer | R | `obj.committingCrime` |
| crimeAgainstFaction | crimeAgainstFaction | Faction | R | `obj.crimeAgainstFaction` |
| usingTrainingEquipmentOf | usingTrainingEquipmentOf | Faction | R | `obj.usingTrainingEquipmentOf` |
| crimeAgainst | crimeAgainst | hand | R | `obj.crimeAgainst` |
| crimeExpiry | crimeExpiry | number | RW | `obj.crimeExpiry = <value>` |
| prisonSentenceBeganTime | prisonSentenceBeganTime | TimeOfDay | R | `obj.prisonSentenceBeganTime` |
| prisonSentenceToServe | prisonSentenceToServe | number | RW | `obj.prisonSentenceToServe = <value>` |
| _hadABountyAssignedForCurrentCrime | _hadABountyAssignedForCurrentCrime | boolean | RW | `obj._hadABountyAssignedForCurrentCrime = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _getHighestBountyFaction | _getHighestBountyFaction | `obj:_getHighestBountyFaction(...)` |
| getBountyRecognitionThreshold | getBountyRecognitionThreshold | `obj:getBountyRecognitionThreshold(...)` |
| getTotalBounty | getTotalBounty | `obj:getTotalBounty(...)` |
| update | update | `obj:update(...)` |
| getBountyExpiryStringForGUI | getBountyExpiryStringForGUI | `obj:getBountyExpiryStringForGUI(...)` |
| notifyPossibleCrimeWitnessed | notifyPossibleCrimeWitnessed | `obj:notifyPossibleCrimeWitnessed(...)` |
| isCommittingCrime | isCommittingCrime | `obj:isCommittingCrime(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| _getBountyFaction | _getBountyFaction | `obj:_getBountyFaction(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| getPercievedBounty | getPercievedBounty | `obj:getPercievedBounty(...)` |
| getActualBounty | getActualBounty | `obj:getActualBounty(...)` |
| notifyPlayerClaimBounty | notifyPlayerClaimBounty | `obj:notifyPlayerClaimBounty(...)` |
| bountyAlreadyBeenClaimedByPlayer | bountyAlreadyBeenClaimedByPlayer | `obj:bountyAlreadyBeenClaimedByPlayer(...)` |
| assignBountyForCrimes | assignBountyForCrimes | `obj:assignBountyForCrimes(...)` |
| unfairAddToBounty | unfairAddToBounty | `obj:unfairAddToBounty(...)` |
| clearBounty | clearBounty | `obj:clearBounty(...)` |
| load | load | `obj:load(...)` |
| save | save | `obj:save(...)` |
| setCrime | setCrime | `obj:setCrime(...)` |
| notifyCrimeWitnessed | notifyCrimeWitnessed | `obj:notifyCrimeWitnessed(...)` |
| notifyStartPrisonSentence | notifyStartPrisonSentence | `obj:notifyStartPrisonSentence(...)` |
| hasAccessPass | hasAccessPass | `obj:hasAccessPass(...)` |
| giveAccessPass | giveAccessPass | `obj:giveAccessPass(...)` |
| crimeToStr | crimeToStr | `obj:crimeToStr(...)` |
| getBountyForCrime | getBountyForCrime | `obj:getBountyForCrime(...)` |
| getPrisonSentenceInHours | getPrisonSentenceInHours | `obj:getPrisonSentenceInHours(...)` |
| getBountyExpirationTime | getBountyExpirationTime | `obj:getBountyExpirationTime(...)` |

## BuildingSwaps
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| toReplace | toReplace | ogre_unordered_set<GameData*>::type | R | `obj.toReplace` |
| replaceWith | replaceWith | FitnessSelector<GameData*> | R | `obj.replaceWith` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## CameraClass
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isRotating | isRotating | boolean | RW | `obj.isRotating = <value>` |
| lastMousePos | lastMousePos | tagPOINT | R | `obj.lastMousePos` |
| rotationMarker | rotationMarker | Ogre::Entity* | R | `obj.rotationMarker` |
| yaw | yaw | number | RW | `obj.yaw = <value>` |
| pitch | pitch | number | RW | `obj.pitch = <value>` |
| initialised | initialised | boolean | RW | `obj.initialised = <value>` |
| terrainLoaded | terrainLoaded | boolean | RW | `obj.terrainLoaded = <value>` |
| objectCurrentlyFollowing | objectCurrentlyFollowing | hand | RW | `obj.objectCurrentlyFollowing = <value>` |
| objectCurrentlyFollowingOffset | objectCurrentlyFollowingOffset | Vector3 | RW | `obj.objectCurrentlyFollowingOffset = <value>` |
| center | center | Ogre::SceneNode* | R | `obj.center` |
| altitude | altitude | number | RW | `obj.altitude = <value>` |
| camera | camera | Ogre::Camera* | R | `obj.camera` |
| node | node | Ogre::SceneNode* | R | `obj.node` |
| currentMusic | currentMusic | integer | RW | `obj.currentMusic = <value>` |
| inBuilding | inBuilding | hand | RW | `obj.inBuilding = <value>` |
| timeInGame | timeInGame | number | RW | `obj.timeInGame = <value>` |
| targetPositionY | targetPositionY | number | RW | `obj.targetPositionY = <value>` |
| speedY | speedY | number | RW | `obj.speedY = <value>` |
| centerBuilding | centerBuilding | Building | R | `obj.centerBuilding` |
| centerBuildingY | centerBuildingY | number | RW | `obj.centerBuildingY = <value>` |
| currentCollisionGroup | currentCollisionGroup | integer | RW | `obj.currentCollisionGroup = <value>` |
| currentFloor | currentFloor | integer | RW | `obj.currentFloor = <value>` |
| freeCameraMode | freeCameraMode | boolean | RW | `obj.freeCameraMode = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| reset | reset | `obj:reset(...)` |
| update | update | `obj:update(...)` |
| updateOptionSettings | updateOptionSettings | `obj:updateOptionSettings(...)` |
| teleport | teleport | `obj:teleport(...)` |
| stopFollowing | stopFollowing | `obj:stopFollowing(...)` |
| manuallySetOrientationAndZoom | manuallySetOrientationAndZoom | `obj:manuallySetOrientationAndZoom(...)` |
| getFacingDirection | getFacingDirection | `obj:getFacingDirection(...)` |
| getCenter | getCenter | `obj:getCenter(...)` |
| getCameraPos | getCameraPos | `obj:getCameraPos(...)` |
| isInitialised | isInitialised | `obj:isInitialised(...)` |
| isFreeCameraMode | isFreeCameraMode | `obj:isFreeCameraMode(...)` |
| setFreeCameraMode | setFreeCameraMode | `obj:setFreeCameraMode(...)` |
| updateFreeCamera | updateFreeCamera | `obj:updateFreeCamera(...)` |
| move | move | `obj:move(...)` |
| zoom | zoom | `obj:zoom(...)` |
| toGround | toGround | `obj:toGround(...)` |
| setZoomDist | setZoomDist | `obj:setZoomDist(...)` |
| rotate | rotate | `obj:rotate(...)` |
| rotationUpdate | rotationUpdate | `obj:rotationUpdate(...)` |
| updateAudio | updateAudio | `obj:updateAudio(...)` |

## CampaignTriggerData
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| what | what | GameData | R | `obj.what` |
| minTime | minTime | integer | RW | `obj.minTime = <value>` |
| maxTime | maxTime | integer | RW | `obj.maxTime = <value>` |
| chance | chance | number | RW | `obj.chance = <value>` |

## CharBody
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| combatClass | combatClass | CombatClass* | R | `obj.combatClass` |
| animation | animation | AnimationClass* | R | `obj.animation` |
| character | character | Character | R | `obj.character` |
| stats | stats | CharStats | R | `obj.stats` |
| target | target | hand | RW | `obj.target = <value>` |
| gotItem | gotItem | boolean | RW | `obj.gotItem = <value>` |
| crouched | crouched | boolean | RW | `obj.crouched = <value>` |
| jogMode | jogMode | boolean | RW | `obj.jogMode = <value>` |
| arbitraryCatchupDist | arbitraryCatchupDist | number | RW | `obj.arbitraryCatchupDist = <value>` |
| ai | ai | AI* | R | `obj.ai` |
| movement | movement | CharMovement* | R | `obj.movement` |
| frameTIME | frameTIME | number | RW | `obj.frameTIME = <value>` |
| currentAction | currentAction | Tasker* | R | `obj.currentAction` |
| amIdle | amIdle | boolean | RW | `obj.amIdle = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| notifyBodyTaskComplete | notifyBodyTaskComplete | `obj:notifyBodyTaskComplete(...)` |
| notifyTaskComplete | notifyTaskComplete | `obj:notifyTaskComplete(...)` |
| _NV_notifyTaskComplete | _NV_notifyTaskComplete | `obj:_NV_notifyTaskComplete(...)` |
| notifyTaskImpossible | notifyTaskImpossible | `obj:notifyTaskImpossible(...)` |
| _NV_notifyTaskImpossible | _NV_notifyTaskImpossible | `obj:_NV_notifyTaskImpossible(...)` |
| isCrouched | isCrouched | `obj:isCrouched(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| _NV_getPosition | _NV_getPosition | `obj:_NV_getPosition(...)` |
| getName | getName | `obj:getName(...)` |
| isCharacter | isCharacter | `obj:isCharacter(...)` |
| _NV_isCharacter | _NV_isCharacter | `obj:_NV_isCharacter(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| _NV_getCharacter | _NV_getCharacter | `obj:_NV_getCharacter(...)` |
| getUpFromRagdoll | getUpFromRagdoll | `obj:getUpFromRagdoll(...)` |
| getPlatoon | getPlatoon | `obj:getPlatoon(...)` |
| _NV_getPlatoon | _NV_getPlatoon | `obj:_NV_getPlatoon(...)` |
| endAction | endAction | `obj:endAction(...)` |
| isIdle | isIdle | `obj:isIdle(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| _endAction | _endAction | `obj:_endAction(...)` |
| _NV__endAction | _NV__endAction | `obj:_NV__endAction(...)` |
| getCurrentAction | CharBody_getCurrentAction | `obj:getCurrentAction(...)` |
| getCurrentActionOrMessage | CharBody_getCurrentActionOrMessage | `obj:getCurrentActionOrMessage(...)` |
| getHandle | CharBody_getHandle | `obj:getHandle(...)` |
| getCurrentSubject | CharBody_getCurrentSubject | `obj:getCurrentSubject(...)` |

## CharMovement
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| flockingVector | flockingVector | Vector3 | RW | `obj.flockingVector = <value>` |
| combatMover | combatMover | CombatMovementController | R | `obj.combatMover` |
| combatMover2 | combatMover2 | FormationMover | R | `obj.combatMover2` |
| flockingTools | flockingTools | FlockingTools | R | `obj.flockingTools` |
| formation | formation | Formation* | R | `obj.formation` |
| enemyFormation | enemyFormation | Formation* | R | `obj.enemyFormation` |
| havokCharacter | havokCharacter | HavokCharacter* | R | `obj.havokCharacter` |
| tracer | tracer | ConstantTracerT* | R | `obj.tracer` |
| dontEverRecreateMe | dontEverRecreateMe | boolean | RW | `obj.dontEverRecreateMe = <value>` |
| floorGroup | floorGroup | integer | RW | `obj.floorGroup = <value>` |
| building | building | hand | RW | `obj.building = <value>` |
| initCheck | initCheck | boolean | RW | `obj.initCheck = <value>` |
| _combatMoveSpeedMult | _combatMoveSpeedMult | number | RW | `obj._combatMoveSpeedMult = <value>` |
| destinationLoaded | destinationLoaded | boolean | RW | `obj.destinationLoaded = <value>` |
| footprintRadius | footprintRadius | number | RW | `obj.footprintRadius = <value>` |
| edgeTarget | edgeTarget | integer | RW | `obj.edgeTarget = <value>` |
| _lastOffMeshCheck | _lastOffMeshCheck | number | RW | `obj._lastOffMeshCheck = <value>` |
| movingToEdge | movingToEdge | boolean | RW | `obj.movingToEdge = <value>` |
| lastStepTime | lastStepTime | number | RW | `obj.lastStepTime = <value>` |
| movementMode | movementMode | MovementMode | R | `obj.movementMode` |
| animationOverride | animationOverride | boolean | RW | `obj.animationOverride = <value>` |
| trackingAnimRelocationVector | trackingAnimRelocationVector | Vector3 | RW | `obj.trackingAnimRelocationVector = <value>` |
| desiredMotion | desiredMotion | Vector3 | RW | `obj.desiredMotion = <value>` |
| moveLimit | moveLimit | number | RW | `obj.moveLimit = <value>` |
| animation | animation | AnimationClass* | R | `obj.animation` |
| character | character | Character | R | `obj.character` |
| clickHull | clickHull | PhysicsHullT* | R | `obj.clickHull` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| _setPositionAndTeleport | _setPositionAndTeleport | `obj:_setPositionAndTeleport(...)` |
| _NV__setPositionAndTeleport | _NV__setPositionAndTeleport | `obj:_NV__setPositionAndTeleport(...)` |
| _setPositionDirectionAndTeleport | _setPositionDirectionAndTeleport | `obj:_setPositionDirectionAndTeleport(...)` |
| _NV__setPositionDirectionAndTeleport | _NV__setPositionDirectionAndTeleport | `obj:_NV__setPositionDirectionAndTeleport(...)` |
| _setPositionSimple | _setPositionSimple | `obj:_setPositionSimple(...)` |
| _NV__setPositionSimple | _NV__setPositionSimple | `obj:_NV__setPositionSimple(...)` |
| isRunning | isRunning | `obj:isRunning(...)` |
| isRunningAway | isRunningAway | `obj:isRunningAway(...)` |
| trackAnimationMovement | trackAnimationMovement | `obj:trackAnimationMovement(...)` |
| handleChanged | handleChanged | `obj:handleChanged(...)` |
| _NV_handleChanged | _NV_handleChanged | `obj:_NV_handleChanged(...)` |
| getRadius | getRadius | `obj:getRadius(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| pausedUpdate | pausedUpdate | `obj:pausedUpdate(...)` |
| twoFrameUpdate | twoFrameUpdate | `obj:twoFrameUpdate(...)` |
| postAnimationUpdate | postAnimationUpdate | `obj:postAnimationUpdate(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| predictNextPosition | predictNextPosition | `obj:predictNextPosition(...)` |
| getMaximumPossibleMovement | getMaximumPossibleMovement | `obj:getMaximumPossibleMovement(...)` |
| faceDirection | faceDirection | `obj:faceDirection(...)` |
| _NV_faceDirection | _NV_faceDirection | `obj:_NV_faceDirection(...)` |
| lookatPosition | lookatPosition | `obj:lookatPosition(...)` |
| _NV_lookatPosition | _NV_lookatPosition | `obj:_NV_lookatPosition(...)` |
| pathOk | pathOk | `obj:pathOk(...)` |
| _NV_pathOk | _NV_pathOk | `obj:_NV_pathOk(...)` |
| pathFailed | pathFailed | `obj:pathFailed(...)` |
| _NV_pathFailed | _NV_pathFailed | `obj:_NV_pathFailed(...)` |
| isDestinationReached | isDestinationReached | `obj:isDestinationReached(...)` |
| _NV_isDestinationReached | _NV_isDestinationReached | `obj:_NV_isDestinationReached(...)` |
| isIdle | isIdle | `obj:isIdle(...)` |
| _NV_isIdle | _NV_isIdle | `obj:_NV_isIdle(...)` |
| playerMoveOrderWhileInCombatMode | playerMoveOrderWhileInCombatMode | `obj:playerMoveOrderWhileInCombatMode(...)` |
| _NV_playerMoveOrderWhileInCombatMode | _NV_playerMoveOrderWhileInCombatMode | `obj:_NV_playerMoveOrderWhileInCombatMode(...)` |
| halt | halt | `obj:halt(...)` |
| _NV_halt | _NV_halt | `obj:_NV_halt(...)` |
| invalidatePath | invalidatePath | `obj:invalidatePath(...)` |
| movedBy | movedBy | `obj:movedBy(...)` |
| isCombatMovementBlockedByCharacters | isCombatMovementBlockedByCharacters | `obj:isCombatMovementBlockedByCharacters(...)` |
| destroy | destroy | `obj:destroy(...)` |
| restore | restore | `obj:restore(...)` |
| refreshClickHull | refreshClickHull | `obj:refreshClickHull(...)` |
| teleportCollisionHull | teleportCollisionHull | `obj:teleportCollisionHull(...)` |
| getCurrentFloor | getCurrentFloor | `obj:getCurrentFloor(...)` |
| isIndoorsHideMeCheck | isIndoorsHideMeCheck | `obj:isIndoorsHideMeCheck(...)` |
| isIndoors | isIndoors | `obj:isIndoors(...)` |
| manualMovement | manualMovement | `obj:manualMovement(...)` |
| _NV_manualMovement | _NV_manualMovement | `obj:_NV_manualMovement(...)` |
| isInsideBuildingLoadedInterior | isInsideBuildingLoadedInterior | `obj:isInsideBuildingLoadedInterior(...)` |
| hasClickHull | hasClickHull | `obj:hasClickHull(...)` |
| isTrackingAnimationMode | isTrackingAnimationMode | `obj:isTrackingAnimationMode(...)` |
| isWaypointMoveMode | isWaypointMoveMode | `obj:isWaypointMoveMode(...)` |
| setDirectMovement | setDirectMovement | `obj:setDirectMovement(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| toGround | toGround | `obj:toGround(...)` |
| updateGroundMaterial | updateGroundMaterial | `obj:updateGroundMaterial(...)` |
| getCombatMoveSpeedMult | getCombatMoveSpeedMult | `obj:getCombatMoveSpeedMult(...)` |
| getHandle | CharMovement_getHandle | `obj:getHandle(...)` |
| _NV_getHandle | CharMovement__NV_getHandle | `obj:_NV_getHandle(...)` |

## CharStats
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| medical | medical | MedicalSystem | R | `obj.medical` |
| me | me | Character | R | `obj.me` |
| athleticsMultiplier | athleticsMultiplier | number | RW | `obj.athleticsMultiplier = <value>` |
| combatSpeedMultiplier | combatSpeedMultiplier | number | RW | `obj.combatSpeedMultiplier = <value>` |
| _skillBonusAttack | _skillBonusAttack | integer | RW | `obj._skillBonusAttack = <value>` |
| _skillBonusDefence | _skillBonusDefence | integer | RW | `obj._skillBonusDefence = <value>` |
| skillBonusIndoors | skillBonusIndoors | integer | RW | `obj.skillBonusIndoors = <value>` |
| skillBonusUnarmed | skillBonusUnarmed | integer | RW | `obj.skillBonusUnarmed = <value>` |
| skillBonusPerception | skillBonusPerception | integer | RW | `obj.skillBonusPerception = <value>` |
| ageMult | ageMult | number | RW | `obj.ageMult = <value>` |
| skillMultDodge | skillMultDodge | number | RW | `obj.skillMultDodge = <value>` |
| skillMultStealth | skillMultStealth | number | RW | `obj.skillMultStealth = <value>` |
| skillMultAssassin | skillMultAssassin | number | RW | `obj.skillMultAssassin = <value>` |
| skillMultDexterity | skillMultDexterity | number | RW | `obj.skillMultDexterity = <value>` |
| skillMultDamage | skillMultDamage | number | RW | `obj.skillMultDamage = <value>` |
| fistInjuryEquipmentMult | fistInjuryEquipmentMult | number | RW | `obj.fistInjuryEquipmentMult = <value>` |
| skillMultRanged | skillMultRanged | number | RW | `obj.skillMultRanged = <value>` |
| _weatherProtections | _weatherProtections | std::map<WeatherAffecting, float, std::less<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, float>, Ogre::GeneralAllocPolicy > > | R | `obj._weatherProtections` |
| _strength | _strength | number | RW | `obj._strength = <value>` |
| fitness | fitness | number | RW | `obj.fitness = <value>` |
| _dexterity | _dexterity | number | RW | `obj._dexterity = <value>` |
| perception | perception | number | RW | `obj.perception = <value>` |
| _toughness | _toughness | number | RW | `obj._toughness = <value>` |
| _athletics | _athletics | number | RW | `obj._athletics = <value>` |
| medic | medic | number | RW | `obj.medic = <value>` |
| massCombat | massCombat | number | RW | `obj.massCombat = <value>` |
| arrowDefence | arrowDefence | number | RW | `obj.arrowDefence = <value>` |
| stealth | stealth | number | RW | `obj.stealth = <value>` |
| swimming | swimming | number | RW | `obj.swimming = <value>` |
| thieving | thieving | number | RW | `obj.thieving = <value>` |
| lockpicking | lockpicking | number | RW | `obj.lockpicking = <value>` |
| bluff | bluff | number | RW | `obj.bluff = <value>` |
| assassin | assassin | number | RW | `obj.assassin = <value>` |
| survival | survival | number | RW | `obj.survival = <value>` |
| tracking | tracking | number | RW | `obj.tracking = <value>` |
| climbing | climbing | number | RW | `obj.climbing = <value>` |
| doctor | doctor | number | RW | `obj.doctor = <value>` |
| engineer | engineer | number | RW | `obj.engineer = <value>` |
| weaponSmith | weaponSmith | number | RW | `obj.weaponSmith = <value>` |
| armourSmith | armourSmith | number | RW | `obj.armourSmith = <value>` |
| bowSmith | bowSmith | number | RW | `obj.bowSmith = <value>` |
| robotics | robotics | number | RW | `obj.robotics = <value>` |
| science | science | number | RW | `obj.science = <value>` |
| labouring | labouring | number | RW | `obj.labouring = <value>` |
| farming | farming | number | RW | `obj.farming = <value>` |
| cooking | cooking | number | RW | `obj.cooking = <value>` |
| dodging | dodging | number | RW | `obj.dodging = <value>` |
| friendlyFire | friendlyFire | number | RW | `obj.friendlyFire = <value>` |
| katanas | katanas | number | RW | `obj.katanas = <value>` |
| sabres | sabres | number | RW | `obj.sabres = <value>` |
| hackers | hackers | number | RW | `obj.hackers = <value>` |
| blunt | blunt | number | RW | `obj.blunt = <value>` |
| heavyWeapons | heavyWeapons | number | RW | `obj.heavyWeapons = <value>` |
| unarmed | unarmed | number | RW | `obj.unarmed = <value>` |
| bows | bows | number | RW | `obj.bows = <value>` |
| turrets | turrets | number | RW | `obj.turrets = <value>` |
| polearms | polearms | number | RW | `obj.polearms = <value>` |
| currentItemMaximumJuryRig | currentItemMaximumJuryRig | number | RW | `obj.currentItemMaximumJuryRig = <value>` |
| __meleeAttack | __meleeAttack | number | RW | `obj.__meleeAttack = <value>` |
| _meleeDefence | _meleeDefence | number | RW | `obj._meleeDefence = <value>` |
| _defensiveMode | _defensiveMode | boolean | RW | `obj._defensiveMode = <value>` |
| rangedMode | rangedMode | boolean | RW | `obj.rangedMode = <value>` |
| tauntMode | tauntMode | boolean | RW | `obj.tauntMode = <value>` |
| _holdPositionMode | _holdPositionMode | boolean | RW | `obj._holdPositionMode = <value>` |
| passiveCombatMode | passiveCombatMode | boolean | RW | `obj.passiveCombatMode = <value>` |
| holdLocation | holdLocation | Vector3 | RW | `obj.holdLocation = <value>` |
| warriorSpirit | warriorSpirit | number | RW | `obj.warriorSpirit = <value>` |
| derivedSpirit | derivedSpirit | number | RW | `obj.derivedSpirit = <value>` |
| aggression | aggression | number | RW | `obj.aggression = <value>` |
| goodness | goodness | number | RW | `obj.goodness = <value>` |
| evilness | evilness | number | RW | `obj.evilness = <value>` |
| longestReachingAttack | longestReachingAttack | number | RW | `obj.longestReachingAttack = <value>` |
| STUBBOURNESS | STUBBOURNESS | number | RW | `obj.STUBBOURNESS = <value>` |
| PROFESSIONALNESS | PROFESSIONALNESS | number | RW | `obj.PROFESSIONALNESS = <value>` |
| HOLDING_POSITION | HOLDING_POSITION | number | RW | `obj.HOLDING_POSITION = <value>` |
| IMMEDIACY | IMMEDIACY | number | RW | `obj.IMMEDIACY = <value>` |
| IMMEDIACY_MAX_RANGE | IMMEDIACY_MAX_RANGE | number | RW | `obj.IMMEDIACY_MAX_RANGE = <value>` |
| MANLINESS | MANLINESS | number | RW | `obj.MANLINESS = <value>` |
| MURDEROUS | MURDEROUS | number | RW | `obj.MURDEROUS = <value>` |
| _stealthXPMultForGUI | _stealthXPMultForGUI | number | RW | `obj._stealthXPMultForGUI = <value>` |
| stealthXPTooManyCooksPenalty | stealthXPTooManyCooksPenalty | number | RW | `obj.stealthXPTooManyCooksPenalty = <value>` |
| currentOperatingMachineHungerRate | currentOperatingMachineHungerRate | number | RW | `obj.currentOperatingMachineHungerRate = <value>` |
| moveSpeed | moveSpeed | number | RW | `obj.moveSpeed = <value>` |
| weaponWeightSpeedMult | weaponWeightSpeedMult | number | RW | `obj.weaponWeightSpeedMult = <value>` |
| weaponWeightXPMult | weaponWeightXPMult | number | RW | `obj.weaponWeightXPMult = <value>` |
| attackSpeed | attackSpeed | number | RW | `obj.attackSpeed = <value>` |
| blockSpeed | blockSpeed | number | RW | `obj.blockSpeed = <value>` |
| encumbranceMult | encumbranceMult | number | RW | `obj.encumbranceMult = <value>` |
| xp | xp | number | RW | `obj.xp = <value>` |
| freeAttributePoints | freeAttributePoints | integer | RW | `obj.freeAttributePoints = <value>` |
| cutDamageMult | cutDamageMult | number | RW | `obj.cutDamageMult = <value>` |
| bluntDamageMult | bluntDamageMult | number | RW | `obj.bluntDamageMult = <value>` |
| bleedDamageMult | bleedDamageMult | number | RW | `obj.bleedDamageMult = <value>` |
| pierceDamageMult | pierceDamageMult | number | RW | `obj.pierceDamageMult = <value>` |
| cutDamageMin | cutDamageMin | number | RW | `obj.cutDamageMin = <value>` |
| bluntDamageMin | bluntDamageMin | number | RW | `obj.bluntDamageMin = <value>` |
| bonusRobots | bonusRobots | number | RW | `obj.bonusRobots = <value>` |
| bonusHumans | bonusHumans | number | RW | `obj.bonusHumans = <value>` |
| bonusAnimals | bonusAnimals | number | RW | `obj.bonusAnimals = <value>` |
| bonusArmourPenetration | bonusArmourPenetration | number | RW | `obj.bonusArmourPenetration = <value>` |
| bonusRaces | bonusRaces | std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, float>, Ogre::GeneralAllocPolicy > > | R | `obj.bonusRaces` |
| currentWeaponType | (lua_Integer | integer | RW | `obj.currentWeaponType = <value>` |
| pCurrentWeaponSkill | pCurrentWeaponSkill | number | RW | `obj.pCurrentWeaponSkill = <value>` |
| currentWeaponLength | currentWeaponLength | number | RW | `obj.currentWeaponLength = <value>` |
| weapon | weapon | hand | RW | `obj.weapon = <value>` |
| weaponWeight | weaponWeight | number | RW | `obj.weaponWeight = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getWeatherProtection | getWeatherProtection | `obj:getWeatherProtection(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| unarmedEncumbrancePenalty | unarmedEncumbrancePenalty | `obj:unarmedEncumbrancePenalty(...)` |
| skillBonusUnarmed_forGUI | skillBonusUnarmed_forGUI | `obj:skillBonusUnarmed_forGUI(...)` |
| skillBonusAttack_melee | skillBonusAttack_melee | `obj:skillBonusAttack_melee(...)` |
| skillBonusAttack_unarmed | skillBonusAttack_unarmed | `obj:skillBonusAttack_unarmed(...)` |
| skillBonusDefence | skillBonusDefence | `obj:skillBonusDefence(...)` |
| _randomiseStats | _randomiseStats | `obj:_randomiseStats(...)` |
| getGUIStatsDisplayMode | getGUIStatsDisplayMode | `obj:getGUIStatsDisplayMode(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| calculateStumbleThresholdDamageAmount | calculateStumbleThresholdDamageAmount | `obj:calculateStumbleThresholdDamageAmount(...)` |
| setEquipmentStatBonuses | setEquipmentStatBonuses | `obj:setEquipmentStatBonuses(...)` |
| getOverallSkillLevel_0_100 | getOverallSkillLevel_0_100 | `obj:getOverallSkillLevel_0_100(...)` |
| getStat | getStat | `obj:getStat(...)` |
| getStatMultiplier | getStatMultiplier | `obj:getStatMultiplier(...)` |
| getStatMultiplierForGUI | getStatMultiplierForGUI | `obj:getStatMultiplierForGUI(...)` |
| getStatPenaltiesTotalForGUI | getStatPenaltiesTotalForGUI | `obj:getStatPenaltiesTotalForGUI(...)` |
| xpStat_timeBased | xpStat_timeBased | `obj:xpStat_timeBased(...)` |
| xpStat_eventBased | xpStat_eventBased | `obj:xpStat_eventBased(...)` |
| xpDodgeEvent | xpDodgeEvent | `obj:xpDodgeEvent(...)` |
| strengthActual | strengthActual | `obj:strengthActual(...)` |
| strengthBase | strengthBase | `obj:strengthBase(...)` |
| _NV_strengthBase | _NV_strengthBase | `obj:_NV_strengthBase(...)` |
| dexterityBase | dexterityBase | `obj:dexterityBase(...)` |
| dexterityActual | dexterityActual | `obj:dexterityActual(...)` |
| toughness | toughness | `obj:toughness(...)` |
| getStrength | getStrength | `obj:getStrength(...)` |
| getStrengthRaw | getStrengthBase | `obj:getStrengthRaw(...)` |
| getDexterity | getDexterity | `obj:getDexterity(...)` |
| getDexterityRaw | getDexterityBase | `obj:getDexterityRaw(...)` |
| getToughness | getToughness | `obj:getToughness(...)` |
| getPerception | getPerception | `obj:getPerception(...)` |
| getAthletics | getAthletics | `obj:getAthletics(...)` |
| getThieving | getThieving | `obj:getThieving(...)` |
| getToughnessMult | getToughnessMult | `obj:getToughnessMult(...)` |
| getRangedFriendlyFireAvoidanceChance | getRangedFriendlyFireAvoidanceChance | `obj:getRangedFriendlyFireAvoidanceChance(...)` |
| getRangedAccuracyMult | getRangedAccuracyMult | `obj:getRangedAccuracyMult(...)` |
| getReloadSkill | getReloadSkill | `obj:getReloadSkill(...)` |
| animalRecruitReduceStats | animalRecruitReduceStats | `obj:animalRecruitReduceStats(...)` |
| getMeleeDefence | getMeleeDefence | `obj:getMeleeDefence(...)` |
| getDodge | getDodge | `obj:getDodge(...)` |
| getDodgePenalty_encumbrance | getDodgePenalty_encumbrance | `obj:getDodgePenalty_encumbrance(...)` |
| getDodgePenalty_injuries | getDodgePenalty_injuries | `obj:getDodgePenalty_injuries(...)` |
| getDodgePenalty_gear | getDodgePenalty_gear | `obj:getDodgePenalty_gear(...)` |
| getMeleeDefence_melee | getMeleeDefence_melee | `obj:getMeleeDefence_melee(...)` |
| getMeleeAttack | getMeleeAttack | `obj:getMeleeAttack(...)` |
| getMeleeAttack_unarmed | getMeleeAttack_unarmed | `obj:getMeleeAttack_unarmed(...)` |
| getMeleeAttack_melee | getMeleeAttack_melee | `obj:getMeleeAttack_melee(...)` |
| _getMeleeAttackBase | _getMeleeAttackBase | `obj:_getMeleeAttackBase(...)` |
| isDefensiveMode | isDefensiveMode | `obj:isDefensiveMode(...)` |
| holdPositionMode | holdPositionMode | `obj:holdPositionMode(...)` |
| setHoldLocation | setHoldLocation | `obj:setHoldLocation(...)` |
| clearHoldLocation | clearHoldLocation | `obj:clearHoldLocation(...)` |
| calculateStumbleBlockTimer | calculateStumbleBlockTimer | `obj:calculateStumbleBlockTimer(...)` |
| calculateTechniqueInegrityCheckTimer | calculateTechniqueInegrityCheckTimer | `obj:calculateTechniqueInegrityCheckTimer(...)` |
| calculateToughnessDamageResistanceMult | calculateToughnessDamageResistanceMult | `obj:calculateToughnessDamageResistanceMult(...)` |
| calculateToughnessWoundDegenerationRate | calculateToughnessWoundDegenerationRate | `obj:calculateToughnessWoundDegenerationRate(...)` |
| getAttackChance | getAttackChance | `obj:getAttackChance(...)` |
| getAttackCuttingDamage | getAttackCuttingDamage | `obj:getAttackCuttingDamage(...)` |
| getAttackBluntPower | getAttackBluntPower | `obj:getAttackBluntPower(...)` |
| getAttackBleedDamageMult | getAttackBleedDamageMult | `obj:getAttackBleedDamageMult(...)` |
| getAttackPierceDamage | getAttackPierceDamage | `obj:getAttackPierceDamage(...)` |
| getEquippedWeaponSkill | getEquippedWeaponSkill | `obj:getEquippedWeaponSkill(...)` |
| _NV_getEquippedWeaponSkill | _NV_getEquippedWeaponSkill | `obj:_NV_getEquippedWeaponSkill(...)` |
| getSkillDifferenceRatio | getSkillDifferenceRatio | `obj:getSkillDifferenceRatio(...)` |
| calculateDeadTime | calculateDeadTime | `obj:calculateDeadTime(...)` |
| xpToughness_RagdollEvent | xpToughness_RagdollEvent | `obj:xpToughness_RagdollEvent(...)` |
| xpToughness_GetUpEvent | xpToughness_GetUpEvent | `obj:xpToughness_GetUpEvent(...)` |
| xpToughness_PunchSomething | xpToughness_PunchSomething | `obj:xpToughness_PunchSomething(...)` |
| xpRunning | xpRunning | `obj:xpRunning(...)` |
| xpStealthHearCheckEvent | xpStealthHearCheckEvent | `obj:xpStealthHearCheckEvent(...)` |
| xpMassCombat | xpMassCombat | `obj:xpMassCombat(...)` |
| xpEngineering | xpEngineering | `obj:xpEngineering(...)` |
| xpLockpicking | xpLockpicking | `obj:xpLockpicking(...)` |
| xpGeneral | xpGeneral | `obj:xpGeneral(...)` |
| calculateAthleticsXPMult | calculateAthleticsXPMult | `obj:calculateAthleticsXPMult(...)` |
| calculateStrengthXPMultFromWalking | calculateStrengthXPMultFromWalking | `obj:calculateStrengthXPMultFromWalking(...)` |
| isUnarmed | isUnarmed | `obj:isUnarmed(...)` |
| getWeaponWeightXPBonus | getWeaponWeightXPBonus | `obj:getWeaponWeightXPBonus(...)` |
| getAttackSpeed | getAttackSpeed | `obj:getAttackSpeed(...)` |
| getBlockSpeed | getBlockSpeed | `obj:getBlockSpeed(...)` |
| getMaxRunSpeed | getMaxRunSpeed | `obj:getMaxRunSpeed(...)` |
| getCurrentWeaponLength | getCurrentWeaponLength | `obj:getCurrentWeaponLength(...)` |
| getStealthSkill01 | getStealthSkill01 | `obj:getStealthSkill01(...)` |
| getAttackSuccessChanceSkill | getAttackSuccessChanceSkill | `obj:getAttackSuccessChanceSkill(...)` |
| getEncumbranceMult | getEncumbranceMult | `obj:getEncumbranceMult(...)` |
| calculateHungerMult | calculateHungerMult | `obj:calculateHungerMult(...)` |
| calculateTheoreticalIdealMaxRunSpeed | calculateTheoreticalIdealMaxRunSpeed | `obj:calculateTheoreticalIdealMaxRunSpeed(...)` |
| calculateWeaponWeightXPMult | calculateWeaponWeightXPMult | `obj:calculateWeaponWeightXPMult(...)` |
| hasWeapon | hasWeapon | `obj:hasWeapon(...)` |
| calculateMaxStealthSpeed | calculateMaxStealthSpeed | `obj:calculateMaxStealthSpeed(...)` |
| _calculateMaxSwimSpeed | _calculateMaxSwimSpeed | `obj:_calculateMaxSwimSpeed(...)` |
| calculateSwimSpeed | calculateSwimSpeed | `obj:calculateSwimSpeed(...)` |
| calculateDodgeChance | calculateDodgeChance | `obj:calculateDodgeChance(...)` |
| calculateMaxRunSpeed | calculateMaxRunSpeed | `obj:calculateMaxRunSpeed(...)` |
| _calculateEncumberanceMult | _calculateEncumberanceMult | `obj:_calculateEncumberanceMult(...)` |
| _calculateWeaponWeightSpeedMultiplier | _calculateWeaponWeightSpeedMultiplier | `obj:_calculateWeaponWeightSpeedMultiplier(...)` |
| currentWeaponHand | currentWeaponHand | `obj:currentWeaponHand(...)` |
| calculateAttackOrBlockSpeed | calculateAttackOrBlockSpeed | `obj:calculateAttackOrBlockSpeed(...)` |
| _calculateBlockChance | _calculateBlockChance | `obj:_calculateBlockChance(...)` |
| _recalculateStats | _recalculateStats | `obj:_recalculateStats(...)` |
| _NV__recalculateStats | _NV__recalculateStats | `obj:_NV__recalculateStats(...)` |
| setEquippedWeaponSkill | setEquippedWeaponSkill | `obj:setEquippedWeaponSkill(...)` |
| _NV_setEquippedWeaponSkill | _NV_setEquippedWeaponSkill | `obj:_NV_setEquippedWeaponSkill(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getTotalAttackDamageFor | CharStats_getTotalAttackDamageFor | `obj:getTotalAttackDamageFor(...)` |
| serialise | serialise | `obj:serialise(...)` |
| updateStats | updateStats | `obj:updateStats(...)` |
| init | init | `obj:init(...)` |
| _NV_init | _NV_init | `obj:_NV_init(...)` |
| getGUIData | getGUIData | `obj:getGUIData(...)` |
| printStealthStats | printStealthStats | `obj:printStealthStats(...)` |
| printRunSpeedStatMax | printRunSpeedStatMax | `obj:printRunSpeedStatMax(...)` |
| getGUIDataForMainInfo | getGUIDataForMainInfo | `obj:getGUIDataForMainInfo(...)` |
| formatWholeStatStringWithBonuses | formatWholeStatStringWithBonuses | `obj:formatWholeStatStringWithBonuses(...)` |
| getStatRef | getStatRef | `obj:getStatRef(...)` |
| getStatName | getStatName | `obj:getStatName(...)` |
| getMeleeAttackRef | getMeleeAttackRef | `obj:getMeleeAttackRef(...)` |
| getMaxHealAmount | getMaxHealAmount | `obj:getMaxHealAmount(...)` |
| getBashAnimation | getBashAnimation | `obj:getBashAnimation(...)` |
| chooseAttack | chooseAttack | `obj:chooseAttack(...)` |
| chooseBlock | chooseBlock | `obj:chooseBlock(...)` |
| getPainAnim | getPainAnim | `obj:getPainAnim(...)` |
| xpMelee | xpMelee | `obj:xpMelee(...)` |
| xpFirstAid | xpFirstAid | `obj:xpFirstAid(...)` |
| xpStealth | xpStealth | `obj:xpStealth(...)` |
| setWeapon | setWeapon | `obj:setWeapon(...)` |
| _convertWeaponWeightToBluntMultiplier | _convertWeaponWeightToBluntMultiplier | `obj:_convertWeaponWeightToBluntMultiplier(...)` |
| _convertBluntMultiplierToWeaponWeight | _convertBluntMultiplierToWeaponWeight | `obj:_convertBluntMultiplierToWeaponWeight(...)` |
| setupCombatTechniques | setupCombatTechniques | `obj:setupCombatTechniques(...)` |

## Character
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| offscreenFrameTime | offscreenFrameTime | number | RW | `obj.offscreenFrameTime = <value>` |
| frameTIME | frameTIME | number | RW | `obj.frameTIME = <value>` |
| frameTIMEfour | frameTIMEfour | number | RW | `obj.frameTIMEfour = <value>` |
| frameTIME_P | frameTIME_P | number | RW | `obj.frameTIME_P = <value>` |
| bodyDecayTimer | bodyDecayTimer | number | RW | `obj.bodyDecayTimer = <value>` |
| stealthMode | stealthMode | boolean | RW | `obj.stealthMode = <value>` |
| _isOnARoof | _isOnARoof | boolean | RW | `obj._isOnARoof = <value>` |
| _lightLevel | _lightLevel | number | RW | `obj._lightLevel = <value>` |
| needsLightLevel | needsLightLevel | boolean | RW | `obj.needsLightLevel = <value>` |
| _currentProneState | (lua_Integer | integer | RW | `obj._currentProneState = <value>` |
| isVisibleUpdateMode | isVisibleUpdateMode | boolean | RW | `obj.isVisibleUpdateMode = <value>` |
| setVisibleMsg | setVisibleMsg | boolean | RW | `obj.setVisibleMsg = <value>` |
| stealthUnseen | stealthUnseen | YesNoMaybe | R | `obj.stealthUnseen` |
| playerWantsMeToGetUp | playerWantsMeToGetUp | boolean | RW | `obj.playerWantsMeToGetUp = <value>` |
| crimes | crimes | BountyManager | RW | `obj.crimes = <value>` |
| currentSkillUsing | (lua_Integer | integer | RW | `obj.currentSkillUsing = <value>` |
| stateBroadcast | stateBroadcast | StateBroadcastData* | R | `obj.stateBroadcast` |
| isVisibleAndNear | isVisibleAndNear | boolean | RW | `obj.isVisibleAndNear = <value>` |
| isOnScreen | isOnScreen | boolean | RW | `obj.isOnScreen = <value>` |
| disguiseGUIFeedbacks | (lua_Integer | integer | R | `obj.disguiseGUIFeedbacks` |
| whoSeesMeSneaking | first | hand | R | `obj.whoSeesMeSneaking` |
| stealthMarkerArrows | stealthMarkerArrows | Character::AttachedArrowManager | R | `obj.stealthMarkerArrows` |
| _isEngagedWithAPlayer | _isEngagedWithAPlayer | boolean | RW | `obj._isEngagedWithAPlayer = <value>` |
| isUsingTurret | isUsingTurret | hand | RW | `obj.isUsingTurret = <value>` |
| isCurrentlyGettingUp | isCurrentlyGettingUp | boolean | RW | `obj.isCurrentlyGettingUp = <value>` |
| isGettingEaten | isGettingEaten | integer | RW | `obj.isGettingEaten = <value>` |
| dialogue | dialogue | Dialogue | RW | `obj.dialogue = <value>` |
| currentStumblePainAnimation | currentStumblePainAnimation | string | RW | `obj.currentStumblePainAnimation = <value>` |
| _isLiterallyUnderMeleeAttackRightNowForSure | _isLiterallyUnderMeleeAttackRightNowForSure | boolean | RW | `obj._isLiterallyUnderMeleeAttackRightNowForSure = <value>` |
| _myMemory | _myMemory | CharacterMemory* | R | `obj._myMemory` |
| lastGuyWhoDefeatedMe | lastGuyWhoDefeatedMe | hand | RW | `obj.lastGuyWhoDefeatedMe = <value>` |
| myRace | myRace | RaceData | RW | `obj.myRace = <value>` |
| inventory | inventory | Inventory | RW | `obj.inventory = <value>` |
| rangedCombat | rangedCombat | RangedCombatClass* | R | `obj.rangedCombat` |
| inSomething | inSomething | UseStuffState | R | `obj.inSomething` |
| inWhat | inWhat | hand | RW | `obj.inWhat = <value>` |
| isChained | isChained | boolean | RW | `obj.isChained = <value>` |
| slaveOwner | slaveOwner | hand | RW | `obj.slaveOwner = <value>` |
| isCarryingSomething | isCarryingSomething | boolean | RW | `obj.isCarryingSomething = <value>` |
| carringObjectLeftOrRight | carringObjectLeftOrRight | string | RW | `obj.carringObjectLeftOrRight = <value>` |
| isCarryingLeftSide | isCarryingLeftSide | boolean | RW | `obj.isCarryingLeftSide = <value>` |
| carryingObject | carryingObject | hand | RW | `obj.carryingObject = <value>` |
| messages | (lua_Integer | integer | RW | `obj.messages = <value>` |
| messageSubject | messageSubject | hand | RW | `obj.messageSubject = <value>` |
| ragdollNavmeshPosition | ragdollNavmeshPosition | Vector3 | RW | `obj.ragdollNavmeshPosition = <value>` |
| _isBeingCarried | _isBeingCarried | boolean | RW | `obj._isBeingCarried = <value>` |
| lastUsedWeaponCategory | (lua_Integer | integer | RW | `obj.lastUsedWeaponCategory = <value>` |
| ragdollMessages | ragdollMessages | std::deque<Character::RagdollMsg, std::allocator<Character::RagdollMsg> > | R | `obj.ragdollMessages` |
| msgCarryMode | (lua_Integer | integer | R | `obj.msgCarryMode` |
| squadMemberID | squadMemberID | integer | RW | `obj.squadMemberID = <value>` |
| diplomacyMultiplier | diplomacyMultiplier | number | RW | `obj.diplomacyMultiplier = <value>` |
| _destinationInsideBuilding | _destinationInsideBuilding | hand | RW | `obj._destinationInsideBuilding = <value>` |
| _destinationInsideWalls | _destinationInsideWalls | integer | RW | `obj._destinationInsideWalls = <value>` |
| animation | animation | AnimationClass* | R | `obj.animation` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |
| medical | medical | MedicalSystem | RW | `obj.medical = <value>` |
| isPhysicalMode | isPhysicalMode | boolean | RW | `obj.isPhysicalMode = <value>` |
| sex | sex | string | RW | `obj.sex = <value>` |
| nameTag | nameTag | CharacterNameTag* | R | `obj.nameTag` |
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| body | body | CharBody | RW | `obj.body = <value>` |
| ai | ai | AI* | R | `obj.ai` |
| platoon | platoon | ActivePlatoon | RW | `obj.platoon = <value>` |
| portraitIndex | portraitIndex | integer | RW | `obj.portraitIndex = <value>` |
| portraitSerial | portraitSerial | integer | RW | `obj.portraitSerial = <value>` |
| audioObject | (lua_Integer | integer | RW | `obj.audioObject = <value>` |
| audioData | audioData | AkSoundPosition | R | `obj.audioData` |
| groundType | (lua_Integer | integer | RW | `obj.groundType = <value>` |
| armourType | (lua_Integer | integer | RW | `obj.armourType = <value>` |
| audioEmitter | audioEmitter | SoundEmitter* | R | `obj.audioEmitter` |
| terrainHeightPosition | terrainHeightPosition | number | RW | `obj.terrainHeightPosition = <value>` |
| inDoorsSetCooldown | inDoorsSetCooldown | integer | RW | `obj.inDoorsSetCooldown = <value>` |
| activeEffects | (lua_Integer | integer | R | `obj.activeEffects` |
| particleEffects | particleEffects | lektor<Effect*> | R | `obj.particleEffects` |
| naturalWeapon | naturalWeapon | Sword | RW | `obj.naturalWeapon = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isImmuneToOffscreenMode | isImmuneToOffscreenMode | `obj:isImmuneToOffscreenMode(...)` |
| init | init | `obj:init(...)` |
| _NV_init | _NV_init | `obj:_NV_init(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| isOnARoof | isOnARoof | `obj:isOnARoof(...)` |
| _NV_isOnARoof | _NV_isOnARoof | `obj:_NV_isOnARoof(...)` |
| isOnAWall | isOnAWall | `obj:isOnAWall(...)` |
| _NV_isOnAWall | _NV_isOnAWall | `obj:_NV_isOnAWall(...)` |
| getLightLevel | getLightLevel | `obj:getLightLevel(...)` |
| getHPMultiplier | getHPMultiplier | `obj:getHPMultiplier(...)` |
| _NV_getHPMultiplier | _NV_getHPMultiplier | `obj:_NV_getHPMultiplier(...)` |
| healCompletely | healCompletely | `obj:healCompletely(...)` |
| resetRagdollNavmeshSafePos | resetRagdollNavmeshSafePos | `obj:resetRagdollNavmeshSafePos(...)` |
| setRagdollNavmeshSafePos | setRagdollNavmeshSafePos | `obj:setRagdollNavmeshSafePos(...)` |
| getFrameTime | getFrameTime | `obj:getFrameTime(...)` |
| frameSkip | frameSkip | `obj:frameSkip(...)` |
| getCurrentNoiseRange | getCurrentNoiseRange | `obj:getCurrentNoiseRange(...)` |
| isDestroyed | isDestroyed | `obj:isDestroyed(...)` |
| _NV_isDestroyed | _NV_isDestroyed | `obj:_NV_isDestroyed(...)` |
| isLawEnforcement | isLawEnforcement | `obj:isLawEnforcement(...)` |
| canAssignBounties | canAssignBounties | `obj:canAssignBounties(...)` |
| getDataType | getDataType | `obj:getDataType(...)` |
| _NV_getDataType | _NV_getDataType | `obj:_NV_getDataType(...)` |
| isDiplomaticStatus | isDiplomaticStatus | `obj:isDiplomaticStatus(...)` |
| isLeadingAWarCampaign | isLeadingAWarCampaign | `obj:isLeadingAWarCampaign(...)` |
| wantsToTriggerCampaigns | wantsToTriggerCampaigns | `obj:wantsToTriggerCampaigns(...)` |
| isUnique | isUnique | `obj:isUnique(...)` |
| canSpeakNormally | canSpeakNormally | `obj:canSpeakNormally(...)` |
| isAnimal | isAnimal | `obj:isAnimal(...)` |
| _NV_isAnimal | _NV_isAnimal | `obj:_NV_isAnimal(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| _NV_takeMoney | _NV_takeMoney | `obj:_NV_takeMoney(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| _NV_getMoney | _NV_getMoney | `obj:_NV_getMoney(...)` |
| setSquadMemberType | setSquadMemberType | `obj:setSquadMemberType(...)` |
| dailyUpdate | dailyUpdate | `obj:dailyUpdate(...)` |
| updateOnScreenCheck | updateOnScreenCheck | `obj:updateOnScreenCheck(...)` |
| offscreenUpdate | offscreenUpdate | `obj:offscreenUpdate(...)` |
| updateTimes | updateTimes | `obj:updateTimes(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| postUpdate | postUpdate | `obj:postUpdate(...)` |
| _NV_postUpdate | _NV_postUpdate | `obj:_NV_postUpdate(...)` |
| ragdollUpdatesUT | ragdollUpdatesUT | `obj:ragdollUpdatesUT(...)` |
| fourFrameUpdate | fourFrameUpdate | `obj:fourFrameUpdate(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| pausedUpdate | pausedUpdate | `obj:pausedUpdate(...)` |
| _NV_pausedUpdate | _NV_pausedUpdate | `obj:_NV_pausedUpdate(...)` |
| updateUT | updateUT | `obj:updateUT(...)` |
| threadedUpdate | threadedUpdate | `obj:threadedUpdate(...)` |
| _NV_threadedUpdate | _NV_threadedUpdate | `obj:_NV_threadedUpdate(...)` |
| threadedUpdate4 | threadedUpdate4 | `obj:threadedUpdate4(...)` |
| _NV_threadedUpdate4 | _NV_threadedUpdate4 | `obj:_NV_threadedUpdate4(...)` |
| threadedUpdatePeriodic | threadedUpdatePeriodic | `obj:threadedUpdatePeriodic(...)` |
| _NV_threadedUpdatePeriodic | _NV_threadedUpdatePeriodic | `obj:_NV_threadedUpdatePeriodic(...)` |
| pathExists | pathExists | `obj:pathExists(...)` |
| weatherUpdate | weatherUpdate | `obj:weatherUpdate(...)` |
| _NV_weatherUpdate | _NV_weatherUpdate | `obj:_NV_weatherUpdate(...)` |
| stealthUpdate | stealthUpdate | `obj:stealthUpdate(...)` |
| getPerceptionMult | getPerceptionMult | `obj:getPerceptionMult(...)` |
| isWithThePlayer | isWithThePlayer | `obj:isWithThePlayer(...)` |
| isItSafeToGetUp | isItSafeToGetUp | `obj:isItSafeToGetUp(...)` |
| separateIntoMyOwnSquad | separateIntoMyOwnSquad | `obj:separateIntoMyOwnSquad(...)` |
| dropGearOnDeath | dropGearOnDeath | `obj:dropGearOnDeath(...)` |
| getCurrentWeatherAffectStatus | getCurrentWeatherAffectStatus | `obj:getCurrentWeatherAffectStatus(...)` |
| getCurrentWeatherAffectStrength | getCurrentWeatherAffectStrength | `obj:getCurrentWeatherAffectStrength(...)` |
| getWaterLevel | getWaterLevel | `obj:getWaterLevel(...)` |
| setTerrainHeightPosition | setTerrainHeightPosition | `obj:setTerrainHeightPosition(...)` |
| getTerrainHeightPosition | getTerrainHeightPosition | `obj:getTerrainHeightPosition(...)` |
| setDisguiseMessage | setDisguiseMessage | `obj:setDisguiseMessage(...)` |
| uniqueStateUpdate | uniqueStateUpdate | `obj:uniqueStateUpdate(...)` |
| foodUpdate | foodUpdate | `obj:foodUpdate(...)` |
| _NV_foodUpdate | _NV_foodUpdate | `obj:_NV_foodUpdate(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| _NV_getPosition | _NV_getPosition | `obj:_NV_getPosition(...)` |
| _getRawPosition | _getRawPosition | `obj:_getRawPosition(...)` |
| getRawEntityPosition | getRawEntityPosition | `obj:getRawEntityPosition(...)` |
| getMovementSpeed | getMovementSpeed | `obj:getMovementSpeed(...)` |
| _NV_getMovementSpeed | _NV_getMovementSpeed | `obj:_NV_getMovementSpeed(...)` |
| getMovementSpeedOrders | getMovementSpeedOrders | `obj:getMovementSpeedOrders(...)` |
| _NV_getMovementSpeedOrders | _NV_getMovementSpeedOrders | `obj:_NV_getMovementSpeedOrders(...)` |
| getMovementDirection | getMovementDirection | `obj:getMovementDirection(...)` |
| _NV_getMovementDirection | _NV_getMovementDirection | `obj:_NV_getMovementDirection(...)` |
| isPhysical | isPhysical | `obj:isPhysical(...)` |
| _NV_isPhysical | _NV_isPhysical | `obj:_NV_isPhysical(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| _NV_setVisible | _NV_setVisible | `obj:_NV_setVisible(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| _NV_getVisible | _NV_getVisible | `obj:_NV_getVisible(...)` |
| switchLights | switchLights | `obj:switchLights(...)` |
| isDisabled | isDisabled | `obj:isDisabled(...)` |
| _NV_isDisabled | _NV_isDisabled | `obj:_NV_isDisabled(...)` |
| setInsideTownWalls | setInsideTownWalls | `obj:setInsideTownWalls(...)` |
| _NV_setInsideTownWalls | _NV_setInsideTownWalls | `obj:_NV_setInsideTownWalls(...)` |
| sheatheWeapon | sheatheWeapon | `obj:sheatheWeapon(...)` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `obj:_NV_sheatheWeapon(...)` |
| select | select | `obj:select(...)` |
| _NV_select | _NV_select | `obj:_NV_select(...)` |
| unselect | unselect | `obj:unselect(...)` |
| _NV_unselect | _NV_unselect | `obj:_NV_unselect(...)` |
| say_WithARepeatLimiter | say_WithARepeatLimiter | `obj:say_WithARepeatLimiter(...)` |
| _NV_say_WithARepeatLimiter | _NV_say_WithARepeatLimiter | `obj:_NV_say_WithARepeatLimiter(...)` |
| say | say | `obj:say(...)` |
| _NV_say | _NV_say | `obj:_NV_say(...)` |
| isInventoryVisible | isInventoryVisible | `obj:isInventoryVisible(...)` |
| _NV_isInventoryVisible | _NV_isInventoryVisible | `obj:_NV_isInventoryVisible(...)` |
| getNumFoodItems | getNumFoodItems | `obj:getNumFoodItems(...)` |
| _NV_getNumFoodItems | _NV_getNumFoodItems | `obj:_NV_getNumFoodItems(...)` |
| hasSimilarItem | hasSimilarItem | `obj:hasSimilarItem(...)` |
| _NV_hasSimilarItem | _NV_hasSimilarItem | `obj:_NV_hasSimilarItem(...)` |
| ifImASmithShouldIDitchMyBackWeapon | ifImASmithShouldIDitchMyBackWeapon | `obj:ifImASmithShouldIDitchMyBackWeapon(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| _NV_getInventory | _NV_getInventory | `obj:_NV_getInventory(...)` |
| hasABackpackOn | hasABackpackOn | `obj:hasABackpackOn(...)` |
| isATrader | isATrader | `obj:isATrader(...)` |
| isFemale | isFemale | `obj:isFemale(...)` |
| isFleeing | isFleeing | `obj:isFleeing(...)` |
| getRoughLevel | getRoughLevel | `obj:getRoughLevel(...)` |
| setStandingOrder | setStandingOrder | `obj:setStandingOrder(...)` |
| _NV_setStandingOrder | _NV_setStandingOrder | `obj:_NV_setStandingOrder(...)` |
| getStandingOrder | getStandingOrder | `obj:getStandingOrder(...)` |
| setStealthMode | setStealthMode | `obj:setStealthMode(...)` |
| isStealthMode | isStealthMode | `obj:isStealthMode(...)` |
| isStealthModeOrCrawling | isStealthModeOrCrawling | `obj:isStealthModeOrCrawling(...)` |
| declareDead | declareDead | `obj:declareDead(...)` |
| removeJob | removeJob | `obj:removeJob(...)` |
| removePermajob | removePermajob | `obj:removePermajob(...)` |
| clearPermajobs | clearPermajobs | `obj:clearPermajobs(...)` |
| movePermajob | movePermajob | `obj:movePermajob(...)` |
| getPermajob | getPermajob | `obj:getPermajob(...)` |
| getPermajobCount | getPermajobCount | `obj:getPermajobCount(...)` |
| endCombatMode | endCombatMode | `obj:endCombatMode(...)` |
| getTotalRelativeStrengthOfAttackers | getTotalRelativeStrengthOfAttackers | `obj:getTotalRelativeStrengthOfAttackers(...)` |
| _NV_getTotalRelativeStrengthOfAttackers | _NV_getTotalRelativeStrengthOfAttackers | `obj:_NV_getTotalRelativeStrengthOfAttackers(...)` |
| isIndoorsRagdoll | isIndoorsRagdoll | `obj:isIndoorsRagdoll(...)` |
| _NV_isIndoorsRagdoll | _NV_isIndoorsRagdoll | `obj:_NV_isIndoorsRagdoll(...)` |
| getIntendedAggression | getIntendedAggression | `obj:getIntendedAggression(...)` |
| _NV_getIntendedAggression | _NV_getIntendedAggression | `obj:_NV_getIntendedAggression(...)` |
| getPositionBip01 | getPositionBip01 | `obj:getPositionBip01(...)` |
| amInsideTownWalls | amInsideTownWalls | `obj:amInsideTownWalls(...)` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `obj:_NV_amInsideTownWalls(...)` |
| setName | setName | `obj:setName(...)` |
| _NV_setName | _NV_setName | `obj:_NV_setName(...)` |
| setNameTagVisible | setNameTagVisible | `obj:setNameTagVisible(...)` |
| ragdollMode | ragdollMode | `obj:ragdollMode(...)` |
| isRagdoll | isRagdoll | `obj:isRagdoll(...)` |
| isDown | isDown | `obj:isDown(...)` |
| getRagdollPhysicsRootPos | getRagdollPhysicsRootPos | `obj:getRagdollPhysicsRootPos(...)` |
| amSomeoneWhoNeedsToEatToLive | amSomeoneWhoNeedsToEatToLive | `obj:amSomeoneWhoNeedsToEatToLive(...)` |
| _NV_amSomeoneWhoNeedsToEatToLive | _NV_amSomeoneWhoNeedsToEatToLive | `obj:_NV_amSomeoneWhoNeedsToEatToLive(...)` |
| getMagicHungerSetting | getMagicHungerSetting | `obj:getMagicHungerSetting(...)` |
| _NV_getMagicHungerSetting | _NV_getMagicHungerSetting | `obj:_NV_getMagicHungerSetting(...)` |
| wantsToEatNow | wantsToEatNow | `obj:wantsToEatNow(...)` |
| isKidnapped | isKidnapped | `obj:isKidnapped(...)` |
| _NV_isKidnapped | _NV_isKidnapped | `obj:_NV_isKidnapped(...)` |
| isLiterallyUnconciousNotPretending | isLiterallyUnconciousNotPretending | `obj:isLiterallyUnconciousNotPretending(...)` |
| _NV_isLiterallyUnconciousNotPretending | _NV_isLiterallyUnconciousNotPretending | `obj:_NV_isLiterallyUnconciousNotPretending(...)` |
| isUnconcious | isUnconcious | `obj:isUnconcious(...)` |
| _NV_isUnconcious | _NV_isUnconcious | `obj:_NV_isUnconcious(...)` |
| isCrippled | isCrippled | `obj:isCrippled(...)` |
| _NV_isCrippled | _NV_isCrippled | `obj:_NV_isCrippled(...)` |
| getProneState | getProneState | `obj:getProneState(...)` |
| _NV_getProneState | _NV_getProneState | `obj:_NV_getProneState(...)` |
| setProneState | setProneState | `obj:setProneState(...)` |
| _NV_setProneState | _NV_setProneState | `obj:_NV_setProneState(...)` |
| _killRagdoll | _killRagdoll | `obj:_killRagdoll(...)` |
| setupAI | setupAI | `obj:setupAI(...)` |
| clearAllAIGoals | clearAllAIGoals | `obj:clearAllAIGoals(...)` |
| setupPlatoonAI | setupPlatoonAI | `obj:setupPlatoonAI(...)` |
| setDestination | setDestination | `obj:setDestination(...)` |
| sayALine | sayALine | `obj:sayALine(...)` |
| hasDialogue | hasDialogue | `obj:hasDialogue(...)` |
| willTalkToEnemies | willTalkToEnemies | `obj:willTalkToEnemies(...)` |
| relocationTeleport | relocationTeleport | `obj:relocationTeleport(...)` |
| teleportVisuallyOnly | teleportVisuallyOnly | `obj:teleportVisuallyOnly(...)` |
| teleportFromAnimation | teleportFromAnimation | `obj:teleportFromAnimation(...)` |
| stumbleState | stumbleState | `obj:stumbleState(...)` |
| setAge | setAge | `obj:setAge(...)` |
| _NV_setAge | _NV_setAge | `obj:_NV_setAge(...)` |
| getAge | getAge | `obj:getAge(...)` |
| _NV_getAge | _NV_getAge | `obj:_NV_getAge(...)` |
| getAge0to1 | getAge0to1 | `obj:getAge0to1(...)` |
| _NV_getAge0to1 | _NV_getAge0to1 | `obj:_NV_getAge0to1(...)` |
| getAgeString | getAgeString | `obj:getAgeString(...)` |
| _NV_getAgeString | _NV_getAgeString | `obj:_NV_getAgeString(...)` |
| getAgeInverse | getAgeInverse | `obj:getAgeInverse(...)` |
| _NV_getAgeInverse | _NV_getAgeInverse | `obj:_NV_getAgeInverse(...)` |
| reThinkCurrentAIAction | reThinkCurrentAIAction | `obj:reThinkCurrentAIAction(...)` |
| getStats | getStats | `obj:getStats(...)` |
| getMedical | getMedical | `obj:getMedical(...)` |
| getOwnerships | getOwnerships | `obj:getOwnerships(...)` |
| isInCombatMode | isInCombatMode | `obj:isInCombatMode(...)` |
| isInRangedCombatMode | isInRangedCombatMode | `obj:isInRangedCombatMode(...)` |
| isLiterallyUnderMeleeAttackRightNowForSure | isLiterallyUnderMeleeAttackRightNowForSure | `obj:isLiterallyUnderMeleeAttackRightNowForSure(...)` |
| _isLiterallyUnderMeleeAttackRightNowForSure_update | _isLiterallyUnderMeleeAttackRightNowForSure_update | `obj:_isLiterallyUnderMeleeAttackRightNowForSure_update(...)` |
| isPrisonerFreeToGo | isPrisonerFreeToGo | `obj:isPrisonerFreeToGo(...)` |
| clearAllTempEnemyStatuses | clearAllTempEnemyStatuses | `obj:clearAllTempEnemyStatuses(...)` |
| lookatPosition | lookatPosition | `obj:lookatPosition(...)` |
| _NV_lookatPosition | _NV_lookatPosition | `obj:_NV_lookatPosition(...)` |
| getAllAttackersCount | getAllAttackersCount | `obj:getAllAttackersCount(...)` |
| getRace | getRace | `obj:getRace(...)` |
| _NV_getRace | _NV_getRace | `obj:_NV_getRace(...)` |
| getRadius | getRadius | `obj:getRadius(...)` |
| isPlayerCharacter | isPlayerCharacter | `obj:isPlayerCharacter(...)` |
| getTotalCarryWeight | getTotalCarryWeight | `obj:getTotalCarryWeight(...)` |
| getCurrentWeapon | getCurrentWeapon | `obj:getCurrentWeapon(...)` |
| getThePreferredWeapon | getThePreferredWeapon | `obj:getThePreferredWeapon(...)` |
| getRangedWeapon | getRangedWeapon | `obj:getRangedWeapon(...)` |
| _NV_getRangedWeapon | _NV_getRangedWeapon | `obj:_NV_getRangedWeapon(...)` |
| getUpperBodyArmour | getUpperBodyArmour | `obj:getUpperBodyArmour(...)` |
| getLowerBodyArmour | getLowerBodyArmour | `obj:getLowerBodyArmour(...)` |
| isInjured | isInjured | `obj:isInjured(...)` |
| shouldUseRangedWeapons | shouldUseRangedWeapons | `obj:shouldUseRangedWeapons(...)` |
| getBoneWorldPosition | getBoneWorldPosition | `obj:getBoneWorldPosition(...)` |
| hasPlatoon | hasPlatoon | `obj:hasPlatoon(...)` |
| isInAPersistentPlatoon | isInAPersistentPlatoon | `obj:isInAPersistentPlatoon(...)` |
| getSquadLeader | getSquadLeader | `obj:getSquadLeader(...)` |
| preventRagdollMode | preventRagdollMode | `obj:preventRagdollMode(...)` |
| setSlaveAIJob | setSlaveAIJob | `obj:setSlaveAIJob(...)` |
| isChainedMode | isChainedMode | `obj:isChainedMode(...)` |
| getChainedModeShackles | getChainedModeShackles | `obj:getChainedModeShackles(...)` |
| isSlave | isSlave | `obj:isSlave(...)` |
| isHeadShaven | isHeadShaven | `obj:isHeadShaven(...)` |
| _NV_isHeadShaven | _NV_isHeadShaven | `obj:_NV_isHeadShaven(...)` |
| runSlaveAnim | runSlaveAnim | `obj:runSlaveAnim(...)` |
| endSlaveAnim | endSlaveAnim | `obj:endSlaveAnim(...)` |
| updatePortraitGUIState | updatePortraitGUIState | `obj:updatePortraitGUIState(...)` |
| slaveAttachToBoneMode | slaveAttachToBoneMode | `obj:slaveAttachToBoneMode(...)` |
| isDead | isDead | `obj:isDead(...)` |
| isBeingCarried | isBeingCarried | `obj:isBeingCarried(...)` |
| chooseCarryObjectLeftOrRight | chooseCarryObjectLeftOrRight | `obj:chooseCarryObjectLeftOrRight(...)` |
| dropCarriedObject | dropCarriedObject | `obj:dropCarriedObject(...)` |
| getDropped | getDropped | `obj:getDropped(...)` |
| getDiplomacyMultiplier | getDiplomacyMultiplier | `obj:getDiplomacyMultiplier(...)` |
| getDefaultTaskRepertoireEnum | getDefaultTaskRepertoireEnum | `obj:getDefaultTaskRepertoireEnum(...)` |
| _NV_getDefaultTaskRepertoireEnum | _NV_getDefaultTaskRepertoireEnum | `obj:_NV_getDefaultTaskRepertoireEnum(...)` |
| getPredictedPosition | getPredictedPosition | `obj:getPredictedPosition(...)` |
| carryModeT | carryModeT | `obj:carryModeT(...)` |
| _carryMode | _carryMode | `obj:_carryMode(...)` |
| recalculateTotalEquipmentSkillBonus | recalculateTotalEquipmentSkillBonus | `obj:recalculateTotalEquipmentSkillBonus(...)` |
| setupAudio | setupAudio | `obj:setupAudio(...)` |
| _NV_setupAudio | _NV_setupAudio | `obj:_NV_setupAudio(...)` |
| setGroundType | setGroundType | `obj:setGroundType(...)` |
| getGroundType | getGroundType | `obj:getGroundType(...)` |
| calculateMainArmourType | calculateMainArmourType | `obj:calculateMainArmourType(...)` |
| getMainArmourType | getMainArmourType | `obj:getMainArmourType(...)` |
| getUniformColorScheme | getUniformColorScheme | `obj:getUniformColorScheme(...)` |
| canTakePlayerOrdersAtThisTime | canTakePlayerOrdersAtThisTime | `obj:canTakePlayerOrdersAtThisTime(...)` |
| stopAllEffects | stopAllEffects | `obj:stopAllEffects(...)` |
| notifyEffect | notifyEffect | `obj:notifyEffect(...)` |
| _NV_notifyEffect | _NV_notifyEffect | `obj:_NV_notifyEffect(...)` |
| validateInventorySections | validateInventorySections | `obj:validateInventorySections(...)` |
| _NV_validateInventorySections | _NV_validateInventorySections | `obj:_NV_validateInventorySections(...)` |
| processCharacterLoadTimeMessages | processCharacterLoadTimeMessages | `obj:processCharacterLoadTimeMessages(...)` |
| wantsPathfinderActive | wantsPathfinderActive | `obj:wantsPathfinderActive(...)` |
| createAnimationClass | createAnimationClass | `obj:createAnimationClass(...)` |
| createPhysical | createPhysical | `obj:createPhysical(...)` |
| _NV_createPhysical | _NV_createPhysical | `obj:_NV_createPhysical(...)` |
| destroyPhysical | destroyPhysical | `obj:destroyPhysical(...)` |
| _NV_destroyPhysical | _NV_destroyPhysical | `obj:_NV_destroyPhysical(...)` |
| loadUnloadCheck | loadUnloadCheck | `obj:loadUnloadCheck(...)` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `obj:_NV_loadUnloadCheck(...)` |
| updateStateBroadcast | updateStateBroadcast | `obj:updateStateBroadcast(...)` |
| postRagdollCallback | postRagdollCallback | `obj:postRagdollCallback(...)` |
| _NV_postRagdollCallback | _NV_postRagdollCallback | `obj:_NV_postRagdollCallback(...)` |
| reCalculateNaturalWeapon | reCalculateNaturalWeapon | `obj:reCalculateNaturalWeapon(...)` |
| _NV_reCalculateNaturalWeapon | _NV_reCalculateNaturalWeapon | `obj:_NV_reCalculateNaturalWeapon(...)` |
| rememberCharacter | rememberCharacter | `obj:rememberCharacter(...)` |
| attackTarget | attackTarget | `obj:attackTarget(...)` |
| isHuman | isHuman | `obj:isHuman(...)` |
| _NV_isHuman | _NV_isHuman | `obj:_NV_isHuman(...)` |
| isResident | isResident | `obj:isResident(...)` |
| getSensoryData | getSensoryData | `obj:getSensoryData(...)` |
| _NV_getSensoryData | _NV_getSensoryData | `obj:_NV_getSensoryData(...)` |
| getCurrentTownLocation | getCurrentTownLocation | `obj:getCurrentTownLocation(...)` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `obj:_NV_getCurrentTownLocation(...)` |
| lineOfSightCheck | lineOfSightCheck | `obj:lineOfSightCheck(...)` |
| isItOkForMeToLoot | isItOkForMeToLoot | `obj:isItOkForMeToLoot(...)` |
| _NV_isItOkForMeToLoot | _NV_isItOkForMeToLoot | `obj:_NV_isItOkForMeToLoot(...)` |
| ImStealingDoYouNotice | ImStealingDoYouNotice | `obj:ImStealingDoYouNotice(...)` |
| _NV_ImStealingDoYouNotice | _NV_ImStealingDoYouNotice | `obj:_NV_ImStealingDoYouNotice(...)` |
| getFencingSuccessChance | getFencingSuccessChance | `obj:getFencingSuccessChance(...)` |
| stolenGoodsDetectionCheck | stolenGoodsDetectionCheck | `obj:stolenGoodsDetectionCheck(...)` |
| _NV_stolenGoodsDetectionCheck | _NV_stolenGoodsDetectionCheck | `obj:_NV_stolenGoodsDetectionCheck(...)` |
| sellingUniformDetectionCheck | sellingUniformDetectionCheck | `obj:sellingUniformDetectionCheck(...)` |
| _NV_sellingUniformDetectionCheck | _NV_sellingUniformDetectionCheck | `obj:_NV_sellingUniformDetectionCheck(...)` |
| smugglingTradeCheck | smugglingTradeCheck | `obj:smugglingTradeCheck(...)` |
| _NV_smugglingTradeCheck | _NV_smugglingTradeCheck | `obj:_NV_smugglingTradeCheck(...)` |
| eatItem | eatItem | `obj:eatItem(...)` |
| giveItem | giveItem | `obj:giveItem(...)` |
| _NV_giveItem | _NV_giveItem | `obj:_NV_giveItem(...)` |
| hasRoomForItem | hasRoomForItem | `obj:hasRoomForItem(...)` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `obj:_NV_hasRoomForItem(...)` |
| hasItem | hasItem | `obj:hasItem(...)` |
| _NV_hasItem | _NV_hasItem | `obj:_NV_hasItem(...)` |
| hasAmmoFor | hasAmmoFor | `obj:hasAmmoFor(...)` |
| _NV_hasAmmoFor | _NV_hasAmmoFor | `obj:_NV_hasAmmoFor(...)` |
| shouldIHelpThisGuy | shouldIHelpThisGuy | `obj:shouldIHelpThisGuy(...)` |
| shouldIScrewThisGuyOver | shouldIScrewThisGuyOver | `obj:shouldIScrewThisGuyOver(...)` |
| ILoveThisGuyBecauseOfStuffThatHappened | ILoveThisGuyBecauseOfStuffThatHappened | `obj:ILoveThisGuyBecauseOfStuffThatHappened(...)` |
| IHateThisGuyBecauseOfStuffThatHappened | IHateThisGuyBecauseOfStuffThatHappened | `obj:IHateThisGuyBecauseOfStuffThatHappened(...)` |
| isEnemy | isEnemy | `obj:isEnemy(...)` |
| _NV_isEnemy | _NV_isEnemy | `obj:_NV_isEnemy(...)` |
| isAlly | isAlly | `obj:isAlly(...)` |
| _NV_isAlly | _NV_isAlly | `obj:_NV_isAlly(...)` |
| setHandle | setHandle | `obj:setHandle(...)` |
| _NV_setHandle | _NV_setHandle | `obj:_NV_setHandle(...)` |
| getStealingSuccessChance | getStealingSuccessChance | `obj:getStealingSuccessChance(...)` |
| canGoIndoors | canGoIndoors | `obj:canGoIndoors(...)` |
| _NV_canGoIndoors | _NV_canGoIndoors | `obj:_NV_canGoIndoors(...)` |
| isIndoors | isIndoors | `obj:isIndoors(...)` |
| _NV_isIndoors | _NV_isIndoors | `obj:_NV_isIndoors(...)` |
| isStandingOnBuilding | isStandingOnBuilding | `obj:isStandingOnBuilding(...)` |
| _NV_isStandingOnBuilding | _NV_isStandingOnBuilding | `obj:_NV_isStandingOnBuilding(...)` |
| notifyIndoors | notifyIndoors | `obj:notifyIndoors(...)` |
| _NV_notifyIndoors | _NV_notifyIndoors | `obj:_NV_notifyIndoors(...)` |
| destinationIndoors | destinationIndoors | `obj:destinationIndoors(...)` |
| setDestinationIndoors | setDestinationIndoors | `obj:setDestinationIndoors(...)` |
| getAppearanceData | getAppearanceData | `obj:getAppearanceData(...)` |
| setAppearanceData | setAppearanceData | `obj:setAppearanceData(...)` |
| setFaction | setFaction | `obj:setFaction(...)` |
| _NV_setFaction | _NV_setFaction | `obj:_NV_setFaction(...)` |
| getBody | getBody | `obj:getBody(...)` |
| getAttackTarget | getAttackTarget | `obj:getAttackTarget(...)` |
| getMovement | getMovement | `obj:getMovement(...)` |
| getAppearance | getAppearance | `obj:getAppearance(...)` |
| getPlatoon | getPlatoon | `obj:getPlatoon(...)` |
| getCarryingObject | getCarryingObject | `obj:getCarryingObject(...)` |
| getAudioObject | getAudioObject | `obj:getAudioObject(...)` |
| equipItem | equipItem | `obj:equipItem(...)` |
| _NV_equipItem | _NV_equipItem | `obj:_NV_equipItem(...)` |
| unequipItem | unequipItem | `obj:unequipItem(...)` |
| _NV_unequipItem | _NV_unequipItem | `obj:_NV_unequipItem(...)` |
| getStealthKOChance | getStealthKOChance | `obj:getStealthKOChance(...)` |
| getKidnappingChance | getKidnappingChance | `obj:getKidnappingChance(...)` |
| getKidnappingEscapeChance_skill | getKidnappingEscapeChance_skill | `obj:getKidnappingEscapeChance_skill(...)` |
| getKidnappingEscapeChance_strength | getKidnappingEscapeChance_strength | `obj:getKidnappingEscapeChance_strength(...)` |
| getIDForMemoryTagging | Character_getIDForMemoryTagging | `obj:getIDForMemoryTagging(...)` |
| getMySlaveOwner | Character_getMySlaveOwner | `obj:getMySlaveOwner(...)` |
| generateWeapon | Character_generateWeapon | `obj:generateWeapon(...)` |
| getName | Character_getName | `obj:getName(...)` |
| _NV_getName | Character__NV_getName | `obj:_NV_getName(...)` |

## CharacterAnimal
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| weaponIsTechnicallyEquipped | weaponIsTechnicallyEquipped | boolean | RW | `obj.weaponIsTechnicallyEquipped = <value>` |
| HPMultiplier | HPMultiplier | number | RW | `obj.HPMultiplier = <value>` |
| itemInMouthTimeStamp | itemInMouthTimeStamp | TimeOfDay | R | `obj.itemInMouthTimeStamp` |
| smellThresholdBlood | smellThresholdBlood | number | RW | `obj.smellThresholdBlood = <value>` |
| smellThresholdEggs | smellThresholdEggs | number | RW | `obj.smellThresholdEggs = <value>` |
| ageSizeMin | ageSizeMin | number | RW | `obj.ageSizeMin = <value>` |
| ageSizeMax | ageSizeMax | number | RW | `obj.ageSizeMax = <value>` |
| lifespanInDays | lifespanInDays | number | RW | `obj.lifespanInDays = <value>` |
| lastUpdatedAge | lastUpdatedAge | number | RW | `obj.lastUpdatedAge = <value>` |
| age | age | number | RW | `obj.age = <value>` |
| weaponInHands | weaponInHands | Weapon | R | `obj.weaponInHands` |
| audioTimeStamp | audioTimeStamp | number | RW | `obj.audioTimeStamp = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isAnimal | isAnimal | `obj:isAnimal(...)` |
| _NV_isAnimal | _NV_isAnimal | `obj:_NV_isAnimal(...)` |
| createAnimationClass | createAnimationClass | `obj:createAnimationClass(...)` |
| _NV_createAnimationClass | _NV_createAnimationClass | `obj:_NV_createAnimationClass(...)` |
| sheatheWeapon | sheatheWeapon | `obj:sheatheWeapon(...)` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `obj:_NV_sheatheWeapon(...)` |
| getCurrentWeapon | getCurrentWeapon | `obj:getCurrentWeapon(...)` |
| _NV_getCurrentWeapon | _NV_getCurrentWeapon | `obj:_NV_getCurrentWeapon(...)` |
| getThePreferredWeapon | getThePreferredWeapon | `obj:getThePreferredWeapon(...)` |
| _NV_getThePreferredWeapon | _NV_getThePreferredWeapon | `obj:_NV_getThePreferredWeapon(...)` |
| setupAudio | setupAudio | `obj:setupAudio(...)` |
| _NV_setupAudio | _NV_setupAudio | `obj:_NV_setupAudio(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| setAge | setAge | `obj:setAge(...)` |
| _NV_setAge | _NV_setAge | `obj:_NV_setAge(...)` |
| getAge | getAge | `obj:getAge(...)` |
| _NV_getAge | _NV_getAge | `obj:_NV_getAge(...)` |
| getAgeInverse | getAgeInverse | `obj:getAgeInverse(...)` |
| _NV_getAgeInverse | _NV_getAgeInverse | `obj:_NV_getAgeInverse(...)` |
| getAge0to1 | getAge0to1 | `obj:getAge0to1(...)` |
| _NV_getAge0to1 | _NV_getAge0to1 | `obj:_NV_getAge0to1(...)` |
| getDefaultTaskRepertoireEnum | getDefaultTaskRepertoireEnum | `obj:getDefaultTaskRepertoireEnum(...)` |
| _NV_getDefaultTaskRepertoireEnum | _NV_getDefaultTaskRepertoireEnum | `obj:_NV_getDefaultTaskRepertoireEnum(...)` |
| getSmellHuntingThresholdBlood | getSmellHuntingThresholdBlood | `obj:getSmellHuntingThresholdBlood(...)` |
| _NV_getSmellHuntingThresholdBlood | _NV_getSmellHuntingThresholdBlood | `obj:_NV_getSmellHuntingThresholdBlood(...)` |
| getSmellHuntingThresholdEggs | getSmellHuntingThresholdEggs | `obj:getSmellHuntingThresholdEggs(...)` |
| _NV_getSmellHuntingThresholdEggs | _NV_getSmellHuntingThresholdEggs | `obj:_NV_getSmellHuntingThresholdEggs(...)` |
| getHPMultiplier | getHPMultiplier | `obj:getHPMultiplier(...)` |
| _NV_getHPMultiplier | _NV_getHPMultiplier | `obj:_NV_getHPMultiplier(...)` |
| foodUpdate | foodUpdate | `obj:foodUpdate(...)` |
| _NV_foodUpdate | _NV_foodUpdate | `obj:_NV_foodUpdate(...)` |
| dropItemInMouth | dropItemInMouth | `obj:dropItemInMouth(...)` |
| getItemInMouth | getItemInMouth | `obj:getItemInMouth(...)` |
| eatItemInMouth | eatItemInMouth | `obj:eatItemInMouth(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| init | init | `obj:init(...)` |
| _NV_init | _NV_init | `obj:_NV_init(...)` |

## CharacterHuman
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| weaponInHands | weaponInHands | Weapon | R | `obj.weaponInHands` |
| weaponInHandsSheathLocation | weaponInHandsSheathLocation | string | RW | `obj.weaponInHandsSheathLocation = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| sheatheWeapon | sheatheWeapon | `obj:sheatheWeapon(...)` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `obj:_NV_sheatheWeapon(...)` |
| getCurrentWeapon | getCurrentWeapon | `obj:getCurrentWeapon(...)` |
| _NV_getCurrentWeapon | _NV_getCurrentWeapon | `obj:_NV_getCurrentWeapon(...)` |
| getThePreferredWeapon | getThePreferredWeapon | `obj:getThePreferredWeapon(...)` |
| _NV_getThePreferredWeapon | _NV_getThePreferredWeapon | `obj:_NV_getThePreferredWeapon(...)` |
| getRangedWeapon | getRangedWeapon | `obj:getRangedWeapon(...)` |
| _NV_getRangedWeapon | _NV_getRangedWeapon | `obj:_NV_getRangedWeapon(...)` |
| validateInventorySections | validateInventorySections | `obj:validateInventorySections(...)` |
| _NV_validateInventorySections | _NV_validateInventorySections | `obj:_NV_validateInventorySections(...)` |
| setupAudio | setupAudio | `obj:setupAudio(...)` |
| _NV_setupAudio | _NV_setupAudio | `obj:_NV_setupAudio(...)` |
| shaveHead | shaveHead | `obj:shaveHead(...)` |
| isHeadShaven | isHeadShaven | `obj:isHeadShaven(...)` |
| _NV_isHeadShaven | _NV_isHeadShaven | `obj:_NV_isHeadShaven(...)` |
| createAnimationClass | createAnimationClass | `obj:createAnimationClass(...)` |
| _NV_createAnimationClass | _NV_createAnimationClass | `obj:_NV_createAnimationClass(...)` |
| dropWeaponInHands | dropWeaponInHands | `obj:dropWeaponInHands(...)` |
| dropWeaponInHandsFake | dropWeaponInHandsFake | `obj:dropWeaponInHandsFake(...)` |
| weatherUpdate | weatherUpdate | `obj:weatherUpdate(...)` |
| _NV_weatherUpdate | _NV_weatherUpdate | `obj:_NV_weatherUpdate(...)` |
| leaveSheathEquipped | leaveSheathEquipped | `obj:leaveSheathEquipped(...)` |
| postRagdollCallback | postRagdollCallback | `obj:postRagdollCallback(...)` |
| _NV_postRagdollCallback | _NV_postRagdollCallback | `obj:_NV_postRagdollCallback(...)` |
| reCalculateNaturalWeapon | reCalculateNaturalWeapon | `obj:reCalculateNaturalWeapon(...)` |
| _NV_reCalculateNaturalWeapon | _NV_reCalculateNaturalWeapon | `obj:_NV_reCalculateNaturalWeapon(...)` |

## CharacterInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## CombatMovementController
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| characterCollisions | characterCollisions | ogre_unordered_map<hand, float>::type | R | `obj.characterCollisions` |
| movement | movement | CharMovement* | R | `obj.movement` |
| chaseMode | chaseMode | boolean | RW | `obj.chaseMode = <value>` |
| chaseStateTimer | chaseStateTimer | number | RW | `obj.chaseStateTimer = <value>` |
| hasForcedWP | hasForcedWP | boolean | RW | `obj.hasForcedWP = <value>` |
| forcedWP | forcedWP | Vector3 | RW | `obj.forcedWP = <value>` |
| flockFilterX | flockFilterX | MotionFilter | R | `obj.flockFilterX` |
| flockFilterZ | flockFilterZ | MotionFilter | R | `obj.flockFilterZ` |
| flockingControl | flockingControl | FlockingTools | R | `obj.flockingControl` |
| stats | stats | CharStats | R | `obj.stats` |
| radius | radius | number | RW | `obj.radius = <value>` |
| jogMode | jogMode | boolean | RW | `obj.jogMode = <value>` |
| TOTALREPULSION_DAMPING | TOTALREPULSION_DAMPING | number | RW | `obj.TOTALREPULSION_DAMPING = <value>` |
| STRAFE_STATE_DAMPING | STRAFE_STATE_DAMPING | number | RW | `obj.STRAFE_STATE_DAMPING = <value>` |
| STRAFE_THRESHOLD | STRAFE_THRESHOLD | number | RW | `obj.STRAFE_THRESHOLD = <value>` |
| FORWARD_THRESHOLD | FORWARD_THRESHOLD | number | RW | `obj.FORWARD_THRESHOLD = <value>` |
| MIN_RANGE_FW | MIN_RANGE_FW | number | RW | `obj.MIN_RANGE_FW = <value>` |
| ENEMY_DIST | ENEMY_DIST | number | RW | `obj.ENEMY_DIST = <value>` |
| ALLY_DIST | ALLY_DIST | number | RW | `obj.ALLY_DIST = <value>` |
| STOP_THRESHOLD | STOP_THRESHOLD | number | RW | `obj.STOP_THRESHOLD = <value>` |
| START_THRESHOLD | START_THRESHOLD | number | RW | `obj.START_THRESHOLD = <value>` |
| ACCEL_RATE_COMBATMODE | ACCEL_RATE_COMBATMODE | number | RW | `obj.ACCEL_RATE_COMBATMODE = <value>` |
| meiMin | meiMin | number | RW | `obj.meiMin = <value>` |
| circlingSpeed | circlingSpeed | number | RW | `obj.circlingSpeed = <value>` |
| combatMinDistance | combatMinDistance | number | RW | `obj.combatMinDistance = <value>` |
| combatMaxDistance | combatMaxDistance | number | RW | `obj.combatMaxDistance = <value>` |
| strafeStateTimer | strafeStateTimer | number | RW | `obj.strafeStateTimer = <value>` |
| strafing | strafing | boolean | RW | `obj.strafing = <value>` |
| powerThrough | powerThrough | boolean | RW | `obj.powerThrough = <value>` |
| canStrafe | canStrafe | boolean | RW | `obj.canStrafe = <value>` |
| speedLimit | speedLimit | number | RW | `obj.speedLimit = <value>` |
| currentAccelSpeed | currentAccelSpeed | number | RW | `obj.currentAccelSpeed = <value>` |
| lookAtCharacter | lookAtCharacter | hand | RW | `obj.lookAtCharacter = <value>` |
| combatTarget | combatTarget | hand | RW | `obj.combatTarget = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| collisionUpdate | collisionUpdate | `obj:collisionUpdate(...)` |
| areTherePeopleInMyWay | areTherePeopleInMyWay | `obj:areTherePeopleInMyWay(...)` |
| getUrgentVelocities | getUrgentVelocities | `obj:getUrgentVelocities(...)` |
| checkWeDontCollideWithCharacters | checkWeDontCollideWithCharacters | `obj:checkWeDontCollideWithCharacters(...)` |
| checkCharacterCollision | checkCharacterCollision | `obj:checkCharacterCollision(...)` |
| setForcedWP | setForcedWP | `obj:setForcedWP(...)` |
| disable | disable | `obj:disable(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## CombatTechniqueData
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| animation | animation | string | RW | `obj.animation = <value>` |
| animSpeedMultiplier | animSpeedMultiplier | number | RW | `obj.animSpeedMultiplier = <value>` |
| isBlock | isBlock | boolean | RW | `obj.isBlock = <value>` |
| isDodge | isDodge | boolean | RW | `obj.isDodge = <value>` |
| stumbleDodge | stumbleDodge | boolean | RW | `obj.stumbleDodge = <value>` |
| gainsGround | gainsGround | boolean | RW | `obj.gainsGround = <value>` |
| isProne | isProne | boolean | RW | `obj.isProne = <value>` |
| lowStrike | lowStrike | boolean | RW | `obj.lowStrike = <value>` |
| hesitationPoint | hesitationPoint | number | RW | `obj.hesitationPoint = <value>` |
| initialDistance | initialDistance | number | RW | `obj.initialDistance = <value>` |
| minDistanceVsStatic | minDistanceVsStatic | number | RW | `obj.minDistanceVsStatic = <value>` |
| acceptableEndTime01 | acceptableEndTime01 | number | RW | `obj.acceptableEndTime01 = <value>` |
| minSkill | minSkill | number | RW | `obj.minSkill = <value>` |
| maxSkill | maxSkill | number | RW | `obj.maxSkill = <value>` |
| maxEncumbrance | maxEncumbrance | number | RW | `obj.maxEncumbrance = <value>` |
| chanceMult | chanceMult | number | RW | `obj.chanceMult = <value>` |
| maxTargetHits | maxTargetHits | integer | RW | `obj.maxTargetHits = <value>` |
| events | events | unknown | R | `obj.events` |
| skillTypes | skillTypes | unknown | R | `obj.skillTypes` |
| impactPoints | impactPoints | lektor<CombatTechniqueData::ImpactPoint> | R | `obj.impactPoints` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| hasSkillType | hasSkillType | `obj:hasSkillType(...)` |
| numImpactPoints | numImpactPoints | `obj:numImpactPoints(...)` |
| impactPoint | impactPoint | `obj:impactPoint(...)` |

## ContainerItem
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| callbackOwner | callbackOwner | RootObject | R | `obj.callbackOwner` |
| athleticsMult | athleticsMult | number | RW | `obj.athleticsMult = <value>` |
| weightMult | weightMult | number | RW | `obj.weightMult = <value>` |
| combatSpeedMult | combatSpeedMult | number | RW | `obj.combatSpeedMult = <value>` |
| combatSkillBonus | combatSkillBonus | integer | RW | `obj.combatSkillBonus = <value>` |
| stealthMult | stealthMult | number | RW | `obj.stealthMult = <value>` |
| racesExclude | racesExclude | ogre_unordered_set<GameData*>::type | R | `obj.racesExclude` |
| inventory | inventory | Inventory | R | `obj.inventory` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getClassType | getClassType | `obj:getClassType(...)` |
| _NV_getClassType | _NV_getClassType | `obj:_NV_getClassType(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| _NV_takeMoney | _NV_takeMoney | `obj:_NV_takeMoney(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| _NV_getMoney | _NV_getMoney | `obj:_NV_getMoney(...)` |
| doubleCheckHandle | doubleCheckHandle | `obj:doubleCheckHandle(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| _NV_getPosition | _NV_getPosition | `obj:_NV_getPosition(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| _NV_getInventory | _NV_getInventory | `obj:_NV_getInventory(...)` |

## ContextMenu
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| rightMouseActivated | rightMouseActivated | boolean | RW | `obj.rightMouseActivated = <value>` |
| orders | orders | lektor<int> | R | `obj.orders` |
| contextMenuName | contextMenuName | string | RW | `obj.contextMenuName = <value>` |
| menuGUI | menuGUI | ContextMenuGUI* | R | `obj.menuGUI` |
| menuGUI2 | menuGUI2 | ContextMenuGUI* | R | `obj.menuGUI2` |
| delayedDestroyFlag | delayedDestroyFlag | boolean | RW | `obj.delayedDestroyFlag = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| isVisible | isVisible | `obj:isVisible(...)` |
| update | update | `obj:update(...)` |
| _destroyMenuGUICheck | _destroyMenuGUICheck | `obj:_destroyMenuGUICheck(...)` |

## CreatelistItem
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| container | container | RootObjectContainer | R | `obj.container` |
| homeBuilding | homeBuilding | Building | R | `obj.homeBuilding` |
| faction | faction | Faction | R | `obj.faction` |
| data | data | GameData | R | `obj.data` |
| position | position | Vector3 | RW | `obj.position = <value>` |
| isFromActiveLevelMod | isFromActiveLevelMod | boolean | RW | `obj.isFromActiveLevelMod = <value>` |
| rotation | rotation | Quaternion | RW | `obj.rotation = <value>` |
| callbackObject | callbackObject | FactoryCallbackInterface* | R | `obj.callbackObject` |
| saveState | saveState | GameSaveState* | R | `obj.saveState` |
| age | age | number | RW | `obj.age = <value>` |

## Crossbow
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| gunClass | gunClass | GunClass* | R | `obj.gunClass` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isCrossbow | isCrossbow | `obj:isCrossbow(...)` |
| _NV_isCrossbow | _NV_isCrossbow | `obj:_NV_isCrossbow(...)` |
| getClassType | getClassType | `obj:getClassType(...)` |
| _NV_getClassType | _NV_getClassType | `obj:_NV_getClassType(...)` |
| getCraftMaterialMult | getCraftMaterialMult | `obj:getCraftMaterialMult(...)` |
| _NV_getCraftMaterialMult | _NV_getCraftMaterialMult | `obj:_NV_getCraftMaterialMult(...)` |
| getCraftTime | getCraftTime | `obj:getCraftTime(...)` |
| _NV_getCraftTime | _NV_getCraftTime | `obj:_NV_getCraftTime(...)` |
| getRangeInUnits | getRangeInUnits | `obj:getRangeInUnits(...)` |
| getEquipPositionOffset | getEquipPositionOffset | `obj:getEquipPositionOffset(...)` |
| destroyItemEntityCallback_Equipping | destroyItemEntityCallback_Equipping | `obj:destroyItemEntityCallback_Equipping(...)` |
| _NV_destroyItemEntityCallback_Equipping | _NV_destroyItemEntityCallback_Equipping | `obj:_NV_destroyItemEntityCallback_Equipping(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| _NV_setVisible | _NV_setVisible | `obj:_NV_setVisible(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Damages
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| cut | cut | number | RW | `obj.cut = <value>` |
| blunt | blunt | number | RW | `obj.blunt = <value>` |
| pierce | pierce | number | RW | `obj.pierce = <value>` |
| extraStun | extraStun | number | RW | `obj.extraStun = <value>` |
| bleedMult | bleedMult | number | RW | `obj.bleedMult = <value>` |
| armourPenetration | armourPenetration | number | RW | `obj.armourPenetration = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| multiply | multiply | `obj:multiply(...)` |
| total | total | `obj:total(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## DataObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isStored | isStored | boolean | RW | `obj.isStored = <value>` |
| objectDatas | objectDatas | GameDataContainer* | R | `obj.objectDatas` |
| datasFile | datasFile | string | RW | `obj.datasFile = <value>` |
| selfType | (lua_Integer | integer | RW | `obj.selfType = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getType | getType | `obj:getType(...)` |
| destroyObjectDatas | destroyObjectDatas | `obj:destroyObjectDatas(...)` |

## DelayedSpawnMsg
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| parentTown | parentTown | hand | RW | `obj.parentTown = <value>` |
| item | item | Item | R | `obj.item` |
| nestData | nestData | GameData | R | `obj.nestData` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| insideBuilding | insideBuilding | hand | RW | `obj.insideBuilding = <value>` |

## DialogAction
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| key | key | DialogActionEnum | R | `obj.key` |
| value | value | integer | RW | `obj.value = <value>` |

## DialogChoiceList
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| conversationChoices | conversationChoices | lektor<DialogLineData*> | R | `obj.conversationChoices` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## DialogCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| key | (lua_Integer | integer | RW | `obj.key = <value>` |
| compareBy | (lua_Integer | integer | RW | `obj.compareBy = <value>` |
| who | (lua_Integer | integer | RW | `obj.who = <value>` |
| value | value | integer | RW | `obj.value = <value>` |

## DialogDataManager
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

## DialogLineData
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| targetFlagsNeeded | targetFlagsNeeded | integer | RW | `obj.targetFlagsNeeded = <value>` |
| targetFlagsNotWanted | targetFlagsNotWanted | integer | RW | `obj.targetFlagsNotWanted = <value>` |
| personalityNeeded | personalityNeeded | integer | RW | `obj.personalityNeeded = <value>` |
| personalityNotWanted | personalityNotWanted | integer | RW | `obj.personalityNotWanted = <value>` |
| campaignTriggers | campaignTriggers | FitnessSelector<CampaignTriggerData*> | R | `obj.campaignTriggers` |
| isTargetRace | isTargetRace | lektor<GameData*> | R | `obj.isTargetRace` |
| isTargetSubRace_specificallyTheTarget | isTargetSubRace_specificallyTheTarget | lektor<GameData*> | R | `obj.isTargetSubRace_specificallyTheTarget` |
| givesItem | givesItem | lektor<GameDataValuePair> | R | `obj.givesItem` |
| inTownOf | inTownOf | std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > | R | `obj.inTownOf` |
| isTargetFaction | isTargetFaction | std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > | R | `obj.isTargetFaction` |
| isMyFaction | isMyFaction | std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > | R | `obj.isMyFaction` |
| isCharacter | isCharacter | GameData | R | `obj.isCharacter` |
| isTargetCarryingCharacter | isTargetCarryingCharacter | GameData | R | `obj.isTargetCarryingCharacter` |
| _hasPackage | _hasPackage | GameData | R | `obj._hasPackage` |
| isMyRace | isMyRace | GameData | R | `obj.isMyRace` |
| isMySubRace | isMySubRace | GameData | R | `obj.isMySubRace` |
| hasItemType | (lua_Integer | integer | RW | `obj.hasItemType = <value>` |
| hasItem | hasItem | lektor<GameData*> | R | `obj.hasItem` |
| worldState | worldState | WorldEventStateQueryList* | R | `obj.worldState` |
| data | data | GameData | R | `obj.data` |
| onceOnly | onceOnly | boolean | RW | `obj.onceOnly = <value>` |
| isMonologue | isMonologue | boolean | RW | `obj.isMonologue = <value>` |
| forCertainType | forCertainType | CharacterTypeEnum | R | `obj.forCertainType` |
| children | children | DialogChoiceList | R | `obj.children` |
| conditions | conditions | lektor<DialogLineData::DialogCondition*> | R | `obj.conditions` |
| actions | actions | lektor<DialogLineData::DialogAction*> | R | `obj.actions` |
| lineCount | lineCount | integer | RW | `obj.lineCount = <value>` |
| texts | texts | string | R | `obj.texts` |
| parent | parent | DialogLineData* | R | `obj.parent` |
| chancePermanent | chancePermanent | number | RW | `obj.chancePermanent = <value>` |
| chanceTemporary | chanceTemporary | number | RW | `obj.chanceTemporary = <value>` |
| unique | unique | boolean | RW | `obj.unique = <value>` |
| uniqueOwner | uniqueOwner | hand | R | `obj.uniqueOwner` |
| dialogRepeatMinTimeInHours | dialogRepeatMinTimeInHours | number | RW | `obj.dialogRepeatMinTimeInHours = <value>` |
| lastTimeSaid | lastTimeSaid | TimeOfDay | R | `obj.lastTimeSaid` |
| score | score | integer | RW | `obj.score = <value>` |
| oneAtATime | oneAtATime | boolean | RW | `obj.oneAtATime = <value>` |
| isLocked | isLocked | boolean | RW | `obj.isLocked = <value>` |
| locks | locks | lektor<DialogLineData*> | R | `obj.locks` |
| unlocks_lockMe | unlocks_lockMe | lektor<DialogLineData*> | R | `obj.unlocks_lockMe` |
| unlocks_dontLockMe | unlocks_dontLockMe | lektor<DialogLineData*> | R | `obj.unlocks_dontLockMe` |
| crowdTrigger | crowdTrigger | DialogLineData* | R | `obj.crowdTrigger` |
| factionRelationEffects | factionRelationEffects | ogre_unordered_map<GameData*, int>::type | R | `obj.factionRelationEffects` |
| playerInterruptionDialog | playerInterruptionDialog | DialogLineData* | R | `obj.playerInterruptionDialog` |
| isInterjection | isInterjection | boolean | RW | `obj.isInterjection = <value>` |
| speaker | speaker | TalkerEnum | R | `obj.speaker` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| hasSpecificCharacterRequirement | hasSpecificCharacterRequirement | `obj:hasSpecificCharacterRequirement(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| setupChildren | setupChildren | `obj:setupChildren(...)` |
| checkRepeatLimits | checkRepeatLimits | `obj:checkRepeatLimits(...)` |
| getName | getName | `obj:getName(...)` |
| saidItBefore | saidItBefore | `obj:saidItBefore(...)` |
| willTalkToEnemies | willTalkToEnemies | `obj:willTalkToEnemies(...)` |
| isEmptyNode | isEmptyNode | `obj:isEmptyNode(...)` |
| _NV_isEmptyNode | _NV_isEmptyNode | `obj:_NV_isEmptyNode(...)` |
| isAnnouncement | isAnnouncement | `obj:isAnnouncement(...)` |
| stampLastTimeSaid | stampLastTimeSaid | `obj:stampLastTimeSaid(...)` |
| hasChildren | hasChildren | `obj:hasChildren(...)` |
| getStringID | getStringID | `obj:getStringID(...)` |
| getGameData | getGameData | `obj:getGameData(...)` |
| getMoneyCostForLine | getMoneyCostForLine | `obj:getMoneyCostForLine(...)` |

## DialogState
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| count | count | integer | RW | `obj.count = <value>` |
| lastTimeStamp | lastTimeStamp | number | RW | `obj.lastTimeStamp = <value>` |
| resetTime | resetTime | number | RW | `obj.resetTime = <value>` |

## Dialogue
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| repCounter | repCounter | RepetitionCounter | RW | `obj.repCounter = <value>` |
| _needsDynamicAssessments | _needsDynamicAssessments | boolean | RW | `obj._needsDynamicAssessments = <value>` |
| locked | locked | std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > > | R | `obj.locked` |
| sayMsg | sayMsg | string | RW | `obj.sayMsg = <value>` |
| threadMessages | threadMessages | Ogre::vector<Dialogue::DT_MSG>::type | R | `obj.threadMessages` |
| pacakgesIHave | pacakgesIHave | std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > > | R | `obj.pacakgesIHave` |
| playerInterruptionDialog | playerInterruptionDialog | DialogLineData* | R | `obj.playerInterruptionDialog` |
| eventRepeatTimers | eventRepeatTimers | std::map<EventTriggerEnum, float, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, float>, Ogre::GeneralAllocPolicy > > | R | `obj.eventRepeatTimers` |
| eventDeliveredStates | eventDeliveredStates | std::map<EventTriggerEnum, hand, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, hand>, Ogre::GeneralAllocPolicy > > | R | `obj.eventDeliveredStates` |
| _hasChanceLines | _hasChanceLines | std::map<DialogLineData*, bool, std::less<DialogLineData*>, Ogre::STLAllocator<std::pair<DialogLineData*const, bool>, Ogre::GeneralAllocPolicy > > | R | `obj._hasChanceLines` |
| _hasEnded | _hasEnded | boolean | RW | `obj._hasEnded = <value>` |
| shouting | shouting | boolean | RW | `obj.shouting = <value>` |
| staysOnScreen | staysOnScreen | boolean | RW | `obj.staysOnScreen = <value>` |
| me | me | Character | R | `obj.me` |
| conversationTarget | conversationTarget | hand | RW | `obj.conversationTarget = <value>` |
| stats | stats | CharStats | R | `obj.stats` |
| movement | movement | CharMovement* | R | `obj.movement` |
| currentConversationType | (lua_Integer | integer | RW | `obj.currentConversationType = <value>` |
| currentConversation | currentConversation | DialogLineData* | R | `obj.currentConversation` |
| currentLine | currentLine | DialogLineData* | R | `obj.currentLine` |
| conversationsMain | conversationsMain | std::map<EventTriggerEnum, DialogChoiceList*, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, DialogChoiceList*>, Ogre::GeneralAllocPolicy > > | R | `obj.conversationsMain` |
| interjector1 | interjector1 | hand | RW | `obj.interjector1 = <value>` |
| interjector2 | interjector2 | hand | RW | `obj.interjector2 = <value>` |
| interjector3 | interjector3 | hand | RW | `obj.interjector3 = <value>` |
| speechBubblePanel | speechBubblePanel | DialogueSpeechBubble* | R | `obj.speechBubblePanel` |
| speechTextTimer | speechTextTimer | number | RW | `obj.speechTextTimer = <value>` |
| speechTextTimer_forced | speechTextTimer_forced | number | RW | `obj.speechTextTimer_forced = <value>` |
| replyIds | replyIds | Ogre::vector<std::string>::type | R | `obj.replyIds` |
| responses | responses | Ogre::vector<std::string>::type | R | `obj.responses` |
| npcReplyText | npcReplyText | string | RW | `obj.npcReplyText = <value>` |
| conversationMaster | conversationMaster | hand | RW | `obj.conversationMaster = <value>` |
| waitingForReplyFrom | waitingForReplyFrom | hand | RW | `obj.waitingForReplyFrom = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| setupWordSwaps | setupWordSwaps | `obj:setupWordSwaps(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| getConversationTarget | getConversationTarget | `obj:getConversationTarget(...)` |
| setInDialog | setInDialog | `obj:setInDialog(...)` |
| clearDialogues | clearDialogues | `obj:clearDialogues(...)` |
| clearAnnouncements | clearAnnouncements | `obj:clearAnnouncements(...)` |
| needsDialogAssessmentUpdate | needsDialogAssessmentUpdate | `obj:needsDialogAssessmentUpdate(...)` |
| clearConversationList | clearConversationList | `obj:clearConversationList(...)` |
| willTalkToEnemies | willTalkToEnemies | `obj:willTalkToEnemies(...)` |
| stopEvent | stopEvent | `obj:stopEvent(...)` |
| conversationHasEnded | conversationHasEnded | `obj:conversationHasEnded(...)` |
| conversationHasEndedPrettyMuch | conversationHasEndedPrettyMuch | `obj:conversationHasEndedPrettyMuch(...)` |
| update | update | `obj:update(...)` |
| endDialogue | endDialogue | `obj:endDialogue(...)` |
| hasDialogue_Fast | hasDialogue_Fast | `obj:hasDialogue_Fast(...)` |
| hasDialogue_Accurate | hasDialogue_Accurate | `obj:hasDialogue_Accurate(...)` |
| hasDialogueEvent | hasDialogueEvent | `obj:hasDialogueEvent(...)` |
| dialogDelivered | dialogDelivered | `obj:dialogDelivered(...)` |
| isKOExempt | isKOExempt | `obj:isKOExempt(...)` |
| _endPlayerConversation | _endPlayerConversation | `obj:_endPlayerConversation(...)` |
| getConversationList | getConversationList | `obj:getConversationList(...)` |
| listPlayerReplies | listPlayerReplies | `obj:listPlayerReplies(...)` |
| _updateTextPos | _updateTextPos | `obj:_updateTextPos(...)` |
| clearSpeechBox | clearSpeechBox | `obj:clearSpeechBox(...)` |
| clearRespones | clearRespones | `obj:clearRespones(...)` |
| clearResponesGUI | clearResponesGUI | `obj:clearResponesGUI(...)` |
| setResponesGUI | setResponesGUI | `obj:setResponesGUI(...)` |
| setConversationReplyGUI | setConversationReplyGUI | `obj:setConversationReplyGUI(...)` |
| getHandle | Dialogue_getHandle | `obj:getHandle(...)` |
| getConversationTarget | Dialogue_getConversationTarget | `obj:getConversationTarget(...)` |
| getSpeaker | Dialogue_getSpeaker | `obj:getSpeaker(...)` |
| findInterjectionCharacter | Dialogue_findInterjectionCharacter | `obj:findInterjectionCharacter(...)` |

## DialogueSpeechBubble
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| stayOnScreen | stayOnScreen | boolean | RW | `obj.stayOnScreen = <value>` |
| shout | shout | boolean | RW | `obj.shout = <value>` |
| marginW | marginW | integer | RW | `obj.marginW = <value>` |
| marginH | marginH | integer | RW | `obj.marginH = <value>` |
| textBox | (lua_Integer | integer | R | `obj.textBox` |
| baseSize | baseSize | MyGUI::types::TSize<int> | R | `obj.baseSize` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| setText | setText | `obj:setText(...)` |
| setAlpha | setAlpha | `obj:setAlpha(...)` |
| reset | reset | `obj:reset(...)` |
| getAlpha | getAlpha | `obj:getAlpha(...)` |

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _antiSlavery | _antiSlavery | boolean | RW | `obj._antiSlavery = <value>` |
| characteristicsData | characteristicsData | Faction::CharacteristicsData | R | `obj.characteristicsData` |
| ranks | ranks | lektor<std::string > | R | `obj.ranks` |
| allowSlavesWeapons | allowSlavesWeapons | boolean | RW | `obj.allowSlavesWeapons = <value>` |
| fundamentalNPCType | fundamentalNPCType | CharacterTypeEnum | R | `obj.fundamentalNPCType` |
| myLawEnforcementFaction | myLawEnforcementFaction | Faction | R | `obj.myLawEnforcementFaction` |
| isALawEnforcementFaction | isALawEnforcementFaction | boolean | RW | `obj.isALawEnforcementFaction = <value>` |
| factionLeader | factionLeader | FactionLeader | R | `obj.factionLeader` |
| diplomatMgr | diplomatMgr | FactionUniqueSquadManager* | R | `obj.diplomatMgr` |
| relations | relations | FactionRelations* | R | `obj.relations` |
| factionOwnerships | factionOwnerships | Ownerships | R | `obj.factionOwnerships` |
| warMgr | warMgr | FactionWarMgr* | R | `obj.warMgr` |
| tradeCulture | tradeCulture | TradeCulture | R | `obj.tradeCulture` |
| raceSelector | raceSelector | FitnessSelector<GameData*> | R | `obj.raceSelector` |
| name | name | string | RW | `obj.name = <value>` |
| notARealFaction | notARealFaction | boolean | RW | `obj.notARealFaction = <value>` |
| roadPreference | roadPreference | number | RW | `obj.roadPreference = <value>` |
| platoonKillList | platoonKillList | Platoon | R | `obj.platoonKillList` |
| platoonRemoveList | platoonRemoveList | Platoon | R | `obj.platoonRemoveList` |
| activePlatoons | activePlatoons | Platoon | R | `obj.activePlatoons` |
| unloadedPlatoons | unloadedPlatoons | Platoon | R | `obj.unloadedPlatoons` |
| periodicUpdateCounter_active | periodicUpdateCounter_active | integer | RW | `obj.periodicUpdateCounter_active = <value>` |
| periodicUpdateCounter_unloaded | periodicUpdateCounter_unloaded | integer | RW | `obj.periodicUpdateCounter_unloaded = <value>` |
| data | data | GameData | R | `obj.data` |
| isAI | isAI | AIPlayer* | R | `obj.isAI` |
| isPlayer | isPlayer | PlayerInterface | R | `obj.isPlayer` |
| spawnTimeStamp | spawnTimeStamp | integer | RW | `obj.spawnTimeStamp = <value>` |
| diplomatTimeStamp | diplomatTimeStamp | integer | RW | `obj.diplomatTimeStamp = <value>` |
| platoonIDs | platoonIDs | integer | RW | `obj.platoonIDs = <value>` |
| p_TIME | p_TIME | number | RW | `obj.p_TIME = <value>` |
| platoonPeriodicUpdateIndex | platoonPeriodicUpdateIndex | integer | RW | `obj.platoonPeriodicUpdateIndex = <value>` |
| buildingSwaps | buildingSwaps | lektor<Faction::BuildingSwaps> | R | `obj.buildingSwaps` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getProsperityMultiplier | getProsperityMultiplier | `obj:getProsperityMultiplier(...)` |
| clearAndDestroy | clearAndDestroy | `obj:clearAndDestroy(...)` |
| setup2 | setup2 | `obj:setup2(...)` |
| setup3 | setup3 | `obj:setup3(...)` |
| getNewPlatoonID | getNewPlatoonID | `obj:getNewPlatoonID(...)` |
| resetPlatoonID | resetPlatoonID | `obj:resetPlatoonID(...)` |
| createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | `obj:createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(...)` |
| resetSquadPositions | resetSquadPositions | `obj:resetSquadPositions(...)` |
| getData | getData | `obj:getData(...)` |
| getDefaultDivision | getDefaultDivision | `obj:getDefaultDivision(...)` |
| getFactionColorScheme | getFactionColorScheme | `obj:getFactionColorScheme(...)` |
| _activateUnloadedPlatoons | _activateUnloadedPlatoons | `obj:_activateUnloadedPlatoons(...)` |
| processKillList | processKillList | `obj:processKillList(...)` |
| _NV_processKillList | _NV_processKillList | `obj:_NV_processKillList(...)` |
| getFactionSize | getFactionSize | `obj:getFactionSize(...)` |
| update | update | `obj:update(...)` |
| periodicUpdateThreaded | periodicUpdateThreaded | `obj:periodicUpdateThreaded(...)` |
| periodicUpdateMT | periodicUpdateMT | `obj:periodicUpdateMT(...)` |
| isThePlayer | isThePlayer | `obj:isThePlayer(...)` |
| isNotARealFaction | isNotARealFaction | `obj:isNotARealFaction(...)` |
| getRoadPreference | getRoadPreference | `obj:getRoadPreference(...)` |
| isAntiSlavery | isAntiSlavery | `obj:isAntiSlavery(...)` |
| getLawEnforcementFaction | getLawEnforcementFaction | `obj:getLawEnforcementFaction(...)` |
| setName | setName | `obj:setName(...)` |
| updateUnloadedPlatoons | updateUnloadedPlatoons | `obj:updateUnloadedPlatoons(...)` |
| updateActivePlatoons | updateActivePlatoons | `obj:updateActivePlatoons(...)` |
| spawnSquadMissionsUpdate | spawnSquadMissionsUpdate | `obj:spawnSquadMissionsUpdate(...)` |
| _spawnASquad | _spawnASquad | `obj:_spawnASquad(...)` |
| getSquadThatOwns | Faction_getSquadThatOwns | `obj:getSquadThatOwns(...)` |
| getActivePlatoons | Faction_getActivePlatoons_method | `obj:getActivePlatoons(...)` |
| getUnloadedPlatoons | Faction_getUnloadedPlatoons_method | `obj:getUnloadedPlatoons(...)` |
| getAllActiveSquads | Faction_getAllActiveSquads | `obj:getAllActiveSquads(...)` |

## FactionLeader
**Header:** `extern/KenshiLib/Include/kenshi/FactionLeader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| faction | faction | Faction | R | `obj.faction` |
| biomeTerritory | biomeTerritory | lektor<GameData*> | R | `obj.biomeTerritory` |
| worstEnemy | worstEnemy | Faction | R | `obj.worstEnemy` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## FactionManager
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| participants | participants | Faction | R | `obj.participants` |
| addListMuto | addListMuto | unknown | R | `obj.addListMuto` |
| toAddList | toAddList | Platoon | R | `obj.toAddList` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| clearAndDestroy | clearAndDestroy | `obj:clearAndDestroy(...)` |
| activateUnloadedPlatoons | activateUnloadedPlatoons | `obj:activateUnloadedPlatoons(...)` |
| getFactionByName | getFactionByName | `obj:getFactionByName(...)` |
| getFactionByStringID | getFactionByStringID | `obj:getFactionByStringID(...)` |
| getEmptyFaction | getEmptyFaction | `obj:getEmptyFaction(...)` |
| setupAndLinkAllFactions | setupAndLinkAllFactions | `obj:setupAndLinkAllFactions(...)` |
| areAnyHostileCampaignsRunning | areAnyHostileCampaignsRunning | `obj:areAnyHostileCampaignsRunning(...)` |
| getNumTempPlatoons | getNumTempPlatoons | `obj:getNumTempPlatoons(...)` |
| updateMT | updateMT | `obj:updateMT(...)` |
| updateThreaded | updateThreaded | `obj:updateThreaded(...)` |
| _showDebugPlatoonMarkers | _showDebugPlatoonMarkers | `obj:_showDebugPlatoonMarkers(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getFactionBySquad | FactionManager_getFactionBySquad | `obj:getFactionBySquad(...)` |
| getAllFactions | FactionManager_getAllFactions | `obj:getAllFactions(...)` |

## FactionRelations
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Faction | R | `obj.me` |
| playerRank | playerRank | integer | RW | `obj.playerRank = <value>` |
| globalReputationTrust | globalReputationTrust | number | RW | `obj.globalReputationTrust = <value>` |
| globalReputationForBadassery | globalReputationForBadassery | number | RW | `obj.globalReputationForBadassery = <value>` |
| _factionRelations | _factionRelations | ogre_unordered_map<Faction*, RelationData>::type | R | `obj._factionRelations` |
| defaultFactionRelation | defaultFactionRelation | number | RW | `obj.defaultFactionRelation = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| setupPhase2 | setupPhase2 | `obj:setupPhase2(...)` |
| isEnemyByDefault | isEnemyByDefault | `obj:isEnemyByDefault(...)` |
| reset | reset | `obj:reset(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## FactoryCallbackInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

## FlagCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| key | (lua_Integer | integer | RW | `obj.key = <value>` |
| want | want | boolean | RW | `obj.want = <value>` |
| flags | flags | integer | RW | `obj.flags = <value>` |

## FlockingTools
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| getOutOfTheWayOfCharacter | getOutOfTheWayOfCharacter | hand | R | `obj.getOutOfTheWayOfCharacter` |
| currentPosition | currentPosition | Vector3 | RW | `obj.currentPosition = <value>` |
| me | me | Character | R | `obj.me` |
| combatMover | combatMover | CombatMovementController* | R | `obj.combatMover` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| setCurrentPosition | setCurrentPosition | `obj:setCurrentPosition(...)` |

## FormationMover
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Character | R | `obj.me` |
| destination | destination | Vector3 | RW | `obj.destination = <value>` |
| direction | direction | Vector3 | RW | `obj.direction = <value>` |
| movementTarget | movementTarget | hand | RW | `obj.movementTarget = <value>` |
| currentFormationID | currentFormationID | integer | RW | `obj.currentFormationID = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| update | update | `obj:update(...)` |
| stopFormationMode | stopFormationMode | `obj:stopFormationMode(...)` |

## GameData
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| validity | validity | integer | RW | `obj.validity = <value>` |
| sourceContainer | sourceContainer | GameDataContainer* | R | `obj.sourceContainer` |
| isStandalone | isStandalone | boolean | RW | `obj.isStandalone = <value>` |
| id | id | integer | RW | `obj.id = <value>` |
| readOnly | readOnly | boolean | RW | `obj.readOnly = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| type | (lua_Integer | integer | RW | `obj.type = <value>` |
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| isFromActiveFile | isFromActiveFile | boolean | RW | `obj.isFromActiveFile = <value>` |
| instances | instances | std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > > | R | `obj.instances` |
| currentID | currentID | integer | RW | `obj.currentID = <value>` |
| activeValues | activeValues | boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > | R | `obj.activeValues` |
| bdata | bdata | boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > | R | `obj.bdata` |
| sdata | sdata | boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > | R | `obj.sdata` |
| idata | idata | boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > | R | `obj.idata` |
| fdata | fdata | boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > | R | `obj.fdata` |
| filesdata | filesdata | boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > | R | `obj.filesdata` |
| vecdata | vecdata | boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > > | R | `obj.vecdata` |
| quatdata | quatdata | boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > > | R | `obj.quatdata` |
| objectReferences | objectReferences | boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > > | R | `obj.objectReferences` |
| createdIndex | createdIndex | integer | RW | `obj.createdIndex = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| isValid | isValid | `obj:isValid(...)` |
| destroy | destroy | `obj:destroy(...)` |
| initialise | initialise | `obj:initialise(...)` |
| loadFromFile | loadFromFile | `obj:loadFromFile(...)` |
| saveToFile | saveToFile | `obj:saveToFile(...)` |
| isValueActive | isValueActive | `obj:isValueActive(...)` |
| isRefActive | isRefActive | `obj:isRefActive(...)` |
| addFileName | addFileName | `obj:addFileName(...)` |
| addString | addString | `obj:addString(...)` |
| addToList | addToList | `obj:addToList(...)` |
| findInList | findInList | `obj:findInList(...)` |
| clearList | clearList | `obj:clearList(...)` |
| clearEverything | clearEverything | `obj:clearEverything(...)` |
| clearInstances | clearInstances | `obj:clearInstances(...)` |
| getListSize | getListSize | `obj:getListSize(...)` |
| listExists | listExists | `obj:listExists(...)` |
| listExistsAndNotEmpty | listExistsAndNotEmpty | `obj:listExistsAndNotEmpty(...)` |
| deleteInstancedObject | deleteInstancedObject | `obj:deleteInstancedObject(...)` |
| getNewID | getNewID | `obj:getNewID(...)` |
| getColorVec | getColorVec | `obj:getColorVec(...)` |
| addDeletedInstance | addDeletedInstance | `obj:addDeletedInstance(...)` |

## GameDataContainer
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentID | currentID | integer | RW | `obj.currentID = <value>` |
| gamedataCatName | gamedataCatName | boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > | R | `obj.gamedataCatName` |
| gamedataID | gamedataID | ogre_unordered_map<int, GameData*>::type | R | `obj.gamedataID` |
| gamedataCatSID | gamedataCatSID | boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > | R | `obj.gamedataCatSID` |
| gamedataSID | gamedataSID | boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > | R | `obj.gamedataSID` |
| mainList | mainList | ogre_unordered_set<GameData*>::type | R | `obj.mainList` |
| name | name | string | RW | `obj.name = <value>` |
| isBaseDatafile | isBaseDatafile | boolean | RW | `obj.isBaseDatafile = <value>` |
| readOnly | readOnly | boolean | RW | `obj.readOnly = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| createNewData | createNewData | `obj:createNewData(...)` |
| getDataByName | getDataByName | `obj:getDataByName(...)` |
| removeAllDataOfType | removeAllDataOfType | `obj:removeAllDataOfType(...)` |
| clearInstances | clearInstances | `obj:clearInstances(...)` |
| clearButDontDestroy | clearButDontDestroy | `obj:clearButDontDestroy(...)` |
| clearButDontDestroyPlatoons | clearButDontDestroyPlatoons | `obj:clearButDontDestroyPlatoons(...)` |
| clearAndDestroy | clearAndDestroy | `obj:clearAndDestroy(...)` |
| getNewID | getNewID | `obj:getNewID(...)` |
| preLoadAllReferencePtrs | preLoadAllReferencePtrs | `obj:preLoadAllReferencePtrs(...)` |
| clearAllReferencePtrs | clearAllReferencePtrs | `obj:clearAllReferencePtrs(...)` |
| setName | setName | `obj:setName(...)` |

## GameDataCopyStandalone
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## GameDataHeader
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |
| author | author | string | RW | `obj.author = <value>` |
| version | version | integer | RW | `obj.version = <value>` |
| description | description | string | RW | `obj.description = <value>` |
| dependencies | dependencies | lektor<std::string > | R | `obj.dependencies` |
| references | references | lektor<std::string > | R | `obj.references` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## GameDataManager
**Header:** `extern/KenshiLib/Include/kenshi/GameDataManager.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| reloadGameData | reloadGameData | `obj:reloadGameData(...)` |
| postProcessingTheDatas | postProcessingTheDatas | `obj:postProcessingTheDatas(...)` |
| getMapSector | getMapSector | `obj:getMapSector(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## GameDataReference
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| values | values | TripleInt | R | `obj.values` |
| sid | sid | string | RW | `obj.sid = <value>` |
| ptr | ptr | GameData | R | `obj.ptr` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## GameDataValuePair
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | R | `obj.data` |
| val0 | val0 | integer | RW | `obj.val0 = <value>` |

## GameSaveState
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| baseData | baseData | GameData | R | `obj.baseData` |
| dataSource | (void* | lightuserdata | R | `obj.dataSource` |
| firstTime | firstTime | boolean | RW | `obj.firstTime = <value>` |
| instance | (void* | lightuserdata | R | `obj.instance` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |
| instanceID | instanceID | string | RW | `obj.instanceID = <value>` |
| states | states | ogre_unordered_map<itemType, GameData*>::type | R | `obj.states` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| generateNewInstanceID | generateNewInstanceID | `obj:generateNewInstanceID(...)` |
| generateStateID | generateStateID | `obj:generateStateID(...)` |
| createState | createState | `obj:createState(...)` |
| hasState | hasState | `obj:hasState(...)` |
| getState | getState | `obj:getState(...)` |
| numStates | numStates | `obj:numStates(...)` |
| getPos | getPos | `obj:getPos(...)` |
| getRot | getRot | `obj:getRot(...)` |
| getTheInstancesData | getTheInstancesData | `obj:getTheInstancesData(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## GameWorld
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| tempSpawnsDisableTimer | tempSpawnsDisableTimer | number | RW | `obj.tempSpawnsDisableTimer = <value>` |
| initialized | initialized | boolean | RW | `obj.initialized = <value>` |
| render | render | RendererT* | R | `obj.render` |
| physics | physics | PhysicsInterface* | R | `obj.physics` |
| gamedata | gamedata | GameDataManager | R | `obj.gamedata` |
| leveldata | leveldata | GameDataManager | R | `obj.leveldata` |
| savedata | savedata | GameDataManager | R | `obj.savedata` |
| theFactory | theFactory | RootObjectFactory* | R | `obj.theFactory` |
| factionMgr | factionMgr | FactionManager* | R | `obj.factionMgr` |
| navmesh | navmesh | NavMesh* | R | `obj.navmesh` |
| nodeList | nodeList | NodeList* | R | `obj.nodeList` |
| guiDisplayObject | guiDisplayObject | hand | RW | `obj.guiDisplayObject = <value>` |
| messageRoller | messageRoller | MessageRoller* | R | `obj.messageRoller` |
| ogreLogger | ogreLogger | Ogre::Log* | R | `obj.ogreLogger` |
| steamEnabled | steamEnabled | boolean | RW | `obj.steamEnabled = <value>` |
| baseMods | baseMods | lektor<ModInfo> | R | `obj.baseMods` |
| baseModsNames | baseModsNames | lektor<std::string> | R | `obj.baseModsNames` |
| activeMods | activeMods | lektor<ModInfo*> | R | `obj.activeMods` |
| availableModsByName | availableModsByName | std::map<std::string, ModInfo, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, ModInfo>, Ogre::GeneralAllocPolicy > > | R | `obj.availableModsByName` |
| availabelModsOrderedList | availabelModsOrderedList | lektor<ModInfo*> | R | `obj.availabelModsOrderedList` |
| player | player | PlayerInterface | R | `obj.player` |
| charactersWithLights | charactersWithLights | ogre_unordered_set<Character*>::type | R | `obj.charactersWithLights` |
| sysMessageList | sysMessageList | std::list<GameWorld::SysMessage, Ogre::STLAllocator<GameWorld::SysMessage, Ogre::GeneralAllocPolicy > > | R | `obj.sysMessageList` |
| updatePortraitsMap | updatePortraitsMap | ogre_unordered_map<hand, float>::type | R | `obj.updatePortraitsMap` |
| dynamicDestroyBuildingsList | dynamicDestroyBuildingsList | lektor<hand> | R | `obj.dynamicDestroyBuildingsList` |
| destroyListAE | destroyListAE | ogre_unordered_set<AttachedEntity*>::type | R | `obj.destroyListAE` |
| destroyListOE | destroyListOE | ogre_unordered_set<Ogre::MovableObject*>::type | R | `obj.destroyListOE` |
| destroyListTBM | destroyListTBM | ogre_unordered_set<TownBuildingsManager*>::type | R | `obj.destroyListTBM` |
| frameSpeedMult | frameSpeedMult | number | RW | `obj.frameSpeedMult = <value>` |
| deathParade | deathParade | ogre_unordered_map<hand, Character*>::type | R | `obj.deathParade` |
| deathParadeWasMeddledWith | deathParadeWasMeddledWith | boolean | RW | `obj.deathParadeWasMeddledWith = <value>` |
| charUpdateListMain_inUse | charUpdateListMain_inUse | boolean | RW | `obj.charUpdateListMain_inUse = <value>` |
| charUpdateListMain | charUpdateListMain | ogre_unordered_set<Character*>::type | R | `obj.charUpdateListMain` |
| _AINonRenderThread | _AINonRenderThread | RenderTimeBackthread* | R | `obj._AINonRenderThread` |
| nestBatcherKillList | nestBatcherKillList | std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy > > | R | `obj.nestBatcherKillList` |
| killListPhase0 | killListPhase0 | ogre_unordered_set<RootObject*>::type | R | `obj.killListPhase0` |
| killListPhase1 | killListPhase1 | ogre_unordered_map<RootObject*, float>::type | R | `obj.killListPhase1` |
| killListPhase2 | killListPhase2 | std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy > > | R | `obj.killListPhase2` |
| mainUpdateListRemovalQueue | mainUpdateListRemovalQueue | lektor<Character*> | R | `obj.mainUpdateListRemovalQueue` |
| timeStamper | timeStamper | SimpleTimeStamper | R | `obj.timeStamper` |
| zoneMgr | zoneMgr | ZoneManager* | R | `obj.zoneMgr` |
| debugFlag | debugFlag | boolean | RW | `obj.debugFlag = <value>` |
| paused | paused | boolean | RW | `obj.paused = <value>` |
| gameResetting | gameResetting | boolean | RW | `obj.gameResetting = <value>` |
| audioThread | audioThread | AudioSystemGlobal* | R | `obj.audioThread` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| startUpThreads | startUpThreads | `obj:startUpThreads(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| resetGame | resetGame | `obj:resetGame(...)` |
| _clearAndDestroyGameWorldStuff | _clearAndDestroyGameWorldStuff | `obj:_clearAndDestroyGameWorldStuff(...)` |
| initialisation | initialisation | `obj:initialisation(...)` |
| initialisationGameData | initialisationGameData | `obj:initialisationGameData(...)` |
| dailyUpdates | dailyUpdates | `obj:dailyUpdates(...)` |
| errorToLogReleaseMode | errorToLogReleaseMode | `obj:errorToLogReleaseMode(...)` |
| errorD | errorD | `obj:errorD(...)` |
| logToSave | logToSave | `obj:logToSave(...)` |
| log | log | `obj:log(...)` |
| flushKillList | flushKillList | `obj:flushKillList(...)` |
| allThreadQueuesAreClear | allThreadQueuesAreClear | `obj:allThreadQueuesAreClear(...)` |
| initBaseMods | initBaseMods | `obj:initBaseMods(...)` |
| initModsList | initModsList | `obj:initModsList(...)` |
| getModIndex | getModIndex | `obj:getModIndex(...)` |
| getLightLevel | getLightLevel | `obj:getLightLevel(...)` |
| findValidSpawnPos | findValidSpawnPos | `obj:findValidSpawnPos(...)` |
| togglePause | togglePause | `obj:togglePause(...)` |
| getFrameSpeedMultiplier | getFrameSpeedMultiplier | `obj:getFrameSpeedMultiplier(...)` |
| setFrameSpeedMultiplier | setFrameSpeedMultiplier | `obj:setFrameSpeedMultiplier(...)` |
| setGameSpeed | setGameSpeed | `obj:setGameSpeed(...)` |
| userPause | userPause | `obj:userPause(...)` |
| isPaused | isPaused | `obj:isPaused(...)` |
| getCameraCenter | getCameraCenter | `obj:getCameraCenter(...)` |
| getCameraPos | getCameraPos | `obj:getCameraPos(...)` |
| fixNaNPosition | fixNaNPosition | `obj:fixNaNPosition(...)` |
| getWindSpeed | getWindSpeed | `obj:getWindSpeed(...)` |
| isLoadingFromASaveGame | isLoadingFromASaveGame | `obj:isLoadingFromASaveGame(...)` |
| hideContextMenu | hideContextMenu | `obj:hideContextMenu(...)` |
| showPlayerAMessage_withLog | showPlayerAMessage_withLog | `obj:showPlayerAMessage_withLog(...)` |
| showPlayerAMessage | showPlayerAMessage | `obj:showPlayerAMessage(...)` |
| showPlayerAMessageD | showPlayerAMessageD | `obj:showPlayerAMessageD(...)` |
| mainLoop_GPUSensitiveStuff | mainLoop_GPUSensitiveStuff | `obj:mainLoop_GPUSensitiveStuff(...)` |
| _NV_mainLoop_GPUSensitiveStuff | _NV_mainLoop_GPUSensitiveStuff | `obj:_NV_mainLoop_GPUSensitiveStuff(...)` |
| clearPortaitsUpdate | clearPortaitsUpdate | `obj:clearPortaitsUpdate(...)` |
| processSysMessages | processSysMessages | `obj:processSysMessages(...)` |
| destroyDeathParade | destroyDeathParade | `obj:destroyDeathParade(...)` |
| processKeys | processKeys | `obj:processKeys(...)` |
| processThreadMessages | processThreadMessages | `obj:processThreadMessages(...)` |
| charsUpdate | charsUpdate | `obj:charsUpdate(...)` |
| charsUpdateUT | charsUpdateUT | `obj:charsUpdateUT(...)` |
| charsUpdatePaused | charsUpdatePaused | `obj:charsUpdatePaused(...)` |
| charsUpdateDeathParade | charsUpdateDeathParade | `obj:charsUpdateDeathParade(...)` |
| threadSafeRagdollUpdates | threadSafeRagdollUpdates | `obj:threadSafeRagdollUpdates(...)` |
| processAttachmentsKillList | processAttachmentsKillList | `obj:processAttachmentsKillList(...)` |
| processKillList | processKillList | `obj:processKillList(...)` |
| processUpdateRemovalList | processUpdateRemovalList | `obj:processUpdateRemovalList(...)` |
| loadAllPlatoons | loadAllPlatoons | `obj:loadAllPlatoons(...)` |
| reCalculateFortificationInsideOutsideStateForAllCharacters | reCalculateFortificationInsideOutsideStateForAllCharacters | `obj:reCalculateFortificationInsideOutsideStateForAllCharacters(...)` |
| getTimeStamp | getTimeStamp | `obj:getTimeStamp(...)` |
| getTimeFromStamp_inGameHours | getTimeFromStamp_inGameHours | `obj:getTimeFromStamp_inGameHours(...)` |
| getLengthOfHourInRealSeconds | getLengthOfHourInRealSeconds | `obj:getLengthOfHourInRealSeconds(...)` |
| getFromDeathParade | GameWorld_getFromDeathParade | `obj:getFromDeathParade(...)` |

## GameplayOptions
**Header:** `extern/KenshiLib/Include/kenshi/GameplayOptions.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| deathFrequency | deathFrequency | number | RW | `obj.deathFrequency = <value>` |
| easyProspecting | easyProspecting | boolean | RW | `obj.easyProspecting = <value>` |
| globalDamageMultiplier | globalDamageMultiplier | number | RW | `obj.globalDamageMultiplier = <value>` |
| buildingSpeed | buildingSpeed | number | RW | `obj.buildingSpeed = <value>` |
| numNestsMult | numNestsMult | number | RW | `obj.numNestsMult = <value>` |
| researchSpeed | researchSpeed | number | RW | `obj.researchSpeed = <value>` |
| productionSpeed | productionSpeed | number | RW | `obj.productionSpeed = <value>` |
| hungerTime | hungerTime | number | RW | `obj.hungerTime = <value>` |
| banditsLootPlayer | banditsLootPlayer | boolean | RW | `obj.banditsLootPlayer = <value>` |
| animalsEat | animalsEat | boolean | RW | `obj.animalsEat = <value>` |
| difficultHealing | difficultHealing | boolean | RW | `obj.difficultHealing = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| reset | reset | `obj:reset(...)` |
| getStarvationTimeInHours | getStarvationTimeInHours | `obj:getStarvationTimeInHours(...)` |

## Gear
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isUniform | isUniform | Faction | R | `obj.isUniform` |
| value | value | integer | RW | `obj.value = <value>` |
| crafter | crafter | string | RW | `obj.crafter = <value>` |
| level | level | number | RW | `obj.level = <value>` |
| level_0_100 | level_0_100 | integer | RW | `obj.level_0_100 = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isGear | isGear | `obj:isGear(...)` |
| _NV_isGear | _NV_isGear | `obj:_NV_isGear(...)` |
| getLevel01 | getLevel01 | `obj:getLevel01(...)` |
| _NV_getLevel01 | _NV_getLevel01 | `obj:_NV_getLevel01(...)` |
| getLevel | getLevel | `obj:getLevel(...)` |
| _NV_getLevel | _NV_getLevel | `obj:_NV_getLevel(...)` |
| isAFactionUniform | isAFactionUniform | `obj:isAFactionUniform(...)` |
| _NV_isAFactionUniform | _NV_isAFactionUniform | `obj:_NV_isAFactionUniform(...)` |
| isPlayerCrafted | isPlayerCrafted | `obj:isPlayerCrafted(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Global
**Header:** `???`

## HasRoomCache
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| itemStates | itemStates | std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > | R | `obj.itemStates` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| modified | modified | `obj:modified(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## HealthPartStatus
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | R | `obj.data` |
| whatAmI | (lua_Integer | integer | RW | `obj.whatAmI = <value>` |
| medical | medical | MedicalSystem | R | `obj.medical` |
| me | me | Character | R | `obj.me` |
| side | (lua_Integer | integer | RW | `obj.side = <value>` |
| robotLimb | robotLimb | RobotLimbItem* | R | `obj.robotLimb` |
| selfHealing | selfHealing | boolean | RW | `obj.selfHealing = <value>` |
| collapses | collapses | boolean | RW | `obj.collapses = <value>` |
| fatal | fatal | boolean | RW | `obj.fatal = <value>` |
| KOMult | KOMult | number | RW | `obj.KOMult = <value>` |
| hitChance | hitChance | number | RW | `obj.hitChance = <value>` |
| hitChanceMult | hitChanceMult | number | RW | `obj.hitChanceMult = <value>` |
| flesh | flesh | number | RW | `obj.flesh = <value>` |
| fleshStun | fleshStun | number | RW | `obj.fleshStun = <value>` |
| bandaging | bandaging | number | RW | `obj.bandaging = <value>` |
| juryRigging | juryRigging | number | RW | `obj.juryRigging = <value>` |
| wearDamage | wearDamage | number | RW | `obj.wearDamage = <value>` |
| _maxHealth | _maxHealth | number | RW | `obj._maxHealth = <value>` |
| age | age | number | RW | `obj.age = <value>` |
| HPMult | HPMult | number | RW | `obj.HPMult = <value>` |
| derivedFleshHealthPercent | derivedFleshHealthPercent | number | RW | `obj.derivedFleshHealthPercent = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isRobotic | isRobotic | `obj:isRobotic(...)` |
| getData | getData | `obj:getData(...)` |
| getRobotLimbEnum | getRobotLimbEnum | `obj:getRobotLimbEnum(...)` |
| update | update | `obj:update(...)` |
| updateDerivedHealths | updateDerivedHealths | `obj:updateDerivedHealths(...)` |
| getWorstDamage | getWorstDamage | `obj:getWorstDamage(...)` |
| getExtraBleedingAmount | getExtraBleedingAmount | `obj:getExtraBleedingAmount(...)` |
| isDead | isDead | `obj:isDead(...)` |
| getBloodynessMult | getBloodynessMult | `obj:getBloodynessMult(...)` |
| maxHealth | maxHealth | `obj:maxHealth(...)` |
| healthAsPercent | healthAsPercent | `obj:healthAsPercent(...)` |

## ImpactPoint
**Header:** `extern/KenshiLib/Include/kenshi/CombatTechniqueData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| direction | (lua_Integer | integer | RW | `obj.direction = <value>` |
| power | power | number | RW | `obj.power = <value>` |
| impactAnimationFrame | impactAnimationFrame | number | RW | `obj.impactAnimationFrame = <value>` |
| motionStopsAnimationFrame | motionStopsAnimationFrame | number | RW | `obj.motionStopsAnimationFrame = <value>` |
| limb | (lua_Integer | integer | RW | `obj.limb = <value>` |

## InputHandler
**Header:** `extern/KenshiLib/Include/kenshi/Globals.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| commands | commands | std::map<std::string, Command, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Command>, Ogre::GeneralAllocPolicy > > | R | `obj.commands` |
| map | map | std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::GeneralAllocPolicy > > | R | `obj.map` |
| editMap | editMap | std::map<int, Command*, std::less<int>, Ogre::STLAllocator<std::pair<int const, Command*>, Ogre::GeneralAllocPolicy > > | R | `obj.editMap` |
| events | events | std::set<Command*, std::less<Command*>, Ogre::STLAllocator<Command*, Ogre::GeneralAllocPolicy > > | R | `obj.events` |
| keyboard | (lua_Integer | integer | R | `obj.keyboard` |
| keyNameMap | keyNameMap | std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > | R | `obj.keyNameMap` |
| controlEnabled | controlEnabled | boolean | RW | `obj.controlEnabled = <value>` |
| gameMode | (lua_Integer | integer | RW | `obj.gameMode = <value>` |
| ctrl | ctrl | boolean | RW | `obj.ctrl = <value>` |
| shift | shift | boolean | RW | `obj.shift = <value>` |
| alt | alt | boolean | RW | `obj.alt = <value>` |
| up | up | boolean | RW | `obj.up = <value>` |
| down | down | boolean | RW | `obj.down = <value>` |
| left | left | boolean | RW | `obj.left = <value>` |
| right | right | boolean | RW | `obj.right = <value>` |
| space | space | boolean | RW | `obj.space = <value>` |
| pgup | pgup | boolean | RW | `obj.pgup = <value>` |
| pgdn | pgdn | boolean | RW | `obj.pgdn = <value>` |
| comma | comma | boolean | RW | `obj.comma = <value>` |
| period | period | boolean | RW | `obj.period = <value>` |
| f1 | f1 | boolean | RW | `obj.f1 = <value>` |
| f2 | f2 | boolean | RW | `obj.f2 = <value>` |
| escape | escape | boolean | RW | `obj.escape = <value>` |
| del | del | boolean | RW | `obj.del = <value>` |
| escape_msg | escape_msg | boolean | RW | `obj.escape_msg = <value>` |
| zoomin | zoomin | boolean | RW | `obj.zoomin = <value>` |
| zoomout | zoomout | boolean | RW | `obj.zoomout = <value>` |
| buildTiltInc | buildTiltInc | boolean | RW | `obj.buildTiltInc = <value>` |
| buildTiltDec | buildTiltDec | boolean | RW | `obj.buildTiltDec = <value>` |
| rotate | rotate | boolean | RW | `obj.rotate = <value>` |
| rotRight | rotRight | boolean | RW | `obj.rotRight = <value>` |
| rotLeft | rotLeft | boolean | RW | `obj.rotLeft = <value>` |
| tiltDown | tiltDown | boolean | RW | `obj.tiltDown = <value>` |
| tiltUp | tiltUp | boolean | RW | `obj.tiltUp = <value>` |
| highlight | highlight | boolean | RW | `obj.highlight = <value>` |
| mLeft | mLeft | boolean | RW | `obj.mLeft = <value>` |
| mRight | mRight | boolean | RW | `obj.mRight = <value>` |
| lastMLeft | lastMLeft | boolean | RW | `obj.lastMLeft = <value>` |
| lastMRight | lastMRight | boolean | RW | `obj.lastMRight = <value>` |
| mLDown | mLDown | boolean | RW | `obj.mLDown = <value>` |
| mRDown | mRDown | boolean | RW | `obj.mRDown = <value>` |
| mLUp | mLUp | boolean | RW | `obj.mLUp = <value>` |
| mRUp | mRUp | boolean | RW | `obj.mRUp = <value>` |
| swapMouseButtons | swapMouseButtons | boolean | RW | `obj.swapMouseButtons = <value>` |
| mPos | mPos | Ogre::Vector2 | R | `obj.mPos` |
| mPosAbs | mPosAbs | Ogre::Vector2 | R | `obj.mPosAbs` |
| mSpeed | mSpeed | Vector3 | RW | `obj.mSpeed = <value>` |
| mWheel | mWheel | integer | RW | `obj.mWheel = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getKeyUTF8 | getKeyUTF8 | `obj:getKeyUTF8(...)` |
| parseKey | parseKey | `obj:parseKey(...)` |
| keyDownEvent | keyDownEvent | `obj:keyDownEvent(...)` |
| keyUpEvent | keyUpEvent | `obj:keyUpEvent(...)` |
| clearMessages | clearMessages | `obj:clearMessages(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| initialise | initialise | `obj:initialise(...)` |
| bind | bind | `obj:bind(...)` |
| unbindAll | unbindAll | `obj:unbindAll(...)` |
| isKeyState | isKeyState | `obj:isKeyState(...)` |
| getMode | getMode | `obj:getMode(...)` |
| sendEvent | sendEvent | `obj:sendEvent(...)` |
| loadConfig | loadConfig | `obj:loadConfig(...)` |
| saveConfig | saveConfig | `obj:saveConfig(...)` |
| keyString | keyString | `obj:keyString(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Inventory
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| hasRoomCache | (lua_Integer | integer | R | `obj.hasRoomCache` |
| _allItems | _allItems | lektor<Item*> | R | `obj._allItems` |
| sections | second | InventorySection | R | `obj.sections` |
| sectionsInSearchOrder | sectionsInSearchOrder | lektor<InventorySection*> | R | `obj.sectionsInSearchOrder` |
| callbackObject | callbackObject | RootObject | R | `obj.callbackObject` |
| owner | owner | RootObject | R | `obj.owner` |
| totalWeight | totalWeight | number | RW | `obj.totalWeight = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| clearAll | clearAll | `obj:clearAll(...)` |
| notifyModified | notifyModified | `obj:notifyModified(...)` |
| initialiseNewSection | initialiseNewSection | `obj:initialiseNewSection(...)` |
| _NV_initialiseNewSection | _NV_initialiseNewSection | `obj:_NV_initialiseNewSection(...)` |
| removeAllSections | removeAllSections | `obj:removeAllSections(...)` |
| getSection | getSection | `obj:getSection(...)` |
| getSectionOfType | getSectionOfType | `obj:getSectionOfType(...)` |
| resizeSection | resizeSection | `obj:resizeSection(...)` |
| getCallbackCharacter | getCallbackCharacter | `obj:getCallbackCharacter(...)` |
| hasItemType | hasItemType | `obj:hasItemType(...)` |
| hasStolenItems | hasStolenItems | `obj:hasStolenItems(...)` |
| getSecondaryWeapon | getSecondaryWeapon | `obj:getSecondaryWeapon(...)` |
| getPrimaryWeapon | getPrimaryWeapon | `obj:getPrimaryWeapon(...)` |
| hasItemFunction | hasItemFunction | `obj:hasItemFunction(...)` |
| getBestItemWithFunction | getBestItemWithFunction | `obj:getBestItemWithFunction(...)` |
| hasWeaponEquipped | hasWeaponEquipped | `obj:hasWeaponEquipped(...)` |
| isAContainer | isAContainer | `obj:isAContainer(...)` |
| getOwner | getOwner | `obj:getOwner(...)` |
| isEmpty | isEmpty | `obj:isEmpty(...)` |
| recalculateTotalWeight | recalculateTotalWeight | `obj:recalculateTotalWeight(...)` |
| getTotalWeight | getTotalWeight | `obj:getTotalWeight(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| isVisible | isVisible | `obj:isVisible(...)` |
| refreshGui | refreshGui | `obj:refreshGui(...)` |
| _NV_refreshGui | _NV_refreshGui | `obj:_NV_refreshGui(...)` |
| autoArrange | autoArrange | `obj:autoArrange(...)` |
| getCallbackObject | getCallbackObject | `obj:getCallbackObject(...)` |
| getHandle | Inventory_getHandle | `obj:getHandle(...)` |
| addItem | Inventory_addItem | `obj:addItem(...)` |
| _NV_addItem | Inventory__NV_addItem | `obj:_NV_addItem(...)` |
| tryAddItem | Inventory_tryAddItem | `obj:tryAddItem(...)` |
| _NV_tryAddItem | Inventory__NV_tryAddItem | `obj:_NV_tryAddItem(...)` |
| removeItemDontDestroy_returnsItem | Inventory_removeItemDontDestroy_returnsItem | `obj:removeItemDontDestroy_returnsItem(...)` |
| _NV_removeItemDontDestroy_returnsItem | Inventory__NV_removeItemDontDestroy_returnsItem | `obj:_NV_removeItemDontDestroy_returnsItem(...)` |
| removeItemAutoDestroy | Inventory_removeItemAutoDestroy | `obj:removeItemAutoDestroy(...)` |
| _NV_removeItemAutoDestroy | Inventory__NV_removeItemAutoDestroy | `obj:_NV_removeItemAutoDestroy(...)` |
| dropItem | Inventory_dropItem | `obj:dropItem(...)` |
| _NV_dropItem | Inventory__NV_dropItem | `obj:_NV_dropItem(...)` |
| getItem | Inventory_getItem | `obj:getItem(...)` |

## InventoryItemBase
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| manufacturerData | manufacturerData | GameData | R | `obj.manufacturerData` |
| materialData | materialData | GameData | R | `obj.materialData` |
| coloriseData | coloriseData | GameData | R | `obj.coloriseData` |
| isInInventory | isInInventory | boolean | RW | `obj.isInInventory = <value>` |
| inventoryPos | inventoryPos | iVector2 | R | `obj.inventoryPos` |
| inventorySection | inventorySection | string | RW | `obj.inventorySection = <value>` |
| slotType | (lua_Integer | integer | RW | `obj.slotType = <value>` |
| originalFullChargeAmount | originalFullChargeAmount | number | RW | `obj.originalFullChargeAmount = <value>` |
| chargesLeft | chargesLeft | number | RW | `obj.chargesLeft = <value>` |
| quality | quality | number | RW | `obj.quality = <value>` |
| weight | weight | number | RW | `obj.weight = <value>` |
| itemFunction | (lua_Integer | integer | RW | `obj.itemFunction = <value>` |
| isTradeItem | isTradeItem | boolean | RW | `obj.isTradeItem = <value>` |
| isEquipped | isEquipped | boolean | RW | `obj.isEquipped = <value>` |
| isUnique | isUnique | boolean | RW | `obj.isUnique = <value>` |
| quantity | quantity | integer | RW | `obj.quantity = <value>` |
| itemWidth | itemWidth | integer | RW | `obj.itemWidth = <value>` |
| itemHeight | itemHeight | integer | RW | `obj.itemHeight = <value>` |
| deathItem | deathItem | boolean | RW | `obj.deathItem = <value>` |
| objectType | (lua_Integer | integer | RW | `obj.objectType = <value>` |
| properOwner | properOwner | hand | RW | `obj.properOwner = <value>` |
| _whosInventoryWeAreIn | _whosInventoryWeAreIn | hand | RW | `obj._whosInventoryWeAreIn = <value>` |
| _isResearchArtifact | _isResearchArtifact | boolean | RW | `obj._isResearchArtifact = <value>` |
| itemGroup | itemGroup | BuildingItemGroup* | R | `obj.itemGroup` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| deactivate | deactivate | `obj:deactivate(...)` |
| resetAfterCopy | resetAfterCopy | `obj:resetAfterCopy(...)` |
| resetCharges | resetCharges | `obj:resetCharges(...)` |
| getItemType | getItemType | `obj:getItemType(...)` |
| getItemWeightSingle | getItemWeightSingle | `obj:getItemWeightSingle(...)` |
| _NV_getItemWeightSingle | _NV_getItemWeightSingle | `obj:_NV_getItemWeightSingle(...)` |
| getItemWeight | getItemWeight | `obj:getItemWeight(...)` |
| _NV_getItemWeight | _NV_getItemWeight | `obj:_NV_getItemWeight(...)` |
| getAvgPrice | getAvgPrice | `obj:getAvgPrice(...)` |
| getValueSingle | getValueSingle | `obj:getValueSingle(...)` |
| _NV_getValueSingle | _NV_getValueSingle | `obj:_NV_getValueSingle(...)` |
| getValueAll | getValueAll | `obj:getValueAll(...)` |
| _NV_getValueAll | _NV_getValueAll | `obj:_NV_getValueAll(...)` |
| getMaxAffordableNum | getMaxAffordableNum | `obj:getMaxAffordableNum(...)` |
| _NV_getMaxAffordableNum | _NV_getMaxAffordableNum | `obj:_NV_getMaxAffordableNum(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| _NV_getInventory | _NV_getInventory | `obj:_NV_getInventory(...)` |
| onGround | onGround | `obj:onGround(...)` |
| isResearchArtifact | isResearchArtifact | `obj:isResearchArtifact(...)` |
| getLevel | getLevel | `obj:getLevel(...)` |
| _NV_getLevel | _NV_getLevel | `obj:_NV_getLevel(...)` |
| getItemSound | getItemSound | `obj:getItemSound(...)` |
| isStolen | isStolen | `obj:isStolen(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| merchantPriceMod | merchantPriceMod | `obj:merchantPriceMod(...)` |

## InventorySection
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |
| width | width | integer | RW | `obj.width = <value>` |
| height | height | integer | RW | `obj.height = <value>` |
| armourOnly | armourOnly | boolean | RW | `obj.armourOnly = <value>` |
| items | items | Ogre::vector<InventorySection::SectionItem>::type | R | `obj.items` |
| content | content | Array2d<Item> | R | `obj.content` |
| stackingBonusMin | stackingBonusMin | integer | RW | `obj.stackingBonusMin = <value>` |
| stackingBonusMult | stackingBonusMult | number | RW | `obj.stackingBonusMult = <value>` |
| veryLimitedSlot | veryLimitedSlot | lektor<GameData*> | R | `obj.veryLimitedSlot` |
| itemsLimit | itemsLimit | integer | RW | `obj.itemsLimit = <value>` |
| weightMultiplier | weightMultiplier | number | RW | `obj.weightMultiplier = <value>` |
| totalWeight | totalWeight | number | RW | `obj.totalWeight = <value>` |
| isAnEquippedItemSection | isAnEquippedItemSection | boolean | RW | `obj.isAnEquippedItemSection = <value>` |
| limitedSlot | (lua_Integer | integer | RW | `obj.limitedSlot = <value>` |
| containerSlot | containerSlot | boolean | RW | `obj.containerSlot = <value>` |
| callbackObject | callbackObject | RootObject | R | `obj.callbackObject` |
| parentInventory | parentInventory | Inventory | R | `obj.parentInventory` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| notifyModified | notifyModified | `obj:notifyModified(...)` |
| getItemAt | getItemAt | `obj:getItemAt(...)` |
| hasRoomForItem | hasRoomForItem | `obj:hasRoomForItem(...)` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `obj:_NV_hasRoomForItem(...)` |
| hasItem | hasItem_Item | `obj:hasItem(...)` |
| hasItem | hasItem_GameData | `obj:hasItem(...)` |
| hasItemType | hasItemType | `obj:hasItemType(...)` |
| autoArrange | autoArrange | `obj:autoArrange(...)` |
| _NV_autoArrange | _NV_autoArrange | `obj:_NV_autoArrange(...)` |
| getNumItems | getNumItems | `obj:getNumItems(...)` |
| isEmpty | isEmpty | `obj:isEmpty(...)` |
| clearAllItems | clearAllItems | `obj:clearAllItems(...)` |
| getLimitedSlot | getLimitedSlot | `obj:getLimitedSlot(...)` |
| applyStackingBonuses | applyStackingBonuses | `obj:applyStackingBonuses(...)` |
| recalculateTotalWeight | recalculateTotalWeight | `obj:recalculateTotalWeight(...)` |
| setWeightMultiplier | setWeightMultiplier | `obj:setWeightMultiplier(...)` |
| setStackingBonus | setStackingBonus | `obj:setStackingBonus(...)` |
| getMaxStack | getMaxStack | `obj:getMaxStack(...)` |
| clearVeryLimitedSlot | clearVeryLimitedSlot | `obj:clearVeryLimitedSlot(...)` |
| getEnabled | getEnabled | `obj:getEnabled(...)` |
| setEnabled | setEnabled | `obj:setEnabled(...)` |
| setItemsLimitCount | setItemsLimitCount | `obj:setItemsLimitCount(...)` |
| getItemsLimitReached | getItemsLimitReached | `obj:getItemsLimitReached(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| getFillPercentage | getFillPercentage | `obj:getFillPercentage(...)` |
| getItem | getItem | `obj:getItem(...)` |
| resize | resize | `obj:resize(...)` |
| addItem | addItem | `obj:addItem(...)` |
| _NV_addItem | _NV_addItem | `obj:_NV_addItem(...)` |
| removeItem | removeItem | `obj:removeItem(...)` |
| canItemGoHere | canItemGoHere | `obj:canItemGoHere(...)` |
| existsItemInFootprint | existsItemInFootprint | `obj:existsItemInFootprint(...)` |
| isLimitedSlotCompatible | isLimitedSlotCompatible | `obj:isLimitedSlotCompatible(...)` |
| getValidInventoryPosition | getValidInventoryPosition | `obj:getValidInventoryPosition(...)` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| physicalShouldExist | physicalShouldExist | boolean | RW | `obj.physicalShouldExist = <value>` |
| existAsBareWeapon | existAsBareWeapon | boolean | RW | `obj.existAsBareWeapon = <value>` |
| persistant | persistant | hand | RW | `obj.persistant = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| physical | physical | SimplePhysXEntity* | R | `obj.physical` |
| _isPhysical | _isPhysical | boolean | RW | `obj._isPhysical = <value>` |
| physicalEntity | physicalEntity | Ogre::Entity* | R | `obj.physicalEntity` |
| creatingPhysical | creatingPhysical | boolean | RW | `obj.creatingPhysical = <value>` |
| fixedPhysicalPosition | fixedPhysicalPosition | boolean | RW | `obj.fixedPhysicalPosition = <value>` |
| useDynamicPhysics | useDynamicPhysics | boolean | RW | `obj.useDynamicPhysics = <value>` |
| loadingEntity | loadingEntity | Ogre::Entity* | R | `obj.loadingEntity` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isGear | isGear | `obj:isGear(...)` |
| _NV_isGear | _NV_isGear | `obj:_NV_isGear(...)` |
| getClassType | getClassType | `obj:getClassType(...)` |
| _NV_getClassType | _NV_getClassType | `obj:_NV_getClassType(...)` |
| resetAfterCopy | resetAfterCopy | `obj:resetAfterCopy(...)` |
| _NV_resetAfterCopy | _NV_resetAfterCopy | `obj:_NV_resetAfterCopy(...)` |
| deactivate | deactivate | `obj:deactivate(...)` |
| _NV_deactivate | _NV_deactivate | `obj:_NV_deactivate(...)` |
| setPositionRotation | setPositionRotation | `obj:setPositionRotation(...)` |
| _NV_setPositionRotation | _NV_setPositionRotation | `obj:_NV_setPositionRotation(...)` |
| isCrossbow | isCrossbow | `obj:isCrossbow(...)` |
| _NV_isCrossbow | _NV_isCrossbow | `obj:_NV_isCrossbow(...)` |
| isArmour | isArmour | `obj:isArmour(...)` |
| _NV_isArmour | _NV_isArmour | `obj:_NV_isArmour(...)` |
| isWeapon | isWeapon | `obj:isWeapon(...)` |
| _NV_isWeapon | _NV_isWeapon | `obj:_NV_isWeapon(...)` |
| isLockedArmour | isLockedArmour | `obj:isLockedArmour(...)` |
| _NV_isLockedArmour | _NV_isLockedArmour | `obj:_NV_isLockedArmour(...)` |
| isAFactionUniform | isAFactionUniform | `obj:isAFactionUniform(...)` |
| _NV_isAFactionUniform | _NV_isAFactionUniform | `obj:_NV_isAFactionUniform(...)` |
| isPhysical | isPhysical | `obj:isPhysical(...)` |
| _NV_isPhysical | _NV_isPhysical | `obj:_NV_isPhysical(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| _NV_setVisible | _NV_setVisible | `obj:_NV_setVisible(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| _NV_getVisible | _NV_getVisible | `obj:_NV_getVisible(...)` |
| getModelName | getModelName | `obj:getModelName(...)` |
| _NV_getModelName | _NV_getModelName | `obj:_NV_getModelName(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| _NV_getInventory | _NV_getInventory | `obj:_NV_getInventory(...)` |
| hasIngredients | hasIngredients | `obj:hasIngredients(...)` |
| _NV_hasIngredients | _NV_hasIngredients | `obj:_NV_hasIngredients(...)` |
| isGoodFood | isGoodFood | `obj:isGoodFood(...)` |
| _NV_isGoodFood | _NV_isGoodFood | `obj:_NV_isGoodFood(...)` |
| getCraftTime | getCraftTime | `obj:getCraftTime(...)` |
| _NV_getCraftTime | _NV_getCraftTime | `obj:_NV_getCraftTime(...)` |
| getCraftMaterialMult | getCraftMaterialMult | `obj:getCraftMaterialMult(...)` |
| _NV_getCraftMaterialMult | _NV_getCraftMaterialMult | `obj:_NV_getCraftMaterialMult(...)` |
| getLevel | getLevel | `obj:getLevel(...)` |
| _NV_getLevel | _NV_getLevel | `obj:_NV_getLevel(...)` |
| destroyItemEntityCallback_Equipping | destroyItemEntityCallback_Equipping | `obj:destroyItemEntityCallback_Equipping(...)` |
| _NV_destroyItemEntityCallback_Equipping | _NV_destroyItemEntityCallback_Equipping | `obj:_NV_destroyItemEntityCallback_Equipping(...)` |
| isPersistant | isPersistant | `obj:isPersistant(...)` |
| persistantOwnerExists | persistantOwnerExists | `obj:persistantOwnerExists(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| createPhysical | createPhysical | `obj:createPhysical(...)` |
| _NV_createPhysical | _NV_createPhysical | `obj:_NV_createPhysical(...)` |
| destroyPhysical | destroyPhysical | `obj:destroyPhysical(...)` |
| _NV_destroyPhysical | _NV_destroyPhysical | `obj:_NV_destroyPhysical(...)` |
| loadUnloadCheck | loadUnloadCheck | `obj:loadUnloadCheck(...)` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `obj:_NV_loadUnloadCheck(...)` |
| getInventoryWeAreIn | getInventoryWeAreIn | `obj:getInventoryWeAreIn(...)` |
| setInventoryWeAreIn | setInventoryWeAreIn | `obj:setInventoryWeAreIn(...)` |
| _NV_setInventoryWeAreIn | _NV_setInventoryWeAreIn | `obj:_NV_setInventoryWeAreIn(...)` |

## ItemData
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | visible | boolean | RW | `obj.visible = <value>` |
| category | category | string | RW | `obj.category = <value>` |
| description | description | string | RW | `obj.description = <value>` |
| fileTypes | fileTypes | string | RW | `obj.fileTypes = <value>` |
| objectType | (lua_Integer | integer | RW | `obj.objectType = <value>` |
| maxSize | maxSize | integer | RW | `obj.maxSize = <value>` |
| maxValue | maxValue | integer | RW | `obj.maxValue = <value>` |
| minValue | minValue | integer | RW | `obj.minValue = <value>` |
| isSlider | isSlider | boolean | RW | `obj.isSlider = <value>` |

## LimbsInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| character | character | Character | R | `obj.character` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Limiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| racesExclude | racesExclude | std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > | R | `obj.racesExclude` |
| racesInclude | racesInclude | std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > | R | `obj.racesInclude` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## LockedArmour
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lock | lock | DoorLock* | R | `obj.lock` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| isArmour | isArmour | `obj:isArmour(...)` |
| _NV_isArmour | _NV_isArmour | `obj:_NV_isArmour(...)` |
| isLockedArmour | isLockedArmour | `obj:isLockedArmour(...)` |
| _NV_isLockedArmour | _NV_isLockedArmour | `obj:_NV_isLockedArmour(...)` |

## MedianFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isPositionsFilter | isPositionsFilter | boolean | RW | `obj.isPositionsFilter = <value>` |
| edgeSkips | edgeSkips | integer | RW | `obj.edgeSkips = <value>` |
| maxLength | maxLength | integer | RW | `obj.maxLength = <value>` |
| mHistoryBufferX | mHistoryBufferX | std::deque<float, std::allocator<float> > | R | `obj.mHistoryBufferX` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| setup | setup | `obj:setup(...)` |
| reset | reset | `obj:reset(...)` |
| applySilent | applySilent | `obj:applySilent(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## MedianFilter2DVector
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| filters | filters | MedianFilter | R | `obj.filters` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| setup | setup | `obj:setup(...)` |
| reset | reset | `obj:reset(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| status | status | ogre_unordered_map<GameData*, MedicalSystem::HealthPartStatus>::type | R | `obj.status` |
| armourList | armourList | lektor<Armour*> | R | `obj.armourList` |
| hunger | hunger | number | RW | `obj.hunger = <value>` |
| fed | fed | number | RW | `obj.fed = <value>` |
| lastPeriodicUpdate | lastPeriodicUpdate | TimeOfDay | R | `obj.lastPeriodicUpdate` |
| blood | blood | number | RW | `obj.blood = <value>` |
| extraBloodLossFromBodyparts | extraBloodLossFromBodyparts | number | RW | `obj.extraBloodLossFromBodyparts = <value>` |
| currentBleedRate | currentBleedRate | number | RW | `obj.currentBleedRate = <value>` |
| leftLeg | (lua_Integer | integer | R | `obj.leftLeg` |
| rightLeg | (lua_Integer | integer | R | `obj.rightLeg` |
| leftArm | (lua_Integer | integer | R | `obj.leftArm` |
| rightArm | (lua_Integer | integer | R | `obj.rightArm` |
| knockoutTimer | knockoutTimer | number | RW | `obj.knockoutTimer = <value>` |
| worstDamage | worstDamage | number | RW | `obj.worstDamage = <value>` |
| needsFirstAidScoreTotal_robot | needsFirstAidScoreTotal_robot | number | RW | `obj.needsFirstAidScoreTotal_robot = <value>` |
| needsFirstAidScoreTotal_fleshy | needsFirstAidScoreTotal_fleshy | number | RW | `obj.needsFirstAidScoreTotal_fleshy = <value>` |
| restedState | restedState | number | RW | `obj.restedState = <value>` |
| stealthHinderance | stealthHinderance | number | RW | `obj.stealthHinderance = <value>` |
| partBestArm | partBestArm | number | RW | `obj.partBestArm = <value>` |
| partHead | partHead | number | RW | `obj.partHead = <value>` |
| partWorstTorso | partWorstTorso | number | RW | `obj.partWorstTorso = <value>` |
| dazedOrAlert | dazedOrAlert | number | RW | `obj.dazedOrAlert = <value>` |
| robotLimbs | robotLimbs | RobotLimbs | R | `obj.robotLimbs` |
| bloodynessChanged | bloodynessChanged | boolean | RW | `obj.bloodynessChanged = <value>` |
| bloodynessCleanedUp | bloodynessCleanedUp | boolean | RW | `obj.bloodynessCleanedUp = <value>` |
| animation | animation | AnimationClass* | R | `obj.animation` |
| me | me | Character | R | `obj.me` |
| weatherGUIfeedback | weatherGUIfeedback | StringPair | R | `obj.weatherGUIfeedback` |
| currentWeatherAffect | (lua_Integer | integer | RW | `obj.currentWeatherAffect = <value>` |
| currentWeatherAffectStrength | currentWeatherAffectStrength | number | RW | `obj.currentWeatherAffectStrength = <value>` |
| lastHungerKO | lastHungerKO | TimeOfDay | R | `obj.lastHungerKO` |
| nextKOTime | nextKOTime | number | RW | `obj.nextKOTime = <value>` |
| _eatenDeathDelay | _eatenDeathDelay | integer | RW | `obj._eatenDeathDelay = <value>` |
| crippled | crippled | boolean | RW | `obj.crippled = <value>` |
| unconcious | unconcious | boolean | RW | `obj.unconcious = <value>` |
| sub50KO | sub50KO | boolean | RW | `obj.sub50KO = <value>` |
| bloodlossTrauma | bloodlossTrauma | boolean | RW | `obj.bloodlossTrauma = <value>` |
| dead | dead | boolean | RW | `obj.dead = <value>` |
| rightArmOk | rightArmOk | boolean | RW | `obj.rightArmOk = <value>` |
| leftArmOk | leftArmOk | boolean | RW | `obj.leftArmOk = <value>` |
| lastBloodPosition | lastBloodPosition | Vector3 | RW | `obj.lastBloodPosition = <value>` |
| wounds | wounds | Ogre::FastArray<Wound*> | R | `obj.wounds` |
| anatomy | anatomy | lektor<MedicalSystem::HealthPartStatus*> | R | `obj.anatomy` |
| stats | stats | CharStats | R | `obj.stats` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| precalculateFirstAidNeedScore | precalculateFirstAidNeedScore | `obj:precalculateFirstAidNeedScore(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| updateStats | updateStats | `obj:updateStats(...)` |
| _NV_updateStats | _NV_updateStats | `obj:_NV_updateStats(...)` |
| medicalUpdate | medicalUpdate | `obj:medicalUpdate(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| scoreFirstAidNeed | scoreFirstAidNeed | `obj:scoreFirstAidNeed(...)` |
| scoreJuryRigNeed | scoreJuryRigNeed | `obj:scoreJuryRigNeed(...)` |
| isFullyRested | isFullyRested | `obj:isFullyRested(...)` |
| _setHealth | _setHealth | `obj:_setHealth(...)` |
| validateHealthValues | validateHealthValues | `obj:validateHealthValues(...)` |
| amputate | amputate | `obj:amputate(...)` |
| crushLimb | crushLimb | `obj:crushLimb(...)` |
| isUselessNoLimbGuy | isUselessNoLimbGuy | `obj:isUselessNoLimbGuy(...)` |
| recalculateStealthHinderance | recalculateStealthHinderance | `obj:recalculateStealthHinderance(...)` |
| getPartCount | getPartCount | `obj:getPartCount(...)` |
| hasRobotics | hasRobotics | `obj:hasRobotics(...)` |
| isFed | isFed | `obj:isFed(...)` |
| getMaxBlood | getMaxBlood | `obj:getMaxBlood(...)` |
| startKnockoutTimer | startKnockoutTimer | `obj:startKnockoutTimer(...)` |
| knockout | knockout | `obj:knockout(...)` |
| knockoutForceTimer | knockoutForceTimer | `obj:knockoutForceTimer(...)` |
| pointOfCollapseBloodloss | pointOfCollapseBloodloss | `obj:pointOfCollapseBloodloss(...)` |
| pointOfNoReturn | pointOfNoReturn | `obj:pointOfNoReturn(...)` |
| pointOfNoReturn_Hunger01 | pointOfNoReturn_Hunger01 | `obj:pointOfNoReturn_Hunger01(...)` |
| isHungerKO | isHungerKO | `obj:isHungerKO(...)` |
| getToughnessXpBonus | getToughnessXpBonus | `obj:getToughnessXpBonus(...)` |
| getHungerSpeedModifier | getHungerSpeedModifier | `obj:getHungerSpeedModifier(...)` |
| getHealthStatModifier | getHealthStatModifier | `obj:getHealthStatModifier(...)` |
| _getRoboticsStatMult | _getRoboticsStatMult | `obj:_getRoboticsStatMult(...)` |
| getMissingArmPenaltyMult | getMissingArmPenaltyMult | `obj:getMissingArmPenaltyMult(...)` |
| getDerivedHeadHealth | getDerivedHeadHealth | `obj:getDerivedHeadHealth(...)` |
| calculateDesiredPainAnimations | calculateDesiredPainAnimations | `obj:calculateDesiredPainAnimations(...)` |
| getMovementSpeedInjuryMultiplier | getMovementSpeedInjuryMultiplier | `obj:getMovementSpeedInjuryMultiplier(...)` |
| getStatRoboticsMultiplier | getStatRoboticsMultiplier | `obj:getStatRoboticsMultiplier(...)` |
| getMovementSwimSpeedInjuryMultiplier | getMovementSwimSpeedInjuryMultiplier | `obj:getMovementSwimSpeedInjuryMultiplier(...)` |
| gettingEaten | gettingEaten | `obj:gettingEaten(...)` |
| gettingAcidRain | gettingAcidRain | `obj:gettingAcidRain(...)` |
| gettingAcidWater | gettingAcidWater | `obj:gettingAcidWater(...)` |
| gettingAcidFeet | gettingAcidFeet | `obj:gettingAcidFeet(...)` |
| gettingGassed | gettingGassed | `obj:gettingGassed(...)` |
| gettingWindyface | gettingWindyface | `obj:gettingWindyface(...)` |
| gettingBurnt | gettingBurnt | `obj:gettingBurnt(...)` |
| reassessCollapseMode | reassessCollapseMode | `obj:reassessCollapseMode(...)` |
| isUnconcious | isUnconcious | `obj:isUnconcious(...)` |
| isCrippled | isCrippled | `obj:isCrippled(...)` |
| isDead | isDead | `obj:isDead(...)` |
| hasAnArmToFightWith | hasAnArmToFightWith | `obj:hasAnArmToFightWith(...)` |
| hasFreshlySeveredALimb | hasFreshlySeveredALimb | `obj:hasFreshlySeveredALimb(...)` |
| isReallyHungry | isReallyHungry | `obj:isReallyHungry(...)` |
| isProbablyDying | isProbablyDying | `obj:isProbablyDying(...)` |
| getOverallHealthRating | getOverallHealthRating | `obj:getOverallHealthRating(...)` |
| canGetUpWakeUp | canGetUpWakeUp | `obj:canGetUpWakeUp(...)` |
| _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll | _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll | `obj:_reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll(...)` |
| isRightArmOk | isRightArmOk | `obj:isRightArmOk(...)` |
| isLeftArmOk | isLeftArmOk | `obj:isLeftArmOk(...)` |
| canIkick | canIkick | `obj:canIkick(...)` |
| isInBloodlossTrauma | isInBloodlossTrauma | `obj:isInBloodlossTrauma(...)` |
| clearWeatherEffects | clearWeatherEffects | `obj:clearWeatherEffects(...)` |
| getWeatherStatPenaltyMult | getWeatherStatPenaltyMult | `obj:getWeatherStatPenaltyMult(...)` |
| getWeatherStatPenalty | getWeatherStatPenalty | `obj:getWeatherStatPenalty(...)` |
| calculateBleedRateForFX | calculateBleedRateForFX | `obj:calculateBleedRateForFX(...)` |
| bloodlossUpdate | bloodlossUpdate | `obj:bloodlossUpdate(...)` |
| updateDamageState | updateDamageState | `obj:updateDamageState(...)` |

## MeshDataLookup
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| boneAssignments | boneAssignments | boost::unordered::unordered_map<Ogre::IdString, lektor<lektor<int> >, boost::hash<Ogre::IdString>, std::equal_to<Ogre::IdString>, Ogre::STLAllocator<std::pair<Ogre::IdString const, lektor<lektor<int> > >, Ogre::GeneralAllocPolicy > > | R | `obj.boneAssignments` |
| vertCount | vertCount | unsigned __int64 | R | `obj.vertCount` |
| verts | verts | Ogre::Vector3* | R | `obj.verts` |
| uvs | uvs | Ogre::Vector2* | R | `obj.uvs` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## ModInfo
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |
| file | file | string | RW | `obj.file = <value>` |
| path | path | string | RW | `obj.path = <value>` |
| isWorkshop | isWorkshop | boolean | RW | `obj.isWorkshop = <value>` |
| isBaseMod | isBaseMod | boolean | RW | `obj.isBaseMod = <value>` |
| leveldataFolder | leveldataFolder | string | RW | `obj.leveldataFolder = <value>` |
| header | header | GameDataHeader | R | `obj.header` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## MotionFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mWeightModifier | mWeightModifier | number | RW | `obj.mWeightModifier = <value>` |
| mHistoryBufferX | mHistoryBufferX | std::deque<float, std::allocator<float> > | R | `obj.mHistoryBufferX` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| SetHistoryBufferLength | SetHistoryBufferLength | `obj:SetHistoryBufferLength(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## MyGui
**Header:** `???`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| setSize | widget_setSize | `obj:setSize(...)` |
| setPosition | widget_setPosition | `obj:setPosition(...)` |
| setCaption | widget_setCaption | `obj:setCaption(...)` |
| getCaption | widget_getCaption | `obj:getCaption(...)` |
| setVisible | widget_setVisible | `obj:setVisible(...)` |
| getVisible | widget_getVisible | `obj:getVisible(...)` |
| setEnabled | widget_setEnabled | `obj:setEnabled(...)` |
| getEnabled | widget_getEnabled | `obj:getEnabled(...)` |
| getType | widget_getType | `obj:getType(...)` |
| getName | widget_getName | `obj:getName(...)` |
| destroy | widget_destroy | `obj:destroy(...)` |
| findWidget | widget_findWidget | `obj:findWidget(...)` |
| getClientWidget | widget_getClientWidget | `obj:getClientWidget(...)` |
| setProperty | widget_setProperty | `obj:setProperty(...)` |
| registerCallback | widget_registerCallback | `obj:registerCallback(...)` |
| getCoord | widget_getCoord | `obj:getCoord(...)` |
| setCoord | widget_setCoord | `obj:setCoord(...)` |
| getPosition | widget_getPosition | `obj:getPosition(...)` |
| getSize | widget_getSize | `obj:getSize(...)` |
| getParent | widget_getParent | `obj:getParent(...)` |
| detachFromWidget | widget_detachFromWidget | `obj:detachFromWidget(...)` |
| attachToWidget | widget_attachToWidget | `obj:attachToWidget(...)` |
| setNeedKeyFocus | widget_setNeedKeyFocus | `obj:setNeedKeyFocus(...)` |
| setNeedMouseFocus | widget_setNeedMouseFocus | `obj:setNeedMouseFocus(...)` |
| setPointer | widget_setPointer | `obj:setPointer(...)` |
| setUserString | widget_setUserString | `obj:setUserString(...)` |
| getUserString | widget_getUserString | `obj:getUserString(...)` |
| isUserString | widget_isUserString | `obj:isUserString(...)` |
| clearUserString | widget_clearUserString | `obj:clearUserString(...)` |
| setStateSelected | widget_setStateSelected | `obj:setStateSelected(...)` |
| getStateSelected | widget_getStateSelected | `obj:getStateSelected(...)` |
| setOnlyText | widget_setOnlyText | `obj:setOnlyText(...)` |
| getOnlyText | widget_getOnlyText | `obj:getOnlyText(...)` |
| setEditReadOnly | widget_setEditReadOnly | `obj:setEditReadOnly(...)` |
| getEditReadOnly | widget_getEditReadOnly | `obj:getEditReadOnly(...)` |
| setEditPassword | widget_setEditPassword | `obj:setEditPassword(...)` |
| getEditPassword | widget_getEditPassword | `obj:getEditPassword(...)` |
| setEditMultiLine | widget_setEditMultiLine | `obj:setEditMultiLine(...)` |
| getEditMultiLine | widget_getEditMultiLine | `obj:getEditMultiLine(...)` |
| setEditStatic | widget_setEditStatic | `obj:setEditStatic(...)` |
| getEditStatic | widget_getEditStatic | `obj:getEditStatic(...)` |
| setPasswordChar | widget_setPasswordChar | `obj:setPasswordChar(...)` |
| getItemCount | widget_getItemCount | `obj:getItemCount(...)` |
| addItem | widget_addItem | `obj:addItem(...)` |
| insertItemAt | widget_insertItemAt | `obj:insertItemAt(...)` |
| removeItemAt | widget_removeItemAt | `obj:removeItemAt(...)` |
| removeAllItems | widget_removeAllItems | `obj:removeAllItems(...)` |
| getIndexSelected | widget_getIndexSelected | `obj:getIndexSelected(...)` |
| setIndexSelected | widget_setIndexSelected | `obj:setIndexSelected(...)` |
| clearIndexSelected | widget_clearIndexSelected | `obj:clearIndexSelected(...)` |
| getItemNameAt | widget_getItemNameAt | `obj:getItemNameAt(...)` |
| setItemNameAt | widget_setItemNameAt | `obj:setItemNameAt(...)` |
| getOptimalHeight | widget_getOptimalHeight | `obj:getOptimalHeight(...)` |
| getWidgetByIndex | widget_getWidgetByIndex | `obj:getWidgetByIndex(...)` |
| setMinSize | widget_setMinSize | `obj:setMinSize(...)` |
| getMinSize | widget_getMinSize | `obj:getMinSize(...)` |
| setMaxSize | widget_setMaxSize | `obj:setMaxSize(...)` |
| getMaxSize | widget_getMaxSize | `obj:getMaxSize(...)` |
| setVisibleSmooth | widget_setVisibleSmooth | `obj:setVisibleSmooth(...)` |
| destroySmooth | widget_destroySmooth | `obj:destroySmooth(...)` |
| setMovable | widget_setMovable | `obj:setMovable(...)` |
| getMovable | widget_getMovable | `obj:getMovable(...)` |
| setImageTexture | widget_setImageTexture | `obj:setImageTexture(...)` |
| setImageCoord | widget_setImageCoord | `obj:setImageCoord(...)` |
| setImageTile | widget_setImageTile | `obj:setImageTile(...)` |
| setImageIndex | widget_setImageIndex | `obj:setImageIndex(...)` |
| getImageIndex | widget_getImageIndex | `obj:getImageIndex(...)` |

## NxUserControllerHitReport
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## ObjectInstance
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |
| refID | refID | string | RW | `obj.refID = <value>` |
| created | created | integer | RW | `obj.created = <value>` |
| modified | modified | integer | RW | `obj.modified = <value>` |
| stateIDs | stateIDs | lektor<std::string > | R | `obj.stateIDs` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## OptionsHolder
**Header:** `extern/KenshiLib/Include/kenshi/Globals.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| CAMERA_MOVE_SPEED | CAMERA_MOVE_SPEED | number | RW | `obj.CAMERA_MOVE_SPEED = <value>` |
| CAMERA_PAN_SPEED | CAMERA_PAN_SPEED | number | RW | `obj.CAMERA_PAN_SPEED = <value>` |
| CAMERA_TILT_SPEED | CAMERA_TILT_SPEED | number | RW | `obj.CAMERA_TILT_SPEED = <value>` |
| CAMERA_ZOOM_SPEED | CAMERA_ZOOM_SPEED | number | RW | `obj.CAMERA_ZOOM_SPEED = <value>` |
| invertX | invertX | number | RW | `obj.invertX = <value>` |
| invertY | invertY | number | RW | `obj.invertY = <value>` |
| VIEW_DISTANCE | VIEW_DISTANCE | number | RW | `obj.VIEW_DISTANCE = <value>` |
| terrainDetail | terrainDetail | number | RW | `obj.terrainDetail = <value>` |
| terrainDistant | terrainDistant | number | RW | `obj.terrainDistant = <value>` |
| terrainThreshold | terrainThreshold | number | RW | `obj.terrainThreshold = <value>` |
| terrainPatchSize | terrainPatchSize | integer | RW | `obj.terrainPatchSize = <value>` |
| grassRange | grassRange | number | RW | `obj.grassRange = <value>` |
| grassDensity | grassDensity | number | RW | `obj.grassDensity = <value>` |
| foliageRange | foliageRange | number | RW | `obj.foliageRange = <value>` |
| NPCRange | NPCRange | number | RW | `obj.NPCRange = <value>` |
| smallBuildingRange | smallBuildingRange | number | RW | `obj.smallBuildingRange = <value>` |
| stencilsDisabled | stencilsDisabled | boolean | RW | `obj.stencilsDisabled = <value>` |
| fancyShaders | fancyShaders | boolean | RW | `obj.fancyShaders = <value>` |
| HWmouse | HWmouse | boolean | RW | `obj.HWmouse = <value>` |
| tutorials | tutorials | boolean | RW | `obj.tutorials = <value>` |
| _enabledCivilians | _enabledCivilians | boolean | RW | `obj._enabledCivilians = <value>` |
| populationMult | populationMult | number | RW | `obj.populationMult = <value>` |
| squadSizeMult | squadSizeMult | number | RW | `obj.squadSizeMult = <value>` |
| raidSizeMult | raidSizeMult | number | RW | `obj.raidSizeMult = <value>` |
| raidFrequencyMult | raidFrequencyMult | number | RW | `obj.raidFrequencyMult = <value>` |
| passingAttacksOnBase | passingAttacksOnBase | integer | RW | `obj.passingAttacksOnBase = <value>` |
| shadowMode | shadowMode | integer | RW | `obj.shadowMode = <value>` |
| shadowQuality | shadowQuality | integer | RW | `obj.shadowQuality = <value>` |
| harpoonLimit | harpoonLimit | number | RW | `obj.harpoonLimit = <value>` |
| decalRange | decalRange | number | RW | `obj.decalRange = <value>` |
| decalResolution | decalResolution | integer | RW | `obj.decalResolution = <value>` |
| characterMultithreading | characterMultithreading | boolean | RW | `obj.characterMultithreading = <value>` |
| limbLossFrequency | limbLossFrequency | integer | RW | `obj.limbLossFrequency = <value>` |
| showNames | showNames | boolean | RW | `obj.showNames = <value>` |
| edgeScrolling | edgeScrolling | boolean | RW | `obj.edgeScrolling = <value>` |
| damageFloaters | damageFloaters | integer | RW | `obj.damageFloaters = <value>` |
| showRotationMarker | showRotationMarker | boolean | RW | `obj.showRotationMarker = <value>` |
| showMoveMarker | showMoveMarker | boolean | RW | `obj.showMoveMarker = <value>` |
| fontSize | fontSize | number | RW | `obj.fontSize = <value>` |
| manyActiveZones | manyActiveZones | boolean | RW | `obj.manyActiveZones = <value>` |
| distantTownRange | distantTownRange | number | RW | `obj.distantTownRange = <value>` |
| featureRange | featureRange | number | RW | `obj.featureRange = <value>` |
| generateDistantTowns | generateDistantTowns | boolean | RW | `obj.generateDistantTowns = <value>` |
| shadowRange | shadowRange | number | RW | `obj.shadowRange = <value>` |
| ddsTextureMipMapGimping | ddsTextureMipMapGimping | integer | RW | `obj.ddsTextureMipMapGimping = <value>` |
| reflectionMode | reflectionMode | integer | RW | `obj.reflectionMode = <value>` |
| reflectionDistance | reflectionDistance | number | RW | `obj.reflectionDistance = <value>` |
| compositors | compositors | lektor<std::pair<std::string, bool> > | R | `obj.compositors` |
| musicVolume | musicVolume | number | RW | `obj.musicVolume = <value>` |
| ambientVolume | ambientVolume | number | RW | `obj.ambientVolume = <value>` |
| footstepVolume | footstepVolume | number | RW | `obj.footstepVolume = <value>` |
| sfxVolume | sfxVolume | number | RW | `obj.sfxVolume = <value>` |
| uiVolume | uiVolume | number | RW | `obj.uiVolume = <value>` |
| voVolume | voVolume | number | RW | `obj.voVolume = <value>` |
| musicFrequency | musicFrequency | number | RW | `obj.musicFrequency = <value>` |
| autosavetime | autosavetime | number | RW | `obj.autosavetime = <value>` |
| fullscreen | fullscreen | boolean | RW | `obj.fullscreen = <value>` |
| borderless | borderless | boolean | RW | `obj.borderless = <value>` |
| autosave | autosave | boolean | RW | `obj.autosave = <value>` |
| userSaves | userSaves | boolean | RW | `obj.userSaves = <value>` |
| blood | blood | boolean | RW | `obj.blood = <value>` |
| censorship | censorship | boolean | RW | `obj.censorship = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| enabledCivilians | enabledCivilians | `obj:enabledCivilians(...)` |
| characterMultithreadingEnabled | characterMultithreadingEnabled | `obj:characterMultithreadingEnabled(...)` |
| compositiorEnabled | compositiorEnabled | `obj:compositiorEnabled(...)` |
| loadCompositorSettings | loadCompositorSettings | `obj:loadCompositorSettings(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Ownerships
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| slaves | slaves | std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > | R | `obj.slaves` |
| _homeTown | _homeTown | TownBase* | R | `obj._homeTown` |
| _homeBuilding | _homeBuilding | hand | RW | `obj._homeBuilding = <value>` |
| stuff | stuff | lektor<hand> | R | `obj.stuff` |
| faction | faction | Faction | R | `obj.faction` |
| me | me | Platoon | R | `obj.me` |
| occupiedTown | occupiedTown | TownBase* | R | `obj.occupiedTown` |
| money | money | integer | RW | `obj.money = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| _NV_takeMoney | _NV_takeMoney | `obj:_NV_takeMoney(...)` |
| takeMoneyByForce | takeMoneyByForce | `obj:takeMoneyByForce(...)` |
| _NV_takeMoneyByForce | _NV_takeMoneyByForce | `obj:_NV_takeMoneyByForce(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| addMoney | addMoney | `obj:addMoney(...)` |
| setMoney | setMoney | `obj:setMoney(...)` |
| setHomeBuildingDesignation | setHomeBuildingDesignation | `obj:setHomeBuildingDesignation(...)` |
| getOccupiedTownFaction | getOccupiedTownFaction | `obj:getOccupiedTownFaction(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| _characterCountCurrent | _characterCountCurrent | integer | RW | `obj._characterCountCurrent = <value>` |
| _characterCountOriginal | _characterCountOriginal | integer | RW | `obj._characterCountOriginal = <value>` |
| squadType | (lua_Integer | integer | RW | `obj.squadType = <value>` |
| hasUniques | hasUniques | YesNoMaybe | R | `obj.hasUniques` |
| speedOverride | (lua_Integer | integer | RW | `obj.speedOverride = <value>` |
| isSeparatedSquad | isSeparatedSquad | hand | RW | `obj.isSeparatedSquad = <value>` |
| canRefresh | canRefresh | boolean | RW | `obj.canRefresh = <value>` |
| regenerates | regenerates | boolean | RW | `obj.regenerates = <value>` |
| myBaseHomeTownData | myBaseHomeTownData | GameData | R | `obj.myBaseHomeTownData` |
| priceMultWhenITrade | priceMultWhenITrade | number | RW | `obj.priceMultWhenITrade = <value>` |
| _iBuyStolenGoods | _iBuyStolenGoods | boolean | RW | `obj._iBuyStolenGoods = <value>` |
| _iBuyIllegalGoods | _iBuyIllegalGoods | boolean | RW | `obj._iBuyIllegalGoods = <value>` |
| locatorModel | locatorModel | Ogre::Entity* | R | `obj.locatorModel` |
| blackboard | blackboard | Blackboard* | R | `obj.blackboard` |
| _isIntact | _isIntact | boolean | RW | `obj._isIntact = <value>` |
| squadTemplate | squadTemplate | GameData | R | `obj.squadTemplate` |
| malnourishedLevel | malnourishedLevel | number | RW | `obj.malnourishedLevel = <value>` |
| hasNeverBeenActivated | hasNeverBeenActivated | boolean | RW | `obj.hasNeverBeenActivated = <value>` |
| _persistentSquad | _persistentSquad | boolean | RW | `obj._persistentSquad = <value>` |
| isResidentSquad | isResidentSquad | boolean | RW | `obj.isResidentSquad = <value>` |
| messageOnActivation | messageOnActivation | PlatoonCreationMessage | R | `obj.messageOnActivation` |
| currentSpawnArea | currentSpawnArea | AreaSector* | R | `obj.currentSpawnArea` |
| squadleader | squadleader | hand | RW | `obj.squadleader = <value>` |
| ownerships | ownerships | Ownerships | R | `obj.ownerships` |
| activePlatoon | activePlatoon | ActivePlatoon* | R | `obj.activePlatoon` |
| unloadedPlatoon | unloadedPlatoon | UnloadedPlatoon* | R | `obj.unloadedPlatoon` |
| patrolSettings | patrolSettings | PatrolInfo* | R | `obj.patrolSettings` |
| isDead | isDead | boolean | RW | `obj.isDead = <value>` |
| imprisoned | imprisoned | boolean | RW | `obj.imprisoned = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| traderInventoryRefreshTime | traderInventoryRefreshTime | TimeOfDay | R | `obj.traderInventoryRefreshTime` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| setCharacterCount | setCharacterCount | `obj:setCharacterCount(...)` |
| isUnconcious | isUnconcious | `obj:isUnconcious(...)` |
| _NV_isUnconcious | _NV_isUnconcious | `obj:_NV_isUnconcious(...)` |
| getSquadType | getSquadType | `obj:getSquadType(...)` |
| setSquadType | setSquadType | `obj:setSquadType(...)` |
| iBuyIllegalGoods | iBuyIllegalGoods | `obj:iBuyIllegalGoods(...)` |
| getPlatoonStringID | getPlatoonStringID | `obj:getPlatoonStringID(...)` |
| getDataType | getDataType | `obj:getDataType(...)` |
| _NV_getDataType | _NV_getDataType | `obj:_NV_getDataType(...)` |
| erasePlatoonFile | erasePlatoonFile | `obj:erasePlatoonFile(...)` |
| showDebugMarker | showDebugMarker | `obj:showDebugMarker(...)` |
| setDataFilename | setDataFilename | `obj:setDataFilename(...)` |
| isIntact | isIntact | `obj:isIntact(...)` |
| notifyMissionEnded | notifyMissionEnded | `obj:notifyMissionEnded(...)` |
| _NV_notifyMissionEnded | _NV_notifyMissionEnded | `obj:_NV_notifyMissionEnded(...)` |
| activate | activate | `obj:activate(...)` |
| declareDead | declareDead | `obj:declareDead(...)` |
| undeclareDead | undeclareDead | `obj:undeclareDead(...)` |
| isFullyLoaded | isFullyLoaded | `obj:isFullyLoaded(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| periodicUpdate_active | periodicUpdate_active | `obj:periodicUpdate_active(...)` |
| _NV_periodicUpdate_active | _NV_periodicUpdate_active | `obj:_NV_periodicUpdate_active(...)` |
| periodicUpdate_unloaded | periodicUpdate_unloaded | `obj:periodicUpdate_unloaded(...)` |
| _NV_periodicUpdate_unloaded | _NV_periodicUpdate_unloaded | `obj:_NV_periodicUpdate_unloaded(...)` |
| setupPatrolSettings | setupPatrolSettings | `obj:setupPatrolSettings(...)` |
| isPersistentSquad | isPersistentSquad | `obj:isPersistentSquad(...)` |
| setPersistentSquad | setPersistentSquad | `obj:setPersistentSquad(...)` |
| getOwnerships | getOwnerships | `obj:getOwnerships(...)` |
| _NV_getOwnerships | _NV_getOwnerships | `obj:_NV_getOwnerships(...)` |
| getNearestActiveCharacter | getNearestActiveCharacter | `obj:getNearestActiveCharacter(...)` |
| getSquadLeader | getSquadLeader | `obj:getSquadLeader(...)` |
| getCharacterCount | getCharacterCount | `obj:getCharacterCount(...)` |
| getCharacterCount_Original | getCharacterCount_Original | `obj:getCharacterCount_Original(...)` |
| needsNewCharacters | needsNewCharacters | `obj:needsNewCharacters(...)` |
| reCheckPersistenceOnUnload | reCheckPersistenceOnUnload | `obj:reCheckPersistenceOnUnload(...)` |
| _NV_reCheckPersistenceOnUnload | _NV_reCheckPersistenceOnUnload | `obj:_NV_reCheckPersistenceOnUnload(...)` |
| chooseNewHome | Platoon_chooseNewHome | `obj:chooseNewHome(...)` |
| getCurrentTownLocation | Platoon_getCurrentTownLocation | `obj:getCurrentTownLocation(...)` |
| _NV_getCurrentTownLocation | Platoon__NV_getCurrentTownLocation | `obj:_NV_getCurrentTownLocation(...)` |
| setFaction | Platoon_setFaction | `obj:setFaction(...)` |
| _NV_setFaction | Platoon__NV_setFaction | `obj:_NV_setFaction(...)` |
| getActivePlatoon | Platoon_getActivePlatoon | `obj:getActivePlatoon(...)` |
| getSquadLeader_theRealOne | Platoon_getSquadLeader_theRealOne | `obj:getSquadLeader_theRealOne(...)` |

## PlayerInterface
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| factionName | factionName | string | RW | `obj.factionName = <value>` |
| camera | camera | CameraClass | R | `obj.camera` |
| technology | technology | Research* | R | `obj.technology` |
| selectedObjectsChangedThisFrame | selectedObjectsChangedThisFrame | boolean | RW | `obj.selectedObjectsChangedThisFrame = <value>` |
| contextMenu | contextMenu | ContextMenu | R | `obj.contextMenu` |
| selectBox | selectBox | SelectionBox | R | `obj.selectBox` |
| moveMarker | moveMarker | MoveMarker* | R | `obj.moveMarker` |
| selectedCharacter | selectedCharacter | hand | RW | `obj.selectedCharacter = <value>` |
| aiOptions | aiOptions | PlayerInterface::AIOptions | R | `obj.aiOptions` |
| zonesVisibilities | zonesVisibilities | ogre_unordered_map<ZoneMap*, unsigned char>::type | R | `obj.zonesVisibilities` |
| townsActive | townsActive | ogre_unordered_set<TownBase*>::type | R | `obj.townsActive` |
| interiorsVisible | interiorsVisible | ogre_unordered_set<hand>::type | R | `obj.interiorsVisible` |
| interiorsVisibleHash | interiorsVisibleHash | integer | RW | `obj.interiorsVisibleHash = <value>` |
| currentFloor | currentFloor | integer | RW | `obj.currentFloor = <value>` |
| currentMouseTask | (lua_Integer | integer | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | (lua_Integer | integer | RW | `obj.mouseTaskTypeRestriction = <value>` |
| mouseRightTargetSet | mouseRightTargetSet | boolean | RW | `obj.mouseRightTargetSet = <value>` |
| mouseRightTarget | mouseRightTarget | RootObject | R | `obj.mouseRightTarget` |
| rmouseTimer | rmouseTimer | number | RW | `obj.rmouseTimer = <value>` |
| selectedCharacters | selectedCharacters | ogre_unordered_set<hand>::type | R | `obj.selectedCharacters` |
| selectedObject | selectedObject | hand | RW | `obj.selectedObject = <value>` |
| onlyAnimalsSelected | onlyAnimalsSelected | boolean | RW | `obj.onlyAnimalsSelected = <value>` |
| selectedLoadedLeft | selectedLoadedLeft | integer | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterHandle | trackedCharacterHandle | hand | RW | `obj.trackedCharacterHandle = <value>` |
| trackedCharacterFloor | trackedCharacterFloor | integer | RW | `obj.trackedCharacterFloor = <value>` |
| levelEditor | levelEditor | LevelEditor* | R | `obj.levelEditor` |
| participant | participant | Faction | R | `obj.participant` |
| currentPlatoon | currentPlatoon | Platoon | R | `obj.currentPlatoon` |
| playerCharacters | playerCharacters | lektor<Character*> | R | `obj.playerCharacters` |
| deadPlayerSquad | deadPlayerSquad | hand | RW | `obj.deadPlayerSquad = <value>` |
| placementObject | placementObject | PlacementObject* | R | `obj.placementObject` |
| characterEditorMode | characterEditorMode | boolean | RW | `obj.characterEditorMode = <value>` |
| mLeftUp | mLeftUp | boolean | RW | `obj.mLeftUp = <value>` |
| mLeftDown | mLeftDown | boolean | RW | `obj.mLeftDown = <value>` |
| mRightUp | mRightUp | boolean | RW | `obj.mRightUp = <value>` |
| mRightDown | mRightDown | boolean | RW | `obj.mRightDown = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getCamera | getCamera | `obj:getCamera(...)` |
| clearAndReset | clearAndReset | `obj:clearAndReset(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| getCurrentPlatoon | getCurrentPlatoon | `obj:getCurrentPlatoon(...)` |
| getCurrentActivePlatoon | getCurrentActivePlatoon | `obj:getCurrentActivePlatoon(...)` |
| update | update | `obj:update(...)` |
| updateUT | updateUT | `obj:updateUT(...)` |
| isBuildMode | isBuildMode | `obj:isBuildMode(...)` |
| setCharacterEditMode | setCharacterEditMode | `obj:setCharacterEditMode(...)` |
| getCharacterEditMode | getCharacterEditMode | `obj:getCharacterEditMode(...)` |
| unselectAll | unselectAll | `obj:unselectAll(...)` |
| selectAll | selectAll | `obj:selectAll(...)` |
| selectPlayerCharacter | selectPlayerCharacter | `obj:selectPlayerCharacter(...)` |
| getCameraCenter | getCameraCenter | `obj:getCameraCenter(...)` |
| getDistanceFromCamera | getDistanceFromCamera | `obj:getDistanceFromCamera(...)` |
| getSquaredDistanceFromCamera | getSquaredDistanceFromCamera | `obj:getSquaredDistanceFromCamera(...)` |
| stopTrackCharacter | stopTrackCharacter | `obj:stopTrackCharacter(...)` |
| isTrackingCharacter | isTrackingCharacter | `obj:isTrackingCharacter(...)` |
| focusCamera | focusCamera | `obj:focusCamera(...)` |
| manuallyOrientCamera | manuallyOrientCamera | `obj:manuallyOrientCamera(...)` |
| focusCameraSelectedCharacter | focusCameraSelectedCharacter | `obj:focusCameraSelectedCharacter(...)` |
| toggleLevelEditorOnSelectedTown | toggleLevelEditorOnSelectedTown | `obj:toggleLevelEditorOnSelectedTown(...)` |
| isLevelEditMode | isLevelEditMode | `obj:isLevelEditMode(...)` |
| isObjectPlacementMode | isObjectPlacementMode | `obj:isObjectPlacementMode(...)` |
| setOrderSelectedCharacters | setOrderSelectedCharacters | `obj:setOrderSelectedCharacters(...)` |
| getCurrentFloor | getCurrentFloor | `obj:getCurrentFloor(...)` |
| setCurrentFloor | setCurrentFloor | `obj:setCurrentFloor(...)` |
| getNearestSelectedCharacterTo | getNearestSelectedCharacterTo | `obj:getNearestSelectedCharacterTo(...)` |
| getNearestCharacterTo | getNearestCharacterTo | `obj:getNearestCharacterTo(...)` |
| removeJobSelectedCharacters | removeJobSelectedCharacters | `obj:removeJobSelectedCharacters(...)` |
| removePermaJobSelectedCharacters | removePermaJobSelectedCharacters | `obj:removePermaJobSelectedCharacters(...)` |
| selectedCharactersUnconcious | selectedCharactersUnconcious | `obj:selectedCharactersUnconcious(...)` |
| selectedCharactersLayingLow | selectedCharactersLayingLow | `obj:selectedCharactersLayingLow(...)` |
| useSpeedGroup | useSpeedGroup | `obj:useSpeedGroup(...)` |
| assignSpeedGroup | assignSpeedGroup | `obj:assignSpeedGroup(...)` |
| cycleSquad | cycleSquad | `obj:cycleSquad(...)` |
| cycleCharacter | cycleCharacter | `obj:cycleCharacter(...)` |
| stopCharactersMovement | stopCharactersMovement | `obj:stopCharactersMovement(...)` |
| getAnyPlayerCharacter | getAnyPlayerCharacter | `obj:getAnyPlayerCharacter(...)` |
| isOrderValidForSelection | isOrderValidForSelection | `obj:isOrderValidForSelection(...)` |
| setVisibilityForReflections | setVisibilityForReflections | `obj:setVisibilityForReflections(...)` |
| resetFloorsVisibility | resetFloorsVisibility | `obj:resetFloorsVisibility(...)` |
| setFloorsVisibility | setFloorsVisibility | `obj:setFloorsVisibility(...)` |
| clearSelection | clearSelection | `obj:clearSelection(...)` |
| mouseScan | mouseScan | `obj:mouseScan(...)` |

## RaceData
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| specialFoods | specialFoods | ogre_unordered_set<GameData*>::type | R | `obj.specialFoods` |
| data | data | GameData | R | `obj.data` |
| runSpeedMaxSkill | runSpeedMaxSkill | number | RW | `obj.runSpeedMaxSkill = <value>` |
| runSpeedMinSkill | runSpeedMinSkill | number | RW | `obj.runSpeedMinSkill = <value>` |
| originalBloodMin | originalBloodMin | number | RW | `obj.originalBloodMin = <value>` |
| originalBloodMax | originalBloodMax | number | RW | `obj.originalBloodMax = <value>` |
| healRate | healRate | number | RW | `obj.healRate = <value>` |
| bleedRate | bleedRate | number | RW | `obj.bleedRate = <value>` |
| swimSpeed | swimSpeed | number | RW | `obj.swimSpeed = <value>` |
| walkSpeed | walkSpeed | number | RW | `obj.walkSpeed = <value>` |
| swimOffset | swimOffset | number | RW | `obj.swimOffset = <value>` |
| waterAvoidance | waterAvoidance | number | RW | `obj.waterAvoidance = <value>` |
| hungerRate | hungerRate | number | RW | `obj.hungerRate = <value>` |
| visionMultiplier | visionMultiplier | number | RW | `obj.visionMultiplier = <value>` |
| gigantic | gigantic | boolean | RW | `obj.gigantic = <value>` |
| swims | swims | boolean | RW | `obj.swims = <value>` |
| carriable | carriable | boolean | RW | `obj.carriable = <value>` |
| singleGender | singleGender | boolean | RW | `obj.singleGender = <value>` |
| robot | robot | boolean | RW | `obj.robot = <value>` |
| vampiric | vampiric | boolean | RW | `obj.vampiric = <value>` |
| noHats | noHats | boolean | RW | `obj.noHats = <value>` |
| noShirts | noShirts | boolean | RW | `obj.noShirts = <value>` |
| noShoes | noShoes | boolean | RW | `obj.noShoes = <value>` |
| extraAttackSlots | extraAttackSlots | integer | RW | `obj.extraAttackSlots = <value>` |
| firstAidSkill | (lua_Integer | integer | RW | `obj.firstAidSkill = <value>` |
| bloodColour | bloodColour | Ogre::ColourValue | R | `obj.bloodColour` |
| canGoIndoors | canGoIndoors | boolean | RW | `obj.canGoIndoors = <value>` |
| statMods | statMods | ogre_unordered_map<StatsEnumerated, float>::type | R | `obj.statMods` |
| weatherImmunities | weatherImmunities | ogre_unordered_set<WeatherAffecting>::type | R | `obj.weatherImmunities` |
| raceGroup | raceGroup | RaceGroupData* | R | `obj.raceGroup` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getStatMod | getStatMod | `obj:getStatMod(...)` |
| isImmune | isImmune | `obj:isImmune(...)` |

## RaceLimiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| limits | limits | ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type | R | `obj.limits` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## RelationData
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| alliance | alliance | boolean | RW | `obj.alliance = <value>` |
| peaceTreaty | peaceTreaty | boolean | RW | `obj.peaceTreaty = <value>` |
| war | war | boolean | RW | `obj.war = <value>` |
| coexists | coexists | boolean | RW | `obj.coexists = <value>` |
| relation | relation | number | RW | `obj.relation = <value>` |
| trustPositives | trustPositives | number | RW | `obj.trustPositives = <value>` |
| trustNegatives | trustNegatives | number | RW | `obj.trustNegatives = <value>` |
| percievedStrength | percievedStrength | number | RW | `obj.percievedStrength = <value>` |
| stateVariables | stateVariables | std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > | R | `obj.stateVariables` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## RepetitionCounter
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| states | states | std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > > | R | `obj.states` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| setup | setup | `obj:setup(...)` |
| count | count | `obj:count(...)` |
| getTimeSinceLastTrigger | getTimeSinceLastTrigger | `obj:getTimeSinceLastTrigger(...)` |
| getCount | getCount | `obj:getCount(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## RobotLimbs
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| character | character | Character | R | `obj.character` |
| inventory | inventory | RootObject | R | `obj.inventory` |
| states | states | LimbState | R | `obj.states` |
| items | items | Item | R | `obj.items` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getLimb | getLimb | `obj:getLimb(...)` |
| getMask | getMask | `obj:getMask(...)` |
| getInventoryInterface | getInventoryInterface | `obj:getInventoryInterface(...)` |
| destroyInventoryInterface | destroyInventoryInterface | `obj:destroyInventoryInterface(...)` |
| getLimbItem | getLimbItem | `obj:getLimbItem(...)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| container | container | RootObjectContainer | R | `obj.container` |
| isInsideBuilding | isInsideBuilding | hand | RW | `obj.isInsideBuilding = <value>` |
| isInsideTownWalls | isInsideTownWalls | integer | RW | `obj.isInsideTownWalls = <value>` |
| floorNum | floorNum | integer | RW | `obj.floorNum = <value>` |
| spacialKey | spacialKey | integer | RW | `obj.spacialKey = <value>` |
| outdoorDelayNotification_timer | outdoorDelayNotification_timer | integer | RW | `obj.outdoorDelayNotification_timer = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| needsSaving | needsSaving | `obj:needsSaving(...)` |
| _NV_needsSaving | _NV_needsSaving | `obj:_NV_needsSaving(...)` |
| getOrientation | getOrientation | `obj:getOrientation(...)` |
| _NV_getOrientation | _NV_getOrientation | `obj:_NV_getOrientation(...)` |
| getRace | getRace | `obj:getRace(...)` |
| _NV_getRace | _NV_getRace | `obj:_NV_getRace(...)` |
| threadedUpdate | threadedUpdate | `obj:threadedUpdate(...)` |
| _NV_threadedUpdate | _NV_threadedUpdate | `obj:_NV_threadedUpdate(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| isPhysical | isPhysical | `obj:isPhysical(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| _NV_getVisible | _NV_getVisible | `obj:_NV_getVisible(...)` |
| isDisabled | isDisabled | `obj:isDisabled(...)` |
| _NV_isDisabled | _NV_isDisabled | `obj:_NV_isDisabled(...)` |
| amInsideTownWalls | amInsideTownWalls | `obj:amInsideTownWalls(...)` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `obj:_NV_amInsideTownWalls(...)` |
| setInsideTownWalls | setInsideTownWalls | `obj:setInsideTownWalls(...)` |
| _NV_setInsideTownWalls | _NV_setInsideTownWalls | `obj:_NV_setInsideTownWalls(...)` |
| getFloor | getFloor | `obj:getFloor(...)` |
| _NV_getFloor | _NV_getFloor | `obj:_NV_getFloor(...)` |
| setFloor | setFloor | `obj:setFloor(...)` |
| _NV_setFloor | _NV_setFloor | `obj:_NV_setFloor(...)` |
| select | select | `obj:select(...)` |
| _NV_select | _NV_select | `obj:_NV_select(...)` |
| unselect | unselect | `obj:unselect(...)` |
| _NV_unselect | _NV_unselect | `obj:_NV_unselect(...)` |
| setStandingOrder | setStandingOrder | `obj:setStandingOrder(...)` |
| _NV_setStandingOrder | _NV_setStandingOrder | `obj:_NV_setStandingOrder(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| _NV_getInventory | _NV_getInventory | `obj:_NV_getInventory(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| _NV_takeMoney | _NV_takeMoney | `obj:_NV_takeMoney(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| _NV_getMoney | _NV_getMoney | `obj:_NV_getMoney(...)` |
| say | say | `obj:say(...)` |
| _NV_say | _NV_say | `obj:_NV_say(...)` |
| notifyOutdoors | notifyOutdoors | `obj:notifyOutdoors(...)` |
| _NV_notifyOutdoors | _NV_notifyOutdoors | `obj:_NV_notifyOutdoors(...)` |
| isOnARoof | isOnARoof | `obj:isOnARoof(...)` |
| _NV_isOnARoof | _NV_isOnARoof | `obj:_NV_isOnARoof(...)` |
| getIntendedAggression | getIntendedAggression | `obj:getIntendedAggression(...)` |
| _NV_getIntendedAggression | _NV_getIntendedAggression | `obj:_NV_getIntendedAggression(...)` |
| createPhysical | createPhysical | `obj:createPhysical(...)` |
| destroyPhysical | destroyPhysical | `obj:destroyPhysical(...)` |
| notifyEffect | notifyEffect | `obj:notifyEffect(...)` |
| _NV_notifyEffect | _NV_notifyEffect | `obj:_NV_notifyEffect(...)` |
| loadUnloadCheck | loadUnloadCheck | `obj:loadUnloadCheck(...)` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `obj:_NV_loadUnloadCheck(...)` |
| setFaction | RootObject_setFaction | `obj:setFaction(...)` |
| _NV_setFaction | RootObject__NV_setFaction | `obj:_NV_setFaction(...)` |
| giveItem | RootObject_giveItem | `obj:giveItem(...)` |
| _NV_giveItem | RootObject__NV_giveItem | `obj:_NV_giveItem(...)` |
| hasItem | RootObject_hasItem | `obj:hasItem(...)` |
| _NV_hasItem | RootObject__NV_hasItem | `obj:_NV_hasItem(...)` |
| equipItem | RootObject_equipItem | `obj:equipItem(...)` |
| _NV_equipItem | RootObject__NV_equipItem | `obj:_NV_equipItem(...)` |
| unequipItem | RootObject_unequipItem | `obj:unequipItem(...)` |
| _NV_unequipItem | RootObject__NV_unequipItem | `obj:_NV_unequipItem(...)` |
| dropItem | RootObject_dropItem | `obj:dropItem(...)` |
| _NV_dropItem | RootObject__NV_dropItem | `obj:_NV_dropItem(...)` |
| isIndoors | RootObject_isIndoors | `obj:isIndoors(...)` |
| _NV_isIndoors | RootObject__NV_isIndoors | `obj:_NV_isIndoors(...)` |
| setIsInsideBuilding | RootObject_setIsInsideBuilding | `obj:setIsInsideBuilding(...)` |
| _NV_setIsInsideBuilding | RootObject__NV_setIsInsideBuilding | `obj:_NV_setIsInsideBuilding(...)` |

## RootObjectBase
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| validKey | validKey | integer | RW | `obj.validKey = <value>` |
| owner | owner | Faction | R | `obj.owner` |
| displayName | displayName | string | RW | `obj.displayName = <value>` |
| data | data | GameData | R | `obj.data` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| handle | handle | hand | RW | `obj.handle = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| isValid | isValid | `obj:isValid(...)` |
| getName | getName | `obj:getName(...)` |
| _NV_getName | _NV_getName | `obj:_NV_getName(...)` |
| setName | setName | `obj:setName(...)` |
| _NV_setName | _NV_setName | `obj:_NV_setName(...)` |
| getGameData | getGameData | `obj:getGameData(...)` |
| _NV_getGameData | _NV_getGameData | `obj:_NV_getGameData(...)` |
| getDataType | getDataType | `obj:getDataType(...)` |
| _NV_getDataType | _NV_getDataType | `obj:_NV_getDataType(...)` |
| typeIsAnItem | typeIsAnItem | `obj:typeIsAnItem(...)` |
| _NV_typeIsAnItem | _NV_typeIsAnItem | `obj:_NV_typeIsAnItem(...)` |
| isUnconcious | isUnconcious | `obj:isUnconcious(...)` |
| _NV_isUnconcious | _NV_isUnconcious | `obj:_NV_isUnconcious(...)` |
| getPositionForWaypoint | getPositionForWaypoint | `obj:getPositionForWaypoint(...)` |
| _NV_getPositionForWaypoint | _NV_getPositionForWaypoint | `obj:_NV_getPositionForWaypoint(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| _NV_getPosition | _NV_getPosition | `obj:_NV_getPosition(...)` |
| getMovementSpeed | getMovementSpeed | `obj:getMovementSpeed(...)` |
| _NV_getMovementSpeed | _NV_getMovementSpeed | `obj:_NV_getMovementSpeed(...)` |
| getMovementDirection | getMovementDirection | `obj:getMovementDirection(...)` |
| _NV_getMovementDirection | _NV_getMovementDirection | `obj:_NV_getMovementDirection(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| _NV_getFaction | _NV_getFaction | `obj:_NV_getFaction(...)` |
| hasFaction | hasFaction | `obj:hasFaction(...)` |
| getFloor | getFloor | `obj:getFloor(...)` |
| _NV_getFloor | _NV_getFloor | `obj:_NV_getFloor(...)` |
| getOwnerships | getOwnerships | `obj:getOwnerships(...)` |
| _NV_getOwnerships | _NV_getOwnerships | `obj:_NV_getOwnerships(...)` |
| getHandle | RootObjectBase_getHandle | `obj:getHandle(...)` |
| getCurrentTownLocation | RootObjectBase_getCurrentTownLocation | `obj:getCurrentTownLocation(...)` |
| _NV_getCurrentTownLocation | RootObjectBase__NV_getCurrentTownLocation | `obj:_NV_getCurrentTownLocation(...)` |
| setFaction | RootObjectBase_setFaction | `obj:setFaction(...)` |
| _NV_setFaction | RootObjectBase__NV_setFaction | `obj:_NV_setFaction(...)` |

## RootObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| things | things | lektor<RootObject*> | R | `obj.things` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| getThing | getThing | `obj:getThing(...)` |
| getNumThings | getNumThings | `obj:getNumThings(...)` |

## RootObjectFactory
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| todoMutex | todoMutex | unknown | R | `obj.todoMutex` |
| todoList | todoList | std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> > | R | `obj.todoList` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| mainThreadUpdate | mainThreadUpdate | `obj:mainThreadUpdate(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| create | create | `obj:create(...)` |
| createBuilding | createBuilding | `obj:createBuilding(...)` |
| createLocationNode | createLocationNode | `obj:createLocationNode(...)` |
| createItem | createItem | `obj:createItem(...)` |
| copyItem | copyItem | `obj:copyItem(...)` |
| chooseDataFromList | chooseDataFromList | `obj:chooseDataFromList(...)` |
| chooseDataFromListWithVals | chooseDataFromListWithVals | `obj:chooseDataFromListWithVals(...)` |
| getValsFromDataInList | getValsFromDataInList | `obj:getValsFromDataInList(...)` |
| createCharacterForBuilding | createCharacterForBuilding | `obj:createCharacterForBuilding(...)` |
| createRandomCharacter | createRandomCharacter | `obj:createRandomCharacter(...)` |
| createRandomUnloadedCharacter | createRandomUnloadedCharacter | `obj:createRandomUnloadedCharacter(...)` |
| createRandomSquad | createRandomSquad | `obj:createRandomSquad(...)` |
| createRandomUnloadedSquad | createRandomUnloadedSquad | `obj:createRandomUnloadedSquad(...)` |
| populateBuilding | populateBuilding | `obj:populateBuilding(...)` |
| process | process | `obj:process(...)` |

## SectionItem
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| item | item | Item | R | `obj.item` |
| x | x | integer | RW | `obj.x = <value>` |
| y | y | integer | RW | `obj.y = <value>` |
| w | w | integer | RW | `obj.w = <value>` |
| h | h | integer | RW | `obj.h = <value>` |

## SeenSomeone
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lastPosition | lastPosition | Vector3 | RW | `obj.lastPosition = <value>` |
| lastSeenTime | lastSeenTime | TimeOfDay | R | `obj.lastSeenTime` |
| percievedFaction | percievedFaction | Faction | R | `obj.percievedFaction` |
| percievedSlave | (lua_Integer | integer | RW | `obj.percievedSlave = <value>` |
| FOVScore | FOVScore | number | RW | `obj.FOVScore = <value>` |
| type | type | TagsClass<SenseType> | R | `obj.type` |
| canSee | canSee | boolean | RW | `obj.canSee = <value>` |
| canHear | canHear | boolean | RW | `obj.canHear = <value>` |
| alarmState | alarmState | number | RW | `obj.alarmState = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| lastSeenInSeconds | lastSeenInSeconds | `obj:lastSeenInSeconds(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |

## SelectionBox
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| startPos | startPos | Ogre::Vector2 | R | `obj.startPos` |
| volume | volume | Ogre::PlaneBoundedVolume | R | `obj.volume` |
| widget | (lua_Integer | integer | R | `obj.widget` |
| active | active | boolean | RW | `obj.active = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| cancel | cancel | `obj:cancel(...)` |
| isActive | isActive | `obj:isActive(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## SenseItr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| it | it | boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > > | R | `obj.it` |
| _end | _end | boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > > | R | `obj._end` |
| flagsAny | flagsAny | integer | RW | `obj.flagsAny = <value>` |
| flagsNot | flagsNot | integer | RW | `obj.flagsNot = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| ended | ended | `obj:ended(...)` |
| increment | increment | `obj:increment(...)` |

## SensoryData
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nearestEnemy | nearestEnemy | number | RW | `obj.nearestEnemy = <value>` |
| seen | seen | ogre_unordered_map<hand, SeenSomeone*>::type | R | `obj.seen` |
| numUnconsciousAllies | numUnconsciousAllies | integer | RW | `obj.numUnconsciousAllies = <value>` |
| numConsciousAllies | numConsciousAllies | integer | RW | `obj.numConsciousAllies = <value>` |
| threats | threats | lektor<hand> | R | `obj.threats` |
| flockingList | flockingList | Ogre::vector<VisibleObjectInfo>::type | R | `obj.flockingList` |
| totalThreatLevelPersonal | totalThreatLevelPersonal | number | RW | `obj.totalThreatLevelPersonal = <value>` |
| totalThreatLevelAllies | totalThreatLevelAllies | number | RW | `obj.totalThreatLevelAllies = <value>` |
| totalIntendedThreatLevelGeneral | totalIntendedThreatLevelGeneral | number | RW | `obj.totalIntendedThreatLevelGeneral = <value>` |
| numEnemies | numEnemies | integer | RW | `obj.numEnemies = <value>` |
| numNeutrals | numNeutrals | integer | RW | `obj.numNeutrals = <value>` |
| lastThreat | lastThreat | number | RW | `obj.lastThreat = <value>` |
| hearTestTimers | hearTestTimers | std::map<hand, float, std::less<hand>, std::allocator<std::pair<hand const, float> > > | R | `obj.hearTestTimers` |
| killList | killList | ogre_unordered_set<hand>::type | R | `obj.killList` |
| currentAssessIndex | currentAssessIndex | integer | RW | `obj.currentAssessIndex = <value>` |
| currentAssessList | currentAssessList | integer | RW | `obj.currentAssessList = <value>` |
| assessList | assessList | ogre_unordered_set<hand>::type | R | `obj.assessList` |
| me | me | Character | R | `obj.me` |
| spottedSneakingPeople | spottedSneakingPeople | SensoryData::SpottingPeopleMgr | R | `obj.spottedSneakingPeople` |
| spottedSuspiciousPeople | spottedSuspiciousPeople | SensoryData::SpottingPeopleMgr | R | `obj.spottedSuspiciousPeople` |
| progressBar | progressBar | FloatingProgressBar* | R | `obj.progressBar` |
| progressBarStillNeeded | progressBarStillNeeded | integer | RW | `obj.progressBarStillNeeded = <value>` |
| spottedGuyIndexForProgressBar | spottedGuyIndexForProgressBar | hand | R | `obj.spottedGuyIndexForProgressBar` |
| amSharingThisFrame | amSharingThisFrame | boolean | RW | `obj.amSharingThisFrame = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| periodicUpdate_KOed | periodicUpdate_KOed | `obj:periodicUpdate_KOed(...)` |
| getVisionRange | getVisionRange | `obj:getVisionRange(...)` |
| update | update | `obj:update(...)` |
| notifyKO | notifyKO | `obj:notifyKO(...)` |
| getNearestEnemyDistanceSq | getNearestEnemyDistanceSq | `obj:getNearestEnemyDistanceSq(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| dialogAssessmentUpdate | dialogAssessmentUpdate | `obj:dialogAssessmentUpdate(...)` |
| processKillList | processKillList | `obj:processKillList(...)` |
| updateMyProgressBar | updateMyProgressBar | `obj:updateMyProgressBar(...)` |
| buildingSpotterUpdate | buildingSpotterUpdate | `obj:buildingSpotterUpdate(...)` |

## ShopTrader
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| trader | trader | Character | R | `obj.trader` |
| inventory | inventory | Inventory | R | `obj.inventory` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| _NV_getInventory | _NV_getInventory | `obj:_NV_getInventory(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| _NV_takeMoney | _NV_takeMoney | `obj:_NV_takeMoney(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| _NV_getMoney | _NV_getMoney | `obj:_NV_getMoney(...)` |
| getOrientation | getOrientation | `obj:getOrientation(...)` |
| _NV_getOrientation | _NV_getOrientation | `obj:_NV_getOrientation(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| _NV_getPosition | _NV_getPosition | `obj:_NV_getPosition(...)` |
| getFloor | getFloor | `obj:getFloor(...)` |
| _NV_getFloor | _NV_getFloor | `obj:_NV_getFloor(...)` |
| getCurrentTownLocation | getCurrentTownLocation | `obj:getCurrentTownLocation(...)` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `obj:_NV_getCurrentTownLocation(...)` |
| getDataType | getDataType | `obj:getDataType(...)` |
| _NV_getDataType | _NV_getDataType | `obj:_NV_getDataType(...)` |
| getTrader | getTrader | `obj:getTrader(...)` |
| isPhysical | isPhysical | `obj:isPhysical(...)` |
| _NV_isPhysical | _NV_isPhysical | `obj:_NV_isPhysical(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| _NV_setVisible | _NV_setVisible | `obj:_NV_setVisible(...)` |
| createPhysical | createPhysical | `obj:createPhysical(...)` |
| _NV_createPhysical | _NV_createPhysical | `obj:_NV_createPhysical(...)` |
| destroyPhysical | destroyPhysical | `obj:destroyPhysical(...)` |
| _NV_destroyPhysical | _NV_destroyPhysical | `obj:_NV_destroyPhysical(...)` |
| updateInventory | updateInventory | `obj:updateInventory(...)` |
| equipItem | equipItem | `obj:equipItem(...)` |
| _NV_equipItem | _NV_equipItem | `obj:_NV_equipItem(...)` |
| unequipItem | unequipItem | `obj:unequipItem(...)` |
| _NV_unequipItem | _NV_unequipItem | `obj:_NV_unequipItem(...)` |

## ShopTraderInventory
**Header:** `extern/KenshiLib/Include/kenshi/ShopTraderInventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| inventories | inventories | ogre_unordered_map<hand, InventorySection*>::type | R | `obj.inventories` |
| section | (void* | lightuserdata | R | `obj.section` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| updateInventory | updateInventory | `obj:updateInventory(...)` |
| _NV_updateInventory | _NV_updateInventory | `obj:_NV_updateInventory(...)` |
| refreshGui | refreshGui | `obj:refreshGui(...)` |
| _NV_refreshGui | _NV_refreshGui | `obj:_NV_refreshGui(...)` |
| initialiseNewSection | initialiseNewSection | `obj:initialiseNewSection(...)` |
| _NV_initialiseNewSection | _NV_initialiseNewSection | `obj:_NV_initialiseNewSection(...)` |

## ShopTraderInventorySection
**Header:** `extern/KenshiLib/Include/kenshi/ShopTraderInventory.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| autoArrange | autoArrange | `obj:autoArrange(...)` |
| _NV_autoArrange | _NV_autoArrange | `obj:_NV_autoArrange(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| addItem | addItem | `obj:addItem(...)` |
| _NV_addItem | _NV_addItem | `obj:_NV_addItem(...)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |

## SimpleTimeStamper
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timer | timer | CPerfTimer | R | `obj.timer` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getTime | getTime | `obj:getTime(...)` |
| stampTime | stampTime | `obj:stampTime(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## SpecificItemLoadFirst
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| baseTypes | (lua_Integer | integer | RW | `obj.baseTypes = <value>` |
| stateEnum | (lua_Integer | integer | RW | `obj.stateEnum = <value>` |
| specificProperty | specificProperty | string | RW | `obj.specificProperty = <value>` |
| desiredSpecificProperty | desiredSpecificProperty | boolean | RW | `obj.desiredSpecificProperty = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| flip | flip | `obj:flip(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## SpeedGroup
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| members | members | ogre_unordered_set<hand>::type | R | `obj.members` |
| position | position | Vector3 | RW | `obj.position = <value>` |
| direction | direction | Vector3 | RW | `obj.direction = <value>` |
| speed | speed | number | RW | `obj.speed = <value>` |
| last | last | integer | RW | `obj.last = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Spot
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timeSoFar | timeSoFar | number | RW | `obj.timeSoFar = <value>` |
| timeLimitMax | timeLimitMax | number | RW | `obj.timeLimitMax = <value>` |
| stillSeen | stillSeen | boolean | RW | `obj.stillSeen = <value>` |

## SpottingPeopleMgr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| spottedPeople | spottedPeople | std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy > > | R | `obj.spottedPeople` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| update | update | `obj:update(...)` |
| resetSeenFlags | resetSeenFlags | `obj:resetSeenFlags(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## Sword
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| cutDamage | cutDamage | number | RW | `obj.cutDamage = <value>` |
| bluntDamage | bluntDamage | number | RW | `obj.bluntDamage = <value>` |
| minCutDamage | minCutDamage | number | RW | `obj.minCutDamage = <value>` |
| modDefence | modDefence | integer | RW | `obj.modDefence = <value>` |
| modIndoors | modIndoors | integer | RW | `obj.modIndoors = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getClassType | getClassType | `obj:getClassType(...)` |
| _NV_getClassType | _NV_getClassType | `obj:_NV_getClassType(...)` |
| isSword | isSword | `obj:isSword(...)` |
| _NV_isSword | _NV_isSword | `obj:_NV_isSword(...)` |
| getSkillModIndoors | getSkillModIndoors | `obj:getSkillModIndoors(...)` |
| _NV_getSkillModIndoors | _NV_getSkillModIndoors | `obj:_NV_getSkillModIndoors(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## SysMessage
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| msg | (lua_Integer | integer | RW | `obj.msg = <value>` |
| target | target | hand | RW | `obj.target = <value>` |
| from | from | hand | RW | `obj.from = <value>` |
| on | on | boolean | RW | `obj.on = <value>` |
| number | number | number | RW | `obj.number = <value>` |
| data | data | void* | R | `obj.data` |

## TaskData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| infrequentGoalChecks | infrequentGoalChecks | boolean | RW | `obj.infrequentGoalChecks = <value>` |
| permaJob | permaJob | PermajobType | R | `obj.permaJob` |
| permaJob_FixedTarget | permaJob_FixedTarget | boolean | RW | `obj.permaJob_FixedTarget = <value>` |
| permaJob_Associated | (lua_Integer | integer | RW | `obj.permaJob_Associated = <value>` |
| permaJob_Associated_Secondary | (lua_Integer | integer | RW | `obj.permaJob_Associated_Secondary = <value>` |
| requirementsAlwaysFalse | requirementsAlwaysFalse | boolean | RW | `obj.requirementsAlwaysFalse = <value>` |
| _resultsAlwaysFalse | _resultsAlwaysFalse | boolean | RW | `obj._resultsAlwaysFalse = <value>` |
| _requirementsCantEndActionPrematurely | _requirementsCantEndActionPrematurely | boolean | RW | `obj._requirementsCantEndActionPrematurely = <value>` |
| durationMin | durationMin | number | RW | `obj.durationMin = <value>` |
| durationFuzz | durationFuzz | number | RW | `obj.durationFuzz = <value>` |
| isDurationBased | isDurationBased | boolean | RW | `obj.isDurationBased = <value>` |
| endsAfterTime | endsAfterTime | boolean | RW | `obj.endsAfterTime = <value>` |
| isUnstoppableTask | isUnstoppableTask | boolean | RW | `obj.isUnstoppableTask = <value>` |
| canDoTaskInStages | canDoTaskInStages | boolean | RW | `obj.canDoTaskInStages = <value>` |
| aggressionLevel | aggressionLevel | number | RW | `obj.aggressionLevel = <value>` |
| noisyness | noisyness | number | RW | `obj.noisyness = <value>` |
| aidLevel | aidLevel | number | RW | `obj.aidLevel = <value>` |
| followMeWeight | followMeWeight | number | RW | `obj.followMeWeight = <value>` |
| copyMeInfluence | copyMeInfluence | number | RW | `obj.copyMeInfluence = <value>` |
| normallyLeadsToSomething | normallyLeadsToSomething | boolean | RW | `obj.normallyLeadsToSomething = <value>` |
| alertnessMult | alertnessMult | number | RW | `obj.alertnessMult = <value>` |
| forDirectPlayerOrdersOnly | forDirectPlayerOrdersOnly | boolean | RW | `obj.forDirectPlayerOrdersOnly = <value>` |
| forFulfillPlayerOrdersOrNPCOnly | forFulfillPlayerOrdersOrNPCOnly | boolean | RW | `obj.forFulfillPlayerOrdersOrNPCOnly = <value>` |
| key | (lua_Integer | integer | RW | `obj.key = <value>` |
| needsTarget | needsTarget | boolean | RW | `obj.needsTarget = <value>` |
| numResults | numResults | integer | RW | `obj.numResults = <value>` |
| results | results | TaskStateData | R | `obj.results` |
| numRequirements | numRequirements | integer | RW | `obj.numRequirements = <value>` |
| requirements | requirements | TaskStateData | R | `obj.requirements` |
| scoreFunction | scoreFunction | function* | R | `obj.scoreFunction` |
| justDoOneTarget | justDoOneTarget | boolean | RW | `obj.justDoOneTarget = <value>` |
| subTask | subTask | TaskStateData* | R | `obj.subTask` |
| dialogueDelivery | (lua_Integer | integer | RW | `obj.dialogueDelivery = <value>` |
| hasAction | hasAction | boolean | RW | `obj.hasAction = <value>` |
| description | description | string | RW | `obj.description = <value>` |
| _findTarget | _findTarget | function* | R | `obj._findTarget` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| setCharacteristics | setCharacteristics | `obj:setCharacteristics(...)` |
| setInfrequentGoalChecks | setInfrequentGoalChecks | `obj:setInfrequentGoalChecks(...)` |
| setAlertnessMult | setAlertnessMult | `obj:setAlertnessMult(...)` |
| setRequirementsCantEndActionPrematurely | setRequirementsCantEndActionPrematurely | `obj:setRequirementsCantEndActionPrematurely(...)` |
| setCopyMeInfluence | setCopyMeInfluence | `obj:setCopyMeInfluence(...)` |
| setFollowMeWeight | setFollowMeWeight | `obj:setFollowMeWeight(...)` |
| setSelfRegulation | setSelfRegulation | `obj:setSelfRegulation(...)` |
| setDurationBased | setDurationBased | `obj:setDurationBased(...)` |
| hasInfrequentGoalChecks | hasInfrequentGoalChecks | `obj:hasInfrequentGoalChecks(...)` |
| getRequirementsCantEndActionPrematurely | getRequirementsCantEndActionPrematurely | `obj:getRequirementsCantEndActionPrematurely(...)` |
| isPermaJob | isPermaJob | `obj:isPermaJob(...)` |
| isPermaJobFixedTarget | isPermaJobFixedTarget | `obj:isPermaJobFixedTarget(...)` |
| getPermaJobAssociation | getPermaJobAssociation | `obj:getPermaJobAssociation(...)` |
| getPermaJobAssociation_secondary | getPermaJobAssociation_secondary | `obj:getPermaJobAssociation_secondary(...)` |
| isTargetFinder | isTargetFinder | `obj:isTargetFinder(...)` |
| setDialogueDeliveryTag | setDialogueDeliveryTag | `obj:setDialogueDeliveryTag(...)` |

## TaskStateData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| key | key | StateType | R | `obj.key` |
| val | val | boolean | RW | `obj.val = <value>` |
| progressionOnly | progressionOnly | boolean | RW | `obj.progressionOnly = <value>` |

## Tasker
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| priority | priority | taskPriority | R | `obj.priority` |
| resetsWhenDone | resetsWhenDone | boolean | RW | `obj.resetsWhenDone = <value>` |
| subject | subject | hand | RW | `obj.subject = <value>` |
| weight | weight | number | RW | `obj.weight = <value>` |
| currentSubTarget | currentSubTarget | hand | RW | `obj.currentSubTarget = <value>` |
| location | location | Vector3 | RW | `obj.location = <value>` |
| startTime | startTime | integer | RW | `obj.startTime = <value>` |
| endTime | endTime | integer | RW | `obj.endTime = <value>` |
| taskData | taskData | TaskData | R | `obj.taskData` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| checkTimeOfDay | checkTimeOfDay | `obj:checkTimeOfDay(...)` |
| key | key | `obj:key(...)` |
| unSkippableJob | unSkippableJob | `obj:unSkippableJob(...)` |
| getLocation | getLocation | `obj:getLocation(...)` |
| setLocation | setLocation | `obj:setLocation(...)` |
| hasActionFunc | hasActionFunc | `obj:hasActionFunc(...)` |
| isSubTasker | isSubTasker | `obj:isSubTasker(...)` |
| isInfiniteGoal | isInfiniteGoal | `obj:isInfiniteGoal(...)` |
| needsSubjectOrLocation | needsSubjectOrLocation | `obj:needsSubjectOrLocation(...)` |
| getTaskData | getTaskData | `obj:getTaskData(...)` |

## Town
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| replacementTown | replacementTown | GameData | R | `obj.replacementTown` |
| isAccessible | isAccessible | boolean | RW | `obj.isAccessible = <value>` |
| alarms | alarms | AlarmManager* | R | `obj.alarms` |
| instanceID | instanceID | InstanceID | R | `obj.instanceID` |
| openToPublic | openToPublic | boolean | RW | `obj.openToPublic = <value>` |
| minFoliageRange | minFoliageRange | number | RW | `obj.minFoliageRange = <value>` |
| playerTownLevel | playerTownLevel | integer | RW | `obj.playerTownLevel = <value>` |
| gates | gates | ogre_unordered_set<hand>::type | R | `obj.gates` |
| playerHasBuildingsInThisTown | playerHasBuildingsInThisTown | boolean | RW | `obj.playerHasBuildingsInThisTown = <value>` |
| powerInList | powerInList | Ogre::FastArray<hand> | R | `obj.powerInList` |
| powerOutList | powerOutList | ogre_unordered_set<hand>::type | R | `obj.powerOutList` |
| batteryList | batteryList | ogre_unordered_set<hand>::type | R | `obj.batteryList` |
| batteryMode | batteryMode | boolean | RW | `obj.batteryMode = <value>` |
| power_Stat | power_Stat | number | RW | `obj.power_Stat = <value>` |
| maxPower_Stat | maxPower_Stat | number | RW | `obj.maxPower_Stat = <value>` |
| neededPowerTotal_Stat | neededPowerTotal_Stat | number | RW | `obj.neededPowerTotal_Stat = <value>` |
| batteryPowerTotal_Stat | batteryPowerTotal_Stat | number | RW | `obj.batteryPowerTotal_Stat = <value>` |
| batteryDrain_Stat | batteryDrain_Stat | number | RW | `obj.batteryDrain_Stat = <value>` |
| batteryChargingupTotal | batteryChargingupTotal | number | RW | `obj.batteryChargingupTotal = <value>` |
| batteryCharge_Stat | batteryCharge_Stat | number | RW | `obj.batteryCharge_Stat = <value>` |
| batteryChargeMax_Stat | batteryChargeMax_Stat | number | RW | `obj.batteryChargeMax_Stat = <value>` |
| _facilitesWeHaveHere | _facilitesWeHaveHere | TagsClass<BuildingDesignation> | R | `obj._facilitesWeHaveHere` |
| tradeCulture | tradeCulture | TradeCulture* | R | `obj.tradeCulture` |
| tradeGoodsMults | tradeGoodsMults | ogre_unordered_map<GameData*, float>::type | R | `obj.tradeGoodsMults` |
| buildingMaterial | buildingMaterial | GameData | R | `obj.buildingMaterial` |
| distantTown | distantTown | DistantTown* | R | `obj.distantTown` |
| nestSpots | nestSpots | lektor<Town::NestSpot> | R | `obj.nestSpots` |
| nestsLoaded | nestsLoaded | boolean | RW | `obj.nestsLoaded = <value>` |
| overrideRange | overrideRange | number | RW | `obj.overrideRange = <value>` |
| townRangeMultiplier | townRangeMultiplier | number | RW | `obj.townRangeMultiplier = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| initialiseResidentData | initialiseResidentData | `obj:initialiseResidentData(...)` |
| getGameData | getGameData | `obj:getGameData(...)` |
| _NV_getGameData | _NV_getGameData | `obj:_NV_getGameData(...)` |
| getOriginalGameData | getOriginalGameData | `obj:getOriginalGameData(...)` |
| _reset | _reset | `obj:_reset(...)` |
| _NV__reset | _NV__reset | `obj:_NV__reset(...)` |
| getDataType | getDataType | `obj:getDataType(...)` |
| _NV_getDataType | _NV_getDataType | `obj:_NV_getDataType(...)` |
| reassessTownPosition | reassessTownPosition | `obj:reassessTownPosition(...)` |
| _NV_reassessTownPosition | _NV_reassessTownPosition | `obj:_NV_reassessTownPosition(...)` |
| showDistantTown | showDistantTown | `obj:showDistantTown(...)` |
| isOutpost | isOutpost | `obj:isOutpost(...)` |
| spawnTheBarFlies | spawnTheBarFlies | `obj:spawnTheBarFlies(...)` |
| townLoadedEvent | townLoadedEvent | `obj:townLoadedEvent(...)` |
| notifyUnloading | notifyUnloading | `obj:notifyUnloading(...)` |
| getBuildingMaterial | getBuildingMaterial | `obj:getBuildingMaterial(...)` |
| isTown | isTown | `obj:isTown(...)` |
| _NV_isTown | _NV_isTown | `obj:_NV_isTown(...)` |
| isPublic | isPublic | `obj:isPublic(...)` |
| _NV_isPublic | _NV_isPublic | `obj:_NV_isPublic(...)` |
| needsSaving | needsSaving | `obj:needsSaving(...)` |
| _NV_needsSaving | _NV_needsSaving | `obj:_NV_needsSaving(...)` |
| setPosition | setPosition | `obj:setPosition(...)` |
| getRadius | getRadius | `obj:getRadius(...)` |
| _NV_getRadius | _NV_getRadius | `obj:_NV_getRadius(...)` |
| isActive | isActive | `obj:isActive(...)` |
| _NV_isActive | _NV_isActive | `obj:_NV_isActive(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| updatePowerGrid | updatePowerGrid | `obj:updatePowerGrid(...)` |
| _NV_updatePowerGrid | _NV_updatePowerGrid | `obj:_NV_updatePowerGrid(...)` |
| gatesAllClosed | gatesAllClosed | `obj:gatesAllClosed(...)` |
| _NV_gatesAllClosed | _NV_gatesAllClosed | `obj:_NV_gatesAllClosed(...)` |
| hasGates | hasGates | `obj:hasGates(...)` |
| _NV_hasGates | _NV_hasGates | `obj:_NV_hasGates(...)` |
| notifyAccesibility | notifyAccesibility | `obj:notifyAccesibility(...)` |
| getPositionOutsideTownGates | getPositionOutsideTownGates | `obj:getPositionOutsideTownGates(...)` |
| _NV_getPositionOutsideTownGates | _NV_getPositionOutsideTownGates | `obj:_NV_getPositionOutsideTownGates(...)` |
| isPlayerBuildingsInThisTown | isPlayerBuildingsInThisTown | `obj:isPlayerBuildingsInThisTown(...)` |
| setPlayerBuildingsInThisTown | setPlayerBuildingsInThisTown | `obj:setPlayerBuildingsInThisTown(...)` |
| getRequiredPower | getRequiredPower | `obj:getRequiredPower(...)` |
| getTotalPower | getTotalPower | `obj:getTotalPower(...)` |
| hasSparePower | hasSparePower | `obj:hasSparePower(...)` |
| getBatteryDrain | getBatteryDrain | `obj:getBatteryDrain(...)` |
| getBatteryChargeMax | getBatteryChargeMax | `obj:getBatteryChargeMax(...)` |
| getBatteryCharge | getBatteryCharge | `obj:getBatteryCharge(...)` |
| getBatteryCharge01 | getBatteryCharge01 | `obj:getBatteryCharge01(...)` |
| getBatteryChargingUpAmount | getBatteryChargingUpAmount | `obj:getBatteryChargingUpAmount(...)` |
| getBatteryPowerTotal | getBatteryPowerTotal | `obj:getBatteryPowerTotal(...)` |
| isBatteryMode | isBatteryMode | `obj:isBatteryMode(...)` |
| clearNests | clearNests | `obj:clearNests(...)` |
| getMapMarker | getMapMarker | `obj:getMapMarker(...)` |
| _NV_getMapMarker | _NV_getMapMarker | `obj:_NV_getMapMarker(...)` |
| getMapMarkerZoomLevel | getMapMarkerZoomLevel | `obj:getMapMarkerZoomLevel(...)` |
| _NV_getMapMarkerZoomLevel | _NV_getMapMarkerZoomLevel | `obj:_NV_getMapMarkerZoomLevel(...)` |
| recalculatePlayerTownLevel | recalculatePlayerTownLevel | `obj:recalculatePlayerTownLevel(...)` |
| deActivationCheck | deActivationCheck | `obj:deActivationCheck(...)` |
| addBuilding | Town_addBuilding | `obj:addBuilding(...)` |
| removeBuilding | Town_removeBuilding | `obj:removeBuilding(...)` |

## TownBase
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| positionCacher | positionCacher | TownPositionCacher | R | `obj.positionCacher` |
| townType | townType | integer | RW | `obj.townType = <value>` |
| population | population | BasePopulationManager* | R | `obj.population` |
| factionsResidentHere | factionsResidentHere | std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > | R | `obj.factionsResidentHere` |
| alreadyInitialisedPopulationParams | alreadyInitialisedPopulationParams | boolean | RW | `obj.alreadyInitialisedPopulationParams = <value>` |
| isSecret | isSecret | boolean | RW | `obj.isSecret = <value>` |
| occupiers | occupiers | std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > | R | `obj.occupiers` |
| timeOfDeath | timeOfDeath | TimeOfDay | R | `obj.timeOfDeath` |
| p_TIME | p_TIME | number | RW | `obj.p_TIME = <value>` |
| nestBatcher | nestBatcher | NestBatcher* | R | `obj.nestBatcher` |
| unexploredName | unexploredName | string | RW | `obj.unexploredName = <value>` |
| discovered | discovered | boolean | RW | `obj.discovered = <value>` |
| explored | explored | boolean | RW | `obj.explored = <value>` |
| recentlyDiscovered | recentlyDiscovered | boolean | RW | `obj.recentlyDiscovered = <value>` |
| entityMarker | entityMarker | Ogre::Entity* | R | `obj.entityMarker` |
| entityLabel | entityLabel | ScreenLabel* | R | `obj.entityLabel` |
| clickHull | clickHull | PhysicsHullT* | R | `obj.clickHull` |
| biome | biome | AreaBiomeGroup* | R | `obj.biome` |
| alarmState | alarmState | TownAlarmState | R | `obj.alarmState` |
| isActivated | isActivated | boolean | RW | `obj.isActivated = <value>` |
| myZoneCoverage | myZoneCoverage | ogre_unordered_set<ZoneMap*>::type | R | `obj.myZoneCoverage` |
| populatedZones | populatedZones | ogre_unordered_map<ZoneMap*, bool>::type | R | `obj.populatedZones` |
| artifacts | artifacts | Ogre::FastArray<ArtifactItemData> | R | `obj.artifacts` |
| currentFloorVisibility | currentFloorVisibility | integer | RW | `obj.currentFloorVisibility = <value>` |
| buildingsManager | buildingsManager | TownBuildingsManager | R | `obj.buildingsManager` |
| residentsSpawned | residentsSpawned | lektor<ResidentData> | R | `obj.residentsSpawned` |
| residentsSpawned_BarsOrSomething | residentsSpawned_BarsOrSomething | lektor<ResidentData> | R | `obj.residentsSpawned_BarsOrSomething` |
| defaultResident | defaultResident | GameData | R | `obj.defaultResident` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| isActive | isActive | `obj:isActive(...)` |
| _NV_isActive | _NV_isActive | `obj:_NV_isActive(...)` |
| _reset | _reset | `obj:_reset(...)` |
| _NV__reset | _NV__reset | `obj:_NV__reset(...)` |
| getKnownName | getKnownName | `obj:getKnownName(...)` |
| reassessTownPosition | reassessTownPosition | `obj:reassessTownPosition(...)` |
| _NV_reassessTownPosition | _NV_reassessTownPosition | `obj:_NV_reassessTownPosition(...)` |
| isNotFriendly | isNotFriendly | `obj:isNotFriendly(...)` |
| _NV_isNotFriendly | _NV_isNotFriendly | `obj:_NV_isNotFriendly(...)` |
| isPhysical | isPhysical | `obj:isPhysical(...)` |
| _NV_isPhysical | _NV_isPhysical | `obj:_NV_isPhysical(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| _NV_setVisible | _NV_setVisible | `obj:_NV_setVisible(...)` |
| getDataType | getDataType | `obj:getDataType(...)` |
| _NV_getDataType | _NV_getDataType | `obj:_NV_getDataType(...)` |
| isTown | isTown | `obj:isTown(...)` |
| _NV_isTown | _NV_isTown | `obj:_NV_isTown(...)` |
| isOutpost | isOutpost | `obj:isOutpost(...)` |
| withinBordersRange | withinBordersRange | `obj:withinBordersRange(...)` |
| withinDiscoveryRange | withinDiscoveryRange | `obj:withinDiscoveryRange(...)` |
| distanceTo | distanceTo | `obj:distanceTo(...)` |
| squaredDistanceTo | squaredDistanceTo | `obj:squaredDistanceTo(...)` |
| isDead | isDead | `obj:isDead(...)` |
| _NV_isDead | _NV_isDead | `obj:_NV_isDead(...)` |
| getPositionOutsideTownGates | getPositionOutsideTownGates | `obj:getPositionOutsideTownGates(...)` |
| _NV_getPositionOutsideTownGates | _NV_getPositionOutsideTownGates | `obj:_NV_getPositionOutsideTownGates(...)` |
| isPublic | isPublic | `obj:isPublic(...)` |
| _NV_isPublic | _NV_isPublic | `obj:_NV_isPublic(...)` |
| getRadius | getRadius | `obj:getRadius(...)` |
| _NV_getRadius | _NV_getRadius | `obj:_NV_getRadius(...)` |
| update | update | `obj:update(...)` |
| _NV_update | _NV_update | `obj:_NV_update(...)` |
| periodicUpdate | periodicUpdate | `obj:periodicUpdate(...)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `obj:_NV_periodicUpdate(...)` |
| updatePowerGrid | updatePowerGrid | `obj:updatePowerGrid(...)` |
| _NV_updatePowerGrid | _NV_updatePowerGrid | `obj:_NV_updatePowerGrid(...)` |
| allBuildingsDoorsOpen | allBuildingsDoorsOpen | `obj:allBuildingsDoorsOpen(...)` |
| _NV_allBuildingsDoorsOpen | _NV_allBuildingsDoorsOpen | `obj:_NV_allBuildingsDoorsOpen(...)` |
| destroyPhysical | destroyPhysical | `obj:destroyPhysical(...)` |
| _NV_destroyPhysical | _NV_destroyPhysical | `obj:_NV_destroyPhysical(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| _NV_getPosition | _NV_getPosition | `obj:_NV_getPosition(...)` |
| getPositionForWaypoint | getPositionForWaypoint | `obj:getPositionForWaypoint(...)` |
| _NV_getPositionForWaypoint | _NV_getPositionForWaypoint | `obj:_NV_getPositionForWaypoint(...)` |
| createPhysical | createPhysical | `obj:createPhysical(...)` |
| _NV_createPhysical | _NV_createPhysical | `obj:_NV_createPhysical(...)` |
| hasGates | hasGates | `obj:hasGates(...)` |
| _NV_hasGates | _NV_hasGates | `obj:_NV_hasGates(...)` |
| gatesAllClosed | gatesAllClosed | `obj:gatesAllClosed(...)` |
| _NV_gatesAllClosed | _NV_gatesAllClosed | `obj:_NV_gatesAllClosed(...)` |
| isRecentlyDiscovered | isRecentlyDiscovered | `obj:isRecentlyDiscovered(...)` |
| _NV_isRecentlyDiscovered | _NV_isRecentlyDiscovered | `obj:_NV_isRecentlyDiscovered(...)` |
| setRecentlyDiscovered | setRecentlyDiscovered | `obj:setRecentlyDiscovered(...)` |
| _NV_setRecentlyDiscovered | _NV_setRecentlyDiscovered | `obj:_NV_setRecentlyDiscovered(...)` |
| isDiscovered | isDiscovered | `obj:isDiscovered(...)` |
| _NV_isDiscovered | _NV_isDiscovered | `obj:_NV_isDiscovered(...)` |
| setDiscovered | setDiscovered | `obj:setDiscovered(...)` |
| _NV_setDiscovered | _NV_setDiscovered | `obj:_NV_setDiscovered(...)` |
| setDead | setDead | `obj:setDead(...)` |
| _NV_setDead | _NV_setDead | `obj:_NV_setDead(...)` |
| isExplored | isExplored | `obj:isExplored(...)` |
| _NV_isExplored | _NV_isExplored | `obj:_NV_isExplored(...)` |
| setExplored | setExplored | `obj:setExplored(...)` |
| _NV_setExplored | _NV_setExplored | `obj:_NV_setExplored(...)` |
| getItemArtifactsMinValue | getItemArtifactsMinValue | `obj:getItemArtifactsMinValue(...)` |
| _NV_getItemArtifactsMinValue | _NV_getItemArtifactsMinValue | `obj:_NV_getItemArtifactsMinValue(...)` |
| getItemArtifactsMaxValue | getItemArtifactsMaxValue | `obj:getItemArtifactsMaxValue(...)` |
| _NV_getItemArtifactsMaxValue | _NV_getItemArtifactsMaxValue | `obj:_NV_getItemArtifactsMaxValue(...)` |
| getGearArtifactsMinValue | getGearArtifactsMinValue | `obj:getGearArtifactsMinValue(...)` |
| _NV_getGearArtifactsMinValue | _NV_getGearArtifactsMinValue | `obj:_NV_getGearArtifactsMinValue(...)` |
| getGearArtifactsMaxValue | getGearArtifactsMaxValue | `obj:getGearArtifactsMaxValue(...)` |
| _NV_getGearArtifactsMaxValue | _NV_getGearArtifactsMaxValue | `obj:_NV_getGearArtifactsMaxValue(...)` |
| resetBuildingsFloorVisibility | resetBuildingsFloorVisibility | `obj:resetBuildingsFloorVisibility(...)` |
| getTownFloorVisiblity | getTownFloorVisiblity | `obj:getTownFloorVisiblity(...)` |
| setTownFloorVisiblity | setTownFloorVisiblity | `obj:setTownFloorVisiblity(...)` |
| resetTownFloorVisibility | resetTownFloorVisibility | `obj:resetTownFloorVisibility(...)` |
| getMapMarker | getMapMarker | `obj:getMapMarker(...)` |
| _NV_getMapMarker | _NV_getMapMarker | `obj:_NV_getMapMarker(...)` |
| getMapMarkerZoomLevel | getMapMarkerZoomLevel | `obj:getMapMarkerZoomLevel(...)` |
| _NV_getMapMarkerZoomLevel | _NV_getMapMarkerZoomLevel | `obj:_NV_getMapMarkerZoomLevel(...)` |
| isOccupied | isOccupied | `obj:isOccupied(...)` |
| distributeArtifacts | distributeArtifacts | `obj:distributeArtifacts(...)` |
| setFaction | TownBase_setFaction | `obj:setFaction(...)` |
| _NV_setFaction | TownBase__NV_setFaction | `obj:_NV_setFaction(...)` |
| findAllBuildingsOfType | TownBase_findAllBuildingsOfType | `obj:findAllBuildingsOfType(...)` |
| _NV_findAllBuildingsOfType | TownBase__NV_findAllBuildingsOfType | `obj:_NV_findAllBuildingsOfType(...)` |
| findAllBuildingsWithFunction | TownBase_findAllBuildingsWithFunction | `obj:findAllBuildingsWithFunction(...)` |
| _NV_findAllBuildingsWithFunction | TownBase__NV_findAllBuildingsWithFunction | `obj:_NV_findAllBuildingsWithFunction(...)` |
| getCurrentTownLocation | TownBase_getCurrentTownLocation | `obj:getCurrentTownLocation(...)` |
| _NV_getCurrentTownLocation | TownBase__NV_getCurrentTownLocation | `obj:_NV_getCurrentTownLocation(...)` |
| getUnexploredName | TownBase_getUnexploredName | `obj:getUnexploredName(...)` |
| _NV_getUnexploredName | TownBase__NV_getUnexploredName | `obj:_NV_getUnexploredName(...)` |

## TownBuildingsManager
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| buildingEntities | buildingEntities | ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type | R | `obj.buildingEntities` |
| instancesManagers | instancesManagers | boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > > | R | `obj.instancesManagers` |
| signs | signs | Ogre::FastArray<std::pair<Building*, Ogre::Entity*> > | R | `obj.signs` |
| signsVisible | signsVisible | boolean | RW | `obj.signsVisible = <value>` |
| town | town | TownBase* | R | `obj.town` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| clear | clear | `obj:clear(...)` |
| setAllVisible | setAllVisible | `obj:setAllVisible(...)` |
| resetAllVisible | resetAllVisible | `obj:resetAllVisible(...)` |
| setSignsVisible | setSignsVisible | `obj:setSignsVisible(...)` |

## TownPositionCacher
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lastUpdateStamp | lastUpdateStamp | TimeOfDay | R | `obj.lastUpdateStamp` |
| updateRateInHours | updateRateInHours | number | RW | `obj.updateRateInHours = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| stampUpdate | stampUpdate | `obj:stampUpdate(...)` |
| needsUpdate | needsUpdate | `obj:needsUpdate(...)` |

## VisibleObjectInfo
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| handle | handle | hand | R | `obj.handle` |
| range | range | number | RW | `obj.range = <value>` |
| isEnemy | isEnemy | boolean | RW | `obj.isEnemy = <value>` |

## Weapon
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| bleedDamage | bleedDamage | number | RW | `obj.bleedDamage = <value>` |
| modAttack | modAttack | integer | RW | `obj.modAttack = <value>` |
| combatWeight | combatWeight | number | RW | `obj.combatWeight = <value>` |
| category | (lua_Integer | integer | RW | `obj.category = <value>` |
| category_animationOverride | (lua_Integer | integer | RW | `obj.category_animationOverride = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getItemWeight | getItemWeight | `obj:getItemWeight(...)` |
| _NV_getItemWeight | _NV_getItemWeight | `obj:_NV_getItemWeight(...)` |
| getValueSingle | getValueSingle | `obj:getValueSingle(...)` |
| _NV_getValueSingle | _NV_getValueSingle | `obj:_NV_getValueSingle(...)` |
| getCategory | getCategory | `obj:getCategory(...)` |
| getCategory_animationOverride | getCategory_animationOverride | `obj:getCategory_animationOverride(...)` |
| is2HandedOnly | is2HandedOnly | `obj:is2HandedOnly(...)` |
| getCombatWeight | getCombatWeight | `obj:getCombatWeight(...)` |
| getCraftTime | getCraftTime | `obj:getCraftTime(...)` |
| _NV_getCraftTime | _NV_getCraftTime | `obj:_NV_getCraftTime(...)` |
| getCraftMaterialMult | getCraftMaterialMult | `obj:getCraftMaterialMult(...)` |
| _NV_getCraftMaterialMult | _NV_getCraftMaterialMult | `obj:_NV_getCraftMaterialMult(...)` |
| isWeapon | isWeapon | `obj:isWeapon(...)` |
| _NV_isWeapon | _NV_isWeapon | `obj:_NV_isWeapon(...)` |
| isSword | isSword | `obj:isSword(...)` |
| _NV_isSword | _NV_isSword | `obj:_NV_isSword(...)` |
| isCrossbow | isCrossbow | `obj:isCrossbow(...)` |
| _NV_isCrossbow | _NV_isCrossbow | `obj:_NV_isCrossbow(...)` |
| getSkillModIndoors | getSkillModIndoors | `obj:getSkillModIndoors(...)` |
| _NV_getSkillModIndoors | _NV_getSkillModIndoors | `obj:_NV_getSkillModIndoors(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## WhoSeesMe
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lastUpdated | lastUpdated | number | RW | `obj.lastUpdated = <value>` |
| seeState | seeState | YesNoMaybe | R | `obj.seeState` |
| progressOfMaybe | progressOfMaybe | number | RW | `obj.progressOfMaybe = <value>` |

## WorldEventStateQuery
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| uniqueNPCsAre | uniqueNPCsAre | ogre_unordered_map<GameData*, WorldStateEnum>::type | R | `obj.uniqueNPCsAre` |
| uniqueNPCsAreNot | uniqueNPCsAreNot | ogre_unordered_map<GameData*, WorldStateEnum>::type | R | `obj.uniqueNPCsAreNot` |
| towns | towns | ogre_unordered_map<GameData*, WorldStateEnum>::type | R | `obj.towns` |
| isAllyOf | isAllyOf | ogre_unordered_map<Faction*, bool>::type | R | `obj.isAllyOf` |
| isEnemyOf | isEnemyOf | ogre_unordered_map<Faction*, bool>::type | R | `obj.isEnemyOf` |
| playerInvolvement | playerInvolvement | boolean | RW | `obj.playerInvolvement = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isTrue | isTrue | `obj:isTrue(...)` |

## WorldEventStateQueryList
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| statesList | statesList | ogre_unordered_map<WorldEventStateQuery*, bool>::type | R | `obj.statesList` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| reset | reset | `obj:reset(...)` |
| isTrue | isTrue | `obj:isTrue(...)` |
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |

## physHit
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _defaultAltitudeFallback | _defaultAltitudeFallback | number | RW | `obj._defaultAltitudeFallback = <value>` |
| _traceWasAborted | _traceWasAborted | boolean | RW | `obj._traceWasAborted = <value>` |
| _doNotAbort | _doNotAbort | boolean | RW | `obj._doNotAbort = <value>` |
| _needsGroup | _needsGroup | boolean | RW | `obj._needsGroup = <value>` |
| hit | hit | boolean | RW | `obj.hit = <value>` |
| position | position | Vector3 | RW | `obj.position = <value>` |
| normal | normal | Vector3 | RW | `obj.normal = <value>` |
| distance | distance | number | RW | `obj.distance = <value>` |
| shape | shape | NxShape* | R | `obj.shape` |
| hitObject | hitObject | hand | RW | `obj.hitObject = <value>` |
| _group | _group | integer | RW | `obj._group = <value>` |
| _hitObjectUnsafePtr | _hitObjectUnsafePtr | RootObject | R | `obj._hitObjectUnsafePtr` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| traceWasAborted | traceWasAborted | `obj:traceWasAborted(...)` |
| reset | reset | `obj:reset(...)` |
| hitObjectUnsafePtr | hitObjectUnsafePtr | `obj:hitObjectUnsafePtr(...)` |
| getBuilding | getBuilding | `obj:getBuilding(...)` |
| group | group | `obj:group(...)` |
