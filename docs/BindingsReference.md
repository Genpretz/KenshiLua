# Lua Bindings Reference

## Overview & Calling Conventions

### Method Invocations
- **Instance Methods**: Called on userdata instances using colon syntax: `instance:methodName(args)`.
- **Static Class Methods**: Support dual invocation (both static table calls `ClassName.methodName(args)` and instance calls `instance:methodName(args)`).
- **Overloaded Methods**: Methods supporting multiple argument counts or polymorphic parameter types are documented with explicit overload indexes (e.g. `[1]`, `[2]`), indicating each signature's parameter types and return type.

## Table of Contents
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
- [`BaseLayout`](#baselayout)
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
  - [`DataPanelLine::Slider`](#datapanelline::slider)
- [`DataPanelLine_Button`](#datapanelline_button)
- [`DataPanelLine_CheckBox`](#datapanelline_checkbox)
- [`DataPanelLine_DropBox`](#datapanelline_dropbox)
- [`DataPanelLine_Faction`](#datapanelline_faction)
- [`DataPanelLine_KeyConfig`](#datapanelline_keyconfig)
- [`DataPanelLine_Progress`](#datapanelline_progress)
- [`DataPanelLine_Research`](#datapanelline_research)
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
- [`MyGUI`](MyGUI_Bindings.md)
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setNull | Instance | `` | `void` | `obj:setNull()` |
| pointWithin | Instance | `v: Vector3` | `boolean` | `obj:pointWithin(v)` |
| inflate | Instance | `amount: number` | `void` | `obj:inflate(amount)` |
| sizeX | Instance | `` | `number` | `obj:sizeX()` |
| sizeY | Instance | `` | `number` | `obj:sizeY()` |
| intersects [1] | Instance | `pos: Vector3, radius: number` | `boolean` | `obj:intersects(pos, radius)` |
| intersects [2] | Instance | `b: AABB2D` | `boolean` | `obj:intersects(b)` |
| intersects [3] | Instance | `raypos: Vector3, raydest: Vector3` | `boolean` | `obj:intersects(raypos, raydest)` |
| intersects2 | Instance | `rayorig: Vector2, raydirection: Vector2` | `Vector2` | `obj:intersects2(rayorig, raydirection)` |

## AbstractMovementBase
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.AbstractMovementBase`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| officiallyStopped | `boolean` | RW | `obj.officiallyStopped = <value>` |
| speedOrders | `integer` | RW | `obj.speedOrders = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| create | Instance | `_pos: Vector3` | `void` | `obj:create(_pos)` |
| getHandle | Instance | `` | `void` | `obj:getHandle()` |
| _setPositionAndTeleport | Instance | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _setPositionSimple | Instance | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| faceDirection | Instance | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| lookatPosition | Instance | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| getDestination | Instance | `` | `Vector3` | `obj:getDestination()` |
| isProbablyStuck | Instance | `` | `boolean` | `obj:isProbablyStuck()` |
| pathOk | Instance | `` | `boolean` | `obj:pathOk()` |
| pathFailed | Instance | `` | `boolean` | `obj:pathFailed()` |
| update | Instance | `_TIME: number` | `void` | `obj:update(_TIME)` |
| isDestinationReached | Instance | `` | `boolean` | `obj:isDestinationReached()` |
| amInsideTownWalls | Instance | `` | `integer` | `obj:amInsideTownWalls()` |
| manualMovement | Instance | `desiredMotion: Vector3` | `void` | `obj:manualMovement(desiredMotion)` |
| halt | Instance | `` | `void` | `obj:halt()` |
| setRoadDestination | Instance | `dest: Vector3` | `boolean` | `obj:setRoadDestination(dest)` |
| setRoadPreference | Instance | `w: number` | `void` | `obj:setRoadPreference(w)` |
| extractRoadFollower | Instance | `` | `lightuserdata` | `obj:extractRoadFollower()` |
| setStandardWalkSpeed | Instance | `s: number` | `void` | `obj:setStandardWalkSpeed(s)` |
| getStandardWalkSpeed | Instance | `` | `number` | `obj:getStandardWalkSpeed()` |
| restoreDesiredSpeed | Instance | `` | `void` | `obj:restoreDesiredSpeed()` |
| setMaxSpeed | Instance | `ms: number` | `void` | `obj:setMaxSpeed(ms)` |
| getMaxSpeed | Instance | `` | `number` | `obj:getMaxSpeed()` |
| isCurrentlyMoving | Instance | `` | `boolean` | `obj:isCurrentlyMoving()` |
| getCurrentSpeed | Instance | `` | `number` | `obj:getCurrentSpeed()` |
| getCurrentMotion | Instance | `` | `Vector3` | `obj:getCurrentMotion()` |
| getCurrentSpeedRelativeToMax01 | Instance | `` | `number` | `obj:getCurrentSpeedRelativeToMax01()` |
| getSpeedOrders | Instance | `` | `integer` | `obj:getSpeedOrders()` |
| leaveSpeedGroup | Instance | `` | `void` | `obj:leaveSpeedGroup()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getFacingDirection | Instance | `` | `Vector3` | `obj:getFacingDirection()` |
| setDestination [1] | Instance | `dest: Vector3, pri: UpdatePriority, _a3: boolean` | `void` | `obj:setDestination(dest, pri, _a3)` |
| setDestination [2] | Instance | `target: RootObjectBase, pri: UpdatePriority` | `void` | `obj:setDestination(target, pri)` |
| setDestination [3] | Instance | `who: Character, pri: UpdatePriority` | `void` | `obj:setDestination(who, pri)` |
| setDestination [4] | Instance | `who: Building, pri: UpdatePriority` | `void` | `obj:setDestination(who, pri)` |
| setCurrentRoadFollower | Instance | `d: Vector3, r: userdata` | `void` | `obj:setCurrentRoadFollower(d, r)` |
| setPatrolInput | Instance | `patrol: userdata` | `void` | `obj:setPatrolInput(patrol)` |
| setDesiredSpeed [1] | Instance | `speed: MoveSpeed` | `void` | `obj:setDesiredSpeed(speed)` |
| setDesiredSpeed [2] | Instance | `speed: number` | `void` | `obj:setDesiredSpeed(speed)` |
| setDesiredSpeedOrders [1] | Instance | `speed: MoveSpeed` | `void` | `obj:setDesiredSpeedOrders(speed)` |
| setDesiredSpeedOrders [2] | Instance | `speed: number` | `void` | `obj:setDesiredSpeedOrders(speed)` |
| onShapeHit | Instance | `hit: userdata` | `integer` | `obj:onShapeHit(hit)` |
| onControllerHit | Instance | `hit: userdata` | `integer` | `obj:onControllerHit(hit)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| _recalculateIsIntact | Instance | `` | `boolean` | `obj:_recalculateIsIntact()` |
| isAnyoneCaptured | Instance | `` | `boolean` | `obj:isAnyoneCaptured()` |
| getGroupSense | Instance | `` | `lightuserdata` | `obj:getGroupSense()` |
| getMemory | Instance | `` | `lightuserdata` | `obj:getMemory()` |
| removeObject | Instance | `` | `boolean` | `obj:removeObject()` |
| addActiveObject | Instance | `` | `boolean` | `obj:addActiveObject()` |
| addCharacterAt | Instance | `index: integer` | `void` | `obj:addCharacterAt(index)` |
| swapCharacters | Instance | `indexA: integer, indexB: integer` | `void` | `obj:swapCharacters(indexA, indexB)` |
| emptySquadCheck | Instance | `` | `void` | `obj:emptySquadCheck()` |
| clearAllTheUniqueNPCStates | Instance | `` | `void` | `obj:clearAllTheUniqueNPCStates()` |
| isIntact | Instance | `` | `boolean` | `obj:isIntact()` |
| getSquadLeader_theRealOne | Instance | `` | `Character` | `obj:getSquadLeader_theRealOne()` |
| getNearestActiveCharacter | Instance | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | Instance | `` | `Character` | `obj:getSquadLeader()` |
| getSquadSize | Instance | `` | `integer` | `obj:getSquadSize()` |
| setSquadLeader | Instance | `` | `void` | `obj:setSquadLeader()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| refreshInventory | Instance | `firstTime: boolean` | `void` | `obj:refreshInventory(firstTime)` |
| _forceRefreshInventory | Instance | `` | `void` | `obj:_forceRefreshInventory()` |
| periodicUpdate | Instance | `` | `boolean` | `obj:periodicUpdate()` |
| serialiseEverythingToDisk | Instance | `levelEditor: boolean` | `void` | `obj:serialiseEverythingToDisk(levelEditor)` |
| isWholeSquadDown | Instance | `minusThis: integer` | `boolean` | `obj:isWholeSquadDown(minusThis)` |
| setDataFilename | Instance | `f: string` | `void` | `obj:setDataFilename(f)` |
| setupLeaderDialogues | Instance | `` | `void` | `obj:setupLeaderDialogues()` |
| isLoaded | Instance | `` | `boolean` | `obj:isLoaded()` |
| teleport | Instance | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| setName | Instance | `name: string` | `void` | `obj:setName(name)` |
| getIsTrader | Instance | `` | `boolean` | `obj:getIsTrader()` |
| getHasVendorList | Instance | `` | `boolean` | `obj:getHasVendorList()` |
| getHasSpecialItemsList | Instance | `` | `boolean` | `obj:getHasSpecialItemsList()` |
| setupTraderBuildings | Instance | `` | `void` | `obj:setupTraderBuildings()` |
| putTheSpecialCharactersInNewSquads_captured | Instance | `` | `void` | `obj:putTheSpecialCharactersInNewSquads_captured()` |
| checkForCharactersBeingCarried | Instance | `` | `boolean` | `obj:checkForCharactersBeingCarried()` |
| restoreSquad | Instance | `` | `void` | `obj:restoreSquad()` |
| unloadCheck | Instance | `` | `boolean` | `obj:unloadCheck()` |
| setupCheck | Instance | `` | `YesNoMaybe` | `obj:setupCheck()` |
| destroyCharacters | Instance | `justUnload: boolean` | `void` | `obj:destroyCharacters(justUnload)` |
| serialiseCharacterData | Instance | `` | `void` | `obj:serialiseCharacterData()` |
| saveToDisk | Instance | `levelEditor: boolean, force: string` | `void` | `obj:saveToDisk(levelEditor, force)` |
| loadCharacters | Instance | `_a1: Vector3` | `void` | `obj:loadCharacters(_a1)` |
| calculateCurrentPos | Instance | `` | `Vector3` | `obj:calculateCurrentPos()` |
| _checkForUniqueCharactersOnUnload | Instance | `` | `void` | `obj:_checkForUniqueCharactersOnUnload()` |
| getName | Instance | `` | `string` | `obj:getName()` |
| loadFromDisk | Instance | `force: boolean, extra: userdata` | `boolean` | `obj:loadFromDisk(force, extra)` |
| getCharactersInArea | Instance | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| loadInstance | Instance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |

## AkSoundPosition
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.AkSoundPosition`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| Position | `unknown` | RW | `obj.Position = <value>` |
| Orientation | `unknown` | RW | `obj.Orientation = <value>` |

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

## AppearanceAnimal
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`
**Metatable:** `KenshiLua.AppearanceAnimal`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createBody | Instance | `` | `void` | `obj:createBody()` |
| updateCharaterTexture | Instance | `` | `void` | `obj:updateCharaterTexture()` |

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
| attachedHarpoons | `HarpoonFastArrayBinding::ArrayType` | RW | `obj.attachedHarpoons = <value>` |
| attachedEffects | `AttachedEffectFastArrayBinding::ArrayType` | RW | `obj.attachedEffects = <value>` |
| attachedEffectsToRemove | `AttachedEffectFastArrayBinding::ArrayType` | RW | `obj.attachedEffectsToRemove = <value>` |
| woundsList | `WoundFastArrayBinding::ArrayType` | RW | `obj.woundsList = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateAnimationTransforms | Instance | `` | `void` | `obj:updateAnimationTransforms()` |
| forceUpdateAnimationTransforms | Instance | `` | `void` | `obj:forceUpdateAnimationTransforms()` |
| update | Instance | `` | `void` | `obj:update()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| setAppearanceData | Instance | `` | `void` | `obj:setAppearanceData()` |
| getAppearanceData | Instance | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| activate | Instance | `` | `void` | `obj:activate()` |
| deactivate | Instance | `` | `void` | `obj:deactivate()` |
| isFemale | Instance | `` | `boolean` | `obj:isFemale()` |
| setGender | Instance | `_female: boolean` | `void` | `obj:setGender(_female)` |
| getRace | Instance | `` | `GameData` | `obj:getRace()` |
| attachEffect | Instance | `boneName: string, offsetPosition: Vector3, offsetOrientation: Quaternion, manual: boolean, baseEmission: number` | `lightuserdata` | `obj:attachEffect(boneName, offsetPosition, offsetOrientation, manual, baseEmission)` |
| getAttachedEntity | Instance | `slot: string` | `lightuserdata` | `obj:getAttachedEntity(slot)` |
| detachAllHarpoonsT | Instance | `` | `void` | `obj:detachAllHarpoonsT()` |
| _detachAllHarpoons | Instance | `` | `void` | `obj:_detachAllHarpoons()` |
| updateWetness | Instance | `force: boolean` | `void` | `obj:updateWetness(force)` |
| updateBloodyness | Instance | `` | `void` | `obj:updateBloodyness()` |
| getAttachmentPosition | Instance | `slot: string, pos: Vector3, rot: Quaternion` | `boolean` | `obj:getAttachmentPosition(slot, pos, rot)` |
| hasSlot | Instance | `slot: string` | `boolean` | `obj:hasSlot(slot)` |
| getNormalisedCharacterHeight | Instance | `` | `number` | `obj:getNormalisedCharacterHeight()` |
| getCharacterHeight | Instance | `` | `number` | `obj:getCharacterHeight()` |
| getAnimationSystem | Instance | `` | `lightuserdata` | `obj:getAnimationSystem()` |
| getSceneNode | Instance | `` | `lightuserdata` | `obj:getSceneNode()` |
| getSkeleton | Instance | `` | `lightuserdata` | `obj:getSkeleton()` |
| getBody | Instance | `` | `lightuserdata` | `obj:getBody()` |
| getBodyRadius | Instance | `` | `number` | `obj:getBodyRadius()` |
| failedToLoad | Instance | `` | `boolean` | `obj:failedToLoad()` |
| getBonePosition | Instance | `boneName: string` | `Vector3` | `obj:getBonePosition(boneName)` |
| getBoneOrientation | Instance | `boneName: string` | `Quaternion` | `obj:getBoneOrientation(boneName)` |
| getVertexWorldPosition | Instance | `boneName: string, vertex: integer` | `Vector3` | `obj:getVertexWorldPosition(boneName, vertex)` |
| getRandomVertex | Instance | `boneName: string, direction: integer` | `integer` | `obj:getRandomVertex(boneName, direction)` |
| notifyDirty | Instance | `` | `void` | `obj:notifyDirty()` |
| reload | Instance | `` | `void` | `obj:reload()` |
| serialise | Instance | `` | `void` | `obj:serialise()` |
| updateAppearance | Instance | `` | `void` | `obj:updateAppearance()` |
| updatePortrait | Instance | `` | `void` | `obj:updatePortrait()` |
| updateMovementScale | Instance | `` | `void` | `obj:updateMovementScale()` |
| switchLights | Instance | `on: boolean` | `void` | `obj:switchLights(on)` |
| hasLights | Instance | `` | `boolean` | `obj:hasLights()` |
| attachItem_Hair | Instance | `slot: string` | `boolean` | `obj:attachItem_Hair(slot)` |
| shaveHead | Instance | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isShaved | Instance | `` | `boolean` | `obj:isShaved()` |
| setFlayed | Instance | `on: boolean` | `void` | `obj:setFlayed(on)` |
| isFlayed | Instance | `` | `boolean` | `obj:isFlayed()` |
| isBarefoot | Instance | `` | `boolean` | `obj:isBarefoot()` |
| setVisible | Instance | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| getAttachmentsLoaded | Instance | `` | `boolean` | `obj:getAttachmentsLoaded()` |
| setAttachmentsVisible | Instance | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| createBody | Instance | `` | `void` | `obj:createBody()` |
| buildAttachments | Instance | `` | `void` | `obj:buildAttachments()` |
| setHairTexture | Instance | `name: string, channel: integer, alpha: integer, colour: Vector3, beard: boolean` | `void` | `obj:setHairTexture(name, channel, alpha, colour, beard)` |
| createAttachedObject | Instance | `` | `lightuserdata` | `obj:createAttachedObject()` |
| updateOverlap | Instance | `` | `void` | `obj:updateOverlap()` |
| updateCharaterTexture | Instance | `` | `void` | `obj:updateCharaterTexture()` |
| getCharacterHeightSpeedMultiplier | Instance | `` | `number` | `obj:getCharacterHeightSpeedMultiplier()` |
| attachItem [1] | Instance | `item: Item, mesh: string, slot: string` | `boolean` | `obj:attachItem(item, mesh, slot)` |
| attachItem [2] | Instance | `item: Item, slot: string` | `boolean` | `obj:attachItem(item, slot)` |
| detachItem [1] | Instance | `item: Item` | `boolean` | `obj:detachItem(item)` |
| detachItem [2] | Instance | `slot: string` | `boolean` | `obj:detachItem(slot)` |
| getVertexPosition | Instance | `index: integer` | `Vector3` | `obj:getVertexPosition(index)` |
| getRandomVertexPosition | Instance | `boneName: string, direction: integer` | `Vector3` | `obj:getRandomVertexPosition(boneName, direction)` |
| chooseBodyMesh | Instance | `` | `void` | `obj:chooseBodyMesh()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setGender | Instance | `female: boolean` | `void` | `obj:setGender(female)` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| setAttachmentsVisible | Instance | `visible: boolean` | `void` | `obj:setAttachmentsVisible(visible)` |
| setHiddenPartsEnabled | Instance | `enabled: boolean` | `void` | `obj:setHiddenPartsEnabled(enabled)` |
| showFace | Instance | `show: boolean` | `void` | `obj:showFace(show)` |
| setFlayed | Instance | `f: boolean` | `void` | `obj:setFlayed(f)` |
| isFlayed | Instance | `` | `boolean` | `obj:isFlayed()` |
| updateProportions | Instance | `` | `void` | `obj:updateProportions()` |
| createBody | Instance | `` | `void` | `obj:createBody()` |
| updateAppearance | Instance | `` | `void` | `obj:updateAppearance()` |
| updateHiddenParts | Instance | `` | `void` | `obj:updateHiddenParts()` |
| updatePysiqueFromStats | Instance | `` | `void` | `obj:updatePysiqueFromStats()` |
| updatePhysiqueMuscleMults | Instance | `` | `void` | `obj:updatePhysiqueMuscleMults()` |
| updateCharaterTexture | Instance | `` | `void` | `obj:updateCharaterTexture()` |
| setPosture | Instance | `posture: number, neck: number, shoulders: number` | `void` | `obj:setPosture(posture, neck, shoulders)` |

## AppearanceManager
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Metatable:** `KenshiLua.AppearanceManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| races | `GameDataFastArrayBinding::ArrayType` | RW | `obj.races = <value>` |
| characterIdleAnimations | `AnimationDataFastArrayBinding::ArrayType` | RW | `obj.characterIdleAnimations = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getInstance | Static / Instance | `` | `AppearanceManager` | `AppearanceManager.getInstance()`<br>`obj:getInstance()` |
| createAppearanceData | Instance | `` | `GameDataCopyStandalone` | `obj:createAppearanceData()` |
| cleanValidateAppearanceData | Instance | `` | `void` | `obj:cleanValidateAppearanceData()` |
| resetAll | Instance | `clearAttachments: boolean` | `void` | `obj:resetAll(clearAttachments)` |
| randomiseAll | Instance | `` | `void` | `obj:randomiseAll()` |
| randomiseAllManual | Instance | `faceRandomnessMult: number, bodyRandomnessMult: number` | `void` | `obj:randomiseAllManual(faceRandomnessMult, bodyRandomnessMult)` |
| randomHair | Instance | `` | `void` | `obj:randomHair()` |
| randomFace | Instance | `` | `void` | `obj:randomFace()` |
| randomFaceManual | Instance | `randomnessMult: number` | `void` | `obj:randomFaceManual(randomnessMult)` |
| randomPoses | Instance | `deviation: number` | `void` | `obj:randomPoses(deviation)` |
| randomBody | Instance | `isPlayer: boolean` | `void` | `obj:randomBody(isPlayer)` |
| randomBodyManual | Instance | `randomnessMult: number` | `void` | `obj:randomBodyManual(randomnessMult)` |
| randomGender | Instance | `femaleChance: number` | `void` | `obj:randomGender(femaleChance)` |
| randomAnimations | Instance | `` | `void` | `obj:randomAnimations()` |
| getRaceData | Instance | `index: integer` | `GameData` | `obj:getRaceData(index)` |
| getRaceIndex | Instance | `` | `integer` | `obj:getRaceIndex()` |
| getRacesCount | Instance | `` | `integer` | `obj:getRacesCount()` |
| isSingleGender | Instance | `` | `boolean` | `obj:isSingleGender()` |
| setGender | Instance | `genderValue: integer` | `void` | `obj:setGender(genderValue)` |
| setHead | Instance | `` | `void` | `obj:setHead()` |
| getHeadName | Instance | `` | `void` | `obj:getHeadName()` |
| setRandomHead | Instance | `` | `void` | `obj:setRandomHead()` |
| getHeadIsValid | Instance | `` | `boolean` | `obj:getHeadIsValid()` |
| setAttachment | Instance | `slot: integer, index: integer` | `void` | `obj:setAttachment(slot, index)` |
| getAttachmentName | Instance | `slot: integer` | `void` | `obj:getAttachmentName(slot)` |
| updateModifiers | Instance | `` | `void` | `obj:updateModifiers()` |
| getNormalMap_Plain | Instance | `` | `void` | `obj:getNormalMap_Plain()` |
| getNormalMap_Muscle | Instance | `` | `void` | `obj:getNormalMap_Muscle()` |
| getNormalMap_Starving | Instance | `` | `void` | `obj:getNormalMap_Starving()` |
| getCharacterIdleAnimations | Instance | `` | `AnimationDataFastArrayBinding::ArrayType` | `obj:getCharacterIdleAnimations()` |

## AppearanceManager::AppearanceData
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_AppearanceData`

## AppearanceManager::DataCategory
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataCategory`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setValue | Instance | `arg1: string` | `void` | `obj:setValue(arg1)` |
| getValue | Instance | `` | `integer` | `obj:getValue()` |

## AppearanceManager::DataRange
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataRange`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clamp | Instance | `` | `void` | `obj:clamp()` |

## AppearanceManager::DataRangePose
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataRangePose`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clamp | Instance | `` | `void` | `obj:clamp()` |

## AppearanceManager::DataRangeVector
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_DataRangeVector`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addValue | Instance | `value: Vector3` | `void` | `obj:addValue(value)` |
| getValue | Instance | `valueIndex: integer` | `Vector3` | `obj:getValue(valueIndex)` |
| getValueIndex | Instance | `value: Vector3` | `integer` | `obj:getValueIndex(value)` |
| size | Instance | `` | `integer` | `obj:size()` |
| clamp | Instance | `` | `void` | `obj:clamp()` |

## AppearanceManager::Gender
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`
**Parent Class:** [`AppearanceManager`](#appearancemanager)
**Metatable:** `KenshiLua.AppearanceManager_Gender`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isMale | Instance | `` | `boolean` | `obj:isMale()` |
| isFemale | Instance | `` | `boolean` | `obj:isFemale()` |
| toString | Instance | `` | `void` | `obj:toString()` |
| getValue | Instance | `` | `integer` | `obj:getValue()` |

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
| materialType | `integer` | RW | `obj.materialType = <value>` |
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
| armourClassEnum | `integer` | RW | `obj.armourClassEnum = <value>` |
| bodypartCoverage | `unknown` | RW | `obj.bodypartCoverage = <value>` |
| stigma | `integer` | RW | `obj.stigma = <value>` |
| weatherProtections | `integer` | RW | `obj.weatherProtections = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getClassType | Instance | `` | `integer` | `obj:getClassType()` |
| isArmour | Instance | `` | `Armour` | `obj:isArmour()` |
| getItemWeight | Instance | `` | `number` | `obj:getItemWeight()` |
| getValueSingle | Instance | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| didIHitFlesh | Instance | `` | `boolean` | `obj:didIHitFlesh()` |
| hasArmourCoverage | Instance | `` | `boolean` | `obj:hasArmourCoverage()` |
| getCraftTime | Instance | `` | `number` | `obj:getCraftTime()` |
| getWeatherProtection_simple | Instance | `weather: integer` | `number` | `obj:getWeatherProtection_simple(weather)` |
| getArmourCraftingMaterialConsumptionRate | Instance | `` | `number` | `obj:getArmourCraftingMaterialConsumptionRate()` |

## Array2d
**Header:** `extern/KenshiLib/Include/kenshi/util/array2d.h`
**Metatable:** `KenshiLua.Array2d`

## BackpackInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.BackpackInventoryLayout`

## BackThreadMessagesToMainT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.BackThreadMessagesToMainT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| swapMutex | `unknown` | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| flush | Instance | `` | `boolean` | `obj:flush()` |

## BadSize
**Header:** `extern/KenshiLib/Include/kenshi/util/Array2d.h`
**Metatable:** `KenshiLua.BadSize`

## BaseLayout
**Header:** `???`
**Metatable:** `KenshiLua.BaseLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mMainWidget | `lightuserdata` | R | `obj.mMainWidget` |
| mPrefix | `string` | RW | `obj.mPrefix = <value>` |
| mLayoutName | `string` | RW | `obj.mLayoutName = <value>` |

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
| crimes | `integer` | RW | `obj.crimes = <value>` |
| bountyHasBeenClaimedOnce | `boolean` | RW | `obj.bountyHasBeenClaimedOnce = <value>` |
| bountyAssignmentStartedTime | `TimeOfDay` | RW | `obj.bountyAssignmentStartedTime = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addCrime | Instance | `crime: integer` | `void` | `obj:addCrime(crime)` |
| hasCrime | Instance | `crime: integer` | `boolean` | `obj:hasCrime(crime)` |

## BountyManager
**Header:** `extern/KenshiLib/Include/kenshi/BountyManager.h`
**Metatable:** `KenshiLua.BountyManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bounties | `unknown` | RW | `obj.bounties = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| _hasAccessPass | `Faction` | RW | `obj._hasAccessPass = <value>` |
| accessPassExpirationTime | `TimeOfDay` | RW | `obj.accessPassExpirationTime = <value>` |
| committingCrime | `integer` | RW | `obj.committingCrime = <value>` |
| crimeAgainstFaction | `Faction` | RW | `obj.crimeAgainstFaction = <value>` |
| usingTrainingEquipmentOf | `Faction` | RW | `obj.usingTrainingEquipmentOf = <value>` |
| crimeAgainst | `unknown` | RW | `obj.crimeAgainst = <value>` |
| crimeExpiry | `number` | RW | `obj.crimeExpiry = <value>` |
| prisonSentenceBeganTime | `TimeOfDay` | RW | `obj.prisonSentenceBeganTime = <value>` |
| prisonSentenceToServe | `number` | RW | `obj.prisonSentenceToServe = <value>` |
| _hadABountyAssignedForCurrentCrime | `boolean` | RW | `obj._hadABountyAssignedForCurrentCrime = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| _getHighestBountyFaction | Instance | `` | `Faction` | `obj:_getHighestBountyFaction()` |
| getBountyRecognitionThreshold | Instance | `` | `integer` | `obj:getBountyRecognitionThreshold()` |
| getTotalBounty | Instance | `` | `integer` | `obj:getTotalBounty()` |
| update | Instance | `frameTime: number` | `void` | `obj:update(frameTime)` |
| getBountyExpiryStringForGUI | Instance | `` | `string` | `obj:getBountyExpiryStringForGUI()` |
| notifyPossibleCrimeWitnessed | Instance | `time: number` | `void` | `obj:notifyPossibleCrimeWitnessed(time)` |
| isCommittingCrime | Instance | `` | `boolean` | `obj:isCommittingCrime()` |
| _getBountyFaction | Instance | `` | `Faction` | `obj:_getBountyFaction()` |
| getPercievedBounty | Instance | `` | `integer` | `obj:getPercievedBounty()` |
| getActualBounty | Instance | `` | `integer` | `obj:getActualBounty()` |
| notifyPlayerClaimBounty | Instance | `` | `void` | `obj:notifyPlayerClaimBounty()` |
| bountyAlreadyBeenClaimedByPlayer | Instance | `` | `boolean` | `obj:bountyAlreadyBeenClaimedByPlayer()` |
| assignBountyForCrimes | Instance | `` | `void` | `obj:assignBountyForCrimes()` |
| unfairAddToBounty | Instance | `amount: integer` | `void` | `obj:unfairAddToBounty(amount)` |
| clearBounty | Instance | `` | `void` | `obj:clearBounty()` |
| load | Instance | `` | `void` | `obj:load()` |
| save | Instance | `` | `void` | `obj:save()` |
| setCrime | Instance | `crime: integer` | `boolean` | `obj:setCrime(crime)` |
| notifyCrimeWitnessed | Instance | `expirytime: integer, what: integer` | `void` | `obj:notifyCrimeWitnessed(expirytime, what)` |
| notifyStartPrisonSentence | Instance | `` | `void` | `obj:notifyStartPrisonSentence()` |
| hasAccessPass | Instance | `` | `boolean` | `obj:hasAccessPass()` |
| giveAccessPass | Instance | `minutes: number` | `void` | `obj:giveAccessPass(minutes)` |
| crimeToStr | Instance | `` | `string` | `obj:crimeToStr()` |
| getBountyForCrime | Instance | `` | `integer` | `obj:getBountyForCrime()` |
| getPrisonSentenceInHours | Instance | `` | `integer` | `obj:getPrisonSentenceInHours()` |
| getBountyExpirationTime | Instance | `` | `number` | `obj:getBountyExpirationTime()` |

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
| designation | `integer` | RW | `obj.designation = <value>` |
| publicDaytime | `boolean` | RW | `obj.publicDaytime = <value>` |
| residentSquad | `unknown` | RW | `obj.residentSquad = <value>` |
| residentSquadTemplate | `GameData` | RW | `obj.residentSquadTemplate = <value>` |
| isAnInteriorObject | `boolean` | RW | `obj.isAnInteriorObject = <value>` |
| instanceID | `InstanceID` | RW | `obj.instanceID = <value>` |
| layoutInstanceID | `string` | RW | `obj.layoutInstanceID = <value>` |
| specialFunction | `integer` | RW | `obj.specialFunction = <value>` |
| _buildState | `Building::ConstructionState` | RW | `obj._buildState = <value>` |
| classType | `integer` | RW | `obj.classType = <value>` |
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
| _town | `unknown` | RW | `obj._town = <value>` |
| myInterior | `lightuserdata` | R | `obj.myInterior` |
| buildingsManager | `TownBuildingsManager` | RW | `obj.buildingsManager = <value>` |
| rootNode | `lightuserdata` | R | `obj.rootNode` |
| soundEmitter | `lightuserdata` | R | `obj.soundEmitter` |
| hasAudio | `boolean` | RW | `obj.hasAudio = <value>` |
| interiorGround | `integer` | RW | `obj.interiorGround = <value>` |
| exteriorGround | `integer` | RW | `obj.exteriorGround = <value>` |
| physical | `lightuserdata` | R | `obj.physical` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getScale | Instance | `` | `number` | `obj:getScale()` |
| getBuildState | Instance | `` | `Building::ConstructionState` | `obj:getBuildState()` |
| getBuildState_ActualNonShared | Instance | `` | `Building::ConstructionState` | `obj:getBuildState_ActualNonShared()` |
| select | Instance | `` | `void` | `obj:select()` |
| getBuildingDesignation | Instance | `` | `integer` | `obj:getBuildingDesignation()` |
| addConstructionProgress | Instance | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| setConstructionProgress | Instance | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| notifyConstructionComplete | Instance | `` | `void` | `obj:notifyConstructionComplete()` |
| addDismantleProgress | Instance | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| notifyConstructionDismantling | Instance | `` | `void` | `obj:notifyConstructionDismantling()` |
| dropMats | Instance | `` | `void` | `obj:dropMats()` |
| upgrade | Instance | `` | `void` | `obj:upgrade()` |
| downgrade | Instance | `` | `void` | `obj:downgrade()` |
| canUpgrade | Instance | `` | `GameData` | `obj:canUpgrade()` |
| canDowngrade | Instance | `` | `GameData` | `obj:canDowngrade()` |
| canDismantle | Instance | `` | `boolean` | `obj:canDismantle()` |
| buyMeAsk | Instance | `` | `void` | `obj:buyMeAsk()` |
| buyMeCallback | Instance | `result: integer` | `void` | `obj:buyMeCallback(result)` |
| calculateSaleValue | Instance | `` | `integer` | `obj:calculateSaleValue()` |
| loadNodes | Instance | `` | `void` | `obj:loadNodes()` |
| isPublic | Instance | `` | `boolean` | `obj:isPublic()` |
| togglePublic | Instance | `` | `void` | `obj:togglePublic()` |
| dismantleButton | Instance | `` | `void` | `obj:dismantleButton()` |
| pauseButton | Instance | `` | `void` | `obj:pauseButton()` |
| confirmDismantle | Instance | `r: integer` | `void` | `obj:confirmDismantle(r)` |
| isAShop | Instance | `` | `boolean` | `obj:isAShop()` |
| isForSale | Instance | `` | `boolean` | `obj:isForSale()` |
| isAWall | Instance | `` | `WallBuilding` | `obj:isAWall()` |
| isAWallRamp | Instance | `` | `boolean` | `obj:isAWallRamp()` |
| hasInterior | Instance | `` | `boolean` | `obj:hasInterior()` |
| affectsNavmesh | Instance | `` | `boolean` | `obj:affectsNavmesh()` |
| setResidentSquad | Instance | `` | `void` | `obj:setResidentSquad()` |
| getResidentSquadLeader | Instance | `` | `Character` | `obj:getResidentSquadLeader()` |
| setDesignation | Instance | `d: integer` | `void` | `obj:setDesignation(d)` |
| getWallEndPosition | Instance | `` | `Vector3` | `obj:getWallEndPosition()` |
| setupMiningResourceLevel | Instance | `` | `void` | `obj:setupMiningResourceLevel()` |
| getMiningResourceLevel | Instance | `` | `number` | `obj:getMiningResourceLevel()` |
| addAnInternalBuilding | Instance | `` | `void` | `obj:addAnInternalBuilding()` |
| getNumInternalBuildings | Instance | `` | `integer` | `obj:getNumInternalBuildings()` |
| moveMountedBuildings | Instance | `` | `void` | `obj:moveMountedBuildings()` |
| reCheckInsideOutsideFortificationStatus | Instance | `` | `void` | `obj:reCheckInsideOutsideFortificationStatus()` |
| setInsideTownWalls | Instance | `code: integer` | `void` | `obj:setInsideTownWalls(code)` |
| postCreationPathfinderSetupStuff | Instance | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| getSpecialFunction | Instance | `` | `integer` | `obj:getSpecialFunction()` |
| getFunctionStuff | Instance | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| getUseableStuff | Instance | `` | `UseableStuff` | `obj:getUseableStuff()` |
| isBroken | Instance | `` | `boolean` | `obj:isBroken()` |
| setBroken | Instance | `_a1: boolean` | `void` | `obj:setBroken(_a1)` |
| switchPowerOn | Instance | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| isPowerOn | Instance | `` | `boolean` | `obj:isPowerOn()` |
| isDamaged | Instance | `` | `boolean` | `obj:isDamaged()` |
| isDestroyed | Instance | `` | `boolean` | `obj:isDestroyed()` |
| isSign | Instance | `` | `boolean` | `obj:isSign()` |
| setDestroyed | Instance | `d: boolean` | `void` | `obj:setDestroyed(d)` |
| canBeDestroyed | Instance | `` | `boolean` | `obj:canBeDestroyed()` |
| setNestTag | Instance | `` | `void` | `obj:setNestTag()` |
| getReachRange | Instance | `` | `number` | `obj:getReachRange()` |
| hasShopCountersSelling | Instance | `type: integer` | `boolean` | `obj:hasShopCountersSelling(type)` |
| getBuildingClass | Instance | `` | `integer` | `obj:getBuildingClass()` |
| needsSaving | Instance | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| notifyChange | Instance | `` | `void` | `obj:notifyChange()` |
| getInstanceID | Instance | `` | `InstanceID` | `obj:getInstanceID()` |
| setToDefaultFactionDivision | Instance | `` | `void` | `obj:setToDefaultFactionDivision()` |
| getOutputBasedRotationSpeedMult | Instance | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| calculateEfficiencyMult | Instance | `` | `number` | `obj:calculateEfficiencyMult()` |
| getSoundIntensity | Instance | `` | `number` | `obj:getSoundIntensity()` |
| loadUnloadCheck | Instance | `` | `void` | `obj:loadUnloadCheck()` |
| _saveBuildingState | Instance | `doorID: string` | `void` | `obj:_saveBuildingState(doorID)` |
| _loadBuildingState | Instance | `doorID: string` | `void` | `obj:_loadBuildingState(doorID)` |
| getGUIName | Instance | `category: integer` | `void` | `obj:getGUIName(category)` |
| getGUIState | Instance | `category: integer` | `void` | `obj:getGUIState(category)` |
| getGUICondition | Instance | `category: integer` | `void` | `obj:getGUICondition(category)` |
| getGUIUpgrade | Instance | `category: integer` | `void` | `obj:getGUIUpgrade(category)` |
| getGUIDestroyButton | Instance | `category: integer` | `void` | `obj:getGUIDestroyButton(category)` |
| getProductionBuilding | Instance | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| getProductionMultForGUI | Instance | `` | `number` | `obj:getProductionMultForGUI()` |
| getProductionMult | Instance | `` | `number` | `obj:getProductionMult()` |
| isThePlayer | Instance | `` | `boolean` | `obj:isThePlayer()` |
| doorStuff | Instance | `` | `DoorStuff` | `obj:doorStuff()` |
| doorParentBuilding | Instance | `` | `Building` | `obj:doorParentBuilding()` |
| isDoor | Instance | `` | `boolean` | `obj:isDoor()` |
| isGate | Instance | `` | `GatewayBuilding` | `obj:isGate()` |
| getDoor | Instance | `` | `DoorStuff` | `obj:getDoor()` |
| getParentLayout | Instance | `` | `lightuserdata` | `obj:getParentLayout()` |
| isFurniture | Instance | `` | `boolean` | `obj:isFurniture()` |
| isFurnitureOrDoor | Instance | `` | `boolean` | `obj:isFurnitureOrDoor()` |
| getIsOutsideFurniture | Instance | `` | `boolean` | `obj:getIsOutsideFurniture()` |
| setIsOutsideFurniture | Instance | `value: boolean` | `void` | `obj:setIsOutsideFurniture(value)` |
| getCurrentTownLocation | Instance | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| furnitureParentBuilding | Instance | `` | `Building` | `obj:furnitureParentBuilding()` |
| hasAnOpenDoor | Instance | `` | `boolean` | `obj:hasAnOpenDoor()` |
| allowAnimals | Instance | `` | `boolean` | `obj:allowAnimals()` |
| update | Instance | `` | `void` | `obj:update()` |
| threadedUpdate | Instance | `` | `void` | `obj:threadedUpdate()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |
| isPhysical | Instance | `` | `boolean` | `obj:isPhysical()` |
| checkLoadedProperly | Instance | `` | `void` | `obj:checkLoadedProperly()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| loadFromSerialise_TheDoors | Instance | `` | `void` | `obj:loadFromSerialise_TheDoors()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| getDoorLock | Instance | `` | `lightuserdata` | `obj:getDoorLock()` |
| hasDoorLock | Instance | `` | `boolean` | `obj:hasDoorLock()` |
| getMouseCursor | Instance | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| _changeTown | Instance | `` | `void` | `obj:_changeTown()` |
| getTownHandle | Instance | `` | `void` | `obj:getTownHandle()` |
| getTown | Instance | `` | `TownBase` | `obj:getTown()` |
| getRealTown | Instance | `` | `Town` | `obj:getRealTown()` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| destroyDoors | Instance | `` | `void` | `obj:destroyDoors()` |
| createTriggerHull | Instance | `` | `void` | `obj:createTriggerHull()` |
| destroyAudioObject | Instance | `` | `void` | `obj:destroyAudioObject()` |
| getGroundType | Instance | `inside: boolean` | `integer` | `obj:getGroundType(inside)` |
| isCeilingMounted | Instance | `` | `boolean` | `obj:isCeilingMounted()` |
| setFloorVisibility | Instance | `floor: integer, vis: boolean` | `void` | `obj:setFloorVisibility(floor, vis)` |
| getNumFloors | Instance | `` | `integer` | `obj:getNumFloors()` |
| buildingComplete_RestoreMaterial | Instance | `` | `void` | `obj:buildingComplete_RestoreMaterial()` |
| loadInteriorPhysical | Instance | `on: boolean` | `void` | `obj:loadInteriorPhysical(on)` |
| loadInteriorGraphics | Instance | `on: boolean` | `void` | `obj:loadInteriorGraphics(on)` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| calculateLeftPost | Instance | `` | `Vector3` | `obj:calculateLeftPost()` |
| setupLevelData | Instance | `interior: string, exterior: string` | `void` | `obj:setupLevelData(interior, exterior)` |
| getLinkLength | Instance | `` | `number` | `obj:getLinkLength()` |
| getRootNode | Instance | `` | `lightuserdata` | `obj:getRootNode()` |
| getZoneMapLocation | Instance | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| clearTownBuildingsManagerPtr | Instance | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| setup [1] | Instance | `buildingdata: GameData` | `void` | `obj:setup(buildingdata)` |
| setup [2] | Instance | `` | `void` | `obj:setup()` |
| setupFromData | Instance | `` | `void` | `obj:setupFromData()` |
| setupAudio | Instance | `` | `void` | `obj:setupAudio()` |
| switchLights | Instance | `on: boolean` | `void` | `obj:switchLights(on)` |
| isBroken | Instance | `` | `boolean` | `obj:isBroken()` |
| getMouseCursor | Instance | `` | `integer` | `obj:getMouseCursor()` |
| getDirectionMarker | Instance | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| getDirectionMarkerQuat | Instance | `currentPosition: Vector3` | `Quaternion` | `obj:getDirectionMarkerQuat(currentPosition)` |
| isCreated | Instance | `` | `boolean` | `obj:isCreated()` |
| updateUsageNodes | Instance | `` | `void` | `obj:updateUsageNodes()` |
| forceValidUsageNodesValidation | Instance | `` | `void` | `obj:forceValidUsageNodesValidation()` |
| addUsageNode | Instance | `nodeId: string` | `void` | `obj:addUsageNode(nodeId)` |
| removeUsageNode | Instance | `nodeId: string` | `void` | `obj:removeUsageNode(nodeId)` |
| clearUsageNodes | Instance | `` | `void` | `obj:clearUsageNodes()` |
| notifyEffect | Instance | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| updatePhysicalWithProgress | Instance | `` | `void` | `obj:updatePhysicalWithProgress()` |
| recalculateWorldAABB | Instance | `` | `void` | `obj:recalculateWorldAABB()` |
| selectPartMaterial | Instance | `` | `GameData` | `obj:selectPartMaterial()` |
| getSeed | Instance | `` | `integer` | `obj:getSeed()` |
| onBuildingLoaded | Instance | `` | `void` | `obj:onBuildingLoaded()` |
| updateBadNodes | Instance | `` | `void` | `obj:updateBadNodes()` |
| isIndoors | Instance | `` | `void` | `obj:isIndoors()` |
| isIndoors_notDestroyed | Instance | `` | `void` | `obj:isIndoors_notDestroyed()` |
| getMountedBuilding | Instance | `` | `void` | `obj:getMountedBuilding()` |
| removeAnInternalBuilding | Instance | `` | `void` | `obj:removeAnInternalBuilding()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| getLayoutInstanceID | Instance | `` | `string` | `obj:getLayoutInstanceID()` |
| getEntityMaterialName | Static / Instance | `` | `string` | `Building.getEntityMaterialName()`<br>`obj:getEntityMaterialName()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addMaterials | Instance | `` | `void` | `obj:addMaterials()` |
| materialsEmpty | Instance | `` | `boolean` | `obj:materialsEmpty()` |
| getBuildingSpeedMultiplier | Static / Instance | `` | `number` | `Building::ConstructionState.getBuildingSpeedMultiplier()`<br>`obj:getBuildingSpeedMultiplier()` |
| getBuildingTimeInHours | Static / Instance | `` | `number` | `Building::ConstructionState.getBuildingTimeInHours()`<br>`obj:getBuildingTimeInHours()` |
| isOverThreshold | Instance | `` | `boolean` | `obj:isOverThreshold()` |
| getHealthBarProgress | Instance | `` | `number` | `obj:getHealthBarProgress()` |
| getConstructionMaterialProgress | Instance | `` | `number` | `obj:getConstructionMaterialProgress()` |
| getHealthBarActual | Instance | `` | `string` | `obj:getHealthBarActual()` |
| getMaterial | Instance | `` | `ConstructionState::BuildMaterial` | `obj:getMaterial()` |
| setup | Instance | `` | `void` | `obj:setup()` |
| getTotalMats | Instance | `` | `number` | `obj:getTotalMats()` |
| getTotalMatsPresent | Instance | `` | `number` | `obj:getTotalMatsPresent()` |
| getNeededMats | Instance | `` | `void` | `obj:getNeededMats()` |
| needsMat | Instance | `` | `integer` | `obj:needsMat()` |
| needMats | Instance | `` | `boolean` | `obj:needMats()` |
| getBuildingSpeedMultiplier | Static / Instance | `` | `number` | `Building::ConstructionState.getBuildingSpeedMultiplier()`<br>`obj:getBuildingSpeedMultiplier()` |
| getBuildingTimeInHours | Static / Instance | `` | `number` | `Building::ConstructionState.getBuildingTimeInHours()`<br>`obj:getBuildingTimeInHours()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getMaterialsBarProgress | Instance | `` | `number` | `obj:getMaterialsBarProgress()` |
| getNumRemaining | Instance | `` | `number` | `obj:getNumRemaining()` |

## BuildingContainerInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`
**Metatable:** `KenshiLua.BuildingContainerInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| capacityText | `MyGUI::Widget` | RW | `obj.capacityText = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCapacity | Instance | `value: integer, full: boolean` | `void` | `obj:setCapacity(value, full)` |
| setupSections | Instance | `inventoryGUI: userdata, sections: userdata, inventory: userdata` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setupSections | Instance | `inventoryGUI: userdata, sections: userdata, inventory: userdata` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |
| setInput | Instance | `inputIndex: integer, name: string, status: string` | `void` | `obj:setInput(inputIndex, name, status)` |
| setOutput | Instance | `name: string` | `void` | `obj:setOutput(name)` |
| setInputProgress | Instance | `inputIdx: integer, progress: number` | `void` | `obj:setInputProgress(inputIdx, progress)` |
| setInputEnabled | Instance | `inputIdx: integer, value: boolean` | `void` | `obj:setInputEnabled(inputIdx, value)` |
| setOutputProgress | Instance | `progress: number` | `void` | `obj:setOutputProgress(progress)` |
| setInputItem | Instance | `inputIdx: integer, visible: boolean` | `void` | `obj:setInputItem(inputIdx, visible)` |
| setOutputItem | Instance | `visible: boolean` | `void` | `obj:setOutputItem(visible)` |

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
| confirmButton | `lightuserdata` | R | `obj.confirmButton` |
| undoButton | `lightuserdata` | R | `obj.undoButton` |
| closeButton | `lightuserdata` | R | `obj.closeButton` |
| categoriesList | `lightuserdata` | R | `obj.categoriesList` |
| buildingsList | `lightuserdata` | R | `obj.buildingsList` |
| buildingTxt | `lightuserdata` | R | `obj.buildingTxt` |
| buildingTypePrevButton | `lightuserdata` | R | `obj.buildingTypePrevButton` |
| buildingTypeNextButton | `lightuserdata` | R | `obj.buildingTypeNextButton` |
| buildingImageBox | `lightuserdata` | R | `obj.buildingImageBox` |
| statsPanel | `lightuserdata` | R | `obj.statsPanel` |
| descriptionTxt | `lightuserdata` | R | `obj.descriptionTxt` |
| messageTextBox | `lightuserdata` | R | `obj.messageTextBox` |
| floorDownButton | `lightuserdata` | R | `obj.floorDownButton` |
| floorUpButton | `lightuserdata` | R | `obj.floorUpButton` |
| floorText | `lightuserdata` | R | `obj.floorText` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setMessage | Instance | `message: string` | `void` | `obj:setMessage(message)` |
| getBuildingListWidget | Instance | `` | `lightuserdata` | `obj:getBuildingListWidget()` |
| setVisible | Instance | `v: boolean` | `void` | `obj:setVisible(v)` |
| setupData | Instance | `` | `void` | `obj:setupData()` |
| listCategories | Instance | `` | `void` | `obj:listCategories()` |
| listBuildingGroups | Instance | `` | `void` | `obj:listBuildingGroups()` |
| updateBuildingUI | Instance | `` | `void` | `obj:updateBuildingUI()` |
| build | Instance | `` | `void` | `obj:build()` |
| showBuildingStats | Instance | `` | `void` | `obj:showBuildingStats()` |
| update | Instance | `` | `void` | `obj:update()` |
| changeCurrentIndex | Instance | `index: integer` | `void` | `obj:changeCurrentIndex(index)` |
| compareBuildMaterials | Static / Instance | `` | `boolean` | `BuildModeWindow.compareBuildMaterials()`<br>`obj:compareBuildMaterials()` |

## BuildModeWindow::BuildingCategory
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`
**Parent Class:** [`BuildModeWindow`](#buildmodewindow)
**Metatable:** `KenshiLua.BuildingCategory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |

## BuildModeWindow::BuildingGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/BuildModeWindow.h`
**Parent Class:** [`BuildModeWindow`](#buildmodewindow)
**Metatable:** `KenshiLua.BuildingGroup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |

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
| objectCurrentlyFollowing | `unknown` | RW | `obj.objectCurrentlyFollowing = <value>` |
| objectCurrentlyFollowingOffset | `Vector3` | RW | `obj.objectCurrentlyFollowingOffset = <value>` |
| center | `lightuserdata` | RW | `obj.center = <value>` |
| altitude | `number` | RW | `obj.altitude = <value>` |
| camera | `lightuserdata` | R | `obj.camera` |
| node | `lightuserdata` | R | `obj.node` |
| currentMusic | `integer` | RW | `obj.currentMusic = <value>` |
| inBuilding | `unknown` | RW | `obj.inBuilding = <value>` |
| timeInGame | `number` | RW | `obj.timeInGame = <value>` |
| targetPositionY | `number` | RW | `obj.targetPositionY = <value>` |
| speedY | `number` | RW | `obj.speedY = <value>` |
| centerBuilding | `Building` | RW | `obj.centerBuilding = <value>` |
| centerBuildingY | `number` | RW | `obj.centerBuildingY = <value>` |
| currentCollisionGroup | `integer` | RW | `obj.currentCollisionGroup = <value>` |
| currentFloor | `integer` | RW | `obj.currentFloor = <value>` |
| freeCameraMode | `boolean` | RW | `obj.freeCameraMode = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | Instance | `` | `void` | `obj:reset()` |
| update | Instance | `controlEnabled: boolean` | `void` | `obj:update(controlEnabled)` |
| focusCameraOnObject | Instance | `offset: Vector3, nearZoom: boolean` | `void` | `obj:focusCameraOnObject(offset, nearZoom)` |
| updateOptionSettings | Instance | `` | `void` | `obj:updateOptionSettings()` |
| save | Instance | `` | `void` | `obj:save()` |
| load | Instance | `` | `void` | `obj:load()` |
| teleport | Instance | `pos: Vector3` | `void` | `obj:teleport(pos)` |
| stopFollowing | Instance | `` | `void` | `obj:stopFollowing()` |
| manuallySetOrientationAndZoom | Instance | `rot: Quaternion, zoom: number` | `void` | `obj:manuallySetOrientationAndZoom(rot, zoom)` |
| getFacingDirection | Instance | `` | `Vector3` | `obj:getFacingDirection()` |
| getCenter | Instance | `` | `Vector3` | `obj:getCenter()` |
| getCameraPos | Instance | `` | `Vector3` | `obj:getCameraPos()` |
| getCenterNode | Instance | `` | `lightuserdata` | `obj:getCenterNode()` |
| getCameraNode | Instance | `` | `lightuserdata` | `obj:getCameraNode()` |
| isInitialised | Instance | `` | `boolean` | `obj:isInitialised()` |
| isFreeCameraMode | Instance | `` | `boolean` | `obj:isFreeCameraMode()` |
| setFreeCameraMode | Instance | `on: boolean` | `void` | `obj:setFreeCameraMode(on)` |
| updateFreeCamera | Instance | `` | `void` | `obj:updateFreeCamera()` |
| move | Instance | `dir: Vector3` | `void` | `obj:move(dir)` |
| zoom | Instance | `` | `void` | `obj:zoom()` |
| toGround | Instance | `smooth: boolean` | `void` | `obj:toGround(smooth)` |
| setZoomDist | Instance | `dist: number` | `void` | `obj:setZoomDist(dist)` |
| rotate | Instance | `_yaw: number, _pitch: number` | `void` | `obj:rotate(_yaw, _pitch)` |
| rotationUpdate | Instance | `` | `void` | `obj:rotationUpdate()` |
| updateAudio | Instance | `` | `void` | `obj:updateAudio()` |
| followObject | Instance | `` | `void` | `obj:followObject()` |
| getFollowObject | Instance | `` | `void` | `obj:getFollowObject()` |

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
| _currentProneState | `integer` | RW | `obj._currentProneState = <value>` |
| isVisibleUpdateMode | `boolean` | RW | `obj.isVisibleUpdateMode = <value>` |
| setVisibleMsg | `boolean` | RW | `obj.setVisibleMsg = <value>` |
| stealthUnseen | `YesNoMaybe` | RW | `obj.stealthUnseen = <value>` |
| playerWantsMeToGetUp | `boolean` | RW | `obj.playerWantsMeToGetUp = <value>` |
| crimes | `BountyManager` | RW | `obj.crimes = <value>` |
| currentSkillUsing | `integer` | RW | `obj.currentSkillUsing = <value>` |
| stateBroadcast | `lightuserdata` | RW | `obj.stateBroadcast = <value>` |
| isVisibleAndNear | `boolean` | RW | `obj.isVisibleAndNear = <value>` |
| isOnScreen | `boolean` | RW | `obj.isOnScreen = <value>` |
| stealthMarkerArrows | `Character::AttachedArrowManager` | R | `obj.stealthMarkerArrows` |
| _isEngagedWithAPlayer | `boolean` | RW | `obj._isEngagedWithAPlayer = <value>` |
| isUsingTurret | `unknown` | RW | `obj.isUsingTurret = <value>` |
| isCurrentlyGettingUp | `boolean` | RW | `obj.isCurrentlyGettingUp = <value>` |
| isGettingEaten | `integer` | RW | `obj.isGettingEaten = <value>` |
| dialogue | `Dialogue` | RW | `obj.dialogue = <value>` |
| currentStumblePainAnimation | `string` | RW | `obj.currentStumblePainAnimation = <value>` |
| _isLiterallyUnderMeleeAttackRightNowForSure | `boolean` | RW | `obj._isLiterallyUnderMeleeAttackRightNowForSure = <value>` |
| _myMemory | `lightuserdata` | RW | `obj._myMemory = <value>` |
| lastGuyWhoDefeatedMe | `unknown` | RW | `obj.lastGuyWhoDefeatedMe = <value>` |
| myRace | `RaceData` | RW | `obj.myRace = <value>` |
| inventory | `Inventory` | RW | `obj.inventory = <value>` |
| rangedCombat | `lightuserdata` | RW | `obj.rangedCombat = <value>` |
| inWhat | `unknown` | RW | `obj.inWhat = <value>` |
| isChained | `boolean` | RW | `obj.isChained = <value>` |
| slaveOwner | `unknown` | RW | `obj.slaveOwner = <value>` |
| isCarryingSomething | `boolean` | RW | `obj.isCarryingSomething = <value>` |
| carringObjectLeftOrRight | `string` | RW | `obj.carringObjectLeftOrRight = <value>` |
| isCarryingLeftSide | `boolean` | RW | `obj.isCarryingLeftSide = <value>` |
| carryingObject | `unknown` | RW | `obj.carryingObject = <value>` |
| messages | `integer` | RW | `obj.messages = <value>` |
| messageSubject | `unknown` | RW | `obj.messageSubject = <value>` |
| ragdollNavmeshPosition | `Vector3` | RW | `obj.ragdollNavmeshPosition = <value>` |
| _isBeingCarried | `boolean` | RW | `obj._isBeingCarried = <value>` |
| lastUsedWeaponCategory | `integer` | RW | `obj.lastUsedWeaponCategory = <value>` |
| msgCarryMode | `Character::CarryMsg` | RW | `obj.msgCarryMode = <value>` |
| squadMemberID | `integer` | RW | `obj.squadMemberID = <value>` |
| diplomacyMultiplier | `number` | RW | `obj.diplomacyMultiplier = <value>` |
| _destinationInsideBuilding | `unknown` | RW | `obj._destinationInsideBuilding = <value>` |
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
| groundType | `integer` | RW | `obj.groundType = <value>` |
| armourType | `integer` | RW | `obj.armourType = <value>` |
| audioEmitter | `lightuserdata` | RW | `obj.audioEmitter = <value>` |
| terrainHeightPosition | `number` | RW | `obj.terrainHeightPosition = <value>` |
| inDoorsSetCooldown | `integer` | RW | `obj.inDoorsSetCooldown = <value>` |
| naturalWeapon | `Sword` | RW | `obj.naturalWeapon = <value>` |
| ragdollMessages | `CharacterRagdollMsgDequeBinding::DequeType` | RW | `obj.ragdollMessages = <value>` |
| audioData | `AkSoundPosition` | RW | `obj.audioData = <value>` |
| disguiseGUIFeedbacks | `integer` | R | `obj.disguiseGUIFeedbacks` |
| whoSeesMeSneaking | `Character::WhoSeesMe` | R | `obj.whoSeesMeSneaking` |
| inSomething | `integer` | RW | `obj.inSomething = <value>` |
| audioObject | `CharacterRagdollMsgDequeBinding::DequeType` | RW | `obj.audioObject = <value>` |
| activeEffects | `integer` | R | `obj.activeEffects` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isImmuneToOffscreenMode | Instance | `` | `boolean` | `obj:isImmuneToOffscreenMode()` |
| init | Instance | `` | `void` | `obj:init()` |
| isOnARoof | Instance | `` | `boolean` | `obj:isOnARoof()` |
| isOnAWall | Instance | `` | `boolean` | `obj:isOnAWall()` |
| getLightLevel | Instance | `` | `number` | `obj:getLightLevel()` |
| getHPMultiplier | Instance | `` | `number` | `obj:getHPMultiplier()` |
| healCompletely | Instance | `` | `void` | `obj:healCompletely()` |
| resetRagdollNavmeshSafePos | Instance | `` | `void` | `obj:resetRagdollNavmeshSafePos()` |
| setRagdollNavmeshSafePos | Instance | `` | `void` | `obj:setRagdollNavmeshSafePos()` |
| getFrameTime | Instance | `` | `number` | `obj:getFrameTime()` |
| frameSkip | Instance | `` | `void` | `obj:frameSkip()` |
| getCurrentNoiseRange | Instance | `` | `number` | `obj:getCurrentNoiseRange()` |
| isDestroyed | Instance | `` | `boolean` | `obj:isDestroyed()` |
| isLawEnforcement | Instance | `` | `boolean` | `obj:isLawEnforcement()` |
| canAssignBounties | Instance | `` | `boolean` | `obj:canAssignBounties()` |
| getDataType | Instance | `` | `integer` | `obj:getDataType()` |
| isDiplomaticStatus | Instance | `factorInBiome: boolean` | `boolean` | `obj:isDiplomaticStatus(factorInBiome)` |
| isLeadingAWarCampaign | Instance | `` | `boolean` | `obj:isLeadingAWarCampaign()` |
| isInAWarCampaign | Instance | `` | `lightuserdata` | `obj:isInAWarCampaign()` |
| wantsToTriggerCampaigns | Instance | `` | `boolean` | `obj:wantsToTriggerCampaigns()` |
| isUnique | Instance | `` | `boolean` | `obj:isUnique()` |
| canSpeakNormally | Instance | `` | `boolean` | `obj:canSpeakNormally()` |
| isAnimal | Instance | `` | `CharacterAnimal` | `obj:isAnimal()` |
| isHuman | Instance | `` | `CharacterHuman` | `obj:isHuman()` |
| takeMoney | Instance | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| setSquadMemberType | Instance | `memType: integer` | `void` | `obj:setSquadMemberType(memType)` |
| isResident | Instance | `` | `TownBase` | `obj:isResident()` |
| dailyUpdate | Instance | `` | `void` | `obj:dailyUpdate()` |
| updateOnScreenCheck | Instance | `` | `boolean` | `obj:updateOnScreenCheck()` |
| offscreenUpdate | Instance | `` | `void` | `obj:offscreenUpdate()` |
| updateTimes | Instance | `` | `void` | `obj:updateTimes()` |
| getSensoryData | Instance | `` | `SensoryData` | `obj:getSensoryData()` |
| getStateBroadcast | Instance | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getFormation | Instance | `` | `lightuserdata` | `obj:getFormation()` |
| getEnemyFormation | Instance | `` | `lightuserdata` | `obj:getEnemyFormation()` |
| AIDestinationIndoorOutdoorCheck | Instance | `` | `boolean` | `obj:AIDestinationIndoorOutdoorCheck()` |
| update | Instance | `` | `void` | `obj:update()` |
| postUpdate | Instance | `` | `void` | `obj:postUpdate()` |
| ragdollUpdatesUT | Instance | `` | `void` | `obj:ragdollUpdatesUT()` |
| fourFrameUpdate | Instance | `` | `void` | `obj:fourFrameUpdate()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| pausedUpdate | Instance | `` | `void` | `obj:pausedUpdate()` |
| updateUT | Instance | `` | `void` | `obj:updateUT()` |
| threadedUpdate | Instance | `` | `void` | `obj:threadedUpdate()` |
| threadedUpdate4 | Instance | `` | `void` | `obj:threadedUpdate4()` |
| threadedUpdatePeriodic | Instance | `` | `void` | `obj:threadedUpdatePeriodic()` |
| pathExists | Instance | `v: Vector3` | `boolean` | `obj:pathExists(v)` |
| weatherUpdate | Instance | `_a1: number` | `void` | `obj:weatherUpdate(_a1)` |
| stealthUpdate | Instance | `_time: number` | `void` | `obj:stealthUpdate(_time)` |
| lineOfSightCheck | Instance | `` | `number` | `obj:lineOfSightCheck()` |
| getPerceptionMult | Instance | `` | `number` | `obj:getPerceptionMult()` |
| isWithThePlayer | Instance | `` | `boolean` | `obj:isWithThePlayer()` |
| notifyICanSeeYouSneaking | Instance | `maybeProgress01: number` | `void` | `obj:notifyICanSeeYouSneaking(maybeProgress01)` |
| isItSafeToGetUp | Instance | `` | `boolean` | `obj:isItSafeToGetUp()` |
| separateIntoMyOwnSquad | Instance | `permanent: boolean` | `Platoon` | `obj:separateIntoMyOwnSquad(permanent)` |
| dropGearOnDeath | Instance | `vampiricDeath: boolean` | `void` | `obj:dropGearOnDeath(vampiricDeath)` |
| isItOkForMeToLoot | Instance | `` | `boolean` | `obj:isItOkForMeToLoot()` |
| ImStealingDoYouNotice | Instance | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| getFencingSuccessChance | Instance | `` | `number` | `obj:getFencingSuccessChance()` |
| stolenGoodsDetectionCheck | Instance | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| sellingUniformDetectionCheck | Instance | `` | `boolean` | `obj:sellingUniformDetectionCheck()` |
| smugglingTradeCheck | Instance | `` | `YesNoMaybe` | `obj:smugglingTradeCheck()` |
| getStealingSuccessChance | Instance | `` | `number` | `obj:getStealingSuccessChance()` |
| getCurrentWeatherAffectStatus | Instance | `` | `integer` | `obj:getCurrentWeatherAffectStatus()` |
| getCurrentWeatherAffectStrength | Instance | `` | `number` | `obj:getCurrentWeatherAffectStrength()` |
| getWaterLevel | Instance | `` | `integer` | `obj:getWaterLevel()` |
| setTerrainHeightPosition | Instance | `height: number` | `void` | `obj:setTerrainHeightPosition(height)` |
| getTerrainHeightPosition | Instance | `` | `number` | `obj:getTerrainHeightPosition()` |
| setDisguiseMessage | Instance | `msg: integer` | `void` | `obj:setDisguiseMessage(msg)` |
| uniqueStateUpdate | Instance | `` | `void` | `obj:uniqueStateUpdate()` |
| foodUpdate | Instance | `` | `void` | `obj:foodUpdate()` |
| eatItem | Instance | `` | `boolean` | `obj:eatItem()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| loadFromSerialisePostCreationStage | Instance | `` | `void` | `obj:loadFromSerialisePostCreationStage()` |
| setupInventorySections | Instance | `` | `boolean` | `obj:setupInventorySections()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| _getRawPosition | Instance | `` | `Vector3` | `obj:_getRawPosition()` |
| getRawEntityPosition | Instance | `` | `Vector3` | `obj:getRawEntityPosition()` |
| getMovementSpeed | Instance | `` | `number` | `obj:getMovementSpeed()` |
| getMovementSpeedOrders | Instance | `` | `integer` | `obj:getMovementSpeedOrders()` |
| getMovementDirection | Instance | `` | `Vector3` | `obj:getMovementDirection()` |
| isPhysical | Instance | `` | `boolean` | `obj:isPhysical()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| switchLights | Instance | `on: boolean` | `void` | `obj:switchLights(on)` |
| isDisabled | Instance | `` | `boolean` | `obj:isDisabled()` |
| setInsideTownWalls | Instance | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| sheatheWeapon | Instance | `` | `void` | `obj:sheatheWeapon()` |
| select | Instance | `` | `void` | `obj:select()` |
| unselect | Instance | `` | `void` | `obj:unselect()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getCurrentTownLocation | Instance | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| say_WithARepeatLimiter | Instance | `s: string` | `void` | `obj:say_WithARepeatLimiter(s)` |
| say | Instance | `s: string` | `void` | `obj:say(s)` |
| isInventoryVisible | Instance | `` | `boolean` | `obj:isInventoryVisible()` |
| giveItem | Instance | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| hasRoomForItem | Instance | `` | `boolean` | `obj:hasRoomForItem()` |
| hasItem | Instance | `` | `boolean` | `obj:hasItem()` |
| hasAmmoFor | Instance | `` | `boolean` | `obj:hasAmmoFor()` |
| getNumFoodItems | Instance | `` | `integer` | `obj:getNumFoodItems()` |
| hasSimilarItem | Instance | `ty: integer` | `boolean` | `obj:hasSimilarItem(ty)` |
| ifImASmithShouldIDitchMyBackWeapon | Instance | `` | `boolean` | `obj:ifImASmithShouldIDitchMyBackWeapon()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| hasABackpackOn | Instance | `` | `ContainerItem` | `obj:hasABackpackOn()` |
| isATrader | Instance | `` | `boolean` | `obj:isATrader()` |
| isFemale | Instance | `` | `boolean` | `obj:isFemale()` |
| isFleeing | Instance | `` | `boolean` | `obj:isFleeing()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| getStealthKOChance | Instance | `factors: boolean` | `number` | `obj:getStealthKOChance(factors)` |
| getKidnappingChance | Instance | `` | `number` | `obj:getKidnappingChance()` |
| getKidnappingEscapeChance_skill | Instance | `` | `number` | `obj:getKidnappingEscapeChance_skill()` |
| getKidnappingEscapeChance_strength | Instance | `` | `number` | `obj:getKidnappingEscapeChance_strength()` |
| shouldIHelpThisGuy | Instance | `` | `boolean` | `obj:shouldIHelpThisGuy()` |
| shouldIScrewThisGuyOver | Instance | `` | `boolean` | `obj:shouldIScrewThisGuyOver()` |
| ILoveThisGuyBecauseOfStuffThatHappened | Instance | `` | `boolean` | `obj:ILoveThisGuyBecauseOfStuffThatHappened()` |
| IHateThisGuyBecauseOfStuffThatHappened | Instance | `` | `boolean` | `obj:IHateThisGuyBecauseOfStuffThatHappened()` |
| getRoughLevel | Instance | `` | `integer` | `obj:getRoughLevel()` |
| setStandingOrder | Instance | `orderID: integer, on: boolean` | `void` | `obj:setStandingOrder(orderID, on)` |
| getStandingOrder | Instance | `orderID: integer` | `boolean` | `obj:getStandingOrder(orderID)` |
| setStealthMode | Instance | `on: boolean` | `void` | `obj:setStealthMode(on)` |
| isStealthMode | Instance | `` | `boolean` | `obj:isStealthMode()` |
| isStealthModeOrCrawling | Instance | `` | `boolean` | `obj:isStealthModeOrCrawling()` |
| declareDead | Instance | `` | `void` | `obj:declareDead()` |
| updateGUIStatsDetails | Instance | `name: string, statId: integer` | `void` | `obj:updateGUIStatsDetails(name, statId)` |
| _printRaceXPBonusLine | Instance | `s: integer` | `void` | `obj:_printRaceXPBonusLine(s)` |
| addGoal | Instance | `t: integer` | `void` | `obj:addGoal(t)` |
| addJob | Instance | `t: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addJob(t, shift, addDontClear, location)` |
| removeJob | Instance | `t: integer` | `void` | `obj:removeJob(t)` |
| removePermajob | Instance | `t: integer` | `void` | `obj:removePermajob(t)` |
| clearPermajobs | Instance | `` | `void` | `obj:clearPermajobs()` |
| movePermajob | Instance | `taskIdx: integer, targetIdx: integer` | `void` | `obj:movePermajob(taskIdx, targetIdx)` |
| getPermajob | Instance | `slot: integer` | `integer` | `obj:getPermajob(slot)` |
| getPermajobData | Instance | `slot: integer` | `Tasker` | `obj:getPermajobData(slot)` |
| getPermajobCount | Instance | `` | `integer` | `obj:getPermajobCount()` |
| addOrder | Instance | `t: integer, shift: boolean, clear: boolean, location: Vector3` | `void` | `obj:addOrder(t, shift, clear, location)` |
| updateLastTask | Instance | `t: integer, location: Vector3` | `void` | `obj:updateLastTask(t, location)` |
| playerMoveOrderDefault | Instance | `location: Vector3` | `void` | `obj:playerMoveOrderDefault(location)` |
| endCombatMode | Instance | `` | `void` | `obj:endCombatMode()` |
| getTotalRelativeStrengthOfAttackers | Instance | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| canGoIndoors | Instance | `` | `boolean` | `obj:canGoIndoors()` |
| isIndoorsRagdoll | Instance | `` | `boolean` | `obj:isIndoorsRagdoll()` |
| destinationIndoors | Instance | `` | `void` | `obj:destinationIndoors()` |
| destinationInsideWalls | Instance | `` | `integer` | `obj:destinationInsideWalls()` |
| getIntendedAggression | Instance | `` | `number` | `obj:getIntendedAggression()` |
| getPositionBip01 | Instance | `` | `Vector3` | `obj:getPositionBip01()` |
| amInsideTownWalls | Instance | `` | `integer` | `obj:amInsideTownWalls()` |
| setName | Instance | `name: string` | `void` | `obj:setName(name)` |
| setNameTagVisible | Instance | `value: boolean` | `void` | `obj:setNameTagVisible(value)` |
| ragdollMode | Instance | `on: boolean, part: integer` | `void` | `obj:ragdollMode(on, part)` |
| isRagdoll | Instance | `` | `boolean` | `obj:isRagdoll()` |
| isDown | Instance | `` | `boolean` | `obj:isDown()` |
| getRagdollPhysicsRootPos | Instance | `` | `Vector3` | `obj:getRagdollPhysicsRootPos()` |
| amSomeoneWhoNeedsToEatToLive | Instance | `` | `boolean` | `obj:amSomeoneWhoNeedsToEatToLive()` |
| getMagicHungerSetting | Instance | `` | `number` | `obj:getMagicHungerSetting()` |
| wantsToEatNow | Instance | `` | `boolean` | `obj:wantsToEatNow()` |
| isKidnapped | Instance | `` | `boolean` | `obj:isKidnapped()` |
| isLiterallyUnconciousNotPretending | Instance | `` | `boolean` | `obj:isLiterallyUnconciousNotPretending()` |
| isUnconcious | Instance | `` | `boolean` | `obj:isUnconcious()` |
| isCrippled | Instance | `` | `boolean` | `obj:isCrippled()` |
| getProneState | Instance | `` | `integer` | `obj:getProneState()` |
| setProneState | Instance | `p: integer` | `void` | `obj:setProneState(p)` |
| _killRagdoll | Instance | `doItNow: boolean` | `void` | `obj:_killRagdoll(doItNow)` |
| giveBirth | Instance | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:giveBirth(position, rotation)` |
| setupAI | Instance | `` | `void` | `obj:setupAI()` |
| clearAllAIGoals | Instance | `` | `void` | `obj:clearAllAIGoals()` |
| setupPlatoonAI | Instance | `` | `void` | `obj:setupPlatoonAI()` |
| setAppearanceData | Instance | `` | `void` | `obj:setAppearanceData()` |
| getAppearanceData | Instance | `` | `GameDataCopyStandalone` | `obj:getAppearanceData()` |
| setDestination | Instance | `pos: Vector3, shift: boolean` | `void` | `obj:setDestination(pos, shift)` |
| sendDialogEventOverride | Instance | `what: integer, forceRepeat: boolean` | `boolean` | `obj:sendDialogEventOverride(what, forceRepeat)` |
| sendDialogEvent | Instance | `what: integer` | `boolean` | `obj:sendDialogEvent(what)` |
| sayALine | Instance | `line: string, force: boolean` | `void` | `obj:sayALine(line, force)` |
| hasDialogue | Instance | `` | `boolean` | `obj:hasDialogue()` |
| willTalkToEnemies | Instance | `` | `boolean` | `obj:willTalkToEnemies()` |
| relocationTeleport | Instance | `moveBy: Vector3` | `void` | `obj:relocationTeleport(moveBy)` |
| teleportVisuallyOnly | Instance | `to: Vector3, rot: Quaternion` | `void` | `obj:teleportVisuallyOnly(to, rot)` |
| teleportFromAnimation | Instance | `` | `void` | `obj:teleportFromAnimation()` |
| attackTarget | Instance | `` | `void` | `obj:attackTarget()` |
| notifyTheCampaignOfAnAttack | Instance | `` | `void` | `obj:notifyTheCampaignOfAnAttack()` |
| iShouldntAggravateThisTarget | Instance | `` | `boolean` | `obj:iShouldntAggravateThisTarget()` |
| sendMessage | Instance | `message: integer` | `void` | `obj:sendMessage(message)` |
| attackingYou | Instance | `so: boolean, doAwarenessCheck: boolean` | `void` | `obj:attackingYou(so, doAwarenessCheck)` |
| gettingEaten | Instance | `amount: number` | `boolean` | `obj:gettingEaten(amount)` |
| getAttackOriginationDirection | Instance | `` | `integer` | `obj:getAttackOriginationDirection()` |
| stumbleState | Instance | `` | `boolean` | `obj:stumbleState()` |
| setAge | Instance | `f: number` | `void` | `obj:setAge(f)` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| getAge | Instance | `` | `number` | `obj:getAge()` |
| getAge0to1 | Instance | `` | `number` | `obj:getAge0to1()` |
| getAgeString | Instance | `` | `string` | `obj:getAgeString()` |
| getAgeInverse | Instance | `` | `number` | `obj:getAgeInverse()` |
| reThinkCurrentAIAction | Instance | `` | `void` | `obj:reThinkCurrentAIAction()` |
| getBody | Instance | `` | `CharBody` | `obj:getBody()` |
| getCombatClass | Instance | `` | `CombatClass` | `obj:getCombatClass()` |
| getStats | Instance | `` | `CharStats` | `obj:getStats()` |
| getMedical | Instance | `` | `MedicalSystem` | `obj:getMedical()` |
| getOwnerships | Instance | `` | `Ownerships` | `obj:getOwnerships()` |
| getAI | Instance | `` | `lightuserdata` | `obj:getAI()` |
| getAttackTarget | Instance | `` | `void` | `obj:getAttackTarget()` |
| isInCombatMode | Instance | `melee: boolean, ranged: boolean` | `boolean` | `obj:isInCombatMode(melee, ranged)` |
| isInRangedCombatMode | Instance | `` | `boolean` | `obj:isInRangedCombatMode()` |
| isLiterallyUnderMeleeAttackRightNowForSure | Instance | `` | `boolean` | `obj:isLiterallyUnderMeleeAttackRightNowForSure()` |
| _isLiterallyUnderMeleeAttackRightNowForSure_update | Instance | `` | `void` | `obj:_isLiterallyUnderMeleeAttackRightNowForSure_update()` |
| conglomerateTagsFor | Instance | `` | `integer` | `obj:conglomerateTagsFor()` |
| isPrisonerFreeToGo | Instance | `` | `boolean` | `obj:isPrisonerFreeToGo()` |
| clearTempEnemyStatus | Instance | `` | `void` | `obj:clearTempEnemyStatus()` |
| clearAllTempEnemyStatuses | Instance | `tag: integer` | `void` | `obj:clearAllTempEnemyStatuses(tag)` |
| lastSeenInHoursAgo | Instance | `` | `number` | `obj:lastSeenInHoursAgo()` |
| haveMetBefore | Instance | `` | `boolean` | `obj:haveMetBefore()` |
| getIDForMemoryTagging | Instance | `` | `void` | `obj:getIDForMemoryTagging()` |
| getMovement | Instance | `` | `CharMovement` | `obj:getMovement()` |
| lookatPosition | Instance | `v: Vector3, fullbodyFacing: boolean` | `void` | `obj:lookatPosition(v, fullbodyFacing)` |
| areYouGonnaGetMe | Instance | `` | `boolean` | `obj:areYouGonnaGetMe()` |
| getAllAttackersCount | Instance | `` | `integer` | `obj:getAllAttackersCount()` |
| getRace | Instance | `` | `RaceData` | `obj:getRace()` |
| setRace | Instance | `` | `void` | `obj:setRace()` |
| getRadius | Instance | `` | `number` | `obj:getRadius()` |
| isPlayerCharacter | Instance | `` | `boolean` | `obj:isPlayerCharacter()` |
| checkPlayerOrderForProblems | Instance | `t: integer` | `boolean` | `obj:checkPlayerOrderForProblems(t)` |
| getTotalCarryWeight | Instance | `` | `number` | `obj:getTotalCarryWeight()` |
| getCurrentWeapon | Instance | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | Instance | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| getRangedWeapon | Instance | `` | `Crossbow` | `obj:getRangedWeapon()` |
| drawWeapon | Instance | `_a2: string` | `boolean` | `obj:drawWeapon(_a2)` |
| getUpperBodyArmour | Instance | `` | `Item` | `obj:getUpperBodyArmour()` |
| getLowerBodyArmour | Instance | `` | `Item` | `obj:getLowerBodyArmour()` |
| isInjured | Instance | `robot: boolean` | `boolean` | `obj:isInjured(robot)` |
| shouldUseRangedWeapons | Instance | `` | `boolean` | `obj:shouldUseRangedWeapons()` |
| getBoneWorldPosition | Instance | `name: string` | `Vector3` | `obj:getBoneWorldPosition(name)` |
| getAppearance | Instance | `` | `AppearanceBase` | `obj:getAppearance()` |
| _setPlatoon | Instance | `idnum: integer` | `void` | `obj:_setPlatoon(idnum)` |
| getPlatoon | Instance | `` | `ActivePlatoon` | `obj:getPlatoon()` |
| hasPlatoon | Instance | `` | `boolean` | `obj:hasPlatoon()` |
| isInAPersistentPlatoon | Instance | `` | `boolean` | `obj:isInAPersistentPlatoon()` |
| getBlackboard | Instance | `` | `lightuserdata` | `obj:getBlackboard()` |
| getSquadLeader | Instance | `` | `Character` | `obj:getSquadLeader()` |
| getOrdersReciever | Instance | `` | `lightuserdata` | `obj:getOrdersReciever()` |
| preventRagdollMode | Instance | `` | `boolean` | `obj:preventRagdollMode()` |
| setPrisonMode | Instance | `on: boolean` | `void` | `obj:setPrisonMode(on)` |
| setBedMode | Instance | `on: boolean` | `void` | `obj:setBedMode(on)` |
| setSlaveAIJob | Instance | `on: boolean` | `void` | `obj:setSlaveAIJob(on)` |
| isChainedMode | Instance | `` | `boolean` | `obj:isChainedMode()` |
| getChainedModeShackles | Instance | `` | `LockedArmour` | `obj:getChainedModeShackles()` |
| getMySlaveOwner | Instance | `` | `void` | `obj:getMySlaveOwner()` |
| isSlave | Instance | `` | `integer` | `obj:isSlave()` |
| isMySlave | Instance | `` | `boolean` | `obj:isMySlave()` |
| isMyFactionsSlave | Instance | `` | `boolean` | `obj:isMyFactionsSlave()` |
| isHeadShaven | Instance | `` | `boolean` | `obj:isHeadShaven()` |
| runSlaveAnim | Instance | `anim: string, speed: number, sync: number` | `void` | `obj:runSlaveAnim(anim, speed, sync)` |
| endSlaveAnim | Instance | `anim: string` | `void` | `obj:endSlaveAnim(anim)` |
| updatePortraitGUIState | Instance | `` | `void` | `obj:updatePortraitGUIState()` |
| pickupObject | Instance | `` | `void` | `obj:pickupObject()` |
| getPickedUp | Instance | `` | `void` | `obj:getPickedUp()` |
| slaveAttachToBoneMode | Instance | `bone: string` | `void` | `obj:slaveAttachToBoneMode(bone)` |
| isDead | Instance | `` | `boolean` | `obj:isDead()` |
| isBeingCarried | Instance | `` | `boolean` | `obj:isBeingCarried()` |
| getCarryingObject | Instance | `` | `void` | `obj:getCarryingObject()` |
| chooseCarryObjectLeftOrRight | Instance | `` | `void` | `obj:chooseCarryObjectLeftOrRight()` |
| dropCarriedObject | Instance | `ragdollHim: boolean, removeOnly: boolean` | `void` | `obj:dropCarriedObject(ragdollHim, removeOnly)` |
| getDropped | Instance | `ragdollHim: boolean, hull: boolean` | `void` | `obj:getDropped(ragdollHim, hull)` |
| getDiplomacyMultiplier | Instance | `` | `number` | `obj:getDiplomacyMultiplier()` |
| isEnemy | Instance | `factorInDisguises: boolean` | `boolean` | `obj:isEnemy(factorInDisguises)` |
| isAlly | Instance | `factorInDisguises: boolean` | `boolean` | `obj:isAlly(factorInDisguises)` |
| getDefaultTaskRepertoireEnum | Instance | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| getAnimationClass | Instance | `` | `lightuserdata` | `obj:getAnimationClass()` |
| getPredictedPosition | Instance | `secondsInFuture: number` | `Vector3` | `obj:getPredictedPosition(secondsInFuture)` |
| carryModeT | Instance | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:carryModeT(on, makeRagdoll, makeHull)` |
| _carryMode | Instance | `on: boolean, makeRagdoll: boolean, makeHull: boolean` | `void` | `obj:_carryMode(on, makeRagdoll, makeHull)` |
| recalculateTotalEquipmentSkillBonus | Instance | `` | `void` | `obj:recalculateTotalEquipmentSkillBonus()` |
| setupAudio | Instance | `` | `void` | `obj:setupAudio()` |
| audioEvent | Instance | `name: string, range: integer` | `boolean` | `obj:audioEvent(name, range)` |
| setGroundType | Instance | `t: integer` | `void` | `obj:setGroundType(t)` |
| getGroundType | Instance | `` | `integer` | `obj:getGroundType()` |
| calculateMainArmourType | Instance | `` | `void` | `obj:calculateMainArmourType()` |
| getMainArmourType | Instance | `` | `integer` | `obj:getMainArmourType()` |
| wearingUniformOf | Instance | `` | `boolean` | `obj:wearingUniformOf()` |
| getUniformColorScheme | Instance | `` | `GameData` | `obj:getUniformColorScheme()` |
| canTakePlayerOrdersAtThisTime | Instance | `` | `boolean` | `obj:canTakePlayerOrdersAtThisTime()` |
| startEffect | Instance | `` | `boolean` | `obj:startEffect()` |
| stopEffect | Instance | `` | `boolean` | `obj:stopEffect()` |
| stopAllEffects | Instance | `` | `void` | `obj:stopAllEffects()` |
| notifyEffect | Instance | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| equipItem | Instance | `sectionName: string` | `void` | `obj:equipItem(sectionName)` |
| unequipItem | Instance | `sectionName: string` | `void` | `obj:unequipItem(sectionName)` |
| validateInventorySections | Instance | `` | `void` | `obj:validateInventorySections()` |
| processCharacterLoadTimeMessages | Instance | `` | `void` | `obj:processCharacterLoadTimeMessages()` |
| wantsPathfinderActive | Instance | `` | `boolean` | `obj:wantsPathfinderActive()` |
| createAnimationClass | Instance | `` | `void` | `obj:createAnimationClass()` |
| calculateDestinationState | Instance | `v: Vector3` | `void` | `obj:calculateDestinationState(v)` |
| generateWeapon | Instance | `` | `Item` | `obj:generateWeapon()` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| createComponents | Instance | `` | `boolean` | `obj:createComponents()` |
| loadUnloadCheck | Instance | `` | `void` | `obj:loadUnloadCheck()` |
| updateStateBroadcast | Instance | `time: number` | `void` | `obj:updateStateBroadcast(time)` |
| setEffectBT | Instance | `active: boolean` | `void` | `obj:setEffectBT(active)` |
| postRagdollCallback | Instance | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | Instance | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| rememberCharacter [1] | Instance | `who: Character, mem: CharacterPerceptionTags_ShortTerm` | `void` | `obj:rememberCharacter(who, mem)` |
| rememberCharacter [2] | Instance | `who: Character, mem: CharacterPerceptionTags_LongTerm` | `void` | `obj:rememberCharacter(who, mem)` |
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| isIndoors | Instance | `` | `void` | `obj:isIndoors()` |
| isStandingOnBuilding | Instance | `` | `void` | `obj:isStandingOnBuilding()` |
| notifyIndoors | Instance | `` | `void` | `obj:notifyIndoors()` |
| setDestinationIndoors | Instance | `` | `void` | `obj:setDestinationIndoors()` |
| getAudioObject | Instance | `` | `integer` | `obj:getAudioObject()` |
| getName | Instance | `` | `string` | `obj:getName()` |
| changeSlaveOwner | Instance | `` | `void` | `obj:changeSlaveOwner()` |
| teleport [1] | Instance | `moveBy: Vector3, rot: Quaternion` | `void` | `obj:teleport(moveBy, rot)` |
| teleport [2] | Instance | `moveBy: Vector3` | `void` | `obj:teleport(moveBy)` |
| audioValue [1] | Instance | `name: char, value: number` | `void` | `obj:audioValue(name, value)` |
| audioValue [2] | Instance | `name: char, value: char` | `void` | `obj:audioValue(name, value)` |
| getPermajobName | Instance | `slot: integer` | `string` | `obj:getPermajobName(slot)` |
| getAABB | Instance | `` | `lightuserdata` | `obj:getAABB()` |
| getAllAttackers | Instance | `` | `void` | `obj:getAllAttackers()` |
| getCharacterMemoryTag [1] | Instance | `who: Character, mem: CharacterPerceptionTags_LongTerm` | `boolean` | `obj:getCharacterMemoryTag(who, mem)` |
| getCharacterMemoryTag [2] | Instance | `who: Character, mem: CharacterPerceptionTags_ShortTerm` | `boolean` | `obj:getCharacterMemoryTag(who, mem)` |
| hitByMeleeAttack | Instance | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| convertCutDirection [1] | Instance | `dir: CutDirection, from: CutOrigination` | `CutDirection` | `obj:convertCutDirection(dir, from)` |
| convertCutDirection [2] | Instance | `cut: CutDirection, attacker: Character` | `CutDirection` | `obj:convertCutDirection(cut, attacker)` |
| breakFollowOrderLoop | Instance | `` | `boolean` | `obj:breakFollowOrderLoop()` |
| formationUpdateCallback | Instance | `pos: Vector3, heading: Vector3, from: userdata` | `void` | `obj:formationUpdateCallback(pos, heading, from)` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| hasItemsFrom | Instance | `` | `boolean` | `obj:hasItemsFrom()` |
| getLockpickChance | Instance | `victim: userdata` | `number` | `obj:getLockpickChance(victim)` |
| debugIndicateCharacters | Instance | `` | `void` | `obj:debugIndicateCharacters()` |
| iShotYou | Instance | `poon: userdata, onPurpose: boolean` | `boolean` | `obj:iShotYou(poon, onPurpose)` |
| _startStumble | Instance | `dir: integer` | `void` | `obj:_startStumble(dir)` |
| getSquadMissionTarget | Instance | `` | `void` | `obj:getSquadMissionTarget()` |
| setChainedMode | Instance | `on: boolean` | `void` | `obj:setChainedMode(on)` |
| _ragdollMode | Instance | `on: boolean, part: integer` | `boolean` | `obj:_ragdollMode(on, part)` |

## Character::AttachedArrowManager
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.AttachedArrowManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| index | `integer` | RW | `obj.index = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clearAll | Instance | `` | `void` | `obj:clearAll()` |
| updateStart | Instance | `` | `void` | `obj:updateStart()` |
| addArrow | Instance | `pos: Vector3, targ: Vector3, color: integer` | `void` | `obj:addArrow(pos, targ, color)` |
| updateEnd | Instance | `` | `void` | `obj:updateEnd()` |

## Character::CarryMsg
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.Character_CarryMsg`

## Character::RagdollMsg
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Parent Class:** [`Character`](#character)
**Metatable:** `KenshiLua.Character_RagdollMsg`

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isAnimal | Instance | `` | `CharacterAnimal` | `obj:isAnimal()` |
| createAnimationClass | Instance | `` | `void` | `obj:createAnimationClass()` |
| drawWeapon | Instance | `lastSlot: string` | `boolean` | `obj:drawWeapon(lastSlot)` |
| sheatheWeapon | Instance | `` | `void` | `obj:sheatheWeapon()` |
| getCurrentWeapon | Instance | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | Instance | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| giveBirth | Instance | `position: Vector3, rotation: Quaternion` | `boolean` | `obj:giveBirth(position, rotation)` |
| setupInventorySections | Instance | `` | `boolean` | `obj:setupInventorySections()` |
| setupAudio | Instance | `` | `void` | `obj:setupAudio()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| setAge | Instance | `zeroToOne: number` | `void` | `obj:setAge(zeroToOne)` |
| getAge | Instance | `` | `number` | `obj:getAge()` |
| getAgeInverse | Instance | `` | `number` | `obj:getAgeInverse()` |
| getAge0to1 | Instance | `` | `number` | `obj:getAge0to1()` |
| getDefaultTaskRepertoireEnum | Instance | `` | `integer` | `obj:getDefaultTaskRepertoireEnum()` |
| canGoIndoors | Instance | `` | `boolean` | `obj:canGoIndoors()` |
| getSmellHuntingThresholdBlood | Instance | `` | `number` | `obj:getSmellHuntingThresholdBlood()` |
| getSmellHuntingThresholdEggs | Instance | `` | `number` | `obj:getSmellHuntingThresholdEggs()` |
| getHPMultiplier | Instance | `` | `number` | `obj:getHPMultiplier()` |
| foodUpdate | Instance | `` | `void` | `obj:foodUpdate()` |
| pickupItemInMouth | Instance | `` | `boolean` | `obj:pickupItemInMouth()` |
| dropItemInMouth | Instance | `` | `boolean` | `obj:dropItemInMouth()` |
| getItemInMouth | Instance | `` | `Item` | `obj:getItemInMouth()` |
| eatItemInMouth | Instance | `` | `void` | `obj:eatItemInMouth()` |
| init | Instance | `` | `void` | `obj:init()` |
| dropItem | Instance | `` | `void` | `obj:dropItem()` |

## CharacterEditWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterEditWindow.h`
**Metatable:** `KenshiLua.CharacterEditWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| camera | `lightuserdata` | R | `obj.camera` |
| txtName | `lightuserdata` | R | `obj.txtName` |
| txtGender | `lightuserdata` | R | `obj.txtGender` |
| txtRace | `lightuserdata` | R | `obj.txtRace` |
| txtSubRace | `lightuserdata` | R | `obj.txtSubRace` |
| txtCharIdx | `lightuserdata` | R | `obj.txtCharIdx` |
| importButton | `lightuserdata` | R | `obj.importButton` |
| exportButton | `lightuserdata` | R | `obj.exportButton` |
| panelTabs | `lightuserdata` | R | `obj.panelTabs` |
| panelTabsView | `lightuserdata` | R | `obj.panelTabsView` |
| btnPrevGender | `lightuserdata` | R | `obj.btnPrevGender` |
| btnNextGender | `lightuserdata` | R | `obj.btnNextGender` |
| btnPrevRace | `lightuserdata` | R | `obj.btnPrevRace` |
| btnNextRace | `lightuserdata` | R | `obj.btnNextRace` |
| btnPrevSubRace | `lightuserdata` | R | `obj.btnPrevSubRace` |
| btnNextSubRace | `lightuserdata` | R | `obj.btnNextSubRace` |
| btnReset | `lightuserdata` | R | `obj.btnReset` |
| btnRandomiseAll | `lightuserdata` | R | `obj.btnRandomiseAll` |
| btnRandomisePart | `lightuserdata` | R | `obj.btnRandomisePart` |
| descriptionPanel | `lightuserdata` | R | `obj.descriptionPanel` |
| descriptionPanelText | `lightuserdata` | R | `obj.descriptionPanelText` |
| statsPanel | `lightuserdata` | R | `obj.statsPanel` |
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
| idleAnimations | `AnimationDataFastArrayBinding::ArrayType` | RW | `obj.idleAnimations = <value>` |
| characters | `CharacterFastArrayBinding::ArrayType` | RW | `obj.characters = <value>` |
| racesGroups | `RaceGroupDataFastArrayBinding::ArrayType` | RW | `obj.racesGroups = <value>` |
| initialPositions | `Vector3FastArrayBinding::ArrayType` | RW | `obj.initialPositions = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| loadData | Instance | `` | `void` | `obj:loadData()` |
| initCharacters | Instance | `` | `void` | `obj:initCharacters()` |
| updateRace | Instance | `` | `void` | `obj:updateRace()` |
| updateCharacterPoses | Instance | `` | `void` | `obj:updateCharacterPoses()` |
| clearCharacterPoses | Instance | `` | `void` | `obj:clearCharacterPoses()` |
| updateCharacter | Instance | `` | `void` | `obj:updateCharacter()` |
| showCharacter | Instance | `on: boolean` | `void` | `obj:showCharacter(on)` |
| updateCurrentCategory | Instance | `` | `void` | `obj:updateCurrentCategory()` |
| loadImportedCharacter | Instance | `accept: boolean, result: string` | `void` | `obj:loadImportedCharacter(accept, result)` |
| setClothesVisible | Instance | `visible: boolean` | `void` | `obj:setClothesVisible(visible)` |
| confirmMessageCallback | Instance | `_btn: integer` | `void` | `obj:confirmMessageCallback(_btn)` |
| setupUI | Instance | `` | `void` | `obj:setupUI()` |
| setUIEnabled | Instance | `enabled: boolean` | `void` | `obj:setUIEnabled(enabled)` |
| refreshUI | Instance | `` | `void` | `obj:refreshUI()` |
| updateLiveObject | Instance | `` | `void` | `obj:updateLiveObject()` |
| refreshCharacterPoses | Instance | `` | `void` | `obj:refreshCharacterPoses()` |
| exportMeshes | Instance | `` | `void` | `obj:exportMeshes()` |

## CharacterHuman
**Header:** `extern/KenshiLib/Include/kenshi/CharacterHuman.h`
**Metatable:** `KenshiLua.CharacterHuman`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| weaponInHands | `Weapon` | RW | `obj.weaponInHands = <value>` |
| weaponInHandsSheathLocation | `string` | RW | `obj.weaponInHandsSheathLocation = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isHuman | Instance | `` | `CharacterHuman` | `obj:isHuman()` |
| drawWeapon | Instance | `lastSection: string` | `boolean` | `obj:drawWeapon(lastSection)` |
| sheatheWeapon | Instance | `` | `void` | `obj:sheatheWeapon()` |
| getCurrentWeapon | Instance | `` | `Weapon` | `obj:getCurrentWeapon()` |
| getThePreferredWeapon | Instance | `` | `Weapon` | `obj:getThePreferredWeapon()` |
| getRangedWeapon | Instance | `` | `Crossbow` | `obj:getRangedWeapon()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| giveBirth | Instance | `_pos: Vector3, _rot: Quaternion` | `boolean` | `obj:giveBirth(_pos, _rot)` |
| setupInventorySections | Instance | `` | `boolean` | `obj:setupInventorySections()` |
| validateInventorySections | Instance | `` | `void` | `obj:validateInventorySections()` |
| setupAudio | Instance | `` | `void` | `obj:setupAudio()` |
| shaveHead | Instance | `on: boolean` | `void` | `obj:shaveHead(on)` |
| isHeadShaven | Instance | `` | `boolean` | `obj:isHeadShaven()` |
| createAnimationClass | Instance | `` | `void` | `obj:createAnimationClass()` |
| dropItem | Instance | `` | `void` | `obj:dropItem()` |
| dropWeaponInHands | Instance | `` | `void` | `obj:dropWeaponInHands()` |
| dropWeaponInHandsFake | Instance | `` | `void` | `obj:dropWeaponInHandsFake()` |
| unequipItem | Instance | `section: string` | `void` | `obj:unequipItem(section)` |
| weatherUpdate | Instance | `time: number` | `void` | `obj:weatherUpdate(time)` |
| leaveSheathEquipped | Instance | `section: string, ypos: integer` | `void` | `obj:leaveSheathEquipped(section, ypos)` |
| postRagdollCallback | Instance | `on: boolean, part: integer` | `void` | `obj:postRagdollCallback(on, part)` |
| reCalculateNaturalWeapon | Instance | `` | `void` | `obj:reCalculateNaturalWeapon()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |

## CharacterInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.CharacterInventoryLayout`

## CharacterStatsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`
**Metatable:** `KenshiLua.CharacterStatsWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | `Character` | R | `obj.character` |
| statsSum | `integer` | RW | `obj.statsSum = <value>` |
| statProgress | `integer` | RW | `obj.statProgress = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| create | Instance | `` | `void` | `obj:create()` |
| update | Instance | `` | `void` | `obj:update()` |
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| setAutoUpdateMode | Instance | `on: boolean` | `void` | `obj:setAutoUpdateMode(on)` |
| setupStats | Instance | `` | `void` | `obj:setupStats()` |
| updateStats | Instance | `` | `void` | `obj:updateStats()` |
| clearDesctiption | Instance | `` | `void` | `obj:clearDesctiption()` |
| sumStats | Instance | `` | `integer` | `obj:sumStats()` |
| getStatsPanel | Instance | `group: integer` | `DatapanelGUI` | `obj:getStatsPanel(group)` |
| autoChangeSelectedObject | Instance | `` | `void` | `obj:autoChangeSelectedObject()` |
| BuildStats | Static / Instance | `` | `void` | `CharacterStatsWindow.BuildStats()`<br>`obj:BuildStats()` |
| addStat | Static / Instance | `` | `void` | `CharacterStatsWindow.addStat()`<br>`obj:addStat()` |
| getStat | Static / Instance | `` | `boolean\|integer` | `CharacterStatsWindow.getStat()`<br>`obj:getStat()` |
| getStatById | Static / Instance | `` | `boolean\|integer` | `CharacterStatsWindow.getStatById()`<br>`obj:getStatById()` |

## CharacterStatsWindow::Stat
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`
**Parent Class:** [`CharacterStatsWindow`](#characterstatswindow)
**Metatable:** `KenshiLua.Stat`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| type | `integer` | RW | `obj.type = <value>` |
| id | `string` | RW | `obj.id = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| description | `string` | RW | `obj.description = <value>` |
| active | `boolean` | RW | `obj.active = <value>` |

## CharacterStatsWindow::StatGroup
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterStatsWindow.h`
**Parent Class:** [`CharacterStatsWindow`](#characterstatswindow)
**Metatable:** `KenshiLua.StatGroup`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| group | `integer` | RW | `obj.group = <value>` |
| name | `string` | RW | `obj.name = <value>` |

## CharacterTradingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterTradingWindow.h`
**Metatable:** `KenshiLua.CharacterTradingWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| tradingHandler | `lightuserdata` | R | `obj.tradingHandler` |
| charactersBox | `lightuserdata` | R | `obj.charactersBox` |
| confirmBtn | `lightuserdata` | R | `obj.confirmBtn` |
| currentTotalText | `lightuserdata` | R | `obj.currentTotalText` |
| selectedCountText | `lightuserdata` | R | `obj.selectedCountText` |
| tradingBoxes | `CharacterTradingBoxFastArrayBinding::ArrayType` | RW | `obj.tradingBoxes = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| update | Instance | `` | `void` | `obj:update()` |
| close | Instance | `` | `void` | `obj:close()` |

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
| target | `unknown` | RW | `obj.target = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `_time: number` | `void` | `obj:update(_time)` |
| periodicUpdate | Instance | `time: number` | `void` | `obj:periodicUpdate(time)` |
| notifyBodyTaskComplete | Instance | `` | `void` | `obj:notifyBodyTaskComplete()` |
| notifyTaskComplete | Instance | `` | `void` | `obj:notifyTaskComplete()` |
| notifyTaskImpossible | Instance | `` | `void` | `obj:notifyTaskImpossible()` |
| getCombatClass | Instance | `` | `CombatClass` | `obj:getCombatClass()` |
| isCrouched | Instance | `` | `boolean` | `obj:isCrouched()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getName | Instance | `` | `string` | `obj:getName()` |
| isCharacter | Instance | `` | `boolean` | `obj:isCharacter()` |
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| getCharBody | Instance | `` | `CharBody` | `obj:getCharBody()` |
| getUpFromRagdoll | Instance | `animationName: string` | `void` | `obj:getUpFromRagdoll(animationName)` |
| getPlatoon | Instance | `` | `Platoon` | `obj:getPlatoon()` |
| getCurrentAction | Instance | `` | `Tasker` | `obj:getCurrentAction()` |
| getCurrentActionOrMessage | Instance | `` | `Tasker` | `obj:getCurrentActionOrMessage()` |
| endAction | Instance | `` | `void` | `obj:endAction()` |
| isIdle | Instance | `` | `boolean` | `obj:isIdle()` |
| getFaction | Instance | `` | `Faction` | `obj:getFaction()` |
| _endAction | Instance | `` | `void` | `obj:_endAction()` |
| create | Instance | `a: userdata, an: userdata` | `void` | `obj:create(a, an)` |
| setCurrentAction [1] | Instance | `startActionMsg: Tasker` | `boolean` | `obj:setCurrentAction(startActionMsg)` |
| setCurrentAction [2] | Instance | `t: TaskType, target: RootObject` | `boolean` | `obj:setCurrentAction(t, target)` |
| notifyPathImpossible | Instance | `` | `void` | `obj:notifyPathImpossible()` |
| _move | Instance | `location: Vector3` | `void` | `obj:_move(location)` |
| _patrol | Instance | `end: integer, pos: Vector3, area: userdata, taskSys: userdata` | `void` | `obj:_patrol(end, pos, area, taskSys)` |
| getHandle | Instance | `` | `void` | `obj:getHandle()` |
| getCurrentSubject | Instance | `` | `void` | `obj:getCurrentSubject()` |

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
| building | `unknown` | RW | `obj.building = <value>` |
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
| movementMode | `integer` | RW | `obj.movementMode = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| _setPositionAndTeleport | Instance | `p: Vector3, floor: integer` | `void` | `obj:_setPositionAndTeleport(p, floor)` |
| _setPositionDirectionAndTeleport | Instance | `position: Vector3, orientation: Quaternion` | `void` | `obj:_setPositionDirectionAndTeleport(position, orientation)` |
| _setPositionSimple | Instance | `p: Vector3` | `void` | `obj:_setPositionSimple(p)` |
| isRunning | Instance | `` | `boolean` | `obj:isRunning()` |
| isRunningAway | Instance | `from: Vector3` | `boolean` | `obj:isRunningAway(from)` |
| trackAnimationMovement | Instance | `on: boolean` | `void` | `obj:trackAnimationMovement(on)` |
| getHandle | Instance | `` | `void` | `obj:getHandle()` |
| handleChanged | Instance | `` | `void` | `obj:handleChanged()` |
| getRadius | Instance | `` | `number` | `obj:getRadius()` |
| update | Instance | `_TIME: number` | `void` | `obj:update(_TIME)` |
| pausedUpdate | Instance | `` | `void` | `obj:pausedUpdate()` |
| twoFrameUpdate | Instance | `_TIME: number` | `void` | `obj:twoFrameUpdate(_TIME)` |
| postAnimationUpdate | Instance | `` | `void` | `obj:postAnimationUpdate()` |
| periodicUpdate | Instance | `time: number` | `void` | `obj:periodicUpdate(time)` |
| predictNextPosition | Instance | `accurate: boolean` | `Vector3` | `obj:predictNextPosition(accurate)` |
| getMaximumPossibleMovement | Instance | `` | `number` | `obj:getMaximumPossibleMovement()` |
| faceDirection | Instance | `dir: Vector3` | `void` | `obj:faceDirection(dir)` |
| lookatPosition | Instance | `pos: Vector3` | `void` | `obj:lookatPosition(pos)` |
| pathOk | Instance | `` | `boolean` | `obj:pathOk()` |
| pathFailed | Instance | `` | `boolean` | `obj:pathFailed()` |
| isDestinationReached | Instance | `` | `boolean` | `obj:isDestinationReached()` |
| isIdle | Instance | `` | `boolean` | `obj:isIdle()` |
| playerMoveOrderWhileInCombatMode | Instance | `pos: Vector3` | `boolean` | `obj:playerMoveOrderWhileInCombatMode(pos)` |
| halt | Instance | `` | `void` | `obj:halt()` |
| invalidatePath | Instance | `` | `void` | `obj:invalidatePath()` |
| movedBy | Instance | `pos: Vector3` | `void` | `obj:movedBy(pos)` |
| isCombatMovementBlockedByCharacters | Instance | `` | `boolean` | `obj:isCombatMovementBlockedByCharacters()` |
| destroy | Instance | `` | `void` | `obj:destroy()` |
| restore | Instance | `` | `void` | `obj:restore()` |
| refreshClickHull | Instance | `` | `void` | `obj:refreshClickHull()` |
| teleportCollisionHull | Instance | `_pos: Vector3` | `void` | `obj:teleportCollisionHull(_pos)` |
| getCurrentFloor | Instance | `` | `integer` | `obj:getCurrentFloor()` |
| isIndoorsHideMeCheck | Instance | `` | `boolean` | `obj:isIndoorsHideMeCheck()` |
| isIndoors | Instance | `` | `boolean` | `obj:isIndoors()` |
| manualMovement | Instance | `v: Vector3` | `void` | `obj:manualMovement(v)` |
| isInsideBuildingLoadedInterior | Instance | `` | `boolean` | `obj:isInsideBuildingLoadedInterior()` |
| hasClickHull | Instance | `` | `boolean` | `obj:hasClickHull()` |
| isTrackingAnimationMode | Instance | `` | `boolean` | `obj:isTrackingAnimationMode()` |
| isWaypointMoveMode | Instance | `` | `boolean` | `obj:isWaypointMoveMode()` |
| setDirectMovement | Instance | `d: Vector3, limit: number` | `void` | `obj:setDirectMovement(d, limit)` |
| getLastGroundTraceResultMT | Instance | `` | `void` | `obj:getLastGroundTraceResultMT()` |
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| toGround | Instance | `` | `boolean` | `obj:toGround()` |
| updateGroundMaterial | Instance | `` | `void` | `obj:updateGroundMaterial()` |
| getCombatMoveSpeedMult | Instance | `` | `number` | `obj:getCombatMoveSpeedMult()` |
| setDestination | Instance | `dest: Vector3, notVertical: boolean` | `void` | `obj:setDestination(dest, notVertical)` |
| setLookatTarget | Instance | `` | `void` | `obj:setLookatTarget()` |
| setMovementMode | Instance | `mode: integer` | `void` | `obj:setMovementMode(mode)` |
| isStandingOnSomething | Instance | `` | `void` | `obj:isStandingOnSomething()` |
| combatMovementOffensive | Instance | `minDistance: number, maxDistance: number, circle: number, power: boolean, speedLimit: number` | `void` | `obj:combatMovementOffensive(minDistance, maxDistance, circle, power, speedLimit)` |

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
| currentWeaponType | `integer` | RW | `obj.currentWeaponType = <value>` |
| pCurrentWeaponSkill | `lightuserdata` | RW | `obj.pCurrentWeaponSkill = <value>` |
| currentWeaponLength | `number` | RW | `obj.currentWeaponLength = <value>` |
| weapon | `unknown` | RW | `obj.weapon = <value>` |
| weaponWeight | `number` | RW | `obj.weaponWeight = <value>` |
| _weatherProtections | `WeatherProtectionsMapBinding::MapType` | RW | `obj._weatherProtections = <value>` |
| bonusRaces | `BonusRacesMapBinding::MapType` | RW | `obj.bonusRaces = <value>` |
| attacks | `lektor<CombatTechniqueData*>` | RW | `obj.attacks = <value>` |
| blocks | `lektor<CombatTechniqueData*>` | RW | `obj.blocks = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWeatherProtection | Instance | `w: integer` | `number` | `obj:getWeatherProtection(w)` |
| unarmedEncumbrancePenalty | Instance | `` | `integer` | `obj:unarmedEncumbrancePenalty()` |
| skillBonusUnarmed_forGUI | Instance | `factorEnvironment: boolean` | `integer` | `obj:skillBonusUnarmed_forGUI(factorEnvironment)` |
| skillBonusAttack_melee | Instance | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_melee(factorEnvironment)` |
| skillBonusAttack_unarmed | Instance | `factorEnvironment: boolean` | `integer` | `obj:skillBonusAttack_unarmed(factorEnvironment)` |
| skillBonusDefence | Instance | `factorEnvironment: boolean` | `integer` | `obj:skillBonusDefence(factorEnvironment)` |
| serialise | Instance | `` | `void` | `obj:serialise()` |
| updateStats | Instance | `` | `void` | `obj:updateStats()` |
| init | Instance | `` | `void` | `obj:init()` |
| _randomiseStats | Instance | `amount: number` | `void` | `obj:_randomiseStats(amount)` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getGUIDataForMainInfo | Instance | `category: integer, combatMode: boolean` | `void` | `obj:getGUIDataForMainInfo(category, combatMode)` |
| getGUIStatsDisplayMode | Instance | `` | `integer` | `obj:getGUIStatsDisplayMode()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| calculateStumbleThresholdDamageAmount | Instance | `` | `number` | `obj:calculateStumbleThresholdDamageAmount()` |
| setEquipmentStatBonuses | Instance | `athlet: number, combatSpd: number, attack: integer, def: integer, _stealth: number, _unarmed: integer, _dodge: number, fistdamage: number, perception: integer, ranged: number, dexmult: number, assmult: number, damagemult: number` | `void` | `obj:setEquipmentStatBonuses(athlet, combatSpd, attack, def, _stealth, _unarmed, _dodge, fistdamage, perception, ranged, dexmult, assmult, damagemult)` |
| getOverallSkillLevel_0_100 | Instance | `` | `number` | `obj:getOverallSkillLevel_0_100()` |
| getStat | Instance | `what: integer, unmodified: boolean` | `number` | `obj:getStat(what, unmodified)` |
| getStatMultiplier | Instance | `st: integer` | `number` | `obj:getStatMultiplier(st)` |
| getStatMultiplierForGUI | Instance | `st: integer` | `string` | `obj:getStatMultiplierForGUI(st)` |
| getStatPenaltiesTotalForGUI | Instance | `statName: string, stat: integer` | `integer` | `obj:getStatPenaltiesTotalForGUI(statName, stat)` |
| xpStat_timeBased | Instance | `st: integer` | `void` | `obj:xpStat_timeBased(st)` |
| xpStat_eventBased | Instance | `st: integer, amount: number` | `void` | `obj:xpStat_eventBased(st, amount)` |
| xpDodgeEvent | Instance | `enemySkill: number, successful: boolean` | `void` | `obj:xpDodgeEvent(enemySkill, successful)` |
| strengthActual | Instance | `` | `number` | `obj:strengthActual()` |
| strengthBase | Instance | `` | `number` | `obj:strengthBase()` |
| dexterityBase | Instance | `` | `number` | `obj:dexterityBase()` |
| dexterityActual | Instance | `` | `number` | `obj:dexterityActual()` |
| toughness | Instance | `` | `number` | `obj:toughness()` |
| getToughnessMult | Instance | `` | `number` | `obj:getToughnessMult()` |
| getRangedFriendlyFireAvoidanceChance | Instance | `` | `number` | `obj:getRangedFriendlyFireAvoidanceChance()` |
| getRangedAccuracyMult | Instance | `stat: integer` | `number` | `obj:getRangedAccuracyMult(stat)` |
| getReloadSkill | Instance | `stat: integer` | `number` | `obj:getReloadSkill(stat)` |
| animalRecruitReduceStats | Instance | `` | `void` | `obj:animalRecruitReduceStats()` |
| getMeleeDefence | Instance | `includeDefensiveMode: boolean` | `number` | `obj:getMeleeDefence(includeDefensiveMode)` |
| getDodge | Instance | `bonuses: boolean` | `number` | `obj:getDodge(bonuses)` |
| getDodgePenalty_encumbrance | Instance | `` | `number` | `obj:getDodgePenalty_encumbrance()` |
| getDodgePenalty_injuries | Instance | `` | `number` | `obj:getDodgePenalty_injuries()` |
| getDodgePenalty_gear | Instance | `` | `number` | `obj:getDodgePenalty_gear()` |
| getMeleeDefence_melee | Instance | `includeDefensiveMode: boolean` | `number` | `obj:getMeleeDefence_melee(includeDefensiveMode)` |
| getMeleeAttack | Instance | `` | `number` | `obj:getMeleeAttack()` |
| getMeleeAttack_unarmed | Instance | `bonuses: boolean` | `number` | `obj:getMeleeAttack_unarmed(bonuses)` |
| getMeleeAttack_melee | Instance | `` | `number` | `obj:getMeleeAttack_melee()` |
| _getMeleeAttackBase | Instance | `` | `number` | `obj:_getMeleeAttackBase()` |
| getMaxHealAmount | Instance | `isRobot: boolean` | `number` | `obj:getMaxHealAmount(isRobot)` |
| isDefensiveMode | Instance | `` | `boolean` | `obj:isDefensiveMode()` |
| holdPositionMode | Instance | `` | `boolean` | `obj:holdPositionMode()` |
| setHoldLocation | Instance | `v: Vector3` | `void` | `obj:setHoldLocation(v)` |
| clearHoldLocation | Instance | `` | `void` | `obj:clearHoldLocation()` |
| getBashAnimation | Instance | `range: number` | `CombatTechniqueData` | `obj:getBashAnimation(range)` |
| chooseAttack | Instance | `range: number, weaponReach: number, opponentIsStationary: boolean` | `CombatTechniqueData` | `obj:chooseAttack(range, weaponReach, opponentIsStationary)` |
| chooseBlock | Instance | `dir: integer, opponentAttackSkill: number, from: integer` | `CombatTechniqueData` | `obj:chooseBlock(dir, opponentAttackSkill, from)` |
| calculateStumbleBlockTimer | Instance | `stumbleForce: number` | `number` | `obj:calculateStumbleBlockTimer(stumbleForce)` |
| calculateTechniqueInegrityCheckTimer | Instance | `` | `number` | `obj:calculateTechniqueInegrityCheckTimer()` |
| calculateToughnessDamageResistanceMult | Instance | `` | `number` | `obj:calculateToughnessDamageResistanceMult()` |
| calculateToughnessWoundDegenerationRate | Instance | `` | `number` | `obj:calculateToughnessWoundDegenerationRate()` |
| getAttackChance | Instance | `` | `number` | `obj:getAttackChance()` |
| getAttackCuttingDamage | Instance | `` | `number` | `obj:getAttackCuttingDamage()` |
| getAttackBluntPower | Instance | `` | `number` | `obj:getAttackBluntPower()` |
| getAttackBleedDamageMult | Instance | `` | `number` | `obj:getAttackBleedDamageMult()` |
| getAttackPierceDamage | Instance | `` | `number` | `obj:getAttackPierceDamage()` |
| getTotalAttackDamageFor | Instance | `` | `void` | `obj:getTotalAttackDamageFor()` |
| getEquippedWeaponSkill | Instance | `` | `number` | `obj:getEquippedWeaponSkill()` |
| getSkillDifferenceRatio | Instance | `mine: number, his: number` | `number` | `obj:getSkillDifferenceRatio(mine, his)` |
| calculateDeadTime | Instance | `state: integer` | `number` | `obj:calculateDeadTime(state)` |
| xpToughness_RagdollEvent | Instance | `` | `void` | `obj:xpToughness_RagdollEvent()` |
| xpToughness_GetUpEvent | Instance | `` | `void` | `obj:xpToughness_GetUpEvent()` |
| xpToughness_PunchSomething | Instance | `mat: integer` | `void` | `obj:xpToughness_PunchSomething(mat)` |
| xpFirstAid | Instance | `time: number, medicStat: integer` | `void` | `obj:xpFirstAid(time, medicStat)` |
| xpRunning | Instance | `time: number, speed: number` | `void` | `obj:xpRunning(time, speed)` |
| xpStealth | Instance | `time: number, enemiesAbout: boolean, isMoving: boolean` | `void` | `obj:xpStealth(time, enemiesAbout, isMoving)` |
| xpStealthHearCheckEvent | Instance | `enemiesAbout: boolean, trespassing: boolean, seen: boolean` | `void` | `obj:xpStealthHearCheckEvent(enemiesAbout, trespassing, seen)` |
| stealthXPMultForGUI | Instance | `` | `void` | `obj:stealthXPMultForGUI()` |
| xpMassCombat | Instance | `` | `void` | `obj:xpMassCombat()` |
| xpEngineering | Instance | `time: number` | `void` | `obj:xpEngineering(time)` |
| xpLockpicking | Instance | `lockLevel: integer, success: boolean` | `void` | `obj:xpLockpicking(lockLevel, success)` |
| xpGeneral | Instance | `time: number, mult: number, what: integer` | `void` | `obj:xpGeneral(time, mult, what)` |
| calculateAthleticsXPMult | Instance | `speed: number` | `number` | `obj:calculateAthleticsXPMult(speed)` |
| calculateStrengthXPMultFromWalking | Instance | `` | `number` | `obj:calculateStrengthXPMultFromWalking()` |
| setWeapon | Instance | `` | `void` | `obj:setWeapon()` |
| isUnarmed | Instance | `` | `boolean` | `obj:isUnarmed()` |
| getWeaponWeightXPBonus | Instance | `` | `number` | `obj:getWeaponWeightXPBonus()` |
| getAttackSpeed | Instance | `` | `number` | `obj:getAttackSpeed()` |
| getBlockSpeed | Instance | `` | `number` | `obj:getBlockSpeed()` |
| getMaxRunSpeed | Instance | `` | `number` | `obj:getMaxRunSpeed()` |
| getCurrentWeaponLength | Instance | `` | `number` | `obj:getCurrentWeaponLength()` |
| getStealthSkill01 | Instance | `modded: boolean` | `number` | `obj:getStealthSkill01(modded)` |
| getAttackSuccessChanceSkill | Instance | `` | `number` | `obj:getAttackSuccessChanceSkill()` |
| getEncumbranceMult | Instance | `` | `number` | `obj:getEncumbranceMult()` |
| calculateHungerMult | Instance | `` | `number` | `obj:calculateHungerMult()` |
| calculateTheoreticalIdealMaxRunSpeed | Instance | `` | `number` | `obj:calculateTheoreticalIdealMaxRunSpeed()` |
| calculateWeaponWeightXPMult | Instance | `weaponWeight: number` | `number` | `obj:calculateWeaponWeightXPMult(weaponWeight)` |
| hasWeapon | Instance | `` | `boolean` | `obj:hasWeapon()` |
| calculateMaxStealthSpeed | Instance | `` | `number` | `obj:calculateMaxStealthSpeed()` |
| _calculateMaxSwimSpeed | Instance | `` | `number` | `obj:_calculateMaxSwimSpeed()` |
| calculateSwimSpeed | Instance | `` | `number` | `obj:calculateSwimSpeed()` |
| calculateDodgeChance | Instance | `versus: number, stumbling: boolean` | `number` | `obj:calculateDodgeChance(versus, stumbling)` |
| calculateMaxRunSpeed | Instance | `` | `void` | `obj:calculateMaxRunSpeed()` |
| _calculateEncumberanceMult | Instance | `` | `number` | `obj:_calculateEncumberanceMult()` |
| _calculateWeaponWeightSpeedMultiplier | Instance | `weaponWeight: number` | `void` | `obj:_calculateWeaponWeightSpeedMultiplier(weaponWeight)` |
| currentWeaponHand | Instance | `` | `integer` | `obj:currentWeaponHand()` |
| calculateAttackOrBlockSpeed | Instance | `weaponWeightSpeedMult: number, attackOrBlockSkill: number, isBlock: boolean` | `number` | `obj:calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock)` |
| _calculateBlockChance | Instance | `versus: number` | `number` | `obj:_calculateBlockChance(versus)` |
| _recalculateStats | Instance | `` | `void` | `obj:_recalculateStats()` |
| setEquippedWeaponSkill | Instance | `v: number` | `void` | `obj:setEquippedWeaponSkill(v)` |
| getStrength | Instance | `` | `number` | `obj:getStrength()` |
| getStrengthRaw | Instance | `` | `number` | `obj:getStrengthRaw()` |
| getDexterity | Instance | `` | `number` | `obj:getDexterity()` |
| getDexterityRaw | Instance | `` | `number` | `obj:getDexterityRaw()` |
| getToughness | Instance | `` | `number` | `obj:getToughness()` |
| getPerception | Instance | `` | `number` | `obj:getPerception()` |
| getAthletics | Instance | `` | `number` | `obj:getAthletics()` |
| getThieving | Instance | `` | `number` | `obj:getThieving()` |
| printStealthStats | Instance | `` | `void` | `obj:printStealthStats()` |
| printRunSpeedStatMax | Instance | `` | `void` | `obj:printRunSpeedStatMax()` |
| formatWholeStatStringWithBonuses [1] | Instance | `base: integer, current: integer` | `string` | `obj:formatWholeStatStringWithBonuses(base, current)` |
| formatWholeStatStringWithBonuses [2] | Instance | `stat: StatsEnumerated` | `string` | `obj:formatWholeStatStringWithBonuses(stat)` |
| getStatRef | Instance | `what: integer` | `number` | `obj:getStatRef(what)` |
| getStatName | Static / Instance | `` | `void` | `CharStats.getStatName()`<br>`obj:getStatName()` |
| getMeleeAttackRef | Instance | `` | `number` | `obj:getMeleeAttackRef()` |
| getPainAnim | Instance | `` | `void` | `obj:getPainAnim()` |
| xpMelee | Instance | `what: integer` | `void` | `obj:xpMelee(what)` |
| convertWeaponWeightToBluntMultiplier | Static / Instance | `` | `number` | `CharStats.convertWeaponWeightToBluntMultiplier()`<br>`obj:convertWeaponWeightToBluntMultiplier()` |
| convertBluntMultiplierToWeaponWeight | Static / Instance | `` | `number` | `CharStats.convertBluntMultiplierToWeaponWeight()`<br>`obj:convertBluntMultiplierToWeaponWeight()` |
| setupCombatTechniques | Static / Instance | `` | `void` | `CharStats.setupCombatTechniques()`<br>`obj:setupCombatTechniques()` |
| getStealthTooltip | Instance | `` | `void` | `obj:getStealthTooltip()` |
| getAthleticsTooltip | Instance | `` | `void` | `obj:getAthleticsTooltip()` |
| getStatPenaltiesForGUI | Instance | `statName: string, stat: integer` | `boolean` | `obj:getStatPenaltiesForGUI(statName, stat)` |
| chooseAttacks | Instance | `range: number, weaponReach: number, opponentIsStationary: boolean, skipMedicals: boolean, _weaponType: integer, _weaponSkill: number` | `void` | `obj:chooseAttacks(range, weaponReach, opponentIsStationary, skipMedicals, _weaponType, _weaponSkill)` |
| printExertionHungerMultTooltip | Instance | `` | `void` | `obj:printExertionHungerMultTooltip()` |
| xpTraining | Instance | `time: number, mult: number, statVal: number, upperLimit: number, whatStatIsIt: integer` | `number` | `obj:xpTraining(time, mult, statVal, upperLimit, whatStatIsIt)` |

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
| blockingTargetH | `unknown` | RW | `obj.blockingTargetH = <value>` |
| targetsInAttackZone | `lektor<hand>` | RW | `obj.targetsInAttackZone = <value>` |
| attackersH | `lektor<hand>` | RW | `obj.attackersH = <value>` |
| threats | `lektor<Character*>` | RW | `obj.threats = <value>` |
| threatsH | `lektor<hand>` | RW | `obj.threatsH = <value>` |
| notifiedThreats | `lektor<hand>` | RW | `obj.notifiedThreats = <value>` |
| lastIncomingAttackComboSection | `integer` | RW | `obj.lastIncomingAttackComboSection = <value>` |
| calculatedTargetsInAttackZoneThisFrame | `boolean` | RW | `obj.calculatedTargetsInAttackZoneThisFrame = <value>` |
| combatState | `integer` | RW | `obj.combatState = <value>` |
| nextMove | `integer` | RW | `obj.nextMove = <value>` |
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
| currentTargetHandle | `unknown` | RW | `obj.currentTargetHandle = <value>` |
| stateMap | `SwordStateMapBinding::MapType` | RW | `obj.stateMap = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isAI | Instance | `` | `boolean` | `obj:isAI()` |
| initCombatMode | Instance | `end: integer, focusedTarget: boolean` | `boolean` | `obj:initCombatMode(end, focusedTarget)` |
| go | Instance | `_frameTime: number` | `void` | `obj:go(_frameTime)` |
| getCombatState | Instance | `` | `integer` | `obj:getCombatState()` |
| getBlockStateEnum | Instance | `` | `integer` | `obj:getBlockStateEnum()` |
| periodicUpdate | Instance | `time: number` | `void` | `obj:periodicUpdate(time)` |
| whoAttacksYouOrMe | Instance | `dist: number` | `integer\|number` | `obj:whoAttacksYouOrMe(dist)` |
| _iHitYouAreYouHit | Instance | `dir: integer` | `integer` | `obj:_iHitYouAreYouHit(dir)` |
| _getHit | Instance | `dir: integer, stumble: boolean` | `void` | `obj:_getHit(dir, stumble)` |
| _blockHit | Instance | `dir: integer` | `void` | `obj:_blockHit(dir)` |
| isAttacking | Instance | `` | `number` | `obj:isAttacking()` |
| informOfFreeAttackSlot | Instance | `` | `void` | `obj:informOfFreeAttackSlot()` |
| isStationary | Instance | `` | `boolean` | `obj:isStationary()` |
| _getAttackTarget | Instance | `` | `void` | `obj:_getAttackTarget()` |
| isFightingAnAllyOfMine | Instance | `` | `boolean` | `obj:isFightingAnAllyOfMine()` |
| getCurrentTechnique | Instance | `` | `CombatTechniqueData` | `obj:getCurrentTechnique()` |
| getCurrentTechniqueSection | Instance | `` | `integer` | `obj:getCurrentTechniqueSection()` |
| getMeiMin | Instance | `` | `number` | `obj:getMeiMin()` |
| areYouFightingAndInNeedOfHelp | Instance | `` | `number` | `obj:areYouFightingAndInNeedOfHelp()` |
| getAttackers | Instance | `` | `lektor<hand>` | `obj:getAttackers()` |
| getNumOpponents | Instance | `` | `integer` | `obj:getNumOpponents()` |
| getTotalRelativeStrengthOfAttackers | Instance | `` | `number` | `obj:getTotalRelativeStrengthOfAttackers()` |
| _isInCombatMode | Instance | `` | `boolean` | `obj:_isInCombatMode()` |
| checkForBadHandles | Instance | `` | `void` | `obj:checkForBadHandles()` |
| addAttackerH | Instance | `` | `boolean` | `obj:addAttackerH()` |
| isInAttackerListH | Instance | `` | `boolean` | `obj:isInAttackerListH()` |
| removeAttackerH | Instance | `` | `boolean` | `obj:removeAttackerH()` |
| youDoKnowImAttackingYouRight | Instance | `` | `void` | `obj:youDoKnowImAttackingYouRight()` |
| getAttackAimAdjustmentThreshold | Instance | `` | `number` | `obj:getAttackAimAdjustmentThreshold()` |
| getNumWaitingAttackers | Instance | `` | `integer` | `obj:getNumWaitingAttackers()` |
| readyToFinishCombatMode | Instance | `` | `boolean` | `obj:readyToFinishCombatMode()` |
| getTimeSinceLastCombatModeInHours | Instance | `` | `number` | `obj:getTimeSinceLastCombatModeInHours()` |
| hasFocusedTarget | Instance | `` | `void` | `obj:hasFocusedTarget()` |
| changeState | Instance | `newState: integer, minTime: number` | `void` | `obj:changeState(newState, minTime)` |
| getStateClass | Instance | `state: integer` | `lightuserdata` | `obj:getStateClass(state)` |
| update [1] | Instance | `` | `void` | `obj:update()` |
| update [2] | Instance | `frameTIME: number` | `void` | `obj:update(frameTIME)` |
| getMeiMax | Instance | `` | `number` | `obj:getMeiMax()` |
| startupState | Instance | `` | `boolean` | `obj:startupState()` |
| stumbleState | Instance | `` | `void` | `obj:stumbleState()` |
| _isAttackingUpdate | Instance | `` | `number` | `obj:_isAttackingUpdate()` |
| canBlock | Instance | `` | `boolean` | `obj:canBlock()` |
| attackState | Instance | `` | `boolean` | `obj:attackState()` |
| checkForNeedBlock | Instance | `thresholdMyAttack: number, thresholdIncomingAttack: number` | `boolean` | `obj:checkForNeedBlock(thresholdMyAttack, thresholdIncomingAttack)` |
| setCombatState | Instance | `state: integer` | `void` | `obj:setCombatState(state)` |
| initialiseBlock | Instance | `isStumbling: boolean` | `boolean` | `obj:initialiseBlock(isStumbling)` |
| blockState | Instance | `stumbleBlocking: boolean` | `boolean` | `obj:blockState(stumbleBlocking)` |
| blockWaitingState | Instance | `` | `void` | `obj:blockWaitingState()` |
| attackImpactCheck | Instance | `` | `void` | `obj:attackImpactCheck()` |
| calculateTargetsInAttackZone | Instance | `` | `void` | `obj:calculateTargetsInAttackZone()` |
| isInAttackZone | Instance | `` | `boolean` | `obj:isInAttackZone()` |
| getNearestEnemyInAttackZone | Instance | `` | `Character` | `obj:getNearestEnemyInAttackZone()` |
| assessIncomingAttacks | Instance | `` | `void` | `obj:assessIncomingAttacks()` |
| notifyBlockNeeded | Instance | `` | `void` | `obj:notifyBlockNeeded()` |
| calculateCurrentTechniqueSection | Instance | `` | `integer\|number` | `obj:calculateCurrentTechniqueSection()` |
| weaponReach | Instance | `` | `number` | `obj:weaponReach()` |
| getBiggestThreat | Instance | `minThreshold: number` | `Character` | `obj:getBiggestThreat(minThreshold)` |
| gotMoreImportantThingsToDoThanFightingYou | Instance | `` | `boolean` | `obj:gotMoreImportantThingsToDoThanFightingYou()` |
| setAttackTarget | Instance | `` | `void` | `obj:setAttackTarget()` |
| setAttackTargetHandle | Instance | `` | `void` | `obj:setAttackTargetHandle()` |
| lookatTarget | Instance | `` | `void` | `obj:lookatTarget()` |
| packPtrsToHandles | Instance | `` | `void` | `obj:packPtrsToHandles()` |
| unpackHandlesToPtrs | Instance | `` | `void` | `obj:unpackHandlesToPtrs()` |
| setup | Static / Instance | `` | `void` | `CombatClass.setup()`<br>`obj:setup()` |
| destroy | Static / Instance | `` | `void` | `CombatClass.destroy()`<br>`obj:destroy()` |
| getCombatEffect | Static / Instance | `` | `GameData` | `CombatClass.getCombatEffect()`<br>`obj:getCombatEffect()` |
| addEffect | Static / Instance | `` | `void` | `CombatClass.addEffect()`<br>`obj:addEffect()` |
| shiftEffects | Static / Instance | `` | `void` | `CombatClass.shiftEffects()`<br>`obj:shiftEffects()` |
| updateEffects | Static / Instance | `` | `void` | `CombatClass.updateEffects()`<br>`obj:updateEffects()` |

## CombatClass::AttackSlotManager
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Parent Class:** [`CombatClass`](#combatclass)
**Metatable:** `KenshiLua.AttackSlotManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | `Character` | RW | `obj.me = <value>` |
| combatClass | `CombatClass` | RW | `obj.combatClass = <value>` |
| attackSlotH | `number` | RW | `obj.attackSlotH = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasFreeAttackSlot | Instance | `` | `boolean` | `obj:hasFreeAttackSlot()` |
| freeAllSlotsH | Instance | `` | `void` | `obj:freeAllSlotsH()` |
| periodicUpdate | Instance | `time: number` | `void` | `obj:periodicUpdate(time)` |
| update | Instance | `` | `void` | `obj:update()` |
| getNumAttackSlots | Instance | `` | `integer` | `obj:getNumAttackSlots()` |
| getMaxPossibleAttackSlots | Instance | `` | `integer` | `obj:getMaxPossibleAttackSlots()` |

## CombatClass::AttackSlotManager::SlotData
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Parent Class:** [`CombatClass`](#combatclass)
**Metatable:** `KenshiLua.CombatClass_AttackSlotManager_SlotData`

## CombatClass::EffectData
**Header:** `extern/KenshiLib/Include/kenshi/CombatClass.h`
**Parent Class:** [`CombatClass`](#combatclass)
**Metatable:** `KenshiLua.CombatClass_EffectData`

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
| lookAtCharacter | `unknown` | RW | `obj.lookAtCharacter = <value>` |
| combatTarget | `unknown` | RW | `obj.combatTarget = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| collisionUpdate | Instance | `time: number` | `void` | `obj:collisionUpdate(time)` |
| chasingModeCheck | Instance | `` | `boolean` | `obj:chasingModeCheck()` |
| create | Instance | `strafe: boolean` | `void` | `obj:create(strafe)` |
| areTherePeopleInMyWay | Instance | `` | `boolean` | `obj:areTherePeopleInMyWay()` |
| addACharacterObstruction | Instance | `` | `void` | `obj:addACharacterObstruction()` |
| setupCombatMovementVariables | Instance | `` | `void` | `obj:setupCombatMovementVariables()` |
| combatMovementUpdate | Instance | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: integer, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| combatMovementUpdate_crippleMode | Instance | `frametime: number, currentPos: Vector3, currentDirIn: Vector3, isCurrentlyMoving: boolean, repulsionVector: Vector3, facingDirOut: Vector3, defensive: boolean, combatState: integer, raceSpeedMult: number` | `void` | `obj:combatMovementUpdate_crippleMode(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult)` |
| getUrgentVelocities | Instance | `pos: Vector3, facingDir: Vector3` | `Vector3` | `obj:getUrgentVelocities(pos, facingDir)` |
| checkWeDontCollideWithCharacters | Instance | `pos: Vector3, newpos: Vector3` | `void` | `obj:checkWeDontCollideWithCharacters(pos, newpos)` |
| checkCharacterCollision | Instance | `pos: Vector3, movement: Vector3` | `boolean` | `obj:checkCharacterCollision(pos, movement)` |
| setForcedWP | Instance | `v: Vector3` | `void` | `obj:setForcedWP(v)` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| disable | Instance | `` | `void` | `obj:disable()` |

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
| events | `unknown` | RW | `obj.events = <value>` |
| skillTypes | `unknown` | R | `obj.skillTypes` |
| impactPoints | `lektor<CombatTechniqueData::ImpactPoint>` | R | `obj.impactPoints` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasSkillType | Instance | `type: integer` | `boolean` | `obj:hasSkillType(type)` |
| numImpactPoints | Instance | `` | `integer` | `obj:numImpactPoints()` |
| impactPoint | Instance | `i: integer` | `CombatTechniqueData::ImpactPoint` | `obj:impactPoint(i)` |

## CombatTechniqueData::ImpactPoint
**Header:** `extern/KenshiLib/Include/kenshi/Terrain.h`
**Parent Class:** [`CombatTechniqueData`](#combattechniquedata)
**Metatable:** `KenshiLua.ImpactPoint`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| direction | `integer` | RW | `obj.direction = <value>` |
| power | `number` | RW | `obj.power = <value>` |
| impactAnimationFrame | `number` | RW | `obj.impactAnimationFrame = <value>` |
| motionStopsAnimationFrame | `number` | RW | `obj.motionStopsAnimationFrame = <value>` |
| limb | `integer` | RW | `obj.limb = <value>` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getClassType | Instance | `` | `integer` | `obj:getClassType()` |
| canEquip | Instance | `` | `boolean` | `obj:canEquip()` |
| equipItem | Instance | `what: string` | `void` | `obj:equipItem(what)` |
| unequipItem | Instance | `what: string` | `void` | `obj:unequipItem(what)` |
| dropItem | Instance | `` | `void` | `obj:dropItem()` |
| takeMoney | Instance | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| doubleCheckHandle | Instance | `` | `void` | `obj:doubleCheckHandle()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| _serialise | Instance | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _loadFromSerialise | Instance | `` | `void` | `obj:_loadFromSerialise()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| setProperOwner | Instance | `` | `void` | `obj:setProperOwner()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| showContextMenu | Instance | `on: boolean` | `void` | `obj:showContextMenu(on)` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| update | Instance | `` | `void` | `obj:update()` |
| _destroyMenuGUICheck | Instance | `` | `void` | `obj:_destroyMenuGUICheck()` |

## ContextMenuGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/ContextMenu.h`
**Metatable:** `KenshiLua.ContextMenuGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| contextMenuTarget | `unknown` | RW | `obj.contextMenuTarget = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| nameText | `lightuserdata` | R | `obj.nameText` |
| optionsList | `lightuserdata` | R | `obj.optionsList` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getMainWidget | Instance | `` | `lightuserdata` | `obj:getMainWidget()` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |

## CPerfTimer
**Header:** `extern/KenshiLib/Include/kenshi/util/PerfTimer.h`
**Metatable:** `KenshiLua.CPerfTimer`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| Stop | Instance | `` | `void` | `obj:Stop()` |
| Resolution | Instance | `` | `number` | `obj:Resolution()` |
| Resolutionms | Instance | `` | `number` | `obj:Resolutionms()` |
| Resolutionus | Instance | `` | `number` | `obj:Resolutionus()` |
| Elapsed | Instance | `` | `number` | `obj:Elapsed()` |
| Elapsedms | Instance | `` | `number` | `obj:Elapsedms()` |
| Elapsedus | Instance | `` | `number` | `obj:Elapsedus()` |

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
| crafting | `CraftingItemDequeBinding::DequeType` | RW | `obj.crafting = <value>` |
| specialCraftItemType | `integer` | RW | `obj.specialCraftItemType = <value>` |
| repeat | `boolean` | RW | `obj.repeat = <value>` |
| whosCrafting | `unknown` | RW | `obj.whosCrafting = <value>` |
| itemCrafted | `boolean` | RW | `obj.itemCrafted = <value>` |
| failiureNotified | `boolean` | RW | `obj.failiureNotified = <value>` |
| biggestCraftableItem | `GameData` | RW | `obj.biggestCraftableItem = <value>` |
| outItem | `Item` | RW | `obj.outItem = <value>` |
| inItems | `lektor<Item*>` | RW | `obj.inItems = <value>` |
| partialItems | `unknown` | RW | `obj.partialItems = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| update | Instance | `` | `void` | `obj:update()` |
| operate | Instance | `amount: number` | `void` | `obj:operate(amount)` |
| givePower | Instance | `amount: number` | `void` | `obj:givePower(amount)` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| hasCraftingQueued | Instance | `` | `boolean` | `obj:hasCraftingQueued()` |
| isProductionFull | Instance | `` | `boolean` | `obj:isProductionFull()` |
| getProductionItemData | Instance | `` | `GameData` | `obj:getProductionItemData()` |
| getCurrentProductionQuantity | Instance | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| isAnyInputsInvalidType | Instance | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| newCraftingButton | Instance | `sender: userdata` | `void` | `obj:newCraftingButton(sender)` |
| addFinishedCraftItem | Instance | `` | `void` | `obj:addFinishedCraftItem()` |
| notifyCraftFailiure | Instance | `` | `void` | `obj:notifyCraftFailiure()` |
| tryOperate | Instance | `` | `boolean` | `obj:tryOperate()` |
| playerManufacturerData | Static / Instance | `` | `GameData` | `CraftingBuilding.playerManufacturerData()`<br>`obj:playerManufacturerData()` |
| getAvailableCrafts | Instance | `` | `void` | `obj:getAvailableCrafts()` |
| _addCraft | Instance | `progress: number, crit: integer` | `lightuserdata` | `obj:_addCraft(progress, crit)` |
| _removeCraft | Instance | `index: integer` | `void` | `obj:_removeCraft(index)` |
| getCraft | Instance | `id: integer` | `lightuserdata` | `obj:getCraft(id)` |
| destroyProductionItem | Instance | `` | `void` | `obj:destroyProductionItem()` |
| predictCraftersBestWeapon | Instance | `levelcap: integer` | `GameData` | `obj:predictCraftersBestWeapon(levelcap)` |
| calculateCriticalChance | Instance | `` | `number` | `obj:calculateCriticalChance()` |
| getCriticalSuccessWeapon | Instance | `normalWeaponLevel: integer` | `GameData` | `obj:getCriticalSuccessWeapon(normalWeaponLevel)` |
| getItemsWeWantRidOf | Instance | `looting: boolean` | `void` | `obj:getItemsWeWantRidOf(looting)` |
| canHaveSomeOfThese | Instance | `` | `boolean` | `obj:canHaveSomeOfThese()` |
| setupFromData | Instance | `` | `void` | `obj:setupFromData()` |
| updateOutput | Instance | `rate: number` | `void` | `obj:updateOutput(rate)` |
| getPlayerCraftedWeaponLevel | Instance | `` | `number` | `obj:getPlayerCraftedWeaponLevel()` |
| getGUIState | Instance | `category: integer` | `void` | `obj:getGUIState(category)` |
| updateInventoryWindow | Instance | `` | `void` | `obj:updateInventoryWindow()` |
| setProductionItem | Instance | `stack: integer, progress01: number` | `void` | `obj:setProductionItem(stack, progress01)` |

## CraftingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/CraftingBuilding.h`
**Metatable:** `KenshiLua.CraftingInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| queueBtn | `MyGUI::Widget` | RW | `obj.queueBtn = <value>` |
| craftingName | `MyGUI::Widget` | RW | `obj.craftingName = <value>` |
| outputType | `integer` | RW | `obj.outputType = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setupSections | Instance | `inventoryGUI: userdata, sections: userdata, inventory: userdata` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| setOutputType | Instance | `type: integer` | `void` | `obj:setOutputType(type)` |
| setCraftingName | Instance | `name: string` | `void` | `obj:setCraftingName(name)` |
| getQueueButton | Instance | `` | `MyGUI::Widget` | `obj:getQueueButton()` |

## Crossbow
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Crossbow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| gunClass | `lightuserdata` | R | `obj.gunClass` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isCrossbow | Instance | `` | `Crossbow` | `obj:isCrossbow()` |
| getClassType | Instance | `` | `integer` | `obj:getClassType()` |
| getCraftMaterialMult | Instance | `` | `number` | `obj:getCraftMaterialMult()` |
| getCraftTime | Instance | `` | `number` | `obj:getCraftTime()` |
| getRangeInUnits | Instance | `` | `number` | `obj:getRangeInUnits()` |
| getEquipPositionOffset | Instance | `` | `number` | `obj:getEquipPositionOffset()` |
| destroyItemEntityCallback_Equipping | Instance | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| multiply | Instance | `mult: number` | `void` | `obj:multiply(mult)` |
| total | Instance | `` | `number` | `obj:total()` |

## DataObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/GameData.h`
**Metatable:** `KenshiLua.DataObjectContainer`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| isStored | `boolean` | RW | `obj.isStored = <value>` |
| objectDatas | `GameDataContainer` | RW | `obj.objectDatas = <value>` |
| datasFile | `string` | RW | `obj.datasFile = <value>` |
| selfType | `integer` | RW | `obj.selfType = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getType | Instance | `` | `integer` | `obj:getType()` |
| setupDataFile | Instance | `filename: string` | `void` | `obj:setupDataFile(filename)` |
| destroyObjectDatas | Instance | `` | `void` | `obj:destroyObjectDatas()` |

## DatapanelGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/DatapanelGUI.h`
**Metatable:** `KenshiLua.DatapanelGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| frequentUpdatesWanted | `boolean` | RW | `obj.frequentUpdatesWanted = <value>` |
| scrollWin | `lightuserdata` | R | `obj.scrollWin` |
| premadeParentWindow | `boolean` | RW | `obj.premadeParentWindow = <value>` |
| scrolling | `boolean` | RW | `obj.scrolling = <value>` |
| isWindow | `boolean` | RW | `obj.isWindow = <value>` |
| currentCategory | `integer` | RW | `obj.currentCategory = <value>` |
| mouseOverEvent | `lightuserdata` | R | `obj.mouseOverEvent` |
| mouseOverEventDatas | `lightuserdata` | R | `obj.mouseOverEventDatas` |
| automaticRefresh | `boolean` | RW | `obj.automaticRefresh = <value>` |
| automaticTarget | `boolean` | RW | `obj.automaticTarget = <value>` |
| tabWin | `lightuserdata` | R | `obj.tabWin` |
| panelName | `string` | RW | `obj.panelName = <value>` |
| x | `number` | RW | `obj.x = <value>` |
| y | `number` | RW | `obj.y = <value>` |
| w | `number` | RW | `obj.w = <value>` |
| h | `number` | RW | `obj.h = <value>` |
| DATALINESPACING | `number` | RW | `obj.DATALINESPACING = <value>` |
| DATALINETHICKNESS | `number` | RW | `obj.DATALINETHICKNESS = <value>` |
| basicSpacing | `boolean` | RW | `obj.basicSpacing = <value>` |
| layer | `string` | RW | `obj.layer = <value>` |
| scrollView | `lightuserdata` | R | `obj.scrollView` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setFrequentUpdateMode | Instance | `` | `void` | `obj:setFrequentUpdateMode()` |
| setPositionReal | Instance | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| setPosition | Instance | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| resize | Instance | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |
| clear | Instance | `` | `void` | `obj:clear()` |
| clearPage | Instance | `cat: integer` | `void` | `obj:clearPage(cat)` |
| hideAllWidgets | Instance | `` | `void` | `obj:hideAllWidgets()` |
| create | Instance | `` | `void` | `obj:create()` |
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| show_NonSmooth | Instance | `on: boolean` | `void` | `obj:show_NonSmooth(on)` |
| update | Instance | `` | `void` | `obj:update()` |
| setPanelName | Instance | `name: string` | `void` | `obj:setPanelName(name)` |
| showTabs | Instance | `on: boolean` | `void` | `obj:showTabs(on)` |
| addTab | Instance | `id: integer, name: string, icon: string` | `void` | `obj:addTab(id, name, icon)` |
| setTabName | Instance | `id: integer, name: string` | `void` | `obj:setTabName(id, name)` |
| setCaption | Instance | `s: string` | `void` | `obj:setCaption(s)` |
| setAutomaticRefresh | Instance | `on: boolean` | `void` | `obj:setAutomaticRefresh(on)` |
| setAutomaticTargeting | Instance | `on: boolean` | `void` | `obj:setAutomaticTargeting(on)` |
| _zeroLines | Instance | `cat: integer` | `DataPanelLine` | `obj:_zeroLines(cat)` |
| setLineStatInfo | Instance | `s1: string, s2: string, category: integer` | `DataPanelLine` | `obj:setLineStatInfo(s1, s2, category)` |
| setLineFaction | Instance | `s1: string, s2: string, category: integer, v1: number, v2: number` | `DataPanelLine_Faction` | `obj:setLineFaction(s1, s2, category, v1, v2)` |
| setLineTextButton | Instance | `text: string, caption: string, category: integer, buttonWidth: number, skin: string` | `DataPanelLine_Button` | `obj:setLineTextButton(text, caption, category, buttonWidth, skin)` |
| setLineButton | Instance | `key: string, caption: string, category: integer` | `DataPanelLine_Button` | `obj:setLineButton(key, caption, category)` |
| setLineToggleButton | Instance | `key: string, caption: string, category: integer` | `DataPanelLine_Button` | `obj:setLineToggleButton(key, caption, category)` |
| setLineSliderEditable | Instance | `key: string, category: integer, showName: boolean, min: number, max: number, tempVal: number` | `DataPanelLine_SliderEditable` | `obj:setLineSliderEditable(key, category, showName, min, max, tempVal)` |
| setLineSlider | Instance | `key: string, caption: string, min: number, max: number, category: integer, tempVal: number, scale: number` | `DataPanelLine_Slider` | `obj:setLineSlider(key, caption, min, max, category, tempVal, scale)` |
| setLineProgress | Instance | `key: string, category: integer, progressValue: number, progressText: string, showKey: boolean` | `DataPanelLine_Progress` | `obj:setLineProgress(key, category, progressValue, progressText, showKey)` |
| removeLine | Instance | `s1: string, category: integer` | `void` | `obj:removeLine(s1, category)` |
| setLineCheckbox | Instance | `s1: string, tempBool: boolean, category: integer` | `DataPanelLine_CheckBox` | `obj:setLineCheckbox(s1, tempBool, category)` |
| setLineDropBox | Instance | `key: string, category: integer, tempInt: integer, goBox: boolean, width: number` | `DataPanelLine_DropBox` | `obj:setLineDropBox(key, category, tempInt, goBox, width)` |
| addSpace | Instance | `category: integer, h: number` | `void` | `obj:addSpace(category, h)` |
| setCategoryIcon | Instance | `cat: integer, image: string` | `void` | `obj:setCategoryIcon(cat, image)` |
| changeCategory | Instance | `cat: integer` | `void` | `obj:changeCategory(cat)` |
| getCurrentCategory | Instance | `` | `integer` | `obj:getCurrentCategory()` |
| addCustomLine | Instance | `` | `void` | `obj:addCustomLine()` |
| getObject | Instance | `` | `void` | `obj:getObject()` |
| setLineSpacing | Instance | `numLinesPerScreen: number` | `void` | `obj:setLineSpacing(numLinesPerScreen)` |
| getLine | Instance | `key: string, cat: integer` | `DataPanelLine` | `obj:getLine(key, cat)` |
| lineExists | Instance | `key: string, cat: integer` | `boolean` | `obj:lineExists(key, cat)` |
| getContentHeight | Instance | `cat: integer` | `integer` | `obj:getContentHeight(cat)` |
| getNumLines | Instance | `cat: integer` | `integer` | `obj:getNumLines(cat)` |
| getLineByNum | Instance | `cat: integer, i: integer` | `DataPanelLine` | `obj:getLineByNum(cat, i)` |
| createLine | Instance | `category: integer, lastLine: boolean` | `DataPanelLine` | `obj:createLine(category, lastLine)` |
| getNextVerticalPos | Instance | `category: integer` | `number` | `obj:getNextVerticalPos(category)` |
| dataExists | Instance | `cat: integer, name: string` | `boolean` | `obj:dataExists(cat, name)` |
| clearCategoryTabs | Instance | `` | `void` | `obj:clearCategoryTabs()` |
| setLine [1] | Instance | `keyValue: string, s1: string, s2: string, skinA: string, skinB: string, category: integer` | `DataPanelLine` | `obj:setLine(keyValue, s1, s2, skinA, skinB, category)` |
| setLine [2] | Instance | `keyValue: string, s1: string, s2: string, category: integer, last: boolean, keyVisible: boolean` | `DataPanelLine` | `obj:setLine(keyValue, s1, s2, category, last, keyVisible)` |
| setLine [3] | Instance | `s1: string, s2: string, skinA: string, skinB: string, category: integer` | `DataPanelLine` | `obj:setLine(s1, s2, skinA, skinB, category)` |
| setLine [4] | Instance | `s1: string, s2: string, barValue: number, category: integer` | `DataPanelLine` | `obj:setLine(s1, s2, barValue, category)` |
| setLine [5] | Instance | `s1: string, s2: string, category: integer, last: boolean, keyVisible: boolean` | `DataPanelLine` | `obj:setLine(s1, s2, category, last, keyVisible)` |
| setLineResearch [1] | Instance | `s1: string, s2: string, category: integer, v1: number, barColor: string, XButton: boolean` | `DataPanelLine_Research` | `obj:setLineResearch(s1, s2, category, v1, barColor, XButton)` |
| setLineResearch [2] | Instance | `key: string, s1: string, s2: string, category: integer, v1: number, barColor: string, Xbutton: boolean` | `DataPanelLine_Research` | `obj:setLineResearch(key, s1, s2, category, v1, barColor, Xbutton)` |

## DataPanelLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| w1 | `lightuserdata` | R | `obj.w1` |
| w2 | `lightuserdata` | R | `obj.w2` |
| category | `integer` | RW | `obj.category = <value>` |
| keyValue | `string` | RW | `obj.keyValue = <value>` |
| s1 | `string` | RW | `obj.s1 = <value>` |
| s2 | `string` | RW | `obj.s2 = <value>` |
| lo | `integer` | RW | `obj.lo = <value>` |
| hi | `integer` | RW | `obj.hi = <value>` |
| skinW1 | `string` | RW | `obj.skinW1 = <value>` |
| skinW2 | `string` | RW | `obj.skinW2 = <value>` |
| classType | `integer` | RW | `obj.classType = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| setEnabled | Instance | `on: boolean` | `void` | `obj:setEnabled(on)` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| resize | Instance | `width: integer, height: integer` | `void` | `obj:resize(width, height)` |
| getBottom | Instance | `` | `integer` | `obj:getBottom()` |
| getType | Instance | `` | `integer` | `obj:getType()` |
| getUserData | Instance | `` | `void` | `obj:getUserData()` |
| getNumWidgets | Instance | `` | `integer` | `obj:getNumWidgets()` |
| getWidget | Instance | `index: integer` | `lightuserdata` | `obj:getWidget(index)` |

## DataPanelLine::Slider
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Parent Class:** [`DataPanelLine`](#datapanelline)
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setValue | Instance | `value: number` | `void` | `obj:setValue(value)` |
| getValue | Instance | `` | `number` | `obj:getValue()` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

## DataPanelLine_Button
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Button`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| userData | `unknown` | RW | `obj.userData = <value>` |
| button | `lightuserdata` | RW | `obj.button = <value>` |
| buttonWidth | `number` | RW | `obj.buttonWidth = <value>` |
| buttonHeight | `number` | RW | `obj.buttonHeight = <value>` |
| buttonSkin | `string` | RW | `obj.buttonSkin = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getUserData | Instance | `` | `void` | `obj:getUserData()` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

## DataPanelLine_CheckBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_CheckBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| valuePtr | `lightuserdata` | R | `obj.valuePtr` |
| text | `lightuserdata` | R | `obj.text` |
| button | `lightuserdata` | R | `obj.button` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| refresh | Instance | `` | `void` | `obj:refresh()` |
| setValue | Instance | `checked: boolean` | `void` | `obj:setValue(checked)` |
| setValuePtr | Instance | `bVal: boolean` | `void` | `obj:setValuePtr(bVal)` |
| getTextBox | Instance | `` | `MyGUI::Widget` | `obj:getTextBox()` |
| getCheckBox | Instance | `` | `MyGUI::Widget` | `obj:getCheckBox()` |
| createMe | Instance | `topReal: number, lastLine: boolean` | `void` | `obj:createMe(topReal, lastLine)` |

## DataPanelLine_DropBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_DropBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| listBox | `lightuserdata` | R | `obj.listBox` |
| listWidth | `number` | RW | `obj.listWidth = <value>` |
| valPtr | `lightuserdata` | R | `obj.valPtr` |
| hasGoBox | `boolean` | RW | `obj.hasGoBox = <value>` |
| goBox | `lightuserdata` | R | `obj.goBox` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addAValue | Instance | `key: string, val: integer` | `void` | `obj:addAValue(key, val)` |
| getSelectedValue | Instance | `` | `integer` | `obj:getSelectedValue()` |
| setSelectedValue | Instance | `val: integer` | `void` | `obj:setSelectedValue(val)` |
| getSelectedText | Instance | `` | `string` | `obj:getSelectedText()` |
| clearValues | Instance | `` | `void` | `obj:clearValues()` |
| getComboBox | Instance | `` | `lightuserdata` | `obj:getComboBox()` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |
| refresh | Instance | `` | `void` | `obj:refresh()` |

## DataPanelLine_Faction
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Faction`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| v1 | `number` | RW | `obj.v1 = <value>` |
| v2 | `number` | RW | `obj.v2 = <value>` |
| bar | `lightuserdata` | R | `obj.bar` |
| bar2 | `lightuserdata` | R | `obj.bar2` |
| but | `lightuserdata` | R | `obj.but` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

## DataPanelLine_KeyConfig
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_KeyConfig`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| btn0 | `lightuserdata` | R | `obj.btn0` |
| btn1 | `lightuserdata` | R | `obj.btn1` |
| command | `string` | RW | `obj.command = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| oldKey | Instance | `` | `integer` | `obj:oldKey()` |
| setKey | Instance | `s: string` | `void` | `obj:setKey(s)` |
| eraseKey | Instance | `key: string` | `void` | `obj:eraseKey(key)` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| cancel | Instance | `` | `void` | `obj:cancel()` |
| createMe | Instance | `vpos: number, lastLine: boolean` | `void` | `obj:createMe(vpos, lastLine)` |

## DataPanelLine_Progress
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Progress`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textBox | `lightuserdata` | R | `obj.textBox` |
| progress | `lightuserdata` | R | `obj.progress` |
| progressText | `lightuserdata` | R | `obj.progressText` |
| showKey | `boolean` | RW | `obj.showKey = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setProgress | Instance | `value: number, text: string` | `void` | `obj:setProgress(value, text)` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

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
| bar | `lightuserdata` | RW | `obj.bar = <value>` |
| but | `lightuserdata` | R | `obj.but` |
| Xbut | `lightuserdata` | R | `obj.Xbut` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

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
| nameText | `lightuserdata` | R | `obj.nameText` |
| valueEditBox | `lightuserdata` | R | `obj.valueEditBox` |
| sliderBar | `lightuserdata` | R | `obj.sliderBar` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setEditableValuePtr | Instance | `tempVal: number, lo: number, hi: number` | `void` | `obj:setEditableValuePtr(tempVal, lo, hi)` |
| getSlider | Instance | `` | `MyGUI::Widget` | `obj:getSlider()` |
| getEditBox | Instance | `` | `MyGUI::Widget` | `obj:getEditBox()` |
| setValue | Instance | `v: number` | `void` | `obj:setValue(v)` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| setPrecision | Instance | `dp: integer` | `void` | `obj:setPrecision(dp)` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

## DataPanelLine_Text
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_Text`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| editBox | `lightuserdata` | R | `obj.editBox` |
| wordWrap | `boolean` | RW | `obj.wordWrap = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

## DataPanelLine_TextEditable
**Header:** `extern/KenshiLib/Include/kenshi/gui/DataPanelLine.h`
**Metatable:** `KenshiLua.DataPanelLine_TextEditable`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| editBox | `lightuserdata` | R | `obj.editBox` |
| nameText | `lightuserdata` | R | `obj.nameText` |
| showKey | `boolean` | RW | `obj.showKey = <value>` |
| multiLine | `boolean` | RW | `obj.multiLine = <value>` |
| width | `number` | RW | `obj.width = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getEditBox | Instance | `` | `lightuserdata` | `obj:getEditBox()` |
| getNameBox | Instance | `` | `lightuserdata` | `obj:getNameBox()` |
| createMe | Instance | `top: number, lastLine: boolean` | `void` | `obj:createMe(top, lastLine)` |

## DialogChoiceList
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Metatable:** `KenshiLua.DialogChoiceList`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| conversationChoices | `lektor<DialogLineData*>` | RW | `obj.conversationChoices = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| add | Instance | `` | `void` | `obj:add()` |

## DialogDataManager
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Metatable:** `KenshiLua.DialogDataManager`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| _createData | Instance | `` | `DialogLineData` | `obj:_createData()` |
| initialise | Instance | `` | `void` | `obj:initialise()` |
| save | Instance | `` | `void` | `obj:save()` |
| load | Instance | `` | `void` | `obj:load()` |
| newGameReset | Instance | `` | `void` | `obj:newGameReset()` |
| getData | Instance | `` | `DialogLineData` | `obj:getData()` |

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
| hasItemType | `integer` | RW | `obj.hasItemType = <value>` |
| hasItem | `lektor<GameData*>` | RW | `obj.hasItem = <value>` |
| worldState | `WorldEventStateQueryList` | RW | `obj.worldState = <value>` |
| data | `GameData` | RW | `obj.data = <value>` |
| onceOnly | `boolean` | RW | `obj.onceOnly = <value>` |
| isMonologue | `boolean` | RW | `obj.isMonologue = <value>` |
| forCertainType | `integer` | RW | `obj.forCertainType = <value>` |
| children | `DialogChoiceList` | RW | `obj.children = <value>` |
| conditions | `lektor<DialogLineData::DialogCondition*>` | RW | `obj.conditions = <value>` |
| actions | `lektor<DialogLineData::DialogAction*>` | RW | `obj.actions = <value>` |
| lineCount | `integer` | RW | `obj.lineCount = <value>` |
| texts | `string` | RW | `obj.texts = <value>` |
| parent | `DialogLineData` | RW | `obj.parent = <value>` |
| chancePermanent | `number` | RW | `obj.chancePermanent = <value>` |
| chanceTemporary | `number` | RW | `obj.chanceTemporary = <value>` |
| unique | `boolean` | RW | `obj.unique = <value>` |
| uniqueOwner | `unknown` | RW | `obj.uniqueOwner = <value>` |
| dialogRepeatMinTimeInHours | `number` | RW | `obj.dialogRepeatMinTimeInHours = <value>` |
| lastTimeSaid | `TimeOfDay` | RW | `obj.lastTimeSaid = <value>` |
| score | `integer` | RW | `obj.score = <value>` |
| oneAtATime | `boolean` | RW | `obj.oneAtATime = <value>` |
| isLocked | `boolean` | RW | `obj.isLocked = <value>` |
| locks | `lektor<DialogLineData*>` | RW | `obj.locks = <value>` |
| unlocks_lockMe | `lektor<DialogLineData*>` | RW | `obj.unlocks_lockMe = <value>` |
| unlocks_dontLockMe | `lektor<DialogLineData*>` | RW | `obj.unlocks_dontLockMe = <value>` |
| crowdTrigger | `DialogLineData` | RW | `obj.crowdTrigger = <value>` |
| factionRelationEffects | `unknown` | RW | `obj.factionRelationEffects = <value>` |
| playerInterruptionDialog | `DialogLineData` | RW | `obj.playerInterruptionDialog = <value>` |
| isInterjection | `boolean` | RW | `obj.isInterjection = <value>` |
| speaker | `integer` | RW | `obj.speaker = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getParent | Instance | `` | `DialogLineData` | `obj:getParent()` |
| isForSpecificCharacter | Instance | `` | `boolean` | `obj:isForSpecificCharacter()` |
| hasSpecificCharacterRequirement | Instance | `` | `boolean` | `obj:hasSpecificCharacterRequirement()` |
| setupChildren | Instance | `` | `void` | `obj:setupChildren()` |
| checkRepeatLimits | Instance | `` | `boolean` | `obj:checkRepeatLimits()` |
| checkTags | Instance | `` | `boolean` | `obj:checkTags()` |
| getName | Instance | `` | `string` | `obj:getName()` |
| saidItBefore | Instance | `` | `boolean` | `obj:saidItBefore()` |
| willTalkToEnemies | Instance | `` | `boolean` | `obj:willTalkToEnemies()` |
| isEmptyNode | Instance | `` | `boolean` | `obj:isEmptyNode()` |
| isAnnouncement | Instance | `` | `boolean` | `obj:isAnnouncement()` |
| stampLastTimeSaid | Instance | `` | `void` | `obj:stampLastTimeSaid()` |
| getScore | Instance | `` | `integer` | `obj:getScore()` |
| getScorePlusChildrenIfEmpty | Instance | `` | `integer` | `obj:getScorePlusChildrenIfEmpty()` |
| hasChildren | Instance | `` | `boolean` | `obj:hasChildren()` |
| checkConditions | Instance | `isWordswap: boolean` | `boolean` | `obj:checkConditions(isWordswap)` |
| chooseAChild | Instance | `isForWordswaps: boolean` | `DialogLineData` | `obj:chooseAChild(isForWordswaps)` |
| getStringID | Instance | `` | `string` | `obj:getStringID()` |
| getGameData | Instance | `` | `GameData` | `obj:getGameData()` |
| getChildByStringID | Instance | `sid: string` | `DialogLineData` | `obj:getChildByStringID(sid)` |
| setParent | Instance | `` | `void` | `obj:setParent()` |
| getMoneyCostForLine | Instance | `` | `integer` | `obj:getMoneyCostForLine()` |
| getText [1] | Instance | `_stampTime: boolean` | `string` | `obj:getText(_stampTime)` |
| getText [2] | Instance | `out: string, _stampTime: boolean` | `void` | `obj:getText(out, _stampTime)` |
| getPlayerReplies | Instance | `` | `void` | `obj:getPlayerReplies()` |
| getActions | Instance | `` | `lektor<DialogLineData::DialogAction*>` | `obj:getActions()` |

## DialogLineData::DialogAction
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`DialogLineData`](#dialoglinedata)
**Metatable:** `KenshiLua.DialogAction`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | `integer` | RW | `obj.value = <value>` |
| key | `integer` | RW | `obj.key = <value>` |

## DialogLineData::DialogCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`DialogLineData`](#dialoglinedata)
**Metatable:** `KenshiLua.DialogCondition`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | `integer` | RW | `obj.key = <value>` |
| compareBy | `integer` | RW | `obj.compareBy = <value>` |
| who | `integer` | RW | `obj.who = <value>` |
| value | `integer` | RW | `obj.value = <value>` |

## DialogLineData::FlagCondition
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`DialogLineData`](#dialoglinedata)
**Metatable:** `KenshiLua.FlagCondition`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | `integer` | RW | `obj.key = <value>` |
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
| conversationTarget | `unknown` | RW | `obj.conversationTarget = <value>` |
| stats | `CharStats` | RW | `obj.stats = <value>` |
| movement | `CharMovement` | RW | `obj.movement = <value>` |
| currentConversationType | `integer` | RW | `obj.currentConversationType = <value>` |
| currentConversation | `DialogLineData` | RW | `obj.currentConversation = <value>` |
| currentLine | `DialogLineData` | RW | `obj.currentLine = <value>` |
| interjector1 | `unknown` | RW | `obj.interjector1 = <value>` |
| interjector2 | `unknown` | RW | `obj.interjector2 = <value>` |
| interjector3 | `unknown` | RW | `obj.interjector3 = <value>` |
| speechBubblePanel | `DialogueSpeechBubble` | RW | `obj.speechBubblePanel = <value>` |
| speechTextTimer | `number` | RW | `obj.speechTextTimer = <value>` |
| speechTextTimer_forced | `number` | RW | `obj.speechTextTimer_forced = <value>` |
| npcReplyText | `string` | RW | `obj.npcReplyText = <value>` |
| conversationMaster | `unknown` | RW | `obj.conversationMaster = <value>` |
| waitingForReplyFrom | `unknown` | RW | `obj.waitingForReplyFrom = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWordSwap | Instance | `key: string, _a3: boolean` | `string` | `obj:getWordSwap(key, _a3)` |
| setupWordSwaps | Instance | `` | `void` | `obj:setupWordSwaps()` |
| getGUIData | Instance | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| create | Instance | `` | `void` | `obj:create()` |
| getHandle | Instance | `` | `void` | `obj:getHandle()` |
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| setLineLocked | Instance | `on: boolean` | `void` | `obj:setLineLocked(on)` |
| isLocked | Instance | `` | `boolean` | `obj:isLocked()` |
| setInDialog | Instance | `on: boolean` | `void` | `obj:setInDialog(on)` |
| clearDialogues | Instance | `` | `void` | `obj:clearDialogues()` |
| clearAnnouncements | Instance | `` | `void` | `obj:clearAnnouncements()` |
| needsDialogAssessmentUpdate | Instance | `` | `boolean` | `obj:needsDialogAssessmentUpdate()` |
| addDialoguePackage | Instance | `` | `void` | `obj:addDialoguePackage()` |
| addConversation | Instance | `t: integer` | `void` | `obj:addConversation(t)` |
| clearConversationList | Instance | `t: integer` | `void` | `obj:clearConversationList(t)` |
| willTalkToEnemies | Instance | `` | `boolean` | `obj:willTalkToEnemies()` |
| sendEventOverride | Instance | `what: integer, forceRepeat: boolean` | `boolean` | `obj:sendEventOverride(what, forceRepeat)` |
| sendEvent | Instance | `what: integer` | `boolean` | `obj:sendEvent(what)` |
| stopEvent | Instance | `what: integer` | `void` | `obj:stopEvent(what)` |
| runCustomDialog | Instance | `` | `boolean` | `obj:runCustomDialog()` |
| scoreCustomDialog | Instance | `` | `integer` | `obj:scoreCustomDialog()` |
| conversationHasEnded | Instance | `` | `boolean` | `obj:conversationHasEnded()` |
| getConversationTarget | Instance | `` | `void` | `obj:getConversationTarget()` |
| changeConversationTarget | Instance | `` | `void` | `obj:changeConversationTarget()` |
| conversationHasEndedPrettyMuch | Instance | `` | `boolean` | `obj:conversationHasEndedPrettyMuch()` |
| makeAnnouncement | Instance | `` | `boolean` | `obj:makeAnnouncement()` |
| update | Instance | `frameTime: number` | `void` | `obj:update(frameTime)` |
| endDialogue | Instance | `definitelyTheEnd: boolean` | `void` | `obj:endDialogue(definitelyTheEnd)` |
| notifyUnderAttack | Instance | `` | `void` | `obj:notifyUnderAttack()` |
| hasDialogue_Fast | Instance | `` | `boolean` | `obj:hasDialogue_Fast()` |
| hasDialogue_Accurate | Instance | `` | `boolean` | `obj:hasDialogue_Accurate()` |
| hasDialogueEvent | Instance | `e: integer` | `boolean` | `obj:hasDialogueEvent(e)` |
| dialogDelivered | Instance | `e: integer` | `boolean` | `obj:dialogDelivered(e)` |
| _checkCondition | Instance | `conditionName: integer, compareBy: integer, val: integer` | `boolean` | `obj:_checkCondition(conditionName, compareBy, val)` |
| dontLetTargetBeMe | Instance | `` | `void` | `obj:dontLetTargetBeMe()` |
| hasThisChanceLine | Instance | `chance: number` | `boolean` | `obj:hasThisChanceLine(chance)` |
| _chooseDialog | Instance | `isWordswap: boolean` | `DialogLineData` | `obj:_chooseDialog(isWordswap)` |
| triggerNextLine | Instance | `` | `void` | `obj:triggerNextLine()` |
| targetInTalkingRange | Instance | `mult: number` | `boolean` | `obj:targetInTalkingRange(mult)` |
| save | Instance | `` | `void` | `obj:save()` |
| load | Instance | `` | `void` | `obj:load()` |
| getSpeaker | Instance | `who: integer, isForWordswaps: boolean` | `Character` | `obj:getSpeaker(who, isForWordswaps)` |
| isCurrentConversationRunning | Instance | `` | `boolean` | `obj:isCurrentConversationRunning()` |
| findInterjectionCharacter | Instance | `` | `Character` | `obj:findInterjectionCharacter()` |
| isKOExempt | Instance | `what: integer` | `boolean` | `obj:isKOExempt(what)` |
| _endPlayerConversation | Instance | `finished: boolean` | `void` | `obj:_endPlayerConversation(finished)` |
| startPlayerConversation | Instance | `` | `boolean` | `obj:startPlayerConversation()` |
| startConversation | Instance | `ev: integer, force: boolean` | `boolean` | `obj:startConversation(ev, force)` |
| getConversationList | Instance | `t: integer` | `DialogChoiceList` | `obj:getConversationList(t)` |
| _doActions | Instance | `` | `void` | `obj:_doActions()` |
| sayLine | Instance | `` | `boolean` | `obj:sayLine()` |
| listPlayerReplies | Instance | `` | `void` | `obj:listPlayerReplies()` |
| isLastLine | Instance | `` | `boolean` | `obj:isLastLine()` |
| setSpeaker | Instance | `who: integer` | `void` | `obj:setSpeaker(who)` |
| _updateTextPos | Instance | `` | `void` | `obj:_updateTextPos()` |
| clearSpeechBox | Instance | `` | `void` | `obj:clearSpeechBox()` |
| clearRespones | Instance | `` | `void` | `obj:clearRespones()` |
| clearResponesGUI | Instance | `` | `void` | `obj:clearResponesGUI()` |
| setResponesGUI | Instance | `` | `void` | `obj:setResponesGUI()` |
| setConversationReplyGUI | Instance | `` | `void` | `obj:setConversationReplyGUI()` |
| say [1] | Instance | `dialogLine: DialogLineData` | `void` | `obj:say(dialogLine)` |
| say [2] | Instance | `_text: string, line: DialogLineData` | `void` | `obj:say(_text, line)` |
| replyClicked [1] | Instance | `index: string` | `void` | `obj:replyClicked(index)` |
| replyClicked [2] | Instance | `index: integer` | `void` | `obj:replyClicked(index)` |
| isAtTownOf | Instance | `` | `boolean` | `obj:isAtTownOf()` |
| resolveOverlappedSpeechBubbles | Instance | `` | `void` | `obj:resolveOverlappedSpeechBubbles()` |

## Dialogue::RepetitionCounter
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`Dialogue`](#dialogue)
**Metatable:** `KenshiLua.RepetitionCounter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| states | `RepetitionStatesMapBinding::MapType` | RW | `obj.states = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | Instance | `` | `void` | `obj:setup()` |
| count | Instance | `ev: integer` | `boolean` | `obj:count(ev)` |
| getTimeSinceLastTrigger | Instance | `ev: integer` | `number` | `obj:getTimeSinceLastTrigger(ev)` |
| getCount | Instance | `ev: integer` | `integer` | `obj:getCount(ev)` |

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
| textBox | `lightuserdata` | RW | `obj.textBox = <value>` |
| baseSize | `integer` | RW | `obj.baseSize = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setText | Instance | `text: string` | `void` | `obj:setText(text)` |
| setAlpha | Instance | `value: number` | `void` | `obj:setAlpha(value)` |
| setPosition [1] | Instance | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setPosition [2] | Instance | `position: Vector3` | `void` | `obj:setPosition(position)` |
| reset | Instance | `` | `void` | `obj:reset()` |
| getAlpha | Instance | `` | `number` | `obj:getAlpha()` |
| getRect | Instance | `` | `integer` | `obj:getRect()` |

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
| conversationPCPanel | `lightuserdata` | RW | `obj.conversationPCPanel = <value>` |
| conversationNPCPanel | `lightuserdata` | RW | `obj.conversationNPCPanel = <value>` |
| conversationNPCNameText | `lightuserdata` | R | `obj.conversationNPCNameText` |
| conversationPCNameText | `lightuserdata` | R | `obj.conversationPCNameText` |
| conversationPCMoneyText | `lightuserdata` | R | `obj.conversationPCMoneyText` |
| conversationNPCSpeech | `lightuserdata` | RW | `obj.conversationNPCSpeech = <value>` |
| conversationPCSpeechPanel | `lightuserdata` | RW | `obj.conversationPCSpeechPanel = <value>` |
| conversationNPCPortrait | `lightuserdata` | R | `obj.conversationNPCPortrait` |
| conversationPCPortrait | `lightuserdata` | R | `obj.conversationPCPortrait` |
| replyTexts | `EditBoxFastArrayBinding::ArrayType` | RW | `obj.replyTexts = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| hide | Instance | `` | `void` | `obj:hide()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| update | Instance | `` | `void` | `obj:update()` |
| getTop | Instance | `` | `integer` | `obj:getTop()` |
| activateResponse | Instance | `index: integer` | `void` | `obj:activateResponse(index)` |
| setNPCText | Instance | `text: string` | `void` | `obj:setNPCText(text)` |
| setResponses | Instance | `arg1: type` | `void` | `obj:setResponses(arg1)` |
| clearResponses | Instance | `` | `void` | `obj:clearResponses()` |
| changePortrait | Instance | `player: boolean` | `void` | `obj:changePortrait(player)` |
| updatePanelsPosition | Instance | `` | `void` | `obj:updatePanelsPosition()` |

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
| state | `integer` | RW | `obj.state = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setupPhysicalUT | Instance | `` | `boolean` | `obj:setupPhysicalUT()` |
| getFaction | Instance | `` | `Faction` | `obj:getFaction()` |
| _getPhysActorUT | Instance | `` | `lightuserdata` | `obj:_getPhysActorUT()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |
| getGateCode | Instance | `` | `integer` | `obj:getGateCode()` |
| setGateCode | Instance | `code: integer` | `void` | `obj:setGateCode(code)` |
| isGate | Instance | `` | `GatewayBuilding` | `obj:isGate()` |
| isPublic | Instance | `` | `boolean` | `obj:isPublic()` |
| getMouseCursor | Instance | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| getReachRange | Instance | `` | `number` | `obj:getReachRange()` |
| getDoor | Instance | `` | `DoorStuff` | `obj:getDoor()` |
| getName | Instance | `` | `string` | `obj:getName()` |
| getDoorLock | Instance | `` | `lightuserdata` | `obj:getDoorLock()` |
| hasDoorLock | Instance | `` | `boolean` | `obj:hasDoorLock()` |
| updateGateCodeState | Instance | `` | `void` | `obj:updateGateCodeState()` |
| onBuildingLoaded | Instance | `` | `void` | `obj:onBuildingLoaded()` |
| setDoorOpenAmount | Instance | `amount: number, forceUnsafe: boolean` | `void` | `obj:setDoorOpenAmount(amount, forceUnsafe)` |
| isBroken | Instance | `` | `boolean` | `obj:isBroken()` |
| setBroken | Instance | `on: boolean` | `void` | `obj:setBroken(on)` |
| isDisabled | Instance | `` | `boolean` | `obj:isDisabled()` |
| isLocked | Instance | `` | `boolean` | `obj:isLocked()` |
| lockDoor | Instance | `` | `void` | `obj:lockDoor()` |
| unlockDoor | Instance | `` | `void` | `obj:unlockDoor()` |
| getDoorOpenAmount | Instance | `` | `number` | `obj:getDoorOpenAmount()` |
| setDoorState | Instance | `what: integer` | `void` | `obj:setDoorState(what)` |
| getDoorState | Instance | `` | `integer` | `obj:getDoorState()` |
| openDoor | Instance | `` | `boolean` | `obj:openDoor()` |
| closeDoor | Instance | `` | `boolean` | `obj:closeDoor()` |
| _forceDoorClosedUT | Instance | `` | `boolean` | `obj:_forceDoorClosedUT()` |
| _forceDoorOpenUT | Instance | `` | `boolean` | `obj:_forceDoorOpenUT()` |
| update | Instance | `` | `void` | `obj:update()` |
| getDoorPosOutside_extraFarOut | Instance | `mult: number` | `Vector3` | `obj:getDoorPosOutside_extraFarOut(mult)` |
| getDoorPosInside_extraFarIn | Instance | `mult: number` | `Vector3` | `obj:getDoorPosInside_extraFarIn(mult)` |
| isOpen | Instance | `` | `boolean` | `obj:isOpen()` |
| doorStuff | Instance | `` | `DoorStuff` | `obj:doorStuff()` |
| doorParentBuilding | Instance | `` | `Building` | `obj:doorParentBuilding()` |
| hitByMeleeAttack | Instance | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |
| getActorClosedPosition | Instance | `` | `Vector3` | `obj:getActorClosedPosition()` |
| getDoorPosition | Instance | `` | `Vector3` | `obj:getDoorPosition()` |
| getDoorPosOutside | Instance | `` | `Vector3` | `obj:getDoorPosOutside()` |
| getDoorPosInside | Instance | `` | `Vector3` | `obj:getDoorPosInside()` |

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
| mLeft | `lightuserdata` | RW | `obj.mLeft = <value>` |
| mRight | `lightuserdata` | RW | `obj.mRight = <value>` |
| face | `integer` | RW | `obj.face = <value>` |
| edge | `integer` | RW | `obj.edge = <value>` |
| leftClearance | `number` | RW | `obj.leftClearance = <value>` |
| rightClearance | `number` | RW | `obj.rightClearance = <value>` |
| maxPoint | `number` | RW | `obj.maxPoint = <value>` |

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`
**Metatable:** `KenshiLua.Faction`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _antiSlavery | `boolean` | RW | `obj._antiSlavery = <value>` |
| characteristicsData | `Faction::CharacteristicsData` | RW | `obj.characteristicsData = <value>` |
| fundamentalNPCType | `integer` | RW | `obj.fundamentalNPCType = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getProsperityMultiplier | Instance | `` | `number` | `obj:getProsperityMultiplier()` |
| clearAndDestroy | Instance | `` | `void` | `obj:clearAndDestroy()` |
| setup | Instance | `` | `boolean` | `obj:setup()` |
| setup2 | Instance | `` | `boolean` | `obj:setup2()` |
| setup3 | Instance | `` | `void` | `obj:setup3()` |
| getNewPlatoonID | Instance | `` | `string` | `obj:getNewPlatoonID()` |
| resetPlatoonID | Instance | `` | `void` | `obj:resetPlatoonID()` |
| createNewEmptyUnloadedPlatoon | Instance | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:createNewEmptyUnloadedPlatoon(pos, persistent)` |
| createNewEmptyActivePlatoon | Instance | `permanent: boolean, p: Vector3` | `Platoon` | `obj:createNewEmptyActivePlatoon(permanent, p)` |
| createPlatoonUnloaded | Instance | `pos: Vector3, persistent: boolean` | `void` | `obj:createPlatoonUnloaded(pos, persistent)` |
| createPlatoonAuto | Instance | `pos: Vector3` | `void` | `obj:createPlatoonAuto(pos)` |
| createReplacementPlatoonForPlayerWhenSavegameIsCorrupt | Instance | `src: string` | `void` | `obj:createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(src)` |
| restorePlatoon | Instance | `` | `void` | `obj:restorePlatoon()` |
| resetSquadPositions | Instance | `target: Vector3` | `boolean` | `obj:resetSquadPositions(target)` |
| countPopulation | Instance | `` | `integer` | `obj:countPopulation()` |
| countNumSquads | Instance | `` | `integer` | `obj:countNumSquads()` |
| destroyPlatoon | Instance | `` | `void` | `obj:destroyPlatoon()` |
| removePlatoon | Instance | `` | `void` | `obj:removePlatoon()` |
| getRandomLockLevel | Instance | `` | `integer` | `obj:getRandomLockLevel()` |
| getData | Instance | `` | `GameData` | `obj:getData()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getDefaultDivision | Instance | `` | `GameData` | `obj:getDefaultDivision()` |
| getFactionColorScheme | Instance | `` | `GameData` | `obj:getFactionColorScheme()` |
| loadState | Instance | `` | `void` | `obj:loadState()` |
| saveState | Instance | `leveleditor: boolean` | `GameData` | `obj:saveState(leveleditor)` |
| _activateUnloadedPlatoons | Instance | `` | `void` | `obj:_activateUnloadedPlatoons()` |
| getCharactersInArea | Instance | `pos: Vector3, radius: number, standingOnly: boolean` | `void` | `obj:getCharactersInArea(pos, radius, standingOnly)` |
| getSelectedObjects | Instance | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| removeObject | Instance | `` | `void` | `obj:removeObject()` |
| destroyObject | Instance | `` | `void` | `obj:destroyObject()` |
| processKillList | Instance | `` | `void` | `obj:processKillList()` |
| addActiveObject | Instance | `` | `boolean` | `obj:addActiveObject()` |
| choosePlatoon | Instance | `` | `ActivePlatoon` | `obj:choosePlatoon()` |
| getActivePlatoons | Instance | `` | `lektor<Platoon*>` | `obj:getActivePlatoons()` |
| getUnloadedPlatoons | Instance | `` | `lektor<Platoon*>` | `obj:getUnloadedPlatoons()` |
| getFactionSize | Instance | `` | `integer` | `obj:getFactionSize()` |
| update | Instance | `time: number` | `void` | `obj:update(time)` |
| periodicUpdateThreaded | Instance | `` | `boolean` | `obj:periodicUpdateThreaded()` |
| periodicUpdateMT | Instance | `` | `boolean` | `obj:periodicUpdateMT()` |
| isThePlayer | Instance | `` | `boolean` | `obj:isThePlayer()` |
| isNotARealFaction | Instance | `` | `boolean` | `obj:isNotARealFaction()` |
| getName | Instance | `` | `void` | `obj:getName()` |
| getNumPlatoons | Instance | `tempsOnly: boolean` | `integer` | `obj:getNumPlatoons(tempsOnly)` |
| getSquadThatOwns | Instance | `` | `Platoon` | `obj:getSquadThatOwns()` |
| getAllActiveSquads | Instance | `` | `lightuserdata` | `obj:getAllActiveSquads()` |
| getRoadPreference | Instance | `` | `number` | `obj:getRoadPreference()` |
| isAntiSlavery | Instance | `` | `boolean` | `obj:isAntiSlavery()` |
| getLawEnforcementFaction | Instance | `` | `Faction` | `obj:getLawEnforcementFaction()` |
| chooseARace | Instance | `` | `GameData` | `obj:chooseARace()` |
| setName | Instance | `_name: string` | `void` | `obj:setName(_name)` |
| getBuildingReplacement | Instance | `` | `GameData` | `obj:getBuildingReplacement()` |
| _switchToUnloadedPlatoon | Instance | `` | `void` | `obj:_switchToUnloadedPlatoon()` |
| _newPlatoon | Instance | `pos: Vector3, persistent: boolean` | `Platoon` | `obj:_newPlatoon(pos, persistent)` |
| _addActivePlatoonToList | Instance | `` | `void` | `obj:_addActivePlatoonToList()` |
| addPlatoon | Instance | `` | `void` | `obj:addPlatoon()` |
| changePlatoonIndex | Instance | `index: integer` | `void` | `obj:changePlatoonIndex(index)` |
| deactivatePlatoon | Instance | `` | `void` | `obj:deactivatePlatoon()` |
| activatePlatoon | Instance | `` | `void` | `obj:activatePlatoon()` |
| updateUnloadedPlatoons | Instance | `time: number` | `void` | `obj:updateUnloadedPlatoons(time)` |
| updateActivePlatoons | Instance | `time: number` | `void` | `obj:updateActivePlatoons(time)` |
| spawnSquadMissionsUpdate | Instance | `` | `void` | `obj:spawnSquadMissionsUpdate()` |
| _spawnASquad | Instance | `listname: string, sizeMultiplier: number` | `boolean` | `obj:_spawnASquad(listname, sizeMultiplier)` |
| getFundamentalNPCType | Instance | `` | `integer` | `obj:getFundamentalNPCType()` |

## Faction::BuildingSwaps
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`Faction`](#faction)
**Metatable:** `KenshiLua.BuildingSwaps`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| toReplace | `ogre_unordered_set<GameData*>::type` | RW | `obj.toReplace = <value>` |
| replaceWith | `FitnessSelector<GameData*>` | RW | `obj.replaceWith = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasReplacement | Instance | `` | `boolean` | `obj:hasReplacement()` |
| getReplacement | Instance | `` | `GameData` | `obj:getReplacement()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setNewLeader | Instance | `` | `void` | `obj:setNewLeader()` |
| getEnemyMissionTargetList | Instance | `` | `void` | `obj:getEnemyMissionTargetList()` |
| getGUIData | Instance | `cat: integer` | `void` | `obj:getGUIData(cat)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| saveGameState | Instance | `` | `void` | `obj:saveGameState()` |
| savePlayerGameState | Instance | `` | `void` | `obj:savePlayerGameState()` |
| clearAndDestroy | Instance | `` | `void` | `obj:clearAndDestroy()` |
| activateUnloadedPlatoons | Instance | `` | `void` | `obj:activateUnloadedPlatoons()` |
| getOrCreateFaction [1] | Instance | `id: string, name: string` | `Faction` | `obj:getOrCreateFaction(id, name)` |
| getOrCreateFaction [2] | Instance | `data: GameData` | `Faction` | `obj:getOrCreateFaction(data)` |
| getFactionByName | Instance | `name: string` | `Faction` | `obj:getFactionByName(name)` |
| getFactionByStringID | Instance | `sid: string` | `Faction` | `obj:getFactionByStringID(sid)` |
| getEmptyFaction | Instance | `` | `Faction` | `obj:getEmptyFaction()` |
| setupAndLinkAllFactions | Instance | `` | `void` | `obj:setupAndLinkAllFactions()` |
| getFactionBySquad | Instance | `` | `Faction` | `obj:getFactionBySquad()` |
| getCampaignGUIInfos | Instance | `cat: integer, playeronly: boolean` | `void` | `obj:getCampaignGUIInfos(cat, playeronly)` |
| areAnyHostileCampaignsRunning | Instance | `` | `boolean` | `obj:areAnyHostileCampaignsRunning()` |
| getNumTempPlatoons | Instance | `` | `integer` | `obj:getNumTempPlatoons()` |
| updateMT | Instance | `time: number` | `void` | `obj:updateMT(time)` |
| updateThreaded | Instance | `time: number` | `void` | `obj:updateThreaded(time)` |
| _showDebugPlatoonMarkers | Instance | `on: boolean` | `void` | `obj:_showDebugPlatoonMarkers(on)` |
| getAllFactions | Instance | `` | `lightuserdata` | `obj:getAllFactions()` |

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
| _factionRelations | `unknown` | RW | `obj._factionRelations = <value>` |
| defaultFactionRelation | `number` | RW | `obj.defaultFactionRelation = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setupPhase2 | Instance | `` | `void` | `obj:setupPhase2()` |
| isEnemyByDefault | Instance | `` | `boolean` | `obj:isEnemyByDefault()` |
| reset | Instance | `` | `void` | `obj:reset()` |
| update | Instance | `` | `void` | `obj:update()` |
| setupPhase1 | Instance | `` | `void` | `obj:setupPhase1()` |
| save [1] | Instance | `factionsList: GameData` | `void` | `obj:save(factionsList)` |
| save [2] | Instance | `factionsList: GameData, ID: string, who: Faction` | `void` | `obj:save(factionsList, ID, who)` |
| load [1] | Instance | `gamestate_faction: GameData, playerOnly: boolean` | `void` | `obj:load(gamestate_faction, playerOnly)` |
| load [2] | Instance | `gamestate_faction: GameData, ID: string, who: Faction` | `void` | `obj:load(gamestate_faction, ID, who)` |
| _isAlly | Instance | `` | `boolean` | `obj:_isAlly()` |
| _isEnemy | Instance | `` | `boolean` | `obj:_isEnemy()` |
| isEnemy | Instance | `` | `boolean` | `obj:isEnemy()` |
| setEnemy | Instance | `` | `void` | `obj:setEnemy()` |
| isAlly | Instance | `` | `boolean` | `obj:isAlly()` |
| isCoexisting | Instance | `` | `boolean` | `obj:isCoexisting()` |
| getFactionRelation | Instance | `` | `number` | `obj:getFactionRelation()` |
| getFactionRelationMultiplier | Instance | `` | `number` | `obj:getFactionRelationMultiplier()` |
| getFactionRelationMultiplierInverse | Instance | `` | `number` | `obj:getFactionRelationMultiplierInverse()` |
| setRelation | Instance | `setTo: number` | `void` | `obj:setRelation(setTo)` |
| affectRelations [1] | Instance | `p: Faction, e: FactionEvent, mult: number` | `void` | `obj:affectRelations(p, e, mult)` |
| affectRelations [2] | Instance | `p: Faction, amount: number, mult: number` | `void` | `obj:affectRelations(p, amount, mult)` |
| affectTrust | Instance | `amount: number, mult: number` | `void` | `obj:affectTrust(amount, mult)` |
| setNoLongerEnemies | Instance | `` | `void` | `obj:setNoLongerEnemies()` |
| declareWar | Instance | `` | `void` | `obj:declareWar()` |
| affectReputation | Instance | `amount: number` | `void` | `obj:affectReputation(amount)` |
| getRelationData | Instance | `` | `FactionRelations::RelationData` | `obj:getRelationData()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getRelationsData | Instance | `` | `void` | `obj:getRelationsData()` |
| checkStateCondition | Instance | `conditionName: integer, compareBy: integer, val: integer` | `boolean` | `obj:checkStateCondition(conditionName, compareBy, val)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| save | Instance | `ID: string` | `void` | `obj:save(ID)` |
| load | Instance | `ID: string` | `void` | `obj:load(ID)` |

## FactionsScreen
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`
**Metatable:** `KenshiLua.FactionsScreen`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mainWidget | `lightuserdata` | R | `obj.mainWidget` |
| selectedFaction | `Faction` | RW | `obj.selectedFaction = <value>` |
| scrollList | `lightuserdata` | RW | `obj.scrollList = <value>` |
| scrollListItemTop | `integer` | RW | `obj.scrollListItemTop = <value>` |
| scrollListItemWidth | `integer` | RW | `obj.scrollListItemWidth = <value>` |
| nameText | `lightuserdata` | R | `obj.nameText` |
| infoPanel | `DatapanelGUI` | RW | `obj.infoPanel = <value>` |
| lines | `FactionLinesMapBinding::MapType` | RW | `obj.lines = <value>` |
| updateTimer | `number` | RW | `obj.updateTimer = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| clear | Instance | `` | `void` | `obj:clear()` |
| update | Instance | `` | `void` | `obj:update()` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| updateInfo | Instance | `` | `void` | `obj:updateInfo()` |

## FactionsScreen::FactionRelationsLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/FactionsScreen.h`
**Parent Class:** [`FactionsScreen`](#factionsscreen)
**Metatable:** `KenshiLua.FactionRelationsLine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| faction | `Faction` | RW | `obj.faction = <value>` |
| value | `number` | RW | `obj.value = <value>` |
| valueText | `lightuserdata` | R | `obj.valueText` |
| leftBar | `lightuserdata` | R | `obj.leftBar` |
| rightBar | `lightuserdata` | R | `obj.rightBar` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |

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

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clearAndReset | Instance | `` | `void` | `obj:clearAndReset()` |
| initialiseNew | Instance | `` | `void` | `obj:initialiseNew()` |
| chooseRandomSquadToSpawn | Instance | `time: number` | `GameData` | `obj:chooseRandomSquadToSpawn(time)` |
| periodicUpdate | Instance | `time: number` | `void` | `obj:periodicUpdate(time)` |
| serialise | Instance | `` | `void` | `obj:serialise()` |
| load | Instance | `import: boolean` | `void` | `obj:load(import)` |
| getGUIData | Instance | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| getExistingSquadsFor | Instance | `` | `lightuserdata` | `obj:getExistingSquadsFor()` |
| spawnNewUniqueSquad | Instance | `` | `lightuserdata` | `obj:spawnNewUniqueSquad()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| currentNumber | Instance | `` | `integer` | `obj:currentNumber()` |

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
| campaignRequests | `lightuserdata` | RW | `obj.campaignRequests = <value>` |
| possibleCampaigns | `lightuserdata` | RW | `obj.possibleCampaigns = <value>` |
| forces | `lightuserdata` | RW | `obj.forces = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | Instance | `` | `void` | `obj:reset()` |
| save | Instance | `` | `void` | `obj:save()` |
| load | Instance | `` | `void` | `obj:load()` |
| removePlatoon | Instance | `` | `void` | `obj:removePlatoon()` |
| addPlatoon | Instance | `` | `void` | `obj:addPlatoon()` |
| getGUIData | Instance | `cat: integer, playeronly: boolean` | `void` | `obj:getGUIData(cat, playeronly)` |
| areAnyHostileCampaignsRunning | Instance | `playeronly: boolean` | `boolean` | `obj:areAnyHostileCampaignsRunning(playeronly)` |
| endCampaign | Instance | `c: userdata` | `void` | `obj:endCampaign(c)` |
| getAllTheForces | Instance | `c: userdata` | `void` | `obj:getAllTheForces(c)` |
| _generateForcesForTown | Instance | `c: userdata` | `void` | `obj:_generateForcesForTown(c)` |
| canGenerateThisManyForces | Instance | `num: integer` | `boolean` | `obj:canGenerateThisManyForces(num)` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| debugButton | Instance | `` | `void` | `obj:debugButton()` |
| triggerCampaign [1] | Instance | `targetTown: RootObjectBase, data: CampaignData, home: TownBase` | `CampaignInstance` | `obj:triggerCampaign(targetTown, data, home)` |
| triggerCampaign [2] | Instance | `targetTown: RootObjectBase, _data: GameData, minTime: number, maxTime: number, hometown: TownBase, forceDuplicate: boolean, triggeringFaction: Faction` | `void` | `obj:triggerCampaign(targetTown, _data, minTime, maxTime, hometown, forceDuplicate, triggeringFaction)` |
| triggerCampaign [3] | Instance | `randomTriggers: FitnessSelector<CampaignTriggerData*>, targetTown: RootObjectBase, hometown: TownBase, forceDuplicate: boolean, triggeringFaction: Faction` | `void` | `obj:triggerCampaign(randomTriggers, targetTown, hometown, forceDuplicate, triggeringFaction)` |
| getCurrentCampaign | Instance | `` | `lightuserdata` | `obj:getCurrentCampaign()` |
| getAITarget | Instance | `` | `void` | `obj:getAITarget()` |
| getMyUnloadedAI | Instance | `` | `integer` | `obj:getMyUnloadedAI()` |
| isBiomeHomeTerritory | Instance | `area: userdata` | `boolean` | `obj:isBiomeHomeTerritory(area)` |
| getNearestTown | Instance | `p: Vector3` | `TownBase` | `obj:getNearestTown(p)` |
| getTownsInBiome | Instance | `b: userdata` | `void` | `obj:getTownsInBiome(b)` |
| getMyTownsWithEnoughFreePopulation | Instance | `popNeeded: integer` | `void` | `obj:getMyTownsWithEnoughFreePopulation(popNeeded)` |
| getActiveCampaign | Instance | `uniqueID: integer` | `lightuserdata` | `obj:getActiveCampaign(uniqueID)` |
| setup | Instance | `` | `void` | `obj:setup()` |
| _createCampaignData | Instance | `` | `lightuserdata` | `obj:_createCampaignData()` |

## FactionWarMgr::CampaignRequest
**Header:** `extern/KenshiLib/Include/kenshi/FactionWarMgr.h`
**Parent Class:** [`FactionWarMgr`](#factionwarmgr)
**Metatable:** `KenshiLua.CampaignRequest`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeToStart | `TimeOfDay` | RW | `obj.timeToStart = <value>` |
| data | `lightuserdata` | R | `obj.data` |
| target | `unknown` | RW | `obj.target = <value>` |
| homeBase | `unknown` | RW | `obj.homeBase = <value>` |
| enemy | `Faction` | RW | `obj.enemy = <value>` |
| numAttempts | `integer` | RW | `obj.numAttempts = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| tryToChangeTarget | Instance | `` | `boolean` | `obj:tryToChangeTarget()` |

## FactoryCallbackInterface
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`
**Metatable:** `KenshiLua.FactoryCallbackInterface`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| factoryObjectCreatedCallback | Instance | `` | `void` | `obj:factoryObjectCreatedCallback()` |

## FarmBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Metatable:** `KenshiLua.FarmBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| cropMultipliers | `unknown` | RW | `obj.cropMultipliers = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| update | Instance | `` | `void` | `obj:update()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |
| operate | Instance | `amount: number` | `void` | `obj:operate(amount)` |
| isAnyInputsEmpty | Instance | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| isProductionFull | Instance | `` | `boolean` | `obj:isProductionFull()` |
| howMuchPowerDoYouWantForSortingFunction | Instance | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| setupMiningResourceLevel | Instance | `` | `void` | `obj:setupMiningResourceLevel()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getGUIEfficiency | Instance | `category: integer` | `void` | `obj:getGUIEfficiency(category)` |
| getGUIWorkers | Instance | `category: integer` | `void` | `obj:getGUIWorkers(category)` |
| getGUIState | Instance | `category: integer` | `void` | `obj:getGUIState(category)` |
| destroyAPlant | Instance | `` | `boolean` | `obj:destroyAPlant()` |
| timeSkip | Instance | `h: number, ignoreWater: boolean` | `void` | `obj:timeSkip(h, ignoreWater)` |
| _updateInputs | Instance | `rate: number` | `boolean` | `obj:_updateInputs(rate)` |
| upgrade | Instance | `` | `void` | `obj:upgrade()` |
| downgrade | Instance | `` | `void` | `obj:downgrade()` |
| getGUIFertility | Instance | `category: integer` | `void` | `obj:getGUIFertility(category)` |
| isCropsEdible | Instance | `` | `boolean` | `obj:isCropsEdible()` |
| eat | Instance | `rate: number` | `void` | `obj:eat(rate)` |
| getYieldChancePerCrop [1] | Instance | `farmData: GameData, biome: AreaBiomeGroup, skillMult: number, resourceMult: number` | `number` | `obj:getYieldChancePerCrop(farmData, biome, skillMult, resourceMult)` |
| getYieldChancePerCrop [2] | Instance | `skillMult: number` | `number` | `obj:getYieldChancePerCrop(skillMult)` |
| getCropMult | Instance | `typ: integer` | `number` | `obj:getCropMult(typ)` |
| serialise | Instance | `offsetPosToSubtract: userdata` | `void` | `obj:serialise(offsetPosToSubtract)` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| getDirectionMarker | Instance | `currentPosition: Vector3` | `Vector3` | `obj:getDirectionMarker(currentPosition)` |
| dontNeedWorkRightNow | Instance | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| getFertilityMultiplier | Instance | `` | `number` | `obj:getFertilityMultiplier()` |
| setupMaterial | Instance | `` | `void` | `obj:setupMaterial()` |
| updateMaterial | Instance | `` | `void` | `obj:updateMaterial()` |
| updatePlantInstance | Instance | `` | `void` | `obj:updatePlantInstance()` |
| createPlants | Instance | `` | `void` | `obj:createPlants()` |
| createClickHull | Instance | `` | `void` | `obj:createClickHull()` |
| createEntity | Instance | `` | `void` | `obj:createEntity()` |
| resetFarm | Instance | `` | `void` | `obj:resetFarm()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| load | Instance | `` | `void` | `obj:load()` |
| meshLoaded | Instance | `res: userdata, entityData: userdata` | `void` | `obj:meshLoaded(res, entityData)` |
| createGeometry | Instance | `` | `void` | `obj:createGeometry()` |

## FarmBuilding::Plant
**Header:** `extern/KenshiLib/Include/kenshi/Building/FarmBuilding.h`
**Parent Class:** [`FarmBuilding`](#farmbuilding)
**Metatable:** `KenshiLua.FarmBuilding_Plant`

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setProgress | Instance | `value: number` | `void` | `obj:setProgress(value)` |
| setCaption | Instance | `value: string` | `void` | `obj:setCaption(value)` |
| update | Instance | `` | `void` | `obj:update()` |

## FloatingProgressBar::ProgressBarWidget
**Header:** `extern/KenshiLib/Include/kenshi/gui/ForgottenGUI.h`
**Parent Class:** [`FloatingProgressBar`](#floatingprogressbar)
**Metatable:** `KenshiLua.ProgressBarWidget`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bar | `lightuserdata` | R | `obj.bar` |
| label | `lightuserdata` | R | `obj.label` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `value: boolean` | `void` | `obj:setVisible(value)` |
| setProgress | Instance | `value: integer` | `void` | `obj:setProgress(value)` |
| setPosition | Instance | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| setCaption | Instance | `value: string` | `void` | `obj:setCaption(value)` |

## FlockingTools
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.FlockingTools`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| getOutOfTheWayOfCharacter | `unknown` | RW | `obj.getOutOfTheWayOfCharacter = <value>` |
| currentPosition | `Vector3` | RW | `obj.currentPosition = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| combatMover | `CombatMovementController` | RW | `obj.combatMover = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| create | Instance | `` | `void` | `obj:create()` |
| getDistanceToClosestCharacter | Instance | `enemies: boolean, allies: boolean` | `number` | `obj:getDistanceToClosestCharacter(enemies, allies)` |
| getOutOfTheWay | Instance | `` | `void` | `obj:getOutOfTheWay()` |
| setCurrentPosition | Instance | `_pos: Vector3` | `void` | `obj:setCurrentPosition(_pos)` |
| getRepulsionMagnitude | Instance | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `number` | `obj:getRepulsionMagnitude(repulsionPoint, MAX_DISTANCE, distance)` |
| getRepulsionVector | Instance | `repulsionPoint: Vector3, MAX_DISTANCE: number, distance: number` | `Vector3` | `obj:getRepulsionVector(repulsionPoint, MAX_DISTANCE, distance)` |
| clampRepulsionVectorTo90Degrees | Instance | `desiredDirection: Vector3, alwaysStrafe: boolean` | `Vector3` | `obj:clampRepulsionVectorTo90Degrees(desiredDirection, alwaysStrafe)` |
| calculateCurrentRepulsionVector | Instance | `MAX_DISTANCE: number, desiredDirection: Vector3, includeEnemies: boolean, includeFriends: boolean, strafeOnly: boolean` | `Vector3` | `obj:calculateCurrentRepulsionVector(MAX_DISTANCE, desiredDirection, includeEnemies, includeFriends, strafeOnly)` |
| getSensoryData | Instance | `` | `SensoryData` | `obj:getSensoryData()` |

## FogEditor
**Header:** `extern/KenshiLib/Include/kenshi/gui/FogEditor.h`
**Metatable:** `KenshiLua.FogEditor`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | `lightuserdata` | R | `obj.window` |
| fogList | `lightuserdata` | R | `obj.fogList` |
| typeList | `lightuserdata` | R | `obj.typeList` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| show | Instance | `` | `void` | `obj:show()` |
| close | Instance | `` | `void` | `obj:close()` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| save | Instance | `filename: string` | `void` | `obj:save(filename)` |
| updateFogName | Instance | `` | `void` | `obj:updateFogName()` |
| updateFogValues | Instance | `` | `void` | `obj:updateFogValues()` |
| selectNextEdge | Instance | `` | `void` | `obj:selectNextEdge()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| getCollisionHash | Instance | `` | `integer` | `obj:getCollisionHash()` |
| setupGrass | Instance | `paged: userdata, grassLoader: userdata, biomeCode: integer` | `void` | `obj:setupGrass(paged, grassLoader, biomeCode)` |
| setupFoliage | Instance | `paged: userdata, treeLoader: userdata, biomeCode: integer` | `void` | `obj:setupFoliage(paged, treeLoader, biomeCode)` |
| spawn | Instance | `ent: userdata, position: Vector3, _treeLoader: userdata` | `boolean` | `obj:spawn(ent, position, _treeLoader)` |
| randomInt | Instance | `min: integer, max: integer` | `integer` | `obj:randomInt(min, max)` |
| random | Instance | `min: number, max: number` | `number` | `obj:random(min, max)` |
| clearStaticData | Static / Instance | `` | `void` | `FoliageSystem.clearStaticData()`<br>`obj:clearStaticData()` |

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
| type | `integer` | RW | `obj.type = <value>` |
| referenceCount | `integer` | RW | `obj.referenceCount = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createEntity1 | Instance | `` | `lightuserdata` | `obj:createEntity1()` |
| createEntity2 | Instance | `` | `lightuserdata` | `obj:createEntity2()` |
| selectBiomeEntity | Instance | `position: Vector3` | `lightuserdata` | `obj:selectBiomeEntity(position)` |
| isLoaded | Instance | `` | `boolean` | `obj:isLoaded()` |

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
| currentCursor | `integer` | RW | `obj.currentCursor = <value>` |
| Scale | `Vector2` | RW | `obj.Scale = <value>` |
| manager | `lightuserdata` | R | `obj.manager` |
| guiPlatform | `lightuserdata` | R | `obj.guiPlatform` |
| _closeTradeWindowMsg | `boolean` | RW | `obj._closeTradeWindowMsg = <value>` |
| tradeA | `unknown` | RW | `obj.tradeA = <value>` |
| tradeB | `unknown` | RW | `obj.tradeB = <value>` |
| inventoryWindowBuilding | `unknown` | RW | `obj.inventoryWindowBuilding = <value>` |
| inventoryWindowCharacter | `unknown` | RW | `obj.inventoryWindowCharacter = <value>` |
| inventoryWindowTrader | `unknown` | RW | `obj.inventoryWindowTrader = <value>` |
| inventoryWindowNPC | `unknown` | RW | `obj.inventoryWindowNPC = <value>` |
| characterEditor | `CharacterEditWindow` | RW | `obj.characterEditor = <value>` |
| guiScreenLabelsMutex | `lightuserdata` | R | `obj.guiScreenLabelsMutex` |
| selectedObject | `unknown` | RW | `obj.selectedObject = <value>` |
| selectedPlayerCharacter | `unknown` | RW | `obj.selectedPlayerCharacter = <value>` |
| cursorPanel | `DatapanelGUI` | RW | `obj.cursorPanel = <value>` |
| cursorAction | `boolean` | RW | `obj.cursorAction = <value>` |
| cursorActionPlayer | `unknown` | RW | `obj.cursorActionPlayer = <value>` |
| cursorActionTarget | `unknown` | RW | `obj.cursorActionTarget = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| created | `boolean` | RW | `obj.created = <value>` |
| inventoryWindowsOpen | `ForgottenInventoryWindowsOpenMapBinding::MapType` | RW | `obj.inventoryWindowsOpen = <value>` |
| inventoryWindowsPermanent | `ForgottenInventoryWindowsPermanentSetBinding::SetType` | RW | `obj.inventoryWindowsPermanent = <value>` |
| guiWindows | `lektor<GUIWindow*>` | RW | `obj.guiWindows = <value>` |
| guiDatapanels | `lektor<DatapanelGUI*>` | RW | `obj.guiDatapanels = <value>` |
| guiScreenLabels | `lektor<ScreenLabelInterface*>` | RW | `obj.guiScreenLabels = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clearGUI | Instance | `` | `void` | `obj:clearGUI()` |
| shutDown | Instance | `` | `void` | `obj:shutDown()` |
| restart | Instance | `` | `void` | `obj:restart()` |
| setupGuiScaling | Instance | `` | `void` | `obj:setupGuiScaling()` |
| init | Instance | `` | `void` | `obj:init()` |
| getTopOfScreenMessagePosition | Instance | `` | `number` | `obj:getTopOfScreenMessagePosition()` |
| showLoadingMessage | Instance | `on: boolean` | `void` | `obj:showLoadingMessage(on)` |
| isLoadingMessageVisible | Instance | `` | `boolean` | `obj:isLoadingMessageVisible()` |
| showPauseMessage | Instance | `on: boolean` | `void` | `obj:showPauseMessage(on)` |
| isLoading | Instance | `` | `boolean` | `obj:isLoading()` |
| setLoading | Instance | `value: boolean` | `void` | `obj:setLoading(value)` |
| isPaused | Instance | `` | `boolean` | `obj:isPaused()` |
| inDialogue | Instance | `` | `boolean` | `obj:inDialogue()` |
| hideMessageBox | Instance | `enter: boolean` | `boolean` | `obj:hideMessageBox(enter)` |
| hasModalMessage | Instance | `` | `boolean` | `obj:hasModalMessage()` |
| showMainbar | Instance | `on: boolean` | `void` | `obj:showMainbar(on)` |
| updateBountyPanelVisibility | Instance | `` | `void` | `obj:updateBountyPanelVisibility()` |
| getInDialogue | Instance | `` | `boolean` | `obj:getInDialogue()` |
| getToolTip | Instance | `` | `ToolTip` | `obj:getToolTip()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| toggle | Instance | `` | `void` | `obj:toggle()` |
| showNames | Instance | `on: boolean` | `void` | `obj:showNames(on)` |
| showPrintOutput | Instance | `v: boolean` | `void` | `obj:showPrintOutput(v)` |
| closeCharacterEditor | Instance | `` | `void` | `obj:closeCharacterEditor()` |
| isCharacterEditorMode | Instance | `` | `boolean` | `obj:isCharacterEditorMode()` |
| closeAllCharacterStatsWindows | Instance | `` | `void` | `obj:closeAllCharacterStatsWindows()` |
| isStatsWindowOpen | Instance | `` | `boolean` | `obj:isStatsWindowOpen()` |
| characterStatsWindowVisible | Instance | `` | `boolean` | `obj:characterStatsWindowVisible()` |
| selectedObjectsChanged | Instance | `` | `void` | `obj:selectedObjectsChanged()` |
| updateToOrdersPanel | Instance | `` | `void` | `obj:updateToOrdersPanel()` |
| notifyTownDeleted | Instance | `` | `void` | `obj:notifyTownDeleted()` |
| update | Instance | `` | `void` | `obj:update()` |
| closeTradeWindow | Instance | `` | `void` | `obj:closeTradeWindow()` |
| closeInventoryBuilding | Instance | `` | `void` | `obj:closeInventoryBuilding()` |
| closeAllInventories | Instance | `` | `void` | `obj:closeAllInventories()` |
| closeAllWindows | Instance | `` | `void` | `obj:closeAllWindows()` |
| getNumOpenInventoryWindows | Instance | `` | `integer` | `obj:getNumOpenInventoryWindows()` |
| getInventoryWindowWithMouse | Instance | `` | `InventoryGUI` | `obj:getInventoryWindowWithMouse()` |
| isAnyInventoryWindowOpen | Instance | `` | `boolean` | `obj:isAnyInventoryWindowOpen()` |
| toggleHelpWindow | Instance | `` | `void` | `obj:toggleHelpWindow()` |
| addWindowToUpdateList | Instance | `` | `void` | `obj:addWindowToUpdateList()` |
| removeWindowFromUpdateList | Instance | `` | `void` | `obj:removeWindowFromUpdateList()` |
| addDatapanelToUpdateList | Instance | `` | `void` | `obj:addDatapanelToUpdateList()` |
| removeDatapanelFromUpdateList | Instance | `` | `void` | `obj:removeDatapanelFromUpdateList()` |
| setMouseCursorVisible | Instance | `visible: boolean` | `void` | `obj:setMouseCursorVisible(visible)` |
| getGuiManager | Instance | `` | `lightuserdata` | `obj:getGuiManager()` |
| createPanel | Instance | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanel(name, top, left, width, height, layer, skin)` |
| createPanelAbs | Instance | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createPanelAbs(name, top, left, width, height, layer, skin)` |
| createTabPanel | Instance | `name: string, top: number, left: number, width: number, height: number, layer: string, skin: string` | `lightuserdata` | `obj:createTabPanel(name, top, left, width, height, layer, skin)` |
| createFloatingImage | Instance | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImage(image, top, left, width, height, layer)` |
| createFloatingImageAbs | Instance | `image: string, top: number, left: number, width: number, height: number, layer: string` | `lightuserdata` | `obj:createFloatingImageAbs(image, top, left, width, height, layer)` |
| createFloatingProgressBar | Instance | `` | `FloatingProgressBar` | `obj:createFloatingProgressBar()` |
| createScreenLabelD | Instance | `text: string, time: number` | `lightuserdata` | `obj:createScreenLabelD(text, time)` |
| showCharacterStatsWindow | Instance | `` | `void` | `obj:showCharacterStatsWindow()` |
| closeCharacterStatsWindow | Instance | `` | `void` | `obj:closeCharacterStatsWindow()` |
| toggleStatsWindow | Instance | `` | `void` | `obj:toggleStatsWindow()` |
| toggleCharacterStatsWindowPermanent | Instance | `` | `void` | `obj:toggleCharacterStatsWindowPermanent()` |
| showInventory | Instance | `autoPosition: boolean` | `InventoryGUI` | `obj:showInventory(autoPosition)` |
| showTraderInventory | Instance | `` | `InventoryGUI` | `obj:showTraderInventory()` |
| showInventoryBuilding | Instance | `` | `InventoryGUI` | `obj:showInventoryBuilding()` |
| showInventoryNPC | Instance | `` | `InventoryGUI` | `obj:showInventoryNPC()` |
| closeInventory | Instance | `` | `void` | `obj:closeInventory()` |
| getInventoryWindow | Instance | `` | `InventoryGUI` | `obj:getInventoryWindow()` |
| hasInventoryWindowOpen | Instance | `` | `boolean` | `obj:hasInventoryWindowOpen()` |
| toggleInventoryWindowPermanent | Instance | `` | `void` | `obj:toggleInventoryWindowPermanent()` |
| getSelectedObject | Instance | `` | `void` | `obj:getSelectedObject()` |
| getSelectedPlayerCharacter | Instance | `` | `void` | `obj:getSelectedPlayerCharacter()` |
| showTradeWindow | Instance | `type: integer` | `void` | `obj:showTradeWindow(type)` |
| changeFontSize | Static / Instance | `` | `void` | `ForgottenGUI.changeFontSize()`<br>`obj:changeFontSize()` |
| destroy [1] | Instance | `label: ScreenLabelInterface` | `void` | `obj:destroy(label)` |
| destroy [2] | Instance | `datapanel: DatapanelGUI` | `void` | `obj:destroy(datapanel)` |
| destroy [3] | Instance | `win: GUIWindow` | `void` | `obj:destroy(win)` |
| changeMouseCursor [1] | Instance | `cursor: CursorType, player: hand, target: hand` | `void` | `obj:changeMouseCursor(cursor, player, target)` |
| changeMouseCursor [2] | Instance | `cursor: CursorType` | `void` | `obj:changeMouseCursor(cursor)` |
| createInventoryWindow [1] | Instance | `owner: hand, inventory: Inventory, layout: InventoryLayout, trader: RootObject` | `InventoryGUI` | `obj:createInventoryWindow(owner, inventory, layout, trader)` |
| createInventoryWindow [2] | Instance | `owner: hand, layout: InventoryLayout` | `InventoryGUI` | `obj:createInventoryWindow(owner, layout)` |

## FormationMover
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.FormationMover`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| me | `Character` | RW | `obj.me = <value>` |
| destination | `Vector3` | RW | `obj.destination = <value>` |
| direction | `Vector3` | RW | `obj.direction = <value>` |
| movementTarget | `unknown` | RW | `obj.movementTarget = <value>` |
| currentFormationID | `integer` | RW | `obj.currentFormationID = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| getSpeeds | Instance | `motion: Vector3, frameTime: number` | `number` | `obj:getSpeeds(motion, frameTime)` |
| setFormationMode | Instance | `` | `void` | `obj:setFormationMode()` |
| stopFormationMode | Instance | `` | `void` | `obj:stopFormationMode()` |

## FurnaceBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`
**Metatable:** `KenshiLua.FurnaceBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| active | `boolean` | RW | `obj.active = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| setupFromData | Instance | `` | `void` | `obj:setupFromData()` |
| getInputValueTotal | Instance | `` | `number` | `obj:getInputValueTotal()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| updateInputs | Instance | `rate: number` | `void` | `obj:updateInputs(rate)` |
| updateOutput | Instance | `rate: number` | `void` | `obj:updateOutput(rate)` |
| limitInputsOutputRate | Instance | `rate: number` | `boolean\|number` | `obj:limitInputsOutputRate(rate)` |

## FurnaceInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/FurnaceBuilding.h`
**Metatable:** `KenshiLua.FurnaceInventoryLayout`

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
| type | `integer` | RW | `obj.type = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isValid | Instance | `` | `boolean` | `obj:isValid()` |
| getSourceContainer | Instance | `` | `GameDataContainer` | `obj:getSourceContainer()` |
| destroy | Instance | `` | `void` | `obj:destroy()` |
| initialise | Instance | `t: integer, isActive: boolean` | `void` | `obj:initialise(t, isActive)` |
| loadFromFile | Instance | `path: string, _type: integer` | `boolean` | `obj:loadFromFile(path, _type)` |
| saveToFile | Instance | `path: string` | `boolean` | `obj:saveToFile(path)` |
| storeHandleList [1] | Instance | `handle: ogre_unordered_set<hand>::type, _name: string` | `void` | `obj:storeHandleList(handle, _name)` |
| storeHandleList [2] | Instance | `handle: lektor<hand>, _name: string` | `void` | `obj:storeHandleList(handle, _name)` |
| storeHandle | Instance | `name: string, redirect: boolean` | `void` | `obj:storeHandle(name, redirect)` |
| getHandle | Instance | `name: string` | `void` | `obj:getHandle(name)` |
| updateFrom | Instance | `mod: boolean` | `boolean` | `obj:updateFrom(mod)` |
| isValueActive | Instance | `v: string` | `boolean` | `obj:isValueActive(v)` |
| isRefActive | Instance | `v: string` | `boolean` | `obj:isRefActive(v)` |
| addFileName | Instance | `n: string, v: string, filestype: string, category: string, vis: boolean` | `void` | `obj:addFileName(n, v, filestype, category, vis)` |
| addString | Instance | `n: string, v: string, category: string, vis: boolean` | `void` | `obj:addString(n, v, category, vis)` |
| add [1] | Instance | `n: string, v: Vector3` | `void` | `obj:add(n, v)` |
| add [2] | Instance | `n: string, v: boolean, category: string, vis: boolean` | `void` | `obj:add(n, v, category, vis)` |
| add [3] | Instance | `n: string, v: number, category: string, vis: boolean, isSlider: boolean` | `void` | `obj:add(n, v, category, vis, isSlider)` |
| add [4] | Instance | `n: string, v: integer, category: string, vis: boolean` | `void` | `obj:add(n, v, category, vis)` |
| getGameDataReferenceObject | Instance | `list: string, id: string` | `GameDataReference` | `obj:getGameDataReferenceObject(list, id)` |
| addToList | Instance | `list: string, id: string, val: integer, val2: integer, val3: integer` | `void` | `obj:addToList(list, id, val, val2, val3)` |
| removeFromList [1] | Instance | `list: string, id: integer` | `void` | `obj:removeFromList(list, id)` |
| removeFromList [2] | Instance | `list: string, id: string` | `void` | `obj:removeFromList(list, id)` |
| findInList | Instance | `list: string, SID: string` | `boolean` | `obj:findInList(list, SID)` |
| clearList | Instance | `n: string` | `void` | `obj:clearList(n)` |
| clearEverything | Instance | `` | `void` | `obj:clearEverything()` |
| clearInstances | Instance | `` | `void` | `obj:clearInstances()` |
| getFromList | Instance | `n: string, index: integer` | `string` | `obj:getFromList(n, index)` |
| getFromList_random | Instance | `n: string` | `string` | `obj:getFromList_random(n)` |
| getListSize | Instance | `n: string` | `integer` | `obj:getListSize(n)` |
| listExists | Instance | `n: string` | `boolean` | `obj:listExists(n)` |
| listExistsAndNotEmpty | Instance | `n: string` | `boolean` | `obj:listExistsAndNotEmpty(n)` |
| getAllFromList | Instance | `n: string` | `void` | `obj:getAllFromList(n)` |
| getReferenceList | Instance | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceList(listname)` |
| getReferenceListIfExists | Instance | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:getReferenceListIfExists(listname)` |
| _getReferenceList_nonConst | Instance | `listname: string` | `Ogre::vector<GameDataReference>::type` | `obj:_getReferenceList_nonConst(listname)` |
| getFromListAsData | Instance | `n: string, index: integer, type: integer` | `GameData` | `obj:getFromListAsData(n, index, type)` |
| getValueFromList | Instance | `list: string, index: integer` | `void` | `obj:getValueFromList(list, index)` |
| deleteInstancedObject | Instance | `id: string, modIndex: integer` | `void` | `obj:deleteInstancedObject(id, modIndex)` |
| getNewID | Instance | `` | `integer` | `obj:getNewID()` |
| getColorVec | Instance | `name: string` | `Vector3` | `obj:getColorVec(name)` |
| addDeletedInstance | Instance | `instanceID: string` | `void` | `obj:addDeletedInstance(instanceID)` |

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
| objectType | `integer` | RW | `obj.objectType = <value>` |
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
| gamedataID | `unknown` | RW | `obj.gamedataID = <value>` |
| gamedataSID | `GameDataSIDMap` | RW | `obj.gamedataSID = <value>` |
| mainList | `ogre_unordered_set<GameData*>::type` | RW | `obj.mainList = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createNewData | Instance | `type: integer, forceID: string, name: string` | `GameData` | `obj:createNewData(type, forceID, name)` |
| getDataByName | Instance | `dataName: string, category: integer` | `GameData` | `obj:getDataByName(dataName, category)` |
| renameData | Instance | `n: string` | `void` | `obj:renameData(n)` |
| removeData | Instance | `` | `void` | `obj:removeData()` |
| removeDuplicatesOf | Instance | `` | `void` | `obj:removeDuplicatesOf()` |
| removeAllDataOfType | Instance | `type: integer` | `void` | `obj:removeAllDataOfType(type)` |
| clearInstances | Instance | `` | `void` | `obj:clearInstances()` |
| clearButDontDestroy | Instance | `` | `void` | `obj:clearButDontDestroy()` |
| clearButDontDestroyPlatoons | Instance | `` | `void` | `obj:clearButDontDestroyPlatoons()` |
| clearAndDestroy | Instance | `` | `void` | `obj:clearAndDestroy()` |
| getNewID | Instance | `` | `integer` | `obj:getNewID()` |
| destroyData | Instance | `` | `void` | `obj:destroyData()` |
| preLoadAllReferencePtrs | Instance | `` | `void` | `obj:preLoadAllReferencePtrs()` |
| clearAllReferencePtrs | Instance | `` | `void` | `obj:clearAllReferencePtrs()` |
| setName | Instance | `name: string` | `void` | `obj:setName(name)` |
| checkForDuplicates | Instance | `` | `void` | `obj:checkForDuplicates()` |
| addNewData | Instance | `dat: string` | `void` | `obj:addNewData(dat)` |
| getData | Instance | `sid: string, category: integer` | `GameData` | `obj:getData(sid, category)` |
| getDataOfType | Instance | `type: integer` | `void` | `obj:getDataOfType(type)` |
| _getAllData | Instance | `` | `void` | `obj:_getAllData()` |
| loadGameDataReturn | Instance | `file: string, isActive: boolean, readOnly: boolean, moreData: userdata` | `boolean` | `obj:loadGameDataReturn(file, isActive, readOnly, moreData)` |
| load | Instance | `filename: string, modName: string, modIndex: integer, moreData: userdata, keepDeletedInstances: boolean` | `boolean` | `obj:load(filename, modName, modIndex, moreData, keepDeletedInstances)` |
| save | Instance | `filename: string, moreData: userdata` | `boolean` | `obj:save(filename, moreData)` |
| flushKillList | Instance | `` | `void` | `obj:flushKillList()` |
| destroyHomelessData | Instance | `` | `void` | `obj:destroyHomelessData()` |
| findAllDataThatReferencesThis | Instance | `ofType: integer, listname: string` | `void` | `obj:findAllDataThatReferencesThis(ofType, listname)` |
| _addToKillList | Instance | `` | `void` | `obj:_addToKillList()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| initDataValues | Instance | `` | `void` | `obj:initDataValues()` |

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

## GameDataManager
**Header:** `extern/KenshiLib/Include/kenshi/GameDataManager.h`
**Metatable:** `KenshiLua.GameDataManager`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reloadGameData | Instance | `filename: string, isActive: boolean, _baseData: boolean` | `boolean` | `obj:reloadGameData(filename, isActive, _baseData)` |
| postProcessingTheDatas | Instance | `` | `void` | `obj:postProcessingTheDatas()` |
| getMapSector | Instance | `x: integer, y: integer` | `GameData` | `obj:getMapSector(x, y)` |
| updateDatasOfType | Instance | `type: integer, isMod: boolean` | `void` | `obj:updateDatasOfType(type, isMod)` |
| updateData | Instance | `isMod: boolean` | `void` | `obj:updateData(isMod)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getPtr | Instance | `` | `GameData` | `obj:getPtr()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | Instance | `` | `void` | `obj:reset()` |
| getStarvationTimeInHours | Instance | `` | `number` | `obj:getStarvationTimeInHours()` |
| save | Instance | `` | `void` | `obj:save()` |
| load | Instance | `` | `void` | `obj:load()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| generateNewInstanceID | Instance | `` | `void` | `obj:generateNewInstanceID()` |
| generateStateID | Instance | `type: integer` | `string` | `obj:generateStateID(type)` |
| createState | Instance | `type: integer` | `GameData` | `obj:createState(type)` |
| hasState | Instance | `type: integer` | `boolean` | `obj:hasState(type)` |
| getState | Instance | `type: integer` | `GameData` | `obj:getState(type)` |
| numStates | Instance | `` | `integer` | `obj:numStates()` |
| getPos | Instance | `` | `Vector3` | `obj:getPos()` |
| getRot | Instance | `` | `Quaternion` | `obj:getRot()` |
| getTheInstancesData | Instance | `` | `GameData` | `obj:getTheInstancesData()` |
| createFromSerialisedInstanceData | Instance | `id: string` | `void` | `obj:createFromSerialisedInstanceData(id)` |
| addState | Instance | `` | `void` | `obj:addState()` |
| getInstanceID | Instance | `` | `void` | `obj:getInstanceID()` |
| isValid | Instance | `` | `boolean` | `obj:isValid()` |

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
| guiDisplayObject | `unknown` | RW | `obj.guiDisplayObject = <value>` |
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
| availableModsByName | `AvailableModsMapBinding::MapType` | RW | `obj.availableModsByName = <value>` |
| availabelModsOrderedList | `lektor<ModInfo*>` | RW | `obj.availabelModsOrderedList = <value>` |
| updatePortraitsMap | `unknown` | RW | `obj.updatePortraitsMap = <value>` |
| dynamicDestroyBuildingsList | `lektor<hand>` | RW | `obj.dynamicDestroyBuildingsList = <value>` |
| destroyListTBM | `ogre_unordered_set<TownBuildingsManager*>::type` | RW | `obj.destroyListTBM = <value>` |
| killListPhase0 | `ogre_unordered_set<RootObject*>::type` | RW | `obj.killListPhase0 = <value>` |
| killListPhase1 | `unknown` | RW | `obj.killListPhase1 = <value>` |
| killListPhase2 | `KillListPhase2DequeBinding::DequeType` | RW | `obj.killListPhase2 = <value>` |
| nestBatcherKillList | `NestBatcherKillListDequeBinding::DequeType` | RW | `obj.nestBatcherKillList = <value>` |
| mainUpdateListRemovalQueue | `lektor<Character*>` | RW | `obj.mainUpdateListRemovalQueue = <value>` |
| charactersWithLights | `ogre_unordered_set<Character*>::type` | RW | `obj.charactersWithLights = <value>` |
| deathParade | `unknown` | RW | `obj.deathParade = <value>` |
| charUpdateListMain | `ogre_unordered_set<Character*>::type` | RW | `obj.charUpdateListMain = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| justLoadFactionRelations | Instance | `` | `void` | `obj:justLoadFactionRelations()` |
| startUpThreads | Instance | `` | `boolean` | `obj:startUpThreads()` |
| start | Instance | `rend: userdata` | `boolean` | `obj:start(rend)` |
| destroy [1] | Instance | `e: Ogre::MovableObject` | `void` | `obj:destroy(e)` |
| destroy [2] | Instance | `e: AttachedEntity` | `void` | `obj:destroy(e)` |
| destroy [3] | Instance | `b: TownBuildingsManager` | `void` | `obj:destroy(b)` |
| destroy [4] | Instance | `n: NestBatcher` | `void` | `obj:destroy(n)` |
| destroy [5] | Instance | `obj: RootObject, justUnloaded: boolean, debugInfo: char` | `boolean` | `obj:destroy(obj, justUnloaded, debugInfo)` |
| destroy [6] | Instance | `d: GameData` | `void` | `obj:destroy(d)` |
| resetGame | Instance | `` | `void` | `obj:resetGame()` |
| _clearAndDestroyGameWorldStuff | Instance | `` | `void` | `obj:_clearAndDestroyGameWorldStuff()` |
| initialisation | Instance | `` | `boolean` | `obj:initialisation()` |
| initialisationGameData | Instance | `` | `boolean` | `obj:initialisationGameData()` |
| dailyUpdates | Instance | `` | `void` | `obj:dailyUpdates()` |
| initialiseNewGameWorld | Instance | `` | `void` | `obj:initialiseNewGameWorld()` |
| errorToLogReleaseMode | Instance | `msg: string` | `void` | `obj:errorToLogReleaseMode(msg)` |
| errorD | Instance | `msg: string` | `void` | `obj:errorD(msg)` |
| logToSave | Instance | `msg: string` | `void` | `obj:logToSave(msg)` |
| log | Instance | `line: string` | `void` | `obj:log(line)` |
| logDebug [1] | Instance | `msg: string, logname: string` | `void` | `obj:logDebug(msg, logname)` |
| logDebug [2] | Instance | `line: string` | `void` | `obj:logDebug(line)` |
| dynamicDestroyBuilding | Instance | `` | `void` | `obj:dynamicDestroyBuilding()` |
| getFromDeathParade | Instance | `` | `Character` | `obj:getFromDeathParade()` |
| addPortraitUpdate | Instance | `` | `void` | `obj:addPortraitUpdate()` |
| removePortaitUpdate | Instance | `` | `void` | `obj:removePortaitUpdate()` |
| getModsListFromConfig | Instance | `` | `lektor<ModInfo*>` | `obj:getModsListFromConfig()` |
| getAllModsList | Instance | `` | `lektor<ModInfo*>` | `obj:getAllModsList()` |
| getModLeveldataFolder | Instance | `modName: string` | `string` | `obj:getModLeveldataFolder(modName)` |
| getObjectsWithinSphere | Instance | `spherePos: Vector3, radius: number, type: integer, maxNumber: integer` | `void` | `obj:getObjectsWithinSphere(spherePos, radius, type, maxNumber)` |
| getCharactersWithinSphere | Instance | `spherePos: Vector3, farRadius: number, nearRadius: number, always: number, maxFar: integer, maxNear: integer` | `void` | `obj:getCharactersWithinSphere(spherePos, farRadius, nearRadius, always, maxFar, maxNear)` |
| getObjectsWithinBox | Instance | `pos: Vector3, size: Vector3, rot: Quaternion, type: integer, maxNumber: integer` | `void` | `obj:getObjectsWithinBox(pos, size, rot, type, maxNumber)` |
| getCharacterUpdateList | Instance | `` | `ogre_unordered_set<Character*>::type` | `obj:getCharacterUpdateList()` |
| sysMessage | Instance | `` | `void` | `obj:sysMessage()` |
| sysMessageUrgent | Instance | `` | `void` | `obj:sysMessageUrgent()` |
| sysMessage_noDuplicates | Instance | `` | `void` | `obj:sysMessage_noDuplicates()` |
| getCollisionGroupType | Instance | `type: integer` | `integer` | `obj:getCollisionGroupType(type)` |
| getTimeFromStamp [1] | Instance | `stamp: TimeOfDay` | `TimeOfDay` | `obj:getTimeFromStamp(stamp)` |
| getTimeFromStamp [2] | Instance | `stamp: number` | `number` | `obj:getTimeFromStamp(stamp)` |
| getIsInKillList | Instance | `` | `boolean` | `obj:getIsInKillList()` |
| flushKillList | Instance | `` | `void` | `obj:flushKillList()` |
| allThreadQueuesAreClear | Instance | `` | `boolean` | `obj:allThreadQueuesAreClear()` |
| initBaseMods | Instance | `` | `void` | `obj:initBaseMods()` |
| initModsList | Instance | `` | `void` | `obj:initModsList()` |
| getModIndex | Instance | `modName: string` | `integer` | `obj:getModIndex(modName)` |
| buildingIntersectionTestCapsule | Instance | `pos: Vector3, radius: number, length: number` | `boolean` | `obj:buildingIntersectionTestCapsule(pos, radius, length)` |
| getLightLevel | Instance | `position: Vector3, floor: integer, inside: boolean` | `number` | `obj:getLightLevel(position, floor, inside)` |
| populateMapArea_nonPermanent | Instance | `howMany: integer, rePopulationMode: boolean` | `void` | `obj:populateMapArea_nonPermanent(howMany, rePopulationMode)` |
| findValidSpawnPos | Instance | `pos: Vector3, centerArea: Vector3` | `boolean` | `obj:findValidSpawnPos(pos, centerArea)` |
| togglePause | Instance | `on: boolean` | `void` | `obj:togglePause(on)` |
| getFrameSpeedMultiplier | Instance | `` | `number` | `obj:getFrameSpeedMultiplier()` |
| setFrameSpeedMultiplier | Instance | `m: number` | `void` | `obj:setFrameSpeedMultiplier(m)` |
| setGameSpeed | Instance | `speed: number, click: boolean` | `void` | `obj:setGameSpeed(speed, click)` |
| userPause | Instance | `p: boolean` | `void` | `obj:userPause(p)` |
| isPaused | Instance | `` | `boolean` | `obj:isPaused()` |
| getCameraCenter | Instance | `` | `Vector3` | `obj:getCameraCenter()` |
| getCameraPos | Instance | `` | `Vector3` | `obj:getCameraPos()` |
| fixNaNPosition | Instance | `pos: Vector3` | `boolean` | `obj:fixNaNPosition(pos)` |
| getWindSpeed | Instance | `pos: Vector3` | `number` | `obj:getWindSpeed(pos)` |
| isLoadingFromASaveGame | Instance | `` | `boolean` | `obj:isLoadingFromASaveGame()` |
| addToUpdateListMain | Instance | `` | `void` | `obj:addToUpdateListMain()` |
| removeFromUpdateListMain | Instance | `` | `void` | `obj:removeFromUpdateListMain()` |
| addToDeathParade | Instance | `` | `void` | `obj:addToDeathParade()` |
| removeFromDeathParade | Instance | `` | `boolean` | `obj:removeFromDeathParade()` |
| removeFromDeathParadeByPlatoon | Instance | `` | `void` | `obj:removeFromDeathParadeByPlatoon()` |
| hideContextMenu | Instance | `` | `void` | `obj:hideContextMenu()` |
| showPlayerAMessage_withLog | Instance | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage_withLog(message, queued)` |
| showPlayerAMessage | Instance | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessage(message, queued)` |
| showPlayerAMessageD | Instance | `message: string, queued: boolean` | `void` | `obj:showPlayerAMessageD(message, queued)` |
| playNotification | Instance | `sound: string` | `void` | `obj:playNotification(sound)` |
| mainLoop_GPUSensitiveStuff | Instance | `time: number` | `void` | `obj:mainLoop_GPUSensitiveStuff(time)` |
| clearPortaitsUpdate | Instance | `` | `void` | `obj:clearPortaitsUpdate()` |
| processSysMessages | Instance | `` | `void` | `obj:processSysMessages()` |
| destroyDeathParade | Instance | `` | `void` | `obj:destroyDeathParade()` |
| processKeys | Instance | `` | `void` | `obj:processKeys()` |
| processThreadMessages | Instance | `` | `void` | `obj:processThreadMessages()` |
| charsUpdate | Instance | `` | `void` | `obj:charsUpdate()` |
| charsUpdateUT | Instance | `` | `void` | `obj:charsUpdateUT()` |
| charsUpdatePaused | Instance | `` | `void` | `obj:charsUpdatePaused()` |
| charsUpdateDeathParade | Instance | `` | `void` | `obj:charsUpdateDeathParade()` |
| threadSafeRagdollUpdates | Instance | `` | `void` | `obj:threadSafeRagdollUpdates()` |
| AINonRenderThread | Instance | `` | `ThreadWannabe` | `obj:AINonRenderThread()` |
| processAttachmentsKillList | Instance | `` | `void` | `obj:processAttachmentsKillList()` |
| processKillList | Instance | `forceImmediate: boolean` | `void` | `obj:processKillList(forceImmediate)` |
| processUpdateRemovalList | Instance | `` | `void` | `obj:processUpdateRemovalList()` |
| loadAllPlatoons | Instance | `` | `void` | `obj:loadAllPlatoons()` |
| reCalculateFortificationInsideOutsideStateForAllCharacters | Instance | `` | `void` | `obj:reCalculateFortificationInsideOutsideStateForAllCharacters()` |
| getTimeStamp | Instance | `` | `number` | `obj:getTimeStamp()` |
| getTimeFromStamp_inGameHours | Instance | `stamp: number` | `number` | `obj:getTimeFromStamp_inGameHours(stamp)` |
| getTimeStamp_inGameHours | Instance | `` | `void` | `obj:getTimeStamp_inGameHours()` |
| getLengthOfHourInRealSeconds | Instance | `` | `number` | `obj:getLengthOfHourInRealSeconds()` |

## GameWorld::SysMessage
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`
**Parent Class:** [`GameWorld`](#gameworld)
**Metatable:** `KenshiLua.SysMessage`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| msg | `integer` | RW | `obj.msg = <value>` |
| target | `unknown` | RW | `obj.target = <value>` |
| from | `unknown` | RW | `obj.from = <value>` |
| on | `boolean` | RW | `obj.on = <value>` |
| number | `number` | RW | `obj.number = <value>` |
| data | `lightuserdata` | R | `obj.data` |

## GatewayBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GatewayBuilding.h`
**Metatable:** `KenshiLua.GatewayBuilding`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reAnnounceGateToPathfinder | Instance | `` | `void` | `obj:reAnnounceGateToPathfinder()` |
| postCreationPathfinderSetupStuff | Instance | `` | `void` | `obj:postCreationPathfinderSetupStuff()` |
| getPositionForWaypoint | Instance | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| getUseableStuff | Instance | `` | `UseableStuff` | `obj:getUseableStuff()` |
| isGate | Instance | `` | `GatewayBuilding` | `obj:isGate()` |
| isForSale | Instance | `` | `boolean` | `obj:isForSale()` |
| setup | Instance | `` | `void` | `obj:setup()` |
| getGateCodeAt | Instance | `p: Vector3` | `integer` | `obj:getGateCodeAt(p)` |
| getOutsideGateCode | Instance | `` | `integer` | `obj:getOutsideGateCode()` |
| separatesAreas | Instance | `` | `boolean` | `obj:separatesAreas()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isGear | Instance | `` | `Gear` | `obj:isGear()` |
| getLevel01 | Instance | `` | `number` | `obj:getLevel01()` |
| getLevel | Instance | `` | `integer` | `obj:getLevel()` |
| isAFactionUniform | Instance | `` | `Faction` | `obj:isAFactionUniform()` |
| _serialise | Instance | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _loadFromSerialise | Instance | `` | `void` | `obj:_loadFromSerialise()` |
| isPlayerCrafted | Instance | `` | `boolean` | `obj:isPlayerCrafted()` |
| setInventoryWeAreIn | Instance | `` | `void` | `obj:setInventoryWeAreIn()` |

## GeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`
**Metatable:** `KenshiLua.GeneratorBuilding`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getPowerOutput | Instance | `` | `number` | `obj:getPowerOutput()` |
| getFuelConsumptionRate | Instance | `` | `number` | `obj:getFuelConsumptionRate()` |

## GenericFixedInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.GenericFixedInventoryLayout`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setSize | Instance | `slotsW: integer, slotsH: integer` | `void` | `obj:setSize(slotsW, slotsH)` |

## GenericInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`
**Metatable:** `KenshiLua.GenericInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| arrangeButton | `MyGUI::Widget` | RW | `obj.arrangeButton = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setSize | Instance | `slotsW: integer, slotsH: integer, hasArrange: boolean, hasType: boolean` | `void` | `obj:setSize(slotsW, slotsH, hasArrange, hasType)` |

## Global
**Header:** `???`
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
| settings | `GameData` | R | `obj.settings` |
| APPEARANCE_RANDOM_DEVIATION | `number` | RW | `obj.APPEARANCE_RANDOM_DEVIATION = <value>` |
| fogDistMax | `number` | RW | `obj.fogDistMax = <value>` |
| fogDistMin | `number` | RW | `obj.fogDistMin = <value>` |

## GUIWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/GUIWindow.h`
**Metatable:** `KenshiLua.GUIWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| win | `MyGUI::Widget` | R | `obj.win` |
| selectedObject | `unknown` | RW | `obj.selectedObject = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| show | Instance | `_a1: boolean` | `void` | `obj:show(_a1)` |
| setPositionReal | Instance | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| setPosition | Instance | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| getWidth | Instance | `` | `integer` | `obj:getWidth()` |
| getHeight | Instance | `` | `integer` | `obj:getHeight()` |
| getWidthReal | Instance | `` | `number` | `obj:getWidthReal()` |
| getHeightReal | Instance | `` | `number` | `obj:getHeightReal()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| update | Instance | `` | `void` | `obj:update()` |
| autoChangeSelectedObject | Instance | `` | `void` | `obj:autoChangeSelectedObject()` |
| getWidget | Instance | `` | `MyGUI::Widget` | `obj:getWidget()` |
| resize | Instance | `w: integer, h: integer` | `void` | `obj:resize(w, h)` |

## Hand
**Header:** `extern/KenshiLib/Include/kenshi/util/hand.h`
**Metatable:** `KenshiLua.hand`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| toString | Instance | `` | `string` | `obj:toString()` |
| fromString | Instance | `str: string` | `void` | `obj:fromString(str)` |
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| getPlatoon | Instance | `` | `Platoon` | `obj:getPlatoon()` |
| getActivePlatoon | Instance | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getBuilding | Instance | `` | `Building` | `obj:getBuilding()` |
| getItem | Instance | `` | `Item` | `obj:getItem()` |
| getRootObject | Instance | `` | `RootObject` | `obj:getRootObject()` |
| getRootObjectBase | Instance | `` | `RootObjectBase` | `obj:getRootObjectBase()` |
| getTown | Instance | `` | `TownBase` | `obj:getTown()` |
| debugWhatHappenedToMe | Instance | `` | `string` | `obj:debugWhatHappenedToMe()` |
| setNull | Instance | `` | `void` | `obj:setNull()` |
| isNull | Instance | `` | `boolean` | `obj:isNull()` |
| isValid | Instance | `` | `boolean` | `obj:isValid()` |
| canCastToRootObject | Instance | `` | `boolean` | `obj:canCastToRootObject()` |
| squadMatch | Instance | `` | `boolean` | `obj:squadMatch()` |

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
| characterState | `integer` | RW | `obj.characterState = <value>` |
| lastState | `integer` | RW | `obj.lastState = <value>` |
| pathState | `integer` | RW | `obj.pathState = <value>` |
| handle | `unknown` | RW | `obj.handle = <value>` |
| collided | `unknown` | RW | `obj.collided = <value>` |
| sensoryData | `SensoryData` | RW | `obj.sensoryData = <value>` |
| resolveFlag | `integer` | RW | `obj.resolveFlag = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setPosition | Instance | `p: Vector3, key: integer` | `void` | `obj:setPosition(p, key)` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| setVelocity | Instance | `v: Vector3` | `void` | `obj:setVelocity(v)` |
| getVelocity | Instance | `` | `Vector3` | `obj:getVelocity()` |
| getWaypointDirection | Instance | `` | `Vector3` | `obj:getWaypointDirection()` |
| getDirectionMoved | Instance | `` | `Vector3` | `obj:getDirectionMoved()` |
| setWaterModifier | Instance | `m: number` | `void` | `obj:setWaterModifier(m)` |
| setManualMode | Instance | `on: boolean` | `void` | `obj:setManualMode(on)` |
| setDesiredSpeed | Instance | `speed: number` | `void` | `obj:setDesiredSpeed(speed)` |
| getState | Instance | `` | `integer` | `obj:getState()` |
| getPathState | Instance | `` | `integer` | `obj:getPathState()` |
| isOnNavmesh | Instance | `` | `boolean` | `obj:isOnNavmesh()` |
| getClosestPoint | Instance | `target: Vector3, max: number` | `Vector3` | `obj:getClosestPoint(target, max)` |
| requestPath | Instance | `goal: Vector3, priority: integer` | `void` | `obj:requestPath(goal, priority)` |
| clearPath | Instance | `` | `void` | `obj:clearPath()` |
| update | Instance | `time: number` | `void` | `obj:update(time)` |
| moveAlongPath | Instance | `time: number` | `boolean` | `obj:moveAlongPath(time)` |
| handleCollision | Instance | `` | `boolean` | `obj:handleCollision()` |
| invalidate | Instance | `rid: integer` | `void` | `obj:invalidate(rid)` |
| _getFaceKey | Instance | `` | `integer` | `obj:_getFaceKey()` |
| pullThroughVertex | Instance | `side: integer, index: integer` | `integer` | `obj:pullThroughVertex(side, index)` |
| updateNextEdge | Instance | `` | `integer` | `obj:updateNextEdge()` |
| resolveProblems | Instance | `` | `void` | `obj:resolveProblems()` |
| atGoal | Instance | `` | `boolean` | `obj:atGoal()` |
| getCollidedCharacter | Instance | `` | `void` | `obj:getCollidedCharacter()` |
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| calculateFuturePosition [1] | Instance | `d: number, out: hkVector4f, dir: hkVector4f, stopAtScreenEdge: boolean` | `integer` | `obj:calculateFuturePosition(d, out, dir, stopAtScreenEdge)` |
| calculateFuturePosition [2] | Instance | `distance: number` | `Vector3` | `obj:calculateFuturePosition(distance)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| blockAlloc | Instance | `_a1: integer` | `void` | `obj:blockAlloc(_a1)` |
| resetPeakMemoryStatistics | Instance | `` | `void` | `obj:resetPeakMemoryStatistics()` |
| getExtendedInterface | Instance | `` | `lightuserdata` | `obj:getExtendedInterface()` |

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

## hkTrait::TraitBool
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.TraitBool`

## hkVector4f
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkVector4f`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setZero | Instance | `` | `void` | `obj:setZero()` |
| zeroComponent | Instance | `i: integer` | `void` | `obj:zeroComponent(i)` |
| setInt24W | Instance | `value: integer` | `void` | `obj:setInt24W(value)` |
| getInt24W | Instance | `` | `integer` | `obj:getInt24W()` |
| getInt16W | Instance | `` | `integer` | `obj:getInt16W()` |
| setZero4 | Instance | `` | `void` | `obj:setZero4()` |
| normalize3 | Instance | `` | `void` | `obj:normalize3()` |
| getZero | Static / Instance | `` | `void` | `hkVector4f.getZero()`<br>`obj:getZero()` |
| set [1] | Instance | `a: number, b: number, c: number, d: number` | `void` | `obj:set(a, b, c, d)` |
| set [2] | Instance | `a: hkSimdFloat32, b: hkSimdFloat32, c: hkSimdFloat32, d: hkSimdFloat32` | `void` | `obj:set(a, b, c, d)` |
| setAll [1] | Instance | `a: number` | `void` | `obj:setAll(a)` |
| setAll [2] | Instance | `a: hkSimdFloat32` | `void` | `obj:setAll(a)` |
| add | Instance | `` | `void` | `obj:add()` |
| sub | Instance | `` | `void` | `obj:sub()` |
| mul [1] | Instance | `s: hkSimdFloat32` | `void` | `obj:mul(s)` |
| mul [2] | Instance | `a: hkVector4f` | `void` | `obj:mul(a)` |
| div | Instance | `` | `void` | `obj:div()` |
| setAdd [1] | Instance | `v0: hkVector4f, v1: hkSimdFloat32` | `void` | `obj:setAdd(v0, v1)` |
| setAdd [2] | Instance | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setAdd(v0, v1)` |
| setSub [1] | Instance | `v0: hkVector4f, v1: hkSimdFloat32` | `void` | `obj:setSub(v0, v1)` |
| setSub [2] | Instance | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setSub(v0, v1)` |
| setMul [1] | Instance | `r: hkSimdFloat32, v1: hkVector4f` | `void` | `obj:setMul(r, v1)` |
| setMul [2] | Instance | `v1: hkVector4f, r: hkSimdFloat32` | `void` | `obj:setMul(v1, r)` |
| setMul [3] | Instance | `v0: hkVector4f, v1: hkVector4f` | `void` | `obj:setMul(v0, v1)` |
| setDiv | Instance | `` | `void` | `obj:setDiv()` |
| addMul [1] | Instance | `r: hkSimdFloat32, v1: hkVector4f` | `void` | `obj:addMul(r, v1)` |
| addMul [2] | Instance | `v1: hkVector4f, r: hkSimdFloat32` | `void` | `obj:addMul(v1, r)` |
| addMul [3] | Instance | `x: hkVector4f, y: hkVector4f` | `void` | `obj:addMul(x, y)` |
| setAddMul [1] | Instance | `a: hkVector4f, b: hkVector4f, r: hkSimdFloat32` | `void` | `obj:setAddMul(a, b, r)` |
| setAddMul [2] | Instance | `a: hkVector4f, x: hkVector4f, y: hkVector4f` | `void` | `obj:setAddMul(a, x, y)` |
| subMul [1] | Instance | `r: hkSimdFloat32, a: hkVector4f` | `void` | `obj:subMul(r, a)` |
| subMul [2] | Instance | `v1: hkVector4f, r: hkSimdFloat32` | `void` | `obj:subMul(v1, r)` |
| subMul [3] | Instance | `x: hkVector4f, y: hkVector4f` | `void` | `obj:subMul(x, y)` |
| setSubMul [1] | Instance | `a: hkVector4f, b: hkVector4f, r: hkSimdFloat32` | `void` | `obj:setSubMul(a, b, r)` |
| setSubMul [2] | Instance | `a: hkVector4f, x: hkVector4f, y: hkVector4f` | `void` | `obj:setSubMul(a, x, y)` |
| setCross | Instance | `` | `void` | `obj:setCross()` |
| setXYZ_W [1] | Instance | `xyz: hkVector4f, w: hkSimdFloat32` | `void` | `obj:setXYZ_W(xyz, w)` |
| setXYZ_W [2] | Instance | `xyz: hkVector4f, w: hkVector4f` | `void` | `obj:setXYZ_W(xyz, w)` |
| setW [1] | Instance | `w: hkSimdFloat32` | `void` | `obj:setW(w)` |
| setW [2] | Instance | `w: hkVector4f` | `void` | `obj:setW(w)` |
| setXYZ [1] | Instance | `v: number` | `void` | `obj:setXYZ(v)` |
| setXYZ [2] | Instance | `xyz: hkVector4f` | `void` | `obj:setXYZ(xyz)` |
| setXYZ_0 | Instance | `` | `void` | `obj:setXYZ_0()` |

## hkVector4fComparison
**Header:** `extern/KenshiLib/Include/kenshi/Havok.h`
**Metatable:** `KenshiLua.hkVector4fComparison`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getIndexOfLastComponentSet | Instance | `` | `integer` | `obj:getIndexOfLastComponentSet()` |
| getIndexOfFirstComponentSet | Instance | `` | `integer` | `obj:getIndexOfFirstComponentSet()` |
| allAreSet | Instance | `` | `integer` | `obj:allAreSet()` |

## ImportGameMenu
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`
**Metatable:** `KenshiLua.ImportGameMenu`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| newGameOptions | `NewGameOptionsWindow` | RW | `obj.newGameOptions = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| select | Instance | `index: integer` | `void` | `obj:select(index)` |

## InputHandler
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`
**Metatable:** `KenshiLua.InputHandler`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| keyboard | `lightuserdata` | RW | `obj.keyboard = <value>` |
| controlEnabled | `boolean` | RW | `obj.controlEnabled = <value>` |
| gameMode | `integer` | RW | `obj.gameMode = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getKeyUTF8 | Instance | `key: integer` | `string` | `obj:getKeyUTF8(key)` |
| parseKey | Instance | `s: string` | `integer` | `obj:parseKey(s)` |
| getCommand | Instance | `s: string` | `lightuserdata` | `obj:getCommand(s)` |
| keyDownEvent | Instance | `key: integer` | `void` | `obj:keyDownEvent(key)` |
| keyUpEvent | Instance | `key: integer` | `void` | `obj:keyUpEvent(key)` |
| clearMessages | Instance | `` | `void` | `obj:clearMessages()` |
| initialise | Instance | `` | `void` | `obj:initialise()` |
| bind | Instance | `name: string, key: integer` | `void` | `obj:bind(name, key)` |
| unbindAll | Instance | `` | `void` | `obj:unbindAll()` |
| isKeyState | Instance | `command: string` | `boolean` | `obj:isKeyState(command)` |
| getMode | Instance | `command: string` | `integer` | `obj:getMode(command)` |
| sendEvent | Instance | `name: string` | `void` | `obj:sendEvent(name)` |
| loadConfig | Instance | `` | `void` | `obj:loadConfig()` |
| saveConfig | Instance | `` | `void` | `obj:saveConfig()` |
| keyString | Instance | `key: integer, translated: boolean` | `string` | `obj:keyString(key, translated)` |
| addCommand [1] | Instance | `name: string, value: integer, key: integer, alt: integer, masks: Masks, mode: GameMode` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| addCommand [2] | Instance | `name: string, value: boolean, key: integer, alt: integer, masks: Masks, mode: GameMode` | `void` | `obj:addCommand(name, value, key, alt, masks, mode)` |
| unbind [1] | Instance | `code: integer, mode: GameMode` | `void` | `obj:unbind(code, mode)` |
| unbind [2] | Instance | `cmd: string` | `void` | `obj:unbind(cmd)` |
| isBound [1] | Instance | `command: string` | `boolean` | `obj:isBound(command)` |
| isBound [2] | Instance | `key: integer` | `boolean` | `obj:isBound(key)` |
| getBoundKeys | Instance | `command: string` | `integer` | `obj:getBoundKeys(command)` |
| getBoundCommand | Instance | `key: integer, mode: integer` | `string` | `obj:getBoundCommand(key, mode)` |

## InputHandler::Command
**Header:** `extern/KenshiLib/Include/kenshi/InputHandler.h`
**Parent Class:** [`InputHandler`](#inputhandler)
**Metatable:** `KenshiLua.InputHandler_Command`

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| assign | Instance | `id: string` | `void` | `obj:assign(id)` |
| clear | Instance | `` | `void` | `obj:clear()` |
| needsSaving | Instance | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| notifyChange | Instance | `` | `void` | `obj:notifyChange()` |
| hasChanges | Instance | `` | `boolean` | `obj:hasChanges()` |
| notifySaved | Instance | `mod: string` | `void` | `obj:notifySaved(mod)` |
| empty | Instance | `` | `boolean` | `obj:empty()` |
| getBaseIndex | Instance | `` | `integer` | `obj:getBaseIndex()` |
| getModIndex [1] | Static / Instance | `` | `integer` | `InstanceID.getModIndex()`<br>`obj:getModIndex()` |
| getModIndex [2] | Static / Instance | `s: string` | `integer` | `InstanceID.getModIndex(s)`<br>`obj:getModIndex(s)` |

## InteriorModeButtonWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/InteriorModeButtonWindow.h`
**Metatable:** `KenshiLua.InteriorModeButtonWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| exteriorsInvisible | `boolean` | RW | `obj.exteriorsInvisible = <value>` |
| interiorMode | `boolean` | RW | `obj.interiorMode = <value>` |
| dataEditWindow | `GameDataEditorWindow` | RW | `obj.dataEditWindow = <value>` |
| currentBuilding | `unknown` | RW | `obj.currentBuilding = <value>` |
| currentInterior | `string` | RW | `obj.currentInterior = <value>` |
| currentExterior | `string` | RW | `obj.currentExterior = <value>` |
| interiorModeButton | `lightuserdata` | R | `obj.interiorModeButton` |
| win | `lightuserdata` | R | `obj.win` |
| centerButton | `lightuserdata` | R | `obj.centerButton` |
| exteriorButton | `lightuserdata` | R | `obj.exteriorButton` |
| titleLabel | `lightuserdata` | R | `obj.titleLabel` |
| saveBut | `lightuserdata` | R | `obj.saveBut` |
| deleteBut | `lightuserdata` | R | `obj.deleteBut` |
| listbox | `lightuserdata` | R | `obj.listbox` |
| namebox | `lightuserdata` | R | `obj.namebox` |
| saveBut2 | `lightuserdata` | R | `obj.saveBut2` |
| deleteBut2 | `lightuserdata` | R | `obj.deleteBut2` |
| listbox2 | `lightuserdata` | R | `obj.listbox2` |
| namebox2 | `lightuserdata` | R | `obj.namebox2` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| toggleInteriorMode | Instance | `` | `void` | `obj:toggleInteriorMode()` |
| setVisible | Instance | `v: boolean` | `void` | `obj:setVisible(v)` |
| wantExteriorsInvisible | Instance | `` | `boolean` | `obj:wantExteriorsInvisible()` |
| setSelectedBuilding | Instance | `` | `void` | `obj:setSelectedBuilding()` |
| getSelectedBuilding | Instance | `` | `Building` | `obj:getSelectedBuilding()` |
| updateUsageNodes | Instance | `` | `boolean` | `obj:updateUsageNodes()` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| activateInteriorMode | Instance | `on: boolean` | `void` | `obj:activateInteriorMode(on)` |
| confirmDeleteInteriorLayout | Instance | `c: integer` | `void` | `obj:confirmDeleteInteriorLayout(c)` |
| confirmDeleteExteriorLayout | Instance | `c: integer` | `void` | `obj:confirmDeleteExteriorLayout(c)` |
| setInteriorLayout | Instance | `name: string` | `void` | `obj:setInteriorLayout(name)` |
| setExteriorLayout | Instance | `name: string` | `void` | `obj:setExteriorLayout(name)` |
| recheckOutsideFurniture | Instance | `` | `void` | `obj:recheckOutsideFurniture()` |
| wasTheInteriorLoadedFromASave | Static / Instance | `` | `boolean` | `InteriorModeButtonWindow.wasTheInteriorLoadedFromASave()`<br>`obj:wasTheInteriorLoadedFromASave()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clearAll | Instance | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAll(destroy, skipUnique)` |
| serialise | Instance | `` | `GameData` | `obj:serialise()` |
| notifyModified | Instance | `` | `void` | `obj:notifyModified()` |
| initialiseNewSection | Instance | `name: string, w: integer, h: integer, limitSlot: integer, equipCallbacks: boolean, isContainerSlot: boolean, enabled: boolean, limit: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit)` |
| resizeSection | Instance | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resizeSection(w, h, clearContent)` |
| removeAllSections | Instance | `` | `void` | `obj:removeAllSections()` |
| getSection | Instance | `name: string` | `InventorySection` | `obj:getSection(name)` |
| getSectionOfType | Instance | `type: integer` | `InventorySection` | `obj:getSectionOfType(type)` |
| getCallbackCharacter | Instance | `` | `Character` | `obj:getCallbackCharacter()` |
| addItem | Instance | `quantity: integer, dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:addItem(quantity, dropOnFail, destroyOnFail)` |
| tryAddItem | Instance | `quantity: integer` | `boolean` | `obj:tryAddItem(quantity)` |
| hasRoomForItem | Instance | `` | `boolean` | `obj:hasRoomForItem()` |
| removeItemDontDestroy_returnsItem | Instance | `howmany: integer, returnCopyIfSomeLeft: boolean` | `Item` | `obj:removeItemDontDestroy_returnsItem(howmany, returnCopyIfSomeLeft)` |
| removeItemAutoDestroy | Instance | `howmany: integer` | `boolean` | `obj:removeItemAutoDestroy(howmany)` |
| dropItem | Instance | `` | `void` | `obj:dropItem()` |
| transferMouseItem | Instance | `` | `boolean` | `obj:transferMouseItem()` |
| countItems | Instance | `` | `integer` | `obj:countItems()` |
| getItem | Instance | `` | `Item` | `obj:getItem()` |
| hasItemType | Instance | `item: integer, skipEquipped: boolean` | `boolean` | `obj:hasItemType(item, skipEquipped)` |
| hasStolenItems | Instance | `` | `boolean` | `obj:hasStolenItems()` |
| getSecondaryWeapon | Instance | `` | `Weapon` | `obj:getSecondaryWeapon()` |
| getPrimaryWeapon | Instance | `` | `Weapon` | `obj:getPrimaryWeapon()` |
| takeOneItemOnly | Instance | `` | `Item` | `obj:takeOneItemOnly()` |
| deathCheck | Instance | `` | `boolean` | `obj:deathCheck()` |
| hasItemFunction | Instance | `type: integer` | `boolean` | `obj:hasItemFunction(type)` |
| getBestItemWithFunction | Instance | `type: integer` | `Item` | `obj:getBestItemWithFunction(type)` |
| getBestFoodItem | Instance | `` | `Item` | `obj:getBestFoodItem()` |
| getNumFoodItems | Instance | `` | `integer` | `obj:getNumFoodItems()` |
| _getBestFoodItem | Instance | `type: integer` | `Item` | `obj:_getBestFoodItem(type)` |
| _getNumFoodItems | Instance | `type: integer` | `integer` | `obj:_getNumFoodItems(type)` |
| hasWeaponEquipped | Instance | `` | `boolean` | `obj:hasWeaponEquipped()` |
| equipItem | Instance | `` | `boolean` | `obj:equipItem()` |
| isAContainer | Instance | `` | `boolean` | `obj:isAContainer()` |
| getOwner | Instance | `` | `RootObject` | `obj:getOwner()` |
| isEmpty | Instance | `` | `boolean` | `obj:isEmpty()` |
| recalculateTotalWeight | Instance | `` | `void` | `obj:recalculateTotalWeight()` |
| getTotalWeight | Instance | `` | `number` | `obj:getTotalWeight()` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| takeMoney | Instance | `val: integer` | `void` | `obj:takeMoney(val)` |
| buyItem | Instance | `` | `Item` | `obj:buyItem()` |
| getInventoryGUI | Instance | `` | `InventoryGUI` | `obj:getInventoryGUI()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| _sectionAddItemCallback | Instance | `` | `void` | `obj:_sectionAddItemCallback()` |
| _sectionUpdateItemCallback | Instance | `_a2: integer` | `void` | `obj:_sectionUpdateItemCallback(_a2)` |
| _sectionRemoveItemCallback | Instance | `` | `void` | `obj:_sectionRemoveItemCallback()` |
| refreshGui | Instance | `` | `void` | `obj:refreshGui()` |
| autoArrange | Instance | `` | `void` | `obj:autoArrange()` |
| getCallbackObject | Instance | `` | `RootObject` | `obj:getCallbackObject()` |
| _addToList | Instance | `` | `void` | `obj:_addToList()` |
| _removeFromList | Instance | `checkEverything: boolean` | `void` | `obj:_removeFromList(checkEverything)` |
| getHandle | Instance | `` | `void` | `obj:getHandle()` |
| loadFrom [1] | Instance | `container: GameDataContainer, inventoryState: GameData` | `void` | `obj:loadFrom(container, inventoryState)` |
| loadFrom [2] | Instance | `state: GameSaveState` | `void` | `obj:loadFrom(state)` |
| fillFromVendorList [1] | Instance | `vendorData: GameData, f: Faction` | `void` | `obj:fillFromVendorList(vendorData, f)` |
| fillFromVendorList [2] | Instance | `vendorlistList: lektor<GameData*>, f: Faction` | `void` | `obj:fillFromVendorList(vendorlistList, f)` |
| getAllSectionsOfType | Instance | `type: integer` | `void` | `obj:getAllSectionsOfType(type)` |
| getAllSections | Instance | `` | `lektor<InventorySection*>` | `obj:getAllSections()` |
| getExcessLoot | Instance | `justAsking: boolean` | `boolean` | `obj:getExcessLoot(justAsking)` |
| getResourceItems | Instance | `buildingMatsToo: boolean` | `void` | `obj:getResourceItems(buildingMatsToo)` |
| getNumItems [1] | Instance | `itemType: GameData` | `integer` | `obj:getNumItems(itemType)` |
| getNumItems [2] | Instance | `` | `integer` | `obj:getNumItems()` |
| hasItem [1] | Instance | `item: GameData, quantity: integer` | `boolean` | `obj:hasItem(item, quantity)` |
| hasItem [2] | Instance | `item: Item` | `boolean` | `obj:hasItem(item)` |
| getAllStolenItems | Instance | `includeUnknown: boolean` | `void` | `obj:getAllStolenItems(includeUnknown)` |
| getAllItemsOfType | Instance | `ty: integer, skipEquipped: boolean` | `void` | `obj:getAllItemsOfType(ty, skipEquipped)` |
| getEquippedWeapons | Instance | `` | `void` | `obj:getEquippedWeapons()` |
| getEquippedArmour | Instance | `` | `void` | `obj:getEquippedArmour()` |
| takeItem_EntireStack [1] | Instance | `what: Item` | `boolean` | `obj:takeItem_EntireStack(what)` |
| takeItem_EntireStack [2] | Instance | `item: GameData` | `Item` | `obj:takeItem_EntireStack(item)` |
| getAllItemsWithFunction | Instance | `type: integer` | `void` | `obj:getAllItemsWithFunction(type)` |
| getBestItemWithLowestCharges [1] | Instance | `what: GameData` | `Item` | `obj:getBestItemWithLowestCharges(what)` |
| getBestItemWithLowestCharges [2] | Instance | `type: ItemFunction` | `Item` | `obj:getBestItemWithLowestCharges(type)` |
| getAllItems | Instance | `` | `lektor<Item*>` | `obj:getAllItems()` |

## Inventory::HasRoomCache
**Header:** `extern/KenshiLib/Include/kenshi/Inventory.h`
**Parent Class:** [`Inventory`](#inventory)
**Metatable:** `KenshiLua.Inventory_HasRoomCache`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| modified | Instance | `` | `void` | `obj:modified()` |
| knowsAbout | Instance | `` | `boolean` | `obj:knowsAbout()` |
| hasRoomFor | Instance | `` | `boolean` | `obj:hasRoomFor()` |
| remember | Instance | `state: boolean` | `void` | `obj:remember(state)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| setPositionReal | Instance | `x: number, y: number` | `void` | `obj:setPositionReal(x, y)` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| showBackpack | Instance | `on: boolean` | `void` | `obj:showBackpack(on)` |
| getBackpack | Instance | `` | `ContainerItem` | `obj:getBackpack()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| hasSameOwner | Instance | `` | `boolean` | `obj:hasSameOwner()` |
| getCallbackCharacter | Instance | `` | `Character` | `obj:getCallbackCharacter()` |
| getCallbackObject | Instance | `` | `RootObject` | `obj:getCallbackObject()` |
| getSelectedItem | Instance | `sectionName: string` | `Item` | `obj:getSelectedItem(sectionName)` |
| stealingGUIInfoUpdate | Instance | `` | `void` | `obj:stealingGUIInfoUpdate()` |
| pickupItemToMouse | Instance | `sectionName: string` | `boolean` | `obj:pickupItemToMouse(sectionName)` |
| getMouseItem | Instance | `` | `Item` | `obj:getMouseItem()` |
| takeCertainAmountFrom | Instance | `amount: integer` | `Item` | `obj:takeCertainAmountFrom(amount)` |
| RClickAutoTrade | Instance | `invSectionName: string, x: integer, y: integer, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTrade(invSectionName, x, y, thieveryChecks, first)` |
| RClickAutoTradeAll | Instance | `invSectionName: string, x: integer, y: integer, thieveryChecks: boolean, first: boolean` | `integer` | `obj:RClickAutoTradeAll(invSectionName, x, y, thieveryChecks, first)` |
| isTradingForMoney | Instance | `` | `boolean` | `obj:isTradingForMoney()` |
| isStealing | Instance | `` | `boolean` | `obj:isStealing()` |
| isWithinRangeToTrade | Instance | `stealing: boolean` | `boolean` | `obj:isWithinRangeToTrade(stealing)` |
| setItemToPlayerPortrait | Instance | `` | `boolean` | `obj:setItemToPlayerPortrait()` |
| playSound | Instance | `eventId: string` | `void` | `obj:playSound(eventId)` |
| fencingConfirmationCallback | Instance | `b: integer` | `void` | `obj:fencingConfirmationCallback(b)` |
| getPlayerTradeCharacter | Instance | `` | `RootObject` | `obj:getPlayerTradeCharacter()` |
| refreshAllSections | Instance | `` | `void` | `obj:refreshAllSections()` |
| updateDatapanel | Instance | `` | `void` | `obj:updateDatapanel()` |
| rightClickAutoEquipping | Instance | `` | `void` | `obj:rightClickAutoEquipping()` |
| tryToEquip | Instance | `replace: boolean` | `boolean` | `obj:tryToEquip(replace)` |
| returnItem | Instance | `sectionName: string` | `void` | `obj:returnItem(sectionName)` |
| hasMouse | Instance | `` | `boolean` | `obj:hasMouse()` |
| getSectionWithMouseLocal | Instance | `` | `string` | `obj:getSectionWithMouseLocal()` |
| getSlotWithMouse | Instance | `` | `void` | `obj:getSlotWithMouse()` |
| setTradingTown | Static / Instance | `` | `void` | `InventoryGUI.setTradingTown()`<br>`obj:setTradingTown()` |
| getTradingTown | Static / Instance | `` | `Town` | `InventoryGUI.getTradingTown()`<br>`obj:getTradingTown()` |
| clearTradePartners | Static / Instance | `` | `void` | `InventoryGUI.clearTradePartners()`<br>`obj:clearTradePartners()` |
| getNPCTrader | Static / Instance | `` | `Character` | `InventoryGUI.getNPCTrader()`<br>`obj:getNPCTrader()` |
| isTradingForMoney_static | Static / Instance | `` | `RootObject` | `InventoryGUI.isTradingForMoney_static()`<br>`obj:isTradingForMoney_static()` |
| isTradingAndStealing_static | Static / Instance | `` | `RootObject` | `InventoryGUI.isTradingAndStealing_static()`<br>`obj:isTradingAndStealing_static()` |
| getTraderPriceMultiplier | Static / Instance | `` | `number` | `InventoryGUI.getTraderPriceMultiplier()`<br>`obj:getTraderPriceMultiplier()` |
| canDropMouseItemWithoutPaying | Static / Instance | `` | `boolean` | `InventoryGUI.canDropMouseItemWithoutPaying()`<br>`obj:canDropMouseItemWithoutPaying()` |
| removeTradePartner | Static / Instance | `` | `void` | `InventoryGUI.removeTradePartner()`<br>`obj:removeTradePartner()` |
| addTradePartner | Static / Instance | `` | `void` | `InventoryGUI.addTradePartner()`<br>`obj:addTradePartner()` |
| lockedItemCheck | Static / Instance | `` | `boolean` | `InventoryGUI.lockedItemCheck()`<br>`obj:lockedItemCheck()` |
| refreshSection [1] | Instance | `section: InventorySection` | `void` | `obj:refreshSection(section)` |
| refreshSection [2] | Instance | `` | `void` | `obj:refreshSection()` |
| getSection [1] | Instance | `sectionName: string` | `InventorySection` | `obj:getSection(sectionName)` |
| getSection [2] | Instance | `sect: InventorySectionGUI` | `InventorySection` | `obj:getSection(sect)` |
| makeIconForItem | Static / Instance | `` | `InventoryIcon` | `InventoryGUI.makeIconForItem()`<br>`obj:makeIconForItem()` |

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
| owner | `unknown` | RW | `obj.owner = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isValid | Instance | `` | `boolean` | `obj:isValid()` |

## InventoryGUI::TradeResult
**Header:** `extern/KenshiLib/Include/kenshi/gui/CharacterTradingWindow.h`
**Parent Class:** [`InventoryGUI`](#inventorygui)
**Metatable:** `KenshiLua.TradeResult`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | `integer` | RW | `obj.value = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| showMessage | Instance | `` | `void` | `obj:showMessage()` |
| ShowMessage | Static / Instance | `` | `void` | `InventoryGUI::TradeResult.ShowMessage()`<br>`obj:ShowMessage()` |

## InventoryIcon
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.InventoryIcon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| item | `Item` | RW | `obj.item = <value>` |
| image | `lightuserdata` | R | `obj.image` |
| quantityText | `lightuserdata` | R | `obj.quantityText` |
| chargesProgress | `lightuserdata` | R | `obj.chargesProgress` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| getWidget | Instance | `` | `lightuserdata` | `obj:getWidget()` |
| setPosition | Instance | `left: integer, top: integer` | `void` | `obj:setPosition(left, top)` |
| getSize | Instance | `` | `integer` | `obj:getSize()` |
| createIconImage | Static / Instance | `` | `void` | `InventoryIcon.createIconImage()`<br>`obj:createIconImage()` |
| getItemSize | Static / Instance | `` | `integer` | `InventoryIcon.getItemSize()`<br>`obj:getItemSize()` |
| getItemPosition | Static / Instance | `` | `integer` | `InventoryIcon.getItemPosition()`<br>`obj:getItemPosition()` |

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
| slotType | `integer` | RW | `obj.slotType = <value>` |
| originalFullChargeAmount | `number` | RW | `obj.originalFullChargeAmount = <value>` |
| chargesLeft | `number` | RW | `obj.chargesLeft = <value>` |
| quality | `number` | RW | `obj.quality = <value>` |
| weight | `number` | RW | `obj.weight = <value>` |
| itemFunction | `integer` | RW | `obj.itemFunction = <value>` |
| isTradeItem | `boolean` | RW | `obj.isTradeItem = <value>` |
| isEquipped | `boolean` | RW | `obj.isEquipped = <value>` |
| isUnique | `boolean` | RW | `obj.isUnique = <value>` |
| quantity | `integer` | RW | `obj.quantity = <value>` |
| itemWidth | `integer` | RW | `obj.itemWidth = <value>` |
| itemHeight | `integer` | RW | `obj.itemHeight = <value>` |
| deathItem | `boolean` | RW | `obj.deathItem = <value>` |
| objectType | `integer` | RW | `obj.objectType = <value>` |
| properOwner | `unknown` | RW | `obj.properOwner = <value>` |
| _whosInventoryWeAreIn | `unknown` | RW | `obj._whosInventoryWeAreIn = <value>` |
| _isResearchArtifact | `boolean` | RW | `obj._isResearchArtifact = <value>` |
| itemGroup | `lightuserdata` | RW | `obj.itemGroup = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| deactivate | Instance | `` | `void` | `obj:deactivate()` |
| resetAfterCopy | Instance | `` | `void` | `obj:resetAfterCopy()` |
| resetCharges | Instance | `randomise: boolean` | `void` | `obj:resetCharges(randomise)` |
| getItemType | Instance | `` | `integer` | `obj:getItemType()` |
| getItemWeightSingle | Instance | `` | `number` | `obj:getItemWeightSingle()` |
| getItemWeight | Instance | `` | `number` | `obj:getItemWeight()` |
| _serialise | Instance | `_a2: integer` | `GameData` | `obj:_serialise(_a2)` |
| _loadFromSerialise | Instance | `` | `void` | `obj:_loadFromSerialise()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| serialiseInInventory | Instance | `` | `GameData` | `obj:serialiseInInventory()` |
| loadFromSerialiseInInventory | Instance | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getAvgPrice | Instance | `` | `integer` | `obj:getAvgPrice()` |
| getValueSingle | Instance | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| getValueAll | Instance | `isPlayer: boolean` | `integer` | `obj:getValueAll(isPlayer)` |
| getMaxAffordableNum | Instance | `cashLimit: integer, isPlayer: boolean` | `integer` | `obj:getMaxAffordableNum(cashLimit, isPlayer)` |
| isStackable | Instance | `` | `integer` | `obj:isStackable()` |
| canStackWith | Instance | `` | `boolean` | `obj:canStackWith()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| isSameAs | Instance | `` | `boolean` | `obj:isSameAs()` |
| onGround | Instance | `` | `boolean` | `obj:onGround()` |
| isResearchArtifact | Instance | `` | `boolean` | `obj:isResearchArtifact()` |
| getLevel | Instance | `` | `integer` | `obj:getLevel()` |
| getItemSound | Instance | `` | `lightuserdata` | `obj:getItemSound()` |
| isStolen | Instance | `includeUnknown: boolean` | `boolean` | `obj:isStolen(includeUnknown)` |
| merchantPriceMod | Instance | `` | `number` | `obj:merchantPriceMod()` |
| activate [1] | Instance | `_a1: boolean, _a2: Vector3, _a3: Quaternion, _a4: boolean, _a5: integer, _a6: boolean` | `void` | `obj:activate(_a1, _a2, _a3, _a4, _a5, _a6)` |
| activate [2] | Instance | `_a1: boolean, _a2: integer, _a3: Quaternion, _a4: boolean, _a5: integer, _a6: boolean` | `void` | `obj:activate(_a1, _a2, _a3, _a4, _a5, _a6)` |
| getStolenItemGUIInfo | Instance | `` | `void` | `obj:getStolenItemGUIInfo()` |
| getBuyBackGUIInfo | Instance | `` | `void` | `obj:getBuyBackGUIInfo()` |
| serialise | Instance | `offsetPosToSubtract: userdata` | `void` | `obj:serialise(offsetPosToSubtract)` |
| getTooltipData1 | Instance | `` | `void` | `obj:getTooltipData1()` |
| getTooltipData2 | Instance | `` | `void` | `obj:getTooltipData2()` |
| addQuantity | Instance | `amount: integer` | `integer` | `obj:addQuantity(amount)` |
| getProperOwner | Instance | `` | `void` | `obj:getProperOwner()` |
| setProperOwner | Instance | `` | `void` | `obj:setProperOwner()` |
| getTooltipTradeValue | Instance | `` | `void` | `obj:getTooltipTradeValue()` |

## InventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.InventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| datapanel | `DatapanelGUI` | RW | `obj.datapanel = <value>` |
| dataPanelInfos | `GameDataCopyStandalone` | RW | `obj.dataPanelInfos = <value>` |
| window | `lightuserdata` | R | `obj.window` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWindow | Instance | `` | `lightuserdata` | `obj:getWindow()` |
| getWidget | Instance | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| getDatapanel | Instance | `` | `DatapanelGUI` | `obj:getDatapanel()` |
| setupDataPanelInfos | Instance | `name: string` | `void` | `obj:setupDataPanelInfos(name)` |
| createSectionGUI | Instance | `` | `InventorySectionGUI` | `obj:createSectionGUI()` |
| setSectionGUIDisabled | Instance | `sectionName: string, width: integer, height: integer` | `void` | `obj:setSectionGUIDisabled(sectionName, width, height)` |
| notifyCellSizeChanged | Static / Instance | `` | `void` | `InventoryLayout.notifyCellSizeChanged()`<br>`obj:notifyCellSizeChanged()` |

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
| limitedSlot | `integer` | RW | `obj.limitedSlot = <value>` |
| containerSlot | `boolean` | RW | `obj.containerSlot = <value>` |
| callbackObject | `RootObject` | RW | `obj.callbackObject = <value>` |
| parentInventory | `Inventory` | RW | `obj.parentInventory = <value>` |
| enabled | `boolean` | RW | `obj.enabled = <value>` |
| content | `Array2d<Item>` | R | `obj.content` |
| items | `Ogre::vector<InventorySection::SectionItem>::type` | R | `obj.items` |
| veryLimitedSlot | `lektor<GameData*>` | RW | `obj.veryLimitedSlot = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasRoomForItem | Instance | `quantity: integer` | `boolean` | `obj:hasRoomForItem(quantity)` |
| notifyModified | Instance | `` | `void` | `obj:notifyModified()` |
| addItem | Instance | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |
| _addItem | Instance | `x: integer, y: integer` | `void` | `obj:_addItem(x, y)` |
| getItemAt | Instance | `x: integer, y: integer` | `Item` | `obj:getItemAt(x, y)` |
| hasItemType | Instance | `type: integer` | `boolean` | `obj:hasItemType(type)` |
| autoArrange | Instance | `` | `void` | `obj:autoArrange()` |
| getNumItems | Instance | `` | `integer` | `obj:getNumItems()` |
| isEmpty | Instance | `` | `boolean` | `obj:isEmpty()` |
| removeItem | Instance | `` | `boolean` | `obj:removeItem()` |
| clearAllItems | Instance | `destroy: boolean, skipUnique: boolean` | `void` | `obj:clearAllItems(destroy, skipUnique)` |
| canItemGoHere | Instance | `x: integer, y: integer` | `boolean` | `obj:canItemGoHere(x, y)` |
| existsItemInFootprint | Instance | `x: integer, y: integer` | `boolean` | `obj:existsItemInFootprint(x, y)` |
| getLimitedSlot | Instance | `` | `integer` | `obj:getLimitedSlot()` |
| setupContainerData | Instance | `` | `void` | `obj:setupContainerData()` |
| applyStackingBonuses | Instance | `normalStackableAmount: integer` | `integer` | `obj:applyStackingBonuses(normalStackableAmount)` |
| recalculateTotalWeight | Instance | `` | `void` | `obj:recalculateTotalWeight()` |
| setWeightMultiplier | Instance | `mult: number` | `void` | `obj:setWeightMultiplier(mult)` |
| setStackingBonus | Instance | `minn: integer, mult: number` | `void` | `obj:setStackingBonus(minn, mult)` |
| getMaxStack | Instance | `` | `integer` | `obj:getMaxStack()` |
| addVeryLimitedSlot | Instance | `` | `void` | `obj:addVeryLimitedSlot()` |
| clearVeryLimitedSlot | Instance | `` | `void` | `obj:clearVeryLimitedSlot()` |
| getEnabled | Instance | `` | `boolean` | `obj:getEnabled()` |
| setEnabled | Instance | `value: boolean` | `void` | `obj:setEnabled(value)` |
| setItemsLimitCount | Instance | `value: integer` | `void` | `obj:setItemsLimitCount(value)` |
| getItemsLimitReached | Instance | `` | `boolean` | `obj:getItemsLimitReached()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| getFillPercentage | Instance | `` | `number` | `obj:getFillPercentage()` |
| getItem | Instance | `` | `Item` | `obj:getItem()` |
| setupEquipCallbacks | Instance | `` | `void` | `obj:setupEquipCallbacks()` |
| numItemsInFootprint | Instance | `x: integer, y: integer` | `integer` | `obj:numItemsInFootprint(x, y)` |
| resize | Instance | `w: integer, h: integer, clearContent: boolean` | `void` | `obj:resize(w, h, clearContent)` |
| hasItem [1] | Instance | `itemData: GameData` | `boolean` | `obj:hasItem(itemData)` |
| hasItem [2] | Instance | `item: Item` | `boolean` | `obj:hasItem(item)` |
| hasItem [1] | Instance | `itemData: GameData` | `boolean` | `obj:hasItem(itemData)` |
| hasItem [2] | Instance | `item: Item` | `boolean` | `obj:hasItem(item)` |
| isLimitedSlotCompatible [1] | Instance | `itemData: GameData` | `boolean` | `obj:isLimitedSlotCompatible(itemData)` |
| isLimitedSlotCompatible [2] | Instance | `item: Item` | `boolean` | `obj:isLimitedSlotCompatible(item)` |
| getValidInventoryPosition | Instance | `` | `boolean\|integer` | `obj:getValidInventoryPosition()` |
| getAllItemsOfType [1] | Instance | `list: lektor<Item*>, item: Item` | `void` | `obj:getAllItemsOfType(list, item)` |
| getAllItemsOfType [2] | Instance | `list: lektor<Item*>, type: itemType` | `void` | `obj:getAllItemsOfType(list, type)` |
| getAllItemsOfName | Instance | `itemName: string` | `void` | `obj:getAllItemsOfName(itemName)` |
| findNearestPlaceForItem | Instance | `` | `boolean\|integer` | `obj:findNearestPlaceForItem()` |
| getItemsInFootprint [1] | Instance | `itemList: lektor<Item*>, itemWidth: integer, itemHeight: integer, x: integer, y: integer` | `integer` | `obj:getItemsInFootprint(itemList, itemWidth, itemHeight, x, y)` |
| getItemsInFootprint [2] | Instance | `out: lektor<Item*>, item: Item, x: integer, y: integer` | `integer` | `obj:getItemsInFootprint(out, item, x, y)` |

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
| widget | `lightuserdata` | R | `obj.widget` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| hasMouse | Instance | `` | `boolean` | `obj:hasMouse()` |
| getWidget | Instance | `` | `lightuserdata` | `obj:getWidget()` |
| setEnabled | Instance | `value: boolean` | `void` | `obj:setEnabled(value)` |
| refreshIcons | Instance | `` | `void` | `obj:refreshIcons()` |
| update | Instance | `` | `void` | `obj:update()` |

## InventoryTraderGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryTraderGUI.h`
**Metatable:** `KenshiLua.InventoryTraderGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| sectionWidth | `integer` | RW | `obj.sectionWidth = <value>` |
| sectionHeight | `integer` | RW | `obj.sectionHeight = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| getCallbackCharacter | Instance | `` | `Character` | `obj:getCallbackCharacter()` |
| getCallbackObject | Instance | `` | `RootObject` | `obj:getCallbackObject()` |
| refreshSection | Instance | `` | `void` | `obj:refreshSection()` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Item.h`
**Metatable:** `KenshiLua.Item`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| physicalShouldExist | `boolean` | RW | `obj.physicalShouldExist = <value>` |
| existAsBareWeapon | `boolean` | RW | `obj.existAsBareWeapon = <value>` |
| persistant | `unknown` | RW | `obj.persistant = <value>` |
| visible | `boolean` | RW | `obj.visible = <value>` |
| physical | `lightuserdata` | RW | `obj.physical = <value>` |
| _isPhysical | `boolean` | RW | `obj._isPhysical = <value>` |
| physicalEntity | `lightuserdata` | RW | `obj.physicalEntity = <value>` |
| creatingPhysical | `boolean` | RW | `obj.creatingPhysical = <value>` |
| fixedPhysicalPosition | `boolean` | RW | `obj.fixedPhysicalPosition = <value>` |
| useDynamicPhysics | `boolean` | RW | `obj.useDynamicPhysics = <value>` |
| loadingEntity | `lightuserdata` | RW | `obj.loadingEntity = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isGear | Instance | `` | `Gear` | `obj:isGear()` |
| getClassType | Instance | `` | `integer` | `obj:getClassType()` |
| resetAfterCopy | Instance | `` | `void` | `obj:resetAfterCopy()` |
| deactivate | Instance | `` | `void` | `obj:deactivate()` |
| setPositionRotation | Instance | `position: Vector3, rotation: Quaternion, fixedPosition: boolean` | `void` | `obj:setPositionRotation(position, rotation, fixedPosition)` |
| isCrossbow | Instance | `` | `Crossbow` | `obj:isCrossbow()` |
| isArmour | Instance | `` | `Armour` | `obj:isArmour()` |
| isWeapon | Instance | `` | `Weapon` | `obj:isWeapon()` |
| isLockedArmour | Instance | `` | `LockedArmour` | `obj:isLockedArmour()` |
| isAFactionUniform | Instance | `` | `Faction` | `obj:isAFactionUniform()` |
| isPhysical | Instance | `` | `boolean` | `obj:isPhysical()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| getModelName | Instance | `` | `string` | `obj:getModelName()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| hasIngredients | Instance | `` | `boolean` | `obj:hasIngredients()` |
| isGoodFood | Instance | `` | `boolean` | `obj:isGoodFood()` |
| getEntity | Instance | `` | `lightuserdata` | `obj:getEntity()` |
| getTimeout | Instance | `` | `void` | `obj:getTimeout()` |
| _serialise | Instance | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _loadFromSerialise | Instance | `` | `void` | `obj:_loadFromSerialise()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| serialiseInInventory | Instance | `` | `GameData` | `obj:serialiseInInventory()` |
| loadFromSerialiseInInventory | Instance | `` | `void` | `obj:loadFromSerialiseInInventory()` |
| getCraftTime | Instance | `` | `number` | `obj:getCraftTime()` |
| getCraftMaterialMult | Instance | `` | `number` | `obj:getCraftMaterialMult()` |
| getLevel | Instance | `` | `integer` | `obj:getLevel()` |
| destroyItemEntityCallback_Equipping | Instance | `` | `void` | `obj:destroyItemEntityCallback_Equipping()` |
| isPersistant | Instance | `` | `boolean` | `obj:isPersistant()` |
| persistantOwnerExists | Instance | `` | `boolean` | `obj:persistantOwnerExists()` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| loadUnloadCheck | Instance | `` | `void` | `obj:loadUnloadCheck()` |
| getInventoryWeAreIn | Instance | `` | `void` | `obj:getInventoryWeAreIn()` |
| setInventoryWeAreIn | Instance | `` | `void` | `obj:setInventoryWeAreIn()` |
| isFood | Instance | `` | `boolean` | `obj:isFood()` |
| activate | Instance | `createPhysical: boolean, bareWeapon: integer, rotation: Quaternion, fixedPosition: boolean, bareWeapon: integer, dynamicPhysics: boolean` | `void` | `obj:activate(createPhysical, bareWeapon, rotation, fixedPosition, bareWeapon, dynamicPhysics)` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| createItemEntityCallback_Equipping | Instance | `ent: userdata, node: userdata` | `void` | `obj:createItemEntityCallback_Equipping(ent, node)` |
| notifyTheftFrom [1] | Instance | `owner: hand` | `void` | `obj:notifyTheftFrom(owner)` |
| notifyTheftFrom [2] | Instance | `obj: RootObject` | `void` | `obj:notifyTheftFrom(obj)` |
| findProperOwner [1] | Instance | `obj: RootObject` | `hand` | `obj:findProperOwner(obj)` |
| findProperOwner [2] | Instance | `handle: hand` | `hand` | `obj:findProperOwner(handle)` |
| setPersistant [1] | Instance | `anchor: hand` | `void` | `obj:setPersistant(anchor)` |
| setPersistant [2] | Instance | `p: boolean` | `void` | `obj:setPersistant(p)` |
| itemEntityCreated | Instance | `ent: userdata` | `void` | `obj:itemEntityCreated(ent)` |

## iVector2
**Header:** `extern/KenshiLib/Include/kenshi/util/iVector2.h`
**Metatable:** `KenshiLua.iVector2`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| x | `integer` | RW | `obj.x = <value>` |
| y | `integer` | RW | `obj.y = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getLinearValue | Instance | `` | `integer` | `obj:getLinearValue()` |
| getAsString | Instance | `` | `string` | `obj:getAsString()` |

## KenshiLib::BinaryVersion
**Header:** `extern/KenshiLib/Include/kenshi/Kenshi.h`
**Metatable:** `KenshiLua.BinaryVersion`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| GetPlatform | Instance | `` | `integer` | `obj:GetPlatform()` |
| GetPlatformStr | Instance | `` | `void` | `obj:GetPlatformStr()` |
| GetBinaryName | Instance | `` | `void` | `obj:GetBinaryName()` |
| ToString | Instance | `` | `void` | `obj:ToString()` |
| GetVersion | Instance | `` | `void` | `obj:GetVersion()` |
| getPlatform | Instance | `` | `integer` | `obj:getPlatform()` |
| getPlatformStr | Instance | `` | `void` | `obj:getPlatformStr()` |
| getBinaryName | Instance | `` | `void` | `obj:getBinaryName()` |
| toString | Instance | `` | `void` | `obj:toString()` |
| getVersion | Instance | `` | `void` | `obj:getVersion()` |
| GetKenshiVersion | Static / Instance | `` | `void` | `KenshiLib::BinaryVersion.GetKenshiVersion()`<br>`obj:GetKenshiVersion()` |
| getKenshiVersion | Static / Instance | `` | `void` | `KenshiLib::BinaryVersion.getKenshiVersion()`<br>`obj:getKenshiVersion()` |
| new | Static / Instance | `` | `void` | `KenshiLib::BinaryVersion.new()`<br>`obj:new()` |

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
| selectedObject | `unknown` | RW | `obj.selectedObject = <value>` |
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
| editMapTitleWindow | `lightuserdata` | R | `obj.editMapTitleWindow` |
| factionTxt | `lightuserdata` | R | `obj.factionTxt` |
| altitudeTxt | `lightuserdata` | R | `obj.altitudeTxt` |
| activeModTxt | `lightuserdata` | R | `obj.activeModTxt` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| close | Instance | `` | `void` | `obj:close()` |
| update | Instance | `` | `void` | `obj:update()` |
| updateGizmo | Instance | `` | `boolean` | `obj:updateGizmo()` |
| levelEditMode | Instance | `on: boolean` | `void` | `obj:levelEditMode(on)` |
| isInteriorEditMode | Instance | `` | `boolean` | `obj:isInteriorEditMode()` |
| getActiveModIndex | Instance | `` | `integer` | `obj:getActiveModIndex()` |
| getActiveMod | Instance | `` | `string` | `obj:getActiveMod()` |
| isBaseActive | Instance | `` | `boolean` | `obj:isBaseActive()` |
| setEditSquad | Instance | `` | `void` | `obj:setEditSquad()` |
| repath | Instance | `` | `void` | `obj:repath()` |
| toggleSeedMode | Instance | `` | `void` | `obj:toggleSeedMode()` |
| clearSeedPoints | Instance | `` | `void` | `obj:clearSeedPoints()` |
| setSeedMode | Instance | `mode: integer` | `void` | `obj:setSeedMode(mode)` |
| toggleRoadEditor | Instance | `tab: integer` | `void` | `obj:toggleRoadEditor(tab)` |
| toggleFoliageRemoval | Instance | `` | `void` | `obj:toggleFoliageRemoval()` |
| clearChanges | Instance | `` | `boolean` | `obj:clearChanges()` |
| deleteDuplicateBuildings | Instance | `` | `integer` | `obj:deleteDuplicateBuildings()` |
| fixMountedBuildings | Instance | `` | `integer` | `obj:fixMountedBuildings()` |
| deleteAll | Instance | `confirmed: boolean` | `integer` | `obj:deleteAll(confirmed)` |
| adjustAltitudeSpeed | Instance | `s: number` | `void` | `obj:adjustAltitudeSpeed(s)` |
| fixInvalidInteriorFurnitureStates | Instance | `` | `integer` | `obj:fixInvalidInteriorFurnitureStates()` |
| fixBuildingFloorState | Instance | `` | `boolean` | `obj:fixBuildingFloorState()` |
| setSelectedObject | Instance | `` | `void` | `obj:setSelectedObject()` |
| updateRoadEditor | Instance | `` | `void` | `obj:updateRoadEditor()` |
| setRoadWidth | Instance | `` | `void` | `obj:setRoadWidth()` |
| setRoadHidden | Instance | `` | `void` | `obj:setRoadHidden()` |
| drawRoads | Instance | `` | `void` | `obj:drawRoads()` |
| eraseRoads | Instance | `` | `void` | `obj:eraseRoads()` |
| drawAllRoads | Instance | `` | `void` | `obj:drawAllRoads()` |
| projectRoads | Instance | `` | `void` | `obj:projectRoads()` |
| validateRoads | Instance | `` | `void` | `obj:validateRoads()` |
| createRoadMarker | Instance | `` | `void` | `obj:createRoadMarker()` |
| destroyRoadMaker | Instance | `` | `void` | `obj:destroyRoadMaker()` |
| updateFoliageRemoval | Instance | `` | `void` | `obj:updateFoliageRemoval()` |
| updateSeedEditor | Instance | `` | `void` | `obj:updateSeedEditor()` |
| deleteObject | Instance | `` | `void` | `obj:deleteObject()` |

## LevelEditor::FactionListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.FactionListWindow`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| itemSelected | Instance | `` | `void` | `obj:itemSelected()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| deselectItem | Instance | `` | `void` | `obj:deselectItem()` |
| selectItem | Instance | `` | `boolean` | `obj:selectItem()` |
| getSelectedItem | Instance | `` | `GameData` | `obj:getSelectedItem()` |
| itemSelected | Instance | `` | `void` | `obj:itemSelected()` |
| formatItem | Instance | `` | `string` | `obj:formatItem()` |
| listItemSelected | Instance | `_index: integer` | `void` | `obj:listItemSelected(_index)` |
| changeFilter | Instance | `` | `void` | `obj:changeFilter()` |

## LevelEditor::ItemListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.ItemListWindow`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| itemSelected | Instance | `` | `void` | `obj:itemSelected()` |

## LevelEditor::NpcListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.NpcListWindow`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| itemSelected | Instance | `` | `void` | `obj:itemSelected()` |

## LevelEditor::SquadListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.SquadListWindow`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| refresh | Instance | `` | `void` | `obj:refresh()` |
| itemSelected | Instance | `` | `void` | `obj:itemSelected()` |

## LevelEditor::TownListWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LevelEditor.h`
**Parent Class:** [`LevelEditor`](#leveleditor)
**Metatable:** `KenshiLua.TownListWindow`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| formatItem | Instance | `` | `string` | `obj:formatItem()` |

## LightBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/LightBuilding.h`
**Metatable:** `KenshiLua.LightBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mountedBuilding | `unknown` | RW | `obj.mountedBuilding = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| getMouseCursor | Instance | `` | `integer` | `obj:getMouseCursor()` |
| needPowerRightNow | Instance | `` | `boolean` | `obj:needPowerRightNow()` |
| getPositionMarker | Instance | `currentPosition: Vector3` | `Vector3` | `obj:getPositionMarker(currentPosition)` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| getMountedBuilding | Instance | `` | `void` | `obj:getMountedBuilding()` |
| setMountedBuilding | Instance | `` | `void` | `obj:setMountedBuilding()` |

## LimbsInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`
**Metatable:** `KenshiLua.LimbsInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| character | `Character` | RW | `obj.character = <value>` |

## ListScrollBar
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_ListScrollBar.h`
**Metatable:** `KenshiLua.ListScrollBar`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| disableEvents | `boolean` | RW | `obj.disableEvents = <value>` |
| mListName | `lightuserdata` | R | `obj.mListName` |
| mListValue | `lightuserdata` | R | `obj.mListValue` |
| mListIndex | `lightuserdata` | R | `obj.mListIndex` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setEnabled | Instance | `_a1: boolean` | `void` | `obj:setEnabled(_a1)` |
| initialiseOverride | Instance | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | Instance | `` | `void` | `obj:shutdownOverride()` |

## LoadingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadingWindow.h`
**Metatable:** `KenshiLua.LoadingWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentIndex | `integer` | RW | `obj.currentIndex = <value>` |
| currentTime | `number` | RW | `obj.currentTime = <value>` |
| loadingText | `lightuserdata` | R | `obj.loadingText` |
| messageText | `lightuserdata` | R | `obj.messageText` |
| backgroundImage | `lightuserdata` | R | `obj.backgroundImage` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reload | Instance | `` | `void` | `obj:reload()` |
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| show | Instance | `` | `void` | `obj:show()` |
| hide | Instance | `` | `void` | `obj:hide()` |
| frameEntered | Instance | `_frame: number` | `void` | `obj:frameEntered(_frame)` |
| setRandomBackground | Instance | `` | `void` | `obj:setRandomBackground()` |
| setRandomTip | Instance | `` | `void` | `obj:setRandomTip()` |
| getInstance | Static / Instance | `` | `LoadingWindow` | `LoadingWindow.getInstance()`<br>`obj:getInstance()` |

## LoadSaveWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/LoadSaveWindow.h`
**Metatable:** `KenshiLua.LoadSaveWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| list | `lightuserdata` | R | `obj.list` |
| infoPanel | `DatapanelGUI` | RW | `obj.infoPanel = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| select | Instance | `index: integer` | `void` | `obj:select(index)` |
| getWidget | Instance | `` | `lightuserdata` | `obj:getWidget()` |
| deleteSelectedSave | Instance | `mbResult: integer` | `void` | `obj:deleteSelectedSave(mbResult)` |
| addOption | Instance | `key: integer, check: string, label: string, caption: string` | `void` | `obj:addOption(key, check, label, caption)` |
| enableOption | Instance | `key: integer, enabled: boolean` | `void` | `obj:enableOption(key, enabled)` |
| getOptions | Instance | `` | `integer` | `obj:getOptions()` |

## LockedArmour
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.LockedArmour`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| lock | `lightuserdata` | R | `obj.lock` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isArmour | Instance | `` | `Armour` | `obj:isArmour()` |
| isLockedArmour | Instance | `` | `LockedArmour` | `obj:isLockedArmour()` |
| _serialise | Instance | `type: integer` | `GameData` | `obj:_serialise(type)` |
| _loadFromSerialise | Instance | `` | `void` | `obj:_loadFromSerialise()` |

## Logger
**Header:** `extern/KenshiLib/Include/kenshi/Logger.h`
**Metatable:** `KenshiLua.Logger`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| init | Instance | `` | `void` | `obj:init()` |
| close | Instance | `` | `void` | `obj:close()` |
| logMessage | Instance | `` | `void` | `obj:logMessage()` |
| logMessageDebug | Instance | `` | `void` | `obj:logMessageDebug()` |
| logHeader | Instance | `` | `void` | `obj:logHeader()` |

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
| portraitContextMenuTarget | `unknown` | RW | `obj.portraitContextMenuTarget = <value>` |
| portraitContextMenuTimer | `number` | RW | `obj.portraitContextMenuTimer = <value>` |
| portraitSelectedContextIndex | `integer` | RW | `obj.portraitSelectedContextIndex = <value>` |
| portraitsUpdating | `boolean` | RW | `obj.portraitsUpdating = <value>` |
| toolTip | `ToolTipFixed` | RW | `obj.toolTip = <value>` |
| pausePanel | `MyGUI::Widget` | R | `obj.pausePanel` |
| loadingPanel | `MyGUI::Widget` | R | `obj.loadingPanel` |
| datapanels | `MainBarDatapanelsMapBinding::MapType` | RW | `obj.datapanels = <value>` |
| portraits | `MainBarPortraitsMapBinding::MapType` | RW | `obj.portraits = <value>` |
| speedButtons | `SpeedButtonsFastArrayBinding::ArrayType` | RW | `obj.speedButtons = <value>` |
| tabPortraits | `TabPortraitsFastArrayBinding::ArrayType` | RW | `obj.tabPortraits = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| update | Instance | `` | `void` | `obj:update()` |
| speedChanged | Instance | `` | `void` | `obj:speedChanged()` |
| updateBountyPanelVisibility | Instance | `` | `void` | `obj:updateBountyPanelVisibility()` |
| setLevelEditMode | Instance | `on: boolean` | `void` | `obj:setLevelEditMode(on)` |
| setLevelEditInteriorMode | Instance | `interiorMode: boolean` | `void` | `obj:setLevelEditInteriorMode(interiorMode)` |
| pressedKey | Instance | `keycode: integer` | `void` | `obj:pressedKey(keycode)` |
| platoonUpdated | Instance | `charAdded: boolean` | `void` | `obj:platoonUpdated(charAdded)` |
| updatePotraitsPlatoon | Instance | `` | `void` | `obj:updatePotraitsPlatoon()` |
| updatePortraits | Instance | `` | `void` | `obj:updatePortraits()` |
| refreshPortraitTabs | Instance | `` | `void` | `obj:refreshPortraitTabs()` |
| updatePortraitSize | Instance | `` | `void` | `obj:updatePortraitSize()` |
| getPausePanel | Instance | `` | `MyGUI::Widget` | `obj:getPausePanel()` |
| getLoadingPanel | Instance | `` | `MyGUI::Widget` | `obj:getLoadingPanel()` |
| getMedicalPanel | Instance | `` | `lightuserdata` | `obj:getMedicalPanel()` |
| ordersPanelClear | Instance | `` | `void` | `obj:ordersPanelClear()` |
| getToolTip | Instance | `` | `ToolTip` | `obj:getToolTip()` |
| getDatapanel | Instance | `id: string` | `DatapanelGUI` | `obj:getDatapanel(id)` |
| setMessagePosition | Instance | `` | `void` | `obj:setMessagePosition()` |
| serialise | Instance | `` | `void` | `obj:serialise()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| setExtendInfoPanelEnabled | Instance | `enabled: boolean` | `void` | `obj:setExtendInfoPanelEnabled(enabled)` |
| _getWidget | Instance | `name: string` | `MyGUI::Widget` | `obj:_getWidget(name)` |
| autoChangeSelectedObject | Instance | `` | `void` | `obj:autoChangeSelectedObject()` |
| getPortrait [1] | Instance | `position: MyGUI::types::TPoint<int>` | `PortraitData` | `obj:getPortrait(position)` |
| getPortrait [2] | Instance | `character: hand` | `PortraitData` | `obj:getPortrait(character)` |
| updatePortrait | Instance | `` | `void` | `obj:updatePortrait()` |
| closeMapWindow | Instance | `` | `void` | `obj:closeMapWindow()` |
| toggleMapWindow | Instance | `` | `void` | `obj:toggleMapWindow()` |
| toggleFactionWindow | Instance | `` | `void` | `obj:toggleFactionWindow()` |
| toggleTechWindow | Instance | `` | `void` | `obj:toggleTechWindow()` |
| toggleCraftWindow | Instance | `` | `void` | `obj:toggleCraftWindow()` |
| toggleSquadWindow | Instance | `` | `void` | `obj:toggleSquadWindow()` |
| changeFloorButtonUp | Instance | `` | `void` | `obj:changeFloorButtonUp()` |
| changeFloorButtonDown | Instance | `` | `void` | `obj:changeFloorButtonDown()` |
| ordersPanelFill | Instance | `` | `void` | `obj:ordersPanelFill()` |
| getBuildingInventoryPosition | Instance | `` | `void` | `obj:getBuildingInventoryPosition()` |
| getTabPlatoonPortrait [1] | Instance | `tabIndex: integer` | `MainTabPortraitPlatoon` | `obj:getTabPlatoonPortrait(tabIndex)` |
| getTabPlatoonPortrait [2] | Instance | `platoon: ActivePlatoon` | `MainTabPortraitPlatoon` | `obj:getTabPlatoonPortrait(platoon)` |
| extendInfoPanel | Instance | `_a2: integer, _a3: integer, arg4: integer` | `void` | `obj:extendInfoPanel(_a2, _a3, arg4)` |
| toggleInventory | Instance | `` | `void` | `obj:toggleInventory()` |
| toggleStatsWindow | Instance | `` | `void` | `obj:toggleStatsWindow()` |
| toggleHelpWindow | Instance | `` | `void` | `obj:toggleHelpWindow()` |
| changeSpeed | Instance | `` | `void` | `obj:changeSpeed()` |
| buildButton | Instance | `` | `void` | `obj:buildButton()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addTab | Instance | `visible: boolean` | `void` | `obj:addTab(visible)` |
| detach | Instance | `` | `void` | `obj:detach()` |
| setFlash | Instance | `flash: boolean` | `void` | `obj:setFlash(flash)` |
| update | Instance | `` | `void` | `obj:update()` |

## MainthreadStateReaderT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.MainthreadStateReaderT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| swapMutex | `unknown` | RW | `obj.swapMutex = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateBackDataCheck | Instance | `` | `boolean` | `obj:updateBackDataCheck()` |
| getMainData | Instance | `` | `void` | `obj:getMainData()` |
| getBackData | Instance | `` | `void` | `obj:getBackData()` |

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
| researchCategoriesListBox | `lightuserdata` | R | `obj.researchCategoriesListBox` |
| availableList | `DatapanelGUI` | RW | `obj.availableList = <value>` |
| info | `DatapanelGUI` | RW | `obj.info = <value>` |
| info2 | `DatapanelGUI` | RW | `obj.info2 = <value>` |
| techCategory | `string` | RW | `obj.techCategory = <value>` |
| currentResearch | `GameData` | RW | `obj.currentResearch = <value>` |
| researchBenchMessage | `lightuserdata` | R | `obj.researchBenchMessage` |
| researchDescriptionUpdateRequest | `boolean` | RW | `obj.researchDescriptionUpdateRequest = <value>` |
| lastResearchRate | `number` | RW | `obj.lastResearchRate = <value>` |
| todoList | `lightuserdata` | R | `obj.todoList` |
| craftingQueue | `lightuserdata` | R | `obj.craftingQueue` |
| messagesTextBox | `lightuserdata` | R | `obj.messagesTextBox` |
| messagesUpdated | `boolean` | RW | `obj.messagesUpdated = <value>` |
| messagesMutex | `lightuserdata` | R | `obj.messagesMutex` |
| messagesPlayerColor | `string` | RW | `obj.messagesPlayerColor = <value>` |
| messagesNPCColor | `string` | RW | `obj.messagesNPCColor = <value>` |
| aiScreen | `DatapanelGUI` | RW | `obj.aiScreen = <value>` |
| aiToolTip | `ToolTip` | RW | `obj.aiToolTip = <value>` |
| toolTip | `ToolTip` | RW | `obj.toolTip = <value>` |
| window | `lightuserdata` | R | `obj.window` |
| tabs | `lightuserdata` | R | `obj.tabs` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| clear | Instance | `` | `void` | `obj:clear()` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setVisible | Instance | `on: boolean, tab: integer` | `void` | `obj:setVisible(on, tab)` |
| getCurrentTab | Instance | `` | `integer` | `obj:getCurrentTab()` |
| getTab | Instance | `index: integer` | `lightuserdata` | `obj:getTab(index)` |
| getWidget | Instance | `name: string` | `lightuserdata` | `obj:getWidget(name)` |
| refresh | Instance | `progress: number` | `void` | `obj:refresh(progress)` |
| refreshResearchList | Instance | `` | `void` | `obj:refreshResearchList()` |
| refreshResearchRate | Instance | `` | `void` | `obj:refreshResearchRate()` |
| refreshDiplomacy | Instance | `` | `void` | `obj:refreshDiplomacy()` |
| refreshSquads | Instance | `` | `void` | `obj:refreshSquads()` |
| refreshMap | Instance | `centerCamera: boolean` | `void` | `obj:refreshMap(centerCamera)` |
| showRoads | Instance | `v: boolean` | `void` | `obj:showRoads(v)` |
| addSquadToMap | Instance | `` | `void` | `obj:addSquadToMap()` |
| removeSquadFromMap | Instance | `` | `void` | `obj:removeSquadFromMap()` |
| resetSquads | Instance | `` | `void` | `obj:resetSquads()` |
| refreshMessages | Instance | `` | `void` | `obj:refreshMessages()` |
| refreshAI | Instance | `` | `void` | `obj:refreshAI()` |
| showDebugMarker | Instance | `p: Vector3` | `void` | `obj:showDebugMarker(p)` |
| setCraftingBench | Instance | `` | `void` | `obj:setCraftingBench()` |
| printResearch | Static / Instance | `` | `void` | `ManagementScreen.printResearch()`<br>`obj:printResearch()` |
| addMessage | Instance | `owner: string, message: string, isPlayer: integer` | `void` | `obj:addMessage(owner, message, isPlayer)` |
| getSingleton | Static / Instance | `` | `ManagementScreen` | `ManagementScreen.getSingleton()`<br>`obj:getSingleton()` |
| updateResearchListRate | Instance | `` | `void` | `obj:updateResearchListRate()` |
| refreshResearchListDescription | Instance | `` | `void` | `obj:refreshResearchListDescription()` |

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
| mainWidget | `lightuserdata` | R | `obj.mainWidget` |
| mapScrollView | `lightuserdata` | R | `obj.mapScrollView` |
| mapImage | `lightuserdata` | R | `obj.mapImage` |
| cameraMarker | `lightuserdata` | R | `obj.cameraMarker` |
| cameraMarkerSkin | `lightuserdata` | R | `obj.cameraMarkerSkin` |
| zoomUpdated | `boolean` | RW | `obj.zoomUpdated = <value>` |
| zoomValueBase | `number` | RW | `obj.zoomValueBase = <value>` |
| zoomValueMax | `number` | RW | `obj.zoomValueMax = <value>` |
| zoomValueCurrent | `number` | RW | `obj.zoomValueCurrent = <value>` |
| zoomLevelCurrent | `integer` | RW | `obj.zoomLevelCurrent = <value>` |
| mapOverlaysContainer | `lightuserdata` | R | `obj.mapOverlaysContainer` |
| zoomLevels | `number` | RW | `obj.zoomLevels = <value>` |
| mapMarkerMovement | `lightuserdata` | RW | `obj.mapMarkerMovement = <value>` |
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
| mapMarkersTownsNew | `HandFastArrayBinding::ArrayType` | RW | `obj.mapMarkersTownsNew = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| centerCamera | Instance | `` | `void` | `obj:centerCamera()` |
| clearTempMarkers | Instance | `` | `void` | `obj:clearTempMarkers()` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| update [1] | Instance | `mapPosition: MyGUI::types::TPoint<int>, zoom: MapZoomLevel` | `void` | `obj:update(mapPosition, zoom)` |
| update [2] | Instance | `mapPosition: MyGUI::types::TPoint<int>` | `void` | `obj:update(mapPosition)` |
| update [3] | Instance | `` | `void` | `obj:update()` |
| addSquad | Instance | `` | `void` | `obj:addSquad()` |
| removeSquad | Instance | `` | `void` | `obj:removeSquad()` |
| hide | Instance | `` | `void` | `obj:hide()` |
| setMovementMarker | Instance | `p: Vector3, time: number` | `void` | `obj:setMovementMarker(p, time)` |
| showRoads | Instance | `on: boolean` | `void` | `obj:showRoads(on)` |
| updateZoom | Instance | `` | `void` | `obj:updateZoom()` |
| updateCameraMarker | Instance | `` | `void` | `obj:updateCameraMarker()` |
| refreshTowns | Instance | `` | `void` | `obj:refreshTowns()` |
| refreshSquads | Instance | `` | `void` | `obj:refreshSquads()` |
| updateCharacterMarker | Instance | `` | `void` | `obj:updateCharacterMarker()` |
| getMouseWorldPosition | Instance | `position: Vector3` | `boolean` | `obj:getMouseWorldPosition(position)` |
| setupRoads | Instance | `` | `void` | `obj:setupRoads()` |
| updateRoads | Instance | `` | `void` | `obj:updateRoads()` |
| updatePlayerTownMapMarker | Instance | `` | `void` | `obj:updatePlayerTownMapMarker()` |
| worldToMapCoords | Instance | `pos: Vector3` | `void` | `obj:worldToMapCoords(pos)` |
| mapCoordsToWorld | Instance | `left: integer, top: integer` | `Vector3` | `obj:mapCoordsToWorld(left, top)` |

## MapScreen::MapMarkerCharacter
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`
**Parent Class:** [`MapScreen`](#mapscreen)
**Metatable:** `KenshiLua.MapMarkerCharacter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | `unknown` | RW | `obj.handle = <value>` |
| image | `lightuserdata` | R | `obj.image` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |

## MapScreen::MapMarkerTown
**Header:** `extern/KenshiLib/Include/kenshi/gui/MapScreen.h`
**Parent Class:** [`MapScreen`](#mapscreen)
**Metatable:** `KenshiLua.MapMarkerTown`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | `unknown` | RW | `obj.handle = <value>` |
| zoomLayer | `integer` | RW | `obj.zoomLayer = <value>` |
| root | `lightuserdata` | R | `obj.root` |
| image | `lightuserdata` | R | `obj.image` |
| label | `lightuserdata` | R | `obj.label` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `value: boolean` | `void` | `obj:setVisible(value)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |

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
| mHistoryBufferX | `FloatDequeBinding::DequeType` | RW | `obj.mHistoryBufferX = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | Instance | `numFrames: integer, numSamples: integer, _isPositionsFilter: boolean` | `void` | `obj:setup(numFrames, numSamples, _isPositionsFilter)` |
| reset | Instance | `` | `void` | `obj:reset()` |
| applySilent | Instance | `delta_mouse_x: number` | `void` | `obj:applySilent(delta_mouse_x)` |

## MedianFilter2DVector
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MedianFilter2DVector`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| filters | `unknown` | RW | `obj.filters = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | Instance | `numFrames: integer, numSamples: integer, positions: boolean` | `void` | `obj:setup(numFrames, numSamples, positions)` |
| reset | Instance | `` | `void` | `obj:reset()` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`
**Metatable:** `KenshiLua.MedicalSystem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| status | `unknown` | RW | `obj.status = <value>` |
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
| currentWeatherAffect | `integer` | RW | `obj.currentWeatherAffect = <value>` |
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
| wounds | `WoundFastArrayBinding::ArrayType` | RW | `obj.wounds = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| precalculateFirstAidNeedScore | Instance | `` | `void` | `obj:precalculateFirstAidNeedScore()` |
| scoreFirstAidNeed | Instance | `robotAid: boolean` | `number` | `obj:scoreFirstAidNeed(robotAid)` |
| scoreJuryRigNeed | Instance | `skills: number` | `number` | `obj:scoreJuryRigNeed(skills)` |
| isFullyRested | Instance | `` | `boolean` | `obj:isFullyRested()` |
| validateHealthValues | Instance | `` | `void` | `obj:validateHealthValues()` |
| amputate | Instance | `limb: integer, createSeveredItem: boolean, force: Vector3` | `void` | `obj:amputate(limb, createSeveredItem, force)` |
| crushLimb | Instance | `limb: integer` | `void` | `obj:crushLimb(limb)` |
| isUselessNoLimbGuy | Instance | `` | `boolean` | `obj:isUselessNoLimbGuy()` |
| recalculateStealthHinderance | Instance | `` | `number` | `obj:recalculateStealthHinderance()` |
| getPartCount | Instance | `` | `integer` | `obj:getPartCount()` |
| hasRobotics | Instance | `` | `boolean` | `obj:hasRobotics()` |
| isFed | Instance | `` | `boolean` | `obj:isFed()` |
| getMaxBlood | Instance | `` | `number` | `obj:getMaxBlood()` |
| startKnockoutTimer | Instance | `` | `void` | `obj:startKnockoutTimer()` |
| knockout | Instance | `skill: number` | `void` | `obj:knockout(skill)` |
| knockoutForceTimer | Instance | `seconds: number` | `void` | `obj:knockoutForceTimer(seconds)` |
| pointOfCollapseBloodloss | Instance | `` | `number` | `obj:pointOfCollapseBloodloss()` |
| pointOfNoReturn | Instance | `` | `number` | `obj:pointOfNoReturn()` |
| isHungerKO | Instance | `` | `boolean` | `obj:isHungerKO()` |
| getToughnessXpBonus | Instance | `` | `number` | `obj:getToughnessXpBonus()` |
| getHungerSpeedModifier | Instance | `` | `number` | `obj:getHungerSpeedModifier()` |
| getMissingArmPenaltyMult | Instance | `` | `number` | `obj:getMissingArmPenaltyMult()` |
| getDerivedHeadHealth | Instance | `` | `number` | `obj:getDerivedHeadHealth()` |
| calculateDesiredPainAnimations | Instance | `` | `void` | `obj:calculateDesiredPainAnimations()` |
| getMovementSpeedInjuryMultiplier | Instance | `` | `number` | `obj:getMovementSpeedInjuryMultiplier()` |
| getMovementSwimSpeedInjuryMultiplier | Instance | `` | `number` | `obj:getMovementSwimSpeedInjuryMultiplier()` |
| gettingEaten | Instance | `amount: number, vampire: boolean` | `boolean` | `obj:gettingEaten(amount, vampire)` |
| gettingAcidRain | Instance | `amount: number` | `boolean` | `obj:gettingAcidRain(amount)` |
| gettingAcidWater | Instance | `amount: number` | `boolean` | `obj:gettingAcidWater(amount)` |
| gettingAcidFeet | Instance | `amount: number` | `boolean` | `obj:gettingAcidFeet(amount)` |
| gettingGassed | Instance | `amount: number` | `boolean` | `obj:gettingGassed(amount)` |
| gettingWindyface | Instance | `amount: number` | `boolean` | `obj:gettingWindyface(amount)` |
| gettingBurnt | Instance | `amount: number` | `boolean` | `obj:gettingBurnt(amount)` |
| reassessCollapseMode | Instance | `medic: boolean, agony: boolean` | `void` | `obj:reassessCollapseMode(medic, agony)` |
| isUnconcious | Instance | `` | `boolean` | `obj:isUnconcious()` |
| isCrippled | Instance | `` | `boolean` | `obj:isCrippled()` |
| isDead | Instance | `` | `boolean` | `obj:isDead()` |
| hasAnArmToFightWith | Instance | `` | `boolean` | `obj:hasAnArmToFightWith()` |
| hasFreshlySeveredALimb | Instance | `` | `boolean` | `obj:hasFreshlySeveredALimb()` |
| isReallyHungry | Instance | `` | `boolean` | `obj:isReallyHungry()` |
| isProbablyDying | Instance | `` | `boolean` | `obj:isProbablyDying()` |
| getOverallHealthRating | Instance | `` | `number` | `obj:getOverallHealthRating()` |
| canGetUpWakeUp | Instance | `` | `boolean` | `obj:canGetUpWakeUp()` |
| isRightArmOk | Instance | `` | `boolean` | `obj:isRightArmOk()` |
| isLeftArmOk | Instance | `` | `boolean` | `obj:isLeftArmOk()` |
| canIkick | Instance | `` | `boolean` | `obj:canIkick()` |
| isInBloodlossTrauma | Instance | `` | `boolean` | `obj:isInBloodlossTrauma()` |
| clearWeatherEffects | Instance | `` | `void` | `obj:clearWeatherEffects()` |
| getWeatherStatPenaltyMult | Instance | `` | `number` | `obj:getWeatherStatPenaltyMult()` |
| getWeatherStatPenalty | Instance | `mult: number` | `integer` | `obj:getWeatherStatPenalty(mult)` |
| calculateBleedRateForFX | Instance | `` | `number` | `obj:calculateBleedRateForFX()` |
| _setHealth | Instance | `` | `void` | `obj:_setHealth()` |
| getLimbState | Instance | `` | `void` | `obj:getLimbState()` |
| getPart [1] | Instance | `what: RobotLimbs::Limb` | `MedicalSystem::HealthPartStatus` | `obj:getPart(what)` |
| getPart [2] | Instance | `index: integer` | `MedicalSystem::HealthPartStatus` | `obj:getPart(index)` |
| getPart [3] | Instance | `partType: MedicalSystem::HealthPartStatus::PartType, leftSide: LeftRight` | `MedicalSystem::HealthPartStatus` | `obj:getPart(partType, leftSide)` |
| addArmour | Instance | `` | `void` | `obj:addArmour()` |
| removeArmour | Instance | `` | `void` | `obj:removeArmour()` |
| wearingUniformOf | Instance | `` | `void` | `obj:wearingUniformOf()` |
| applyFirstAid | Instance | `` | `void` | `obj:applyFirstAid()` |
| applyDoctoring | Instance | `` | `void` | `obj:applyDoctoring()` |
| applyRigging | Instance | `` | `void` | `obj:applyRigging()` |

## MedicalSystem::HealthPartStatus
**Header:** `extern/KenshiLib/Include/kenshi/MedicalSystem.h`
**Parent Class:** [`MedicalSystem`](#medicalsystem)
**Metatable:** `KenshiLua.HealthPartStatus`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| data | `GameData` | RW | `obj.data = <value>` |
| whatAmI | `integer` | RW | `obj.whatAmI = <value>` |
| medical | `MedicalSystem` | RW | `obj.medical = <value>` |
| me | `Character` | RW | `obj.me = <value>` |
| side | `integer` | RW | `obj.side = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| serialise | Instance | `num: integer` | `void` | `obj:serialise(num)` |
| load | Instance | `num: integer` | `void` | `obj:load(num)` |
| isRobotic | Instance | `` | `boolean` | `obj:isRobotic()` |
| getData | Instance | `` | `GameData` | `obj:getData()` |
| getRobotLimbEnum | Instance | `` | `integer` | `obj:getRobotLimbEnum()` |
| setup | Instance | `_hitchance: number, _max: number, _age: number, selfHeal: boolean` | `void` | `obj:setup(_hitchance, _max, _age, selfHeal)` |
| update | Instance | `frameTIME: number, healMultFlesh: number, healMultRobot: number, degenerationRate: number, _age: number, robotWear: number` | `boolean` | `obj:update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear)` |
| updateDerivedHealths | Instance | `` | `void` | `obj:updateDerivedHealths()` |
| getWorstDamage | Instance | `brokenBoneValue: number` | `number` | `obj:getWorstDamage(brokenBoneValue)` |
| setRobotLimbItem | Instance | `isLoadingASave: boolean` | `void` | `obj:setRobotLimbItem(isLoadingASave)` |
| getExtraBleedingAmount | Instance | `` | `number` | `obj:getExtraBleedingAmount()` |
| isDead | Instance | `` | `boolean` | `obj:isDead()` |
| getBloodynessMult | Instance | `` | `number` | `obj:getBloodynessMult()` |
| maxHealth | Instance | `` | `number` | `obj:maxHealth()` |
| healthAsPercent | Instance | `healt: number` | `number` | `obj:healthAsPercent(healt)` |

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

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| hideMessageBox | Static / Instance | `` | `boolean` | `MessageBoxManager.hideMessageBox()`<br>`obj:hideMessageBox()` |
| hasModalMessage | Static / Instance | `` | `boolean` | `MessageBoxManager.hasModalMessage()`<br>`obj:hasModalMessage()` |

## MessageBoxManager::Box
**Header:** `extern/KenshiLib/Include/kenshi/gui/MessageBoxManager.h`
**Parent Class:** [`MessageBoxManager`](#messageboxmanager)
**Metatable:** `KenshiLua.Box`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| modal | `boolean` | RW | `obj.modal = <value>` |
| callback | `lightuserdata` | R | `obj.callback` |

## MessageChain
**Header:** `extern/KenshiLib/Include/kenshi/physicsactual.h`
**Metatable:** `KenshiLua.MessageChain`

## MessageForB
**Header:** `extern/KenshiLib/Include/kenshi/Enums.h`
**Metatable:** `KenshiLua.MessageForB`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| messageType | `integer` | RW | `obj.messageType = <value>` |
| messageInt | `integer` | RW | `obj.messageInt = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| new | Static / Instance | `` | `void` | `MessageForB.new()`<br>`obj:new()` |

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

## MotionFilter
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MotionFilter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mWeightModifier | `number` | RW | `obj.mWeightModifier = <value>` |
| mHistoryBufferX | `FloatDequeBinding::DequeType` | RW | `obj.mHistoryBufferX = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| SetHistoryBufferLength | Instance | `length: integer, fill: number` | `boolean` | `obj:SetHistoryBufferLength(length, fill)` |

## MultiSlider
**Header:** `extern/KenshiLib/Include/kenshi/gui/MyGUI_MultiSlider.h`
**Metatable:** `KenshiLua.MultiSlider`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mName | `lightuserdata` | R | `obj.mName` |
| mDisableEvents | `boolean` | RW | `obj.mDisableEvents = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| initialiseOverride | Instance | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | Instance | `` | `void` | `obj:shutdownOverride()` |

## MustEndWithSemiColon
**Header:** `extern/KenshiLib/Include/kenshi/CharMovement.h`
**Metatable:** `KenshiLua.MustEndWithSemiColon`

## MyGUI
For full widget creation, layout loading, property access, and event handling reference, see the dedicated [MyGUI Bindings Documentation](MyGUI_Bindings.md).

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| initialise | Instance | `` | `void` | `obj:initialise()` |
| shutdown | Instance | `` | `void` | `obj:shutdown()` |
| create | Instance | `` | `void` | `obj:create()` |
| unload | Instance | `` | `void` | `obj:unload()` |
| destroy | Instance | `` | `void` | `obj:destroy()` |
| getZoneEdge | Instance | `start: Vector3, target: Vector3, offset: number` | `Vector3` | `obj:getZoneEdge(start, target, offset)` |
| getClosestExteriorPoint | Instance | `point: Vector3, radius: number, inset: number, out: Vector3` | `integer` | `obj:getClosestExteriorPoint(point, radius, inset, out)` |
| setDoorState | Instance | `open: boolean` | `void` | `obj:setDoorState(open)` |
| isInterior | Instance | `key: integer` | `boolean` | `obj:isInterior(key)` |
| getPositionValid | Instance | `point: Vector3` | `boolean` | `obj:getPositionValid(point)` |
| processCompletedCharacterMessages | Instance | `` | `void` | `obj:processCompletedCharacterMessages()` |
| processDoorRequests | Instance | `` | `void` | `obj:processDoorRequests()` |
| getPolygonID | Instance | `p: Vector3` | `string` | `obj:getPolygonID(p)` |
| validateFaceKey | Instance | `key: integer` | `boolean` | `obj:validateFaceKey(key)` |
| isGenerating | Instance | `` | `boolean` | `obj:isGenerating()` |
| getWorldShift | Instance | `` | `Vector3` | `obj:getWorldShift()` |
| threadProc | Instance | `` | `integer` | `obj:threadProc()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| setupHavok | Instance | `` | `void` | `obj:setupHavok()` |
| shutdownHavok | Instance | `` | `void` | `obj:shutdownHavok()` |
| loadZone | Instance | `` | `void` | `obj:loadZone()` |
| unloadZone | Instance | `` | `void` | `obj:unloadZone()` |
| unloadBuilding | Instance | `` | `void` | `obj:unloadBuilding()` |
| getUID [1] | Static / Instance | `building: hand` | `integer` | `NavMesh.getUID(building)`<br>`obj:getUID(building)` |
| getUID [2] | Static / Instance | `zone: iVector2` | `integer` | `NavMesh.getUID(zone)`<br>`obj:getUID(zone)` |
| hashBuilding | Static / Instance | `` | `integer` | `NavMesh.hashBuilding()`<br>`obj:hashBuilding()` |
| hashInterior | Static / Instance | `` | `integer` | `NavMesh.hashInterior()`<br>`obj:hashInterior()` |
| hashZone | Static / Instance | `` | `integer` | `NavMesh.hashZone()`<br>`obj:hashZone()` |
| getFilename | Static / Instance | `` | `string` | `NavMesh.getFilename()`<br>`obj:getFilename()` |

## NavMesh::BuildingInfo
**Header:** `extern/KenshiLib/Include/kenshi/NavMesh.h`
**Parent Class:** [`NavMesh`](#navmesh)
**Metatable:** `KenshiLua.NavMesh_BuildingInfo`

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isGenerating | Instance | `` | `boolean` | `obj:isGenerating()` |
| threadProc | Instance | `` | `integer` | `obj:threadProc()` |
| updateBT | Instance | `` | `boolean` | `obj:updateBT()` |
| generateTaskBT | Instance | `task: userdata` | `void` | `obj:generateTaskBT(task)` |
| validateBuildingStates | Instance | `task: userdata` | `integer` | `obj:validateBuildingStates(task)` |
| carve | Instance | `task: userdata` | `integer` | `obj:carve(task)` |
| splice | Instance | `t: userdata` | `integer` | `obj:splice(t)` |
| stitchInterior | Instance | `t: userdata` | `integer` | `obj:stitchInterior(t)` |
| stitchExterior | Instance | `t: userdata` | `integer` | `obj:stitchExterior(t)` |
| revertSettings | Instance | `` | `void` | `obj:revertSettings()` |
| unlockTask | Instance | `task: userdata` | `void` | `obj:unlockTask(task)` |
| hasJob | Instance | `` | `boolean` | `obj:hasJob()` |
| update | Instance | `` | `void` | `obj:update()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| load | Instance | `` | `void` | `obj:load()` |
| save | Instance | `` | `void` | `obj:save()` |
| addSeedPoint | Instance | `p: Vector3, terrain: boolean` | `void` | `obj:addSeedPoint(p, terrain)` |
| removeSeedPoints | Instance | `pos: Vector3, radius: number` | `integer` | `obj:removeSeedPoints(pos, radius)` |
| clearSeedPoints | Instance | `` | `integer` | `obj:clearSeedPoints()` |
| removeIsland | Instance | `pos: Vector3, radius: number` | `integer` | `obj:removeIsland(pos, radius)` |
| projectToTerrain | Instance | `` | `void` | `obj:projectToTerrain()` |
| getSeedPoints | Instance | `` | `lightuserdata` | `obj:getSeedPoints()` |

## NewGameOptionsWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameOptionsWindow.h`
**Metatable:** `KenshiLua.NewGameOptionsWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| optionsPanel | `DatapanelGUI` | RW | `obj.optionsPanel = <value>` |
| tooltip | `ToolTip` | RW | `obj.tooltip = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setPosition | Instance | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| update | Instance | `` | `void` | `obj:update()` |

## NewGameWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/NewGameWindow.h`
**Metatable:** `KenshiLua.NewGameWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| currentStart | `integer` | RW | `obj.currentStart = <value>` |
| startInfo | `DatapanelGUI` | RW | `obj.startInfo = <value>` |
| startNameTextBox | `lightuserdata` | R | `obj.startNameTextBox` |
| newGameOptions | `NewGameOptionsWindow` | RW | `obj.newGameOptions = <value>` |
| startsData | `GameDataFastArrayBinding::ArrayType` | RW | `obj.startsData = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setRealPosition | Instance | `x: number, y: number` | `void` | `obj:setRealPosition(x, y)` |
| setPosition | Instance | `x: integer, y: integer` | `void` | `obj:setPosition(x, y)` |
| show | Instance | `_a1: boolean` | `void` | `obj:show(_a1)` |
| update | Instance | `` | `void` | `obj:update()` |
| loadData | Instance | `` | `void` | `obj:loadData()` |
| updateCurrentData | Instance | `` | `void` | `obj:updateCurrentData()` |

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

## NxMat33
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Metatable:** `KenshiLua.NxMat33`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setRowMajor | Instance | `d: userdata` | `void` | `obj:setRowMajor(d)` |
| getRowMajor | Instance | `d: userdata` | `void` | `obj:getRowMajor(d)` |
| getColumnMajor | Instance | `d: userdata` | `void` | `obj:getColumnMajor(d)` |
| setRowMajorStride4 | Instance | `d: userdata` | `void` | `obj:setRowMajorStride4(d)` |
| getRowMajorStride4 | Instance | `d: userdata` | `void` | `obj:getRowMajorStride4(d)` |
| getColumnMajorStride4 | Instance | `d: userdata` | `void` | `obj:getColumnMajorStride4(d)` |
| isFinite | Instance | `` | `boolean` | `obj:isFinite()` |
| zero | Instance | `` | `void` | `obj:zero()` |
| id | Instance | `` | `void` | `obj:id()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| zero | Instance | `` | `void` | `obj:zero()` |
| isZero | Instance | `` | `integer` | `obj:isZero()` |
| normalize | Instance | `` | `number` | `obj:normalize()` |
| setMagnitude | Instance | `length: number` | `void` | `obj:setMagnitude(length)` |
| closestAxis | Instance | `` | `integer` | `obj:closestAxis()` |
| isFinite | Instance | `` | `boolean` | `obj:isFinite()` |
| magnitude | Instance | `` | `number` | `obj:magnitude()` |
| magnitudeSquared | Instance | `` | `number` | `obj:magnitudeSquared()` |

## OpenSaveFileDialog
**Header:** `extern/KenshiLib/Include/kenshi/gui/OpenSaveFileDialog.h`
**Metatable:** `KenshiLua.OpenSaveFileDialog`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| filesList | `lightuserdata` | R | `obj.filesList` |
| fileNameTxt | `lightuserdata` | R | `obj.fileNameTxt` |
| currentFolderList | `lightuserdata` | R | `obj.currentFolderList` |
| openSaveButton | `lightuserdata` | R | `obj.openSaveButton` |
| currentFolder | `string` | RW | `obj.currentFolder = <value>` |
| fileName | `string` | RW | `obj.fileName = <value>` |
| fileMask | `string` | RW | `obj.fileMask = <value>` |
| currentSelected | `string` | RW | `obj.currentSelected = <value>` |
| folderMode | `boolean` | RW | `obj.folderMode = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setDialogInfo | Instance | `_caption: string, _button: string, _folderMode: boolean` | `void` | `obj:setDialogInfo(_caption, _button, _folderMode)` |
| setCurrentFolder | Instance | `_folder: string` | `void` | `obj:setCurrentFolder(_folder)` |
| setFileName | Instance | `_value: string` | `void` | `obj:setFileName(_value)` |
| setFileMask | Instance | `_value: string` | `void` | `obj:setFileMask(_value)` |
| update | Instance | `` | `void` | `obj:update()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| enabledCivilians | Instance | `` | `boolean` | `obj:enabledCivilians()` |
| characterMultithreadingEnabled | Instance | `` | `boolean` | `obj:characterMultithreadingEnabled()` |
| compositiorEnabled | Instance | `name: string` | `boolean` | `obj:compositiorEnabled(name)` |
| loadCompositorSettings | Instance | `` | `void` | `obj:loadCompositorSettings()` |

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
| tabs | `lightuserdata` | R | `obj.tabs` |
| created | `boolean` | RW | `obj.created = <value>` |
| tooltip | `ToolTip` | RW | `obj.tooltip = <value>` |
| previewFontSize | `boolean` | RW | `obj.previewFontSize = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| show | Instance | `value: boolean` | `void` | `obj:show(value)` |
| hide | Instance | `` | `void` | `obj:hide()` |
| toggle | Instance | `` | `void` | `obj:toggle()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| waitingForKey | Instance | `` | `boolean` | `obj:waitingForKey()` |
| setKey | Instance | `code: integer` | `void` | `obj:setKey(code)` |
| update | Instance | `` | `void` | `obj:update()` |
| saveLocationChanged | Instance | `` | `void` | `obj:saveLocationChanged()` |
| changeFontSize | Instance | `` | `void` | `obj:changeFontSize()` |
| changeVolume | Instance | `` | `void` | `obj:changeVolume()` |
| toggleNames | Instance | `` | `void` | `obj:toggleNames()` |
| resetTutorials | Instance | `` | `void` | `obj:resetTutorials()` |
| toggleTutorials | Instance | `` | `void` | `obj:toggleTutorials()` |
| changeDistances | Instance | `` | `void` | `obj:changeDistances()` |
| toggleCompositor | Instance | `` | `void` | `obj:toggleCompositor()` |
| resetAllKeys | Instance | `` | `void` | `obj:resetAllKeys()` |
| saveOptions | Instance | `` | `void` | `obj:saveOptions()` |
| create | Instance | `` | `void` | `obj:create()` |
| updateResolutions | Instance | `` | `void` | `obj:updateResolutions()` |
| getSingleton | Static / Instance | `` | `OptionsWindow` | `OptionsWindow.getSingleton()`<br>`obj:getSingleton()` |

## OrderCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrderCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| orderText | `lightuserdata` | R | `obj.orderText` |
| removeButton | `lightuserdata` | R | `obj.removeButton` |
| data | `OrderData` | RW | `obj.data = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWidget | Instance | `` | `lightuserdata` | `obj:getWidget()` |
| resize | Instance | `` | `void` | `obj:resize()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| set | Instance | `_index: integer, _enabled: boolean` | `void` | `obj:set(_index, _enabled)` |
| updateText | Instance | `` | `void` | `obj:updateText()` |

## OrdersItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrdersItemBox`

## OrdersPanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/OrdersPanel.h`
**Metatable:** `KenshiLua.OrdersPanel`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| ordersCharacter | `unknown` | RW | `obj.ordersCharacter = <value>` |
| ordersItemBox | `OrdersItemBox` | RW | `obj.ordersItemBox = <value>` |
| ordersItemWidth | `integer` | RW | `obj.ordersItemWidth = <value>` |
| ordersItemBoxScrollBarSize | `integer` | RW | `obj.ordersItemBoxScrollBarSize = <value>` |
| ordersItemBoxMaxVisible | `integer` | RW | `obj.ordersItemBoxMaxVisible = <value>` |
| ordersEmptyPanel | `lightuserdata` | R | `obj.ordersEmptyPanel` |
| blocksCheckbox | `lightuserdata` | R | `obj.blocksCheckbox` |
| holdCheckBox | `lightuserdata` | R | `obj.holdCheckBox` |
| passiveCheckBox | `lightuserdata` | R | `obj.passiveCheckBox` |
| chaseCheckBox | `lightuserdata` | R | `obj.chaseCheckBox` |
| tauntCheckBox | `lightuserdata` | R | `obj.tauntCheckBox` |
| rangedCheckBox | `lightuserdata` | R | `obj.rangedCheckBox` |
| stealthCheckBox | `lightuserdata` | R | `obj.stealthCheckBox` |
| speedPrevButton | `lightuserdata` | R | `obj.speedPrevButton` |
| speedNextButton | `lightuserdata` | R | `obj.speedNextButton` |
| speedImagePanel | `lightuserdata` | R | `obj.speedImagePanel` |
| speedImageNamesIdx | `integer` | RW | `obj.speedImageNamesIdx = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| clear | Instance | `` | `void` | `obj:clear()` |
| command | Instance | `cmd: integer` | `void` | `obj:command(cmd)` |
| refreshOrders | Instance | `` | `void` | `obj:refreshOrders()` |
| moveJob | Instance | `orderIdx: integer, targetIdx: integer` | `void` | `obj:moveJob(orderIdx, targetIdx)` |
| removeJob | Instance | `` | `void` | `obj:removeJob()` |
| notifyEndDropOrder | Instance | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropOrder(_sender, _result)` |
| setSpeed | Instance | `moveSpeed: integer` | `void` | `obj:setSpeed(moveSpeed)` |
| setSpeedImage | Instance | `moveSpeed: integer` | `void` | `obj:setSpeedImage(moveSpeed)` |

## Ownerships
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.Ownerships`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| _homeTown | `TownBase` | RW | `obj._homeTown = <value>` |
| _homeBuilding | `unknown` | RW | `obj._homeBuilding = <value>` |
| faction | `Faction` | RW | `obj.faction = <value>` |
| me | `Platoon` | RW | `obj.me = <value>` |
| occupiedTown | `TownBase` | RW | `obj.occupiedTown = <value>` |
| money | `integer` | RW | `obj.money = <value>` |
| slaves | `unknown` | RW | `obj.slaves = <value>` |
| stuff | `lektor<hand>` | RW | `obj.stuff = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| takeMoney | Instance | `val: integer` | `boolean` | `obj:takeMoney(val)` |
| takeMoneyByForce | Instance | `val: integer` | `void` | `obj:takeMoneyByForce(val)` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| addMoney | Instance | `amount: integer` | `void` | `obj:addMoney(amount)` |
| setMoney | Instance | `amount: integer` | `void` | `obj:setMoney(amount)` |
| setHomeBuildingDesignation | Instance | `d: integer` | `void` | `obj:setHomeBuildingDesignation(d)` |
| copyFrom | Instance | `` | `void` | `obj:copyFrom()` |
| serialise | Instance | `` | `void` | `obj:serialise()` |
| load | Instance | `st: integer` | `void` | `obj:load(st)` |
| setHomeTown | Instance | `squadtype: integer` | `void` | `obj:setHomeTown(squadtype)` |
| isMyTown | Instance | `` | `boolean` | `obj:isMyTown()` |
| canIUseThisBuilding | Instance | `` | `boolean` | `obj:canIUseThisBuilding()` |
| declareOccupiedTown | Instance | `` | `void` | `obj:declareOccupiedTown()` |
| getOccupiedTownFaction | Instance | `` | `Faction` | `obj:getOccupiedTownFaction()` |
| addOwnedObject | Instance | `` | `void` | `obj:addOwnedObject()` |
| removeOwnedObject | Instance | `` | `void` | `obj:removeOwnedObject()` |
| isOwned | Instance | `` | `boolean` | `obj:isOwned()` |
| setHomeBuilding | Instance | `t: integer` | `void` | `obj:setHomeBuilding(t)` |
| getOwnedBuildingsH | Instance | `` | `void` | `obj:getOwnedBuildingsH()` |
| getOwnedBuildingPtrs | Instance | `` | `void` | `obj:getOwnedBuildingPtrs()` |
| getHomeFurnitureOfType | Instance | `type: integer` | `void` | `obj:getHomeFurnitureOfType(type)` |
| getOwnedPtrs | Instance | `type: integer` | `integer` | `obj:getOwnedPtrs(type)` |
| getBuildingsWithFunction | Instance | `bf: integer` | `void` | `obj:getBuildingsWithFunction(bf)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| init | Instance | `` | `void` | `obj:init()` |
| destroy | Instance | `` | `void` | `obj:destroy()` |
| getSize | Instance | `` | `integer` | `obj:getSize()` |
| update | Instance | `` | `void` | `obj:update()` |
| shiftParticles | Instance | `shift: Vector3` | `void` | `obj:shiftParticles(shift)` |

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
| hitObject | `unknown` | RW | `obj.hitObject = <value>` |
| _group | `integer` | RW | `obj._group = <value>` |
| _hitObjectUnsafePtr | `RootObject` | RW | `obj._hitObjectUnsafePtr = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| traceWasAborted | Instance | `` | `boolean` | `obj:traceWasAborted()` |
| reset | Instance | `` | `void` | `obj:reset()` |
| hitObjectUnsafePtr | Instance | `` | `RootObject` | `obj:hitObjectUnsafePtr()` |
| getBuilding | Instance | `` | `Building` | `obj:getBuilding()` |
| group | Instance | `` | `integer` | `obj:group()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateUT | Instance | `` | `void` | `obj:updateUT()` |
| backThreadUpdate | Instance | `time: number, _useOwnTimers: boolean` | `void` | `obj:backThreadUpdate(time, _useOwnTimers)` |
| threadJunkPreBT | Instance | `` | `void` | `obj:threadJunkPreBT()` |
| threadJunkPostBT | Instance | `` | `void` | `obj:threadJunkPostBT()` |
| setup | Instance | `` | `boolean` | `obj:setup()` |
| scytheGetFirstModelName | Instance | `filename: string` | `string` | `obj:scytheGetFirstModelName(filename)` |
| _createTriggerHull | Instance | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:_createTriggerHull(pos, size)` |
| _createStaticCapsule | Instance | `pos: Vector3, length: number, radius: number` | `lightuserdata` | `obj:_createStaticCapsule(pos, length, radius)` |
| _createStaticBox | Instance | `pos: Vector3, dimensions: Vector3, rot: Quaternion, group: integer` | `lightuserdata` | `obj:_createStaticBox(pos, dimensions, rot, group)` |
| uncookMesh | Instance | `mesh: userdata, cId: string` | `boolean` | `obj:uncookMesh(mesh, cId)` |

## PhysicsActual::TriggerCallback
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsActual.h`
**Parent Class:** [`PhysicsActual`](#physicsactual)
**Metatable:** `KenshiLua.TriggerCallback`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateFrameEndMT | Instance | `` | `void` | `obj:updateFrameEndMT()` |

## PhysicsCollection
**Header:** `extern/KenshiLib/Include/kenshi/physicscollection.h`
**Metatable:** `KenshiLua.PhysicsCollection`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| findRotatingEnt | Instance | `` | `PhysicsCollection::RotatingEnt` | `obj:findRotatingEnt()` |
| getWindRotationPower | Instance | `` | `number` | `obj:getWindRotationPower()` |
| getWindMillPart | Instance | `` | `PhysicsCollection::RotatingEnt` | `obj:getWindMillPart()` |
| isLoaded | Instance | `` | `boolean` | `obj:isLoaded()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| update [1] | Instance | `spd: number` | `void` | `obj:update(spd)` |
| update [2] | Instance | `speed: number` | `void` | `obj:update(speed)` |
| updateAimingType | Instance | `speed: number, rotTarget: Vector3` | `number` | `obj:updateAimingType(speed, rotTarget)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setEnergyLevel | Instance | `level: number` | `void` | `obj:setEnergyLevel(level)` |
| setFloor | Instance | `floor: integer` | `void` | `obj:setFloor(floor)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `productionSpeed: number` | `void` | `obj:update(productionSpeed)` |
| updateAim | Instance | `speed: number, target: Vector3` | `number` | `obj:updateAim(speed, target)` |
| isRotatingEnt | Instance | `` | `boolean` | `obj:isRotatingEnt()` |
| getRotationPower | Instance | `` | `number` | `obj:getRotationPower()` |

## PhysicsCollection::StaticEnt
**Header:** `extern/KenshiLib/Include/kenshi/PhysicsCollection.h`
**Parent Class:** [`PhysicsCollection`](#physicscollection)
**Metatable:** `KenshiLua.StaticEnt`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `spd: number` | `void` | `obj:update(spd)` |
| updateAim | Instance | `rotSpeed: number, target: Vector3` | `number` | `obj:updateAim(rotSpeed, target)` |
| isRotatingEnt | Instance | `` | `boolean` | `obj:isRotatingEnt()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getBackthread | Instance | `` | `lightuserdata` | `obj:getBackthread()` |
| updateUT | Instance | `` | `void` | `obj:updateUT()` |
| backThreadUpdate | Instance | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| createTriggerHull | Instance | `pos: Vector3, size: Vector3` | `lightuserdata` | `obj:createTriggerHull(pos, size)` |
| createStaticCapsule | Instance | `pos: Vector3, h: number, w: number` | `lightuserdata` | `obj:createStaticCapsule(pos, h, w)` |
| doorWantsSetup | Instance | `` | `void` | `obj:doorWantsSetup()` |
| scytheInsertPreview | Instance | `` | `boolean` | `obj:scytheInsertPreview()` |
| loadScytheFileMT | Instance | `file: string, pos: Vector3, q: Quaternion, boneAttachment: string` | `lightuserdata` | `obj:loadScytheFileMT(file, pos, q, boneAttachment)` |
| queuesAreClearMT | Instance | `` | `boolean` | `obj:queuesAreClearMT()` |
| setQueuesAreClear | Instance | `on: boolean` | `void` | `obj:setQueuesAreClear(on)` |

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Platoon.h`
**Metatable:** `KenshiLua.Platoon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| stringID | `string` | RW | `obj.stringID = <value>` |
| _characterCountCurrent | `integer` | RW | `obj._characterCountCurrent = <value>` |
| _characterCountOriginal | `integer` | RW | `obj._characterCountOriginal = <value>` |
| squadType | `integer` | RW | `obj.squadType = <value>` |
| hasUniques | `YesNoMaybe` | RW | `obj.hasUniques = <value>` |
| speedOverride | `integer` | RW | `obj.speedOverride = <value>` |
| isSeparatedSquad | `unknown` | RW | `obj.isSeparatedSquad = <value>` |
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
| squadleader | `unknown` | RW | `obj.squadleader = <value>` |
| ownerships | `Ownerships` | RW | `obj.ownerships = <value>` |
| activePlatoon | `ActivePlatoon` | RW | `obj.activePlatoon = <value>` |
| unloadedPlatoon | `lightuserdata` | RW | `obj.unloadedPlatoon = <value>` |
| patrolSettings | `lightuserdata` | RW | `obj.patrolSettings = <value>` |
| isDead | `boolean` | RW | `obj.isDead = <value>` |
| imprisoned | `boolean` | RW | `obj.imprisoned = <value>` |
| index | `integer` | RW | `obj.index = <value>` |
| traderInventoryRefreshTime | `TimeOfDay` | RW | `obj.traderInventoryRefreshTime = <value>` |
| messageOnActivation | `integer` | RW | `obj.messageOnActivation = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCharacterCount | Instance | `count: integer` | `void` | `obj:setCharacterCount(count)` |
| chooseNewHome | Instance | `` | `void` | `obj:chooseNewHome()` |
| isUnconcious | Instance | `` | `boolean` | `obj:isUnconcious()` |
| getSquadType | Instance | `` | `integer` | `obj:getSquadType()` |
| setSquadType | Instance | `t: integer` | `void` | `obj:setSquadType(t)` |
| getCurrentTownLocation | Instance | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| hasCampaign | Instance | `` | `lightuserdata` | `obj:hasCampaign()` |
| iBuyStolenGoods | Instance | `` | `boolean` | `obj:iBuyStolenGoods()` |
| iBuyIllegalGoods | Instance | `` | `boolean` | `obj:iBuyIllegalGoods()` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| canTakeRefugees | Instance | `` | `boolean` | `obj:canTakeRefugees()` |
| isUnique | Instance | `` | `lightuserdata` | `obj:isUnique()` |
| getPlatoonStringID | Instance | `` | `string` | `obj:getPlatoonStringID()` |
| getBlackboard | Instance | `` | `lightuserdata` | `obj:getBlackboard()` |
| getDataType | Instance | `` | `integer` | `obj:getDataType()` |
| erasePlatoonFile | Instance | `` | `void` | `obj:erasePlatoonFile()` |
| showDebugMarker | Instance | `on: boolean` | `void` | `obj:showDebugMarker(on)` |
| getStateBroadcast | Instance | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| serialiseEverything | Instance | `levelEditor: boolean` | `GameData` | `obj:serialiseEverything(levelEditor)` |
| loadStateData | Instance | `` | `void` | `obj:loadStateData()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| reprocessTask | Instance | `` | `void` | `obj:reprocessTask()` |
| taskIsComplete | Instance | `` | `void` | `obj:taskIsComplete()` |
| setDataFilename | Instance | `f: string` | `void` | `obj:setDataFilename(f)` |
| isIntact | Instance | `` | `boolean` | `obj:isIntact()` |
| notifyMissionEnded | Instance | `` | `void` | `obj:notifyMissionEnded()` |
| activate | Instance | `` | `void` | `obj:activate()` |
| deactivate | Instance | `` | `void` | `obj:deactivate()` |
| declareDead | Instance | `` | `void` | `obj:declareDead()` |
| undeclareDead | Instance | `` | `void` | `obj:undeclareDead()` |
| isFullyLoaded | Instance | `` | `boolean` | `obj:isFullyLoaded()` |
| getActivePlatoon | Instance | `` | `ActivePlatoon` | `obj:getActivePlatoon()` |
| getUnloadedPlatoon | Instance | `` | `lightuserdata` | `obj:getUnloadedPlatoon()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| periodicUpdate_active | Instance | `time: number` | `void` | `obj:periodicUpdate_active(time)` |
| periodicUpdate_unloaded | Instance | `` | `void` | `obj:periodicUpdate_unloaded()` |
| setupPatrolSettings | Instance | `minRange: integer, maxRange: integer` | `void` | `obj:setupPatrolSettings(minRange, maxRange)` |
| getPatrolInfo | Instance | `` | `lightuserdata` | `obj:getPatrolInfo()` |
| getRoamingMapArea | Instance | `` | `lightuserdata` | `obj:getRoamingMapArea()` |
| isPersistentSquad | Instance | `` | `boolean` | `obj:isPersistentSquad()` |
| setPersistentSquad | Instance | `on: boolean` | `void` | `obj:setPersistentSquad(on)` |
| getOwnerships | Instance | `` | `Ownerships` | `obj:getOwnerships()` |
| getNearestActiveCharacter | Instance | `p: Vector3, floor: integer` | `Character` | `obj:getNearestActiveCharacter(p, floor)` |
| getSquadLeader | Instance | `` | `Character` | `obj:getSquadLeader()` |
| getCharacterCount | Instance | `` | `integer` | `obj:getCharacterCount()` |
| getCharacterCount_Original | Instance | `` | `integer` | `obj:getCharacterCount_Original()` |
| needsNewCharacters | Instance | `` | `integer` | `obj:needsNewCharacters()` |
| reCheckPersistenceOnUnload | Instance | `` | `void` | `obj:reCheckPersistenceOnUnload()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| setRoamingMapArea | Instance | `a: userdata` | `void` | `obj:setRoamingMapArea(a)` |
| getSquadLeader_theRealOne | Instance | `` | `void` | `obj:getSquadLeader_theRealOne()` |

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
| selectedCharacter | `unknown` | RW | `obj.selectedCharacter = <value>` |
| aiOptions | `PlayerInterface::AIOptions` | RW | `obj.aiOptions = <value>` |
| interiorsVisibleHash | `integer` | RW | `obj.interiorsVisibleHash = <value>` |
| currentFloor | `integer` | RW | `obj.currentFloor = <value>` |
| currentMouseTask | `integer` | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | `integer` | RW | `obj.mouseTaskTypeRestriction = <value>` |
| mouseRightTargetSet | `boolean` | RW | `obj.mouseRightTargetSet = <value>` |
| mouseRightTarget | `RootObject` | RW | `obj.mouseRightTarget = <value>` |
| rmouseTimer | `number` | RW | `obj.rmouseTimer = <value>` |
| selectedObject | `unknown` | RW | `obj.selectedObject = <value>` |
| onlyAnimalsSelected | `boolean` | RW | `obj.onlyAnimalsSelected = <value>` |
| selectedLoadedLeft | `integer` | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterHandle | `unknown` | RW | `obj.trackedCharacterHandle = <value>` |
| trackedCharacterFloor | `integer` | RW | `obj.trackedCharacterFloor = <value>` |
| levelEditor | `LevelEditor` | RW | `obj.levelEditor = <value>` |
| participant | `Faction` | RW | `obj.participant = <value>` |
| currentPlatoon | `Platoon` | RW | `obj.currentPlatoon = <value>` |
| deadPlayerSquad | `unknown` | RW | `obj.deadPlayerSquad = <value>` |
| placementObject | `lightuserdata` | RW | `obj.placementObject = <value>` |
| characterEditorMode | `boolean` | RW | `obj.characterEditorMode = <value>` |
| mLeftUp | `boolean` | RW | `obj.mLeftUp = <value>` |
| mLeftDown | `boolean` | RW | `obj.mLeftDown = <value>` |
| mRightUp | `boolean` | RW | `obj.mRightUp = <value>` |
| mRightDown | `boolean` | RW | `obj.mRightDown = <value>` |
| interiorsVisible | `ogre_unordered_set<hand>::type` | RW | `obj.interiorsVisible = <value>` |
| playerCharacters | `lektor<Character*>` | RW | `obj.playerCharacters = <value>` |
| selectedCharacters | `ogre_unordered_set<hand>::type` | RW | `obj.selectedCharacters = <value>` |
| townsActive | `ogre_unordered_set<TownBase*>::type` | RW | `obj.townsActive = <value>` |
| zonesVisibilities | `unknown` | RW | `obj.zonesVisibilities = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getCamera | Instance | `` | `CameraClass` | `obj:getCamera()` |
| playerSetup | Instance | `` | `void` | `obj:playerSetup()` |
| clearAndReset | Instance | `` | `void` | `obj:clearAndReset()` |
| factoryObjectCreatedCallback | Instance | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| getFaction | Instance | `` | `Faction` | `obj:getFaction()` |
| setCurrentPlatoon | Instance | `` | `boolean` | `obj:setCurrentPlatoon()` |
| getCurrentPlatoon | Instance | `` | `Platoon` | `obj:getCurrentPlatoon()` |
| getCurrentActivePlatoon | Instance | `` | `RootObjectContainer` | `obj:getCurrentActivePlatoon()` |
| createSquad | Instance | `` | `ActivePlatoon` | `obj:createSquad()` |
| getDeadSquad | Instance | `` | `ActivePlatoon` | `obj:getDeadSquad()` |
| update | Instance | `` | `void` | `obj:update()` |
| updateUT | Instance | `` | `void` | `obj:updateUT()` |
| isBuildMode | Instance | `` | `boolean` | `obj:isBuildMode()` |
| activateObjectPlacementMode | Instance | `` | `void` | `obj:activateObjectPlacementMode()` |
| activateCharacterEditMode | Instance | `` | `void` | `obj:activateCharacterEditMode()` |
| triggerAreaArrivalDialogue | Instance | `` | `boolean` | `obj:triggerAreaArrivalDialogue()` |
| setCharacterEditMode | Instance | `on: boolean` | `void` | `obj:setCharacterEditMode(on)` |
| getCharacterEditMode | Instance | `` | `boolean` | `obj:getCharacterEditMode()` |
| unselectAll | Instance | `` | `void` | `obj:unselectAll()` |
| selectAll | Instance | `` | `void` | `obj:selectAll()` |
| selectObject | Instance | `modifier: boolean` | `void` | `obj:selectObject(modifier)` |
| selectPlayerCharacter | Instance | `index: integer, modifier: boolean, track: boolean` | `void` | `obj:selectPlayerCharacter(index, modifier, track)` |
| _selectPlayerCharacter | Instance | `modifier: boolean, track: boolean` | `void` | `obj:_selectPlayerCharacter(modifier, track)` |
| activateSelection | Instance | `` | `void` | `obj:activateSelection()` |
| getCameraCenter | Instance | `` | `Vector3` | `obj:getCameraCenter()` |
| getDistanceFromCamera | Instance | `v: Vector3` | `number` | `obj:getDistanceFromCamera(v)` |
| getSquaredDistanceFromCamera | Instance | `v: Vector3` | `number` | `obj:getSquaredDistanceFromCamera(v)` |
| startTrackCharacter | Instance | `` | `void` | `obj:startTrackCharacter()` |
| stopTrackCharacter | Instance | `` | `void` | `obj:stopTrackCharacter()` |
| isTrackingCharacter | Instance | `` | `boolean` | `obj:isTrackingCharacter()` |
| focusCamera | Instance | `pos: Vector3` | `void` | `obj:focusCamera(pos)` |
| manuallyOrientCamera | Instance | `rot: Quaternion, zoom: number` | `void` | `obj:manuallyOrientCamera(rot, zoom)` |
| focusCameraSelectedCharacter | Instance | `` | `void` | `obj:focusCameraSelectedCharacter()` |
| toggleLevelEditorOnSelectedTown | Instance | `` | `void` | `obj:toggleLevelEditorOnSelectedTown()` |
| isLevelEditMode | Instance | `` | `boolean` | `obj:isLevelEditMode()` |
| isObjectPlacementMode | Instance | `` | `boolean` | `obj:isObjectPlacementMode()` |
| setOrderSelectedCharacters | Instance | `order: integer` | `void` | `obj:setOrderSelectedCharacters(order)` |
| getLevelEditor | Instance | `` | `LevelEditor` | `obj:getLevelEditor()` |
| objectSelected | Instance | `select: boolean` | `void` | `obj:objectSelected(select)` |
| toggleObjectSelected | Instance | `` | `void` | `obj:toggleObjectSelected()` |
| isObjectSelected | Instance | `` | `boolean` | `obj:isObjectSelected()` |
| unselectPlayerCharacter | Instance | `` | `void` | `obj:unselectPlayerCharacter()` |
| getCurrentFloor | Instance | `` | `integer` | `obj:getCurrentFloor()` |
| setCurrentFloor | Instance | `floor: integer` | `void` | `obj:setCurrentFloor(floor)` |
| getNearestSelectedCharacterTo | Instance | `pos: Vector3` | `Character` | `obj:getNearestSelectedCharacterTo(pos)` |
| getNearestCharacterTo | Instance | `pos: Vector3` | `Character` | `obj:getNearestCharacterTo(pos)` |
| addOrderSelectedCharacters | Instance | `task: integer, shift: boolean, addDontClear: boolean, location: Vector3` | `void` | `obj:addOrderSelectedCharacters(task, shift, addDontClear, location)` |
| addJobSelectedCharacters | Instance | `task: integer, shift: boolean, add: boolean, location: Vector3` | `void` | `obj:addJobSelectedCharacters(task, shift, add, location)` |
| removeJobSelectedCharacters | Instance | `t: integer` | `void` | `obj:removeJobSelectedCharacters(t)` |
| removePermaJobSelectedCharacters | Instance | `id: integer` | `void` | `obj:removePermaJobSelectedCharacters(id)` |
| selectedCharactersUnconcious | Instance | `displayMessage: boolean` | `boolean` | `obj:selectedCharactersUnconcious(displayMessage)` |
| selectedCharactersLayingLow | Instance | `` | `boolean` | `obj:selectedCharactersLayingLow()` |
| useSpeedGroup | Instance | `use: boolean` | `void` | `obj:useSpeedGroup(use)` |
| assignSpeedGroup | Instance | `create: boolean` | `void` | `obj:assignSpeedGroup(create)` |
| isEnemy | Instance | `` | `boolean` | `obj:isEnemy()` |
| isFactionKnown | Instance | `` | `boolean` | `obj:isFactionKnown()` |
| encounterFaction | Instance | `` | `void` | `obj:encounterFaction()` |
| pickupItem | Instance | `` | `void` | `obj:pickupItem()` |
| cycleSquad | Instance | `` | `void` | `obj:cycleSquad()` |
| cycleCharacter | Instance | `d: integer` | `void` | `obj:cycleCharacter(d)` |
| stopCharactersMovement | Instance | `` | `void` | `obj:stopCharactersMovement()` |
| getAnyPlayerCharacter | Instance | `` | `Character` | `obj:getAnyPlayerCharacter()` |
| isOrderValidForSelection | Instance | `task: integer` | `boolean` | `obj:isOrderValidForSelection(task)` |
| serialise | Instance | `` | `void` | `obj:serialise()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| getInteriorsVisible | Instance | `` | `boolean` | `obj:getInteriorsVisible()` |
| setVisibilityForReflections | Instance | `set: boolean` | `void` | `obj:setVisibilityForReflections(set)` |
| resetFloorsVisibility | Instance | `` | `void` | `obj:resetFloorsVisibility()` |
| setFloorsVisibility | Instance | `floor: integer` | `void` | `obj:setFloorsVisibility(floor)` |
| addTaskNearestSelectedCharacter | Instance | `t: integer, shift: boolean, location: Vector3, noAnimals: boolean` | `void` | `obj:addTaskNearestSelectedCharacter(t, shift, location, noAnimals)` |
| updateLastMoveWaypointSelectedCharacters | Instance | `location: Vector3` | `void` | `obj:updateLastMoveWaypointSelectedCharacters(location)` |
| clearSelection | Instance | `` | `void` | `obj:clearSelection()` |
| mouseScan | Instance | `` | `void` | `obj:mouseScan()` |
| characterSelected | Instance | `` | `void` | `obj:characterSelected()` |
| itemSelected | Instance | `` | `void` | `obj:itemSelected()` |
| buildingSelected | Instance | `position: Vector3, interiorsVisible: boolean` | `boolean` | `obj:buildingSelected(position, interiorsVisible)` |
| playerMove | Instance | `pos: Vector3` | `void` | `obj:playerMove(pos)` |
| _isPlayerCharacter | Instance | `` | `boolean` | `obj:_isPlayerCharacter()` |
| recruit [1] | Instance | `characters: lektor<Character*>, editor: boolean` | `boolean` | `obj:recruit(characters, editor)` |
| recruit [2] | Instance | `character: Character, editor: boolean` | `boolean` | `obj:recruit(character, editor)` |
| getDeadSquadHandle | Instance | `` | `hand` | `obj:getDeadSquadHandle()` |
| updatePlayerSelection | Instance | `` | `void` | `obj:updatePlayerSelection()` |
| getAllSelectedObjects | Instance | `type: integer` | `void` | `obj:getAllSelectedObjects(type)` |
| newPlayerTaskSelectedCharacters | Instance | `t: integer, clickpos: Vector3, addDontClear: boolean` | `void` | `obj:newPlayerTaskSelectedCharacters(t, clickpos, addDontClear)` |
| getPlayerTaskProbability | Instance | `task: integer` | `boolean\|number` | `obj:getPlayerTaskProbability(task)` |
| getAllPlayerCharacters [1] | Instance | `list: lektor<RootObject*>` | `void` | `obj:getAllPlayerCharacters(list)` |
| getAllPlayerCharacters [2] | Instance | `` | `lektor<Character*>` | `obj:getAllPlayerCharacters()` |
| updateFloorVisibility | Instance | `` | `void` | `obj:updateFloorVisibility()` |
| playerControl | Instance | `` | `void` | `obj:playerControl()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| load | Instance | `` | `void` | `obj:load()` |
| save | Instance | `` | `void` | `obj:save()` |

## PortraitData
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| name | `string` | RW | `obj.name = <value>` |
| flashing | `integer` | RW | `obj.flashing = <value>` |
| state | `integer` | RW | `obj.state = <value>` |
| reloadPortrait | `boolean` | RW | `obj.reloadPortrait = <value>` |
| characterHandle | `unknown` | RW | `obj.characterHandle = <value>` |
| updateRequested | `boolean` | RW | `obj.updateRequested = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| forceUpdate | Instance | `` | `void` | `obj:forceUpdate()` |
| isSelected | Instance | `` | `boolean` | `obj:isSelected()` |
| isDown | Instance | `` | `boolean` | `obj:isDown()` |
| getBackgroundImageName | Instance | `` | `string` | `obj:getBackgroundImageName()` |
| getBackOverlayImageName | Instance | `` | `string` | `obj:getBackOverlayImageName()` |
| getFrontOverlayImageName | Instance | `` | `string` | `obj:getFrontOverlayImageName()` |

## PortraitImage
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitImage`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| index | `integer` | RW | `obj.index = <value>` |
| created | `boolean` | RW | `obj.created = <value>` |
| textureName | `string` | RW | `obj.textureName = <value>` |

## PortraitMainCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Metatable:** `KenshiLua.PortraitMainCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| characterHandle | `unknown` | RW | `obj.characterHandle = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| border | `lightuserdata` | R | `obj.border` |
| imageBackground | `lightuserdata` | R | `obj.imageBackground` |
| imagePortrait | `lightuserdata` | R | `obj.imagePortrait` |
| imageOverlayBack | `lightuserdata` | R | `obj.imageOverlayBack` |
| imageOverlayFront | `lightuserdata` | R | `obj.imageOverlayFront` |
| textName | `lightuserdata` | R | `obj.textName` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| resize | Instance | `size: integer` | `void` | `obj:resize(size)` |
| setName | Instance | `newName: string` | `void` | `obj:setName(newName)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| init | Instance | `` | `void` | `obj:init()` |
| destroy | Instance | `` | `void` | `obj:destroy()` |
| setUpdateEnabled | Instance | `enabled: boolean` | `void` | `obj:setUpdateEnabled(enabled)` |
| reloadPortraits | Instance | `` | `void` | `obj:reloadPortraits()` |
| reloadTexture | Instance | `` | `void` | `obj:reloadTexture()` |
| saveTexture | Instance | `` | `void` | `obj:saveTexture()` |
| clearPortraits | Instance | `loadTexture: boolean` | `void` | `obj:clearPortraits(loadTexture)` |
| getCharacterFlashing | Instance | `` | `boolean` | `obj:getCharacterFlashing()` |
| getCharacterInCombat | Instance | `` | `boolean` | `obj:getCharacterInCombat()` |
| getCharacterDown | Instance | `` | `boolean` | `obj:getCharacterDown()` |
| getSquadFlashing | Instance | `` | `boolean` | `obj:getSquadFlashing()` |
| getPortrait | Instance | `` | `PortraitData` | `obj:getPortrait()` |
| updatePortrait | Instance | `` | `void` | `obj:updatePortrait()` |
| updatePortraitImage | Instance | `` | `boolean` | `obj:updatePortraitImage()` |
| setImageWidget | Instance | `imgBox: userdata, force: boolean` | `void` | `obj:setImageWidget(imgBox, force)` |
| getInstance | Static / Instance | `` | `PortraitManager` | `PortraitManager.getInstance()`<br>`obj:getInstance()` |

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
| prospectResource | `integer` | RW | `obj.prospectResource = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| type | Instance | `` | `integer` | `obj:type()` |
| checkProspectingIsNotZero | Instance | `` | `boolean` | `obj:checkProspectingIsNotZero()` |
| isASnapToBuilding | Instance | `` | `boolean` | `obj:isASnapToBuilding()` |
| isACeilingBuilding | Instance | `` | `boolean` | `obj:isACeilingBuilding()` |
| snappingOk | Instance | `` | `boolean` | `obj:snappingOk()` |
| isInteriorBuilding | Instance | `` | `boolean` | `obj:isInteriorBuilding()` |
| isCurrent | Instance | `` | `boolean` | `obj:isCurrent()` |
| setup | Instance | `` | `boolean` | `obj:setup()` |
| _destroyEnts | Instance | `` | `void` | `obj:_destroyEnts()` |
| update | Instance | `` | `void` | `obj:update()` |
| figureOutWhichTown | Instance | `` | `void` | `obj:figureOutWhichTown()` |
| setVisualPosition | Instance | `position: Vector3` | `void` | `obj:setVisualPosition(position)` |
| yawBy | Instance | `pan: number` | `void` | `obj:yawBy(pan)` |
| yawSet | Instance | `pan: number` | `void` | `obj:yawSet(pan)` |
| rotateBy | Instance | `by: Quaternion` | `void` | `obj:rotateBy(by)` |
| tilt | Instance | `pan: number` | `void` | `obj:tilt(pan)` |
| roll | Instance | `pan: number` | `void` | `obj:roll(pan)` |
| setRotation | Instance | `r: Quaternion` | `void` | `obj:setRotation(r)` |
| allFootprintsWantBelowGround | Instance | `` | `boolean` | `obj:allFootprintsWantBelowGround()` |
| allFootprintsWantAboveGround | Instance | `` | `boolean` | `obj:allFootprintsWantAboveGround()` |
| updateFootprintHeights | Instance | `` | `boolean` | `obj:updateFootprintHeights()` |
| isCollisionOK | Instance | `` | `boolean` | `obj:isCollisionOK()` |
| isFloorOk | Instance | `` | `boolean` | `obj:isFloorOk()` |
| isIndoorsOk | Instance | `` | `boolean` | `obj:isIndoorsOk()` |
| isNodesOk | Instance | `` | `boolean` | `obj:isNodesOk()` |
| isBlockingBuildingsNodes | Instance | `` | `boolean` | `obj:isBlockingBuildingsNodes()` |
| isGoodAboveAndBelow | Instance | `` | `boolean` | `obj:isGoodAboveAndBelow()` |
| isOnValidGround | Instance | `` | `boolean` | `obj:isOnValidGround()` |
| isLinked | Instance | `` | `boolean` | `obj:isLinked()` |
| moveHeightOffset | Instance | `h: number` | `void` | `obj:moveHeightOffset(h)` |
| resetHeightOffset | Instance | `` | `void` | `obj:resetHeightOffset()` |
| getFootprintShift | Instance | `` | `number` | `obj:getFootprintShift()` |
| setOrientation | Instance | `q: Quaternion` | `void` | `obj:setOrientation(q)` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getFloor | Instance | `` | `integer` | `obj:getFloor()` |
| setStartPosition | Instance | `p: Vector3` | `void` | `obj:setStartPosition(p)` |
| setEndPosition | Instance | `position: Vector3` | `void` | `obj:setEndPosition(position)` |
| getEndPos | Instance | `` | `Vector3` | `obj:getEndPos()` |
| clearPointersTo | Instance | `` | `void` | `obj:clearPointersTo()` |
| placeFinalPreviewBuilding | Instance | `` | `void` | `obj:placeFinalPreviewBuilding()` |
| insideBuilding | Instance | `` | `Building` | `obj:insideBuilding()` |
| placementVerification | Instance | `` | `boolean` | `obj:placementVerification()` |
| getGameData | Instance | `` | `GameData` | `obj:getGameData()` |
| noAltitude | Instance | `` | `boolean` | `obj:noAltitude()` |
| noPathfindingNeeded | Instance | `` | `boolean` | `obj:noPathfindingNeeded()` |
| placePreview | Instance | `position: Vector3, rotation: Quaternion, floorNumber: integer` | `void` | `obj:placePreview(position, rotation, floorNumber)` |
| resetUseageNodes | Instance | `` | `void` | `obj:resetUseageNodes()` |
| calculateRotationsAndStuff | Instance | `position: Vector3` | `void` | `obj:calculateRotationsAndStuff(position)` |
| placementVerification_recurse | Instance | `` | `boolean` | `obj:placementVerification_recurse()` |
| getTerrainHeightAtCenter | Instance | `` | `number` | `obj:getTerrainHeightAtCenter()` |
| recalculateWorldAABB | Instance | `` | `void` | `obj:recalculateWorldAABB()` |
| validateUsageNodes | Instance | `` | `void` | `obj:validateUsageNodes()` |
| getPlacementResultMaterialName | Static / Instance | `` | `void` | `PreviewBuilding.getPlacementResultMaterialName()`<br>`obj:getPlacementResultMaterialName()` |
| getOrientation | Instance | `` | `Quaternion` | `obj:getOrientation()` |
| getCentreOffset | Instance | `` | `Vector3` | `obj:getCentreOffset()` |
| isNoCollideWithThisBuilding [1] | Instance | `what: RootObject, shape: NxShape, node: boolean` | `boolean` | `obj:isNoCollideWithThisBuilding(what, shape, node)` |
| isNoCollideWithThisBuilding [2] | Instance | `what: PreviewBuilding` | `boolean` | `obj:isNoCollideWithThisBuilding(what)` |

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
| groundType | `integer` | RW | `obj.groundType = <value>` |
| valid | `boolean` | RW | `obj.valid = <value>` |
| parent | `PreviewBuilding` | RW | `obj.parent = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getSpace | Instance | `` | `number` | `obj:getSpace()` |
| getMarker | Instance | `` | `number` | `obj:getMarker()` |
| setValid | Instance | `value: boolean` | `void` | `obj:setValid(value)` |
| getValid | Instance | `` | `boolean` | `obj:getValid()` |
| validate | Instance | `` | `boolean` | `obj:validate()` |
| fakeOppositeValidate | Instance | `gap: number` | `boolean` | `obj:fakeOppositeValidate(gap)` |
| collisionTestBuildings | Instance | `isFurniture: boolean, currentFloor: integer` | `boolean` | `obj:collisionTestBuildings(isFurniture, currentFloor)` |
| collisionTestCharacters | Instance | `` | `boolean` | `obj:collisionTestCharacters()` |
| validFloorTest | Instance | `` | `boolean` | `obj:validFloorTest()` |
| isIndoorsOK | Instance | `isFurniture: boolean` | `boolean` | `obj:isIndoorsOK(isFurniture)` |
| isGroundValid | Instance | `` | `boolean` | `obj:isGroundValid()` |
| getWorldCorner | Instance | `corner: integer` | `Vector3` | `obj:getWorldCorner(corner)` |
| updateBox | Instance | `` | `void` | `obj:updateBox()` |
| getGroundHeight | Instance | `pos: Vector3` | `number` | `obj:getGroundHeight(pos)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateBox | Instance | `` | `void` | `obj:updateBox()` |
| setEnabled | Instance | `value: boolean` | `void` | `obj:setEnabled(value)` |

## ProductionBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`
**Metatable:** `KenshiLua.ProductionBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| productionState | `integer` | RW | `obj.productionState = <value>` |
| _resourceMiningLevel | `number` | RW | `obj._resourceMiningLevel = <value>` |
| outSection | `InventorySection` | RW | `obj.outSection = <value>` |
| consumptionItems | `lektor<StorageBuilding::ConsumptionItem>` | RW | `obj.consumptionItems = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getProductionBuilding | Instance | `` | `ProductionBuilding` | `obj:getProductionBuilding()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| update | Instance | `` | `void` | `obj:update()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |
| getProductionMult | Instance | `` | `number` | `obj:getProductionMult()` |
| getProductionMultForGUI | Instance | `` | `number` | `obj:getProductionMultForGUI()` |
| setupMiningResourceLevel | Instance | `` | `void` | `obj:setupMiningResourceLevel()` |
| getMiningResourceLevel | Instance | `` | `number` | `obj:getMiningResourceLevel()` |
| getMouseCursor | Instance | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| isAnyInputsEmpty | Instance | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| isAnyInputsInvalidType | Instance | `` | `boolean` | `obj:isAnyInputsInvalidType()` |
| isAnyInputsFull | Instance | `` | `boolean` | `obj:isAnyInputsFull()` |
| isProductionFull | Instance | `` | `boolean` | `obj:isProductionFull()` |
| isProductionEmpty | Instance | `` | `boolean` | `obj:isProductionEmpty()` |
| getOutputBasedRotationSpeedMult | Instance | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| getOutput | Instance | `` | `number` | `obj:getOutput()` |
| getNumConsumtionItems | Instance | `` | `integer` | `obj:getNumConsumtionItems()` |
| getConsumtionItems | Instance | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| setupFromData | Instance | `` | `void` | `obj:setupFromData()` |
| updateInventoryWindow | Instance | `` | `void` | `obj:updateInventoryWindow()` |
| updateInputs | Instance | `rate: number` | `void` | `obj:updateInputs(rate)` |
| updateOutput | Instance | `rate: number` | `void` | `obj:updateOutput(rate)` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| limitInputsOutputRate | Instance | `rate: number` | `boolean\|number` | `obj:limitInputsOutputRate(rate)` |

## ProductionInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ProductionBuilding.h`
**Metatable:** `KenshiLua.ProductionInventoryLayout`

## ProspectingWindow
**Header:** `extern/KenshiLib/Include/kenshi/gui/ProspectingWindow.h`
**Metatable:** `KenshiLua.ProspectingWindow`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| window | `lightuserdata` | R | `obj.window` |
| imgMap | `lightuserdata` | R | `obj.imgMap` |
| listResourcesPanel | `lightuserdata` | R | `obj.listResourcesPanel` |
| listResourcesSelected | `lightuserdata` | R | `obj.listResourcesSelected` |
| cameraMarker | `lightuserdata` | R | `obj.cameraMarker` |
| cameraMarkerSkin | `lightuserdata` | R | `obj.cameraMarkerSkin` |
| datapanelOverview1 | `DatapanelGUI` | RW | `obj.datapanelOverview1 = <value>` |
| datapanelOverview2 | `DatapanelGUI` | RW | `obj.datapanelOverview2 = <value>` |
| resourceImage | `lightuserdata` | R | `obj.resourceImage` |
| lastPos | `Vector3` | RW | `obj.lastPos = <value>` |
| lastSkill | `number` | RW | `obj.lastSkill = <value>` |
| lastName | `string` | RW | `obj.lastName = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| showT | Instance | `pos: Vector3, skill: number, name: string` | `void` | `obj:showT(pos, skill, name)` |
| _show | Instance | `` | `void` | `obj:_show()` |
| hide | Instance | `` | `void` | `obj:hide()` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| updateCameraMarker | Instance | `` | `void` | `obj:updateCameraMarker()` |
| updateMap | Instance | `resource: integer` | `void` | `obj:updateMap(resource)` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| clear | Instance | `` | `void` | `obj:clear()` |
| worldToMapCoords | Instance | `pos: Vector3` | `void` | `obj:worldToMapCoords(pos)` |
| getSingleton | Static / Instance | `` | `ProspectingWindow` | `ProspectingWindow.getSingleton()`<br>`obj:getSingleton()` |

## ProspectingWindow::ResourceLinePanel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ManagementScreen.h`
**Parent Class:** [`ProspectingWindow`](#prospectingwindow)
**Metatable:** `KenshiLua.ResourceLinePanel`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| button | `MyGUI::Widget` | R | `obj.button` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getWidget | Instance | `` | `MyGUI::Widget` | `obj:getWidget()` |

## ProsperityManager
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`
**Metatable:** `KenshiLua.ProsperityManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| actualProsperity | `number` | RW | `obj.actualProsperity = <value>` |
| maxProsperity | `number` | RW | `obj.maxProsperity = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setup | Instance | `` | `void` | `obj:setup()` |
| load | Instance | `` | `void` | `obj:load()` |
| save | Instance | `` | `void` | `obj:save()` |
| getProsperityMultiplier | Instance | `` | `number` | `obj:getProsperityMultiplier()` |
| getGUIData | Instance | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| update | Instance | `time: number` | `void` | `obj:update(time)` |
| notifySquadDefeated | Instance | `` | `void` | `obj:notifySquadDefeated()` |
| notifySpecialNPCDead | Instance | `` | `void` | `obj:notifySpecialNPCDead()` |

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
| firstAidSkill | `integer` | RW | `obj.firstAidSkill = <value>` |
| canGoIndoors | `boolean` | RW | `obj.canGoIndoors = <value>` |
| raceGroup | `lightuserdata` | RW | `obj.raceGroup = <value>` |
| bloodColour | `unknown` | RW | `obj.bloodColour = <value>` |
| specialFoods | `ogre_unordered_set<GameData*>::type` | RW | `obj.specialFoods = <value>` |
| statMods | `unknown` | RW | `obj.statMods = <value>` |
| weatherImmunities | `ogre_unordered_set<WeatherAffecting>::type` | RW | `obj.weatherImmunities = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getRaceData [1] | Instance | `stringID: string` | `RaceData` | `obj:getRaceData(stringID)` |
| getRaceData [2] | Instance | `data: GameData` | `RaceData` | `obj:getRaceData(data)` |
| isRelatedRace [1] | Instance | `data: RaceData` | `boolean` | `obj:isRelatedRace(data)` |
| isRelatedRace [2] | Instance | `d: GameData` | `boolean` | `obj:isRelatedRace(d)` |
| isSpecificRace | Instance | `` | `boolean` | `obj:isSpecificRace()` |
| getStatMod | Instance | `stat: integer` | `number` | `obj:getStatMod(stat)` |
| isImmune | Instance | `w: integer` | `boolean` | `obj:isImmune(w)` |
| canEat [1] | Instance | `food: GameData, isAnimal: boolean` | `boolean` | `obj:canEat(food, isAnimal)` |
| canEat [2] | Instance | `food: Item, isAnimal: boolean` | `boolean` | `obj:canEat(food, isAnimal)` |

## RaceLimiter
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`
**Metatable:** `KenshiLua.RaceLimiter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| limits | `unknown` | RW | `obj.limits = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addLimit | Instance | `` | `void` | `obj:addLimit()` |
| getSingleton | Static / Instance | `` | `RaceLimiter` | `RaceLimiter.getSingleton()`<br>`obj:getSingleton()` |
| canEquip | Instance | `isAnimal: boolean` | `boolean` | `obj:canEquip(isAnimal)` |

## RaceLimiter::Limiter
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`
**Parent Class:** [`RaceLimiter`](#racelimiter)
**Metatable:** `KenshiLua.Limiter`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| racesExclude | `unknown` | RW | `obj.racesExclude = <value>` |
| racesInclude | `unknown` | RW | `obj.racesInclude = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| canEquip | Instance | `isAnimal: boolean` | `boolean` | `obj:canEquip(isAnimal)` |

## RainCollectorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/RainCollectorBuilding.h`
**Metatable:** `KenshiLua.RainCollectorBuilding`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| calculateEfficiencyMult | Instance | `` | `number` | `obj:calculateEfficiencyMult()` |
| getRainAmount | Instance | `` | `number` | `obj:getRainAmount()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| refresh | Instance | `force: boolean` | `void` | `obj:refresh(force)` |
| notifyEndDrop | Instance | `sender: integer, info: integer, result: boolean` | `void` | `obj:notifyEndDrop(sender, info, result)` |
| notifyRemoved | Instance | `index: integer` | `void` | `obj:notifyRemoved(index)` |

## ResearchBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`
**Metatable:** `KenshiLua.ResearchBuilding`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| dontNeedWorkRightNow | Instance | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| update | Instance | `` | `void` | `obj:update()` |
| notifyConstructionComplete | Instance | `` | `void` | `obj:notifyConstructionComplete()` |
| getTechLevel | Instance | `` | `integer` | `obj:getTechLevel()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |

## ResearchBuildingInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/Building/ResearchBuilding.h`
**Metatable:** `KenshiLua.ResearchBuildingInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| researchButton | `MyGUI::Widget` | RW | `obj.researchButton = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getResearchButton | Instance | `` | `MyGUI::Widget` | `obj:getResearchButton()` |
| setupSections | Instance | `inventoryGUI: userdata, sections: userdata, inventory: userdata` | `void` | `obj:setupSections(inventoryGUI, sections, inventory)` |

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
| texturesLoading | `TextureLoadDataFastArrayBinding::ArrayType` | RW | `obj.texturesLoading = <value>` |
| texturesLoaded | `TextureLoadDataFastArrayBinding::ArrayType` | RW | `obj.texturesLoaded = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateMT | Instance | `` | `void` | `obj:updateMT()` |
| updateBT | Instance | `` | `boolean` | `obj:updateBT()` |
| isLoading | Instance | `` | `boolean` | `obj:isLoading()` |
| init | Instance | `` | `void` | `obj:init()` |
| threadProc | Instance | `` | `integer` | `obj:threadProc()` |
| getInstance | Static / Instance | `` | `void` | `ResourceLoader.getInstance()`<br>`obj:getInstance()` |
| destroy [1] | Instance | `material: Ogre::SharedPtr<Ogre::Material>, destroyManualTextures: boolean` | `void` | `obj:destroy(material, destroyManualTextures)` |
| destroy [2] | Instance | `entity: Ogre::InstancedEntity, destroyParent: boolean` | `void` | `obj:destroy(entity, destroyParent)` |
| destroy [3] | Instance | `obj: Ogre::MovableObject, destroyParent: boolean` | `void` | `obj:destroy(obj, destroyParent)` |
| destroy [4] | Instance | `entity: Ogre::Entity, destroyParent: boolean` | `void` | `obj:destroy(entity, destroyParent)` |
| destroy [5] | Instance | `` | `void` | `obj:destroy()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| finish | Instance | `` | `void` | `obj:finish()` |

## ResourceLoader::ResourceLoadRequestTexture
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.ResourceLoadRequestTexture`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| textureUnitState | `lightuserdata` | R | `obj.textureUnitState` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isMaterialValid | Instance | `` | `boolean` | `obj:isMaterialValid()` |

## ResourceLoader::TextureArrayLoadData
**Header:** `extern/KenshiLib/Include/kenshi/ResourceLoader.h`
**Parent Class:** [`ResourceLoader`](#resourceloader)
**Metatable:** `KenshiLua.TextureArrayLoadData`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| loadImage | Instance | `` | `void` | `obj:loadImage()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| loadImage | Instance | `` | `void` | `obj:loadImage()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| load | Instance | `` | `void` | `obj:load()` |
| save | Instance | `` | `void` | `obj:save()` |
| getLimb | Instance | `limb: integer` | `Item` | `obj:getLimb(limb)` |
| getMask | Instance | `` | `integer` | `obj:getMask()` |
| getInventoryInterface | Instance | `create: boolean` | `RootObject` | `obj:getInventoryInterface(create)` |
| destroyInventoryInterface | Instance | `` | `void` | `obj:destroyInventoryInterface()` |
| getLimbItem | Instance | `l: integer` | `Item` | `obj:getLimbItem(l)` |
| getState | Instance | `limb: integer` | `integer` | `obj:getState(limb)` |
| setLimb | Instance | `limb: integer, state: integer` | `void` | `obj:setLimb(limb, state)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`
**Metatable:** `KenshiLua.RootObject`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| container | `RootObjectContainer` | RW | `obj.container = <value>` |
| isInsideBuilding | `unknown` | RW | `obj.isInsideBuilding = <value>` |
| isInsideTownWalls | `integer` | RW | `obj.isInsideTownWalls = <value>` |
| floorNum | `integer` | RW | `obj.floorNum = <value>` |
| spacialKey | `integer` | RW | `obj.spacialKey = <value>` |
| outdoorDelayNotification_timer | `integer` | RW | `obj.outdoorDelayNotification_timer = <value>` |
| rot | `Quaternion` | RW | `obj.rot = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| needsSaving | Instance | `s: string` | `boolean` | `obj:needsSaving(s)` |
| getInstanceID | Instance | `` | `InstanceID` | `obj:getInstanceID()` |
| getOrientation | Instance | `` | `Quaternion` | `obj:getOrientation()` |
| getZoneMapLocation | Instance | `` | `ZoneMap` | `obj:getZoneMapLocation()` |
| getRace | Instance | `` | `RaceData` | `obj:getRace()` |
| threadedUpdate | Instance | `` | `void` | `obj:threadedUpdate()` |
| update | Instance | `` | `void` | `obj:update()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| isPhysical | Instance | `` | `boolean` | `obj:isPhysical()` |
| setVisible | Instance | `_a1: boolean` | `void` | `obj:setVisible(_a1)` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| isDisabled | Instance | `` | `boolean` | `obj:isDisabled()` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| amInsideTownWalls | Instance | `` | `integer` | `obj:amInsideTownWalls()` |
| setInsideTownWalls | Instance | `s: integer` | `void` | `obj:setInsideTownWalls(s)` |
| getFloor | Instance | `` | `integer` | `obj:getFloor()` |
| setFloor | Instance | `f: integer` | `void` | `obj:setFloor(f)` |
| select | Instance | `` | `void` | `obj:select()` |
| unselect | Instance | `` | `void` | `obj:unselect()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| setStandingOrder | Instance | `_a1: integer` | `void` | `obj:setStandingOrder(_a1)` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| giveItem | Instance | `dropOnFail: boolean, destroyOnFail: boolean` | `boolean` | `obj:giveItem(dropOnFail, destroyOnFail)` |
| hasRoomForItem | Instance | `` | `boolean` | `obj:hasRoomForItem()` |
| hasItem | Instance | `` | `boolean` | `obj:hasItem()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| ImStealingDoYouNotice | Instance | `` | `boolean` | `obj:ImStealingDoYouNotice()` |
| stolenGoodsDetectionCheck | Instance | `` | `boolean` | `obj:stolenGoodsDetectionCheck()` |
| equipItem | Instance | `_a1: string` | `void` | `obj:equipItem(_a1)` |
| unequipItem | Instance | `_a1: string` | `void` | `obj:unequipItem(_a1)` |
| dropItem | Instance | `` | `void` | `obj:dropItem()` |
| takeMoney | Instance | `_a1: integer` | `boolean` | `obj:takeMoney(_a1)` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| say | Instance | `_a1: string` | `void` | `obj:say(_a1)` |
| notifyOutdoors | Instance | `` | `void` | `obj:notifyOutdoors()` |
| isOnARoof | Instance | `` | `boolean` | `obj:isOnARoof()` |
| getIntendedAggression | Instance | `` | `number` | `obj:getIntendedAggression()` |
| getPlatoonAI | Instance | `` | `lightuserdata` | `obj:getPlatoonAI()` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| notifyEffect | Instance | `type: integer, what: integer, strength: number` | `void` | `obj:notifyEffect(type, what, strength)` |
| loadUnloadCheck | Instance | `` | `void` | `obj:loadUnloadCheck()` |
| isIndoors | Instance | `` | `void` | `obj:isIndoors()` |
| setIsInsideBuilding | Instance | `` | `void` | `obj:setIsInsideBuilding()` |
| getLayoutInstanceID | Instance | `` | `string` | `obj:getLayoutInstanceID()` |
| getAABB | Instance | `` | `lightuserdata` | `obj:getAABB()` |
| getGUIDataCategories | Instance | `` | `void` | `obj:getGUIDataCategories()` |
| getOrders | Instance | `` | `void` | `obj:getOrders()` |
| notifyIndoors | Instance | `` | `void` | `obj:notifyIndoors()` |
| hitByMeleeAttack | Instance | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |

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
| handle | `unknown` | RW | `obj.handle = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isValid | Instance | `` | `boolean` | `obj:isValid()` |
| getName | Instance | `` | `string` | `obj:getName()` |
| setName | Instance | `name: string` | `void` | `obj:setName(name)` |
| getGameData | Instance | `` | `GameData` | `obj:getGameData()` |
| getDataType | Instance | `` | `integer` | `obj:getDataType()` |
| typeIsAnItem | Instance | `` | `boolean` | `obj:typeIsAnItem()` |
| isUnconcious | Instance | `` | `boolean` | `obj:isUnconcious()` |
| getPositionForWaypoint | Instance | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getMovementSpeed | Instance | `` | `number` | `obj:getMovementSpeed()` |
| getMovementDirection | Instance | `` | `Vector3` | `obj:getMovementDirection()` |
| getFaction | Instance | `` | `Faction` | `obj:getFaction()` |
| hasFaction | Instance | `` | `boolean` | `obj:hasFaction()` |
| getFloor | Instance | `` | `integer` | `obj:getFloor()` |
| getSensoryData | Instance | `` | `SensoryData` | `obj:getSensoryData()` |
| getStateBroadcast | Instance | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getCurrentTownLocation | Instance | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| getOwnerships | Instance | `` | `Ownerships` | `obj:getOwnerships()` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| getHandle | Instance | `` | `void` | `obj:getHandle()` |
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |

## RootObjectContainer
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`
**Metatable:** `KenshiLua.RootObjectContainer`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| things | `lektor<RootObject*>` | RW | `obj.things = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| addActiveObject | Instance | `` | `boolean` | `obj:addActiveObject()` |
| removeObject | Instance | `` | `boolean` | `obj:removeObject()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| getThing | Instance | `id: integer` | `RootObject` | `obj:getThing(id)` |
| getNumThings | Instance | `` | `integer` | `obj:getNumThings()` |
| getThings | Instance | `` | `lektor<RootObject*>` | `obj:getThings()` |
| loadToReality | Instance | `skipSaveState: boolean, positionMoved: Vector3, rotOffset: Quaternion, specificSID: string` | `void` | `obj:loadToReality(skipSaveState, positionMoved, rotOffset, specificSID)` |
| getSelectedObjects | Instance | `type: integer, selectedOnly: boolean` | `void` | `obj:getSelectedObjects(type, selectedOnly)` |
| serialiseThings [1] | Instance | `_things: lektor<RootObject*>, outputToInstanceCollectionOfSomeKind: GameData, source: GameDataContainer, offsetPosToSubtract: PosRotPair, mod: string` | `void` | `obj:serialiseThings(_things, outputToInstanceCollectionOfSomeKind, source, offsetPosToSubtract, mod)` |
| serialiseThings [2] | Instance | `outputToInstanceCollectionOfSomeKind: GameData, source: GameDataContainer, offsetPosToSubtract: PosRotPair, mod: string` | `void` | `obj:serialiseThings(outputToInstanceCollectionOfSomeKind, source, offsetPosToSubtract, mod)` |
| loadInstance | Instance | `skipSaveState: boolean, pos: Vector3, rot: Quaternion, positionMoved: Vector3` | `void` | `obj:loadInstance(skipSaveState, pos, rot, positionMoved)` |

## RootObjectContainer::SpecificItemLoadFirst
**Header:** `extern/KenshiLib/Include/kenshi/RootObject.h`
**Parent Class:** [`RootObjectContainer`](#rootobjectcontainer)
**Metatable:** `KenshiLua.SpecificItemLoadFirst`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| baseTypes | `integer` | RW | `obj.baseTypes = <value>` |
| stateEnum | `integer` | RW | `obj.stateEnum = <value>` |
| specificProperty | `string` | RW | `obj.specificProperty = <value>` |
| desiredSpecificProperty | `boolean` | RW | `obj.desiredSpecificProperty = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| shouldSkip | Instance | `` | `boolean` | `obj:shouldSkip()` |
| flip | Instance | `` | `void` | `obj:flip()` |

## RootObjectFactory
**Header:** `extern/KenshiLib/Include/kenshi/RootObjectFactory.h`
**Metatable:** `KenshiLua.RootObjectFactory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| mutex | `unknown` | RW | `obj.mutex = <value>` |
| todoList | `CreatelistItemDequeBinding::DequeType` | RW | `obj.todoList = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| create | Instance | `position: Vector3, isFromActiveLevelMod: boolean, rotation: Quaternion, invisible: boolean, age: number` | `RootObjectBase` | `obj:create(position, isFromActiveLevelMod, rotation, invisible, age)` |
| createLocationNode | Instance | `addToNodeListAutomatically: boolean, position: Vector3, rotation: Quaternion, nodeId: string` | `lightuserdata` | `obj:createLocationNode(addToNodeListAutomatically, position, rotation, nodeId)` |
| copyItem | Instance | `` | `Item` | `obj:copyItem()` |
| chooseDataFromList | Instance | `listName: string, materialDataType: integer, useVal012: integer` | `GameData` | `obj:chooseDataFromList(listName, materialDataType, useVal012)` |
| chooseDataFromListWithVals | Instance | `listName: string, materialDataType: integer, useVal012: integer` | `GameDataReference` | `obj:chooseDataFromListWithVals(listName, materialDataType, useVal012)` |
| createCharacterForBuilding | Instance | `` | `void` | `obj:createCharacterForBuilding()` |
| createRandomCharacter | Instance | `position: Vector3, age: number` | `RootObject` | `obj:createRandomCharacter(position, age)` |
| mainThreadUpdate | Instance | `` | `void` | `obj:mainThreadUpdate()` |
| populateBuilding | Instance | `` | `void` | `obj:populateBuilding()` |
| process | Instance | `o: userdata` | `RootObjectBase` | `obj:process(o)` |
| createBuilding | Instance | `position: Vector3, rotation: Quaternion, furnitureOf: userdata, invisible: boolean, completed: boolean, isFoliage: boolean, floorNumber: integer, isOutsideFurniture: boolean` | `Building` | `obj:createBuilding(position, rotation, furnitureOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture)` |
| createItem [1] | Instance | `gd: GameData, handle: hand, weaponMesh: GameData, matData: GameData, levelOverride: integer, flagUniform: Faction` | `Item` | `obj:createItem(gd, handle, weaponMesh, matData, levelOverride, flagUniform)` |
| createItem [2] | Instance | `itemState: GameData` | `Item` | `obj:createItem(itemState)` |
| getValsFromDataInList | Instance | `listName: string` | `void` | `obj:getValsFromDataInList(listName)` |
| createRandomUnloadedCharacter | Instance | `platoon: userdata, position: Vector3` | `void` | `obj:createRandomUnloadedCharacter(platoon, position)` |
| createRandomSquad | Instance | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, sizeMultiplier: number, squadType: integer, isJustARefresh: boolean` | `Platoon` | `obj:createRandomSquad(position, maxnum, maparea, permanentsquad, sizeMultiplier, squadType, isJustARefresh)` |
| createRandomUnloadedSquad | Instance | `position: Vector3, maxnum: integer, maparea: userdata, permanentsquad: boolean, squadType: integer` | `Platoon` | `obj:createRandomUnloadedSquad(position, maxnum, maparea, permanentsquad, squadType)` |
| chooseMyClothing | Static / Instance | `` | `void` | `RootObjectFactory.chooseMyClothing()`<br>`obj:chooseMyClothing()` |
| _chooseClothingItemFromList | Static / Instance | `` | `GameData` | `RootObjectFactory._chooseClothingItemFromList()`<br>`obj:_chooseClothingItemFromList()` |

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
| savingIcon | `lightuserdata` | R | `obj.savingIcon` |
| state | `integer` | RW | `obj.state = <value>` |
| failedToCopyError | `string` | RW | `obj.failedToCopyError = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| log | Instance | `message: string, level: integer` | `void` | `obj:log(message, level)` |
| setTemporaryPath | Instance | `path: string` | `void` | `obj:setTemporaryPath(path)` |
| fileExists | Instance | `name: string` | `boolean` | `obj:fileExists(name)` |
| readFile | Instance | `name: string` | `string` | `obj:readFile(name)` |
| writeFile | Instance | `name: string` | `string` | `obj:writeFile(name)` |
| deleteFile | Instance | `name: string` | `void` | `obj:deleteFile(name)` |
| newGame | Instance | `` | `void` | `obj:newGame()` |
| loadGame | Instance | `savePath: string` | `void` | `obj:loadGame(savePath)` |
| saveGame | Instance | `savePath: string` | `boolean` | `obj:saveGame(savePath)` |
| sync | Instance | `` | `void` | `obj:sync()` |
| analyse | Instance | `` | `void` | `obj:analyse()` |
| cleanup | Instance | `full: boolean` | `void` | `obj:cleanup(full)` |
| scanForResidualTempFolders | Instance | `` | `void` | `obj:scanForResidualTempFolders()` |
| isTempFolder | Instance | `f: string` | `boolean` | `obj:isTempFolder(f)` |
| busy | Instance | `` | `boolean` | `obj:busy()` |
| createCurrent | Instance | `` | `void` | `obj:createCurrent()` |
| threadProc | Instance | `` | `integer` | `obj:threadProc()` |
| addMessage | Instance | `type: integer, src: string, dst: string` | `void` | `obj:addMessage(type, src, dst)` |
| getSingleton | Static / Instance | `` | `void` | `SaveFileSystem.getSingleton()`<br>`obj:getSingleton()` |
| getActiveSave | Instance | `` | `string` | `obj:getActiveSave()` |

## SaveFileSystem::FileMessage
**Header:** `extern/KenshiLib/Include/kenshi/SaveFileSystem.h`
**Parent Class:** [`SaveFileSystem`](#savefilesystem)
**Metatable:** `KenshiLua.SaveFileSystem_FileMessage`

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isVisible | Instance | `` | `integer` | `obj:isVisible()` |
| showSave | Instance | `` | `void` | `obj:showSave()` |
| showLoad | Instance | `` | `void` | `obj:showLoad()` |
| showImport | Instance | `` | `void` | `obj:showImport()` |
| hide | Instance | `` | `void` | `obj:hide()` |
| newGame | Instance | `startId: string` | `void` | `obj:newGame(startId)` |
| save | Instance | `s: string, autosave: boolean` | `void` | `obj:save(s, autosave)` |
| savesExist | Instance | `` | `boolean` | `obj:savesExist()` |
| saveExists | Instance | `location: string, name: string` | `boolean` | `obj:saveExists(location, name)` |
| execute | Instance | `` | `void` | `obj:execute()` |
| versionCode | Instance | `version: string` | `integer` | `obj:versionCode(version)` |
| updateAutoSave | Instance | `` | `void` | `obj:updateAutoSave()` |
| initialisePaths | Instance | `` | `void` | `obj:initialisePaths()` |
| saveGame | Instance | `location: string, name: string` | `integer` | `obj:saveGame(location, name)` |
| loadGame | Instance | `location: string, name: string` | `integer` | `obj:loadGame(location, name)` |
| importGame | Instance | `location: string, name: string, flags: integer` | `integer` | `obj:importGame(location, name, flags)` |
| importPlayerBuildings | Instance | `path: string, file: string` | `integer` | `obj:importPlayerBuildings(path, file)` |
| importOldPlayerBuildings | Instance | `path: string, name: string` | `integer` | `obj:importOldPlayerBuildings(path, name)` |
| getSingleton | Static / Instance | `` | `void` | `SaveManager.getSingleton()`<br>`obj:getSingleton()` |
| load [1] | Instance | `s: SaveInfo, resetPos: boolean` | `void` | `obj:load(s, resetPos)` |
| load [2] | Instance | `name: string` | `void` | `obj:load(name)` |
| import | Instance | `flags: integer` | `void` | `obj:import(flags)` |
| loadInfo | Instance | `` | `boolean` | `obj:loadInfo()` |
| checkVersion | Instance | `` | `boolean` | `obj:checkVersion()` |
| getCurrentGame | Instance | `` | `string` | `obj:getCurrentGame()` |
| getSavePath | Instance | `` | `string` | `obj:getSavePath()` |

## ScreenLabel
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`
**Metatable:** `KenshiLua.ScreenLabel`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| caption | `string` | RW | `obj.caption = <value>` |
| textWidget | `lightuserdata` | R | `obj.textWidget` |
| risingSpeed | `number` | RW | `obj.risingSpeed = <value>` |
| risingHeight | `number` | RW | `obj.risingHeight = <value>` |
| labelSize | `integer` | RW | `obj.labelSize = <value>` |
| trackingHandle | `unknown` | RW | `obj.trackingHandle = <value>` |
| trackingOffset | `Vector3` | RW | `obj.trackingOffset = <value>` |
| destroyed | `boolean` | RW | `obj.destroyed = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCaption | Instance | `value: string` | `void` | `obj:setCaption(value)` |
| setRisingSpeed | Instance | `value: integer` | `void` | `obj:setRisingSpeed(value)` |
| setPosition | Instance | `value: Vector3` | `void` | `obj:setPosition(value)` |
| update | Instance | `` | `void` | `obj:update()` |
| destroy | Instance | `` | `void` | `obj:destroy()` |

## ScreenLabelDebug
**Header:** `extern/KenshiLib/Include/kenshi/gui/ScreenLabel.h`
**Metatable:** `KenshiLua.ScreenLabelDebug`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timeLeft | `number` | RW | `obj.timeLeft = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| setVisible | Instance | `value: boolean` | `void` | `obj:setVisible(value)` |
| setPosition | Instance | `value: Vector3` | `void` | `obj:setPosition(value)` |

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
| percievedSlave | `integer` | RW | `obj.percievedSlave = <value>` |
| FOVScore | `number` | RW | `obj.FOVScore = <value>` |
| canSee | `boolean` | RW | `obj.canSee = <value>` |
| canHear | `boolean` | RW | `obj.canHear = <value>` |
| alarmState | `number` | RW | `obj.alarmState = <value>` |
| type | `integer` | RW | `obj.type = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| lastSeenInSeconds | Instance | `` | `number` | `obj:lastSeenInSeconds()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getFaction | Instance | `` | `Faction` | `obj:getFaction()` |

## SelectionBox
**Header:** `extern/KenshiLib/Include/kenshi/PlayerInterface.h`
**Metatable:** `KenshiLua.SelectionBox`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| startPos | `Vector2` | RW | `obj.startPos = <value>` |
| widget | `lightuserdata` | R | `obj.widget` |
| active | `boolean` | RW | `obj.active = <value>` |
| volume | `Ogre::PlaneBoundedVolume` | R | `obj.volume` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| start | Instance | `m: Vector2` | `void` | `obj:start(m)` |
| update | Instance | `m: Vector2` | `void` | `obj:update(m)` |
| cancel | Instance | `` | `void` | `obj:cancel()` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| contains [1] | Instance | `a: Vector3, b: Vector3, radius: number` | `boolean` | `obj:contains(a, b, radius)` |
| contains [2] | Instance | `box: Ogre::AxisAlignedBox` | `boolean` | `obj:contains(box)` |
| contains [3] | Instance | `point: Vector3, r: number` | `boolean` | `obj:contains(point, r)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| getData | Instance | `` | `SeenSomeone` | `obj:getData()` |
| ended | Instance | `` | `boolean` | `obj:ended()` |
| increment | Instance | `` | `void` | `obj:increment()` |

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
| spottedGuyIndexForProgressBar | `unknown` | RW | `obj.spottedGuyIndexForProgressBar = <value>` |
| amSharingThisFrame | `boolean` | RW | `obj.amSharingThisFrame = <value>` |
| assessList | `lightuserdata` | R | `obj.assessList` |
| flockingList | `lightuserdata` | R | `obj.flockingList` |
| hearTestTimers | `lightuserdata` | R | `obj.hearTestTimers` |
| killList | `lightuserdata` | R | `obj.killList` |
| seen | `lightuserdata` | R | `obj.seen` |
| threats | `lightuserdata` | R | `obj.threats` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| periodicUpdate | Instance | `time: number` | `void` | `obj:periodicUpdate(time)` |
| periodicUpdate_KOed | Instance | `` | `void` | `obj:periodicUpdate_KOed()` |
| getVisionRange | Instance | `inTown: boolean` | `number` | `obj:getVisionRange(inTown)` |
| update [1] | Instance | `frameTime: number` | `void` | `obj:update(frameTime)` |
| update [2] | Instance | `time: number` | `void` | `obj:update(time)` |
| notifyKO | Instance | `` | `void` | `obj:notifyKO()` |
| getIterator | Instance | `tagsAny: integer, tagsNOT: integer` | `void` | `obj:getIterator(tagsAny, tagsNOT)` |
| getNearestEnemyDistanceSq | Instance | `` | `number` | `obj:getNearestEnemyDistanceSq()` |
| canISeeThisGuy | Instance | `` | `boolean` | `obj:canISeeThisGuy()` |
| canIHearThisGuy | Instance | `` | `boolean` | `obj:canIHearThisGuy()` |
| amIAwareOfThisGuy | Instance | `needToSeeOrHear: boolean` | `boolean` | `obj:amIAwareOfThisGuy(needToSeeOrHear)` |
| getLastKnownPositionOf | Instance | `` | `Vector3` | `obj:getLastKnownPositionOf()` |
| getDataFor | Instance | `` | `SeenSomeone` | `obj:getDataFor()` |
| getFactionRelation | Instance | `` | `number` | `obj:getFactionRelation()` |
| getStateBroadcast | Instance | `` | `lightuserdata` | `obj:getStateBroadcast()` |
| getGUIData | Instance | `cat: integer` | `void` | `obj:getGUIData(cat)` |
| _calculateFOVScore | Instance | `` | `number` | `obj:_calculateFOVScore()` |
| _traceLineOfSightCheck | Instance | `` | `boolean` | `obj:_traceLineOfSightCheck()` |
| getCharacter | Instance | `` | `Character` | `obj:getCharacter()` |
| dialogAssessmentUpdate | Instance | `frameTime: number, inDepth: boolean` | `void` | `obj:dialogAssessmentUpdate(frameTime, inDepth)` |
| noticeThisPerson | Instance | `alarmed: boolean` | `void` | `obj:noticeThisPerson(alarmed)` |
| add | Instance | `see: boolean, hear: boolean` | `SeenSomeone` | `obj:add(see, hear)` |
| remove | Instance | `` | `void` | `obj:remove()` |
| decay | Instance | `` | `void` | `obj:decay()` |
| canSee | Instance | `` | `boolean` | `obj:canSee()` |
| canHear | Instance | `` | `boolean` | `obj:canHear()` |
| disguiseMods | Instance | `FOV: number` | `boolean` | `obj:disguiseMods(FOV)` |
| assessCrimes | Instance | `` | `void` | `obj:assessCrimes()` |
| assessKidnapping | Instance | `` | `void` | `obj:assessKidnapping()` |
| processKillList | Instance | `` | `void` | `obj:processKillList()` |
| assessNeutral | Instance | `inDepth: boolean` | `void` | `obj:assessNeutral(inDepth)` |
| updateMyProgressBar | Instance | `progress: number, text: string` | `void` | `obj:updateMyProgressBar(progress, text)` |
| canISeeThisGuyDoinSneakingOrSomething | Instance | `FOVScore: number, spotTimeMinFOV: number, spotTimeMaxFOV: number` | `YesNoMaybe` | `obj:canISeeThisGuyDoinSneakingOrSomething(FOVScore, spotTimeMinFOV, spotTimeMaxFOV)` |
| isIntruder_Base | Instance | `` | `boolean` | `obj:isIntruder_Base()` |
| isIntruder_Building | Instance | `` | `boolean` | `obj:isIntruder_Building()` |
| isInMyPrivate_Building | Instance | `` | `boolean` | `obj:isInMyPrivate_Building()` |
| isEscapee | Instance | `` | `boolean` | `obj:isEscapee()` |
| reassess | Instance | `time: number` | `SeenSomeone` | `obj:reassess(time)` |
| addToThreatsAndFlockingList | Instance | `` | `void` | `obj:addToThreatsAndFlockingList()` |
| buildingSpotterUpdate | Instance | `` | `void` | `obj:buildingSpotterUpdate()` |
| notifyCriminalThreat | Instance | `` | `void` | `obj:notifyCriminalThreat()` |
| getStateBroadcastOf | Instance | `` | `StateBroadcastData*` | `obj:getStateBroadcastOf()` |
| _shareSensesCheck | Instance | `list: userdata, time: number` | `boolean` | `obj:_shareSensesCheck(list, time)` |
| setupMyProgressBar | Instance | `` | `void` | `obj:setupMyProgressBar()` |
| reassessAll | Instance | `newTargets: userdata, time: number` | `void` | `obj:reassessAll(newTargets, time)` |

## SensoryData::SpottingPeopleMgr
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Parent Class:** [`SensoryData`](#sensorydata)
**Metatable:** `KenshiLua.SpottingPeopleMgr`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| spottedPeople | `unknown` | RW | `obj.spottedPeople = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `time: number` | `void` | `obj:update(time)` |
| resetSeenFlags | Instance | `` | `void` | `obj:resetSeenFlags()` |
| spot | Instance | `timelimit: number` | `void` | `obj:spot(timelimit)` |
| getTime | Instance | `` | `number` | `obj:getTime()` |
| cantSeeAnymore | Instance | `` | `void` | `obj:cantSeeAnymore()` |
| has | Instance | `` | `boolean` | `obj:has()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| takeMoney | Instance | `money: integer` | `boolean` | `obj:takeMoney(money)` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| getOrientation | Instance | `` | `Quaternion` | `obj:getOrientation()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| isIndoors | Instance | `` | `void` | `obj:isIndoors()` |
| getFloor | Instance | `` | `integer` | `obj:getFloor()` |
| getCurrentTownLocation | Instance | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| getDataType | Instance | `` | `integer` | `obj:getDataType()` |
| serialise | Instance | `offsetPosToSubtract: userdata` | `void` | `obj:serialise(offsetPosToSubtract)` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| getTrader | Instance | `` | `Character` | `obj:getTrader()` |
| isPhysical | Instance | `` | `boolean` | `obj:isPhysical()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| updateInventory | Instance | `` | `void` | `obj:updateInventory()` |
| equipItem | Instance | `sectionName: string` | `void` | `obj:equipItem(sectionName)` |
| unequipItem | Instance | `sectionName: string` | `void` | `obj:unequipItem(sectionName)` |

## ShopTraderInventory
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`
**Metatable:** `KenshiLua.ShopTraderInventory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| inventories | `unknown` | RW | `obj.inventories = <value>` |
| section | `ShopTraderInventorySection` | RW | `obj.section = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateInventory | Instance | `` | `void` | `obj:updateInventory()` |
| dropItem | Instance | `` | `void` | `obj:dropItem()` |
| refreshGui | Instance | `` | `void` | `obj:refreshGui()` |
| initialiseNewSection | Instance | `name: string, w: integer, h: integer, _a4: integer, equipCallbacks: boolean, _a6: boolean, _a7: boolean, _a8: integer` | `InventorySection` | `obj:initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8)` |
| _addItem | Instance | `quantity: integer` | `boolean` | `obj:_addItem(quantity)` |
| _addItemToInventories | Instance | `` | `boolean` | `obj:_addItemToInventories()` |
| _removeItemFromInventories | Instance | `quantity: integer` | `void` | `obj:_removeItemFromInventories(quantity)` |
| _sectionAddItemCallback | Instance | `` | `void` | `obj:_sectionAddItemCallback()` |
| _sectionUpdateItemCallback | Instance | `prevQuantity: integer` | `void` | `obj:_sectionUpdateItemCallback(prevQuantity)` |
| _sectionRemoveItemCallback | Instance | `` | `void` | `obj:_sectionRemoveItemCallback()` |

## ShopTraderInventorySection
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`
**Metatable:** `KenshiLua.ShopTraderInventorySection`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| autoArrange | Instance | `` | `void` | `obj:autoArrange()` |
| addItem | Instance | `quantity: integer` | `boolean` | `obj:addItem(quantity)` |

## SimpleTimeStamper
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`
**Metatable:** `KenshiLua.SimpleTimeStamper`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timer | `CPerfTimer` | RW | `obj.timer = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getTime | Instance | `_lastStamp: number` | `number` | `obj:getTime(_lastStamp)` |
| stampTime | Instance | `` | `number` | `obj:stampTime()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| initialiseOverride | Instance | `` | `void` | `obj:initialiseOverride()` |
| shutdownOverride | Instance | `` | `void` | `obj:shutdownOverride()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getSpeed | Instance | `` | `number` | `obj:getSpeed()` |

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
| mainPanel | `lightuserdata` | R | `obj.mainPanel` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| getState | Instance | `` | `integer` | `obj:getState()` |
| getEnded | Instance | `` | `boolean` | `obj:getEnded()` |
| skip | Instance | `` | `void` | `obj:skip()` |
| addLogo | Instance | `file: string, scale: number` | `void` | `obj:addLogo(file, scale)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| update [1] | Instance | `` | `void` | `obj:update()` |
| update [2] | Instance | `_info: MyGUI::IBDrawItemInfo, _data: PortraitData` | `void` | `obj:update(_info, _data)` |
| update [3] | Instance | `_info: MyGUI::IBDrawItemInfo, _data: SquadManagementScreen::SquadData` | `void` | `obj:update(_info, _data)` |
| reset | Instance | `` | `void` | `obj:reset()` |
| refreshSquads | Instance | `` | `void` | `obj:refreshSquads()` |
| notifyEndDropSquad | Instance | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropSquad(_sender, _result)` |
| notifyEndDropPortrait | Instance | `_sender: userdata, _result: boolean` | `void` | `obj:notifyEndDropPortrait(_sender, _result)` |
| removeSquad | Instance | `` | `void` | `obj:removeSquad()` |
| getSquad | Instance | `` | `SquadManagementScreen::SquadData` | `obj:getSquad()` |
| dismissCharacter | Instance | `result: integer` | `void` | `obj:dismissCharacter(result)` |

## SquadManagementScreen::PortraitSquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/PortraitManager.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.PortraitSquadCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| characterHandle | `unknown` | RW | `obj.characterHandle = <value>` |
| name | `string` | RW | `obj.name = <value>` |
| border | `lightuserdata` | R | `obj.border` |
| imgBoxPortrait | `lightuserdata` | R | `obj.imgBoxPortrait` |
| txtName | `lightuserdata` | R | `obj.txtName` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| resize | Instance | `` | `void` | `obj:resize()` |
| setName | Instance | `newName: string` | `void` | `obj:setName(newName)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getItemCount | Instance | `` | `integer` | `obj:getItemCount()` |
| update | Instance | `` | `void` | `obj:update()` |

## SquadManagementScreen::SquadCellView
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.SquadCellView`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| portraitsBox | `SquadManagementScreen::PortraitSquadItemBox` | RW | `obj.portraitsBox = <value>` |
| txtName | `lightuserdata` | R | `obj.txtName` |
| txtSquadSize | `lightuserdata` | R | `obj.txtSquadSize` |
| squad | `SquadManagementScreen::SquadData` | RW | `obj.squad = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateSquadSize | Instance | `` | `void` | `obj:updateSquadSize()` |

## SquadManagementScreen::SquadData
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.SquadData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| platoon | `ActivePlatoon` | RW | `obj.platoon = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setName | Instance | `name: string` | `void` | `obj:setName(name)` |

## SquadManagementScreen::SquadItemBox
**Header:** `extern/KenshiLib/Include/kenshi/gui/SquadManagementScreen.h`
**Parent Class:** [`SquadManagementScreen`](#squadmanagementscreen)
**Metatable:** `KenshiLua.SquadItemBox`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCellSize | Instance | `width: integer, height: integer` | `void` | `obj:setCellSize(width, height)` |
| getItemCount | Instance | `` | `integer` | `obj:getItemCount()` |

## StorageBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/StorageBuilding.h`
**Metatable:** `KenshiLua.StorageBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| specialItemTypesOnly | `integer` | RW | `obj.specialItemTypesOnly = <value>` |
| endOfTheLine | `boolean` | RW | `obj.endOfTheLine = <value>` |
| productionItem | `StorageBuilding::ConsumptionItem` | RW | `obj.productionItem = <value>` |
| manyLimitItems | `lektor<StorageBuilding::ConsumptionItem*>` | RW | `obj.manyLimitItems = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getFunctionStuff | Instance | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| getUseableStuff | Instance | `` | `UseableStuff` | `obj:getUseableStuff()` |
| update | Instance | `` | `void` | `obj:update()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| getProductionItemData | Instance | `` | `GameData` | `obj:getProductionItemData()` |
| getProductionItem | Instance | `` | `lightuserdata` | `obj:getProductionItem()` |
| getCurrentProductionQuantity | Instance | `` | `integer` | `obj:getCurrentProductionQuantity()` |
| isAnyInputsEmpty | Instance | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| isAnyInputsFull | Instance | `` | `boolean` | `obj:isAnyInputsFull()` |
| isProductionFull | Instance | `` | `boolean` | `obj:isProductionFull()` |
| isProductionEmpty | Instance | `` | `boolean` | `obj:isProductionEmpty()` |
| getNumConsumtionItems | Instance | `` | `integer` | `obj:getNumConsumtionItems()` |
| getConsumtionItems | Instance | `id: integer` | `lightuserdata` | `obj:getConsumtionItems(id)` |
| limitedByType | Instance | `` | `boolean` | `obj:limitedByType()` |
| updateInventoryWindow | Instance | `` | `void` | `obj:updateInventoryWindow()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isFull | Instance | `` | `boolean` | `obj:isFull()` |
| isEmpty | Instance | `` | `boolean` | `obj:isEmpty()` |

## StringPair
**Header:** `extern/KenshiLib/Include/kenshi/util/StringPair.h`
**Metatable:** `KenshiLua.StringPair`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| s1 | `string` | RW | `obj.s1 = <value>` |
| s2 | `string` | RW | `obj.s2 = <value>` |
| val1 | `number` | RW | `obj.val1 = <value>` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getClassType | Instance | `` | `integer` | `obj:getClassType()` |
| isSword | Instance | `` | `Sword` | `obj:isSword()` |
| setupStats | Instance | `_level: integer` | `void` | `obj:setupStats(_level)` |
| getSkillModIndoors | Instance | `` | `integer` | `obj:getSkillModIndoors()` |

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
| permaJob_Associated | `integer` | RW | `obj.permaJob_Associated = <value>` |
| permaJob_Associated_Secondary | `integer` | RW | `obj.permaJob_Associated_Secondary = <value>` |
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
| key | `integer` | RW | `obj.key = <value>` |
| needsTarget | `boolean` | RW | `obj.needsTarget = <value>` |
| numResults | `integer` | RW | `obj.numResults = <value>` |
| results | `unknown` | RW | `obj.results = <value>` |
| numRequirements | `integer` | RW | `obj.numRequirements = <value>` |
| requirements | `unknown` | RW | `obj.requirements = <value>` |
| scoreFunction | `lightuserdata` | R | `obj.scoreFunction` |
| justDoOneTarget | `boolean` | RW | `obj.justDoOneTarget = <value>` |
| subTask | `TaskStateData` | RW | `obj.subTask = <value>` |
| dialogueDelivery | `integer` | RW | `obj.dialogueDelivery = <value>` |
| hasAction | `boolean` | RW | `obj.hasAction = <value>` |
| description | `string` | RW | `obj.description = <value>` |
| _findTarget | `lightuserdata` | R | `obj._findTarget` |
| permaJob | `integer` | RW | `obj.permaJob = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCharacteristics | Instance | `_aid: number, _aggressionLevel: number, noise: number, leadsSomewhere: boolean` | `void` | `obj:setCharacteristics(_aid, _aggressionLevel, noise, leadsSomewhere)` |
| setInfrequentGoalChecks | Instance | `` | `void` | `obj:setInfrequentGoalChecks()` |
| setAlertnessMult | Instance | `a: number` | `void` | `obj:setAlertnessMult(a)` |
| setRequirementsCantEndActionPrematurely | Instance | `on: boolean` | `void` | `obj:setRequirementsCantEndActionPrematurely(on)` |
| setCopyMeInfluence | Instance | `weight: number` | `void` | `obj:setCopyMeInfluence(weight)` |
| setFollowMeWeight | Instance | `weight: number` | `void` | `obj:setFollowMeWeight(weight)` |
| setSelfRegulation | Instance | `requirements: boolean, results: boolean` | `void` | `obj:setSelfRegulation(requirements, results)` |
| setDurationBased | Instance | `mintime: number, fuzz: number, _endsAfterTime: boolean` | `void` | `obj:setDurationBased(mintime, fuzz, _endsAfterTime)` |
| hasInfrequentGoalChecks | Instance | `` | `boolean` | `obj:hasInfrequentGoalChecks()` |
| getRequirementsCantEndActionPrematurely | Instance | `` | `boolean` | `obj:getRequirementsCantEndActionPrematurely()` |
| isPermaJob | Instance | `` | `boolean` | `obj:isPermaJob()` |
| isPermaJobFixedTarget | Instance | `` | `boolean` | `obj:isPermaJobFixedTarget()` |
| getPermaJobAssociation | Instance | `` | `integer` | `obj:getPermaJobAssociation()` |
| getPermaJobAssociation_secondary | Instance | `` | `integer` | `obj:getPermaJobAssociation_secondary()` |
| isTargetFinder | Instance | `` | `boolean` | `obj:isTargetFinder()` |
| setDialogueDeliveryTag | Instance | `d: integer` | `void` | `obj:setDialogueDeliveryTag(d)` |
| setPermaJob | Instance | `on: integer, fixedTarget: boolean, t: integer, secondary: integer` | `void` | `obj:setPermaJob(on, fixedTarget, t, secondary)` |
| getPermaJobType | Instance | `` | `integer` | `obj:getPermaJobType()` |

## Tasker
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`
**Metatable:** `KenshiLua.Tasker`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| resetsWhenDone | `boolean` | RW | `obj.resetsWhenDone = <value>` |
| subject | `unknown` | RW | `obj.subject = <value>` |
| weight | `number` | RW | `obj.weight = <value>` |
| currentSubTarget | `unknown` | RW | `obj.currentSubTarget = <value>` |
| location | `Vector3` | RW | `obj.location = <value>` |
| startTime | `integer` | RW | `obj.startTime = <value>` |
| endTime | `integer` | RW | `obj.endTime = <value>` |
| taskData | `TaskData` | RW | `obj.taskData = <value>` |
| priority | `integer` | RW | `obj.priority = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| checkTimeOfDay | Instance | `` | `boolean` | `obj:checkTimeOfDay()` |
| getFrameTime | Instance | `` | `number` | `obj:getFrameTime()` |
| key | Instance | `` | `integer` | `obj:key()` |
| unSkippableJob | Instance | `` | `boolean` | `obj:unSkippableJob()` |
| getLocation | Instance | `` | `Vector3` | `obj:getLocation()` |
| setLocation | Instance | `loc: Vector3` | `void` | `obj:setLocation(loc)` |
| sameAs | Instance | `` | `boolean` | `obj:sameAs()` |
| hasActionFunc | Instance | `` | `boolean` | `obj:hasActionFunc()` |
| isSubTasker | Instance | `` | `boolean` | `obj:isSubTasker()` |
| getSubTask | Instance | `` | `TaskStateData` | `obj:getSubTask()` |
| isInfiniteGoal | Instance | `` | `boolean` | `obj:isInfiniteGoal()` |
| needsSubjectOrLocation | Instance | `` | `boolean` | `obj:needsSubjectOrLocation()` |
| getTaskData | Instance | `` | `TaskData` | `obj:getTaskData()` |
| startAction | Instance | `` | `void` | `obj:startAction()` |
| runAction | Instance | `` | `void` | `obj:runAction()` |
| endAction | Instance | `` | `void` | `obj:endAction()` |
| taskSaysItsFinished | Instance | `` | `boolean` | `obj:taskSaysItsFinished()` |
| score | Instance | `ai: userdata` | `number` | `obj:score(ai)` |
| isResultsComplete | Instance | `ai: userdata` | `boolean` | `obj:isResultsComplete(ai)` |
| isResultsComplete_ignoreSubtasker | Instance | `ai: userdata` | `boolean` | `obj:isResultsComplete_ignoreSubtasker(ai)` |
| isRequirementsComplete | Instance | `ai: userdata, autoTargetFinder: boolean` | `boolean` | `obj:isRequirementsComplete(ai, autoTargetFinder)` |
| getRequirementComplaint | Instance | `ai: userdata, autoTargetFinder: boolean` | `string` | `obj:getRequirementComplaint(ai, autoTargetFinder)` |
| getNextSubTarget | Instance | `ai: userdata` | `hand` | `obj:getNextSubTarget(ai)` |

## TaskStateData
**Header:** `extern/KenshiLib/Include/kenshi/Tasker.h`
**Metatable:** `KenshiLua.TaskStateData`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| val | `boolean` | RW | `obj.val = <value>` |
| progressionOnly | `boolean` | RW | `obj.progressionOnly = <value>` |
| key | `integer` | RW | `obj.key = <value>` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getBoundingRadius | Instance | `` | `number` | `obj:getBoundingRadius()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| stopRunning | Instance | `` | `void` | `obj:stopRunning()` |
| canIRun | Instance | `` | `boolean` | `obj:canIRun()` |
| startRunning | Instance | `time: number` | `boolean` | `obj:startRunning(time)` |
| isRunning | Instance | `` | `boolean` | `obj:isRunning()` |
| waitForRunningStop_Blocking | Instance | `` | `boolean` | `obj:waitForRunningStop_Blocking()` |
| setup | Instance | `_frameTime: number, infinite: boolean, _pretendThread: boolean` | `void` | `obj:setup(_frameTime, infinite, _pretendThread)` |
| beginThread | Instance | `_frameTime: number, infinite: boolean, priority: integer` | `boolean` | `obj:beginThread(_frameTime, infinite, priority)` |
| setThreadName | Instance | `threadName: string` | `void` | `obj:setThreadName(threadName)` |
| endThread | Instance | `` | `void` | `obj:endThread()` |
| setName | Instance | `name: string` | `void` | `obj:setName(name)` |
| threadProc | Instance | `` | `integer` | `obj:threadProc()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| backThreadUpdate | Instance | `_a1: number, _a2: boolean` | `void` | `obj:backThreadUpdate(_a1, _a2)` |
| isPaused | Instance | `` | `boolean` | `obj:isPaused()` |
| setPaused | Instance | `on: boolean, _speedMult: number` | `void` | `obj:setPaused(on, _speedMult)` |
| threadProc | Instance | `` | `integer` | `obj:threadProc()` |
| forceLoopMT | Instance | `` | `void` | `obj:forceLoopMT()` |

## TimeOfDay
**Header:** `extern/KenshiLib/Include/kenshi/util/TimeOfDay.h`
**Metatable:** `KenshiLua.TimeOfDay`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| time | `number` | RW | `obj.time = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setNull | Instance | `` | `void` | `obj:setNull()` |
| isUnset | Instance | `` | `boolean` | `obj:isUnset()` |
| setTime | Instance | `hrs: number` | `void` | `obj:setTime(hrs)` |
| addHours | Instance | `hours: number` | `void` | `obj:addHours(hours)` |
| addMinutes | Instance | `mins: number` | `void` | `obj:addMinutes(mins)` |
| getTotalHours | Instance | `` | `number` | `obj:getTotalHours()` |
| getTotalMinutes | Instance | `` | `number` | `obj:getTotalMinutes()` |
| getTotalSeconds | Instance | `` | `number` | `obj:getTotalSeconds()` |
| getRealLifeSeconds | Instance | `` | `number` | `obj:getRealLifeSeconds()` |
| getRealLifeSecondsPassed | Instance | `` | `number` | `obj:getRealLifeSecondsPassed()` |
| getTotalDays | Instance | `` | `number` | `obj:getTotalDays()` |
| stampTime | Instance | `` | `void` | `obj:stampTime()` |
| getHoursPassed | Instance | `` | `number` | `obj:getHoursPassed()` |
| getMinutesPassed | Instance | `` | `number` | `obj:getMinutesPassed()` |
| getSecondsPassed | Instance | `` | `number` | `obj:getSecondsPassed()` |
| timeOfDayHasPassed | Instance | `additionalHours: number` | `boolean` | `obj:timeOfDayHasPassed(additionalHours)` |
| timePassed | Instance | `` | `number` | `obj:timePassed()` |
| getTimePassedString | Instance | `` | `string` | `obj:getTimePassedString()` |
| getTimeRemainingString | Instance | `` | `string` | `obj:getTimeRemainingString()` |
| getTotalTimeString | Instance | `` | `string` | `obj:getTotalTimeString()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| show | Instance | `on: boolean` | `void` | `obj:show(on)` |
| update | Instance | `` | `void` | `obj:update()` |
| closeTheOtherBits | Instance | `` | `boolean` | `obj:closeTheOtherBits()` |
| setCreditsVisible | Instance | `value: boolean` | `void` | `obj:setCreditsVisible(value)` |
| getSingleton | Static / Instance | `` | `TitleScreen` | `TitleScreen.getSingleton()`<br>`obj:getSingleton()` |

## ToolTip
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTip`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| panel | `lightuserdata` | RW | `obj.panel = <value>` |
| panelWidth | `integer` | RW | `obj.panelWidth = <value>` |
| lineMarginH | `number` | RW | `obj.lineMarginH = <value>` |
| panelMarginV | `integer` | RW | `obj.panelMarginV = <value>` |
| lineSpacing | `integer` | RW | `obj.lineSpacing = <value>` |
| caller | `lightuserdata` | R | `obj.caller` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| hide | Instance | `` | `void` | `obj:hide()` |
| getVisible | Instance | `` | `boolean` | `obj:getVisible()` |
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |
| addLine | Instance | `textLeft: string, textRight: string` | `void` | `obj:addLine(textLeft, textRight)` |
| clearLines | Instance | `` | `void` | `obj:clearLines()` |

## ToolTip::ToolTipLine
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Parent Class:** [`ToolTip`](#tooltip)
**Metatable:** `KenshiLua.ToolTipLine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| content | `MyGUI::Widget` | R | `obj.content` |
| leftBox | `MyGUI::Widget` | R | `obj.leftBox` |
| rightBox | `MyGUI::Widget` | R | `obj.rightBox` |
| width | `integer` | RW | `obj.width = <value>` |

## ToolTipDynamic
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipDynamic`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |

## ToolTipFixed
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipFixed`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentPanel | `lightuserdata` | R | `obj.parentPanel` |
| minHeight | `integer` | RW | `obj.minHeight = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |

## ToolTipInventory
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipInventory`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| compareTooltip | `ToolTipInventory` | RW | `obj.compareTooltip = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |

## ToolTipStatic
**Header:** `extern/KenshiLib/Include/kenshi/gui/ToolTip.h`
**Metatable:** `KenshiLua.ToolTipStatic`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| update | Instance | `` | `void` | `obj:update()` |
| setVisible | Instance | `visible: boolean` | `void` | `obj:setVisible(visible)` |

## TortureBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/TortureBuilding.h`
**Metatable:** `KenshiLua.TortureBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| timer | `number` | RW | `obj.timer = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getFunctionStuff | Instance | `` | `StorageBuilding` | `obj:getFunctionStuff()` |
| update | Instance | `` | `void` | `obj:update()` |

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
| powerInList | `HandFastArrayBinding::ArrayType` | RW | `obj.powerInList = <value>` |
| powerOutList | `ogre_unordered_set<hand>::type` | RW | `obj.powerOutList = <value>` |
| tradeGoodsMults | `unknown` | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| initialiseResidentData | Instance | `` | `void` | `obj:initialiseResidentData()` |
| getGameData | Instance | `` | `GameData` | `obj:getGameData()` |
| getOriginalGameData | Instance | `` | `GameData` | `obj:getOriginalGameData()` |
| notifyRepopulation | Instance | `` | `void` | `obj:notifyRepopulation()` |
| isMyOldHomeTownStillValid | Instance | `` | `boolean` | `obj:isMyOldHomeTownStillValid()` |
| setup | Instance | `_pos: Vector3` | `void` | `obj:setup(_pos)` |
| _reset | Instance | `` | `void` | `obj:_reset()` |
| getDataType | Instance | `` | `integer` | `obj:getDataType()` |
| reassessTownPosition | Instance | `` | `void` | `obj:reassessTownPosition()` |
| showDistantTown | Instance | `vis: boolean` | `void` | `obj:showDistantTown(vis)` |
| getAlarmMgr | Instance | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| isOutpost | Instance | `` | `boolean` | `obj:isOutpost()` |
| _setMainResident | Instance | `forceForGates: boolean` | `boolean` | `obj:_setMainResident(forceForGates)` |
| spawnTheBarFlies | Instance | `` | `void` | `obj:spawnTheBarFlies()` |
| townLoadedEvent | Instance | `newGameFirstTime: boolean` | `void` | `obj:townLoadedEvent(newGameFirstTime)` |
| notifyUnloading | Instance | `` | `void` | `obj:notifyUnloading()` |
| getBuildingMaterial | Instance | `` | `GameData` | `obj:getBuildingMaterial()` |
| getLocalTradePriceMult | Instance | `` | `number` | `obj:getLocalTradePriceMult()` |
| getFactionTradeCultureMult | Instance | `` | `number` | `obj:getFactionTradeCultureMult()` |
| isTown | Instance | `` | `Town` | `obj:isTown()` |
| isNest | Instance | `` | `lightuserdata` | `obj:isNest()` |
| isPublic | Instance | `` | `boolean` | `obj:isPublic()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| saveState | Instance | `` | `void` | `obj:saveState()` |
| loadState | Instance | `` | `void` | `obj:loadState()` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| needsSaving | Instance | `mod: string` | `boolean` | `obj:needsSaving(mod)` |
| setPosition | Instance | `p: Vector3` | `void` | `obj:setPosition(p)` |
| saveStateEditor | Instance | `` | `void` | `obj:saveStateEditor()` |
| loadStateEditor | Instance | `` | `void` | `obj:loadStateEditor()` |
| getRadius | Instance | `` | `number` | `obj:getRadius()` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| update | Instance | `` | `void` | `obj:update()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| updatePowerGrid | Instance | `` | `void` | `obj:updatePowerGrid()` |
| hasResidentHQ | Instance | `` | `boolean` | `obj:hasResidentHQ()` |
| gatesAllClosed | Instance | `` | `boolean` | `obj:gatesAllClosed()` |
| hasGates | Instance | `` | `boolean` | `obj:hasGates()` |
| notifyAccesibility | Instance | `accessible: boolean` | `void` | `obj:notifyAccesibility(accessible)` |
| getNearestGate | Instance | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| getPositionOutsideTownGates | Instance | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| addBuilding | Instance | `powerIn: boolean, powerOut: boolean, battery: boolean` | `void` | `obj:addBuilding(powerIn, powerOut, battery)` |
| removeBuilding | Instance | `` | `void` | `obj:removeBuilding()` |
| isPlayerBuildingsInThisTown | Instance | `` | `boolean` | `obj:isPlayerBuildingsInThisTown()` |
| setPlayerBuildingsInThisTown | Instance | `` | `void` | `obj:setPlayerBuildingsInThisTown()` |
| getRequiredPower | Instance | `` | `number` | `obj:getRequiredPower()` |
| getTotalPower | Instance | `` | `number` | `obj:getTotalPower()` |
| hasSparePower | Instance | `` | `boolean` | `obj:hasSparePower()` |
| getBatteryDrain | Instance | `` | `number` | `obj:getBatteryDrain()` |
| getBatteryChargeMax | Instance | `` | `number` | `obj:getBatteryChargeMax()` |
| getBatteryCharge | Instance | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryCharge01 | Instance | `` | `number` | `obj:getBatteryCharge01()` |
| getBatteryChargingUpAmount | Instance | `` | `number` | `obj:getBatteryChargingUpAmount()` |
| getBatteryPowerTotal | Instance | `` | `number` | `obj:getBatteryPowerTotal()` |
| isBatteryMode | Instance | `` | `boolean` | `obj:isBatteryMode()` |
| addNest | Instance | `pos: Vector3` | `void` | `obj:addNest(pos)` |
| removeNest | Instance | `` | `boolean` | `obj:removeNest()` |
| clearNests | Instance | `` | `void` | `obj:clearNests()` |
| getMapMarker | Instance | `` | `string` | `obj:getMapMarker()` |
| getMapMarkerZoomLevel | Instance | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| recalculatePlayerTownLevel | Instance | `` | `void` | `obj:recalculatePlayerTownLevel()` |
| deActivationCheck | Instance | `` | `void` | `obj:deActivationCheck()` |
| _initialiseResidentData | Instance | `` | `void` | `obj:_initialiseResidentData()` |
| chooseResidents | Instance | `` | `void` | `obj:chooseResidents()` |
| chooseBuildingForResident | Instance | `` | `Building` | `obj:chooseBuildingForResident()` |
| addGate | Instance | `` | `void` | `obj:addGate()` |
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| getPlayerTownTypeEnum | Instance | `` | `integer` | `obj:getPlayerTownTypeEnum()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |

## Town::NestSpot
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`Town`](#town)
**Metatable:** `KenshiLua.Town_NestSpot`

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
| alarmState | `integer` | RW | `obj.alarmState = <value>` |
| artifacts | `Ogre::FastArray<ArtifactItemData>` | R | `obj.artifacts` |
| factionsResidentHere | `unknown` | RW | `obj.factionsResidentHere = <value>` |
| myZoneCoverage | `ogre_unordered_set<ZoneMap*>::type` | RW | `obj.myZoneCoverage = <value>` |
| occupiers | `unknown` | RW | `obj.occupiers = <value>` |
| populatedZones | `unknown` | RW | `obj.populatedZones = <value>` |
| residentsSpawned | `lektor<TownBase::ResidentData>` | RW | `obj.residentsSpawned = <value>` |
| residentsSpawned_BarsOrSomething | `lektor<TownBase::ResidentData>` | RW | `obj.residentsSpawned_BarsOrSomething = <value>` |
| townType | `integer` | RW | `obj.townType = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| activate | Instance | `` | `void` | `obj:activate()` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| setup | Instance | `_pos: Vector3` | `void` | `obj:setup(_pos)` |
| _reset | Instance | `` | `void` | `obj:_reset()` |
| getKnownName | Instance | `` | `string` | `obj:getKnownName()` |
| reassessTownPosition | Instance | `` | `void` | `obj:reassessTownPosition()` |
| isNotFriendly | Instance | `` | `boolean` | `obj:isNotFriendly()` |
| isPhysical | Instance | `` | `boolean` | `obj:isPhysical()` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| getDataType | Instance | `` | `integer` | `obj:getDataType()` |
| isTown | Instance | `` | `Town` | `obj:isTown()` |
| isNest | Instance | `` | `lightuserdata` | `obj:isNest()` |
| nestUpThisSpot | Instance | `pos: Vector3` | `void` | `obj:nestUpThisSpot(pos)` |
| loadFromSerialise | Instance | `` | `void` | `obj:loadFromSerialise()` |
| isOutpost | Instance | `` | `boolean` | `obj:isOutpost()` |
| withinBordersRange | Instance | `p: Vector3, mult: number` | `boolean` | `obj:withinBordersRange(p, mult)` |
| withinDiscoveryRange | Instance | `p: Vector3, explored: boolean` | `boolean` | `obj:withinDiscoveryRange(p, explored)` |
| isIllegal | Instance | `` | `boolean` | `obj:isIllegal()` |
| distanceTo | Instance | `to: Vector3` | `number` | `obj:distanceTo(to)` |
| squaredDistanceTo | Instance | `to: Vector3` | `number` | `obj:squaredDistanceTo(to)` |
| isDead | Instance | `` | `boolean` | `obj:isDead()` |
| getPositionOutsideTownGates | Instance | `dist: number` | `Vector3` | `obj:getPositionOutsideTownGates(dist)` |
| setFaction | Instance | `` | `void` | `obj:setFaction()` |
| isPublic | Instance | `` | `boolean` | `obj:isPublic()` |
| addGate | Instance | `` | `void` | `obj:addGate()` |
| addOccupier | Instance | `` | `void` | `obj:addOccupier()` |
| removeOccupier | Instance | `` | `void` | `obj:removeOccupier()` |
| getRadius | Instance | `` | `number` | `obj:getRadius()` |
| getGUIData | Instance | `category: integer` | `void` | `obj:getGUIData(category)` |
| saveState | Instance | `` | `void` | `obj:saveState()` |
| loadState | Instance | `` | `void` | `obj:loadState()` |
| update | Instance | `` | `void` | `obj:update()` |
| periodicUpdate | Instance | `` | `void` | `obj:periodicUpdate()` |
| updatePowerGrid | Instance | `` | `void` | `obj:updatePowerGrid()` |
| hasResidentHQ | Instance | `` | `boolean` | `obj:hasResidentHQ()` |
| findAllBuildingsOfType | Instance | `func: integer` | `lektor<Building*>` | `obj:findAllBuildingsOfType(func)` |
| findAllBuildingsWithFunction | Instance | `func: integer` | `lektor<Building*>` | `obj:findAllBuildingsWithFunction(func)` |
| allBuildingsDoorsOpen | Instance | `` | `boolean` | `obj:allBuildingsDoorsOpen()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| getPosition | Instance | `` | `Vector3` | `obj:getPosition()` |
| getPositionForWaypoint | Instance | `from: Vector3` | `Vector3` | `obj:getPositionForWaypoint(from)` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| getAlarmMgr | Instance | `` | `lightuserdata` | `obj:getAlarmMgr()` |
| hasGates | Instance | `` | `boolean` | `obj:hasGates()` |
| gatesAllClosed | Instance | `` | `boolean` | `obj:gatesAllClosed()` |
| getNearestGate | Instance | `to: Vector3` | `GatewayBuilding` | `obj:getNearestGate(to)` |
| getBiome | Instance | `` | `lightuserdata` | `obj:getBiome()` |
| isRecentlyDiscovered | Instance | `` | `boolean` | `obj:isRecentlyDiscovered()` |
| setRecentlyDiscovered | Instance | `value: boolean` | `void` | `obj:setRecentlyDiscovered(value)` |
| isDiscovered | Instance | `` | `boolean` | `obj:isDiscovered()` |
| setDiscovered | Instance | `value: boolean` | `void` | `obj:setDiscovered(value)` |
| setDead | Instance | `` | `void` | `obj:setDead()` |
| isExplored | Instance | `` | `boolean` | `obj:isExplored()` |
| setExplored | Instance | `value: boolean` | `void` | `obj:setExplored(value)` |
| getItemArtifactsMinValue | Instance | `` | `integer` | `obj:getItemArtifactsMinValue()` |
| getItemArtifactsMaxValue | Instance | `` | `integer` | `obj:getItemArtifactsMaxValue()` |
| getGearArtifactsMinValue | Instance | `` | `integer` | `obj:getGearArtifactsMinValue()` |
| getGearArtifactsMaxValue | Instance | `` | `integer` | `obj:getGearArtifactsMaxValue()` |
| setZonePopulated | Instance | `` | `void` | `obj:setZonePopulated()` |
| getBuildingsManager | Instance | `` | `TownBuildingsManager` | `obj:getBuildingsManager()` |
| getBuildingFloorVisibility | Instance | `` | `integer` | `obj:getBuildingFloorVisibility()` |
| setBuildingsFloorVisibility | Instance | `floor: integer` | `void` | `obj:setBuildingsFloorVisibility(floor)` |
| resetBuildingsFloorVisibility | Instance | `` | `void` | `obj:resetBuildingsFloorVisibility()` |
| getTownFloorVisiblity | Instance | `` | `integer` | `obj:getTownFloorVisiblity()` |
| setTownFloorVisiblity | Instance | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setTownFloorVisiblity(floor, onlyPlayerBuildings)` |
| resetTownFloorVisibility | Instance | `` | `void` | `obj:resetTownFloorVisibility()` |
| getCurrentTownLocation | Instance | `` | `TownBase` | `obj:getCurrentTownLocation()` |
| getMapMarker | Instance | `` | `string` | `obj:getMapMarker()` |
| getMapMarkerZoomLevel | Instance | `` | `integer` | `obj:getMapMarkerZoomLevel()` |
| isOccupied | Instance | `` | `boolean` | `obj:isOccupied()` |
| _nestUpThisSpot | Instance | `pos: Vector3` | `void` | `obj:_nestUpThisSpot(pos)` |
| distributeArtifacts | Instance | `` | `void` | `obj:distributeArtifacts()` |
| getUnexploredName | Instance | `` | `string` | `obj:getUnexploredName()` |
| getAlarmState | Instance | `` | `integer` | `obj:getAlarmState()` |
| setAlarmState | Instance | `st: integer` | `void` | `obj:setAlarmState(st)` |
| setHandle | Instance | `` | `void` | `obj:setHandle()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| delayedSpawningChecks | Static / Instance | `` | `integer` | `TownBase.delayedSpawningChecks()`<br>`obj:delayedSpawningChecks()` |
| clearDelayedItemLoadingMessages | Static / Instance | `` | `void` | `TownBase.clearDelayedItemLoadingMessages()`<br>`obj:clearDelayedItemLoadingMessages()` |
| getZonesCoverage | Instance | `` | `ogre_unordered_set<ZoneMap*>::type` | `obj:getZonesCoverage()` |
| spawnDebris | Instance | `staticGeometry: userdata, centerpos: Vector3, range: number, num: integer, scale: number, spawnItems: boolean` | `void` | `obj:spawnDebris(staticGeometry, centerpos, range, num, scale, spawnItems)` |

## TownBase::DelayedSpawnMsg
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`TownBase`](#townbase)
**Metatable:** `KenshiLua.DelayedSpawnMsg`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| parentTown | `unknown` | RW | `obj.parentTown = <value>` |
| item | `Item` | RW | `obj.item = <value>` |
| nestData | `GameData` | RW | `obj.nestData = <value>` |
| pos | `Vector3` | RW | `obj.pos = <value>` |
| insideBuilding | `unknown` | RW | `obj.insideBuilding = <value>` |

## TownBase::ResidentData
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Parent Class:** [`TownBase`](#townbase)
**Metatable:** `KenshiLua.TownBase_ResidentData`

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| stampUpdate | Instance | `` | `void` | `obj:stampUpdate()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |

## TownBuildingsManager
**Header:** `extern/KenshiLib/Include/kenshi/Town.h`
**Metatable:** `KenshiLua.TownBuildingsManager`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| signsVisible | `boolean` | RW | `obj.signsVisible = <value>` |
| town | `TownBase` | RW | `obj.town = <value>` |
| buildingEntities | `unknown` | RW | `obj.buildingEntities = <value>` |
| instancesManagers | `boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >` | R | `obj.instancesManagers` |
| signs | `Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >` | R | `obj.signs` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| moveBuildingsTo | Instance | `` | `void` | `obj:moveBuildingsTo()` |
| removeBuilding | Instance | `` | `void` | `obj:removeBuilding()` |
| setFloorVisible | Instance | `floor: integer` | `void` | `obj:setFloorVisible(floor)` |
| setAllVisible | Instance | `floor: integer, onlyPlayerBuildings: boolean` | `void` | `obj:setAllVisible(floor, onlyPlayerBuildings)` |
| resetAllVisible | Instance | `` | `void` | `obj:resetAllVisible()` |
| setSignsVisible | Instance | `value: boolean` | `void` | `obj:setSignsVisible(value)` |
| factoryObjectCreatedCallback | Instance | `` | `void` | `obj:factoryObjectCreatedCallback()` |
| getFloorVisible [1] | Instance | `building: Building` | `integer` | `obj:getFloorVisible(building)` |
| getFloorVisible [2] | Instance | `building: Building, floor: integer` | `boolean` | `obj:getFloorVisible(building, floor)` |

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
| tradeGoodsMults | `unknown` | RW | `obj.tradeGoodsMults = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | Instance | `` | `void` | `obj:reset()` |
| getAllIllegalItems | Instance | `` | `StdSetBinding<GameData*>::SetType` | `obj:getAllIllegalItems()` |
| isItemIllegal | Instance | `` | `boolean` | `obj:isItemIllegal()` |
| getTradePriceMultiplier | Instance | `` | `number` | `obj:getTradePriceMultiplier()` |
| hasTradePriceMultiplier | Instance | `` | `boolean` | `obj:hasTradePriceMultiplier()` |
| getForbiddenItemsList | Instance | `` | `lektor<GameData*>` | `obj:getForbiddenItemsList()` |

## TraderInventoryLayout
**Header:** `extern/KenshiLib/Include/kenshi/gui/InventoryGUI.h`
**Metatable:** `KenshiLua.TraderInventoryLayout`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| scrollBackpack | `lightuserdata` | R | `obj.scrollBackpack` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setCaption | Instance | `s: string` | `void` | `obj:setCaption(s)` |
| updateState | Instance | `` | `void` | `obj:updateState()` |
| close | Instance | `` | `void` | `obj:close()` |
| refresh | Instance | `` | `void` | `obj:refresh()` |
| updateGizmo | Instance | `` | `boolean` | `obj:updateGizmo()` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| hasChanged | Instance | `` | `boolean` | `obj:hasChanged()` |
| clearChangedFlag | Instance | `` | `void` | `obj:clearChangedFlag()` |
| getMode | Instance | `` | `integer` | `obj:getMode()` |
| setMode | Instance | `m: integer` | `boolean` | `obj:setMode(m)` |
| getLastZone | Instance | `` | `ZoneMap` | `obj:getLastZone()` |
| getZone | Instance | `` | `ZoneMap` | `obj:getZone()` |
| changeMode | Instance | `` | `void` | `obj:changeMode()` |
| changeCoord | Instance | `` | `void` | `obj:changeCoord()` |
| changeValue | Instance | `` | `void` | `obj:changeValue()` |
| reset | Instance | `` | `void` | `obj:reset()` |
| revert | Instance | `` | `void` | `obj:revert()` |
| getSingleton | Static / Instance | `` | `TransformWindow` | `TransformWindow.getSingleton()`<br>`obj:getSingleton()` |

## TripleInt
**Header:** `extern/KenshiLib/Include/kenshi/util/TripleInt.h`
**Metatable:** `KenshiLua.TripleInt`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| value | `unknown` | RW | `obj.value = <value>` |

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
| mountedBuilding | `unknown` | RW | `obj.mountedBuilding = <value>` |
| hingePart | `lightuserdata` | R | `obj.hingePart` |
| gunPart | `lightuserdata` | R | `obj.gunPart` |
| aimTargetPos | `Vector3` | RW | `obj.aimTargetPos = <value>` |
| rotating | `integer` | RW | `obj.rotating = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| setup | Instance | `` | `void` | `obj:setup()` |
| update | Instance | `` | `void` | `obj:update()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |
| getStatUsed | Instance | `` | `integer` | `obj:getStatUsed()` |
| getProductionMultForGUI | Instance | `` | `number` | `obj:getProductionMultForGUI()` |
| aimAt | Instance | `who: Vector3` | `void` | `obj:aimAt(who)` |
| setVisible | Instance | `on: boolean` | `void` | `obj:setVisible(on)` |
| amInsideTownWalls | Instance | `` | `integer` | `obj:amInsideTownWalls()` |
| notifyConstructionComplete | Instance | `` | `void` | `obj:notifyConstructionComplete()` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| destroyPhysical | Instance | `` | `void` | `obj:destroyPhysical()` |
| onBuildingLoaded | Instance | `` | `void` | `obj:onBuildingLoaded()` |
| calculatePowerMult | Instance | `` | `number` | `obj:calculatePowerMult()` |
| _teleport | Instance | `p: Vector3` | `void` | `obj:_teleport(p)` |
| clearTownBuildingsManagerPtr | Instance | `` | `void` | `obj:clearTownBuildingsManagerPtr()` |
| getMountedBuilding | Instance | `` | `void` | `obj:getMountedBuilding()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |

## TutorialGUI
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Metatable:** `KenshiLua.TutorialGUI`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| highlightItem | `integer` | RW | `obj.highlightItem = <value>` |
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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| clear | Instance | `` | `void` | `obj:clear()` |
| startHighlight | Instance | `item: integer` | `void` | `obj:startHighlight(item)` |
| endHighlight | Instance | `` | `void` | `obj:endHighlight()` |
| _setHightlightCoords | Instance | `` | `void` | `obj:_setHightlightCoords()` |
| update | Instance | `` | `void` | `obj:update()` |
| setEnabled | Instance | `value: boolean` | `void` | `obj:setEnabled(value)` |
| show | Instance | `value: boolean` | `void` | `obj:show(value)` |
| removeTutorialFromList | Instance | `` | `void` | `obj:removeTutorialFromList()` |
| arrangeList | Instance | `` | `void` | `obj:arrangeList()` |
| refreshUI | Instance | `` | `void` | `obj:refreshUI()` |
| showTutorialWindow | Instance | `` | `void` | `obj:showTutorialWindow()` |
| closeTutorialWindow | Instance | `` | `void` | `obj:closeTutorialWindow()` |
| updateCurrentItem | Instance | `` | `void` | `obj:updateCurrentItem()` |

## TutorialGUI::TutorialGUILine
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Parent Class:** [`TutorialGUI`](#tutorialgui)
**Metatable:** `KenshiLua.TutorialGUILine`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| nameButton | `lightuserdata` | R | `obj.nameButton` |
| closeButton | `lightuserdata` | R | `obj.closeButton` |
| flashWidget | `lightuserdata` | R | `obj.flashWidget` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| updateHighlight | Instance | `time: number` | `boolean` | `obj:updateHighlight(time)` |

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
| state | `integer` | RW | `obj.state = <value>` |
| subItemIndex | `integer` | RW | `obj.subItemIndex = <value>` |
| subItems | `TutorialSubItemFastArrayBinding::ArrayType` | RW | `obj.subItems = <value>` |
| requiredTutorialsStr | `StringFastArrayBinding::ArrayType` | RW | `obj.requiredTutorialsStr = <value>` |
| requiredTutorials | `TutorialItemFastArrayBinding::ArrayType` | RW | `obj.requiredTutorials = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getId | Instance | `` | `integer` | `obj:getId()` |
| isLastSubItem | Instance | `` | `boolean` | `obj:isLastSubItem()` |
| isSkippable | Instance | `` | `boolean` | `obj:isSkippable()` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| hasEnded | Instance | `` | `boolean` | `obj:hasEnded()` |
| getCurrentSubItem | Instance | `` | `TutorialSubItem` | `obj:getCurrentSubItem()` |
| getSubItemAt | Instance | `index: integer` | `TutorialSubItem` | `obj:getSubItemAt(index)` |
| getCurrentSubItemIndex | Instance | `` | `integer` | `obj:getCurrentSubItemIndex()` |
| getNumSubItems | Instance | `` | `integer` | `obj:getNumSubItems()` |
| hasNextSubItem | Instance | `` | `boolean` | `obj:hasNextSubItem()` |
| hasPrevSubItem | Instance | `` | `boolean` | `obj:hasPrevSubItem()` |
| nextSubItem | Instance | `` | `void` | `obj:nextSubItem()` |
| prevSubItem | Instance | `` | `void` | `obj:prevSubItem()` |
| getStarted | Instance | `` | `boolean` | `obj:getStarted()` |
| getEnded | Instance | `` | `boolean` | `obj:getEnded()` |
| reset | Instance | `` | `void` | `obj:reset()` |
| conditionsMet | Instance | `` | `boolean` | `obj:conditionsMet()` |
| start | Instance | `` | `void` | `obj:start()` |
| run | Instance | `` | `boolean` | `obj:run()` |
| end | Instance | `` | `void` | `obj:end()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| show | Instance | `value: boolean` | `void` | `obj:show(value)` |
| clear | Instance | `` | `void` | `obj:clear()` |
| isVisible | Instance | `` | `boolean` | `obj:isVisible()` |
| setup | Instance | `` | `void` | `obj:setup()` |
| updateCurrentItem | Instance | `` | `void` | `obj:updateCurrentItem()` |

## TutorialSubItem
**Header:** `extern/KenshiLib/Include/kenshi/gui/TutorialGUI.h`
**Metatable:** `KenshiLua.TutorialSubItem`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| description | `string` | RW | `obj.description = <value>` |
| skippeable | `boolean` | RW | `obj.skippeable = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| start | Instance | `` | `void` | `obj:start()` |
| run | Instance | `` | `boolean` | `obj:run()` |
| end | Instance | `` | `void` | `obj:end()` |

## UseableStuff
**Header:** `extern/KenshiLib/Include/kenshi/Building/UseableStuff.h`
**Metatable:** `KenshiLua.UseableStuff`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| shopOwner | `unknown` | RW | `obj.shopOwner = <value>` |
| callbackOwner | `unknown` | RW | `obj.callbackOwner = <value>` |
| hasProgressBarWhenUsed | `boolean` | RW | `obj.hasProgressBarWhenUsed = <value>` |
| progressBarLevel | `number` | RW | `obj.progressBarLevel = <value>` |
| occupantSelection | `unknown` | RW | `obj.occupantSelection = <value>` |
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
| currentOperators | `unknown` | RW | `obj.currentOperators = <value>` |
| usesStat | `integer` | RW | `obj.usesStat = <value>` |
| functionalityData | `GameData` | RW | `obj.functionalityData = <value>` |
| animation | `GameData` | RW | `obj.animation = <value>` |
| animationKO | `GameData` | RW | `obj.animationKO = <value>` |
| animationDazed | `GameData` | RW | `obj.animationDazed = <value>` |
| maxUseRange | `number` | RW | `obj.maxUseRange = <value>` |
| sfxTime | `number` | RW | `obj.sfxTime = <value>` |
| inventory | `Inventory` | R | `obj.inventory` |
| doorLock | `lightuserdata` | R | `obj.doorLock` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getUseableStuff | Instance | `` | `UseableStuff` | `obj:getUseableStuff()` |
| createInventoryLayout | Instance | `` | `InventoryLayout` | `obj:createInventoryLayout()` |
| takeMoney | Instance | `n: integer` | `boolean` | `obj:takeMoney(n)` |
| getMoney | Instance | `` | `integer` | `obj:getMoney()` |
| getInventory | Instance | `` | `Inventory` | `obj:getInventory()` |
| isAnyInputsEmpty | Instance | `` | `boolean` | `obj:isAnyInputsEmpty()` |
| needsUpdate | Instance | `` | `boolean` | `obj:needsUpdate()` |
| threadedUpdate | Instance | `` | `void` | `obj:threadedUpdate()` |
| calculateEfficiencyMult | Instance | `` | `number` | `obj:calculateEfficiencyMult()` |
| isOutOfPower | Instance | `` | `number` | `obj:isOutOfPower()` |
| isBroken | Instance | `` | `boolean` | `obj:isBroken()` |
| setBroken | Instance | `on: boolean` | `void` | `obj:setBroken(on)` |
| isDisabled | Instance | `` | `boolean` | `obj:isDisabled()` |
| getMouseCursor | Instance | `` | `integer` | `obj:getMouseCursor()` |
| getDefaultTask | Instance | `` | `integer` | `obj:getDefaultTask()` |
| getReachRange | Instance | `` | `number` | `obj:getReachRange()` |
| dontNeedWorkRightNow | Instance | `` | `boolean` | `obj:dontNeedWorkRightNow()` |
| isForSale | Instance | `` | `boolean` | `obj:isForSale()` |
| takePowerFrom | Instance | `amount: number, frameTime: number` | `number` | `obj:takePowerFrom(amount, frameTime)` |
| howMuchPowerDoYouWantMax | Instance | `` | `number` | `obj:howMuchPowerDoYouWantMax()` |
| howMuchPowerDoYouWantForSortingFunction | Instance | `` | `number` | `obj:howMuchPowerDoYouWantForSortingFunction()` |
| howMuchPowerDoYouWantNow | Instance | `` | `number` | `obj:howMuchPowerDoYouWantNow()` |
| needPowerRightNow | Instance | `` | `boolean` | `obj:needPowerRightNow()` |
| givePower | Instance | `amount: number` | `void` | `obj:givePower(amount)` |
| resetPower | Instance | `` | `void` | `obj:resetPower()` |
| getMaxPower | Instance | `` | `number` | `obj:getMaxPower()` |
| getPowerOutput | Instance | `` | `number` | `obj:getPowerOutput()` |
| getFuelConsumptionRate | Instance | `` | `number` | `obj:getFuelConsumptionRate()` |
| isBattery | Instance | `` | `boolean` | `obj:isBattery()` |
| isGenerator | Instance | `` | `boolean` | `obj:isGenerator()` |
| getBatteryCharge | Instance | `` | `number` | `obj:getBatteryCharge()` |
| getBatteryChargeMax | Instance | `` | `number` | `obj:getBatteryChargeMax()` |
| setupFromData | Instance | `` | `void` | `obj:setupFromData()` |
| switchPowerOn | Instance | `on: boolean` | `void` | `obj:switchPowerOn(on)` |
| hasPower | Instance | `` | `boolean` | `obj:hasPower()` |
| isPowerOn | Instance | `` | `boolean` | `obj:isPowerOn()` |
| isRecievesBatteryPower | Instance | `` | `boolean` | `obj:isRecievesBatteryPower()` |
| getStatUsed | Instance | `` | `integer` | `obj:getStatUsed()` |
| getDoorLock | Instance | `` | `lightuserdata` | `obj:getDoorLock()` |
| hasDoorLock | Instance | `` | `boolean` | `obj:hasDoorLock()` |
| getFunctionalityData | Instance | `` | `GameData` | `obj:getFunctionalityData()` |
| setup | Instance | `` | `void` | `obj:setup()` |
| getOutputBasedRotationSpeedMult | Instance | `` | `number` | `obj:getOutputBasedRotationSpeedMult()` |
| getGUIPowerEfficiencyToolTipString | Instance | `` | `string` | `obj:getGUIPowerEfficiencyToolTipString()` |
| getOccupant | Instance | `` | `void` | `obj:getOccupant()` |
| getAnimation | Instance | `` | `string` | `obj:getAnimation()` |
| getAnimationKO | Instance | `` | `string` | `obj:getAnimationKO()` |
| getAnimationDazed | Instance | `` | `string` | `obj:getAnimationDazed()` |
| serialise | Instance | `offset: userdata` | `void` | `obj:serialise(offset)` |
| hitByMeleeAttack | Instance | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |

## UtilityT
**Header:** `extern/KenshiLib/Include/kenshi/util/UtilityT.h`
**Metatable:** `KenshiLua.UtilityT`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| marker | `lightuserdata` | R | `obj.marker` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| perlinNoise_2D | Instance | `x: number, y: number, zoom: number, dropPoint: number` | `number` | `obj:perlinNoise_2D(x, y, zoom, dropPoint)` |
| getTerrainHeightFastWithNormal | Instance | `x: number, z: number, normal: Vector3` | `number` | `obj:getTerrainHeightFastWithNormal(x, z, normal)` |
| getTerrainSlopeFast | Instance | `x: number, z: number` | `number` | `obj:getTerrainSlopeFast(x, z)` |
| profilesClear | Instance | `` | `void` | `obj:profilesClear()` |
| profilesPrint | Instance | `` | `void` | `obj:profilesPrint()` |
| profileGet | Instance | `name: string` | `integer` | `obj:profileGet(name)` |
| flushMarkerQueue | Instance | `` | `void` | `obj:flushMarkerQueue()` |
| removeMarkers | Instance | `` | `void` | `obj:removeMarkers()` |
| folderExists | Instance | `folder: string` | `boolean` | `obj:folderExists(folder)` |
| fileExistsASCII | Instance | `file: string` | `boolean` | `obj:fileExistsASCII(file)` |
| createFile | Instance | `path: string, content: string` | `boolean` | `obj:createFile(path, content)` |
| writeFile | Instance | `path: string, content: string, append: boolean` | `boolean` | `obj:writeFile(path, content, append)` |
| isFile | Instance | `_path: string` | `boolean` | `obj:isFile(_path)` |
| isDirectory | Instance | `_path: string` | `boolean` | `obj:isDirectory(_path)` |
| deleteFilesInFolder | Instance | `dir: string, filter: string, recursive: boolean` | `void` | `obj:deleteFilesInFolder(dir, filter, recursive)` |
| deleteFolder | Instance | `dir: string` | `void` | `obj:deleteFolder(dir)` |
| deleteFile | Instance | `dir: string` | `void` | `obj:deleteFile(dir)` |
| moveFile | Instance | `from: string, to: string` | `boolean` | `obj:moveFile(from, to)` |
| copyFile | Instance | `from: string, to: string` | `boolean` | `obj:copyFile(from, to)` |
| copyFilesInFolder | Instance | `from: string, to: string, filter: string` | `boolean` | `obj:copyFilesInFolder(from, to, filter)` |
| getTerrainHeight | Instance | `z: number` | `number` | `obj:getTerrainHeight(z)` |
| getTerrainWithWaterHeight | Instance | `z: number` | `number` | `obj:getTerrainWithWaterHeight(z)` |
| getTerrainWithWaterHeightFromRenderer | Instance | `` | `number` | `obj:getTerrainWithWaterHeightFromRenderer()` |
| getPositionInWater | Instance | `z: number` | `boolean` | `obj:getPositionInWater(z)` |
| getFloorHeight [1] | Instance | `origin: Vector3, floorNum: integer, withTerrain: boolean, furniture: boolean` | `number` | `obj:getFloorHeight(origin, floorNum, withTerrain, furniture)` |
| getFloorHeight [2] | Instance | `origin: Vector3, withTerrain: boolean, furniture: boolean` | `number` | `obj:getFloorHeight(origin, withTerrain, furniture)` |
| getBuildingGroundFloorHeight | Instance | `withTerrain: boolean` | `number` | `obj:getBuildingGroundFloorHeight(withTerrain)` |
| isIndoors | Instance | `` | `Building` | `obj:isIndoors()` |
| isIndoorsFast | Instance | `` | `boolean` | `obj:isIndoorsFast()` |
| isIndoors_forWaypoint | Instance | `` | `Building` | `obj:isIndoors_forWaypoint()` |
| getFloorNumber [1] | Instance | `collisionGroup: integer` | `integer` | `obj:getFloorNumber(collisionGroup)` |
| getFloorNumber [2] | Instance | `position: Vector3, hitBuilding: hand` | `integer` | `obj:getFloorNumber(position, hitBuilding)` |
| getTerrainHeightFast | Instance | `z: number` | `number` | `obj:getTerrainHeightFast(z)` |
| random [1] | Instance | `lo: number, hi: number` | `number` | `obj:random(lo, hi)` |
| random [2] | Instance | `` | `number` | `obj:random()` |
| randomBool | Instance | `` | `boolean` | `obj:randomBool()` |
| randomInt | Instance | `hi: integer` | `integer` | `obj:randomInt(hi)` |
| seed [1] | Instance | `s: integer` | `void` | `obj:seed(s)` |
| seed [2] | Instance | `` | `void` | `obj:seed()` |
| round | Instance | `` | `integer` | `obj:round()` |
| nlerp | Instance | `b: number, t: number` | `number` | `obj:nlerp(b, t)` |
| getNextPow2 | Instance | `` | `integer` | `obj:getNextPow2()` |
| quatSetDirection | Instance | `arg1: unknown, arg2: unknown` | `Quaternion` | `obj:quatSetDirection(arg1, arg2)` |
| getSubMapSector | Instance | `Z: number` | `void` | `obj:getSubMapSector(Z)` |
| getSubMapSectorBounds | Instance | `` | `Vector4` | `obj:getSubMapSectorBounds()` |
| getResourceFilePath | Instance | `` | `string` | `obj:getResourceFilePath()` |
| removePathFromString | Instance | `` | `string` | `obj:removePathFromString()` |
| removeFilenameFromPath | Instance | `` | `string` | `obj:removeFilenameFromPath()` |
| removeFileExtensionFromString | Instance | `` | `string` | `obj:removeFileExtensionFromString()` |
| getFileExtensionFromString | Instance | `` | `string` | `obj:getFileExtensionFromString()` |
| removeInvalidFileNameChars | Instance | `` | `string` | `obj:removeInvalidFileNameChars()` |
| compareStringsCaseInsenstive | Instance | `b: string` | `boolean` | `obj:compareStringsCaseInsenstive(b)` |
| makeSureGameFolderExists | Instance | `` | `void` | `obj:makeSureGameFolderExists()` |
| makeSureFolderExists | Instance | `` | `void` | `obj:makeSureFolderExists()` |
| getFullPath | Instance | `` | `string` | `obj:getFullPath()` |
| positionIsInFrontOfMe | Instance | `arg1: unknown` | `boolean` | `obj:positionIsInFrontOfMe(arg1)` |
| pointInPlane | Instance | `arg1: unknown, arg2: unknown` | `boolean` | `obj:pointInPlane(arg1, arg2)` |
| colorToGUIString | Instance | `g: number, b: number, a: number` | `string` | `obj:colorToGUIString(g, b, a)` |
| getFilesInDir | Instance | `dir: string, type: string` | `boolean` | `obj:getFilesInDir(dir, type)` |
| getFilesInGameDir | Instance | `dir: string, type: string` | `boolean` | `obj:getFilesInGameDir(dir, type)` |
| getDirsInDir | Instance | `dir: string` | `void` | `obj:getDirsInDir(dir)` |
| readFile | Instance | `path: string` | `string` | `obj:readFile(path)` |
| roundToNearest | Instance | `input: number, roundTo: integer` | `number` | `obj:roundToNearest(input, roundTo)` |

## VisibleObjectInfo
**Header:** `extern/KenshiLib/Include/kenshi/SensoryData.h`
**Metatable:** `KenshiLua.VisibleObjectInfo`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| handle | `unknown` | RW | `obj.handle = <value>` |
| range | `number` | RW | `obj.range = <value>` |
| isEnemy | `boolean` | RW | `obj.isEnemy = <value>` |

## WallBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/WallBuilding.h`
**Metatable:** `KenshiLua.WallBuilding`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| wallSectionLinkType | `integer` | RW | `obj.wallSectionLinkType = <value>` |
| shareBuildStateOfAnother | `unknown` | RW | `obj.shareBuildStateOfAnother = <value>` |
| othersSharingMyBuildState | `lektor<hand>` | RW | `obj.othersSharingMyBuildState = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getUseableStuff | Instance | `` | `UseableStuff` | `obj:getUseableStuff()` |
| getReachRange | Instance | `` | `number` | `obj:getReachRange()` |
| isForSale | Instance | `` | `boolean` | `obj:isForSale()` |
| createPhysical | Instance | `` | `boolean` | `obj:createPhysical()` |
| isDamaged | Instance | `` | `boolean` | `obj:isDamaged()` |
| getPositionForWaypoint_outside | Instance | `` | `Vector3` | `obj:getPositionForWaypoint_outside()` |
| getOutsideGateCode | Instance | `` | `integer` | `obj:getOutsideGateCode()` |
| isAWall | Instance | `` | `WallBuilding` | `obj:isAWall()` |
| canUpgrade | Instance | `` | `GameData` | `obj:canUpgrade()` |
| addConstructionProgress | Instance | `amount: number` | `void` | `obj:addConstructionProgress(amount)` |
| setConstructionProgress | Instance | `amount: number` | `void` | `obj:setConstructionProgress(amount)` |
| notifyConstructionComplete | Instance | `` | `void` | `obj:notifyConstructionComplete()` |
| addDismantleProgress | Instance | `amount: number` | `boolean` | `obj:addDismantleProgress(amount)` |
| notifyConstructionDismantling | Instance | `` | `void` | `obj:notifyConstructionDismantling()` |
| getBuildState | Instance | `` | `Building::ConstructionState` | `obj:getBuildState()` |
| isALittleWallPartLikeACornerOrSomething | Instance | `` | `boolean` | `obj:isALittleWallPartLikeACornerOrSomething()` |
| isAShortWallPart | Instance | `` | `boolean` | `obj:isAShortWallPart()` |
| hitByMeleeAttack | Instance | `dir: integer, comboID: integer` | `integer` | `obj:hitByMeleeAttack(dir, comboID)` |

## Weapon
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`
**Metatable:** `KenshiLua.Weapon`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| bleedDamage | `number` | RW | `obj.bleedDamage = <value>` |
| modAttack | `integer` | RW | `obj.modAttack = <value>` |
| combatWeight | `number` | RW | `obj.combatWeight = <value>` |
| category | `integer` | RW | `obj.category = <value>` |
| category_animationOverride | `integer` | RW | `obj.category_animationOverride = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getItemWeight | Instance | `` | `number` | `obj:getItemWeight()` |
| getValueSingle | Instance | `isPlayer: boolean` | `integer` | `obj:getValueSingle(isPlayer)` |
| getCategory | Instance | `` | `integer` | `obj:getCategory()` |
| getCategory_animationOverride | Instance | `` | `integer` | `obj:getCategory_animationOverride()` |
| is2HandedOnly | Instance | `` | `boolean` | `obj:is2HandedOnly()` |
| getCombatWeight | Instance | `` | `number` | `obj:getCombatWeight()` |
| getCraftTime | Instance | `` | `number` | `obj:getCraftTime()` |
| getCraftMaterialMult | Instance | `` | `number` | `obj:getCraftMaterialMult()` |
| isWeapon | Instance | `` | `Weapon` | `obj:isWeapon()` |
| isSword | Instance | `` | `Sword` | `obj:isSword()` |
| isCrossbow | Instance | `` | `Crossbow` | `obj:isCrossbow()` |
| getSkillModIndoors | Instance | `` | `integer` | `obj:getSkillModIndoors()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| reset | Instance | `` | `void` | `obj:reset()` |
| getWeatherInstance | Instance | `` | `lightuserdata` | `obj:getWeatherInstance()` |
| setCurrentSeason | Instance | `seasonIndex: integer, seasonEnd: integer` | `void` | `obj:setCurrentSeason(seasonIndex, seasonEnd)` |
| getNewWeatherStrength | Instance | `` | `number` | `obj:getNewWeatherStrength()` |
| update | Instance | `` | `void` | `obj:update()` |
| updateBT | Instance | `` | `void` | `obj:updateBT()` |
| addListener | Instance | `listener: userdata` | `void` | `obj:addListener(listener)` |
| removeListener | Instance | `listener: userdata` | `void` | `obj:removeListener(listener)` |
| addGlobalEffect | Instance | `type: integer` | `void` | `obj:addGlobalEffect(type)` |
| getNewSeason | Instance | `` | `void` | `obj:getNewSeason()` |
| weatherChanged | Instance | `newWeather: boolean` | `void` | `obj:weatherChanged(newWeather)` |
| updateWeatherEffects | Instance | `` | `void` | `obj:updateWeatherEffects()` |
| save | Instance | `key: string` | `void` | `obj:save(key)` |
| load | Instance | `key: string` | `void` | `obj:load(key)` |

## WeatherRegion::Listener
**Header:** `extern/KenshiLib/Include/kenshi/Dialogue.h`
**Parent Class:** [`WeatherRegion`](#weatherregion)
**Metatable:** `KenshiLua.Listener`

## WindGeneratorBuilding
**Header:** `extern/KenshiLib/Include/kenshi/Building/GeneratorBuilding.h`
**Metatable:** `KenshiLua.WindGeneratorBuilding`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| getPowerOutput | Instance | `` | `number` | `obj:getPowerOutput()` |
| getSoundIntensity | Instance | `` | `number` | `obj:getSoundIntensity()` |
| isAnyInputsEmpty | Instance | `` | `boolean` | `obj:isAnyInputsEmpty()` |

## WorldEventStateQuery
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`
**Metatable:** `KenshiLua.WorldEventStateQuery`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| playerInvolvement | `boolean` | RW | `obj.playerInvolvement = <value>` |
| isAllyOf | `unknown` | RW | `obj.isAllyOf = <value>` |
| isEnemyOf | `unknown` | RW | `obj.isEnemyOf = <value>` |
| towns | `unknown` | RW | `obj.towns = <value>` |
| uniqueNPCsAre | `unknown` | RW | `obj.uniqueNPCsAre = <value>` |
| uniqueNPCsAreNot | `unknown` | RW | `obj.uniqueNPCsAreNot = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isTrue | Instance | `` | `boolean` | `obj:isTrue()` |
| checkAllStatesInObject | Static / Instance | `` | `boolean` | `WorldEventStateQuery.checkAllStatesInObject()`<br>`obj:checkAllStatesInObject()` |
| getFromData | Static / Instance | `` | `WorldEventStateQuery` | `WorldEventStateQuery.getFromData()`<br>`obj:getFromData()` |

## WorldEventStateQueryList
**Header:** `extern/KenshiLib/Include/kenshi/WorldEventStateQuery.h`
**Metatable:** `KenshiLua.WorldEventStateQueryList`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| statesList | `unknown` | RW | `obj.statesList = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| setupFrom | Instance | `listname: string` | `boolean` | `obj:setupFrom(listname)` |
| reset | Instance | `` | `void` | `obj:reset()` |
| isTrue | Instance | `` | `boolean` | `obj:isTrue()` |

## YesNoMaybe
**Header:** `extern/KenshiLib/Include/kenshi/util/YesNoMaybe.h`
**Metatable:** `KenshiLua.YesNoMaybe`

### Fields
| Lua Name | Type | R/W | Example |
|---|---|---|---|
| key | `integer` | RW | `obj.key = <value>` |

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| toInt | Instance | `` | `integer` | `obj:toInt()` |
| isValid | Instance | `` | `boolean` | `obj:isValid()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isZoneLoadedT | Instance | `pos: Vector3` | `boolean` | `obj:isZoneLoadedT(pos)` |
| isZoneBeingLoadedT | Instance | `pos: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(pos)` |
| getNumActiveZones | Instance | `` | `integer` | `obj:getNumActiveZones()` |
| findShop | Instance | `selling: integer` | `Building` | `obj:findShop(selling)` |
| findAnyShop | Instance | `` | `Building` | `obj:findAnyShop()` |
| setup | Instance | `` | `void` | `obj:setup()` |
| updateMainThread | Instance | `camerapos: Vector3` | `void` | `obj:updateMainThread(camerapos)` |
| updateRendertimeThread | Instance | `camerapos: Vector3` | `void` | `obj:updateRendertimeThread(camerapos)` |
| updateGPUSafeThread | Instance | `camerapos: Vector3` | `void` | `obj:updateGPUSafeThread(camerapos)` |
| spawnChecksUpdateThreaded | Instance | `island: integer` | `void` | `obj:spawnChecksUpdateThreaded(island)` |
| levelEditorDeleteAllSelectedObjects | Instance | `` | `void` | `obj:levelEditorDeleteAllSelectedObjects()` |
| getCurrentMapSector | Instance | `` | `void` | `obj:getCurrentMapSector()` |
| getCurrentZoneMap | Instance | `` | `ZoneMap` | `obj:getCurrentZoneMap()` |
| getSubMapSector | Instance | `X: number, Z: number` | `void` | `obj:getSubMapSector(X, Z)` |
| getZoneMapFromResolutionCoord | Instance | `X: number, Z: number` | `void` | `obj:getZoneMapFromResolutionCoord(X, Z)` |
| playerActivate | Instance | `pos: Vector3` | `boolean` | `obj:playerActivate(pos)` |
| deactivateZoneMap | Instance | `saveZoneState: boolean` | `void` | `obj:deactivateZoneMap(saveZoneState)` |
| getBiome | Instance | `position: Vector3` | `GameData` | `obj:getBiome(position)` |
| getBiomeCode | Instance | `position: Vector3` | `integer` | `obj:getBiomeCode(position)` |
| getBiomeMap | Instance | `` | `lightuserdata` | `obj:getBiomeMap()` |
| getGroundTypeIndex | Instance | `pos: Vector3` | `integer` | `obj:getGroundTypeIndex(pos)` |
| getGroundType | Instance | `pos: Vector3` | `integer` | `obj:getGroundType(pos)` |
| addGroundEffect | Instance | `position: Vector3` | `void` | `obj:addGroundEffect(position)` |
| shiftGroundEffects | Instance | `shift: Vector3` | `void` | `obj:shiftGroundEffects(shift)` |
| checkZoneFiles | Instance | `` | `boolean` | `obj:checkZoneFiles()` |
| resetStates | Instance | `` | `void` | `obj:resetStates()` |
| getResourceId | Instance | `resource: integer` | `string` | `obj:getResourceId(resource)` |
| getResourceName | Instance | `resource: integer` | `string` | `obj:getResourceName(resource)` |
| saveMapFeatures | Instance | `` | `boolean` | `obj:saveMapFeatures()` |
| saveLevelData | Instance | `path: string, modName: string` | `void` | `obj:saveLevelData(path, modName)` |
| saveActiveZoneStates | Instance | `` | `void` | `obj:saveActiveZoneStates()` |
| resetGame | Instance | `` | `void` | `obj:resetGame()` |
| deactivateAllActiveZones | Instance | `` | `void` | `obj:deactivateAllActiveZones()` |
| activateAllActiveZones | Instance | `` | `void` | `obj:activateAllActiveZones()` |
| populateTownsForLevelEditor | Instance | `` | `void` | `obj:populateTownsForLevelEditor()` |
| calculateIslands | Instance | `` | `void` | `obj:calculateIslands()` |
| _reloadAllFoliage | Instance | `` | `void` | `obj:_reloadAllFoliage()` |
| _reloadGroundTextures | Instance | `` | `void` | `obj:_reloadGroundTextures()` |
| _unloadAllZones | Instance | `` | `void` | `obj:_unloadAllZones()` |
| checkForRepopulateTown | Instance | `` | `boolean` | `obj:checkForRepopulateTown()` |
| getCentralZone | Instance | `` | `ZoneMap` | `obj:getCentralZone()` |
| isLoading | Instance | `` | `integer` | `obj:isLoading()` |
| _calculateIslands | Instance | `` | `void` | `obj:_calculateIslands()` |
| loadFeatures | Instance | `` | `void` | `obj:loadFeatures()` |
| loadDistantTowns | Instance | `` | `void` | `obj:loadDistantTowns()` |
| processLoading | Instance | `` | `boolean` | `obj:processLoading()` |
| loadPhase1 | Instance | `` | `void` | `obj:loadPhase1()` |
| loadPhase2 | Instance | `` | `void` | `obj:loadPhase2()` |
| loadPhase3 | Instance | `` | `void` | `obj:loadPhase3()` |
| getMapSector [1] | Instance | `v: Vector3` | `iVector2` | `obj:getMapSector(v)` |
| getMapSector [2] | Instance | `x: number, z: number` | `iVector2` | `obj:getMapSector(x, z)` |
| getZoneBoundsT | Instance | `pos: Vector3` | `void` | `obj:getZoneBoundsT(pos)` |
| getZoneMapSectorBounds | Instance | `` | `Vector4` | `obj:getZoneMapSectorBounds()` |
| getZoneMap [1] | Instance | `v: Vector3` | `ZoneMap` | `obj:getZoneMap(v)` |
| getZoneMap [2] | Instance | `x: integer, y: integer` | `ZoneMap` | `obj:getZoneMap(x, y)` |
| getZoneMap [3] | Instance | `v: iVector2` | `ZoneMap` | `obj:getZoneMap(v)` |
| getZoneMapFromBuildingHandle | Instance | `` | `ZoneMap` | `obj:getZoneMapFromBuildingHandle()` |
| getGroundSound [1] | Static / Instance | `type: GroundType, barefoot: boolean` | `char` | `ZoneManager.getGroundSound(type, barefoot)`<br>`obj:getGroundSound(type, barefoot)` |
| getGroundSound [2] | Static / Instance | `pos: Vector3` | `char` | `ZoneManager.getGroundSound(pos)`<br>`obj:getGroundSound(pos)` |
| activateZoneMap [1] | Instance | `map: ZoneMap, center: iVector2, range: integer, type: ZoneActivationType, deactivationTimer: number` | `boolean` | `obj:activateZoneMap(map, center, range, type, deactivationTimer)` |
| activateZoneMap [2] | Instance | `co: iVector2, range: integer, playerActivated: ZoneActivationType, backThread: boolean` | `boolean` | `obj:activateZoneMap(co, range, playerActivated, backThread)` |
| findBuilding [1] | Instance | `t: TownBase, f: Faction, out: BuildingFinderClass` | `void` | `obj:findBuilding(t, f, out)` |
| findBuilding [2] | Instance | `t: TownBase, f: Faction, forSaleOnly: boolean, fun: BuildingFunction, own: Ownerships` | `Building` | `obj:findBuilding(t, f, forSaleOnly, fun, own)` |
| getAllActiveZones | Instance | `` | `void` | `obj:getAllActiveZones()` |
| getAllActiveIslandNumbers | Instance | `` | `integer` | `obj:getAllActiveIslandNumbers()` |
| getZonesTouchingTown | Instance | `` | `void` | `obj:getZonesTouchingTown()` |
| findOverlappingActiveZones | Instance | `pos: Vector3, radius: number` | `void` | `obj:findOverlappingActiveZones(pos, radius)` |
| getBuildingsThatLinkTo | Instance | `` | `void` | `obj:getBuildingsThatLinkTo()` |
| findAllBuildings | Instance | `forSaleOnly: boolean, fun: integer` | `void` | `obj:findAllBuildings(forSaleOnly, fun)` |
| getResource | Instance | `resource: integer, biome: userdata, pos: Vector3` | `number` | `obj:getResource(resource, biome, pos)` |
| getResourceBase | Instance | `resource: integer, biome: userdata, pos: Vector3` | `number` | `obj:getResourceBase(resource, biome, pos)` |
| getGroundEffect | Instance | `pos: Vector3` | `boolean\|number` | `obj:getGroundEffect(pos)` |

## ZoneManager::BiomeGroundEffects
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Parent Class:** [`ZoneManager`](#zonemanager)
**Metatable:** `KenshiLua.ZoneManager_BiomeGroundEffects`

## ZoneManagerInterfaceT
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Metatable:** `KenshiLua.ZoneManagerInterfaceT`

### Methods
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isZoneLoadedT | Instance | `_a1: Vector3` | `boolean` | `obj:isZoneLoadedT(_a1)` |
| isZoneBeingLoadedT | Instance | `_a1: Vector3` | `boolean` | `obj:isZoneBeingLoadedT(_a1)` |
| getZoneBoundsT [1] | Instance | `_a1: Vector3` | `AABB2D` | `obj:getZoneBoundsT(_a1)` |
| getZoneBoundsT [2] | Instance | `_a1: iVector2` | `AABB2D` | `obj:getZoneBoundsT(_a1)` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| isInIsland | Instance | `` | `boolean` | `obj:isInIsland()` |
| initialise | Instance | `` | `void` | `obj:initialise()` |
| threadedUpdate | Instance | `` | `void` | `obj:threadedUpdate()` |
| update | Instance | `` | `boolean` | `obj:update()` |
| selectBiomes | Instance | `` | `integer` | `obj:selectBiomes()` |
| getBiomeCount | Instance | `` | `integer` | `obj:getBiomeCount()` |
| getBiomeData | Instance | `i: integer` | `GameData` | `obj:getBiomeData(i)` |
| getOverlay | Instance | `` | `lightuserdata` | `obj:getOverlay()` |
| getAreaSector | Instance | `` | `lightuserdata` | `obj:getAreaSector()` |
| getTerrainHeight | Instance | `_x: number, _y: number` | `number` | `obj:getTerrainHeight(_x, _y)` |
| getTerrainHeightWithNormal | Instance | `_x: number, _y: number, normal: Vector3` | `number` | `obj:getTerrainHeightWithNormal(_x, _y, normal)` |
| getTerrainSlope | Instance | `_x: number, _y: number` | `number` | `obj:getTerrainSlope(_x, _y)` |
| isWithinBoundsMinusUnloadedEdges | Instance | `borderThickness: number, v: Vector3` | `boolean` | `obj:isWithinBoundsMinusUnloadedEdges(borderThickness, v)` |
| getCornerPos | Instance | `` | `Vector3` | `obj:getCornerPos()` |
| getTerrainSector | Instance | `force: boolean` | `lightuserdata` | `obj:getTerrainSector(force)` |
| isActive | Instance | `` | `boolean` | `obj:isActive()` |
| getDeactivationCountdown | Instance | `` | `number` | `obj:getDeactivationCountdown()` |
| isLoadedBT | Instance | `` | `boolean` | `obj:isLoadedBT()` |
| isBeingLoadedBT | Instance | `` | `boolean` | `obj:isBeingLoadedBT()` |
| isLoadedMT | Instance | `` | `boolean` | `obj:isLoadedMT()` |
| isBeingLoadedMT | Instance | `` | `boolean` | `obj:isBeingLoadedMT()` |
| isANeighbour | Instance | `` | `boolean` | `obj:isANeighbour()` |
| isTerrainCollisionLoaded | Instance | `` | `boolean` | `obj:isTerrainCollisionLoaded()` |
| _makeSureTerrainHeightmapLoaded | Instance | `` | `void` | `obj:_makeSureTerrainHeightmapLoaded()` |
| _dactivateMT | Instance | `saveZoneState: boolean` | `void` | `obj:_dactivateMT(saveZoneState)` |
| generateNavMeshes | Instance | `` | `boolean` | `obj:generateNavMeshes()` |
| updateBuildingUsageNodes | Instance | `` | `void` | `obj:updateBuildingUsageNodes()` |
| getBounds | Instance | `` | `Vector4` | `obj:getBounds()` |
| getBoundsMinusUnloadedEdges | Instance | `borderThickness: number` | `Vector4` | `obj:getBoundsMinusUnloadedEdges(borderThickness)` |
| getActiveZoneIsland | Instance | `` | `void` | `obj:getActiveZoneIsland()` |
| getActiveNeighbours4 | Instance | `` | `void` | `obj:getActiveNeighbours4()` |
| getActiveNeighbours8 | Instance | `` | `void` | `obj:getActiveNeighbours8()` |
| isActivationType | Instance | `type: integer` | `boolean` | `obj:isActivationType(type)` |
| init | Instance | `` | `void` | `obj:init()` |
| getCenterPos | Instance | `` | `Vector3` | `obj:getCenterPos()` |

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
| Lua Name | Scope | Arguments | Return Type | Example |
|---|---|---|---|---|
| add | Instance | `` | `integer` | `obj:add()` |
| remove | Instance | `` | `boolean` | `obj:remove()` |
| update | Instance | `` | `integer` | `obj:update()` |
| addZone | Instance | `` | `void` | `obj:addZone()` |
| removeZone | Instance | `` | `void` | `obj:removeZone()` |
| getZoneKey | Instance | `p: Vector3` | `integer` | `obj:getZoneKey(p)` |
| getCellKey | Instance | `p: Vector3` | `integer` | `obj:getCellKey(p)` |
| getFullKey | Instance | `p: Vector3` | `integer` | `obj:getFullKey(p)` |
| initialiseGrid | Instance | `size: number` | `void` | `obj:initialiseGrid(size)` |

## ZoneSpacialGrid::ZoneCell
**Header:** `extern/KenshiLib/Include/kenshi/ZoneManager.h`
**Parent Class:** [`ZoneSpacialGrid`](#zonespacialgrid)
**Metatable:** `KenshiLua.ZoneSpacialGrid_ZoneCell`
