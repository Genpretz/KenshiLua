# Lua Bindings Reference

## Overview & Calling Conventions

### Method Invocations
- **Instance Methods**: Called on userdata instances using colon syntax: `instance:methodName(args)`.
- **Static Methods**: Functions that can be invoked statically via class table `ClassName.methodName(args)` or on an instance `instance:methodName(args)`.
- **Overloaded Methods**: Methods supporting multiple argument counts or polymorphic parameter types are documented with explicit overload indexes (e.g. `[1]`, `[2]`), indicating each signature's parameter types and return type.
- **Enums**: Enum values are Lua integers. Enum type names identify the constant table documented in the [Enums Reference](EnumsReference.md); types marked as bitmasks may combine multiple enum flags.
- **MyGUI User Interface**: For MyGUI widgets, dialogs, layouts, properties, and event callbacks, see the dedicated [MyGUI Reference](MyGUIReference.md).

## Table of Contents
- [MyGUI UI Reference](MyGUIReference.md)
- [`AABB2D`](#aabb2d)
- [`AbstractMovementBase`](#abstractmovementbase)
- [`ActivePlatoon`](#activeplatoon)
- [`AkSoundPosition`](#aksoundposition)
- [`AkVector`](#akvector)
- [`AnimalInventoryLayout`](#animalinventorylayout)
- [`AppearanceAnimal`](#appearanceanimal)
- [`AppearanceBase`](#appearancebase)
- [`AppearanceHuman`](#appearancehuman)
- [`AppearanceManager`](#appearancemanager)
  - [`AppearanceManager::AppearanceData`](#appearancemanager::appearancedata)
  - [`AppearanceManager::DataCategory`](#appearancemanager::datacategory)
  - [`AppearanceManager::DataRange`](#appearancemanager::datarange)
  - [`AppearanceManager::DataRangePose`](#appearancemanager::datarangepose)
  - [`AppearanceManager::DataRangeVector`](#appearancemanager::datarangevector)
  - [`AppearanceManager::Gender`](#appearancemanager::gender)
- [`Armour`](#armour)
- [`Array2d`](#array2d)
- [`BackpackInventoryLayout`](#backpackinventorylayout)
- [`BackThreadMessagesToMainT`](#backthreadmessagestomaint)
- [`BadSize`](#badsize)
- [`BoundsViolation`](#boundsviolation)
- [`Bounty`](#bounty)
- [`BountyManager`](#bountymanager)
- [`Building`](#building)
  - [`Building::ConstructionState`](#building::constructionstate)
  - [`Building::ConstructionState::BuildMaterial`](#building::constructionstate::buildmaterial)
- [`BuildingContainerInventoryLayout`](#buildingcontainerinventorylayout)
- [`BuildingPlacementGroundType`](#buildingplacementgroundtype)
- [`BuildInventoryLayout`](#buildinventorylayout)
- [`BuildModeWindow`](#buildmodewindow)
  - [`BuildModeWindow::BuildingCategory`](#buildmodewindow::buildingcategory)
  - [`BuildModeWindow::BuildingGroup`](#buildmodewindow::buildinggroup)
- [`CameraClass`](#cameraclass)
- [`CampaignTriggerData`](#campaigntriggerdata)
- [`Character`](#character)
  - [`Character::AttachedArrowManager`](#character::attachedarrowmanager)
  - [`Character::CarryMsg`](#character::carrymsg)
  - [`Character::RagdollMsg`](#character::ragdollmsg)
  - [`Character::WhoSeesMe`](#character::whoseesme)
- [`CharacterAnimal`](#characteranimal)
- [`CharacterEditWindow`](#charactereditwindow)
- [`CharacterHuman`](#characterhuman)
- [`CharacterInventoryLayout`](#characterinventorylayout)
- [`CharacterStatsWindow`](#characterstatswindow)
  - [`CharacterStatsWindow::Stat`](#characterstatswindow::stat)
  - [`CharacterStatsWindow::StatGroup`](#characterstatswindow::statgroup)
- [`CharacterTradingWindow`](#charactertradingwindow)
- [`CharBody`](#charbody)
- [`CharMovement`](#charmovement)
- [`CharStats`](#charstats)
- [`CombatClass`](#combatclass)
  - [`CombatClass::AttackSlotManager`](#combatclass::attackslotmanager)
  - [`CombatClass::AttackSlotManager::SlotData`](#combatclass::attackslotmanager::slotdata)
  - [`CombatClass::EffectData`](#combatclass::effectdata)
- [`CombatMovementController`](#combatmovementcontroller)
- [`CombatTechniqueData`](#combattechniquedata)
  - [`CombatTechniqueData::ImpactPoint`](#combattechniquedata::impactpoint)
- [`ContainerItem`](#containeritem)
- [`ContextMenu`](#contextmenu)
- [`ContextMenuGUI`](#contextmenugui)
- [`CPerfTimer`](#cperftimer)
- [`CPerfTimerT`](#cperftimert)
- [`CraftingBuilding`](#craftingbuilding)
- [`CraftingInventoryLayout`](#craftinginventorylayout)
- [`Crossbow`](#crossbow)
- [`Damages`](#damages)
- [`DataObjectContainer`](#dataobjectcontainer)
- [`DatapanelGUI`](#datapanelgui)
- [`DataPanelLine`](#datapanelline)
- [`DataPanelLine_Button`](#datapanelline_button)
- [`DataPanelLine_CheckBox`](#datapanelline_checkbox)
- [`DataPanelLine_DropBox`](#datapanelline_dropbox)
- [`DataPanelLine_Faction`](#datapanelline_faction)
- [`DataPanelLine_KeyConfig`](#datapanelline_keyconfig)
- [`DataPanelLine_Progress`](#datapanelline_progress)
- [`DataPanelLine_Research`](#datapanelline_research)
- [`DataPanelLine_Slider`](#datapanelline_slider)
- [`DataPanelLine_SliderEditable`](#datapanelline_slidereditable)
- [`DataPanelLine_Text`](#datapanelline_text)
- [`DataPanelLine_TextEditable`](#datapanelline_texteditable)
- [`DialogChoiceList`](#dialogchoicelist)
- [`DialogDataManager`](#dialogdatamanager)
- [`DialogLineData`](#dialoglinedata)
  - [`DialogLineData::DialogAction`](#dialoglinedata::dialogaction)
  - [`DialogLineData::DialogCondition`](#dialoglinedata::dialogcondition)
  - [`DialogLineData::FlagCondition`](#dialoglinedata::flagcondition)
- [`Dialogue`](#dialogue)
  - [`Dialogue::RepetitionCounter`](#dialogue::repetitioncounter)
  - [`Dialogue::RepetitionCounter::DialogState`](#dialogue::repetitioncounter::dialogstate)
- [`DialogueSpeechBubble`](#dialoguespeechbubble)
- [`DialogueWindow`](#dialoguewindow)
- [`DoorStuff`](#doorstuff)
- [`EdgeCache`](#edgecache)
  - [`EdgeCache::Edge`](#edgecache::edge)
- [`EdgePathNode`](#edgepathnode)
- [`Faction`](#faction)
  - [`Faction::BuildingSwaps`](#faction::buildingswaps)
  - [`Faction::CharacteristicsData`](#faction::characteristicsdata)
- [`FactionLeader`](#factionleader)
- [`FactionManager`](#factionmanager)
- [`FactionRelations`](#factionrelations)
  - [`FactionRelations::RelationData`](#factionrelations::relationdata)
- [`FactionsScreen`](#factionsscreen)
  - [`FactionsScreen::FactionRelationsLine`](#factionsscreen::factionrelationsline)
  - [`FactionsScreen::FactionRelationsLine::LessSort`](#factionsscreen::factionrelationsline::lesssort)
- [`FactionUniqueSquadManager`](#factionuniquesquadmanager)
  - [`FactionUniqueSquadManager::UniqueSpawnData`](#factionuniquesquadmanager::uniquespawndata)
- [`FactionWarMgr`](#factionwarmgr)
  - [`FactionWarMgr::CampaignRequest`](#factionwarmgr::campaignrequest)
- [`FactoryCallbackInterface`](#factorycallbackinterface)
- [`FarmBuilding`](#farmbuilding)
  - [`FarmBuilding::FarmBatch`](#farmbuilding::farmbatch)
  - [`FarmBuilding::Plant`](#farmbuilding::plant)
  - [`FarmBuilding::PlantSource`](#farmbuilding::plantsource)
  - [`FarmBuilding::SubPlant`](#farmbuilding::subplant)
- [`FloatingProgressBar`](#floatingprogressbar)
  - [`FloatingProgressBar::ProgressBarWidget`](#floatingprogressbar::progressbarwidget)
- [`FlockingTools`](#flockingtools)
- [`FogEditor`](#fogeditor)
- [`FoliageSystem`](#foliagesystem)
  - [`FoliageSystem::EntData`](#foliagesystem::entdata)
  - [`FoliageSystem::TreeData`](#foliagesystem::treedata)
- [`ForgottenGUI`](#forgottengui)
- [`FormationMover`](#formationmover)
- [`FurnaceBuilding`](#furnacebuilding)
- [`FurnaceInventoryLayout`](#furnaceinventorylayout)
- [`GameData`](#gamedata)
  - [`GameData::ItemData`](#gamedata::itemdata)
  - [`GameData::ObjectInstance`](#gamedata::objectinstance)
- [`GameDataContainer`](#gamedatacontainer)
- [`GameDataCopyStandalone`](#gamedatacopystandalone)
- [`GameDataEditorWindow`](#gamedataeditorwindow)
  - [`GameDataEditorWindow::DataItem`](#gamedataeditorwindow::dataitem)
- [`GameDataGroup`](#gamedatagroup)
- [`GameDataHeader`](#gamedataheader)
- [`GameDataManager`](#gamedatamanager)
- [`GameDataReference`](#gamedatareference)
- [`GameDataValuePair`](#gamedatavaluepair)
- [`GameplayOptions`](#gameplayoptions)
- [`GameSaveState`](#gamesavestate)
- [`GameWorld`](#gameworld)
  - [`GameWorld::SysMessage`](#gameworld::sysmessage)
- [`GatewayBuilding`](#gatewaybuilding)
- [`Gear`](#gear)
- [`GeneratorBuilding`](#generatorbuilding)
- [`GenericFixedInventoryLayout`](#genericfixedinventorylayout)
- [`GenericInventoryLayout`](#genericinventorylayout)
- [`Global`](#global)
- [`GlobalConstants`](#globalconstants)
- [`GUIWindow`](#guiwindow)
- [`Hand`](#hand)
- [`HavokCharacter`](#havokcharacter)
- [`hkArray`](#hkarray)
- [`hkArrayBase`](#hkarraybase)
- [`hkBool`](#hkbool)
- [`hkContainerHeapAllocator`](#hkcontainerheapallocator)
  - [`hkContainerHeapAllocator::Allocator`](#hkcontainerheapallocator::allocator)
- [`hkMemoryAllocator`](#hkmemoryallocator)
  - [`hkMemoryAllocator::ExtendedInterface`](#hkmemoryallocator::extendedinterface)
  - [`hkMemoryAllocator::MemoryStatistics`](#hkmemoryallocator::memorystatistics)
- [`hkResult`](#hkresult)
- [`hkTrait::TraitBool`](#hktrait::traitbool)
- [`hkVector4f`](#hkvector4f)
- [`hkVector4fComparison`](#hkvector4fcomparison)
- [`ImportGameMenu`](#importgamemenu)
- [`InputHandler`](#inputhandler)
  - [`InputHandler::Command`](#inputhandler::command)
- [`InstanceID`](#instanceid)
- [`InteriorModeButtonWindow`](#interiormodebuttonwindow)
- [`Inventory`](#inventory)
  - [`Inventory::HasRoomCache`](#inventory::hasroomcache)
- [`InventoryGUI`](#inventorygui)
  - [`InventoryGUI::FenceCallbackData`](#inventorygui::fencecallbackdata)
  - [`InventoryGUI::InventoryTradeData`](#inventorygui::inventorytradedata)
  - [`InventoryGUI::TradeResult`](#inventorygui::traderesult)
- [`InventoryIcon`](#inventoryicon)
- [`InventoryItemBase`](#inventoryitembase)
- [`InventoryLayout`](#inventorylayout)
- [`InventorySection`](#inventorysection)
  - [`InventorySection::SectionItem`](#inventorysection::sectionitem)
- [`InventorySectionGUI`](#inventorysectiongui)
- [`InventoryTraderGUI`](#inventorytradergui)
- [`Item`](#item)
- [`iVector2`](#ivector2)
- [`KenshiLib::BinaryVersion`](#kenshilib::binaryversion)
- [`LevelEditor`](#leveleditor)
  - [`LevelEditor::FactionListWindow`](#leveleditor::factionlistwindow)
  - [`LevelEditor::GamedataSelectionList`](#leveleditor::gamedataselectionlist)
  - [`LevelEditor::ItemListWindow`](#leveleditor::itemlistwindow)
  - [`LevelEditor::NpcListWindow`](#leveleditor::npclistwindow)
  - [`LevelEditor::SquadListWindow`](#leveleditor::squadlistwindow)
  - [`LevelEditor::TownListWindow`](#leveleditor::townlistwindow)
- [`LightBuilding`](#lightbuilding)
- [`LimbsInventoryLayout`](#limbsinventorylayout)
- [`ListScrollBar`](#listscrollbar)
- [`LoadingWindow`](#loadingwindow)
- [`LoadSaveWindow`](#loadsavewindow)
- [`LockedArmour`](#lockedarmour)
- [`Logger`](#logger)
- [`MainBarGUI`](#mainbargui)
- [`MainTabPortraitPlatoon`](#maintabportraitplatoon)
- [`MainthreadStateReaderT`](#mainthreadstatereadert)
- [`ManagementScreen`](#managementscreen)
  - [`ManagementScreen::TechItemViewData`](#managementscreen::techitemviewdata)
- [`MapScreen`](#mapscreen)
  - [`MapScreen::MapMarkerCharacter`](#mapscreen::mapmarkercharacter)
  - [`MapScreen::MapMarkerTown`](#mapscreen::mapmarkertown)
  - [`MapScreen::MapRoad`](#mapscreen::maproad)
- [`MedianFilter`](#medianfilter)
- [`MedianFilter2DVector`](#medianfilter2dvector)
- [`MedicalSystem`](#medicalsystem)
  - [`MedicalSystem::HealthPartStatus`](#medicalsystem::healthpartstatus)
- [`MeshDataLookup`](#meshdatalookup)
- [`MessageBoxManager`](#messageboxmanager)
  - [`MessageBoxManager::Box`](#messageboxmanager::box)
- [`MessageChain`](#messagechain)
- [`MessageForB`](#messageforb)
- [`MessageQueue`](#messagequeue)
  - [`MessageQueue::Node`](#messagequeue::node)
- [`ModInfo`](#modinfo)
- [`MotionFilter`](#motionfilter)
- [`MultiSlider`](#multislider)
- [`MustEndWithSemiColon`](#mustendwithsemicolon)
- [`NavInstance`](#navinstance)
- [`NavMesh`](#navmesh)
  - [`NavMesh::BuildingInfo`](#navmesh::buildinginfo)
  - [`NavMesh::NavMeshMessage`](#navmesh::navmeshmessage)
- [`NavMeshGenerator`](#navmeshgenerator)
  - [`NavMeshGenerator::Task`](#navmeshgenerator::task)
  - [`NavMeshGenerator::TaskQueue`](#navmeshgenerator::taskqueue)
- [`NavMeshSeeds`](#navmeshseeds)
- [`NewGameOptionsWindow`](#newgameoptionswindow)
- [`NewGameWindow`](#newgamewindow)
- [`Nx9Real`](#nx9real)
  - [`Nx9Real::S`](#nx9real::s)
- [`NxBox`](#nxbox)
- [`NxMat33`](#nxmat33)
- [`NxUserControllerHitReport`](#nxusercontrollerhitreport)
- [`NxUserTriggerReport`](#nxusertriggerreport)
- [`NxVec3`](#nxvec3)
- [`OpenSaveFileDialog`](#opensavefiledialog)
- [`OptionsHolder`](#optionsholder)
- [`OptionsWindow`](#optionswindow)
- [`OrderCellView`](#ordercellview)
- [`OrderData`](#orderdata)
- [`OrdersItemBox`](#ordersitembox)
- [`OrdersPanel`](#orderspanel)
- [`Ownerships`](#ownerships)
- [`ParticlePool`](#particlepool)
  - [`ParticlePool::ParticleData`](#particlepool::particledata)
- [`physHit`](#physhit)
- [`PhysicalEntity`](#physicalentity)
- [`PhysicsActual`](#physicsactual)
  - [`PhysicsActual::TriggerCallback`](#physicsactual::triggercallback)
- [`PhysicsCollection`](#physicscollection)
  - [`PhysicsCollection::LightEnt`](#physicscollection::lightent)
  - [`PhysicsCollection::RotatingEnt`](#physicscollection::rotatingent)
  - [`PhysicsCollection::StaticEnt`](#physicscollection::staticent)
- [`PhysicsInterface`](#physicsinterface)
- [`Platoon`](#platoon)
- [`PlayerInterface`](#playerinterface)
  - [`PlayerInterface::AIOptions`](#playerinterface::aioptions)
- [`PortraitData`](#portraitdata)
- [`PortraitImage`](#portraitimage)
- [`PortraitMainCellView`](#portraitmaincellview)
- [`PortraitManager`](#portraitmanager)
- [`PreviewBuilding`](#previewbuilding)
  - [`PreviewBuilding::Footprint`](#previewbuilding::footprint)
  - [`PreviewBuilding::FootprintNode`](#previewbuilding::footprintnode)
- [`ProductionBuilding`](#productionbuilding)
- [`ProductionInventoryLayout`](#productioninventorylayout)
- [`ProspectingWindow`](#prospectingwindow)
  - [`ProspectingWindow::ResourceLinePanel`](#prospectingwindow::resourcelinepanel)
- [`ProsperityManager`](#prosperitymanager)
- [`RaceData`](#racedata)
- [`RaceLimiter`](#racelimiter)
  - [`RaceLimiter::Limiter`](#racelimiter::limiter)
- [`RainCollectorBuilding`](#raincollectorbuilding)
- [`rendHit`](#rendhit)
- [`ReorderableList`](#reorderablelist)
- [`ResearchBuilding`](#researchbuilding)
- [`ResearchBuildingInventoryLayout`](#researchbuildinginventorylayout)
- [`ResourceLoader`](#resourceloader)
  - [`ResourceLoader::MeshLoadData`](#resourceloader::meshloaddata)
  - [`ResourceLoader::ResourceLoadRequestMesh`](#resourceloader::resourceloadrequestmesh)
  - [`ResourceLoader::ResourceLoadRequestTexture`](#resourceloader::resourceloadrequesttexture)
  - [`ResourceLoader::TextureArrayLoadData`](#resourceloader::texturearrayloaddata)
  - [`ResourceLoader::TextureLoadData`](#resourceloader::textureloaddata)
- [`RobotLimbItem`](#robotlimbitem)
- [`RobotLimbs`](#robotlimbs)
- [`RootObject`](#rootobject)
- [`RootObjectBase`](#rootobjectbase)
- [`RootObjectContainer`](#rootobjectcontainer)
  - [`RootObjectContainer::SpecificItemLoadFirst`](#rootobjectcontainer::specificitemloadfirst)
- [`RootObjectFactory`](#rootobjectfactory)
  - [`RootObjectFactory::CreatelistItem`](#rootobjectfactory::createlistitem)
- [`SaveFileSystem`](#savefilesystem)
  - [`SaveFileSystem::FileMessage`](#savefilesystem::filemessage)
- [`SaveInfo`](#saveinfo)
- [`SaveManager`](#savemanager)
- [`ScreenLabel`](#screenlabel)
- [`ScreenLabelDebug`](#screenlabeldebug)
- [`ScreenLabelInterface`](#screenlabelinterface)
- [`Scythe::PhysicsClass`](#scythe::physicsclass)
- [`SeenSomeone`](#seensomeone)
- [`SelectionBox`](#selectionbox)
- [`SenseItr`](#senseitr)
- [`SensoryData`](#sensorydata)
  - [`SensoryData::SpottingPeopleMgr`](#sensorydata::spottingpeoplemgr)
  - [`SensoryData::SpottingPeopleMgr::Spot`](#sensorydata::spottingpeoplemgr::spot)
- [`ShopTrader`](#shoptrader)
- [`ShopTraderInventory`](#shoptraderinventory)
- [`ShopTraderInventorySection`](#shoptraderinventorysection)
- [`SimpleTimeStamper`](#simpletimestamper)
- [`Slider`](#slider)
- [`SpeedGroup`](#speedgroup)
- [`SplashScreen`](#splashscreen)
- [`SquadManagementScreen`](#squadmanagementscreen)
  - [`SquadManagementScreen::PortraitSquadCellView`](#squadmanagementscreen::portraitsquadcellview)
  - [`SquadManagementScreen::PortraitSquadItemBox`](#squadmanagementscreen::portraitsquaditembox)
  - [`SquadManagementScreen::SquadCellView`](#squadmanagementscreen::squadcellview)
  - [`SquadManagementScreen::SquadData`](#squadmanagementscreen::squaddata)
  - [`SquadManagementScreen::SquadItemBox`](#squadmanagementscreen::squaditembox)
- [`StorageBuilding`](#storagebuilding)
  - [`StorageBuilding::ConsumptionItem`](#storagebuilding::consumptionitem)
- [`StringPair`](#stringpair)
- [`Sword`](#sword)
- [`TagsClass`](#tagsclass)
- [`TaskData`](#taskdata)
- [`Tasker`](#tasker)
- [`TaskStateData`](#taskstatedata)
- [`Terrain`](#terrain)
  - [`Terrain::BloodQueue`](#terrain::bloodqueue)
  - [`Terrain::Box`](#terrain::box)
  - [`Terrain::Hit`](#terrain::hit)
  - [`Terrain::Info`](#terrain::info)
- [`ThreadClass`](#threadclass)
- [`ThreadWannabe`](#threadwannabe)
- [`TimeOfDay`](#timeofday)
- [`TimerClass`](#timerclass)
- [`TitleScreen`](#titlescreen)
- [`ToolTip`](#tooltip)
  - [`ToolTip::ToolTipLine`](#tooltip::tooltipline)
- [`ToolTipDynamic`](#tooltipdynamic)
- [`ToolTipFixed`](#tooltipfixed)
- [`ToolTipInventory`](#tooltipinventory)
- [`ToolTipStatic`](#tooltipstatic)
- [`TortureBuilding`](#torturebuilding)
- [`Town`](#town)
  - [`Town::NestSpot`](#town::nestspot)
- [`TownBase`](#townbase)
  - [`TownBase::DelayedSpawnMsg`](#townbase::delayedspawnmsg)
  - [`TownBase::ResidentData`](#townbase::residentdata)
  - [`TownBase::TownPositionCacher`](#townbase::townpositioncacher)
- [`TownBuildingsManager`](#townbuildingsmanager)
  - [`TownBuildingsManager::BuildingInfo`](#townbuildingsmanager::buildinginfo)
- [`TradeCulture`](#tradeculture)
- [`TraderInventoryLayout`](#traderinventorylayout)
- [`TransformWindow`](#transformwindow)
- [`TripleInt`](#tripleint)
- [`TurretBuilding`](#turretbuilding)
- [`TutorialGUI`](#tutorialgui)
  - [`TutorialGUI::TutorialGUILine`](#tutorialgui::tutorialguiline)
- [`TutorialItem`](#tutorialitem)
- [`TutorialpediaGUI`](#tutorialpediagui)
- [`TutorialSubItem`](#tutorialsubitem)
- [`UseableStuff`](#useablestuff)
- [`UtilityT`](#utilityt)
- [`VisibleObjectInfo`](#visibleobjectinfo)
- [`WallBuilding`](#wallbuilding)
- [`Weapon`](#weapon)
- [`WeatherRegion`](#weatherregion)
  - [`WeatherRegion::Listener`](#weatherregion::listener)
- [`WindGeneratorBuilding`](#windgeneratorbuilding)
- [`WorldEventStateQuery`](#worldeventstatequery)
- [`WorldEventStateQueryList`](#worldeventstatequerylist)
- [`YesNoMaybe`](#yesnomaybe)
- [`ZoneManager`](#zonemanager)
  - [`ZoneManager::BiomeGroundEffects`](#zonemanager::biomegroundeffects)
- [`ZoneManagerInterfaceT`](#zonemanagerinterfacet)
- [`ZoneMap`](#zonemap)
  - [`ZoneMap::StateT`](#zonemap::statet)
- [`ZoneSpacialGrid`](#zonespacialgrid)
  - [`ZoneSpacialGrid::ZoneCell`](#zonespacialgrid::zonecell)

## AABB2D
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.AABB2D`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | `number` | RW | `obj.x = <value>` |
| y | `number` | RW | `obj.y = <value>` |
| x2 | `number` | RW | `obj.x2 = <value>` |
| y2 | `number` | RW | `obj.y2 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setNull | `` | `void` | `obj:setNull()` |
| pointWithin | `v: Vector3` | `boolean` | `obj:pointWithin(v)` |
| inflate | `amount: number` | `void` | `obj:inflate(amount)` |
| sizeX | `` | `number` | `obj:sizeX()` |
| sizeY | `` | `number` | `obj:sizeY()` |
| intersects [1] | `pos: Vector3, radius: number` | `boolean` | `obj:intersects(pos, radius)` |
| intersects [2] | `b: AABB2D` | `boolean` | `obj:intersects(b)` |
| intersects [3] | `raypos: Vector3, raydest: Vector3` | `boolean` | `obj:intersects(raypos, raydest)` |
| intersects2 | `rayorig: Vector2, raydirection: Vector2` | `Vector2` | `obj:intersects2(rayorig, raydirection)` |

## AbstractMovementBase
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.AbstractMovementBase`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| officiallyStopped | `boolean` | RW | `obj.officiallyStopped = <value>` |
| speedOrders | `MoveSpeed` | RW | `obj.speedOrders = <value>` |
| currentlyMoving | `boolean` | RW | `obj.currentlyMoving = <value>` |
| positionSmoother | `MedianFilter2DVector` | RW | `obj.positionSmoother = <value>` |
| currentMotion | `Vector3` | RW | `obj.currentMotion = <value>` |
| maxSpeed | `number` | RW | `obj.maxSpeed = <value>` |
| currentSpeed | `number` | RW | `obj.currentSpeed = <value>` |
| desiredSpeed | `number` | RW | `obj.desiredSpeed = <value>` |
| walkSpeed | `number` | RW | `obj.walkSpeed = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| direction | `Vector3` | RW | `obj.direction = <value>` |
| destination | `Vector3` | RW | `obj.destination = <value>` |
| pathDestination | `Vector3` | RW | `obj.pathDestination = <value>` |
| roadFollower | `lightuserdata` | RW | `obj.roadFollower = <value>` |
| roadWeight | `number` | RW | `obj.roadWeight = <value>` |
| speedGroup | `SpeedGroup` | RW | `obj.speedGroup = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| create | `_pos: Vector3` | `void` | `obj:create(_pos)` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| _setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _setPositionSimple | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| faceDirection | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| lookatPosition | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| getDestination | `` | `Vector3` | `obj:getDestination()` |
| isProbablyStuck | `` | `boolean` | `obj:isProbablyStuck()` |
| pathOk | `` | `boolean` | `obj:pathOk()` |
| pathFailed | `` | `boolean` | `obj:pathFailed()` |
| update | `_TIME: number` | `void` | `obj:update(_TIME)` |
| isDestinationReached | `` | `boolean` | `obj:isDestinationReached()` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| manualMovement | `desiredMotion: Vector3` | `void` | `obj:manualMovement(desiredMotion)` |
| halt | `` | `void` | `obj:halt()` |
| setRoadDestination | `dest: Vector3` | `boolean` | `obj:setRoadDestination(dest)` |
| setRoadPreference | `w: number` | `void` | `obj:setRoadPreference(w)` |
| extractRoadFollower | `` | `lightuserdata` | `obj:extractRoadFollower()` |
| setStandardWalkSpeed | `s: number` | `void` | `obj:setStandardWalkSpeed(s)` |
| getStandardWalkSpeed | `` | `number` | `obj:getStandardWalkSpeed()` |
| restoreDesiredSpeed | `` | `void` | `obj:restoreDesiredSpeed()` |
| setMaxSpeed | `ms: number` | `void` | `obj:setMaxSpeed(ms)` |
| getMaxSpeed | `` | `number` | `obj:getMaxSpeed()` |
| isCurrentlyMoving | `` | `boolean` | `obj:isCurrentlyMoving()` |
| getCurrentSpeed | `` | `number` | `obj:getCurrentSpeed()` |
| getCurrentMotion | `` | `Vector3` | `obj:getCurrentMotion()` |
| getCurrentSpeedRelativeToMax01 | `` | `number` | `obj:getCurrentSpeedRelativeToMax01()` |
| getSpeedOrders | `` | `MoveSpeed` | `obj:getSpeedOrders()` |
| leaveSpeedGroup | `` | `void` | `obj:leaveSpeedGroup()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFacingDirection | `` | `Vector3` | `obj:getFacingDirection()` |
| setDestination [1] | `dest: Vector3, pri: UpdatePriority, _a3: boolean` | `void` | `obj:setDestination(dest, pri, _a3)` |
| setDestination [2] | `target: RootObjectBase, pri: UpdatePriority` | `void` | `obj:setDestination(target, pri)` |
| setDestination [3] | `who: Character, pri: UpdatePriority` | `void` | `obj:setDestination(who, pri)` |
| setDestination [4] | `who: Building, pri: UpdatePriority` | `void` | `obj:setDestination(who, pri)` |
| setCurrentRoadFollower | `d: Vector3, r: userdata` | `void` | `obj:setCurrentRoadFollower(d, r)` |
| setPatrolInput | `patrol: userdata` | `void` | `obj:setPatrolInput(patrol)` |
| setDesiredSpeed [1] | `speed: MoveSpeed` | `void` | `obj:setDesiredSpeed(speed)` |
| setDesiredSpeed [2] | `speed: number` | `void` | `obj:setDesiredSpeed(speed)` |
| setDesiredSpeedOrders [1] | `speed: MoveSpeed` | `void` | `obj:setDesiredSpeedOrders(speed)` |
| setDesiredSpeedOrders [2] | `speed: number` | `void` | `obj:setDesiredSpeedOrders(speed)` |
| onShapeHit | `hit: userdata` | `integer` | `obj:onShapeHit(hit)` |
| onControllerHit | `hit: userdata` | `integer` | `obj:onControllerHit(hit)` |

## ActivePlatoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.ActivePlatoon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _groupSense | `lightuserdata` | R | `obj._groupSense` |
| isAnimalsOnly | `boolean` | RW | `obj.isAnimalsOnly = <value>` |
| me | `Platoon` | RW | `obj.me = <value>` |
| characterHandles | `lightuserdata` | R | `obj.characterHandles` |
| p_TIME | `number` | RW | `obj.p_TIME = <value>` |
| lastActiveZone | `ZoneMap` | RW | `obj.lastActiveZone = <value>` |
| _myMemory | `lightuserdata` | R | `obj._myMemory` |
| squadleader | `Character` | RW | `obj.squadleader = <value>` |
| backupLeader | `Character` | RW | `obj.backupLeader = <value>` |
| deactivationTimer | `number` | RW | `obj.deactivationTimer = <value>` |
| workingPos | `Vector3` | RW | `obj.workingPos = <value>` |
| currentGoal | `Tasker` | RW | `obj.currentGoal = <value>` |
| positionMoved | `Vector3` | RW | `obj.positionMoved = <value>` |
| teleportTo | `Vector3` | RW | `obj.teleportTo = <value>` |
| teleportMessage | `boolean` | RW | `obj.teleportMessage = <value>` |
| isPlayer | `PlayerInterface` | RW | `obj.isPlayer = <value>` |
| isPhysical | `boolean` | RW | `obj.isPhysical = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _recalculateIsIntact | `` | `boolean` | `obj:_recalculateIsIntact()` |
| isAnyoneCaptured | `` | `boolean` | `obj:isAnyoneCaptured()` |
| getGroupSense | `` | `lightuserdata` | `obj:getGroupSense()` |
| getMemory | `` | `lightuserdata` | `obj:getMemory()` |
| removeObject | `c: RootObject` | `boolean` | `obj:removeObject(c)` |
| addActiveObject | `c: RootObject` | `boolean` | `obj:addActiveObject(c)` |
| addCharacterAt | `c: RootObject, index: integer` | `void` | `obj:addCharacterAt(c, index)` |
| swapCharacters | `indexA: integer, indexB: integer` | `void` | `obj:swapCharacters(indexA, indexB)` |
| emptySquadCheck | `` | `void` | `obj:emptySquadCheck()` |
| clearAllTheUniqueNPCStates | `` | `void` | `obj:clearAllTheUniqueNPCStates()` |
| isIntact | `` | `boolean` | `obj:isIntact()` |
| getSquadLeader_theRealOne | `` | `Character` | `obj:getSquadLeader_theRealOne()` |
| getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getSquadSize | `` | `integer` | `obj:getSquadSize()` |
| setSquadLeader | `who: Character` | `void` | `obj:setSquadLeader(who)` |
| update | `` | `boolean` | `obj:update()` |
| refreshInventory | `firstTime: boolean` | `void` | `obj:refreshInventory(firstTime)` |
| _forceRefreshInventory | `` | `void` | `obj:_forceRefreshInventory()` |
| periodicUpdate | `` | `boolean` | `obj:periodicUpdate()` |
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
| unloadCheck | `` | `boolean` | `obj:unloadCheck()` |
| setupCheck | `` | `YesNoMaybe` | `obj:setupCheck()` |
| destroyCharacters | `justUnload: boolean` | `void` | `obj:destroyCharacters(justUnload)` |
| serialiseCharacterData | `` | `void` | `obj:serialiseCharacterData()` |
| saveToDisk | `levelEditor: boolean, force: string` | `void` | `obj:saveToDisk(levelEditor, force)` |
| loadCharacters | `_a1: Vector3, _a2: FactoryCallbackInterface` | `void` | `obj:loadCharacters(_a1, _a2)` |
| calculateCurrentPos | `` | `Vector3` | `obj:calculateCurrentPos()` |
| _checkForUniqueCharactersOnUnload | `` | `void` | `obj:_checkForUniqueCharactersOnUnload()` |
| getName | `` | `string` | `obj:getName()` |
| loadFromDisk | `force: boolean, extra: userdata` | `boolean` | `obj:loadFromDisk(force, extra)` |
| getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| loadInstance | `state: GameSaveState, skipSaveState: boolean, pos: Vector3, rot: Quaternion, callback: FactoryCallbackInterface, positionMoved: Vector3` | `void` | `obj:loadInstance(state, skipSaveState, pos, rot, callback, positionMoved)` |

## AkSoundPosition
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.AkSoundPosition`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| Position | `AkVector` | RW | `obj.Position = <value>` |
| Orientation | `AkVector` | RW | `obj.Orientation = <value>` |

## AkVector
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.AkVector`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| X | `number` | RW | `obj.X = <value>` |
| Y | `number` | RW | `obj.Y = <value>` |
| Z | `number` | RW | `obj.Z = <value>` |

## AnimalInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`
**Metatable:** `KenshiLua.AnimalInventoryLayout`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |

## AppearanceAnimal
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`
**Metatable:** `KenshiLua.AppearanceAnimal`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createBody | `` | `void` | `obj:createBody()` |
| updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |

## AppearanceBase
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`
**Metatable:** `KenshiLua.AppearanceBase`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| slots | `lightuserdata` | R | `obj.slots` |
| msgClearHarpoons | `boolean` | RW | `obj.msgClearHarpoons = <value>` |
| woundsListMutex | `lightuserdata` | R | `obj.woundsListMutex` |
| body | `lightuserdata` | RW | `obj.body = <value>` |
| bodyLoader | `lightuserdata` | R | `obj.bodyLoader` |
| isCreatingBody | `boolean` | RW | `obj.isCreatingBody = <value>` |
| bodyRadius | `number` | RW | `obj.bodyRadius = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| bodyFilename | `string` | RW | `obj.bodyFilename = <value>` |
| animation | `lightuserdata` | R | `obj.animation` |
| female | `boolean` | RW | `obj.female = <value>` |
| updatedAttachments | `boolean` | RW | `obj.updatedAttachments = <value>` |
| updatedAppearanceData | `boolean` | RW | `obj.updatedAppearanceData = <value>` |
| updateBody | `boolean` | RW | `obj.updateBody = <value>` |
| suid | `integer` | RW | `obj.suid = <value>` |
| appearanceData | `GameDataCopyStandalone` | RW | `obj.appearanceData = <value>` |
| raceData | `GameData` | RW | `obj.raceData = <value>` |
| factionColor | `GameData` | RW | `obj.factionColor = <value>` |
| hairStyle | `GameData` | RW | `obj.hairStyle = <value>` |
| shaved | `boolean` | RW | `obj.shaved = <value>` |
| waterLineFadeTimer | `number` | RW | `obj.waterLineFadeTimer = <value>` |
| barefoot | `boolean` | RW | `obj.barefoot = <value>` |
| hideAttachments | `boolean` | RW | `obj.hideAttachments = <value>` |
| characterHeight | `number` | RW | `obj.characterHeight = <value>` |
| characterHeightSpeedMultiplier | `number` | RW | `obj.characterHeightSpeedMultiplier = <value>` |
| characterHeight_0to1 | `number` | RW | `obj.characterHeight_0to1 = <value>` |
| waterline | `Vector4` | RW | `obj.waterline = <value>` |
| attachedHarpoons | `Ogre::FastArray<Harpoon*>` | RW | `obj.attachedHarpoons = <value>` |
| attachedEffects | `Ogre::FastArray<AttachedEffect*>` | RW | `obj.attachedEffects = <value>` |
| attachedEffectsToRemove | `Ogre::FastArray<AttachedEffect*>` | RW | `obj.attachedEffectsToRemove = <value>` |
| woundsList | `Ogre::FastArray<Wound*>` | RW | `obj.woundsList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateAnimationTransforms | `` | `void` | `obj:updateAnimationTransforms()` |
| forceUpdateAnimationTransforms | `` | `void` | `obj:forceUpdateAnimationTransforms()` |
| update | `` | `void` | `obj:update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| setAppearanceData | `data: GameDataCopyStandalone` | `void` | `obj:setAppearanceData(data)` |
| getAppearanceData | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| activate | `` | `void` | `obj:activate()` |
| deactivate | `` | `void` | `obj:deactivate()` |
| isFemale | `` | `boolean` | `obj:isFemale()` |
| setGender | `_female: boolean` | `void` | `obj:setGender(_female)` |
| getRace | `` | `GameData` | `obj:getRace()` |
| attachEffect | `data: GameData, boneName: string, offsetPosition: Vector3, offsetOrientation: Quaternion, manual: boolean, baseEmission: number` | `lightuserdata` | `obj:attachEffect(data, boneName, offsetPosition, offsetOrientation, manual, baseEmission)` |
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
| getRandomVertex | `boneName: string, direction: MeshDataLookup::Dir` | `integer` | `obj:getRandomVertex(boneName, direction)` |
| notifyDirty | `` | `void` | `obj:notifyDirty()` |
| reload | `` | `void` | `obj:reload()` |
| serialise | `state: GameData` | `void` | `obj:serialise(state)` |
| updateAppearance | `` | `void` | `obj:updateAppearance()` |
| updatePortrait | `` | `void` | `obj:updatePortrait()` |
| updateMovementScale | `` | `void` | `obj:updateMovementScale()` |
| switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| hasLights | `` | `boolean` | `obj:hasLights()` |
| attachItem_Hair | `data: GameData, slot: string` | `boolean` | `obj:attachItem_Hair(data, slot)` |
| shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isShaved | `` | `boolean` | `obj:isShaved()` |
| setFlayed | `on: boolean` | `void` | `obj:setFlayed(on)` |
| isFlayed | `` | `boolean` | `obj:isFlayed()` |
| isBarefoot | `` | `boolean` | `obj:isBarefoot()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| getAttachmentsLoaded | `` | `boolean` | `obj:getAttachmentsLoaded()` |
| setAttachmentsVisible | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| createBody | `` | `void` | `obj:createBody()` |
| buildAttachments | `` | `void` | `obj:buildAttachments()` |
| setHairTexture | `name: string, channel: integer, alpha: integer, colour: Vector3, beard: boolean` | `void` | `obj:setHairTexture(name, channel, alpha, colour, beard)` |
| createAttachedObject | `item: Item` | `lightuserdata` | `obj:createAttachedObject(item)` |
| updateOverlap | `` | `void` | `obj:updateOverlap()` |
| updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| getCharacterHeightSpeedMultiplier | `` | `number` | `obj:getCharacterHeightSpeedMultiplier()` |
| attachItem [1] | `item: Item, mesh: string, slot: string` | `boolean` | `obj:attachItem(item, mesh, slot)` |
| attachItem [2] | `item: Item, slot: string` | `boolean` | `obj:attachItem(item, slot)` |
| detachItem [1] | `item: Item` | `boolean` | `obj:detachItem(item)` |
| detachItem [2] | `slot: string` | `boolean` | `obj:detachItem(slot)` |
| getVertexPosition | `index: integer` | `Vector3` | `obj:getVertexPosition(index)` |
| getRandomVertexPosition | `boneName: string, direction: MeshDataLookup::Dir` | `Vector3` | `obj:getRandomVertexPosition(boneName, direction)` |
| chooseBodyMesh | `` | `void` | `obj:chooseBodyMesh()` |

## AppearanceHuman
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`
**Metatable:** `KenshiLua.AppearanceHuman`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| robotLegScale | `number` | RW | `obj.robotLegScale = <value>` |
| lastPhysiqueStats | `Vector3` | RW | `obj.lastPhysiqueStats = <value>` |
| bulkMult | `number` | RW | `obj.bulkMult = <value>` |
| muscleMult | `number` | RW | `obj.muscleMult = <value>` |
| skinnyMult | `number` | RW | `obj.skinnyMult = <value>` |
| flayed | `boolean` | RW | `obj.flayed = <value>` |
| beard | `GameData` | RW | `obj.beard = <value>` |
| hiddenPartsEnabled | `boolean` | RW | `obj.hiddenPartsEnabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setGender | `female: boolean` | `void` | `obj:setGender(female)` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| setAttachmentsVisible | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| setHiddenPartsEnabled | `enabled: boolean` | `void` | `obj:setHiddenPartsEnabled(enabled)` |
| showFace | `show: boolean` | `void` | `obj:showFace(show)` |
| setFlayed | `f: boolean` | `void` | `obj:setFlayed(f)` |
| isFlayed | `` | `boolean` | `obj:isFlayed()` |
| updateProportions | `` | `void` | `obj:updateProportions()` |
| createBody | `` | `void` | `obj:createBody()` |
| updateAppearance | `` | `void` | `obj:updateAppearance()` |
| updateHiddenParts | `` | `void` | `obj:updateHiddenParts()` |
| updatePysiqueFromStats | `` | `void` | `obj:updatePysiqueFromStats()` |
| updatePhysiqueMuscleMults | `` | `void` | `obj:updatePhysiqueMuscleMults()` |
| updateCharaterTexture | `` | `void` | `obj:updateCharaterTexture()` |
| setPosture | `posture: number, neck: number, shoulders: number` | `void` | `obj:setPosture(posture, neck, shoulders)` |

## AppearanceManager
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Metatable:** `KenshiLua.AppearanceManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| races | `Ogre::FastArray<GameData*>` | RW | `obj.races = <value>` |
| characterIdleAnimations | `Ogre::FastArray<AnimationData*>` | RW | `obj.characterIdleAnimations = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createAppearanceData | `race: GameData` | `GameDataCopyStandalone` | `obj:createAppearanceData(race)` |
| cleanValidateAppearanceData | `appearanceData: GameData` | `void` | `obj:cleanValidateAppearanceData(appearanceData)` |
| resetAll | `appearanceData: GameData, clearAttachments: boolean` | `void` | `obj:resetAll(appearanceData, clearAttachments)` |
| randomiseAll | `appearanceData: GameData` | `void` | `obj:randomiseAll(appearanceData)` |
| randomiseAllManual | `appearanceData: GameData, faceRandomnessMult: number, bodyRandomnessMult: number` | `void` | `obj:randomiseAllManual(appearanceData, faceRandomnessMult, bodyRandomnessMult)` |
| randomHair | `appearanceData: GameData, faction: Faction` | `void` | `obj:randomHair(appearanceData, faction)` |
| randomFace | `appearanceData: GameData` | `void` | `obj:randomFace(appearanceData)` |
| randomFaceManual | `appearanceData: GameData, randomnessMult: number` | `void` | `obj:randomFaceManual(appearanceData, randomnessMult)` |
| randomPoses | `appearanceData: GameData, deviation: number` | `void` | `obj:randomPoses(appearanceData, deviation)` |
| randomBody | `appearanceData: GameData, isPlayer: boolean` | `void` | `obj:randomBody(appearanceData, isPlayer)` |
| randomBodyManual | `appearanceData: GameData, randomnessMult: number` | `void` | `obj:randomBodyManual(appearanceData, randomnessMult)` |
| randomGender | `appearanceData: GameData, femaleChance: number` | `void` | `obj:randomGender(appearanceData, femaleChance)` |
| randomAnimations | `appearanceData: GameData, character: Character` | `void` | `obj:randomAnimations(appearanceData, character)` |
| getRaceData | `index: integer` | `GameData` | `obj:getRaceData(index)` |
| getRaceIndex | `data: GameData` | `integer` | `obj:getRaceIndex(data)` |
| getRacesCount | `` | `integer` | `obj:getRacesCount()` |
| isSingleGender | `raceData: GameData` | `boolean` | `obj:isSingleGender(raceData)` |
| setGender | `appearanceData: GameData, genderValue: integer` | `void` | `obj:setGender(appearanceData, genderValue)` |
| setHead | `appearanceData: GameData, headData: GameData` | `void` | `obj:setHead(appearanceData, headData)` |
| getHeadName | `appearanceData: GameData, appearance: AppearanceManager::AppearanceData` | `void` | `obj:getHeadName(appearanceData, appearance)` |
| setRandomHead | `raceData: GameData, appearanceData: GameData` | `void` | `obj:setRandomHead(raceData, appearanceData)` |
| getHeadIsValid | `raceData: GameData, appearanceData: GameData, headData: GameData` | `boolean` | `obj:getHeadIsValid(raceData, appearanceData, headData)` |
| setAttachment | `appearanceData: GameData, appearance: AppearanceManager::AppearanceData, slot: AttachSlot, index: integer` | `void` | `obj:setAttachment(appearanceData, appearance, slot, index)` |
| getAttachmentName | `appearanceData: GameData, appearance: AppearanceManager::AppearanceData, slot: AttachSlot` | `void` | `obj:getAttachmentName(appearanceData, appearance, slot)` |
| updateModifiers | `appearanceData: GameData, raceData: GameData` | `void` | `obj:updateModifiers(appearanceData, raceData)` |
| getNormalMap_Plain | `race: GameData` | `void` | `obj:getNormalMap_Plain(race)` |
| getNormalMap_Muscle | `race: GameData` | `void` | `obj:getNormalMap_Muscle(race)` |
| getNormalMap_Starving | `race: GameData` | `void` | `obj:getNormalMap_Starving(race)` |
| getCharacterIdleAnimations | `` | `AnimationDataFastArrayBinding::ArrayType` | `obj:getCharacterIdleAnimations()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getInstance | `` | `AppearanceManager` | `AppearanceManager.getInstance()`<br>`obj:getInstance()` |

## AppearanceManager::AppearanceData
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_AppearanceData`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `other: AppearanceManager::AppearanceData` | `void` | `obj:operator_assign(other)` |

## AppearanceManager::DataCategory
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataCategory`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setValue | `arg1: string` | `void` | `obj:setValue(arg1)` |
| getValue | `` | `integer` | `obj:getValue()` |
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## AppearanceManager::DataRange
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataRange`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clamp | `data: GameData` | `void` | `obj:clamp(data)` |
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## AppearanceManager::DataRangePose
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataRangePose`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clamp | `data: GameData` | `void` | `obj:clamp(data)` |
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## AppearanceManager::DataRangeVector
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataRangeVector`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addValue | `value: Vector3` | `void` | `obj:addValue(value)` |
| getValue | `valueIndex: integer` | `Vector3` | `obj:getValue(valueIndex)` |
| getValueIndex | `value: Vector3` | `integer` | `obj:getValueIndex(value)` |
| size | `` | `integer` | `obj:size()` |
| clamp | `data: GameData` | `void` | `obj:clamp(data)` |
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## AppearanceManager::Gender
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_Gender`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isMale | `` | `boolean` | `obj:isMale()` |
| isFemale | `` | `boolean` | `obj:isFemale()` |
| toString | `` | `void` | `obj:toString()` |
| getValue | `` | `integer` | `obj:getValue()` |

## Armour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Armour`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cutResistance | `number` | RW | `obj.cutResistance = <value>` |
| bluntResistance | `number` | RW | `obj.bluntResistance = <value>` |
| pierceResistance | `number` | RW | `obj.pierceResistance = <value>` |
| minCutResistance | `number` | RW | `obj.minCutResistance = <value>` |
| cutToStun | `number` | RW | `obj.cutToStun = <value>` |
| materialType | `ArmourType` | RW | `obj.materialType = <value>` |
| athleticsMult | `number` | RW | `obj.athleticsMult = <value>` |
| combatSkillBonusAttk | `integer` | RW | `obj.combatSkillBonusAttk = <value>` |
| combatSkillBonusDef | `integer` | RW | `obj.combatSkillBonusDef = <value>` |
| perceptionBonus | `integer` | RW | `obj.perceptionBonus = <value>` |
| combatSpeedMult | `number` | RW | `obj.combatSpeedMult = <value>` |
| stealthMult | `number` | RW | `obj.stealthMult = <value>` |
| assassinMult | `number` | RW | `obj.assassinMult = <value>` |
| dexterityMult | `number` | RW | `obj.dexterityMult = <value>` |
| damageMult | `number` | RW | `obj.damageMult = <value>` |
| dodgeMult | `number` | RW | `obj.dodgeMult = <value>` |
| unarmedBonus | `integer` | RW | `obj.unarmedBonus = <value>` |
| fistInjuryMult | `number` | RW | `obj.fistInjuryMult = <value>` |
| weatherProtectionAmount | `number` | RW | `obj.weatherProtectionAmount = <value>` |
| rangedSkillMult | `number` | RW | `obj.rangedSkillMult = <value>` |
| craftTime | `number` | RW | `obj.craftTime = <value>` |
| armourClassEnum | `ArmourClass` | RW | `obj.armourClassEnum = <value>` |
| bodypartCoverage | `ogre_unordered_map<GameData*, float>::type` | RW | `obj.bodypartCoverage = <value>` |
| stigma | `CharacterTypeEnum` | RW | `obj.stigma = <value>` |
| weatherProtections | `integer` | RW | `obj.weatherProtections = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getClassType | `` | `integer` | `obj:getClassType()` |
| isArmour | `` | `Armour` | `obj:isArmour()` |
| getItemWeight | `` | `number` | `obj:getItemWeight()` |
| getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| didIHitFlesh | `bodypart: GameData` | `boolean` | `obj:didIHitFlesh(bodypart)` |
| hasArmourCoverage | `` | `boolean` | `obj:hasArmourCoverage()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| getWeatherProtection_simple | `weather: WeatherAffecting` | `number` | `obj:getWeatherProtection_simple(weather)` |
| getArmourCraftingMaterialConsumptionRate | `` | `number` | `obj:getArmourCraftingMaterialConsumptionRate()` |
| getTooltipData1 | `` | `void` | `obj:getTooltipData1()` |
| getTooltipData2 | `` | `void` | `obj:getTooltipData2()` |

## Array2d
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`
**Metatable:** `KenshiLua.Array2d`

## BackpackInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.BackpackInventoryLayout`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |

## BackThreadMessagesToMainT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.BackThreadMessagesToMainT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| swapMutex | `unknown` | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| flush | `` | `boolean` | `obj:flush()` |

## BadSize
**Header:** `extern/KenshiLib/Include/kenshi/util/Array2d.h`
**Metatable:** `KenshiLua.BadSize`

## BoundsViolation
**Header:** `extern/KenshiLib/Include/kenshi/util/Array2d.h`
**Metatable:** `KenshiLua.BoundsViolation`

## Bounty
**Header:** `extern/KenshiLib/Include/kenshi/Bounty.h`
**Metatable:** `KenshiLua.Bounty`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| amount | `integer` | RW | `obj.amount = <value>` |
| crimes | `integer (CrimeEnum bitmask)` | RW | `obj.crimes = <value>` |
| bountyHasBeenClaimedOnce | `boolean` | RW | `obj.bountyHasBeenClaimedOnce = <value>` |
| bountyAssignmentStartedTime | `TimeOfDay` | RW | `obj.bountyAssignmentStartedTime = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addCrime | `crime: CrimeEnum` | `void` | `obj:addCrime(crime)` |
| hasCrime | `crime: CrimeEnum` | `boolean` | `obj:hasCrime(crime)` |

## BountyManager
**Header:** `extern/KenshiLib/Include/kenshi/BountyManager.h`
**Metatable:** `KenshiLua.BountyManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bounties | `ogre_unordered_map<Faction*, Bounty>` | RW | `obj.bounties = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| _hasAccessPass | `Faction` | RW | `obj._hasAccessPass = <value>` |
| accessPassExpirationTime | `TimeOfDay` | RW | `obj.accessPassExpirationTime = <value>` |
| committingCrime | `CrimeEnum` | RW | `obj.committingCrime = <value>` |
| crimeAgainstFaction | `Faction` | RW | `obj.crimeAgainstFaction = <value>` |
| usingTrainingEquipmentOf | `Faction` | RW | `obj.usingTrainingEquipmentOf = <value>` |
| crimeAgainst | `hand` | RW | `obj.crimeAgainst = <value>` |
| crimeExpiry | `number` | RW | `obj.crimeExpiry = <value>` |
| prisonSentenceBeganTime | `TimeOfDay` | RW | `obj.prisonSentenceBeganTime = <value>` |
| prisonSentenceToServe | `number` | RW | `obj.prisonSentenceToServe = <value>` |
| _hadABountyAssignedForCurrentCrime | `boolean` | RW | `obj._hadABountyAssignedForCurrentCrime = <value>` |

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
| _getBountyFaction | `f: Faction` | `Faction` | `obj:_getBountyFaction(f)` |
| getPercievedBounty | `whosLooking: Character` | `integer` | `obj:getPercievedBounty(whosLooking)` |
| getActualBounty | `whosLooking: Faction` | `integer` | `obj:getActualBounty(whosLooking)` |
| notifyPlayerClaimBounty | `whosLooking: Faction` | `void` | `obj:notifyPlayerClaimBounty(whosLooking)` |
| bountyAlreadyBeenClaimedByPlayer | `whosLooking: Faction` | `boolean` | `obj:bountyAlreadyBeenClaimedByPlayer(whosLooking)` |
| assignBountyForCrimes | `enforcer: Faction` | `void` | `obj:assignBountyForCrimes(enforcer)` |
| unfairAddToBounty | `enforcer: Faction, amount: integer` | `void` | `obj:unfairAddToBounty(enforcer, amount)` |
| clearBounty | `enforcer: Faction` | `void` | `obj:clearBounty(enforcer)` |
| load | `state: GameData` | `void` | `obj:load(state)` |
| save | `state: GameData` | `void` | `obj:save(state)` |
| setCrime | `crime: CrimeEnum, against: Faction, agnst: hand` | `boolean` | `obj:setCrime(crime, against, agnst)` |
| notifyCrimeWitnessed | `against: Faction, againstWho: hand, expirytime: integer, what: CrimeEnum` | `void` | `obj:notifyCrimeWitnessed(against, againstWho, expirytime, what)` |
| notifyStartPrisonSentence | `law: Faction` | `void` | `obj:notifyStartPrisonSentence(law)` |
| hasAccessPass | `forFac: Faction` | `boolean` | `obj:hasAccessPass(forFac)` |
| giveAccessPass | `who: Faction, minutes: number` | `void` | `obj:giveAccessPass(who, minutes)` |
| crimeToStr | `c: CrimeEnum` | `string` | `obj:crimeToStr(c)` |
| getBountyForCrime | `c: CrimeEnum` | `integer` | `obj:getBountyForCrime(c)` |
| getPrisonSentenceInHours | `` | `integer` | `obj:getPrisonSentenceInHours()` |
| getBountyExpirationTime | `` | `number` | `obj:getBountyExpirationTime()` |

## Building
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Metatable:** `KenshiLua.Building`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isFoliage | `boolean` | RW | `obj.isFoliage = <value>` |
| hasTerrainInside | `boolean` | RW | `obj.hasTerrainInside = <value>` |
| isCavernous | `boolean` | RW | `obj.isCavernous = <value>` |
| enforceCeiling | `boolean` | RW | `obj.enforceCeiling = <value>` |
| designation | `BuildingDesignation` | RW | `obj.designation = <value>` |
| publicDaytime | `boolean` | RW | `obj.publicDaytime = <value>` |
| residentSquad | `hand` | RW | `obj.residentSquad = <value>` |
| residentSquadTemplate | `GameData` | RW | `obj.residentSquadTemplate = <value>` |
| isAnInteriorObject | `boolean` | RW | `obj.isAnInteriorObject = <value>` |
| instanceID | `InstanceID` | RW | `obj.instanceID = <value>` |
| layoutInstanceID | `string` | RW | `obj.layoutInstanceID = <value>` |
| specialFunction | `BuildingFunction` | RW | `obj.specialFunction = <value>` |
| _buildState | `Building::ConstructionState` | RW | `obj._buildState = <value>` |
| classType | `BuildingClassType` | RW | `obj.classType = <value>` |
| updateNavmesh | `boolean` | RW | `obj.updateNavmesh = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| interiorVisibility | `boolean` | RW | `obj.interiorVisibility = <value>` |
| justBeenUpgradedFlag | `boolean` | RW | `obj.justBeenUpgradedFlag = <value>` |
| imADoor | `boolean` | RW | `obj.imADoor = <value>` |
| destroyed | `boolean` | RW | `obj.destroyed = <value>` |
| productionMult | `number` | RW | `obj.productionMult = <value>` |
| productionMult_baseData | `number` | RW | `obj.productionMult_baseData = <value>` |
| hasMovingParts | `boolean` | RW | `obj.hasMovingParts = <value>` |
| saveVersion | `integer` | RW | `obj.saveVersion = <value>` |
| _town | `hand` | RW | `obj._town = <value>` |
| myInterior | `lightuserdata` | R | `obj.myInterior` |
| buildingsManager | `TownBuildingsManager` | RW | `obj.buildingsManager = <value>` |
| rootNode | `lightuserdata` | R | `obj.rootNode` |
| soundEmitter | `lightuserdata` | R | `obj.soundEmitter` |
| hasAudio | `boolean` | RW | `obj.hasAudio = <value>` |
| interiorGround | `GroundType` | RW | `obj.interiorGround = <value>` |
| exteriorGround | `GroundType` | RW | `obj.exteriorGround = <value>` |
| physical | `PhysicsCollection` | RW | `obj.physical = <value>` |
| entitiesToLoad | `integer` | RW | `obj.entitiesToLoad = <value>` |
| entitiesLoaded | `boolean` | RW | `obj.entitiesLoaded = <value>` |
| isFurnitureOf | `lightuserdata` | R | `obj.isFurnitureOf` |
| isOutsideFurniture | `boolean` | RW | `obj.isOutsideFurniture = <value>` |
| isNestItem | `boolean` | RW | `obj.isNestItem = <value>` |
| baseMaterial | `GameData` | RW | `obj.baseMaterial = <value>` |
| effectsVisible | `boolean` | RW | `obj.effectsVisible = <value>` |
| effectsActive | `boolean` | RW | `obj.effectsActive = <value>` |
| lightsVisible | `boolean` | RW | `obj.lightsVisible = <value>` |
| positionMarker | `Vector3` | RW | `obj.positionMarker = <value>` |
| heightAboveGround | `number` | RW | `obj.heightAboveGround = <value>` |
| isRedDebugTextureMode | `boolean` | RW | `obj.isRedDebugTextureMode = <value>` |
| materialName | `string` | RW | `obj.materialName = <value>` |
| triggerVolume | `lightuserdata` | R | `obj.triggerVolume` |
| doors | `lektor<Building*>` | RW | `obj.doors = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getScale | `` | `number` | `obj:getScale()` |
| getBuildState | `` | `Building::ConstructionState` | `obj:getBuildState()` |
| getBuildState_ActualNonShared | `` | `Building::ConstructionState` | `obj:getBuildState_ActualNonShared()` |
| getMountedBuildings | `` | `integer` | `obj:getMountedBuildings()` |
| findAllFurnitureWithFunction | `func: BuildingFunction` | `void` | `obj:findAllFurnitureWithFunction(func)` |
| select | `` | `void` | `obj:select()` |
| getBuildingDesignation | `` | `BuildingDesignation` | `obj:getBuildingDesignation()` |
| addConstructionProgress | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| setConstructionProgress | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| addDismantleProgress | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| notifyConstructionDismantling | `` | `void` | `obj:notifyConstructionDismantling()` |
| dropMats | `` | `void` | `obj:dropMats()` |
| upgrade | `_a1: DataPanelLine` | `void` | `obj:upgrade(_a1)` |
| downgrade | `_a1: DataPanelLine` | `void` | `obj:downgrade(_a1)` |
| canUpgrade | `` | `GameData` | `obj:canUpgrade()` |
| canDowngrade | `` | `GameData` | `obj:canDowngrade()` |
| canDismantle | `` | `boolean` | `obj:canDismantle()` |
| buyMeAsk | `_a1: DataPanelLine` | `void` | `obj:buyMeAsk(_a1)` |
| buyMeCallback | `result: integer` | `void` | `obj:buyMeCallback(result)` |
| calculateSaleValue | `` | `integer` | `obj:calculateSaleValue()` |
| loadNodes | `` | `void` | `obj:loadNodes()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| togglePublic | `_a1: DataPanelLine` | `void` | `obj:togglePublic(_a1)` |
| dismantleButton | `_a1: DataPanelLine` | `void` | `obj:dismantleButton(_a1)` |
| pauseButton | `_a1: DataPanelLine` | `void` | `obj:pauseButton(_a1)` |
| confirmDismantle | `r: integer` | `void` | `obj:confirmDismantle(r)` |
| isAShop | `` | `boolean` | `obj:isAShop()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| isAWall | `` | `WallBuilding` | `obj:isAWall()` |
| isAWallRamp | `` | `boolean` | `obj:isAWallRamp()` |
| hasInterior | `` | `boolean` | `obj:hasInterior()` |
| affectsNavmesh | `` | `boolean` | `obj:affectsNavmesh()` |
| setResidentSquad | `who: Platoon` | `void` | `obj:setResidentSquad(who)` |
| getResidentSquadLeader | `` | `Character` | `obj:getResidentSquadLeader()` |
| setDesignation | `d: BuildingDesignation` | `void` | `obj:setDesignation(d)` |
| getWallEndPosition | `` | `Vector3` | `obj:getWallEndPosition()` |
| setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| getMiningResourceLevel | `` | `number` | `obj:getMiningResourceLevel()` |
| addAnInternalBuilding | `b: Building` | `void` | `obj:addAnInternalBuilding(b)` |
| getNumInternalBuildings | `` | `integer` | `obj:getNumInternalBuildings()` |
| moveMountedBuildings | `` | `void` | `obj:moveMountedBuildings()` |
| reCheckInsideOutsideFortificationStatus | `` | `void` | `obj:reCheckInsideOutsideFortificationStatus()` |
| setInsideTownWalls | `code: integer` | `void` | `obj:setInsideTownWalls(code)` |
| postCreationPathfinderSetupStuff | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| getSpecialFunction | `` | `BuildingFunction` | `obj:getSpecialFunction()` |
| getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| setBroken | `_a1: boolean` | `void` | `obj:setBroken(_a1)` |
| switchPowerOn | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| isPowerOn | `` | `boolean` | `obj:isPowerOn()` |
| isDamaged | `` | `boolean` | `obj:isDamaged()` |
| isDestroyed | `` | `boolean` | `obj:isDestroyed()` |
| isSign | `` | `boolean` | `obj:isSign()` |
| setDestroyed | `d: boolean` | `void` | `obj:setDestroyed(d)` |
| canBeDestroyed | `` | `boolean` | `obj:canBeDestroyed()` |
| setNestTag | `` | `void` | `obj:setNestTag()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| hasShopCountersSelling | `type: ItemFunction` | `boolean` | `obj:hasShopCountersSelling(type)` |
| getBuildingClass | `` | `BuildingClassType` | `obj:getBuildingClass()` |
| needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| notifyChange | `` | `void` | `obj:notifyChange()` |
| getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| setToDefaultFactionDivision | `` | `void` | `obj:setToDefaultFactionDivision()` |
| getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| getSoundIntensity | `` | `number` | `obj:getSoundIntensity()` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| _saveBuildingState | `state: GameData, doorID: string` | `void` | `obj:_saveBuildingState(state, doorID)` |
| _loadBuildingState | `state: GameData, doorID: string` | `void` | `obj:_loadBuildingState(state, doorID)` |
| getGUIName | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIName(datapanel, category)` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |
| getGUICondition | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUICondition(datapanel, category)` |
| getGUIUpgrade | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIUpgrade(datapanel, category)` |
| getGUIDestroyButton | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIDestroyButton(datapanel, category)` |
| getProductionBuilding | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| getProductionMult | `` | `number` | `obj:getProductionMult()` |
| isThePlayer | `` | `boolean` | `obj:isThePlayer()` |
| doorStuff | `` | `DoorStuff` | `obj:doorStuff()` |
| doorParentBuilding | `` | `Building` | `obj:doorParentBuilding()` |
| isDoor | `` | `boolean` | `obj:isDoor()` |
| isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| getDoor | `` | `DoorStuff` | `obj:getDoor()` |
| getParentLayout | `` | `lightuserdata` | `obj:getParentLayout()` |
| isFurniture | `` | `boolean` | `obj:isFurniture()` |
| isFurnitureOrDoor | `` | `boolean` | `obj:isFurnitureOrDoor()` |
| getIsOutsideFurniture | `` | `boolean` | `obj:getIsOutsideFurniture()` |
| setIsOutsideFurniture | `value: boolean` | `void` | `obj:setIsOutsideFurniture(value)` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| furnitureParentBuilding | `` | `Building` | `obj:furnitureParentBuilding()` |
| hasAnOpenDoor | `` | `boolean` | `obj:hasAnOpenDoor()` |
| allowAnimals | `` | `boolean` | `obj:allowAnimals()` |
| update | `` | `void` | `obj:update()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| checkLoadedProperly | `` | `void` | `obj:checkLoadedProperly()` |
| loadFromSerialise | `savestate: GameSaveState` | `void` | `obj:loadFromSerialise(savestate)` |
| loadFromSerialise_TheDoors | `savestate: GameSaveState` | `void` | `obj:loadFromSerialise_TheDoors(savestate)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| getMouseCursor | `` | `CursorType` | `obj:getMouseCursor()` |
| getDefaultTask | `` | `TaskType` | `obj:getDefaultTask()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| _changeTown | `t: Town` | `void` | `obj:_changeTown(t)` |
| getTownHandle | `` | `hand` | `obj:getTownHandle()` |
| getTown | `` | `TownBase` | `obj:getTown()` |
| getRealTown | `` | `Town` | `obj:getRealTown()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| destroyDoors | `` | `void` | `obj:destroyDoors()` |
| createTriggerHull | `` | `void` | `obj:createTriggerHull()` |
| destroyAudioObject | `` | `void` | `obj:destroyAudioObject()` |
| getAudioObject | `` | `integer` | `obj:getAudioObject()` |
| getGroundType | `inside: boolean` | `GroundType` | `obj:getGroundType(inside)` |
| isCeilingMounted | `` | `boolean` | `obj:isCeilingMounted()` |
| setFloorVisibility | `floor: integer, vis: boolean` | `void` | `obj:setFloorVisibility(floor, vis)` |
| getNumFloors | `` | `integer` | `obj:getNumFloors()` |
| buildingComplete_RestoreMaterial | `` | `void` | `obj:buildingComplete_RestoreMaterial()` |
| loadInteriorPhysical | `on: boolean` | `void` | `obj:loadInteriorPhysical(on)` |
| loadInteriorGraphics | `on: boolean` | `void` | `obj:loadInteriorGraphics(on)` |
| setFaction | `p: Faction, a: ActivePlatoon` | `void` | `obj:setFaction(p, a)` |
| calculateLeftPost | `` | `Vector3` | `obj:calculateLeftPost()` |
| setupLevelData | `f: Faction, squad: GameData, interior: string, exterior: string` | `void` | `obj:setupLevelData(f, squad, interior, exterior)` |
| getLinkLength | `` | `number` | `obj:getLinkLength()` |
| getRootNode | `` | `lightuserdata` | `obj:getRootNode()` |
| getZoneMapLocation | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| clearTownBuildingsManagerPtr | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| setup [1] | `buildingdata: GameData` | `void` | `obj:setup(buildingdata)` |
| setup [2] | `` | `void` | `obj:setup()` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| getMouseCursor | `` | `CursorType` | `obj:getMouseCursor()` |
| getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| getDirectionMarkerQuat | `currentPosition: Vector3` | `Quaternion` | `obj:getDirectionMarkerQuat(currentPosition)` |
| isCreated | `` | `boolean` | `obj:isCreated()` |
| updateUsageNodes | `` | `void` | `obj:updateUsageNodes()` |
| forceValidUsageNodesValidation | `` | `void` | `obj:forceValidUsageNodesValidation()` |
| addUsageNode | `nodeId: string` | `void` | `obj:addUsageNode(nodeId)` |
| removeUsageNode | `nodeId: string` | `void` | `obj:removeUsageNode(nodeId)` |
| clearUsageNodes | `` | `void` | `obj:clearUsageNodes()` |
| notifyEffect | `type: EffectType::Enum, what: WeatherAffecting, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| updatePhysicalWithProgress | `` | `void` | `obj:updatePhysicalWithProgress()` |
| recalculateWorldAABB | `` | `void` | `obj:recalculateWorldAABB()` |
| selectPartMaterial | `partData: GameData` | `GameData` | `obj:selectPartMaterial(partData)` |
| getSeed | `` | `integer` | `obj:getSeed()` |
| onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| updateBadNodes | `` | `void` | `obj:updateBadNodes()` |
| isIndoors | `` | `hand` | `obj:isIndoors()` |
| isIndoors_notDestroyed | `` | `hand` | `obj:isIndoors_notDestroyed()` |
| getMountedBuilding | `` | `hand` | `obj:getMountedBuilding()` |
| removeAnInternalBuilding | `b: hand` | `void` | `obj:removeAnInternalBuilding(b)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| getLayoutInstanceID | `` | `string` | `obj:getLayoutInstanceID()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getEntityMaterialName | `` | `string` | `Building.getEntityMaterialName()`<br>`obj:getEntityMaterialName()` |

## Building::ConstructionState
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Parent Class:** [`Building`](#building)
**Metatable:** `KenshiLua.ConstructionState`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isComplete | `boolean` | RW | `obj.isComplete = <value>` |
| isPaused | `boolean` | RW | `obj.isPaused = <value>` |
| isDismantled | `boolean` | RW | `obj.isDismantled = <value>` |
| constructionProgress | `number` | RW | `obj.constructionProgress = <value>` |
| msgDismantleAmount | `number` | RW | `obj.msgDismantleAmount = <value>` |
| mats | `lektor<Building::ConstructionState::BuildMaterial*>` | RW | `obj.mats = <value>` |
| totalMats | `number` | RW | `obj.totalMats = <value>` |
| buildTimeMult | `number` | RW | `obj.buildTimeMult = <value>` |
| buildersThisFrame | `integer` | RW | `obj.buildersThisFrame = <value>` |
| pathThreshold | `number` | RW | `obj.pathThreshold = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addMaterials | `mat: GameData` | `void` | `obj:addMaterials(mat)` |
| materialsEmpty | `` | `boolean` | `obj:materialsEmpty()` |
| isOverThreshold | `` | `boolean` | `obj:isOverThreshold()` |
| getHealthBarProgress | `` | `number` | `obj:getHealthBarProgress()` |
| getConstructionMaterialProgress | `` | `number` | `obj:getConstructionMaterialProgress()` |
| getHealthBarActual | `` | `string` | `obj:getHealthBarActual()` |
| getMaterial | `d: GameData` | `ConstructionState::BuildMaterial` | `obj:getMaterial(d)` |
| setup | `buildingdata: GameData` | `void` | `obj:setup(buildingdata)` |
| getTotalMats | `` | `number` | `obj:getTotalMats()` |
| getTotalMatsPresent | `` | `number` | `obj:getTotalMatsPresent()` |
| getNeededMats | `` | `void` | `obj:getNeededMats()` |
| needsMat | `what: GameData` | `integer` | `obj:needsMat(what)` |
| needMats | `` | `boolean` | `obj:needMats()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getBuildingSpeedMultiplier | `` | `number` | `Building::ConstructionState.getBuildingSpeedMultiplier()`<br>`obj:getBuildingSpeedMultiplier()` |
| getBuildingTimeInHours | `` | `number` | `Building::ConstructionState.getBuildingTimeInHours()`<br>`obj:getBuildingTimeInHours()` |
| getBuildingSpeedMultiplier | `` | `number` | `Building::ConstructionState.getBuildingSpeedMultiplier()`<br>`obj:getBuildingSpeedMultiplier()` |
| getBuildingTimeInHours | `` | `number` | `Building::ConstructionState.getBuildingTimeInHours()`<br>`obj:getBuildingTimeInHours()` |

## Building::ConstructionState::BuildMaterial
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Parent Class:** [`Building`](#building)
**Metatable:** `KenshiLua.BuildMaterial`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mat | `GameData` | RW | `obj.mat = <value>` |
| buildMatsTotal | `number` | RW | `obj.buildMatsTotal = <value>` |
| amountOfMaterials | `number` | RW | `obj.amountOfMaterials = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getMaterialsBarProgress | `` | `number` | `obj:getMaterialsBarProgress()` |
| getNumRemaining | `` | `number` | `obj:getNumRemaining()` |

## BuildingContainerInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`
**Metatable:** `KenshiLua.BuildingContainerInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| capacityText | `MyGUI::Widget` | RW | `obj.capacityText = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setCapacity | `value: integer, full: boolean` | `void` | `obj:setCapacity(value, full)` |
| setupSections | `inventoryGUI: InventoryGUI, sections: SectionsMap, inventory: Inventory` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |

## BuildingPlacementGroundType
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Metatable:** `KenshiLua.BuildingPlacementGroundType`

## BuildInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`
**Metatable:** `KenshiLua.BuildInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| input1NameText | `MyGUI::TextBox` | RW | `obj.input1NameText = <value>` |
| input2NameText | `MyGUI::TextBox` | RW | `obj.input2NameText = <value>` |
| input1StatusText | `MyGUI::TextBox` | RW | `obj.input1StatusText = <value>` |
| input2StatusText | `MyGUI::TextBox` | RW | `obj.input2StatusText = <value>` |
| input1ItemIcon | `MyGUI::ImageBox` | RW | `obj.input1ItemIcon = <value>` |
| input2ItemIcon | `MyGUI::ImageBox` | RW | `obj.input2ItemIcon = <value>` |
| outputNameText | `MyGUI::TextBox` | RW | `obj.outputNameText = <value>` |
| outputItemIcon | `MyGUI::ImageBox` | RW | `obj.outputItemIcon = <value>` |
| input1Panel | `MyGUI::Widget` | RW | `obj.input1Panel = <value>` |
| input2Panel | `MyGUI::Widget` | RW | `obj.input2Panel = <value>` |
| input1Progress | `MyGUI::ProgressBar` | RW | `obj.input1Progress = <value>` |
| input2Progress | `MyGUI::ProgressBar` | RW | `obj.input2Progress = <value>` |
| outputProgress | `MyGUI::ProgressBar` | RW | `obj.outputProgress = <value>` |
| inputs | `integer` | RW | `obj.inputs = <value>` |
| outputs | `integer` | RW | `obj.outputs = <value>` |
| input1Item | `Item` | RW | `obj.input1Item = <value>` |
| input2Item | `Item` | RW | `obj.input2Item = <value>` |
| outputItem | `Item` | RW | `obj.outputItem = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `inventoryGUI: InventoryGUI, sections: SectionsMap, inventory: Inventory` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |
| setInput | `inputIndex: integer, name: string, status: string` | `void` | `obj:setInput(inputIndex, name, status)` |
| setOutput | `name: string` | `void` | `obj:setOutput(name)` |
| setInputProgress | `inputIdx: integer, progress: number` | `void` | `obj:setInputProgress(inputIdx, progress)` |
| setInputEnabled | `inputIdx: integer, value: boolean` | `void` | `obj:setInputEnabled(inputIdx, value)` |
| setOutputProgress | `progress: number` | `void` | `obj:setOutputProgress(progress)` |
| setInputItem | `inputIdx: integer, item: Item, visible: boolean` | `void` | `obj:setInputItem(inputIdx, item, visible)` |
| setOutputItem | `item: Item, visible: boolean` | `void` | `obj:setOutputItem(item, visible)` |

## BuildModeWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`
**Metatable:** `KenshiLua.BuildModeWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| playerBuildMode | `lightuserdata` | R | `obj.playerBuildMode` |
| levelEditorMode | `boolean` | RW | `obj.levelEditorMode = <value>` |
| playerResearch | `lightuserdata` | R | `obj.playerResearch` |
| currentBuildingCategory | `BuildModeWindow::BuildingCategory` | RW | `obj.currentBuildingCategory = <value>` |
| currentBuildingGroup | `BuildModeWindow::BuildingGroup` | RW | `obj.currentBuildingGroup = <value>` |
| currentBuildingInfo | `GameData` | RW | `obj.currentBuildingInfo = <value>` |
| currentBuildingIndex | `integer` | RW | `obj.currentBuildingIndex = <value>` |
| switchBuildingIndex | `integer` | RW | `obj.switchBuildingIndex = <value>` |
| statsDataPanel | `DatapanelGUI` | RW | `obj.statsDataPanel = <value>` |
| confirmButton | `MyGUI::Widget` | RW | `obj.confirmButton = <value>` |
| undoButton | `MyGUI::Widget` | RW | `obj.undoButton = <value>` |
| closeButton | `MyGUI::Widget` | RW | `obj.closeButton = <value>` |
| categoriesList | `MyGUI::Widget` | RW | `obj.categoriesList = <value>` |
| buildingsList | `MyGUI::Widget` | RW | `obj.buildingsList = <value>` |
| buildingTxt | `MyGUI::Widget` | RW | `obj.buildingTxt = <value>` |
| buildingTypePrevButton | `MyGUI::Widget` | RW | `obj.buildingTypePrevButton = <value>` |
| buildingTypeNextButton | `MyGUI::Widget` | RW | `obj.buildingTypeNextButton = <value>` |
| buildingImageBox | `MyGUI::Widget` | RW | `obj.buildingImageBox = <value>` |
| statsPanel | `MyGUI::Widget` | RW | `obj.statsPanel = <value>` |
| descriptionTxt | `MyGUI::Widget` | RW | `obj.descriptionTxt = <value>` |
| messageTextBox | `MyGUI::Widget` | RW | `obj.messageTextBox = <value>` |
| floorDownButton | `MyGUI::Widget` | RW | `obj.floorDownButton = <value>` |
| floorUpButton | `MyGUI::Widget` | RW | `obj.floorUpButton = <value>` |
| floorText | `MyGUI::Widget` | RW | `obj.floorText = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setMessage | `message: string` | `void` | `obj:setMessage(message)` |
| getBuildingListWidget | `` | `MyGUI::Widget` | `obj:getBuildingListWidget()` |
| setVisible | `v: boolean` | `void` | `obj:setVisible(v)` |
| setupData | `` | `void` | `obj:setupData()` |
| listCategories | `` | `void` | `obj:listCategories()` |
| listBuildingGroups | `` | `void` | `obj:listBuildingGroups()` |
| updateBuildingUI | `` | `void` | `obj:updateBuildingUI()` |
| build | `` | `void` | `obj:build()` |
| showBuildingStats | `` | `void` | `obj:showBuildingStats()` |
| update | `` | `void` | `obj:update()` |
| changeCurrentIndex | `index: integer` | `void` | `obj:changeCurrentIndex(index)` |
| categorySelected | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:categorySelected(sender, index)` |
| buildingSelected | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:buildingSelected(sender, index)` |
| confirm | `sender: MyGUI::Widget` | `void` | `obj:confirm(sender)` |
| undo | `sender: MyGUI::Widget` | `void` | `obj:undo(sender)` |
| close | `sender: MyGUI::Widget` | `void` | `obj:close(sender)` |
| buildingTypePrev | `sender: MyGUI::Widget` | `void` | `obj:buildingTypePrev(sender)` |
| buildingTypeNext | `sender: MyGUI::Widget` | `void` | `obj:buildingTypeNext(sender)` |
| changeFloorButtonUp | `sender: MyGUI::Widget` | `void` | `obj:changeFloorButtonUp(sender)` |
| changeFloorButtonDown | `sender: MyGUI::Widget` | `void` | `obj:changeFloorButtonDown(sender)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| compareBuildMaterials | `` | `boolean` | `BuildModeWindow.compareBuildMaterials()`<br>`obj:compareBuildMaterials()` |

## BuildModeWindow::BuildingCategory
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`
**Parent Class:** [`BuildModeWindow`](#buildmodewindow)
**Metatable:** `KenshiLua.BuildingCategory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_lt | `b: BuildingCategory` | `boolean` | `obj:operator_lt(b)` |
| operator_assign | `other: BuildingCategory` | `void` | `obj:operator_assign(other)` |

## BuildModeWindow::BuildingGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`
**Parent Class:** [`BuildModeWindow`](#buildmodewindow)
**Metatable:** `KenshiLua.BuildingGroup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_lt | `b: BuildingGroup` | `boolean` | `obj:operator_lt(b)` |
| operator_assign | `other: BuildingGroup` | `void` | `obj:operator_assign(other)` |

## CameraClass
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`
**Metatable:** `KenshiLua.CameraClass`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isRotating | `boolean` | RW | `obj.isRotating = <value>` |
| rotationMarker | `lightuserdata` | R | `obj.rotationMarker` |
| yaw | `number` | RW | `obj.yaw = <value>` |
| pitch | `number` | RW | `obj.pitch = <value>` |
| initialised | `boolean` | RW | `obj.initialised = <value>` |
| terrainLoaded | `boolean` | RW | `obj.terrainLoaded = <value>` |
| objectCurrentlyFollowing | `hand` | RW | `obj.objectCurrentlyFollowing = <value>` |
| objectCurrentlyFollowingOffset | `Vector3` | RW | `obj.objectCurrentlyFollowingOffset = <value>` |
| center | `lightuserdata` | RW | `obj.center = <value>` |
| altitude | `number` | RW | `obj.altitude = <value>` |
| camera | `lightuserdata` | R | `obj.camera` |
| node | `lightuserdata` | R | `obj.node` |
| currentMusic | `integer` | RW | `obj.currentMusic = <value>` |
| inBuilding | `hand` | RW | `obj.inBuilding = <value>` |
| timeInGame | `number` | RW | `obj.timeInGame = <value>` |
| targetPositionY | `number` | RW | `obj.targetPositionY = <value>` |
| speedY | `number` | RW | `obj.speedY = <value>` |
| centerBuilding | `Building` | RW | `obj.centerBuilding = <value>` |
| centerBuildingY | `number` | RW | `obj.centerBuildingY = <value>` |
| currentCollisionGroup | `integer` | RW | `obj.currentCollisionGroup = <value>` |
| currentFloor | `integer` | RW | `obj.currentFloor = <value>` |
| freeCameraMode | `boolean` | RW | `obj.freeCameraMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| update | `controlEnabled: boolean` | `void` | `obj:update(controlEnabled)` |
| focusCameraOnObject | `object: RootObject, offset: Vector3, nearZoom: boolean` | `void` | `obj:focusCameraOnObject(object, offset, nearZoom)` |
| updateOptionSettings | `` | `void` | `obj:updateOptionSettings()` |
| save | `data: GameData` | `void` | `obj:save(data)` |
| load | `data: GameData` | `void` | `obj:load(data)` |
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
| followObject | `h: hand` | `void` | `obj:followObject(h)` |
| getFollowObject | `` | `hand` | `obj:getFollowObject()` |
| isVisible [1] | `pos: Vector3, radius: number` | `boolean` | `obj:isVisible(pos, radius)` |
| isVisible [2] | `pos: Vector3` | `boolean` | `obj:isVisible(pos)` |
| restrictPosition | `` | `void` | `obj:restrictPosition()` |

## CampaignTriggerData
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`
**Metatable:** `KenshiLua.CampaignTriggerData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| what | `GameData` | RW | `obj.what = <value>` |
| minTime | `integer` | RW | `obj.minTime = <value>` |
| maxTime | `integer` | RW | `obj.maxTime = <value>` |
| chance | `number` | RW | `obj.chance = <value>` |

## Character
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.Character`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| offscreenFrameTime | `number` | RW | `obj.offscreenFrameTime = <value>` |
| frameTIME | `number` | RW | `obj.frameTIME = <value>` |
| frameTIMEfour | `number` | RW | `obj.frameTIMEfour = <value>` |
| frameTIME_P | `number` | RW | `obj.frameTIME_P = <value>` |
| bodyDecayTimer | `number` | RW | `obj.bodyDecayTimer = <value>` |
| stealthMode | `boolean` | RW | `obj.stealthMode = <value>` |
| _isOnARoof | `boolean` | RW | `obj._isOnARoof = <value>` |
| _lightLevel | `number` | RW | `obj._lightLevel = <value>` |
| needsLightLevel | `boolean` | RW | `obj.needsLightLevel = <value>` |
| _currentProneState | `ProneState` | RW | `obj._currentProneState = <value>` |
| isVisibleUpdateMode | `boolean` | RW | `obj.isVisibleUpdateMode = <value>` |
| setVisibleMsg | `boolean` | RW | `obj.setVisibleMsg = <value>` |
| stealthUnseen | `YesNoMaybe` | RW | `obj.stealthUnseen = <value>` |
| playerWantsMeToGetUp | `boolean` | RW | `obj.playerWantsMeToGetUp = <value>` |
| crimes | `BountyManager` | RW | `obj.crimes = <value>` |
| currentSkillUsing | `StatsEnumerated` | RW | `obj.currentSkillUsing = <value>` |
| stateBroadcast | `lightuserdata` | RW | `obj.stateBroadcast = <value>` |
| isVisibleAndNear | `boolean` | RW | `obj.isVisibleAndNear = <value>` |
| isOnScreen | `boolean` | RW | `obj.isOnScreen = <value>` |
| stealthMarkerArrows | `Character::AttachedArrowManager` | R | `obj.stealthMarkerArrows` |
| _isEngagedWithAPlayer | `boolean` | RW | `obj._isEngagedWithAPlayer = <value>` |
| isUsingTurret | `hand` | RW | `obj.isUsingTurret = <value>` |
| isCurrentlyGettingUp | `boolean` | RW | `obj.isCurrentlyGettingUp = <value>` |
| isGettingEaten | `integer` | RW | `obj.isGettingEaten = <value>` |
| dialogue | `Dialogue` | RW | `obj.dialogue = <value>` |
| currentStumblePainAnimation | `string` | RW | `obj.currentStumblePainAnimation = <value>` |
| _isLiterallyUnderMeleeAttackRightNowForSure | `boolean` | RW | `obj._isLiterallyUnderMeleeAttackRightNowForSure = <value>` |
| _myMemory | `lightuserdata` | RW | `obj._myMemory = <value>` |
| lastGuyWhoDefeatedMe | `hand` | RW | `obj.lastGuyWhoDefeatedMe = <value>` |
| myRace | `RaceData` | RW | `obj.myRace = <value>` |
| inventory | `Inventory` | RW | `obj.inventory = <value>` |
| rangedCombat | `lightuserdata` | RW | `obj.rangedCombat = <value>` |
| inWhat | `hand` | RW | `obj.inWhat = <value>` |
| isChained | `boolean` | RW | `obj.isChained = <value>` |
| slaveOwner | `hand` | RW | `obj.slaveOwner = <value>` |
| isCarryingSomething | `boolean` | RW | `obj.isCarryingSomething = <value>` |
| carringObjectLeftOrRight | `string` | RW | `obj.carringObjectLeftOrRight = <value>` |
| isCarryingLeftSide | `boolean` | RW | `obj.isCarryingLeftSide = <value>` |
| carryingObject | `hand` | RW | `obj.carryingObject = <value>` |
| messages | `Character::CharMessage` | RW | `obj.messages = <value>` |
| messageSubject | `hand` | RW | `obj.messageSubject = <value>` |
| ragdollNavmeshPosition | `Vector3` | RW | `obj.ragdollNavmeshPosition = <value>` |
| _isBeingCarried | `boolean` | RW | `obj._isBeingCarried = <value>` |
| lastUsedWeaponCategory | `WeaponCategory` | RW | `obj.lastUsedWeaponCategory = <value>` |
| msgCarryMode | `Character::CarryMsg` | RW | `obj.msgCarryMode = <value>` |
| squadMemberID | `integer` | RW | `obj.squadMemberID = <value>` |
| diplomacyMultiplier | `number` | RW | `obj.diplomacyMultiplier = <value>` |
| _destinationInsideBuilding | `hand` | RW | `obj._destinationInsideBuilding = <value>` |
| _destinationInsideWalls | `integer` | RW | `obj._destinationInsideWalls = <value>` |
| animation | `lightuserdata` | RW | `obj.animation = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| medical | `MedicalSystem` | RW | `obj.medical = <value>` |
| isPhysicalMode | `boolean` | RW | `obj.isPhysicalMode = <value>` |
| sex | `string` | RW | `obj.sex = <value>` |
| nameTag | `lightuserdata` | RW | `obj.nameTag = <value>` |
| movement | `CharMovement` | RW | `obj.movement = <value>` |
| body | `CharBody` | RW | `obj.body = <value>` |
| ai | `lightuserdata` | RW | `obj.ai = <value>` |
| platoon | `ActivePlatoon` | RW | `obj.platoon = <value>` |
| portraitIndex | `integer` | RW | `obj.portraitIndex = <value>` |
| portraitSerial | `integer` | RW | `obj.portraitSerial = <value>` |
| groundType | `GroundType` | RW | `obj.groundType = <value>` |
| armourType | `ArmourType` | RW | `obj.armourType = <value>` |
| audioEmitter | `lightuserdata` | RW | `obj.audioEmitter = <value>` |
| terrainHeightPosition | `number` | RW | `obj.terrainHeightPosition = <value>` |
| inDoorsSetCooldown | `integer` | RW | `obj.inDoorsSetCooldown = <value>` |
| naturalWeapon | `Sword` | RW | `obj.naturalWeapon = <value>` |
| ragdollMessages | `std::deque<Character::RagdollMsg>` | RW | `obj.ragdollMessages = <value>` |
| audioData | `AkSoundPosition` | RW | `obj.audioData = <value>` |
| disguiseGUIFeedbacks | `integer` | R | `obj.disguiseGUIFeedbacks` |
| whoSeesMeSneaking | `hand` | R | `obj.whoSeesMeSneaking` |
| inSomething | `UseStuffState` | RW | `obj.inSomething = <value>` |
| audioObject | `std::deque<Character::RagdollMsg>` | RW | `obj.audioObject = <value>` |
| activeEffects | `integer` | R | `obj.activeEffects` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isImmuneToOffscreenMode | `` | `boolean` | `obj:isImmuneToOffscreenMode()` |
| init | `` | `void` | `obj:init()` |
| isOnARoof | `` | `boolean` | `obj:isOnARoof()` |
| isOnAWall | `` | `boolean` | `obj:isOnAWall()` |
| getLightLevel | `` | `number` | `obj:getLightLevel()` |
| getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| healCompletely | `` | `void` | `obj:healCompletely()` |
| resetRagdollNavmeshSafePos | `` | `void` | `obj:resetRagdollNavmeshSafePos()` |
| setRagdollNavmeshSafePos | `` | `void` | `obj:setRagdollNavmeshSafePos()` |
| getFrameTime | `` | `number` | `obj:getFrameTime()` |
| frameSkip | `` | `void` | `obj:frameSkip()` |
| getCurrentNoiseRange | `` | `number` | `obj:getCurrentNoiseRange()` |
| isDestroyed | `` | `boolean` | `obj:isDestroyed()` |
| isLawEnforcement | `` | `boolean` | `obj:isLawEnforcement()` |
| canAssignBounties | `` | `boolean` | `obj:canAssignBounties()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| isDiplomaticStatus | `factorInBiome: boolean` | `boolean` | `obj:isDiplomaticStatus(factorInBiome)` |
| isLeadingAWarCampaign | `` | `boolean` | `obj:isLeadingAWarCampaign()` |
| isInAWarCampaign | `` | `lightuserdata` | `obj:isInAWarCampaign()` |
| wantsToTriggerCampaigns | `` | `boolean` | `obj:wantsToTriggerCampaigns()` |
| isUnique | `` | `boolean` | `obj:isUnique()` |
| canSpeakNormally | `` | `boolean` | `obj:canSpeakNormally()` |
| isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| setSquadMemberType | `memType: SquadMemberType` | `void` | `obj:setSquadMemberType(memType)` |
| isResident | `` | `TownBase` | `obj:isResident()` |
| dailyUpdate | `` | `void` | `obj:dailyUpdate()` |
| updateOnScreenCheck | `` | `boolean` | `obj:updateOnScreenCheck()` |
| offscreenUpdate | `` | `void` | `obj:offscreenUpdate()` |
| updateTimes | `` | `void` | `obj:updateTimes()` |
| getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getFormation | `` | `lightuserdata` | `obj:getFormation()` |
| getEnemyFormation | `` | `lightuserdata` | `obj:getEnemyFormation()` |
| AIDestinationIndoorOutdoorCheck | `who: RootObject` | `boolean` | `obj:AIDestinationIndoorOutdoorCheck(who)` |
| update | `` | `void` | `obj:update()` |
| postUpdate | `` | `void` | `obj:postUpdate()` |
| ragdollUpdatesUT | `` | `void` | `obj:ragdollUpdatesUT()` |
| fourFrameUpdate | `` | `void` | `obj:fourFrameUpdate()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| pausedUpdate | `` | `void` | `obj:pausedUpdate()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| threadedUpdate4 | `` | `void` | `obj:threadedUpdate4()` |
| threadedUpdatePeriodic | `` | `void` | `obj:threadedUpdatePeriodic()` |
| pathExists | `v: Vector3` | `boolean` | `obj:pathExists(v)` |
| weatherUpdate | `_a1: number` | `void` | `obj:weatherUpdate(_a1)` |
| stealthUpdate | `_time: number` | `void` | `obj:stealthUpdate(_time)` |
| lineOfSightCheck | `who: Character` | `number` | `obj:lineOfSightCheck(who)` |
| getPerceptionMult | `` | `number` | `obj:getPerceptionMult()` |
| isWithThePlayer | `` | `boolean` | `obj:isWithThePlayer()` |
| notifyICanSeeYouSneaking | `who: Character, seeing: YesNoMaybe, maybeProgress01: number` | `void` | `obj:notifyICanSeeYouSneaking(who, seeing, maybeProgress01)` |
| isItSafeToGetUp | `` | `boolean` | `obj:isItSafeToGetUp()` |
| separateIntoMyOwnSquad | `permanent: boolean` | `Platoon` | `obj:separateIntoMyOwnSquad(permanent)` |
| dropGearOnDeath | `vampiricDeath: boolean` | `void` | `obj:dropGearOnDeath(vampiricDeath)` |
| isItOkForMeToLoot | `_victim: RootObject, item: Item` | `boolean` | `obj:isItOkForMeToLoot(_victim, item)` |
| ImStealingDoYouNotice | `stealFrom: RootObject, item: Item` | `boolean` | `obj:ImStealingDoYouNotice(stealFrom, item)` |
| getFencingSuccessChance | `item: Item, thief: RootObject` | `number` | `obj:getFencingSuccessChance(item, thief)` |
| stolenGoodsDetectionCheck | `item: Item, thief: RootObject` | `boolean` | `obj:stolenGoodsDetectionCheck(item, thief)` |
| sellingUniformDetectionCheck | `item: Item, thief: Character` | `boolean` | `obj:sellingUniformDetectionCheck(item, thief)` |
| smugglingTradeCheck | `item: Item, who: Character` | `YesNoMaybe` | `obj:smugglingTradeCheck(item, who)` |
| getStealingSuccessChance | `stealFrom: RootObject, item: Item` | `number` | `obj:getStealingSuccessChance(stealFrom, item)` |
| getCurrentWeatherAffectStatus | `` | `WeatherAffecting` | `obj:getCurrentWeatherAffectStatus()` |
| getCurrentWeatherAffectStrength | `` | `number` | `obj:getCurrentWeatherAffectStrength()` |
| getWaterLevel | `` | `WaterState::Enum` | `obj:getWaterLevel()` |
| setTerrainHeightPosition | `height: number` | `void` | `obj:setTerrainHeightPosition(height)` |
| getTerrainHeightPosition | `` | `number` | `obj:getTerrainHeightPosition()` |
| setDisguiseMessage | `msg: Character::DisguiseGUIFeedback` | `void` | `obj:setDisguiseMessage(msg)` |
| uniqueStateUpdate | `` | `void` | `obj:uniqueStateUpdate()` |
| foodUpdate | `` | `void` | `obj:foodUpdate()` |
| eatItem | `food: Item, from: Inventory` | `boolean` | `obj:eatItem(food, from)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| loadFromSerialisePostCreationStage | `gd: GameSaveState` | `void` | `obj:loadFromSerialisePostCreationStage(gd)` |
| setupInventorySections | `state: GameSaveState` | `boolean` | `obj:setupInventorySections(state)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| _getRawPosition | `` | `Vector3` | `obj:_getRawPosition()` |
| getRawEntityPosition | `` | `Vector3` | `obj:getRawEntityPosition()` |
| getMovementSpeed | `` | `number` | `obj:getMovementSpeed()` |
| getMovementSpeedOrders | `` | `MoveSpeed` | `obj:getMovementSpeedOrders()` |
| getMovementDirection | `` | `Vector3` | `obj:getMovementDirection()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| switchLights | `on: boolean` | `void` | `obj:switchLights(on)` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| setInsideTownWalls | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| select | `` | `void` | `obj:select()` |
| unselect | `` | `void` | `obj:unselect()` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| say_WithARepeatLimiter | `s: string` | `void` | `obj:say_WithARepeatLimiter(s)` |
| say | `s: string` | `void` | `obj:say(s)` |
| isInventoryVisible | `` | `boolean` | `obj:isInventoryVisible()` |
| giveItem | `item: Item, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(item, dropOnFail, destroyOnFail)` |
| hasRoomForItem | `item: GameData` | `boolean` | `obj:hasRoomForItem(item)` |
| hasItem | `item: GameData` | `boolean` | `obj:hasItem(item)` |
| hasAmmoFor | `c: Crossbow` | `boolean` | `obj:hasAmmoFor(c)` |
| getNumFoodItems | `` | `integer` | `obj:getNumFoodItems()` |
| hasSimilarItem | `ty: itemType` | `boolean` | `obj:hasSimilarItem(ty)` |
| ifImASmithShouldIDitchMyBackWeapon | `` | `boolean` | `obj:ifImASmithShouldIDitchMyBackWeapon()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| hasABackpackOn | `` | `ContainerItem` | `obj:hasABackpackOn()` |
| isATrader | `` | `boolean` | `obj:isATrader()` |
| isFemale | `` | `boolean` | `obj:isFemale()` |
| isFleeing | `` | `boolean` | `obj:isFleeing()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| getStealthKOChance | `victim: Character, factors: boolean` | `number` | `obj:getStealthKOChance(victim, factors)` |
| getKidnappingChance | `victim: Character` | `number` | `obj:getKidnappingChance(victim)` |
| getKidnappingEscapeChance_skill | `captor: Character` | `number` | `obj:getKidnappingEscapeChance_skill(captor)` |
| getKidnappingEscapeChance_strength | `captor: Character` | `number` | `obj:getKidnappingEscapeChance_strength(captor)` |
| shouldIHelpThisGuy | `who: Character` | `boolean` | `obj:shouldIHelpThisGuy(who)` |
| shouldIScrewThisGuyOver | `who: Character` | `boolean` | `obj:shouldIScrewThisGuyOver(who)` |
| ILoveThisGuyBecauseOfStuffThatHappened | `who: Character` | `boolean` | `obj:ILoveThisGuyBecauseOfStuffThatHappened(who)` |
| IHateThisGuyBecauseOfStuffThatHappened | `who: Character` | `boolean` | `obj:IHateThisGuyBecauseOfStuffThatHappened(who)` |
| getRoughLevel | `` | `integer` | `obj:getRoughLevel()` |
| setStandingOrder | `orderID: MessageForB::StandingOrder, on: boolean` | `void` | `obj:setStandingOrder(orderID, on)` |
| getStandingOrder | `orderID: MessageForB::StandingOrder` | `boolean` | `obj:getStandingOrder(orderID)` |
| setStealthMode | `on: boolean` | `void` | `obj:setStealthMode(on)` |
| isStealthMode | `` | `boolean` | `obj:isStealthMode()` |
| isStealthModeOrCrawling | `` | `boolean` | `obj:isStealthModeOrCrawling()` |
| declareDead | `` | `void` | `obj:declareDead()` |
| updateGUIStatsDetails | `datapanel: DatapanelGUI, name: string, statId: integer` | `void` | `obj:updateGUIStatsDetails(datapanel, name, statId)` |
| _printRaceXPBonusLine | `panel: DatapanelGUI, s: StatsEnumerated` | `void` | `obj:_printRaceXPBonusLine(panel, s)` |
| addGoal | `t: TaskType, subject: RootObjectBase` | `void` | `obj:addGoal(t, subject)` |
| addJob | `t: TaskType, subject: RootObject, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addJob(t, subject, shift, addDontClear, location)` |
| removeJob | `t: TaskType` | `void` | `obj:removeJob(t)` |
| removePermajob | `t: integer` | `void` | `obj:removePermajob(t)` |
| clearPermajobs | `` | `void` | `obj:clearPermajobs()` |
| movePermajob | `taskIdx: integer, targetIdx: integer` | `void` | `obj:movePermajob(taskIdx, targetIdx)` |
| getPermajob | `slot: integer` | `TaskType` | `obj:getPermajob(slot)` |
| getPermajobData | `slot: integer` | `Tasker` | `obj:getPermajobData(slot)` |
| getPermajobCount | `` | `integer` | `obj:getPermajobCount()` |
| addOrder | `dest: Building, t: TaskType, subject: RootObject, shift: boolean, clear: boolean, location: Vector3` | `void` | `obj:addOrder(dest, t, subject, shift, clear, location)` |
| updateLastTask | `dest: Building, t: TaskType, subject: RootObject, location: Vector3` | `void` | `obj:updateLastTask(dest, t, subject, location)` |
| playerMoveOrderDefault | `dest: Building, subject: RootObject, location: Vector3` | `void` | `obj:playerMoveOrderDefault(dest, subject, location)` |
| endCombatMode | `` | `void` | `obj:endCombatMode()` |
| getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| canGoIndoors | `b: Building` | `boolean` | `obj:canGoIndoors(b)` |
| isIndoorsRagdoll | `` | `boolean` | `obj:isIndoorsRagdoll()` |
| destinationIndoors | `r: RootObject` | `hand` | `obj:destinationIndoors(r)` |
| destinationInsideWalls | `r: RootObject` | `integer` | `obj:destinationInsideWalls(r)` |
| getIntendedAggression | `` | `number` | `obj:getIntendedAggression()` |
| getPositionBip01 | `` | `Vector3` | `obj:getPositionBip01()` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| setNameTagVisible | `value: boolean` | `void` | `obj:setNameTagVisible(value)` |
| ragdollMode | `on: boolean, part: RagdollPart::Enum` | `void` | `obj:ragdollMode(on, part)` |
| isRagdoll | `` | `boolean` | `obj:isRagdoll()` |
| isDown | `` | `boolean` | `obj:isDown()` |
| getRagdollPhysicsRootPos | `` | `Vector3` | `obj:getRagdollPhysicsRootPos()` |
| amSomeoneWhoNeedsToEatToLive | `` | `boolean` | `obj:amSomeoneWhoNeedsToEatToLive()` |
| getMagicHungerSetting | `` | `number` | `obj:getMagicHungerSetting()` |
| wantsToEatNow | `` | `boolean` | `obj:wantsToEatNow()` |
| isKidnapped | `` | `boolean` | `obj:isKidnapped()` |
| isLiterallyUnconciousNotPretending | `` | `boolean` | `obj:isLiterallyUnconciousNotPretending()` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| isCrippled | `` | `boolean` | `obj:isCrippled()` |
| getProneState | `` | `ProneState` | `obj:getProneState()` |
| setProneState | `p: ProneState` | `void` | `obj:setProneState(p)` |
| _killRagdoll | `doItNow: boolean` | `void` | `obj:_killRagdoll(doItNow)` |
| giveBirth | `appearance: GameDataCopyStandalone, position: Vector3, rotation: Quaternion, state: GameSaveState, tempplatoonptr: ActivePlatoon, _faction: Faction` | `boolean` | `obj:giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction)` |
| setupAI | `` | `void` | `obj:setupAI()` |
| clearAllAIGoals | `` | `void` | `obj:clearAllAIGoals()` |
| setupPlatoonAI | `` | `void` | `obj:setupPlatoonAI()` |
| setAppearanceData | `data: GameDataCopyStandalone` | `void` | `obj:setAppearanceData(data)` |
| getAppearanceData | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| setDestination | `pos: Vector3, shift: boolean` | `void` | `obj:setDestination(pos, shift)` |
| sendDialogEventOverride | `target: Character, what: EventTriggerEnum, forceRepeat: boolean` | `boolean` | `obj:sendDialogEventOverride(target, what, forceRepeat)` |
| sendDialogEvent | `target: Character, what: EventTriggerEnum` | `boolean` | `obj:sendDialogEvent(target, what)` |
| sayALine | `line: string, force: boolean` | `void` | `obj:sayALine(line, force)` |
| hasDialogue | `` | `boolean` | `obj:hasDialogue()` |
| willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| relocationTeleport | `moveBy: Vector3` | `void` | `obj:relocationTeleport(moveBy)` |
| teleportVisuallyOnly | `to: Vector3, rot: Quaternion` | `void` | `obj:teleportVisuallyOnly(to, rot)` |
| teleportFromAnimation | `` | `void` | `obj:teleportFromAnimation()` |
| attackTarget | `who: Character` | `void` | `obj:attackTarget(who)` |
| notifyTheCampaignOfAnAttack | `attacker: Character` | `void` | `obj:notifyTheCampaignOfAnAttack(attacker)` |
| iShouldntAggravateThisTarget | `target: Character` | `boolean` | `obj:iShouldntAggravateThisTarget(target)` |
| sendMessage | `message: integer, sender: RootObject, subject: RootObject` | `void` | `obj:sendMessage(message, sender, subject)` |
| attackingYou | `attacker: Character, so: boolean, doAwarenessCheck: boolean` | `void` | `obj:attackingYou(attacker, so, doAwarenessCheck)` |
| gettingEaten | `amount: number, eater: Character` | `boolean` | `obj:gettingEaten(amount, eater)` |
| getAttackOriginationDirection | `attacker: Character` | `CutOrigination` | `obj:getAttackOriginationDirection(attacker)` |
| stumbleState | `` | `boolean` | `obj:stumbleState()` |
| setAge | `f: number` | `void` | `obj:setAge(f)` |
| setFaction | `p: Faction, a: ActivePlatoon` | `void` | `obj:setFaction(p, a)` |
| getAge | `` | `number` | `obj:getAge()` |
| getAge0to1 | `` | `number` | `obj:getAge0to1()` |
| getAgeString | `` | `string` | `obj:getAgeString()` |
| getAgeInverse | `` | `number` | `obj:getAgeInverse()` |
| reThinkCurrentAIAction | `` | `void` | `obj:reThinkCurrentAIAction()` |
| getBody | `` | `CharBody` | `obj:getBody()` |
| getCombatClass | `` | `CombatClass` | `obj:getCombatClass()` |
| getStats | `` | `CharStats` | `obj:getStats()` |
| getMedical | `` | `MedicalSystem` | `obj:getMedical()` |
| getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| getAI | `` | `lightuserdata` | `obj:getAI()` |
| getAttackTarget | `` | `hand` | `obj:getAttackTarget()` |
| isInCombatMode | `melee: boolean, ranged: boolean` | `boolean` | `obj:isInCombatMode(melee, ranged)` |
| isInRangedCombatMode | `` | `boolean` | `obj:isInRangedCombatMode()` |
| isLiterallyUnderMeleeAttackRightNowForSure | `` | `boolean` | `obj:isLiterallyUnderMeleeAttackRightNowForSure()` |
| _isLiterallyUnderMeleeAttackRightNowForSure_update | `` | `void` | `obj:_isLiterallyUnderMeleeAttackRightNowForSure_update()` |
| conglomerateTagsFor | `who: Character` | `integer` | `obj:conglomerateTagsFor(who)` |
| isPrisonerFreeToGo | `` | `boolean` | `obj:isPrisonerFreeToGo()` |
| clearTempEnemyStatus | `theEnemy: Character` | `void` | `obj:clearTempEnemyStatus(theEnemy)` |
| clearAllTempEnemyStatuses | `tag: CharacterPerceptionTags_ShortTerm` | `void` | `obj:clearAllTempEnemyStatuses(tag)` |
| lastSeenInHoursAgo | `c: Character` | `number` | `obj:lastSeenInHoursAgo(c)` |
| haveMetBefore | `h: Character` | `boolean` | `obj:haveMetBefore(h)` |
| getIDForMemoryTagging | `` | `hand` | `obj:getIDForMemoryTagging()` |
| getMovement | `` | `CharMovement` | `obj:getMovement()` |
| lookatPosition | `v: Vector3, fullbodyFacing: boolean` | `void` | `obj:lookatPosition(v, fullbodyFacing)` |
| areYouGonnaGetMe | `who: Character` | `boolean` | `obj:areYouGonnaGetMe(who)` |
| getAllAttackersCount | `` | `integer` | `obj:getAllAttackersCount()` |
| getRace | `` | `RaceData` | `obj:getRace()` |
| setRace | `r: GameData` | `void` | `obj:setRace(r)` |
| getRadius | `` | `number` | `obj:getRadius()` |
| isPlayerCharacter | `` | `boolean` | `obj:isPlayerCharacter()` |
| checkPlayerOrderForProblems | `t: TaskType, subject: RootObject` | `boolean` | `obj:checkPlayerOrderForProblems(t, subject)` |
| getTotalCarryWeight | `` | `number` | `obj:getTotalCarryWeight()` |
| getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| drawWeapon | `_a1: Item, _a2: string` | `boolean` | `obj:drawWeapon(_a1, _a2)` |
| getUpperBodyArmour | `` | `Item` | `obj:getUpperBodyArmour()` |
| getLowerBodyArmour | `` | `Item` | `obj:getLowerBodyArmour()` |
| isInjured | `robot: boolean` | `boolean` | `obj:isInjured(robot)` |
| shouldUseRangedWeapons | `` | `boolean` | `obj:shouldUseRangedWeapons()` |
| getBoneWorldPosition | `name: string` | `Vector3` | `obj:getBoneWorldPosition(name)` |
| getAppearance | `` | `AppearanceBase` | `obj:getAppearance()` |
| _setPlatoon | `p: ActivePlatoon, idnum: integer` | `void` | `obj:_setPlatoon(p, idnum)` |
| getPlatoon | `` | `ActivePlatoon` | `obj:getPlatoon()` |
| hasPlatoon | `` | `boolean` | `obj:hasPlatoon()` |
| isInAPersistentPlatoon | `` | `boolean` | `obj:isInAPersistentPlatoon()` |
| getBlackboard | `` | `lightuserdata` | `obj:getBlackboard()` |
| getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getOrdersReciever | `` | `lightuserdata` | `obj:getOrdersReciever()` |
| preventRagdollMode | `` | `boolean` | `obj:preventRagdollMode()` |
| setPrisonMode | `on: boolean, h: UseableStuff` | `void` | `obj:setPrisonMode(on, h)` |
| setBedMode | `on: boolean, h: UseableStuff` | `void` | `obj:setBedMode(on, h)` |
| setSlaveAIJob | `on: boolean` | `void` | `obj:setSlaveAIJob(on)` |
| isChainedMode | `` | `boolean` | `obj:isChainedMode()` |
| getChainedModeShackles | `` | `LockedArmour` | `obj:getChainedModeShackles()` |
| getMySlaveOwner | `` | `hand` | `obj:getMySlaveOwner()` |
| isSlave | `` | `SlaveStateEnum` | `obj:isSlave()` |
| isMySlave | `slave: Character` | `boolean` | `obj:isMySlave(slave)` |
| isMyFactionsSlave | `slave: Character` | `boolean` | `obj:isMyFactionsSlave(slave)` |
| isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| runSlaveAnim | `anim: string, speed: number, sync: number` | `void` | `obj:runSlaveAnim(anim, speed, sync)` |
| endSlaveAnim | `anim: string` | `void` | `obj:endSlaveAnim(anim)` |
| updatePortraitGUIState | `` | `void` | `obj:updatePortraitGUIState()` |
| pickupObject | `who: Character` | `void` | `obj:pickupObject(who)` |
| getPickedUp | `byWhom: Character` | `void` | `obj:getPickedUp(byWhom)` |
| slaveAttachToBoneMode | `bone: string` | `void` | `obj:slaveAttachToBoneMode(bone)` |
| isDead | `` | `boolean` | `obj:isDead()` |
| isBeingCarried | `` | `boolean` | `obj:isBeingCarried()` |
| getCarryingObject | `` | `hand` | `obj:getCarryingObject()` |
| chooseCarryObjectLeftOrRight | `` | `void` | `obj:chooseCarryObjectLeftOrRight()` |
| dropCarriedObject | `ragdollHim: boolean, removeOnly: boolean` | `void` | `obj:dropCarriedObject(ragdollHim, removeOnly)` |
| getDropped | `ragdollHim: boolean, hull: boolean` | `void` | `obj:getDropped(ragdollHim, hull)` |
| getDiplomacyMultiplier | `` | `number` | `obj:getDiplomacyMultiplier()` |
| isEnemy | `who: Character, factorInDisguises: boolean` | `boolean` | `obj:isEnemy(who, factorInDisguises)` |
| isAlly | `who: Character, factorInDisguises: boolean` | `boolean` | `obj:isAlly(who, factorInDisguises)` |
| getDefaultTaskRepertoireEnum | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| getAnimationClass | `` | `lightuserdata` | `obj:getAnimationClass()` |
| getPredictedPosition | `secondsInFuture: number` | `Vector3` | `obj:getPredictedPosition(secondsInFuture)` |
| carryModeT | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:carryModeT(on, makeRagdoll, makeHull)` |
| _carryMode | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:_carryMode(on, makeRagdoll, makeHull)` |
| recalculateTotalEquipmentSkillBonus | `` | `void` | `obj:recalculateTotalEquipmentSkillBonus()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| audioEvent | `name: string, range: SoundRange` | `boolean` | `obj:audioEvent(name, range)` |
| setGroundType | `t: GroundType` | `void` | `obj:setGroundType(t)` |
| getGroundType | `` | `GroundType` | `obj:getGroundType()` |
| calculateMainArmourType | `` | `void` | `obj:calculateMainArmourType()` |
| getMainArmourType | `` | `ArmourType` | `obj:getMainArmourType()` |
| wearingUniformOf | `f: Faction` | `boolean` | `obj:wearingUniformOf(f)` |
| getUniformColorScheme | `` | `GameData` | `obj:getUniformColorScheme()` |
| canTakePlayerOrdersAtThisTime | `` | `boolean` | `obj:canTakePlayerOrdersAtThisTime()` |
| startEffect | `effect: GameData` | `boolean` | `obj:startEffect(effect)` |
| stopEffect | `effect: GameData` | `boolean` | `obj:stopEffect(effect)` |
| stopAllEffects | `` | `void` | `obj:stopAllEffects()` |
| notifyEffect | `type: EffectType::Enum, what: WeatherAffecting, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| equipItem | `sectionName: string, item: Item` | `void` | `obj:equipItem(sectionName, item)` |
| unequipItem | `sectionName: string, item: Item` | `void` | `obj:unequipItem(sectionName, item)` |
| validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| processCharacterLoadTimeMessages | `` | `void` | `obj:processCharacterLoadTimeMessages()` |
| wantsPathfinderActive | `` | `boolean` | `obj:wantsPathfinderActive()` |
| createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| calculateDestinationState | `dest: Building, subject: RootObject, v: Vector3` | `void` | `obj:calculateDestinationState(dest, subject, v)` |
| generateWeapon | `weapon: GameData, manufacturer: GameData` | `Item` | `obj:generateWeapon(weapon, manufacturer)` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| createComponents | `appearance: GameDataCopyStandalone` | `boolean` | `obj:createComponents(appearance)` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| updateStateBroadcast | `time: number` | `void` | `obj:updateStateBroadcast(time)` |
| setEffectBT | `effect: GameData, active: boolean` | `void` | `obj:setEffectBT(effect, active)` |
| postRagdollCallback | `on: boolean, part: RagdollPart::Enum` | `void` | `obj:postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| rememberCharacter [1] | `who: Character, mem: CharacterPerceptionTags_ShortTerm` | `void` | `obj:rememberCharacter(who, mem)` |
| rememberCharacter [2] | `who: Character, mem: CharacterPerceptionTags_LongTerm` | `void` | `obj:rememberCharacter(who, mem)` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| isIndoors | `` | `hand` | `obj:isIndoors()` |
| isStandingOnBuilding | `` | `hand` | `obj:isStandingOnBuilding()` |
| notifyIndoors | `in: hand` | `void` | `obj:notifyIndoors(in)` |
| setDestinationIndoors | `h: hand` | `void` | `obj:setDestinationIndoors(h)` |
| getAudioObject | `` | `integer` | `obj:getAudioObject()` |
| getName | `` | `string` | `obj:getName()` |
| changeSlaveOwner | `newOwner: hand` | `void` | `obj:changeSlaveOwner(newOwner)` |
| teleport [1] | `moveBy: Vector3, rot: Quaternion` | `void` | `obj:teleport(moveBy, rot)` |
| teleport [2] | `moveBy: Vector3` | `void` | `obj:teleport(moveBy)` |
| audioValue [1] | `name: char, value: number` | `void` | `obj:audioValue(name, value)` |
| audioValue [2] | `name: char, value: char` | `void` | `obj:audioValue(name, value)` |
| getPermajobName | `slot: integer` | `string` | `obj:getPermajobName(slot)` |
| getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| getAllAttackers | `` | `void` | `obj:getAllAttackers()` |
| getCharacterMemoryTag [1] | `who: Character, mem: CharacterPerceptionTags_LongTerm` | `boolean` | `obj:getCharacterMemoryTag(who, mem)` |
| getCharacterMemoryTag [2] | `who: Character, mem: CharacterPerceptionTags_ShortTerm` | `boolean` | `obj:getCharacterMemoryTag(who, mem)` |
| hitByMeleeAttack [1] | `who: Character` | `void` | `obj:hitByMeleeAttack(who)` |
| hitByMeleeAttack [2] | `attack: CombatTechniqueData` | `void` | `obj:hitByMeleeAttack(attack)` |
| convertCutDirection [1] | `dir: CutDirection, from: CutOrigination` | `CutDirection` | `obj:convertCutDirection(dir, from)` |
| convertCutDirection [2] | `cut: CutDirection, attacker: Character` | `CutDirection` | `obj:convertCutDirection(cut, attacker)` |
| breakFollowOrderLoop | `start: hand` | `boolean` | `obj:breakFollowOrderLoop(start)` |
| formationUpdateCallback | `pos: Vector3, target: hand, heading: Vector3, from: userdata` | `void` | `obj:formationUpdateCallback(pos, target, heading, from)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| hasItemsFrom | `from: StorageBuilding` | `boolean` | `obj:hasItemsFrom(from)` |
| getLockpickChance | `victim: userdata` | `number` | `obj:getLockpickChance(victim)` |
| debugIndicateCharacters | `` | `void` | `obj:debugIndicateCharacters()` |
| iShotYou | `attacker: Character, poon: userdata, onPurpose: boolean` | `boolean` | `obj:iShotYou(attacker, poon, onPurpose)` |
| _startStumble | `dir: CutDirection, damage: Damages, bodyPart: GameData, attacker: Character` | `void` | `obj:_startStumble(dir, damage, bodyPart, attacker)` |
| getSquadMissionTarget | `` | `hand` | `obj:getSquadMissionTarget()` |
| setChainedMode | `on: boolean, owner: hand` | `void` | `obj:setChainedMode(on, owner)` |
| _ragdollMode | `on: boolean, part: integer` | `boolean` | `obj:_ragdollMode(on, part)` |

## Character::AttachedArrowManager
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.AttachedArrowManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| index | `integer` | RW | `obj.index = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clearAll | `` | `void` | `obj:clearAll()` |
| updateStart | `` | `void` | `obj:updateStart()` |
| addArrow | `pos: Vector3, targ: Vector3, color: integer` | `void` | `obj:addArrow(pos, targ, color)` |
| updateEnd | `` | `void` | `obj:updateEnd()` |

## Character::CarryMsg
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.Character_CarryMsg`

## Character::RagdollMsg
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.Character_RagdollMsg`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |

## Character::WhoSeesMe
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.WhoSeesMe`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lastUpdated | `number` | RW | `obj.lastUpdated = <value>` |
| seeState | `YesNoMaybe` | RW | `obj.seeState = <value>` |
| progressOfMaybe | `number` | RW | `obj.progressOfMaybe = <value>` |

## CharacterAnimal
**Header:** `extern/KenshiLib/Include/kenshi/CharacterAnimal.h`
**Metatable:** `KenshiLua.CharacterAnimal`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| weaponIsTechnicallyEquipped | `boolean` | RW | `obj.weaponIsTechnicallyEquipped = <value>` |
| HPMultiplier | `number` | RW | `obj.HPMultiplier = <value>` |
| itemInMouthTimeStamp | `TimeOfDay` | RW | `obj.itemInMouthTimeStamp = <value>` |
| smellThresholdBlood | `number` | RW | `obj.smellThresholdBlood = <value>` |
| smellThresholdEggs | `number` | RW | `obj.smellThresholdEggs = <value>` |
| ageSizeMin | `number` | RW | `obj.ageSizeMin = <value>` |
| ageSizeMax | `number` | RW | `obj.ageSizeMax = <value>` |
| lifespanInDays | `number` | RW | `obj.lifespanInDays = <value>` |
| lastUpdatedAge | `number` | RW | `obj.lastUpdatedAge = <value>` |
| age | `number` | RW | `obj.age = <value>` |
| weaponInHands | `Weapon` | RW | `obj.weaponInHands = <value>` |
| audioTimeStamp | `number` | RW | `obj.audioTimeStamp = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isAnimal | `` | `CharacterAnimal` | `obj:isAnimal()` |
| createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| drawWeapon | `_a1: Item, lastSlot: string` | `boolean` | `obj:drawWeapon(_a1, lastSlot)` |
| sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| giveBirth | `appearance: GameDataCopyStandalone, position: Vector3, rotation: Quaternion, state: GameSaveState, tempplatoonptr: ActivePlatoon, _faction: Faction` | `boolean` | `obj:giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction)` |
| setupInventorySections | `state: GameSaveState` | `boolean` | `obj:setupInventorySections(state)` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| setAge | `zeroToOne: number` | `void` | `obj:setAge(zeroToOne)` |
| getAge | `` | `number` | `obj:getAge()` |
| getAgeInverse | `` | `number` | `obj:getAgeInverse()` |
| getAge0to1 | `` | `number` | `obj:getAge0to1()` |
| getDefaultTaskRepertoireEnum | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| canGoIndoors | `b: Building` | `boolean` | `obj:canGoIndoors(b)` |
| getSmellHuntingThresholdBlood | `` | `number` | `obj:getSmellHuntingThresholdBlood()` |
| getSmellHuntingThresholdEggs | `` | `number` | `obj:getSmellHuntingThresholdEggs()` |
| getHPMultiplier | `` | `number` | `obj:getHPMultiplier()` |
| foodUpdate | `` | `void` | `obj:foodUpdate()` |
| pickupItemInMouth | `item: Item` | `boolean` | `obj:pickupItemInMouth(item)` |
| dropItemInMouth | `` | `boolean` | `obj:dropItemInMouth()` |
| getItemInMouth | `` | `Item` | `obj:getItemInMouth()` |
| eatItemInMouth | `` | `void` | `obj:eatItemInMouth()` |
| init | `` | `void` | `obj:init()` |
| dropItem | `itembase: RootObject` | `void` | `obj:dropItem(itembase)` |

## CharacterEditWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterEditWindow.h`
**Metatable:** `KenshiLua.CharacterEditWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| camera | `lightuserdata` | R | `obj.camera` |
| txtName | `MyGUI::Widget` | RW | `obj.txtName = <value>` |
| txtGender | `MyGUI::Widget` | RW | `obj.txtGender = <value>` |
| txtRace | `MyGUI::Widget` | RW | `obj.txtRace = <value>` |
| txtSubRace | `MyGUI::Widget` | RW | `obj.txtSubRace = <value>` |
| txtCharIdx | `MyGUI::Widget` | RW | `obj.txtCharIdx = <value>` |
| importButton | `MyGUI::Widget` | RW | `obj.importButton = <value>` |
| exportButton | `MyGUI::Widget` | RW | `obj.exportButton = <value>` |
| panelTabs | `MyGUI::Widget` | RW | `obj.panelTabs = <value>` |
| panelTabsView | `MyGUI::Widget` | RW | `obj.panelTabsView = <value>` |
| btnPrevGender | `MyGUI::Widget` | RW | `obj.btnPrevGender = <value>` |
| btnNextGender | `MyGUI::Widget` | RW | `obj.btnNextGender = <value>` |
| btnPrevRace | `MyGUI::Widget` | RW | `obj.btnPrevRace = <value>` |
| btnNextRace | `MyGUI::Widget` | RW | `obj.btnNextRace = <value>` |
| btnPrevSubRace | `MyGUI::Widget` | RW | `obj.btnPrevSubRace = <value>` |
| btnNextSubRace | `MyGUI::Widget` | RW | `obj.btnNextSubRace = <value>` |
| btnReset | `MyGUI::Widget` | RW | `obj.btnReset = <value>` |
| btnRandomiseAll | `MyGUI::Widget` | RW | `obj.btnRandomiseAll = <value>` |
| btnRandomisePart | `MyGUI::Widget` | RW | `obj.btnRandomisePart = <value>` |
| descriptionPanel | `MyGUI::Widget` | RW | `obj.descriptionPanel = <value>` |
| descriptionPanelText | `MyGUI::Widget` | RW | `obj.descriptionPanelText = <value>` |
| statsPanel | `MyGUI::Widget` | RW | `obj.statsPanel = <value>` |
| statsDataPanel | `DatapanelGUI` | RW | `obj.statsDataPanel = <value>` |
| dialog | `OpenSaveFileDialog` | RW | `obj.dialog = <value>` |
| isMidGame | `boolean` | RW | `obj.isMidGame = <value>` |
| multipleCharactersChangedCheck | `integer` | RW | `obj.multipleCharactersChangedCheck = <value>` |
| characterEntityUpdated | `boolean` | RW | `obj.characterEntityUpdated = <value>` |
| clothVisible | `boolean` | RW | `obj.clothVisible = <value>` |
| appearanceData | `GameDataCopyStandalone` | RW | `obj.appearanceData = <value>` |
| raceData | `GameData` | RW | `obj.raceData = <value>` |
| currentCategory | `integer` | RW | `obj.currentCategory = <value>` |
| currentRaceGroupIndex | `integer` | RW | `obj.currentRaceGroupIndex = <value>` |
| currentSubRaceIndex | `integer` | RW | `obj.currentSubRaceIndex = <value>` |
| currentGender | `integer` | RW | `obj.currentGender = <value>` |
| currentRaceData | `lightuserdata` | R | `obj.currentRaceData` |
| currentEditData | `lightuserdata` | R | `obj.currentEditData` |
| character | `Character` | RW | `obj.character = <value>` |
| currentCharacterIdx | `integer` | RW | `obj.currentCharacterIdx = <value>` |
| currentAnimation | `lightuserdata` | R | `obj.currentAnimation` |
| raceLimits | `lightuserdata` | R | `obj.raceLimits` |
| showNamesOption | `boolean` | RW | `obj.showNamesOption = <value>` |
| editorRootNode | `lightuserdata` | R | `obj.editorRootNode` |
| characterPositionNode | `lightuserdata` | R | `obj.characterPositionNode` |
| characterRotationNode | `lightuserdata` | R | `obj.characterRotationNode` |
| workspace | `lightuserdata` | R | `obj.workspace` |
| platform | `lightuserdata` | R | `obj.platform` |
| requestUpdateLiveObject | `boolean` | RW | `obj.requestUpdateLiveObject = <value>` |
| idleAnimations | `Ogre::FastArray<AnimationData*>` | RW | `obj.idleAnimations = <value>` |
| characters | `Ogre::FastArray<Character*>` | RW | `obj.characters = <value>` |
| racesGroups | `Ogre::FastArray<RaceGroupData*>` | RW | `obj.racesGroups = <value>` |
| initialPositions | `Ogre::FastArray<Ogre::Vector3>` | RW | `obj.initialPositions = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| loadData | `` | `void` | `obj:loadData()` |
| initCharacters | `` | `void` | `obj:initCharacters()` |
| updateRace | `` | `void` | `obj:updateRace()` |
| updateCharacterPoses | `` | `void` | `obj:updateCharacterPoses()` |
| clearCharacterPoses | `` | `void` | `obj:clearCharacterPoses()` |
| updateCharacter | `` | `void` | `obj:updateCharacter()` |
| showCharacter | `c: Character, on: boolean` | `void` | `obj:showCharacter(c, on)` |
| updateCurrentCategory | `` | `void` | `obj:updateCurrentCategory()` |
| loadImportedCharacter | `_dialog: OpenSaveFileDialog, accept: boolean, result: string` | `void` | `obj:loadImportedCharacter(_dialog, accept, result)` |
| setClothesVisible | `_character: Character, visible: boolean` | `void` | `obj:setClothesVisible(_character, visible)` |
| confirmMessageCallback | `_btn: integer` | `void` | `obj:confirmMessageCallback(_btn)` |
| setupUI | `` | `void` | `obj:setupUI()` |
| setUIEnabled | `enabled: boolean` | `void` | `obj:setUIEnabled(enabled)` |
| refreshUI | `` | `void` | `obj:refreshUI()` |
| updateLiveObject | `` | `void` | `obj:updateLiveObject()` |
| refreshCharacterPoses | `` | `void` | `obj:refreshCharacterPoses()` |
| exportMeshes | `` | `void` | `obj:exportMeshes()` |
| getCurrentHeadName | `` | `void` | `obj:getCurrentHeadName()` |
| getCurrentAttachmentName | `slot: AttachSlot` | `void` | `obj:getCurrentAttachmentName(slot)` |
| setCurrentHeadName | `index: integer` | `void` | `obj:setCurrentHeadName(index)` |
| setCurrentAttachmentName | `slot: AttachSlot, index: integer` | `void` | `obj:setCurrentAttachmentName(slot, index)` |
| nameChanged | `sender: MyGUI::EditBox` | `void` | `obj:nameChanged(sender)` |
| prevRace | `sender: MyGUI::Widget` | `void` | `obj:prevRace(sender)` |
| nextRace | `sender: MyGUI::Widget` | `void` | `obj:nextRace(sender)` |
| prevSubRace | `sender: MyGUI::Widget` | `void` | `obj:prevSubRace(sender)` |
| nextSubRace | `sender: MyGUI::Widget` | `void` | `obj:nextSubRace(sender)` |
| changeGender | `sender: MyGUI::Widget` | `void` | `obj:changeGender(sender)` |
| changeAppearanceData | `prevRace: GameData, genderVal: AppearanceManager::Gender` | `void` | `obj:changeAppearanceData(prevRace, genderVal)` |
| prevCharacter | `sender: MyGUI::Widget` | `void` | `obj:prevCharacter(sender)` |
| nextCharacter | `sender: MyGUI::Widget` | `void` | `obj:nextCharacter(sender)` |
| changeCategory | `sender: MyGUI::Widget` | `void` | `obj:changeCategory(sender)` |
| resetAppearance | `sender: MyGUI::Widget` | `void` | `obj:resetAppearance(sender)` |
| randomiseAll | `sender: MyGUI::Widget` | `void` | `obj:randomiseAll(sender)` |
| randomisePart | `sender: MyGUI::Widget` | `void` | `obj:randomisePart(sender)` |
| importCharacter | `sender: MyGUI::Widget` | `void` | `obj:importCharacter(sender)` |
| exportCharacter | `sender: MyGUI::Widget` | `void` | `obj:exportCharacter(sender)` |
| toggleClothes | `sender: MyGUI::Widget` | `void` | `obj:toggleClothes(sender)` |
| confirmButton | `sender: MyGUI::Widget` | `void` | `obj:confirmButton(sender)` |

## CharacterHuman
**Header:** `extern/KenshiLib/Include/kenshi/CharacterHuman.h`
**Metatable:** `KenshiLua.CharacterHuman`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| weaponInHands | `Weapon` | RW | `obj.weaponInHands = <value>` |
| weaponInHandsSheathLocation | `string` | RW | `obj.weaponInHandsSheathLocation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isHuman | `` | `CharacterHuman` | `obj:isHuman()` |
| drawWeapon | `item: Item, lastSection: string` | `boolean` | `obj:drawWeapon(item, lastSection)` |
| sheatheWeapon | `` | `void` | `obj:sheatheWeapon()` |
| getCurrentWeapon | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| getRangedWeapon | `` | `Crossbow` | `obj:getRangedWeapon()` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| giveBirth | `_appearance: GameDataCopyStandalone, _pos: Vector3, _rot: Quaternion, state: GameSaveState, tempplatoonptr: ActivePlatoon, _faction: Faction` | `boolean` | `obj:giveBirth(_appearance, _pos, _rot, state, tempplatoonptr, _faction)` |
| setupInventorySections | `state: GameSaveState` | `boolean` | `obj:setupInventorySections(state)` |
| validateInventorySections | `` | `void` | `obj:validateInventorySections()` |
| setupAudio | `` | `void` | `obj:setupAudio()` |
| shaveHead | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isHeadShaven | `` | `boolean` | `obj:isHeadShaven()` |
| createAnimationClass | `` | `void` | `obj:createAnimationClass()` |
| dropItem | `itembase: RootObject` | `void` | `obj:dropItem(itembase)` |
| dropWeaponInHands | `` | `void` | `obj:dropWeaponInHands()` |
| dropWeaponInHandsFake | `` | `void` | `obj:dropWeaponInHandsFake()` |
| unequipItem | `section: string, item: Item` | `void` | `obj:unequipItem(section, item)` |
| weatherUpdate | `time: number` | `void` | `obj:weatherUpdate(time)` |
| leaveSheathEquipped | `section: string, ypos: integer` | `void` | `obj:leaveSheathEquipped(section, ypos)` |
| postRagdollCallback | `on: boolean, part: RagdollPart::Enum` | `void` | `obj:postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |

## CharacterInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.CharacterInventoryLayout`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |

## CharacterStatsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`
**Metatable:** `KenshiLua.CharacterStatsWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | `Character` | R | `obj.character` |
| statsSum | `integer` | RW | `obj.statsSum = <value>` |
| statProgress | `StatsEnumerated` | RW | `obj.statProgress = <value>` |
| currentStatIdDescription | `string` | RW | `obj.currentStatIdDescription = <value>` |
| attributesDatapanel | `DatapanelGUI` | R | `obj.attributesDatapanel` |
| skills1Datapanel | `DatapanelGUI` | R | `obj.skills1Datapanel` |
| skills2Datapanel | `DatapanelGUI` | R | `obj.skills2Datapanel` |
| skills3Datapanel | `DatapanelGUI` | R | `obj.skills3Datapanel` |
| skills4Datapanel | `DatapanelGUI` | R | `obj.skills4Datapanel` |
| statsDatapanel | `DatapanelGUI` | R | `obj.statsDatapanel` |
| description1Datapanel | `DatapanelGUI` | R | `obj.description1Datapanel` |
| description2Datapanel | `DatapanelGUI` | R | `obj.description2Datapanel` |
| autoUpdateMode | `boolean` | RW | `obj.autoUpdateMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| create | `` | `void` | `obj:create()` |
| update | `` | `void` | `obj:update()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| setAutoUpdateMode | `on: boolean` | `void` | `obj:setAutoUpdateMode(on)` |
| setupStats | `` | `void` | `obj:setupStats()` |
| updateStats | `` | `void` | `obj:updateStats()` |
| clearDesctiption | `` | `void` | `obj:clearDesctiption()` |
| sumStats | `` | `integer` | `obj:sumStats()` |
| getStatsPanel | `group: CharacterStatsWindow::StatGroup::Group` | `DatapanelGUI` | `obj:getStatsPanel(group)` |
| autoChangeSelectedObject | `obj: hand` | `void` | `obj:autoChangeSelectedObject(obj)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| BuildStats | `` | `void` | `CharacterStatsWindow.BuildStats()`<br>`obj:BuildStats()` |
| addStat | `` | `void` | `CharacterStatsWindow.addStat()`<br>`obj:addStat()` |
| getStat | `type: StatsEnumerated` | `boolean\|integer` | `CharacterStatsWindow.getStat(type)`<br>`obj:getStat(type)` |
| getStatById | `` | `boolean\|integer` | `CharacterStatsWindow.getStatById()`<br>`obj:getStatById()` |

## CharacterStatsWindow::Stat
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`
**Parent Class:** [`CharacterStatsWindow`](#characterstatswindow)
**Metatable:** `KenshiLua.Stat`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| type | `StatsEnumerated` | RW | `obj.type = <value>` |
| id | `string` | RW | `obj.id = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| description | `string` | RW | `obj.description = <value>` |
| active | `boolean` | RW | `obj.active = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: Stat` | `void` | `obj:operator_assign(other)` |

## CharacterStatsWindow::StatGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`
**Parent Class:** [`CharacterStatsWindow`](#characterstatswindow)
**Metatable:** `KenshiLua.StatGroup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| group | `CharacterStatsWindow::StatGroup::Group` | RW | `obj.group = <value>` |
| name | `string` | RW | `obj.name = <value>` |

## CharacterTradingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterTradingWindow.h`
**Metatable:** `KenshiLua.CharacterTradingWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| tradingHandler | `lightuserdata` | R | `obj.tradingHandler` |
| charactersBox | `MyGUI::Widget` | R | `obj.charactersBox` |
| confirmBtn | `MyGUI::Widget` | R | `obj.confirmBtn` |
| currentTotalText | `MyGUI::Widget` | R | `obj.currentTotalText` |
| selectedCountText | `MyGUI::Widget` | R | `obj.selectedCountText` |
| tradingBoxes | `Ogre::FastArray<CharacterTradingBox*>` | RW | `obj.tradingBoxes = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| show | `on: boolean` | `void` | `obj:show(on)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| update | `` | `void` | `obj:update()` |
| close | `` | `void` | `obj:close()` |

## CharBody
**Header:** `extern/KenshiLib/Include/kenshi/CharBody.h`
**Metatable:** `KenshiLua.CharBody`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| combatClass | `CombatClass` | RW | `obj.combatClass = <value>` |
| animation | `lightuserdata` | RW | `obj.animation = <value>` |
| character | `Character` | RW | `obj.character = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| target | `hand` | RW | `obj.target = <value>` |
| gotItem | `boolean` | RW | `obj.gotItem = <value>` |
| crouched | `boolean` | RW | `obj.crouched = <value>` |
| jogMode | `boolean` | RW | `obj.jogMode = <value>` |
| arbitraryCatchupDist | `number` | RW | `obj.arbitraryCatchupDist = <value>` |
| ai | `lightuserdata` | RW | `obj.ai = <value>` |
| movement | `CharMovement` | RW | `obj.movement = <value>` |
| frameTIME | `number` | RW | `obj.frameTIME = <value>` |
| currentAction | `Tasker` | RW | `obj.currentAction = <value>` |
| amIdle | `boolean` | RW | `obj.amIdle = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `_time: number` | `void` | `obj:update(_time)` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| notifyBodyTaskComplete | `` | `void` | `obj:notifyBodyTaskComplete()` |
| notifyTaskComplete | `` | `void` | `obj:notifyTaskComplete()` |
| notifyTaskImpossible | `` | `void` | `obj:notifyTaskImpossible()` |
| getCombatClass | `` | `CombatClass` | `obj:getCombatClass()` |
| isCrouched | `` | `boolean` | `obj:isCrouched()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getName | `` | `string` | `obj:getName()` |
| isCharacter | `` | `boolean` | `obj:isCharacter()` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| getCharBody | `` | `CharBody` | `obj:getCharBody()` |
| getUpFromRagdoll | `animationName: string` | `void` | `obj:getUpFromRagdoll(animationName)` |
| getPlatoon | `` | `Platoon` | `obj:getPlatoon()` |
| getCurrentAction | `` | `Tasker` | `obj:getCurrentAction()` |
| getCurrentActionOrMessage | `` | `Tasker` | `obj:getCurrentActionOrMessage()` |
| endAction | `` | `void` | `obj:endAction()` |
| isIdle | `` | `boolean` | `obj:isIdle()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| _endAction | `` | `void` | `obj:_endAction()` |
| create | `m: CharMovement, a: userdata, an: userdata, c: Character, st: CharStats` | `void` | `obj:create(m, a, an, c, st)` |
| setCurrentAction [1] | `startActionMsg: Tasker` | `boolean` | `obj:setCurrentAction(startActionMsg)` |
| setCurrentAction [2] | `t: TaskType, target: RootObject` | `boolean` | `obj:setCurrentAction(t, target)` |
| notifyPathImpossible | `h: hand` | `void` | `obj:notifyPathImpossible(h)` |
| _move | `who: RootObjectBase, location: Vector3` | `void` | `obj:_move(who, location)` |
| _patrol | `task: Tasker, end: integer, pos: Vector3, area: userdata, taskSys: userdata, town: TownBase` | `void` | `obj:_patrol(task, end, pos, area, taskSys, town)` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| getCurrentSubject | `` | `hand` | `obj:getCurrentSubject()` |

## CharMovement
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.CharMovement`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| flockingVector | `Vector3` | RW | `obj.flockingVector = <value>` |
| combatMover | `CombatMovementController` | RW | `obj.combatMover = <value>` |
| combatMover2 | `FormationMover` | RW | `obj.combatMover2 = <value>` |
| flockingTools | `FlockingTools` | RW | `obj.flockingTools = <value>` |
| formation | `lightuserdata` | RW | `obj.formation = <value>` |
| enemyFormation | `lightuserdata` | RW | `obj.enemyFormation = <value>` |
| havokCharacter | `HavokCharacter` | RW | `obj.havokCharacter = <value>` |
| tracer | `lightuserdata` | RW | `obj.tracer = <value>` |
| dontEverRecreateMe | `boolean` | RW | `obj.dontEverRecreateMe = <value>` |
| floorGroup | `integer` | RW | `obj.floorGroup = <value>` |
| building | `hand` | RW | `obj.building = <value>` |
| initCheck | `boolean` | RW | `obj.initCheck = <value>` |
| _combatMoveSpeedMult | `number` | RW | `obj._combatMoveSpeedMult = <value>` |
| destinationLoaded | `boolean` | RW | `obj.destinationLoaded = <value>` |
| footprintRadius | `number` | RW | `obj.footprintRadius = <value>` |
| edgeTarget | `integer` | RW | `obj.edgeTarget = <value>` |
| _lastOffMeshCheck | `number` | RW | `obj._lastOffMeshCheck = <value>` |
| movingToEdge | `boolean` | RW | `obj.movingToEdge = <value>` |
| lastStepTime | `number` | RW | `obj.lastStepTime = <value>` |
| animationOverride | `boolean` | RW | `obj.animationOverride = <value>` |
| trackingAnimRelocationVector | `Vector3` | RW | `obj.trackingAnimRelocationVector = <value>` |
| desiredMotion | `Vector3` | RW | `obj.desiredMotion = <value>` |
| moveLimit | `number` | RW | `obj.moveLimit = <value>` |
| animation | `lightuserdata` | RW | `obj.animation = <value>` |
| character | `Character` | RW | `obj.character = <value>` |
| clickHull | `lightuserdata` | RW | `obj.clickHull = <value>` |
| movementMode | `MovementMode` | RW | `obj.movementMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| _setPositionAndTeleport | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _setPositionDirectionAndTeleport | `position: Vector3, orientation: Quaternion` | `void` | `obj:_setPositionDirectionAndTeleport(position, orientation)` |
| _setPositionSimple | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| isRunning | `` | `boolean` | `obj:isRunning()` |
| isRunningAway | `from: Vector3` | `boolean` | `obj:isRunningAway(from)` |
| trackAnimationMovement | `on: boolean` | `void` | `obj:trackAnimationMovement(on)` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| handleChanged | `` | `void` | `obj:handleChanged()` |
| getRadius | `` | `number` | `obj:getRadius()` |
| update | `_TIME: number` | `void` | `obj:update(_TIME)` |
| pausedUpdate | `` | `void` | `obj:pausedUpdate()` |
| twoFrameUpdate | `_TIME: number` | `void` | `obj:twoFrameUpdate(_TIME)` |
| postAnimationUpdate | `` | `void` | `obj:postAnimationUpdate()` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| predictNextPosition | `accurate: boolean` | `Vector3` | `obj:predictNextPosition(accurate)` |
| getMaximumPossibleMovement | `` | `number` | `obj:getMaximumPossibleMovement()` |
| faceDirection | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| lookatPosition | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| pathOk | `` | `boolean` | `obj:pathOk()` |
| pathFailed | `` | `boolean` | `obj:pathFailed()` |
| isDestinationReached | `` | `boolean` | `obj:isDestinationReached()` |
| isIdle | `` | `boolean` | `obj:isIdle()` |
| playerMoveOrderWhileInCombatMode | `pos: Vector3` | `boolean` | `obj:playerMoveOrderWhileInCombatMode(pos)` |
| halt | `` | `void` | `obj:halt()` |
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
| setDestination | `dest: Vector3, who: integer, notVertical: boolean` | `void` | `obj:setDestination(dest, who, notVertical)` |
| setLookatTarget | `lookatCharacter: hand` | `void` | `obj:setLookatTarget(lookatCharacter)` |
| setMovementMode | `mode: MovementMode` | `void` | `obj:setMovementMode(mode)` |
| isStandingOnSomething | `` | `hand` | `obj:isStandingOnSomething()` |
| combatMovementOffensive | `target: hand, minDistance: number, maxDistance: number, circle: number, power: boolean, speedLimit: number` | `void` | `obj:combatMovementOffensive(target, minDistance, maxDistance, circle, power, speedLimit)` |

## CharStats
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`
**Metatable:** `KenshiLua.CharStats`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| medical | `MedicalSystem` | RW | `obj.medical = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| athleticsMultiplier | `number` | RW | `obj.athleticsMultiplier = <value>` |
| combatSpeedMultiplier | `number` | RW | `obj.combatSpeedMultiplier = <value>` |
| _skillBonusAttack | `integer` | RW | `obj._skillBonusAttack = <value>` |
| _skillBonusDefence | `integer` | RW | `obj._skillBonusDefence = <value>` |
| skillBonusIndoors | `integer` | RW | `obj.skillBonusIndoors = <value>` |
| skillBonusUnarmed | `integer` | RW | `obj.skillBonusUnarmed = <value>` |
| skillBonusPerception | `integer` | RW | `obj.skillBonusPerception = <value>` |
| ageMult | `number` | RW | `obj.ageMult = <value>` |
| skillMultDodge | `number` | RW | `obj.skillMultDodge = <value>` |
| skillMultStealth | `number` | RW | `obj.skillMultStealth = <value>` |
| skillMultAssassin | `number` | RW | `obj.skillMultAssassin = <value>` |
| skillMultDexterity | `number` | RW | `obj.skillMultDexterity = <value>` |
| skillMultDamage | `number` | RW | `obj.skillMultDamage = <value>` |
| fistInjuryEquipmentMult | `number` | RW | `obj.fistInjuryEquipmentMult = <value>` |
| skillMultRanged | `number` | RW | `obj.skillMultRanged = <value>` |
| _strength | `number` | RW | `obj._strength = <value>` |
| fitness | `number` | RW | `obj.fitness = <value>` |
| _dexterity | `number` | RW | `obj._dexterity = <value>` |
| perception | `number` | RW | `obj.perception = <value>` |
| _toughness | `number` | RW | `obj._toughness = <value>` |
| _athletics | `number` | RW | `obj._athletics = <value>` |
| medic | `number` | RW | `obj.medic = <value>` |
| massCombat | `number` | RW | `obj.massCombat = <value>` |
| arrowDefence | `number` | RW | `obj.arrowDefence = <value>` |
| stealth | `number` | RW | `obj.stealth = <value>` |
| swimming | `number` | RW | `obj.swimming = <value>` |
| thieving | `number` | RW | `obj.thieving = <value>` |
| lockpicking | `number` | RW | `obj.lockpicking = <value>` |
| bluff | `number` | RW | `obj.bluff = <value>` |
| assassin | `number` | RW | `obj.assassin = <value>` |
| survival | `number` | RW | `obj.survival = <value>` |
| tracking | `number` | RW | `obj.tracking = <value>` |
| climbing | `number` | RW | `obj.climbing = <value>` |
| doctor | `number` | RW | `obj.doctor = <value>` |
| engineer | `number` | RW | `obj.engineer = <value>` |
| weaponSmith | `number` | RW | `obj.weaponSmith = <value>` |
| armourSmith | `number` | RW | `obj.armourSmith = <value>` |
| bowSmith | `number` | RW | `obj.bowSmith = <value>` |
| robotics | `number` | RW | `obj.robotics = <value>` |
| science | `number` | RW | `obj.science = <value>` |
| labouring | `number` | RW | `obj.labouring = <value>` |
| farming | `number` | RW | `obj.farming = <value>` |
| cooking | `number` | RW | `obj.cooking = <value>` |
| dodging | `number` | RW | `obj.dodging = <value>` |
| friendlyFire | `number` | RW | `obj.friendlyFire = <value>` |
| katanas | `number` | RW | `obj.katanas = <value>` |
| sabres | `number` | RW | `obj.sabres = <value>` |
| hackers | `number` | RW | `obj.hackers = <value>` |
| blunt | `number` | RW | `obj.blunt = <value>` |
| heavyWeapons | `number` | RW | `obj.heavyWeapons = <value>` |
| unarmed | `number` | RW | `obj.unarmed = <value>` |
| bows | `number` | RW | `obj.bows = <value>` |
| turrets | `number` | RW | `obj.turrets = <value>` |
| polearms | `number` | RW | `obj.polearms = <value>` |
| currentItemMaximumJuryRig | `number` | RW | `obj.currentItemMaximumJuryRig = <value>` |
| __meleeAttack | `number` | RW | `obj.__meleeAttack = <value>` |
| _meleeDefence | `number` | RW | `obj._meleeDefence = <value>` |
| _defensiveMode | `boolean` | RW | `obj._defensiveMode = <value>` |
| rangedMode | `boolean` | RW | `obj.rangedMode = <value>` |
| tauntMode | `boolean` | RW | `obj.tauntMode = <value>` |
| _holdPositionMode | `boolean` | RW | `obj._holdPositionMode = <value>` |
| passiveCombatMode | `boolean` | RW | `obj.passiveCombatMode = <value>` |
| holdLocation | `Vector3` | RW | `obj.holdLocation = <value>` |
| warriorSpirit | `number` | RW | `obj.warriorSpirit = <value>` |
| derivedSpirit | `number` | RW | `obj.derivedSpirit = <value>` |
| aggression | `number` | RW | `obj.aggression = <value>` |
| goodness | `number` | RW | `obj.goodness = <value>` |
| evilness | `number` | RW | `obj.evilness = <value>` |
| longestReachingAttack | `number` | RW | `obj.longestReachingAttack = <value>` |
| STUBBOURNESS | `number` | RW | `obj.STUBBOURNESS = <value>` |
| PROFESSIONALNESS | `number` | RW | `obj.PROFESSIONALNESS = <value>` |
| HOLDING_POSITION | `number` | RW | `obj.HOLDING_POSITION = <value>` |
| IMMEDIACY | `number` | RW | `obj.IMMEDIACY = <value>` |
| IMMEDIACY_MAX_RANGE | `number` | RW | `obj.IMMEDIACY_MAX_RANGE = <value>` |
| MANLINESS | `number` | RW | `obj.MANLINESS = <value>` |
| MURDEROUS | `number` | RW | `obj.MURDEROUS = <value>` |
| _stealthXPMultForGUI | `number` | RW | `obj._stealthXPMultForGUI = <value>` |
| stealthXPTooManyCooksPenalty | `number` | RW | `obj.stealthXPTooManyCooksPenalty = <value>` |
| currentOperatingMachineHungerRate | `number` | RW | `obj.currentOperatingMachineHungerRate = <value>` |
| moveSpeed | `number` | RW | `obj.moveSpeed = <value>` |
| weaponWeightSpeedMult | `number` | RW | `obj.weaponWeightSpeedMult = <value>` |
| weaponWeightXPMult | `number` | RW | `obj.weaponWeightXPMult = <value>` |
| attackSpeed | `number` | RW | `obj.attackSpeed = <value>` |
| blockSpeed | `number` | RW | `obj.blockSpeed = <value>` |
| encumbranceMult | `number` | RW | `obj.encumbranceMult = <value>` |
| xp | `number` | RW | `obj.xp = <value>` |
| freeAttributePoints | `integer` | RW | `obj.freeAttributePoints = <value>` |
| cutDamageMult | `number` | RW | `obj.cutDamageMult = <value>` |
| bluntDamageMult | `number` | RW | `obj.bluntDamageMult = <value>` |
| bleedDamageMult | `number` | RW | `obj.bleedDamageMult = <value>` |
| pierceDamageMult | `number` | RW | `obj.pierceDamageMult = <value>` |
| cutDamageMin | `number` | RW | `obj.cutDamageMin = <value>` |
| bluntDamageMin | `number` | RW | `obj.bluntDamageMin = <value>` |
| bonusRobots | `number` | RW | `obj.bonusRobots = <value>` |
| bonusHumans | `number` | RW | `obj.bonusHumans = <value>` |
| bonusAnimals | `number` | RW | `obj.bonusAnimals = <value>` |
| bonusArmourPenetration | `number` | RW | `obj.bonusArmourPenetration = <value>` |
| currentWeaponType | `WeaponCategory` | RW | `obj.currentWeaponType = <value>` |
| pCurrentWeaponSkill | `lightuserdata` | RW | `obj.pCurrentWeaponSkill = <value>` |
| currentWeaponLength | `number` | RW | `obj.currentWeaponLength = <value>` |
| weapon | `hand` | RW | `obj.weapon = <value>` |
| weaponWeight | `number` | RW | `obj.weaponWeight = <value>` |
| _weatherProtections | `std::map<WeatherAffecting, float>` | RW | `obj._weatherProtections = <value>` |
| bonusRaces | `std::map<GameData*, float>` | RW | `obj.bonusRaces = <value>` |
| attacks | `lektor<CombatTechniqueData*>` | RW | `obj.attacks = <value>` |
| blocks | `lektor<CombatTechniqueData*>` | RW | `obj.blocks = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWeatherProtection | `w: WeatherAffecting` | `number` | `obj:getWeatherProtection(w)` |
| unarmedEncumbrancePenalty | `` | `integer` | `obj:unarmedEncumbrancePenalty()` |
| skillBonusUnarmed_forGUI | `factorEnvironment: boolean` | `integer` | `obj:skillBonusUnarmed_forGUI(factorEnvironment)` |
| skillBonusAttack_melee | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_melee(factorEnvironment)` |
| skillBonusAttack_unarmed | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_unarmed(factorEnvironment)` |
| skillBonusDefence | `factorEnvironment: boolean` | `integer` | `obj:skillBonusDefence(factorEnvironment)` |
| serialise | `data: GameData` | `void` | `obj:serialise(data)` |
| updateStats | `statData: GameData` | `void` | `obj:updateStats(statData)` |
| init | `data: GameData, _med: MedicalSystem, charact: Character` | `void` | `obj:init(data, _med, charact)` |
| _randomiseStats | `amount: number` | `void` | `obj:_randomiseStats(amount)` |
| getGUIData | `panel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(panel, category)` |
| getGUIDataForMainInfo | `datapanel: DatapanelGUI, category: integer, combatMode: boolean` | `void` | `obj:getGUIDataForMainInfo(datapanel, category, combatMode)` |
| getGUIStatsDisplayMode | `` | `CharStats::GUIStatsDisplayMode` | `obj:getGUIStatsDisplayMode()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| calculateStumbleThresholdDamageAmount | `` | `number` | `obj:calculateStumbleThresholdDamageAmount()` |
| setEquipmentStatBonuses | `athlet: number, combatSpd: number, attack: integer, def: integer, _stealth: number, _unarmed: integer, _dodge: number, fistdamage: number, perception: integer, ranged: number, dexmult: number, assmult: number, damagemult: number` | `void` | `obj:setEquipmentStatBonuses(athlet, combatSpd, attack, def, _stealth, _unarmed, _dodge, fistdamage, perception, ranged, dexmult, assmult, damagemult)` |
| getOverallSkillLevel_0_100 | `` | `number` | `obj:getOverallSkillLevel_0_100()` |
| getStat | `what: StatsEnumerated, unmodified: boolean` | `number` | `obj:getStat(what, unmodified)` |
| getStatMultiplier | `st: StatsEnumerated` | `number` | `obj:getStatMultiplier(st)` |
| getStatMultiplierForGUI | `st: StatsEnumerated` | `string` | `obj:getStatMultiplierForGUI(st)` |
| getStatPenaltiesTotalForGUI | `statName: string, stat: StatsEnumerated` | `integer` | `obj:getStatPenaltiesTotalForGUI(statName, stat)` |
| xpStat_timeBased | `st: StatsEnumerated` | `void` | `obj:xpStat_timeBased(st)` |
| xpStat_eventBased | `st: StatsEnumerated, amount: number` | `void` | `obj:xpStat_eventBased(st, amount)` |
| xpDodgeEvent | `enemySkill: number, successful: boolean` | `void` | `obj:xpDodgeEvent(enemySkill, successful)` |
| strengthActual | `` | `number` | `obj:strengthActual()` |
| strengthBase | `` | `number` | `obj:strengthBase()` |
| dexterityBase | `` | `number` | `obj:dexterityBase()` |
| dexterityActual | `` | `number` | `obj:dexterityActual()` |
| toughness | `` | `number` | `obj:toughness()` |
| getToughnessMult | `` | `number` | `obj:getToughnessMult()` |
| getRangedFriendlyFireAvoidanceChance | `` | `number` | `obj:getRangedFriendlyFireAvoidanceChance()` |
| getRangedAccuracyMult | `stat: StatsEnumerated` | `number` | `obj:getRangedAccuracyMult(stat)` |
| getReloadSkill | `stat: StatsEnumerated` | `number` | `obj:getReloadSkill(stat)` |
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
| getMaxHealAmount | `equipment: Item, bed: Building, isRobot: boolean` | `number` | `obj:getMaxHealAmount(equipment, bed, isRobot)` |
| isDefensiveMode | `` | `boolean` | `obj:isDefensiveMode()` |
| holdPositionMode | `` | `boolean` | `obj:holdPositionMode()` |
| setHoldLocation | `v: Vector3` | `void` | `obj:setHoldLocation(v)` |
| clearHoldLocation | `` | `void` | `obj:clearHoldLocation()` |
| getBashAnimation | `range: number` | `CombatTechniqueData` | `obj:getBashAnimation(range)` |
| chooseAttack | `range: number, weaponReach: number, lastAttack: CombatTechniqueData, opponentIsStationary: boolean` | `CombatTechniqueData` | `obj:chooseAttack(range, weaponReach, lastAttack, opponentIsStationary)` |
| chooseBlock | `dir: CutDirection, opponentAttackSkill: number, from: CutOrigination, opponent: Character` | `CombatTechniqueData` | `obj:chooseBlock(dir, opponentAttackSkill, from, opponent)` |
| calculateStumbleBlockTimer | `stumbleForce: number` | `number` | `obj:calculateStumbleBlockTimer(stumbleForce)` |
| calculateTechniqueInegrityCheckTimer | `` | `number` | `obj:calculateTechniqueInegrityCheckTimer()` |
| calculateToughnessDamageResistanceMult | `` | `number` | `obj:calculateToughnessDamageResistanceMult()` |
| calculateToughnessWoundDegenerationRate | `` | `number` | `obj:calculateToughnessWoundDegenerationRate()` |
| getAttackChance | `` | `number` | `obj:getAttackChance()` |
| getAttackCuttingDamage | `` | `number` | `obj:getAttackCuttingDamage()` |
| getAttackBluntPower | `` | `number` | `obj:getAttackBluntPower()` |
| getAttackBleedDamageMult | `` | `number` | `obj:getAttackBleedDamageMult()` |
| getAttackPierceDamage | `` | `number` | `obj:getAttackPierceDamage()` |
| getTotalAttackDamageFor | `target: Character` | `Damages` | `obj:getTotalAttackDamageFor(target)` |
| getEquippedWeaponSkill | `` | `number` | `obj:getEquippedWeaponSkill()` |
| getSkillDifferenceRatio | `mine: number, his: number` | `number` | `obj:getSkillDifferenceRatio(mine, his)` |
| calculateDeadTime | `state: CharStats::DeadTimeState` | `number` | `obj:calculateDeadTime(state)` |
| xpToughness_RagdollEvent | `` | `void` | `obj:xpToughness_RagdollEvent()` |
| xpToughness_GetUpEvent | `` | `void` | `obj:xpToughness_GetUpEvent()` |
| xpToughness_PunchSomething | `mat: HitMaterialType` | `void` | `obj:xpToughness_PunchSomething(mat)` |
| xpFirstAid | `patient: Character, time: number, medicStat: StatsEnumerated` | `void` | `obj:xpFirstAid(patient, time, medicStat)` |
| xpRunning | `time: number, speed: number` | `void` | `obj:xpRunning(time, speed)` |
| xpStealth | `time: number, enemiesAbout: boolean, seen: YesNoMaybe, isMoving: boolean` | `void` | `obj:xpStealth(time, enemiesAbout, seen, isMoving)` |
| xpStealthHearCheckEvent | `enemiesAbout: boolean, trespassing: boolean, seen: boolean` | `void` | `obj:xpStealthHearCheckEvent(enemiesAbout, trespassing, seen)` |
| stealthXPMultForGUI | `` | `StringPair` | `obj:stealthXPMultForGUI()` |
| xpMassCombat | `` | `void` | `obj:xpMassCombat()` |
| xpEngineering | `time: number` | `void` | `obj:xpEngineering(time)` |
| xpLockpicking | `lockLevel: integer, success: boolean` | `void` | `obj:xpLockpicking(lockLevel, success)` |
| xpGeneral | `time: number, mult: number, what: StatsEnumerated` | `void` | `obj:xpGeneral(time, mult, what)` |
| calculateAthleticsXPMult | `speed: number` | `number` | `obj:calculateAthleticsXPMult(speed)` |
| calculateStrengthXPMultFromWalking | `` | `number` | `obj:calculateStrengthXPMultFromWalking()` |
| setWeapon | `_weapon: Weapon` | `void` | `obj:setWeapon(_weapon)` |
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
| currentWeaponHand | `` | `LeftRight` | `obj:currentWeaponHand()` |
| calculateAttackOrBlockSpeed | `weaponWeightSpeedMult: number, attackOrBlockSkill: number, isBlock: boolean` | `number` | `obj:calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock)` |
| _calculateBlockChance | `versus: number` | `number` | `obj:_calculateBlockChance(versus)` |
| _recalculateStats | `` | `void` | `obj:_recalculateStats()` |
| setEquippedWeaponSkill | `v: number` | `void` | `obj:setEquippedWeaponSkill(v)` |
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
| formatWholeStatStringWithBonuses [1] | `base: integer, current: integer` | `string` | `obj:formatWholeStatStringWithBonuses(base, current)` |
| formatWholeStatStringWithBonuses [2] | `stat: StatsEnumerated` | `string` | `obj:formatWholeStatStringWithBonuses(stat)` |
| getStatRef | `what: StatsEnumerated` | `number` | `obj:getStatRef(what)` |
| getMeleeAttackRef | `` | `number` | `obj:getMeleeAttackRef()` |
| getPainAnim | `anatomyHit: GameData` | `void` | `obj:getPainAnim(anatomyHit)` |
| xpMelee | `what: CharStats::DeadTimeState, target: Character, damage: Damages` | `void` | `obj:xpMelee(what, target, damage)` |
| getStealthTooltip | `dats: lektor<StringPair>` | `void` | `obj:getStealthTooltip(dats)` |
| getAthleticsTooltip | `dats: lektor<StringPair>` | `void` | `obj:getAthleticsTooltip(dats)` |
| getStatPenaltiesForGUI | `statName: string, stat: StatsEnumerated, dats: lektor<StringPair>` | `boolean` | `obj:getStatPenaltiesForGUI(statName, stat, dats)` |
| chooseAttacks [1] | `lastAttack: CombatTechniqueData` | `void` | `obj:chooseAttacks(lastAttack)` |
| chooseAttacks [2] | `range: number, weaponReach: number, lastAttack: CombatTechniqueData, opponentIsStationary: boolean, skipMedicals: boolean, _weaponType: WeaponCategory, _weaponSkill: number` | `void` | `obj:chooseAttacks(range, weaponReach, lastAttack, opponentIsStationary, skipMedicals, _weaponType, _weaponSkill)` |
| printExertionHungerMultTooltip | `dats: lektor<StringPair>` | `void` | `obj:printExertionHungerMultTooltip(dats)` |
| xpTraining | `time: number, mult: number, statVal: number, upperLimit: number, whatStatIsIt: StatsEnumerated` | `number` | `obj:xpTraining(time, mult, statVal, upperLimit, whatStatIsIt)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getStatName | `what: StatsEnumerated` | `void` | `CharStats.getStatName(what)`<br>`obj:getStatName(what)` |
| convertWeaponWeightToBluntMultiplier | `` | `number` | `CharStats.convertWeaponWeightToBluntMultiplier()`<br>`obj:convertWeaponWeightToBluntMultiplier()` |
| convertBluntMultiplierToWeaponWeight | `` | `number` | `CharStats.convertBluntMultiplierToWeaponWeight()`<br>`obj:convertBluntMultiplierToWeaponWeight()` |
| setupCombatTechniques | `` | `void` | `CharStats.setupCombatTechniques()`<br>`obj:setupCombatTechniques()` |

## CombatClass
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Metatable:** `KenshiLua.CombatClass`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| attackSlots | `CombatClass::AttackSlotManager` | RW | `obj.attackSlots = <value>` |
| wantsToBlock | `boolean` | RW | `obj.wantsToBlock = <value>` |
| isStumbleBlocking | `boolean` | RW | `obj.isStumbleBlocking = <value>` |
| stumbleTimer | `number` | RW | `obj.stumbleTimer = <value>` |
| whenCanStopStumble | `number` | RW | `obj.whenCanStopStumble = <value>` |
| stumbleForce | `number` | RW | `obj.stumbleForce = <value>` |
| combatModeActive | `boolean` | RW | `obj.combatModeActive = <value>` |
| lastCombatModeTimeStamp | `number` | RW | `obj.lastCombatModeTimeStamp = <value>` |
| _isAttacking | `number` | RW | `obj._isAttacking = <value>` |
| inDeadTime | `boolean` | RW | `obj.inDeadTime = <value>` |
| deadTimer | `number` | RW | `obj.deadTimer = <value>` |
| stateTimer | `number` | RW | `obj.stateTimer = <value>` |
| currentTechnique | `CombatTechniqueData` | RW | `obj.currentTechnique = <value>` |
| currentTechniqueHasFinished | `boolean` | RW | `obj.currentTechniqueHasFinished = <value>` |
| attackStartPos | `Vector3` | RW | `obj.attackStartPos = <value>` |
| frameTIME | `number` | RW | `obj.frameTIME = <value>` |
| movement | `CharMovement` | RW | `obj.movement = <value>` |
| ai | `lightuserdata` | RW | `obj.ai = <value>` |
| animation | `lightuserdata` | RW | `obj.animation = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| medical | `MedicalSystem` | RW | `obj.medical = <value>` |
| myRadiusX | `number` | RW | `obj.myRadiusX = <value>` |
| blockingTarget | `Character` | RW | `obj.blockingTarget = <value>` |
| blockingTargetH | `hand` | RW | `obj.blockingTargetH = <value>` |
| targetsInAttackZone | `lektor<hand>` | RW | `obj.targetsInAttackZone = <value>` |
| attackersH | `lektor<hand>` | RW | `obj.attackersH = <value>` |
| threats | `lektor<Character*>` | RW | `obj.threats = <value>` |
| threatsH | `lektor<hand>` | RW | `obj.threatsH = <value>` |
| notifiedThreats | `lektor<hand>` | RW | `obj.notifiedThreats = <value>` |
| lastIncomingAttackComboSection | `integer` | RW | `obj.lastIncomingAttackComboSection = <value>` |
| calculatedTargetsInAttackZoneThisFrame | `boolean` | RW | `obj.calculatedTargetsInAttackZoneThisFrame = <value>` |
| combatState | `swordStateEnum` | RW | `obj.combatState = <value>` |
| nextMove | `swordStateEnum` | RW | `obj.nextMove = <value>` |
| numEnemiesWaitingForMe1 | `integer` | RW | `obj.numEnemiesWaitingForMe1 = <value>` |
| numEnemiesWaitingForMe2 | `integer` | RW | `obj.numEnemiesWaitingForMe2 = <value>` |
| waitCountAlternator | `boolean` | RW | `obj.waitCountAlternator = <value>` |
| currentComboSection | `integer` | RW | `obj.currentComboSection = <value>` |
| lastComboSection | `integer` | RW | `obj.lastComboSection = <value>` |
| lastSoundIndex | `integer` | RW | `obj.lastSoundIndex = <value>` |
| techniqueIntegrityCheckTimer | `number` | RW | `obj.techniqueIntegrityCheckTimer = <value>` |
| MEI_MIN | `number` | RW | `obj.MEI_MIN = <value>` |
| MEI_MAX | `number` | RW | `obj.MEI_MAX = <value>` |
| MINIMUM_DISTANCE_TO_OTHERS | `number` | RW | `obj.MINIMUM_DISTANCE_TO_OTHERS = <value>` |
| BLOCKING_MEI_DISTANCE_MIN | `number` | RW | `obj.BLOCKING_MEI_DISTANCE_MIN = <value>` |
| BLOCKING_MEI_DISTANCE_MAX | `number` | RW | `obj.BLOCKING_MEI_DISTANCE_MAX = <value>` |
| currentTarget | `Character` | RW | `obj.currentTarget = <value>` |
| currentTargetHandle | `hand` | RW | `obj.currentTargetHandle = <value>` |
| stateMap | `ogre_unordered_map<swordStateEnum, CombatState*>` | RW | `obj.stateMap = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isAI | `` | `boolean` | `obj:isAI()` |
| initCombatMode | `subject: hand, end: integer, focusedTarget: boolean` | `boolean` | `obj:initCombatMode(subject, end, focusedTarget)` |
| go | `_frameTime: number` | `void` | `obj:go(_frameTime)` |
| getCombatState | `` | `swordStateEnum` | `obj:getCombatState()` |
| getBlockStateEnum | `` | `swordStateEnum` | `obj:getBlockStateEnum()` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| whoAttacksYouOrMe | `attacker: Character, dist: number` | `integer\|number` | `obj:whoAttacksYouOrMe(attacker, dist)` |
| _iHitYouAreYouHit | `dir: CutDirection, damage: Damages, who: Character` | `HitMaterialType` | `obj:_iHitYouAreYouHit(dir, damage, who)` |
| _getHit | `dir: CutDirection, damage: Damages, who: RootObject, stumble: boolean` | `void` | `obj:_getHit(dir, damage, who, stumble)` |
| _blockHit | `dir: CutDirection, damage: Damages, who: RootObject` | `void` | `obj:_blockHit(dir, damage, who)` |
| isAttacking | `who: Character` | `number` | `obj:isAttacking(who)` |
| informOfFreeAttackSlot | `_a1: Character` | `void` | `obj:informOfFreeAttackSlot(_a1)` |
| isStationary | `` | `boolean` | `obj:isStationary()` |
| _getAttackTarget | `` | `hand` | `obj:_getAttackTarget()` |
| isFightingAnAllyOfMine | `who: Character` | `boolean` | `obj:isFightingAnAllyOfMine(who)` |
| getCurrentTechnique | `` | `CombatTechniqueData` | `obj:getCurrentTechnique()` |
| getCurrentTechniqueSection | `` | `integer` | `obj:getCurrentTechniqueSection()` |
| getMeiMin | `` | `number` | `obj:getMeiMin()` |
| areYouFightingAndInNeedOfHelp | `` | `number` | `obj:areYouFightingAndInNeedOfHelp()` |
| getAttackers | `` | `lektor<hand>` | `obj:getAttackers()` |
| getNumOpponents | `` | `integer` | `obj:getNumOpponents()` |
| getTotalRelativeStrengthOfAttackers | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _isInCombatMode | `` | `boolean` | `obj:_isInCombatMode()` |
| checkForBadHandles | `` | `void` | `obj:checkForBadHandles()` |
| addAttackerH | `c: Character` | `boolean` | `obj:addAttackerH(c)` |
| isInAttackerListH | `c: Character` | `boolean` | `obj:isInAttackerListH(c)` |
| removeAttackerH | `c: Character` | `boolean` | `obj:removeAttackerH(c)` |
| youDoKnowImAttackingYouRight | `h: hand` | `void` | `obj:youDoKnowImAttackingYouRight(h)` |
| getAttackAimAdjustmentThreshold | `target: Character` | `number` | `obj:getAttackAimAdjustmentThreshold(target)` |
| getNumWaitingAttackers | `` | `integer` | `obj:getNumWaitingAttackers()` |
| readyToFinishCombatMode | `` | `boolean` | `obj:readyToFinishCombatMode()` |
| getTimeSinceLastCombatModeInHours | `` | `number` | `obj:getTimeSinceLastCombatModeInHours()` |
| hasFocusedTarget | `` | `hand` | `obj:hasFocusedTarget()` |
| changeState | `newState: swordStateEnum, minTime: number` | `void` | `obj:changeState(newState, minTime)` |
| getStateClass | `state: swordStateEnum` | `lightuserdata` | `obj:getStateClass(state)` |
| update [1] | `` | `void` | `obj:update()` |
| update [2] | `frameTIME: number` | `void` | `obj:update(frameTIME)` |
| getMeiMax | `` | `number` | `obj:getMeiMax()` |
| startupState | `` | `boolean` | `obj:startupState()` |
| stumbleState | `` | `void` | `obj:stumbleState()` |
| _isAttackingUpdate | `` | `number` | `obj:_isAttackingUpdate()` |
| canBlock | `` | `boolean` | `obj:canBlock()` |
| attackState | `` | `boolean` | `obj:attackState()` |
| checkForNeedBlock | `thresholdMyAttack: number, thresholdIncomingAttack: number` | `boolean` | `obj:checkForNeedBlock(thresholdMyAttack, thresholdIncomingAttack)` |
| setCombatState | `state: swordStateEnum` | `void` | `obj:setCombatState(state)` |
| initialiseBlock | `isStumbling: boolean` | `boolean` | `obj:initialiseBlock(isStumbling)` |
| blockState | `stumbleBlocking: boolean` | `boolean` | `obj:blockState(stumbleBlocking)` |
| blockWaitingState | `` | `void` | `obj:blockWaitingState()` |
| attackImpactCheck | `` | `void` | `obj:attackImpactCheck()` |
| calculateTargetsInAttackZone | `` | `void` | `obj:calculateTargetsInAttackZone()` |
| isInAttackZone | `who: Character` | `boolean` | `obj:isInAttackZone(who)` |
| getNearestEnemyInAttackZone | `` | `Character` | `obj:getNearestEnemyInAttackZone()` |
| assessIncomingAttacks | `outLektor: lektor<Character*>` | `void` | `obj:assessIncomingAttacks(outLektor)` |
| notifyBlockNeeded | `` | `void` | `obj:notifyBlockNeeded()` |
| calculateCurrentTechniqueSection | `` | `integer\|number` | `obj:calculateCurrentTechniqueSection()` |
| weaponReach | `` | `number` | `obj:weaponReach()` |
| getBiggestThreat | `list: lektor<Character*>, minThreshold: number` | `Character` | `obj:getBiggestThreat(list, minThreshold)` |
| gotMoreImportantThingsToDoThanFightingYou | `who: Character` | `boolean` | `obj:gotMoreImportantThingsToDoThanFightingYou(who)` |
| setAttackTarget | `c: Character` | `void` | `obj:setAttackTarget(c)` |
| setAttackTargetHandle | `c: Character` | `void` | `obj:setAttackTargetHandle(c)` |
| lookatTarget | `target: Character` | `void` | `obj:lookatTarget(target)` |
| packPtrsToHandles | `` | `void` | `obj:packPtrsToHandles()` |
| unpackHandlesToPtrs | `` | `void` | `obj:unpackHandlesToPtrs()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `` | `void` | `CombatClass.setup()`<br>`obj:setup()` |
| destroy | `` | `void` | `CombatClass.destroy()`<br>`obj:destroy()` |
| getCombatEffect | `` | `GameData` | `CombatClass.getCombatEffect()`<br>`obj:getCombatEffect()` |
| addEffect | `` | `void` | `CombatClass.addEffect()`<br>`obj:addEffect()` |
| shiftEffects | `` | `void` | `CombatClass.shiftEffects()`<br>`obj:shiftEffects()` |
| updateEffects | `` | `void` | `CombatClass.updateEffects()`<br>`obj:updateEffects()` |

## CombatClass::AttackSlotManager
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Parent Class:** [`CombatClass`](#combatclass)
**Metatable:** `KenshiLua.AttackSlotManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | `Character` | RW | `obj.me = <value>` |
| combatClass | `CombatClass` | RW | `obj.combatClass = <value>` |
| attackSlotH | `hand` | RW | `obj.attackSlotH = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hasFreeAttackSlot | `` | `boolean` | `obj:hasFreeAttackSlot()` |
| freeSlotH | `who: hand` | `void` | `obj:freeSlotH(who)` |
| freeAllSlotsH | `` | `void` | `obj:freeAllSlotsH()` |
| addToSlotH | `who: hand` | `boolean` | `obj:addToSlotH(who)` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| update | `` | `void` | `obj:update()` |
| getNumAttackSlots | `` | `integer` | `obj:getNumAttackSlots()` |
| getMaxPossibleAttackSlots | `` | `integer` | `obj:getMaxPossibleAttackSlots()` |

## CombatClass::AttackSlotManager::SlotData
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Parent Class:** [`CombatClass`](#combatclass)
**Metatable:** `KenshiLua.CombatClass_AttackSlotManager_SlotData`

## CombatClass::EffectData
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Parent Class:** [`CombatClass`](#combatclass)
**Metatable:** `KenshiLua.CombatClass_EffectData`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## CombatMovementController
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.CombatMovementController`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| movement | `CharMovement` | RW | `obj.movement = <value>` |
| chaseMode | `boolean` | RW | `obj.chaseMode = <value>` |
| chaseStateTimer | `number` | RW | `obj.chaseStateTimer = <value>` |
| hasForcedWP | `boolean` | RW | `obj.hasForcedWP = <value>` |
| forcedWP | `Vector3` | RW | `obj.forcedWP = <value>` |
| flockFilterX | `MotionFilter` | RW | `obj.flockFilterX = <value>` |
| flockFilterZ | `MotionFilter` | RW | `obj.flockFilterZ = <value>` |
| flockingControl | `FlockingTools` | RW | `obj.flockingControl = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| radius | `number` | RW | `obj.radius = <value>` |
| jogMode | `boolean` | RW | `obj.jogMode = <value>` |
| TOTALREPULSION_DAMPING | `number` | RW | `obj.TOTALREPULSION_DAMPING = <value>` |
| STRAFE_STATE_DAMPING | `number` | RW | `obj.STRAFE_STATE_DAMPING = <value>` |
| STRAFE_THRESHOLD | `number` | RW | `obj.STRAFE_THRESHOLD = <value>` |
| FORWARD_THRESHOLD | `number` | RW | `obj.FORWARD_THRESHOLD = <value>` |
| MIN_RANGE_FW | `number` | RW | `obj.MIN_RANGE_FW = <value>` |
| ENEMY_DIST | `number` | RW | `obj.ENEMY_DIST = <value>` |
| ALLY_DIST | `number` | RW | `obj.ALLY_DIST = <value>` |
| STOP_THRESHOLD | `number` | RW | `obj.STOP_THRESHOLD = <value>` |
| START_THRESHOLD | `number` | RW | `obj.START_THRESHOLD = <value>` |
| ACCEL_RATE_COMBATMODE | `number` | RW | `obj.ACCEL_RATE_COMBATMODE = <value>` |
| meiMin | `number` | RW | `obj.meiMin = <value>` |
| circlingSpeed | `number` | RW | `obj.circlingSpeed = <value>` |
| combatMinDistance | `number` | RW | `obj.combatMinDistance = <value>` |
| combatMaxDistance | `number` | RW | `obj.combatMaxDistance = <value>` |
| strafeStateTimer | `number` | RW | `obj.strafeStateTimer = <value>` |
| strafing | `boolean` | RW | `obj.strafing = <value>` |
| powerThrough | `boolean` | RW | `obj.powerThrough = <value>` |
| canStrafe | `boolean` | RW | `obj.canStrafe = <value>` |
| speedLimit | `number` | RW | `obj.speedLimit = <value>` |
| currentAccelSpeed | `number` | RW | `obj.currentAccelSpeed = <value>` |
| lookAtCharacter | `hand` | RW | `obj.lookAtCharacter = <value>` |
| combatTarget | `hand` | RW | `obj.combatTarget = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| collisionUpdate | `time: number` | `void` | `obj:collisionUpdate(time)` |
| chasingModeCheck | `whoTarget: Character` | `boolean` | `obj:chasingModeCheck(whoTarget)` |
| create | `flock: FlockingTools, move: CharMovement, med: CharStats, strafe: boolean` | `void` | `obj:create(flock, move, med, strafe)` |
| areTherePeopleInMyWay | `` | `boolean` | `obj:areTherePeopleInMyWay()` |
| addACharacterObstruction | `c: Character` | `void` | `obj:addACharacterObstruction(c)` |
| setupCombatMovementVariables | `me: Character` | `void` | `obj:setupCombatMovementVariables(me)` |
| combatMovementUpdate | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: swordStateEnum, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| combatMovementUpdate_crippleMode | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: swordStateEnum, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate_crippleMode(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| getUrgentVelocities | `pos: Vector3, facingDir: Vector3` | `Vector3` | `obj:getUrgentVelocities(pos, facingDir)` |
| checkWeDontCollideWithCharacters | `pos: Vector3, newpos: Vector3` | `void` | `obj:checkWeDontCollideWithCharacters(pos, newpos)` |
| checkCharacterCollision | `pos: Vector3, movement: Vector3` | `boolean` | `obj:checkCharacterCollision(pos, movement)` |
| setForcedWP | `v: Vector3` | `void` | `obj:setForcedWP(v)` |
| getGUIData | `panel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(panel, category)` |
| disable | `` | `void` | `obj:disable()` |

## CombatTechniqueData
**Header:** `extern/KenshiLib/Include/kenshi/CombatTechniqueData.h`
**Metatable:** `KenshiLua.CombatTechniqueData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| animation | `string` | RW | `obj.animation = <value>` |
| animSpeedMultiplier | `number` | RW | `obj.animSpeedMultiplier = <value>` |
| isBlock | `boolean` | RW | `obj.isBlock = <value>` |
| isDodge | `boolean` | RW | `obj.isDodge = <value>` |
| stumbleDodge | `boolean` | RW | `obj.stumbleDodge = <value>` |
| gainsGround | `boolean` | RW | `obj.gainsGround = <value>` |
| isProne | `boolean` | RW | `obj.isProne = <value>` |
| lowStrike | `boolean` | RW | `obj.lowStrike = <value>` |
| hesitationPoint | `number` | RW | `obj.hesitationPoint = <value>` |
| initialDistance | `number` | RW | `obj.initialDistance = <value>` |
| minDistanceVsStatic | `number` | RW | `obj.minDistanceVsStatic = <value>` |
| acceptableEndTime01 | `number` | RW | `obj.acceptableEndTime01 = <value>` |
| minSkill | `number` | RW | `obj.minSkill = <value>` |
| maxSkill | `number` | RW | `obj.maxSkill = <value>` |
| maxEncumbrance | `number` | RW | `obj.maxEncumbrance = <value>` |
| chanceMult | `number` | RW | `obj.chanceMult = <value>` |
| maxTargetHits | `integer` | RW | `obj.maxTargetHits = <value>` |
| events | `ogre_unordered_map<GameData*, float>::type` | RW | `obj.events = <value>` |
| skillTypes | `unknown` | R | `obj.skillTypes` |
| impactPoints | `lektor<CombatTechniqueData::ImpactPoint>` | R | `obj.impactPoints` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hasSkillType | `type: WeaponCategory` | `boolean` | `obj:hasSkillType(type)` |
| numImpactPoints | `` | `integer` | `obj:numImpactPoints()` |
| impactPoint | `i: integer` | `CombatTechniqueData::ImpactPoint` | `obj:impactPoint(i)` |

## CombatTechniqueData::ImpactPoint
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Parent Class:** [`CombatTechniqueData`](#combattechniquedata)
**Metatable:** `KenshiLua.ImpactPoint`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| direction | `CutDirection` | RW | `obj.direction = <value>` |
| power | `number` | RW | `obj.power = <value>` |
| impactAnimationFrame | `number` | RW | `obj.impactAnimationFrame = <value>` |
| motionStopsAnimationFrame | `number` | RW | `obj.motionStopsAnimationFrame = <value>` |
| limb | `RobotLimbs::Limb` | RW | `obj.limb = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: ImpactPoint` | `void` | `obj:operator_assign(other)` |

## ContainerItem
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`
**Metatable:** `KenshiLua.ContainerItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| callbackOwner | `RootObject` | RW | `obj.callbackOwner = <value>` |
| athleticsMult | `number` | RW | `obj.athleticsMult = <value>` |
| weightMult | `number` | RW | `obj.weightMult = <value>` |
| combatSpeedMult | `number` | RW | `obj.combatSpeedMult = <value>` |
| combatSkillBonus | `integer` | RW | `obj.combatSkillBonus = <value>` |
| stealthMult | `number` | RW | `obj.stealthMult = <value>` |
| inventory | `Inventory` | RW | `obj.inventory = <value>` |
| racesExclude | `ogre_unordered_set<GameData*>::type` | RW | `obj.racesExclude = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getClassType | `` | `integer` | `obj:getClassType()` |
| canEquip | `race: GameData` | `boolean` | `obj:canEquip(race)` |
| equipItem | `what: string, who: Item` | `void` | `obj:equipItem(what, who)` |
| unequipItem | `what: string, item: Item` | `void` | `obj:unequipItem(what, item)` |
| dropItem | `what: RootObject` | `void` | `obj:dropItem(what)` |
| takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| doubleCheckHandle | `` | `void` | `obj:doubleCheckHandle()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _serialise | `container: GameDataContainer, type: itemType` | `GameData` | `obj:_serialise(container, type)` |
| _loadFromSerialise | `container: GameDataContainer, state: GameData` | `void` | `obj:_loadFromSerialise(container, state)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| setProperOwner | `h: hand` | `void` | `obj:setProperOwner(h)` |

## ContextMenu
**Header:** `extern/KenshiLib/Include/kenshi/gui/ContextMenu.h`
**Metatable:** `KenshiLua.ContextMenu`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| rightMouseActivated | `boolean` | RW | `obj.rightMouseActivated = <value>` |
| orders | `unknown` | RW | `obj.orders = <value>` |
| contextMenuName | `string` | RW | `obj.contextMenuName = <value>` |
| menuGUI | `ContextMenuGUI` | RW | `obj.menuGUI = <value>` |
| menuGUI2 | `ContextMenuGUI` | RW | `obj.menuGUI2 = <value>` |
| delayedDestroyFlag | `boolean` | RW | `obj.delayedDestroyFlag = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| showContextMenu | `on: boolean, what: RootObject` | `void` | `obj:showContextMenu(on, what)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| update | `` | `void` | `obj:update()` |
| _destroyMenuGUICheck | `` | `void` | `obj:_destroyMenuGUICheck()` |

## ContextMenuGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ContextMenu.h`
**Metatable:** `KenshiLua.ContextMenuGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| contextMenuTarget | `hand` | RW | `obj.contextMenuTarget = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| nameText | `MyGUI::Widget` | RW | `obj.nameText = <value>` |
| optionsList | `MyGUI::Widget` | RW | `obj.optionsList = <value>` |
| optionCoords | `MyGUI::IntCoord` | RW | `obj.optionCoords = <value>` |
| buttonCoords | `MyGUI::IntCoord` | RW | `obj.buttonCoords = <value>` |
| valueCoords | `MyGUI::IntCoord` | RW | `obj.valueCoords = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getMainWidget | `` | `MyGUI::Widget` | `obj:getMainWidget()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| show | `ordersList: lektor<int>, name: string, offset: boolean` | `void` | `obj:show(ordersList, name, offset)` |
| optionSelected | `sender: MyGUI::Widget, left: integer, top: integer, id: integer` | `void` | `obj:optionSelected(sender, left, top, id)` |

## CPerfTimer
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`
**Metatable:** `KenshiLua.CPerfTimer`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `b: CPerfTimer` | `void` | `obj:operator_assign(b)` |
| operator_add | `b: CPerfTimer` | `CPerfTimer` | `obj:operator_add(b)` |
| operator_sub | `b: CPerfTimer` | `CPerfTimer` | `obj:operator_sub(b)` |
| operator_add_assign | `b: CPerfTimer` | `void` | `obj:operator_add_assign(b)` |
| operator_sub_assign | `b: CPerfTimer` | `void` | `obj:operator_sub_assign(b)` |
| operator_lt | `b: CPerfTimer` | `boolean` | `obj:operator_lt(b)` |
| operator_le | `b: CPerfTimer` | `boolean` | `obj:operator_le(b)` |
| operator_gt | `b: CPerfTimer` | `boolean` | `obj:operator_gt(b)` |
| operator_ge | `b: CPerfTimer` | `boolean` | `obj:operator_ge(b)` |
| Start | `bReset: boolean` | `void` | `obj:Start(bReset)` |
| Stop | `` | `void` | `obj:Stop()` |
| IsRunning | `` | `boolean` | `obj:IsRunning()` |
| IsSupported | `` | `boolean` | `obj:IsSupported()` |
| Resolution | `` | `number` | `obj:Resolution()` |
| Resolutionms | `` | `number` | `obj:Resolutionms()` |
| Resolutionus | `` | `number` | `obj:Resolutionus()` |
| Elapsed | `` | `number` | `obj:Elapsed()` |
| Elapsedms | `` | `number` | `obj:Elapsedms()` |
| Elapsedus | `` | `number` | `obj:Elapsedus()` |

## CPerfTimerT
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`
**Metatable:** `KenshiLua.CPerfTimerT`

## CraftingBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`
**Metatable:** `KenshiLua.CraftingBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| maxCraftLevel | `integer` | RW | `obj.maxCraftLevel = <value>` |
| crafting | `std::deque<CraftingItem>` | RW | `obj.crafting = <value>` |
| specialCraftItemType | `itemType` | RW | `obj.specialCraftItemType = <value>` |
| repeat | `boolean` | RW | `obj.repeat = <value>` |
| whosCrafting | `hand` | RW | `obj.whosCrafting = <value>` |
| itemCrafted | `boolean` | RW | `obj.itemCrafted = <value>` |
| failiureNotified | `boolean` | RW | `obj.failiureNotified = <value>` |
| biggestCraftableItem | `GameData` | RW | `obj.biggestCraftableItem = <value>` |
| outItem | `Item` | RW | `obj.outItem = <value>` |
| inItems | `lektor<Item*>` | RW | `obj.inItems = <value>` |
| partialItems | `ogre_unordered_map<GameData*, float>::type` | RW | `obj.partialItems = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| update | `` | `void` | `obj:update()` |
| operate | `stats: Character, amount: number` | `void` | `obj:operate(stats, amount)` |
| givePower | `amount: number` | `void` | `obj:givePower(amount)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| loadFromSerialise | `wholeState: GameSaveState` | `void` | `obj:loadFromSerialise(wholeState)` |
| hasCraftingQueued | `` | `boolean` | `obj:hasCraftingQueued()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| getProductionItemData | `` | `GameData` | `obj:getProductionItemData()` |
| getCurrentProductionQuantity | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| isAnyInputsInvalidType | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| newCraftingButton | `` | `void` | `obj:newCraftingButton()` |
| addFinishedCraftItem | `what: Item` | `void` | `obj:addFinishedCraftItem(what)` |
| notifyCraftFailiure | `` | `void` | `obj:notifyCraftFailiure()` |
| tryOperate | `h: hand` | `boolean` | `obj:tryOperate(h)` |
| getAvailableCrafts | `` | `void` | `obj:getAvailableCrafts()` |
| _addCraft | `basedata: GameData, matdata: GameData, progress: number, crit: YesNoMaybe` | `lightuserdata` | `obj:_addCraft(basedata, matdata, progress, crit)` |
| _removeCraft | `index: integer` | `void` | `obj:_removeCraft(index)` |
| getCraft | `id: integer` | `lightuserdata` | `obj:getCraft(id)` |
| destroyProductionItem | `` | `void` | `obj:destroyProductionItem()` |
| predictCraftersBestWeapon | `who: hand, levelcap: integer` | `GameData` | `obj:predictCraftersBestWeapon(who, levelcap)` |
| calculateCriticalChance | `smith: Character` | `number` | `obj:calculateCriticalChance(smith)` |
| getCriticalSuccessWeapon | `normalWeaponLevel: integer` | `GameData` | `obj:getCriticalSuccessWeapon(normalWeaponLevel)` |
| getItemsWeWantRidOf | `looting: boolean` | `void` | `obj:getItemsWeWantRidOf(looting)` |
| canHaveSomeOfThese | `these: GameData` | `boolean` | `obj:canHaveSomeOfThese(these)` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| getPlayerCraftedWeaponLevel | `matspec: GameData` | `number` | `obj:getPlayerCraftedWeaponLevel(matspec)` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |
| updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| setProductionItem | `itemData: GameData, stack: integer, progress01: number` | `void` | `obj:setProductionItem(itemData, stack, progress01)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| playerManufacturerData | `` | `GameData` | `CraftingBuilding.playerManufacturerData()`<br>`obj:playerManufacturerData()` |

## CraftingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`
**Metatable:** `KenshiLua.CraftingInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| queueBtn | `MyGUI::Widget` | RW | `obj.queueBtn = <value>` |
| craftingName | `MyGUI::Widget` | RW | `obj.craftingName = <value>` |
| outputType | `itemType` | RW | `obj.outputType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `inventoryGUI: InventoryGUI, sections: SectionsMap, inventory: Inventory` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |
| refresh | `` | `void` | `obj:refresh()` |
| setOutputType | `type: itemType` | `void` | `obj:setOutputType(type)` |
| setCraftingName | `name: string` | `void` | `obj:setCraftingName(name)` |
| getQueueButton | `` | `MyGUI::Widget` | `obj:getQueueButton()` |

## Crossbow
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Crossbow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| gunClass | `lightuserdata` | R | `obj.gunClass` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| getClassType | `` | `integer` | `obj:getClassType()` |
| getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| getRangeInUnits | `` | `number` | `obj:getRangeInUnits()` |
| getEquipPositionOffset | `` | `number` | `obj:getEquipPositionOffset()` |
| destroyItemEntityCallback_Equipping | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| getTooltipData1 | `` | `void` | `obj:getTooltipData1()` |
| getTooltipData2 | `` | `void` | `obj:getTooltipData2()` |

## Damages
**Header:** `extern/KenshiLib/Include/kenshi/Damages.h`
**Metatable:** `KenshiLua.Damages`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cut | `number` | RW | `obj.cut = <value>` |
| blunt | `number` | RW | `obj.blunt = <value>` |
| pierce | `number` | RW | `obj.pierce = <value>` |
| extraStun | `number` | RW | `obj.extraStun = <value>` |
| bleedMult | `number` | RW | `obj.bleedMult = <value>` |
| armourPenetration | `number` | RW | `obj.armourPenetration = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| multiply | `mult: number` | `void` | `obj:multiply(mult)` |
| total | `` | `number` | `obj:total()` |

## DataObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.DataObjectContainer`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isStored | `boolean` | RW | `obj.isStored = <value>` |
| objectDatas | `GameDataContainer` | RW | `obj.objectDatas = <value>` |
| datasFile | `string` | RW | `obj.datasFile = <value>` |
| selfType | `DataObjectContainer::GroupType` | RW | `obj.selfType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getType | `` | `integer` | `obj:getType()` |
| setupDataFile | `filename: string, container: GameDataContainer` | `void` | `obj:setupDataFile(filename, container)` |
| destroyObjectDatas | `` | `void` | `obj:destroyObjectDatas()` |

## DatapanelGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/DatapanelGUI.h`
**Metatable:** `KenshiLua.DatapanelGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| frequentUpdatesWanted | `boolean` | RW | `obj.frequentUpdatesWanted = <value>` |
| scrollWin | `MyGUI::Widget` | R | `obj.scrollWin` |
| premadeParentWindow | `boolean` | RW | `obj.premadeParentWindow = <value>` |
| scrolling | `boolean` | RW | `obj.scrolling = <value>` |
| isWindow | `boolean` | RW | `obj.isWindow = <value>` |
| currentCategory | `integer` | RW | `obj.currentCategory = <value>` |
| mouseOverEvent | `lightuserdata` | R | `obj.mouseOverEvent` |
| mouseOverEventDatas | `lightuserdata` | R | `obj.mouseOverEventDatas` |
| automaticRefresh | `boolean` | RW | `obj.automaticRefresh = <value>` |
| automaticTarget | `boolean` | RW | `obj.automaticTarget = <value>` |
| tabWin | `MyGUI::Widget` | R | `obj.tabWin` |
| tabs | `lektor<MyGUI::Button*>` | RW | `obj.tabs = <value>` |
| panelName | `string` | RW | `obj.panelName = <value>` |
| x | `number` | RW | `obj.x = <value>` |
| y | `number` | RW | `obj.y = <value>` |
| w | `number` | RW | `obj.w = <value>` |
| h | `number` | RW | `obj.h = <value>` |
| DATALINESPACING | `number` | RW | `obj.DATALINESPACING = <value>` |
| DATALINETHICKNESS | `number` | RW | `obj.DATALINETHICKNESS = <value>` |
| basicSpacing | `boolean` | RW | `obj.basicSpacing = <value>` |
| layer | `string` | RW | `obj.layer = <value>` |
| scrollView | `MyGUI::Widget` | R | `obj.scrollView` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setFrequentUpdateMode | `` | `void` | `obj:setFrequentUpdateMode()` |
| setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| resize | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |
| clear | `` | `void` | `obj:clear()` |
| clearPage | `cat: integer` | `void` | `obj:clearPage(cat)` |
| hideAllWidgets | `` | `void` | `obj:hideAllWidgets()` |
| create | `` | `void` | `obj:create()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| show_NonSmooth | `on: boolean` | `void` | `obj:show_NonSmooth(on)` |
| update | `` | `void` | `obj:update()` |
| setPanelName | `name: string` | `void` | `obj:setPanelName(name)` |
| showTabs | `on: boolean` | `void` | `obj:showTabs(on)` |
| addTab | `id: integer, name: string, icon: string` | `void` | `obj:addTab(id, name, icon)` |
| setTabName | `id: integer, name: string` | `void` | `obj:setTabName(id, name)` |
| setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| setAutomaticRefresh | `on: boolean` | `void` | `obj:setAutomaticRefresh(on)` |
| setAutomaticTargeting | `on: boolean` | `void` | `obj:setAutomaticTargeting(on)` |
| _zeroLines | `cat: integer` | `DataPanelLine` | `obj:_zeroLines(cat)` |
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
| changeCategory | `cat: integer` | `void` | `obj:changeCategory(cat)` |
| getCurrentCategory | `` | `integer` | `obj:getCurrentCategory()` |
| addCustomLine | `line: DataPanelLine` | `void` | `obj:addCustomLine(line)` |
| getObject | `` | `hand` | `obj:getObject()` |
| setLineSpacing | `numLinesPerScreen: number` | `void` | `obj:setLineSpacing(numLinesPerScreen)` |
| getLine | `key: string, cat: integer` | `DataPanelLine` | `obj:getLine(key, cat)` |
| lineExists | `key: string, cat: integer` | `boolean` | `obj:lineExists(key, cat)` |
| getContentHeight | `cat: integer` | `integer` | `obj:getContentHeight(cat)` |
| getNumLines | `cat: integer` | `integer` | `obj:getNumLines(cat)` |
| getLineByNum | `cat: integer, i: integer` | `DataPanelLine` | `obj:getLineByNum(cat, i)` |
| createLine | `line: DataPanelLine, category: integer, lastLine: boolean` | `DataPanelLine` | `obj:createLine(line, category, lastLine)` |
| getNextVerticalPos | `category: integer` | `number` | `obj:getNextVerticalPos(category)` |
| dataExists | `cat: integer, name: string` | `boolean` | `obj:dataExists(cat, name)` |
| clearCategoryTabs | `` | `void` | `obj:clearCategoryTabs()` |
| setLine [1] | `keyValue: string, s1: string, s2: string, skinA: string, skinB: string, category: integer` | `DataPanelLine` | `obj:setLine(keyValue, s1, s2, skinA, skinB, category)` |
| setLine [2] | `keyValue: string, s1: string, s2: string, category: integer, last: boolean, keyVisible: boolean` | `DataPanelLine` | `obj:setLine(keyValue, s1, s2, category, last, keyVisible)` |
| setLine [3] | `s1: string, s2: string, skinA: string, skinB: string, category: integer` | `DataPanelLine` | `obj:setLine(s1, s2, skinA, skinB, category)` |
| setLine [4] | `s1: string, s2: string, barValue: number, category: integer` | `DataPanelLine` | `obj:setLine(s1, s2, barValue, category)` |
| setLine [5] | `s1: string, s2: string, category: integer, last: boolean, keyVisible: boolean` | `DataPanelLine` | `obj:setLine(s1, s2, category, last, keyVisible)` |
| setLineResearch [1] | `s1: string, s2: string, category: integer, v1: number, barColor: string, XButton: boolean` | `DataPanelLine_Research` | `obj:setLineResearch(s1, s2, category, v1, barColor, XButton)` |
| setLineResearch [2] | `key: string, s1: string, s2: string, category: integer, v1: number, barColor: string, Xbutton: boolean` | `DataPanelLine_Research` | `obj:setLineResearch(key, s1, s2, category, v1, barColor, Xbutton)` |
| setTabEnabled | `id: integer, enabled: boolean` | `void` | `obj:setTabEnabled(id, enabled)` |
| setLineText | `key: string, caption: string, category: integer, wordWrap: boolean, textAlign: string` | `DataPanelLine_Text` | `obj:setLineText(key, caption, category, wordWrap, textAlign)` |
| setLineTextEditable | `key: string, text: string, category: integer, showKey: boolean, multiLine: boolean, textAlign: string, width: number` | `DataPanelLine_TextEditable` | `obj:setLineTextEditable(key, text, category, showKey, multiLine, textAlign, width)` |
| setLines | `category: integer` | `void` | `obj:setLines(category)` |
| autoChangeSelectedObject | `obj: hand` | `void` | `obj:autoChangeSelectedObject(obj)` |
| setObject | `obj: hand` | `void` | `obj:setObject(obj)` |
| getCoords | `left: number, top: number, width: number, height: number` | `MyGUI::IntCoord` | `obj:getCoords(left, top, width, height)` |

## DataPanelLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| w1 | `MyGUI::Widget` | R | `obj.w1` |
| w2 | `MyGUI::Widget` | R | `obj.w2` |
| category | `integer` | RW | `obj.category = <value>` |
| keyValue | `string` | RW | `obj.keyValue = <value>` |
| s1 | `string` | RW | `obj.s1 = <value>` |
| s2 | `string` | RW | `obj.s2 = <value>` |
| lo | `integer` | RW | `obj.lo = <value>` |
| hi | `integer` | RW | `obj.hi = <value>` |
| skinW1 | `string` | RW | `obj.skinW1 = <value>` |
| skinW2 | `string` | RW | `obj.skinW2 = <value>` |
| classType | `DataPanelLine::LineType` | RW | `obj.classType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| setEnabled | `on: boolean` | `void` | `obj:setEnabled(on)` |
| refresh | `` | `void` | `obj:refresh()` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |
| resize | `width: integer, height: integer` | `void` | `obj:resize(width, height)` |
| getBottom | `` | `integer` | `obj:getBottom()` |
| getType | `` | `DataPanelLine::LineType` | `obj:getType()` |
| getUserData | `` | `hand` | `obj:getUserData()` |
| getNumWidgets | `` | `integer` | `obj:getNumWidgets()` |
| getWidget | `index: integer` | `MyGUI::Widget` | `obj:getWidget(index)` |

## DataPanelLine_Button
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Button`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| userData | `hand` | RW | `obj.userData = <value>` |
| button | `MyGUI::Widget` | RW | `obj.button = <value>` |
| buttonWidth | `number` | RW | `obj.buttonWidth = <value>` |
| buttonHeight | `number` | RW | `obj.buttonHeight = <value>` |
| buttonSkin | `string` | RW | `obj.buttonSkin = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getUserData | `` | `hand` | `obj:getUserData()` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_CheckBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_CheckBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| valuePtr | `lightuserdata` | R | `obj.valuePtr` |
| text | `MyGUI::Widget` | R | `obj.text` |
| button | `MyGUI::Widget` | R | `obj.button` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| refresh | `` | `void` | `obj:refresh()` |
| setValue | `checked: boolean` | `void` | `obj:setValue(checked)` |
| setValuePtr | `bVal: boolean` | `void` | `obj:setValuePtr(bVal)` |
| getTextBox | `` | `MyGUI::Widget` | `obj:getTextBox()` |
| getCheckBox | `` | `MyGUI::Widget` | `obj:getCheckBox()` |
| createMe | `parent: DatapanelGUI, topReal: number, lastLine: boolean` | `void` | `obj:createMe(parent, topReal, lastLine)` |

## DataPanelLine_DropBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_DropBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| listBox | `MyGUI::Widget` | R | `obj.listBox` |
| listWidth | `number` | RW | `obj.listWidth = <value>` |
| valPtr | `lightuserdata` | R | `obj.valPtr` |
| hasGoBox | `boolean` | RW | `obj.hasGoBox = <value>` |
| goBox | `MyGUI::Widget` | R | `obj.goBox` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addAValue | `key: string, val: integer` | `void` | `obj:addAValue(key, val)` |
| getSelectedValue | `` | `integer` | `obj:getSelectedValue()` |
| setSelectedValue | `val: integer` | `void` | `obj:setSelectedValue(val)` |
| getSelectedText | `` | `string` | `obj:getSelectedText()` |
| clearValues | `` | `void` | `obj:clearValues()` |
| getComboBox | `` | `MyGUI::Widget` | `obj:getComboBox()` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |
| refresh | `` | `void` | `obj:refresh()` |

## DataPanelLine_Faction
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Faction`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| v1 | `number` | RW | `obj.v1 = <value>` |
| v2 | `number` | RW | `obj.v2 = <value>` |
| bar | `MyGUI::Widget` | R | `obj.bar` |
| bar2 | `MyGUI::Widget` | R | `obj.bar2` |
| but | `MyGUI::Widget` | R | `obj.but` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_KeyConfig
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_KeyConfig`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| btn0 | `MyGUI::Widget` | R | `obj.btn0` |
| btn1 | `MyGUI::Widget` | R | `obj.btn1` |
| command | `string` | RW | `obj.command = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| oldKey | `` | `integer` | `obj:oldKey()` |
| setKey | `s: string` | `void` | `obj:setKey(s)` |
| eraseKey | `key: string` | `void` | `obj:eraseKey(key)` |
| refresh | `` | `void` | `obj:refresh()` |
| cancel | `` | `void` | `obj:cancel()` |
| createMe | `p: DatapanelGUI, vpos: number, lastLine: boolean` | `void` | `obj:createMe(p, vpos, lastLine)` |
| getCommand | `` | `void` | `obj:getCommand()` |

## DataPanelLine_Progress
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Progress`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textBox | `MyGUI::Widget` | R | `obj.textBox` |
| progress | `MyGUI::Widget` | R | `obj.progress` |
| progressText | `MyGUI::Widget` | R | `obj.progressText` |
| showKey | `boolean` | RW | `obj.showKey = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setProgress | `value: number, text: string` | `void` | `obj:setProgress(value, text)` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_Research
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Research`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| v1 | `number` | RW | `obj.v1 = <value>` |
| v2 | `number` | RW | `obj.v2 = <value>` |
| hasXBut | `boolean` | RW | `obj.hasXBut = <value>` |
| barSkin | `string` | RW | `obj.barSkin = <value>` |
| bar | `MyGUI::Widget` | RW | `obj.bar = <value>` |
| but | `MyGUI::Widget` | R | `obj.but` |
| Xbut | `MyGUI::Widget` | R | `obj.Xbut` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Slider`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| scale | `number` | RW | `obj.scale = <value>` |
| min | `number` | RW | `obj.min = <value>` |
| max | `number` | RW | `obj.max = <value>` |
| valuePtr | `lightuserdata` | R | `obj.valuePtr` |
| slider | `lightuserdata` | R | `obj.slider` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setValue | `value: number` | `void` | `obj:setValue(value)` |
| getValue | `` | `number` | `obj:getValue()` |
| refresh | `` | `void` | `obj:refresh()` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_SliderEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_SliderEditable`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| width | `number` | RW | `obj.width = <value>` |
| showName | `boolean` | RW | `obj.showName = <value>` |
| min | `number` | RW | `obj.min = <value>` |
| max | `number` | RW | `obj.max = <value>` |
| valuePtr | `lightuserdata` | R | `obj.valuePtr` |
| scale | `number` | RW | `obj.scale = <value>` |
| nameText | `MyGUI::Widget` | R | `obj.nameText` |
| valueEditBox | `MyGUI::Widget` | R | `obj.valueEditBox` |
| sliderBar | `MyGUI::Widget` | R | `obj.sliderBar` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setEditableValuePtr | `tempVal: number, lo: number, hi: number` | `void` | `obj:setEditableValuePtr(tempVal, lo, hi)` |
| getSlider | `` | `MyGUI::Widget` | `obj:getSlider()` |
| getEditBox | `` | `MyGUI::Widget` | `obj:getEditBox()` |
| setValue | `v: number` | `void` | `obj:setValue(v)` |
| refresh | `` | `void` | `obj:refresh()` |
| setPrecision | `dp: integer` | `void` | `obj:setPrecision(dp)` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_Text
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Text`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| editBox | `MyGUI::Widget` | R | `obj.editBox` |
| wordWrap | `boolean` | RW | `obj.wordWrap = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DataPanelLine_TextEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_TextEditable`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| editBox | `MyGUI::Widget` | R | `obj.editBox` |
| nameText | `MyGUI::Widget` | R | `obj.nameText` |
| showKey | `boolean` | RW | `obj.showKey = <value>` |
| multiLine | `boolean` | RW | `obj.multiLine = <value>` |
| width | `number` | RW | `obj.width = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getEditBox | `` | `MyGUI::Widget` | `obj:getEditBox()` |
| getNameBox | `` | `MyGUI::Widget` | `obj:getNameBox()` |
| createMe | `parent: DatapanelGUI, top: number, lastLine: boolean` | `void` | `obj:createMe(parent, top, lastLine)` |

## DialogChoiceList
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Metatable:** `KenshiLua.DialogChoiceList`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| conversationChoices | `lektor<DialogLineData*>` | RW | `obj.conversationChoices = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| add | `conversation: GameData, parent: DialogLineData` | `void` | `obj:add(conversation, parent)` |

## DialogDataManager
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Metatable:** `KenshiLua.DialogDataManager`

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
**Metatable:** `KenshiLua.DialogLineData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| targetFlagsNeeded | `integer` | RW | `obj.targetFlagsNeeded = <value>` |
| targetFlagsNotWanted | `integer` | RW | `obj.targetFlagsNotWanted = <value>` |
| personalityNeeded | `integer` | RW | `obj.personalityNeeded = <value>` |
| personalityNotWanted | `integer` | RW | `obj.personalityNotWanted = <value>` |
| campaignTriggers | `FitnessSelector<CampaignTriggerData*>` | RW | `obj.campaignTriggers = <value>` |
| isTargetRace | `lektor<GameData*>` | RW | `obj.isTargetRace = <value>` |
| isTargetSubRace_specificallyTheTarget | `lektor<GameData*>` | RW | `obj.isTargetSubRace_specificallyTheTarget = <value>` |
| givesItem | `lektor<GameDataValuePair>` | RW | `obj.givesItem = <value>` |
| inTownOf | `Faction` | RW | `obj.inTownOf = <value>` |
| isTargetFaction | `Faction` | RW | `obj.isTargetFaction = <value>` |
| isMyFaction | `Faction` | RW | `obj.isMyFaction = <value>` |
| isCharacter | `lektor<GameData*>` | RW | `obj.isCharacter = <value>` |
| isTargetCarryingCharacter | `lektor<GameData*>` | RW | `obj.isTargetCarryingCharacter = <value>` |
| hasPackage | `lektor<GameData*>` | RW | `obj.hasPackage = <value>` |
| isMyRace | `lektor<GameData*>` | RW | `obj.isMyRace = <value>` |
| isMySubRace | `lektor<GameData*>` | RW | `obj.isMySubRace = <value>` |
| hasItemType | `ItemFunction` | RW | `obj.hasItemType = <value>` |
| hasItem | `lektor<GameData*>` | RW | `obj.hasItem = <value>` |
| worldState | `WorldEventStateQueryList` | RW | `obj.worldState = <value>` |
| data | `GameData` | RW | `obj.data = <value>` |
| onceOnly | `boolean` | RW | `obj.onceOnly = <value>` |
| isMonologue | `boolean` | RW | `obj.isMonologue = <value>` |
| forCertainType | `CharacterTypeEnum` | RW | `obj.forCertainType = <value>` |
| children | `DialogChoiceList` | RW | `obj.children = <value>` |
| conditions | `lektor<DialogLineData::DialogCondition*>` | RW | `obj.conditions = <value>` |
| actions | `lektor<DialogLineData::DialogAction*>` | RW | `obj.actions = <value>` |
| lineCount | `integer` | RW | `obj.lineCount = <value>` |
| texts | `string` | RW | `obj.texts = <value>` |
| parent | `DialogLineData` | RW | `obj.parent = <value>` |
| chancePermanent | `number` | RW | `obj.chancePermanent = <value>` |
| chanceTemporary | `number` | RW | `obj.chanceTemporary = <value>` |
| unique | `boolean` | RW | `obj.unique = <value>` |
| uniqueOwner | `hand` | RW | `obj.uniqueOwner = <value>` |
| dialogRepeatMinTimeInHours | `number` | RW | `obj.dialogRepeatMinTimeInHours = <value>` |
| lastTimeSaid | `TimeOfDay` | RW | `obj.lastTimeSaid = <value>` |
| score | `integer` | RW | `obj.score = <value>` |
| oneAtATime | `boolean` | RW | `obj.oneAtATime = <value>` |
| isLocked | `boolean` | RW | `obj.isLocked = <value>` |
| locks | `lektor<DialogLineData*>` | RW | `obj.locks = <value>` |
| unlocks_lockMe | `lektor<DialogLineData*>` | RW | `obj.unlocks_lockMe = <value>` |
| unlocks_dontLockMe | `lektor<DialogLineData*>` | RW | `obj.unlocks_dontLockMe = <value>` |
| crowdTrigger | `DialogLineData` | RW | `obj.crowdTrigger = <value>` |
| factionRelationEffects | `ogre_unordered_map<GameData*, int>` | RW | `obj.factionRelationEffects = <value>` |
| playerInterruptionDialog | `DialogLineData` | RW | `obj.playerInterruptionDialog = <value>` |
| isInterjection | `boolean` | RW | `obj.isInterjection = <value>` |
| speaker | `TalkerEnum` | RW | `obj.speaker = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getParent | `` | `DialogLineData` | `obj:getParent()` |
| isForSpecificCharacter | `who: GameData` | `boolean` | `obj:isForSpecificCharacter(who)` |
| hasSpecificCharacterRequirement | `` | `boolean` | `obj:hasSpecificCharacterRequirement()` |
| setupChildren | `` | `void` | `obj:setupChildren()` |
| checkRepeatLimits | `` | `boolean` | `obj:checkRepeatLimits()` |
| checkTags | `me: Character, target: Character` | `boolean` | `obj:checkTags(me, target)` |
| getName | `` | `string` | `obj:getName()` |
| saidItBefore | `` | `boolean` | `obj:saidItBefore()` |
| willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| isEmptyNode | `` | `boolean` | `obj:isEmptyNode()` |
| isAnnouncement | `` | `boolean` | `obj:isAnnouncement()` |
| stampLastTimeSaid | `` | `void` | `obj:stampLastTimeSaid()` |
| getScore | `target: Character` | `integer` | `obj:getScore(target)` |
| getScorePlusChildrenIfEmpty | `target: Character` | `integer` | `obj:getScorePlusChildrenIfEmpty(target)` |
| hasChildren | `` | `boolean` | `obj:hasChildren()` |
| checkConditions | `dialog: Dialogue, target: Character, isWordswap: boolean` | `boolean` | `obj:checkConditions(dialog, target, isWordswap)` |
| chooseAChild | `who: Dialogue, target: Character, isForWordswaps: boolean` | `DialogLineData` | `obj:chooseAChild(who, target, isForWordswaps)` |
| getStringID | `` | `string` | `obj:getStringID()` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| getChildByStringID | `sid: string` | `DialogLineData` | `obj:getChildByStringID(sid)` |
| setParent | `p: DialogLineData` | `void` | `obj:setParent(p)` |
| getMoneyCostForLine | `` | `integer` | `obj:getMoneyCostForLine()` |
| getText [1] | `_stampTime: boolean` | `string` | `obj:getText(_stampTime)` |
| getText [2] | `out: string, _stampTime: boolean` | `void` | `obj:getText(out, _stampTime)` |
| getPlayerReplies | `out: lektor<DialogLineData*>, who: Dialogue, target: Character` | `void` | `obj:getPlayerReplies(out, who, target)` |
| getActions | `` | `lektor<DialogLineData::DialogAction*>` | `obj:getActions()` |

## DialogLineData::DialogAction
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`DialogLineData`](#dialoglinedata)
**Metatable:** `KenshiLua.DialogAction`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | `integer` | RW | `obj.value = <value>` |
| key | `DialogActionEnum` | RW | `obj.key = <value>` |

## DialogLineData::DialogCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`DialogLineData`](#dialoglinedata)
**Metatable:** `KenshiLua.DialogCondition`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | `DialogConditionEnum` | RW | `obj.key = <value>` |
| compareBy | `ComparisonEnum` | RW | `obj.compareBy = <value>` |
| who | `TalkerEnum` | RW | `obj.who = <value>` |
| value | `integer` | RW | `obj.value = <value>` |

## DialogLineData::FlagCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`DialogLineData`](#dialoglinedata)
**Metatable:** `KenshiLua.FlagCondition`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | `DialogConditionEnum` | RW | `obj.key = <value>` |
| want | `boolean` | RW | `obj.want = <value>` |
| flags | `integer` | RW | `obj.flags = <value>` |

## Dialogue
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Metatable:** `KenshiLua.Dialogue`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| repCounter | `Dialogue::RepetitionCounter` | RW | `obj.repCounter = <value>` |
| _needsDynamicAssessments | `boolean` | RW | `obj._needsDynamicAssessments = <value>` |
| sayMsg | `string` | RW | `obj.sayMsg = <value>` |
| playerInterruptionDialog | `DialogLineData` | RW | `obj.playerInterruptionDialog = <value>` |
| _hasEnded | `boolean` | RW | `obj._hasEnded = <value>` |
| shouting | `boolean` | RW | `obj.shouting = <value>` |
| staysOnScreen | `boolean` | RW | `obj.staysOnScreen = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| conversationTarget | `hand` | RW | `obj.conversationTarget = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| movement | `CharMovement` | RW | `obj.movement = <value>` |
| currentConversationType | `EventTriggerEnum` | RW | `obj.currentConversationType = <value>` |
| currentConversation | `DialogLineData` | RW | `obj.currentConversation = <value>` |
| currentLine | `DialogLineData` | RW | `obj.currentLine = <value>` |
| interjector1 | `hand` | RW | `obj.interjector1 = <value>` |
| interjector2 | `hand` | RW | `obj.interjector2 = <value>` |
| interjector3 | `hand` | RW | `obj.interjector3 = <value>` |
| speechBubblePanel | `DialogueSpeechBubble` | RW | `obj.speechBubblePanel = <value>` |
| speechTextTimer | `number` | RW | `obj.speechTextTimer = <value>` |
| speechTextTimer_forced | `number` | RW | `obj.speechTextTimer_forced = <value>` |
| npcReplyText | `string` | RW | `obj.npcReplyText = <value>` |
| conversationMaster | `hand` | RW | `obj.conversationMaster = <value>` |
| waitingForReplyFrom | `hand` | RW | `obj.waitingForReplyFrom = <value>` |
| pacakgesIHave | `GameData` | RW | `obj.pacakgesIHave = <value>` |
| locked | `DialogLineDataBoolMapBinding::MapType` | RW | `obj.locked = <value>` |
| _hasChanceLines | `DialogLineDataBoolMapBinding::MapType` | RW | `obj._hasChanceLines = <value>` |
| eventRepeatTimers | `EventRepeatTimersMapBinding::MapType` | RW | `obj.eventRepeatTimers = <value>` |
| eventDeliveredStates | `EventDeliveredStatesMapBinding::MapType` | RW | `obj.eventDeliveredStates = <value>` |
| conversationsMain | `ConversationsMainMapBinding::MapType` | RW | `obj.conversationsMain = <value>` |
| threadMessages | `integer` | RW | `obj.threadMessages = <value>` |
| replyIds | `string` | RW | `obj.replyIds = <value>` |
| responses | `string` | RW | `obj.responses = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWordSwap | `key: string, _target: Character, _a3: boolean, _line: DialogLineData` | `string` | `obj:getWordSwap(key, _target, _a3, _line)` |
| setupWordSwaps | `` | `void` | `obj:setupWordSwaps()` |
| getGUIData | `datapanel: DatapanelGUI, cat: integer` | `void` | `obj:getGUIData(datapanel, cat)` |
| create | `c: Character, s: CharStats, m: CharMovement` | `void` | `obj:create(c, s, m)` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| setLineLocked | `line: DialogLineData, on: boolean` | `void` | `obj:setLineLocked(line, on)` |
| isLocked | `line: DialogLineData` | `boolean` | `obj:isLocked(line)` |
| setInDialog | `on: boolean` | `void` | `obj:setInDialog(on)` |
| clearDialogues | `` | `void` | `obj:clearDialogues()` |
| clearAnnouncements | `` | `void` | `obj:clearAnnouncements()` |
| needsDialogAssessmentUpdate | `` | `boolean` | `obj:needsDialogAssessmentUpdate()` |
| addDialoguePackage | `_con: GameData` | `void` | `obj:addDialoguePackage(_con)` |
| addConversation | `_con: GameData, t: EventTriggerEnum` | `void` | `obj:addConversation(_con, t)` |
| clearConversationList | `t: EventTriggerEnum` | `void` | `obj:clearConversationList(t)` |
| willTalkToEnemies | `` | `boolean` | `obj:willTalkToEnemies()` |
| sendEventOverride | `who: Character, what: EventTriggerEnum, forceRepeat: boolean` | `boolean` | `obj:sendEventOverride(who, what, forceRepeat)` |
| sendEvent | `who: Character, what: EventTriggerEnum` | `boolean` | `obj:sendEvent(who, what)` |
| stopEvent | `what: EventTriggerEnum` | `void` | `obj:stopEvent(what)` |
| runCustomDialog | `dialog: GameData` | `boolean` | `obj:runCustomDialog(dialog)` |
| scoreCustomDialog | `dialog: GameData` | `integer` | `obj:scoreCustomDialog(dialog)` |
| conversationHasEnded | `` | `boolean` | `obj:conversationHasEnded()` |
| getConversationTarget | `` | `hand` | `obj:getConversationTarget()` |
| changeConversationTarget | `c: Character` | `void` | `obj:changeConversationTarget(c)` |
| conversationHasEndedPrettyMuch | `` | `boolean` | `obj:conversationHasEndedPrettyMuch()` |
| makeAnnouncement | `dat: GameData` | `boolean` | `obj:makeAnnouncement(dat)` |
| update | `frameTime: number` | `void` | `obj:update(frameTime)` |
| endDialogue | `definitelyTheEnd: boolean` | `void` | `obj:endDialogue(definitelyTheEnd)` |
| notifyUnderAttack | `attacker: Character` | `void` | `obj:notifyUnderAttack(attacker)` |
| hasDialogue_Fast | `` | `boolean` | `obj:hasDialogue_Fast()` |
| hasDialogue_Accurate | `` | `boolean` | `obj:hasDialogue_Accurate()` |
| hasDialogueEvent | `e: EventTriggerEnum` | `boolean` | `obj:hasDialogueEvent(e)` |
| dialogDelivered | `e: EventTriggerEnum` | `boolean` | `obj:dialogDelivered(e)` |
| _checkCondition | `conditionName: DialogConditionEnum, compareBy: ComparisonEnum, val: integer, target: Character, actualConversationTarget: Character` | `boolean` | `obj:_checkCondition(conditionName, compareBy, val, target, actualConversationTarget)` |
| dontLetTargetBeMe | `targetObj: Character, actualTarget: Character` | `void` | `obj:dontLetTargetBeMe(targetObj, actualTarget)` |
| hasThisChanceLine | `line: DialogLineData, chance: number` | `boolean` | `obj:hasThisChanceLine(line, chance)` |
| _chooseDialog | `list: DialogChoiceList, target: Character, isWordswap: boolean` | `DialogLineData` | `obj:_chooseDialog(list, target, isWordswap)` |
| triggerNextLine | `previousLine: DialogLineData` | `void` | `obj:triggerNextLine(previousLine)` |
| targetInTalkingRange | `target: Character, mult: number` | `boolean` | `obj:targetInTalkingRange(target, mult)` |
| save | `to: GameData` | `void` | `obj:save(to)` |
| load | `to: GameData` | `void` | `obj:load(to)` |
| getSpeaker | `who: TalkerEnum, line: DialogLineData, isForWordswaps: boolean` | `Character` | `obj:getSpeaker(who, line, isForWordswaps)` |
| isCurrentConversationRunning | `line: DialogLineData` | `boolean` | `obj:isCurrentConversationRunning(line)` |
| findInterjectionCharacter | `line: DialogLineData` | `Character` | `obj:findInterjectionCharacter(line)` |
| isKOExempt | `what: EventTriggerEnum` | `boolean` | `obj:isKOExempt(what)` |
| _endPlayerConversation | `finished: boolean` | `void` | `obj:_endPlayerConversation(finished)` |
| startPlayerConversation | `target: Character, _talk: DialogLineData` | `boolean` | `obj:startPlayerConversation(target, _talk)` |
| startConversation | `target: Character, _talk: DialogLineData, ev: EventTriggerEnum, force: boolean` | `boolean` | `obj:startConversation(target, _talk, ev, force)` |
| getConversationList | `t: EventTriggerEnum` | `DialogChoiceList` | `obj:getConversationList(t)` |
| _doActions | `dialogLine: DialogLineData` | `void` | `obj:_doActions(dialogLine)` |
| sayLine | `line: DialogLineData` | `boolean` | `obj:sayLine(line)` |
| listPlayerReplies | `` | `void` | `obj:listPlayerReplies()` |
| isLastLine | `dialogLine: DialogLineData` | `boolean` | `obj:isLastLine(dialogLine)` |
| setSpeaker | `who: TalkerEnum, c: Character` | `void` | `obj:setSpeaker(who, c)` |
| _updateTextPos | `` | `void` | `obj:_updateTextPos()` |
| clearSpeechBox | `` | `void` | `obj:clearSpeechBox()` |
| clearRespones | `` | `void` | `obj:clearRespones()` |
| clearResponesGUI | `` | `void` | `obj:clearResponesGUI()` |
| setResponesGUI | `` | `void` | `obj:setResponesGUI()` |
| setConversationReplyGUI | `` | `void` | `obj:setConversationReplyGUI()` |
| say [1] | `dialogLine: DialogLineData` | `void` | `obj:say(dialogLine)` |
| say [2] | `_text: string, line: DialogLineData` | `void` | `obj:say(_text, line)` |
| replyClicked [1] | `index: string` | `void` | `obj:replyClicked(index)` |
| replyClicked [2] | `index: integer` | `void` | `obj:replyClicked(index)` |
| isAtTownOf | `` | `boolean` | `obj:isAtTownOf()` |
| resolveOverlappedSpeechBubbles | `` | `void` | `obj:resolveOverlappedSpeechBubbles()` |

## Dialogue::RepetitionCounter
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`Dialogue`](#dialogue)
**Metatable:** `KenshiLua.RepetitionCounter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| states | `RepetitionStatesMapBinding::MapType` | RW | `obj.states = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `` | `void` | `obj:setup()` |
| count | `ev: EventTriggerEnum` | `boolean` | `obj:count(ev)` |
| getTimeSinceLastTrigger | `ev: EventTriggerEnum` | `number` | `obj:getTimeSinceLastTrigger(ev)` |
| getCount | `ev: EventTriggerEnum` | `integer` | `obj:getCount(ev)` |

## Dialogue::RepetitionCounter::DialogState
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`Dialogue`](#dialogue)
**Metatable:** `KenshiLua.DialogState`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| count | `integer` | RW | `obj.count = <value>` |
| lastTimeStamp | `number` | RW | `obj.lastTimeStamp = <value>` |
| resetTime | `number` | RW | `obj.resetTime = <value>` |

## DialogueSpeechBubble
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Metatable:** `KenshiLua.DialogueSpeechBubble`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| stayOnScreen | `boolean` | RW | `obj.stayOnScreen = <value>` |
| shout | `boolean` | RW | `obj.shout = <value>` |
| marginW | `integer` | RW | `obj.marginW = <value>` |
| marginH | `integer` | RW | `obj.marginH = <value>` |
| textBox | `MyGUI::Widget` | RW | `obj.textBox = <value>` |
| baseSize | `integer` | RW | `obj.baseSize = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setText | `text: string` | `void` | `obj:setText(text)` |
| setAlpha | `value: number` | `void` | `obj:setAlpha(value)` |
| setPosition [1] | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setPosition [2] | `position: Vector3` | `void` | `obj:setPosition(position)` |
| reset | `` | `void` | `obj:reset()` |
| getAlpha | `` | `number` | `obj:getAlpha()` |
| getRect | `` | `integer` | `obj:getRect()` |

## DialogueWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/DialogueWindow.h`
**Metatable:** `KenshiLua.DialogueWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| dialogue | `Dialogue` | RW | `obj.dialogue = <value>` |
| conversationPanelsMargin | `integer` | RW | `obj.conversationPanelsMargin = <value>` |
| converstaionPCPanelBottom | `integer` | RW | `obj.converstaionPCPanelBottom = <value>` |
| conversationPCSpeechPanelMinHeight | `integer` | RW | `obj.conversationPCSpeechPanelMinHeight = <value>` |
| conversationNPCSpeechPanelMinHeight | `integer` | RW | `obj.conversationNPCSpeechPanelMinHeight = <value>` |
| conversationPCPanelHeightDiffSpeechPanel | `integer` | RW | `obj.conversationPCPanelHeightDiffSpeechPanel = <value>` |
| conversationNPCPanelHeightDiffSpeechPanel | `integer` | RW | `obj.conversationNPCPanelHeightDiffSpeechPanel = <value>` |
| conversationPC | `Character` | RW | `obj.conversationPC = <value>` |
| conversationPCPanel | `MyGUI::Widget` | RW | `obj.conversationPCPanel = <value>` |
| conversationNPCPanel | `MyGUI::Widget` | RW | `obj.conversationNPCPanel = <value>` |
| conversationNPCNameText | `MyGUI::Widget` | R | `obj.conversationNPCNameText` |
| conversationPCNameText | `MyGUI::Widget` | R | `obj.conversationPCNameText` |
| conversationPCMoneyText | `MyGUI::Widget` | R | `obj.conversationPCMoneyText` |
| conversationNPCSpeech | `MyGUI::Widget` | RW | `obj.conversationNPCSpeech = <value>` |
| conversationPCSpeechPanel | `MyGUI::Widget` | RW | `obj.conversationPCSpeechPanel = <value>` |
| conversationNPCPortrait | `MyGUI::Widget` | R | `obj.conversationNPCPortrait` |
| conversationPCPortrait | `MyGUI::Widget` | R | `obj.conversationPCPortrait` |
| replyTexts | `Ogre::FastArray<MyGUI::EditBox*>` | RW | `obj.replyTexts = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| show | `_dialogue: Dialogue` | `void` | `obj:show(_dialogue)` |
| hide | `_dialogue: Dialogue` | `void` | `obj:hide(_dialogue)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| update | `` | `void` | `obj:update()` |
| getTop | `` | `integer` | `obj:getTop()` |
| activateResponse | `index: integer` | `void` | `obj:activateResponse(index)` |
| setNPCText | `text: string` | `void` | `obj:setNPCText(text)` |
| setResponses | `arg1: type` | `void` | `obj:setResponses(arg1)` |
| clearResponses | `` | `void` | `obj:clearResponses()` |
| changePortrait | `character: Character, player: boolean` | `void` | `obj:changePortrait(character, player)` |
| updatePanelsPosition | `` | `void` | `obj:updatePanelsPosition()` |

## DoorStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/DoorStuff.h`
**Metatable:** `KenshiLua.DoorStuff`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isSetupComplete | `boolean` | RW | `obj.isSetupComplete = <value>` |
| parent | `Building` | RW | `obj.parent = <value>` |
| doorLock | `lightuserdata` | RW | `obj.doorLock = <value>` |
| gateCode | `integer` | RW | `obj.gateCode = <value>` |
| doorOpenAmount | `number` | RW | `obj.doorOpenAmount = <value>` |
| state | `DoorState` | RW | `obj.state = <value>` |
| wantsToLock | `boolean` | RW | `obj.wantsToLock = <value>` |
| doorSpeed | `number` | RW | `obj.doorSpeed = <value>` |
| doorDistance | `number` | RW | `obj.doorDistance = <value>` |
| doorMoveAxis | `integer` | RW | `obj.doorMoveAxis = <value>` |
| doorComesOut | `number` | RW | `obj.doorComesOut = <value>` |
| nodeClosedPosition | `Vector3` | R | `obj.nodeClosedPosition` |
| actorClosedPosition | `Vector3` | RW | `obj.actorClosedPosition = <value>` |
| doorClosedPosition | `Vector3` | RW | `obj.doorClosedPosition = <value>` |
| doorClosedPositionOut | `Vector3` | RW | `obj.doorClosedPositionOut = <value>` |
| doorClosedPositionIn | `Vector3` | RW | `obj.doorClosedPositionIn = <value>` |
| axisH | `Vector3` | RW | `obj.axisH = <value>` |
| axisF | `Vector3` | RW | `obj.axisF = <value>` |
| _isBroken | `boolean` | RW | `obj._isBroken = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupPhysicalUT | `` | `boolean` | `obj:setupPhysicalUT()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| _getPhysActorUT | `` | `lightuserdata` | `obj:_getPhysActorUT()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| getGateCode | `` | `integer` | `obj:getGateCode()` |
| setGateCode | `code: integer` | `void` | `obj:setGateCode(code)` |
| isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| getDoor | `` | `DoorStuff` | `obj:getDoor()` |
| getName | `` | `string` | `obj:getName()` |
| getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| updateGateCodeState | `` | `void` | `obj:updateGateCodeState()` |
| onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| setDoorOpenAmount | `amount: number, forceUnsafe: boolean` | `void` | `obj:setDoorOpenAmount(amount, forceUnsafe)` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| setBroken | `on: boolean` | `void` | `obj:setBroken(on)` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| isLocked | `` | `boolean` | `obj:isLocked()` |
| lockDoor | `` | `void` | `obj:lockDoor()` |
| unlockDoor | `` | `void` | `obj:unlockDoor()` |
| getDoorOpenAmount | `` | `number` | `obj:getDoorOpenAmount()` |
| setDoorState | `what: DoorState` | `void` | `obj:setDoorState(what)` |
| getDoorState | `` | `DoorState` | `obj:getDoorState()` |
| openDoor | `` | `boolean` | `obj:openDoor()` |
| closeDoor | `` | `boolean` | `obj:closeDoor()` |
| _forceDoorClosedUT | `` | `boolean` | `obj:_forceDoorClosedUT()` |
| _forceDoorOpenUT | `` | `boolean` | `obj:_forceDoorOpenUT()` |
| update | `` | `void` | `obj:update()` |
| getDoorPosOutside_extraFarOut | `mult: number` | `Vector3` | `obj:getDoorPosOutside_extraFarOut(mult)` |
| getDoorPosInside_extraFarIn | `mult: number` | `Vector3` | `obj:getDoorPosInside_extraFarIn(mult)` |
| isOpen | `` | `boolean` | `obj:isOpen()` |
| doorStuff | `` | `DoorStuff` | `obj:doorStuff()` |
| doorParentBuilding | `` | `Building` | `obj:doorParentBuilding()` |
| hitByMeleeAttack | `dir: CutDirection, damage: Damages, who: Character, attack: CombatTechniqueData, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, damage, who, attack, comboID)` |
| getActorClosedPosition | `` | `Vector3` | `obj:getActorClosedPosition()` |
| getDoorPosition | `` | `Vector3` | `obj:getDoorPosition()` |
| getDoorPosOutside | `` | `Vector3` | `obj:getDoorPosOutside()` |
| getDoorPosInside | `` | `Vector3` | `obj:getDoorPosInside()` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| openButton | `line: DataPanelLine` | `void` | `obj:openButton(line)` |
| lockButton | `line: DataPanelLine` | `void` | `obj:lockButton(line)` |
| _serialise | `save: GameData, id: string` | `void` | `obj:_serialise(save, id)` |
| _loadFromSerialise | `save: GameData, id: string, firstTime: boolean` | `void` | `obj:_loadFromSerialise(save, id, firstTime)` |

## EdgeCache
**Header:** `extern/KenshiLib/Include/kenshi/HavokCharacter.h`
**Metatable:** `KenshiLua.EdgeCache`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| centre | `lightuserdata` | RW | `obj.centre = <value>` |
| radius | `number` | RW | `obj.radius = <value>` |
| hasDoor | `boolean` | RW | `obj.hasDoor = <value>` |

## EdgeCache::Edge
**Header:** `extern/KenshiLib/Include/kenshi/HavokCharacter.h`
**Parent Class:** [`EdgeCache`](#edgecache)
**Metatable:** `KenshiLua.EdgeCache_Edge`

## EdgePathNode
**Header:** `extern/KenshiLib/Include/kenshi/HavokCharacter.h`
**Metatable:** `KenshiLua.EdgePathNode`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mLeft | `hkVector4f` | RW | `obj.mLeft = <value>` |
| mRight | `hkVector4f` | RW | `obj.mRight = <value>` |
| face | `integer` | RW | `obj.face = <value>` |
| edge | `integer` | RW | `obj.edge = <value>` |
| leftClearance | `number` | RW | `obj.leftClearance = <value>` |
| rightClearance | `number` | RW | `obj.rightClearance = <value>` |
| maxPoint | `number` | RW | `obj.maxPoint = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`
**Metatable:** `KenshiLua.Faction`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _antiSlavery | `boolean` | RW | `obj._antiSlavery = <value>` |
| characteristicsData | `Faction::CharacteristicsData` | RW | `obj.characteristicsData = <value>` |
| fundamentalNPCType | `CharacterTypeEnum` | RW | `obj.fundamentalNPCType = <value>` |
| ranks | `lektor<std::string>` | RW | `obj.ranks = <value>` |
| allowSlavesWeapons | `boolean` | RW | `obj.allowSlavesWeapons = <value>` |
| myLawEnforcementFaction | `Faction` | RW | `obj.myLawEnforcementFaction = <value>` |
| isALawEnforcementFaction | `boolean` | RW | `obj.isALawEnforcementFaction = <value>` |
| factionLeader | `FactionLeader` | RW | `obj.factionLeader = <value>` |
| diplomatMgr | `FactionUniqueSquadManager` | RW | `obj.diplomatMgr = <value>` |
| relations | `FactionRelations` | RW | `obj.relations = <value>` |
| factionOwnerships | `Ownerships` | RW | `obj.factionOwnerships = <value>` |
| warMgr | `FactionWarMgr` | RW | `obj.warMgr = <value>` |
| tradeCulture | `TradeCulture` | RW | `obj.tradeCulture = <value>` |
| raceSelector | `FitnessSelector<GameData*>` | RW | `obj.raceSelector = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| notARealFaction | `boolean` | RW | `obj.notARealFaction = <value>` |
| roadPreference | `number` | RW | `obj.roadPreference = <value>` |
| platoonKillList | `lektor<Platoon*>` | RW | `obj.platoonKillList = <value>` |
| platoonRemoveList | `lektor<Platoon*>` | RW | `obj.platoonRemoveList = <value>` |
| activePlatoons | `lektor<Platoon*>` | RW | `obj.activePlatoons = <value>` |
| unloadedPlatoons | `lektor<Platoon*>` | RW | `obj.unloadedPlatoons = <value>` |
| periodicUpdateCounter_active | `integer` | RW | `obj.periodicUpdateCounter_active = <value>` |
| periodicUpdateCounter_unloaded | `integer` | RW | `obj.periodicUpdateCounter_unloaded = <value>` |
| data | `GameData` | RW | `obj.data = <value>` |
| isAI | `lightuserdata` | RW | `obj.isAI = <value>` |
| isPlayer | `PlayerInterface` | RW | `obj.isPlayer = <value>` |
| spawnTimeStamp | `integer` | RW | `obj.spawnTimeStamp = <value>` |
| diplomatTimeStamp | `integer` | RW | `obj.diplomatTimeStamp = <value>` |
| platoonIDs | `integer` | RW | `obj.platoonIDs = <value>` |
| p_TIME | `number` | RW | `obj.p_TIME = <value>` |
| platoonPeriodicUpdateIndex | `integer` | RW | `obj.platoonPeriodicUpdateIndex = <value>` |
| buildingSwaps | `lektor<Faction::BuildingSwaps>` | RW | `obj.buildingSwaps = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| setup | `_data: GameData` | `boolean` | `obj:setup(_data)` |
| setup2 | `` | `boolean` | `obj:setup2()` |
| setup3 | `` | `void` | `obj:setup3()` |
| getNewPlatoonID | `` | `string` | `obj:getNewPlatoonID()` |
| resetPlatoonID | `` | `void` | `obj:resetPlatoonID()` |
| createNewEmptyUnloadedPlatoon | `squadTemplate: GameData, pos: Vector3, forcecharacterDatas: GameDataContainer, persistent: boolean` | `Platoon` | `obj:createNewEmptyUnloadedPlatoon(squadTemplate, pos, forcecharacterDatas, persistent)` |
| createNewEmptyActivePlatoon | `squadTemplate: GameData, permanent: boolean, p: Vector3` | `Platoon` | `obj:createNewEmptyActivePlatoon(squadTemplate, permanent, p)` |
| createPlatoonUnloaded | `platoonstate: GameData, charactersState: GameDataContainer, squadTemplate: GameData, pos: Vector3, persistent: boolean` | `void` | `obj:createPlatoonUnloaded(platoonstate, charactersState, squadTemplate, pos, persistent)` |
| createPlatoonAuto | `platoonstate: GameData, squadTemplate: GameData, pos: Vector3` | `void` | `obj:createPlatoonAuto(platoonstate, squadTemplate, pos)` |
| createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | `src: string` | `void` | `obj:createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src)` |
| restorePlatoon | `p: Platoon` | `void` | `obj:restorePlatoon(p)` |
| resetSquadPositions | `target: Vector3` | `boolean` | `obj:resetSquadPositions(target)` |
| countPopulation | `t: TownBase` | `integer` | `obj:countPopulation(t)` |
| countNumSquads | `squadTemplate: GameData, squadHome: TownBase` | `integer` | `obj:countNumSquads(squadTemplate, squadHome)` |
| destroyPlatoon | `platoon: Platoon` | `void` | `obj:destroyPlatoon(platoon)` |
| removePlatoon | `platoon: Platoon` | `void` | `obj:removePlatoon(platoon)` |
| getRandomLockLevel | `objData: GameData` | `integer` | `obj:getRandomLockLevel(objData)` |
| getData | `` | `GameData` | `obj:getData()` |
| getGUIData | `panel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(panel, category)` |
| getDefaultDivision | `` | `GameData` | `obj:getDefaultDivision()` |
| getFactionColorScheme | `` | `GameData` | `obj:getFactionColorScheme()` |
| loadState | `saveSource: GameDataContainer, gamestate_faction: GameData` | `void` | `obj:loadState(saveSource, gamestate_faction)` |
| saveState | `container: GameDataContainer, leveleditor: boolean` | `GameData` | `obj:saveState(container, leveleditor)` |
| _activateUnloadedPlatoons | `` | `void` | `obj:_activateUnloadedPlatoons()` |
| getCharactersInArea | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| getSelectedObjects | `type: itemType, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| removeObject | `c: RootObject` | `void` | `obj:removeObject(c)` |
| destroyObject | `c: RootObject` | `void` | `obj:destroyObject(c)` |
| processKillList | `` | `void` | `obj:processKillList()` |
| addActiveObject | `c: RootObject, p: ActivePlatoon` | `boolean` | `obj:addActiveObject(c, p)` |
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
| getNumPlatoons | `squadTemplate: GameData, tempsOnly: boolean, hometown: TownBase` | `integer` | `obj:getNumPlatoons(squadTemplate, tempsOnly, hometown)` |
| getSquadThatOwns | `what: Building` | `Platoon` | `obj:getSquadThatOwns(what)` |
| getAllActiveSquads | `` | `void` | `obj:getAllActiveSquads()` |
| getRoadPreference | `` | `number` | `obj:getRoadPreference()` |
| isAntiSlavery | `` | `boolean` | `obj:isAntiSlavery()` |
| getLawEnforcementFaction | `` | `Faction` | `obj:getLawEnforcementFaction()` |
| chooseARace | `character: GameData, squadTemplate: GameData` | `GameData` | `obj:chooseARace(character, squadTemplate)` |
| setName | `_name: string` | `void` | `obj:setName(_name)` |
| getBuildingReplacement | `building: GameData` | `GameData` | `obj:getBuildingReplacement(building)` |
| _switchToUnloadedPlatoon | `platoon: ActivePlatoon` | `void` | `obj:_switchToUnloadedPlatoon(platoon)` |
| _newPlatoon | `f: Faction, squadTemplate: GameData, platoonState: GameData, pos: Vector3, persistent: boolean` | `Platoon` | `obj:_newPlatoon(f, squadTemplate, platoonState, pos, persistent)` |
| _addActivePlatoonToList | `platoon: Platoon` | `void` | `obj:_addActivePlatoonToList(platoon)` |
| addPlatoon | `platoon: Platoon` | `void` | `obj:addPlatoon(platoon)` |
| changePlatoonIndex | `platoon: Platoon, index: integer` | `void` | `obj:changePlatoonIndex(platoon, index)` |
| deactivatePlatoon | `p: Platoon` | `void` | `obj:deactivatePlatoon(p)` |
| activatePlatoon | `p: Platoon` | `void` | `obj:activatePlatoon(p)` |
| updateUnloadedPlatoons | `time: number` | `void` | `obj:updateUnloadedPlatoons(time)` |
| updateActivePlatoons | `time: number` | `void` | `obj:updateActivePlatoons(time)` |
| spawnSquadMissionsUpdate | `` | `void` | `obj:spawnSquadMissionsUpdate()` |
| _spawnASquad | `listname: string, sizeMultiplier: number` | `boolean` | `obj:_spawnASquad(listname, sizeMultiplier)` |
| getFundamentalNPCType | `` | `CharacterTypeEnum` | `obj:getFundamentalNPCType()` |

## Faction::BuildingSwaps
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`
**Parent Class:** [`Faction`](#faction)
**Metatable:** `KenshiLua.BuildingSwaps`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| toReplace | `ogre_unordered_set<GameData*>::type` | RW | `obj.toReplace = <value>` |
| replaceWith | `FitnessSelector<GameData*>` | RW | `obj.replaceWith = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: BuildingSwaps` | `void` | `obj:operator_assign(other)` |
| hasReplacement | `building: GameData` | `boolean` | `obj:hasReplacement(building)` |
| getReplacement | `building: GameData` | `GameData` | `obj:getReplacement(building)` |

## Faction::CharacteristicsData
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`
**Parent Class:** [`Faction`](#faction)
**Metatable:** `KenshiLua.Faction_CharacteristicsData`

## FactionLeader
**Header:** `extern/KenshiLib/Include/kenshi/FactionLeader.h`
**Metatable:** `KenshiLua.FactionLeader`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| faction | `Faction` | RW | `obj.faction = <value>` |
| worstEnemy | `Faction` | RW | `obj.worstEnemy = <value>` |
| biomeTerritory | `lektor<GameData*>` | RW | `obj.biomeTerritory = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setNewLeader | `_a1: Character` | `void` | `obj:setNewLeader(_a1)` |
| getEnemyMissionTargetList | `mission: GameData` | `void` | `obj:getEnemyMissionTargetList(mission)` |
| getGUIData | `_a1: DatapanelGUI, cat: integer` | `void` | `obj:getGUIData(_a1, cat)` |

## FactionManager
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`
**Metatable:** `KenshiLua.FactionManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| addListMuto | `integer` | RW | `obj.addListMuto = <value>` |
| participants | `lektor<Faction*>` | RW | `obj.participants = <value>` |
| toAddList | `lektor<Platoon*>` | RW | `obj.toAddList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| saveGameState | `container: GameDataContainer` | `void` | `obj:saveGameState(container)` |
| savePlayerGameState | `container: GameDataContainer` | `void` | `obj:savePlayerGameState(container)` |
| clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| activateUnloadedPlatoons | `` | `void` | `obj:activateUnloadedPlatoons()` |
| getOrCreateFaction [1] | `id: string, name: string` | `Faction` | `obj:getOrCreateFaction(id, name)` |
| getOrCreateFaction [2] | `data: GameData` | `Faction` | `obj:getOrCreateFaction(data)` |
| getFactionByName | `name: string` | `Faction` | `obj:getFactionByName(name)` |
| getFactionByStringID | `sid: string` | `Faction` | `obj:getFactionByStringID(sid)` |
| getEmptyFaction | `` | `Faction` | `obj:getEmptyFaction()` |
| setupAndLinkAllFactions | `` | `void` | `obj:setupAndLinkAllFactions()` |
| getFactionBySquad | `squadtemplate: GameData` | `Faction` | `obj:getFactionBySquad(squadtemplate)` |
| getCampaignGUIInfos | `pan: DatapanelGUI, cat: integer, playeronly: boolean` | `void` | `obj:getCampaignGUIInfos(pan, cat, playeronly)` |
| areAnyHostileCampaignsRunning | `` | `boolean` | `obj:areAnyHostileCampaignsRunning()` |
| getNumTempPlatoons | `` | `integer` | `obj:getNumTempPlatoons()` |
| updateMT | `time: number` | `void` | `obj:updateMT(time)` |
| updateThreaded | `time: number` | `void` | `obj:updateThreaded(time)` |
| _showDebugPlatoonMarkers | `on: boolean` | `void` | `obj:_showDebugPlatoonMarkers(on)` |
| getAllFactions | `` | `lektor<Faction*>` | `obj:getAllFactions()` |

## FactionRelations
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`
**Metatable:** `KenshiLua.FactionRelations`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | `Faction` | RW | `obj.me = <value>` |
| playerRank | `integer` | RW | `obj.playerRank = <value>` |
| globalReputationTrust | `number` | RW | `obj.globalReputationTrust = <value>` |
| globalReputationForBadassery | `number` | RW | `obj.globalReputationForBadassery = <value>` |
| _factionRelations | `ogre_unordered_map<Faction*, FactionRelationData>` | RW | `obj._factionRelations = <value>` |
| defaultFactionRelation | `number` | RW | `obj.defaultFactionRelation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupPhase2 | `` | `void` | `obj:setupPhase2()` |
| isEnemyByDefault | `` | `boolean` | `obj:isEnemyByDefault()` |
| reset | `` | `void` | `obj:reset()` |
| update | `` | `void` | `obj:update()` |
| setupPhase1 | `f: Faction` | `void` | `obj:setupPhase1(f)` |
| save [1] | `factionsList: GameData` | `void` | `obj:save(factionsList)` |
| save [2] | `factionsList: GameData, ID: string, who: Faction` | `void` | `obj:save(factionsList, ID, who)` |
| load [1] | `gamestate_faction: GameData, playerOnly: boolean` | `void` | `obj:load(gamestate_faction, playerOnly)` |
| load [2] | `gamestate_faction: GameData, ID: string, who: Faction` | `void` | `obj:load(gamestate_faction, ID, who)` |
| _isAlly | `c: Faction` | `boolean` | `obj:_isAlly(c)` |
| _isEnemy | `c: Faction` | `boolean` | `obj:_isEnemy(c)` |
| isEnemy | `c: Faction` | `boolean` | `obj:isEnemy(c)` |
| setEnemy | `c: Faction` | `void` | `obj:setEnemy(c)` |
| isAlly | `c: Faction` | `boolean` | `obj:isAlly(c)` |
| isCoexisting | `c: Faction` | `boolean` | `obj:isCoexisting(c)` |
| getFactionRelation | `p: Faction` | `number` | `obj:getFactionRelation(p)` |
| getFactionRelationMultiplier | `p: Faction` | `number` | `obj:getFactionRelationMultiplier(p)` |
| getFactionRelationMultiplierInverse | `p: Faction` | `number` | `obj:getFactionRelationMultiplierInverse(p)` |
| setRelation | `who: Faction, setTo: number` | `void` | `obj:setRelation(who, setTo)` |
| affectRelations [1] | `p: Faction, e: FactionEvent, mult: number` | `void` | `obj:affectRelations(p, e, mult)` |
| affectRelations [2] | `p: Faction, amount: number, mult: number` | `void` | `obj:affectRelations(p, amount, mult)` |
| affectTrust | `p: Faction, amount: number, mult: number` | `void` | `obj:affectTrust(p, amount, mult)` |
| setNoLongerEnemies | `p: Faction` | `void` | `obj:setNoLongerEnemies(p)` |
| declareWar | `p: Faction` | `void` | `obj:declareWar(p)` |
| affectReputation | `p: Faction, amount: number` | `void` | `obj:affectReputation(p, amount)` |
| getRelationData | `p: Faction` | `FactionRelations::RelationData` | `obj:getRelationData(p)` |
| getGUIData | `panel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(panel, category)` |
| getRelationsData | `` | `void` | `obj:getRelationsData()` |
| checkStateCondition | `conditionName: DialogConditionEnum, compareBy: ComparisonEnum, val: integer, yourFaction: Faction` | `boolean` | `obj:checkStateCondition(conditionName, compareBy, val, yourFaction)` |

## FactionRelations::RelationData
**Header:** `extern/KenshiLib/Include/kenshi/FactionRelations.h`
**Parent Class:** [`FactionRelations`](#factionrelations)
**Metatable:** `KenshiLua.RelationData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| alliance | `boolean` | RW | `obj.alliance = <value>` |
| peaceTreaty | `boolean` | RW | `obj.peaceTreaty = <value>` |
| war | `boolean` | RW | `obj.war = <value>` |
| coexists | `boolean` | RW | `obj.coexists = <value>` |
| relation | `number` | RW | `obj.relation = <value>` |
| trustPositives | `number` | RW | `obj.trustPositives = <value>` |
| trustNegatives | `number` | RW | `obj.trustNegatives = <value>` |
| percievedStrength | `number` | RW | `obj.percievedStrength = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| save | `factionsList: GameData, ID: string, who: Faction` | `void` | `obj:save(factionsList, ID, who)` |
| load | `gamestate_faction: GameData, ID: string, who: Faction` | `void` | `obj:load(gamestate_faction, ID, who)` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## FactionsScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`
**Metatable:** `KenshiLua.FactionsScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mainWidget | `MyGUI::Widget` | R | `obj.mainWidget` |
| selectedFaction | `Faction` | RW | `obj.selectedFaction = <value>` |
| scrollList | `MyGUI::Widget` | RW | `obj.scrollList = <value>` |
| scrollListItemTop | `integer` | RW | `obj.scrollListItemTop = <value>` |
| scrollListItemWidth | `integer` | RW | `obj.scrollListItemWidth = <value>` |
| nameText | `MyGUI::Widget` | R | `obj.nameText` |
| infoPanel | `DatapanelGUI` | RW | `obj.infoPanel = <value>` |
| lines | `FactionLinesMapBinding::MapType` | RW | `obj.lines = <value>` |
| updateTimer | `number` | RW | `obj.updateTimer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getVisible | `` | `boolean` | `obj:getVisible()` |
| clear | `` | `void` | `obj:clear()` |
| update | `` | `void` | `obj:update()` |
| refresh | `` | `void` | `obj:refresh()` |
| updateInfo | `` | `void` | `obj:updateInfo()` |
| notifyEditTextChange | `sender: MyGUI::EditBox` | `void` | `obj:notifyEditTextChange(sender)` |
| setFocus | `a1: MyGUI::Widget, a2: MyGUI::Widget` | `void` | `obj:setFocus(a1, a2)` |
| loseFocus | `a1: MyGUI::Widget, a2: MyGUI::Widget` | `void` | `obj:loseFocus(a1, a2)` |
| factionLineSelected | `sender: MyGUI::Widget` | `void` | `obj:factionLineSelected(sender)` |
| notifyMouseWheel | `sender: MyGUI::Widget, rel: integer` | `void` | `obj:notifyMouseWheel(sender, rel)` |

## FactionsScreen::FactionRelationsLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`
**Parent Class:** [`FactionsScreen`](#factionsscreen)
**Metatable:** `KenshiLua.FactionRelationsLine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| faction | `Faction` | RW | `obj.faction = <value>` |
| value | `number` | RW | `obj.value = <value>` |
| valueText | `MyGUI::Widget` | R | `obj.valueText` |
| leftBar | `MyGUI::Widget` | R | `obj.leftBar` |
| rightBar | `MyGUI::Widget` | R | `obj.rightBar` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |

## FactionsScreen::FactionRelationsLine::LessSort
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`
**Parent Class:** [`FactionsScreen`](#factionsscreen)
**Metatable:** `KenshiLua.FactionsScreen_FactionRelationsLine_LessSort`

## FactionUniqueSquadManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`
**Metatable:** `KenshiLua.FactionUniqueSquadManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| prosperityMgr | `ProsperityManager` | RW | `obj.prosperityMgr = <value>` |
| me | `Faction` | RW | `obj.me = <value>` |
| squadListData | `GameData` | RW | `obj.squadListData = <value>` |
| homeTown | `Town` | RW | `obj.homeTown = <value>` |
| squads | `unknown` | RW | `obj.squads = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clearAndReset | `` | `void` | `obj:clearAndReset()` |
| initialiseNew | `faction: Faction, mdat: GameData, t: Town` | `void` | `obj:initialiseNew(faction, mdat, t)` |
| chooseRandomSquadToSpawn | `time: number` | `GameData` | `obj:chooseRandomSquadToSpawn(time)` |
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| serialise | `state: GameData` | `void` | `obj:serialise(state)` |
| load | `state: GameData, import: boolean` | `void` | `obj:load(state, import)` |
| getGUIData | `panel: DatapanelGUI, cat: integer` | `void` | `obj:getGUIData(panel, cat)` |
| getExistingSquadsFor | `squad: GameData` | `FactionUniqueSquadManager::UniqueSpawnData` | `obj:getExistingSquadsFor(squad)` |
| spawnNewUniqueSquad | `squadtemplate: GameData` | `lightuserdata` | `obj:spawnNewUniqueSquad(squadtemplate)` |
| endOfUniqueSquad | `who: userdata` | `void` | `obj:endOfUniqueSquad(who)` |

## FactionUniqueSquadManager::UniqueSpawnData
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`
**Parent Class:** [`FactionUniqueSquadManager`](#factionuniquesquadmanager)
**Metatable:** `KenshiLua.UniqueSpawnData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| squadTemplate | `GameData` | RW | `obj.squadTemplate = <value>` |
| desiredNumberToHave | `integer` | RW | `obj.desiredNumberToHave = <value>` |
| respawnTimer | `number` | RW | `obj.respawnTimer = <value>` |
| existingSquadsList | `lektor<hand>` | RW | `obj.existingSquadsList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| currentNumber | `` | `integer` | `obj:currentNumber()` |

## FactionWarMgr
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`
**Metatable:** `KenshiLua.FactionWarMgr`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | `Faction` | RW | `obj.me = <value>` |
| lastID | `integer` | RW | `obj.lastID = <value>` |
| nextUpdateTime | `TimeOfDay` | RW | `obj.nextUpdateTime = <value>` |
| myTowns | `lektor<TownBase*>` | RW | `obj.myTowns = <value>` |
| hiredForces | `lektor<hand>` | RW | `obj.hiredForces = <value>` |
| activeCampaigns | `lightuserdata` | RW | `obj.activeCampaigns = <value>` |
| biomeTerritories | `lightuserdata` | RW | `obj.biomeTerritories = <value>` |
| biomeNoGoZones | `lightuserdata` | RW | `obj.biomeNoGoZones = <value>` |
| campaignRequests | `unknown` | RW | `obj.campaignRequests = <value>` |
| possibleCampaigns | `lightuserdata` | RW | `obj.possibleCampaigns = <value>` |
| forces | `lightuserdata` | RW | `obj.forces = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| save | `s: GameData` | `void` | `obj:save(s)` |
| load | `s: GameData` | `void` | `obj:load(s)` |
| removePlatoon | `p: Platoon` | `void` | `obj:removePlatoon(p)` |
| addPlatoon | `p: Platoon` | `void` | `obj:addPlatoon(p)` |
| getGUIData | `panel: DatapanelGUI, cat: integer, playeronly: boolean` | `void` | `obj:getGUIData(panel, cat, playeronly)` |
| areAnyHostileCampaignsRunning | `playeronly: boolean` | `boolean` | `obj:areAnyHostileCampaignsRunning(playeronly)` |
| endCampaign | `c: userdata` | `void` | `obj:endCampaign(c)` |
| getAllTheForces | `target: RootObjectBase, c: userdata` | `void` | `obj:getAllTheForces(target, c)` |
| _generateForcesForTown | `t: TownBase, c: userdata` | `void` | `obj:_generateForcesForTown(t, c)` |
| canGenerateThisManyForces | `num: integer` | `boolean` | `obj:canGenerateThisManyForces(num)` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| debugButton | `` | `void` | `obj:debugButton()` |
| triggerCampaign [1] | `targetTown: RootObjectBase, data: CampaignData, home: TownBase` | `CampaignInstance` | `obj:triggerCampaign(targetTown, data, home)` |
| triggerCampaign [2] | `targetTown: RootObjectBase, _data: GameData, minTime: number, maxTime: number, hometown: TownBase, forceDuplicate: boolean, triggeringFaction: Faction` | `void` | `obj:triggerCampaign(targetTown, _data, minTime, maxTime, hometown, forceDuplicate, triggeringFaction)` |
| triggerCampaign [3] | `randomTriggers: FitnessSelector<CampaignTriggerData*>, targetTown: RootObjectBase, hometown: TownBase, forceDuplicate: boolean, triggeringFaction: Faction` | `void` | `obj:triggerCampaign(randomTriggers, targetTown, hometown, forceDuplicate, triggeringFaction)` |
| getCurrentCampaign | `who: Platoon` | `lightuserdata` | `obj:getCurrentCampaign(who)` |
| getAITarget | `who: Platoon` | `hand` | `obj:getAITarget(who)` |
| getMyUnloadedAI | `who: Platoon` | `UnloadedPlatoonJob` | `obj:getMyUnloadedAI(who)` |
| isBiomeHomeTerritory | `area: userdata` | `boolean` | `obj:isBiomeHomeTerritory(area)` |
| getNearestTown | `p: Vector3` | `TownBase` | `obj:getNearestTown(p)` |
| getTownsInBiome | `b: userdata` | `void` | `obj:getTownsInBiome(b)` |
| getMyTownsWithEnoughFreePopulation | `popNeeded: integer` | `void` | `obj:getMyTownsWithEnoughFreePopulation(popNeeded)` |
| getActiveCampaign | `uniqueID: integer` | `lightuserdata` | `obj:getActiveCampaign(uniqueID)` |
| setup | `` | `void` | `obj:setup()` |
| _createCampaignData | `dat: GameData` | `lightuserdata` | `obj:_createCampaignData(dat)` |

## FactionWarMgr::CampaignRequest
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`
**Parent Class:** [`FactionWarMgr`](#factionwarmgr)
**Metatable:** `KenshiLua.CampaignRequest`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeToStart | `TimeOfDay` | RW | `obj.timeToStart = <value>` |
| data | `lightuserdata` | R | `obj.data` |
| target | `hand` | RW | `obj.target = <value>` |
| homeBase | `hand` | RW | `obj.homeBase = <value>` |
| enemy | `Faction` | RW | `obj.enemy = <value>` |
| numAttempts | `integer` | RW | `obj.numAttempts = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| tryToChangeTarget | `` | `boolean` | `obj:tryToChangeTarget()` |

## FactoryCallbackInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`
**Metatable:** `KenshiLua.FactoryCallbackInterface`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| factoryObjectCreatedCallback | `_a1: RootObject` | `void` | `obj:factoryObjectCreatedCallback(_a1)` |

## FarmBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Metatable:** `KenshiLua.FarmBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cropMultipliers | `ogre_unordered_map<CropType, float>::type` | RW | `obj.cropMultipliers = <value>` |
| material | `lightuserdata` | R | `obj.material` |
| plantEntity | `lightuserdata` | RW | `obj.plantEntity = <value>` |
| plants | `lektor<FarmBuilding::Plant>` | RW | `obj.plants = <value>` |
| clickHull | `lightuserdata` | RW | `obj.clickHull = <value>` |
| batch | `FarmBuilding::FarmBatch` | RW | `obj.batch = <value>` |
| lastUpdated | `number` | RW | `obj.lastUpdated = <value>` |
| eatingTime | `number` | RW | `obj.eatingTime = <value>` |
| grown | `number` | RW | `obj.grown = <value>` |
| died | `number` | RW | `obj.died = <value>` |
| cleared | `number` | RW | `obj.cleared = <value>` |
| growStart | `number` | RW | `obj.growStart = <value>` |
| harvested | `integer` | RW | `obj.harvested = <value>` |
| itemsPerPlant | `number` | RW | `obj.itemsPerPlant = <value>` |
| clearRate | `number` | RW | `obj.clearRate = <value>` |
| consumptionRate | `number` | RW | `obj.consumptionRate = <value>` |
| harvestRate | `number` | RW | `obj.harvestRate = <value>` |
| growthTime | `number` | RW | `obj.growthTime = <value>` |
| harvestTime | `number` | RW | `obj.harvestTime = <value>` |
| deathTime | `number` | RW | `obj.deathTime = <value>` |
| droughtTime | `number` | RW | `obj.droughtTime = <value>` |
| deathThreshold | `number` | RW | `obj.deathThreshold = <value>` |
| droughtMultiplier | `number` | RW | `obj.droughtMultiplier = <value>` |
| fertilityMultiplier | `number` | RW | `obj.fertilityMultiplier = <value>` |
| isHydroponic | `boolean` | RW | `obj.isHydroponic = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| update | `` | `void` | `obj:update()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| operate | `who: Character, amount: number` | `void` | `obj:operate(who, amount)` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getGUIEfficiency | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIEfficiency(datapanel, category)` |
| getGUIWorkers | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIWorkers(datapanel, category)` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |
| destroyAPlant | `` | `boolean` | `obj:destroyAPlant()` |
| timeSkip | `h: number, ignoreWater: boolean` | `void` | `obj:timeSkip(h, ignoreWater)` |
| _updateInputs | `rate: number` | `boolean` | `obj:_updateInputs(rate)` |
| upgrade | `line: DataPanelLine` | `void` | `obj:upgrade(line)` |
| downgrade | `line: DataPanelLine` | `void` | `obj:downgrade(line)` |
| getGUIFertility | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIFertility(datapanel, category)` |
| isCropsEdible | `` | `boolean` | `obj:isCropsEdible()` |
| eat | `rate: number` | `void` | `obj:eat(rate)` |
| getYieldChancePerCrop [1] | `farmData: GameData, biome: AreaBiomeGroup, skillMult: number, resourceMult: number` | `number` | `obj:getYieldChancePerCrop(farmData, biome, skillMult, resourceMult)` |
| getYieldChancePerCrop [2] | `skillMult: number` | `number` | `obj:getYieldChancePerCrop(skillMult)` |
| getCropMult | `typ: CropType` | `number` | `obj:getCropMult(typ)` |
| serialise | `container: GameDataContainer, refList: GameData, offsetPosToSubtract: userdata` | `GameSaveState` | `obj:serialise(container, refList, offsetPosToSubtract)` |
| loadFromSerialise | `stateList: GameSaveState` | `void` | `obj:loadFromSerialise(stateList)` |
| getDirectionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| getFertilityMultiplier | `farmData: GameData` | `number` | `obj:getFertilityMultiplier(farmData)` |
| setupMaterial | `` | `void` | `obj:setupMaterial()` |
| updateMaterial | `` | `void` | `obj:updateMaterial()` |
| updatePlantInstance | `p: FarmBuilding::Plant` | `void` | `obj:updatePlantInstance(p)` |
| createPlants | `batch: FarmBuilding::FarmBatch` | `void` | `obj:createPlants(batch)` |
| createClickHull | `batch: FarmBuilding::FarmBatch` | `void` | `obj:createClickHull(batch)` |
| createEntity | `batch: FarmBuilding::FarmBatch` | `void` | `obj:createEntity(batch)` |
| resetFarm | `` | `void` | `obj:resetFarm()` |

## FarmBuilding::FarmBatch
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Parent Class:** [`FarmBuilding`](#farmbuilding)
**Metatable:** `KenshiLua.FarmBatch`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| plantSource | `lektor<FarmBuilding::PlantSource*>` | RW | `obj.plantSource = <value>` |
| plantGroups | `lektor<int>` | RW | `obj.plantGroups = <value>` |
| geometry | `lightuserdata` | R | `obj.geometry` |
| height | `number` | RW | `obj.height = <value>` |
| size | `integer` | RW | `obj.size = <value>` |
| meshesLoaded | `integer` | RW | `obj.meshesLoaded = <value>` |
| farms | `lektor<FarmBuilding*>` | RW | `obj.farms = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| load | `` | `void` | `obj:load()` |
| meshLoaded | `res: userdata, entityData: userdata` | `void` | `obj:meshLoaded(res, entityData)` |
| createGeometry | `` | `void` | `obj:createGeometry()` |

## FarmBuilding::Plant
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Parent Class:** [`FarmBuilding`](#farmbuilding)
**Metatable:** `KenshiLua.FarmBuilding_Plant`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## FarmBuilding::PlantSource
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Parent Class:** [`FarmBuilding`](#farmbuilding)
**Metatable:** `KenshiLua.FarmBuilding_PlantSource`

## FarmBuilding::SubPlant
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Parent Class:** [`FarmBuilding`](#farmbuilding)
**Metatable:** `KenshiLua.FarmBuilding_SubPlant`

## FloatingProgressBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/ForgottenGUI.h`
**Metatable:** `KenshiLua.FloatingProgressBar`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| caption | `string` | RW | `obj.caption = <value>` |
| progress | `integer` | RW | `obj.progress = <value>` |
| bar | `FloatingProgressBar::ProgressBarWidget` | RW | `obj.bar = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setProgress | `value: number` | `void` | `obj:setProgress(value)` |
| setCaption | `value: string` | `void` | `obj:setCaption(value)` |
| update | `` | `void` | `obj:update()` |

## FloatingProgressBar::ProgressBarWidget
**Header:** `extern/KenshiLib/Include/kenshi/gui/ForgottenGUI.h`
**Parent Class:** [`FloatingProgressBar`](#floatingprogressbar)
**Metatable:** `KenshiLua.ProgressBarWidget`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bar | `MyGUI::Widget` | R | `obj.bar` |
| label | `MyGUI::Widget` | R | `obj.label` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| setProgress | `value: integer` | `void` | `obj:setProgress(value)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setCaption | `value: string` | `void` | `obj:setCaption(value)` |

## FlockingTools
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.FlockingTools`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| getOutOfTheWayOfCharacter | `hand` | RW | `obj.getOutOfTheWayOfCharacter = <value>` |
| currentPosition | `Vector3` | RW | `obj.currentPosition = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| combatMover | `CombatMovementController` | RW | `obj.combatMover = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| create | `chme: Character, c: CombatMovementController` | `void` | `obj:create(chme, c)` |
| getDistanceToClosestCharacter | `enemies: boolean, allies: boolean, skip: hand` | `number` | `obj:getDistanceToClosestCharacter(enemies, allies, skip)` |
| getOutOfTheWay | `caller: hand` | `void` | `obj:getOutOfTheWay(caller)` |
| setCurrentPosition | `_pos: Vector3` | `void` | `obj:setCurrentPosition(_pos)` |
| getRepulsionMagnitude | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `number` | `obj:getRepulsionMagnitude(repulsionPoint, MAX_DISTANCE, distance)` |
| getRepulsionVector | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `Vector3` | `obj:getRepulsionVector(repulsionPoint, MAX_DISTANCE, distance)` |
| clampRepulsionVectorTo90Degrees | `desiredDirection: Vector3, alwaysStrafe: boolean` | `Vector3` | `obj:clampRepulsionVectorTo90Degrees(desiredDirection, alwaysStrafe)` |
| calculateCurrentRepulsionVector | `MAX_DISTANCE: number, desiredDirection: Vector3, skip: Character, includeEnemies: boolean, includeFriends: boolean, strafeOnly: boolean` | `Vector3` | `obj:calculateCurrentRepulsionVector(MAX_DISTANCE, desiredDirection, skip, includeEnemies, includeFriends, strafeOnly)` |
| getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |

## FogEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/FogEditor.h`
**Metatable:** `KenshiLua.FogEditor`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | `MyGUI::Widget` | R | `obj.window` |
| fogList | `MyGUI::Widget` | R | `obj.fogList` |
| typeList | `MyGUI::Widget` | R | `obj.typeList` |
| panel | `DatapanelGUI` | RW | `obj.panel = <value>` |
| selectedFog | `lightuserdata` | R | `obj.selectedFog` |
| selectedSide | `integer` | RW | `obj.selectedSide = <value>` |
| colour | `Vector3` | RW | `obj.colour = <value>` |
| distance | `number` | RW | `obj.distance = <value>` |
| radius | `number` | RW | `obj.radius = <value>` |
| edge | `number` | RW | `obj.edge = <value>` |
| editCage | `lightuserdata` | R | `obj.editCage` |
| editNode | `lightuserdata` | R | `obj.editNode` |
| editPos | `Vector3` | RW | `obj.editPos = <value>` |
| editRot | `Quaternion` | RW | `obj.editRot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| show | `` | `void` | `obj:show()` |
| close | `` | `void` | `obj:close()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| update | `` | `boolean` | `obj:update()` |
| save | `filename: string` | `void` | `obj:save(filename)` |
| updateFogName | `line: DataPanelLine` | `void` | `obj:updateFogName(line)` |
| updateFogValues | `_a1: DataPanelLine` | `void` | `obj:updateFogValues(_a1)` |
| selectNextEdge | `_a1: DataPanelLine` | `void` | `obj:selectNextEdge(_a1)` |

## FoliageSystem
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`
**Metatable:** `KenshiLua.FoliageSystem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| reloaded | `boolean` | RW | `obj.reloaded = <value>` |
| generateOverlay | `boolean` | RW | `obj.generateOverlay = <value>` |
| firstTimeLoad | `boolean` | RW | `obj.firstTimeLoad = <value>` |
| collisionHash | `integer` | RW | `obj.collisionHash = <value>` |
| loadComplete | `boolean` | RW | `obj.loadComplete = <value>` |
| zoneMap | `ZoneMap` | RW | `obj.zoneMap = <value>` |
| coverageMap | `lightuserdata` | R | `obj.coverageMap` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| getCollisionHash | `` | `integer` | `obj:getCollisionHash()` |
| setupGrass | `layerData: GameData, paged: userdata, grassLoader: userdata, biomeCode: integer` | `void` | `obj:setupGrass(layerData, paged, grassLoader, biomeCode)` |
| setupFoliage | `dat: GameData, paged: userdata, treeLoader: userdata, biomeCode: integer` | `void` | `obj:setupFoliage(dat, paged, treeLoader, biomeCode)` |
| spawn | `ent: userdata, position: Vector3, _treeLoader: userdata` | `boolean` | `obj:spawn(ent, position, _treeLoader)` |
| randomInt | `min: integer, max: integer` | `integer` | `obj:randomInt(min, max)` |
| random | `min: number, max: number` | `number` | `obj:random(min, max)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clearStaticData | `` | `void` | `FoliageSystem.clearStaticData()`<br>`obj:clearStaticData()` |

## FoliageSystem::EntData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`FoliageSystem`](#foliagesystem)
**Metatable:** `KenshiLua.EntData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `GameData` | RW | `obj.data = <value>` |
| maxSlope | `number` | RW | `obj.maxSlope = <value>` |
| minSlope | `number` | RW | `obj.minSlope = <value>` |
| chance | `number` | RW | `obj.chance = <value>` |
| minAltitude | `number` | RW | `obj.minAltitude = <value>` |
| maxAltitude | `number` | RW | `obj.maxAltitude = <value>` |
| slopeAlign | `boolean` | RW | `obj.slopeAlign = <value>` |
| floating | `boolean` | RW | `obj.floating = <value>` |
| uniformScale | `boolean` | RW | `obj.uniformScale = <value>` |
| scales | `Vector4` | RW | `obj.scales = <value>` |
| accurateTrace | `boolean` | RW | `obj.accurateTrace = <value>` |
| upright | `boolean` | RW | `obj.upright = <value>` |
| minV | `number` | RW | `obj.minV = <value>` |
| maxV | `number` | RW | `obj.maxV = <value>` |
| clustered | `boolean` | RW | `obj.clustered = <value>` |
| limitToGrassAreas | `boolean` | RW | `obj.limitToGrassAreas = <value>` |
| nonBatched | `boolean` | RW | `obj.nonBatched = <value>` |
| carveRadius | `number` | RW | `obj.carveRadius = <value>` |
| grassSpot | `number` | RW | `obj.grassSpot = <value>` |
| roadRadius | `number` | RW | `obj.roadRadius = <value>` |
| clusterMin | `number` | RW | `obj.clusterMin = <value>` |
| clusterMax | `number` | RW | `obj.clusterMax = <value>` |
| clusterRadiusMin | `number` | RW | `obj.clusterRadiusMin = <value>` |
| clusterRadiusMax | `number` | RW | `obj.clusterRadiusMax = <value>` |
| viewDistance | `number` | RW | `obj.viewDistance = <value>` |
| seedOffset | `integer` | RW | `obj.seedOffset = <value>` |
| biomeSeparation | `boolean` | RW | `obj.biomeSeparation = <value>` |
| childClusterRadius | `number` | RW | `obj.childClusterRadius = <value>` |
| xmlFilename | `string` | RW | `obj.xmlFilename = <value>` |
| entity1 | `lightuserdata` | RW | `obj.entity1 = <value>` |
| entity2 | `lightuserdata` | RW | `obj.entity2 = <value>` |
| entity1Loaded | `boolean` | RW | `obj.entity1Loaded = <value>` |
| entity2Loaded | `boolean` | RW | `obj.entity2Loaded = <value>` |
| position | `Vector3` | RW | `obj.position = <value>` |
| type | `itemType` | RW | `obj.type = <value>` |
| referenceCount | `integer` | RW | `obj.referenceCount = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createEntity1 | `` | `lightuserdata` | `obj:createEntity1()` |
| createEntity2 | `` | `lightuserdata` | `obj:createEntity2()` |
| selectBiomeEntity | `position: Vector3` | `lightuserdata` | `obj:selectBiomeEntity(position)` |
| isLoaded | `` | `boolean` | `obj:isLoaded()` |

## FoliageSystem::TreeData
**Header:** `extern/KenshiLib/Include/kenshi/FoliageSystem.h`
**Parent Class:** [`FoliageSystem`](#foliagesystem)
**Metatable:** `KenshiLua.TreeData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| position | `Vector3` | RW | `obj.position = <value>` |
| scale | `number` | RW | `obj.scale = <value>` |
| target | `lightuserdata` | R | `obj.target` |
| building | `Building` | RW | `obj.building = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: TreeData` | `void` | `obj:operator_assign(other)` |

## ForgottenGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ForgottenGUI.h`
**Metatable:** `KenshiLua.ForgottenGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| hasMouse | `boolean` | RW | `obj.hasMouse = <value>` |
| mainbar | `MainBarGUI` | RW | `obj.mainbar = <value>` |
| tooltip | `ToolTip` | RW | `obj.tooltip = <value>` |
| dialogue | `DialogueWindow` | RW | `obj.dialogue = <value>` |
| tutorial | `TutorialGUI` | RW | `obj.tutorial = <value>` |
| tutorialpedia | `TutorialpediaGUI` | RW | `obj.tutorialpedia = <value>` |
| currentCursor | `CursorType` | RW | `obj.currentCursor = <value>` |
| Scale | `Vector2` | RW | `obj.Scale = <value>` |
| manager | `MyGUI::Gui` | R | `obj.manager` |
| guiPlatform | `lightuserdata` | R | `obj.guiPlatform` |
| _closeTradeWindowMsg | `boolean` | RW | `obj._closeTradeWindowMsg = <value>` |
| _showTradeWindowMsg | `TradeWindowType` | RW | `obj._showTradeWindowMsg = <value>` |
| tradeA | `hand` | RW | `obj.tradeA = <value>` |
| tradeB | `hand` | RW | `obj.tradeB = <value>` |
| inventoryWindowBuilding | `hand` | RW | `obj.inventoryWindowBuilding = <value>` |
| inventoryWindowCharacter | `hand` | RW | `obj.inventoryWindowCharacter = <value>` |
| inventoryWindowTrader | `hand` | RW | `obj.inventoryWindowTrader = <value>` |
| inventoryWindowNPC | `hand` | RW | `obj.inventoryWindowNPC = <value>` |
| characterEditor | `CharacterEditWindow` | RW | `obj.characterEditor = <value>` |
| guiScreenLabelsMutex | `lightuserdata` | R | `obj.guiScreenLabelsMutex` |
| selectedObject | `hand` | RW | `obj.selectedObject = <value>` |
| selectedPlayerCharacter | `hand` | RW | `obj.selectedPlayerCharacter = <value>` |
| cursorPanel | `DatapanelGUI` | RW | `obj.cursorPanel = <value>` |
| cursorAction | `boolean` | RW | `obj.cursorAction = <value>` |
| cursorActionPlayer | `hand` | RW | `obj.cursorActionPlayer = <value>` |
| cursorActionTarget | `hand` | RW | `obj.cursorActionTarget = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| created | `boolean` | RW | `obj.created = <value>` |
| inventoryWindowsOpen | `ForgottenInventoryWindowsOpenMapBinding::MapType` | RW | `obj.inventoryWindowsOpen = <value>` |
| inventoryWindowsPermanent | `ForgottenInventoryWindowsPermanentSetBinding::SetType` | RW | `obj.inventoryWindowsPermanent = <value>` |
| guiWindows | `lektor<GUIWindow*>` | RW | `obj.guiWindows = <value>` |
| guiDatapanels | `lektor<DatapanelGUI*>` | RW | `obj.guiDatapanels = <value>` |
| guiScreenLabels | `lektor<ScreenLabelInterface*>` | RW | `obj.guiScreenLabels = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
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
| notifyTownDeleted | `t: Town` | `void` | `obj:notifyTownDeleted(t)` |
| update | `` | `void` | `obj:update()` |
| closeTradeWindow | `` | `void` | `obj:closeTradeWindow()` |
| closeInventoryBuilding | `` | `void` | `obj:closeInventoryBuilding()` |
| closeAllInventories | `` | `void` | `obj:closeAllInventories()` |
| closeAllWindows | `` | `void` | `obj:closeAllWindows()` |
| getNumOpenInventoryWindows | `` | `integer` | `obj:getNumOpenInventoryWindows()` |
| getInventoryWindowWithMouse | `` | `InventoryGUI` | `obj:getInventoryWindowWithMouse()` |
| isAnyInventoryWindowOpen | `` | `boolean` | `obj:isAnyInventoryWindowOpen()` |
| toggleHelpWindow | `` | `void` | `obj:toggleHelpWindow()` |
| addWindowToUpdateList | `win: GUIWindow` | `void` | `obj:addWindowToUpdateList(win)` |
| removeWindowFromUpdateList | `win: GUIWindow` | `void` | `obj:removeWindowFromUpdateList(win)` |
| addDatapanelToUpdateList | `datapanel: DatapanelGUI` | `void` | `obj:addDatapanelToUpdateList(datapanel)` |
| removeDatapanelFromUpdateList | `datapanel: DatapanelGUI` | `void` | `obj:removeDatapanelFromUpdateList(datapanel)` |
| setMouseCursorVisible | `visible: boolean` | `void` | `obj:setMouseCursorVisible(visible)` |
| getGuiManager | `` | `MyGUI::Gui` | `obj:getGuiManager()` |
| createPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `MyGUI::Widget` | `obj:createPanel(name, top, left, width, height, layer, skin)` |
| createPanelAbs | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `MyGUI::Widget` | `obj:createPanelAbs(name, top, left, width, height, layer, skin)` |
| createTabPanel | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `MyGUI::Widget` | `obj:createTabPanel(name, top, left, width, height, layer, skin)` |
| createFloatingImage | `image: string, top: number, left: number, width: number, height: number, layer: string` | `MyGUI::Widget` | `obj:createFloatingImage(image, top, left, width, height, layer)` |
| createFloatingImageAbs | `image: string, top: number, left: number, width: number, height: number, layer: string` | `MyGUI::Widget` | `obj:createFloatingImageAbs(image, top, left, width, height, layer)` |
| createFloatingProgressBar | `` | `FloatingProgressBar` | `obj:createFloatingProgressBar()` |
| createScreenLabelD | `text: string, time: number` | `lightuserdata` | `obj:createScreenLabelD(text, time)` |
| showCharacterStatsWindow | `owner: hand` | `void` | `obj:showCharacterStatsWindow(owner)` |
| closeCharacterStatsWindow | `owner: hand` | `void` | `obj:closeCharacterStatsWindow(owner)` |
| toggleStatsWindow | `owner: hand` | `void` | `obj:toggleStatsWindow(owner)` |
| toggleCharacterStatsWindowPermanent | `owner: hand` | `void` | `obj:toggleCharacterStatsWindowPermanent(owner)` |
| showInventory | `owner: hand, autoPosition: boolean, x: number, y: number` | `InventoryGUI` | `obj:showInventory(owner, autoPosition, x, y)` |
| showTraderInventory | `owner: hand` | `InventoryGUI` | `obj:showTraderInventory(owner)` |
| showInventoryBuilding | `owner: hand` | `InventoryGUI` | `obj:showInventoryBuilding(owner)` |
| showInventoryNPC | `owner: hand` | `InventoryGUI` | `obj:showInventoryNPC(owner)` |
| closeInventory | `owner: hand` | `void` | `obj:closeInventory(owner)` |
| getInventoryWindow | `who: hand` | `InventoryGUI` | `obj:getInventoryWindow(who)` |
| hasInventoryWindowOpen | `obj: hand` | `boolean` | `obj:hasInventoryWindowOpen(obj)` |
| toggleInventoryWindowPermanent | `owner: hand` | `void` | `obj:toggleInventoryWindowPermanent(owner)` |
| getSelectedObject | `` | `hand` | `obj:getSelectedObject()` |
| getSelectedPlayerCharacter | `` | `hand` | `obj:getSelectedPlayerCharacter()` |
| showTradeWindow | `a: hand, b: hand, type: TradeWindowType` | `void` | `obj:showTradeWindow(a, b, type)` |
| destroy [1] | `label: ScreenLabelInterface` | `void` | `obj:destroy(label)` |
| destroy [2] | `datapanel: DatapanelGUI` | `void` | `obj:destroy(datapanel)` |
| destroy [3] | `win: GUIWindow` | `void` | `obj:destroy(win)` |
| createDatapanel [1] | `name: string, win: MyGUI::Widget, scrolls: boolean` | `DatapanelGUI` | `obj:createDatapanel(name, win, scrolls)` |
| createDatapanel [2] | `top: number, left: number, width: number, height: number, scrolls: boolean, layer: string, window: boolean` | `DatapanelGUI` | `obj:createDatapanel(top, left, width, height, scrolls, layer, window)` |
| changeMouseCursor [1] | `cursor: CursorType, player: hand, target: hand` | `void` | `obj:changeMouseCursor(cursor, player, target)` |
| changeMouseCursor [2] | `cursor: CursorType` | `void` | `obj:changeMouseCursor(cursor)` |
| createInventoryWindow [1] | `owner: hand, inventory: Inventory, layout: InventoryLayout, trader: RootObject` | `InventoryGUI` | `obj:createInventoryWindow(owner, inventory, layout, trader)` |
| createInventoryWindow [2] | `owner: hand, layout: InventoryLayout` | `InventoryGUI` | `obj:createInventoryWindow(owner, layout)` |
| toggleInventory | `owner: hand, parentInv: InventoryGUI, attached: boolean` | `InventoryGUI` | `obj:toggleInventory(owner, parentInv, attached)` |
| widgetHasMouse | `` | `boolean` | `obj:widgetHasMouse()` |
| destroyWidget | `` | `void` | `obj:destroyWidget()` |
| getDataLineColor | `actualVal: integer, normalVal: integer` | `void` | `obj:getDataLineColor(actualVal, normalVal)` |
| addScreenLabel | `label: ScreenLabelInterface` | `void` | `obj:addScreenLabel(label)` |
| keepWindownOnScreen | `` | `void` | `obj:keepWindownOnScreen()` |
| setInventoryPosition | `owner: hand, inventory: InventoryGUI` | `void` | `obj:setInventoryPosition(owner, inventory)` |
| inventoriesSelectedObjectUpdate | `obj: hand` | `void` | `obj:inventoriesSelectedObjectUpdate(obj)` |
| _showTradeWindow | `a: RootObject, b: RootObject, tradeType: TradeWindowType` | `void` | `obj:_showTradeWindow(a, b, tradeType)` |
| createFloatingLabel | `top: number, left: number, width: number, height: number, text: string, a: integer, layer: string` | `MyGUI::Widget` | `obj:createFloatingLabel(top, left, width, height, text, a, layer)` |
| createImage | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, image: string` | `MyGUI::Widget` | `obj:createImage(parent, top, left, width, height, image)` |
| createImageAbs | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, image: string` | `MyGUI::Widget` | `obj:createImageAbs(parent, top, left, width, height, image)` |
| createRotatableImageAbs | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, image: string` | `MyGUI::Widget` | `obj:createRotatableImageAbs(parent, top, left, width, height, image)` |
| createButton | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, name: string, text: string, skin: string` | `MyGUI::Widget` | `obj:createButton(parent, top, left, width, height, name, text, skin)` |
| createButtonAbs | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, name: string, text: string, skin: string` | `MyGUI::Widget` | `obj:createButtonAbs(parent, top, left, width, height, name, text, skin)` |
| createCheckbox | `parent: MyGUI::Widget, left: integer, top: integer, width: integer, height: integer, caption: string` | `MyGUI::Widget` | `obj:createCheckbox(parent, left, top, width, height, caption)` |
| createDropBox | `parent: MyGUI::Widget, name: string, top: number, left: number, width: number, height: number` | `MyGUI::Widget` | `obj:createDropBox(parent, name, top, left, width, height)` |
| createDropBoxAbs | `parent: MyGUI::Widget, name: string, top: integer, left: integer, width: integer, height: integer` | `MyGUI::Widget` | `obj:createDropBoxAbs(parent, name, top, left, width, height)` |
| createProgressBar | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, type: string` | `MyGUI::Widget` | `obj:createProgressBar(parent, top, left, width, height, type)` |
| createProgressBarAbs | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, type: string` | `MyGUI::Widget` | `obj:createProgressBarAbs(parent, top, left, width, height, type)` |
| createLabel [1] | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, text: string, skin: string` | `MyGUI::EditBox` | `obj:createLabel(parent, top, left, width, height, text, skin)` |
| createLabel [2] | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, text: string, a: MyGUI::Align` | `MyGUI::TextBox` | `obj:createLabel(parent, top, left, width, height, text, a)` |
| createLabelAbs [1] | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, labelText: string, align: MyGUI::Align` | `MyGUI::TextBox` | `obj:createLabelAbs(parent, top, left, width, height, labelText, align)` |
| createLabelAbs [2] | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, text: string, skin: string` | `MyGUI::EditBox` | `obj:createLabelAbs(parent, top, left, width, height, text, skin)` |
| createValueEdit | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, name: string` | `MyGUI::Widget` | `obj:createValueEdit(parent, top, left, width, height, name)` |
| createValueEditTransparent | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, name: string` | `MyGUI::Widget` | `obj:createValueEditTransparent(parent, top, left, width, height, name)` |
| createEditBox [1] | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, name: string, skin: string, multiLine: boolean` | `MyGUI::EditBox` | `obj:createEditBox(parent, top, left, width, height, name, skin, multiLine)` |
| createEditBox [2] | `parent: MyGUI::Widget, top: number, left: number, width: number, height: number, name: string, multiLine: boolean` | `MyGUI::EditBox` | `obj:createEditBox(parent, top, left, width, height, name, multiLine)` |
| createEditBoxAbs [1] | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, name: string, skin: string, multiLine: boolean` | `MyGUI::EditBox` | `obj:createEditBoxAbs(parent, top, left, width, height, name, skin, multiLine)` |
| createEditBoxAbs [2] | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, name: string, multiLine: boolean` | `MyGUI::EditBox` | `obj:createEditBoxAbs(parent, top, left, width, height, name, multiLine)` |
| createScrollBarAbs | `parent: MyGUI::Widget, top: integer, left: integer, width: integer, height: integer, range: integer, value: integer` | `MyGUI::Widget` | `obj:createScrollBarAbs(parent, top, left, width, height, range, value)` |
| createListbox | `parent: MyGUI::Window, top: number, left: number, width: number, height: number` | `MyGUI::Widget` | `obj:createListbox(parent, top, left, width, height)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| changeFontSize | `` | `void` | `ForgottenGUI.changeFontSize()`<br>`obj:changeFontSize()` |

## FormationMover
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.FormationMover`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | `Character` | RW | `obj.me = <value>` |
| destination | `Vector3` | RW | `obj.destination = <value>` |
| direction | `Vector3` | RW | `obj.direction = <value>` |
| movementTarget | `hand` | RW | `obj.movementTarget = <value>` |
| currentFormationID | `integer` | RW | `obj.currentFormationID = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| getSpeeds | `motion: Vector3, frameTime: number` | `number` | `obj:getSpeeds(motion, frameTime)` |
| setFormationMode | `target: hand` | `void` | `obj:setFormationMode(target)` |
| stopFormationMode | `` | `void` | `obj:stopFormationMode()` |

## FurnaceBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`
**Metatable:** `KenshiLua.FurnaceBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| active | `boolean` | RW | `obj.active = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| getInputValueTotal | `` | `number` | `obj:getInputValueTotal()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| updateInputs | `rate: number` | `void` | `obj:updateInputs(rate)` |
| updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| limitInputsOutputRate | `rate: number` | `boolean\|number` | `obj:limitInputsOutputRate(rate)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getInputValue | `item: Item` | `number` | `obj:getInputValue(item)` |
| getResourcesNeededBecauseNotFull | `` | `void` | `obj:getResourcesNeededBecauseNotFull()` |
| getResourcesNeededBecauseEmpty | `` | `void` | `obj:getResourcesNeededBecauseEmpty()` |
| canHaveSomeOfThese | `input: GameData` | `boolean` | `obj:canHaveSomeOfThese(input)` |
| incinerate | `line: DataPanelLine` | `void` | `obj:incinerate(line)` |
| operate | `stats: Character, amount: number` | `void` | `obj:operate(stats, amount)` |
| getIronAmountInItem | `data: GameData` | `number` | `obj:getIronAmountInItem(data)` |

## FurnaceInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`
**Metatable:** `KenshiLua.FurnaceInventoryLayout`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |

## GameData
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.GameData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| validity | `integer` | RW | `obj.validity = <value>` |
| sourceContainer | `GameDataContainer` | RW | `obj.sourceContainer = <value>` |
| isStandalone | `boolean` | RW | `obj.isStandalone = <value>` |
| id | `integer` | RW | `obj.id = <value>` |
| readOnly | `boolean` | RW | `obj.readOnly = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| type | `itemType` | RW | `obj.type = <value>` |
| stringID | `string` | RW | `obj.stringID = <value>` |
| isFromActiveFile | `boolean` | RW | `obj.isFromActiveFile = <value>` |
| currentID | `integer` | RW | `obj.currentID = <value>` |
| createdIndex | `integer` | RW | `obj.createdIndex = <value>` |
| activeValues | `unknown` | RW | `obj.activeValues = <value>` |
| bdata | `unknown` | RW | `obj.bdata = <value>` |
| sdata | `unknown` | RW | `obj.sdata = <value>` |
| idata | `unknown` | RW | `obj.idata = <value>` |
| fdata | `unknown` | RW | `obj.fdata = <value>` |
| filesdata | `unknown` | RW | `obj.filesdata = <value>` |
| vecdata | `unknown` | RW | `obj.vecdata = <value>` |
| quatdata | `unknown` | RW | `obj.quatdata = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isValid | `` | `boolean` | `obj:isValid()` |
| getSourceContainer | `` | `GameDataContainer` | `obj:getSourceContainer()` |
| destroy | `` | `void` | `obj:destroy()` |
| initialise | `t: itemType, isActive: boolean` | `void` | `obj:initialise(t, isActive)` |
| loadFromFile | `path: string, _type: itemType` | `boolean` | `obj:loadFromFile(path, _type)` |
| saveToFile | `path: string` | `boolean` | `obj:saveToFile(path)` |
| storeHandleList [1] | `handle: ogre_unordered_set<hand>::type, _name: string` | `void` | `obj:storeHandleList(handle, _name)` |
| storeHandleList [2] | `handle: lektor<hand>, _name: string` | `void` | `obj:storeHandleList(handle, _name)` |
| storeHandle | `h: hand, name: string, redirect: boolean` | `void` | `obj:storeHandle(h, name, redirect)` |
| getHandle | `name: string` | `hand` | `obj:getHandle(name)` |
| updateFrom | `from: GameData, mod: boolean` | `boolean` | `obj:updateFrom(from, mod)` |
| isValueActive | `v: string` | `boolean` | `obj:isValueActive(v)` |
| isRefActive | `v: string` | `boolean` | `obj:isRefActive(v)` |
| addFileName | `n: string, v: string, filestype: string, category: string, vis: boolean` | `void` | `obj:addFileName(n, v, filestype, category, vis)` |
| addString | `n: string, v: string, category: string, vis: boolean` | `void` | `obj:addString(n, v, category, vis)` |
| add [1] | `n: string, v: Vector3` | `void` | `obj:add(n, v)` |
| add [2] | `n: string, v: boolean, category: string, vis: boolean` | `void` | `obj:add(n, v, category, vis)` |
| add [3] | `n: string, v: number, category: string, vis: boolean, isSlider: boolean` | `void` | `obj:add(n, v, category, vis, isSlider)` |
| add [4] | `n: string, v: integer, category: string, vis: boolean` | `void` | `obj:add(n, v, category, vis)` |
| getGameDataReferenceObject | `list: string, id: string` | `GameDataReference` | `obj:getGameDataReferenceObject(list, id)` |
| addToList | `list: string, id: string, val: integer, val2: integer, val3: integer` | `void` | `obj:addToList(list, id, val, val2, val3)` |
| removeFromList [1] | `list: string, id: integer` | `void` | `obj:removeFromList(list, id)` |
| removeFromList [2] | `list: string, id: string` | `void` | `obj:removeFromList(list, id)` |
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
| getFromListAsData | `n: string, index: integer, dataContainer: GameDataContainer, type: itemType` | `GameData` | `obj:getFromListAsData(n, index, dataContainer, type)` |
| getValueFromList | `list: string, index: integer` | `TripleInt` | `obj:getValueFromList(list, index)` |
| deleteInstancedObject | `id: string, modIndex: integer` | `void` | `obj:deleteInstancedObject(id, modIndex)` |
| getNewID | `` | `integer` | `obj:getNewID()` |
| getColorVec | `name: string` | `Vector3` | `obj:getColorVec(name)` |
| addDeletedInstance | `instanceID: string` | `void` | `obj:addDeletedInstance(instanceID)` |

## GameData::ItemData
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`
**Parent Class:** [`GameData`](#gamedata)
**Metatable:** `KenshiLua.ItemData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| visible | `boolean` | RW | `obj.visible = <value>` |
| category | `string` | RW | `obj.category = <value>` |
| description | `string` | RW | `obj.description = <value>` |
| fileTypes | `string` | RW | `obj.fileTypes = <value>` |
| objectType | `itemType` | RW | `obj.objectType = <value>` |
| maxSize | `integer` | RW | `obj.maxSize = <value>` |
| maxValue | `integer` | RW | `obj.maxValue = <value>` |
| minValue | `integer` | RW | `obj.minValue = <value>` |
| isSlider | `boolean` | RW | `obj.isSlider = <value>` |

## GameData::ObjectInstance
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Parent Class:** [`GameData`](#gamedata)
**Metatable:** `KenshiLua.ObjectInstance`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| pos | `Vector3` | RW | `obj.pos = <value>` |
| rot | `Quaternion` | RW | `obj.rot = <value>` |
| refID | `string` | RW | `obj.refID = <value>` |
| created | `integer` | RW | `obj.created = <value>` |
| modified | `integer` | RW | `obj.modified = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: GameData::ObjectInstance` | `void` | `obj:operator_assign(other)` |

## GameDataContainer
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.GameDataContainer`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentID | `integer` | RW | `obj.currentID = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| isBaseDatafile | `boolean` | RW | `obj.isBaseDatafile = <value>` |
| readOnly | `boolean` | RW | `obj.readOnly = <value>` |
| gamedataID | `ogre_unordered_map<int, GameData*>` | RW | `obj.gamedataID = <value>` |
| gamedataSID | `boost_unordered_map<std::string, GameData*>` | RW | `obj.gamedataSID = <value>` |
| mainList | `ogre_unordered_set<GameData*>` | RW | `obj.mainList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createNewData | `type: itemType, forceID: string, name: string` | `GameData` | `obj:createNewData(type, forceID, name)` |
| getDataByName | `dataName: string, category: itemType` | `GameData` | `obj:getDataByName(dataName, category)` |
| renameData | `data: GameData, n: string` | `void` | `obj:renameData(data, n)` |
| removeData | `dat: GameData` | `void` | `obj:removeData(dat)` |
| removeDuplicatesOf | `dat: GameData` | `void` | `obj:removeDuplicatesOf(dat)` |
| removeAllDataOfType | `type: itemType` | `void` | `obj:removeAllDataOfType(type)` |
| clearInstances | `` | `void` | `obj:clearInstances()` |
| clearButDontDestroy | `` | `void` | `obj:clearButDontDestroy()` |
| clearButDontDestroyPlatoons | `` | `void` | `obj:clearButDontDestroyPlatoons()` |
| clearAndDestroy | `` | `void` | `obj:clearAndDestroy()` |
| getNewID | `` | `integer` | `obj:getNewID()` |
| destroyData | `dat: GameData` | `void` | `obj:destroyData(dat)` |
| preLoadAllReferencePtrs | `` | `void` | `obj:preLoadAllReferencePtrs()` |
| clearAllReferencePtrs | `` | `void` | `obj:clearAllReferencePtrs()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| checkForDuplicates | `dat: GameData` | `void` | `obj:checkForDuplicates(dat)` |
| addNewData | `dat: GameData, dat: string` | `void` | `obj:addNewData(dat, dat)` |
| getData [1] | `sid: string, category: integer` | `GameData` | `obj:getData(sid, category)` |
| getData [2] | `id: integer, category: integer` | `GameData` | `obj:getData(id, category)` |
| getDataOfType | `type: itemType` | `void` | `obj:getDataOfType(type)` |
| _getAllData | `` | `ogre_unordered_map<int, GameData*>::type` | `obj:_getAllData()` |
| loadGameDataReturn | `file: string, isActive: boolean, readOnly: boolean, moreData: userdata` | `boolean` | `obj:loadGameDataReturn(file, isActive, readOnly, moreData)` |
| load | `filename: string, modName: string, modIndex: integer, moreData: userdata, keepDeletedInstances: boolean` | `boolean` | `obj:load(filename, modName, modIndex, moreData, keepDeletedInstances)` |
| save | `filename: string, moreData: userdata` | `boolean` | `obj:save(filename, moreData)` |
| flushKillList | `` | `void` | `obj:flushKillList()` |
| destroyHomelessData | `` | `void` | `obj:destroyHomelessData()` |
| findAllDataThatReferencesThis | `what: GameData, ofType: itemType, listname: string` | `void` | `obj:findAllDataThatReferencesThis(what, ofType, listname)` |
| _addToKillList | `` | `void` | `obj:_addToKillList()` |

## GameDataCopyStandalone
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.GameDataCopyStandalone`

## GameDataEditorWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`
**Metatable:** `KenshiLua.GameDataEditorWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | `DatapanelGUI` | RW | `obj.win = <value>` |
| data | `GameData` | RW | `obj.data = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| initDataValues | `` | `void` | `obj:initDataValues()` |

## GameDataEditorWindow::DataItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`
**Parent Class:** [`GameDataEditorWindow`](#gamedataeditorwindow)
**Metatable:** `KenshiLua.GameDataEditorWindow_DataItem`

## GameDataGroup
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`
**Metatable:** `KenshiLua.GameDataGroup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| g1 | `GameData` | RW | `obj.g1 = <value>` |
| g2 | `GameData` | RW | `obj.g2 = <value>` |

## GameDataHeader
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.GameDataHeader`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |
| author | `string` | RW | `obj.author = <value>` |
| version | `integer` | RW | `obj.version = <value>` |
| description | `string` | RW | `obj.description = <value>` |
| dependencies | `lektor<std::string>` | RW | `obj.dependencies = <value>` |
| references | `lektor<std::string>` | RW | `obj.references = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `` | `void` | `obj:operator_assign()` |

## GameDataManager
**Header:** `extern/KenshiLib/Include/kenshi/GameDataManager.h`
**Metatable:** `KenshiLua.GameDataManager`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reloadGameData | `filename: string, isActive: boolean, _baseData: boolean` | `boolean` | `obj:reloadGameData(filename, isActive, _baseData)` |
| postProcessingTheDatas | `` | `void` | `obj:postProcessingTheDatas()` |
| getMapSector | `x: integer, y: integer` | `GameData` | `obj:getMapSector(x, y)` |
| updateDatasOfType | `fromcontainer: GameDataContainer, type: itemType, isMod: boolean` | `void` | `obj:updateDatasOfType(fromcontainer, type, isMod)` |
| updateData | `from: GameData, isMod: boolean` | `void` | `obj:updateData(from, isMod)` |
| getBuildings | `category: string` | `void` | `obj:getBuildings(category)` |

## GameDataReference
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.GameDataReference`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| values | `TripleInt` | RW | `obj.values = <value>` |
| sid | `string` | RW | `obj.sid = <value>` |
| ptr | `GameData` | RW | `obj.ptr = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: GameDataReference` | `void` | `obj:operator_assign(other)` |
| getPtr | `source: GameDataContainer` | `GameData` | `obj:getPtr(source)` |

## GameDataValuePair
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.GameDataValuePair`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `GameData` | RW | `obj.data = <value>` |
| val0 | `integer` | RW | `obj.val0 = <value>` |

## GameplayOptions
**Header:** `extern/KenshiLib/Include/kenshi/GameplayOptions.h`
**Metatable:** `KenshiLua.GameplayOptions`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| deathFrequency | `number` | RW | `obj.deathFrequency = <value>` |
| easyProspecting | `boolean` | RW | `obj.easyProspecting = <value>` |
| globalDamageMultiplier | `number` | RW | `obj.globalDamageMultiplier = <value>` |
| buildingSpeed | `number` | RW | `obj.buildingSpeed = <value>` |
| numNestsMult | `number` | RW | `obj.numNestsMult = <value>` |
| researchSpeed | `number` | RW | `obj.researchSpeed = <value>` |
| productionSpeed | `number` | RW | `obj.productionSpeed = <value>` |
| hungerTime | `number` | RW | `obj.hungerTime = <value>` |
| banditsLootPlayer | `boolean` | RW | `obj.banditsLootPlayer = <value>` |
| animalsEat | `boolean` | RW | `obj.animalsEat = <value>` |
| difficultHealing | `boolean` | RW | `obj.difficultHealing = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| getStarvationTimeInHours | `` | `number` | `obj:getStarvationTimeInHours()` |
| save | `data: GameData` | `void` | `obj:save(data)` |
| load | `data: GameData` | `void` | `obj:load(data)` |

## GameSaveState
**Header:** `extern/KenshiLib/Include/kenshi/GameSaveState.h`
**Metatable:** `KenshiLua.GameSaveState`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| baseData | `GameData` | RW | `obj.baseData = <value>` |
| dataSource | `GameDataContainer` | RW | `obj.dataSource = <value>` |
| firstTime | `boolean` | RW | `obj.firstTime = <value>` |
| instance | `GameData::ObjectInstance` | RW | `obj.instance = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| rot | `Quaternion` | RW | `obj.rot = <value>` |
| instanceID | `string` | RW | `obj.instanceID = <value>` |
| states | `StatesMapBinding::MapType` | RW | `obj.states = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| generateNewInstanceID | `` | `void` | `obj:generateNewInstanceID()` |
| generateStateID | `type: itemType` | `string` | `obj:generateStateID(type)` |
| createState | `type: itemType` | `GameData` | `obj:createState(type)` |
| hasState | `type: itemType` | `boolean` | `obj:hasState(type)` |
| getState | `type: itemType` | `GameData` | `obj:getState(type)` |
| numStates | `` | `integer` | `obj:numStates()` |
| getPos | `` | `Vector3` | `obj:getPos()` |
| getRot | `` | `Quaternion` | `obj:getRot()` |
| getTheInstancesData | `` | `GameData` | `obj:getTheInstancesData()` |
| createFromSerialisedInstanceData | `container: GameDataContainer, inst: GameData::ObjectInstance, id: string` | `void` | `obj:createFromSerialisedInstanceData(container, inst, id)` |
| addState | `state: GameData` | `void` | `obj:addState(state)` |
| getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| operator_bool | `` | `boolean` | `obj:operator_bool()` |

## GameWorld
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`
**Metatable:** `KenshiLua.GameWorld`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| tempSpawnsDisableTimer | `number` | RW | `obj.tempSpawnsDisableTimer = <value>` |
| initialized | `boolean` | RW | `obj.initialized = <value>` |
| render | `lightuserdata` | RW | `obj.render = <value>` |
| physics | `PhysicsInterface` | RW | `obj.physics = <value>` |
| gamedata | `GameDataManager` | RW | `obj.gamedata = <value>` |
| leveldata | `GameDataManager` | RW | `obj.leveldata = <value>` |
| savedata | `GameDataManager` | RW | `obj.savedata = <value>` |
| theFactory | `RootObjectFactory` | RW | `obj.theFactory = <value>` |
| factionMgr | `FactionManager` | RW | `obj.factionMgr = <value>` |
| navmesh | `NavMesh` | RW | `obj.navmesh = <value>` |
| nodeList | `lightuserdata` | RW | `obj.nodeList = <value>` |
| guiDisplayObject | `hand` | RW | `obj.guiDisplayObject = <value>` |
| messageRoller | `lightuserdata` | RW | `obj.messageRoller = <value>` |
| ogreLogger | `lightuserdata` | RW | `obj.ogreLogger = <value>` |
| steamEnabled | `boolean` | RW | `obj.steamEnabled = <value>` |
| player | `PlayerInterface` | RW | `obj.player = <value>` |
| frameSpeedMult | `number` | RW | `obj.frameSpeedMult = <value>` |
| deathParadeWasMeddledWith | `boolean` | RW | `obj.deathParadeWasMeddledWith = <value>` |
| charUpdateListMain_inUse | `boolean` | RW | `obj.charUpdateListMain_inUse = <value>` |
| _AINonRenderThread | `lightuserdata` | RW | `obj._AINonRenderThread = <value>` |
| timeStamper | `SimpleTimeStamper` | RW | `obj.timeStamper = <value>` |
| zoneMgr | `ZoneManager` | RW | `obj.zoneMgr = <value>` |
| debugFlag | `boolean` | RW | `obj.debugFlag = <value>` |
| paused | `boolean` | RW | `obj.paused = <value>` |
| gameResetting | `boolean` | RW | `obj.gameResetting = <value>` |
| audioThread | `lightuserdata` | RW | `obj.audioThread = <value>` |
| baseMods | `lektor<ModInfo>` | RW | `obj.baseMods = <value>` |
| baseModsNames | `lektor<std::string>` | RW | `obj.baseModsNames = <value>` |
| activeMods | `lektor<ModInfo*>` | RW | `obj.activeMods = <value>` |
| availableModsByName | `std::map<std::string, ModInfo>` | RW | `obj.availableModsByName = <value>` |
| availabelModsOrderedList | `lektor<ModInfo*>` | RW | `obj.availabelModsOrderedList = <value>` |
| updatePortraitsMap | `ogre_unordered_map<hand, float>` | RW | `obj.updatePortraitsMap = <value>` |
| dynamicDestroyBuildingsList | `lektor<hand>` | RW | `obj.dynamicDestroyBuildingsList = <value>` |
| destroyListTBM | `ogre_unordered_set<TownBuildingsManager*>` | RW | `obj.destroyListTBM = <value>` |
| killListPhase0 | `ogre_unordered_set<RootObject*>` | RW | `obj.killListPhase0 = <value>` |
| killListPhase1 | `ogre_unordered_map<RootObject*, float>` | RW | `obj.killListPhase1 = <value>` |
| killListPhase2 | `std::deque<RootObject*>` | RW | `obj.killListPhase2 = <value>` |
| nestBatcherKillList | `std::deque<NestBatcher*>` | RW | `obj.nestBatcherKillList = <value>` |
| mainUpdateListRemovalQueue | `lektor<Character*>` | RW | `obj.mainUpdateListRemovalQueue = <value>` |
| charactersWithLights | `ogre_unordered_set<Character*>` | RW | `obj.charactersWithLights = <value>` |
| deathParade | `ogre_unordered_map<hand, Character*>` | RW | `obj.deathParade = <value>` |
| charUpdateListMain | `ogre_unordered_set<Character*>` | RW | `obj.charUpdateListMain = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| justLoadFactionRelations | `datasrc: GameDataManager` | `void` | `obj:justLoadFactionRelations(datasrc)` |
| startUpThreads | `` | `boolean` | `obj:startUpThreads()` |
| start | `rend: userdata` | `boolean` | `obj:start(rend)` |
| destroy [1] | `e: Ogre::MovableObject` | `void` | `obj:destroy(e)` |
| destroy [2] | `e: AttachedEntity` | `void` | `obj:destroy(e)` |
| destroy [3] | `b: TownBuildingsManager` | `void` | `obj:destroy(b)` |
| destroy [4] | `n: NestBatcher` | `void` | `obj:destroy(n)` |
| destroy [5] | `obj: RootObject, justUnloaded: boolean, debugInfo: char` | `boolean` | `obj:destroy(obj, justUnloaded, debugInfo)` |
| destroy [6] | `d: GameData` | `void` | `obj:destroy(d)` |
| resetGame | `` | `void` | `obj:resetGame()` |
| _clearAndDestroyGameWorldStuff | `` | `void` | `obj:_clearAndDestroyGameWorldStuff()` |
| initialisation | `` | `boolean` | `obj:initialisation()` |
| initialisationGameData | `` | `boolean` | `obj:initialisationGameData()` |
| dailyUpdates | `` | `void` | `obj:dailyUpdates()` |
| initialiseNewGameWorld | `datasrc: GameDataManager` | `void` | `obj:initialiseNewGameWorld(datasrc)` |
| errorToLogReleaseMode | `msg: string` | `void` | `obj:errorToLogReleaseMode(msg)` |
| errorD | `msg: string` | `void` | `obj:errorD(msg)` |
| logToSave | `msg: string` | `void` | `obj:logToSave(msg)` |
| log | `line: string` | `void` | `obj:log(line)` |
| logDebug [1] | `msg: string, logname: string` | `void` | `obj:logDebug(msg, logname)` |
| logDebug [2] | `line: string` | `void` | `obj:logDebug(line)` |
| dynamicDestroyBuilding | `h: hand` | `void` | `obj:dynamicDestroyBuilding(h)` |
| getFromDeathParade | `h: hand` | `Character` | `obj:getFromDeathParade(h)` |
| addPortraitUpdate | `h: hand` | `void` | `obj:addPortraitUpdate(h)` |
| removePortaitUpdate | `h: hand` | `void` | `obj:removePortaitUpdate(h)` |
| getModsListFromConfig | `` | `lektor<ModInfo*>` | `obj:getModsListFromConfig()` |
| getAllModsList | `` | `lektor<ModInfo*>` | `obj:getAllModsList()` |
| getModLeveldataFolder | `modName: string` | `string` | `obj:getModLeveldataFolder(modName)` |
| getObjectsWithinSphere | `spherePos: Vector3, radius: number, type: itemType, maxNumber: integer, skip: RootObject` | `void` | `obj:getObjectsWithinSphere(spherePos, radius, type, maxNumber, skip)` |
| getCharactersWithinSphere | `spherePos: Vector3, farRadius: number, nearRadius: number, always: number, maxFar: integer, maxNear: integer, skip: RootObject` | `void` | `obj:getCharactersWithinSphere(spherePos, farRadius, nearRadius, always, maxFar, maxNear, skip)` |
| getObjectsWithinBox | `pos: Vector3, size: Vector3, rot: Quaternion, type: itemType, maxNumber: integer, skip: RootObject` | `void` | `obj:getObjectsWithinBox(pos, size, rot, type, maxNumber, skip)` |
| getCharacterUpdateList | `` | `ogre_unordered_set<Character*>::type` | `obj:getCharacterUpdateList()` |
| sysMessage | `m: GameWorld::SysMessage` | `void` | `obj:sysMessage(m)` |
| sysMessageUrgent | `m: GameWorld::SysMessage` | `void` | `obj:sysMessageUrgent(m)` |
| sysMessage_noDuplicates | `m: GameWorld::SysMessage` | `void` | `obj:sysMessage_noDuplicates(m)` |
| getCollisionGroupType | `type: itemType` | `integer` | `obj:getCollisionGroupType(type)` |
| getTimeFromStamp [1] | `stamp: TimeOfDay` | `TimeOfDay` | `obj:getTimeFromStamp(stamp)` |
| getTimeFromStamp [2] | `stamp: number` | `number` | `obj:getTimeFromStamp(stamp)` |
| getIsInKillList | `obj: RootObject` | `boolean` | `obj:getIsInKillList(obj)` |
| flushKillList | `` | `void` | `obj:flushKillList()` |
| allThreadQueuesAreClear | `` | `boolean` | `obj:allThreadQueuesAreClear()` |
| initBaseMods | `` | `void` | `obj:initBaseMods()` |
| initModsList | `` | `void` | `obj:initModsList()` |
| getModIndex | `modName: string` | `integer` | `obj:getModIndex(modName)` |
| buildingIntersectionTestCapsule | `pos: Vector3, radius: number, length: number, skip: RootObject` | `boolean` | `obj:buildingIntersectionTestCapsule(pos, radius, length, skip)` |
| getLightLevel | `position: Vector3, floor: integer, inside: boolean` | `number` | `obj:getLightLevel(position, floor, inside)` |
| populateMapArea_nonPermanent | `map: ZoneMap, howMany: integer, rePopulationMode: boolean` | `void` | `obj:populateMapArea_nonPermanent(map, howMany, rePopulationMode)` |
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
| addToUpdateListMain | `character: Character` | `void` | `obj:addToUpdateListMain(character)` |
| removeFromUpdateListMain | `character: Character` | `void` | `obj:removeFromUpdateListMain(character)` |
| addToDeathParade | `who: Character` | `void` | `obj:addToDeathParade(who)` |
| removeFromDeathParade | `who: Character` | `boolean` | `obj:removeFromDeathParade(who)` |
| removeFromDeathParadeByPlatoon | `p: Platoon` | `void` | `obj:removeFromDeathParadeByPlatoon(p)` |
| hideContextMenu | `` | `void` | `obj:hideContextMenu()` |
| showPlayerAMessage_withLog | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage_withLog(message, queued)` |
| showPlayerAMessage | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage(message, queued)` |
| showPlayerAMessageD | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessageD(message, queued)` |
| playNotification | `sound: string` | `void` | `obj:playNotification(sound)` |
| mainLoop_GPUSensitiveStuff | `time: number` | `void` | `obj:mainLoop_GPUSensitiveStuff(time)` |
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
| getTimeStamp_inGameHours | `` | `TimeOfDay` | `obj:getTimeStamp_inGameHours()` |
| getLengthOfHourInRealSeconds | `` | `number` | `obj:getLengthOfHourInRealSeconds()` |

## GameWorld::SysMessage
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`
**Parent Class:** [`GameWorld`](#gameworld)
**Metatable:** `KenshiLua.SysMessage`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| msg | `GameWorld::SysMessageEnum` | RW | `obj.msg = <value>` |
| target | `hand` | RW | `obj.target = <value>` |
| from | `hand` | RW | `obj.from = <value>` |
| on | `boolean` | RW | `obj.on = <value>` |
| number | `number` | RW | `obj.number = <value>` |
| data | `lightuserdata` | R | `obj.data` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `b: SysMessage` | `boolean` | `obj:operator_eq(b)` |

## GatewayBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GatewayBuilding.h`
**Metatable:** `KenshiLua.GatewayBuilding`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reAnnounceGateToPathfinder | `` | `void` | `obj:reAnnounceGateToPathfinder()` |
| postCreationPathfinderSetupStuff | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| isGate | `` | `GatewayBuilding` | `obj:isGate()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| setup | `` | `void` | `obj:setup()` |
| getGateCodeAt | `p: Vector3` | `integer` | `obj:getGateCodeAt(p)` |
| getOutsideGateCode | `` | `integer` | `obj:getOutsideGateCode()` |
| separatesAreas | `` | `boolean` | `obj:separatesAreas()` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |

## Gear
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Gear`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isUniform | `Faction` | RW | `obj.isUniform = <value>` |
| value | `integer` | RW | `obj.value = <value>` |
| crafter | `string` | RW | `obj.crafter = <value>` |
| level | `number` | RW | `obj.level = <value>` |
| level_0_100 | `integer` | RW | `obj.level_0_100 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isGear | `` | `Gear` | `obj:isGear()` |
| getLevel01 | `` | `number` | `obj:getLevel01()` |
| getLevel | `` | `integer` | `obj:getLevel()` |
| isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| _serialise | `container: GameDataContainer, type: itemType` | `GameData` | `obj:_serialise(container, type)` |
| _loadFromSerialise | `container: GameDataContainer, state: GameData` | `void` | `obj:_loadFromSerialise(container, state)` |
| isPlayerCrafted | `` | `boolean` | `obj:isPlayerCrafted()` |
| setInventoryWeAreIn | `h: hand` | `void` | `obj:setInventoryWeAreIn(h)` |

## GeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`
**Metatable:** `KenshiLua.GeneratorBuilding`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| getFuelConsumptionRate | `` | `number` | `obj:getFuelConsumptionRate()` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |
| getInputValue | `item: Item` | `number` | `obj:getInputValue(item)` |

## GenericFixedInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.GenericFixedInventoryLayout`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setSize | `slotsW: integer, slotsH: integer` | `void` | `obj:setSize(slotsW, slotsH)` |

## GenericInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`
**Metatable:** `KenshiLua.GenericInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| arrangeButton | `MyGUI::Widget` | RW | `obj.arrangeButton = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setSize | `slotsW: integer, slotsH: integer, hasArrange: boolean, hasType: boolean` | `void` | `obj:setSize(slotsW, slotsH, hasArrange, hasType)` |

## Global
**Header:** `extern/KenshiLib/Include/kenshi/Globals.h`
**Metatable:** `KenshiLua.Global`

## GlobalConstants
**Header:** `extern/KenshiLib/Include/kenshi/GlobalConstants.h`
**Metatable:** `KenshiLua.GlobalConstants`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER | `number` | RW | `obj.EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER = <value>` |
| BLEED_RATE_MULTIPLIER | `number` | RW | `obj.BLEED_RATE_MULTIPLIER = <value>` |
| INITIAL_BLEED_LOSS_MULTIPLIER | `number` | RW | `obj.INITIAL_BLEED_LOSS_MULTIPLIER = <value>` |
| BLEED_CLOT_RATE | `number` | RW | `obj.BLEED_CLOT_RATE = <value>` |
| BLUNT_DAMAGE_1 | `number` | RW | `obj.BLUNT_DAMAGE_1 = <value>` |
| BLUNT_DAMAGE_99 | `number` | RW | `obj.BLUNT_DAMAGE_99 = <value>` |
| CUT_DAMAGE_1 | `number` | RW | `obj.CUT_DAMAGE_1 = <value>` |
| CUT_DAMAGE_99 | `number` | RW | `obj.CUT_DAMAGE_99 = <value>` |
| BOW_DAMAGE_0 | `number` | RW | `obj.BOW_DAMAGE_0 = <value>` |
| BOW_DAMAGE_99 | `number` | RW | `obj.BOW_DAMAGE_99 = <value>` |
| PIERCE_MULTIPLIER | `number` | RW | `obj.PIERCE_MULTIPLIER = <value>` |
| MIN_STUMBLE_DAMAGE_MAX | `number` | RW | `obj.MIN_STUMBLE_DAMAGE_MAX = <value>` |
| DAMAGE_RESISTANCE_MIN | `number` | RW | `obj.DAMAGE_RESISTANCE_MIN = <value>` |
| DAMAGE_RESISTANCE_MAX | `number` | RW | `obj.DAMAGE_RESISTANCE_MAX = <value>` |
| STUN_RECOVERY_RATE | `number` | RW | `obj.STUN_RECOVERY_RATE = <value>` |
| BLOOD_RECOVERY_RATE | `number` | RW | `obj.BLOOD_RECOVERY_RATE = <value>` |
| ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR | `number` | RW | `obj.ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR = <value>` |
| BASE_BLOCK_CHANCE | `number` | RW | `obj.BASE_BLOCK_CHANCE = <value>` |
| BLOCK_CHANCE_REDUCTION | `number` | RW | `obj.BLOCK_CHANCE_REDUCTION = <value>` |
| BLOCK_CHANCE_INCREASE | `number` | RW | `obj.BLOCK_CHANCE_INCREASE = <value>` |
| DEGENERATION_MULT_1 | `number` | RW | `obj.DEGENERATION_MULT_1 = <value>` |
| DEGENERATION_MULT_99 | `number` | RW | `obj.DEGENERATION_MULT_99 = <value>` |
| MEDIC_SPEED_MULT | `number` | RW | `obj.MEDIC_SPEED_MULT = <value>` |
| KNOCKOUT_MULT_1 | `number` | RW | `obj.KNOCKOUT_MULT_1 = <value>` |
| KNOCKOUT_MULT_99 | `number` | RW | `obj.KNOCKOUT_MULT_99 = <value>` |
| KNOCKOUT_BASE_TIME | `number` | RW | `obj.KNOCKOUT_BASE_TIME = <value>` |
| BODYPART_DEGENERATE_RATE_MULT | `number` | RW | `obj.BODYPART_DEGENERATE_RATE_MULT = <value>` |
| BODYPART_HEAL_RATE_MULT | `number` | RW | `obj.BODYPART_HEAL_RATE_MULT = <value>` |
| BODYPART_HEAL_RATE_MULT_RESTING | `number` | RW | `obj.BODYPART_HEAL_RATE_MULT_RESTING = <value>` |
| XP_MEDIC_1 | `number` | RW | `obj.XP_MEDIC_1 = <value>` |
| XP_MEDIC_99 | `number` | RW | `obj.XP_MEDIC_99 = <value>` |
| MEDKIT_DRAIN_1 | `number` | RW | `obj.MEDKIT_DRAIN_1 = <value>` |
| MEDKIT_DRAIN_99 | `number` | RW | `obj.MEDKIT_DRAIN_99 = <value>` |
| ROBOT_WEAR_RATE | `number` | RW | `obj.ROBOT_WEAR_RATE = <value>` |
| ROBOT_FIRST_AID_SPEED | `number` | RW | `obj.ROBOT_FIRST_AID_SPEED = <value>` |
| STARVATION_TIME_HRS | `number` | RW | `obj.STARVATION_TIME_HRS = <value>` |
| FED_RECOVERY_RATE_MULT | `number` | RW | `obj.FED_RECOVERY_RATE_MULT = <value>` |
| BED_HUNGER_RATE | `number` | RW | `obj.BED_HUNGER_RATE = <value>` |
| ENCUMBRANCE_HUNGER_RATE | `number` | RW | `obj.ENCUMBRANCE_HUNGER_RATE = <value>` |
| FOOD_QUALITY_MULT | `number` | RW | `obj.FOOD_QUALITY_MULT = <value>` |
| FOOD_PRICE_MULT | `number` | RW | `obj.FOOD_PRICE_MULT = <value>` |
| SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS | `number` | RW | `obj.SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS = <value>` |
| SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY | `number` | RW | `obj.SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY = <value>` |
| XP_HIT_THEM | `number` | RW | `obj.XP_HIT_THEM = <value>` |
| XP_HIT_ME | `number` | RW | `obj.XP_HIT_ME = <value>` |
| XP_BLOCKED_THEM | `number` | RW | `obj.XP_BLOCKED_THEM = <value>` |
| XP_BLOCKED_ME | `number` | RW | `obj.XP_BLOCKED_ME = <value>` |
| XP_FIRSTAID | `number` | RW | `obj.XP_FIRSTAID = <value>` |
| XP_FITNESS | `number` | RW | `obj.XP_FITNESS = <value>` |
| XP_TOUGHNESS | `number` | RW | `obj.XP_TOUGHNESS = <value>` |
| PRICE_ROBOTICS | `number` | RW | `obj.PRICE_ROBOTICS = <value>` |
| PRICE_CROSSBOWS | `number` | RW | `obj.PRICE_CROSSBOWS = <value>` |
| PRICE_ARMOUR | `number` | RW | `obj.PRICE_ARMOUR = <value>` |
| PRICE_SWORDS | `number` | RW | `obj.PRICE_SWORDS = <value>` |
| PRICE_TRADE | `number` | RW | `obj.PRICE_TRADE = <value>` |
| PRICE_GLOBAL_MULT | `number` | RW | `obj.PRICE_GLOBAL_MULT = <value>` |
| PRICE_CLOTHING | `number` | RW | `obj.PRICE_CLOTHING = <value>` |
| TRADE_PROFIT_MARGINS | `number` | RW | `obj.TRADE_PROFIT_MARGINS = <value>` |
| PRICE_LOOT_GEAR | `number` | RW | `obj.PRICE_LOOT_GEAR = <value>` |
| PRICE_LOOT_ITEMS | `number` | RW | `obj.PRICE_LOOT_ITEMS = <value>` |
| PRICE_LOOT_PLAYER_CRAFTED_ARMOUR | `number` | RW | `obj.PRICE_LOOT_PLAYER_CRAFTED_ARMOUR = <value>` |
| PRICE_LOOT_PLAYER_CRAFTED_WEAPONS | `number` | RW | `obj.PRICE_LOOT_PLAYER_CRAFTED_WEAPONS = <value>` |
| BLUEPRINT_COST_MULT | `number` | RW | `obj.BLUEPRINT_COST_MULT = <value>` |
| UNIFORM_PRICE_MULT | `number` | RW | `obj.UNIFORM_PRICE_MULT = <value>` |
| BLUNT_PERMANENT_DAMAGE_RATIO | `number` | RW | `obj.BLUNT_PERMANENT_DAMAGE_RATIO = <value>` |
| UNARMED_DAMAGE_MULT | `number` | RW | `obj.UNARMED_DAMAGE_MULT = <value>` |
| MAX_NUM_ATTACK_SLOTS | `integer` | RW | `obj.MAX_NUM_ATTACK_SLOTS = <value>` |
| MINIMUM_STRENGTH_XP_MULT | `number` | RW | `obj.MINIMUM_STRENGTH_XP_MULT = <value>` |
| WEIGHT_STR_DIFF_1X | `number` | RW | `obj.WEIGHT_STR_DIFF_1X = <value>` |
| WEIGHT_STR_DIFF_MAX | `number` | RW | `obj.WEIGHT_STR_DIFF_MAX = <value>` |
| WEAPON_INVENTORY_WEIGHT_MULT | `number` | RW | `obj.WEAPON_INVENTORY_WEIGHT_MULT = <value>` |
| STRENGTH_XP_RATE_FROM_WALKING | `number` | RW | `obj.STRENGTH_XP_RATE_FROM_WALKING = <value>` |
| STRENGTH_XP_RATE | `number` | RW | `obj.STRENGTH_XP_RATE = <value>` |
| ATHLETICS_XP_RATE | `number` | RW | `obj.ATHLETICS_XP_RATE = <value>` |
| ENCUMBRANCE_BASE | `number` | RW | `obj.ENCUMBRANCE_BASE = <value>` |
| CARRY_WEIGHT_MULT | `number` | RW | `obj.CARRY_WEIGHT_MULT = <value>` |
| CARRY_PERSON_WEIGHT | `number` | RW | `obj.CARRY_PERSON_WEIGHT = <value>` |
| MIN_MATS_FROM_DISMANTLE_01 | `number` | RW | `obj.MIN_MATS_FROM_DISMANTLE_01 = <value>` |
| EXPERIENCE_GAIN | `number` | RW | `obj.EXPERIENCE_GAIN = <value>` |
| EXPERIENCE_GAIN_1 | `number` | RW | `obj.EXPERIENCE_GAIN_1 = <value>` |
| EXPERIENCE_GAIN_99 | `number` | RW | `obj.EXPERIENCE_GAIN_99 = <value>` |
| RESEARCH_LEVEL_INCREASE | `number` | RW | `obj.RESEARCH_LEVEL_INCREASE = <value>` |
| RESEARCH_RATE | `number` | RW | `obj.RESEARCH_RATE = <value>` |
| LOCKPICK_CHANCE_MINIMUM | `number` | RW | `obj.LOCKPICK_CHANCE_MINIMUM = <value>` |
| EXPERIENCE_CURVE | `number` | RW | `obj.EXPERIENCE_CURVE = <value>` |
| ANIMATION_BLEND_RATE | `number` | RW | `obj.ANIMATION_BLEND_RATE = <value>` |
| PRODUCTION_MULTIPLIER | `number` | RW | `obj.PRODUCTION_MULTIPLIER = <value>` |
| BUILD_SPEED_MULTIPLIER | `number` | RW | `obj.BUILD_SPEED_MULTIPLIER = <value>` |
| PRISON_TIME_MULT | `number` | RW | `obj.PRISON_TIME_MULT = <value>` |
| TOUGHNESS_KO_POINT_MIN | `number` | RW | `obj.TOUGHNESS_KO_POINT_MIN = <value>` |
| TOUGHNESS_KO_POINT_MAX | `number` | RW | `obj.TOUGHNESS_KO_POINT_MAX = <value>` |
| MAX_SQUAD_SIZE | `integer` | RW | `obj.MAX_SQUAD_SIZE = <value>` |
| MAX_SQUADS | `integer` | RW | `obj.MAX_SQUADS = <value>` |
| MAX_FACTION_SIZE | `integer` | RW | `obj.MAX_FACTION_SIZE = <value>` |
| attackDiplomats | `boolean` | RW | `obj.attackDiplomats = <value>` |
| settings | `GameData` | RW | `obj.settings = <value>` |
| APPEARANCE_RANDOM_DEVIATION | `number` | RW | `obj.APPEARANCE_RANDOM_DEVIATION = <value>` |
| fogDistMax | `number` | RW | `obj.fogDistMax = <value>` |
| fogDistMin | `number` | RW | `obj.fogDistMin = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `data: GameData` | `void` | `obj:setup(data)` |

## GUIWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GUIWindow.h`
**Metatable:** `KenshiLua.GUIWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | `MyGUI::Widget` | R | `obj.win` |
| selectedObject | `hand` | RW | `obj.selectedObject = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| show | `_a1: boolean` | `void` | `obj:show(_a1)` |
| setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| getWidth | `` | `integer` | `obj:getWidth()` |
| getHeight | `` | `integer` | `obj:getHeight()` |
| getWidthReal | `` | `number` | `obj:getWidthReal()` |
| getHeightReal | `` | `number` | `obj:getHeightReal()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| update | `` | `void` | `obj:update()` |
| autoChangeSelectedObject | `obj: hand` | `void` | `obj:autoChangeSelectedObject(obj)` |
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
| resize | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |

## Hand
**Header:** `extern/KenshiLib/Include/kenshi/util/hand.h`
**Metatable:** `KenshiLua.hand`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_bool | `` | `boolean` | `obj:operator_bool()` |
| operator_eq | `b: hand` | `boolean` | `obj:operator_eq(b)` |
| operator_ne | `b: hand` | `boolean` | `obj:operator_ne(b)` |
| operator_lt | `` | `boolean` | `obj:operator_lt()` |
| operator_assign | `otherHand: hand` | `void` | `obj:operator_assign(otherHand)` |
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
| squadMatch | `` | `boolean` | `obj:squadMatch()` |

## HavokCharacter
**Header:** `extern/KenshiLib/Include/kenshi/HavokCharacter.h`
**Metatable:** `KenshiLua.HavokCharacter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| startingFace | `integer` | RW | `obj.startingFace = <value>` |
| currentFace | `integer` | RW | `obj.currentFace = <value>` |
| nextEdge | `integer` | RW | `obj.nextEdge = <value>` |
| radius | `number` | RW | `obj.radius = <value>` |
| waterModifier | `number` | RW | `obj.waterModifier = <value>` |
| acceleration | `number` | RW | `obj.acceleration = <value>` |
| desiredSpeed | `number` | RW | `obj.desiredSpeed = <value>` |
| positionChanged | `boolean` | RW | `obj.positionChanged = <value>` |
| timeOffPath | `number` | RW | `obj.timeOffPath = <value>` |
| characterState | `HavokCharacter::CharacterState` | RW | `obj.characterState = <value>` |
| lastState | `HavokCharacter::CharacterState` | RW | `obj.lastState = <value>` |
| pathState | `HavokCharacter::PathState` | RW | `obj.pathState = <value>` |
| handle | `hand` | RW | `obj.handle = <value>` |
| collided | `hand` | RW | `obj.collided = <value>` |
| sensoryData | `SensoryData` | RW | `obj.sensoryData = <value>` |
| resolveFlag | `integer` | RW | `obj.resolveFlag = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setPosition | `p: Vector3, key: integer` | `void` | `obj:setPosition(p, key)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| setVelocity | `v: Vector3` | `void` | `obj:setVelocity(v)` |
| getVelocity | `` | `Vector3` | `obj:getVelocity()` |
| getWaypointDirection | `` | `Vector3` | `obj:getWaypointDirection()` |
| getDirectionMoved | `` | `Vector3` | `obj:getDirectionMoved()` |
| setWaterModifier | `m: number` | `void` | `obj:setWaterModifier(m)` |
| setManualMode | `on: boolean` | `void` | `obj:setManualMode(on)` |
| setDesiredSpeed | `speed: number` | `void` | `obj:setDesiredSpeed(speed)` |
| getState | `` | `HavokCharacter::CharacterState` | `obj:getState()` |
| getPathState | `` | `HavokCharacter::PathState` | `obj:getPathState()` |
| isOnNavmesh | `` | `boolean` | `obj:isOnNavmesh()` |
| getClosestPoint | `target: Vector3, max: number, building: Building` | `Vector3` | `obj:getClosestPoint(target, max, building)` |
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
| getCollidedCharacter | `` | `hand` | `obj:getCollidedCharacter()` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| calculateFuturePosition [1] | `d: number, out: hkVector4f, dir: hkVector4f, stopAtScreenEdge: boolean` | `integer` | `obj:calculateFuturePosition(d, out, dir, stopAtScreenEdge)` |
| calculateFuturePosition [2] | `distance: number` | `Vector3` | `obj:calculateFuturePosition(distance)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_new | `` | `void*` | `HavokCharacter.operator_new()`<br>`obj:operator_new()` |
| operator_delete | `arg1: HavokCharacter` | `void` | `HavokCharacter.operator_delete(arg1)`<br>`obj:operator_delete(arg1)` |

## hkArray
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkArray`

## hkArrayBase
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkArrayBase`

## hkBool
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkBool`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| m_bool | `integer` | RW | `obj.m_bool = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_bool | `` | `boolean` | `obj:operator_bool()` |
| operator_eq | `other: hkBool` | `boolean` | `obj:operator_eq(other)` |
| operator_ne | `other: hkBool` | `boolean` | `obj:operator_ne(other)` |

## hkContainerHeapAllocator
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkContainerHeapAllocator`

## hkContainerHeapAllocator::Allocator
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Parent Class:** [`hkContainerHeapAllocator`](#hkcontainerheapallocator)
**Metatable:** `KenshiLua.hkContainerHeapAllocator_Allocator`

## hkMemoryAllocator
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkMemoryAllocator`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| blockAlloc | `_a1: integer` | `void` | `obj:blockAlloc(_a1)` |
| resetPeakMemoryStatistics | `` | `void` | `obj:resetPeakMemoryStatistics()` |
| getExtendedInterface | `` | `lightuserdata` | `obj:getExtendedInterface()` |

## hkMemoryAllocator::ExtendedInterface
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Parent Class:** [`hkMemoryAllocator`](#hkmemoryallocator)
**Metatable:** `KenshiLua.hkMemoryAllocator_ExtendedInterface`

## hkMemoryAllocator::MemoryStatistics
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Parent Class:** [`hkMemoryAllocator`](#hkmemoryallocator)
**Metatable:** `KenshiLua.hkMemoryAllocator_MemoryStatistics`

## hkResult
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkResult`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| m_enum | `integer` | RW | `obj.m_enum = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `b: hkResult` | `boolean` | `obj:operator_eq(b)` |
| operator_ne | `b: hkResult` | `boolean` | `obj:operator_ne(b)` |

## hkTrait::TraitBool
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.TraitBool`

## hkVector4f
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkVector4f`

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
| set [1] | `a: number, b: number, c: number, d: number` | `void` | `obj:set(a, b, c, d)` |
| set [2] | `a: hkSimdFloat32, b: hkSimdFloat32, c: hkSimdFloat32, d: hkSimdFloat32` | `void` | `obj:set(a, b, c, d)` |
| setAll [1] | `a: number` | `void` | `obj:setAll(a)` |
| setAll [2] | `a: hkSimdFloat32` | `void` | `obj:setAll(a)` |
| add | `a: hkVector4f` | `void` | `obj:add(a)` |
| sub | `a: hkVector4f` | `void` | `obj:sub(a)` |
| mul [1] | `s: hkSimdFloat32` | `void` | `obj:mul(s)` |
| mul [2] | `a: hkVector4f` | `void` | `obj:mul(a)` |
| div | `a: hkVector4f` | `void` | `obj:div(a)` |
| setAdd [1] | `v0: hkVector4f, v1: hkSimdFloat32` | `void` | `obj:setAdd(v0, v1)` |
| setAdd [2] | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setAdd(v0, v1)` |
| setSub [1] | `v0: hkVector4f, v1: hkSimdFloat32` | `void` | `obj:setSub(v0, v1)` |
| setSub [2] | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setSub(v0, v1)` |
| setMul [1] | `r: hkSimdFloat32, v1: hkVector4f` | `void` | `obj:setMul(r, v1)` |
| setMul [2] | `v1: hkVector4f, r: hkSimdFloat32` | `void` | `obj:setMul(v1, r)` |
| setMul [3] | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setMul(v0, v1)` |
| setDiv | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setDiv(v0, v1)` |
| addMul [1] | `r: hkSimdFloat32, v1: hkVector4f` | `void` | `obj:addMul(r, v1)` |
| addMul [2] | `v1: hkVector4f, r: hkSimdFloat32` | `void` | `obj:addMul(v1, r)` |
| addMul [3] | `x: hkVector4f, y: hkVector4f` | `void` | `obj:addMul(x, y)` |
| setAddMul [1] | `a: hkVector4f, b: hkVector4f, r: hkSimdFloat32` | `void` | `obj:setAddMul(a, b, r)` |
| setAddMul [2] | `a: hkVector4f, x: hkVector4f, y: hkVector4f` | `void` | `obj:setAddMul(a, x, y)` |
| subMul [1] | `r: hkSimdFloat32, a: hkVector4f` | `void` | `obj:subMul(r, a)` |
| subMul [2] | `v1: hkVector4f, r: hkSimdFloat32` | `void` | `obj:subMul(v1, r)` |
| subMul [3] | `x: hkVector4f, y: hkVector4f` | `void` | `obj:subMul(x, y)` |
| setSubMul [1] | `a: hkVector4f, b: hkVector4f, r: hkSimdFloat32` | `void` | `obj:setSubMul(a, b, r)` |
| setSubMul [2] | `a: hkVector4f, x: hkVector4f, y: hkVector4f` | `void` | `obj:setSubMul(a, x, y)` |
| setCross | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setCross(v0, v1)` |
| setXYZ_W [1] | `xyz: hkVector4f, w: hkSimdFloat32` | `void` | `obj:setXYZ_W(xyz, w)` |
| setXYZ_W [2] | `xyz: hkVector4f, w: hkVector4f` | `void` | `obj:setXYZ_W(xyz, w)` |
| setW [1] | `w: hkSimdFloat32` | `void` | `obj:setW(w)` |
| setW [2] | `w: hkVector4f` | `void` | `obj:setW(w)` |
| setXYZ [1] | `v: number` | `void` | `obj:setXYZ(v)` |
| setXYZ [2] | `xyz: hkVector4f` | `void` | `obj:setXYZ(xyz)` |
| setXYZ_0 | `xyz: hkVector4f` | `void` | `obj:setXYZ_0(xyz)` |
| equals3 | `epsilon: number` | `boolean` | `obj:equals3(epsilon)` |
| setAbs | `` | `void` | `obj:setAbs()` |
| setMin | `` | `void` | `obj:setMin()` |
| setMax | `` | `void` | `obj:setMax()` |
| setClamped | `` | `void` | `obj:setClamped()` |
| setClampedZeroOne | `` | `void` | `obj:setClampedZeroOne()` |
| setReciprocal | `` | `void` | `obj:setReciprocal()` |
| setSqrt | `` | `void` | `obj:setSqrt()` |
| setSqrtInverse | `` | `void` | `obj:setSqrtInverse()` |
| setSelect | `comp: hkVector4fComparison` | `void` | `obj:setSelect(comp)` |
| zeroIfFalse | `comp: hkVector4fComparison` | `void` | `obj:zeroIfFalse(comp)` |
| zeroIfTrue | `comp: hkVector4fComparison` | `void` | `obj:zeroIfTrue(comp)` |
| less | `` | `hkVector4fComparison` | `obj:less()` |
| lessEqual | `` | `hkVector4fComparison` | `obj:lessEqual()` |
| greater | `` | `hkVector4fComparison` | `obj:greater()` |
| greaterEqual | `` | `hkVector4fComparison` | `obj:greaterEqual()` |
| equal | `` | `hkVector4fComparison` | `obj:equal()` |
| notEqual | `` | `hkVector4fComparison` | `obj:notEqual()` |
| lessZero | `` | `hkVector4fComparison` | `obj:lessZero()` |
| lessEqualZero | `` | `hkVector4fComparison` | `obj:lessEqualZero()` |
| greaterZero | `` | `hkVector4fComparison` | `obj:greaterZero()` |
| greaterEqualZero | `` | `hkVector4fComparison` | `obj:greaterEqualZero()` |
| equalZero | `` | `hkVector4fComparison` | `obj:equalZero()` |
| notEqualZero | `` | `hkVector4fComparison` | `obj:notEqualZero()` |
| isOk3 | `` | `boolean` | `obj:isOk3()` |
| isOk4 | `` | `boolean` | `obj:isOk4()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |
| operator_call [1] | `val: number` | `void` | `obj:operator_call(val)` |
| operator_call [2] | `idx: integer, val: number` | `number` | `obj:operator_call(idx, val)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getZero | `` | `void` | `hkVector4f.getZero()`<br>`obj:getZero()` |
| operator_new | `` | `void*` | `hkVector4f.operator_new()`<br>`obj:operator_new()` |
| operator_delete | `arg1: hkVector4f` | `void` | `hkVector4f.operator_delete(arg1)`<br>`obj:operator_delete(arg1)` |

### Constructors
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hkVector4f | `[x: number, y: number, z: number, w: number]` | `hkVector4f` | `local v = hkVector4f(1, 2, 3, 4)` |

## hkVector4fComparison
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkVector4fComparison`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getIndexOfLastComponentSet | `` | `integer` | `obj:getIndexOfLastComponentSet()` |
| getIndexOfFirstComponentSet | `` | `integer` | `obj:getIndexOfFirstComponentSet()` |
| allAreSet | `` | `integer` | `obj:allAreSet()` |
| anyIsSet [1] | `` | `integer` | `obj:anyIsSet()` |
| anyIsSet [2] | `m: Mask` | `integer` | `obj:anyIsSet(m)` |
| getMask [1] | `m: Mask` | `Mask` | `obj:getMask(m)` |
| getMask [2] | `` | `Mask` | `obj:getMask()` |
| set | `m: integer` | `void` | `obj:set(m)` |
| setAnd | `` | `void` | `obj:setAnd()` |
| setAndNot | `` | `void` | `obj:setAndNot()` |
| setXor | `` | `void` | `obj:setXor()` |
| setOr | `` | `void` | `obj:setOr()` |
| setNot | `` | `void` | `obj:setNot()` |
| setSelect | `` | `void` | `obj:setSelect()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getMaskForComponent | `` | `integer` | `hkVector4fComparison.getMaskForComponent()`<br>`obj:getMaskForComponent()` |

### Constructors
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hkVector4fComparison | `[mask: integer]` | `hkVector4fComparison` | `local comp = hkVector4fComparison()` |

## ImportGameMenu
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`
**Metatable:** `KenshiLua.ImportGameMenu`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| newGameOptions | `NewGameOptionsWindow` | RW | `obj.newGameOptions = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| select | `index: integer` | `void` | `obj:select(index)` |
| importPress | `sender: MyGUI::Widget` | `void` | `obj:importPress(sender)` |
| toggleAdvancedOptions | `sender: MyGUI::Widget` | `void` | `obj:toggleAdvancedOptions(sender)` |

## InputHandler
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`
**Metatable:** `KenshiLua.InputHandler`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| keyboard | `lightuserdata` | RW | `obj.keyboard = <value>` |
| controlEnabled | `boolean` | RW | `obj.controlEnabled = <value>` |
| gameMode | `InputHandler::GameMode` | RW | `obj.gameMode = <value>` |
| ctrl | `boolean` | RW | `obj.ctrl = <value>` |
| shift | `boolean` | RW | `obj.shift = <value>` |
| alt | `boolean` | RW | `obj.alt = <value>` |
| up | `boolean` | RW | `obj.up = <value>` |
| down | `boolean` | RW | `obj.down = <value>` |
| left | `boolean` | RW | `obj.left = <value>` |
| right | `boolean` | RW | `obj.right = <value>` |
| space | `boolean` | RW | `obj.space = <value>` |
| pgup | `boolean` | RW | `obj.pgup = <value>` |
| pgdn | `boolean` | RW | `obj.pgdn = <value>` |
| comma | `boolean` | RW | `obj.comma = <value>` |
| period | `boolean` | RW | `obj.period = <value>` |
| f1 | `boolean` | RW | `obj.f1 = <value>` |
| f2 | `boolean` | RW | `obj.f2 = <value>` |
| escape | `boolean` | RW | `obj.escape = <value>` |
| del | `boolean` | RW | `obj.del = <value>` |
| escape_msg | `boolean` | RW | `obj.escape_msg = <value>` |
| zoomin | `boolean` | RW | `obj.zoomin = <value>` |
| zoomout | `boolean` | RW | `obj.zoomout = <value>` |
| buildTiltInc | `boolean` | RW | `obj.buildTiltInc = <value>` |
| buildTiltDec | `boolean` | RW | `obj.buildTiltDec = <value>` |
| rotate | `boolean` | RW | `obj.rotate = <value>` |
| rotRight | `boolean` | RW | `obj.rotRight = <value>` |
| rotLeft | `boolean` | RW | `obj.rotLeft = <value>` |
| tiltDown | `boolean` | RW | `obj.tiltDown = <value>` |
| tiltUp | `boolean` | RW | `obj.tiltUp = <value>` |
| highlight | `boolean` | RW | `obj.highlight = <value>` |
| mLeft | `boolean` | RW | `obj.mLeft = <value>` |
| mRight | `boolean` | RW | `obj.mRight = <value>` |
| lastMLeft | `boolean` | RW | `obj.lastMLeft = <value>` |
| lastMRight | `boolean` | RW | `obj.lastMRight = <value>` |
| mLDown | `boolean` | RW | `obj.mLDown = <value>` |
| mRDown | `boolean` | RW | `obj.mRDown = <value>` |
| mLUp | `boolean` | RW | `obj.mLUp = <value>` |
| mRUp | `boolean` | RW | `obj.mRUp = <value>` |
| swapMouseButtons | `boolean` | RW | `obj.swapMouseButtons = <value>` |
| mPos | `Vector2` | RW | `obj.mPos = <value>` |
| mPosAbs | `Vector2` | RW | `obj.mPosAbs = <value>` |
| mSpeed | `Vector3` | RW | `obj.mSpeed = <value>` |
| mWheel | `integer` | RW | `obj.mWheel = <value>` |
| commands | `lightuserdata` | R | `obj.commands` |
| map | `lightuserdata` | R | `obj.map` |
| editMap | `lightuserdata` | R | `obj.editMap` |
| events | `lightuserdata` | R | `obj.events` |
| keyNameMap | `integer` | R | `obj.keyNameMap` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getKeyUTF8 | `key: integer` | `string` | `obj:getKeyUTF8(key)` |
| parseKey | `s: string` | `integer` | `obj:parseKey(s)` |
| getCommand | `s: string` | `lightuserdata` | `obj:getCommand(s)` |
| keyDownEvent | `key: integer` | `void` | `obj:keyDownEvent(key)` |
| keyUpEvent | `key: integer` | `void` | `obj:keyUpEvent(key)` |
| clearMessages | `` | `void` | `obj:clearMessages()` |
| initialise | `` | `void` | `obj:initialise()` |
| bind | `name: string, key: integer` | `void` | `obj:bind(name, key)` |
| unbindAll | `` | `void` | `obj:unbindAll()` |
| isKeyState | `command: string` | `boolean` | `obj:isKeyState(command)` |
| getMode | `command: string` | `integer` | `obj:getMode(command)` |
| sendEvent | `name: string` | `void` | `obj:sendEvent(name)` |
| loadConfig | `` | `void` | `obj:loadConfig()` |
| saveConfig | `` | `void` | `obj:saveConfig()` |
| keyString | `key: integer, translated: boolean` | `string` | `obj:keyString(key, translated)` |
| addCommand [1] | `name: string, value: integer, key: integer, alt: integer, masks: Masks, mode: GameMode` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| addCommand [2] | `name: string, value: boolean, key: integer, alt: integer, masks: Masks, mode: GameMode` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| unbind [1] | `code: integer, mode: GameMode` | `void` | `obj:unbind(code, mode)` |
| unbind [2] | `cmd: string` | `void` | `obj:unbind(cmd)` |
| isBound [1] | `command: string` | `boolean` | `obj:isBound(command)` |
| isBound [2] | `key: integer` | `boolean` | `obj:isBound(key)` |
| getBoundKeys | `command: string` | `integer` | `obj:getBoundKeys(command)` |
| getBoundCommand | `key: integer, mode: InputHandler::GameMode` | `string` | `obj:getBoundCommand(key, mode)` |

## InputHandler::Command
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`
**Parent Class:** [`InputHandler`](#inputhandler)
**Metatable:** `KenshiLua.InputHandler_Command`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## InstanceID
**Header:** `extern/KenshiLib/Include/kenshi/InstanceID.h`
**Metatable:** `KenshiLua.InstanceID`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| uid | `string` | RW | `obj.uid = <value>` |
| baseIndex | `integer` | RW | `obj.baseIndex = <value>` |
| modIndex | `integer` | RW | `obj.modIndex = <value>` |
| modified | `boolean` | RW | `obj.modified = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq [1] | `s: string` | `boolean` | `obj:operator_eq(s)` |
| operator_eq [2] | `other: InstanceID` | `boolean` | `obj:operator_eq(other)` |
| operator_assign | `other: InstanceID` | `void` | `obj:operator_assign(other)` |
| assign | `id: string` | `void` | `obj:assign(id)` |
| clear | `` | `void` | `obj:clear()` |
| needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| notifyChange | `` | `void` | `obj:notifyChange()` |
| hasChanges | `` | `boolean` | `obj:hasChanges()` |
| notifySaved | `mod: string` | `void` | `obj:notifySaved(mod)` |
| empty | `` | `boolean` | `obj:empty()` |
| getBaseIndex | `` | `integer` | `obj:getBaseIndex()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getModIndex [1] | `` | `integer` | `InstanceID.getModIndex()`<br>`obj:getModIndex()` |
| getModIndex [2] | `s: string` | `integer` | `InstanceID.getModIndex(s)`<br>`obj:getModIndex(s)` |

## InteriorModeButtonWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/InteriorModeButtonWindow.h`
**Metatable:** `KenshiLua.InteriorModeButtonWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| exteriorsInvisible | `boolean` | RW | `obj.exteriorsInvisible = <value>` |
| interiorMode | `boolean` | RW | `obj.interiorMode = <value>` |
| dataEditWindow | `GameDataEditorWindow` | RW | `obj.dataEditWindow = <value>` |
| currentBuilding | `hand` | RW | `obj.currentBuilding = <value>` |
| currentInterior | `string` | RW | `obj.currentInterior = <value>` |
| currentExterior | `string` | RW | `obj.currentExterior = <value>` |
| interiorModeButton | `MyGUI::Widget` | RW | `obj.interiorModeButton = <value>` |
| win | `MyGUI::Widget` | RW | `obj.win = <value>` |
| centerButton | `MyGUI::Widget` | RW | `obj.centerButton = <value>` |
| exteriorButton | `MyGUI::Widget` | RW | `obj.exteriorButton = <value>` |
| titleLabel | `MyGUI::Widget` | RW | `obj.titleLabel = <value>` |
| saveBut | `MyGUI::Widget` | RW | `obj.saveBut = <value>` |
| deleteBut | `MyGUI::Widget` | RW | `obj.deleteBut = <value>` |
| listbox | `MyGUI::Widget` | RW | `obj.listbox = <value>` |
| namebox | `MyGUI::Widget` | RW | `obj.namebox = <value>` |
| saveBut2 | `MyGUI::Widget` | RW | `obj.saveBut2 = <value>` |
| deleteBut2 | `MyGUI::Widget` | RW | `obj.deleteBut2 = <value>` |
| listbox2 | `MyGUI::Widget` | RW | `obj.listbox2 = <value>` |
| namebox2 | `MyGUI::Widget` | RW | `obj.namebox2 = <value>` |
| updateNodesMessages | `unknown` | RW | `obj.updateNodesMessages = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| toggleInteriorMode | `` | `void` | `obj:toggleInteriorMode()` |
| setVisible | `v: boolean` | `void` | `obj:setVisible(v)` |
| wantExteriorsInvisible | `` | `boolean` | `obj:wantExteriorsInvisible()` |
| setSelectedBuilding | `b: Building` | `void` | `obj:setSelectedBuilding(b)` |
| getSelectedBuilding | `` | `Building` | `obj:getSelectedBuilding()` |
| updateUsageNodes | `` | `boolean` | `obj:updateUsageNodes()` |
| refresh | `` | `void` | `obj:refresh()` |
| activateInteriorMode | `on: boolean` | `void` | `obj:activateInteriorMode(on)` |
| confirmDeleteInteriorLayout | `c: integer` | `void` | `obj:confirmDeleteInteriorLayout(c)` |
| confirmDeleteExteriorLayout | `c: integer` | `void` | `obj:confirmDeleteExteriorLayout(c)` |
| setInteriorLayout | `name: string` | `void` | `obj:setInteriorLayout(name)` |
| setExteriorLayout | `name: string` | `void` | `obj:setExteriorLayout(name)` |
| recheckOutsideFurniture | `building: Building` | `void` | `obj:recheckOutsideFurniture(building)` |
| interiorModePressed | `sender: MyGUI::Widget` | `void` | `obj:interiorModePressed(sender)` |
| interiorModeButtonUpdate | `sender: MyGUI::Widget, a2: integer, a3: integer, a4: integer` | `void` | `obj:interiorModeButtonUpdate(sender, a2, a3, a4)` |
| interiorModeButtonUpdate2 | `sender: MyGUI::Widget, sender2: MyGUI::Widget` | `void` | `obj:interiorModeButtonUpdate2(sender, sender2)` |
| deleteButtonPressed | `sender: MyGUI::Widget` | `void` | `obj:deleteButtonPressed(sender)` |
| deleteButtonPressed2 | `sender: MyGUI::Widget` | `void` | `obj:deleteButtonPressed2(sender)` |
| closeWindow | `sender: MyGUI::Window, name: string` | `void` | `obj:closeWindow(sender, name)` |
| toggleVisButtonPressed | `sender: MyGUI::Widget` | `void` | `obj:toggleVisButtonPressed(sender)` |
| notifyEditTextChange | `sender: MyGUI::EditBox` | `void` | `obj:notifyEditTextChange(sender)` |
| centerButtonPressed | `sender: MyGUI::Widget` | `void` | `obj:centerButtonPressed(sender)` |
| saveButtonPressed | `sender: MyGUI::Widget` | `void` | `obj:saveButtonPressed(sender)` |
| clearNodes | `sender: MyGUI::Widget` | `void` | `obj:clearNodes(sender)` |
| clearAll | `sender: MyGUI::Widget` | `void` | `obj:clearAll(sender)` |
| listItemSelected | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:listItemSelected(sender, index)` |
| saveButtonPressed2 | `sender: MyGUI::Widget` | `void` | `obj:saveButtonPressed2(sender)` |
| listItemSelected2 | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:listItemSelected2(sender, index)` |
| notifyEditTextChange2 | `sender: MyGUI::EditBox` | `void` | `obj:notifyEditTextChange2(sender)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| wasTheInteriorLoadedFromASave | `` | `boolean` | `InteriorModeButtonWindow.wasTheInteriorLoadedFromASave()`<br>`obj:wasTheInteriorLoadedFromASave()` |

## Inventory
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`
**Metatable:** `KenshiLua.Inventory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| hasRoomCache | `Inventory::HasRoomCache` | RW | `obj.hasRoomCache = <value>` |
| callbackObject | `RootObject` | RW | `obj.callbackObject = <value>` |
| owner | `RootObject` | RW | `obj.owner = <value>` |
| totalWeight | `number` | RW | `obj.totalWeight = <value>` |
| _allItems | `lektor<Item*>` | RW | `obj._allItems = <value>` |
| sections | `unknown` | RW | `obj.sections = <value>` |
| sectionsInSearchOrder | `lektor<InventorySection*>` | RW | `obj.sectionsInSearchOrder = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clearAll | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAll(destroy, skipUnique)` |
| serialise | `container: GameDataContainer, refList: GameData` | `GameData` | `obj:serialise(container, refList)` |
| notifyModified | `` | `void` | `obj:notifyModified()` |
| initialiseNewSection | `name: string, w: integer, h: integer, limitSlot: AttachSlot, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| resizeSection | `sect: InventorySection, w: integer, h: integer, clearContent: boolean` | `void` | `obj:resizeSection(sect, w, h, clearContent)` |
| removeAllSections | `` | `void` | `obj:removeAllSections()` |
| getSection | `name: string` | `InventorySection` | `obj:getSection(name)` |
| getSectionOfType | `type: AttachSlot` | `InventorySection` | `obj:getSectionOfType(type)` |
| getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| addItem | `item: Item, quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:addItem(item, quantity, dropOnFail, destroyOnFail)` |
| tryAddItem | `item: Item, quantity: integer` | `boolean` | `obj:tryAddItem(item, quantity)` |
| hasRoomForItem | `item: GameData` | `boolean` | `obj:hasRoomForItem(item)` |
| removeItemDontDestroy_returnsItem | `it: Item, howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:removeItemDontDestroy_returnsItem(it, howmany, returnCopyIfSomeLeft)` |
| removeItemAutoDestroy | `it: Item, howmany: integer` | `boolean` | `obj:removeItemAutoDestroy(it, howmany)` |
| dropItem | `it: Item` | `void` | `obj:dropItem(it)` |
| transferMouseItem | `item: Item` | `boolean` | `obj:transferMouseItem(item)` |
| countItems | `item: GameData` | `integer` | `obj:countItems(item)` |
| getItem | `item: GameData` | `Item` | `obj:getItem(item)` |
| hasItemType | `item: itemType, skipEquipped: boolean` | `boolean` | `obj:hasItemType(item, skipEquipped)` |
| hasStolenItems | `` | `boolean` | `obj:hasStolenItems()` |
| getSecondaryWeapon | `` | `Weapon` | `obj:getSecondaryWeapon()` |
| getPrimaryWeapon | `` | `Weapon` | `obj:getPrimaryWeapon()` |
| takeOneItemOnly | `item: GameData` | `Item` | `obj:takeOneItemOnly(item)` |
| deathCheck | `item: Item` | `boolean` | `obj:deathCheck(item)` |
| hasItemFunction | `type: ItemFunction` | `boolean` | `obj:hasItemFunction(type)` |
| getBestItemWithFunction | `type: ItemFunction` | `Item` | `obj:getBestItemWithFunction(type)` |
| getBestFoodItem | `race: Character` | `Item` | `obj:getBestFoodItem(race)` |
| getNumFoodItems | `race: Character` | `integer` | `obj:getNumFoodItems(race)` |
| _getBestFoodItem | `type: ItemFunction, race: Character` | `Item` | `obj:_getBestFoodItem(type, race)` |
| _getNumFoodItems | `type: ItemFunction, race: Character` | `integer` | `obj:_getNumFoodItems(type, race)` |
| hasWeaponEquipped | `` | `boolean` | `obj:hasWeaponEquipped()` |
| equipItem | `item: Item` | `boolean` | `obj:equipItem(item)` |
| isAContainer | `` | `boolean` | `obj:isAContainer()` |
| getOwner | `` | `RootObject` | `obj:getOwner()` |
| isEmpty | `` | `boolean` | `obj:isEmpty()` |
| recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| getTotalWeight | `` | `number` | `obj:getTotalWeight()` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| takeMoney | `val: integer` | `void` | `obj:takeMoney(val)` |
| buyItem | `itemToBuy: Item, sendingTo: RootObject` | `Item` | `obj:buyItem(itemToBuy, sendingTo)` |
| getInventoryGUI | `` | `InventoryGUI` | `obj:getInventoryGUI()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| _sectionAddItemCallback | `item: Item` | `void` | `obj:_sectionAddItemCallback(item)` |
| _sectionUpdateItemCallback | `_a1: Item, _a2: integer` | `void` | `obj:_sectionUpdateItemCallback(_a1, _a2)` |
| _sectionRemoveItemCallback | `item: Item` | `void` | `obj:_sectionRemoveItemCallback(item)` |
| refreshGui | `` | `void` | `obj:refreshGui()` |
| autoArrange | `` | `void` | `obj:autoArrange()` |
| getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| _addToList | `item: Item` | `void` | `obj:_addToList(item)` |
| _removeFromList | `item: Item, checkEverything: boolean` | `void` | `obj:_removeFromList(item, checkEverything)` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| loadFrom [1] | `container: GameDataContainer, inventoryState: GameData` | `void` | `obj:loadFrom(container, inventoryState)` |
| loadFrom [2] | `state: GameSaveState` | `void` | `obj:loadFrom(state)` |
| fillFromVendorList [1] | `vendorData: GameData, f: Faction` | `void` | `obj:fillFromVendorList(vendorData, f)` |
| fillFromVendorList [2] | `vendorlistList: lektor<GameData*>, f: Faction` | `void` | `obj:fillFromVendorList(vendorlistList, f)` |
| getAllSectionsOfType | `type: AttachSlot` | `void` | `obj:getAllSectionsOfType(type)` |
| getAllSections | `` | `lektor<InventorySection*>` | `obj:getAllSections()` |
| getExcessLoot | `me: hand, justAsking: boolean` | `boolean` | `obj:getExcessLoot(me, justAsking)` |
| getResourceItems | `buildingMatsToo: boolean` | `void` | `obj:getResourceItems(buildingMatsToo)` |
| getNumItems [1] | `itemType: GameData` | `integer` | `obj:getNumItems(itemType)` |
| getNumItems [2] | `` | `integer` | `obj:getNumItems()` |
| hasItem [1] | `item: GameData, quantity: integer` | `boolean` | `obj:hasItem(item, quantity)` |
| hasItem [2] | `item: Item` | `boolean` | `obj:hasItem(item)` |
| getAllStolenItems | `includeUnknown: boolean` | `void` | `obj:getAllStolenItems(includeUnknown)` |
| getAllItemsOfType | `ty: itemType, skipEquipped: boolean` | `void` | `obj:getAllItemsOfType(ty, skipEquipped)` |
| getEquippedWeapons | `` | `void` | `obj:getEquippedWeapons()` |
| getEquippedArmour | `` | `void` | `obj:getEquippedArmour()` |
| takeItem_EntireStack [1] | `what: Item` | `boolean` | `obj:takeItem_EntireStack(what)` |
| takeItem_EntireStack [2] | `item: GameData` | `Item` | `obj:takeItem_EntireStack(item)` |
| getAllItemsWithFunction | `type: ItemFunction` | `void` | `obj:getAllItemsWithFunction(type)` |
| getBestItemWithLowestCharges [1] | `what: GameData` | `Item` | `obj:getBestItemWithLowestCharges(what)` |
| getBestItemWithLowestCharges [2] | `type: ItemFunction` | `Item` | `obj:getBestItemWithLowestCharges(type)` |
| getAllItems | `` | `lektor<Item*>` | `obj:getAllItems()` |

## Inventory::HasRoomCache
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`
**Parent Class:** [`Inventory`](#inventory)
**Metatable:** `KenshiLua.Inventory_HasRoomCache`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| modified | `` | `void` | `obj:modified()` |
| knowsAbout | `item: GameData` | `boolean` | `obj:knowsAbout(item)` |
| hasRoomFor | `item: GameData` | `boolean` | `obj:hasRoomFor(item)` |
| remember | `d: GameData, state: boolean` | `void` | `obj:remember(d, state)` |

## InventoryGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.InventoryGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| layoutMgr | `InventoryLayout` | RW | `obj.layoutMgr = <value>` |
| ownerInventory | `InventoryGUI` | RW | `obj.ownerInventory = <value>` |
| childInventory | `InventoryGUI` | RW | `obj.childInventory = <value>` |
| mouseFocus | `boolean` | RW | `obj.mouseFocus = <value>` |
| callbackObject | `RootObject` | RW | `obj.callbackObject = <value>` |
| needItemsUpdate | `boolean` | RW | `obj.needItemsUpdate = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| inventorySections | `InventorySectionsMapBinding::MapType` | RW | `obj.inventorySections = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| setPositionReal | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| showBackpack | `on: boolean` | `void` | `obj:showBackpack(on)` |
| getBackpack | `` | `ContainerItem` | `obj:getBackpack()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| hasSameOwner | `other: InventoryGUI` | `boolean` | `obj:hasSameOwner(other)` |
| getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| getSelectedItem | `sectionName: string` | `Item` | `obj:getSelectedItem(sectionName)` |
| stealingGUIInfoUpdate | `` | `void` | `obj:stealingGUIInfoUpdate()` |
| pickupItemToMouse | `sectionName: string` | `boolean` | `obj:pickupItemToMouse(sectionName)` |
| getMouseItem | `` | `Item` | `obj:getMouseItem()` |
| takeCertainAmountFrom | `baseItem: Item, amount: integer` | `Item` | `obj:takeCertainAmountFrom(baseItem, amount)` |
| RClickAutoTrade | `invSectionName: string, x: integer, y: integer, sendingTo: InventoryGUI, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTrade(invSectionName, x, y, sendingTo, thieveryChecks, first)` |
| RClickAutoTradeAll | `invSectionName: string, x: integer, y: integer, sendingTo: InventoryGUI, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTradeAll(invSectionName, x, y, sendingTo, thieveryChecks, first)` |
| isTradingForMoney | `cameFrom: InventoryGUI` | `boolean` | `obj:isTradingForMoney(cameFrom)` |
| isStealing | `cameFrom: InventoryGUI` | `boolean` | `obj:isStealing(cameFrom)` |
| isWithinRangeToTrade | `otherOwner: RootObject, stealing: boolean` | `boolean` | `obj:isWithinRangeToTrade(otherOwner, stealing)` |
| setItemToPlayerPortrait | `item: Item, character: Character` | `boolean` | `obj:setItemToPlayerPortrait(item, character)` |
| playSound | `eventId: string, item: Item` | `void` | `obj:playSound(eventId, item)` |
| fencingConfirmationCallback | `b: integer` | `void` | `obj:fencingConfirmationCallback(b)` |
| getPlayerTradeCharacter | `` | `RootObject` | `obj:getPlayerTradeCharacter()` |
| refreshAllSections | `` | `void` | `obj:refreshAllSections()` |
| updateDatapanel | `` | `void` | `obj:updateDatapanel()` |
| rightClickAutoEquipping | `` | `void` | `obj:rightClickAutoEquipping()` |
| tryToEquip | `item: Item, replace: boolean` | `boolean` | `obj:tryToEquip(item, replace)` |
| returnItem | `item: Item, sectionName: string` | `void` | `obj:returnItem(item, sectionName)` |
| hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getSectionWithMouseLocal | `` | `string` | `obj:getSectionWithMouseLocal()` |
| getSlotWithMouse | `` | `iVector2` | `obj:getSlotWithMouse()` |
| refreshSection [1] | `section: InventorySection` | `void` | `obj:refreshSection(section)` |
| refreshSection [2] | `` | `void` | `obj:refreshSection()` |
| getSection [1] | `sectionName: string` | `InventorySection` | `obj:getSection(sectionName)` |
| getSection [2] | `sect: InventorySectionGUI` | `InventorySection` | `obj:getSection(sect)` |
| getWindowCoord | `` | `MyGUI::IntCoord` | `obj:getWindowCoord()` |
| autoChangeSelectedObject | `obj: hand` | `void` | `obj:autoChangeSelectedObject(obj)` |
| placeItemFromMouse | `sectionName: string` | `boolean` | `obj:placeItemFromMouse(sectionName)` |
| autoArrangeButton | `` | `void` | `obj:autoArrangeButton()` |
| openBackpackButton | `` | `void` | `obj:openBackpackButton()` |
| openLimbsInterface | `` | `void` | `obj:openLimbsInterface()` |
| windowButtonPressed | `name: string` | `void` | `obj:windowButtonPressed(name)` |
| fencingConfirmation | `item: Item, thief: RootObject, fence: Character, sectionName: string` | `boolean` | `obj:fencingConfirmation(item, thief, fence, sectionName)` |
| getTrader1Trader2 | `` | `InventoryGUI` | `obj:getTrader1Trader2()` |
| sectionMouseButtonPressed | `sender: MyGUI::Widget, left: integer, top: integer, id: integer` | `void` | `obj:sectionMouseButtonPressed(sender, left, top, id)` |
| sectionMouseButtonReleased | `sender: MyGUI::Widget, left: integer, top: integer, id: integer` | `void` | `obj:sectionMouseButtonReleased(sender, left, top, id)` |
| onWindowFocus | `sender: MyGUI::Widget, focus: boolean` | `void` | `obj:onWindowFocus(sender, focus)` |
| windowMoved | `sender: MyGUI::Window` | `void` | `obj:windowMoved(sender)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setTradingTown | `` | `void` | `InventoryGUI.setTradingTown()`<br>`obj:setTradingTown()` |
| getTradingTown | `` | `Town` | `InventoryGUI.getTradingTown()`<br>`obj:getTradingTown()` |
| clearTradePartners | `` | `void` | `InventoryGUI.clearTradePartners()`<br>`obj:clearTradePartners()` |
| getNPCTrader | `` | `Character` | `InventoryGUI.getNPCTrader()`<br>`obj:getNPCTrader()` |
| isTradingForMoney_static | `` | `RootObject` | `InventoryGUI.isTradingForMoney_static()`<br>`obj:isTradingForMoney_static()` |
| isTradingAndStealing_static | `` | `RootObject` | `InventoryGUI.isTradingAndStealing_static()`<br>`obj:isTradingAndStealing_static()` |
| getTraderPriceMultiplier | `` | `number` | `InventoryGUI.getTraderPriceMultiplier()`<br>`obj:getTraderPriceMultiplier()` |
| canDropMouseItemWithoutPaying | `` | `boolean` | `InventoryGUI.canDropMouseItemWithoutPaying()`<br>`obj:canDropMouseItemWithoutPaying()` |
| removeTradePartner | `` | `void` | `InventoryGUI.removeTradePartner()`<br>`obj:removeTradePartner()` |
| addTradePartner | `` | `void` | `InventoryGUI.addTradePartner()`<br>`obj:addTradePartner()` |
| lockedItemCheck | `` | `boolean` | `InventoryGUI.lockedItemCheck()`<br>`obj:lockedItemCheck()` |
| makeIconForItem | `` | `InventoryIcon` | `InventoryGUI.makeIconForItem()`<br>`obj:makeIconForItem()` |

## InventoryGUI::FenceCallbackData
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Parent Class:** [`InventoryGUI`](#inventorygui)
**Metatable:** `KenshiLua.InventoryGUI_FenceCallbackData`

## InventoryGUI::InventoryTradeData
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`
**Parent Class:** [`InventoryGUI`](#inventorygui)
**Metatable:** `KenshiLua.InventoryTradeData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| inventory | `InventoryGUI` | RW | `obj.inventory = <value>` |
| paymentRequired | `boolean` | RW | `obj.paymentRequired = <value>` |
| canDropItems | `boolean` | RW | `obj.canDropItems = <value>` |
| isPlayer | `boolean` | RW | `obj.isPlayer = <value>` |
| owner | `hand` | RW | `obj.owner = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: InventoryTradeData` | `void` | `obj:operator_assign(other)` |
| isValid | `` | `boolean` | `obj:isValid()` |

## InventoryGUI::TradeResult
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterTradingWindow.h`
**Parent Class:** [`InventoryGUI`](#inventorygui)
**Metatable:** `KenshiLua.TradeResult`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | `integer` | RW | `obj.value = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `b: TradeResult` | `boolean` | `obj:operator_eq(b)` |
| showMessage | `` | `void` | `obj:showMessage()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| ShowMessage | `` | `void` | `InventoryGUI::TradeResult.ShowMessage()`<br>`obj:ShowMessage()` |

## InventoryIcon
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.InventoryIcon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| item | `Item` | RW | `obj.item = <value>` |
| image | `MyGUI::Widget` | R | `obj.image` |
| quantityText | `MyGUI::Widget` | R | `obj.quantityText` |
| chargesProgress | `MyGUI::Widget` | R | `obj.chargesProgress` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
| setPosition | `left: integer, top: integer` | `void` | `obj:setPosition(left, top)` |
| getSize | `` | `integer` | `obj:getSize()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createIconImage | `` | `iVector2` | `InventoryIcon.createIconImage()`<br>`obj:createIconImage()` |
| getItemSize | `` | `integer` | `InventoryIcon.getItemSize()`<br>`obj:getItemSize()` |
| getItemPosition | `` | `integer` | `InventoryIcon.getItemPosition()`<br>`obj:getItemPosition()` |

## InventoryItemBase
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`
**Metatable:** `KenshiLua.InventoryItemBase`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| manufacturerData | `GameData` | RW | `obj.manufacturerData = <value>` |
| materialData | `GameData` | RW | `obj.materialData = <value>` |
| coloriseData | `GameData` | RW | `obj.coloriseData = <value>` |
| isInInventory | `boolean` | RW | `obj.isInInventory = <value>` |
| inventoryPos | `iVector2` | RW | `obj.inventoryPos = <value>` |
| inventorySection | `string` | RW | `obj.inventorySection = <value>` |
| slotType | `AttachSlot` | RW | `obj.slotType = <value>` |
| originalFullChargeAmount | `number` | RW | `obj.originalFullChargeAmount = <value>` |
| chargesLeft | `number` | RW | `obj.chargesLeft = <value>` |
| quality | `number` | RW | `obj.quality = <value>` |
| weight | `number` | RW | `obj.weight = <value>` |
| itemFunction | `ItemFunction` | RW | `obj.itemFunction = <value>` |
| isTradeItem | `boolean` | RW | `obj.isTradeItem = <value>` |
| isEquipped | `boolean` | RW | `obj.isEquipped = <value>` |
| isUnique | `boolean` | RW | `obj.isUnique = <value>` |
| quantity | `integer` | RW | `obj.quantity = <value>` |
| itemWidth | `integer` | RW | `obj.itemWidth = <value>` |
| itemHeight | `integer` | RW | `obj.itemHeight = <value>` |
| deathItem | `boolean` | RW | `obj.deathItem = <value>` |
| objectType | `itemType` | RW | `obj.objectType = <value>` |
| properOwner | `hand` | RW | `obj.properOwner = <value>` |
| _whosInventoryWeAreIn | `hand` | RW | `obj._whosInventoryWeAreIn = <value>` |
| _isResearchArtifact | `boolean` | RW | `obj._isResearchArtifact = <value>` |
| itemGroup | `lightuserdata` | RW | `obj.itemGroup = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| deactivate | `` | `void` | `obj:deactivate()` |
| resetAfterCopy | `` | `void` | `obj:resetAfterCopy()` |
| resetCharges | `randomise: boolean` | `void` | `obj:resetCharges(randomise)` |
| getItemType | `` | `integer` | `obj:getItemType()` |
| getItemWeightSingle | `` | `number` | `obj:getItemWeightSingle()` |
| getItemWeight | `` | `number` | `obj:getItemWeight()` |
| _serialise | `_a1: GameDataContainer, _a2: itemType` | `GameData` | `obj:_serialise(_a1, _a2)` |
| _loadFromSerialise | `_a1: GameDataContainer, _a2: GameData` | `void` | `obj:_loadFromSerialise(_a1, _a2)` |
| loadFromSerialise | `_a1: GameSaveState` | `void` | `obj:loadFromSerialise(_a1)` |
| serialiseInInventory | `_a1: GameDataContainer, _a2: GameData` | `GameData` | `obj:serialiseInInventory(_a1, _a2)` |
| loadFromSerialiseInInventory | `_a1: GameDataContainer, _a2: GameData` | `void` | `obj:loadFromSerialiseInInventory(_a1, _a2)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getAvgPrice | `` | `integer` | `obj:getAvgPrice()` |
| getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| getValueAll | `isPlayer: boolean` | `integer` | `obj:getValueAll(isPlayer)` |
| getMaxAffordableNum | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:getMaxAffordableNum(cashLimit, isPlayer)` |
| isStackable | `section: InventorySection` | `integer` | `obj:isStackable(section)` |
| canStackWith | `other: InventoryItemBase` | `boolean` | `obj:canStackWith(other)` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| isSameAs | `who: InventoryItemBase` | `boolean` | `obj:isSameAs(who)` |
| onGround | `` | `boolean` | `obj:onGround()` |
| isResearchArtifact | `` | `boolean` | `obj:isResearchArtifact()` |
| getLevel | `` | `integer` | `obj:getLevel()` |
| getItemSound | `` | `lightuserdata` | `obj:getItemSound()` |
| isStolen | `includeUnknown: boolean` | `boolean` | `obj:isStolen(includeUnknown)` |
| merchantPriceMod | `` | `number` | `obj:merchantPriceMod()` |
| activate | `_a1: boolean, _a2: Vector3, _a3: Quaternion, _a4: boolean, _a5: integer, _a6: boolean` | `void` | `obj:activate(_a1, _a2, _a3, _a4, _a5, _a6)` |
| getStolenItemGUIInfo | `` | `void` | `obj:getStolenItemGUIInfo()` |
| getBuyBackGUIInfo | `` | `void` | `obj:getBuyBackGUIInfo()` |
| serialise | `container: GameDataContainer, refList: GameData, offsetPosToSubtract: userdata` | `GameSaveState` | `obj:serialise(container, refList, offsetPosToSubtract)` |
| getTooltipData1 | `` | `void` | `obj:getTooltipData1()` |
| getTooltipData2 | `` | `void` | `obj:getTooltipData2()` |
| addQuantity | `amount: integer, addedItem: Item, section: InventorySection` | `integer` | `obj:addQuantity(amount, addedItem, section)` |
| getProperOwner | `` | `hand` | `obj:getProperOwner()` |
| setProperOwner | `h: hand` | `void` | `obj:setProperOwner(h)` |
| getTooltipTradeValue | `` | `void` | `obj:getTooltipTradeValue()` |

## InventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.InventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| datapanel | `DatapanelGUI` | RW | `obj.datapanel = <value>` |
| dataPanelInfos | `GameDataCopyStandalone` | RW | `obj.dataPanelInfos = <value>` |
| window | `MyGUI::Window` | RW | `obj.window = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWindow | `` | `MyGUI::Window` | `obj:getWindow()` |
| getWidget | `name: string` | `MyGUI::Widget` | `obj:getWidget(name)` |
| getDatapanel | `` | `DatapanelGUI` | `obj:getDatapanel()` |
| setupDataPanelInfos | `name: string` | `void` | `obj:setupDataPanelInfos(name)` |
| createSectionGUI | `section: InventorySection` | `InventorySectionGUI` | `obj:createSectionGUI(section)` |
| setSectionGUIDisabled | `sectionName: string, width: integer, height: integer` | `void` | `obj:setSectionGUIDisabled(sectionName, width, height)` |
| resizeSection | `section: InventorySection, sectionGUI: InventorySectionGUI` | `MyGUI::IntSize` | `obj:resizeSection(section, sectionGUI)` |
| resizeSectionWidget | `width: integer, height: integer` | `MyGUI::IntSize` | `obj:resizeSectionWidget(width, height)` |
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| notifyCellSizeChanged | `` | `void` | `InventoryLayout.notifyCellSizeChanged()`<br>`obj:notifyCellSizeChanged()` |

## InventorySection
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`
**Metatable:** `KenshiLua.InventorySection`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |
| width | `integer` | RW | `obj.width = <value>` |
| height | `integer` | RW | `obj.height = <value>` |
| armourOnly | `boolean` | RW | `obj.armourOnly = <value>` |
| stackingBonusMin | `integer` | RW | `obj.stackingBonusMin = <value>` |
| stackingBonusMult | `number` | RW | `obj.stackingBonusMult = <value>` |
| itemsLimit | `integer` | RW | `obj.itemsLimit = <value>` |
| weightMultiplier | `number` | RW | `obj.weightMultiplier = <value>` |
| totalWeight | `number` | RW | `obj.totalWeight = <value>` |
| isAnEquippedItemSection | `boolean` | RW | `obj.isAnEquippedItemSection = <value>` |
| limitedSlot | `AttachSlot` | RW | `obj.limitedSlot = <value>` |
| containerSlot | `boolean` | RW | `obj.containerSlot = <value>` |
| callbackObject | `RootObject` | RW | `obj.callbackObject = <value>` |
| parentInventory | `Inventory` | RW | `obj.parentInventory = <value>` |
| enabled | `boolean` | RW | `obj.enabled = <value>` |
| content | `unknown` | RW | `obj.content = <value>` |
| items | `Ogre::vector<InventorySection::SectionItem>::type` | RW | `obj.items = <value>` |
| veryLimitedSlot | `lektor<GameData*>` | RW | `obj.veryLimitedSlot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hasRoomForItem | `_itemData: GameData, quantity: integer` | `boolean` | `obj:hasRoomForItem(_itemData, quantity)` |
| notifyModified | `` | `void` | `obj:notifyModified()` |
| addItem | `itemToAdd: Item, quantity: integer` | `boolean` | `obj:addItem(itemToAdd, quantity)` |
| _addItem | `item: Item, x: integer, y: integer` | `void` | `obj:_addItem(item, x, y)` |
| getItemAt | `x: integer, y: integer` | `Item` | `obj:getItemAt(x, y)` |
| hasItemType | `type: itemType` | `boolean` | `obj:hasItemType(type)` |
| autoArrange | `` | `void` | `obj:autoArrange()` |
| getNumItems | `` | `integer` | `obj:getNumItems()` |
| isEmpty | `` | `boolean` | `obj:isEmpty()` |
| removeItem | `item: Item` | `boolean` | `obj:removeItem(item)` |
| clearAllItems | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAllItems(destroy, skipUnique)` |
| canItemGoHere | `item: Item, x: integer, y: integer` | `boolean` | `obj:canItemGoHere(item, x, y)` |
| existsItemInFootprint | `item: Item, x: integer, y: integer` | `boolean` | `obj:existsItemInFootprint(item, x, y)` |
| getLimitedSlot | `` | `AttachSlot` | `obj:getLimitedSlot()` |
| setupContainerData | `data: GameData` | `void` | `obj:setupContainerData(data)` |
| applyStackingBonuses | `normalStackableAmount: integer` | `integer` | `obj:applyStackingBonuses(normalStackableAmount)` |
| recalculateTotalWeight | `` | `void` | `obj:recalculateTotalWeight()` |
| setWeightMultiplier | `mult: number` | `void` | `obj:setWeightMultiplier(mult)` |
| setStackingBonus | `minn: integer, mult: number` | `void` | `obj:setStackingBonus(minn, mult)` |
| getMaxStack | `` | `integer` | `obj:getMaxStack()` |
| addVeryLimitedSlot | `item: GameData` | `void` | `obj:addVeryLimitedSlot(item)` |
| clearVeryLimitedSlot | `` | `void` | `obj:clearVeryLimitedSlot()` |
| getEnabled | `` | `boolean` | `obj:getEnabled()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| setItemsLimitCount | `value: integer` | `void` | `obj:setItemsLimitCount(value)` |
| getItemsLimitReached | `` | `boolean` | `obj:getItemsLimitReached()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| getFillPercentage | `` | `number` | `obj:getFillPercentage()` |
| getItem | `` | `Item` | `obj:getItem()` |
| setupEquipCallbacks | `owner: RootObject` | `void` | `obj:setupEquipCallbacks(owner)` |
| numItemsInFootprint | `item: Item, x: integer, y: integer` | `integer` | `obj:numItemsInFootprint(item, x, y)` |
| resize | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resize(w, h, clearContent)` |
| hasItem [1] | `itemData: GameData` | `boolean` | `obj:hasItem(itemData)` |
| hasItem [2] | `item: Item` | `boolean` | `obj:hasItem(item)` |
| hasItem [1] | `itemData: GameData` | `boolean` | `obj:hasItem(itemData)` |
| hasItem [2] | `item: Item` | `boolean` | `obj:hasItem(item)` |
| isLimitedSlotCompatible [1] | `itemData: GameData` | `boolean` | `obj:isLimitedSlotCompatible(itemData)` |
| isLimitedSlotCompatible [2] | `item: Item` | `boolean` | `obj:isLimitedSlotCompatible(item)` |
| getValidInventoryPosition | `item: Item` | `boolean\|integer` | `obj:getValidInventoryPosition(item)` |
| getAllItemsOfType [1] | `list: lektor<Item*>, item: Item` | `void` | `obj:getAllItemsOfType(list, item)` |
| getAllItemsOfType [2] | `list: lektor<Item*>, type: itemType` | `void` | `obj:getAllItemsOfType(list, type)` |
| getAllItemsOfName | `itemName: string` | `void` | `obj:getAllItemsOfName(itemName)` |
| findNearestPlaceForItem | `item: Item` | `boolean\|integer` | `obj:findNearestPlaceForItem(item)` |
| getItemsInFootprint [1] | `itemList: lektor<Item*>, itemWidth: integer, itemHeight: integer, x: integer, y: integer` | `integer` | `obj:getItemsInFootprint(itemList, itemWidth, itemHeight, x, y)` |
| getItemsInFootprint [2] | `out: lektor<Item*>, item: Item, x: integer, y: integer` | `integer` | `obj:getItemsInFootprint(out, item, x, y)` |
| getItems | `` | `Ogre::vector<InventorySection::SectionItem>::type` | `obj:getItems()` |

## InventorySection::SectionItem
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`
**Parent Class:** [`InventorySection`](#inventorysection)
**Metatable:** `KenshiLua.SectionItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| item | `Item` | RW | `obj.item = <value>` |
| x | `integer` | RW | `obj.x = <value>` |
| y | `integer` | RW | `obj.y = <value>` |
| w | `integer` | RW | `obj.w = <value>` |
| h | `integer` | RW | `obj.h = <value>` |

## InventorySectionGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.InventorySectionGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| widget | `MyGUI::Widget` | RW | `obj.widget = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hasMouse | `` | `boolean` | `obj:hasMouse()` |
| getItemAbsolutePosition | `x: integer, y: integer` | `MyGUI::IntPoint` | `obj:getItemAbsolutePosition(x, y)` |
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
| getPositionSlot | `section: InventorySection, round: boolean` | `MyGUI::IntPoint` | `obj:getPositionSlot(section, round)` |
| getBestPositionSlot | `section: InventorySection, item: Item` | `MyGUI::IntPoint` | `obj:getBestPositionSlot(section, item)` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| refreshIcons | `section: InventorySection` | `void` | `obj:refreshIcons(section)` |
| update | `` | `void` | `obj:update()` |

## InventoryTraderGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`
**Metatable:** `KenshiLua.InventoryTraderGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| sectionWidth | `integer` | RW | `obj.sectionWidth = <value>` |
| sectionHeight | `integer` | RW | `obj.sectionHeight = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| getCallbackCharacter | `` | `Character` | `obj:getCallbackCharacter()` |
| getCallbackObject | `` | `RootObject` | `obj:getCallbackObject()` |
| refreshSection | `section: InventorySection` | `void` | `obj:refreshSection(section)` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`
**Metatable:** `KenshiLua.Item`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| physicalShouldExist | `boolean` | RW | `obj.physicalShouldExist = <value>` |
| existAsBareWeapon | `boolean` | RW | `obj.existAsBareWeapon = <value>` |
| persistant | `hand` | RW | `obj.persistant = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| physical | `lightuserdata` | RW | `obj.physical = <value>` |
| _isPhysical | `boolean` | RW | `obj._isPhysical = <value>` |
| physicalEntity | `lightuserdata` | RW | `obj.physicalEntity = <value>` |
| creatingPhysical | `boolean` | RW | `obj.creatingPhysical = <value>` |
| fixedPhysicalPosition | `boolean` | RW | `obj.fixedPhysicalPosition = <value>` |
| useDynamicPhysics | `boolean` | RW | `obj.useDynamicPhysics = <value>` |
| loadingEntity | `lightuserdata` | RW | `obj.loadingEntity = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isGear | `` | `Gear` | `obj:isGear()` |
| getClassType | `` | `itemType` | `obj:getClassType()` |
| resetAfterCopy | `` | `void` | `obj:resetAfterCopy()` |
| deactivate | `` | `void` | `obj:deactivate()` |
| setPositionRotation | `position: Vector3, rotation: Quaternion, fixedPosition: boolean` | `void` | `obj:setPositionRotation(position, rotation, fixedPosition)` |
| isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| isArmour | `` | `Armour` | `obj:isArmour()` |
| isWeapon | `` | `Weapon` | `obj:isWeapon()` |
| isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| isAFactionUniform | `` | `Faction` | `obj:isAFactionUniform()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| getModelName | `` | `string` | `obj:getModelName()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| hasIngredients | `` | `boolean` | `obj:hasIngredients()` |
| isGoodFood | `` | `boolean` | `obj:isGoodFood()` |
| getEntity | `` | `lightuserdata` | `obj:getEntity()` |
| getTimeout | `` | `TimeOfDay` | `obj:getTimeout()` |
| _serialise | `container: GameDataContainer, type: itemType` | `GameData` | `obj:_serialise(container, type)` |
| _loadFromSerialise | `container: GameDataContainer, state: GameData` | `void` | `obj:_loadFromSerialise(container, state)` |
| loadFromSerialise | `saveState: GameSaveState` | `void` | `obj:loadFromSerialise(saveState)` |
| serialiseInInventory | `container: GameDataContainer, refList: GameData` | `GameData` | `obj:serialiseInInventory(container, refList)` |
| loadFromSerialiseInInventory | `container: GameDataContainer, state: GameData` | `void` | `obj:loadFromSerialiseInInventory(container, state)` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| getLevel | `` | `integer` | `obj:getLevel()` |
| destroyItemEntityCallback_Equipping | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| isPersistant | `` | `boolean` | `obj:isPersistant()` |
| persistantOwnerExists | `` | `boolean` | `obj:persistantOwnerExists()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| getInventoryWeAreIn | `` | `hand` | `obj:getInventoryWeAreIn()` |
| setInventoryWeAreIn | `h: hand` | `void` | `obj:setInventoryWeAreIn(h)` |
| isFood | `` | `boolean` | `obj:isFood()` |
| activate | `createPhysical: boolean, position: Vector3, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:activate(createPhysical, position, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| serialise | `c: GameDataContainer, r: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(c, r, offset)` |
| createItemEntityCallback_Equipping | `ent: userdata, node: userdata` | `void` | `obj:createItemEntityCallback_Equipping(ent, node)` |
| notifyTheftFrom [1] | `owner: hand` | `void` | `obj:notifyTheftFrom(owner)` |
| notifyTheftFrom [2] | `obj: RootObject` | `void` | `obj:notifyTheftFrom(obj)` |
| findProperOwner [1] | `obj: RootObject` | `hand` | `obj:findProperOwner(obj)` |
| findProperOwner [2] | `handle: hand` | `hand` | `obj:findProperOwner(handle)` |
| setPersistant [1] | `anchor: hand` | `void` | `obj:setPersistant(anchor)` |
| setPersistant [2] | `p: boolean` | `void` | `obj:setPersistant(p)` |
| itemEntityCreated | `ent: userdata` | `void` | `obj:itemEntityCreated(ent)` |

## iVector2
**Header:** `extern/KenshiLib/Include/kenshi/util/iVector2.h`
**Metatable:** `KenshiLua.iVector2`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | `integer` | RW | `obj.x = <value>` |
| y | `integer` | RW | `obj.y = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getLinearValue | `` | `integer` | `obj:getLinearValue()` |
| getAsString | `` | `string` | `obj:getAsString()` |
| operator_eq | `b: iVector2` | `boolean` | `obj:operator_eq(b)` |
| operator_ne | `` | `boolean` | `obj:operator_ne()` |
| operator_lt | `` | `boolean` | `obj:operator_lt()` |
| operator_add | `` | `iVector2` | `obj:operator_add()` |

## KenshiLib::BinaryVersion
**Header:** `extern/KenshiLib/Include/kenshi/Kenshi.h`
**Metatable:** `KenshiLua.BinaryVersion`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_lt | `` | `boolean` | `obj:operator_lt()` |
| GetPlatform | `` | `integer` | `obj:GetPlatform()` |
| GetPlatformStr | `` | `void` | `obj:GetPlatformStr()` |
| GetBinaryName | `` | `void` | `obj:GetBinaryName()` |
| ToString | `` | `void` | `obj:ToString()` |
| GetVersion | `` | `void` | `obj:GetVersion()` |
| getPlatform | `` | `integer` | `obj:getPlatform()` |
| getPlatformStr | `` | `void` | `obj:getPlatformStr()` |
| getBinaryName | `` | `void` | `obj:getBinaryName()` |
| toString | `` | `void` | `obj:toString()` |
| getVersion | `` | `void` | `obj:getVersion()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| GetKenshiVersion | `` | `KenshiLib::BinaryVersion` | `KenshiLib::BinaryVersion.GetKenshiVersion()`<br>`obj:GetKenshiVersion()` |
| getKenshiVersion | `` | `KenshiLib::BinaryVersion` | `KenshiLib::BinaryVersion.getKenshiVersion()`<br>`obj:getKenshiVersion()` |
| new | `` | `KenshiLib::BinaryVersion` | `KenshiLib::BinaryVersion.new()`<br>`obj:new()` |

## LevelEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Metatable:** `KenshiLua.LevelEditor`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| levelEditModeOn | `boolean` | RW | `obj.levelEditModeOn = <value>` |
| panel | `lightuserdata` | R | `obj.panel` |
| interiorModeWindow | `InteriorModeButtonWindow` | RW | `obj.interiorModeWindow = <value>` |
| selectedLocked | `integer` | RW | `obj.selectedLocked = <value>` |
| selectedObject | `hand` | RW | `obj.selectedObject = <value>` |
| selectedFeature | `lightuserdata` | R | `obj.selectedFeature` |
| seedMode | `integer` | RW | `obj.seedMode = <value>` |
| roadMode | `integer` | RW | `obj.roadMode = <value>` |
| roadIndex | `integer` | RW | `obj.roadIndex = <value>` |
| roadMarker | `lightuserdata` | R | `obj.roadMarker` |
| roadMakerMO | `lightuserdata` | R | `obj.roadMakerMO` |
| foliageEraser | `lightuserdata` | R | `obj.foliageEraser` |
| fogEditor | `FogEditor` | RW | `obj.fogEditor = <value>` |
| townListWindow | `LevelEditor::TownListWindow` | RW | `obj.townListWindow = <value>` |
| factionListWindow | `LevelEditor::FactionListWindow` | RW | `obj.factionListWindow = <value>` |
| squadListWindow | `LevelEditor::SquadListWindow` | RW | `obj.squadListWindow = <value>` |
| npcListWindow | `LevelEditor::NpcListWindow` | RW | `obj.npcListWindow = <value>` |
| featureListWindow | `LevelEditor::NpcListWindow` | RW | `obj.featureListWindow = <value>` |
| itemListWindow | `LevelEditor::ItemListWindow` | RW | `obj.itemListWindow = <value>` |
| navmeshWindow | `DatapanelGUI` | RW | `obj.navmeshWindow = <value>` |
| editMapTitleWindow | `MyGUI::Widget` | R | `obj.editMapTitleWindow` |
| factionTxt | `MyGUI::Widget` | R | `obj.factionTxt` |
| altitudeTxt | `MyGUI::Widget` | R | `obj.altitudeTxt` |
| activeModTxt | `MyGUI::Widget` | R | `obj.activeModTxt` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| close | `` | `void` | `obj:close()` |
| update | `` | `void` | `obj:update()` |
| updateGizmo | `` | `boolean` | `obj:updateGizmo()` |
| levelEditMode | `on: boolean` | `void` | `obj:levelEditMode(on)` |
| isInteriorEditMode | `` | `boolean` | `obj:isInteriorEditMode()` |
| getActiveModIndex | `` | `integer` | `obj:getActiveModIndex()` |
| getActiveMod | `` | `string` | `obj:getActiveMod()` |
| isBaseActive | `` | `boolean` | `obj:isBaseActive()` |
| setEditSquad | `squad: GameData` | `void` | `obj:setEditSquad(squad)` |
| repath | `_a1: DataPanelLine` | `void` | `obj:repath(_a1)` |
| toggleSeedMode | `line: DataPanelLine` | `void` | `obj:toggleSeedMode(line)` |
| clearSeedPoints | `_a1: DataPanelLine` | `void` | `obj:clearSeedPoints(_a1)` |
| setSeedMode | `mode: integer` | `void` | `obj:setSeedMode(mode)` |
| toggleRoadEditor | `_a1: DatapanelGUI, tab: integer` | `void` | `obj:toggleRoadEditor(_a1, tab)` |
| toggleFoliageRemoval | `line: DataPanelLine` | `void` | `obj:toggleFoliageRemoval(line)` |
| clearChanges | `object: RootObject` | `boolean` | `obj:clearChanges(object)` |
| deleteDuplicateBuildings | `` | `integer` | `obj:deleteDuplicateBuildings()` |
| fixMountedBuildings | `` | `integer` | `obj:fixMountedBuildings()` |
| deleteAll | `data: GameData, confirmed: boolean` | `integer` | `obj:deleteAll(data, confirmed)` |
| adjustAltitudeSpeed | `s: number` | `void` | `obj:adjustAltitudeSpeed(s)` |
| fixInvalidInteriorFurnitureStates | `` | `integer` | `obj:fixInvalidInteriorFurnitureStates()` |
| fixBuildingFloorState | `b: Building, parent: Building` | `boolean` | `obj:fixBuildingFloorState(b, parent)` |
| setSelectedObject | `obj: RootObject` | `void` | `obj:setSelectedObject(obj)` |
| updateRoadEditor | `` | `void` | `obj:updateRoadEditor()` |
| setRoadWidth | `l: DataPanelLine` | `void` | `obj:setRoadWidth(l)` |
| setRoadHidden | `l: DataPanelLine` | `void` | `obj:setRoadHidden(l)` |
| drawRoads | `_a1: DataPanelLine` | `void` | `obj:drawRoads(_a1)` |
| eraseRoads | `_a1: DataPanelLine` | `void` | `obj:eraseRoads(_a1)` |
| drawAllRoads | `_a1: DataPanelLine` | `void` | `obj:drawAllRoads(_a1)` |
| projectRoads | `_a1: DataPanelLine` | `void` | `obj:projectRoads(_a1)` |
| validateRoads | `_a1: DataPanelLine` | `void` | `obj:validateRoads(_a1)` |
| createRoadMarker | `` | `void` | `obj:createRoadMarker()` |
| destroyRoadMaker | `` | `void` | `obj:destroyRoadMaker()` |
| updateFoliageRemoval | `` | `void` | `obj:updateFoliageRemoval()` |
| updateSeedEditor | `` | `void` | `obj:updateSeedEditor()` |
| deleteObject | `h: hand` | `void` | `obj:deleteObject(h)` |
| saveMod | `sender: MyGUI::Widget` | `void` | `obj:saveMod(sender)` |
| regenerate | `sender: MyGUI::Widget` | `void` | `obj:regenerate(sender)` |
| closeNavmeshWindow | `a1: MyGUI::Window, a2: string` | `void` | `obj:closeNavmeshWindow(a1, a2)` |
| fixBuildings | `a1: MyGUI::Widget` | `void` | `obj:fixBuildings(a1)` |
| factionButton | `sender: MyGUI::Widget` | `void` | `obj:factionButton(sender)` |
| npcButton | `sender: MyGUI::Widget` | `void` | `obj:npcButton(sender)` |
| townButton | `sender: MyGUI::Widget` | `void` | `obj:townButton(sender)` |
| squadButton | `sender: MyGUI::Widget` | `void` | `obj:squadButton(sender)` |
| featureButton | `sender: MyGUI::Widget` | `void` | `obj:featureButton(sender)` |
| fogButton | `sender: MyGUI::Widget` | `void` | `obj:fogButton(sender)` |
| itemsButton | `sender: MyGUI::Widget` | `void` | `obj:itemsButton(sender)` |
| buildingsButton | `sender: MyGUI::Widget` | `void` | `obj:buildingsButton(sender)` |
| navmeshButton | `a1: MyGUI::Widget` | `void` | `obj:navmeshButton(a1)` |
| exitLevelEditMode | `sender: MyGUI::Widget` | `void` | `obj:exitLevelEditMode(sender)` |
| activeModChanged | `sender: MyGUI::ComboBox, a2: integer` | `void` | `obj:activeModChanged(sender, a2)` |

## LevelEditor::FactionListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.FactionListWindow`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| itemSelected | `item: GameData` | `void` | `obj:itemSelected(item)` |

## LevelEditor::GamedataSelectionList
**Header:** `extern/KenshiLib/Include/kenshi/gui/GameDataEditorWindow.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.GamedataSelectionList`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | `MyGUI::Widget` | R | `obj.win` |
| list | `MyGUI::Widget` | R | `obj.list` |
| items | `lektor<GameData*>` | RW | `obj.items = <value>` |
| levelEditor | `LevelEditor` | R | `obj.levelEditor` |
| lastItem | `integer` | RW | `obj.lastItem = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| deselectItem | `` | `void` | `obj:deselectItem()` |
| selectItem | `item: GameData` | `boolean` | `obj:selectItem(item)` |
| getSelectedItem | `` | `GameData` | `obj:getSelectedItem()` |
| itemSelected | `item: GameData` | `void` | `obj:itemSelected(item)` |
| formatItem | `o: GameData` | `string` | `obj:formatItem(o)` |
| listItemSelected | `_sender: MyGUI::Widget, _index: integer` | `void` | `obj:listItemSelected(_sender, _index)` |
| changeFilter | `e: MyGUI::Widget` | `void` | `obj:changeFilter(e)` |

## LevelEditor::ItemListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.ItemListWindow`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| itemSelected | `item: GameData` | `void` | `obj:itemSelected(item)` |

## LevelEditor::NpcListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.NpcListWindow`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| itemSelected | `item: GameData` | `void` | `obj:itemSelected(item)` |

## LevelEditor::SquadListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.SquadListWindow`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| refresh | `faction: GameData` | `void` | `obj:refresh(faction)` |
| itemSelected | `item: GameData` | `void` | `obj:itemSelected(item)` |

## LevelEditor::TownListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.TownListWindow`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| formatItem | `o: GameData` | `string` | `obj:formatItem(o)` |

## LightBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/LightBuilding.h`
**Metatable:** `KenshiLua.LightBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mountedBuilding | `hand` | RW | `obj.mountedBuilding = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| needPowerRightNow | `` | `boolean` | `obj:needPowerRightNow()` |
| getPositionMarker | `currentPosition: Vector3` | `Vector3` | `obj:getPositionMarker(currentPosition)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| getMountedBuilding | `` | `hand` | `obj:getMountedBuilding()` |
| setMountedBuilding | `b: Building` | `void` | `obj:setMountedBuilding(b)` |

## LimbsInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.LimbsInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | `Character` | RW | `obj.character = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |

## ListScrollBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_ListScrollBar.h`
**Metatable:** `KenshiLua.ListScrollBar`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| disableEvents | `boolean` | RW | `obj.disableEvents = <value>` |
| mListName | `MyGUI::Widget` | R | `obj.mListName` |
| mListValue | `MyGUI::Widget` | R | `obj.mListValue` |
| mListIndex | `MyGUI::Widget` | R | `obj.mListIndex` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setEnabled | `_a1: boolean` | `void` | `obj:setEnabled(_a1)` |
| initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | `` | `void` | `obj:shutdownOverride()` |
| getTypeName | `` | `void` | `obj:getTypeName()` |

## LoadingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadingWindow.h`
**Metatable:** `KenshiLua.LoadingWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentIndex | `integer` | RW | `obj.currentIndex = <value>` |
| currentTime | `number` | RW | `obj.currentTime = <value>` |
| loadingText | `MyGUI::Widget` | R | `obj.loadingText` |
| messageText | `MyGUI::Widget` | R | `obj.messageText` |
| backgroundImage | `MyGUI::Widget` | R | `obj.backgroundImage` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reload | `` | `void` | `obj:reload()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| show | `` | `void` | `obj:show()` |
| hide | `` | `void` | `obj:hide()` |
| frameEntered | `_frame: number` | `void` | `obj:frameEntered(_frame)` |
| setRandomBackground | `` | `void` | `obj:setRandomBackground()` |
| setRandomTip | `` | `void` | `obj:setRandomTip()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getInstance | `` | `LoadingWindow` | `LoadingWindow.getInstance()`<br>`obj:getInstance()` |

## LoadSaveWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`
**Metatable:** `KenshiLua.LoadSaveWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| list | `MyGUI::Widget` | R | `obj.list` |
| games | `lektor<SaveInfo>` | RW | `obj.games = <value>` |
| infoPanel | `DatapanelGUI` | RW | `obj.infoPanel = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| select | `index: integer` | `void` | `obj:select(index)` |
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
| deleteSelectedSave | `mbResult: integer` | `void` | `obj:deleteSelectedSave(mbResult)` |
| addOption | `key: integer, check: string, label: string, caption: string` | `void` | `obj:addOption(key, check, label, caption)` |
| enableOption | `key: integer, enabled: boolean` | `void` | `obj:enableOption(key, enabled)` |
| getOptions | `` | `integer` | `obj:getOptions()` |
| close | `sender: MyGUI::Widget` | `void` | `obj:close(sender)` |
| selectGame | `sender: MyGUI::MultiListBox, index: integer` | `void` | `obj:selectGame(sender, index)` |
| keyPressed | `w: MyGUI::Widget, key: integer, a3: integer` | `void` | `obj:keyPressed(w, key, a3)` |
| toggleCheck | `sender: MyGUI::Widget` | `void` | `obj:toggleCheck(sender)` |
| createInfo | `panel: MyGUI::Widget` | `void` | `obj:createInfo(panel)` |
| updateInfo | `index: integer` | `void` | `obj:updateInfo(index)` |

## LockedArmour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.LockedArmour`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lock | `lightuserdata` | R | `obj.lock` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isArmour | `` | `Armour` | `obj:isArmour()` |
| isLockedArmour | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _serialise | `container: GameDataContainer, type: itemType` | `GameData` | `obj:_serialise(container, type)` |
| _loadFromSerialise | `container: GameDataContainer, state: GameData` | `void` | `obj:_loadFromSerialise(container, state)` |
| getTooltipData1 | `` | `void` | `obj:getTooltipData1()` |
| getTooltipData2 | `` | `void` | `obj:getTooltipData2()` |

## Logger
**Header:** `extern/KenshiLib/Include/kenshi/Logger.h`
**Metatable:** `KenshiLua.Logger`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| init | `` | `void` | `obj:init()` |
| close | `` | `void` | `obj:close()` |
| logMessage | `sev: integer` | `void` | `obj:logMessage(sev)` |
| logMessageDebug | `` | `void` | `obj:logMessageDebug()` |
| logHeader | `` | `void` | `obj:logHeader()` |

## MainBarGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`
**Metatable:** `KenshiLua.MainBarGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| closeManagerWindowMsg | `integer` | RW | `obj.closeManagerWindowMsg = <value>` |
| isLevelEditMode | `boolean` | RW | `obj.isLevelEditMode = <value>` |
| isInteriorLevelEditMode | `boolean` | RW | `obj.isInteriorLevelEditMode = <value>` |
| bountyPanel | `MyGUI::Widget` | R | `obj.bountyPanel` |
| bountyDatapanel | `DatapanelGUI` | RW | `obj.bountyDatapanel = <value>` |
| townPanel | `lightuserdata` | R | `obj.townPanel` |
| portraitsTabPanel | `MyGUI::Widget` | R | `obj.portraitsTabPanel` |
| floorDownButton | `MyGUI::Widget` | R | `obj.floorDownButton` |
| floorUpButton | `MyGUI::Widget` | R | `obj.floorUpButton` |
| floorText | `MyGUI::Widget` | R | `obj.floorText` |
| dayText | `MyGUI::Widget` | R | `obj.dayText` |
| moneyLabel | `MyGUI::Widget` | R | `obj.moneyLabel` |
| moneyText | `MyGUI::Widget` | R | `obj.moneyText` |
| timeText | `MyGUI::Widget` | R | `obj.timeText` |
| medicalPanel | `lightuserdata` | R | `obj.medicalPanel` |
| ordersDataPanel | `OrdersPanel` | RW | `obj.ordersDataPanel = <value>` |
| extendInfoPanelButton | `MyGUI::Widget` | R | `obj.extendInfoPanelButton` |
| extendedInfoPanel | `MyGUI::Widget` | RW | `obj.extendedInfoPanel = <value>` |
| extendedInfoPanelDuration | `number` | RW | `obj.extendedInfoPanelDuration = <value>` |
| infoPanelEnabled | `boolean` | RW | `obj.infoPanelEnabled = <value>` |
| infoPanelExtended | `boolean` | RW | `obj.infoPanelExtended = <value>` |
| biomePanel | `MyGUI::Widget` | RW | `obj.biomePanel = <value>` |
| biomePanelText | `MyGUI::Widget` | R | `obj.biomePanelText` |
| biomePanelVisibleTimer | `number` | RW | `obj.biomePanelVisibleTimer = <value>` |
| biomeTimer | `number` | RW | `obj.biomeTimer = <value>` |
| lastFrameBiomeGroup | `GameData` | RW | `obj.lastFrameBiomeGroup = <value>` |
| rememberlastBiomeGroup | `GameData` | RW | `obj.rememberlastBiomeGroup = <value>` |
| portraitContextMenuTarget | `hand` | RW | `obj.portraitContextMenuTarget = <value>` |
| portraitContextMenuTimer | `number` | RW | `obj.portraitContextMenuTimer = <value>` |
| portraitSelectedContextIndex | `integer` | RW | `obj.portraitSelectedContextIndex = <value>` |
| portraitsUpdating | `boolean` | RW | `obj.portraitsUpdating = <value>` |
| toolTip | `ToolTipFixed` | RW | `obj.toolTip = <value>` |
| pausePanel | `MyGUI::Widget` | R | `obj.pausePanel` |
| loadingPanel | `MyGUI::Widget` | R | `obj.loadingPanel` |
| datapanels | `MainBarDatapanelsMapBinding::MapType` | RW | `obj.datapanels = <value>` |
| portraits | `MainBarPortraitsMapBinding::MapType` | RW | `obj.portraits = <value>` |
| speedButtons | `Ogre::FastArray<MyGUI::Button*>` | RW | `obj.speedButtons = <value>` |
| tabPortraits | `Ogre::FastArray<MainTabPortraitPlatoon>` | RW | `obj.tabPortraits = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| update | `` | `void` | `obj:update()` |
| speedChanged | `` | `void` | `obj:speedChanged()` |
| updateBountyPanelVisibility | `` | `void` | `obj:updateBountyPanelVisibility()` |
| setLevelEditMode | `on: boolean` | `void` | `obj:setLevelEditMode(on)` |
| setLevelEditInteriorMode | `interiorMode: boolean` | `void` | `obj:setLevelEditInteriorMode(interiorMode)` |
| pressedKey | `keycode: integer` | `void` | `obj:pressedKey(keycode)` |
| platoonUpdated | `platoon: RootObjectContainer, charAdded: boolean` | `void` | `obj:platoonUpdated(platoon, charAdded)` |
| updatePotraitsPlatoon | `` | `void` | `obj:updatePotraitsPlatoon()` |
| updatePortraits | `` | `void` | `obj:updatePortraits()` |
| refreshPortraitTabs | `` | `void` | `obj:refreshPortraitTabs()` |
| updatePortraitSize | `platoon: ActivePlatoon` | `void` | `obj:updatePortraitSize(platoon)` |
| getPausePanel | `` | `MyGUI::Widget` | `obj:getPausePanel()` |
| getLoadingPanel | `` | `MyGUI::Widget` | `obj:getLoadingPanel()` |
| getMedicalPanel | `` | `lightuserdata` | `obj:getMedicalPanel()` |
| ordersPanelClear | `` | `void` | `obj:ordersPanelClear()` |
| getToolTip | `` | `ToolTip` | `obj:getToolTip()` |
| getDatapanel | `id: string` | `DatapanelGUI` | `obj:getDatapanel(id)` |
| setMessagePosition | `` | `void` | `obj:setMessagePosition()` |
| serialise | `data: GameData` | `void` | `obj:serialise(data)` |
| loadFromSerialise | `data: GameData` | `void` | `obj:loadFromSerialise(data)` |
| setExtendInfoPanelEnabled | `enabled: boolean` | `void` | `obj:setExtendInfoPanelEnabled(enabled)` |
| _getWidget | `name: string` | `MyGUI::Widget` | `obj:_getWidget(name)` |
| autoChangeSelectedObject | `obj: hand` | `void` | `obj:autoChangeSelectedObject(obj)` |
| getPortrait [1] | `position: MyGUI::types::TPoint<int>` | `PortraitData` | `obj:getPortrait(position)` |
| getPortrait [2] | `character: hand` | `PortraitData` | `obj:getPortrait(character)` |
| updatePortrait | `character: hand` | `void` | `obj:updatePortrait(character)` |
| closeMapWindow | `_sender: MyGUI::Widget` | `void` | `obj:closeMapWindow(_sender)` |
| toggleMapWindow | `_sender: MyGUI::Widget` | `void` | `obj:toggleMapWindow(_sender)` |
| toggleFactionWindow | `_sender: MyGUI::Widget` | `void` | `obj:toggleFactionWindow(_sender)` |
| toggleTechWindow | `_sender: MyGUI::Widget` | `void` | `obj:toggleTechWindow(_sender)` |
| toggleCraftWindow | `_sender: MyGUI::Widget` | `void` | `obj:toggleCraftWindow(_sender)` |
| toggleSquadWindow | `_sender: MyGUI::Widget` | `void` | `obj:toggleSquadWindow(_sender)` |
| changeFloorButtonUp | `_sender: MyGUI::Widget` | `void` | `obj:changeFloorButtonUp(_sender)` |
| changeFloorButtonDown | `_sender: MyGUI::Widget` | `void` | `obj:changeFloorButtonDown(_sender)` |
| ordersPanelFill | `c: hand` | `void` | `obj:ordersPanelFill(c)` |
| getBuildingInventoryPosition | `` | `void` | `obj:getBuildingInventoryPosition()` |
| getTabPlatoonPortrait [1] | `tabIndex: integer` | `MainTabPortraitPlatoon` | `obj:getTabPlatoonPortrait(tabIndex)` |
| getTabPlatoonPortrait [2] | `platoon: ActivePlatoon` | `MainTabPortraitPlatoon` | `obj:getTabPlatoonPortrait(platoon)` |
| extendInfoPanel | `_sender: MyGUI::Widget, _a2: integer, _a3: integer, arg4: integer` | `void` | `obj:extendInfoPanel(_sender, _a2, _a3, arg4)` |
| toggleInventory | `_sender: MyGUI::Widget` | `void` | `obj:toggleInventory(_sender)` |
| toggleStatsWindow | `_sender: MyGUI::Widget` | `void` | `obj:toggleStatsWindow(_sender)` |
| toggleHelpWindow | `_a1: MyGUI::Widget` | `void` | `obj:toggleHelpWindow(_a1)` |
| changeSpeed | `_sender: MyGUI::Widget` | `void` | `obj:changeSpeed(_sender)` |
| buildButton | `_sender: MyGUI::Widget` | `void` | `obj:buildButton(_sender)` |

## MainTabPortraitPlatoon
**Header:** `extern/KenshiLib/Include/kenshi/gui/MainBarGUI.h`
**Metatable:** `KenshiLua.MainTabPortraitPlatoon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| portraitBox | `lightuserdata` | R | `obj.portraitBox` |
| platoon | `ActivePlatoon` | RW | `obj.platoon = <value>` |
| tab | `MyGUI::Widget` | RW | `obj.tab = <value>` |
| tabIndex | `integer` | RW | `obj.tabIndex = <value>` |
| flashImage | `MyGUI::Widget` | R | `obj.flashImage` |
| flashing | `integer` | RW | `obj.flashing = <value>` |
| animationTime | `number` | RW | `obj.animationTime = <value>` |
| currentAlpha | `number` | RW | `obj.currentAlpha = <value>` |
| mainbar | `MainBarGUI` | RW | `obj.mainbar = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addTab | `tabControl: MyGUI::Widget, visible: boolean` | `void` | `obj:addTab(tabControl, visible)` |
| detach | `` | `void` | `obj:detach()` |
| setFlash | `flash: boolean` | `void` | `obj:setFlash(flash)` |
| update | `` | `void` | `obj:update()` |

## MainthreadStateReaderT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.MainthreadStateReaderT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| swapMutex | `unknown` | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateBackDataCheck | `` | `boolean` | `obj:updateBackDataCheck()` |
| getMainData | `` | `void` | `obj:getMainData()` |
| getBackData | `` | `void` | `obj:getBackData()` |

## ManagementScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`
**Metatable:** `KenshiLua.ManagementScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| squadScreen | `SquadManagementScreen` | RW | `obj.squadScreen = <value>` |
| mapScreen | `MapScreen` | RW | `obj.mapScreen = <value>` |
| currentCategoryList | `lektor<GameData*>` | R | `obj.currentCategoryList` |
| factionScreen | `FactionsScreen` | RW | `obj.factionScreen = <value>` |
| researchCategoriesListBox | `MyGUI::Widget` | RW | `obj.researchCategoriesListBox = <value>` |
| availableList | `DatapanelGUI` | RW | `obj.availableList = <value>` |
| info | `DatapanelGUI` | RW | `obj.info = <value>` |
| info2 | `DatapanelGUI` | RW | `obj.info2 = <value>` |
| techCategory | `string` | RW | `obj.techCategory = <value>` |
| currentResearch | `GameData` | RW | `obj.currentResearch = <value>` |
| researchBenchMessage | `MyGUI::Widget` | RW | `obj.researchBenchMessage = <value>` |
| researchDescriptionUpdateRequest | `boolean` | RW | `obj.researchDescriptionUpdateRequest = <value>` |
| lastResearchRate | `number` | RW | `obj.lastResearchRate = <value>` |
| todoList | `lightuserdata` | R | `obj.todoList` |
| craftingQueue | `lightuserdata` | R | `obj.craftingQueue` |
| messagesTextBox | `MyGUI::Widget` | RW | `obj.messagesTextBox = <value>` |
| messagesUpdated | `boolean` | RW | `obj.messagesUpdated = <value>` |
| messagesMutex | `lightuserdata` | R | `obj.messagesMutex` |
| messagesPlayerColor | `string` | RW | `obj.messagesPlayerColor = <value>` |
| messagesNPCColor | `string` | RW | `obj.messagesNPCColor = <value>` |
| aiScreen | `DatapanelGUI` | RW | `obj.aiScreen = <value>` |
| aiToolTip | `ToolTip` | RW | `obj.aiToolTip = <value>` |
| toolTip | `ToolTip` | RW | `obj.toolTip = <value>` |
| window | `MyGUI::Widget` | RW | `obj.window = <value>` |
| tabs | `MyGUI::Widget` | RW | `obj.tabs = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| clear | `` | `void` | `obj:clear()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `on: boolean, tab: integer` | `void` | `obj:setVisible(on, tab)` |
| getCurrentTab | `` | `integer` | `obj:getCurrentTab()` |
| getTab | `index: integer` | `MyGUI::Widget` | `obj:getTab(index)` |
| getWidget | `name: string` | `MyGUI::Widget` | `obj:getWidget(name)` |
| refresh | `current: GameData, progress: number` | `void` | `obj:refresh(current, progress)` |
| refreshResearchList | `` | `void` | `obj:refreshResearchList()` |
| refreshResearchRate | `` | `void` | `obj:refreshResearchRate()` |
| refreshDiplomacy | `` | `void` | `obj:refreshDiplomacy()` |
| refreshSquads | `` | `void` | `obj:refreshSquads()` |
| refreshMap | `centerCamera: boolean` | `void` | `obj:refreshMap(centerCamera)` |
| showRoads | `v: boolean` | `void` | `obj:showRoads(v)` |
| addSquadToMap | `squad: Platoon` | `void` | `obj:addSquadToMap(squad)` |
| removeSquadFromMap | `squad: Platoon` | `void` | `obj:removeSquadFromMap(squad)` |
| resetSquads | `` | `void` | `obj:resetSquads()` |
| refreshMessages | `` | `void` | `obj:refreshMessages()` |
| refreshAI | `` | `void` | `obj:refreshAI()` |
| showDebugMarker | `p: Vector3` | `void` | `obj:showDebugMarker(p)` |
| setCraftingBench | `h: hand` | `void` | `obj:setCraftingBench(h)` |
| addMessage | `owner: string, message: string, isPlayer: MessageLogColor` | `void` | `obj:addMessage(owner, message, isPlayer)` |
| updateResearchListRate | `` | `void` | `obj:updateResearchListRate()` |
| refreshResearchListDescription | `` | `void` | `obj:refreshResearchListDescription()` |
| closeEverythingButton | `widget: MyGUI::Window, name: string` | `void` | `obj:closeEverythingButton(widget, name)` |
| tabCallback | `sender: MyGUI::TabControl, index: integer` | `void` | `obj:tabCallback(sender, index)` |
| researchTypeSelect | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:researchTypeSelect(sender, index)` |
| addButtonPress | `sender: MyGUI::Widget, a2: integer, a3: integer, a4: integer` | `void` | `obj:addButtonPress(sender, a2, a3, a4)` |
| removeButtonPress | `sender: MyGUI::Widget, a2: integer, a3: integer, a4: integer` | `void` | `obj:removeButtonPress(sender, a2, a3, a4)` |
| mouseOverCallback | `sender: MyGUI::Widget, a2: integer, a3: integer` | `void` | `obj:mouseOverCallback(sender, a2, a3)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| printResearch | `` | `void` | `ManagementScreen.printResearch()`<br>`obj:printResearch()` |
| getSingleton | `` | `ManagementScreen` | `ManagementScreen.getSingleton()`<br>`obj:getSingleton()` |

## ManagementScreen::TechItemViewData
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`
**Parent Class:** [`ManagementScreen`](#managementscreen)
**Metatable:** `KenshiLua.ManagementScreen_TechItemViewData`

## MapScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`
**Metatable:** `KenshiLua.MapScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| updateTimer | `number` | RW | `obj.updateTimer = <value>` |
| toolTip | `ToolTip` | RW | `obj.toolTip = <value>` |
| mainWidget | `MyGUI::Widget` | RW | `obj.mainWidget = <value>` |
| mapScrollView | `MyGUI::Widget` | RW | `obj.mapScrollView = <value>` |
| mapImage | `MyGUI::Widget` | RW | `obj.mapImage = <value>` |
| cameraMarker | `MyGUI::Widget` | RW | `obj.cameraMarker = <value>` |
| cameraMarkerSkin | `lightuserdata` | R | `obj.cameraMarkerSkin` |
| zoomUpdated | `boolean` | RW | `obj.zoomUpdated = <value>` |
| zoomValueBase | `number` | RW | `obj.zoomValueBase = <value>` |
| zoomValueMax | `number` | RW | `obj.zoomValueMax = <value>` |
| zoomValueCurrent | `number` | RW | `obj.zoomValueCurrent = <value>` |
| zoomLevelCurrent | `MapZoomLevel` | RW | `obj.zoomLevelCurrent = <value>` |
| mapOverlaysContainer | `MyGUI::Widget` | RW | `obj.mapOverlaysContainer = <value>` |
| zoomLevels | `number` | RW | `obj.zoomLevels = <value>` |
| mapMarkerMovement | `MyGUI::Widget` | RW | `obj.mapMarkerMovement = <value>` |
| mapMarkerMovementPosition | `Vector3` | RW | `obj.mapMarkerMovementPosition = <value>` |
| mapMarkerMovementFadeOutDelay | `number` | RW | `obj.mapMarkerMovementFadeOutDelay = <value>` |
| mapDragging | `boolean` | RW | `obj.mapDragging = <value>` |
| mapMouseLastPosition | `Vector2` | RW | `obj.mapMouseLastPosition = <value>` |
| mapOffsetView | `Vector2` | RW | `obj.mapOffsetView = <value>` |
| worldSize | `Vector2` | RW | `obj.worldSize = <value>` |
| zoomCenterOffset | `Vector4` | RW | `obj.zoomCenterOffset = <value>` |
| worldBounds | `Vector4` | RW | `obj.worldBounds = <value>` |
| mapMarkersTowns | `MapMarkersTownsMapBinding::MapType` | RW | `obj.mapMarkersTowns = <value>` |
| mapMarkersCharacters | `MapMarkersCharactersMapBinding::MapType` | RW | `obj.mapMarkersCharacters = <value>` |
| squadsList | `SquadsListSetBinding::SetType` | RW | `obj.squadsList = <value>` |
| mapMarkersTownsNew | `Ogre::FastArray<hand>` | RW | `obj.mapMarkersTownsNew = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| centerCamera | `` | `void` | `obj:centerCamera()` |
| clearTempMarkers | `` | `void` | `obj:clearTempMarkers()` |
| refresh | `` | `void` | `obj:refresh()` |
| update [1] | `mapPosition: MyGUI::types::TPoint<int>, zoom: MapZoomLevel` | `void` | `obj:update(mapPosition, zoom)` |
| update [2] | `mapPosition: MyGUI::types::TPoint<int>` | `void` | `obj:update(mapPosition)` |
| update [3] | `` | `void` | `obj:update()` |
| addSquad | `squad: Platoon` | `void` | `obj:addSquad(squad)` |
| removeSquad | `squad: Platoon` | `void` | `obj:removeSquad(squad)` |
| hide | `` | `void` | `obj:hide()` |
| setMovementMarker | `p: Vector3, time: number` | `void` | `obj:setMovementMarker(p, time)` |
| showRoads | `on: boolean` | `void` | `obj:showRoads(on)` |
| updateZoom | `` | `void` | `obj:updateZoom()` |
| updateCameraMarker | `` | `void` | `obj:updateCameraMarker()` |
| refreshTowns | `` | `void` | `obj:refreshTowns()` |
| refreshSquads | `` | `void` | `obj:refreshSquads()` |
| updateCharacterMarker | `object: RootObjectBase` | `void` | `obj:updateCharacterMarker(object)` |
| getMouseWorldPosition | `position: Vector3` | `boolean` | `obj:getMouseWorldPosition(position)` |
| setupRoads | `` | `void` | `obj:setupRoads()` |
| updateRoads | `` | `void` | `obj:updateRoads()` |
| updatePlayerTownMapMarker | `town: hand` | `void` | `obj:updatePlayerTownMapMarker(town)` |
| worldToMapCoords | `pos: Vector3` | `void` | `obj:worldToMapCoords(pos)` |
| mapCoordsToWorld | `left: integer, top: integer` | `Vector3` | `obj:mapCoordsToWorld(left, top)` |
| mapMouseWheel | `sender: MyGUI::Widget, rel: integer` | `void` | `obj:mapMouseWheel(sender, rel)` |
| mapMousePressed | `sender: MyGUI::Widget, left: integer, top: integer, id: integer` | `void` | `obj:mapMousePressed(sender, left, top, id)` |
| mapMouseReleased | `sender: MyGUI::Widget, left: integer, top: integer, id: integer` | `void` | `obj:mapMouseReleased(sender, left, top, id)` |
| centerButton | `sender: MyGUI::Widget` | `void` | `obj:centerButton(sender)` |
| zoomInButton | `sender: MyGUI::Widget` | `void` | `obj:zoomInButton(sender)` |
| zoomOutButton | `sender: MyGUI::Widget` | `void` | `obj:zoomOutButton(sender)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getMarkerColor | `` | `MyGUI::Colour` | `MapScreen.getMarkerColor()`<br>`obj:getMarkerColor()` |

## MapScreen::MapMarkerCharacter
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`
**Parent Class:** [`MapScreen`](#mapscreen)
**Metatable:** `KenshiLua.MapMarkerCharacter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | `hand` | RW | `obj.handle = <value>` |
| image | `MyGUI::Widget` | R | `obj.image` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |

## MapScreen::MapMarkerTown
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`
**Parent Class:** [`MapScreen`](#mapscreen)
**Metatable:** `KenshiLua.MapMarkerTown`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | `hand` | RW | `obj.handle = <value>` |
| zoomLayer | `MapZoomLevel` | RW | `obj.zoomLayer = <value>` |
| root | `MyGUI::Widget` | R | `obj.root` |
| image | `MyGUI::Widget` | R | `obj.image` |
| label | `MyGUI::Widget` | R | `obj.label` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |

## MapScreen::MapRoad
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`
**Parent Class:** [`MapScreen`](#mapscreen)
**Metatable:** `KenshiLua.MapScreen_MapRoad`

## MedianFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MedianFilter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isPositionsFilter | `boolean` | RW | `obj.isPositionsFilter = <value>` |
| edgeSkips | `integer` | RW | `obj.edgeSkips = <value>` |
| maxLength | `integer` | RW | `obj.maxLength = <value>` |
| mHistoryBufferX | `std::deque<float>` | RW | `obj.mHistoryBufferX = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `numFrames: integer, numSamples: integer, _isPositionsFilter: boolean` | `void` | `obj:setup(numFrames, numSamples, _isPositionsFilter)` |
| reset | `` | `void` | `obj:reset()` |
| applySilent | `delta_mouse_x: number` | `void` | `obj:applySilent(delta_mouse_x)` |

## MedianFilter2DVector
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MedianFilter2DVector`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| filters | `unknown` | RW | `obj.filters = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `numFrames: integer, numSamples: integer, positions: boolean` | `void` | `obj:setup(numFrames, numSamples, positions)` |
| reset | `` | `void` | `obj:reset()` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`
**Metatable:** `KenshiLua.MedicalSystem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| status | `ogre_unordered_map<GameData*, HealthPartStatus>` | RW | `obj.status = <value>` |
| armourList | `lektor<Armour*>` | RW | `obj.armourList = <value>` |
| hunger | `number` | RW | `obj.hunger = <value>` |
| fed | `number` | RW | `obj.fed = <value>` |
| lastPeriodicUpdate | `TimeOfDay` | RW | `obj.lastPeriodicUpdate = <value>` |
| blood | `number` | RW | `obj.blood = <value>` |
| extraBloodLossFromBodyparts | `number` | RW | `obj.extraBloodLossFromBodyparts = <value>` |
| currentBleedRate | `number` | RW | `obj.currentBleedRate = <value>` |
| leftLeg | `MedicalSystem::HealthPartStatus` | RW | `obj.leftLeg = <value>` |
| rightLeg | `MedicalSystem::HealthPartStatus` | RW | `obj.rightLeg = <value>` |
| leftArm | `MedicalSystem::HealthPartStatus` | RW | `obj.leftArm = <value>` |
| rightArm | `MedicalSystem::HealthPartStatus` | RW | `obj.rightArm = <value>` |
| knockoutTimer | `number` | RW | `obj.knockoutTimer = <value>` |
| worstDamage | `number` | RW | `obj.worstDamage = <value>` |
| needsFirstAidScoreTotal_robot | `number` | RW | `obj.needsFirstAidScoreTotal_robot = <value>` |
| needsFirstAidScoreTotal_fleshy | `number` | RW | `obj.needsFirstAidScoreTotal_fleshy = <value>` |
| restedState | `number` | RW | `obj.restedState = <value>` |
| stealthHinderance | `number` | RW | `obj.stealthHinderance = <value>` |
| partBestArm | `number` | RW | `obj.partBestArm = <value>` |
| partHead | `number` | RW | `obj.partHead = <value>` |
| partWorstTorso | `number` | RW | `obj.partWorstTorso = <value>` |
| dazedOrAlert | `number` | RW | `obj.dazedOrAlert = <value>` |
| robotLimbs | `RobotLimbs` | RW | `obj.robotLimbs = <value>` |
| bloodynessChanged | `boolean` | RW | `obj.bloodynessChanged = <value>` |
| bloodynessCleanedUp | `boolean` | RW | `obj.bloodynessCleanedUp = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| weatherGUIfeedback | `StringPair` | RW | `obj.weatherGUIfeedback = <value>` |
| currentWeatherAffect | `WeatherAffecting` | RW | `obj.currentWeatherAffect = <value>` |
| currentWeatherAffectStrength | `number` | RW | `obj.currentWeatherAffectStrength = <value>` |
| lastHungerKO | `TimeOfDay` | RW | `obj.lastHungerKO = <value>` |
| nextKOTime | `number` | RW | `obj.nextKOTime = <value>` |
| _eatenDeathDelay | `integer` | RW | `obj._eatenDeathDelay = <value>` |
| crippled | `boolean` | RW | `obj.crippled = <value>` |
| unconcious | `boolean` | RW | `obj.unconcious = <value>` |
| sub50KO | `boolean` | RW | `obj.sub50KO = <value>` |
| bloodlossTrauma | `boolean` | RW | `obj.bloodlossTrauma = <value>` |
| dead | `boolean` | RW | `obj.dead = <value>` |
| rightArmOk | `boolean` | RW | `obj.rightArmOk = <value>` |
| leftArmOk | `boolean` | RW | `obj.leftArmOk = <value>` |
| lastBloodPosition | `Vector3` | RW | `obj.lastBloodPosition = <value>` |
| anatomy | `lektor<MedicalSystem::HealthPartStatus*>` | RW | `obj.anatomy = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| wounds | `Ogre::FastArray<Wound*>` | RW | `obj.wounds = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| precalculateFirstAidNeedScore | `` | `void` | `obj:precalculateFirstAidNeedScore()` |
| scoreFirstAidNeed | `robotAid: boolean` | `number` | `obj:scoreFirstAidNeed(robotAid)` |
| scoreJuryRigNeed | `skills: number` | `number` | `obj:scoreJuryRigNeed(skills)` |
| isFullyRested | `` | `boolean` | `obj:isFullyRested()` |
| validateHealthValues | `` | `void` | `obj:validateHealthValues()` |
| amputate | `limb: RobotLimbs::Limb, createSeveredItem: boolean, force: Vector3` | `void` | `obj:amputate(limb, createSeveredItem, force)` |
| crushLimb | `limb: RobotLimbs::Limb` | `void` | `obj:crushLimb(limb)` |
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
| getLimbState | `limb: RobotLimbs::Limb` | `void` | `obj:getLimbState(limb)` |
| getPart [1] | `what: RobotLimbs::Limb` | `MedicalSystem::HealthPartStatus` | `obj:getPart(what)` |
| getPart [2] | `index: integer` | `MedicalSystem::HealthPartStatus` | `obj:getPart(index)` |
| getPart [3] | `partType: MedicalSystem::HealthPartStatus::PartType, leftSide: LeftRight` | `MedicalSystem::HealthPartStatus` | `obj:getPart(partType, leftSide)` |
| addArmour | `` | `void` | `obj:addArmour()` |
| removeArmour | `` | `void` | `obj:removeArmour()` |
| wearingUniformOf | `` | `void` | `obj:wearingUniformOf()` |
| applyFirstAid | `` | `void` | `obj:applyFirstAid()` |
| applyDoctoring | `` | `void` | `obj:applyDoctoring()` |
| applyRigging | `` | `void` | `obj:applyRigging()` |

## MedicalSystem::HealthPartStatus
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`
**Parent Class:** [`MedicalSystem`](#medicalsystem)
**Metatable:** `KenshiLua.MedicalSystem_HealthPartStatus`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `GameData` | RW | `obj.data = <value>` |
| whatAmI | `MedicalSystem::HealthPartStatus::PartType` | RW | `obj.whatAmI = <value>` |
| medical | `MedicalSystem` | RW | `obj.medical = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| side | `LeftRight` | RW | `obj.side = <value>` |
| robotLimb | `RobotLimbItem` | RW | `obj.robotLimb = <value>` |
| selfHealing | `boolean` | RW | `obj.selfHealing = <value>` |
| collapses | `boolean` | RW | `obj.collapses = <value>` |
| fatal | `boolean` | RW | `obj.fatal = <value>` |
| KOMult | `number` | RW | `obj.KOMult = <value>` |
| hitChance | `number` | RW | `obj.hitChance = <value>` |
| hitChanceMult | `number` | RW | `obj.hitChanceMult = <value>` |
| flesh | `number` | RW | `obj.flesh = <value>` |
| fleshStun | `number` | RW | `obj.fleshStun = <value>` |
| bandaging | `number` | RW | `obj.bandaging = <value>` |
| juryRigging | `number` | RW | `obj.juryRigging = <value>` |
| wearDamage | `number` | RW | `obj.wearDamage = <value>` |
| _maxHealth | `number` | RW | `obj._maxHealth = <value>` |
| age | `number` | RW | `obj.age = <value>` |
| HPMult | `number` | RW | `obj.HPMult = <value>` |
| derivedFleshHealthPercent | `number` | RW | `obj.derivedFleshHealthPercent = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| serialise | `out: GameData, num: integer` | `void` | `obj:serialise(out, num)` |
| load | `out: GameData, num: integer` | `void` | `obj:load(out, num)` |
| isRobotic | `` | `boolean` | `obj:isRobotic()` |
| getData | `` | `GameData` | `obj:getData()` |
| getRobotLimbEnum | `` | `RobotLimbs::Limb` | `obj:getRobotLimbEnum()` |
| setup | `dat: GameData, _hitchance: number, _max: number, _age: number, med: MedicalSystem, selfHeal: boolean, _me: Character` | `void` | `obj:setup(dat, _hitchance, _max, _age, med, selfHeal, _me)` |
| update | `frameTIME: number, healMultFlesh: number, healMultRobot: number, degenerationRate: number, _age: number, robotWear: number` | `boolean` | `obj:update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear)` |
| updateDerivedHealths | `` | `void` | `obj:updateDerivedHealths()` |
| getWorstDamage | `brokenBoneValue: number` | `number` | `obj:getWorstDamage(brokenBoneValue)` |
| setRobotLimbItem | `_robotLimb: RobotLimbItem, isLoadingASave: boolean` | `void` | `obj:setRobotLimbItem(_robotLimb, isLoadingASave)` |
| getExtraBleedingAmount | `` | `number` | `obj:getExtraBleedingAmount()` |
| isDead | `` | `boolean` | `obj:isDead()` |
| getBloodynessMult | `` | `number` | `obj:getBloodynessMult()` |
| maxHealth | `` | `number` | `obj:maxHealth()` |
| healthAsPercent | `healt: number` | `number` | `obj:healthAsPercent(healt)` |

## MeshDataLookup
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Metatable:** `KenshiLua.MeshDataLookup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| verts | `lightuserdata` | RW | `obj.verts = <value>` |
| uvs | `lightuserdata` | RW | `obj.uvs = <value>` |

## MessageBoxManager
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`
**Metatable:** `KenshiLua.MessageBoxManager`

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| hideMessageBox | `` | `boolean` | `MessageBoxManager.hideMessageBox()`<br>`obj:hideMessageBox()` |
| hasModalMessage | `` | `boolean` | `MessageBoxManager.hasModalMessage()`<br>`obj:hasModalMessage()` |
| removeMessageBox | `` | `void` | `MessageBoxManager.removeMessageBox()`<br>`obj:removeMessageBox()` |

## MessageBoxManager::Box
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`
**Parent Class:** [`MessageBoxManager`](#messageboxmanager)
**Metatable:** `KenshiLua.Box`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| modal | `boolean` | RW | `obj.modal = <value>` |
| callback | `lightuserdata` | R | `obj.callback` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| buttonClick | `sender: MyGUI::Widget` | `void` | `obj:buttonClick(sender)` |

## MessageChain
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`
**Metatable:** `KenshiLua.MessageChain`

## MessageForB
**Header:** `extern/KenshiLib/Include/kenshi/Enums.h`
**Metatable:** `KenshiLua.MessageForB`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| messageType | `MessageForB::MessageType` | RW | `obj.messageType = <value>` |
| messageInt | `integer` | RW | `obj.messageInt = <value>` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| new | `` | `MessageForB` | `MessageForB.new()`<br>`obj:new()` |

## MessageQueue
**Header:** `extern/KenshiLib/Include/kenshi/navmesh.h`
**Metatable:** `KenshiLua.MessageQueue`

## MessageQueue::Node
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`
**Parent Class:** [`MessageQueue`](#messagequeue)
**Metatable:** `KenshiLua.MessageQueue_Node`

## ModInfo
**Header:** `extern/KenshiLib/Include/kenshi/ModInfo.h`
**Metatable:** `KenshiLua.ModInfo`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |
| file | `string` | RW | `obj.file = <value>` |
| path | `string` | RW | `obj.path = <value>` |
| isWorkshop | `boolean` | RW | `obj.isWorkshop = <value>` |
| isBaseMod | `boolean` | RW | `obj.isBaseMod = <value>` |
| leveldataFolder | `string` | RW | `obj.leveldataFolder = <value>` |
| header | `GameDataHeader` | RW | `obj.header = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: ModInfo` | `void` | `obj:operator_assign(other)` |
| getLocale | `` | `boolean\|string` | `obj:getLocale()` |

## MotionFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MotionFilter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mWeightModifier | `number` | RW | `obj.mWeightModifier = <value>` |
| mHistoryBufferX | `std::deque<float>` | RW | `obj.mHistoryBufferX = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| SetHistoryBufferLength | `length: integer, fill: number` | `boolean` | `obj:SetHistoryBufferLength(length, fill)` |

## MultiSlider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_MultiSlider.h`
**Metatable:** `KenshiLua.MultiSlider`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mName | `MyGUI::Widget` | R | `obj.mName` |
| mDisableEvents | `boolean` | RW | `obj.mDisableEvents = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | `` | `void` | `obj:shutdownOverride()` |
| getTypeName | `` | `void` | `obj:getTypeName()` |

## MustEndWithSemiColon
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MustEndWithSemiColon`

## NavInstance
**Header:** `extern/KenshiLib/Include/kenshi/NavInstance.h`
**Metatable:** `KenshiLua.NavInstance`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mesh | `lightuserdata` | RW | `obj.mesh = <value>` |
| graph | `lightuserdata` | RW | `obj.graph = <value>` |
| graphInstance | `lightuserdata` | RW | `obj.graphInstance = <value>` |
| mediator | `lightuserdata` | RW | `obj.mediator = <value>` |
| instance | `lightuserdata` | RW | `obj.instance = <value>` |
| offset | `Vector3` | RW | `obj.offset = <value>` |

## NavMesh
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`
**Metatable:** `KenshiLua.NavMesh`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| world | `lightuserdata` | RW | `obj.world = <value>` |
| shiftMutex | `lightuserdata` | R | `obj.shiftMutex` |
| worldShiftEnabled | `boolean` | RW | `obj.worldShiftEnabled = <value>` |
| running | `boolean` | RW | `obj.running = <value>` |
| worldX | `number` | RW | `obj.worldX = <value>` |
| worldY | `number` | RW | `obj.worldY = <value>` |
| cellSize | `number` | RW | `obj.cellSize = <value>` |
| worldShift | `lightuserdata` | RW | `obj.worldShift = <value>` |
| mutex | `lightuserdata` | R | `obj.mutex` |
| changeMutex | `lightuserdata` | R | `obj.changeMutex` |
| edgeFilter | `lightuserdata` | R | `obj.edgeFilter` |
| generator | `NavMeshGenerator` | R | `obj.generator` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| initialise | `` | `void` | `obj:initialise()` |
| shutdown | `` | `void` | `obj:shutdown()` |
| create | `zone: ZoneMap` | `void` | `obj:create(zone)` |
| unload | `zone: ZoneMap` | `void` | `obj:unload(zone)` |
| destroy | `b: Building` | `void` | `obj:destroy(b)` |
| getZoneEdge | `start: Vector3, target: Vector3, offset: number` | `Vector3` | `obj:getZoneEdge(start, target, offset)` |
| getClosestExteriorPoint | `point: Vector3, radius: number, inset: number, out: Vector3` | `integer` | `obj:getClosestExteriorPoint(point, radius, inset, out)` |
| setDoorState | `door: Building, open: boolean` | `void` | `obj:setDoorState(door, open)` |
| isInterior | `key: integer` | `boolean` | `obj:isInterior(key)` |
| getHandle | `key: integer` | `hand` | `obj:getHandle(key)` |
| getPositionValid | `point: Vector3` | `boolean` | `obj:getPositionValid(point)` |
| processCompletedCharacterMessages | `` | `void` | `obj:processCompletedCharacterMessages()` |
| processDoorRequests | `` | `void` | `obj:processDoorRequests()` |
| getPolygonID | `p: Vector3` | `string` | `obj:getPolygonID(p)` |
| validateFaceKey | `key: integer` | `boolean` | `obj:validateFaceKey(key)` |
| isGenerating | `` | `boolean` | `obj:isGenerating()` |
| getWorldShift | `` | `Vector3` | `obj:getWorldShift()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| update | `` | `boolean` | `obj:update()` |
| setupHavok | `` | `void` | `obj:setupHavok()` |
| shutdownHavok | `` | `void` | `obj:shutdownHavok()` |
| loadZone | `` | `void` | `obj:loadZone()` |
| unloadZone | `` | `void` | `obj:unloadZone()` |
| unloadBuilding | `h: hand` | `void` | `obj:unloadBuilding(h)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getUID [1] | `building: hand` | `integer` | `NavMesh.getUID(building)`<br>`obj:getUID(building)` |
| getUID [2] | `zone: iVector2` | `integer` | `NavMesh.getUID(zone)`<br>`obj:getUID(zone)` |
| hashBuilding | `` | `integer` | `NavMesh.hashBuilding()`<br>`obj:hashBuilding()` |
| hashInterior | `` | `integer` | `NavMesh.hashInterior()`<br>`obj:hashInterior()` |
| hashZone | `` | `integer` | `NavMesh.hashZone()`<br>`obj:hashZone()` |
| getFilename | `` | `string` | `NavMesh.getFilename()`<br>`obj:getFilename()` |

## NavMesh::BuildingInfo
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`
**Parent Class:** [`NavMesh`](#navmesh)
**Metatable:** `KenshiLua.NavMesh_BuildingInfo`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## NavMesh::NavMeshMessage
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`
**Parent Class:** [`NavMesh`](#navmesh)
**Metatable:** `KenshiLua.NavMesh_NavMeshMessage`

## NavMeshGenerator
**Header:** `extern/KenshiLib/Include/kenshi/NavMeshGenerator.h`
**Metatable:** `KenshiLua.NavMeshGenerator`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| queue | `lightuserdata` | R | `obj.queue` |
| done | `lightuserdata` | R | `obj.done` |
| current | `lightuserdata` | R | `obj.current` |
| navmesh | `lightuserdata` | R | `obj.navmesh` |
| needSave | `boolean` | RW | `obj.needSave = <value>` |
| settings | `lightuserdata` | R | `obj.settings` |
| threadRunning | `boolean` | RW | `obj.threadRunning = <value>` |
| doingStuff | `boolean` | RW | `obj.doingStuff = <value>` |
| taskMutex | `lightuserdata` | R | `obj.taskMutex` |
| lockedTask | `lightuserdata` | R | `obj.lockedTask` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isGenerating | `` | `boolean` | `obj:isGenerating()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| updateBT | `` | `boolean` | `obj:updateBT()` |
| generateTaskBT | `task: userdata` | `void` | `obj:generateTaskBT(task)` |
| validateBuildingStates | `task: userdata` | `integer` | `obj:validateBuildingStates(task)` |
| carve | `task: userdata` | `integer` | `obj:carve(task)` |
| splice | `t: userdata` | `integer` | `obj:splice(t)` |
| stitchInterior | `t: userdata` | `integer` | `obj:stitchInterior(t)` |
| stitchExterior | `t: userdata` | `integer` | `obj:stitchExterior(t)` |
| revertSettings | `` | `void` | `obj:revertSettings()` |
| unlockTask | `task: userdata` | `void` | `obj:unlockTask(task)` |
| hasJob | `zone: ZoneMap` | `boolean` | `obj:hasJob(zone)` |
| update | `` | `void` | `obj:update()` |

## NavMeshGenerator::Task
**Header:** `extern/KenshiLib/Include/kenshi/NavMeshGenerator.h`
**Parent Class:** [`NavMeshGenerator`](#navmeshgenerator)
**Metatable:** `KenshiLua.NavMeshGenerator_Task`

## NavMeshGenerator::TaskQueue
**Header:** `extern/KenshiLib/Include/kenshi/NavMeshGenerator.h`
**Parent Class:** [`NavMeshGenerator`](#navmeshgenerator)
**Metatable:** `KenshiLua.NavMeshGenerator_TaskQueue`

## NavMeshSeeds
**Header:** `extern/KenshiLib/Include/kenshi/NavMeshGenerator.h`
**Metatable:** `KenshiLua.NavMeshSeeds`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| load | `` | `void` | `obj:load()` |
| save | `` | `void` | `obj:save()` |
| addSeedPoint | `p: Vector3, terrain: boolean` | `void` | `obj:addSeedPoint(p, terrain)` |
| removeSeedPoints | `pos: Vector3, radius: number` | `integer` | `obj:removeSeedPoints(pos, radius)` |
| clearSeedPoints | `zone: ZoneMap` | `integer` | `obj:clearSeedPoints(zone)` |
| removeIsland | `pos: Vector3, radius: number` | `integer` | `obj:removeIsland(pos, radius)` |
| projectToTerrain | `zone: ZoneMap` | `void` | `obj:projectToTerrain(zone)` |
| getSeedPoints | `zone: ZoneMap` | `lightuserdata` | `obj:getSeedPoints(zone)` |

## NewGameOptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameOptionsWindow.h`
**Metatable:** `KenshiLua.NewGameOptionsWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| optionsPanel | `DatapanelGUI` | RW | `obj.optionsPanel = <value>` |
| tooltip | `ToolTip` | RW | `obj.tooltip = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| update | `` | `void` | `obj:update()` |

## NewGameWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameWindow.h`
**Metatable:** `KenshiLua.NewGameWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentStart | `integer` | RW | `obj.currentStart = <value>` |
| startInfo | `DatapanelGUI` | RW | `obj.startInfo = <value>` |
| startNameTextBox | `MyGUI::Widget` | R | `obj.startNameTextBox` |
| newGameOptions | `NewGameOptionsWindow` | RW | `obj.newGameOptions = <value>` |
| startsData | `Ogre::FastArray<GameData*>` | RW | `obj.startsData = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setRealPosition | `x: number, y: number` | `void` | `obj:setRealPosition(x, y)` |
| setPosition | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| show | `_a1: boolean` | `void` | `obj:show(_a1)` |
| update | `` | `void` | `obj:update()` |
| loadData | `` | `void` | `obj:loadData()` |
| updateCurrentData | `` | `void` | `obj:updateCurrentData()` |
| showWindow | `sender: MyGUI::Widget` | `void` | `obj:showWindow(sender)` |
| close | `sender: MyGUI::Widget` | `void` | `obj:close(sender)` |
| prevStart | `sender: MyGUI::Widget` | `void` | `obj:prevStart(sender)` |
| nextStart | `sender: MyGUI::Widget` | `void` | `obj:nextStart(sender)` |
| newGameStart | `a1: MyGUI::Widget` | `void` | `obj:newGameStart(a1)` |
| toggleAdvancedOptions | `sender: MyGUI::Widget` | `void` | `obj:toggleAdvancedOptions(sender)` |

## Nx9Real
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.Nx9Real`

## Nx9Real::S
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Parent Class:** [`Nx9Real`](#nx9real)
**Metatable:** `KenshiLua.Nx9Real_S`

## NxBox
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.NxBox`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: NxBox` | `void` | `obj:operator_assign(other)` |

## NxMat33
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.NxMat33`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setRowMajor | `d: userdata` | `void` | `obj:setRowMajor(d)` |
| getRowMajor | `d: userdata` | `void` | `obj:getRowMajor(d)` |
| getColumnMajor | `d: userdata` | `void` | `obj:getColumnMajor(d)` |
| setRowMajorStride4 | `d: userdata` | `void` | `obj:setRowMajorStride4(d)` |
| getRowMajorStride4 | `d: userdata` | `void` | `obj:getRowMajorStride4(d)` |
| getColumnMajorStride4 | `d: userdata` | `void` | `obj:getColumnMajorStride4(d)` |
| isFinite | `` | `boolean` | `obj:isFinite()` |
| zero | `` | `void` | `obj:zero()` |
| id | `` | `void` | `obj:id()` |
| setColumn | `col: integer, v: NxVec3` | `void` | `obj:setColumn(col, v)` |
| getRow | `row: integer` | `NxVec3` | `obj:getRow(row)` |
| getColumn [1] | `col: integer` | `NxVec3` | `obj:getColumn(col)` |
| getColumn [2] | `col: integer, v: NxVec3` | `void` | `obj:getColumn(col, v)` |
| multiply [1] | `left: NxMat33, right: NxMat33` | `void` | `obj:multiply(left, right)` |
| multiply [2] | `src: NxVec3, dst: NxVec3` | `void` | `obj:multiply(src, dst)` |
| get | `row: integer, col: integer` | `number` | `obj:get(row, col)` |
| set | `row: integer, col: integer, val: number` | `void` | `obj:set(row, col, val)` |
| operator_mul | `v: NxVec3` | `NxVec3` | `obj:operator_mul(v)` |
| operator_assign | `other: NxMat33` | `void` | `obj:operator_assign(other)` |
| operator_mul_assign | `other: NxMat33` | `void` | `obj:operator_mul_assign(other)` |
| operator_call [1] | `val: number` | `void` | `obj:operator_call(val)` |
| operator_call [2] | `row: integer, col: integer, val: number` | `number` | `obj:operator_call(row, col, val)` |

### Constructors
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| NxMat33 | `[other: NxMat33]` | `NxMat33` | `local m = NxMat33()` |

## NxUserControllerHitReport
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.NxUserControllerHitReport`

## NxUserTriggerReport
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.NxUserTriggerReport`

## NxVec3
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.NxVec3`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | `number` | RW | `obj.x = <value>` |
| y | `number` | RW | `obj.y = <value>` |
| z | `number` | RW | `obj.z = <value>` |

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
| dot | `` | `number` | `obj:dot()` |
| equals | `epsilon: number` | `boolean` | `obj:equals(epsilon)` |
| multiplyAdd | `s: number` | `void` | `obj:multiplyAdd(s)` |
| add | `` | `void` | `obj:add()` |
| subtract | `` | `void` | `obj:subtract()` |
| cross | `` | `NxVec3` | `obj:cross()` |
| set [1] | `_x: number, _y: number, _z: number` | `void` | `obj:set(_x, _y, _z)` |
| set [2] | `v: number` | `void` | `obj:set(v)` |
| operator_assign | `` | `void` | `obj:operator_assign()` |
| operator_subscript [1] | `val: number` | `void` | `obj:operator_subscript(val)` |
| operator_subscript [2] | `` | `number` | `obj:operator_subscript()` |
| operator_eq | `b: NxVec3` | `boolean` | `obj:operator_eq(b)` |
| operator_ne | `` | `boolean` | `obj:operator_ne()` |
| operator_add | `` | `NxVec3` | `obj:operator_add()` |
| operator_sub | `` | `NxVec3` | `obj:operator_sub()` |
| operator_unm | `` | `NxVec3` | `obj:operator_unm()` |
| operator_mul | `s: number` | `NxVec3` | `obj:operator_mul(s)` |
| operator_add_assign | `` | `void` | `obj:operator_add_assign()` |
| operator_sub_assign | `` | `void` | `obj:operator_sub_assign()` |
| operator_mul_assign | `f: number` | `void` | `obj:operator_mul_assign(f)` |
| operator_xor | `` | `NxVec3` | `obj:operator_xor()` |

### Constructors
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| NxVec3 | `[x: number, y: number, z: number]` | `NxVec3` | `local v = NxVec3(1, 2, 3)` |

## OpenSaveFileDialog
**Header:** `extern/KenshiLib/Include/kenshi/gui/OpenSaveFileDialog.h`
**Metatable:** `KenshiLua.OpenSaveFileDialog`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| filesList | `MyGUI::Widget` | R | `obj.filesList` |
| fileNameTxt | `MyGUI::Widget` | R | `obj.fileNameTxt` |
| currentFolderList | `MyGUI::Widget` | R | `obj.currentFolderList` |
| openSaveButton | `MyGUI::Widget` | R | `obj.openSaveButton` |
| currentFolder | `string` | RW | `obj.currentFolder = <value>` |
| fileName | `string` | RW | `obj.fileName = <value>` |
| fileMask | `string` | RW | `obj.fileMask = <value>` |
| currentSelected | `string` | RW | `obj.currentSelected = <value>` |
| folderMode | `boolean` | RW | `obj.folderMode = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setDialogInfo | `_caption: string, _button: string, _folderMode: boolean` | `void` | `obj:setDialogInfo(_caption, _button, _folderMode)` |
| setCurrentFolder | `_folder: string` | `void` | `obj:setCurrentFolder(_folder)` |
| getCurrentFolder | `` | `void` | `obj:getCurrentFolder()` |
| setFileName | `_value: string` | `void` | `obj:setFileName(_value)` |
| getFileName | `` | `void` | `obj:getFileName()` |
| setFileMask | `_value: string` | `void` | `obj:setFileMask(_value)` |
| getFileMask | `` | `void` | `obj:getFileMask()` |
| update | `` | `void` | `obj:update()` |
| accept | `a1: MyGUI::Widget` | `void` | `obj:accept(a1)` |
| cancel | `a1: MyGUI::Widget` | `void` | `obj:cancel(a1)` |
| upFolder | `a1: MyGUI::Widget` | `void` | `obj:upFolder(a1)` |
| notifyDirectoryComboAccept | `sender: MyGUI::ComboBox, index: integer` | `void` | `obj:notifyDirectoryComboAccept(sender, index)` |
| notifyDirectoryComboChangePosition | `sender: MyGUI::ComboBox, index: integer` | `void` | `obj:notifyDirectoryComboChangePosition(sender, index)` |
| notifyListChangePosition | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:notifyListChangePosition(sender, index)` |
| notifyListSelectAccept | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:notifyListSelectAccept(sender, index)` |
| closeWindow | `sender: MyGUI::Window, name: string` | `void` | `obj:closeWindow(sender, name)` |

## OptionsHolder
**Header:** `extern/KenshiLib/Include/kenshi/OptionsHolder.h`
**Metatable:** `KenshiLua.OptionsHolder`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| CAMERA_MOVE_SPEED | `number` | RW | `obj.CAMERA_MOVE_SPEED = <value>` |
| CAMERA_PAN_SPEED | `number` | RW | `obj.CAMERA_PAN_SPEED = <value>` |
| CAMERA_TILT_SPEED | `number` | RW | `obj.CAMERA_TILT_SPEED = <value>` |
| CAMERA_ZOOM_SPEED | `number` | RW | `obj.CAMERA_ZOOM_SPEED = <value>` |
| invertX | `number` | RW | `obj.invertX = <value>` |
| invertY | `number` | RW | `obj.invertY = <value>` |
| VIEW_DISTANCE | `number` | RW | `obj.VIEW_DISTANCE = <value>` |
| terrainDetail | `number` | RW | `obj.terrainDetail = <value>` |
| terrainDistant | `number` | RW | `obj.terrainDistant = <value>` |
| terrainThreshold | `number` | RW | `obj.terrainThreshold = <value>` |
| terrainPatchSize | `integer` | RW | `obj.terrainPatchSize = <value>` |
| grassRange | `number` | RW | `obj.grassRange = <value>` |
| grassDensity | `number` | RW | `obj.grassDensity = <value>` |
| foliageRange | `number` | RW | `obj.foliageRange = <value>` |
| NPCRange | `number` | RW | `obj.NPCRange = <value>` |
| smallBuildingRange | `number` | RW | `obj.smallBuildingRange = <value>` |
| stencilsDisabled | `boolean` | RW | `obj.stencilsDisabled = <value>` |
| fancyShaders | `boolean` | RW | `obj.fancyShaders = <value>` |
| HWmouse | `boolean` | RW | `obj.HWmouse = <value>` |
| tutorials | `boolean` | RW | `obj.tutorials = <value>` |
| _enabledCivilians | `boolean` | RW | `obj._enabledCivilians = <value>` |
| populationMult | `number` | RW | `obj.populationMult = <value>` |
| squadSizeMult | `number` | RW | `obj.squadSizeMult = <value>` |
| raidSizeMult | `number` | RW | `obj.raidSizeMult = <value>` |
| raidFrequencyMult | `number` | RW | `obj.raidFrequencyMult = <value>` |
| passingAttacksOnBase | `integer` | RW | `obj.passingAttacksOnBase = <value>` |
| shadowMode | `integer` | RW | `obj.shadowMode = <value>` |
| shadowQuality | `integer` | RW | `obj.shadowQuality = <value>` |
| harpoonLimit | `number` | RW | `obj.harpoonLimit = <value>` |
| decalRange | `number` | RW | `obj.decalRange = <value>` |
| decalResolution | `integer` | RW | `obj.decalResolution = <value>` |
| characterMultithreading | `boolean` | RW | `obj.characterMultithreading = <value>` |
| limbLossFrequency | `integer` | RW | `obj.limbLossFrequency = <value>` |
| showNames | `boolean` | RW | `obj.showNames = <value>` |
| edgeScrolling | `boolean` | RW | `obj.edgeScrolling = <value>` |
| damageFloaters | `integer` | RW | `obj.damageFloaters = <value>` |
| showRotationMarker | `boolean` | RW | `obj.showRotationMarker = <value>` |
| showMoveMarker | `boolean` | RW | `obj.showMoveMarker = <value>` |
| fontSize | `number` | RW | `obj.fontSize = <value>` |
| manyActiveZones | `boolean` | RW | `obj.manyActiveZones = <value>` |
| distantTownRange | `number` | RW | `obj.distantTownRange = <value>` |
| featureRange | `number` | RW | `obj.featureRange = <value>` |
| generateDistantTowns | `boolean` | RW | `obj.generateDistantTowns = <value>` |
| shadowRange | `number` | RW | `obj.shadowRange = <value>` |
| ddsTextureMipMapGimping | `integer` | RW | `obj.ddsTextureMipMapGimping = <value>` |
| reflectionMode | `integer` | RW | `obj.reflectionMode = <value>` |
| reflectionDistance | `number` | RW | `obj.reflectionDistance = <value>` |
| compositors | `lektor<std::pair<std::string, bool> >` | R | `obj.compositors` |
| musicVolume | `number` | RW | `obj.musicVolume = <value>` |
| ambientVolume | `number` | RW | `obj.ambientVolume = <value>` |
| footstepVolume | `number` | RW | `obj.footstepVolume = <value>` |
| sfxVolume | `number` | RW | `obj.sfxVolume = <value>` |
| uiVolume | `number` | RW | `obj.uiVolume = <value>` |
| voVolume | `number` | RW | `obj.voVolume = <value>` |
| musicFrequency | `number` | RW | `obj.musicFrequency = <value>` |
| autosavetime | `number` | RW | `obj.autosavetime = <value>` |
| fullscreen | `boolean` | RW | `obj.fullscreen = <value>` |
| borderless | `boolean` | RW | `obj.borderless = <value>` |
| autosave | `boolean` | RW | `obj.autosave = <value>` |
| userSaves | `boolean` | RW | `obj.userSaves = <value>` |
| blood | `boolean` | RW | `obj.blood = <value>` |
| censorship | `boolean` | RW | `obj.censorship = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| enabledCivilians | `` | `boolean` | `obj:enabledCivilians()` |
| characterMultithreadingEnabled | `` | `boolean` | `obj:characterMultithreadingEnabled()` |
| compositiorEnabled | `name: string` | `boolean` | `obj:compositiorEnabled(name)` |
| loadCompositorSettings | `` | `void` | `obj:loadCompositorSettings()` |

## OptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/OptionsWindow.h`
**Metatable:** `KenshiLua.OptionsWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| resolutions | `lektor<std::string>` | R | `obj.resolutions` |
| invertX | `boolean` | RW | `obj.invertX = <value>` |
| invertY | `boolean` | RW | `obj.invertY = <value>` |
| resolutionIndex | `integer` | RW | `obj.resolutionIndex = <value>` |
| keyConfig | `DataPanelLine_KeyConfig` | RW | `obj.keyConfig = <value>` |
| keysDatapanel | `DatapanelGUI` | RW | `obj.keysDatapanel = <value>` |
| tabs | `MyGUI::Widget` | R | `obj.tabs` |
| created | `boolean` | RW | `obj.created = <value>` |
| tooltip | `ToolTip` | RW | `obj.tooltip = <value>` |
| previewFontSize | `boolean` | RW | `obj.previewFontSize = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| show | `value: boolean` | `void` | `obj:show(value)` |
| hide | `` | `void` | `obj:hide()` |
| toggle | `` | `void` | `obj:toggle()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| waitingForKey | `` | `boolean` | `obj:waitingForKey()` |
| setKey | `code: integer` | `void` | `obj:setKey(code)` |
| update | `` | `void` | `obj:update()` |
| saveLocationChanged | `line: DataPanelLine` | `void` | `obj:saveLocationChanged(line)` |
| changeFontSize | `line: DataPanelLine` | `void` | `obj:changeFontSize(line)` |
| changeVolume | `line: DataPanelLine` | `void` | `obj:changeVolume(line)` |
| toggleNames | `line: DataPanelLine` | `void` | `obj:toggleNames(line)` |
| resetTutorials | `_a1: DataPanelLine` | `void` | `obj:resetTutorials(_a1)` |
| toggleTutorials | `_a1: DataPanelLine` | `void` | `obj:toggleTutorials(_a1)` |
| changeDistances | `_a1: DataPanelLine` | `void` | `obj:changeDistances(_a1)` |
| toggleCompositor | `l: DataPanelLine` | `void` | `obj:toggleCompositor(l)` |
| resetAllKeys | `_a1: DataPanelLine` | `void` | `obj:resetAllKeys(_a1)` |
| saveOptions | `` | `void` | `obj:saveOptions()` |
| create | `` | `void` | `obj:create()` |
| updateResolutions | `` | `void` | `obj:updateResolutions()` |
| closeButton | `sender: MyGUI::Widget` | `void` | `obj:closeButton(sender)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `OptionsWindow` | `OptionsWindow.getSingleton()`<br>`obj:getSingleton()` |

## OrderCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrderCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| orderText | `MyGUI::Widget` | R | `obj.orderText` |
| removeButton | `MyGUI::Widget` | R | `obj.removeButton` |
| data | `OrderData` | RW | `obj.data = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |
| resize | `` | `void` | `obj:resize()` |
| onRemove | `widget: MyGUI::Widget` | `void` | `obj:onRemove(widget)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCellDimension | `` | `MyGUI::IntCoord` | `OrderCellView.getCellDimension()`<br>`obj:getCellDimension()` |

## OrderData
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrderData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| task | `Tasker` | RW | `obj.task = <value>` |
| index | `integer` | RW | `obj.index = <value>` |
| text | `string` | RW | `obj.text = <value>` |
| enabled | `boolean` | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: OrderData` | `void` | `obj:operator_assign(other)` |
| set | `_task: Tasker, _index: integer, _enabled: boolean` | `void` | `obj:set(_task, _index, _enabled)` |
| updateText | `` | `void` | `obj:updateText()` |

## OrdersItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrdersItemBox`

## OrdersPanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrdersPanel`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| ordersCharacter | `hand` | RW | `obj.ordersCharacter = <value>` |
| ordersItemBox | `OrdersItemBox` | RW | `obj.ordersItemBox = <value>` |
| ordersItemWidth | `integer` | RW | `obj.ordersItemWidth = <value>` |
| ordersItemBoxScrollBarSize | `integer` | RW | `obj.ordersItemBoxScrollBarSize = <value>` |
| ordersItemBoxMaxVisible | `integer` | RW | `obj.ordersItemBoxMaxVisible = <value>` |
| ordersEmptyPanel | `MyGUI::Widget` | R | `obj.ordersEmptyPanel` |
| blocksCheckbox | `MyGUI::Widget` | R | `obj.blocksCheckbox` |
| holdCheckBox | `MyGUI::Widget` | R | `obj.holdCheckBox` |
| passiveCheckBox | `MyGUI::Widget` | R | `obj.passiveCheckBox` |
| chaseCheckBox | `MyGUI::Widget` | R | `obj.chaseCheckBox` |
| tauntCheckBox | `MyGUI::Widget` | R | `obj.tauntCheckBox` |
| rangedCheckBox | `MyGUI::Widget` | R | `obj.rangedCheckBox` |
| stealthCheckBox | `MyGUI::Widget` | R | `obj.stealthCheckBox` |
| speedPrevButton | `MyGUI::Widget` | R | `obj.speedPrevButton` |
| speedNextButton | `MyGUI::Widget` | R | `obj.speedNextButton` |
| speedImagePanel | `MyGUI::Widget` | R | `obj.speedImagePanel` |
| speedImageNamesIdx | `integer` | RW | `obj.speedImageNamesIdx = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `character: Character` | `void` | `obj:update(character)` |
| clear | `` | `void` | `obj:clear()` |
| command | `cmd: integer` | `void` | `obj:command(cmd)` |
| refreshOrders | `` | `void` | `obj:refreshOrders()` |
| moveJob | `orderIdx: integer, targetIdx: integer` | `void` | `obj:moveJob(orderIdx, targetIdx)` |
| removeJob | `data: OrderData` | `void` | `obj:removeJob(data)` |
| notifyEndDropOrder | `raw: userdata, _result: boolean` | `void` | `obj:notifyEndDropOrder(raw, _result)` |
| setSpeed | `moveSpeed: MoveSpeed` | `void` | `obj:setSpeed(moveSpeed)` |
| setSpeedImage | `moveSpeed: MoveSpeed` | `void` | `obj:setSpeedImage(moveSpeed)` |
| toggleStealth | `sender: MyGUI::Widget` | `void` | `obj:toggleStealth(sender)` |
| toggleRanged | `sender: MyGUI::Widget` | `void` | `obj:toggleRanged(sender)` |
| speedPrevious | `sender: MyGUI::Widget` | `void` | `obj:speedPrevious(sender)` |
| speedNext | `sender: MyGUI::Widget` | `void` | `obj:speedNext(sender)` |
| blockmodeButton | `sender: MyGUI::Widget` | `void` | `obj:blockmodeButton(sender)` |
| holdButtonCallback | `sender: MyGUI::Widget` | `void` | `obj:holdButtonCallback(sender)` |
| passiveButtonCallback | `sender: MyGUI::Widget` | `void` | `obj:passiveButtonCallback(sender)` |
| chaseButtonCallback | `sender: MyGUI::Widget` | `void` | `obj:chaseButtonCallback(sender)` |
| tauntButtonCallback | `sender: MyGUI::Widget` | `void` | `obj:tauntButtonCallback(sender)` |
| medicButton | `sender: MyGUI::Widget` | `void` | `obj:medicButton(sender)` |
| liftButton | `sender: MyGUI::Widget` | `void` | `obj:liftButton(sender)` |
| prospectingButton | `sender: MyGUI::Widget` | `void` | `obj:prospectingButton(sender)` |

## Ownerships
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.Ownerships`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _homeTown | `TownBase` | RW | `obj._homeTown = <value>` |
| _homeBuilding | `hand` | RW | `obj._homeBuilding = <value>` |
| faction | `Faction` | RW | `obj.faction = <value>` |
| me | `Platoon` | RW | `obj.me = <value>` |
| occupiedTown | `TownBase` | RW | `obj.occupiedTown = <value>` |
| money | `integer` | RW | `obj.money = <value>` |
| slaves | `std::set<hand>` | RW | `obj.slaves = <value>` |
| stuff | `lektor<hand>` | RW | `obj.stuff = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setHandle | `h: Platoon` | `void` | `obj:setHandle(h)` |
| takeMoney | `val: integer` | `boolean` | `obj:takeMoney(val)` |
| takeMoneyByForce | `val: integer` | `void` | `obj:takeMoneyByForce(val)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| addMoney | `amount: integer` | `void` | `obj:addMoney(amount)` |
| setMoney | `amount: integer` | `void` | `obj:setMoney(amount)` |
| setHomeBuildingDesignation | `d: BuildingDesignation` | `void` | `obj:setHomeBuildingDesignation(d)` |
| copyFrom | `other: Ownerships` | `void` | `obj:copyFrom(other)` |
| serialise | `state: GameData` | `void` | `obj:serialise(state)` |
| load | `state: GameData, st: SquadType` | `void` | `obj:load(state, st)` |
| setHomeTown | `t: TownBase, squadtype: SquadType` | `void` | `obj:setHomeTown(t, squadtype)` |
| isMyTown | `t: TownBase` | `boolean` | `obj:isMyTown(t)` |
| canIUseThisBuilding | `b: Building, _me: Character` | `boolean` | `obj:canIUseThisBuilding(b, _me)` |
| declareOccupiedTown | `t: TownBase` | `void` | `obj:declareOccupiedTown(t)` |
| getOccupiedTownFaction | `` | `Faction` | `obj:getOccupiedTownFaction()` |
| addOwnedObject | `what: hand` | `void` | `obj:addOwnedObject(what)` |
| removeOwnedObject | `what: hand` | `void` | `obj:removeOwnedObject(what)` |
| isOwned | `what: hand` | `boolean` | `obj:isOwned(what)` |
| setHomeBuilding | `h: hand, t: SquadType` | `void` | `obj:setHomeBuilding(h, t)` |
| getOwnedBuildingsH | `` | `void` | `obj:getOwnedBuildingsH()` |
| getOwnedBuildingPtrs | `town: TownBase` | `void` | `obj:getOwnedBuildingPtrs(town)` |
| getHomeFurnitureOfType | `type: BuildingFunction` | `void` | `obj:getHomeFurnitureOfType(type)` |
| getOwnedPtrs | `type: itemType` | `integer` | `obj:getOwnedPtrs(type)` |
| getBuildingsWithFunction | `bf: BuildingFunction` | `void` | `obj:getBuildingsWithFunction(bf)` |

## ParticlePool
**Header:** `extern/KenshiLib/Include/kenshi/ParticlePool.h`
**Metatable:** `KenshiLua.ParticlePool`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| limit | `integer` | RW | `obj.limit = <value>` |
| lastIndex | `integer` | RW | `obj.lastIndex = <value>` |
| particles | `lightuserdata` | R | `obj.particles` |
| maxTTL | `number` | RW | `obj.maxTTL = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| init | `` | `void` | `obj:init()` |
| destroy | `` | `void` | `obj:destroy()` |
| getSize | `` | `integer` | `obj:getSize()` |
| update | `` | `void` | `obj:update()` |
| shiftParticles | `shift: Vector3` | `void` | `obj:shiftParticles(shift)` |

## ParticlePool::ParticleData
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Parent Class:** [`ParticlePool`](#particlepool)
**Metatable:** `KenshiLua.ParticlePool_ParticleData`

## physHit
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.physHit`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _defaultAltitudeFallback | `number` | RW | `obj._defaultAltitudeFallback = <value>` |
| _traceWasAborted | `boolean` | RW | `obj._traceWasAborted = <value>` |
| _doNotAbort | `boolean` | RW | `obj._doNotAbort = <value>` |
| _needsGroup | `boolean` | RW | `obj._needsGroup = <value>` |
| hit | `boolean` | RW | `obj.hit = <value>` |
| position | `Vector3` | RW | `obj.position = <value>` |
| normal | `Vector3` | RW | `obj.normal = <value>` |
| distance | `number` | RW | `obj.distance = <value>` |
| shape | `lightuserdata` | R | `obj.shape` |
| hitObject | `hand` | RW | `obj.hitObject = <value>` |
| _group | `integer` | RW | `obj._group = <value>` |
| _hitObjectUnsafePtr | `RootObject` | RW | `obj._hitObjectUnsafePtr = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| traceWasAborted | `` | `boolean` | `obj:traceWasAborted()` |
| reset | `` | `void` | `obj:reset()` |
| hitObjectUnsafePtr | `` | `RootObject` | `obj:hitObjectUnsafePtr()` |
| getBuilding | `` | `Building` | `obj:getBuilding()` |
| group | `` | `integer` | `obj:group()` |
| operator_bool | `` | `boolean` | `obj:operator_bool()` |
| operator_assign | `other: physHit` | `void` | `obj:operator_assign(other)` |

## PhysicalEntity
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`
**Metatable:** `KenshiLua.PhysicalEntity`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| ent | `lightuserdata` | R | `obj.ent` |
| parent | `lightuserdata` | R | `obj.parent` |
| floorNumber | `integer` | RW | `obj.floorNumber = <value>` |
| mat | `GameData` | RW | `obj.mat = <value>` |
| partData | `GameData` | RW | `obj.partData = <value>` |
| instanced | `boolean` | RW | `obj.instanced = <value>` |
| isShell | `boolean` | RW | `obj.isShell = <value>` |
| isEmissive | `boolean` | RW | `obj.isEmissive = <value>` |

## PhysicsActual
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.PhysicsActual`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| materialConcrete | `lightuserdata` | R | `obj.materialConcrete` |
| materialMetal | `lightuserdata` | R | `obj.materialMetal` |
| materialSand | `lightuserdata` | R | `obj.materialSand` |
| materialHuman | `lightuserdata` | R | `obj.materialHuman` |
| myTriggerCallback | `PhysicsActual::TriggerCallback` | RW | `obj.myTriggerCallback = <value>` |
| HW | `boolean` | RW | `obj.HW = <value>` |
| debugRenderOn | `boolean` | RW | `obj.debugRenderOn = <value>` |
| scytheClass | `lightuserdata` | RW | `obj.scytheClass = <value>` |
| controllerMgr | `lightuserdata` | R | `obj.controllerMgr` |
| physicsSDK | `lightuserdata` | R | `obj.physicsSDK` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateUT | `` | `void` | `obj:updateUT()` |
| backThreadUpdate | `time: number, _useOwnTimers: boolean` | `void` | `obj:backThreadUpdate(time, _useOwnTimers)` |
| threadJunkPreBT | `` | `void` | `obj:threadJunkPreBT()` |
| threadJunkPostBT | `` | `void` | `obj:threadJunkPostBT()` |
| setup | `` | `boolean` | `obj:setup()` |
| scytheGetFirstModelName | `filename: string` | `string` | `obj:scytheGetFirstModelName(filename)` |
| _createTriggerHull | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:_createTriggerHull(pos, size)` |
| _createStaticCapsule | `pos: Vector3, length: number, radius: number` | `lightuserdata` | `obj:_createStaticCapsule(pos, length, radius)` |
| _createStaticBox | `pos: Vector3, dimensions: Vector3, rot: Quaternion, group: integer` | `lightuserdata` | `obj:_createStaticBox(pos, dimensions, rot, group)` |
| _destroy | `actor: userdata` | `void` | `obj:_destroy(actor)` |
| uncookMesh | `mesh: userdata, cId: string` | `boolean` | `obj:uncookMesh(mesh, cId)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setActorCollisionGroup | `` | `void` | `PhysicsActual.setActorCollisionGroup()`<br>`obj:setActorCollisionGroup()` |
| getActorCollisionGroup | `` | `integer` | `PhysicsActual.getActorCollisionGroup()`<br>`obj:getActorCollisionGroup()` |
| setActorMaterial | `` | `void` | `PhysicsActual.setActorMaterial()`<br>`obj:setActorMaterial()` |

## PhysicsActual::TriggerCallback
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Parent Class:** [`PhysicsActual`](#physicsactual)
**Metatable:** `KenshiLua.TriggerCallback`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateFrameEndMT | `` | `void` | `obj:updateFrameEndMT()` |

## PhysicsCollection
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`
**Metatable:** `KenshiLua.PhysicsCollection`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| findRotatingEnt | `part: GameData` | `PhysicsCollection::RotatingEnt` | `obj:findRotatingEnt(part)` |
| getWindRotationPower | `` | `number` | `obj:getWindRotationPower()` |
| getWindMillPart | `` | `PhysicsCollection::RotatingEnt` | `obj:getWindMillPart()` |
| isLoaded | `` | `boolean` | `obj:isLoaded()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| handleChanged | `h: hand` | `void` | `obj:handleChanged(h)` |
| update [1] | `spd: number` | `void` | `obj:update(spd)` |
| update [2] | `speed: number` | `void` | `obj:update(speed)` |
| updateAimingType | `speed: number, rotTarget: Vector3` | `number` | `obj:updateAimingType(speed, rotTarget)` |

## PhysicsCollection::LightEnt
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`PhysicsCollection`](#physicscollection)
**Metatable:** `KenshiLua.LightEnt`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| light | `lightuserdata` | R | `obj.light` |
| brightness | `number` | RW | `obj.brightness = <value>` |
| range | `number` | RW | `obj.range = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setEnergyLevel | `level: number` | `void` | `obj:setEnergyLevel(level)` |
| setFloor | `floor: integer` | `void` | `obj:setFloor(floor)` |

## PhysicsCollection::RotatingEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`
**Parent Class:** [`PhysicsCollection`](#physicscollection)
**Metatable:** `KenshiLua.RotatingEnt`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| rotAxis | `Vector3` | RW | `obj.rotAxis = <value>` |
| rotationSpeed | `number` | RW | `obj.rotationSpeed = <value>` |
| rotationPower | `number` | RW | `obj.rotationPower = <value>` |
| speedMin | `number` | RW | `obj.speedMin = <value>` |
| speedMax | `number` | RW | `obj.speedMax = <value>` |
| rotationBase | `Quaternion` | RW | `obj.rotationBase = <value>` |
| isRotating | `boolean` | RW | `obj.isRotating = <value>` |
| rotationSrc | `Quaternion` | RW | `obj.rotationSrc = <value>` |
| rotationDst | `Quaternion` | RW | `obj.rotationDst = <value>` |
| rotatingTime | `number` | RW | `obj.rotatingTime = <value>` |
| rotationDuration | `number` | RW | `obj.rotationDuration = <value>` |
| windSpeedRotationMin | `number` | RW | `obj.windSpeedRotationMin = <value>` |
| windSpeedRotationMax | `number` | RW | `obj.windSpeedRotationMax = <value>` |
| windSpeedRotationDanger | `number` | RW | `obj.windSpeedRotationDanger = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `productionSpeed: number` | `void` | `obj:update(productionSpeed)` |
| updateAim | `speed: number, target: Vector3` | `number` | `obj:updateAim(speed, target)` |
| isRotatingEnt | `` | `boolean` | `obj:isRotatingEnt()` |
| getRotationPower | `` | `number` | `obj:getRotationPower()` |

## PhysicsCollection::StaticEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`
**Parent Class:** [`PhysicsCollection`](#physicscollection)
**Metatable:** `KenshiLua.StaticEnt`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `spd: number` | `void` | `obj:update(spd)` |
| updateAim | `rotSpeed: number, target: Vector3` | `number` | `obj:updateAim(rotSpeed, target)` |
| isRotatingEnt | `` | `boolean` | `obj:isRotatingEnt()` |

## PhysicsInterface
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.PhysicsInterface`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nWorld | `lightuserdata` | R | `obj.nWorld` |
| _queuesClear | `boolean` | RW | `obj._queuesClear = <value>` |
| queuesClearMuto | `lightuserdata` | R | `obj.queuesClearMuto` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getBackthread | `` | `PhysicsActual` | `obj:getBackthread()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| backThreadUpdate | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| createTriggerHull | `pos: Vector3, size: Vector3, user: RootObject` | `lightuserdata` | `obj:createTriggerHull(pos, size, user)` |
| createStaticCapsule | `pos: Vector3, h: number, w: number` | `lightuserdata` | `obj:createStaticCapsule(pos, h, w)` |
| doorWantsSetup | `t: DoorStuff` | `void` | `obj:doorWantsSetup(t)` |
| scytheInsertPreview | `buildingData: GameData, pre: PreviewBuilding` | `boolean` | `obj:scytheInsertPreview(buildingData, pre)` |
| loadScytheFileMT | `userdata: RootObject, file: string, pos: Vector3, q: Quaternion, boneAttachment: string, itemdata: GameData` | `lightuserdata` | `obj:loadScytheFileMT(userdata, file, pos, q, boneAttachment, itemdata)` |
| queuesAreClearMT | `` | `boolean` | `obj:queuesAreClearMT()` |
| setQueuesAreClear | `on: boolean` | `void` | `obj:setQueuesAreClear(on)` |

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.Platoon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| stringID | `string` | RW | `obj.stringID = <value>` |
| _characterCountCurrent | `integer` | RW | `obj._characterCountCurrent = <value>` |
| _characterCountOriginal | `integer` | RW | `obj._characterCountOriginal = <value>` |
| squadType | `SquadType` | RW | `obj.squadType = <value>` |
| hasUniques | `YesNoMaybe` | RW | `obj.hasUniques = <value>` |
| speedOverride | `MoveSpeed` | RW | `obj.speedOverride = <value>` |
| isSeparatedSquad | `hand` | RW | `obj.isSeparatedSquad = <value>` |
| canRefresh | `boolean` | RW | `obj.canRefresh = <value>` |
| regenerates | `boolean` | RW | `obj.regenerates = <value>` |
| myBaseHomeTownData | `GameData` | RW | `obj.myBaseHomeTownData = <value>` |
| priceMultWhenITrade | `number` | RW | `obj.priceMultWhenITrade = <value>` |
| _iBuyStolenGoods | `boolean` | RW | `obj._iBuyStolenGoods = <value>` |
| _iBuyIllegalGoods | `boolean` | RW | `obj._iBuyIllegalGoods = <value>` |
| locatorModel | `lightuserdata` | RW | `obj.locatorModel = <value>` |
| blackboard | `lightuserdata` | RW | `obj.blackboard = <value>` |
| _isIntact | `boolean` | RW | `obj._isIntact = <value>` |
| squadTemplate | `GameData` | RW | `obj.squadTemplate = <value>` |
| malnourishedLevel | `number` | RW | `obj.malnourishedLevel = <value>` |
| hasNeverBeenActivated | `boolean` | RW | `obj.hasNeverBeenActivated = <value>` |
| _persistentSquad | `boolean` | RW | `obj._persistentSquad = <value>` |
| isResidentSquad | `boolean` | RW | `obj.isResidentSquad = <value>` |
| currentSpawnArea | `lightuserdata` | RW | `obj.currentSpawnArea = <value>` |
| squadleader | `hand` | RW | `obj.squadleader = <value>` |
| ownerships | `Ownerships` | RW | `obj.ownerships = <value>` |
| activePlatoon | `ActivePlatoon` | RW | `obj.activePlatoon = <value>` |
| unloadedPlatoon | `lightuserdata` | RW | `obj.unloadedPlatoon = <value>` |
| patrolSettings | `lightuserdata` | RW | `obj.patrolSettings = <value>` |
| isDead | `boolean` | RW | `obj.isDead = <value>` |
| imprisoned | `boolean` | RW | `obj.imprisoned = <value>` |
| index | `integer` | RW | `obj.index = <value>` |
| traderInventoryRefreshTime | `TimeOfDay` | RW | `obj.traderInventoryRefreshTime = <value>` |
| messageOnActivation | `PlatoonCreationMessage` | RW | `obj.messageOnActivation = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setCharacterCount | `count: integer` | `void` | `obj:setCharacterCount(count)` |
| chooseNewHome | `` | `hand` | `obj:chooseNewHome()` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| getSquadType | `` | `SquadType` | `obj:getSquadType()` |
| setSquadType | `t: SquadType` | `void` | `obj:setSquadType(t)` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| hasCampaign | `` | `lightuserdata` | `obj:hasCampaign()` |
| iBuyStolenGoods | `what: Item` | `boolean` | `obj:iBuyStolenGoods(what)` |
| iBuyIllegalGoods | `` | `boolean` | `obj:iBuyIllegalGoods()` |
| setFaction | `p: Faction` | `void` | `obj:setFaction(p)` |
| canTakeRefugees | `who: Platoon` | `boolean` | `obj:canTakeRefugees(who)` |
| isUnique | `` | `lightuserdata` | `obj:isUnique()` |
| getPlatoonStringID | `` | `string` | `obj:getPlatoonStringID()` |
| getBlackboard | `` | `lightuserdata` | `obj:getBlackboard()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| erasePlatoonFile | `` | `void` | `obj:erasePlatoonFile()` |
| showDebugMarker | `on: boolean` | `void` | `obj:showDebugMarker(on)` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| serialiseEverything | `dataContainer: GameDataContainer, levelEditor: boolean` | `GameData` | `obj:serialiseEverything(dataContainer, levelEditor)` |
| loadStateData | `state: GameData` | `void` | `obj:loadStateData(state)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| reprocessTask | `t: Tasker` | `void` | `obj:reprocessTask(t)` |
| taskIsComplete | `t: Tasker` | `void` | `obj:taskIsComplete(t)` |
| setDataFilename | `f: string` | `void` | `obj:setDataFilename(f)` |
| isIntact | `` | `boolean` | `obj:isIntact()` |
| notifyMissionEnded | `` | `void` | `obj:notifyMissionEnded()` |
| activate | `` | `void` | `obj:activate()` |
| deactivate | `forceCharacterStates: GameDataContainer` | `void` | `obj:deactivate(forceCharacterStates)` |
| declareDead | `` | `void` | `obj:declareDead()` |
| undeclareDead | `` | `void` | `obj:undeclareDead()` |
| isFullyLoaded | `` | `boolean` | `obj:isFullyLoaded()` |
| getActivePlatoon | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getUnloadedPlatoon | `` | `lightuserdata` | `obj:getUnloadedPlatoon()` |
| update | `` | `boolean` | `obj:update()` |
| periodicUpdate_active | `time: number` | `void` | `obj:periodicUpdate_active(time)` |
| periodicUpdate_unloaded | `` | `void` | `obj:periodicUpdate_unloaded()` |
| setupPatrolSettings | `minRange: integer, maxRange: integer` | `void` | `obj:setupPatrolSettings(minRange, maxRange)` |
| getPatrolInfo | `` | `lightuserdata` | `obj:getPatrolInfo()` |
| getRoamingMapArea | `` | `lightuserdata` | `obj:getRoamingMapArea()` |
| isPersistentSquad | `` | `boolean` | `obj:isPersistentSquad()` |
| setPersistentSquad | `on: boolean` | `void` | `obj:setPersistentSquad(on)` |
| getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| getNearestActiveCharacter | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | `` | `Character` | `obj:getSquadLeader()` |
| getCharacterCount | `` | `integer` | `obj:getCharacterCount()` |
| getCharacterCount_Original | `` | `integer` | `obj:getCharacterCount_Original()` |
| needsNewCharacters | `` | `integer` | `obj:needsNewCharacters()` |
| reCheckPersistenceOnUnload | `` | `void` | `obj:reCheckPersistenceOnUnload()` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| setRoamingMapArea | `a: userdata` | `void` | `obj:setRoamingMapArea(a)` |
| getSquadLeader_theRealOne | `` | `hand` | `obj:getSquadLeader_theRealOne()` |

## PlayerInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`
**Metatable:** `KenshiLua.PlayerInterface`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| factionName | `string` | RW | `obj.factionName = <value>` |
| camera | `CameraClass` | RW | `obj.camera = <value>` |
| technology | `lightuserdata` | RW | `obj.technology = <value>` |
| selectedObjectsChangedThisFrame | `boolean` | RW | `obj.selectedObjectsChangedThisFrame = <value>` |
| contextMenu | `ContextMenu` | RW | `obj.contextMenu = <value>` |
| selectBox | `SelectionBox` | RW | `obj.selectBox = <value>` |
| moveMarker | `lightuserdata` | RW | `obj.moveMarker = <value>` |
| selectedCharacter | `hand` | RW | `obj.selectedCharacter = <value>` |
| aiOptions | `PlayerInterface::AIOptions` | RW | `obj.aiOptions = <value>` |
| interiorsVisibleHash | `integer` | RW | `obj.interiorsVisibleHash = <value>` |
| currentFloor | `integer` | RW | `obj.currentFloor = <value>` |
| currentMouseTask | `TaskType` | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | `itemType` | RW | `obj.mouseTaskTypeRestriction = <value>` |
| mouseRightTargetSet | `boolean` | RW | `obj.mouseRightTargetSet = <value>` |
| mouseRightTarget | `RootObject` | RW | `obj.mouseRightTarget = <value>` |
| rmouseTimer | `number` | RW | `obj.rmouseTimer = <value>` |
| selectedObject | `hand` | RW | `obj.selectedObject = <value>` |
| onlyAnimalsSelected | `boolean` | RW | `obj.onlyAnimalsSelected = <value>` |
| selectedLoadedLeft | `integer` | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterHandle | `hand` | RW | `obj.trackedCharacterHandle = <value>` |
| trackedCharacterFloor | `integer` | RW | `obj.trackedCharacterFloor = <value>` |
| levelEditor | `LevelEditor` | RW | `obj.levelEditor = <value>` |
| participant | `Faction` | RW | `obj.participant = <value>` |
| currentPlatoon | `Platoon` | RW | `obj.currentPlatoon = <value>` |
| deadPlayerSquad | `hand` | RW | `obj.deadPlayerSquad = <value>` |
| placementObject | `lightuserdata` | RW | `obj.placementObject = <value>` |
| characterEditorMode | `boolean` | RW | `obj.characterEditorMode = <value>` |
| mLeftUp | `boolean` | RW | `obj.mLeftUp = <value>` |
| mLeftDown | `boolean` | RW | `obj.mLeftDown = <value>` |
| mRightUp | `boolean` | RW | `obj.mRightUp = <value>` |
| mRightDown | `boolean` | RW | `obj.mRightDown = <value>` |
| interiorsVisible | `ogre_unordered_set<hand>` | RW | `obj.interiorsVisible = <value>` |
| playerCharacters | `lektor<Character*>` | RW | `obj.playerCharacters = <value>` |
| selectedCharacters | `ogre_unordered_set<hand>` | RW | `obj.selectedCharacters = <value>` |
| townsActive | `ogre_unordered_set<TownBase*>` | RW | `obj.townsActive = <value>` |
| zonesVisibilities | `ogre_unordered_map<ZoneMap*, unsigned char>` | RW | `obj.zonesVisibilities = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCamera | `` | `CameraClass` | `obj:getCamera()` |
| playerSetup | `cam: CameraClass` | `void` | `obj:playerSetup(cam)` |
| clearAndReset | `` | `void` | `obj:clearAndReset()` |
| factoryObjectCreatedCallback | `building: RootObject` | `void` | `obj:factoryObjectCreatedCallback(building)` |
| setFaction | `f: Faction` | `void` | `obj:setFaction(f)` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| setCurrentPlatoon | `platoon: Platoon` | `boolean` | `obj:setCurrentPlatoon(platoon)` |
| getCurrentPlatoon | `` | `Platoon` | `obj:getCurrentPlatoon()` |
| getCurrentActivePlatoon | `` | `RootObjectContainer` | `obj:getCurrentActivePlatoon()` |
| createSquad | `` | `ActivePlatoon` | `obj:createSquad()` |
| getDeadSquad | `` | `ActivePlatoon` | `obj:getDeadSquad()` |
| update | `` | `void` | `obj:update()` |
| updateUT | `` | `void` | `obj:updateUT()` |
| isBuildMode | `` | `boolean` | `obj:isBuildMode()` |
| activateObjectPlacementMode | `data: GameData` | `void` | `obj:activateObjectPlacementMode(data)` |
| activateCharacterEditMode | `character: Character` | `void` | `obj:activateCharacterEditMode(character)` |
| triggerAreaArrivalDialogue | `area: GameData` | `boolean` | `obj:triggerAreaArrivalDialogue(area)` |
| setCharacterEditMode | `on: boolean` | `void` | `obj:setCharacterEditMode(on)` |
| getCharacterEditMode | `` | `boolean` | `obj:getCharacterEditMode()` |
| unselectAll | `` | `void` | `obj:unselectAll()` |
| selectAll | `` | `void` | `obj:selectAll()` |
| selectObject | `obj: RootObject, modifier: boolean` | `void` | `obj:selectObject(obj, modifier)` |
| selectPlayerCharacter | `index: integer, modifier: boolean, track: boolean` | `void` | `obj:selectPlayerCharacter(index, modifier, track)` |
| _selectPlayerCharacter | `obj: RootObject, modifier: boolean, track: boolean` | `void` | `obj:_selectPlayerCharacter(obj, modifier, track)` |
| activateSelection | `obj: RootObject` | `void` | `obj:activateSelection(obj)` |
| getCameraCenter | `` | `Vector3` | `obj:getCameraCenter()` |
| getDistanceFromCamera | `v: Vector3` | `number` | `obj:getDistanceFromCamera(v)` |
| getSquaredDistanceFromCamera | `v: Vector3` | `number` | `obj:getSquaredDistanceFromCamera(v)` |
| startTrackCharacter | `target: RootObject` | `void` | `obj:startTrackCharacter(target)` |
| stopTrackCharacter | `` | `void` | `obj:stopTrackCharacter()` |
| isTrackingCharacter | `` | `boolean` | `obj:isTrackingCharacter()` |
| focusCamera | `pos: Vector3` | `void` | `obj:focusCamera(pos)` |
| manuallyOrientCamera | `rot: Quaternion, zoom: number` | `void` | `obj:manuallyOrientCamera(rot, zoom)` |
| focusCameraSelectedCharacter | `` | `void` | `obj:focusCameraSelectedCharacter()` |
| toggleLevelEditorOnSelectedTown | `` | `void` | `obj:toggleLevelEditorOnSelectedTown()` |
| isLevelEditMode | `` | `boolean` | `obj:isLevelEditMode()` |
| isObjectPlacementMode | `` | `boolean` | `obj:isObjectPlacementMode()` |
| setOrderSelectedCharacters | `order: MessageForB::StandingOrder` | `void` | `obj:setOrderSelectedCharacters(order)` |
| getLevelEditor | `` | `LevelEditor` | `obj:getLevelEditor()` |
| objectSelected | `obj: RootObject, select: boolean` | `void` | `obj:objectSelected(obj, select)` |
| toggleObjectSelected | `obj: RootObject` | `void` | `obj:toggleObjectSelected(obj)` |
| isObjectSelected | `obj: RootObject` | `boolean` | `obj:isObjectSelected(obj)` |
| unselectPlayerCharacter | `obj: RootObject` | `void` | `obj:unselectPlayerCharacter(obj)` |
| getCurrentFloor | `` | `integer` | `obj:getCurrentFloor()` |
| setCurrentFloor | `floor: integer` | `void` | `obj:setCurrentFloor(floor)` |
| getNearestSelectedCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestSelectedCharacterTo(pos)` |
| getNearestCharacterTo | `pos: Vector3` | `Character` | `obj:getNearestCharacterTo(pos)` |
| addOrderSelectedCharacters | `destinationIndoors: Building, task: TaskType, subject: RootObject, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addOrderSelectedCharacters(destinationIndoors, task, subject, shift, addDontClear, location)` |
| addJobSelectedCharacters | `task: TaskType, subject: RootObject, shift: boolean, add: boolean, location: Vector3` | `void` | `obj:addJobSelectedCharacters(task, subject, shift, add, location)` |
| removeJobSelectedCharacters | `t: TaskType` | `void` | `obj:removeJobSelectedCharacters(t)` |
| removePermaJobSelectedCharacters | `id: integer` | `void` | `obj:removePermaJobSelectedCharacters(id)` |
| selectedCharactersUnconcious | `displayMessage: boolean` | `boolean` | `obj:selectedCharactersUnconcious(displayMessage)` |
| selectedCharactersLayingLow | `` | `boolean` | `obj:selectedCharactersLayingLow()` |
| useSpeedGroup | `use: boolean` | `void` | `obj:useSpeedGroup(use)` |
| assignSpeedGroup | `create: boolean` | `void` | `obj:assignSpeedGroup(create)` |
| isEnemy | `who: Character` | `boolean` | `obj:isEnemy(who)` |
| isFactionKnown | `f: Faction` | `boolean` | `obj:isFactionKnown(f)` |
| encounterFaction | `faction: Faction` | `void` | `obj:encounterFaction(faction)` |
| pickupItem | `item: Item` | `void` | `obj:pickupItem(item)` |
| cycleSquad | `` | `void` | `obj:cycleSquad()` |
| cycleCharacter | `d: integer` | `void` | `obj:cycleCharacter(d)` |
| stopCharactersMovement | `` | `void` | `obj:stopCharactersMovement()` |
| getAnyPlayerCharacter | `` | `Character` | `obj:getAnyPlayerCharacter()` |
| isOrderValidForSelection | `task: TaskType` | `boolean` | `obj:isOrderValidForSelection(task)` |
| serialise | `data: GameData` | `void` | `obj:serialise(data)` |
| loadFromSerialise | `data: GameData` | `void` | `obj:loadFromSerialise(data)` |
| getInteriorsVisible | `building: Building` | `boolean` | `obj:getInteriorsVisible(building)` |
| setVisibilityForReflections | `set: boolean` | `void` | `obj:setVisibilityForReflections(set)` |
| resetFloorsVisibility | `` | `void` | `obj:resetFloorsVisibility()` |
| setFloorsVisibility | `floor: integer` | `void` | `obj:setFloorsVisibility(floor)` |
| addTaskNearestSelectedCharacter | `dest: Building, t: TaskType, subject: RootObject, shift: boolean, location: Vector3, noAnimals: boolean` | `void` | `obj:addTaskNearestSelectedCharacter(dest, t, subject, shift, location, noAnimals)` |
| updateLastMoveWaypointSelectedCharacters | `location: Vector3, dest: Building` | `void` | `obj:updateLastMoveWaypointSelectedCharacters(location, dest)` |
| clearSelection | `` | `void` | `obj:clearSelection()` |
| mouseScan | `` | `void` | `obj:mouseScan()` |
| characterSelected | `target: Character` | `void` | `obj:characterSelected(target)` |
| itemSelected | `item: Item` | `void` | `obj:itemSelected(item)` |
| buildingSelected | `building: Building, position: Vector3, interiorsVisible: boolean` | `boolean` | `obj:buildingSelected(building, position, interiorsVisible)` |
| playerMove | `pos: Vector3, destBuilding: Building` | `void` | `obj:playerMove(pos, destBuilding)` |
| _isPlayerCharacter | `obj: RootObject` | `boolean` | `obj:_isPlayerCharacter(obj)` |
| recruit [1] | `characters: lektor<Character*>, editor: boolean` | `boolean` | `obj:recruit(characters, editor)` |
| recruit [2] | `character: Character, editor: boolean` | `boolean` | `obj:recruit(character, editor)` |
| getDeadSquadHandle | `` | `hand` | `obj:getDeadSquadHandle()` |
| updatePlayerSelection | `oldHandle: hand, newHandle: hand` | `void` | `obj:updatePlayerSelection(oldHandle, newHandle)` |
| getAllSelectedObjects | `out: lektor<RootObject*>, type: itemType` | `void` | `obj:getAllSelectedObjects(out, type)` |
| newPlayerTaskSelectedCharacters | `t: TaskType, targetH: hand, destinationIndoors: Building, clickpos: Vector3, addDontClear: boolean` | `void` | `obj:newPlayerTaskSelectedCharacters(t, targetH, destinationIndoors, clickpos, addDontClear)` |
| getPlayerTaskProbability | `task: TaskType, target: RootObject` | `boolean\|number` | `obj:getPlayerTaskProbability(task, target)` |
| getAllPlayerCharacters [1] | `list: lektor<RootObject*>` | `void` | `obj:getAllPlayerCharacters(list)` |
| getAllPlayerCharacters [2] | `` | `lektor<Character*>` | `obj:getAllPlayerCharacters()` |
| updateFloorVisibility | `characters: lektor<Character*>` | `void` | `obj:updateFloorVisibility(characters)` |
| playerControl | `key: InputHandler` | `void` | `obj:playerControl(key)` |

## PlayerInterface::AIOptions
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`
**Parent Class:** [`PlayerInterface`](#playerinterface)
**Metatable:** `KenshiLua.AIOptions`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| healAllies | `boolean` | RW | `obj.healAllies = <value>` |
| helpAllies | `boolean` | RW | `obj.helpAllies = <value>` |
| rescueAllies | `boolean` | RW | `obj.rescueAllies = <value>` |
| stayInBase | `boolean` | RW | `obj.stayInBase = <value>` |
| feedAnimals | `boolean` | RW | `obj.feedAnimals = <value>` |
| shareFood | `boolean` | RW | `obj.shareFood = <value>` |
| autoSleep | `boolean` | RW | `obj.autoSleep = <value>` |
| autoDitchItems | `boolean` | RW | `obj.autoDitchItems = <value>` |
| autoSit | `boolean` | RW | `obj.autoSit = <value>` |
| ejectEnemies | `boolean` | RW | `obj.ejectEnemies = <value>` |
| shootFirst | `boolean` | RW | `obj.shootFirst = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| load | `data: GameData` | `void` | `obj:load(data)` |
| save | `data: GameData` | `void` | `obj:save(data)` |

## PortraitData
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |
| flashing | `integer` | RW | `obj.flashing = <value>` |
| state | `PortraitData::State` | RW | `obj.state = <value>` |
| reloadPortrait | `boolean` | RW | `obj.reloadPortrait = <value>` |
| characterHandle | `hand` | RW | `obj.characterHandle = <value>` |
| updateRequested | `boolean` | RW | `obj.updateRequested = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| update | `` | `boolean` | `obj:update()` |
| forceUpdate | `` | `void` | `obj:forceUpdate()` |
| isSelected | `` | `boolean` | `obj:isSelected()` |
| isDown | `` | `boolean` | `obj:isDown()` |
| getBackgroundImageName | `` | `string` | `obj:getBackgroundImageName()` |
| getBackOverlayImageName | `` | `string` | `obj:getBackOverlayImageName()` |
| getFrontOverlayImageName | `` | `string` | `obj:getFrontOverlayImageName()` |

## PortraitImage
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitImage`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| index | `integer` | RW | `obj.index = <value>` |
| created | `boolean` | RW | `obj.created = <value>` |
| textureName | `string` | RW | `obj.textureName = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateImageWidget | `image: MyGUI::ImageBox, val: boolean` | `void` | `obj:updateImageWidget(image, val)` |

## PortraitMainCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitMainCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| characterHandle | `hand` | RW | `obj.characterHandle = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| border | `MyGUI::Widget` | R | `obj.border` |
| imageBackground | `MyGUI::Widget` | R | `obj.imageBackground` |
| imagePortrait | `MyGUI::Widget` | R | `obj.imagePortrait` |
| imageOverlayBack | `MyGUI::Widget` | R | `obj.imageOverlayBack` |
| imageOverlayFront | `MyGUI::Widget` | R | `obj.imageOverlayFront` |
| textName | `MyGUI::Widget` | R | `obj.textName` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| resize | `size: integer` | `void` | `obj:resize(size)` |
| setName | `newName: string` | `void` | `obj:setName(newName)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCellDimension | `` | `MyGUI::IntCoord` | `PortraitMainCellView.getCellDimension()`<br>`obj:getCellDimension()` |

## PortraitManager
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textureSize | `iVector2` | RW | `obj.textureSize = <value>` |
| textureName | `string` | RW | `obj.textureName = <value>` |
| texturePortraitSize | `iVector2` | RW | `obj.texturePortraitSize = <value>` |
| maxIndex | `integer` | RW | `obj.maxIndex = <value>` |
| imagesIndices | `lightuserdata` | R | `obj.imagesIndices` |
| disableUpdate | `boolean` | RW | `obj.disableUpdate = <value>` |

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
| getCharacterFlashing | `character: Character` | `boolean` | `obj:getCharacterFlashing(character)` |
| getCharacterInCombat | `character: Character` | `boolean` | `obj:getCharacterInCombat(character)` |
| getCharacterDown | `character: Character` | `boolean` | `obj:getCharacterDown(character)` |
| getSquadFlashing | `platoon: ActivePlatoon` | `boolean` | `obj:getSquadFlashing(platoon)` |
| getPortrait | `characterHandle: hand` | `PortraitData` | `obj:getPortrait(characterHandle)` |
| updatePortrait | `oldHandle: hand, newHandle: hand` | `void` | `obj:updatePortrait(oldHandle, newHandle)` |
| updatePortraitImage | `characterHandle: hand` | `boolean` | `obj:updatePortraitImage(characterHandle)` |
| setImageWidget | `characterHandle: hand, imgBox: MyGUI::ImageBox, force: boolean` | `void` | `obj:setImageWidget(characterHandle, imgBox, force)` |
| setImageWidgetNPC | `character: Character, imgBox: MyGUI::ImageBox` | `void` | `obj:setImageWidgetNPC(character, imgBox)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getInstance | `` | `PortraitManager` | `PortraitManager.getInstance()`<br>`obj:getInstance()` |

## PreviewBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Metatable:** `KenshiLua.PreviewBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentNode | `lightuserdata` | R | `obj.parentNode` |
| isCurrentlySnapped | `boolean` | RW | `obj.isCurrentlySnapped = <value>` |
| snappedTo | `Building` | RW | `obj.snappedTo = <value>` |
| prospectingInformation | `DatapanelGUI` | RW | `obj.prospectingInformation = <value>` |
| prospectResource | `MiningResource` | RW | `obj.prospectResource = <value>` |
| roofOnly | `boolean` | RW | `obj.roofOnly = <value>` |
| spaceAbove | `number` | RW | `obj.spaceAbove = <value>` |
| spaceBelow | `number` | RW | `obj.spaceBelow = <value>` |
| collisionOK | `boolean` | RW | `obj.collisionOK = <value>` |
| charactersOK | `boolean` | RW | `obj.charactersOK = <value>` |
| floorOk | `boolean` | RW | `obj.floorOk = <value>` |
| indoorsOK | `boolean` | RW | `obj.indoorsOK = <value>` |
| slopeOK | `boolean` | RW | `obj.slopeOK = <value>` |
| nodesOk | `boolean` | RW | `obj.nodesOk = <value>` |
| blockedBuildings | `boolean` | RW | `obj.blockedBuildings = <value>` |
| validGround | `boolean` | RW | `obj.validGround = <value>` |
| inTown | `Town` | RW | `obj.inTown = <value>` |
| floorNum | `integer` | RW | `obj.floorNum = <value>` |
| isOutside | `boolean` | RW | `obj.isOutside = <value>` |
| matchSlope | `boolean` | RW | `obj.matchSlope = <value>` |
| justBeenBuilt | `Building` | RW | `obj.justBeenBuilt = <value>` |
| yaw | `number` | RW | `obj.yaw = <value>` |
| centreOffset | `Vector3` | RW | `obj.centreOffset = <value>` |
| isFurnitureOf | `Building` | RW | `obj.isFurnitureOf = <value>` |
| isIndoors | `Building` | RW | `obj.isIndoors = <value>` |
| buildDataPtr | `GameData` | RW | `obj.buildDataPtr = <value>` |
| farmData | `GameData` | RW | `obj.farmData = <value>` |
| prospectingOK | `boolean` | RW | `obj.prospectingOK = <value>` |
| furniture | `boolean` | RW | `obj.furniture = <value>` |
| exteriorFurniture | `boolean` | RW | `obj.exteriorFurniture = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| rot | `Quaternion` | RW | `obj.rot = <value>` |
| positionHitGroup | `integer` | RW | `obj.positionHitGroup = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| type | `` | `PreviewBuilding::PreviewBuildingClassType` | `obj:type()` |
| checkProspectingIsNotZero | `` | `boolean` | `obj:checkProspectingIsNotZero()` |
| isASnapToBuilding | `` | `boolean` | `obj:isASnapToBuilding()` |
| isACeilingBuilding | `` | `boolean` | `obj:isACeilingBuilding()` |
| snappingOk | `` | `boolean` | `obj:snappingOk()` |
| isInteriorBuilding | `` | `boolean` | `obj:isInteriorBuilding()` |
| isCurrent | `` | `boolean` | `obj:isCurrent()` |
| setup | `` | `boolean` | `obj:setup()` |
| _destroyEnts | `` | `void` | `obj:_destroyEnts()` |
| update | `` | `void` | `obj:update()` |
| figureOutWhichTown | `` | `void` | `obj:figureOutWhichTown()` |
| setVisualPosition | `position: Vector3` | `void` | `obj:setVisualPosition(position)` |
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
| isFloorOk | `` | `boolean` | `obj:isFloorOk()` |
| isIndoorsOk | `` | `boolean` | `obj:isIndoorsOk()` |
| isNodesOk | `` | `boolean` | `obj:isNodesOk()` |
| isBlockingBuildingsNodes | `` | `boolean` | `obj:isBlockingBuildingsNodes()` |
| isGoodAboveAndBelow | `` | `boolean` | `obj:isGoodAboveAndBelow()` |
| isOnValidGround | `` | `boolean` | `obj:isOnValidGround()` |
| isLinked | `` | `boolean` | `obj:isLinked()` |
| moveHeightOffset | `h: number` | `void` | `obj:moveHeightOffset(h)` |
| resetHeightOffset | `` | `void` | `obj:resetHeightOffset()` |
| getFootprintShift | `` | `number` | `obj:getFootprintShift()` |
| setOrientation | `q: Quaternion` | `void` | `obj:setOrientation(q)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| setStartPosition | `p: Vector3` | `void` | `obj:setStartPosition(p)` |
| setEndPosition | `position: Vector3` | `void` | `obj:setEndPosition(position)` |
| getEndPos | `` | `Vector3` | `obj:getEndPos()` |
| clearPointersTo | `_a1: PreviewBuilding` | `void` | `obj:clearPointersTo(_a1)` |
| placeFinalPreviewBuilding | `` | `void` | `obj:placeFinalPreviewBuilding()` |
| insideBuilding | `` | `Building` | `obj:insideBuilding()` |
| placementVerification | `` | `boolean` | `obj:placementVerification()` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| noAltitude | `` | `boolean` | `obj:noAltitude()` |
| noPathfindingNeeded | `` | `boolean` | `obj:noPathfindingNeeded()` |
| placePreview | `position: Vector3, rotation: Quaternion, floorNumber: integer` | `void` | `obj:placePreview(position, rotation, floorNumber)` |
| resetUseageNodes | `` | `void` | `obj:resetUseageNodes()` |
| calculateRotationsAndStuff | `position: Vector3` | `void` | `obj:calculateRotationsAndStuff(position)` |
| placementVerification_recurse | `` | `boolean` | `obj:placementVerification_recurse()` |
| getTerrainHeightAtCenter | `` | `number` | `obj:getTerrainHeightAtCenter()` |
| recalculateWorldAABB | `` | `void` | `obj:recalculateWorldAABB()` |
| validateUsageNodes | `` | `void` | `obj:validateUsageNodes()` |
| getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| getCentreOffset | `` | `Vector3` | `obj:getCentreOffset()` |
| isNoCollideWithThisBuilding [1] | `what: RootObject, shape: NxShape, node: boolean` | `boolean` | `obj:isNoCollideWithThisBuilding(what, shape, node)` |
| isNoCollideWithThisBuilding [2] | `what: PreviewBuilding` | `boolean` | `obj:isNoCollideWithThisBuilding(what)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getPlacementResultMaterialName | `result: PreviewBuilding::PlacementResult` | `void` | `PreviewBuilding.getPlacementResultMaterialName(result)`<br>`obj:getPlacementResultMaterialName(result)` |

## PreviewBuilding::Footprint
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Parent Class:** [`PreviewBuilding`](#previewbuilding)
**Metatable:** `KenshiLua.Footprint`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| wantsAboveGround | `boolean` | RW | `obj.wantsAboveGround = <value>` |
| lower | `number` | RW | `obj.lower = <value>` |
| space | `number` | RW | `obj.space = <value>` |
| scale | `number` | RW | `obj.scale = <value>` |
| ent | `lightuserdata` | R | `obj.ent` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| rot | `Quaternion` | RW | `obj.rot = <value>` |
| groundType | `BuildingPlacementGroundType::Enum` | RW | `obj.groundType = <value>` |
| valid | `boolean` | RW | `obj.valid = <value>` |
| parent | `PreviewBuilding` | RW | `obj.parent = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSpace | `` | `number` | `obj:getSpace()` |
| getMarker | `` | `number` | `obj:getMarker()` |
| setValid | `value: boolean` | `void` | `obj:setValid(value)` |
| getValid | `` | `boolean` | `obj:getValid()` |
| validate | `` | `boolean` | `obj:validate()` |
| fakeOppositeValidate | `gap: number` | `boolean` | `obj:fakeOppositeValidate(gap)` |
| collisionTestBuildings | `isFurniture: boolean, indoors: Building, currentFloor: integer` | `boolean` | `obj:collisionTestBuildings(isFurniture, indoors, currentFloor)` |
| collisionTestCharacters | `` | `boolean` | `obj:collisionTestCharacters()` |
| validFloorTest | `` | `boolean` | `obj:validFloorTest()` |
| isIndoorsOK | `isFurniture: boolean, out: Building, t: Town` | `boolean` | `obj:isIndoorsOK(isFurniture, out, t)` |
| isGroundValid | `` | `boolean` | `obj:isGroundValid()` |
| getWorldCorner | `corner: integer` | `Vector3` | `obj:getWorldCorner(corner)` |
| updateBox | `` | `void` | `obj:updateBox()` |
| getGroundHeight | `pos: Vector3` | `number` | `obj:getGroundHeight(pos)` |
| operator_assign | `other: Footprint` | `void` | `obj:operator_assign(other)` |

## PreviewBuilding::FootprintNode
**Header:** `extern/KenshiLib/Include/kenshi/Building/Building.h`
**Parent Class:** [`PreviewBuilding`](#previewbuilding)
**Metatable:** `KenshiLua.FootprintNode`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nodeId | `string` | RW | `obj.nodeId = <value>` |
| enabled | `boolean` | RW | `obj.enabled = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateBox | `` | `void` | `obj:updateBox()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| getNodeId | `` | `void` | `obj:getNodeId()` |
| operator_assign | `other: FootprintNode` | `void` | `obj:operator_assign(other)` |

## ProductionBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`
**Metatable:** `KenshiLua.ProductionBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| productionState | `ProductionBuilding::ProductionState` | RW | `obj.productionState = <value>` |
| _resourceMiningLevel | `number` | RW | `obj._resourceMiningLevel = <value>` |
| outSection | `InventorySection` | RW | `obj.outSection = <value>` |
| consumptionItems | `lektor<StorageBuilding::ConsumptionItem>` | RW | `obj.consumptionItems = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getProductionBuilding | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| update | `` | `void` | `obj:update()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| getProductionMult | `` | `number` | `obj:getProductionMult()` |
| getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| setupMiningResourceLevel | `` | `void` | `obj:setupMiningResourceLevel()` |
| getMiningResourceLevel | `` | `number` | `obj:getMiningResourceLevel()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| isAnyInputsInvalidType | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| isAnyInputsFull | `` | `boolean` | `obj:isAnyInputsFull()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| isProductionEmpty | `` | `boolean` | `obj:isProductionEmpty()` |
| getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| getOutput | `` | `number` | `obj:getOutput()` |
| getNumConsumtionItems | `` | `integer` | `obj:getNumConsumtionItems()` |
| getConsumtionItems | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| updateInputs | `rate: number` | `void` | `obj:updateInputs(rate)` |
| updateOutput | `rate: number` | `void` | `obj:updateOutput(rate)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| limitInputsOutputRate | `rate: number` | `boolean\|number` | `obj:limitInputsOutputRate(rate)` |
| operate | `who: Character, amount: number` | `void` | `obj:operate(who, amount)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getGUIToolTipForGroundResourceEfficiency | `` | `void` | `obj:getGUIToolTipForGroundResourceEfficiency()` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| getInputValue | `item: Item` | `number` | `obj:getInputValue(item)` |
| getResourcesNeededBecauseEmpty | `` | `void` | `obj:getResourcesNeededBecauseEmpty()` |
| getResourcesNeededBecauseNotFull | `` | `void` | `obj:getResourcesNeededBecauseNotFull()` |
| canHaveSomeOfThese | `these: GameData` | `boolean` | `obj:canHaveSomeOfThese(these)` |
| getItemsWeWantRidOf | `loot: boolean` | `void` | `obj:getItemsWeWantRidOf(loot)` |
| setProductionItem | `itemData: GameData, stack: integer, progress: number` | `void` | `obj:setProductionItem(itemData, stack, progress)` |
| getGUIFertility | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIFertility(datapanel, category)` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |

## ProductionInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`
**Metatable:** `KenshiLua.ProductionInventoryLayout`

## ProspectingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/ProspectingWindow.h`
**Metatable:** `KenshiLua.ProspectingWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | `MyGUI::Widget` | R | `obj.window` |
| imgMap | `MyGUI::Widget` | R | `obj.imgMap` |
| listResourcesPanel | `MyGUI::Widget` | R | `obj.listResourcesPanel` |
| listResourcesSelected | `MyGUI::Widget` | R | `obj.listResourcesSelected` |
| cameraMarker | `MyGUI::Widget` | R | `obj.cameraMarker` |
| cameraMarkerSkin | `lightuserdata` | R | `obj.cameraMarkerSkin` |
| datapanelOverview1 | `DatapanelGUI` | RW | `obj.datapanelOverview1 = <value>` |
| datapanelOverview2 | `DatapanelGUI` | RW | `obj.datapanelOverview2 = <value>` |
| resourceImage | `lightuserdata` | R | `obj.resourceImage` |
| lastPos | `Vector3` | RW | `obj.lastPos = <value>` |
| lastSkill | `number` | RW | `obj.lastSkill = <value>` |
| lastName | `string` | RW | `obj.lastName = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| showT | `pos: Vector3, skill: number, name: string` | `void` | `obj:showT(pos, skill, name)` |
| _show | `` | `void` | `obj:_show()` |
| hide | `` | `void` | `obj:hide()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| updateCameraMarker | `` | `void` | `obj:updateCameraMarker()` |
| updateMap | `resource: MiningResource` | `void` | `obj:updateMap(resource)` |
| refresh | `` | `void` | `obj:refresh()` |
| clear | `` | `void` | `obj:clear()` |
| worldToMapCoords | `pos: Vector3` | `void` | `obj:worldToMapCoords(pos)` |
| closeButton | `window: MyGUI::Window, name: string` | `void` | `obj:closeButton(window, name)` |
| resourceSelected | `widget: MyGUI::Widget` | `void` | `obj:resourceSelected(widget)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `ProspectingWindow` | `ProspectingWindow.getSingleton()`<br>`obj:getSingleton()` |

## ProspectingWindow::ResourceLinePanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`
**Parent Class:** [`ProspectingWindow`](#prospectingwindow)
**Metatable:** `KenshiLua.ResourceLinePanel`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| button | `MyGUI::Widget` | R | `obj.button` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getWidget | `` | `MyGUI::Widget` | `obj:getWidget()` |

## ProsperityManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`
**Metatable:** `KenshiLua.ProsperityManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| actualProsperity | `number` | RW | `obj.actualProsperity = <value>` |
| maxProsperity | `number` | RW | `obj.maxProsperity = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setup | `faction: GameData` | `void` | `obj:setup(faction)` |
| load | `state: GameData` | `void` | `obj:load(state)` |
| save | `state: GameData` | `void` | `obj:save(state)` |
| getProsperityMultiplier | `` | `number` | `obj:getProsperityMultiplier()` |
| getGUIData | `panel: DatapanelGUI, cat: integer` | `void` | `obj:getGUIData(panel, cat)` |
| update | `time: number` | `void` | `obj:update(time)` |
| notifySquadDefeated | `squadTemplate: GameData` | `void` | `obj:notifySquadDefeated(squadTemplate)` |
| notifySpecialNPCDead | `npc: GameData` | `void` | `obj:notifySpecialNPCDead(npc)` |

## RaceData
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`
**Metatable:** `KenshiLua.RaceData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `GameData` | RW | `obj.data = <value>` |
| runSpeedMaxSkill | `number` | RW | `obj.runSpeedMaxSkill = <value>` |
| runSpeedMinSkill | `number` | RW | `obj.runSpeedMinSkill = <value>` |
| originalBloodMin | `number` | RW | `obj.originalBloodMin = <value>` |
| originalBloodMax | `number` | RW | `obj.originalBloodMax = <value>` |
| healRate | `number` | RW | `obj.healRate = <value>` |
| bleedRate | `number` | RW | `obj.bleedRate = <value>` |
| swimSpeed | `number` | RW | `obj.swimSpeed = <value>` |
| walkSpeed | `number` | RW | `obj.walkSpeed = <value>` |
| swimOffset | `number` | RW | `obj.swimOffset = <value>` |
| waterAvoidance | `number` | RW | `obj.waterAvoidance = <value>` |
| hungerRate | `number` | RW | `obj.hungerRate = <value>` |
| visionMultiplier | `number` | RW | `obj.visionMultiplier = <value>` |
| gigantic | `boolean` | RW | `obj.gigantic = <value>` |
| swims | `boolean` | RW | `obj.swims = <value>` |
| carriable | `boolean` | RW | `obj.carriable = <value>` |
| singleGender | `boolean` | RW | `obj.singleGender = <value>` |
| robot | `boolean` | RW | `obj.robot = <value>` |
| vampiric | `boolean` | RW | `obj.vampiric = <value>` |
| noHats | `boolean` | RW | `obj.noHats = <value>` |
| noShirts | `boolean` | RW | `obj.noShirts = <value>` |
| noShoes | `boolean` | RW | `obj.noShoes = <value>` |
| extraAttackSlots | `integer` | RW | `obj.extraAttackSlots = <value>` |
| firstAidSkill | `StatsEnumerated` | RW | `obj.firstAidSkill = <value>` |
| canGoIndoors | `boolean` | RW | `obj.canGoIndoors = <value>` |
| raceGroup | `lightuserdata` | RW | `obj.raceGroup = <value>` |
| bloodColour | `unknown` | RW | `obj.bloodColour = <value>` |
| specialFoods | `ogre_unordered_set<GameData*>::type` | RW | `obj.specialFoods = <value>` |
| statMods | `ogre_unordered_map<StatsEnumerated, float>::type` | RW | `obj.statMods = <value>` |
| weatherImmunities | `ogre_unordered_set<WeatherAffecting>::type` | RW | `obj.weatherImmunities = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getRaceData [1] | `stringID: string` | `RaceData` | `obj:getRaceData(stringID)` |
| getRaceData [2] | `data: GameData` | `RaceData` | `obj:getRaceData(data)` |
| isRelatedRace [1] | `data: RaceData` | `boolean` | `obj:isRelatedRace(data)` |
| isRelatedRace [2] | `d: GameData` | `boolean` | `obj:isRelatedRace(d)` |
| isSpecificRace | `subrace: GameData` | `boolean` | `obj:isSpecificRace(subrace)` |
| getStatMod | `stat: StatsEnumerated` | `number` | `obj:getStatMod(stat)` |
| isImmune | `w: WeatherAffecting` | `boolean` | `obj:isImmune(w)` |
| canEat [1] | `food: GameData, isAnimal: boolean` | `boolean` | `obj:canEat(food, isAnimal)` |
| canEat [2] | `food: Item, isAnimal: boolean` | `boolean` | `obj:canEat(food, isAnimal)` |

## RaceLimiter
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`
**Metatable:** `KenshiLua.RaceLimiter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| limits | `ogre_unordered_map<GameData*, RaceLimiter::Limiter>` | RW | `obj.limits = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addLimit | `dat: GameData` | `void` | `obj:addLimit(dat)` |
| canEquip [1] | `race: RaceData, isAnimal: boolean` | `boolean` | `obj:canEquip(race, isAnimal)` |
| canEquip [2] | `item: GameData, race: RaceData, isAnimal: boolean` | `boolean` | `obj:canEquip(item, race, isAnimal)` |
| canEquip [3] | `item: GameData, who: RootObject` | `boolean` | `obj:canEquip(item, who)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `RaceLimiter` | `RaceLimiter.getSingleton()`<br>`obj:getSingleton()` |

## RaceLimiter::Limiter
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`
**Parent Class:** [`RaceLimiter`](#racelimiter)
**Metatable:** `KenshiLua.Limiter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| racesExclude | `std::set<RaceData*>` | RW | `obj.racesExclude = <value>` |
| racesInclude | `std::set<RaceData*>` | RW | `obj.racesInclude = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| canEquip | `race: RaceData, isAnimal: boolean` | `boolean` | `obj:canEquip(race, isAnimal)` |

## RainCollectorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/RainCollectorBuilding.h`
**Metatable:** `KenshiLua.RainCollectorBuilding`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| getRainAmount | `` | `number` | `obj:getRainAmount()` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |
| getGUIToolTipForGroundResourceEfficiency | `` | `void` | `obj:getGUIToolTipForGroundResourceEfficiency()` |

## rendHit
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`
**Metatable:** `KenshiLua.rendHit`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `integer` | RW | `obj.data = <value>` |
| hit | `Vector3` | RW | `obj.hit = <value>` |

## ReorderableList
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterEditWindow.h`
**Metatable:** `KenshiLua.ReorderableList`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `lightuserdata` | R | `obj.data` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| refresh | `force: boolean` | `void` | `obj:refresh(force)` |
| notifyEndDrop | `sender: integer, info: integer, result: boolean` | `void` | `obj:notifyEndDrop(sender, info, result)` |
| notifyRemoved | `index: integer` | `void` | `obj:notifyRemoved(index)` |

## ResearchBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`
**Metatable:** `KenshiLua.ResearchBuilding`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| update | `` | `void` | `obj:update()` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| getTechLevel | `` | `integer` | `obj:getTechLevel()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| operate | `stats: Character, amount: number` | `void` | `obj:operate(stats, amount)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| showResearchWindow | `` | `void` | `obj:showResearchWindow()` |

## ResearchBuildingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`
**Metatable:** `KenshiLua.ResearchBuildingInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| researchButton | `MyGUI::Widget` | RW | `obj.researchButton = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getResearchButton | `` | `MyGUI::Widget` | `obj:getResearchButton()` |
| setupSections | `inventoryGUI: InventoryGUI, sections: SectionsMap, inventory: Inventory` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |

## ResourceLoader
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Metatable:** `KenshiLua.ResourceLoader`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| running | `boolean` | RW | `obj.running = <value>` |
| sceneManager | `lightuserdata` | R | `obj.sceneManager` |
| loadingMeshQueueMutex | `lightuserdata` | R | `obj.loadingMeshQueueMutex` |
| texturesLoadingMutex | `lightuserdata` | R | `obj.texturesLoadingMutex` |
| texturesLoadedMutex | `lightuserdata` | R | `obj.texturesLoadedMutex` |
| texturesLoading | `Ogre::FastArray<TextureLoadData*>` | RW | `obj.texturesLoading = <value>` |
| texturesLoaded | `Ogre::FastArray<TextureLoadData*>` | RW | `obj.texturesLoaded = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateMT | `` | `void` | `obj:updateMT()` |
| updateBT | `` | `boolean` | `obj:updateBT()` |
| isLoading | `` | `boolean` | `obj:isLoading()` |
| init | `` | `void` | `obj:init()` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| destroy [1] | `material: Ogre::SharedPtr<Ogre::Material>, destroyManualTextures: boolean` | `void` | `obj:destroy(material, destroyManualTextures)` |
| destroy [2] | `entity: Ogre::InstancedEntity, destroyParent: boolean` | `void` | `obj:destroy(entity, destroyParent)` |
| destroy [3] | `obj: Ogre::MovableObject, destroyParent: boolean` | `void` | `obj:destroy(obj, destroyParent)` |
| destroy [4] | `entity: Ogre::Entity, destroyParent: boolean` | `void` | `obj:destroy(entity, destroyParent)` |
| destroy [5] | `` | `void` | `obj:destroy()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getInstance | `` | `void` | `ResourceLoader.getInstance()`<br>`obj:getInstance()` |

## ResourceLoader::MeshLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.MeshLoadData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| skeletonName | `string` | RW | `obj.skeletonName = <value>` |
| materialName | `string` | RW | `obj.materialName = <value>` |
| renderQueue | `integer` | RW | `obj.renderQueue = <value>` |

## ResourceLoader::ResourceLoadRequestMesh
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.ResourceLoadRequestMesh`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| entity | `lightuserdata` | R | `obj.entity` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| finish | `` | `void` | `obj:finish()` |

## ResourceLoader::ResourceLoadRequestTexture
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.ResourceLoadRequestTexture`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textureUnitState | `lightuserdata` | R | `obj.textureUnitState` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isMaterialValid | `` | `boolean` | `obj:isMaterialValid()` |

## ResourceLoader::TextureArrayLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.TextureArrayLoadData`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| loadImage | `` | `void` | `obj:loadImage()` |

## ResourceLoader::TextureLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.TextureLoadData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |
| group | `string` | RW | `obj.group = <value>` |
| loaded | `boolean` | RW | `obj.loaded = <value>` |
| queued | `boolean` | RW | `obj.queued = <value>` |
| success | `boolean` | RW | `obj.success = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| loadImage | `` | `void` | `obj:loadImage()` |

## RobotLimbItem
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`
**Metatable:** `KenshiLua.RobotLimbItem`

## RobotLimbs
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`
**Metatable:** `KenshiLua.RobotLimbs`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | `Character` | RW | `obj.character = <value>` |
| inventory | `RootObject` | RW | `obj.inventory = <value>` |
| states | `integer` | RW | `obj.states = <value>` |
| items | `Item` | RW | `obj.items = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| load | `state: GameData` | `void` | `obj:load(state)` |
| save | `state: GameData` | `void` | `obj:save(state)` |
| getLimb | `limb: integer` | `Item` | `obj:getLimb(limb)` |
| getMask | `` | `integer` | `obj:getMask()` |
| getInventoryInterface | `create: boolean` | `RootObject` | `obj:getInventoryInterface(create)` |
| destroyInventoryInterface | `` | `void` | `obj:destroyInventoryInterface()` |
| getLimbItem | `l: integer` | `Item` | `obj:getLimbItem(l)` |
| getState | `limb: integer` | `LimbState` | `obj:getState(limb)` |
| setLimb | `limb: integer, state: LimbState, item: Item` | `void` | `obj:setLimb(limb, state, item)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`
**Metatable:** `KenshiLua.RootObject`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| container | `RootObjectContainer` | RW | `obj.container = <value>` |
| isInsideBuilding | `hand` | RW | `obj.isInsideBuilding = <value>` |
| isInsideTownWalls | `integer` | RW | `obj.isInsideTownWalls = <value>` |
| floorNum | `integer` | RW | `obj.floorNum = <value>` |
| spacialKey | `integer` | RW | `obj.spacialKey = <value>` |
| outdoorDelayNotification_timer | `integer` | RW | `obj.outdoorDelayNotification_timer = <value>` |
| rot | `Quaternion` | RW | `obj.rot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| needsSaving | `s: string` | `boolean` | `obj:needsSaving(s)` |
| getInstanceID | `` | `InstanceID` | `obj:getInstanceID()` |
| getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| getZoneMapLocation | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| getRace | `` | `RaceData` | `obj:getRace()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| update | `` | `void` | `obj:update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | `_a1: boolean` | `void` | `obj:setVisible(_a1)` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| setFaction | `p: Faction, a: ActivePlatoon` | `void` | `obj:setFaction(p, a)` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| setInsideTownWalls | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| setFloor | `f: integer` | `void` | `obj:setFloor(f)` |
| select | `` | `void` | `obj:select()` |
| unselect | `` | `void` | `obj:unselect()` |
| getGUIData | `_a1: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(_a1, category)` |
| setStandingOrder | `_a1: MessageForB::StandingOrder` | `void` | `obj:setStandingOrder(_a1)` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| giveItem | `item: Item, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(item, dropOnFail, destroyOnFail)` |
| hasRoomForItem | `item: GameData` | `boolean` | `obj:hasRoomForItem(item)` |
| hasItem | `item: GameData` | `boolean` | `obj:hasItem(item)` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| ImStealingDoYouNotice | `thief: RootObject` | `boolean` | `obj:ImStealingDoYouNotice(thief)` |
| stolenGoodsDetectionCheck | `item: Item, thief: RootObject` | `boolean` | `obj:stolenGoodsDetectionCheck(item, thief)` |
| equipItem | `_a1: string, _a2: Item` | `void` | `obj:equipItem(_a1, _a2)` |
| unequipItem | `_a1: string, _a2: Item` | `void` | `obj:unequipItem(_a1, _a2)` |
| dropItem | `_a1: RootObject` | `void` | `obj:dropItem(_a1)` |
| takeMoney | `_a1: integer` | `boolean` | `obj:takeMoney(_a1)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| say | `_a1: string` | `void` | `obj:say(_a1)` |
| notifyOutdoors | `` | `void` | `obj:notifyOutdoors()` |
| isOnARoof | `` | `boolean` | `obj:isOnARoof()` |
| getIntendedAggression | `` | `number` | `obj:getIntendedAggression()` |
| getPlatoonAI | `` | `lightuserdata` | `obj:getPlatoonAI()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| notifyEffect | `type: EffectType::Enum, what: WeatherAffecting, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| loadUnloadCheck | `` | `void` | `obj:loadUnloadCheck()` |
| isIndoors | `` | `hand` | `obj:isIndoors()` |
| setIsInsideBuilding | `h: hand` | `void` | `obj:setIsInsideBuilding(h)` |
| getLayoutInstanceID | `` | `string` | `obj:getLayoutInstanceID()` |
| getAABB | `` | `lightuserdata` | `obj:getAABB()` |
| getGUIDataCategories | `` | `void` | `obj:getGUIDataCategories()` |
| getOrders | `` | `void` | `obj:getOrders()` |
| notifyIndoors | `in: hand` | `void` | `obj:notifyIndoors(in)` |
| hitByMeleeAttack [1] | `who: Character` | `void` | `obj:hitByMeleeAttack(who)` |
| hitByMeleeAttack [2] | `attack: CombatTechniqueData` | `void` | `obj:hitByMeleeAttack(attack)` |

## RootObjectBase
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectBase.h`
**Metatable:** `KenshiLua.RootObjectBase`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| validKey | `integer` | RW | `obj.validKey = <value>` |
| owner | `Faction` | RW | `obj.owner = <value>` |
| displayName | `string` | RW | `obj.displayName = <value>` |
| data | `GameData` | RW | `obj.data = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| handle | `hand` | RW | `obj.handle = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isValid | `` | `boolean` | `obj:isValid()` |
| getName | `` | `string` | `obj:getName()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| getDataType | `` | `itemType` | `obj:getDataType()` |
| typeIsAnItem | `` | `boolean` | `obj:typeIsAnItem()` |
| isUnconcious | `` | `boolean` | `obj:isUnconcious()` |
| getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getMovementSpeed | `` | `number` | `obj:getMovementSpeed()` |
| getMovementDirection | `` | `Vector3` | `obj:getMovementDirection()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |
| hasFaction | `` | `boolean` | `obj:hasFaction()` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| getSensoryData | `` | `SensoryData` | `obj:getSensoryData()` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| loadFromSerialise | `_a1: GameSaveState` | `void` | `obj:loadFromSerialise(_a1)` |
| getOwnerships | `` | `Ownerships` | `obj:getOwnerships()` |
| setFaction | `p: Faction, a: ActivePlatoon` | `void` | `obj:setFaction(p, a)` |
| getHandle | `` | `hand` | `obj:getHandle()` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |

## RootObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`
**Metatable:** `KenshiLua.RootObjectContainer`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| things | `lektor<RootObject*>` | RW | `obj.things = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| addActiveObject | `b: RootObject` | `boolean` | `obj:addActiveObject(b)` |
| removeObject | `c: RootObject` | `boolean` | `obj:removeObject(c)` |
| update | `` | `boolean` | `obj:update()` |
| getThing | `id: integer` | `RootObject` | `obj:getThing(id)` |
| getNumThings | `` | `integer` | `obj:getNumThings()` |
| getThings | `` | `lektor<RootObject*>` | `obj:getThings()` |
| loadToReality | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, callback: FactoryCallbackInterface, specificSID: string, externalContainer: GameDataContainer, skipperClass: RootObjectContainer::SpecificItemLoadFirst` | `void` | `obj:loadToReality(skipSaveState, positionMoved, rotOffset, callback, specificSID, externalContainer, skipperClass)` |
| getSelectedObjects | `type: itemType, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| serialiseThings [1] | `_things: lektor<RootObject*>, outputToInstanceCollectionOfSomeKind: GameData, source: GameDataContainer, offsetPosToSubtract: PosRotPair, mod: string` | `void` | `obj:serialiseThings(_things, outputToInstanceCollectionOfSomeKind, source, offsetPosToSubtract, mod)` |
| serialiseThings [2] | `outputToInstanceCollectionOfSomeKind: GameData, source: GameDataContainer, offsetPosToSubtract: PosRotPair, mod: string` | `void` | `obj:serialiseThings(outputToInstanceCollectionOfSomeKind, source, offsetPosToSubtract, mod)` |
| loadInstance | `state: GameSaveState, skipSaveState: boolean, pos: Vector3, rot: Quaternion, callback: FactoryCallbackInterface, positionMoved: Vector3` | `void` | `obj:loadInstance(state, skipSaveState, pos, rot, callback, positionMoved)` |

## RootObjectContainer::SpecificItemLoadFirst
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`
**Parent Class:** [`RootObjectContainer`](#rootobjectcontainer)
**Metatable:** `KenshiLua.SpecificItemLoadFirst`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| baseTypes | `itemType` | RW | `obj.baseTypes = <value>` |
| stateEnum | `itemType` | RW | `obj.stateEnum = <value>` |
| specificProperty | `string` | RW | `obj.specificProperty = <value>` |
| desiredSpecificProperty | `boolean` | RW | `obj.desiredSpecificProperty = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| shouldSkip | `state: GameSaveState` | `boolean` | `obj:shouldSkip(state)` |
| flip | `` | `void` | `obj:flip()` |

## RootObjectFactory
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`
**Metatable:** `KenshiLua.RootObjectFactory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| todoList | `std::deque<CreatelistItem*>` | RW | `obj.todoList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| create | `data: GameData, position: Vector3, isFromActiveLevelMod: boolean, owner: Faction, rotation: Quaternion, callbackObject: FactoryCallbackInterface, certainContainer: RootObjectContainer, state: GameSaveState, invisible: boolean, homeBuilding: Building, age: number` | `RootObjectBase` | `obj:create(data, position, isFromActiveLevelMod, owner, rotation, callbackObject, certainContainer, state, invisible, homeBuilding, age)` |
| createLocationNode | `addToNodeListAutomatically: boolean, data: GameData, position: Vector3, building: Building, owner: Faction, rotation: Quaternion, saveState: GameSaveState, nodeId: string` | `lightuserdata` | `obj:createLocationNode(addToNodeListAutomatically, data, position, building, owner, rotation, saveState, nodeId)` |
| copyItem | `from: Item` | `Item` | `obj:copyItem(from)` |
| chooseDataFromList | `dataList: GameData, listName: string, materialDataType: itemType, useVal012: integer` | `GameData` | `obj:chooseDataFromList(dataList, listName, materialDataType, useVal012)` |
| chooseDataFromListWithVals | `dataList: GameData, listName: string, materialDataType: itemType, useVal012: integer` | `GameDataReference` | `obj:chooseDataFromListWithVals(dataList, listName, materialDataType, useVal012)` |
| createCharacterForBuilding | `b: Building` | `void` | `obj:createCharacterForBuilding(b)` |
| createRandomCharacter | `faction: Faction, position: Vector3, owner: RootObjectContainer, characterTemplate: GameData, home: Building, age: number` | `RootObject` | `obj:createRandomCharacter(faction, position, owner, characterTemplate, home, age)` |
| mainThreadUpdate | `` | `void` | `obj:mainThreadUpdate()` |
| populateBuilding | `building: Building` | `void` | `obj:populateBuilding(building)` |
| process | `o: RootObjectFactory::CreatelistItem` | `RootObjectBase` | `obj:process(o)` |
| createBuilding | `data: GameData, position: Vector3, t: TownBase, owner: Faction, rotation: Quaternion, callbackObject: FactoryCallbackInterface, furnitureOf: userdata, isDoorOf: Building, saveState: GameSaveState, isIndoorsOf: Building, invisible: boolean, completed: boolean, isFoliage: boolean, floorNumber: integer, isOutsideFurniture: boolean` | `Building` | `obj:createBuilding(data, position, t, owner, rotation, callbackObject, furnitureOf, isDoorOf, saveState, isIndoorsOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture)` |
| createItem [1] | `gd: GameData, handle: hand, weaponMesh: GameData, matData: GameData, levelOverride: integer, flagUniform: Faction` | `Item` | `obj:createItem(gd, handle, weaponMesh, matData, levelOverride, flagUniform)` |
| createItem [2] | `itemState: GameData` | `Item` | `obj:createItem(itemState)` |
| getValsFromDataInList | `dataList: GameData, itemInList: GameData, listName: string` | `void` | `obj:getValsFromDataInList(dataList, itemInList, listName)` |
| createRandomUnloadedCharacter | `faction: Faction, platoon: userdata, position: Vector3, characterTemplate: GameData, owns: Ownerships` | `GameSaveState` | `obj:createRandomUnloadedCharacter(faction, platoon, position, characterTemplate, owns)` |
| createRandomSquad | `faction: Faction, position: Vector3, homeTown: TownBase, maxnum: integer, home: Building, squad: GameData, ownr: RootObjectContainer, maparea: userdata, _activePlatoon: Platoon, permanentsquad: boolean, AItarget: hand, targetTown: TownBase, sizeMultiplier: number, squadType: SquadType, isJustARefresh: boolean` | `Platoon` | `obj:createRandomSquad(faction, position, homeTown, maxnum, home, squad, ownr, maparea, _activePlatoon, permanentsquad, AItarget, targetTown, sizeMultiplier, squadType, isJustARefresh)` |
| createRandomUnloadedSquad | `faction: Faction, position: Vector3, homeTown: TownBase, maxnum: integer, home: Building, squad: GameData, owner: RootObjectContainer, maparea: userdata, permanentsquad: boolean, AItarget: hand, targetTown: TownBase, squadType: SquadType` | `Platoon` | `obj:createRandomUnloadedSquad(faction, position, homeTown, maxnum, home, squad, owner, maparea, permanentsquad, AItarget, targetTown, squadType)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| chooseMyClothing | `` | `void` | `RootObjectFactory.chooseMyClothing()`<br>`obj:chooseMyClothing()` |
| _chooseClothingItemFromList | `` | `GameData` | `RootObjectFactory._chooseClothingItemFromList()`<br>`obj:_chooseClothingItemFromList()` |

## RootObjectFactory::CreatelistItem
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`
**Parent Class:** [`RootObjectFactory`](#rootobjectfactory)
**Metatable:** `KenshiLua.CreatelistItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| container | `RootObjectContainer` | RW | `obj.container = <value>` |
| homeBuilding | `Building` | RW | `obj.homeBuilding = <value>` |
| faction | `Faction` | RW | `obj.faction = <value>` |
| data | `GameData` | RW | `obj.data = <value>` |
| position | `Vector3` | RW | `obj.position = <value>` |
| isFromActiveLevelMod | `boolean` | RW | `obj.isFromActiveLevelMod = <value>` |
| rotation | `Quaternion` | RW | `obj.rotation = <value>` |
| callbackObject | `FactoryCallbackInterface` | RW | `obj.callbackObject = <value>` |
| saveState | `GameSaveState` | RW | `obj.saveState = <value>` |
| age | `number` | RW | `obj.age = <value>` |

## SaveFileSystem
**Header:** `extern/KenshiLib/Include/kenshi/SaveFileSystem.h`
**Metatable:** `KenshiLua.SaveFileSystem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentSave | `string` | RW | `obj.currentSave = <value>` |
| currentFolder | `string` | RW | `obj.currentFolder = <value>` |
| tempFolder | `string` | RW | `obj.tempFolder = <value>` |
| currentPathIndex | `integer` | RW | `obj.currentPathIndex = <value>` |
| currentMutex | `lightuserdata` | R | `obj.currentMutex` |
| savingIcon | `MyGUI::Widget` | R | `obj.savingIcon` |
| state | `SaveFileSystem::State` | RW | `obj.state = <value>` |
| failedToCopyError | `string` | RW | `obj.failedToCopyError = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| log | `message: string, level: Logger::Severity` | `void` | `obj:log(message, level)` |
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
| addMessage | `type: SaveFileSystem::MessageType, src: string, dst: string` | `void` | `obj:addMessage(type, src, dst)` |
| getActiveSave | `` | `string` | `obj:getActiveSave()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `void` | `SaveFileSystem.getSingleton()`<br>`obj:getSingleton()` |

## SaveFileSystem::FileMessage
**Header:** `extern/KenshiLib/Include/kenshi/SaveFileSystem.h`
**Parent Class:** [`SaveFileSystem`](#savefilesystem)
**Metatable:** `KenshiLua.SaveFileSystem_FileMessage`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## SaveInfo
**Header:** `extern/KenshiLib/Include/kenshi/SaveInfo.h`
**Metatable:** `KenshiLua.SaveInfo`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| version | `string` | RW | `obj.version = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| area | `string` | RW | `obj.area = <value>` |
| time | `number` | RW | `obj.time = <value>` |
| faction | `string` | RW | `obj.faction = <value>` |
| money | `integer` | RW | `obj.money = <value>` |
| size | `integer` | RW | `obj.size = <value>` |
| days | `integer` | RW | `obj.days = <value>` |
| location | `string` | RW | `obj.location = <value>` |
| advanced | `GameplayOptions` | RW | `obj.advanced = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## SaveManager
**Header:** `extern/KenshiLib/Include/kenshi/SaveManager.h`
**Metatable:** `KenshiLua.SaveManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentGame | `string` | RW | `obj.currentGame = <value>` |
| saveVersion | `string` | RW | `obj.saveVersion = <value>` |
| localSavePath | `string` | RW | `obj.localSavePath = <value>` |
| userSavePath | `string` | RW | `obj.userSavePath = <value>` |
| signal | `integer` | RW | `obj.signal = <value>` |
| flags | `integer` | RW | `obj.flags = <value>` |
| delay | `integer` | RW | `obj.delay = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| location | `string` | RW | `obj.location = <value>` |
| loadMenu | `lightuserdata` | R | `obj.loadMenu` |
| saveMenu | `lightuserdata` | R | `obj.saveMenu` |
| importMenu | `lightuserdata` | R | `obj.importMenu` |
| autoSaveTimer | `number` | RW | `obj.autoSaveTimer = <value>` |
| pauseAutoSaveTimer | `boolean` | RW | `obj.pauseAutoSaveTimer = <value>` |

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
| saveGame | `location: string, name: string` | `integer` | `obj:saveGame(location, name)` |
| loadGame | `location: string, name: string` | `integer` | `obj:loadGame(location, name)` |
| importGame | `location: string, name: string, flags: integer` | `integer` | `obj:importGame(location, name, flags)` |
| importPlayerBuildings | `path: string, file: string` | `integer` | `obj:importPlayerBuildings(path, file)` |
| importOldPlayerBuildings | `path: string, name: string` | `integer` | `obj:importOldPlayerBuildings(path, name)` |
| load [1] | `s: SaveInfo, resetPos: boolean` | `void` | `obj:load(s, resetPos)` |
| load [2] | `name: string` | `void` | `obj:load(name)` |
| import | `s: SaveInfo, flags: integer` | `void` | `obj:import(s, flags)` |
| loadInfo | `info: SaveInfo` | `boolean` | `obj:loadInfo(info)` |
| checkVersion | `info: SaveInfo` | `boolean` | `obj:checkVersion(info)` |
| getCurrentGame | `` | `string` | `obj:getCurrentGame()` |
| getSavePath | `` | `string` | `obj:getSavePath()` |
| scanGames [1] | `list: lektor<SaveInfo>, loadDetails: boolean` | `integer` | `obj:scanGames(list, loadDetails)` |
| scanGames [2] | `location: string, list: lektor<SaveInfo>, loadDetails: boolean` | `integer` | `obj:scanGames(location, list, loadDetails)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `void` | `SaveManager.getSingleton()`<br>`obj:getSingleton()` |

## ScreenLabel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`
**Metatable:** `KenshiLua.ScreenLabel`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| caption | `string` | RW | `obj.caption = <value>` |
| textWidget | `MyGUI::Widget` | R | `obj.textWidget` |
| risingSpeed | `number` | RW | `obj.risingSpeed = <value>` |
| risingHeight | `number` | RW | `obj.risingHeight = <value>` |
| labelSize | `ScreenLabel::LabelSize` | RW | `obj.labelSize = <value>` |
| trackingHandle | `hand` | RW | `obj.trackingHandle = <value>` |
| trackingOffset | `Vector3` | RW | `obj.trackingOffset = <value>` |
| destroyed | `boolean` | RW | `obj.destroyed = <value>` |
| color | `MyGUI::Colour` | RW | `obj.color = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setTracking | `handle: hand, offset: Vector3` | `void` | `obj:setTracking(handle, offset)` |
| setCaption | `value: string` | `void` | `obj:setCaption(value)` |
| setRisingSpeed | `value: ScreenLabel::RisingSpeed` | `void` | `obj:setRisingSpeed(value)` |
| setColor | `` | `void` | `obj:setColor()` |
| setPosition | `value: Vector3` | `void` | `obj:setPosition(value)` |
| update | `` | `void` | `obj:update()` |
| destroy | `` | `void` | `obj:destroy()` |

## ScreenLabelDebug
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`
**Metatable:** `KenshiLua.ScreenLabelDebug`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeLeft | `number` | RW | `obj.timeLeft = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| getCaption | `` | `void` | `obj:getCaption()` |

## ScreenLabelInterface
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`
**Metatable:** `KenshiLua.ScreenLabelInterface`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| visible | `boolean` | RW | `obj.visible = <value>` |
| position | `Vector3` | RW | `obj.position = <value>` |
| needUpdate | `boolean` | RW | `obj.needUpdate = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| setVisible | `value: boolean` | `void` | `obj:setVisible(value)` |
| setPosition | `value: Vector3` | `void` | `obj:setPosition(value)` |

## Scythe::PhysicsClass
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.PhysicsClass`

## SeenSomeone
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Metatable:** `KenshiLua.SeenSomeone`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lastPosition | `Vector3` | RW | `obj.lastPosition = <value>` |
| lastSeenTime | `TimeOfDay` | RW | `obj.lastSeenTime = <value>` |
| percievedFaction | `Faction` | RW | `obj.percievedFaction = <value>` |
| percievedSlave | `SlaveStateEnum` | RW | `obj.percievedSlave = <value>` |
| FOVScore | `number` | RW | `obj.FOVScore = <value>` |
| canSee | `boolean` | RW | `obj.canSee = <value>` |
| canHear | `boolean` | RW | `obj.canHear = <value>` |
| alarmState | `number` | RW | `obj.alarmState = <value>` |
| type | `integer` | RW | `obj.type = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| lastSeenInSeconds | `` | `number` | `obj:lastSeenInSeconds()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getFaction | `` | `Faction` | `obj:getFaction()` |

## SelectionBox
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`
**Metatable:** `KenshiLua.SelectionBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| startPos | `Vector2` | RW | `obj.startPos = <value>` |
| widget | `MyGUI::Widget` | R | `obj.widget` |
| active | `boolean` | RW | `obj.active = <value>` |
| volume | `Ogre::PlaneBoundedVolume` | R | `obj.volume` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| start | `m: Vector2` | `void` | `obj:start(m)` |
| update | `m: Vector2` | `void` | `obj:update(m)` |
| cancel | `` | `void` | `obj:cancel()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| contains [1] | `a: Vector3, b: Vector3, radius: number` | `boolean` | `obj:contains(a, b, radius)` |
| contains [2] | `box: Ogre::AxisAlignedBox` | `boolean` | `obj:contains(box)` |
| contains [3] | `point: Vector3, r: number` | `boolean` | `obj:contains(point, r)` |

## SenseItr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Metatable:** `KenshiLua.SenseItr`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| flagsAny | `integer` | RW | `obj.flagsAny = <value>` |
| flagsNot | `integer` | RW | `obj.flagsNot = <value>` |
| _end | `boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >` | R | `obj._end` |
| it | `boost::unordered::iterator_detail::c_iterator<boost::unordered::detail::ptr_node<std::pair<hand const, SeenSomeone*> > >` | R | `obj.it` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| getData | `` | `SeenSomeone` | `obj:getData()` |
| ended | `` | `boolean` | `obj:ended()` |
| increment | `` | `void` | `obj:increment()` |
| operator_inc | `` | `void` | `obj:operator_inc()` |

## SensoryData
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Metatable:** `KenshiLua.SensoryData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nearestEnemy | `number` | RW | `obj.nearestEnemy = <value>` |
| numUnconsciousAllies | `integer` | RW | `obj.numUnconsciousAllies = <value>` |
| numConsciousAllies | `integer` | RW | `obj.numConsciousAllies = <value>` |
| totalThreatLevelPersonal | `number` | RW | `obj.totalThreatLevelPersonal = <value>` |
| totalThreatLevelAllies | `number` | RW | `obj.totalThreatLevelAllies = <value>` |
| totalIntendedThreatLevelGeneral | `number` | RW | `obj.totalIntendedThreatLevelGeneral = <value>` |
| numEnemies | `integer` | RW | `obj.numEnemies = <value>` |
| numNeutrals | `integer` | RW | `obj.numNeutrals = <value>` |
| lastThreat | `number` | RW | `obj.lastThreat = <value>` |
| currentAssessIndex | `integer` | RW | `obj.currentAssessIndex = <value>` |
| currentAssessList | `integer` | RW | `obj.currentAssessList = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| spottedSneakingPeople | `SensoryData::SpottingPeopleMgr` | RW | `obj.spottedSneakingPeople = <value>` |
| spottedSuspiciousPeople | `SensoryData::SpottingPeopleMgr` | RW | `obj.spottedSuspiciousPeople = <value>` |
| progressBar | `FloatingProgressBar` | RW | `obj.progressBar = <value>` |
| progressBarStillNeeded | `integer` | RW | `obj.progressBarStillNeeded = <value>` |
| spottedGuyIndexForProgressBar | `hand` | RW | `obj.spottedGuyIndexForProgressBar = <value>` |
| amSharingThisFrame | `boolean` | RW | `obj.amSharingThisFrame = <value>` |
| assessList | `lightuserdata` | R | `obj.assessList` |
| flockingList | `lightuserdata` | R | `obj.flockingList` |
| hearTestTimers | `lightuserdata` | R | `obj.hearTestTimers` |
| killList | `lightuserdata` | R | `obj.killList` |
| seen | `lightuserdata` | R | `obj.seen` |
| threats | `lightuserdata` | R | `obj.threats` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| periodicUpdate | `time: number` | `void` | `obj:periodicUpdate(time)` |
| periodicUpdate_KOed | `` | `void` | `obj:periodicUpdate_KOed()` |
| getVisionRange | `inTown: boolean` | `number` | `obj:getVisionRange(inTown)` |
| update [1] | `frameTime: number` | `void` | `obj:update(frameTime)` |
| update [2] | `time: number` | `void` | `obj:update(time)` |
| notifyKO | `` | `void` | `obj:notifyKO()` |
| getIterator | `tagsAny: integer, tagsNOT: integer` | `SenseItr` | `obj:getIterator(tagsAny, tagsNOT)` |
| getNearestEnemyDistanceSq | `` | `number` | `obj:getNearestEnemyDistanceSq()` |
| canISeeThisGuy | `who: Character` | `boolean` | `obj:canISeeThisGuy(who)` |
| canIHearThisGuy | `who: Character` | `boolean` | `obj:canIHearThisGuy(who)` |
| amIAwareOfThisGuy | `who: Character, needToSeeOrHear: boolean` | `boolean` | `obj:amIAwareOfThisGuy(who, needToSeeOrHear)` |
| getLastKnownPositionOf | `who: Character` | `Vector3` | `obj:getLastKnownPositionOf(who)` |
| getDataFor | `who: Character` | `SeenSomeone` | `obj:getDataFor(who)` |
| getFactionRelation | `c: RootObjectBase` | `number` | `obj:getFactionRelation(c)` |
| getStateBroadcast | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getGUIData | `panel: DatapanelGUI, cat: integer` | `void` | `obj:getGUIData(panel, cat)` |
| _calculateFOVScore | `who: Character` | `number` | `obj:_calculateFOVScore(who)` |
| _traceLineOfSightCheck | `who: Character` | `boolean` | `obj:_traceLineOfSightCheck(who)` |
| getCharacter | `` | `Character` | `obj:getCharacter()` |
| dialogAssessmentUpdate | `frameTime: number, inDepth: boolean` | `void` | `obj:dialogAssessmentUpdate(frameTime, inDepth)` |
| noticeThisPerson | `c: Character, alarmed: boolean` | `void` | `obj:noticeThisPerson(c, alarmed)` |
| add | `c: Character, see: boolean, hear: boolean` | `SeenSomeone` | `obj:add(c, see, hear)` |
| remove | `c: Character` | `void` | `obj:remove(c)` |
| decay | `c: Character` | `void` | `obj:decay(c)` |
| canSee | `c: Character, sees: SeenSomeone` | `boolean` | `obj:canSee(c, sees)` |
| canHear | `c: Character, see: SeenSomeone` | `boolean` | `obj:canHear(c, see)` |
| disguiseMods | `c: Character, FOV: number` | `boolean` | `obj:disguiseMods(c, FOV)` |
| assessCrimes | `c: Character` | `void` | `obj:assessCrimes(c)` |
| assessKidnapping | `c: Character` | `void` | `obj:assessKidnapping(c)` |
| processKillList | `` | `void` | `obj:processKillList()` |
| assessNeutral | `who: Character, inDepth: boolean` | `void` | `obj:assessNeutral(who, inDepth)` |
| updateMyProgressBar | `progress: number, text: string` | `void` | `obj:updateMyProgressBar(progress, text)` |
| canISeeThisGuyDoinSneakingOrSomething | `who: Character, FOVScore: number, memory: SensoryData::SpottingPeopleMgr, spotTimeMinFOV: number, spotTimeMaxFOV: number` | `YesNoMaybe` | `obj:canISeeThisGuyDoinSneakingOrSomething(who, FOVScore, memory, spotTimeMinFOV, spotTimeMaxFOV)` |
| isIntruder_Base | `who: Character` | `boolean` | `obj:isIntruder_Base(who)` |
| isIntruder_Building | `who: Character` | `boolean` | `obj:isIntruder_Building(who)` |
| isInMyPrivate_Building | `who: Character` | `boolean` | `obj:isInMyPrivate_Building(who)` |
| isEscapee | `who: Character` | `boolean` | `obj:isEscapee(who)` |
| reassess | `c: Character, sees: SeenSomeone, time: number` | `SeenSomeone` | `obj:reassess(c, sees, time)` |
| addToThreatsAndFlockingList | `c: Character` | `void` | `obj:addToThreatsAndFlockingList(c)` |
| buildingSpotterUpdate | `` | `void` | `obj:buildingSpotterUpdate()` |
| notifyCriminalThreat | `h: hand` | `void` | `obj:notifyCriminalThreat(h)` |
| getStateBroadcastOf | `who: hand` | `StateBroadcastData*` | `obj:getStateBroadcastOf(who)` |
| _shareSensesCheck | `leader: Character, list: userdata, time: number` | `boolean` | `obj:_shareSensesCheck(leader, list, time)` |
| setupMyProgressBar | `who: hand` | `void` | `obj:setupMyProgressBar(who)` |
| reassessAll | `newTargets: userdata, time: number` | `void` | `obj:reassessAll(newTargets, time)` |

## SensoryData::SpottingPeopleMgr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Parent Class:** [`SensoryData`](#sensorydata)
**Metatable:** `KenshiLua.SpottingPeopleMgr`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| spottedPeople | `std::map<hand, SensoryData::SpottingPeopleMgr::Spot>` | RW | `obj.spottedPeople = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `time: number` | `void` | `obj:update(time)` |
| resetSeenFlags | `` | `void` | `obj:resetSeenFlags()` |
| spot | `h: hand, timelimit: number` | `void` | `obj:spot(h, timelimit)` |
| getTime | `h: hand` | `number` | `obj:getTime(h)` |
| cantSeeAnymore | `h: hand` | `void` | `obj:cantSeeAnymore(h)` |
| has | `h: hand` | `boolean` | `obj:has(h)` |

## SensoryData::SpottingPeopleMgr::Spot
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Parent Class:** [`SensoryData`](#sensorydata)
**Metatable:** `KenshiLua.Spot`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeSoFar | `number` | RW | `obj.timeSoFar = <value>` |
| timeLimitMax | `number` | RW | `obj.timeLimitMax = <value>` |
| stillSeen | `boolean` | RW | `obj.stillSeen = <value>` |

## ShopTrader
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`
**Metatable:** `KenshiLua.ShopTrader`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| trader | `Character` | RW | `obj.trader = <value>` |
| inventory | `Inventory` | RW | `obj.inventory = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| takeMoney | `money: integer` | `boolean` | `obj:takeMoney(money)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| getOrientation | `` | `Quaternion` | `obj:getOrientation()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| isIndoors | `` | `hand` | `obj:isIndoors()` |
| getFloor | `` | `integer` | `obj:getFloor()` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| serialise | `container: GameDataContainer, refList: GameData, offsetPosToSubtract: userdata` | `GameSaveState` | `obj:serialise(container, refList, offsetPosToSubtract)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| getTrader | `` | `Character` | `obj:getTrader()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| updateInventory | `` | `void` | `obj:updateInventory()` |
| equipItem | `sectionName: string, item: Item` | `void` | `obj:equipItem(sectionName, item)` |
| unequipItem | `sectionName: string, item: Item` | `void` | `obj:unequipItem(sectionName, item)` |

## ShopTraderInventory
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`
**Metatable:** `KenshiLua.ShopTraderInventory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| inventories | `ogre_unordered_map<hand, InventorySection*>` | RW | `obj.inventories = <value>` |
| section | `ShopTraderInventorySection` | RW | `obj.section = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateInventory | `` | `void` | `obj:updateInventory()` |
| dropItem | `item: Item` | `void` | `obj:dropItem(item)` |
| refreshGui | `` | `void` | `obj:refreshGui()` |
| initialiseNewSection | `name: string, w: integer, h: integer, _a4: AttachSlot, equipCallbacks: boolean, _a6: boolean, _a7: boolean, _a8: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8)` |
| _addItem | `item: Item, quantity: integer` | `boolean` | `obj:_addItem(item, quantity)` |
| _addItemToInventories | `item: Item` | `boolean` | `obj:_addItemToInventories(item)` |
| _removeItemFromInventories | `item: Item, quantity: integer` | `void` | `obj:_removeItemFromInventories(item, quantity)` |
| _sectionAddItemCallback | `item: Item` | `void` | `obj:_sectionAddItemCallback(item)` |
| _sectionUpdateItemCallback | `item: Item, prevQuantity: integer` | `void` | `obj:_sectionUpdateItemCallback(item, prevQuantity)` |
| _sectionRemoveItemCallback | `item: Item` | `void` | `obj:_sectionRemoveItemCallback(item)` |

## ShopTraderInventorySection
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`
**Metatable:** `KenshiLua.ShopTraderInventorySection`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| autoArrange | `` | `void` | `obj:autoArrange()` |
| addItem | `item: Item, quantity: integer` | `boolean` | `obj:addItem(item, quantity)` |

## SimpleTimeStamper
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`
**Metatable:** `KenshiLua.SimpleTimeStamper`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timer | `CPerfTimer` | RW | `obj.timer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getTime | `_lastStamp: number` | `number` | `obj:getTime(_lastStamp)` |
| stampTime | `` | `number` | `obj:stampTime()` |

## Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_Slider.h`
**Metatable:** `KenshiLua.Slider`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mDisableEvents | `boolean` | RW | `obj.mDisableEvents = <value>` |
| mScrollbar | `MyGUI::Widget` | R | `obj.mScrollbar` |
| mSliderName | `MyGUI::Widget` | R | `obj.mSliderName` |
| mSliderValue | `MyGUI::Widget` | R | `obj.mSliderValue` |
| mLoValue | `integer` | RW | `obj.mLoValue = <value>` |
| mHiValue | `integer` | RW | `obj.mHiValue = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| initialiseOverride | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | `` | `void` | `obj:shutdownOverride()` |
| getTypeName | `` | `void` | `obj:getTypeName()` |

## SpeedGroup
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.SpeedGroup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| position | `Vector3` | RW | `obj.position = <value>` |
| direction | `Vector3` | RW | `obj.direction = <value>` |
| speed | `number` | RW | `obj.speed = <value>` |
| last | `integer` | RW | `obj.last = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSpeed | `who: Character` | `number` | `obj:getSpeed(who)` |
| insert | `h: hand` | `void` | `obj:insert(h)` |
| erase | `h: hand` | `void` | `obj:erase(h)` |

## SplashScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/SplashScreen.h`
**Metatable:** `KenshiLua.SplashScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentState | `integer` | RW | `obj.currentState = <value>` |
| startTime | `number` | RW | `obj.startTime = <value>` |
| skipLogo | `boolean` | RW | `obj.skipLogo = <value>` |
| delay | `integer` | RW | `obj.delay = <value>` |
| mainPanel | `MyGUI::Widget` | R | `obj.mainPanel` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| getState | `` | `integer` | `obj:getState()` |
| getEnded | `` | `boolean` | `obj:getEnded()` |
| skip | `` | `void` | `obj:skip()` |
| addLogo | `file: string, scale: number` | `void` | `obj:addLogo(file, scale)` |

## SquadManagementScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Metatable:** `KenshiLua.SquadManagementScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mainWidget | `MyGUI::Widget` | R | `obj.mainWidget` |
| btnAddSquad | `MyGUI::Widget` | R | `obj.btnAddSquad` |
| txtFactionSize | `MyGUI::Widget` | R | `obj.txtFactionSize` |
| factionSize | `integer` | RW | `obj.factionSize = <value>` |
| panelSquads | `SquadManagementScreen::SquadItemBox` | RW | `obj.panelSquads = <value>` |
| panelDismiss | `SquadManagementScreen::PortraitSquadItemBox` | RW | `obj.panelDismiss = <value>` |
| dismissChar | `Character` | RW | `obj.dismissChar = <value>` |
| faction | `Faction` | RW | `obj.faction = <value>` |
| squads | `SquadsMapBinding::MapType` | RW | `obj.squads = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getVisible | `` | `boolean` | `obj:getVisible()` |
| update [1] | `` | `void` | `obj:update()` |
| update [2] | `_info: MyGUI::IBDrawItemInfo, _data: PortraitData` | `void` | `obj:update(_info, _data)` |
| update [3] | `_info: MyGUI::IBDrawItemInfo, _data: SquadManagementScreen::SquadData` | `void` | `obj:update(_info, _data)` |
| reset | `` | `void` | `obj:reset()` |
| refreshSquads | `` | `void` | `obj:refreshSquads()` |
| notifyEndDropSquad | `raw: userdata, _result: boolean` | `void` | `obj:notifyEndDropSquad(raw, _result)` |
| notifyEndDropPortrait | `raw: userdata, _result: boolean` | `void` | `obj:notifyEndDropPortrait(raw, _result)` |
| removeSquad | `squad: SquadManagementScreen::SquadData` | `void` | `obj:removeSquad(squad)` |
| getSquad | `platoon: ActivePlatoon` | `SquadManagementScreen::SquadData` | `obj:getSquad(platoon)` |
| dismissCharacter | `result: integer` | `void` | `obj:dismissCharacter(result)` |
| onAddSquad | `widget: MyGUI::Widget` | `void` | `obj:onAddSquad(widget)` |

## SquadManagementScreen::PortraitSquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.PortraitSquadCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| characterHandle | `hand` | RW | `obj.characterHandle = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| border | `MyGUI::Widget` | R | `obj.border` |
| imgBoxPortrait | `MyGUI::Widget` | R | `obj.imgBoxPortrait` |
| txtName | `MyGUI::Widget` | R | `obj.txtName` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| resize | `` | `void` | `obj:resize()` |
| setName | `newName: string` | `void` | `obj:setName(newName)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCellDimension | `` | `MyGUI::IntCoord` | `SquadManagementScreen::PortraitSquadCellView.getCellDimension()`<br>`obj:getCellDimension()` |

## SquadManagementScreen::PortraitSquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.PortraitSquadItemBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| squad | `lightuserdata` | R | `obj.squad` |
| squadView | `lightuserdata` | R | `obj.squadView` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getItemCount | `` | `integer` | `obj:getItemCount()` |
| update | `` | `void` | `obj:update()` |

## SquadManagementScreen::SquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.SquadCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| portraitsBox | `SquadManagementScreen::PortraitSquadItemBox` | RW | `obj.portraitsBox = <value>` |
| txtName | `MyGUI::Widget` | R | `obj.txtName` |
| txtSquadSize | `MyGUI::Widget` | R | `obj.txtSquadSize` |
| squad | `SquadManagementScreen::SquadData` | RW | `obj.squad = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateSquadSize | `` | `void` | `obj:updateSquadSize()` |
| onNameChanged | `editBox: MyGUI::EditBox` | `void` | `obj:onNameChanged(editBox)` |
| onRemove | `widget: MyGUI::Widget` | `void` | `obj:onRemove(widget)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getCellDimension | `` | `MyGUI::IntCoord` | `SquadManagementScreen::SquadCellView.getCellDimension()`<br>`obj:getCellDimension()` |

## SquadManagementScreen::SquadData
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.SquadData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| platoon | `ActivePlatoon` | RW | `obj.platoon = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setName | `name: string` | `void` | `obj:setName(name)` |
| getName | `` | `void` | `obj:getName()` |

## SquadManagementScreen::SquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.SquadItemBox`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setCellSize | `width: integer, height: integer` | `void` | `obj:setCellSize(width, height)` |
| getItemCount | `` | `integer` | `obj:getItemCount()` |

## StorageBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`
**Metatable:** `KenshiLua.StorageBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| specialItemTypesOnly | `itemType` | RW | `obj.specialItemTypesOnly = <value>` |
| endOfTheLine | `boolean` | RW | `obj.endOfTheLine = <value>` |
| productionItem | `StorageBuilding::ConsumptionItem` | RW | `obj.productionItem = <value>` |
| manyLimitItems | `lektor<StorageBuilding::ConsumptionItem*>` | RW | `obj.manyLimitItems = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| update | `` | `void` | `obj:update()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| getProductionItemData | `` | `GameData` | `obj:getProductionItemData()` |
| getProductionItem | `` | `lightuserdata` | `obj:getProductionItem()` |
| getCurrentProductionQuantity | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| isAnyInputsFull | `` | `boolean` | `obj:isAnyInputsFull()` |
| isProductionFull | `` | `boolean` | `obj:isProductionFull()` |
| isProductionEmpty | `` | `boolean` | `obj:isProductionEmpty()` |
| getNumConsumtionItems | `` | `integer` | `obj:getNumConsumtionItems()` |
| getConsumtionItems | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| limitedByType | `` | `boolean` | `obj:limitedByType()` |
| updateInventoryWindow | `` | `void` | `obj:updateInventoryWindow()` |
| getItemsWeWantRidOf | `forceLooting: boolean` | `void` | `obj:getItemsWeWantRidOf(forceLooting)` |
| canHaveSomeOfThese | `input: GameData` | `boolean` | `obj:canHaveSomeOfThese(input)` |
| getResourcesNeededBecauseEmpty | `` | `void` | `obj:getResourcesNeededBecauseEmpty()` |
| getResourcesNeededBecauseNotFull | `` | `void` | `obj:getResourcesNeededBecauseNotFull()` |
| getConsumtionItems_inStock | `` | `void` | `obj:getConsumtionItems_inStock()` |

## StorageBuilding::ConsumptionItem
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`
**Parent Class:** [`StorageBuilding`](#storagebuilding)
**Metatable:** `KenshiLua.ConsumptionItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| amount | `number` | RW | `obj.amount = <value>` |
| rate | `number` | RW | `obj.rate = <value>` |
| maxCapacity | `integer` | RW | `obj.maxCapacity = <value>` |
| item | `GameData` | RW | `obj.item = <value>` |
| inventorySection | `InventorySection` | RW | `obj.inventorySection = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isFull | `` | `boolean` | `obj:isFull()` |
| isEmpty | `` | `boolean` | `obj:isEmpty()` |

## StringPair
**Header:** `extern/KenshiLib/Include/kenshi/util/StringPair.h`
**Metatable:** `KenshiLua.StringPair`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| s1 | `string` | RW | `obj.s1 = <value>` |
| s2 | `string` | RW | `obj.s2 = <value>` |
| val1 | `number` | RW | `obj.val1 = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: StringPair` | `void` | `obj:operator_assign(other)` |

## Sword
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Sword`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cutDamage | `number` | RW | `obj.cutDamage = <value>` |
| bluntDamage | `number` | RW | `obj.bluntDamage = <value>` |
| minCutDamage | `number` | RW | `obj.minCutDamage = <value>` |
| modDefence | `integer` | RW | `obj.modDefence = <value>` |
| modIndoors | `integer` | RW | `obj.modIndoors = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getClassType | `` | `integer` | `obj:getClassType()` |
| isSword | `` | `Sword` | `obj:isSword()` |
| setupStats | `_level: integer, baseData: GameData, companyData: GameData, materialData: GameData` | `void` | `obj:setupStats(_level, baseData, companyData, materialData)` |
| getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| getTooltipData1 | `` | `void` | `obj:getTooltipData1()` |
| getTooltipData2 | `` | `void` | `obj:getTooltipData2()` |

## TagsClass
**Header:** `extern/KenshiLib/Include/kenshi/util/TagsClass.h`
**Metatable:** `KenshiLua.TagsClass`

## TaskData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`
**Metatable:** `KenshiLua.TaskData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| infrequentGoalChecks | `boolean` | RW | `obj.infrequentGoalChecks = <value>` |
| permaJob_FixedTarget | `boolean` | RW | `obj.permaJob_FixedTarget = <value>` |
| permaJob_Associated | `TaskType` | RW | `obj.permaJob_Associated = <value>` |
| permaJob_Associated_Secondary | `TaskType` | RW | `obj.permaJob_Associated_Secondary = <value>` |
| requirementsAlwaysFalse | `boolean` | RW | `obj.requirementsAlwaysFalse = <value>` |
| _resultsAlwaysFalse | `boolean` | RW | `obj._resultsAlwaysFalse = <value>` |
| _requirementsCantEndActionPrematurely | `boolean` | RW | `obj._requirementsCantEndActionPrematurely = <value>` |
| durationMin | `number` | RW | `obj.durationMin = <value>` |
| durationFuzz | `number` | RW | `obj.durationFuzz = <value>` |
| isDurationBased | `boolean` | RW | `obj.isDurationBased = <value>` |
| endsAfterTime | `boolean` | RW | `obj.endsAfterTime = <value>` |
| isUnstoppableTask | `boolean` | RW | `obj.isUnstoppableTask = <value>` |
| canDoTaskInStages | `boolean` | RW | `obj.canDoTaskInStages = <value>` |
| aggressionLevel | `number` | RW | `obj.aggressionLevel = <value>` |
| noisyness | `number` | RW | `obj.noisyness = <value>` |
| aidLevel | `number` | RW | `obj.aidLevel = <value>` |
| followMeWeight | `number` | RW | `obj.followMeWeight = <value>` |
| copyMeInfluence | `number` | RW | `obj.copyMeInfluence = <value>` |
| normallyLeadsToSomething | `boolean` | RW | `obj.normallyLeadsToSomething = <value>` |
| alertnessMult | `number` | RW | `obj.alertnessMult = <value>` |
| forDirectPlayerOrdersOnly | `boolean` | RW | `obj.forDirectPlayerOrdersOnly = <value>` |
| forFulfillPlayerOrdersOrNPCOnly | `boolean` | RW | `obj.forFulfillPlayerOrdersOrNPCOnly = <value>` |
| key | `TaskType` | RW | `obj.key = <value>` |
| needsTarget | `boolean` | RW | `obj.needsTarget = <value>` |
| numResults | `integer` | RW | `obj.numResults = <value>` |
| results | `unknown` | RW | `obj.results = <value>` |
| numRequirements | `integer` | RW | `obj.numRequirements = <value>` |
| requirements | `unknown` | RW | `obj.requirements = <value>` |
| scoreFunction | `lightuserdata` | R | `obj.scoreFunction` |
| justDoOneTarget | `boolean` | RW | `obj.justDoOneTarget = <value>` |
| subTask | `TaskStateData` | RW | `obj.subTask = <value>` |
| dialogueDelivery | `EventTriggerEnum` | RW | `obj.dialogueDelivery = <value>` |
| hasAction | `boolean` | RW | `obj.hasAction = <value>` |
| description | `string` | RW | `obj.description = <value>` |
| _findTarget | `lightuserdata` | R | `obj._findTarget` |
| permaJob | `PermajobType` | RW | `obj.permaJob = <value>` |

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
| getPermaJobAssociation | `` | `TaskType` | `obj:getPermaJobAssociation()` |
| getPermaJobAssociation_secondary | `` | `TaskType` | `obj:getPermaJobAssociation_secondary()` |
| isTargetFinder | `` | `boolean` | `obj:isTargetFinder()` |
| setDialogueDeliveryTag | `d: EventTriggerEnum` | `void` | `obj:setDialogueDeliveryTag(d)` |
| setPermaJob | `on: PermajobType, fixedTarget: boolean, t: TaskType, secondary: TaskType` | `void` | `obj:setPermaJob(on, fixedTarget, t, secondary)` |
| getPermaJobType | `` | `PermajobType` | `obj:getPermaJobType()` |

## Tasker
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`
**Metatable:** `KenshiLua.Tasker`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| resetsWhenDone | `boolean` | RW | `obj.resetsWhenDone = <value>` |
| subject | `hand` | RW | `obj.subject = <value>` |
| weight | `number` | RW | `obj.weight = <value>` |
| currentSubTarget | `hand` | RW | `obj.currentSubTarget = <value>` |
| location | `Vector3` | RW | `obj.location = <value>` |
| startTime | `integer` | RW | `obj.startTime = <value>` |
| endTime | `integer` | RW | `obj.endTime = <value>` |
| taskData | `TaskData` | RW | `obj.taskData = <value>` |
| priority | `taskPriority` | RW | `obj.priority = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| checkTimeOfDay | `` | `boolean` | `obj:checkTimeOfDay()` |
| getFrameTime | `b: CharBody` | `number` | `obj:getFrameTime(b)` |
| key | `` | `TaskType` | `obj:key()` |
| unSkippableJob | `` | `boolean` | `obj:unSkippableJob()` |
| getLocation | `` | `Vector3` | `obj:getLocation()` |
| setLocation | `loc: Vector3` | `void` | `obj:setLocation(loc)` |
| sameAs | `t: Tasker` | `boolean` | `obj:sameAs(t)` |
| getDescription | `` | `void` | `obj:getDescription()` |
| hasActionFunc | `` | `boolean` | `obj:hasActionFunc()` |
| isSubTasker | `` | `boolean` | `obj:isSubTasker()` |
| getSubTask | `` | `TaskStateData` | `obj:getSubTask()` |
| isInfiniteGoal | `` | `boolean` | `obj:isInfiniteGoal()` |
| needsSubjectOrLocation | `` | `boolean` | `obj:needsSubjectOrLocation()` |
| getTaskData | `` | `TaskData` | `obj:getTaskData()` |
| startAction | `_a1: CharBody` | `void` | `obj:startAction(_a1)` |
| runAction | `_a1: CharBody` | `void` | `obj:runAction(_a1)` |
| endAction | `_a1: CharBody` | `void` | `obj:endAction(_a1)` |
| taskSaysItsFinished | `me: Character` | `boolean` | `obj:taskSaysItsFinished(me)` |
| score | `ai: userdata` | `number` | `obj:score(ai)` |
| isResultsComplete | `ai: userdata` | `boolean` | `obj:isResultsComplete(ai)` |
| isResultsComplete_ignoreSubtasker | `ai: userdata` | `boolean` | `obj:isResultsComplete_ignoreSubtasker(ai)` |
| isRequirementsComplete | `ai: userdata, autoTargetFinder: boolean` | `boolean` | `obj:isRequirementsComplete(ai, autoTargetFinder)` |
| getRequirementComplaint | `ai: userdata, autoTargetFinder: boolean` | `string` | `obj:getRequirementComplaint(ai, autoTargetFinder)` |
| getNextSubTarget | `ai: userdata` | `hand` | `obj:getNextSubTarget(ai)` |

## TaskStateData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`
**Metatable:** `KenshiLua.TaskStateData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| val | `boolean` | RW | `obj.val = <value>` |
| progressionOnly | `boolean` | RW | `obj.progressionOnly = <value>` |
| key | `StateType` | RW | `obj.key = <value>` |

## Terrain
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Metatable:** `KenshiLua.Terrain`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mCamera | `lightuserdata` | RW | `obj.mCamera = <value>` |
| mCameraPosition | `Vector3` | RW | `obj.mCameraPosition = <value>` |
| mStream | `lightuserdata` | R | `obj.mStream` |
| mTerrain | `lightuserdata` | R | `obj.mTerrain` |
| mSize | `number` | RW | `obj.mSize = <value>` |
| mHeight | `number` | RW | `obj.mHeight = <value>` |
| mHeightScale | `number` | RW | `obj.mHeightScale = <value>` |
| mOffset | `number` | RW | `obj.mOffset = <value>` |
| mSizeScale | `number` | RW | `obj.mSizeScale = <value>` |
| mBuildCounter | `integer` | RW | `obj.mBuildCounter = <value>` |
| mNeedsBuilding | `boolean` | RW | `obj.mNeedsBuilding = <value>` |
| mPatchesToBuild | `integer` | RW | `obj.mPatchesToBuild = <value>` |
| mOnscreenLimit | `integer` | RW | `obj.mOnscreenLimit = <value>` |
| mOffscreenLimit | `integer` | RW | `obj.mOffscreenLimit = <value>` |
| mDrawableCount | `integer` | RW | `obj.mDrawableCount = <value>` |
| mMaterialDistance | `number` | RW | `obj.mMaterialDistance = <value>` |
| mHeightCacheSize | `integer` | RW | `obj.mHeightCacheSize = <value>` |
| mHeightCacheBox | `lightuserdata` | RW | `obj.mHeightCacheBox = <value>` |
| mCachePositionX | `integer` | RW | `obj.mCachePositionX = <value>` |
| mCachePositionY | `integer` | RW | `obj.mCachePositionY = <value>` |
| mHeightCache | `lightuserdata` | RW | `obj.mHeightCache = <value>` |
| mBloodCamera | `lightuserdata` | R | `obj.mBloodCamera` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getBoundingRadius | `` | `number` | `obj:getBoundingRadius()` |
| getMovableType | `` | `void` | `obj:getMovableType()` |

## Terrain::BloodQueue
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Parent Class:** [`Terrain`](#terrain)
**Metatable:** `KenshiLua.Terrain_BloodQueue`

## Terrain::Box
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Parent Class:** [`Terrain`](#terrain)
**Metatable:** `KenshiLua.Terrain_Box`

## Terrain::Hit
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Parent Class:** [`Terrain`](#terrain)
**Metatable:** `KenshiLua.Terrain_Hit`

## Terrain::Info
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Parent Class:** [`Terrain`](#terrain)
**Metatable:** `KenshiLua.Terrain_Info`

## ThreadClass
**Header:** `extern/KenshiLib/Include/kenshi/ThreadClass.h`
**Metatable:** `KenshiLua.ThreadClass`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| threadHandle | `lightuserdata` | R | `obj.threadHandle` |
| threadID | `integer` | RW | `obj.threadID = <value>` |
| _running | `boolean` | RW | `obj._running = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| frameTime | `number` | RW | `obj.frameTime = <value>` |
| infiniteMode | `boolean` | RW | `obj.infiniteMode = <value>` |
| pretendThread | `boolean` | RW | `obj.pretendThread = <value>` |
| runMute | `lightuserdata` | R | `obj.runMute` |
| lockedWhileRunningMute | `lightuserdata` | R | `obj.lockedWhileRunningMute` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| stopRunning | `` | `void` | `obj:stopRunning()` |
| canIRun | `` | `boolean` | `obj:canIRun()` |
| startRunning | `time: number` | `boolean` | `obj:startRunning(time)` |
| isRunning | `` | `boolean` | `obj:isRunning()` |
| waitForRunningStop_Blocking | `` | `boolean` | `obj:waitForRunningStop_Blocking()` |
| setup | `_frameTime: number, infinite: boolean, _pretendThread: boolean` | `void` | `obj:setup(_frameTime, infinite, _pretendThread)` |
| beginThread | `_frameTime: number, infinite: boolean, priority: integer` | `boolean` | `obj:beginThread(_frameTime, infinite, priority)` |
| setThreadName | `threadName: string` | `void` | `obj:setThreadName(threadName)` |
| endThread | `` | `void` | `obj:endThread()` |
| setName | `name: string` | `void` | `obj:setName(name)` |
| threadProc | `` | `integer` | `obj:threadProc()` |

## ThreadWannabe
**Header:** `extern/KenshiLib/Include/kenshi/ThreadClass.h`
**Metatable:** `KenshiLua.ThreadWannabe`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mute | `lightuserdata` | R | `obj.mute` |
| paused | `boolean` | RW | `obj.paused = <value>` |
| speedMult | `number` | RW | `obj.speedMult = <value>` |
| haltEverythingMutex | `lightuserdata` | R | `obj.haltEverythingMutex` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| backThreadUpdate | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| isPaused | `` | `boolean` | `obj:isPaused()` |
| setPaused | `on: boolean, _speedMult: number` | `void` | `obj:setPaused(on, _speedMult)` |
| threadProc | `` | `integer` | `obj:threadProc()` |
| forceLoopMT | `` | `void` | `obj:forceLoopMT()` |

## TimeOfDay
**Header:** `extern/KenshiLib/Include/kenshi/util/TimeOfDay.h`
**Metatable:** `KenshiLua.TimeOfDay`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| time | `number` | RW | `obj.time = <value>` |

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
| operator_gt | `` | `boolean` | `obj:operator_gt()` |
| operator_ge | `` | `boolean` | `obj:operator_ge()` |
| operator_lt | `` | `boolean` | `obj:operator_lt()` |
| operator_le | `` | `boolean` | `obj:operator_le()` |
| operator_eq | `b: TimeOfDay` | `boolean` | `obj:operator_eq(b)` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## TimerClass
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`
**Metatable:** `KenshiLua.TimerClass`

## TitleScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/TitleScreen.h`
**Metatable:** `KenshiLua.TitleScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| newGameWindow | `NewGameWindow` | RW | `obj.newGameWindow = <value>` |
| creditsPanel | `MyGUI::Widget` | RW | `obj.creditsPanel = <value>` |
| creditsText | `MyGUI::Widget` | RW | `obj.creditsText = <value>` |
| creditsLoaded | `boolean` | RW | `obj.creditsLoaded = <value>` |
| creditsPosition | `number` | RW | `obj.creditsPosition = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| show | `on: boolean` | `void` | `obj:show(on)` |
| update | `` | `void` | `obj:update()` |
| closeTheOtherBits | `` | `boolean` | `obj:closeTheOtherBits()` |
| setCreditsVisible | `value: boolean` | `void` | `obj:setCreditsVisible(value)` |
| loadGame | `sender: MyGUI::Widget` | `void` | `obj:loadGame(sender)` |
| importGame | `sender: MyGUI::Widget` | `void` | `obj:importGame(sender)` |
| showOptions | `sender: MyGUI::Widget` | `void` | `obj:showOptions(sender)` |
| credits | `sender: MyGUI::Widget` | `void` | `obj:credits(sender)` |
| exitGame | `sender: MyGUI::Widget` | `void` | `obj:exitGame(sender)` |
| continueGame | `sender: MyGUI::Widget` | `void` | `obj:continueGame(sender)` |
| hover | `sender: MyGUI::Widget, a2: MyGUI::Widget` | `void` | `obj:hover(sender, a2)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `TitleScreen` | `TitleScreen.getSingleton()`<br>`obj:getSingleton()` |

## ToolTip
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTip`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| panel | `MyGUI::Widget` | RW | `obj.panel = <value>` |
| panelWidth | `integer` | RW | `obj.panelWidth = <value>` |
| lineMarginH | `number` | RW | `obj.lineMarginH = <value>` |
| panelMarginV | `integer` | RW | `obj.panelMarginV = <value>` |
| lineSpacing | `integer` | RW | `obj.lineSpacing = <value>` |
| caller | `MyGUI::Widget` | R | `obj.caller` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| hide | `` | `void` | `obj:hide()` |
| getVisible | `` | `boolean` | `obj:getVisible()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| addLine | `textLeft: string, textRight: string` | `void` | `obj:addLine(textLeft, textRight)` |
| clearLines | `` | `void` | `obj:clearLines()` |
| setup_hand | `widget: MyGUI::Widget, data: hand` | `void` | `obj:setup_hand(widget, data)` |
| setup_gamedata | `widget: MyGUI::Widget, data: GameData` | `void` | `obj:setup_gamedata(widget, data)` |
| setup_stringpairs | `widget: MyGUI::Widget` | `void` | `obj:setup_stringpairs(widget)` |
| setup_text | `widget: MyGUI::Widget, text: string` | `void` | `obj:setup_text(widget, text)` |
| clear | `widget: MyGUI::Widget` | `void` | `obj:clear(widget)` |
| _setup | `widget: MyGUI::Widget` | `void` | `obj:_setup(widget)` |
| clearData | `widget: MyGUI::Widget` | `void` | `obj:clearData(widget)` |
| show | `sender: MyGUI::Widget` | `void` | `obj:show(sender)` |
| setContent | `widget: MyGUI::Widget` | `void` | `obj:setContent(widget)` |
| showText | `widget: MyGUI::Widget` | `void` | `obj:showText(widget)` |
| showMultiLine | `widget: MyGUI::Widget` | `void` | `obj:showMultiLine(widget)` |
| showGameData_hand | `h: hand` | `void` | `obj:showGameData_hand(h)` |
| showGameData_widget | `widget: MyGUI::Widget` | `void` | `obj:showGameData_widget(widget)` |
| setPosition | `` | `void` | `obj:setPosition()` |

## ToolTip::ToolTipLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Parent Class:** [`ToolTip`](#tooltip)
**Metatable:** `KenshiLua.ToolTipLine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| content | `MyGUI::Widget` | RW | `obj.content = <value>` |
| leftBox | `MyGUI::Widget` | RW | `obj.leftBox = <value>` |
| rightBox | `MyGUI::Widget` | RW | `obj.rightBox = <value>` |
| width | `integer` | RW | `obj.width = <value>` |

## ToolTipDynamic
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipDynamic`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| setPosition | `` | `void` | `obj:setPosition()` |

## ToolTipFixed
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipFixed`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentPanel | `MyGUI::Widget` | RW | `obj.parentPanel = <value>` |
| minHeight | `integer` | RW | `obj.minHeight = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| clear | `widget: MyGUI::Widget` | `void` | `obj:clear(widget)` |
| setBottomPosition | `` | `void` | `obj:setBottomPosition()` |
| setPosition | `` | `void` | `obj:setPosition()` |
| _setup | `widget: MyGUI::Widget` | `void` | `obj:_setup(widget)` |
| mouseMoved | `sender: MyGUI::Widget, left: integer, top: integer` | `void` | `obj:mouseMoved(sender, left, top)` |

## ToolTipInventory
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipInventory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| compareTooltip | `ToolTipInventory` | RW | `obj.compareTooltip = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| _setup | `widget: MyGUI::Widget` | `void` | `obj:_setup(widget)` |
| setup | `widget: MyGUI::Widget` | `void` | `obj:setup(widget)` |
| show | `sender: MyGUI::Widget` | `void` | `obj:show(sender)` |
| setContent | `widget: MyGUI::Widget` | `void` | `obj:setContent(widget)` |
| clearData | `widget: MyGUI::Widget` | `void` | `obj:clearData(widget)` |
| mouseMoved | `sender: MyGUI::Widget, left: integer, top: integer` | `void` | `obj:mouseMoved(sender, left, top)` |
| setPosition | `` | `void` | `obj:setPosition()` |

## ToolTipStatic
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipStatic`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| update | `` | `void` | `obj:update()` |
| setVisible | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| clear | `widget: MyGUI::Widget` | `void` | `obj:clear(widget)` |
| _setup | `widget: MyGUI::Widget` | `void` | `obj:_setup(widget)` |
| setPosition | `` | `void` | `obj:setPosition()` |
| mouseMoved | `sender: MyGUI::Widget, left: integer, top: integer` | `void` | `obj:mouseMoved(sender, left, top)` |

## TortureBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TortureBuilding.h`
**Metatable:** `KenshiLua.TortureBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timer | `number` | RW | `obj.timer = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getFunctionStuff | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| update | `` | `void` | `obj:update()` |

## Town
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Metatable:** `KenshiLua.Town`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| replacementTown | `GameData` | RW | `obj.replacementTown = <value>` |
| isAccessible | `boolean` | RW | `obj.isAccessible = <value>` |
| alarms | `lightuserdata` | RW | `obj.alarms = <value>` |
| instanceID | `InstanceID` | RW | `obj.instanceID = <value>` |
| openToPublic | `boolean` | RW | `obj.openToPublic = <value>` |
| minFoliageRange | `number` | RW | `obj.minFoliageRange = <value>` |
| playerTownLevel | `integer` | RW | `obj.playerTownLevel = <value>` |
| playerHasBuildingsInThisTown | `boolean` | RW | `obj.playerHasBuildingsInThisTown = <value>` |
| batteryMode | `boolean` | RW | `obj.batteryMode = <value>` |
| power_Stat | `number` | RW | `obj.power_Stat = <value>` |
| maxPower_Stat | `number` | RW | `obj.maxPower_Stat = <value>` |
| neededPowerTotal_Stat | `number` | RW | `obj.neededPowerTotal_Stat = <value>` |
| batteryPowerTotal_Stat | `number` | RW | `obj.batteryPowerTotal_Stat = <value>` |
| batteryDrain_Stat | `number` | RW | `obj.batteryDrain_Stat = <value>` |
| batteryChargingupTotal | `number` | RW | `obj.batteryChargingupTotal = <value>` |
| batteryCharge_Stat | `number` | RW | `obj.batteryCharge_Stat = <value>` |
| batteryChargeMax_Stat | `number` | RW | `obj.batteryChargeMax_Stat = <value>` |
| tradeCulture | `TradeCulture` | RW | `obj.tradeCulture = <value>` |
| buildingMaterial | `GameData` | RW | `obj.buildingMaterial = <value>` |
| distantTown | `lightuserdata` | RW | `obj.distantTown = <value>` |
| nestsLoaded | `boolean` | RW | `obj.nestsLoaded = <value>` |
| overrideRange | `number` | RW | `obj.overrideRange = <value>` |
| townRangeMultiplier | `number` | RW | `obj.townRangeMultiplier = <value>` |
| _facilitesWeHaveHere | `integer` | RW | `obj._facilitesWeHaveHere = <value>` |
| batteryList | `ogre_unordered_set<hand>::type` | RW | `obj.batteryList = <value>` |
| gates | `ogre_unordered_set<hand>::type` | RW | `obj.gates = <value>` |
| nestSpots | `Vector3` | RW | `obj.nestSpots = <value>` |
| powerInList | `Ogre::FastArray<hand>` | RW | `obj.powerInList = <value>` |
| powerOutList | `ogre_unordered_set<hand>::type` | RW | `obj.powerOutList = <value>` |
| tradeGoodsMults | `ogre_unordered_map<GameData*, float>::type` | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| facilitesWeHaveHere | `` | `TagsClass<BuildingDesignation>` | `obj:facilitesWeHaveHere()` |
| initialiseResidentData | `` | `void` | `obj:initialiseResidentData()` |
| getGameData | `` | `GameData` | `obj:getGameData()` |
| getOriginalGameData | `` | `GameData` | `obj:getOriginalGameData()` |
| notifyRepopulation | `newTowndata: GameData` | `void` | `obj:notifyRepopulation(newTowndata)` |
| isMyOldHomeTownStillValid | `myHomeTown: GameData` | `boolean` | `obj:isMyOldHomeTownStillValid(myHomeTown)` |
| setup | `_town: GameData, _pos: Vector3, h: hand` | `void` | `obj:setup(_town, _pos, h)` |
| _reset | `` | `void` | `obj:_reset()` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| showDistantTown | `vis: boolean` | `void` | `obj:showDistantTown(vis)` |
| getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| isOutpost | `` | `boolean` | `obj:isOutpost()` |
| _setMainResident | `building: Building, residents: GameData, forceForGates: boolean` | `boolean` | `obj:_setMainResident(building, residents, forceForGates)` |
| spawnTheBarFlies | `` | `void` | `obj:spawnTheBarFlies()` |
| townLoadedEvent | `newGameFirstTime: boolean` | `void` | `obj:townLoadedEvent(newGameFirstTime)` |
| notifyUnloading | `` | `void` | `obj:notifyUnloading()` |
| getBuildingMaterial | `` | `GameData` | `obj:getBuildingMaterial()` |
| getLocalTradePriceMult | `item: GameData` | `number` | `obj:getLocalTradePriceMult(item)` |
| getFactionTradeCultureMult | `item: GameData` | `number` | `obj:getFactionTradeCultureMult(item)` |
| isTown | `` | `Town` | `obj:isTown()` |
| isNest | `` | `lightuserdata` | `obj:isNest()` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| getGUIData | `panel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(panel, category)` |
| saveState | `state: GameData` | `void` | `obj:saveState(state)` |
| loadState | `state: GameData` | `void` | `obj:loadState(state)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| needsSaving | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| setPosition | `p: Vector3` | `void` | `obj:setPosition(p)` |
| saveStateEditor | `state: GameData` | `void` | `obj:saveStateEditor(state)` |
| loadStateEditor | `state: GameData` | `void` | `obj:loadStateEditor(state)` |
| getRadius | `` | `number` | `obj:getRadius()` |
| isActive | `` | `boolean` | `obj:isActive()` |
| update | `` | `void` | `obj:update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| hasResidentHQ | `f: Faction` | `boolean` | `obj:hasResidentHQ(f)` |
| gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| hasGates | `` | `boolean` | `obj:hasGates()` |
| notifyAccesibility | `accessible: boolean` | `void` | `obj:notifyAccesibility(accessible)` |
| getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| addBuilding | `b: UseableStuff, powerIn: boolean, powerOut: boolean, battery: boolean` | `void` | `obj:addBuilding(b, powerIn, powerOut, battery)` |
| removeBuilding | `b: UseableStuff` | `void` | `obj:removeBuilding(b)` |
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
| addNest | `nestInfo: GameData, pos: Vector3, keepInside: Building` | `void` | `obj:addNest(nestInfo, pos, keepInside)` |
| removeNest | `b: Building` | `boolean` | `obj:removeNest(b)` |
| clearNests | `` | `void` | `obj:clearNests()` |
| getMapMarker | `` | `string` | `obj:getMapMarker()` |
| getMapMarkerZoomLevel | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| recalculatePlayerTownLevel | `` | `void` | `obj:recalculatePlayerTownLevel()` |
| deActivationCheck | `` | `void` | `obj:deActivationCheck()` |
| _initialiseResidentData | `residentSourceData: GameData` | `void` | `obj:_initialiseResidentData(residentSourceData)` |
| chooseResidents | `` | `void` | `obj:chooseResidents()` |
| chooseBuildingForResident | `resident: TownBase::ResidentData` | `Building` | `obj:chooseBuildingForResident(resident)` |
| addGate | `g: hand` | `void` | `obj:addGate(g)` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| getPlayerTownTypeEnum | `` | `TownType` | `obj:getPlayerTownTypeEnum()` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |

## Town::NestSpot
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`Town`](#town)
**Metatable:** `KenshiLua.Town_NestSpot`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## TownBase
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Metatable:** `KenshiLua.TownBase`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| positionCacher | `TownPositionCacher` | RW | `obj.positionCacher = <value>` |
| population | `lightuserdata` | RW | `obj.population = <value>` |
| alreadyInitialisedPopulationParams | `boolean` | RW | `obj.alreadyInitialisedPopulationParams = <value>` |
| isSecret | `boolean` | RW | `obj.isSecret = <value>` |
| timeOfDeath | `TimeOfDay` | RW | `obj.timeOfDeath = <value>` |
| p_TIME | `number` | RW | `obj.p_TIME = <value>` |
| nestBatcher | `lightuserdata` | RW | `obj.nestBatcher = <value>` |
| unexploredName | `string` | RW | `obj.unexploredName = <value>` |
| discovered | `boolean` | RW | `obj.discovered = <value>` |
| explored | `boolean` | RW | `obj.explored = <value>` |
| recentlyDiscovered | `boolean` | RW | `obj.recentlyDiscovered = <value>` |
| entityMarker | `lightuserdata` | RW | `obj.entityMarker = <value>` |
| entityLabel | `ScreenLabel` | RW | `obj.entityLabel = <value>` |
| clickHull | `lightuserdata` | RW | `obj.clickHull = <value>` |
| biome | `lightuserdata` | RW | `obj.biome = <value>` |
| isActivated | `boolean` | RW | `obj.isActivated = <value>` |
| currentFloorVisibility | `integer` | RW | `obj.currentFloorVisibility = <value>` |
| buildingsManager | `TownBuildingsManager` | RW | `obj.buildingsManager = <value>` |
| defaultResident | `GameData` | RW | `obj.defaultResident = <value>` |
| alarmState | `TownAlarmState` | RW | `obj.alarmState = <value>` |
| artifacts | `Ogre::FastArray<ArtifactItemData>` | R | `obj.artifacts` |
| factionsResidentHere | `std::set<Faction*>` | RW | `obj.factionsResidentHere = <value>` |
| myZoneCoverage | `ogre_unordered_set<ZoneMap*>::type` | RW | `obj.myZoneCoverage = <value>` |
| occupiers | `std::set<hand>` | RW | `obj.occupiers = <value>` |
| populatedZones | `ogre_unordered_map<ZoneMap*, bool>::type` | RW | `obj.populatedZones = <value>` |
| residentsSpawned | `lektor<TownBase::ResidentData>` | RW | `obj.residentsSpawned = <value>` |
| residentsSpawned_BarsOrSomething | `lektor<TownBase::ResidentData>` | RW | `obj.residentsSpawned_BarsOrSomething = <value>` |
| townType | `integer` | RW | `obj.townType = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| activate | `zone: ZoneMap` | `void` | `obj:activate(zone)` |
| isActive | `` | `boolean` | `obj:isActive()` |
| setup | `_town: GameData, _pos: Vector3, h: hand` | `void` | `obj:setup(_town, _pos, h)` |
| _reset | `` | `void` | `obj:_reset()` |
| getKnownName | `` | `string` | `obj:getKnownName()` |
| reassessTownPosition | `` | `void` | `obj:reassessTownPosition()` |
| isNotFriendly | `` | `boolean` | `obj:isNotFriendly()` |
| isPhysical | `` | `boolean` | `obj:isPhysical()` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| getDataType | `` | `integer` | `obj:getDataType()` |
| isTown | `` | `Town` | `obj:isTown()` |
| isNest | `` | `lightuserdata` | `obj:isNest()` |
| nestUpThisSpot | `nestInfo: GameData, pos: Vector3, keepInside: Building` | `void` | `obj:nestUpThisSpot(nestInfo, pos, keepInside)` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| isOutpost | `` | `boolean` | `obj:isOutpost()` |
| withinBordersRange | `p: Vector3, mult: number` | `boolean` | `obj:withinBordersRange(p, mult)` |
| withinDiscoveryRange | `p: Vector3, explored: boolean` | `boolean` | `obj:withinDiscoveryRange(p, explored)` |
| isIllegal | `what: Item` | `boolean` | `obj:isIllegal(what)` |
| distanceTo | `to: Vector3` | `number` | `obj:distanceTo(to)` |
| squaredDistanceTo | `to: Vector3` | `number` | `obj:squaredDistanceTo(to)` |
| isDead | `` | `boolean` | `obj:isDead()` |
| getPositionOutsideTownGates | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| setFaction | `faction: Faction, _a2: ActivePlatoon` | `void` | `obj:setFaction(faction, _a2)` |
| isPublic | `` | `boolean` | `obj:isPublic()` |
| addGate | `g: hand` | `void` | `obj:addGate(g)` |
| addOccupier | `o: hand` | `void` | `obj:addOccupier(o)` |
| removeOccupier | `o: hand` | `void` | `obj:removeOccupier(o)` |
| getRadius | `` | `number` | `obj:getRadius()` |
| getGUIData | `_a1: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(_a1, category)` |
| saveState | `state: GameData` | `void` | `obj:saveState(state)` |
| loadState | `state: GameData` | `void` | `obj:loadState(state)` |
| update | `` | `void` | `obj:update()` |
| periodicUpdate | `` | `void` | `obj:periodicUpdate()` |
| updatePowerGrid | `` | `void` | `obj:updatePowerGrid()` |
| hasResidentHQ | `f: Faction` | `boolean` | `obj:hasResidentHQ(f)` |
| findAllBuildingsOfType [1] | `me: Character` | `void` | `obj:findAllBuildingsOfType(me)` |
| findAllBuildingsOfType [2] | `func: BuildingDesignation, me: Character` | `lektor<Building*>` | `obj:findAllBuildingsOfType(func, me)` |
| findAllBuildingsWithFunction [1] | `me: Character` | `void` | `obj:findAllBuildingsWithFunction(me)` |
| findAllBuildingsWithFunction [2] | `func: BuildingFunction, me: Character` | `lektor<Building*>` | `obj:findAllBuildingsWithFunction(func, me)` |
| allBuildingsDoorsOpen | `` | `boolean` | `obj:allBuildingsDoorsOpen()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| getPosition | `` | `Vector3` | `obj:getPosition()` |
| getPositionForWaypoint | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| getAlarmMgr | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| hasGates | `` | `boolean` | `obj:hasGates()` |
| gatesAllClosed | `` | `boolean` | `obj:gatesAllClosed()` |
| getNearestGate | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| getBiome | `` | `lightuserdata` | `obj:getBiome()` |
| isRecentlyDiscovered | `` | `boolean` | `obj:isRecentlyDiscovered()` |
| setRecentlyDiscovered | `value: boolean` | `void` | `obj:setRecentlyDiscovered(value)` |
| isDiscovered | `` | `boolean` | `obj:isDiscovered()` |
| setDiscovered | `value: boolean` | `void` | `obj:setDiscovered(value)` |
| setDead | `` | `void` | `obj:setDead()` |
| isExplored | `` | `boolean` | `obj:isExplored()` |
| setExplored | `value: boolean` | `void` | `obj:setExplored(value)` |
| getItemArtifactsMinValue | `` | `integer` | `obj:getItemArtifactsMinValue()` |
| getItemArtifactsMaxValue | `` | `integer` | `obj:getItemArtifactsMaxValue()` |
| getGearArtifactsMinValue | `` | `integer` | `obj:getGearArtifactsMinValue()` |
| getGearArtifactsMaxValue | `` | `integer` | `obj:getGearArtifactsMaxValue()` |
| setZonePopulated | `zoneMap: ZoneMap` | `void` | `obj:setZonePopulated(zoneMap)` |
| getBuildingsManager | `` | `TownBuildingsManager` | `obj:getBuildingsManager()` |
| getBuildingFloorVisibility | `building: Building` | `integer` | `obj:getBuildingFloorVisibility(building)` |
| setBuildingsFloorVisibility | `building: Building, floor: integer` | `void` | `obj:setBuildingsFloorVisibility(building, floor)` |
| resetBuildingsFloorVisibility | `` | `void` | `obj:resetBuildingsFloorVisibility()` |
| getTownFloorVisiblity | `` | `integer` | `obj:getTownFloorVisiblity()` |
| setTownFloorVisiblity | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setTownFloorVisiblity(floor, onlyPlayerBuildings)` |
| resetTownFloorVisibility | `` | `void` | `obj:resetTownFloorVisibility()` |
| getCurrentTownLocation | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| getMapMarker | `` | `string` | `obj:getMapMarker()` |
| getMapMarkerZoomLevel | `` | `MapZoomLevel` | `obj:getMapMarkerZoomLevel()` |
| isOccupied | `` | `boolean` | `obj:isOccupied()` |
| _nestUpThisSpot | `nestInfo: GameData, pos: Vector3, keepInside: Building` | `void` | `obj:_nestUpThisSpot(nestInfo, pos, keepInside)` |
| distributeArtifacts | `` | `void` | `obj:distributeArtifacts()` |
| getUnexploredName | `` | `string` | `obj:getUnexploredName()` |
| getAlarmState | `` | `TownAlarmState` | `obj:getAlarmState()` |
| setAlarmState | `st: TownAlarmState` | `void` | `obj:setAlarmState(st)` |
| setHandle | `h: hand` | `void` | `obj:setHandle(h)` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| getZonesCoverage | `` | `ogre_unordered_set<ZoneMap*>::type` | `obj:getZonesCoverage()` |
| spawnDebris [1] | `keepInside: Building` | `void` | `obj:spawnDebris(keepInside)` |
| spawnDebris [2] | `staticGeometry: userdata, itemData: GameData, materialData: GameData, centerpos: Vector3, range: number, num: integer, scale: number, keepInside: Building, spawnItems: boolean` | `void` | `obj:spawnDebris(staticGeometry, itemData, materialData, centerpos, range, num, scale, keepInside, spawnItems)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| delayedSpawningChecks | `` | `integer` | `TownBase.delayedSpawningChecks()`<br>`obj:delayedSpawningChecks()` |
| clearDelayedItemLoadingMessages | `` | `void` | `TownBase.clearDelayedItemLoadingMessages()`<br>`obj:clearDelayedItemLoadingMessages()` |

## TownBase::DelayedSpawnMsg
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`TownBase`](#townbase)
**Metatable:** `KenshiLua.DelayedSpawnMsg`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentTown | `hand` | RW | `obj.parentTown = <value>` |
| item | `Item` | RW | `obj.item = <value>` |
| nestData | `GameData` | RW | `obj.nestData = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| insideBuilding | `hand` | RW | `obj.insideBuilding = <value>` |

## TownBase::ResidentData
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`TownBase`](#townbase)
**Metatable:** `KenshiLua.TownBase_ResidentData`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq | `` | `boolean` | `obj:operator_eq()` |
| operator_assign | `` | `void` | `obj:operator_assign()` |

## TownBase::TownPositionCacher
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`TownBase`](#townbase)
**Metatable:** `KenshiLua.TownPositionCacher`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lastUpdateStamp | `TimeOfDay` | RW | `obj.lastUpdateStamp = <value>` |
| updateRateInHours | `number` | RW | `obj.updateRateInHours = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| stampUpdate | `` | `void` | `obj:stampUpdate()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |

## TownBuildingsManager
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Metatable:** `KenshiLua.TownBuildingsManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| signsVisible | `boolean` | RW | `obj.signsVisible = <value>` |
| town | `TownBase` | RW | `obj.town = <value>` |
| buildingEntities | `OgreUnorderedMapBinding<Building*, TownBuildingsManager::BuildingInfo>::MapType` | RW | `obj.buildingEntities = <value>` |
| instancesManagers | `boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >` | R | `obj.instancesManagers` |
| signs | `Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >` | R | `obj.signs` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| moveBuildingsTo | `to: TownBuildingsManager` | `void` | `obj:moveBuildingsTo(to)` |
| removeBuilding | `building: Building` | `void` | `obj:removeBuilding(building)` |
| setFloorVisible | `building: Building, floor: integer` | `void` | `obj:setFloorVisible(building, floor)` |
| setAllVisible | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setAllVisible(floor, onlyPlayerBuildings)` |
| resetAllVisible | `` | `void` | `obj:resetAllVisible()` |
| setSignsVisible | `value: boolean` | `void` | `obj:setSignsVisible(value)` |
| factoryObjectCreatedCallback | `_a1: RootObject` | `void` | `obj:factoryObjectCreatedCallback(_a1)` |
| getFloorVisible [1] | `building: Building` | `integer` | `obj:getFloorVisible(building)` |
| getFloorVisible [2] | `building: Building, floor: integer` | `boolean` | `obj:getFloorVisible(building, floor)` |

## TownBuildingsManager::BuildingInfo
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`TownBuildingsManager`](#townbuildingsmanager)
**Metatable:** `KenshiLua.TownBuildingsManager_BuildingInfo`

## TradeCulture
**Header:** `extern/KenshiLib/Include/kenshi/TradeCulture.h`
**Metatable:** `KenshiLua.TradeCulture`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| forbiddenItems | `lektor<GameData*>` | RW | `obj.forbiddenItems = <value>` |
| illegalBuildings | `StdSetBinding<GameData*>::SetType` | RW | `obj.illegalBuildings = <value>` |
| happyBuildings | `StdSetBinding<GameData*>::SetType` | RW | `obj.happyBuildings = <value>` |
| illegalItems | `StdSetBinding<GameData*>::SetType` | RW | `obj.illegalItems = <value>` |
| tradeGoodsMults | `StdMapBinding<GameData*, float>::MapType` | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| getAllIllegalItems | `` | `StdSetBinding<GameData*>::SetType` | `obj:getAllIllegalItems()` |
| isItemIllegal | `item: GameData` | `boolean` | `obj:isItemIllegal(item)` |
| getTradePriceMultiplier | `item: GameData` | `number` | `obj:getTradePriceMultiplier(item)` |
| hasTradePriceMultiplier | `item: GameData` | `boolean` | `obj:hasTradePriceMultiplier(item)` |
| getForbiddenItemsList | `` | `lektor<GameData*>` | `obj:getForbiddenItemsList()` |

## TraderInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.TraderInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| scrollBackpack | `MyGUI::Widget` | R | `obj.scrollBackpack` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupSections | `gui: InventoryGUI, sections: userdata, inv: Inventory` | `void` | `obj:setupSections(gui, sections, inv)` |
| notifyMouseWheel | `widget: MyGUI::Widget, rel: integer` | `void` | `obj:notifyMouseWheel(widget, rel)` |

## TransformWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/TransformWindow.h`
**Metatable:** `KenshiLua.TransformWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | `DatapanelGUI` | RW | `obj.window = <value>` |
| windowXValue | `DataPanelLine_TextEditable` | RW | `obj.windowXValue = <value>` |
| windowYValue | `DataPanelLine_TextEditable` | RW | `obj.windowYValue = <value>` |
| windowZValue | `DataPanelLine_TextEditable` | RW | `obj.windowZValue = <value>` |
| modeButton | `DataPanelLine_Button` | RW | `obj.modeButton = <value>` |
| axisButton | `DataPanelLine_Button` | RW | `obj.axisButton = <value>` |
| revertButton | `DataPanelLine_Button` | RW | `obj.revertButton = <value>` |
| node | `lightuserdata` | RW | `obj.node = <value>` |
| parentNode | `lightuserdata` | RW | `obj.parentNode = <value>` |
| gizmo | `lightuserdata` | RW | `obj.gizmo = <value>` |
| mode | `integer` | RW | `obj.mode = <value>` |
| coordinateSystem | `integer` | RW | `obj.coordinateSystem = <value>` |
| hasScale | `boolean` | RW | `obj.hasScale = <value>` |
| lastZone | `ZoneMap` | RW | `obj.lastZone = <value>` |
| currentZone | `ZoneMap` | RW | `obj.currentZone = <value>` |
| currentInstance | `InstanceID` | RW | `obj.currentInstance = <value>` |
| changed | `boolean` | RW | `obj.changed = <value>` |
| editChanged | `boolean` | RW | `obj.editChanged = <value>` |
| lastMouse | `Vector2` | RW | `obj.lastMouse = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setCaption | `s: string` | `void` | `obj:setCaption(s)` |
| updateState | `id: InstanceID` | `void` | `obj:updateState(id)` |
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
| changeMode | `line: DataPanelLine` | `void` | `obj:changeMode(line)` |
| changeCoord | `line: DataPanelLine` | `void` | `obj:changeCoord(line)` |
| changeValue | `line: DataPanelLine` | `void` | `obj:changeValue(line)` |
| reset | `_a1: DataPanelLine` | `void` | `obj:reset(_a1)` |
| revert | `_a1: DataPanelLine` | `void` | `obj:revert(_a1)` |
| confirmValue | `w1: MyGUI::Widget, w2: MyGUI::Widget` | `void` | `obj:confirmValue(w1, w2)` |
| hide | `sender: MyGUI::Window, name: string` | `void` | `obj:hide(sender, name)` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getSingleton | `` | `TransformWindow` | `TransformWindow.getSingleton()`<br>`obj:getSingleton()` |

## TripleInt
**Header:** `extern/KenshiLib/Include/kenshi/util/TripleInt.h`
**Metatable:** `KenshiLua.TripleInt`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | `unknown` | RW | `obj.value = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: TripleInt` | `void` | `obj:operator_assign(other)` |
| operator_subscript [1] | `val: integer` | `void` | `obj:operator_subscript(val)` |
| operator_subscript [2] | `` | `integer` | `obj:operator_subscript()` |
| operator_index [1] | `val: integer` | `void` | `obj:operator_index(val)` |
| operator_index [2] | `` | `integer` | `obj:operator_index()` |

## TurretBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TurretBuilding.h`
**Metatable:** `KenshiLua.TurretBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| gunClass | `lightuserdata` | R | `obj.gunClass` |
| aimDistInDegrees | `number` | RW | `obj.aimDistInDegrees = <value>` |
| currentAimDir | `Vector3` | RW | `obj.currentAimDir = <value>` |
| rootAimDir | `Vector3` | RW | `obj.rootAimDir = <value>` |
| currentAimSpeed | `number` | RW | `obj.currentAimSpeed = <value>` |
| currentAimTarget | `Vector3` | RW | `obj.currentAimTarget = <value>` |
| mountedBuilding | `hand` | RW | `obj.mountedBuilding = <value>` |
| hingePart | `lightuserdata` | R | `obj.hingePart` |
| gunPart | `lightuserdata` | R | `obj.gunPart` |
| aimTargetPos | `Vector3` | RW | `obj.aimTargetPos = <value>` |
| rotating | `integer` | RW | `obj.rotating = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| setup | `` | `void` | `obj:setup()` |
| update | `` | `void` | `obj:update()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| getStatUsed | `` | `StatsEnumerated` | `obj:getStatUsed()` |
| getProductionMultForGUI | `` | `number` | `obj:getProductionMultForGUI()` |
| aimAt | `who: Vector3` | `void` | `obj:aimAt(who)` |
| setVisible | `on: boolean` | `void` | `obj:setVisible(on)` |
| amInsideTownWalls | `` | `integer` | `obj:amInsideTownWalls()` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | `` | `void` | `obj:destroyPhysical()` |
| onBuildingLoaded | `` | `void` | `obj:onBuildingLoaded()` |
| calculatePowerMult | `` | `number` | `obj:calculatePowerMult()` |
| _teleport | `p: Vector3` | `void` | `obj:_teleport(p)` |
| clearTownBuildingsManagerPtr | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| getMountedBuilding | `` | `hand` | `obj:getMountedBuilding()` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |

## TutorialGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Metatable:** `KenshiLua.TutorialGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| highlightItem | `TutorialGUI::HighlightItem` | RW | `obj.highlightItem = <value>` |
| highlightItemWidget | `MyGUI::Widget` | R | `obj.highlightItemWidget` |
| highlightPanel | `MyGUI::Widget` | R | `obj.highlightPanel` |
| highlightDirection | `integer` | RW | `obj.highlightDirection = <value>` |
| highlightAlpha | `number` | RW | `obj.highlightAlpha = <value>` |
| window | `MyGUI::Widget` | R | `obj.window` |
| windowPrevButton | `MyGUI::Widget` | R | `obj.windowPrevButton` |
| windowNextButton | `MyGUI::Widget` | R | `obj.windowNextButton` |
| windowText | `MyGUI::Widget` | R | `obj.windowText` |
| dismissButton | `MyGUI::Widget` | R | `obj.dismissButton` |
| pagingText | `MyGUI::Widget` | R | `obj.pagingText` |
| tooltipsPanel | `MyGUI::Widget` | R | `obj.tooltipsPanel` |
| currentTutorialItem | `TutorialItem` | RW | `obj.currentTutorialItem = <value>` |
| flashNewItem | `boolean` | RW | `obj.flashNewItem = <value>` |
| enabled | `boolean` | RW | `obj.enabled = <value>` |
| activeTutorials | `ActiveTutorialsMapBinding::MapType` | RW | `obj.activeTutorials = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| clear | `` | `void` | `obj:clear()` |
| startHighlight | `item: TutorialGUI::HighlightItem` | `void` | `obj:startHighlight(item)` |
| endHighlight | `` | `void` | `obj:endHighlight()` |
| _setHightlightCoords | `` | `void` | `obj:_setHightlightCoords()` |
| update | `` | `void` | `obj:update()` |
| setEnabled | `value: boolean` | `void` | `obj:setEnabled(value)` |
| show | `value: boolean` | `void` | `obj:show(value)` |
| removeTutorialFromList | `tutorial: TutorialItem` | `void` | `obj:removeTutorialFromList(tutorial)` |
| arrangeList | `` | `void` | `obj:arrangeList()` |
| refreshUI | `` | `void` | `obj:refreshUI()` |
| showTutorialWindow | `item: TutorialItem` | `void` | `obj:showTutorialWindow(item)` |
| closeTutorialWindow | `` | `void` | `obj:closeTutorialWindow()` |
| updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |
| windowButtonEvent | `sender: MyGUI::Window, name: string` | `void` | `obj:windowButtonEvent(sender, name)` |
| windowPrevEvent | `sender: MyGUI::Widget` | `void` | `obj:windowPrevEvent(sender)` |
| windowNextEvent | `sender: MyGUI::Widget` | `void` | `obj:windowNextEvent(sender)` |
| dismissButtonEvent | `sender: MyGUI::Widget` | `void` | `obj:dismissButtonEvent(sender)` |
| tooltipOpen | `sender: MyGUI::Widget` | `void` | `obj:tooltipOpen(sender)` |
| tooltipClose | `sender: MyGUI::Widget` | `void` | `obj:tooltipClose(sender)` |

## TutorialGUI::TutorialGUILine
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Parent Class:** [`TutorialGUI`](#tutorialgui)
**Metatable:** `KenshiLua.TutorialGUILine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nameButton | `MyGUI::Widget` | R | `obj.nameButton` |
| closeButton | `MyGUI::Widget` | R | `obj.closeButton` |
| flashWidget | `MyGUI::Widget` | R | `obj.flashWidget` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| updateHighlight | `time: number` | `boolean` | `obj:updateHighlight(time)` |

## TutorialItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Metatable:** `KenshiLua.TutorialItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| id | `integer` | RW | `obj.id = <value>` |
| started | `boolean` | RW | `obj.started = <value>` |
| locked | `boolean` | RW | `obj.locked = <value>` |
| title | `string` | RW | `obj.title = <value>` |
| state | `TutorialItem::State` | RW | `obj.state = <value>` |
| subItemIndex | `integer` | RW | `obj.subItemIndex = <value>` |
| subItems | `Ogre::FastArray<TutorialSubItem*>` | RW | `obj.subItems = <value>` |
| requiredTutorialsStr | `Ogre::FastArray<std::string>` | RW | `obj.requiredTutorialsStr = <value>` |
| requiredTutorials | `Ogre::FastArray<TutorialItem*>` | RW | `obj.requiredTutorials = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getId | `` | `integer` | `obj:getId()` |
| getTitle | `` | `void` | `obj:getTitle()` |
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
| conditionsMet | `` | `boolean` | `obj:conditionsMet()` |
| start | `` | `void` | `obj:start()` |
| run | `` | `boolean` | `obj:run()` |
| end | `` | `void` | `obj:end()` |

## TutorialpediaGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Metatable:** `KenshiLua.TutorialpediaGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentItem | `TutorialItem` | RW | `obj.currentItem = <value>` |
| currentItemIndex | `integer` | RW | `obj.currentItemIndex = <value>` |
| tutorialsList | `MyGUI::Widget` | R | `obj.tutorialsList` |
| descriptionText | `MyGUI::Widget` | R | `obj.descriptionText` |
| activateButton | `MyGUI::Widget` | R | `obj.activateButton` |
| prevButton | `MyGUI::Widget` | R | `obj.prevButton` |
| nextButton | `MyGUI::Widget` | R | `obj.nextButton` |
| pagingText | `MyGUI::Widget` | R | `obj.pagingText` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| show | `value: boolean` | `void` | `obj:show(value)` |
| clear | `` | `void` | `obj:clear()` |
| isVisible | `` | `boolean` | `obj:isVisible()` |
| setup | `` | `void` | `obj:setup()` |
| updateCurrentItem | `` | `void` | `obj:updateCurrentItem()` |
| tutorialSelectedEvent | `sender: MyGUI::ListBox, index: integer` | `void` | `obj:tutorialSelectedEvent(sender, index)` |
| tutorialPrevEvent | `sender: MyGUI::Widget` | `void` | `obj:tutorialPrevEvent(sender)` |
| tutorialNextEvent | `sender: MyGUI::Widget` | `void` | `obj:tutorialNextEvent(sender)` |
| tutorialActivateButtonEvent | `sender: MyGUI::Widget` | `void` | `obj:tutorialActivateButtonEvent(sender)` |
| tutorialWindowButton | `sender: MyGUI::Window, name: string` | `void` | `obj:tutorialWindowButton(sender, name)` |

## TutorialSubItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Metatable:** `KenshiLua.TutorialSubItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| description | `string` | RW | `obj.description = <value>` |
| skippeable | `boolean` | RW | `obj.skippeable = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| start | `` | `void` | `obj:start()` |
| run | `` | `boolean` | `obj:run()` |
| end | `` | `void` | `obj:end()` |

## UseableStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`
**Metatable:** `KenshiLua.UseableStuff`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| shopOwner | `hand` | RW | `obj.shopOwner = <value>` |
| callbackOwner | `hand` | RW | `obj.callbackOwner = <value>` |
| hasProgressBarWhenUsed | `boolean` | RW | `obj.hasProgressBarWhenUsed = <value>` |
| progressBarLevel | `number` | RW | `obj.progressBarLevel = <value>` |
| occupantSelection | `boolean` | RW | `obj.occupantSelection = <value>` |
| needsOperating | `boolean` | RW | `obj.needsOperating = <value>` |
| numOperatorsMax | `integer` | RW | `obj.numOperatorsMax = <value>` |
| hungerRate | `number` | RW | `obj.hungerRate = <value>` |
| _recievesBatteryPower | `boolean` | RW | `obj._recievesBatteryPower = <value>` |
| powerOn | `boolean` | RW | `obj.powerOn = <value>` |
| _isBroken | `boolean` | RW | `obj._isBroken = <value>` |
| batteryOutputStat | `number` | RW | `obj.batteryOutputStat = <value>` |
| _powerOutputMax | `number` | RW | `obj._powerOutputMax = <value>` |
| currentPower | `number` | RW | `obj.currentPower = <value>` |
| powerTimeStored | `number` | RW | `obj.powerTimeStored = <value>` |
| _powerTimeStoreMax | `number` | RW | `obj._powerTimeStoreMax = <value>` |
| currentOperators | `StdSetBinding<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy>>::SetType` | RW | `obj.currentOperators = <value>` |
| usesStat | `StatsEnumerated` | RW | `obj.usesStat = <value>` |
| functionalityData | `GameData` | RW | `obj.functionalityData = <value>` |
| animation | `GameData` | RW | `obj.animation = <value>` |
| animationKO | `GameData` | RW | `obj.animationKO = <value>` |
| animationDazed | `GameData` | RW | `obj.animationDazed = <value>` |
| maxUseRange | `number` | RW | `obj.maxUseRange = <value>` |
| sfxTime | `number` | RW | `obj.sfxTime = <value>` |
| inventory | `Inventory` | R | `obj.inventory` |
| doorLock | `lightuserdata` | R | `obj.doorLock` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| createInventoryLayout | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| takeMoney | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| getMoney | `` | `integer` | `obj:getMoney()` |
| getInventory | `` | `Inventory` | `obj:getInventory()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| needsUpdate | `` | `boolean` | `obj:needsUpdate()` |
| threadedUpdate | `` | `void` | `obj:threadedUpdate()` |
| calculateEfficiencyMult | `` | `number` | `obj:calculateEfficiencyMult()` |
| isOutOfPower | `` | `number` | `obj:isOutOfPower()` |
| isBroken | `` | `boolean` | `obj:isBroken()` |
| setBroken | `on: boolean` | `void` | `obj:setBroken(on)` |
| isDisabled | `` | `boolean` | `obj:isDisabled()` |
| getMouseCursor | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | `` | `integer` | `obj:getDefaultTask()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| dontNeedWorkRightNow | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| takePowerFrom | `amount: number, frameTime: number` | `number` | `obj:takePowerFrom(amount, frameTime)` |
| howMuchPowerDoYouWantMax | `` | `number` | `obj:howMuchPowerDoYouWantMax()` |
| howMuchPowerDoYouWantForSortingFunction | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| howMuchPowerDoYouWantNow | `` | `number` | `obj:howMuchPowerDoYouWantNow()` |
| needPowerRightNow | `` | `boolean` | `obj:needPowerRightNow()` |
| givePower | `amount: number` | `void` | `obj:givePower(amount)` |
| resetPower | `` | `void` | `obj:resetPower()` |
| getMaxPower | `` | `number` | `obj:getMaxPower()` |
| getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| getFuelConsumptionRate | `` | `number` | `obj:getFuelConsumptionRate()` |
| isBattery | `` | `boolean` | `obj:isBattery()` |
| isGenerator | `` | `boolean` | `obj:isGenerator()` |
| getBatteryCharge | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryChargeMax | `` | `number` | `obj:getBatteryChargeMax()` |
| setupFromData | `` | `void` | `obj:setupFromData()` |
| switchPowerOn | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| hasPower | `` | `boolean` | `obj:hasPower()` |
| isPowerOn | `` | `boolean` | `obj:isPowerOn()` |
| isRecievesBatteryPower | `` | `boolean` | `obj:isRecievesBatteryPower()` |
| getStatUsed | `` | `StatsEnumerated` | `obj:getStatUsed()` |
| getDoorLock | `` | `lightuserdata` | `obj:getDoorLock()` |
| hasDoorLock | `` | `boolean` | `obj:hasDoorLock()` |
| getFunctionalityData | `` | `GameData` | `obj:getFunctionalityData()` |
| setup | `` | `void` | `obj:setup()` |
| getOutputBasedRotationSpeedMult | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| getGUIPowerEfficiencyToolTipString | `` | `string` | `obj:getGUIPowerEfficiencyToolTipString()` |
| getOccupant | `` | `hand` | `obj:getOccupant()` |
| getAnimation | `` | `string` | `obj:getAnimation()` |
| getAnimationKO | `` | `string` | `obj:getAnimationKO()` |
| getAnimationDazed | `` | `string` | `obj:getAnimationDazed()` |
| serialise | `container: GameDataContainer, refList: GameData, offset: userdata` | `GameSaveState` | `obj:serialise(container, refList, offset)` |
| hitByMeleeAttack | `dir: CutDirection, damage: Damages, who: Character, attack: CombatTechniqueData, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, damage, who, attack, comboID)` |
| equipItem | `slot: string, item: Item` | `void` | `obj:equipItem(slot, item)` |
| unequipItem | `slot: string, item: Item` | `void` | `obj:unequipItem(slot, item)` |
| dropItem | `what: RootObject` | `void` | `obj:dropItem(what)` |
| canHaveSomeOfThese | `input: GameData` | `boolean` | `obj:canHaveSomeOfThese(input)` |
| operate | `who: Character, amount: number` | `void` | `obj:operate(who, amount)` |
| getCostToUse | `who: Character` | `integer` | `obj:getCostToUse(who)` |
| getGUIData | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIData(datapanel, category)` |
| getGUIPower | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIPower(datapanel, category)` |
| getGUIEfficiency | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIEfficiency(datapanel, category)` |
| getGUIWorkers | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIWorkers(datapanel, category)` |
| getGUIToolTipForGroundResourceEfficiency | `` | `void` | `obj:getGUIToolTipForGroundResourceEfficiency()` |
| loadFromSerialise | `state: GameSaveState` | `void` | `obj:loadFromSerialise(state)` |
| isFreeSlot | `h: hand` | `boolean` | `obj:isFreeSlot(h)` |
| tryOperate | `h: hand` | `boolean` | `obj:tryOperate(h)` |
| couldIOperate | `h: hand` | `boolean` | `obj:couldIOperate(h)` |
| stopOperating | `h: hand` | `void` | `obj:stopOperating(h)` |
| occupantHandleChangedEvent | `h: hand` | `void` | `obj:occupantHandleChangedEvent(h)` |
| togglePowerButton | `line: DataPanelLine` | `void` | `obj:togglePowerButton(line)` |
| toggleBattButton | `line: DataPanelLine` | `void` | `obj:toggleBattButton(line)` |

## UtilityT
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`
**Metatable:** `KenshiLua.UtilityT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| marker | `lightuserdata` | R | `obj.marker` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| perlinNoise_2D | `x: number, y: number, zoom: number, dropPoint: number` | `number` | `obj:perlinNoise_2D(x, y, zoom, dropPoint)` |
| getTerrainHeightFastWithNormal | `x: number, z: number, normal: Vector3, map: ZoneMap` | `number` | `obj:getTerrainHeightFastWithNormal(x, z, normal, map)` |
| getTerrainSlopeFast | `x: number, z: number, map: ZoneMap` | `number` | `obj:getTerrainSlopeFast(x, z, map)` |
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
| getFloorHeight [1] | `origin: Vector3, floorNum: integer, withTerrain: boolean, furniture: boolean` | `number` | `obj:getFloorHeight(origin, floorNum, withTerrain, furniture)` |
| getFloorHeight [2] | `origin: Vector3, withTerrain: boolean, furniture: boolean` | `number` | `obj:getFloorHeight(origin, withTerrain, furniture)` |
| getBuildingGroundFloorHeight | `withTerrain: boolean` | `number` | `obj:getBuildingGroundFloorHeight(withTerrain)` |
| isIndoors | `` | `Building` | `obj:isIndoors()` |
| isIndoorsFast | `` | `boolean` | `obj:isIndoorsFast()` |
| isIndoors_forWaypoint | `` | `Building` | `obj:isIndoors_forWaypoint()` |
| getFloorNumber [1] | `collisionGroup: integer` | `integer` | `obj:getFloorNumber(collisionGroup)` |
| getFloorNumber [2] | `position: Vector3, hitBuilding: hand` | `integer` | `obj:getFloorNumber(position, hitBuilding)` |
| getTerrainHeightFast | `z: number, map: ZoneMap` | `number` | `obj:getTerrainHeightFast(z, map)` |
| random [1] | `lo: number, hi: number` | `number` | `obj:random(lo, hi)` |
| random [2] | `` | `number` | `obj:random()` |
| randomBool | `` | `boolean` | `obj:randomBool()` |
| randomInt | `hi: integer` | `integer` | `obj:randomInt(hi)` |
| seed [1] | `s: integer` | `void` | `obj:seed(s)` |
| seed [2] | `` | `void` | `obj:seed()` |
| round | `` | `integer` | `obj:round()` |
| nlerp | `b: number, t: number` | `number` | `obj:nlerp(b, t)` |
| getNextPow2 | `` | `integer` | `obj:getNextPow2()` |
| quatSetDirection | `` | `Quaternion` | `obj:quatSetDirection()` |
| getSubMapSector | `Z: number` | `iVector2` | `obj:getSubMapSector(Z)` |
| getSubMapSectorBounds | `` | `Vector4` | `obj:getSubMapSectorBounds()` |
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
| positionIsInFrontOfMe | `` | `boolean` | `obj:positionIsInFrontOfMe()` |
| pointInPlane | `` | `boolean` | `obj:pointInPlane()` |
| colorToGUIString | `g: number, b: number, a: number` | `string` | `obj:colorToGUIString(g, b, a)` |
| getFilesInDir | `dir: string, type: string` | `boolean` | `obj:getFilesInDir(dir, type)` |
| getFilesInGameDir | `dir: string, type: string` | `boolean` | `obj:getFilesInGameDir(dir, type)` |
| getDirsInDir | `dir: string` | `void` | `obj:getDirsInDir(dir)` |
| readFile | `path: string` | `string` | `obj:readFile(path)` |
| roundToNearest | `input: number, roundTo: integer` | `number` | `obj:roundToNearest(input, roundTo)` |

## VisibleObjectInfo
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Metatable:** `KenshiLua.VisibleObjectInfo`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | `hand` | RW | `obj.handle = <value>` |
| range | `number` | RW | `obj.range = <value>` |
| isEnemy | `boolean` | RW | `obj.isEnemy = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_assign | `other: VisibleObjectInfo` | `void` | `obj:operator_assign(other)` |

## WallBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/WallBuilding.h`
**Metatable:** `KenshiLua.WallBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| wallSectionLinkType | `WallSectionLinkType` | RW | `obj.wallSectionLinkType = <value>` |
| shareBuildStateOfAnother | `hand` | RW | `obj.shareBuildStateOfAnother = <value>` |
| othersSharingMyBuildState | `lektor<hand>` | RW | `obj.othersSharingMyBuildState = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getUseableStuff | `` | `UseableStuff` | `obj:getUseableStuff()` |
| getReachRange | `` | `number` | `obj:getReachRange()` |
| isForSale | `` | `boolean` | `obj:isForSale()` |
| createPhysical | `` | `boolean` | `obj:createPhysical()` |
| isDamaged | `` | `boolean` | `obj:isDamaged()` |
| getPositionForWaypoint_outside | `` | `Vector3` | `obj:getPositionForWaypoint_outside()` |
| getOutsideGateCode | `` | `integer` | `obj:getOutsideGateCode()` |
| isAWall | `` | `WallBuilding` | `obj:isAWall()` |
| canUpgrade | `` | `GameData` | `obj:canUpgrade()` |
| addConstructionProgress | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| setConstructionProgress | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| notifyConstructionComplete | `` | `void` | `obj:notifyConstructionComplete()` |
| addDismantleProgress | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| notifyConstructionDismantling | `` | `void` | `obj:notifyConstructionDismantling()` |
| getBuildState | `` | `Building::ConstructionState` | `obj:getBuildState()` |
| isALittleWallPartLikeACornerOrSomething | `` | `boolean` | `obj:isALittleWallPartLikeACornerOrSomething()` |
| isAShortWallPart | `` | `boolean` | `obj:isAShortWallPart()` |
| hitByMeleeAttack | `dir: CutDirection, damage: Damages, who: Character, attack: CombatTechniqueData, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, damage, who, attack, comboID)` |
| upgrade | `line: DataPanelLine` | `void` | `obj:upgrade(line)` |
| getGUIUpgrade | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIUpgrade(datapanel, category)` |
| getGUIDestroyButton | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIDestroyButton(datapanel, category)` |
| dismantleButton_all | `line: DataPanelLine` | `void` | `obj:dismantleButton_all(line)` |
| letsShare | `who: WallBuilding` | `boolean` | `obj:letsShare(who)` |

## Weapon
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Weapon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bleedDamage | `number` | RW | `obj.bleedDamage = <value>` |
| modAttack | `integer` | RW | `obj.modAttack = <value>` |
| combatWeight | `number` | RW | `obj.combatWeight = <value>` |
| category | `WeaponCategory` | RW | `obj.category = <value>` |
| category_animationOverride | `WeaponCategory` | RW | `obj.category_animationOverride = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getItemWeight | `` | `number` | `obj:getItemWeight()` |
| getValueSingle | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| getCategory | `` | `WeaponCategory` | `obj:getCategory()` |
| getCategory_animationOverride | `` | `WeaponCategory` | `obj:getCategory_animationOverride()` |
| is2HandedOnly | `` | `boolean` | `obj:is2HandedOnly()` |
| getCombatWeight | `` | `number` | `obj:getCombatWeight()` |
| getCraftTime | `` | `number` | `obj:getCraftTime()` |
| getCraftMaterialMult | `` | `number` | `obj:getCraftMaterialMult()` |
| isWeapon | `` | `Weapon` | `obj:isWeapon()` |
| isSword | `` | `Sword` | `obj:isSword()` |
| isCrossbow | `` | `Crossbow` | `obj:isCrossbow()` |
| getSkillModIndoors | `` | `integer` | `obj:getSkillModIndoors()` |
| getTooltipData1 | `` | `void` | `obj:getTooltipData1()` |

## WeatherRegion
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`
**Metatable:** `KenshiLua.WeatherRegion`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| biomeGroup | `lightuserdata` | RW | `obj.biomeGroup = <value>` |
| weatherStrengthMultiplierMin | `number` | RW | `obj.weatherStrengthMultiplierMin = <value>` |
| weatherStrengthMultiplierMax | `number` | RW | `obj.weatherStrengthMultiplierMax = <value>` |
| weatherInstance | `lightuserdata` | R | `obj.weatherInstance` |
| currentSeason | `lightuserdata` | RW | `obj.currentSeason = <value>` |
| currentSeasonIndex | `integer` | RW | `obj.currentSeasonIndex = <value>` |
| currentSeasonEndDay | `integer` | RW | `obj.currentSeasonEndDay = <value>` |
| biomeGroupLoaded | `boolean` | RW | `obj.biomeGroupLoaded = <value>` |
| requestUpdateEffects | `boolean` | RW | `obj.requestUpdateEffects = <value>` |
| activeCameraBiome | `boolean` | RW | `obj.activeCameraBiome = <value>` |
| weatherUpdated | `boolean` | RW | `obj.weatherUpdated = <value>` |
| instanceUpdated | `boolean` | RW | `obj.instanceUpdated = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| reset | `` | `void` | `obj:reset()` |
| getWeatherInstance | `` | `lightuserdata` | `obj:getWeatherInstance()` |
| setCurrentSeason | `seasonIndex: integer, seasonEnd: integer` | `void` | `obj:setCurrentSeason(seasonIndex, seasonEnd)` |
| getNewWeatherStrength | `` | `number` | `obj:getNewWeatherStrength()` |
| update | `` | `void` | `obj:update()` |
| updateBT | `` | `void` | `obj:updateBT()` |
| addListener | `listener: userdata` | `void` | `obj:addListener(listener)` |
| removeListener | `listener: userdata` | `void` | `obj:removeListener(listener)` |
| addGlobalEffect | `type: EffectType::Enum` | `void` | `obj:addGlobalEffect(type)` |
| getNewSeason | `` | `void` | `obj:getNewSeason()` |
| weatherChanged | `newWeather: boolean` | `void` | `obj:weatherChanged(newWeather)` |
| updateWeatherEffects | `` | `void` | `obj:updateWeatherEffects()` |
| save | `data: GameData, key: string` | `void` | `obj:save(data, key)` |
| load | `data: GameData, key: string` | `void` | `obj:load(data, key)` |

## WeatherRegion::Listener
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`WeatherRegion`](#weatherregion)
**Metatable:** `KenshiLua.Listener`

## WindGeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`
**Metatable:** `KenshiLua.WindGeneratorBuilding`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getPowerOutput | `` | `number` | `obj:getPowerOutput()` |
| getSoundIntensity | `` | `number` | `obj:getSoundIntensity()` |
| isAnyInputsEmpty | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| getGUIState | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIState(datapanel, category)` |
| getGUIPower | `datapanel: DatapanelGUI, category: integer` | `void` | `obj:getGUIPower(datapanel, category)` |

## WorldEventStateQuery
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`
**Metatable:** `KenshiLua.WorldEventStateQuery`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| playerInvolvement | `boolean` | RW | `obj.playerInvolvement = <value>` |
| isAllyOf | `ogre_unordered_map<Faction*, bool>::type` | RW | `obj.isAllyOf = <value>` |
| isEnemyOf | `ogre_unordered_map<Faction*, bool>::type` | RW | `obj.isEnemyOf = <value>` |
| towns | `ogre_unordered_map<GameData*, WorldStateEnum>::type` | RW | `obj.towns = <value>` |
| uniqueNPCsAre | `ogre_unordered_map<GameData*, WorldStateEnum>::type` | RW | `obj.uniqueNPCsAre = <value>` |
| uniqueNPCsAreNot | `ogre_unordered_map<GameData*, WorldStateEnum>::type` | RW | `obj.uniqueNPCsAreNot = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isTrue | `` | `boolean` | `obj:isTrue()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| checkAllStatesInObject | `` | `boolean` | `WorldEventStateQuery.checkAllStatesInObject()`<br>`obj:checkAllStatesInObject()` |
| getFromData | `` | `WorldEventStateQuery` | `WorldEventStateQuery.getFromData()`<br>`obj:getFromData()` |

## WorldEventStateQueryList
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`
**Metatable:** `KenshiLua.WorldEventStateQueryList`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| statesList | `ogre_unordered_map<WorldEventStateQuery*, bool>::type` | RW | `obj.statesList = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| setupFrom | `d: GameData, listname: string` | `boolean` | `obj:setupFrom(d, listname)` |
| reset | `` | `void` | `obj:reset()` |
| isTrue | `` | `boolean` | `obj:isTrue()` |

## YesNoMaybe
**Header:** `extern/KenshiLib/Include/kenshi/util/YesNoMaybe.h`
**Metatable:** `KenshiLua.YesNoMaybe`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | `integer` | RW | `obj.key = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| operator_eq [1] | `` | `boolean` | `obj:operator_eq()` |
| operator_eq [2] | `val: integer` | `boolean` | `obj:operator_eq(val)` |
| operator_ne [1] | `` | `boolean` | `obj:operator_ne()` |
| operator_ne [2] | `b: boolean` | `boolean` | `obj:operator_ne(b)` |
| operator_ne [3] | `val: integer` | `boolean` | `obj:operator_ne(val)` |
| toInt | `` | `integer` | `obj:toInt()` |
| operator_bool | `` | `boolean` | `obj:operator_bool()` |
| operator_ynm | `` | `integer` | `obj:operator_ynm()` |

## ZoneManager
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.ZoneManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| justLoadedAGame | `boolean` | RW | `obj.justLoadedAGame = <value>` |
| characterGrid | `ZoneSpacialGrid` | R | `obj.characterGrid` |
| buildingGrid | `ZoneSpacialGrid` | R | `obj.buildingGrid` |
| itemGrid | `ZoneSpacialGrid` | R | `obj.itemGrid` |
| _needCalculateIslands | `boolean` | RW | `obj._needCalculateIslands = <value>` |
| spawnUpdateTimerMT | `number` | RW | `obj.spawnUpdateTimerMT = <value>` |
| spawnUpdateTimerTT | `number` | RW | `obj.spawnUpdateTimerTT = <value>` |
| distantTownCentre | `iVector2` | RW | `obj.distantTownCentre = <value>` |
| centralZone | `ZoneMap` | RW | `obj.centralZone = <value>` |
| loadingPhase | `integer` | RW | `obj.loadingPhase = <value>` |
| biomeMap | `lightuserdata` | R | `obj.biomeMap` |
| groundEffectsPool | `ParticlePool` | RW | `obj.groundEffectsPool = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isZoneLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneLoadedT(pos)` |
| isZoneBeingLoadedT | `pos: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(pos)` |
| getNumActiveZones | `` | `integer` | `obj:getNumActiveZones()` |
| findShop | `t: Town, selling: ItemFunction` | `Building` | `obj:findShop(t, selling)` |
| findAnyShop | `t: Town` | `Building` | `obj:findAnyShop(t)` |
| setup | `` | `void` | `obj:setup()` |
| updateMainThread | `camerapos: Vector3` | `void` | `obj:updateMainThread(camerapos)` |
| updateRendertimeThread | `camerapos: Vector3` | `void` | `obj:updateRendertimeThread(camerapos)` |
| updateGPUSafeThread | `camerapos: Vector3` | `void` | `obj:updateGPUSafeThread(camerapos)` |
| spawnChecksUpdateThreaded | `island: integer` | `void` | `obj:spawnChecksUpdateThreaded(island)` |
| levelEditorDeleteAllSelectedObjects | `` | `void` | `obj:levelEditorDeleteAllSelectedObjects()` |
| levelEditorGetAllSelectedObjects | `type: itemType` | `void` | `obj:levelEditorGetAllSelectedObjects(type)` |
| getIsland | `zone: ZoneMap` | `void` | `obj:getIsland(zone)` |
| getCurrentMapSector | `` | `iVector2` | `obj:getCurrentMapSector()` |
| getCurrentZoneMap | `` | `ZoneMap` | `obj:getCurrentZoneMap()` |
| getSubMapSector | `X: number, Z: number` | `iVector2` | `obj:getSubMapSector(X, Z)` |
| getZoneMapFromResolutionCoord | `X: number, Z: number` | `iVector2` | `obj:getZoneMapFromResolutionCoord(X, Z)` |
| playerActivate | `pos: Vector3` | `boolean` | `obj:playerActivate(pos)` |
| deactivateZoneMap | `map: ZoneMap, saveZoneState: boolean` | `void` | `obj:deactivateZoneMap(map, saveZoneState)` |
| getBiome | `position: Vector3` | `GameData` | `obj:getBiome(position)` |
| getBiomeCode | `position: Vector3` | `integer` | `obj:getBiomeCode(position)` |
| getBiomeMap | `` | `lightuserdata` | `obj:getBiomeMap()` |
| getGroundTypeIndex | `pos: Vector3` | `integer` | `obj:getGroundTypeIndex(pos)` |
| getGroundType | `pos: Vector3` | `GroundType` | `obj:getGroundType(pos)` |
| addGroundEffect | `effectData: GameData, position: Vector3` | `void` | `obj:addGroundEffect(effectData, position)` |
| shiftGroundEffects | `shift: Vector3` | `void` | `obj:shiftGroundEffects(shift)` |
| checkZoneFiles | `` | `boolean` | `obj:checkZoneFiles()` |
| resetStates | `` | `void` | `obj:resetStates()` |
| getResourceId | `resource: MiningResource` | `string` | `obj:getResourceId(resource)` |
| getResourceName | `resource: MiningResource` | `string` | `obj:getResourceName(resource)` |
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
| checkForRepopulateTown | `t: Town` | `boolean` | `obj:checkForRepopulateTown(t)` |
| getCentralZone | `` | `ZoneMap` | `obj:getCentralZone()` |
| isLoading | `` | `integer` | `obj:isLoading()` |
| _calculateIslands | `` | `void` | `obj:_calculateIslands()` |
| loadFeatures | `` | `void` | `obj:loadFeatures()` |
| loadDistantTowns | `` | `void` | `obj:loadDistantTowns()` |
| processLoading | `` | `boolean` | `obj:processLoading()` |
| loadPhase1 | `` | `void` | `obj:loadPhase1()` |
| loadPhase2 | `` | `void` | `obj:loadPhase2()` |
| loadPhase3 | `` | `void` | `obj:loadPhase3()` |
| getMapSector [1] | `v: Vector3` | `iVector2` | `obj:getMapSector(v)` |
| getMapSector [2] | `x: number, z: number` | `iVector2` | `obj:getMapSector(x, z)` |
| getZoneBoundsT | `pos: Vector3` | `AABB2D` | `obj:getZoneBoundsT(pos)` |
| getZoneMapSectorBounds | `sector: iVector2` | `Vector4` | `obj:getZoneMapSectorBounds(sector)` |
| getZoneMap [1] | `v: Vector3` | `ZoneMap` | `obj:getZoneMap(v)` |
| getZoneMap [2] | `x: integer, y: integer` | `ZoneMap` | `obj:getZoneMap(x, y)` |
| getZoneMap [3] | `v: iVector2` | `ZoneMap` | `obj:getZoneMap(v)` |
| getZoneMapFromBuildingHandle | `h: hand` | `ZoneMap` | `obj:getZoneMapFromBuildingHandle(h)` |
| activateZoneMap [1] | `map: ZoneMap, center: iVector2, range: integer, type: ZoneActivationType, deactivationTimer: number` | `boolean` | `obj:activateZoneMap(map, center, range, type, deactivationTimer)` |
| activateZoneMap [2] | `co: iVector2, range: integer, playerActivated: ZoneActivationType, backThread: boolean` | `boolean` | `obj:activateZoneMap(co, range, playerActivated, backThread)` |
| findBuilding [1] | `t: TownBase, f: Faction, out: BuildingFinderClass` | `void` | `obj:findBuilding(t, f, out)` |
| findBuilding [2] | `t: TownBase, f: Faction, forSaleOnly: boolean, fun: BuildingFunction, own: Ownerships` | `Building` | `obj:findBuilding(t, f, forSaleOnly, fun, own)` |
| getAllActiveZones | `` | `void` | `obj:getAllActiveZones()` |
| getAllActiveIslandNumbers | `` | `integer` | `obj:getAllActiveIslandNumbers()` |
| getZonesTouchingTown | `town: Town` | `void` | `obj:getZonesTouchingTown(town)` |
| findOverlappingActiveZones | `pos: Vector3, radius: number` | `void` | `obj:findOverlappingActiveZones(pos, radius)` |
| getBuildingsThatLinkTo | `buildingType: GameData` | `void` | `obj:getBuildingsThatLinkTo(buildingType)` |
| findAllBuildings | `t: TownBase, f: Faction, forSaleOnly: boolean, fun: integer, ownership: Ownerships` | `void` | `obj:findAllBuildings(t, f, forSaleOnly, fun, ownership)` |
| getResource | `resource: MiningResource, biome: userdata, pos: Vector3` | `number` | `obj:getResource(resource, biome, pos)` |
| getResourceBase | `resource: MiningResource, biome: userdata, pos: Vector3` | `number` | `obj:getResourceBase(resource, biome, pos)` |
| getGroundEffect | `pos: Vector3` | `boolean\|number` | `obj:getGroundEffect(pos)` |
| getAllActiveZonesT | `` | `void` | `obj:getAllActiveZonesT()` |

### Static Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| getGroundSound [1] | `type: GroundType, barefoot: boolean` | `char` | `ZoneManager.getGroundSound(type, barefoot)`<br>`obj:getGroundSound(type, barefoot)` |
| getGroundSound [2] | `pos: Vector3` | `char` | `ZoneManager.getGroundSound(pos)`<br>`obj:getGroundSound(pos)` |

## ZoneManager::BiomeGroundEffects
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Parent Class:** [`ZoneManager`](#zonemanager)
**Metatable:** `KenshiLua.ZoneManager_BiomeGroundEffects`

## ZoneManagerInterfaceT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.ZoneManagerInterfaceT`

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isZoneLoadedT | `_a1: Vector3` | `boolean` | `obj:isZoneLoadedT(_a1)` |
| isZoneBeingLoadedT | `_a1: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(_a1)` |
| getZoneBoundsT [1] | `_a1: Vector3` | `AABB2D` | `obj:getZoneBoundsT(_a1)` |
| getZoneBoundsT [2] | `_a1: iVector2` | `AABB2D` | `obj:getZoneBoundsT(_a1)` |
| getAllActiveZonesT | `` | `void` | `obj:getAllActiveZonesT()` |

## ZoneMap
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.ZoneMap`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mapContent | `lightuserdata` | R | `obj.mapContent` |
| mapFeatures | `lightuserdata` | R | `obj.mapFeatures` |
| zoneSmell | `lightuserdata` | R | `obj.zoneSmell` |
| coordinates | `iVector2` | RW | `obj.coordinates = <value>` |
| island | `integer` | RW | `obj.island = <value>` |
| hasFile | `boolean` | RW | `obj.hasFile = <value>` |
| terrainCollision | `lightuserdata` | R | `obj.terrainCollision` |
| activatedCountdown | `unknown` | RW | `obj.activatedCountdown = <value>` |
| _generateNavMeshesFlag | `boolean` | RW | `obj._generateNavMeshesFlag = <value>` |
| center | `Vector3` | RW | `obj.center = <value>` |
| loadCount | `integer` | RW | `obj.loadCount = <value>` |
| neighbors | `unknown` | RW | `obj.neighbors = <value>` |
| neighborsDiagonal | `unknown` | RW | `obj.neighborsDiagonal = <value>` |
| AABB | `Vector4` | RW | `obj.AABB = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| isInIsland | `other: ZoneMap` | `boolean` | `obj:isInIsland(other)` |
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
| isANeighbour | `who: ZoneMap` | `boolean` | `obj:isANeighbour(who)` |
| isTerrainCollisionLoaded | `` | `boolean` | `obj:isTerrainCollisionLoaded()` |
| _makeSureTerrainHeightmapLoaded | `` | `void` | `obj:_makeSureTerrainHeightmapLoaded()` |
| _dactivateMT | `saveZoneState: boolean` | `void` | `obj:_dactivateMT(saveZoneState)` |
| generateNavMeshes | `` | `boolean` | `obj:generateNavMeshes()` |
| updateBuildingUsageNodes | `` | `void` | `obj:updateBuildingUsageNodes()` |
| getBounds | `` | `Vector4` | `obj:getBounds()` |
| getBoundsMinusUnloadedEdges | `borderThickness: number` | `Vector4` | `obj:getBoundsMinusUnloadedEdges(borderThickness)` |
| getActiveZoneIsland | `` | `void` | `obj:getActiveZoneIsland()` |
| getActiveNeighbours4 | `` | `void` | `obj:getActiveNeighbours4()` |
| getActiveNeighbours8 | `` | `void` | `obj:getActiveNeighbours8()` |
| isActivationType | `type: ZoneActivationType` | `boolean` | `obj:isActivationType(type)` |
| init | `loc: iVector2` | `void` | `obj:init(loc)` |
| getCenterPos | `` | `Vector3` | `obj:getCenterPos()` |

## ZoneMap::StateT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Parent Class:** [`ZoneMap`](#zonemap)
**Metatable:** `KenshiLua.StateT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _zoneBeingLoaded | `boolean` | RW | `obj._zoneBeingLoaded = <value>` |
| _zoneIsLoaded | `boolean` | RW | `obj._zoneIsLoaded = <value>` |

## ZoneSpacialGrid
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.ZoneSpacialGrid`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| zones | `lightuserdata` | R | `obj.zones` |
| createCellsFunc | `lightuserdata` | R | `obj.createCellsFunc` |
| cellCount | `integer` | RW | `obj.cellCount = <value>` |
| cellSize | `number` | RW | `obj.cellSize = <value>` |
| mutex | `unknown` | RW | `obj.mutex = <value>` |

### Methods
| Lua Name | Arguments | Return Type | Example |
|---|---|---|---|
| add | `o: RootObject` | `integer` | `obj:add(o)` |
| remove | `o: RootObject` | `boolean` | `obj:remove(o)` |
| update | `o: RootObject` | `ZoneSpacialGrid::Result` | `obj:update(o)` |
| addZone | `z: ZoneMap` | `void` | `obj:addZone(z)` |
| removeZone | `z: ZoneMap` | `void` | `obj:removeZone(z)` |
| getZoneKey | `p: Vector3` | `integer` | `obj:getZoneKey(p)` |
| getCellKey | `zone: ZoneMap, p: Vector3` | `integer` | `obj:getCellKey(zone, p)` |
| getFullKey | `p: Vector3` | `integer` | `obj:getFullKey(p)` |
| initialiseGrid | `size: number` | `void` | `obj:initialiseGrid(size)` |

## ZoneSpacialGrid::ZoneCell
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Parent Class:** [`ZoneSpacialGrid`](#zonespacialgrid)
**Metatable:** `KenshiLua.ZoneSpacialGrid_ZoneCell`
