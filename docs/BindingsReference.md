# Lua Bindings Reference

## Table of Contents
- [AABB2D](#aabb2d)
- [AIOptions](#aioptions)
- [AbstractMovementBase](#abstractmovementbase)
- [ActivePlatoon](#activeplatoon)
- [AnimalInventoryLayout](#animalinventorylayout)
- [AppearanceAnimal](#appearanceanimal)
- [AppearanceBase](#appearancebase)
- [AppearanceHuman](#appearancehuman)
- [Armour](#armour)
- [AttachedArrowManager](#attachedarrowmanager)
- [AttackSlotManager](#attackslotmanager)
- [BackThreadMessagesToMainT](#backthreadmessagestomaint)
- [BackpackInventoryLayout](#backpackinventorylayout)
- [Bounty](#bounty)
- [BountyManager](#bountymanager)
- [BuildInventoryLayout](#buildinventorylayout)
- [BuildMaterial](#buildmaterial)
- [BuildModeWindow](#buildmodewindow)
- [Building](#building)
- [BuildingCategory](#buildingcategory)
- [BuildingContainerInventoryLayout](#buildingcontainerinventorylayout)
- [BuildingGroup](#buildinggroup)
- [BuildingPlacementGroundType](#buildingplacementgroundtype)
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
- [CharacterStatsWindow](#characterstatswindow)
- [CharacterTradingWindow](#charactertradingwindow)
- [CombatClass](#combatclass)
- [CombatMovementController](#combatmovementcontroller)
- [CombatTechniqueData](#combattechniquedata)
- [ConstructionState](#constructionstate)
- [ConsumptionItem](#consumptionitem)
- [ContainerItem](#containeritem)
- [ContextMenu](#contextmenu)
- [CraftingBuilding](#craftingbuilding)
- [CraftingInventoryLayout](#craftinginventorylayout)
- [CreatelistItem](#createlistitem)
- [Crossbow](#crossbow)
- [Damages](#damages)
- [DataObjectContainer](#dataobjectcontainer)
- [DataPanelLine](#datapanelline)
- [DataPanelLine_Button](#datapanelline_button)
- [DataPanelLine_CheckBox](#datapanelline_checkbox)
- [DataPanelLine_DropBox](#datapanelline_dropbox)
- [DataPanelLine_Faction](#datapanelline_faction)
- [DataPanelLine_KeyConfig](#datapanelline_keyconfig)
- [DataPanelLine_Progress](#datapanelline_progress)
- [DataPanelLine_Research](#datapanelline_research)
- [DataPanelLine_Slider](#datapanelline_slider)
- [DataPanelLine_SliderEditable](#datapanelline_slidereditable)
- [DataPanelLine_Text](#datapanelline_text)
- [DataPanelLine_TextEditable](#datapanelline_texteditable)
- [DatapanelGUI](#datapanelgui)
- [DelayedSpawnMsg](#delayedspawnmsg)
- [DialogAction](#dialogaction)
- [DialogChoiceList](#dialogchoicelist)
- [DialogCondition](#dialogcondition)
- [DialogDataManager](#dialogdatamanager)
- [DialogLineData](#dialoglinedata)
- [DialogState](#dialogstate)
- [Dialogue](#dialogue)
- [DialogueSpeechBubble](#dialoguespeechbubble)
- [DialogueWindow](#dialoguewindow)
- [DoorStuff](#doorstuff)
- [Faction](#faction)
- [FactionLeader](#factionleader)
- [FactionManager](#factionmanager)
- [FactionRelations](#factionrelations)
- [FactionRelationsLine](#factionrelationsline)
- [FactionUniqueSquadManager](#factionuniquesquadmanager)
- [FactionsScreen](#factionsscreen)
- [FactoryCallbackInterface](#factorycallbackinterface)
- [FarmBatch](#farmbatch)
- [FarmBuilding](#farmbuilding)
- [FlagCondition](#flagcondition)
- [FlockingTools](#flockingtools)
- [Footprint](#footprint)
- [FootprintNode](#footprintnode)
- [ForgottenGUI](#forgottengui)
- [FormationMover](#formationmover)
- [FurnaceBuilding](#furnacebuilding)
- [FurnaceInventoryLayout](#furnaceinventorylayout)
- [GUIWindow](#guiwindow)
- [GameData](#gamedata)
- [GameDataContainer](#gamedatacontainer)
- [GameDataCopyStandalone](#gamedatacopystandalone)
- [GameDataEditorWindow](#gamedataeditorwindow)
- [GameDataGroup](#gamedatagroup)
- [GameDataHeader](#gamedataheader)
- [GameDataManager](#gamedatamanager)
- [GameDataReference](#gamedatareference)
- [GameDataValuePair](#gamedatavaluepair)
- [GameSaveState](#gamesavestate)
- [GameWorld](#gameworld)
- [GameplayOptions](#gameplayoptions)
- [GatewayBuilding](#gatewaybuilding)
- [Gear](#gear)
- [GeneratorBuilding](#generatorbuilding)
- [GenericFixedInventoryLayout](#genericfixedinventorylayout)
- [GenericInventoryLayout](#genericinventorylayout)
- [Global](#global)
- [GlobalConstants](#globalconstants)
- [HasRoomCache](#hasroomcache)
- [HealthPartStatus](#healthpartstatus)
- [ImpactPoint](#impactpoint)
- [InputHandler](#inputhandler)
- [InstanceID](#instanceid)
- [Inventory](#inventory)
- [InventoryGUI](#inventorygui)
- [InventoryIcon](#inventoryicon)
- [InventoryItemBase](#inventoryitembase)
- [InventoryLayout](#inventorylayout)
- [InventorySection](#inventorysection)
- [InventorySectionGUI](#inventorysectiongui)
- [InventoryTradeData](#inventorytradedata)
- [Item](#item)
- [ItemData](#itemdata)
- [LightBuilding](#lightbuilding)
- [LimbsInventoryLayout](#limbsinventorylayout)
- [Limiter](#limiter)
- [LockedArmour](#lockedarmour)
- [MainBarGUI](#mainbargui)
- [MainTabPortraitPlatoon](#maintabportraitplatoon)
- [MainthreadStateReaderT](#mainthreadstatereadert)
- [MedianFilter](#medianfilter)
- [MedianFilter2DVector](#medianfilter2dvector)
- [MedicalSystem](#medicalsystem)
- [MeshDataLookup](#meshdatalookup)
- [MeshLoadData](#meshloaddata)
- [ModInfo](#modinfo)
- [MotionFilter](#motionfilter)
- [MyGui](#mygui)
- [NxUserControllerHitReport](#nxusercontrollerhitreport)
- [ObjectInstance](#objectinstance)
- [OpenSaveFileDialog](#opensavefiledialog)
- [OptionsHolder](#optionsholder)
- [OptionsWindow](#optionswindow)
- [OrderCellView](#ordercellview)
- [OrderData](#orderdata)
- [OrdersItemBox](#ordersitembox)
- [OrdersPanel](#orderspanel)
- [Ownerships](#ownerships)
- [ParticlePool](#particlepool)
- [Platoon](#platoon)
- [PlayerInterface](#playerinterface)
- [PreviewBuilding](#previewbuilding)
- [ProductionBuilding](#productionbuilding)
- [ProductionInventoryLayout](#productioninventorylayout)
- [ProsperityManager](#prosperitymanager)
- [RaceData](#racedata)
- [RaceLimiter](#racelimiter)
- [RainCollectorBuilding](#raincollectorbuilding)
- [RelationData](#relationdata)
- [RepetitionCounter](#repetitioncounter)
- [ResearchBuilding](#researchbuilding)
- [ResearchBuildingInventoryLayout](#researchbuildinginventorylayout)
- [ResourceLoadRequestMesh](#resourceloadrequestmesh)
- [ResourceLoadRequestTexture](#resourceloadrequesttexture)
- [ResourceLoader](#resourceloader)
- [RobotLimbItem](#robotlimbitem)
- [RobotLimbs](#robotlimbs)
- [RootObject](#rootobject)
- [RootObjectBase](#rootobjectbase)
- [RootObjectContainer](#rootobjectcontainer)
- [RootObjectFactory](#rootobjectfactory)
- [SaveFileSystem](#savefilesystem)
- [SaveManager](#savemanager)
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
- [Stat](#stat)
- [StatGroup](#statgroup)
- [StateT](#statet)
- [StorageBuilding](#storagebuilding)
- [StringPair](#stringpair)
- [Sword](#sword)
- [SysMessage](#sysmessage)
- [TaskData](#taskdata)
- [TaskStateData](#taskstatedata)
- [Tasker](#tasker)
- [TextureArrayLoadData](#texturearrayloaddata)
- [TextureLoadData](#textureloaddata)
- [TimeOfDay](#timeofday)
- [ToolTip](#tooltip)
- [ToolTipDynamic](#tooltipdynamic)
- [ToolTipFixed](#tooltipfixed)
- [ToolTipInventory](#tooltipinventory)
- [ToolTipLine](#tooltipline)
- [ToolTipStatic](#tooltipstatic)
- [TortureBuilding](#torturebuilding)
- [Town](#town)
- [TownBase](#townbase)
- [TownBuildingsManager](#townbuildingsmanager)
- [TownPositionCacher](#townpositioncacher)
- [TradeCulture](#tradeculture)
- [TradeResult](#traderesult)
- [TransformWindow](#transformwindow)
- [TurretBuilding](#turretbuilding)
- [TutorialGUI](#tutorialgui)
- [TutorialGUILine](#tutorialguiline)
- [TutorialItem](#tutorialitem)
- [TutorialSubItem](#tutorialsubitem)
- [TutorialpediaGUI](#tutorialpediagui)
- [UniqueSpawnData](#uniquespawndata)
- [UseableStuff](#useablestuff)
- [VisibleObjectInfo](#visibleobjectinfo)
- [WallBuilding](#wallbuilding)
- [Weapon](#weapon)
- [WhoSeesMe](#whoseesme)
- [WindGeneratorBuilding](#windgeneratorbuilding)
- [WorldEventStateQuery](#worldeventstatequery)
- [WorldEventStateQueryList](#worldeventstatequerylist)
- [YesNoMaybe](#yesnomaybe)
- [ZoneManager](#zonemanager)
- [ZoneManagerInterfaceT](#zonemanagerinterfacet)
- [ZoneMap](#zonemap)
- [ZoneSpacialGrid](#zonespacialgrid)
- [hand](#hand)
- [iVector2](#ivector2)
- [physHit](#physhit)

## AABB2D
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| x | x | number | RW | `obj.x = <value>` |
| y | y | number | RW | `obj.y = <value>` |
| x2 | x2 | number | RW | `obj.x2 = <value>` |
| y2 | y2 | number | RW | `obj.y2 = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setNull | setNull | `` | `void` | `obj:setNull()` |
| pointWithin | pointWithin | `v: Vector3` | `boolean` | `obj:pointWithin(v)` |
| inflate | inflate | `amount: number` | `void` | `obj:inflate(amount)` |
| sizeX | sizeX | `` | `number` | `obj:sizeX()` |
| sizeY | sizeY | `` | `number` | `obj:sizeY()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| create | create | `_pos: Vector3` | `void` | `obj:create(_pos)` |
| _setPositionAndTeleport | _setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _NV__setPositionAndTeleport | _NV__setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_NV__setPositionAndTeleport(p, floor)` |
| _setPositionSimple | _setPositionSimple | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| _NV__setPositionSimple | _NV__setPositionSimple | `p: Vector3` | `void` | `obj:_NV__setPositionSimple(p)` |
| faceDirection | faceDirection | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| _NV_faceDirection | _NV_faceDirection | `dir: Vector3` | `void` | `obj:_NV_faceDirection(dir)` |
| lookatPosition | lookatPosition | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| _NV_lookatPosition | _NV_lookatPosition | `pos: Vector3` | `void` | `obj:_NV_lookatPosition(pos)` |
| getDestination | getDestination | `` | `Vector3` | `obj:getDestination()` |
| isProbablyStuck | isProbablyStuck | `` | `boolean` | `obj:isProbablyStuck()` |
| pathOk | pathOk | `` | `boolean` | `obj:pathOk()` |
| _NV_pathOk | _NV_pathOk | `` | `boolean` | `obj:_NV_pathOk()` |
| pathFailed | pathFailed | `` | `boolean` | `obj:pathFailed()` |
| _NV_pathFailed | _NV_pathFailed | `` | `boolean` | `obj:_NV_pathFailed()` |
| update | update | `_TIME: number` | `void` | `obj:update(_TIME)` |
| _NV_update | _NV_update | `_TIME: number` | `void` | `obj:_NV_update(_TIME)` |
| isDestinationReached | isDestinationReached | `` | `boolean` | `obj:isDestinationReached()` |
| _NV_isDestinationReached | _NV_isDestinationReached | `` | `boolean` | `obj:_NV_isDestinationReached()` |
| amInsideTownWalls | amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| manualMovement | manualMovement | `desiredMotion: Vector3` | `void` | `obj:manualMovement(desiredMotion)` |
| _NV_manualMovement | _NV_manualMovement | `desiredMotion: Vector3` | `void` | `obj:_NV_manualMovement(desiredMotion)` |
| halt | halt | `` | `void` | `obj:halt()` |
| _NV_halt | _NV_halt | `` | `void` | `obj:_NV_halt()` |
| setRoadDestination | setRoadDestination | `dest: Vector3` | `boolean` | `obj:setRoadDestination(dest)` |
| setRoadPreference | setRoadPreference | `w: number` | `void` | `obj:setRoadPreference(w)` |
| setDestination | setDestination | `dest: Vector3, pri: integer, _a3: boolean` | `void` | `obj:setDestination(dest, pri, _a3)` |
| _NV_setDestination | _NV_setDestination | `dest: Vector3, pri: integer, _a3: boolean` | `void` | `obj:_NV_setDestination(dest, pri, _a3)` |
| setDesiredSpeed | setDesiredSpeed | `val: number` | `void` | `obj:setDesiredSpeed(val)` |
| setDesiredSpeedOrders | setDesiredSpeedOrders | `val: number` | `void` | `obj:setDesiredSpeedOrders(val)` |
| _NV_setDesiredSpeed | _NV_setDesiredSpeed | `speed: integer` | `void` | `obj:_NV_setDesiredSpeed(speed)` |
| setStandardWalkSpeed | setStandardWalkSpeed | `s: number` | `void` | `obj:setStandardWalkSpeed(s)` |
| getStandardWalkSpeed | getStandardWalkSpeed | `` | `number` | `obj:getStandardWalkSpeed()` |
| restoreDesiredSpeed | restoreDesiredSpeed | `` | `void` | `obj:restoreDesiredSpeed()` |
| setMaxSpeed | setMaxSpeed | `ms: number` | `void` | `obj:setMaxSpeed(ms)` |
| getMaxSpeed | getMaxSpeed | `` | `number` | `obj:getMaxSpeed()` |
| isCurrentlyMoving | isCurrentlyMoving | `` | `boolean` | `obj:isCurrentlyMoving()` |
| getCurrentSpeed | getCurrentSpeed | `` | `number` | `obj:getCurrentSpeed()` |
| getCurrentMotion | getCurrentMotion | `` | `Vector3` | `obj:getCurrentMotion()` |
| getCurrentSpeedRelativeToMax01 | getCurrentSpeedRelativeToMax01 | `` | `number` | `obj:getCurrentSpeedRelativeToMax01()` |
| getSpeedOrders | getSpeedOrders | `` | `integer` | `obj:getSpeedOrders()` |
| leaveSpeedGroup | leaveSpeedGroup | `` | `void` | `obj:leaveSpeedGroup()` |
| getHandle | AbstractMovementBase_getHandle | `` | `hand` | `obj:getHandle()` |
| _NV_getHandle | AbstractMovementBase__NV_getHandle | `` | `hand` | `obj:_NV_getHandle()` |
| getPosition | AbstractMovementBase_getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | AbstractMovementBase__NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getFacingDirection | AbstractMovementBase_getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |

## ActivePlatoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _recalculateIsIntact | _recalculateIsIntact | `` | `boolean` | `obj:_recalculateIsIntact()` |
| isAnyoneCaptured | isAnyoneCaptured | `` | `boolean` | `obj:isAnyoneCaptured()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| swapCharacters | swapCharacters | `indexA: integer, indexB: integer` | `void` | `obj:swapCharacters(indexA, indexB)` |
| emptySquadCheck | emptySquadCheck | `` | `void` | `obj:emptySquadCheck()` |
| clearAllTheUniqueNPCStates | clearAllTheUniqueNPCStates | `` | `void` | `obj:clearAllTheUniqueNPCStates()` |
| isIntact | isIntact | `` | `boolean` | `obj:isIntact()` |
| getSquadLeader_theRealOne | getSquadLeader_theRealOne | `` | `Character` | `obj:getSquadLeader_theRealOne()` |
| getNearestActiveCharacter | getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getSquadSize | getSquadSize | `` | `integer` | `obj:getSquadSize()` |
| update | update | `` | `boolean` | `obj:update()` |
| _NV_update | _NV_update | `` | `boolean` | `obj:_NV_update()` |
| refreshInventory | refreshInventory | `firstTime: boolean` | `void` | `obj:refreshInventory(firstTime)` |
| _forceRefreshInventory | _forceRefreshInventory | `` | `void` | `obj:_forceRefreshInventory()` |
| periodicUpdate | periodicUpdate | `` | `boolean` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `boolean` | `obj:_NV_periodicUpdate()` |
| serialiseEverythingToDisk | serialiseEverythingToDisk | `levelEditor: boolean` | `void` | `obj:serialiseEverythingToDisk(levelEditor)` |
| isWholeSquadDown | isWholeSquadDown | `minusThis: integer` | `boolean` | `obj:isWholeSquadDown(minusThis)` |
| setDataFilename | setDataFilename | `f: string` | `void` | `obj:setDataFilename(f)` |
| setupLeaderDialogues | setupLeaderDialogues | `` | `void` | `obj:setupLeaderDialogues()` |
| isLoaded | isLoaded | `` | `boolean` | `obj:isLoaded()` |
| teleport | teleport | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |
| getIsTrader | getIsTrader | `` | `boolean` | `obj:getIsTrader()` |
| getHasVendorList | getHasVendorList | `` | `boolean` | `obj:getHasVendorList()` |
| getHasSpecialItemsList | getHasSpecialItemsList | `` | `boolean` | `obj:getHasSpecialItemsList()` |
| setupTraderBuildings | setupTraderBuildings | `` | `void` | `obj:setupTraderBuildings()` |
| putTheSpecialCharactersInNewSquads_captured | putTheSpecialCharactersInNewSquads_captured | `` | `void` | `obj:putTheSpecialCharactersInNewSquads_captured()` |
| checkForCharactersBeingCarried | checkForCharactersBeingCarried | `` | `boolean` | `obj:checkForCharactersBeingCarried()` |
| restoreSquad | restoreSquad | `` | `void` | `obj:restoreSquad()` |
| unloadCheck | unloadCheck | `` | `boolean` | `obj:unloadCheck()` |
| destroyCharacters | destroyCharacters | `justUnload: boolean` | `void` | `obj:destroyCharacters(justUnload)` |
| serialiseCharacterData | serialiseCharacterData | `` | `void` | `obj:serialiseCharacterData()` |
| saveToDisk | saveToDisk | `levelEditor: boolean, force: string` | `void` | `obj:saveToDisk(levelEditor, force)` |
| calculateCurrentPos | calculateCurrentPos | `` | `Vector3` | `obj:calculateCurrentPos()` |
| _checkForUniqueCharactersOnUnload | _checkForUniqueCharactersOnUnload | `` | `void` | `obj:_checkForUniqueCharactersOnUnload()` |
| removeObject | ActivePlatoon_removeObject | `` | `boolean` | `obj:removeObject()` |
| _NV_removeObject | ActivePlatoon__NV_removeObject | `` | `boolean` | `obj:_NV_removeObject()` |
| addActiveObject | ActivePlatoon_addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | ActivePlatoon__NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| addCharacterAt | ActivePlatoon_addCharacterAt | `index: integer` | `void` | `obj:addCharacterAt(index)` |
| setSquadLeader | ActivePlatoon_setSquadLeader | `` | `void` | `obj:setSquadLeader()` |
| getName | ActivePlatoon_getName | `` | `string` | `obj:getName()` |
| loadFromDisk | ActivePlatoon_loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:loadFromDisk(force, extra)` |
| _NV_loadFromDisk | ActivePlatoon__NV_loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:_NV_loadFromDisk(force, extra)` |
| getGroupSense | ActivePlatoon_getGroupSense | `` | `lightuserdata` | `obj:getGroupSense()` |
| getMemory | ActivePlatoon_getMemory | `` | `lightuserdata` | `obj:getMemory()` |
| getCharactersInArea | ActivePlatoon_getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| setupCheck | ActivePlatoon_setupCheck | `` | `integer` | `obj:setupCheck()` |
| loadCharacters | ActivePlatoon_loadCharacters | `pos: Vector3` | `void` | `obj:loadCharacters(pos)` |
| _NV_loadCharacters | ActivePlatoon__NV_loadCharacters | `pos: Vector3` | `void` | `obj:_NV_loadCharacters(pos)` |
| loadInstance | ActivePlatoon_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |
| _NV_loadInstance | ActivePlatoon__NV_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:_NV_loadInstance(skipSaveState, pos, rot, positionMoved)` |

## AnimalInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## AppearanceAnimal
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createBody | createBody | `` | `void` | `obj:createBody()` |
| _NV_createBody | _NV_createBody | `` | `void` | `obj:_NV_createBody()` |
| updateCharaterTexture | updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| _NV_updateCharaterTexture | _NV_updateCharaterTexture | `` | `void` | `obj:_NV_updateCharaterTexture()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateAnimationTransforms | updateAnimationTransforms | `` | `void` | `obj:updateAnimationTransforms()` |
| forceUpdateAnimationTransforms | forceUpdateAnimationTransforms | `` | `void` | `obj:forceUpdateAnimationTransforms()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| activate | activate | `` | `void` | `obj:activate()` |
| _NV_activate | _NV_activate | `` | `void` | `obj:_NV_activate()` |
| deactivate | deactivate | `` | `void` | `obj:deactivate()` |
| _NV_deactivate | _NV_deactivate | `` | `void` | `obj:_NV_deactivate()` |
| isFemale | isFemale | `` | `boolean` | `obj:isFemale()` |
| setGender | setGender | `_female: boolean` | `void` | `obj:setGender(_female)` |
| _NV_setGender | _NV_setGender | `_female: boolean` | `void` | `obj:_NV_setGender(_female)` |
| getRace | getRace | `` | `GameData` | `obj:getRace()` |
| detachAllHarpoonsT | detachAllHarpoonsT | `` | `void` | `obj:detachAllHarpoonsT()` |
| _detachAllHarpoons | _detachAllHarpoons | `` | `void` | `obj:_detachAllHarpoons()` |
| updateWetness | updateWetness | `force: boolean` | `void` | `obj:updateWetness(force)` |
| updateBloodyness | updateBloodyness | `` | `void` | `obj:updateBloodyness()` |
| getAttachmentPosition | getAttachmentPosition | `slot: string, pos: Vector3, rot: Quaternion` | `boolean` | `obj:getAttachmentPosition(slot, pos, rot)` |
| hasSlot | hasSlot | `slot: string` | `boolean` | `obj:hasSlot(slot)` |
| getNormalisedCharacterHeight | getNormalisedCharacterHeight | `` | `number` | `obj:getNormalisedCharacterHeight()` |
| getCharacterHeight | getCharacterHeight | `` | `number` | `obj:getCharacterHeight()` |
| getBodyRadius | getBodyRadius | `` | `number` | `obj:getBodyRadius()` |
| failedToLoad | failedToLoad | `` | `boolean` | `obj:failedToLoad()` |
| getBonePosition | getBonePosition | `boneName: string` | `Vector3` | `obj:getBonePosition(boneName)` |
| getBoneOrientation | getBoneOrientation | `boneName: string` | `Quaternion` | `obj:getBoneOrientation(boneName)` |
| getVertexWorldPosition | getVertexWorldPosition | `boneName: string, vertex: integer` | `Vector3` | `obj:getVertexWorldPosition(boneName, vertex)` |
| getRandomVertex | getRandomVertex | `boneName: string, direction: integer` | `integer` | `obj:getRandomVertex(boneName, direction)` |
| notifyDirty | notifyDirty | `` | `void` | `obj:notifyDirty()` |
| reload | reload | `` | `void` | `obj:reload()` |
| updateAppearance | updateAppearance | `` | `void` | `obj:updateAppearance()` |
| _NV_updateAppearance | _NV_updateAppearance | `` | `void` | `obj:_NV_updateAppearance()` |
| updatePortrait | updatePortrait | `` | `void` | `obj:updatePortrait()` |
| updateMovementScale | updateMovementScale | `` | `void` | `obj:updateMovementScale()` |
| switchLights | switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| hasLights | hasLights | `` | `boolean` | `obj:hasLights()` |
| shaveHead | shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isShaved | isShaved | `` | `boolean` | `obj:isShaved()` |
| setFlayed | setFlayed | `on: boolean` | `void` | `obj:setFlayed(on)` |
| _NV_setFlayed | _NV_setFlayed | `on: boolean` | `void` | `obj:_NV_setFlayed(on)` |
| isFlayed | isFlayed | `` | `boolean` | `obj:isFlayed()` |
| _NV_isFlayed | _NV_isFlayed | `` | `boolean` | `obj:_NV_isFlayed()` |
| isBarefoot | isBarefoot | `` | `boolean` | `obj:isBarefoot()` |
| _NV_isBarefoot | _NV_isBarefoot | `` | `boolean` | `obj:_NV_isBarefoot()` |
| setVisible | setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| getAttachmentsLoaded | getAttachmentsLoaded | `` | `boolean` | `obj:getAttachmentsLoaded()` |
| setAttachmentsVisible | setAttachmentsVisible | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| _NV_setAttachmentsVisible | _NV_setAttachmentsVisible | `visible: boolean` | `void` | `obj:_NV_setAttachmentsVisible(visible)` |
| createBody | createBody | `` | `void` | `obj:createBody()` |
| buildAttachments | buildAttachments | `` | `void` | `obj:buildAttachments()` |
| setHairTexture | setHairTexture | `name: string, channel: integer, alpha: integer, colour: Vector3, beard: boolean` | `void` | `obj:setHairTexture(name, channel, alpha, colour, beard)` |
| updateOverlap | updateOverlap | `` | `void` | `obj:updateOverlap()` |
| updateCharaterTexture | updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| getCharacterHeightSpeedMultiplier | getCharacterHeightSpeedMultiplier | `` | `number` | `obj:getCharacterHeightSpeedMultiplier()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setGender | setGender | `female: boolean` | `void` | `obj:setGender(female)` |
| _NV_setGender | _NV_setGender | `female: boolean` | `void` | `obj:_NV_setGender(female)` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| setAttachmentsVisible | setAttachmentsVisible | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| _NV_setAttachmentsVisible | _NV_setAttachmentsVisible | `visible: boolean` | `void` | `obj:_NV_setAttachmentsVisible(visible)` |
| setHiddenPartsEnabled | setHiddenPartsEnabled | `enabled: boolean` | `void` | `obj:setHiddenPartsEnabled(enabled)` |
| showFace | showFace | `show: boolean` | `void` | `obj:showFace(show)` |
| setFlayed | setFlayed | `f: boolean` | `void` | `obj:setFlayed(f)` |
| _NV_setFlayed | _NV_setFlayed | `f: boolean` | `void` | `obj:_NV_setFlayed(f)` |
| isFlayed | isFlayed | `` | `boolean` | `obj:isFlayed()` |
| _NV_isFlayed | _NV_isFlayed | `` | `boolean` | `obj:_NV_isFlayed()` |
| updateProportions | updateProportions | `` | `void` | `obj:updateProportions()` |
| createBody | createBody | `` | `void` | `obj:createBody()` |
| _NV_createBody | _NV_createBody | `` | `void` | `obj:_NV_createBody()` |
| updateAppearance | updateAppearance | `` | `void` | `obj:updateAppearance()` |
| _NV_updateAppearance | _NV_updateAppearance | `` | `void` | `obj:_NV_updateAppearance()` |
| updateHiddenParts | updateHiddenParts | `` | `void` | `obj:updateHiddenParts()` |
| updatePysiqueFromStats | updatePysiqueFromStats | `` | `void` | `obj:updatePysiqueFromStats()` |
| updatePhysiqueMuscleMults | updatePhysiqueMuscleMults | `` | `void` | `obj:updatePhysiqueMuscleMults()` |
| updateCharaterTexture | updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| _NV_updateCharaterTexture | _NV_updateCharaterTexture | `` | `void` | `obj:_NV_updateCharaterTexture()` |
| setPosture | setPosture | `posture: number, neck: number, shoulders: number` | `void` | `obj:setPosture(posture, neck, shoulders)` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| isArmour | isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| getItemWeight | getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _NV_getItemWeight | _NV_getItemWeight | `` | `number` | `obj:_NV_getItemWeight()` |
| getValueSingle | getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| hasArmourCoverage | hasArmourCoverage | `` | `boolean` | `obj:hasArmourCoverage()` |
| getCraftTime | getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getWeatherProtection_simple | getWeatherProtection_simple | `weather: integer` | `number` | `obj:getWeatherProtection_simple(weather)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| didIHitFlesh | didIHitFlesh | `` | `boolean` | `obj:didIHitFlesh()` |
| getArmourCraftingMaterialConsumptionRate | getArmourCraftingMaterialConsumptionRate | `` | `number` | `obj:getArmourCraftingMaterialConsumptionRate()` |

## AttachedArrowManager
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| index | index | integer | RW | `obj.index = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAll | clearAll | `` | `void` | `obj:clearAll()` |
| updateStart | updateStart | `` | `void` | `obj:updateStart()` |
| addArrow | addArrow | `pos: Vector3, targ: Vector3, color: integer` | `void` | `obj:addArrow(pos, targ, color)` |
| updateEnd | updateEnd | `` | `void` | `obj:updateEnd()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Character::AttachedArrowManager` | `obj:_CONSTRUCTOR()` |

## AttackSlotManager
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Character | R | `obj.me` |
| combatClass | (void* | lightuserdata | R | `obj.combatClass` |
| attackSlotH | (void* | lightuserdata | R | `obj.attackSlotH` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasFreeAttackSlot | hasFreeAttackSlot | `` | `boolean` | `obj:hasFreeAttackSlot()` |
| freeAllSlotsH | freeAllSlotsH | `` | `void` | `obj:freeAllSlotsH()` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| update | update | `` | `void` | `obj:update()` |
| getNumAttackSlots | getNumAttackSlots | `` | `integer` | `obj:getNumAttackSlots()` |
| getMaxPossibleAttackSlots | getMaxPossibleAttackSlots | `` | `integer` | `obj:getMaxPossibleAttackSlots()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BackThreadMessagesToMainT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| flush | flush | `` | `boolean` | `obj:flush()` |

## BackpackInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `standAlone: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(standAlone)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Bounty
**Header:** `extern/KenshiLib/Include/kenshi/Bounty.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| amount | amount | integer | RW | `obj.amount = <value>` |
| crimes | crimes | integer | RW | `obj.crimes = <value>` |
| bountyHasBeenClaimedOnce | bountyHasBeenClaimedOnce | boolean | RW | `obj.bountyHasBeenClaimedOnce = <value>` |
| bountyAssignmentStartedTime | bountyAssignmentStartedTime | TimeOfDay | RW | `obj.bountyAssignmentStartedTime = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Bounty` | `obj:_CONSTRUCTOR()` |
| addCrime | addCrime | `crime: integer` | `void` | `obj:addCrime(crime)` |
| hasCrime | hasCrime | `crime: integer` | `boolean` | `obj:hasCrime(crime)` |

## BountyManager
**Header:** `extern/KenshiLib/Include/kenshi/BountyManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| bounties | bounties | unknown | RW | `obj.bounties = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
| _hasAccessPass | _hasAccessPass | Faction | RW | `obj._hasAccessPass = <value>` |
| accessPassExpirationTime | accessPassExpirationTime | TimeOfDay | RW | `obj.accessPassExpirationTime = <value>` |
| committingCrime | (int | integer | RW | `obj.committingCrime = <value>` |
| crimeAgainstFaction | crimeAgainstFaction | Faction | RW | `obj.crimeAgainstFaction = <value>` |
| usingTrainingEquipmentOf | usingTrainingEquipmentOf | Faction | RW | `obj.usingTrainingEquipmentOf = <value>` |
| crimeAgainst | crimeAgainst | hand | RW | `obj.crimeAgainst = <value>` |
| crimeExpiry | crimeExpiry | number | RW | `obj.crimeExpiry = <value>` |
| prisonSentenceBeganTime | prisonSentenceBeganTime | TimeOfDay | RW | `obj.prisonSentenceBeganTime = <value>` |
| prisonSentenceToServe | prisonSentenceToServe | number | RW | `obj.prisonSentenceToServe = <value>` |
| _hadABountyAssignedForCurrentCrime | _hadABountyAssignedForCurrentCrime | boolean | RW | `obj._hadABountyAssignedForCurrentCrime = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _getHighestBountyFaction | _getHighestBountyFaction | `` | `Faction` | `obj:_getHighestBountyFaction()` |
| getBountyRecognitionThreshold | getBountyRecognitionThreshold | `` | `integer` | `obj:getBountyRecognitionThreshold()` |
| getTotalBounty | getTotalBounty | `` | `integer` | `obj:getTotalBounty()` |
| update | update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| getBountyExpiryStringForGUI | getBountyExpiryStringForGUI | `` | `string` | `obj:getBountyExpiryStringForGUI()` |
| notifyPossibleCrimeWitnessed | notifyPossibleCrimeWitnessed | `time: number` | `void` | `obj:notifyPossibleCrimeWitnessed(time)` |
| isCommittingCrime | isCommittingCrime | `` | `boolean` | `obj:isCommittingCrime()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _getBountyFaction | _getBountyFaction | `` | `Faction` | `obj:_getBountyFaction()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `BountyManager` | `obj:_CONSTRUCTOR()` |
| getPercievedBounty | getPercievedBounty | `` | `integer` | `obj:getPercievedBounty()` |
| getActualBounty | getActualBounty | `` | `integer` | `obj:getActualBounty()` |
| notifyPlayerClaimBounty | notifyPlayerClaimBounty | `` | `void` | `obj:notifyPlayerClaimBounty()` |
| bountyAlreadyBeenClaimedByPlayer | bountyAlreadyBeenClaimedByPlayer | `` | `boolean` | `obj:bountyAlreadyBeenClaimedByPlayer()` |
| assignBountyForCrimes | assignBountyForCrimes | `` | `void` | `obj:assignBountyForCrimes()` |
| unfairAddToBounty | unfairAddToBounty | `amount: integer` | `void` | `obj:unfairAddToBounty(amount)` |
| clearBounty | clearBounty | `` | `void` | `obj:clearBounty()` |
| load | load | `` | `void` | `obj:load()` |
| save | save | `` | `void` | `obj:save()` |
| setCrime | setCrime | `crime: integer` | `boolean` | `obj:setCrime(crime)` |
| notifyCrimeWitnessed | notifyCrimeWitnessed | `expirytime: integer, what: integer` | `void` | `obj:notifyCrimeWitnessed(expirytime, what)` |
| notifyStartPrisonSentence | notifyStartPrisonSentence | `` | `void` | `obj:notifyStartPrisonSentence()` |
| hasAccessPass | hasAccessPass | `` | `boolean` | `obj:hasAccessPass()` |
| giveAccessPass | giveAccessPass | `minutes: number` | `void` | `obj:giveAccessPass(minutes)` |
| crimeToStr | crimeToStr | `` | `string` | `obj:crimeToStr()` |
| getBountyForCrime | getBountyForCrime | `` | `integer` | `obj:getBountyForCrime()` |
| getPrisonSentenceInHours | getPrisonSentenceInHours | `` | `integer` | `obj:getPrisonSentenceInHours()` |
| getBountyExpirationTime | getBountyExpirationTime | `` | `number` | `obj:getBountyExpirationTime()` |

## BuildInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| input1NameText | (void* | lightuserdata | R | `obj.input1NameText` |
| input2NameText | (void* | lightuserdata | R | `obj.input2NameText` |
| input1StatusText | (void* | lightuserdata | R | `obj.input1StatusText` |
| input2StatusText | (void* | lightuserdata | R | `obj.input2StatusText` |
| input1ItemIcon | (void* | lightuserdata | R | `obj.input1ItemIcon` |
| input2ItemIcon | (void* | lightuserdata | R | `obj.input2ItemIcon` |
| outputNameText | (void* | lightuserdata | R | `obj.outputNameText` |
| outputItemIcon | (void* | lightuserdata | R | `obj.outputItemIcon` |
| input1Panel | (void* | lightuserdata | R | `obj.input1Panel` |
| input2Panel | (void* | lightuserdata | R | `obj.input2Panel` |
| input1Progress | (void* | lightuserdata | R | `obj.input1Progress` |
| input2Progress | (void* | lightuserdata | R | `obj.input2Progress` |
| outputProgress | (void* | lightuserdata | R | `obj.outputProgress` |
| inputs | inputs | integer | RW | `obj.inputs = <value>` |
| outputs | outputs | integer | RW | `obj.outputs = <value>` |
| input1Item | input1Item | Item | R | `obj.input1Item` |
| input2Item | input2Item | Item | R | `obj.input2Item` |
| outputItem | outputItem | Item | R | `obj.outputItem` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `title: string, ins: integer, outs: integer, hasQueue: boolean` | `BuildInventoryLayout` | `obj:_CONSTRUCTOR(title, ins, outs, hasQueue)` |
| setInput | setInput | `inputIndex: integer, name: string, status: string` | `void` | `obj:setInput(inputIndex, name, status)` |
| setOutput | setOutput | `name: string` | `void` | `obj:setOutput(name)` |
| setInputProgress | setInputProgress | `inputIdx: integer, progress: number` | `void` | `obj:setInputProgress(inputIdx, progress)` |
| setInputEnabled | setInputEnabled | `inputIdx: integer, value: boolean` | `void` | `obj:setInputEnabled(inputIdx, value)` |
| setOutputProgress | setOutputProgress | `progress: number` | `void` | `obj:setOutputProgress(progress)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildMaterial
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mat | mat | GameData | RW | `obj.mat = <value>` |
| buildMatsTotal | buildMatsTotal | number | RW | `obj.buildMatsTotal = <value>` |
| amountOfMaterials | amountOfMaterials | number | RW | `obj.amountOfMaterials = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getMaterialsBarProgress | getMaterialsBarProgress | `` | `number` | `obj:getMaterialsBarProgress()` |
| getNumRemaining | getNumRemaining | `` | `number` | `obj:getNumRemaining()` |

## BuildModeWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| playerBuildMode | (void* | lightuserdata | R | `obj.playerBuildMode` |
| levelEditorMode | levelEditorMode | boolean | RW | `obj.levelEditorMode = <value>` |
| playerResearch | (void* | lightuserdata | R | `obj.playerResearch` |
| currentBuildingCategory | (void* | lightuserdata | R | `obj.currentBuildingCategory` |
| currentBuildingGroup | currentBuildingGroup | object | RW | `obj.currentBuildingGroup = <value>` |
| currentBuildingInfo | currentBuildingInfo | GameData | R | `obj.currentBuildingInfo` |
| currentBuildingIndex | currentBuildingIndex | integer | RW | `obj.currentBuildingIndex = <value>` |
| switchBuildingIndex | switchBuildingIndex | integer | RW | `obj.switchBuildingIndex = <value>` |
| statsDataPanel | statsDataPanel | DatapanelGUI | R | `obj.statsDataPanel` |
| confirmButton | (void* | lightuserdata | R | `obj.confirmButton` |
| undoButton | (void* | lightuserdata | R | `obj.undoButton` |
| closeButton | (void* | lightuserdata | R | `obj.closeButton` |
| categoriesList | (void* | lightuserdata | R | `obj.categoriesList` |
| buildingsList | (void* | lightuserdata | R | `obj.buildingsList` |
| buildingTxt | (void* | lightuserdata | R | `obj.buildingTxt` |
| buildingTypePrevButton | (void* | lightuserdata | R | `obj.buildingTypePrevButton` |
| buildingTypeNextButton | (void* | lightuserdata | R | `obj.buildingTypeNextButton` |
| buildingImageBox | (void* | lightuserdata | R | `obj.buildingImageBox` |
| statsPanel | (void* | lightuserdata | R | `obj.statsPanel` |
| descriptionTxt | (void* | lightuserdata | R | `obj.descriptionTxt` |
| messageTextBox | (void* | lightuserdata | R | `obj.messageTextBox` |
| floorDownButton | (void* | lightuserdata | R | `obj.floorDownButton` |
| floorUpButton | (void* | lightuserdata | R | `obj.floorUpButton` |
| floorText | (void* | lightuserdata | R | `obj.floorText` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setMessage | setMessage | `message: string` | `void` | `obj:setMessage(message)` |
| getBuildingListWidget | getBuildingListWidget | `` | `lightuserdata` | `obj:getBuildingListWidget()` |
| setVisible | setVisible | `v: boolean` | `void` | `obj:setVisible(v)` |
| setupData | setupData | `` | `void` | `obj:setupData()` |
| listCategories | listCategories | `` | `void` | `obj:listCategories()` |
| listBuildingGroups | listBuildingGroups | `` | `void` | `obj:listBuildingGroups()` |
| updateBuildingUI | updateBuildingUI | `` | `void` | `obj:updateBuildingUI()` |
| build | build | `` | `void` | `obj:build()` |
| showBuildingStats | showBuildingStats | `` | `void` | `obj:showBuildingStats()` |
| update | update | `` | `void` | `obj:update()` |
| changeCurrentIndex | changeCurrentIndex | `index: integer` | `void` | `obj:changeCurrentIndex(index)` |

## Building
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isFoliage | isFoliage | boolean | RW | `obj.isFoliage = <value>` |
| hasTerrainInside | hasTerrainInside | boolean | RW | `obj.hasTerrainInside = <value>` |
| isCavernous | isCavernous | boolean | RW | `obj.isCavernous = <value>` |
| enforceCeiling | enforceCeiling | boolean | RW | `obj.enforceCeiling = <value>` |
| designation | (lua_Integer | integer | RW | `obj.designation = <value>` |
| publicDaytime | publicDaytime | boolean | RW | `obj.publicDaytime = <value>` |
| residentSquad | residentSquad | hand | RW | `obj.residentSquad = <value>` |
| residentSquadTemplate | residentSquadTemplate | GameData | RW | `obj.residentSquadTemplate = <value>` |
| isAnInteriorObject | isAnInteriorObject | boolean | RW | `obj.isAnInteriorObject = <value>` |
| instanceID | instanceID | InstanceID | RW | `obj.instanceID = <value>` |
| layoutInstanceID | layoutInstanceID | string | RW | `obj.layoutInstanceID = <value>` |
| specialFunction | (lua_Integer | integer | RW | `obj.specialFunction = <value>` |
| _buildState | _buildState | Building::ConstructionState | RW | `obj._buildState = <value>` |
| classType | (lua_Integer | integer | RW | `obj.classType = <value>` |
| updateNavmesh | updateNavmesh | boolean | RW | `obj.updateNavmesh = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| interiorVisibility | interiorVisibility | boolean | RW | `obj.interiorVisibility = <value>` |
| justBeenUpgradedFlag | justBeenUpgradedFlag | boolean | RW | `obj.justBeenUpgradedFlag = <value>` |
| imADoor | imADoor | boolean | RW | `obj.imADoor = <value>` |
| destroyed | destroyed | boolean | RW | `obj.destroyed = <value>` |
| productionMult | productionMult | number | RW | `obj.productionMult = <value>` |
| productionMult_baseData | productionMult_baseData | number | RW | `obj.productionMult_baseData = <value>` |
| hasMovingParts | hasMovingParts | boolean | RW | `obj.hasMovingParts = <value>` |
| saveVersion | saveVersion | integer | RW | `obj.saveVersion = <value>` |
| _town | _town | hand | RW | `obj._town = <value>` |
| myInterior | (void* | lightuserdata | R | `obj.myInterior` |
| buildingsManager | buildingsManager | TownBuildingsManager | RW | `obj.buildingsManager = <value>` |
| rootNode | (void* | lightuserdata | R | `obj.rootNode` |
| soundEmitter | (void* | lightuserdata | R | `obj.soundEmitter` |
| hasAudio | hasAudio | boolean | RW | `obj.hasAudio = <value>` |
| interiorGround | (lua_Integer | integer | RW | `obj.interiorGround = <value>` |
| exteriorGround | (lua_Integer | integer | RW | `obj.exteriorGround = <value>` |
| physical | (void* | lightuserdata | R | `obj.physical` |
| entitiesToLoad | entitiesToLoad | integer | RW | `obj.entitiesToLoad = <value>` |
| entitiesLoaded | entitiesLoaded | boolean | RW | `obj.entitiesLoaded = <value>` |
| isFurnitureOf | (void* | lightuserdata | R | `obj.isFurnitureOf` |
| isOutsideFurniture | isOutsideFurniture | boolean | RW | `obj.isOutsideFurniture = <value>` |
| isNestItem | isNestItem | boolean | RW | `obj.isNestItem = <value>` |
| baseMaterial | baseMaterial | GameData | RW | `obj.baseMaterial = <value>` |
| effectsVisible | effectsVisible | boolean | RW | `obj.effectsVisible = <value>` |
| effectsActive | effectsActive | boolean | RW | `obj.effectsActive = <value>` |
| lightsVisible | lightsVisible | boolean | RW | `obj.lightsVisible = <value>` |
| positionMarker | positionMarker | Vector3 | RW | `obj.positionMarker = <value>` |
| heightAboveGround | heightAboveGround | number | RW | `obj.heightAboveGround = <value>` |
| isRedDebugTextureMode | isRedDebugTextureMode | boolean | RW | `obj.isRedDebugTextureMode = <value>` |
| materialName | materialName | string | RW | `obj.materialName = <value>` |
| triggerVolume | (void* | lightuserdata | R | `obj.triggerVolume` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getScale | getScale | `` | `number` | `obj:getScale()` |
| getBuildState | getBuildState | `` | `Building::ConstructionState` | `obj:getBuildState()` |
| _NV_getBuildState | _NV_getBuildState | `` | `Building::ConstructionState` | `obj:_NV_getBuildState()` |
| getBuildState_ActualNonShared | getBuildState_ActualNonShared | `` | `Building::ConstructionState` | `obj:getBuildState_ActualNonShared()` |
| select | select | `` | `void` | `obj:select()` |
| _NV_select | _NV_select | `` | `void` | `obj:_NV_select()` |
| getBuildingDesignation | getBuildingDesignation | `` | `integer` | `obj:getBuildingDesignation()` |
| addConstructionProgress | addConstructionProgress | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| _NV_addConstructionProgress | _NV_addConstructionProgress | `amount: number` | `void` | `obj:_NV_addConstructionProgress(amount)` |
| setConstructionProgress | setConstructionProgress | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| _NV_setConstructionProgress | _NV_setConstructionProgress | `amount: number` | `void` | `obj:_NV_setConstructionProgress(amount)` |
| notifyConstructionComplete | notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| addDismantleProgress | addDismantleProgress | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| _NV_addDismantleProgress | _NV_addDismantleProgress | `amount: number` | `boolean` | `obj:_NV_addDismantleProgress(amount)` |
| notifyConstructionDismantling | notifyConstructionDismantling | `` | `void` | `obj:notifyConstructionDismantling()` |
| _NV_notifyConstructionDismantling | _NV_notifyConstructionDismantling | `` | `void` | `obj:_NV_notifyConstructionDismantling()` |
| dropMats | dropMats | `` | `void` | `obj:dropMats()` |
| upgrade | upgrade | `` | `void` | `obj:upgrade()` |
| _NV_upgrade | _NV_upgrade | `` | `void` | `obj:_NV_upgrade()` |
| downgrade | downgrade | `` | `void` | `obj:downgrade()` |
| _NV_downgrade | _NV_downgrade | `` | `void` | `obj:_NV_downgrade()` |
| canUpgrade | canUpgrade | `` | `GameData` | `obj:canUpgrade()` |
| _NV_canUpgrade | _NV_canUpgrade | `` | `GameData` | `obj:_NV_canUpgrade()` |
| canDowngrade | canDowngrade | `` | `GameData` | `obj:canDowngrade()` |
| _NV_canDowngrade | _NV_canDowngrade | `` | `GameData` | `obj:_NV_canDowngrade()` |
| canDismantle | canDismantle | `` | `boolean` | `obj:canDismantle()` |
| _NV_canDismantle | _NV_canDismantle | `` | `boolean` | `obj:_NV_canDismantle()` |
| buyMeAsk | buyMeAsk | `` | `void` | `obj:buyMeAsk()` |
| _NV_buyMeAsk | _NV_buyMeAsk | `` | `void` | `obj:_NV_buyMeAsk()` |
| buyMeCallback | buyMeCallback | `result: integer` | `void` | `obj:buyMeCallback(result)` |
| _NV_buyMeCallback | _NV_buyMeCallback | `result: integer` | `void` | `obj:_NV_buyMeCallback(result)` |
| calculateSaleValue | calculateSaleValue | `` | `integer` | `obj:calculateSaleValue()` |
| loadNodes | loadNodes | `` | `void` | `obj:loadNodes()` |
| isPublic | isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| togglePublic | togglePublic | `` | `void` | `obj:togglePublic()` |
| _NV_togglePublic | _NV_togglePublic | `` | `void` | `obj:_NV_togglePublic()` |
| dismantleButton | dismantleButton | `` | `void` | `obj:dismantleButton()` |
| _NV_dismantleButton | _NV_dismantleButton | `` | `void` | `obj:_NV_dismantleButton()` |
| pauseButton | pauseButton | `` | `void` | `obj:pauseButton()` |
| _NV_pauseButton | _NV_pauseButton | `` | `void` | `obj:_NV_pauseButton()` |
| confirmDismantle | confirmDismantle | `r: integer` | `void` | `obj:confirmDismantle(r)` |
| _NV_confirmDismantle | _NV_confirmDismantle | `r: integer` | `void` | `obj:_NV_confirmDismantle(r)` |
| isAShop | isAShop | `` | `boolean` | `obj:isAShop()` |
| _NV_isAShop | _NV_isAShop | `` | `boolean` | `obj:_NV_isAShop()` |
| isForSale | isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| isAWall | isAWall | `` | `WallBuilding` | `obj:isAWall()` |
| _NV_isAWall | _NV_isAWall | `` | `WallBuilding` | `obj:_NV_isAWall()` |
| isAWallRamp | isAWallRamp | `` | `boolean` | `obj:isAWallRamp()` |
| _NV_isAWallRamp | _NV_isAWallRamp | `` | `boolean` | `obj:_NV_isAWallRamp()` |
| hasInterior | hasInterior | `` | `boolean` | `obj:hasInterior()` |
| affectsNavmesh | affectsNavmesh | `` | `boolean` | `obj:affectsNavmesh()` |
| setResidentSquad | setResidentSquad | `` | `void` | `obj:setResidentSquad()` |
| getResidentSquadLeader | getResidentSquadLeader | `` | `Character` | `obj:getResidentSquadLeader()` |
| setDesignation | setDesignation | `d: integer` | `void` | `obj:setDesignation(d)` |
| getWallEndPosition | getWallEndPosition | `` | `Vector3` | `obj:getWallEndPosition()` |
| setupMiningResourceLevel | setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| _NV_setupMiningResourceLevel | _NV_setupMiningResourceLevel | `` | `void` | `obj:_NV_setupMiningResourceLevel()` |
| getMiningResourceLevel | getMiningResourceLevel | `` | `number` | `obj:getMiningResourceLevel()` |
| _NV_getMiningResourceLevel | _NV_getMiningResourceLevel | `` | `number` | `obj:_NV_getMiningResourceLevel()` |
| addAnInternalBuilding | addAnInternalBuilding | `` | `void` | `obj:addAnInternalBuilding()` |
| getNumInternalBuildings | getNumInternalBuildings | `` | `integer` | `obj:getNumInternalBuildings()` |
| moveMountedBuildings | moveMountedBuildings | `` | `void` | `obj:moveMountedBuildings()` |
| reCheckInsideOutsideFortificationStatus | reCheckInsideOutsideFortificationStatus | `` | `void` | `obj:reCheckInsideOutsideFortificationStatus()` |
| setInsideTownWalls | setInsideTownWalls | `code: integer` | `void` | `obj:setInsideTownWalls(code)` |
| _NV_setInsideTownWalls | _NV_setInsideTownWalls | `code: integer` | `void` | `obj:_NV_setInsideTownWalls(code)` |
| postCreationPathfinderSetupStuff | postCreationPathfinderSetupStuff | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| _NV_postCreationPathfinderSetupStuff | _NV_postCreationPathfinderSetupStuff | `` | `void` | `obj:_NV_postCreationPathfinderSetupStuff()` |
| getSpecialFunction | getSpecialFunction | `` | `integer` | `obj:getSpecialFunction()` |
| _NV_getSpecialFunction | _NV_getSpecialFunction | `` | `integer` | `obj:_NV_getSpecialFunction()` |
| getFunctionStuff | getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| _NV_getFunctionStuff | _NV_getFunctionStuff | `` | `StorageBuilding` | `obj:_NV_getFunctionStuff()` |
| getUseableStuff | getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| isBroken | isBroken | `` | `boolean` | `obj:isBroken()` |
| _NV_isBroken | _NV_isBroken | `` | `boolean` | `obj:_NV_isBroken()` |
| setBroken | setBroken | `_a1: boolean` | `void` | `obj:setBroken(_a1)` |
| _NV_setBroken | _NV_setBroken | `_a1: boolean` | `void` | `obj:_NV_setBroken(_a1)` |
| switchPowerOn | switchPowerOn | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| _NV_switchPowerOn | _NV_switchPowerOn | `on: boolean` | `void` | `obj:_NV_switchPowerOn(on)` |
| isPowerOn | isPowerOn | `` | `boolean` | `obj:isPowerOn()` |
| _NV_isPowerOn | _NV_isPowerOn | `` | `boolean` | `obj:_NV_isPowerOn()` |
| isDamaged | isDamaged | `` | `boolean` | `obj:isDamaged()` |
| _NV_isDamaged | _NV_isDamaged | `` | `boolean` | `obj:_NV_isDamaged()` |
| isDestroyed | isDestroyed | `` | `boolean` | `obj:isDestroyed()` |
| _NV_isDestroyed | _NV_isDestroyed | `` | `boolean` | `obj:_NV_isDestroyed()` |
| isSign | isSign | `` | `boolean` | `obj:isSign()` |
| _NV_isSign | _NV_isSign | `` | `boolean` | `obj:_NV_isSign()` |
| setDestroyed | setDestroyed | `d: boolean` | `void` | `obj:setDestroyed(d)` |
| _NV_setDestroyed | _NV_setDestroyed | `d: boolean` | `void` | `obj:_NV_setDestroyed(d)` |
| canBeDestroyed | canBeDestroyed | `` | `boolean` | `obj:canBeDestroyed()` |
| _NV_canBeDestroyed | _NV_canBeDestroyed | `` | `boolean` | `obj:_NV_canBeDestroyed()` |
| setNestTag | setNestTag | `` | `void` | `obj:setNestTag()` |
| getReachRange | getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| hasShopCountersSelling | hasShopCountersSelling | `type: integer` | `boolean` | `obj:hasShopCountersSelling(type)` |
| getBuildingClass | getBuildingClass | `` | `integer` | `obj:getBuildingClass()` |
| _NV_getBuildingClass | _NV_getBuildingClass | `` | `integer` | `obj:_NV_getBuildingClass()` |
| needsSaving | needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| _NV_needsSaving | _NV_needsSaving | `mod: string` | `boolean` | `obj:_NV_needsSaving(mod)` |
| notifyChange | notifyChange | `` | `void` | `obj:notifyChange()` |
| getInstanceID | getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| _NV_getInstanceID | _NV_getInstanceID | `` | `InstanceID` | `obj:_NV_getInstanceID()` |
| setToDefaultFactionDivision | setToDefaultFactionDivision | `` | `void` | `obj:setToDefaultFactionDivision()` |
| getOutputBasedRotationSpeedMult | getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| _NV_getOutputBasedRotationSpeedMult | _NV_getOutputBasedRotationSpeedMult | `` | `number` | `obj:_NV_getOutputBasedRotationSpeedMult()` |
| calculateEfficiencyMult | calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| _NV_calculateEfficiencyMult | _NV_calculateEfficiencyMult | `` | `number` | `obj:_NV_calculateEfficiencyMult()` |
| getSoundIntensity | getSoundIntensity | `` | `number` | `obj:getSoundIntensity()` |
| _NV_getSoundIntensity | _NV_getSoundIntensity | `` | `number` | `obj:_NV_getSoundIntensity()` |
| loadUnloadCheck | loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _saveBuildingState | _saveBuildingState | `doorID: string` | `void` | `obj:_saveBuildingState(doorID)` |
| _NV__saveBuildingState | _NV__saveBuildingState | `doorID: string` | `void` | `obj:_NV__saveBuildingState(doorID)` |
| _loadBuildingState | _loadBuildingState | `doorID: string` | `void` | `obj:_loadBuildingState(doorID)` |
| _NV__loadBuildingState | _NV__loadBuildingState | `doorID: string` | `void` | `obj:_NV__loadBuildingState(doorID)` |
| getGUIName | getGUIName | `category: integer` | `void` | `obj:getGUIName(category)` |
| _NV_getGUIName | _NV_getGUIName | `category: integer` | `void` | `obj:_NV_getGUIName(category)` |
| getGUIState | getGUIState | `category: integer` | `void` | `obj:getGUIState(category)` |
| _NV_getGUIState | _NV_getGUIState | `category: integer` | `void` | `obj:_NV_getGUIState(category)` |
| getGUICondition | getGUICondition | `category: integer` | `void` | `obj:getGUICondition(category)` |
| _NV_getGUICondition | _NV_getGUICondition | `category: integer` | `void` | `obj:_NV_getGUICondition(category)` |
| getGUIUpgrade | getGUIUpgrade | `category: integer` | `void` | `obj:getGUIUpgrade(category)` |
| _NV_getGUIUpgrade | _NV_getGUIUpgrade | `category: integer` | `void` | `obj:_NV_getGUIUpgrade(category)` |
| getGUIDestroyButton | getGUIDestroyButton | `category: integer` | `void` | `obj:getGUIDestroyButton(category)` |
| _NV_getGUIDestroyButton | _NV_getGUIDestroyButton | `category: integer` | `void` | `obj:_NV_getGUIDestroyButton(category)` |
| getProductionBuilding | getProductionBuilding | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| _NV_getProductionBuilding | _NV_getProductionBuilding | `` | `ProductionBuilding` | `obj:_NV_getProductionBuilding()` |
| getProductionMultForGUI | getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| _NV_getProductionMultForGUI | _NV_getProductionMultForGUI | `` | `number` | `obj:_NV_getProductionMultForGUI()` |
| getProductionMult | getProductionMult | `` | `number` | `obj:getProductionMult()` |
| _NV_getProductionMult | _NV_getProductionMult | `` | `number` | `obj:_NV_getProductionMult()` |
| isThePlayer | isThePlayer | `` | `boolean` | `obj:isThePlayer()` |
| doorStuff | doorStuff | `` | `DoorStuff` | `obj:doorStuff()` |
| _NV_doorStuff | _NV_doorStuff | `` | `DoorStuff` | `obj:_NV_doorStuff()` |
| doorParentBuilding | doorParentBuilding | `` | `Building` | `obj:doorParentBuilding()` |
| _NV_doorParentBuilding | _NV_doorParentBuilding | `` | `Building` | `obj:_NV_doorParentBuilding()` |
| isDoor | isDoor | `` | `boolean` | `obj:isDoor()` |
| isGate | isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| _NV_isGate | _NV_isGate | `` | `GatewayBuilding` | `obj:_NV_isGate()` |
| getDoor | getDoor | `` | `DoorStuff` | `obj:getDoor()` |
| _NV_getDoor | _NV_getDoor | `` | `DoorStuff` | `obj:_NV_getDoor()` |
| getParentLayout | getParentLayout | `` | `lightuserdata` | `obj:getParentLayout()` |
| isFurniture | isFurniture | `` | `boolean` | `obj:isFurniture()` |
| isFurnitureOrDoor | isFurnitureOrDoor | `` | `boolean` | `obj:isFurnitureOrDoor()` |
| getIsOutsideFurniture | getIsOutsideFurniture | `` | `boolean` | `obj:getIsOutsideFurniture()` |
| setIsOutsideFurniture | setIsOutsideFurniture | `value: boolean` | `void` | `obj:setIsOutsideFurniture(value)` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| furnitureParentBuilding | furnitureParentBuilding | `` | `Building` | `obj:furnitureParentBuilding()` |
| hasAnOpenDoor | hasAnOpenDoor | `` | `boolean` | `obj:hasAnOpenDoor()` |
| allowAnimals | allowAnimals | `` | `boolean` | `obj:allowAnimals()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| threadedUpdate | threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| isPhysical | isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| checkLoadedProperly | checkLoadedProperly | `` | `void` | `obj:checkLoadedProperly()` |
| _NV_checkLoadedProperly | _NV_checkLoadedProperly | `` | `void` | `obj:_NV_checkLoadedProperly()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| loadFromSerialise_TheDoors | loadFromSerialise_TheDoors | `` | `void` | `obj:loadFromSerialise_TheDoors()` |
| _NV_loadFromSerialise_TheDoors | _NV_loadFromSerialise_TheDoors | `` | `void` | `obj:_NV_loadFromSerialise_TheDoors()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| getDoorLock | getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| _NV_getDoorLock | _NV_getDoorLock | `` | `lightuserdata` | `obj:_NV_getDoorLock()` |
| hasDoorLock | hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| _NV_hasDoorLock | _NV_hasDoorLock | `` | `boolean` | `obj:_NV_hasDoorLock()` |
| getMouseCursor | getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| _changeTown | _changeTown | `` | `void` | `obj:_changeTown()` |
| getTownHandle | getTownHandle | `` | `hand` | `obj:getTownHandle()` |
| getTown | getTown | `` | `TownBase` | `obj:getTown()` |
| getRealTown | getRealTown | `` | `Town` | `obj:getRealTown()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| destroyDoors | destroyDoors | `` | `void` | `obj:destroyDoors()` |
| createTriggerHull | createTriggerHull | `` | `void` | `obj:createTriggerHull()` |
| destroyAudioObject | destroyAudioObject | `` | `void` | `obj:destroyAudioObject()` |
| getGroundType | getGroundType | `inside: boolean` | `integer` | `obj:getGroundType(inside)` |
| isCeilingMounted | isCeilingMounted | `` | `boolean` | `obj:isCeilingMounted()` |
| _NV_isCeilingMounted | _NV_isCeilingMounted | `` | `boolean` | `obj:_NV_isCeilingMounted()` |
| setFloorVisibility | setFloorVisibility | `floor: integer, vis: boolean` | `void` | `obj:setFloorVisibility(floor, vis)` |
| getNumFloors | getNumFloors | `` | `integer` | `obj:getNumFloors()` |
| buildingComplete_RestoreMaterial | buildingComplete_RestoreMaterial | `` | `void` | `obj:buildingComplete_RestoreMaterial()` |
| loadInteriorPhysical | loadInteriorPhysical | `on: boolean` | `void` | `obj:loadInteriorPhysical(on)` |
| loadInteriorGraphics | loadInteriorGraphics | `on: boolean` | `void` | `obj:loadInteriorGraphics(on)` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| calculateLeftPost | calculateLeftPost | `` | `Vector3` | `obj:calculateLeftPost()` |
| setupLevelData | setupLevelData | `interior: string, exterior: string` | `void` | `obj:setupLevelData(interior, exterior)` |
| getLinkLength | getLinkLength | `` | `number` | `obj:getLinkLength()` |
| _NV_getLinkLength | _NV_getLinkLength | `` | `number` | `obj:_NV_getLinkLength()` |
| getRootNode | getRootNode | `` | `lightuserdata` | `obj:getRootNode()` |
| getZoneMapLocation | getZoneMapLocation | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| _NV_getZoneMapLocation | _NV_getZoneMapLocation | `` | `ZoneMap` | `obj:_NV_getZoneMapLocation()` |
| clearTownBuildingsManagerPtr | clearTownBuildingsManagerPtr | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| _NV_clearTownBuildingsManagerPtr | _NV_clearTownBuildingsManagerPtr | `` | `void` | `obj:_NV_clearTownBuildingsManagerPtr()` |
| setup | setup | `` | `void` | `obj:setup()` |
| _NV_setup | _NV_setup | `` | `void` | `obj:_NV_setup()` |
| setupFromData | setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| setupAudio | setupAudio | `` | `void` | `obj:setupAudio()` |
| switchLights | switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| _NV_switchLights | _NV_switchLights | `on: boolean` | `void` | `obj:_NV_switchLights(on)` |
| switchEffects | switchEffects | `on: boolean` | `void` | `obj:switchEffects(on)` |
| _NV_switchEffects | _NV_switchEffects | `on: boolean` | `void` | `obj:_NV_switchEffects(on)` |
| hasAnyGoodPositionMarkersLeft | hasAnyGoodPositionMarkersLeft | `` | `boolean` | `obj:hasAnyGoodPositionMarkersLeft()` |
| notifyBadPositionMarker | notifyBadPositionMarker | `what: Vector3` | `void` | `obj:notifyBadPositionMarker(what)` |
| getPositionMarker | getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getPositionMarker(currentPosition)` |
| _NV_getPositionMarker | _NV_getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getPositionMarker(currentPosition)` |
| getDirectionMarker | getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| _NV_getDirectionMarker | _NV_getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getDirectionMarker(currentPosition)` |
| getDirectionMarkerQuat | getDirectionMarkerQuat | `currentPosition: Vector3` | `Quaternion` | `obj:getDirectionMarkerQuat(currentPosition)` |
| _NV_getDirectionMarkerQuat | _NV_getDirectionMarkerQuat | `currentPosition: Vector3` | `Quaternion` | `obj:_NV_getDirectionMarkerQuat(currentPosition)` |
| isCreated | isCreated | `` | `boolean` | `obj:isCreated()` |
| _NV_isCreated | _NV_isCreated | `` | `boolean` | `obj:_NV_isCreated()` |
| updateUsageNodes | updateUsageNodes | `` | `void` | `obj:updateUsageNodes()` |
| forceValidUsageNodesValidation | forceValidUsageNodesValidation | `` | `void` | `obj:forceValidUsageNodesValidation()` |
| addUsageNode | addUsageNode | `nodeId: string` | `void` | `obj:addUsageNode(nodeId)` |
| removeUsageNode | removeUsageNode | `nodeId: string` | `void` | `obj:removeUsageNode(nodeId)` |
| clearUsageNodes | clearUsageNodes | `` | `void` | `obj:clearUsageNodes()` |
| notifyEffect | notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| updatePhysicalWithProgress | updatePhysicalWithProgress | `` | `void` | `obj:updatePhysicalWithProgress()` |
| recalculateWorldAABB | recalculateWorldAABB | `` | `void` | `obj:recalculateWorldAABB()` |
| selectPartMaterial | selectPartMaterial | `` | `GameData` | `obj:selectPartMaterial()` |
| getSeed | getSeed | `` | `integer` | `obj:getSeed()` |
| onBuildingLoaded | onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| _NV_onBuildingLoaded | _NV_onBuildingLoaded | `` | `void` | `obj:_NV_onBuildingLoaded()` |
| updateBadNodes | updateBadNodes | `` | `void` | `obj:updateBadNodes()` |

## BuildingCategory
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildingContainerInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| capacityText | (void* | lightuserdata | R | `obj.capacityText` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `BuildingContainerInventoryLayout` | `obj:_CONSTRUCTOR()` |
| setCapacity | setCapacity | `value: integer, full: boolean` | `void` | `obj:setCapacity(value, full)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildingGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildingPlacementGroundType
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

## BuildingSwaps
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| toReplace | toReplace | ogre_unordered_set<GameData*>::type | RW | `obj.toReplace = <value>` |
| replaceWith | replaceWith | FitnessSelector<GameData*> | RW | `obj.replaceWith = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Faction::BuildingSwaps` | `obj:_CONSTRUCTOR()` |
| hasReplacement | hasReplacement | `` | `boolean` | `obj:hasReplacement()` |
| getReplacement | getReplacement | `` | `void` | `obj:getReplacement()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | reset | `` | `void` | `obj:reset()` |
| update | update | `controlEnabled: boolean` | `void` | `obj:update(controlEnabled)` |
| updateOptionSettings | updateOptionSettings | `` | `void` | `obj:updateOptionSettings()` |
| teleport | teleport | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| stopFollowing | stopFollowing | `` | `void` | `obj:stopFollowing()` |
| manuallySetOrientationAndZoom | manuallySetOrientationAndZoom | `rot: Quaternion, zoom: number` | `void` | `obj:manuallySetOrientationAndZoom(rot, zoom)` |
| getFacingDirection | getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |
| getCenter | getCenter | `` | `Vector3` | `obj:getCenter()` |
| getCameraPos | getCameraPos | `` | `Vector3` | `obj:getCameraPos()` |
| isInitialised | isInitialised | `` | `boolean` | `obj:isInitialised()` |
| isFreeCameraMode | isFreeCameraMode | `` | `boolean` | `obj:isFreeCameraMode()` |
| setFreeCameraMode | setFreeCameraMode | `on: boolean` | `void` | `obj:setFreeCameraMode(on)` |
| updateFreeCamera | updateFreeCamera | `` | `void` | `obj:updateFreeCamera()` |
| move | move | `dir: Vector3` | `void` | `obj:move(dir)` |
| zoom | zoom | `` | `void` | `obj:zoom()` |
| toGround | toGround | `smooth: boolean` | `void` | `obj:toGround(smooth)` |
| setZoomDist | setZoomDist | `dist: number` | `void` | `obj:setZoomDist(dist)` |
| rotate | rotate | `_yaw: number, _pitch: number` | `void` | `obj:rotate(_yaw, _pitch)` |
| rotationUpdate | rotationUpdate | `` | `void` | `obj:rotationUpdate()` |
| updateAudio | updateAudio | `` | `void` | `obj:updateAudio()` |

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
**Header:** `extern/KenshiLib/Include/kenshi/CharBody.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| combatClass | combatClass | CombatClass | RW | `obj.combatClass = <value>` |
| animation | (void* | lightuserdata | RW | `obj.animation = <value>` |
| character | character | Character | RW | `obj.character = <value>` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |
| target | target | hand | RW | `obj.target = <value>` |
| gotItem | gotItem | boolean | RW | `obj.gotItem = <value>` |
| crouched | crouched | boolean | RW | `obj.crouched = <value>` |
| jogMode | jogMode | boolean | RW | `obj.jogMode = <value>` |
| arbitraryCatchupDist | arbitraryCatchupDist | number | RW | `obj.arbitraryCatchupDist = <value>` |
| ai | (void* | lightuserdata | RW | `obj.ai = <value>` |
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| frameTIME | frameTIME | number | RW | `obj.frameTIME = <value>` |
| currentAction | currentAction | Tasker | RW | `obj.currentAction = <value>` |
| amIdle | amIdle | boolean | RW | `obj.amIdle = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `CharBody` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `_time: number` | `void` | `obj:update(_time)` |
| _NV_update | _NV_update | `_time: number` | `void` | `obj:_NV_update(_time)` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| notifyBodyTaskComplete | notifyBodyTaskComplete | `` | `void` | `obj:notifyBodyTaskComplete()` |
| notifyTaskComplete | notifyTaskComplete | `` | `void` | `obj:notifyTaskComplete()` |
| _NV_notifyTaskComplete | _NV_notifyTaskComplete | `` | `void` | `obj:_NV_notifyTaskComplete()` |
| notifyTaskImpossible | notifyTaskImpossible | `` | `void` | `obj:notifyTaskImpossible()` |
| _NV_notifyTaskImpossible | _NV_notifyTaskImpossible | `` | `void` | `obj:_NV_notifyTaskImpossible()` |
| getCombatClass | getCombatClass | `` | `CombatClass` | `obj:getCombatClass()` |
| isCrouched | isCrouched | `` | `boolean` | `obj:isCrouched()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getName | getName | `` | `string` | `obj:getName()` |
| isCharacter | isCharacter | `` | `boolean` | `obj:isCharacter()` |
| _NV_isCharacter | _NV_isCharacter | `` | `boolean` | `obj:_NV_isCharacter()` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| _NV_getCharacter | _NV_getCharacter | `` | `Character` | `obj:_NV_getCharacter()` |
| getCharBody | getCharBody | `` | `CharBody` | `obj:getCharBody()` |
| _NV_getCharBody | _NV_getCharBody | `` | `CharBody` | `obj:_NV_getCharBody()` |
| getUpFromRagdoll | getUpFromRagdoll | `animationName: string` | `void` | `obj:getUpFromRagdoll(animationName)` |
| getPlatoon | getPlatoon | `` | `Platoon` | `obj:getPlatoon()` |
| _NV_getPlatoon | _NV_getPlatoon | `` | `Platoon` | `obj:_NV_getPlatoon()` |
| getCurrentAction | getCurrentAction | `` | `Tasker` | `obj:getCurrentAction()` |
| getCurrentActionOrMessage | getCurrentActionOrMessage | `` | `Tasker` | `obj:getCurrentActionOrMessage()` |
| endAction | endAction | `` | `void` | `obj:endAction()` |
| isIdle | isIdle | `` | `boolean` | `obj:isIdle()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |
| _endAction | _endAction | `` | `void` | `obj:_endAction()` |
| _NV__endAction | _NV__endAction | `` | `void` | `obj:_NV__endAction()` |
| create | create | `a: userdata, an: userdata` | `void` | `obj:create(a, an)` |
| setCurrentAction | setCurrentAction | `t: integer` | `boolean` | `obj:setCurrentAction(t)` |
| _NV_setCurrentAction | _NV_setCurrentAction | `t: integer` | `boolean` | `obj:_NV_setCurrentAction(t)` |
| notifyPathImpossible | notifyPathImpossible | `` | `void` | `obj:notifyPathImpossible()` |
| _NV_notifyPathImpossible | _NV_notifyPathImpossible | `` | `void` | `obj:_NV_notifyPathImpossible()` |
| _move | _move | `location: Vector3` | `void` | `obj:_move(location)` |
| _patrol | _patrol | `end: integer, pos: Vector3, area: userdata, taskSys: userdata` | `void` | `obj:_patrol(end, pos, area, taskSys)` |
| getHandle | CharBody_getHandle | `` | `hand` | `obj:getHandle()` |
| getCurrentSubject | CharBody_getCurrentSubject | `` | `hand` | `obj:getCurrentSubject()` |

## CharMovement
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _setPositionAndTeleport | _setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _NV__setPositionAndTeleport | _NV__setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_NV__setPositionAndTeleport(p, floor)` |
| _setPositionDirectionAndTeleport | _setPositionDirectionAndTeleport | `position: Vector3, orientation: Quaternion` | `void` | `obj:_setPositionDirectionAndTeleport(position, orientation)` |
| _NV__setPositionDirectionAndTeleport | _NV__setPositionDirectionAndTeleport | `position: Vector3, orientation: Quaternion` | `void` | `obj:_NV__setPositionDirectionAndTeleport(position, orientation)` |
| _setPositionSimple | _setPositionSimple | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| _NV__setPositionSimple | _NV__setPositionSimple | `p: Vector3` | `void` | `obj:_NV__setPositionSimple(p)` |
| isRunning | isRunning | `` | `boolean` | `obj:isRunning()` |
| isRunningAway | isRunningAway | `from: Vector3` | `boolean` | `obj:isRunningAway(from)` |
| trackAnimationMovement | trackAnimationMovement | `on: boolean` | `void` | `obj:trackAnimationMovement(on)` |
| handleChanged | handleChanged | `` | `void` | `obj:handleChanged()` |
| _NV_handleChanged | _NV_handleChanged | `` | `void` | `obj:_NV_handleChanged()` |
| getRadius | getRadius | `` | `number` | `obj:getRadius()` |
| update | update | `_TIME: number` | `void` | `obj:update(_TIME)` |
| _NV_update | _NV_update | `_TIME: number` | `void` | `obj:_NV_update(_TIME)` |
| pausedUpdate | pausedUpdate | `` | `void` | `obj:pausedUpdate()` |
| twoFrameUpdate | twoFrameUpdate | `_TIME: number` | `void` | `obj:twoFrameUpdate(_TIME)` |
| postAnimationUpdate | postAnimationUpdate | `` | `void` | `obj:postAnimationUpdate()` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| predictNextPosition | predictNextPosition | `accurate: boolean` | `Vector3` | `obj:predictNextPosition(accurate)` |
| getMaximumPossibleMovement | getMaximumPossibleMovement | `` | `number` | `obj:getMaximumPossibleMovement()` |
| faceDirection | faceDirection | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| _NV_faceDirection | _NV_faceDirection | `dir: Vector3` | `void` | `obj:_NV_faceDirection(dir)` |
| lookatPosition | lookatPosition | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| _NV_lookatPosition | _NV_lookatPosition | `pos: Vector3` | `void` | `obj:_NV_lookatPosition(pos)` |
| pathOk | pathOk | `` | `boolean` | `obj:pathOk()` |
| _NV_pathOk | _NV_pathOk | `` | `boolean` | `obj:_NV_pathOk()` |
| pathFailed | pathFailed | `` | `boolean` | `obj:pathFailed()` |
| _NV_pathFailed | _NV_pathFailed | `` | `boolean` | `obj:_NV_pathFailed()` |
| isDestinationReached | isDestinationReached | `` | `boolean` | `obj:isDestinationReached()` |
| _NV_isDestinationReached | _NV_isDestinationReached | `` | `boolean` | `obj:_NV_isDestinationReached()` |
| isIdle | isIdle | `` | `boolean` | `obj:isIdle()` |
| _NV_isIdle | _NV_isIdle | `` | `boolean` | `obj:_NV_isIdle()` |
| playerMoveOrderWhileInCombatMode | playerMoveOrderWhileInCombatMode | `pos: Vector3` | `boolean` | `obj:playerMoveOrderWhileInCombatMode(pos)` |
| _NV_playerMoveOrderWhileInCombatMode | _NV_playerMoveOrderWhileInCombatMode | `pos: Vector3` | `boolean` | `obj:_NV_playerMoveOrderWhileInCombatMode(pos)` |
| halt | halt | `` | `void` | `obj:halt()` |
| _NV_halt | _NV_halt | `` | `void` | `obj:_NV_halt()` |
| invalidatePath | invalidatePath | `` | `void` | `obj:invalidatePath()` |
| movedBy | movedBy | `pos: Vector3` | `void` | `obj:movedBy(pos)` |
| isCombatMovementBlockedByCharacters | isCombatMovementBlockedByCharacters | `` | `boolean` | `obj:isCombatMovementBlockedByCharacters()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| restore | restore | `` | `void` | `obj:restore()` |
| refreshClickHull | refreshClickHull | `` | `void` | `obj:refreshClickHull()` |
| teleportCollisionHull | teleportCollisionHull | `_pos: Vector3` | `void` | `obj:teleportCollisionHull(_pos)` |
| getCurrentFloor | getCurrentFloor | `` | `integer` | `obj:getCurrentFloor()` |
| isIndoorsHideMeCheck | isIndoorsHideMeCheck | `` | `boolean` | `obj:isIndoorsHideMeCheck()` |
| isIndoors | isIndoors | `` | `boolean` | `obj:isIndoors()` |
| manualMovement | manualMovement | `v: Vector3` | `void` | `obj:manualMovement(v)` |
| _NV_manualMovement | _NV_manualMovement | `v: Vector3` | `void` | `obj:_NV_manualMovement(v)` |
| isInsideBuildingLoadedInterior | isInsideBuildingLoadedInterior | `` | `boolean` | `obj:isInsideBuildingLoadedInterior()` |
| hasClickHull | hasClickHull | `` | `boolean` | `obj:hasClickHull()` |
| isTrackingAnimationMode | isTrackingAnimationMode | `` | `boolean` | `obj:isTrackingAnimationMode()` |
| isWaypointMoveMode | isWaypointMoveMode | `` | `boolean` | `obj:isWaypointMoveMode()` |
| setDirectMovement | setDirectMovement | `d: Vector3, limit: number` | `void` | `obj:setDirectMovement(d, limit)` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| toGround | toGround | `` | `boolean` | `obj:toGround()` |
| updateGroundMaterial | updateGroundMaterial | `` | `void` | `obj:updateGroundMaterial()` |
| getCombatMoveSpeedMult | getCombatMoveSpeedMult | `` | `number` | `obj:getCombatMoveSpeedMult()` |
| getHandle | CharMovement_getHandle | `` | `hand` | `obj:getHandle()` |
| _NV_getHandle | CharMovement__NV_getHandle | `` | `hand` | `obj:_NV_getHandle()` |

## CharStats
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| medical | medical | MedicalSystem | RW | `obj.medical = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
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
| _weatherProtections | _weatherProtections | WeatherProtectionsMapBinding::MapType | RW | `obj._weatherProtections = <value>` |
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
| bonusRaces | bonusRaces | BonusRacesMapBinding::MapType | RW | `obj.bonusRaces = <value>` |
| currentWeaponType | (lua_Integer | integer | RW | `obj.currentWeaponType = <value>` |
| pCurrentWeaponSkill | pCurrentWeaponSkill | number | RW | `obj.pCurrentWeaponSkill = <value>` |
| currentWeaponLength | currentWeaponLength | number | RW | `obj.currentWeaponLength = <value>` |
| weapon | weapon | hand | RW | `obj.weapon = <value>` |
| weaponWeight | weaponWeight | number | RW | `obj.weaponWeight = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWeatherProtection | getWeatherProtection | `w: integer` | `number` | `obj:getWeatherProtection(w)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `CharStats` | `obj:_CONSTRUCTOR()` |
| unarmedEncumbrancePenalty | unarmedEncumbrancePenalty | `` | `integer` | `obj:unarmedEncumbrancePenalty()` |
| skillBonusUnarmed_forGUI | skillBonusUnarmed_forGUI | `factorEnvironment: boolean` | `integer` | `obj:skillBonusUnarmed_forGUI(factorEnvironment)` |
| skillBonusAttack_melee | skillBonusAttack_melee | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_melee(factorEnvironment)` |
| skillBonusAttack_unarmed | skillBonusAttack_unarmed | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_unarmed(factorEnvironment)` |
| skillBonusDefence | skillBonusDefence | `factorEnvironment: boolean` | `integer` | `obj:skillBonusDefence(factorEnvironment)` |
| randomiseStats | _randomiseStats | `amount: number` | `void` | `obj:randomiseStats(amount)` |
| getGUIStatsDisplayMode | getGUIStatsDisplayMode | `` | `integer` | `obj:getGUIStatsDisplayMode()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| calculateStumbleThresholdDamageAmount | calculateStumbleThresholdDamageAmount | `` | `number` | `obj:calculateStumbleThresholdDamageAmount()` |
| setEquipmentStatBonuses | setEquipmentStatBonuses | `athlet: number, combatSpd: number, attack: integer, def: integer, _stealth: number, _unarmed: integer, _dodge: number, fistdamage: number, perception: integer, ranged: number, dexmult: number, assmult: number, damagemult: number` | `void` | `obj:setEquipmentStatBonuses(athlet, combatSpd, attack, def, _stealth, _unarmed, _dodge, fistdamage, perception, ranged, dexmult, assmult, damagemult)` |
| getOverallSkillLevel_0_100 | getOverallSkillLevel_0_100 | `` | `number` | `obj:getOverallSkillLevel_0_100()` |
| getStat | getStat | `what: integer, unmodified: boolean` | `number` | `obj:getStat(what, unmodified)` |
| getStatMultiplier | getStatMultiplier | `st: integer` | `number` | `obj:getStatMultiplier(st)` |
| getStatMultiplierForGUI | getStatMultiplierForGUI | `st: integer` | `string` | `obj:getStatMultiplierForGUI(st)` |
| getStatPenaltiesTotalForGUI | getStatPenaltiesTotalForGUI | `statName: string, stat: integer` | `integer` | `obj:getStatPenaltiesTotalForGUI(statName, stat)` |
| xpStat_timeBased | xpStat_timeBased | `st: integer` | `void` | `obj:xpStat_timeBased(st)` |
| xpStat_eventBased | xpStat_eventBased | `st: integer, amount: number` | `void` | `obj:xpStat_eventBased(st, amount)` |
| xpDodgeEvent | xpDodgeEvent | `enemySkill: number, successful: boolean` | `void` | `obj:xpDodgeEvent(enemySkill, successful)` |
| strengthActual | strengthActual | `` | `number` | `obj:strengthActual()` |
| strengthBase | strengthBase | `` | `number` | `obj:strengthBase()` |
| _NV_strengthBase | _NV_strengthBase | `` | `number` | `obj:_NV_strengthBase()` |
| dexterityBase | dexterityBase | `` | `number` | `obj:dexterityBase()` |
| dexterityActual | dexterityActual | `` | `number` | `obj:dexterityActual()` |
| toughness | toughness | `` | `number` | `obj:toughness()` |
| getToughnessMult | getToughnessMult | `` | `number` | `obj:getToughnessMult()` |
| getRangedFriendlyFireAvoidanceChance | getRangedFriendlyFireAvoidanceChance | `` | `number` | `obj:getRangedFriendlyFireAvoidanceChance()` |
| getRangedAccuracyMult | getRangedAccuracyMult | `stat: integer` | `number` | `obj:getRangedAccuracyMult(stat)` |
| getReloadSkill | getReloadSkill | `stat: integer` | `number` | `obj:getReloadSkill(stat)` |
| animalRecruitReduceStats | animalRecruitReduceStats | `` | `void` | `obj:animalRecruitReduceStats()` |
| getMeleeDefence | getMeleeDefence | `includeDefensiveMode: boolean` | `number` | `obj:getMeleeDefence(includeDefensiveMode)` |
| getDodge | getDodge | `bonuses: boolean` | `number` | `obj:getDodge(bonuses)` |
| getDodgePenalty_encumbrance | getDodgePenalty_encumbrance | `` | `number` | `obj:getDodgePenalty_encumbrance()` |
| getDodgePenalty_injuries | getDodgePenalty_injuries | `` | `number` | `obj:getDodgePenalty_injuries()` |
| getDodgePenalty_gear | getDodgePenalty_gear | `` | `number` | `obj:getDodgePenalty_gear()` |
| getMeleeDefence_melee | getMeleeDefence_melee | `includeDefensiveMode: boolean` | `number` | `obj:getMeleeDefence_melee(includeDefensiveMode)` |
| getMeleeAttack | getMeleeAttack | `` | `number` | `obj:getMeleeAttack()` |
| getMeleeAttack_unarmed | getMeleeAttack_unarmed | `bonuses: boolean` | `number` | `obj:getMeleeAttack_unarmed(bonuses)` |
| getMeleeAttack_melee | getMeleeAttack_melee | `` | `number` | `obj:getMeleeAttack_melee()` |
| getMeleeAttackBase | _getMeleeAttackBase | `` | `number` | `obj:getMeleeAttackBase()` |
| isDefensiveMode | isDefensiveMode | `` | `boolean` | `obj:isDefensiveMode()` |
| holdPositionMode | holdPositionMode | `` | `boolean` | `obj:holdPositionMode()` |
| setHoldLocation | setHoldLocation | `v: Vector3` | `void` | `obj:setHoldLocation(v)` |
| clearHoldLocation | clearHoldLocation | `` | `void` | `obj:clearHoldLocation()` |
| calculateStumbleBlockTimer | calculateStumbleBlockTimer | `stumbleForce: number` | `number` | `obj:calculateStumbleBlockTimer(stumbleForce)` |
| calculateTechniqueInegrityCheckTimer | calculateTechniqueInegrityCheckTimer | `` | `number` | `obj:calculateTechniqueInegrityCheckTimer()` |
| calculateToughnessDamageResistanceMult | calculateToughnessDamageResistanceMult | `` | `number` | `obj:calculateToughnessDamageResistanceMult()` |
| calculateToughnessWoundDegenerationRate | calculateToughnessWoundDegenerationRate | `` | `number` | `obj:calculateToughnessWoundDegenerationRate()` |
| getAttackChance | getAttackChance | `` | `number` | `obj:getAttackChance()` |
| getAttackCuttingDamage | getAttackCuttingDamage | `` | `number` | `obj:getAttackCuttingDamage()` |
| getAttackBluntPower | getAttackBluntPower | `` | `number` | `obj:getAttackBluntPower()` |
| getAttackBleedDamageMult | getAttackBleedDamageMult | `` | `number` | `obj:getAttackBleedDamageMult()` |
| getAttackPierceDamage | getAttackPierceDamage | `` | `number` | `obj:getAttackPierceDamage()` |
| getEquippedWeaponSkill | getEquippedWeaponSkill | `` | `number` | `obj:getEquippedWeaponSkill()` |
| _NV_getEquippedWeaponSkill | _NV_getEquippedWeaponSkill | `` | `number` | `obj:_NV_getEquippedWeaponSkill()` |
| getSkillDifferenceRatio | getSkillDifferenceRatio | `mine: number, his: number` | `number` | `obj:getSkillDifferenceRatio(mine, his)` |
| calculateDeadTime | calculateDeadTime | `state: integer` | `number` | `obj:calculateDeadTime(state)` |
| xpToughness_RagdollEvent | xpToughness_RagdollEvent | `` | `void` | `obj:xpToughness_RagdollEvent()` |
| xpToughness_GetUpEvent | xpToughness_GetUpEvent | `` | `void` | `obj:xpToughness_GetUpEvent()` |
| xpToughness_PunchSomething | xpToughness_PunchSomething | `mat: integer` | `void` | `obj:xpToughness_PunchSomething(mat)` |
| xpRunning | xpRunning | `time: number, speed: number` | `void` | `obj:xpRunning(time, speed)` |
| xpStealthHearCheckEvent | xpStealthHearCheckEvent | `enemiesAbout: boolean, trespassing: boolean, seen: boolean` | `void` | `obj:xpStealthHearCheckEvent(enemiesAbout, trespassing, seen)` |
| xpMassCombat | xpMassCombat | `` | `void` | `obj:xpMassCombat()` |
| xpEngineering | xpEngineering | `time: number` | `void` | `obj:xpEngineering(time)` |
| xpLockpicking | xpLockpicking | `lockLevel: integer, success: boolean` | `void` | `obj:xpLockpicking(lockLevel, success)` |
| xpGeneral | xpGeneral | `time: number, mult: number, what: integer` | `void` | `obj:xpGeneral(time, mult, what)` |
| calculateAthleticsXPMult | calculateAthleticsXPMult | `speed: number` | `number` | `obj:calculateAthleticsXPMult(speed)` |
| calculateStrengthXPMultFromWalking | calculateStrengthXPMultFromWalking | `` | `number` | `obj:calculateStrengthXPMultFromWalking()` |
| isUnarmed | isUnarmed | `` | `boolean` | `obj:isUnarmed()` |
| getWeaponWeightXPBonus | getWeaponWeightXPBonus | `` | `number` | `obj:getWeaponWeightXPBonus()` |
| getAttackSpeed | getAttackSpeed | `` | `number` | `obj:getAttackSpeed()` |
| getBlockSpeed | getBlockSpeed | `` | `number` | `obj:getBlockSpeed()` |
| getMaxRunSpeed | getMaxRunSpeed | `` | `number` | `obj:getMaxRunSpeed()` |
| getCurrentWeaponLength | getCurrentWeaponLength | `` | `number` | `obj:getCurrentWeaponLength()` |
| getStealthSkill01 | getStealthSkill01 | `modded: boolean` | `number` | `obj:getStealthSkill01(modded)` |
| getAttackSuccessChanceSkill | getAttackSuccessChanceSkill | `` | `number` | `obj:getAttackSuccessChanceSkill()` |
| getEncumbranceMult | getEncumbranceMult | `` | `number` | `obj:getEncumbranceMult()` |
| calculateHungerMult | calculateHungerMult | `` | `number` | `obj:calculateHungerMult()` |
| calculateTheoreticalIdealMaxRunSpeed | calculateTheoreticalIdealMaxRunSpeed | `` | `number` | `obj:calculateTheoreticalIdealMaxRunSpeed()` |
| calculateWeaponWeightXPMult | calculateWeaponWeightXPMult | `weaponWeight: number` | `number` | `obj:calculateWeaponWeightXPMult(weaponWeight)` |
| hasWeapon | hasWeapon | `` | `boolean` | `obj:hasWeapon()` |
| calculateMaxStealthSpeed | calculateMaxStealthSpeed | `` | `number` | `obj:calculateMaxStealthSpeed()` |
| calculateMaxSwimSpeed | _calculateMaxSwimSpeed | `` | `number` | `obj:calculateMaxSwimSpeed()` |
| calculateSwimSpeed | calculateSwimSpeed | `` | `number` | `obj:calculateSwimSpeed()` |
| calculateDodgeChance | calculateDodgeChance | `versus: number, stumbling: boolean` | `number` | `obj:calculateDodgeChance(versus, stumbling)` |
| calculateMaxRunSpeed | calculateMaxRunSpeed | `` | `void` | `obj:calculateMaxRunSpeed()` |
| calculateEncumberanceMult | _calculateEncumberanceMult | `` | `number` | `obj:calculateEncumberanceMult()` |
| calculateWeaponWeightSpeedMultiplier | _calculateWeaponWeightSpeedMultiplier | `weaponWeight: number` | `void` | `obj:calculateWeaponWeightSpeedMultiplier(weaponWeight)` |
| currentWeaponHand | currentWeaponHand | `` | `integer` | `obj:currentWeaponHand()` |
| calculateAttackOrBlockSpeed | calculateAttackOrBlockSpeed | `weaponWeightSpeedMult: number, attackOrBlockSkill: number, isBlock: boolean` | `number` | `obj:calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock)` |
| calculateBlockChance | _calculateBlockChance | `versus: number` | `number` | `obj:calculateBlockChance(versus)` |
| recalculateStats | _recalculateStats | `` | `void` | `obj:recalculateStats()` |
| _NV__recalculateStats | _NV__recalculateStats | `` | `void` | `obj:_NV__recalculateStats()` |
| setEquippedWeaponSkill | setEquippedWeaponSkill | `v: number` | `void` | `obj:setEquippedWeaponSkill(v)` |
| _NV_setEquippedWeaponSkill | _NV_setEquippedWeaponSkill | `v: number` | `void` | `obj:_NV_setEquippedWeaponSkill(v)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getTotalAttackDamageFor | CharStats_getTotalAttackDamageFor | `` | `Damages` | `obj:getTotalAttackDamageFor()` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| updateStats | updateStats | `` | `void` | `obj:updateStats()` |
| init | init | `` | `void` | `obj:init()` |
| _NV_init | _NV_init | `` | `void` | `obj:_NV_init()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| printStealthStats | printStealthStats | `` | `void` | `obj:printStealthStats()` |
| printRunSpeedStatMax | printRunSpeedStatMax | `` | `void` | `obj:printRunSpeedStatMax()` |
| getGUIDataForMainInfo | getGUIDataForMainInfo | `category: integer, combatMode: boolean` | `void` | `obj:getGUIDataForMainInfo(category, combatMode)` |
| formatWholeStatStringWithBonuses | formatWholeStatStringWithBonuses | `stat: integer, current: integer` | `void` | `obj:formatWholeStatStringWithBonuses(stat, current)` |
| getStatRef | getStatRef | `what: integer` | `number` | `obj:getStatRef(what)` |
| getStatName | getStatName | `` | `void` | `obj:getStatName()` |
| getMeleeAttackRef | getMeleeAttackRef | `` | `number` | `obj:getMeleeAttackRef()` |
| getMaxHealAmount | getMaxHealAmount | `isRobot: boolean` | `number` | `obj:getMaxHealAmount(isRobot)` |
| getBashAnimation | getBashAnimation | `range: number` | `lightuserdata` | `obj:getBashAnimation(range)` |
| chooseAttack | chooseAttack | `range: number, weaponReach: number, lastAttack: userdata, opponentIsStationary: boolean` | `lightuserdata` | `obj:chooseAttack(range, weaponReach, lastAttack, opponentIsStationary)` |
| chooseBlock | chooseBlock | `dir: integer, opponentAttackSkill: number, from: integer` | `lightuserdata` | `obj:chooseBlock(dir, opponentAttackSkill, from)` |
| getPainAnim | getPainAnim | `` | `void` | `obj:getPainAnim()` |
| xpMelee | xpMelee | `what: integer` | `void` | `obj:xpMelee(what)` |
| xpFirstAid | xpFirstAid | `time: number, medicStat: integer` | `void` | `obj:xpFirstAid(time, medicStat)` |
| xpStealth | xpStealth | `time: number, enemiesAbout: boolean, seen: integer, isMoving: boolean` | `void` | `obj:xpStealth(time, enemiesAbout, seen, isMoving)` |
| setWeapon | setWeapon | `` | `void` | `obj:setWeapon()` |
| convertWeaponWeightToBluntMultiplier | _convertWeaponWeightToBluntMultiplier | `` | `number` | `obj:convertWeaponWeightToBluntMultiplier()` |
| convertBluntMultiplierToWeaponWeight | _convertBluntMultiplierToWeaponWeight | `` | `number` | `obj:convertBluntMultiplierToWeaponWeight()` |
| setupCombatTechniques | setupCombatTechniques | `` | `void` | `obj:setupCombatTechniques()` |
| getStealthTooltip | getStealthTooltip | `` | `void` | `obj:getStealthTooltip()` |
| getAthleticsTooltip | getAthleticsTooltip | `` | `void` | `obj:getAthleticsTooltip()` |
| getStatPenaltiesForGUI | getStatPenaltiesForGUI | `statName: string, stat: integer` | `boolean` | `obj:getStatPenaltiesForGUI(statName, stat)` |
| chooseAttacks | _chooseAttacks | `range: number, weaponReach: number, opponentIsStationary: boolean, skipMedicals: boolean, _weaponType: integer, _weaponSkill: number` | `void` | `obj:chooseAttacks(range, weaponReach, opponentIsStationary, skipMedicals, _weaponType, _weaponSkill)` |
| stealthXPMultForGUI | stealthXPMultForGUI | `` | `StringPair` | `obj:stealthXPMultForGUI()` |
| printExertionHungerMultTooltip | printExertionHungerMultTooltip | `` | `void` | `obj:printExertionHungerMultTooltip()` |
| xpTraining | xpTraining | `time: number, mult: number, statVal: number, upperLimit: number, whatStatIsIt: integer` | `number` | `obj:xpTraining(time, mult, statVal, upperLimit, whatStatIsIt)` |

## Character
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

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
| stealthUnseen | stealthUnseen | YesNoMaybe | RW | `obj.stealthUnseen = <value>` |
| playerWantsMeToGetUp | playerWantsMeToGetUp | boolean | RW | `obj.playerWantsMeToGetUp = <value>` |
| crimes | crimes | BountyManager | RW | `obj.crimes = <value>` |
| currentSkillUsing | (lua_Integer | integer | RW | `obj.currentSkillUsing = <value>` |
| stateBroadcast | (void* | lightuserdata | RW | `obj.stateBroadcast = <value>` |
| isVisibleAndNear | isVisibleAndNear | boolean | RW | `obj.isVisibleAndNear = <value>` |
| isOnScreen | isOnScreen | boolean | RW | `obj.isOnScreen = <value>` |
| stealthMarkerArrows | stealthMarkerArrows | Character::AttachedArrowManager | R | `obj.stealthMarkerArrows` |
| _isEngagedWithAPlayer | _isEngagedWithAPlayer | boolean | RW | `obj._isEngagedWithAPlayer = <value>` |
| isUsingTurret | isUsingTurret | hand | RW | `obj.isUsingTurret = <value>` |
| isCurrentlyGettingUp | isCurrentlyGettingUp | boolean | RW | `obj.isCurrentlyGettingUp = <value>` |
| isGettingEaten | isGettingEaten | integer | RW | `obj.isGettingEaten = <value>` |
| dialogue | dialogue | Dialogue | RW | `obj.dialogue = <value>` |
| currentStumblePainAnimation | currentStumblePainAnimation | string | RW | `obj.currentStumblePainAnimation = <value>` |
| _isLiterallyUnderMeleeAttackRightNowForSure | _isLiterallyUnderMeleeAttackRightNowForSure | boolean | RW | `obj._isLiterallyUnderMeleeAttackRightNowForSure = <value>` |
| _myMemory | (void* | lightuserdata | RW | `obj._myMemory = <value>` |
| lastGuyWhoDefeatedMe | lastGuyWhoDefeatedMe | hand | RW | `obj.lastGuyWhoDefeatedMe = <value>` |
| myRace | myRace | RaceData | RW | `obj.myRace = <value>` |
| inventory | inventory | Inventory | RW | `obj.inventory = <value>` |
| rangedCombat | (void* | lightuserdata | RW | `obj.rangedCombat = <value>` |
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
| msgCarryMode | (void* | lightuserdata | RW | `obj.msgCarryMode = <value>` |
| squadMemberID | squadMemberID | integer | RW | `obj.squadMemberID = <value>` |
| diplomacyMultiplier | diplomacyMultiplier | number | RW | `obj.diplomacyMultiplier = <value>` |
| _destinationInsideBuilding | _destinationInsideBuilding | hand | RW | `obj._destinationInsideBuilding = <value>` |
| _destinationInsideWalls | _destinationInsideWalls | integer | RW | `obj._destinationInsideWalls = <value>` |
| animation | (void* | lightuserdata | RW | `obj.animation = <value>` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |
| medical | medical | MedicalSystem | RW | `obj.medical = <value>` |
| isPhysicalMode | isPhysicalMode | boolean | RW | `obj.isPhysicalMode = <value>` |
| sex | sex | string | RW | `obj.sex = <value>` |
| nameTag | (void* | lightuserdata | RW | `obj.nameTag = <value>` |
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| body | body | CharBody | RW | `obj.body = <value>` |
| ai | (void* | lightuserdata | RW | `obj.ai = <value>` |
| platoon | platoon | ActivePlatoon | RW | `obj.platoon = <value>` |
| portraitIndex | portraitIndex | integer | RW | `obj.portraitIndex = <value>` |
| portraitSerial | portraitSerial | integer | RW | `obj.portraitSerial = <value>` |
| groundType | (lua_Integer | integer | RW | `obj.groundType = <value>` |
| armourType | (lua_Integer | integer | RW | `obj.armourType = <value>` |
| audioEmitter | (void* | lightuserdata | RW | `obj.audioEmitter = <value>` |
| terrainHeightPosition | terrainHeightPosition | number | RW | `obj.terrainHeightPosition = <value>` |
| inDoorsSetCooldown | inDoorsSetCooldown | integer | RW | `obj.inDoorsSetCooldown = <value>` |
| naturalWeapon | naturalWeapon | Sword | RW | `obj.naturalWeapon = <value>` |
| disguiseGUIFeedbacks | (lua_Integer | integer | R | `obj.disguiseGUIFeedbacks` |
| whoSeesMeSneaking | first | hand | R | `obj.whoSeesMeSneaking` |
| inSomething | (lua_Integer | integer | RW | `obj.inSomething = <value>` |
| audioObject | (lua_Integer | integer | RW | `obj.audioObject = <value>` |
| activeEffects | (lua_Integer | integer | R | `obj.activeEffects` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isImmuneToOffscreenMode | isImmuneToOffscreenMode | `` | `boolean` | `obj:isImmuneToOffscreenMode()` |
| init | init | `` | `void` | `obj:init()` |
| _NV_init | _NV_init | `` | `void` | `obj:_NV_init()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isOnARoof | isOnARoof | `` | `boolean` | `obj:isOnARoof()` |
| _NV_isOnARoof | _NV_isOnARoof | `` | `boolean` | `obj:_NV_isOnARoof()` |
| isOnAWall | isOnAWall | `` | `boolean` | `obj:isOnAWall()` |
| _NV_isOnAWall | _NV_isOnAWall | `` | `boolean` | `obj:_NV_isOnAWall()` |
| getLightLevel | getLightLevel | `` | `number` | `obj:getLightLevel()` |
| getHPMultiplier | getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| _NV_getHPMultiplier | _NV_getHPMultiplier | `` | `number` | `obj:_NV_getHPMultiplier()` |
| healCompletely | healCompletely | `` | `void` | `obj:healCompletely()` |
| resetRagdollNavmeshSafePos | resetRagdollNavmeshSafePos | `` | `void` | `obj:resetRagdollNavmeshSafePos()` |
| setRagdollNavmeshSafePos | setRagdollNavmeshSafePos | `` | `void` | `obj:setRagdollNavmeshSafePos()` |
| getFrameTime | getFrameTime | `` | `number` | `obj:getFrameTime()` |
| frameSkip | frameSkip | `` | `void` | `obj:frameSkip()` |
| getCurrentNoiseRange | getCurrentNoiseRange | `` | `number` | `obj:getCurrentNoiseRange()` |
| isDestroyed | isDestroyed | `` | `boolean` | `obj:isDestroyed()` |
| _NV_isDestroyed | _NV_isDestroyed | `` | `boolean` | `obj:_NV_isDestroyed()` |
| isLawEnforcement | isLawEnforcement | `` | `boolean` | `obj:isLawEnforcement()` |
| canAssignBounties | canAssignBounties | `` | `boolean` | `obj:canAssignBounties()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| isDiplomaticStatus | isDiplomaticStatus | `factorInBiome: boolean` | `boolean` | `obj:isDiplomaticStatus(factorInBiome)` |
| isLeadingAWarCampaign | isLeadingAWarCampaign | `` | `boolean` | `obj:isLeadingAWarCampaign()` |
| isInAWarCampaign | isInAWarCampaign | `` | `lightuserdata` | `obj:isInAWarCampaign()` |
| wantsToTriggerCampaigns | wantsToTriggerCampaigns | `` | `boolean` | `obj:wantsToTriggerCampaigns()` |
| isUnique | isUnique | `` | `boolean` | `obj:isUnique()` |
| canSpeakNormally | canSpeakNormally | `` | `boolean` | `obj:canSpeakNormally()` |
| isAnimal | isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| _NV_isAnimal | _NV_isAnimal | `` | `CharacterAnimal` | `obj:_NV_isAnimal()` |
| isHuman | isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| _NV_isHuman | _NV_isHuman | `` | `CharacterHuman` | `obj:_NV_isHuman()` |
| takeMoney | takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| setSquadMemberType | setSquadMemberType | `memType: integer` | `void` | `obj:setSquadMemberType(memType)` |
| isResident | isResident | `` | `TownBase` | `obj:isResident()` |
| dailyUpdate | dailyUpdate | `` | `void` | `obj:dailyUpdate()` |
| updateOnScreenCheck | updateOnScreenCheck | `` | `boolean` | `obj:updateOnScreenCheck()` |
| offscreenUpdate | offscreenUpdate | `` | `void` | `obj:offscreenUpdate()` |
| updateTimes | updateTimes | `` | `void` | `obj:updateTimes()` |
| getSensoryData | getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| _NV_getSensoryData | _NV_getSensoryData | `` | `SensoryData` | `obj:_NV_getSensoryData()` |
| getStateBroadcast | getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| getFormation | getFormation | `` | `lightuserdata` | `obj:getFormation()` |
| _NV_getFormation | _NV_getFormation | `` | `lightuserdata` | `obj:_NV_getFormation()` |
| getEnemyFormation | getEnemyFormation | `` | `lightuserdata` | `obj:getEnemyFormation()` |
| _NV_getEnemyFormation | _NV_getEnemyFormation | `` | `lightuserdata` | `obj:_NV_getEnemyFormation()` |
| AIDestinationIndoorOutdoorCheck | AIDestinationIndoorOutdoorCheck | `` | `boolean` | `obj:AIDestinationIndoorOutdoorCheck()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| postUpdate | postUpdate | `` | `void` | `obj:postUpdate()` |
| _NV_postUpdate | _NV_postUpdate | `` | `void` | `obj:_NV_postUpdate()` |
| ragdollUpdatesUT | ragdollUpdatesUT | `` | `void` | `obj:ragdollUpdatesUT()` |
| fourFrameUpdate | fourFrameUpdate | `` | `void` | `obj:fourFrameUpdate()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| pausedUpdate | pausedUpdate | `` | `void` | `obj:pausedUpdate()` |
| _NV_pausedUpdate | _NV_pausedUpdate | `` | `void` | `obj:_NV_pausedUpdate()` |
| updateUT | updateUT | `` | `void` | `obj:updateUT()` |
| threadedUpdate | threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| threadedUpdate4 | threadedUpdate4 | `` | `void` | `obj:threadedUpdate4()` |
| _NV_threadedUpdate4 | _NV_threadedUpdate4 | `` | `void` | `obj:_NV_threadedUpdate4()` |
| threadedUpdatePeriodic | threadedUpdatePeriodic | `` | `void` | `obj:threadedUpdatePeriodic()` |
| _NV_threadedUpdatePeriodic | _NV_threadedUpdatePeriodic | `` | `void` | `obj:_NV_threadedUpdatePeriodic()` |
| pathExists | pathExists | `v: Vector3` | `boolean` | `obj:pathExists(v)` |
| weatherUpdate | weatherUpdate | `_a1: number` | `void` | `obj:weatherUpdate(_a1)` |
| _NV_weatherUpdate | _NV_weatherUpdate | `_a1: number` | `void` | `obj:_NV_weatherUpdate(_a1)` |
| stealthUpdate | stealthUpdate | `_time: number` | `void` | `obj:stealthUpdate(_time)` |
| lineOfSightCheck | lineOfSightCheck | `` | `number` | `obj:lineOfSightCheck()` |
| getPerceptionMult | getPerceptionMult | `` | `number` | `obj:getPerceptionMult()` |
| isWithThePlayer | isWithThePlayer | `` | `boolean` | `obj:isWithThePlayer()` |
| notifyICanSeeYouSneaking | notifyICanSeeYouSneaking | `maybeProgress01: number` | `void` | `obj:notifyICanSeeYouSneaking(maybeProgress01)` |
| isItSafeToGetUp | isItSafeToGetUp | `` | `boolean` | `obj:isItSafeToGetUp()` |
| separateIntoMyOwnSquad | separateIntoMyOwnSquad | `permanent: boolean` | `Platoon` | `obj:separateIntoMyOwnSquad(permanent)` |
| dropGearOnDeath | dropGearOnDeath | `vampiricDeath: boolean` | `void` | `obj:dropGearOnDeath(vampiricDeath)` |
| isItOkForMeToLoot | isItOkForMeToLoot | `` | `boolean` | `obj:isItOkForMeToLoot()` |
| _NV_isItOkForMeToLoot | _NV_isItOkForMeToLoot | `` | `boolean` | `obj:_NV_isItOkForMeToLoot()` |
| ImStealingDoYouNotice | ImStealingDoYouNotice | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| _NV_ImStealingDoYouNotice | _NV_ImStealingDoYouNotice | `` | `boolean` | `obj:_NV_ImStealingDoYouNotice()` |
| getFencingSuccessChance | getFencingSuccessChance | `` | `number` | `obj:getFencingSuccessChance()` |
| stolenGoodsDetectionCheck | stolenGoodsDetectionCheck | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| _NV_stolenGoodsDetectionCheck | _NV_stolenGoodsDetectionCheck | `` | `boolean` | `obj:_NV_stolenGoodsDetectionCheck()` |
| sellingUniformDetectionCheck | sellingUniformDetectionCheck | `` | `boolean` | `obj:sellingUniformDetectionCheck()` |
| _NV_sellingUniformDetectionCheck | _NV_sellingUniformDetectionCheck | `` | `boolean` | `obj:_NV_sellingUniformDetectionCheck()` |
| smugglingTradeCheck | smugglingTradeCheck | `` | `YesNoMaybe` | `obj:smugglingTradeCheck()` |
| _NV_smugglingTradeCheck | _NV_smugglingTradeCheck | `` | `YesNoMaybe` | `obj:_NV_smugglingTradeCheck()` |
| getStealingSuccessChance | getStealingSuccessChance | `` | `number` | `obj:getStealingSuccessChance()` |
| getCurrentWeatherAffectStatus | getCurrentWeatherAffectStatus | `` | `integer` | `obj:getCurrentWeatherAffectStatus()` |
| getCurrentWeatherAffectStrength | getCurrentWeatherAffectStrength | `` | `number` | `obj:getCurrentWeatherAffectStrength()` |
| getWaterLevel | getWaterLevel | `` | `integer` | `obj:getWaterLevel()` |
| setTerrainHeightPosition | setTerrainHeightPosition | `height: number` | `void` | `obj:setTerrainHeightPosition(height)` |
| getTerrainHeightPosition | getTerrainHeightPosition | `` | `number` | `obj:getTerrainHeightPosition()` |
| setDisguiseMessage | setDisguiseMessage | `msg: integer` | `void` | `obj:setDisguiseMessage(msg)` |
| uniqueStateUpdate | uniqueStateUpdate | `` | `void` | `obj:uniqueStateUpdate()` |
| foodUpdate | foodUpdate | `` | `void` | `obj:foodUpdate()` |
| _NV_foodUpdate | _NV_foodUpdate | `` | `void` | `obj:_NV_foodUpdate()` |
| eatItem | eatItem | `` | `boolean` | `obj:eatItem()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| loadFromSerialisePostCreationStage | loadFromSerialisePostCreationStage | `` | `void` | `obj:loadFromSerialisePostCreationStage()` |
| _NV_loadFromSerialisePostCreationStage | _NV_loadFromSerialisePostCreationStage | `` | `void` | `obj:_NV_loadFromSerialisePostCreationStage()` |
| setupInventorySections | setupInventorySections | `` | `boolean` | `obj:setupInventorySections()` |
| _NV_setupInventorySections | _NV_setupInventorySections | `` | `boolean` | `obj:_NV_setupInventorySections()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| _getRawPosition | _getRawPosition | `` | `Vector3` | `obj:_getRawPosition()` |
| getRawEntityPosition | getRawEntityPosition | `` | `Vector3` | `obj:getRawEntityPosition()` |
| getMovementSpeed | getMovementSpeed | `` | `number` | `obj:getMovementSpeed()` |
| _NV_getMovementSpeed | _NV_getMovementSpeed | `` | `number` | `obj:_NV_getMovementSpeed()` |
| getMovementSpeedOrders | getMovementSpeedOrders | `` | `integer` | `obj:getMovementSpeedOrders()` |
| _NV_getMovementSpeedOrders | _NV_getMovementSpeedOrders | `` | `integer` | `obj:_NV_getMovementSpeedOrders()` |
| getMovementDirection | getMovementDirection | `` | `Vector3` | `obj:getMovementDirection()` |
| _NV_getMovementDirection | _NV_getMovementDirection | `` | `Vector3` | `obj:_NV_getMovementDirection()` |
| isPhysical | isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| switchLights | switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| isDisabled | isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| setInsideTownWalls | setInsideTownWalls | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| _NV_setInsideTownWalls | _NV_setInsideTownWalls | `s: integer` | `void` | `obj:_NV_setInsideTownWalls(s)` |
| sheatheWeapon | sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| select | select | `` | `void` | `obj:select()` |
| _NV_select | _NV_select | `` | `void` | `obj:_NV_select()` |
| unselect | unselect | `` | `void` | `obj:unselect()` |
| _NV_unselect | _NV_unselect | `` | `void` | `obj:_NV_unselect()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| say_WithARepeatLimiter | say_WithARepeatLimiter | `s: string` | `void` | `obj:say_WithARepeatLimiter(s)` |
| _NV_say_WithARepeatLimiter | _NV_say_WithARepeatLimiter | `s: string` | `void` | `obj:_NV_say_WithARepeatLimiter(s)` |
| say | say | `s: string` | `void` | `obj:say(s)` |
| _NV_say | _NV_say | `s: string` | `void` | `obj:_NV_say(s)` |
| isInventoryVisible | isInventoryVisible | `` | `boolean` | `obj:isInventoryVisible()` |
| _NV_isInventoryVisible | _NV_isInventoryVisible | `` | `boolean` | `obj:_NV_isInventoryVisible()` |
| giveItem | giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| _NV_giveItem | _NV_giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_giveItem(dropOnFail, destroyOnFail)` |
| hasRoomForItem | hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| hasItem | hasItem | `` | `boolean` | `obj:hasItem()` |
| _NV_hasItem | _NV_hasItem | `` | `boolean` | `obj:_NV_hasItem()` |
| hasAmmoFor | hasAmmoFor | `` | `boolean` | `obj:hasAmmoFor()` |
| _NV_hasAmmoFor | _NV_hasAmmoFor | `` | `boolean` | `obj:_NV_hasAmmoFor()` |
| getNumFoodItems | getNumFoodItems | `` | `integer` | `obj:getNumFoodItems()` |
| _NV_getNumFoodItems | _NV_getNumFoodItems | `` | `integer` | `obj:_NV_getNumFoodItems()` |
| hasSimilarItem | hasSimilarItem | `ty: integer` | `boolean` | `obj:hasSimilarItem(ty)` |
| _NV_hasSimilarItem | _NV_hasSimilarItem | `ty: integer` | `boolean` | `obj:_NV_hasSimilarItem(ty)` |
| ifImASmithShouldIDitchMyBackWeapon | ifImASmithShouldIDitchMyBackWeapon | `` | `boolean` | `obj:ifImASmithShouldIDitchMyBackWeapon()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| hasABackpackOn | hasABackpackOn | `` | `ContainerItem` | `obj:hasABackpackOn()` |
| isATrader | isATrader | `` | `boolean` | `obj:isATrader()` |
| isFemale | isFemale | `` | `boolean` | `obj:isFemale()` |
| isFleeing | isFleeing | `` | `boolean` | `obj:isFleeing()` |
| createInventoryLayout | createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| getStealthKOChance | getStealthKOChance | `factors: boolean` | `number` | `obj:getStealthKOChance(factors)` |
| getKidnappingChance | getKidnappingChance | `` | `number` | `obj:getKidnappingChance()` |
| getKidnappingEscapeChance_skill | getKidnappingEscapeChance_skill | `` | `number` | `obj:getKidnappingEscapeChance_skill()` |
| getKidnappingEscapeChance_strength | getKidnappingEscapeChance_strength | `` | `number` | `obj:getKidnappingEscapeChance_strength()` |
| shouldIHelpThisGuy | shouldIHelpThisGuy | `` | `boolean` | `obj:shouldIHelpThisGuy()` |
| shouldIScrewThisGuyOver | shouldIScrewThisGuyOver | `` | `boolean` | `obj:shouldIScrewThisGuyOver()` |
| ILoveThisGuyBecauseOfStuffThatHappened | ILoveThisGuyBecauseOfStuffThatHappened | `` | `boolean` | `obj:ILoveThisGuyBecauseOfStuffThatHappened()` |
| IHateThisGuyBecauseOfStuffThatHappened | IHateThisGuyBecauseOfStuffThatHappened | `` | `boolean` | `obj:IHateThisGuyBecauseOfStuffThatHappened()` |
| getRoughLevel | getRoughLevel | `` | `integer` | `obj:getRoughLevel()` |
| setStandingOrder | setStandingOrder | `orderID: integer, on: boolean` | `void` | `obj:setStandingOrder(orderID, on)` |
| _NV_setStandingOrder | _NV_setStandingOrder | `orderID: integer, on: boolean` | `void` | `obj:_NV_setStandingOrder(orderID, on)` |
| getStandingOrder | getStandingOrder | `orderID: integer` | `boolean` | `obj:getStandingOrder(orderID)` |
| setStealthMode | setStealthMode | `on: boolean` | `void` | `obj:setStealthMode(on)` |
| isStealthMode | isStealthMode | `` | `boolean` | `obj:isStealthMode()` |
| isStealthModeOrCrawling | isStealthModeOrCrawling | `` | `boolean` | `obj:isStealthModeOrCrawling()` |
| declareDead | declareDead | `` | `void` | `obj:declareDead()` |
| updateGUIStatsDetails | updateGUIStatsDetails | `name: string, statId: integer` | `void` | `obj:updateGUIStatsDetails(name, statId)` |
| _printRaceXPBonusLine | _printRaceXPBonusLine | `s: integer` | `void` | `obj:_printRaceXPBonusLine(s)` |
| addGoal | addGoal | `t: integer` | `void` | `obj:addGoal(t)` |
| addJob | addJob | `t: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addJob(t, shift, addDontClear, location)` |
| removeJob | removeJob | `t: integer` | `void` | `obj:removeJob(t)` |
| removePermajob | removePermajob | `t: integer` | `void` | `obj:removePermajob(t)` |
| clearPermajobs | clearPermajobs | `` | `void` | `obj:clearPermajobs()` |
| movePermajob | movePermajob | `taskIdx: integer, targetIdx: integer` | `void` | `obj:movePermajob(taskIdx, targetIdx)` |
| getPermajob | getPermajob | `slot: integer` | `integer` | `obj:getPermajob(slot)` |
| getPermajobData | getPermajobData | `slot: integer` | `Tasker` | `obj:getPermajobData(slot)` |
| getPermajobCount | getPermajobCount | `` | `integer` | `obj:getPermajobCount()` |
| addOrder | addOrder | `t: integer, shift: boolean, clear: boolean, location: Vector3` | `void` | `obj:addOrder(t, shift, clear, location)` |
| updateLastTask | updateLastTask | `t: integer, location: Vector3` | `void` | `obj:updateLastTask(t, location)` |
| _NV_updateLastTask | _NV_updateLastTask | `t: integer, location: Vector3` | `void` | `obj:_NV_updateLastTask(t, location)` |
| playerMoveOrderDefault | playerMoveOrderDefault | `location: Vector3` | `void` | `obj:playerMoveOrderDefault(location)` |
| _NV_playerMoveOrderDefault | _NV_playerMoveOrderDefault | `location: Vector3` | `void` | `obj:_NV_playerMoveOrderDefault(location)` |
| endCombatMode | endCombatMode | `` | `void` | `obj:endCombatMode()` |
| getTotalRelativeStrengthOfAttackers | getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _NV_getTotalRelativeStrengthOfAttackers | _NV_getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:_NV_getTotalRelativeStrengthOfAttackers()` |
| canGoIndoors | canGoIndoors | `` | `boolean` | `obj:canGoIndoors()` |
| _NV_canGoIndoors | _NV_canGoIndoors | `` | `boolean` | `obj:_NV_canGoIndoors()` |
| isIndoorsRagdoll | isIndoorsRagdoll | `` | `boolean` | `obj:isIndoorsRagdoll()` |
| _NV_isIndoorsRagdoll | _NV_isIndoorsRagdoll | `` | `boolean` | `obj:_NV_isIndoorsRagdoll()` |
| destinationIndoors | destinationIndoors | `` | `hand` | `obj:destinationIndoors()` |
| destinationInsideWalls | destinationInsideWalls | `` | `integer` | `obj:destinationInsideWalls()` |
| getIntendedAggression | getIntendedAggression | `` | `number` | `obj:getIntendedAggression()` |
| _NV_getIntendedAggression | _NV_getIntendedAggression | `` | `number` | `obj:_NV_getIntendedAggression()` |
| getPositionBip01 | getPositionBip01 | `` | `Vector3` | `obj:getPositionBip01()` |
| amInsideTownWalls | amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |
| _NV_setName | _NV_setName | `name: string` | `void` | `obj:_NV_setName(name)` |
| setNameTagVisible | setNameTagVisible | `value: boolean` | `void` | `obj:setNameTagVisible(value)` |
| ragdollMode | ragdollMode | `on: boolean, part: integer` | `void` | `obj:ragdollMode(on, part)` |
| isRagdoll | isRagdoll | `` | `boolean` | `obj:isRagdoll()` |
| isDown | isDown | `` | `boolean` | `obj:isDown()` |
| getRagdollPhysicsRootPos | getRagdollPhysicsRootPos | `` | `Vector3` | `obj:getRagdollPhysicsRootPos()` |
| amSomeoneWhoNeedsToEatToLive | amSomeoneWhoNeedsToEatToLive | `` | `boolean` | `obj:amSomeoneWhoNeedsToEatToLive()` |
| _NV_amSomeoneWhoNeedsToEatToLive | _NV_amSomeoneWhoNeedsToEatToLive | `` | `boolean` | `obj:_NV_amSomeoneWhoNeedsToEatToLive()` |
| getMagicHungerSetting | getMagicHungerSetting | `` | `number` | `obj:getMagicHungerSetting()` |
| _NV_getMagicHungerSetting | _NV_getMagicHungerSetting | `` | `number` | `obj:_NV_getMagicHungerSetting()` |
| wantsToEatNow | wantsToEatNow | `` | `boolean` | `obj:wantsToEatNow()` |
| isKidnapped | isKidnapped | `` | `boolean` | `obj:isKidnapped()` |
| _NV_isKidnapped | _NV_isKidnapped | `` | `boolean` | `obj:_NV_isKidnapped()` |
| isLiterallyUnconciousNotPretending | isLiterallyUnconciousNotPretending | `` | `boolean` | `obj:isLiterallyUnconciousNotPretending()` |
| _NV_isLiterallyUnconciousNotPretending | _NV_isLiterallyUnconciousNotPretending | `` | `boolean` | `obj:_NV_isLiterallyUnconciousNotPretending()` |
| isUnconcious | isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| isCrippled | isCrippled | `` | `boolean` | `obj:isCrippled()` |
| _NV_isCrippled | _NV_isCrippled | `` | `boolean` | `obj:_NV_isCrippled()` |
| getProneState | getProneState | `` | `integer` | `obj:getProneState()` |
| _NV_getProneState | _NV_getProneState | `` | `integer` | `obj:_NV_getProneState()` |
| setProneState | setProneState | `p: integer` | `void` | `obj:setProneState(p)` |
| _NV_setProneState | _NV_setProneState | `p: integer` | `void` | `obj:_NV_setProneState(p)` |
| _killRagdoll | _killRagdoll | `doItNow: boolean` | `void` | `obj:_killRagdoll(doItNow)` |
| giveBirth | giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:giveBirth(position, rotation)` |
| _NV_giveBirth | _NV_giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:_NV_giveBirth(position, rotation)` |
| setupAI | setupAI | `` | `void` | `obj:setupAI()` |
| clearAllAIGoals | clearAllAIGoals | `` | `void` | `obj:clearAllAIGoals()` |
| setupPlatoonAI | setupPlatoonAI | `` | `void` | `obj:setupPlatoonAI()` |
| setAppearanceData | setAppearanceData | `` | `void` | `obj:setAppearanceData()` |
| getAppearanceData | getAppearanceData | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| setDestination | setDestination | `pos: Vector3, shift: boolean` | `void` | `obj:setDestination(pos, shift)` |
| sendDialogEventOverride | sendDialogEventOverride | `what: integer, forceRepeat: boolean` | `boolean` | `obj:sendDialogEventOverride(what, forceRepeat)` |
| sendDialogEvent | sendDialogEvent | `what: integer` | `boolean` | `obj:sendDialogEvent(what)` |
| sayALine | sayALine | `line: string, force: boolean` | `void` | `obj:sayALine(line, force)` |
| hasDialogue | hasDialogue | `` | `boolean` | `obj:hasDialogue()` |
| willTalkToEnemies | willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| relocationTeleport | relocationTeleport | `moveBy: Vector3` | `void` | `obj:relocationTeleport(moveBy)` |
| teleportVisuallyOnly | teleportVisuallyOnly | `to: Vector3, rot: Quaternion` | `void` | `obj:teleportVisuallyOnly(to, rot)` |
| teleportFromAnimation | teleportFromAnimation | `` | `void` | `obj:teleportFromAnimation()` |
| attackTarget | attackTarget | `` | `void` | `obj:attackTarget()` |
| notifyTheCampaignOfAnAttack | notifyTheCampaignOfAnAttack | `` | `void` | `obj:notifyTheCampaignOfAnAttack()` |
| iShouldntAggravateThisTarget | iShouldntAggravateThisTarget | `` | `boolean` | `obj:iShouldntAggravateThisTarget()` |
| sendMessage | sendMessage | `message: integer` | `void` | `obj:sendMessage(message)` |
| attackingYou | attackingYou | `so: boolean, doAwarenessCheck: boolean` | `void` | `obj:attackingYou(so, doAwarenessCheck)` |
| gettingEaten | gettingEaten | `amount: number` | `boolean` | `obj:gettingEaten(amount)` |
| _NV_gettingEaten | _NV_gettingEaten | `amount: number` | `boolean` | `obj:_NV_gettingEaten(amount)` |
| getAttackOriginationDirection | getAttackOriginationDirection | `` | `integer` | `obj:getAttackOriginationDirection()` |
| stumbleState | stumbleState | `` | `boolean` | `obj:stumbleState()` |
| setAge | setAge | `f: number` | `void` | `obj:setAge(f)` |
| _NV_setAge | _NV_setAge | `f: number` | `void` | `obj:_NV_setAge(f)` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| getAge | getAge | `` | `number` | `obj:getAge()` |
| _NV_getAge | _NV_getAge | `` | `number` | `obj:_NV_getAge()` |
| getAge0to1 | getAge0to1 | `` | `number` | `obj:getAge0to1()` |
| _NV_getAge0to1 | _NV_getAge0to1 | `` | `number` | `obj:_NV_getAge0to1()` |
| getAgeString | getAgeString | `` | `string` | `obj:getAgeString()` |
| _NV_getAgeString | _NV_getAgeString | `` | `string` | `obj:_NV_getAgeString()` |
| getAgeInverse | getAgeInverse | `` | `number` | `obj:getAgeInverse()` |
| _NV_getAgeInverse | _NV_getAgeInverse | `` | `number` | `obj:_NV_getAgeInverse()` |
| reThinkCurrentAIAction | reThinkCurrentAIAction | `` | `void` | `obj:reThinkCurrentAIAction()` |
| getBody | getBody | `` | `CharBody` | `obj:getBody()` |
| getCombatClass | getCombatClass | `` | `CombatClass` | `obj:getCombatClass()` |
| getStats | getStats | `` | `CharStats` | `obj:getStats()` |
| getMedical | getMedical | `` | `MedicalSystem` | `obj:getMedical()` |
| getOwnerships | getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| getAI | getAI | `` | `lightuserdata` | `obj:getAI()` |
| getAttackTarget | getAttackTarget | `` | `hand` | `obj:getAttackTarget()` |
| isInCombatMode | isInCombatMode | `melee: boolean, ranged: boolean` | `boolean` | `obj:isInCombatMode(melee, ranged)` |
| isInRangedCombatMode | isInRangedCombatMode | `` | `boolean` | `obj:isInRangedCombatMode()` |
| isLiterallyUnderMeleeAttackRightNowForSure | isLiterallyUnderMeleeAttackRightNowForSure | `` | `boolean` | `obj:isLiterallyUnderMeleeAttackRightNowForSure()` |
| _isLiterallyUnderMeleeAttackRightNowForSure_update | _isLiterallyUnderMeleeAttackRightNowForSure_update | `` | `void` | `obj:_isLiterallyUnderMeleeAttackRightNowForSure_update()` |
| conglomerateTagsFor | conglomerateTagsFor | `` | `integer` | `obj:conglomerateTagsFor()` |
| isPrisonerFreeToGo | isPrisonerFreeToGo | `` | `boolean` | `obj:isPrisonerFreeToGo()` |
| clearTempEnemyStatus | clearTempEnemyStatus | `` | `void` | `obj:clearTempEnemyStatus()` |
| clearAllTempEnemyStatuses | clearAllTempEnemyStatuses | `tag: integer` | `void` | `obj:clearAllTempEnemyStatuses(tag)` |
| lastSeenInHoursAgo | lastSeenInHoursAgo | `` | `number` | `obj:lastSeenInHoursAgo()` |
| haveMetBefore | haveMetBefore | `` | `boolean` | `obj:haveMetBefore()` |
| getIDForMemoryTagging | getIDForMemoryTagging | `` | `hand` | `obj:getIDForMemoryTagging()` |
| getMovement | getMovement | `` | `CharMovement` | `obj:getMovement()` |
| lookatPosition | lookatPosition | `v: Vector3, fullbodyFacing: boolean` | `void` | `obj:lookatPosition(v, fullbodyFacing)` |
| _NV_lookatPosition | _NV_lookatPosition | `v: Vector3, fullbodyFacing: boolean` | `void` | `obj:_NV_lookatPosition(v, fullbodyFacing)` |
| areYouGonnaGetMe | areYouGonnaGetMe | `` | `boolean` | `obj:areYouGonnaGetMe()` |
| getAllAttackersCount | getAllAttackersCount | `` | `integer` | `obj:getAllAttackersCount()` |
| getRace | getRace | `` | `RaceData` | `obj:getRace()` |
| _NV_getRace | _NV_getRace | `` | `RaceData` | `obj:_NV_getRace()` |
| setRace | setRace | `` | `void` | `obj:setRace()` |
| _NV_setRace | _NV_setRace | `` | `void` | `obj:_NV_setRace()` |
| getRadius | getRadius | `` | `number` | `obj:getRadius()` |
| isPlayerCharacter | isPlayerCharacter | `` | `boolean` | `obj:isPlayerCharacter()` |
| checkPlayerOrderForProblems | checkPlayerOrderForProblems | `t: integer` | `boolean` | `obj:checkPlayerOrderForProblems(t)` |
| getTotalCarryWeight | getTotalCarryWeight | `` | `number` | `obj:getTotalCarryWeight()` |
| getCurrentWeapon | getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| getRangedWeapon | getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| _NV_getRangedWeapon | _NV_getRangedWeapon | `` | `Crossbow` | `obj:_NV_getRangedWeapon()` |
| drawWeapon | drawWeapon | `_a2: string` | `boolean` | `obj:drawWeapon(_a2)` |
| getUpperBodyArmour | getUpperBodyArmour | `` | `Item` | `obj:getUpperBodyArmour()` |
| getLowerBodyArmour | getLowerBodyArmour | `` | `Item` | `obj:getLowerBodyArmour()` |
| isInjured | isInjured | `robot: boolean` | `boolean` | `obj:isInjured(robot)` |
| shouldUseRangedWeapons | shouldUseRangedWeapons | `` | `boolean` | `obj:shouldUseRangedWeapons()` |
| getBoneWorldPosition | getBoneWorldPosition | `name: string` | `Vector3` | `obj:getBoneWorldPosition(name)` |
| getAppearance | getAppearance | `` | `AppearanceBase` | `obj:getAppearance()` |
| _setPlatoon | _setPlatoon | `idnum: integer` | `void` | `obj:_setPlatoon(idnum)` |
| getPlatoon | getPlatoon | `` | `ActivePlatoon` | `obj:getPlatoon()` |
| hasPlatoon | hasPlatoon | `` | `boolean` | `obj:hasPlatoon()` |
| isInAPersistentPlatoon | isInAPersistentPlatoon | `` | `boolean` | `obj:isInAPersistentPlatoon()` |
| getBlackboard | getBlackboard | `` | `lightuserdata` | `obj:getBlackboard()` |
| getSquadLeader | getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getOrdersReciever | getOrdersReciever | `` | `lightuserdata` | `obj:getOrdersReciever()` |
| preventRagdollMode | preventRagdollMode | `` | `boolean` | `obj:preventRagdollMode()` |
| setPrisonMode | setPrisonMode | `on: boolean` | `void` | `obj:setPrisonMode(on)` |
| setBedMode | setBedMode | `on: boolean` | `void` | `obj:setBedMode(on)` |
| setSlaveAIJob | setSlaveAIJob | `on: boolean` | `void` | `obj:setSlaveAIJob(on)` |
| isChainedMode | isChainedMode | `` | `boolean` | `obj:isChainedMode()` |
| getChainedModeShackles | getChainedModeShackles | `` | `LockedArmour` | `obj:getChainedModeShackles()` |
| getMySlaveOwner | getMySlaveOwner | `` | `hand` | `obj:getMySlaveOwner()` |
| isSlave | isSlave | `` | `integer` | `obj:isSlave()` |
| isMySlave | isMySlave | `` | `boolean` | `obj:isMySlave()` |
| isMyFactionsSlave | isMyFactionsSlave | `` | `boolean` | `obj:isMyFactionsSlave()` |
| isHeadShaven | isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| _NV_isHeadShaven | _NV_isHeadShaven | `` | `boolean` | `obj:_NV_isHeadShaven()` |
| runSlaveAnim | runSlaveAnim | `anim: string, speed: number, sync: number` | `void` | `obj:runSlaveAnim(anim, speed, sync)` |
| endSlaveAnim | endSlaveAnim | `anim: string` | `void` | `obj:endSlaveAnim(anim)` |
| updatePortraitGUIState | updatePortraitGUIState | `` | `void` | `obj:updatePortraitGUIState()` |
| pickupObject | pickupObject | `` | `void` | `obj:pickupObject()` |
| getPickedUp | getPickedUp | `` | `void` | `obj:getPickedUp()` |
| slaveAttachToBoneMode | slaveAttachToBoneMode | `bone: string` | `void` | `obj:slaveAttachToBoneMode(bone)` |
| isDead | isDead | `` | `boolean` | `obj:isDead()` |
| isBeingCarried | isBeingCarried | `` | `boolean` | `obj:isBeingCarried()` |
| getCarryingObject | getCarryingObject | `` | `hand` | `obj:getCarryingObject()` |
| chooseCarryObjectLeftOrRight | chooseCarryObjectLeftOrRight | `` | `void` | `obj:chooseCarryObjectLeftOrRight()` |
| dropCarriedObject | dropCarriedObject | `ragdollHim: boolean, removeOnly: boolean` | `void` | `obj:dropCarriedObject(ragdollHim, removeOnly)` |
| getDropped | getDropped | `ragdollHim: boolean, hull: boolean` | `void` | `obj:getDropped(ragdollHim, hull)` |
| getDiplomacyMultiplier | getDiplomacyMultiplier | `` | `number` | `obj:getDiplomacyMultiplier()` |
| isEnemy | isEnemy | `factorInDisguises: boolean` | `boolean` | `obj:isEnemy(factorInDisguises)` |
| _NV_isEnemy | _NV_isEnemy | `factorInDisguises: boolean` | `boolean` | `obj:_NV_isEnemy(factorInDisguises)` |
| isAlly | isAlly | `factorInDisguises: boolean` | `boolean` | `obj:isAlly(factorInDisguises)` |
| _NV_isAlly | _NV_isAlly | `factorInDisguises: boolean` | `boolean` | `obj:_NV_isAlly(factorInDisguises)` |
| getDefaultTaskRepertoireEnum | getDefaultTaskRepertoireEnum | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| _NV_getDefaultTaskRepertoireEnum | _NV_getDefaultTaskRepertoireEnum | `` | `integer` | `obj:_NV_getDefaultTaskRepertoireEnum()` |
| getAnimationClass | getAnimationClass | `` | `lightuserdata` | `obj:getAnimationClass()` |
| getPredictedPosition | getPredictedPosition | `secondsInFuture: number` | `Vector3` | `obj:getPredictedPosition(secondsInFuture)` |
| carryModeT | carryModeT | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:carryModeT(on, makeRagdoll, makeHull)` |
| _carryMode | _carryMode | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:_carryMode(on, makeRagdoll, makeHull)` |
| recalculateTotalEquipmentSkillBonus | recalculateTotalEquipmentSkillBonus | `` | `void` | `obj:recalculateTotalEquipmentSkillBonus()` |
| setupAudio | setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| audioEvent | audioEvent | `name: string, range: integer` | `boolean` | `obj:audioEvent(name, range)` |
| setGroundType | setGroundType | `t: integer` | `void` | `obj:setGroundType(t)` |
| getGroundType | getGroundType | `` | `integer` | `obj:getGroundType()` |
| calculateMainArmourType | calculateMainArmourType | `` | `void` | `obj:calculateMainArmourType()` |
| getMainArmourType | getMainArmourType | `` | `integer` | `obj:getMainArmourType()` |
| wearingUniformOf | wearingUniformOf | `` | `boolean` | `obj:wearingUniformOf()` |
| _NV_wearingUniformOf | _NV_wearingUniformOf | `` | `boolean` | `obj:_NV_wearingUniformOf()` |
| getUniformColorScheme | getUniformColorScheme | `` | `GameData` | `obj:getUniformColorScheme()` |
| canTakePlayerOrdersAtThisTime | canTakePlayerOrdersAtThisTime | `` | `boolean` | `obj:canTakePlayerOrdersAtThisTime()` |
| startEffect | startEffect | `` | `boolean` | `obj:startEffect()` |
| stopEffect | stopEffect | `` | `boolean` | `obj:stopEffect()` |
| stopAllEffects | stopAllEffects | `` | `void` | `obj:stopAllEffects()` |
| notifyEffect | notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| equipItem | equipItem | `sectionName: string` | `void` | `obj:equipItem(sectionName)` |
| _NV_equipItem | _NV_equipItem | `sectionName: string` | `void` | `obj:_NV_equipItem(sectionName)` |
| unequipItem | unequipItem | `sectionName: string` | `void` | `obj:unequipItem(sectionName)` |
| _NV_unequipItem | _NV_unequipItem | `sectionName: string` | `void` | `obj:_NV_unequipItem(sectionName)` |
| validateInventorySections | validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| _NV_validateInventorySections | _NV_validateInventorySections | `` | `void` | `obj:_NV_validateInventorySections()` |
| processCharacterLoadTimeMessages | processCharacterLoadTimeMessages | `` | `void` | `obj:processCharacterLoadTimeMessages()` |
| wantsPathfinderActive | wantsPathfinderActive | `` | `boolean` | `obj:wantsPathfinderActive()` |
| createAnimationClass | createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| calculateDestinationState | calculateDestinationState | `v: Vector3` | `void` | `obj:calculateDestinationState(v)` |
| generateWeapon | generateWeapon | `` | `Item` | `obj:generateWeapon()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| createComponents | createComponents | `` | `boolean` | `obj:createComponents()` |
| loadUnloadCheck | loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| updateStateBroadcast | updateStateBroadcast | `time: number` | `void` | `obj:updateStateBroadcast(time)` |
| setEffectBT | setEffectBT | `active: boolean` | `void` | `obj:setEffectBT(active)` |
| postRagdollCallback | postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| _NV_postRagdollCallback | _NV_postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:_NV_postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| _NV_reCalculateNaturalWeapon | _NV_reCalculateNaturalWeapon | `` | `void` | `obj:_NV_reCalculateNaturalWeapon()` |
| rememberCharacter | rememberCharacter | `str: string, arg3: boolean` | `void` | `obj:rememberCharacter(str, arg3)` |
| setHandle | setHandle | `` | `void` | `obj:setHandle()` |
| _NV_setHandle | _NV_setHandle | `` | `void` | `obj:_NV_setHandle()` |
| isIndoors | isIndoors | `` | `hand` | `obj:isIndoors()` |
| _NV_isIndoors | _NV_isIndoors | `` | `hand` | `obj:_NV_isIndoors()` |
| isStandingOnBuilding | isStandingOnBuilding | `` | `hand` | `obj:isStandingOnBuilding()` |
| _NV_isStandingOnBuilding | _NV_isStandingOnBuilding | `` | `hand` | `obj:_NV_isStandingOnBuilding()` |
| notifyIndoors | notifyIndoors | `` | `void` | `obj:notifyIndoors()` |
| _NV_notifyIndoors | _NV_notifyIndoors | `` | `void` | `obj:_NV_notifyIndoors()` |
| setDestinationIndoors | setDestinationIndoors | `` | `void` | `obj:setDestinationIndoors()` |
| getAudioObject | getAudioObject | `` | `integer` | `obj:getAudioObject()` |
| getName | getName | `` | `string` | `obj:getName()` |
| _NV_getName | _NV_getName | `` | `string` | `obj:_NV_getName()` |
| changeSlaveOwner | changeSlaveOwner | `` | `void` | `obj:changeSlaveOwner()` |
| teleport | teleport | `moveBy: Vector3, rot: Quaternion` | `void` | `obj:teleport(moveBy, rot)` |
| audioValue | audioValue | `name: string, value: string` | `void` | `obj:audioValue(name, value)` |
| getPermajobName | getPermajobName | `slot: integer` | `string` | `obj:getPermajobName(slot)` |
| getAABB | getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| _NV_getAABB | _NV_getAABB | `` | `lightuserdata` | `obj:_NV_getAABB()` |
| getAllAttackers | getAllAttackers | `` | `void` | `obj:getAllAttackers()` |
| getCharacterMemoryTag | getCharacterMemoryTag | `mem: integer, isLongTerm: boolean` | `boolean` | `obj:getCharacterMemoryTag(mem, isLongTerm)` |
| hitByMeleeAttack | hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| convertCutDirection | convertCutDirection | `cut: integer, from: integer` | `integer` | `obj:convertCutDirection(cut, from)` |
| breakFollowOrderLoop | breakFollowOrderLoop | `` | `boolean` | `obj:breakFollowOrderLoop()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Character` | `obj:_CONSTRUCTOR()` |
| formationUpdateCallback | formationUpdateCallback | `pos: Vector3, heading: Vector3, from: userdata` | `void` | `obj:formationUpdateCallback(pos, heading, from)` |
| serialise | serialise | `offset: userdata` | `GameSaveState` | `obj:serialise(offset)` |
| _NV_serialise | _NV_serialise | `offset: userdata` | `GameSaveState` | `obj:_NV_serialise(offset)` |
| hasItemsFrom | hasItemsFrom | `` | `boolean` | `obj:hasItemsFrom()` |
| _NV_hasItemsFrom | _NV_hasItemsFrom | `` | `boolean` | `obj:_NV_hasItemsFrom()` |
| getLockpickChance | getLockpickChance | `victim: userdata` | `number` | `obj:getLockpickChance(victim)` |
| debugIndicateCharacters | debugIndicateCharacters | `` | `void` | `obj:debugIndicateCharacters()` |
| iShotYou | iShotYou | `poon: userdata, onPurpose: boolean` | `boolean` | `obj:iShotYou(poon, onPurpose)` |
| _startStumble | _startStumble | `dir: integer` | `void` | `obj:_startStumble(dir)` |
| getSquadMissionTarget | getSquadMissionTarget | `` | `hand` | `obj:getSquadMissionTarget()` |
| setChainedMode | setChainedMode | `on: boolean` | `void` | `obj:setChainedMode(on)` |
| _ragdollMode | _ragdollMode | `on: boolean, part: integer` | `boolean` | `obj:_ragdollMode(on, part)` |

## CharacterAnimal
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isAnimal | isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| _NV_isAnimal | _NV_isAnimal | `` | `CharacterAnimal` | `obj:_NV_isAnimal()` |
| createAnimationClass | createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| _NV_createAnimationClass | _NV_createAnimationClass | `` | `void` | `obj:_NV_createAnimationClass()` |
| sheatheWeapon | sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| getCurrentWeapon | getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| _NV_getCurrentWeapon | _NV_getCurrentWeapon | `` | `Weapon` | `obj:_NV_getCurrentWeapon()` |
| getThePreferredWeapon | getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| _NV_getThePreferredWeapon | _NV_getThePreferredWeapon | `` | `Weapon` | `obj:_NV_getThePreferredWeapon()` |
| setupAudio | setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| setAge | setAge | `zeroToOne: number` | `void` | `obj:setAge(zeroToOne)` |
| _NV_setAge | _NV_setAge | `zeroToOne: number` | `void` | `obj:_NV_setAge(zeroToOne)` |
| getAge | getAge | `` | `number` | `obj:getAge()` |
| _NV_getAge | _NV_getAge | `` | `number` | `obj:_NV_getAge()` |
| getAgeInverse | getAgeInverse | `` | `number` | `obj:getAgeInverse()` |
| _NV_getAgeInverse | _NV_getAgeInverse | `` | `number` | `obj:_NV_getAgeInverse()` |
| getAge0to1 | getAge0to1 | `` | `number` | `obj:getAge0to1()` |
| _NV_getAge0to1 | _NV_getAge0to1 | `` | `number` | `obj:_NV_getAge0to1()` |
| getDefaultTaskRepertoireEnum | getDefaultTaskRepertoireEnum | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| _NV_getDefaultTaskRepertoireEnum | _NV_getDefaultTaskRepertoireEnum | `` | `integer` | `obj:_NV_getDefaultTaskRepertoireEnum()` |
| getSmellHuntingThresholdBlood | getSmellHuntingThresholdBlood | `` | `number` | `obj:getSmellHuntingThresholdBlood()` |
| _NV_getSmellHuntingThresholdBlood | _NV_getSmellHuntingThresholdBlood | `` | `number` | `obj:_NV_getSmellHuntingThresholdBlood()` |
| getSmellHuntingThresholdEggs | getSmellHuntingThresholdEggs | `` | `number` | `obj:getSmellHuntingThresholdEggs()` |
| _NV_getSmellHuntingThresholdEggs | _NV_getSmellHuntingThresholdEggs | `` | `number` | `obj:_NV_getSmellHuntingThresholdEggs()` |
| getHPMultiplier | getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| _NV_getHPMultiplier | _NV_getHPMultiplier | `` | `number` | `obj:_NV_getHPMultiplier()` |
| foodUpdate | foodUpdate | `` | `void` | `obj:foodUpdate()` |
| _NV_foodUpdate | _NV_foodUpdate | `` | `void` | `obj:_NV_foodUpdate()` |
| dropItemInMouth | dropItemInMouth | `` | `boolean` | `obj:dropItemInMouth()` |
| getItemInMouth | getItemInMouth | `` | `Item` | `obj:getItemInMouth()` |
| eatItemInMouth | eatItemInMouth | `` | `void` | `obj:eatItemInMouth()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | init | `` | `void` | `obj:init()` |
| _NV_init | _NV_init | `` | `void` | `obj:_NV_init()` |

## CharacterHuman
**Header:** `extern/KenshiLib/Include/kenshi/CharacterHuman.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| weaponInHands | weaponInHands | Weapon | RW | `obj.weaponInHands = <value>` |
| weaponInHandsSheathLocation | weaponInHandsSheathLocation | string | RW | `obj.weaponInHandsSheathLocation = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| sheatheWeapon | sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| getCurrentWeapon | getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| _NV_getCurrentWeapon | _NV_getCurrentWeapon | `` | `Weapon` | `obj:_NV_getCurrentWeapon()` |
| getThePreferredWeapon | getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| _NV_getThePreferredWeapon | _NV_getThePreferredWeapon | `` | `Weapon` | `obj:_NV_getThePreferredWeapon()` |
| getRangedWeapon | getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| _NV_getRangedWeapon | _NV_getRangedWeapon | `` | `Crossbow` | `obj:_NV_getRangedWeapon()` |
| validateInventorySections | validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| _NV_validateInventorySections | _NV_validateInventorySections | `` | `void` | `obj:_NV_validateInventorySections()` |
| setupAudio | setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| shaveHead | shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isHeadShaven | isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| _NV_isHeadShaven | _NV_isHeadShaven | `` | `boolean` | `obj:_NV_isHeadShaven()` |
| createAnimationClass | createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| _NV_createAnimationClass | _NV_createAnimationClass | `` | `void` | `obj:_NV_createAnimationClass()` |
| dropWeaponInHands | dropWeaponInHands | `` | `void` | `obj:dropWeaponInHands()` |
| dropWeaponInHandsFake | dropWeaponInHandsFake | `` | `void` | `obj:dropWeaponInHandsFake()` |
| weatherUpdate | weatherUpdate | `time: number` | `void` | `obj:weatherUpdate(time)` |
| _NV_weatherUpdate | _NV_weatherUpdate | `time: number` | `void` | `obj:_NV_weatherUpdate(time)` |
| leaveSheathEquipped | leaveSheathEquipped | `section: string, ypos: integer` | `void` | `obj:leaveSheathEquipped(section, ypos)` |
| postRagdollCallback | postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| _NV_postRagdollCallback | _NV_postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:_NV_postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| _NV_reCalculateNaturalWeapon | _NV_reCalculateNaturalWeapon | `` | `void` | `obj:_NV_reCalculateNaturalWeapon()` |
| isHuman | isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| _NV_isHuman | _NV_isHuman | `` | `CharacterHuman` | `obj:_NV_isHuman()` |
| drawWeapon | drawWeapon | `lastSection: string` | `boolean` | `obj:drawWeapon(lastSection)` |
| _NV_drawWeapon | _NV_drawWeapon | `lastSection: string` | `boolean` | `obj:_NV_drawWeapon(lastSection)` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| unequipItem | unequipItem | `section: string` | `void` | `obj:unequipItem(section)` |
| _NV_unequipItem | _NV_unequipItem | `section: string` | `void` | `obj:_NV_unequipItem(section)` |

## CharacterInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `CharacterInventoryLayout` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CharacterStatsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| character | character | Character | R | `obj.character` |
| statsSum | statsSum | integer | RW | `obj.statsSum = <value>` |
| statProgress | (lua_Integer | integer | RW | `obj.statProgress = <value>` |
| currentStatIdDescription | currentStatIdDescription | string | RW | `obj.currentStatIdDescription = <value>` |
| attributesDatapanel | attributesDatapanel | DatapanelGUI | R | `obj.attributesDatapanel` |
| skills1Datapanel | skills1Datapanel | DatapanelGUI | R | `obj.skills1Datapanel` |
| skills2Datapanel | skills2Datapanel | DatapanelGUI | R | `obj.skills2Datapanel` |
| skills3Datapanel | skills3Datapanel | DatapanelGUI | R | `obj.skills3Datapanel` |
| skills4Datapanel | skills4Datapanel | DatapanelGUI | R | `obj.skills4Datapanel` |
| statsDatapanel | statsDatapanel | DatapanelGUI | R | `obj.statsDatapanel` |
| description1Datapanel | description1Datapanel | DatapanelGUI | R | `obj.description1Datapanel` |
| description2Datapanel | description2Datapanel | DatapanelGUI | R | `obj.description2Datapanel` |
| autoUpdateMode | autoUpdateMode | boolean | RW | `obj.autoUpdateMode = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| _NV_clear | _NV_clear | `` | `void` | `obj:_NV_clear()` |
| create | create | `` | `void` | `obj:create()` |
| _NV_create | _NV_create | `` | `void` | `obj:_NV_create()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| show | show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| setAutoUpdateMode | setAutoUpdateMode | `on: boolean` | `void` | `obj:setAutoUpdateMode(on)` |
| setupStats | setupStats | `` | `void` | `obj:setupStats()` |
| updateStats | updateStats | `` | `void` | `obj:updateStats()` |
| clearDesctiption | clearDesctiption | `` | `void` | `obj:clearDesctiption()` |
| sumStats | sumStats | `` | `integer` | `obj:sumStats()` |
| getStatsPanel | getStatsPanel | `group: integer` | `DatapanelGUI` | `obj:getStatsPanel(group)` |

## CharacterTradingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterTradingWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| tradingHandler | (void* | lightuserdata | R | `obj.tradingHandler` |
| charactersBox | (void* | lightuserdata | R | `obj.charactersBox` |
| confirmBtn | (void* | lightuserdata | R | `obj.confirmBtn` |
| currentTotalText | (void* | lightuserdata | R | `obj.currentTotalText` |
| selectedCountText | (void* | lightuserdata | R | `obj.selectedCountText` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| show | show | `on: boolean` | `void` | `obj:show(on)` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| update | update | `` | `void` | `obj:update()` |
| close | close | `` | `void` | `obj:close()` |

## CombatClass
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| attackSlots | attackSlots | CombatClass::AttackSlotManager | R | `obj.attackSlots` |
| wantsToBlock | wantsToBlock | boolean | RW | `obj.wantsToBlock = <value>` |
| isStumbleBlocking | isStumbleBlocking | boolean | RW | `obj.isStumbleBlocking = <value>` |
| stumbleTimer | stumbleTimer | number | RW | `obj.stumbleTimer = <value>` |
| whenCanStopStumble | whenCanStopStumble | number | RW | `obj.whenCanStopStumble = <value>` |
| stumbleForce | stumbleForce | number | RW | `obj.stumbleForce = <value>` |
| combatModeActive | combatModeActive | boolean | RW | `obj.combatModeActive = <value>` |
| lastCombatModeTimeStamp | lastCombatModeTimeStamp | number | RW | `obj.lastCombatModeTimeStamp = <value>` |
| _isAttacking | _isAttacking | number | RW | `obj._isAttacking = <value>` |
| inDeadTime | inDeadTime | boolean | RW | `obj.inDeadTime = <value>` |
| deadTimer | deadTimer | number | RW | `obj.deadTimer = <value>` |
| stateTimer | stateTimer | number | RW | `obj.stateTimer = <value>` |
| currentTechnique | currentTechnique | CombatTechniqueData | RW | `obj.currentTechnique = <value>` |
| currentTechniqueHasFinished | currentTechniqueHasFinished | boolean | RW | `obj.currentTechniqueHasFinished = <value>` |
| attackStartPos | attackStartPos | Vector3 | RW | `obj.attackStartPos = <value>` |
| frameTIME | frameTIME | number | RW | `obj.frameTIME = <value>` |
| movement | movement | CharMovement | R | `obj.movement` |
| ai | (void* | lightuserdata | R | `obj.ai` |
| animation | (void* | lightuserdata | R | `obj.animation` |
| me | me | Character | R | `obj.me` |
| stats | stats | CharStats | R | `obj.stats` |
| medical | medical | MedicalSystem | R | `obj.medical` |
| myRadiusX | myRadiusX | number | RW | `obj.myRadiusX = <value>` |
| blockingTarget | blockingTarget | Character | RW | `obj.blockingTarget = <value>` |
| lastIncomingAttackComboSection | lastIncomingAttackComboSection | integer | RW | `obj.lastIncomingAttackComboSection = <value>` |
| calculatedTargetsInAttackZoneThisFrame | calculatedTargetsInAttackZoneThisFrame | boolean | RW | `obj.calculatedTargetsInAttackZoneThisFrame = <value>` |
| combatState | (lua_Integer | integer | RW | `obj.combatState = <value>` |
| nextMove | (lua_Integer | integer | RW | `obj.nextMove = <value>` |
| numEnemiesWaitingForMe1 | numEnemiesWaitingForMe1 | integer | RW | `obj.numEnemiesWaitingForMe1 = <value>` |
| numEnemiesWaitingForMe2 | numEnemiesWaitingForMe2 | integer | RW | `obj.numEnemiesWaitingForMe2 = <value>` |
| waitCountAlternator | waitCountAlternator | boolean | RW | `obj.waitCountAlternator = <value>` |
| currentComboSection | currentComboSection | integer | RW | `obj.currentComboSection = <value>` |
| lastComboSection | lastComboSection | integer | RW | `obj.lastComboSection = <value>` |
| lastSoundIndex | lastSoundIndex | integer | RW | `obj.lastSoundIndex = <value>` |
| techniqueIntegrityCheckTimer | techniqueIntegrityCheckTimer | number | RW | `obj.techniqueIntegrityCheckTimer = <value>` |
| MEI_MIN | MEI_MIN | number | RW | `obj.MEI_MIN = <value>` |
| MEI_MAX | MEI_MAX | number | RW | `obj.MEI_MAX = <value>` |
| MINIMUM_DISTANCE_TO_OTHERS | MINIMUM_DISTANCE_TO_OTHERS | number | RW | `obj.MINIMUM_DISTANCE_TO_OTHERS = <value>` |
| BLOCKING_MEI_DISTANCE_MIN | BLOCKING_MEI_DISTANCE_MIN | number | RW | `obj.BLOCKING_MEI_DISTANCE_MIN = <value>` |
| BLOCKING_MEI_DISTANCE_MAX | BLOCKING_MEI_DISTANCE_MAX | number | RW | `obj.BLOCKING_MEI_DISTANCE_MAX = <value>` |
| currentTarget | currentTarget | Character | RW | `obj.currentTarget = <value>` |
| blockingTargetH | blockingTargetH | hand | RW | `obj.blockingTargetH = <value>` |
| targetsInAttackZone | targetsInAttackZone | lektor<hand> | RW | `obj.targetsInAttackZone = <value>` |
| attackersH | attackersH | lektor<hand> | RW | `obj.attackersH = <value>` |
| threats | threats | lektor<Character*> | RW | `obj.threats = <value>` |
| threatsH | threatsH | lektor<hand> | RW | `obj.threatsH = <value>` |
| notifiedThreats | notifiedThreats | lektor<hand> | RW | `obj.notifiedThreats = <value>` |
| currentTargetHandle | currentTargetHandle | hand | RW | `obj.currentTargetHandle = <value>` |
| stateMap | stateMap | SwordStateMapBinding::MapType | RW | `obj.stateMap = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isAI | isAI | `` | `boolean` | `obj:isAI()` |
| _NV_isAI | _NV_isAI | `` | `boolean` | `obj:_NV_isAI()` |
| go | go | `_frameTime: number` | `void` | `obj:go(_frameTime)` |
| _NV_go | _NV_go | `_frameTime: number` | `void` | `obj:_NV_go(_frameTime)` |
| getCombatState | getCombatState | `` | `integer` | `obj:getCombatState()` |
| getBlockStateEnum | getBlockStateEnum | `` | `integer` | `obj:getBlockStateEnum()` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| _NV_periodicUpdate | _NV_periodicUpdate | `time: number` | `void` | `obj:_NV_periodicUpdate(time)` |
| isStationary | isStationary | `` | `boolean` | `obj:isStationary()` |
| getCurrentTechnique | getCurrentTechnique | `` | `CombatTechniqueData` | `obj:getCurrentTechnique()` |
| getCurrentTechniqueSection | getCurrentTechniqueSection | `` | `integer` | `obj:getCurrentTechniqueSection()` |
| getMeiMin | getMeiMin | `` | `number` | `obj:getMeiMin()` |
| areYouFightingAndInNeedOfHelp | areYouFightingAndInNeedOfHelp | `` | `number` | `obj:areYouFightingAndInNeedOfHelp()` |
| getNumOpponents | getNumOpponents | `` | `integer` | `obj:getNumOpponents()` |
| getTotalRelativeStrengthOfAttackers | getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _isInCombatMode | _isInCombatMode | `` | `boolean` | `obj:_isInCombatMode()` |
| checkForBadHandles | checkForBadHandles | `` | `void` | `obj:checkForBadHandles()` |
| getNumWaitingAttackers | getNumWaitingAttackers | `` | `integer` | `obj:getNumWaitingAttackers()` |
| readyToFinishCombatMode | readyToFinishCombatMode | `` | `boolean` | `obj:readyToFinishCombatMode()` |
| getTimeSinceLastCombatModeInHours | getTimeSinceLastCombatModeInHours | `` | `number` | `obj:getTimeSinceLastCombatModeInHours()` |
| changeState | changeState | `newState: integer, minTime: number` | `void` | `obj:changeState(newState, minTime)` |
| getStateClass | getStateClass | `state: integer` | `lightuserdata` | `obj:getStateClass(state)` |
| _NV_getStateClass | _NV_getStateClass | `state: integer` | `lightuserdata` | `obj:_NV_getStateClass(state)` |
| update | update | `frameTIME: number` | `void` | `obj:update(frameTIME)` |
| _NV_update | _NV_update | `frameTIME: number` | `void` | `obj:_NV_update(frameTIME)` |
| getMeiMax | getMeiMax | `` | `number` | `obj:getMeiMax()` |
| startupState | startupState | `` | `boolean` | `obj:startupState()` |
| _NV_startupState | _NV_startupState | `` | `boolean` | `obj:_NV_startupState()` |
| stumbleState | stumbleState | `` | `void` | `obj:stumbleState()` |
| _isAttackingUpdate | _isAttackingUpdate | `` | `number` | `obj:_isAttackingUpdate()` |
| canBlock | canBlock | `` | `boolean` | `obj:canBlock()` |
| attackState | attackState | `` | `boolean` | `obj:attackState()` |
| _NV_attackState | _NV_attackState | `` | `boolean` | `obj:_NV_attackState()` |
| checkForNeedBlock | checkForNeedBlock | `thresholdMyAttack: number, thresholdIncomingAttack: number` | `boolean` | `obj:checkForNeedBlock(thresholdMyAttack, thresholdIncomingAttack)` |
| setCombatState | setCombatState | `state: integer` | `void` | `obj:setCombatState(state)` |
| initialiseBlock | initialiseBlock | `isStumbling: boolean` | `boolean` | `obj:initialiseBlock(isStumbling)` |
| blockState | blockState | `stumbleBlocking: boolean` | `boolean` | `obj:blockState(stumbleBlocking)` |
| _NV_blockState | _NV_blockState | `stumbleBlocking: boolean` | `boolean` | `obj:_NV_blockState(stumbleBlocking)` |
| blockWaitingState | blockWaitingState | `` | `void` | `obj:blockWaitingState()` |
| attackImpactCheck | attackImpactCheck | `` | `void` | `obj:attackImpactCheck()` |
| calculateTargetsInAttackZone | calculateTargetsInAttackZone | `` | `void` | `obj:calculateTargetsInAttackZone()` |
| getNearestEnemyInAttackZone | getNearestEnemyInAttackZone | `` | `Character` | `obj:getNearestEnemyInAttackZone()` |
| notifyBlockNeeded | notifyBlockNeeded | `` | `void` | `obj:notifyBlockNeeded()` |
| weaponReach | weaponReach | `` | `number` | `obj:weaponReach()` |
| packPtrsToHandles | packPtrsToHandles | `` | `void` | `obj:packPtrsToHandles()` |
| _NV_packPtrsToHandles | _NV_packPtrsToHandles | `` | `void` | `obj:_NV_packPtrsToHandles()` |
| unpackHandlesToPtrs | unpackHandlesToPtrs | `` | `void` | `obj:unpackHandlesToPtrs()` |
| _NV_unpackHandlesToPtrs | _NV_unpackHandlesToPtrs | `` | `void` | `obj:_NV_unpackHandlesToPtrs()` |
| _iHitYouAreYouHit | _iHitYouAreYouHit | `dir: integer` | `integer` | `obj:_iHitYouAreYouHit(dir)` |
| _getHit | _getHit | `dir: integer, stumble: boolean` | `void` | `obj:_getHit(dir, stumble)` |
| _blockHit | _blockHit | `dir: integer` | `void` | `obj:_blockHit(dir)` |
| isAttacking | isAttacking | `` | `number` | `obj:isAttacking()` |
| informOfFreeAttackSlot | informOfFreeAttackSlot | `` | `void` | `obj:informOfFreeAttackSlot()` |
| _NV_informOfFreeAttackSlot | _NV_informOfFreeAttackSlot | `` | `void` | `obj:_NV_informOfFreeAttackSlot()` |
| _getAttackTarget | _getAttackTarget | `` | `hand` | `obj:_getAttackTarget()` |
| isFightingAnAllyOfMine | isFightingAnAllyOfMine | `` | `boolean` | `obj:isFightingAnAllyOfMine()` |
| getAttackers | getAttackers | `` | `lektor<hand>` | `obj:getAttackers()` |
| addAttackerH | addAttackerH | `` | `boolean` | `obj:addAttackerH()` |
| isInAttackerListH | isInAttackerListH | `` | `boolean` | `obj:isInAttackerListH()` |
| removeAttackerH | removeAttackerH | `` | `boolean` | `obj:removeAttackerH()` |
| youDoKnowImAttackingYouRight | youDoKnowImAttackingYouRight | `` | `void` | `obj:youDoKnowImAttackingYouRight()` |
| getAttackAimAdjustmentThreshold | getAttackAimAdjustmentThreshold | `` | `number` | `obj:getAttackAimAdjustmentThreshold()` |
| hasFocusedTarget | hasFocusedTarget | `` | `hand` | `obj:hasFocusedTarget()` |
| _NV_hasFocusedTarget | _NV_hasFocusedTarget | `` | `hand` | `obj:_NV_hasFocusedTarget()` |
| isInAttackZone | isInAttackZone | `` | `boolean` | `obj:isInAttackZone()` |
| assessIncomingAttacks | assessIncomingAttacks | `` | `void` | `obj:assessIncomingAttacks()` |
| calculateCurrentTechniqueSection | calculateCurrentTechniqueSection | `` | `integer|number` | `obj:calculateCurrentTechniqueSection()` |
| getBiggestThreat | getBiggestThreat | `minThreshold: number` | `Character` | `obj:getBiggestThreat(minThreshold)` |
| gotMoreImportantThingsToDoThanFightingYou | gotMoreImportantThingsToDoThanFightingYou | `` | `boolean` | `obj:gotMoreImportantThingsToDoThanFightingYou()` |
| _NV_gotMoreImportantThingsToDoThanFightingYou | _NV_gotMoreImportantThingsToDoThanFightingYou | `` | `boolean` | `obj:_NV_gotMoreImportantThingsToDoThanFightingYou()` |
| setAttackTarget | setAttackTarget | `` | `void` | `obj:setAttackTarget()` |
| setAttackTargetHandle | setAttackTargetHandle | `` | `void` | `obj:setAttackTargetHandle()` |
| lookatTarget | lookatTarget | `` | `void` | `obj:lookatTarget()` |

## CombatMovementController
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| characterCollisions | characterCollisions | unknown | RW | `obj.characterCollisions = <value>` |
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| chaseMode | chaseMode | boolean | RW | `obj.chaseMode = <value>` |
| chaseStateTimer | chaseStateTimer | number | RW | `obj.chaseStateTimer = <value>` |
| hasForcedWP | hasForcedWP | boolean | RW | `obj.hasForcedWP = <value>` |
| forcedWP | forcedWP | Vector3 | RW | `obj.forcedWP = <value>` |
| flockFilterX | flockFilterX | MotionFilter | RW | `obj.flockFilterX = <value>` |
| flockFilterZ | flockFilterZ | MotionFilter | RW | `obj.flockFilterZ = <value>` |
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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| collisionUpdate | collisionUpdate | `time: number` | `void` | `obj:collisionUpdate(time)` |
| areTherePeopleInMyWay | areTherePeopleInMyWay | `` | `boolean` | `obj:areTherePeopleInMyWay()` |
| getUrgentVelocities | getUrgentVelocities | `pos: Vector3, facingDir: Vector3` | `Vector3` | `obj:getUrgentVelocities(pos, facingDir)` |
| checkWeDontCollideWithCharacters | checkWeDontCollideWithCharacters | `pos: Vector3, newpos: Vector3` | `void` | `obj:checkWeDontCollideWithCharacters(pos, newpos)` |
| checkCharacterCollision | checkCharacterCollision | `pos: Vector3, movement: Vector3` | `boolean` | `obj:checkCharacterCollision(pos, movement)` |
| setForcedWP | setForcedWP | `v: Vector3` | `void` | `obj:setForcedWP(v)` |
| disable | disable | `` | `void` | `obj:disable()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CombatTechniqueData
**Header:** `extern/KenshiLib/Include/kenshi/CombatTechniqueData.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasSkillType | hasSkillType | `type: integer` | `boolean` | `obj:hasSkillType(type)` |
| numImpactPoints | numImpactPoints | `` | `integer` | `obj:numImpactPoints()` |
| impactPoint | impactPoint | `i: integer` | `lightuserdata` | `obj:impactPoint(i)` |

## ConstructionState
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isComplete | isComplete | boolean | RW | `obj.isComplete = <value>` |
| isPaused | isPaused | boolean | RW | `obj.isPaused = <value>` |
| isDismantled | isDismantled | boolean | RW | `obj.isDismantled = <value>` |
| constructionProgress | constructionProgress | number | RW | `obj.constructionProgress = <value>` |
| msgDismantleAmount | msgDismantleAmount | number | RW | `obj.msgDismantleAmount = <value>` |
| totalMats | totalMats | number | RW | `obj.totalMats = <value>` |
| buildTimeMult | buildTimeMult | number | RW | `obj.buildTimeMult = <value>` |
| buildersThisFrame | buildersThisFrame | integer | RW | `obj.buildersThisFrame = <value>` |
| pathThreshold | pathThreshold | number | RW | `obj.pathThreshold = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| addMaterials | addMaterials | `` | `void` | `obj:addMaterials()` |
| materialsEmpty | materialsEmpty | `` | `boolean` | `obj:materialsEmpty()` |
| isOverThreshold | isOverThreshold | `` | `boolean` | `obj:isOverThreshold()` |
| getHealthBarProgress | getHealthBarProgress | `` | `number` | `obj:getHealthBarProgress()` |
| getConstructionMaterialProgress | getConstructionMaterialProgress | `` | `number` | `obj:getConstructionMaterialProgress()` |
| getHealthBarActual | getHealthBarActual | `` | `string` | `obj:getHealthBarActual()` |
| getMaterial | getMaterial | `` | `lightuserdata` | `obj:getMaterial()` |
| setup | setup | `` | `void` | `obj:setup()` |
| getTotalMats | getTotalMats | `` | `number` | `obj:getTotalMats()` |
| getTotalMatsPresent | getTotalMatsPresent | `` | `number` | `obj:getTotalMatsPresent()` |
| needsMat | needsMat | `` | `integer` | `obj:needsMat()` |
| needMats | needMats | `` | `boolean` | `obj:needMats()` |

## ConsumptionItem
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| amount | amount | number | RW | `obj.amount = <value>` |
| rate | rate | number | RW | `obj.rate = <value>` |
| maxCapacity | maxCapacity | integer | RW | `obj.maxCapacity = <value>` |
| item | item | GameData | R | `obj.item` |
| inventorySection | inventorySection | InventorySection | R | `obj.inventorySection` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isFull | isFull | `` | `boolean` | `obj:isFull()` |
| isEmpty | isEmpty | `` | `boolean` | `obj:isEmpty()` |

## ContainerItem
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| takeMoney | takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| doubleCheckHandle | doubleCheckHandle | `` | `void` | `obj:doubleCheckHandle()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| update | update | `` | `void` | `obj:update()` |
| _destroyMenuGUICheck | _destroyMenuGUICheck | `` | `void` | `obj:_destroyMenuGUICheck()` |

## CraftingBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| maxCraftLevel | maxCraftLevel | integer | RW | `obj.maxCraftLevel = <value>` |
| crafting | crafting | std::deque<CraftingItem, std::allocator<CraftingItem> > | R | `obj.crafting` |
| specialCraftItemType | (lua_Integer | integer | RW | `obj.specialCraftItemType = <value>` |
| repeat | repeat | boolean | RW | `obj.repeat = <value>` |
| whosCrafting | whosCrafting | hand | RW | `obj.whosCrafting = <value>` |
| itemCrafted | itemCrafted | boolean | RW | `obj.itemCrafted = <value>` |
| failiureNotified | failiureNotified | boolean | RW | `obj.failiureNotified = <value>` |
| biggestCraftableItem | biggestCraftableItem | GameData | R | `obj.biggestCraftableItem` |
| outItem | outItem | Item | R | `obj.outItem` |
| inItems | inItems | Item | R | `obj.inItems` |
| partialItems | partialItems | ogre_unordered_map<GameData*, float>::type | R | `obj.partialItems` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createInventoryLayout | createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| givePower | givePower | `amount: number` | `void` | `obj:givePower(amount)` |
| _NV_givePower | _NV_givePower | `amount: number` | `void` | `obj:_NV_givePower(amount)` |
| hasCraftingQueued | hasCraftingQueued | `` | `boolean` | `obj:hasCraftingQueued()` |
| _NV_hasCraftingQueued | _NV_hasCraftingQueued | `` | `boolean` | `obj:_NV_hasCraftingQueued()` |
| isProductionFull | isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| getProductionItemData | getProductionItemData | `` | `GameData` | `obj:getProductionItemData()` |
| _NV_getProductionItemData | _NV_getProductionItemData | `` | `GameData` | `obj:_NV_getProductionItemData()` |
| getCurrentProductionQuantity | getCurrentProductionQuantity | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| _NV_getCurrentProductionQuantity | _NV_getCurrentProductionQuantity | `` | `integer` | `obj:_NV_getCurrentProductionQuantity()` |
| isAnyInputsInvalidType | isAnyInputsInvalidType | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| _NV_isAnyInputsInvalidType | _NV_isAnyInputsInvalidType | `` | `boolean` | `obj:_NV_isAnyInputsInvalidType()` |
| notifyCraftFailiure | notifyCraftFailiure | `` | `void` | `obj:notifyCraftFailiure()` |
| _removeCraft | _removeCraft | `index: integer` | `void` | `obj:_removeCraft(index)` |
| getCraft | getCraft | `id: integer` | `lightuserdata` | `obj:getCraft(id)` |
| destroyProductionItem | destroyProductionItem | `` | `void` | `obj:destroyProductionItem()` |
| getCriticalSuccessWeapon | getCriticalSuccessWeapon | `normalWeaponLevel: integer` | `GameData` | `obj:getCriticalSuccessWeapon(normalWeaponLevel)` |
| setupFromData | setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| updateOutput | updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| _NV_updateOutput | _NV_updateOutput | `rate: number` | `void` | `obj:_NV_updateOutput(rate)` |
| updateInventoryWindow | updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| _NV_updateInventoryWindow | _NV_updateInventoryWindow | `` | `void` | `obj:_NV_updateInventoryWindow()` |

## CraftingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| queueBtn | (void* | lightuserdata | R | `obj.queueBtn` |
| craftingName | (void* | lightuserdata | R | `obj.craftingName` |
| outputType | (lua_Integer | integer | RW | `obj.outputType = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `title: string, ins: integer, outs: integer` | `CraftingInventoryLayout` | `obj:_CONSTRUCTOR(title, ins, outs)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| setOutputType | setOutputType | `type: integer` | `void` | `obj:setOutputType(type)` |
| setCraftingName | setCraftingName | `name: string` | `void` | `obj:setCraftingName(name)` |
| getQueueButton | getQueueButton | `` | `lightuserdata` | `obj:getQueueButton()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| gunClass | gunClass | GunClass* | R | `obj.gunClass` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isCrossbow | isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| _NV_isCrossbow | _NV_isCrossbow | `` | `Crossbow` | `obj:_NV_isCrossbow()` |
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| getCraftMaterialMult | getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| _NV_getCraftMaterialMult | _NV_getCraftMaterialMult | `` | `number` | `obj:_NV_getCraftMaterialMult()` |
| getCraftTime | getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getRangeInUnits | getRangeInUnits | `` | `number` | `obj:getRangeInUnits()` |
| getEquipPositionOffset | getEquipPositionOffset | `` | `number` | `obj:getEquipPositionOffset()` |
| destroyItemEntityCallback_Equipping | destroyItemEntityCallback_Equipping | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| _NV_destroyItemEntityCallback_Equipping | _NV_destroyItemEntityCallback_Equipping | `` | `void` | `obj:_NV_destroyItemEntityCallback_Equipping()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Damages
**Header:** `extern/KenshiLib/Include/kenshi/Damages.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| multiply | multiply | `mult: number` | `void` | `obj:multiply(mult)` |
| total | total | `` | `number` | `obj:total()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getType | getType | `` | `integer` | `obj:getType()` |
| destroyObjectDatas | destroyObjectDatas | `` | `void` | `obj:destroyObjectDatas()` |

## DataPanelLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| w1 | (void* | lightuserdata | R | `obj.w1` |
| w2 | (void* | lightuserdata | R | `obj.w2` |
| category | category | integer | RW | `obj.category = <value>` |
| callback | callback | MyGUI::delegates::CDelegate1<DataPanelLine*> | R | `obj.callback` |
| keyValue | keyValue | string | RW | `obj.keyValue = <value>` |
| s1 | s1 | string | RW | `obj.s1 = <value>` |
| s2 | s2 | string | RW | `obj.s2 = <value>` |
| lo | lo | integer | RW | `obj.lo = <value>` |
| hi | hi | integer | RW | `obj.hi = <value>` |
| skinW1 | skinW1 | string | RW | `obj.skinW1 = <value>` |
| skinW2 | skinW2 | string | RW | `obj.skinW2 = <value>` |
| widgets | widgets | Ogre::vector<MyGUI::Widget*>::type | R | `obj.widgets` |
| classType | (lua_Integer | integer | RW | `obj.classType = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| setEnabled | setEnabled | `on: boolean` | `void` | `obj:setEnabled(on)` |
| _NV_setEnabled | _NV_setEnabled | `on: boolean` | `void` | `obj:_NV_setEnabled(on)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| resize | resize | `width: integer, height: integer` | `void` | `obj:resize(width, height)` |
| _NV_resize | _NV_resize | `width: integer, height: integer` | `void` | `obj:_NV_resize(width, height)` |
| getBottom | getBottom | `` | `integer` | `obj:getBottom()` |
| _NV_getBottom | _NV_getBottom | `` | `integer` | `obj:_NV_getBottom()` |
| getType | getType | `` | `integer` | `obj:getType()` |
| getNumWidgets | getNumWidgets | `` | `integer` | `obj:getNumWidgets()` |
| getWidget | getWidget | `index: integer` | `lightuserdata` | `obj:getWidget(index)` |

## DataPanelLine_Button
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| userData | userData | hand | RW | `obj.userData = <value>` |
| button | (void* | lightuserdata | R | `obj.button` |
| buttonWidth | buttonWidth | number | RW | `obj.buttonWidth = <value>` |
| buttonHeight | buttonHeight | number | RW | `obj.buttonHeight = <value>` |
| buttonSkin | buttonSkin | string | RW | `obj.buttonSkin = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `a: string, b: string, cat: integer, w: number, skin: string` | `lightuserdata` | `obj:_CONSTRUCTOR(a, b, cat, w, skin)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_CheckBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| valuePtr | (void* | lightuserdata | R | `obj.valuePtr` |
| text | (void* | lightuserdata | R | `obj.text` |
| button | (void* | lightuserdata | R | `obj.button` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| setValue | setValue | `checked: boolean` | `void` | `obj:setValue(checked)` |
| getTextBox | getTextBox | `` | `lightuserdata` | `obj:getTextBox()` |
| getCheckBox | getCheckBox | `` | `lightuserdata` | `obj:getCheckBox()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_DropBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| listBox | (void* | lightuserdata | R | `obj.listBox` |
| listWidth | listWidth | number | RW | `obj.listWidth = <value>` |
| valPtr | (void* | lightuserdata | R | `obj.valPtr` |
| hasGoBox | hasGoBox | boolean | RW | `obj.hasGoBox = <value>` |
| goBox | (void* | lightuserdata | R | `obj.goBox` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| addAValue | addAValue | `key: string, val: integer` | `void` | `obj:addAValue(key, val)` |
| getSelectedValue | getSelectedValue | `` | `integer` | `obj:getSelectedValue()` |
| setSelectedValue | setSelectedValue | `val: integer` | `void` | `obj:setSelectedValue(val)` |
| getSelectedText | getSelectedText | `` | `string` | `obj:getSelectedText()` |
| clearValues | clearValues | `` | `void` | `obj:clearValues()` |
| getComboBox | getComboBox | `` | `lightuserdata` | `obj:getComboBox()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Faction
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| v1 | v1 | number | RW | `obj.v1 = <value>` |
| v2 | v2 | number | RW | `obj.v2 = <value>` |
| bar | (void* | lightuserdata | R | `obj.bar` |
| bar2 | (void* | lightuserdata | R | `obj.bar2` |
| but | (void* | lightuserdata | R | `obj.but` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `a: string, b: string, cat: integer, vv1: number, vv2: number` | `lightuserdata` | `obj:_CONSTRUCTOR(a, b, cat, vv1, vv2)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_KeyConfig
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| btn0 | (void* | lightuserdata | R | `obj.btn0` |
| btn1 | (void* | lightuserdata | R | `obj.btn1` |
| command | command | string | RW | `obj.command = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `cmd: string, text: string, cat: integer` | `lightuserdata` | `obj:_CONSTRUCTOR(cmd, text, cat)` |
| oldKey | oldKey | `` | `integer` | `obj:oldKey()` |
| setKey | setKey | `s: string` | `void` | `obj:setKey(s)` |
| eraseKey | eraseKey | `key: string` | `void` | `obj:eraseKey(key)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| cancel | cancel | `` | `void` | `obj:cancel()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Progress
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| textBox | (void* | lightuserdata | R | `obj.textBox` |
| progress | (void* | lightuserdata | R | `obj.progress` |
| progressText | (void* | lightuserdata | R | `obj.progressText` |
| showKey | showKey | boolean | RW | `obj.showKey = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setProgress | setProgress | `value: number, text: string` | `void` | `obj:setProgress(value, text)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `key: string, category: integer, showKey: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(key, category, showKey)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Research
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| v1 | v1 | number | RW | `obj.v1 = <value>` |
| v2 | v2 | number | RW | `obj.v2 = <value>` |
| hasXBut | hasXBut | boolean | RW | `obj.hasXBut = <value>` |
| barSkin | barSkin | string | RW | `obj.barSkin = <value>` |
| bar | (void* | lightuserdata | R | `obj.bar` |
| but | (void* | lightuserdata | R | `obj.but` |
| Xbut | (void* | lightuserdata | R | `obj.Xbut` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `a: string, b: string, cat: integer, vv1: number, _barColor: string, _Xbut: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(a, b, cat, vv1, _barColor, _Xbut)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| scale | scale | number | RW | `obj.scale = <value>` |
| min | min | number | RW | `obj.min = <value>` |
| max | max | number | RW | `obj.max = <value>` |
| valuePtr | (void* | lightuserdata | R | `obj.valuePtr` |
| slider | (void* | lightuserdata | R | `obj.slider` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `key: string, text: string, min: number, max: number, category: integer, scale: number` | `lightuserdata` | `obj:_CONSTRUCTOR(key, text, min, max, category, scale)` |
| setValue | setValue | `value: number` | `void` | `obj:setValue(value)` |
| getValue | getValue | `` | `number` | `obj:getValue()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_SliderEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| width | width | number | RW | `obj.width = <value>` |
| showName | showName | boolean | RW | `obj.showName = <value>` |
| min | min | number | RW | `obj.min = <value>` |
| max | max | number | RW | `obj.max = <value>` |
| valuePtr | (void* | lightuserdata | R | `obj.valuePtr` |
| scale | scale | number | RW | `obj.scale = <value>` |
| nameText | (void* | lightuserdata | R | `obj.nameText` |
| valueEditBox | (void* | lightuserdata | R | `obj.valueEditBox` |
| sliderBar | (void* | lightuserdata | R | `obj.sliderBar` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getSlider | getSlider | `` | `lightuserdata` | `obj:getSlider()` |
| getEditBox | getEditBox | `` | `lightuserdata` | `obj:getEditBox()` |
| setValue | setValue | `v: number` | `void` | `obj:setValue(v)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| setPrecision | setPrecision | `dp: integer` | `void` | `obj:setPrecision(dp)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Text
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| editBox | (void* | lightuserdata | R | `obj.editBox` |
| textAlign | textAlign | MyGUI::Align | R | `obj.textAlign` |
| wordWrap | wordWrap | boolean | RW | `obj.wordWrap = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_TextEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| editBox | (void* | lightuserdata | R | `obj.editBox` |
| nameText | (void* | lightuserdata | R | `obj.nameText` |
| textAlign | textAlign | MyGUI::Align | R | `obj.textAlign` |
| showKey | showKey | boolean | RW | `obj.showKey = <value>` |
| multiLine | multiLine | boolean | RW | `obj.multiLine = <value>` |
| width | width | number | RW | `obj.width = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getEditBox | getEditBox | `` | `lightuserdata` | `obj:getEditBox()` |
| getNameBox | getNameBox | `` | `lightuserdata` | `obj:getNameBox()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DatapanelGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/DatapanelGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| tabEvent | tabEvent | MyGUI::delegates::CMultiDelegate2<DatapanelGUI*, int> | R | `obj.tabEvent` |
| frequentUpdatesWanted | frequentUpdatesWanted | boolean | RW | `obj.frequentUpdatesWanted = <value>` |
| scrollWin | (void* | lightuserdata | R | `obj.scrollWin` |
| premadeParentWindow | premadeParentWindow | boolean | RW | `obj.premadeParentWindow = <value>` |
| scrolling | scrolling | boolean | RW | `obj.scrolling = <value>` |
| isWindow | isWindow | boolean | RW | `obj.isWindow = <value>` |
| content | content | std::map<int, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > >, std::less<int>, Ogre::STLAllocator<std::pair<int const, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > | R | `obj.content` |
| bottomLine | bottomLine | std::map<int, DataPanelLine*, std::less<int>, Ogre::STLAllocator<std::pair<int const, DataPanelLine*>, Ogre::GeneralAllocPolicy > > | R | `obj.bottomLine` |
| currentCategory | currentCategory | integer | RW | `obj.currentCategory = <value>` |
| mouseOverEvent | (void* | lightuserdata | R | `obj.mouseOverEvent` |
| mouseOverEventDatas | (void* | lightuserdata | R | `obj.mouseOverEventDatas` |
| automaticRefresh | automaticRefresh | boolean | RW | `obj.automaticRefresh = <value>` |
| automaticTarget | automaticTarget | boolean | RW | `obj.automaticTarget = <value>` |
| tabWin | (void* | lightuserdata | R | `obj.tabWin` |
| tabs | tabs | lektor<MyGUI::Button*> | R | `obj.tabs` |
| panelName | panelName | string | RW | `obj.panelName = <value>` |
| x | x | number | RW | `obj.x = <value>` |
| y | y | number | RW | `obj.y = <value>` |
| w | w | number | RW | `obj.w = <value>` |
| h | h | number | RW | `obj.h = <value>` |
| DATALINESPACING | DATALINESPACING | number | RW | `obj.DATALINESPACING = <value>` |
| DATALINETHICKNESS | DATALINETHICKNESS | number | RW | `obj.DATALINETHICKNESS = <value>` |
| basicSpacing | basicSpacing | boolean | RW | `obj.basicSpacing = <value>` |
| layer | layer | string | RW | `obj.layer = <value>` |
| scrollView | (void* | lightuserdata | R | `obj.scrollView` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setFrequentUpdateMode | setFrequentUpdateMode | `` | `void` | `obj:setFrequentUpdateMode()` |
| setPositionReal | setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| _NV_setPositionReal | _NV_setPositionReal | `x: number, y: number` | `void` | `obj:_NV_setPositionReal(x, y)` |
| setPosition | setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| _NV_setPosition | _NV_setPosition | `x: integer, y: integer` | `void` | `obj:_NV_setPosition(x, y)` |
| resize | resize | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |
| _NV_resize | _NV_resize | `w: integer, h: integer` | `void` | `obj:_NV_resize(w, h)` |
| clear | clear | `` | `void` | `obj:clear()` |
| _NV_clear | _NV_clear | `` | `void` | `obj:_NV_clear()` |
| clearPage | clearPage | `cat: integer` | `void` | `obj:clearPage(cat)` |
| _NV_clearPage | _NV_clearPage | `cat: integer` | `void` | `obj:_NV_clearPage(cat)` |
| hideAllWidgets | hideAllWidgets | `` | `void` | `obj:hideAllWidgets()` |
| _NV_hideAllWidgets | _NV_hideAllWidgets | `` | `void` | `obj:_NV_hideAllWidgets()` |
| create | create | `` | `void` | `obj:create()` |
| _NV_create | _NV_create | `` | `void` | `obj:_NV_create()` |
| show | show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| show_NonSmooth | show_NonSmooth | `on: boolean` | `void` | `obj:show_NonSmooth(on)` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| setPanelName | setPanelName | `name: string` | `void` | `obj:setPanelName(name)` |
| showTabs | showTabs | `on: boolean` | `void` | `obj:showTabs(on)` |
| _NV_showTabs | _NV_showTabs | `on: boolean` | `void` | `obj:_NV_showTabs(on)` |
| addTab | addTab | `id: integer, name: string, icon: string` | `void` | `obj:addTab(id, name, icon)` |
| _NV_addTab | _NV_addTab | `id: integer, name: string, icon: string` | `void` | `obj:_NV_addTab(id, name, icon)` |
| setTabName | setTabName | `id: integer, name: string` | `void` | `obj:setTabName(id, name)` |
| _NV_setTabName | _NV_setTabName | `id: integer, name: string` | `void` | `obj:_NV_setTabName(id, name)` |
| setCaption | setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| setAutomaticRefresh | setAutomaticRefresh | `on: boolean` | `void` | `obj:setAutomaticRefresh(on)` |
| _NV_setAutomaticRefresh | _NV_setAutomaticRefresh | `on: boolean` | `void` | `obj:_NV_setAutomaticRefresh(on)` |
| setAutomaticTargeting | setAutomaticTargeting | `on: boolean` | `void` | `obj:setAutomaticTargeting(on)` |
| _NV_setAutomaticTargeting | _NV_setAutomaticTargeting | `on: boolean` | `void` | `obj:_NV_setAutomaticTargeting(on)` |
| _zeroLines | _zeroLines | `cat: integer` | `DataPanelLine` | `obj:_zeroLines(cat)` |
| _NV__zeroLines | _NV__zeroLines | `cat: integer` | `DataPanelLine` | `obj:_NV__zeroLines(cat)` |
| setLineStatInfo | setLineStatInfo | `s1: string, s2: string, category: integer` | `DataPanelLine` | `obj:setLineStatInfo(s1, s2, category)` |
| setLineFaction | setLineFaction | `s1: string, s2: string, category: integer, v1: number, v2: number` | `lightuserdata` | `obj:setLineFaction(s1, s2, category, v1, v2)` |
| setLineTextButton | setLineTextButton | `text: string, caption: string, category: integer, buttonWidth: number, skin: string` | `lightuserdata` | `obj:setLineTextButton(text, caption, category, buttonWidth, skin)` |
| setLineButton | setLineButton | `key: string, caption: string, category: integer` | `lightuserdata` | `obj:setLineButton(key, caption, category)` |
| setLineToggleButton | setLineToggleButton | `key: string, caption: string, category: integer` | `lightuserdata` | `obj:setLineToggleButton(key, caption, category)` |
| setLineProgress | setLineProgress | `key: string, category: integer, progressValue: number, progressText: string, showKey: boolean` | `lightuserdata` | `obj:setLineProgress(key, category, progressValue, progressText, showKey)` |
| removeLine | removeLine | `s1: string, category: integer` | `void` | `obj:removeLine(s1, category)` |
| addSpace | addSpace | `category: integer, h: number` | `void` | `obj:addSpace(category, h)` |
| setCategoryIcon | setCategoryIcon | `cat: integer, image: string` | `void` | `obj:setCategoryIcon(cat, image)` |
| _NV_setCategoryIcon | _NV_setCategoryIcon | `cat: integer, image: string` | `void` | `obj:_NV_setCategoryIcon(cat, image)` |
| changeCategory | changeCategory | `cat: integer` | `void` | `obj:changeCategory(cat)` |
| _NV_changeCategory | _NV_changeCategory | `cat: integer` | `void` | `obj:_NV_changeCategory(cat)` |
| getCurrentCategory | getCurrentCategory | `` | `integer` | `obj:getCurrentCategory()` |
| _NV_getCurrentCategory | _NV_getCurrentCategory | `` | `integer` | `obj:_NV_getCurrentCategory()` |
| setLineSpacing | setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:setLineSpacing(numLinesPerScreen)` |
| _NV_setLineSpacing | _NV_setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:_NV_setLineSpacing(numLinesPerScreen)` |
| getLine | getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:getLine(key, cat)` |
| _NV_getLine | _NV_getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:_NV_getLine(key, cat)` |
| lineExists | lineExists | `key: string, cat: integer` | `boolean` | `obj:lineExists(key, cat)` |
| getContentHeight | getContentHeight | `cat: integer` | `integer` | `obj:getContentHeight(cat)` |
| getNumLines | getNumLines | `cat: integer` | `integer` | `obj:getNumLines(cat)` |
| getLineByNum | getLineByNum | `cat: integer, i: integer` | `DataPanelLine` | `obj:getLineByNum(cat, i)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getNextVerticalPos | getNextVerticalPos | `category: integer` | `number` | `obj:getNextVerticalPos(category)` |
| dataExists | dataExists | `cat: integer, name: string` | `boolean` | `obj:dataExists(cat, name)` |
| clearCategoryTabs | clearCategoryTabs | `` | `void` | `obj:clearCategoryTabs()` |

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
| key | (lua_Integer | integer | RW | `obj.key = <value>` |
| value | value | integer | RW | `obj.value = <value>` |

## DialogChoiceList
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| conversationChoices | conversationChoices | lektor<DialogLineData*> | RW | `obj.conversationChoices = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `DialogChoiceList` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| add | add | `` | `void` | `obj:add()` |

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
| campaignTriggers | campaignTriggers | FitnessSelector<CampaignTriggerData*> | RW | `obj.campaignTriggers = <value>` |
| isTargetRace | isTargetRace | lektor<GameData*> | RW | `obj.isTargetRace = <value>` |
| isTargetSubRace_specificallyTheTarget | isTargetSubRace_specificallyTheTarget | lektor<GameData*> | RW | `obj.isTargetSubRace_specificallyTheTarget = <value>` |
| givesItem | givesItem | lektor<GameDataValuePair> | RW | `obj.givesItem = <value>` |
| inTownOf | *it, FactionBinding::getMetatableName( | Faction | R | `obj.inTownOf` |
| isTargetFaction | *it, FactionBinding::getMetatableName( | Faction | R | `obj.isTargetFaction` |
| isMyFaction | *it, FactionBinding::getMetatableName( | Faction | R | `obj.isMyFaction` |
| isCharacter | isCharacter | GameData | RW | `obj.isCharacter = <value>` |
| isTargetCarryingCharacter | isTargetCarryingCharacter | GameData | RW | `obj.isTargetCarryingCharacter = <value>` |
| _hasPackage | _hasPackage | GameData | RW | `obj._hasPackage = <value>` |
| isMyRace | isMyRace | GameData | RW | `obj.isMyRace = <value>` |
| isMySubRace | isMySubRace | GameData | RW | `obj.isMySubRace = <value>` |
| hasItemType | (lua_Integer | integer | RW | `obj.hasItemType = <value>` |
| hasItem | hasItem | lektor<GameData*> | RW | `obj.hasItem = <value>` |
| worldState | (void* | lightuserdata | RW | `obj.worldState = <value>` |
| data | data | GameData | RW | `obj.data = <value>` |
| onceOnly | onceOnly | boolean | RW | `obj.onceOnly = <value>` |
| isMonologue | isMonologue | boolean | RW | `obj.isMonologue = <value>` |
| forCertainType | (lua_Integer | integer | RW | `obj.forCertainType = <value>` |
| children | children | DialogChoiceList | RW | `obj.children = <value>` |
| conditions | conditions | lektor<DialogLineData::DialogCondition*> | RW | `obj.conditions = <value>` |
| actions | actions | lektor<DialogLineData::DialogAction*> | RW | `obj.actions = <value>` |
| lineCount | lineCount | integer | RW | `obj.lineCount = <value>` |
| texts | texts | string | RW | `obj.texts = <value>` |
| parent | parent | DialogLineData | RW | `obj.parent = <value>` |
| chancePermanent | chancePermanent | number | RW | `obj.chancePermanent = <value>` |
| chanceTemporary | chanceTemporary | number | RW | `obj.chanceTemporary = <value>` |
| unique | unique | boolean | RW | `obj.unique = <value>` |
| uniqueOwner | uniqueOwner | hand | RW | `obj.uniqueOwner = <value>` |
| dialogRepeatMinTimeInHours | dialogRepeatMinTimeInHours | number | RW | `obj.dialogRepeatMinTimeInHours = <value>` |
| lastTimeSaid | lastTimeSaid | TimeOfDay | RW | `obj.lastTimeSaid = <value>` |
| score | score | integer | RW | `obj.score = <value>` |
| oneAtATime | oneAtATime | boolean | RW | `obj.oneAtATime = <value>` |
| isLocked | isLocked | boolean | RW | `obj.isLocked = <value>` |
| locks | locks | lektor<DialogLineData*> | RW | `obj.locks = <value>` |
| unlocks_lockMe | unlocks_lockMe | lektor<DialogLineData*> | RW | `obj.unlocks_lockMe = <value>` |
| unlocks_dontLockMe | unlocks_dontLockMe | lektor<DialogLineData*> | RW | `obj.unlocks_dontLockMe = <value>` |
| crowdTrigger | crowdTrigger | DialogLineData | RW | `obj.crowdTrigger = <value>` |
| factionRelationEffects | factionRelationEffects | unknown | RW | `obj.factionRelationEffects = <value>` |
| playerInterruptionDialog | playerInterruptionDialog | DialogLineData | RW | `obj.playerInterruptionDialog = <value>` |
| isInterjection | isInterjection | boolean | RW | `obj.isInterjection = <value>` |
| speaker | (lua_Integer | integer | RW | `obj.speaker = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasSpecificCharacterRequirement | hasSpecificCharacterRequirement | `` | `boolean` | `obj:hasSpecificCharacterRequirement()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupChildren | setupChildren | `` | `void` | `obj:setupChildren()` |
| checkRepeatLimits | checkRepeatLimits | `` | `boolean` | `obj:checkRepeatLimits()` |
| getName | getName | `` | `string` | `obj:getName()` |
| saidItBefore | saidItBefore | `` | `boolean` | `obj:saidItBefore()` |
| willTalkToEnemies | willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| isEmptyNode | isEmptyNode | `` | `boolean` | `obj:isEmptyNode()` |
| _NV_isEmptyNode | _NV_isEmptyNode | `` | `boolean` | `obj:_NV_isEmptyNode()` |
| isAnnouncement | isAnnouncement | `` | `boolean` | `obj:isAnnouncement()` |
| stampLastTimeSaid | stampLastTimeSaid | `` | `void` | `obj:stampLastTimeSaid()` |
| hasChildren | hasChildren | `` | `boolean` | `obj:hasChildren()` |
| getStringID | getStringID | `` | `string` | `obj:getStringID()` |
| getGameData | getGameData | `` | `GameData` | `obj:getGameData()` |
| getMoneyCostForLine | getMoneyCostForLine | `` | `integer` | `obj:getMoneyCostForLine()` |

## DialogState
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| count | count | integer | RW | `obj.count = <value>` |
| lastTimeStamp | lastTimeStamp | number | RW | `obj.lastTimeStamp = <value>` |
| resetTime | resetTime | number | RW | `obj.resetTime = <value>` |

## Dialogue
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setupWordSwaps | setupWordSwaps | `` | `void` | `obj:setupWordSwaps()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Dialogue` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| getConversationTarget | getConversationTarget | `` | `hand` | `obj:getConversationTarget()` |
| setInDialog | setInDialog | `on: boolean` | `void` | `obj:setInDialog(on)` |
| clearDialogues | clearDialogues | `` | `void` | `obj:clearDialogues()` |
| clearAnnouncements | clearAnnouncements | `` | `void` | `obj:clearAnnouncements()` |
| needsDialogAssessmentUpdate | needsDialogAssessmentUpdate | `` | `boolean` | `obj:needsDialogAssessmentUpdate()` |
| clearConversationList | clearConversationList | `t: integer` | `void` | `obj:clearConversationList(t)` |
| willTalkToEnemies | willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| stopEvent | stopEvent | `what: integer` | `void` | `obj:stopEvent(what)` |
| conversationHasEnded | conversationHasEnded | `` | `boolean` | `obj:conversationHasEnded()` |
| conversationHasEndedPrettyMuch | conversationHasEndedPrettyMuch | `` | `boolean` | `obj:conversationHasEndedPrettyMuch()` |
| update | update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| endDialogue | endDialogue | `definitelyTheEnd: boolean` | `void` | `obj:endDialogue(definitelyTheEnd)` |
| hasDialogue_Fast | hasDialogue_Fast | `` | `boolean` | `obj:hasDialogue_Fast()` |
| hasDialogue_Accurate | hasDialogue_Accurate | `` | `boolean` | `obj:hasDialogue_Accurate()` |
| hasDialogueEvent | hasDialogueEvent | `e: integer` | `boolean` | `obj:hasDialogueEvent(e)` |
| dialogDelivered | dialogDelivered | `e: integer` | `boolean` | `obj:dialogDelivered(e)` |
| isKOExempt | isKOExempt | `what: integer` | `boolean` | `obj:isKOExempt(what)` |
| _endPlayerConversation | _endPlayerConversation | `finished: boolean` | `void` | `obj:_endPlayerConversation(finished)` |
| getConversationList | getConversationList | `t: integer` | `DialogChoiceList` | `obj:getConversationList(t)` |
| listPlayerReplies | listPlayerReplies | `` | `void` | `obj:listPlayerReplies()` |
| _updateTextPos | _updateTextPos | `` | `void` | `obj:_updateTextPos()` |
| clearSpeechBox | clearSpeechBox | `` | `void` | `obj:clearSpeechBox()` |
| clearRespones | clearRespones | `` | `void` | `obj:clearRespones()` |
| clearResponesGUI | clearResponesGUI | `` | `void` | `obj:clearResponesGUI()` |
| setResponesGUI | setResponesGUI | `` | `void` | `obj:setResponesGUI()` |
| setConversationReplyGUI | setConversationReplyGUI | `` | `void` | `obj:setConversationReplyGUI()` |
| getHandle | Dialogue_getHandle | `` | `hand` | `obj:getHandle()` |
| getConversationTarget | Dialogue_getConversationTarget | `` | `hand` | `obj:getConversationTarget()` |
| getSpeaker | Dialogue_getSpeaker | `who: integer, isForWordswaps: boolean` | `Character` | `obj:getSpeaker(who, isForWordswaps)` |
| findInterjectionCharacter | Dialogue_findInterjectionCharacter | `` | `Character` | `obj:findInterjectionCharacter()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setText | setText | `text: string` | `void` | `obj:setText(text)` |
| setAlpha | setAlpha | `value: number` | `void` | `obj:setAlpha(value)` |
| reset | reset | `` | `void` | `obj:reset()` |
| getAlpha | getAlpha | `` | `number` | `obj:getAlpha()` |

## DialogueWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/DialogueWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| dialogue | dialogue | Dialogue | R | `obj.dialogue` |
| conversationPanelsMargin | conversationPanelsMargin | integer | RW | `obj.conversationPanelsMargin = <value>` |
| converstaionPCPanelBottom | converstaionPCPanelBottom | integer | RW | `obj.converstaionPCPanelBottom = <value>` |
| conversationPCSpeechPanelMinHeight | conversationPCSpeechPanelMinHeight | integer | RW | `obj.conversationPCSpeechPanelMinHeight = <value>` |
| conversationNPCSpeechPanelMinHeight | conversationNPCSpeechPanelMinHeight | integer | RW | `obj.conversationNPCSpeechPanelMinHeight = <value>` |
| conversationPCPanelHeightDiffSpeechPanel | conversationPCPanelHeightDiffSpeechPanel | integer | RW | `obj.conversationPCPanelHeightDiffSpeechPanel = <value>` |
| conversationNPCPanelHeightDiffSpeechPanel | conversationNPCPanelHeightDiffSpeechPanel | integer | RW | `obj.conversationNPCPanelHeightDiffSpeechPanel = <value>` |
| conversationPC | conversationPC | Character | R | `obj.conversationPC` |
| conversationPCPanel | (void* | lightuserdata | R | `obj.conversationPCPanel` |
| conversationNPCPanel | (void* | lightuserdata | R | `obj.conversationNPCPanel` |
| conversationNPCNameText | (void* | lightuserdata | R | `obj.conversationNPCNameText` |
| conversationPCNameText | (void* | lightuserdata | R | `obj.conversationPCNameText` |
| conversationPCMoneyText | (void* | lightuserdata | R | `obj.conversationPCMoneyText` |
| conversationNPCSpeech | (void* | lightuserdata | R | `obj.conversationNPCSpeech` |
| conversationPCSpeechPanel | (void* | lightuserdata | R | `obj.conversationPCSpeechPanel` |
| conversationNPCPortrait | (void* | lightuserdata | R | `obj.conversationNPCPortrait` |
| conversationPCPortrait | (void* | lightuserdata | R | `obj.conversationPCPortrait` |
| conversationTextColor | conversationTextColor | MyGUI::Colour | R | `obj.conversationTextColor` |
| conversationTextSelectedColor | conversationTextSelectedColor | MyGUI::Colour | R | `obj.conversationTextSelectedColor` |
| replyTexts | replyTexts | Ogre::FastArray<MyGUI::EditBox*> | R | `obj.replyTexts` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| getTop | getTop | `` | `integer` | `obj:getTop()` |
| activateResponse | activateResponse | `index: integer` | `void` | `obj:activateResponse(index)` |
| setNPCText | setNPCText | `text: string` | `void` | `obj:setNPCText(text)` |
| clearResponses | clearResponses | `` | `void` | `obj:clearResponses()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `DialogueWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updatePanelsPosition | updatePanelsPosition | `` | `void` | `obj:updatePanelsPosition()` |

## DoorStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/DoorStuff.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isSetupComplete | isSetupComplete | boolean | RW | `obj.isSetupComplete = <value>` |
| parent | parent | Building | R | `obj.parent` |
| doorLock | (void* | lightuserdata | R | `obj.doorLock` |
| gateCode | gateCode | integer | RW | `obj.gateCode = <value>` |
| doorOpenAmount | doorOpenAmount | number | RW | `obj.doorOpenAmount = <value>` |
| state | (lua_Integer | integer | RW | `obj.state = <value>` |
| wantsToLock | wantsToLock | boolean | RW | `obj.wantsToLock = <value>` |
| doorSpeed | doorSpeed | number | RW | `obj.doorSpeed = <value>` |
| doorDistance | doorDistance | number | RW | `obj.doorDistance = <value>` |
| doorMoveAxis | doorMoveAxis | integer | RW | `obj.doorMoveAxis = <value>` |
| doorComesOut | doorComesOut | number | RW | `obj.doorComesOut = <value>` |
| nodeClosedPosition | nodeClosedPosition | Vector3 | R | `obj.nodeClosedPosition` |
| actorClosedPosition | actorClosedPosition | Vector3 | RW | `obj.actorClosedPosition = <value>` |
| doorClosedPosition | doorClosedPosition | Vector3 | RW | `obj.doorClosedPosition = <value>` |
| doorClosedPositionOut | doorClosedPositionOut | Vector3 | RW | `obj.doorClosedPositionOut = <value>` |
| doorClosedPositionIn | doorClosedPositionIn | Vector3 | RW | `obj.doorClosedPositionIn = <value>` |
| axisH | axisH | Vector3 | RW | `obj.axisH = <value>` |
| axisF | axisF | Vector3 | RW | `obj.axisF = <value>` |
| _isBroken | _isBroken | boolean | RW | `obj._isBroken = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupPhysicalUT | setupPhysicalUT | `` | `boolean` | `obj:setupPhysicalUT()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |
| _NV_getFaction | _NV_getFaction | `` | `Faction` | `obj:_NV_getFaction()` |
| _getPhysActorUT | _getPhysActorUT | `` | `lightuserdata` | `obj:_getPhysActorUT()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| getGateCode | getGateCode | `` | `integer` | `obj:getGateCode()` |
| setGateCode | setGateCode | `code: integer` | `void` | `obj:setGateCode(code)` |
| isGate | isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| _NV_isGate | _NV_isGate | `` | `GatewayBuilding` | `obj:_NV_isGate()` |
| isPublic | isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| getMouseCursor | getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getReachRange | getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| getDoor | getDoor | `` | `DoorStuff` | `obj:getDoor()` |
| _NV_getDoor | _NV_getDoor | `` | `DoorStuff` | `obj:_NV_getDoor()` |
| getName | getName | `` | `string` | `obj:getName()` |
| _NV_getName | _NV_getName | `` | `string` | `obj:_NV_getName()` |
| getDoorLock | getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| _NV_getDoorLock | _NV_getDoorLock | `` | `lightuserdata` | `obj:_NV_getDoorLock()` |
| hasDoorLock | hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| _NV_hasDoorLock | _NV_hasDoorLock | `` | `boolean` | `obj:_NV_hasDoorLock()` |
| updateGateCodeState | updateGateCodeState | `` | `void` | `obj:updateGateCodeState()` |
| onBuildingLoaded | onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| _NV_onBuildingLoaded | _NV_onBuildingLoaded | `` | `void` | `obj:_NV_onBuildingLoaded()` |
| setDoorOpenAmount | setDoorOpenAmount | `amount: number, forceUnsafe: boolean` | `void` | `obj:setDoorOpenAmount(amount, forceUnsafe)` |
| isBroken | isBroken | `` | `boolean` | `obj:isBroken()` |
| _NV_isBroken | _NV_isBroken | `` | `boolean` | `obj:_NV_isBroken()` |
| setBroken | setBroken | `on: boolean` | `void` | `obj:setBroken(on)` |
| _NV_setBroken | _NV_setBroken | `on: boolean` | `void` | `obj:_NV_setBroken(on)` |
| isDisabled | isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| isLocked | isLocked | `` | `boolean` | `obj:isLocked()` |
| lockDoor | lockDoor | `` | `void` | `obj:lockDoor()` |
| unlockDoor | unlockDoor | `` | `void` | `obj:unlockDoor()` |
| getDoorOpenAmount | getDoorOpenAmount | `` | `number` | `obj:getDoorOpenAmount()` |
| setDoorState | setDoorState | `what: integer` | `void` | `obj:setDoorState(what)` |
| getDoorState | getDoorState | `` | `integer` | `obj:getDoorState()` |
| openDoor | openDoor | `` | `boolean` | `obj:openDoor()` |
| closeDoor | closeDoor | `` | `boolean` | `obj:closeDoor()` |
| _forceDoorClosedUT | _forceDoorClosedUT | `` | `boolean` | `obj:_forceDoorClosedUT()` |
| _forceDoorOpenUT | _forceDoorOpenUT | `` | `boolean` | `obj:_forceDoorOpenUT()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| getDoorPosOutside_extraFarOut | getDoorPosOutside_extraFarOut | `mult: number` | `Vector3` | `obj:getDoorPosOutside_extraFarOut(mult)` |
| getDoorPosInside_extraFarIn | getDoorPosInside_extraFarIn | `mult: number` | `Vector3` | `obj:getDoorPosInside_extraFarIn(mult)` |
| isOpen | isOpen | `` | `boolean` | `obj:isOpen()` |
| doorStuff | doorStuff | `` | `DoorStuff` | `obj:doorStuff()` |
| _NV_doorStuff | _NV_doorStuff | `` | `DoorStuff` | `obj:_NV_doorStuff()` |
| doorParentBuilding | doorParentBuilding | `` | `Building` | `obj:doorParentBuilding()` |
| _NV_doorParentBuilding | _NV_doorParentBuilding | `` | `Building` | `obj:_NV_doorParentBuilding()` |

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _antiSlavery | _antiSlavery | boolean | RW | `obj._antiSlavery = <value>` |
| characteristicsData | characteristicsData | Faction::CharacteristicsData | R | `obj.characteristicsData` |
| ranks | ranks | lektor<std::string> | R | `obj.ranks` |
| allowSlavesWeapons | allowSlavesWeapons | boolean | RW | `obj.allowSlavesWeapons = <value>` |
| fundamentalNPCType | (lua_Integer | integer | RW | `obj.fundamentalNPCType = <value>` |
| myLawEnforcementFaction | myLawEnforcementFaction | Faction | R | `obj.myLawEnforcementFaction` |
| isALawEnforcementFaction | isALawEnforcementFaction | boolean | RW | `obj.isALawEnforcementFaction = <value>` |
| factionLeader | factionLeader | FactionLeader | R | `obj.factionLeader` |
| diplomatMgr | diplomatMgr | FactionUniqueSquadManager* | R | `obj.diplomatMgr` |
| relations | relations | FactionRelations | RW | `obj.relations = <value>` |
| factionOwnerships | factionOwnerships | Ownerships | R | `obj.factionOwnerships` |
| warMgr | warMgr | FactionWarMgr* | R | `obj.warMgr` |
| tradeCulture | tradeCulture | TradeCulture | RW | `obj.tradeCulture = <value>` |
| raceSelector | raceSelector | FitnessSelector<GameData*> | R | `obj.raceSelector` |
| name | name | string | RW | `obj.name = <value>` |
| notARealFaction | notARealFaction | boolean | RW | `obj.notARealFaction = <value>` |
| roadPreference | roadPreference | number | RW | `obj.roadPreference = <value>` |
| platoonKillList | platoonKillList | lektor<Platoon*> | R | `obj.platoonKillList` |
| platoonRemoveList | platoonRemoveList | lektor<Platoon*> | R | `obj.platoonRemoveList` |
| activePlatoons | activePlatoons | lektor<Platoon*> | R | `obj.activePlatoons` |
| unloadedPlatoons | unloadedPlatoons | lektor<Platoon*> | R | `obj.unloadedPlatoons` |
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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `_name: string` | `Faction` | `obj:_CONSTRUCTOR(_name)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getProsperityMultiplier | getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| clearAndDestroy | clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| setup2 | setup2 | `` | `boolean` | `obj:setup2()` |
| setup3 | setup3 | `` | `void` | `obj:setup3()` |
| getNewPlatoonID | getNewPlatoonID | `` | `string` | `obj:getNewPlatoonID()` |
| resetPlatoonID | resetPlatoonID | `` | `void` | `obj:resetPlatoonID()` |
| createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | `src: string` | `void` | `obj:createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src)` |
| resetSquadPositions | resetSquadPositions | `target: Vector3` | `boolean` | `obj:resetSquadPositions(target)` |
| getData | getData | `` | `GameData` | `obj:getData()` |
| getDefaultDivision | getDefaultDivision | `` | `GameData` | `obj:getDefaultDivision()` |
| getFactionColorScheme | getFactionColorScheme | `` | `GameData` | `obj:getFactionColorScheme()` |
| _activateUnloadedPlatoons | _activateUnloadedPlatoons | `` | `void` | `obj:_activateUnloadedPlatoons()` |
| processKillList | processKillList | `` | `void` | `obj:processKillList()` |
| _NV_processKillList | _NV_processKillList | `` | `void` | `obj:_NV_processKillList()` |
| getFactionSize | getFactionSize | `` | `integer` | `obj:getFactionSize()` |
| update | update | `time: number` | `void` | `obj:update(time)` |
| periodicUpdateThreaded | periodicUpdateThreaded | `` | `boolean` | `obj:periodicUpdateThreaded()` |
| periodicUpdateMT | periodicUpdateMT | `` | `boolean` | `obj:periodicUpdateMT()` |
| isThePlayer | isThePlayer | `` | `boolean` | `obj:isThePlayer()` |
| isNotARealFaction | isNotARealFaction | `` | `boolean` | `obj:isNotARealFaction()` |
| getRoadPreference | getRoadPreference | `` | `number` | `obj:getRoadPreference()` |
| isAntiSlavery | isAntiSlavery | `` | `boolean` | `obj:isAntiSlavery()` |
| getLawEnforcementFaction | getLawEnforcementFaction | `` | `Faction` | `obj:getLawEnforcementFaction()` |
| setName | setName | `_name: string` | `void` | `obj:setName(_name)` |
| updateUnloadedPlatoons | updateUnloadedPlatoons | `time: number` | `void` | `obj:updateUnloadedPlatoons(time)` |
| updateActivePlatoons | updateActivePlatoons | `time: number` | `void` | `obj:updateActivePlatoons(time)` |
| spawnSquadMissionsUpdate | spawnSquadMissionsUpdate | `` | `void` | `obj:spawnSquadMissionsUpdate()` |
| _spawnASquad | _spawnASquad | `listname: string, sizeMultiplier: number` | `boolean` | `obj:_spawnASquad(listname, sizeMultiplier)` |
| getSquadThatOwns | Faction_getSquadThatOwns | `` | `Platoon` | `obj:getSquadThatOwns()` |
| getActivePlatoons | Faction_getActivePlatoons_method | `` | `lektor<Platoon*>` | `obj:getActivePlatoons()` |
| getUnloadedPlatoons | Faction_getUnloadedPlatoons_method | `` | `lektor<Platoon*>` | `obj:getUnloadedPlatoons()` |
| getAllActiveSquads | Faction_getAllActiveSquads | `` | `lektor<Platoon*>` | `obj:getAllActiveSquads()` |
| getFundamentalNPCType | getFundamentalNPCType | `` | `integer` | `obj:getFundamentalNPCType()` |
| setup | setup | `` | `boolean` | `obj:setup()` |
| createNewEmptyUnloadedPlatoon | createNewEmptyUnloadedPlatoon | `pos: Vector3, forcecharacterDatas: userdata, persistent: boolean` | `Platoon` | `obj:createNewEmptyUnloadedPlatoon(pos, forcecharacterDatas, persistent)` |
| createNewEmptyActivePlatoon | createNewEmptyActivePlatoon | `permanent: boolean, p: Vector3` | `Platoon` | `obj:createNewEmptyActivePlatoon(permanent, p)` |
| createPlatoonUnloaded | createPlatoonUnloaded | `charactersState: userdata, pos: Vector3, persistent: boolean` | `void` | `obj:createPlatoonUnloaded(charactersState, pos, persistent)` |
| createPlatoonAuto | createPlatoonAuto | `pos: Vector3` | `void` | `obj:createPlatoonAuto(pos)` |
| createPlatoonsAuto | createPlatoonsAuto | `` | `void` | `obj:createPlatoonsAuto()` |
| restorePlatoon | restorePlatoon | `` | `void` | `obj:restorePlatoon()` |
| countPopulation | countPopulation | `` | `integer` | `obj:countPopulation()` |
| countNumSquads | countNumSquads | `` | `integer` | `obj:countNumSquads()` |
| destroyPlatoon | destroyPlatoon | `` | `void` | `obj:destroyPlatoon()` |
| removePlatoon | removePlatoon | `` | `void` | `obj:removePlatoon()` |
| getRandomLockLevel | getRandomLockLevel | `` | `integer` | `obj:getRandomLockLevel()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| loadState | loadState | `saveSource: userdata` | `void` | `obj:loadState(saveSource)` |
| saveState | saveState | `container: userdata, leveleditor: boolean` | `GameData` | `obj:saveState(container, leveleditor)` |
| getCharactersInArea | getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| _NV_getCharactersInArea | _NV_getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:_NV_getCharactersInArea(pos, radius, standingOnly)` |
| getSelectedObjects | getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| _NV_getSelectedObjects | _NV_getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:_NV_getSelectedObjects(type, selectedOnly)` |
| removeObject | removeObject | `` | `void` | `obj:removeObject()` |
| _NV_removeObject | _NV_removeObject | `` | `void` | `obj:_NV_removeObject()` |
| destroyObject | destroyObject | `` | `void` | `obj:destroyObject()` |
| _NV_destroyObject | _NV_destroyObject | `` | `void` | `obj:_NV_destroyObject()` |
| addActiveObject | addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| choosePlatoon | choosePlatoon | `` | `ActivePlatoon` | `obj:choosePlatoon()` |
| getName | getName | `` | `void` | `obj:getName()` |
| getNumPlatoons | getNumPlatoons | `tempsOnly: boolean` | `integer` | `obj:getNumPlatoons(tempsOnly)` |
| getAllSquadsThatOwn | getAllSquadsThatOwn | `` | `void` | `obj:getAllSquadsThatOwn()` |
| chooseARace | chooseARace | `` | `GameData` | `obj:chooseARace()` |
| getBuildingReplacement | getBuildingReplacement | `` | `GameData` | `obj:getBuildingReplacement()` |
| _switchToUnloadedPlatoon | _switchToUnloadedPlatoon | `` | `void` | `obj:_switchToUnloadedPlatoon()` |
| _newPlatoon | _newPlatoon | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:_newPlatoon(pos, persistent)` |
| _addActivePlatoonToList | _addActivePlatoonToList | `` | `void` | `obj:_addActivePlatoonToList()` |
| addPlatoon | addPlatoon | `` | `void` | `obj:addPlatoon()` |
| changePlatoonIndex | changePlatoonIndex | `index: integer` | `void` | `obj:changePlatoonIndex(index)` |
| deactivatePlatoon | deactivatePlatoon | `` | `void` | `obj:deactivatePlatoon()` |
| activatePlatoon | activatePlatoon | `` | `void` | `obj:activatePlatoon()` |

## FactionLeader
**Header:** `extern/KenshiLib/Include/kenshi/FactionLeader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| faction | faction | Faction | R | `obj.faction` |
| biomeTerritory | biomeTerritory | lektor<GameData*> | R | `obj.biomeTerritory` |
| worstEnemy | worstEnemy | Faction | R | `obj.worstEnemy` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionManager
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| participants | participants | Faction | R | `obj.participants` |
| addListMuto | addListMuto | unknown | R | `obj.addListMuto` |
| toAddList | toAddList | Platoon | R | `obj.toAddList` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| clearAndDestroy | clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| activateUnloadedPlatoons | activateUnloadedPlatoons | `` | `void` | `obj:activateUnloadedPlatoons()` |
| getFactionByName | getFactionByName | `name: string` | `Faction` | `obj:getFactionByName(name)` |
| getFactionByStringID | getFactionByStringID | `sid: string` | `Faction` | `obj:getFactionByStringID(sid)` |
| getEmptyFaction | getEmptyFaction | `` | `Faction` | `obj:getEmptyFaction()` |
| setupAndLinkAllFactions | setupAndLinkAllFactions | `` | `void` | `obj:setupAndLinkAllFactions()` |
| areAnyHostileCampaignsRunning | areAnyHostileCampaignsRunning | `` | `boolean` | `obj:areAnyHostileCampaignsRunning()` |
| getNumTempPlatoons | getNumTempPlatoons | `` | `integer` | `obj:getNumTempPlatoons()` |
| updateMT | updateMT | `time: number` | `void` | `obj:updateMT(time)` |
| updateThreaded | updateThreaded | `time: number` | `void` | `obj:updateThreaded(time)` |
| _showDebugPlatoonMarkers | _showDebugPlatoonMarkers | `on: boolean` | `void` | `obj:_showDebugPlatoonMarkers(on)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getFactionBySquad | FactionManager_getFactionBySquad | `` | `Faction` | `obj:getFactionBySquad()` |
| getAllFactions | FactionManager_getAllFactions | `` | `void` | `obj:getAllFactions()` |

## FactionRelations
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Faction | RW | `obj.me = <value>` |
| playerRank | playerRank | integer | RW | `obj.playerRank = <value>` |
| globalReputationTrust | globalReputationTrust | number | RW | `obj.globalReputationTrust = <value>` |
| globalReputationForBadassery | globalReputationForBadassery | number | RW | `obj.globalReputationForBadassery = <value>` |
| _factionRelations | _factionRelations | unknown | R | `obj._factionRelations` |
| defaultFactionRelation | defaultFactionRelation | number | RW | `obj.defaultFactionRelation = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactionRelations` | `obj:_CONSTRUCTOR()` |
| setupPhase2 | setupPhase2 | `` | `void` | `obj:setupPhase2()` |
| isEnemyByDefault | isEnemyByDefault | `` | `boolean` | `obj:isEnemyByDefault()` |
| reset | reset | `` | `void` | `obj:reset()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupPhase1 | setupPhase1 | `` | `void` | `obj:setupPhase1()` |
| save | save | `` | `void` | `obj:save()` |
| _NV_save | _NV_save | `` | `void` | `obj:_NV_save()` |
| load | load | `playerOnly: boolean` | `void` | `obj:load(playerOnly)` |
| _NV_load | _NV_load | `playerOnly: boolean` | `void` | `obj:_NV_load(playerOnly)` |
| _isAlly | _isAlly | `` | `boolean` | `obj:_isAlly()` |
| _isEnemy | _isEnemy | `` | `boolean` | `obj:_isEnemy()` |
| isEnemy | isEnemy | `` | `boolean` | `obj:isEnemy()` |
| setEnemy | setEnemy | `` | `void` | `obj:setEnemy()` |
| _NV_setEnemy | _NV_setEnemy | `` | `void` | `obj:_NV_setEnemy()` |
| isAlly | isAlly | `` | `boolean` | `obj:isAlly()` |
| isCoexisting | isCoexisting | `` | `boolean` | `obj:isCoexisting()` |
| getFactionRelation | getFactionRelation | `` | `number` | `obj:getFactionRelation()` |
| getFactionRelationMultiplier | getFactionRelationMultiplier | `` | `number` | `obj:getFactionRelationMultiplier()` |
| getFactionRelationMultiplierInverse | getFactionRelationMultiplierInverse | `` | `number` | `obj:getFactionRelationMultiplierInverse()` |
| setRelation | setRelation | `setTo: number` | `void` | `obj:setRelation(setTo)` |
| affectRelations | affectRelations | `amount: number, mult: number` | `void` | `obj:affectRelations(amount, mult)` |
| _NV_affectRelations | _NV_affectRelations | `amount: number, mult: number` | `void` | `obj:_NV_affectRelations(amount, mult)` |
| affectTrust | affectTrust | `amount: number, mult: number` | `void` | `obj:affectTrust(amount, mult)` |
| _NV_affectTrust | _NV_affectTrust | `amount: number, mult: number` | `void` | `obj:_NV_affectTrust(amount, mult)` |
| setNoLongerEnemies | setNoLongerEnemies | `` | `void` | `obj:setNoLongerEnemies()` |
| _NV_setNoLongerEnemies | _NV_setNoLongerEnemies | `` | `void` | `obj:_NV_setNoLongerEnemies()` |
| declareWar | declareWar | `` | `void` | `obj:declareWar()` |
| _NV_declareWar | _NV_declareWar | `` | `void` | `obj:_NV_declareWar()` |
| affectReputation | affectReputation | `amount: number` | `void` | `obj:affectReputation(amount)` |
| _NV_affectReputation | _NV_affectReputation | `amount: number` | `void` | `obj:_NV_affectReputation(amount)` |
| getRelationData | getRelationData | `` | `FactionRelations::RelationData` | `obj:getRelationData()` |
| _NV_getRelationData | _NV_getRelationData | `` | `FactionRelations::RelationData` | `obj:_NV_getRelationData()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| getRelationsData | getRelationsData | `` | `void` | `obj:getRelationsData()` |
| checkStateCondition | checkStateCondition | `conditionName: integer, compareBy: integer, val: integer` | `boolean` | `obj:checkStateCondition(conditionName, compareBy, val)` |

## FactionRelationsLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| faction | faction | Faction | R | `obj.faction` |
| value | value | number | RW | `obj.value = <value>` |
| valueText | (void* | lightuserdata | R | `obj.valueText` |
| leftBar | (void* | lightuserdata | R | `obj.leftBar` |
| rightBar | (void* | lightuserdata | R | `obj.rightBar` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | update | `` | `void` | `obj:update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionUniqueSquadManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Faction | R | `obj.me` |
| squadListData | squadListData | GameData | R | `obj.squadListData` |
| homeTown | homeTown | Town | R | `obj.homeTown` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAndReset | clearAndReset | `` | `void` | `obj:clearAndReset()` |
| chooseRandomSquadToSpawn | chooseRandomSquadToSpawn | `time: number` | `GameData` | `obj:chooseRandomSquadToSpawn(time)` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |

## FactionsScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mainWidget | (void* | lightuserdata | R | `obj.mainWidget` |
| selectedFaction | selectedFaction | Faction | R | `obj.selectedFaction` |
| scrollList | (void* | lightuserdata | RW | `obj.scrollList = <value>` |
| scrollListItemTop | scrollListItemTop | integer | RW | `obj.scrollListItemTop = <value>` |
| scrollListItemWidth | scrollListItemWidth | integer | RW | `obj.scrollListItemWidth = <value>` |
| nameText | (void* | lightuserdata | R | `obj.nameText` |
| infoPanel | infoPanel | DatapanelGUI | R | `obj.infoPanel` |
| updateTimer | updateTimer | number | RW | `obj.updateTimer = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| clear | clear | `` | `void` | `obj:clear()` |
| update | update | `` | `void` | `obj:update()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| updateInfo | updateInfo | `` | `void` | `obj:updateInfo()` |

## FactoryCallbackInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

## FarmBatch
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| plantSource | plantSource | lektor<FarmBuilding::PlantSource*> | R | `obj.plantSource` |
| plantGroups | plantGroups | lektor<int> | R | `obj.plantGroups` |
| geometry | geometry | Ogre::SharedPtr<Ogre::Mesh> | R | `obj.geometry` |
| height | height | number | RW | `obj.height = <value>` |
| size | size | integer | RW | `obj.size = <value>` |
| meshesLoaded | meshesLoaded | integer | RW | `obj.meshesLoaded = <value>` |
| farms | farms | lektor<FarmBuilding*> | R | `obj.farms` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| load | load | `` | `void` | `obj:load()` |
| createGeometry | createGeometry | `` | `void` | `obj:createGeometry()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FarmBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| cropMultipliers | cropMultipliers | ogre_unordered_map<CropType, float>::type | R | `obj.cropMultipliers` |
| material | material | Ogre::SharedPtr<Ogre::Material> | R | `obj.material` |
| plantEntity | (void* | lightuserdata | R | `obj.plantEntity` |
| plants | plants | lektor<FarmBuilding::Plant> | R | `obj.plants` |
| clickHull | (void* | lightuserdata | R | `obj.clickHull` |
| batch | (void* | lightuserdata | R | `obj.batch` |
| lastUpdated | lastUpdated | number | RW | `obj.lastUpdated = <value>` |
| eatingTime | eatingTime | number | RW | `obj.eatingTime = <value>` |
| grown | grown | number | RW | `obj.grown = <value>` |
| died | died | number | RW | `obj.died = <value>` |
| cleared | cleared | number | RW | `obj.cleared = <value>` |
| growStart | growStart | number | RW | `obj.growStart = <value>` |
| harvested | harvested | integer | RW | `obj.harvested = <value>` |
| itemsPerPlant | itemsPerPlant | number | RW | `obj.itemsPerPlant = <value>` |
| clearRate | clearRate | number | RW | `obj.clearRate = <value>` |
| consumptionRate | consumptionRate | number | RW | `obj.consumptionRate = <value>` |
| harvestRate | harvestRate | number | RW | `obj.harvestRate = <value>` |
| growthTime | growthTime | number | RW | `obj.growthTime = <value>` |
| harvestTime | harvestTime | number | RW | `obj.harvestTime = <value>` |
| deathTime | deathTime | number | RW | `obj.deathTime = <value>` |
| droughtTime | droughtTime | number | RW | `obj.droughtTime = <value>` |
| deathThreshold | deathThreshold | number | RW | `obj.deathThreshold = <value>` |
| droughtMultiplier | droughtMultiplier | number | RW | `obj.droughtMultiplier = <value>` |
| fertilityMultiplier | fertilityMultiplier | number | RW | `obj.fertilityMultiplier = <value>` |
| isHydroponic | isHydroponic | boolean | RW | `obj.isHydroponic = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| isAnyInputsEmpty | isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| isProductionFull | isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| howMuchPowerDoYouWantForSortingFunction | howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| _NV_howMuchPowerDoYouWantForSortingFunction | _NV_howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:_NV_howMuchPowerDoYouWantForSortingFunction()` |
| setupMiningResourceLevel | setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| _NV_setupMiningResourceLevel | _NV_setupMiningResourceLevel | `` | `void` | `obj:_NV_setupMiningResourceLevel()` |
| destroyAPlant | destroyAPlant | `` | `boolean` | `obj:destroyAPlant()` |
| timeSkip | timeSkip | `h: number, ignoreWater: boolean` | `void` | `obj:timeSkip(h, ignoreWater)` |
| _updateInputs | _updateInputs | `rate: number` | `boolean` | `obj:_updateInputs(rate)` |
| isCropsEdible | isCropsEdible | `` | `boolean` | `obj:isCropsEdible()` |
| eat | eat | `rate: number` | `void` | `obj:eat(rate)` |
| getDirectionMarker | getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| _NV_getDirectionMarker | _NV_getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getDirectionMarker(currentPosition)` |
| dontNeedWorkRightNow | dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| _NV_dontNeedWorkRightNow | _NV_dontNeedWorkRightNow | `` | `boolean` | `obj:_NV_dontNeedWorkRightNow()` |
| setupMaterial | setupMaterial | `` | `void` | `obj:setupMaterial()` |
| updateMaterial | updateMaterial | `` | `void` | `obj:updateMaterial()` |
| resetFarm | resetFarm | `` | `void` | `obj:resetFarm()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FlockingTools` | `obj:_CONSTRUCTOR()` |
| setCurrentPosition | setCurrentPosition | `_pos: Vector3` | `void` | `obj:setCurrentPosition(_pos)` |

## Footprint
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| wantsAboveGround | wantsAboveGround | boolean | RW | `obj.wantsAboveGround = <value>` |
| lower | lower | number | RW | `obj.lower = <value>` |
| space | space | number | RW | `obj.space = <value>` |
| scale | scale | number | RW | `obj.scale = <value>` |
| ent | (void* | lightuserdata | R | `obj.ent` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |
| groundType | (lua_Integer | integer | RW | `obj.groundType = <value>` |
| valid | valid | boolean | RW | `obj.valid = <value>` |
| parent | parent | PreviewBuilding | RW | `obj.parent = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getSpace | getSpace | `` | `number` | `obj:getSpace()` |
| getMarker | getMarker | `` | `number` | `obj:getMarker()` |
| setValid | setValid | `value: boolean` | `void` | `obj:setValid(value)` |
| getValid | getValid | `` | `boolean` | `obj:getValid()` |
| validate | validate | `` | `boolean` | `obj:validate()` |
| fakeOppositeValidate | fakeOppositeValidate | `gap: number` | `boolean` | `obj:fakeOppositeValidate(gap)` |
| collisionTestBuildings | collisionTestBuildings | `isFurniture: boolean, currentFloor: integer` | `boolean` | `obj:collisionTestBuildings(isFurniture, currentFloor)` |
| collisionTestCharacters | collisionTestCharacters | `` | `boolean` | `obj:collisionTestCharacters()` |
| validFloorTest | validFloorTest | `` | `boolean` | `obj:validFloorTest()` |
| isIndoorsOK | isIndoorsOK | `isFurniture: boolean` | `boolean` | `obj:isIndoorsOK(isFurniture)` |
| isGroundValid | isGroundValid | `` | `boolean` | `obj:isGroundValid()` |
| getWorldCorner | getWorldCorner | `corner: integer` | `Vector3` | `obj:getWorldCorner(corner)` |
| updateBox | updateBox | `` | `void` | `obj:updateBox()` |
| _NV_updateBox | _NV_updateBox | `` | `void` | `obj:_NV_updateBox()` |
| getGroundHeight | getGroundHeight | `pos: Vector3` | `number` | `obj:getGroundHeight(pos)` |

## FootprintNode
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nodeId | nodeId | string | RW | `obj.nodeId = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateBox | updateBox | `` | `void` | `obj:updateBox()` |
| _NV_updateBox | _NV_updateBox | `` | `void` | `obj:_NV_updateBox()` |
| setEnabled | setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ForgottenGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ForgottenGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| hasMouse | hasMouse | boolean | RW | `obj.hasMouse = <value>` |
| mainbar | (void* | lightuserdata | R | `obj.mainbar` |
| tooltip | (void* | lightuserdata | R | `obj.tooltip` |
| dialogue | dialogue | DialogueWindow | R | `obj.dialogue` |
| tutorial | (void* | lightuserdata | R | `obj.tutorial` |
| tutorialpedia | (void* | lightuserdata | R | `obj.tutorialpedia` |
| currentCursor | (lua_Integer | integer | RW | `obj.currentCursor = <value>` |
| manager | (void* | lightuserdata | R | `obj.manager` |
| guiPlatform | (void* | lightuserdata | R | `obj.guiPlatform` |
| _closeTradeWindowMsg | _closeTradeWindowMsg | boolean | RW | `obj._closeTradeWindowMsg = <value>` |
| characterEditor | (void* | lightuserdata | R | `obj.characterEditor` |
| cursorPanel | cursorPanel | DatapanelGUI | R | `obj.cursorPanel` |
| cursorAction | cursorAction | boolean | RW | `obj.cursorAction = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| created | created | boolean | RW | `obj.created = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearGUI | clearGUI | `` | `void` | `obj:clearGUI()` |
| shutDown | shutDown | `` | `void` | `obj:shutDown()` |
| restart | restart | `` | `void` | `obj:restart()` |
| setupGuiScaling | setupGuiScaling | `` | `void` | `obj:setupGuiScaling()` |
| init | init | `` | `void` | `obj:init()` |
| getTopOfScreenMessagePosition | getTopOfScreenMessagePosition | `` | `number` | `obj:getTopOfScreenMessagePosition()` |
| showLoadingMessage | showLoadingMessage | `on: boolean` | `void` | `obj:showLoadingMessage(on)` |
| isLoadingMessageVisible | isLoadingMessageVisible | `` | `boolean` | `obj:isLoadingMessageVisible()` |
| showPauseMessage | showPauseMessage | `on: boolean` | `void` | `obj:showPauseMessage(on)` |
| isLoading | isLoading | `` | `boolean` | `obj:isLoading()` |
| setLoading | setLoading | `value: boolean` | `void` | `obj:setLoading(value)` |
| isPaused | isPaused | `` | `boolean` | `obj:isPaused()` |
| inDialogue | inDialogue | `` | `boolean` | `obj:inDialogue()` |
| hideMessageBox | hideMessageBox | `enter: boolean` | `boolean` | `obj:hideMessageBox(enter)` |
| hasModalMessage | hasModalMessage | `` | `boolean` | `obj:hasModalMessage()` |
| showMainbar | showMainbar | `on: boolean` | `void` | `obj:showMainbar(on)` |
| updateBountyPanelVisibility | updateBountyPanelVisibility | `` | `void` | `obj:updateBountyPanelVisibility()` |
| getInDialogue | getInDialogue | `` | `boolean` | `obj:getInDialogue()` |
| getToolTip | getToolTip | `` | `lightuserdata` | `obj:getToolTip()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| toggle | toggle | `` | `void` | `obj:toggle()` |
| showNames | showNames | `on: boolean` | `void` | `obj:showNames(on)` |
| showPrintOutput | showPrintOutput | `v: boolean` | `void` | `obj:showPrintOutput(v)` |
| closeCharacterEditor | closeCharacterEditor | `` | `void` | `obj:closeCharacterEditor()` |
| isCharacterEditorMode | isCharacterEditorMode | `` | `boolean` | `obj:isCharacterEditorMode()` |
| closeAllCharacterStatsWindows | closeAllCharacterStatsWindows | `` | `void` | `obj:closeAllCharacterStatsWindows()` |
| isStatsWindowOpen | isStatsWindowOpen | `` | `boolean` | `obj:isStatsWindowOpen()` |
| characterStatsWindowVisible | characterStatsWindowVisible | `` | `boolean` | `obj:characterStatsWindowVisible()` |
| selectedObjectsChanged | selectedObjectsChanged | `` | `void` | `obj:selectedObjectsChanged()` |
| updateToOrdersPanel | updateToOrdersPanel | `` | `void` | `obj:updateToOrdersPanel()` |
| update | update | `` | `void` | `obj:update()` |
| closeTradeWindow | closeTradeWindow | `` | `void` | `obj:closeTradeWindow()` |
| closeInventoryBuilding | closeInventoryBuilding | `` | `void` | `obj:closeInventoryBuilding()` |
| closeAllInventories | closeAllInventories | `` | `void` | `obj:closeAllInventories()` |
| closeAllWindows | closeAllWindows | `` | `void` | `obj:closeAllWindows()` |
| getNumOpenInventoryWindows | getNumOpenInventoryWindows | `` | `integer` | `obj:getNumOpenInventoryWindows()` |
| getInventoryWindowWithMouse | getInventoryWindowWithMouse | `` | `lightuserdata` | `obj:getInventoryWindowWithMouse()` |
| isAnyInventoryWindowOpen | isAnyInventoryWindowOpen | `` | `boolean` | `obj:isAnyInventoryWindowOpen()` |
| toggleHelpWindow | toggleHelpWindow | `` | `void` | `obj:toggleHelpWindow()` |
| setMouseCursorVisible | setMouseCursorVisible | `visible: boolean` | `void` | `obj:setMouseCursorVisible(visible)` |
| getGuiManager | getGuiManager | `` | `lightuserdata` | `obj:getGuiManager()` |
| createPanel | createPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanel(name, top, left, width, height, layer, skin)` |
| createPanelAbs | createPanelAbs | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanelAbs(name, top, left, width, height, layer, skin)` |
| createTabPanel | createTabPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createTabPanel(name, top, left, width, height, layer, skin)` |
| createFloatingImage | createFloatingImage | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImage(image, top, left, width, height, layer)` |
| createFloatingImageAbs | createFloatingImageAbs | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImageAbs(image, top, left, width, height, layer)` |
| createFloatingProgressBar | createFloatingProgressBar | `` | `lightuserdata` | `obj:createFloatingProgressBar()` |
| createScreenLabelD | createScreenLabelD | `text: string, time: number` | `lightuserdata` | `obj:createScreenLabelD(text, time)` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| stopFormationMode | stopFormationMode | `` | `void` | `obj:stopFormationMode()` |

## FurnaceBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| active | active | boolean | RW | `obj.active = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| createInventoryLayout | createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| setupFromData | setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| getInputValueTotal | getInputValueTotal | `` | `number` | `obj:getInputValueTotal()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateInputs | updateInputs | `rate: number` | `void` | `obj:updateInputs(rate)` |
| _NV_updateInputs | _NV_updateInputs | `rate: number` | `void` | `obj:_NV_updateInputs(rate)` |
| updateOutput | updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| _NV_updateOutput | _NV_updateOutput | `rate: number` | `void` | `obj:_NV_updateOutput(rate)` |

## FurnaceInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `title: string, ins: integer, outs: integer` | `lightuserdata` | `obj:_CONSTRUCTOR(title, ins, outs)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GUIWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GUIWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| win | (void* | lightuserdata | R | `obj.win` |
| selectedObject | selectedObject | hand | RW | `obj.selectedObject = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GUIWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| _NV_clear | _NV_clear | `` | `void` | `obj:_NV_clear()` |
| show | show | `_a1: boolean` | `void` | `obj:show(_a1)` |
| setPositionReal | setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| _NV_setPositionReal | _NV_setPositionReal | `x: number, y: number` | `void` | `obj:_NV_setPositionReal(x, y)` |
| setPosition | setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| _NV_setPosition | _NV_setPosition | `x: integer, y: integer` | `void` | `obj:_NV_setPosition(x, y)` |
| getWidth | getWidth | `` | `integer` | `obj:getWidth()` |
| _NV_getWidth | _NV_getWidth | `` | `integer` | `obj:_NV_getWidth()` |
| getHeight | getHeight | `` | `integer` | `obj:getHeight()` |
| _NV_getHeight | _NV_getHeight | `` | `integer` | `obj:_NV_getHeight()` |
| getWidthReal | getWidthReal | `` | `number` | `obj:getWidthReal()` |
| _NV_getWidthReal | _NV_getWidthReal | `` | `number` | `obj:_NV_getWidthReal()` |
| getHeightReal | getHeightReal | `` | `number` | `obj:getHeightReal()` |
| _NV_getHeightReal | _NV_getHeightReal | `` | `number` | `obj:_NV_getHeightReal()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| getWidget | getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| resize | resize | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |
| _NV_resize | _NV_resize | `w: integer, h: integer` | `void` | `obj:_NV_resize(w, h)` |

## GameData
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| validity | validity | integer | RW | `obj.validity = <value>` |
| sourceContainer | sourceContainer | GameDataContainer | RW | `obj.sourceContainer = <value>` |
| isStandalone | isStandalone | boolean | RW | `obj.isStandalone = <value>` |
| id | id | integer | RW | `obj.id = <value>` |
| readOnly | readOnly | boolean | RW | `obj.readOnly = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| type | (lua_Integer | integer | RW | `obj.type = <value>` |
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| isFromActiveFile | isFromActiveFile | boolean | RW | `obj.isFromActiveFile = <value>` |
| instances | instances | InstancesMapBinding::MapType | RW | `obj.instances = <value>` |
| currentID | currentID | integer | RW | `obj.currentID = <value>` |
| activeValues | activeValues | ActiveValuesMapBinding::MapType | RW | `obj.activeValues = <value>` |
| bdata | bdata | ActiveValuesMapBinding::MapType | RW | `obj.bdata = <value>` |
| sdata | sdata | StringMapBinding::MapType | RW | `obj.sdata = <value>` |
| idata | idata | IntMapBinding::MapType | RW | `obj.idata = <value>` |
| fdata | fdata | FloatMapBinding::MapType | RW | `obj.fdata = <value>` |
| filesdata | filesdata | StringMapBinding::MapType | RW | `obj.filesdata = <value>` |
| vecdata | vecdata | Vector3MapBinding::MapType | RW | `obj.vecdata = <value>` |
| quatdata | quatdata | QuaternionMapBinding::MapType | RW | `obj.quatdata = <value>` |
| objectReferences | objectReferences | ObjectReferencesMapBinding::MapType | RW | `obj.objectReferences = <value>` |
| createdIndex | createdIndex | integer | RW | `obj.createdIndex = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameData` | `obj:_CONSTRUCTOR()` |
| isValid | isValid | `` | `boolean` | `obj:isValid()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| initialise | initialise | `t: integer, isActive: boolean` | `void` | `obj:initialise(t, isActive)` |
| loadFromFile | loadFromFile | `path: string, _type: integer` | `boolean` | `obj:loadFromFile(path, _type)` |
| saveToFile | saveToFile | `path: string` | `boolean` | `obj:saveToFile(path)` |
| isValueActive | isValueActive | `v: string` | `boolean` | `obj:isValueActive(v)` |
| isRefActive | isRefActive | `v: string` | `boolean` | `obj:isRefActive(v)` |
| addFileName | addFileName | `n: string, v: string, filestype: string, category: string, vis: boolean` | `void` | `obj:addFileName(n, v, filestype, category, vis)` |
| addString | addString | `n: string, v: string, category: string, vis: boolean` | `void` | `obj:addString(n, v, category, vis)` |
| addToList | addToList | `list: string, id: string, val: integer, val2: integer, val3: integer` | `void` | `obj:addToList(list, id, val, val2, val3)` |
| findInList | findInList | `list: string, SID: string` | `boolean` | `obj:findInList(list, SID)` |
| clearList | clearList | `n: string` | `void` | `obj:clearList(n)` |
| clearEverything | clearEverything | `` | `void` | `obj:clearEverything()` |
| clearInstances | clearInstances | `` | `void` | `obj:clearInstances()` |
| getListSize | getListSize | `n: string` | `integer` | `obj:getListSize(n)` |
| listExists | listExists | `n: string` | `boolean` | `obj:listExists(n)` |
| listExistsAndNotEmpty | listExistsAndNotEmpty | `n: string` | `boolean` | `obj:listExistsAndNotEmpty(n)` |
| deleteInstancedObject | deleteInstancedObject | `id: string, modIndex: integer` | `void` | `obj:deleteInstancedObject(id, modIndex)` |
| getNewID | getNewID | `` | `integer` | `obj:getNewID()` |
| getColorVec | getColorVec | `name: string` | `Vector3` | `obj:getColorVec(name)` |
| addDeletedInstance | addDeletedInstance | `instanceID: string` | `void` | `obj:addDeletedInstance(instanceID)` |
| getSourceContainer | getSourceContainer | `` | `GameDataContainer` | `obj:getSourceContainer()` |
| storeHandleList | storeHandleList | `name: string` | `void` | `obj:storeHandleList(name)` |
| getHandleList | getHandleList | `name: string` | `void` | `obj:getHandleList(name)` |
| storeHandle | storeHandle | `name: string, redirect: boolean` | `void` | `obj:storeHandle(name, redirect)` |
| getHandle | getHandle | `name: string` | `boolean` | `obj:getHandle(name)` |
| updateFrom | updateFrom | `mod: boolean` | `boolean` | `obj:updateFrom(mod)` |
| add | add | `n: string, num: number, category: string, vis: boolean, isSlider: boolean` | `void` | `obj:add(n, num, category, vis, isSlider)` |
| getGameDataReferenceObject | getGameDataReferenceObject | `list: string, id: string` | `GameDataReference` | `obj:getGameDataReferenceObject(list, id)` |
| removeFromList | removeFromList | `list: string, id: string` | `void` | `obj:removeFromList(list, id)` |
| getFromList | getFromList | `n: string, index: integer` | `string` | `obj:getFromList(n, index)` |
| getFromList_random | getFromList_random | `n: string` | `string` | `obj:getFromList_random(n)` |
| getAllFromList | getAllFromList | `n: string` | `void` | `obj:getAllFromList(n)` |
| getReferenceList | getReferenceList | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceList(listname)` |
| getReferenceListIfExists | getReferenceListIfExists | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceListIfExists(listname)` |
| _getReferenceList_nonConst | _getReferenceList_nonConst | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:_getReferenceList_nonConst(listname)` |
| getAllFromListAsDatas | getAllFromListAsDatas | `n: string, type: integer` | `void` | `obj:getAllFromListAsDatas(n, type)` |
| getFromListAsData | getFromListAsData | `n: string, index: integer, type: integer` | `GameData` | `obj:getFromListAsData(n, index, type)` |
| getValueFromList | getValueFromList | `n: string, index: integer` | `void` | `obj:getValueFromList(n, index)` |
| addSavedInstancedObject | addSavedInstancedObject | `id: string, refID: string, modIndex: integer, pos: Vector3, rot: Quaternion` | `void` | `obj:addSavedInstancedObject(id, refID, modIndex, pos, rot)` |
| getInstances | getInstances | `` | `void` | `obj:getInstances()` |
| getColor | getColor | `name: string` | `void` | `obj:getColor(name)` |
| setColor | setColor | `name: string, c: Vector3` | `void` | `obj:setColor(name, c)` |
| addANewInstancedObject | addANewInstancedObject | `saveState: userdata, offset: userdata` | `GameData::ObjectInstance` | `obj:addANewInstancedObject(saveState, offset)` |

## GameDataContainer
**Header:** `extern/KenshiLib/Include/kenshi/GameDataManager.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createNewData | createNewData | `type: integer, forceID: string, name: string` | `GameData` | `obj:createNewData(type, forceID, name)` |
| getDataByName | getDataByName | `dataName: string, category: integer` | `GameData` | `obj:getDataByName(dataName, category)` |
| removeAllDataOfType | removeAllDataOfType | `type: integer` | `void` | `obj:removeAllDataOfType(type)` |
| clearInstances | clearInstances | `` | `void` | `obj:clearInstances()` |
| clearButDontDestroy | clearButDontDestroy | `` | `void` | `obj:clearButDontDestroy()` |
| clearButDontDestroyPlatoons | clearButDontDestroyPlatoons | `` | `void` | `obj:clearButDontDestroyPlatoons()` |
| clearAndDestroy | clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| getNewID | getNewID | `` | `integer` | `obj:getNewID()` |
| preLoadAllReferencePtrs | preLoadAllReferencePtrs | `` | `void` | `obj:preLoadAllReferencePtrs()` |
| clearAllReferencePtrs | clearAllReferencePtrs | `` | `void` | `obj:clearAllReferencePtrs()` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |

## GameDataCopyStandalone
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataEditorWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| win | win | DatapanelGUI | R | `obj.win` |
| data | data | GameData | R | `obj.data` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| initDataValues | initDataValues | `` | `void` | `obj:initDataValues()` |

## GameDataGroup
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| g1 | g1 | GameData | R | `obj.g1` |
| g2 | g2 | GameData | R | `obj.g2` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataManager
**Header:** `extern/KenshiLib/Include/kenshi/GameDataManager.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| reloadGameData | reloadGameData | `filename: string, isActive: boolean, _baseData: boolean` | `boolean` | `obj:reloadGameData(filename, isActive, _baseData)` |
| postProcessingTheDatas | postProcessingTheDatas | `` | `void` | `obj:postProcessingTheDatas()` |
| getMapSector | getMapSector | `x: integer, y: integer` | `GameData` | `obj:getMapSector(x, y)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataReference
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| values | values | unknown | RW | `obj.values = <value>` |
| sid | sid | string | RW | `obj.sid = <value>` |
| ptr | ptr | GameData | R | `obj.ptr` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataValuePair
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | R | `obj.data` |
| val0 | val0 | integer | RW | `obj.val0 = <value>` |

## GameSaveState
**Header:** `extern/KenshiLib/Include/kenshi/GameSaveState.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| baseData | baseData | GameData | RW | `obj.baseData = <value>` |
| dataSource | dataSource | GameDataContainer | RW | `obj.dataSource = <value>` |
| firstTime | firstTime | boolean | RW | `obj.firstTime = <value>` |
| instance | instance | GameData::ObjectInstance | RW | `obj.instance = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |
| instanceID | instanceID | string | RW | `obj.instanceID = <value>` |
| states | states | StatesMapBinding::MapType | RW | `obj.states = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| generateNewInstanceID | generateNewInstanceID | `` | `void` | `obj:generateNewInstanceID()` |
| generateStateID | generateStateID | `type: integer` | `string` | `obj:generateStateID(type)` |
| createState | createState | `type: integer` | `GameData` | `obj:createState(type)` |
| hasState | hasState | `type: integer` | `boolean` | `obj:hasState(type)` |
| getState | getState | `type: integer` | `GameData` | `obj:getState(type)` |
| numStates | numStates | `` | `integer` | `obj:numStates()` |
| getPos | getPos | `` | `Vector3` | `obj:getPos()` |
| getRot | getRot | `` | `Quaternion` | `obj:getRot()` |
| getTheInstancesData | getTheInstancesData | `` | `GameData` | `obj:getTheInstancesData()` |
| createFromSerialisedInstanceData | createFromSerialisedInstanceData | `id: string` | `void` | `obj:createFromSerialisedInstanceData(id)` |
| addState | addState | `` | `void` | `obj:addState()` |
| getInstanceID | getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| isValid | isValid | `` | `boolean` | `obj:isValid()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| theFactory | theFactory | RootObjectFactory | R | `obj.theFactory` |
| factionMgr | factionMgr | FactionManager | R | `obj.factionMgr` |
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
| updatePortraitsMap | updatePortraitsMap | unknown | R | `obj.updatePortraitsMap` |
| dynamicDestroyBuildingsList | dynamicDestroyBuildingsList | lektor<hand> | R | `obj.dynamicDestroyBuildingsList` |
| destroyListAE | destroyListAE | ogre_unordered_set<AttachedEntity*>::type | R | `obj.destroyListAE` |
| destroyListOE | destroyListOE | ogre_unordered_set<Ogre::MovableObject*>::type | R | `obj.destroyListOE` |
| destroyListTBM | destroyListTBM | ogre_unordered_set<TownBuildingsManager*>::type | R | `obj.destroyListTBM` |
| frameSpeedMult | frameSpeedMult | number | RW | `obj.frameSpeedMult = <value>` |
| deathParade | deathParade | unknown | R | `obj.deathParade` |
| deathParadeWasMeddledWith | deathParadeWasMeddledWith | boolean | RW | `obj.deathParadeWasMeddledWith = <value>` |
| charUpdateListMain_inUse | charUpdateListMain_inUse | boolean | RW | `obj.charUpdateListMain_inUse = <value>` |
| charUpdateListMain | charUpdateListMain | ogre_unordered_set<Character*>::type | R | `obj.charUpdateListMain` |
| _AINonRenderThread | _AINonRenderThread | RenderTimeBackthread* | R | `obj._AINonRenderThread` |
| nestBatcherKillList | nestBatcherKillList | std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy > > | R | `obj.nestBatcherKillList` |
| killListPhase0 | killListPhase0 | ogre_unordered_set<RootObject*>::type | R | `obj.killListPhase0` |
| killListPhase1 | killListPhase1 | unknown | R | `obj.killListPhase1` |
| killListPhase2 | killListPhase2 | std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy > > | R | `obj.killListPhase2` |
| mainUpdateListRemovalQueue | mainUpdateListRemovalQueue | lektor<Character*> | R | `obj.mainUpdateListRemovalQueue` |
| timeStamper | timeStamper | SimpleTimeStamper | R | `obj.timeStamper` |
| zoneMgr | zoneMgr | ZoneManager | R | `obj.zoneMgr` |
| debugFlag | debugFlag | boolean | RW | `obj.debugFlag = <value>` |
| paused | paused | boolean | RW | `obj.paused = <value>` |
| gameResetting | gameResetting | boolean | RW | `obj.gameResetting = <value>` |
| audioThread | audioThread | AudioSystemGlobal* | R | `obj.audioThread` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| startUpThreads | startUpThreads | `` | `boolean` | `obj:startUpThreads()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameWorld` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resetGame | resetGame | `` | `void` | `obj:resetGame()` |
| _clearAndDestroyGameWorldStuff | _clearAndDestroyGameWorldStuff | `` | `void` | `obj:_clearAndDestroyGameWorldStuff()` |
| initialisation | initialisation | `` | `boolean` | `obj:initialisation()` |
| initialisationGameData | initialisationGameData | `` | `boolean` | `obj:initialisationGameData()` |
| dailyUpdates | dailyUpdates | `` | `void` | `obj:dailyUpdates()` |
| errorToLogReleaseMode | errorToLogReleaseMode | `msg: string` | `void` | `obj:errorToLogReleaseMode(msg)` |
| errorD | errorD | `msg: string` | `void` | `obj:errorD(msg)` |
| logToSave | logToSave | `msg: string` | `void` | `obj:logToSave(msg)` |
| log | log | `line: string` | `void` | `obj:log(line)` |
| flushKillList | flushKillList | `` | `void` | `obj:flushKillList()` |
| allThreadQueuesAreClear | allThreadQueuesAreClear | `` | `boolean` | `obj:allThreadQueuesAreClear()` |
| initBaseMods | initBaseMods | `` | `void` | `obj:initBaseMods()` |
| initModsList | initModsList | `` | `void` | `obj:initModsList()` |
| getModIndex | getModIndex | `modName: string` | `integer` | `obj:getModIndex(modName)` |
| getLightLevel | getLightLevel | `position: Vector3, floor: integer, inside: boolean` | `number` | `obj:getLightLevel(position, floor, inside)` |
| findValidSpawnPos | findValidSpawnPos | `pos: Vector3, centerArea: Vector3` | `boolean` | `obj:findValidSpawnPos(pos, centerArea)` |
| togglePause | togglePause | `on: boolean` | `void` | `obj:togglePause(on)` |
| getFrameSpeedMultiplier | getFrameSpeedMultiplier | `` | `number` | `obj:getFrameSpeedMultiplier()` |
| setFrameSpeedMultiplier | setFrameSpeedMultiplier | `m: number` | `void` | `obj:setFrameSpeedMultiplier(m)` |
| setGameSpeed | setGameSpeed | `speed: number, click: boolean` | `void` | `obj:setGameSpeed(speed, click)` |
| userPause | userPause | `p: boolean` | `void` | `obj:userPause(p)` |
| isPaused | isPaused | `` | `boolean` | `obj:isPaused()` |
| getCameraCenter | getCameraCenter | `` | `Vector3` | `obj:getCameraCenter()` |
| getCameraPos | getCameraPos | `` | `Vector3` | `obj:getCameraPos()` |
| fixNaNPosition | fixNaNPosition | `pos: Vector3` | `boolean` | `obj:fixNaNPosition(pos)` |
| getWindSpeed | getWindSpeed | `pos: Vector3` | `number` | `obj:getWindSpeed(pos)` |
| isLoadingFromASaveGame | isLoadingFromASaveGame | `` | `boolean` | `obj:isLoadingFromASaveGame()` |
| hideContextMenu | hideContextMenu | `` | `void` | `obj:hideContextMenu()` |
| showPlayerAMessage_withLog | showPlayerAMessage_withLog | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage_withLog(message, queued)` |
| showPlayerAMessage | showPlayerAMessage | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage(message, queued)` |
| showPlayerAMessageD | showPlayerAMessageD | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessageD(message, queued)` |
| mainLoop_GPUSensitiveStuff | mainLoop_GPUSensitiveStuff | `time: number` | `void` | `obj:mainLoop_GPUSensitiveStuff(time)` |
| _NV_mainLoop_GPUSensitiveStuff | _NV_mainLoop_GPUSensitiveStuff | `time: number` | `void` | `obj:_NV_mainLoop_GPUSensitiveStuff(time)` |
| clearPortaitsUpdate | clearPortaitsUpdate | `` | `void` | `obj:clearPortaitsUpdate()` |
| processSysMessages | processSysMessages | `` | `void` | `obj:processSysMessages()` |
| destroyDeathParade | destroyDeathParade | `` | `void` | `obj:destroyDeathParade()` |
| processKeys | processKeys | `` | `void` | `obj:processKeys()` |
| processThreadMessages | processThreadMessages | `` | `void` | `obj:processThreadMessages()` |
| charsUpdate | charsUpdate | `` | `void` | `obj:charsUpdate()` |
| charsUpdateUT | charsUpdateUT | `` | `void` | `obj:charsUpdateUT()` |
| charsUpdatePaused | charsUpdatePaused | `` | `void` | `obj:charsUpdatePaused()` |
| charsUpdateDeathParade | charsUpdateDeathParade | `` | `void` | `obj:charsUpdateDeathParade()` |
| threadSafeRagdollUpdates | threadSafeRagdollUpdates | `` | `void` | `obj:threadSafeRagdollUpdates()` |
| processAttachmentsKillList | processAttachmentsKillList | `` | `void` | `obj:processAttachmentsKillList()` |
| processKillList | processKillList | `forceImmediate: boolean` | `void` | `obj:processKillList(forceImmediate)` |
| processUpdateRemovalList | processUpdateRemovalList | `` | `void` | `obj:processUpdateRemovalList()` |
| loadAllPlatoons | loadAllPlatoons | `` | `void` | `obj:loadAllPlatoons()` |
| reCalculateFortificationInsideOutsideStateForAllCharacters | reCalculateFortificationInsideOutsideStateForAllCharacters | `` | `void` | `obj:reCalculateFortificationInsideOutsideStateForAllCharacters()` |
| getTimeStamp | getTimeStamp | `` | `number` | `obj:getTimeStamp()` |
| getTimeFromStamp_inGameHours | getTimeFromStamp_inGameHours | `stamp: number` | `number` | `obj:getTimeFromStamp_inGameHours(stamp)` |
| getLengthOfHourInRealSeconds | getLengthOfHourInRealSeconds | `` | `number` | `obj:getLengthOfHourInRealSeconds()` |
| getFromDeathParade | GameWorld_getFromDeathParade | `` | `Character` | `obj:getFromDeathParade()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameplayOptions` | `obj:_CONSTRUCTOR()` |
| reset | reset | `` | `void` | `obj:reset()` |
| getStarvationTimeInHours | getStarvationTimeInHours | `` | `number` | `obj:getStarvationTimeInHours()` |

## GatewayBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GatewayBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| reAnnounceGateToPathfinder | reAnnounceGateToPathfinder | `` | `void` | `obj:reAnnounceGateToPathfinder()` |
| postCreationPathfinderSetupStuff | postCreationPathfinderSetupStuff | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| _NV_postCreationPathfinderSetupStuff | _NV_postCreationPathfinderSetupStuff | `` | `void` | `obj:_NV_postCreationPathfinderSetupStuff()` |
| getPositionForWaypoint | getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| _NV_getPositionForWaypoint | _NV_getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:_NV_getPositionForWaypoint(from)` |
| getUseableStuff | getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| isGate | isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| _NV_isGate | _NV_isGate | `` | `GatewayBuilding` | `obj:_NV_isGate()` |
| isForSale | isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| setup | setup | `` | `void` | `obj:setup()` |
| _NV_setup | _NV_setup | `` | `void` | `obj:_NV_setup()` |
| getGateCodeAt | getGateCodeAt | `p: Vector3` | `integer` | `obj:getGateCodeAt(p)` |
| getOutsideGateCode | getOutsideGateCode | `` | `integer` | `obj:getOutsideGateCode()` |
| separatesAreas | separatesAreas | `` | `boolean` | `obj:separatesAreas()` |

## Gear
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isUniform | isUniform | Faction | RW | `obj.isUniform = <value>` |
| value | value | integer | RW | `obj.value = <value>` |
| crafter | crafter | string | RW | `obj.crafter = <value>` |
| level | level | number | RW | `obj.level = <value>` |
| level_0_100 | level_0_100 | integer | RW | `obj.level_0_100 = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isGear | isGear | `` | `Gear` | `obj:isGear()` |
| _NV_isGear | _NV_isGear | `` | `Gear` | `obj:_NV_isGear()` |
| getLevel01 | getLevel01 | `` | `number` | `obj:getLevel01()` |
| _NV_getLevel01 | _NV_getLevel01 | `` | `number` | `obj:_NV_getLevel01()` |
| getLevel | getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| isAFactionUniform | isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| _NV_isAFactionUniform | _NV_isAFactionUniform | `` | `Faction` | `obj:_NV_isAFactionUniform()` |
| isPlayerCrafted | isPlayerCrafted | `` | `boolean` | `obj:isPlayerCrafted()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setInventoryWeAreIn | setInventoryWeAreIn | `` | `void` | `obj:setInventoryWeAreIn()` |
| _NV_setInventoryWeAreIn | _NV_setInventoryWeAreIn | `` | `void` | `obj:_NV_setInventoryWeAreIn()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `_level: integer` | `Gear` | `obj:_CONSTRUCTOR(_level)` |
| _serialise | _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |

## GeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getPowerOutput | getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| _NV_getPowerOutput | _NV_getPowerOutput | `` | `number` | `obj:_NV_getPowerOutput()` |
| getFuelConsumptionRate | getFuelConsumptionRate | `` | `number` | `obj:getFuelConsumptionRate()` |
| _NV_getFuelConsumptionRate | _NV_getFuelConsumptionRate | `` | `number` | `obj:_NV_getFuelConsumptionRate()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GenericFixedInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| setSize | setSize | `slotsW: integer, slotsH: integer` | `void` | `obj:setSize(slotsW, slotsH)` |
| _NV_setSize | _NV_setSize | `slotsW: integer, slotsH: integer` | `void` | `obj:_NV_setSize(slotsW, slotsH)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GenericInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| arrangeButton | (void* | lightuserdata | R | `obj.arrangeButton` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setSize | setSize | `slotsW: integer, slotsH: integer, hasArrange: boolean, hasType: boolean` | `void` | `obj:setSize(slotsW, slotsH, hasArrange, hasType)` |
| _NV_setSize | _NV_setSize | `slotsW: integer, slotsH: integer, hasArrange: boolean, hasType: boolean` | `void` | `obj:_NV_setSize(slotsW, slotsH, hasArrange, hasType)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Global
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

## GlobalConstants
**Header:** `extern/KenshiLib/Include/kenshi/GlobalConstants.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER | EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER | number | RW | `obj.EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER = <value>` |
| BLEED_RATE_MULTIPLIER | BLEED_RATE_MULTIPLIER | number | RW | `obj.BLEED_RATE_MULTIPLIER = <value>` |
| INITIAL_BLEED_LOSS_MULTIPLIER | INITIAL_BLEED_LOSS_MULTIPLIER | number | RW | `obj.INITIAL_BLEED_LOSS_MULTIPLIER = <value>` |
| BLEED_CLOT_RATE | BLEED_CLOT_RATE | number | RW | `obj.BLEED_CLOT_RATE = <value>` |
| BLUNT_DAMAGE_1 | BLUNT_DAMAGE_1 | number | RW | `obj.BLUNT_DAMAGE_1 = <value>` |
| BLUNT_DAMAGE_99 | BLUNT_DAMAGE_99 | number | RW | `obj.BLUNT_DAMAGE_99 = <value>` |
| CUT_DAMAGE_1 | CUT_DAMAGE_1 | number | RW | `obj.CUT_DAMAGE_1 = <value>` |
| CUT_DAMAGE_99 | CUT_DAMAGE_99 | number | RW | `obj.CUT_DAMAGE_99 = <value>` |
| BOW_DAMAGE_0 | BOW_DAMAGE_0 | number | RW | `obj.BOW_DAMAGE_0 = <value>` |
| BOW_DAMAGE_99 | BOW_DAMAGE_99 | number | RW | `obj.BOW_DAMAGE_99 = <value>` |
| PIERCE_MULTIPLIER | PIERCE_MULTIPLIER | number | RW | `obj.PIERCE_MULTIPLIER = <value>` |
| MIN_STUMBLE_DAMAGE_MAX | MIN_STUMBLE_DAMAGE_MAX | number | RW | `obj.MIN_STUMBLE_DAMAGE_MAX = <value>` |
| DAMAGE_RESISTANCE_MIN | DAMAGE_RESISTANCE_MIN | number | RW | `obj.DAMAGE_RESISTANCE_MIN = <value>` |
| DAMAGE_RESISTANCE_MAX | DAMAGE_RESISTANCE_MAX | number | RW | `obj.DAMAGE_RESISTANCE_MAX = <value>` |
| STUN_RECOVERY_RATE | STUN_RECOVERY_RATE | number | RW | `obj.STUN_RECOVERY_RATE = <value>` |
| BLOOD_RECOVERY_RATE | BLOOD_RECOVERY_RATE | number | RW | `obj.BLOOD_RECOVERY_RATE = <value>` |
| ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR | ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR | number | RW | `obj.ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR = <value>` |
| BASE_BLOCK_CHANCE | BASE_BLOCK_CHANCE | number | RW | `obj.BASE_BLOCK_CHANCE = <value>` |
| BLOCK_CHANCE_REDUCTION | BLOCK_CHANCE_REDUCTION | number | RW | `obj.BLOCK_CHANCE_REDUCTION = <value>` |
| BLOCK_CHANCE_INCREASE | BLOCK_CHANCE_INCREASE | number | RW | `obj.BLOCK_CHANCE_INCREASE = <value>` |
| DEGENERATION_MULT_1 | DEGENERATION_MULT_1 | number | RW | `obj.DEGENERATION_MULT_1 = <value>` |
| DEGENERATION_MULT_99 | DEGENERATION_MULT_99 | number | RW | `obj.DEGENERATION_MULT_99 = <value>` |
| MEDIC_SPEED_MULT | MEDIC_SPEED_MULT | number | RW | `obj.MEDIC_SPEED_MULT = <value>` |
| KNOCKOUT_MULT_1 | KNOCKOUT_MULT_1 | number | RW | `obj.KNOCKOUT_MULT_1 = <value>` |
| KNOCKOUT_MULT_99 | KNOCKOUT_MULT_99 | number | RW | `obj.KNOCKOUT_MULT_99 = <value>` |
| KNOCKOUT_BASE_TIME | KNOCKOUT_BASE_TIME | number | RW | `obj.KNOCKOUT_BASE_TIME = <value>` |
| BODYPART_DEGENERATE_RATE_MULT | BODYPART_DEGENERATE_RATE_MULT | number | RW | `obj.BODYPART_DEGENERATE_RATE_MULT = <value>` |
| BODYPART_HEAL_RATE_MULT | BODYPART_HEAL_RATE_MULT | number | RW | `obj.BODYPART_HEAL_RATE_MULT = <value>` |
| BODYPART_HEAL_RATE_MULT_RESTING | BODYPART_HEAL_RATE_MULT_RESTING | number | RW | `obj.BODYPART_HEAL_RATE_MULT_RESTING = <value>` |
| XP_MEDIC_1 | XP_MEDIC_1 | number | RW | `obj.XP_MEDIC_1 = <value>` |
| XP_MEDIC_99 | XP_MEDIC_99 | number | RW | `obj.XP_MEDIC_99 = <value>` |
| MEDKIT_DRAIN_1 | MEDKIT_DRAIN_1 | number | RW | `obj.MEDKIT_DRAIN_1 = <value>` |
| MEDKIT_DRAIN_99 | MEDKIT_DRAIN_99 | number | RW | `obj.MEDKIT_DRAIN_99 = <value>` |
| ROBOT_WEAR_RATE | ROBOT_WEAR_RATE | number | RW | `obj.ROBOT_WEAR_RATE = <value>` |
| ROBOT_FIRST_AID_SPEED | ROBOT_FIRST_AID_SPEED | number | RW | `obj.ROBOT_FIRST_AID_SPEED = <value>` |
| STARVATION_TIME_HRS | STARVATION_TIME_HRS | number | RW | `obj.STARVATION_TIME_HRS = <value>` |
| FED_RECOVERY_RATE_MULT | FED_RECOVERY_RATE_MULT | number | RW | `obj.FED_RECOVERY_RATE_MULT = <value>` |
| BED_HUNGER_RATE | BED_HUNGER_RATE | number | RW | `obj.BED_HUNGER_RATE = <value>` |
| ENCUMBRANCE_HUNGER_RATE | ENCUMBRANCE_HUNGER_RATE | number | RW | `obj.ENCUMBRANCE_HUNGER_RATE = <value>` |
| FOOD_QUALITY_MULT | FOOD_QUALITY_MULT | number | RW | `obj.FOOD_QUALITY_MULT = <value>` |
| FOOD_PRICE_MULT | FOOD_PRICE_MULT | number | RW | `obj.FOOD_PRICE_MULT = <value>` |
| SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS | SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS | number | RW | `obj.SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS = <value>` |
| SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY | SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY | number | RW | `obj.SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY = <value>` |
| XP_HIT_THEM | XP_HIT_THEM | number | RW | `obj.XP_HIT_THEM = <value>` |
| XP_HIT_ME | XP_HIT_ME | number | RW | `obj.XP_HIT_ME = <value>` |
| XP_BLOCKED_THEM | XP_BLOCKED_THEM | number | RW | `obj.XP_BLOCKED_THEM = <value>` |
| XP_BLOCKED_ME | XP_BLOCKED_ME | number | RW | `obj.XP_BLOCKED_ME = <value>` |
| XP_FIRSTAID | XP_FIRSTAID | number | RW | `obj.XP_FIRSTAID = <value>` |
| XP_FITNESS | XP_FITNESS | number | RW | `obj.XP_FITNESS = <value>` |
| XP_TOUGHNESS | XP_TOUGHNESS | number | RW | `obj.XP_TOUGHNESS = <value>` |
| PRICE_ROBOTICS | PRICE_ROBOTICS | number | RW | `obj.PRICE_ROBOTICS = <value>` |
| PRICE_CROSSBOWS | PRICE_CROSSBOWS | number | RW | `obj.PRICE_CROSSBOWS = <value>` |
| PRICE_ARMOUR | PRICE_ARMOUR | number | RW | `obj.PRICE_ARMOUR = <value>` |
| PRICE_SWORDS | PRICE_SWORDS | number | RW | `obj.PRICE_SWORDS = <value>` |
| PRICE_TRADE | PRICE_TRADE | number | RW | `obj.PRICE_TRADE = <value>` |
| PRICE_GLOBAL_MULT | PRICE_GLOBAL_MULT | number | RW | `obj.PRICE_GLOBAL_MULT = <value>` |
| PRICE_CLOTHING | PRICE_CLOTHING | number | RW | `obj.PRICE_CLOTHING = <value>` |
| TRADE_PROFIT_MARGINS | TRADE_PROFIT_MARGINS | number | RW | `obj.TRADE_PROFIT_MARGINS = <value>` |
| PRICE_LOOT_GEAR | PRICE_LOOT_GEAR | number | RW | `obj.PRICE_LOOT_GEAR = <value>` |
| PRICE_LOOT_ITEMS | PRICE_LOOT_ITEMS | number | RW | `obj.PRICE_LOOT_ITEMS = <value>` |
| PRICE_LOOT_PLAYER_CRAFTED_ARMOUR | PRICE_LOOT_PLAYER_CRAFTED_ARMOUR | number | RW | `obj.PRICE_LOOT_PLAYER_CRAFTED_ARMOUR = <value>` |
| PRICE_LOOT_PLAYER_CRAFTED_WEAPONS | PRICE_LOOT_PLAYER_CRAFTED_WEAPONS | number | RW | `obj.PRICE_LOOT_PLAYER_CRAFTED_WEAPONS = <value>` |
| BLUEPRINT_COST_MULT | BLUEPRINT_COST_MULT | number | RW | `obj.BLUEPRINT_COST_MULT = <value>` |
| UNIFORM_PRICE_MULT | UNIFORM_PRICE_MULT | number | RW | `obj.UNIFORM_PRICE_MULT = <value>` |
| BLUNT_PERMANENT_DAMAGE_RATIO | BLUNT_PERMANENT_DAMAGE_RATIO | number | RW | `obj.BLUNT_PERMANENT_DAMAGE_RATIO = <value>` |
| UNARMED_DAMAGE_MULT | UNARMED_DAMAGE_MULT | number | RW | `obj.UNARMED_DAMAGE_MULT = <value>` |
| MAX_NUM_ATTACK_SLOTS | MAX_NUM_ATTACK_SLOTS | integer | RW | `obj.MAX_NUM_ATTACK_SLOTS = <value>` |
| MINIMUM_STRENGTH_XP_MULT | MINIMUM_STRENGTH_XP_MULT | number | RW | `obj.MINIMUM_STRENGTH_XP_MULT = <value>` |
| WEIGHT_STR_DIFF_1X | WEIGHT_STR_DIFF_1X | number | RW | `obj.WEIGHT_STR_DIFF_1X = <value>` |
| WEIGHT_STR_DIFF_MAX | WEIGHT_STR_DIFF_MAX | number | RW | `obj.WEIGHT_STR_DIFF_MAX = <value>` |
| WEAPON_INVENTORY_WEIGHT_MULT | WEAPON_INVENTORY_WEIGHT_MULT | number | RW | `obj.WEAPON_INVENTORY_WEIGHT_MULT = <value>` |
| STRENGTH_XP_RATE_FROM_WALKING | STRENGTH_XP_RATE_FROM_WALKING | number | RW | `obj.STRENGTH_XP_RATE_FROM_WALKING = <value>` |
| STRENGTH_XP_RATE | STRENGTH_XP_RATE | number | RW | `obj.STRENGTH_XP_RATE = <value>` |
| ATHLETICS_XP_RATE | ATHLETICS_XP_RATE | number | RW | `obj.ATHLETICS_XP_RATE = <value>` |
| ENCUMBRANCE_BASE | ENCUMBRANCE_BASE | number | RW | `obj.ENCUMBRANCE_BASE = <value>` |
| CARRY_WEIGHT_MULT | CARRY_WEIGHT_MULT | number | RW | `obj.CARRY_WEIGHT_MULT = <value>` |
| CARRY_PERSON_WEIGHT | CARRY_PERSON_WEIGHT | number | RW | `obj.CARRY_PERSON_WEIGHT = <value>` |
| MIN_MATS_FROM_DISMANTLE_01 | MIN_MATS_FROM_DISMANTLE_01 | number | RW | `obj.MIN_MATS_FROM_DISMANTLE_01 = <value>` |
| EXPERIENCE_GAIN | EXPERIENCE_GAIN | number | RW | `obj.EXPERIENCE_GAIN = <value>` |
| EXPERIENCE_GAIN_1 | EXPERIENCE_GAIN_1 | number | RW | `obj.EXPERIENCE_GAIN_1 = <value>` |
| EXPERIENCE_GAIN_99 | EXPERIENCE_GAIN_99 | number | RW | `obj.EXPERIENCE_GAIN_99 = <value>` |
| RESEARCH_LEVEL_INCREASE | RESEARCH_LEVEL_INCREASE | number | RW | `obj.RESEARCH_LEVEL_INCREASE = <value>` |
| RESEARCH_RATE | RESEARCH_RATE | number | RW | `obj.RESEARCH_RATE = <value>` |
| LOCKPICK_CHANCE_MINIMUM | LOCKPICK_CHANCE_MINIMUM | number | RW | `obj.LOCKPICK_CHANCE_MINIMUM = <value>` |
| EXPERIENCE_CURVE | EXPERIENCE_CURVE | number | RW | `obj.EXPERIENCE_CURVE = <value>` |
| ANIMATION_BLEND_RATE | ANIMATION_BLEND_RATE | number | RW | `obj.ANIMATION_BLEND_RATE = <value>` |
| PRODUCTION_MULTIPLIER | PRODUCTION_MULTIPLIER | number | RW | `obj.PRODUCTION_MULTIPLIER = <value>` |
| BUILD_SPEED_MULTIPLIER | BUILD_SPEED_MULTIPLIER | number | RW | `obj.BUILD_SPEED_MULTIPLIER = <value>` |
| PRISON_TIME_MULT | PRISON_TIME_MULT | number | RW | `obj.PRISON_TIME_MULT = <value>` |
| TOUGHNESS_KO_POINT_MIN | TOUGHNESS_KO_POINT_MIN | number | RW | `obj.TOUGHNESS_KO_POINT_MIN = <value>` |
| TOUGHNESS_KO_POINT_MAX | TOUGHNESS_KO_POINT_MAX | number | RW | `obj.TOUGHNESS_KO_POINT_MAX = <value>` |
| MAX_SQUAD_SIZE | MAX_SQUAD_SIZE | integer | RW | `obj.MAX_SQUAD_SIZE = <value>` |
| MAX_SQUADS | MAX_SQUADS | integer | RW | `obj.MAX_SQUADS = <value>` |
| MAX_FACTION_SIZE | MAX_FACTION_SIZE | integer | RW | `obj.MAX_FACTION_SIZE = <value>` |
| attackDiplomats | attackDiplomats | boolean | RW | `obj.attackDiplomats = <value>` |
| settings | settings | GameData | R | `obj.settings` |
| APPEARANCE_RANDOM_DEVIATION | APPEARANCE_RANDOM_DEVIATION | number | RW | `obj.APPEARANCE_RANDOM_DEVIATION = <value>` |
| fogDistMax | fogDistMax | number | RW | `obj.fogDistMax = <value>` |
| fogDistMin | fogDistMin | number | RW | `obj.fogDistMin = <value>` |

## HasRoomCache
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| itemStates | itemStates | std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > | R | `obj.itemStates` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| modified | modified | `` | `void` | `obj:modified()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| robotLimb | robotLimb | RobotLimbItem | RW | `obj.robotLimb = <value>` |
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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isRobotic | isRobotic | `` | `boolean` | `obj:isRobotic()` |
| getData | getData | `` | `GameData` | `obj:getData()` |
| getRobotLimbEnum | getRobotLimbEnum | `` | `integer` | `obj:getRobotLimbEnum()` |
| update | update | `frameTIME: number, healMultFlesh: number, healMultRobot: number, degenerationRate: number, _age: number, robotWear: number` | `boolean` | `obj:update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear)` |
| updateDerivedHealths | updateDerivedHealths | `` | `void` | `obj:updateDerivedHealths()` |
| getWorstDamage | getWorstDamage | `brokenBoneValue: number` | `number` | `obj:getWorstDamage(brokenBoneValue)` |
| getExtraBleedingAmount | getExtraBleedingAmount | `` | `number` | `obj:getExtraBleedingAmount()` |
| isDead | isDead | `` | `boolean` | `obj:isDead()` |
| getBloodynessMult | getBloodynessMult | `` | `number` | `obj:getBloodynessMult()` |
| maxHealth | maxHealth | `` | `number` | `obj:maxHealth()` |
| healthAsPercent | healthAsPercent | `healt: number` | `number` | `obj:healthAsPercent(healt)` |
| serialise | serialise | `num: integer` | `void` | `obj:serialise(num)` |
| load | load | `num: integer` | `void` | `obj:load(num)` |
| setup | setup | `_hitchance: number, _max: number, _age: number, selfHeal: boolean` | `void` | `obj:setup(_hitchance, _max, _age, selfHeal)` |
| applyDamage | applyDamage | `` | `void` | `obj:applyDamage()` |
| applyWearDamage | applyWearDamage | `` | `void` | `obj:applyWearDamage()` |
| getRobotLimbState | getRobotLimbState | `` | `integer` | `obj:getRobotLimbState()` |
| setRobotLimbItem | setRobotLimbItem | `isLoadingASave: boolean` | `void` | `obj:setRobotLimbItem(isLoadingASave)` |

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
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`

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
| mPos | mPos | number | RW | `obj.mPos = <value>` |
| mPosAbs | mPosAbs | number | RW | `obj.mPosAbs = <value>` |
| mSpeed | mSpeed | Vector3 | RW | `obj.mSpeed = <value>` |
| mWheel | mWheel | integer | RW | `obj.mWheel = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getKeyUTF8 | getKeyUTF8 | `key: integer` | `string` | `obj:getKeyUTF8(key)` |
| parseKey | parseKey | `s: string` | `integer` | `obj:parseKey(s)` |
| keyDownEvent | keyDownEvent | `key: integer` | `void` | `obj:keyDownEvent(key)` |
| keyUpEvent | keyUpEvent | `key: integer` | `void` | `obj:keyUpEvent(key)` |
| clearMessages | clearMessages | `` | `void` | `obj:clearMessages()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `InputHandler` | `obj:_CONSTRUCTOR()` |
| initialise | initialise | `` | `void` | `obj:initialise()` |
| bind | bind | `name: string, key: integer` | `void` | `obj:bind(name, key)` |
| unbindAll | unbindAll | `` | `void` | `obj:unbindAll()` |
| isKeyState | isKeyState | `command: string` | `boolean` | `obj:isKeyState(command)` |
| getMode | getMode | `command: string` | `integer` | `obj:getMode(command)` |
| sendEvent | sendEvent | `name: string` | `void` | `obj:sendEvent(name)` |
| loadConfig | loadConfig | `` | `void` | `obj:loadConfig()` |
| saveConfig | saveConfig | `` | `void` | `obj:saveConfig()` |
| keyString | keyString | `key: integer, translated: boolean` | `string` | `obj:keyString(key, translated)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getCommand | getCommand | `s: string` | `lightuserdata` | `obj:getCommand(s)` |
| addCommand | addCommand | `name: string, value: integer, key: integer, alt: integer, masks: integer, mode: integer` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| unbind | unbind | `cmd: string, mode: integer` | `void` | `obj:unbind(cmd, mode)` |
| isBound | isBound | `cmd: string` | `boolean` | `obj:isBound(cmd)` |
| getBoundKeys | getBoundKeys | `command: string` | `integer` | `obj:getBoundKeys(command)` |

## InstanceID
**Header:** `extern/KenshiLib/Include/kenshi/InstanceID.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| uid | uid | string | RW | `obj.uid = <value>` |
| baseIndex | baseIndex | integer | RW | `obj.baseIndex = <value>` |
| modIndex | modIndex | integer | RW | `obj.modIndex = <value>` |
| modified | modified | boolean | RW | `obj.modified = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| assign | assign | `id: string` | `void` | `obj:assign(id)` |
| clear | clear | `` | `void` | `obj:clear()` |
| needsSaving | needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| notifyChange | notifyChange | `` | `void` | `obj:notifyChange()` |
| hasChanges | hasChanges | `` | `boolean` | `obj:hasChanges()` |
| notifySaved | notifySaved | `mod: string` | `void` | `obj:notifySaved(mod)` |
| empty | empty | `` | `boolean` | `obj:empty()` |
| getBaseIndex | getBaseIndex | `` | `integer` | `obj:getBaseIndex()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Inventory
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| hasRoomCache | hasRoomCache | Inventory::HasRoomCache | RW | `obj.hasRoomCache = <value>` |
| _allItems | _allItems | lektor<Item*> | R | `obj._allItems` |
| sections | second | InventorySection | R | `obj.sections` |
| sectionsInSearchOrder | sectionsInSearchOrder | lektor<InventorySection*> | R | `obj.sectionsInSearchOrder` |
| callbackObject | callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
| owner | owner | RootObject | RW | `obj.owner = <value>` |
| totalWeight | totalWeight | number | RW | `obj.totalWeight = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAll | clearAll | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAll(destroy, skipUnique)` |
| notifyModified | notifyModified | `` | `void` | `obj:notifyModified()` |
| initialiseNewSection | initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| _NV_initialiseNewSection | _NV_initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:_NV_initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| removeAllSections | removeAllSections | `` | `void` | `obj:removeAllSections()` |
| getSection | getSection | `name: string` | `InventorySection` | `obj:getSection(name)` |
| getSectionOfType | getSectionOfType | `type: integer` | `InventorySection` | `obj:getSectionOfType(type)` |
| resizeSection | resizeSection | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resizeSection(w, h, clearContent)` |
| getCallbackCharacter | getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| hasItemType | hasItemType | `item: integer, skipEquipped: boolean` | `boolean` | `obj:hasItemType(item, skipEquipped)` |
| hasStolenItems | hasStolenItems | `` | `boolean` | `obj:hasStolenItems()` |
| getSecondaryWeapon | getSecondaryWeapon | `` | `Weapon` | `obj:getSecondaryWeapon()` |
| getPrimaryWeapon | getPrimaryWeapon | `` | `Weapon` | `obj:getPrimaryWeapon()` |
| hasItemFunction | hasItemFunction | `type: integer` | `boolean` | `obj:hasItemFunction(type)` |
| getBestItemWithFunction | getBestItemWithFunction | `type: integer` | `Item` | `obj:getBestItemWithFunction(type)` |
| hasWeaponEquipped | hasWeaponEquipped | `` | `boolean` | `obj:hasWeaponEquipped()` |
| isAContainer | isAContainer | `` | `boolean` | `obj:isAContainer()` |
| getOwner | getOwner | `` | `RootObject` | `obj:getOwner()` |
| isEmpty | isEmpty | `` | `boolean` | `obj:isEmpty()` |
| recalculateTotalWeight | recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| getTotalWeight | getTotalWeight | `` | `number` | `obj:getTotalWeight()` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| takeMoney | takeMoney | `val: integer` | `void` | `obj:takeMoney(val)` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| refreshGui | refreshGui | `` | `void` | `obj:refreshGui()` |
| _NV_refreshGui | _NV_refreshGui | `` | `void` | `obj:_NV_refreshGui()` |
| autoArrange | autoArrange | `` | `void` | `obj:autoArrange()` |
| getCallbackObject | getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| getHandle | getHandle | `` | `hand` | `obj:getHandle()` |
| addItem | addItem | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:addItem(quantity, dropOnFail, destroyOnFail)` |
| _NV_addItem | _NV_addItem | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_addItem(quantity, dropOnFail, destroyOnFail)` |
| tryAddItem | tryAddItem | `quantity: integer` | `boolean` | `obj:tryAddItem(quantity)` |
| _NV_tryAddItem | _NV_tryAddItem | `quantity: integer` | `boolean` | `obj:_NV_tryAddItem(quantity)` |
| removeItemDontDestroy_returnsItem | removeItemDontDestroy_returnsItem | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| _NV_removeItemDontDestroy_returnsItem | _NV_removeItemDontDestroy_returnsItem | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:_NV_removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| removeItemAutoDestroy | removeItemAutoDestroy | `howmany: integer` | `boolean` | `obj:removeItemAutoDestroy(howmany)` |
| _NV_removeItemAutoDestroy | _NV_removeItemAutoDestroy | `howmany: integer` | `boolean` | `obj:_NV_removeItemAutoDestroy(howmany)` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| getItem | getItem | `` | `Item` | `obj:getItem()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Inventory` | `obj:_CONSTRUCTOR()` |
| serialise | serialise | `` | `GameData` | `obj:serialise()` |
| loadFrom | loadFrom | `` | `void` | `obj:loadFrom()` |
| fillFromVendorList | fillFromVendorList | `` | `void` | `obj:fillFromVendorList()` |
| getAllSectionsOfType | getAllSectionsOfType | `type: integer` | `void` | `obj:getAllSectionsOfType(type)` |
| getAllSections | getAllSections | `` | `lektor<InventorySection*>` | `obj:getAllSections()` |
| getExcessLoot | getExcessLoot | `justAsking: boolean` | `boolean` | `obj:getExcessLoot(justAsking)` |
| getResourceItems | getResourceItems | `buildingMatsToo: boolean` | `void` | `obj:getResourceItems(buildingMatsToo)` |
| getNumItems | getNumItems | `` | `integer` | `obj:getNumItems()` |
| hasRoomForItem | hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| transferMouseItem | transferMouseItem | `` | `boolean` | `obj:transferMouseItem()` |
| hasItem | hasItem | `quantity: integer` | `boolean` | `obj:hasItem(quantity)` |
| countItems | countItems | `` | `integer` | `obj:countItems()` |
| getAllStolenItems | getAllStolenItems | `includeUnknown: boolean` | `void` | `obj:getAllStolenItems(includeUnknown)` |
| getAllItemsOfType | getAllItemsOfType | `ty: integer, skipEquipped: boolean` | `void` | `obj:getAllItemsOfType(ty, skipEquipped)` |
| getEquippedWeapons | getEquippedWeapons | `` | `void` | `obj:getEquippedWeapons()` |
| getEquippedArmour | getEquippedArmour | `` | `void` | `obj:getEquippedArmour()` |
| takeOneItemOnly | takeOneItemOnly | `` | `Item` | `obj:takeOneItemOnly()` |
| deathCheck | deathCheck | `` | `boolean` | `obj:deathCheck()` |
| takeItem_EntireStack | takeItem_EntireStack | `` | `Item` | `obj:takeItem_EntireStack()` |
| getAllItemsWithFunction | getAllItemsWithFunction | `type: integer` | `void` | `obj:getAllItemsWithFunction(type)` |
| getBestItemWithLowestCharges | getBestItemWithLowestCharges | `type: integer` | `Item` | `obj:getBestItemWithLowestCharges(type)` |
| getBestFoodItem | getBestFoodItem | `` | `Item` | `obj:getBestFoodItem()` |
| getNumFoodItems | getNumFoodItems | `` | `integer` | `obj:getNumFoodItems()` |
| _getBestFoodItem | _getBestFoodItem | `type: integer` | `Item` | `obj:_getBestFoodItem(type)` |
| _getNumFoodItems | _getNumFoodItems | `type: integer` | `integer` | `obj:_getNumFoodItems(type)` |
| equipItem | equipItem | `` | `boolean` | `obj:equipItem()` |
| buyItem | buyItem | `` | `Item` | `obj:buyItem()` |
| getInventoryGUI | getInventoryGUI | `` | `lightuserdata` | `obj:getInventoryGUI()` |
| _sectionAddItemCallback | _sectionAddItemCallback | `` | `void` | `obj:_sectionAddItemCallback()` |
| _NV__sectionAddItemCallback | _NV__sectionAddItemCallback | `` | `void` | `obj:_NV__sectionAddItemCallback()` |
| _sectionUpdateItemCallback | _sectionUpdateItemCallback | `quantity: integer` | `void` | `obj:_sectionUpdateItemCallback(quantity)` |
| _NV__sectionUpdateItemCallback | _NV__sectionUpdateItemCallback | `quantity: integer` | `void` | `obj:_NV__sectionUpdateItemCallback(quantity)` |
| _sectionRemoveItemCallback | _sectionRemoveItemCallback | `` | `void` | `obj:_sectionRemoveItemCallback()` |
| _NV__sectionRemoveItemCallback | _NV__sectionRemoveItemCallback | `` | `void` | `obj:_NV__sectionRemoveItemCallback()` |
| _addToList | _addToList | `` | `void` | `obj:_addToList()` |
| _NV__addToList | _NV__addToList | `` | `void` | `obj:_NV__addToList()` |
| _removeFromList | _removeFromList | `checkEverything: boolean` | `void` | `obj:_removeFromList(checkEverything)` |
| _NV__removeFromList | _NV__removeFromList | `checkEverything: boolean` | `void` | `obj:_NV__removeFromList(checkEverything)` |
| getAllItems | getAllItems | `` | `lektor<Item*>` | `obj:getAllItems()` |

## InventoryGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| layoutMgr | (void* | lightuserdata | R | `obj.layoutMgr` |
| ownerInventory | (void* | lightuserdata | R | `obj.ownerInventory` |
| childInventory | (void* | lightuserdata | R | `obj.childInventory` |
| mouseFocus | mouseFocus | boolean | RW | `obj.mouseFocus = <value>` |
| callbackObject | callbackObject | RootObject | R | `obj.callbackObject` |
| needItemsUpdate | needItemsUpdate | boolean | RW | `obj.needItemsUpdate = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| show | show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| setPositionReal | setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| _NV_setPositionReal | _NV_setPositionReal | `x: number, y: number` | `void` | `obj:_NV_setPositionReal(x, y)` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| showBackpack | showBackpack | `on: boolean` | `void` | `obj:showBackpack(on)` |
| getBackpack | getBackpack | `` | `ContainerItem` | `obj:getBackpack()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| getCallbackCharacter | getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| _NV_getCallbackCharacter | _NV_getCallbackCharacter | `` | `Character` | `obj:_NV_getCallbackCharacter()` |
| getCallbackObject | getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _NV_getCallbackObject | _NV_getCallbackObject | `` | `RootObject` | `obj:_NV_getCallbackObject()` |
| getSelectedItem | getSelectedItem | `sectionName: string` | `Item` | `obj:getSelectedItem(sectionName)` |
| stealingGUIInfoUpdate | stealingGUIInfoUpdate | `` | `void` | `obj:stealingGUIInfoUpdate()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| pickupItemToMouse | pickupItemToMouse | `sectionName: string` | `boolean` | `obj:pickupItemToMouse(sectionName)` |
| getMouseItem | getMouseItem | `` | `Item` | `obj:getMouseItem()` |
| fencingConfirmationCallback | fencingConfirmationCallback | `b: integer` | `void` | `obj:fencingConfirmationCallback(b)` |
| getPlayerTradeCharacter | getPlayerTradeCharacter | `` | `RootObject` | `obj:getPlayerTradeCharacter()` |
| refreshAllSections | refreshAllSections | `` | `void` | `obj:refreshAllSections()` |
| updateDatapanel | updateDatapanel | `` | `void` | `obj:updateDatapanel()` |
| rightClickAutoEquipping | rightClickAutoEquipping | `` | `void` | `obj:rightClickAutoEquipping()` |
| hasMouse | hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getSectionWithMouseLocal | getSectionWithMouseLocal | `` | `string` | `obj:getSectionWithMouseLocal()` |

## InventoryIcon
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| item | item | Item | R | `obj.item` |
| image | (void* | lightuserdata | R | `obj.image` |
| quantityText | (void* | lightuserdata | R | `obj.quantityText` |
| chargesProgress | (void* | lightuserdata | R | `obj.chargesProgress` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | update | `` | `void` | `obj:update()` |
| getWidget | getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| deactivate | deactivate | `` | `void` | `obj:deactivate()` |
| resetAfterCopy | resetAfterCopy | `` | `void` | `obj:resetAfterCopy()` |
| resetCharges | resetCharges | `randomise: boolean` | `void` | `obj:resetCharges(randomise)` |
| getItemType | getItemType | `` | `integer` | `obj:getItemType()` |
| getItemWeightSingle | getItemWeightSingle | `` | `number` | `obj:getItemWeightSingle()` |
| _NV_getItemWeightSingle | _NV_getItemWeightSingle | `` | `number` | `obj:_NV_getItemWeightSingle()` |
| getItemWeight | getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _NV_getItemWeight | _NV_getItemWeight | `` | `number` | `obj:_NV_getItemWeight()` |
| getAvgPrice | getAvgPrice | `` | `integer` | `obj:getAvgPrice()` |
| getValueSingle | getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| getValueAll | getValueAll | `isPlayer: boolean` | `integer` | `obj:getValueAll(isPlayer)` |
| _NV_getValueAll | _NV_getValueAll | `isPlayer: boolean` | `integer` | `obj:_NV_getValueAll(isPlayer)` |
| getMaxAffordableNum | getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:getMaxAffordableNum(cashLimit, isPlayer)` |
| _NV_getMaxAffordableNum | _NV_getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:_NV_getMaxAffordableNum(cashLimit, isPlayer)` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| onGround | onGround | `` | `boolean` | `obj:onGround()` |
| isResearchArtifact | isResearchArtifact | `` | `boolean` | `obj:isResearchArtifact()` |
| getLevel | getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| getItemSound | getItemSound | `` | `string` | `obj:getItemSound()` |
| isStolen | isStolen | `includeUnknown: boolean` | `boolean` | `obj:isStolen(includeUnknown)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| merchantPriceMod | merchantPriceMod | `` | `number` | `obj:merchantPriceMod()` |

## InventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| datapanel | datapanel | DatapanelGUI | R | `obj.datapanel` |
| window | (void* | lightuserdata | R | `obj.window` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `file: string` | `lightuserdata` | `obj:_CONSTRUCTOR(file)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWindow | getWindow | `` | `lightuserdata` | `obj:getWindow()` |
| getWidget | getWidget | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| getDatapanel | getDatapanel | `` | `DatapanelGUI` | `obj:getDatapanel()` |
| _NV_getDatapanel | _NV_getDatapanel | `` | `DatapanelGUI` | `obj:_NV_getDatapanel()` |
| setupDataPanelInfos | setupDataPanelInfos | `name: string` | `void` | `obj:setupDataPanelInfos(name)` |
| setSectionGUIDisabled | setSectionGUIDisabled | `sectionName: string, width: integer, height: integer` | `void` | `obj:setSectionGUIDisabled(sectionName, width, height)` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `name: string, w: integer, h: integer, slot: integer, containerSlot: boolean, equipSlot: boolean, enabled: boolean` | `InventorySection` | `obj:_CONSTRUCTOR(name, w, h, slot, containerSlot, equipSlot, enabled)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| notifyModified | notifyModified | `` | `void` | `obj:notifyModified()` |
| getItemAt | getItemAt | `x: integer, y: integer` | `Item` | `obj:getItemAt(x, y)` |
| hasRoomForItem | hasRoomForItem | `quantity: integer` | `boolean` | `obj:hasRoomForItem(quantity)` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `quantity: integer` | `boolean` | `obj:_NV_hasRoomForItem(quantity)` |
| hasItem | hasItem_Item | `` | `boolean` | `obj:hasItem()` |
| hasItem | hasItem_GameData | `` | `boolean` | `obj:hasItem()` |
| hasItemType | hasItemType | `type: integer` | `boolean` | `obj:hasItemType(type)` |
| autoArrange | autoArrange | `` | `void` | `obj:autoArrange()` |
| _NV_autoArrange | _NV_autoArrange | `` | `void` | `obj:_NV_autoArrange()` |
| getNumItems | getNumItems | `` | `integer` | `obj:getNumItems()` |
| isEmpty | isEmpty | `` | `boolean` | `obj:isEmpty()` |
| clearAllItems | clearAllItems | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAllItems(destroy, skipUnique)` |
| getLimitedSlot | getLimitedSlot | `` | `integer` | `obj:getLimitedSlot()` |
| applyStackingBonuses | applyStackingBonuses | `normalStackableAmount: integer` | `integer` | `obj:applyStackingBonuses(normalStackableAmount)` |
| recalculateTotalWeight | recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| setWeightMultiplier | setWeightMultiplier | `mult: number` | `void` | `obj:setWeightMultiplier(mult)` |
| setStackingBonus | setStackingBonus | `minn: integer, mult: number` | `void` | `obj:setStackingBonus(minn, mult)` |
| getMaxStack | getMaxStack | `` | `integer` | `obj:getMaxStack()` |
| clearVeryLimitedSlot | clearVeryLimitedSlot | `` | `void` | `obj:clearVeryLimitedSlot()` |
| getEnabled | getEnabled | `` | `boolean` | `obj:getEnabled()` |
| setEnabled | setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| setItemsLimitCount | setItemsLimitCount | `value: integer` | `void` | `obj:setItemsLimitCount(value)` |
| getItemsLimitReached | getItemsLimitReached | `` | `boolean` | `obj:getItemsLimitReached()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| getFillPercentage | getFillPercentage | `` | `number` | `obj:getFillPercentage()` |
| getItem | getItem | `` | `Item` | `obj:getItem()` |
| resize | resize | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resize(w, h, clearContent)` |
| addItem | addItem | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |
| _NV_addItem | _NV_addItem | `quantity: integer` | `boolean` | `obj:_NV_addItem(quantity)` |
| removeItem | removeItem | `` | `boolean` | `obj:removeItem()` |
| canItemGoHere | canItemGoHere | `x: integer, y: integer` | `boolean` | `obj:canItemGoHere(x, y)` |
| existsItemInFootprint | existsItemInFootprint | `x: integer, y: integer` | `boolean` | `obj:existsItemInFootprint(x, y)` |
| isLimitedSlotCompatible | isLimitedSlotCompatible | `` | `boolean` | `obj:isLimitedSlotCompatible()` |
| getValidInventoryPosition | getValidInventoryPosition | `` | `boolean|integer` | `obj:getValidInventoryPosition()` |

## InventorySectionGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| widget | (void* | lightuserdata | R | `obj.widget` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| hasMouse | hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getWidget | getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| setEnabled | setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| update | update | `` | `void` | `obj:update()` |

## InventoryTradeData
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| inventory | (void* | lightuserdata | R | `obj.inventory` |
| paymentRequired | paymentRequired | boolean | RW | `obj.paymentRequired = <value>` |
| canDropItems | canDropItems | boolean | RW | `obj.canDropItems = <value>` |
| isPlayer | isPlayer | boolean | RW | `obj.isPlayer = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isValid | isValid | `` | `boolean` | `obj:isValid()` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| physicalShouldExist | physicalShouldExist | boolean | RW | `obj.physicalShouldExist = <value>` |
| existAsBareWeapon | existAsBareWeapon | boolean | RW | `obj.existAsBareWeapon = <value>` |
| persistant | persistant | hand | RW | `obj.persistant = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| physical | (void* | lightuserdata | RW | `obj.physical = <value>` |
| _isPhysical | _isPhysical | boolean | RW | `obj._isPhysical = <value>` |
| physicalEntity | (void* | lightuserdata | RW | `obj.physicalEntity = <value>` |
| creatingPhysical | creatingPhysical | boolean | RW | `obj.creatingPhysical = <value>` |
| fixedPhysicalPosition | fixedPhysicalPosition | boolean | RW | `obj.fixedPhysicalPosition = <value>` |
| useDynamicPhysics | useDynamicPhysics | boolean | RW | `obj.useDynamicPhysics = <value>` |
| loadingEntity | (void* | lightuserdata | RW | `obj.loadingEntity = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isGear | isGear | `` | `Gear` | `obj:isGear()` |
| _NV_isGear | _NV_isGear | `` | `Gear` | `obj:_NV_isGear()` |
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| resetAfterCopy | resetAfterCopy | `` | `void` | `obj:resetAfterCopy()` |
| _NV_resetAfterCopy | _NV_resetAfterCopy | `` | `void` | `obj:_NV_resetAfterCopy()` |
| deactivate | deactivate | `` | `void` | `obj:deactivate()` |
| _NV_deactivate | _NV_deactivate | `` | `void` | `obj:_NV_deactivate()` |
| setPositionRotation | setPositionRotation | `position: Vector3, rotation: Quaternion, fixedPosition: boolean` | `void` | `obj:setPositionRotation(position, rotation, fixedPosition)` |
| _NV_setPositionRotation | _NV_setPositionRotation | `position: Vector3, rotation: Quaternion, fixedPosition: boolean` | `void` | `obj:_NV_setPositionRotation(position, rotation, fixedPosition)` |
| isCrossbow | isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| _NV_isCrossbow | _NV_isCrossbow | `` | `Crossbow` | `obj:_NV_isCrossbow()` |
| isArmour | isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| isWeapon | isWeapon | `` | `Weapon` | `obj:isWeapon()` |
| _NV_isWeapon | _NV_isWeapon | `` | `Weapon` | `obj:_NV_isWeapon()` |
| isLockedArmour | isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _NV_isLockedArmour | _NV_isLockedArmour | `` | `LockedArmour` | `obj:_NV_isLockedArmour()` |
| isAFactionUniform | isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| _NV_isAFactionUniform | _NV_isAFactionUniform | `` | `Faction` | `obj:_NV_isAFactionUniform()` |
| isPhysical | isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| getModelName | getModelName | `` | `string` | `obj:getModelName()` |
| _NV_getModelName | _NV_getModelName | `` | `string` | `obj:_NV_getModelName()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| hasIngredients | hasIngredients | `` | `boolean` | `obj:hasIngredients()` |
| _NV_hasIngredients | _NV_hasIngredients | `` | `boolean` | `obj:_NV_hasIngredients()` |
| isGoodFood | isGoodFood | `` | `boolean` | `obj:isGoodFood()` |
| _NV_isGoodFood | _NV_isGoodFood | `` | `boolean` | `obj:_NV_isGoodFood()` |
| getCraftTime | getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getCraftMaterialMult | getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| _NV_getCraftMaterialMult | _NV_getCraftMaterialMult | `` | `number` | `obj:_NV_getCraftMaterialMult()` |
| getLevel | getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| destroyItemEntityCallback_Equipping | destroyItemEntityCallback_Equipping | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| _NV_destroyItemEntityCallback_Equipping | _NV_destroyItemEntityCallback_Equipping | `` | `void` | `obj:_NV_destroyItemEntityCallback_Equipping()` |
| isPersistant | isPersistant | `` | `boolean` | `obj:isPersistant()` |
| persistantOwnerExists | persistantOwnerExists | `` | `boolean` | `obj:persistantOwnerExists()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| loadUnloadCheck | loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| getInventoryWeAreIn | getInventoryWeAreIn | `` | `hand` | `obj:getInventoryWeAreIn()` |
| setInventoryWeAreIn | setInventoryWeAreIn | `` | `void` | `obj:setInventoryWeAreIn()` |
| _NV_setInventoryWeAreIn | _NV_setInventoryWeAreIn | `` | `void` | `obj:_NV_setInventoryWeAreIn()` |
| isFood | isFood | `` | `boolean` | `obj:isFood()` |
| activate | activate | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| _NV_activate | _NV_activate | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:_NV_activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| getEntity | getEntity | `` | `lightuserdata` | `obj:getEntity()` |
| _NV_getEntity | _NV_getEntity | `` | `lightuserdata` | `obj:_NV_getEntity()` |
| getTimeout | getTimeout | `` | `TimeOfDay` | `obj:getTimeout()` |
| _NV_getTimeout | _NV_getTimeout | `` | `TimeOfDay` | `obj:_NV_getTimeout()` |
| _serialise | _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| serialise | serialise | `offset: userdata` | `GameSaveState` | `obj:serialise(offset)` |
| _NV_serialise | _NV_serialise | `offset: userdata` | `GameSaveState` | `obj:_NV_serialise(offset)` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| serialiseInInventory | serialiseInInventory | `` | `GameData` | `obj:serialiseInInventory()` |
| _NV_serialiseInInventory | _NV_serialiseInInventory | `` | `GameData` | `obj:_NV_serialiseInInventory()` |
| loadFromSerialiseInInventory | loadFromSerialiseInInventory | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| _NV_loadFromSerialiseInInventory | _NV_loadFromSerialiseInInventory | `` | `void` | `obj:_NV_loadFromSerialiseInInventory()` |
| createItemEntityCallback_Equipping | createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:createItemEntityCallback_Equipping(ent, node)` |
| _NV_createItemEntityCallback_Equipping | _NV_createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:_NV_createItemEntityCallback_Equipping(ent, node)` |
| notifyTheftFrom | notifyTheftFrom | `` | `void` | `obj:notifyTheftFrom()` |
| _NV_notifyTheftFrom | _NV_notifyTheftFrom | `` | `void` | `obj:_NV_notifyTheftFrom()` |
| findProperOwner | findProperOwner | `` | `hand` | `obj:findProperOwner()` |
| setPersistant | setPersistant | `p: boolean` | `void` | `obj:setPersistant(p)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Item` | `obj:_CONSTRUCTOR()` |
| itemEntityCreated | itemEntityCreated | `ent: userdata` | `void` | `obj:itemEntityCreated(ent)` |
| _NV_itemEntityCreated | _NV_itemEntityCreated | `ent: userdata` | `void` | `obj:_NV_itemEntityCreated(ent)` |

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

## LightBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/LightBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mountedBuilding | mountedBuilding | hand | R | `obj.mountedBuilding` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| getMouseCursor | getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| needPowerRightNow | needPowerRightNow | `` | `boolean` | `obj:needPowerRightNow()` |
| _NV_needPowerRightNow | _NV_needPowerRightNow | `` | `boolean` | `obj:_NV_needPowerRightNow()` |
| getPositionMarker | getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getPositionMarker(currentPosition)` |
| _NV_getPositionMarker | _NV_getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getPositionMarker(currentPosition)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## LimbsInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| character | character | Character | R | `obj.character` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Limiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| racesExclude | racesExclude | std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > | R | `obj.racesExclude` |
| racesInclude | racesInclude | std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > | R | `obj.racesInclude` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## LockedArmour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lock | lock | DoorLock* | R | `obj.lock` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isArmour | isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| isLockedArmour | isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _NV_isLockedArmour | _NV_isLockedArmour | `` | `LockedArmour` | `obj:_NV_isLockedArmour()` |

## MainBarGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| closeManagerWindowMsg | closeManagerWindowMsg | integer | RW | `obj.closeManagerWindowMsg = <value>` |
| isLevelEditMode | isLevelEditMode | boolean | RW | `obj.isLevelEditMode = <value>` |
| isInteriorLevelEditMode | isInteriorLevelEditMode | boolean | RW | `obj.isInteriorLevelEditMode = <value>` |
| bountyPanel | (void* | lightuserdata | R | `obj.bountyPanel` |
| bountyDatapanel | bountyDatapanel | DatapanelGUI | R | `obj.bountyDatapanel` |
| townPanel | (void* | lightuserdata | R | `obj.townPanel` |
| portraitsTabPanel | (void* | lightuserdata | R | `obj.portraitsTabPanel` |
| floorDownButton | (void* | lightuserdata | R | `obj.floorDownButton` |
| floorUpButton | (void* | lightuserdata | R | `obj.floorUpButton` |
| floorText | (void* | lightuserdata | R | `obj.floorText` |
| dayText | (void* | lightuserdata | R | `obj.dayText` |
| moneyLabel | (void* | lightuserdata | R | `obj.moneyLabel` |
| moneyText | (void* | lightuserdata | R | `obj.moneyText` |
| timeText | (void* | lightuserdata | R | `obj.timeText` |
| medicalPanel | (void* | lightuserdata | R | `obj.medicalPanel` |
| ordersDataPanel | (void* | lightuserdata | R | `obj.ordersDataPanel` |
| extendInfoPanelButton | (void* | lightuserdata | R | `obj.extendInfoPanelButton` |
| extendedInfoPanel | (void* | lightuserdata | RW | `obj.extendedInfoPanel = <value>` |
| extendedInfoPanelDuration | extendedInfoPanelDuration | number | RW | `obj.extendedInfoPanelDuration = <value>` |
| infoPanelEnabled | infoPanelEnabled | boolean | RW | `obj.infoPanelEnabled = <value>` |
| infoPanelExtended | infoPanelExtended | boolean | RW | `obj.infoPanelExtended = <value>` |
| biomePanel | (void* | lightuserdata | RW | `obj.biomePanel = <value>` |
| biomePanelText | (void* | lightuserdata | R | `obj.biomePanelText` |
| biomePanelVisibleTimer | biomePanelVisibleTimer | number | RW | `obj.biomePanelVisibleTimer = <value>` |
| biomeTimer | biomeTimer | number | RW | `obj.biomeTimer = <value>` |
| lastFrameBiomeGroup | lastFrameBiomeGroup | GameData | R | `obj.lastFrameBiomeGroup` |
| rememberlastBiomeGroup | rememberlastBiomeGroup | GameData | R | `obj.rememberlastBiomeGroup` |
| portraitContextMenuTimer | portraitContextMenuTimer | number | RW | `obj.portraitContextMenuTimer = <value>` |
| portraitSelectedContextIndex | portraitSelectedContextIndex | integer | RW | `obj.portraitSelectedContextIndex = <value>` |
| portraitsUpdating | portraitsUpdating | boolean | RW | `obj.portraitsUpdating = <value>` |
| toolTip | (void* | lightuserdata | R | `obj.toolTip` |
| pausePanel | (void* | lightuserdata | R | `obj.pausePanel` |
| loadingPanel | (void* | lightuserdata | R | `obj.loadingPanel` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| _NV_clear | _NV_clear | `` | `void` | `obj:_NV_clear()` |
| show | show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| speedChanged | speedChanged | `` | `void` | `obj:speedChanged()` |
| updateBountyPanelVisibility | updateBountyPanelVisibility | `` | `void` | `obj:updateBountyPanelVisibility()` |
| _NV_updateBountyPanelVisibility | _NV_updateBountyPanelVisibility | `` | `void` | `obj:_NV_updateBountyPanelVisibility()` |
| setLevelEditMode | setLevelEditMode | `on: boolean` | `void` | `obj:setLevelEditMode(on)` |
| setLevelEditInteriorMode | setLevelEditInteriorMode | `interiorMode: boolean` | `void` | `obj:setLevelEditInteriorMode(interiorMode)` |
| pressedKey | pressedKey | `keycode: integer` | `void` | `obj:pressedKey(keycode)` |
| updatePotraitsPlatoon | updatePotraitsPlatoon | `` | `void` | `obj:updatePotraitsPlatoon()` |
| updatePortraits | updatePortraits | `` | `void` | `obj:updatePortraits()` |
| refreshPortraitTabs | refreshPortraitTabs | `` | `void` | `obj:refreshPortraitTabs()` |
| getPausePanel | getPausePanel | `` | `lightuserdata` | `obj:getPausePanel()` |
| getLoadingPanel | getLoadingPanel | `` | `lightuserdata` | `obj:getLoadingPanel()` |
| getMedicalPanel | getMedicalPanel | `` | `lightuserdata` | `obj:getMedicalPanel()` |
| ordersPanelClear | ordersPanelClear | `` | `void` | `obj:ordersPanelClear()` |
| getToolTip | getToolTip | `` | `lightuserdata` | `obj:getToolTip()` |
| _NV_getToolTip | _NV_getToolTip | `` | `lightuserdata` | `obj:_NV_getToolTip()` |
| getDatapanel | getDatapanel | `id: string` | `DatapanelGUI` | `obj:getDatapanel(id)` |
| setMessagePosition | setMessagePosition | `` | `void` | `obj:setMessagePosition()` |
| setExtendInfoPanelEnabled | setExtendInfoPanelEnabled | `enabled: boolean` | `void` | `obj:setExtendInfoPanelEnabled(enabled)` |
| _getWidget | _getWidget | `name: string` | `lightuserdata` | `obj:_getWidget(name)` |

## MainTabPortraitPlatoon
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| portraitBox | (void* | lightuserdata | R | `obj.portraitBox` |
| platoon | platoon | ActivePlatoon | R | `obj.platoon` |
| tab | (void* | lightuserdata | RW | `obj.tab = <value>` |
| tabIndex | tabIndex | integer | RW | `obj.tabIndex = <value>` |
| flashImage | (void* | lightuserdata | R | `obj.flashImage` |
| flashing | flashing | integer | RW | `obj.flashing = <value>` |
| animationTime | animationTime | number | RW | `obj.animationTime = <value>` |
| currentAlpha | currentAlpha | number | RW | `obj.currentAlpha = <value>` |
| mainbar | (void* | lightuserdata | R | `obj.mainbar` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| detach | detach | `` | `void` | `obj:detach()` |
| setFlash | setFlash | `flash: boolean` | `void` | `obj:setFlash(flash)` |
| update | update | `` | `void` | `obj:update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MainthreadStateReaderT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateBackDataCheck | updateBackDataCheck | `` | `boolean` | `obj:updateBackDataCheck()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | setup | `numFrames: integer, numSamples: integer, _isPositionsFilter: boolean` | `void` | `obj:setup(numFrames, numSamples, _isPositionsFilter)` |
| reset | reset | `` | `void` | `obj:reset()` |
| applySilent | applySilent | `delta_mouse_x: number` | `void` | `obj:applySilent(delta_mouse_x)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedianFilter2DVector
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| filters | filters | MedianFilter | R | `obj.filters` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | setup | `numFrames: integer, numSamples: integer, positions: boolean` | `void` | `obj:setup(numFrames, numSamples, positions)` |
| reset | reset | `` | `void` | `obj:reset()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| precalculateFirstAidNeedScore | precalculateFirstAidNeedScore | `` | `void` | `obj:precalculateFirstAidNeedScore()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `MedicalSystem` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateStats | updateStats | `` | `void` | `obj:updateStats()` |
| _NV_updateStats | _NV_updateStats | `` | `void` | `obj:_NV_updateStats()` |
| medicalUpdate | medicalUpdate | `frameTime: number` | `void` | `obj:medicalUpdate(frameTime)` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| scoreFirstAidNeed | scoreFirstAidNeed | `robotAid: boolean` | `number` | `obj:scoreFirstAidNeed(robotAid)` |
| scoreJuryRigNeed | scoreJuryRigNeed | `skills: number` | `number` | `obj:scoreJuryRigNeed(skills)` |
| isFullyRested | isFullyRested | `` | `boolean` | `obj:isFullyRested()` |
| _setHealth | _setHealth | `bodypart: string, amount: number` | `void` | `obj:_setHealth(bodypart, amount)` |
| validateHealthValues | validateHealthValues | `` | `void` | `obj:validateHealthValues()` |
| amputate | amputate | `limb: integer, createSeveredItem: boolean, force: Vector3` | `void` | `obj:amputate(limb, createSeveredItem, force)` |
| crushLimb | crushLimb | `limb: integer` | `void` | `obj:crushLimb(limb)` |
| isUselessNoLimbGuy | isUselessNoLimbGuy | `` | `boolean` | `obj:isUselessNoLimbGuy()` |
| recalculateStealthHinderance | recalculateStealthHinderance | `` | `number` | `obj:recalculateStealthHinderance()` |
| getPartCount | getPartCount | `` | `integer` | `obj:getPartCount()` |
| hasRobotics | hasRobotics | `` | `boolean` | `obj:hasRobotics()` |
| isFed | isFed | `` | `boolean` | `obj:isFed()` |
| getMaxBlood | getMaxBlood | `` | `number` | `obj:getMaxBlood()` |
| startKnockoutTimer | startKnockoutTimer | `` | `void` | `obj:startKnockoutTimer()` |
| knockout | knockout | `skill01: number` | `void` | `obj:knockout(skill01)` |
| knockoutForceTimer | knockoutForceTimer | `seconds: number` | `void` | `obj:knockoutForceTimer(seconds)` |
| pointOfCollapseBloodloss | pointOfCollapseBloodloss | `` | `number` | `obj:pointOfCollapseBloodloss()` |
| pointOfNoReturn | pointOfNoReturn | `` | `number` | `obj:pointOfNoReturn()` |
| pointOfNoReturn_Hunger01 | pointOfNoReturn_Hunger01 | `mult: number` | `number` | `obj:pointOfNoReturn_Hunger01(mult)` |
| isHungerKO | isHungerKO | `` | `boolean` | `obj:isHungerKO()` |
| getToughnessXpBonus | getToughnessXpBonus | `` | `number` | `obj:getToughnessXpBonus()` |
| getHungerSpeedModifier | getHungerSpeedModifier | `` | `number` | `obj:getHungerSpeedModifier()` |
| getHealthStatModifier | getHealthStatModifier | `stat: integer, _hunger: boolean, _wounds: boolean, _darkness: boolean, robotParts: boolean, weather: boolean, gear: boolean` | `number` | `obj:getHealthStatModifier(stat, _hunger, _wounds, _darkness, robotParts, weather, gear)` |
| _getRoboticsStatMult | _getRoboticsStatMult | `stat: integer` | `number` | `obj:_getRoboticsStatMult(stat)` |
| getMissingArmPenaltyMult | getMissingArmPenaltyMult | `` | `number` | `obj:getMissingArmPenaltyMult()` |
| getDerivedHeadHealth | getDerivedHeadHealth | `` | `number` | `obj:getDerivedHeadHealth()` |
| calculateDesiredPainAnimations | calculateDesiredPainAnimations | `` | `void` | `obj:calculateDesiredPainAnimations()` |
| getMovementSpeedInjuryMultiplier | getMovementSpeedInjuryMultiplier | `` | `number` | `obj:getMovementSpeedInjuryMultiplier()` |
| getStatRoboticsMultiplier | getStatRoboticsMultiplier | `stat: integer` | `number` | `obj:getStatRoboticsMultiplier(stat)` |
| getMovementSwimSpeedInjuryMultiplier | getMovementSwimSpeedInjuryMultiplier | `` | `number` | `obj:getMovementSwimSpeedInjuryMultiplier()` |
| gettingEaten | gettingEaten | `amount: number, vampire: boolean` | `boolean` | `obj:gettingEaten(amount, vampire)` |
| gettingAcidRain | gettingAcidRain | `amount: number` | `boolean` | `obj:gettingAcidRain(amount)` |
| gettingAcidWater | gettingAcidWater | `amount: number` | `boolean` | `obj:gettingAcidWater(amount)` |
| gettingAcidFeet | gettingAcidFeet | `amount: number` | `boolean` | `obj:gettingAcidFeet(amount)` |
| gettingGassed | gettingGassed | `amount: number` | `boolean` | `obj:gettingGassed(amount)` |
| gettingWindyface | gettingWindyface | `amount: number` | `boolean` | `obj:gettingWindyface(amount)` |
| gettingBurnt | gettingBurnt | `amount: number` | `boolean` | `obj:gettingBurnt(amount)` |
| reassessCollapseMode | reassessCollapseMode | `medic: boolean, agony: boolean` | `void` | `obj:reassessCollapseMode(medic, agony)` |
| isUnconcious | isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| isCrippled | isCrippled | `` | `boolean` | `obj:isCrippled()` |
| isDead | isDead | `` | `boolean` | `obj:isDead()` |
| hasAnArmToFightWith | hasAnArmToFightWith | `` | `boolean` | `obj:hasAnArmToFightWith()` |
| hasFreshlySeveredALimb | hasFreshlySeveredALimb | `` | `boolean` | `obj:hasFreshlySeveredALimb()` |
| isReallyHungry | isReallyHungry | `` | `boolean` | `obj:isReallyHungry()` |
| isProbablyDying | isProbablyDying | `` | `boolean` | `obj:isProbablyDying()` |
| getOverallHealthRating | getOverallHealthRating | `` | `number` | `obj:getOverallHealthRating()` |
| canGetUpWakeUp | canGetUpWakeUp | `` | `boolean` | `obj:canGetUpWakeUp()` |
| _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll | _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll | `` | `void` | `obj:_reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll()` |
| isRightArmOk | isRightArmOk | `` | `boolean` | `obj:isRightArmOk()` |
| isLeftArmOk | isLeftArmOk | `` | `boolean` | `obj:isLeftArmOk()` |
| canIkick | canIkick | `` | `boolean` | `obj:canIkick()` |
| isInBloodlossTrauma | isInBloodlossTrauma | `` | `boolean` | `obj:isInBloodlossTrauma()` |
| clearWeatherEffects | clearWeatherEffects | `` | `void` | `obj:clearWeatherEffects()` |
| getWeatherStatPenaltyMult | getWeatherStatPenaltyMult | `` | `number` | `obj:getWeatherStatPenaltyMult()` |
| getWeatherStatPenalty | getWeatherStatPenalty | `mult: number` | `integer` | `obj:getWeatherStatPenalty(mult)` |
| calculateBleedRateForFX | calculateBleedRateForFX | `` | `number` | `obj:calculateBleedRateForFX()` |
| bloodlossUpdate | bloodlossUpdate | `frameTime: number` | `void` | `obj:bloodlossUpdate(frameTime)` |
| updateDamageState | updateDamageState | `` | `void` | `obj:updateDamageState()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MeshLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| skeletonName | skeletonName | string | RW | `obj.skeletonName = <value>` |
| materialName | materialName | string | RW | `obj.materialName = <value>` |
| renderQueue | renderQueue | integer | RW | `obj.renderQueue = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ModInfo
**Header:** `extern/KenshiLib/Include/kenshi/ModInfo.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MotionFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mWeightModifier | mWeightModifier | number | RW | `obj.mWeightModifier = <value>` |
| mHistoryBufferX | mHistoryBufferX | std::deque<float, std::allocator<float> > | R | `obj.mHistoryBufferX` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| SetHistoryBufferLength | SetHistoryBufferLength | `length: integer, fill: number` | `boolean` | `obj:SetHistoryBufferLength(length, fill)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MyGui
**Header:** `???`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setSize | widget_setSize | `width: integer, height: integer` | `void` | `obj:setSize(width, height)` |
| setPosition | widget_setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setCaption | widget_setCaption | `caption: string` | `void` | `obj:setCaption(caption)` |
| getCaption | widget_getCaption | `` | `string` | `obj:getCaption()` |
| setVisible | widget_setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | widget_getVisible | `` | `boolean` | `obj:getVisible()` |
| setEnabled | widget_setEnabled | `enabled: boolean` | `void` | `obj:setEnabled(enabled)` |
| getEnabled | widget_getEnabled | `` | `boolean` | `obj:getEnabled()` |
| getType | widget_getType | `` | `string` | `obj:getType()` |
| getName | widget_getName | `` | `string` | `obj:getName()` |
| destroy | widget_destroy | `` | `void` | `obj:destroy()` |
| findWidget | widget_findWidget | `name: string` | `MyGUI::Widget` | `obj:findWidget(name)` |
| getClientWidget | widget_getClientWidget | `` | `MyGUI::Widget` | `obj:getClientWidget()` |
| setProperty | widget_setProperty | `key: string, value: string` | `void` | `obj:setProperty(key, value)` |
| registerCallback | widget_registerCallback | `eventType: string` | `void` | `obj:registerCallback(eventType)` |
| getCoord | widget_getCoord | `` | `integer` | `obj:getCoord()` |
| setCoord | widget_setCoord | `left: integer, top: integer, width: integer, height: integer` | `void` | `obj:setCoord(left, top, width, height)` |
| setRealCoord | widget_setRealCoord | `left: number, top: number, width: number, height: number` | `void` | `obj:setRealCoord(left, top, width, height)` |
| setRealPosition | widget_setRealPosition | `left: number, top: number` | `void` | `obj:setRealPosition(left, top)` |
| setRealSize | widget_setRealSize | `width: number, height: number` | `void` | `obj:setRealSize(width, height)` |
| setPositionReal | widget_setRealCoord | `left: number, top: number, width: number, height: number` | `void` | `obj:setPositionReal(left, top, width, height)` |
| setCoordReal | widget_setRealCoord | `left: number, top: number, width: number, height: number` | `void` | `obj:setCoordReal(left, top, width, height)` |
| getPosition | widget_getPosition | `` | `integer` | `obj:getPosition()` |
| getSize | widget_getSize | `` | `integer` | `obj:getSize()` |
| getParent | widget_getParent | `` | `MyGUI::Widget` | `obj:getParent()` |
| detachFromWidget | widget_detachFromWidget | `layer: string` | `void` | `obj:detachFromWidget(layer)` |
| attachToWidget | widget_attachToWidget | `styleVal: integer, layer: string` | `void` | `obj:attachToWidget(styleVal, layer)` |
| setNeedKeyFocus | widget_setNeedKeyFocus | `need: boolean` | `void` | `obj:setNeedKeyFocus(need)` |
| setNeedMouseFocus | widget_setNeedMouseFocus | `need: boolean` | `void` | `obj:setNeedMouseFocus(need)` |
| setPointer | widget_setPointer | `ptrStr: string` | `void` | `obj:setPointer(ptrStr)` |
| setUserString | widget_setUserString | `key: string, value: string` | `void` | `obj:setUserString(key, value)` |
| getUserString | widget_getUserString | `key: string` | `string` | `obj:getUserString(key)` |
| isUserString | widget_isUserString | `key: string` | `boolean` | `obj:isUserString(key)` |
| clearUserString | widget_clearUserString | `key: string` | `void` | `obj:clearUserString(key)` |
| setStateSelected | widget_setStateSelected | `state: boolean` | `void` | `obj:setStateSelected(state)` |
| getStateSelected | widget_getStateSelected | `` | `boolean` | `obj:getStateSelected()` |
| setOnlyText | widget_setOnlyText | `text: string` | `void` | `obj:setOnlyText(text)` |
| getOnlyText | widget_getOnlyText | `` | `string` | `obj:getOnlyText()` |
| setEditReadOnly | widget_setEditReadOnly | `readOnly: boolean` | `void` | `obj:setEditReadOnly(readOnly)` |
| getEditReadOnly | widget_getEditReadOnly | `` | `boolean` | `obj:getEditReadOnly()` |
| setEditPassword | widget_setEditPassword | `pwd: boolean` | `void` | `obj:setEditPassword(pwd)` |
| getEditPassword | widget_getEditPassword | `` | `boolean` | `obj:getEditPassword()` |
| setEditMultiLine | widget_setEditMultiLine | `ml: boolean` | `void` | `obj:setEditMultiLine(ml)` |
| getEditMultiLine | widget_getEditMultiLine | `` | `boolean` | `obj:getEditMultiLine()` |
| setEditStatic | widget_setEditStatic | `st: boolean` | `void` | `obj:setEditStatic(st)` |
| getEditStatic | widget_getEditStatic | `` | `boolean` | `obj:getEditStatic()` |
| setPasswordChar | widget_setPasswordChar | `pwdChar: string` | `void` | `obj:setPasswordChar(pwdChar)` |
| getItemCount | widget_getItemCount | `` | `integer` | `obj:getItemCount()` |
| addItem | widget_addItem | `name: string` | `MyGUI::Widget` | `obj:addItem(name)` |
| insertItemAt | widget_insertItemAt | `idx: integer, name: string` | `MyGUI::Widget` | `obj:insertItemAt(idx, name)` |
| removeItemAt | widget_removeItemAt | `idx: integer` | `void` | `obj:removeItemAt(idx)` |
| removeAllItems | widget_removeAllItems | `` | `void` | `obj:removeAllItems()` |
| getIndexSelected | widget_getIndexSelected | `` | `integer` | `obj:getIndexSelected()` |
| setIndexSelected | widget_setIndexSelected | `idx: integer` | `void` | `obj:setIndexSelected(idx)` |
| clearIndexSelected | widget_clearIndexSelected | `` | `void` | `obj:clearIndexSelected()` |
| getItemNameAt | widget_getItemNameAt | `idx: integer` | `string` | `obj:getItemNameAt(idx)` |
| setItemNameAt | widget_setItemNameAt | `idx: integer, name: string` | `void` | `obj:setItemNameAt(idx, name)` |
| getOptimalHeight | widget_getOptimalHeight | `` | `integer` | `obj:getOptimalHeight()` |
| getWidgetByIndex | widget_getWidgetByIndex | `idx: integer` | `MyGUI::Widget` | `obj:getWidgetByIndex(idx)` |
| setMinSize | widget_setMinSize | `width: integer, height: integer` | `void` | `obj:setMinSize(width, height)` |
| getMinSize | widget_getMinSize | `` | `integer` | `obj:getMinSize()` |
| setMaxSize | widget_setMaxSize | `width: integer, height: integer` | `void` | `obj:setMaxSize(width, height)` |
| getMaxSize | widget_getMaxSize | `` | `integer` | `obj:getMaxSize()` |
| setVisibleSmooth | widget_setVisibleSmooth | `visible: boolean` | `void` | `obj:setVisibleSmooth(visible)` |
| destroySmooth | widget_destroySmooth | `` | `void` | `obj:destroySmooth()` |
| setMovable | widget_setMovable | `movable: boolean` | `void` | `obj:setMovable(movable)` |
| getMovable | widget_getMovable | `` | `boolean` | `obj:getMovable()` |
| setImageTexture | widget_setImageTexture | `texture: string` | `void` | `obj:setImageTexture(texture)` |
| setImageCoord | widget_setImageCoord | `x: integer, y: integer, width: integer, height: integer` | `void` | `obj:setImageCoord(x, y, width, height)` |
| setImageTile | widget_setImageTile | `width: integer, height: integer` | `void` | `obj:setImageTile(width, height)` |
| setImageIndex | widget_setImageIndex | `idx: integer` | `void` | `obj:setImageIndex(idx)` |
| getImageIndex | widget_getImageIndex | `` | `integer` | `obj:getImageIndex()` |

## NxUserControllerHitReport
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OpenSaveFileDialog
**Header:** `extern/KenshiLib/Include/kenshi/gui/OpenSaveFileDialog.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| filesList | (void* | lightuserdata | R | `obj.filesList` |
| fileNameTxt | (void* | lightuserdata | R | `obj.fileNameTxt` |
| currentFolderList | (void* | lightuserdata | R | `obj.currentFolderList` |
| openSaveButton | (void* | lightuserdata | R | `obj.openSaveButton` |
| currentFolder | currentFolder | string | RW | `obj.currentFolder = <value>` |
| fileName | fileName | string | RW | `obj.fileName = <value>` |
| fileMask | fileMask | string | RW | `obj.fileMask = <value>` |
| currentSelected | currentSelected | string | RW | `obj.currentSelected = <value>` |
| folderMode | folderMode | boolean | RW | `obj.folderMode = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setDialogInfo | setDialogInfo | `_caption: string, _button: string, _folderMode: boolean` | `void` | `obj:setDialogInfo(_caption, _button, _folderMode)` |
| setCurrentFolder | setCurrentFolder | `_folder: string` | `void` | `obj:setCurrentFolder(_folder)` |
| setFileName | setFileName | `_value: string` | `void` | `obj:setFileName(_value)` |
| setFileMask | setFileMask | `_value: string` | `void` | `obj:setFileMask(_value)` |
| update | update | `` | `void` | `obj:update()` |

## OptionsHolder
**Header:** `extern/KenshiLib/Include/kenshi/OptionsHolder.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| enabledCivilians | enabledCivilians | `` | `boolean` | `obj:enabledCivilians()` |
| characterMultithreadingEnabled | characterMultithreadingEnabled | `` | `boolean` | `obj:characterMultithreadingEnabled()` |
| compositiorEnabled | compositiorEnabled | `name: string` | `boolean` | `obj:compositiorEnabled(name)` |
| loadCompositorSettings | loadCompositorSettings | `` | `void` | `obj:loadCompositorSettings()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/OptionsWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| invertX | invertX | boolean | RW | `obj.invertX = <value>` |
| invertY | invertY | boolean | RW | `obj.invertY = <value>` |
| resolutionIndex | resolutionIndex | integer | RW | `obj.resolutionIndex = <value>` |
| keyConfig | keyConfig | DataPanelLine_KeyConfig | R | `obj.keyConfig` |
| keysDatapanel | keysDatapanel | DatapanelGUI | R | `obj.keysDatapanel` |
| tabs | (void* | lightuserdata | R | `obj.tabs` |
| created | created | boolean | RW | `obj.created = <value>` |
| tooltip | (void* | lightuserdata | R | `obj.tooltip` |
| previewFontSize | previewFontSize | boolean | RW | `obj.previewFontSize = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _NV_show | _NV_show | `value: boolean` | `void` | `obj:_NV_show(value)` |
| hide | hide | `` | `void` | `obj:hide()` |
| toggle | toggle | `` | `void` | `obj:toggle()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| waitingForKey | waitingForKey | `` | `boolean` | `obj:waitingForKey()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| saveOptions | saveOptions | `` | `void` | `obj:saveOptions()` |
| create | create | `` | `void` | `obj:create()` |
| updateResolutions | updateResolutions | `` | `void` | `obj:updateResolutions()` |

## OrderCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| orderText | (void* | lightuserdata | R | `obj.orderText` |
| removeButton | (void* | lightuserdata | R | `obj.removeButton` |
| data | (void* | lightuserdata | R | `obj.data` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWidget | getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| resize | resize | `` | `void` | `obj:resize()` |

## OrderData
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| task | task | Tasker | R | `obj.task` |
| index | index | integer | RW | `obj.index = <value>` |
| text | text | string | RW | `obj.text = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| updateText | updateText | `` | `void` | `obj:updateText()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OrdersItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OrdersPanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| ordersItemBox | (void* | lightuserdata | RW | `obj.ordersItemBox = <value>` |
| ordersItemWidth | ordersItemWidth | integer | RW | `obj.ordersItemWidth = <value>` |
| ordersItemBoxScrollBarSize | ordersItemBoxScrollBarSize | integer | RW | `obj.ordersItemBoxScrollBarSize = <value>` |
| ordersItemBoxMaxVisible | ordersItemBoxMaxVisible | integer | RW | `obj.ordersItemBoxMaxVisible = <value>` |
| ordersEmptyPanel | (void* | lightuserdata | R | `obj.ordersEmptyPanel` |
| blocksCheckbox | (void* | lightuserdata | R | `obj.blocksCheckbox` |
| holdCheckBox | (void* | lightuserdata | R | `obj.holdCheckBox` |
| passiveCheckBox | (void* | lightuserdata | R | `obj.passiveCheckBox` |
| chaseCheckBox | (void* | lightuserdata | R | `obj.chaseCheckBox` |
| tauntCheckBox | (void* | lightuserdata | R | `obj.tauntCheckBox` |
| rangedCheckBox | (void* | lightuserdata | R | `obj.rangedCheckBox` |
| stealthCheckBox | (void* | lightuserdata | R | `obj.stealthCheckBox` |
| speedPrevButton | (void* | lightuserdata | R | `obj.speedPrevButton` |
| speedNextButton | (void* | lightuserdata | R | `obj.speedNextButton` |
| speedImagePanel | (void* | lightuserdata | R | `obj.speedImagePanel` |
| speedImageNamesIdx | speedImageNamesIdx | integer | RW | `obj.speedImageNamesIdx = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| command | command | `cmd: integer` | `void` | `obj:command(cmd)` |
| refreshOrders | refreshOrders | `` | `void` | `obj:refreshOrders()` |
| moveJob | moveJob | `orderIdx: integer, targetIdx: integer` | `void` | `obj:moveJob(orderIdx, targetIdx)` |
| setSpeed | setSpeed | `moveSpeed: integer` | `void` | `obj:setSpeed(moveSpeed)` |
| setSpeedImage | setSpeedImage | `moveSpeed: integer` | `void` | `obj:setSpeedImage(moveSpeed)` |

## Ownerships
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| takeMoney | takeMoney | `val: integer` | `boolean` | `obj:takeMoney(val)` |
| _NV_takeMoney | _NV_takeMoney | `val: integer` | `boolean` | `obj:_NV_takeMoney(val)` |
| takeMoneyByForce | takeMoneyByForce | `val: integer` | `void` | `obj:takeMoneyByForce(val)` |
| _NV_takeMoneyByForce | _NV_takeMoneyByForce | `val: integer` | `void` | `obj:_NV_takeMoneyByForce(val)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| addMoney | addMoney | `amount: integer` | `void` | `obj:addMoney(amount)` |
| setMoney | setMoney | `amount: integer` | `void` | `obj:setMoney(amount)` |
| setHomeBuildingDesignation | setHomeBuildingDesignation | `d: integer` | `void` | `obj:setHomeBuildingDesignation(d)` |
| getOccupiedTownFaction | getOccupiedTownFaction | `` | `Faction` | `obj:getOccupiedTownFaction()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ParticlePool
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| limit | limit | integer | RW | `obj.limit = <value>` |
| lastIndex | lastIndex | integer | RW | `obj.lastIndex = <value>` |
| particles | (void* | lightuserdata | R | `obj.particles` |
| maxTTL | maxTTL | number | RW | `obj.maxTTL = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `limit: integer, ttl: number` | `lightuserdata` | `obj:_CONSTRUCTOR(limit, ttl)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | init | `` | `void` | `obj:init()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| getSize | getSize | `` | `integer` | `obj:getSize()` |
| update | update | `` | `void` | `obj:update()` |
| shiftParticles | shiftParticles | `shift: Vector3` | `void` | `obj:shiftParticles(shift)` |

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| _characterCountCurrent | _characterCountCurrent | integer | RW | `obj._characterCountCurrent = <value>` |
| _characterCountOriginal | _characterCountOriginal | integer | RW | `obj._characterCountOriginal = <value>` |
| squadType | (lua_Integer | integer | RW | `obj.squadType = <value>` |
| hasUniques | (lua_Integer | integer | RW | `obj.hasUniques = <value>` |
| speedOverride | (lua_Integer | integer | RW | `obj.speedOverride = <value>` |
| isSeparatedSquad | isSeparatedSquad | hand | RW | `obj.isSeparatedSquad = <value>` |
| canRefresh | canRefresh | boolean | RW | `obj.canRefresh = <value>` |
| regenerates | regenerates | boolean | RW | `obj.regenerates = <value>` |
| myBaseHomeTownData | myBaseHomeTownData | GameData | RW | `obj.myBaseHomeTownData = <value>` |
| priceMultWhenITrade | priceMultWhenITrade | number | RW | `obj.priceMultWhenITrade = <value>` |
| _iBuyStolenGoods | _iBuyStolenGoods | boolean | RW | `obj._iBuyStolenGoods = <value>` |
| _iBuyIllegalGoods | _iBuyIllegalGoods | boolean | RW | `obj._iBuyIllegalGoods = <value>` |
| locatorModel | locatorModel | lightuserdata | RW | `obj.locatorModel = <value>` |
| blackboard | blackboard | lightuserdata | RW | `obj.blackboard = <value>` |
| _isIntact | _isIntact | boolean | RW | `obj._isIntact = <value>` |
| squadTemplate | squadTemplate | GameData | RW | `obj.squadTemplate = <value>` |
| malnourishedLevel | malnourishedLevel | number | RW | `obj.malnourishedLevel = <value>` |
| hasNeverBeenActivated | hasNeverBeenActivated | boolean | RW | `obj.hasNeverBeenActivated = <value>` |
| _persistentSquad | _persistentSquad | boolean | RW | `obj._persistentSquad = <value>` |
| isResidentSquad | isResidentSquad | boolean | RW | `obj.isResidentSquad = <value>` |
| messageOnActivation | (lua_Integer | integer | RW | `obj.messageOnActivation = <value>` |
| currentSpawnArea | currentSpawnArea | lightuserdata | RW | `obj.currentSpawnArea = <value>` |
| squadleader | squadleader | hand | RW | `obj.squadleader = <value>` |
| ownerships | getOwnerships | Ownerships | R | `obj.ownerships` |
| activePlatoon | getActivePlatoon | ActivePlatoon | RW | `obj.activePlatoon = <value>` |
| unloadedPlatoon | unloadedPlatoon | lightuserdata | RW | `obj.unloadedPlatoon = <value>` |
| patrolSettings | patrolSettings | lightuserdata | RW | `obj.patrolSettings = <value>` |
| isDead | isDead | boolean | RW | `obj.isDead = <value>` |
| imprisoned | imprisoned | boolean | RW | `obj.imprisoned = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| traderInventoryRefreshTime | traderInventoryRefreshTime | number | RW | `obj.traderInventoryRefreshTime = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCharacterCount | setCharacterCount | `count: integer` | `void` | `obj:setCharacterCount(count)` |
| isUnconcious | isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| getSquadType | getSquadType | `` | `integer` | `obj:getSquadType()` |
| setSquadType | setSquadType | `t: integer` | `void` | `obj:setSquadType(t)` |
| iBuyIllegalGoods | iBuyIllegalGoods | `` | `boolean` | `obj:iBuyIllegalGoods()` |
| getPlatoonStringID | getPlatoonStringID | `` | `string` | `obj:getPlatoonStringID()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| erasePlatoonFile | erasePlatoonFile | `` | `void` | `obj:erasePlatoonFile()` |
| showDebugMarker | showDebugMarker | `on: boolean` | `void` | `obj:showDebugMarker(on)` |
| setDataFilename | setDataFilename | `f: string` | `void` | `obj:setDataFilename(f)` |
| isIntact | isIntact | `` | `boolean` | `obj:isIntact()` |
| notifyMissionEnded | notifyMissionEnded | `` | `void` | `obj:notifyMissionEnded()` |
| _NV_notifyMissionEnded | _NV_notifyMissionEnded | `` | `void` | `obj:_NV_notifyMissionEnded()` |
| activate | activate | `` | `void` | `obj:activate()` |
| declareDead | declareDead | `` | `void` | `obj:declareDead()` |
| undeclareDead | undeclareDead | `` | `void` | `obj:undeclareDead()` |
| isFullyLoaded | isFullyLoaded | `` | `boolean` | `obj:isFullyLoaded()` |
| update | update | `` | `boolean` | `obj:update()` |
| _NV_update | _NV_update | `` | `boolean` | `obj:_NV_update()` |
| periodicUpdate_active | periodicUpdate_active | `time: number` | `void` | `obj:periodicUpdate_active(time)` |
| _NV_periodicUpdate_active | _NV_periodicUpdate_active | `time: number` | `void` | `obj:_NV_periodicUpdate_active(time)` |
| periodicUpdate_unloaded | periodicUpdate_unloaded | `` | `void` | `obj:periodicUpdate_unloaded()` |
| _NV_periodicUpdate_unloaded | _NV_periodicUpdate_unloaded | `` | `void` | `obj:_NV_periodicUpdate_unloaded()` |
| setupPatrolSettings | setupPatrolSettings | `minRange: integer, maxRange: integer` | `void` | `obj:setupPatrolSettings(minRange, maxRange)` |
| isPersistentSquad | isPersistentSquad | `` | `boolean` | `obj:isPersistentSquad()` |
| setPersistentSquad | setPersistentSquad | `on: boolean` | `void` | `obj:setPersistentSquad(on)` |
| getOwnerships | getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| _NV_getOwnerships | _NV_getOwnerships | `` | `Ownerships` | `obj:_NV_getOwnerships()` |
| getNearestActiveCharacter | getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getCharacterCount | getCharacterCount | `` | `integer` | `obj:getCharacterCount()` |
| getCharacterCount_Original | getCharacterCount_Original | `` | `integer` | `obj:getCharacterCount_Original()` |
| needsNewCharacters | needsNewCharacters | `` | `integer` | `obj:needsNewCharacters()` |
| reCheckPersistenceOnUnload | reCheckPersistenceOnUnload | `` | `void` | `obj:reCheckPersistenceOnUnload()` |
| _NV_reCheckPersistenceOnUnload | _NV_reCheckPersistenceOnUnload | `` | `void` | `obj:_NV_reCheckPersistenceOnUnload()` |
| chooseNewHome | Platoon_chooseNewHome | `` | `hand` | `obj:chooseNewHome()` |
| getCurrentTownLocation | Platoon_getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | Platoon__NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| hasCampaign | Platoon_hasCampaign | `` | `hand` | `obj:hasCampaign()` |
| iBuyStolenGoods | Platoon_iBuyStolenGoods | `` | `boolean` | `obj:iBuyStolenGoods()` |
| setFaction | Platoon_setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | Platoon__NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| canTakeRefugees | Platoon_canTakeRefugees | `` | `boolean` | `obj:canTakeRefugees()` |
| isUnique | Platoon_isUnique | `` | `hand` | `obj:isUnique()` |
| _NV_isUnique | Platoon__NV_isUnique | `` | `hand` | `obj:_NV_isUnique()` |
| getBlackboard | Platoon_getBlackboard | `` | `hand` | `obj:getBlackboard()` |
| getStateBroadcast | Platoon_getStateBroadcast | `` | `hand` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | Platoon__NV_getStateBroadcast | `` | `hand` | `obj:_NV_getStateBroadcast()` |
| serialiseEverything | Platoon_serialiseEverything | `levelEditor: boolean` | `GameData` | `obj:serialiseEverything(levelEditor)` |
| _NV_serialiseEverything | Platoon__NV_serialiseEverything | `levelEditor: boolean` | `GameData` | `obj:_NV_serialiseEverything(levelEditor)` |
| loadStateData | Platoon_loadStateData | `` | `void` | `obj:loadStateData()` |
| _NV_loadStateData | Platoon__NV_loadStateData | `` | `void` | `obj:_NV_loadStateData()` |
| serialise | Platoon_serialise | `` | `hand` | `obj:serialise()` |
| _NV_serialise | Platoon__NV_serialise | `` | `hand` | `obj:_NV_serialise()` |
| loadFromSerialise | Platoon_loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | Platoon__NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| reprocessTask | Platoon_reprocessTask | `` | `void` | `obj:reprocessTask()` |
| taskIsComplete | Platoon_taskIsComplete | `` | `void` | `obj:taskIsComplete()` |
| deactivate | Platoon_deactivate | `forceCharacterStates: userdata` | `void` | `obj:deactivate(forceCharacterStates)` |
| getActivePlatoon | Platoon_getActivePlatoon | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getUnloadedPlatoon | Platoon_getUnloadedPlatoon | `` | `hand` | `obj:getUnloadedPlatoon()` |
| getPatrolInfo | Platoon_getPatrolInfo | `` | `hand` | `obj:getPatrolInfo()` |
| getRoamingMapArea | Platoon_getRoamingMapArea | `` | `hand` | `obj:getRoamingMapArea()` |
| setRoamingMapArea | Platoon_setRoamingMapArea | `` | `hand` | `obj:setRoamingMapArea()` |
| getSquadLeader_theRealOne | Platoon_getSquadLeader_theRealOne | `` | `hand` | `obj:getSquadLeader_theRealOne()` |

## PlayerInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| factionName | factionName | string | RW | `obj.factionName = <value>` |
| camera | camera | CameraClass | RW | `obj.camera = <value>` |
| technology | (void* | lightuserdata | RW | `obj.technology = <value>` |
| selectedObjectsChangedThisFrame | selectedObjectsChangedThisFrame | boolean | RW | `obj.selectedObjectsChangedThisFrame = <value>` |
| contextMenu | contextMenu | ContextMenu | RW | `obj.contextMenu = <value>` |
| selectBox | selectBox | SelectionBox | RW | `obj.selectBox = <value>` |
| moveMarker | (void* | lightuserdata | RW | `obj.moveMarker = <value>` |
| selectedCharacter | selectedCharacter | hand | RW | `obj.selectedCharacter = <value>` |
| aiOptions | aiOptions | PlayerInterface::AIOptions | RW | `obj.aiOptions = <value>` |
| zonesVisibilities | zonesVisibilities | unknown | RW | `obj.zonesVisibilities = <value>` |
| townsActive | townsActive | ogre_unordered_set<TownBase*>::type | RW | `obj.townsActive = <value>` |
| interiorsVisible | interiorsVisible | ogre_unordered_set<hand>::type | RW | `obj.interiorsVisible = <value>` |
| interiorsVisibleHash | interiorsVisibleHash | integer | RW | `obj.interiorsVisibleHash = <value>` |
| currentFloor | currentFloor | integer | RW | `obj.currentFloor = <value>` |
| currentMouseTask | (lua_Integer | integer | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | (lua_Integer | integer | RW | `obj.mouseTaskTypeRestriction = <value>` |
| mouseRightTargetSet | mouseRightTargetSet | boolean | RW | `obj.mouseRightTargetSet = <value>` |
| mouseRightTarget | mouseRightTarget | RootObject | RW | `obj.mouseRightTarget = <value>` |
| rmouseTimer | rmouseTimer | number | RW | `obj.rmouseTimer = <value>` |
| selectedCharacters | selectedCharacters | ogre_unordered_set<hand>::type | RW | `obj.selectedCharacters = <value>` |
| selectedObject | selectedObject | hand | RW | `obj.selectedObject = <value>` |
| onlyAnimalsSelected | onlyAnimalsSelected | boolean | RW | `obj.onlyAnimalsSelected = <value>` |
| selectedLoadedLeft | selectedLoadedLeft | integer | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterHandle | trackedCharacterHandle | hand | RW | `obj.trackedCharacterHandle = <value>` |
| trackedCharacterFloor | trackedCharacterFloor | integer | RW | `obj.trackedCharacterFloor = <value>` |
| levelEditor | (void* | lightuserdata | RW | `obj.levelEditor = <value>` |
| participant | participant | Faction | RW | `obj.participant = <value>` |
| currentPlatoon | currentPlatoon | Platoon | RW | `obj.currentPlatoon = <value>` |
| playerCharacters | playerCharacters | lektor<Character*> | RW | `obj.playerCharacters = <value>` |
| deadPlayerSquad | deadPlayerSquad | hand | RW | `obj.deadPlayerSquad = <value>` |
| placementObject | (void* | lightuserdata | RW | `obj.placementObject = <value>` |
| characterEditorMode | characterEditorMode | boolean | RW | `obj.characterEditorMode = <value>` |
| mLeftUp | mLeftUp | boolean | RW | `obj.mLeftUp = <value>` |
| mLeftDown | mLeftDown | boolean | RW | `obj.mLeftDown = <value>` |
| mRightUp | mRightUp | boolean | RW | `obj.mRightUp = <value>` |
| mRightDown | mRightDown | boolean | RW | `obj.mRightDown = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `PlayerInterface` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getCamera | getCamera | `` | `CameraClass` | `obj:getCamera()` |
| clearAndReset | clearAndReset | `` | `void` | `obj:clearAndReset()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |
| getCurrentPlatoon | getCurrentPlatoon | `` | `Platoon` | `obj:getCurrentPlatoon()` |
| getCurrentActivePlatoon | getCurrentActivePlatoon | `` | `RootObjectContainer` | `obj:getCurrentActivePlatoon()` |
| update | update | `` | `void` | `obj:update()` |
| updateUT | updateUT | `` | `void` | `obj:updateUT()` |
| isBuildMode | isBuildMode | `` | `boolean` | `obj:isBuildMode()` |
| setCharacterEditMode | setCharacterEditMode | `on: boolean` | `void` | `obj:setCharacterEditMode(on)` |
| getCharacterEditMode | getCharacterEditMode | `` | `boolean` | `obj:getCharacterEditMode()` |
| unselectAll | unselectAll | `` | `void` | `obj:unselectAll()` |
| selectAll | selectAll | `` | `void` | `obj:selectAll()` |
| selectPlayerCharacter | selectPlayerCharacter | `index: integer, modifier: boolean, track: boolean` | `void` | `obj:selectPlayerCharacter(index, modifier, track)` |
| getCameraCenter | getCameraCenter | `` | `Vector3` | `obj:getCameraCenter()` |
| getDistanceFromCamera | getDistanceFromCamera | `v: Vector3` | `number` | `obj:getDistanceFromCamera(v)` |
| getSquaredDistanceFromCamera | getSquaredDistanceFromCamera | `v: Vector3` | `number` | `obj:getSquaredDistanceFromCamera(v)` |
| stopTrackCharacter | stopTrackCharacter | `` | `void` | `obj:stopTrackCharacter()` |
| isTrackingCharacter | isTrackingCharacter | `` | `boolean` | `obj:isTrackingCharacter()` |
| focusCamera | focusCamera | `pos: Vector3` | `void` | `obj:focusCamera(pos)` |
| manuallyOrientCamera | manuallyOrientCamera | `rot: Quaternion, zoom: number` | `void` | `obj:manuallyOrientCamera(rot, zoom)` |
| focusCameraSelectedCharacter | focusCameraSelectedCharacter | `` | `void` | `obj:focusCameraSelectedCharacter()` |
| toggleLevelEditorOnSelectedTown | toggleLevelEditorOnSelectedTown | `` | `void` | `obj:toggleLevelEditorOnSelectedTown()` |
| isLevelEditMode | isLevelEditMode | `` | `boolean` | `obj:isLevelEditMode()` |
| isObjectPlacementMode | isObjectPlacementMode | `` | `boolean` | `obj:isObjectPlacementMode()` |
| setOrderSelectedCharacters | setOrderSelectedCharacters | `order: integer` | `void` | `obj:setOrderSelectedCharacters(order)` |
| getCurrentFloor | getCurrentFloor | `` | `integer` | `obj:getCurrentFloor()` |
| setCurrentFloor | setCurrentFloor | `floor: integer` | `void` | `obj:setCurrentFloor(floor)` |
| getNearestSelectedCharacterTo | getNearestSelectedCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestSelectedCharacterTo(pos)` |
| getNearestCharacterTo | getNearestCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestCharacterTo(pos)` |
| removeJobSelectedCharacters | removeJobSelectedCharacters | `t: integer` | `void` | `obj:removeJobSelectedCharacters(t)` |
| removePermaJobSelectedCharacters | removePermaJobSelectedCharacters | `id: integer` | `void` | `obj:removePermaJobSelectedCharacters(id)` |
| selectedCharactersUnconcious | selectedCharactersUnconcious | `displayMessage: boolean` | `boolean` | `obj:selectedCharactersUnconcious(displayMessage)` |
| selectedCharactersLayingLow | selectedCharactersLayingLow | `` | `boolean` | `obj:selectedCharactersLayingLow()` |
| useSpeedGroup | useSpeedGroup | `use: boolean` | `void` | `obj:useSpeedGroup(use)` |
| assignSpeedGroup | assignSpeedGroup | `create: boolean` | `void` | `obj:assignSpeedGroup(create)` |
| cycleSquad | cycleSquad | `` | `void` | `obj:cycleSquad()` |
| cycleCharacter | cycleCharacter | `d: integer` | `void` | `obj:cycleCharacter(d)` |
| stopCharactersMovement | stopCharactersMovement | `` | `void` | `obj:stopCharactersMovement()` |
| getAnyPlayerCharacter | getAnyPlayerCharacter | `` | `Character` | `obj:getAnyPlayerCharacter()` |
| isOrderValidForSelection | isOrderValidForSelection | `task: integer` | `boolean` | `obj:isOrderValidForSelection(task)` |
| setVisibilityForReflections | setVisibilityForReflections | `set: boolean` | `void` | `obj:setVisibilityForReflections(set)` |
| resetFloorsVisibility | resetFloorsVisibility | `` | `void` | `obj:resetFloorsVisibility()` |
| setFloorsVisibility | setFloorsVisibility | `floor: integer` | `void` | `obj:setFloorsVisibility(floor)` |
| clearSelection | clearSelection | `` | `void` | `obj:clearSelection()` |
| mouseScan | mouseScan | `` | `void` | `obj:mouseScan()` |
| playerSetup | playerSetup | `` | `void` | `obj:playerSetup()` |
| factoryObjectCreatedCallback | factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _NV_factoryObjectCreatedCallback | _NV_factoryObjectCreatedCallback | `` | `void` | `obj:_NV_factoryObjectCreatedCallback()` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| setCurrentPlatoon | setCurrentPlatoon | `` | `boolean` | `obj:setCurrentPlatoon()` |
| recruit | recruit | `editor: boolean` | `boolean` | `obj:recruit(editor)` |
| createSquad | createSquad | `` | `ActivePlatoon` | `obj:createSquad()` |
| getDeadSquad | getDeadSquad | `` | `ActivePlatoon` | `obj:getDeadSquad()` |
| getDeadSquadHandle | getDeadSquadHandle | `` | `hand` | `obj:getDeadSquadHandle()` |
| activateObjectPlacementMode | activateObjectPlacementMode | `` | `void` | `obj:activateObjectPlacementMode()` |
| activateCharacterEditMode | activateCharacterEditMode | `` | `void` | `obj:activateCharacterEditMode()` |
| triggerAreaArrivalDialogue | triggerAreaArrivalDialogue | `` | `boolean` | `obj:triggerAreaArrivalDialogue()` |
| selectObject | selectObject | `modifier: boolean` | `void` | `obj:selectObject(modifier)` |
| _selectPlayerCharacter | _selectPlayerCharacter | `modifier: boolean, track: boolean` | `void` | `obj:_selectPlayerCharacter(modifier, track)` |
| activateSelection | activateSelection | `` | `void` | `obj:activateSelection()` |
| startTrackCharacter | startTrackCharacter | `` | `void` | `obj:startTrackCharacter()` |
| getLevelEditor | getLevelEditor | `` | `lightuserdata` | `obj:getLevelEditor()` |
| objectSelected | objectSelected | `select: boolean` | `void` | `obj:objectSelected(select)` |
| toggleObjectSelected | toggleObjectSelected | `` | `void` | `obj:toggleObjectSelected()` |
| isObjectSelected | isObjectSelected | `` | `boolean` | `obj:isObjectSelected()` |
| unselectPlayerCharacter | unselectPlayerCharacter | `` | `void` | `obj:unselectPlayerCharacter()` |
| updatePlayerSelection | updatePlayerSelection | `` | `void` | `obj:updatePlayerSelection()` |
| getAllSelectedObjects | getAllSelectedObjects | `type: integer` | `void` | `obj:getAllSelectedObjects(type)` |
| newPlayerTaskSelectedCharacters | newPlayerTaskSelectedCharacters | `t: integer, clickpos: Vector3, addDontClear: boolean` | `void` | `obj:newPlayerTaskSelectedCharacters(t, clickpos, addDontClear)` |
| getPlayerTaskProbability | getPlayerTaskProbability | `task: integer` | `boolean|number` | `obj:getPlayerTaskProbability(task)` |
| addOrderSelectedCharacters | addOrderSelectedCharacters | `task: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addOrderSelectedCharacters(task, shift, addDontClear, location)` |
| addJobSelectedCharacters | addJobSelectedCharacters | `task: integer, shift: boolean, add: boolean, location: Vector3` | `void` | `obj:addJobSelectedCharacters(task, shift, add, location)` |
| isEnemy | isEnemy | `` | `boolean` | `obj:isEnemy()` |
| isFactionKnown | isFactionKnown | `` | `boolean` | `obj:isFactionKnown()` |
| encounterFaction | encounterFaction | `` | `void` | `obj:encounterFaction()` |
| pickupItem | pickupItem | `` | `void` | `obj:pickupItem()` |
| getAllPlayerCharacters | getAllPlayerCharacters | `` | `lektor<Character*>` | `obj:getAllPlayerCharacters()` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| getInteriorsVisible | getInteriorsVisible | `` | `boolean` | `obj:getInteriorsVisible()` |
| updateFloorVisibility | updateFloorVisibility | `` | `void` | `obj:updateFloorVisibility()` |
| addTaskNearestSelectedCharacter | addTaskNearestSelectedCharacter | `t: integer, shift: boolean, location: Vector3, noAnimals: boolean` | `void` | `obj:addTaskNearestSelectedCharacter(t, shift, location, noAnimals)` |
| updateLastMoveWaypointSelectedCharacters | updateLastMoveWaypointSelectedCharacters | `location: Vector3` | `void` | `obj:updateLastMoveWaypointSelectedCharacters(location)` |
| playerControl | playerControl | `` | `void` | `obj:playerControl()` |
| characterSelected | characterSelected | `` | `void` | `obj:characterSelected()` |
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| buildingSelected | buildingSelected | `position: Vector3, interiorsVisible: boolean` | `boolean` | `obj:buildingSelected(position, interiorsVisible)` |
| playerMove | playerMove | `pos: Vector3` | `void` | `obj:playerMove(pos)` |
| _isPlayerCharacter | _isPlayerCharacter | `` | `boolean` | `obj:_isPlayerCharacter()` |

## PreviewBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| parentNode | (void* | lightuserdata | R | `obj.parentNode` |
| isCurrentlySnapped | isCurrentlySnapped | boolean | RW | `obj.isCurrentlySnapped = <value>` |
| snappedTo | snappedTo | Building | RW | `obj.snappedTo = <value>` |
| prospectingInformation | prospectingInformation | DatapanelGUI | RW | `obj.prospectingInformation = <value>` |
| prospectResource | (lua_Integer | integer | RW | `obj.prospectResource = <value>` |
| roofOnly | roofOnly | boolean | RW | `obj.roofOnly = <value>` |
| spaceAbove | spaceAbove | number | RW | `obj.spaceAbove = <value>` |
| spaceBelow | spaceBelow | number | RW | `obj.spaceBelow = <value>` |
| collisionOK | collisionOK | boolean | RW | `obj.collisionOK = <value>` |
| charactersOK | charactersOK | boolean | RW | `obj.charactersOK = <value>` |
| floorOk | floorOk | boolean | RW | `obj.floorOk = <value>` |
| indoorsOK | indoorsOK | boolean | RW | `obj.indoorsOK = <value>` |
| slopeOK | slopeOK | boolean | RW | `obj.slopeOK = <value>` |
| nodesOk | nodesOk | boolean | RW | `obj.nodesOk = <value>` |
| blockedBuildings | blockedBuildings | boolean | RW | `obj.blockedBuildings = <value>` |
| validGround | validGround | boolean | RW | `obj.validGround = <value>` |
| inTown | inTown | Town | RW | `obj.inTown = <value>` |
| floorNum | floorNum | integer | RW | `obj.floorNum = <value>` |
| isOutside | isOutside | boolean | RW | `obj.isOutside = <value>` |
| matchSlope | matchSlope | boolean | RW | `obj.matchSlope = <value>` |
| justBeenBuilt | justBeenBuilt | Building | RW | `obj.justBeenBuilt = <value>` |
| yaw | yaw | number | RW | `obj.yaw = <value>` |
| centreOffset | centreOffset | Vector3 | RW | `obj.centreOffset = <value>` |
| isFurnitureOf | isFurnitureOf | Building | RW | `obj.isFurnitureOf = <value>` |
| isIndoors | isIndoors | Building | RW | `obj.isIndoors = <value>` |
| buildDataPtr | buildDataPtr | GameData | RW | `obj.buildDataPtr = <value>` |
| farmData | farmData | GameData | RW | `obj.farmData = <value>` |
| prospectingOK | prospectingOK | boolean | RW | `obj.prospectingOK = <value>` |
| furniture | furniture | boolean | RW | `obj.furniture = <value>` |
| exteriorFurniture | exteriorFurniture | boolean | RW | `obj.exteriorFurniture = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |
| positionHitGroup | positionHitGroup | integer | RW | `obj.positionHitGroup = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `PreviewBuilding` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| type | type | `` | `integer` | `obj:type()` |
| _NV_type | _NV_type | `` | `integer` | `obj:_NV_type()` |
| checkProspectingIsNotZero | checkProspectingIsNotZero | `` | `boolean` | `obj:checkProspectingIsNotZero()` |
| _NV_checkProspectingIsNotZero | _NV_checkProspectingIsNotZero | `` | `boolean` | `obj:_NV_checkProspectingIsNotZero()` |
| isASnapToBuilding | isASnapToBuilding | `` | `boolean` | `obj:isASnapToBuilding()` |
| _NV_isASnapToBuilding | _NV_isASnapToBuilding | `` | `boolean` | `obj:_NV_isASnapToBuilding()` |
| isACeilingBuilding | isACeilingBuilding | `` | `boolean` | `obj:isACeilingBuilding()` |
| _NV_isACeilingBuilding | _NV_isACeilingBuilding | `` | `boolean` | `obj:_NV_isACeilingBuilding()` |
| snappingOk | snappingOk | `` | `boolean` | `obj:snappingOk()` |
| _NV_snappingOk | _NV_snappingOk | `` | `boolean` | `obj:_NV_snappingOk()` |
| isInteriorBuilding | isInteriorBuilding | `` | `boolean` | `obj:isInteriorBuilding()` |
| _NV_isInteriorBuilding | _NV_isInteriorBuilding | `` | `boolean` | `obj:_NV_isInteriorBuilding()` |
| isCurrent | isCurrent | `` | `boolean` | `obj:isCurrent()` |
| setup | setup | `` | `boolean` | `obj:setup()` |
| _NV_setup | _NV_setup | `` | `boolean` | `obj:_NV_setup()` |
| _destroyEnts | _destroyEnts | `` | `void` | `obj:_destroyEnts()` |
| _NV__destroyEnts | _NV__destroyEnts | `` | `void` | `obj:_NV__destroyEnts()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| figureOutWhichTown | figureOutWhichTown | `` | `void` | `obj:figureOutWhichTown()` |
| setVisualPosition | setVisualPosition | `position: Vector3` | `void` | `obj:setVisualPosition(position)` |
| _NV_setVisualPosition | _NV_setVisualPosition | `position: Vector3` | `void` | `obj:_NV_setVisualPosition(position)` |
| yawBy | yawBy | `pan: number` | `void` | `obj:yawBy(pan)` |
| yawSet | yawSet | `pan: number` | `void` | `obj:yawSet(pan)` |
| rotateBy | rotateBy | `by: Quaternion` | `void` | `obj:rotateBy(by)` |
| tilt | tilt | `pan: number` | `void` | `obj:tilt(pan)` |
| roll | roll | `pan: number` | `void` | `obj:roll(pan)` |
| setRotation | setRotation | `r: Quaternion` | `void` | `obj:setRotation(r)` |
| allFootprintsWantBelowGround | allFootprintsWantBelowGround | `` | `boolean` | `obj:allFootprintsWantBelowGround()` |
| allFootprintsWantAboveGround | allFootprintsWantAboveGround | `` | `boolean` | `obj:allFootprintsWantAboveGround()` |
| updateFootprintHeights | updateFootprintHeights | `` | `boolean` | `obj:updateFootprintHeights()` |
| isCollisionOK | isCollisionOK | `` | `boolean` | `obj:isCollisionOK()` |
| _NV_isCollisionOK | _NV_isCollisionOK | `` | `boolean` | `obj:_NV_isCollisionOK()` |
| isFloorOk | isFloorOk | `` | `boolean` | `obj:isFloorOk()` |
| _NV_isFloorOk | _NV_isFloorOk | `` | `boolean` | `obj:_NV_isFloorOk()` |
| isIndoorsOk | isIndoorsOk | `` | `boolean` | `obj:isIndoorsOk()` |
| _NV_isIndoorsOk | _NV_isIndoorsOk | `` | `boolean` | `obj:_NV_isIndoorsOk()` |
| isNodesOk | isNodesOk | `` | `boolean` | `obj:isNodesOk()` |
| _NV_isNodesOk | _NV_isNodesOk | `` | `boolean` | `obj:_NV_isNodesOk()` |
| isBlockingBuildingsNodes | isBlockingBuildingsNodes | `` | `boolean` | `obj:isBlockingBuildingsNodes()` |
| _NV_isBlockingBuildingsNodes | _NV_isBlockingBuildingsNodes | `` | `boolean` | `obj:_NV_isBlockingBuildingsNodes()` |
| isGoodAboveAndBelow | isGoodAboveAndBelow | `` | `boolean` | `obj:isGoodAboveAndBelow()` |
| _NV_isGoodAboveAndBelow | _NV_isGoodAboveAndBelow | `` | `boolean` | `obj:_NV_isGoodAboveAndBelow()` |
| isOnValidGround | isOnValidGround | `` | `boolean` | `obj:isOnValidGround()` |
| _NV_isOnValidGround | _NV_isOnValidGround | `` | `boolean` | `obj:_NV_isOnValidGround()` |
| isLinked | isLinked | `` | `boolean` | `obj:isLinked()` |
| _NV_isLinked | _NV_isLinked | `` | `boolean` | `obj:_NV_isLinked()` |
| moveHeightOffset | moveHeightOffset | `h: number` | `void` | `obj:moveHeightOffset(h)` |
| resetHeightOffset | resetHeightOffset | `` | `void` | `obj:resetHeightOffset()` |
| getFootprintShift | getFootprintShift | `` | `number` | `obj:getFootprintShift()` |
| setOrientation | setOrientation | `q: Quaternion` | `void` | `obj:setOrientation(q)` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFloor | getFloor | `` | `integer` | `obj:getFloor()` |
| setStartPosition | setStartPosition | `p: Vector3` | `void` | `obj:setStartPosition(p)` |
| _NV_setStartPosition | _NV_setStartPosition | `p: Vector3` | `void` | `obj:_NV_setStartPosition(p)` |
| setEndPosition | setEndPosition | `position: Vector3` | `void` | `obj:setEndPosition(position)` |
| _NV_setEndPosition | _NV_setEndPosition | `position: Vector3` | `void` | `obj:_NV_setEndPosition(position)` |
| getEndPos | getEndPos | `` | `Vector3` | `obj:getEndPos()` |
| _NV_getEndPos | _NV_getEndPos | `` | `Vector3` | `obj:_NV_getEndPos()` |
| clearPointersTo | clearPointersTo | `` | `void` | `obj:clearPointersTo()` |
| _NV_clearPointersTo | _NV_clearPointersTo | `` | `void` | `obj:_NV_clearPointersTo()` |
| placeFinalPreviewBuilding | placeFinalPreviewBuilding | `` | `void` | `obj:placeFinalPreviewBuilding()` |
| _NV_placeFinalPreviewBuilding | _NV_placeFinalPreviewBuilding | `` | `void` | `obj:_NV_placeFinalPreviewBuilding()` |
| insideBuilding | insideBuilding | `` | `Building` | `obj:insideBuilding()` |
| placementVerification | placementVerification | `` | `boolean` | `obj:placementVerification()` |
| _NV_placementVerification | _NV_placementVerification | `` | `boolean` | `obj:_NV_placementVerification()` |
| getGameData | getGameData | `` | `GameData` | `obj:getGameData()` |
| noAltitude | noAltitude | `` | `boolean` | `obj:noAltitude()` |
| _NV_noAltitude | _NV_noAltitude | `` | `boolean` | `obj:_NV_noAltitude()` |
| noPathfindingNeeded | noPathfindingNeeded | `` | `boolean` | `obj:noPathfindingNeeded()` |
| _NV_noPathfindingNeeded | _NV_noPathfindingNeeded | `` | `boolean` | `obj:_NV_noPathfindingNeeded()` |
| placePreview | placePreview | `position: Vector3, rotation: Quaternion, floorNumber: integer` | `void` | `obj:placePreview(position, rotation, floorNumber)` |
| _NV_placePreview | _NV_placePreview | `position: Vector3, rotation: Quaternion, floorNumber: integer` | `void` | `obj:_NV_placePreview(position, rotation, floorNumber)` |
| resetUseageNodes | resetUseageNodes | `` | `void` | `obj:resetUseageNodes()` |
| calculateRotationsAndStuff | calculateRotationsAndStuff | `position: Vector3` | `void` | `obj:calculateRotationsAndStuff(position)` |
| _NV_calculateRotationsAndStuff | _NV_calculateRotationsAndStuff | `position: Vector3` | `void` | `obj:_NV_calculateRotationsAndStuff(position)` |
| placementVerification_recurse | placementVerification_recurse | `` | `boolean` | `obj:placementVerification_recurse()` |
| getTerrainHeightAtCenter | getTerrainHeightAtCenter | `` | `number` | `obj:getTerrainHeightAtCenter()` |
| _NV_getTerrainHeightAtCenter | _NV_getTerrainHeightAtCenter | `` | `number` | `obj:_NV_getTerrainHeightAtCenter()` |
| recalculateWorldAABB | recalculateWorldAABB | `` | `void` | `obj:recalculateWorldAABB()` |
| validateUsageNodes | validateUsageNodes | `` | `void` | `obj:validateUsageNodes()` |

## ProductionBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| productionState | (lua_Integer | integer | RW | `obj.productionState = <value>` |
| _resourceMiningLevel | _resourceMiningLevel | number | RW | `obj._resourceMiningLevel = <value>` |
| outSection | outSection | InventorySection | R | `obj.outSection` |
| consumptionItems | consumptionItems | lektor<StorageBuilding::ConsumptionItem> | R | `obj.consumptionItems` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getProductionBuilding | getProductionBuilding | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| _NV_getProductionBuilding | _NV_getProductionBuilding | `` | `ProductionBuilding` | `obj:_NV_getProductionBuilding()` |
| createInventoryLayout | createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| getProductionMult | getProductionMult | `` | `number` | `obj:getProductionMult()` |
| _NV_getProductionMult | _NV_getProductionMult | `` | `number` | `obj:_NV_getProductionMult()` |
| getProductionMultForGUI | getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| _NV_getProductionMultForGUI | _NV_getProductionMultForGUI | `` | `number` | `obj:_NV_getProductionMultForGUI()` |
| setupMiningResourceLevel | setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| _NV_setupMiningResourceLevel | _NV_setupMiningResourceLevel | `` | `void` | `obj:_NV_setupMiningResourceLevel()` |
| getMiningResourceLevel | getMiningResourceLevel | `` | `number` | `obj:getMiningResourceLevel()` |
| _NV_getMiningResourceLevel | _NV_getMiningResourceLevel | `` | `number` | `obj:_NV_getMiningResourceLevel()` |
| getMouseCursor | getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| isAnyInputsEmpty | isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| isAnyInputsInvalidType | isAnyInputsInvalidType | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| _NV_isAnyInputsInvalidType | _NV_isAnyInputsInvalidType | `` | `boolean` | `obj:_NV_isAnyInputsInvalidType()` |
| isAnyInputsFull | isAnyInputsFull | `` | `boolean` | `obj:isAnyInputsFull()` |
| _NV_isAnyInputsFull | _NV_isAnyInputsFull | `` | `boolean` | `obj:_NV_isAnyInputsFull()` |
| isProductionFull | isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| isProductionEmpty | isProductionEmpty | `` | `boolean` | `obj:isProductionEmpty()` |
| _NV_isProductionEmpty | _NV_isProductionEmpty | `` | `boolean` | `obj:_NV_isProductionEmpty()` |
| getOutputBasedRotationSpeedMult | getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| _NV_getOutputBasedRotationSpeedMult | _NV_getOutputBasedRotationSpeedMult | `` | `number` | `obj:_NV_getOutputBasedRotationSpeedMult()` |
| getOutput | getOutput | `` | `number` | `obj:getOutput()` |
| getNumConsumtionItems | getNumConsumtionItems | `` | `integer` | `obj:getNumConsumtionItems()` |
| _NV_getNumConsumtionItems | _NV_getNumConsumtionItems | `` | `integer` | `obj:_NV_getNumConsumtionItems()` |
| getConsumtionItems | getConsumtionItems | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| _NV_getConsumtionItems | _NV_getConsumtionItems | `id: integer` | `lightuserdata` | `obj:_NV_getConsumtionItems(id)` |
| setupFromData | setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| updateInventoryWindow | updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| _NV_updateInventoryWindow | _NV_updateInventoryWindow | `` | `void` | `obj:_NV_updateInventoryWindow()` |
| updateInputs | updateInputs | `rate: number` | `void` | `obj:updateInputs(rate)` |
| _NV_updateInputs | _NV_updateInputs | `rate: number` | `void` | `obj:_NV_updateInputs(rate)` |
| updateOutput | updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| _NV_updateOutput | _NV_updateOutput | `rate: number` | `void` | `obj:_NV_updateOutput(rate)` |

## ProductionInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `title: string, ins: integer, outs: integer` | `ProductionInventoryLayout` | `obj:_CONSTRUCTOR(title, ins, outs)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ProsperityManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| actualProsperity | actualProsperity | number | RW | `obj.actualProsperity = <value>` |
| maxProsperity | maxProsperity | number | RW | `obj.maxProsperity = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| getProsperityMultiplier | getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| update | update | `time: number` | `void` | `obj:update(time)` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getStatMod | getStatMod | `stat: integer` | `number` | `obj:getStatMod(stat)` |
| isImmune | isImmune | `w: integer` | `boolean` | `obj:isImmune(w)` |

## RaceLimiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| limits | limits | ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type | R | `obj.limits` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## RainCollectorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/RainCollectorBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| calculateEfficiencyMult | calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| _NV_calculateEfficiencyMult | _NV_calculateEfficiencyMult | `` | `number` | `obj:_NV_calculateEfficiencyMult()` |
| getRainAmount | getRainAmount | `` | `number` | `obj:getRainAmount()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## RepetitionCounter
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| states | states | std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > > | R | `obj.states` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | setup | `` | `void` | `obj:setup()` |
| count | count | `ev: integer` | `boolean` | `obj:count(ev)` |
| getTimeSinceLastTrigger | getTimeSinceLastTrigger | `ev: integer` | `number` | `obj:getTimeSinceLastTrigger(ev)` |
| getCount | getCount | `ev: integer` | `integer` | `obj:getCount(ev)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ResearchBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| dontNeedWorkRightNow | dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| _NV_dontNeedWorkRightNow | _NV_dontNeedWorkRightNow | `` | `boolean` | `obj:_NV_dontNeedWorkRightNow()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| notifyConstructionComplete | notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| getTechLevel | getTechLevel | `` | `integer` | `obj:getTechLevel()` |
| _NV_getTechLevel | _NV_getTechLevel | `` | `integer` | `obj:_NV_getTechLevel()` |
| createInventoryLayout | createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |

## ResearchBuildingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| researchButton | (void* | lightuserdata | R | `obj.researchButton` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| getResearchButton | getResearchButton | `` | `lightuserdata` | `obj:getResearchButton()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ResourceLoadRequestMesh
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| entity | (void* | lightuserdata | R | `obj.entity` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| finish | finish | `` | `void` | `obj:finish()` |

## ResourceLoadRequestTexture
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| textureUnitState | (void* | lightuserdata | R | `obj.textureUnitState` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isMaterialValid | isMaterialValid | `` | `boolean` | `obj:isMaterialValid()` |

## ResourceLoader
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| running | running | boolean | RW | `obj.running = <value>` |
| sceneManager | (void* | lightuserdata | R | `obj.sceneManager` |
| loadingMeshQueueMutex | (void* | lightuserdata | R | `obj.loadingMeshQueueMutex` |
| texturesLoadingMutex | (void* | lightuserdata | R | `obj.texturesLoadingMutex` |
| texturesLoadedMutex | (void* | lightuserdata | R | `obj.texturesLoadedMutex` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateMT | updateMT | `` | `void` | `obj:updateMT()` |
| updateBT | updateBT | `` | `boolean` | `obj:updateBT()` |
| isLoading | isLoading | `` | `boolean` | `obj:isLoading()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | init | `` | `void` | `obj:init()` |
| threadProc | threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |

## RobotLimbItem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getLimb | getLimb | `limb: integer` | `Item` | `obj:getLimb(limb)` |
| getMask | getMask | `` | `integer` | `obj:getMask()` |
| getInventoryInterface | getInventoryInterface | `create: boolean` | `RootObject` | `obj:getInventoryInterface(create)` |
| destroyInventoryInterface | destroyInventoryInterface | `` | `void` | `obj:destroyInventoryInterface()` |
| getLimbItem | getLimbItem | `l: integer` | `Item` | `obj:getLimbItem(l)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| container | container | RootObjectContainer | RW | `obj.container = <value>` |
| isInsideBuilding | isInsideBuilding | hand | RW | `obj.isInsideBuilding = <value>` |
| isInsideTownWalls | isInsideTownWalls | integer | RW | `obj.isInsideTownWalls = <value>` |
| floorNum | floorNum | integer | RW | `obj.floorNum = <value>` |
| spacialKey | spacialKey | integer | RW | `obj.spacialKey = <value>` |
| outdoorDelayNotification_timer | outdoorDelayNotification_timer | integer | RW | `obj.outdoorDelayNotification_timer = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| needsSaving | needsSaving | `s: string` | `boolean` | `obj:needsSaving(s)` |
| _NV_needsSaving | _NV_needsSaving | `s: string` | `boolean` | `obj:_NV_needsSaving(s)` |
| getOrientation | getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| _NV_getOrientation | _NV_getOrientation | `` | `Quaternion` | `obj:_NV_getOrientation()` |
| getRace | getRace | `` | `RaceData` | `obj:getRace()` |
| _NV_getRace | _NV_getRace | `` | `RaceData` | `obj:_NV_getRace()` |
| threadedUpdate | threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| isPhysical | isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | setVisible | `_a1: boolean` | `void` | `obj:setVisible(_a1)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| isDisabled | isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| amInsideTownWalls | amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| setInsideTownWalls | setInsideTownWalls | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| _NV_setInsideTownWalls | _NV_setInsideTownWalls | `s: integer` | `void` | `obj:_NV_setInsideTownWalls(s)` |
| getFloor | getFloor | `` | `integer` | `obj:getFloor()` |
| _NV_getFloor | _NV_getFloor | `` | `integer` | `obj:_NV_getFloor()` |
| setFloor | setFloor | `f: integer` | `void` | `obj:setFloor(f)` |
| _NV_setFloor | _NV_setFloor | `f: integer` | `void` | `obj:_NV_setFloor(f)` |
| select | select | `` | `void` | `obj:select()` |
| _NV_select | _NV_select | `` | `void` | `obj:_NV_select()` |
| unselect | unselect | `` | `void` | `obj:unselect()` |
| _NV_unselect | _NV_unselect | `` | `void` | `obj:_NV_unselect()` |
| setStandingOrder | setStandingOrder | `_a1: integer` | `void` | `obj:setStandingOrder(_a1)` |
| _NV_setStandingOrder | _NV_setStandingOrder | `_a1: integer` | `void` | `obj:_NV_setStandingOrder(_a1)` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| takeMoney | takeMoney | `_a1: integer` | `boolean` | `obj:takeMoney(_a1)` |
| _NV_takeMoney | _NV_takeMoney | `_a1: integer` | `boolean` | `obj:_NV_takeMoney(_a1)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| say | say | `_a1: string` | `void` | `obj:say(_a1)` |
| _NV_say | _NV_say | `_a1: string` | `void` | `obj:_NV_say(_a1)` |
| notifyOutdoors | notifyOutdoors | `` | `void` | `obj:notifyOutdoors()` |
| _NV_notifyOutdoors | _NV_notifyOutdoors | `` | `void` | `obj:_NV_notifyOutdoors()` |
| isOnARoof | isOnARoof | `` | `boolean` | `obj:isOnARoof()` |
| _NV_isOnARoof | _NV_isOnARoof | `` | `boolean` | `obj:_NV_isOnARoof()` |
| getIntendedAggression | getIntendedAggression | `` | `number` | `obj:getIntendedAggression()` |
| _NV_getIntendedAggression | _NV_getIntendedAggression | `` | `number` | `obj:_NV_getIntendedAggression()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| notifyEffect | notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| loadUnloadCheck | loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| giveItem | giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| _NV_giveItem | _NV_giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_giveItem(dropOnFail, destroyOnFail)` |
| hasItem | hasItem | `` | `boolean` | `obj:hasItem()` |
| _NV_hasItem | _NV_hasItem | `` | `boolean` | `obj:_NV_hasItem()` |
| equipItem | equipItem | `slotName: string` | `void` | `obj:equipItem(slotName)` |
| _NV_equipItem | _NV_equipItem | `slotName: string` | `void` | `obj:_NV_equipItem(slotName)` |
| unequipItem | unequipItem | `slotName: string` | `void` | `obj:unequipItem(slotName)` |
| _NV_unequipItem | _NV_unequipItem | `slotName: string` | `void` | `obj:_NV_unequipItem(slotName)` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| isIndoors | isIndoors | `` | `hand` | `obj:isIndoors()` |
| _NV_isIndoors | _NV_isIndoors | `` | `hand` | `obj:_NV_isIndoors()` |
| setIsInsideBuilding | setIsInsideBuilding | `` | `void` | `obj:setIsInsideBuilding()` |
| _NV_setIsInsideBuilding | _NV_setIsInsideBuilding | `` | `void` | `obj:_NV_setIsInsideBuilding()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RootObject` | `obj:_CONSTRUCTOR()` |
| getInstanceID | getInstanceID | `` | `lightuserdata` | `obj:getInstanceID()` |
| _NV_getInstanceID | _NV_getInstanceID | `` | `lightuserdata` | `obj:_NV_getInstanceID()` |
| getLayoutInstanceID | getLayoutInstanceID | `` | `string` | `obj:getLayoutInstanceID()` |
| _NV_getLayoutInstanceID | _NV_getLayoutInstanceID | `` | `string` | `obj:_NV_getLayoutInstanceID()` |
| getZoneMapLocation | getZoneMapLocation | `` | `lightuserdata` | `obj:getZoneMapLocation()` |
| _NV_getZoneMapLocation | _NV_getZoneMapLocation | `` | `lightuserdata` | `obj:_NV_getZoneMapLocation()` |
| getAABB | getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| _NV_getAABB | _NV_getAABB | `` | `lightuserdata` | `obj:_NV_getAABB()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| getGUIDataCategories | getGUIDataCategories | `` | `void` | `obj:getGUIDataCategories()` |
| _NV_getGUIDataCategories | _NV_getGUIDataCategories | `` | `void` | `obj:_NV_getGUIDataCategories()` |
| getOrders | getOrders | `` | `void` | `obj:getOrders()` |
| _NV_getOrders | _NV_getOrders | `` | `void` | `obj:_NV_getOrders()` |
| hasRoomForItem | hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| createInventoryLayout | createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| ImStealingDoYouNotice | ImStealingDoYouNotice | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| _NV_ImStealingDoYouNotice | _NV_ImStealingDoYouNotice | `` | `boolean` | `obj:_NV_ImStealingDoYouNotice()` |
| stolenGoodsDetectionCheck | stolenGoodsDetectionCheck | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| _NV_stolenGoodsDetectionCheck | _NV_stolenGoodsDetectionCheck | `` | `boolean` | `obj:_NV_stolenGoodsDetectionCheck()` |
| notifyIndoors | notifyIndoors | `` | `void` | `obj:notifyIndoors()` |
| _NV_notifyIndoors | _NV_notifyIndoors | `` | `void` | `obj:_NV_notifyIndoors()` |
| hitByMeleeAttack | hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| _NV_hitByMeleeAttack | _NV_hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:_NV_hitByMeleeAttack(dir, comboID)` |
| getPlatoonAI | getPlatoonAI | `` | `lightuserdata` | `obj:getPlatoonAI()` |
| _NV_getPlatoonAI | _NV_getPlatoonAI | `` | `lightuserdata` | `obj:_NV_getPlatoonAI()` |

## RootObjectBase
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectBase.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| validKey | validKey | integer | RW | `obj.validKey = <value>` |
| owner | owner | Faction | RW | `obj.owner = <value>` |
| displayName | displayName | string | RW | `obj.displayName = <value>` |
| data | data | GameData | RW | `obj.data = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| handle | handle | hand | RW | `obj.handle = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isValid | isValid | `` | `boolean` | `obj:isValid()` |
| getName | getName | `` | `string` | `obj:getName()` |
| _NV_getName | _NV_getName | `` | `string` | `obj:_NV_getName()` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |
| _NV_setName | _NV_setName | `name: string` | `void` | `obj:_NV_setName(name)` |
| getGameData | getGameData | `` | `GameData` | `obj:getGameData()` |
| _NV_getGameData | _NV_getGameData | `` | `GameData` | `obj:_NV_getGameData()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| typeIsAnItem | typeIsAnItem | `` | `boolean` | `obj:typeIsAnItem()` |
| _NV_typeIsAnItem | _NV_typeIsAnItem | `` | `boolean` | `obj:_NV_typeIsAnItem()` |
| isUnconcious | isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| getPositionForWaypoint | getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| _NV_getPositionForWaypoint | _NV_getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:_NV_getPositionForWaypoint(from)` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getMovementSpeed | getMovementSpeed | `` | `number` | `obj:getMovementSpeed()` |
| _NV_getMovementSpeed | _NV_getMovementSpeed | `` | `number` | `obj:_NV_getMovementSpeed()` |
| getMovementDirection | getMovementDirection | `` | `Vector3` | `obj:getMovementDirection()` |
| _NV_getMovementDirection | _NV_getMovementDirection | `` | `Vector3` | `obj:_NV_getMovementDirection()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |
| _NV_getFaction | _NV_getFaction | `` | `Faction` | `obj:_NV_getFaction()` |
| hasFaction | hasFaction | `` | `boolean` | `obj:hasFaction()` |
| getFloor | getFloor | `` | `integer` | `obj:getFloor()` |
| _NV_getFloor | _NV_getFloor | `` | `integer` | `obj:_NV_getFloor()` |
| getOwnerships | getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| _NV_getOwnerships | _NV_getOwnerships | `` | `Ownerships` | `obj:_NV_getOwnerships()` |
| getHandle | getHandle | `` | `hand` | `obj:getHandle()` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RootObjectBase` | `obj:_CONSTRUCTOR()` |
| getSensoryData | getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| _NV_getSensoryData | _NV_getSensoryData | `` | `SensoryData` | `obj:_NV_getSensoryData()` |
| getStateBroadcast | getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| setHandle | setHandle | `` | `void` | `obj:setHandle()` |
| _NV_setHandle | _NV_setHandle | `` | `void` | `obj:_NV_setHandle()` |
| serialise | serialise | `offset: userdata` | `GameSaveState` | `obj:serialise(offset)` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |

## RootObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| things | things | lektor<RootObject*> | R | `obj.things` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `boolean` | `obj:update()` |
| _NV_update | _NV_update | `` | `boolean` | `obj:_NV_update()` |
| getThing | getThing | `id: integer` | `RootObject` | `obj:getThing(id)` |
| getNumThings | getNumThings | `` | `integer` | `obj:getNumThings()` |
| getThings | getThings | `` | `lektor<RootObject*>` | `obj:getThings()` |
| getSelectedObjects | getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| _NV_getSelectedObjects | _NV_getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:_NV_getSelectedObjects(type, selectedOnly)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `type: integer` | `RootObjectContainer` | `obj:_CONSTRUCTOR(type)` |
| addActiveObject | addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| removeObject | removeObject | `` | `boolean` | `obj:removeObject()` |
| _NV_removeObject | _NV_removeObject | `` | `boolean` | `obj:_NV_removeObject()` |
| serialiseThings | serialiseThings | `offset: userdata, mod: string, mod: string` | `void` | `obj:serialiseThings(offset, mod, mod)` |
| loadToReality | loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| _NV_loadToReality | _NV_loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:_NV_loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| loadInstance | loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |
| _NV_loadInstance | _NV_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:_NV_loadInstance(skipSaveState, pos, rot, positionMoved)` |

## RootObjectFactory
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| todoMutex | todoMutex | unknown | R | `obj.todoMutex` |
| todoList | todoList | std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> > | R | `obj.todoList` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| mainThreadUpdate | mainThreadUpdate | `` | `void` | `obj:mainThreadUpdate()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| create | create | `position: Vector3, isFromActiveLevelMod: boolean, rotation: Quaternion, invisible: boolean, age: number` | `RootObjectBase` | `obj:create(position, isFromActiveLevelMod, rotation, invisible, age)` |
| createBuilding | createBuilding | `position: Vector3, rotation: Quaternion, furnitureOf: userdata, invisible: boolean, completed: boolean, isFoliage: boolean, floorNumber: integer, isOutsideFurniture: boolean` | `Building` | `obj:createBuilding(position, rotation, furnitureOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture)` |
| createLocationNode | createLocationNode | `addToNodeListAutomatically: boolean, position: Vector3, rotation: Quaternion, nodeId: string` | `LocationNode*` | `obj:createLocationNode(addToNodeListAutomatically, position, rotation, nodeId)` |
| createItem | createItem | `levelOverride: integer` | `Item` | `obj:createItem(levelOverride)` |
| copyItem | copyItem | `` | `Item` | `obj:copyItem()` |
| chooseDataFromList | chooseDataFromList | `listName: string, materialDataType: integer, useVal012: integer` | `GameData` | `obj:chooseDataFromList(listName, materialDataType, useVal012)` |
| chooseDataFromListWithVals | chooseDataFromListWithVals | `listName: string, materialDataType: integer, useVal012: integer` | `const GameDataReference` | `obj:chooseDataFromListWithVals(listName, materialDataType, useVal012)` |
| getValsFromDataInList | getValsFromDataInList | `listName: string` | `integer` | `obj:getValsFromDataInList(listName)` |
| createCharacterForBuilding | createCharacterForBuilding | `` | `void` | `obj:createCharacterForBuilding()` |
| createRandomCharacter | createRandomCharacter | `position: Vector3, age: number` | `RootObject` | `obj:createRandomCharacter(position, age)` |
| createRandomUnloadedCharacter | createRandomUnloadedCharacter | `platoon: userdata, position: Vector3` | `GameSaveState` | `obj:createRandomUnloadedCharacter(platoon, position)` |
| createRandomSquad | createRandomSquad | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, sizeMultiplier: number, squadType: integer, isJustARefresh: boolean` | `Platoon` | `obj:createRandomSquad(position, maxnum, maparea, permanentsquad, sizeMultiplier, squadType, isJustARefresh)` |
| createRandomUnloadedSquad | createRandomUnloadedSquad | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, squadType: integer` | `Platoon` | `obj:createRandomUnloadedSquad(position, maxnum, maparea, permanentsquad, squadType)` |
| populateBuilding | populateBuilding | `` | `void` | `obj:populateBuilding()` |
| process | process | `` | `RootObjectBase` | `obj:process()` |

## SaveFileSystem
**Header:** `extern/KenshiLib/Include/kenshi/SaveFileSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentSave | currentSave | string | RW | `obj.currentSave = <value>` |
| currentFolder | currentFolder | string | RW | `obj.currentFolder = <value>` |
| tempFolder | tempFolder | string | RW | `obj.tempFolder = <value>` |
| currentPathIndex | currentPathIndex | integer | RW | `obj.currentPathIndex = <value>` |
| currentMutex | (void* | lightuserdata | R | `obj.currentMutex` |
| savingIcon | (void* | lightuserdata | R | `obj.savingIcon` |
| state | (lua_Integer | integer | RW | `obj.state = <value>` |
| failedToCopyError | failedToCopyError | string | RW | `obj.failedToCopyError = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| log | log | `message: string, level: integer` | `void` | `obj:log(message, level)` |
| setTemporaryPath | setTemporaryPath | `path: string` | `void` | `obj:setTemporaryPath(path)` |
| fileExists | fileExists | `name: string` | `boolean` | `obj:fileExists(name)` |
| readFile | readFile | `name: string` | `string` | `obj:readFile(name)` |
| writeFile | writeFile | `name: string` | `string` | `obj:writeFile(name)` |
| deleteFile | deleteFile | `name: string` | `void` | `obj:deleteFile(name)` |
| newGame | newGame | `` | `void` | `obj:newGame()` |
| loadGame | loadGame | `savePath: string` | `void` | `obj:loadGame(savePath)` |
| saveGame | saveGame | `savePath: string` | `boolean` | `obj:saveGame(savePath)` |
| sync | sync | `` | `void` | `obj:sync()` |
| analyse | analyse | `` | `void` | `obj:analyse()` |
| cleanup | cleanup | `full: boolean` | `void` | `obj:cleanup(full)` |
| scanForResidualTempFolders | scanForResidualTempFolders | `` | `void` | `obj:scanForResidualTempFolders()` |
| isTempFolder | isTempFolder | `f: string` | `boolean` | `obj:isTempFolder(f)` |
| busy | busy | `` | `boolean` | `obj:busy()` |
| createCurrent | createCurrent | `` | `void` | `obj:createCurrent()` |
| threadProc | threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| addMessage | addMessage | `type: integer, src: string, dst: string` | `void` | `obj:addMessage(type, src, dst)` |

## SaveManager
**Header:** `extern/KenshiLib/Include/kenshi/SaveManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentGame | currentGame | string | RW | `obj.currentGame = <value>` |
| saveVersion | saveVersion | string | RW | `obj.saveVersion = <value>` |
| localSavePath | localSavePath | string | RW | `obj.localSavePath = <value>` |
| userSavePath | userSavePath | string | RW | `obj.userSavePath = <value>` |
| signal | signal | integer | RW | `obj.signal = <value>` |
| flags | flags | integer | RW | `obj.flags = <value>` |
| delay | delay | integer | RW | `obj.delay = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| location | location | string | RW | `obj.location = <value>` |
| loadMenu | (void* | lightuserdata | R | `obj.loadMenu` |
| saveMenu | (void* | lightuserdata | R | `obj.saveMenu` |
| importMenu | (void* | lightuserdata | R | `obj.importMenu` |
| autoSaveTimer | autoSaveTimer | number | RW | `obj.autoSaveTimer = <value>` |
| pauseAutoSaveTimer | pauseAutoSaveTimer | boolean | RW | `obj.pauseAutoSaveTimer = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isVisible | isVisible | `` | `integer` | `obj:isVisible()` |
| showSave | showSave | `` | `void` | `obj:showSave()` |
| showLoad | showLoad | `` | `void` | `obj:showLoad()` |
| showImport | showImport | `` | `void` | `obj:showImport()` |
| hide | hide | `` | `void` | `obj:hide()` |
| newGame | newGame | `startId: string` | `void` | `obj:newGame(startId)` |
| save | save | `s: string, autosave: boolean` | `void` | `obj:save(s, autosave)` |
| savesExist | savesExist | `` | `boolean` | `obj:savesExist()` |
| saveExists | saveExists | `location: string, name: string` | `boolean` | `obj:saveExists(location, name)` |
| execute | execute | `` | `void` | `obj:execute()` |
| versionCode | versionCode | `version: string` | `integer` | `obj:versionCode(version)` |
| updateAutoSave | updateAutoSave | `` | `void` | `obj:updateAutoSave()` |
| initialisePaths | initialisePaths | `` | `void` | `obj:initialisePaths()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| saveGame | saveGame | `location: string, name: string` | `integer` | `obj:saveGame(location, name)` |
| loadGame | loadGame | `location: string, name: string` | `integer` | `obj:loadGame(location, name)` |
| importGame | importGame | `location: string, name: string, flags: integer` | `integer` | `obj:importGame(location, name, flags)` |
| importPlayerBuildings | importPlayerBuildings | `path: string, file: string` | `integer` | `obj:importPlayerBuildings(path, file)` |
| importOldPlayerBuildings | importOldPlayerBuildings | `path: string, name: string` | `integer` | `obj:importOldPlayerBuildings(path, name)` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| lastSeenInSeconds | lastSeenInSeconds | `` | `number` | `obj:lastSeenInSeconds()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| cancel | cancel | `` | `void` | `obj:cancel()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| ended | ended | `` | `boolean` | `obj:ended()` |
| increment | increment | `` | `void` | `obj:increment()` |

## SensoryData
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nearestEnemy | nearestEnemy | number | RW | `obj.nearestEnemy = <value>` |
| seen | seen | lightuserdata | R | `obj.seen` |
| numUnconsciousAllies | numUnconsciousAllies | integer | RW | `obj.numUnconsciousAllies = <value>` |
| numConsciousAllies | numConsciousAllies | integer | RW | `obj.numConsciousAllies = <value>` |
| threats | threats | lightuserdata | R | `obj.threats` |
| flockingList | flockingList | lightuserdata | R | `obj.flockingList` |
| totalThreatLevelPersonal | totalThreatLevelPersonal | number | RW | `obj.totalThreatLevelPersonal = <value>` |
| totalThreatLevelAllies | totalThreatLevelAllies | number | RW | `obj.totalThreatLevelAllies = <value>` |
| totalIntendedThreatLevelGeneral | totalIntendedThreatLevelGeneral | number | RW | `obj.totalIntendedThreatLevelGeneral = <value>` |
| numEnemies | numEnemies | integer | RW | `obj.numEnemies = <value>` |
| numNeutrals | numNeutrals | integer | RW | `obj.numNeutrals = <value>` |
| lastThreat | lastThreat | number | RW | `obj.lastThreat = <value>` |
| hearTestTimers | hearTestTimers | lightuserdata | R | `obj.hearTestTimers` |
| killList | killList | lightuserdata | R | `obj.killList` |
| currentAssessIndex | currentAssessIndex | integer | RW | `obj.currentAssessIndex = <value>` |
| currentAssessList | currentAssessList | integer | RW | `obj.currentAssessList = <value>` |
| assessList | assessList | lightuserdata | R | `obj.assessList` |
| me | me | Character | RW | `obj.me = <value>` |
| spottedSneakingPeople | spottedSneakingPeople | SensoryData::SpottingPeopleMgr | R | `obj.spottedSneakingPeople` |
| spottedSuspiciousPeople | spottedSuspiciousPeople | SensoryData::SpottingPeopleMgr | R | `obj.spottedSuspiciousPeople` |
| progressBar | progressBar | lightuserdata | RW | `obj.progressBar = <value>` |
| progressBarStillNeeded | progressBarStillNeeded | integer | RW | `obj.progressBarStillNeeded = <value>` |
| spottedGuyIndexForProgressBar | spottedGuyIndexForProgressBar | hand | RW | `obj.spottedGuyIndexForProgressBar = <value>` |
| amSharingThisFrame | amSharingThisFrame | boolean | RW | `obj.amSharingThisFrame = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| periodicUpdate_KOed | periodicUpdate_KOed | `` | `void` | `obj:periodicUpdate_KOed()` |
| getVisionRange | getVisionRange | `inTown: boolean` | `number` | `obj:getVisionRange(inTown)` |
| update | update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| notifyKO | notifyKO | `` | `void` | `obj:notifyKO()` |
| getNearestEnemyDistanceSq | getNearestEnemyDistanceSq | `` | `number` | `obj:getNearestEnemyDistanceSq()` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| dialogAssessmentUpdate | dialogAssessmentUpdate | `frameTime: number, inDepth: boolean` | `void` | `obj:dialogAssessmentUpdate(frameTime, inDepth)` |
| processKillList | processKillList | `` | `void` | `obj:processKillList()` |
| updateMyProgressBar | updateMyProgressBar | `progress: number, text: string` | `void` | `obj:updateMyProgressBar(progress, text)` |
| buildingSpotterUpdate | buildingSpotterUpdate | `` | `void` | `obj:buildingSpotterUpdate()` |
| getIterator | SensoryData_getIterator | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:getIterator(tagsAny, tagsNOT)` |
| canISeeThisGuy | SensoryData_canISeeThisGuy | `` | `boolean` | `obj:canISeeThisGuy()` |
| canIHearThisGuy | SensoryData_canIHearThisGuy | `` | `boolean` | `obj:canIHearThisGuy()` |
| amIAwareOfThisGuy | SensoryData_amIAwareOfThisGuy | `needToSeeOrHear: boolean` | `boolean` | `obj:amIAwareOfThisGuy(needToSeeOrHear)` |
| getLastKnownPositionOf | SensoryData_getLastKnownPositionOf | `` | `Vector3` | `obj:getLastKnownPositionOf()` |
| getDataFor | SensoryData_getDataFor | `` | `SeenSomeone` | `obj:getDataFor()` |
| notifyCriminalThreat | SensoryData_notifyCriminalThreat | `` | `void` | `obj:notifyCriminalThreat()` |
| getFactionRelation | SensoryData_getFactionRelation | `` | `number` | `obj:getFactionRelation()` |
| getStateBroadcast | SensoryData_getStateBroadcast | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:getStateBroadcast(tagsAny, tagsNOT)` |
| getStateBroadcastOf | SensoryData_getStateBroadcastOf | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:getStateBroadcastOf(tagsAny, tagsNOT)` |
| _shareSensesCheck | SensoryData__shareSensesCheck | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:_shareSensesCheck(tagsAny, tagsNOT)` |
| getGUIData | SensoryData_getGUIData | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:getGUIData(tagsAny, tagsNOT)` |
| _calculateFOVScore | SensoryData__calculateFOVScore | `` | `number` | `obj:_calculateFOVScore()` |
| _traceLineOfSightCheck | SensoryData__traceLineOfSightCheck | `` | `boolean` | `obj:_traceLineOfSightCheck()` |
| noticeThisPerson | SensoryData_noticeThisPerson | `alarmed: boolean` | `void` | `obj:noticeThisPerson(alarmed)` |
| add | SensoryData_add | `see: boolean, hear: boolean` | `SeenSomeone` | `obj:add(see, hear)` |
| remove | SensoryData_remove | `` | `void` | `obj:remove()` |
| decay | SensoryData_decay | `` | `void` | `obj:decay()` |
| canSee | SensoryData_canSee | `` | `boolean` | `obj:canSee()` |
| canHear | SensoryData_canHear | `` | `boolean` | `obj:canHear()` |
| disguiseMods | SensoryData_disguiseMods | `FOV: number` | `boolean` | `obj:disguiseMods(FOV)` |
| assessCrimes | SensoryData_assessCrimes | `` | `void` | `obj:assessCrimes()` |
| assessKidnapping | SensoryData_assessKidnapping | `` | `void` | `obj:assessKidnapping()` |
| assessNeutral | SensoryData_assessNeutral | `inDepth: boolean` | `void` | `obj:assessNeutral(inDepth)` |
| setupMyProgressBar | SensoryData_setupMyProgressBar | `` | `void` | `obj:setupMyProgressBar()` |
| canISeeThisGuyDoinSneakingOrSomething | SensoryData_canISeeThisGuyDoinSneakingOrSomething | `FOVScore: number, spotTimeMinFOV: number, spotTimeMaxFOV: number` | `integer` | `obj:canISeeThisGuyDoinSneakingOrSomething(FOVScore, spotTimeMinFOV, spotTimeMaxFOV)` |
| isIntruder_Base | SensoryData_isIntruder_Base | `` | `boolean` | `obj:isIntruder_Base()` |
| isIntruder_Building | SensoryData_isIntruder_Building | `` | `boolean` | `obj:isIntruder_Building()` |
| isInMyPrivate_Building | SensoryData_isInMyPrivate_Building | `` | `boolean` | `obj:isInMyPrivate_Building()` |
| isEscapee | SensoryData_isEscapee | `` | `boolean` | `obj:isEscapee()` |
| reassessAll | SensoryData_reassessAll | `newTargets: userdata, time: number` | `void` | `obj:reassessAll(newTargets, time)` |
| reassess | SensoryData_reassess | `time: number` | `SeenSomeone` | `obj:reassess(time)` |
| addToThreatsAndFlockingList | SensoryData_addToThreatsAndFlockingList | `` | `void` | `obj:addToThreatsAndFlockingList()` |

## ShopTrader
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| trader | trader | Character | R | `obj.trader` |
| inventory | inventory | Inventory | R | `obj.inventory` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| takeMoney | takeMoney | `money: integer` | `boolean` | `obj:takeMoney(money)` |
| _NV_takeMoney | _NV_takeMoney | `money: integer` | `boolean` | `obj:_NV_takeMoney(money)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| getOrientation | getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| _NV_getOrientation | _NV_getOrientation | `` | `Quaternion` | `obj:_NV_getOrientation()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getFloor | getFloor | `` | `integer` | `obj:getFloor()` |
| _NV_getFloor | _NV_getFloor | `` | `integer` | `obj:_NV_getFloor()` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| getTrader | getTrader | `` | `Character` | `obj:getTrader()` |
| isPhysical | isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| updateInventory | updateInventory | `` | `void` | `obj:updateInventory()` |
| equipItem | equipItem | `sectionName: string` | `void` | `obj:equipItem(sectionName)` |
| _NV_equipItem | _NV_equipItem | `sectionName: string` | `void` | `obj:_NV_equipItem(sectionName)` |
| unequipItem | unequipItem | `sectionName: string` | `void` | `obj:unequipItem(sectionName)` |
| _NV_unequipItem | _NV_unequipItem | `sectionName: string` | `void` | `obj:_NV_unequipItem(sectionName)` |

## ShopTraderInventory
**Header:** `extern/KenshiLib/Include/kenshi/ShopTraderInventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| inventories | inventories | ogre_unordered_map<hand, InventorySection*>::type | R | `obj.inventories` |
| section | (void* | lightuserdata | R | `obj.section` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateInventory | updateInventory | `` | `void` | `obj:updateInventory()` |
| _NV_updateInventory | _NV_updateInventory | `` | `void` | `obj:_NV_updateInventory()` |
| refreshGui | refreshGui | `` | `void` | `obj:refreshGui()` |
| _NV_refreshGui | _NV_refreshGui | `` | `void` | `obj:_NV_refreshGui()` |
| initialiseNewSection | initialiseNewSection | `name: string, w: integer, h: integer, _a4: integer, equipCallbacks: boolean, _a6: boolean, _a7: boolean, _a8: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8)` |
| _NV_initialiseNewSection | _NV_initialiseNewSection | `name: string, w: integer, h: integer, _a4: integer, equipCallbacks: boolean, _a6: boolean, _a7: boolean, _a8: integer` | `InventorySection` | `obj:_NV_initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8)` |

## ShopTraderInventorySection
**Header:** `extern/KenshiLib/Include/kenshi/ShopTraderInventory.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| autoArrange | autoArrange | `` | `void` | `obj:autoArrange()` |
| _NV_autoArrange | _NV_autoArrange | `` | `void` | `obj:_NV_autoArrange()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| addItem | addItem | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |
| _NV_addItem | _NV_addItem | `quantity: integer` | `boolean` | `obj:_NV_addItem(quantity)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `name: string, w: integer, h: integer` | `ShopTraderInventorySection` | `obj:_CONSTRUCTOR(name, w, h)` |

## SimpleTimeStamper
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timer | timer | CPerfTimer | R | `obj.timer` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getTime | getTime | `_lastStamp: number` | `number` | `obj:getTime(_lastStamp)` |
| stampTime | stampTime | `` | `number` | `obj:stampTime()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| flip | flip | `` | `void` | `obj:flip()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | update | `time: number` | `void` | `obj:update(time)` |
| resetSeenFlags | resetSeenFlags | `` | `void` | `obj:resetSeenFlags()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Stat
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| type | (lua_Integer | integer | RW | `obj.type = <value>` |
| id | id | string | RW | `obj.id = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| description | description | string | RW | `obj.description = <value>` |
| active | active | boolean | RW | `obj.active = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## StatGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| group | (lua_Integer | integer | RW | `obj.group = <value>` |
| name | name | string | RW | `obj.name = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## StateT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _zoneBeingLoaded | _zoneBeingLoaded | boolean | RW | `obj._zoneBeingLoaded = <value>` |
| _zoneIsLoaded | _zoneIsLoaded | boolean | RW | `obj._zoneIsLoaded = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## StorageBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| specialItemTypesOnly | (lua_Integer | integer | RW | `obj.specialItemTypesOnly = <value>` |
| endOfTheLine | endOfTheLine | boolean | RW | `obj.endOfTheLine = <value>` |
| productionItem | (void* | lightuserdata | R | `obj.productionItem` |
| manyLimitItems | manyLimitItems | lektor<StorageBuilding::ConsumptionItem*> | R | `obj.manyLimitItems` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getFunctionStuff | getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| _NV_getFunctionStuff | _NV_getFunctionStuff | `` | `StorageBuilding` | `obj:_NV_getFunctionStuff()` |
| getUseableStuff | getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getProductionItemData | getProductionItemData | `` | `GameData` | `obj:getProductionItemData()` |
| _NV_getProductionItemData | _NV_getProductionItemData | `` | `GameData` | `obj:_NV_getProductionItemData()` |
| getProductionItem | getProductionItem | `` | `lightuserdata` | `obj:getProductionItem()` |
| getCurrentProductionQuantity | getCurrentProductionQuantity | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| _NV_getCurrentProductionQuantity | _NV_getCurrentProductionQuantity | `` | `integer` | `obj:_NV_getCurrentProductionQuantity()` |
| isAnyInputsEmpty | isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| isAnyInputsFull | isAnyInputsFull | `` | `boolean` | `obj:isAnyInputsFull()` |
| _NV_isAnyInputsFull | _NV_isAnyInputsFull | `` | `boolean` | `obj:_NV_isAnyInputsFull()` |
| isProductionFull | isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| isProductionEmpty | isProductionEmpty | `` | `boolean` | `obj:isProductionEmpty()` |
| _NV_isProductionEmpty | _NV_isProductionEmpty | `` | `boolean` | `obj:_NV_isProductionEmpty()` |
| getNumConsumtionItems | getNumConsumtionItems | `` | `integer` | `obj:getNumConsumtionItems()` |
| _NV_getNumConsumtionItems | _NV_getNumConsumtionItems | `` | `integer` | `obj:_NV_getNumConsumtionItems()` |
| getConsumtionItems | getConsumtionItems | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| _NV_getConsumtionItems | _NV_getConsumtionItems | `id: integer` | `lightuserdata` | `obj:_NV_getConsumtionItems(id)` |
| limitedByType | limitedByType | `` | `boolean` | `obj:limitedByType()` |
| updateInventoryWindow | updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| _NV_updateInventoryWindow | _NV_updateInventoryWindow | `` | `void` | `obj:_NV_updateInventoryWindow()` |

## StringPair
**Header:** `extern/KenshiLib/Include/kenshi/util/StringPair.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| s1 | s1 | string | RW | `obj.s1 = <value>` |
| s2 | s2 | string | RW | `obj.s2 = <value>` |
| val1 | val1 | number | RW | `obj.val1 = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Sword
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| cutDamage | cutDamage | number | RW | `obj.cutDamage = <value>` |
| bluntDamage | bluntDamage | number | RW | `obj.bluntDamage = <value>` |
| minCutDamage | minCutDamage | number | RW | `obj.minCutDamage = <value>` |
| modDefence | modDefence | integer | RW | `obj.modDefence = <value>` |
| modIndoors | modIndoors | integer | RW | `obj.modIndoors = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| isSword | isSword | `` | `Sword` | `obj:isSword()` |
| _NV_isSword | _NV_isSword | `` | `Sword` | `obj:_NV_isSword()` |
| getSkillModIndoors | getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| _NV_getSkillModIndoors | _NV_getSkillModIndoors | `` | `integer` | `obj:_NV_getSkillModIndoors()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCharacteristics | setCharacteristics | `_aid: number, _aggressionLevel: number, noise: number, leadsSomewhere: boolean` | `void` | `obj:setCharacteristics(_aid, _aggressionLevel, noise, leadsSomewhere)` |
| setInfrequentGoalChecks | setInfrequentGoalChecks | `` | `void` | `obj:setInfrequentGoalChecks()` |
| setAlertnessMult | setAlertnessMult | `a: number` | `void` | `obj:setAlertnessMult(a)` |
| setRequirementsCantEndActionPrematurely | setRequirementsCantEndActionPrematurely | `on: boolean` | `void` | `obj:setRequirementsCantEndActionPrematurely(on)` |
| setCopyMeInfluence | setCopyMeInfluence | `weight: number` | `void` | `obj:setCopyMeInfluence(weight)` |
| setFollowMeWeight | setFollowMeWeight | `weight: number` | `void` | `obj:setFollowMeWeight(weight)` |
| setSelfRegulation | setSelfRegulation | `requirements: boolean, results: boolean` | `void` | `obj:setSelfRegulation(requirements, results)` |
| setDurationBased | setDurationBased | `mintime: number, fuzz: number, _endsAfterTime: boolean` | `void` | `obj:setDurationBased(mintime, fuzz, _endsAfterTime)` |
| hasInfrequentGoalChecks | hasInfrequentGoalChecks | `` | `boolean` | `obj:hasInfrequentGoalChecks()` |
| getRequirementsCantEndActionPrematurely | getRequirementsCantEndActionPrematurely | `` | `boolean` | `obj:getRequirementsCantEndActionPrematurely()` |
| isPermaJob | isPermaJob | `` | `boolean` | `obj:isPermaJob()` |
| isPermaJobFixedTarget | isPermaJobFixedTarget | `` | `boolean` | `obj:isPermaJobFixedTarget()` |
| getPermaJobAssociation | getPermaJobAssociation | `` | `integer` | `obj:getPermaJobAssociation()` |
| getPermaJobAssociation_secondary | getPermaJobAssociation_secondary | `` | `integer` | `obj:getPermaJobAssociation_secondary()` |
| isTargetFinder | isTargetFinder | `` | `boolean` | `obj:isTargetFinder()` |
| setDialogueDeliveryTag | setDialogueDeliveryTag | `d: integer` | `void` | `obj:setDialogueDeliveryTag(d)` |

## TaskStateData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| key | key | StateType | R | `obj.key` |
| val | val | boolean | RW | `obj.val = <value>` |
| progressionOnly | progressionOnly | boolean | RW | `obj.progressionOnly = <value>` |

## Tasker
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| priority | (lua_Integer | integer | RW | `obj.priority = <value>` |
| resetsWhenDone | resetsWhenDone | boolean | RW | `obj.resetsWhenDone = <value>` |
| subject | subject | hand | RW | `obj.subject = <value>` |
| weight | weight | number | RW | `obj.weight = <value>` |
| currentSubTarget | currentSubTarget | hand | RW | `obj.currentSubTarget = <value>` |
| location | location | Vector3 | RW | `obj.location = <value>` |
| startTime | startTime | integer | RW | `obj.startTime = <value>` |
| endTime | endTime | integer | RW | `obj.endTime = <value>` |
| taskData | taskData | TaskData | RW | `obj.taskData = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| checkTimeOfDay | checkTimeOfDay | `` | `boolean` | `obj:checkTimeOfDay()` |
| key | key | `` | `integer` | `obj:key()` |
| unSkippableJob | unSkippableJob | `` | `boolean` | `obj:unSkippableJob()` |
| getLocation | getLocation | `` | `Vector3` | `obj:getLocation()` |
| setLocation | setLocation | `loc: Vector3` | `void` | `obj:setLocation(loc)` |
| hasActionFunc | hasActionFunc | `` | `boolean` | `obj:hasActionFunc()` |
| isSubTasker | isSubTasker | `` | `boolean` | `obj:isSubTasker()` |
| isInfiniteGoal | isInfiniteGoal | `` | `boolean` | `obj:isInfiniteGoal()` |
| needsSubjectOrLocation | needsSubjectOrLocation | `` | `boolean` | `obj:needsSubjectOrLocation()` |
| getTaskData | getTaskData | `` | `TaskData` | `obj:getTaskData()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Tasker` | `obj:_CONSTRUCTOR()` |
| getFrameTime | getFrameTime | `` | `number` | `obj:getFrameTime()` |
| sameAs | sameAs | `` | `boolean` | `obj:sameAs()` |
| score | score | `ai: userdata` | `number` | `obj:score(ai)` |
| isResultsComplete | isResultsComplete | `ai: userdata` | `boolean` | `obj:isResultsComplete(ai)` |
| isResultsComplete_ignoreSubtasker | isResultsComplete_ignoreSubtasker | `ai: userdata` | `boolean` | `obj:isResultsComplete_ignoreSubtasker(ai)` |
| isRequirementsComplete | isRequirementsComplete | `ai: userdata, autoTargetFinder: boolean` | `boolean` | `obj:isRequirementsComplete(ai, autoTargetFinder)` |
| getRequirementComplaint | getRequirementComplaint | `ai: userdata, autoTargetFinder: boolean` | `string` | `obj:getRequirementComplaint(ai, autoTargetFinder)` |
| getNextSubTarget | getNextSubTarget | `ai: userdata` | `hand` | `obj:getNextSubTarget(ai)` |
| getSubTask | getSubTask | `` | `TaskStateData` | `obj:getSubTask()` |

## TextureArrayLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| loadImage | loadImage | `` | `void` | `obj:loadImage()` |
| _NV_loadImage | _NV_loadImage | `` | `void` | `obj:_NV_loadImage()` |

## TextureLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |
| group | group | string | RW | `obj.group = <value>` |
| loaded | loaded | boolean | RW | `obj.loaded = <value>` |
| queued | queued | boolean | RW | `obj.queued = <value>` |
| success | success | boolean | RW | `obj.success = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `name: string, group: string` | `lightuserdata` | `obj:_CONSTRUCTOR(name, group)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| loadImage | loadImage | `` | `void` | `obj:loadImage()` |
| _NV_loadImage | _NV_loadImage | `` | `void` | `obj:_NV_loadImage()` |

## TimeOfDay
**Header:** `extern/KenshiLib/Include/kenshi/util/TimeOfDay.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| time | time | number | RW | `obj.time = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setNull | setNull | `` | `void` | `obj:setNull()` |
| isUnset | isUnset | `` | `boolean` | `obj:isUnset()` |
| setTime | setTime | `hrs: number` | `void` | `obj:setTime(hrs)` |
| addHours | addHours | `hours: number` | `void` | `obj:addHours(hours)` |
| addMinutes | addMinutes | `mins: number` | `void` | `obj:addMinutes(mins)` |
| getTotalHours | getTotalHours | `` | `number` | `obj:getTotalHours()` |
| getTotalMinutes | getTotalMinutes | `` | `number` | `obj:getTotalMinutes()` |
| getTotalSeconds | getTotalSeconds | `` | `number` | `obj:getTotalSeconds()` |
| getRealLifeSeconds | getRealLifeSeconds | `` | `number` | `obj:getRealLifeSeconds()` |
| getRealLifeSecondsPassed | getRealLifeSecondsPassed | `` | `number` | `obj:getRealLifeSecondsPassed()` |
| getTotalDays | getTotalDays | `` | `number` | `obj:getTotalDays()` |
| stampTime | stampTime | `` | `void` | `obj:stampTime()` |
| getHoursPassed | getHoursPassed | `` | `number` | `obj:getHoursPassed()` |
| getMinutesPassed | getMinutesPassed | `` | `number` | `obj:getMinutesPassed()` |
| getSecondsPassed | getSecondsPassed | `` | `number` | `obj:getSecondsPassed()` |
| timeOfDayHasPassed | timeOfDayHasPassed | `additionalHours: number` | `boolean` | `obj:timeOfDayHasPassed(additionalHours)` |
| timePassed | timePassed | `` | `number` | `obj:timePassed()` |
| getTimePassedString | getTimePassedString | `` | `string` | `obj:getTimePassedString()` |
| getTimeRemainingString | getTimeRemainingString | `` | `string` | `obj:getTimeRemainingString()` |
| getTotalTimeString | getTotalTimeString | `` | `string` | `obj:getTotalTimeString()` |

## ToolTip
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| panel | (void* | lightuserdata | RW | `obj.panel = <value>` |
| panelWidth | panelWidth | integer | RW | `obj.panelWidth = <value>` |
| lineMarginH | lineMarginH | number | RW | `obj.lineMarginH = <value>` |
| panelMarginV | panelMarginV | integer | RW | `obj.panelMarginV = <value>` |
| lineSpacing | lineSpacing | integer | RW | `obj.lineSpacing = <value>` |
| caller | (void* | lightuserdata | R | `obj.caller` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| hide | hide | `` | `void` | `obj:hide()` |
| _NV_hide | _NV_hide | `` | `void` | `obj:_NV_hide()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |
| addLine | addLine | `textLeft: string, textRight: string` | `void` | `obj:addLine(textLeft, textRight)` |
| clearLines | clearLines | `` | `void` | `obj:clearLines()` |

## ToolTipDynamic
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## ToolTipFixed
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| parentPanel | (void* | lightuserdata | R | `obj.parentPanel` |
| minHeight | minHeight | integer | RW | `obj.minHeight = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## ToolTipInventory
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| compareTooltip | (void* | lightuserdata | R | `obj.compareTooltip` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |

## ToolTipLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| content | (void* | lightuserdata | R | `obj.content` |
| leftBox | (void* | lightuserdata | R | `obj.leftBox` |
| rightBox | (void* | lightuserdata | R | `obj.rightBox` |
| width | width | integer | RW | `obj.width = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ToolTipStatic
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## TortureBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TortureBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timer | timer | number | RW | `obj.timer = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getFunctionStuff | getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| _NV_getFunctionStuff | _NV_getFunctionStuff | `` | `StorageBuilding` | `obj:_NV_getFunctionStuff()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Town
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| replacementTown | replacementTown | GameData | R | `obj.replacementTown` |
| isAccessible | isAccessible | boolean | RW | `obj.isAccessible = <value>` |
| alarms | (void* | lightuserdata | RW | `obj.alarms = <value>` |
| instanceID | instanceID | InstanceID | RW | `obj.instanceID = <value>` |
| openToPublic | openToPublic | boolean | RW | `obj.openToPublic = <value>` |
| minFoliageRange | minFoliageRange | number | RW | `obj.minFoliageRange = <value>` |
| playerTownLevel | playerTownLevel | integer | RW | `obj.playerTownLevel = <value>` |
| gates | gates | ogre_unordered_set<hand>::type | RW | `obj.gates = <value>` |
| playerHasBuildingsInThisTown | playerHasBuildingsInThisTown | boolean | RW | `obj.playerHasBuildingsInThisTown = <value>` |
| powerInList | powerInList | hand | RW | `obj.powerInList = <value>` |
| powerOutList | powerOutList | ogre_unordered_set<hand>::type | RW | `obj.powerOutList = <value>` |
| batteryList | batteryList | ogre_unordered_set<hand>::type | RW | `obj.batteryList = <value>` |
| batteryMode | batteryMode | boolean | RW | `obj.batteryMode = <value>` |
| power_Stat | power_Stat | number | RW | `obj.power_Stat = <value>` |
| maxPower_Stat | maxPower_Stat | number | RW | `obj.maxPower_Stat = <value>` |
| neededPowerTotal_Stat | neededPowerTotal_Stat | number | RW | `obj.neededPowerTotal_Stat = <value>` |
| batteryPowerTotal_Stat | batteryPowerTotal_Stat | number | RW | `obj.batteryPowerTotal_Stat = <value>` |
| batteryDrain_Stat | batteryDrain_Stat | number | RW | `obj.batteryDrain_Stat = <value>` |
| batteryChargingupTotal | batteryChargingupTotal | number | RW | `obj.batteryChargingupTotal = <value>` |
| batteryCharge_Stat | batteryCharge_Stat | number | RW | `obj.batteryCharge_Stat = <value>` |
| batteryChargeMax_Stat | batteryChargeMax_Stat | number | RW | `obj.batteryChargeMax_Stat = <value>` |
| _facilitesWeHaveHere | (lua_Integer | integer | RW | `obj._facilitesWeHaveHere = <value>` |
| tradeCulture | tradeCulture | TradeCulture | RW | `obj.tradeCulture = <value>` |
| tradeGoodsMults | tradeGoodsMults | unknown | RW | `obj.tradeGoodsMults = <value>` |
| buildingMaterial | buildingMaterial | GameData | RW | `obj.buildingMaterial = <value>` |
| distantTown | (void* | lightuserdata | RW | `obj.distantTown = <value>` |
| nestSpots | nestSpots | Vector3 | RW | `obj.nestSpots = <value>` |
| nestsLoaded | nestsLoaded | boolean | RW | `obj.nestsLoaded = <value>` |
| overrideRange | overrideRange | number | RW | `obj.overrideRange = <value>` |
| townRangeMultiplier | townRangeMultiplier | number | RW | `obj.townRangeMultiplier = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| initialiseResidentData | initialiseResidentData | `` | `void` | `obj:initialiseResidentData()` |
| getGameData | getGameData | `` | `GameData` | `obj:getGameData()` |
| _NV_getGameData | _NV_getGameData | `` | `GameData` | `obj:_NV_getGameData()` |
| getOriginalGameData | getOriginalGameData | `` | `GameData` | `obj:getOriginalGameData()` |
| _reset | _reset | `` | `void` | `obj:_reset()` |
| _NV__reset | _NV__reset | `` | `void` | `obj:_NV__reset()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| reassessTownPosition | reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| _NV_reassessTownPosition | _NV_reassessTownPosition | `` | `void` | `obj:_NV_reassessTownPosition()` |
| showDistantTown | showDistantTown | `vis: boolean` | `void` | `obj:showDistantTown(vis)` |
| isOutpost | isOutpost | `` | `boolean` | `obj:isOutpost()` |
| spawnTheBarFlies | spawnTheBarFlies | `` | `void` | `obj:spawnTheBarFlies()` |
| townLoadedEvent | townLoadedEvent | `newGameFirstTime: boolean` | `void` | `obj:townLoadedEvent(newGameFirstTime)` |
| notifyUnloading | notifyUnloading | `` | `void` | `obj:notifyUnloading()` |
| getBuildingMaterial | getBuildingMaterial | `` | `GameData` | `obj:getBuildingMaterial()` |
| isTown | isTown | `` | `Town` | `obj:isTown()` |
| _NV_isTown | _NV_isTown | `` | `Town` | `obj:_NV_isTown()` |
| isPublic | isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| needsSaving | needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| _NV_needsSaving | _NV_needsSaving | `mod: string` | `boolean` | `obj:_NV_needsSaving(mod)` |
| setPosition | setPosition | `p: Vector3` | `void` | `obj:setPosition(p)` |
| getRadius | getRadius | `` | `number` | `obj:getRadius()` |
| _NV_getRadius | _NV_getRadius | `` | `number` | `obj:_NV_getRadius()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| _NV_isActive | _NV_isActive | `` | `boolean` | `obj:_NV_isActive()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| updatePowerGrid | updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| _NV_updatePowerGrid | _NV_updatePowerGrid | `` | `void` | `obj:_NV_updatePowerGrid()` |
| gatesAllClosed | gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| _NV_gatesAllClosed | _NV_gatesAllClosed | `` | `boolean` | `obj:_NV_gatesAllClosed()` |
| hasGates | hasGates | `` | `boolean` | `obj:hasGates()` |
| _NV_hasGates | _NV_hasGates | `` | `boolean` | `obj:_NV_hasGates()` |
| notifyAccesibility | notifyAccesibility | `accessible: boolean` | `void` | `obj:notifyAccesibility(accessible)` |
| getPositionOutsideTownGates | getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| _NV_getPositionOutsideTownGates | _NV_getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:_NV_getPositionOutsideTownGates(dist)` |
| isPlayerBuildingsInThisTown | isPlayerBuildingsInThisTown | `` | `boolean` | `obj:isPlayerBuildingsInThisTown()` |
| setPlayerBuildingsInThisTown | setPlayerBuildingsInThisTown | `` | `void` | `obj:setPlayerBuildingsInThisTown()` |
| getRequiredPower | getRequiredPower | `` | `number` | `obj:getRequiredPower()` |
| getTotalPower | getTotalPower | `` | `number` | `obj:getTotalPower()` |
| hasSparePower | hasSparePower | `` | `boolean` | `obj:hasSparePower()` |
| getBatteryDrain | getBatteryDrain | `` | `number` | `obj:getBatteryDrain()` |
| getBatteryChargeMax | getBatteryChargeMax | `` | `number` | `obj:getBatteryChargeMax()` |
| getBatteryCharge | getBatteryCharge | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryCharge01 | getBatteryCharge01 | `` | `number` | `obj:getBatteryCharge01()` |
| getBatteryChargingUpAmount | getBatteryChargingUpAmount | `` | `number` | `obj:getBatteryChargingUpAmount()` |
| getBatteryPowerTotal | getBatteryPowerTotal | `` | `number` | `obj:getBatteryPowerTotal()` |
| isBatteryMode | isBatteryMode | `` | `boolean` | `obj:isBatteryMode()` |
| clearNests | clearNests | `` | `void` | `obj:clearNests()` |
| getMapMarker | getMapMarker | `` | `string` | `obj:getMapMarker()` |
| _NV_getMapMarker | _NV_getMapMarker | `` | `string` | `obj:_NV_getMapMarker()` |
| getMapMarkerZoomLevel | getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| _NV_getMapMarkerZoomLevel | _NV_getMapMarkerZoomLevel | `` | `integer` | `obj:_NV_getMapMarkerZoomLevel()` |
| recalculatePlayerTownLevel | recalculatePlayerTownLevel | `` | `void` | `obj:recalculatePlayerTownLevel()` |
| deActivationCheck | deActivationCheck | `` | `void` | `obj:deActivationCheck()` |
| addBuilding | Town_addBuilding | `powerIn: boolean, powerOut: boolean, battery: boolean` | `void` | `obj:addBuilding(powerIn, powerOut, battery)` |
| removeBuilding | Town_removeBuilding | `` | `void` | `obj:removeBuilding()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Town` | `obj:_CONSTRUCTOR()` |
| notifyRepopulation | notifyRepopulation | `` | `void` | `obj:notifyRepopulation()` |
| isMyOldHomeTownStillValid | isMyOldHomeTownStillValid | `` | `boolean` | `obj:isMyOldHomeTownStillValid()` |
| setup | setup | `pos: Vector3` | `void` | `obj:setup(pos)` |
| _NV_setup | _NV_setup | `pos: Vector3` | `void` | `obj:_NV_setup(pos)` |
| getAlarmMgr | getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| _NV_getAlarmMgr | _NV_getAlarmMgr | `` | `lightuserdata` | `obj:_NV_getAlarmMgr()` |
| _setMainResident | _setMainResident | `forceForGates: boolean` | `boolean` | `obj:_setMainResident(forceForGates)` |
| chooseResidents | chooseResidents | `` | `void` | `obj:chooseResidents()` |
| chooseBuildingForResident | chooseBuildingForResident | `` | `Building` | `obj:chooseBuildingForResident()` |

## TownBase
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

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
| residentsSpawned | residentsSpawned | lektor<TownBase::ResidentData> | RW | `obj.residentsSpawned = <value>` |
| residentsSpawned_BarsOrSomething | residentsSpawned_BarsOrSomething | lektor<TownBase::ResidentData> | RW | `obj.residentsSpawned_BarsOrSomething = <value>` |
| defaultResident | defaultResident | GameData | R | `obj.defaultResident` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| _NV_isActive | _NV_isActive | `` | `boolean` | `obj:_NV_isActive()` |
| _reset | _reset | `` | `void` | `obj:_reset()` |
| _NV__reset | _NV__reset | `` | `void` | `obj:_NV__reset()` |
| getKnownName | getKnownName | `` | `string` | `obj:getKnownName()` |
| reassessTownPosition | reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| _NV_reassessTownPosition | _NV_reassessTownPosition | `` | `void` | `obj:_NV_reassessTownPosition()` |
| isNotFriendly | isNotFriendly | `` | `boolean` | `obj:isNotFriendly()` |
| _NV_isNotFriendly | _NV_isNotFriendly | `` | `boolean` | `obj:_NV_isNotFriendly()` |
| isPhysical | isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| isTown | isTown | `` | `Town` | `obj:isTown()` |
| _NV_isTown | _NV_isTown | `` | `Town` | `obj:_NV_isTown()` |
| isOutpost | isOutpost | `` | `boolean` | `obj:isOutpost()` |
| withinBordersRange | withinBordersRange | `p: Vector3, mult: number` | `boolean` | `obj:withinBordersRange(p, mult)` |
| withinDiscoveryRange | withinDiscoveryRange | `p: Vector3, explored: boolean` | `boolean` | `obj:withinDiscoveryRange(p, explored)` |
| distanceTo | distanceTo | `to: Vector3` | `number` | `obj:distanceTo(to)` |
| squaredDistanceTo | squaredDistanceTo | `to: Vector3` | `number` | `obj:squaredDistanceTo(to)` |
| isDead | isDead | `` | `boolean` | `obj:isDead()` |
| _NV_isDead | _NV_isDead | `` | `boolean` | `obj:_NV_isDead()` |
| getPositionOutsideTownGates | getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| _NV_getPositionOutsideTownGates | _NV_getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:_NV_getPositionOutsideTownGates(dist)` |
| isPublic | isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| getRadius | getRadius | `` | `number` | `obj:getRadius()` |
| _NV_getRadius | _NV_getRadius | `` | `number` | `obj:_NV_getRadius()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| updatePowerGrid | updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| _NV_updatePowerGrid | _NV_updatePowerGrid | `` | `void` | `obj:_NV_updatePowerGrid()` |
| allBuildingsDoorsOpen | allBuildingsDoorsOpen | `` | `boolean` | `obj:allBuildingsDoorsOpen()` |
| _NV_allBuildingsDoorsOpen | _NV_allBuildingsDoorsOpen | `` | `boolean` | `obj:_NV_allBuildingsDoorsOpen()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getPositionForWaypoint | getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| _NV_getPositionForWaypoint | _NV_getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:_NV_getPositionForWaypoint(from)` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| hasGates | hasGates | `` | `boolean` | `obj:hasGates()` |
| _NV_hasGates | _NV_hasGates | `` | `boolean` | `obj:_NV_hasGates()` |
| gatesAllClosed | gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| _NV_gatesAllClosed | _NV_gatesAllClosed | `` | `boolean` | `obj:_NV_gatesAllClosed()` |
| isRecentlyDiscovered | isRecentlyDiscovered | `` | `boolean` | `obj:isRecentlyDiscovered()` |
| _NV_isRecentlyDiscovered | _NV_isRecentlyDiscovered | `` | `boolean` | `obj:_NV_isRecentlyDiscovered()` |
| setRecentlyDiscovered | setRecentlyDiscovered | `value: boolean` | `void` | `obj:setRecentlyDiscovered(value)` |
| _NV_setRecentlyDiscovered | _NV_setRecentlyDiscovered | `value: boolean` | `void` | `obj:_NV_setRecentlyDiscovered(value)` |
| isDiscovered | isDiscovered | `` | `boolean` | `obj:isDiscovered()` |
| _NV_isDiscovered | _NV_isDiscovered | `` | `boolean` | `obj:_NV_isDiscovered()` |
| setDiscovered | setDiscovered | `value: boolean` | `void` | `obj:setDiscovered(value)` |
| _NV_setDiscovered | _NV_setDiscovered | `value: boolean` | `void` | `obj:_NV_setDiscovered(value)` |
| setDead | setDead | `` | `void` | `obj:setDead()` |
| _NV_setDead | _NV_setDead | `` | `void` | `obj:_NV_setDead()` |
| isExplored | isExplored | `` | `boolean` | `obj:isExplored()` |
| _NV_isExplored | _NV_isExplored | `` | `boolean` | `obj:_NV_isExplored()` |
| setExplored | setExplored | `value: boolean` | `void` | `obj:setExplored(value)` |
| _NV_setExplored | _NV_setExplored | `value: boolean` | `void` | `obj:_NV_setExplored(value)` |
| getItemArtifactsMinValue | getItemArtifactsMinValue | `` | `integer` | `obj:getItemArtifactsMinValue()` |
| _NV_getItemArtifactsMinValue | _NV_getItemArtifactsMinValue | `` | `integer` | `obj:_NV_getItemArtifactsMinValue()` |
| getItemArtifactsMaxValue | getItemArtifactsMaxValue | `` | `integer` | `obj:getItemArtifactsMaxValue()` |
| _NV_getItemArtifactsMaxValue | _NV_getItemArtifactsMaxValue | `` | `integer` | `obj:_NV_getItemArtifactsMaxValue()` |
| getGearArtifactsMinValue | getGearArtifactsMinValue | `` | `integer` | `obj:getGearArtifactsMinValue()` |
| _NV_getGearArtifactsMinValue | _NV_getGearArtifactsMinValue | `` | `integer` | `obj:_NV_getGearArtifactsMinValue()` |
| getGearArtifactsMaxValue | getGearArtifactsMaxValue | `` | `integer` | `obj:getGearArtifactsMaxValue()` |
| _NV_getGearArtifactsMaxValue | _NV_getGearArtifactsMaxValue | `` | `integer` | `obj:_NV_getGearArtifactsMaxValue()` |
| resetBuildingsFloorVisibility | resetBuildingsFloorVisibility | `` | `void` | `obj:resetBuildingsFloorVisibility()` |
| getTownFloorVisiblity | getTownFloorVisiblity | `` | `integer` | `obj:getTownFloorVisiblity()` |
| setTownFloorVisiblity | setTownFloorVisiblity | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setTownFloorVisiblity(floor, onlyPlayerBuildings)` |
| resetTownFloorVisibility | resetTownFloorVisibility | `` | `void` | `obj:resetTownFloorVisibility()` |
| getMapMarker | getMapMarker | `` | `string` | `obj:getMapMarker()` |
| _NV_getMapMarker | _NV_getMapMarker | `` | `string` | `obj:_NV_getMapMarker()` |
| getMapMarkerZoomLevel | getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| _NV_getMapMarkerZoomLevel | _NV_getMapMarkerZoomLevel | `` | `integer` | `obj:_NV_getMapMarkerZoomLevel()` |
| isOccupied | isOccupied | `` | `boolean` | `obj:isOccupied()` |
| distributeArtifacts | distributeArtifacts | `` | `void` | `obj:distributeArtifacts()` |
| setFaction | TownBase_setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | TownBase__NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| findAllBuildingsOfType | TownBase_findAllBuildingsOfType | `func: integer` | `lektor<Building*>` | `obj:findAllBuildingsOfType(func)` |
| _NV_findAllBuildingsOfType | TownBase__NV_findAllBuildingsOfType | `func: integer` | `lektor<Building*>` | `obj:_NV_findAllBuildingsOfType(func)` |
| findAllBuildingsWithFunction | TownBase_findAllBuildingsWithFunction | `func: integer` | `lektor<Building*>` | `obj:findAllBuildingsWithFunction(func)` |
| _NV_findAllBuildingsWithFunction | TownBase__NV_findAllBuildingsWithFunction | `func: integer` | `lektor<Building*>` | `obj:_NV_findAllBuildingsWithFunction(func)` |
| getCurrentTownLocation | TownBase_getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | TownBase__NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| getUnexploredName | TownBase_getUnexploredName | `` | `string` | `obj:getUnexploredName()` |
| _NV_getUnexploredName | TownBase__NV_getUnexploredName | `` | `string` | `obj:_NV_getUnexploredName()` |

## TownBuildingsManager
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| buildingEntities | buildingEntities | ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type | R | `obj.buildingEntities` |
| instancesManagers | instancesManagers | boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > > | R | `obj.instancesManagers` |
| signs | signs | Ogre::FastArray<std::pair<Building*, Ogre::Entity*> > | R | `obj.signs` |
| signsVisible | signsVisible | boolean | RW | `obj.signsVisible = <value>` |
| town | town | TownBase* | R | `obj.town` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| setAllVisible | setAllVisible | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setAllVisible(floor, onlyPlayerBuildings)` |
| resetAllVisible | resetAllVisible | `` | `void` | `obj:resetAllVisible()` |
| setSignsVisible | setSignsVisible | `value: boolean` | `void` | `obj:setSignsVisible(value)` |

## TownPositionCacher
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lastUpdateStamp | lastUpdateStamp | TimeOfDay | R | `obj.lastUpdateStamp` |
| updateRateInHours | updateRateInHours | number | RW | `obj.updateRateInHours = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| stampUpdate | stampUpdate | `` | `void` | `obj:stampUpdate()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |

## TradeCulture
**Header:** `extern/KenshiLib/Include/kenshi/TradeCulture.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | reset | `` | `void` | `obj:reset()` |
| getAllIllegalItems | getAllIllegalItems | `` | `lightuserdata` | `obj:getAllIllegalItems()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TradeCulture` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TradeResult
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| value | (lua_Integer | integer | RW | `obj.value = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `value: integer` | `lightuserdata` | `obj:_CONSTRUCTOR(value)` |
| showMessage | showMessage | `` | `void` | `obj:showMessage()` |

## TransformWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/TransformWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| window | window | DatapanelGUI | R | `obj.window` |
| windowXValue | windowXValue | DataPanelLine_TextEditable | R | `obj.windowXValue` |
| windowYValue | windowYValue | DataPanelLine_TextEditable | R | `obj.windowYValue` |
| windowZValue | windowZValue | DataPanelLine_TextEditable | R | `obj.windowZValue` |
| modeButton | modeButton | DataPanelLine_Button | R | `obj.modeButton` |
| axisButton | axisButton | DataPanelLine_Button | R | `obj.axisButton` |
| revertButton | revertButton | DataPanelLine_Button | R | `obj.revertButton` |
| node | (void* | lightuserdata | R | `obj.node` |
| parentNode | (void* | lightuserdata | R | `obj.parentNode` |
| gizmo | (void* | lightuserdata | R | `obj.gizmo` |
| mode | mode | integer | RW | `obj.mode = <value>` |
| coordinateSystem | coordinateSystem | integer | RW | `obj.coordinateSystem = <value>` |
| hasScale | hasScale | boolean | RW | `obj.hasScale = <value>` |
| lastZone | (void* | lightuserdata | R | `obj.lastZone` |
| currentZone | (void* | lightuserdata | R | `obj.currentZone` |
| currentInstance | (void* | lightuserdata | R | `obj.currentInstance` |
| changed | changed | boolean | RW | `obj.changed = <value>` |
| editChanged | editChanged | boolean | RW | `obj.editChanged = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCaption | setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| close | close | `` | `void` | `obj:close()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| updateGizmo | updateGizmo | `` | `boolean` | `obj:updateGizmo()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| hasChanged | hasChanged | `` | `boolean` | `obj:hasChanged()` |
| clearChangedFlag | clearChangedFlag | `` | `void` | `obj:clearChangedFlag()` |
| getMode | getMode | `` | `integer` | `obj:getMode()` |
| setMode | setMode | `m: integer` | `boolean` | `obj:setMode(m)` |
| getLastZone | getLastZone | `` | `lightuserdata` | `obj:getLastZone()` |
| getZone | getZone | `` | `lightuserdata` | `obj:getZone()` |

## TurretBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TurretBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| gunClass | (void* | lightuserdata | R | `obj.gunClass` |
| aimDistInDegrees | aimDistInDegrees | number | RW | `obj.aimDistInDegrees = <value>` |
| currentAimDir | currentAimDir | Vector3 | RW | `obj.currentAimDir = <value>` |
| rootAimDir | rootAimDir | Vector3 | RW | `obj.rootAimDir = <value>` |
| currentAimSpeed | currentAimSpeed | number | RW | `obj.currentAimSpeed = <value>` |
| currentAimTarget | currentAimTarget | Vector3 | RW | `obj.currentAimTarget = <value>` |
| mountedBuilding | mountedBuilding | hand | R | `obj.mountedBuilding` |
| hingePart | (void* | lightuserdata | R | `obj.hingePart` |
| gunPart | (void* | lightuserdata | R | `obj.gunPart` |
| aimTargetPos | aimTargetPos | Vector3 | RW | `obj.aimTargetPos = <value>` |
| rotating | rotating | integer | RW | `obj.rotating = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| setup | setup | `` | `void` | `obj:setup()` |
| _NV_setup | _NV_setup | `` | `void` | `obj:_NV_setup()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| getStatUsed | getStatUsed | `` | `integer` | `obj:getStatUsed()` |
| getProductionMultForGUI | getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| _NV_getProductionMultForGUI | _NV_getProductionMultForGUI | `` | `number` | `obj:_NV_getProductionMultForGUI()` |
| aimAt | aimAt | `who: Vector3` | `void` | `obj:aimAt(who)` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| amInsideTownWalls | amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| notifyConstructionComplete | notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| onBuildingLoaded | onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| _NV_onBuildingLoaded | _NV_onBuildingLoaded | `` | `void` | `obj:_NV_onBuildingLoaded()` |
| calculatePowerMult | calculatePowerMult | `` | `number` | `obj:calculatePowerMult()` |
| _teleport | _teleport | `p: Vector3` | `void` | `obj:_teleport(p)` |
| clearTownBuildingsManagerPtr | clearTownBuildingsManagerPtr | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| _NV_clearTownBuildingsManagerPtr | _NV_clearTownBuildingsManagerPtr | `` | `void` | `obj:_NV_clearTownBuildingsManagerPtr()` |

## TutorialGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| highlightItem | (lua_Integer | integer | RW | `obj.highlightItem = <value>` |
| highlightItemWidget | (void* | lightuserdata | R | `obj.highlightItemWidget` |
| highlightPanel | (void* | lightuserdata | R | `obj.highlightPanel` |
| highlightDirection | highlightDirection | integer | RW | `obj.highlightDirection = <value>` |
| highlightAlpha | highlightAlpha | number | RW | `obj.highlightAlpha = <value>` |
| window | (void* | lightuserdata | R | `obj.window` |
| windowPrevButton | (void* | lightuserdata | R | `obj.windowPrevButton` |
| windowNextButton | (void* | lightuserdata | R | `obj.windowNextButton` |
| windowText | (void* | lightuserdata | R | `obj.windowText` |
| dismissButton | (void* | lightuserdata | R | `obj.dismissButton` |
| pagingText | (void* | lightuserdata | R | `obj.pagingText` |
| tooltipsPanel | (void* | lightuserdata | R | `obj.tooltipsPanel` |
| currentTutorialItem | (void* | lightuserdata | R | `obj.currentTutorialItem` |
| flashNewItem | flashNewItem | boolean | RW | `obj.flashNewItem = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| _NV_clear | _NV_clear | `` | `void` | `obj:_NV_clear()` |
| startHighlight | startHighlight | `item: integer` | `void` | `obj:startHighlight(item)` |
| endHighlight | endHighlight | `` | `void` | `obj:endHighlight()` |
| _setHightlightCoords | _setHightlightCoords | `` | `void` | `obj:_setHightlightCoords()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| setEnabled | setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| show | show | `value: boolean` | `void` | `obj:show(value)` |
| _NV_show | _NV_show | `value: boolean` | `void` | `obj:_NV_show(value)` |
| arrangeList | arrangeList | `` | `void` | `obj:arrangeList()` |
| refreshUI | refreshUI | `` | `void` | `obj:refreshUI()` |
| closeTutorialWindow | closeTutorialWindow | `` | `void` | `obj:closeTutorialWindow()` |
| updateCurrentItem | updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |

## TutorialGUILine
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nameButton | (void* | lightuserdata | R | `obj.nameButton` |
| closeButton | (void* | lightuserdata | R | `obj.closeButton` |
| flashWidget | (void* | lightuserdata | R | `obj.flashWidget` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateHighlight | updateHighlight | `time: number` | `boolean` | `obj:updateHighlight(time)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TutorialItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| id | id | integer | RW | `obj.id = <value>` |
| started | started | boolean | RW | `obj.started = <value>` |
| locked | locked | boolean | RW | `obj.locked = <value>` |
| title | title | string | RW | `obj.title = <value>` |
| state | (lua_Integer | integer | RW | `obj.state = <value>` |
| subItemIndex | subItemIndex | integer | RW | `obj.subItemIndex = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getId | getId | `` | `integer` | `obj:getId()` |
| isLastSubItem | isLastSubItem | `` | `boolean` | `obj:isLastSubItem()` |
| isSkippable | isSkippable | `` | `boolean` | `obj:isSkippable()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| hasEnded | hasEnded | `` | `boolean` | `obj:hasEnded()` |
| getCurrentSubItem | getCurrentSubItem | `` | `lightuserdata` | `obj:getCurrentSubItem()` |
| getSubItemAt | getSubItemAt | `index: integer` | `lightuserdata` | `obj:getSubItemAt(index)` |
| getCurrentSubItemIndex | getCurrentSubItemIndex | `` | `integer` | `obj:getCurrentSubItemIndex()` |
| getNumSubItems | getNumSubItems | `` | `integer` | `obj:getNumSubItems()` |
| hasNextSubItem | hasNextSubItem | `` | `boolean` | `obj:hasNextSubItem()` |
| hasPrevSubItem | hasPrevSubItem | `` | `boolean` | `obj:hasPrevSubItem()` |
| nextSubItem | nextSubItem | `` | `void` | `obj:nextSubItem()` |
| prevSubItem | prevSubItem | `` | `void` | `obj:prevSubItem()` |
| getStarted | getStarted | `` | `boolean` | `obj:getStarted()` |
| getEnded | getEnded | `` | `boolean` | `obj:getEnded()` |
| reset | reset | `` | `void` | `obj:reset()` |
| _NV_reset | _NV_reset | `` | `void` | `obj:_NV_reset()` |
| conditionsMet | conditionsMet | `` | `boolean` | `obj:conditionsMet()` |
| start | start | `` | `void` | `obj:start()` |
| _NV_start | _NV_start | `` | `void` | `obj:_NV_start()` |
| run | run | `` | `boolean` | `obj:run()` |
| _NV_run | _NV_run | `` | `boolean` | `obj:_NV_run()` |
| end | end | `` | `void` | `obj:end()` |
| _NV_end | _NV_end | `` | `void` | `obj:_NV_end()` |

## TutorialSubItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| description | description | string | RW | `obj.description = <value>` |
| skippeable | skippeable | boolean | RW | `obj.skippeable = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| start | start | `` | `void` | `obj:start()` |
| _NV_start | _NV_start | `` | `void` | `obj:_NV_start()` |
| run | run | `` | `boolean` | `obj:run()` |
| _NV_run | _NV_run | `` | `boolean` | `obj:_NV_run()` |
| end | end | `` | `void` | `obj:end()` |
| _NV_end | _NV_end | `` | `void` | `obj:_NV_end()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TutorialpediaGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentItem | (void* | lightuserdata | RW | `obj.currentItem = <value>` |
| currentItemIndex | currentItemIndex | integer | RW | `obj.currentItemIndex = <value>` |
| tutorialsList | (void* | lightuserdata | R | `obj.tutorialsList` |
| descriptionText | (void* | lightuserdata | R | `obj.descriptionText` |
| activateButton | (void* | lightuserdata | R | `obj.activateButton` |
| prevButton | (void* | lightuserdata | R | `obj.prevButton` |
| nextButton | (void* | lightuserdata | R | `obj.nextButton` |
| pagingText | (void* | lightuserdata | R | `obj.pagingText` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| show | show | `value: boolean` | `void` | `obj:show(value)` |
| _NV_show | _NV_show | `value: boolean` | `void` | `obj:_NV_show(value)` |
| clear | clear | `` | `void` | `obj:clear()` |
| _NV_clear | _NV_clear | `` | `void` | `obj:_NV_clear()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setup | setup | `` | `void` | `obj:setup()` |
| updateCurrentItem | updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |

## UniqueSpawnData
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| squadTemplate | squadTemplate | GameData | R | `obj.squadTemplate` |
| desiredNumberToHave | desiredNumberToHave | integer | RW | `obj.desiredNumberToHave = <value>` |
| respawnTimer | respawnTimer | number | RW | `obj.respawnTimer = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| currentNumber | currentNumber | `` | `integer` | `obj:currentNumber()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## UseableStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| shopOwner | shopOwner | hand | RW | `obj.shopOwner = <value>` |
| callbackOwner | callbackOwner | hand | RW | `obj.callbackOwner = <value>` |
| hasProgressBarWhenUsed | hasProgressBarWhenUsed | boolean | RW | `obj.hasProgressBarWhenUsed = <value>` |
| progressBarLevel | progressBarLevel | number | RW | `obj.progressBarLevel = <value>` |
| occupantSelection | occupantSelection | boolean | RW | `obj.occupantSelection = <value>` |
| needsOperating | needsOperating | boolean | RW | `obj.needsOperating = <value>` |
| numOperatorsMax | numOperatorsMax | integer | RW | `obj.numOperatorsMax = <value>` |
| hungerRate | hungerRate | number | RW | `obj.hungerRate = <value>` |
| _recievesBatteryPower | _recievesBatteryPower | boolean | RW | `obj._recievesBatteryPower = <value>` |
| powerOn | powerOn | boolean | RW | `obj.powerOn = <value>` |
| _isBroken | _isBroken | boolean | RW | `obj._isBroken = <value>` |
| batteryOutputStat | batteryOutputStat | number | RW | `obj.batteryOutputStat = <value>` |
| _powerOutputMax | _powerOutputMax | number | RW | `obj._powerOutputMax = <value>` |
| currentPower | currentPower | number | RW | `obj.currentPower = <value>` |
| powerTimeStored | powerTimeStored | number | RW | `obj.powerTimeStored = <value>` |
| _powerTimeStoreMax | _powerTimeStoreMax | number | RW | `obj._powerTimeStoreMax = <value>` |
| currentOperators | currentOperators | std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > | R | `obj.currentOperators` |
| usesStat | (lua_Integer | integer | RW | `obj.usesStat = <value>` |
| functionalityData | functionalityData | GameData | R | `obj.functionalityData` |
| animation | animation | GameData | R | `obj.animation` |
| animationKO | animationKO | GameData | R | `obj.animationKO` |
| animationDazed | animationDazed | GameData | R | `obj.animationDazed` |
| maxUseRange | maxUseRange | number | RW | `obj.maxUseRange = <value>` |
| sfxTime | sfxTime | number | RW | `obj.sfxTime = <value>` |
| inventory | inventory | Inventory | R | `obj.inventory` |
| doorLock | (void* | lightuserdata | R | `obj.doorLock` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getUseableStuff | getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| createInventoryLayout | createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| takeMoney | takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| isAnyInputsEmpty | isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| needsUpdate | needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| threadedUpdate | threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| calculateEfficiencyMult | calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| _NV_calculateEfficiencyMult | _NV_calculateEfficiencyMult | `` | `number` | `obj:_NV_calculateEfficiencyMult()` |
| isOutOfPower | isOutOfPower | `` | `number` | `obj:isOutOfPower()` |
| _NV_isOutOfPower | _NV_isOutOfPower | `` | `number` | `obj:_NV_isOutOfPower()` |
| isBroken | isBroken | `` | `boolean` | `obj:isBroken()` |
| _NV_isBroken | _NV_isBroken | `` | `boolean` | `obj:_NV_isBroken()` |
| setBroken | setBroken | `on: boolean` | `void` | `obj:setBroken(on)` |
| _NV_setBroken | _NV_setBroken | `on: boolean` | `void` | `obj:_NV_setBroken(on)` |
| isDisabled | isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| getMouseCursor | getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getReachRange | getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| dontNeedWorkRightNow | dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| _NV_dontNeedWorkRightNow | _NV_dontNeedWorkRightNow | `` | `boolean` | `obj:_NV_dontNeedWorkRightNow()` |
| isForSale | isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| takePowerFrom | takePowerFrom | `amount: number, frameTime: number` | `number` | `obj:takePowerFrom(amount, frameTime)` |
| howMuchPowerDoYouWantMax | howMuchPowerDoYouWantMax | `` | `number` | `obj:howMuchPowerDoYouWantMax()` |
| howMuchPowerDoYouWantForSortingFunction | howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| _NV_howMuchPowerDoYouWantForSortingFunction | _NV_howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:_NV_howMuchPowerDoYouWantForSortingFunction()` |
| howMuchPowerDoYouWantNow | howMuchPowerDoYouWantNow | `` | `number` | `obj:howMuchPowerDoYouWantNow()` |
| needPowerRightNow | needPowerRightNow | `` | `boolean` | `obj:needPowerRightNow()` |
| _NV_needPowerRightNow | _NV_needPowerRightNow | `` | `boolean` | `obj:_NV_needPowerRightNow()` |
| givePower | givePower | `amount: number` | `void` | `obj:givePower(amount)` |
| _NV_givePower | _NV_givePower | `amount: number` | `void` | `obj:_NV_givePower(amount)` |
| resetPower | resetPower | `` | `void` | `obj:resetPower()` |
| getMaxPower | getMaxPower | `` | `number` | `obj:getMaxPower()` |
| getPowerOutput | getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| _NV_getPowerOutput | _NV_getPowerOutput | `` | `number` | `obj:_NV_getPowerOutput()` |
| getFuelConsumptionRate | getFuelConsumptionRate | `` | `number` | `obj:getFuelConsumptionRate()` |
| _NV_getFuelConsumptionRate | _NV_getFuelConsumptionRate | `` | `number` | `obj:_NV_getFuelConsumptionRate()` |
| isBattery | isBattery | `` | `boolean` | `obj:isBattery()` |
| isGenerator | isGenerator | `` | `boolean` | `obj:isGenerator()` |
| getBatteryCharge | getBatteryCharge | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryChargeMax | getBatteryChargeMax | `` | `number` | `obj:getBatteryChargeMax()` |
| setupFromData | setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| switchPowerOn | switchPowerOn | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| _NV_switchPowerOn | _NV_switchPowerOn | `on: boolean` | `void` | `obj:_NV_switchPowerOn(on)` |
| hasPower | hasPower | `` | `boolean` | `obj:hasPower()` |
| isPowerOn | isPowerOn | `` | `boolean` | `obj:isPowerOn()` |
| _NV_isPowerOn | _NV_isPowerOn | `` | `boolean` | `obj:_NV_isPowerOn()` |
| isRecievesBatteryPower | isRecievesBatteryPower | `` | `boolean` | `obj:isRecievesBatteryPower()` |
| getStatUsed | getStatUsed | `` | `integer` | `obj:getStatUsed()` |
| getDoorLock | getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| _NV_getDoorLock | _NV_getDoorLock | `` | `lightuserdata` | `obj:_NV_getDoorLock()` |
| hasDoorLock | hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| _NV_hasDoorLock | _NV_hasDoorLock | `` | `boolean` | `obj:_NV_hasDoorLock()` |
| getFunctionalityData | getFunctionalityData | `` | `GameData` | `obj:getFunctionalityData()` |
| setup | setup | `` | `void` | `obj:setup()` |
| _NV_setup | _NV_setup | `` | `void` | `obj:_NV_setup()` |
| getOutputBasedRotationSpeedMult | getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| _NV_getOutputBasedRotationSpeedMult | _NV_getOutputBasedRotationSpeedMult | `` | `number` | `obj:_NV_getOutputBasedRotationSpeedMult()` |
| getGUIPowerEfficiencyToolTipString | getGUIPowerEfficiencyToolTipString | `` | `string` | `obj:getGUIPowerEfficiencyToolTipString()` |
| _NV_getGUIPowerEfficiencyToolTipString | _NV_getGUIPowerEfficiencyToolTipString | `` | `string` | `obj:_NV_getGUIPowerEfficiencyToolTipString()` |

## VisibleObjectInfo
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| handle | handle | hand | R | `obj.handle` |
| range | range | number | RW | `obj.range = <value>` |
| isEnemy | isEnemy | boolean | RW | `obj.isEnemy = <value>` |

## WallBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/WallBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| wallSectionLinkType | wallSectionLinkType | WallSectionLinkType | R | `obj.wallSectionLinkType` |
| shareBuildStateOfAnother | shareBuildStateOfAnother | hand | R | `obj.shareBuildStateOfAnother` |
| othersSharingMyBuildState | othersSharingMyBuildState | lektor<hand> | R | `obj.othersSharingMyBuildState` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getUseableStuff | getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| getReachRange | getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| isForSale | isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| isDamaged | isDamaged | `` | `boolean` | `obj:isDamaged()` |
| _NV_isDamaged | _NV_isDamaged | `` | `boolean` | `obj:_NV_isDamaged()` |
| getPositionForWaypoint_outside | getPositionForWaypoint_outside | `` | `Vector3` | `obj:getPositionForWaypoint_outside()` |
| getOutsideGateCode | getOutsideGateCode | `` | `integer` | `obj:getOutsideGateCode()` |
| isAWall | isAWall | `` | `WallBuilding` | `obj:isAWall()` |
| _NV_isAWall | _NV_isAWall | `` | `WallBuilding` | `obj:_NV_isAWall()` |
| canUpgrade | canUpgrade | `` | `GameData` | `obj:canUpgrade()` |
| _NV_canUpgrade | _NV_canUpgrade | `` | `GameData` | `obj:_NV_canUpgrade()` |
| addConstructionProgress | addConstructionProgress | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| _NV_addConstructionProgress | _NV_addConstructionProgress | `amount: number` | `void` | `obj:_NV_addConstructionProgress(amount)` |
| setConstructionProgress | setConstructionProgress | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| _NV_setConstructionProgress | _NV_setConstructionProgress | `amount: number` | `void` | `obj:_NV_setConstructionProgress(amount)` |
| notifyConstructionComplete | notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| addDismantleProgress | addDismantleProgress | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| _NV_addDismantleProgress | _NV_addDismantleProgress | `amount: number` | `boolean` | `obj:_NV_addDismantleProgress(amount)` |
| notifyConstructionDismantling | notifyConstructionDismantling | `` | `void` | `obj:notifyConstructionDismantling()` |
| _NV_notifyConstructionDismantling | _NV_notifyConstructionDismantling | `` | `void` | `obj:_NV_notifyConstructionDismantling()` |
| getBuildState | getBuildState | `` | `lightuserdata` | `obj:getBuildState()` |
| _NV_getBuildState | _NV_getBuildState | `` | `lightuserdata` | `obj:_NV_getBuildState()` |
| isALittleWallPartLikeACornerOrSomething | isALittleWallPartLikeACornerOrSomething | `` | `boolean` | `obj:isALittleWallPartLikeACornerOrSomething()` |
| isAShortWallPart | isAShortWallPart | `` | `boolean` | `obj:isAShortWallPart()` |

## Weapon
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| bleedDamage | bleedDamage | number | RW | `obj.bleedDamage = <value>` |
| modAttack | modAttack | integer | RW | `obj.modAttack = <value>` |
| combatWeight | combatWeight | number | RW | `obj.combatWeight = <value>` |
| category | (lua_Integer | integer | RW | `obj.category = <value>` |
| category_animationOverride | (lua_Integer | integer | RW | `obj.category_animationOverride = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getItemWeight | getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _NV_getItemWeight | _NV_getItemWeight | `` | `number` | `obj:_NV_getItemWeight()` |
| getValueSingle | getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| getCategory | getCategory | `` | `integer` | `obj:getCategory()` |
| getCategory_animationOverride | getCategory_animationOverride | `` | `integer` | `obj:getCategory_animationOverride()` |
| is2HandedOnly | is2HandedOnly | `` | `boolean` | `obj:is2HandedOnly()` |
| getCombatWeight | getCombatWeight | `` | `number` | `obj:getCombatWeight()` |
| getCraftTime | getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getCraftMaterialMult | getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| _NV_getCraftMaterialMult | _NV_getCraftMaterialMult | `` | `number` | `obj:_NV_getCraftMaterialMult()` |
| isWeapon | isWeapon | `` | `Weapon` | `obj:isWeapon()` |
| _NV_isWeapon | _NV_isWeapon | `` | `Weapon` | `obj:_NV_isWeapon()` |
| isSword | isSword | `` | `Sword` | `obj:isSword()` |
| _NV_isSword | _NV_isSword | `` | `Sword` | `obj:_NV_isSword()` |
| isCrossbow | isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| _NV_isCrossbow | _NV_isCrossbow | `` | `Crossbow` | `obj:_NV_isCrossbow()` |
| getSkillModIndoors | getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| _NV_getSkillModIndoors | _NV_getSkillModIndoors | `` | `integer` | `obj:_NV_getSkillModIndoors()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## WhoSeesMe
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lastUpdated | lastUpdated | number | RW | `obj.lastUpdated = <value>` |
| seeState | seeState | YesNoMaybe | RW | `obj.seeState = <value>` |
| progressOfMaybe | progressOfMaybe | number | RW | `obj.progressOfMaybe = <value>` |

## WindGeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getPowerOutput | getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| _NV_getPowerOutput | _NV_getPowerOutput | `` | `number` | `obj:_NV_getPowerOutput()` |
| getSoundIntensity | getSoundIntensity | `` | `number` | `obj:getSoundIntensity()` |
| _NV_getSoundIntensity | _NV_getSoundIntensity | `` | `number` | `obj:_NV_getSoundIntensity()` |
| isAnyInputsEmpty | isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isTrue | isTrue | `` | `boolean` | `obj:isTrue()` |

## WorldEventStateQueryList
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| statesList | statesList | ogre_unordered_map<WorldEventStateQuery*, bool>::type | R | `obj.statesList` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | reset | `` | `void` | `obj:reset()` |
| isTrue | isTrue | `` | `boolean` | `obj:isTrue()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## YesNoMaybe
**Header:** `extern/KenshiLib/Include/kenshi/util/YesNoMaybe.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| key | (lua_Integer | integer | RW | `obj.key = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| toInt | toInt | `` | `integer` | `obj:toInt()` |

## ZoneManager
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| justLoadedAGame | justLoadedAGame | boolean | RW | `obj.justLoadedAGame = <value>` |
| _needCalculateIslands | _needCalculateIslands | boolean | RW | `obj._needCalculateIslands = <value>` |
| spawnUpdateTimerMT | spawnUpdateTimerMT | number | RW | `obj.spawnUpdateTimerMT = <value>` |
| spawnUpdateTimerTT | spawnUpdateTimerTT | number | RW | `obj.spawnUpdateTimerTT = <value>` |
| centralZone | (void* | lightuserdata | R | `obj.centralZone` |
| loadingPhase | loadingPhase | integer | RW | `obj.loadingPhase = <value>` |
| biomeMap | (void* | lightuserdata | R | `obj.biomeMap` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isZoneLoadedT | isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneLoadedT(pos)` |
| _NV_isZoneLoadedT | _NV_isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:_NV_isZoneLoadedT(pos)` |
| isZoneBeingLoadedT | isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(pos)` |
| _NV_isZoneBeingLoadedT | _NV_isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:_NV_isZoneBeingLoadedT(pos)` |
| getNumActiveZones | getNumActiveZones | `` | `integer` | `obj:getNumActiveZones()` |
| setup | setup | `` | `void` | `obj:setup()` |
| updateMainThread | updateMainThread | `camerapos: Vector3` | `void` | `obj:updateMainThread(camerapos)` |
| updateRendertimeThread | updateRendertimeThread | `camerapos: Vector3` | `void` | `obj:updateRendertimeThread(camerapos)` |
| updateGPUSafeThread | updateGPUSafeThread | `camerapos: Vector3` | `void` | `obj:updateGPUSafeThread(camerapos)` |
| spawnChecksUpdateThreaded | spawnChecksUpdateThreaded | `island: integer` | `void` | `obj:spawnChecksUpdateThreaded(island)` |
| levelEditorDeleteAllSelectedObjects | levelEditorDeleteAllSelectedObjects | `` | `void` | `obj:levelEditorDeleteAllSelectedObjects()` |
| getCurrentZoneMap | getCurrentZoneMap | `` | `lightuserdata` | `obj:getCurrentZoneMap()` |
| playerActivate | playerActivate | `pos: Vector3` | `boolean` | `obj:playerActivate(pos)` |
| getBiome | getBiome | `position: Vector3` | `GameData` | `obj:getBiome(position)` |
| getBiomeCode | getBiomeCode | `position: Vector3` | `integer` | `obj:getBiomeCode(position)` |
| getBiomeMap | getBiomeMap | `` | `lightuserdata` | `obj:getBiomeMap()` |
| getGroundTypeIndex | getGroundTypeIndex | `pos: Vector3` | `integer` | `obj:getGroundTypeIndex(pos)` |
| getGroundType | getGroundType | `pos: Vector3` | `integer` | `obj:getGroundType(pos)` |
| shiftGroundEffects | shiftGroundEffects | `shift: Vector3` | `void` | `obj:shiftGroundEffects(shift)` |
| checkZoneFiles | checkZoneFiles | `` | `boolean` | `obj:checkZoneFiles()` |
| resetStates | resetStates | `` | `void` | `obj:resetStates()` |
| getResourceId | getResourceId | `resource: integer` | `string` | `obj:getResourceId(resource)` |
| getResourceName | getResourceName | `resource: integer` | `string` | `obj:getResourceName(resource)` |
| saveMapFeatures | saveMapFeatures | `` | `boolean` | `obj:saveMapFeatures()` |
| saveLevelData | saveLevelData | `path: string, modName: string` | `void` | `obj:saveLevelData(path, modName)` |
| saveActiveZoneStates | saveActiveZoneStates | `` | `void` | `obj:saveActiveZoneStates()` |
| resetGame | resetGame | `` | `void` | `obj:resetGame()` |
| deactivateAllActiveZones | deactivateAllActiveZones | `` | `void` | `obj:deactivateAllActiveZones()` |
| activateAllActiveZones | activateAllActiveZones | `` | `void` | `obj:activateAllActiveZones()` |
| populateTownsForLevelEditor | populateTownsForLevelEditor | `` | `void` | `obj:populateTownsForLevelEditor()` |
| calculateIslands | calculateIslands | `` | `void` | `obj:calculateIslands()` |
| _reloadAllFoliage | _reloadAllFoliage | `` | `void` | `obj:_reloadAllFoliage()` |
| _reloadGroundTextures | _reloadGroundTextures | `` | `void` | `obj:_reloadGroundTextures()` |
| _unloadAllZones | _unloadAllZones | `` | `void` | `obj:_unloadAllZones()` |
| getCentralZone | getCentralZone | `` | `lightuserdata` | `obj:getCentralZone()` |
| isLoading | isLoading | `` | `integer` | `obj:isLoading()` |
| _calculateIslands | _calculateIslands | `` | `void` | `obj:_calculateIslands()` |
| loadFeatures | loadFeatures | `` | `void` | `obj:loadFeatures()` |
| loadDistantTowns | loadDistantTowns | `` | `void` | `obj:loadDistantTowns()` |
| processLoading | processLoading | `` | `boolean` | `obj:processLoading()` |
| loadPhase1 | loadPhase1 | `` | `void` | `obj:loadPhase1()` |
| loadPhase2 | loadPhase2 | `` | `void` | `obj:loadPhase2()` |
| loadPhase3 | loadPhase3 | `` | `void` | `obj:loadPhase3()` |

## ZoneManagerInterfaceT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isZoneLoadedT | isZoneLoadedT | `_a1: Vector3` | `boolean` | `obj:isZoneLoadedT(_a1)` |
| isZoneBeingLoadedT | isZoneBeingLoadedT | `_a1: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(_a1)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## ZoneMap
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mapContent | (void* | lightuserdata | R | `obj.mapContent` |
| mapFeatures | (void* | lightuserdata | R | `obj.mapFeatures` |
| zoneSmell | (void* | lightuserdata | R | `obj.zoneSmell` |
| island | island | integer | RW | `obj.island = <value>` |
| hasFile | hasFile | boolean | RW | `obj.hasFile = <value>` |
| terrainCollision | (void* | lightuserdata | R | `obj.terrainCollision` |
| activatedCountdown | activatedCountdown | number | RW | `obj.activatedCountdown = <value>` |
| _generateNavMeshesFlag | _generateNavMeshesFlag | boolean | RW | `obj._generateNavMeshesFlag = <value>` |
| center | center | Vector3 | RW | `obj.center = <value>` |
| loadCount | loadCount | integer | RW | `obj.loadCount = <value>` |
| neighbors | (void* | lightuserdata | R | `obj.neighbors` |
| neighborsDiagonal | (void* | lightuserdata | R | `obj.neighborsDiagonal` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| initialise | initialise | `` | `void` | `obj:initialise()` |
| threadedUpdate | threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| update | update | `` | `boolean` | `obj:update()` |
| selectBiomes | selectBiomes | `` | `integer` | `obj:selectBiomes()` |
| getBiomeCount | getBiomeCount | `` | `integer` | `obj:getBiomeCount()` |
| getBiomeData | getBiomeData | `i: integer` | `GameData` | `obj:getBiomeData(i)` |
| getOverlay | getOverlay | `` | `lightuserdata` | `obj:getOverlay()` |
| getAreaSector | getAreaSector | `` | `lightuserdata` | `obj:getAreaSector()` |
| getTerrainHeight | getTerrainHeight | `_x: number, _y: number` | `number` | `obj:getTerrainHeight(_x, _y)` |
| getTerrainHeightWithNormal | getTerrainHeightWithNormal | `_x: number, _y: number, normal: Vector3` | `number` | `obj:getTerrainHeightWithNormal(_x, _y, normal)` |
| getTerrainSlope | getTerrainSlope | `_x: number, _y: number` | `number` | `obj:getTerrainSlope(_x, _y)` |
| isWithinBoundsMinusUnloadedEdges | isWithinBoundsMinusUnloadedEdges | `borderThickness: number, v: Vector3` | `boolean` | `obj:isWithinBoundsMinusUnloadedEdges(borderThickness, v)` |
| getCornerPos | getCornerPos | `` | `Vector3` | `obj:getCornerPos()` |
| getTerrainSector | getTerrainSector | `force: boolean` | `lightuserdata` | `obj:getTerrainSector(force)` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| getDeactivationCountdown | getDeactivationCountdown | `` | `number` | `obj:getDeactivationCountdown()` |
| isLoadedBT | isLoadedBT | `` | `boolean` | `obj:isLoadedBT()` |
| isBeingLoadedBT | isBeingLoadedBT | `` | `boolean` | `obj:isBeingLoadedBT()` |
| isLoadedMT | isLoadedMT | `` | `boolean` | `obj:isLoadedMT()` |
| isBeingLoadedMT | isBeingLoadedMT | `` | `boolean` | `obj:isBeingLoadedMT()` |
| isTerrainCollisionLoaded | isTerrainCollisionLoaded | `` | `boolean` | `obj:isTerrainCollisionLoaded()` |
| _makeSureTerrainHeightmapLoaded | _makeSureTerrainHeightmapLoaded | `` | `void` | `obj:_makeSureTerrainHeightmapLoaded()` |
| _dactivateMT | _dactivateMT | `saveZoneState: boolean` | `void` | `obj:_dactivateMT(saveZoneState)` |
| generateNavMeshes | generateNavMeshes | `` | `boolean` | `obj:generateNavMeshes()` |
| updateBuildingUsageNodes | updateBuildingUsageNodes | `` | `void` | `obj:updateBuildingUsageNodes()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ZoneSpacialGrid
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| zones | (void* | lightuserdata | R | `obj.zones` |
| createCellsFunc | (void* | lightuserdata | R | `obj.createCellsFunc` |
| cellCount | cellCount | integer | RW | `obj.cellCount = <value>` |
| cellSize | cellSize | number | RW | `obj.cellSize = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getZoneKey | getZoneKey | `p: Vector3` | `integer` | `obj:getZoneKey(p)` |
| getFullKey | getFullKey | `p: Vector3` | `integer` | `obj:getFullKey(p)` |
| initialiseGrid | initialiseGrid | `size: number` | `void` | `obj:initialiseGrid(size)` |

## hand
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| type | (lua_Integer | integer | RW | `obj.type = <value>` |
| container | container | integer | RW | `obj.container = <value>` |
| containerSerial | containerSerial | integer | RW | `obj.containerSerial = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| serial | serial | integer | RW | `obj.serial = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| toString | toString | `` | `string` | `obj:toString()` |
| fromString | fromString | `str: string` | `void` | `obj:fromString(str)` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| getPlatoon | getPlatoon | `` | `Platoon` | `obj:getPlatoon()` |
| getActivePlatoon | getActivePlatoon | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getBuilding | getBuilding | `` | `Building` | `obj:getBuilding()` |
| getItem | getItem | `` | `Item` | `obj:getItem()` |
| getRootObject | getRootObject | `` | `RootObject` | `obj:getRootObject()` |
| getRootObjectBase | getRootObjectBase | `` | `RootObjectBase` | `obj:getRootObjectBase()` |
| getTown | getTown | `` | `TownBase` | `obj:getTown()` |
| debugWhatHappenedToMe | debugWhatHappenedToMe | `` | `string` | `obj:debugWhatHappenedToMe()` |
| setNull | setNull | `` | `void` | `obj:setNull()` |
| isNull | isNull | `` | `boolean` | `obj:isNull()` |
| isValid | isValid | `` | `boolean` | `obj:isValid()` |
| canCastToRootObject | canCastToRootObject | `` | `boolean` | `obj:canCastToRootObject()` |

## iVector2
**Header:** `extern/KenshiLib/Include/kenshi/util/iVector2.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| x | x | integer | RW | `obj.x = <value>` |
| y | y | integer | RW | `obj.y = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getLinearValue | getLinearValue | `` | `integer` | `obj:getLinearValue()` |
| getAsString | getAsString | `` | `string` | `obj:getAsString()` |

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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| traceWasAborted | traceWasAborted | `` | `boolean` | `obj:traceWasAborted()` |
| reset | reset | `` | `void` | `obj:reset()` |
| hitObjectUnsafePtr | hitObjectUnsafePtr | `` | `RootObject` | `obj:hitObjectUnsafePtr()` |
| getBuilding | getBuilding | `` | `Building` | `obj:getBuilding()` |
| group | group | `` | `integer` | `obj:group()` |
