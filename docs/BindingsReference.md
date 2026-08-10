# Lua Bindings Reference

## Table of Contents
- [AABB2D](#aabb2d)
- [AIOptions](#aioptions)
- [AbstractMovementBase](#abstractmovementbase)
- [ActivePlatoon](#activeplatoon)
- [AkSoundPosition](#aksoundposition)
- [AkVector](#akvector)
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
- [Character_CarryMsg](#character_carrymsg)
- [Character_RagdollMsg](#character_ragdollmsg)
- [CombatClass](#combatclass)
- [CombatClass_AttackSlotManager_SlotData](#combatclass_attackslotmanager_slotdata)
- [CombatClass_EffectData](#combatclass_effectdata)
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
- [EdgeCache](#edgecache)
- [EdgeCache_Edge](#edgecache_edge)
- [EdgePathNode](#edgepathnode)
- [EntData](#entdata)
- [Faction](#faction)
- [FactionLeader](#factionleader)
- [FactionListWindow](#factionlistwindow)
- [FactionManager](#factionmanager)
- [FactionRelations](#factionrelations)
- [FactionRelationsLine](#factionrelationsline)
- [FactionUniqueSquadManager](#factionuniquesquadmanager)
- [FactionWarMgr](#factionwarmgr)
- [Faction_CharacteristicsData](#faction_characteristicsdata)
- [FactionsScreen](#factionsscreen)
- [FactionsScreen_FactionRelationsLine_LessSort](#factionsscreen_factionrelationsline_lesssort)
- [FactoryCallbackInterface](#factorycallbackinterface)
- [FarmBatch](#farmbatch)
- [FarmBuilding](#farmbuilding)
- [FarmBuilding_Plant](#farmbuilding_plant)
- [FarmBuilding_PlantSource](#farmbuilding_plantsource)
- [FarmBuilding_SubPlant](#farmbuilding_subplant)
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
- [GameDataEditorWindow_DataItem](#gamedataeditorwindow_dataitem)
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
- [InputHandler_Command](#inputhandler_command)
- [InstanceID](#instanceid)
- [InteriorModeButtonWindow](#interiormodebuttonwindow)
- [Inventory](#inventory)
- [InventoryGUI](#inventorygui)
- [InventoryGUI_FenceCallbackData](#inventorygui_fencecallbackdata)
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
- [ManagementScreen_TechItemViewData](#managementscreen_techitemviewdata)
- [MapMarkerCharacter](#mapmarkercharacter)
- [MapMarkerTown](#mapmarkertown)
- [MapScreen](#mapscreen)
- [MapScreen_MapRoad](#mapscreen_maproad)
- [MedianFilter](#medianfilter)
- [MedianFilter2DVector](#medianfilter2dvector)
- [MedicalSystem](#medicalsystem)
- [MeshDataLookup](#meshdatalookup)
- [MeshLoadData](#meshloaddata)
- [MessageBoxManager](#messageboxmanager)
- [MessageChain](#messagechain)
- [MessageQueue](#messagequeue)
- [MessageQueue_Node](#messagequeue_node)
- [ModInfo](#modinfo)
- [MotionFilter](#motionfilter)
- [MultiSlider](#multislider)
- [MustEndWithSemiColon](#mustendwithsemicolon)
- [MyGUI](MyGUI_Bindings.md)
- [NavInstance](#navinstance)
- [NavMesh](#navmesh)
- [NavMeshGenerator](#navmeshgenerator)
- [NavMeshGenerator_Task](#navmeshgenerator_task)
- [NavMeshGenerator_TaskQueue](#navmeshgenerator_taskqueue)
- [NavMeshSeeds](#navmeshseeds)
- [NavMesh_BuildingInfo](#navmesh_buildinginfo)
- [NavMesh_NavMeshMessage](#navmesh_navmeshmessage)
- [NewGameOptionsWindow](#newgameoptionswindow)
- [NewGameWindow](#newgamewindow)
- [NpcListWindow](#npclistwindow)
- [Nx9Real](#nx9real)
- [Nx9Real_S](#nx9real_s)
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
- [ParticlePool_ParticleData](#particlepool_particledata)
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
- [SaveFileSystem_FileMessage](#savefilesystem_filemessage)
- [SaveInfo](#saveinfo)
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
- [Terrain_BloodQueue](#terrain_bloodqueue)
- [Terrain_Box](#terrain_box)
- [Terrain_Hit](#terrain_hit)
- [Terrain_Info](#terrain_info)
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
- [TownBase_ResidentData](#townbase_residentdata)
- [TownBuildingsManager](#townbuildingsmanager)
- [TownBuildingsManager_BuildingInfo](#townbuildingsmanager_buildinginfo)
- [TownListWindow](#townlistwindow)
- [TownPositionCacher](#townpositioncacher)
- [Town_NestSpot](#town_nestspot)
- [TradeCulture](#tradeculture)
- [TradeResult](#traderesult)
- [TraderInventoryLayout](#traderinventorylayout)
- [TraitBool](#traitbool)
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
- [ZoneManager_BiomeGroundEffects](#zonemanager_biomegroundeffects)
- [ZoneMap](#zonemap)
- [ZoneSpacialGrid](#zonespacialgrid)
- [ZoneSpacialGrid_ZoneCell](#zonespacialgrid_zonecell)
- [hkArray](#hkarray)
- [hkArrayBase](#hkarraybase)
- [hkBool](#hkbool)
- [hkContainerHeapAllocator](#hkcontainerheapallocator)
- [hkContainerHeapAllocator_Allocator](#hkcontainerheapallocator_allocator)
- [hkMemoryAllocator](#hkmemoryallocator)
- [hkMemoryAllocator_ExtendedInterface](#hkmemoryallocator_extendedinterface)
- [hkMemoryAllocator_MemoryStatistics](#hkmemoryallocator_memorystatistics)
- [hkResult](#hkresult)
- [hkVector4f](#hkvector4f)
- [hkVector4fComparison](#hkvector4fcomparison)
- [iVector2](#ivector2)
- [physHit](#physhit)
- [rendHit](#rendhit)

## AABB2D
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | number | RW | `obj.x = <value>` |
| y | number | RW | `obj.y = <value>` |
| x2 | number | RW | `obj.x2 = <value>` |
| y2 | number | RW | `obj.y2 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `a: Quaternion` | `AABB2D` | `obj:_CONSTRUCTOR(a)` |
| setNull | `` | `void` | `obj:setNull()` |
| pointWithin | `v: Vector3` | `boolean` | `obj:pointWithin(v)` |
| inflate | `amount: number` | `void` | `obj:inflate(amount)` |
| sizeX | `` | `number` | `obj:sizeX()` |
| sizeY | `` | `number` | `obj:sizeY()` |
| intersects | `v1: Vector3, radius: number` | `boolean` | `obj:intersects(v1, radius)` |
| intersects2 | `` | `void` | `obj:intersects2()` |

## AIOptions
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| healAllies | boolean | RW | `obj.healAllies = <value>` |
| helpAllies | boolean | RW | `obj.helpAllies = <value>` |
| rescueAllies | boolean | RW | `obj.rescueAllies = <value>` |
| stayInBase | boolean | RW | `obj.stayInBase = <value>` |
| feedAnimals | boolean | RW | `obj.feedAnimals = <value>` |
| shareFood | boolean | RW | `obj.shareFood = <value>` |
| autoSleep | boolean | RW | `obj.autoSleep = <value>` |
| autoDitchItems | boolean | RW | `obj.autoDitchItems = <value>` |
| autoSit | boolean | RW | `obj.autoSit = <value>` |
| ejectEnemies | boolean | RW | `obj.ejectEnemies = <value>` |
| shootFirst | boolean | RW | `obj.shootFirst = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `AIOptions` | `obj:_CONSTRUCTOR()` |
| load | `` | `void` | `obj:load()` |
| save | `` | `void` | `obj:save()` |

## AbstractMovementBase
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| officiallyStopped | boolean | RW | `obj.officiallyStopped = <value>` |
| speedOrders | integer | RW | `obj.speedOrders = <value>` |
| currentlyMoving | boolean | RW | `obj.currentlyMoving = <value>` |
| positionSmoother | MedianFilter2DVector | RW | `obj.positionSmoother = <value>` |
| currentMotion | Vector3 | RW | `obj.currentMotion = <value>` |
| maxSpeed | number | RW | `obj.maxSpeed = <value>` |
| currentSpeed | number | RW | `obj.currentSpeed = <value>` |
| desiredSpeed | number | RW | `obj.desiredSpeed = <value>` |
| walkSpeed | number | RW | `obj.walkSpeed = <value>` |
| pos | Vector3 | RW | `obj.pos = <value>` |
| direction | Vector3 | RW | `obj.direction = <value>` |
| destination | Vector3 | RW | `obj.destination = <value>` |
| pathDestination | Vector3 | RW | `obj.pathDestination = <value>` |
| roadFollower | lightuserdata | R | `obj.roadFollower` |
| roadWeight | number | RW | `obj.roadWeight = <value>` |
| speedGroup | SpeedGroup | RW | `obj.speedGroup = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `AbstractMovementBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| create | `_pos: Vector3` | `void` | `obj:create(_pos)` |
| getHandle | `` | `void` | `obj:getHandle()` |
| _NV_getHandle | `` | `void` | `obj:_NV_getHandle()` |
| _setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _NV__setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_NV__setPositionAndTeleport(p, floor)` |
| _setPositionSimple | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| _NV__setPositionSimple | `p: Vector3` | `void` | `obj:_NV__setPositionSimple(p)` |
| faceDirection | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| _NV_faceDirection | `dir: Vector3` | `void` | `obj:_NV_faceDirection(dir)` |
| lookatPosition | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| _NV_lookatPosition | `pos: Vector3` | `void` | `obj:_NV_lookatPosition(pos)` |
| getDestination | `` | `Vector3` | `obj:getDestination()` |
| isProbablyStuck | `` | `boolean` | `obj:isProbablyStuck()` |
| pathOk | `` | `boolean` | `obj:pathOk()` |
| _NV_pathOk | `` | `boolean` | `obj:_NV_pathOk()` |
| pathFailed | `` | `boolean` | `obj:pathFailed()` |
| _NV_pathFailed | `` | `boolean` | `obj:_NV_pathFailed()` |
| update | `_TIME: number` | `void` | `obj:update(_TIME)` |
| _NV_update | `_TIME: number` | `void` | `obj:_NV_update(_TIME)` |
| isDestinationReached | `` | `boolean` | `obj:isDestinationReached()` |
| _NV_isDestinationReached | `` | `boolean` | `obj:_NV_isDestinationReached()` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| manualMovement | `desiredMotion: Vector3` | `void` | `obj:manualMovement(desiredMotion)` |
| _NV_manualMovement | `desiredMotion: Vector3` | `void` | `obj:_NV_manualMovement(desiredMotion)` |
| halt | `` | `void` | `obj:halt()` |
| _NV_halt | `` | `void` | `obj:_NV_halt()` |
| setRoadDestination | `dest: Vector3` | `boolean` | `obj:setRoadDestination(dest)` |
| setRoadPreference | `w: number` | `void` | `obj:setRoadPreference(w)` |
| extractRoadFollower | `` | `lightuserdata` | `obj:extractRoadFollower()` |
| _NV_setDesiredSpeed | `speed: integer` | `void` | `obj:_NV_setDesiredSpeed(speed)` |
| setStandardWalkSpeed | `s: number` | `void` | `obj:setStandardWalkSpeed(s)` |
| getStandardWalkSpeed | `` | `number` | `obj:getStandardWalkSpeed()` |
| restoreDesiredSpeed | `` | `void` | `obj:restoreDesiredSpeed()` |
| setMaxSpeed | `ms: number` | `void` | `obj:setMaxSpeed(ms)` |
| getMaxSpeed | `` | `number` | `obj:getMaxSpeed()` |
| isCurrentlyMoving | `` | `boolean` | `obj:isCurrentlyMoving()` |
| getCurrentSpeed | `` | `number` | `obj:getCurrentSpeed()` |
| getCurrentMotion | `` | `Vector3` | `obj:getCurrentMotion()` |
| getCurrentSpeedRelativeToMax01 | `` | `number` | `obj:getCurrentSpeedRelativeToMax01()` |
| getSpeedOrders | `` | `integer` | `obj:getSpeedOrders()` |
| leaveSpeedGroup | `` | `void` | `obj:leaveSpeedGroup()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |
| setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:setDestination(dest, notVertical)` |
| _NV_setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:_NV_setDestination(dest, notVertical)` |
| setCurrentRoadFollower | `d: Vector3, r: userdata` | `void` | `obj:setCurrentRoadFollower(d, r)` |
| setPatrolInput | `patrol: userdata` | `void` | `obj:setPatrolInput(patrol)` |
| _NV_setPatrolInput | `patrol: userdata` | `void` | `obj:_NV_setPatrolInput(patrol)` |
| setDesiredSpeed | `i: integer` | `void` | `obj:setDesiredSpeed(i)` |
| setDesiredSpeedOrders | `i: integer` | `void` | `obj:setDesiredSpeedOrders(i)` |

## ActivePlatoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _groupSense | lightuserdata | R | `obj._groupSense` |
| isAnimalsOnly | boolean | RW | `obj.isAnimalsOnly = <value>` |
| me | Platoon | RW | `obj.me = <value>` |
| characterHandles | lightuserdata | R | `obj.characterHandles` |
| p_TIME | number | RW | `obj.p_TIME = <value>` |
| lastActiveZone | ZoneMap | RW | `obj.lastActiveZone = <value>` |
| _myMemory | lightuserdata | R | `obj._myMemory` |
| squadleader | Character | RW | `obj.squadleader = <value>` |
| backupLeader | Character | RW | `obj.backupLeader = <value>` |
| deactivationTimer | number | RW | `obj.deactivationTimer = <value>` |
| workingPos | Vector3 | RW | `obj.workingPos = <value>` |
| currentGoal | Tasker | RW | `obj.currentGoal = <value>` |
| positionMoved | Vector3 | RW | `obj.positionMoved = <value>` |
| teleportTo | Vector3 | RW | `obj.teleportTo = <value>` |
| teleportMessage | boolean | RW | `obj.teleportMessage = <value>` |
| isPlayer | PlayerInterface | RW | `obj.isPlayer = <value>` |
| isPhysical | boolean | RW | `obj.isPhysical = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _recalculateIsIntact | `` | `boolean` | `obj:_recalculateIsIntact()` |
| isAnyoneCaptured | `` | `boolean` | `obj:isAnyoneCaptured()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getGroupSense | `` | `lightuserdata` | `obj:getGroupSense()` |
| getMemory | `` | `lightuserdata` | `obj:getMemory()` |
| removeObject | `` | `boolean` | `obj:removeObject()` |
| _NV_removeObject | `` | `boolean` | `obj:_NV_removeObject()` |
| addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| addCharacterAt | `index: integer` | `void` | `obj:addCharacterAt(index)` |
| swapCharacters | `indexA: integer, indexB: integer` | `void` | `obj:swapCharacters(indexA, indexB)` |
| emptySquadCheck | `` | `void` | `obj:emptySquadCheck()` |
| clearAllTheUniqueNPCStates | `` | `void` | `obj:clearAllTheUniqueNPCStates()` |
| isIntact | `` | `boolean` | `obj:isIntact()` |
| getSquadLeader_theRealOne | `` | `Character` | `obj:getSquadLeader_theRealOne()` |
| getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getSquadSize | `` | `integer` | `obj:getSquadSize()` |
| setSquadLeader | `` | `void` | `obj:setSquadLeader()` |
| update | `` | `boolean` | `obj:update()` |
| _NV_update | `` | `boolean` | `obj:_NV_update()` |
| refreshInventory | `firstTime: boolean` | `void` | `obj:refreshInventory(firstTime)` |
| _forceRefreshInventory | `` | `void` | `obj:_forceRefreshInventory()` |
| periodicUpdate | `` | `boolean` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `boolean` | `obj:_NV_periodicUpdate()` |
| serialiseEverythingToDisk | `levelEditor: boolean` | `void` | `obj:serialiseEverythingToDisk(levelEditor)` |
| isWholeSquadDown | `minusThis: integer` | `boolean` | `obj:isWholeSquadDown(minusThis)` |
| setDataFilename | `f: string` | `void` | `obj:setDataFilename(f)` |
| setupLeaderDialogues | `` | `void` | `obj:setupLeaderDialogues()` |
| isLoaded | `` | `boolean` | `obj:isLoaded()` |
| teleport | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| getIsTrader | `` | `boolean` | `obj:getIsTrader()` |
| getHasVendorList | `` | `boolean` | `obj:getHasVendorList()` |
| getHasSpecialItemsList | `` | `boolean` | `obj:getHasSpecialItemsList()` |
| setupTraderBuildings | `` | `void` | `obj:setupTraderBuildings()` |
| putTheSpecialCharactersInNewSquads_captured | `` | `void` | `obj:putTheSpecialCharactersInNewSquads_captured()` |
| checkForCharactersBeingCarried | `` | `boolean` | `obj:checkForCharactersBeingCarried()` |
| restoreSquad | `` | `void` | `obj:restoreSquad()` |
| _CONSTRUCTOR | `_posOffset: Vector3` | `ActivePlatoon` | `obj:_CONSTRUCTOR(_posOffset)` |
| unloadCheck | `` | `boolean` | `obj:unloadCheck()` |
| setupCheck | `` | `YesNoMaybe` | `obj:setupCheck()` |
| destroyCharacters | `justUnload: boolean` | `void` | `obj:destroyCharacters(justUnload)` |
| serialiseCharacterData | `` | `void` | `obj:serialiseCharacterData()` |
| saveToDisk | `levelEditor: boolean, force: string` | `void` | `obj:saveToDisk(levelEditor, force)` |
| loadCharacters | `_a1: Vector3` | `void` | `obj:loadCharacters(_a1)` |
| _NV_loadCharacters | `_a1: Vector3` | `void` | `obj:_NV_loadCharacters(_a1)` |
| calculateCurrentPos | `` | `Vector3` | `obj:calculateCurrentPos()` |
| _checkForUniqueCharactersOnUnload | `` | `void` | `obj:_checkForUniqueCharactersOnUnload()` |
| getName | `` | `string` | `obj:getName()` |
| loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:loadFromDisk(force, extra)` |
| _NV_loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:_NV_loadFromDisk(force, extra)` |
| getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |
| _NV_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:_NV_loadInstance(skipSaveState, pos, rot, positionMoved)` |

## AkSoundPosition
**Header:** `???`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| Position | unknown | RW | `obj.Position = <value>` |
| Orientation | unknown | RW | `obj.Orientation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `AkSoundPosition` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## AkVector
**Header:** `???`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| X | number | RW | `obj.X = <value>` |
| Y | number | RW | `obj.Y = <value>` |
| Z | number | RW | `obj.Z = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `Y: number, Z: number` | `AkVector` | `obj:_CONSTRUCTOR(Y, Z)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## AnimalInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `AnimalInventoryLayout` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## AppearanceAnimal
**Header:** `extern/KenshiLib/Include/kenshi/appearance.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createBody | `` | `void` | `obj:createBody()` |
| _NV_createBody | `` | `void` | `obj:_NV_createBody()` |
| updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| _NV_updateCharaterTexture | `` | `void` | `obj:_NV_updateCharaterTexture()` |

## AppearanceBase
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| slots | lightuserdata | R | `obj.slots` |
| msgClearHarpoons | boolean | RW | `obj.msgClearHarpoons = <value>` |
| woundsListMutex | lightuserdata | R | `obj.woundsListMutex` |
| body | lightuserdata | RW | `obj.body = <value>` |
| bodyLoader | lightuserdata | R | `obj.bodyLoader` |
| isCreatingBody | boolean | RW | `obj.isCreatingBody = <value>` |
| bodyRadius | number | RW | `obj.bodyRadius = <value>` |
| me | Character | RW | `obj.me = <value>` |
| visible | boolean | RW | `obj.visible = <value>` |
| bodyFilename | string | RW | `obj.bodyFilename = <value>` |
| animation | lightuserdata | R | `obj.animation` |
| female | boolean | RW | `obj.female = <value>` |
| updatedAttachments | boolean | RW | `obj.updatedAttachments = <value>` |
| updatedAppearanceData | boolean | RW | `obj.updatedAppearanceData = <value>` |
| updateBody | boolean | RW | `obj.updateBody = <value>` |
| suid | integer | RW | `obj.suid = <value>` |
| appearanceData | GameDataCopyStandalone | RW | `obj.appearanceData = <value>` |
| raceData | GameData | RW | `obj.raceData = <value>` |
| factionColor | GameData | RW | `obj.factionColor = <value>` |
| hairStyle | GameData | RW | `obj.hairStyle = <value>` |
| shaved | boolean | RW | `obj.shaved = <value>` |
| waterLineFadeTimer | number | RW | `obj.waterLineFadeTimer = <value>` |
| barefoot | boolean | RW | `obj.barefoot = <value>` |
| hideAttachments | boolean | RW | `obj.hideAttachments = <value>` |
| characterHeight | number | RW | `obj.characterHeight = <value>` |
| characterHeightSpeedMultiplier | number | RW | `obj.characterHeightSpeedMultiplier = <value>` |
| characterHeight_0to1 | number | RW | `obj.characterHeight_0to1 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateAnimationTransforms | `` | `void` | `obj:updateAnimationTransforms()` |
| forceUpdateAnimationTransforms | `` | `void` | `obj:forceUpdateAnimationTransforms()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| setAppearanceData | `` | `void` | `obj:setAppearanceData()` |
| getAppearanceData | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| activate | `` | `void` | `obj:activate()` |
| _NV_activate | `` | `void` | `obj:_NV_activate()` |
| deactivate | `` | `void` | `obj:deactivate()` |
| _NV_deactivate | `` | `void` | `obj:_NV_deactivate()` |
| isFemale | `` | `boolean` | `obj:isFemale()` |
| setGender | `_female: boolean` | `void` | `obj:setGender(_female)` |
| _NV_setGender | `_female: boolean` | `void` | `obj:_NV_setGender(_female)` |
| getRace | `` | `GameData` | `obj:getRace()` |
| attachEffect | `boneName: string, offsetPosition: Vector3, offsetOrientation: Quaternion, manual: boolean, baseEmission: number` | `lightuserdata` | `obj:attachEffect(boneName, offsetPosition, offsetOrientation, manual, baseEmission)` |
| getAttachedEntity | `slot: string` | `lightuserdata` | `obj:getAttachedEntity(slot)` |
| detachAllHarpoonsT | `` | `void` | `obj:detachAllHarpoonsT()` |
| _detachAllHarpoons | `` | `void` | `obj:_detachAllHarpoons()` |
| updateWetness | `force: boolean` | `void` | `obj:updateWetness(force)` |
| updateBloodyness | `` | `void` | `obj:updateBloodyness()` |
| getAttachmentPosition | `slot: string, pos: Vector3, rot: Quaternion` | `boolean` | `obj:getAttachmentPosition(slot, pos, rot)` |
| hasSlot | `slot: string` | `boolean` | `obj:hasSlot(slot)` |
| getNormalisedCharacterHeight | `` | `number` | `obj:getNormalisedCharacterHeight()` |
| getCharacterHeight | `` | `number` | `obj:getCharacterHeight()` |
| getAnimationSystem | `` | `lightuserdata` | `obj:getAnimationSystem()` |
| getSceneNode | `` | `lightuserdata` | `obj:getSceneNode()` |
| getSkeleton | `` | `lightuserdata` | `obj:getSkeleton()` |
| getBody | `` | `lightuserdata` | `obj:getBody()` |
| getBodyRadius | `` | `number` | `obj:getBodyRadius()` |
| failedToLoad | `` | `boolean` | `obj:failedToLoad()` |
| getBonePosition | `boneName: string` | `Vector3` | `obj:getBonePosition(boneName)` |
| getBoneOrientation | `boneName: string` | `Quaternion` | `obj:getBoneOrientation(boneName)` |
| getVertexWorldPosition | `boneName: string, vertex: integer` | `Vector3` | `obj:getVertexWorldPosition(boneName, vertex)` |
| getRandomVertex | `boneName: string, direction: integer` | `integer` | `obj:getRandomVertex(boneName, direction)` |
| notifyDirty | `` | `void` | `obj:notifyDirty()` |
| reload | `` | `void` | `obj:reload()` |
| serialise | `` | `void` | `obj:serialise()` |
| updateAppearance | `` | `void` | `obj:updateAppearance()` |
| _NV_updateAppearance | `` | `void` | `obj:_NV_updateAppearance()` |
| updatePortrait | `` | `void` | `obj:updatePortrait()` |
| updateMovementScale | `` | `void` | `obj:updateMovementScale()` |
| switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| hasLights | `` | `boolean` | `obj:hasLights()` |
| attachItem_Hair | `slot: string` | `boolean` | `obj:attachItem_Hair(slot)` |
| shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isShaved | `` | `boolean` | `obj:isShaved()` |
| setFlayed | `on: boolean` | `void` | `obj:setFlayed(on)` |
| _NV_setFlayed | `on: boolean` | `void` | `obj:_NV_setFlayed(on)` |
| isFlayed | `` | `boolean` | `obj:isFlayed()` |
| _NV_isFlayed | `` | `boolean` | `obj:_NV_isFlayed()` |
| isBarefoot | `` | `boolean` | `obj:isBarefoot()` |
| _NV_isBarefoot | `` | `boolean` | `obj:_NV_isBarefoot()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| getAttachmentsLoaded | `` | `boolean` | `obj:getAttachmentsLoaded()` |
| setAttachmentsVisible | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| _NV_setAttachmentsVisible | `visible: boolean` | `void` | `obj:_NV_setAttachmentsVisible(visible)` |
| createBody | `` | `void` | `obj:createBody()` |
| buildAttachments | `` | `void` | `obj:buildAttachments()` |
| setHairTexture | `name: string, channel: integer, alpha: integer, colour: Vector3, beard: boolean` | `void` | `obj:setHairTexture(name, channel, alpha, colour, beard)` |
| createAttachedObject | `` | `lightuserdata` | `obj:createAttachedObject()` |
| updateOverlap | `` | `void` | `obj:updateOverlap()` |
| updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| getCharacterHeightSpeedMultiplier | `` | `number` | `obj:getCharacterHeightSpeedMultiplier()` |

## AppearanceHuman
**Header:** `extern/KenshiLib/Include/kenshi/appearance.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| robotLegScale | number | RW | `obj.robotLegScale = <value>` |
| lastPhysiqueStats | Vector3 | RW | `obj.lastPhysiqueStats = <value>` |
| bulkMult | number | RW | `obj.bulkMult = <value>` |
| muscleMult | number | RW | `obj.muscleMult = <value>` |
| skinnyMult | number | RW | `obj.skinnyMult = <value>` |
| flayed | boolean | RW | `obj.flayed = <value>` |
| beard | GameData | RW | `obj.beard = <value>` |
| hiddenPartsEnabled | boolean | RW | `obj.hiddenPartsEnabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setGender | `female: boolean` | `void` | `obj:setGender(female)` |
| _NV_setGender | `female: boolean` | `void` | `obj:_NV_setGender(female)` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| setAttachmentsVisible | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| _NV_setAttachmentsVisible | `visible: boolean` | `void` | `obj:_NV_setAttachmentsVisible(visible)` |
| setHiddenPartsEnabled | `enabled: boolean` | `void` | `obj:setHiddenPartsEnabled(enabled)` |
| showFace | `show: boolean` | `void` | `obj:showFace(show)` |
| setFlayed | `f: boolean` | `void` | `obj:setFlayed(f)` |
| _NV_setFlayed | `f: boolean` | `void` | `obj:_NV_setFlayed(f)` |
| isFlayed | `` | `boolean` | `obj:isFlayed()` |
| _NV_isFlayed | `` | `boolean` | `obj:_NV_isFlayed()` |
| updateProportions | `` | `void` | `obj:updateProportions()` |
| createBody | `` | `void` | `obj:createBody()` |
| _NV_createBody | `` | `void` | `obj:_NV_createBody()` |
| updateAppearance | `` | `void` | `obj:updateAppearance()` |
| _NV_updateAppearance | `` | `void` | `obj:_NV_updateAppearance()` |
| updateHiddenParts | `` | `void` | `obj:updateHiddenParts()` |
| updatePysiqueFromStats | `` | `void` | `obj:updatePysiqueFromStats()` |
| updatePhysiqueMuscleMults | `` | `void` | `obj:updatePhysiqueMuscleMults()` |
| updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| _NV_updateCharaterTexture | `` | `void` | `obj:_NV_updateCharaterTexture()` |
| setPosture | `posture: number, neck: number, shoulders: number` | `void` | `obj:setPosture(posture, neck, shoulders)` |

## Armour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cutResistance | number | RW | `obj.cutResistance = <value>` |
| bluntResistance | number | RW | `obj.bluntResistance = <value>` |
| pierceResistance | number | RW | `obj.pierceResistance = <value>` |
| minCutResistance | number | RW | `obj.minCutResistance = <value>` |
| cutToStun | number | RW | `obj.cutToStun = <value>` |
| materialType | integer | RW | `obj.materialType = <value>` |
| athleticsMult | number | RW | `obj.athleticsMult = <value>` |
| combatSkillBonusAttk | integer | RW | `obj.combatSkillBonusAttk = <value>` |
| combatSkillBonusDef | integer | RW | `obj.combatSkillBonusDef = <value>` |
| perceptionBonus | integer | RW | `obj.perceptionBonus = <value>` |
| combatSpeedMult | number | RW | `obj.combatSpeedMult = <value>` |
| stealthMult | number | RW | `obj.stealthMult = <value>` |
| assassinMult | number | RW | `obj.assassinMult = <value>` |
| dexterityMult | number | RW | `obj.dexterityMult = <value>` |
| damageMult | number | RW | `obj.damageMult = <value>` |
| dodgeMult | number | RW | `obj.dodgeMult = <value>` |
| unarmedBonus | integer | RW | `obj.unarmedBonus = <value>` |
| fistInjuryMult | number | RW | `obj.fistInjuryMult = <value>` |
| weatherProtectionAmount | number | RW | `obj.weatherProtectionAmount = <value>` |
| rangedSkillMult | number | RW | `obj.rangedSkillMult = <value>` |
| craftTime | number | RW | `obj.craftTime = <value>` |
| armourClassEnum | integer | RW | `obj.armourClassEnum = <value>` |
| bodypartCoverage | unknown | RW | `obj.bodypartCoverage = <value>` |
| stigma | integer | RW | `obj.stigma = <value>` |
| weatherProtections | integer | RW | `obj.weatherProtections = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _NV_getItemWeight | `` | `number` | `obj:_NV_getItemWeight()` |
| getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| didIHitFlesh | `` | `boolean` | `obj:didIHitFlesh()` |
| hasArmourCoverage | `` | `boolean` | `obj:hasArmourCoverage()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getWeatherProtection_simple | `weather: integer` | `number` | `obj:getWeatherProtection_simple(weather)` |
| _CONSTRUCTOR | `_level: integer` | `Armour` | `obj:_CONSTRUCTOR(_level)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getArmourCraftingMaterialConsumptionRate | `` | `number` | `obj:getArmourCraftingMaterialConsumptionRate()` |

## Array2d
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nRows | integer | RW | `obj.nRows = <value>` |
| nCols | integer | RW | `obj.nCols = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| resize | `nrows: integer, ncols: integer, clear: boolean` | `void` | `obj:resize(nrows, ncols, clear)` |
| setToZeros | `` | `void` | `obj:setToZeros()` |

## AttachedArrowManager
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| index | integer | RW | `obj.index = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAll | `` | `void` | `obj:clearAll()` |
| updateStart | `` | `void` | `obj:updateStart()` |
| addArrow | `pos: Vector3, targ: Vector3, color: integer` | `void` | `obj:addArrow(pos, targ, color)` |
| updateEnd | `` | `void` | `obj:updateEnd()` |
| _CONSTRUCTOR | `` | `Character::AttachedArrowManager` | `obj:_CONSTRUCTOR()` |

## AttackSlotManager
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | Character | RW | `obj.me = <value>` |
| combatClass | CombatClass | RW | `obj.combatClass = <value>` |
| attackSlotH | number | RW | `obj.attackSlotH = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `AttackSlotManager` | `obj:_CONSTRUCTOR()` |
| hasFreeAttackSlot | `` | `boolean` | `obj:hasFreeAttackSlot()` |
| freeAllSlotsH | `` | `void` | `obj:freeAllSlotsH()` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| update | `` | `void` | `obj:update()` |
| getNumAttackSlots | `` | `integer` | `obj:getNumAttackSlots()` |
| getMaxPossibleAttackSlots | `` | `integer` | `obj:getMaxPossibleAttackSlots()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BackThreadMessagesToMainT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| swapMutex | unknown | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| flush | `` | `boolean` | `obj:flush()` |
| _NV_flush | `` | `void` | `obj:_NV_flush()` |

## BackpackInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `standAlone: boolean` | `BackpackInventoryLayout` | `obj:_CONSTRUCTOR(standAlone)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BadSize
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`

## BaseLayout
**Header:** `???`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mMainWidget | lightuserdata | R | `obj.mMainWidget` |
| mPrefix | string | RW | `obj.mPrefix = <value>` |
| mLayoutName | string | RW | `obj.mLayoutName = <value>` |

## BoundsViolation
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`

## Bounty
**Header:** `extern/KenshiLib/Include/kenshi/Bounty.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| amount | integer | RW | `obj.amount = <value>` |
| crimes | integer | RW | `obj.crimes = <value>` |
| bountyHasBeenClaimedOnce | boolean | RW | `obj.bountyHasBeenClaimedOnce = <value>` |
| bountyAssignmentStartedTime | TimeOfDay | RW | `obj.bountyAssignmentStartedTime = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Bounty` | `obj:_CONSTRUCTOR()` |
| addCrime | `crime: integer` | `void` | `obj:addCrime(crime)` |
| hasCrime | `crime: integer` | `boolean` | `obj:hasCrime(crime)` |

## BountyManager
**Header:** `extern/KenshiLib/Include/kenshi/BountyManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bounties | unknown | RW | `obj.bounties = <value>` |
| me | Character | RW | `obj.me = <value>` |
| _hasAccessPass | Faction | RW | `obj._hasAccessPass = <value>` |
| accessPassExpirationTime | TimeOfDay | RW | `obj.accessPassExpirationTime = <value>` |
| committingCrime | integer | RW | `obj.committingCrime = <value>` |
| crimeAgainstFaction | Faction | RW | `obj.crimeAgainstFaction = <value>` |
| usingTrainingEquipmentOf | Faction | RW | `obj.usingTrainingEquipmentOf = <value>` |
| crimeAgainst | unknown | RW | `obj.crimeAgainst = <value>` |
| crimeExpiry | number | RW | `obj.crimeExpiry = <value>` |
| prisonSentenceBeganTime | TimeOfDay | RW | `obj.prisonSentenceBeganTime = <value>` |
| prisonSentenceToServe | number | RW | `obj.prisonSentenceToServe = <value>` |
| _hadABountyAssignedForCurrentCrime | boolean | RW | `obj._hadABountyAssignedForCurrentCrime = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _getHighestBountyFaction | `` | `Faction` | `obj:_getHighestBountyFaction()` |
| getBountyRecognitionThreshold | `` | `integer` | `obj:getBountyRecognitionThreshold()` |
| getTotalBounty | `` | `integer` | `obj:getTotalBounty()` |
| update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| getBountyExpiryStringForGUI | `` | `string` | `obj:getBountyExpiryStringForGUI()` |
| notifyPossibleCrimeWitnessed | `time: number` | `void` | `obj:notifyPossibleCrimeWitnessed(time)` |
| isCommittingCrime | `` | `boolean` | `obj:isCommittingCrime()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _getBountyFaction | `` | `Faction` | `obj:_getBountyFaction()` |
| _CONSTRUCTOR | `` | `BountyManager` | `obj:_CONSTRUCTOR()` |
| getPercievedBounty | `` | `integer` | `obj:getPercievedBounty()` |
| getActualBounty | `` | `integer` | `obj:getActualBounty()` |
| notifyPlayerClaimBounty | `` | `void` | `obj:notifyPlayerClaimBounty()` |
| bountyAlreadyBeenClaimedByPlayer | `` | `boolean` | `obj:bountyAlreadyBeenClaimedByPlayer()` |
| assignBountyForCrimes | `` | `void` | `obj:assignBountyForCrimes()` |
| unfairAddToBounty | `amount: integer` | `void` | `obj:unfairAddToBounty(amount)` |
| clearBounty | `` | `void` | `obj:clearBounty()` |
| load | `` | `void` | `obj:load()` |
| save | `` | `void` | `obj:save()` |
| setCrime | `crime: integer` | `boolean` | `obj:setCrime(crime)` |
| notifyCrimeWitnessed | `expirytime: integer, what: integer` | `void` | `obj:notifyCrimeWitnessed(expirytime, what)` |
| notifyStartPrisonSentence | `` | `void` | `obj:notifyStartPrisonSentence()` |
| hasAccessPass | `` | `boolean` | `obj:hasAccessPass()` |
| giveAccessPass | `minutes: number` | `void` | `obj:giveAccessPass(minutes)` |
| crimeToStr | `` | `string` | `obj:crimeToStr()` |
| getBountyForCrime | `` | `integer` | `obj:getBountyForCrime()` |
| getPrisonSentenceInHours | `` | `integer` | `obj:getPrisonSentenceInHours()` |
| getBountyExpirationTime | `` | `number` | `obj:getBountyExpirationTime()` |

## Box
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| modal | boolean | RW | `obj.modal = <value>` |
| callback | lightuserdata | R | `obj.callback` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `MessageBoxManager::Box` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| input1NameText | lightuserdata | R | `obj.input1NameText` |
| input2NameText | lightuserdata | R | `obj.input2NameText` |
| input1StatusText | lightuserdata | R | `obj.input1StatusText` |
| input2StatusText | lightuserdata | R | `obj.input2StatusText` |
| input1ItemIcon | lightuserdata | R | `obj.input1ItemIcon` |
| input2ItemIcon | lightuserdata | R | `obj.input2ItemIcon` |
| outputNameText | lightuserdata | R | `obj.outputNameText` |
| outputItemIcon | lightuserdata | R | `obj.outputItemIcon` |
| input1Panel | lightuserdata | R | `obj.input1Panel` |
| input2Panel | lightuserdata | R | `obj.input2Panel` |
| input1Progress | lightuserdata | R | `obj.input1Progress` |
| input2Progress | lightuserdata | R | `obj.input2Progress` |
| outputProgress | lightuserdata | R | `obj.outputProgress` |
| inputs | integer | RW | `obj.inputs = <value>` |
| outputs | integer | RW | `obj.outputs = <value>` |
| input1Item | Item | R | `obj.input1Item` |
| input2Item | Item | R | `obj.input2Item` |
| outputItem | Item | R | `obj.outputItem` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `title: string, ins: integer, outs: integer, hasQueue: boolean` | `BuildInventoryLayout` | `obj:_CONSTRUCTOR(title, ins, outs, hasQueue)` |
| setInput | `inputIndex: integer, name: string, status: string` | `void` | `obj:setInput(inputIndex, name, status)` |
| setOutput | `name: string` | `void` | `obj:setOutput(name)` |
| setInputProgress | `inputIdx: integer, progress: number` | `void` | `obj:setInputProgress(inputIdx, progress)` |
| setInputEnabled | `inputIdx: integer, value: boolean` | `void` | `obj:setInputEnabled(inputIdx, value)` |
| setOutputProgress | `progress: number` | `void` | `obj:setOutputProgress(progress)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildMaterial
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mat | GameData | RW | `obj.mat = <value>` |
| buildMatsTotal | number | RW | `obj.buildMatsTotal = <value>` |
| amountOfMaterials | number | RW | `obj.amountOfMaterials = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getMaterialsBarProgress | `` | `number` | `obj:getMaterialsBarProgress()` |
| getNumRemaining | `` | `number` | `obj:getNumRemaining()` |

## BuildModeWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| playerBuildMode | lightuserdata | R | `obj.playerBuildMode` |
| levelEditorMode | boolean | RW | `obj.levelEditorMode = <value>` |
| playerResearch | lightuserdata | R | `obj.playerResearch` |
| currentBuildingCategory | lightuserdata | R | `obj.currentBuildingCategory` |
| currentBuildingGroup | BuildModeWindow::BuildingGroup | RW | `obj.currentBuildingGroup = <value>` |
| currentBuildingInfo | GameData | RW | `obj.currentBuildingInfo = <value>` |
| currentBuildingIndex | integer | RW | `obj.currentBuildingIndex = <value>` |
| switchBuildingIndex | integer | RW | `obj.switchBuildingIndex = <value>` |
| statsDataPanel | DatapanelGUI | RW | `obj.statsDataPanel = <value>` |
| confirmButton | lightuserdata | R | `obj.confirmButton` |
| undoButton | lightuserdata | R | `obj.undoButton` |
| closeButton | lightuserdata | R | `obj.closeButton` |
| categoriesList | lightuserdata | R | `obj.categoriesList` |
| buildingsList | lightuserdata | R | `obj.buildingsList` |
| buildingTxt | lightuserdata | R | `obj.buildingTxt` |
| buildingTypePrevButton | lightuserdata | R | `obj.buildingTypePrevButton` |
| buildingTypeNextButton | lightuserdata | R | `obj.buildingTypeNextButton` |
| buildingImageBox | lightuserdata | R | `obj.buildingImageBox` |
| statsPanel | lightuserdata | R | `obj.statsPanel` |
| descriptionTxt | lightuserdata | R | `obj.descriptionTxt` |
| messageTextBox | lightuserdata | R | `obj.messageTextBox` |
| floorDownButton | lightuserdata | R | `obj.floorDownButton` |
| floorUpButton | lightuserdata | R | `obj.floorUpButton` |
| floorText | lightuserdata | R | `obj.floorText` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setMessage | `message: string` | `void` | `obj:setMessage(message)` |
| getBuildingListWidget | `` | `lightuserdata` | `obj:getBuildingListWidget()` |
| setVisible | `v: boolean` | `void` | `obj:setVisible(v)` |
| setupData | `` | `void` | `obj:setupData()` |
| listCategories | `` | `void` | `obj:listCategories()` |
| listBuildingGroups | `` | `void` | `obj:listBuildingGroups()` |
| updateBuildingUI | `` | `void` | `obj:updateBuildingUI()` |
| build | `` | `void` | `obj:build()` |
| showBuildingStats | `` | `void` | `obj:showBuildingStats()` |
| update | `` | `void` | `obj:update()` |
| changeCurrentIndex | `index: integer` | `void` | `obj:changeCurrentIndex(index)` |

## Building
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isFoliage | boolean | RW | `obj.isFoliage = <value>` |
| hasTerrainInside | boolean | RW | `obj.hasTerrainInside = <value>` |
| isCavernous | boolean | RW | `obj.isCavernous = <value>` |
| enforceCeiling | boolean | RW | `obj.enforceCeiling = <value>` |
| designation | integer | RW | `obj.designation = <value>` |
| publicDaytime | boolean | RW | `obj.publicDaytime = <value>` |
| residentSquad | unknown | RW | `obj.residentSquad = <value>` |
| residentSquadTemplate | GameData | RW | `obj.residentSquadTemplate = <value>` |
| isAnInteriorObject | boolean | RW | `obj.isAnInteriorObject = <value>` |
| instanceID | InstanceID | RW | `obj.instanceID = <value>` |
| layoutInstanceID | string | RW | `obj.layoutInstanceID = <value>` |
| specialFunction | integer | RW | `obj.specialFunction = <value>` |
| _buildState | Building::ConstructionState | RW | `obj._buildState = <value>` |
| classType | integer | RW | `obj.classType = <value>` |
| updateNavmesh | boolean | RW | `obj.updateNavmesh = <value>` |
| visible | boolean | RW | `obj.visible = <value>` |
| interiorVisibility | boolean | RW | `obj.interiorVisibility = <value>` |
| justBeenUpgradedFlag | boolean | RW | `obj.justBeenUpgradedFlag = <value>` |
| imADoor | boolean | RW | `obj.imADoor = <value>` |
| destroyed | boolean | RW | `obj.destroyed = <value>` |
| productionMult | number | RW | `obj.productionMult = <value>` |
| productionMult_baseData | number | RW | `obj.productionMult_baseData = <value>` |
| hasMovingParts | boolean | RW | `obj.hasMovingParts = <value>` |
| saveVersion | integer | RW | `obj.saveVersion = <value>` |
| _town | unknown | RW | `obj._town = <value>` |
| myInterior | lightuserdata | R | `obj.myInterior` |
| buildingsManager | TownBuildingsManager | RW | `obj.buildingsManager = <value>` |
| rootNode | lightuserdata | R | `obj.rootNode` |
| soundEmitter | lightuserdata | R | `obj.soundEmitter` |
| hasAudio | boolean | RW | `obj.hasAudio = <value>` |
| interiorGround | integer | RW | `obj.interiorGround = <value>` |
| exteriorGround | integer | RW | `obj.exteriorGround = <value>` |
| physical | lightuserdata | R | `obj.physical` |
| entitiesToLoad | integer | RW | `obj.entitiesToLoad = <value>` |
| entitiesLoaded | boolean | RW | `obj.entitiesLoaded = <value>` |
| isFurnitureOf | lightuserdata | R | `obj.isFurnitureOf` |
| isOutsideFurniture | boolean | RW | `obj.isOutsideFurniture = <value>` |
| isNestItem | boolean | RW | `obj.isNestItem = <value>` |
| baseMaterial | GameData | RW | `obj.baseMaterial = <value>` |
| effectsVisible | boolean | RW | `obj.effectsVisible = <value>` |
| effectsActive | boolean | RW | `obj.effectsActive = <value>` |
| lightsVisible | boolean | RW | `obj.lightsVisible = <value>` |
| positionMarker | Vector3 | RW | `obj.positionMarker = <value>` |
| heightAboveGround | number | RW | `obj.heightAboveGround = <value>` |
| isRedDebugTextureMode | boolean | RW | `obj.isRedDebugTextureMode = <value>` |
| materialName | string | RW | `obj.materialName = <value>` |
| triggerVolume | lightuserdata | R | `obj.triggerVolume` |
| doors | lektor<Building*> | RW | `obj.doors = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getScale | `` | `number` | `obj:getScale()` |
| getBuildState | `` | `Building::ConstructionState` | `obj:getBuildState()` |
| _NV_getBuildState | `` | `Building::ConstructionState` | `obj:_NV_getBuildState()` |
| getBuildState_ActualNonShared | `` | `Building::ConstructionState` | `obj:getBuildState_ActualNonShared()` |
| select | `` | `void` | `obj:select()` |
| _NV_select | `` | `void` | `obj:_NV_select()` |
| getBuildingDesignation | `` | `integer` | `obj:getBuildingDesignation()` |
| addConstructionProgress | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| _NV_addConstructionProgress | `amount: number` | `void` | `obj:_NV_addConstructionProgress(amount)` |
| setConstructionProgress | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| _NV_setConstructionProgress | `amount: number` | `void` | `obj:_NV_setConstructionProgress(amount)` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| addDismantleProgress | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| _NV_addDismantleProgress | `amount: number` | `boolean` | `obj:_NV_addDismantleProgress(amount)` |
| notifyConstructionDismantling | `` | `void` | `obj:notifyConstructionDismantling()` |
| _NV_notifyConstructionDismantling | `` | `void` | `obj:_NV_notifyConstructionDismantling()` |
| dropMats | `` | `void` | `obj:dropMats()` |
| upgrade | `` | `void` | `obj:upgrade()` |
| _NV_upgrade | `` | `void` | `obj:_NV_upgrade()` |
| downgrade | `` | `void` | `obj:downgrade()` |
| _NV_downgrade | `` | `void` | `obj:_NV_downgrade()` |
| canUpgrade | `` | `GameData` | `obj:canUpgrade()` |
| _NV_canUpgrade | `` | `GameData` | `obj:_NV_canUpgrade()` |
| canDowngrade | `` | `GameData` | `obj:canDowngrade()` |
| _NV_canDowngrade | `` | `GameData` | `obj:_NV_canDowngrade()` |
| canDismantle | `` | `boolean` | `obj:canDismantle()` |
| _NV_canDismantle | `` | `boolean` | `obj:_NV_canDismantle()` |
| buyMeAsk | `` | `void` | `obj:buyMeAsk()` |
| _NV_buyMeAsk | `` | `void` | `obj:_NV_buyMeAsk()` |
| buyMeCallback | `result: integer` | `void` | `obj:buyMeCallback(result)` |
| _NV_buyMeCallback | `result: integer` | `void` | `obj:_NV_buyMeCallback(result)` |
| calculateSaleValue | `` | `integer` | `obj:calculateSaleValue()` |
| loadNodes | `` | `void` | `obj:loadNodes()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| togglePublic | `` | `void` | `obj:togglePublic()` |
| _NV_togglePublic | `` | `void` | `obj:_NV_togglePublic()` |
| dismantleButton | `` | `void` | `obj:dismantleButton()` |
| _NV_dismantleButton | `` | `void` | `obj:_NV_dismantleButton()` |
| pauseButton | `` | `void` | `obj:pauseButton()` |
| _NV_pauseButton | `` | `void` | `obj:_NV_pauseButton()` |
| confirmDismantle | `r: integer` | `void` | `obj:confirmDismantle(r)` |
| _NV_confirmDismantle | `r: integer` | `void` | `obj:_NV_confirmDismantle(r)` |
| isAShop | `` | `boolean` | `obj:isAShop()` |
| _NV_isAShop | `` | `boolean` | `obj:_NV_isAShop()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| isAWall | `` | `WallBuilding` | `obj:isAWall()` |
| _NV_isAWall | `` | `WallBuilding` | `obj:_NV_isAWall()` |
| isAWallRamp | `` | `boolean` | `obj:isAWallRamp()` |
| _NV_isAWallRamp | `` | `boolean` | `obj:_NV_isAWallRamp()` |
| hasInterior | `` | `boolean` | `obj:hasInterior()` |
| affectsNavmesh | `` | `boolean` | `obj:affectsNavmesh()` |
| setResidentSquad | `` | `void` | `obj:setResidentSquad()` |
| getResidentSquadLeader | `` | `Character` | `obj:getResidentSquadLeader()` |
| setDesignation | `d: integer` | `void` | `obj:setDesignation(d)` |
| getWallEndPosition | `` | `Vector3` | `obj:getWallEndPosition()` |
| setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| _NV_setupMiningResourceLevel | `` | `void` | `obj:_NV_setupMiningResourceLevel()` |
| getMiningResourceLevel | `` | `number` | `obj:getMiningResourceLevel()` |
| _NV_getMiningResourceLevel | `` | `number` | `obj:_NV_getMiningResourceLevel()` |
| addAnInternalBuilding | `` | `void` | `obj:addAnInternalBuilding()` |
| getNumInternalBuildings | `` | `integer` | `obj:getNumInternalBuildings()` |
| moveMountedBuildings | `` | `void` | `obj:moveMountedBuildings()` |
| reCheckInsideOutsideFortificationStatus | `` | `void` | `obj:reCheckInsideOutsideFortificationStatus()` |
| setInsideTownWalls | `code: integer` | `void` | `obj:setInsideTownWalls(code)` |
| _NV_setInsideTownWalls | `code: integer` | `void` | `obj:_NV_setInsideTownWalls(code)` |
| postCreationPathfinderSetupStuff | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| _NV_postCreationPathfinderSetupStuff | `` | `void` | `obj:_NV_postCreationPathfinderSetupStuff()` |
| getSpecialFunction | `` | `integer` | `obj:getSpecialFunction()` |
| _NV_getSpecialFunction | `` | `integer` | `obj:_NV_getSpecialFunction()` |
| getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| _NV_getFunctionStuff | `` | `StorageBuilding` | `obj:_NV_getFunctionStuff()` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| _NV_isBroken | `` | `boolean` | `obj:_NV_isBroken()` |
| setBroken | `_a1: boolean` | `void` | `obj:setBroken(_a1)` |
| _NV_setBroken | `_a1: boolean` | `void` | `obj:_NV_setBroken(_a1)` |
| switchPowerOn | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| _NV_switchPowerOn | `on: boolean` | `void` | `obj:_NV_switchPowerOn(on)` |
| isPowerOn | `` | `boolean` | `obj:isPowerOn()` |
| _NV_isPowerOn | `` | `boolean` | `obj:_NV_isPowerOn()` |
| isDamaged | `` | `boolean` | `obj:isDamaged()` |
| _NV_isDamaged | `` | `boolean` | `obj:_NV_isDamaged()` |
| isDestroyed | `` | `boolean` | `obj:isDestroyed()` |
| _NV_isDestroyed | `` | `boolean` | `obj:_NV_isDestroyed()` |
| isSign | `` | `boolean` | `obj:isSign()` |
| _NV_isSign | `` | `boolean` | `obj:_NV_isSign()` |
| setDestroyed | `d: boolean` | `void` | `obj:setDestroyed(d)` |
| _NV_setDestroyed | `d: boolean` | `void` | `obj:_NV_setDestroyed(d)` |
| canBeDestroyed | `` | `boolean` | `obj:canBeDestroyed()` |
| _NV_canBeDestroyed | `` | `boolean` | `obj:_NV_canBeDestroyed()` |
| setNestTag | `` | `void` | `obj:setNestTag()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| hasShopCountersSelling | `type: integer` | `boolean` | `obj:hasShopCountersSelling(type)` |
| getBuildingClass | `` | `integer` | `obj:getBuildingClass()` |
| _NV_getBuildingClass | `` | `integer` | `obj:_NV_getBuildingClass()` |
| needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| _NV_needsSaving | `mod: string` | `boolean` | `obj:_NV_needsSaving(mod)` |
| notifyChange | `` | `void` | `obj:notifyChange()` |
| getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| _NV_getInstanceID | `` | `InstanceID` | `obj:_NV_getInstanceID()` |
| setToDefaultFactionDivision | `` | `void` | `obj:setToDefaultFactionDivision()` |
| getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| _NV_getOutputBasedRotationSpeedMult | `` | `number` | `obj:_NV_getOutputBasedRotationSpeedMult()` |
| calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| _NV_calculateEfficiencyMult | `` | `number` | `obj:_NV_calculateEfficiencyMult()` |
| getSoundIntensity | `` | `number` | `obj:getSoundIntensity()` |
| _NV_getSoundIntensity | `` | `number` | `obj:_NV_getSoundIntensity()` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _saveBuildingState | `doorID: string` | `void` | `obj:_saveBuildingState(doorID)` |
| _NV__saveBuildingState | `doorID: string` | `void` | `obj:_NV__saveBuildingState(doorID)` |
| _loadBuildingState | `doorID: string` | `void` | `obj:_loadBuildingState(doorID)` |
| _NV__loadBuildingState | `doorID: string` | `void` | `obj:_NV__loadBuildingState(doorID)` |
| getGUIName | `category: integer` | `void` | `obj:getGUIName(category)` |
| _NV_getGUIName | `category: integer` | `void` | `obj:_NV_getGUIName(category)` |
| getGUIState | `category: integer` | `void` | `obj:getGUIState(category)` |
| _NV_getGUIState | `category: integer` | `void` | `obj:_NV_getGUIState(category)` |
| getGUICondition | `category: integer` | `void` | `obj:getGUICondition(category)` |
| _NV_getGUICondition | `category: integer` | `void` | `obj:_NV_getGUICondition(category)` |
| getGUIUpgrade | `category: integer` | `void` | `obj:getGUIUpgrade(category)` |
| _NV_getGUIUpgrade | `category: integer` | `void` | `obj:_NV_getGUIUpgrade(category)` |
| getGUIDestroyButton | `category: integer` | `void` | `obj:getGUIDestroyButton(category)` |
| _NV_getGUIDestroyButton | `category: integer` | `void` | `obj:_NV_getGUIDestroyButton(category)` |
| getProductionBuilding | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| _NV_getProductionBuilding | `` | `ProductionBuilding` | `obj:_NV_getProductionBuilding()` |
| getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| _NV_getProductionMultForGUI | `` | `number` | `obj:_NV_getProductionMultForGUI()` |
| getProductionMult | `` | `number` | `obj:getProductionMult()` |
| _NV_getProductionMult | `` | `number` | `obj:_NV_getProductionMult()` |
| isThePlayer | `` | `boolean` | `obj:isThePlayer()` |
| doorStuff | `` | `DoorStuff` | `obj:doorStuff()` |
| _NV_doorStuff | `` | `DoorStuff` | `obj:_NV_doorStuff()` |
| doorParentBuilding | `` | `Building` | `obj:doorParentBuilding()` |
| _NV_doorParentBuilding | `` | `Building` | `obj:_NV_doorParentBuilding()` |
| isDoor | `` | `boolean` | `obj:isDoor()` |
| isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| _NV_isGate | `` | `GatewayBuilding` | `obj:_NV_isGate()` |
| getDoor | `` | `DoorStuff` | `obj:getDoor()` |
| _NV_getDoor | `` | `DoorStuff` | `obj:_NV_getDoor()` |
| getParentLayout | `` | `lightuserdata` | `obj:getParentLayout()` |
| isFurniture | `` | `boolean` | `obj:isFurniture()` |
| isFurnitureOrDoor | `` | `boolean` | `obj:isFurnitureOrDoor()` |
| getIsOutsideFurniture | `` | `boolean` | `obj:getIsOutsideFurniture()` |
| setIsOutsideFurniture | `value: boolean` | `void` | `obj:setIsOutsideFurniture(value)` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| furnitureParentBuilding | `` | `Building` | `obj:furnitureParentBuilding()` |
| hasAnOpenDoor | `` | `boolean` | `obj:hasAnOpenDoor()` |
| allowAnimals | `` | `boolean` | `obj:allowAnimals()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| checkLoadedProperly | `` | `void` | `obj:checkLoadedProperly()` |
| _NV_checkLoadedProperly | `` | `void` | `obj:_NV_checkLoadedProperly()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| loadFromSerialise_TheDoors | `` | `void` | `obj:loadFromSerialise_TheDoors()` |
| _NV_loadFromSerialise_TheDoors | `` | `void` | `obj:_NV_loadFromSerialise_TheDoors()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| _NV_getDoorLock | `` | `lightuserdata` | `obj:_NV_getDoorLock()` |
| hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| _NV_hasDoorLock | `` | `boolean` | `obj:_NV_hasDoorLock()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| _changeTown | `` | `void` | `obj:_changeTown()` |
| getTownHandle | `` | `void` | `obj:getTownHandle()` |
| getTown | `` | `TownBase` | `obj:getTown()` |
| getRealTown | `` | `Town` | `obj:getRealTown()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| destroyDoors | `` | `void` | `obj:destroyDoors()` |
| createTriggerHull | `` | `void` | `obj:createTriggerHull()` |
| destroyAudioObject | `` | `void` | `obj:destroyAudioObject()` |
| getGroundType | `inside: boolean` | `integer` | `obj:getGroundType(inside)` |
| isCeilingMounted | `` | `boolean` | `obj:isCeilingMounted()` |
| _NV_isCeilingMounted | `` | `boolean` | `obj:_NV_isCeilingMounted()` |
| setFloorVisibility | `floor: integer, vis: boolean` | `void` | `obj:setFloorVisibility(floor, vis)` |
| getNumFloors | `` | `integer` | `obj:getNumFloors()` |
| buildingComplete_RestoreMaterial | `` | `void` | `obj:buildingComplete_RestoreMaterial()` |
| loadInteriorPhysical | `on: boolean` | `void` | `obj:loadInteriorPhysical(on)` |
| loadInteriorGraphics | `on: boolean` | `void` | `obj:loadInteriorGraphics(on)` |
| setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| calculateLeftPost | `` | `Vector3` | `obj:calculateLeftPost()` |
| setupLevelData | `interior: string, exterior: string` | `void` | `obj:setupLevelData(interior, exterior)` |
| getLinkLength | `` | `number` | `obj:getLinkLength()` |
| _NV_getLinkLength | `` | `number` | `obj:_NV_getLinkLength()` |
| getRootNode | `` | `lightuserdata` | `obj:getRootNode()` |
| getZoneMapLocation | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| _NV_getZoneMapLocation | `` | `ZoneMap` | `obj:_NV_getZoneMapLocation()` |
| clearTownBuildingsManagerPtr | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| _NV_clearTownBuildingsManagerPtr | `` | `void` | `obj:_NV_clearTownBuildingsManagerPtr()` |
| setup | `` | `void` | `obj:setup()` |
| _NV_setup | `` | `void` | `obj:_NV_setup()` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| _NV_switchLights | `on: boolean` | `void` | `obj:_NV_switchLights(on)` |
| switchEffects | `on: boolean` | `void` | `obj:switchEffects(on)` |
| _NV_switchEffects | `on: boolean` | `void` | `obj:_NV_switchEffects(on)` |
| hasAnyGoodPositionMarkersLeft | `` | `boolean` | `obj:hasAnyGoodPositionMarkersLeft()` |
| notifyBadPositionMarker | `what: Vector3` | `void` | `obj:notifyBadPositionMarker(what)` |
| getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getPositionMarker(currentPosition)` |
| _NV_getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getPositionMarker(currentPosition)` |
| getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| _NV_getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getDirectionMarker(currentPosition)` |
| getDirectionMarkerQuat | `currentPosition: Vector3` | `Quaternion` | `obj:getDirectionMarkerQuat(currentPosition)` |
| _NV_getDirectionMarkerQuat | `currentPosition: Vector3` | `Quaternion` | `obj:_NV_getDirectionMarkerQuat(currentPosition)` |
| isCreated | `` | `boolean` | `obj:isCreated()` |
| _NV_isCreated | `` | `boolean` | `obj:_NV_isCreated()` |
| updateUsageNodes | `` | `void` | `obj:updateUsageNodes()` |
| forceValidUsageNodesValidation | `` | `void` | `obj:forceValidUsageNodesValidation()` |
| addUsageNode | `nodeId: string` | `void` | `obj:addUsageNode(nodeId)` |
| removeUsageNode | `nodeId: string` | `void` | `obj:removeUsageNode(nodeId)` |
| clearUsageNodes | `` | `void` | `obj:clearUsageNodes()` |
| notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| updatePhysicalWithProgress | `` | `void` | `obj:updatePhysicalWithProgress()` |
| recalculateWorldAABB | `` | `void` | `obj:recalculateWorldAABB()` |
| selectPartMaterial | `` | `GameData` | `obj:selectPartMaterial()` |
| getSeed | `` | `integer` | `obj:getSeed()` |
| onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| _NV_onBuildingLoaded | `` | `void` | `obj:_NV_onBuildingLoaded()` |
| updateBadNodes | `` | `void` | `obj:updateBadNodes()` |
| isIndoors | `` | `void` | `obj:isIndoors()` |
| _NV_isIndoors | `` | `void` | `obj:_NV_isIndoors()` |
| isIndoors_notDestroyed | `` | `void` | `obj:isIndoors_notDestroyed()` |
| _NV_isIndoors_notDestroyed | `` | `void` | `obj:_NV_isIndoors_notDestroyed()` |
| getMountedBuilding | `` | `void` | `obj:getMountedBuilding()` |
| _NV_getMountedBuilding | `` | `void` | `obj:_NV_getMountedBuilding()` |
| removeAnInternalBuilding | `` | `void` | `obj:removeAnInternalBuilding()` |

## BuildingCategory
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildingContainerInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| capacityText | lightuserdata | R | `obj.capacityText` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `BuildingContainerInventoryLayout` | `obj:_CONSTRUCTOR()` |
| setCapacity | `value: integer, full: boolean` | `void` | `obj:setCapacity(value, full)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildingGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## BuildingPlacementGroundType
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

## BuildingSwaps
**Header:** `extern/KenshiLib/Include/kenshi/faction.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| toReplace | ogre_unordered_set<GameData*>::type | RW | `obj.toReplace = <value>` |
| replaceWith | FitnessSelector<GameData*> | RW | `obj.replaceWith = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hasReplacement | `` | `boolean` | `obj:hasReplacement()` |
| getReplacement | `` | `GameData` | `obj:getReplacement()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CPerfTimer
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| Stop | `` | `void` | `obj:Stop()` |
| Resolution | `` | `number` | `obj:Resolution()` |
| Resolutionms | `` | `number` | `obj:Resolutionms()` |
| Resolutionus | `` | `number` | `obj:Resolutionus()` |
| Elapsed | `` | `number` | `obj:Elapsed()` |
| Elapsedms | `` | `number` | `obj:Elapsedms()` |
| Elapsedus | `` | `number` | `obj:Elapsedus()` |

## CPerfTimerT
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`

## CameraClass
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isRotating | boolean | RW | `obj.isRotating = <value>` |
| rotationMarker | lightuserdata | R | `obj.rotationMarker` |
| yaw | number | RW | `obj.yaw = <value>` |
| pitch | number | RW | `obj.pitch = <value>` |
| initialised | boolean | RW | `obj.initialised = <value>` |
| terrainLoaded | boolean | RW | `obj.terrainLoaded = <value>` |
| objectCurrentlyFollowing | unknown | RW | `obj.objectCurrentlyFollowing = <value>` |
| objectCurrentlyFollowingOffset | Vector3 | RW | `obj.objectCurrentlyFollowingOffset = <value>` |
| center | lightuserdata | RW | `obj.center = <value>` |
| altitude | number | RW | `obj.altitude = <value>` |
| camera | lightuserdata | R | `obj.camera` |
| node | lightuserdata | R | `obj.node` |
| currentMusic | integer | RW | `obj.currentMusic = <value>` |
| inBuilding | unknown | RW | `obj.inBuilding = <value>` |
| timeInGame | number | RW | `obj.timeInGame = <value>` |
| targetPositionY | number | RW | `obj.targetPositionY = <value>` |
| speedY | number | RW | `obj.speedY = <value>` |
| centerBuilding | Building | RW | `obj.centerBuilding = <value>` |
| centerBuildingY | number | RW | `obj.centerBuildingY = <value>` |
| currentCollisionGroup | integer | RW | `obj.currentCollisionGroup = <value>` |
| currentFloor | integer | RW | `obj.currentFloor = <value>` |
| freeCameraMode | boolean | RW | `obj.freeCameraMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| update | `controlEnabled: boolean` | `void` | `obj:update(controlEnabled)` |
| focusCameraOnObject | `offset: Vector3, nearZoom: boolean` | `void` | `obj:focusCameraOnObject(offset, nearZoom)` |
| updateOptionSettings | `` | `void` | `obj:updateOptionSettings()` |
| save | `` | `void` | `obj:save()` |
| load | `` | `void` | `obj:load()` |
| teleport | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| stopFollowing | `` | `void` | `obj:stopFollowing()` |
| manuallySetOrientationAndZoom | `rot: Quaternion, zoom: number` | `void` | `obj:manuallySetOrientationAndZoom(rot, zoom)` |
| getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |
| getCenter | `` | `Vector3` | `obj:getCenter()` |
| getCameraPos | `` | `Vector3` | `obj:getCameraPos()` |
| getCenterNode | `` | `lightuserdata` | `obj:getCenterNode()` |
| getCameraNode | `` | `lightuserdata` | `obj:getCameraNode()` |
| isInitialised | `` | `boolean` | `obj:isInitialised()` |
| isFreeCameraMode | `` | `boolean` | `obj:isFreeCameraMode()` |
| setFreeCameraMode | `on: boolean` | `void` | `obj:setFreeCameraMode(on)` |
| updateFreeCamera | `` | `void` | `obj:updateFreeCamera()` |
| move | `dir: Vector3` | `void` | `obj:move(dir)` |
| zoom | `` | `void` | `obj:zoom()` |
| toGround | `smooth: boolean` | `void` | `obj:toGround(smooth)` |
| setZoomDist | `dist: number` | `void` | `obj:setZoomDist(dist)` |
| rotate | `_yaw: number, _pitch: number` | `void` | `obj:rotate(_yaw, _pitch)` |
| rotationUpdate | `` | `void` | `obj:rotationUpdate()` |
| updateAudio | `` | `void` | `obj:updateAudio()` |
| followObject | `` | `void` | `obj:followObject()` |
| getFollowObject | `` | `void` | `obj:getFollowObject()` |

## CampaignRequest
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeToStart | TimeOfDay | RW | `obj.timeToStart = <value>` |
| data | lightuserdata | R | `obj.data` |
| target | unknown | RW | `obj.target = <value>` |
| homeBase | unknown | RW | `obj.homeBase = <value>` |
| enemy | Faction | RW | `obj.enemy = <value>` |
| numAttempts | integer | RW | `obj.numAttempts = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| tryToChangeTarget | `` | `boolean` | `obj:tryToChangeTarget()` |

## CampaignTriggerData
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| what | GameData | RW | `obj.what = <value>` |
| minTime | integer | RW | `obj.minTime = <value>` |
| maxTime | integer | RW | `obj.maxTime = <value>` |
| chance | number | RW | `obj.chance = <value>` |

## CharBody
**Header:** `extern/KenshiLib/Include/kenshi/CharBody.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| combatClass | CombatClass | RW | `obj.combatClass = <value>` |
| animation | lightuserdata | RW | `obj.animation = <value>` |
| character | Character | RW | `obj.character = <value>` |
| stats | CharStats | RW | `obj.stats = <value>` |
| target | unknown | RW | `obj.target = <value>` |
| gotItem | boolean | RW | `obj.gotItem = <value>` |
| crouched | boolean | RW | `obj.crouched = <value>` |
| jogMode | boolean | RW | `obj.jogMode = <value>` |
| arbitraryCatchupDist | number | RW | `obj.arbitraryCatchupDist = <value>` |
| ai | lightuserdata | RW | `obj.ai = <value>` |
| movement | CharMovement | RW | `obj.movement = <value>` |
| frameTIME | number | RW | `obj.frameTIME = <value>` |
| currentAction | Tasker | RW | `obj.currentAction = <value>` |
| amIdle | boolean | RW | `obj.amIdle = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `CharBody` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `_time: number` | `void` | `obj:update(_time)` |
| _NV_update | `_time: number` | `void` | `obj:_NV_update(_time)` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| notifyBodyTaskComplete | `` | `void` | `obj:notifyBodyTaskComplete()` |
| notifyTaskComplete | `` | `void` | `obj:notifyTaskComplete()` |
| _NV_notifyTaskComplete | `` | `void` | `obj:_NV_notifyTaskComplete()` |
| notifyTaskImpossible | `` | `void` | `obj:notifyTaskImpossible()` |
| _NV_notifyTaskImpossible | `` | `void` | `obj:_NV_notifyTaskImpossible()` |
| getCombatClass | `` | `CombatClass` | `obj:getCombatClass()` |
| isCrouched | `` | `boolean` | `obj:isCrouched()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getName | `` | `string` | `obj:getName()` |
| isCharacter | `` | `boolean` | `obj:isCharacter()` |
| _NV_isCharacter | `` | `boolean` | `obj:_NV_isCharacter()` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| _NV_getCharacter | `` | `Character` | `obj:_NV_getCharacter()` |
| getCharBody | `` | `CharBody` | `obj:getCharBody()` |
| _NV_getCharBody | `` | `CharBody` | `obj:_NV_getCharBody()` |
| getUpFromRagdoll | `animationName: string` | `void` | `obj:getUpFromRagdoll(animationName)` |
| getPlatoon | `` | `Platoon` | `obj:getPlatoon()` |
| _NV_getPlatoon | `` | `Platoon` | `obj:_NV_getPlatoon()` |
| getCurrentAction | `` | `Tasker` | `obj:getCurrentAction()` |
| getCurrentActionOrMessage | `` | `Tasker` | `obj:getCurrentActionOrMessage()` |
| endAction | `` | `void` | `obj:endAction()` |
| isIdle | `` | `boolean` | `obj:isIdle()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| _endAction | `` | `void` | `obj:_endAction()` |
| _NV__endAction | `` | `void` | `obj:_NV__endAction()` |
| create | `a: userdata, an: userdata` | `void` | `obj:create(a, an)` |
| setCurrentAction | `t: integer` | `boolean` | `obj:setCurrentAction(t)` |
| _NV_setCurrentAction | `t: integer` | `boolean` | `obj:_NV_setCurrentAction(t)` |
| notifyPathImpossible | `` | `void` | `obj:notifyPathImpossible()` |
| _NV_notifyPathImpossible | `` | `void` | `obj:_NV_notifyPathImpossible()` |
| _move | `location: Vector3` | `void` | `obj:_move(location)` |
| _patrol | `end: integer, pos: Vector3, area: userdata, taskSys: userdata` | `void` | `obj:_patrol(end, pos, area, taskSys)` |
| getHandle | `` | `void` | `obj:getHandle()` |
| getCurrentSubject | `` | `void` | `obj:getCurrentSubject()` |

## CharMovement
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| flockingVector | Vector3 | RW | `obj.flockingVector = <value>` |
| combatMover | CombatMovementController | RW | `obj.combatMover = <value>` |
| combatMover2 | FormationMover | RW | `obj.combatMover2 = <value>` |
| flockingTools | FlockingTools | RW | `obj.flockingTools = <value>` |
| formation | lightuserdata | R | `obj.formation` |
| enemyFormation | lightuserdata | R | `obj.enemyFormation` |
| havokCharacter | lightuserdata | R | `obj.havokCharacter` |
| tracer | lightuserdata | R | `obj.tracer` |
| dontEverRecreateMe | boolean | RW | `obj.dontEverRecreateMe = <value>` |
| floorGroup | integer | RW | `obj.floorGroup = <value>` |
| building | unknown | RW | `obj.building = <value>` |
| initCheck | boolean | RW | `obj.initCheck = <value>` |
| _combatMoveSpeedMult | number | RW | `obj._combatMoveSpeedMult = <value>` |
| destinationLoaded | boolean | RW | `obj.destinationLoaded = <value>` |
| footprintRadius | number | RW | `obj.footprintRadius = <value>` |
| edgeTarget | integer | RW | `obj.edgeTarget = <value>` |
| _lastOffMeshCheck | number | RW | `obj._lastOffMeshCheck = <value>` |
| movingToEdge | boolean | RW | `obj.movingToEdge = <value>` |
| lastStepTime | number | RW | `obj.lastStepTime = <value>` |
| animationOverride | boolean | RW | `obj.animationOverride = <value>` |
| trackingAnimRelocationVector | Vector3 | RW | `obj.trackingAnimRelocationVector = <value>` |
| desiredMotion | Vector3 | RW | `obj.desiredMotion = <value>` |
| moveLimit | number | RW | `obj.moveLimit = <value>` |
| animation | lightuserdata | RW | `obj.animation = <value>` |
| character | Character | RW | `obj.character = <value>` |
| clickHull | lightuserdata | R | `obj.clickHull` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `CharMovement` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _NV__setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_NV__setPositionAndTeleport(p, floor)` |
| _setPositionDirectionAndTeleport | `position: Vector3, orientation: Quaternion` | `void` | `obj:_setPositionDirectionAndTeleport(position, orientation)` |
| _NV__setPositionDirectionAndTeleport | `position: Vector3, orientation: Quaternion` | `void` | `obj:_NV__setPositionDirectionAndTeleport(position, orientation)` |
| _setPositionSimple | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| _NV__setPositionSimple | `p: Vector3` | `void` | `obj:_NV__setPositionSimple(p)` |
| isRunning | `` | `boolean` | `obj:isRunning()` |
| isRunningAway | `from: Vector3` | `boolean` | `obj:isRunningAway(from)` |
| trackAnimationMovement | `on: boolean` | `void` | `obj:trackAnimationMovement(on)` |
| getHandle | `` | `void` | `obj:getHandle()` |
| _NV_getHandle | `` | `void` | `obj:_NV_getHandle()` |
| handleChanged | `` | `void` | `obj:handleChanged()` |
| _NV_handleChanged | `` | `void` | `obj:_NV_handleChanged()` |
| getRadius | `` | `number` | `obj:getRadius()` |
| update | `_TIME: number` | `void` | `obj:update(_TIME)` |
| _NV_update | `_TIME: number` | `void` | `obj:_NV_update(_TIME)` |
| pausedUpdate | `` | `void` | `obj:pausedUpdate()` |
| twoFrameUpdate | `_TIME: number` | `void` | `obj:twoFrameUpdate(_TIME)` |
| postAnimationUpdate | `` | `void` | `obj:postAnimationUpdate()` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| predictNextPosition | `accurate: boolean` | `Vector3` | `obj:predictNextPosition(accurate)` |
| getMaximumPossibleMovement | `` | `number` | `obj:getMaximumPossibleMovement()` |
| faceDirection | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| _NV_faceDirection | `dir: Vector3` | `void` | `obj:_NV_faceDirection(dir)` |
| lookatPosition | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| _NV_lookatPosition | `pos: Vector3` | `void` | `obj:_NV_lookatPosition(pos)` |
| pathOk | `` | `boolean` | `obj:pathOk()` |
| _NV_pathOk | `` | `boolean` | `obj:_NV_pathOk()` |
| pathFailed | `` | `boolean` | `obj:pathFailed()` |
| _NV_pathFailed | `` | `boolean` | `obj:_NV_pathFailed()` |
| isDestinationReached | `` | `boolean` | `obj:isDestinationReached()` |
| _NV_isDestinationReached | `` | `boolean` | `obj:_NV_isDestinationReached()` |
| isIdle | `` | `boolean` | `obj:isIdle()` |
| _NV_isIdle | `` | `boolean` | `obj:_NV_isIdle()` |
| playerMoveOrderWhileInCombatMode | `pos: Vector3` | `boolean` | `obj:playerMoveOrderWhileInCombatMode(pos)` |
| _NV_playerMoveOrderWhileInCombatMode | `pos: Vector3` | `boolean` | `obj:_NV_playerMoveOrderWhileInCombatMode(pos)` |
| halt | `` | `void` | `obj:halt()` |
| _NV_halt | `` | `void` | `obj:_NV_halt()` |
| invalidatePath | `` | `void` | `obj:invalidatePath()` |
| movedBy | `pos: Vector3` | `void` | `obj:movedBy(pos)` |
| isCombatMovementBlockedByCharacters | `` | `boolean` | `obj:isCombatMovementBlockedByCharacters()` |
| destroy | `` | `void` | `obj:destroy()` |
| restore | `` | `void` | `obj:restore()` |
| refreshClickHull | `` | `void` | `obj:refreshClickHull()` |
| teleportCollisionHull | `_pos: Vector3` | `void` | `obj:teleportCollisionHull(_pos)` |
| getCurrentFloor | `` | `integer` | `obj:getCurrentFloor()` |
| isIndoorsHideMeCheck | `` | `boolean` | `obj:isIndoorsHideMeCheck()` |
| isIndoors | `` | `boolean` | `obj:isIndoors()` |
| manualMovement | `v: Vector3` | `void` | `obj:manualMovement(v)` |
| _NV_manualMovement | `v: Vector3` | `void` | `obj:_NV_manualMovement(v)` |
| isInsideBuildingLoadedInterior | `` | `boolean` | `obj:isInsideBuildingLoadedInterior()` |
| hasClickHull | `` | `boolean` | `obj:hasClickHull()` |
| isTrackingAnimationMode | `` | `boolean` | `obj:isTrackingAnimationMode()` |
| isWaypointMoveMode | `` | `boolean` | `obj:isWaypointMoveMode()` |
| setDirectMovement | `d: Vector3, limit: number` | `void` | `obj:setDirectMovement(d, limit)` |
| getLastGroundTraceResultMT | `` | `physHit` | `obj:getLastGroundTraceResultMT()` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| toGround | `` | `boolean` | `obj:toGround()` |
| updateGroundMaterial | `` | `void` | `obj:updateGroundMaterial()` |
| getCombatMoveSpeedMult | `` | `number` | `obj:getCombatMoveSpeedMult()` |
| setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:setDestination(dest, notVertical)` |
| _NV_setDestination | `dest: Vector3, notVertical: boolean` | `void` | `obj:_NV_setDestination(dest, notVertical)` |
| setLookatTarget | `` | `void` | `obj:setLookatTarget()` |

## CharStats
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| medical | MedicalSystem | RW | `obj.medical = <value>` |
| me | Character | RW | `obj.me = <value>` |
| athleticsMultiplier | number | RW | `obj.athleticsMultiplier = <value>` |
| combatSpeedMultiplier | number | RW | `obj.combatSpeedMultiplier = <value>` |
| _skillBonusAttack | integer | RW | `obj._skillBonusAttack = <value>` |
| _skillBonusDefence | integer | RW | `obj._skillBonusDefence = <value>` |
| skillBonusIndoors | integer | RW | `obj.skillBonusIndoors = <value>` |
| skillBonusUnarmed | integer | RW | `obj.skillBonusUnarmed = <value>` |
| skillBonusPerception | integer | RW | `obj.skillBonusPerception = <value>` |
| ageMult | number | RW | `obj.ageMult = <value>` |
| skillMultDodge | number | RW | `obj.skillMultDodge = <value>` |
| skillMultStealth | number | RW | `obj.skillMultStealth = <value>` |
| skillMultAssassin | number | RW | `obj.skillMultAssassin = <value>` |
| skillMultDexterity | number | RW | `obj.skillMultDexterity = <value>` |
| skillMultDamage | number | RW | `obj.skillMultDamage = <value>` |
| fistInjuryEquipmentMult | number | RW | `obj.fistInjuryEquipmentMult = <value>` |
| skillMultRanged | number | RW | `obj.skillMultRanged = <value>` |
| _strength | number | RW | `obj._strength = <value>` |
| fitness | number | RW | `obj.fitness = <value>` |
| _dexterity | number | RW | `obj._dexterity = <value>` |
| perception | number | RW | `obj.perception = <value>` |
| _toughness | number | RW | `obj._toughness = <value>` |
| _athletics | number | RW | `obj._athletics = <value>` |
| medic | number | RW | `obj.medic = <value>` |
| massCombat | number | RW | `obj.massCombat = <value>` |
| arrowDefence | number | RW | `obj.arrowDefence = <value>` |
| stealth | number | RW | `obj.stealth = <value>` |
| swimming | number | RW | `obj.swimming = <value>` |
| thieving | number | RW | `obj.thieving = <value>` |
| lockpicking | number | RW | `obj.lockpicking = <value>` |
| bluff | number | RW | `obj.bluff = <value>` |
| assassin | number | RW | `obj.assassin = <value>` |
| survival | number | RW | `obj.survival = <value>` |
| tracking | number | RW | `obj.tracking = <value>` |
| climbing | number | RW | `obj.climbing = <value>` |
| doctor | number | RW | `obj.doctor = <value>` |
| engineer | number | RW | `obj.engineer = <value>` |
| weaponSmith | number | RW | `obj.weaponSmith = <value>` |
| armourSmith | number | RW | `obj.armourSmith = <value>` |
| bowSmith | number | RW | `obj.bowSmith = <value>` |
| robotics | number | RW | `obj.robotics = <value>` |
| science | number | RW | `obj.science = <value>` |
| labouring | number | RW | `obj.labouring = <value>` |
| farming | number | RW | `obj.farming = <value>` |
| cooking | number | RW | `obj.cooking = <value>` |
| dodging | number | RW | `obj.dodging = <value>` |
| friendlyFire | number | RW | `obj.friendlyFire = <value>` |
| katanas | number | RW | `obj.katanas = <value>` |
| sabres | number | RW | `obj.sabres = <value>` |
| hackers | number | RW | `obj.hackers = <value>` |
| blunt | number | RW | `obj.blunt = <value>` |
| heavyWeapons | number | RW | `obj.heavyWeapons = <value>` |
| unarmed | number | RW | `obj.unarmed = <value>` |
| bows | number | RW | `obj.bows = <value>` |
| turrets | number | RW | `obj.turrets = <value>` |
| polearms | number | RW | `obj.polearms = <value>` |
| currentItemMaximumJuryRig | number | RW | `obj.currentItemMaximumJuryRig = <value>` |
| __meleeAttack | number | RW | `obj.__meleeAttack = <value>` |
| _meleeDefence | number | RW | `obj._meleeDefence = <value>` |
| _defensiveMode | boolean | RW | `obj._defensiveMode = <value>` |
| rangedMode | boolean | RW | `obj.rangedMode = <value>` |
| tauntMode | boolean | RW | `obj.tauntMode = <value>` |
| _holdPositionMode | boolean | RW | `obj._holdPositionMode = <value>` |
| passiveCombatMode | boolean | RW | `obj.passiveCombatMode = <value>` |
| holdLocation | Vector3 | RW | `obj.holdLocation = <value>` |
| warriorSpirit | number | RW | `obj.warriorSpirit = <value>` |
| derivedSpirit | number | RW | `obj.derivedSpirit = <value>` |
| aggression | number | RW | `obj.aggression = <value>` |
| goodness | number | RW | `obj.goodness = <value>` |
| evilness | number | RW | `obj.evilness = <value>` |
| longestReachingAttack | number | RW | `obj.longestReachingAttack = <value>` |
| STUBBOURNESS | number | RW | `obj.STUBBOURNESS = <value>` |
| PROFESSIONALNESS | number | RW | `obj.PROFESSIONALNESS = <value>` |
| HOLDING_POSITION | number | RW | `obj.HOLDING_POSITION = <value>` |
| IMMEDIACY | number | RW | `obj.IMMEDIACY = <value>` |
| IMMEDIACY_MAX_RANGE | number | RW | `obj.IMMEDIACY_MAX_RANGE = <value>` |
| MANLINESS | number | RW | `obj.MANLINESS = <value>` |
| MURDEROUS | number | RW | `obj.MURDEROUS = <value>` |
| _stealthXPMultForGUI | number | RW | `obj._stealthXPMultForGUI = <value>` |
| stealthXPTooManyCooksPenalty | number | RW | `obj.stealthXPTooManyCooksPenalty = <value>` |
| currentOperatingMachineHungerRate | number | RW | `obj.currentOperatingMachineHungerRate = <value>` |
| moveSpeed | number | RW | `obj.moveSpeed = <value>` |
| weaponWeightSpeedMult | number | RW | `obj.weaponWeightSpeedMult = <value>` |
| weaponWeightXPMult | number | RW | `obj.weaponWeightXPMult = <value>` |
| attackSpeed | number | RW | `obj.attackSpeed = <value>` |
| blockSpeed | number | RW | `obj.blockSpeed = <value>` |
| encumbranceMult | number | RW | `obj.encumbranceMult = <value>` |
| xp | number | RW | `obj.xp = <value>` |
| freeAttributePoints | integer | RW | `obj.freeAttributePoints = <value>` |
| cutDamageMult | number | RW | `obj.cutDamageMult = <value>` |
| bluntDamageMult | number | RW | `obj.bluntDamageMult = <value>` |
| bleedDamageMult | number | RW | `obj.bleedDamageMult = <value>` |
| pierceDamageMult | number | RW | `obj.pierceDamageMult = <value>` |
| cutDamageMin | number | RW | `obj.cutDamageMin = <value>` |
| bluntDamageMin | number | RW | `obj.bluntDamageMin = <value>` |
| bonusRobots | number | RW | `obj.bonusRobots = <value>` |
| bonusHumans | number | RW | `obj.bonusHumans = <value>` |
| bonusAnimals | number | RW | `obj.bonusAnimals = <value>` |
| bonusArmourPenetration | number | RW | `obj.bonusArmourPenetration = <value>` |
| currentWeaponType | integer | RW | `obj.currentWeaponType = <value>` |
| pCurrentWeaponSkill | lightuserdata | RW | `obj.pCurrentWeaponSkill = <value>` |
| currentWeaponLength | number | RW | `obj.currentWeaponLength = <value>` |
| weapon | unknown | RW | `obj.weapon = <value>` |
| weaponWeight | number | RW | `obj.weaponWeight = <value>` |
| _weatherProtections | WeatherProtectionsMapBinding::MapType | RW | `obj._weatherProtections = <value>` |
| bonusRaces | BonusRacesMapBinding::MapType | RW | `obj.bonusRaces = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWeatherProtection | `w: integer` | `number` | `obj:getWeatherProtection(w)` |
| _CONSTRUCTOR | `` | `CharStats` | `obj:_CONSTRUCTOR()` |
| unarmedEncumbrancePenalty | `` | `integer` | `obj:unarmedEncumbrancePenalty()` |
| skillBonusUnarmed_forGUI | `factorEnvironment: boolean` | `integer` | `obj:skillBonusUnarmed_forGUI(factorEnvironment)` |
| skillBonusAttack_melee | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_melee(factorEnvironment)` |
| skillBonusAttack_unarmed | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_unarmed(factorEnvironment)` |
| skillBonusDefence | `factorEnvironment: boolean` | `integer` | `obj:skillBonusDefence(factorEnvironment)` |
| serialise | `` | `void` | `obj:serialise()` |
| updateStats | `` | `void` | `obj:updateStats()` |
| init | `` | `void` | `obj:init()` |
| _NV_init | `` | `void` | `obj:_NV_init()` |
| _randomiseStats | `amount: number` | `void` | `obj:_randomiseStats(amount)` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| getGUIDataForMainInfo | `category: integer, combatMode: boolean` | `void` | `obj:getGUIDataForMainInfo(category, combatMode)` |
| getGUIStatsDisplayMode | `` | `integer` | `obj:getGUIStatsDisplayMode()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| calculateStumbleThresholdDamageAmount | `` | `number` | `obj:calculateStumbleThresholdDamageAmount()` |
| setEquipmentStatBonuses | `athlet: number, combatSpd: number, attack: integer, def: integer, _stealth: number, _unarmed: integer, _dodge: number, fistdamage: number, perception: integer, ranged: number, dexmult: number, assmult: number, damagemult: number` | `void` | `obj:setEquipmentStatBonuses(athlet, combatSpd, attack, def, _stealth, _unarmed, _dodge, fistdamage, perception, ranged, dexmult, assmult, damagemult)` |
| getOverallSkillLevel_0_100 | `` | `number` | `obj:getOverallSkillLevel_0_100()` |
| getStat | `what: integer, unmodified: boolean` | `number` | `obj:getStat(what, unmodified)` |
| getStatMultiplier | `st: integer` | `number` | `obj:getStatMultiplier(st)` |
| getStatMultiplierForGUI | `st: integer` | `string` | `obj:getStatMultiplierForGUI(st)` |
| getStatPenaltiesTotalForGUI | `statName: string, stat: integer` | `integer` | `obj:getStatPenaltiesTotalForGUI(statName, stat)` |
| xpStat_timeBased | `st: integer` | `void` | `obj:xpStat_timeBased(st)` |
| xpStat_eventBased | `st: integer, amount: number` | `void` | `obj:xpStat_eventBased(st, amount)` |
| xpDodgeEvent | `enemySkill: number, successful: boolean` | `void` | `obj:xpDodgeEvent(enemySkill, successful)` |
| strengthActual | `` | `number` | `obj:strengthActual()` |
| strengthBase | `` | `number` | `obj:strengthBase()` |
| _NV_strengthBase | `` | `number` | `obj:_NV_strengthBase()` |
| dexterityBase | `` | `number` | `obj:dexterityBase()` |
| dexterityActual | `` | `number` | `obj:dexterityActual()` |
| toughness | `` | `number` | `obj:toughness()` |
| getToughnessMult | `` | `number` | `obj:getToughnessMult()` |
| getRangedFriendlyFireAvoidanceChance | `` | `number` | `obj:getRangedFriendlyFireAvoidanceChance()` |
| getRangedAccuracyMult | `stat: integer` | `number` | `obj:getRangedAccuracyMult(stat)` |
| getReloadSkill | `stat: integer` | `number` | `obj:getReloadSkill(stat)` |
| animalRecruitReduceStats | `` | `void` | `obj:animalRecruitReduceStats()` |
| getMeleeDefence | `includeDefensiveMode: boolean` | `number` | `obj:getMeleeDefence(includeDefensiveMode)` |
| getDodge | `bonuses: boolean` | `number` | `obj:getDodge(bonuses)` |
| getDodgePenalty_encumbrance | `` | `number` | `obj:getDodgePenalty_encumbrance()` |
| getDodgePenalty_injuries | `` | `number` | `obj:getDodgePenalty_injuries()` |
| getDodgePenalty_gear | `` | `number` | `obj:getDodgePenalty_gear()` |
| getMeleeDefence_melee | `includeDefensiveMode: boolean` | `number` | `obj:getMeleeDefence_melee(includeDefensiveMode)` |
| getMeleeAttack | `` | `number` | `obj:getMeleeAttack()` |
| getMeleeAttack_unarmed | `bonuses: boolean` | `number` | `obj:getMeleeAttack_unarmed(bonuses)` |
| getMeleeAttack_melee | `` | `number` | `obj:getMeleeAttack_melee()` |
| _getMeleeAttackBase | `` | `number` | `obj:_getMeleeAttackBase()` |
| getMaxHealAmount | `isRobot: boolean` | `number` | `obj:getMaxHealAmount(isRobot)` |
| isDefensiveMode | `` | `boolean` | `obj:isDefensiveMode()` |
| holdPositionMode | `` | `boolean` | `obj:holdPositionMode()` |
| setHoldLocation | `v: Vector3` | `void` | `obj:setHoldLocation(v)` |
| clearHoldLocation | `` | `void` | `obj:clearHoldLocation()` |
| getBashAnimation | `range: number` | `CombatTechniqueData` | `obj:getBashAnimation(range)` |
| chooseAttack | `range: number, weaponReach: number, opponentIsStationary: boolean` | `CombatTechniqueData` | `obj:chooseAttack(range, weaponReach, opponentIsStationary)` |
| chooseBlock | `dir: integer, opponentAttackSkill: number, from: integer` | `CombatTechniqueData` | `obj:chooseBlock(dir, opponentAttackSkill, from)` |
| calculateStumbleBlockTimer | `stumbleForce: number` | `number` | `obj:calculateStumbleBlockTimer(stumbleForce)` |
| calculateTechniqueInegrityCheckTimer | `` | `number` | `obj:calculateTechniqueInegrityCheckTimer()` |
| calculateToughnessDamageResistanceMult | `` | `number` | `obj:calculateToughnessDamageResistanceMult()` |
| calculateToughnessWoundDegenerationRate | `` | `number` | `obj:calculateToughnessWoundDegenerationRate()` |
| getAttackChance | `` | `number` | `obj:getAttackChance()` |
| getAttackCuttingDamage | `` | `number` | `obj:getAttackCuttingDamage()` |
| getAttackBluntPower | `` | `number` | `obj:getAttackBluntPower()` |
| getAttackBleedDamageMult | `` | `number` | `obj:getAttackBleedDamageMult()` |
| getAttackPierceDamage | `` | `number` | `obj:getAttackPierceDamage()` |
| getTotalAttackDamageFor | `` | `void` | `obj:getTotalAttackDamageFor()` |
| getEquippedWeaponSkill | `` | `number` | `obj:getEquippedWeaponSkill()` |
| _NV_getEquippedWeaponSkill | `` | `number` | `obj:_NV_getEquippedWeaponSkill()` |
| getSkillDifferenceRatio | `mine: number, his: number` | `number` | `obj:getSkillDifferenceRatio(mine, his)` |
| calculateDeadTime | `state: integer` | `number` | `obj:calculateDeadTime(state)` |
| xpToughness_RagdollEvent | `` | `void` | `obj:xpToughness_RagdollEvent()` |
| xpToughness_GetUpEvent | `` | `void` | `obj:xpToughness_GetUpEvent()` |
| xpToughness_PunchSomething | `mat: integer` | `void` | `obj:xpToughness_PunchSomething(mat)` |
| xpFirstAid | `time: number, medicStat: integer` | `void` | `obj:xpFirstAid(time, medicStat)` |
| xpRunning | `time: number, speed: number` | `void` | `obj:xpRunning(time, speed)` |
| xpStealth | `time: number, enemiesAbout: boolean, isMoving: boolean` | `void` | `obj:xpStealth(time, enemiesAbout, isMoving)` |
| xpStealthHearCheckEvent | `enemiesAbout: boolean, trespassing: boolean, seen: boolean` | `void` | `obj:xpStealthHearCheckEvent(enemiesAbout, trespassing, seen)` |
| stealthXPMultForGUI | `` | `void` | `obj:stealthXPMultForGUI()` |
| xpMassCombat | `` | `void` | `obj:xpMassCombat()` |
| xpEngineering | `time: number` | `void` | `obj:xpEngineering(time)` |
| xpLockpicking | `lockLevel: integer, success: boolean` | `void` | `obj:xpLockpicking(lockLevel, success)` |
| xpGeneral | `time: number, mult: number, what: integer` | `void` | `obj:xpGeneral(time, mult, what)` |
| calculateAthleticsXPMult | `speed: number` | `number` | `obj:calculateAthleticsXPMult(speed)` |
| calculateStrengthXPMultFromWalking | `` | `number` | `obj:calculateStrengthXPMultFromWalking()` |
| setWeapon | `` | `void` | `obj:setWeapon()` |
| isUnarmed | `` | `boolean` | `obj:isUnarmed()` |
| getWeaponWeightXPBonus | `` | `number` | `obj:getWeaponWeightXPBonus()` |
| getAttackSpeed | `` | `number` | `obj:getAttackSpeed()` |
| getBlockSpeed | `` | `number` | `obj:getBlockSpeed()` |
| getMaxRunSpeed | `` | `number` | `obj:getMaxRunSpeed()` |
| getCurrentWeaponLength | `` | `number` | `obj:getCurrentWeaponLength()` |
| getStealthSkill01 | `modded: boolean` | `number` | `obj:getStealthSkill01(modded)` |
| getAttackSuccessChanceSkill | `` | `number` | `obj:getAttackSuccessChanceSkill()` |
| getEncumbranceMult | `` | `number` | `obj:getEncumbranceMult()` |
| calculateHungerMult | `` | `number` | `obj:calculateHungerMult()` |
| calculateTheoreticalIdealMaxRunSpeed | `` | `number` | `obj:calculateTheoreticalIdealMaxRunSpeed()` |
| calculateWeaponWeightXPMult | `weaponWeight: number` | `number` | `obj:calculateWeaponWeightXPMult(weaponWeight)` |
| hasWeapon | `` | `boolean` | `obj:hasWeapon()` |
| calculateMaxStealthSpeed | `` | `number` | `obj:calculateMaxStealthSpeed()` |
| _calculateMaxSwimSpeed | `` | `number` | `obj:_calculateMaxSwimSpeed()` |
| calculateSwimSpeed | `` | `number` | `obj:calculateSwimSpeed()` |
| calculateDodgeChance | `versus: number, stumbling: boolean` | `number` | `obj:calculateDodgeChance(versus, stumbling)` |
| calculateMaxRunSpeed | `` | `void` | `obj:calculateMaxRunSpeed()` |
| _calculateEncumberanceMult | `` | `number` | `obj:_calculateEncumberanceMult()` |
| _calculateWeaponWeightSpeedMultiplier | `weaponWeight: number` | `void` | `obj:_calculateWeaponWeightSpeedMultiplier(weaponWeight)` |
| currentWeaponHand | `` | `integer` | `obj:currentWeaponHand()` |
| calculateAttackOrBlockSpeed | `weaponWeightSpeedMult: number, attackOrBlockSkill: number, isBlock: boolean` | `number` | `obj:calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock)` |
| _calculateBlockChance | `versus: number` | `number` | `obj:_calculateBlockChance(versus)` |
| _recalculateStats | `` | `void` | `obj:_recalculateStats()` |
| _NV__recalculateStats | `` | `void` | `obj:_NV__recalculateStats()` |
| setEquippedWeaponSkill | `v: number` | `void` | `obj:setEquippedWeaponSkill(v)` |
| _NV_setEquippedWeaponSkill | `v: number` | `void` | `obj:_NV_setEquippedWeaponSkill(v)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getStrength | `` | `number` | `obj:getStrength()` |
| getStrengthRaw | `` | `number` | `obj:getStrengthRaw()` |
| getDexterity | `` | `number` | `obj:getDexterity()` |
| getDexterityRaw | `` | `number` | `obj:getDexterityRaw()` |
| getToughness | `` | `number` | `obj:getToughness()` |
| getPerception | `` | `number` | `obj:getPerception()` |
| getAthletics | `` | `number` | `obj:getAthletics()` |
| getThieving | `` | `number` | `obj:getThieving()` |
| printStealthStats | `` | `void` | `obj:printStealthStats()` |
| printRunSpeedStatMax | `` | `void` | `obj:printRunSpeedStatMax()` |
| formatWholeStatStringWithBonuses | `stat: integer, current: integer` | `void` | `obj:formatWholeStatStringWithBonuses(stat, current)` |
| getStatRef | `what: integer` | `number` | `obj:getStatRef(what)` |
| getStatName | `` | `void` | `obj:getStatName()` |
| getMeleeAttackRef | `` | `number` | `obj:getMeleeAttackRef()` |
| getPainAnim | `` | `void` | `obj:getPainAnim()` |
| xpMelee | `what: integer` | `void` | `obj:xpMelee(what)` |
| convertWeaponWeightToBluntMultiplier | `` | `number` | `obj:convertWeaponWeightToBluntMultiplier()` |
| convertBluntMultiplierToWeaponWeight | `` | `number` | `obj:convertBluntMultiplierToWeaponWeight()` |
| setupCombatTechniques | `` | `void` | `obj:setupCombatTechniques()` |
| getStealthTooltip | `` | `void` | `obj:getStealthTooltip()` |
| getAthleticsTooltip | `` | `void` | `obj:getAthleticsTooltip()` |
| getStatPenaltiesForGUI | `statName: string, stat: integer` | `boolean` | `obj:getStatPenaltiesForGUI(statName, stat)` |
| chooseAttacks | `range: number, weaponReach: number, opponentIsStationary: boolean, skipMedicals: boolean, _weaponType: integer, _weaponSkill: number` | `void` | `obj:chooseAttacks(range, weaponReach, opponentIsStationary, skipMedicals, _weaponType, _weaponSkill)` |
| printExertionHungerMultTooltip | `` | `void` | `obj:printExertionHungerMultTooltip()` |
| xpTraining | `time: number, mult: number, statVal: number, upperLimit: number, whatStatIsIt: integer` | `number` | `obj:xpTraining(time, mult, statVal, upperLimit, whatStatIsIt)` |

## Character
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| offscreenFrameTime | number | RW | `obj.offscreenFrameTime = <value>` |
| frameTIME | number | RW | `obj.frameTIME = <value>` |
| frameTIMEfour | number | RW | `obj.frameTIMEfour = <value>` |
| frameTIME_P | number | RW | `obj.frameTIME_P = <value>` |
| bodyDecayTimer | number | RW | `obj.bodyDecayTimer = <value>` |
| stealthMode | boolean | RW | `obj.stealthMode = <value>` |
| _isOnARoof | boolean | RW | `obj._isOnARoof = <value>` |
| _lightLevel | number | RW | `obj._lightLevel = <value>` |
| needsLightLevel | boolean | RW | `obj.needsLightLevel = <value>` |
| _currentProneState | integer | RW | `obj._currentProneState = <value>` |
| isVisibleUpdateMode | boolean | RW | `obj.isVisibleUpdateMode = <value>` |
| setVisibleMsg | boolean | RW | `obj.setVisibleMsg = <value>` |
| stealthUnseen | YesNoMaybe | RW | `obj.stealthUnseen = <value>` |
| playerWantsMeToGetUp | boolean | RW | `obj.playerWantsMeToGetUp = <value>` |
| crimes | BountyManager | RW | `obj.crimes = <value>` |
| currentSkillUsing | integer | RW | `obj.currentSkillUsing = <value>` |
| stateBroadcast | lightuserdata | RW | `obj.stateBroadcast = <value>` |
| isVisibleAndNear | boolean | RW | `obj.isVisibleAndNear = <value>` |
| isOnScreen | boolean | RW | `obj.isOnScreen = <value>` |
| stealthMarkerArrows | Character::AttachedArrowManager | R | `obj.stealthMarkerArrows` |
| _isEngagedWithAPlayer | boolean | RW | `obj._isEngagedWithAPlayer = <value>` |
| isUsingTurret | unknown | RW | `obj.isUsingTurret = <value>` |
| isCurrentlyGettingUp | boolean | RW | `obj.isCurrentlyGettingUp = <value>` |
| isGettingEaten | integer | RW | `obj.isGettingEaten = <value>` |
| dialogue | Dialogue | RW | `obj.dialogue = <value>` |
| currentStumblePainAnimation | string | RW | `obj.currentStumblePainAnimation = <value>` |
| _isLiterallyUnderMeleeAttackRightNowForSure | boolean | RW | `obj._isLiterallyUnderMeleeAttackRightNowForSure = <value>` |
| _myMemory | lightuserdata | RW | `obj._myMemory = <value>` |
| lastGuyWhoDefeatedMe | unknown | RW | `obj.lastGuyWhoDefeatedMe = <value>` |
| myRace | RaceData | RW | `obj.myRace = <value>` |
| inventory | Inventory | RW | `obj.inventory = <value>` |
| rangedCombat | lightuserdata | RW | `obj.rangedCombat = <value>` |
| inWhat | unknown | RW | `obj.inWhat = <value>` |
| isChained | boolean | RW | `obj.isChained = <value>` |
| slaveOwner | unknown | RW | `obj.slaveOwner = <value>` |
| isCarryingSomething | boolean | RW | `obj.isCarryingSomething = <value>` |
| carringObjectLeftOrRight | string | RW | `obj.carringObjectLeftOrRight = <value>` |
| isCarryingLeftSide | boolean | RW | `obj.isCarryingLeftSide = <value>` |
| carryingObject | unknown | RW | `obj.carryingObject = <value>` |
| messages | integer | RW | `obj.messages = <value>` |
| messageSubject | unknown | RW | `obj.messageSubject = <value>` |
| ragdollNavmeshPosition | Vector3 | RW | `obj.ragdollNavmeshPosition = <value>` |
| _isBeingCarried | boolean | RW | `obj._isBeingCarried = <value>` |
| lastUsedWeaponCategory | integer | RW | `obj.lastUsedWeaponCategory = <value>` |
| msgCarryMode | lightuserdata | RW | `obj.msgCarryMode = <value>` |
| squadMemberID | integer | RW | `obj.squadMemberID = <value>` |
| diplomacyMultiplier | number | RW | `obj.diplomacyMultiplier = <value>` |
| _destinationInsideBuilding | unknown | RW | `obj._destinationInsideBuilding = <value>` |
| _destinationInsideWalls | integer | RW | `obj._destinationInsideWalls = <value>` |
| animation | lightuserdata | RW | `obj.animation = <value>` |
| stats | CharStats | RW | `obj.stats = <value>` |
| medical | MedicalSystem | RW | `obj.medical = <value>` |
| isPhysicalMode | boolean | RW | `obj.isPhysicalMode = <value>` |
| sex | string | RW | `obj.sex = <value>` |
| nameTag | lightuserdata | RW | `obj.nameTag = <value>` |
| movement | CharMovement | RW | `obj.movement = <value>` |
| body | CharBody | RW | `obj.body = <value>` |
| ai | lightuserdata | RW | `obj.ai = <value>` |
| platoon | ActivePlatoon | RW | `obj.platoon = <value>` |
| portraitIndex | integer | RW | `obj.portraitIndex = <value>` |
| portraitSerial | integer | RW | `obj.portraitSerial = <value>` |
| groundType | integer | RW | `obj.groundType = <value>` |
| armourType | integer | RW | `obj.armourType = <value>` |
| audioEmitter | lightuserdata | RW | `obj.audioEmitter = <value>` |
| terrainHeightPosition | number | RW | `obj.terrainHeightPosition = <value>` |
| inDoorsSetCooldown | integer | RW | `obj.inDoorsSetCooldown = <value>` |
| naturalWeapon | Sword | RW | `obj.naturalWeapon = <value>` |
| disguiseGUIFeedbacks | integer | R | `obj.disguiseGUIFeedbacks` |
| whoSeesMeSneaking | Character::WhoSeesMe | R | `obj.whoSeesMeSneaking` |
| inSomething | integer | RW | `obj.inSomething = <value>` |
| audioObject | integer | RW | `obj.audioObject = <value>` |
| activeEffects | integer | R | `obj.activeEffects` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isImmuneToOffscreenMode | `` | `boolean` | `obj:isImmuneToOffscreenMode()` |
| init | `` | `void` | `obj:init()` |
| _NV_init | `` | `void` | `obj:_NV_init()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isOnARoof | `` | `boolean` | `obj:isOnARoof()` |
| _NV_isOnARoof | `` | `boolean` | `obj:_NV_isOnARoof()` |
| isOnAWall | `` | `boolean` | `obj:isOnAWall()` |
| _NV_isOnAWall | `` | `boolean` | `obj:_NV_isOnAWall()` |
| getLightLevel | `` | `number` | `obj:getLightLevel()` |
| getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| _NV_getHPMultiplier | `` | `number` | `obj:_NV_getHPMultiplier()` |
| healCompletely | `` | `void` | `obj:healCompletely()` |
| resetRagdollNavmeshSafePos | `` | `void` | `obj:resetRagdollNavmeshSafePos()` |
| setRagdollNavmeshSafePos | `` | `void` | `obj:setRagdollNavmeshSafePos()` |
| getFrameTime | `` | `number` | `obj:getFrameTime()` |
| frameSkip | `` | `void` | `obj:frameSkip()` |
| getCurrentNoiseRange | `` | `number` | `obj:getCurrentNoiseRange()` |
| isDestroyed | `` | `boolean` | `obj:isDestroyed()` |
| _NV_isDestroyed | `` | `boolean` | `obj:_NV_isDestroyed()` |
| isLawEnforcement | `` | `boolean` | `obj:isLawEnforcement()` |
| canAssignBounties | `` | `boolean` | `obj:canAssignBounties()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| isDiplomaticStatus | `factorInBiome: boolean` | `boolean` | `obj:isDiplomaticStatus(factorInBiome)` |
| isLeadingAWarCampaign | `` | `boolean` | `obj:isLeadingAWarCampaign()` |
| isInAWarCampaign | `` | `lightuserdata` | `obj:isInAWarCampaign()` |
| wantsToTriggerCampaigns | `` | `boolean` | `obj:wantsToTriggerCampaigns()` |
| isUnique | `` | `boolean` | `obj:isUnique()` |
| canSpeakNormally | `` | `boolean` | `obj:canSpeakNormally()` |
| isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| _NV_isAnimal | `` | `CharacterAnimal` | `obj:_NV_isAnimal()` |
| isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| _NV_isHuman | `` | `CharacterHuman` | `obj:_NV_isHuman()` |
| takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| setSquadMemberType | `memType: integer` | `void` | `obj:setSquadMemberType(memType)` |
| isResident | `` | `TownBase` | `obj:isResident()` |
| dailyUpdate | `` | `void` | `obj:dailyUpdate()` |
| updateOnScreenCheck | `` | `boolean` | `obj:updateOnScreenCheck()` |
| offscreenUpdate | `` | `void` | `obj:offscreenUpdate()` |
| updateTimes | `` | `void` | `obj:updateTimes()` |
| getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| _NV_getSensoryData | `` | `SensoryData` | `obj:_NV_getSensoryData()` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| getFormation | `` | `lightuserdata` | `obj:getFormation()` |
| _NV_getFormation | `` | `lightuserdata` | `obj:_NV_getFormation()` |
| getEnemyFormation | `` | `lightuserdata` | `obj:getEnemyFormation()` |
| _NV_getEnemyFormation | `` | `lightuserdata` | `obj:_NV_getEnemyFormation()` |
| AIDestinationIndoorOutdoorCheck | `` | `boolean` | `obj:AIDestinationIndoorOutdoorCheck()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| postUpdate | `` | `void` | `obj:postUpdate()` |
| _NV_postUpdate | `` | `void` | `obj:_NV_postUpdate()` |
| ragdollUpdatesUT | `` | `void` | `obj:ragdollUpdatesUT()` |
| fourFrameUpdate | `` | `void` | `obj:fourFrameUpdate()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| pausedUpdate | `` | `void` | `obj:pausedUpdate()` |
| _NV_pausedUpdate | `` | `void` | `obj:_NV_pausedUpdate()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| threadedUpdate4 | `` | `void` | `obj:threadedUpdate4()` |
| _NV_threadedUpdate4 | `` | `void` | `obj:_NV_threadedUpdate4()` |
| threadedUpdatePeriodic | `` | `void` | `obj:threadedUpdatePeriodic()` |
| _NV_threadedUpdatePeriodic | `` | `void` | `obj:_NV_threadedUpdatePeriodic()` |
| pathExists | `v: Vector3` | `boolean` | `obj:pathExists(v)` |
| weatherUpdate | `_a1: number` | `void` | `obj:weatherUpdate(_a1)` |
| _NV_weatherUpdate | `_a1: number` | `void` | `obj:_NV_weatherUpdate(_a1)` |
| stealthUpdate | `_time: number` | `void` | `obj:stealthUpdate(_time)` |
| lineOfSightCheck | `` | `number` | `obj:lineOfSightCheck()` |
| getPerceptionMult | `` | `number` | `obj:getPerceptionMult()` |
| isWithThePlayer | `` | `boolean` | `obj:isWithThePlayer()` |
| notifyICanSeeYouSneaking | `maybeProgress01: number` | `void` | `obj:notifyICanSeeYouSneaking(maybeProgress01)` |
| isItSafeToGetUp | `` | `boolean` | `obj:isItSafeToGetUp()` |
| separateIntoMyOwnSquad | `permanent: boolean` | `Platoon` | `obj:separateIntoMyOwnSquad(permanent)` |
| dropGearOnDeath | `vampiricDeath: boolean` | `void` | `obj:dropGearOnDeath(vampiricDeath)` |
| isItOkForMeToLoot | `` | `boolean` | `obj:isItOkForMeToLoot()` |
| _NV_isItOkForMeToLoot | `` | `boolean` | `obj:_NV_isItOkForMeToLoot()` |
| ImStealingDoYouNotice | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| _NV_ImStealingDoYouNotice | `` | `boolean` | `obj:_NV_ImStealingDoYouNotice()` |
| getFencingSuccessChance | `` | `number` | `obj:getFencingSuccessChance()` |
| stolenGoodsDetectionCheck | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| _NV_stolenGoodsDetectionCheck | `` | `boolean` | `obj:_NV_stolenGoodsDetectionCheck()` |
| sellingUniformDetectionCheck | `` | `boolean` | `obj:sellingUniformDetectionCheck()` |
| _NV_sellingUniformDetectionCheck | `` | `boolean` | `obj:_NV_sellingUniformDetectionCheck()` |
| smugglingTradeCheck | `` | `YesNoMaybe` | `obj:smugglingTradeCheck()` |
| _NV_smugglingTradeCheck | `` | `YesNoMaybe` | `obj:_NV_smugglingTradeCheck()` |
| getStealingSuccessChance | `` | `number` | `obj:getStealingSuccessChance()` |
| getCurrentWeatherAffectStatus | `` | `integer` | `obj:getCurrentWeatherAffectStatus()` |
| getCurrentWeatherAffectStrength | `` | `number` | `obj:getCurrentWeatherAffectStrength()` |
| getWaterLevel | `` | `integer` | `obj:getWaterLevel()` |
| setTerrainHeightPosition | `height: number` | `void` | `obj:setTerrainHeightPosition(height)` |
| getTerrainHeightPosition | `` | `number` | `obj:getTerrainHeightPosition()` |
| setDisguiseMessage | `msg: integer` | `void` | `obj:setDisguiseMessage(msg)` |
| uniqueStateUpdate | `` | `void` | `obj:uniqueStateUpdate()` |
| foodUpdate | `` | `void` | `obj:foodUpdate()` |
| _NV_foodUpdate | `` | `void` | `obj:_NV_foodUpdate()` |
| eatItem | `` | `boolean` | `obj:eatItem()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| loadFromSerialisePostCreationStage | `` | `void` | `obj:loadFromSerialisePostCreationStage()` |
| _NV_loadFromSerialisePostCreationStage | `` | `void` | `obj:_NV_loadFromSerialisePostCreationStage()` |
| setupInventorySections | `` | `boolean` | `obj:setupInventorySections()` |
| _NV_setupInventorySections | `` | `boolean` | `obj:_NV_setupInventorySections()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| _getRawPosition | `` | `Vector3` | `obj:_getRawPosition()` |
| getRawEntityPosition | `` | `Vector3` | `obj:getRawEntityPosition()` |
| getMovementSpeed | `` | `number` | `obj:getMovementSpeed()` |
| _NV_getMovementSpeed | `` | `number` | `obj:_NV_getMovementSpeed()` |
| getMovementSpeedOrders | `` | `integer` | `obj:getMovementSpeedOrders()` |
| _NV_getMovementSpeedOrders | `` | `integer` | `obj:_NV_getMovementSpeedOrders()` |
| getMovementDirection | `` | `Vector3` | `obj:getMovementDirection()` |
| _NV_getMovementDirection | `` | `Vector3` | `obj:_NV_getMovementDirection()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| setInsideTownWalls | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| _NV_setInsideTownWalls | `s: integer` | `void` | `obj:_NV_setInsideTownWalls(s)` |
| sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| select | `` | `void` | `obj:select()` |
| _NV_select | `` | `void` | `obj:_NV_select()` |
| unselect | `` | `void` | `obj:unselect()` |
| _NV_unselect | `` | `void` | `obj:_NV_unselect()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| say_WithARepeatLimiter | `s: string` | `void` | `obj:say_WithARepeatLimiter(s)` |
| _NV_say_WithARepeatLimiter | `s: string` | `void` | `obj:_NV_say_WithARepeatLimiter(s)` |
| say | `s: string` | `void` | `obj:say(s)` |
| _NV_say | `s: string` | `void` | `obj:_NV_say(s)` |
| isInventoryVisible | `` | `boolean` | `obj:isInventoryVisible()` |
| _NV_isInventoryVisible | `` | `boolean` | `obj:_NV_isInventoryVisible()` |
| giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| _NV_giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_giveItem(dropOnFail, destroyOnFail)` |
| hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| hasItem | `` | `boolean` | `obj:hasItem()` |
| _NV_hasItem | `` | `boolean` | `obj:_NV_hasItem()` |
| hasAmmoFor | `` | `boolean` | `obj:hasAmmoFor()` |
| _NV_hasAmmoFor | `` | `boolean` | `obj:_NV_hasAmmoFor()` |
| getNumFoodItems | `` | `integer` | `obj:getNumFoodItems()` |
| _NV_getNumFoodItems | `` | `integer` | `obj:_NV_getNumFoodItems()` |
| hasSimilarItem | `ty: integer` | `boolean` | `obj:hasSimilarItem(ty)` |
| _NV_hasSimilarItem | `ty: integer` | `boolean` | `obj:_NV_hasSimilarItem(ty)` |
| ifImASmithShouldIDitchMyBackWeapon | `` | `boolean` | `obj:ifImASmithShouldIDitchMyBackWeapon()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| hasABackpackOn | `` | `ContainerItem` | `obj:hasABackpackOn()` |
| isATrader | `` | `boolean` | `obj:isATrader()` |
| isFemale | `` | `boolean` | `obj:isFemale()` |
| isFleeing | `` | `boolean` | `obj:isFleeing()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| getStealthKOChance | `factors: boolean` | `number` | `obj:getStealthKOChance(factors)` |
| getKidnappingChance | `` | `number` | `obj:getKidnappingChance()` |
| getKidnappingEscapeChance_skill | `` | `number` | `obj:getKidnappingEscapeChance_skill()` |
| getKidnappingEscapeChance_strength | `` | `number` | `obj:getKidnappingEscapeChance_strength()` |
| shouldIHelpThisGuy | `` | `boolean` | `obj:shouldIHelpThisGuy()` |
| shouldIScrewThisGuyOver | `` | `boolean` | `obj:shouldIScrewThisGuyOver()` |
| ILoveThisGuyBecauseOfStuffThatHappened | `` | `boolean` | `obj:ILoveThisGuyBecauseOfStuffThatHappened()` |
| IHateThisGuyBecauseOfStuffThatHappened | `` | `boolean` | `obj:IHateThisGuyBecauseOfStuffThatHappened()` |
| getRoughLevel | `` | `integer` | `obj:getRoughLevel()` |
| setStandingOrder | `orderID: integer, on: boolean` | `void` | `obj:setStandingOrder(orderID, on)` |
| _NV_setStandingOrder | `orderID: integer, on: boolean` | `void` | `obj:_NV_setStandingOrder(orderID, on)` |
| getStandingOrder | `orderID: integer` | `boolean` | `obj:getStandingOrder(orderID)` |
| setStealthMode | `on: boolean` | `void` | `obj:setStealthMode(on)` |
| isStealthMode | `` | `boolean` | `obj:isStealthMode()` |
| isStealthModeOrCrawling | `` | `boolean` | `obj:isStealthModeOrCrawling()` |
| declareDead | `` | `void` | `obj:declareDead()` |
| updateGUIStatsDetails | `name: string, statId: integer` | `void` | `obj:updateGUIStatsDetails(name, statId)` |
| _printRaceXPBonusLine | `s: integer` | `void` | `obj:_printRaceXPBonusLine(s)` |
| addGoal | `t: integer` | `void` | `obj:addGoal(t)` |
| addJob | `t: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addJob(t, shift, addDontClear, location)` |
| removeJob | `t: integer` | `void` | `obj:removeJob(t)` |
| removePermajob | `t: integer` | `void` | `obj:removePermajob(t)` |
| clearPermajobs | `` | `void` | `obj:clearPermajobs()` |
| movePermajob | `taskIdx: integer, targetIdx: integer` | `void` | `obj:movePermajob(taskIdx, targetIdx)` |
| getPermajob | `slot: integer` | `integer` | `obj:getPermajob(slot)` |
| getPermajobData | `slot: integer` | `Tasker` | `obj:getPermajobData(slot)` |
| getPermajobCount | `` | `integer` | `obj:getPermajobCount()` |
| addOrder | `t: integer, shift: boolean, clear: boolean, location: Vector3` | `void` | `obj:addOrder(t, shift, clear, location)` |
| updateLastTask | `t: integer, location: Vector3` | `void` | `obj:updateLastTask(t, location)` |
| _NV_updateLastTask | `t: integer, location: Vector3` | `void` | `obj:_NV_updateLastTask(t, location)` |
| playerMoveOrderDefault | `location: Vector3` | `void` | `obj:playerMoveOrderDefault(location)` |
| _NV_playerMoveOrderDefault | `location: Vector3` | `void` | `obj:_NV_playerMoveOrderDefault(location)` |
| endCombatMode | `` | `void` | `obj:endCombatMode()` |
| getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _NV_getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:_NV_getTotalRelativeStrengthOfAttackers()` |
| canGoIndoors | `` | `boolean` | `obj:canGoIndoors()` |
| _NV_canGoIndoors | `` | `boolean` | `obj:_NV_canGoIndoors()` |
| isIndoorsRagdoll | `` | `boolean` | `obj:isIndoorsRagdoll()` |
| _NV_isIndoorsRagdoll | `` | `boolean` | `obj:_NV_isIndoorsRagdoll()` |
| destinationIndoors | `` | `void` | `obj:destinationIndoors()` |
| destinationInsideWalls | `` | `integer` | `obj:destinationInsideWalls()` |
| getIntendedAggression | `` | `number` | `obj:getIntendedAggression()` |
| _NV_getIntendedAggression | `` | `number` | `obj:_NV_getIntendedAggression()` |
| getPositionBip01 | `` | `Vector3` | `obj:getPositionBip01()` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| _NV_setName | `name: string` | `void` | `obj:_NV_setName(name)` |
| setNameTagVisible | `value: boolean` | `void` | `obj:setNameTagVisible(value)` |
| ragdollMode | `on: boolean, part: integer` | `void` | `obj:ragdollMode(on, part)` |
| isRagdoll | `` | `boolean` | `obj:isRagdoll()` |
| isDown | `` | `boolean` | `obj:isDown()` |
| getRagdollPhysicsRootPos | `` | `Vector3` | `obj:getRagdollPhysicsRootPos()` |
| amSomeoneWhoNeedsToEatToLive | `` | `boolean` | `obj:amSomeoneWhoNeedsToEatToLive()` |
| _NV_amSomeoneWhoNeedsToEatToLive | `` | `boolean` | `obj:_NV_amSomeoneWhoNeedsToEatToLive()` |
| getMagicHungerSetting | `` | `number` | `obj:getMagicHungerSetting()` |
| _NV_getMagicHungerSetting | `` | `number` | `obj:_NV_getMagicHungerSetting()` |
| wantsToEatNow | `` | `boolean` | `obj:wantsToEatNow()` |
| isKidnapped | `` | `boolean` | `obj:isKidnapped()` |
| _NV_isKidnapped | `` | `boolean` | `obj:_NV_isKidnapped()` |
| isLiterallyUnconciousNotPretending | `` | `boolean` | `obj:isLiterallyUnconciousNotPretending()` |
| _NV_isLiterallyUnconciousNotPretending | `` | `boolean` | `obj:_NV_isLiterallyUnconciousNotPretending()` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| isCrippled | `` | `boolean` | `obj:isCrippled()` |
| _NV_isCrippled | `` | `boolean` | `obj:_NV_isCrippled()` |
| getProneState | `` | `integer` | `obj:getProneState()` |
| _NV_getProneState | `` | `integer` | `obj:_NV_getProneState()` |
| setProneState | `p: integer` | `void` | `obj:setProneState(p)` |
| _NV_setProneState | `p: integer` | `void` | `obj:_NV_setProneState(p)` |
| _killRagdoll | `doItNow: boolean` | `void` | `obj:_killRagdoll(doItNow)` |
| giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:giveBirth(position, rotation)` |
| _NV_giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:_NV_giveBirth(position, rotation)` |
| setupAI | `` | `void` | `obj:setupAI()` |
| clearAllAIGoals | `` | `void` | `obj:clearAllAIGoals()` |
| setupPlatoonAI | `` | `void` | `obj:setupPlatoonAI()` |
| setAppearanceData | `` | `void` | `obj:setAppearanceData()` |
| getAppearanceData | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| setDestination | `pos: Vector3, shift: boolean` | `void` | `obj:setDestination(pos, shift)` |
| sendDialogEventOverride | `what: integer, forceRepeat: boolean` | `boolean` | `obj:sendDialogEventOverride(what, forceRepeat)` |
| sendDialogEvent | `what: integer` | `boolean` | `obj:sendDialogEvent(what)` |
| sayALine | `line: string, force: boolean` | `void` | `obj:sayALine(line, force)` |
| hasDialogue | `` | `boolean` | `obj:hasDialogue()` |
| willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| relocationTeleport | `moveBy: Vector3` | `void` | `obj:relocationTeleport(moveBy)` |
| teleportVisuallyOnly | `to: Vector3, rot: Quaternion` | `void` | `obj:teleportVisuallyOnly(to, rot)` |
| teleportFromAnimation | `` | `void` | `obj:teleportFromAnimation()` |
| attackTarget | `` | `void` | `obj:attackTarget()` |
| notifyTheCampaignOfAnAttack | `` | `void` | `obj:notifyTheCampaignOfAnAttack()` |
| iShouldntAggravateThisTarget | `` | `boolean` | `obj:iShouldntAggravateThisTarget()` |
| sendMessage | `message: integer` | `void` | `obj:sendMessage(message)` |
| attackingYou | `so: boolean, doAwarenessCheck: boolean` | `void` | `obj:attackingYou(so, doAwarenessCheck)` |
| gettingEaten | `amount: number` | `boolean` | `obj:gettingEaten(amount)` |
| _NV_gettingEaten | `amount: number` | `boolean` | `obj:_NV_gettingEaten(amount)` |
| getAttackOriginationDirection | `` | `integer` | `obj:getAttackOriginationDirection()` |
| stumbleState | `` | `boolean` | `obj:stumbleState()` |
| setAge | `f: number` | `void` | `obj:setAge(f)` |
| _NV_setAge | `f: number` | `void` | `obj:_NV_setAge(f)` |
| setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| getAge | `` | `number` | `obj:getAge()` |
| _NV_getAge | `` | `number` | `obj:_NV_getAge()` |
| getAge0to1 | `` | `number` | `obj:getAge0to1()` |
| _NV_getAge0to1 | `` | `number` | `obj:_NV_getAge0to1()` |
| getAgeString | `` | `string` | `obj:getAgeString()` |
| _NV_getAgeString | `` | `string` | `obj:_NV_getAgeString()` |
| getAgeInverse | `` | `number` | `obj:getAgeInverse()` |
| _NV_getAgeInverse | `` | `number` | `obj:_NV_getAgeInverse()` |
| reThinkCurrentAIAction | `` | `void` | `obj:reThinkCurrentAIAction()` |
| getBody | `` | `CharBody` | `obj:getBody()` |
| getCombatClass | `` | `CombatClass` | `obj:getCombatClass()` |
| getStats | `` | `CharStats` | `obj:getStats()` |
| getMedical | `` | `MedicalSystem` | `obj:getMedical()` |
| getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| getAI | `` | `lightuserdata` | `obj:getAI()` |
| getAttackTarget | `` | `void` | `obj:getAttackTarget()` |
| isInCombatMode | `melee: boolean, ranged: boolean` | `boolean` | `obj:isInCombatMode(melee, ranged)` |
| isInRangedCombatMode | `` | `boolean` | `obj:isInRangedCombatMode()` |
| isLiterallyUnderMeleeAttackRightNowForSure | `` | `boolean` | `obj:isLiterallyUnderMeleeAttackRightNowForSure()` |
| _isLiterallyUnderMeleeAttackRightNowForSure_update | `` | `void` | `obj:_isLiterallyUnderMeleeAttackRightNowForSure_update()` |
| conglomerateTagsFor | `` | `integer` | `obj:conglomerateTagsFor()` |
| isPrisonerFreeToGo | `` | `boolean` | `obj:isPrisonerFreeToGo()` |
| clearTempEnemyStatus | `` | `void` | `obj:clearTempEnemyStatus()` |
| clearAllTempEnemyStatuses | `tag: integer` | `void` | `obj:clearAllTempEnemyStatuses(tag)` |
| lastSeenInHoursAgo | `` | `number` | `obj:lastSeenInHoursAgo()` |
| haveMetBefore | `` | `boolean` | `obj:haveMetBefore()` |
| getIDForMemoryTagging | `` | `void` | `obj:getIDForMemoryTagging()` |
| getMovement | `` | `CharMovement` | `obj:getMovement()` |
| lookatPosition | `v: Vector3, fullbodyFacing: boolean` | `void` | `obj:lookatPosition(v, fullbodyFacing)` |
| _NV_lookatPosition | `v: Vector3, fullbodyFacing: boolean` | `void` | `obj:_NV_lookatPosition(v, fullbodyFacing)` |
| areYouGonnaGetMe | `` | `boolean` | `obj:areYouGonnaGetMe()` |
| getAllAttackersCount | `` | `integer` | `obj:getAllAttackersCount()` |
| getRace | `` | `RaceData` | `obj:getRace()` |
| _NV_getRace | `` | `RaceData` | `obj:_NV_getRace()` |
| setRace | `` | `void` | `obj:setRace()` |
| _NV_setRace | `` | `void` | `obj:_NV_setRace()` |
| getRadius | `` | `number` | `obj:getRadius()` |
| isPlayerCharacter | `` | `boolean` | `obj:isPlayerCharacter()` |
| checkPlayerOrderForProblems | `t: integer` | `boolean` | `obj:checkPlayerOrderForProblems(t)` |
| getTotalCarryWeight | `` | `number` | `obj:getTotalCarryWeight()` |
| getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| _NV_getRangedWeapon | `` | `Crossbow` | `obj:_NV_getRangedWeapon()` |
| drawWeapon | `_a2: string` | `boolean` | `obj:drawWeapon(_a2)` |
| getUpperBodyArmour | `` | `Item` | `obj:getUpperBodyArmour()` |
| getLowerBodyArmour | `` | `Item` | `obj:getLowerBodyArmour()` |
| isInjured | `robot: boolean` | `boolean` | `obj:isInjured(robot)` |
| shouldUseRangedWeapons | `` | `boolean` | `obj:shouldUseRangedWeapons()` |
| getBoneWorldPosition | `name: string` | `Vector3` | `obj:getBoneWorldPosition(name)` |
| getAppearance | `` | `AppearanceBase` | `obj:getAppearance()` |
| _setPlatoon | `idnum: integer` | `void` | `obj:_setPlatoon(idnum)` |
| getPlatoon | `` | `ActivePlatoon` | `obj:getPlatoon()` |
| hasPlatoon | `` | `boolean` | `obj:hasPlatoon()` |
| isInAPersistentPlatoon | `` | `boolean` | `obj:isInAPersistentPlatoon()` |
| getBlackboard | `` | `lightuserdata` | `obj:getBlackboard()` |
| getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getOrdersReciever | `` | `lightuserdata` | `obj:getOrdersReciever()` |
| preventRagdollMode | `` | `boolean` | `obj:preventRagdollMode()` |
| setPrisonMode | `on: boolean` | `void` | `obj:setPrisonMode(on)` |
| setBedMode | `on: boolean` | `void` | `obj:setBedMode(on)` |
| setSlaveAIJob | `on: boolean` | `void` | `obj:setSlaveAIJob(on)` |
| isChainedMode | `` | `boolean` | `obj:isChainedMode()` |
| getChainedModeShackles | `` | `LockedArmour` | `obj:getChainedModeShackles()` |
| getMySlaveOwner | `` | `void` | `obj:getMySlaveOwner()` |
| isSlave | `` | `integer` | `obj:isSlave()` |
| isMySlave | `` | `boolean` | `obj:isMySlave()` |
| isMyFactionsSlave | `` | `boolean` | `obj:isMyFactionsSlave()` |
| isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| _NV_isHeadShaven | `` | `boolean` | `obj:_NV_isHeadShaven()` |
| runSlaveAnim | `anim: string, speed: number, sync: number` | `void` | `obj:runSlaveAnim(anim, speed, sync)` |
| endSlaveAnim | `anim: string` | `void` | `obj:endSlaveAnim(anim)` |
| updatePortraitGUIState | `` | `void` | `obj:updatePortraitGUIState()` |
| pickupObject | `` | `void` | `obj:pickupObject()` |
| getPickedUp | `` | `void` | `obj:getPickedUp()` |
| slaveAttachToBoneMode | `bone: string` | `void` | `obj:slaveAttachToBoneMode(bone)` |
| isDead | `` | `boolean` | `obj:isDead()` |
| isBeingCarried | `` | `boolean` | `obj:isBeingCarried()` |
| getCarryingObject | `` | `void` | `obj:getCarryingObject()` |
| chooseCarryObjectLeftOrRight | `` | `void` | `obj:chooseCarryObjectLeftOrRight()` |
| dropCarriedObject | `ragdollHim: boolean, removeOnly: boolean` | `void` | `obj:dropCarriedObject(ragdollHim, removeOnly)` |
| getDropped | `ragdollHim: boolean, hull: boolean` | `void` | `obj:getDropped(ragdollHim, hull)` |
| getDiplomacyMultiplier | `` | `number` | `obj:getDiplomacyMultiplier()` |
| isEnemy | `factorInDisguises: boolean` | `boolean` | `obj:isEnemy(factorInDisguises)` |
| _NV_isEnemy | `factorInDisguises: boolean` | `boolean` | `obj:_NV_isEnemy(factorInDisguises)` |
| isAlly | `factorInDisguises: boolean` | `boolean` | `obj:isAlly(factorInDisguises)` |
| _NV_isAlly | `factorInDisguises: boolean` | `boolean` | `obj:_NV_isAlly(factorInDisguises)` |
| getDefaultTaskRepertoireEnum | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| _NV_getDefaultTaskRepertoireEnum | `` | `integer` | `obj:_NV_getDefaultTaskRepertoireEnum()` |
| getAnimationClass | `` | `lightuserdata` | `obj:getAnimationClass()` |
| getPredictedPosition | `secondsInFuture: number` | `Vector3` | `obj:getPredictedPosition(secondsInFuture)` |
| carryModeT | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:carryModeT(on, makeRagdoll, makeHull)` |
| _carryMode | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:_carryMode(on, makeRagdoll, makeHull)` |
| recalculateTotalEquipmentSkillBonus | `` | `void` | `obj:recalculateTotalEquipmentSkillBonus()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| audioEvent | `name: string, range: integer` | `boolean` | `obj:audioEvent(name, range)` |
| setGroundType | `t: integer` | `void` | `obj:setGroundType(t)` |
| getGroundType | `` | `integer` | `obj:getGroundType()` |
| calculateMainArmourType | `` | `void` | `obj:calculateMainArmourType()` |
| getMainArmourType | `` | `integer` | `obj:getMainArmourType()` |
| wearingUniformOf | `` | `boolean` | `obj:wearingUniformOf()` |
| _NV_wearingUniformOf | `` | `boolean` | `obj:_NV_wearingUniformOf()` |
| getUniformColorScheme | `` | `GameData` | `obj:getUniformColorScheme()` |
| canTakePlayerOrdersAtThisTime | `` | `boolean` | `obj:canTakePlayerOrdersAtThisTime()` |
| startEffect | `` | `boolean` | `obj:startEffect()` |
| stopEffect | `` | `boolean` | `obj:stopEffect()` |
| stopAllEffects | `` | `void` | `obj:stopAllEffects()` |
| notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| equipItem | `sectionName: string` | `void` | `obj:equipItem(sectionName)` |
| _NV_equipItem | `sectionName: string` | `void` | `obj:_NV_equipItem(sectionName)` |
| unequipItem | `sectionName: string` | `void` | `obj:unequipItem(sectionName)` |
| _NV_unequipItem | `sectionName: string` | `void` | `obj:_NV_unequipItem(sectionName)` |
| validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| _NV_validateInventorySections | `` | `void` | `obj:_NV_validateInventorySections()` |
| processCharacterLoadTimeMessages | `` | `void` | `obj:processCharacterLoadTimeMessages()` |
| wantsPathfinderActive | `` | `boolean` | `obj:wantsPathfinderActive()` |
| createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| calculateDestinationState | `v: Vector3` | `void` | `obj:calculateDestinationState(v)` |
| generateWeapon | `` | `Item` | `obj:generateWeapon()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| createComponents | `` | `boolean` | `obj:createComponents()` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| updateStateBroadcast | `time: number` | `void` | `obj:updateStateBroadcast(time)` |
| setEffectBT | `active: boolean` | `void` | `obj:setEffectBT(active)` |
| postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| _NV_postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:_NV_postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| _NV_reCalculateNaturalWeapon | `` | `void` | `obj:_NV_reCalculateNaturalWeapon()` |
| rememberCharacter | `str: string, arg3: boolean` | `void` | `obj:rememberCharacter(str, arg3)` |
| setHandle | `` | `void` | `obj:setHandle()` |
| _NV_setHandle | `` | `void` | `obj:_NV_setHandle()` |
| isIndoors | `` | `void` | `obj:isIndoors()` |
| _NV_isIndoors | `` | `void` | `obj:_NV_isIndoors()` |
| isStandingOnBuilding | `` | `void` | `obj:isStandingOnBuilding()` |
| _NV_isStandingOnBuilding | `` | `void` | `obj:_NV_isStandingOnBuilding()` |
| notifyIndoors | `` | `void` | `obj:notifyIndoors()` |
| _NV_notifyIndoors | `` | `void` | `obj:_NV_notifyIndoors()` |
| setDestinationIndoors | `` | `void` | `obj:setDestinationIndoors()` |
| getAudioObject | `` | `integer` | `obj:getAudioObject()` |
| getName | `` | `string` | `obj:getName()` |
| _NV_getName | `` | `string` | `obj:_NV_getName()` |
| changeSlaveOwner | `` | `void` | `obj:changeSlaveOwner()` |
| teleport | `moveBy: Vector3, rot: Quaternion` | `void` | `obj:teleport(moveBy, rot)` |
| audioValue | `name: string, value: string` | `void` | `obj:audioValue(name, value)` |
| getPermajobName | `slot: integer` | `string` | `obj:getPermajobName(slot)` |
| getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| _NV_getAABB | `` | `lightuserdata` | `obj:_NV_getAABB()` |
| getAllAttackers | `` | `void` | `obj:getAllAttackers()` |
| getCharacterMemoryTag | `mem: integer, isLongTerm: boolean` | `boolean` | `obj:getCharacterMemoryTag(mem, isLongTerm)` |
| hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| convertCutDirection | `cut: integer, from: integer` | `integer` | `obj:convertCutDirection(cut, from)` |
| breakFollowOrderLoop | `` | `boolean` | `obj:breakFollowOrderLoop()` |
| _CONSTRUCTOR | `` | `Character` | `obj:_CONSTRUCTOR()` |
| formationUpdateCallback | `pos: Vector3, heading: Vector3, from: userdata` | `void` | `obj:formationUpdateCallback(pos, heading, from)` |
| serialise | `offset: userdata` | `void` | `obj:serialise(offset)` |
| _NV_serialise | `offset: userdata` | `void` | `obj:_NV_serialise(offset)` |
| hasItemsFrom | `` | `boolean` | `obj:hasItemsFrom()` |
| _NV_hasItemsFrom | `` | `boolean` | `obj:_NV_hasItemsFrom()` |
| getLockpickChance | `victim: userdata` | `number` | `obj:getLockpickChance(victim)` |
| debugIndicateCharacters | `` | `void` | `obj:debugIndicateCharacters()` |
| iShotYou | `poon: userdata, onPurpose: boolean` | `boolean` | `obj:iShotYou(poon, onPurpose)` |
| _startStumble | `dir: integer` | `void` | `obj:_startStumble(dir)` |
| getSquadMissionTarget | `` | `void` | `obj:getSquadMissionTarget()` |
| setChainedMode | `on: boolean` | `void` | `obj:setChainedMode(on)` |
| _ragdollMode | `on: boolean, part: integer` | `boolean` | `obj:_ragdollMode(on, part)` |

## CharacterAnimal
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| weaponIsTechnicallyEquipped | boolean | RW | `obj.weaponIsTechnicallyEquipped = <value>` |
| HPMultiplier | number | RW | `obj.HPMultiplier = <value>` |
| itemInMouthTimeStamp | TimeOfDay | RW | `obj.itemInMouthTimeStamp = <value>` |
| smellThresholdBlood | number | RW | `obj.smellThresholdBlood = <value>` |
| smellThresholdEggs | number | RW | `obj.smellThresholdEggs = <value>` |
| ageSizeMin | number | RW | `obj.ageSizeMin = <value>` |
| ageSizeMax | number | RW | `obj.ageSizeMax = <value>` |
| lifespanInDays | number | RW | `obj.lifespanInDays = <value>` |
| lastUpdatedAge | number | RW | `obj.lastUpdatedAge = <value>` |
| age | number | RW | `obj.age = <value>` |
| weaponInHands | Weapon | RW | `obj.weaponInHands = <value>` |
| audioTimeStamp | number | RW | `obj.audioTimeStamp = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| _NV_isAnimal | `` | `CharacterAnimal` | `obj:_NV_isAnimal()` |
| createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| _NV_createAnimationClass | `` | `void` | `obj:_NV_createAnimationClass()` |
| drawWeapon | `lastSlot: string` | `boolean` | `obj:drawWeapon(lastSlot)` |
| _NV_drawWeapon | `lastSlot: string` | `boolean` | `obj:_NV_drawWeapon(lastSlot)` |
| sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| _NV_getCurrentWeapon | `` | `Weapon` | `obj:_NV_getCurrentWeapon()` |
| getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| _NV_getThePreferredWeapon | `` | `Weapon` | `obj:_NV_getThePreferredWeapon()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:giveBirth(position, rotation)` |
| _NV_giveBirth | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:_NV_giveBirth(position, rotation)` |
| setupInventorySections | `` | `boolean` | `obj:setupInventorySections()` |
| _NV_setupInventorySections | `` | `boolean` | `obj:_NV_setupInventorySections()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| setAge | `zeroToOne: number` | `void` | `obj:setAge(zeroToOne)` |
| _NV_setAge | `zeroToOne: number` | `void` | `obj:_NV_setAge(zeroToOne)` |
| getAge | `` | `number` | `obj:getAge()` |
| _NV_getAge | `` | `number` | `obj:_NV_getAge()` |
| getAgeInverse | `` | `number` | `obj:getAgeInverse()` |
| _NV_getAgeInverse | `` | `number` | `obj:_NV_getAgeInverse()` |
| getAge0to1 | `` | `number` | `obj:getAge0to1()` |
| _NV_getAge0to1 | `` | `number` | `obj:_NV_getAge0to1()` |
| getDefaultTaskRepertoireEnum | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| _NV_getDefaultTaskRepertoireEnum | `` | `integer` | `obj:_NV_getDefaultTaskRepertoireEnum()` |
| canGoIndoors | `` | `boolean` | `obj:canGoIndoors()` |
| _NV_canGoIndoors | `` | `boolean` | `obj:_NV_canGoIndoors()` |
| getSmellHuntingThresholdBlood | `` | `number` | `obj:getSmellHuntingThresholdBlood()` |
| _NV_getSmellHuntingThresholdBlood | `` | `number` | `obj:_NV_getSmellHuntingThresholdBlood()` |
| getSmellHuntingThresholdEggs | `` | `number` | `obj:getSmellHuntingThresholdEggs()` |
| _NV_getSmellHuntingThresholdEggs | `` | `number` | `obj:_NV_getSmellHuntingThresholdEggs()` |
| getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| _NV_getHPMultiplier | `` | `number` | `obj:_NV_getHPMultiplier()` |
| foodUpdate | `` | `void` | `obj:foodUpdate()` |
| _NV_foodUpdate | `` | `void` | `obj:_NV_foodUpdate()` |
| pickupItemInMouth | `` | `boolean` | `obj:pickupItemInMouth()` |
| dropItemInMouth | `` | `boolean` | `obj:dropItemInMouth()` |
| getItemInMouth | `` | `Item` | `obj:getItemInMouth()` |
| eatItemInMouth | `` | `void` | `obj:eatItemInMouth()` |
| _CONSTRUCTOR | `_age: number` | `CharacterAnimal` | `obj:_CONSTRUCTOR(_age)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | `` | `void` | `obj:init()` |
| _NV_init | `` | `void` | `obj:_NV_init()` |
| dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |

## CharacterEditWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterEditWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| camera | lightuserdata | R | `obj.camera` |
| txtName | lightuserdata | R | `obj.txtName` |
| txtGender | lightuserdata | R | `obj.txtGender` |
| txtRace | lightuserdata | R | `obj.txtRace` |
| txtSubRace | lightuserdata | R | `obj.txtSubRace` |
| txtCharIdx | lightuserdata | R | `obj.txtCharIdx` |
| importButton | lightuserdata | R | `obj.importButton` |
| exportButton | lightuserdata | R | `obj.exportButton` |
| panelTabs | lightuserdata | R | `obj.panelTabs` |
| panelTabsView | lightuserdata | R | `obj.panelTabsView` |
| btnPrevGender | lightuserdata | R | `obj.btnPrevGender` |
| btnNextGender | lightuserdata | R | `obj.btnNextGender` |
| btnPrevRace | lightuserdata | R | `obj.btnPrevRace` |
| btnNextRace | lightuserdata | R | `obj.btnNextRace` |
| btnPrevSubRace | lightuserdata | R | `obj.btnPrevSubRace` |
| btnNextSubRace | lightuserdata | R | `obj.btnNextSubRace` |
| btnReset | lightuserdata | R | `obj.btnReset` |
| btnRandomiseAll | lightuserdata | R | `obj.btnRandomiseAll` |
| btnRandomisePart | lightuserdata | R | `obj.btnRandomisePart` |
| descriptionPanel | lightuserdata | R | `obj.descriptionPanel` |
| descriptionPanelText | lightuserdata | R | `obj.descriptionPanelText` |
| statsPanel | lightuserdata | R | `obj.statsPanel` |
| statsDataPanel | DatapanelGUI | RW | `obj.statsDataPanel = <value>` |
| dialog | OpenSaveFileDialog | RW | `obj.dialog = <value>` |
| isMidGame | boolean | RW | `obj.isMidGame = <value>` |
| multipleCharactersChangedCheck | integer | RW | `obj.multipleCharactersChangedCheck = <value>` |
| characterEntityUpdated | boolean | RW | `obj.characterEntityUpdated = <value>` |
| clothVisible | boolean | RW | `obj.clothVisible = <value>` |
| appearanceData | GameDataCopyStandalone | RW | `obj.appearanceData = <value>` |
| raceData | GameData | RW | `obj.raceData = <value>` |
| currentCategory | integer | RW | `obj.currentCategory = <value>` |
| currentRaceGroupIndex | integer | RW | `obj.currentRaceGroupIndex = <value>` |
| currentSubRaceIndex | integer | RW | `obj.currentSubRaceIndex = <value>` |
| currentGender | integer | RW | `obj.currentGender = <value>` |
| currentRaceData | lightuserdata | R | `obj.currentRaceData` |
| currentEditData | lightuserdata | R | `obj.currentEditData` |
| character | Character | RW | `obj.character = <value>` |
| currentCharacterIdx | integer | RW | `obj.currentCharacterIdx = <value>` |
| currentAnimation | lightuserdata | R | `obj.currentAnimation` |
| raceLimits | lightuserdata | R | `obj.raceLimits` |
| showNamesOption | boolean | RW | `obj.showNamesOption = <value>` |
| editorRootNode | lightuserdata | R | `obj.editorRootNode` |
| characterPositionNode | lightuserdata | R | `obj.characterPositionNode` |
| characterRotationNode | lightuserdata | R | `obj.characterRotationNode` |
| workspace | lightuserdata | R | `obj.workspace` |
| platform | lightuserdata | R | `obj.platform` |
| requestUpdateLiveObject | boolean | RW | `obj.requestUpdateLiveObject = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| loadData | `` | `void` | `obj:loadData()` |
| initCharacters | `` | `void` | `obj:initCharacters()` |
| updateRace | `` | `void` | `obj:updateRace()` |
| updateCharacterPoses | `` | `void` | `obj:updateCharacterPoses()` |
| clearCharacterPoses | `` | `void` | `obj:clearCharacterPoses()` |
| updateCharacter | `` | `void` | `obj:updateCharacter()` |
| showCharacter | `on: boolean` | `void` | `obj:showCharacter(on)` |
| updateCurrentCategory | `` | `void` | `obj:updateCurrentCategory()` |
| loadImportedCharacter | `accept: boolean, result: string` | `void` | `obj:loadImportedCharacter(accept, result)` |
| setClothesVisible | `visible: boolean` | `void` | `obj:setClothesVisible(visible)` |
| confirmMessageCallback | `_btn: integer` | `void` | `obj:confirmMessageCallback(_btn)` |
| setupUI | `` | `void` | `obj:setupUI()` |
| setUIEnabled | `enabled: boolean` | `void` | `obj:setUIEnabled(enabled)` |
| refreshUI | `` | `void` | `obj:refreshUI()` |
| updateLiveObject | `` | `void` | `obj:updateLiveObject()` |
| refreshCharacterPoses | `` | `void` | `obj:refreshCharacterPoses()` |
| exportMeshes | `` | `void` | `obj:exportMeshes()` |

## CharacterHuman
**Header:** `extern/KenshiLib/Include/kenshi/CharacterHuman.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| weaponInHands | Weapon | RW | `obj.weaponInHands = <value>` |
| weaponInHandsSheathLocation | string | RW | `obj.weaponInHandsSheathLocation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `CharacterHuman` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| _NV_isHuman | `` | `CharacterHuman` | `obj:_NV_isHuman()` |
| drawWeapon | `lastSection: string` | `boolean` | `obj:drawWeapon(lastSection)` |
| _NV_drawWeapon | `lastSection: string` | `boolean` | `obj:_NV_drawWeapon(lastSection)` |
| sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| _NV_sheatheWeapon | `` | `void` | `obj:_NV_sheatheWeapon()` |
| getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| _NV_getCurrentWeapon | `` | `Weapon` | `obj:_NV_getCurrentWeapon()` |
| getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| _NV_getThePreferredWeapon | `` | `Weapon` | `obj:_NV_getThePreferredWeapon()` |
| getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| _NV_getRangedWeapon | `` | `Crossbow` | `obj:_NV_getRangedWeapon()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| giveBirth | `_pos: Vector3, _rot: Quaternion` | `boolean` | `obj:giveBirth(_pos, _rot)` |
| _NV_giveBirth | `_pos: Vector3, _rot: Quaternion` | `boolean` | `obj:_NV_giveBirth(_pos, _rot)` |
| setupInventorySections | `` | `boolean` | `obj:setupInventorySections()` |
| _NV_setupInventorySections | `` | `boolean` | `obj:_NV_setupInventorySections()` |
| validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| _NV_validateInventorySections | `` | `void` | `obj:_NV_validateInventorySections()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| _NV_setupAudio | `` | `void` | `obj:_NV_setupAudio()` |
| shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| _NV_isHeadShaven | `` | `boolean` | `obj:_NV_isHeadShaven()` |
| createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| _NV_createAnimationClass | `` | `void` | `obj:_NV_createAnimationClass()` |
| dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| dropWeaponInHands | `` | `void` | `obj:dropWeaponInHands()` |
| dropWeaponInHandsFake | `` | `void` | `obj:dropWeaponInHandsFake()` |
| unequipItem | `section: string` | `void` | `obj:unequipItem(section)` |
| _NV_unequipItem | `section: string` | `void` | `obj:_NV_unequipItem(section)` |
| weatherUpdate | `time: number` | `void` | `obj:weatherUpdate(time)` |
| _NV_weatherUpdate | `time: number` | `void` | `obj:_NV_weatherUpdate(time)` |
| leaveSheathEquipped | `section: string, ypos: integer` | `void` | `obj:leaveSheathEquipped(section, ypos)` |
| postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| _NV_postRagdollCallback | `on: boolean, part: integer` | `void` | `obj:_NV_postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| _NV_reCalculateNaturalWeapon | `` | `void` | `obj:_NV_reCalculateNaturalWeapon()` |

## CharacterInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `CharacterInventoryLayout` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CharacterStatsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | Character | R | `obj.character` |
| statsSum | integer | RW | `obj.statsSum = <value>` |
| statProgress | integer | RW | `obj.statProgress = <value>` |
| currentStatIdDescription | string | RW | `obj.currentStatIdDescription = <value>` |
| attributesDatapanel | DatapanelGUI | R | `obj.attributesDatapanel` |
| skills1Datapanel | DatapanelGUI | R | `obj.skills1Datapanel` |
| skills2Datapanel | DatapanelGUI | R | `obj.skills2Datapanel` |
| skills3Datapanel | DatapanelGUI | R | `obj.skills3Datapanel` |
| skills4Datapanel | DatapanelGUI | R | `obj.skills4Datapanel` |
| statsDatapanel | DatapanelGUI | R | `obj.statsDatapanel` |
| description1Datapanel | DatapanelGUI | R | `obj.description1Datapanel` |
| description2Datapanel | DatapanelGUI | R | `obj.description2Datapanel` |
| autoUpdateMode | boolean | RW | `obj.autoUpdateMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| create | `` | `void` | `obj:create()` |
| _NV_create | `` | `void` | `obj:_NV_create()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| setAutoUpdateMode | `on: boolean` | `void` | `obj:setAutoUpdateMode(on)` |
| setupStats | `` | `void` | `obj:setupStats()` |
| updateStats | `` | `void` | `obj:updateStats()` |
| clearDesctiption | `` | `void` | `obj:clearDesctiption()` |
| sumStats | `` | `integer` | `obj:sumStats()` |
| getStatsPanel | `group: integer` | `DatapanelGUI` | `obj:getStatsPanel(group)` |

## CharacterTradingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterTradingWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| tradingHandler | lightuserdata | R | `obj.tradingHandler` |
| charactersBox | lightuserdata | R | `obj.charactersBox` |
| confirmBtn | lightuserdata | R | `obj.confirmBtn` |
| currentTotalText | lightuserdata | R | `obj.currentTotalText` |
| selectedCountText | lightuserdata | R | `obj.selectedCountText` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| update | `` | `void` | `obj:update()` |
| close | `` | `void` | `obj:close()` |

## Character_CarryMsg
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `rag: boolean, hull: boolean` | `Character::CarryMsg` | `obj:_CONSTRUCTOR(rag, hull)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Character_RagdollMsg
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `part: integer` | `Character::RagdollMsg` | `obj:_CONSTRUCTOR(part)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CombatClass
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| attackSlots | CombatClass::AttackSlotManager | RW | `obj.attackSlots = <value>` |
| wantsToBlock | boolean | RW | `obj.wantsToBlock = <value>` |
| isStumbleBlocking | boolean | RW | `obj.isStumbleBlocking = <value>` |
| stumbleTimer | number | RW | `obj.stumbleTimer = <value>` |
| whenCanStopStumble | number | RW | `obj.whenCanStopStumble = <value>` |
| stumbleForce | number | RW | `obj.stumbleForce = <value>` |
| combatModeActive | boolean | RW | `obj.combatModeActive = <value>` |
| lastCombatModeTimeStamp | number | RW | `obj.lastCombatModeTimeStamp = <value>` |
| _isAttacking | number | RW | `obj._isAttacking = <value>` |
| inDeadTime | boolean | RW | `obj.inDeadTime = <value>` |
| deadTimer | number | RW | `obj.deadTimer = <value>` |
| stateTimer | number | RW | `obj.stateTimer = <value>` |
| currentTechnique | CombatTechniqueData | RW | `obj.currentTechnique = <value>` |
| currentTechniqueHasFinished | boolean | RW | `obj.currentTechniqueHasFinished = <value>` |
| attackStartPos | Vector3 | RW | `obj.attackStartPos = <value>` |
| frameTIME | number | RW | `obj.frameTIME = <value>` |
| movement | CharMovement | RW | `obj.movement = <value>` |
| ai | lightuserdata | R | `obj.ai` |
| animation | lightuserdata | R | `obj.animation` |
| me | Character | RW | `obj.me = <value>` |
| stats | CharStats | RW | `obj.stats = <value>` |
| medical | MedicalSystem | RW | `obj.medical = <value>` |
| myRadiusX | number | RW | `obj.myRadiusX = <value>` |
| blockingTarget | Character | RW | `obj.blockingTarget = <value>` |
| blockingTargetH | unknown | RW | `obj.blockingTargetH = <value>` |
| targetsInAttackZone | lektor<hand> | R | `obj.targetsInAttackZone` |
| attackersH | lektor<hand> | RW | `obj.attackersH = <value>` |
| threats | lektor<Character*> | RW | `obj.threats = <value>` |
| threatsH | lektor<hand> | RW | `obj.threatsH = <value>` |
| notifiedThreats | lektor<hand> | RW | `obj.notifiedThreats = <value>` |
| lastIncomingAttackComboSection | integer | RW | `obj.lastIncomingAttackComboSection = <value>` |
| calculatedTargetsInAttackZoneThisFrame | boolean | RW | `obj.calculatedTargetsInAttackZoneThisFrame = <value>` |
| combatState | integer | RW | `obj.combatState = <value>` |
| nextMove | integer | RW | `obj.nextMove = <value>` |
| numEnemiesWaitingForMe1 | integer | RW | `obj.numEnemiesWaitingForMe1 = <value>` |
| numEnemiesWaitingForMe2 | integer | RW | `obj.numEnemiesWaitingForMe2 = <value>` |
| waitCountAlternator | boolean | RW | `obj.waitCountAlternator = <value>` |
| currentComboSection | integer | RW | `obj.currentComboSection = <value>` |
| lastComboSection | integer | RW | `obj.lastComboSection = <value>` |
| lastSoundIndex | integer | RW | `obj.lastSoundIndex = <value>` |
| techniqueIntegrityCheckTimer | number | RW | `obj.techniqueIntegrityCheckTimer = <value>` |
| MEI_MIN | number | RW | `obj.MEI_MIN = <value>` |
| MEI_MAX | number | RW | `obj.MEI_MAX = <value>` |
| MINIMUM_DISTANCE_TO_OTHERS | number | RW | `obj.MINIMUM_DISTANCE_TO_OTHERS = <value>` |
| BLOCKING_MEI_DISTANCE_MIN | number | RW | `obj.BLOCKING_MEI_DISTANCE_MIN = <value>` |
| BLOCKING_MEI_DISTANCE_MAX | number | RW | `obj.BLOCKING_MEI_DISTANCE_MAX = <value>` |
| currentTarget | Character | RW | `obj.currentTarget = <value>` |
| currentTargetHandle | unknown | RW | `obj.currentTargetHandle = <value>` |
| stateMap | SwordStateMapBinding::MapType | RW | `obj.stateMap = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isAI | `` | `boolean` | `obj:isAI()` |
| _NV_isAI | `` | `boolean` | `obj:_NV_isAI()` |
| go | `_frameTime: number` | `void` | `obj:go(_frameTime)` |
| _NV_go | `_frameTime: number` | `void` | `obj:_NV_go(_frameTime)` |
| getCombatState | `` | `integer` | `obj:getCombatState()` |
| getBlockStateEnum | `` | `integer` | `obj:getBlockStateEnum()` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| _NV_periodicUpdate | `time: number` | `void` | `obj:_NV_periodicUpdate(time)` |
| isAttacking | `` | `number` | `obj:isAttacking()` |
| informOfFreeAttackSlot | `` | `void` | `obj:informOfFreeAttackSlot()` |
| _NV_informOfFreeAttackSlot | `` | `void` | `obj:_NV_informOfFreeAttackSlot()` |
| isStationary | `` | `boolean` | `obj:isStationary()` |
| _getAttackTarget | `` | `void` | `obj:_getAttackTarget()` |
| isFightingAnAllyOfMine | `` | `boolean` | `obj:isFightingAnAllyOfMine()` |
| getCurrentTechnique | `` | `CombatTechniqueData` | `obj:getCurrentTechnique()` |
| getCurrentTechniqueSection | `` | `integer` | `obj:getCurrentTechniqueSection()` |
| getMeiMin | `` | `number` | `obj:getMeiMin()` |
| areYouFightingAndInNeedOfHelp | `` | `number` | `obj:areYouFightingAndInNeedOfHelp()` |
| getNumOpponents | `` | `integer` | `obj:getNumOpponents()` |
| getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _isInCombatMode | `` | `boolean` | `obj:_isInCombatMode()` |
| checkForBadHandles | `` | `void` | `obj:checkForBadHandles()` |
| addAttackerH | `` | `boolean` | `obj:addAttackerH()` |
| isInAttackerListH | `` | `boolean` | `obj:isInAttackerListH()` |
| removeAttackerH | `` | `boolean` | `obj:removeAttackerH()` |
| getAttackAimAdjustmentThreshold | `` | `number` | `obj:getAttackAimAdjustmentThreshold()` |
| getNumWaitingAttackers | `` | `integer` | `obj:getNumWaitingAttackers()` |
| readyToFinishCombatMode | `` | `boolean` | `obj:readyToFinishCombatMode()` |
| getTimeSinceLastCombatModeInHours | `` | `number` | `obj:getTimeSinceLastCombatModeInHours()` |
| hasFocusedTarget | `` | `void` | `obj:hasFocusedTarget()` |
| _NV_hasFocusedTarget | `` | `void` | `obj:_NV_hasFocusedTarget()` |
| changeState | `newState: integer, minTime: number` | `void` | `obj:changeState(newState, minTime)` |
| getStateClass | `state: integer` | `lightuserdata` | `obj:getStateClass(state)` |
| _NV_getStateClass | `state: integer` | `lightuserdata` | `obj:_NV_getStateClass(state)` |
| update | `frameTIME: number` | `void` | `obj:update(frameTIME)` |
| _NV_update | `frameTIME: number` | `void` | `obj:_NV_update(frameTIME)` |
| getMeiMax | `` | `number` | `obj:getMeiMax()` |
| startupState | `` | `boolean` | `obj:startupState()` |
| _NV_startupState | `` | `boolean` | `obj:_NV_startupState()` |
| stumbleState | `` | `void` | `obj:stumbleState()` |
| _isAttackingUpdate | `` | `number` | `obj:_isAttackingUpdate()` |
| canBlock | `` | `boolean` | `obj:canBlock()` |
| attackState | `` | `boolean` | `obj:attackState()` |
| _NV_attackState | `` | `boolean` | `obj:_NV_attackState()` |
| checkForNeedBlock | `thresholdMyAttack: number, thresholdIncomingAttack: number` | `boolean` | `obj:checkForNeedBlock(thresholdMyAttack, thresholdIncomingAttack)` |
| setCombatState | `state: integer` | `void` | `obj:setCombatState(state)` |
| initialiseBlock | `isStumbling: boolean` | `boolean` | `obj:initialiseBlock(isStumbling)` |
| blockState | `stumbleBlocking: boolean` | `boolean` | `obj:blockState(stumbleBlocking)` |
| _NV_blockState | `stumbleBlocking: boolean` | `boolean` | `obj:_NV_blockState(stumbleBlocking)` |
| blockWaitingState | `` | `void` | `obj:blockWaitingState()` |
| attackImpactCheck | `` | `void` | `obj:attackImpactCheck()` |
| calculateTargetsInAttackZone | `` | `void` | `obj:calculateTargetsInAttackZone()` |
| isInAttackZone | `` | `boolean` | `obj:isInAttackZone()` |
| getNearestEnemyInAttackZone | `` | `Character` | `obj:getNearestEnemyInAttackZone()` |
| notifyBlockNeeded | `` | `void` | `obj:notifyBlockNeeded()` |
| weaponReach | `` | `number` | `obj:weaponReach()` |
| gotMoreImportantThingsToDoThanFightingYou | `` | `boolean` | `obj:gotMoreImportantThingsToDoThanFightingYou()` |
| _NV_gotMoreImportantThingsToDoThanFightingYou | `` | `boolean` | `obj:_NV_gotMoreImportantThingsToDoThanFightingYou()` |
| setAttackTarget | `` | `void` | `obj:setAttackTarget()` |
| setAttackTargetHandle | `` | `void` | `obj:setAttackTargetHandle()` |
| lookatTarget | `` | `void` | `obj:lookatTarget()` |
| packPtrsToHandles | `` | `void` | `obj:packPtrsToHandles()` |
| _NV_packPtrsToHandles | `` | `void` | `obj:_NV_packPtrsToHandles()` |
| unpackHandlesToPtrs | `` | `void` | `obj:unpackHandlesToPtrs()` |
| _NV_unpackHandlesToPtrs | `` | `void` | `obj:_NV_unpackHandlesToPtrs()` |

## CombatClass_AttackSlotManager_SlotData
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `time: number` | `CombatClass::AttackSlotManager::SlotData` | `obj:_CONSTRUCTOR(time)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CombatClass_EffectData
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `arg3: unknown` | `CombatClass::EffectData` | `obj:_CONSTRUCTOR(arg3)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CombatMovementController
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| movement | CharMovement | RW | `obj.movement = <value>` |
| chaseMode | boolean | RW | `obj.chaseMode = <value>` |
| chaseStateTimer | number | RW | `obj.chaseStateTimer = <value>` |
| hasForcedWP | boolean | RW | `obj.hasForcedWP = <value>` |
| forcedWP | Vector3 | RW | `obj.forcedWP = <value>` |
| flockFilterX | MotionFilter | RW | `obj.flockFilterX = <value>` |
| flockFilterZ | MotionFilter | RW | `obj.flockFilterZ = <value>` |
| flockingControl | FlockingTools | RW | `obj.flockingControl = <value>` |
| stats | CharStats | RW | `obj.stats = <value>` |
| radius | number | RW | `obj.radius = <value>` |
| jogMode | boolean | RW | `obj.jogMode = <value>` |
| TOTALREPULSION_DAMPING | number | RW | `obj.TOTALREPULSION_DAMPING = <value>` |
| STRAFE_STATE_DAMPING | number | RW | `obj.STRAFE_STATE_DAMPING = <value>` |
| STRAFE_THRESHOLD | number | RW | `obj.STRAFE_THRESHOLD = <value>` |
| FORWARD_THRESHOLD | number | RW | `obj.FORWARD_THRESHOLD = <value>` |
| MIN_RANGE_FW | number | RW | `obj.MIN_RANGE_FW = <value>` |
| ENEMY_DIST | number | RW | `obj.ENEMY_DIST = <value>` |
| ALLY_DIST | number | RW | `obj.ALLY_DIST = <value>` |
| STOP_THRESHOLD | number | RW | `obj.STOP_THRESHOLD = <value>` |
| START_THRESHOLD | number | RW | `obj.START_THRESHOLD = <value>` |
| ACCEL_RATE_COMBATMODE | number | RW | `obj.ACCEL_RATE_COMBATMODE = <value>` |
| meiMin | number | RW | `obj.meiMin = <value>` |
| circlingSpeed | number | RW | `obj.circlingSpeed = <value>` |
| combatMinDistance | number | RW | `obj.combatMinDistance = <value>` |
| combatMaxDistance | number | RW | `obj.combatMaxDistance = <value>` |
| strafeStateTimer | number | RW | `obj.strafeStateTimer = <value>` |
| strafing | boolean | RW | `obj.strafing = <value>` |
| powerThrough | boolean | RW | `obj.powerThrough = <value>` |
| canStrafe | boolean | RW | `obj.canStrafe = <value>` |
| speedLimit | number | RW | `obj.speedLimit = <value>` |
| currentAccelSpeed | number | RW | `obj.currentAccelSpeed = <value>` |
| lookAtCharacter | unknown | RW | `obj.lookAtCharacter = <value>` |
| combatTarget | unknown | RW | `obj.combatTarget = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `CombatMovementController` | `obj:_CONSTRUCTOR()` |
| collisionUpdate | `time: number` | `void` | `obj:collisionUpdate(time)` |
| chasingModeCheck | `` | `boolean` | `obj:chasingModeCheck()` |
| create | `strafe: boolean` | `void` | `obj:create(strafe)` |
| areTherePeopleInMyWay | `` | `boolean` | `obj:areTherePeopleInMyWay()` |
| addACharacterObstruction | `` | `void` | `obj:addACharacterObstruction()` |
| setupCombatMovementVariables | `` | `void` | `obj:setupCombatMovementVariables()` |
| combatMovementUpdate | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: integer, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| combatMovementUpdate_crippleMode | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: integer, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate_crippleMode(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| getUrgentVelocities | `pos: Vector3, facingDir: Vector3` | `Vector3` | `obj:getUrgentVelocities(pos, facingDir)` |
| checkWeDontCollideWithCharacters | `pos: Vector3, newpos: Vector3` | `void` | `obj:checkWeDontCollideWithCharacters(pos, newpos)` |
| checkCharacterCollision | `pos: Vector3, movement: Vector3` | `boolean` | `obj:checkCharacterCollision(pos, movement)` |
| setForcedWP | `v: Vector3` | `void` | `obj:setForcedWP(v)` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| disable | `` | `void` | `obj:disable()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CombatTechniqueData
**Header:** `extern/KenshiLib/Include/kenshi/CombatTechniqueData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| animation | string | RW | `obj.animation = <value>` |
| animSpeedMultiplier | number | RW | `obj.animSpeedMultiplier = <value>` |
| isBlock | boolean | RW | `obj.isBlock = <value>` |
| isDodge | boolean | RW | `obj.isDodge = <value>` |
| stumbleDodge | boolean | RW | `obj.stumbleDodge = <value>` |
| gainsGround | boolean | RW | `obj.gainsGround = <value>` |
| isProne | boolean | RW | `obj.isProne = <value>` |
| lowStrike | boolean | RW | `obj.lowStrike = <value>` |
| hesitationPoint | number | RW | `obj.hesitationPoint = <value>` |
| initialDistance | number | RW | `obj.initialDistance = <value>` |
| minDistanceVsStatic | number | RW | `obj.minDistanceVsStatic = <value>` |
| acceptableEndTime01 | number | RW | `obj.acceptableEndTime01 = <value>` |
| minSkill | number | RW | `obj.minSkill = <value>` |
| maxSkill | number | RW | `obj.maxSkill = <value>` |
| maxEncumbrance | number | RW | `obj.maxEncumbrance = <value>` |
| chanceMult | number | RW | `obj.chanceMult = <value>` |
| maxTargetHits | integer | RW | `obj.maxTargetHits = <value>` |
| events | unknown | RW | `obj.events = <value>` |
| skillTypes | unknown | R | `obj.skillTypes` |
| impactPoints | lektor<CombatTechniqueData::ImpactPoint> | R | `obj.impactPoints` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hasSkillType | `type: integer` | `boolean` | `obj:hasSkillType(type)` |
| numImpactPoints | `` | `integer` | `obj:numImpactPoints()` |
| impactPoint | `i: integer` | `lightuserdata` | `obj:impactPoint(i)` |

## ConstructionState
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isComplete | boolean | RW | `obj.isComplete = <value>` |
| isPaused | boolean | RW | `obj.isPaused = <value>` |
| isDismantled | boolean | RW | `obj.isDismantled = <value>` |
| constructionProgress | number | RW | `obj.constructionProgress = <value>` |
| msgDismantleAmount | number | RW | `obj.msgDismantleAmount = <value>` |
| totalMats | number | RW | `obj.totalMats = <value>` |
| buildTimeMult | number | RW | `obj.buildTimeMult = <value>` |
| buildersThisFrame | integer | RW | `obj.buildersThisFrame = <value>` |
| pathThreshold | number | RW | `obj.pathThreshold = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| addMaterials | `` | `void` | `obj:addMaterials()` |
| materialsEmpty | `` | `boolean` | `obj:materialsEmpty()` |
| isOverThreshold | `` | `boolean` | `obj:isOverThreshold()` |
| getHealthBarProgress | `` | `number` | `obj:getHealthBarProgress()` |
| getConstructionMaterialProgress | `` | `number` | `obj:getConstructionMaterialProgress()` |
| getHealthBarActual | `` | `string` | `obj:getHealthBarActual()` |
| getMaterial | `` | `lightuserdata` | `obj:getMaterial()` |
| setup | `` | `void` | `obj:setup()` |
| getTotalMats | `` | `number` | `obj:getTotalMats()` |
| getTotalMatsPresent | `` | `number` | `obj:getTotalMatsPresent()` |
| needsMat | `` | `integer` | `obj:needsMat()` |
| needMats | `` | `boolean` | `obj:needMats()` |

## ConsumptionItem
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| amount | number | RW | `obj.amount = <value>` |
| rate | number | RW | `obj.rate = <value>` |
| maxCapacity | integer | RW | `obj.maxCapacity = <value>` |
| item | GameData | R | `obj.item` |
| inventorySection | InventorySection | R | `obj.inventorySection` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isFull | `` | `boolean` | `obj:isFull()` |
| isEmpty | `` | `boolean` | `obj:isEmpty()` |

## ContainerItem
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| callbackOwner | RootObject | RW | `obj.callbackOwner = <value>` |
| athleticsMult | number | RW | `obj.athleticsMult = <value>` |
| weightMult | number | RW | `obj.weightMult = <value>` |
| combatSpeedMult | number | RW | `obj.combatSpeedMult = <value>` |
| combatSkillBonus | integer | RW | `obj.combatSkillBonus = <value>` |
| stealthMult | number | RW | `obj.stealthMult = <value>` |
| inventory | Inventory | RW | `obj.inventory = <value>` |
| racesExclude | ogre_unordered_set<GameData*>::type | RW | `obj.racesExclude = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| canEquip | `` | `boolean` | `obj:canEquip()` |
| _NV_canEquip | `` | `boolean` | `obj:_NV_canEquip()` |
| equipItem | `what: string` | `void` | `obj:equipItem(what)` |
| _NV_equipItem | `what: string` | `void` | `obj:_NV_equipItem(what)` |
| unequipItem | `what: string` | `void` | `obj:unequipItem(what)` |
| _NV_unequipItem | `what: string` | `void` | `obj:_NV_unequipItem(what)` |
| dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| doubleCheckHandle | `` | `void` | `obj:doubleCheckHandle()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| setProperOwner | `` | `void` | `obj:setProperOwner()` |
| _NV_setProperOwner | `` | `void` | `obj:_NV_setProperOwner()` |
| _CONSTRUCTOR | `` | `ContainerItem` | `obj:_CONSTRUCTOR()` |

## ContextMenu
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| rightMouseActivated | boolean | RW | `obj.rightMouseActivated = <value>` |
| orders | unknown | RW | `obj.orders = <value>` |
| contextMenuName | string | RW | `obj.contextMenuName = <value>` |
| menuGUI | lightuserdata | RW | `obj.menuGUI = <value>` |
| menuGUI2 | lightuserdata | RW | `obj.menuGUI2 = <value>` |
| delayedDestroyFlag | boolean | RW | `obj.delayedDestroyFlag = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ContextMenu` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| showContextMenu | `on: boolean` | `void` | `obj:showContextMenu(on)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| update | `` | `void` | `obj:update()` |
| _destroyMenuGUICheck | `` | `void` | `obj:_destroyMenuGUICheck()` |

## ContextMenuGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ContextMenu.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| contextMenuTarget | unknown | RW | `obj.contextMenuTarget = <value>` |
| name | string | RW | `obj.name = <value>` |
| nameText | lightuserdata | R | `obj.nameText` |
| optionsList | lightuserdata | R | `obj.optionsList` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getMainWidget | `` | `lightuserdata` | `obj:getMainWidget()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |

## CraftingBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| maxCraftLevel | integer | RW | `obj.maxCraftLevel = <value>` |
| crafting | std::deque<CraftingItem, std::allocator<CraftingItem> > | R | `obj.crafting` |
| specialCraftItemType | integer | RW | `obj.specialCraftItemType = <value>` |
| repeat | boolean | RW | `obj.repeat = <value>` |
| whosCrafting | unknown | RW | `obj.whosCrafting = <value>` |
| itemCrafted | boolean | RW | `obj.itemCrafted = <value>` |
| failiureNotified | boolean | RW | `obj.failiureNotified = <value>` |
| biggestCraftableItem | GameData | R | `obj.biggestCraftableItem` |
| outItem | Item | R | `obj.outItem` |
| inItems | Item | R | `obj.inItems` |
| partialItems | unknown | RW | `obj.partialItems = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| givePower | `amount: number` | `void` | `obj:givePower(amount)` |
| _NV_givePower | `amount: number` | `void` | `obj:_NV_givePower(amount)` |
| hasCraftingQueued | `` | `boolean` | `obj:hasCraftingQueued()` |
| _NV_hasCraftingQueued | `` | `boolean` | `obj:_NV_hasCraftingQueued()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| getProductionItemData | `` | `GameData` | `obj:getProductionItemData()` |
| _NV_getProductionItemData | `` | `GameData` | `obj:_NV_getProductionItemData()` |
| getCurrentProductionQuantity | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| _NV_getCurrentProductionQuantity | `` | `integer` | `obj:_NV_getCurrentProductionQuantity()` |
| isAnyInputsInvalidType | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| _NV_isAnyInputsInvalidType | `` | `boolean` | `obj:_NV_isAnyInputsInvalidType()` |
| notifyCraftFailiure | `` | `void` | `obj:notifyCraftFailiure()` |
| _removeCraft | `index: integer` | `void` | `obj:_removeCraft(index)` |
| getCraft | `id: integer` | `lightuserdata` | `obj:getCraft(id)` |
| destroyProductionItem | `` | `void` | `obj:destroyProductionItem()` |
| getCriticalSuccessWeapon | `normalWeaponLevel: integer` | `GameData` | `obj:getCriticalSuccessWeapon(normalWeaponLevel)` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| _NV_updateOutput | `rate: number` | `void` | `obj:_NV_updateOutput(rate)` |
| updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| _NV_updateInventoryWindow | `` | `void` | `obj:_NV_updateInventoryWindow()` |

## CraftingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| queueBtn | lightuserdata | R | `obj.queueBtn` |
| craftingName | lightuserdata | R | `obj.craftingName` |
| outputType | integer | RW | `obj.outputType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `title: string, ins: integer, outs: integer` | `CraftingInventoryLayout` | `obj:_CONSTRUCTOR(title, ins, outs)` |
| refresh | `` | `void` | `obj:refresh()` |
| setOutputType | `type: integer` | `void` | `obj:setOutputType(type)` |
| setCraftingName | `name: string` | `void` | `obj:setCraftingName(name)` |
| getQueueButton | `` | `lightuserdata` | `obj:getQueueButton()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## CreatelistItem
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| container | RootObjectContainer | RW | `obj.container = <value>` |
| homeBuilding | Building | RW | `obj.homeBuilding = <value>` |
| faction | Faction | RW | `obj.faction = <value>` |
| data | GameData | RW | `obj.data = <value>` |
| position | Vector3 | RW | `obj.position = <value>` |
| isFromActiveLevelMod | boolean | RW | `obj.isFromActiveLevelMod = <value>` |
| rotation | Quaternion | RW | `obj.rotation = <value>` |
| callbackObject | FactoryCallbackInterface | RW | `obj.callbackObject = <value>` |
| saveState | GameSaveState | RW | `obj.saveState = <value>` |
| age | number | RW | `obj.age = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_position: Vector3, _isFromActiveLevelMod: boolean, _rotation: Quaternion, _age: number` | `CreatelistItem` | `obj:_CONSTRUCTOR(_position, _isFromActiveLevelMod, _rotation, _age)` |

## Crossbow
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| gunClass | lightuserdata | R | `obj.gunClass` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_overalllevel: integer` | `Crossbow` | `obj:_CONSTRUCTOR(_overalllevel)` |
| isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| _NV_isCrossbow | `` | `Crossbow` | `obj:_NV_isCrossbow()` |
| getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| _NV_getCraftMaterialMult | `` | `number` | `obj:_NV_getCraftMaterialMult()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getRangeInUnits | `` | `number` | `obj:getRangeInUnits()` |
| getEquipPositionOffset | `` | `number` | `obj:getEquipPositionOffset()` |
| destroyItemEntityCallback_Equipping | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| _NV_destroyItemEntityCallback_Equipping | `` | `void` | `obj:_NV_destroyItemEntityCallback_Equipping()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Damages
**Header:** `extern/KenshiLib/Include/kenshi/Damages.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cut | number | RW | `obj.cut = <value>` |
| blunt | number | RW | `obj.blunt = <value>` |
| pierce | number | RW | `obj.pierce = <value>` |
| extraStun | number | RW | `obj.extraStun = <value>` |
| bleedMult | number | RW | `obj.bleedMult = <value>` |
| armourPenetration | number | RW | `obj.armourPenetration = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `blunt: number, pierce: number, bleed: number, armour: number` | `Damages` | `obj:_CONSTRUCTOR(blunt, pierce, bleed, armour)` |
| multiply | `mult: number` | `void` | `obj:multiply(mult)` |
| total | `` | `number` | `obj:total()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isStored | boolean | RW | `obj.isStored = <value>` |
| objectDatas | GameDataContainer | RW | `obj.objectDatas = <value>` |
| datasFile | string | RW | `obj.datasFile = <value>` |
| selfType | integer | RW | `obj.selfType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getType | `` | `integer` | `obj:getType()` |
| setupDataFile | `filename: string` | `void` | `obj:setupDataFile(filename)` |
| destroyObjectDatas | `` | `void` | `obj:destroyObjectDatas()` |

## DataPanelLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| w1 | lightuserdata | R | `obj.w1` |
| w2 | lightuserdata | R | `obj.w2` |
| category | integer | RW | `obj.category = <value>` |
| keyValue | string | RW | `obj.keyValue = <value>` |
| s1 | string | RW | `obj.s1 = <value>` |
| s2 | string | RW | `obj.s2 = <value>` |
| lo | integer | RW | `obj.lo = <value>` |
| hi | integer | RW | `obj.hi = <value>` |
| skinW1 | string | RW | `obj.skinW1 = <value>` |
| skinW2 | string | RW | `obj.skinW2 = <value>` |
| classType | integer | RW | `obj.classType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| setEnabled | `on: boolean` | `void` | `obj:setEnabled(on)` |
| _NV_setEnabled | `on: boolean` | `void` | `obj:_NV_setEnabled(on)` |
| refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| resize | `width: integer, height: integer` | `void` | `obj:resize(width, height)` |
| _NV_resize | `width: integer, height: integer` | `void` | `obj:_NV_resize(width, height)` |
| getBottom | `` | `integer` | `obj:getBottom()` |
| _NV_getBottom | `` | `integer` | `obj:_NV_getBottom()` |
| getType | `` | `integer` | `obj:getType()` |
| getUserData | `` | `void` | `obj:getUserData()` |
| _NV_getUserData | `` | `void` | `obj:_NV_getUserData()` |
| getNumWidgets | `` | `integer` | `obj:getNumWidgets()` |
| getWidget | `index: integer` | `lightuserdata` | `obj:getWidget(index)` |

## DataPanelLine_Button
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| userData | unknown | RW | `obj.userData = <value>` |
| button | lightuserdata | RW | `obj.button = <value>` |
| buttonWidth | number | RW | `obj.buttonWidth = <value>` |
| buttonHeight | number | RW | `obj.buttonHeight = <value>` |
| buttonSkin | string | RW | `obj.buttonSkin = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `a: string, b: string, cat: integer, w: number, skin: string` | `DataPanelLine_Button` | `obj:_CONSTRUCTOR(a, b, cat, w, skin)` |
| getUserData | `` | `void` | `obj:getUserData()` |
| _NV_getUserData | `` | `void` | `obj:_NV_getUserData()` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_CheckBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| valuePtr | lightuserdata | R | `obj.valuePtr` |
| text | lightuserdata | R | `obj.text` |
| button | lightuserdata | R | `obj.button` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| setValue | `checked: boolean` | `void` | `obj:setValue(checked)` |
| setValuePtr | `bVal: boolean` | `void` | `obj:setValuePtr(bVal)` |
| getTextBox | `` | `MyGUI::Widget` | `obj:getTextBox()` |
| getCheckBox | `` | `MyGUI::Widget` | `obj:getCheckBox()` |
| _CONSTRUCTOR | `key: string, cat: integer, bVal: boolean` | `DataPanelLine_CheckBox` | `obj:_CONSTRUCTOR(key, cat, bVal)` |
| createMe | `topReal: number, lastLine: boolean` | `void` | `obj:createMe(topReal, lastLine)` |
| _NV_createMe | `topReal: number, lastLine: boolean` | `void` | `obj:_NV_createMe(topReal, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_DropBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| listBox | lightuserdata | R | `obj.listBox` |
| listWidth | number | RW | `obj.listWidth = <value>` |
| valPtr | lightuserdata | R | `obj.valPtr` |
| hasGoBox | boolean | RW | `obj.hasGoBox = <value>` |
| goBox | lightuserdata | R | `obj.goBox` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addAValue | `key: string, val: integer` | `void` | `obj:addAValue(key, val)` |
| getSelectedValue | `` | `integer` | `obj:getSelectedValue()` |
| setSelectedValue | `val: integer` | `void` | `obj:setSelectedValue(val)` |
| getSelectedText | `` | `string` | `obj:getSelectedText()` |
| clearValues | `` | `void` | `obj:clearValues()` |
| getComboBox | `` | `lightuserdata` | `obj:getComboBox()` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| _CONSTRUCTOR | `text: string, category: integer, valInt: integer, width: number, hasGobox: boolean` | `DataPanelLine_DropBox` | `obj:_CONSTRUCTOR(text, category, valInt, width, hasGobox)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Faction
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| v1 | number | RW | `obj.v1 = <value>` |
| v2 | number | RW | `obj.v2 = <value>` |
| bar | lightuserdata | R | `obj.bar` |
| bar2 | lightuserdata | R | `obj.bar2` |
| but | lightuserdata | R | `obj.but` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `a: string, b: string, cat: integer, vv1: number, vv2: number` | `DataPanelLine_Faction` | `obj:_CONSTRUCTOR(a, b, cat, vv1, vv2)` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_KeyConfig
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| btn0 | lightuserdata | R | `obj.btn0` |
| btn1 | lightuserdata | R | `obj.btn1` |
| command | string | RW | `obj.command = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `cmd: string, text: string, cat: integer` | `DataPanelLine_KeyConfig` | `obj:_CONSTRUCTOR(cmd, text, cat)` |
| oldKey | `` | `integer` | `obj:oldKey()` |
| setKey | `s: string` | `void` | `obj:setKey(s)` |
| eraseKey | `key: string` | `void` | `obj:eraseKey(key)` |
| refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| cancel | `` | `void` | `obj:cancel()` |
| createMe | `vpos: number, lastLine: boolean` | `void` | `obj:createMe(vpos, lastLine)` |
| _NV_createMe | `vpos: number, lastLine: boolean` | `void` | `obj:_NV_createMe(vpos, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Progress
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textBox | lightuserdata | R | `obj.textBox` |
| progress | lightuserdata | R | `obj.progress` |
| progressText | lightuserdata | R | `obj.progressText` |
| showKey | boolean | RW | `obj.showKey = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setProgress | `value: number, text: string` | `void` | `obj:setProgress(value, text)` |
| _CONSTRUCTOR | `key: string, category: integer, showKey: boolean` | `DataPanelLine_Progress` | `obj:_CONSTRUCTOR(key, category, showKey)` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Research
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| v1 | number | RW | `obj.v1 = <value>` |
| v2 | number | RW | `obj.v2 = <value>` |
| hasXBut | boolean | RW | `obj.hasXBut = <value>` |
| barSkin | string | RW | `obj.barSkin = <value>` |
| bar | lightuserdata | RW | `obj.bar = <value>` |
| but | lightuserdata | R | `obj.but` |
| Xbut | lightuserdata | R | `obj.Xbut` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `a: string, b: string, cat: integer, vv1: number, _barColor: string, _Xbut: boolean` | `DataPanelLine_Research` | `obj:_CONSTRUCTOR(a, b, cat, vv1, _barColor, _Xbut)` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| scale | number | RW | `obj.scale = <value>` |
| min | number | RW | `obj.min = <value>` |
| max | number | RW | `obj.max = <value>` |
| valuePtr | lightuserdata | R | `obj.valuePtr` |
| slider | lightuserdata | R | `obj.slider` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `key: string, text: string, min: number, max: number, category: integer, scale: number` | `DataPanelLine_Slider` | `obj:_CONSTRUCTOR(key, text, min, max, category, scale)` |
| setValue | `value: number` | `void` | `obj:setValue(value)` |
| getValue | `` | `number` | `obj:getValue()` |
| refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_SliderEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| width | number | RW | `obj.width = <value>` |
| showName | boolean | RW | `obj.showName = <value>` |
| min | number | RW | `obj.min = <value>` |
| max | number | RW | `obj.max = <value>` |
| valuePtr | lightuserdata | R | `obj.valuePtr` |
| scale | number | RW | `obj.scale = <value>` |
| nameText | lightuserdata | R | `obj.nameText` |
| valueEditBox | lightuserdata | R | `obj.valueEditBox` |
| sliderBar | lightuserdata | R | `obj.sliderBar` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setEditableValuePtr | `tempVal: number, lo: number, hi: number` | `void` | `obj:setEditableValuePtr(tempVal, lo, hi)` |
| getSlider | `` | `MyGUI::Widget` | `obj:getSlider()` |
| getEditBox | `` | `MyGUI::Widget` | `obj:getEditBox()` |
| setValue | `v: number` | `void` | `obj:setValue(v)` |
| refresh | `` | `void` | `obj:refresh()` |
| _NV_refresh | `` | `void` | `obj:_NV_refresh()` |
| setPrecision | `dp: integer` | `void` | `obj:setPrecision(dp)` |
| _CONSTRUCTOR | `text: string, category: integer, showName: boolean, min: number, max: number, tempVal: number` | `DataPanelLine_SliderEditable` | `obj:_CONSTRUCTOR(text, category, showName, min, max, tempVal)` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_Text
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| editBox | lightuserdata | R | `obj.editBox` |
| wordWrap | boolean | RW | `obj.wordWrap = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DataPanelLine_TextEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| editBox | lightuserdata | R | `obj.editBox` |
| nameText | lightuserdata | R | `obj.nameText` |
| showKey | boolean | RW | `obj.showKey = <value>` |
| multiLine | boolean | RW | `obj.multiLine = <value>` |
| width | number | RW | `obj.width = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getEditBox | `` | `lightuserdata` | `obj:getEditBox()` |
| getNameBox | `` | `lightuserdata` | `obj:getNameBox()` |
| createMe | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| _NV_createMe | `top: number, lastLine: boolean` | `void` | `obj:_NV_createMe(top, lastLine)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## DatapanelGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/DatapanelGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| frequentUpdatesWanted | boolean | RW | `obj.frequentUpdatesWanted = <value>` |
| scrollWin | lightuserdata | R | `obj.scrollWin` |
| premadeParentWindow | boolean | RW | `obj.premadeParentWindow = <value>` |
| scrolling | boolean | RW | `obj.scrolling = <value>` |
| isWindow | boolean | RW | `obj.isWindow = <value>` |
| currentCategory | integer | RW | `obj.currentCategory = <value>` |
| mouseOverEvent | lightuserdata | R | `obj.mouseOverEvent` |
| mouseOverEventDatas | lightuserdata | R | `obj.mouseOverEventDatas` |
| automaticRefresh | boolean | RW | `obj.automaticRefresh = <value>` |
| automaticTarget | boolean | RW | `obj.automaticTarget = <value>` |
| tabWin | lightuserdata | R | `obj.tabWin` |
| panelName | string | RW | `obj.panelName = <value>` |
| x | number | RW | `obj.x = <value>` |
| y | number | RW | `obj.y = <value>` |
| w | number | RW | `obj.w = <value>` |
| h | number | RW | `obj.h = <value>` |
| DATALINESPACING | number | RW | `obj.DATALINESPACING = <value>` |
| DATALINETHICKNESS | number | RW | `obj.DATALINETHICKNESS = <value>` |
| basicSpacing | boolean | RW | `obj.basicSpacing = <value>` |
| layer | string | RW | `obj.layer = <value>` |
| scrollView | lightuserdata | R | `obj.scrollView` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setFrequentUpdateMode | `` | `void` | `obj:setFrequentUpdateMode()` |
| setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| _NV_setPositionReal | `x: number, y: number` | `void` | `obj:_NV_setPositionReal(x, y)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| _NV_setPosition | `x: integer, y: integer` | `void` | `obj:_NV_setPosition(x, y)` |
| resize | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |
| _NV_resize | `w: integer, h: integer` | `void` | `obj:_NV_resize(w, h)` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| clearPage | `cat: integer` | `void` | `obj:clearPage(cat)` |
| _NV_clearPage | `cat: integer` | `void` | `obj:_NV_clearPage(cat)` |
| hideAllWidgets | `` | `void` | `obj:hideAllWidgets()` |
| _NV_hideAllWidgets | `` | `void` | `obj:_NV_hideAllWidgets()` |
| create | `` | `void` | `obj:create()` |
| _NV_create | `` | `void` | `obj:_NV_create()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| show_NonSmooth | `on: boolean` | `void` | `obj:show_NonSmooth(on)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| setPanelName | `name: string` | `void` | `obj:setPanelName(name)` |
| showTabs | `on: boolean` | `void` | `obj:showTabs(on)` |
| _NV_showTabs | `on: boolean` | `void` | `obj:_NV_showTabs(on)` |
| addTab | `id: integer, name: string, icon: string` | `void` | `obj:addTab(id, name, icon)` |
| _NV_addTab | `id: integer, name: string, icon: string` | `void` | `obj:_NV_addTab(id, name, icon)` |
| setTabName | `id: integer, name: string` | `void` | `obj:setTabName(id, name)` |
| _NV_setTabName | `id: integer, name: string` | `void` | `obj:_NV_setTabName(id, name)` |
| setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| setAutomaticRefresh | `on: boolean` | `void` | `obj:setAutomaticRefresh(on)` |
| _NV_setAutomaticRefresh | `on: boolean` | `void` | `obj:_NV_setAutomaticRefresh(on)` |
| setAutomaticTargeting | `on: boolean` | `void` | `obj:setAutomaticTargeting(on)` |
| _NV_setAutomaticTargeting | `on: boolean` | `void` | `obj:_NV_setAutomaticTargeting(on)` |
| _zeroLines | `cat: integer` | `DataPanelLine` | `obj:_zeroLines(cat)` |
| _NV__zeroLines | `cat: integer` | `DataPanelLine` | `obj:_NV__zeroLines(cat)` |
| setLineStatInfo | `s1: string, s2: string, category: integer` | `DataPanelLine` | `obj:setLineStatInfo(s1, s2, category)` |
| setLineFaction | `s1: string, s2: string, category: integer, v1: number, v2: number` | `DataPanelLine_Faction` | `obj:setLineFaction(s1, s2, category, v1, v2)` |
| setLineTextButton | `text: string, caption: string, category: integer, buttonWidth: number, skin: string` | `DataPanelLine_Button` | `obj:setLineTextButton(text, caption, category, buttonWidth, skin)` |
| setLineButton | `key: string, caption: string, category: integer` | `DataPanelLine_Button` | `obj:setLineButton(key, caption, category)` |
| setLineToggleButton | `key: string, caption: string, category: integer` | `DataPanelLine_Button` | `obj:setLineToggleButton(key, caption, category)` |
| setLineSliderEditable | `key: string, category: integer, showName: boolean, min: number, max: number, tempVal: number` | `DataPanelLine_SliderEditable` | `obj:setLineSliderEditable(key, category, showName, min, max, tempVal)` |
| setLineSlider | `key: string, caption: string, min: number, max: number, category: integer, tempVal: number, scale: number` | `DataPanelLine_Slider` | `obj:setLineSlider(key, caption, min, max, category, tempVal, scale)` |
| setLineProgress | `key: string, category: integer, progressValue: number, progressText: string, showKey: boolean` | `DataPanelLine_Progress` | `obj:setLineProgress(key, category, progressValue, progressText, showKey)` |
| removeLine | `s1: string, category: integer` | `void` | `obj:removeLine(s1, category)` |
| setLineCheckbox | `s1: string, tempBool: boolean, category: integer` | `DataPanelLine_CheckBox` | `obj:setLineCheckbox(s1, tempBool, category)` |
| setLineDropBox | `key: string, category: integer, tempInt: integer, goBox: boolean, width: number` | `DataPanelLine_DropBox` | `obj:setLineDropBox(key, category, tempInt, goBox, width)` |
| addSpace | `category: integer, h: number` | `void` | `obj:addSpace(category, h)` |
| setCategoryIcon | `cat: integer, image: string` | `void` | `obj:setCategoryIcon(cat, image)` |
| _NV_setCategoryIcon | `cat: integer, image: string` | `void` | `obj:_NV_setCategoryIcon(cat, image)` |
| changeCategory | `cat: integer` | `void` | `obj:changeCategory(cat)` |
| _NV_changeCategory | `cat: integer` | `void` | `obj:_NV_changeCategory(cat)` |
| getCurrentCategory | `` | `integer` | `obj:getCurrentCategory()` |
| _NV_getCurrentCategory | `` | `integer` | `obj:_NV_getCurrentCategory()` |
| addCustomLine | `` | `void` | `obj:addCustomLine()` |
| getObject | `` | `void` | `obj:getObject()` |
| _NV_getObject | `` | `void` | `obj:_NV_getObject()` |
| setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:setLineSpacing(numLinesPerScreen)` |
| _NV_setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:_NV_setLineSpacing(numLinesPerScreen)` |
| getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:getLine(key, cat)` |
| _NV_getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:_NV_getLine(key, cat)` |
| lineExists | `key: string, cat: integer` | `boolean` | `obj:lineExists(key, cat)` |
| getContentHeight | `cat: integer` | `integer` | `obj:getContentHeight(cat)` |
| getNumLines | `cat: integer` | `integer` | `obj:getNumLines(cat)` |
| getLineByNum | `cat: integer, i: integer` | `DataPanelLine` | `obj:getLineByNum(cat, i)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createLine | `category: integer, lastLine: boolean` | `DataPanelLine` | `obj:createLine(category, lastLine)` |
| getNextVerticalPos | `category: integer` | `number` | `obj:getNextVerticalPos(category)` |
| dataExists | `cat: integer, name: string` | `boolean` | `obj:dataExists(cat, name)` |
| clearCategoryTabs | `` | `void` | `obj:clearCategoryTabs()` |

## DelayedSpawnMsg
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentTown | unknown | RW | `obj.parentTown = <value>` |
| item | Item | RW | `obj.item = <value>` |
| nestData | GameData | RW | `obj.nestData = <value>` |
| pos | Vector3 | RW | `obj.pos = <value>` |
| insideBuilding | unknown | RW | `obj.insideBuilding = <value>` |

## DialogAction
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | integer | RW | `obj.value = <value>` |
| key | integer | RW | `obj.key = <value>` |

## DialogChoiceList
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| conversationChoices | lektor<DialogLineData*> | RW | `obj.conversationChoices = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `DialogChoiceList` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| add | `` | `void` | `obj:add()` |

## DialogCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | integer | RW | `obj.key = <value>` |
| compareBy | integer | RW | `obj.compareBy = <value>` |
| who | integer | RW | `obj.who = <value>` |
| value | integer | RW | `obj.value = <value>` |

## DialogDataManager
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _createData | `` | `DialogLineData` | `obj:_createData()` |
| initialise | `` | `void` | `obj:initialise()` |
| save | `` | `void` | `obj:save()` |
| load | `` | `void` | `obj:load()` |
| newGameReset | `` | `void` | `obj:newGameReset()` |
| getData | `` | `DialogLineData` | `obj:getData()` |

## DialogLineData
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| targetFlagsNeeded | integer | RW | `obj.targetFlagsNeeded = <value>` |
| targetFlagsNotWanted | integer | RW | `obj.targetFlagsNotWanted = <value>` |
| personalityNeeded | integer | RW | `obj.personalityNeeded = <value>` |
| personalityNotWanted | integer | RW | `obj.personalityNotWanted = <value>` |
| campaignTriggers | FitnessSelector<CampaignTriggerData*> | RW | `obj.campaignTriggers = <value>` |
| isTargetRace | lektor<GameData*> | RW | `obj.isTargetRace = <value>` |
| isTargetSubRace_specificallyTheTarget | lektor<GameData*> | RW | `obj.isTargetSubRace_specificallyTheTarget = <value>` |
| givesItem | lektor<GameDataValuePair> | RW | `obj.givesItem = <value>` |
| inTownOf | Faction | RW | `obj.inTownOf = <value>` |
| isTargetFaction | Faction | RW | `obj.isTargetFaction = <value>` |
| isMyFaction | Faction | RW | `obj.isMyFaction = <value>` |
| isCharacter | lektor<GameData*> | RW | `obj.isCharacter = <value>` |
| isTargetCarryingCharacter | lektor<GameData*> | RW | `obj.isTargetCarryingCharacter = <value>` |
| hasPackage | lektor<GameData*> | RW | `obj.hasPackage = <value>` |
| isMyRace | lektor<GameData*> | RW | `obj.isMyRace = <value>` |
| isMySubRace | lektor<GameData*> | RW | `obj.isMySubRace = <value>` |
| hasItemType | integer | RW | `obj.hasItemType = <value>` |
| hasItem | lektor<GameData*> | RW | `obj.hasItem = <value>` |
| worldState | WorldEventStateQueryList | RW | `obj.worldState = <value>` |
| data | GameData | RW | `obj.data = <value>` |
| onceOnly | boolean | RW | `obj.onceOnly = <value>` |
| isMonologue | boolean | RW | `obj.isMonologue = <value>` |
| forCertainType | integer | RW | `obj.forCertainType = <value>` |
| children | DialogChoiceList | RW | `obj.children = <value>` |
| conditions | lektor<DialogLineData::DialogCondition*> | RW | `obj.conditions = <value>` |
| actions | lektor<DialogLineData::DialogAction*> | RW | `obj.actions = <value>` |
| lineCount | integer | RW | `obj.lineCount = <value>` |
| texts | string | RW | `obj.texts = <value>` |
| parent | DialogLineData | RW | `obj.parent = <value>` |
| chancePermanent | number | RW | `obj.chancePermanent = <value>` |
| chanceTemporary | number | RW | `obj.chanceTemporary = <value>` |
| unique | boolean | RW | `obj.unique = <value>` |
| uniqueOwner | unknown | RW | `obj.uniqueOwner = <value>` |
| dialogRepeatMinTimeInHours | number | RW | `obj.dialogRepeatMinTimeInHours = <value>` |
| lastTimeSaid | TimeOfDay | RW | `obj.lastTimeSaid = <value>` |
| score | integer | RW | `obj.score = <value>` |
| oneAtATime | boolean | RW | `obj.oneAtATime = <value>` |
| isLocked | boolean | RW | `obj.isLocked = <value>` |
| locks | lektor<DialogLineData*> | RW | `obj.locks = <value>` |
| unlocks_lockMe | lektor<DialogLineData*> | RW | `obj.unlocks_lockMe = <value>` |
| unlocks_dontLockMe | lektor<DialogLineData*> | RW | `obj.unlocks_dontLockMe = <value>` |
| crowdTrigger | DialogLineData | RW | `obj.crowdTrigger = <value>` |
| factionRelationEffects | unknown | RW | `obj.factionRelationEffects = <value>` |
| playerInterruptionDialog | DialogLineData | RW | `obj.playerInterruptionDialog = <value>` |
| isInterjection | boolean | RW | `obj.isInterjection = <value>` |
| speaker | integer | RW | `obj.speaker = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getParent | `` | `DialogLineData` | `obj:getParent()` |
| isForSpecificCharacter | `` | `boolean` | `obj:isForSpecificCharacter()` |
| hasSpecificCharacterRequirement | `` | `boolean` | `obj:hasSpecificCharacterRequirement()` |
| _CONSTRUCTOR | `` | `DialogLineData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupChildren | `` | `void` | `obj:setupChildren()` |
| checkRepeatLimits | `` | `boolean` | `obj:checkRepeatLimits()` |
| checkTags | `` | `boolean` | `obj:checkTags()` |
| getName | `` | `string` | `obj:getName()` |
| saidItBefore | `` | `boolean` | `obj:saidItBefore()` |
| willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| isEmptyNode | `` | `boolean` | `obj:isEmptyNode()` |
| _NV_isEmptyNode | `` | `boolean` | `obj:_NV_isEmptyNode()` |
| isAnnouncement | `` | `boolean` | `obj:isAnnouncement()` |
| stampLastTimeSaid | `` | `void` | `obj:stampLastTimeSaid()` |
| getScore | `` | `integer` | `obj:getScore()` |
| getScorePlusChildrenIfEmpty | `` | `integer` | `obj:getScorePlusChildrenIfEmpty()` |
| hasChildren | `` | `boolean` | `obj:hasChildren()` |
| checkConditions | `isWordswap: boolean` | `boolean` | `obj:checkConditions(isWordswap)` |
| chooseAChild | `isForWordswaps: boolean` | `DialogLineData` | `obj:chooseAChild(isForWordswaps)` |
| getStringID | `` | `string` | `obj:getStringID()` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| getChildByStringID | `sid: string` | `DialogLineData` | `obj:getChildByStringID(sid)` |
| setParent | `` | `void` | `obj:setParent()` |
| getMoneyCostForLine | `` | `integer` | `obj:getMoneyCostForLine()` |
| getText | `stampTime: boolean` | `string` | `obj:getText(stampTime)` |
| getPlayerReplies | `` | `void` | `obj:getPlayerReplies()` |
| getActions | `` | `lektor<DialogLineData::DialogAction*>` | `obj:getActions()` |

## DialogState
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| count | integer | RW | `obj.count = <value>` |
| lastTimeStamp | number | RW | `obj.lastTimeStamp = <value>` |
| resetTime | number | RW | `obj.resetTime = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `DialogState` | `obj:_CONSTRUCTOR()` |

## Dialogue
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| repCounter | Dialogue::RepetitionCounter | RW | `obj.repCounter = <value>` |
| _needsDynamicAssessments | boolean | RW | `obj._needsDynamicAssessments = <value>` |
| sayMsg | string | RW | `obj.sayMsg = <value>` |
| playerInterruptionDialog | DialogLineData | RW | `obj.playerInterruptionDialog = <value>` |
| _hasEnded | boolean | RW | `obj._hasEnded = <value>` |
| shouting | boolean | RW | `obj.shouting = <value>` |
| staysOnScreen | boolean | RW | `obj.staysOnScreen = <value>` |
| me | Character | RW | `obj.me = <value>` |
| conversationTarget | unknown | RW | `obj.conversationTarget = <value>` |
| stats | CharStats | RW | `obj.stats = <value>` |
| movement | CharMovement | RW | `obj.movement = <value>` |
| currentConversationType | integer | RW | `obj.currentConversationType = <value>` |
| currentConversation | DialogLineData | RW | `obj.currentConversation = <value>` |
| currentLine | DialogLineData | RW | `obj.currentLine = <value>` |
| interjector1 | unknown | RW | `obj.interjector1 = <value>` |
| interjector2 | unknown | RW | `obj.interjector2 = <value>` |
| interjector3 | unknown | RW | `obj.interjector3 = <value>` |
| speechBubblePanel | DialogueSpeechBubble | RW | `obj.speechBubblePanel = <value>` |
| speechTextTimer | number | RW | `obj.speechTextTimer = <value>` |
| speechTextTimer_forced | number | RW | `obj.speechTextTimer_forced = <value>` |
| npcReplyText | string | RW | `obj.npcReplyText = <value>` |
| conversationMaster | unknown | RW | `obj.conversationMaster = <value>` |
| waitingForReplyFrom | unknown | RW | `obj.waitingForReplyFrom = <value>` |
| pacakgesIHave | GameData | RW | `obj.pacakgesIHave = <value>` |
| locked | DialogLineDataBoolMapBinding::MapType | RW | `obj.locked = <value>` |
| _hasChanceLines | DialogLineDataBoolMapBinding::MapType | RW | `obj._hasChanceLines = <value>` |
| eventRepeatTimers | EventRepeatTimersMapBinding::MapType | RW | `obj.eventRepeatTimers = <value>` |
| eventDeliveredStates | EventDeliveredStatesMapBinding::MapType | RW | `obj.eventDeliveredStates = <value>` |
| conversationsMain | ConversationsMainMapBinding::MapType | RW | `obj.conversationsMain = <value>` |
| threadMessages | integer | RW | `obj.threadMessages = <value>` |
| replyIds | string | RW | `obj.replyIds = <value>` |
| responses | string | RW | `obj.responses = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWordSwap | `key: string, _a3: boolean` | `string` | `obj:getWordSwap(key, _a3)` |
| setupWordSwaps | `` | `void` | `obj:setupWordSwaps()` |
| _CONSTRUCTOR | `` | `Dialogue` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| create | `` | `void` | `obj:create()` |
| getHandle | `` | `void` | `obj:getHandle()` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| setLineLocked | `on: boolean` | `void` | `obj:setLineLocked(on)` |
| isLocked | `` | `boolean` | `obj:isLocked()` |
| setInDialog | `on: boolean` | `void` | `obj:setInDialog(on)` |
| clearDialogues | `` | `void` | `obj:clearDialogues()` |
| clearAnnouncements | `` | `void` | `obj:clearAnnouncements()` |
| needsDialogAssessmentUpdate | `` | `boolean` | `obj:needsDialogAssessmentUpdate()` |
| addDialoguePackage | `` | `void` | `obj:addDialoguePackage()` |
| addConversation | `t: integer` | `void` | `obj:addConversation(t)` |
| clearConversationList | `t: integer` | `void` | `obj:clearConversationList(t)` |
| willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| sendEventOverride | `what: integer, forceRepeat: boolean` | `boolean` | `obj:sendEventOverride(what, forceRepeat)` |
| sendEvent | `what: integer` | `boolean` | `obj:sendEvent(what)` |
| stopEvent | `what: integer` | `void` | `obj:stopEvent(what)` |
| runCustomDialog | `` | `boolean` | `obj:runCustomDialog()` |
| scoreCustomDialog | `` | `integer` | `obj:scoreCustomDialog()` |
| conversationHasEnded | `` | `boolean` | `obj:conversationHasEnded()` |
| getConversationTarget | `` | `void` | `obj:getConversationTarget()` |
| changeConversationTarget | `` | `void` | `obj:changeConversationTarget()` |
| conversationHasEndedPrettyMuch | `` | `boolean` | `obj:conversationHasEndedPrettyMuch()` |
| makeAnnouncement | `` | `boolean` | `obj:makeAnnouncement()` |
| update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| endDialogue | `definitelyTheEnd: boolean` | `void` | `obj:endDialogue(definitelyTheEnd)` |
| notifyUnderAttack | `` | `void` | `obj:notifyUnderAttack()` |
| hasDialogue_Fast | `` | `boolean` | `obj:hasDialogue_Fast()` |
| hasDialogue_Accurate | `` | `boolean` | `obj:hasDialogue_Accurate()` |
| hasDialogueEvent | `e: integer` | `boolean` | `obj:hasDialogueEvent(e)` |
| dialogDelivered | `e: integer` | `boolean` | `obj:dialogDelivered(e)` |
| _checkCondition | `conditionName: integer, compareBy: integer, val: integer` | `boolean` | `obj:_checkCondition(conditionName, compareBy, val)` |
| dontLetTargetBeMe | `` | `void` | `obj:dontLetTargetBeMe()` |
| hasThisChanceLine | `chance: number` | `boolean` | `obj:hasThisChanceLine(chance)` |
| _chooseDialog | `isWordswap: boolean` | `DialogLineData` | `obj:_chooseDialog(isWordswap)` |
| triggerNextLine | `` | `void` | `obj:triggerNextLine()` |
| targetInTalkingRange | `mult: number` | `boolean` | `obj:targetInTalkingRange(mult)` |
| save | `` | `void` | `obj:save()` |
| load | `` | `void` | `obj:load()` |
| getSpeaker | `who: integer, isForWordswaps: boolean` | `Character` | `obj:getSpeaker(who, isForWordswaps)` |
| isCurrentConversationRunning | `` | `boolean` | `obj:isCurrentConversationRunning()` |
| findInterjectionCharacter | `` | `Character` | `obj:findInterjectionCharacter()` |
| isKOExempt | `what: integer` | `boolean` | `obj:isKOExempt(what)` |
| _endPlayerConversation | `finished: boolean` | `void` | `obj:_endPlayerConversation(finished)` |
| startPlayerConversation | `` | `boolean` | `obj:startPlayerConversation()` |
| startConversation | `ev: integer, force: boolean` | `boolean` | `obj:startConversation(ev, force)` |
| getConversationList | `t: integer` | `DialogChoiceList` | `obj:getConversationList(t)` |
| _doActions | `` | `void` | `obj:_doActions()` |
| sayLine | `` | `boolean` | `obj:sayLine()` |
| listPlayerReplies | `` | `void` | `obj:listPlayerReplies()` |
| isLastLine | `` | `boolean` | `obj:isLastLine()` |
| setSpeaker | `who: integer` | `void` | `obj:setSpeaker(who)` |
| _updateTextPos | `` | `void` | `obj:_updateTextPos()` |
| clearSpeechBox | `` | `void` | `obj:clearSpeechBox()` |
| clearRespones | `` | `void` | `obj:clearRespones()` |
| clearResponesGUI | `` | `void` | `obj:clearResponesGUI()` |
| setResponesGUI | `` | `void` | `obj:setResponesGUI()` |
| setConversationReplyGUI | `` | `void` | `obj:setConversationReplyGUI()` |
| say | `text: string` | `void` | `obj:say(text)` |
| replyClicked | `index: string` | `void` | `obj:replyClicked(index)` |
| isAtTownOf | `` | `boolean` | `obj:isAtTownOf()` |
| resolveOverlappedSpeechBubbles | `` | `void` | `obj:resolveOverlappedSpeechBubbles()` |

## DialogueSpeechBubble
**Header:** `extern/KenshiLib/Include/kenshi/dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| stayOnScreen | boolean | RW | `obj.stayOnScreen = <value>` |
| shout | boolean | RW | `obj.shout = <value>` |
| marginW | integer | RW | `obj.marginW = <value>` |
| marginH | integer | RW | `obj.marginH = <value>` |
| textBox | lightuserdata | RW | `obj.textBox = <value>` |
| baseSize | integer | RW | `obj.baseSize = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `shout: boolean, importnt: boolean` | `DialogueSpeechBubble` | `obj:_CONSTRUCTOR(shout, importnt)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setText | `text: string` | `void` | `obj:setText(text)` |
| setAlpha | `value: number` | `void` | `obj:setAlpha(value)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| reset | `` | `void` | `obj:reset()` |
| getAlpha | `` | `number` | `obj:getAlpha()` |
| getRect | `` | `integer` | `obj:getRect()` |

## DialogueWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/DialogueWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| dialogue | Dialogue | RW | `obj.dialogue = <value>` |
| conversationPanelsMargin | integer | RW | `obj.conversationPanelsMargin = <value>` |
| converstaionPCPanelBottom | integer | RW | `obj.converstaionPCPanelBottom = <value>` |
| conversationPCSpeechPanelMinHeight | integer | RW | `obj.conversationPCSpeechPanelMinHeight = <value>` |
| conversationNPCSpeechPanelMinHeight | integer | RW | `obj.conversationNPCSpeechPanelMinHeight = <value>` |
| conversationPCPanelHeightDiffSpeechPanel | integer | RW | `obj.conversationPCPanelHeightDiffSpeechPanel = <value>` |
| conversationNPCPanelHeightDiffSpeechPanel | integer | RW | `obj.conversationNPCPanelHeightDiffSpeechPanel = <value>` |
| conversationPC | Character | RW | `obj.conversationPC = <value>` |
| conversationPCPanel | lightuserdata | RW | `obj.conversationPCPanel = <value>` |
| conversationNPCPanel | lightuserdata | RW | `obj.conversationNPCPanel = <value>` |
| conversationNPCNameText | lightuserdata | R | `obj.conversationNPCNameText` |
| conversationPCNameText | lightuserdata | R | `obj.conversationPCNameText` |
| conversationPCMoneyText | lightuserdata | R | `obj.conversationPCMoneyText` |
| conversationNPCSpeech | lightuserdata | RW | `obj.conversationNPCSpeech = <value>` |
| conversationPCSpeechPanel | lightuserdata | RW | `obj.conversationPCSpeechPanel = <value>` |
| conversationNPCPortrait | lightuserdata | R | `obj.conversationNPCPortrait` |
| conversationPCPortrait | lightuserdata | R | `obj.conversationPCPortrait` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| hide | `` | `void` | `obj:hide()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| getTop | `` | `integer` | `obj:getTop()` |
| activateResponse | `index: integer` | `void` | `obj:activateResponse(index)` |
| setNPCText | `text: string` | `void` | `obj:setNPCText(text)` |
| clearResponses | `` | `void` | `obj:clearResponses()` |
| changePortrait | `player: boolean` | `void` | `obj:changePortrait(player)` |
| _CONSTRUCTOR | `` | `DialogueWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updatePanelsPosition | `` | `void` | `obj:updatePanelsPosition()` |

## DoorStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/DoorStuff.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isSetupComplete | boolean | RW | `obj.isSetupComplete = <value>` |
| parent | Building | R | `obj.parent` |
| doorLock | lightuserdata | R | `obj.doorLock` |
| gateCode | integer | RW | `obj.gateCode = <value>` |
| doorOpenAmount | number | RW | `obj.doorOpenAmount = <value>` |
| state | integer | RW | `obj.state = <value>` |
| wantsToLock | boolean | RW | `obj.wantsToLock = <value>` |
| doorSpeed | number | RW | `obj.doorSpeed = <value>` |
| doorDistance | number | RW | `obj.doorDistance = <value>` |
| doorMoveAxis | integer | RW | `obj.doorMoveAxis = <value>` |
| doorComesOut | number | RW | `obj.doorComesOut = <value>` |
| nodeClosedPosition | Vector3 | R | `obj.nodeClosedPosition` |
| actorClosedPosition | Vector3 | RW | `obj.actorClosedPosition = <value>` |
| doorClosedPosition | Vector3 | RW | `obj.doorClosedPosition = <value>` |
| doorClosedPositionOut | Vector3 | RW | `obj.doorClosedPositionOut = <value>` |
| doorClosedPositionIn | Vector3 | RW | `obj.doorClosedPositionIn = <value>` |
| axisH | Vector3 | RW | `obj.axisH = <value>` |
| axisF | Vector3 | RW | `obj.axisF = <value>` |
| _isBroken | boolean | RW | `obj._isBroken = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupPhysicalUT | `` | `boolean` | `obj:setupPhysicalUT()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| _NV_getFaction | `` | `Faction` | `obj:_NV_getFaction()` |
| _getPhysActorUT | `` | `lightuserdata` | `obj:_getPhysActorUT()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| getGateCode | `` | `integer` | `obj:getGateCode()` |
| setGateCode | `code: integer` | `void` | `obj:setGateCode(code)` |
| isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| _NV_isGate | `` | `GatewayBuilding` | `obj:_NV_isGate()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| getDoor | `` | `DoorStuff` | `obj:getDoor()` |
| _NV_getDoor | `` | `DoorStuff` | `obj:_NV_getDoor()` |
| getName | `` | `string` | `obj:getName()` |
| _NV_getName | `` | `string` | `obj:_NV_getName()` |
| getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| _NV_getDoorLock | `` | `lightuserdata` | `obj:_NV_getDoorLock()` |
| hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| _NV_hasDoorLock | `` | `boolean` | `obj:_NV_hasDoorLock()` |
| updateGateCodeState | `` | `void` | `obj:updateGateCodeState()` |
| onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| _NV_onBuildingLoaded | `` | `void` | `obj:_NV_onBuildingLoaded()` |
| setDoorOpenAmount | `amount: number, forceUnsafe: boolean` | `void` | `obj:setDoorOpenAmount(amount, forceUnsafe)` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| _NV_isBroken | `` | `boolean` | `obj:_NV_isBroken()` |
| setBroken | `on: boolean` | `void` | `obj:setBroken(on)` |
| _NV_setBroken | `on: boolean` | `void` | `obj:_NV_setBroken(on)` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| isLocked | `` | `boolean` | `obj:isLocked()` |
| lockDoor | `` | `void` | `obj:lockDoor()` |
| unlockDoor | `` | `void` | `obj:unlockDoor()` |
| getDoorOpenAmount | `` | `number` | `obj:getDoorOpenAmount()` |
| setDoorState | `what: integer` | `void` | `obj:setDoorState(what)` |
| getDoorState | `` | `integer` | `obj:getDoorState()` |
| openDoor | `` | `boolean` | `obj:openDoor()` |
| closeDoor | `` | `boolean` | `obj:closeDoor()` |
| _forceDoorClosedUT | `` | `boolean` | `obj:_forceDoorClosedUT()` |
| _forceDoorOpenUT | `` | `boolean` | `obj:_forceDoorOpenUT()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| getDoorPosOutside_extraFarOut | `mult: number` | `Vector3` | `obj:getDoorPosOutside_extraFarOut(mult)` |
| getDoorPosInside_extraFarIn | `mult: number` | `Vector3` | `obj:getDoorPosInside_extraFarIn(mult)` |
| isOpen | `` | `boolean` | `obj:isOpen()` |
| doorStuff | `` | `DoorStuff` | `obj:doorStuff()` |
| _NV_doorStuff | `` | `DoorStuff` | `obj:_NV_doorStuff()` |
| doorParentBuilding | `` | `Building` | `obj:doorParentBuilding()` |
| _NV_doorParentBuilding | `` | `Building` | `obj:_NV_doorParentBuilding()` |

## EdgeCache
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| centre | lightuserdata | RW | `obj.centre = <value>` |
| radius | number | RW | `obj.radius = <value>` |
| hasDoor | boolean | RW | `obj.hasDoor = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `radius: number, hasDoor: boolean` | `EdgeCache` | `obj:_CONSTRUCTOR(radius, hasDoor)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## EdgeCache_Edge
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `EdgeCache::Edge` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## EdgePathNode
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mLeft | lightuserdata | RW | `obj.mLeft = <value>` |
| mRight | lightuserdata | RW | `obj.mRight = <value>` |
| face | integer | RW | `obj.face = <value>` |
| edge | integer | RW | `obj.edge = <value>` |
| leftClearance | number | RW | `obj.leftClearance = <value>` |
| rightClearance | number | RW | `obj.rightClearance = <value>` |
| maxPoint | number | RW | `obj.maxPoint = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `face: integer, edge: integer, leftClearance: number, rightClearance: number, maxPoint: number` | `EdgePathNode` | `obj:_CONSTRUCTOR(face, edge, leftClearance, rightClearance, maxPoint)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## EntData
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | GameData | RW | `obj.data = <value>` |
| maxSlope | number | RW | `obj.maxSlope = <value>` |
| minSlope | number | RW | `obj.minSlope = <value>` |
| chance | number | RW | `obj.chance = <value>` |
| minAltitude | number | RW | `obj.minAltitude = <value>` |
| maxAltitude | number | RW | `obj.maxAltitude = <value>` |
| slopeAlign | boolean | RW | `obj.slopeAlign = <value>` |
| floating | boolean | RW | `obj.floating = <value>` |
| uniformScale | boolean | RW | `obj.uniformScale = <value>` |
| accurateTrace | boolean | RW | `obj.accurateTrace = <value>` |
| upright | boolean | RW | `obj.upright = <value>` |
| minV | number | RW | `obj.minV = <value>` |
| maxV | number | RW | `obj.maxV = <value>` |
| clustered | boolean | RW | `obj.clustered = <value>` |
| limitToGrassAreas | boolean | RW | `obj.limitToGrassAreas = <value>` |
| nonBatched | boolean | RW | `obj.nonBatched = <value>` |
| carveRadius | number | RW | `obj.carveRadius = <value>` |
| grassSpot | number | RW | `obj.grassSpot = <value>` |
| roadRadius | number | RW | `obj.roadRadius = <value>` |
| clusterMin | number | RW | `obj.clusterMin = <value>` |
| clusterMax | number | RW | `obj.clusterMax = <value>` |
| clusterRadiusMin | number | RW | `obj.clusterRadiusMin = <value>` |
| clusterRadiusMax | number | RW | `obj.clusterRadiusMax = <value>` |
| viewDistance | number | RW | `obj.viewDistance = <value>` |
| seedOffset | integer | RW | `obj.seedOffset = <value>` |
| biomeSeparation | boolean | RW | `obj.biomeSeparation = <value>` |
| childClusterRadius | number | RW | `obj.childClusterRadius = <value>` |
| xmlFilename | string | RW | `obj.xmlFilename = <value>` |
| entity1 | lightuserdata | RW | `obj.entity1 = <value>` |
| entity2 | lightuserdata | RW | `obj.entity2 = <value>` |
| entity1Loaded | boolean | RW | `obj.entity1Loaded = <value>` |
| entity2Loaded | boolean | RW | `obj.entity2Loaded = <value>` |
| position | Vector3 | RW | `obj.position = <value>` |
| type | integer | RW | `obj.type = <value>` |
| referenceCount | integer | RW | `obj.referenceCount = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `rld: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(rld)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createEntity1 | `` | `lightuserdata` | `obj:createEntity1()` |
| createEntity2 | `` | `lightuserdata` | `obj:createEntity2()` |
| selectBiomeEntity | `position: Vector3` | `lightuserdata` | `obj:selectBiomeEntity(position)` |
| isLoaded | `` | `boolean` | `obj:isLoaded()` |

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _antiSlavery | boolean | RW | `obj._antiSlavery = <value>` |
| characteristicsData | lightuserdata | RW | `obj.characteristicsData = <value>` |
| fundamentalNPCType | integer | RW | `obj.fundamentalNPCType = <value>` |
| ranks | lektor<std::string> | RW | `obj.ranks = <value>` |
| allowSlavesWeapons | boolean | RW | `obj.allowSlavesWeapons = <value>` |
| myLawEnforcementFaction | Faction | RW | `obj.myLawEnforcementFaction = <value>` |
| isALawEnforcementFaction | boolean | RW | `obj.isALawEnforcementFaction = <value>` |
| factionLeader | FactionLeader | RW | `obj.factionLeader = <value>` |
| diplomatMgr | FactionUniqueSquadManager | RW | `obj.diplomatMgr = <value>` |
| relations | FactionRelations | RW | `obj.relations = <value>` |
| factionOwnerships | Ownerships | RW | `obj.factionOwnerships = <value>` |
| warMgr | FactionWarMgr | RW | `obj.warMgr = <value>` |
| tradeCulture | TradeCulture | RW | `obj.tradeCulture = <value>` |
| raceSelector | FitnessSelector<GameData*> | RW | `obj.raceSelector = <value>` |
| name | string | RW | `obj.name = <value>` |
| notARealFaction | boolean | RW | `obj.notARealFaction = <value>` |
| roadPreference | number | RW | `obj.roadPreference = <value>` |
| platoonKillList | lektor<Platoon*> | RW | `obj.platoonKillList = <value>` |
| platoonRemoveList | lektor<Platoon*> | RW | `obj.platoonRemoveList = <value>` |
| activePlatoons | lektor<Platoon*> | RW | `obj.activePlatoons = <value>` |
| unloadedPlatoons | lektor<Platoon*> | RW | `obj.unloadedPlatoons = <value>` |
| periodicUpdateCounter_active | integer | RW | `obj.periodicUpdateCounter_active = <value>` |
| periodicUpdateCounter_unloaded | integer | RW | `obj.periodicUpdateCounter_unloaded = <value>` |
| data | GameData | RW | `obj.data = <value>` |
| isAI | lightuserdata | RW | `obj.isAI = <value>` |
| isPlayer | PlayerInterface | RW | `obj.isPlayer = <value>` |
| spawnTimeStamp | integer | RW | `obj.spawnTimeStamp = <value>` |
| diplomatTimeStamp | integer | RW | `obj.diplomatTimeStamp = <value>` |
| platoonIDs | integer | RW | `obj.platoonIDs = <value>` |
| p_TIME | number | RW | `obj.p_TIME = <value>` |
| platoonPeriodicUpdateIndex | integer | RW | `obj.platoonPeriodicUpdateIndex = <value>` |
| buildingSwaps | lektor<Faction::BuildingSwaps> | RW | `obj.buildingSwaps = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_name: string` | `Faction` | `obj:_CONSTRUCTOR(_name)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| setup | `` | `boolean` | `obj:setup()` |
| setup2 | `` | `boolean` | `obj:setup2()` |
| setup3 | `` | `void` | `obj:setup3()` |
| getNewPlatoonID | `` | `string` | `obj:getNewPlatoonID()` |
| resetPlatoonID | `` | `void` | `obj:resetPlatoonID()` |
| createNewEmptyUnloadedPlatoon | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:createNewEmptyUnloadedPlatoon(pos, persistent)` |
| createNewEmptyActivePlatoon | `permanent: boolean, p: Vector3` | `Platoon` | `obj:createNewEmptyActivePlatoon(permanent, p)` |
| createPlatoonUnloaded | `pos: Vector3, persistent: boolean` | `void` | `obj:createPlatoonUnloaded(pos, persistent)` |
| createPlatoonAuto | `pos: Vector3` | `void` | `obj:createPlatoonAuto(pos)` |
| createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | `src: string` | `void` | `obj:createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src)` |
| restorePlatoon | `` | `void` | `obj:restorePlatoon()` |
| resetSquadPositions | `target: Vector3` | `boolean` | `obj:resetSquadPositions(target)` |
| countPopulation | `` | `integer` | `obj:countPopulation()` |
| countNumSquads | `` | `integer` | `obj:countNumSquads()` |
| destroyPlatoon | `` | `void` | `obj:destroyPlatoon()` |
| removePlatoon | `` | `void` | `obj:removePlatoon()` |
| getRandomLockLevel | `` | `integer` | `obj:getRandomLockLevel()` |
| getData | `` | `GameData` | `obj:getData()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| getDefaultDivision | `` | `GameData` | `obj:getDefaultDivision()` |
| getFactionColorScheme | `` | `GameData` | `obj:getFactionColorScheme()` |
| loadState | `` | `void` | `obj:loadState()` |
| saveState | `leveleditor: boolean` | `GameData` | `obj:saveState(leveleditor)` |
| _activateUnloadedPlatoons | `` | `void` | `obj:_activateUnloadedPlatoons()` |
| getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| _NV_getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:_NV_getCharactersInArea(pos, radius, standingOnly)` |
| getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| _NV_getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:_NV_getSelectedObjects(type, selectedOnly)` |
| removeObject | `` | `void` | `obj:removeObject()` |
| _NV_removeObject | `` | `void` | `obj:_NV_removeObject()` |
| destroyObject | `` | `void` | `obj:destroyObject()` |
| _NV_destroyObject | `` | `void` | `obj:_NV_destroyObject()` |
| processKillList | `` | `void` | `obj:processKillList()` |
| _NV_processKillList | `` | `void` | `obj:_NV_processKillList()` |
| addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| choosePlatoon | `` | `ActivePlatoon` | `obj:choosePlatoon()` |
| getActivePlatoons | `` | `lektor<Platoon*>` | `obj:getActivePlatoons()` |
| getUnloadedPlatoons | `` | `lektor<Platoon*>` | `obj:getUnloadedPlatoons()` |
| getFactionSize | `` | `integer` | `obj:getFactionSize()` |
| update | `time: number` | `void` | `obj:update(time)` |
| periodicUpdateThreaded | `` | `boolean` | `obj:periodicUpdateThreaded()` |
| periodicUpdateMT | `` | `boolean` | `obj:periodicUpdateMT()` |
| isThePlayer | `` | `boolean` | `obj:isThePlayer()` |
| isNotARealFaction | `` | `boolean` | `obj:isNotARealFaction()` |
| getName | `` | `void` | `obj:getName()` |
| getNumPlatoons | `tempsOnly: boolean` | `integer` | `obj:getNumPlatoons(tempsOnly)` |
| getSquadThatOwns | `` | `Platoon` | `obj:getSquadThatOwns()` |
| getAllActiveSquads | `` | `lightuserdata` | `obj:getAllActiveSquads()` |
| getRoadPreference | `` | `number` | `obj:getRoadPreference()` |
| isAntiSlavery | `` | `boolean` | `obj:isAntiSlavery()` |
| getLawEnforcementFaction | `` | `Faction` | `obj:getLawEnforcementFaction()` |
| chooseARace | `` | `GameData` | `obj:chooseARace()` |
| setName | `_name: string` | `void` | `obj:setName(_name)` |
| getBuildingReplacement | `` | `GameData` | `obj:getBuildingReplacement()` |
| _switchToUnloadedPlatoon | `` | `void` | `obj:_switchToUnloadedPlatoon()` |
| _newPlatoon | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:_newPlatoon(pos, persistent)` |
| _addActivePlatoonToList | `` | `void` | `obj:_addActivePlatoonToList()` |
| addPlatoon | `` | `void` | `obj:addPlatoon()` |
| changePlatoonIndex | `index: integer` | `void` | `obj:changePlatoonIndex(index)` |
| deactivatePlatoon | `` | `void` | `obj:deactivatePlatoon()` |
| activatePlatoon | `` | `void` | `obj:activatePlatoon()` |
| updateUnloadedPlatoons | `time: number` | `void` | `obj:updateUnloadedPlatoons(time)` |
| updateActivePlatoons | `time: number` | `void` | `obj:updateActivePlatoons(time)` |
| spawnSquadMissionsUpdate | `` | `void` | `obj:spawnSquadMissionsUpdate()` |
| _spawnASquad | `listname: string, sizeMultiplier: number` | `boolean` | `obj:_spawnASquad(listname, sizeMultiplier)` |
| getFundamentalNPCType | `` | `integer` | `obj:getFundamentalNPCType()` |

## FactionLeader
**Header:** `extern/KenshiLib/Include/kenshi/FactionLeader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| faction | Faction | RW | `obj.faction = <value>` |
| worstEnemy | Faction | RW | `obj.worstEnemy = <value>` |
| biomeTerritory | lektor<GameData*> | RW | `obj.biomeTerritory = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionLeader` | `obj:_CONSTRUCTOR()` |
| setNewLeader | `` | `void` | `obj:setNewLeader()` |
| getEnemyMissionTargetList | `` | `void` | `obj:getEnemyMissionTargetList()` |
| getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionManager
**Header:** `extern/KenshiLib/Include/kenshi/faction.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| addListMuto | integer | RW | `obj.addListMuto = <value>` |
| participants | lektor<Faction*> | RW | `obj.participants = <value>` |
| toAddList | lektor<Platoon*> | RW | `obj.toAddList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionManager` | `obj:_CONSTRUCTOR()` |
| saveGameState | `` | `void` | `obj:saveGameState()` |
| savePlayerGameState | `` | `void` | `obj:savePlayerGameState()` |
| clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| activateUnloadedPlatoons | `` | `void` | `obj:activateUnloadedPlatoons()` |
| getOrCreateFaction | `id: string, name: string` | `Faction` | `obj:getOrCreateFaction(id, name)` |
| getFactionByName | `name: string` | `Faction` | `obj:getFactionByName(name)` |
| getFactionByStringID | `sid: string` | `Faction` | `obj:getFactionByStringID(sid)` |
| getEmptyFaction | `` | `Faction` | `obj:getEmptyFaction()` |
| setupAndLinkAllFactions | `` | `void` | `obj:setupAndLinkAllFactions()` |
| getFactionBySquad | `` | `Faction` | `obj:getFactionBySquad()` |
| getCampaignGUIInfos | `cat: integer, playeronly: boolean` | `void` | `obj:getCampaignGUIInfos(cat, playeronly)` |
| areAnyHostileCampaignsRunning | `` | `boolean` | `obj:areAnyHostileCampaignsRunning()` |
| getNumTempPlatoons | `` | `integer` | `obj:getNumTempPlatoons()` |
| updateMT | `time: number` | `void` | `obj:updateMT(time)` |
| updateThreaded | `time: number` | `void` | `obj:updateThreaded(time)` |
| _showDebugPlatoonMarkers | `on: boolean` | `void` | `obj:_showDebugPlatoonMarkers(on)` |
| getAllFactions | `` | `lightuserdata` | `obj:getAllFactions()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionRelations
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | Faction | RW | `obj.me = <value>` |
| playerRank | integer | RW | `obj.playerRank = <value>` |
| globalReputationTrust | number | RW | `obj.globalReputationTrust = <value>` |
| globalReputationForBadassery | number | RW | `obj.globalReputationForBadassery = <value>` |
| _factionRelations | unknown | RW | `obj._factionRelations = <value>` |
| defaultFactionRelation | number | RW | `obj.defaultFactionRelation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionRelations` | `obj:_CONSTRUCTOR()` |
| setupPhase2 | `` | `void` | `obj:setupPhase2()` |
| isEnemyByDefault | `` | `boolean` | `obj:isEnemyByDefault()` |
| reset | `` | `void` | `obj:reset()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setupPhase1 | `` | `void` | `obj:setupPhase1()` |
| save | `` | `void` | `obj:save()` |
| _NV_save | `` | `void` | `obj:_NV_save()` |
| load | `playerOnly: boolean` | `void` | `obj:load(playerOnly)` |
| _NV_load | `playerOnly: boolean` | `void` | `obj:_NV_load(playerOnly)` |
| _isAlly | `` | `boolean` | `obj:_isAlly()` |
| _isEnemy | `` | `boolean` | `obj:_isEnemy()` |
| isEnemy | `` | `boolean` | `obj:isEnemy()` |
| setEnemy | `` | `void` | `obj:setEnemy()` |
| _NV_setEnemy | `` | `void` | `obj:_NV_setEnemy()` |
| isAlly | `` | `boolean` | `obj:isAlly()` |
| isCoexisting | `` | `boolean` | `obj:isCoexisting()` |
| getFactionRelation | `` | `number` | `obj:getFactionRelation()` |
| getFactionRelationMultiplier | `` | `number` | `obj:getFactionRelationMultiplier()` |
| getFactionRelationMultiplierInverse | `` | `number` | `obj:getFactionRelationMultiplierInverse()` |
| setRelation | `setTo: number` | `void` | `obj:setRelation(setTo)` |
| affectRelations | `amount: number, mult: number` | `void` | `obj:affectRelations(amount, mult)` |
| _NV_affectRelations | `amount: number, mult: number` | `void` | `obj:_NV_affectRelations(amount, mult)` |
| affectTrust | `amount: number, mult: number` | `void` | `obj:affectTrust(amount, mult)` |
| _NV_affectTrust | `amount: number, mult: number` | `void` | `obj:_NV_affectTrust(amount, mult)` |
| setNoLongerEnemies | `` | `void` | `obj:setNoLongerEnemies()` |
| _NV_setNoLongerEnemies | `` | `void` | `obj:_NV_setNoLongerEnemies()` |
| declareWar | `` | `void` | `obj:declareWar()` |
| _NV_declareWar | `` | `void` | `obj:_NV_declareWar()` |
| affectReputation | `amount: number` | `void` | `obj:affectReputation(amount)` |
| _NV_affectReputation | `amount: number` | `void` | `obj:_NV_affectReputation(amount)` |
| getRelationData | `` | `FactionRelations::RelationData` | `obj:getRelationData()` |
| _NV_getRelationData | `` | `FactionRelations::RelationData` | `obj:_NV_getRelationData()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| getRelationsData | `` | `void` | `obj:getRelationsData()` |
| checkStateCondition | `conditionName: integer, compareBy: integer, val: integer` | `boolean` | `obj:checkStateCondition(conditionName, compareBy, val)` |

## FactionRelationsLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| faction | Faction | RW | `obj.faction = <value>` |
| value | number | RW | `obj.value = <value>` |
| valueText | lightuserdata | R | `obj.valueText` |
| leftBar | lightuserdata | R | `obj.leftBar` |
| rightBar | lightuserdata | R | `obj.rightBar` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionRelationsLine` | `obj:_CONSTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionUniqueSquadManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| prosperityMgr | ProsperityManager | RW | `obj.prosperityMgr = <value>` |
| me | Faction | RW | `obj.me = <value>` |
| squadListData | GameData | RW | `obj.squadListData = <value>` |
| homeTown | Town | RW | `obj.homeTown = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionUniqueSquadManager` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAndReset | `` | `void` | `obj:clearAndReset()` |
| initialiseNew | `` | `void` | `obj:initialiseNew()` |
| chooseRandomSquadToSpawn | `time: number` | `GameData` | `obj:chooseRandomSquadToSpawn(time)` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| serialise | `` | `void` | `obj:serialise()` |
| load | `import: boolean` | `void` | `obj:load(import)` |
| getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| getExistingSquadsFor | `` | `lightuserdata` | `obj:getExistingSquadsFor()` |
| spawnNewUniqueSquad | `` | `lightuserdata` | `obj:spawnNewUniqueSquad()` |

## FactionWarMgr
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | Faction | RW | `obj.me = <value>` |
| lastID | integer | RW | `obj.lastID = <value>` |
| nextUpdateTime | TimeOfDay | RW | `obj.nextUpdateTime = <value>` |
| myTowns | lektor<TownBase*> | RW | `obj.myTowns = <value>` |
| hiredForces | lektor<hand> | RW | `obj.hiredForces = <value>` |
| activeCampaigns | lightuserdata | RW | `obj.activeCampaigns = <value>` |
| biomeTerritories | lightuserdata | RW | `obj.biomeTerritories = <value>` |
| biomeNoGoZones | lightuserdata | RW | `obj.biomeNoGoZones = <value>` |
| campaignRequests | lightuserdata | RW | `obj.campaignRequests = <value>` |
| possibleCampaigns | lightuserdata | RW | `obj.possibleCampaigns = <value>` |
| forces | lightuserdata | RW | `obj.forces = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionWarMgr` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| reset | `` | `void` | `obj:reset()` |
| save | `` | `void` | `obj:save()` |
| load | `` | `void` | `obj:load()` |
| removePlatoon | `` | `void` | `obj:removePlatoon()` |
| addPlatoon | `` | `void` | `obj:addPlatoon()` |
| getGUIData | `cat: integer, playeronly: boolean` | `void` | `obj:getGUIData(cat, playeronly)` |
| areAnyHostileCampaignsRunning | `playeronly: boolean` | `boolean` | `obj:areAnyHostileCampaignsRunning(playeronly)` |
| endCampaign | `c: userdata` | `void` | `obj:endCampaign(c)` |
| getAllTheForces | `c: userdata` | `void` | `obj:getAllTheForces(c)` |
| _generateForcesForTown | `c: userdata` | `void` | `obj:_generateForcesForTown(c)` |
| canGenerateThisManyForces | `num: integer` | `boolean` | `obj:canGenerateThisManyForces(num)` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| debugButton | `` | `void` | `obj:debugButton()` |
| triggerCampaign | `data: userdata, minTime: number, forceDuplicate: boolean, forceDuplicate: boolean` | `lightuserdata` | `obj:triggerCampaign(data, minTime, forceDuplicate, forceDuplicate)` |
| getCurrentCampaign | `` | `lightuserdata` | `obj:getCurrentCampaign()` |
| getAITarget | `` | `void` | `obj:getAITarget()` |
| getMyUnloadedAI | `` | `integer` | `obj:getMyUnloadedAI()` |
| isBiomeHomeTerritory | `area: userdata` | `boolean` | `obj:isBiomeHomeTerritory(area)` |
| getNearestTown | `p: Vector3` | `TownBase` | `obj:getNearestTown(p)` |
| getTownsInBiome | `b: userdata` | `void` | `obj:getTownsInBiome(b)` |
| getMyTownsWithEnoughFreePopulation | `popNeeded: integer` | `void` | `obj:getMyTownsWithEnoughFreePopulation(popNeeded)` |
| getActiveCampaign | `uniqueID: integer` | `lightuserdata` | `obj:getActiveCampaign(uniqueID)` |
| setup | `` | `void` | `obj:setup()` |
| _createCampaignData | `` | `lightuserdata` | `obj:_createCampaignData()` |

## Faction_CharacteristicsData
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `fleeRatio_relativeEnemy: number` | `Faction::CharacteristicsData` | `obj:_CONSTRUCTOR(fleeRatio_relativeEnemy)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactionsScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mainWidget | lightuserdata | R | `obj.mainWidget` |
| selectedFaction | Faction | RW | `obj.selectedFaction = <value>` |
| scrollList | lightuserdata | RW | `obj.scrollList = <value>` |
| scrollListItemTop | integer | RW | `obj.scrollListItemTop = <value>` |
| scrollListItemWidth | integer | RW | `obj.scrollListItemWidth = <value>` |
| nameText | lightuserdata | R | `obj.nameText` |
| infoPanel | DatapanelGUI | RW | `obj.infoPanel = <value>` |
| updateTimer | number | RW | `obj.updateTimer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| clear | `` | `void` | `obj:clear()` |
| update | `` | `void` | `obj:update()` |
| refresh | `` | `void` | `obj:refresh()` |
| updateInfo | `` | `void` | `obj:updateInfo()` |

## FactionsScreen_FactionRelationsLine_LessSort
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FactionsScreen::FactionRelationsLine::LessSort` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FactoryCallbackInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _CONSTRUCTOR | `` | `FactoryCallbackInterface` | `obj:_CONSTRUCTOR()` |

## FarmBatch
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| plantSource | lektor<FarmBuilding::PlantSource*> | R | `obj.plantSource` |
| plantGroups | lektor<int> | RW | `obj.plantGroups = <value>` |
| geometry | Ogre::SharedPtr<Ogre::Mesh> | R | `obj.geometry` |
| height | number | RW | `obj.height = <value>` |
| size | integer | RW | `obj.size = <value>` |
| meshesLoaded | integer | RW | `obj.meshesLoaded = <value>` |
| farms | lektor<FarmBuilding*> | RW | `obj.farms = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| load | `` | `void` | `obj:load()` |
| createGeometry | `` | `void` | `obj:createGeometry()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FarmBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cropMultipliers | ogre_unordered_map<CropType, float>::type | R | `obj.cropMultipliers` |
| material | Ogre::SharedPtr<Ogre::Material> | R | `obj.material` |
| plantEntity | lightuserdata | R | `obj.plantEntity` |
| plants | lektor<FarmBuilding::Plant> | R | `obj.plants` |
| clickHull | lightuserdata | R | `obj.clickHull` |
| batch | lightuserdata | R | `obj.batch` |
| lastUpdated | number | RW | `obj.lastUpdated = <value>` |
| eatingTime | number | RW | `obj.eatingTime = <value>` |
| grown | number | RW | `obj.grown = <value>` |
| died | number | RW | `obj.died = <value>` |
| cleared | number | RW | `obj.cleared = <value>` |
| growStart | number | RW | `obj.growStart = <value>` |
| harvested | integer | RW | `obj.harvested = <value>` |
| itemsPerPlant | number | RW | `obj.itemsPerPlant = <value>` |
| clearRate | number | RW | `obj.clearRate = <value>` |
| consumptionRate | number | RW | `obj.consumptionRate = <value>` |
| harvestRate | number | RW | `obj.harvestRate = <value>` |
| growthTime | number | RW | `obj.growthTime = <value>` |
| harvestTime | number | RW | `obj.harvestTime = <value>` |
| deathTime | number | RW | `obj.deathTime = <value>` |
| droughtTime | number | RW | `obj.droughtTime = <value>` |
| deathThreshold | number | RW | `obj.deathThreshold = <value>` |
| droughtMultiplier | number | RW | `obj.droughtMultiplier = <value>` |
| fertilityMultiplier | number | RW | `obj.fertilityMultiplier = <value>` |
| isHydroponic | boolean | RW | `obj.isHydroponic = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| _NV_howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:_NV_howMuchPowerDoYouWantForSortingFunction()` |
| setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| _NV_setupMiningResourceLevel | `` | `void` | `obj:_NV_setupMiningResourceLevel()` |
| destroyAPlant | `` | `boolean` | `obj:destroyAPlant()` |
| timeSkip | `h: number, ignoreWater: boolean` | `void` | `obj:timeSkip(h, ignoreWater)` |
| _updateInputs | `rate: number` | `boolean` | `obj:_updateInputs(rate)` |
| isCropsEdible | `` | `boolean` | `obj:isCropsEdible()` |
| eat | `rate: number` | `void` | `obj:eat(rate)` |
| getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| _NV_getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getDirectionMarker(currentPosition)` |
| dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| _NV_dontNeedWorkRightNow | `` | `boolean` | `obj:_NV_dontNeedWorkRightNow()` |
| setupMaterial | `` | `void` | `obj:setupMaterial()` |
| updateMaterial | `` | `void` | `obj:updateMaterial()` |
| resetFarm | `` | `void` | `obj:resetFarm()` |

## FarmBuilding_Plant
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `arg1: unknown` | `FarmBuilding::Plant` | `obj:_CONSTRUCTOR(arg1)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FarmBuilding_PlantSource
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `scaleStart: number, scaleEnd: number, scaleVariance: number, offsetStart: number, offsetEnd: number, delay: number, delayScale: number, isStatic: boolean, count: integer, group: integer` | `FarmBuilding::PlantSource` | `obj:_CONSTRUCTOR(scaleStart, scaleEnd, scaleVariance, offsetStart, offsetEnd, delay, delayScale, isStatic, count, group)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FarmBuilding_SubPlant
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FarmBuilding::SubPlant` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FlagCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | integer | RW | `obj.key = <value>` |
| want | boolean | RW | `obj.want = <value>` |
| flags | integer | RW | `obj.flags = <value>` |

## FloatingProgressBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| caption | string | RW | `obj.caption = <value>` |
| progress | integer | RW | `obj.progress = <value>` |
| bar | lightuserdata | R | `obj.bar` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FloatingProgressBar` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setProgress | `value: number` | `void` | `obj:setProgress(value)` |
| setCaption | `value: string` | `void` | `obj:setCaption(value)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |

## FlockingTools
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| getOutOfTheWayOfCharacter | unknown | RW | `obj.getOutOfTheWayOfCharacter = <value>` |
| currentPosition | Vector3 | RW | `obj.currentPosition = <value>` |
| me | Character | RW | `obj.me = <value>` |
| combatMover | CombatMovementController | RW | `obj.combatMover = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FlockingTools` | `obj:_CONSTRUCTOR()` |
| create | `` | `void` | `obj:create()` |
| getDistanceToClosestCharacter | `enemies: boolean, allies: boolean` | `number` | `obj:getDistanceToClosestCharacter(enemies, allies)` |
| getOutOfTheWay | `` | `void` | `obj:getOutOfTheWay()` |
| setCurrentPosition | `_pos: Vector3` | `void` | `obj:setCurrentPosition(_pos)` |
| getRepulsionMagnitude | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `number` | `obj:getRepulsionMagnitude(repulsionPoint, MAX_DISTANCE, distance)` |
| getRepulsionVector | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `Vector3` | `obj:getRepulsionVector(repulsionPoint, MAX_DISTANCE, distance)` |
| clampRepulsionVectorTo90Degrees | `desiredDirection: Vector3, alwaysStrafe: boolean` | `Vector3` | `obj:clampRepulsionVectorTo90Degrees(desiredDirection, alwaysStrafe)` |
| calculateCurrentRepulsionVector | `MAX_DISTANCE: number, desiredDirection: Vector3, includeEnemies: boolean, includeFriends: boolean, strafeOnly: boolean` | `Vector3` | `obj:calculateCurrentRepulsionVector(MAX_DISTANCE, desiredDirection, includeEnemies, includeFriends, strafeOnly)` |
| getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |

## FogEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/FogEditor.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | lightuserdata | R | `obj.window` |
| fogList | lightuserdata | R | `obj.fogList` |
| typeList | lightuserdata | R | `obj.typeList` |
| panel | DatapanelGUI | RW | `obj.panel = <value>` |
| selectedFog | lightuserdata | R | `obj.selectedFog` |
| selectedSide | integer | RW | `obj.selectedSide = <value>` |
| colour | Vector3 | RW | `obj.colour = <value>` |
| distance | number | RW | `obj.distance = <value>` |
| radius | number | RW | `obj.radius = <value>` |
| edge | number | RW | `obj.edge = <value>` |
| editCage | lightuserdata | R | `obj.editCage` |
| editNode | lightuserdata | R | `obj.editNode` |
| editPos | Vector3 | RW | `obj.editPos = <value>` |
| editRot | Quaternion | RW | `obj.editRot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| show | `` | `void` | `obj:show()` |
| close | `` | `void` | `obj:close()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| update | `` | `boolean` | `obj:update()` |
| save | `filename: string` | `void` | `obj:save(filename)` |
| updateFogName | `` | `void` | `obj:updateFogName()` |
| updateFogValues | `` | `void` | `obj:updateFogValues()` |
| selectNextEdge | `` | `void` | `obj:selectNextEdge()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## FoliageSystem
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| reloaded | boolean | RW | `obj.reloaded = <value>` |
| generateOverlay | boolean | RW | `obj.generateOverlay = <value>` |
| firstTimeLoad | boolean | RW | `obj.firstTimeLoad = <value>` |
| collisionHash | integer | RW | `obj.collisionHash = <value>` |
| loadComplete | boolean | RW | `obj.loadComplete = <value>` |
| zoneMap | ZoneMap | RW | `obj.zoneMap = <value>` |
| coverageMap | lightuserdata | R | `obj.coverageMap` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `firstTimeLoad: boolean, buildOverlay: boolean, reloadData: boolean` | `lightuserdata` | `obj:_CONSTRUCTOR(firstTimeLoad, buildOverlay, reloadData)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| getCollisionHash | `` | `integer` | `obj:getCollisionHash()` |
| setupGrass | `paged: userdata, grassLoader: userdata, biomeCode: integer` | `void` | `obj:setupGrass(paged, grassLoader, biomeCode)` |
| setupFoliage | `paged: userdata, treeLoader: userdata, biomeCode: integer` | `void` | `obj:setupFoliage(paged, treeLoader, biomeCode)` |
| spawn | `ent: userdata, position: Vector3, _treeLoader: userdata` | `boolean` | `obj:spawn(ent, position, _treeLoader)` |
| randomInt | `min: integer, max: integer` | `integer` | `obj:randomInt(min, max)` |
| random | `min: number, max: number` | `number` | `obj:random(min, max)` |

## Footprint
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| wantsAboveGround | boolean | RW | `obj.wantsAboveGround = <value>` |
| lower | number | RW | `obj.lower = <value>` |
| space | number | RW | `obj.space = <value>` |
| scale | number | RW | `obj.scale = <value>` |
| ent | lightuserdata | R | `obj.ent` |
| pos | Vector3 | RW | `obj.pos = <value>` |
| rot | Quaternion | RW | `obj.rot = <value>` |
| groundType | integer | RW | `obj.groundType = <value>` |
| valid | boolean | RW | `obj.valid = <value>` |
| parent | PreviewBuilding | RW | `obj.parent = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getSpace | `` | `number` | `obj:getSpace()` |
| getMarker | `` | `number` | `obj:getMarker()` |
| setValid | `value: boolean` | `void` | `obj:setValid(value)` |
| getValid | `` | `boolean` | `obj:getValid()` |
| validate | `` | `boolean` | `obj:validate()` |
| fakeOppositeValidate | `gap: number` | `boolean` | `obj:fakeOppositeValidate(gap)` |
| collisionTestBuildings | `isFurniture: boolean, currentFloor: integer` | `boolean` | `obj:collisionTestBuildings(isFurniture, currentFloor)` |
| collisionTestCharacters | `` | `boolean` | `obj:collisionTestCharacters()` |
| validFloorTest | `` | `boolean` | `obj:validFloorTest()` |
| isIndoorsOK | `isFurniture: boolean` | `boolean` | `obj:isIndoorsOK(isFurniture)` |
| isGroundValid | `` | `boolean` | `obj:isGroundValid()` |
| getWorldCorner | `corner: integer` | `Vector3` | `obj:getWorldCorner(corner)` |
| updateBox | `` | `void` | `obj:updateBox()` |
| _NV_updateBox | `` | `void` | `obj:_NV_updateBox()` |
| getGroundHeight | `pos: Vector3` | `number` | `obj:getGroundHeight(pos)` |

## FootprintNode
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nodeId | string | RW | `obj.nodeId = <value>` |
| enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateBox | `` | `void` | `obj:updateBox()` |
| _NV_updateBox | `` | `void` | `obj:_NV_updateBox()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ForgottenGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ForgottenGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| hasMouse | boolean | RW | `obj.hasMouse = <value>` |
| mainbar | MainBarGUI | RW | `obj.mainbar = <value>` |
| tooltip | ToolTip | RW | `obj.tooltip = <value>` |
| dialogue | DialogueWindow | RW | `obj.dialogue = <value>` |
| tutorial | TutorialGUI | RW | `obj.tutorial = <value>` |
| tutorialpedia | TutorialpediaGUI | RW | `obj.tutorialpedia = <value>` |
| currentCursor | integer | RW | `obj.currentCursor = <value>` |
| Scale | unknown | RW | `obj.Scale = <value>` |
| manager | lightuserdata | R | `obj.manager` |
| guiPlatform | lightuserdata | R | `obj.guiPlatform` |
| _closeTradeWindowMsg | boolean | RW | `obj._closeTradeWindowMsg = <value>` |
| tradeA | unknown | RW | `obj.tradeA = <value>` |
| tradeB | unknown | RW | `obj.tradeB = <value>` |
| inventoryWindowBuilding | unknown | RW | `obj.inventoryWindowBuilding = <value>` |
| inventoryWindowCharacter | unknown | RW | `obj.inventoryWindowCharacter = <value>` |
| inventoryWindowTrader | unknown | RW | `obj.inventoryWindowTrader = <value>` |
| inventoryWindowNPC | unknown | RW | `obj.inventoryWindowNPC = <value>` |
| characterEditor | CharacterEditWindow | RW | `obj.characterEditor = <value>` |
| guiScreenLabelsMutex | lightuserdata | R | `obj.guiScreenLabelsMutex` |
| selectedObject | unknown | RW | `obj.selectedObject = <value>` |
| selectedPlayerCharacter | unknown | RW | `obj.selectedPlayerCharacter = <value>` |
| cursorPanel | DatapanelGUI | RW | `obj.cursorPanel = <value>` |
| cursorAction | boolean | RW | `obj.cursorAction = <value>` |
| cursorActionPlayer | unknown | RW | `obj.cursorActionPlayer = <value>` |
| cursorActionTarget | unknown | RW | `obj.cursorActionTarget = <value>` |
| visible | boolean | RW | `obj.visible = <value>` |
| created | boolean | RW | `obj.created = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ForgottenGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearGUI | `` | `void` | `obj:clearGUI()` |
| shutDown | `` | `void` | `obj:shutDown()` |
| restart | `` | `void` | `obj:restart()` |
| setupGuiScaling | `` | `void` | `obj:setupGuiScaling()` |
| init | `` | `void` | `obj:init()` |
| getTopOfScreenMessagePosition | `` | `number` | `obj:getTopOfScreenMessagePosition()` |
| showLoadingMessage | `on: boolean` | `void` | `obj:showLoadingMessage(on)` |
| isLoadingMessageVisible | `` | `boolean` | `obj:isLoadingMessageVisible()` |
| showPauseMessage | `on: boolean` | `void` | `obj:showPauseMessage(on)` |
| isLoading | `` | `boolean` | `obj:isLoading()` |
| setLoading | `value: boolean` | `void` | `obj:setLoading(value)` |
| isPaused | `` | `boolean` | `obj:isPaused()` |
| inDialogue | `` | `boolean` | `obj:inDialogue()` |
| hideMessageBox | `enter: boolean` | `boolean` | `obj:hideMessageBox(enter)` |
| hasModalMessage | `` | `boolean` | `obj:hasModalMessage()` |
| showMainbar | `on: boolean` | `void` | `obj:showMainbar(on)` |
| updateBountyPanelVisibility | `` | `void` | `obj:updateBountyPanelVisibility()` |
| getInDialogue | `` | `boolean` | `obj:getInDialogue()` |
| getToolTip | `` | `ToolTip` | `obj:getToolTip()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| toggle | `` | `void` | `obj:toggle()` |
| showNames | `on: boolean` | `void` | `obj:showNames(on)` |
| showPrintOutput | `v: boolean` | `void` | `obj:showPrintOutput(v)` |
| closeCharacterEditor | `` | `void` | `obj:closeCharacterEditor()` |
| isCharacterEditorMode | `` | `boolean` | `obj:isCharacterEditorMode()` |
| closeAllCharacterStatsWindows | `` | `void` | `obj:closeAllCharacterStatsWindows()` |
| isStatsWindowOpen | `` | `boolean` | `obj:isStatsWindowOpen()` |
| characterStatsWindowVisible | `` | `boolean` | `obj:characterStatsWindowVisible()` |
| selectedObjectsChanged | `` | `void` | `obj:selectedObjectsChanged()` |
| updateToOrdersPanel | `` | `void` | `obj:updateToOrdersPanel()` |
| notifyTownDeleted | `` | `void` | `obj:notifyTownDeleted()` |
| update | `` | `void` | `obj:update()` |
| closeTradeWindow | `` | `void` | `obj:closeTradeWindow()` |
| closeInventoryBuilding | `` | `void` | `obj:closeInventoryBuilding()` |
| closeAllInventories | `` | `void` | `obj:closeAllInventories()` |
| closeAllWindows | `` | `void` | `obj:closeAllWindows()` |
| getNumOpenInventoryWindows | `` | `integer` | `obj:getNumOpenInventoryWindows()` |
| getInventoryWindowWithMouse | `` | `InventoryGUI` | `obj:getInventoryWindowWithMouse()` |
| isAnyInventoryWindowOpen | `` | `boolean` | `obj:isAnyInventoryWindowOpen()` |
| toggleHelpWindow | `` | `void` | `obj:toggleHelpWindow()` |
| addWindowToUpdateList | `` | `void` | `obj:addWindowToUpdateList()` |
| removeWindowFromUpdateList | `` | `void` | `obj:removeWindowFromUpdateList()` |
| addDatapanelToUpdateList | `` | `void` | `obj:addDatapanelToUpdateList()` |
| removeDatapanelFromUpdateList | `` | `void` | `obj:removeDatapanelFromUpdateList()` |
| setMouseCursorVisible | `visible: boolean` | `void` | `obj:setMouseCursorVisible(visible)` |
| getGuiManager | `` | `lightuserdata` | `obj:getGuiManager()` |
| createPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanel(name, top, left, width, height, layer, skin)` |
| createPanelAbs | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanelAbs(name, top, left, width, height, layer, skin)` |
| createTabPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createTabPanel(name, top, left, width, height, layer, skin)` |
| createFloatingImage | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImage(image, top, left, width, height, layer)` |
| createFloatingImageAbs | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImageAbs(image, top, left, width, height, layer)` |
| createFloatingProgressBar | `` | `FloatingProgressBar` | `obj:createFloatingProgressBar()` |
| createScreenLabelD | `text: string, time: number` | `lightuserdata` | `obj:createScreenLabelD(text, time)` |

## FormationMover
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | Character | RW | `obj.me = <value>` |
| destination | Vector3 | RW | `obj.destination = <value>` |
| direction | Vector3 | RW | `obj.direction = <value>` |
| movementTarget | unknown | RW | `obj.movementTarget = <value>` |
| currentFormationID | integer | RW | `obj.currentFormationID = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `FormationMover` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| getSpeeds | `motion: Vector3, frameTime: number` | `number` | `obj:getSpeeds(motion, frameTime)` |
| setFormationMode | `` | `void` | `obj:setFormationMode()` |
| stopFormationMode | `` | `void` | `obj:stopFormationMode()` |

## FurnaceBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| active | boolean | RW | `obj.active = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| getInputValueTotal | `` | `number` | `obj:getInputValueTotal()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateInputs | `rate: number` | `void` | `obj:updateInputs(rate)` |
| _NV_updateInputs | `rate: number` | `void` | `obj:_NV_updateInputs(rate)` |
| updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| _NV_updateOutput | `rate: number` | `void` | `obj:_NV_updateOutput(rate)` |

## FurnaceInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `title: string, ins: integer, outs: integer` | `lightuserdata` | `obj:_CONSTRUCTOR(title, ins, outs)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GUIWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GUIWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | MyGUI::Widget | R | `obj.win` |
| selectedObject | unknown | RW | `obj.selectedObject = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GUIWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| show | `_a1: boolean` | `void` | `obj:show(_a1)` |
| setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| _NV_setPositionReal | `x: number, y: number` | `void` | `obj:_NV_setPositionReal(x, y)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| _NV_setPosition | `x: integer, y: integer` | `void` | `obj:_NV_setPosition(x, y)` |
| getWidth | `` | `integer` | `obj:getWidth()` |
| _NV_getWidth | `` | `integer` | `obj:_NV_getWidth()` |
| getHeight | `` | `integer` | `obj:getHeight()` |
| _NV_getHeight | `` | `integer` | `obj:_NV_getHeight()` |
| getWidthReal | `` | `number` | `obj:getWidthReal()` |
| _NV_getWidthReal | `` | `number` | `obj:_NV_getWidthReal()` |
| getHeightReal | `` | `number` | `obj:getHeightReal()` |
| _NV_getHeightReal | `` | `number` | `obj:_NV_getHeightReal()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| autoChangeSelectedObject | `` | `void` | `obj:autoChangeSelectedObject()` |
| _NV_autoChangeSelectedObject | `` | `void` | `obj:_NV_autoChangeSelectedObject()` |
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
| resize | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |
| _NV_resize | `w: integer, h: integer` | `void` | `obj:_NV_resize(w, h)` |

## GameData
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| validity | integer | RW | `obj.validity = <value>` |
| sourceContainer | GameDataContainer | RW | `obj.sourceContainer = <value>` |
| isStandalone | boolean | RW | `obj.isStandalone = <value>` |
| id | integer | RW | `obj.id = <value>` |
| readOnly | boolean | RW | `obj.readOnly = <value>` |
| name | string | RW | `obj.name = <value>` |
| type | integer | RW | `obj.type = <value>` |
| stringID | string | RW | `obj.stringID = <value>` |
| isFromActiveFile | boolean | RW | `obj.isFromActiveFile = <value>` |
| currentID | integer | RW | `obj.currentID = <value>` |
| createdIndex | integer | RW | `obj.createdIndex = <value>` |
| activeValues | unknown | RW | `obj.activeValues = <value>` |
| bdata | unknown | RW | `obj.bdata = <value>` |
| sdata | unknown | RW | `obj.sdata = <value>` |
| idata | unknown | RW | `obj.idata = <value>` |
| fdata | unknown | RW | `obj.fdata = <value>` |
| filesdata | unknown | RW | `obj.filesdata = <value>` |
| vecdata | unknown | RW | `obj.vecdata = <value>` |
| quatdata | unknown | RW | `obj.quatdata = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | `` | `GameData` | `obj:_CONSTRUCTOR()` |
| isValid | `` | `boolean` | `obj:isValid()` |
| getSourceContainer | `` | `GameDataContainer` | `obj:getSourceContainer()` |
| destroy | `` | `void` | `obj:destroy()` |
| initialise | `t: integer, isActive: boolean` | `void` | `obj:initialise(t, isActive)` |
| loadFromFile | `path: string, _type: integer` | `boolean` | `obj:loadFromFile(path, _type)` |
| saveToFile | `path: string` | `boolean` | `obj:saveToFile(path)` |
| storeHandleList | `name: string` | `void` | `obj:storeHandleList(name)` |
| storeHandle | `name: string, redirect: boolean` | `void` | `obj:storeHandle(name, redirect)` |
| getHandle | `name: string` | `void` | `obj:getHandle(name)` |
| updateFrom | `mod: boolean` | `boolean` | `obj:updateFrom(mod)` |
| isValueActive | `v: string` | `boolean` | `obj:isValueActive(v)` |
| isRefActive | `v: string` | `boolean` | `obj:isRefActive(v)` |
| addFileName | `n: string, v: string, filestype: string, category: string, vis: boolean` | `void` | `obj:addFileName(n, v, filestype, category, vis)` |
| addString | `n: string, v: string, category: string, vis: boolean` | `void` | `obj:addString(n, v, category, vis)` |
| add | `n: string, v: number, vis: boolean, isSlider: boolean` | `void` | `obj:add(n, v, vis, isSlider)` |
| getGameDataReferenceObject | `list: string, id: string` | `GameDataReference` | `obj:getGameDataReferenceObject(list, id)` |
| addToList | `list: string, id: string, val: integer, val2: integer, val3: integer` | `void` | `obj:addToList(list, id, val, val2, val3)` |
| removeFromList | `list: string, id: string` | `void` | `obj:removeFromList(list, id)` |
| findInList | `list: string, SID: string` | `boolean` | `obj:findInList(list, SID)` |
| clearList | `n: string` | `void` | `obj:clearList(n)` |
| clearEverything | `` | `void` | `obj:clearEverything()` |
| clearInstances | `` | `void` | `obj:clearInstances()` |
| getFromList | `n: string, index: integer` | `string` | `obj:getFromList(n, index)` |
| getFromList_random | `n: string` | `string` | `obj:getFromList_random(n)` |
| getListSize | `n: string` | `integer` | `obj:getListSize(n)` |
| listExists | `n: string` | `boolean` | `obj:listExists(n)` |
| listExistsAndNotEmpty | `n: string` | `boolean` | `obj:listExistsAndNotEmpty(n)` |
| getAllFromList | `n: string` | `void` | `obj:getAllFromList(n)` |
| getReferenceList | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceList(listname)` |
| getReferenceListIfExists | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceListIfExists(listname)` |
| _getReferenceList_nonConst | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:_getReferenceList_nonConst(listname)` |
| getFromListAsData | `n: string, index: integer, type: integer` | `GameData` | `obj:getFromListAsData(n, index, type)` |
| getValueFromList | `list: string, index: integer` | `void` | `obj:getValueFromList(list, index)` |
| deleteInstancedObject | `id: string, modIndex: integer` | `void` | `obj:deleteInstancedObject(id, modIndex)` |
| getNewID | `` | `integer` | `obj:getNewID()` |
| getColorVec | `name: string` | `Vector3` | `obj:getColorVec(name)` |
| addDeletedInstance | `instanceID: string` | `void` | `obj:addDeletedInstance(instanceID)` |

## GameDataContainer
**Header:** `extern/KenshiLib/Include/kenshi/gamedatamanager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentID | integer | RW | `obj.currentID = <value>` |
| name | string | RW | `obj.name = <value>` |
| isBaseDatafile | boolean | RW | `obj.isBaseDatafile = <value>` |
| readOnly | boolean | RW | `obj.readOnly = <value>` |
| gamedataID | unknown | RW | `obj.gamedataID = <value>` |
| gamedataSID | GameDataSIDMap | RW | `obj.gamedataSID = <value>` |
| mainList | ogre_unordered_set<GameData*>::type | RW | `obj.mainList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GameDataContainer` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createNewData | `type: integer, forceID: string, name: string` | `GameData` | `obj:createNewData(type, forceID, name)` |
| getDataByName | `dataName: string, category: integer` | `GameData` | `obj:getDataByName(dataName, category)` |
| renameData | `n: string` | `void` | `obj:renameData(n)` |
| removeData | `` | `void` | `obj:removeData()` |
| removeDuplicatesOf | `` | `void` | `obj:removeDuplicatesOf()` |
| removeAllDataOfType | `type: integer` | `void` | `obj:removeAllDataOfType(type)` |
| clearInstances | `` | `void` | `obj:clearInstances()` |
| clearButDontDestroy | `` | `void` | `obj:clearButDontDestroy()` |
| clearButDontDestroyPlatoons | `` | `void` | `obj:clearButDontDestroyPlatoons()` |
| clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| getNewID | `` | `integer` | `obj:getNewID()` |
| destroyData | `` | `void` | `obj:destroyData()` |
| preLoadAllReferencePtrs | `` | `void` | `obj:preLoadAllReferencePtrs()` |
| clearAllReferencePtrs | `` | `void` | `obj:clearAllReferencePtrs()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| checkForDuplicates | `` | `void` | `obj:checkForDuplicates()` |
| addNewData | `dat: string` | `void` | `obj:addNewData(dat)` |
| getData | `sid: string, category: integer` | `GameData` | `obj:getData(sid, category)` |
| getDataOfType | `type: integer` | `void` | `obj:getDataOfType(type)` |
| _getAllData | `` | `void` | `obj:_getAllData()` |
| loadGameDataReturn | `file: string, isActive: boolean, readOnly: boolean, moreData: userdata` | `boolean` | `obj:loadGameDataReturn(file, isActive, readOnly, moreData)` |
| load | `filename: string, modName: string, modIndex: integer, moreData: userdata, keepDeletedInstances: boolean` | `boolean` | `obj:load(filename, modName, modIndex, moreData, keepDeletedInstances)` |
| save | `filename: string, moreData: userdata` | `boolean` | `obj:save(filename, moreData)` |
| flushKillList | `` | `void` | `obj:flushKillList()` |
| destroyHomelessData | `` | `void` | `obj:destroyHomelessData()` |
| findAllDataThatReferencesThis | `ofType: integer, listname: string` | `void` | `obj:findAllDataThatReferencesThis(ofType, listname)` |
| _addToKillList | `` | `void` | `obj:_addToKillList()` |

## GameDataCopyStandalone
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GameDataCopyStandalone` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataEditorWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | DatapanelGUI | RW | `obj.win = <value>` |
| data | GameData | RW | `obj.data = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| initDataValues | `` | `void` | `obj:initDataValues()` |

## GameDataEditorWindow_DataItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GameDataEditorWindow::DataItem` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataGroup
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| g1 | GameData | R | `obj.g1` |
| g2 | GameData | R | `obj.g2` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## GameDataHeader
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |
| author | string | RW | `obj.author = <value>` |
| version | integer | RW | `obj.version = <value>` |
| description | string | RW | `obj.description = <value>` |
| dependencies | lektor<std::string> | RW | `obj.dependencies = <value>` |
| references | lektor<std::string> | RW | `obj.references = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `name: string, filename: string` | `GameDataHeader` | `obj:_CONSTRUCTOR(name, filename)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataManager
**Header:** `extern/KenshiLib/Include/kenshi/gamedatamanager.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GameDataManager` | `obj:_CONSTRUCTOR()` |
| reloadGameData | `filename: string, isActive: boolean, _baseData: boolean` | `boolean` | `obj:reloadGameData(filename, isActive, _baseData)` |
| postProcessingTheDatas | `` | `void` | `obj:postProcessingTheDatas()` |
| getMapSector | `x: integer, y: integer` | `GameData` | `obj:getMapSector(x, y)` |
| updateDatasOfType | `type: integer, isMod: boolean` | `void` | `obj:updateDatasOfType(type, isMod)` |
| updateData | `isMod: boolean` | `void` | `obj:updateData(isMod)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataReference
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| values | TripleInt | RW | `obj.values = <value>` |
| sid | string | RW | `obj.sid = <value>` |
| ptr | GameData | RW | `obj.ptr = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getPtr | `` | `GameData` | `obj:getPtr()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameDataValuePair
**Header:** `extern/KenshiLib/Include/kenshi/dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | GameData | RW | `obj.data = <value>` |
| val0 | integer | RW | `obj.val0 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `v: integer` | `GameDataValuePair` | `obj:_CONSTRUCTOR(v)` |

## GameSaveState
**Header:** `extern/KenshiLib/Include/kenshi/GameSaveState.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| baseData | GameData | RW | `obj.baseData = <value>` |
| dataSource | GameDataContainer | RW | `obj.dataSource = <value>` |
| firstTime | boolean | RW | `obj.firstTime = <value>` |
| instance | GameData::ObjectInstance | RW | `obj.instance = <value>` |
| pos | Vector3 | RW | `obj.pos = <value>` |
| rot | Quaternion | RW | `obj.rot = <value>` |
| instanceID | string | RW | `obj.instanceID = <value>` |
| states | StatesMapBinding::MapType | RW | `obj.states = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| generateNewInstanceID | `` | `void` | `obj:generateNewInstanceID()` |
| generateStateID | `type: integer` | `string` | `obj:generateStateID(type)` |
| createState | `type: integer` | `GameData` | `obj:createState(type)` |
| hasState | `type: integer` | `boolean` | `obj:hasState(type)` |
| getState | `type: integer` | `GameData` | `obj:getState(type)` |
| numStates | `` | `integer` | `obj:numStates()` |
| getPos | `` | `Vector3` | `obj:getPos()` |
| getRot | `` | `Quaternion` | `obj:getRot()` |
| getTheInstancesData | `` | `GameData` | `obj:getTheInstancesData()` |
| createFromSerialisedInstanceData | `id: string` | `void` | `obj:createFromSerialisedInstanceData(id)` |
| addState | `` | `void` | `obj:addState()` |
| getInstanceID | `` | `void` | `obj:getInstanceID()` |
| isValid | `` | `boolean` | `obj:isValid()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GameWorld
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| tempSpawnsDisableTimer | number | RW | `obj.tempSpawnsDisableTimer = <value>` |
| initialized | boolean | RW | `obj.initialized = <value>` |
| render | lightuserdata | R | `obj.render` |
| physics | PhysicsInterface | RW | `obj.physics = <value>` |
| gamedata | GameDataManager | RW | `obj.gamedata = <value>` |
| leveldata | GameDataManager | RW | `obj.leveldata = <value>` |
| savedata | GameDataManager | RW | `obj.savedata = <value>` |
| theFactory | RootObjectFactory | RW | `obj.theFactory = <value>` |
| factionMgr | FactionManager | RW | `obj.factionMgr = <value>` |
| navmesh | NavMesh | RW | `obj.navmesh = <value>` |
| nodeList | lightuserdata | R | `obj.nodeList` |
| guiDisplayObject | unknown | RW | `obj.guiDisplayObject = <value>` |
| messageRoller | lightuserdata | R | `obj.messageRoller` |
| ogreLogger | lightuserdata | R | `obj.ogreLogger` |
| steamEnabled | boolean | RW | `obj.steamEnabled = <value>` |
| player | PlayerInterface | RW | `obj.player = <value>` |
| frameSpeedMult | number | RW | `obj.frameSpeedMult = <value>` |
| deathParadeWasMeddledWith | boolean | RW | `obj.deathParadeWasMeddledWith = <value>` |
| charUpdateListMain_inUse | boolean | RW | `obj.charUpdateListMain_inUse = <value>` |
| _AINonRenderThread | lightuserdata | R | `obj._AINonRenderThread` |
| timeStamper | SimpleTimeStamper | RW | `obj.timeStamper = <value>` |
| zoneMgr | ZoneManager | RW | `obj.zoneMgr = <value>` |
| debugFlag | boolean | RW | `obj.debugFlag = <value>` |
| paused | boolean | RW | `obj.paused = <value>` |
| gameResetting | boolean | RW | `obj.gameResetting = <value>` |
| audioThread | lightuserdata | R | `obj.audioThread` |
| baseMods | lektor<ModInfo> | RW | `obj.baseMods = <value>` |
| baseModsNames | lektor<std::string> | RW | `obj.baseModsNames = <value>` |
| activeMods | lektor<ModInfo*> | RW | `obj.activeMods = <value>` |
| availableModsByName | AvailableModsMapBinding::MapType | RW | `obj.availableModsByName = <value>` |
| availabelModsOrderedList | lektor<ModInfo*> | RW | `obj.availabelModsOrderedList = <value>` |
| updatePortraitsMap | unknown | RW | `obj.updatePortraitsMap = <value>` |
| dynamicDestroyBuildingsList | lektor<hand> | RW | `obj.dynamicDestroyBuildingsList = <value>` |
| destroyListTBM | ogre_unordered_set<TownBuildingsManager*>::type | RW | `obj.destroyListTBM = <value>` |
| killListPhase0 | ogre_unordered_set<RootObject*>::type | RW | `obj.killListPhase0 = <value>` |
| killListPhase1 | unknown | RW | `obj.killListPhase1 = <value>` |
| mainUpdateListRemovalQueue | lektor<Character*> | RW | `obj.mainUpdateListRemovalQueue = <value>` |
| charactersWithLights | ogre_unordered_set<Character*>::type | RW | `obj.charactersWithLights = <value>` |
| deathParade | unknown | RW | `obj.deathParade = <value>` |
| charUpdateListMain | ogre_unordered_set<Character*>::type | RW | `obj.charUpdateListMain = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| justLoadFactionRelations | `` | `void` | `obj:justLoadFactionRelations()` |
| startUpThreads | `` | `boolean` | `obj:startUpThreads()` |
| start | `rend: userdata` | `boolean` | `obj:start(rend)` |
| destroy | `ptr: userdata, obj: boolean, debugInfo: string` | `boolean` | `obj:destroy(ptr, obj, debugInfo)` |
| _CONSTRUCTOR | `` | `GameWorld` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resetGame | `` | `void` | `obj:resetGame()` |
| _clearAndDestroyGameWorldStuff | `` | `void` | `obj:_clearAndDestroyGameWorldStuff()` |
| initialisation | `` | `boolean` | `obj:initialisation()` |
| initialisationGameData | `` | `boolean` | `obj:initialisationGameData()` |
| dailyUpdates | `` | `void` | `obj:dailyUpdates()` |
| initialiseNewGameWorld | `` | `void` | `obj:initialiseNewGameWorld()` |
| errorToLogReleaseMode | `msg: string` | `void` | `obj:errorToLogReleaseMode(msg)` |
| errorD | `msg: string` | `void` | `obj:errorD(msg)` |
| logToSave | `msg: string` | `void` | `obj:logToSave(msg)` |
| log | `line: string` | `void` | `obj:log(line)` |
| logDebug | `line: string, logname: string` | `void` | `obj:logDebug(line, logname)` |
| dynamicDestroyBuilding | `` | `void` | `obj:dynamicDestroyBuilding()` |
| getFromDeathParade | `` | `Character` | `obj:getFromDeathParade()` |
| addPortraitUpdate | `` | `void` | `obj:addPortraitUpdate()` |
| removePortaitUpdate | `` | `void` | `obj:removePortaitUpdate()` |
| getModsListFromConfig | `` | `lektor<ModInfo*>` | `obj:getModsListFromConfig()` |
| getAllModsList | `` | `lektor<ModInfo*>` | `obj:getAllModsList()` |
| getModLeveldataFolder | `modName: string` | `string` | `obj:getModLeveldataFolder(modName)` |
| getObjectsWithinSphere | `spherePos: Vector3, radius: number, type: integer, maxNumber: integer` | `void` | `obj:getObjectsWithinSphere(spherePos, radius, type, maxNumber)` |
| getCharactersWithinSphere | `spherePos: Vector3, farRadius: number, nearRadius: number, always: number, maxFar: integer, maxNear: integer` | `void` | `obj:getCharactersWithinSphere(spherePos, farRadius, nearRadius, always, maxFar, maxNear)` |
| getObjectsWithinBox | `pos: Vector3, size: Vector3, rot: Quaternion, type: integer, maxNumber: integer` | `void` | `obj:getObjectsWithinBox(pos, size, rot, type, maxNumber)` |
| getCharacterUpdateList | `` | `ogre_unordered_set<Character*>::type` | `obj:getCharacterUpdateList()` |
| sysMessage | `` | `void` | `obj:sysMessage()` |
| sysMessageUrgent | `` | `void` | `obj:sysMessageUrgent()` |
| sysMessage_noDuplicates | `` | `void` | `obj:sysMessage_noDuplicates()` |
| getCollisionGroupType | `type: integer` | `integer` | `obj:getCollisionGroupType(type)` |
| getTimeFromStamp | `stamp: number` | `number` | `obj:getTimeFromStamp(stamp)` |
| getIsInKillList | `` | `boolean` | `obj:getIsInKillList()` |
| flushKillList | `` | `void` | `obj:flushKillList()` |
| allThreadQueuesAreClear | `` | `boolean` | `obj:allThreadQueuesAreClear()` |
| initBaseMods | `` | `void` | `obj:initBaseMods()` |
| initModsList | `` | `void` | `obj:initModsList()` |
| getModIndex | `modName: string` | `integer` | `obj:getModIndex(modName)` |
| buildingIntersectionTestCapsule | `pos: Vector3, radius: number, length: number` | `boolean` | `obj:buildingIntersectionTestCapsule(pos, radius, length)` |
| getLightLevel | `position: Vector3, floor: integer, inside: boolean` | `number` | `obj:getLightLevel(position, floor, inside)` |
| populateMapArea_nonPermanent | `howMany: integer, rePopulationMode: boolean` | `void` | `obj:populateMapArea_nonPermanent(howMany, rePopulationMode)` |
| findValidSpawnPos | `pos: Vector3, centerArea: Vector3` | `boolean` | `obj:findValidSpawnPos(pos, centerArea)` |
| togglePause | `on: boolean` | `void` | `obj:togglePause(on)` |
| getFrameSpeedMultiplier | `` | `number` | `obj:getFrameSpeedMultiplier()` |
| setFrameSpeedMultiplier | `m: number` | `void` | `obj:setFrameSpeedMultiplier(m)` |
| setGameSpeed | `speed: number, click: boolean` | `void` | `obj:setGameSpeed(speed, click)` |
| userPause | `p: boolean` | `void` | `obj:userPause(p)` |
| isPaused | `` | `boolean` | `obj:isPaused()` |
| getCameraCenter | `` | `Vector3` | `obj:getCameraCenter()` |
| getCameraPos | `` | `Vector3` | `obj:getCameraPos()` |
| fixNaNPosition | `pos: Vector3` | `boolean` | `obj:fixNaNPosition(pos)` |
| getWindSpeed | `pos: Vector3` | `number` | `obj:getWindSpeed(pos)` |
| isLoadingFromASaveGame | `` | `boolean` | `obj:isLoadingFromASaveGame()` |
| addToUpdateListMain | `` | `void` | `obj:addToUpdateListMain()` |
| removeFromUpdateListMain | `` | `void` | `obj:removeFromUpdateListMain()` |
| addToDeathParade | `` | `void` | `obj:addToDeathParade()` |
| removeFromDeathParade | `` | `boolean` | `obj:removeFromDeathParade()` |
| removeFromDeathParadeByPlatoon | `` | `void` | `obj:removeFromDeathParadeByPlatoon()` |
| hideContextMenu | `` | `void` | `obj:hideContextMenu()` |
| showPlayerAMessage_withLog | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage_withLog(message, queued)` |
| showPlayerAMessage | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage(message, queued)` |
| showPlayerAMessageD | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessageD(message, queued)` |
| playNotification | `sound: string` | `void` | `obj:playNotification(sound)` |
| mainLoop_GPUSensitiveStuff | `time: number` | `void` | `obj:mainLoop_GPUSensitiveStuff(time)` |
| _NV_mainLoop_GPUSensitiveStuff | `time: number` | `void` | `obj:_NV_mainLoop_GPUSensitiveStuff(time)` |
| clearPortaitsUpdate | `` | `void` | `obj:clearPortaitsUpdate()` |
| processSysMessages | `` | `void` | `obj:processSysMessages()` |
| destroyDeathParade | `` | `void` | `obj:destroyDeathParade()` |
| processKeys | `` | `void` | `obj:processKeys()` |
| processThreadMessages | `` | `void` | `obj:processThreadMessages()` |
| charsUpdate | `` | `void` | `obj:charsUpdate()` |
| charsUpdateUT | `` | `void` | `obj:charsUpdateUT()` |
| charsUpdatePaused | `` | `void` | `obj:charsUpdatePaused()` |
| charsUpdateDeathParade | `` | `void` | `obj:charsUpdateDeathParade()` |
| threadSafeRagdollUpdates | `` | `void` | `obj:threadSafeRagdollUpdates()` |
| AINonRenderThread | `` | `ThreadWannabe` | `obj:AINonRenderThread()` |
| processAttachmentsKillList | `` | `void` | `obj:processAttachmentsKillList()` |
| processKillList | `forceImmediate: boolean` | `void` | `obj:processKillList(forceImmediate)` |
| processUpdateRemovalList | `` | `void` | `obj:processUpdateRemovalList()` |
| loadAllPlatoons | `` | `void` | `obj:loadAllPlatoons()` |
| reCalculateFortificationInsideOutsideStateForAllCharacters | `` | `void` | `obj:reCalculateFortificationInsideOutsideStateForAllCharacters()` |
| getTimeStamp | `` | `number` | `obj:getTimeStamp()` |
| getTimeFromStamp_inGameHours | `stamp: number` | `number` | `obj:getTimeFromStamp_inGameHours(stamp)` |
| getTimeStamp_inGameHours | `` | `void` | `obj:getTimeStamp_inGameHours()` |
| getLengthOfHourInRealSeconds | `` | `number` | `obj:getLengthOfHourInRealSeconds()` |

## GamedataSelectionList
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | MyGUI::Widget | R | `obj.win` |
| list | MyGUI::Widget | R | `obj.list` |
| items | lektor<GameData*> | R | `obj.items` |
| levelEditor | LevelEditor | R | `obj.levelEditor` |
| lastItem | integer | RW | `obj.lastItem = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `type: integer, top: number, left: number, w: number, h: number` | `GamedataSelectionList` | `obj:_CONSTRUCTOR(type, top, left, w, h)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| deselectItem | `` | `void` | `obj:deselectItem()` |
| selectItem | `` | `boolean` | `obj:selectItem()` |
| getSelectedItem | `` | `GameData` | `obj:getSelectedItem()` |
| itemSelected | `` | `void` | `obj:itemSelected()` |
| formatItem | `` | `string` | `obj:formatItem()` |
| _NV_formatItem | `` | `string` | `obj:_NV_formatItem()` |
| listItemSelected | `_index: integer` | `void` | `obj:listItemSelected(_index)` |
| changeFilter | `` | `void` | `obj:changeFilter()` |

## GameplayOptions
**Header:** `extern/KenshiLib/Include/kenshi/saveinfo.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| deathFrequency | number | RW | `obj.deathFrequency = <value>` |
| easyProspecting | boolean | RW | `obj.easyProspecting = <value>` |
| globalDamageMultiplier | number | RW | `obj.globalDamageMultiplier = <value>` |
| buildingSpeed | number | RW | `obj.buildingSpeed = <value>` |
| numNestsMult | number | RW | `obj.numNestsMult = <value>` |
| researchSpeed | number | RW | `obj.researchSpeed = <value>` |
| productionSpeed | number | RW | `obj.productionSpeed = <value>` |
| hungerTime | number | RW | `obj.hungerTime = <value>` |
| banditsLootPlayer | boolean | RW | `obj.banditsLootPlayer = <value>` |
| animalsEat | boolean | RW | `obj.animalsEat = <value>` |
| difficultHealing | boolean | RW | `obj.difficultHealing = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GameplayOptions` | `obj:_CONSTRUCTOR()` |
| reset | `` | `void` | `obj:reset()` |
| getStarvationTimeInHours | `` | `number` | `obj:getStarvationTimeInHours()` |
| save | `` | `void` | `obj:save()` |
| load | `` | `void` | `obj:load()` |

## GatewayBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GatewayBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| reAnnounceGateToPathfinder | `` | `void` | `obj:reAnnounceGateToPathfinder()` |
| postCreationPathfinderSetupStuff | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| _NV_postCreationPathfinderSetupStuff | `` | `void` | `obj:_NV_postCreationPathfinderSetupStuff()` |
| getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| _NV_getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:_NV_getPositionForWaypoint(from)` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| _NV_isGate | `` | `GatewayBuilding` | `obj:_NV_isGate()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| setup | `` | `void` | `obj:setup()` |
| _NV_setup | `` | `void` | `obj:_NV_setup()` |
| getGateCodeAt | `p: Vector3` | `integer` | `obj:getGateCodeAt(p)` |
| getOutsideGateCode | `` | `integer` | `obj:getOutsideGateCode()` |
| separatesAreas | `` | `boolean` | `obj:separatesAreas()` |

## Gear
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isUniform | Faction | RW | `obj.isUniform = <value>` |
| value | integer | RW | `obj.value = <value>` |
| crafter | string | RW | `obj.crafter = <value>` |
| level | number | RW | `obj.level = <value>` |
| level_0_100 | integer | RW | `obj.level_0_100 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_level: integer` | `Gear` | `obj:_CONSTRUCTOR(_level)` |
| isGear | `` | `Gear` | `obj:isGear()` |
| _NV_isGear | `` | `Gear` | `obj:_NV_isGear()` |
| getLevel01 | `` | `number` | `obj:getLevel01()` |
| _NV_getLevel01 | `` | `number` | `obj:_NV_getLevel01()` |
| getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| _NV_isAFactionUniform | `` | `Faction` | `obj:_NV_isAFactionUniform()` |
| _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| isPlayerCrafted | `` | `boolean` | `obj:isPlayerCrafted()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setInventoryWeAreIn | `` | `void` | `obj:setInventoryWeAreIn()` |
| _NV_setInventoryWeAreIn | `` | `void` | `obj:_NV_setInventoryWeAreIn()` |

## GeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| _NV_getPowerOutput | `` | `number` | `obj:_NV_getPowerOutput()` |
| getFuelConsumptionRate | `` | `number` | `obj:getFuelConsumptionRate()` |
| _NV_getFuelConsumptionRate | `` | `number` | `obj:_NV_getFuelConsumptionRate()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GenericFixedInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `GenericFixedInventoryLayout` | `obj:_CONSTRUCTOR()` |
| setSize | `slotsW: integer, slotsH: integer` | `void` | `obj:setSize(slotsW, slotsH)` |
| _NV_setSize | `slotsW: integer, slotsH: integer` | `void` | `obj:_NV_setSize(slotsW, slotsH)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## GenericInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| arrangeButton | lightuserdata | R | `obj.arrangeButton` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setSize | `slotsW: integer, slotsH: integer, hasArrange: boolean, hasType: boolean` | `void` | `obj:setSize(slotsW, slotsH, hasArrange, hasType)` |
| _NV_setSize | `slotsW: integer, slotsH: integer, hasArrange: boolean, hasType: boolean` | `void` | `obj:_NV_setSize(slotsW, slotsH, hasArrange, hasType)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Global
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

## GlobalConstants
**Header:** `extern/KenshiLib/Include/kenshi/GlobalConstants.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER | number | RW | `obj.EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER = <value>` |
| BLEED_RATE_MULTIPLIER | number | RW | `obj.BLEED_RATE_MULTIPLIER = <value>` |
| INITIAL_BLEED_LOSS_MULTIPLIER | number | RW | `obj.INITIAL_BLEED_LOSS_MULTIPLIER = <value>` |
| BLEED_CLOT_RATE | number | RW | `obj.BLEED_CLOT_RATE = <value>` |
| BLUNT_DAMAGE_1 | number | RW | `obj.BLUNT_DAMAGE_1 = <value>` |
| BLUNT_DAMAGE_99 | number | RW | `obj.BLUNT_DAMAGE_99 = <value>` |
| CUT_DAMAGE_1 | number | RW | `obj.CUT_DAMAGE_1 = <value>` |
| CUT_DAMAGE_99 | number | RW | `obj.CUT_DAMAGE_99 = <value>` |
| BOW_DAMAGE_0 | number | RW | `obj.BOW_DAMAGE_0 = <value>` |
| BOW_DAMAGE_99 | number | RW | `obj.BOW_DAMAGE_99 = <value>` |
| PIERCE_MULTIPLIER | number | RW | `obj.PIERCE_MULTIPLIER = <value>` |
| MIN_STUMBLE_DAMAGE_MAX | number | RW | `obj.MIN_STUMBLE_DAMAGE_MAX = <value>` |
| DAMAGE_RESISTANCE_MIN | number | RW | `obj.DAMAGE_RESISTANCE_MIN = <value>` |
| DAMAGE_RESISTANCE_MAX | number | RW | `obj.DAMAGE_RESISTANCE_MAX = <value>` |
| STUN_RECOVERY_RATE | number | RW | `obj.STUN_RECOVERY_RATE = <value>` |
| BLOOD_RECOVERY_RATE | number | RW | `obj.BLOOD_RECOVERY_RATE = <value>` |
| ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR | number | RW | `obj.ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR = <value>` |
| BASE_BLOCK_CHANCE | number | RW | `obj.BASE_BLOCK_CHANCE = <value>` |
| BLOCK_CHANCE_REDUCTION | number | RW | `obj.BLOCK_CHANCE_REDUCTION = <value>` |
| BLOCK_CHANCE_INCREASE | number | RW | `obj.BLOCK_CHANCE_INCREASE = <value>` |
| DEGENERATION_MULT_1 | number | RW | `obj.DEGENERATION_MULT_1 = <value>` |
| DEGENERATION_MULT_99 | number | RW | `obj.DEGENERATION_MULT_99 = <value>` |
| MEDIC_SPEED_MULT | number | RW | `obj.MEDIC_SPEED_MULT = <value>` |
| KNOCKOUT_MULT_1 | number | RW | `obj.KNOCKOUT_MULT_1 = <value>` |
| KNOCKOUT_MULT_99 | number | RW | `obj.KNOCKOUT_MULT_99 = <value>` |
| KNOCKOUT_BASE_TIME | number | RW | `obj.KNOCKOUT_BASE_TIME = <value>` |
| BODYPART_DEGENERATE_RATE_MULT | number | RW | `obj.BODYPART_DEGENERATE_RATE_MULT = <value>` |
| BODYPART_HEAL_RATE_MULT | number | RW | `obj.BODYPART_HEAL_RATE_MULT = <value>` |
| BODYPART_HEAL_RATE_MULT_RESTING | number | RW | `obj.BODYPART_HEAL_RATE_MULT_RESTING = <value>` |
| XP_MEDIC_1 | number | RW | `obj.XP_MEDIC_1 = <value>` |
| XP_MEDIC_99 | number | RW | `obj.XP_MEDIC_99 = <value>` |
| MEDKIT_DRAIN_1 | number | RW | `obj.MEDKIT_DRAIN_1 = <value>` |
| MEDKIT_DRAIN_99 | number | RW | `obj.MEDKIT_DRAIN_99 = <value>` |
| ROBOT_WEAR_RATE | number | RW | `obj.ROBOT_WEAR_RATE = <value>` |
| ROBOT_FIRST_AID_SPEED | number | RW | `obj.ROBOT_FIRST_AID_SPEED = <value>` |
| STARVATION_TIME_HRS | number | RW | `obj.STARVATION_TIME_HRS = <value>` |
| FED_RECOVERY_RATE_MULT | number | RW | `obj.FED_RECOVERY_RATE_MULT = <value>` |
| BED_HUNGER_RATE | number | RW | `obj.BED_HUNGER_RATE = <value>` |
| ENCUMBRANCE_HUNGER_RATE | number | RW | `obj.ENCUMBRANCE_HUNGER_RATE = <value>` |
| FOOD_QUALITY_MULT | number | RW | `obj.FOOD_QUALITY_MULT = <value>` |
| FOOD_PRICE_MULT | number | RW | `obj.FOOD_PRICE_MULT = <value>` |
| SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS | number | RW | `obj.SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS = <value>` |
| SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY | number | RW | `obj.SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY = <value>` |
| XP_HIT_THEM | number | RW | `obj.XP_HIT_THEM = <value>` |
| XP_HIT_ME | number | RW | `obj.XP_HIT_ME = <value>` |
| XP_BLOCKED_THEM | number | RW | `obj.XP_BLOCKED_THEM = <value>` |
| XP_BLOCKED_ME | number | RW | `obj.XP_BLOCKED_ME = <value>` |
| XP_FIRSTAID | number | RW | `obj.XP_FIRSTAID = <value>` |
| XP_FITNESS | number | RW | `obj.XP_FITNESS = <value>` |
| XP_TOUGHNESS | number | RW | `obj.XP_TOUGHNESS = <value>` |
| PRICE_ROBOTICS | number | RW | `obj.PRICE_ROBOTICS = <value>` |
| PRICE_CROSSBOWS | number | RW | `obj.PRICE_CROSSBOWS = <value>` |
| PRICE_ARMOUR | number | RW | `obj.PRICE_ARMOUR = <value>` |
| PRICE_SWORDS | number | RW | `obj.PRICE_SWORDS = <value>` |
| PRICE_TRADE | number | RW | `obj.PRICE_TRADE = <value>` |
| PRICE_GLOBAL_MULT | number | RW | `obj.PRICE_GLOBAL_MULT = <value>` |
| PRICE_CLOTHING | number | RW | `obj.PRICE_CLOTHING = <value>` |
| TRADE_PROFIT_MARGINS | number | RW | `obj.TRADE_PROFIT_MARGINS = <value>` |
| PRICE_LOOT_GEAR | number | RW | `obj.PRICE_LOOT_GEAR = <value>` |
| PRICE_LOOT_ITEMS | number | RW | `obj.PRICE_LOOT_ITEMS = <value>` |
| PRICE_LOOT_PLAYER_CRAFTED_ARMOUR | number | RW | `obj.PRICE_LOOT_PLAYER_CRAFTED_ARMOUR = <value>` |
| PRICE_LOOT_PLAYER_CRAFTED_WEAPONS | number | RW | `obj.PRICE_LOOT_PLAYER_CRAFTED_WEAPONS = <value>` |
| BLUEPRINT_COST_MULT | number | RW | `obj.BLUEPRINT_COST_MULT = <value>` |
| UNIFORM_PRICE_MULT | number | RW | `obj.UNIFORM_PRICE_MULT = <value>` |
| BLUNT_PERMANENT_DAMAGE_RATIO | number | RW | `obj.BLUNT_PERMANENT_DAMAGE_RATIO = <value>` |
| UNARMED_DAMAGE_MULT | number | RW | `obj.UNARMED_DAMAGE_MULT = <value>` |
| MAX_NUM_ATTACK_SLOTS | integer | RW | `obj.MAX_NUM_ATTACK_SLOTS = <value>` |
| MINIMUM_STRENGTH_XP_MULT | number | RW | `obj.MINIMUM_STRENGTH_XP_MULT = <value>` |
| WEIGHT_STR_DIFF_1X | number | RW | `obj.WEIGHT_STR_DIFF_1X = <value>` |
| WEIGHT_STR_DIFF_MAX | number | RW | `obj.WEIGHT_STR_DIFF_MAX = <value>` |
| WEAPON_INVENTORY_WEIGHT_MULT | number | RW | `obj.WEAPON_INVENTORY_WEIGHT_MULT = <value>` |
| STRENGTH_XP_RATE_FROM_WALKING | number | RW | `obj.STRENGTH_XP_RATE_FROM_WALKING = <value>` |
| STRENGTH_XP_RATE | number | RW | `obj.STRENGTH_XP_RATE = <value>` |
| ATHLETICS_XP_RATE | number | RW | `obj.ATHLETICS_XP_RATE = <value>` |
| ENCUMBRANCE_BASE | number | RW | `obj.ENCUMBRANCE_BASE = <value>` |
| CARRY_WEIGHT_MULT | number | RW | `obj.CARRY_WEIGHT_MULT = <value>` |
| CARRY_PERSON_WEIGHT | number | RW | `obj.CARRY_PERSON_WEIGHT = <value>` |
| MIN_MATS_FROM_DISMANTLE_01 | number | RW | `obj.MIN_MATS_FROM_DISMANTLE_01 = <value>` |
| EXPERIENCE_GAIN | number | RW | `obj.EXPERIENCE_GAIN = <value>` |
| EXPERIENCE_GAIN_1 | number | RW | `obj.EXPERIENCE_GAIN_1 = <value>` |
| EXPERIENCE_GAIN_99 | number | RW | `obj.EXPERIENCE_GAIN_99 = <value>` |
| RESEARCH_LEVEL_INCREASE | number | RW | `obj.RESEARCH_LEVEL_INCREASE = <value>` |
| RESEARCH_RATE | number | RW | `obj.RESEARCH_RATE = <value>` |
| LOCKPICK_CHANCE_MINIMUM | number | RW | `obj.LOCKPICK_CHANCE_MINIMUM = <value>` |
| EXPERIENCE_CURVE | number | RW | `obj.EXPERIENCE_CURVE = <value>` |
| ANIMATION_BLEND_RATE | number | RW | `obj.ANIMATION_BLEND_RATE = <value>` |
| PRODUCTION_MULTIPLIER | number | RW | `obj.PRODUCTION_MULTIPLIER = <value>` |
| BUILD_SPEED_MULTIPLIER | number | RW | `obj.BUILD_SPEED_MULTIPLIER = <value>` |
| PRISON_TIME_MULT | number | RW | `obj.PRISON_TIME_MULT = <value>` |
| TOUGHNESS_KO_POINT_MIN | number | RW | `obj.TOUGHNESS_KO_POINT_MIN = <value>` |
| TOUGHNESS_KO_POINT_MAX | number | RW | `obj.TOUGHNESS_KO_POINT_MAX = <value>` |
| MAX_SQUAD_SIZE | integer | RW | `obj.MAX_SQUAD_SIZE = <value>` |
| MAX_SQUADS | integer | RW | `obj.MAX_SQUADS = <value>` |
| MAX_FACTION_SIZE | integer | RW | `obj.MAX_FACTION_SIZE = <value>` |
| attackDiplomats | boolean | RW | `obj.attackDiplomats = <value>` |
| settings | GameData | R | `obj.settings` |
| APPEARANCE_RANDOM_DEVIATION | number | RW | `obj.APPEARANCE_RANDOM_DEVIATION = <value>` |
| fogDistMax | number | RW | `obj.fogDistMax = <value>` |
| fogDistMin | number | RW | `obj.fogDistMin = <value>` |

## Hand
**Header:** `extern/KenshiLib/Include/kenshi/util/hand.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| toString | `` | `string` | `obj:toString()` |
| fromString | `str: string` | `void` | `obj:fromString(str)` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| getPlatoon | `` | `Platoon` | `obj:getPlatoon()` |
| getActivePlatoon | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getBuilding | `` | `Building` | `obj:getBuilding()` |
| getItem | `` | `Item` | `obj:getItem()` |
| getRootObject | `` | `RootObject` | `obj:getRootObject()` |
| getRootObjectBase | `` | `RootObjectBase` | `obj:getRootObjectBase()` |
| getTown | `` | `TownBase` | `obj:getTown()` |
| debugWhatHappenedToMe | `` | `string` | `obj:debugWhatHappenedToMe()` |
| setNull | `` | `void` | `obj:setNull()` |
| isNull | `` | `boolean` | `obj:isNull()` |
| isValid | `` | `boolean` | `obj:isValid()` |
| canCastToRootObject | `` | `boolean` | `obj:canCastToRootObject()` |

## HasRoomCache
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| itemStates | GameDataBoolStdMapBinding::MapType | RW | `obj.itemStates = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| modified | `` | `void` | `obj:modified()` |
| knowsAbout | `` | `boolean` | `obj:knowsAbout()` |
| hasRoomFor | `` | `boolean` | `obj:hasRoomFor()` |
| remember | `state: boolean` | `void` | `obj:remember(state)` |
| _CONSTRUCTOR | `` | `HasRoomCache` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## HavokCharacter
**Header:** `extern/KenshiLib/Include/kenshi/havokcharacter.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| startingFace | integer | RW | `obj.startingFace = <value>` |
| currentFace | integer | RW | `obj.currentFace = <value>` |
| nextEdge | integer | RW | `obj.nextEdge = <value>` |
| radius | number | RW | `obj.radius = <value>` |
| waterModifier | number | RW | `obj.waterModifier = <value>` |
| acceleration | number | RW | `obj.acceleration = <value>` |
| desiredSpeed | number | RW | `obj.desiredSpeed = <value>` |
| positionChanged | boolean | RW | `obj.positionChanged = <value>` |
| timeOffPath | number | RW | `obj.timeOffPath = <value>` |
| characterState | integer | RW | `obj.characterState = <value>` |
| lastState | integer | RW | `obj.lastState = <value>` |
| pathState | integer | RW | `obj.pathState = <value>` |
| handle | unknown | RW | `obj.handle = <value>` |
| collided | unknown | RW | `obj.collided = <value>` |
| sensoryData | SensoryData | RW | `obj.sensoryData = <value>` |
| resolveFlag | integer | RW | `obj.resolveFlag = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setPosition | `p: Vector3, key: integer` | `void` | `obj:setPosition(p, key)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| setVelocity | `v: Vector3` | `void` | `obj:setVelocity(v)` |
| getVelocity | `` | `Vector3` | `obj:getVelocity()` |
| getWaypointDirection | `` | `Vector3` | `obj:getWaypointDirection()` |
| getDirectionMoved | `` | `Vector3` | `obj:getDirectionMoved()` |
| setWaterModifier | `m: number` | `void` | `obj:setWaterModifier(m)` |
| setManualMode | `on: boolean` | `void` | `obj:setManualMode(on)` |
| setDesiredSpeed | `speed: number` | `void` | `obj:setDesiredSpeed(speed)` |
| getState | `` | `integer` | `obj:getState()` |
| getPathState | `` | `integer` | `obj:getPathState()` |
| isOnNavmesh | `` | `boolean` | `obj:isOnNavmesh()` |
| getClosestPoint | `target: Vector3, max: number` | `Vector3` | `obj:getClosestPoint(target, max)` |
| requestPath | `goal: Vector3, priority: integer` | `void` | `obj:requestPath(goal, priority)` |
| clearPath | `` | `void` | `obj:clearPath()` |
| update | `time: number` | `void` | `obj:update(time)` |
| moveAlongPath | `time: number` | `boolean` | `obj:moveAlongPath(time)` |
| handleCollision | `` | `boolean` | `obj:handleCollision()` |
| invalidate | `rid: integer` | `void` | `obj:invalidate(rid)` |
| _getFaceKey | `` | `integer` | `obj:_getFaceKey()` |
| pullThroughVertex | `side: integer, index: integer` | `integer` | `obj:pullThroughVertex(side, index)` |
| updateNextEdge | `` | `integer` | `obj:updateNextEdge()` |
| resolveProblems | `` | `void` | `obj:resolveProblems()` |
| atGoal | `` | `boolean` | `obj:atGoal()` |

## HealthPartStatus
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | GameData | RW | `obj.data = <value>` |
| whatAmI | integer | RW | `obj.whatAmI = <value>` |
| medical | MedicalSystem | RW | `obj.medical = <value>` |
| me | Character | RW | `obj.me = <value>` |
| side | integer | RW | `obj.side = <value>` |
| robotLimb | RobotLimbItem | RW | `obj.robotLimb = <value>` |
| selfHealing | boolean | RW | `obj.selfHealing = <value>` |
| collapses | boolean | RW | `obj.collapses = <value>` |
| fatal | boolean | RW | `obj.fatal = <value>` |
| KOMult | number | RW | `obj.KOMult = <value>` |
| hitChance | number | RW | `obj.hitChance = <value>` |
| hitChanceMult | number | RW | `obj.hitChanceMult = <value>` |
| flesh | number | RW | `obj.flesh = <value>` |
| fleshStun | number | RW | `obj.fleshStun = <value>` |
| bandaging | number | RW | `obj.bandaging = <value>` |
| juryRigging | number | RW | `obj.juryRigging = <value>` |
| wearDamage | number | RW | `obj.wearDamage = <value>` |
| _maxHealth | number | RW | `obj._maxHealth = <value>` |
| age | number | RW | `obj.age = <value>` |
| HPMult | number | RW | `obj.HPMult = <value>` |
| derivedFleshHealthPercent | number | RW | `obj.derivedFleshHealthPercent = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| serialise | `num: integer` | `void` | `obj:serialise(num)` |
| load | `num: integer` | `void` | `obj:load(num)` |
| isRobotic | `` | `boolean` | `obj:isRobotic()` |
| getData | `` | `GameData` | `obj:getData()` |
| getRobotLimbEnum | `` | `integer` | `obj:getRobotLimbEnum()` |
| setup | `_hitchance: number, _max: number, _age: number, selfHeal: boolean` | `void` | `obj:setup(_hitchance, _max, _age, selfHeal)` |
| update | `frameTIME: number, healMultFlesh: number, healMultRobot: number, degenerationRate: number, _age: number, robotWear: number` | `boolean` | `obj:update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear)` |
| updateDerivedHealths | `` | `void` | `obj:updateDerivedHealths()` |
| getWorstDamage | `brokenBoneValue: number` | `number` | `obj:getWorstDamage(brokenBoneValue)` |
| setRobotLimbItem | `isLoadingASave: boolean` | `void` | `obj:setRobotLimbItem(isLoadingASave)` |
| getExtraBleedingAmount | `` | `number` | `obj:getExtraBleedingAmount()` |
| isDead | `` | `boolean` | `obj:isDead()` |
| getBloodynessMult | `` | `number` | `obj:getBloodynessMult()` |
| maxHealth | `` | `number` | `obj:maxHealth()` |
| healthAsPercent | `healt: number` | `number` | `obj:healthAsPercent(healt)` |

## ImpactPoint
**Header:** `extern/KenshiLib/Include/kenshi/CombatTechniqueData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| direction | integer | RW | `obj.direction = <value>` |
| power | number | RW | `obj.power = <value>` |
| impactAnimationFrame | number | RW | `obj.impactAnimationFrame = <value>` |
| motionStopsAnimationFrame | number | RW | `obj.motionStopsAnimationFrame = <value>` |
| limb | integer | RW | `obj.limb = <value>` |

## ImportGameMenu
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| newGameOptions | lightuserdata | R | `obj.newGameOptions` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| select | `index: integer` | `void` | `obj:select(index)` |
| _NV_select | `index: integer` | `void` | `obj:_NV_select(index)` |

## InputHandler
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| keyboard | lightuserdata | RW | `obj.keyboard = <value>` |
| controlEnabled | boolean | RW | `obj.controlEnabled = <value>` |
| gameMode | integer | RW | `obj.gameMode = <value>` |
| ctrl | boolean | RW | `obj.ctrl = <value>` |
| shift | boolean | RW | `obj.shift = <value>` |
| alt | boolean | RW | `obj.alt = <value>` |
| up | boolean | RW | `obj.up = <value>` |
| down | boolean | RW | `obj.down = <value>` |
| left | boolean | RW | `obj.left = <value>` |
| right | boolean | RW | `obj.right = <value>` |
| space | boolean | RW | `obj.space = <value>` |
| pgup | boolean | RW | `obj.pgup = <value>` |
| pgdn | boolean | RW | `obj.pgdn = <value>` |
| comma | boolean | RW | `obj.comma = <value>` |
| period | boolean | RW | `obj.period = <value>` |
| f1 | boolean | RW | `obj.f1 = <value>` |
| f2 | boolean | RW | `obj.f2 = <value>` |
| escape | boolean | RW | `obj.escape = <value>` |
| del | boolean | RW | `obj.del = <value>` |
| escape_msg | boolean | RW | `obj.escape_msg = <value>` |
| zoomin | boolean | RW | `obj.zoomin = <value>` |
| zoomout | boolean | RW | `obj.zoomout = <value>` |
| buildTiltInc | boolean | RW | `obj.buildTiltInc = <value>` |
| buildTiltDec | boolean | RW | `obj.buildTiltDec = <value>` |
| rotate | boolean | RW | `obj.rotate = <value>` |
| rotRight | boolean | RW | `obj.rotRight = <value>` |
| rotLeft | boolean | RW | `obj.rotLeft = <value>` |
| tiltDown | boolean | RW | `obj.tiltDown = <value>` |
| tiltUp | boolean | RW | `obj.tiltUp = <value>` |
| highlight | boolean | RW | `obj.highlight = <value>` |
| mLeft | boolean | RW | `obj.mLeft = <value>` |
| mRight | boolean | RW | `obj.mRight = <value>` |
| lastMLeft | boolean | RW | `obj.lastMLeft = <value>` |
| lastMRight | boolean | RW | `obj.lastMRight = <value>` |
| mLDown | boolean | RW | `obj.mLDown = <value>` |
| mRDown | boolean | RW | `obj.mRDown = <value>` |
| mLUp | boolean | RW | `obj.mLUp = <value>` |
| mRUp | boolean | RW | `obj.mRUp = <value>` |
| swapMouseButtons | boolean | RW | `obj.swapMouseButtons = <value>` |
| mPos | unknown | RW | `obj.mPos = <value>` |
| mPosAbs | unknown | RW | `obj.mPosAbs = <value>` |
| mSpeed | Vector3 | RW | `obj.mSpeed = <value>` |
| mWheel | integer | RW | `obj.mWheel = <value>` |
| commands | lightuserdata | R | `obj.commands` |
| map | lightuserdata | R | `obj.map` |
| editMap | lightuserdata | R | `obj.editMap` |
| events | lightuserdata | R | `obj.events` |
| keyNameMap | integer | R | `obj.keyNameMap` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getKeyUTF8 | `key: integer` | `string` | `obj:getKeyUTF8(key)` |
| parseKey | `s: string` | `integer` | `obj:parseKey(s)` |
| getCommand | `s: string` | `lightuserdata` | `obj:getCommand(s)` |
| keyDownEvent | `key: integer` | `void` | `obj:keyDownEvent(key)` |
| keyUpEvent | `key: integer` | `void` | `obj:keyUpEvent(key)` |
| clearMessages | `` | `void` | `obj:clearMessages()` |
| _CONSTRUCTOR | `` | `InputHandler` | `obj:_CONSTRUCTOR()` |
| initialise | `` | `void` | `obj:initialise()` |
| bind | `name: string, key: integer` | `void` | `obj:bind(name, key)` |
| unbindAll | `` | `void` | `obj:unbindAll()` |
| isKeyState | `command: string` | `boolean` | `obj:isKeyState(command)` |
| getMode | `command: string` | `integer` | `obj:getMode(command)` |
| sendEvent | `name: string` | `void` | `obj:sendEvent(name)` |
| loadConfig | `` | `void` | `obj:loadConfig()` |
| saveConfig | `` | `void` | `obj:saveConfig()` |
| keyString | `key: integer, translated: boolean` | `string` | `obj:keyString(key, translated)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| addCommand | `name: string, value: integer, key: integer, alt: integer, masks: integer, mode: integer` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| unbind | `cmd: string, mode: integer` | `void` | `obj:unbind(cmd, mode)` |
| isBound | `cmd: string` | `boolean` | `obj:isBound(cmd)` |
| getBoundKeys | `command: string` | `integer` | `obj:getBoundKeys(command)` |
| getBoundCommand | `key: integer, mode: integer` | `string` | `obj:getBoundCommand(key, mode)` |

## InputHandler_Command
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `isKey: boolean, code: integer, bound: integer` | `InputHandler::Command` | `obj:_CONSTRUCTOR(isKey, code, bound)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## InstanceID
**Header:** `extern/KenshiLib/Include/kenshi/InstanceID.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| uid | string | RW | `obj.uid = <value>` |
| baseIndex | integer | RW | `obj.baseIndex = <value>` |
| modIndex | integer | RW | `obj.modIndex = <value>` |
| modified | boolean | RW | `obj.modified = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| assign | `id: string` | `void` | `obj:assign(id)` |
| clear | `` | `void` | `obj:clear()` |
| needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| notifyChange | `` | `void` | `obj:notifyChange()` |
| hasChanges | `` | `boolean` | `obj:hasChanges()` |
| notifySaved | `mod: string` | `void` | `obj:notifySaved(mod)` |
| empty | `` | `boolean` | `obj:empty()` |
| getBaseIndex | `` | `integer` | `obj:getBaseIndex()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## InteriorModeButtonWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/InteriorModeButtonWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| exteriorsInvisible | boolean | RW | `obj.exteriorsInvisible = <value>` |
| interiorMode | boolean | RW | `obj.interiorMode = <value>` |
| dataEditWindow | GameDataEditorWindow | RW | `obj.dataEditWindow = <value>` |
| currentBuilding | unknown | RW | `obj.currentBuilding = <value>` |
| currentInterior | string | RW | `obj.currentInterior = <value>` |
| currentExterior | string | RW | `obj.currentExterior = <value>` |
| interiorModeButton | lightuserdata | R | `obj.interiorModeButton` |
| win | lightuserdata | R | `obj.win` |
| centerButton | lightuserdata | R | `obj.centerButton` |
| exteriorButton | lightuserdata | R | `obj.exteriorButton` |
| titleLabel | lightuserdata | R | `obj.titleLabel` |
| saveBut | lightuserdata | R | `obj.saveBut` |
| deleteBut | lightuserdata | R | `obj.deleteBut` |
| listbox | lightuserdata | R | `obj.listbox` |
| namebox | lightuserdata | R | `obj.namebox` |
| saveBut2 | lightuserdata | R | `obj.saveBut2` |
| deleteBut2 | lightuserdata | R | `obj.deleteBut2` |
| listbox2 | lightuserdata | R | `obj.listbox2` |
| namebox2 | lightuserdata | R | `obj.namebox2` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| toggleInteriorMode | `` | `void` | `obj:toggleInteriorMode()` |
| setVisible | `v: boolean` | `void` | `obj:setVisible(v)` |
| wantExteriorsInvisible | `` | `boolean` | `obj:wantExteriorsInvisible()` |
| setSelectedBuilding | `` | `void` | `obj:setSelectedBuilding()` |
| getSelectedBuilding | `` | `Building` | `obj:getSelectedBuilding()` |
| updateUsageNodes | `` | `boolean` | `obj:updateUsageNodes()` |
| refresh | `` | `void` | `obj:refresh()` |
| activateInteriorMode | `on: boolean` | `void` | `obj:activateInteriorMode(on)` |
| confirmDeleteInteriorLayout | `c: integer` | `void` | `obj:confirmDeleteInteriorLayout(c)` |
| confirmDeleteExteriorLayout | `c: integer` | `void` | `obj:confirmDeleteExteriorLayout(c)` |
| setInteriorLayout | `name: string` | `void` | `obj:setInteriorLayout(name)` |
| setExteriorLayout | `name: string` | `void` | `obj:setExteriorLayout(name)` |
| recheckOutsideFurniture | `` | `void` | `obj:recheckOutsideFurniture()` |

## Inventory
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| hasRoomCache | lightuserdata | RW | `obj.hasRoomCache = <value>` |
| callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
| owner | RootObject | RW | `obj.owner = <value>` |
| totalWeight | number | RW | `obj.totalWeight = <value>` |
| _allItems | lektor<Item*> | R | `obj._allItems` |
| sections | InventorySection | R | `obj.sections` |
| sectionsInSearchOrder | lektor<InventorySection*> | R | `obj.sectionsInSearchOrder` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Inventory` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAll | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAll(destroy, skipUnique)` |
| serialise | `` | `GameData` | `obj:serialise()` |
| notifyModified | `` | `void` | `obj:notifyModified()` |
| initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| _NV_initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:_NV_initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| resizeSection | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resizeSection(w, h, clearContent)` |
| removeAllSections | `` | `void` | `obj:removeAllSections()` |
| getSection | `name: string` | `InventorySection` | `obj:getSection(name)` |
| getSectionOfType | `type: integer` | `InventorySection` | `obj:getSectionOfType(type)` |
| getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| addItem | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:addItem(quantity, dropOnFail, destroyOnFail)` |
| _NV_addItem | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_addItem(quantity, dropOnFail, destroyOnFail)` |
| tryAddItem | `quantity: integer` | `boolean` | `obj:tryAddItem(quantity)` |
| _NV_tryAddItem | `quantity: integer` | `boolean` | `obj:_NV_tryAddItem(quantity)` |
| hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| removeItemDontDestroy_returnsItem | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| _NV_removeItemDontDestroy_returnsItem | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:_NV_removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| removeItemAutoDestroy | `howmany: integer` | `boolean` | `obj:removeItemAutoDestroy(howmany)` |
| _NV_removeItemAutoDestroy | `howmany: integer` | `boolean` | `obj:_NV_removeItemAutoDestroy(howmany)` |
| dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| transferMouseItem | `` | `boolean` | `obj:transferMouseItem()` |
| countItems | `` | `integer` | `obj:countItems()` |
| getItem | `` | `Item` | `obj:getItem()` |
| hasItemType | `item: integer, skipEquipped: boolean` | `boolean` | `obj:hasItemType(item, skipEquipped)` |
| hasStolenItems | `` | `boolean` | `obj:hasStolenItems()` |
| getSecondaryWeapon | `` | `Weapon` | `obj:getSecondaryWeapon()` |
| getPrimaryWeapon | `` | `Weapon` | `obj:getPrimaryWeapon()` |
| takeOneItemOnly | `` | `Item` | `obj:takeOneItemOnly()` |
| deathCheck | `` | `boolean` | `obj:deathCheck()` |
| hasItemFunction | `type: integer` | `boolean` | `obj:hasItemFunction(type)` |
| getBestItemWithFunction | `type: integer` | `Item` | `obj:getBestItemWithFunction(type)` |
| getBestFoodItem | `` | `Item` | `obj:getBestFoodItem()` |
| getNumFoodItems | `` | `integer` | `obj:getNumFoodItems()` |
| _getBestFoodItem | `type: integer` | `Item` | `obj:_getBestFoodItem(type)` |
| _getNumFoodItems | `type: integer` | `integer` | `obj:_getNumFoodItems(type)` |
| hasWeaponEquipped | `` | `boolean` | `obj:hasWeaponEquipped()` |
| equipItem | `` | `boolean` | `obj:equipItem()` |
| isAContainer | `` | `boolean` | `obj:isAContainer()` |
| getOwner | `` | `RootObject` | `obj:getOwner()` |
| isEmpty | `` | `boolean` | `obj:isEmpty()` |
| recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| getTotalWeight | `` | `number` | `obj:getTotalWeight()` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| takeMoney | `val: integer` | `void` | `obj:takeMoney(val)` |
| buyItem | `` | `Item` | `obj:buyItem()` |
| getInventoryGUI | `` | `InventoryGUI` | `obj:getInventoryGUI()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _sectionAddItemCallback | `` | `void` | `obj:_sectionAddItemCallback()` |
| _NV__sectionAddItemCallback | `` | `void` | `obj:_NV__sectionAddItemCallback()` |
| _sectionUpdateItemCallback | `_a2: integer` | `void` | `obj:_sectionUpdateItemCallback(_a2)` |
| _NV__sectionUpdateItemCallback | `_a2: integer` | `void` | `obj:_NV__sectionUpdateItemCallback(_a2)` |
| _sectionRemoveItemCallback | `` | `void` | `obj:_sectionRemoveItemCallback()` |
| _NV__sectionRemoveItemCallback | `` | `void` | `obj:_NV__sectionRemoveItemCallback()` |
| refreshGui | `` | `void` | `obj:refreshGui()` |
| _NV_refreshGui | `` | `void` | `obj:_NV_refreshGui()` |
| autoArrange | `` | `void` | `obj:autoArrange()` |
| getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _addToList | `` | `void` | `obj:_addToList()` |
| _NV__addToList | `` | `void` | `obj:_NV__addToList()` |
| _removeFromList | `checkEverything: boolean` | `void` | `obj:_removeFromList(checkEverything)` |
| _NV__removeFromList | `checkEverything: boolean` | `void` | `obj:_NV__removeFromList(checkEverything)` |
| getHandle | `` | `void` | `obj:getHandle()` |
| loadFrom | `` | `void` | `obj:loadFrom()` |
| fillFromVendorList | `` | `void` | `obj:fillFromVendorList()` |
| getAllSectionsOfType | `type: integer` | `void` | `obj:getAllSectionsOfType(type)` |
| getAllSections | `` | `lektor<InventorySection*>` | `obj:getAllSections()` |
| getExcessLoot | `justAsking: boolean` | `boolean` | `obj:getExcessLoot(justAsking)` |
| getResourceItems | `buildingMatsToo: boolean` | `void` | `obj:getResourceItems(buildingMatsToo)` |
| getNumItems | `` | `integer` | `obj:getNumItems()` |
| hasItem | `quantity: integer` | `boolean` | `obj:hasItem(quantity)` |
| getAllStolenItems | `includeUnknown: boolean` | `void` | `obj:getAllStolenItems(includeUnknown)` |
| getAllItemsOfType | `ty: integer, skipEquipped: boolean` | `void` | `obj:getAllItemsOfType(ty, skipEquipped)` |
| getEquippedWeapons | `` | `void` | `obj:getEquippedWeapons()` |
| getEquippedArmour | `` | `void` | `obj:getEquippedArmour()` |
| takeItem_EntireStack | `` | `Item` | `obj:takeItem_EntireStack()` |
| getAllItemsWithFunction | `type: integer` | `void` | `obj:getAllItemsWithFunction(type)` |
| getBestItemWithLowestCharges | `type: integer` | `Item` | `obj:getBestItemWithLowestCharges(type)` |
| getAllItems | `` | `lektor<Item*>` | `obj:getAllItems()` |

## InventoryGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| layoutMgr | InventoryLayout | RW | `obj.layoutMgr = <value>` |
| ownerInventory | InventoryGUI | RW | `obj.ownerInventory = <value>` |
| childInventory | InventoryGUI | RW | `obj.childInventory = <value>` |
| mouseFocus | boolean | RW | `obj.mouseFocus = <value>` |
| callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
| needItemsUpdate | boolean | RW | `obj.needItemsUpdate = <value>` |
| visible | boolean | RW | `obj.visible = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| _NV_setPositionReal | `x: number, y: number` | `void` | `obj:_NV_setPositionReal(x, y)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| _NV_refreshSection | `` | `void` | `obj:_NV_refreshSection()` |
| showBackpack | `on: boolean` | `void` | `obj:showBackpack(on)` |
| getBackpack | `` | `ContainerItem` | `obj:getBackpack()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| hasSameOwner | `` | `boolean` | `obj:hasSameOwner()` |
| getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| _NV_getCallbackCharacter | `` | `Character` | `obj:_NV_getCallbackCharacter()` |
| getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _NV_getCallbackObject | `` | `RootObject` | `obj:_NV_getCallbackObject()` |
| getSelectedItem | `sectionName: string` | `Item` | `obj:getSelectedItem(sectionName)` |
| stealingGUIInfoUpdate | `` | `void` | `obj:stealingGUIInfoUpdate()` |
| _CONSTRUCTOR | `` | `InventoryGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| pickupItemToMouse | `sectionName: string` | `boolean` | `obj:pickupItemToMouse(sectionName)` |
| getMouseItem | `` | `Item` | `obj:getMouseItem()` |
| takeCertainAmountFrom | `amount: integer` | `Item` | `obj:takeCertainAmountFrom(amount)` |
| RClickAutoTrade | `invSectionName: string, x: integer, y: integer, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTrade(invSectionName, x, y, thieveryChecks, first)` |
| RClickAutoTradeAll | `invSectionName: string, x: integer, y: integer, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTradeAll(invSectionName, x, y, thieveryChecks, first)` |
| isTradingForMoney | `` | `boolean` | `obj:isTradingForMoney()` |
| isStealing | `` | `boolean` | `obj:isStealing()` |
| isWithinRangeToTrade | `stealing: boolean` | `boolean` | `obj:isWithinRangeToTrade(stealing)` |
| setItemToPlayerPortrait | `` | `boolean` | `obj:setItemToPlayerPortrait()` |
| playSound | `eventId: string` | `void` | `obj:playSound(eventId)` |
| fencingConfirmationCallback | `b: integer` | `void` | `obj:fencingConfirmationCallback(b)` |
| getPlayerTradeCharacter | `` | `RootObject` | `obj:getPlayerTradeCharacter()` |
| refreshAllSections | `` | `void` | `obj:refreshAllSections()` |
| updateDatapanel | `` | `void` | `obj:updateDatapanel()` |
| rightClickAutoEquipping | `` | `void` | `obj:rightClickAutoEquipping()` |
| tryToEquip | `replace: boolean` | `boolean` | `obj:tryToEquip(replace)` |
| returnItem | `sectionName: string` | `void` | `obj:returnItem(sectionName)` |
| hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getSectionWithMouseLocal | `` | `string` | `obj:getSectionWithMouseLocal()` |
| getSlotWithMouse | `` | `void` | `obj:getSlotWithMouse()` |

## InventoryGUI_FenceCallbackData
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `InventoryGUI::FenceCallbackData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## InventoryIcon
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| item | Item | RW | `obj.item = <value>` |
| image | lightuserdata | R | `obj.image` |
| quantityText | lightuserdata | R | `obj.quantityText` |
| chargesProgress | lightuserdata | R | `obj.chargesProgress` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## InventoryItemBase
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| manufacturerData | GameData | RW | `obj.manufacturerData = <value>` |
| materialData | GameData | RW | `obj.materialData = <value>` |
| coloriseData | GameData | RW | `obj.coloriseData = <value>` |
| isInInventory | boolean | RW | `obj.isInInventory = <value>` |
| inventoryPos | iVector2 | RW | `obj.inventoryPos = <value>` |
| inventorySection | string | RW | `obj.inventorySection = <value>` |
| slotType | integer | RW | `obj.slotType = <value>` |
| originalFullChargeAmount | number | RW | `obj.originalFullChargeAmount = <value>` |
| chargesLeft | number | RW | `obj.chargesLeft = <value>` |
| quality | number | RW | `obj.quality = <value>` |
| weight | number | RW | `obj.weight = <value>` |
| itemFunction | integer | RW | `obj.itemFunction = <value>` |
| isTradeItem | boolean | RW | `obj.isTradeItem = <value>` |
| isEquipped | boolean | RW | `obj.isEquipped = <value>` |
| isUnique | boolean | RW | `obj.isUnique = <value>` |
| quantity | integer | RW | `obj.quantity = <value>` |
| itemWidth | integer | RW | `obj.itemWidth = <value>` |
| itemHeight | integer | RW | `obj.itemHeight = <value>` |
| deathItem | boolean | RW | `obj.deathItem = <value>` |
| objectType | integer | RW | `obj.objectType = <value>` |
| properOwner | unknown | RW | `obj.properOwner = <value>` |
| _whosInventoryWeAreIn | unknown | RW | `obj._whosInventoryWeAreIn = <value>` |
| _isResearchArtifact | boolean | RW | `obj._isResearchArtifact = <value>` |
| itemGroup | lightuserdata | R | `obj.itemGroup` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| deactivate | `` | `void` | `obj:deactivate()` |
| resetAfterCopy | `` | `void` | `obj:resetAfterCopy()` |
| resetCharges | `randomise: boolean` | `void` | `obj:resetCharges(randomise)` |
| getItemType | `` | `integer` | `obj:getItemType()` |
| getItemWeightSingle | `` | `number` | `obj:getItemWeightSingle()` |
| _NV_getItemWeightSingle | `` | `number` | `obj:_NV_getItemWeightSingle()` |
| getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _NV_getItemWeight | `` | `number` | `obj:_NV_getItemWeight()` |
| _serialise | `_a2: integer` | `GameData` | `obj:_serialise(_a2)` |
| _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| serialiseInInventory | `` | `GameData` | `obj:serialiseInInventory()` |
| loadFromSerialiseInInventory | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| getAvgPrice | `` | `integer` | `obj:getAvgPrice()` |
| getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| getValueAll | `isPlayer: boolean` | `integer` | `obj:getValueAll(isPlayer)` |
| _NV_getValueAll | `isPlayer: boolean` | `integer` | `obj:_NV_getValueAll(isPlayer)` |
| getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:getMaxAffordableNum(cashLimit, isPlayer)` |
| _NV_getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:_NV_getMaxAffordableNum(cashLimit, isPlayer)` |
| isStackable | `` | `integer` | `obj:isStackable()` |
| canStackWith | `` | `boolean` | `obj:canStackWith()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| isSameAs | `` | `boolean` | `obj:isSameAs()` |
| _NV_isSameAs | `` | `boolean` | `obj:_NV_isSameAs()` |
| onGround | `` | `boolean` | `obj:onGround()` |
| isResearchArtifact | `` | `boolean` | `obj:isResearchArtifact()` |
| getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| getItemSound | `` | `lightuserdata` | `obj:getItemSound()` |
| isStolen | `includeUnknown: boolean` | `boolean` | `obj:isStolen(includeUnknown)` |
| _CONSTRUCTOR | `` | `InventoryItemBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| merchantPriceMod | `` | `number` | `obj:merchantPriceMod()` |

## InventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| datapanel | DatapanelGUI | RW | `obj.datapanel = <value>` |
| dataPanelInfos | GameDataCopyStandalone | RW | `obj.dataPanelInfos = <value>` |
| window | lightuserdata | R | `obj.window` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `file: string` | `InventoryLayout` | `obj:_CONSTRUCTOR(file)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWindow | `` | `lightuserdata` | `obj:getWindow()` |
| getWidget | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| getDatapanel | `` | `DatapanelGUI` | `obj:getDatapanel()` |
| _NV_getDatapanel | `` | `DatapanelGUI` | `obj:_NV_getDatapanel()` |
| setupDataPanelInfos | `name: string` | `void` | `obj:setupDataPanelInfos(name)` |
| createSectionGUI | `` | `InventorySectionGUI` | `obj:createSectionGUI()` |
| setSectionGUIDisabled | `sectionName: string, width: integer, height: integer` | `void` | `obj:setSectionGUIDisabled(sectionName, width, height)` |

## InventorySection
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |
| width | integer | RW | `obj.width = <value>` |
| height | integer | RW | `obj.height = <value>` |
| armourOnly | boolean | RW | `obj.armourOnly = <value>` |
| stackingBonusMin | integer | RW | `obj.stackingBonusMin = <value>` |
| stackingBonusMult | number | RW | `obj.stackingBonusMult = <value>` |
| itemsLimit | integer | RW | `obj.itemsLimit = <value>` |
| weightMultiplier | number | RW | `obj.weightMultiplier = <value>` |
| totalWeight | number | RW | `obj.totalWeight = <value>` |
| isAnEquippedItemSection | boolean | RW | `obj.isAnEquippedItemSection = <value>` |
| limitedSlot | integer | RW | `obj.limitedSlot = <value>` |
| containerSlot | boolean | RW | `obj.containerSlot = <value>` |
| callbackObject | RootObject | RW | `obj.callbackObject = <value>` |
| parentInventory | Inventory | RW | `obj.parentInventory = <value>` |
| enabled | boolean | RW | `obj.enabled = <value>` |
| content | Array2d<Item> | R | `obj.content` |
| items | Ogre::vector<InventorySection::SectionItem>::type | R | `obj.items` |
| veryLimitedSlot | lektor<GameData*> | RW | `obj.veryLimitedSlot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_name: string, _w: integer, _h: integer, slot: integer, _containerSlot: boolean, _equipSlot: boolean, enabled: boolean` | `InventorySection` | `obj:_CONSTRUCTOR(_name, _w, _h, slot, _containerSlot, _equipSlot, enabled)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| hasRoomForItem | `quantity: integer` | `boolean` | `obj:hasRoomForItem(quantity)` |
| _NV_hasRoomForItem | `quantity: integer` | `boolean` | `obj:_NV_hasRoomForItem(quantity)` |
| notifyModified | `` | `void` | `obj:notifyModified()` |
| addItem | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |
| _NV_addItem | `quantity: integer` | `boolean` | `obj:_NV_addItem(quantity)` |
| _addItem | `x: integer, y: integer` | `void` | `obj:_addItem(x, y)` |
| _NV__addItem | `x: integer, y: integer` | `void` | `obj:_NV__addItem(x, y)` |
| getItemAt | `x: integer, y: integer` | `Item` | `obj:getItemAt(x, y)` |
| hasItemType | `type: integer` | `boolean` | `obj:hasItemType(type)` |
| autoArrange | `` | `void` | `obj:autoArrange()` |
| _NV_autoArrange | `` | `void` | `obj:_NV_autoArrange()` |
| getNumItems | `` | `integer` | `obj:getNumItems()` |
| isEmpty | `` | `boolean` | `obj:isEmpty()` |
| removeItem | `` | `boolean` | `obj:removeItem()` |
| clearAllItems | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAllItems(destroy, skipUnique)` |
| canItemGoHere | `x: integer, y: integer` | `boolean` | `obj:canItemGoHere(x, y)` |
| existsItemInFootprint | `x: integer, y: integer` | `boolean` | `obj:existsItemInFootprint(x, y)` |
| getLimitedSlot | `` | `integer` | `obj:getLimitedSlot()` |
| setupContainerData | `` | `void` | `obj:setupContainerData()` |
| applyStackingBonuses | `normalStackableAmount: integer` | `integer` | `obj:applyStackingBonuses(normalStackableAmount)` |
| recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| setWeightMultiplier | `mult: number` | `void` | `obj:setWeightMultiplier(mult)` |
| setStackingBonus | `minn: integer, mult: number` | `void` | `obj:setStackingBonus(minn, mult)` |
| getMaxStack | `` | `integer` | `obj:getMaxStack()` |
| addVeryLimitedSlot | `` | `void` | `obj:addVeryLimitedSlot()` |
| clearVeryLimitedSlot | `` | `void` | `obj:clearVeryLimitedSlot()` |
| getEnabled | `` | `boolean` | `obj:getEnabled()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| setItemsLimitCount | `value: integer` | `void` | `obj:setItemsLimitCount(value)` |
| getItemsLimitReached | `` | `boolean` | `obj:getItemsLimitReached()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| getFillPercentage | `` | `number` | `obj:getFillPercentage()` |
| getItem | `` | `Item` | `obj:getItem()` |
| setupEquipCallbacks | `` | `void` | `obj:setupEquipCallbacks()` |
| numItemsInFootprint | `x: integer, y: integer` | `integer` | `obj:numItemsInFootprint(x, y)` |
| resize | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resize(w, h, clearContent)` |
| hasItem | `` | `boolean` | `obj:hasItem()` |
| hasItem | `` | `boolean` | `obj:hasItem()` |
| isLimitedSlotCompatible | `` | `boolean` | `obj:isLimitedSlotCompatible()` |
| getValidInventoryPosition | `` | `boolean|integer` | `obj:getValidInventoryPosition()` |

## InventorySectionGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| widget | lightuserdata | R | `obj.widget` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| refreshIcons | `` | `void` | `obj:refreshIcons()` |
| update | `` | `void` | `obj:update()` |

## InventoryTradeData
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| inventory | InventoryGUI | RW | `obj.inventory = <value>` |
| paymentRequired | boolean | RW | `obj.paymentRequired = <value>` |
| canDropItems | boolean | RW | `obj.canDropItems = <value>` |
| isPlayer | boolean | RW | `obj.isPlayer = <value>` |
| owner | unknown | RW | `obj.owner = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isValid | `` | `boolean` | `obj:isValid()` |

## InventoryTraderGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| sectionWidth | integer | RW | `obj.sectionWidth = <value>` |
| sectionHeight | integer | RW | `obj.sectionHeight = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| _NV_getCallbackCharacter | `` | `Character` | `obj:_NV_getCallbackCharacter()` |
| getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _NV_getCallbackObject | `` | `RootObject` | `obj:_NV_getCallbackObject()` |
| refreshSection | `` | `void` | `obj:refreshSection()` |
| _NV_refreshSection | `` | `void` | `obj:_NV_refreshSection()` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| physicalShouldExist | boolean | RW | `obj.physicalShouldExist = <value>` |
| existAsBareWeapon | boolean | RW | `obj.existAsBareWeapon = <value>` |
| persistant | unknown | RW | `obj.persistant = <value>` |
| visible | boolean | RW | `obj.visible = <value>` |
| physical | lightuserdata | RW | `obj.physical = <value>` |
| _isPhysical | boolean | RW | `obj._isPhysical = <value>` |
| physicalEntity | lightuserdata | RW | `obj.physicalEntity = <value>` |
| creatingPhysical | boolean | RW | `obj.creatingPhysical = <value>` |
| fixedPhysicalPosition | boolean | RW | `obj.fixedPhysicalPosition = <value>` |
| useDynamicPhysics | boolean | RW | `obj.useDynamicPhysics = <value>` |
| loadingEntity | lightuserdata | RW | `obj.loadingEntity = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isGear | `` | `Gear` | `obj:isGear()` |
| _NV_isGear | `` | `Gear` | `obj:_NV_isGear()` |
| getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| resetAfterCopy | `` | `void` | `obj:resetAfterCopy()` |
| _NV_resetAfterCopy | `` | `void` | `obj:_NV_resetAfterCopy()` |
| deactivate | `` | `void` | `obj:deactivate()` |
| _NV_deactivate | `` | `void` | `obj:_NV_deactivate()` |
| setPositionRotation | `position: Vector3, rotation: Quaternion, fixedPosition: boolean` | `void` | `obj:setPositionRotation(position, rotation, fixedPosition)` |
| _NV_setPositionRotation | `position: Vector3, rotation: Quaternion, fixedPosition: boolean` | `void` | `obj:_NV_setPositionRotation(position, rotation, fixedPosition)` |
| isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| _NV_isCrossbow | `` | `Crossbow` | `obj:_NV_isCrossbow()` |
| isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| isWeapon | `` | `Weapon` | `obj:isWeapon()` |
| _NV_isWeapon | `` | `Weapon` | `obj:_NV_isWeapon()` |
| isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _NV_isLockedArmour | `` | `LockedArmour` | `obj:_NV_isLockedArmour()` |
| isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| _NV_isAFactionUniform | `` | `Faction` | `obj:_NV_isAFactionUniform()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| getModelName | `` | `string` | `obj:getModelName()` |
| _NV_getModelName | `` | `string` | `obj:_NV_getModelName()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| hasIngredients | `` | `boolean` | `obj:hasIngredients()` |
| _NV_hasIngredients | `` | `boolean` | `obj:_NV_hasIngredients()` |
| isGoodFood | `` | `boolean` | `obj:isGoodFood()` |
| _NV_isGoodFood | `` | `boolean` | `obj:_NV_isGoodFood()` |
| getEntity | `` | `lightuserdata` | `obj:getEntity()` |
| _NV_getEntity | `` | `lightuserdata` | `obj:_NV_getEntity()` |
| getTimeout | `` | `void` | `obj:getTimeout()` |
| _NV_getTimeout | `` | `void` | `obj:_NV_getTimeout()` |
| _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| serialiseInInventory | `` | `GameData` | `obj:serialiseInInventory()` |
| _NV_serialiseInInventory | `` | `GameData` | `obj:_NV_serialiseInInventory()` |
| loadFromSerialiseInInventory | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| _NV_loadFromSerialiseInInventory | `` | `void` | `obj:_NV_loadFromSerialiseInInventory()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| _NV_getCraftMaterialMult | `` | `number` | `obj:_NV_getCraftMaterialMult()` |
| getLevel | `` | `integer` | `obj:getLevel()` |
| _NV_getLevel | `` | `integer` | `obj:_NV_getLevel()` |
| destroyItemEntityCallback_Equipping | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| _NV_destroyItemEntityCallback_Equipping | `` | `void` | `obj:_NV_destroyItemEntityCallback_Equipping()` |
| isPersistant | `` | `boolean` | `obj:isPersistant()` |
| persistantOwnerExists | `` | `boolean` | `obj:persistantOwnerExists()` |
| _CONSTRUCTOR | `` | `Item` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| getInventoryWeAreIn | `` | `void` | `obj:getInventoryWeAreIn()` |
| setInventoryWeAreIn | `` | `void` | `obj:setInventoryWeAreIn()` |
| _NV_setInventoryWeAreIn | `` | `void` | `obj:_NV_setInventoryWeAreIn()` |
| isFood | `` | `boolean` | `obj:isFood()` |
| activate | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| _NV_activate | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:_NV_activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| serialise | `offset: userdata` | `void` | `obj:serialise(offset)` |
| _NV_serialise | `offset: userdata` | `void` | `obj:_NV_serialise(offset)` |
| createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:createItemEntityCallback_Equipping(ent, node)` |
| _NV_createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:_NV_createItemEntityCallback_Equipping(ent, node)` |
| notifyTheftFrom | `` | `void` | `obj:notifyTheftFrom()` |
| _NV_notifyTheftFrom | `` | `void` | `obj:_NV_notifyTheftFrom()` |
| findProperOwner | `` | `hand` | `obj:findProperOwner()` |
| setPersistant | `p: boolean` | `void` | `obj:setPersistant(p)` |
| itemEntityCreated | `ent: userdata` | `void` | `obj:itemEntityCreated(ent)` |
| _NV_itemEntityCreated | `ent: userdata` | `void` | `obj:_NV_itemEntityCreated(ent)` |

## ItemData
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| visible | boolean | RW | `obj.visible = <value>` |
| category | string | RW | `obj.category = <value>` |
| description | string | RW | `obj.description = <value>` |
| fileTypes | string | RW | `obj.fileTypes = <value>` |
| objectType | integer | RW | `obj.objectType = <value>` |
| maxSize | integer | RW | `obj.maxSize = <value>` |
| maxValue | integer | RW | `obj.maxValue = <value>` |
| minValue | integer | RW | `obj.minValue = <value>` |
| isSlider | boolean | RW | `obj.isSlider = <value>` |

## ItemListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |

## LevelEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| levelEditModeOn | boolean | RW | `obj.levelEditModeOn = <value>` |
| panel | lightuserdata | R | `obj.panel` |
| interiorModeWindow | lightuserdata | R | `obj.interiorModeWindow` |
| selectedLocked | integer | RW | `obj.selectedLocked = <value>` |
| selectedObject | unknown | RW | `obj.selectedObject = <value>` |
| selectedFeature | lightuserdata | R | `obj.selectedFeature` |
| seedMode | integer | RW | `obj.seedMode = <value>` |
| roadMode | integer | RW | `obj.roadMode = <value>` |
| roadIndex | integer | RW | `obj.roadIndex = <value>` |
| roadMarker | lightuserdata | R | `obj.roadMarker` |
| roadMakerMO | lightuserdata | R | `obj.roadMakerMO` |
| foliageEraser | lightuserdata | R | `obj.foliageEraser` |
| fogEditor | FogEditor | RW | `obj.fogEditor = <value>` |
| townListWindow | lightuserdata | R | `obj.townListWindow` |
| factionListWindow | lightuserdata | R | `obj.factionListWindow` |
| squadListWindow | lightuserdata | R | `obj.squadListWindow` |
| npcListWindow | lightuserdata | R | `obj.npcListWindow` |
| featureListWindow | lightuserdata | R | `obj.featureListWindow` |
| itemListWindow | lightuserdata | R | `obj.itemListWindow` |
| navmeshWindow | DatapanelGUI | RW | `obj.navmeshWindow = <value>` |
| editMapTitleWindow | lightuserdata | R | `obj.editMapTitleWindow` |
| factionTxt | lightuserdata | R | `obj.factionTxt` |
| altitudeTxt | lightuserdata | R | `obj.altitudeTxt` |
| activeModTxt | lightuserdata | R | `obj.activeModTxt` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| close | `` | `void` | `obj:close()` |
| update | `` | `void` | `obj:update()` |
| updateGizmo | `` | `boolean` | `obj:updateGizmo()` |
| levelEditMode | `on: boolean` | `void` | `obj:levelEditMode(on)` |
| isInteriorEditMode | `` | `boolean` | `obj:isInteriorEditMode()` |
| getActiveModIndex | `` | `integer` | `obj:getActiveModIndex()` |
| getActiveMod | `` | `string` | `obj:getActiveMod()` |
| isBaseActive | `` | `boolean` | `obj:isBaseActive()` |
| setEditSquad | `` | `void` | `obj:setEditSquad()` |
| repath | `` | `void` | `obj:repath()` |
| toggleSeedMode | `` | `void` | `obj:toggleSeedMode()` |
| clearSeedPoints | `` | `void` | `obj:clearSeedPoints()` |
| setSeedMode | `mode: integer` | `void` | `obj:setSeedMode(mode)` |
| toggleRoadEditor | `tab: integer` | `void` | `obj:toggleRoadEditor(tab)` |
| toggleFoliageRemoval | `` | `void` | `obj:toggleFoliageRemoval()` |
| clearChanges | `` | `boolean` | `obj:clearChanges()` |
| deleteDuplicateBuildings | `` | `integer` | `obj:deleteDuplicateBuildings()` |
| fixMountedBuildings | `` | `integer` | `obj:fixMountedBuildings()` |
| deleteAll | `confirmed: boolean` | `integer` | `obj:deleteAll(confirmed)` |
| adjustAltitudeSpeed | `s: number` | `void` | `obj:adjustAltitudeSpeed(s)` |
| fixInvalidInteriorFurnitureStates | `` | `integer` | `obj:fixInvalidInteriorFurnitureStates()` |
| fixBuildingFloorState | `` | `boolean` | `obj:fixBuildingFloorState()` |
| setSelectedObject | `` | `void` | `obj:setSelectedObject()` |
| updateRoadEditor | `` | `void` | `obj:updateRoadEditor()` |
| setRoadWidth | `` | `void` | `obj:setRoadWidth()` |
| setRoadHidden | `` | `void` | `obj:setRoadHidden()` |
| drawRoads | `` | `void` | `obj:drawRoads()` |
| eraseRoads | `` | `void` | `obj:eraseRoads()` |
| drawAllRoads | `` | `void` | `obj:drawAllRoads()` |
| projectRoads | `` | `void` | `obj:projectRoads()` |
| validateRoads | `` | `void` | `obj:validateRoads()` |
| createRoadMarker | `` | `void` | `obj:createRoadMarker()` |
| destroyRoadMaker | `` | `void` | `obj:destroyRoadMaker()` |
| updateFoliageRemoval | `` | `void` | `obj:updateFoliageRemoval()` |
| updateSeedEditor | `` | `void` | `obj:updateSeedEditor()` |

## LightBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/LightBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mountedBuilding | hand | R | `obj.mountedBuilding` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| needPowerRightNow | `` | `boolean` | `obj:needPowerRightNow()` |
| _NV_needPowerRightNow | `` | `boolean` | `obj:_NV_needPowerRightNow()` |
| getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getPositionMarker(currentPosition)` |
| _NV_getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:_NV_getPositionMarker(currentPosition)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## LightEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| light | lightuserdata | R | `obj.light` |
| brightness | number | RW | `obj.brightness = <value>` |
| range | number | RW | `obj.range = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setEnergyLevel | `level: number` | `void` | `obj:setEnergyLevel(level)` |
| setFloor | `floor: integer` | `void` | `obj:setFloor(floor)` |

## LimbsInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | Character | RW | `obj.character = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `LimbsInventoryLayout` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Limiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| racesExclude | std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > | R | `obj.racesExclude` |
| racesInclude | std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > | R | `obj.racesInclude` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| canEquip | `isAnimal: boolean` | `boolean` | `obj:canEquip(isAnimal)` |
| _NV_canEquip | `isAnimal: boolean` | `boolean` | `obj:_NV_canEquip(isAnimal)` |
| _CONSTRUCTOR | `` | `Limiter` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ListScrollBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_ListScrollBar.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| disableEvents | boolean | RW | `obj.disableEvents = <value>` |
| mListName | lightuserdata | R | `obj.mListName` |
| mListValue | lightuserdata | R | `obj.mListValue` |
| mListIndex | lightuserdata | R | `obj.mListIndex` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setEnabled | `_a1: boolean` | `void` | `obj:setEnabled(_a1)` |
| initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | `` | `void` | `obj:shutdownOverride()` |

## Listener
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## LoadSaveWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| list | lightuserdata | R | `obj.list` |
| infoPanel | DatapanelGUI | RW | `obj.infoPanel = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `layout: string` | `lightuserdata` | `obj:_CONSTRUCTOR(layout)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| select | `index: integer` | `void` | `obj:select(index)` |
| _NV_select | `index: integer` | `void` | `obj:_NV_select(index)` |
| getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| deleteSelectedSave | `mbResult: integer` | `void` | `obj:deleteSelectedSave(mbResult)` |
| addOption | `key: integer, check: string, label: string, caption: string` | `void` | `obj:addOption(key, check, label, caption)` |
| enableOption | `key: integer, enabled: boolean` | `void` | `obj:enableOption(key, enabled)` |
| getOptions | `` | `integer` | `obj:getOptions()` |

## LoadingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadingWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentIndex | integer | RW | `obj.currentIndex = <value>` |
| currentTime | number | RW | `obj.currentTime = <value>` |
| loadingText | lightuserdata | R | `obj.loadingText` |
| messageText | lightuserdata | R | `obj.messageText` |
| backgroundImage | lightuserdata | R | `obj.backgroundImage` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reload | `` | `void` | `obj:reload()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| show | `` | `void` | `obj:show()` |
| hide | `` | `void` | `obj:hide()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| frameEntered | `_frame: number` | `void` | `obj:frameEntered(_frame)` |
| setRandomBackground | `` | `void` | `obj:setRandomBackground()` |
| setRandomTip | `` | `void` | `obj:setRandomTip()` |

## LockedArmour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lock | lightuserdata | R | `obj.lock` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_level: integer` | `LockedArmour` | `obj:_CONSTRUCTOR(_level)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isArmour | `` | `Armour` | `obj:isArmour()` |
| _NV_isArmour | `` | `Armour` | `obj:_NV_isArmour()` |
| isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _NV_isLockedArmour | `` | `LockedArmour` | `obj:_NV_isLockedArmour()` |
| _serialise | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _NV__serialise | `type: integer` | `GameData` | `obj:_NV__serialise(type)` |
| _loadFromSerialise | `` | `void` | `obj:_loadFromSerialise()` |
| _NV__loadFromSerialise | `` | `void` | `obj:_NV__loadFromSerialise()` |

## Logger
**Header:** `extern/KenshiLib/Include/kenshi/logger.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| init | `` | `void` | `obj:init()` |
| close | `` | `void` | `obj:close()` |
| logMessage | `` | `void` | `obj:logMessage()` |
| logMessageDebug | `` | `void` | `obj:logMessageDebug()` |
| logHeader | `` | `void` | `obj:logHeader()` |

## MainBarGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| closeManagerWindowMsg | integer | RW | `obj.closeManagerWindowMsg = <value>` |
| isLevelEditMode | boolean | RW | `obj.isLevelEditMode = <value>` |
| isInteriorLevelEditMode | boolean | RW | `obj.isInteriorLevelEditMode = <value>` |
| bountyPanel | MyGUI::Widget | R | `obj.bountyPanel` |
| bountyDatapanel | DatapanelGUI | RW | `obj.bountyDatapanel = <value>` |
| townPanel | lightuserdata | R | `obj.townPanel` |
| portraitsTabPanel | MyGUI::Widget | R | `obj.portraitsTabPanel` |
| floorDownButton | MyGUI::Widget | R | `obj.floorDownButton` |
| floorUpButton | MyGUI::Widget | R | `obj.floorUpButton` |
| floorText | MyGUI::Widget | R | `obj.floorText` |
| dayText | MyGUI::Widget | R | `obj.dayText` |
| moneyLabel | MyGUI::Widget | R | `obj.moneyLabel` |
| moneyText | MyGUI::Widget | R | `obj.moneyText` |
| timeText | MyGUI::Widget | R | `obj.timeText` |
| medicalPanel | lightuserdata | R | `obj.medicalPanel` |
| ordersDataPanel | OrdersPanel | RW | `obj.ordersDataPanel = <value>` |
| extendInfoPanelButton | MyGUI::Widget | R | `obj.extendInfoPanelButton` |
| extendedInfoPanel | MyGUI::Widget | RW | `obj.extendedInfoPanel = <value>` |
| extendedInfoPanelDuration | number | RW | `obj.extendedInfoPanelDuration = <value>` |
| infoPanelEnabled | boolean | RW | `obj.infoPanelEnabled = <value>` |
| infoPanelExtended | boolean | RW | `obj.infoPanelExtended = <value>` |
| biomePanel | MyGUI::Widget | RW | `obj.biomePanel = <value>` |
| biomePanelText | MyGUI::Widget | R | `obj.biomePanelText` |
| biomePanelVisibleTimer | number | RW | `obj.biomePanelVisibleTimer = <value>` |
| biomeTimer | number | RW | `obj.biomeTimer = <value>` |
| lastFrameBiomeGroup | GameData | RW | `obj.lastFrameBiomeGroup = <value>` |
| rememberlastBiomeGroup | GameData | RW | `obj.rememberlastBiomeGroup = <value>` |
| portraitContextMenuTarget | unknown | RW | `obj.portraitContextMenuTarget = <value>` |
| portraitContextMenuTimer | number | RW | `obj.portraitContextMenuTimer = <value>` |
| portraitSelectedContextIndex | integer | RW | `obj.portraitSelectedContextIndex = <value>` |
| portraitsUpdating | boolean | RW | `obj.portraitsUpdating = <value>` |
| toolTip | ToolTipFixed | RW | `obj.toolTip = <value>` |
| pausePanel | MyGUI::Widget | R | `obj.pausePanel` |
| loadingPanel | MyGUI::Widget | R | `obj.loadingPanel` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `MainBarGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| speedChanged | `` | `void` | `obj:speedChanged()` |
| updateBountyPanelVisibility | `` | `void` | `obj:updateBountyPanelVisibility()` |
| _NV_updateBountyPanelVisibility | `` | `void` | `obj:_NV_updateBountyPanelVisibility()` |
| setLevelEditMode | `on: boolean` | `void` | `obj:setLevelEditMode(on)` |
| setLevelEditInteriorMode | `interiorMode: boolean` | `void` | `obj:setLevelEditInteriorMode(interiorMode)` |
| pressedKey | `keycode: integer` | `void` | `obj:pressedKey(keycode)` |
| platoonUpdated | `charAdded: boolean` | `void` | `obj:platoonUpdated(charAdded)` |
| updatePotraitsPlatoon | `` | `void` | `obj:updatePotraitsPlatoon()` |
| updatePortraits | `` | `void` | `obj:updatePortraits()` |
| refreshPortraitTabs | `` | `void` | `obj:refreshPortraitTabs()` |
| updatePortraitSize | `` | `void` | `obj:updatePortraitSize()` |
| getPausePanel | `` | `MyGUI::Widget` | `obj:getPausePanel()` |
| getLoadingPanel | `` | `MyGUI::Widget` | `obj:getLoadingPanel()` |
| getMedicalPanel | `` | `lightuserdata` | `obj:getMedicalPanel()` |
| ordersPanelClear | `` | `void` | `obj:ordersPanelClear()` |
| getToolTip | `` | `ToolTip` | `obj:getToolTip()` |
| _NV_getToolTip | `` | `ToolTip` | `obj:_NV_getToolTip()` |
| getDatapanel | `id: string` | `DatapanelGUI` | `obj:getDatapanel(id)` |
| setMessagePosition | `` | `void` | `obj:setMessagePosition()` |
| serialise | `` | `void` | `obj:serialise()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| setExtendInfoPanelEnabled | `enabled: boolean` | `void` | `obj:setExtendInfoPanelEnabled(enabled)` |
| _getWidget | `name: string` | `MyGUI::Widget` | `obj:_getWidget(name)` |
| autoChangeSelectedObject | `` | `void` | `obj:autoChangeSelectedObject()` |
| _NV_autoChangeSelectedObject | `` | `void` | `obj:_NV_autoChangeSelectedObject()` |
| getPortrait | `left: integer, top: integer` | `lightuserdata` | `obj:getPortrait(left, top)` |
| updatePortrait | `` | `void` | `obj:updatePortrait()` |
| closeMapWindow | `` | `void` | `obj:closeMapWindow()` |
| toggleMapWindow | `` | `void` | `obj:toggleMapWindow()` |
| toggleFactionWindow | `` | `void` | `obj:toggleFactionWindow()` |
| toggleTechWindow | `` | `void` | `obj:toggleTechWindow()` |
| toggleCraftWindow | `` | `void` | `obj:toggleCraftWindow()` |
| toggleSquadWindow | `` | `void` | `obj:toggleSquadWindow()` |
| changeFloorButtonUp | `` | `void` | `obj:changeFloorButtonUp()` |
| changeFloorButtonDown | `` | `void` | `obj:changeFloorButtonDown()` |
| ordersPanelFill | `` | `void` | `obj:ordersPanelFill()` |
| getBuildingInventoryPosition | `` | `void` | `obj:getBuildingInventoryPosition()` |
| getTabPlatoonPortrait | `idx: integer` | `MainTabPortraitPlatoon` | `obj:getTabPlatoonPortrait(idx)` |
| extendInfoPanel | `_a2: integer, _a3: integer, arg4: integer` | `void` | `obj:extendInfoPanel(_a2, _a3, arg4)` |
| toggleInventory | `` | `void` | `obj:toggleInventory()` |
| toggleStatsWindow | `` | `void` | `obj:toggleStatsWindow()` |
| toggleHelpWindow | `` | `void` | `obj:toggleHelpWindow()` |
| changeSpeed | `` | `void` | `obj:changeSpeed()` |
| buildButton | `` | `void` | `obj:buildButton()` |

## MainTabPortraitPlatoon
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| portraitBox | lightuserdata | R | `obj.portraitBox` |
| platoon | ActivePlatoon | RW | `obj.platoon = <value>` |
| tab | MyGUI::Widget | RW | `obj.tab = <value>` |
| tabIndex | integer | RW | `obj.tabIndex = <value>` |
| flashImage | MyGUI::Widget | R | `obj.flashImage` |
| flashing | integer | RW | `obj.flashing = <value>` |
| animationTime | number | RW | `obj.animationTime = <value>` |
| currentAlpha | number | RW | `obj.currentAlpha = <value>` |
| mainbar | MainBarGUI | RW | `obj.mainbar = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| addTab | `visible: boolean` | `void` | `obj:addTab(visible)` |
| detach | `` | `void` | `obj:detach()` |
| setFlash | `flash: boolean` | `void` | `obj:setFlash(flash)` |
| update | `` | `void` | `obj:update()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MainthreadStateReaderT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| swapMutex | unknown | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateBackDataCheck | `` | `boolean` | `obj:updateBackDataCheck()` |
| _NV_updateBackDataCheck | `` | `void` | `obj:_NV_updateBackDataCheck()` |
| getMainData | `` | `void` | `obj:getMainData()` |
| getBackData | `` | `void` | `obj:getBackData()` |

## ManagementScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| squadScreen | SquadManagementScreen | RW | `obj.squadScreen = <value>` |
| mapScreen | lightuserdata | R | `obj.mapScreen` |
| factionScreen | FactionsScreen | RW | `obj.factionScreen = <value>` |
| researchCategoriesListBox | lightuserdata | R | `obj.researchCategoriesListBox` |
| availableList | DatapanelGUI | RW | `obj.availableList = <value>` |
| info | DatapanelGUI | RW | `obj.info = <value>` |
| info2 | DatapanelGUI | RW | `obj.info2 = <value>` |
| techCategory | string | RW | `obj.techCategory = <value>` |
| currentResearch | GameData | RW | `obj.currentResearch = <value>` |
| researchBenchMessage | lightuserdata | R | `obj.researchBenchMessage` |
| researchDescriptionUpdateRequest | boolean | RW | `obj.researchDescriptionUpdateRequest = <value>` |
| lastResearchRate | number | RW | `obj.lastResearchRate = <value>` |
| todoList | lightuserdata | R | `obj.todoList` |
| craftingQueue | lightuserdata | R | `obj.craftingQueue` |
| messagesTextBox | lightuserdata | R | `obj.messagesTextBox` |
| messagesUpdated | boolean | RW | `obj.messagesUpdated = <value>` |
| messagesMutex | lightuserdata | R | `obj.messagesMutex` |
| messagesPlayerColor | string | RW | `obj.messagesPlayerColor = <value>` |
| messagesNPCColor | string | RW | `obj.messagesNPCColor = <value>` |
| aiScreen | DatapanelGUI | RW | `obj.aiScreen = <value>` |
| aiToolTip | ToolTip | RW | `obj.aiToolTip = <value>` |
| toolTip | ToolTip | RW | `obj.toolTip = <value>` |
| window | lightuserdata | R | `obj.window` |
| tabs | lightuserdata | R | `obj.tabs` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| clear | `` | `void` | `obj:clear()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `on: boolean, tab: integer` | `void` | `obj:setVisible(on, tab)` |
| getCurrentTab | `` | `integer` | `obj:getCurrentTab()` |
| getTab | `index: integer` | `lightuserdata` | `obj:getTab(index)` |
| getWidget | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| refresh | `progress: number` | `void` | `obj:refresh(progress)` |
| refreshResearchList | `` | `void` | `obj:refreshResearchList()` |
| refreshResearchRate | `` | `void` | `obj:refreshResearchRate()` |
| refreshDiplomacy | `` | `void` | `obj:refreshDiplomacy()` |
| refreshSquads | `` | `void` | `obj:refreshSquads()` |
| refreshMap | `centerCamera: boolean` | `void` | `obj:refreshMap(centerCamera)` |
| showRoads | `v: boolean` | `void` | `obj:showRoads(v)` |
| addSquadToMap | `` | `void` | `obj:addSquadToMap()` |
| removeSquadFromMap | `` | `void` | `obj:removeSquadFromMap()` |
| resetSquads | `` | `void` | `obj:resetSquads()` |
| refreshMessages | `` | `void` | `obj:refreshMessages()` |
| refreshAI | `` | `void` | `obj:refreshAI()` |
| showDebugMarker | `p: Vector3` | `void` | `obj:showDebugMarker(p)` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| updateResearchListRate | `` | `void` | `obj:updateResearchListRate()` |
| refreshResearchListDescription | `` | `void` | `obj:refreshResearchListDescription()` |

## ManagementScreen_TechItemViewData
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ManagementScreen::TechItemViewData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MapMarkerCharacter
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | unknown | RW | `obj.handle = <value>` |
| image | lightuserdata | R | `obj.image` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |

## MapMarkerTown
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | unknown | RW | `obj.handle = <value>` |
| zoomLayer | integer | RW | `obj.zoomLayer = <value>` |
| root | lightuserdata | R | `obj.root` |
| image | lightuserdata | R | `obj.image` |
| label | lightuserdata | R | `obj.label` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |

## MapScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| updateTimer | number | RW | `obj.updateTimer = <value>` |
| toolTip | ToolTip | RW | `obj.toolTip = <value>` |
| mainWidget | lightuserdata | R | `obj.mainWidget` |
| mapScrollView | lightuserdata | R | `obj.mapScrollView` |
| mapImage | lightuserdata | R | `obj.mapImage` |
| cameraMarker | lightuserdata | R | `obj.cameraMarker` |
| cameraMarkerSkin | lightuserdata | R | `obj.cameraMarkerSkin` |
| zoomUpdated | boolean | RW | `obj.zoomUpdated = <value>` |
| zoomValueBase | number | RW | `obj.zoomValueBase = <value>` |
| zoomValueMax | number | RW | `obj.zoomValueMax = <value>` |
| zoomValueCurrent | number | RW | `obj.zoomValueCurrent = <value>` |
| zoomLevelCurrent | integer | RW | `obj.zoomLevelCurrent = <value>` |
| mapOverlaysContainer | lightuserdata | R | `obj.mapOverlaysContainer` |
| zoomLevels | number | RW | `obj.zoomLevels = <value>` |
| mapMarkerMovement | lightuserdata | RW | `obj.mapMarkerMovement = <value>` |
| mapMarkerMovementPosition | Vector3 | RW | `obj.mapMarkerMovementPosition = <value>` |
| mapMarkerMovementFadeOutDelay | number | RW | `obj.mapMarkerMovementFadeOutDelay = <value>` |
| mapDragging | boolean | RW | `obj.mapDragging = <value>` |
| mapMouseLastPosition | unknown | RW | `obj.mapMouseLastPosition = <value>` |
| mapOffsetView | unknown | RW | `obj.mapOffsetView = <value>` |
| worldSize | unknown | RW | `obj.worldSize = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| centerCamera | `` | `void` | `obj:centerCamera()` |
| clearTempMarkers | `` | `void` | `obj:clearTempMarkers()` |
| refresh | `` | `void` | `obj:refresh()` |
| update | `` | `void` | `obj:update()` |
| addSquad | `` | `void` | `obj:addSquad()` |
| removeSquad | `` | `void` | `obj:removeSquad()` |
| hide | `` | `void` | `obj:hide()` |
| setMovementMarker | `p: Vector3, time: number` | `void` | `obj:setMovementMarker(p, time)` |
| showRoads | `on: boolean` | `void` | `obj:showRoads(on)` |
| updateZoom | `` | `void` | `obj:updateZoom()` |
| updateCameraMarker | `` | `void` | `obj:updateCameraMarker()` |
| refreshTowns | `` | `void` | `obj:refreshTowns()` |
| refreshSquads | `` | `void` | `obj:refreshSquads()` |
| updateCharacterMarker | `` | `void` | `obj:updateCharacterMarker()` |
| getMouseWorldPosition | `position: Vector3` | `boolean` | `obj:getMouseWorldPosition(position)` |
| setupRoads | `` | `void` | `obj:setupRoads()` |
| updateRoads | `` | `void` | `obj:updateRoads()` |

## MapScreen_MapRoad
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `MapScreen::MapRoad` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedianFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isPositionsFilter | boolean | RW | `obj.isPositionsFilter = <value>` |
| edgeSkips | integer | RW | `obj.edgeSkips = <value>` |
| maxLength | integer | RW | `obj.maxLength = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `MedianFilter` | `obj:_CONSTRUCTOR()` |
| setup | `numFrames: integer, numSamples: integer, _isPositionsFilter: boolean` | `void` | `obj:setup(numFrames, numSamples, _isPositionsFilter)` |
| reset | `` | `void` | `obj:reset()` |
| applySilent | `delta_mouse_x: number` | `void` | `obj:applySilent(delta_mouse_x)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedianFilter2DVector
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| filters | unknown | RW | `obj.filters = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `MedianFilter2DVector` | `obj:_CONSTRUCTOR()` |
| setup | `numFrames: integer, numSamples: integer, positions: boolean` | `void` | `obj:setup(numFrames, numSamples, positions)` |
| reset | `` | `void` | `obj:reset()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| status | unknown | RW | `obj.status = <value>` |
| armourList | lektor<Armour*> | RW | `obj.armourList = <value>` |
| hunger | number | RW | `obj.hunger = <value>` |
| fed | number | RW | `obj.fed = <value>` |
| lastPeriodicUpdate | TimeOfDay | RW | `obj.lastPeriodicUpdate = <value>` |
| blood | number | RW | `obj.blood = <value>` |
| extraBloodLossFromBodyparts | number | RW | `obj.extraBloodLossFromBodyparts = <value>` |
| currentBleedRate | number | RW | `obj.currentBleedRate = <value>` |
| leftLeg | MedicalSystem::HealthPartStatus | RW | `obj.leftLeg = <value>` |
| rightLeg | MedicalSystem::HealthPartStatus | RW | `obj.rightLeg = <value>` |
| leftArm | MedicalSystem::HealthPartStatus | RW | `obj.leftArm = <value>` |
| rightArm | MedicalSystem::HealthPartStatus | RW | `obj.rightArm = <value>` |
| knockoutTimer | number | RW | `obj.knockoutTimer = <value>` |
| worstDamage | number | RW | `obj.worstDamage = <value>` |
| needsFirstAidScoreTotal_robot | number | RW | `obj.needsFirstAidScoreTotal_robot = <value>` |
| needsFirstAidScoreTotal_fleshy | number | RW | `obj.needsFirstAidScoreTotal_fleshy = <value>` |
| restedState | number | RW | `obj.restedState = <value>` |
| stealthHinderance | number | RW | `obj.stealthHinderance = <value>` |
| partBestArm | number | RW | `obj.partBestArm = <value>` |
| partHead | number | RW | `obj.partHead = <value>` |
| partWorstTorso | number | RW | `obj.partWorstTorso = <value>` |
| dazedOrAlert | number | RW | `obj.dazedOrAlert = <value>` |
| robotLimbs | RobotLimbs | RW | `obj.robotLimbs = <value>` |
| bloodynessChanged | boolean | RW | `obj.bloodynessChanged = <value>` |
| bloodynessCleanedUp | boolean | RW | `obj.bloodynessCleanedUp = <value>` |
| me | Character | RW | `obj.me = <value>` |
| weatherGUIfeedback | StringPair | RW | `obj.weatherGUIfeedback = <value>` |
| currentWeatherAffect | integer | RW | `obj.currentWeatherAffect = <value>` |
| currentWeatherAffectStrength | number | RW | `obj.currentWeatherAffectStrength = <value>` |
| lastHungerKO | TimeOfDay | RW | `obj.lastHungerKO = <value>` |
| nextKOTime | number | RW | `obj.nextKOTime = <value>` |
| _eatenDeathDelay | integer | RW | `obj._eatenDeathDelay = <value>` |
| crippled | boolean | RW | `obj.crippled = <value>` |
| unconcious | boolean | RW | `obj.unconcious = <value>` |
| sub50KO | boolean | RW | `obj.sub50KO = <value>` |
| bloodlossTrauma | boolean | RW | `obj.bloodlossTrauma = <value>` |
| dead | boolean | RW | `obj.dead = <value>` |
| rightArmOk | boolean | RW | `obj.rightArmOk = <value>` |
| leftArmOk | boolean | RW | `obj.leftArmOk = <value>` |
| lastBloodPosition | Vector3 | RW | `obj.lastBloodPosition = <value>` |
| anatomy | lektor<MedicalSystem::HealthPartStatus*> | RW | `obj.anatomy = <value>` |
| stats | CharStats | RW | `obj.stats = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| precalculateFirstAidNeedScore | `` | `void` | `obj:precalculateFirstAidNeedScore()` |
| scoreFirstAidNeed | `robotAid: boolean` | `number` | `obj:scoreFirstAidNeed(robotAid)` |
| scoreJuryRigNeed | `skills: number` | `number` | `obj:scoreJuryRigNeed(skills)` |
| isFullyRested | `` | `boolean` | `obj:isFullyRested()` |
| validateHealthValues | `` | `void` | `obj:validateHealthValues()` |
| amputate | `limb: integer, createSeveredItem: boolean, force: Vector3` | `void` | `obj:amputate(limb, createSeveredItem, force)` |
| crushLimb | `limb: integer` | `void` | `obj:crushLimb(limb)` |
| isUselessNoLimbGuy | `` | `boolean` | `obj:isUselessNoLimbGuy()` |
| recalculateStealthHinderance | `` | `number` | `obj:recalculateStealthHinderance()` |
| getPartCount | `` | `integer` | `obj:getPartCount()` |
| hasRobotics | `` | `boolean` | `obj:hasRobotics()` |
| isFed | `` | `boolean` | `obj:isFed()` |
| getMaxBlood | `` | `number` | `obj:getMaxBlood()` |
| startKnockoutTimer | `` | `void` | `obj:startKnockoutTimer()` |
| knockout | `skill: number` | `void` | `obj:knockout(skill)` |
| knockoutForceTimer | `seconds: number` | `void` | `obj:knockoutForceTimer(seconds)` |
| pointOfCollapseBloodloss | `` | `number` | `obj:pointOfCollapseBloodloss()` |
| pointOfNoReturn | `` | `number` | `obj:pointOfNoReturn()` |
| isHungerKO | `` | `boolean` | `obj:isHungerKO()` |
| getToughnessXpBonus | `` | `number` | `obj:getToughnessXpBonus()` |
| getHungerSpeedModifier | `` | `number` | `obj:getHungerSpeedModifier()` |
| getMissingArmPenaltyMult | `` | `number` | `obj:getMissingArmPenaltyMult()` |
| getDerivedHeadHealth | `` | `number` | `obj:getDerivedHeadHealth()` |
| calculateDesiredPainAnimations | `` | `void` | `obj:calculateDesiredPainAnimations()` |
| getMovementSpeedInjuryMultiplier | `` | `number` | `obj:getMovementSpeedInjuryMultiplier()` |
| getMovementSwimSpeedInjuryMultiplier | `` | `number` | `obj:getMovementSwimSpeedInjuryMultiplier()` |
| gettingEaten | `amount: number, vampire: boolean` | `boolean` | `obj:gettingEaten(amount, vampire)` |
| gettingAcidRain | `amount: number` | `boolean` | `obj:gettingAcidRain(amount)` |
| gettingAcidWater | `amount: number` | `boolean` | `obj:gettingAcidWater(amount)` |
| gettingAcidFeet | `amount: number` | `boolean` | `obj:gettingAcidFeet(amount)` |
| gettingGassed | `amount: number` | `boolean` | `obj:gettingGassed(amount)` |
| gettingWindyface | `amount: number` | `boolean` | `obj:gettingWindyface(amount)` |
| gettingBurnt | `amount: number` | `boolean` | `obj:gettingBurnt(amount)` |
| reassessCollapseMode | `medic: boolean, agony: boolean` | `void` | `obj:reassessCollapseMode(medic, agony)` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| isCrippled | `` | `boolean` | `obj:isCrippled()` |
| isDead | `` | `boolean` | `obj:isDead()` |
| hasAnArmToFightWith | `` | `boolean` | `obj:hasAnArmToFightWith()` |
| hasFreshlySeveredALimb | `` | `boolean` | `obj:hasFreshlySeveredALimb()` |
| isReallyHungry | `` | `boolean` | `obj:isReallyHungry()` |
| isProbablyDying | `` | `boolean` | `obj:isProbablyDying()` |
| getOverallHealthRating | `` | `number` | `obj:getOverallHealthRating()` |
| canGetUpWakeUp | `` | `boolean` | `obj:canGetUpWakeUp()` |
| isRightArmOk | `` | `boolean` | `obj:isRightArmOk()` |
| isLeftArmOk | `` | `boolean` | `obj:isLeftArmOk()` |
| canIkick | `` | `boolean` | `obj:canIkick()` |
| isInBloodlossTrauma | `` | `boolean` | `obj:isInBloodlossTrauma()` |
| clearWeatherEffects | `` | `void` | `obj:clearWeatherEffects()` |
| getWeatherStatPenaltyMult | `` | `number` | `obj:getWeatherStatPenaltyMult()` |
| getWeatherStatPenalty | `mult: number` | `integer` | `obj:getWeatherStatPenalty(mult)` |
| calculateBleedRateForFX | `` | `number` | `obj:calculateBleedRateForFX()` |
| _setHealth | `` | `void` | `obj:_setHealth()` |
| getLimbState | `` | `void` | `obj:getLimbState()` |
| getPart | `` | `void` | `obj:getPart()` |
| addArmour | `` | `void` | `obj:addArmour()` |
| removeArmour | `` | `void` | `obj:removeArmour()` |
| wearingUniformOf | `` | `void` | `obj:wearingUniformOf()` |
| applyFirstAid | `` | `void` | `obj:applyFirstAid()` |
| applyDoctoring | `` | `void` | `obj:applyDoctoring()` |
| applyRigging | `` | `void` | `obj:applyRigging()` |

## MeshDataLookup
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| verts | lightuserdata | RW | `obj.verts = <value>` |
| uvs | lightuserdata | RW | `obj.uvs = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MeshLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| skeletonName | string | RW | `obj.skeletonName = <value>` |
| materialName | string | RW | `obj.materialName = <value>` |
| renderQueue | integer | RW | `obj.renderQueue = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MessageBoxManager
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`

## MessageChain
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| flush | `` | `boolean` | `obj:flush()` |

## MessageQueue
**Header:** `extern/KenshiLib/Include/kenshi/navmesh.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| s | integer | RW | `obj.s = <value>` |
| root | lightuserdata | R | `obj.root` |
| split | lightuserdata | R | `obj.split` |
| back | lightuserdata | R | `obj.back` |
| mutex | integer | RW | `obj.mutex = <value>` |

## MessageQueue_Node
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `MessageQueue_Node` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ModInfo
**Header:** `extern/KenshiLib/Include/kenshi/ModInfo.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |
| file | string | RW | `obj.file = <value>` |
| path | string | RW | `obj.path = <value>` |
| isWorkshop | boolean | RW | `obj.isWorkshop = <value>` |
| isBaseMod | boolean | RW | `obj.isBaseMod = <value>` |
| leveldataFolder | string | RW | `obj.leveldataFolder = <value>` |
| header | GameDataHeader | R | `obj.header` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MotionFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mWeightModifier | number | RW | `obj.mWeightModifier = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `length: integer, weight_modifier: number, fill: number` | `MotionFilter` | `obj:_CONSTRUCTOR(length, weight_modifier, fill)` |
| SetHistoryBufferLength | `length: integer, fill: number` | `boolean` | `obj:SetHistoryBufferLength(length, fill)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## MultiSlider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_MultiSlider.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mName | lightuserdata | R | `obj.mName` |
| mDisableEvents | boolean | RW | `obj.mDisableEvents = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | `` | `void` | `obj:shutdownOverride()` |

## MustEndWithSemiColon
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

## MyGUI
For full widget creation, layout loading, property access, and event handling reference, see the dedicated [MyGUI Bindings Documentation](MyGUI_Bindings.md).

## NavInstance
**Header:** `extern/KenshiLib/Include/kenshi/NavInstance.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mesh | lightuserdata | RW | `obj.mesh = <value>` |
| graph | lightuserdata | RW | `obj.graph = <value>` |
| graphInstance | lightuserdata | RW | `obj.graphInstance = <value>` |
| mediator | lightuserdata | RW | `obj.mediator = <value>` |
| instance | lightuserdata | RW | `obj.instance = <value>` |
| offset | Vector3 | RW | `obj.offset = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `arg5: unknown` | `NavInstance` | `obj:_CONSTRUCTOR(arg5)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMesh
**Header:** `extern/KenshiLib/Include/kenshi/navmesh.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| world | lightuserdata | RW | `obj.world = <value>` |
| shiftMutex | lightuserdata | R | `obj.shiftMutex` |
| worldShiftEnabled | boolean | RW | `obj.worldShiftEnabled = <value>` |
| running | boolean | RW | `obj.running = <value>` |
| worldX | number | RW | `obj.worldX = <value>` |
| worldY | number | RW | `obj.worldY = <value>` |
| cellSize | number | RW | `obj.cellSize = <value>` |
| worldShift | lightuserdata | RW | `obj.worldShift = <value>` |
| mutex | lightuserdata | R | `obj.mutex` |
| changeMutex | lightuserdata | R | `obj.changeMutex` |
| edgeFilter | lightuserdata | R | `obj.edgeFilter` |
| generator | lightuserdata | R | `obj.generator` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| initialise | `` | `void` | `obj:initialise()` |
| shutdown | `` | `void` | `obj:shutdown()` |
| create | `` | `void` | `obj:create()` |
| unload | `` | `void` | `obj:unload()` |
| destroy | `` | `void` | `obj:destroy()` |
| getZoneEdge | `start: Vector3, target: Vector3, offset: number` | `Vector3` | `obj:getZoneEdge(start, target, offset)` |
| getClosestExteriorPoint | `point: Vector3, radius: number, inset: number, out: Vector3` | `integer` | `obj:getClosestExteriorPoint(point, radius, inset, out)` |
| setDoorState | `open: boolean` | `void` | `obj:setDoorState(open)` |
| isInterior | `key: integer` | `boolean` | `obj:isInterior(key)` |
| getPositionValid | `point: Vector3` | `boolean` | `obj:getPositionValid(point)` |
| processCompletedCharacterMessages | `` | `void` | `obj:processCompletedCharacterMessages()` |
| processDoorRequests | `` | `void` | `obj:processDoorRequests()` |
| getPolygonID | `p: Vector3` | `string` | `obj:getPolygonID(p)` |
| validateFaceKey | `key: integer` | `boolean` | `obj:validateFaceKey(key)` |
| isGenerating | `` | `boolean` | `obj:isGenerating()` |
| getWorldShift | `` | `Vector3` | `obj:getWorldShift()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| update | `` | `boolean` | `obj:update()` |
| setupHavok | `` | `void` | `obj:setupHavok()` |
| shutdownHavok | `` | `void` | `obj:shutdownHavok()` |
| loadZone | `` | `void` | `obj:loadZone()` |
| unloadZone | `` | `void` | `obj:unloadZone()` |
| unloadBuilding | `` | `void` | `obj:unloadBuilding()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMeshGenerator
**Header:** `extern/KenshiLib/Include/kenshi/navmeshgenerator.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| queue | lightuserdata | R | `obj.queue` |
| done | lightuserdata | R | `obj.done` |
| current | lightuserdata | R | `obj.current` |
| navmesh | lightuserdata | R | `obj.navmesh` |
| needSave | boolean | RW | `obj.needSave = <value>` |
| settings | lightuserdata | R | `obj.settings` |
| threadRunning | boolean | RW | `obj.threadRunning = <value>` |
| doingStuff | boolean | RW | `obj.doingStuff = <value>` |
| taskMutex | lightuserdata | R | `obj.taskMutex` |
| lockedTask | lightuserdata | R | `obj.lockedTask` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isGenerating | `` | `boolean` | `obj:isGenerating()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| updateBT | `` | `boolean` | `obj:updateBT()` |
| generateTaskBT | `task: userdata` | `void` | `obj:generateTaskBT(task)` |
| validateBuildingStates | `task: userdata` | `integer` | `obj:validateBuildingStates(task)` |
| carve | `task: userdata` | `integer` | `obj:carve(task)` |
| splice | `t: userdata` | `integer` | `obj:splice(t)` |
| stitchInterior | `t: userdata` | `integer` | `obj:stitchInterior(t)` |
| stitchExterior | `t: userdata` | `integer` | `obj:stitchExterior(t)` |
| revertSettings | `` | `void` | `obj:revertSettings()` |
| unlockTask | `task: userdata` | `void` | `obj:unlockTask(task)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| hasJob | `` | `boolean` | `obj:hasJob()` |
| update | `` | `void` | `obj:update()` |

## NavMeshGenerator_Task
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `NavMeshGenerator::Task` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMeshGenerator_TaskQueue
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `NavMeshGenerator::TaskQueue` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMeshSeeds
**Header:** `extern/KenshiLib/Include/kenshi/navmeshgenerator.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| load | `` | `void` | `obj:load()` |
| save | `` | `void` | `obj:save()` |
| addSeedPoint | `p: Vector3, terrain: boolean` | `void` | `obj:addSeedPoint(p, terrain)` |
| removeSeedPoints | `pos: Vector3, radius: number` | `integer` | `obj:removeSeedPoints(pos, radius)` |
| clearSeedPoints | `` | `integer` | `obj:clearSeedPoints()` |
| removeIsland | `pos: Vector3, radius: number` | `integer` | `obj:removeIsland(pos, radius)` |
| projectToTerrain | `` | `void` | `obj:projectToTerrain()` |
| getSeedPoints | `` | `lightuserdata` | `obj:getSeedPoints()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMesh_BuildingInfo
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `hash: integer` | `NavMesh::BuildingInfo` | `obj:_CONSTRUCTOR(hash)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NavMesh_NavMeshMessage
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `NavMesh::NavMeshMessage` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NewGameOptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameOptionsWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| optionsPanel | DatapanelGUI | RW | `obj.optionsPanel = <value>` |
| tooltip | ToolTip | RW | `obj.tooltip = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| update | `` | `void` | `obj:update()` |

## NewGameWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentStart | integer | RW | `obj.currentStart = <value>` |
| startInfo | DatapanelGUI | RW | `obj.startInfo = <value>` |
| startNameTextBox | lightuserdata | R | `obj.startNameTextBox` |
| newGameOptions | NewGameOptionsWindow | RW | `obj.newGameOptions = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setRealPosition | `x: number, y: number` | `void` | `obj:setRealPosition(x, y)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| _NV_setPosition | `x: integer, y: integer` | `void` | `obj:_NV_setPosition(x, y)` |
| show | `_a1: boolean` | `void` | `obj:show(_a1)` |
| _NV_show | `_a1: boolean` | `void` | `obj:_NV_show(_a1)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| loadData | `` | `void` | `obj:loadData()` |
| updateCurrentData | `` | `void` | `obj:updateCurrentData()` |

## NpcListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |

## Nx9Real
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

## Nx9Real_S
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_12: number, _13: number, _21: number, _22: number, _23: number, _31: number, _32: number, _33: number` | `Nx9Real::S` | `obj:_CONSTRUCTOR(_12, _13, _21, _22, _23, _31, _32, _33)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NxBox
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## NxMat33
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setRowMajor | `d: userdata` | `void` | `obj:setRowMajor(d)` |
| getRowMajor | `d: userdata` | `void` | `obj:getRowMajor(d)` |
| getColumnMajor | `d: userdata` | `void` | `obj:getColumnMajor(d)` |
| setRowMajorStride4 | `d: userdata` | `void` | `obj:setRowMajorStride4(d)` |
| getRowMajorStride4 | `d: userdata` | `void` | `obj:getRowMajorStride4(d)` |
| getColumnMajorStride4 | `d: userdata` | `void` | `obj:getColumnMajorStride4(d)` |
| isFinite | `` | `boolean` | `obj:isFinite()` |
| zero | `` | `void` | `obj:zero()` |
| id | `` | `void` | `obj:id()` |

## NxUserControllerHitReport
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | `` | `NxUserControllerHitReport` | `obj:_CONSTRUCTOR()` |

## NxUserTriggerReport
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## NxVec3
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | number | RW | `obj.x = <value>` |
| y | number | RW | `obj.y = <value>` |
| z | number | RW | `obj.z = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| zero | `` | `void` | `obj:zero()` |
| isZero | `` | `integer` | `obj:isZero()` |
| normalize | `` | `number` | `obj:normalize()` |
| setMagnitude | `length: number` | `void` | `obj:setMagnitude(length)` |
| closestAxis | `` | `integer` | `obj:closestAxis()` |
| isFinite | `` | `boolean` | `obj:isFinite()` |
| magnitude | `` | `number` | `obj:magnitude()` |
| magnitudeSquared | `` | `number` | `obj:magnitudeSquared()` |

## ObjectInstance
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| pos | Vector3 | RW | `obj.pos = <value>` |
| rot | Quaternion | RW | `obj.rot = <value>` |
| refID | string | RW | `obj.refID = <value>` |
| created | integer | RW | `obj.created = <value>` |
| modified | integer | RW | `obj.modified = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OpenSaveFileDialog
**Header:** `extern/KenshiLib/Include/kenshi/gui/OpenSaveFileDialog.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| filesList | lightuserdata | R | `obj.filesList` |
| fileNameTxt | lightuserdata | R | `obj.fileNameTxt` |
| currentFolderList | lightuserdata | R | `obj.currentFolderList` |
| openSaveButton | lightuserdata | R | `obj.openSaveButton` |
| currentFolder | string | RW | `obj.currentFolder = <value>` |
| fileName | string | RW | `obj.fileName = <value>` |
| fileMask | string | RW | `obj.fileMask = <value>` |
| currentSelected | string | RW | `obj.currentSelected = <value>` |
| folderMode | boolean | RW | `obj.folderMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setDialogInfo | `_caption: string, _button: string, _folderMode: boolean` | `void` | `obj:setDialogInfo(_caption, _button, _folderMode)` |
| setCurrentFolder | `_folder: string` | `void` | `obj:setCurrentFolder(_folder)` |
| setFileName | `_value: string` | `void` | `obj:setFileName(_value)` |
| setFileMask | `_value: string` | `void` | `obj:setFileMask(_value)` |
| update | `` | `void` | `obj:update()` |

## OptionsHolder
**Header:** `extern/KenshiLib/Include/kenshi/OptionsHolder.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| CAMERA_MOVE_SPEED | number | RW | `obj.CAMERA_MOVE_SPEED = <value>` |
| CAMERA_PAN_SPEED | number | RW | `obj.CAMERA_PAN_SPEED = <value>` |
| CAMERA_TILT_SPEED | number | RW | `obj.CAMERA_TILT_SPEED = <value>` |
| CAMERA_ZOOM_SPEED | number | RW | `obj.CAMERA_ZOOM_SPEED = <value>` |
| invertX | number | RW | `obj.invertX = <value>` |
| invertY | number | RW | `obj.invertY = <value>` |
| VIEW_DISTANCE | number | RW | `obj.VIEW_DISTANCE = <value>` |
| terrainDetail | number | RW | `obj.terrainDetail = <value>` |
| terrainDistant | number | RW | `obj.terrainDistant = <value>` |
| terrainThreshold | number | RW | `obj.terrainThreshold = <value>` |
| terrainPatchSize | integer | RW | `obj.terrainPatchSize = <value>` |
| grassRange | number | RW | `obj.grassRange = <value>` |
| grassDensity | number | RW | `obj.grassDensity = <value>` |
| foliageRange | number | RW | `obj.foliageRange = <value>` |
| NPCRange | number | RW | `obj.NPCRange = <value>` |
| smallBuildingRange | number | RW | `obj.smallBuildingRange = <value>` |
| stencilsDisabled | boolean | RW | `obj.stencilsDisabled = <value>` |
| fancyShaders | boolean | RW | `obj.fancyShaders = <value>` |
| HWmouse | boolean | RW | `obj.HWmouse = <value>` |
| tutorials | boolean | RW | `obj.tutorials = <value>` |
| _enabledCivilians | boolean | RW | `obj._enabledCivilians = <value>` |
| populationMult | number | RW | `obj.populationMult = <value>` |
| squadSizeMult | number | RW | `obj.squadSizeMult = <value>` |
| raidSizeMult | number | RW | `obj.raidSizeMult = <value>` |
| raidFrequencyMult | number | RW | `obj.raidFrequencyMult = <value>` |
| passingAttacksOnBase | integer | RW | `obj.passingAttacksOnBase = <value>` |
| shadowMode | integer | RW | `obj.shadowMode = <value>` |
| shadowQuality | integer | RW | `obj.shadowQuality = <value>` |
| harpoonLimit | number | RW | `obj.harpoonLimit = <value>` |
| decalRange | number | RW | `obj.decalRange = <value>` |
| decalResolution | integer | RW | `obj.decalResolution = <value>` |
| characterMultithreading | boolean | RW | `obj.characterMultithreading = <value>` |
| limbLossFrequency | integer | RW | `obj.limbLossFrequency = <value>` |
| showNames | boolean | RW | `obj.showNames = <value>` |
| edgeScrolling | boolean | RW | `obj.edgeScrolling = <value>` |
| damageFloaters | integer | RW | `obj.damageFloaters = <value>` |
| showRotationMarker | boolean | RW | `obj.showRotationMarker = <value>` |
| showMoveMarker | boolean | RW | `obj.showMoveMarker = <value>` |
| fontSize | number | RW | `obj.fontSize = <value>` |
| manyActiveZones | boolean | RW | `obj.manyActiveZones = <value>` |
| distantTownRange | number | RW | `obj.distantTownRange = <value>` |
| featureRange | number | RW | `obj.featureRange = <value>` |
| generateDistantTowns | boolean | RW | `obj.generateDistantTowns = <value>` |
| shadowRange | number | RW | `obj.shadowRange = <value>` |
| ddsTextureMipMapGimping | integer | RW | `obj.ddsTextureMipMapGimping = <value>` |
| reflectionMode | integer | RW | `obj.reflectionMode = <value>` |
| reflectionDistance | number | RW | `obj.reflectionDistance = <value>` |
| compositors | lektor<std::pair<std::string, bool> > | R | `obj.compositors` |
| musicVolume | number | RW | `obj.musicVolume = <value>` |
| ambientVolume | number | RW | `obj.ambientVolume = <value>` |
| footstepVolume | number | RW | `obj.footstepVolume = <value>` |
| sfxVolume | number | RW | `obj.sfxVolume = <value>` |
| uiVolume | number | RW | `obj.uiVolume = <value>` |
| voVolume | number | RW | `obj.voVolume = <value>` |
| musicFrequency | number | RW | `obj.musicFrequency = <value>` |
| autosavetime | number | RW | `obj.autosavetime = <value>` |
| fullscreen | boolean | RW | `obj.fullscreen = <value>` |
| borderless | boolean | RW | `obj.borderless = <value>` |
| autosave | boolean | RW | `obj.autosave = <value>` |
| userSaves | boolean | RW | `obj.userSaves = <value>` |
| blood | boolean | RW | `obj.blood = <value>` |
| censorship | boolean | RW | `obj.censorship = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| enabledCivilians | `` | `boolean` | `obj:enabledCivilians()` |
| characterMultithreadingEnabled | `` | `boolean` | `obj:characterMultithreadingEnabled()` |
| compositiorEnabled | `name: string` | `boolean` | `obj:compositiorEnabled(name)` |
| loadCompositorSettings | `` | `void` | `obj:loadCompositorSettings()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/OptionsWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| invertX | boolean | RW | `obj.invertX = <value>` |
| invertY | boolean | RW | `obj.invertY = <value>` |
| resolutionIndex | integer | RW | `obj.resolutionIndex = <value>` |
| keyConfig | DataPanelLine_KeyConfig | RW | `obj.keyConfig = <value>` |
| keysDatapanel | DatapanelGUI | RW | `obj.keysDatapanel = <value>` |
| tabs | lightuserdata | R | `obj.tabs` |
| created | boolean | RW | `obj.created = <value>` |
| tooltip | ToolTip | RW | `obj.tooltip = <value>` |
| previewFontSize | boolean | RW | `obj.previewFontSize = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _NV_show | `value: boolean` | `void` | `obj:_NV_show(value)` |
| hide | `` | `void` | `obj:hide()` |
| toggle | `` | `void` | `obj:toggle()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| waitingForKey | `` | `boolean` | `obj:waitingForKey()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| _CONSTRUCTOR | `` | `OptionsWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| saveLocationChanged | `` | `void` | `obj:saveLocationChanged()` |
| changeFontSize | `` | `void` | `obj:changeFontSize()` |
| changeVolume | `` | `void` | `obj:changeVolume()` |
| toggleNames | `` | `void` | `obj:toggleNames()` |
| resetTutorials | `` | `void` | `obj:resetTutorials()` |
| toggleTutorials | `` | `void` | `obj:toggleTutorials()` |
| changeDistances | `` | `void` | `obj:changeDistances()` |
| toggleCompositor | `` | `void` | `obj:toggleCompositor()` |
| resetAllKeys | `` | `void` | `obj:resetAllKeys()` |
| saveOptions | `` | `void` | `obj:saveOptions()` |
| create | `` | `void` | `obj:create()` |
| updateResolutions | `` | `void` | `obj:updateResolutions()` |

## OrderCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| orderText | lightuserdata | R | `obj.orderText` |
| removeButton | lightuserdata | R | `obj.removeButton` |
| data | OrderData | RW | `obj.data = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWidget | `` | `lightuserdata` | `obj:getWidget()` |
| resize | `` | `void` | `obj:resize()` |

## OrderData
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| task | Tasker | RW | `obj.task = <value>` |
| index | integer | RW | `obj.index = <value>` |
| text | string | RW | `obj.text = <value>` |
| enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `OrderData` | `obj:_CONSTRUCTOR()` |
| set | `_index: integer, _enabled: boolean` | `void` | `obj:set(_index, _enabled)` |
| updateText | `` | `void` | `obj:updateText()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OrdersItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## OrdersPanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| ordersCharacter | unknown | RW | `obj.ordersCharacter = <value>` |
| ordersItemBox | OrdersItemBox | RW | `obj.ordersItemBox = <value>` |
| ordersItemWidth | integer | RW | `obj.ordersItemWidth = <value>` |
| ordersItemBoxScrollBarSize | integer | RW | `obj.ordersItemBoxScrollBarSize = <value>` |
| ordersItemBoxMaxVisible | integer | RW | `obj.ordersItemBoxMaxVisible = <value>` |
| ordersEmptyPanel | lightuserdata | R | `obj.ordersEmptyPanel` |
| blocksCheckbox | lightuserdata | R | `obj.blocksCheckbox` |
| holdCheckBox | lightuserdata | R | `obj.holdCheckBox` |
| passiveCheckBox | lightuserdata | R | `obj.passiveCheckBox` |
| chaseCheckBox | lightuserdata | R | `obj.chaseCheckBox` |
| tauntCheckBox | lightuserdata | R | `obj.tauntCheckBox` |
| rangedCheckBox | lightuserdata | R | `obj.rangedCheckBox` |
| stealthCheckBox | lightuserdata | R | `obj.stealthCheckBox` |
| speedPrevButton | lightuserdata | R | `obj.speedPrevButton` |
| speedNextButton | lightuserdata | R | `obj.speedNextButton` |
| speedImagePanel | lightuserdata | R | `obj.speedImagePanel` |
| speedImageNamesIdx | integer | RW | `obj.speedImageNamesIdx = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| clear | `` | `void` | `obj:clear()` |
| command | `cmd: integer` | `void` | `obj:command(cmd)` |
| refreshOrders | `` | `void` | `obj:refreshOrders()` |
| moveJob | `orderIdx: integer, targetIdx: integer` | `void` | `obj:moveJob(orderIdx, targetIdx)` |
| removeJob | `` | `void` | `obj:removeJob()` |
| notifyEndDropOrder | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropOrder(_sender, _result)` |
| setSpeed | `moveSpeed: integer` | `void` | `obj:setSpeed(moveSpeed)` |
| setSpeedImage | `moveSpeed: integer` | `void` | `obj:setSpeedImage(moveSpeed)` |

## Ownerships
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _homeTown | TownBase | RW | `obj._homeTown = <value>` |
| _homeBuilding | unknown | RW | `obj._homeBuilding = <value>` |
| faction | Faction | RW | `obj.faction = <value>` |
| me | Platoon | RW | `obj.me = <value>` |
| occupiedTown | TownBase | RW | `obj.occupiedTown = <value>` |
| money | integer | RW | `obj.money = <value>` |
| slaves | unknown | RW | `obj.slaves = <value>` |
| stuff | lektor<hand> | RW | `obj.stuff = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Ownerships` | `obj:_CONSTRUCTOR()` |
| setHandle | `` | `void` | `obj:setHandle()` |
| takeMoney | `val: integer` | `boolean` | `obj:takeMoney(val)` |
| _NV_takeMoney | `val: integer` | `boolean` | `obj:_NV_takeMoney(val)` |
| takeMoneyByForce | `val: integer` | `void` | `obj:takeMoneyByForce(val)` |
| _NV_takeMoneyByForce | `val: integer` | `void` | `obj:_NV_takeMoneyByForce(val)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| addMoney | `amount: integer` | `void` | `obj:addMoney(amount)` |
| setMoney | `amount: integer` | `void` | `obj:setMoney(amount)` |
| setHomeBuildingDesignation | `d: integer` | `void` | `obj:setHomeBuildingDesignation(d)` |
| copyFrom | `` | `void` | `obj:copyFrom()` |
| serialise | `` | `void` | `obj:serialise()` |
| load | `st: integer` | `void` | `obj:load(st)` |
| setHomeTown | `squadtype: integer` | `void` | `obj:setHomeTown(squadtype)` |
| isMyTown | `` | `boolean` | `obj:isMyTown()` |
| canIUseThisBuilding | `` | `boolean` | `obj:canIUseThisBuilding()` |
| declareOccupiedTown | `` | `void` | `obj:declareOccupiedTown()` |
| getOccupiedTownFaction | `` | `Faction` | `obj:getOccupiedTownFaction()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ParticlePool
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| limit | integer | RW | `obj.limit = <value>` |
| lastIndex | integer | RW | `obj.lastIndex = <value>` |
| particles | lightuserdata | R | `obj.particles` |
| maxTTL | number | RW | `obj.maxTTL = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `limit: integer, ttl: number` | `ParticlePool` | `obj:_CONSTRUCTOR(limit, ttl)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | `` | `void` | `obj:init()` |
| destroy | `` | `void` | `obj:destroy()` |
| getSize | `` | `integer` | `obj:getSize()` |
| update | `` | `void` | `obj:update()` |
| shiftParticles | `shift: Vector3` | `void` | `obj:shiftParticles(shift)` |

## ParticlePool_ParticleData
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ParticlePool::ParticleData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PhysicalEntity
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| ent | lightuserdata | R | `obj.ent` |
| parent | lightuserdata | R | `obj.parent` |
| floorNumber | integer | RW | `obj.floorNumber = <value>` |
| mat | GameData | RW | `obj.mat = <value>` |
| partData | GameData | RW | `obj.partData = <value>` |
| instanced | boolean | RW | `obj.instanced = <value>` |
| isShell | boolean | RW | `obj.isShell = <value>` |
| isEmissive | boolean | RW | `obj.isEmissive = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PhysicsActual
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| materialConcrete | lightuserdata | R | `obj.materialConcrete` |
| materialMetal | lightuserdata | R | `obj.materialMetal` |
| materialSand | lightuserdata | R | `obj.materialSand` |
| materialHuman | lightuserdata | R | `obj.materialHuman` |
| myTriggerCallback | lightuserdata | RW | `obj.myTriggerCallback = <value>` |
| HW | boolean | RW | `obj.HW = <value>` |
| debugRenderOn | boolean | RW | `obj.debugRenderOn = <value>` |
| scytheClass | lightuserdata | RW | `obj.scytheClass = <value>` |
| controllerMgr | lightuserdata | R | `obj.controllerMgr` |
| physicsSDK | lightuserdata | R | `obj.physicsSDK` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| _NV_updateUT | `` | `void` | `obj:_NV_updateUT()` |
| backThreadUpdate | `time: number, _useOwnTimers: boolean` | `void` | `obj:backThreadUpdate(time, _useOwnTimers)` |
| _NV_backThreadUpdate | `time: number, _useOwnTimers: boolean` | `void` | `obj:_NV_backThreadUpdate(time, _useOwnTimers)` |
| threadJunkPreBT | `` | `void` | `obj:threadJunkPreBT()` |
| threadJunkPostBT | `` | `void` | `obj:threadJunkPostBT()` |
| setup | `` | `boolean` | `obj:setup()` |
| scytheGetFirstModelName | `filename: string` | `string` | `obj:scytheGetFirstModelName(filename)` |
| _createTriggerHull | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:_createTriggerHull(pos, size)` |
| _createStaticCapsule | `pos: Vector3, length: number, radius: number` | `lightuserdata` | `obj:_createStaticCapsule(pos, length, radius)` |
| _createStaticBox | `pos: Vector3, dimensions: Vector3, rot: Quaternion, group: integer` | `lightuserdata` | `obj:_createStaticBox(pos, dimensions, rot, group)` |
| uncookMesh | `mesh: userdata, cId: string` | `boolean` | `obj:uncookMesh(mesh, cId)` |

## PhysicsClass
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`

## PhysicsCollection
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| findRotatingEnt | `` | `lightuserdata` | `obj:findRotatingEnt()` |
| getWindRotationPower | `` | `number` | `obj:getWindRotationPower()` |
| getWindMillPart | `` | `lightuserdata` | `obj:getWindMillPart()` |
| isLoaded | `` | `boolean` | `obj:isLoaded()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| update | `speed: number` | `void` | `obj:update(speed)` |
| updateAimingType | `speed: number, rotTarget: Vector3` | `number` | `obj:updateAimingType(speed, rotTarget)` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## PhysicsInterface
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nWorld | lightuserdata | R | `obj.nWorld` |
| _queuesClear | boolean | RW | `obj._queuesClear = <value>` |
| queuesClearMuto | lightuserdata | R | `obj.queuesClearMuto` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getBackthread | `` | `lightuserdata` | `obj:getBackthread()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| backThreadUpdate | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| createTriggerHull | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:createTriggerHull(pos, size)` |
| createStaticCapsule | `pos: Vector3, h: number, w: number` | `lightuserdata` | `obj:createStaticCapsule(pos, h, w)` |
| doorWantsSetup | `` | `void` | `obj:doorWantsSetup()` |
| scytheInsertPreview | `` | `boolean` | `obj:scytheInsertPreview()` |
| loadScytheFileMT | `file: string, pos: Vector3, q: Quaternion, boneAttachment: string` | `lightuserdata` | `obj:loadScytheFileMT(file, pos, q, boneAttachment)` |
| queuesAreClearMT | `` | `boolean` | `obj:queuesAreClearMT()` |
| setQueuesAreClear | `on: boolean` | `void` | `obj:setQueuesAreClear(on)` |

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| stringID | string | RW | `obj.stringID = <value>` |
| _characterCountCurrent | integer | RW | `obj._characterCountCurrent = <value>` |
| _characterCountOriginal | integer | RW | `obj._characterCountOriginal = <value>` |
| squadType | integer | RW | `obj.squadType = <value>` |
| hasUniques | YesNoMaybe | RW | `obj.hasUniques = <value>` |
| speedOverride | integer | RW | `obj.speedOverride = <value>` |
| isSeparatedSquad | unknown | RW | `obj.isSeparatedSquad = <value>` |
| canRefresh | boolean | RW | `obj.canRefresh = <value>` |
| regenerates | boolean | RW | `obj.regenerates = <value>` |
| myBaseHomeTownData | GameData | RW | `obj.myBaseHomeTownData = <value>` |
| priceMultWhenITrade | number | RW | `obj.priceMultWhenITrade = <value>` |
| _iBuyStolenGoods | boolean | RW | `obj._iBuyStolenGoods = <value>` |
| _iBuyIllegalGoods | boolean | RW | `obj._iBuyIllegalGoods = <value>` |
| locatorModel | lightuserdata | RW | `obj.locatorModel = <value>` |
| blackboard | lightuserdata | RW | `obj.blackboard = <value>` |
| _isIntact | boolean | RW | `obj._isIntact = <value>` |
| squadTemplate | GameData | RW | `obj.squadTemplate = <value>` |
| malnourishedLevel | number | RW | `obj.malnourishedLevel = <value>` |
| hasNeverBeenActivated | boolean | RW | `obj.hasNeverBeenActivated = <value>` |
| _persistentSquad | boolean | RW | `obj._persistentSquad = <value>` |
| isResidentSquad | boolean | RW | `obj.isResidentSquad = <value>` |
| currentSpawnArea | lightuserdata | RW | `obj.currentSpawnArea = <value>` |
| squadleader | unknown | RW | `obj.squadleader = <value>` |
| ownerships | Ownerships | RW | `obj.ownerships = <value>` |
| activePlatoon | ActivePlatoon | RW | `obj.activePlatoon = <value>` |
| unloadedPlatoon | lightuserdata | RW | `obj.unloadedPlatoon = <value>` |
| patrolSettings | lightuserdata | RW | `obj.patrolSettings = <value>` |
| isDead | boolean | RW | `obj.isDead = <value>` |
| imprisoned | boolean | RW | `obj.imprisoned = <value>` |
| index | integer | RW | `obj.index = <value>` |
| traderInventoryRefreshTime | TimeOfDay | RW | `obj.traderInventoryRefreshTime = <value>` |
| messageOnActivation | integer | RW | `obj.messageOnActivation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `p: Vector3, _persistent: boolean` | `Platoon` | `obj:_CONSTRUCTOR(p, _persistent)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCharacterCount | `count: integer` | `void` | `obj:setCharacterCount(count)` |
| chooseNewHome | `` | `void` | `obj:chooseNewHome()` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| getSquadType | `` | `integer` | `obj:getSquadType()` |
| setSquadType | `t: integer` | `void` | `obj:setSquadType(t)` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| hasCampaign | `` | `lightuserdata` | `obj:hasCampaign()` |
| iBuyStolenGoods | `` | `boolean` | `obj:iBuyStolenGoods()` |
| iBuyIllegalGoods | `` | `boolean` | `obj:iBuyIllegalGoods()` |
| setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| canTakeRefugees | `` | `boolean` | `obj:canTakeRefugees()` |
| isUnique | `` | `lightuserdata` | `obj:isUnique()` |
| _NV_isUnique | `` | `lightuserdata` | `obj:_NV_isUnique()` |
| getPlatoonStringID | `` | `string` | `obj:getPlatoonStringID()` |
| getBlackboard | `` | `lightuserdata` | `obj:getBlackboard()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| erasePlatoonFile | `` | `void` | `obj:erasePlatoonFile()` |
| showDebugMarker | `on: boolean` | `void` | `obj:showDebugMarker(on)` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| serialiseEverything | `levelEditor: boolean` | `GameData` | `obj:serialiseEverything(levelEditor)` |
| _NV_serialiseEverything | `levelEditor: boolean` | `GameData` | `obj:_NV_serialiseEverything(levelEditor)` |
| loadStateData | `` | `void` | `obj:loadStateData()` |
| _NV_loadStateData | `` | `void` | `obj:_NV_loadStateData()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| reprocessTask | `` | `void` | `obj:reprocessTask()` |
| taskIsComplete | `` | `void` | `obj:taskIsComplete()` |
| setDataFilename | `f: string` | `void` | `obj:setDataFilename(f)` |
| isIntact | `` | `boolean` | `obj:isIntact()` |
| notifyMissionEnded | `` | `void` | `obj:notifyMissionEnded()` |
| _NV_notifyMissionEnded | `` | `void` | `obj:_NV_notifyMissionEnded()` |
| activate | `` | `void` | `obj:activate()` |
| deactivate | `` | `void` | `obj:deactivate()` |
| declareDead | `` | `void` | `obj:declareDead()` |
| undeclareDead | `` | `void` | `obj:undeclareDead()` |
| isFullyLoaded | `` | `boolean` | `obj:isFullyLoaded()` |
| getActivePlatoon | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getUnloadedPlatoon | `` | `lightuserdata` | `obj:getUnloadedPlatoon()` |
| update | `` | `boolean` | `obj:update()` |
| _NV_update | `` | `boolean` | `obj:_NV_update()` |
| periodicUpdate_active | `time: number` | `void` | `obj:periodicUpdate_active(time)` |
| _NV_periodicUpdate_active | `time: number` | `void` | `obj:_NV_periodicUpdate_active(time)` |
| periodicUpdate_unloaded | `` | `void` | `obj:periodicUpdate_unloaded()` |
| _NV_periodicUpdate_unloaded | `` | `void` | `obj:_NV_periodicUpdate_unloaded()` |
| setupPatrolSettings | `minRange: integer, maxRange: integer` | `void` | `obj:setupPatrolSettings(minRange, maxRange)` |
| getPatrolInfo | `` | `lightuserdata` | `obj:getPatrolInfo()` |
| getRoamingMapArea | `` | `lightuserdata` | `obj:getRoamingMapArea()` |
| isPersistentSquad | `` | `boolean` | `obj:isPersistentSquad()` |
| setPersistentSquad | `on: boolean` | `void` | `obj:setPersistentSquad(on)` |
| getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| _NV_getOwnerships | `` | `Ownerships` | `obj:_NV_getOwnerships()` |
| getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getCharacterCount | `` | `integer` | `obj:getCharacterCount()` |
| getCharacterCount_Original | `` | `integer` | `obj:getCharacterCount_Original()` |
| needsNewCharacters | `` | `integer` | `obj:needsNewCharacters()` |
| reCheckPersistenceOnUnload | `` | `void` | `obj:reCheckPersistenceOnUnload()` |
| _NV_reCheckPersistenceOnUnload | `` | `void` | `obj:_NV_reCheckPersistenceOnUnload()` |
| serialise | `offsetPosToSubtract: userdata` | `void` | `obj:serialise(offsetPosToSubtract)` |
| _NV_serialise | `offsetPosToSubtract: userdata` | `void` | `obj:_NV_serialise(offsetPosToSubtract)` |
| setRoamingMapArea | `maparea: userdata` | `void` | `obj:setRoamingMapArea(maparea)` |
| getSquadLeader_theRealOne | `` | `void` | `obj:getSquadLeader_theRealOne()` |

## PlayerInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| factionName | string | RW | `obj.factionName = <value>` |
| camera | CameraClass | RW | `obj.camera = <value>` |
| technology | lightuserdata | RW | `obj.technology = <value>` |
| selectedObjectsChangedThisFrame | boolean | RW | `obj.selectedObjectsChangedThisFrame = <value>` |
| contextMenu | ContextMenu | RW | `obj.contextMenu = <value>` |
| selectBox | SelectionBox | RW | `obj.selectBox = <value>` |
| moveMarker | lightuserdata | RW | `obj.moveMarker = <value>` |
| selectedCharacter | unknown | RW | `obj.selectedCharacter = <value>` |
| aiOptions | PlayerInterface::AIOptions | RW | `obj.aiOptions = <value>` |
| interiorsVisibleHash | integer | RW | `obj.interiorsVisibleHash = <value>` |
| currentFloor | integer | RW | `obj.currentFloor = <value>` |
| currentMouseTask | integer | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | integer | RW | `obj.mouseTaskTypeRestriction = <value>` |
| mouseRightTargetSet | boolean | RW | `obj.mouseRightTargetSet = <value>` |
| mouseRightTarget | RootObject | RW | `obj.mouseRightTarget = <value>` |
| rmouseTimer | number | RW | `obj.rmouseTimer = <value>` |
| selectedObject | unknown | RW | `obj.selectedObject = <value>` |
| onlyAnimalsSelected | boolean | RW | `obj.onlyAnimalsSelected = <value>` |
| selectedLoadedLeft | integer | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterHandle | unknown | RW | `obj.trackedCharacterHandle = <value>` |
| trackedCharacterFloor | integer | RW | `obj.trackedCharacterFloor = <value>` |
| levelEditor | LevelEditor | RW | `obj.levelEditor = <value>` |
| participant | Faction | RW | `obj.participant = <value>` |
| currentPlatoon | Platoon | RW | `obj.currentPlatoon = <value>` |
| deadPlayerSquad | unknown | RW | `obj.deadPlayerSquad = <value>` |
| placementObject | lightuserdata | RW | `obj.placementObject = <value>` |
| characterEditorMode | boolean | RW | `obj.characterEditorMode = <value>` |
| mLeftUp | boolean | RW | `obj.mLeftUp = <value>` |
| mLeftDown | boolean | RW | `obj.mLeftDown = <value>` |
| mRightUp | boolean | RW | `obj.mRightUp = <value>` |
| mRightDown | boolean | RW | `obj.mRightDown = <value>` |
| interiorsVisible | ogre_unordered_set<hand>::type | RW | `obj.interiorsVisible = <value>` |
| playerCharacters | lektor<Character*> | RW | `obj.playerCharacters = <value>` |
| selectedCharacters | ogre_unordered_set<hand>::type | RW | `obj.selectedCharacters = <value>` |
| townsActive | ogre_unordered_set<TownBase*>::type | RW | `obj.townsActive = <value>` |
| zonesVisibilities | unknown | RW | `obj.zonesVisibilities = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `PlayerInterface` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getCamera | `` | `CameraClass` | `obj:getCamera()` |
| playerSetup | `` | `void` | `obj:playerSetup()` |
| clearAndReset | `` | `void` | `obj:clearAndReset()` |
| factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _NV_factoryObjectCreatedCallback | `` | `void` | `obj:_NV_factoryObjectCreatedCallback()` |
| setFaction | `` | `void` | `obj:setFaction()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| setCurrentPlatoon | `` | `boolean` | `obj:setCurrentPlatoon()` |
| getCurrentPlatoon | `` | `Platoon` | `obj:getCurrentPlatoon()` |
| getCurrentActivePlatoon | `` | `RootObjectContainer` | `obj:getCurrentActivePlatoon()` |
| createSquad | `` | `ActivePlatoon` | `obj:createSquad()` |
| getDeadSquad | `` | `ActivePlatoon` | `obj:getDeadSquad()` |
| update | `` | `void` | `obj:update()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| isBuildMode | `` | `boolean` | `obj:isBuildMode()` |
| activateObjectPlacementMode | `` | `void` | `obj:activateObjectPlacementMode()` |
| activateCharacterEditMode | `` | `void` | `obj:activateCharacterEditMode()` |
| triggerAreaArrivalDialogue | `` | `boolean` | `obj:triggerAreaArrivalDialogue()` |
| setCharacterEditMode | `on: boolean` | `void` | `obj:setCharacterEditMode(on)` |
| getCharacterEditMode | `` | `boolean` | `obj:getCharacterEditMode()` |
| unselectAll | `` | `void` | `obj:unselectAll()` |
| selectAll | `` | `void` | `obj:selectAll()` |
| selectObject | `modifier: boolean` | `void` | `obj:selectObject(modifier)` |
| selectPlayerCharacter | `index: integer, modifier: boolean, track: boolean` | `void` | `obj:selectPlayerCharacter(index, modifier, track)` |
| _selectPlayerCharacter | `modifier: boolean, track: boolean` | `void` | `obj:_selectPlayerCharacter(modifier, track)` |
| activateSelection | `` | `void` | `obj:activateSelection()` |
| getCameraCenter | `` | `Vector3` | `obj:getCameraCenter()` |
| getDistanceFromCamera | `v: Vector3` | `number` | `obj:getDistanceFromCamera(v)` |
| getSquaredDistanceFromCamera | `v: Vector3` | `number` | `obj:getSquaredDistanceFromCamera(v)` |
| startTrackCharacter | `` | `void` | `obj:startTrackCharacter()` |
| stopTrackCharacter | `` | `void` | `obj:stopTrackCharacter()` |
| isTrackingCharacter | `` | `boolean` | `obj:isTrackingCharacter()` |
| focusCamera | `pos: Vector3` | `void` | `obj:focusCamera(pos)` |
| manuallyOrientCamera | `rot: Quaternion, zoom: number` | `void` | `obj:manuallyOrientCamera(rot, zoom)` |
| focusCameraSelectedCharacter | `` | `void` | `obj:focusCameraSelectedCharacter()` |
| toggleLevelEditorOnSelectedTown | `` | `void` | `obj:toggleLevelEditorOnSelectedTown()` |
| isLevelEditMode | `` | `boolean` | `obj:isLevelEditMode()` |
| isObjectPlacementMode | `` | `boolean` | `obj:isObjectPlacementMode()` |
| setOrderSelectedCharacters | `order: integer` | `void` | `obj:setOrderSelectedCharacters(order)` |
| getLevelEditor | `` | `LevelEditor` | `obj:getLevelEditor()` |
| objectSelected | `select: boolean` | `void` | `obj:objectSelected(select)` |
| toggleObjectSelected | `` | `void` | `obj:toggleObjectSelected()` |
| isObjectSelected | `` | `boolean` | `obj:isObjectSelected()` |
| unselectPlayerCharacter | `` | `void` | `obj:unselectPlayerCharacter()` |
| getCurrentFloor | `` | `integer` | `obj:getCurrentFloor()` |
| setCurrentFloor | `floor: integer` | `void` | `obj:setCurrentFloor(floor)` |
| getNearestSelectedCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestSelectedCharacterTo(pos)` |
| getNearestCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestCharacterTo(pos)` |
| addOrderSelectedCharacters | `task: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addOrderSelectedCharacters(task, shift, addDontClear, location)` |
| addJobSelectedCharacters | `task: integer, shift: boolean, add: boolean, location: Vector3` | `void` | `obj:addJobSelectedCharacters(task, shift, add, location)` |
| removeJobSelectedCharacters | `t: integer` | `void` | `obj:removeJobSelectedCharacters(t)` |
| removePermaJobSelectedCharacters | `id: integer` | `void` | `obj:removePermaJobSelectedCharacters(id)` |
| selectedCharactersUnconcious | `displayMessage: boolean` | `boolean` | `obj:selectedCharactersUnconcious(displayMessage)` |
| selectedCharactersLayingLow | `` | `boolean` | `obj:selectedCharactersLayingLow()` |
| useSpeedGroup | `use: boolean` | `void` | `obj:useSpeedGroup(use)` |
| assignSpeedGroup | `create: boolean` | `void` | `obj:assignSpeedGroup(create)` |
| isEnemy | `` | `boolean` | `obj:isEnemy()` |
| isFactionKnown | `` | `boolean` | `obj:isFactionKnown()` |
| encounterFaction | `` | `void` | `obj:encounterFaction()` |
| pickupItem | `` | `void` | `obj:pickupItem()` |
| cycleSquad | `` | `void` | `obj:cycleSquad()` |
| cycleCharacter | `d: integer` | `void` | `obj:cycleCharacter(d)` |
| stopCharactersMovement | `` | `void` | `obj:stopCharactersMovement()` |
| getAnyPlayerCharacter | `` | `Character` | `obj:getAnyPlayerCharacter()` |
| isOrderValidForSelection | `task: integer` | `boolean` | `obj:isOrderValidForSelection(task)` |
| serialise | `` | `void` | `obj:serialise()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| getInteriorsVisible | `` | `boolean` | `obj:getInteriorsVisible()` |
| setVisibilityForReflections | `set: boolean` | `void` | `obj:setVisibilityForReflections(set)` |
| resetFloorsVisibility | `` | `void` | `obj:resetFloorsVisibility()` |
| setFloorsVisibility | `floor: integer` | `void` | `obj:setFloorsVisibility(floor)` |
| addTaskNearestSelectedCharacter | `t: integer, shift: boolean, location: Vector3, noAnimals: boolean` | `void` | `obj:addTaskNearestSelectedCharacter(t, shift, location, noAnimals)` |
| updateLastMoveWaypointSelectedCharacters | `location: Vector3` | `void` | `obj:updateLastMoveWaypointSelectedCharacters(location)` |
| clearSelection | `` | `void` | `obj:clearSelection()` |
| mouseScan | `` | `void` | `obj:mouseScan()` |
| characterSelected | `` | `void` | `obj:characterSelected()` |
| itemSelected | `` | `void` | `obj:itemSelected()` |
| buildingSelected | `position: Vector3, interiorsVisible: boolean` | `boolean` | `obj:buildingSelected(position, interiorsVisible)` |
| playerMove | `pos: Vector3` | `void` | `obj:playerMove(pos)` |
| _isPlayerCharacter | `` | `boolean` | `obj:_isPlayerCharacter()` |
| recruit | `editor: boolean` | `boolean` | `obj:recruit(editor)` |
| getDeadSquadHandle | `` | `hand` | `obj:getDeadSquadHandle()` |
| updatePlayerSelection | `` | `void` | `obj:updatePlayerSelection()` |
| getAllSelectedObjects | `type: integer` | `void` | `obj:getAllSelectedObjects(type)` |
| newPlayerTaskSelectedCharacters | `t: integer, clickpos: Vector3, addDontClear: boolean` | `void` | `obj:newPlayerTaskSelectedCharacters(t, clickpos, addDontClear)` |
| getPlayerTaskProbability | `task: integer` | `boolean|number` | `obj:getPlayerTaskProbability(task)` |
| getAllPlayerCharacters | `` | `lektor<Character*>` | `obj:getAllPlayerCharacters()` |
| updateFloorVisibility | `` | `void` | `obj:updateFloorVisibility()` |
| playerControl | `` | `void` | `obj:playerControl()` |

## PortraitData
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |
| flashing | integer | RW | `obj.flashing = <value>` |
| state | integer | RW | `obj.state = <value>` |
| reloadPortrait | boolean | RW | `obj.reloadPortrait = <value>` |
| characterHandle | unknown | RW | `obj.characterHandle = <value>` |
| updateRequested | boolean | RW | `obj.updateRequested = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| update | `` | `boolean` | `obj:update()` |
| forceUpdate | `` | `void` | `obj:forceUpdate()` |
| isSelected | `` | `boolean` | `obj:isSelected()` |
| isDown | `` | `boolean` | `obj:isDown()` |
| getBackgroundImageName | `` | `string` | `obj:getBackgroundImageName()` |
| getBackOverlayImageName | `` | `string` | `obj:getBackOverlayImageName()` |
| getFrontOverlayImageName | `` | `string` | `obj:getFrontOverlayImageName()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PortraitImage
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| index | integer | RW | `obj.index = <value>` |
| created | boolean | RW | `obj.created = <value>` |
| textureName | string | RW | `obj.textureName = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PortraitMainCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| characterHandle | unknown | RW | `obj.characterHandle = <value>` |
| name | string | RW | `obj.name = <value>` |
| border | lightuserdata | R | `obj.border` |
| imageBackground | lightuserdata | R | `obj.imageBackground` |
| imagePortrait | lightuserdata | R | `obj.imagePortrait` |
| imageOverlayBack | lightuserdata | R | `obj.imageOverlayBack` |
| imageOverlayFront | lightuserdata | R | `obj.imageOverlayFront` |
| textName | lightuserdata | R | `obj.textName` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resize | `size: integer` | `void` | `obj:resize(size)` |
| setName | `newName: string` | `void` | `obj:setName(newName)` |

## PortraitManager
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textureSize | iVector2 | RW | `obj.textureSize = <value>` |
| textureName | string | RW | `obj.textureName = <value>` |
| texturePortraitSize | iVector2 | RW | `obj.texturePortraitSize = <value>` |
| maxIndex | integer | RW | `obj.maxIndex = <value>` |
| imagesIndices | lightuserdata | R | `obj.imagesIndices` |
| disableUpdate | boolean | RW | `obj.disableUpdate = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| init | `` | `void` | `obj:init()` |
| destroy | `` | `void` | `obj:destroy()` |
| setUpdateEnabled | `enabled: boolean` | `void` | `obj:setUpdateEnabled(enabled)` |
| reloadPortraits | `` | `void` | `obj:reloadPortraits()` |
| reloadTexture | `` | `void` | `obj:reloadTexture()` |
| saveTexture | `` | `void` | `obj:saveTexture()` |
| clearPortraits | `loadTexture: boolean` | `void` | `obj:clearPortraits(loadTexture)` |
| getCharacterFlashing | `` | `boolean` | `obj:getCharacterFlashing()` |
| getCharacterInCombat | `` | `boolean` | `obj:getCharacterInCombat()` |
| getCharacterDown | `` | `boolean` | `obj:getCharacterDown()` |
| getSquadFlashing | `` | `boolean` | `obj:getSquadFlashing()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## PortraitSquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| characterHandle | unknown | RW | `obj.characterHandle = <value>` |
| name | string | RW | `obj.name = <value>` |
| border | lightuserdata | R | `obj.border` |
| imgBoxPortrait | lightuserdata | R | `obj.imgBoxPortrait` |
| txtName | lightuserdata | R | `obj.txtName` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| resize | `` | `void` | `obj:resize()` |
| setName | `newName: string` | `void` | `obj:setName(newName)` |

## PortraitSquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| squad | lightuserdata | R | `obj.squad` |
| squadView | lightuserdata | R | `obj.squadView` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getItemCount | `` | `integer` | `obj:getItemCount()` |
| update | `` | `void` | `obj:update()` |

## PreviewBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentNode | lightuserdata | R | `obj.parentNode` |
| isCurrentlySnapped | boolean | RW | `obj.isCurrentlySnapped = <value>` |
| snappedTo | Building | RW | `obj.snappedTo = <value>` |
| prospectingInformation | DatapanelGUI | RW | `obj.prospectingInformation = <value>` |
| prospectResource | integer | RW | `obj.prospectResource = <value>` |
| roofOnly | boolean | RW | `obj.roofOnly = <value>` |
| spaceAbove | number | RW | `obj.spaceAbove = <value>` |
| spaceBelow | number | RW | `obj.spaceBelow = <value>` |
| collisionOK | boolean | RW | `obj.collisionOK = <value>` |
| charactersOK | boolean | RW | `obj.charactersOK = <value>` |
| floorOk | boolean | RW | `obj.floorOk = <value>` |
| indoorsOK | boolean | RW | `obj.indoorsOK = <value>` |
| slopeOK | boolean | RW | `obj.slopeOK = <value>` |
| nodesOk | boolean | RW | `obj.nodesOk = <value>` |
| blockedBuildings | boolean | RW | `obj.blockedBuildings = <value>` |
| validGround | boolean | RW | `obj.validGround = <value>` |
| inTown | Town | RW | `obj.inTown = <value>` |
| floorNum | integer | RW | `obj.floorNum = <value>` |
| isOutside | boolean | RW | `obj.isOutside = <value>` |
| matchSlope | boolean | RW | `obj.matchSlope = <value>` |
| justBeenBuilt | Building | RW | `obj.justBeenBuilt = <value>` |
| yaw | number | RW | `obj.yaw = <value>` |
| centreOffset | Vector3 | RW | `obj.centreOffset = <value>` |
| isFurnitureOf | Building | RW | `obj.isFurnitureOf = <value>` |
| isIndoors | Building | RW | `obj.isIndoors = <value>` |
| buildDataPtr | GameData | RW | `obj.buildDataPtr = <value>` |
| farmData | GameData | RW | `obj.farmData = <value>` |
| prospectingOK | boolean | RW | `obj.prospectingOK = <value>` |
| furniture | boolean | RW | `obj.furniture = <value>` |
| exteriorFurniture | boolean | RW | `obj.exteriorFurniture = <value>` |
| pos | Vector3 | RW | `obj.pos = <value>` |
| rot | Quaternion | RW | `obj.rot = <value>` |
| positionHitGroup | integer | RW | `obj.positionHitGroup = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `PreviewBuilding` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| type | `` | `integer` | `obj:type()` |
| _NV_type | `` | `integer` | `obj:_NV_type()` |
| checkProspectingIsNotZero | `` | `boolean` | `obj:checkProspectingIsNotZero()` |
| _NV_checkProspectingIsNotZero | `` | `boolean` | `obj:_NV_checkProspectingIsNotZero()` |
| isASnapToBuilding | `` | `boolean` | `obj:isASnapToBuilding()` |
| _NV_isASnapToBuilding | `` | `boolean` | `obj:_NV_isASnapToBuilding()` |
| isACeilingBuilding | `` | `boolean` | `obj:isACeilingBuilding()` |
| _NV_isACeilingBuilding | `` | `boolean` | `obj:_NV_isACeilingBuilding()` |
| snappingOk | `` | `boolean` | `obj:snappingOk()` |
| _NV_snappingOk | `` | `boolean` | `obj:_NV_snappingOk()` |
| isInteriorBuilding | `` | `boolean` | `obj:isInteriorBuilding()` |
| _NV_isInteriorBuilding | `` | `boolean` | `obj:_NV_isInteriorBuilding()` |
| isCurrent | `` | `boolean` | `obj:isCurrent()` |
| setup | `` | `boolean` | `obj:setup()` |
| _NV_setup | `` | `boolean` | `obj:_NV_setup()` |
| _destroyEnts | `` | `void` | `obj:_destroyEnts()` |
| _NV__destroyEnts | `` | `void` | `obj:_NV__destroyEnts()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| figureOutWhichTown | `` | `void` | `obj:figureOutWhichTown()` |
| setVisualPosition | `position: Vector3` | `void` | `obj:setVisualPosition(position)` |
| _NV_setVisualPosition | `position: Vector3` | `void` | `obj:_NV_setVisualPosition(position)` |
| yawBy | `pan: number` | `void` | `obj:yawBy(pan)` |
| yawSet | `pan: number` | `void` | `obj:yawSet(pan)` |
| rotateBy | `by: Quaternion` | `void` | `obj:rotateBy(by)` |
| tilt | `pan: number` | `void` | `obj:tilt(pan)` |
| roll | `pan: number` | `void` | `obj:roll(pan)` |
| setRotation | `r: Quaternion` | `void` | `obj:setRotation(r)` |
| allFootprintsWantBelowGround | `` | `boolean` | `obj:allFootprintsWantBelowGround()` |
| allFootprintsWantAboveGround | `` | `boolean` | `obj:allFootprintsWantAboveGround()` |
| updateFootprintHeights | `` | `boolean` | `obj:updateFootprintHeights()` |
| isCollisionOK | `` | `boolean` | `obj:isCollisionOK()` |
| _NV_isCollisionOK | `` | `boolean` | `obj:_NV_isCollisionOK()` |
| isFloorOk | `` | `boolean` | `obj:isFloorOk()` |
| _NV_isFloorOk | `` | `boolean` | `obj:_NV_isFloorOk()` |
| isIndoorsOk | `` | `boolean` | `obj:isIndoorsOk()` |
| _NV_isIndoorsOk | `` | `boolean` | `obj:_NV_isIndoorsOk()` |
| isNodesOk | `` | `boolean` | `obj:isNodesOk()` |
| _NV_isNodesOk | `` | `boolean` | `obj:_NV_isNodesOk()` |
| isBlockingBuildingsNodes | `` | `boolean` | `obj:isBlockingBuildingsNodes()` |
| _NV_isBlockingBuildingsNodes | `` | `boolean` | `obj:_NV_isBlockingBuildingsNodes()` |
| isGoodAboveAndBelow | `` | `boolean` | `obj:isGoodAboveAndBelow()` |
| _NV_isGoodAboveAndBelow | `` | `boolean` | `obj:_NV_isGoodAboveAndBelow()` |
| isOnValidGround | `` | `boolean` | `obj:isOnValidGround()` |
| _NV_isOnValidGround | `` | `boolean` | `obj:_NV_isOnValidGround()` |
| isLinked | `` | `boolean` | `obj:isLinked()` |
| _NV_isLinked | `` | `boolean` | `obj:_NV_isLinked()` |
| moveHeightOffset | `h: number` | `void` | `obj:moveHeightOffset(h)` |
| resetHeightOffset | `` | `void` | `obj:resetHeightOffset()` |
| getFootprintShift | `` | `number` | `obj:getFootprintShift()` |
| setOrientation | `q: Quaternion` | `void` | `obj:setOrientation(q)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| setStartPosition | `p: Vector3` | `void` | `obj:setStartPosition(p)` |
| _NV_setStartPosition | `p: Vector3` | `void` | `obj:_NV_setStartPosition(p)` |
| setEndPosition | `position: Vector3` | `void` | `obj:setEndPosition(position)` |
| _NV_setEndPosition | `position: Vector3` | `void` | `obj:_NV_setEndPosition(position)` |
| getEndPos | `` | `Vector3` | `obj:getEndPos()` |
| _NV_getEndPos | `` | `Vector3` | `obj:_NV_getEndPos()` |
| clearPointersTo | `` | `void` | `obj:clearPointersTo()` |
| _NV_clearPointersTo | `` | `void` | `obj:_NV_clearPointersTo()` |
| placeFinalPreviewBuilding | `` | `void` | `obj:placeFinalPreviewBuilding()` |
| _NV_placeFinalPreviewBuilding | `` | `void` | `obj:_NV_placeFinalPreviewBuilding()` |
| insideBuilding | `` | `Building` | `obj:insideBuilding()` |
| placementVerification | `` | `boolean` | `obj:placementVerification()` |
| _NV_placementVerification | `` | `boolean` | `obj:_NV_placementVerification()` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| noAltitude | `` | `boolean` | `obj:noAltitude()` |
| _NV_noAltitude | `` | `boolean` | `obj:_NV_noAltitude()` |
| noPathfindingNeeded | `` | `boolean` | `obj:noPathfindingNeeded()` |
| _NV_noPathfindingNeeded | `` | `boolean` | `obj:_NV_noPathfindingNeeded()` |
| placePreview | `position: Vector3, rotation: Quaternion, floorNumber: integer` | `void` | `obj:placePreview(position, rotation, floorNumber)` |
| _NV_placePreview | `position: Vector3, rotation: Quaternion, floorNumber: integer` | `void` | `obj:_NV_placePreview(position, rotation, floorNumber)` |
| resetUseageNodes | `` | `void` | `obj:resetUseageNodes()` |
| calculateRotationsAndStuff | `position: Vector3` | `void` | `obj:calculateRotationsAndStuff(position)` |
| _NV_calculateRotationsAndStuff | `position: Vector3` | `void` | `obj:_NV_calculateRotationsAndStuff(position)` |
| placementVerification_recurse | `` | `boolean` | `obj:placementVerification_recurse()` |
| getTerrainHeightAtCenter | `` | `number` | `obj:getTerrainHeightAtCenter()` |
| _NV_getTerrainHeightAtCenter | `` | `number` | `obj:_NV_getTerrainHeightAtCenter()` |
| recalculateWorldAABB | `` | `void` | `obj:recalculateWorldAABB()` |
| validateUsageNodes | `` | `void` | `obj:validateUsageNodes()` |

## ProductionBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| productionState | integer | RW | `obj.productionState = <value>` |
| _resourceMiningLevel | number | RW | `obj._resourceMiningLevel = <value>` |
| outSection | InventorySection | R | `obj.outSection` |
| consumptionItems | lektor<StorageBuilding::ConsumptionItem> | R | `obj.consumptionItems` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getProductionBuilding | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| _NV_getProductionBuilding | `` | `ProductionBuilding` | `obj:_NV_getProductionBuilding()` |
| createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| getProductionMult | `` | `number` | `obj:getProductionMult()` |
| _NV_getProductionMult | `` | `number` | `obj:_NV_getProductionMult()` |
| getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| _NV_getProductionMultForGUI | `` | `number` | `obj:_NV_getProductionMultForGUI()` |
| setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| _NV_setupMiningResourceLevel | `` | `void` | `obj:_NV_setupMiningResourceLevel()` |
| getMiningResourceLevel | `` | `number` | `obj:getMiningResourceLevel()` |
| _NV_getMiningResourceLevel | `` | `number` | `obj:_NV_getMiningResourceLevel()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| isAnyInputsInvalidType | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| _NV_isAnyInputsInvalidType | `` | `boolean` | `obj:_NV_isAnyInputsInvalidType()` |
| isAnyInputsFull | `` | `boolean` | `obj:isAnyInputsFull()` |
| _NV_isAnyInputsFull | `` | `boolean` | `obj:_NV_isAnyInputsFull()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| isProductionEmpty | `` | `boolean` | `obj:isProductionEmpty()` |
| _NV_isProductionEmpty | `` | `boolean` | `obj:_NV_isProductionEmpty()` |
| getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| _NV_getOutputBasedRotationSpeedMult | `` | `number` | `obj:_NV_getOutputBasedRotationSpeedMult()` |
| getOutput | `` | `number` | `obj:getOutput()` |
| getNumConsumtionItems | `` | `integer` | `obj:getNumConsumtionItems()` |
| _NV_getNumConsumtionItems | `` | `integer` | `obj:_NV_getNumConsumtionItems()` |
| getConsumtionItems | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| _NV_getConsumtionItems | `id: integer` | `lightuserdata` | `obj:_NV_getConsumtionItems(id)` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| _NV_updateInventoryWindow | `` | `void` | `obj:_NV_updateInventoryWindow()` |
| updateInputs | `rate: number` | `void` | `obj:updateInputs(rate)` |
| _NV_updateInputs | `rate: number` | `void` | `obj:_NV_updateInputs(rate)` |
| updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| _NV_updateOutput | `rate: number` | `void` | `obj:_NV_updateOutput(rate)` |

## ProductionInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `title: string, ins: integer, outs: integer` | `ProductionInventoryLayout` | `obj:_CONSTRUCTOR(title, ins, outs)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ProgressBarWidget
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bar | lightuserdata | R | `obj.bar` |
| label | lightuserdata | R | `obj.label` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| setProgress | `value: integer` | `void` | `obj:setProgress(value)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setCaption | `value: string` | `void` | `obj:setCaption(value)` |

## ProspectingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/ProspectingWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | lightuserdata | R | `obj.window` |
| imgMap | lightuserdata | R | `obj.imgMap` |
| listResourcesPanel | lightuserdata | R | `obj.listResourcesPanel` |
| listResourcesSelected | lightuserdata | R | `obj.listResourcesSelected` |
| cameraMarker | lightuserdata | R | `obj.cameraMarker` |
| cameraMarkerSkin | lightuserdata | R | `obj.cameraMarkerSkin` |
| datapanelOverview1 | DatapanelGUI | RW | `obj.datapanelOverview1 = <value>` |
| datapanelOverview2 | DatapanelGUI | RW | `obj.datapanelOverview2 = <value>` |
| resourceImage | lightuserdata | R | `obj.resourceImage` |
| lastPos | Vector3 | RW | `obj.lastPos = <value>` |
| lastSkill | number | RW | `obj.lastSkill = <value>` |
| lastName | string | RW | `obj.lastName = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| showT | `pos: Vector3, skill: number, name: string` | `void` | `obj:showT(pos, skill, name)` |
| _show | `` | `void` | `obj:_show()` |
| hide | `` | `void` | `obj:hide()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| updateCameraMarker | `` | `void` | `obj:updateCameraMarker()` |
| updateMap | `resource: integer` | `void` | `obj:updateMap(resource)` |
| refresh | `` | `void` | `obj:refresh()` |
| clear | `` | `void` | `obj:clear()` |

## ProsperityManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| actualProsperity | number | RW | `obj.actualProsperity = <value>` |
| maxProsperity | number | RW | `obj.maxProsperity = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ProsperityManager` | `obj:_CONSTRUCTOR()` |
| setup | `` | `void` | `obj:setup()` |
| load | `` | `void` | `obj:load()` |
| save | `` | `void` | `obj:save()` |
| getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| update | `time: number` | `void` | `obj:update(time)` |
| notifySquadDefeated | `` | `void` | `obj:notifySquadDefeated()` |
| notifySpecialNPCDead | `` | `void` | `obj:notifySpecialNPCDead()` |

## RaceData
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | GameData | RW | `obj.data = <value>` |
| runSpeedMaxSkill | number | RW | `obj.runSpeedMaxSkill = <value>` |
| runSpeedMinSkill | number | RW | `obj.runSpeedMinSkill = <value>` |
| originalBloodMin | number | RW | `obj.originalBloodMin = <value>` |
| originalBloodMax | number | RW | `obj.originalBloodMax = <value>` |
| healRate | number | RW | `obj.healRate = <value>` |
| bleedRate | number | RW | `obj.bleedRate = <value>` |
| swimSpeed | number | RW | `obj.swimSpeed = <value>` |
| walkSpeed | number | RW | `obj.walkSpeed = <value>` |
| swimOffset | number | RW | `obj.swimOffset = <value>` |
| waterAvoidance | number | RW | `obj.waterAvoidance = <value>` |
| hungerRate | number | RW | `obj.hungerRate = <value>` |
| visionMultiplier | number | RW | `obj.visionMultiplier = <value>` |
| gigantic | boolean | RW | `obj.gigantic = <value>` |
| swims | boolean | RW | `obj.swims = <value>` |
| carriable | boolean | RW | `obj.carriable = <value>` |
| singleGender | boolean | RW | `obj.singleGender = <value>` |
| robot | boolean | RW | `obj.robot = <value>` |
| vampiric | boolean | RW | `obj.vampiric = <value>` |
| noHats | boolean | RW | `obj.noHats = <value>` |
| noShirts | boolean | RW | `obj.noShirts = <value>` |
| noShoes | boolean | RW | `obj.noShoes = <value>` |
| extraAttackSlots | integer | RW | `obj.extraAttackSlots = <value>` |
| firstAidSkill | integer | RW | `obj.firstAidSkill = <value>` |
| canGoIndoors | boolean | RW | `obj.canGoIndoors = <value>` |
| raceGroup | lightuserdata | RW | `obj.raceGroup = <value>` |
| bloodColour | unknown | RW | `obj.bloodColour = <value>` |
| specialFoods | ogre_unordered_set<GameData*>::type | RW | `obj.specialFoods = <value>` |
| statMods | unknown | RW | `obj.statMods = <value>` |
| weatherImmunities | ogre_unordered_set<WeatherAffecting>::type | RW | `obj.weatherImmunities = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `RaceData` | `obj:_CONSTRUCTOR()` |
| getRaceData | `` | `RaceData` | `obj:getRaceData()` |
| isRelatedRace | `` | `boolean` | `obj:isRelatedRace()` |
| isSpecificRace | `` | `boolean` | `obj:isSpecificRace()` |
| getStatMod | `stat: integer` | `number` | `obj:getStatMod(stat)` |
| isImmune | `w: integer` | `boolean` | `obj:isImmune(w)` |
| canEat | `isAnimal: boolean` | `boolean` | `obj:canEat(isAnimal)` |

## RaceLimiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| limits | ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type | R | `obj.limits` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addLimit | `` | `void` | `obj:addLimit()` |
| _CONSTRUCTOR | `` | `RaceLimiter` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## RainCollectorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/RainCollectorBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| _NV_calculateEfficiencyMult | `` | `number` | `obj:_NV_calculateEfficiencyMult()` |
| getRainAmount | `` | `number` | `obj:getRainAmount()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## RelationData
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| alliance | boolean | RW | `obj.alliance = <value>` |
| peaceTreaty | boolean | RW | `obj.peaceTreaty = <value>` |
| war | boolean | RW | `obj.war = <value>` |
| coexists | boolean | RW | `obj.coexists = <value>` |
| relation | number | RW | `obj.relation = <value>` |
| trustPositives | number | RW | `obj.trustPositives = <value>` |
| trustNegatives | number | RW | `obj.trustNegatives = <value>` |
| percievedStrength | number | RW | `obj.percievedStrength = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| save | `ID: string` | `void` | `obj:save(ID)` |
| load | `ID: string` | `void` | `obj:load(ID)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ReorderableList
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | lightuserdata | R | `obj.data` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| refresh | `force: boolean` | `void` | `obj:refresh(force)` |
| notifyEndDrop | `sender: integer, info: integer, result: boolean` | `void` | `obj:notifyEndDrop(sender, info, result)` |
| notifyRemoved | `index: integer` | `void` | `obj:notifyRemoved(index)` |

## RepetitionCounter
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| states | RepetitionStatesMapBinding::MapType | RW | `obj.states = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `` | `void` | `obj:setup()` |
| count | `ev: integer` | `boolean` | `obj:count(ev)` |
| getTimeSinceLastTrigger | `ev: integer` | `number` | `obj:getTimeSinceLastTrigger(ev)` |
| getCount | `ev: integer` | `integer` | `obj:getCount(ev)` |
| _CONSTRUCTOR | `` | `RepetitionCounter` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ResearchBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| _NV_dontNeedWorkRightNow | `` | `boolean` | `obj:_NV_dontNeedWorkRightNow()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| getTechLevel | `` | `integer` | `obj:getTechLevel()` |
| _NV_getTechLevel | `` | `integer` | `obj:_NV_getTechLevel()` |
| createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |

## ResearchBuildingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| researchButton | lightuserdata | R | `obj.researchButton` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| getResearchButton | `` | `lightuserdata` | `obj:getResearchButton()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ResourceLinePanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ProspectingWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| button | MyGUI::Widget | R | `obj.button` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |

## ResourceLoadRequestMesh
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| entity | lightuserdata | R | `obj.entity` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| finish | `` | `void` | `obj:finish()` |

## ResourceLoadRequestTexture
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textureUnitState | lightuserdata | R | `obj.textureUnitState` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isMaterialValid | `` | `boolean` | `obj:isMaterialValid()` |

## ResourceLoader
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| running | boolean | RW | `obj.running = <value>` |
| sceneManager | lightuserdata | R | `obj.sceneManager` |
| loadingMeshQueueMutex | lightuserdata | R | `obj.loadingMeshQueueMutex` |
| texturesLoadingMutex | lightuserdata | R | `obj.texturesLoadingMutex` |
| texturesLoadedMutex | lightuserdata | R | `obj.texturesLoadedMutex` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateMT | `` | `void` | `obj:updateMT()` |
| updateBT | `` | `boolean` | `obj:updateBT()` |
| isLoading | `` | `boolean` | `obj:isLoading()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| init | `` | `void` | `obj:init()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |

## RobotLimbItem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

## RobotLimbs
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | Character | RW | `obj.character = <value>` |
| inventory | RootObject | RW | `obj.inventory = <value>` |
| states | integer | RW | `obj.states = <value>` |
| items | Item | RW | `obj.items = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `RobotLimbs` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| load | `` | `void` | `obj:load()` |
| save | `` | `void` | `obj:save()` |
| getLimb | `limb: integer` | `Item` | `obj:getLimb(limb)` |
| getMask | `` | `integer` | `obj:getMask()` |
| getInventoryInterface | `create: boolean` | `RootObject` | `obj:getInventoryInterface(create)` |
| destroyInventoryInterface | `` | `void` | `obj:destroyInventoryInterface()` |
| getLimbItem | `l: integer` | `Item` | `obj:getLimbItem(l)` |
| getState | `limb: integer` | `integer` | `obj:getState(limb)` |
| setLimb | `limb: integer, state: integer` | `void` | `obj:setLimb(limb, state)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| container | RootObjectContainer | RW | `obj.container = <value>` |
| isInsideBuilding | unknown | RW | `obj.isInsideBuilding = <value>` |
| isInsideTownWalls | integer | RW | `obj.isInsideTownWalls = <value>` |
| floorNum | integer | RW | `obj.floorNum = <value>` |
| spacialKey | integer | RW | `obj.spacialKey = <value>` |
| outdoorDelayNotification_timer | integer | RW | `obj.outdoorDelayNotification_timer = <value>` |
| rot | Quaternion | RW | `obj.rot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `RootObject` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| needsSaving | `s: string` | `boolean` | `obj:needsSaving(s)` |
| _NV_needsSaving | `s: string` | `boolean` | `obj:_NV_needsSaving(s)` |
| getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| _NV_getInstanceID | `` | `InstanceID` | `obj:_NV_getInstanceID()` |
| getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| _NV_getOrientation | `` | `Quaternion` | `obj:_NV_getOrientation()` |
| getZoneMapLocation | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| _NV_getZoneMapLocation | `` | `ZoneMap` | `obj:_NV_getZoneMapLocation()` |
| getRace | `` | `RaceData` | `obj:getRace()` |
| _NV_getRace | `` | `RaceData` | `obj:_NV_getRace()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | `_a1: boolean` | `void` | `obj:setVisible(_a1)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| _NV_getVisible | `` | `boolean` | `obj:_NV_getVisible()` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| setInsideTownWalls | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| _NV_setInsideTownWalls | `s: integer` | `void` | `obj:_NV_setInsideTownWalls(s)` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| _NV_getFloor | `` | `integer` | `obj:_NV_getFloor()` |
| setFloor | `f: integer` | `void` | `obj:setFloor(f)` |
| _NV_setFloor | `f: integer` | `void` | `obj:_NV_setFloor(f)` |
| select | `` | `void` | `obj:select()` |
| _NV_select | `` | `void` | `obj:_NV_select()` |
| unselect | `` | `void` | `obj:unselect()` |
| _NV_unselect | `` | `void` | `obj:_NV_unselect()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| setStandingOrder | `_a1: integer` | `void` | `obj:setStandingOrder(_a1)` |
| _NV_setStandingOrder | `_a1: integer` | `void` | `obj:_NV_setStandingOrder(_a1)` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| _NV_giveItem | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:_NV_giveItem(dropOnFail, destroyOnFail)` |
| hasRoomForItem | `` | `boolean` | `obj:hasRoomForItem()` |
| _NV_hasRoomForItem | `` | `boolean` | `obj:_NV_hasRoomForItem()` |
| hasItem | `` | `boolean` | `obj:hasItem()` |
| _NV_hasItem | `` | `boolean` | `obj:_NV_hasItem()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `InventoryLayout` | `obj:_NV_createInventoryLayout()` |
| ImStealingDoYouNotice | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| _NV_ImStealingDoYouNotice | `` | `boolean` | `obj:_NV_ImStealingDoYouNotice()` |
| stolenGoodsDetectionCheck | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| _NV_stolenGoodsDetectionCheck | `` | `boolean` | `obj:_NV_stolenGoodsDetectionCheck()` |
| equipItem | `_a1: string` | `void` | `obj:equipItem(_a1)` |
| _NV_equipItem | `_a1: string` | `void` | `obj:_NV_equipItem(_a1)` |
| unequipItem | `_a1: string` | `void` | `obj:unequipItem(_a1)` |
| _NV_unequipItem | `_a1: string` | `void` | `obj:_NV_unequipItem(_a1)` |
| dropItem | `` | `void` | `obj:dropItem()` |
| _NV_dropItem | `` | `void` | `obj:_NV_dropItem()` |
| takeMoney | `_a1: integer` | `boolean` | `obj:takeMoney(_a1)` |
| _NV_takeMoney | `_a1: integer` | `boolean` | `obj:_NV_takeMoney(_a1)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| say | `_a1: string` | `void` | `obj:say(_a1)` |
| _NV_say | `_a1: string` | `void` | `obj:_NV_say(_a1)` |
| notifyOutdoors | `` | `void` | `obj:notifyOutdoors()` |
| _NV_notifyOutdoors | `` | `void` | `obj:_NV_notifyOutdoors()` |
| isOnARoof | `` | `boolean` | `obj:isOnARoof()` |
| _NV_isOnARoof | `` | `boolean` | `obj:_NV_isOnARoof()` |
| getIntendedAggression | `` | `number` | `obj:getIntendedAggression()` |
| _NV_getIntendedAggression | `` | `number` | `obj:_NV_getIntendedAggression()` |
| getPlatoonAI | `` | `lightuserdata` | `obj:getPlatoonAI()` |
| _NV_getPlatoonAI | `` | `lightuserdata` | `obj:_NV_getPlatoonAI()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| _NV_notifyEffect | `type: integer, what: integer, strength: number` | `void` | `obj:_NV_notifyEffect(type, what, strength)` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _NV_loadUnloadCheck | `` | `void` | `obj:_NV_loadUnloadCheck()` |
| isIndoors | `` | `void` | `obj:isIndoors()` |
| _NV_isIndoors | `` | `void` | `obj:_NV_isIndoors()` |
| setIsInsideBuilding | `` | `void` | `obj:setIsInsideBuilding()` |
| _NV_setIsInsideBuilding | `` | `void` | `obj:_NV_setIsInsideBuilding()` |
| getLayoutInstanceID | `` | `string` | `obj:getLayoutInstanceID()` |
| _NV_getLayoutInstanceID | `` | `string` | `obj:_NV_getLayoutInstanceID()` |
| getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| _NV_getAABB | `` | `lightuserdata` | `obj:_NV_getAABB()` |
| getGUIDataCategories | `` | `void` | `obj:getGUIDataCategories()` |
| _NV_getGUIDataCategories | `` | `void` | `obj:_NV_getGUIDataCategories()` |
| getOrders | `` | `void` | `obj:getOrders()` |
| _NV_getOrders | `` | `void` | `obj:_NV_getOrders()` |
| notifyIndoors | `` | `void` | `obj:notifyIndoors()` |
| _NV_notifyIndoors | `` | `void` | `obj:_NV_notifyIndoors()` |
| hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| _NV_hitByMeleeAttack | `dir: integer, comboID: integer` | `integer` | `obj:_NV_hitByMeleeAttack(dir, comboID)` |

## RootObjectBase
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectBase.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| validKey | integer | RW | `obj.validKey = <value>` |
| owner | Faction | RW | `obj.owner = <value>` |
| displayName | string | RW | `obj.displayName = <value>` |
| data | GameData | RW | `obj.data = <value>` |
| pos | Vector3 | RW | `obj.pos = <value>` |
| handle | unknown | RW | `obj.handle = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `RootObjectBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isValid | `` | `boolean` | `obj:isValid()` |
| getName | `` | `string` | `obj:getName()` |
| _NV_getName | `` | `string` | `obj:_NV_getName()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| _NV_setName | `name: string` | `void` | `obj:_NV_setName(name)` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| _NV_getGameData | `` | `GameData` | `obj:_NV_getGameData()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| typeIsAnItem | `` | `boolean` | `obj:typeIsAnItem()` |
| _NV_typeIsAnItem | `` | `boolean` | `obj:_NV_typeIsAnItem()` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| _NV_isUnconcious | `` | `boolean` | `obj:_NV_isUnconcious()` |
| getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| _NV_getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:_NV_getPositionForWaypoint(from)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getMovementSpeed | `` | `number` | `obj:getMovementSpeed()` |
| _NV_getMovementSpeed | `` | `number` | `obj:_NV_getMovementSpeed()` |
| getMovementDirection | `` | `Vector3` | `obj:getMovementDirection()` |
| _NV_getMovementDirection | `` | `Vector3` | `obj:_NV_getMovementDirection()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| _NV_getFaction | `` | `Faction` | `obj:_NV_getFaction()` |
| hasFaction | `` | `boolean` | `obj:hasFaction()` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| _NV_getFloor | `` | `integer` | `obj:_NV_getFloor()` |
| getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| _NV_getSensoryData | `` | `SensoryData` | `obj:_NV_getSensoryData()` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| _NV_getStateBroadcast | `` | `lightuserdata` | `obj:_NV_getStateBroadcast()` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| _NV_getOwnerships | `` | `Ownerships` | `obj:_NV_getOwnerships()` |
| setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| getHandle | `` | `void` | `obj:getHandle()` |
| setHandle | `` | `void` | `obj:setHandle()` |
| _NV_setHandle | `` | `void` | `obj:_NV_setHandle()` |
| serialise | `offset: userdata` | `void` | `obj:serialise(offset)` |

## RootObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| things | lektor<RootObject*> | R | `obj.things` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| addActiveObject | `` | `boolean` | `obj:addActiveObject()` |
| _NV_addActiveObject | `` | `boolean` | `obj:_NV_addActiveObject()` |
| removeObject | `` | `boolean` | `obj:removeObject()` |
| _NV_removeObject | `` | `boolean` | `obj:_NV_removeObject()` |
| update | `` | `boolean` | `obj:update()` |
| _NV_update | `` | `boolean` | `obj:_NV_update()` |
| getThing | `id: integer` | `RootObject` | `obj:getThing(id)` |
| getNumThings | `` | `integer` | `obj:getNumThings()` |
| getThings | `` | `lightuserdata` | `obj:getThings()` |
| loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| _NV_loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:_NV_loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| _NV_getSelectedObjects | `type: integer, selectedOnly: boolean` | `void` | `obj:_NV_getSelectedObjects(type, selectedOnly)` |
| _CONSTRUCTOR | `type: integer` | `RootObjectContainer` | `obj:_CONSTRUCTOR(type)` |
| serialiseThings | `offset: userdata, mod: string, mod: string` | `void` | `obj:serialiseThings(offset, mod, mod)` |
| loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |
| _NV_loadInstance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:_NV_loadInstance(skipSaveState, pos, rot, positionMoved)` |

## RootObjectFactory
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mutex | unknown | RW | `obj.mutex = <value>` |
| todoList | RootObjectFactory::CreatelistItem | RW | `obj.todoList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| create | `position: Vector3, isFromActiveLevelMod: boolean, rotation: Quaternion, invisible: boolean, age: number` | `RootObjectBase` | `obj:create(position, isFromActiveLevelMod, rotation, invisible, age)` |
| createLocationNode | `addToNodeListAutomatically: boolean, position: Vector3, rotation: Quaternion, nodeId: string` | `lightuserdata` | `obj:createLocationNode(addToNodeListAutomatically, position, rotation, nodeId)` |
| copyItem | `` | `Item` | `obj:copyItem()` |
| chooseDataFromList | `listName: string, materialDataType: integer, useVal012: integer` | `GameData` | `obj:chooseDataFromList(listName, materialDataType, useVal012)` |
| chooseDataFromListWithVals | `listName: string, materialDataType: integer, useVal012: integer` | `GameDataReference` | `obj:chooseDataFromListWithVals(listName, materialDataType, useVal012)` |
| createCharacterForBuilding | `` | `void` | `obj:createCharacterForBuilding()` |
| createRandomCharacter | `position: Vector3, age: number` | `RootObject` | `obj:createRandomCharacter(position, age)` |
| mainThreadUpdate | `` | `void` | `obj:mainThreadUpdate()` |
| populateBuilding | `` | `void` | `obj:populateBuilding()` |
| process | `o: userdata` | `RootObjectBase` | `obj:process(o)` |
| _CONSTRUCTOR | `` | `RootObjectFactory` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| createBuilding | `position: Vector3, rotation: Quaternion, furnitureOf: userdata, invisible: boolean, completed: boolean, isFoliage: boolean, floorNumber: integer, isOutsideFurniture: boolean` | `Building` | `obj:createBuilding(position, rotation, furnitureOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture)` |
| createItem | `levelOverride: integer` | `Item` | `obj:createItem(levelOverride)` |
| getValsFromDataInList | `listName: string` | `void` | `obj:getValsFromDataInList(listName)` |
| createRandomUnloadedCharacter | `platoon: userdata, position: Vector3` | `void` | `obj:createRandomUnloadedCharacter(platoon, position)` |
| createRandomSquad | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, sizeMultiplier: number, squadType: integer, isJustARefresh: boolean` | `Platoon` | `obj:createRandomSquad(position, maxnum, maparea, permanentsquad, sizeMultiplier, squadType, isJustARefresh)` |
| createRandomUnloadedSquad | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, squadType: integer` | `Platoon` | `obj:createRandomUnloadedSquad(position, maxnum, maparea, permanentsquad, squadType)` |
| chooseMyClothing | `` | `void` | `obj:chooseMyClothing()` |
| _chooseClothingItemFromList | `` | `GameData` | `obj:_chooseClothingItemFromList()` |

## RotatingEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| rotAxis | Vector3 | RW | `obj.rotAxis = <value>` |
| rotationSpeed | number | RW | `obj.rotationSpeed = <value>` |
| rotationPower | number | RW | `obj.rotationPower = <value>` |
| speedMin | number | RW | `obj.speedMin = <value>` |
| speedMax | number | RW | `obj.speedMax = <value>` |
| rotationBase | Quaternion | RW | `obj.rotationBase = <value>` |
| isRotating | boolean | RW | `obj.isRotating = <value>` |
| rotationSrc | Quaternion | RW | `obj.rotationSrc = <value>` |
| rotationDst | Quaternion | RW | `obj.rotationDst = <value>` |
| rotatingTime | number | RW | `obj.rotatingTime = <value>` |
| rotationDuration | number | RW | `obj.rotationDuration = <value>` |
| windSpeedRotationMin | number | RW | `obj.windSpeedRotationMin = <value>` |
| windSpeedRotationMax | number | RW | `obj.windSpeedRotationMax = <value>` |
| windSpeedRotationDanger | number | RW | `obj.windSpeedRotationDanger = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `productionSpeed: number` | `void` | `obj:update(productionSpeed)` |
| _NV_update | `productionSpeed: number` | `void` | `obj:_NV_update(productionSpeed)` |
| updateAim | `speed: number, target: Vector3` | `number` | `obj:updateAim(speed, target)` |
| _NV_updateAim | `speed: number, target: Vector3` | `number` | `obj:_NV_updateAim(speed, target)` |
| isRotatingEnt | `` | `boolean` | `obj:isRotatingEnt()` |
| _NV_isRotatingEnt | `` | `boolean` | `obj:_NV_isRotatingEnt()` |
| getRotationPower | `` | `number` | `obj:getRotationPower()` |

## SaveFileSystem
**Header:** `extern/KenshiLib/Include/kenshi/SaveFileSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentSave | string | RW | `obj.currentSave = <value>` |
| currentFolder | string | RW | `obj.currentFolder = <value>` |
| tempFolder | string | RW | `obj.tempFolder = <value>` |
| currentPathIndex | integer | RW | `obj.currentPathIndex = <value>` |
| currentMutex | lightuserdata | R | `obj.currentMutex` |
| savingIcon | lightuserdata | R | `obj.savingIcon` |
| state | integer | RW | `obj.state = <value>` |
| failedToCopyError | string | RW | `obj.failedToCopyError = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| log | `message: string, level: integer` | `void` | `obj:log(message, level)` |
| setTemporaryPath | `path: string` | `void` | `obj:setTemporaryPath(path)` |
| fileExists | `name: string` | `boolean` | `obj:fileExists(name)` |
| readFile | `name: string` | `string` | `obj:readFile(name)` |
| writeFile | `name: string` | `string` | `obj:writeFile(name)` |
| deleteFile | `name: string` | `void` | `obj:deleteFile(name)` |
| newGame | `` | `void` | `obj:newGame()` |
| loadGame | `savePath: string` | `void` | `obj:loadGame(savePath)` |
| saveGame | `savePath: string` | `boolean` | `obj:saveGame(savePath)` |
| sync | `` | `void` | `obj:sync()` |
| analyse | `` | `void` | `obj:analyse()` |
| cleanup | `full: boolean` | `void` | `obj:cleanup(full)` |
| scanForResidualTempFolders | `` | `void` | `obj:scanForResidualTempFolders()` |
| isTempFolder | `f: string` | `boolean` | `obj:isTempFolder(f)` |
| busy | `` | `boolean` | `obj:busy()` |
| createCurrent | `` | `void` | `obj:createCurrent()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| addMessage | `type: integer, src: string, dst: string` | `void` | `obj:addMessage(type, src, dst)` |

## SaveFileSystem_FileMessage
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SaveFileSystem::FileMessage` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SaveInfo
**Header:** `???`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| version | string | RW | `obj.version = <value>` |
| name | string | RW | `obj.name = <value>` |
| area | string | RW | `obj.area = <value>` |
| time | number | RW | `obj.time = <value>` |
| faction | string | RW | `obj.faction = <value>` |
| money | integer | RW | `obj.money = <value>` |
| size | integer | RW | `obj.size = <value>` |
| days | integer | RW | `obj.days = <value>` |
| location | string | RW | `obj.location = <value>` |
| advanced | GameplayOptions | RW | `obj.advanced = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `money: integer, size: integer, days: integer` | `SaveInfo` | `obj:_CONSTRUCTOR(money, size, days)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SaveManager
**Header:** `extern/KenshiLib/Include/kenshi/SaveManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentGame | string | RW | `obj.currentGame = <value>` |
| saveVersion | string | RW | `obj.saveVersion = <value>` |
| localSavePath | string | RW | `obj.localSavePath = <value>` |
| userSavePath | string | RW | `obj.userSavePath = <value>` |
| signal | integer | RW | `obj.signal = <value>` |
| flags | integer | RW | `obj.flags = <value>` |
| delay | integer | RW | `obj.delay = <value>` |
| name | string | RW | `obj.name = <value>` |
| location | string | RW | `obj.location = <value>` |
| loadMenu | lightuserdata | R | `obj.loadMenu` |
| saveMenu | lightuserdata | R | `obj.saveMenu` |
| importMenu | lightuserdata | R | `obj.importMenu` |
| autoSaveTimer | number | RW | `obj.autoSaveTimer = <value>` |
| pauseAutoSaveTimer | boolean | RW | `obj.pauseAutoSaveTimer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isVisible | `` | `integer` | `obj:isVisible()` |
| showSave | `` | `void` | `obj:showSave()` |
| showLoad | `` | `void` | `obj:showLoad()` |
| showImport | `` | `void` | `obj:showImport()` |
| hide | `` | `void` | `obj:hide()` |
| newGame | `startId: string` | `void` | `obj:newGame(startId)` |
| save | `s: string, autosave: boolean` | `void` | `obj:save(s, autosave)` |
| savesExist | `` | `boolean` | `obj:savesExist()` |
| saveExists | `location: string, name: string` | `boolean` | `obj:saveExists(location, name)` |
| execute | `` | `void` | `obj:execute()` |
| versionCode | `version: string` | `integer` | `obj:versionCode(version)` |
| updateAutoSave | `` | `void` | `obj:updateAutoSave()` |
| initialisePaths | `` | `void` | `obj:initialisePaths()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| saveGame | `location: string, name: string` | `integer` | `obj:saveGame(location, name)` |
| loadGame | `location: string, name: string` | `integer` | `obj:loadGame(location, name)` |
| importGame | `location: string, name: string, flags: integer` | `integer` | `obj:importGame(location, name, flags)` |
| importPlayerBuildings | `path: string, file: string` | `integer` | `obj:importPlayerBuildings(path, file)` |
| importOldPlayerBuildings | `path: string, name: string` | `integer` | `obj:importOldPlayerBuildings(path, name)` |

## ScreenLabel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| caption | string | RW | `obj.caption = <value>` |
| textWidget | lightuserdata | R | `obj.textWidget` |
| risingSpeed | number | RW | `obj.risingSpeed = <value>` |
| risingHeight | number | RW | `obj.risingHeight = <value>` |
| labelSize | integer | RW | `obj.labelSize = <value>` |
| trackingHandle | unknown | RW | `obj.trackingHandle = <value>` |
| trackingOffset | Vector3 | RW | `obj.trackingOffset = <value>` |
| destroyed | boolean | RW | `obj.destroyed = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setCaption | `value: string` | `void` | `obj:setCaption(value)` |
| _NV_setCaption | `value: string` | `void` | `obj:_NV_setCaption(value)` |
| setRisingSpeed | `value: integer` | `void` | `obj:setRisingSpeed(value)` |
| _NV_setRisingSpeed | `value: integer` | `void` | `obj:_NV_setRisingSpeed(value)` |
| setPosition | `value: Vector3` | `void` | `obj:setPosition(value)` |
| _NV_setPosition | `value: Vector3` | `void` | `obj:_NV_setPosition(value)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| destroy | `` | `void` | `obj:destroy()` |

## ScreenLabelDebug
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeLeft | number | RW | `obj.timeLeft = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| _CONSTRUCTOR | `caption: string, time: number` | `lightuserdata` | `obj:_CONSTRUCTOR(caption, time)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ScreenLabelInterface
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| visible | boolean | RW | `obj.visible = <value>` |
| position | Vector3 | RW | `obj.position = <value>` |
| needUpdate | boolean | RW | `obj.needUpdate = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| _NV_setVisible | `value: boolean` | `void` | `obj:_NV_setVisible(value)` |
| setPosition | `value: Vector3` | `void` | `obj:setPosition(value)` |
| _NV_setPosition | `value: Vector3` | `void` | `obj:_NV_setPosition(value)` |

## SectionItem
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| item | Item | RW | `obj.item = <value>` |
| x | integer | RW | `obj.x = <value>` |
| y | integer | RW | `obj.y = <value>` |
| w | integer | RW | `obj.w = <value>` |
| h | integer | RW | `obj.h = <value>` |

## SeenSomeone
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lastPosition | Vector3 | RW | `obj.lastPosition = <value>` |
| lastSeenTime | TimeOfDay | RW | `obj.lastSeenTime = <value>` |
| percievedFaction | Faction | RW | `obj.percievedFaction = <value>` |
| percievedSlave | integer | RW | `obj.percievedSlave = <value>` |
| FOVScore | number | RW | `obj.FOVScore = <value>` |
| canSee | boolean | RW | `obj.canSee = <value>` |
| canHear | boolean | RW | `obj.canHear = <value>` |
| alarmState | number | RW | `obj.alarmState = <value>` |
| type | TagsClass<SenseType> | R | `obj.type` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SeenSomeone` | `obj:_CONSTRUCTOR()` |
| lastSeenInSeconds | `` | `number` | `obj:lastSeenInSeconds()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |

## SelectionBox
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| startPos | unknown | RW | `obj.startPos = <value>` |
| widget | lightuserdata | R | `obj.widget` |
| active | boolean | RW | `obj.active = <value>` |
| volume | Ogre::PlaneBoundedVolume | R | `obj.volume` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| start | `` | `void` | `obj:start()` |
| update | `` | `void` | `obj:update()` |
| cancel | `` | `void` | `obj:cancel()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| _CONSTRUCTOR | `` | `SelectionBox` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SenseItr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| flagsAny | integer | RW | `obj.flagsAny = <value>` |
| flagsNot | integer | RW | `obj.flagsNot = <value>` |
| _end | boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > > | R | `obj._end` |
| it | boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > > | R | `obj.it` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| getData | `` | `SeenSomeone` | `obj:getData()` |
| ended | `` | `boolean` | `obj:ended()` |
| increment | `` | `void` | `obj:increment()` |

## SensoryData
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nearestEnemy | number | RW | `obj.nearestEnemy = <value>` |
| numUnconsciousAllies | integer | RW | `obj.numUnconsciousAllies = <value>` |
| numConsciousAllies | integer | RW | `obj.numConsciousAllies = <value>` |
| totalThreatLevelPersonal | number | RW | `obj.totalThreatLevelPersonal = <value>` |
| totalThreatLevelAllies | number | RW | `obj.totalThreatLevelAllies = <value>` |
| totalIntendedThreatLevelGeneral | number | RW | `obj.totalIntendedThreatLevelGeneral = <value>` |
| numEnemies | integer | RW | `obj.numEnemies = <value>` |
| numNeutrals | integer | RW | `obj.numNeutrals = <value>` |
| lastThreat | number | RW | `obj.lastThreat = <value>` |
| currentAssessIndex | integer | RW | `obj.currentAssessIndex = <value>` |
| currentAssessList | integer | RW | `obj.currentAssessList = <value>` |
| me | Character | RW | `obj.me = <value>` |
| spottedSneakingPeople | SensoryData::SpottingPeopleMgr | RW | `obj.spottedSneakingPeople = <value>` |
| spottedSuspiciousPeople | SensoryData::SpottingPeopleMgr | RW | `obj.spottedSuspiciousPeople = <value>` |
| progressBar | FloatingProgressBar | RW | `obj.progressBar = <value>` |
| progressBarStillNeeded | integer | RW | `obj.progressBarStillNeeded = <value>` |
| spottedGuyIndexForProgressBar | unknown | RW | `obj.spottedGuyIndexForProgressBar = <value>` |
| amSharingThisFrame | boolean | RW | `obj.amSharingThisFrame = <value>` |
| assessList | lightuserdata | R | `obj.assessList` |
| flockingList | lightuserdata | R | `obj.flockingList` |
| hearTestTimers | lightuserdata | R | `obj.hearTestTimers` |
| killList | lightuserdata | R | `obj.killList` |
| seen | lightuserdata | R | `obj.seen` |
| threats | lightuserdata | R | `obj.threats` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SensoryData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| periodicUpdate_KOed | `` | `void` | `obj:periodicUpdate_KOed()` |
| getVisionRange | `inTown: boolean` | `number` | `obj:getVisionRange(inTown)` |
| update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| notifyKO | `` | `void` | `obj:notifyKO()` |
| getIterator | `tagsAny: integer, tagsNOT: integer` | `void` | `obj:getIterator(tagsAny, tagsNOT)` |
| getNearestEnemyDistanceSq | `` | `number` | `obj:getNearestEnemyDistanceSq()` |
| canISeeThisGuy | `` | `boolean` | `obj:canISeeThisGuy()` |
| canIHearThisGuy | `` | `boolean` | `obj:canIHearThisGuy()` |
| amIAwareOfThisGuy | `needToSeeOrHear: boolean` | `boolean` | `obj:amIAwareOfThisGuy(needToSeeOrHear)` |
| getLastKnownPositionOf | `` | `Vector3` | `obj:getLastKnownPositionOf()` |
| getDataFor | `` | `SeenSomeone` | `obj:getDataFor()` |
| getFactionRelation | `` | `number` | `obj:getFactionRelation()` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getGUIData | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| _calculateFOVScore | `` | `number` | `obj:_calculateFOVScore()` |
| _traceLineOfSightCheck | `` | `boolean` | `obj:_traceLineOfSightCheck()` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| dialogAssessmentUpdate | `frameTime: number, inDepth: boolean` | `void` | `obj:dialogAssessmentUpdate(frameTime, inDepth)` |
| noticeThisPerson | `alarmed: boolean` | `void` | `obj:noticeThisPerson(alarmed)` |
| add | `see: boolean, hear: boolean` | `SeenSomeone` | `obj:add(see, hear)` |
| remove | `` | `void` | `obj:remove()` |
| decay | `` | `void` | `obj:decay()` |
| canSee | `` | `boolean` | `obj:canSee()` |
| canHear | `` | `boolean` | `obj:canHear()` |
| disguiseMods | `FOV: number` | `boolean` | `obj:disguiseMods(FOV)` |
| assessCrimes | `` | `void` | `obj:assessCrimes()` |
| assessKidnapping | `` | `void` | `obj:assessKidnapping()` |
| processKillList | `` | `void` | `obj:processKillList()` |
| assessNeutral | `inDepth: boolean` | `void` | `obj:assessNeutral(inDepth)` |
| updateMyProgressBar | `progress: number, text: string` | `void` | `obj:updateMyProgressBar(progress, text)` |
| canISeeThisGuyDoinSneakingOrSomething | `FOVScore: number, spotTimeMinFOV: number, spotTimeMaxFOV: number` | `YesNoMaybe` | `obj:canISeeThisGuyDoinSneakingOrSomething(FOVScore, spotTimeMinFOV, spotTimeMaxFOV)` |
| isIntruder_Base | `` | `boolean` | `obj:isIntruder_Base()` |
| isIntruder_Building | `` | `boolean` | `obj:isIntruder_Building()` |
| isInMyPrivate_Building | `` | `boolean` | `obj:isInMyPrivate_Building()` |
| isEscapee | `` | `boolean` | `obj:isEscapee()` |
| reassess | `time: number` | `SeenSomeone` | `obj:reassess(time)` |
| addToThreatsAndFlockingList | `` | `void` | `obj:addToThreatsAndFlockingList()` |
| buildingSpotterUpdate | `` | `void` | `obj:buildingSpotterUpdate()` |
| notifyCriminalThreat | `` | `void` | `obj:notifyCriminalThreat()` |
| getStateBroadcastOf | `` | `StateBroadcastData*` | `obj:getStateBroadcastOf()` |
| _shareSensesCheck | `list: userdata, time: number` | `boolean` | `obj:_shareSensesCheck(list, time)` |
| setupMyProgressBar | `` | `void` | `obj:setupMyProgressBar()` |
| reassessAll | `newTargets: userdata, time: number` | `void` | `obj:reassessAll(newTargets, time)` |

## ShopTrader
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| trader | Character | R | `obj.trader` |
| inventory | Inventory | R | `obj.inventory` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| takeMoney | `money: integer` | `boolean` | `obj:takeMoney(money)` |
| _NV_takeMoney | `money: integer` | `boolean` | `obj:_NV_takeMoney(money)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| _NV_getOrientation | `` | `Quaternion` | `obj:_NV_getOrientation()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| _NV_getFloor | `` | `integer` | `obj:_NV_getFloor()` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| getTrader | `` | `Character` | `obj:getTrader()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| updateInventory | `` | `void` | `obj:updateInventory()` |
| equipItem | `sectionName: string` | `void` | `obj:equipItem(sectionName)` |
| _NV_equipItem | `sectionName: string` | `void` | `obj:_NV_equipItem(sectionName)` |
| unequipItem | `sectionName: string` | `void` | `obj:unequipItem(sectionName)` |
| _NV_unequipItem | `sectionName: string` | `void` | `obj:_NV_unequipItem(sectionName)` |

## ShopTraderInventory
**Header:** `extern/KenshiLib/Include/kenshi/ShopTraderInventory.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| inventories | unknown | RW | `obj.inventories = <value>` |
| section | lightuserdata | R | `obj.section` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateInventory | `` | `void` | `obj:updateInventory()` |
| _NV_updateInventory | `` | `void` | `obj:_NV_updateInventory()` |
| refreshGui | `` | `void` | `obj:refreshGui()` |
| _NV_refreshGui | `` | `void` | `obj:_NV_refreshGui()` |
| initialiseNewSection | `name: string, w: integer, h: integer, _a4: integer, equipCallbacks: boolean, _a6: boolean, _a7: boolean, _a8: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8)` |
| _NV_initialiseNewSection | `name: string, w: integer, h: integer, _a4: integer, equipCallbacks: boolean, _a6: boolean, _a7: boolean, _a8: integer` | `InventorySection` | `obj:_NV_initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8)` |

## ShopTraderInventorySection
**Header:** `extern/KenshiLib/Include/kenshi/ShopTraderInventory.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| autoArrange | `` | `void` | `obj:autoArrange()` |
| _NV_autoArrange | `` | `void` | `obj:_NV_autoArrange()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| addItem | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |
| _NV_addItem | `quantity: integer` | `boolean` | `obj:_NV_addItem(quantity)` |
| _CONSTRUCTOR | `name: string, w: integer, h: integer` | `ShopTraderInventorySection` | `obj:_CONSTRUCTOR(name, w, h)` |

## SimpleTimeStamper
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timer | CPerfTimer | RW | `obj.timer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SimpleTimeStamper` | `obj:_CONSTRUCTOR()` |
| getTime | `_lastStamp: number` | `number` | `obj:getTime(_lastStamp)` |
| stampTime | `` | `number` | `obj:stampTime()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_Slider.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mDisableEvents | boolean | RW | `obj.mDisableEvents = <value>` |
| mScrollbar | MyGUI::Widget | R | `obj.mScrollbar` |
| mSliderName | MyGUI::Widget | R | `obj.mSliderName` |
| mSliderValue | MyGUI::Widget | R | `obj.mSliderValue` |
| mLoValue | integer | RW | `obj.mLoValue = <value>` |
| mHiValue | integer | RW | `obj.mHiValue = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | `` | `void` | `obj:shutdownOverride()` |

## SpecificItemLoadFirst
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| baseTypes | integer | RW | `obj.baseTypes = <value>` |
| stateEnum | integer | RW | `obj.stateEnum = <value>` |
| specificProperty | string | RW | `obj.specificProperty = <value>` |
| desiredSpecificProperty | boolean | RW | `obj.desiredSpecificProperty = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `BaseItemType: integer, _stateEnum: integer, _specificProperty: string, _desiredSpecificProperty: boolean` | `SpecificItemLoadFirst` | `obj:_CONSTRUCTOR(BaseItemType, _stateEnum, _specificProperty, _desiredSpecificProperty)` |
| shouldSkip | `` | `boolean` | `obj:shouldSkip()` |
| _NV_shouldSkip | `` | `boolean` | `obj:_NV_shouldSkip()` |
| flip | `` | `void` | `obj:flip()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SpeedGroup
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| position | Vector3 | RW | `obj.position = <value>` |
| direction | Vector3 | RW | `obj.direction = <value>` |
| speed | number | RW | `obj.speed = <value>` |
| last | integer | RW | `obj.last = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SpeedGroup` | `obj:_CONSTRUCTOR()` |
| getSpeed | `` | `number` | `obj:getSpeed()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SplashScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/SplashScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentState | integer | RW | `obj.currentState = <value>` |
| startTime | number | RW | `obj.startTime = <value>` |
| skipLogo | boolean | RW | `obj.skipLogo = <value>` |
| delay | integer | RW | `obj.delay = <value>` |
| mainPanel | lightuserdata | R | `obj.mainPanel` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| getState | `` | `integer` | `obj:getState()` |
| getEnded | `` | `boolean` | `obj:getEnded()` |
| skip | `` | `void` | `obj:skip()` |
| addLogo | `file: string, scale: number` | `void` | `obj:addLogo(file, scale)` |

## Spot
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeSoFar | number | RW | `obj.timeSoFar = <value>` |
| timeLimitMax | number | RW | `obj.timeLimitMax = <value>` |
| stillSeen | boolean | RW | `obj.stillSeen = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Spot` | `obj:_CONSTRUCTOR()` |

## SpottingPeopleMgr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| spottedPeople | std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy > > | R | `obj.spottedPeople` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `time: number` | `void` | `obj:update(time)` |
| resetSeenFlags | `` | `void` | `obj:resetSeenFlags()` |
| _CONSTRUCTOR | `` | `SpottingPeopleMgr` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| portraitsBox | lightuserdata | R | `obj.portraitsBox` |
| txtName | lightuserdata | R | `obj.txtName` |
| txtSquadSize | lightuserdata | R | `obj.txtSquadSize` |
| squad | lightuserdata | R | `obj.squad` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| updateSquadSize | `` | `void` | `obj:updateSquadSize()` |

## SquadData
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| platoon | ActivePlatoon | RW | `obj.platoon = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SquadData` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setName | `name: string` | `void` | `obj:setName(name)` |

## SquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCellSize | `width: integer, height: integer` | `void` | `obj:setCellSize(width, height)` |
| getItemCount | `` | `integer` | `obj:getItemCount()` |

## SquadListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| refresh | `` | `void` | `obj:refresh()` |
| itemSelected | `` | `void` | `obj:itemSelected()` |
| _NV_itemSelected | `` | `void` | `obj:_NV_itemSelected()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SquadManagementScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mainWidget | MyGUI::Widget | R | `obj.mainWidget` |
| btnAddSquad | MyGUI::Widget | R | `obj.btnAddSquad` |
| txtFactionSize | MyGUI::Widget | R | `obj.txtFactionSize` |
| factionSize | integer | RW | `obj.factionSize = <value>` |
| panelSquads | MyGUI::Widget | R | `obj.panelSquads` |
| panelDismiss | MyGUI::Widget | R | `obj.panelDismiss` |
| dismissChar | Character | RW | `obj.dismissChar = <value>` |
| faction | Faction | RW | `obj.faction = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `SquadManagementScreen` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| update | `` | `void` | `obj:update()` |
| reset | `` | `void` | `obj:reset()` |
| refreshSquads | `` | `void` | `obj:refreshSquads()` |
| notifyEndDropSquad | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropSquad(_sender, _result)` |
| notifyEndDropPortrait | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropPortrait(_sender, _result)` |
| removeSquad | `` | `void` | `obj:removeSquad()` |
| getSquad | `` | `lightuserdata` | `obj:getSquad()` |
| dismissCharacter | `result: integer` | `void` | `obj:dismissCharacter(result)` |

## Stat
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| type | integer | RW | `obj.type = <value>` |
| id | string | RW | `obj.id = <value>` |
| name | string | RW | `obj.name = <value>` |
| description | string | RW | `obj.description = <value>` |
| active | boolean | RW | `obj.active = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## StatGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| group | integer | RW | `obj.group = <value>` |
| name | string | RW | `obj.name = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## StateT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _zoneBeingLoaded | boolean | RW | `obj._zoneBeingLoaded = <value>` |
| _zoneIsLoaded | boolean | RW | `obj._zoneIsLoaded = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `StateT` | `obj:_CONSTRUCTOR()` |

## StaticEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `spd: number` | `void` | `obj:update(spd)` |
| _NV_update | `spd: number` | `void` | `obj:_NV_update(spd)` |
| updateAim | `rotSpeed: number, target: Vector3` | `number` | `obj:updateAim(rotSpeed, target)` |
| _NV_updateAim | `rotSpeed: number, target: Vector3` | `number` | `obj:_NV_updateAim(rotSpeed, target)` |
| isRotatingEnt | `` | `boolean` | `obj:isRotatingEnt()` |
| _NV_isRotatingEnt | `` | `boolean` | `obj:_NV_isRotatingEnt()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## StorageBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| specialItemTypesOnly | integer | RW | `obj.specialItemTypesOnly = <value>` |
| endOfTheLine | boolean | RW | `obj.endOfTheLine = <value>` |
| productionItem | lightuserdata | R | `obj.productionItem` |
| manyLimitItems | lektor<StorageBuilding::ConsumptionItem*> | R | `obj.manyLimitItems` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| _NV_getFunctionStuff | `` | `StorageBuilding` | `obj:_NV_getFunctionStuff()` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getProductionItemData | `` | `GameData` | `obj:getProductionItemData()` |
| _NV_getProductionItemData | `` | `GameData` | `obj:_NV_getProductionItemData()` |
| getProductionItem | `` | `lightuserdata` | `obj:getProductionItem()` |
| getCurrentProductionQuantity | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| _NV_getCurrentProductionQuantity | `` | `integer` | `obj:_NV_getCurrentProductionQuantity()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| isAnyInputsFull | `` | `boolean` | `obj:isAnyInputsFull()` |
| _NV_isAnyInputsFull | `` | `boolean` | `obj:_NV_isAnyInputsFull()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| _NV_isProductionFull | `` | `boolean` | `obj:_NV_isProductionFull()` |
| isProductionEmpty | `` | `boolean` | `obj:isProductionEmpty()` |
| _NV_isProductionEmpty | `` | `boolean` | `obj:_NV_isProductionEmpty()` |
| getNumConsumtionItems | `` | `integer` | `obj:getNumConsumtionItems()` |
| _NV_getNumConsumtionItems | `` | `integer` | `obj:_NV_getNumConsumtionItems()` |
| getConsumtionItems | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| _NV_getConsumtionItems | `id: integer` | `lightuserdata` | `obj:_NV_getConsumtionItems(id)` |
| limitedByType | `` | `boolean` | `obj:limitedByType()` |
| updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| _NV_updateInventoryWindow | `` | `void` | `obj:_NV_updateInventoryWindow()` |

## StringPair
**Header:** `extern/KenshiLib/Include/kenshi/util/StringPair.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| s1 | string | RW | `obj.s1 = <value>` |
| s2 | string | RW | `obj.s2 = <value>` |
| val1 | number | RW | `obj.val1 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Sword
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cutDamage | number | RW | `obj.cutDamage = <value>` |
| bluntDamage | number | RW | `obj.bluntDamage = <value>` |
| minCutDamage | number | RW | `obj.minCutDamage = <value>` |
| modDefence | integer | RW | `obj.modDefence = <value>` |
| modIndoors | integer | RW | `obj.modIndoors = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `_level: integer` | `Sword` | `obj:_CONSTRUCTOR(_level)` |
| getClassType | `` | `integer` | `obj:getClassType()` |
| _NV_getClassType | `` | `integer` | `obj:_NV_getClassType()` |
| isSword | `` | `Sword` | `obj:isSword()` |
| _NV_isSword | `` | `Sword` | `obj:_NV_isSword()` |
| setupStats | `_level: integer` | `void` | `obj:setupStats(_level)` |
| getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| _NV_getSkillModIndoors | `` | `integer` | `obj:_NV_getSkillModIndoors()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## SysMessage
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| msg | integer | RW | `obj.msg = <value>` |
| target | unknown | RW | `obj.target = <value>` |
| from | unknown | RW | `obj.from = <value>` |
| on | boolean | RW | `obj.on = <value>` |
| number | number | RW | `obj.number = <value>` |
| data | lightuserdata | R | `obj.data` |

## TagsClass
**Header:** `extern/KenshiLib/Include/kenshi/util/TagsClass.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| flags | integer | RW | `obj.flags = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| clearAll | `` | `void` | `obj:clearAll()` |
| hasNONEOfTheseBitsSet | `flagsToTest: integer` | `boolean` | `obj:hasNONEOfTheseBitsSet(flagsToTest)` |
| hasANYOfTheseBitsSet | `flagsToTest: integer` | `boolean` | `obj:hasANYOfTheseBitsSet(flagsToTest)` |

## TaskData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| infrequentGoalChecks | boolean | RW | `obj.infrequentGoalChecks = <value>` |
| permaJob_FixedTarget | boolean | RW | `obj.permaJob_FixedTarget = <value>` |
| permaJob_Associated | integer | RW | `obj.permaJob_Associated = <value>` |
| permaJob_Associated_Secondary | integer | RW | `obj.permaJob_Associated_Secondary = <value>` |
| requirementsAlwaysFalse | boolean | RW | `obj.requirementsAlwaysFalse = <value>` |
| _resultsAlwaysFalse | boolean | RW | `obj._resultsAlwaysFalse = <value>` |
| _requirementsCantEndActionPrematurely | boolean | RW | `obj._requirementsCantEndActionPrematurely = <value>` |
| durationMin | number | RW | `obj.durationMin = <value>` |
| durationFuzz | number | RW | `obj.durationFuzz = <value>` |
| isDurationBased | boolean | RW | `obj.isDurationBased = <value>` |
| endsAfterTime | boolean | RW | `obj.endsAfterTime = <value>` |
| isUnstoppableTask | boolean | RW | `obj.isUnstoppableTask = <value>` |
| canDoTaskInStages | boolean | RW | `obj.canDoTaskInStages = <value>` |
| aggressionLevel | number | RW | `obj.aggressionLevel = <value>` |
| noisyness | number | RW | `obj.noisyness = <value>` |
| aidLevel | number | RW | `obj.aidLevel = <value>` |
| followMeWeight | number | RW | `obj.followMeWeight = <value>` |
| copyMeInfluence | number | RW | `obj.copyMeInfluence = <value>` |
| normallyLeadsToSomething | boolean | RW | `obj.normallyLeadsToSomething = <value>` |
| alertnessMult | number | RW | `obj.alertnessMult = <value>` |
| forDirectPlayerOrdersOnly | boolean | RW | `obj.forDirectPlayerOrdersOnly = <value>` |
| forFulfillPlayerOrdersOrNPCOnly | boolean | RW | `obj.forFulfillPlayerOrdersOrNPCOnly = <value>` |
| key | integer | RW | `obj.key = <value>` |
| needsTarget | boolean | RW | `obj.needsTarget = <value>` |
| numResults | integer | RW | `obj.numResults = <value>` |
| results | unknown | RW | `obj.results = <value>` |
| numRequirements | integer | RW | `obj.numRequirements = <value>` |
| requirements | unknown | RW | `obj.requirements = <value>` |
| scoreFunction | lightuserdata | R | `obj.scoreFunction` |
| justDoOneTarget | boolean | RW | `obj.justDoOneTarget = <value>` |
| subTask | TaskStateData | RW | `obj.subTask = <value>` |
| dialogueDelivery | integer | RW | `obj.dialogueDelivery = <value>` |
| hasAction | boolean | RW | `obj.hasAction = <value>` |
| description | string | RW | `obj.description = <value>` |
| _findTarget | lightuserdata | R | `obj._findTarget` |
| permaJob | PermajobType | R | `obj.permaJob` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setCharacteristics | `_aid: number, _aggressionLevel: number, noise: number, leadsSomewhere: boolean` | `void` | `obj:setCharacteristics(_aid, _aggressionLevel, noise, leadsSomewhere)` |
| setInfrequentGoalChecks | `` | `void` | `obj:setInfrequentGoalChecks()` |
| setAlertnessMult | `a: number` | `void` | `obj:setAlertnessMult(a)` |
| setRequirementsCantEndActionPrematurely | `on: boolean` | `void` | `obj:setRequirementsCantEndActionPrematurely(on)` |
| setCopyMeInfluence | `weight: number` | `void` | `obj:setCopyMeInfluence(weight)` |
| setFollowMeWeight | `weight: number` | `void` | `obj:setFollowMeWeight(weight)` |
| setSelfRegulation | `requirements: boolean, results: boolean` | `void` | `obj:setSelfRegulation(requirements, results)` |
| setDurationBased | `mintime: number, fuzz: number, _endsAfterTime: boolean` | `void` | `obj:setDurationBased(mintime, fuzz, _endsAfterTime)` |
| hasInfrequentGoalChecks | `` | `boolean` | `obj:hasInfrequentGoalChecks()` |
| getRequirementsCantEndActionPrematurely | `` | `boolean` | `obj:getRequirementsCantEndActionPrematurely()` |
| isPermaJob | `` | `boolean` | `obj:isPermaJob()` |
| isPermaJobFixedTarget | `` | `boolean` | `obj:isPermaJobFixedTarget()` |
| getPermaJobAssociation | `` | `integer` | `obj:getPermaJobAssociation()` |
| getPermaJobAssociation_secondary | `` | `integer` | `obj:getPermaJobAssociation_secondary()` |
| isTargetFinder | `` | `boolean` | `obj:isTargetFinder()` |
| setDialogueDeliveryTag | `d: integer` | `void` | `obj:setDialogueDeliveryTag(d)` |

## TaskStateData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| val | boolean | RW | `obj.val = <value>` |
| progressionOnly | boolean | RW | `obj.progressionOnly = <value>` |
| key | StateType | R | `obj.key` |

## Tasker
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| resetsWhenDone | boolean | RW | `obj.resetsWhenDone = <value>` |
| subject | unknown | RW | `obj.subject = <value>` |
| weight | number | RW | `obj.weight = <value>` |
| currentSubTarget | unknown | RW | `obj.currentSubTarget = <value>` |
| location | Vector3 | RW | `obj.location = <value>` |
| startTime | integer | RW | `obj.startTime = <value>` |
| endTime | integer | RW | `obj.endTime = <value>` |
| taskData | TaskData | RW | `obj.taskData = <value>` |
| priority | integer | RW | `obj.priority = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Tasker` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| checkTimeOfDay | `` | `boolean` | `obj:checkTimeOfDay()` |
| getFrameTime | `` | `number` | `obj:getFrameTime()` |
| key | `` | `integer` | `obj:key()` |
| unSkippableJob | `` | `boolean` | `obj:unSkippableJob()` |
| getLocation | `` | `Vector3` | `obj:getLocation()` |
| setLocation | `loc: Vector3` | `void` | `obj:setLocation(loc)` |
| sameAs | `` | `boolean` | `obj:sameAs()` |
| hasActionFunc | `` | `boolean` | `obj:hasActionFunc()` |
| isSubTasker | `` | `boolean` | `obj:isSubTasker()` |
| getSubTask | `` | `TaskStateData` | `obj:getSubTask()` |
| isInfiniteGoal | `` | `boolean` | `obj:isInfiniteGoal()` |
| needsSubjectOrLocation | `` | `boolean` | `obj:needsSubjectOrLocation()` |
| getTaskData | `` | `TaskData` | `obj:getTaskData()` |
| startAction | `` | `void` | `obj:startAction()` |
| _NV_startAction | `` | `void` | `obj:_NV_startAction()` |
| runAction | `` | `void` | `obj:runAction()` |
| endAction | `` | `void` | `obj:endAction()` |
| _NV_endAction | `` | `void` | `obj:_NV_endAction()` |
| taskSaysItsFinished | `` | `boolean` | `obj:taskSaysItsFinished()` |
| _NV_taskSaysItsFinished | `` | `boolean` | `obj:_NV_taskSaysItsFinished()` |
| score | `ai: userdata` | `number` | `obj:score(ai)` |
| isResultsComplete | `ai: userdata` | `boolean` | `obj:isResultsComplete(ai)` |
| isResultsComplete_ignoreSubtasker | `ai: userdata` | `boolean` | `obj:isResultsComplete_ignoreSubtasker(ai)` |
| isRequirementsComplete | `ai: userdata, autoTargetFinder: boolean` | `boolean` | `obj:isRequirementsComplete(ai, autoTargetFinder)` |
| getRequirementComplaint | `ai: userdata, autoTargetFinder: boolean` | `string` | `obj:getRequirementComplaint(ai, autoTargetFinder)` |
| getNextSubTarget | `ai: userdata` | `hand` | `obj:getNextSubTarget(ai)` |

## Terrain
**Header:** `extern/KenshiLib/Include/kenshi/terrain.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mCamera | lightuserdata | RW | `obj.mCamera = <value>` |
| mCameraPosition | Vector3 | RW | `obj.mCameraPosition = <value>` |
| mStream | lightuserdata | R | `obj.mStream` |
| mTerrain | lightuserdata | R | `obj.mTerrain` |
| mSize | number | RW | `obj.mSize = <value>` |
| mHeight | number | RW | `obj.mHeight = <value>` |
| mHeightScale | number | RW | `obj.mHeightScale = <value>` |
| mOffset | number | RW | `obj.mOffset = <value>` |
| mSizeScale | number | RW | `obj.mSizeScale = <value>` |
| mBuildCounter | integer | RW | `obj.mBuildCounter = <value>` |
| mNeedsBuilding | boolean | RW | `obj.mNeedsBuilding = <value>` |
| mPatchesToBuild | integer | RW | `obj.mPatchesToBuild = <value>` |
| mOnscreenLimit | integer | RW | `obj.mOnscreenLimit = <value>` |
| mOffscreenLimit | integer | RW | `obj.mOffscreenLimit = <value>` |
| mDrawableCount | integer | RW | `obj.mDrawableCount = <value>` |
| mMaterialDistance | number | RW | `obj.mMaterialDistance = <value>` |
| mHeightCacheSize | integer | RW | `obj.mHeightCacheSize = <value>` |
| mHeightCacheBox | lightuserdata | RW | `obj.mHeightCacheBox = <value>` |
| mCachePositionX | integer | RW | `obj.mCachePositionX = <value>` |
| mCachePositionY | integer | RW | `obj.mCachePositionY = <value>` |
| mHeightCache | lightuserdata | RW | `obj.mHeightCache = <value>` |
| mBloodCamera | lightuserdata | R | `obj.mBloodCamera` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getBoundingRadius | `` | `number` | `obj:getBoundingRadius()` |

## Terrain_BloodQueue
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `sector: integer, depth: integer` | `Terrain::BloodQueue` | `obj:_CONSTRUCTOR(sector, depth)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Terrain_Box
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `left: integer, right: integer, bottom: integer, cx: integer, cy: integer` | `Terrain::Box` | `obj:_CONSTRUCTOR(left, right, bottom, cx, cy)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Terrain_Hit
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `level: integer, arg2: unknown, arg3: unknown` | `Terrain::Hit` | `obj:_CONSTRUCTOR(level, arg2, arg3)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Terrain_Info
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Terrain::Info` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TextureArrayLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| loadImage | `` | `void` | `obj:loadImage()` |
| _NV_loadImage | `` | `void` | `obj:_NV_loadImage()` |

## TextureLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | string | RW | `obj.name = <value>` |
| group | string | RW | `obj.group = <value>` |
| loaded | boolean | RW | `obj.loaded = <value>` |
| queued | boolean | RW | `obj.queued = <value>` |
| success | boolean | RW | `obj.success = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `name: string, group: string` | `lightuserdata` | `obj:_CONSTRUCTOR(name, group)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| loadImage | `` | `void` | `obj:loadImage()` |
| _NV_loadImage | `` | `void` | `obj:_NV_loadImage()` |

## ThreadClass
**Header:** `extern/KenshiLib/Include/kenshi/threadclass.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| threadHandle | lightuserdata | R | `obj.threadHandle` |
| threadID | integer | RW | `obj.threadID = <value>` |
| _running | boolean | RW | `obj._running = <value>` |
| name | string | RW | `obj.name = <value>` |
| frameTime | number | RW | `obj.frameTime = <value>` |
| infiniteMode | boolean | RW | `obj.infiniteMode = <value>` |
| pretendThread | boolean | RW | `obj.pretendThread = <value>` |
| runMute | lightuserdata | R | `obj.runMute` |
| lockedWhileRunningMute | lightuserdata | R | `obj.lockedWhileRunningMute` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| stopRunning | `` | `void` | `obj:stopRunning()` |
| canIRun | `` | `boolean` | `obj:canIRun()` |
| startRunning | `time: number` | `boolean` | `obj:startRunning(time)` |
| isRunning | `` | `boolean` | `obj:isRunning()` |
| waitForRunningStop_Blocking | `` | `boolean` | `obj:waitForRunningStop_Blocking()` |
| _CONSTRUCTOR | `_name: string` | `lightuserdata` | `obj:_CONSTRUCTOR(_name)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setup | `_frameTime: number, infinite: boolean, _pretendThread: boolean` | `void` | `obj:setup(_frameTime, infinite, _pretendThread)` |
| beginThread | `_frameTime: number, infinite: boolean, priority: integer` | `boolean` | `obj:beginThread(_frameTime, infinite, priority)` |
| setThreadName | `threadName: string` | `void` | `obj:setThreadName(threadName)` |
| endThread | `` | `void` | `obj:endThread()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| threadProc | `` | `integer` | `obj:threadProc()` |

## ThreadWannabe
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mute | lightuserdata | R | `obj.mute` |
| paused | boolean | RW | `obj.paused = <value>` |
| speedMult | number | RW | `obj.speedMult = <value>` |
| haltEverythingMutex | lightuserdata | R | `obj.haltEverythingMutex` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `threadname: string` | `lightuserdata` | `obj:_CONSTRUCTOR(threadname)` |
| backThreadUpdate | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| isPaused | `` | `boolean` | `obj:isPaused()` |
| setPaused | `on: boolean, _speedMult: number` | `void` | `obj:setPaused(on, _speedMult)` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| _NV_threadProc | `` | `integer` | `obj:_NV_threadProc()` |
| forceLoopMT | `` | `void` | `obj:forceLoopMT()` |
| _NV_forceLoopMT | `` | `void` | `obj:_NV_forceLoopMT()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TimeOfDay
**Header:** `extern/KenshiLib/Include/kenshi/util/TimeOfDay.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| time | number | RW | `obj.time = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setNull | `` | `void` | `obj:setNull()` |
| isUnset | `` | `boolean` | `obj:isUnset()` |
| setTime | `hrs: number` | `void` | `obj:setTime(hrs)` |
| addHours | `hours: number` | `void` | `obj:addHours(hours)` |
| addMinutes | `mins: number` | `void` | `obj:addMinutes(mins)` |
| getTotalHours | `` | `number` | `obj:getTotalHours()` |
| getTotalMinutes | `` | `number` | `obj:getTotalMinutes()` |
| getTotalSeconds | `` | `number` | `obj:getTotalSeconds()` |
| getRealLifeSeconds | `` | `number` | `obj:getRealLifeSeconds()` |
| getRealLifeSecondsPassed | `` | `number` | `obj:getRealLifeSecondsPassed()` |
| getTotalDays | `` | `number` | `obj:getTotalDays()` |
| stampTime | `` | `void` | `obj:stampTime()` |
| getHoursPassed | `` | `number` | `obj:getHoursPassed()` |
| getMinutesPassed | `` | `number` | `obj:getMinutesPassed()` |
| getSecondsPassed | `` | `number` | `obj:getSecondsPassed()` |
| timeOfDayHasPassed | `additionalHours: number` | `boolean` | `obj:timeOfDayHasPassed(additionalHours)` |
| timePassed | `` | `number` | `obj:timePassed()` |
| getTimePassedString | `` | `string` | `obj:getTimePassedString()` |
| getTimeRemainingString | `` | `string` | `obj:getTimeRemainingString()` |
| getTotalTimeString | `` | `string` | `obj:getTotalTimeString()` |

## TimerClass
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## TitleScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/TitleScreen.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| newGameWindow | NewGameWindow | RW | `obj.newGameWindow = <value>` |
| creditsPanel | MyGUI::Widget | R | `obj.creditsPanel` |
| creditsText | MyGUI::Widget | R | `obj.creditsText` |
| creditsLoaded | boolean | RW | `obj.creditsLoaded = <value>` |
| creditsPosition | number | RW | `obj.creditsPosition = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| _NV_show | `on: boolean` | `void` | `obj:_NV_show(on)` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| closeTheOtherBits | `` | `boolean` | `obj:closeTheOtherBits()` |
| setCreditsVisible | `value: boolean` | `void` | `obj:setCreditsVisible(value)` |

## ToolTip
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| panel | lightuserdata | RW | `obj.panel = <value>` |
| panelWidth | integer | RW | `obj.panelWidth = <value>` |
| lineMarginH | number | RW | `obj.lineMarginH = <value>` |
| panelMarginV | integer | RW | `obj.panelMarginV = <value>` |
| lineSpacing | integer | RW | `obj.lineSpacing = <value>` |
| caller | lightuserdata | R | `obj.caller` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| hide | `` | `void` | `obj:hide()` |
| _NV_hide | `` | `void` | `obj:_NV_hide()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |
| addLine | `textLeft: string, textRight: string` | `void` | `obj:addLine(textLeft, textRight)` |
| clearLines | `` | `void` | `obj:clearLines()` |

## ToolTipDynamic
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ToolTipDynamic` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## ToolTipFixed
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentPanel | lightuserdata | R | `obj.parentPanel` |
| minHeight | integer | RW | `obj.minHeight = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## ToolTipInventory
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| compareTooltip | ToolTipInventory | RW | `obj.compareTooltip = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ToolTipInventory` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |

## ToolTipLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| content | MyGUI::Widget | R | `obj.content` |
| leftBox | MyGUI::Widget | R | `obj.leftBox` |
| rightBox | MyGUI::Widget | R | `obj.rightBox` |
| width | integer | RW | `obj.width = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ToolTipStatic
**Header:** `extern/KenshiLib/Include/kenshi/gui/Tooltip.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| _NV_setVisible | `visible: boolean` | `void` | `obj:_NV_setVisible(visible)` |

## TortureBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TortureBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timer | number | RW | `obj.timer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| _NV_getFunctionStuff | `` | `StorageBuilding` | `obj:_NV_getFunctionStuff()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## Town
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| replacementTown | GameData | RW | `obj.replacementTown = <value>` |
| isAccessible | boolean | RW | `obj.isAccessible = <value>` |
| alarms | lightuserdata | RW | `obj.alarms = <value>` |
| instanceID | InstanceID | RW | `obj.instanceID = <value>` |
| openToPublic | boolean | RW | `obj.openToPublic = <value>` |
| minFoliageRange | number | RW | `obj.minFoliageRange = <value>` |
| playerTownLevel | integer | RW | `obj.playerTownLevel = <value>` |
| playerHasBuildingsInThisTown | boolean | RW | `obj.playerHasBuildingsInThisTown = <value>` |
| batteryMode | boolean | RW | `obj.batteryMode = <value>` |
| power_Stat | number | RW | `obj.power_Stat = <value>` |
| maxPower_Stat | number | RW | `obj.maxPower_Stat = <value>` |
| neededPowerTotal_Stat | number | RW | `obj.neededPowerTotal_Stat = <value>` |
| batteryPowerTotal_Stat | number | RW | `obj.batteryPowerTotal_Stat = <value>` |
| batteryDrain_Stat | number | RW | `obj.batteryDrain_Stat = <value>` |
| batteryChargingupTotal | number | RW | `obj.batteryChargingupTotal = <value>` |
| batteryCharge_Stat | number | RW | `obj.batteryCharge_Stat = <value>` |
| batteryChargeMax_Stat | number | RW | `obj.batteryChargeMax_Stat = <value>` |
| tradeCulture | TradeCulture | RW | `obj.tradeCulture = <value>` |
| buildingMaterial | GameData | RW | `obj.buildingMaterial = <value>` |
| distantTown | lightuserdata | RW | `obj.distantTown = <value>` |
| nestsLoaded | boolean | RW | `obj.nestsLoaded = <value>` |
| overrideRange | number | RW | `obj.overrideRange = <value>` |
| townRangeMultiplier | number | RW | `obj.townRangeMultiplier = <value>` |
| _facilitesWeHaveHere | integer | RW | `obj._facilitesWeHaveHere = <value>` |
| batteryList | ogre_unordered_set<hand>::type | RW | `obj.batteryList = <value>` |
| gates | ogre_unordered_set<hand>::type | RW | `obj.gates = <value>` |
| nestSpots | Vector3 | RW | `obj.nestSpots = <value>` |
| powerInList | unknown | RW | `obj.powerInList = <value>` |
| powerOutList | ogre_unordered_set<hand>::type | RW | `obj.powerOutList = <value>` |
| tradeGoodsMults | unknown | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Town` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| initialiseResidentData | `` | `void` | `obj:initialiseResidentData()` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| _NV_getGameData | `` | `GameData` | `obj:_NV_getGameData()` |
| getOriginalGameData | `` | `GameData` | `obj:getOriginalGameData()` |
| notifyRepopulation | `` | `void` | `obj:notifyRepopulation()` |
| isMyOldHomeTownStillValid | `` | `boolean` | `obj:isMyOldHomeTownStillValid()` |
| setup | `_pos: Vector3` | `void` | `obj:setup(_pos)` |
| _NV_setup | `_pos: Vector3` | `void` | `obj:_NV_setup(_pos)` |
| _reset | `` | `void` | `obj:_reset()` |
| _NV__reset | `` | `void` | `obj:_NV__reset()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| _NV_reassessTownPosition | `` | `void` | `obj:_NV_reassessTownPosition()` |
| showDistantTown | `vis: boolean` | `void` | `obj:showDistantTown(vis)` |
| getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| _NV_getAlarmMgr | `` | `lightuserdata` | `obj:_NV_getAlarmMgr()` |
| isOutpost | `` | `boolean` | `obj:isOutpost()` |
| _setMainResident | `forceForGates: boolean` | `boolean` | `obj:_setMainResident(forceForGates)` |
| spawnTheBarFlies | `` | `void` | `obj:spawnTheBarFlies()` |
| townLoadedEvent | `newGameFirstTime: boolean` | `void` | `obj:townLoadedEvent(newGameFirstTime)` |
| notifyUnloading | `` | `void` | `obj:notifyUnloading()` |
| getBuildingMaterial | `` | `GameData` | `obj:getBuildingMaterial()` |
| getLocalTradePriceMult | `` | `number` | `obj:getLocalTradePriceMult()` |
| getFactionTradeCultureMult | `` | `number` | `obj:getFactionTradeCultureMult()` |
| isTown | `` | `Town` | `obj:isTown()` |
| _NV_isTown | `` | `Town` | `obj:_NV_isTown()` |
| isNest | `` | `lightuserdata` | `obj:isNest()` |
| _NV_isNest | `` | `lightuserdata` | `obj:_NV_isNest()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| saveState | `` | `void` | `obj:saveState()` |
| _NV_saveState | `` | `void` | `obj:_NV_saveState()` |
| loadState | `` | `void` | `obj:loadState()` |
| _NV_loadState | `` | `void` | `obj:_NV_loadState()` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| _NV_needsSaving | `mod: string` | `boolean` | `obj:_NV_needsSaving(mod)` |
| setPosition | `p: Vector3` | `void` | `obj:setPosition(p)` |
| saveStateEditor | `` | `void` | `obj:saveStateEditor()` |
| _NV_saveStateEditor | `` | `void` | `obj:_NV_saveStateEditor()` |
| loadStateEditor | `` | `void` | `obj:loadStateEditor()` |
| _NV_loadStateEditor | `` | `void` | `obj:_NV_loadStateEditor()` |
| getRadius | `` | `number` | `obj:getRadius()` |
| _NV_getRadius | `` | `number` | `obj:_NV_getRadius()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| _NV_isActive | `` | `boolean` | `obj:_NV_isActive()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| _NV_updatePowerGrid | `` | `void` | `obj:_NV_updatePowerGrid()` |
| hasResidentHQ | `` | `boolean` | `obj:hasResidentHQ()` |
| _NV_hasResidentHQ | `` | `boolean` | `obj:_NV_hasResidentHQ()` |
| gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| _NV_gatesAllClosed | `` | `boolean` | `obj:_NV_gatesAllClosed()` |
| hasGates | `` | `boolean` | `obj:hasGates()` |
| _NV_hasGates | `` | `boolean` | `obj:_NV_hasGates()` |
| notifyAccesibility | `accessible: boolean` | `void` | `obj:notifyAccesibility(accessible)` |
| getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| _NV_getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:_NV_getNearestGate(to)` |
| getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| _NV_getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:_NV_getPositionOutsideTownGates(dist)` |
| addBuilding | `powerIn: boolean, powerOut: boolean, battery: boolean` | `void` | `obj:addBuilding(powerIn, powerOut, battery)` |
| removeBuilding | `` | `void` | `obj:removeBuilding()` |
| isPlayerBuildingsInThisTown | `` | `boolean` | `obj:isPlayerBuildingsInThisTown()` |
| setPlayerBuildingsInThisTown | `` | `void` | `obj:setPlayerBuildingsInThisTown()` |
| getRequiredPower | `` | `number` | `obj:getRequiredPower()` |
| getTotalPower | `` | `number` | `obj:getTotalPower()` |
| hasSparePower | `` | `boolean` | `obj:hasSparePower()` |
| getBatteryDrain | `` | `number` | `obj:getBatteryDrain()` |
| getBatteryChargeMax | `` | `number` | `obj:getBatteryChargeMax()` |
| getBatteryCharge | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryCharge01 | `` | `number` | `obj:getBatteryCharge01()` |
| getBatteryChargingUpAmount | `` | `number` | `obj:getBatteryChargingUpAmount()` |
| getBatteryPowerTotal | `` | `number` | `obj:getBatteryPowerTotal()` |
| isBatteryMode | `` | `boolean` | `obj:isBatteryMode()` |
| addNest | `pos: Vector3` | `void` | `obj:addNest(pos)` |
| removeNest | `` | `boolean` | `obj:removeNest()` |
| clearNests | `` | `void` | `obj:clearNests()` |
| getMapMarker | `` | `string` | `obj:getMapMarker()` |
| _NV_getMapMarker | `` | `string` | `obj:_NV_getMapMarker()` |
| getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| _NV_getMapMarkerZoomLevel | `` | `integer` | `obj:_NV_getMapMarkerZoomLevel()` |
| recalculatePlayerTownLevel | `` | `void` | `obj:recalculatePlayerTownLevel()` |
| deActivationCheck | `` | `void` | `obj:deActivationCheck()` |
| _initialiseResidentData | `` | `void` | `obj:_initialiseResidentData()` |
| chooseResidents | `` | `void` | `obj:chooseResidents()` |
| chooseBuildingForResident | `` | `Building` | `obj:chooseBuildingForResident()` |
| addGate | `` | `void` | `obj:addGate()` |
| _NV_addGate | `` | `void` | `obj:_NV_addGate()` |
| setHandle | `` | `void` | `obj:setHandle()` |
| _NV_setHandle | `` | `void` | `obj:_NV_setHandle()` |
| getPlayerTownTypeEnum | `` | `integer` | `obj:getPlayerTownTypeEnum()` |

## TownBase
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| positionCacher | TownPositionCacher | RW | `obj.positionCacher = <value>` |
| population | lightuserdata | R | `obj.population` |
| alreadyInitialisedPopulationParams | boolean | RW | `obj.alreadyInitialisedPopulationParams = <value>` |
| isSecret | boolean | RW | `obj.isSecret = <value>` |
| timeOfDeath | TimeOfDay | RW | `obj.timeOfDeath = <value>` |
| p_TIME | number | RW | `obj.p_TIME = <value>` |
| nestBatcher | lightuserdata | R | `obj.nestBatcher` |
| unexploredName | string | RW | `obj.unexploredName = <value>` |
| discovered | boolean | RW | `obj.discovered = <value>` |
| explored | boolean | RW | `obj.explored = <value>` |
| recentlyDiscovered | boolean | RW | `obj.recentlyDiscovered = <value>` |
| entityMarker | lightuserdata | R | `obj.entityMarker` |
| entityLabel | ScreenLabel | RW | `obj.entityLabel = <value>` |
| clickHull | lightuserdata | R | `obj.clickHull` |
| biome | lightuserdata | R | `obj.biome` |
| isActivated | boolean | RW | `obj.isActivated = <value>` |
| currentFloorVisibility | integer | RW | `obj.currentFloorVisibility = <value>` |
| buildingsManager | TownBuildingsManager | RW | `obj.buildingsManager = <value>` |
| defaultResident | GameData | RW | `obj.defaultResident = <value>` |
| alarmState | TownAlarmState | R | `obj.alarmState` |
| artifacts | Ogre::FastArray<ArtifactItemData> | R | `obj.artifacts` |
| factionsResidentHere | unknown | RW | `obj.factionsResidentHere = <value>` |
| myZoneCoverage | ogre_unordered_set<ZoneMap*>::type | RW | `obj.myZoneCoverage = <value>` |
| occupiers | unknown | RW | `obj.occupiers = <value>` |
| populatedZones | unknown | RW | `obj.populatedZones = <value>` |
| residentsSpawned | lektor<TownBase::ResidentData> | RW | `obj.residentsSpawned = <value>` |
| residentsSpawned_BarsOrSomething | lektor<TownBase::ResidentData> | RW | `obj.residentsSpawned_BarsOrSomething = <value>` |
| townType | integer | RW | `obj.townType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TownBase` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| activate | `` | `void` | `obj:activate()` |
| _NV_activate | `` | `void` | `obj:_NV_activate()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| _NV_isActive | `` | `boolean` | `obj:_NV_isActive()` |
| setup | `_pos: Vector3` | `void` | `obj:setup(_pos)` |
| _NV_setup | `_pos: Vector3` | `void` | `obj:_NV_setup(_pos)` |
| _reset | `` | `void` | `obj:_reset()` |
| _NV__reset | `` | `void` | `obj:_NV__reset()` |
| getKnownName | `` | `string` | `obj:getKnownName()` |
| reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| _NV_reassessTownPosition | `` | `void` | `obj:_NV_reassessTownPosition()` |
| isNotFriendly | `` | `boolean` | `obj:isNotFriendly()` |
| _NV_isNotFriendly | `` | `boolean` | `obj:_NV_isNotFriendly()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| _NV_isPhysical | `` | `boolean` | `obj:_NV_isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| _NV_getDataType | `` | `integer` | `obj:_NV_getDataType()` |
| isTown | `` | `Town` | `obj:isTown()` |
| _NV_isTown | `` | `Town` | `obj:_NV_isTown()` |
| isNest | `` | `lightuserdata` | `obj:isNest()` |
| nestUpThisSpot | `pos: Vector3` | `void` | `obj:nestUpThisSpot(pos)` |
| _NV_nestUpThisSpot | `pos: Vector3` | `void` | `obj:_NV_nestUpThisSpot(pos)` |
| loadFromSerialise | `` | `void` | `obj:loadFromSerialise()` |
| _NV_loadFromSerialise | `` | `void` | `obj:_NV_loadFromSerialise()` |
| isOutpost | `` | `boolean` | `obj:isOutpost()` |
| withinBordersRange | `p: Vector3, mult: number` | `boolean` | `obj:withinBordersRange(p, mult)` |
| withinDiscoveryRange | `p: Vector3, explored: boolean` | `boolean` | `obj:withinDiscoveryRange(p, explored)` |
| isIllegal | `` | `boolean` | `obj:isIllegal()` |
| _NV_isIllegal | `` | `boolean` | `obj:_NV_isIllegal()` |
| distanceTo | `to: Vector3` | `number` | `obj:distanceTo(to)` |
| squaredDistanceTo | `to: Vector3` | `number` | `obj:squaredDistanceTo(to)` |
| isDead | `` | `boolean` | `obj:isDead()` |
| _NV_isDead | `` | `boolean` | `obj:_NV_isDead()` |
| getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| _NV_getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:_NV_getPositionOutsideTownGates(dist)` |
| setFaction | `` | `void` | `obj:setFaction()` |
| _NV_setFaction | `` | `void` | `obj:_NV_setFaction()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| _NV_isPublic | `` | `boolean` | `obj:_NV_isPublic()` |
| addGate | `` | `void` | `obj:addGate()` |
| _NV_addGate | `` | `void` | `obj:_NV_addGate()` |
| addOccupier | `` | `void` | `obj:addOccupier()` |
| removeOccupier | `` | `void` | `obj:removeOccupier()` |
| getRadius | `` | `number` | `obj:getRadius()` |
| _NV_getRadius | `` | `number` | `obj:_NV_getRadius()` |
| getGUIData | `category: integer` | `void` | `obj:getGUIData(category)` |
| _NV_getGUIData | `category: integer` | `void` | `obj:_NV_getGUIData(category)` |
| saveState | `` | `void` | `obj:saveState()` |
| _NV_saveState | `` | `void` | `obj:_NV_saveState()` |
| loadState | `` | `void` | `obj:loadState()` |
| _NV_loadState | `` | `void` | `obj:_NV_loadState()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| _NV_periodicUpdate | `` | `void` | `obj:_NV_periodicUpdate()` |
| updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| _NV_updatePowerGrid | `` | `void` | `obj:_NV_updatePowerGrid()` |
| hasResidentHQ | `` | `boolean` | `obj:hasResidentHQ()` |
| _NV_hasResidentHQ | `` | `boolean` | `obj:_NV_hasResidentHQ()` |
| findAllBuildingsOfType | `func: integer` | `lightuserdata` | `obj:findAllBuildingsOfType(func)` |
| _NV_findAllBuildingsOfType | `func: integer` | `lightuserdata` | `obj:_NV_findAllBuildingsOfType(func)` |
| findAllBuildingsWithFunction | `func: integer` | `lightuserdata` | `obj:findAllBuildingsWithFunction(func)` |
| _NV_findAllBuildingsWithFunction | `func: integer` | `lightuserdata` | `obj:_NV_findAllBuildingsWithFunction(func)` |
| allBuildingsDoorsOpen | `` | `boolean` | `obj:allBuildingsDoorsOpen()` |
| _NV_allBuildingsDoorsOpen | `` | `boolean` | `obj:_NV_allBuildingsDoorsOpen()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _NV_getPosition | `` | `Vector3` | `obj:_NV_getPosition()` |
| getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| _NV_getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:_NV_getPositionForWaypoint(from)` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| _NV_getAlarmMgr | `` | `lightuserdata` | `obj:_NV_getAlarmMgr()` |
| hasGates | `` | `boolean` | `obj:hasGates()` |
| _NV_hasGates | `` | `boolean` | `obj:_NV_hasGates()` |
| gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| _NV_gatesAllClosed | `` | `boolean` | `obj:_NV_gatesAllClosed()` |
| getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| _NV_getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:_NV_getNearestGate(to)` |
| getBiome | `` | `lightuserdata` | `obj:getBiome()` |
| _NV_getBiome | `` | `lightuserdata` | `obj:_NV_getBiome()` |
| isRecentlyDiscovered | `` | `boolean` | `obj:isRecentlyDiscovered()` |
| _NV_isRecentlyDiscovered | `` | `boolean` | `obj:_NV_isRecentlyDiscovered()` |
| setRecentlyDiscovered | `value: boolean` | `void` | `obj:setRecentlyDiscovered(value)` |
| _NV_setRecentlyDiscovered | `value: boolean` | `void` | `obj:_NV_setRecentlyDiscovered(value)` |
| isDiscovered | `` | `boolean` | `obj:isDiscovered()` |
| _NV_isDiscovered | `` | `boolean` | `obj:_NV_isDiscovered()` |
| setDiscovered | `value: boolean` | `void` | `obj:setDiscovered(value)` |
| _NV_setDiscovered | `value: boolean` | `void` | `obj:_NV_setDiscovered(value)` |
| setDead | `` | `void` | `obj:setDead()` |
| _NV_setDead | `` | `void` | `obj:_NV_setDead()` |
| isExplored | `` | `boolean` | `obj:isExplored()` |
| _NV_isExplored | `` | `boolean` | `obj:_NV_isExplored()` |
| setExplored | `value: boolean` | `void` | `obj:setExplored(value)` |
| _NV_setExplored | `value: boolean` | `void` | `obj:_NV_setExplored(value)` |
| getItemArtifactsMinValue | `` | `integer` | `obj:getItemArtifactsMinValue()` |
| _NV_getItemArtifactsMinValue | `` | `integer` | `obj:_NV_getItemArtifactsMinValue()` |
| getItemArtifactsMaxValue | `` | `integer` | `obj:getItemArtifactsMaxValue()` |
| _NV_getItemArtifactsMaxValue | `` | `integer` | `obj:_NV_getItemArtifactsMaxValue()` |
| getGearArtifactsMinValue | `` | `integer` | `obj:getGearArtifactsMinValue()` |
| _NV_getGearArtifactsMinValue | `` | `integer` | `obj:_NV_getGearArtifactsMinValue()` |
| getGearArtifactsMaxValue | `` | `integer` | `obj:getGearArtifactsMaxValue()` |
| _NV_getGearArtifactsMaxValue | `` | `integer` | `obj:_NV_getGearArtifactsMaxValue()` |
| setZonePopulated | `` | `void` | `obj:setZonePopulated()` |
| getBuildingsManager | `` | `TownBuildingsManager` | `obj:getBuildingsManager()` |
| getBuildingFloorVisibility | `` | `integer` | `obj:getBuildingFloorVisibility()` |
| setBuildingsFloorVisibility | `floor: integer` | `void` | `obj:setBuildingsFloorVisibility(floor)` |
| resetBuildingsFloorVisibility | `` | `void` | `obj:resetBuildingsFloorVisibility()` |
| getTownFloorVisiblity | `` | `integer` | `obj:getTownFloorVisiblity()` |
| setTownFloorVisiblity | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setTownFloorVisiblity(floor, onlyPlayerBuildings)` |
| resetTownFloorVisibility | `` | `void` | `obj:resetTownFloorVisibility()` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| _NV_getCurrentTownLocation | `` | `TownBase` | `obj:_NV_getCurrentTownLocation()` |
| getMapMarker | `` | `string` | `obj:getMapMarker()` |
| _NV_getMapMarker | `` | `string` | `obj:_NV_getMapMarker()` |
| getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| _NV_getMapMarkerZoomLevel | `` | `integer` | `obj:_NV_getMapMarkerZoomLevel()` |
| isOccupied | `` | `boolean` | `obj:isOccupied()` |
| _nestUpThisSpot | `pos: Vector3` | `void` | `obj:_nestUpThisSpot(pos)` |
| _NV__nestUpThisSpot | `pos: Vector3` | `void` | `obj:_NV__nestUpThisSpot(pos)` |
| distributeArtifacts | `` | `void` | `obj:distributeArtifacts()` |
| getUnexploredName | `` | `string` | `obj:getUnexploredName()` |
| _NV_getUnexploredName | `` | `string` | `obj:_NV_getUnexploredName()` |

## TownBase_ResidentData
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `count: integer, chance: integer, priority: integer` | `TownBase::ResidentData` | `obj:_CONSTRUCTOR(count, chance, priority)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TownBuildingsManager
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| signsVisible | boolean | RW | `obj.signsVisible = <value>` |
| town | TownBase | RW | `obj.town = <value>` |
| buildingEntities | ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type | R | `obj.buildingEntities` |
| instancesManagers | boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > > | R | `obj.instancesManagers` |
| signs | Ogre::FastArray<std::pair<Building*, Ogre::Entity*> > | R | `obj.signs` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TownBuildingsManager` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| moveBuildingsTo | `` | `void` | `obj:moveBuildingsTo()` |
| removeBuilding | `` | `void` | `obj:removeBuilding()` |
| setFloorVisible | `floor: integer` | `void` | `obj:setFloorVisible(floor)` |
| setAllVisible | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setAllVisible(floor, onlyPlayerBuildings)` |
| resetAllVisible | `` | `void` | `obj:resetAllVisible()` |
| setSignsVisible | `value: boolean` | `void` | `obj:setSignsVisible(value)` |
| factoryObjectCreatedCallback | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| _NV_factoryObjectCreatedCallback | `` | `void` | `obj:_NV_factoryObjectCreatedCallback()` |

## TownBuildingsManager_BuildingInfo
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TownBuildingsManager::BuildingInfo` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TownListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| formatItem | `` | `string` | `obj:formatItem()` |
| _NV_formatItem | `` | `string` | `obj:_NV_formatItem()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TownPositionCacher
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lastUpdateStamp | TimeOfDay | RW | `obj.lastUpdateStamp = <value>` |
| updateRateInHours | number | RW | `obj.updateRateInHours = <value>` |
| pos | Vector3 | RW | `obj.pos = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TownPositionCacher` | `obj:_CONSTRUCTOR()` |
| stampUpdate | `` | `void` | `obj:stampUpdate()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |

## Town_NestSpot
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `Town::NestSpot` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TradeCulture
**Header:** `extern/KenshiLib/Include/kenshi/TradeCulture.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| forbiddenItems | lektor<GameData*> | RW | `obj.forbiddenItems = <value>` |
| illegalBuildings | StdSetBinding<GameData*>::SetType | RW | `obj.illegalBuildings = <value>` |
| happyBuildings | StdSetBinding<GameData*>::SetType | RW | `obj.happyBuildings = <value>` |
| illegalItems | StdSetBinding<GameData*>::SetType | RW | `obj.illegalItems = <value>` |
| tradeGoodsMults | unknown | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| getAllIllegalItems | `` | `StdSetBinding<GameData*>::SetType` | `obj:getAllIllegalItems()` |
| isItemIllegal | `` | `boolean` | `obj:isItemIllegal()` |
| getTradePriceMultiplier | `` | `number` | `obj:getTradePriceMultiplier()` |
| hasTradePriceMultiplier | `` | `boolean` | `obj:hasTradePriceMultiplier()` |
| getForbiddenItemsList | `` | `lektor<GameData*>` | `obj:getForbiddenItemsList()` |
| _CONSTRUCTOR | `` | `TradeCulture` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TradeResult
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | integer | RW | `obj.value = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `value: integer` | `TradeResult` | `obj:_CONSTRUCTOR(value)` |
| showMessage | `` | `void` | `obj:showMessage()` |

## TraderInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| scrollBackpack | lightuserdata | R | `obj.scrollBackpack` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TraitBool
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TraitBool` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TransformWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/TransformWindow.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | DatapanelGUI | RW | `obj.window = <value>` |
| windowXValue | DataPanelLine_TextEditable | RW | `obj.windowXValue = <value>` |
| windowYValue | DataPanelLine_TextEditable | RW | `obj.windowYValue = <value>` |
| windowZValue | DataPanelLine_TextEditable | RW | `obj.windowZValue = <value>` |
| modeButton | DataPanelLine_Button | RW | `obj.modeButton = <value>` |
| axisButton | DataPanelLine_Button | RW | `obj.axisButton = <value>` |
| revertButton | DataPanelLine_Button | RW | `obj.revertButton = <value>` |
| node | lightuserdata | R | `obj.node` |
| parentNode | lightuserdata | R | `obj.parentNode` |
| gizmo | lightuserdata | R | `obj.gizmo` |
| mode | integer | RW | `obj.mode = <value>` |
| coordinateSystem | integer | RW | `obj.coordinateSystem = <value>` |
| hasScale | boolean | RW | `obj.hasScale = <value>` |
| lastZone | ZoneMap | RW | `obj.lastZone = <value>` |
| currentZone | ZoneMap | RW | `obj.currentZone = <value>` |
| currentInstance | InstanceID | RW | `obj.currentInstance = <value>` |
| changed | boolean | RW | `obj.changed = <value>` |
| editChanged | boolean | RW | `obj.editChanged = <value>` |
| lastMouse | unknown | RW | `obj.lastMouse = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TransformWindow` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| updateState | `` | `void` | `obj:updateState()` |
| close | `` | `void` | `obj:close()` |
| refresh | `` | `void` | `obj:refresh()` |
| updateGizmo | `` | `boolean` | `obj:updateGizmo()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| hasChanged | `` | `boolean` | `obj:hasChanged()` |
| clearChangedFlag | `` | `void` | `obj:clearChangedFlag()` |
| getMode | `` | `integer` | `obj:getMode()` |
| setMode | `m: integer` | `boolean` | `obj:setMode(m)` |
| getLastZone | `` | `ZoneMap` | `obj:getLastZone()` |
| getZone | `` | `ZoneMap` | `obj:getZone()` |
| changeMode | `` | `void` | `obj:changeMode()` |
| changeCoord | `` | `void` | `obj:changeCoord()` |
| changeValue | `` | `void` | `obj:changeValue()` |
| reset | `` | `void` | `obj:reset()` |
| revert | `` | `void` | `obj:revert()` |

## TreeData
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| position | Vector3 | RW | `obj.position = <value>` |
| scale | number | RW | `obj.scale = <value>` |
| target | lightuserdata | R | `obj.target` |
| building | Building | RW | `obj.building = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TriggerCallback
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateFrameEndMT | `` | `void` | `obj:updateFrameEndMT()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TripleInt
**Header:** `extern/KenshiLib/Include/kenshi/util/TripleInt.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | unknown | RW | `obj.value = <value>` |

## TurretBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TurretBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| gunClass | lightuserdata | R | `obj.gunClass` |
| aimDistInDegrees | number | RW | `obj.aimDistInDegrees = <value>` |
| currentAimDir | Vector3 | RW | `obj.currentAimDir = <value>` |
| rootAimDir | Vector3 | RW | `obj.rootAimDir = <value>` |
| currentAimSpeed | number | RW | `obj.currentAimSpeed = <value>` |
| currentAimTarget | Vector3 | RW | `obj.currentAimTarget = <value>` |
| mountedBuilding | hand | R | `obj.mountedBuilding` |
| hingePart | lightuserdata | R | `obj.hingePart` |
| gunPart | lightuserdata | R | `obj.gunPart` |
| aimTargetPos | Vector3 | RW | `obj.aimTargetPos = <value>` |
| rotating | integer | RW | `obj.rotating = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| setup | `` | `void` | `obj:setup()` |
| _NV_setup | `` | `void` | `obj:_NV_setup()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| getStatUsed | `` | `integer` | `obj:getStatUsed()` |
| getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| _NV_getProductionMultForGUI | `` | `number` | `obj:_NV_getProductionMultForGUI()` |
| aimAt | `who: Vector3` | `void` | `obj:aimAt(who)` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| _NV_setVisible | `on: boolean` | `void` | `obj:_NV_setVisible(on)` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| _NV_amInsideTownWalls | `` | `integer` | `obj:_NV_amInsideTownWalls()` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| _NV_destroyPhysical | `` | `void` | `obj:_NV_destroyPhysical()` |
| onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| _NV_onBuildingLoaded | `` | `void` | `obj:_NV_onBuildingLoaded()` |
| calculatePowerMult | `` | `number` | `obj:calculatePowerMult()` |
| _teleport | `p: Vector3` | `void` | `obj:_teleport(p)` |
| clearTownBuildingsManagerPtr | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| _NV_clearTownBuildingsManagerPtr | `` | `void` | `obj:_NV_clearTownBuildingsManagerPtr()` |

## TutorialGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| highlightItem | integer | RW | `obj.highlightItem = <value>` |
| highlightItemWidget | MyGUI::Widget | R | `obj.highlightItemWidget` |
| highlightPanel | MyGUI::Widget | R | `obj.highlightPanel` |
| highlightDirection | integer | RW | `obj.highlightDirection = <value>` |
| highlightAlpha | number | RW | `obj.highlightAlpha = <value>` |
| window | MyGUI::Widget | R | `obj.window` |
| windowPrevButton | MyGUI::Widget | R | `obj.windowPrevButton` |
| windowNextButton | MyGUI::Widget | R | `obj.windowNextButton` |
| windowText | MyGUI::Widget | R | `obj.windowText` |
| dismissButton | MyGUI::Widget | R | `obj.dismissButton` |
| pagingText | MyGUI::Widget | R | `obj.pagingText` |
| tooltipsPanel | MyGUI::Widget | R | `obj.tooltipsPanel` |
| currentTutorialItem | TutorialItem | RW | `obj.currentTutorialItem = <value>` |
| flashNewItem | boolean | RW | `obj.flashNewItem = <value>` |
| enabled | boolean | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TutorialGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| startHighlight | `item: integer` | `void` | `obj:startHighlight(item)` |
| endHighlight | `` | `void` | `obj:endHighlight()` |
| _setHightlightCoords | `` | `void` | `obj:_setHightlightCoords()` |
| update | `` | `void` | `obj:update()` |
| _NV_update | `` | `void` | `obj:_NV_update()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| show | `value: boolean` | `void` | `obj:show(value)` |
| _NV_show | `value: boolean` | `void` | `obj:_NV_show(value)` |
| removeTutorialFromList | `` | `void` | `obj:removeTutorialFromList()` |
| arrangeList | `` | `void` | `obj:arrangeList()` |
| refreshUI | `` | `void` | `obj:refreshUI()` |
| showTutorialWindow | `` | `void` | `obj:showTutorialWindow()` |
| closeTutorialWindow | `` | `void` | `obj:closeTutorialWindow()` |
| updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |

## TutorialGUILine
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nameButton | lightuserdata | R | `obj.nameButton` |
| closeButton | lightuserdata | R | `obj.closeButton` |
| flashWidget | lightuserdata | R | `obj.flashWidget` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateHighlight | `time: number` | `boolean` | `obj:updateHighlight(time)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TutorialItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| id | integer | RW | `obj.id = <value>` |
| started | boolean | RW | `obj.started = <value>` |
| locked | boolean | RW | `obj.locked = <value>` |
| title | string | RW | `obj.title = <value>` |
| state | integer | RW | `obj.state = <value>` |
| subItemIndex | integer | RW | `obj.subItemIndex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `TutorialItem` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getId | `` | `integer` | `obj:getId()` |
| isLastSubItem | `` | `boolean` | `obj:isLastSubItem()` |
| isSkippable | `` | `boolean` | `obj:isSkippable()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| hasEnded | `` | `boolean` | `obj:hasEnded()` |
| getCurrentSubItem | `` | `TutorialSubItem` | `obj:getCurrentSubItem()` |
| getSubItemAt | `index: integer` | `TutorialSubItem` | `obj:getSubItemAt(index)` |
| getCurrentSubItemIndex | `` | `integer` | `obj:getCurrentSubItemIndex()` |
| getNumSubItems | `` | `integer` | `obj:getNumSubItems()` |
| hasNextSubItem | `` | `boolean` | `obj:hasNextSubItem()` |
| hasPrevSubItem | `` | `boolean` | `obj:hasPrevSubItem()` |
| nextSubItem | `` | `void` | `obj:nextSubItem()` |
| prevSubItem | `` | `void` | `obj:prevSubItem()` |
| getStarted | `` | `boolean` | `obj:getStarted()` |
| getEnded | `` | `boolean` | `obj:getEnded()` |
| reset | `` | `void` | `obj:reset()` |
| _NV_reset | `` | `void` | `obj:_NV_reset()` |
| conditionsMet | `` | `boolean` | `obj:conditionsMet()` |
| start | `` | `void` | `obj:start()` |
| _NV_start | `` | `void` | `obj:_NV_start()` |
| run | `` | `boolean` | `obj:run()` |
| _NV_run | `` | `boolean` | `obj:_NV_run()` |
| end | `` | `void` | `obj:end()` |
| _NV_end | `` | `void` | `obj:_NV_end()` |

## TutorialSubItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| description | string | RW | `obj.description = <value>` |
| skippeable | boolean | RW | `obj.skippeable = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| start | `` | `void` | `obj:start()` |
| _NV_start | `` | `void` | `obj:_NV_start()` |
| run | `` | `boolean` | `obj:run()` |
| _NV_run | `` | `boolean` | `obj:_NV_run()` |
| end | `` | `void` | `obj:end()` |
| _NV_end | `` | `void` | `obj:_NV_end()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## TutorialpediaGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentItem | TutorialItem | RW | `obj.currentItem = <value>` |
| currentItemIndex | integer | RW | `obj.currentItemIndex = <value>` |
| tutorialsList | MyGUI::Widget | R | `obj.tutorialsList` |
| descriptionText | MyGUI::Widget | R | `obj.descriptionText` |
| activateButton | MyGUI::Widget | R | `obj.activateButton` |
| prevButton | MyGUI::Widget | R | `obj.prevButton` |
| nextButton | MyGUI::Widget | R | `obj.nextButton` |
| pagingText | MyGUI::Widget | R | `obj.pagingText` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| show | `value: boolean` | `void` | `obj:show(value)` |
| _NV_show | `value: boolean` | `void` | `obj:_NV_show(value)` |
| clear | `` | `void` | `obj:clear()` |
| _NV_clear | `` | `void` | `obj:_NV_clear()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _NV_isVisible | `` | `boolean` | `obj:_NV_isVisible()` |
| _CONSTRUCTOR | `` | `TutorialpediaGUI` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| setup | `` | `void` | `obj:setup()` |
| updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |

## UniqueSpawnData
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| squadTemplate | GameData | RW | `obj.squadTemplate = <value>` |
| desiredNumberToHave | integer | RW | `obj.desiredNumberToHave = <value>` |
| respawnTimer | number | RW | `obj.respawnTimer = <value>` |
| existingSquadsList | lektor<hand> | RW | `obj.existingSquadsList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `num: integer` | `UniqueSpawnData` | `obj:_CONSTRUCTOR(num)` |
| currentNumber | `` | `integer` | `obj:currentNumber()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## UseableStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| shopOwner | unknown | RW | `obj.shopOwner = <value>` |
| callbackOwner | unknown | RW | `obj.callbackOwner = <value>` |
| hasProgressBarWhenUsed | boolean | RW | `obj.hasProgressBarWhenUsed = <value>` |
| progressBarLevel | number | RW | `obj.progressBarLevel = <value>` |
| occupantSelection | boolean | RW | `obj.occupantSelection = <value>` |
| needsOperating | boolean | RW | `obj.needsOperating = <value>` |
| numOperatorsMax | integer | RW | `obj.numOperatorsMax = <value>` |
| hungerRate | number | RW | `obj.hungerRate = <value>` |
| _recievesBatteryPower | boolean | RW | `obj._recievesBatteryPower = <value>` |
| powerOn | boolean | RW | `obj.powerOn = <value>` |
| _isBroken | boolean | RW | `obj._isBroken = <value>` |
| batteryOutputStat | number | RW | `obj.batteryOutputStat = <value>` |
| _powerOutputMax | number | RW | `obj._powerOutputMax = <value>` |
| currentPower | number | RW | `obj.currentPower = <value>` |
| powerTimeStored | number | RW | `obj.powerTimeStored = <value>` |
| _powerTimeStoreMax | number | RW | `obj._powerTimeStoreMax = <value>` |
| currentOperators | std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > | R | `obj.currentOperators` |
| usesStat | integer | RW | `obj.usesStat = <value>` |
| functionalityData | GameData | R | `obj.functionalityData` |
| animation | GameData | R | `obj.animation` |
| animationKO | GameData | R | `obj.animationKO` |
| animationDazed | GameData | R | `obj.animationDazed` |
| maxUseRange | number | RW | `obj.maxUseRange = <value>` |
| sfxTime | number | RW | `obj.sfxTime = <value>` |
| inventory | Inventory | R | `obj.inventory` |
| doorLock | lightuserdata | R | `obj.doorLock` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| createInventoryLayout | `` | `lightuserdata` | `obj:createInventoryLayout()` |
| _NV_createInventoryLayout | `` | `lightuserdata` | `obj:_NV_createInventoryLayout()` |
| takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| _NV_takeMoney | `n: integer` | `boolean` | `obj:_NV_takeMoney(n)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| _NV_getMoney | `` | `integer` | `obj:_NV_getMoney()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _NV_getInventory | `` | `Inventory` | `obj:_NV_getInventory()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| _NV_needsUpdate | `` | `boolean` | `obj:_NV_needsUpdate()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| _NV_threadedUpdate | `` | `void` | `obj:_NV_threadedUpdate()` |
| calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| _NV_calculateEfficiencyMult | `` | `number` | `obj:_NV_calculateEfficiencyMult()` |
| isOutOfPower | `` | `number` | `obj:isOutOfPower()` |
| _NV_isOutOfPower | `` | `number` | `obj:_NV_isOutOfPower()` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| _NV_isBroken | `` | `boolean` | `obj:_NV_isBroken()` |
| setBroken | `on: boolean` | `void` | `obj:setBroken(on)` |
| _NV_setBroken | `on: boolean` | `void` | `obj:_NV_setBroken(on)` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| _NV_isDisabled | `` | `boolean` | `obj:_NV_isDisabled()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| _NV_getMouseCursor | `` | `integer` | `obj:_NV_getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| _NV_getDefaultTask | `` | `integer` | `obj:_NV_getDefaultTask()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| _NV_dontNeedWorkRightNow | `` | `boolean` | `obj:_NV_dontNeedWorkRightNow()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| takePowerFrom | `amount: number, frameTime: number` | `number` | `obj:takePowerFrom(amount, frameTime)` |
| howMuchPowerDoYouWantMax | `` | `number` | `obj:howMuchPowerDoYouWantMax()` |
| howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| _NV_howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:_NV_howMuchPowerDoYouWantForSortingFunction()` |
| howMuchPowerDoYouWantNow | `` | `number` | `obj:howMuchPowerDoYouWantNow()` |
| needPowerRightNow | `` | `boolean` | `obj:needPowerRightNow()` |
| _NV_needPowerRightNow | `` | `boolean` | `obj:_NV_needPowerRightNow()` |
| givePower | `amount: number` | `void` | `obj:givePower(amount)` |
| _NV_givePower | `amount: number` | `void` | `obj:_NV_givePower(amount)` |
| resetPower | `` | `void` | `obj:resetPower()` |
| getMaxPower | `` | `number` | `obj:getMaxPower()` |
| getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| _NV_getPowerOutput | `` | `number` | `obj:_NV_getPowerOutput()` |
| getFuelConsumptionRate | `` | `number` | `obj:getFuelConsumptionRate()` |
| _NV_getFuelConsumptionRate | `` | `number` | `obj:_NV_getFuelConsumptionRate()` |
| isBattery | `` | `boolean` | `obj:isBattery()` |
| isGenerator | `` | `boolean` | `obj:isGenerator()` |
| getBatteryCharge | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryChargeMax | `` | `number` | `obj:getBatteryChargeMax()` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| _NV_setupFromData | `` | `void` | `obj:_NV_setupFromData()` |
| switchPowerOn | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| _NV_switchPowerOn | `on: boolean` | `void` | `obj:_NV_switchPowerOn(on)` |
| hasPower | `` | `boolean` | `obj:hasPower()` |
| isPowerOn | `` | `boolean` | `obj:isPowerOn()` |
| _NV_isPowerOn | `` | `boolean` | `obj:_NV_isPowerOn()` |
| isRecievesBatteryPower | `` | `boolean` | `obj:isRecievesBatteryPower()` |
| getStatUsed | `` | `integer` | `obj:getStatUsed()` |
| getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| _NV_getDoorLock | `` | `lightuserdata` | `obj:_NV_getDoorLock()` |
| hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| _NV_hasDoorLock | `` | `boolean` | `obj:_NV_hasDoorLock()` |
| getFunctionalityData | `` | `GameData` | `obj:getFunctionalityData()` |
| setup | `` | `void` | `obj:setup()` |
| _NV_setup | `` | `void` | `obj:_NV_setup()` |
| getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| _NV_getOutputBasedRotationSpeedMult | `` | `number` | `obj:_NV_getOutputBasedRotationSpeedMult()` |
| getGUIPowerEfficiencyToolTipString | `` | `string` | `obj:getGUIPowerEfficiencyToolTipString()` |
| _NV_getGUIPowerEfficiencyToolTipString | `` | `string` | `obj:_NV_getGUIPowerEfficiencyToolTipString()` |

## UtilityT
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| marker | lightuserdata | R | `obj.marker` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| perlinNoise_2D | `x: number, y: number, zoom: number, dropPoint: number` | `number` | `obj:perlinNoise_2D(x, y, zoom, dropPoint)` |
| getTerrainHeightFastWithNormal | `x: number, z: number, normal: Vector3` | `number` | `obj:getTerrainHeightFastWithNormal(x, z, normal)` |
| getTerrainSlopeFast | `x: number, z: number` | `number` | `obj:getTerrainSlopeFast(x, z)` |
| profilesClear | `` | `void` | `obj:profilesClear()` |
| profilesPrint | `` | `void` | `obj:profilesPrint()` |
| profileGet | `name: string` | `integer` | `obj:profileGet(name)` |
| flushMarkerQueue | `` | `void` | `obj:flushMarkerQueue()` |
| removeMarkers | `` | `void` | `obj:removeMarkers()` |
| folderExists | `folder: string` | `boolean` | `obj:folderExists(folder)` |
| fileExistsASCII | `file: string` | `boolean` | `obj:fileExistsASCII(file)` |
| createFile | `path: string, content: string` | `boolean` | `obj:createFile(path, content)` |
| writeFile | `path: string, content: string, append: boolean` | `boolean` | `obj:writeFile(path, content, append)` |
| isFile | `_path: string` | `boolean` | `obj:isFile(_path)` |
| isDirectory | `_path: string` | `boolean` | `obj:isDirectory(_path)` |
| deleteFilesInFolder | `dir: string, filter: string, recursive: boolean` | `void` | `obj:deleteFilesInFolder(dir, filter, recursive)` |
| deleteFolder | `dir: string` | `void` | `obj:deleteFolder(dir)` |
| deleteFile | `dir: string` | `void` | `obj:deleteFile(dir)` |
| moveFile | `from: string, to: string` | `boolean` | `obj:moveFile(from, to)` |
| copyFile | `from: string, to: string` | `boolean` | `obj:copyFile(from, to)` |
| copyFilesInFolder | `from: string, to: string, filter: string` | `boolean` | `obj:copyFilesInFolder(from, to, filter)` |
| getTerrainHeight | `z: number` | `number` | `obj:getTerrainHeight(z)` |
| getTerrainWithWaterHeight | `z: number` | `number` | `obj:getTerrainWithWaterHeight(z)` |
| getTerrainWithWaterHeightFromRenderer | `` | `number` | `obj:getTerrainWithWaterHeightFromRenderer()` |
| getPositionInWater | `z: number` | `boolean` | `obj:getPositionInWater(z)` |
| getFloorHeight | `withTerrain: boolean, furniture: boolean, furniture: boolean` | `number` | `obj:getFloorHeight(withTerrain, furniture, furniture)` |
| getBuildingGroundFloorHeight | `withTerrain: boolean` | `number` | `obj:getBuildingGroundFloorHeight(withTerrain)` |
| isIndoors | `` | `Building` | `obj:isIndoors()` |
| isIndoorsFast | `` | `boolean` | `obj:isIndoorsFast()` |
| isIndoors_forWaypoint | `` | `Building` | `obj:isIndoors_forWaypoint()` |
| getFloorNumber | `` | `integer` | `obj:getFloorNumber()` |
| getTerrainHeightFast | `z: number` | `number` | `obj:getTerrainHeightFast(z)` |
| random | `hi: number` | `number` | `obj:random(hi)` |
| randomBool | `` | `boolean` | `obj:randomBool()` |
| randomInt | `hi: integer` | `integer` | `obj:randomInt(hi)` |
| seed | `` | `void` | `obj:seed()` |
| round | `` | `integer` | `obj:round()` |
| nlerp | `b: number, t: number` | `number` | `obj:nlerp(b, t)` |
| getNextPow2 | `` | `integer` | `obj:getNextPow2()` |
| quatSetDirection | `arg1: unknown, arg2: unknown` | `Quaternion` | `obj:quatSetDirection(arg1, arg2)` |
| getSubMapSector | `Z: number` | `void` | `obj:getSubMapSector(Z)` |
| getSubMapSectorBounds | `` | `number` | `obj:getSubMapSectorBounds()` |
| getResourceFilePath | `` | `string` | `obj:getResourceFilePath()` |
| removePathFromString | `` | `string` | `obj:removePathFromString()` |
| removeFilenameFromPath | `` | `string` | `obj:removeFilenameFromPath()` |
| removeFileExtensionFromString | `` | `string` | `obj:removeFileExtensionFromString()` |
| getFileExtensionFromString | `` | `string` | `obj:getFileExtensionFromString()` |
| removeInvalidFileNameChars | `` | `string` | `obj:removeInvalidFileNameChars()` |
| compareStringsCaseInsenstive | `b: string` | `boolean` | `obj:compareStringsCaseInsenstive(b)` |
| makeSureGameFolderExists | `` | `void` | `obj:makeSureGameFolderExists()` |
| makeSureFolderExists | `` | `void` | `obj:makeSureFolderExists()` |
| getFullPath | `` | `string` | `obj:getFullPath()` |
| positionIsInFrontOfMe | `arg1: unknown` | `boolean` | `obj:positionIsInFrontOfMe(arg1)` |
| pointInPlane | `arg1: unknown, arg2: unknown` | `boolean` | `obj:pointInPlane(arg1, arg2)` |
| colorToGUIString | `g: number, b: number, a: number` | `string` | `obj:colorToGUIString(g, b, a)` |
| getFilesInDir | `dir: string, type: string` | `boolean` | `obj:getFilesInDir(dir, type)` |
| getFilesInGameDir | `dir: string, type: string` | `boolean` | `obj:getFilesInGameDir(dir, type)` |
| getDirsInDir | `dir: string` | `void` | `obj:getDirsInDir(dir)` |
| readFile | `path: string` | `string` | `obj:readFile(path)` |
| roundToNearest | `input: number, roundTo: integer` | `number` | `obj:roundToNearest(input, roundTo)` |

## VisibleObjectInfo
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | unknown | RW | `obj.handle = <value>` |
| range | number | RW | `obj.range = <value>` |
| isEnemy | boolean | RW | `obj.isEnemy = <value>` |

## WallBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/WallBuilding.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| wallSectionLinkType | WallSectionLinkType | R | `obj.wallSectionLinkType` |
| shareBuildStateOfAnother | unknown | RW | `obj.shareBuildStateOfAnother = <value>` |
| othersSharingMyBuildState | lektor<hand> | RW | `obj.othersSharingMyBuildState = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| _NV_getUseableStuff | `` | `UseableStuff` | `obj:_NV_getUseableStuff()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| _NV_getReachRange | `` | `number` | `obj:_NV_getReachRange()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| _NV_isForSale | `` | `boolean` | `obj:_NV_isForSale()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| _NV_createPhysical | `` | `boolean` | `obj:_NV_createPhysical()` |
| isDamaged | `` | `boolean` | `obj:isDamaged()` |
| _NV_isDamaged | `` | `boolean` | `obj:_NV_isDamaged()` |
| getPositionForWaypoint_outside | `` | `Vector3` | `obj:getPositionForWaypoint_outside()` |
| getOutsideGateCode | `` | `integer` | `obj:getOutsideGateCode()` |
| isAWall | `` | `WallBuilding` | `obj:isAWall()` |
| _NV_isAWall | `` | `WallBuilding` | `obj:_NV_isAWall()` |
| canUpgrade | `` | `GameData` | `obj:canUpgrade()` |
| _NV_canUpgrade | `` | `GameData` | `obj:_NV_canUpgrade()` |
| addConstructionProgress | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| _NV_addConstructionProgress | `amount: number` | `void` | `obj:_NV_addConstructionProgress(amount)` |
| setConstructionProgress | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| _NV_setConstructionProgress | `amount: number` | `void` | `obj:_NV_setConstructionProgress(amount)` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| _NV_notifyConstructionComplete | `` | `void` | `obj:_NV_notifyConstructionComplete()` |
| addDismantleProgress | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| _NV_addDismantleProgress | `amount: number` | `boolean` | `obj:_NV_addDismantleProgress(amount)` |
| notifyConstructionDismantling | `` | `void` | `obj:notifyConstructionDismantling()` |
| _NV_notifyConstructionDismantling | `` | `void` | `obj:_NV_notifyConstructionDismantling()` |
| getBuildState | `` | `lightuserdata` | `obj:getBuildState()` |
| _NV_getBuildState | `` | `lightuserdata` | `obj:_NV_getBuildState()` |
| isALittleWallPartLikeACornerOrSomething | `` | `boolean` | `obj:isALittleWallPartLikeACornerOrSomething()` |
| isAShortWallPart | `` | `boolean` | `obj:isAShortWallPart()` |

## Weapon
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bleedDamage | number | RW | `obj.bleedDamage = <value>` |
| modAttack | integer | RW | `obj.modAttack = <value>` |
| combatWeight | number | RW | `obj.combatWeight = <value>` |
| category | integer | RW | `obj.category = <value>` |
| category_animationOverride | integer | RW | `obj.category_animationOverride = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _NV_getItemWeight | `` | `number` | `obj:_NV_getItemWeight()` |
| getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| _NV_getValueSingle | `isPlayer: boolean` | `integer` | `obj:_NV_getValueSingle(isPlayer)` |
| getCategory | `` | `integer` | `obj:getCategory()` |
| getCategory_animationOverride | `` | `integer` | `obj:getCategory_animationOverride()` |
| is2HandedOnly | `` | `boolean` | `obj:is2HandedOnly()` |
| getCombatWeight | `` | `number` | `obj:getCombatWeight()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| _NV_getCraftTime | `` | `number` | `obj:_NV_getCraftTime()` |
| getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| _NV_getCraftMaterialMult | `` | `number` | `obj:_NV_getCraftMaterialMult()` |
| isWeapon | `` | `Weapon` | `obj:isWeapon()` |
| _NV_isWeapon | `` | `Weapon` | `obj:_NV_isWeapon()` |
| isSword | `` | `Sword` | `obj:isSword()` |
| _NV_isSword | `` | `Sword` | `obj:_NV_isSword()` |
| isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| _NV_isCrossbow | `` | `Crossbow` | `obj:_NV_isCrossbow()` |
| getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| _NV_getSkillModIndoors | `` | `integer` | `obj:_NV_getSkillModIndoors()` |
| _CONSTRUCTOR | `_level: integer` | `Weapon` | `obj:_CONSTRUCTOR(_level)` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## WeatherRegion
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| biomeGroup | lightuserdata | RW | `obj.biomeGroup = <value>` |
| weatherStrengthMultiplierMin | number | RW | `obj.weatherStrengthMultiplierMin = <value>` |
| weatherStrengthMultiplierMax | number | RW | `obj.weatherStrengthMultiplierMax = <value>` |
| weatherInstance | lightuserdata | R | `obj.weatherInstance` |
| currentSeason | lightuserdata | RW | `obj.currentSeason = <value>` |
| currentSeasonIndex | integer | RW | `obj.currentSeasonIndex = <value>` |
| currentSeasonEndDay | integer | RW | `obj.currentSeasonEndDay = <value>` |
| biomeGroupLoaded | boolean | RW | `obj.biomeGroupLoaded = <value>` |
| requestUpdateEffects | boolean | RW | `obj.requestUpdateEffects = <value>` |
| activeCameraBiome | boolean | RW | `obj.activeCameraBiome = <value>` |
| weatherUpdated | boolean | RW | `obj.weatherUpdated = <value>` |
| instanceUpdated | boolean | RW | `obj.instanceUpdated = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| reset | `` | `void` | `obj:reset()` |
| getWeatherInstance | `` | `lightuserdata` | `obj:getWeatherInstance()` |
| setCurrentSeason | `seasonIndex: integer, seasonEnd: integer` | `void` | `obj:setCurrentSeason(seasonIndex, seasonEnd)` |
| getNewWeatherStrength | `` | `number` | `obj:getNewWeatherStrength()` |
| update | `` | `void` | `obj:update()` |
| updateBT | `` | `void` | `obj:updateBT()` |
| addListener | `listener: userdata` | `void` | `obj:addListener(listener)` |
| removeListener | `listener: userdata` | `void` | `obj:removeListener(listener)` |
| addGlobalEffect | `type: integer` | `void` | `obj:addGlobalEffect(type)` |
| getNewSeason | `` | `void` | `obj:getNewSeason()` |
| weatherChanged | `newWeather: boolean` | `void` | `obj:weatherChanged(newWeather)` |
| updateWeatherEffects | `` | `void` | `obj:updateWeatherEffects()` |
| save | `key: string` | `void` | `obj:save(key)` |
| load | `key: string` | `void` | `obj:load(key)` |

## WhoSeesMe
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lastUpdated | number | RW | `obj.lastUpdated = <value>` |
| seeState | YesNoMaybe | RW | `obj.seeState = <value>` |
| progressOfMaybe | number | RW | `obj.progressOfMaybe = <value>` |

## WindGeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| _NV_getPowerOutput | `` | `number` | `obj:_NV_getPowerOutput()` |
| getSoundIntensity | `` | `number` | `obj:getSoundIntensity()` |
| _NV_getSoundIntensity | `` | `number` | `obj:_NV_getSoundIntensity()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| _NV_isAnyInputsEmpty | `` | `boolean` | `obj:_NV_isAnyInputsEmpty()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## WorldEventStateQuery
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| playerInvolvement | boolean | RW | `obj.playerInvolvement = <value>` |
| isAllyOf | unknown | RW | `obj.isAllyOf = <value>` |
| isEnemyOf | unknown | RW | `obj.isEnemyOf = <value>` |
| towns | unknown | RW | `obj.towns = <value>` |
| uniqueNPCsAre | unknown | RW | `obj.uniqueNPCsAre = <value>` |
| uniqueNPCsAreNot | unknown | RW | `obj.uniqueNPCsAreNot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `WorldEventStateQuery` | `obj:_CONSTRUCTOR()` |
| isTrue | `` | `boolean` | `obj:isTrue()` |

## WorldEventStateQueryList
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| statesList | unknown | RW | `obj.statesList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupFrom | `listname: string` | `boolean` | `obj:setupFrom(listname)` |
| reset | `` | `void` | `obj:reset()` |
| isTrue | `` | `boolean` | `obj:isTrue()` |
| _CONSTRUCTOR | `` | `WorldEventStateQueryList` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## YesNoMaybe
**Header:** `extern/KenshiLib/Include/kenshi/util/YesNoMaybe.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | integer | RW | `obj.key = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| toInt | `` | `integer` | `obj:toInt()` |

## ZoneManager
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| justLoadedAGame | boolean | RW | `obj.justLoadedAGame = <value>` |
| characterGrid | ZoneSpacialGrid | R | `obj.characterGrid` |
| buildingGrid | ZoneSpacialGrid | R | `obj.buildingGrid` |
| itemGrid | ZoneSpacialGrid | R | `obj.itemGrid` |
| _needCalculateIslands | boolean | RW | `obj._needCalculateIslands = <value>` |
| spawnUpdateTimerMT | number | RW | `obj.spawnUpdateTimerMT = <value>` |
| spawnUpdateTimerTT | number | RW | `obj.spawnUpdateTimerTT = <value>` |
| distantTownCentre | iVector2 | RW | `obj.distantTownCentre = <value>` |
| centralZone | ZoneMap | RW | `obj.centralZone = <value>` |
| loadingPhase | integer | RW | `obj.loadingPhase = <value>` |
| biomeMap | lightuserdata | R | `obj.biomeMap` |
| groundEffectsPool | ParticlePool | RW | `obj.groundEffectsPool = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ZoneManager` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneLoadedT(pos)` |
| _NV_isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:_NV_isZoneLoadedT(pos)` |
| isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(pos)` |
| _NV_isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:_NV_isZoneBeingLoadedT(pos)` |
| getNumActiveZones | `` | `integer` | `obj:getNumActiveZones()` |
| findShop | `selling: integer` | `Building` | `obj:findShop(selling)` |
| findAnyShop | `` | `Building` | `obj:findAnyShop()` |
| setup | `` | `void` | `obj:setup()` |
| updateMainThread | `camerapos: Vector3` | `void` | `obj:updateMainThread(camerapos)` |
| updateRendertimeThread | `camerapos: Vector3` | `void` | `obj:updateRendertimeThread(camerapos)` |
| updateGPUSafeThread | `camerapos: Vector3` | `void` | `obj:updateGPUSafeThread(camerapos)` |
| spawnChecksUpdateThreaded | `island: integer` | `void` | `obj:spawnChecksUpdateThreaded(island)` |
| levelEditorDeleteAllSelectedObjects | `` | `void` | `obj:levelEditorDeleteAllSelectedObjects()` |
| getCurrentMapSector | `` | `void` | `obj:getCurrentMapSector()` |
| getCurrentZoneMap | `` | `ZoneMap` | `obj:getCurrentZoneMap()` |
| getSubMapSector | `X: number, Z: number` | `void` | `obj:getSubMapSector(X, Z)` |
| getZoneMapFromResolutionCoord | `X: number, Z: number` | `void` | `obj:getZoneMapFromResolutionCoord(X, Z)` |
| playerActivate | `pos: Vector3` | `boolean` | `obj:playerActivate(pos)` |
| deactivateZoneMap | `saveZoneState: boolean` | `void` | `obj:deactivateZoneMap(saveZoneState)` |
| getBiome | `position: Vector3` | `GameData` | `obj:getBiome(position)` |
| getBiomeCode | `position: Vector3` | `integer` | `obj:getBiomeCode(position)` |
| getBiomeMap | `` | `lightuserdata` | `obj:getBiomeMap()` |
| getGroundTypeIndex | `pos: Vector3` | `integer` | `obj:getGroundTypeIndex(pos)` |
| getGroundType | `pos: Vector3` | `integer` | `obj:getGroundType(pos)` |
| addGroundEffect | `position: Vector3` | `void` | `obj:addGroundEffect(position)` |
| shiftGroundEffects | `shift: Vector3` | `void` | `obj:shiftGroundEffects(shift)` |
| checkZoneFiles | `` | `boolean` | `obj:checkZoneFiles()` |
| resetStates | `` | `void` | `obj:resetStates()` |
| getResourceId | `resource: integer` | `string` | `obj:getResourceId(resource)` |
| getResourceName | `resource: integer` | `string` | `obj:getResourceName(resource)` |
| saveMapFeatures | `` | `boolean` | `obj:saveMapFeatures()` |
| saveLevelData | `path: string, modName: string` | `void` | `obj:saveLevelData(path, modName)` |
| saveActiveZoneStates | `` | `void` | `obj:saveActiveZoneStates()` |
| resetGame | `` | `void` | `obj:resetGame()` |
| deactivateAllActiveZones | `` | `void` | `obj:deactivateAllActiveZones()` |
| activateAllActiveZones | `` | `void` | `obj:activateAllActiveZones()` |
| populateTownsForLevelEditor | `` | `void` | `obj:populateTownsForLevelEditor()` |
| calculateIslands | `` | `void` | `obj:calculateIslands()` |
| _reloadAllFoliage | `` | `void` | `obj:_reloadAllFoliage()` |
| _reloadGroundTextures | `` | `void` | `obj:_reloadGroundTextures()` |
| _unloadAllZones | `` | `void` | `obj:_unloadAllZones()` |
| checkForRepopulateTown | `` | `boolean` | `obj:checkForRepopulateTown()` |
| getCentralZone | `` | `ZoneMap` | `obj:getCentralZone()` |
| isLoading | `` | `integer` | `obj:isLoading()` |
| _calculateIslands | `` | `void` | `obj:_calculateIslands()` |
| loadFeatures | `` | `void` | `obj:loadFeatures()` |
| loadDistantTowns | `` | `void` | `obj:loadDistantTowns()` |
| processLoading | `` | `boolean` | `obj:processLoading()` |
| loadPhase1 | `` | `void` | `obj:loadPhase1()` |
| loadPhase2 | `` | `void` | `obj:loadPhase2()` |
| loadPhase3 | `` | `void` | `obj:loadPhase3()` |

## ZoneManagerInterfaceT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isZoneLoadedT | `_a1: Vector3` | `boolean` | `obj:isZoneLoadedT(_a1)` |
| isZoneBeingLoadedT | `_a1: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(_a1)` |
| _CONSTRUCTOR | `` | `ZoneManagerInterfaceT` | `obj:_CONSTRUCTOR()` |

## ZoneManager_BiomeGroundEffects
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ZoneManager::BiomeGroundEffects` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ZoneMap
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mapContent | lightuserdata | R | `obj.mapContent` |
| mapFeatures | lightuserdata | R | `obj.mapFeatures` |
| zoneSmell | lightuserdata | R | `obj.zoneSmell` |
| coordinates | iVector2 | RW | `obj.coordinates = <value>` |
| island | integer | RW | `obj.island = <value>` |
| hasFile | boolean | RW | `obj.hasFile = <value>` |
| terrainCollision | lightuserdata | R | `obj.terrainCollision` |
| activatedCountdown | unknown | RW | `obj.activatedCountdown = <value>` |
| _generateNavMeshesFlag | boolean | RW | `obj._generateNavMeshesFlag = <value>` |
| center | Vector3 | RW | `obj.center = <value>` |
| loadCount | integer | RW | `obj.loadCount = <value>` |
| neighbors | unknown | RW | `obj.neighbors = <value>` |
| neighborsDiagonal | unknown | RW | `obj.neighborsDiagonal = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ZoneMap` | `obj:_CONSTRUCTOR()` |
| isInIsland | `` | `boolean` | `obj:isInIsland()` |
| initialise | `` | `void` | `obj:initialise()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| update | `` | `boolean` | `obj:update()` |
| selectBiomes | `` | `integer` | `obj:selectBiomes()` |
| getBiomeCount | `` | `integer` | `obj:getBiomeCount()` |
| getBiomeData | `i: integer` | `GameData` | `obj:getBiomeData(i)` |
| getOverlay | `` | `lightuserdata` | `obj:getOverlay()` |
| getAreaSector | `` | `lightuserdata` | `obj:getAreaSector()` |
| getTerrainHeight | `_x: number, _y: number` | `number` | `obj:getTerrainHeight(_x, _y)` |
| getTerrainHeightWithNormal | `_x: number, _y: number, normal: Vector3` | `number` | `obj:getTerrainHeightWithNormal(_x, _y, normal)` |
| getTerrainSlope | `_x: number, _y: number` | `number` | `obj:getTerrainSlope(_x, _y)` |
| isWithinBoundsMinusUnloadedEdges | `borderThickness: number, v: Vector3` | `boolean` | `obj:isWithinBoundsMinusUnloadedEdges(borderThickness, v)` |
| getCornerPos | `` | `Vector3` | `obj:getCornerPos()` |
| getTerrainSector | `force: boolean` | `lightuserdata` | `obj:getTerrainSector(force)` |
| isActive | `` | `boolean` | `obj:isActive()` |
| getDeactivationCountdown | `` | `number` | `obj:getDeactivationCountdown()` |
| isLoadedBT | `` | `boolean` | `obj:isLoadedBT()` |
| isBeingLoadedBT | `` | `boolean` | `obj:isBeingLoadedBT()` |
| isLoadedMT | `` | `boolean` | `obj:isLoadedMT()` |
| isBeingLoadedMT | `` | `boolean` | `obj:isBeingLoadedMT()` |
| isANeighbour | `` | `boolean` | `obj:isANeighbour()` |
| isTerrainCollisionLoaded | `` | `boolean` | `obj:isTerrainCollisionLoaded()` |
| _makeSureTerrainHeightmapLoaded | `` | `void` | `obj:_makeSureTerrainHeightmapLoaded()` |
| _dactivateMT | `saveZoneState: boolean` | `void` | `obj:_dactivateMT(saveZoneState)` |
| generateNavMeshes | `` | `boolean` | `obj:generateNavMeshes()` |
| updateBuildingUsageNodes | `` | `void` | `obj:updateBuildingUsageNodes()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## ZoneSpacialGrid
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| zones | lightuserdata | R | `obj.zones` |
| createCellsFunc | lightuserdata | R | `obj.createCellsFunc` |
| cellCount | integer | RW | `obj.cellCount = <value>` |
| cellSize | number | RW | `obj.cellSize = <value>` |
| mutex | unknown | RW | `obj.mutex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ZoneSpacialGrid` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| add | `` | `integer` | `obj:add()` |
| remove | `` | `boolean` | `obj:remove()` |
| update | `` | `integer` | `obj:update()` |
| addZone | `` | `void` | `obj:addZone()` |
| removeZone | `` | `void` | `obj:removeZone()` |
| getZoneKey | `p: Vector3` | `integer` | `obj:getZoneKey(p)` |
| getCellKey | `p: Vector3` | `integer` | `obj:getCellKey(p)` |
| getFullKey | `p: Vector3` | `integer` | `obj:getFullKey(p)` |
| initialiseGrid | `size: number` | `void` | `obj:initialiseGrid(size)` |

## ZoneSpacialGrid_ZoneCell
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `ZoneSpacialGrid::ZoneCell` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## hkArray
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| clearAndDeallocate | `` | `void` | `obj:clearAndDeallocate()` |

## hkArrayBase
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| m_data | lightuserdata | R | `obj.m_data` |
| m_size | integer | RW | `obj.m_size = <value>` |
| m_capacityAndFlags | integer | RW | `obj.m_capacityAndFlags = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| getSize | `` | `integer` | `obj:getSize()` |
| getCapacity | `` | `integer` | `obj:getCapacity()` |
| clear | `` | `void` | `obj:clear()` |

## hkBool
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| m_bool | integer | RW | `obj.m_bool = <value>` |

## hkContainerHeapAllocator
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `hkContainerHeapAllocator` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## hkContainerHeapAllocator_Allocator
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `hkContainerHeapAllocator::Allocator` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## hkMemoryAllocator
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |
| blockAlloc | `_a1: integer` | `void` | `obj:blockAlloc(_a1)` |
| resetPeakMemoryStatistics | `` | `void` | `obj:resetPeakMemoryStatistics()` |
| _NV_resetPeakMemoryStatistics | `` | `void` | `obj:_NV_resetPeakMemoryStatistics()` |
| getExtendedInterface | `` | `lightuserdata` | `obj:getExtendedInterface()` |
| _NV_getExtendedInterface | `` | `lightuserdata` | `obj:_NV_getExtendedInterface()` |
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |

## hkMemoryAllocator_ExtendedInterface
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `void` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## hkMemoryAllocator_MemoryStatistics
**Header:** `???`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `hkMemoryAllocator::MemoryStatistics` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## hkResult
**Header:** `???`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| m_enum | integer | RW | `obj.m_enum = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `hkResult` | `obj:_CONSTRUCTOR()` |
| _DESTRUCTOR | `` | `void` | `obj:_DESTRUCTOR()` |

## hkVector4f
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setZero | `` | `void` | `obj:setZero()` |
| zeroComponent | `i: integer` | `void` | `obj:zeroComponent(i)` |
| setInt24W | `value: integer` | `void` | `obj:setInt24W(value)` |
| getInt24W | `` | `integer` | `obj:getInt24W()` |
| getInt16W | `` | `integer` | `obj:getInt16W()` |
| setZero4 | `` | `void` | `obj:setZero4()` |
| normalize3 | `` | `void` | `obj:normalize3()` |

## hkVector4fComparison
**Header:** `extern/KenshiLib/Include/kenshi/havok.h`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getIndexOfLastComponentSet | `` | `integer` | `obj:getIndexOfLastComponentSet()` |
| getIndexOfFirstComponentSet | `` | `integer` | `obj:getIndexOfFirstComponentSet()` |
| set | `m: integer` | `void` | `obj:set(m)` |
| allAreSet | `` | `integer` | `obj:allAreSet()` |

## iVector2
**Header:** `extern/KenshiLib/Include/kenshi/util/iVector2.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | integer | RW | `obj.x = <value>` |
| y | integer | RW | `obj.y = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getLinearValue | `` | `integer` | `obj:getLinearValue()` |
| getAsString | `` | `string` | `obj:getAsString()` |

## physHit
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _defaultAltitudeFallback | number | RW | `obj._defaultAltitudeFallback = <value>` |
| _traceWasAborted | boolean | RW | `obj._traceWasAborted = <value>` |
| _doNotAbort | boolean | RW | `obj._doNotAbort = <value>` |
| _needsGroup | boolean | RW | `obj._needsGroup = <value>` |
| hit | boolean | RW | `obj.hit = <value>` |
| position | Vector3 | RW | `obj.position = <value>` |
| normal | Vector3 | RW | `obj.normal = <value>` |
| distance | number | RW | `obj.distance = <value>` |
| shape | lightuserdata | R | `obj.shape` |
| hitObject | unknown | RW | `obj.hitObject = <value>` |
| _group | integer | RW | `obj._group = <value>` |
| _hitObjectUnsafePtr | RootObject | RW | `obj._hitObjectUnsafePtr = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| traceWasAborted | `` | `boolean` | `obj:traceWasAborted()` |
| reset | `` | `void` | `obj:reset()` |
| hitObjectUnsafePtr | `` | `RootObject` | `obj:hitObjectUnsafePtr()` |
| getBuilding | `` | `Building` | `obj:getBuilding()` |
| group | `` | `integer` | `obj:group()` |

## rendHit
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | integer | RW | `obj.data = <value>` |
| hit | Vector3 | RW | `obj.hit = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _CONSTRUCTOR | `` | `lightuserdata` | `obj:_CONSTRUCTOR()` |
