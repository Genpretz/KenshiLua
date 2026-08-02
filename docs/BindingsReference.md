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
- [Array2d](#array2d)
- [AttachedArrowManager](#attachedarrowmanager)
- [AttackSlotManager](#attackslotmanager)
- [BackThreadMessagesToMainT](#backthreadmessagestomaint)
- [BackpackInventoryLayout](#backpackinventorylayout)
- [BadSize](#badsize)
- [BaseLayout](#baselayout)
- [BoundsViolation](#boundsviolation)
- [Bounty](#bounty)
- [BountyManager](#bountymanager)
- [Box](#box)
- [BuildInventoryLayout](#buildinventorylayout)
- [BuildMaterial](#buildmaterial)
- [BuildModeWindow](#buildmodewindow)
- [Building](#building)
- [BuildingCategory](#buildingcategory)
- [BuildingContainerInventoryLayout](#buildingcontainerinventorylayout)
- [BuildingGroup](#buildinggroup)
- [BuildingPlacementGroundType](#buildingplacementgroundtype)
- [BuildingSwaps](#buildingswaps)
- [CPerfTimer](#cperftimer)
- [CPerfTimerT](#cperftimert)
- [CameraClass](#cameraclass)
- [CampaignRequest](#campaignrequest)
- [CampaignTriggerData](#campaigntriggerdata)
- [CharBody](#charbody)
- [CharMovement](#charmovement)
- [CharStats](#charstats)
- [Character](#character)
- [CharacterAnimal](#characteranimal)
- [CharacterEditWindow](#charactereditwindow)
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
- [ContextMenuGUI](#contextmenugui)
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
- [EntData](#entdata)
- [Faction](#faction)
- [FactionLeader](#factionleader)
- [FactionListWindow](#factionlistwindow)
- [FactionManager](#factionmanager)
- [FactionRelations](#factionrelations)
- [FactionRelationsLine](#factionrelationsline)
- [FactionUniqueSquadManager](#factionuniquesquadmanager)
- [FactionWarMgr](#factionwarmgr)
- [FactionsScreen](#factionsscreen)
- [FactoryCallbackInterface](#factorycallbackinterface)
- [FarmBatch](#farmbatch)
- [FarmBuilding](#farmbuilding)
- [FlagCondition](#flagcondition)
- [FloatingProgressBar](#floatingprogressbar)
- [FlockingTools](#flockingtools)
- [FogEditor](#fogeditor)
- [FoliageSystem](#foliagesystem)
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
- [GamedataSelectionList](#gamedataselectionlist)
- [GameplayOptions](#gameplayoptions)
- [GatewayBuilding](#gatewaybuilding)
- [Gear](#gear)
- [GeneratorBuilding](#generatorbuilding)
- [GenericFixedInventoryLayout](#genericfixedinventorylayout)
- [GenericInventoryLayout](#genericinventorylayout)
- [Global](#global)
- [GlobalConstants](#globalconstants)
- [Hand](#hand)
- [HasRoomCache](#hasroomcache)
- [HavokCharacter](#havokcharacter)
- [HealthPartStatus](#healthpartstatus)
- [ImpactPoint](#impactpoint)
- [ImportGameMenu](#importgamemenu)
- [InputHandler](#inputhandler)
- [InstanceID](#instanceid)
- [InteriorModeButtonWindow](#interiormodebuttonwindow)
- [Inventory](#inventory)
- [InventoryGUI](#inventorygui)
- [InventoryIcon](#inventoryicon)
- [InventoryItemBase](#inventoryitembase)
- [InventoryLayout](#inventorylayout)
- [InventorySection](#inventorysection)
- [InventorySectionGUI](#inventorysectiongui)
- [InventoryTradeData](#inventorytradedata)
- [InventoryTraderGUI](#inventorytradergui)
- [Item](#item)
- [ItemData](#itemdata)
- [ItemListWindow](#itemlistwindow)
- [LevelEditor](#leveleditor)
- [LightBuilding](#lightbuilding)
- [LightEnt](#lightent)
- [LimbsInventoryLayout](#limbsinventorylayout)
- [Limiter](#limiter)
- [ListScrollBar](#listscrollbar)
- [Listener](#listener)
- [LoadSaveWindow](#loadsavewindow)
- [LoadingWindow](#loadingwindow)
- [LockedArmour](#lockedarmour)
- [Logger](#logger)
- [MainBarGUI](#mainbargui)
- [MainTabPortraitPlatoon](#maintabportraitplatoon)
- [MainthreadStateReaderT](#mainthreadstatereadert)
- [ManagementScreen](#managementscreen)
- [MapMarkerCharacter](#mapmarkercharacter)
- [MapMarkerTown](#mapmarkertown)
- [MapScreen](#mapscreen)
- [MedianFilter](#medianfilter)
- [MedianFilter2DVector](#medianfilter2dvector)
- [MedicalSystem](#medicalsystem)
- [MeshDataLookup](#meshdatalookup)
- [MeshLoadData](#meshloaddata)
- [MessageBoxManager](#messageboxmanager)
- [MessageChain](#messagechain)
- [MessageQueue](#messagequeue)
- [ModInfo](#modinfo)
- [MotionFilter](#motionfilter)
- [MultiSlider](#multislider)
- [MustEndWithSemiColon](#mustendwithsemicolon)
- [MyGUI](MyGUI_Bindings.md)
- [NavMesh](#navmesh)
- [NavMeshGenerator](#navmeshgenerator)
- [NavMeshSeeds](#navmeshseeds)
- [NewGameOptionsWindow](#newgameoptionswindow)
- [NewGameWindow](#newgamewindow)
- [NpcListWindow](#npclistwindow)
- [Nx9Real](#nx9real)
- [NxBox](#nxbox)
- [NxMat33](#nxmat33)
- [NxUserControllerHitReport](#nxusercontrollerhitreport)
- [NxUserTriggerReport](#nxusertriggerreport)
- [NxVec3](#nxvec3)
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
- [PhysicalEntity](#physicalentity)
- [PhysicsActual](#physicsactual)
- [PhysicsClass](#physicsclass)
- [PhysicsCollection](#physicscollection)
- [PhysicsInterface](#physicsinterface)
- [Platoon](#platoon)
- [PlayerInterface](#playerinterface)
- [PortraitData](#portraitdata)
- [PortraitImage](#portraitimage)
- [PortraitMainCellView](#portraitmaincellview)
- [PortraitManager](#portraitmanager)
- [PortraitSquadCellView](#portraitsquadcellview)
- [PortraitSquadItemBox](#portraitsquaditembox)
- [PreviewBuilding](#previewbuilding)
- [ProductionBuilding](#productionbuilding)
- [ProductionInventoryLayout](#productioninventorylayout)
- [ProgressBarWidget](#progressbarwidget)
- [ProspectingWindow](#prospectingwindow)
- [ProsperityManager](#prosperitymanager)
- [RaceData](#racedata)
- [RaceLimiter](#racelimiter)
- [RainCollectorBuilding](#raincollectorbuilding)
- [RelationData](#relationdata)
- [ReorderableList](#reorderablelist)
- [RepetitionCounter](#repetitioncounter)
- [ResearchBuilding](#researchbuilding)
- [ResearchBuildingInventoryLayout](#researchbuildinginventorylayout)
- [ResourceLinePanel](#resourcelinepanel)
- [ResourceLoadRequestMesh](#resourceloadrequestmesh)
- [ResourceLoadRequestTexture](#resourceloadrequesttexture)
- [ResourceLoader](#resourceloader)
- [RobotLimbItem](#robotlimbitem)
- [RobotLimbs](#robotlimbs)
- [RootObject](#rootobject)
- [RootObjectBase](#rootobjectbase)
- [RootObjectContainer](#rootobjectcontainer)
- [RootObjectFactory](#rootobjectfactory)
- [RotatingEnt](#rotatingent)
- [SaveFileSystem](#savefilesystem)
- [SaveManager](#savemanager)
- [ScreenLabel](#screenlabel)
- [ScreenLabelDebug](#screenlabeldebug)
- [ScreenLabelInterface](#screenlabelinterface)
- [SectionItem](#sectionitem)
- [SeenSomeone](#seensomeone)
- [SelectionBox](#selectionbox)
- [SenseItr](#senseitr)
- [SensoryData](#sensorydata)
- [ShopTrader](#shoptrader)
- [ShopTraderInventory](#shoptraderinventory)
- [ShopTraderInventorySection](#shoptraderinventorysection)
- [SimpleTimeStamper](#simpletimestamper)
- [Slider](#slider)
- [SpecificItemLoadFirst](#specificitemloadfirst)
- [SpeedGroup](#speedgroup)
- [SplashScreen](#splashscreen)
- [Spot](#spot)
- [SpottingPeopleMgr](#spottingpeoplemgr)
- [SquadCellView](#squadcellview)
- [SquadData](#squaddata)
- [SquadItemBox](#squaditembox)
- [SquadListWindow](#squadlistwindow)
- [SquadManagementScreen](#squadmanagementscreen)
- [Stat](#stat)
- [StatGroup](#statgroup)
- [StateT](#statet)
- [StaticEnt](#staticent)
- [StorageBuilding](#storagebuilding)
- [StringPair](#stringpair)
- [Sword](#sword)
- [SysMessage](#sysmessage)
- [TagsClass](#tagsclass)
- [TaskData](#taskdata)
- [TaskStateData](#taskstatedata)
- [Tasker](#tasker)
- [Terrain](#terrain)
- [TextureArrayLoadData](#texturearrayloaddata)
- [TextureLoadData](#textureloaddata)
- [ThreadClass](#threadclass)
- [ThreadWannabe](#threadwannabe)
- [TimeOfDay](#timeofday)
- [TimerClass](#timerclass)
- [TitleScreen](#titlescreen)
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
- [TownListWindow](#townlistwindow)
- [TownPositionCacher](#townpositioncacher)
- [TradeCulture](#tradeculture)
- [TradeResult](#traderesult)
- [TraderInventoryLayout](#traderinventorylayout)
- [TransformWindow](#transformwindow)
- [TreeData](#treedata)
- [TriggerCallback](#triggercallback)
- [TripleInt](#tripleint)
- [TurretBuilding](#turretbuilding)
- [TutorialGUI](#tutorialgui)
- [TutorialGUILine](#tutorialguiline)
- [TutorialItem](#tutorialitem)
- [TutorialSubItem](#tutorialsubitem)
- [TutorialpediaGUI](#tutorialpediagui)
- [UniqueSpawnData](#uniquespawndata)
- [UseableStuff](#useablestuff)
- [UtilityT](#utilityt)
- [VisibleObjectInfo](#visibleobjectinfo)
- [WallBuilding](#wallbuilding)
- [Weapon](#weapon)
- [WeatherRegion](#weatherregion)
- [WhoSeesMe](#whoseesme)
- [WindGeneratorBuilding](#windgeneratorbuilding)
- [WorldEventStateQuery](#worldeventstatequery)
- [WorldEventStateQueryList](#worldeventstatequerylist)
- [YesNoMaybe](#yesnomaybe)
- [ZoneManager](#zonemanager)
- [ZoneManagerInterfaceT](#zonemanagerinterfacet)
- [ZoneMap](#zonemap)
- [ZoneSpacialGrid](#zonespacialgrid)
- [hkArray](#hkarray)
- [hkArrayBase](#hkarraybase)
- [hkBool](#hkbool)
- [hkMemoryAllocator](#hkmemoryallocator)
- [hkVector4f](#hkvector4f)
- [hkVector4fComparison](#hkvector4fcomparison)
- [iVector2](#ivector2)
- [physHit](#physhit)
- [rendHit](#rendhit)

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
| _CONSTRUCTOR | _CONSTRUCTOR | `a: Quaternion` | `AABB2D` | `obj:_CONSTRUCTOR(a)` |
| setNull | setNull | `` | `void` | `obj:setNull()` |
| pointWithin | pointWithin | `v: Vector3` | `boolean` | `obj:pointWithin(v)` |
| inflate | inflate | `amount: number` | `void` | `obj:inflate(amount)` |
| sizeX | sizeX | `` | `number` | `obj:sizeX()` |
| sizeY | sizeY | `` | `number` | `obj:sizeY()` |
| intersects | intersects | `v1: Vector3, radius: number` | `boolean` | `obj:intersects(v1, radius)` |
| intersects2 | intersects2 | `` | `void` | `obj:intersects2()` |

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

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `AIOptions` | `obj:_CONSTRUCTOR()` |
| load | load | `` | `void` | `obj:load()` |
| save | save | `` | `void` | `obj:save()` |

## AbstractMovementBase
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| officiallyStopped | officiallyStopped | boolean | RW | `obj.officiallyStopped = <value>` |
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
| roadFollower | (void* | lightuserdata | R | `obj.roadFollower` |
| roadWeight | roadWeight | number | RW | `obj.roadWeight = <value>` |
| speedGroup | speedGroup | SpeedGroup | RW | `obj.speedGroup = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `AbstractMovementBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| create | create | `_pos: Vector3` | `void` | `obj:create(_pos)` |
| getHandle | getHandle | `` | `void` | `obj:getHandle()` |
| _NV_getHandle | _NV_getHandle | `` | `void` | `obj:_NV_getHandle()` |
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
| extractRoadFollower | extractRoadFollower | `` | `lightuserdata` | `obj:extractRoadFollower()` |
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
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getFacingDirection | getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |
| setDestination | setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:setDestination(dest, notVertical)` |
| _NV_setDestination | _NV_setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:_NV_setDestination(dest, notVertical)` |
| setCurrentRoadFollower | setCurrentRoadFollower | `d: Vector3, r: userdata` | `void` | `obj:setCurrentRoadFollower(d, r)` |
| setPatrolInput | setPatrolInput | `patrol: userdata` | `void` | `obj:setPatrolInput(patrol)` |
| _NV_setPatrolInput | _NV_setPatrolInput | `patrol: userdata` | `void` | `obj:_NV_setPatrolInput(patrol)` |
| setDesiredSpeed | setDesiredSpeed | `i: integer` | `void` | `obj:setDesiredSpeed(i)` |
| setDesiredSpeedOrders | setDesiredSpeedOrders | `i: integer` | `void` | `obj:setDesiredSpeedOrders(i)` |

## ActivePlatoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _groupSense | (void* | lightuserdata | R | `obj._groupSense` |
| isAnimalsOnly | isAnimalsOnly | boolean | RW | `obj.isAnimalsOnly = <value>` |
| me | me | Platoon | RW | `obj.me = <value>` |
| characterHandles | (void* | lightuserdata | R | `obj.characterHandles` |
| p_TIME | p_TIME | number | RW | `obj.p_TIME = <value>` |
| lastActiveZone | lastActiveZone | ZoneMap | RW | `obj.lastActiveZone = <value>` |
| _myMemory | (void* | lightuserdata | R | `obj._myMemory` |
| squadleader | squadleader | Character | RW | `obj.squadleader = <value>` |
| backupLeader | backupLeader | Character | RW | `obj.backupLeader = <value>` |
| deactivationTimer | deactivationTimer | number | RW | `obj.deactivationTimer = <value>` |
| workingPos | workingPos | Vector3 | RW | `obj.workingPos = <value>` |
| currentGoal | currentGoal | Tasker | RW | `obj.currentGoal = <value>` |
| positionMoved | positionMoved | Vector3 | RW | `obj.positionMoved = <value>` |
| teleportTo | teleportTo | Vector3 | RW | `obj.teleportTo = <value>` |
| teleportMessage | teleportMessage | boolean | RW | `obj.teleportMessage = <value>` |
| isPlayer | isPlayer | PlayerInterface | RW | `obj.isPlayer = <value>` |
| isPhysical | isPhysical | boolean | RW | `obj.isPhysical = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _recalculateIsIntact | _recalculateIsIntact | `` | `boolean` | `obj:_recalculateIsIntact()` |
| isAnyoneCaptured | isAnyoneCaptured | `` | `boolean` | `obj:isAnyoneCaptured()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getGroupSense | getGroupSense | `` | `lightuserdata` | `obj:getGroupSense()` |
| getMemory | getMemory | `` | `lightuserdata` | `obj:getMemory()` |
| removeObject | removeObject | `` | `boolean` | `obj:removeObject()` |
| _NV_removeObject | _NV_removeObject | `` | `boolean` | `obj:_NV_removeObject()` |
| addActiveObject | addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| addCharacterAt | addCharacterAt | `index: integer` | `void` | `obj:addCharacterAt(index)` |
| swapCharacters | swapCharacters | `indexA: integer, indexB: integer` | `void` | `obj:swapCharacters(indexA, indexB)` |
| emptySquadCheck | emptySquadCheck | `` | `void` | `obj:emptySquadCheck()` |
| clearAllTheUniqueNPCStates | clearAllTheUniqueNPCStates | `` | `void` | `obj:clearAllTheUniqueNPCStates()` |
| isIntact | isIntact | `` | `boolean` | `obj:isIntact()` |
| getSquadLeader_theRealOne | getSquadLeader_theRealOne | `` | `Character` | `obj:getSquadLeader_theRealOne()` |
| getNearestActiveCharacter | getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getSquadSize | getSquadSize | `` | `integer` | `obj:getSquadSize()` |
| setSquadLeader | setSquadLeader | `` | `void` | `obj:setSquadLeader()` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `_posOffset: Vector3` | `ActivePlatoon` | `obj:_CONSTRUCTOR(_posOffset)` |
| unloadCheck | unloadCheck | `` | `boolean` | `obj:unloadCheck()` |
| setupCheck | setupCheck | `` | `YesNoMaybe` | `obj:setupCheck()` |
| destroyCharacters | destroyCharacters | `justUnload: boolean` | `void` | `obj:destroyCharacters(justUnload)` |
| serialiseCharacterData | serialiseCharacterData | `` | `void` | `obj:serialiseCharacterData()` |
| saveToDisk | saveToDisk | `levelEditor: boolean, force: string` | `void` | `obj:saveToDisk(levelEditor, force)` |
| loadCharacters | loadCharacters | `_a1: Vector3` | `void` | `obj:loadCharacters(_a1)` |
| _NV_loadCharacters | _NV_loadCharacters | `_a1: Vector3` | `void` | `obj:_NV_loadCharacters(_a1)` |
| calculateCurrentPos | calculateCurrentPos | `` | `Vector3` | `obj:calculateCurrentPos()` |
| _checkForUniqueCharactersOnUnload | _checkForUniqueCharactersOnUnload | `` | `void` | `obj:_checkForUniqueCharactersOnUnload()` |
| getName | ActivePlatoon_getName | `` | `string` | `obj:getName()` |
| loadFromDisk | ActivePlatoon_loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:loadFromDisk(force, extra)` |
| _NV_loadFromDisk | ActivePlatoon__NV_loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:_NV_loadFromDisk(force, extra)` |
| getCharactersInArea | ActivePlatoon_getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| loadInstance | ActivePlatoon_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |
| _NV_loadInstance | ActivePlatoon__NV_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:_NV_loadInstance(skipSaveState, pos, rot, positionMoved)` |

## AnimalInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `AnimalInventoryLayout` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## AppearanceAnimal
**Header:** `extern/KenshiLib/Include/kenshi/appearance.h`

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
| slots | (void* | lightuserdata | R | `obj.slots` |
| msgClearHarpoons | msgClearHarpoons | boolean | RW | `obj.msgClearHarpoons = <value>` |
| woundsListMutex | (void* | lightuserdata | R | `obj.woundsListMutex` |
| body | (void* | lightuserdata | RW | `obj.body = <value>` |
| bodyLoader | (void* | lightuserdata | R | `obj.bodyLoader` |
| isCreatingBody | isCreatingBody | boolean | RW | `obj.isCreatingBody = <value>` |
| bodyRadius | bodyRadius | number | RW | `obj.bodyRadius = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| bodyFilename | bodyFilename | string | RW | `obj.bodyFilename = <value>` |
| animation | (void* | lightuserdata | R | `obj.animation` |
| female | female | boolean | RW | `obj.female = <value>` |
| updatedAttachments | updatedAttachments | boolean | RW | `obj.updatedAttachments = <value>` |
| updatedAppearanceData | updatedAppearanceData | boolean | RW | `obj.updatedAppearanceData = <value>` |
| updateBody | updateBody | boolean | RW | `obj.updateBody = <value>` |
| suid | suid | integer | RW | `obj.suid = <value>` |
| appearanceData | appearanceData | GameDataCopyStandalone | RW | `obj.appearanceData = <value>` |
| raceData | raceData | GameData | RW | `obj.raceData = <value>` |
| factionColor | factionColor | GameData | RW | `obj.factionColor = <value>` |
| hairStyle | hairStyle | GameData | RW | `obj.hairStyle = <value>` |
| shaved | shaved | boolean | RW | `obj.shaved = <value>` |
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
| setAppearanceData | setAppearanceData | `` | `void` | `obj:setAppearanceData()` |
| getAppearanceData | getAppearanceData | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| activate | activate | `` | `void` | `obj:activate()` |
| _NV_activate | _NV_activate | `` | `void` | `obj:_NV_activate()` |
| deactivate | deactivate | `` | `void` | `obj:deactivate()` |
| _NV_deactivate | _NV_deactivate | `` | `void` | `obj:_NV_deactivate()` |
| isFemale | isFemale | `` | `boolean` | `obj:isFemale()` |
| setGender | setGender | `_female: boolean` | `void` | `obj:setGender(_female)` |
| _NV_setGender | _NV_setGender | `_female: boolean` | `void` | `obj:_NV_setGender(_female)` |
| getRace | getRace | `` | `GameData` | `obj:getRace()` |
| attachEffect | attachEffect | `boneName: string, offsetPosition: Vector3, offsetOrientation: Quaternion, manual: boolean, baseEmission: number` | `lightuserdata` | `obj:attachEffect(boneName, offsetPosition, offsetOrientation, manual, baseEmission)` |
| getAttachedEntity | getAttachedEntity | `slot: string` | `lightuserdata` | `obj:getAttachedEntity(slot)` |
| detachAllHarpoonsT | detachAllHarpoonsT | `` | `void` | `obj:detachAllHarpoonsT()` |
| _detachAllHarpoons | _detachAllHarpoons | `` | `void` | `obj:_detachAllHarpoons()` |
| updateWetness | updateWetness | `force: boolean` | `void` | `obj:updateWetness(force)` |
| updateBloodyness | updateBloodyness | `` | `void` | `obj:updateBloodyness()` |
| getAttachmentPosition | getAttachmentPosition | `slot: string, pos: Vector3, rot: Quaternion` | `boolean` | `obj:getAttachmentPosition(slot, pos, rot)` |
| hasSlot | hasSlot | `slot: string` | `boolean` | `obj:hasSlot(slot)` |
| getNormalisedCharacterHeight | getNormalisedCharacterHeight | `` | `number` | `obj:getNormalisedCharacterHeight()` |
| getCharacterHeight | getCharacterHeight | `` | `number` | `obj:getCharacterHeight()` |
| getAnimationSystem | getAnimationSystem | `` | `lightuserdata` | `obj:getAnimationSystem()` |
| getSceneNode | getSceneNode | `` | `lightuserdata` | `obj:getSceneNode()` |
| getSkeleton | getSkeleton | `` | `lightuserdata` | `obj:getSkeleton()` |
| getBody | getBody | `` | `lightuserdata` | `obj:getBody()` |
| getBodyRadius | getBodyRadius | `` | `number` | `obj:getBodyRadius()` |
| failedToLoad | failedToLoad | `` | `boolean` | `obj:failedToLoad()` |
| getBonePosition | getBonePosition | `boneName: string` | `Vector3` | `obj:getBonePosition(boneName)` |
| getBoneOrientation | getBoneOrientation | `boneName: string` | `Quaternion` | `obj:getBoneOrientation(boneName)` |
| getVertexWorldPosition | getVertexWorldPosition | `boneName: string, vertex: integer` | `Vector3` | `obj:getVertexWorldPosition(boneName, vertex)` |
| getRandomVertex | getRandomVertex | `boneName: string, direction: integer` | `integer` | `obj:getRandomVertex(boneName, direction)` |
| notifyDirty | notifyDirty | `` | `void` | `obj:notifyDirty()` |
| reload | reload | `` | `void` | `obj:reload()` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| updateAppearance | updateAppearance | `` | `void` | `obj:updateAppearance()` |
| _NV_updateAppearance | _NV_updateAppearance | `` | `void` | `obj:_NV_updateAppearance()` |
| updatePortrait | updatePortrait | `` | `void` | `obj:updatePortrait()` |
| updateMovementScale | updateMovementScale | `` | `void` | `obj:updateMovementScale()` |
| switchLights | switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| hasLights | hasLights | `` | `boolean` | `obj:hasLights()` |
| attachItem_Hair | attachItem_Hair | `slot: string` | `boolean` | `obj:attachItem_Hair(slot)` |
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
| createAttachedObject | createAttachedObject | `` | `lightuserdata` | `obj:createAttachedObject()` |
| updateOverlap | updateOverlap | `` | `void` | `obj:updateOverlap()` |
| updateCharaterTexture | updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| getCharacterHeightSpeedMultiplier | getCharacterHeightSpeedMultiplier | `` | `number` | `obj:getCharacterHeightSpeedMultiplier()` |

## AppearanceHuman
**Header:** `extern/KenshiLib/Include/kenshi/appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| robotLegScale | robotLegScale | number | RW | `obj.robotLegScale = <value>` |
| lastPhysiqueStats | lastPhysiqueStats | Vector3 | RW | `obj.lastPhysiqueStats = <value>` |
| bulkMult | bulkMult | number | RW | `obj.bulkMult = <value>` |
| muscleMult | muscleMult | number | RW | `obj.muscleMult = <value>` |
| skinnyMult | skinnyMult | number | RW | `obj.skinnyMult = <value>` |
| flayed | flayed | boolean | RW | `obj.flayed = <value>` |
| beard | beard | GameData | RW | `obj.beard = <value>` |
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
| craftTime | craftTime | number | RW | `obj.craftTime = <value>` |
| armourClassEnum | (lua_Integer | integer | RW | `obj.armourClassEnum = <value>` |
| bodypartCoverage | bodypartCoverage | unknown | RW | `obj.bodypartCoverage = <value>` |
| stigma | (lua_Integer | integer | RW | `obj.stigma = <value>` |
| weatherProtections | (lua_Integer | integer | RW | `obj.weatherProtections = <value>` |

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
| didIHitFlesh | didIHitFlesh | `` | `boolean` | `obj:didIHitFlesh()` |
| hasArmourCoverage | hasArmourCoverage | `` | `boolean` | `obj:hasArmourCoverage()` |
| getCraftTime | getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getWeatherProtection_simple | getWeatherProtection_simple | `weather: integer` | `number` | `obj:getWeatherProtection_simple(weather)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `_level: integer` | `Armour` | `obj:_CONSTRUCTOR(_level)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getArmourCraftingMaterialConsumptionRate | getArmourCraftingMaterialConsumptionRate | `` | `number` | `obj:getArmourCraftingMaterialConsumptionRate()` |

## Array2d
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nRows | nRows | integer | RW | `obj.nRows = <value>` |
| nCols | nCols | integer | RW | `obj.nCols = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| resize | resize | `nrows: integer, ncols: integer, clear: boolean` | `void` | `obj:resize(nrows, ncols, clear)` |
| setToZeros | setToZeros | `` | `void` | `obj:setToZeros()` |

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
| me | me | Character | RW | `obj.me = <value>` |
| combatClass | combatClass | CombatClass | RW | `obj.combatClass = <value>` |
| attackSlotH | attackSlotH | number | RW | `obj.attackSlotH = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `AttackSlotManager` | `obj:_CONSTRUCTOR()` |
| hasFreeAttackSlot | hasFreeAttackSlot | `` | `boolean` | `obj:hasFreeAttackSlot()` |
| freeAllSlotsH | freeAllSlotsH | `` | `void` | `obj:freeAllSlotsH()` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| update | update | `` | `void` | `obj:update()` |
| getNumAttackSlots | getNumAttackSlots | `` | `integer` | `obj:getNumAttackSlots()` |
| getMaxPossibleAttackSlots | getMaxPossibleAttackSlots | `` | `integer` | `obj:getMaxPossibleAttackSlots()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BackThreadMessagesToMainT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| swapMutex | swapMutex | unknown | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| flush | flush | `` | `boolean` | `obj:flush()` |
| _NV_flush | _NV_flush | `` | `void` | `obj:_NV_flush()` |

## BackpackInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `standAlone: boolean` | `BackpackInventoryLayout` | `obj:_CONSTRUCTOR(standAlone)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BadSize
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`

## BaseLayout
**Header:** `???`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mMainWidget | (void* | lightuserdata | R | `obj.mMainWidget` |
| mPrefix | mPrefix | string | RW | `obj.mPrefix = <value>` |
| mLayoutName | mLayoutName | string | RW | `obj.mLayoutName = <value>` |

## BoundsViolation
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`

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
| crimeAgainst | crimeAgainst | unknown | RW | `obj.crimeAgainst = <value>` |
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

## Box
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| modal | modal | boolean | RW | `obj.modal = <value>` |
| callback | (void* | lightuserdata | R | `obj.callback` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `MessageBoxManager::Box` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| currentBuildingGroup | currentBuildingGroup | BuildModeWindow::BuildingGroup | RW | `obj.currentBuildingGroup = <value>` |
| currentBuildingInfo | currentBuildingInfo | GameData | RW | `obj.currentBuildingInfo = <value>` |
| currentBuildingIndex | currentBuildingIndex | integer | RW | `obj.currentBuildingIndex = <value>` |
| switchBuildingIndex | switchBuildingIndex | integer | RW | `obj.switchBuildingIndex = <value>` |
| statsDataPanel | statsDataPanel | DatapanelGUI | RW | `obj.statsDataPanel = <value>` |
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
| residentSquad | residentSquad | unknown | RW | `obj.residentSquad = <value>` |
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
| _town | _town | unknown | RW | `obj._town = <value>` |
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
| getTownHandle | getTownHandle | `` | `void` | `obj:getTownHandle()` |
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
**Header:** `extern/KenshiLib/Include/kenshi/faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| toReplace | toReplace | ogre_unordered_set<GameData*>::type | RW | `obj.toReplace = <value>` |
| replaceWith | replaceWith | FitnessSelector<GameData*> | RW | `obj.replaceWith = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasReplacement | hasReplacement | `` | `boolean` | `obj:hasReplacement()` |
| getReplacement | getReplacement | `` | `GameData` | `obj:getReplacement()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CPerfTimer
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| Stop | Stop | `` | `void` | `obj:Stop()` |
| Resolution | Resolution | `` | `number` | `obj:Resolution()` |
| Resolutionms | Resolutionms | `` | `number` | `obj:Resolutionms()` |
| Resolutionus | Resolutionus | `` | `number` | `obj:Resolutionus()` |
| Elapsed | Elapsed | `` | `number` | `obj:Elapsed()` |
| Elapsedms | Elapsedms | `` | `number` | `obj:Elapsedms()` |
| Elapsedus | Elapsedus | `` | `number` | `obj:Elapsedus()` |

## CPerfTimerT
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`

## CameraClass
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isRotating | isRotating | boolean | RW | `obj.isRotating = <value>` |
| rotationMarker | (void* | lightuserdata | R | `obj.rotationMarker` |
| yaw | yaw | number | RW | `obj.yaw = <value>` |
| pitch | pitch | number | RW | `obj.pitch = <value>` |
| initialised | initialised | boolean | RW | `obj.initialised = <value>` |
| terrainLoaded | terrainLoaded | boolean | RW | `obj.terrainLoaded = <value>` |
| objectCurrentlyFollowing | objectCurrentlyFollowing | unknown | RW | `obj.objectCurrentlyFollowing = <value>` |
| objectCurrentlyFollowingOffset | objectCurrentlyFollowingOffset | Vector3 | RW | `obj.objectCurrentlyFollowingOffset = <value>` |
| center | (void* | lightuserdata | RW | `obj.center = <value>` |
| altitude | altitude | number | RW | `obj.altitude = <value>` |
| camera | (void* | lightuserdata | R | `obj.camera` |
| node | (void* | lightuserdata | R | `obj.node` |
| currentMusic | currentMusic | integer | RW | `obj.currentMusic = <value>` |
| inBuilding | inBuilding | unknown | RW | `obj.inBuilding = <value>` |
| timeInGame | timeInGame | number | RW | `obj.timeInGame = <value>` |
| targetPositionY | targetPositionY | number | RW | `obj.targetPositionY = <value>` |
| speedY | speedY | number | RW | `obj.speedY = <value>` |
| centerBuilding | centerBuilding | Building | RW | `obj.centerBuilding = <value>` |
| centerBuildingY | centerBuildingY | number | RW | `obj.centerBuildingY = <value>` |
| currentCollisionGroup | currentCollisionGroup | integer | RW | `obj.currentCollisionGroup = <value>` |
| currentFloor | currentFloor | integer | RW | `obj.currentFloor = <value>` |
| freeCameraMode | freeCameraMode | boolean | RW | `obj.freeCameraMode = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | reset | `` | `void` | `obj:reset()` |
| update | update | `controlEnabled: boolean` | `void` | `obj:update(controlEnabled)` |
| focusCameraOnObject | focusCameraOnObject | `offset: Vector3, nearZoom: boolean` | `void` | `obj:focusCameraOnObject(offset, nearZoom)` |
| updateOptionSettings | updateOptionSettings | `` | `void` | `obj:updateOptionSettings()` |
| save | save | `` | `void` | `obj:save()` |
| load | load | `` | `void` | `obj:load()` |
| teleport | teleport | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| stopFollowing | stopFollowing | `` | `void` | `obj:stopFollowing()` |
| manuallySetOrientationAndZoom | manuallySetOrientationAndZoom | `rot: Quaternion, zoom: number` | `void` | `obj:manuallySetOrientationAndZoom(rot, zoom)` |
| getFacingDirection | getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |
| getCenter | getCenter | `` | `Vector3` | `obj:getCenter()` |
| getCameraPos | getCameraPos | `` | `Vector3` | `obj:getCameraPos()` |
| getCenterNode | getCenterNode | `` | `lightuserdata` | `obj:getCenterNode()` |
| getCameraNode | getCameraNode | `` | `lightuserdata` | `obj:getCameraNode()` |
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

## CampaignRequest
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timeToStart | timeToStart | TimeOfDay | RW | `obj.timeToStart = <value>` |
| data | (void* | lightuserdata | R | `obj.data` |
| target | target | unknown | RW | `obj.target = <value>` |
| homeBase | homeBase | unknown | RW | `obj.homeBase = <value>` |
| enemy | enemy | Faction | RW | `obj.enemy = <value>` |
| numAttempts | numAttempts | integer | RW | `obj.numAttempts = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| tryToChangeTarget | tryToChangeTarget | `` | `boolean` | `obj:tryToChangeTarget()` |

## CampaignTriggerData
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| what | what | GameData | RW | `obj.what = <value>` |
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
| target | target | unknown | RW | `obj.target = <value>` |
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
| getHandle | CharBody_getHandle | `` | `void` | `obj:getHandle()` |
| getCurrentSubject | CharBody_getCurrentSubject | `` | `void` | `obj:getCurrentSubject()` |

## CharMovement
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| flockingVector | flockingVector | Vector3 | RW | `obj.flockingVector = <value>` |
| combatMover | combatMover | CombatMovementController | RW | `obj.combatMover = <value>` |
| combatMover2 | combatMover2 | FormationMover | RW | `obj.combatMover2 = <value>` |
| flockingTools | flockingTools | FlockingTools | RW | `obj.flockingTools = <value>` |
| formation | (void* | lightuserdata | R | `obj.formation` |
| enemyFormation | (void* | lightuserdata | R | `obj.enemyFormation` |
| havokCharacter | (void* | lightuserdata | R | `obj.havokCharacter` |
| tracer | (void* | lightuserdata | R | `obj.tracer` |
| dontEverRecreateMe | dontEverRecreateMe | boolean | RW | `obj.dontEverRecreateMe = <value>` |
| floorGroup | floorGroup | integer | RW | `obj.floorGroup = <value>` |
| building | building | unknown | RW | `obj.building = <value>` |
| initCheck | initCheck | boolean | RW | `obj.initCheck = <value>` |
| _combatMoveSpeedMult | _combatMoveSpeedMult | number | RW | `obj._combatMoveSpeedMult = <value>` |
| destinationLoaded | destinationLoaded | boolean | RW | `obj.destinationLoaded = <value>` |
| footprintRadius | footprintRadius | number | RW | `obj.footprintRadius = <value>` |
| edgeTarget | edgeTarget | integer | RW | `obj.edgeTarget = <value>` |
| _lastOffMeshCheck | _lastOffMeshCheck | number | RW | `obj._lastOffMeshCheck = <value>` |
| movingToEdge | movingToEdge | boolean | RW | `obj.movingToEdge = <value>` |
| lastStepTime | lastStepTime | number | RW | `obj.lastStepTime = <value>` |
| animationOverride | animationOverride | boolean | RW | `obj.animationOverride = <value>` |
| trackingAnimRelocationVector | trackingAnimRelocationVector | Vector3 | RW | `obj.trackingAnimRelocationVector = <value>` |
| desiredMotion | desiredMotion | Vector3 | RW | `obj.desiredMotion = <value>` |
| moveLimit | moveLimit | number | RW | `obj.moveLimit = <value>` |
| animation | (void* | lightuserdata | RW | `obj.animation = <value>` |
| character | character | Character | RW | `obj.character = <value>` |
| clickHull | (void* | lightuserdata | R | `obj.clickHull` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `CharMovement` | `obj:_CONSTRUCTOR()` |
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
| getHandle | getHandle | `` | `void` | `obj:getHandle()` |
| _NV_getHandle | _NV_getHandle | `` | `void` | `obj:_NV_getHandle()` |
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
| getLastGroundTraceResultMT | getLastGroundTraceResultMT | `` | `physHit` | `obj:getLastGroundTraceResultMT()` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| toGround | toGround | `` | `boolean` | `obj:toGround()` |
| updateGroundMaterial | updateGroundMaterial | `` | `void` | `obj:updateGroundMaterial()` |
| getCombatMoveSpeedMult | getCombatMoveSpeedMult | `` | `number` | `obj:getCombatMoveSpeedMult()` |
| setDestination | setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:setDestination(dest, notVertical)` |
| _NV_setDestination | _NV_setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:_NV_setDestination(dest, notVertical)` |
| setLookatTarget | setLookatTarget | `` | `void` | `obj:setLookatTarget()` |

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
| currentWeaponType | (lua_Integer | integer | RW | `obj.currentWeaponType = <value>` |
| pCurrentWeaponSkill | (void* | lightuserdata | RW | `obj.pCurrentWeaponSkill = <value>` |
| currentWeaponLength | currentWeaponLength | number | RW | `obj.currentWeaponLength = <value>` |
| weapon | weapon | unknown | RW | `obj.weapon = <value>` |
| weaponWeight | weaponWeight | number | RW | `obj.weaponWeight = <value>` |
| _weatherProtections | _weatherProtections | WeatherProtectionsMapBinding::MapType | RW | `obj._weatherProtections = <value>` |
| bonusRaces | bonusRaces | BonusRacesMapBinding::MapType | RW | `obj.bonusRaces = <value>` |

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
| serialise | serialise | `` | `void` | `obj:serialise()` |
| updateStats | updateStats | `` | `void` | `obj:updateStats()` |
| init | init | `` | `void` | `obj:init()` |
| _NV_init | _NV_init | `` | `void` | `obj:_NV_init()` |
| _randomiseStats | _randomiseStats | `amount: number` | `void` | `obj:_randomiseStats(amount)` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| getGUIDataForMainInfo | getGUIDataForMainInfo | `category: integer, combatMode: boolean` | `void` | `obj:getGUIDataForMainInfo(category, combatMode)` |
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
| _getMeleeAttackBase | _getMeleeAttackBase | `` | `number` | `obj:_getMeleeAttackBase()` |
| getMaxHealAmount | getMaxHealAmount | `isRobot: boolean` | `number` | `obj:getMaxHealAmount(isRobot)` |
| isDefensiveMode | isDefensiveMode | `` | `boolean` | `obj:isDefensiveMode()` |
| holdPositionMode | holdPositionMode | `` | `boolean` | `obj:holdPositionMode()` |
| setHoldLocation | setHoldLocation | `v: Vector3` | `void` | `obj:setHoldLocation(v)` |
| clearHoldLocation | clearHoldLocation | `` | `void` | `obj:clearHoldLocation()` |
| getBashAnimation | getBashAnimation | `range: number` | `CombatTechniqueData` | `obj:getBashAnimation(range)` |
| chooseAttack | chooseAttack | `range: number, weaponReach: number, opponentIsStationary: boolean` | `CombatTechniqueData` | `obj:chooseAttack(range, weaponReach, opponentIsStationary)` |
| chooseBlock | chooseBlock | `dir: integer, opponentAttackSkill: number, from: integer` | `CombatTechniqueData` | `obj:chooseBlock(dir, opponentAttackSkill, from)` |
| calculateStumbleBlockTimer | calculateStumbleBlockTimer | `stumbleForce: number` | `number` | `obj:calculateStumbleBlockTimer(stumbleForce)` |
| calculateTechniqueInegrityCheckTimer | calculateTechniqueInegrityCheckTimer | `` | `number` | `obj:calculateTechniqueInegrityCheckTimer()` |
| calculateToughnessDamageResistanceMult | calculateToughnessDamageResistanceMult | `` | `number` | `obj:calculateToughnessDamageResistanceMult()` |
| calculateToughnessWoundDegenerationRate | calculateToughnessWoundDegenerationRate | `` | `number` | `obj:calculateToughnessWoundDegenerationRate()` |
| getAttackChance | getAttackChance | `` | `number` | `obj:getAttackChance()` |
| getAttackCuttingDamage | getAttackCuttingDamage | `` | `number` | `obj:getAttackCuttingDamage()` |
| getAttackBluntPower | getAttackBluntPower | `` | `number` | `obj:getAttackBluntPower()` |
| getAttackBleedDamageMult | getAttackBleedDamageMult | `` | `number` | `obj:getAttackBleedDamageMult()` |
| getAttackPierceDamage | getAttackPierceDamage | `` | `number` | `obj:getAttackPierceDamage()` |
| getTotalAttackDamageFor | getTotalAttackDamageFor | `` | `Damages` | `obj:getTotalAttackDamageFor()` |
| getEquippedWeaponSkill | getEquippedWeaponSkill | `` | `number` | `obj:getEquippedWeaponSkill()` |
| _NV_getEquippedWeaponSkill | _NV_getEquippedWeaponSkill | `` | `number` | `obj:_NV_getEquippedWeaponSkill()` |
| getSkillDifferenceRatio | getSkillDifferenceRatio | `mine: number, his: number` | `number` | `obj:getSkillDifferenceRatio(mine, his)` |
| calculateDeadTime | calculateDeadTime | `state: integer` | `number` | `obj:calculateDeadTime(state)` |
| xpToughness_RagdollEvent | xpToughness_RagdollEvent | `` | `void` | `obj:xpToughness_RagdollEvent()` |
| xpToughness_GetUpEvent | xpToughness_GetUpEvent | `` | `void` | `obj:xpToughness_GetUpEvent()` |
| xpToughness_PunchSomething | xpToughness_PunchSomething | `mat: integer` | `void` | `obj:xpToughness_PunchSomething(mat)` |
| xpFirstAid | xpFirstAid | `time: number, medicStat: integer` | `void` | `obj:xpFirstAid(time, medicStat)` |
| xpRunning | xpRunning | `time: number, speed: number` | `void` | `obj:xpRunning(time, speed)` |
| xpStealth | xpStealth | `time: number, enemiesAbout: boolean, isMoving: boolean` | `void` | `obj:xpStealth(time, enemiesAbout, isMoving)` |
| xpStealthHearCheckEvent | xpStealthHearCheckEvent | `enemiesAbout: boolean, trespassing: boolean, seen: boolean` | `void` | `obj:xpStealthHearCheckEvent(enemiesAbout, trespassing, seen)` |
| stealthXPMultForGUI | stealthXPMultForGUI | `` | `StringPair` | `obj:stealthXPMultForGUI()` |
| xpMassCombat | xpMassCombat | `` | `void` | `obj:xpMassCombat()` |
| xpEngineering | xpEngineering | `time: number` | `void` | `obj:xpEngineering(time)` |
| xpLockpicking | xpLockpicking | `lockLevel: integer, success: boolean` | `void` | `obj:xpLockpicking(lockLevel, success)` |
| xpGeneral | xpGeneral | `time: number, mult: number, what: integer` | `void` | `obj:xpGeneral(time, mult, what)` |
| calculateAthleticsXPMult | calculateAthleticsXPMult | `speed: number` | `number` | `obj:calculateAthleticsXPMult(speed)` |
| calculateStrengthXPMultFromWalking | calculateStrengthXPMultFromWalking | `` | `number` | `obj:calculateStrengthXPMultFromWalking()` |
| setWeapon | setWeapon | `` | `void` | `obj:setWeapon()` |
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
| _calculateMaxSwimSpeed | _calculateMaxSwimSpeed | `` | `number` | `obj:_calculateMaxSwimSpeed()` |
| calculateSwimSpeed | calculateSwimSpeed | `` | `number` | `obj:calculateSwimSpeed()` |
| calculateDodgeChance | calculateDodgeChance | `versus: number, stumbling: boolean` | `number` | `obj:calculateDodgeChance(versus, stumbling)` |
| calculateMaxRunSpeed | calculateMaxRunSpeed | `` | `void` | `obj:calculateMaxRunSpeed()` |
| _calculateEncumberanceMult | _calculateEncumberanceMult | `` | `number` | `obj:_calculateEncumberanceMult()` |
| _calculateWeaponWeightSpeedMultiplier | _calculateWeaponWeightSpeedMultiplier | `weaponWeight: number` | `void` | `obj:_calculateWeaponWeightSpeedMultiplier(weaponWeight)` |
| currentWeaponHand | currentWeaponHand | `` | `integer` | `obj:currentWeaponHand()` |
| calculateAttackOrBlockSpeed | calculateAttackOrBlockSpeed | `weaponWeightSpeedMult: number, attackOrBlockSkill: number, isBlock: boolean` | `number` | `obj:calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock)` |
| _calculateBlockChance | _calculateBlockChance | `versus: number` | `number` | `obj:_calculateBlockChance(versus)` |
| _recalculateStats | _recalculateStats | `` | `void` | `obj:_recalculateStats()` |
| _NV__recalculateStats | _NV__recalculateStats | `` | `void` | `obj:_NV__recalculateStats()` |
| setEquippedWeaponSkill | setEquippedWeaponSkill | `v: number` | `void` | `obj:setEquippedWeaponSkill(v)` |
| _NV_setEquippedWeaponSkill | _NV_setEquippedWeaponSkill | `v: number` | `void` | `obj:_NV_setEquippedWeaponSkill(v)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getStrength | getStrength | `` | `number` | `obj:getStrength()` |
| getStrengthRaw | getStrengthBase | `` | `number` | `obj:getStrengthRaw()` |
| getDexterity | getDexterity | `` | `number` | `obj:getDexterity()` |
| getDexterityRaw | getDexterityBase | `` | `number` | `obj:getDexterityRaw()` |
| getToughness | getToughness | `` | `number` | `obj:getToughness()` |
| getPerception | getPerception | `` | `number` | `obj:getPerception()` |
| getAthletics | getAthletics | `` | `number` | `obj:getAthletics()` |
| getThieving | getThieving | `` | `number` | `obj:getThieving()` |
| printStealthStats | printStealthStats | `` | `void` | `obj:printStealthStats()` |
| printRunSpeedStatMax | printRunSpeedStatMax | `` | `void` | `obj:printRunSpeedStatMax()` |
| formatWholeStatStringWithBonuses | formatWholeStatStringWithBonuses | `stat: integer, current: integer` | `void` | `obj:formatWholeStatStringWithBonuses(stat, current)` |
| getStatRef | getStatRef | `what: integer` | `number` | `obj:getStatRef(what)` |
| getStatName | getStatName | `` | `void` | `obj:getStatName()` |
| getMeleeAttackRef | getMeleeAttackRef | `` | `number` | `obj:getMeleeAttackRef()` |
| getPainAnim | getPainAnim | `` | `void` | `obj:getPainAnim()` |
| xpMelee | xpMelee | `what: integer` | `void` | `obj:xpMelee(what)` |
| convertWeaponWeightToBluntMultiplier | _convertWeaponWeightToBluntMultiplier | `` | `number` | `obj:convertWeaponWeightToBluntMultiplier()` |
| convertBluntMultiplierToWeaponWeight | _convertBluntMultiplierToWeaponWeight | `` | `number` | `obj:convertBluntMultiplierToWeaponWeight()` |
| setupCombatTechniques | setupCombatTechniques | `` | `void` | `obj:setupCombatTechniques()` |
| getStealthTooltip | getStealthTooltip | `` | `void` | `obj:getStealthTooltip()` |
| getAthleticsTooltip | getAthleticsTooltip | `` | `void` | `obj:getAthleticsTooltip()` |
| getStatPenaltiesForGUI | getStatPenaltiesForGUI | `statName: string, stat: integer` | `boolean` | `obj:getStatPenaltiesForGUI(statName, stat)` |
| chooseAttacks | _chooseAttacks | `range: number, weaponReach: number, opponentIsStationary: boolean, skipMedicals: boolean, _weaponType: integer, _weaponSkill: number` | `void` | `obj:chooseAttacks(range, weaponReach, opponentIsStationary, skipMedicals, _weaponType, _weaponSkill)` |
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
| isUsingTurret | isUsingTurret | unknown | RW | `obj.isUsingTurret = <value>` |
| isCurrentlyGettingUp | isCurrentlyGettingUp | boolean | RW | `obj.isCurrentlyGettingUp = <value>` |
| isGettingEaten | isGettingEaten | integer | RW | `obj.isGettingEaten = <value>` |
| dialogue | dialogue | Dialogue | RW | `obj.dialogue = <value>` |
| currentStumblePainAnimation | currentStumblePainAnimation | string | RW | `obj.currentStumblePainAnimation = <value>` |
| _isLiterallyUnderMeleeAttackRightNowForSure | _isLiterallyUnderMeleeAttackRightNowForSure | boolean | RW | `obj._isLiterallyUnderMeleeAttackRightNowForSure = <value>` |
| _myMemory | (void* | lightuserdata | RW | `obj._myMemory = <value>` |
| lastGuyWhoDefeatedMe | lastGuyWhoDefeatedMe | unknown | RW | `obj.lastGuyWhoDefeatedMe = <value>` |
| myRace | myRace | RaceData | RW | `obj.myRace = <value>` |
| inventory | inventory | Inventory | RW | `obj.inventory = <value>` |
| rangedCombat | (void* | lightuserdata | RW | `obj.rangedCombat = <value>` |
| inWhat | inWhat | unknown | RW | `obj.inWhat = <value>` |
| isChained | isChained | boolean | RW | `obj.isChained = <value>` |
| slaveOwner | slaveOwner | unknown | RW | `obj.slaveOwner = <value>` |
| isCarryingSomething | isCarryingSomething | boolean | RW | `obj.isCarryingSomething = <value>` |
| carringObjectLeftOrRight | carringObjectLeftOrRight | string | RW | `obj.carringObjectLeftOrRight = <value>` |
| isCarryingLeftSide | isCarryingLeftSide | boolean | RW | `obj.isCarryingLeftSide = <value>` |
| carryingObject | carryingObject | unknown | RW | `obj.carryingObject = <value>` |
| messages | (lua_Integer | integer | RW | `obj.messages = <value>` |
| messageSubject | messageSubject | unknown | RW | `obj.messageSubject = <value>` |
| ragdollNavmeshPosition | ragdollNavmeshPosition | Vector3 | RW | `obj.ragdollNavmeshPosition = <value>` |
| _isBeingCarried | _isBeingCarried | boolean | RW | `obj._isBeingCarried = <value>` |
| lastUsedWeaponCategory | (lua_Integer | integer | RW | `obj.lastUsedWeaponCategory = <value>` |
| msgCarryMode | (void* | lightuserdata | RW | `obj.msgCarryMode = <value>` |
| squadMemberID | squadMemberID | integer | RW | `obj.squadMemberID = <value>` |
| diplomacyMultiplier | diplomacyMultiplier | number | RW | `obj.diplomacyMultiplier = <value>` |
| _destinationInsideBuilding | _destinationInsideBuilding | unknown | RW | `obj._destinationInsideBuilding = <value>` |
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
| whoSeesMeSneaking | second | Character::WhoSeesMe | R | `obj.whoSeesMeSneaking` |
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
| destinationIndoors | destinationIndoors | `` | `void` | `obj:destinationIndoors()` |
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
| getAttackTarget | getAttackTarget | `` | `void` | `obj:getAttackTarget()` |
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
| getIDForMemoryTagging | getIDForMemoryTagging | `` | `void` | `obj:getIDForMemoryTagging()` |
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
| getMySlaveOwner | getMySlaveOwner | `` | `void` | `obj:getMySlaveOwner()` |
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
| getCarryingObject | getCarryingObject | `` | `void` | `obj:getCarryingObject()` |
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
| isIndoors | isIndoors | `` | `void` | `obj:isIndoors()` |
| _NV_isIndoors | _NV_isIndoors | `` | `void` | `obj:_NV_isIndoors()` |
| isStandingOnBuilding | isStandingOnBuilding | `` | `void` | `obj:isStandingOnBuilding()` |
| _NV_isStandingOnBuilding | _NV_isStandingOnBuilding | `` | `void` | `obj:_NV_isStandingOnBuilding()` |
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
| getSquadMissionTarget | getSquadMissionTarget | `` | `void` | `obj:getSquadMissionTarget()` |
| setChainedMode | setChainedMode | `on: boolean` | `void` | `obj:setChainedMode(on)` |
| _ragdollMode | _ragdollMode | `on: boolean, part: integer` | `boolean` | `obj:_ragdollMode(on, part)` |

## CharacterAnimal
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| weaponIsTechnicallyEquipped | weaponIsTechnicallyEquipped | boolean | RW | `obj.weaponIsTechnicallyEquipped = <value>` |
| HPMultiplier | HPMultiplier | number | RW | `obj.HPMultiplier = <value>` |
| itemInMouthTimeStamp | itemInMouthTimeStamp | TimeOfDay | RW | `obj.itemInMouthTimeStamp = <value>` |
| smellThresholdBlood | smellThresholdBlood | number | RW | `obj.smellThresholdBlood = <value>` |
| smellThresholdEggs | smellThresholdEggs | number | RW | `obj.smellThresholdEggs = <value>` |
| ageSizeMin | ageSizeMin | number | RW | `obj.ageSizeMin = <value>` |
| ageSizeMax | ageSizeMax | number | RW | `obj.ageSizeMax = <value>` |
| lifespanInDays | lifespanInDays | number | RW | `obj.lifespanInDays = <value>` |
| lastUpdatedAge | lastUpdatedAge | number | RW | `obj.lastUpdatedAge = <value>` |
| age | age | number | RW | `obj.age = <value>` |
| weaponInHands | weaponInHands | Weapon | RW | `obj.weaponInHands = <value>` |
| audioTimeStamp | audioTimeStamp | number | RW | `obj.audioTimeStamp = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isAnimal | isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| _NV_isAnimal | _NV_isAnimal | `` | `CharacterAnimal` | `obj:_NV_isAnimal()` |
| createAnimationClass | createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| _NV_createAnimationClass | _NV_createAnimationClass | `` | `void` | `obj:_NV_createAnimationClass()` |
| drawWeapon | drawWeapon | `lastSlot: string` | `boolean` | `obj:drawWeapon(lastSlot)` |
| _NV_drawWeapon | _NV_drawWeapon | `lastSlot: string` | `boolean` | `obj:_NV_drawWeapon(lastSlot)` |
| sheatheWeapon | sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| getCurrentWeapon | getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| _NV_getCurrentWeapon | _NV_getCurrentWeapon | `` | `Weapon` | `obj:_NV_getCurrentWeapon()` |
| getThePreferredWeapon | getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| _NV_getThePreferredWeapon | _NV_getThePreferredWeapon | `` | `Weapon` | `obj:_NV_getThePreferredWeapon()` |
| createInventoryLayout | createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| giveBirth | giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:giveBirth(position, rotation)` |
| _NV_giveBirth | _NV_giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:_NV_giveBirth(position, rotation)` |
| setupInventorySections | setupInventorySections | `` | `boolean` | `obj:setupInventorySections()` |
| _NV_setupInventorySections | _NV_setupInventorySections | `` | `boolean` | `obj:_NV_setupInventorySections()` |
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
| canGoIndoors | canGoIndoors | `` | `boolean` | `obj:canGoIndoors()` |
| _NV_canGoIndoors | _NV_canGoIndoors | `` | `boolean` | `obj:_NV_canGoIndoors()` |
| getSmellHuntingThresholdBlood | getSmellHuntingThresholdBlood | `` | `number` | `obj:getSmellHuntingThresholdBlood()` |
| _NV_getSmellHuntingThresholdBlood | _NV_getSmellHuntingThresholdBlood | `` | `number` | `obj:_NV_getSmellHuntingThresholdBlood()` |
| getSmellHuntingThresholdEggs | getSmellHuntingThresholdEggs | `` | `number` | `obj:getSmellHuntingThresholdEggs()` |
| _NV_getSmellHuntingThresholdEggs | _NV_getSmellHuntingThresholdEggs | `` | `number` | `obj:_NV_getSmellHuntingThresholdEggs()` |
| getHPMultiplier | getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| _NV_getHPMultiplier | _NV_getHPMultiplier | `` | `number` | `obj:_NV_getHPMultiplier()` |
| foodUpdate | foodUpdate | `` | `void` | `obj:foodUpdate()` |
| _NV_foodUpdate | _NV_foodUpdate | `` | `void` | `obj:_NV_foodUpdate()` |
| pickupItemInMouth | pickupItemInMouth | `` | `boolean` | `obj:pickupItemInMouth()` |
| dropItemInMouth | dropItemInMouth | `` | `boolean` | `obj:dropItemInMouth()` |
| getItemInMouth | getItemInMouth | `` | `Item` | `obj:getItemInMouth()` |
| eatItemInMouth | eatItemInMouth | `` | `void` | `obj:eatItemInMouth()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `_age: number` | `CharacterAnimal` | `obj:_CONSTRUCTOR(_age)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | init | `` | `void` | `obj:init()` |
| _NV_init | _NV_init | `` | `void` | `obj:_NV_init()` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |

## CharacterEditWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterEditWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| camera | (void* | lightuserdata | R | `obj.camera` |
| txtName | (void* | lightuserdata | R | `obj.txtName` |
| txtGender | (void* | lightuserdata | R | `obj.txtGender` |
| txtRace | (void* | lightuserdata | R | `obj.txtRace` |
| txtSubRace | (void* | lightuserdata | R | `obj.txtSubRace` |
| txtCharIdx | (void* | lightuserdata | R | `obj.txtCharIdx` |
| importButton | (void* | lightuserdata | R | `obj.importButton` |
| exportButton | (void* | lightuserdata | R | `obj.exportButton` |
| panelTabs | (void* | lightuserdata | R | `obj.panelTabs` |
| panelTabsView | (void* | lightuserdata | R | `obj.panelTabsView` |
| btnPrevGender | (void* | lightuserdata | R | `obj.btnPrevGender` |
| btnNextGender | (void* | lightuserdata | R | `obj.btnNextGender` |
| btnPrevRace | (void* | lightuserdata | R | `obj.btnPrevRace` |
| btnNextRace | (void* | lightuserdata | R | `obj.btnNextRace` |
| btnPrevSubRace | (void* | lightuserdata | R | `obj.btnPrevSubRace` |
| btnNextSubRace | (void* | lightuserdata | R | `obj.btnNextSubRace` |
| btnReset | (void* | lightuserdata | R | `obj.btnReset` |
| btnRandomiseAll | (void* | lightuserdata | R | `obj.btnRandomiseAll` |
| btnRandomisePart | (void* | lightuserdata | R | `obj.btnRandomisePart` |
| descriptionPanel | (void* | lightuserdata | R | `obj.descriptionPanel` |
| descriptionPanelText | (void* | lightuserdata | R | `obj.descriptionPanelText` |
| statsPanel | (void* | lightuserdata | R | `obj.statsPanel` |
| statsDataPanel | statsDataPanel | DatapanelGUI | RW | `obj.statsDataPanel = <value>` |
| dialog | dialog | OpenSaveFileDialog | RW | `obj.dialog = <value>` |
| isMidGame | isMidGame | boolean | RW | `obj.isMidGame = <value>` |
| multipleCharactersChangedCheck | multipleCharactersChangedCheck | integer | RW | `obj.multipleCharactersChangedCheck = <value>` |
| characterEntityUpdated | characterEntityUpdated | boolean | RW | `obj.characterEntityUpdated = <value>` |
| clothVisible | clothVisible | boolean | RW | `obj.clothVisible = <value>` |
| appearanceData | appearanceData | GameDataCopyStandalone | RW | `obj.appearanceData = <value>` |
| raceData | raceData | GameData | RW | `obj.raceData = <value>` |
| currentCategory | (lua_Integer | integer | RW | `obj.currentCategory = <value>` |
| currentRaceGroupIndex | currentRaceGroupIndex | integer | RW | `obj.currentRaceGroupIndex = <value>` |
| currentSubRaceIndex | currentSubRaceIndex | integer | RW | `obj.currentSubRaceIndex = <value>` |
| currentGender | (lua_Integer | integer | RW | `obj.currentGender = <value>` |
| currentRaceData | (void* | lightuserdata | R | `obj.currentRaceData` |
| currentEditData | (void* | lightuserdata | R | `obj.currentEditData` |
| character | character | Character | RW | `obj.character = <value>` |
| currentCharacterIdx | currentCharacterIdx | integer | RW | `obj.currentCharacterIdx = <value>` |
| currentAnimation | (void* | lightuserdata | R | `obj.currentAnimation` |
| raceLimits | (void* | lightuserdata | R | `obj.raceLimits` |
| showNamesOption | showNamesOption | boolean | RW | `obj.showNamesOption = <value>` |
| editorRootNode | (void* | lightuserdata | R | `obj.editorRootNode` |
| characterPositionNode | (void* | lightuserdata | R | `obj.characterPositionNode` |
| characterRotationNode | (void* | lightuserdata | R | `obj.characterRotationNode` |
| workspace | (void* | lightuserdata | R | `obj.workspace` |
| platform | (void* | lightuserdata | R | `obj.platform` |
| requestUpdateLiveObject | requestUpdateLiveObject | boolean | RW | `obj.requestUpdateLiveObject = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| loadData | loadData | `` | `void` | `obj:loadData()` |
| initCharacters | initCharacters | `` | `void` | `obj:initCharacters()` |
| updateRace | updateRace | `` | `void` | `obj:updateRace()` |
| updateCharacterPoses | updateCharacterPoses | `` | `void` | `obj:updateCharacterPoses()` |
| clearCharacterPoses | clearCharacterPoses | `` | `void` | `obj:clearCharacterPoses()` |
| updateCharacter | updateCharacter | `` | `void` | `obj:updateCharacter()` |
| showCharacter | showCharacter | `on: boolean` | `void` | `obj:showCharacter(on)` |
| updateCurrentCategory | updateCurrentCategory | `` | `void` | `obj:updateCurrentCategory()` |
| loadImportedCharacter | loadImportedCharacter | `accept: boolean, result: string` | `void` | `obj:loadImportedCharacter(accept, result)` |
| setClothesVisible | setClothesVisible | `visible: boolean` | `void` | `obj:setClothesVisible(visible)` |
| confirmMessageCallback | confirmMessageCallback | `_btn: integer` | `void` | `obj:confirmMessageCallback(_btn)` |
| setupUI | setupUI | `` | `void` | `obj:setupUI()` |
| setUIEnabled | setUIEnabled | `enabled: boolean` | `void` | `obj:setUIEnabled(enabled)` |
| refreshUI | refreshUI | `` | `void` | `obj:refreshUI()` |
| updateLiveObject | updateLiveObject | `` | `void` | `obj:updateLiveObject()` |
| refreshCharacterPoses | refreshCharacterPoses | `` | `void` | `obj:refreshCharacterPoses()` |
| exportMeshes | exportMeshes | `` | `void` | `obj:exportMeshes()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `CharacterHuman` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isHuman | isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| _NV_isHuman | _NV_isHuman | `` | `CharacterHuman` | `obj:_NV_isHuman()` |
| drawWeapon | drawWeapon | `lastSection: string` | `boolean` | `obj:drawWeapon(lastSection)` |
| _NV_drawWeapon | _NV_drawWeapon | `lastSection: string` | `boolean` | `obj:_NV_drawWeapon(lastSection)` |
| sheatheWeapon | sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| getCurrentWeapon | getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| _NV_getCurrentWeapon | _NV_getCurrentWeapon | `` | `Weapon` | `obj:_NV_getCurrentWeapon()` |
| getThePreferredWeapon | getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| _NV_getThePreferredWeapon | _NV_getThePreferredWeapon | `` | `Weapon` | `obj:_NV_getThePreferredWeapon()` |
| getRangedWeapon | getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| _NV_getRangedWeapon | _NV_getRangedWeapon | `` | `Crossbow` | `obj:_NV_getRangedWeapon()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| giveBirth | giveBirth | `_pos: Vector3, _rot: Quaternion` | `boolean` | `obj:giveBirth(_pos, _rot)` |
| _NV_giveBirth | _NV_giveBirth | `_pos: Vector3, _rot: Quaternion` | `boolean` | `obj:_NV_giveBirth(_pos, _rot)` |
| setupInventorySections | setupInventorySections | `` | `boolean` | `obj:setupInventorySections()` |
| _NV_setupInventorySections | _NV_setupInventorySections | `` | `boolean` | `obj:_NV_setupInventorySections()` |
| validateInventorySections | validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| _NV_validateInventorySections | _NV_validateInventorySections | `` | `void` | `obj:_NV_validateInventorySections()` |
| setupAudio | setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| shaveHead | shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isHeadShaven | isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| _NV_isHeadShaven | _NV_isHeadShaven | `` | `boolean` | `obj:_NV_isHeadShaven()` |
| createAnimationClass | createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| _NV_createAnimationClass | _NV_createAnimationClass | `` | `void` | `obj:_NV_createAnimationClass()` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| dropWeaponInHands | dropWeaponInHands | `` | `void` | `obj:dropWeaponInHands()` |
| dropWeaponInHandsFake | dropWeaponInHandsFake | `` | `void` | `obj:dropWeaponInHandsFake()` |
| unequipItem | unequipItem | `section: string` | `void` | `obj:unequipItem(section)` |
| _NV_unequipItem | _NV_unequipItem | `section: string` | `void` | `obj:_NV_unequipItem(section)` |
| weatherUpdate | weatherUpdate | `time: number` | `void` | `obj:weatherUpdate(time)` |
| _NV_weatherUpdate | _NV_weatherUpdate | `time: number` | `void` | `obj:_NV_weatherUpdate(time)` |
| leaveSheathEquipped | leaveSheathEquipped | `section: string, ypos: integer` | `void` | `obj:leaveSheathEquipped(section, ypos)` |
| postRagdollCallback | postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| _NV_postRagdollCallback | _NV_postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:_NV_postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| _NV_reCalculateNaturalWeapon | _NV_reCalculateNaturalWeapon | `` | `void` | `obj:_NV_reCalculateNaturalWeapon()` |

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
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| attackSlots | attackSlots | CombatClass::AttackSlotManager | RW | `obj.attackSlots = <value>` |
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
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| ai | (void* | lightuserdata | R | `obj.ai` |
| animation | (void* | lightuserdata | R | `obj.animation` |
| me | me | Character | RW | `obj.me = <value>` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |
| medical | medical | MedicalSystem | RW | `obj.medical = <value>` |
| myRadiusX | myRadiusX | number | RW | `obj.myRadiusX = <value>` |
| blockingTarget | blockingTarget | Character | RW | `obj.blockingTarget = <value>` |
| blockingTargetH | blockingTargetH | unknown | RW | `obj.blockingTargetH = <value>` |
| targetsInAttackZone | targetsInAttackZone | lektor<hand> | R | `obj.targetsInAttackZone` |
| attackersH | attackersH | lektor<hand> | RW | `obj.attackersH = <value>` |
| threats | threats | lektor<Character*> | RW | `obj.threats = <value>` |
| threatsH | threatsH | lektor<hand> | RW | `obj.threatsH = <value>` |
| notifiedThreats | notifiedThreats | lektor<hand> | RW | `obj.notifiedThreats = <value>` |
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
| currentTargetHandle | currentTargetHandle | unknown | RW | `obj.currentTargetHandle = <value>` |
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
| isAttacking | isAttacking | `` | `number` | `obj:isAttacking()` |
| informOfFreeAttackSlot | informOfFreeAttackSlot | `` | `void` | `obj:informOfFreeAttackSlot()` |
| _NV_informOfFreeAttackSlot | _NV_informOfFreeAttackSlot | `` | `void` | `obj:_NV_informOfFreeAttackSlot()` |
| isStationary | isStationary | `` | `boolean` | `obj:isStationary()` |
| _getAttackTarget | _getAttackTarget | `` | `void` | `obj:_getAttackTarget()` |
| isFightingAnAllyOfMine | isFightingAnAllyOfMine | `` | `boolean` | `obj:isFightingAnAllyOfMine()` |
| getCurrentTechnique | getCurrentTechnique | `` | `CombatTechniqueData` | `obj:getCurrentTechnique()` |
| getCurrentTechniqueSection | getCurrentTechniqueSection | `` | `integer` | `obj:getCurrentTechniqueSection()` |
| getMeiMin | getMeiMin | `` | `number` | `obj:getMeiMin()` |
| areYouFightingAndInNeedOfHelp | areYouFightingAndInNeedOfHelp | `` | `number` | `obj:areYouFightingAndInNeedOfHelp()` |
| getNumOpponents | getNumOpponents | `` | `integer` | `obj:getNumOpponents()` |
| getTotalRelativeStrengthOfAttackers | getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _isInCombatMode | _isInCombatMode | `` | `boolean` | `obj:_isInCombatMode()` |
| checkForBadHandles | checkForBadHandles | `` | `void` | `obj:checkForBadHandles()` |
| addAttackerH | addAttackerH | `` | `boolean` | `obj:addAttackerH()` |
| isInAttackerListH | isInAttackerListH | `` | `boolean` | `obj:isInAttackerListH()` |
| removeAttackerH | removeAttackerH | `` | `boolean` | `obj:removeAttackerH()` |
| getAttackAimAdjustmentThreshold | getAttackAimAdjustmentThreshold | `` | `number` | `obj:getAttackAimAdjustmentThreshold()` |
| getNumWaitingAttackers | getNumWaitingAttackers | `` | `integer` | `obj:getNumWaitingAttackers()` |
| readyToFinishCombatMode | readyToFinishCombatMode | `` | `boolean` | `obj:readyToFinishCombatMode()` |
| getTimeSinceLastCombatModeInHours | getTimeSinceLastCombatModeInHours | `` | `number` | `obj:getTimeSinceLastCombatModeInHours()` |
| hasFocusedTarget | hasFocusedTarget | `` | `void` | `obj:hasFocusedTarget()` |
| _NV_hasFocusedTarget | _NV_hasFocusedTarget | `` | `void` | `obj:_NV_hasFocusedTarget()` |
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
| isInAttackZone | isInAttackZone | `` | `boolean` | `obj:isInAttackZone()` |
| getNearestEnemyInAttackZone | getNearestEnemyInAttackZone | `` | `Character` | `obj:getNearestEnemyInAttackZone()` |
| notifyBlockNeeded | notifyBlockNeeded | `` | `void` | `obj:notifyBlockNeeded()` |
| weaponReach | weaponReach | `` | `number` | `obj:weaponReach()` |
| gotMoreImportantThingsToDoThanFightingYou | gotMoreImportantThingsToDoThanFightingYou | `` | `boolean` | `obj:gotMoreImportantThingsToDoThanFightingYou()` |
| _NV_gotMoreImportantThingsToDoThanFightingYou | _NV_gotMoreImportantThingsToDoThanFightingYou | `` | `boolean` | `obj:_NV_gotMoreImportantThingsToDoThanFightingYou()` |
| setAttackTarget | setAttackTarget | `` | `void` | `obj:setAttackTarget()` |
| setAttackTargetHandle | setAttackTargetHandle | `` | `void` | `obj:setAttackTargetHandle()` |
| lookatTarget | lookatTarget | `` | `void` | `obj:lookatTarget()` |
| packPtrsToHandles | packPtrsToHandles | `` | `void` | `obj:packPtrsToHandles()` |
| _NV_packPtrsToHandles | _NV_packPtrsToHandles | `` | `void` | `obj:_NV_packPtrsToHandles()` |
| unpackHandlesToPtrs | unpackHandlesToPtrs | `` | `void` | `obj:unpackHandlesToPtrs()` |
| _NV_unpackHandlesToPtrs | _NV_unpackHandlesToPtrs | `` | `void` | `obj:_NV_unpackHandlesToPtrs()` |

## CombatMovementController
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| chaseMode | chaseMode | boolean | RW | `obj.chaseMode = <value>` |
| chaseStateTimer | chaseStateTimer | number | RW | `obj.chaseStateTimer = <value>` |
| hasForcedWP | hasForcedWP | boolean | RW | `obj.hasForcedWP = <value>` |
| forcedWP | forcedWP | Vector3 | RW | `obj.forcedWP = <value>` |
| flockFilterX | flockFilterX | MotionFilter | RW | `obj.flockFilterX = <value>` |
| flockFilterZ | flockFilterZ | MotionFilter | RW | `obj.flockFilterZ = <value>` |
| flockingControl | flockingControl | FlockingTools | RW | `obj.flockingControl = <value>` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |
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
| lookAtCharacter | lookAtCharacter | unknown | RW | `obj.lookAtCharacter = <value>` |
| combatTarget | combatTarget | unknown | RW | `obj.combatTarget = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `CombatMovementController` | `obj:_CONSTRUCTOR()` |
| collisionUpdate | collisionUpdate | `time: number` | `void` | `obj:collisionUpdate(time)` |
| chasingModeCheck | chasingModeCheck | `` | `boolean` | `obj:chasingModeCheck()` |
| create | create | `strafe: boolean` | `void` | `obj:create(strafe)` |
| areTherePeopleInMyWay | areTherePeopleInMyWay | `` | `boolean` | `obj:areTherePeopleInMyWay()` |
| addACharacterObstruction | addACharacterObstruction | `` | `void` | `obj:addACharacterObstruction()` |
| setupCombatMovementVariables | setupCombatMovementVariables | `` | `void` | `obj:setupCombatMovementVariables()` |
| combatMovementUpdate | combatMovementUpdate | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: integer, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| combatMovementUpdate_crippleMode | combatMovementUpdate_crippleMode | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: integer, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate_crippleMode(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| getUrgentVelocities | getUrgentVelocities | `pos: Vector3, facingDir: Vector3` | `Vector3` | `obj:getUrgentVelocities(pos, facingDir)` |
| checkWeDontCollideWithCharacters | checkWeDontCollideWithCharacters | `pos: Vector3, newpos: Vector3` | `void` | `obj:checkWeDontCollideWithCharacters(pos, newpos)` |
| checkCharacterCollision | checkCharacterCollision | `pos: Vector3, movement: Vector3` | `boolean` | `obj:checkCharacterCollision(pos, movement)` |
| setForcedWP | setForcedWP | `v: Vector3` | `void` | `obj:setForcedWP(v)` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
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
| callbackOwner | callbackOwner | RootObject | RW | `obj.callbackOwner = <value>` |
| athleticsMult | athleticsMult | number | RW | `obj.athleticsMult = <value>` |
| weightMult | weightMult | number | RW | `obj.weightMult = <value>` |
| combatSpeedMult | combatSpeedMult | number | RW | `obj.combatSpeedMult = <value>` |
| combatSkillBonus | combatSkillBonus | integer | RW | `obj.combatSkillBonus = <value>` |
| stealthMult | stealthMult | number | RW | `obj.stealthMult = <value>` |
| inventory | inventory | Inventory | RW | `obj.inventory = <value>` |
| racesExclude | racesExclude | ogre_unordered_set<GameData*>::type | RW | `obj.racesExclude = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| canEquip | canEquip | `` | `boolean` | `obj:canEquip()` |
| _NV_canEquip | _NV_canEquip | `` | `boolean` | `obj:_NV_canEquip()` |
| equipItem | equipItem | `what: string` | `void` | `obj:equipItem(what)` |
| _NV_equipItem | _NV_equipItem | `what: string` | `void` | `obj:_NV_equipItem(what)` |
| unequipItem | unequipItem | `what: string` | `void` | `obj:unequipItem(what)` |
| _NV_unequipItem | _NV_unequipItem | `what: string` | `void` | `obj:_NV_unequipItem(what)` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| takeMoney | takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| doubleCheckHandle | doubleCheckHandle | `` | `void` | `obj:doubleCheckHandle()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| createInventoryLayout | createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| _serialise | _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| setProperOwner | setProperOwner | `` | `void` | `obj:setProperOwner()` |
| _NV_setProperOwner | _NV_setProperOwner | `` | `void` | `obj:_NV_setProperOwner()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ContainerItem` | `obj:_CONSTRUCTOR()` |

## ContextMenu
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| rightMouseActivated | rightMouseActivated | boolean | RW | `obj.rightMouseActivated = <value>` |
| orders | orders | unknown | RW | `obj.orders = <value>` |
| contextMenuName | contextMenuName | string | RW | `obj.contextMenuName = <value>` |
| menuGUI | (void* | lightuserdata | RW | `obj.menuGUI = <value>` |
| menuGUI2 | (void* | lightuserdata | RW | `obj.menuGUI2 = <value>` |
| delayedDestroyFlag | delayedDestroyFlag | boolean | RW | `obj.delayedDestroyFlag = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ContextMenu` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| showContextMenu | showContextMenu | `on: boolean` | `void` | `obj:showContextMenu(on)` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| update | update | `` | `void` | `obj:update()` |
| _destroyMenuGUICheck | _destroyMenuGUICheck | `` | `void` | `obj:_destroyMenuGUICheck()` |

## ContextMenuGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ContextMenu.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| contextMenuTarget | contextMenuTarget | unknown | RW | `obj.contextMenuTarget = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| nameText | (void* | lightuserdata | R | `obj.nameText` |
| optionsList | (void* | lightuserdata | R | `obj.optionsList` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getMainWidget | getMainWidget | `` | `lightuserdata` | `obj:getMainWidget()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |

## CraftingBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| maxCraftLevel | maxCraftLevel | integer | RW | `obj.maxCraftLevel = <value>` |
| crafting | crafting | std::deque<CraftingItem, std::allocator<CraftingItem> > | R | `obj.crafting` |
| specialCraftItemType | (lua_Integer | integer | RW | `obj.specialCraftItemType = <value>` |
| repeat | repeat | boolean | RW | `obj.repeat = <value>` |
| whosCrafting | whosCrafting | unknown | RW | `obj.whosCrafting = <value>` |
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
| container | container | RootObjectContainer | RW | `obj.container = <value>` |
| homeBuilding | homeBuilding | Building | RW | `obj.homeBuilding = <value>` |
| faction | faction | Faction | RW | `obj.faction = <value>` |
| data | data | GameData | RW | `obj.data = <value>` |
| position | position | Vector3 | RW | `obj.position = <value>` |
| isFromActiveLevelMod | isFromActiveLevelMod | boolean | RW | `obj.isFromActiveLevelMod = <value>` |
| rotation | rotation | Quaternion | RW | `obj.rotation = <value>` |
| callbackObject | callbackObject | FactoryCallbackInterface | RW | `obj.callbackObject = <value>` |
| saveState | saveState | GameSaveState | RW | `obj.saveState = <value>` |
| age | age | number | RW | `obj.age = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `_position: Vector3, _isFromActiveLevelMod: boolean, _rotation: Quaternion, _age: number` | `CreatelistItem` | `obj:_CONSTRUCTOR(_position, _isFromActiveLevelMod, _rotation, _age)` |

## Crossbow
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| gunClass | (void* | lightuserdata | R | `obj.gunClass` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `_overalllevel: integer` | `Crossbow` | `obj:_CONSTRUCTOR(_overalllevel)` |
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
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `blunt: number, pierce: number, bleed: number, armour: number` | `Damages` | `obj:_CONSTRUCTOR(blunt, pierce, bleed, armour)` |
| multiply | multiply | `mult: number` | `void` | `obj:multiply(mult)` |
| total | total | `` | `number` | `obj:total()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isStored | isStored | boolean | RW | `obj.isStored = <value>` |
| objectDatas | objectDatas | GameDataContainer | RW | `obj.objectDatas = <value>` |
| datasFile | datasFile | string | RW | `obj.datasFile = <value>` |
| selfType | (lua_Integer | integer | RW | `obj.selfType = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getType | getType | `` | `integer` | `obj:getType()` |
| setupDataFile | setupDataFile | `filename: string` | `void` | `obj:setupDataFile(filename)` |
| destroyObjectDatas | destroyObjectDatas | `` | `void` | `obj:destroyObjectDatas()` |

## DataPanelLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| w1 | (void* | lightuserdata | R | `obj.w1` |
| w2 | (void* | lightuserdata | R | `obj.w2` |
| category | category | integer | RW | `obj.category = <value>` |
| keyValue | keyValue | string | RW | `obj.keyValue = <value>` |
| s1 | s1 | string | RW | `obj.s1 = <value>` |
| s2 | s2 | string | RW | `obj.s2 = <value>` |
| lo | lo | integer | RW | `obj.lo = <value>` |
| hi | hi | integer | RW | `obj.hi = <value>` |
| skinW1 | skinW1 | string | RW | `obj.skinW1 = <value>` |
| skinW2 | skinW2 | string | RW | `obj.skinW2 = <value>` |
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
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| resize | resize | `width: integer, height: integer` | `void` | `obj:resize(width, height)` |
| _NV_resize | _NV_resize | `width: integer, height: integer` | `void` | `obj:_NV_resize(width, height)` |
| getBottom | getBottom | `` | `integer` | `obj:getBottom()` |
| _NV_getBottom | _NV_getBottom | `` | `integer` | `obj:_NV_getBottom()` |
| getType | getType | `` | `integer` | `obj:getType()` |
| getUserData | getUserData | `` | `void` | `obj:getUserData()` |
| _NV_getUserData | _NV_getUserData | `` | `void` | `obj:_NV_getUserData()` |
| getNumWidgets | getNumWidgets | `` | `integer` | `obj:getNumWidgets()` |
| getWidget | getWidget | `index: integer` | `lightuserdata` | `obj:getWidget(index)` |

## DataPanelLine_Button
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| userData | userData | unknown | RW | `obj.userData = <value>` |
| button | (void* | lightuserdata | RW | `obj.button = <value>` |
| buttonWidth | buttonWidth | number | RW | `obj.buttonWidth = <value>` |
| buttonHeight | buttonHeight | number | RW | `obj.buttonHeight = <value>` |
| buttonSkin | buttonSkin | string | RW | `obj.buttonSkin = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `a: string, b: string, cat: integer, w: number, skin: string` | `DataPanelLine_Button` | `obj:_CONSTRUCTOR(a, b, cat, w, skin)` |
| getUserData | getUserData | `` | `void` | `obj:getUserData()` |
| _NV_getUserData | _NV_getUserData | `` | `void` | `obj:_NV_getUserData()` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
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
| setValuePtr | setValuePtr | `bVal: boolean` | `void` | `obj:setValuePtr(bVal)` |
| getTextBox | getTextBox | `` | `MyGUI::Widget` | `obj:getTextBox()` |
| getCheckBox | getCheckBox | `` | `MyGUI::Widget` | `obj:getCheckBox()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `key: string, cat: integer, bVal: boolean` | `DataPanelLine_CheckBox` | `obj:_CONSTRUCTOR(key, cat, bVal)` |
| createMe | createMe | `topReal: number, lastLine: boolean` | `void` | `obj:createMe(topReal, lastLine)` |
| _NV_createMe | _NV_createMe | `topReal: number, lastLine: boolean` | `void` | `obj:_NV_createMe(topReal, lastLine)` |
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
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `text: string, category: integer, valInt: integer, width: number, hasGobox: boolean` | `DataPanelLine_DropBox` | `obj:_CONSTRUCTOR(text, category, valInt, width, hasGobox)` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `a: string, b: string, cat: integer, vv1: number, vv2: number` | `DataPanelLine_Faction` | `obj:_CONSTRUCTOR(a, b, cat, vv1, vv2)` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `cmd: string, text: string, cat: integer` | `DataPanelLine_KeyConfig` | `obj:_CONSTRUCTOR(cmd, text, cat)` |
| oldKey | oldKey | `` | `integer` | `obj:oldKey()` |
| setKey | setKey | `s: string` | `void` | `obj:setKey(s)` |
| eraseKey | eraseKey | `key: string` | `void` | `obj:eraseKey(key)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| cancel | cancel | `` | `void` | `obj:cancel()` |
| createMe | createMe | `vpos: number, lastLine: boolean` | `void` | `obj:createMe(vpos, lastLine)` |
| _NV_createMe | _NV_createMe | `vpos: number, lastLine: boolean` | `void` | `obj:_NV_createMe(vpos, lastLine)` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `key: string, category: integer, showKey: boolean` | `DataPanelLine_Progress` | `obj:_CONSTRUCTOR(key, category, showKey)` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
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
| bar | (void* | lightuserdata | RW | `obj.bar = <value>` |
| but | (void* | lightuserdata | R | `obj.but` |
| Xbut | (void* | lightuserdata | R | `obj.Xbut` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `a: string, b: string, cat: integer, vv1: number, _barColor: string, _Xbut: boolean` | `DataPanelLine_Research` | `obj:_CONSTRUCTOR(a, b, cat, vv1, _barColor, _Xbut)` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `key: string, text: string, min: number, max: number, category: integer, scale: number` | `DataPanelLine_Slider` | `obj:_CONSTRUCTOR(key, text, min, max, category, scale)` |
| setValue | setValue | `value: number` | `void` | `obj:setValue(value)` |
| getValue | getValue | `` | `number` | `obj:getValue()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
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
| setEditableValuePtr | setEditableValuePtr | `tempVal: number, lo: number, hi: number` | `void` | `obj:setEditableValuePtr(tempVal, lo, hi)` |
| getSlider | getSlider | `` | `MyGUI::Widget` | `obj:getSlider()` |
| getEditBox | getEditBox | `` | `MyGUI::Widget` | `obj:getEditBox()` |
| setValue | setValue | `v: number` | `void` | `obj:setValue(v)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| setPrecision | setPrecision | `dp: integer` | `void` | `obj:setPrecision(dp)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `text: string, category: integer, showName: boolean, min: number, max: number, tempVal: number` | `DataPanelLine_SliderEditable` | `obj:_CONSTRUCTOR(text, category, showName, min, max, tempVal)` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Text
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| editBox | (void* | lightuserdata | R | `obj.editBox` |
| wordWrap | wordWrap | boolean | RW | `obj.wordWrap = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_TextEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| editBox | (void* | lightuserdata | R | `obj.editBox` |
| nameText | (void* | lightuserdata | R | `obj.nameText` |
| showKey | showKey | boolean | RW | `obj.showKey = <value>` |
| multiLine | multiLine | boolean | RW | `obj.multiLine = <value>` |
| width | width | number | RW | `obj.width = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getEditBox | getEditBox | `` | `lightuserdata` | `obj:getEditBox()` |
| getNameBox | getNameBox | `` | `lightuserdata` | `obj:getNameBox()` |
| createMe | createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DatapanelGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/DatapanelGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| frequentUpdatesWanted | frequentUpdatesWanted | boolean | RW | `obj.frequentUpdatesWanted = <value>` |
| scrollWin | (void* | lightuserdata | R | `obj.scrollWin` |
| premadeParentWindow | premadeParentWindow | boolean | RW | `obj.premadeParentWindow = <value>` |
| scrolling | scrolling | boolean | RW | `obj.scrolling = <value>` |
| isWindow | isWindow | boolean | RW | `obj.isWindow = <value>` |
| currentCategory | currentCategory | integer | RW | `obj.currentCategory = <value>` |
| mouseOverEvent | (void* | lightuserdata | R | `obj.mouseOverEvent` |
| mouseOverEventDatas | (void* | lightuserdata | R | `obj.mouseOverEventDatas` |
| automaticRefresh | automaticRefresh | boolean | RW | `obj.automaticRefresh = <value>` |
| automaticTarget | automaticTarget | boolean | RW | `obj.automaticTarget = <value>` |
| tabWin | (void* | lightuserdata | R | `obj.tabWin` |
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
| setLineFaction | setLineFaction | `s1: string, s2: string, category: integer, v1: number, v2: number` | `DataPanelLine_Faction` | `obj:setLineFaction(s1, s2, category, v1, v2)` |
| setLineTextButton | setLineTextButton | `text: string, caption: string, category: integer, buttonWidth: number, skin: string` | `DataPanelLine_Button` | `obj:setLineTextButton(text, caption, category, buttonWidth, skin)` |
| setLineButton | setLineButton | `key: string, caption: string, category: integer` | `DataPanelLine_Button` | `obj:setLineButton(key, caption, category)` |
| setLineToggleButton | setLineToggleButton | `key: string, caption: string, category: integer` | `DataPanelLine_Button` | `obj:setLineToggleButton(key, caption, category)` |
| setLineSliderEditable | setLineSliderEditable | `key: string, category: integer, showName: boolean, min: number, max: number, tempVal: number` | `DataPanelLine_SliderEditable` | `obj:setLineSliderEditable(key, category, showName, min, max, tempVal)` |
| setLineSlider | setLineSlider | `key: string, caption: string, min: number, max: number, category: integer, tempVal: number, scale: number` | `DataPanelLine_Slider` | `obj:setLineSlider(key, caption, min, max, category, tempVal, scale)` |
| setLineProgress | setLineProgress | `key: string, category: integer, progressValue: number, progressText: string, showKey: boolean` | `DataPanelLine_Progress` | `obj:setLineProgress(key, category, progressValue, progressText, showKey)` |
| removeLine | removeLine | `s1: string, category: integer` | `void` | `obj:removeLine(s1, category)` |
| setLineCheckbox | setLineCheckbox | `s1: string, tempBool: boolean, category: integer` | `DataPanelLine_CheckBox` | `obj:setLineCheckbox(s1, tempBool, category)` |
| setLineDropBox | setLineDropBox | `key: string, category: integer, tempInt: integer, goBox: boolean, width: number` | `DataPanelLine_DropBox` | `obj:setLineDropBox(key, category, tempInt, goBox, width)` |
| addSpace | addSpace | `category: integer, h: number` | `void` | `obj:addSpace(category, h)` |
| setCategoryIcon | setCategoryIcon | `cat: integer, image: string` | `void` | `obj:setCategoryIcon(cat, image)` |
| _NV_setCategoryIcon | _NV_setCategoryIcon | `cat: integer, image: string` | `void` | `obj:_NV_setCategoryIcon(cat, image)` |
| changeCategory | changeCategory | `cat: integer` | `void` | `obj:changeCategory(cat)` |
| _NV_changeCategory | _NV_changeCategory | `cat: integer` | `void` | `obj:_NV_changeCategory(cat)` |
| getCurrentCategory | getCurrentCategory | `` | `integer` | `obj:getCurrentCategory()` |
| _NV_getCurrentCategory | _NV_getCurrentCategory | `` | `integer` | `obj:_NV_getCurrentCategory()` |
| addCustomLine | addCustomLine | `` | `void` | `obj:addCustomLine()` |
| getObject | getObject | `` | `void` | `obj:getObject()` |
| _NV_getObject | _NV_getObject | `` | `void` | `obj:_NV_getObject()` |
| setLineSpacing | setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:setLineSpacing(numLinesPerScreen)` |
| _NV_setLineSpacing | _NV_setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:_NV_setLineSpacing(numLinesPerScreen)` |
| getLine | getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:getLine(key, cat)` |
| _NV_getLine | _NV_getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:_NV_getLine(key, cat)` |
| lineExists | lineExists | `key: string, cat: integer` | `boolean` | `obj:lineExists(key, cat)` |
| getContentHeight | getContentHeight | `cat: integer` | `integer` | `obj:getContentHeight(cat)` |
| getNumLines | getNumLines | `cat: integer` | `integer` | `obj:getNumLines(cat)` |
| getLineByNum | getLineByNum | `cat: integer, i: integer` | `DataPanelLine` | `obj:getLineByNum(cat, i)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createLine | createLine | `category: integer, lastLine: boolean` | `DataPanelLine` | `obj:createLine(category, lastLine)` |
| getNextVerticalPos | getNextVerticalPos | `category: integer` | `number` | `obj:getNextVerticalPos(category)` |
| dataExists | dataExists | `cat: integer, name: string` | `boolean` | `obj:dataExists(cat, name)` |
| clearCategoryTabs | clearCategoryTabs | `` | `void` | `obj:clearCategoryTabs()` |

## DelayedSpawnMsg
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| parentTown | parentTown | unknown | RW | `obj.parentTown = <value>` |
| item | item | Item | RW | `obj.item = <value>` |
| nestData | nestData | GameData | RW | `obj.nestData = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |
| insideBuilding | insideBuilding | unknown | RW | `obj.insideBuilding = <value>` |

## DialogAction
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| value | value | integer | RW | `obj.value = <value>` |
| key | (lua_Integer | integer | RW | `obj.key = <value>` |

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

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _createData | _createData | `` | `DialogLineData` | `obj:_createData()` |
| initialise | initialise | `` | `void` | `obj:initialise()` |
| save | save | `` | `void` | `obj:save()` |
| load | load | `` | `void` | `obj:load()` |
| newGameReset | newGameReset | `` | `void` | `obj:newGameReset()` |
| getData | getData | `` | `DialogLineData` | `obj:getData()` |

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
| inTownOf | *it, FactionBinding::getMetatableName( | Faction | RW | `obj.inTownOf = <value>` |
| isTargetFaction | *it, FactionBinding::getMetatableName( | Faction | RW | `obj.isTargetFaction = <value>` |
| isMyFaction | *it, FactionBinding::getMetatableName( | Faction | RW | `obj.isMyFaction = <value>` |
| isCharacter | isCharacter | lektor<GameData*> | RW | `obj.isCharacter = <value>` |
| isTargetCarryingCharacter | isTargetCarryingCharacter | lektor<GameData*> | RW | `obj.isTargetCarryingCharacter = <value>` |
| hasPackage | _hasPackage | lektor<GameData*> | RW | `obj.hasPackage = <value>` |
| isMyRace | isMyRace | lektor<GameData*> | RW | `obj.isMyRace = <value>` |
| isMySubRace | isMySubRace | lektor<GameData*> | RW | `obj.isMySubRace = <value>` |
| hasItemType | (lua_Integer | integer | RW | `obj.hasItemType = <value>` |
| hasItem | hasItem | lektor<GameData*> | RW | `obj.hasItem = <value>` |
| worldState | worldState | WorldEventStateQueryList | RW | `obj.worldState = <value>` |
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
| uniqueOwner | uniqueOwner | unknown | RW | `obj.uniqueOwner = <value>` |
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
| getParent | getParent | `` | `DialogLineData` | `obj:getParent()` |
| isForSpecificCharacter | isForSpecificCharacter | `` | `boolean` | `obj:isForSpecificCharacter()` |
| hasSpecificCharacterRequirement | hasSpecificCharacterRequirement | `` | `boolean` | `obj:hasSpecificCharacterRequirement()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `DialogLineData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupChildren | setupChildren | `` | `void` | `obj:setupChildren()` |
| checkRepeatLimits | checkRepeatLimits | `` | `boolean` | `obj:checkRepeatLimits()` |
| checkTags | checkTags | `` | `boolean` | `obj:checkTags()` |
| getName | getName | `` | `string` | `obj:getName()` |
| saidItBefore | saidItBefore | `` | `boolean` | `obj:saidItBefore()` |
| willTalkToEnemies | willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| isEmptyNode | isEmptyNode | `` | `boolean` | `obj:isEmptyNode()` |
| _NV_isEmptyNode | _NV_isEmptyNode | `` | `boolean` | `obj:_NV_isEmptyNode()` |
| isAnnouncement | isAnnouncement | `` | `boolean` | `obj:isAnnouncement()` |
| stampLastTimeSaid | stampLastTimeSaid | `` | `void` | `obj:stampLastTimeSaid()` |
| getScore | getScore | `` | `integer` | `obj:getScore()` |
| getScorePlusChildrenIfEmpty | getScorePlusChildrenIfEmpty | `` | `integer` | `obj:getScorePlusChildrenIfEmpty()` |
| hasChildren | hasChildren | `` | `boolean` | `obj:hasChildren()` |
| checkConditions | checkConditions | `isWordswap: boolean` | `boolean` | `obj:checkConditions(isWordswap)` |
| chooseAChild | chooseAChild | `isForWordswaps: boolean` | `DialogLineData` | `obj:chooseAChild(isForWordswaps)` |
| getStringID | getStringID | `` | `string` | `obj:getStringID()` |
| getGameData | getGameData | `` | `GameData` | `obj:getGameData()` |
| getChildByStringID | getChildByStringID | `sid: string` | `DialogLineData` | `obj:getChildByStringID(sid)` |
| setParent | setParent | `` | `void` | `obj:setParent()` |
| getMoneyCostForLine | getMoneyCostForLine | `` | `integer` | `obj:getMoneyCostForLine()` |
| getText | getText | `stampTime: boolean` | `string` | `obj:getText(stampTime)` |
| getPlayerReplies | getPlayerReplies | `` | `void` | `obj:getPlayerReplies()` |
| getActions | getActions | `` | `lektor<DialogLineData::DialogAction*>` | `obj:getActions()` |

## DialogState
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| count | count | integer | RW | `obj.count = <value>` |
| lastTimeStamp | lastTimeStamp | number | RW | `obj.lastTimeStamp = <value>` |
| resetTime | resetTime | number | RW | `obj.resetTime = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `DialogState` | `obj:_CONSTRUCTOR()` |

## Dialogue
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| repCounter | repCounter | Dialogue::RepetitionCounter | RW | `obj.repCounter = <value>` |
| _needsDynamicAssessments | _needsDynamicAssessments | boolean | RW | `obj._needsDynamicAssessments = <value>` |
| sayMsg | sayMsg | string | RW | `obj.sayMsg = <value>` |
| playerInterruptionDialog | playerInterruptionDialog | DialogLineData | RW | `obj.playerInterruptionDialog = <value>` |
| _hasEnded | _hasEnded | boolean | RW | `obj._hasEnded = <value>` |
| shouting | shouting | boolean | RW | `obj.shouting = <value>` |
| staysOnScreen | staysOnScreen | boolean | RW | `obj.staysOnScreen = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
| conversationTarget | conversationTarget | unknown | RW | `obj.conversationTarget = <value>` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |
| movement | movement | CharMovement | RW | `obj.movement = <value>` |
| currentConversationType | (lua_Integer | integer | RW | `obj.currentConversationType = <value>` |
| currentConversation | currentConversation | DialogLineData | RW | `obj.currentConversation = <value>` |
| currentLine | currentLine | DialogLineData | RW | `obj.currentLine = <value>` |
| interjector1 | interjector1 | unknown | RW | `obj.interjector1 = <value>` |
| interjector2 | interjector2 | unknown | RW | `obj.interjector2 = <value>` |
| interjector3 | interjector3 | unknown | RW | `obj.interjector3 = <value>` |
| speechBubblePanel | speechBubblePanel | DialogueSpeechBubble | RW | `obj.speechBubblePanel = <value>` |
| speechTextTimer | speechTextTimer | number | RW | `obj.speechTextTimer = <value>` |
| speechTextTimer_forced | speechTextTimer_forced | number | RW | `obj.speechTextTimer_forced = <value>` |
| npcReplyText | npcReplyText | string | RW | `obj.npcReplyText = <value>` |
| conversationMaster | conversationMaster | unknown | RW | `obj.conversationMaster = <value>` |
| waitingForReplyFrom | waitingForReplyFrom | unknown | RW | `obj.waitingForReplyFrom = <value>` |
| pacakgesIHave | *it, GameDataBinding::getMetatableName( | GameData | RW | `obj.pacakgesIHave = <value>` |
| locked | locked | DialogLineDataBoolMapBinding::MapType | RW | `obj.locked = <value>` |
| _hasChanceLines | _hasChanceLines | DialogLineDataBoolMapBinding::MapType | RW | `obj._hasChanceLines = <value>` |
| eventRepeatTimers | eventRepeatTimers | EventRepeatTimersMapBinding::MapType | RW | `obj.eventRepeatTimers = <value>` |
| eventDeliveredStates | eventDeliveredStates | EventDeliveredStatesMapBinding::MapType | RW | `obj.eventDeliveredStates = <value>` |
| conversationsMain | conversationsMain | ConversationsMainMapBinding::MapType | RW | `obj.conversationsMain = <value>` |
| threadMessages | (lua_Integer | integer | RW | `obj.threadMessages = <value>` |
| replyIds | replyIds | string | RW | `obj.replyIds = <value>` |
| responses | responses | string | RW | `obj.responses = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWordSwap | getWordSwap | `key: string, _a3: boolean` | `string` | `obj:getWordSwap(key, _a3)` |
| setupWordSwaps | setupWordSwaps | `` | `void` | `obj:setupWordSwaps()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Dialogue` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getGUIData | getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| create | create | `` | `void` | `obj:create()` |
| getHandle | getHandle | `` | `void` | `obj:getHandle()` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| setLineLocked | setLineLocked | `on: boolean` | `void` | `obj:setLineLocked(on)` |
| isLocked | isLocked | `` | `boolean` | `obj:isLocked()` |
| setInDialog | setInDialog | `on: boolean` | `void` | `obj:setInDialog(on)` |
| clearDialogues | clearDialogues | `` | `void` | `obj:clearDialogues()` |
| clearAnnouncements | clearAnnouncements | `` | `void` | `obj:clearAnnouncements()` |
| needsDialogAssessmentUpdate | needsDialogAssessmentUpdate | `` | `boolean` | `obj:needsDialogAssessmentUpdate()` |
| addDialoguePackage | addDialoguePackage | `` | `void` | `obj:addDialoguePackage()` |
| addConversation | addConversation | `t: integer` | `void` | `obj:addConversation(t)` |
| clearConversationList | clearConversationList | `t: integer` | `void` | `obj:clearConversationList(t)` |
| willTalkToEnemies | willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| sendEventOverride | sendEventOverride | `what: integer, forceRepeat: boolean` | `boolean` | `obj:sendEventOverride(what, forceRepeat)` |
| sendEvent | sendEvent | `what: integer` | `boolean` | `obj:sendEvent(what)` |
| stopEvent | stopEvent | `what: integer` | `void` | `obj:stopEvent(what)` |
| runCustomDialog | runCustomDialog | `` | `boolean` | `obj:runCustomDialog()` |
| scoreCustomDialog | scoreCustomDialog | `` | `integer` | `obj:scoreCustomDialog()` |
| conversationHasEnded | conversationHasEnded | `` | `boolean` | `obj:conversationHasEnded()` |
| getConversationTarget | getConversationTarget | `` | `void` | `obj:getConversationTarget()` |
| changeConversationTarget | changeConversationTarget | `` | `void` | `obj:changeConversationTarget()` |
| conversationHasEndedPrettyMuch | conversationHasEndedPrettyMuch | `` | `boolean` | `obj:conversationHasEndedPrettyMuch()` |
| makeAnnouncement | makeAnnouncement | `` | `boolean` | `obj:makeAnnouncement()` |
| update | update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| endDialogue | endDialogue | `definitelyTheEnd: boolean` | `void` | `obj:endDialogue(definitelyTheEnd)` |
| notifyUnderAttack | notifyUnderAttack | `` | `void` | `obj:notifyUnderAttack()` |
| hasDialogue_Fast | hasDialogue_Fast | `` | `boolean` | `obj:hasDialogue_Fast()` |
| hasDialogue_Accurate | hasDialogue_Accurate | `` | `boolean` | `obj:hasDialogue_Accurate()` |
| hasDialogueEvent | hasDialogueEvent | `e: integer` | `boolean` | `obj:hasDialogueEvent(e)` |
| dialogDelivered | dialogDelivered | `e: integer` | `boolean` | `obj:dialogDelivered(e)` |
| _checkCondition | _checkCondition | `conditionName: integer, compareBy: integer, val: integer` | `boolean` | `obj:_checkCondition(conditionName, compareBy, val)` |
| dontLetTargetBeMe | dontLetTargetBeMe | `` | `void` | `obj:dontLetTargetBeMe()` |
| hasThisChanceLine | hasThisChanceLine | `chance: number` | `boolean` | `obj:hasThisChanceLine(chance)` |
| _chooseDialog | _chooseDialog | `isWordswap: boolean` | `DialogLineData` | `obj:_chooseDialog(isWordswap)` |
| triggerNextLine | triggerNextLine | `` | `void` | `obj:triggerNextLine()` |
| targetInTalkingRange | targetInTalkingRange | `mult: number` | `boolean` | `obj:targetInTalkingRange(mult)` |
| save | save | `` | `void` | `obj:save()` |
| load | load | `` | `void` | `obj:load()` |
| getSpeaker | getSpeaker | `who: integer, isForWordswaps: boolean` | `Character` | `obj:getSpeaker(who, isForWordswaps)` |
| isCurrentConversationRunning | isCurrentConversationRunning | `` | `boolean` | `obj:isCurrentConversationRunning()` |
| findInterjectionCharacter | findInterjectionCharacter | `` | `Character` | `obj:findInterjectionCharacter()` |
| isKOExempt | isKOExempt | `what: integer` | `boolean` | `obj:isKOExempt(what)` |
| _endPlayerConversation | _endPlayerConversation | `finished: boolean` | `void` | `obj:_endPlayerConversation(finished)` |
| startPlayerConversation | startPlayerConversation | `` | `boolean` | `obj:startPlayerConversation()` |
| startConversation | startConversation | `ev: integer, force: boolean` | `boolean` | `obj:startConversation(ev, force)` |
| getConversationList | getConversationList | `t: integer` | `DialogChoiceList` | `obj:getConversationList(t)` |
| _doActions | _doActions | `` | `void` | `obj:_doActions()` |
| sayLine | sayLine | `` | `boolean` | `obj:sayLine()` |
| listPlayerReplies | listPlayerReplies | `` | `void` | `obj:listPlayerReplies()` |
| isLastLine | isLastLine | `` | `boolean` | `obj:isLastLine()` |
| setSpeaker | setSpeaker | `who: integer` | `void` | `obj:setSpeaker(who)` |
| _updateTextPos | _updateTextPos | `` | `void` | `obj:_updateTextPos()` |
| clearSpeechBox | clearSpeechBox | `` | `void` | `obj:clearSpeechBox()` |
| clearRespones | clearRespones | `` | `void` | `obj:clearRespones()` |
| clearResponesGUI | clearResponesGUI | `` | `void` | `obj:clearResponesGUI()` |
| setResponesGUI | setResponesGUI | `` | `void` | `obj:setResponesGUI()` |
| setConversationReplyGUI | setConversationReplyGUI | `` | `void` | `obj:setConversationReplyGUI()` |
| say | say | `text: string` | `void` | `obj:say(text)` |
| replyClicked | replyClicked | `index: string` | `void` | `obj:replyClicked(index)` |
| isAtTownOf | isAtTownOf | `` | `boolean` | `obj:isAtTownOf()` |
| resolveOverlappedSpeechBubbles | resolveOverlappedSpeechBubbles | `` | `void` | `obj:resolveOverlappedSpeechBubbles()` |

## DialogueSpeechBubble
**Header:** `extern/KenshiLib/Include/kenshi/dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| stayOnScreen | stayOnScreen | boolean | RW | `obj.stayOnScreen = <value>` |
| shout | shout | boolean | RW | `obj.shout = <value>` |
| marginW | marginW | integer | RW | `obj.marginW = <value>` |
| marginH | marginH | integer | RW | `obj.marginH = <value>` |
| textBox | (void* | lightuserdata | RW | `obj.textBox = <value>` |
| baseSize | baseSize | integer | RW | `obj.baseSize = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `shout: boolean, importnt: boolean` | `DialogueSpeechBubble` | `obj:_CONSTRUCTOR(shout, importnt)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setText | setText | `text: string` | `void` | `obj:setText(text)` |
| setAlpha | setAlpha | `value: number` | `void` | `obj:setAlpha(value)` |
| setPosition | setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| reset | reset | `` | `void` | `obj:reset()` |
| getAlpha | getAlpha | `` | `number` | `obj:getAlpha()` |
| getRect | getRect | `` | `integer` | `obj:getRect()` |

## DialogueWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/DialogueWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| dialogue | dialogue | Dialogue | RW | `obj.dialogue = <value>` |
| conversationPanelsMargin | conversationPanelsMargin | integer | RW | `obj.conversationPanelsMargin = <value>` |
| converstaionPCPanelBottom | converstaionPCPanelBottom | integer | RW | `obj.converstaionPCPanelBottom = <value>` |
| conversationPCSpeechPanelMinHeight | conversationPCSpeechPanelMinHeight | integer | RW | `obj.conversationPCSpeechPanelMinHeight = <value>` |
| conversationNPCSpeechPanelMinHeight | conversationNPCSpeechPanelMinHeight | integer | RW | `obj.conversationNPCSpeechPanelMinHeight = <value>` |
| conversationPCPanelHeightDiffSpeechPanel | conversationPCPanelHeightDiffSpeechPanel | integer | RW | `obj.conversationPCPanelHeightDiffSpeechPanel = <value>` |
| conversationNPCPanelHeightDiffSpeechPanel | conversationNPCPanelHeightDiffSpeechPanel | integer | RW | `obj.conversationNPCPanelHeightDiffSpeechPanel = <value>` |
| conversationPC | conversationPC | Character | RW | `obj.conversationPC = <value>` |
| conversationPCPanel | (void* | lightuserdata | RW | `obj.conversationPCPanel = <value>` |
| conversationNPCPanel | (void* | lightuserdata | RW | `obj.conversationNPCPanel = <value>` |
| conversationNPCNameText | (void* | lightuserdata | R | `obj.conversationNPCNameText` |
| conversationPCNameText | (void* | lightuserdata | R | `obj.conversationPCNameText` |
| conversationPCMoneyText | (void* | lightuserdata | R | `obj.conversationPCMoneyText` |
| conversationNPCSpeech | (void* | lightuserdata | RW | `obj.conversationNPCSpeech = <value>` |
| conversationPCSpeechPanel | (void* | lightuserdata | RW | `obj.conversationPCSpeechPanel = <value>` |
| conversationNPCPortrait | (void* | lightuserdata | R | `obj.conversationNPCPortrait` |
| conversationPCPortrait | (void* | lightuserdata | R | `obj.conversationPCPortrait` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_show | _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| hide | hide | `` | `void` | `obj:hide()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| getTop | getTop | `` | `integer` | `obj:getTop()` |
| activateResponse | activateResponse | `index: integer` | `void` | `obj:activateResponse(index)` |
| setNPCText | setNPCText | `text: string` | `void` | `obj:setNPCText(text)` |
| clearResponses | clearResponses | `` | `void` | `obj:clearResponses()` |
| changePortrait | changePortrait | `player: boolean` | `void` | `obj:changePortrait(player)` |
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

## EntData
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | RW | `obj.data = <value>` |
| maxSlope | maxSlope | number | RW | `obj.maxSlope = <value>` |
| minSlope | minSlope | number | RW | `obj.minSlope = <value>` |
| chance | chance | number | RW | `obj.chance = <value>` |
| minAltitude | minAltitude | number | RW | `obj.minAltitude = <value>` |
| maxAltitude | maxAltitude | number | RW | `obj.maxAltitude = <value>` |
| slopeAlign | slopeAlign | boolean | RW | `obj.slopeAlign = <value>` |
| floating | floating | boolean | RW | `obj.floating = <value>` |
| uniformScale | uniformScale | boolean | RW | `obj.uniformScale = <value>` |
| accurateTrace | accurateTrace | boolean | RW | `obj.accurateTrace = <value>` |
| upright | upright | boolean | RW | `obj.upright = <value>` |
| minV | minV | number | RW | `obj.minV = <value>` |
| maxV | maxV | number | RW | `obj.maxV = <value>` |
| clustered | clustered | boolean | RW | `obj.clustered = <value>` |
| limitToGrassAreas | limitToGrassAreas | boolean | RW | `obj.limitToGrassAreas = <value>` |
| nonBatched | nonBatched | boolean | RW | `obj.nonBatched = <value>` |
| carveRadius | carveRadius | number | RW | `obj.carveRadius = <value>` |
| grassSpot | grassSpot | number | RW | `obj.grassSpot = <value>` |
| roadRadius | roadRadius | number | RW | `obj.roadRadius = <value>` |
| clusterMin | clusterMin | number | RW | `obj.clusterMin = <value>` |
| clusterMax | clusterMax | number | RW | `obj.clusterMax = <value>` |
| clusterRadiusMin | clusterRadiusMin | number | RW | `obj.clusterRadiusMin = <value>` |
| clusterRadiusMax | clusterRadiusMax | number | RW | `obj.clusterRadiusMax = <value>` |
| viewDistance | viewDistance | number | RW | `obj.viewDistance = <value>` |
| seedOffset | seedOffset | integer | RW | `obj.seedOffset = <value>` |
| biomeSeparation | biomeSeparation | boolean | RW | `obj.biomeSeparation = <value>` |
| childClusterRadius | childClusterRadius | number | RW | `obj.childClusterRadius = <value>` |
| xmlFilename | xmlFilename | string | RW | `obj.xmlFilename = <value>` |
| entity1 | (void* | lightuserdata | RW | `obj.entity1 = <value>` |
| entity2 | (void* | lightuserdata | RW | `obj.entity2 = <value>` |
| entity1Loaded | entity1Loaded | boolean | RW | `obj.entity1Loaded = <value>` |
| entity2Loaded | entity2Loaded | boolean | RW | `obj.entity2Loaded = <value>` |
| position | position | Vector3 | RW | `obj.position = <value>` |
| type | (lua_Integer | integer | RW | `obj.type = <value>` |
| referenceCount | referenceCount | integer | RW | `obj.referenceCount = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `rld: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(rld)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createEntity1 | createEntity1 | `` | `lightuserdata` | `obj:createEntity1()` |
| createEntity2 | createEntity2 | `` | `lightuserdata` | `obj:createEntity2()` |
| selectBiomeEntity | selectBiomeEntity | `position: Vector3` | `lightuserdata` | `obj:selectBiomeEntity(position)` |
| isLoaded | isLoaded | `` | `boolean` | `obj:isLoaded()` |

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _antiSlavery | _antiSlavery | boolean | RW | `obj._antiSlavery = <value>` |
| characteristicsData | characteristicsData | lightuserdata | RW | `obj.characteristicsData = <value>` |
| fundamentalNPCType | (lua_Integer | integer | RW | `obj.fundamentalNPCType = <value>` |
| ranks | ranks | lektor<std::string> | RW | `obj.ranks = <value>` |
| allowSlavesWeapons | allowSlavesWeapons | boolean | RW | `obj.allowSlavesWeapons = <value>` |
| myLawEnforcementFaction | myLawEnforcementFaction | Faction | RW | `obj.myLawEnforcementFaction = <value>` |
| isALawEnforcementFaction | isALawEnforcementFaction | boolean | RW | `obj.isALawEnforcementFaction = <value>` |
| factionLeader | factionLeader | FactionLeader | RW | `obj.factionLeader = <value>` |
| diplomatMgr | diplomatMgr | FactionUniqueSquadManager | RW | `obj.diplomatMgr = <value>` |
| relations | relations | FactionRelations | RW | `obj.relations = <value>` |
| factionOwnerships | factionOwnerships | Ownerships | RW | `obj.factionOwnerships = <value>` |
| warMgr | warMgr | FactionWarMgr | RW | `obj.warMgr = <value>` |
| tradeCulture | tradeCulture | TradeCulture | RW | `obj.tradeCulture = <value>` |
| raceSelector | raceSelector | FitnessSelector<GameData*> | RW | `obj.raceSelector = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| notARealFaction | notARealFaction | boolean | RW | `obj.notARealFaction = <value>` |
| roadPreference | roadPreference | number | RW | `obj.roadPreference = <value>` |
| platoonKillList | platoonKillList | lektor<Platoon*> | RW | `obj.platoonKillList = <value>` |
| platoonRemoveList | platoonRemoveList | lektor<Platoon*> | RW | `obj.platoonRemoveList = <value>` |
| activePlatoons | activePlatoons | lektor<Platoon*> | RW | `obj.activePlatoons = <value>` |
| unloadedPlatoons | unloadedPlatoons | lektor<Platoon*> | RW | `obj.unloadedPlatoons = <value>` |
| periodicUpdateCounter_active | periodicUpdateCounter_active | integer | RW | `obj.periodicUpdateCounter_active = <value>` |
| periodicUpdateCounter_unloaded | periodicUpdateCounter_unloaded | integer | RW | `obj.periodicUpdateCounter_unloaded = <value>` |
| data | data | GameData | RW | `obj.data = <value>` |
| isAI | (void* | lightuserdata | RW | `obj.isAI = <value>` |
| isPlayer | isPlayer | PlayerInterface | RW | `obj.isPlayer = <value>` |
| spawnTimeStamp | spawnTimeStamp | integer | RW | `obj.spawnTimeStamp = <value>` |
| diplomatTimeStamp | diplomatTimeStamp | integer | RW | `obj.diplomatTimeStamp = <value>` |
| platoonIDs | platoonIDs | integer | RW | `obj.platoonIDs = <value>` |
| p_TIME | p_TIME | number | RW | `obj.p_TIME = <value>` |
| platoonPeriodicUpdateIndex | platoonPeriodicUpdateIndex | integer | RW | `obj.platoonPeriodicUpdateIndex = <value>` |
| buildingSwaps | buildingSwaps | lektor<Faction::BuildingSwaps> | RW | `obj.buildingSwaps = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `_name: string` | `Faction` | `obj:_CONSTRUCTOR(_name)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getProsperityMultiplier | getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| clearAndDestroy | clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| setup | setup | `` | `boolean` | `obj:setup()` |
| setup2 | setup2 | `` | `boolean` | `obj:setup2()` |
| setup3 | setup3 | `` | `void` | `obj:setup3()` |
| getNewPlatoonID | getNewPlatoonID | `` | `string` | `obj:getNewPlatoonID()` |
| resetPlatoonID | resetPlatoonID | `` | `void` | `obj:resetPlatoonID()` |
| createNewEmptyUnloadedPlatoon | createNewEmptyUnloadedPlatoon | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:createNewEmptyUnloadedPlatoon(pos, persistent)` |
| createNewEmptyActivePlatoon | createNewEmptyActivePlatoon | `permanent: boolean, p: Vector3` | `Platoon` | `obj:createNewEmptyActivePlatoon(permanent, p)` |
| createPlatoonUnloaded | createPlatoonUnloaded | `pos: Vector3, persistent: boolean` | `void` | `obj:createPlatoonUnloaded(pos, persistent)` |
| createPlatoonAuto | createPlatoonAuto | `pos: Vector3` | `void` | `obj:createPlatoonAuto(pos)` |
| createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | `src: string` | `void` | `obj:createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src)` |
| restorePlatoon | restorePlatoon | `` | `void` | `obj:restorePlatoon()` |
| resetSquadPositions | resetSquadPositions | `target: Vector3` | `boolean` | `obj:resetSquadPositions(target)` |
| countPopulation | countPopulation | `` | `integer` | `obj:countPopulation()` |
| countNumSquads | countNumSquads | `` | `integer` | `obj:countNumSquads()` |
| destroyPlatoon | destroyPlatoon | `` | `void` | `obj:destroyPlatoon()` |
| removePlatoon | removePlatoon | `` | `void` | `obj:removePlatoon()` |
| getRandomLockLevel | getRandomLockLevel | `` | `integer` | `obj:getRandomLockLevel()` |
| getData | getData | `` | `GameData` | `obj:getData()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| getDefaultDivision | getDefaultDivision | `` | `GameData` | `obj:getDefaultDivision()` |
| getFactionColorScheme | getFactionColorScheme | `` | `GameData` | `obj:getFactionColorScheme()` |
| loadState | loadState | `` | `void` | `obj:loadState()` |
| saveState | saveState | `leveleditor: boolean` | `GameData` | `obj:saveState(leveleditor)` |
| _activateUnloadedPlatoons | _activateUnloadedPlatoons | `` | `void` | `obj:_activateUnloadedPlatoons()` |
| getCharactersInArea | getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| _NV_getCharactersInArea | _NV_getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:_NV_getCharactersInArea(pos, radius, standingOnly)` |
| getSelectedObjects | getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| _NV_getSelectedObjects | _NV_getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:_NV_getSelectedObjects(type, selectedOnly)` |
| removeObject | removeObject | `` | `void` | `obj:removeObject()` |
| _NV_removeObject | _NV_removeObject | `` | `void` | `obj:_NV_removeObject()` |
| destroyObject | destroyObject | `` | `void` | `obj:destroyObject()` |
| _NV_destroyObject | _NV_destroyObject | `` | `void` | `obj:_NV_destroyObject()` |
| processKillList | processKillList | `` | `void` | `obj:processKillList()` |
| _NV_processKillList | _NV_processKillList | `` | `void` | `obj:_NV_processKillList()` |
| addActiveObject | addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| choosePlatoon | choosePlatoon | `` | `ActivePlatoon` | `obj:choosePlatoon()` |
| getActivePlatoons | getActivePlatoons | `` | `lektor<Platoon*>` | `obj:getActivePlatoons()` |
| getUnloadedPlatoons | getUnloadedPlatoons | `` | `lektor<Platoon*>` | `obj:getUnloadedPlatoons()` |
| getFactionSize | getFactionSize | `` | `integer` | `obj:getFactionSize()` |
| update | update | `time: number` | `void` | `obj:update(time)` |
| periodicUpdateThreaded | periodicUpdateThreaded | `` | `boolean` | `obj:periodicUpdateThreaded()` |
| periodicUpdateMT | periodicUpdateMT | `` | `boolean` | `obj:periodicUpdateMT()` |
| isThePlayer | isThePlayer | `` | `boolean` | `obj:isThePlayer()` |
| isNotARealFaction | isNotARealFaction | `` | `boolean` | `obj:isNotARealFaction()` |
| getName | getName | `` | `void` | `obj:getName()` |
| getNumPlatoons | getNumPlatoons | `tempsOnly: boolean` | `integer` | `obj:getNumPlatoons(tempsOnly)` |
| getSquadThatOwns | getSquadThatOwns | `` | `Platoon` | `obj:getSquadThatOwns()` |
| getAllActiveSquads | getAllActiveSquads | `` | `lightuserdata` | `obj:getAllActiveSquads()` |
| getRoadPreference | getRoadPreference | `` | `number` | `obj:getRoadPreference()` |
| isAntiSlavery | isAntiSlavery | `` | `boolean` | `obj:isAntiSlavery()` |
| getLawEnforcementFaction | getLawEnforcementFaction | `` | `Faction` | `obj:getLawEnforcementFaction()` |
| chooseARace | chooseARace | `` | `GameData` | `obj:chooseARace()` |
| setName | setName | `_name: string` | `void` | `obj:setName(_name)` |
| getBuildingReplacement | getBuildingReplacement | `` | `GameData` | `obj:getBuildingReplacement()` |
| _switchToUnloadedPlatoon | _switchToUnloadedPlatoon | `` | `void` | `obj:_switchToUnloadedPlatoon()` |
| _newPlatoon | _newPlatoon | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:_newPlatoon(pos, persistent)` |
| _addActivePlatoonToList | _addActivePlatoonToList | `` | `void` | `obj:_addActivePlatoonToList()` |
| addPlatoon | addPlatoon | `` | `void` | `obj:addPlatoon()` |
| changePlatoonIndex | changePlatoonIndex | `index: integer` | `void` | `obj:changePlatoonIndex(index)` |
| deactivatePlatoon | deactivatePlatoon | `` | `void` | `obj:deactivatePlatoon()` |
| activatePlatoon | activatePlatoon | `` | `void` | `obj:activatePlatoon()` |
| updateUnloadedPlatoons | updateUnloadedPlatoons | `time: number` | `void` | `obj:updateUnloadedPlatoons(time)` |
| updateActivePlatoons | updateActivePlatoons | `time: number` | `void` | `obj:updateActivePlatoons(time)` |
| spawnSquadMissionsUpdate | spawnSquadMissionsUpdate | `` | `void` | `obj:spawnSquadMissionsUpdate()` |
| _spawnASquad | _spawnASquad | `listname: string, sizeMultiplier: number` | `boolean` | `obj:_spawnASquad(listname, sizeMultiplier)` |
| getFundamentalNPCType | getFundamentalNPCType | `` | `integer` | `obj:getFundamentalNPCType()` |

## FactionLeader
**Header:** `extern/KenshiLib/Include/kenshi/FactionLeader.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| faction | faction | Faction | RW | `obj.faction = <value>` |
| worstEnemy | worstEnemy | Faction | RW | `obj.worstEnemy = <value>` |
| biomeTerritory | biomeTerritory | lektor<GameData*> | RW | `obj.biomeTerritory = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactionLeader` | `obj:_CONSTRUCTOR()` |
| setNewLeader | setNewLeader | `` | `void` | `obj:setNewLeader()` |
| getEnemyMissionTargetList | getEnemyMissionTargetList | `` | `void` | `obj:getEnemyMissionTargetList()` |
| getGUIData | getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionManager
**Header:** `extern/KenshiLib/Include/kenshi/faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| addListMuto | (lua_Integer | integer | RW | `obj.addListMuto = <value>` |
| participants | participants | lektor<Faction*> | RW | `obj.participants = <value>` |
| toAddList | toAddList | lektor<Platoon*> | RW | `obj.toAddList = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactionManager` | `obj:_CONSTRUCTOR()` |
| saveGameState | saveGameState | `` | `void` | `obj:saveGameState()` |
| savePlayerGameState | savePlayerGameState | `` | `void` | `obj:savePlayerGameState()` |
| clearAndDestroy | clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| activateUnloadedPlatoons | activateUnloadedPlatoons | `` | `void` | `obj:activateUnloadedPlatoons()` |
| getOrCreateFaction | getOrCreateFaction | `id: string, name: string` | `Faction` | `obj:getOrCreateFaction(id, name)` |
| getFactionByName | getFactionByName | `name: string` | `Faction` | `obj:getFactionByName(name)` |
| getFactionByStringID | getFactionByStringID | `sid: string` | `Faction` | `obj:getFactionByStringID(sid)` |
| getEmptyFaction | getEmptyFaction | `` | `Faction` | `obj:getEmptyFaction()` |
| setupAndLinkAllFactions | setupAndLinkAllFactions | `` | `void` | `obj:setupAndLinkAllFactions()` |
| getFactionBySquad | getFactionBySquad | `` | `Faction` | `obj:getFactionBySquad()` |
| getCampaignGUIInfos | getCampaignGUIInfos | `cat: integer, playeronly: boolean` | `void` | `obj:getCampaignGUIInfos(cat, playeronly)` |
| areAnyHostileCampaignsRunning | areAnyHostileCampaignsRunning | `` | `boolean` | `obj:areAnyHostileCampaignsRunning()` |
| getNumTempPlatoons | getNumTempPlatoons | `` | `integer` | `obj:getNumTempPlatoons()` |
| updateMT | updateMT | `time: number` | `void` | `obj:updateMT(time)` |
| updateThreaded | updateThreaded | `time: number` | `void` | `obj:updateThreaded(time)` |
| _showDebugPlatoonMarkers | _showDebugPlatoonMarkers | `on: boolean` | `void` | `obj:_showDebugPlatoonMarkers(on)` |
| getAllFactions | getAllFactions | `` | `lightuserdata` | `obj:getAllFactions()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionRelations
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Faction | RW | `obj.me = <value>` |
| playerRank | playerRank | integer | RW | `obj.playerRank = <value>` |
| globalReputationTrust | globalReputationTrust | number | RW | `obj.globalReputationTrust = <value>` |
| globalReputationForBadassery | globalReputationForBadassery | number | RW | `obj.globalReputationForBadassery = <value>` |
| _factionRelations | _factionRelations | unknown | RW | `obj._factionRelations = <value>` |
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
| faction | faction | Faction | RW | `obj.faction = <value>` |
| value | value | number | RW | `obj.value = <value>` |
| valueText | (void* | lightuserdata | R | `obj.valueText` |
| leftBar | (void* | lightuserdata | R | `obj.leftBar` |
| rightBar | (void* | lightuserdata | R | `obj.rightBar` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactionRelationsLine` | `obj:_CONSTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionUniqueSquadManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| prosperityMgr | prosperityMgr | ProsperityManager | RW | `obj.prosperityMgr = <value>` |
| me | me | Faction | RW | `obj.me = <value>` |
| squadListData | squadListData | GameData | RW | `obj.squadListData = <value>` |
| homeTown | homeTown | Town | RW | `obj.homeTown = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactionUniqueSquadManager` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAndReset | clearAndReset | `` | `void` | `obj:clearAndReset()` |
| initialiseNew | initialiseNew | `` | `void` | `obj:initialiseNew()` |
| chooseRandomSquadToSpawn | chooseRandomSquadToSpawn | `time: number` | `GameData` | `obj:chooseRandomSquadToSpawn(time)` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| load | load | `import: boolean` | `void` | `obj:load(import)` |
| getGUIData | getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| getExistingSquadsFor | getExistingSquadsFor | `` | `lightuserdata` | `obj:getExistingSquadsFor()` |
| spawnNewUniqueSquad | spawnNewUniqueSquad | `` | `lightuserdata` | `obj:spawnNewUniqueSquad()` |

## FactionWarMgr
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Faction | RW | `obj.me = <value>` |
| lastID | lastID | integer | RW | `obj.lastID = <value>` |
| nextUpdateTime | nextUpdateTime | TimeOfDay | RW | `obj.nextUpdateTime = <value>` |
| myTowns | myTowns | lektor<TownBase*> | RW | `obj.myTowns = <value>` |
| hiredForces | hiredForces | lektor<hand> | RW | `obj.hiredForces = <value>` |
| activeCampaigns | (void* | lightuserdata | RW | `obj.activeCampaigns = <value>` |
| biomeTerritories | (void* | lightuserdata | RW | `obj.biomeTerritories = <value>` |
| biomeNoGoZones | (void* | lightuserdata | RW | `obj.biomeNoGoZones = <value>` |
| campaignRequests | (void* | lightuserdata | RW | `obj.campaignRequests = <value>` |
| possibleCampaigns | (void* | lightuserdata | RW | `obj.possibleCampaigns = <value>` |
| forces | (void* | lightuserdata | RW | `obj.forces = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactionWarMgr` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| reset | reset | `` | `void` | `obj:reset()` |
| save | save | `` | `void` | `obj:save()` |
| load | load | `` | `void` | `obj:load()` |
| removePlatoon | removePlatoon | `` | `void` | `obj:removePlatoon()` |
| addPlatoon | addPlatoon | `` | `void` | `obj:addPlatoon()` |
| getGUIData | getGUIData | `cat: integer, playeronly: boolean` | `void` | `obj:getGUIData(cat, playeronly)` |
| areAnyHostileCampaignsRunning | areAnyHostileCampaignsRunning | `playeronly: boolean` | `boolean` | `obj:areAnyHostileCampaignsRunning(playeronly)` |
| endCampaign | endCampaign | `c: userdata` | `void` | `obj:endCampaign(c)` |
| getAllTheForces | getAllTheForces | `c: userdata` | `void` | `obj:getAllTheForces(c)` |
| _generateForcesForTown | _generateForcesForTown | `c: userdata` | `void` | `obj:_generateForcesForTown(c)` |
| canGenerateThisManyForces | canGenerateThisManyForces | `num: integer` | `boolean` | `obj:canGenerateThisManyForces(num)` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| debugButton | debugButton | `` | `void` | `obj:debugButton()` |
| triggerCampaign | triggerCampaign | `data: userdata, minTime: number, forceDuplicate: boolean, forceDuplicate: boolean` | `lightuserdata` | `obj:triggerCampaign(data, minTime, forceDuplicate, forceDuplicate)` |
| getCurrentCampaign | getCurrentCampaign | `` | `lightuserdata` | `obj:getCurrentCampaign()` |
| getAITarget | getAITarget | `` | `void` | `obj:getAITarget()` |
| getMyUnloadedAI | getMyUnloadedAI | `` | `integer` | `obj:getMyUnloadedAI()` |
| isBiomeHomeTerritory | isBiomeHomeTerritory | `area: userdata` | `boolean` | `obj:isBiomeHomeTerritory(area)` |
| getNearestTown | getNearestTown | `p: Vector3` | `TownBase` | `obj:getNearestTown(p)` |
| getTownsInBiome | getTownsInBiome | `b: userdata` | `void` | `obj:getTownsInBiome(b)` |
| getMyTownsWithEnoughFreePopulation | getMyTownsWithEnoughFreePopulation | `popNeeded: integer` | `void` | `obj:getMyTownsWithEnoughFreePopulation(popNeeded)` |
| getActiveCampaign | getActiveCampaign | `uniqueID: integer` | `lightuserdata` | `obj:getActiveCampaign(uniqueID)` |
| setup | setup | `` | `void` | `obj:setup()` |
| _createCampaignData | _createCampaignData | `` | `lightuserdata` | `obj:_createCampaignData()` |

## FactionsScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mainWidget | (void* | lightuserdata | R | `obj.mainWidget` |
| selectedFaction | selectedFaction | Faction | RW | `obj.selectedFaction = <value>` |
| scrollList | (void* | lightuserdata | RW | `obj.scrollList = <value>` |
| scrollListItemTop | scrollListItemTop | integer | RW | `obj.scrollListItemTop = <value>` |
| scrollListItemWidth | scrollListItemWidth | integer | RW | `obj.scrollListItemWidth = <value>` |
| nameText | (void* | lightuserdata | R | `obj.nameText` |
| infoPanel | infoPanel | DatapanelGUI | RW | `obj.infoPanel = <value>` |
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

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| factoryObjectCreatedCallback | factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FactoryCallbackInterface` | `obj:_CONSTRUCTOR()` |

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

## FloatingProgressBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| caption | caption | string | RW | `obj.caption = <value>` |
| progress | progress | integer | RW | `obj.progress = <value>` |
| bar | (void* | lightuserdata | R | `obj.bar` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FloatingProgressBar` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setProgress | setProgress | `value: number` | `void` | `obj:setProgress(value)` |
| setCaption | setCaption | `value: string` | `void` | `obj:setCaption(value)` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |

## FlockingTools
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| getOutOfTheWayOfCharacter | getOutOfTheWayOfCharacter | unknown | RW | `obj.getOutOfTheWayOfCharacter = <value>` |
| currentPosition | currentPosition | Vector3 | RW | `obj.currentPosition = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
| combatMover | combatMover | CombatMovementController | RW | `obj.combatMover = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FlockingTools` | `obj:_CONSTRUCTOR()` |
| create | create | `` | `void` | `obj:create()` |
| getDistanceToClosestCharacter | getDistanceToClosestCharacter | `enemies: boolean, allies: boolean` | `number` | `obj:getDistanceToClosestCharacter(enemies, allies)` |
| getOutOfTheWay | getOutOfTheWay | `` | `void` | `obj:getOutOfTheWay()` |
| setCurrentPosition | setCurrentPosition | `_pos: Vector3` | `void` | `obj:setCurrentPosition(_pos)` |
| getRepulsionMagnitude | getRepulsionMagnitude | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `number` | `obj:getRepulsionMagnitude(repulsionPoint, MAX_DISTANCE, distance)` |
| getRepulsionVector | getRepulsionVector | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `Vector3` | `obj:getRepulsionVector(repulsionPoint, MAX_DISTANCE, distance)` |
| clampRepulsionVectorTo90Degrees | clampRepulsionVectorTo90Degrees | `desiredDirection: Vector3, alwaysStrafe: boolean` | `Vector3` | `obj:clampRepulsionVectorTo90Degrees(desiredDirection, alwaysStrafe)` |
| calculateCurrentRepulsionVector | calculateCurrentRepulsionVector | `MAX_DISTANCE: number, desiredDirection: Vector3, includeEnemies: boolean, includeFriends: boolean, strafeOnly: boolean` | `Vector3` | `obj:calculateCurrentRepulsionVector(MAX_DISTANCE, desiredDirection, includeEnemies, includeFriends, strafeOnly)` |
| getSensoryData | getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |

## FogEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/FogEditor.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| window | (void* | lightuserdata | R | `obj.window` |
| fogList | (void* | lightuserdata | R | `obj.fogList` |
| typeList | (void* | lightuserdata | R | `obj.typeList` |
| panel | panel | DatapanelGUI | RW | `obj.panel = <value>` |
| selectedFog | (void* | lightuserdata | R | `obj.selectedFog` |
| selectedSide | selectedSide | integer | RW | `obj.selectedSide = <value>` |
| colour | colour | Vector3 | RW | `obj.colour = <value>` |
| distance | distance | number | RW | `obj.distance = <value>` |
| radius | radius | number | RW | `obj.radius = <value>` |
| edge | edge | number | RW | `obj.edge = <value>` |
| editCage | (void* | lightuserdata | R | `obj.editCage` |
| editNode | (void* | lightuserdata | R | `obj.editNode` |
| editPos | editPos | Vector3 | RW | `obj.editPos = <value>` |
| editRot | editRot | Quaternion | RW | `obj.editRot = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| show | show | `` | `void` | `obj:show()` |
| close | close | `` | `void` | `obj:close()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| update | update | `` | `boolean` | `obj:update()` |
| save | save | `filename: string` | `void` | `obj:save(filename)` |
| updateFogName | updateFogName | `` | `void` | `obj:updateFogName()` |
| updateFogValues | updateFogValues | `` | `void` | `obj:updateFogValues()` |
| selectNextEdge | selectNextEdge | `` | `void` | `obj:selectNextEdge()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FoliageSystem
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| reloaded | reloaded | boolean | RW | `obj.reloaded = <value>` |
| generateOverlay | generateOverlay | boolean | RW | `obj.generateOverlay = <value>` |
| firstTimeLoad | firstTimeLoad | boolean | RW | `obj.firstTimeLoad = <value>` |
| collisionHash | collisionHash | integer | RW | `obj.collisionHash = <value>` |
| loadComplete | loadComplete | boolean | RW | `obj.loadComplete = <value>` |
| zoneMap | zoneMap | ZoneMap | RW | `obj.zoneMap = <value>` |
| coverageMap | (void* | lightuserdata | R | `obj.coverageMap` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `firstTimeLoad: boolean, buildOverlay: boolean, reloadData: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(firstTimeLoad, buildOverlay, reloadData)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| getCollisionHash | getCollisionHash | `` | `integer` | `obj:getCollisionHash()` |
| setupGrass | setupGrass | `paged: userdata, grassLoader: userdata, biomeCode: integer` | `void` | `obj:setupGrass(paged, grassLoader, biomeCode)` |
| setupFoliage | setupFoliage | `paged: userdata, treeLoader: userdata, biomeCode: integer` | `void` | `obj:setupFoliage(paged, treeLoader, biomeCode)` |
| spawn | spawn | `ent: userdata, position: Vector3, _treeLoader: userdata` | `boolean` | `obj:spawn(ent, position, _treeLoader)` |
| randomInt | randomInt | `min: integer, max: integer` | `integer` | `obj:randomInt(min, max)` |
| random | random | `min: number, max: number` | `number` | `obj:random(min, max)` |

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
| mainbar | mainbar | MainBarGUI | RW | `obj.mainbar = <value>` |
| tooltip | tooltip | ToolTip | RW | `obj.tooltip = <value>` |
| dialogue | dialogue | DialogueWindow | RW | `obj.dialogue = <value>` |
| tutorial | tutorial | TutorialGUI | RW | `obj.tutorial = <value>` |
| tutorialpedia | tutorialpedia | TutorialpediaGUI | RW | `obj.tutorialpedia = <value>` |
| currentCursor | (lua_Integer | integer | RW | `obj.currentCursor = <value>` |
| Scale | Scale | unknown | RW | `obj.Scale = <value>` |
| manager | (void* | lightuserdata | R | `obj.manager` |
| guiPlatform | (void* | lightuserdata | R | `obj.guiPlatform` |
| _closeTradeWindowMsg | _closeTradeWindowMsg | boolean | RW | `obj._closeTradeWindowMsg = <value>` |
| tradeA | tradeA | unknown | RW | `obj.tradeA = <value>` |
| tradeB | tradeB | unknown | RW | `obj.tradeB = <value>` |
| inventoryWindowBuilding | inventoryWindowBuilding | unknown | RW | `obj.inventoryWindowBuilding = <value>` |
| inventoryWindowCharacter | inventoryWindowCharacter | unknown | RW | `obj.inventoryWindowCharacter = <value>` |
| inventoryWindowTrader | inventoryWindowTrader | unknown | RW | `obj.inventoryWindowTrader = <value>` |
| inventoryWindowNPC | inventoryWindowNPC | unknown | RW | `obj.inventoryWindowNPC = <value>` |
| characterEditor | characterEditor | CharacterEditWindow | RW | `obj.characterEditor = <value>` |
| guiScreenLabelsMutex | (void* | lightuserdata | R | `obj.guiScreenLabelsMutex` |
| selectedObject | selectedObject | unknown | RW | `obj.selectedObject = <value>` |
| selectedPlayerCharacter | selectedPlayerCharacter | unknown | RW | `obj.selectedPlayerCharacter = <value>` |
| cursorPanel | cursorPanel | DatapanelGUI | RW | `obj.cursorPanel = <value>` |
| cursorAction | cursorAction | boolean | RW | `obj.cursorAction = <value>` |
| cursorActionPlayer | cursorActionPlayer | unknown | RW | `obj.cursorActionPlayer = <value>` |
| cursorActionTarget | cursorActionTarget | unknown | RW | `obj.cursorActionTarget = <value>` |
| visible | visible | boolean | RW | `obj.visible = <value>` |
| created | created | boolean | RW | `obj.created = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ForgottenGUI` | `obj:_CONSTRUCTOR()` |
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
| getToolTip | getToolTip | `` | `ToolTip` | `obj:getToolTip()` |
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
| notifyTownDeleted | notifyTownDeleted | `` | `void` | `obj:notifyTownDeleted()` |
| update | update | `` | `void` | `obj:update()` |
| closeTradeWindow | closeTradeWindow | `` | `void` | `obj:closeTradeWindow()` |
| closeInventoryBuilding | closeInventoryBuilding | `` | `void` | `obj:closeInventoryBuilding()` |
| closeAllInventories | closeAllInventories | `` | `void` | `obj:closeAllInventories()` |
| closeAllWindows | closeAllWindows | `` | `void` | `obj:closeAllWindows()` |
| getNumOpenInventoryWindows | getNumOpenInventoryWindows | `` | `integer` | `obj:getNumOpenInventoryWindows()` |
| getInventoryWindowWithMouse | getInventoryWindowWithMouse | `` | `InventoryGUI` | `obj:getInventoryWindowWithMouse()` |
| isAnyInventoryWindowOpen | isAnyInventoryWindowOpen | `` | `boolean` | `obj:isAnyInventoryWindowOpen()` |
| toggleHelpWindow | toggleHelpWindow | `` | `void` | `obj:toggleHelpWindow()` |
| addWindowToUpdateList | addWindowToUpdateList | `` | `void` | `obj:addWindowToUpdateList()` |
| removeWindowFromUpdateList | removeWindowFromUpdateList | `` | `void` | `obj:removeWindowFromUpdateList()` |
| addDatapanelToUpdateList | addDatapanelToUpdateList | `` | `void` | `obj:addDatapanelToUpdateList()` |
| removeDatapanelFromUpdateList | removeDatapanelFromUpdateList | `` | `void` | `obj:removeDatapanelFromUpdateList()` |
| setMouseCursorVisible | setMouseCursorVisible | `visible: boolean` | `void` | `obj:setMouseCursorVisible(visible)` |
| getGuiManager | getGuiManager | `` | `lightuserdata` | `obj:getGuiManager()` |
| createPanel | createPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanel(name, top, left, width, height, layer, skin)` |
| createPanelAbs | createPanelAbs | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanelAbs(name, top, left, width, height, layer, skin)` |
| createTabPanel | createTabPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createTabPanel(name, top, left, width, height, layer, skin)` |
| createFloatingImage | createFloatingImage | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImage(image, top, left, width, height, layer)` |
| createFloatingImageAbs | createFloatingImageAbs | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImageAbs(image, top, left, width, height, layer)` |
| createFloatingProgressBar | createFloatingProgressBar | `` | `FloatingProgressBar` | `obj:createFloatingProgressBar()` |
| createScreenLabelD | createScreenLabelD | `text: string, time: number` | `lightuserdata` | `obj:createScreenLabelD(text, time)` |

## FormationMover
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| me | me | Character | RW | `obj.me = <value>` |
| destination | destination | Vector3 | RW | `obj.destination = <value>` |
| direction | direction | Vector3 | RW | `obj.direction = <value>` |
| movementTarget | movementTarget | unknown | RW | `obj.movementTarget = <value>` |
| currentFormationID | currentFormationID | integer | RW | `obj.currentFormationID = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `FormationMover` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| getSpeeds | getSpeeds | `motion: Vector3, frameTime: number` | `number` | `obj:getSpeeds(motion, frameTime)` |
| setFormationMode | setFormationMode | `` | `void` | `obj:setFormationMode()` |
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
| win | win | MyGUI::Widget | R | `obj.win` |
| selectedObject | selectedObject | unknown | RW | `obj.selectedObject = <value>` |

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
| autoChangeSelectedObject | autoChangeSelectedObject | `` | `void` | `obj:autoChangeSelectedObject()` |
| _NV_autoChangeSelectedObject | _NV_autoChangeSelectedObject | `` | `void` | `obj:_NV_autoChangeSelectedObject()` |
| getWidget | getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
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
| currentID | currentID | integer | RW | `obj.currentID = <value>` |
| createdIndex | createdIndex | integer | RW | `obj.createdIndex = <value>` |
| activeValues | activeValues | unknown | RW | `obj.activeValues = <value>` |
| bdata | bdata | unknown | RW | `obj.bdata = <value>` |
| sdata | sdata | unknown | RW | `obj.sdata = <value>` |
| idata | idata | unknown | RW | `obj.idata = <value>` |
| fdata | fdata | unknown | RW | `obj.fdata = <value>` |
| filesdata | filesdata | unknown | RW | `obj.filesdata = <value>` |
| vecdata | vecdata | unknown | RW | `obj.vecdata = <value>` |
| quatdata | quatdata | unknown | RW | `obj.quatdata = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameData` | `obj:_CONSTRUCTOR()` |
| isValid | isValid | `` | `boolean` | `obj:isValid()` |
| getSourceContainer | getSourceContainer | `` | `GameDataContainer` | `obj:getSourceContainer()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| initialise | initialise | `t: integer, isActive: boolean` | `void` | `obj:initialise(t, isActive)` |
| loadFromFile | loadFromFile | `path: string, _type: integer` | `boolean` | `obj:loadFromFile(path, _type)` |
| saveToFile | saveToFile | `path: string` | `boolean` | `obj:saveToFile(path)` |
| storeHandleList | storeHandleList | `name: string` | `void` | `obj:storeHandleList(name)` |
| storeHandle | storeHandle | `name: string, redirect: boolean` | `void` | `obj:storeHandle(name, redirect)` |
| getHandle | getHandle | `name: string` | `void` | `obj:getHandle(name)` |
| updateFrom | updateFrom | `mod: boolean` | `boolean` | `obj:updateFrom(mod)` |
| isValueActive | isValueActive | `v: string` | `boolean` | `obj:isValueActive(v)` |
| isRefActive | isRefActive | `v: string` | `boolean` | `obj:isRefActive(v)` |
| addFileName | addFileName | `n: string, v: string, filestype: string, category: string, vis: boolean` | `void` | `obj:addFileName(n, v, filestype, category, vis)` |
| addString | addString | `n: string, v: string, category: string, vis: boolean` | `void` | `obj:addString(n, v, category, vis)` |
| add | add | `n: string, v: number, vis: boolean, isSlider: boolean` | `void` | `obj:add(n, v, vis, isSlider)` |
| getGameDataReferenceObject | getGameDataReferenceObject | `list: string, id: string` | `GameDataReference` | `obj:getGameDataReferenceObject(list, id)` |
| addToList | addToList | `list: string, id: string, val: integer, val2: integer, val3: integer` | `void` | `obj:addToList(list, id, val, val2, val3)` |
| removeFromList | removeFromList | `list: string, id: string` | `void` | `obj:removeFromList(list, id)` |
| findInList | findInList | `list: string, SID: string` | `boolean` | `obj:findInList(list, SID)` |
| clearList | clearList | `n: string` | `void` | `obj:clearList(n)` |
| clearEverything | clearEverything | `` | `void` | `obj:clearEverything()` |
| clearInstances | clearInstances | `` | `void` | `obj:clearInstances()` |
| getFromList | getFromList | `n: string, index: integer` | `string` | `obj:getFromList(n, index)` |
| getFromList_random | getFromList_random | `n: string` | `string` | `obj:getFromList_random(n)` |
| getListSize | getListSize | `n: string` | `integer` | `obj:getListSize(n)` |
| listExists | listExists | `n: string` | `boolean` | `obj:listExists(n)` |
| listExistsAndNotEmpty | listExistsAndNotEmpty | `n: string` | `boolean` | `obj:listExistsAndNotEmpty(n)` |
| getAllFromList | getAllFromList | `n: string` | `void` | `obj:getAllFromList(n)` |
| getReferenceList | getReferenceList | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceList(listname)` |
| getReferenceListIfExists | getReferenceListIfExists | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceListIfExists(listname)` |
| _getReferenceList_nonConst | _getReferenceList_nonConst | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:_getReferenceList_nonConst(listname)` |
| getFromListAsData | getFromListAsData | `n: string, index: integer, type: integer` | `GameData` | `obj:getFromListAsData(n, index, type)` |
| getValueFromList | getValueFromList | `list: string, index: integer` | `TripleInt` | `obj:getValueFromList(list, index)` |
| deleteInstancedObject | deleteInstancedObject | `id: string, modIndex: integer` | `void` | `obj:deleteInstancedObject(id, modIndex)` |
| getNewID | getNewID | `` | `integer` | `obj:getNewID()` |
| getColorVec | getColorVec | `name: string` | `Vector3` | `obj:getColorVec(name)` |
| addDeletedInstance | addDeletedInstance | `instanceID: string` | `void` | `obj:addDeletedInstance(instanceID)` |

## GameDataContainer
**Header:** `extern/KenshiLib/Include/kenshi/gamedatamanager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentID | currentID | integer | RW | `obj.currentID = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| isBaseDatafile | isBaseDatafile | boolean | RW | `obj.isBaseDatafile = <value>` |
| readOnly | readOnly | boolean | RW | `obj.readOnly = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameDataContainer` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createNewData | createNewData | `type: integer, forceID: string, name: string` | `GameData` | `obj:createNewData(type, forceID, name)` |
| getDataByName | getDataByName | `dataName: string, category: integer` | `GameData` | `obj:getDataByName(dataName, category)` |
| renameData | renameData | `n: string` | `void` | `obj:renameData(n)` |
| removeData | removeData | `` | `void` | `obj:removeData()` |
| removeDuplicatesOf | removeDuplicatesOf | `` | `void` | `obj:removeDuplicatesOf()` |
| removeAllDataOfType | removeAllDataOfType | `type: integer` | `void` | `obj:removeAllDataOfType(type)` |
| clearInstances | clearInstances | `` | `void` | `obj:clearInstances()` |
| clearButDontDestroy | clearButDontDestroy | `` | `void` | `obj:clearButDontDestroy()` |
| clearButDontDestroyPlatoons | clearButDontDestroyPlatoons | `` | `void` | `obj:clearButDontDestroyPlatoons()` |
| clearAndDestroy | clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| getNewID | getNewID | `` | `integer` | `obj:getNewID()` |
| destroyData | destroyData | `` | `void` | `obj:destroyData()` |
| preLoadAllReferencePtrs | preLoadAllReferencePtrs | `` | `void` | `obj:preLoadAllReferencePtrs()` |
| clearAllReferencePtrs | clearAllReferencePtrs | `` | `void` | `obj:clearAllReferencePtrs()` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |
| checkForDuplicates | checkForDuplicates | `` | `void` | `obj:checkForDuplicates()` |

## GameDataCopyStandalone
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameDataCopyStandalone` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataEditorWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| win | win | DatapanelGUI | RW | `obj.win = <value>` |
| data | data | GameData | RW | `obj.data = <value>` |

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

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataManager
**Header:** `extern/KenshiLib/Include/kenshi/gamedatamanager.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameDataManager` | `obj:_CONSTRUCTOR()` |
| reloadGameData | reloadGameData | `filename: string, isActive: boolean, _baseData: boolean` | `boolean` | `obj:reloadGameData(filename, isActive, _baseData)` |
| postProcessingTheDatas | postProcessingTheDatas | `` | `void` | `obj:postProcessingTheDatas()` |
| getMapSector | getMapSector | `x: integer, y: integer` | `GameData` | `obj:getMapSector(x, y)` |
| updateDatasOfType | updateDatasOfType | `type: integer, isMod: boolean` | `void` | `obj:updateDatasOfType(type, isMod)` |
| updateData | updateData | `isMod: boolean` | `void` | `obj:updateData(isMod)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataReference
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| values | values | TripleInt | RW | `obj.values = <value>` |
| sid | sid | string | RW | `obj.sid = <value>` |
| ptr | ptr | GameData | RW | `obj.ptr = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getPtr | getPtr | `` | `GameData` | `obj:getPtr()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataValuePair
**Header:** `extern/KenshiLib/Include/kenshi/dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | RW | `obj.data = <value>` |
| val0 | val0 | integer | RW | `obj.val0 = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `v: integer` | `GameDataValuePair` | `obj:_CONSTRUCTOR(v)` |

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
| render | (void* | lightuserdata | R | `obj.render` |
| physics | physics | PhysicsInterface | RW | `obj.physics = <value>` |
| gamedata | gamedata | GameDataManager | RW | `obj.gamedata = <value>` |
| leveldata | leveldata | GameDataManager | RW | `obj.leveldata = <value>` |
| savedata | savedata | GameDataManager | RW | `obj.savedata = <value>` |
| theFactory | theFactory | RootObjectFactory | RW | `obj.theFactory = <value>` |
| factionMgr | factionMgr | FactionManager | RW | `obj.factionMgr = <value>` |
| navmesh | navmesh | NavMesh | RW | `obj.navmesh = <value>` |
| nodeList | (void* | lightuserdata | R | `obj.nodeList` |
| guiDisplayObject | guiDisplayObject | unknown | RW | `obj.guiDisplayObject = <value>` |
| messageRoller | (void* | lightuserdata | R | `obj.messageRoller` |
| ogreLogger | (void* | lightuserdata | R | `obj.ogreLogger` |
| steamEnabled | steamEnabled | boolean | RW | `obj.steamEnabled = <value>` |
| player | player | PlayerInterface | RW | `obj.player = <value>` |
| frameSpeedMult | frameSpeedMult | number | RW | `obj.frameSpeedMult = <value>` |
| deathParadeWasMeddledWith | deathParadeWasMeddledWith | boolean | RW | `obj.deathParadeWasMeddledWith = <value>` |
| charUpdateListMain_inUse | charUpdateListMain_inUse | boolean | RW | `obj.charUpdateListMain_inUse = <value>` |
| _AINonRenderThread | (void* | lightuserdata | R | `obj._AINonRenderThread` |
| timeStamper | timeStamper | SimpleTimeStamper | RW | `obj.timeStamper = <value>` |
| zoneMgr | zoneMgr | ZoneManager | RW | `obj.zoneMgr = <value>` |
| debugFlag | debugFlag | boolean | RW | `obj.debugFlag = <value>` |
| paused | paused | boolean | RW | `obj.paused = <value>` |
| gameResetting | gameResetting | boolean | RW | `obj.gameResetting = <value>` |
| audioThread | (void* | lightuserdata | R | `obj.audioThread` |
| charactersWithLights | charactersWithLights | ogre_unordered_set<Character*>::type | RW | `obj.charactersWithLights = <value>` |
| deathParade | deathParade | unknown | RW | `obj.deathParade = <value>` |
| charUpdateListMain | charUpdateListMain | ogre_unordered_set<Character*>::type | RW | `obj.charUpdateListMain = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| justLoadFactionRelations | justLoadFactionRelations | `` | `void` | `obj:justLoadFactionRelations()` |
| startUpThreads | startUpThreads | `` | `boolean` | `obj:startUpThreads()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GameWorld` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resetGame | resetGame | `` | `void` | `obj:resetGame()` |
| _clearAndDestroyGameWorldStuff | _clearAndDestroyGameWorldStuff | `` | `void` | `obj:_clearAndDestroyGameWorldStuff()` |
| initialisation | initialisation | `` | `boolean` | `obj:initialisation()` |
| initialisationGameData | initialisationGameData | `` | `boolean` | `obj:initialisationGameData()` |
| dailyUpdates | dailyUpdates | `` | `void` | `obj:dailyUpdates()` |
| initialiseNewGameWorld | initialiseNewGameWorld | `` | `void` | `obj:initialiseNewGameWorld()` |
| errorToLogReleaseMode | errorToLogReleaseMode | `msg: string` | `void` | `obj:errorToLogReleaseMode(msg)` |
| errorD | errorD | `msg: string` | `void` | `obj:errorD(msg)` |
| logToSave | logToSave | `msg: string` | `void` | `obj:logToSave(msg)` |
| log | log | `line: string` | `void` | `obj:log(line)` |
| logDebug | logDebug | `line: string, logname: string` | `void` | `obj:logDebug(line, logname)` |
| dynamicDestroyBuilding | dynamicDestroyBuilding | `` | `void` | `obj:dynamicDestroyBuilding()` |
| getFromDeathParade | getFromDeathParade | `` | `Character` | `obj:getFromDeathParade()` |
| addPortraitUpdate | addPortraitUpdate | `` | `void` | `obj:addPortraitUpdate()` |
| removePortaitUpdate | removePortaitUpdate | `` | `void` | `obj:removePortaitUpdate()` |
| getTimeFromStamp | getTimeFromStamp | `stamp: number` | `TimeOfDay` | `obj:getTimeFromStamp(stamp)` |
| getIsInKillList | getIsInKillList | `` | `boolean` | `obj:getIsInKillList()` |
| flushKillList | flushKillList | `` | `void` | `obj:flushKillList()` |
| allThreadQueuesAreClear | allThreadQueuesAreClear | `` | `boolean` | `obj:allThreadQueuesAreClear()` |
| initBaseMods | initBaseMods | `` | `void` | `obj:initBaseMods()` |
| initModsList | initModsList | `` | `void` | `obj:initModsList()` |
| getModIndex | getModIndex | `modName: string` | `integer` | `obj:getModIndex(modName)` |
| buildingIntersectionTestCapsule | buildingIntersectionTestCapsule | `pos: Vector3, radius: number, length: number` | `boolean` | `obj:buildingIntersectionTestCapsule(pos, radius, length)` |
| getLightLevel | getLightLevel | `position: Vector3, floor: integer, inside: boolean` | `number` | `obj:getLightLevel(position, floor, inside)` |
| populateMapArea_nonPermanent | populateMapArea_nonPermanent | `howMany: integer, rePopulationMode: boolean` | `void` | `obj:populateMapArea_nonPermanent(howMany, rePopulationMode)` |
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
| addToUpdateListMain | addToUpdateListMain | `` | `void` | `obj:addToUpdateListMain()` |
| removeFromUpdateListMain | removeFromUpdateListMain | `` | `void` | `obj:removeFromUpdateListMain()` |
| addToDeathParade | addToDeathParade | `` | `void` | `obj:addToDeathParade()` |
| removeFromDeathParade | removeFromDeathParade | `` | `boolean` | `obj:removeFromDeathParade()` |
| removeFromDeathParadeByPlatoon | removeFromDeathParadeByPlatoon | `` | `void` | `obj:removeFromDeathParadeByPlatoon()` |
| hideContextMenu | hideContextMenu | `` | `void` | `obj:hideContextMenu()` |
| showPlayerAMessage_withLog | showPlayerAMessage_withLog | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage_withLog(message, queued)` |
| showPlayerAMessage | showPlayerAMessage | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage(message, queued)` |
| showPlayerAMessageD | showPlayerAMessageD | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessageD(message, queued)` |
| playNotification | playNotification | `sound: string` | `void` | `obj:playNotification(sound)` |
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
| AINonRenderThread | AINonRenderThread | `` | `ThreadWannabe` | `obj:AINonRenderThread()` |
| processAttachmentsKillList | processAttachmentsKillList | `` | `void` | `obj:processAttachmentsKillList()` |
| processKillList | processKillList | `forceImmediate: boolean` | `void` | `obj:processKillList(forceImmediate)` |
| processUpdateRemovalList | processUpdateRemovalList | `` | `void` | `obj:processUpdateRemovalList()` |
| loadAllPlatoons | loadAllPlatoons | `` | `void` | `obj:loadAllPlatoons()` |
| reCalculateFortificationInsideOutsideStateForAllCharacters | reCalculateFortificationInsideOutsideStateForAllCharacters | `` | `void` | `obj:reCalculateFortificationInsideOutsideStateForAllCharacters()` |
| getTimeStamp | getTimeStamp | `` | `number` | `obj:getTimeStamp()` |
| getTimeFromStamp_inGameHours | getTimeFromStamp_inGameHours | `stamp: number` | `number` | `obj:getTimeFromStamp_inGameHours(stamp)` |
| getTimeStamp_inGameHours | getTimeStamp_inGameHours | `` | `TimeOfDay` | `obj:getTimeStamp_inGameHours()` |
| getLengthOfHourInRealSeconds | getLengthOfHourInRealSeconds | `` | `number` | `obj:getLengthOfHourInRealSeconds()` |

## GamedataSelectionList
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| win | (MyGUI::Widget* | MyGUI::Widget | R | `obj.win` |
| list | (MyGUI::Widget* | MyGUI::Widget | R | `obj.list` |
| items | items | lektor<GameData*> | R | `obj.items` |
| levelEditor | levelEditor | LevelEditor | R | `obj.levelEditor` |
| lastItem | (lua_Integer | integer | RW | `obj.lastItem = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `type: integer, top: number, left: number, w: number, h: number` | `GamedataSelectionList` | `obj:_CONSTRUCTOR(type, top, left, w, h)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| deselectItem | deselectItem | `` | `void` | `obj:deselectItem()` |
| selectItem | selectItem | `` | `boolean` | `obj:selectItem()` |
| getSelectedItem | getSelectedItem | `` | `GameData` | `obj:getSelectedItem()` |
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| formatItem | formatItem | `` | `string` | `obj:formatItem()` |
| _NV_formatItem | _NV_formatItem | `` | `string` | `obj:_NV_formatItem()` |
| listItemSelected | listItemSelected | `_index: integer` | `void` | `obj:listItemSelected(_index)` |
| changeFilter | changeFilter | `` | `void` | `obj:changeFilter()` |

## GameplayOptions
**Header:** `extern/KenshiLib/Include/kenshi/saveinfo.h`

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
| save | save | `` | `void` | `obj:save()` |
| load | load | `` | `void` | `obj:load()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `_level: integer` | `Gear` | `obj:_CONSTRUCTOR(_level)` |
| isGear | isGear | `` | `Gear` | `obj:isGear()` |
| _NV_isGear | _NV_isGear | `` | `Gear` | `obj:_NV_isGear()` |
| getLevel01 | getLevel01 | `` | `number` | `obj:getLevel01()` |
| _NV_getLevel01 | _NV_getLevel01 | `` | `number` | `obj:_NV_getLevel01()` |
| getLevel | getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| isAFactionUniform | isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| _NV_isAFactionUniform | _NV_isAFactionUniform | `` | `Faction` | `obj:_NV_isAFactionUniform()` |
| _serialise | _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| isPlayerCrafted | isPlayerCrafted | `` | `boolean` | `obj:isPlayerCrafted()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setInventoryWeAreIn | setInventoryWeAreIn | `` | `void` | `obj:setInventoryWeAreIn()` |
| _NV_setInventoryWeAreIn | _NV_setInventoryWeAreIn | `` | `void` | `obj:_NV_setInventoryWeAreIn()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `GenericFixedInventoryLayout` | `obj:_CONSTRUCTOR()` |
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

## Hand
**Header:** `extern/KenshiLib/Include/kenshi/util/hand.h`

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
| knowsAbout | knowsAbout | `` | `boolean` | `obj:knowsAbout()` |
| hasRoomFor | hasRoomFor | `` | `boolean` | `obj:hasRoomFor()` |
| remember | remember | `state: boolean` | `void` | `obj:remember(state)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `HasRoomCache` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## HavokCharacter
**Header:** `extern/KenshiLib/Include/kenshi/havokcharacter.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| startingFace | startingFace | integer | RW | `obj.startingFace = <value>` |
| currentFace | currentFace | integer | RW | `obj.currentFace = <value>` |
| nextEdge | nextEdge | integer | RW | `obj.nextEdge = <value>` |
| radius | radius | number | RW | `obj.radius = <value>` |
| waterModifier | waterModifier | number | RW | `obj.waterModifier = <value>` |
| acceleration | acceleration | number | RW | `obj.acceleration = <value>` |
| desiredSpeed | desiredSpeed | number | RW | `obj.desiredSpeed = <value>` |
| positionChanged | positionChanged | boolean | RW | `obj.positionChanged = <value>` |
| timeOffPath | timeOffPath | number | RW | `obj.timeOffPath = <value>` |
| characterState | (lua_Integer | integer | RW | `obj.characterState = <value>` |
| lastState | (lua_Integer | integer | RW | `obj.lastState = <value>` |
| pathState | (lua_Integer | integer | RW | `obj.pathState = <value>` |
| handle | handle | unknown | RW | `obj.handle = <value>` |
| collided | collided | unknown | RW | `obj.collided = <value>` |
| sensoryData | sensoryData | SensoryData | RW | `obj.sensoryData = <value>` |
| resolveFlag | resolveFlag | integer | RW | `obj.resolveFlag = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setPosition | setPosition | `p: Vector3, key: integer` | `void` | `obj:setPosition(p, key)` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| setVelocity | setVelocity | `v: Vector3` | `void` | `obj:setVelocity(v)` |
| getVelocity | getVelocity | `` | `Vector3` | `obj:getVelocity()` |
| getWaypointDirection | getWaypointDirection | `` | `Vector3` | `obj:getWaypointDirection()` |
| getDirectionMoved | getDirectionMoved | `` | `Vector3` | `obj:getDirectionMoved()` |
| setWaterModifier | setWaterModifier | `m: number` | `void` | `obj:setWaterModifier(m)` |
| setManualMode | setManualMode | `on: boolean` | `void` | `obj:setManualMode(on)` |
| setDesiredSpeed | setDesiredSpeed | `speed: number` | `void` | `obj:setDesiredSpeed(speed)` |
| getState | getState | `` | `integer` | `obj:getState()` |
| getPathState | getPathState | `` | `integer` | `obj:getPathState()` |
| isOnNavmesh | isOnNavmesh | `` | `boolean` | `obj:isOnNavmesh()` |
| getClosestPoint | getClosestPoint | `target: Vector3, max: number` | `Vector3` | `obj:getClosestPoint(target, max)` |
| requestPath | requestPath | `goal: Vector3, priority: integer` | `void` | `obj:requestPath(goal, priority)` |
| clearPath | clearPath | `` | `void` | `obj:clearPath()` |
| update | update | `time: number` | `void` | `obj:update(time)` |
| moveAlongPath | moveAlongPath | `time: number` | `boolean` | `obj:moveAlongPath(time)` |
| handleCollision | handleCollision | `` | `boolean` | `obj:handleCollision()` |
| invalidate | invalidate | `rid: integer` | `void` | `obj:invalidate(rid)` |
| _getFaceKey | _getFaceKey | `` | `integer` | `obj:_getFaceKey()` |
| pullThroughVertex | pullThroughVertex | `side: integer, index: integer` | `integer` | `obj:pullThroughVertex(side, index)` |
| updateNextEdge | updateNextEdge | `` | `integer` | `obj:updateNextEdge()` |
| resolveProblems | resolveProblems | `` | `void` | `obj:resolveProblems()` |
| atGoal | atGoal | `` | `boolean` | `obj:atGoal()` |

## HealthPartStatus
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | RW | `obj.data = <value>` |
| whatAmI | (lua_Integer | integer | RW | `obj.whatAmI = <value>` |
| medical | medical | MedicalSystem | RW | `obj.medical = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
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
| serialise | serialise | `num: integer` | `void` | `obj:serialise(num)` |
| load | load | `num: integer` | `void` | `obj:load(num)` |
| isRobotic | isRobotic | `` | `boolean` | `obj:isRobotic()` |
| getData | getData | `` | `GameData` | `obj:getData()` |
| getRobotLimbEnum | getRobotLimbEnum | `` | `integer` | `obj:getRobotLimbEnum()` |
| setup | setup | `_hitchance: number, _max: number, _age: number, selfHeal: boolean` | `void` | `obj:setup(_hitchance, _max, _age, selfHeal)` |
| update | update | `frameTIME: number, healMultFlesh: number, healMultRobot: number, degenerationRate: number, _age: number, robotWear: number` | `boolean` | `obj:update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear)` |
| updateDerivedHealths | updateDerivedHealths | `` | `void` | `obj:updateDerivedHealths()` |
| getWorstDamage | getWorstDamage | `brokenBoneValue: number` | `number` | `obj:getWorstDamage(brokenBoneValue)` |
| setRobotLimbItem | setRobotLimbItem | `isLoadingASave: boolean` | `void` | `obj:setRobotLimbItem(isLoadingASave)` |
| getExtraBleedingAmount | getExtraBleedingAmount | `` | `number` | `obj:getExtraBleedingAmount()` |
| isDead | isDead | `` | `boolean` | `obj:isDead()` |
| getBloodynessMult | getBloodynessMult | `` | `number` | `obj:getBloodynessMult()` |
| maxHealth | maxHealth | `` | `number` | `obj:maxHealth()` |
| healthAsPercent | healthAsPercent | `healt: number` | `number` | `obj:healthAsPercent(healt)` |

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

## ImportGameMenu
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| newGameOptions | (void* | lightuserdata | R | `obj.newGameOptions` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| select | select | `index: integer` | `void` | `obj:select(index)` |
| _NV_select | _NV_select | `index: integer` | `void` | `obj:_NV_select(index)` |

## InputHandler
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| keyboard | (void* | lightuserdata | RW | `obj.keyboard = <value>` |
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
| mPos | mPos | unknown | RW | `obj.mPos = <value>` |
| mPosAbs | mPosAbs | unknown | RW | `obj.mPosAbs = <value>` |
| mSpeed | mSpeed | Vector3 | RW | `obj.mSpeed = <value>` |
| mWheel | mWheel | integer | RW | `obj.mWheel = <value>` |
| commands | (void* | lightuserdata | R | `obj.commands` |
| map | (void* | lightuserdata | R | `obj.map` |
| editMap | (void* | lightuserdata | R | `obj.editMap` |
| events | (void* | lightuserdata | R | `obj.events` |
| keyNameMap | second | integer | R | `obj.keyNameMap` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getKeyUTF8 | getKeyUTF8 | `key: integer` | `string` | `obj:getKeyUTF8(key)` |
| parseKey | parseKey | `s: string` | `integer` | `obj:parseKey(s)` |
| getCommand | getCommand | `s: string` | `lightuserdata` | `obj:getCommand(s)` |
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
| addCommand | addCommand | `name: string, value: integer, key: integer, alt: integer, masks: integer, mode: integer` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| unbind | unbind | `cmd: string, mode: integer` | `void` | `obj:unbind(cmd, mode)` |
| isBound | isBound | `cmd: string` | `boolean` | `obj:isBound(cmd)` |
| getBoundKeys | getBoundKeys | `command: string` | `integer` | `obj:getBoundKeys(command)` |
| getBoundCommand | getBoundCommand | `key: integer, mode: integer` | `string` | `obj:getBoundCommand(key, mode)` |

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

## InteriorModeButtonWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/InteriorModeButtonWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| exteriorsInvisible | exteriorsInvisible | boolean | RW | `obj.exteriorsInvisible = <value>` |
| interiorMode | interiorMode | boolean | RW | `obj.interiorMode = <value>` |
| dataEditWindow | dataEditWindow | GameDataEditorWindow | RW | `obj.dataEditWindow = <value>` |
| currentBuilding | currentBuilding | unknown | RW | `obj.currentBuilding = <value>` |
| currentInterior | currentInterior | string | RW | `obj.currentInterior = <value>` |
| currentExterior | currentExterior | string | RW | `obj.currentExterior = <value>` |
| interiorModeButton | (void* | lightuserdata | R | `obj.interiorModeButton` |
| win | (void* | lightuserdata | R | `obj.win` |
| centerButton | (void* | lightuserdata | R | `obj.centerButton` |
| exteriorButton | (void* | lightuserdata | R | `obj.exteriorButton` |
| titleLabel | (void* | lightuserdata | R | `obj.titleLabel` |
| saveBut | (void* | lightuserdata | R | `obj.saveBut` |
| deleteBut | (void* | lightuserdata | R | `obj.deleteBut` |
| listbox | (void* | lightuserdata | R | `obj.listbox` |
| namebox | (void* | lightuserdata | R | `obj.namebox` |
| saveBut2 | (void* | lightuserdata | R | `obj.saveBut2` |
| deleteBut2 | (void* | lightuserdata | R | `obj.deleteBut2` |
| listbox2 | (void* | lightuserdata | R | `obj.listbox2` |
| namebox2 | (void* | lightuserdata | R | `obj.namebox2` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| toggleInteriorMode | toggleInteriorMode | `` | `void` | `obj:toggleInteriorMode()` |
| setVisible | setVisible | `v: boolean` | `void` | `obj:setVisible(v)` |
| wantExteriorsInvisible | wantExteriorsInvisible | `` | `boolean` | `obj:wantExteriorsInvisible()` |
| setSelectedBuilding | setSelectedBuilding | `` | `void` | `obj:setSelectedBuilding()` |
| getSelectedBuilding | getSelectedBuilding | `` | `Building` | `obj:getSelectedBuilding()` |
| updateUsageNodes | updateUsageNodes | `` | `boolean` | `obj:updateUsageNodes()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| activateInteriorMode | activateInteriorMode | `on: boolean` | `void` | `obj:activateInteriorMode(on)` |
| confirmDeleteInteriorLayout | confirmDeleteInteriorLayout | `c: integer` | `void` | `obj:confirmDeleteInteriorLayout(c)` |
| confirmDeleteExteriorLayout | confirmDeleteExteriorLayout | `c: integer` | `void` | `obj:confirmDeleteExteriorLayout(c)` |
| setInteriorLayout | setInteriorLayout | `name: string` | `void` | `obj:setInteriorLayout(name)` |
| setExteriorLayout | setExteriorLayout | `name: string` | `void` | `obj:setExteriorLayout(name)` |
| recheckOutsideFurniture | recheckOutsideFurniture | `` | `void` | `obj:recheckOutsideFurniture()` |

## Inventory
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| hasRoomCache | (void* | lightuserdata | RW | `obj.hasRoomCache = <value>` |
| callbackObject | callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
| owner | owner | RootObject | RW | `obj.owner = <value>` |
| totalWeight | totalWeight | number | RW | `obj.totalWeight = <value>` |
| _allItems | _allItems | lektor<Item*> | R | `obj._allItems` |
| sections | second | InventorySection | R | `obj.sections` |
| sectionsInSearchOrder | sectionsInSearchOrder | lektor<InventorySection*> | R | `obj.sectionsInSearchOrder` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Inventory` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAll | clearAll | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAll(destroy, skipUnique)` |
| serialise | serialise | `` | `GameData` | `obj:serialise()` |
| notifyModified | notifyModified | `` | `void` | `obj:notifyModified()` |
| initialiseNewSection | initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| _NV_initialiseNewSection | _NV_initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:_NV_initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| resizeSection | resizeSection | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resizeSection(w, h, clearContent)` |
| removeAllSections | removeAllSections | `` | `void` | `obj:removeAllSections()` |
| getSection | getSection | `name: string` | `InventorySection` | `obj:getSection(name)` |
| getSectionOfType | getSectionOfType | `type: integer` | `InventorySection` | `obj:getSectionOfType(type)` |
| getCallbackCharacter | getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| addItem | addItem | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:addItem(quantity, dropOnFail, destroyOnFail)` |
| _NV_addItem | _NV_addItem | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_addItem(quantity, dropOnFail, destroyOnFail)` |
| tryAddItem | tryAddItem | `quantity: integer` | `boolean` | `obj:tryAddItem(quantity)` |
| _NV_tryAddItem | _NV_tryAddItem | `quantity: integer` | `boolean` | `obj:_NV_tryAddItem(quantity)` |
| hasRoomForItem | hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| removeItemDontDestroy_returnsItem | removeItemDontDestroy_returnsItem | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| _NV_removeItemDontDestroy_returnsItem | _NV_removeItemDontDestroy_returnsItem | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:_NV_removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| removeItemAutoDestroy | removeItemAutoDestroy | `howmany: integer` | `boolean` | `obj:removeItemAutoDestroy(howmany)` |
| _NV_removeItemAutoDestroy | _NV_removeItemAutoDestroy | `howmany: integer` | `boolean` | `obj:_NV_removeItemAutoDestroy(howmany)` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| transferMouseItem | transferMouseItem | `` | `boolean` | `obj:transferMouseItem()` |
| countItems | countItems | `` | `integer` | `obj:countItems()` |
| getItem | getItem | `` | `Item` | `obj:getItem()` |
| hasItemType | hasItemType | `item: integer, skipEquipped: boolean` | `boolean` | `obj:hasItemType(item, skipEquipped)` |
| hasStolenItems | hasStolenItems | `` | `boolean` | `obj:hasStolenItems()` |
| getSecondaryWeapon | getSecondaryWeapon | `` | `Weapon` | `obj:getSecondaryWeapon()` |
| getPrimaryWeapon | getPrimaryWeapon | `` | `Weapon` | `obj:getPrimaryWeapon()` |
| takeOneItemOnly | takeOneItemOnly | `` | `Item` | `obj:takeOneItemOnly()` |
| deathCheck | deathCheck | `` | `boolean` | `obj:deathCheck()` |
| hasItemFunction | hasItemFunction | `type: integer` | `boolean` | `obj:hasItemFunction(type)` |
| getBestItemWithFunction | getBestItemWithFunction | `type: integer` | `Item` | `obj:getBestItemWithFunction(type)` |
| getBestFoodItem | getBestFoodItem | `` | `Item` | `obj:getBestFoodItem()` |
| getNumFoodItems | getNumFoodItems | `` | `integer` | `obj:getNumFoodItems()` |
| _getBestFoodItem | _getBestFoodItem | `type: integer` | `Item` | `obj:_getBestFoodItem(type)` |
| _getNumFoodItems | _getNumFoodItems | `type: integer` | `integer` | `obj:_getNumFoodItems(type)` |
| hasWeaponEquipped | hasWeaponEquipped | `` | `boolean` | `obj:hasWeaponEquipped()` |
| equipItem | equipItem | `` | `boolean` | `obj:equipItem()` |
| isAContainer | isAContainer | `` | `boolean` | `obj:isAContainer()` |
| getOwner | getOwner | `` | `RootObject` | `obj:getOwner()` |
| isEmpty | isEmpty | `` | `boolean` | `obj:isEmpty()` |
| recalculateTotalWeight | recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| getTotalWeight | getTotalWeight | `` | `number` | `obj:getTotalWeight()` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| takeMoney | takeMoney | `val: integer` | `void` | `obj:takeMoney(val)` |
| buyItem | buyItem | `` | `Item` | `obj:buyItem()` |
| getInventoryGUI | getInventoryGUI | `` | `InventoryGUI` | `obj:getInventoryGUI()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| _sectionAddItemCallback | _sectionAddItemCallback | `` | `void` | `obj:_sectionAddItemCallback()` |
| _NV__sectionAddItemCallback | _NV__sectionAddItemCallback | `` | `void` | `obj:_NV__sectionAddItemCallback()` |
| _sectionUpdateItemCallback | _sectionUpdateItemCallback | `_a2: integer` | `void` | `obj:_sectionUpdateItemCallback(_a2)` |
| _NV__sectionUpdateItemCallback | _NV__sectionUpdateItemCallback | `_a2: integer` | `void` | `obj:_NV__sectionUpdateItemCallback(_a2)` |
| _sectionRemoveItemCallback | _sectionRemoveItemCallback | `` | `void` | `obj:_sectionRemoveItemCallback()` |
| _NV__sectionRemoveItemCallback | _NV__sectionRemoveItemCallback | `` | `void` | `obj:_NV__sectionRemoveItemCallback()` |
| refreshGui | refreshGui | `` | `void` | `obj:refreshGui()` |
| _NV_refreshGui | _NV_refreshGui | `` | `void` | `obj:_NV_refreshGui()` |
| autoArrange | autoArrange | `` | `void` | `obj:autoArrange()` |
| getCallbackObject | getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _addToList | _addToList | `` | `void` | `obj:_addToList()` |
| _NV__addToList | _NV__addToList | `` | `void` | `obj:_NV__addToList()` |
| _removeFromList | _removeFromList | `checkEverything: boolean` | `void` | `obj:_removeFromList(checkEverything)` |
| _NV__removeFromList | _NV__removeFromList | `checkEverything: boolean` | `void` | `obj:_NV__removeFromList(checkEverything)` |
| getHandle | getHandle | `` | `void` | `obj:getHandle()` |
| loadFrom | loadFrom | `` | `void` | `obj:loadFrom()` |
| fillFromVendorList | fillFromVendorList | `` | `void` | `obj:fillFromVendorList()` |
| getAllSectionsOfType | getAllSectionsOfType | `type: integer` | `void` | `obj:getAllSectionsOfType(type)` |
| getAllSections | getAllSections | `` | `lektor<InventorySection*>` | `obj:getAllSections()` |
| getExcessLoot | getExcessLoot | `justAsking: boolean` | `boolean` | `obj:getExcessLoot(justAsking)` |
| getResourceItems | getResourceItems | `buildingMatsToo: boolean` | `void` | `obj:getResourceItems(buildingMatsToo)` |
| getNumItems | getNumItems | `` | `integer` | `obj:getNumItems()` |
| hasItem | hasItem | `quantity: integer` | `boolean` | `obj:hasItem(quantity)` |
| getAllStolenItems | getAllStolenItems | `includeUnknown: boolean` | `void` | `obj:getAllStolenItems(includeUnknown)` |
| getAllItemsOfType | getAllItemsOfType | `ty: integer, skipEquipped: boolean` | `void` | `obj:getAllItemsOfType(ty, skipEquipped)` |
| getEquippedWeapons | getEquippedWeapons | `` | `void` | `obj:getEquippedWeapons()` |
| getEquippedArmour | getEquippedArmour | `` | `void` | `obj:getEquippedArmour()` |
| takeItem_EntireStack | takeItem_EntireStack | `` | `Item` | `obj:takeItem_EntireStack()` |
| getAllItemsWithFunction | getAllItemsWithFunction | `type: integer` | `void` | `obj:getAllItemsWithFunction(type)` |
| getBestItemWithLowestCharges | getBestItemWithLowestCharges | `type: integer` | `Item` | `obj:getBestItemWithLowestCharges(type)` |
| getAllItems | getAllItems | `` | `lektor<Item*>` | `obj:getAllItems()` |

## InventoryGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| layoutMgr | layoutMgr | InventoryLayout | RW | `obj.layoutMgr = <value>` |
| ownerInventory | ownerInventory | InventoryGUI | RW | `obj.ownerInventory = <value>` |
| childInventory | childInventory | InventoryGUI | RW | `obj.childInventory = <value>` |
| mouseFocus | mouseFocus | boolean | RW | `obj.mouseFocus = <value>` |
| callbackObject | callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
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
| _NV_refreshSection | _NV_refreshSection | `` | `void` | `obj:_NV_refreshSection()` |
| showBackpack | showBackpack | `on: boolean` | `void` | `obj:showBackpack(on)` |
| getBackpack | getBackpack | `` | `ContainerItem` | `obj:getBackpack()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| hasSameOwner | hasSameOwner | `` | `boolean` | `obj:hasSameOwner()` |
| getCallbackCharacter | getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| _NV_getCallbackCharacter | _NV_getCallbackCharacter | `` | `Character` | `obj:_NV_getCallbackCharacter()` |
| getCallbackObject | getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _NV_getCallbackObject | _NV_getCallbackObject | `` | `RootObject` | `obj:_NV_getCallbackObject()` |
| getSelectedItem | getSelectedItem | `sectionName: string` | `Item` | `obj:getSelectedItem(sectionName)` |
| stealingGUIInfoUpdate | stealingGUIInfoUpdate | `` | `void` | `obj:stealingGUIInfoUpdate()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `InventoryGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| pickupItemToMouse | pickupItemToMouse | `sectionName: string` | `boolean` | `obj:pickupItemToMouse(sectionName)` |
| getMouseItem | getMouseItem | `` | `Item` | `obj:getMouseItem()` |
| takeCertainAmountFrom | takeCertainAmountFrom | `amount: integer` | `Item` | `obj:takeCertainAmountFrom(amount)` |
| RClickAutoTrade | RClickAutoTrade | `invSectionName: string, x: integer, y: integer, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTrade(invSectionName, x, y, thieveryChecks, first)` |
| RClickAutoTradeAll | RClickAutoTradeAll | `invSectionName: string, x: integer, y: integer, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTradeAll(invSectionName, x, y, thieveryChecks, first)` |
| isTradingForMoney | isTradingForMoney | `` | `boolean` | `obj:isTradingForMoney()` |
| isStealing | isStealing | `` | `boolean` | `obj:isStealing()` |
| isWithinRangeToTrade | isWithinRangeToTrade | `stealing: boolean` | `boolean` | `obj:isWithinRangeToTrade(stealing)` |
| setItemToPlayerPortrait | setItemToPlayerPortrait | `` | `boolean` | `obj:setItemToPlayerPortrait()` |
| playSound | playSound | `eventId: string` | `void` | `obj:playSound(eventId)` |
| fencingConfirmationCallback | fencingConfirmationCallback | `b: integer` | `void` | `obj:fencingConfirmationCallback(b)` |
| getPlayerTradeCharacter | getPlayerTradeCharacter | `` | `RootObject` | `obj:getPlayerTradeCharacter()` |
| refreshAllSections | refreshAllSections | `` | `void` | `obj:refreshAllSections()` |
| updateDatapanel | updateDatapanel | `` | `void` | `obj:updateDatapanel()` |
| rightClickAutoEquipping | rightClickAutoEquipping | `` | `void` | `obj:rightClickAutoEquipping()` |
| tryToEquip | tryToEquip | `replace: boolean` | `boolean` | `obj:tryToEquip(replace)` |
| returnItem | returnItem | `sectionName: string` | `void` | `obj:returnItem(sectionName)` |
| hasMouse | hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getSectionWithMouseLocal | getSectionWithMouseLocal | `` | `string` | `obj:getSectionWithMouseLocal()` |
| getSlotWithMouse | getSlotWithMouse | `` | `iVector2` | `obj:getSlotWithMouse()` |

## InventoryIcon
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| item | item | Item | RW | `obj.item = <value>` |
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
| manufacturerData | manufacturerData | GameData | RW | `obj.manufacturerData = <value>` |
| materialData | materialData | GameData | RW | `obj.materialData = <value>` |
| coloriseData | coloriseData | GameData | RW | `obj.coloriseData = <value>` |
| isInInventory | isInInventory | boolean | RW | `obj.isInInventory = <value>` |
| inventoryPos | inventoryPos | iVector2 | RW | `obj.inventoryPos = <value>` |
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
| properOwner | properOwner | unknown | RW | `obj.properOwner = <value>` |
| _whosInventoryWeAreIn | _whosInventoryWeAreIn | unknown | RW | `obj._whosInventoryWeAreIn = <value>` |
| _isResearchArtifact | _isResearchArtifact | boolean | RW | `obj._isResearchArtifact = <value>` |
| itemGroup | (void* | lightuserdata | R | `obj.itemGroup` |

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
| _serialise | _serialise | `_a2: integer` | `GameData` | `obj:_serialise(_a2)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| serialiseInInventory | serialiseInInventory | `` | `GameData` | `obj:serialiseInInventory()` |
| loadFromSerialiseInInventory | loadFromSerialiseInInventory | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| getAvgPrice | getAvgPrice | `` | `integer` | `obj:getAvgPrice()` |
| getValueSingle | getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| getValueAll | getValueAll | `isPlayer: boolean` | `integer` | `obj:getValueAll(isPlayer)` |
| _NV_getValueAll | _NV_getValueAll | `isPlayer: boolean` | `integer` | `obj:_NV_getValueAll(isPlayer)` |
| getMaxAffordableNum | getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:getMaxAffordableNum(cashLimit, isPlayer)` |
| _NV_getMaxAffordableNum | _NV_getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:_NV_getMaxAffordableNum(cashLimit, isPlayer)` |
| isStackable | isStackable | `` | `integer` | `obj:isStackable()` |
| canStackWith | canStackWith | `` | `boolean` | `obj:canStackWith()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| isSameAs | isSameAs | `` | `boolean` | `obj:isSameAs()` |
| _NV_isSameAs | _NV_isSameAs | `` | `boolean` | `obj:_NV_isSameAs()` |
| onGround | onGround | `` | `boolean` | `obj:onGround()` |
| isResearchArtifact | isResearchArtifact | `` | `boolean` | `obj:isResearchArtifact()` |
| getLevel | getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| getItemSound | getItemSound | `` | `lightuserdata` | `obj:getItemSound()` |
| isStolen | isStolen | `includeUnknown: boolean` | `boolean` | `obj:isStolen(includeUnknown)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `InventoryItemBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| merchantPriceMod | merchantPriceMod | `` | `number` | `obj:merchantPriceMod()` |

## InventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| datapanel | datapanel | DatapanelGUI | RW | `obj.datapanel = <value>` |
| dataPanelInfos | dataPanelInfos | GameDataCopyStandalone | RW | `obj.dataPanelInfos = <value>` |
| window | (void* | lightuserdata | R | `obj.window` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `file: string` | `InventoryLayout` | `obj:_CONSTRUCTOR(file)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWindow | getWindow | `` | `lightuserdata` | `obj:getWindow()` |
| getWidget | getWidget | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| getDatapanel | getDatapanel | `` | `DatapanelGUI` | `obj:getDatapanel()` |
| _NV_getDatapanel | _NV_getDatapanel | `` | `DatapanelGUI` | `obj:_NV_getDatapanel()` |
| setupDataPanelInfos | setupDataPanelInfos | `name: string` | `void` | `obj:setupDataPanelInfos(name)` |
| createSectionGUI | createSectionGUI | `` | `InventorySectionGUI` | `obj:createSectionGUI()` |
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
| stackingBonusMin | stackingBonusMin | integer | RW | `obj.stackingBonusMin = <value>` |
| stackingBonusMult | stackingBonusMult | number | RW | `obj.stackingBonusMult = <value>` |
| itemsLimit | itemsLimit | integer | RW | `obj.itemsLimit = <value>` |
| weightMultiplier | weightMultiplier | number | RW | `obj.weightMultiplier = <value>` |
| totalWeight | totalWeight | number | RW | `obj.totalWeight = <value>` |
| isAnEquippedItemSection | isAnEquippedItemSection | boolean | RW | `obj.isAnEquippedItemSection = <value>` |
| limitedSlot | (lua_Integer | integer | RW | `obj.limitedSlot = <value>` |
| containerSlot | containerSlot | boolean | RW | `obj.containerSlot = <value>` |
| callbackObject | callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
| parentInventory | parentInventory | Inventory | RW | `obj.parentInventory = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |
| content | content | Array2d<Item> | R | `obj.content` |
| items | items | Ogre::vector<InventorySection::SectionItem>::type | R | `obj.items` |
| veryLimitedSlot | veryLimitedSlot | lektor<GameData*> | R | `obj.veryLimitedSlot` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `_name: string, _w: integer, _h: integer, slot: integer, _containerSlot: boolean, _equipSlot: boolean, enabled: boolean` | `InventorySection` | `obj:_CONSTRUCTOR(_name, _w, _h, slot, _containerSlot, _equipSlot, enabled)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| hasRoomForItem | hasRoomForItem | `quantity: integer` | `boolean` | `obj:hasRoomForItem(quantity)` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `quantity: integer` | `boolean` | `obj:_NV_hasRoomForItem(quantity)` |
| notifyModified | notifyModified | `` | `void` | `obj:notifyModified()` |
| addItem | addItem | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |
| _NV_addItem | _NV_addItem | `quantity: integer` | `boolean` | `obj:_NV_addItem(quantity)` |
| _addItem | _addItem | `x: integer, y: integer` | `void` | `obj:_addItem(x, y)` |
| _NV__addItem | _NV__addItem | `x: integer, y: integer` | `void` | `obj:_NV__addItem(x, y)` |
| getItemAt | getItemAt | `x: integer, y: integer` | `Item` | `obj:getItemAt(x, y)` |
| hasItemType | hasItemType | `type: integer` | `boolean` | `obj:hasItemType(type)` |
| autoArrange | autoArrange | `` | `void` | `obj:autoArrange()` |
| _NV_autoArrange | _NV_autoArrange | `` | `void` | `obj:_NV_autoArrange()` |
| getNumItems | getNumItems | `` | `integer` | `obj:getNumItems()` |
| isEmpty | isEmpty | `` | `boolean` | `obj:isEmpty()` |
| removeItem | removeItem | `` | `boolean` | `obj:removeItem()` |
| clearAllItems | clearAllItems | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAllItems(destroy, skipUnique)` |
| canItemGoHere | canItemGoHere | `x: integer, y: integer` | `boolean` | `obj:canItemGoHere(x, y)` |
| existsItemInFootprint | existsItemInFootprint | `x: integer, y: integer` | `boolean` | `obj:existsItemInFootprint(x, y)` |
| getLimitedSlot | getLimitedSlot | `` | `integer` | `obj:getLimitedSlot()` |
| setupContainerData | setupContainerData | `` | `void` | `obj:setupContainerData()` |
| applyStackingBonuses | applyStackingBonuses | `normalStackableAmount: integer` | `integer` | `obj:applyStackingBonuses(normalStackableAmount)` |
| recalculateTotalWeight | recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| setWeightMultiplier | setWeightMultiplier | `mult: number` | `void` | `obj:setWeightMultiplier(mult)` |
| setStackingBonus | setStackingBonus | `minn: integer, mult: number` | `void` | `obj:setStackingBonus(minn, mult)` |
| getMaxStack | getMaxStack | `` | `integer` | `obj:getMaxStack()` |
| addVeryLimitedSlot | addVeryLimitedSlot | `` | `void` | `obj:addVeryLimitedSlot()` |
| clearVeryLimitedSlot | clearVeryLimitedSlot | `` | `void` | `obj:clearVeryLimitedSlot()` |
| getEnabled | getEnabled | `` | `boolean` | `obj:getEnabled()` |
| setEnabled | setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| setItemsLimitCount | setItemsLimitCount | `value: integer` | `void` | `obj:setItemsLimitCount(value)` |
| getItemsLimitReached | getItemsLimitReached | `` | `boolean` | `obj:getItemsLimitReached()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| getFillPercentage | getFillPercentage | `` | `number` | `obj:getFillPercentage()` |
| getItem | getItem | `` | `Item` | `obj:getItem()` |
| setupEquipCallbacks | setupEquipCallbacks | `` | `void` | `obj:setupEquipCallbacks()` |
| numItemsInFootprint | numItemsInFootprint | `x: integer, y: integer` | `integer` | `obj:numItemsInFootprint(x, y)` |
| resize | resize | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resize(w, h, clearContent)` |
| hasItem | hasItem_Item | `` | `boolean` | `obj:hasItem()` |
| hasItem | hasItem_GameData | `` | `boolean` | `obj:hasItem()` |
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
| refreshIcons | refreshIcons | `` | `void` | `obj:refreshIcons()` |
| update | update | `` | `void` | `obj:update()` |

## InventoryTradeData
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| inventory | inventory | InventoryGUI | RW | `obj.inventory = <value>` |
| paymentRequired | paymentRequired | boolean | RW | `obj.paymentRequired = <value>` |
| canDropItems | canDropItems | boolean | RW | `obj.canDropItems = <value>` |
| isPlayer | isPlayer | boolean | RW | `obj.isPlayer = <value>` |
| owner | owner | unknown | RW | `obj.owner = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isValid | isValid | `` | `boolean` | `obj:isValid()` |

## InventoryTraderGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| sectionWidth | sectionWidth | integer | RW | `obj.sectionWidth = <value>` |
| sectionHeight | sectionHeight | integer | RW | `obj.sectionHeight = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| getCallbackCharacter | getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| _NV_getCallbackCharacter | _NV_getCallbackCharacter | `` | `Character` | `obj:_NV_getCallbackCharacter()` |
| getCallbackObject | getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _NV_getCallbackObject | _NV_getCallbackObject | `` | `RootObject` | `obj:_NV_getCallbackObject()` |
| refreshSection | refreshSection | `` | `void` | `obj:refreshSection()` |
| _NV_refreshSection | _NV_refreshSection | `` | `void` | `obj:_NV_refreshSection()` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| physicalShouldExist | physicalShouldExist | boolean | RW | `obj.physicalShouldExist = <value>` |
| existAsBareWeapon | existAsBareWeapon | boolean | RW | `obj.existAsBareWeapon = <value>` |
| persistant | persistant | unknown | RW | `obj.persistant = <value>` |
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
| getEntity | getEntity | `` | `lightuserdata` | `obj:getEntity()` |
| _NV_getEntity | _NV_getEntity | `` | `lightuserdata` | `obj:_NV_getEntity()` |
| getTimeout | getTimeout | `` | `TimeOfDay` | `obj:getTimeout()` |
| _NV_getTimeout | _NV_getTimeout | `` | `TimeOfDay` | `obj:_NV_getTimeout()` |
| _serialise | _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| serialiseInInventory | serialiseInInventory | `` | `GameData` | `obj:serialiseInInventory()` |
| _NV_serialiseInInventory | _NV_serialiseInInventory | `` | `GameData` | `obj:_NV_serialiseInInventory()` |
| loadFromSerialiseInInventory | loadFromSerialiseInInventory | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| _NV_loadFromSerialiseInInventory | _NV_loadFromSerialiseInInventory | `` | `void` | `obj:_NV_loadFromSerialiseInInventory()` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Item` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| loadUnloadCheck | loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| getInventoryWeAreIn | getInventoryWeAreIn | `` | `void` | `obj:getInventoryWeAreIn()` |
| setInventoryWeAreIn | setInventoryWeAreIn | `` | `void` | `obj:setInventoryWeAreIn()` |
| _NV_setInventoryWeAreIn | _NV_setInventoryWeAreIn | `` | `void` | `obj:_NV_setInventoryWeAreIn()` |
| isFood | isFood | `` | `boolean` | `obj:isFood()` |
| activate | activate | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| _NV_activate | _NV_activate | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:_NV_activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| serialise | serialise | `offset: userdata` | `GameSaveState` | `obj:serialise(offset)` |
| _NV_serialise | _NV_serialise | `offset: userdata` | `GameSaveState` | `obj:_NV_serialise(offset)` |
| createItemEntityCallback_Equipping | createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:createItemEntityCallback_Equipping(ent, node)` |
| _NV_createItemEntityCallback_Equipping | _NV_createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:_NV_createItemEntityCallback_Equipping(ent, node)` |
| notifyTheftFrom | notifyTheftFrom | `` | `void` | `obj:notifyTheftFrom()` |
| _NV_notifyTheftFrom | _NV_notifyTheftFrom | `` | `void` | `obj:_NV_notifyTheftFrom()` |
| findProperOwner | findProperOwner | `` | `hand` | `obj:findProperOwner()` |
| setPersistant | setPersistant | `p: boolean` | `void` | `obj:setPersistant(p)` |
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

## ItemListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |

## LevelEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| levelEditModeOn | levelEditModeOn | boolean | RW | `obj.levelEditModeOn = <value>` |
| panel | (void* | lightuserdata | R | `obj.panel` |
| interiorModeWindow | (void* | lightuserdata | R | `obj.interiorModeWindow` |
| selectedLocked | selectedLocked | integer | RW | `obj.selectedLocked = <value>` |
| selectedObject | selectedObject | unknown | RW | `obj.selectedObject = <value>` |
| selectedFeature | (void* | lightuserdata | R | `obj.selectedFeature` |
| seedMode | seedMode | integer | RW | `obj.seedMode = <value>` |
| roadMode | roadMode | integer | RW | `obj.roadMode = <value>` |
| roadIndex | roadIndex | integer | RW | `obj.roadIndex = <value>` |
| roadMarker | (void* | lightuserdata | R | `obj.roadMarker` |
| roadMakerMO | (void* | lightuserdata | R | `obj.roadMakerMO` |
| foliageEraser | (void* | lightuserdata | R | `obj.foliageEraser` |
| fogEditor | fogEditor | FogEditor | RW | `obj.fogEditor = <value>` |
| townListWindow | (void* | lightuserdata | R | `obj.townListWindow` |
| factionListWindow | (void* | lightuserdata | R | `obj.factionListWindow` |
| squadListWindow | (void* | lightuserdata | R | `obj.squadListWindow` |
| npcListWindow | (void* | lightuserdata | R | `obj.npcListWindow` |
| featureListWindow | (void* | lightuserdata | R | `obj.featureListWindow` |
| itemListWindow | (void* | lightuserdata | R | `obj.itemListWindow` |
| navmeshWindow | navmeshWindow | DatapanelGUI | RW | `obj.navmeshWindow = <value>` |
| editMapTitleWindow | (void* | lightuserdata | R | `obj.editMapTitleWindow` |
| factionTxt | (void* | lightuserdata | R | `obj.factionTxt` |
| altitudeTxt | (void* | lightuserdata | R | `obj.altitudeTxt` |
| activeModTxt | (void* | lightuserdata | R | `obj.activeModTxt` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| close | close | `` | `void` | `obj:close()` |
| update | update | `` | `void` | `obj:update()` |
| updateGizmo | updateGizmo | `` | `boolean` | `obj:updateGizmo()` |
| levelEditMode | levelEditMode | `on: boolean` | `void` | `obj:levelEditMode(on)` |
| isInteriorEditMode | isInteriorEditMode | `` | `boolean` | `obj:isInteriorEditMode()` |
| getActiveModIndex | getActiveModIndex | `` | `integer` | `obj:getActiveModIndex()` |
| getActiveMod | getActiveMod | `` | `string` | `obj:getActiveMod()` |
| isBaseActive | isBaseActive | `` | `boolean` | `obj:isBaseActive()` |
| setEditSquad | setEditSquad | `` | `void` | `obj:setEditSquad()` |
| repath | repath | `` | `void` | `obj:repath()` |
| toggleSeedMode | toggleSeedMode | `` | `void` | `obj:toggleSeedMode()` |
| clearSeedPoints | clearSeedPoints | `` | `void` | `obj:clearSeedPoints()` |
| setSeedMode | setSeedMode | `mode: integer` | `void` | `obj:setSeedMode(mode)` |
| toggleRoadEditor | toggleRoadEditor | `tab: integer` | `void` | `obj:toggleRoadEditor(tab)` |
| toggleFoliageRemoval | toggleFoliageRemoval | `` | `void` | `obj:toggleFoliageRemoval()` |
| clearChanges | clearChanges | `` | `boolean` | `obj:clearChanges()` |
| deleteDuplicateBuildings | deleteDuplicateBuildings | `` | `integer` | `obj:deleteDuplicateBuildings()` |
| fixMountedBuildings | fixMountedBuildings | `` | `integer` | `obj:fixMountedBuildings()` |
| deleteAll | deleteAll | `confirmed: boolean` | `integer` | `obj:deleteAll(confirmed)` |
| adjustAltitudeSpeed | adjustAltitudeSpeed | `s: number` | `void` | `obj:adjustAltitudeSpeed(s)` |
| fixInvalidInteriorFurnitureStates | fixInvalidInteriorFurnitureStates | `` | `integer` | `obj:fixInvalidInteriorFurnitureStates()` |
| fixBuildingFloorState | fixBuildingFloorState | `` | `boolean` | `obj:fixBuildingFloorState()` |
| setSelectedObject | setSelectedObject | `` | `void` | `obj:setSelectedObject()` |
| updateRoadEditor | updateRoadEditor | `` | `void` | `obj:updateRoadEditor()` |
| setRoadWidth | setRoadWidth | `` | `void` | `obj:setRoadWidth()` |
| setRoadHidden | setRoadHidden | `` | `void` | `obj:setRoadHidden()` |
| drawRoads | drawRoads | `` | `void` | `obj:drawRoads()` |
| eraseRoads | eraseRoads | `` | `void` | `obj:eraseRoads()` |
| drawAllRoads | drawAllRoads | `` | `void` | `obj:drawAllRoads()` |
| projectRoads | projectRoads | `` | `void` | `obj:projectRoads()` |
| validateRoads | validateRoads | `` | `void` | `obj:validateRoads()` |
| createRoadMarker | createRoadMarker | `` | `void` | `obj:createRoadMarker()` |
| destroyRoadMaker | destroyRoadMaker | `` | `void` | `obj:destroyRoadMaker()` |
| updateFoliageRemoval | updateFoliageRemoval | `` | `void` | `obj:updateFoliageRemoval()` |
| updateSeedEditor | updateSeedEditor | `` | `void` | `obj:updateSeedEditor()` |

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

## LightEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| light | (void* | lightuserdata | R | `obj.light` |
| brightness | brightness | number | RW | `obj.brightness = <value>` |
| range | range | number | RW | `obj.range = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setEnergyLevel | setEnergyLevel | `level: number` | `void` | `obj:setEnergyLevel(level)` |
| setFloor | setFloor | `floor: integer` | `void` | `obj:setFloor(floor)` |

## LimbsInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| character | character | Character | RW | `obj.character = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `LimbsInventoryLayout` | `obj:_CONSTRUCTOR()` |
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
| canEquip | canEquip | `isAnimal: boolean` | `boolean` | `obj:canEquip(isAnimal)` |
| _NV_canEquip | _NV_canEquip | `isAnimal: boolean` | `boolean` | `obj:_NV_canEquip(isAnimal)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Limiter` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ListScrollBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_ListScrollBar.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| disableEvents | disableEvents | boolean | RW | `obj.disableEvents = <value>` |
| mListName | (void* | lightuserdata | R | `obj.mListName` |
| mListValue | (void* | lightuserdata | R | `obj.mListValue` |
| mListIndex | (void* | lightuserdata | R | `obj.mListIndex` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setEnabled | setEnabled | `_a1: boolean` | `void` | `obj:setEnabled(_a1)` |
| initialiseOverride | initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | shutdownOverride | `` | `void` | `obj:shutdownOverride()` |

## Listener
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## LoadSaveWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| list | (void* | lightuserdata | R | `obj.list` |
| infoPanel | infoPanel | DatapanelGUI | RW | `obj.infoPanel = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `layout: string` | `lightuserdata` | `obj:_CONSTRUCTOR(layout)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| select | select | `index: integer` | `void` | `obj:select(index)` |
| _NV_select | _NV_select | `index: integer` | `void` | `obj:_NV_select(index)` |
| getWidget | getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| deleteSelectedSave | deleteSelectedSave | `mbResult: integer` | `void` | `obj:deleteSelectedSave(mbResult)` |
| addOption | addOption | `key: integer, check: string, label: string, caption: string` | `void` | `obj:addOption(key, check, label, caption)` |
| enableOption | enableOption | `key: integer, enabled: boolean` | `void` | `obj:enableOption(key, enabled)` |
| getOptions | getOptions | `` | `integer` | `obj:getOptions()` |

## LoadingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadingWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentIndex | currentIndex | integer | RW | `obj.currentIndex = <value>` |
| currentTime | currentTime | number | RW | `obj.currentTime = <value>` |
| loadingText | (void* | lightuserdata | R | `obj.loadingText` |
| messageText | (void* | lightuserdata | R | `obj.messageText` |
| backgroundImage | (void* | lightuserdata | R | `obj.backgroundImage` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| reload | reload | `` | `void` | `obj:reload()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| show | show | `` | `void` | `obj:show()` |
| hide | hide | `` | `void` | `obj:hide()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| frameEntered | frameEntered | `_frame: number` | `void` | `obj:frameEntered(_frame)` |
| setRandomBackground | setRandomBackground | `` | `void` | `obj:setRandomBackground()` |
| setRandomTip | setRandomTip | `` | `void` | `obj:setRandomTip()` |

## LockedArmour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lock | (void* | lightuserdata | R | `obj.lock` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `_level: integer` | `LockedArmour` | `obj:_CONSTRUCTOR(_level)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isArmour | isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| isLockedArmour | isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _NV_isLockedArmour | _NV_isLockedArmour | `` | `LockedArmour` | `obj:_NV_isLockedArmour()` |
| _serialise | _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |

## Logger
**Header:** `extern/KenshiLib/Include/kenshi/logger.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| init | init | `` | `void` | `obj:init()` |
| close | close | `` | `void` | `obj:close()` |
| logMessage | logMessage | `` | `void` | `obj:logMessage()` |
| logMessageDebug | logMessageDebug | `` | `void` | `obj:logMessageDebug()` |
| logHeader | logHeader | `` | `void` | `obj:logHeader()` |

## MainBarGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| closeManagerWindowMsg | closeManagerWindowMsg | integer | RW | `obj.closeManagerWindowMsg = <value>` |
| isLevelEditMode | isLevelEditMode | boolean | RW | `obj.isLevelEditMode = <value>` |
| isInteriorLevelEditMode | isInteriorLevelEditMode | boolean | RW | `obj.isInteriorLevelEditMode = <value>` |
| bountyPanel | bountyPanel | MyGUI::Widget | R | `obj.bountyPanel` |
| bountyDatapanel | bountyDatapanel | DatapanelGUI | RW | `obj.bountyDatapanel = <value>` |
| townPanel | (void* | lightuserdata | R | `obj.townPanel` |
| portraitsTabPanel | (MyGUI::Widget* | MyGUI::Widget | R | `obj.portraitsTabPanel` |
| floorDownButton | (MyGUI::Widget* | MyGUI::Widget | R | `obj.floorDownButton` |
| floorUpButton | (MyGUI::Widget* | MyGUI::Widget | R | `obj.floorUpButton` |
| floorText | (MyGUI::Widget* | MyGUI::Widget | R | `obj.floorText` |
| dayText | (MyGUI::Widget* | MyGUI::Widget | R | `obj.dayText` |
| moneyLabel | (MyGUI::Widget* | MyGUI::Widget | R | `obj.moneyLabel` |
| moneyText | (MyGUI::Widget* | MyGUI::Widget | R | `obj.moneyText` |
| timeText | (MyGUI::Widget* | MyGUI::Widget | R | `obj.timeText` |
| medicalPanel | (void* | lightuserdata | R | `obj.medicalPanel` |
| ordersDataPanel | ordersDataPanel | OrdersPanel | RW | `obj.ordersDataPanel = <value>` |
| extendInfoPanelButton | (MyGUI::Widget* | MyGUI::Widget | R | `obj.extendInfoPanelButton` |
| extendedInfoPanel | extendedInfoPanel | MyGUI::Widget | RW | `obj.extendedInfoPanel = <value>` |
| extendedInfoPanelDuration | extendedInfoPanelDuration | number | RW | `obj.extendedInfoPanelDuration = <value>` |
| infoPanelEnabled | infoPanelEnabled | boolean | RW | `obj.infoPanelEnabled = <value>` |
| infoPanelExtended | infoPanelExtended | boolean | RW | `obj.infoPanelExtended = <value>` |
| biomePanel | biomePanel | MyGUI::Widget | RW | `obj.biomePanel = <value>` |
| biomePanelText | (MyGUI::Widget* | MyGUI::Widget | R | `obj.biomePanelText` |
| biomePanelVisibleTimer | biomePanelVisibleTimer | number | RW | `obj.biomePanelVisibleTimer = <value>` |
| biomeTimer | biomeTimer | number | RW | `obj.biomeTimer = <value>` |
| lastFrameBiomeGroup | lastFrameBiomeGroup | GameData | RW | `obj.lastFrameBiomeGroup = <value>` |
| rememberlastBiomeGroup | rememberlastBiomeGroup | GameData | RW | `obj.rememberlastBiomeGroup = <value>` |
| portraitContextMenuTarget | portraitContextMenuTarget | unknown | RW | `obj.portraitContextMenuTarget = <value>` |
| portraitContextMenuTimer | portraitContextMenuTimer | number | RW | `obj.portraitContextMenuTimer = <value>` |
| portraitSelectedContextIndex | portraitSelectedContextIndex | integer | RW | `obj.portraitSelectedContextIndex = <value>` |
| portraitsUpdating | portraitsUpdating | boolean | RW | `obj.portraitsUpdating = <value>` |
| toolTip | toolTip | ToolTipFixed | RW | `obj.toolTip = <value>` |
| pausePanel | pausePanel | MyGUI::Widget | R | `obj.pausePanel` |
| loadingPanel | loadingPanel | MyGUI::Widget | R | `obj.loadingPanel` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `MainBarGUI` | `obj:_CONSTRUCTOR()` |
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
| platoonUpdated | platoonUpdated | `charAdded: boolean` | `void` | `obj:platoonUpdated(charAdded)` |
| updatePotraitsPlatoon | updatePotraitsPlatoon | `` | `void` | `obj:updatePotraitsPlatoon()` |
| updatePortraits | updatePortraits | `` | `void` | `obj:updatePortraits()` |
| refreshPortraitTabs | refreshPortraitTabs | `` | `void` | `obj:refreshPortraitTabs()` |
| updatePortraitSize | updatePortraitSize | `` | `void` | `obj:updatePortraitSize()` |
| getPausePanel | getPausePanel | `` | `MyGUI::Widget` | `obj:getPausePanel()` |
| getLoadingPanel | getLoadingPanel | `` | `MyGUI::Widget` | `obj:getLoadingPanel()` |
| getMedicalPanel | getMedicalPanel | `` | `lightuserdata` | `obj:getMedicalPanel()` |
| ordersPanelClear | ordersPanelClear | `` | `void` | `obj:ordersPanelClear()` |
| getToolTip | getToolTip | `` | `ToolTip` | `obj:getToolTip()` |
| _NV_getToolTip | _NV_getToolTip | `` | `ToolTip` | `obj:_NV_getToolTip()` |
| getDatapanel | getDatapanel | `id: string` | `DatapanelGUI` | `obj:getDatapanel(id)` |
| setMessagePosition | setMessagePosition | `` | `void` | `obj:setMessagePosition()` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| setExtendInfoPanelEnabled | setExtendInfoPanelEnabled | `enabled: boolean` | `void` | `obj:setExtendInfoPanelEnabled(enabled)` |
| _getWidget | _getWidget | `name: string` | `MyGUI::Widget` | `obj:_getWidget(name)` |
| autoChangeSelectedObject | autoChangeSelectedObject | `` | `void` | `obj:autoChangeSelectedObject()` |
| _NV_autoChangeSelectedObject | _NV_autoChangeSelectedObject | `` | `void` | `obj:_NV_autoChangeSelectedObject()` |
| getPortrait | getPortrait | `left: integer, top: integer` | `lightuserdata` | `obj:getPortrait(left, top)` |
| updatePortrait | updatePortrait | `` | `void` | `obj:updatePortrait()` |
| closeMapWindow | closeMapWindow | `` | `void` | `obj:closeMapWindow()` |
| toggleMapWindow | toggleMapWindow | `` | `void` | `obj:toggleMapWindow()` |
| toggleFactionWindow | toggleFactionWindow | `` | `void` | `obj:toggleFactionWindow()` |
| toggleTechWindow | toggleTechWindow | `` | `void` | `obj:toggleTechWindow()` |
| toggleCraftWindow | toggleCraftWindow | `` | `void` | `obj:toggleCraftWindow()` |
| toggleSquadWindow | toggleSquadWindow | `` | `void` | `obj:toggleSquadWindow()` |
| changeFloorButtonUp | changeFloorButtonUp | `` | `void` | `obj:changeFloorButtonUp()` |
| changeFloorButtonDown | changeFloorButtonDown | `` | `void` | `obj:changeFloorButtonDown()` |
| ordersPanelFill | ordersPanelFill | `` | `void` | `obj:ordersPanelFill()` |
| getBuildingInventoryPosition | getBuildingInventoryPosition | `` | `void` | `obj:getBuildingInventoryPosition()` |
| getTabPlatoonPortrait | getTabPlatoonPortrait | `idx: integer` | `MainTabPortraitPlatoon` | `obj:getTabPlatoonPortrait(idx)` |
| extendInfoPanel | extendInfoPanel | `_a2: integer, _a3: integer, arg4: integer` | `void` | `obj:extendInfoPanel(_a2, _a3, arg4)` |
| toggleInventory | toggleInventory | `` | `void` | `obj:toggleInventory()` |
| toggleStatsWindow | toggleStatsWindow | `` | `void` | `obj:toggleStatsWindow()` |
| toggleHelpWindow | toggleHelpWindow | `` | `void` | `obj:toggleHelpWindow()` |
| changeSpeed | changeSpeed | `` | `void` | `obj:changeSpeed()` |
| buildButton | buildButton | `` | `void` | `obj:buildButton()` |

## MainTabPortraitPlatoon
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| portraitBox | (void* | lightuserdata | R | `obj.portraitBox` |
| platoon | platoon | ActivePlatoon | RW | `obj.platoon = <value>` |
| tab | (MyGUI::Widget* | MyGUI::Widget | RW | `obj.tab = <value>` |
| tabIndex | tabIndex | integer | RW | `obj.tabIndex = <value>` |
| flashImage | (MyGUI::Widget* | MyGUI::Widget | R | `obj.flashImage` |
| flashing | flashing | integer | RW | `obj.flashing = <value>` |
| animationTime | animationTime | number | RW | `obj.animationTime = <value>` |
| currentAlpha | currentAlpha | number | RW | `obj.currentAlpha = <value>` |
| mainbar | mainbar | MainBarGUI | RW | `obj.mainbar = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| addTab | addTab | `visible: boolean` | `void` | `obj:addTab(visible)` |
| detach | detach | `` | `void` | `obj:detach()` |
| setFlash | setFlash | `flash: boolean` | `void` | `obj:setFlash(flash)` |
| update | update | `` | `void` | `obj:update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MainthreadStateReaderT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| swapMutex | swapMutex | unknown | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateBackDataCheck | updateBackDataCheck | `` | `boolean` | `obj:updateBackDataCheck()` |
| _NV_updateBackDataCheck | _NV_updateBackDataCheck | `` | `void` | `obj:_NV_updateBackDataCheck()` |
| getMainData | getMainData | `` | `void` | `obj:getMainData()` |
| getBackData | getBackData | `` | `void` | `obj:getBackData()` |

## ManagementScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| squadScreen | squadScreen | SquadManagementScreen | RW | `obj.squadScreen = <value>` |
| mapScreen | (void* | lightuserdata | R | `obj.mapScreen` |
| factionScreen | factionScreen | FactionsScreen | RW | `obj.factionScreen = <value>` |
| researchCategoriesListBox | (void* | lightuserdata | R | `obj.researchCategoriesListBox` |
| availableList | availableList | DatapanelGUI | RW | `obj.availableList = <value>` |
| info | info | DatapanelGUI | RW | `obj.info = <value>` |
| info2 | info2 | DatapanelGUI | RW | `obj.info2 = <value>` |
| techCategory | techCategory | string | RW | `obj.techCategory = <value>` |
| currentResearch | currentResearch | GameData | RW | `obj.currentResearch = <value>` |
| researchBenchMessage | (void* | lightuserdata | R | `obj.researchBenchMessage` |
| researchDescriptionUpdateRequest | researchDescriptionUpdateRequest | boolean | RW | `obj.researchDescriptionUpdateRequest = <value>` |
| lastResearchRate | lastResearchRate | number | RW | `obj.lastResearchRate = <value>` |
| todoList | (void* | lightuserdata | R | `obj.todoList` |
| craftingQueue | (void* | lightuserdata | R | `obj.craftingQueue` |
| messagesTextBox | (void* | lightuserdata | R | `obj.messagesTextBox` |
| messagesUpdated | messagesUpdated | boolean | RW | `obj.messagesUpdated = <value>` |
| messagesMutex | (void* | lightuserdata | R | `obj.messagesMutex` |
| messagesPlayerColor | messagesPlayerColor | string | RW | `obj.messagesPlayerColor = <value>` |
| messagesNPCColor | messagesNPCColor | string | RW | `obj.messagesNPCColor = <value>` |
| aiScreen | aiScreen | DatapanelGUI | RW | `obj.aiScreen = <value>` |
| aiToolTip | aiToolTip | ToolTip | RW | `obj.aiToolTip = <value>` |
| toolTip | toolTip | ToolTip | RW | `obj.toolTip = <value>` |
| window | (void* | lightuserdata | R | `obj.window` |
| tabs | (void* | lightuserdata | R | `obj.tabs` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| clear | clear | `` | `void` | `obj:clear()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | setVisible | `on: boolean, tab: integer` | `void` | `obj:setVisible(on, tab)` |
| getCurrentTab | getCurrentTab | `` | `integer` | `obj:getCurrentTab()` |
| getTab | getTab | `index: integer` | `lightuserdata` | `obj:getTab(index)` |
| getWidget | getWidget | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| refresh | refresh | `progress: number` | `void` | `obj:refresh(progress)` |
| refreshResearchList | refreshResearchList | `` | `void` | `obj:refreshResearchList()` |
| refreshResearchRate | refreshResearchRate | `` | `void` | `obj:refreshResearchRate()` |
| refreshDiplomacy | refreshDiplomacy | `` | `void` | `obj:refreshDiplomacy()` |
| refreshSquads | refreshSquads | `` | `void` | `obj:refreshSquads()` |
| refreshMap | refreshMap | `centerCamera: boolean` | `void` | `obj:refreshMap(centerCamera)` |
| showRoads | showRoads | `v: boolean` | `void` | `obj:showRoads(v)` |
| addSquadToMap | addSquadToMap | `` | `void` | `obj:addSquadToMap()` |
| removeSquadFromMap | removeSquadFromMap | `` | `void` | `obj:removeSquadFromMap()` |
| resetSquads | resetSquads | `` | `void` | `obj:resetSquads()` |
| refreshMessages | refreshMessages | `` | `void` | `obj:refreshMessages()` |
| refreshAI | refreshAI | `` | `void` | `obj:refreshAI()` |
| showDebugMarker | showDebugMarker | `p: Vector3` | `void` | `obj:showDebugMarker(p)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| updateResearchListRate | updateResearchListRate | `` | `void` | `obj:updateResearchListRate()` |
| refreshResearchListDescription | refreshResearchListDescription | `` | `void` | `obj:refreshResearchListDescription()` |

## MapMarkerCharacter
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| handle | handle | unknown | RW | `obj.handle = <value>` |
| image | (void* | lightuserdata | R | `obj.image` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |

## MapMarkerTown
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| handle | handle | unknown | RW | `obj.handle = <value>` |
| zoomLayer | (lua_Integer | integer | RW | `obj.zoomLayer = <value>` |
| root | (void* | lightuserdata | R | `obj.root` |
| image | (void* | lightuserdata | R | `obj.image` |
| label | (void* | lightuserdata | R | `obj.label` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |

## MapScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| updateTimer | updateTimer | number | RW | `obj.updateTimer = <value>` |
| toolTip | toolTip | ToolTip | RW | `obj.toolTip = <value>` |
| mainWidget | (void* | lightuserdata | R | `obj.mainWidget` |
| mapScrollView | (void* | lightuserdata | R | `obj.mapScrollView` |
| mapImage | (void* | lightuserdata | R | `obj.mapImage` |
| cameraMarker | (void* | lightuserdata | R | `obj.cameraMarker` |
| cameraMarkerSkin | (void* | lightuserdata | R | `obj.cameraMarkerSkin` |
| zoomUpdated | zoomUpdated | boolean | RW | `obj.zoomUpdated = <value>` |
| zoomValueBase | zoomValueBase | number | RW | `obj.zoomValueBase = <value>` |
| zoomValueMax | zoomValueMax | number | RW | `obj.zoomValueMax = <value>` |
| zoomValueCurrent | zoomValueCurrent | number | RW | `obj.zoomValueCurrent = <value>` |
| zoomLevelCurrent | (lua_Integer | integer | RW | `obj.zoomLevelCurrent = <value>` |
| mapOverlaysContainer | (void* | lightuserdata | R | `obj.mapOverlaysContainer` |
| zoomLevels | zoomLevels | number | RW | `obj.zoomLevels = <value>` |
| mapMarkerMovement | (void* | lightuserdata | RW | `obj.mapMarkerMovement = <value>` |
| mapMarkerMovementPosition | mapMarkerMovementPosition | Vector3 | RW | `obj.mapMarkerMovementPosition = <value>` |
| mapMarkerMovementFadeOutDelay | mapMarkerMovementFadeOutDelay | number | RW | `obj.mapMarkerMovementFadeOutDelay = <value>` |
| mapDragging | mapDragging | boolean | RW | `obj.mapDragging = <value>` |
| mapMouseLastPosition | mapMouseLastPosition | unknown | RW | `obj.mapMouseLastPosition = <value>` |
| mapOffsetView | mapOffsetView | unknown | RW | `obj.mapOffsetView = <value>` |
| worldSize | worldSize | unknown | RW | `obj.worldSize = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| centerCamera | centerCamera | `` | `void` | `obj:centerCamera()` |
| clearTempMarkers | clearTempMarkers | `` | `void` | `obj:clearTempMarkers()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| update | update | `` | `void` | `obj:update()` |
| addSquad | addSquad | `` | `void` | `obj:addSquad()` |
| removeSquad | removeSquad | `` | `void` | `obj:removeSquad()` |
| hide | hide | `` | `void` | `obj:hide()` |
| setMovementMarker | setMovementMarker | `p: Vector3, time: number` | `void` | `obj:setMovementMarker(p, time)` |
| showRoads | showRoads | `on: boolean` | `void` | `obj:showRoads(on)` |
| updateZoom | updateZoom | `` | `void` | `obj:updateZoom()` |
| updateCameraMarker | updateCameraMarker | `` | `void` | `obj:updateCameraMarker()` |
| refreshTowns | refreshTowns | `` | `void` | `obj:refreshTowns()` |
| refreshSquads | refreshSquads | `` | `void` | `obj:refreshSquads()` |
| updateCharacterMarker | updateCharacterMarker | `` | `void` | `obj:updateCharacterMarker()` |
| getMouseWorldPosition | getMouseWorldPosition | `position: Vector3` | `boolean` | `obj:getMouseWorldPosition(position)` |
| setupRoads | setupRoads | `` | `void` | `obj:setupRoads()` |
| updateRoads | updateRoads | `` | `void` | `obj:updateRoads()` |

## MedianFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isPositionsFilter | isPositionsFilter | boolean | RW | `obj.isPositionsFilter = <value>` |
| edgeSkips | edgeSkips | integer | RW | `obj.edgeSkips = <value>` |
| maxLength | maxLength | integer | RW | `obj.maxLength = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `MedianFilter` | `obj:_CONSTRUCTOR()` |
| setup | setup | `numFrames: integer, numSamples: integer, _isPositionsFilter: boolean` | `void` | `obj:setup(numFrames, numSamples, _isPositionsFilter)` |
| reset | reset | `` | `void` | `obj:reset()` |
| applySilent | applySilent | `delta_mouse_x: number` | `void` | `obj:applySilent(delta_mouse_x)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedianFilter2DVector
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| filters | filters | unknown | RW | `obj.filters = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `MedianFilter2DVector` | `obj:_CONSTRUCTOR()` |
| setup | setup | `numFrames: integer, numSamples: integer, positions: boolean` | `void` | `obj:setup(numFrames, numSamples, positions)` |
| reset | reset | `` | `void` | `obj:reset()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| status | status | unknown | RW | `obj.status = <value>` |
| armourList | armourList | lektor<Armour*> | RW | `obj.armourList = <value>` |
| hunger | hunger | number | RW | `obj.hunger = <value>` |
| fed | fed | number | RW | `obj.fed = <value>` |
| lastPeriodicUpdate | lastPeriodicUpdate | TimeOfDay | RW | `obj.lastPeriodicUpdate = <value>` |
| blood | blood | number | RW | `obj.blood = <value>` |
| extraBloodLossFromBodyparts | extraBloodLossFromBodyparts | number | RW | `obj.extraBloodLossFromBodyparts = <value>` |
| currentBleedRate | currentBleedRate | number | RW | `obj.currentBleedRate = <value>` |
| leftLeg | leftLeg | MedicalSystem::HealthPartStatus | RW | `obj.leftLeg = <value>` |
| rightLeg | rightLeg | MedicalSystem::HealthPartStatus | RW | `obj.rightLeg = <value>` |
| leftArm | leftArm | MedicalSystem::HealthPartStatus | RW | `obj.leftArm = <value>` |
| rightArm | rightArm | MedicalSystem::HealthPartStatus | RW | `obj.rightArm = <value>` |
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
| robotLimbs | robotLimbs | RobotLimbs | RW | `obj.robotLimbs = <value>` |
| bloodynessChanged | bloodynessChanged | boolean | RW | `obj.bloodynessChanged = <value>` |
| bloodynessCleanedUp | bloodynessCleanedUp | boolean | RW | `obj.bloodynessCleanedUp = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
| weatherGUIfeedback | weatherGUIfeedback | StringPair | RW | `obj.weatherGUIfeedback = <value>` |
| currentWeatherAffect | (lua_Integer | integer | RW | `obj.currentWeatherAffect = <value>` |
| currentWeatherAffectStrength | currentWeatherAffectStrength | number | RW | `obj.currentWeatherAffectStrength = <value>` |
| lastHungerKO | lastHungerKO | TimeOfDay | RW | `obj.lastHungerKO = <value>` |
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
| anatomy | anatomy | lektor<MedicalSystem::HealthPartStatus*> | RW | `obj.anatomy = <value>` |
| stats | stats | CharStats | RW | `obj.stats = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| precalculateFirstAidNeedScore | precalculateFirstAidNeedScore | `` | `void` | `obj:precalculateFirstAidNeedScore()` |
| scoreFirstAidNeed | scoreFirstAidNeed | `robotAid: boolean` | `number` | `obj:scoreFirstAidNeed(robotAid)` |
| scoreJuryRigNeed | scoreJuryRigNeed | `skills: number` | `number` | `obj:scoreJuryRigNeed(skills)` |
| isFullyRested | isFullyRested | `` | `boolean` | `obj:isFullyRested()` |
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
| knockout | knockout | `skill: number` | `void` | `obj:knockout(skill)` |
| knockoutForceTimer | knockoutForceTimer | `seconds: number` | `void` | `obj:knockoutForceTimer(seconds)` |
| pointOfCollapseBloodloss | pointOfCollapseBloodloss | `` | `number` | `obj:pointOfCollapseBloodloss()` |
| pointOfNoReturn | pointOfNoReturn | `` | `number` | `obj:pointOfNoReturn()` |
| isHungerKO | isHungerKO | `` | `boolean` | `obj:isHungerKO()` |
| getToughnessXpBonus | getToughnessXpBonus | `` | `number` | `obj:getToughnessXpBonus()` |
| getHungerSpeedModifier | getHungerSpeedModifier | `` | `number` | `obj:getHungerSpeedModifier()` |
| getMissingArmPenaltyMult | getMissingArmPenaltyMult | `` | `number` | `obj:getMissingArmPenaltyMult()` |
| getDerivedHeadHealth | getDerivedHeadHealth | `` | `number` | `obj:getDerivedHeadHealth()` |
| calculateDesiredPainAnimations | calculateDesiredPainAnimations | `` | `void` | `obj:calculateDesiredPainAnimations()` |
| getMovementSpeedInjuryMultiplier | getMovementSpeedInjuryMultiplier | `` | `number` | `obj:getMovementSpeedInjuryMultiplier()` |
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
| isRightArmOk | isRightArmOk | `` | `boolean` | `obj:isRightArmOk()` |
| isLeftArmOk | isLeftArmOk | `` | `boolean` | `obj:isLeftArmOk()` |
| canIkick | canIkick | `` | `boolean` | `obj:canIkick()` |
| isInBloodlossTrauma | isInBloodlossTrauma | `` | `boolean` | `obj:isInBloodlossTrauma()` |
| clearWeatherEffects | clearWeatherEffects | `` | `void` | `obj:clearWeatherEffects()` |
| getWeatherStatPenaltyMult | getWeatherStatPenaltyMult | `` | `number` | `obj:getWeatherStatPenaltyMult()` |
| getWeatherStatPenalty | getWeatherStatPenalty | `mult: number` | `integer` | `obj:getWeatherStatPenalty(mult)` |
| calculateBleedRateForFX | calculateBleedRateForFX | `` | `number` | `obj:calculateBleedRateForFX()` |
| _setHealth | _setHealth | `` | `void` | `obj:_setHealth()` |
| getLimbState | getLimbState | `` | `void` | `obj:getLimbState()` |
| getPart | getPart | `` | `void` | `obj:getPart()` |
| addArmour | addArmour | `` | `void` | `obj:addArmour()` |
| removeArmour | removeArmour | `` | `void` | `obj:removeArmour()` |
| wearingUniformOf | wearingUniformOf | `` | `void` | `obj:wearingUniformOf()` |
| applyFirstAid | applyFirstAid | `` | `void` | `obj:applyFirstAid()` |
| applyDoctoring | applyDoctoring | `` | `void` | `obj:applyDoctoring()` |
| applyRigging | applyRigging | `` | `void` | `obj:applyRigging()` |

## MeshDataLookup
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| verts | (void* | lightuserdata | RW | `obj.verts = <value>` |
| uvs | (void* | lightuserdata | RW | `obj.uvs = <value>` |

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

## MessageBoxManager
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`

## MessageChain
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| flush | flush | `` | `boolean` | `obj:flush()` |

## MessageQueue
**Header:** `extern/KenshiLib/Include/kenshi/navmesh.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| s | s | integer | RW | `obj.s = <value>` |
| root | (void* | lightuserdata | R | `obj.root` |
| split | (void* | lightuserdata | R | `obj.split` |
| back | (void* | lightuserdata | R | `obj.back` |
| mutex | (lua_Integer | integer | RW | `obj.mutex = <value>` |

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

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `length: integer, weight_modifier: number, fill: number` | `MotionFilter` | `obj:_CONSTRUCTOR(length, weight_modifier, fill)` |
| SetHistoryBufferLength | SetHistoryBufferLength | `length: integer, fill: number` | `boolean` | `obj:SetHistoryBufferLength(length, fill)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MultiSlider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_MultiSlider.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mName | (void* | lightuserdata | R | `obj.mName` |
| mDisableEvents | mDisableEvents | boolean | RW | `obj.mDisableEvents = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| initialiseOverride | initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | shutdownOverride | `` | `void` | `obj:shutdownOverride()` |

## MustEndWithSemiColon
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

## MyGUI
For full widget creation, layout loading, property access, and event handling reference, see the dedicated [MyGUI Bindings Documentation](MyGUI_Bindings.md).

## NavMesh
**Header:** `extern/KenshiLib/Include/kenshi/navmesh.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| world | (void* | lightuserdata | RW | `obj.world = <value>` |
| shiftMutex | shiftMutex | lightuserdata | R | `obj.shiftMutex` |
| worldShiftEnabled | worldShiftEnabled | boolean | RW | `obj.worldShiftEnabled = <value>` |
| running | running | boolean | RW | `obj.running = <value>` |
| worldX | worldX | number | RW | `obj.worldX = <value>` |
| worldY | worldY | number | RW | `obj.worldY = <value>` |
| cellSize | cellSize | number | RW | `obj.cellSize = <value>` |
| worldShift | (void* | lightuserdata | RW | `obj.worldShift = <value>` |
| mutex | mutex | lightuserdata | R | `obj.mutex` |
| changeMutex | changeMutex | lightuserdata | R | `obj.changeMutex` |
| edgeFilter | (void* | lightuserdata | R | `obj.edgeFilter` |
| generator | (void* | lightuserdata | R | `obj.generator` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| initialise | initialise | `` | `void` | `obj:initialise()` |
| shutdown | shutdown | `` | `void` | `obj:shutdown()` |
| create | create | `` | `void` | `obj:create()` |
| unload | unload | `` | `void` | `obj:unload()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| getZoneEdge | getZoneEdge | `start: Vector3, target: Vector3, offset: number` | `Vector3` | `obj:getZoneEdge(start, target, offset)` |
| getClosestExteriorPoint | getClosestExteriorPoint | `point: Vector3, radius: number, inset: number, out: Vector3` | `integer` | `obj:getClosestExteriorPoint(point, radius, inset, out)` |
| setDoorState | setDoorState | `open: boolean` | `void` | `obj:setDoorState(open)` |
| isInterior | isInterior | `key: integer` | `boolean` | `obj:isInterior(key)` |
| getPositionValid | getPositionValid | `point: Vector3` | `boolean` | `obj:getPositionValid(point)` |
| processCompletedCharacterMessages | processCompletedCharacterMessages | `` | `void` | `obj:processCompletedCharacterMessages()` |
| processDoorRequests | processDoorRequests | `` | `void` | `obj:processDoorRequests()` |
| getPolygonID | getPolygonID | `p: Vector3` | `string` | `obj:getPolygonID(p)` |
| validateFaceKey | validateFaceKey | `key: integer` | `boolean` | `obj:validateFaceKey(key)` |
| isGenerating | isGenerating | `` | `boolean` | `obj:isGenerating()` |
| getWorldShift | getWorldShift | `` | `Vector3` | `obj:getWorldShift()` |
| threadProc | threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| update | update | `` | `boolean` | `obj:update()` |
| setupHavok | setupHavok | `` | `void` | `obj:setupHavok()` |
| shutdownHavok | shutdownHavok | `` | `void` | `obj:shutdownHavok()` |
| loadZone | loadZone | `` | `void` | `obj:loadZone()` |
| unloadZone | unloadZone | `` | `void` | `obj:unloadZone()` |
| unloadBuilding | unloadBuilding | `` | `void` | `obj:unloadBuilding()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMeshGenerator
**Header:** `extern/KenshiLib/Include/kenshi/navmeshgenerator.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| queue | queue | lightuserdata | R | `obj.queue` |
| done | done | lightuserdata | R | `obj.done` |
| current | (void* | lightuserdata | R | `obj.current` |
| navmesh | (void* | lightuserdata | R | `obj.navmesh` |
| needSave | needSave | boolean | RW | `obj.needSave = <value>` |
| settings | (void* | lightuserdata | R | `obj.settings` |
| threadRunning | threadRunning | boolean | RW | `obj.threadRunning = <value>` |
| doingStuff | doingStuff | boolean | RW | `obj.doingStuff = <value>` |
| taskMutex | taskMutex | lightuserdata | R | `obj.taskMutex` |
| lockedTask | (void* | lightuserdata | R | `obj.lockedTask` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| isGenerating | isGenerating | `` | `boolean` | `obj:isGenerating()` |
| threadProc | threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| updateBT | updateBT | `` | `boolean` | `obj:updateBT()` |
| generateTaskBT | generateTaskBT | `task: userdata` | `void` | `obj:generateTaskBT(task)` |
| validateBuildingStates | validateBuildingStates | `task: userdata` | `integer` | `obj:validateBuildingStates(task)` |
| carve | carve | `task: userdata` | `integer` | `obj:carve(task)` |
| splice | splice | `t: userdata` | `integer` | `obj:splice(t)` |
| stitchInterior | stitchInterior | `t: userdata` | `integer` | `obj:stitchInterior(t)` |
| stitchExterior | stitchExterior | `t: userdata` | `integer` | `obj:stitchExterior(t)` |
| revertSettings | revertSettings | `` | `void` | `obj:revertSettings()` |
| unlockTask | unlockTask | `task: userdata` | `void` | `obj:unlockTask(task)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| hasJob | hasJob | `` | `boolean` | `obj:hasJob()` |
| update | update | `` | `void` | `obj:update()` |

## NavMeshSeeds
**Header:** `extern/KenshiLib/Include/kenshi/navmeshgenerator.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| load | load | `` | `void` | `obj:load()` |
| save | save | `` | `void` | `obj:save()` |
| addSeedPoint | addSeedPoint | `p: Vector3, terrain: boolean` | `void` | `obj:addSeedPoint(p, terrain)` |
| removeSeedPoints | removeSeedPoints | `pos: Vector3, radius: number` | `integer` | `obj:removeSeedPoints(pos, radius)` |
| clearSeedPoints | clearSeedPoints | `` | `integer` | `obj:clearSeedPoints()` |
| removeIsland | removeIsland | `pos: Vector3, radius: number` | `integer` | `obj:removeIsland(pos, radius)` |
| projectToTerrain | projectToTerrain | `` | `void` | `obj:projectToTerrain()` |
| getSeedPoints | getSeedPoints | `` | `lightuserdata` | `obj:getSeedPoints()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NewGameOptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameOptionsWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| optionsPanel | optionsPanel | DatapanelGUI | RW | `obj.optionsPanel = <value>` |
| tooltip | tooltip | ToolTip | RW | `obj.tooltip = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setPosition | setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| update | update | `` | `void` | `obj:update()` |

## NewGameWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentStart | currentStart | integer | RW | `obj.currentStart = <value>` |
| startInfo | startInfo | DatapanelGUI | RW | `obj.startInfo = <value>` |
| startNameTextBox | (void* | lightuserdata | R | `obj.startNameTextBox` |
| newGameOptions | newGameOptions | NewGameOptionsWindow | RW | `obj.newGameOptions = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| setRealPosition | setRealPosition | `x: number, y: number` | `void` | `obj:setRealPosition(x, y)` |
| setPosition | setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| _NV_setPosition | _NV_setPosition | `x: integer, y: integer` | `void` | `obj:_NV_setPosition(x, y)` |
| show | show | `_a1: boolean` | `void` | `obj:show(_a1)` |
| _NV_show | _NV_show | `_a1: boolean` | `void` | `obj:_NV_show(_a1)` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| loadData | loadData | `` | `void` | `obj:loadData()` |
| updateCurrentData | updateCurrentData | `` | `void` | `obj:updateCurrentData()` |

## NpcListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |

## Nx9Real
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

## NxBox
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NxMat33
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setRowMajor | setRowMajor | `d: userdata` | `void` | `obj:setRowMajor(d)` |
| getRowMajor | getRowMajor | `d: userdata` | `void` | `obj:getRowMajor(d)` |
| getColumnMajor | getColumnMajor | `d: userdata` | `void` | `obj:getColumnMajor(d)` |
| setRowMajorStride4 | setRowMajorStride4 | `d: userdata` | `void` | `obj:setRowMajorStride4(d)` |
| getRowMajorStride4 | getRowMajorStride4 | `d: userdata` | `void` | `obj:getRowMajorStride4(d)` |
| getColumnMajorStride4 | getColumnMajorStride4 | `d: userdata` | `void` | `obj:getColumnMajorStride4(d)` |
| isFinite | isFinite | `` | `boolean` | `obj:isFinite()` |
| zero | zero | `` | `void` | `obj:zero()` |
| id | id | `` | `void` | `obj:id()` |

## NxUserControllerHitReport
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `NxUserControllerHitReport` | `obj:_CONSTRUCTOR()` |

## NxUserTriggerReport
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## NxVec3
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| x | x | number | RW | `obj.x = <value>` |
| y | y | number | RW | `obj.y = <value>` |
| z | z | number | RW | `obj.z = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| zero | zero | `` | `void` | `obj:zero()` |
| isZero | isZero | `` | `integer` | `obj:isZero()` |
| normalize | normalize | `` | `number` | `obj:normalize()` |
| setMagnitude | setMagnitude | `length: number` | `void` | `obj:setMagnitude(length)` |
| closestAxis | closestAxis | `` | `integer` | `obj:closestAxis()` |
| isFinite | isFinite | `` | `boolean` | `obj:isFinite()` |
| magnitude | magnitude | `` | `number` | `obj:magnitude()` |
| magnitudeSquared | magnitudeSquared | `` | `number` | `obj:magnitudeSquared()` |

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
| keyConfig | keyConfig | DataPanelLine_KeyConfig | RW | `obj.keyConfig = <value>` |
| keysDatapanel | keysDatapanel | DatapanelGUI | RW | `obj.keysDatapanel = <value>` |
| tabs | (void* | lightuserdata | R | `obj.tabs` |
| created | created | boolean | RW | `obj.created = <value>` |
| tooltip | tooltip | ToolTip | RW | `obj.tooltip = <value>` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `OptionsWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| saveLocationChanged | saveLocationChanged | `` | `void` | `obj:saveLocationChanged()` |
| changeFontSize | changeFontSize | `` | `void` | `obj:changeFontSize()` |
| changeVolume | changeVolume | `` | `void` | `obj:changeVolume()` |
| toggleNames | toggleNames | `` | `void` | `obj:toggleNames()` |
| resetTutorials | resetTutorials | `` | `void` | `obj:resetTutorials()` |
| toggleTutorials | toggleTutorials | `` | `void` | `obj:toggleTutorials()` |
| changeDistances | changeDistances | `` | `void` | `obj:changeDistances()` |
| toggleCompositor | toggleCompositor | `` | `void` | `obj:toggleCompositor()` |
| resetAllKeys | resetAllKeys | `` | `void` | `obj:resetAllKeys()` |
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
| data | data | OrderData | RW | `obj.data = <value>` |

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
| task | task | Tasker | RW | `obj.task = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| text | text | string | RW | `obj.text = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `OrderData` | `obj:_CONSTRUCTOR()` |
| set | set | `_index: integer, _enabled: boolean` | `void` | `obj:set(_index, _enabled)` |
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
| ordersCharacter | ordersCharacter | unknown | RW | `obj.ordersCharacter = <value>` |
| ordersItemBox | ordersItemBox | OrdersItemBox | RW | `obj.ordersItemBox = <value>` |
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
| update | update | `` | `void` | `obj:update()` |
| clear | clear | `` | `void` | `obj:clear()` |
| command | command | `cmd: integer` | `void` | `obj:command(cmd)` |
| refreshOrders | refreshOrders | `` | `void` | `obj:refreshOrders()` |
| moveJob | moveJob | `orderIdx: integer, targetIdx: integer` | `void` | `obj:moveJob(orderIdx, targetIdx)` |
| removeJob | removeJob | `` | `void` | `obj:removeJob()` |
| notifyEndDropOrder | notifyEndDropOrder | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropOrder(_sender, _result)` |
| setSpeed | setSpeed | `moveSpeed: integer` | `void` | `obj:setSpeed(moveSpeed)` |
| setSpeedImage | setSpeedImage | `moveSpeed: integer` | `void` | `obj:setSpeedImage(moveSpeed)` |

## Ownerships
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| _homeTown | _homeTown | TownBase | RW | `obj._homeTown = <value>` |
| _homeBuilding | _homeBuilding | unknown | RW | `obj._homeBuilding = <value>` |
| faction | faction | Faction | RW | `obj.faction = <value>` |
| me | me | Platoon | RW | `obj.me = <value>` |
| occupiedTown | occupiedTown | TownBase | RW | `obj.occupiedTown = <value>` |
| money | money | integer | RW | `obj.money = <value>` |
| slaves | slaves | std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > | R | `obj.slaves` |
| stuff | stuff | lektor<hand> | R | `obj.stuff` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Ownerships` | `obj:_CONSTRUCTOR()` |
| setHandle | setHandle | `` | `void` | `obj:setHandle()` |
| takeMoney | takeMoney | `val: integer` | `boolean` | `obj:takeMoney(val)` |
| _NV_takeMoney | _NV_takeMoney | `val: integer` | `boolean` | `obj:_NV_takeMoney(val)` |
| takeMoneyByForce | takeMoneyByForce | `val: integer` | `void` | `obj:takeMoneyByForce(val)` |
| _NV_takeMoneyByForce | _NV_takeMoneyByForce | `val: integer` | `void` | `obj:_NV_takeMoneyByForce(val)` |
| getMoney | getMoney | `` | `integer` | `obj:getMoney()` |
| addMoney | addMoney | `amount: integer` | `void` | `obj:addMoney(amount)` |
| setMoney | setMoney | `amount: integer` | `void` | `obj:setMoney(amount)` |
| setHomeBuildingDesignation | setHomeBuildingDesignation | `d: integer` | `void` | `obj:setHomeBuildingDesignation(d)` |
| copyFrom | copyFrom | `` | `void` | `obj:copyFrom()` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| load | load | `st: integer` | `void` | `obj:load(st)` |
| setHomeTown | setHomeTown | `squadtype: integer` | `void` | `obj:setHomeTown(squadtype)` |
| isMyTown | isMyTown | `` | `boolean` | `obj:isMyTown()` |
| canIUseThisBuilding | canIUseThisBuilding | `` | `boolean` | `obj:canIUseThisBuilding()` |
| declareOccupiedTown | declareOccupiedTown | `` | `void` | `obj:declareOccupiedTown()` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `limit: integer, ttl: number` | `ParticlePool` | `obj:_CONSTRUCTOR(limit, ttl)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | init | `` | `void` | `obj:init()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| getSize | getSize | `` | `integer` | `obj:getSize()` |
| update | update | `` | `void` | `obj:update()` |
| shiftParticles | shiftParticles | `shift: Vector3` | `void` | `obj:shiftParticles(shift)` |

## PhysicalEntity
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| ent | (void* | lightuserdata | R | `obj.ent` |
| parent | (void* | lightuserdata | R | `obj.parent` |
| floorNumber | floorNumber | integer | RW | `obj.floorNumber = <value>` |
| mat | mat | GameData | RW | `obj.mat = <value>` |
| partData | partData | GameData | RW | `obj.partData = <value>` |
| instanced | instanced | boolean | RW | `obj.instanced = <value>` |
| isShell | isShell | boolean | RW | `obj.isShell = <value>` |
| isEmissive | isEmissive | boolean | RW | `obj.isEmissive = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PhysicsActual
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| materialConcrete | (void* | lightuserdata | R | `obj.materialConcrete` |
| materialMetal | (void* | lightuserdata | R | `obj.materialMetal` |
| materialSand | (void* | lightuserdata | R | `obj.materialSand` |
| materialHuman | (void* | lightuserdata | R | `obj.materialHuman` |
| myTriggerCallback | myTriggerCallback | lightuserdata | RW | `obj.myTriggerCallback = <value>` |
| HW | HW | boolean | RW | `obj.HW = <value>` |
| debugRenderOn | debugRenderOn | boolean | RW | `obj.debugRenderOn = <value>` |
| scytheClass | scytheClass | lightuserdata | RW | `obj.scytheClass = <value>` |
| controllerMgr | (void* | lightuserdata | R | `obj.controllerMgr` |
| physicsSDK | (void* | lightuserdata | R | `obj.physicsSDK` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateUT | updateUT | `` | `void` | `obj:updateUT()` |
| _NV_updateUT | _NV_updateUT | `` | `void` | `obj:_NV_updateUT()` |
| backThreadUpdate | backThreadUpdate | `time: number, _useOwnTimers: boolean` | `void` | `obj:backThreadUpdate(time, _useOwnTimers)` |
| _NV_backThreadUpdate | _NV_backThreadUpdate | `time: number, _useOwnTimers: boolean` | `void` | `obj:_NV_backThreadUpdate(time, _useOwnTimers)` |
| threadJunkPreBT | threadJunkPreBT | `` | `void` | `obj:threadJunkPreBT()` |
| threadJunkPostBT | threadJunkPostBT | `` | `void` | `obj:threadJunkPostBT()` |
| setup | setup | `` | `boolean` | `obj:setup()` |
| scytheGetFirstModelName | scytheGetFirstModelName | `filename: string` | `string` | `obj:scytheGetFirstModelName(filename)` |
| _createTriggerHull | _createTriggerHull | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:_createTriggerHull(pos, size)` |
| _createStaticCapsule | _createStaticCapsule | `pos: Vector3, length: number, radius: number` | `lightuserdata` | `obj:_createStaticCapsule(pos, length, radius)` |
| _createStaticBox | _createStaticBox | `pos: Vector3, dimensions: Vector3, rot: Quaternion, group: integer` | `lightuserdata` | `obj:_createStaticBox(pos, dimensions, rot, group)` |
| uncookMesh | uncookMesh | `mesh: userdata, cId: string` | `boolean` | `obj:uncookMesh(mesh, cId)` |

## PhysicsClass
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`

## PhysicsCollection
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| findRotatingEnt | findRotatingEnt | `` | `lightuserdata` | `obj:findRotatingEnt()` |
| getWindRotationPower | getWindRotationPower | `` | `number` | `obj:getWindRotationPower()` |
| getWindMillPart | getWindMillPart | `` | `lightuserdata` | `obj:getWindMillPart()` |
| isLoaded | isLoaded | `` | `boolean` | `obj:isLoaded()` |
| setVisible | setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| update | update | `speed: number` | `void` | `obj:update(speed)` |
| updateAimingType | updateAimingType | `speed: number, rotTarget: Vector3` | `number` | `obj:updateAimingType(speed, rotTarget)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## PhysicsInterface
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nWorld | (void* | lightuserdata | R | `obj.nWorld` |
| _queuesClear | _queuesClear | boolean | RW | `obj._queuesClear = <value>` |
| queuesClearMuto | queuesClearMuto | lightuserdata | R | `obj.queuesClearMuto` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getBackthread | getBackthread | `` | `lightuserdata` | `obj:getBackthread()` |
| updateUT | updateUT | `` | `void` | `obj:updateUT()` |
| backThreadUpdate | backThreadUpdate | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| createTriggerHull | createTriggerHull | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:createTriggerHull(pos, size)` |
| createStaticCapsule | createStaticCapsule | `pos: Vector3, h: number, w: number` | `lightuserdata` | `obj:createStaticCapsule(pos, h, w)` |
| doorWantsSetup | doorWantsSetup | `` | `void` | `obj:doorWantsSetup()` |
| scytheInsertPreview | scytheInsertPreview | `` | `boolean` | `obj:scytheInsertPreview()` |
| loadScytheFileMT | loadScytheFileMT | `file: string, pos: Vector3, q: Quaternion, boneAttachment: string` | `lightuserdata` | `obj:loadScytheFileMT(file, pos, q, boneAttachment)` |
| queuesAreClearMT | queuesAreClearMT | `` | `boolean` | `obj:queuesAreClearMT()` |
| setQueuesAreClear | setQueuesAreClear | `on: boolean` | `void` | `obj:setQueuesAreClear(on)` |

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| _characterCountCurrent | _characterCountCurrent | integer | RW | `obj._characterCountCurrent = <value>` |
| _characterCountOriginal | _characterCountOriginal | integer | RW | `obj._characterCountOriginal = <value>` |
| squadType | (lua_Integer | integer | RW | `obj.squadType = <value>` |
| hasUniques | hasUniques | YesNoMaybe | RW | `obj.hasUniques = <value>` |
| speedOverride | (lua_Integer | integer | RW | `obj.speedOverride = <value>` |
| isSeparatedSquad | isSeparatedSquad | unknown | RW | `obj.isSeparatedSquad = <value>` |
| canRefresh | canRefresh | boolean | RW | `obj.canRefresh = <value>` |
| regenerates | regenerates | boolean | RW | `obj.regenerates = <value>` |
| myBaseHomeTownData | myBaseHomeTownData | GameData | RW | `obj.myBaseHomeTownData = <value>` |
| priceMultWhenITrade | priceMultWhenITrade | number | RW | `obj.priceMultWhenITrade = <value>` |
| _iBuyStolenGoods | _iBuyStolenGoods | boolean | RW | `obj._iBuyStolenGoods = <value>` |
| _iBuyIllegalGoods | _iBuyIllegalGoods | boolean | RW | `obj._iBuyIllegalGoods = <value>` |
| locatorModel | (void* | lightuserdata | RW | `obj.locatorModel = <value>` |
| blackboard | (void* | lightuserdata | RW | `obj.blackboard = <value>` |
| _isIntact | _isIntact | boolean | RW | `obj._isIntact = <value>` |
| squadTemplate | squadTemplate | GameData | RW | `obj.squadTemplate = <value>` |
| malnourishedLevel | malnourishedLevel | number | RW | `obj.malnourishedLevel = <value>` |
| hasNeverBeenActivated | hasNeverBeenActivated | boolean | RW | `obj.hasNeverBeenActivated = <value>` |
| _persistentSquad | _persistentSquad | boolean | RW | `obj._persistentSquad = <value>` |
| isResidentSquad | isResidentSquad | boolean | RW | `obj.isResidentSquad = <value>` |
| currentSpawnArea | (void* | lightuserdata | RW | `obj.currentSpawnArea = <value>` |
| squadleader | squadleader | unknown | RW | `obj.squadleader = <value>` |
| ownerships | ownerships | Ownerships | RW | `obj.ownerships = <value>` |
| activePlatoon | activePlatoon | ActivePlatoon | RW | `obj.activePlatoon = <value>` |
| unloadedPlatoon | (void* | lightuserdata | RW | `obj.unloadedPlatoon = <value>` |
| patrolSettings | (void* | lightuserdata | RW | `obj.patrolSettings = <value>` |
| isDead | isDead | boolean | RW | `obj.isDead = <value>` |
| imprisoned | imprisoned | boolean | RW | `obj.imprisoned = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| traderInventoryRefreshTime | traderInventoryRefreshTime | TimeOfDay | RW | `obj.traderInventoryRefreshTime = <value>` |
| messageOnActivation | (lua_Integer | integer | RW | `obj.messageOnActivation = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `p: Vector3, _persistent: boolean` | `Platoon` | `obj:_CONSTRUCTOR(p, _persistent)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCharacterCount | setCharacterCount | `count: integer` | `void` | `obj:setCharacterCount(count)` |
| chooseNewHome | chooseNewHome | `` | `void` | `obj:chooseNewHome()` |
| isUnconcious | isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| getSquadType | getSquadType | `` | `integer` | `obj:getSquadType()` |
| setSquadType | setSquadType | `t: integer` | `void` | `obj:setSquadType(t)` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| hasCampaign | hasCampaign | `` | `lightuserdata` | `obj:hasCampaign()` |
| iBuyStolenGoods | iBuyStolenGoods | `` | `boolean` | `obj:iBuyStolenGoods()` |
| iBuyIllegalGoods | iBuyIllegalGoods | `` | `boolean` | `obj:iBuyIllegalGoods()` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| canTakeRefugees | canTakeRefugees | `` | `boolean` | `obj:canTakeRefugees()` |
| isUnique | isUnique | `` | `lightuserdata` | `obj:isUnique()` |
| _NV_isUnique | _NV_isUnique | `` | `lightuserdata` | `obj:_NV_isUnique()` |
| getPlatoonStringID | getPlatoonStringID | `` | `string` | `obj:getPlatoonStringID()` |
| getBlackboard | getBlackboard | `` | `lightuserdata` | `obj:getBlackboard()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| erasePlatoonFile | erasePlatoonFile | `` | `void` | `obj:erasePlatoonFile()` |
| showDebugMarker | showDebugMarker | `on: boolean` | `void` | `obj:showDebugMarker(on)` |
| getStateBroadcast | getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| serialiseEverything | serialiseEverything | `levelEditor: boolean` | `GameData` | `obj:serialiseEverything(levelEditor)` |
| _NV_serialiseEverything | _NV_serialiseEverything | `levelEditor: boolean` | `GameData` | `obj:_NV_serialiseEverything(levelEditor)` |
| loadStateData | loadStateData | `` | `void` | `obj:loadStateData()` |
| _NV_loadStateData | _NV_loadStateData | `` | `void` | `obj:_NV_loadStateData()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| reprocessTask | reprocessTask | `` | `void` | `obj:reprocessTask()` |
| taskIsComplete | taskIsComplete | `` | `void` | `obj:taskIsComplete()` |
| setDataFilename | setDataFilename | `f: string` | `void` | `obj:setDataFilename(f)` |
| isIntact | isIntact | `` | `boolean` | `obj:isIntact()` |
| notifyMissionEnded | notifyMissionEnded | `` | `void` | `obj:notifyMissionEnded()` |
| _NV_notifyMissionEnded | _NV_notifyMissionEnded | `` | `void` | `obj:_NV_notifyMissionEnded()` |
| activate | activate | `` | `void` | `obj:activate()` |
| deactivate | deactivate | `` | `void` | `obj:deactivate()` |
| declareDead | declareDead | `` | `void` | `obj:declareDead()` |
| undeclareDead | undeclareDead | `` | `void` | `obj:undeclareDead()` |
| isFullyLoaded | isFullyLoaded | `` | `boolean` | `obj:isFullyLoaded()` |
| getActivePlatoon | getActivePlatoon | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getUnloadedPlatoon | getUnloadedPlatoon | `` | `lightuserdata` | `obj:getUnloadedPlatoon()` |
| update | update | `` | `boolean` | `obj:update()` |
| _NV_update | _NV_update | `` | `boolean` | `obj:_NV_update()` |
| periodicUpdate_active | periodicUpdate_active | `time: number` | `void` | `obj:periodicUpdate_active(time)` |
| _NV_periodicUpdate_active | _NV_periodicUpdate_active | `time: number` | `void` | `obj:_NV_periodicUpdate_active(time)` |
| periodicUpdate_unloaded | periodicUpdate_unloaded | `` | `void` | `obj:periodicUpdate_unloaded()` |
| _NV_periodicUpdate_unloaded | _NV_periodicUpdate_unloaded | `` | `void` | `obj:_NV_periodicUpdate_unloaded()` |
| setupPatrolSettings | setupPatrolSettings | `minRange: integer, maxRange: integer` | `void` | `obj:setupPatrolSettings(minRange, maxRange)` |
| getPatrolInfo | getPatrolInfo | `` | `lightuserdata` | `obj:getPatrolInfo()` |
| getRoamingMapArea | getRoamingMapArea | `` | `lightuserdata` | `obj:getRoamingMapArea()` |
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
| serialise | Platoon_serialise | `offsetPosToSubtract: userdata` | `GameSaveState` | `obj:serialise(offsetPosToSubtract)` |
| _NV_serialise | Platoon__NV_serialise | `offsetPosToSubtract: userdata` | `GameSaveState` | `obj:_NV_serialise(offsetPosToSubtract)` |
| setRoamingMapArea | Platoon_setRoamingMapArea | `maparea: userdata` | `void` | `obj:setRoamingMapArea(maparea)` |
| getSquadLeader_theRealOne | Platoon_getSquadLeader_theRealOne | `` | `void` | `obj:getSquadLeader_theRealOne()` |

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
| selectedCharacter | selectedCharacter | unknown | RW | `obj.selectedCharacter = <value>` |
| aiOptions | aiOptions | PlayerInterface::AIOptions | RW | `obj.aiOptions = <value>` |
| interiorsVisibleHash | interiorsVisibleHash | integer | RW | `obj.interiorsVisibleHash = <value>` |
| currentFloor | currentFloor | integer | RW | `obj.currentFloor = <value>` |
| currentMouseTask | (lua_Integer | integer | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | (lua_Integer | integer | RW | `obj.mouseTaskTypeRestriction = <value>` |
| mouseRightTargetSet | mouseRightTargetSet | boolean | RW | `obj.mouseRightTargetSet = <value>` |
| mouseRightTarget | mouseRightTarget | RootObject | RW | `obj.mouseRightTarget = <value>` |
| rmouseTimer | rmouseTimer | number | RW | `obj.rmouseTimer = <value>` |
| selectedObject | selectedObject | unknown | RW | `obj.selectedObject = <value>` |
| onlyAnimalsSelected | onlyAnimalsSelected | boolean | RW | `obj.onlyAnimalsSelected = <value>` |
| selectedLoadedLeft | selectedLoadedLeft | integer | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterHandle | trackedCharacterHandle | unknown | RW | `obj.trackedCharacterHandle = <value>` |
| trackedCharacterFloor | trackedCharacterFloor | integer | RW | `obj.trackedCharacterFloor = <value>` |
| levelEditor | levelEditor | LevelEditor | RW | `obj.levelEditor = <value>` |
| participant | participant | Faction | RW | `obj.participant = <value>` |
| currentPlatoon | currentPlatoon | Platoon | RW | `obj.currentPlatoon = <value>` |
| deadPlayerSquad | deadPlayerSquad | unknown | RW | `obj.deadPlayerSquad = <value>` |
| placementObject | (void* | lightuserdata | RW | `obj.placementObject = <value>` |
| characterEditorMode | characterEditorMode | boolean | RW | `obj.characterEditorMode = <value>` |
| mLeftUp | mLeftUp | boolean | RW | `obj.mLeftUp = <value>` |
| mLeftDown | mLeftDown | boolean | RW | `obj.mLeftDown = <value>` |
| mRightUp | mRightUp | boolean | RW | `obj.mRightUp = <value>` |
| mRightDown | mRightDown | boolean | RW | `obj.mRightDown = <value>` |
| interiorsVisible | interiorsVisible | ogre_unordered_set<hand>::type | RW | `obj.interiorsVisible = <value>` |
| playerCharacters | playerCharacters | lektor<Character*> | RW | `obj.playerCharacters = <value>` |
| selectedCharacters | selectedCharacters | ogre_unordered_set<hand>::type | RW | `obj.selectedCharacters = <value>` |
| townsActive | townsActive | ogre_unordered_set<TownBase*>::type | RW | `obj.townsActive = <value>` |
| zonesVisibilities | zonesVisibilities | unknown | RW | `obj.zonesVisibilities = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `PlayerInterface` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getCamera | getCamera | `` | `CameraClass` | `obj:getCamera()` |
| playerSetup | playerSetup | `` | `void` | `obj:playerSetup()` |
| clearAndReset | clearAndReset | `` | `void` | `obj:clearAndReset()` |
| factoryObjectCreatedCallback | factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _NV_factoryObjectCreatedCallback | _NV_factoryObjectCreatedCallback | `` | `void` | `obj:_NV_factoryObjectCreatedCallback()` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |
| setCurrentPlatoon | setCurrentPlatoon | `` | `boolean` | `obj:setCurrentPlatoon()` |
| getCurrentPlatoon | getCurrentPlatoon | `` | `Platoon` | `obj:getCurrentPlatoon()` |
| getCurrentActivePlatoon | getCurrentActivePlatoon | `` | `RootObjectContainer` | `obj:getCurrentActivePlatoon()` |
| createSquad | createSquad | `` | `ActivePlatoon` | `obj:createSquad()` |
| getDeadSquad | getDeadSquad | `` | `ActivePlatoon` | `obj:getDeadSquad()` |
| update | update | `` | `void` | `obj:update()` |
| updateUT | updateUT | `` | `void` | `obj:updateUT()` |
| isBuildMode | isBuildMode | `` | `boolean` | `obj:isBuildMode()` |
| activateObjectPlacementMode | activateObjectPlacementMode | `` | `void` | `obj:activateObjectPlacementMode()` |
| activateCharacterEditMode | activateCharacterEditMode | `` | `void` | `obj:activateCharacterEditMode()` |
| triggerAreaArrivalDialogue | triggerAreaArrivalDialogue | `` | `boolean` | `obj:triggerAreaArrivalDialogue()` |
| setCharacterEditMode | setCharacterEditMode | `on: boolean` | `void` | `obj:setCharacterEditMode(on)` |
| getCharacterEditMode | getCharacterEditMode | `` | `boolean` | `obj:getCharacterEditMode()` |
| unselectAll | unselectAll | `` | `void` | `obj:unselectAll()` |
| selectAll | selectAll | `` | `void` | `obj:selectAll()` |
| selectObject | selectObject | `modifier: boolean` | `void` | `obj:selectObject(modifier)` |
| selectPlayerCharacter | selectPlayerCharacter | `index: integer, modifier: boolean, track: boolean` | `void` | `obj:selectPlayerCharacter(index, modifier, track)` |
| _selectPlayerCharacter | _selectPlayerCharacter | `modifier: boolean, track: boolean` | `void` | `obj:_selectPlayerCharacter(modifier, track)` |
| activateSelection | activateSelection | `` | `void` | `obj:activateSelection()` |
| getCameraCenter | getCameraCenter | `` | `Vector3` | `obj:getCameraCenter()` |
| getDistanceFromCamera | getDistanceFromCamera | `v: Vector3` | `number` | `obj:getDistanceFromCamera(v)` |
| getSquaredDistanceFromCamera | getSquaredDistanceFromCamera | `v: Vector3` | `number` | `obj:getSquaredDistanceFromCamera(v)` |
| startTrackCharacter | startTrackCharacter | `` | `void` | `obj:startTrackCharacter()` |
| stopTrackCharacter | stopTrackCharacter | `` | `void` | `obj:stopTrackCharacter()` |
| isTrackingCharacter | isTrackingCharacter | `` | `boolean` | `obj:isTrackingCharacter()` |
| focusCamera | focusCamera | `pos: Vector3` | `void` | `obj:focusCamera(pos)` |
| manuallyOrientCamera | manuallyOrientCamera | `rot: Quaternion, zoom: number` | `void` | `obj:manuallyOrientCamera(rot, zoom)` |
| focusCameraSelectedCharacter | focusCameraSelectedCharacter | `` | `void` | `obj:focusCameraSelectedCharacter()` |
| toggleLevelEditorOnSelectedTown | toggleLevelEditorOnSelectedTown | `` | `void` | `obj:toggleLevelEditorOnSelectedTown()` |
| isLevelEditMode | isLevelEditMode | `` | `boolean` | `obj:isLevelEditMode()` |
| isObjectPlacementMode | isObjectPlacementMode | `` | `boolean` | `obj:isObjectPlacementMode()` |
| setOrderSelectedCharacters | setOrderSelectedCharacters | `order: integer` | `void` | `obj:setOrderSelectedCharacters(order)` |
| getLevelEditor | getLevelEditor | `` | `LevelEditor` | `obj:getLevelEditor()` |
| objectSelected | objectSelected | `select: boolean` | `void` | `obj:objectSelected(select)` |
| toggleObjectSelected | toggleObjectSelected | `` | `void` | `obj:toggleObjectSelected()` |
| isObjectSelected | isObjectSelected | `` | `boolean` | `obj:isObjectSelected()` |
| unselectPlayerCharacter | unselectPlayerCharacter | `` | `void` | `obj:unselectPlayerCharacter()` |
| getCurrentFloor | getCurrentFloor | `` | `integer` | `obj:getCurrentFloor()` |
| setCurrentFloor | setCurrentFloor | `floor: integer` | `void` | `obj:setCurrentFloor(floor)` |
| getNearestSelectedCharacterTo | getNearestSelectedCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestSelectedCharacterTo(pos)` |
| getNearestCharacterTo | getNearestCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestCharacterTo(pos)` |
| addOrderSelectedCharacters | addOrderSelectedCharacters | `task: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addOrderSelectedCharacters(task, shift, addDontClear, location)` |
| addJobSelectedCharacters | addJobSelectedCharacters | `task: integer, shift: boolean, add: boolean, location: Vector3` | `void` | `obj:addJobSelectedCharacters(task, shift, add, location)` |
| removeJobSelectedCharacters | removeJobSelectedCharacters | `t: integer` | `void` | `obj:removeJobSelectedCharacters(t)` |
| removePermaJobSelectedCharacters | removePermaJobSelectedCharacters | `id: integer` | `void` | `obj:removePermaJobSelectedCharacters(id)` |
| selectedCharactersUnconcious | selectedCharactersUnconcious | `displayMessage: boolean` | `boolean` | `obj:selectedCharactersUnconcious(displayMessage)` |
| selectedCharactersLayingLow | selectedCharactersLayingLow | `` | `boolean` | `obj:selectedCharactersLayingLow()` |
| useSpeedGroup | useSpeedGroup | `use: boolean` | `void` | `obj:useSpeedGroup(use)` |
| assignSpeedGroup | assignSpeedGroup | `create: boolean` | `void` | `obj:assignSpeedGroup(create)` |
| isEnemy | isEnemy | `` | `boolean` | `obj:isEnemy()` |
| isFactionKnown | isFactionKnown | `` | `boolean` | `obj:isFactionKnown()` |
| encounterFaction | encounterFaction | `` | `void` | `obj:encounterFaction()` |
| pickupItem | pickupItem | `` | `void` | `obj:pickupItem()` |
| cycleSquad | cycleSquad | `` | `void` | `obj:cycleSquad()` |
| cycleCharacter | cycleCharacter | `d: integer` | `void` | `obj:cycleCharacter(d)` |
| stopCharactersMovement | stopCharactersMovement | `` | `void` | `obj:stopCharactersMovement()` |
| getAnyPlayerCharacter | getAnyPlayerCharacter | `` | `Character` | `obj:getAnyPlayerCharacter()` |
| isOrderValidForSelection | isOrderValidForSelection | `task: integer` | `boolean` | `obj:isOrderValidForSelection(task)` |
| serialise | serialise | `` | `void` | `obj:serialise()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| getInteriorsVisible | getInteriorsVisible | `` | `boolean` | `obj:getInteriorsVisible()` |
| setVisibilityForReflections | setVisibilityForReflections | `set: boolean` | `void` | `obj:setVisibilityForReflections(set)` |
| resetFloorsVisibility | resetFloorsVisibility | `` | `void` | `obj:resetFloorsVisibility()` |
| setFloorsVisibility | setFloorsVisibility | `floor: integer` | `void` | `obj:setFloorsVisibility(floor)` |
| addTaskNearestSelectedCharacter | addTaskNearestSelectedCharacter | `t: integer, shift: boolean, location: Vector3, noAnimals: boolean` | `void` | `obj:addTaskNearestSelectedCharacter(t, shift, location, noAnimals)` |
| updateLastMoveWaypointSelectedCharacters | updateLastMoveWaypointSelectedCharacters | `location: Vector3` | `void` | `obj:updateLastMoveWaypointSelectedCharacters(location)` |
| clearSelection | clearSelection | `` | `void` | `obj:clearSelection()` |
| mouseScan | mouseScan | `` | `void` | `obj:mouseScan()` |
| characterSelected | characterSelected | `` | `void` | `obj:characterSelected()` |
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| buildingSelected | buildingSelected | `position: Vector3, interiorsVisible: boolean` | `boolean` | `obj:buildingSelected(position, interiorsVisible)` |
| playerMove | playerMove | `pos: Vector3` | `void` | `obj:playerMove(pos)` |
| _isPlayerCharacter | _isPlayerCharacter | `` | `boolean` | `obj:_isPlayerCharacter()` |
| recruit | recruit | `editor: boolean` | `boolean` | `obj:recruit(editor)` |
| getDeadSquadHandle | getDeadSquadHandle | `` | `hand` | `obj:getDeadSquadHandle()` |
| updatePlayerSelection | updatePlayerSelection | `` | `void` | `obj:updatePlayerSelection()` |
| getAllSelectedObjects | getAllSelectedObjects | `type: integer` | `void` | `obj:getAllSelectedObjects(type)` |
| newPlayerTaskSelectedCharacters | newPlayerTaskSelectedCharacters | `t: integer, clickpos: Vector3, addDontClear: boolean` | `void` | `obj:newPlayerTaskSelectedCharacters(t, clickpos, addDontClear)` |
| getPlayerTaskProbability | getPlayerTaskProbability | `task: integer` | `boolean|number` | `obj:getPlayerTaskProbability(task)` |
| getAllPlayerCharacters | getAllPlayerCharacters | `` | `lektor<Character*>` | `obj:getAllPlayerCharacters()` |
| updateFloorVisibility | updateFloorVisibility | `` | `void` | `obj:updateFloorVisibility()` |
| playerControl | playerControl | `` | `void` | `obj:playerControl()` |

## PortraitData
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | RW | `obj.name = <value>` |
| flashing | flashing | integer | RW | `obj.flashing = <value>` |
| state | (lua_Integer | integer | RW | `obj.state = <value>` |
| reloadPortrait | reloadPortrait | boolean | RW | `obj.reloadPortrait = <value>` |
| characterHandle | characterHandle | unknown | RW | `obj.characterHandle = <value>` |
| updateRequested | updateRequested | boolean | RW | `obj.updateRequested = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| update | update | `` | `boolean` | `obj:update()` |
| forceUpdate | forceUpdate | `` | `void` | `obj:forceUpdate()` |
| isSelected | isSelected | `` | `boolean` | `obj:isSelected()` |
| isDown | isDown | `` | `boolean` | `obj:isDown()` |
| getBackgroundImageName | getBackgroundImageName | `` | `string` | `obj:getBackgroundImageName()` |
| getBackOverlayImageName | getBackOverlayImageName | `` | `string` | `obj:getBackOverlayImageName()` |
| getFrontOverlayImageName | getFrontOverlayImageName | `` | `string` | `obj:getFrontOverlayImageName()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PortraitImage
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| index | index | integer | RW | `obj.index = <value>` |
| created | created | boolean | RW | `obj.created = <value>` |
| textureName | textureName | string | RW | `obj.textureName = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PortraitMainCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| characterHandle | characterHandle | unknown | RW | `obj.characterHandle = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| border | (void* | lightuserdata | R | `obj.border` |
| imageBackground | (void* | lightuserdata | R | `obj.imageBackground` |
| imagePortrait | (void* | lightuserdata | R | `obj.imagePortrait` |
| imageOverlayBack | (void* | lightuserdata | R | `obj.imageOverlayBack` |
| imageOverlayFront | (void* | lightuserdata | R | `obj.imageOverlayFront` |
| textName | (void* | lightuserdata | R | `obj.textName` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resize | resize | `size: integer` | `void` | `obj:resize(size)` |
| setName | setName | `newName: string` | `void` | `obj:setName(newName)` |

## PortraitManager
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| textureSize | textureSize | iVector2 | RW | `obj.textureSize = <value>` |
| textureName | textureName | string | RW | `obj.textureName = <value>` |
| texturePortraitSize | texturePortraitSize | iVector2 | RW | `obj.texturePortraitSize = <value>` |
| maxIndex | maxIndex | integer | RW | `obj.maxIndex = <value>` |
| imagesIndices | (void* | lightuserdata | R | `obj.imagesIndices` |
| disableUpdate | disableUpdate | boolean | RW | `obj.disableUpdate = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| init | init | `` | `void` | `obj:init()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |
| setUpdateEnabled | setUpdateEnabled | `enabled: boolean` | `void` | `obj:setUpdateEnabled(enabled)` |
| reloadPortraits | reloadPortraits | `` | `void` | `obj:reloadPortraits()` |
| reloadTexture | reloadTexture | `` | `void` | `obj:reloadTexture()` |
| saveTexture | saveTexture | `` | `void` | `obj:saveTexture()` |
| clearPortraits | clearPortraits | `loadTexture: boolean` | `void` | `obj:clearPortraits(loadTexture)` |
| getCharacterFlashing | getCharacterFlashing | `` | `boolean` | `obj:getCharacterFlashing()` |
| getCharacterInCombat | getCharacterInCombat | `` | `boolean` | `obj:getCharacterInCombat()` |
| getCharacterDown | getCharacterDown | `` | `boolean` | `obj:getCharacterDown()` |
| getSquadFlashing | getSquadFlashing | `` | `boolean` | `obj:getSquadFlashing()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PortraitSquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| characterHandle | characterHandle | unknown | RW | `obj.characterHandle = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| border | (void* | lightuserdata | R | `obj.border` |
| imgBoxPortrait | (void* | lightuserdata | R | `obj.imgBoxPortrait` |
| txtName | (void* | lightuserdata | R | `obj.txtName` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resize | resize | `` | `void` | `obj:resize()` |
| setName | setName | `newName: string` | `void` | `obj:setName(newName)` |

## PortraitSquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| squad | (void* | lightuserdata | R | `obj.squad` |
| squadView | (void* | lightuserdata | R | `obj.squadView` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getItemCount | getItemCount | `` | `integer` | `obj:getItemCount()` |
| update | update | `` | `void` | `obj:update()` |

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

## ProgressBarWidget
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| bar | (void* | lightuserdata | R | `obj.bar` |
| label | (void* | lightuserdata | R | `obj.label` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| setProgress | setProgress | `value: integer` | `void` | `obj:setProgress(value)` |
| setPosition | setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setCaption | setCaption | `value: string` | `void` | `obj:setCaption(value)` |

## ProspectingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/ProspectingWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| window | (void* | lightuserdata | R | `obj.window` |
| imgMap | (void* | lightuserdata | R | `obj.imgMap` |
| listResourcesPanel | (void* | lightuserdata | R | `obj.listResourcesPanel` |
| listResourcesSelected | (void* | lightuserdata | R | `obj.listResourcesSelected` |
| cameraMarker | (void* | lightuserdata | R | `obj.cameraMarker` |
| cameraMarkerSkin | (void* | lightuserdata | R | `obj.cameraMarkerSkin` |
| datapanelOverview1 | datapanelOverview1 | DatapanelGUI | RW | `obj.datapanelOverview1 = <value>` |
| datapanelOverview2 | datapanelOverview2 | DatapanelGUI | RW | `obj.datapanelOverview2 = <value>` |
| resourceImage | (void* | lightuserdata | R | `obj.resourceImage` |
| lastPos | lastPos | Vector3 | RW | `obj.lastPos = <value>` |
| lastSkill | lastSkill | number | RW | `obj.lastSkill = <value>` |
| lastName | lastName | string | RW | `obj.lastName = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| showT | showT | `pos: Vector3, skill: number, name: string` | `void` | `obj:showT(pos, skill, name)` |
| _show | _show | `` | `void` | `obj:_show()` |
| hide | hide | `` | `void` | `obj:hide()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| updateCameraMarker | updateCameraMarker | `` | `void` | `obj:updateCameraMarker()` |
| updateMap | updateMap | `resource: integer` | `void` | `obj:updateMap(resource)` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| clear | clear | `` | `void` | `obj:clear()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ProsperityManager` | `obj:_CONSTRUCTOR()` |
| setup | setup | `` | `void` | `obj:setup()` |
| load | load | `` | `void` | `obj:load()` |
| save | save | `` | `void` | `obj:save()` |
| getProsperityMultiplier | getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| getGUIData | getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| update | update | `time: number` | `void` | `obj:update(time)` |
| notifySquadDefeated | notifySquadDefeated | `` | `void` | `obj:notifySquadDefeated()` |
| notifySpecialNPCDead | notifySpecialNPCDead | `` | `void` | `obj:notifySpecialNPCDead()` |

## RaceData
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | GameData | RW | `obj.data = <value>` |
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
| canGoIndoors | canGoIndoors | boolean | RW | `obj.canGoIndoors = <value>` |
| raceGroup | (void* | lightuserdata | RW | `obj.raceGroup = <value>` |
| bloodColour | bloodColour | unknown | RW | `obj.bloodColour = <value>` |
| specialFoods | specialFoods | ogre_unordered_set<GameData*>::type | RW | `obj.specialFoods = <value>` |
| statMods | statMods | unknown | RW | `obj.statMods = <value>` |
| weatherImmunities | weatherImmunities | ogre_unordered_set<WeatherAffecting>::type | RW | `obj.weatherImmunities = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RaceData` | `obj:_CONSTRUCTOR()` |
| getRaceData | getRaceData | `` | `RaceData` | `obj:getRaceData()` |
| isRelatedRace | isRelatedRace | `` | `boolean` | `obj:isRelatedRace()` |
| isSpecificRace | isSpecificRace | `` | `boolean` | `obj:isSpecificRace()` |
| getStatMod | getStatMod | `stat: integer` | `number` | `obj:getStatMod(stat)` |
| isImmune | isImmune | `w: integer` | `boolean` | `obj:isImmune(w)` |
| canEat | canEat | `isAnimal: boolean` | `boolean` | `obj:canEat(isAnimal)` |

## RaceLimiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| limits | limits | ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type | R | `obj.limits` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| addLimit | addLimit | `` | `void` | `obj:addLimit()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RaceLimiter` | `obj:_CONSTRUCTOR()` |
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

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| save | save | `ID: string` | `void` | `obj:save(ID)` |
| load | load | `ID: string` | `void` | `obj:load(ID)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ReorderableList
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | (void* | lightuserdata | R | `obj.data` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | clear | `` | `void` | `obj:clear()` |
| refresh | refresh | `force: boolean` | `void` | `obj:refresh(force)` |
| notifyEndDrop | notifyEndDrop | `sender: integer, info: integer, result: boolean` | `void` | `obj:notifyEndDrop(sender, info, result)` |
| notifyRemoved | notifyRemoved | `index: integer` | `void` | `obj:notifyRemoved(index)` |

## RepetitionCounter
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| states | states | RepetitionStatesMapBinding::MapType | RW | `obj.states = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | setup | `` | `void` | `obj:setup()` |
| count | count | `ev: integer` | `boolean` | `obj:count(ev)` |
| getTimeSinceLastTrigger | getTimeSinceLastTrigger | `ev: integer` | `number` | `obj:getTimeSinceLastTrigger(ev)` |
| getCount | getCount | `ev: integer` | `integer` | `obj:getCount(ev)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RepetitionCounter` | `obj:_CONSTRUCTOR()` |
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

## ResourceLinePanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ProspectingWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| button | (MyGUI::Widget* | MyGUI::Widget | R | `obj.button` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWidget | getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |

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
| character | character | Character | RW | `obj.character = <value>` |
| inventory | inventory | RootObject | RW | `obj.inventory = <value>` |
| states | (lua_Integer | integer | RW | `obj.states = <value>` |
| items | items | Item | RW | `obj.items = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RobotLimbs` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| load | load | `` | `void` | `obj:load()` |
| save | save | `` | `void` | `obj:save()` |
| getLimb | getLimb | `limb: integer` | `Item` | `obj:getLimb(limb)` |
| getMask | getMask | `` | `integer` | `obj:getMask()` |
| getInventoryInterface | getInventoryInterface | `create: boolean` | `RootObject` | `obj:getInventoryInterface(create)` |
| destroyInventoryInterface | destroyInventoryInterface | `` | `void` | `obj:destroyInventoryInterface()` |
| getLimbItem | getLimbItem | `l: integer` | `Item` | `obj:getLimbItem(l)` |
| getState | getState | `limb: integer` | `integer` | `obj:getState(limb)` |
| setLimb | setLimb | `limb: integer, state: integer` | `void` | `obj:setLimb(limb, state)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| container | container | RootObjectContainer | RW | `obj.container = <value>` |
| isInsideBuilding | isInsideBuilding | unknown | RW | `obj.isInsideBuilding = <value>` |
| isInsideTownWalls | isInsideTownWalls | integer | RW | `obj.isInsideTownWalls = <value>` |
| floorNum | floorNum | integer | RW | `obj.floorNum = <value>` |
| spacialKey | spacialKey | integer | RW | `obj.spacialKey = <value>` |
| outdoorDelayNotification_timer | outdoorDelayNotification_timer | integer | RW | `obj.outdoorDelayNotification_timer = <value>` |
| rot | rot | Quaternion | RW | `obj.rot = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RootObject` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| needsSaving | needsSaving | `s: string` | `boolean` | `obj:needsSaving(s)` |
| _NV_needsSaving | _NV_needsSaving | `s: string` | `boolean` | `obj:_NV_needsSaving(s)` |
| getInstanceID | getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| _NV_getInstanceID | _NV_getInstanceID | `` | `InstanceID` | `obj:_NV_getInstanceID()` |
| getOrientation | getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| _NV_getOrientation | _NV_getOrientation | `` | `Quaternion` | `obj:_NV_getOrientation()` |
| getZoneMapLocation | getZoneMapLocation | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| _NV_getZoneMapLocation | _NV_getZoneMapLocation | `` | `ZoneMap` | `obj:_NV_getZoneMapLocation()` |
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
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
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
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| setStandingOrder | setStandingOrder | `_a1: integer` | `void` | `obj:setStandingOrder(_a1)` |
| _NV_setStandingOrder | _NV_setStandingOrder | `_a1: integer` | `void` | `obj:_NV_setStandingOrder(_a1)` |
| getInventory | getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| giveItem | giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| _NV_giveItem | _NV_giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_giveItem(dropOnFail, destroyOnFail)` |
| hasRoomForItem | hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| hasItem | hasItem | `` | `boolean` | `obj:hasItem()` |
| _NV_hasItem | _NV_hasItem | `` | `boolean` | `obj:_NV_hasItem()` |
| createInventoryLayout | createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| ImStealingDoYouNotice | ImStealingDoYouNotice | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| _NV_ImStealingDoYouNotice | _NV_ImStealingDoYouNotice | `` | `boolean` | `obj:_NV_ImStealingDoYouNotice()` |
| stolenGoodsDetectionCheck | stolenGoodsDetectionCheck | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| _NV_stolenGoodsDetectionCheck | _NV_stolenGoodsDetectionCheck | `` | `boolean` | `obj:_NV_stolenGoodsDetectionCheck()` |
| equipItem | equipItem | `_a1: string` | `void` | `obj:equipItem(_a1)` |
| _NV_equipItem | _NV_equipItem | `_a1: string` | `void` | `obj:_NV_equipItem(_a1)` |
| unequipItem | unequipItem | `_a1: string` | `void` | `obj:unequipItem(_a1)` |
| _NV_unequipItem | _NV_unequipItem | `_a1: string` | `void` | `obj:_NV_unequipItem(_a1)` |
| dropItem | dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
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
| getPlatoonAI | getPlatoonAI | `` | `lightuserdata` | `obj:getPlatoonAI()` |
| _NV_getPlatoonAI | _NV_getPlatoonAI | `` | `lightuserdata` | `obj:_NV_getPlatoonAI()` |
| createPhysical | createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| notifyEffect | notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| loadUnloadCheck | loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| isIndoors | isIndoors | `` | `void` | `obj:isIndoors()` |
| _NV_isIndoors | _NV_isIndoors | `` | `void` | `obj:_NV_isIndoors()` |
| setIsInsideBuilding | setIsInsideBuilding | `` | `void` | `obj:setIsInsideBuilding()` |
| _NV_setIsInsideBuilding | _NV_setIsInsideBuilding | `` | `void` | `obj:_NV_setIsInsideBuilding()` |
| getLayoutInstanceID | getLayoutInstanceID | `` | `string` | `obj:getLayoutInstanceID()` |
| _NV_getLayoutInstanceID | _NV_getLayoutInstanceID | `` | `string` | `obj:_NV_getLayoutInstanceID()` |
| getAABB | getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| _NV_getAABB | _NV_getAABB | `` | `lightuserdata` | `obj:_NV_getAABB()` |
| getGUIDataCategories | getGUIDataCategories | `` | `void` | `obj:getGUIDataCategories()` |
| _NV_getGUIDataCategories | _NV_getGUIDataCategories | `` | `void` | `obj:_NV_getGUIDataCategories()` |
| getOrders | getOrders | `` | `void` | `obj:getOrders()` |
| _NV_getOrders | _NV_getOrders | `` | `void` | `obj:_NV_getOrders()` |
| notifyIndoors | notifyIndoors | `` | `void` | `obj:notifyIndoors()` |
| _NV_notifyIndoors | _NV_notifyIndoors | `` | `void` | `obj:_NV_notifyIndoors()` |
| hitByMeleeAttack | hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| _NV_hitByMeleeAttack | _NV_hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:_NV_hitByMeleeAttack(dir, comboID)` |

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
| handle | handle | unknown | RW | `obj.handle = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RootObjectBase` | `obj:_CONSTRUCTOR()` |
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
| getSensoryData | getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| _NV_getSensoryData | _NV_getSensoryData | `` | `SensoryData` | `obj:_NV_getSensoryData()` |
| getStateBroadcast | getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| getOwnerships | getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| _NV_getOwnerships | _NV_getOwnerships | `` | `Ownerships` | `obj:_NV_getOwnerships()` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| getHandle | getHandle | `` | `void` | `obj:getHandle()` |
| setHandle | setHandle | `` | `void` | `obj:setHandle()` |
| _NV_setHandle | _NV_setHandle | `` | `void` | `obj:_NV_setHandle()` |
| serialise | serialise | `offset: userdata` | `GameSaveState` | `obj:serialise(offset)` |

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
| addActiveObject | addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| removeObject | removeObject | `` | `boolean` | `obj:removeObject()` |
| _NV_removeObject | _NV_removeObject | `` | `boolean` | `obj:_NV_removeObject()` |
| update | update | `` | `boolean` | `obj:update()` |
| _NV_update | _NV_update | `` | `boolean` | `obj:_NV_update()` |
| getThing | getThing | `id: integer` | `RootObject` | `obj:getThing(id)` |
| getNumThings | getNumThings | `` | `integer` | `obj:getNumThings()` |
| getThings | getThings | `` | `lightuserdata` | `obj:getThings()` |
| loadToReality | loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| _NV_loadToReality | _NV_loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:_NV_loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| getSelectedObjects | getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| _NV_getSelectedObjects | _NV_getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:_NV_getSelectedObjects(type, selectedOnly)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `type: integer` | `RootObjectContainer` | `obj:_CONSTRUCTOR(type)` |
| serialiseThings | serialiseThings | `offset: userdata, mod: string, mod: string` | `void` | `obj:serialiseThings(offset, mod, mod)` |
| loadInstance | loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |
| _NV_loadInstance | _NV_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:_NV_loadInstance(skipSaveState, pos, rot, positionMoved)` |

## RootObjectFactory
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mutex | mutex | unknown | RW | `obj.mutex = <value>` |
| todoList | todoList | unknown | RW | `obj.todoList = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| create | create | `position: Vector3, isFromActiveLevelMod: boolean, rotation: Quaternion, invisible: boolean, age: number` | `RootObjectBase` | `obj:create(position, isFromActiveLevelMod, rotation, invisible, age)` |
| createLocationNode | createLocationNode | `addToNodeListAutomatically: boolean, position: Vector3, rotation: Quaternion, nodeId: string` | `lightuserdata` | `obj:createLocationNode(addToNodeListAutomatically, position, rotation, nodeId)` |
| copyItem | copyItem | `` | `Item` | `obj:copyItem()` |
| chooseDataFromList | chooseDataFromList | `listName: string, materialDataType: integer, useVal012: integer` | `GameData` | `obj:chooseDataFromList(listName, materialDataType, useVal012)` |
| chooseDataFromListWithVals | chooseDataFromListWithVals | `listName: string, materialDataType: integer, useVal012: integer` | `GameDataReference` | `obj:chooseDataFromListWithVals(listName, materialDataType, useVal012)` |
| createCharacterForBuilding | createCharacterForBuilding | `` | `void` | `obj:createCharacterForBuilding()` |
| createRandomCharacter | createRandomCharacter | `position: Vector3, age: number` | `RootObject` | `obj:createRandomCharacter(position, age)` |
| mainThreadUpdate | mainThreadUpdate | `` | `void` | `obj:mainThreadUpdate()` |
| populateBuilding | populateBuilding | `` | `void` | `obj:populateBuilding()` |
| process | process | `o: userdata` | `RootObjectBase` | `obj:process(o)` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `RootObjectFactory` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createBuilding | createBuilding | `position: Vector3, rotation: Quaternion, furnitureOf: userdata, invisible: boolean, completed: boolean, isFoliage: boolean, floorNumber: integer, isOutsideFurniture: boolean` | `Building` | `obj:createBuilding(position, rotation, furnitureOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture)` |
| createItem | createItem | `levelOverride: integer` | `Item` | `obj:createItem(levelOverride)` |
| getValsFromDataInList | getValsFromDataInList | `listName: string` | `integer` | `obj:getValsFromDataInList(listName)` |
| createRandomUnloadedCharacter | createRandomUnloadedCharacter | `platoon: userdata, position: Vector3` | `GameSaveState` | `obj:createRandomUnloadedCharacter(platoon, position)` |
| createRandomSquad | createRandomSquad | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, sizeMultiplier: number, squadType: integer, isJustARefresh: boolean` | `Platoon` | `obj:createRandomSquad(position, maxnum, maparea, permanentsquad, sizeMultiplier, squadType, isJustARefresh)` |
| createRandomUnloadedSquad | createRandomUnloadedSquad | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, squadType: integer` | `Platoon` | `obj:createRandomUnloadedSquad(position, maxnum, maparea, permanentsquad, squadType)` |

## RotatingEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| rotAxis | rotAxis | Vector3 | RW | `obj.rotAxis = <value>` |
| rotationSpeed | rotationSpeed | number | RW | `obj.rotationSpeed = <value>` |
| rotationPower | rotationPower | number | RW | `obj.rotationPower = <value>` |
| speedMin | speedMin | number | RW | `obj.speedMin = <value>` |
| speedMax | speedMax | number | RW | `obj.speedMax = <value>` |
| rotationBase | rotationBase | Quaternion | RW | `obj.rotationBase = <value>` |
| isRotating | isRotating | boolean | RW | `obj.isRotating = <value>` |
| rotationSrc | rotationSrc | Quaternion | RW | `obj.rotationSrc = <value>` |
| rotationDst | rotationDst | Quaternion | RW | `obj.rotationDst = <value>` |
| rotatingTime | rotatingTime | number | RW | `obj.rotatingTime = <value>` |
| rotationDuration | rotationDuration | number | RW | `obj.rotationDuration = <value>` |
| windSpeedRotationMin | windSpeedRotationMin | number | RW | `obj.windSpeedRotationMin = <value>` |
| windSpeedRotationMax | windSpeedRotationMax | number | RW | `obj.windSpeedRotationMax = <value>` |
| windSpeedRotationDanger | windSpeedRotationDanger | number | RW | `obj.windSpeedRotationDanger = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `productionSpeed: number` | `void` | `obj:update(productionSpeed)` |
| _NV_update | _NV_update | `productionSpeed: number` | `void` | `obj:_NV_update(productionSpeed)` |
| updateAim | updateAim | `speed: number, target: Vector3` | `number` | `obj:updateAim(speed, target)` |
| _NV_updateAim | _NV_updateAim | `speed: number, target: Vector3` | `number` | `obj:_NV_updateAim(speed, target)` |
| isRotatingEnt | isRotatingEnt | `` | `boolean` | `obj:isRotatingEnt()` |
| _NV_isRotatingEnt | _NV_isRotatingEnt | `` | `boolean` | `obj:_NV_isRotatingEnt()` |
| getRotationPower | getRotationPower | `` | `number` | `obj:getRotationPower()` |

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

## ScreenLabel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| caption | caption | string | RW | `obj.caption = <value>` |
| textWidget | (void* | lightuserdata | R | `obj.textWidget` |
| risingSpeed | risingSpeed | number | RW | `obj.risingSpeed = <value>` |
| risingHeight | risingHeight | number | RW | `obj.risingHeight = <value>` |
| labelSize | (lua_Integer | integer | RW | `obj.labelSize = <value>` |
| trackingHandle | trackingHandle | unknown | RW | `obj.trackingHandle = <value>` |
| trackingOffset | trackingOffset | Vector3 | RW | `obj.trackingOffset = <value>` |
| destroyed | destroyed | boolean | RW | `obj.destroyed = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCaption | setCaption | `value: string` | `void` | `obj:setCaption(value)` |
| _NV_setCaption | _NV_setCaption | `value: string` | `void` | `obj:_NV_setCaption(value)` |
| setRisingSpeed | setRisingSpeed | `value: integer` | `void` | `obj:setRisingSpeed(value)` |
| _NV_setRisingSpeed | _NV_setRisingSpeed | `value: integer` | `void` | `obj:_NV_setRisingSpeed(value)` |
| setPosition | setPosition | `value: Vector3` | `void` | `obj:setPosition(value)` |
| _NV_setPosition | _NV_setPosition | `value: Vector3` | `void` | `obj:_NV_setPosition(value)` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| destroy | destroy | `` | `void` | `obj:destroy()` |

## ScreenLabelDebug
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timeLeft | timeLeft | number | RW | `obj.timeLeft = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `caption: string, time: number` | `lightuserdata` | `obj:_CONSTRUCTOR(caption, time)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ScreenLabelInterface
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | visible | boolean | RW | `obj.visible = <value>` |
| position | position | Vector3 | RW | `obj.position = <value>` |
| needUpdate | needUpdate | boolean | RW | `obj.needUpdate = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| setVisible | setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| _NV_setVisible | _NV_setVisible | `value: boolean` | `void` | `obj:_NV_setVisible(value)` |
| setPosition | setPosition | `value: Vector3` | `void` | `obj:setPosition(value)` |
| _NV_setPosition | _NV_setPosition | `value: Vector3` | `void` | `obj:_NV_setPosition(value)` |

## SectionItem
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| item | item | Item | RW | `obj.item = <value>` |
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
| lastSeenTime | lastSeenTime | TimeOfDay | RW | `obj.lastSeenTime = <value>` |
| percievedFaction | percievedFaction | Faction | RW | `obj.percievedFaction = <value>` |
| percievedSlave | (lua_Integer | integer | RW | `obj.percievedSlave = <value>` |
| FOVScore | FOVScore | number | RW | `obj.FOVScore = <value>` |
| canSee | canSee | boolean | RW | `obj.canSee = <value>` |
| canHear | canHear | boolean | RW | `obj.canHear = <value>` |
| alarmState | alarmState | number | RW | `obj.alarmState = <value>` |
| type | type | TagsClass<SenseType> | R | `obj.type` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SeenSomeone` | `obj:_CONSTRUCTOR()` |
| lastSeenInSeconds | lastSeenInSeconds | `` | `number` | `obj:lastSeenInSeconds()` |
| getPosition | getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFaction | getFaction | `` | `Faction` | `obj:getFaction()` |

## SelectionBox
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| startPos | startPos | unknown | RW | `obj.startPos = <value>` |
| widget | (void* | lightuserdata | R | `obj.widget` |
| active | active | boolean | RW | `obj.active = <value>` |
| volume | volume | Ogre::PlaneBoundedVolume | R | `obj.volume` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| start | start | `` | `void` | `obj:start()` |
| update | update | `` | `void` | `obj:update()` |
| cancel | cancel | `` | `void` | `obj:cancel()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SelectionBox` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SenseItr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| flagsAny | flagsAny | integer | RW | `obj.flagsAny = <value>` |
| flagsNot | flagsNot | integer | RW | `obj.flagsNot = <value>` |
| _end | _end | boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > > | R | `obj._end` |
| it | it | boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > > | R | `obj.it` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| getData | getData | `` | `SeenSomeone` | `obj:getData()` |
| ended | ended | `` | `boolean` | `obj:ended()` |
| increment | increment | `` | `void` | `obj:increment()` |

## SensoryData
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| nearestEnemy | nearestEnemy | number | RW | `obj.nearestEnemy = <value>` |
| numUnconsciousAllies | numUnconsciousAllies | integer | RW | `obj.numUnconsciousAllies = <value>` |
| numConsciousAllies | numConsciousAllies | integer | RW | `obj.numConsciousAllies = <value>` |
| totalThreatLevelPersonal | totalThreatLevelPersonal | number | RW | `obj.totalThreatLevelPersonal = <value>` |
| totalThreatLevelAllies | totalThreatLevelAllies | number | RW | `obj.totalThreatLevelAllies = <value>` |
| totalIntendedThreatLevelGeneral | totalIntendedThreatLevelGeneral | number | RW | `obj.totalIntendedThreatLevelGeneral = <value>` |
| numEnemies | numEnemies | integer | RW | `obj.numEnemies = <value>` |
| numNeutrals | numNeutrals | integer | RW | `obj.numNeutrals = <value>` |
| lastThreat | lastThreat | number | RW | `obj.lastThreat = <value>` |
| currentAssessIndex | currentAssessIndex | integer | RW | `obj.currentAssessIndex = <value>` |
| currentAssessList | currentAssessList | integer | RW | `obj.currentAssessList = <value>` |
| me | me | Character | RW | `obj.me = <value>` |
| spottedSneakingPeople | &getInstance(L, 1 | SensoryData::SpottingPeopleMgr | RW | `obj.spottedSneakingPeople = <value>` |
| spottedSuspiciousPeople | &getInstance(L, 1 | SensoryData::SpottingPeopleMgr | RW | `obj.spottedSuspiciousPeople = <value>` |
| progressBar | progressBar | FloatingProgressBar | RW | `obj.progressBar = <value>` |
| progressBarStillNeeded | progressBarStillNeeded | integer | RW | `obj.progressBarStillNeeded = <value>` |
| spottedGuyIndexForProgressBar | spottedGuyIndexForProgressBar | unknown | RW | `obj.spottedGuyIndexForProgressBar = <value>` |
| amSharingThisFrame | amSharingThisFrame | boolean | RW | `obj.amSharingThisFrame = <value>` |
| assessList | assessList | lightuserdata | R | `obj.assessList` |
| flockingList | flockingList | lightuserdata | R | `obj.flockingList` |
| hearTestTimers | hearTestTimers | lightuserdata | R | `obj.hearTestTimers` |
| killList | killList | lightuserdata | R | `obj.killList` |
| seen | seen | lightuserdata | R | `obj.seen` |
| threats | threats | lightuserdata | R | `obj.threats` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SensoryData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| periodicUpdate | periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| periodicUpdate_KOed | periodicUpdate_KOed | `` | `void` | `obj:periodicUpdate_KOed()` |
| getVisionRange | getVisionRange | `inTown: boolean` | `number` | `obj:getVisionRange(inTown)` |
| update | update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| notifyKO | notifyKO | `` | `void` | `obj:notifyKO()` |
| getIterator | getIterator | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:getIterator(tagsAny, tagsNOT)` |
| getNearestEnemyDistanceSq | getNearestEnemyDistanceSq | `` | `number` | `obj:getNearestEnemyDistanceSq()` |
| canISeeThisGuy | canISeeThisGuy | `` | `boolean` | `obj:canISeeThisGuy()` |
| canIHearThisGuy | canIHearThisGuy | `` | `boolean` | `obj:canIHearThisGuy()` |
| amIAwareOfThisGuy | amIAwareOfThisGuy | `needToSeeOrHear: boolean` | `boolean` | `obj:amIAwareOfThisGuy(needToSeeOrHear)` |
| getLastKnownPositionOf | getLastKnownPositionOf | `` | `Vector3` | `obj:getLastKnownPositionOf()` |
| getDataFor | getDataFor | `` | `SeenSomeone` | `obj:getDataFor()` |
| getFactionRelation | getFactionRelation | `` | `number` | `obj:getFactionRelation()` |
| getStateBroadcast | getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getGUIData | getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| _calculateFOVScore | _calculateFOVScore | `` | `number` | `obj:_calculateFOVScore()` |
| _traceLineOfSightCheck | _traceLineOfSightCheck | `` | `boolean` | `obj:_traceLineOfSightCheck()` |
| getCharacter | getCharacter | `` | `Character` | `obj:getCharacter()` |
| dialogAssessmentUpdate | dialogAssessmentUpdate | `frameTime: number, inDepth: boolean` | `void` | `obj:dialogAssessmentUpdate(frameTime, inDepth)` |
| noticeThisPerson | noticeThisPerson | `alarmed: boolean` | `void` | `obj:noticeThisPerson(alarmed)` |
| add | add | `see: boolean, hear: boolean` | `SeenSomeone` | `obj:add(see, hear)` |
| remove | remove | `` | `void` | `obj:remove()` |
| decay | decay | `` | `void` | `obj:decay()` |
| canSee | canSee | `` | `boolean` | `obj:canSee()` |
| canHear | canHear | `` | `boolean` | `obj:canHear()` |
| disguiseMods | disguiseMods | `FOV: number` | `boolean` | `obj:disguiseMods(FOV)` |
| assessCrimes | assessCrimes | `` | `void` | `obj:assessCrimes()` |
| assessKidnapping | assessKidnapping | `` | `void` | `obj:assessKidnapping()` |
| processKillList | processKillList | `` | `void` | `obj:processKillList()` |
| assessNeutral | assessNeutral | `inDepth: boolean` | `void` | `obj:assessNeutral(inDepth)` |
| updateMyProgressBar | updateMyProgressBar | `progress: number, text: string` | `void` | `obj:updateMyProgressBar(progress, text)` |
| canISeeThisGuyDoinSneakingOrSomething | canISeeThisGuyDoinSneakingOrSomething | `FOVScore: number, spotTimeMinFOV: number, spotTimeMaxFOV: number` | `YesNoMaybe` | `obj:canISeeThisGuyDoinSneakingOrSomething(FOVScore, spotTimeMinFOV, spotTimeMaxFOV)` |
| isIntruder_Base | isIntruder_Base | `` | `boolean` | `obj:isIntruder_Base()` |
| isIntruder_Building | isIntruder_Building | `` | `boolean` | `obj:isIntruder_Building()` |
| isInMyPrivate_Building | isInMyPrivate_Building | `` | `boolean` | `obj:isInMyPrivate_Building()` |
| isEscapee | isEscapee | `` | `boolean` | `obj:isEscapee()` |
| reassess | reassess | `time: number` | `SeenSomeone` | `obj:reassess(time)` |
| addToThreatsAndFlockingList | addToThreatsAndFlockingList | `` | `void` | `obj:addToThreatsAndFlockingList()` |
| buildingSpotterUpdate | buildingSpotterUpdate | `` | `void` | `obj:buildingSpotterUpdate()` |
| notifyCriminalThreat | SensoryData_notifyCriminalThreat | `` | `void` | `obj:notifyCriminalThreat()` |
| getStateBroadcastOf | SensoryData_getStateBroadcastOf | `` | `StateBroadcastData*` | `obj:getStateBroadcastOf()` |
| _shareSensesCheck | SensoryData__shareSensesCheck | `list: userdata, time: number` | `boolean` | `obj:_shareSensesCheck(list, time)` |
| setupMyProgressBar | SensoryData_setupMyProgressBar | `` | `void` | `obj:setupMyProgressBar()` |
| reassessAll | SensoryData_reassessAll | `newTargets: userdata, time: number` | `void` | `obj:reassessAll(newTargets, time)` |

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
| timer | timer | CPerfTimer | RW | `obj.timer = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SimpleTimeStamper` | `obj:_CONSTRUCTOR()` |
| getTime | getTime | `_lastStamp: number` | `number` | `obj:getTime(_lastStamp)` |
| stampTime | stampTime | `` | `number` | `obj:stampTime()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_Slider.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mDisableEvents | mDisableEvents | boolean | RW | `obj.mDisableEvents = <value>` |
| mScrollbar | (void* | lightuserdata | R | `obj.mScrollbar` |
| mSliderName | (void* | lightuserdata | R | `obj.mSliderName` |
| mSliderValue | (void* | lightuserdata | R | `obj.mSliderValue` |
| mLoValue | mLoValue | integer | RW | `obj.mLoValue = <value>` |
| mHiValue | mHiValue | integer | RW | `obj.mHiValue = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| initialiseOverride | initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | shutdownOverride | `` | `void` | `obj:shutdownOverride()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `BaseItemType: integer, _stateEnum: integer, _specificProperty: string, _desiredSpecificProperty: boolean` | `SpecificItemLoadFirst` | `obj:_CONSTRUCTOR(BaseItemType, _stateEnum, _specificProperty, _desiredSpecificProperty)` |
| shouldSkip | shouldSkip | `` | `boolean` | `obj:shouldSkip()` |
| _NV_shouldSkip | _NV_shouldSkip | `` | `boolean` | `obj:_NV_shouldSkip()` |
| flip | flip | `` | `void` | `obj:flip()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SpeedGroup
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| position | position | Vector3 | RW | `obj.position = <value>` |
| direction | direction | Vector3 | RW | `obj.direction = <value>` |
| speed | speed | number | RW | `obj.speed = <value>` |
| last | last | integer | RW | `obj.last = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SpeedGroup` | `obj:_CONSTRUCTOR()` |
| getSpeed | getSpeed | `` | `number` | `obj:getSpeed()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SplashScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/SplashScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| currentState | currentState | integer | RW | `obj.currentState = <value>` |
| startTime | startTime | number | RW | `obj.startTime = <value>` |
| skipLogo | skipLogo | boolean | RW | `obj.skipLogo = <value>` |
| delay | delay | integer | RW | `obj.delay = <value>` |
| mainPanel | (void* | lightuserdata | R | `obj.mainPanel` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| getState | getState | `` | `integer` | `obj:getState()` |
| getEnded | getEnded | `` | `boolean` | `obj:getEnded()` |
| skip | skip | `` | `void` | `obj:skip()` |
| addLogo | addLogo | `file: string, scale: number` | `void` | `obj:addLogo(file, scale)` |

## Spot
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| timeSoFar | timeSoFar | number | RW | `obj.timeSoFar = <value>` |
| timeLimitMax | timeLimitMax | number | RW | `obj.timeLimitMax = <value>` |
| stillSeen | stillSeen | boolean | RW | `obj.stillSeen = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Spot` | `obj:_CONSTRUCTOR()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SpottingPeopleMgr` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| portraitsBox | (void* | lightuserdata | R | `obj.portraitsBox` |
| txtName | (void* | lightuserdata | R | `obj.txtName` |
| txtSquadSize | (void* | lightuserdata | R | `obj.txtSquadSize` |
| squad | (void* | lightuserdata | R | `obj.squad` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateSquadSize | updateSquadSize | `` | `void` | `obj:updateSquadSize()` |

## SquadData
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| platoon | platoon | ActivePlatoon | RW | `obj.platoon = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SquadData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |

## SquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCellSize | setCellSize | `width: integer, height: integer` | `void` | `obj:setCellSize(width, height)` |
| getItemCount | getItemCount | `` | `integer` | `obj:getItemCount()` |

## SquadListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| refresh | refresh | `` | `void` | `obj:refresh()` |
| itemSelected | itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SquadManagementScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mainWidget | (void* | lightuserdata | R | `obj.mainWidget` |
| btnAddSquad | (void* | lightuserdata | R | `obj.btnAddSquad` |
| txtFactionSize | (void* | lightuserdata | R | `obj.txtFactionSize` |
| factionSize | factionSize | integer | RW | `obj.factionSize = <value>` |
| panelSquads | (void* | lightuserdata | R | `obj.panelSquads` |
| panelDismiss | (void* | lightuserdata | R | `obj.panelDismiss` |
| dismissChar | dismissChar | Character | RW | `obj.dismissChar = <value>` |
| faction | faction | Faction | RW | `obj.faction = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `SquadManagementScreen` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getVisible | getVisible | `` | `boolean` | `obj:getVisible()` |
| update | update | `` | `void` | `obj:update()` |
| reset | reset | `` | `void` | `obj:reset()` |
| refreshSquads | refreshSquads | `` | `void` | `obj:refreshSquads()` |
| notifyEndDropSquad | notifyEndDropSquad | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropSquad(_sender, _result)` |
| notifyEndDropPortrait | notifyEndDropPortrait | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropPortrait(_sender, _result)` |
| removeSquad | removeSquad | `` | `void` | `obj:removeSquad()` |
| getSquad | getSquad | `` | `lightuserdata` | `obj:getSquad()` |
| dismissCharacter | dismissCharacter | `result: integer` | `void` | `obj:dismissCharacter(result)` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `StateT` | `obj:_CONSTRUCTOR()` |

## StaticEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | update | `spd: number` | `void` | `obj:update(spd)` |
| _NV_update | _NV_update | `spd: number` | `void` | `obj:_NV_update(spd)` |
| updateAim | updateAim | `rotSpeed: number, target: Vector3` | `number` | `obj:updateAim(rotSpeed, target)` |
| _NV_updateAim | _NV_updateAim | `rotSpeed: number, target: Vector3` | `number` | `obj:_NV_updateAim(rotSpeed, target)` |
| isRotatingEnt | isRotatingEnt | `` | `boolean` | `obj:isRotatingEnt()` |
| _NV_isRotatingEnt | _NV_isRotatingEnt | `` | `boolean` | `obj:_NV_isRotatingEnt()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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
| _CONSTRUCTOR | _CONSTRUCTOR | `_level: integer` | `Sword` | `obj:_CONSTRUCTOR(_level)` |
| getClassType | getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| isSword | isSword | `` | `Sword` | `obj:isSword()` |
| _NV_isSword | _NV_isSword | `` | `Sword` | `obj:_NV_isSword()` |
| setupStats | setupStats | `_level: integer` | `void` | `obj:setupStats(_level)` |
| getSkillModIndoors | getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| _NV_getSkillModIndoors | _NV_getSkillModIndoors | `` | `integer` | `obj:_NV_getSkillModIndoors()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SysMessage
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| msg | (lua_Integer | integer | RW | `obj.msg = <value>` |
| target | target | unknown | RW | `obj.target = <value>` |
| from | from | unknown | RW | `obj.from = <value>` |
| on | on | boolean | RW | `obj.on = <value>` |
| number | number | number | RW | `obj.number = <value>` |
| data | (void* | lightuserdata | R | `obj.data` |

## TagsClass
**Header:** `extern/KenshiLib/Include/kenshi/util/TagsClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| flags | flags | integer | RW | `obj.flags = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| clearAll | clearAll | `` | `void` | `obj:clearAll()` |
| hasNONEOfTheseBitsSet | hasNONEOfTheseBitsSet | `flagsToTest: integer` | `boolean` | `obj:hasNONEOfTheseBitsSet(flagsToTest)` |
| hasANYOfTheseBitsSet | hasANYOfTheseBitsSet | `flagsToTest: integer` | `boolean` | `obj:hasANYOfTheseBitsSet(flagsToTest)` |

## TaskData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| infrequentGoalChecks | infrequentGoalChecks | boolean | RW | `obj.infrequentGoalChecks = <value>` |
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
| results | results | unknown | RW | `obj.results = <value>` |
| numRequirements | numRequirements | integer | RW | `obj.numRequirements = <value>` |
| requirements | requirements | unknown | RW | `obj.requirements = <value>` |
| scoreFunction | (void* | lightuserdata | R | `obj.scoreFunction` |
| justDoOneTarget | justDoOneTarget | boolean | RW | `obj.justDoOneTarget = <value>` |
| subTask | subTask | TaskStateData | RW | `obj.subTask = <value>` |
| dialogueDelivery | (lua_Integer | integer | RW | `obj.dialogueDelivery = <value>` |
| hasAction | hasAction | boolean | RW | `obj.hasAction = <value>` |
| description | description | string | RW | `obj.description = <value>` |
| _findTarget | (void* | lightuserdata | R | `obj._findTarget` |
| permaJob | permaJob | PermajobType | R | `obj.permaJob` |

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
| val | val | boolean | RW | `obj.val = <value>` |
| progressionOnly | progressionOnly | boolean | RW | `obj.progressionOnly = <value>` |
| key | key | StateType | R | `obj.key` |

## Tasker
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| resetsWhenDone | resetsWhenDone | boolean | RW | `obj.resetsWhenDone = <value>` |
| subject | subject | unknown | RW | `obj.subject = <value>` |
| weight | weight | number | RW | `obj.weight = <value>` |
| currentSubTarget | currentSubTarget | unknown | RW | `obj.currentSubTarget = <value>` |
| location | location | Vector3 | RW | `obj.location = <value>` |
| startTime | startTime | integer | RW | `obj.startTime = <value>` |
| endTime | endTime | integer | RW | `obj.endTime = <value>` |
| taskData | taskData | TaskData | RW | `obj.taskData = <value>` |
| priority | (lua_Integer | integer | RW | `obj.priority = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Tasker` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| checkTimeOfDay | checkTimeOfDay | `` | `boolean` | `obj:checkTimeOfDay()` |
| getFrameTime | getFrameTime | `` | `number` | `obj:getFrameTime()` |
| key | key | `` | `integer` | `obj:key()` |
| unSkippableJob | unSkippableJob | `` | `boolean` | `obj:unSkippableJob()` |
| getLocation | getLocation | `` | `Vector3` | `obj:getLocation()` |
| setLocation | setLocation | `loc: Vector3` | `void` | `obj:setLocation(loc)` |
| sameAs | sameAs | `` | `boolean` | `obj:sameAs()` |
| hasActionFunc | hasActionFunc | `` | `boolean` | `obj:hasActionFunc()` |
| isSubTasker | isSubTasker | `` | `boolean` | `obj:isSubTasker()` |
| getSubTask | getSubTask | `` | `TaskStateData` | `obj:getSubTask()` |
| isInfiniteGoal | isInfiniteGoal | `` | `boolean` | `obj:isInfiniteGoal()` |
| needsSubjectOrLocation | needsSubjectOrLocation | `` | `boolean` | `obj:needsSubjectOrLocation()` |
| getTaskData | getTaskData | `` | `TaskData` | `obj:getTaskData()` |
| startAction | startAction | `` | `void` | `obj:startAction()` |
| _NV_startAction | _NV_startAction | `` | `void` | `obj:_NV_startAction()` |
| runAction | runAction | `` | `void` | `obj:runAction()` |
| endAction | endAction | `` | `void` | `obj:endAction()` |
| _NV_endAction | _NV_endAction | `` | `void` | `obj:_NV_endAction()` |
| taskSaysItsFinished | taskSaysItsFinished | `` | `boolean` | `obj:taskSaysItsFinished()` |
| _NV_taskSaysItsFinished | _NV_taskSaysItsFinished | `` | `boolean` | `obj:_NV_taskSaysItsFinished()` |
| score | score | `ai: userdata` | `number` | `obj:score(ai)` |
| isResultsComplete | isResultsComplete | `ai: userdata` | `boolean` | `obj:isResultsComplete(ai)` |
| isResultsComplete_ignoreSubtasker | isResultsComplete_ignoreSubtasker | `ai: userdata` | `boolean` | `obj:isResultsComplete_ignoreSubtasker(ai)` |
| isRequirementsComplete | isRequirementsComplete | `ai: userdata, autoTargetFinder: boolean` | `boolean` | `obj:isRequirementsComplete(ai, autoTargetFinder)` |
| getRequirementComplaint | getRequirementComplaint | `ai: userdata, autoTargetFinder: boolean` | `string` | `obj:getRequirementComplaint(ai, autoTargetFinder)` |
| getNextSubTarget | getNextSubTarget | `ai: userdata` | `hand` | `obj:getNextSubTarget(ai)` |

## Terrain
**Header:** `extern/KenshiLib/Include/kenshi/terrain.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mCamera | (void* | lightuserdata | RW | `obj.mCamera = <value>` |
| mCameraPosition | mCameraPosition | Vector3 | RW | `obj.mCameraPosition = <value>` |
| mStream | (void* | lightuserdata | R | `obj.mStream` |
| mTerrain | (void* | lightuserdata | R | `obj.mTerrain` |
| mSize | mSize | number | RW | `obj.mSize = <value>` |
| mHeight | mHeight | number | RW | `obj.mHeight = <value>` |
| mHeightScale | mHeightScale | number | RW | `obj.mHeightScale = <value>` |
| mOffset | mOffset | number | RW | `obj.mOffset = <value>` |
| mSizeScale | mSizeScale | number | RW | `obj.mSizeScale = <value>` |
| mBuildCounter | mBuildCounter | integer | RW | `obj.mBuildCounter = <value>` |
| mNeedsBuilding | mNeedsBuilding | boolean | RW | `obj.mNeedsBuilding = <value>` |
| mPatchesToBuild | mPatchesToBuild | integer | RW | `obj.mPatchesToBuild = <value>` |
| mOnscreenLimit | mOnscreenLimit | integer | RW | `obj.mOnscreenLimit = <value>` |
| mOffscreenLimit | mOffscreenLimit | integer | RW | `obj.mOffscreenLimit = <value>` |
| mDrawableCount | mDrawableCount | integer | RW | `obj.mDrawableCount = <value>` |
| mMaterialDistance | mMaterialDistance | number | RW | `obj.mMaterialDistance = <value>` |
| mHeightCacheSize | mHeightCacheSize | integer | RW | `obj.mHeightCacheSize = <value>` |
| mHeightCacheBox | mHeightCacheBox | lightuserdata | RW | `obj.mHeightCacheBox = <value>` |
| mCachePositionX | mCachePositionX | integer | RW | `obj.mCachePositionX = <value>` |
| mCachePositionY | mCachePositionY | integer | RW | `obj.mCachePositionY = <value>` |
| mHeightCache | (void* | lightuserdata | RW | `obj.mHeightCache = <value>` |
| mBloodCamera | (void* | lightuserdata | R | `obj.mBloodCamera` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getBoundingRadius | getBoundingRadius | `` | `number` | `obj:getBoundingRadius()` |

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

## ThreadClass
**Header:** `extern/KenshiLib/Include/kenshi/threadclass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| threadHandle | (void* | lightuserdata | R | `obj.threadHandle` |
| threadID | threadID | integer | RW | `obj.threadID = <value>` |
| _running | _running | boolean | RW | `obj._running = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| frameTime | frameTime | number | RW | `obj.frameTime = <value>` |
| infiniteMode | infiniteMode | boolean | RW | `obj.infiniteMode = <value>` |
| pretendThread | pretendThread | boolean | RW | `obj.pretendThread = <value>` |
| runMute | runMute | lightuserdata | R | `obj.runMute` |
| lockedWhileRunningMute | lockedWhileRunningMute | lightuserdata | R | `obj.lockedWhileRunningMute` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| stopRunning | stopRunning | `` | `void` | `obj:stopRunning()` |
| canIRun | canIRun | `` | `boolean` | `obj:canIRun()` |
| startRunning | startRunning | `time: number` | `boolean` | `obj:startRunning(time)` |
| isRunning | isRunning | `` | `boolean` | `obj:isRunning()` |
| waitForRunningStop_Blocking | waitForRunningStop_Blocking | `` | `boolean` | `obj:waitForRunningStop_Blocking()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `_name: string` | `lightuserdata` | `obj:_CONSTRUCTOR(_name)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setup | setup | `_frameTime: number, infinite: boolean, _pretendThread: boolean` | `void` | `obj:setup(_frameTime, infinite, _pretendThread)` |
| beginThread | beginThread | `_frameTime: number, infinite: boolean, priority: integer` | `boolean` | `obj:beginThread(_frameTime, infinite, priority)` |
| setThreadName | setThreadName | `threadName: string` | `void` | `obj:setThreadName(threadName)` |
| endThread | endThread | `` | `void` | `obj:endThread()` |
| setName | setName | `name: string` | `void` | `obj:setName(name)` |
| threadProc | threadProc | `` | `integer` | `obj:threadProc()` |

## ThreadWannabe
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mute | mute | lightuserdata | R | `obj.mute` |
| paused | paused | boolean | RW | `obj.paused = <value>` |
| speedMult | speedMult | number | RW | `obj.speedMult = <value>` |
| haltEverythingMutex | haltEverythingMutex | lightuserdata | R | `obj.haltEverythingMutex` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `threadname: string` | `lightuserdata` | `obj:_CONSTRUCTOR(threadname)` |
| backThreadUpdate | backThreadUpdate | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| isPaused | isPaused | `` | `boolean` | `obj:isPaused()` |
| setPaused | setPaused | `on: boolean, _speedMult: number` | `void` | `obj:setPaused(on, _speedMult)` |
| threadProc | threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| forceLoopMT | forceLoopMT | `` | `void` | `obj:forceLoopMT()` |
| _NV_forceLoopMT | _NV_forceLoopMT | `` | `void` | `obj:_NV_forceLoopMT()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

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

## TimerClass
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## TitleScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/TitleScreen.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| newGameWindow | newGameWindow | NewGameWindow | RW | `obj.newGameWindow = <value>` |
| creditsPanel | (void* | lightuserdata | R | `obj.creditsPanel` |
| creditsText | (void* | lightuserdata | R | `obj.creditsText` |
| creditsLoaded | creditsLoaded | boolean | RW | `obj.creditsLoaded = <value>` |
| creditsPosition | creditsPosition | number | RW | `obj.creditsPosition = <value>` |

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
| closeTheOtherBits | closeTheOtherBits | `` | `boolean` | `obj:closeTheOtherBits()` |
| setCreditsVisible | setCreditsVisible | `value: boolean` | `void` | `obj:setCreditsVisible(value)` |

## ToolTip
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

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
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ToolTipDynamic` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## ToolTipFixed
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

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
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| compareTooltip | compareTooltip | ToolTipInventory | RW | `obj.compareTooltip = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ToolTipInventory` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |

## ToolTipLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

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
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

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
| replacementTown | replacementTown | GameData | RW | `obj.replacementTown = <value>` |
| isAccessible | isAccessible | boolean | RW | `obj.isAccessible = <value>` |
| alarms | (void* | lightuserdata | RW | `obj.alarms = <value>` |
| instanceID | instanceID | InstanceID | RW | `obj.instanceID = <value>` |
| openToPublic | openToPublic | boolean | RW | `obj.openToPublic = <value>` |
| minFoliageRange | minFoliageRange | number | RW | `obj.minFoliageRange = <value>` |
| playerTownLevel | playerTownLevel | integer | RW | `obj.playerTownLevel = <value>` |
| playerHasBuildingsInThisTown | playerHasBuildingsInThisTown | boolean | RW | `obj.playerHasBuildingsInThisTown = <value>` |
| batteryMode | batteryMode | boolean | RW | `obj.batteryMode = <value>` |
| power_Stat | power_Stat | number | RW | `obj.power_Stat = <value>` |
| maxPower_Stat | maxPower_Stat | number | RW | `obj.maxPower_Stat = <value>` |
| neededPowerTotal_Stat | neededPowerTotal_Stat | number | RW | `obj.neededPowerTotal_Stat = <value>` |
| batteryPowerTotal_Stat | batteryPowerTotal_Stat | number | RW | `obj.batteryPowerTotal_Stat = <value>` |
| batteryDrain_Stat | batteryDrain_Stat | number | RW | `obj.batteryDrain_Stat = <value>` |
| batteryChargingupTotal | batteryChargingupTotal | number | RW | `obj.batteryChargingupTotal = <value>` |
| batteryCharge_Stat | batteryCharge_Stat | number | RW | `obj.batteryCharge_Stat = <value>` |
| batteryChargeMax_Stat | batteryChargeMax_Stat | number | RW | `obj.batteryChargeMax_Stat = <value>` |
| tradeCulture | tradeCulture | TradeCulture | RW | `obj.tradeCulture = <value>` |
| buildingMaterial | buildingMaterial | GameData | RW | `obj.buildingMaterial = <value>` |
| distantTown | (void* | lightuserdata | RW | `obj.distantTown = <value>` |
| nestsLoaded | nestsLoaded | boolean | RW | `obj.nestsLoaded = <value>` |
| overrideRange | overrideRange | number | RW | `obj.overrideRange = <value>` |
| townRangeMultiplier | townRangeMultiplier | number | RW | `obj.townRangeMultiplier = <value>` |
| _facilitesWeHaveHere | (lua_Integer | integer | RW | `obj._facilitesWeHaveHere = <value>` |
| batteryList | batteryList | ogre_unordered_set<hand>::type | RW | `obj.batteryList = <value>` |
| gates | gates | ogre_unordered_set<hand>::type | RW | `obj.gates = <value>` |
| nestSpots | nestSpots | Vector3 | RW | `obj.nestSpots = <value>` |
| powerInList | powerInList | unknown | RW | `obj.powerInList = <value>` |
| powerOutList | powerOutList | ogre_unordered_set<hand>::type | RW | `obj.powerOutList = <value>` |
| tradeGoodsMults | tradeGoodsMults | unknown | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `Town` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| initialiseResidentData | initialiseResidentData | `` | `void` | `obj:initialiseResidentData()` |
| getGameData | getGameData | `` | `GameData` | `obj:getGameData()` |
| _NV_getGameData | _NV_getGameData | `` | `GameData` | `obj:_NV_getGameData()` |
| getOriginalGameData | getOriginalGameData | `` | `GameData` | `obj:getOriginalGameData()` |
| notifyRepopulation | notifyRepopulation | `` | `void` | `obj:notifyRepopulation()` |
| isMyOldHomeTownStillValid | isMyOldHomeTownStillValid | `` | `boolean` | `obj:isMyOldHomeTownStillValid()` |
| setup | setup | `_pos: Vector3` | `void` | `obj:setup(_pos)` |
| _NV_setup | _NV_setup | `_pos: Vector3` | `void` | `obj:_NV_setup(_pos)` |
| _reset | _reset | `` | `void` | `obj:_reset()` |
| _NV__reset | _NV__reset | `` | `void` | `obj:_NV__reset()` |
| getDataType | getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| reassessTownPosition | reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| _NV_reassessTownPosition | _NV_reassessTownPosition | `` | `void` | `obj:_NV_reassessTownPosition()` |
| showDistantTown | showDistantTown | `vis: boolean` | `void` | `obj:showDistantTown(vis)` |
| getAlarmMgr | getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| _NV_getAlarmMgr | _NV_getAlarmMgr | `` | `lightuserdata` | `obj:_NV_getAlarmMgr()` |
| isOutpost | isOutpost | `` | `boolean` | `obj:isOutpost()` |
| _setMainResident | _setMainResident | `forceForGates: boolean` | `boolean` | `obj:_setMainResident(forceForGates)` |
| spawnTheBarFlies | spawnTheBarFlies | `` | `void` | `obj:spawnTheBarFlies()` |
| townLoadedEvent | townLoadedEvent | `newGameFirstTime: boolean` | `void` | `obj:townLoadedEvent(newGameFirstTime)` |
| notifyUnloading | notifyUnloading | `` | `void` | `obj:notifyUnloading()` |
| getBuildingMaterial | getBuildingMaterial | `` | `GameData` | `obj:getBuildingMaterial()` |
| getLocalTradePriceMult | getLocalTradePriceMult | `` | `number` | `obj:getLocalTradePriceMult()` |
| getFactionTradeCultureMult | getFactionTradeCultureMult | `` | `number` | `obj:getFactionTradeCultureMult()` |
| isTown | isTown | `` | `Town` | `obj:isTown()` |
| _NV_isTown | _NV_isTown | `` | `Town` | `obj:_NV_isTown()` |
| isNest | isNest | `` | `lightuserdata` | `obj:isNest()` |
| _NV_isNest | _NV_isNest | `` | `lightuserdata` | `obj:_NV_isNest()` |
| isPublic | isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| saveState | saveState | `` | `void` | `obj:saveState()` |
| _NV_saveState | _NV_saveState | `` | `void` | `obj:_NV_saveState()` |
| loadState | loadState | `` | `void` | `obj:loadState()` |
| _NV_loadState | _NV_loadState | `` | `void` | `obj:_NV_loadState()` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| needsSaving | needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| _NV_needsSaving | _NV_needsSaving | `mod: string` | `boolean` | `obj:_NV_needsSaving(mod)` |
| setPosition | setPosition | `p: Vector3` | `void` | `obj:setPosition(p)` |
| saveStateEditor | saveStateEditor | `` | `void` | `obj:saveStateEditor()` |
| _NV_saveStateEditor | _NV_saveStateEditor | `` | `void` | `obj:_NV_saveStateEditor()` |
| loadStateEditor | loadStateEditor | `` | `void` | `obj:loadStateEditor()` |
| _NV_loadStateEditor | _NV_loadStateEditor | `` | `void` | `obj:_NV_loadStateEditor()` |
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
| hasResidentHQ | hasResidentHQ | `` | `boolean` | `obj:hasResidentHQ()` |
| _NV_hasResidentHQ | _NV_hasResidentHQ | `` | `boolean` | `obj:_NV_hasResidentHQ()` |
| gatesAllClosed | gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| _NV_gatesAllClosed | _NV_gatesAllClosed | `` | `boolean` | `obj:_NV_gatesAllClosed()` |
| hasGates | hasGates | `` | `boolean` | `obj:hasGates()` |
| _NV_hasGates | _NV_hasGates | `` | `boolean` | `obj:_NV_hasGates()` |
| notifyAccesibility | notifyAccesibility | `accessible: boolean` | `void` | `obj:notifyAccesibility(accessible)` |
| getNearestGate | getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| _NV_getNearestGate | _NV_getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:_NV_getNearestGate(to)` |
| getPositionOutsideTownGates | getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| _NV_getPositionOutsideTownGates | _NV_getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:_NV_getPositionOutsideTownGates(dist)` |
| addBuilding | addBuilding | `powerIn: boolean, powerOut: boolean, battery: boolean` | `void` | `obj:addBuilding(powerIn, powerOut, battery)` |
| removeBuilding | removeBuilding | `` | `void` | `obj:removeBuilding()` |
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
| addNest | addNest | `pos: Vector3` | `void` | `obj:addNest(pos)` |
| removeNest | removeNest | `` | `boolean` | `obj:removeNest()` |
| clearNests | clearNests | `` | `void` | `obj:clearNests()` |
| getMapMarker | getMapMarker | `` | `string` | `obj:getMapMarker()` |
| _NV_getMapMarker | _NV_getMapMarker | `` | `string` | `obj:_NV_getMapMarker()` |
| getMapMarkerZoomLevel | getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| _NV_getMapMarkerZoomLevel | _NV_getMapMarkerZoomLevel | `` | `integer` | `obj:_NV_getMapMarkerZoomLevel()` |
| recalculatePlayerTownLevel | recalculatePlayerTownLevel | `` | `void` | `obj:recalculatePlayerTownLevel()` |
| deActivationCheck | deActivationCheck | `` | `void` | `obj:deActivationCheck()` |
| _initialiseResidentData | _initialiseResidentData | `` | `void` | `obj:_initialiseResidentData()` |
| chooseResidents | chooseResidents | `` | `void` | `obj:chooseResidents()` |
| chooseBuildingForResident | chooseBuildingForResident | `` | `Building` | `obj:chooseBuildingForResident()` |

## TownBase
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| positionCacher | positionCacher | TownPositionCacher | RW | `obj.positionCacher = <value>` |
| population | (void* | lightuserdata | R | `obj.population` |
| alreadyInitialisedPopulationParams | alreadyInitialisedPopulationParams | boolean | RW | `obj.alreadyInitialisedPopulationParams = <value>` |
| isSecret | isSecret | boolean | RW | `obj.isSecret = <value>` |
| timeOfDeath | timeOfDeath | TimeOfDay | RW | `obj.timeOfDeath = <value>` |
| p_TIME | p_TIME | number | RW | `obj.p_TIME = <value>` |
| nestBatcher | (void* | lightuserdata | R | `obj.nestBatcher` |
| unexploredName | unexploredName | string | RW | `obj.unexploredName = <value>` |
| discovered | discovered | boolean | RW | `obj.discovered = <value>` |
| explored | explored | boolean | RW | `obj.explored = <value>` |
| recentlyDiscovered | recentlyDiscovered | boolean | RW | `obj.recentlyDiscovered = <value>` |
| entityMarker | (void* | lightuserdata | R | `obj.entityMarker` |
| entityLabel | entityLabel | ScreenLabel | RW | `obj.entityLabel = <value>` |
| clickHull | (void* | lightuserdata | R | `obj.clickHull` |
| biome | (void* | lightuserdata | R | `obj.biome` |
| isActivated | isActivated | boolean | RW | `obj.isActivated = <value>` |
| currentFloorVisibility | currentFloorVisibility | integer | RW | `obj.currentFloorVisibility = <value>` |
| buildingsManager | buildingsManager | TownBuildingsManager | RW | `obj.buildingsManager = <value>` |
| defaultResident | defaultResident | GameData | RW | `obj.defaultResident = <value>` |
| alarmState | alarmState | TownAlarmState | R | `obj.alarmState` |
| artifacts | artifacts | Ogre::FastArray<ArtifactItemData> | R | `obj.artifacts` |
| factionsResidentHere | factionsResidentHere | std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > | R | `obj.factionsResidentHere` |
| myZoneCoverage | myZoneCoverage | ogre_unordered_set<ZoneMap*>::type | R | `obj.myZoneCoverage` |
| occupiers | occupiers | std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > | R | `obj.occupiers` |
| populatedZones | populatedZones | ogre_unordered_map<ZoneMap*, bool>::type | R | `obj.populatedZones` |
| residentsSpawned | residentsSpawned | lektor<TownBase::ResidentData> | RW | `obj.residentsSpawned = <value>` |
| residentsSpawned_BarsOrSomething | residentsSpawned_BarsOrSomething | lektor<TownBase::ResidentData> | RW | `obj.residentsSpawned_BarsOrSomething = <value>` |
| townType | townType | integer | RW | `obj.townType = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TownBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| activate | activate | `` | `void` | `obj:activate()` |
| _NV_activate | _NV_activate | `` | `void` | `obj:_NV_activate()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| _NV_isActive | _NV_isActive | `` | `boolean` | `obj:_NV_isActive()` |
| setup | setup | `_pos: Vector3` | `void` | `obj:setup(_pos)` |
| _NV_setup | _NV_setup | `_pos: Vector3` | `void` | `obj:_NV_setup(_pos)` |
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
| isNest | isNest | `` | `lightuserdata` | `obj:isNest()` |
| nestUpThisSpot | nestUpThisSpot | `pos: Vector3` | `void` | `obj:nestUpThisSpot(pos)` |
| _NV_nestUpThisSpot | _NV_nestUpThisSpot | `pos: Vector3` | `void` | `obj:_NV_nestUpThisSpot(pos)` |
| loadFromSerialise | loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| isOutpost | isOutpost | `` | `boolean` | `obj:isOutpost()` |
| withinBordersRange | withinBordersRange | `p: Vector3, mult: number` | `boolean` | `obj:withinBordersRange(p, mult)` |
| withinDiscoveryRange | withinDiscoveryRange | `p: Vector3, explored: boolean` | `boolean` | `obj:withinDiscoveryRange(p, explored)` |
| isIllegal | isIllegal | `` | `boolean` | `obj:isIllegal()` |
| _NV_isIllegal | _NV_isIllegal | `` | `boolean` | `obj:_NV_isIllegal()` |
| distanceTo | distanceTo | `to: Vector3` | `number` | `obj:distanceTo(to)` |
| squaredDistanceTo | squaredDistanceTo | `to: Vector3` | `number` | `obj:squaredDistanceTo(to)` |
| isDead | isDead | `` | `boolean` | `obj:isDead()` |
| _NV_isDead | _NV_isDead | `` | `boolean` | `obj:_NV_isDead()` |
| getPositionOutsideTownGates | getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| _NV_getPositionOutsideTownGates | _NV_getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:_NV_getPositionOutsideTownGates(dist)` |
| setFaction | setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| isPublic | isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| getRadius | getRadius | `` | `number` | `obj:getRadius()` |
| _NV_getRadius | _NV_getRadius | `` | `number` | `obj:_NV_getRadius()` |
| getGUIData | getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| saveState | saveState | `` | `void` | `obj:saveState()` |
| _NV_saveState | _NV_saveState | `` | `void` | `obj:_NV_saveState()` |
| loadState | loadState | `` | `void` | `obj:loadState()` |
| _NV_loadState | _NV_loadState | `` | `void` | `obj:_NV_loadState()` |
| update | update | `` | `void` | `obj:update()` |
| _NV_update | _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| updatePowerGrid | updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| _NV_updatePowerGrid | _NV_updatePowerGrid | `` | `void` | `obj:_NV_updatePowerGrid()` |
| hasResidentHQ | hasResidentHQ | `` | `boolean` | `obj:hasResidentHQ()` |
| _NV_hasResidentHQ | _NV_hasResidentHQ | `` | `boolean` | `obj:_NV_hasResidentHQ()` |
| findAllBuildingsOfType | findAllBuildingsOfType | `func: integer` | `lightuserdata` | `obj:findAllBuildingsOfType(func)` |
| _NV_findAllBuildingsOfType | _NV_findAllBuildingsOfType | `func: integer` | `lightuserdata` | `obj:_NV_findAllBuildingsOfType(func)` |
| findAllBuildingsWithFunction | findAllBuildingsWithFunction | `func: integer` | `lightuserdata` | `obj:findAllBuildingsWithFunction(func)` |
| _NV_findAllBuildingsWithFunction | _NV_findAllBuildingsWithFunction | `func: integer` | `lightuserdata` | `obj:_NV_findAllBuildingsWithFunction(func)` |
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
| getAlarmMgr | getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| _NV_getAlarmMgr | _NV_getAlarmMgr | `` | `lightuserdata` | `obj:_NV_getAlarmMgr()` |
| hasGates | hasGates | `` | `boolean` | `obj:hasGates()` |
| _NV_hasGates | _NV_hasGates | `` | `boolean` | `obj:_NV_hasGates()` |
| gatesAllClosed | gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| _NV_gatesAllClosed | _NV_gatesAllClosed | `` | `boolean` | `obj:_NV_gatesAllClosed()` |
| getNearestGate | getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| _NV_getNearestGate | _NV_getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:_NV_getNearestGate(to)` |
| getBiome | getBiome | `` | `lightuserdata` | `obj:getBiome()` |
| _NV_getBiome | _NV_getBiome | `` | `lightuserdata` | `obj:_NV_getBiome()` |
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
| setZonePopulated | setZonePopulated | `` | `void` | `obj:setZonePopulated()` |
| getBuildingsManager | getBuildingsManager | `` | `TownBuildingsManager` | `obj:getBuildingsManager()` |
| getBuildingFloorVisibility | getBuildingFloorVisibility | `` | `integer` | `obj:getBuildingFloorVisibility()` |
| setBuildingsFloorVisibility | setBuildingsFloorVisibility | `floor: integer` | `void` | `obj:setBuildingsFloorVisibility(floor)` |
| resetBuildingsFloorVisibility | resetBuildingsFloorVisibility | `` | `void` | `obj:resetBuildingsFloorVisibility()` |
| getTownFloorVisiblity | getTownFloorVisiblity | `` | `integer` | `obj:getTownFloorVisiblity()` |
| setTownFloorVisiblity | setTownFloorVisiblity | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setTownFloorVisiblity(floor, onlyPlayerBuildings)` |
| resetTownFloorVisibility | resetTownFloorVisibility | `` | `void` | `obj:resetTownFloorVisibility()` |
| getCurrentTownLocation | getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| getMapMarker | getMapMarker | `` | `string` | `obj:getMapMarker()` |
| _NV_getMapMarker | _NV_getMapMarker | `` | `string` | `obj:_NV_getMapMarker()` |
| getMapMarkerZoomLevel | getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| _NV_getMapMarkerZoomLevel | _NV_getMapMarkerZoomLevel | `` | `integer` | `obj:_NV_getMapMarkerZoomLevel()` |
| isOccupied | isOccupied | `` | `boolean` | `obj:isOccupied()` |
| _nestUpThisSpot | _nestUpThisSpot | `pos: Vector3` | `void` | `obj:_nestUpThisSpot(pos)` |
| _NV__nestUpThisSpot | _NV__nestUpThisSpot | `pos: Vector3` | `void` | `obj:_NV__nestUpThisSpot(pos)` |
| distributeArtifacts | distributeArtifacts | `` | `void` | `obj:distributeArtifacts()` |
| getUnexploredName | TownBase_getUnexploredName | `` | `string` | `obj:getUnexploredName()` |
| _NV_getUnexploredName | TownBase__NV_getUnexploredName | `` | `string` | `obj:_NV_getUnexploredName()` |

## TownBuildingsManager
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| signsVisible | signsVisible | boolean | RW | `obj.signsVisible = <value>` |
| town | town | TownBase | RW | `obj.town = <value>` |
| buildingEntities | buildingEntities | ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type | R | `obj.buildingEntities` |
| instancesManagers | instancesManagers | boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > > | R | `obj.instancesManagers` |
| signs | signs | Ogre::FastArray<std::pair<Building*, Ogre::Entity*> > | R | `obj.signs` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TownBuildingsManager` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | clear | `` | `void` | `obj:clear()` |
| moveBuildingsTo | moveBuildingsTo | `` | `void` | `obj:moveBuildingsTo()` |
| removeBuilding | removeBuilding | `` | `void` | `obj:removeBuilding()` |
| setFloorVisible | setFloorVisible | `floor: integer` | `void` | `obj:setFloorVisible(floor)` |
| setAllVisible | setAllVisible | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setAllVisible(floor, onlyPlayerBuildings)` |
| resetAllVisible | resetAllVisible | `` | `void` | `obj:resetAllVisible()` |
| setSignsVisible | setSignsVisible | `value: boolean` | `void` | `obj:setSignsVisible(value)` |
| factoryObjectCreatedCallback | factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _NV_factoryObjectCreatedCallback | _NV_factoryObjectCreatedCallback | `` | `void` | `obj:_NV_factoryObjectCreatedCallback()` |

## TownListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| formatItem | formatItem | `` | `string` | `obj:formatItem()` |
| _NV_formatItem | _NV_formatItem | `` | `string` | `obj:_NV_formatItem()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TownPositionCacher
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| lastUpdateStamp | lastUpdateStamp | TimeOfDay | RW | `obj.lastUpdateStamp = <value>` |
| updateRateInHours | updateRateInHours | number | RW | `obj.updateRateInHours = <value>` |
| pos | pos | Vector3 | RW | `obj.pos = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TownPositionCacher` | `obj:_CONSTRUCTOR()` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `value: integer` | `TradeResult` | `obj:_CONSTRUCTOR(value)` |
| showMessage | showMessage | `` | `void` | `obj:showMessage()` |

## TraderInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| scrollBackpack | (void* | lightuserdata | R | `obj.scrollBackpack` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TransformWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/TransformWindow.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| window | window | DatapanelGUI | RW | `obj.window = <value>` |
| windowXValue | windowXValue | DataPanelLine_TextEditable | RW | `obj.windowXValue = <value>` |
| windowYValue | windowYValue | DataPanelLine_TextEditable | RW | `obj.windowYValue = <value>` |
| windowZValue | windowZValue | DataPanelLine_TextEditable | RW | `obj.windowZValue = <value>` |
| modeButton | modeButton | DataPanelLine_Button | RW | `obj.modeButton = <value>` |
| axisButton | axisButton | DataPanelLine_Button | RW | `obj.axisButton = <value>` |
| revertButton | revertButton | DataPanelLine_Button | RW | `obj.revertButton = <value>` |
| node | (void* | lightuserdata | R | `obj.node` |
| parentNode | (void* | lightuserdata | R | `obj.parentNode` |
| gizmo | (void* | lightuserdata | R | `obj.gizmo` |
| mode | mode | integer | RW | `obj.mode = <value>` |
| coordinateSystem | coordinateSystem | integer | RW | `obj.coordinateSystem = <value>` |
| hasScale | hasScale | boolean | RW | `obj.hasScale = <value>` |
| lastZone | lastZone | ZoneMap | RW | `obj.lastZone = <value>` |
| currentZone | currentZone | ZoneMap | RW | `obj.currentZone = <value>` |
| currentInstance | currentInstance | InstanceID | RW | `obj.currentInstance = <value>` |
| changed | changed | boolean | RW | `obj.changed = <value>` |
| editChanged | editChanged | boolean | RW | `obj.editChanged = <value>` |
| lastMouse | lastMouse | unknown | RW | `obj.lastMouse = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TransformWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCaption | setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| updateState | updateState | `` | `void` | `obj:updateState()` |
| close | close | `` | `void` | `obj:close()` |
| refresh | refresh | `` | `void` | `obj:refresh()` |
| updateGizmo | updateGizmo | `` | `boolean` | `obj:updateGizmo()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| isVisible | isVisible | `` | `boolean` | `obj:isVisible()` |
| hasChanged | hasChanged | `` | `boolean` | `obj:hasChanged()` |
| clearChangedFlag | clearChangedFlag | `` | `void` | `obj:clearChangedFlag()` |
| getMode | getMode | `` | `integer` | `obj:getMode()` |
| setMode | setMode | `m: integer` | `boolean` | `obj:setMode(m)` |
| getLastZone | getLastZone | `` | `ZoneMap` | `obj:getLastZone()` |
| getZone | getZone | `` | `ZoneMap` | `obj:getZone()` |
| changeMode | changeMode | `` | `void` | `obj:changeMode()` |
| changeCoord | changeCoord | `` | `void` | `obj:changeCoord()` |
| changeValue | changeValue | `` | `void` | `obj:changeValue()` |
| reset | reset | `` | `void` | `obj:reset()` |
| revert | revert | `` | `void` | `obj:revert()` |

## TreeData
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| position | position | Vector3 | RW | `obj.position = <value>` |
| scale | scale | number | RW | `obj.scale = <value>` |
| target | (void* | lightuserdata | R | `obj.target` |
| building | building | Building | RW | `obj.building = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TriggerCallback
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateFrameEndMT | updateFrameEndMT | `` | `void` | `obj:updateFrameEndMT()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TripleInt
**Header:** `extern/KenshiLib/Include/kenshi/util/TripleInt.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| value | value | unknown | RW | `obj.value = <value>` |

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
| currentTutorialItem | currentTutorialItem | TutorialItem | RW | `obj.currentTutorialItem = <value>` |
| flashNewItem | flashNewItem | boolean | RW | `obj.flashNewItem = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TutorialGUI` | `obj:_CONSTRUCTOR()` |
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
| removeTutorialFromList | removeTutorialFromList | `` | `void` | `obj:removeTutorialFromList()` |
| arrangeList | arrangeList | `` | `void` | `obj:arrangeList()` |
| refreshUI | refreshUI | `` | `void` | `obj:refreshUI()` |
| showTutorialWindow | showTutorialWindow | `` | `void` | `obj:showTutorialWindow()` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TutorialItem` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getId | getId | `` | `integer` | `obj:getId()` |
| isLastSubItem | isLastSubItem | `` | `boolean` | `obj:isLastSubItem()` |
| isSkippable | isSkippable | `` | `boolean` | `obj:isSkippable()` |
| isActive | isActive | `` | `boolean` | `obj:isActive()` |
| hasEnded | hasEnded | `` | `boolean` | `obj:hasEnded()` |
| getCurrentSubItem | getCurrentSubItem | `` | `TutorialSubItem` | `obj:getCurrentSubItem()` |
| getSubItemAt | getSubItemAt | `index: integer` | `TutorialSubItem` | `obj:getSubItemAt(index)` |
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
| currentItem | currentItem | TutorialItem | RW | `obj.currentItem = <value>` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `TutorialpediaGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setup | setup | `` | `void` | `obj:setup()` |
| updateCurrentItem | updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |

## UniqueSpawnData
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| squadTemplate | squadTemplate | GameData | RW | `obj.squadTemplate = <value>` |
| desiredNumberToHave | desiredNumberToHave | integer | RW | `obj.desiredNumberToHave = <value>` |
| respawnTimer | respawnTimer | number | RW | `obj.respawnTimer = <value>` |
| existingSquadsList | existingSquadsList | lektor<hand> | RW | `obj.existingSquadsList = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `num: integer` | `UniqueSpawnData` | `obj:_CONSTRUCTOR(num)` |
| currentNumber | currentNumber | `` | `integer` | `obj:currentNumber()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## UseableStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| shopOwner | shopOwner | unknown | RW | `obj.shopOwner = <value>` |
| callbackOwner | callbackOwner | unknown | RW | `obj.callbackOwner = <value>` |
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

## UtilityT
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| marker | (void* | lightuserdata | R | `obj.marker` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| perlinNoise_2D | perlinNoise_2D | `x: number, y: number, zoom: number, dropPoint: number` | `number` | `obj:perlinNoise_2D(x, y, zoom, dropPoint)` |
| getTerrainHeightFastWithNormal | getTerrainHeightFastWithNormal | `x: number, z: number, normal: Vector3` | `number` | `obj:getTerrainHeightFastWithNormal(x, z, normal)` |
| getTerrainSlopeFast | getTerrainSlopeFast | `x: number, z: number` | `number` | `obj:getTerrainSlopeFast(x, z)` |
| profilesClear | profilesClear | `` | `void` | `obj:profilesClear()` |
| profilesPrint | profilesPrint | `` | `void` | `obj:profilesPrint()` |
| profileGet | profileGet | `name: string` | `integer` | `obj:profileGet(name)` |
| flushMarkerQueue | flushMarkerQueue | `` | `void` | `obj:flushMarkerQueue()` |
| removeMarkers | removeMarkers | `` | `void` | `obj:removeMarkers()` |
| folderExists | folderExists | `folder: string` | `boolean` | `obj:folderExists(folder)` |
| fileExistsASCII | fileExistsASCII | `file: string` | `boolean` | `obj:fileExistsASCII(file)` |
| createFile | createFile | `path: string, content: string` | `boolean` | `obj:createFile(path, content)` |
| writeFile | writeFile | `path: string, content: string, append: boolean` | `boolean` | `obj:writeFile(path, content, append)` |
| isFile | isFile | `_path: string` | `boolean` | `obj:isFile(_path)` |
| isDirectory | isDirectory | `_path: string` | `boolean` | `obj:isDirectory(_path)` |
| deleteFilesInFolder | deleteFilesInFolder | `dir: string, filter: string, recursive: boolean` | `void` | `obj:deleteFilesInFolder(dir, filter, recursive)` |
| deleteFolder | deleteFolder | `dir: string` | `void` | `obj:deleteFolder(dir)` |
| deleteFile | deleteFile | `dir: string` | `void` | `obj:deleteFile(dir)` |
| moveFile | moveFile | `from: string, to: string` | `boolean` | `obj:moveFile(from, to)` |
| copyFile | copyFile | `from: string, to: string` | `boolean` | `obj:copyFile(from, to)` |
| copyFilesInFolder | copyFilesInFolder | `from: string, to: string, filter: string` | `boolean` | `obj:copyFilesInFolder(from, to, filter)` |

## VisibleObjectInfo
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| handle | handle | unknown | RW | `obj.handle = <value>` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `_level: integer` | `Weapon` | `obj:_CONSTRUCTOR(_level)` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## WeatherRegion
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| biomeGroup | (void* | lightuserdata | RW | `obj.biomeGroup = <value>` |
| weatherStrengthMultiplierMin | weatherStrengthMultiplierMin | number | RW | `obj.weatherStrengthMultiplierMin = <value>` |
| weatherStrengthMultiplierMax | weatherStrengthMultiplierMax | number | RW | `obj.weatherStrengthMultiplierMax = <value>` |
| weatherInstance | (void* | lightuserdata | R | `obj.weatherInstance` |
| currentSeason | (void* | lightuserdata | RW | `obj.currentSeason = <value>` |
| currentSeasonIndex | currentSeasonIndex | integer | RW | `obj.currentSeasonIndex = <value>` |
| currentSeasonEndDay | currentSeasonEndDay | integer | RW | `obj.currentSeasonEndDay = <value>` |
| biomeGroupLoaded | biomeGroupLoaded | boolean | RW | `obj.biomeGroupLoaded = <value>` |
| requestUpdateEffects | requestUpdateEffects | boolean | RW | `obj.requestUpdateEffects = <value>` |
| activeCameraBiome | activeCameraBiome | boolean | RW | `obj.activeCameraBiome = <value>` |
| weatherUpdated | weatherUpdated | boolean | RW | `obj.weatherUpdated = <value>` |
| instanceUpdated | instanceUpdated | boolean | RW | `obj.instanceUpdated = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| reset | reset | `` | `void` | `obj:reset()` |
| getWeatherInstance | getWeatherInstance | `` | `lightuserdata` | `obj:getWeatherInstance()` |
| setCurrentSeason | setCurrentSeason | `seasonIndex: integer, seasonEnd: integer` | `void` | `obj:setCurrentSeason(seasonIndex, seasonEnd)` |
| getNewWeatherStrength | getNewWeatherStrength | `` | `number` | `obj:getNewWeatherStrength()` |
| update | update | `` | `void` | `obj:update()` |
| updateBT | updateBT | `` | `void` | `obj:updateBT()` |
| addListener | addListener | `listener: userdata` | `void` | `obj:addListener(listener)` |
| removeListener | removeListener | `listener: userdata` | `void` | `obj:removeListener(listener)` |
| addGlobalEffect | addGlobalEffect | `type: integer` | `void` | `obj:addGlobalEffect(type)` |
| getNewSeason | getNewSeason | `` | `void` | `obj:getNewSeason()` |
| weatherChanged | weatherChanged | `newWeather: boolean` | `void` | `obj:weatherChanged(newWeather)` |
| updateWeatherEffects | updateWeatherEffects | `` | `void` | `obj:updateWeatherEffects()` |
| save | save | `key: string` | `void` | `obj:save(key)` |
| load | load | `key: string` | `void` | `obj:load(key)` |

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
| playerInvolvement | playerInvolvement | boolean | RW | `obj.playerInvolvement = <value>` |
| isAllyOf | isAllyOf | ogre_unordered_map<Faction*, bool>::type | R | `obj.isAllyOf` |
| isEnemyOf | isEnemyOf | ogre_unordered_map<Faction*, bool>::type | R | `obj.isEnemyOf` |
| towns | towns | ogre_unordered_map<GameData*, WorldStateEnum>::type | R | `obj.towns` |
| uniqueNPCsAre | uniqueNPCsAre | ogre_unordered_map<GameData*, WorldStateEnum>::type | R | `obj.uniqueNPCsAre` |
| uniqueNPCsAreNot | uniqueNPCsAreNot | ogre_unordered_map<GameData*, WorldStateEnum>::type | R | `obj.uniqueNPCsAreNot` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `WorldEventStateQuery` | `obj:_CONSTRUCTOR()` |
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
| setupFrom | setupFrom | `listname: string` | `boolean` | `obj:setupFrom(listname)` |
| reset | reset | `` | `void` | `obj:reset()` |
| isTrue | isTrue | `` | `boolean` | `obj:isTrue()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `WorldEventStateQueryList` | `obj:_CONSTRUCTOR()` |
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
| characterGrid | characterGrid | ZoneSpacialGrid | R | `obj.characterGrid` |
| buildingGrid | buildingGrid | ZoneSpacialGrid | R | `obj.buildingGrid` |
| itemGrid | itemGrid | ZoneSpacialGrid | R | `obj.itemGrid` |
| _needCalculateIslands | _needCalculateIslands | boolean | RW | `obj._needCalculateIslands = <value>` |
| spawnUpdateTimerMT | spawnUpdateTimerMT | number | RW | `obj.spawnUpdateTimerMT = <value>` |
| spawnUpdateTimerTT | spawnUpdateTimerTT | number | RW | `obj.spawnUpdateTimerTT = <value>` |
| distantTownCentre | distantTownCentre | iVector2 | RW | `obj.distantTownCentre = <value>` |
| centralZone | centralZone | ZoneMap | RW | `obj.centralZone = <value>` |
| loadingPhase | loadingPhase | integer | RW | `obj.loadingPhase = <value>` |
| biomeMap | (void* | lightuserdata | R | `obj.biomeMap` |
| groundEffectsPool | groundEffectsPool | ParticlePool | RW | `obj.groundEffectsPool = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ZoneManager` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isZoneLoadedT | isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneLoadedT(pos)` |
| _NV_isZoneLoadedT | _NV_isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:_NV_isZoneLoadedT(pos)` |
| isZoneBeingLoadedT | isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(pos)` |
| _NV_isZoneBeingLoadedT | _NV_isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:_NV_isZoneBeingLoadedT(pos)` |
| getNumActiveZones | getNumActiveZones | `` | `integer` | `obj:getNumActiveZones()` |
| findShop | findShop | `selling: integer` | `Building` | `obj:findShop(selling)` |
| findAnyShop | findAnyShop | `` | `Building` | `obj:findAnyShop()` |
| setup | setup | `` | `void` | `obj:setup()` |
| updateMainThread | updateMainThread | `camerapos: Vector3` | `void` | `obj:updateMainThread(camerapos)` |
| updateRendertimeThread | updateRendertimeThread | `camerapos: Vector3` | `void` | `obj:updateRendertimeThread(camerapos)` |
| updateGPUSafeThread | updateGPUSafeThread | `camerapos: Vector3` | `void` | `obj:updateGPUSafeThread(camerapos)` |
| spawnChecksUpdateThreaded | spawnChecksUpdateThreaded | `island: integer` | `void` | `obj:spawnChecksUpdateThreaded(island)` |
| levelEditorDeleteAllSelectedObjects | levelEditorDeleteAllSelectedObjects | `` | `void` | `obj:levelEditorDeleteAllSelectedObjects()` |
| getCurrentMapSector | getCurrentMapSector | `` | `iVector2` | `obj:getCurrentMapSector()` |
| getCurrentZoneMap | getCurrentZoneMap | `` | `ZoneMap` | `obj:getCurrentZoneMap()` |
| getSubMapSector | getSubMapSector | `X: number, Z: number` | `iVector2` | `obj:getSubMapSector(X, Z)` |
| getZoneMapFromResolutionCoord | getZoneMapFromResolutionCoord | `X: number, Z: number` | `iVector2` | `obj:getZoneMapFromResolutionCoord(X, Z)` |
| playerActivate | playerActivate | `pos: Vector3` | `boolean` | `obj:playerActivate(pos)` |
| deactivateZoneMap | deactivateZoneMap | `saveZoneState: boolean` | `void` | `obj:deactivateZoneMap(saveZoneState)` |
| getBiome | getBiome | `position: Vector3` | `GameData` | `obj:getBiome(position)` |
| getBiomeCode | getBiomeCode | `position: Vector3` | `integer` | `obj:getBiomeCode(position)` |
| getBiomeMap | getBiomeMap | `` | `lightuserdata` | `obj:getBiomeMap()` |
| getGroundTypeIndex | getGroundTypeIndex | `pos: Vector3` | `integer` | `obj:getGroundTypeIndex(pos)` |
| getGroundType | getGroundType | `pos: Vector3` | `integer` | `obj:getGroundType(pos)` |
| addGroundEffect | addGroundEffect | `position: Vector3` | `void` | `obj:addGroundEffect(position)` |
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
| checkForRepopulateTown | checkForRepopulateTown | `` | `boolean` | `obj:checkForRepopulateTown()` |
| getCentralZone | getCentralZone | `` | `ZoneMap` | `obj:getCentralZone()` |
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
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ZoneManagerInterfaceT` | `obj:_CONSTRUCTOR()` |

## ZoneMap
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| mapContent | (void* | lightuserdata | R | `obj.mapContent` |
| mapFeatures | (void* | lightuserdata | R | `obj.mapFeatures` |
| zoneSmell | (void* | lightuserdata | R | `obj.zoneSmell` |
| coordinates | coordinates | iVector2 | RW | `obj.coordinates = <value>` |
| island | island | integer | RW | `obj.island = <value>` |
| hasFile | hasFile | boolean | RW | `obj.hasFile = <value>` |
| terrainCollision | (void* | lightuserdata | R | `obj.terrainCollision` |
| activatedCountdown | activatedCountdown | unknown | RW | `obj.activatedCountdown = <value>` |
| _generateNavMeshesFlag | _generateNavMeshesFlag | boolean | RW | `obj._generateNavMeshesFlag = <value>` |
| center | center | Vector3 | RW | `obj.center = <value>` |
| loadCount | loadCount | integer | RW | `obj.loadCount = <value>` |
| neighbors | neighbors | unknown | RW | `obj.neighbors = <value>` |
| neighborsDiagonal | neighborsDiagonal | unknown | RW | `obj.neighborsDiagonal = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ZoneMap` | `obj:_CONSTRUCTOR()` |
| isInIsland | isInIsland | `` | `boolean` | `obj:isInIsland()` |
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
| isANeighbour | isANeighbour | `` | `boolean` | `obj:isANeighbour()` |
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
| mutex | mutex | unknown | RW | `obj.mutex = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `ZoneSpacialGrid` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| add | add | `` | `integer` | `obj:add()` |
| remove | remove | `` | `boolean` | `obj:remove()` |
| update | update | `` | `integer` | `obj:update()` |
| addZone | addZone | `` | `void` | `obj:addZone()` |
| removeZone | removeZone | `` | `void` | `obj:removeZone()` |
| getZoneKey | getZoneKey | `p: Vector3` | `integer` | `obj:getZoneKey(p)` |
| getCellKey | getCellKey | `p: Vector3` | `integer` | `obj:getCellKey(p)` |
| getFullKey | getFullKey | `p: Vector3` | `integer` | `obj:getFullKey(p)` |
| initialiseGrid | initialiseGrid | `size: number` | `void` | `obj:initialiseGrid(size)` |

## hkArray
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAndDeallocate | clearAndDeallocate | `` | `void` | `obj:clearAndDeallocate()` |

## hkArrayBase
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| m_data | (void* | lightuserdata | R | `obj.m_data` |
| m_size | m_size | integer | RW | `obj.m_size = <value>` |
| m_capacityAndFlags | m_capacityAndFlags | integer | RW | `obj.m_capacityAndFlags = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getSize | getSize | `` | `integer` | `obj:getSize()` |
| getCapacity | getCapacity | `` | `integer` | `obj:getCapacity()` |
| clear | clear | `` | `void` | `obj:clear()` |

## hkBool
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| m_bool | m_bool | integer | RW | `obj.m_bool = <value>` |

## hkMemoryAllocator
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| blockAlloc | blockAlloc | `_a1: integer` | `void` | `obj:blockAlloc(_a1)` |
| resetPeakMemoryStatistics | resetPeakMemoryStatistics | `` | `void` | `obj:resetPeakMemoryStatistics()` |
| _NV_resetPeakMemoryStatistics | _NV_resetPeakMemoryStatistics | `` | `void` | `obj:_NV_resetPeakMemoryStatistics()` |
| getExtendedInterface | getExtendedInterface | `` | `lightuserdata` | `obj:getExtendedInterface()` |
| _NV_getExtendedInterface | _NV_getExtendedInterface | `` | `lightuserdata` | `obj:_NV_getExtendedInterface()` |
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## hkVector4f
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| setZero | setZero | `` | `void` | `obj:setZero()` |
| zeroComponent | zeroComponent | `i: integer` | `void` | `obj:zeroComponent(i)` |
| setInt24W | setInt24W | `value: integer` | `void` | `obj:setInt24W(value)` |
| getInt24W | getInt24W | `` | `integer` | `obj:getInt24W()` |
| getInt16W | getInt16W | `` | `integer` | `obj:getInt16W()` |
| setZero4 | setZero4 | `` | `void` | `obj:setZero4()` |
| normalize3 | normalize3 | `` | `void` | `obj:normalize3()` |

## hkVector4fComparison
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| getIndexOfLastComponentSet | getIndexOfLastComponentSet | `` | `integer` | `obj:getIndexOfLastComponentSet()` |
| getIndexOfFirstComponentSet | getIndexOfFirstComponentSet | `` | `integer` | `obj:getIndexOfFirstComponentSet()` |
| set | set | `m: integer` | `void` | `obj:set(m)` |
| allAreSet | allAreSet | `` | `integer` | `obj:allAreSet()` |

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
| shape | (void* | lightuserdata | R | `obj.shape` |
| hitObject | hitObject | unknown | RW | `obj.hitObject = <value>` |
| _group | _group | integer | RW | `obj._group = <value>` |
| _hitObjectUnsafePtr | _hitObjectUnsafePtr | RootObject | RW | `obj._hitObjectUnsafePtr = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| traceWasAborted | traceWasAborted | `` | `boolean` | `obj:traceWasAborted()` |
| reset | reset | `` | `void` | `obj:reset()` |
| hitObjectUnsafePtr | hitObjectUnsafePtr | `` | `RootObject` | `obj:hitObjectUnsafePtr()` |
| getBuilding | getBuilding | `` | `Building` | `obj:getBuilding()` |
| group | group | `` | `integer` | `obj:group()` |

## rendHit
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| data | data | integer | RW | `obj.data = <value>` |
| hit | hit | Vector3 | RW | `obj.hit = <value>` |

### Methods
| Lua Name | C++ Method | Arguments | Return Type | Example |
|---|---|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
