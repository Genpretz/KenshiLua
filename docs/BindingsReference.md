# Lua Bindings Reference

## Table of Contents
- [Bounty](#bounty)
- [BountyManager](#bountymanager)
- [Building](#building)
- [CameraClass](#cameraclass)
- [CharBody](#charbody)
- [CharStats](#charstats)
- [Character](#character)
- [CharacterAnimal](#characteranimal)
- [Damages](#damages)
- [Dialogue](#dialogue)
- [DialogueEvent](#dialogueevent)
- [Faction](#faction)
- [GameData](#gamedata)
- [GameWorld](#gameworld)
- [Gear](#gear)
- [Global](#global)
- [Hand](#hand)
- [InputHandler](#inputhandler)
- [Inventory](#inventory)
- [Item](#item)
- [MedicalSystem](#medicalsystem)
- [MyGui](#mygui)
- [Platoon](#platoon)
- [PlayerInterface](#playerinterface)
- [RaceData](#racedata)
- [RootObject](#rootobject)
- [ShopTrader](#shoptrader)
- [Town](#town)
- [Enums](#enums)

## Bounty
**Header:** `extern/KenshiLib/Include/kenshi/Bounty.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| amount | amount | integer | RW | `obj.amount = <value>` |
| crimes | crimes | integer | RW | `obj.crimes = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| addCrime | addCrime | `obj:addCrime(...)` |
| hasCrime | hasCrime | `obj:hasCrime(...)` |

## BountyManager
**Header:** `extern/KenshiLib/Include/kenshi/BountyManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isCommittingCrime | isCommittingCrime | boolean | R | `obj.isCommittingCrime` |
| crimeExpiry | crimeExpiry | number | RW | `obj.crimeExpiry = <value>` |
| prisonSentenceToServe | prisonSentenceToServe | number | RW | `obj.prisonSentenceToServe = <value>` |
| committingCrime | committingCrime | integer | RW | `obj.committingCrime = <value>` |
| totalBounty | getTotalBounty | integer | R | `obj.totalBounty` |
| accessPassExpirationTime | accessPassExpirationTime | number | R | `obj.accessPassExpirationTime` |
| prisonSentenceBeganTime | prisonSentenceBeganTime | number | R | `obj.prisonSentenceBeganTime` |
| me | me | unknown | W | `obj.me = <value>` |
| crimeAgainstFaction | crimeAgainstFaction | unknown | W | `obj.crimeAgainstFaction = <value>` |
| usingTrainingEquipmentOf | usingTrainingEquipmentOf | unknown | W | `obj.usingTrainingEquipmentOf = <value>` |
| crimeAgainst | crimeAgainst | unknown | W | `obj.crimeAgainst = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isCommittingCrime | isCommittingCrime | `obj:isCommittingCrime(...)` |
| getTotalBounty | getTotalBounty | `obj:getTotalBounty(...)` |
| getPercievedBounty | getPercievedBounty | `obj:getPercievedBounty(...)` |
| getActualBounty | getActualBounty | `obj:getActualBounty(...)` |
| clearBounty | clearBounty | `obj:clearBounty(...)` |
| unfairAddToBounty | unfairAddToBounty | `obj:unfairAddToBounty(...)` |
| hasAccessPass | hasAccessPass | `obj:hasAccessPass(...)` |
| giveAccessPass | giveAccessPass | `obj:giveAccessPass(...)` |
| notifyPlayerClaimBounty | notifyPlayerClaimBounty | `obj:notifyPlayerClaimBounty(...)` |
| bountyAlreadyBeenClaimedByPlayer | bountyAlreadyBeenClaimedByPlayer | `obj:bountyAlreadyBeenClaimedByPlayer(...)` |
| assignBountyForCrimes | assignBountyForCrimes | `obj:assignBountyForCrimes(...)` |
| getBountyRecognitionThreshold | getBountyRecognitionThreshold | `obj:getBountyRecognitionThreshold(...)` |
| update | update | `obj:update(...)` |
| getBountyExpiryStringForGUI | getBountyExpiryStringForGUI | `obj:getBountyExpiryStringForGUI(...)` |
| load | load | `obj:load(...)` |
| save | save | `obj:save(...)` |
| setCrime | setCrime | `obj:setCrime(...)` |
| notifyCrimeWitnessed | notifyCrimeWitnessed | `obj:notifyCrimeWitnessed(...)` |
| notifyPossibleCrimeWitnessed | notifyPossibleCrimeWitnessed | `obj:notifyPossibleCrimeWitnessed(...)` |
| notifyStartPrisonSentence | notifyStartPrisonSentence | `obj:notifyStartPrisonSentence(...)` |
| crimeToStr | crimeToStr | `obj:crimeToStr(...)` |
| getBountyForCrime | getBountyForCrime | `obj:getBountyForCrime(...)` |
| getPrisonSentenceInHours | getPrisonSentenceInHours | `obj:getPrisonSentenceInHours(...)` |
| getBountyExpirationTime | getBountyExpirationTime | `obj:getBountyExpirationTime(...)` |

## Building
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| justBeenUpgraded | justBeenUpgradedFlag | boolean | RW | `obj.justBeenUpgraded = <value>` |
| isOutsideFurniture | isOutsideFurniture | boolean | RW | `obj.isOutsideFurniture = <value>` |
| lightsVisible | lightsVisible | boolean | RW | `obj.lightsVisible = <value>` |
| heightAboveGround | heightAboveGround | number | RW | `obj.heightAboveGround = <value>` |
| designation | designation | integer | RW | `obj.designation = <value>` |
| materialName | materialName | string | RW | `obj.materialName = <value>` |
| isFurnitureOf | isFurnitureOf | lightuserdata | R | `obj.isFurnitureOf` |
| isFoliage | isFoliage | unknown | W | `obj.isFoliage = <value>` |
| hasTerrainInside | hasTerrainInside | unknown | W | `obj.hasTerrainInside = <value>` |
| isCavernous | isCavernous | unknown | W | `obj.isCavernous = <value>` |
| enforceCeiling | enforceCeiling | unknown | W | `obj.enforceCeiling = <value>` |
| publicDaytime | publicDaytime | unknown | W | `obj.publicDaytime = <value>` |
| updateNavmesh | updateNavmesh | unknown | W | `obj.updateNavmesh = <value>` |
| visible | visible | unknown | W | `obj.visible = <value>` |
| interiorVisibility | interiorVisibility | unknown | W | `obj.interiorVisibility = <value>` |
| imADoor | imADoor | unknown | W | `obj.imADoor = <value>` |
| hasMovingParts | hasMovingParts | unknown | W | `obj.hasMovingParts = <value>` |
| isAnInteriorObject | isAnInteriorObject | unknown | W | `obj.isAnInteriorObject = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getName | getName | `obj:getName(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| getBuildingDesignation | getBuildingDesignation | `obj:getBuildingDesignation(...)` |
| getBuildingClass | getBuildingClass | `obj:getBuildingClass(...)` |
| getSpecialFunction | getSpecialFunction | `obj:getSpecialFunction(...)` |
| getBuildState | getBuildState | `obj:getBuildState(...)` |
| getConstructionProgress | getConstructionProgress | `obj:getConstructionProgress(...)` |
| isPublic | isPublic | `obj:isPublic(...)` |
| isAShop | isAShop | `obj:isAShop(...)` |
| isForSale | isForSale | `obj:isForSale(...)` |
| isAWall | isAWall | `obj:isAWall(...)` |
| isDamaged | isDamaged | `obj:isDamaged(...)` |
| isDestroyed | isDestroyed | `obj:isDestroyed(...)` |
| isBroken | isBroken | `obj:isBroken(...)` |
| isPowerOn | isPowerOn | `obj:isPowerOn(...)` |
| getScale | getScale | `obj:getScale(...)` |
| getMiningResourceLevel | getMiningResourceLevel | `obj:getMiningResourceLevel(...)` |
| isValid | isValid | `obj:isValid(...)` |
| setDesignation | setDesignation | `obj:setDesignation(...)` |
| setBroken | setBroken | `obj:setBroken(...)` |
| setDestroyed | setDestroyed | `obj:setDestroyed(...)` |
| setConstructionProgress | setConstructionProgress | `obj:setConstructionProgress(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| switchPowerOn | switchPowerOn | `obj:switchPowerOn(...)` |
| togglePublic | togglePublic | `obj:togglePublic(...)` |

## CameraClass
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| freeCameraMode | freeCameraMode | boolean | RW | `obj.freeCameraMode = <value>` |
| isRotating | isRotating | boolean | RW | `obj.isRotating = <value>` |
| initialised | initialised | boolean | RW | `obj.initialised = <value>` |
| terrainLoaded | terrainLoaded | boolean | RW | `obj.terrainLoaded = <value>` |
| yaw | yaw | number | RW | `obj.yaw = <value>` |
| pitch | pitch | number | RW | `obj.pitch = <value>` |
| altitude | altitude | number | RW | `obj.altitude = <value>` |
| timeInGame | timeInGame | number | RW | `obj.timeInGame = <value>` |
| targetPositionY | targetPositionY | number | RW | `obj.targetPositionY = <value>` |
| speedY | speedY | number | RW | `obj.speedY = <value>` |
| centerBuildingY | centerBuildingY | number | RW | `obj.centerBuildingY = <value>` |
| currentMusic | currentMusic | number | R | `obj.currentMusic` |
| rotationMarker | rotationMarker | lightuserdata | R | `obj.rotationMarker` |
| center | center | lightuserdata | R | `obj.center` |
| camera | camera | lightuserdata | R | `obj.camera` |
| node | node | lightuserdata | R | `obj.node` |
| centerBuilding | centerBuilding | unknown | W | `obj.centerBuilding = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| save | save | `obj:save(...)` |
| load | load | `obj:load(...)` |
| reset | reset | `obj:reset(...)` |
| update | update | `obj:update(...)` |
| updateOptionSettings | updateOptionSettings | `obj:updateOptionSettings(...)` |
| isVisible | isVisible | `obj:isVisible(...)` |
| intersectScreenEdge | intersectScreenEdge | `obj:intersectScreenEdge(...)` |
| focusCameraOnObject | focusCameraOnObject | `obj:focusCameraOnObject(...)` |
| teleport | teleport | `obj:teleport(...)` |
| followObject | followObject | `obj:followObject(...)` |
| stopFollowing | stopFollowing | `obj:stopFollowing(...)` |
| getFollowObject | getFollowObject | `obj:getFollowObject(...)` |
| manuallySetOrientationAndZoom | manuallySetOrientationAndZoom | `obj:manuallySetOrientationAndZoom(...)` |
| getFacingDirection | getFacingDirection | `obj:getFacingDirection(...)` |
| getCenter | getCenter | `obj:getCenter(...)` |
| getCameraPos | getCameraPos | `obj:getCameraPos(...)` |
| isFreeCameraMode | isFreeCameraMode | `obj:isFreeCameraMode(...)` |
| setFreeCameraMode | setFreeCameraMode | `obj:setFreeCameraMode(...)` |
| move | move | `obj:move(...)` |
| zoom | zoom | `obj:zoom(...)` |
| toGround | toGround | `obj:toGround(...)` |
| setZoomDist | setZoomDist | `obj:setZoomDist(...)` |
| rotate | rotate | `obj:rotate(...)` |
| rotationUpdate | rotationUpdate | `obj:rotationUpdate(...)` |
| updateAudio | updateAudio | `obj:updateAudio(...)` |

## CharBody
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| gotItem | gotItem | boolean | RW | `obj.gotItem = <value>` |
| crouched | crouched | boolean | RW | `obj.crouched = <value>` |
| jogMode | jogMode | boolean | RW | `obj.jogMode = <value>` |
| arbitraryCatchupDist | arbitraryCatchupDist | number | RW | `obj.arbitraryCatchupDist = <value>` |
| frameTIME | frameTIME | number | RW | `obj.frameTIME = <value>` |
| amIdle | amIdle | boolean | RW | `obj.amIdle = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _CONSTRUCTOR | _CONSTRUCTOR | `obj:_CONSTRUCTOR(...)` |
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
| getName | getName | `obj:getName(...)` |
| isCharacter | isCharacter | `obj:isCharacter(...)` |
| _NV_isCharacter | _NV_isCharacter | `obj:_NV_isCharacter(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| _NV_getCharacter | _NV_getCharacter | `obj:_NV_getCharacter(...)` |
| getCharBody | getCharBody | `obj:getCharBody(...)` |
| _NV_getCharBody | _NV_getCharBody | `obj:_NV_getCharBody(...)` |
| getUpFromRagdoll | getUpFromRagdoll | `obj:getUpFromRagdoll(...)` |
| getPlatoon | getPlatoon | `obj:getPlatoon(...)` |
| _NV_getPlatoon | _NV_getPlatoon | `obj:_NV_getPlatoon(...)` |
| endAction | endAction | `obj:endAction(...)` |
| isIdle | isIdle | `obj:isIdle(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| _endAction | _endAction | `obj:_endAction(...)` |
| _NV__endAction | _NV__endAction | `obj:_NV__endAction(...)` |

## CharStats
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
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
| currentWeaponLength | currentWeaponLength | number | RW | `obj.currentWeaponLength = <value>` |
| weaponWeight | weaponWeight | number | RW | `obj.weaponWeight = <value>` |
| _defensiveMode | _defensiveMode | boolean | RW | `obj._defensiveMode = <value>` |
| rangedMode | rangedMode | boolean | RW | `obj.rangedMode = <value>` |
| tauntMode | tauntMode | boolean | RW | `obj.tauntMode = <value>` |
| _holdPositionMode | _holdPositionMode | boolean | RW | `obj._holdPositionMode = <value>` |
| passiveCombatMode | passiveCombatMode | boolean | RW | `obj.passiveCombatMode = <value>` |
| freeAttributePoints | freeAttributePoints | integer | RW | `obj.freeAttributePoints = <value>` |
| currentWeaponType | currentWeaponType | integer | RW | `obj.currentWeaponType = <value>` |
| medical | medical | unknown | W | `obj.medical = <value>` |
| me | me | unknown | W | `obj.me = <value>` |
| weapon | weapon | unknown | W | `obj.weapon = <value>` |
| holdLocation | holdLocation | unknown | W | `obj.holdLocation = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getStrength | getStrength | `obj:getStrength(...)` |
| getStrengthRaw | getStrengthRaw | `obj:getStrengthRaw(...)` |
| getDexterity | getDexterity | `obj:getDexterity(...)` |
| getDexterityRaw | getDexterityRaw | `obj:getDexterityRaw(...)` |
| getToughness | getToughness | `obj:getToughness(...)` |
| getToughnessRaw | getToughnessRaw | `obj:getToughnessRaw(...)` |
| getPerception | getPerception | `obj:getPerception(...)` |
| getAthletics | getAthletics | `obj:getAthletics(...)` |
| getMeleeAttack | getMeleeAttack | `obj:getMeleeAttack(...)` |
| getMeleeDefence | getMeleeDefence | `obj:getMeleeDefence(...)` |
| getDodge | getDodge | `obj:getDodge(...)` |
| getMassCombat | getMassCombat | `obj:getMassCombat(...)` |
| getMartialArts | getMartialArts | `obj:getMartialArts(...)` |
| getKatanas | getKatanas | `obj:getKatanas(...)` |
| getSabres | getSabres | `obj:getSabres(...)` |
| getHackers | getHackers | `obj:getHackers(...)` |
| getBlunt | getBlunt | `obj:getBlunt(...)` |
| getHeavyWeapons | getHeavyWeapons | `obj:getHeavyWeapons(...)` |
| getPolearms | getPolearms | `obj:getPolearms(...)` |
| getBows | getBows | `obj:getBows(...)` |
| getTurrets | getTurrets | `obj:getTurrets(...)` |
| getStealth | getStealth | `obj:getStealth(...)` |
| getThieving | getThieving | `obj:getThieving(...)` |
| getLockpicking | getLockpicking | `obj:getLockpicking(...)` |
| getAssassination | getAssassination | `obj:getAssassination(...)` |
| getSurvival | getSurvival | `obj:getSurvival(...)` |
| getTracking | getTracking | `obj:getTracking(...)` |
| getClimbing | getClimbing | `obj:getClimbing(...)` |
| getSwimming | getSwimming | `obj:getSwimming(...)` |
| getBluff | getBluff | `obj:getBluff(...)` |
| getFieldMedic | getFieldMedic | `obj:getFieldMedic(...)` |
| getDoctor | getDoctor | `obj:getDoctor(...)` |
| getScience | getScience | `obj:getScience(...)` |
| getEngineer | getEngineer | `obj:getEngineer(...)` |
| getRobotics | getRobotics | `obj:getRobotics(...)` |
| getLabouring | getLabouring | `obj:getLabouring(...)` |
| getFarming | getFarming | `obj:getFarming(...)` |
| getCooking | getCooking | `obj:getCooking(...)` |
| getWeaponSmith | getWeaponSmith | `obj:getWeaponSmith(...)` |
| getArmourSmith | getArmourSmith | `obj:getArmourSmith(...)` |
| getBowSmith | getBowSmith | `obj:getBowSmith(...)` |
| getXp | getXp | `obj:getXp(...)` |
| getFreeAttributePoints | getFreeAttributePoints | `obj:getFreeAttributePoints(...)` |
| getOverallSkillLevel | getOverallSkillLevel | `obj:getOverallSkillLevel(...)` |
| isUnarmed | isUnarmed | `obj:isUnarmed(...)` |
| isDefensiveMode | isDefensiveMode | `obj:isDefensiveMode(...)` |
| isHoldPositionMode | isHoldPositionMode | `obj:isHoldPositionMode(...)` |
| isRangedMode | isRangedMode | `obj:isRangedMode(...)` |
| getMedicalSystem | getMedicalSystem | `obj:getMedicalSystem(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| setEquippedWeaponSkill | setEquippedWeaponSkill | `obj:setEquippedWeaponSkill(...)` |
| _NV_setEquippedWeaponSkill | _NV_setEquippedWeaponSkill | `obj:_NV_setEquippedWeaponSkill(...)` |
| setEquipmentStatBonuses | setEquipmentStatBonuses | `obj:setEquipmentStatBonuses(...)` |

## Character
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| stealthMode | stealthMode | boolean | RW | `obj.stealthMode = <value>` |
| _isOnARoof | _isOnARoof | boolean | RW | `obj._isOnARoof = <value>` |
| needsLightLevel | needsLightLevel | boolean | RW | `obj.needsLightLevel = <value>` |
| isVisibleUpdateMode | isVisibleUpdateMode | boolean | RW | `obj.isVisibleUpdateMode = <value>` |
| setVisibleMsg | setVisibleMsg | boolean | RW | `obj.setVisibleMsg = <value>` |
| playerWantsMeToGetUp | playerWantsMeToGetUp | boolean | RW | `obj.playerWantsMeToGetUp = <value>` |
| isCarryingSomething | isCarryingSomething | boolean | RW | `obj.isCarryingSomething = <value>` |
| isCarryingLeftSide | isCarryingLeftSide | boolean | RW | `obj.isCarryingLeftSide = <value>` |
| _isBeingCarried | _isBeingCarried | boolean | RW | `obj._isBeingCarried = <value>` |
| isPhysicalMode | isPhysicalMode | boolean | RW | `obj.isPhysicalMode = <value>` |
| isChained | isChained | boolean | RW | `obj.isChained = <value>` |
| isCurrentlyGettingUp | isCurrentlyGettingUp | boolean | RW | `obj.isCurrentlyGettingUp = <value>` |
| _isEngagedWithAPlayer | _isEngagedWithAPlayer | boolean | RW | `obj._isEngagedWithAPlayer = <value>` |
| isVisibleAndNear | isVisibleAndNear | boolean | RW | `obj.isVisibleAndNear = <value>` |
| isOnScreen | isOnScreen | boolean | RW | `obj.isOnScreen = <value>` |
| isLiterallyUnderAttack | _isLiterallyUnderMeleeAttackRightNowForSure | boolean | RW | `obj.isLiterallyUnderAttack = <value>` |
| isOnARoof | _isOnARoof | boolean | R | `obj.isOnARoof` |
| isEngagedWithAPlayer | _isEngagedWithAPlayer | boolean | R | `obj.isEngagedWithAPlayer` |
| isBeingCarried | _isBeingCarried | boolean | R | `obj.isBeingCarried` |
| offscreenFrameTime | offscreenFrameTime | number | RW | `obj.offscreenFrameTime = <value>` |
| frameTIME | frameTIME | number | RW | `obj.frameTIME = <value>` |
| frameTIMEfour | frameTIMEfour | number | RW | `obj.frameTIMEfour = <value>` |
| frameTIME_P | frameTIME_P | number | RW | `obj.frameTIME_P = <value>` |
| bodyDecayTimer | bodyDecayTimer | number | RW | `obj.bodyDecayTimer = <value>` |
| _lightLevel | _lightLevel | number | RW | `obj._lightLevel = <value>` |
| diplomacyMultiplier | diplomacyMultiplier | number | RW | `obj.diplomacyMultiplier = <value>` |
| terrainHeightPosition | terrainHeightPosition | number | RW | `obj.terrainHeightPosition = <value>` |
| lightLevel | _lightLevel | number | R | `obj.lightLevel` |
| _currentProneState | _currentProneState | integer | RW | `obj._currentProneState = <value>` |
| squadMemberID | squadMemberID | integer | RW | `obj.squadMemberID = <value>` |
| _destinationInsideWalls | _destinationInsideWalls | integer | RW | `obj._destinationInsideWalls = <value>` |
| portraitIndex | portraitIndex | integer | RW | `obj.portraitIndex = <value>` |
| portraitSerial | portraitSerial | integer | RW | `obj.portraitSerial = <value>` |
| audioObject | audioObject | integer | RW | `obj.audioObject = <value>` |
| stealthUnseen | stealthUnseen | integer | RW | `obj.stealthUnseen = <value>` |
| currentSkillUsing | currentSkillUsing | integer | RW | `obj.currentSkillUsing = <value>` |
| isGettingEaten | isGettingEaten | integer | RW | `obj.isGettingEaten = <value>` |
| inSomething | inSomething | integer | RW | `obj.inSomething = <value>` |
| lastUsedWeaponCategory | lastUsedWeaponCategory | integer | RW | `obj.lastUsedWeaponCategory = <value>` |
| groundType | groundType | integer | RW | `obj.groundType = <value>` |
| armourType | armourType | integer | RW | `obj.armourType = <value>` |
| currentProneState | _currentProneState | integer | R | `obj.currentProneState` |
| destinationInsideWalls | _destinationInsideWalls | integer | R | `obj.destinationInsideWalls` |
| currentStumblePainAnimation | currentStumblePainAnimation | string | RW | `obj.currentStumblePainAnimation = <value>` |
| carryingObjectLeftOrRight | carringObjectLeftOrRight | string | RW | `obj.carryingObjectLeftOrRight = <value>` |
| sex | sex | string | RW | `obj.sex = <value>` |
| myMemory | _myMemory | lightuserdata | R | `obj.myMemory` |
| isUsingTurret | isUsingTurret | unknown | W | `obj.isUsingTurret = <value>` |
| slaveOwner | slaveOwner | unknown | W | `obj.slaveOwner = <value>` |
| inWhat | inWhat | unknown | W | `obj.inWhat = <value>` |
| carryingObject | carryingObject | unknown | W | `obj.carryingObject = <value>` |
| messageSubject | messageSubject | unknown | W | `obj.messageSubject = <value>` |
| _destinationInsideBuilding | _destinationInsideBuilding | unknown | W | `obj._destinationInsideBuilding = <value>` |
| stats | stats | unknown | W | `obj.stats = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isValid | isValid | `obj:isValid(...)` |
| isPlayerCharacter | isPlayerCharacter | `obj:isPlayerCharacter(...)` |
| isUnique | isUnique | `obj:isUnique(...)` |
| isFemale | isFemale | `obj:isFemale(...)` |
| isDestroyed | isDestroyed | `obj:isDestroyed(...)` |
| isDead | isDead | `obj:isDead(...)` |
| getName | getName | `obj:getName(...)` |
| setName | setName | `obj:setName(...)` |
| setNameTagVisible | setNameTagVisible | `obj:setNameTagVisible(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| getBoneWorldPosition | getBoneWorldPosition | `obj:getBoneWorldPosition(...)` |
| getMovementSpeed | getMovementSpeed | `obj:getMovementSpeed(...)` |
| getMovementDirection | getMovementDirection | `obj:getMovementDirection(...)` |
| teleport | teleport | `obj:teleport(...)` |
| setDestination | setDestination | `obj:setDestination(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| setFaction | setFaction | `obj:setFaction(...)` |
| getRace | getRace | `obj:getRace(...)` |
| getPlatoon | getPlatoon | `obj:getPlatoon(...)` |
| getSquadLeader | getSquadLeader | `obj:getSquadLeader(...)` |
| isUnconcious | isUnconcious | `obj:isUnconcious(...)` |
| isDown | isDown | `obj:isDown(...)` |
| isRagdoll | isRagdoll | `obj:isRagdoll(...)` |
| isCrippled | isCrippled | `obj:isCrippled(...)` |
| isInCombatMode | isInCombatMode | `obj:isInCombatMode(...)` |
| isInRangedCombatMode | isInRangedCombatMode | `obj:isInRangedCombatMode(...)` |
| isFleeing | isFleeing | `obj:isFleeing(...)` |
| isStealthMode | isStealthMode | `obj:isStealthMode(...)` |
| isInjured | isInjured | `obj:isInjured(...)` |
| isKidnapped | isKidnapped | `obj:isKidnapped(...)` |
| getProneState | getProneState | `obj:getProneState(...)` |
| setProneState | setProneState | `obj:setProneState(...)` |
| isEnemy | isEnemy | `obj:isEnemy(...)` |
| isAlly | isAlly | `obj:isAlly(...)` |
| attackTarget | attackTarget | `obj:attackTarget(...)` |
| endCombatMode | endCombatMode | `obj:endCombatMode(...)` |
| getCurrentWeapon | getCurrentWeapon | `obj:getCurrentWeapon(...)` |
| getAttackTarget | getAttackTarget | `obj:getAttackTarget(...)` |
| healCompletely | healCompletely | `obj:healCompletely(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| getStats | getStats | `obj:getStats(...)` |
| getMedical | getMedical | `obj:getMedical(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| hasItem | hasItem | `obj:hasItem(...)` |
| hasRoomForItem | hasRoomForItem | `obj:hasRoomForItem(...)` |
| sayALine | sayALine | `obj:sayALine(...)` |
| say | say | `obj:say(...)` |
| sendDialogEvent | sendDialogEvent | `obj:sendDialogEvent(...)` |
| sendDialogEventOverride | sendDialogEventOverride | `obj:sendDialogEventOverride(...)` |
| hasDialogue | hasDialogue | `obj:hasDialogue(...)` |
| setStandingOrder | setStandingOrder | `obj:setStandingOrder(...)` |
| getStandingOrder | getStandingOrder | `obj:getStandingOrder(...)` |
| setStealthMode | setStealthMode | `obj:setStealthMode(...)` |
| getAge | getAge | `obj:getAge(...)` |
| setAge | setAge | `obj:setAge(...)` |
| setSquadMemberType | setSquadMemberType | `obj:setSquadMemberType(...)` |
| rememberCharacter | rememberCharacter | `obj:rememberCharacter(...)` |
| isImmuneToOffscreenMode | isImmuneToOffscreenMode | `obj:isImmuneToOffscreenMode(...)` |

## CharacterAnimal
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| weaponIsTechnicallyEquipped | weaponIsTechnicallyEquipped | boolean | RW | `obj.weaponIsTechnicallyEquipped = <value>` |
| HPMultiplier | HPMultiplier | number | RW | `obj.HPMultiplier = <value>` |
| smellThresholdBlood | smellThresholdBlood | number | RW | `obj.smellThresholdBlood = <value>` |
| smellThresholdEggs | smellThresholdEggs | number | RW | `obj.smellThresholdEggs = <value>` |
| ageSizeMin | ageSizeMin | number | RW | `obj.ageSizeMin = <value>` |
| ageSizeMax | ageSizeMax | number | RW | `obj.ageSizeMax = <value>` |
| lifespanInDays | lifespanInDays | number | RW | `obj.lifespanInDays = <value>` |
| lastUpdatedAge | lastUpdatedAge | number | RW | `obj.lastUpdatedAge = <value>` |
| age | age | number | RW | `obj.age = <value>` |
| audioTimeStamp | audioTimeStamp | number | RW | `obj.audioTimeStamp = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
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

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getCut | getCut | `obj:getCut(...)` |
| setCut | setCut | `obj:setCut(...)` |
| getBlunt | getBlunt | `obj:getBlunt(...)` |
| setBlunt | setBlunt | `obj:setBlunt(...)` |
| getPierce | getPierce | `obj:getPierce(...)` |
| setPierce | setPierce | `obj:setPierce(...)` |
| getBleed | getBleed | `obj:getBleed(...)` |
| setBleed | setBleed | `obj:setBleed(...)` |
| getArmourPenetration | getArmourPenetration | `obj:getArmourPenetration(...)` |
| setArmourPenetration | setArmourPenetration | `obj:setArmourPenetration(...)` |
| total | total | `obj:total(...)` |
| multiply | multiply | `obj:multiply(...)` |

## Dialogue
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| shouting | shouting | boolean | RW | `obj.shouting = <value>` |
| staysOnScreen | staysOnScreen | boolean | RW | `obj.staysOnScreen = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| getConversationTarget | getConversationTarget | `obj:getConversationTarget(...)` |
| hasDialogueEvent | hasDialogueEvent | `obj:hasDialogueEvent(...)` |
| willTalkToEnemies | willTalkToEnemies | `obj:willTalkToEnemies(...)` |
| conversationHasEnded | conversationHasEnded | `obj:conversationHasEnded(...)` |
| sendEvent | sendEvent | `obj:sendEvent(...)` |
| sendEventOverride | sendEventOverride | `obj:sendEventOverride(...)` |
| endDialogue | endDialogue | `obj:endDialogue(...)` |
| isValid | isValid | `obj:isValid(...)` |

## DialogueEvent
**Header:** `???`

## Faction
**Header:** `extern/KenshiLib/Include/kenshi/AppearanceManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isThePlayer | isThePlayer | boolean | R | `obj.isThePlayer` |
| isAntiSlavery | isAntiSlavery | boolean | R | `obj.isAntiSlavery` |
| isALawEnforcementFaction | isALawEnforcementFaction | boolean | R | `obj.isALawEnforcementFaction` |
| prosperityMultiplier | getProsperityMultiplier | number | R | `obj.prosperityMultiplier` |
| roadPreference | getRoadPreference | number | R | `obj.roadPreference` |
| factionSize | getFactionSize | integer | R | `obj.factionSize` |
| name | name | string | R | `obj.name` |
| allowSlavesWeapons | allowSlavesWeapons | boolean | RW | `obj.allowSlavesWeapons = <value>` |
| diplomatTimeStamp | diplomatTimeStamp | integer | RW | `obj.diplomatTimeStamp = <value>` |
| fundamentalNPCType | fundamentalNPCType | integer | RW | `obj.fundamentalNPCType = <value>` |
| ranks | ranks | string | R | `obj.ranks` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getName | getName | `obj:getName(...)` |
| setName | setName | `obj:setName(...)` |
| isThePlayer | isThePlayer | `obj:isThePlayer(...)` |
| isNotARealFaction | isNotARealFaction | `obj:isNotARealFaction(...)` |
| isAntiSlavery | isAntiSlavery | `obj:isAntiSlavery(...)` |
| isALawEnforcementFaction | isALawEnforcementFaction | `obj:isALawEnforcementFaction(...)` |
| getLawEnforcementFaction | getLawEnforcementFaction | `obj:getLawEnforcementFaction(...)` |
| getFactionSize | getFactionSize | `obj:getFactionSize(...)` |
| getNumPlatoons | getNumPlatoons | `obj:getNumPlatoons(...)` |
| getProsperityMultiplier | getProsperityMultiplier | `obj:getProsperityMultiplier(...)` |
| getRoadPreference | getRoadPreference | `obj:getRoadPreference(...)` |
| getRelation | getRelation | `obj:getRelation(...)` |
| setRelation | setRelation | `obj:setRelation(...)` |
| declareWar | declareWar | `obj:declareWar(...)` |
| declarePeace | declarePeace | `obj:declarePeace(...)` |
| createPlatoon | createPlatoon | `obj:createPlatoon(...)` |

## GameData
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | visible | boolean | RW | `obj.visible = <value>` |
| category | category | string | RW | `obj.category = <value>` |
| description | description | string | RW | `obj.description = <value>` |
| fileTypes | fileTypes | string | RW | `obj.fileTypes = <value>` |
| maxSize | maxSize | integer | RW | `obj.maxSize = <value>` |
| maxValue | maxValue | integer | RW | `obj.maxValue = <value>` |
| minValue | minValue | integer | RW | `obj.minValue = <value>` |
| isSlider | isSlider | boolean | RW | `obj.isSlider = <value>` |
| refID | refID | string | RW | `obj.refID = <value>` |
| created | created | integer | RW | `obj.created = <value>` |
| modified | modified | integer | RW | `obj.modified = <value>` |
| validity | validity | integer | RW | `obj.validity = <value>` |
| isStandalone | isStandalone | boolean | RW | `obj.isStandalone = <value>` |
| id | id | integer | RW | `obj.id = <value>` |
| readOnly | readOnly | boolean | RW | `obj.readOnly = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| isFromActiveFile | isFromActiveFile | boolean | RW | `obj.isFromActiveFile = <value>` |
| currentID | currentID | integer | RW | `obj.currentID = <value>` |
| createdIndex | createdIndex | integer | RW | `obj.createdIndex = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isValid | isValid | `obj:isValid(...)` |
| destroy | destroy | `obj:destroy(...)` |
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
| addDeletedInstance | addDeletedInstance | `obj:addDeletedInstance(...)` |

## GameWorld
**Header:** `extern/KenshiLib/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isPaused | isPaused | boolean | R | `obj.isPaused` |
| frameSpeedMultiplier | getFrameSpeedMultiplier | number | R | `obj.frameSpeedMultiplier` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getCameraCenter | getCameraCenter | `obj:getCameraCenter(...)` |
| getCameraPos | getCameraPos | `obj:getCameraPos(...)` |
| isPaused | isPaused | `obj:isPaused(...)` |
| getFrameSpeedMultiplier | getFrameSpeedMultiplier | `obj:getFrameSpeedMultiplier(...)` |
| getLightLevel | getLightLevel | `obj:getLightLevel(...)` |
| setPaused | setPaused | `obj:setPaused(...)` |
| setGameSpeed | setGameSpeed | `obj:setGameSpeed(...)` |
| setFrameSpeedMultiplier | setFrameSpeedMultiplier | `obj:setFrameSpeedMultiplier(...)` |
| showMessage | showMessage | `obj:showMessage(...)` |
| playSound | playSound | `obj:playSound(...)` |
| getPlayer | getPlayer | `obj:getPlayer(...)` |

## Gear
**Header:** `extern/KenshiLib/Include/kenshi/Gear.h`

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isAFactionUniform | isAFactionUniform | `obj:isAFactionUniform(...)` |
| isPlayerCrafted | isPlayerCrafted | `obj:isPlayerCrafted(...)` |

## Global
**Header:** `???`

## Hand
**Header:** `???`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isValid | isValid | boolean | R | `obj.isValid` |
| isNull | isNull | boolean | R | `obj.isNull` |
| type | type | integer | RW | `obj.type = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| serial | serial | integer | RW | `obj.serial = <value>` |
| container | container | integer | RW | `obj.container = <value>` |
| containerSerial | containerSerial | integer | RW | `obj.containerSerial = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isValid | isValid | `obj:isValid(...)` |
| isNull | isNull | `obj:isNull(...)` |
| getType | getType | `obj:getType(...)` |
| getIndex | getIndex | `obj:getIndex(...)` |
| getSerial | getSerial | `obj:getSerial(...)` |
| getContainer | getContainer | `obj:getContainer(...)` |
| getContainerSerial | getContainerSerial | `obj:getContainerSerial(...)` |
| getCharacter | getCharacter | `obj:getCharacter(...)` |
| getPlatoon | getPlatoon | `obj:getPlatoon(...)` |
| getBuilding | getBuilding | `obj:getBuilding(...)` |
| getItem | getItem | `obj:getItem(...)` |
| getTown | getTown | `obj:getTown(...)` |

## InputHandler
**Header:** `extern/KenshiLib/Include/kenshi/Globals.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| ctrl | ctrl | boolean | RW | `obj.ctrl = <value>` |
| shift | shift | boolean | RW | `obj.shift = <value>` |
| alt | alt | boolean | RW | `obj.alt = <value>` |
| up | up | boolean | R | `obj.up` |
| down | down | boolean | R | `obj.down` |
| left | left | boolean | R | `obj.left` |
| right | right | boolean | R | `obj.right` |
| space | space | boolean | R | `obj.space` |
| pgup | pgup | boolean | R | `obj.pgup` |
| pgdn | pgdn | boolean | R | `obj.pgdn` |
| comma | comma | boolean | R | `obj.comma` |
| period | period | boolean | R | `obj.period` |
| f1 | f1 | boolean | R | `obj.f1` |
| f2 | f2 | boolean | R | `obj.f2` |
| escape | escape | boolean | R | `obj.escape` |
| del | del | boolean | R | `obj.del` |
| zoomin | zoomin | boolean | R | `obj.zoomin` |
| zoomout | zoomout | boolean | R | `obj.zoomout` |
| rotate | rotate | boolean | R | `obj.rotate` |
| highlight | highlight | boolean | R | `obj.highlight` |
| mLeft | mLeft | boolean | R | `obj.mLeft` |
| mRight | mRight | boolean | R | `obj.mRight` |
| mLDown | mLDown | boolean | R | `obj.mLDown` |
| mRDown | mRDown | boolean | R | `obj.mRDown` |
| mLUp | mLUp | boolean | R | `obj.mLUp` |
| mRUp | mRUp | boolean | R | `obj.mRUp` |
| mWheel | mWheel | integer | R | `obj.mWheel` |
| mPos | mPos | number | R | `obj.mPos` |
| mPosAbs | mPosAbs | number | R | `obj.mPosAbs` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isKeyState | isKeyState | `obj:isKeyState(...)` |
| isBound | isBound | `obj:isBound(...)` |
| sendEvent | sendEvent | `obj:sendEvent(...)` |
| bind | bind | `obj:bind(...)` |
| unbind | unbind | `obj:unbind(...)` |
| unbindAll | unbindAll | `obj:unbindAll(...)` |
| getMousePos | getMousePos | `obj:getMousePos(...)` |
| getMousePosAbs | getMousePosAbs | `obj:getMousePosAbs(...)` |
| getMouseWheel | getMouseWheel | `obj:getMouseWheel(...)` |
| getModifiers | getModifiers | `obj:getModifiers(...)` |

## Inventory
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| hasRoomCache | hasRoomCache | integer | R | `obj.hasRoomCache` |
| totalWeight | totalWeight | number | RW | `obj.totalWeight = <value>` |
| name | name | string | RW | `obj.name = <value>` |
| width | width | integer | RW | `obj.width = <value>` |
| height | height | integer | RW | `obj.height = <value>` |
| armourOnly | armourOnly | boolean | RW | `obj.armourOnly = <value>` |
| stackingBonusMin | stackingBonusMin | integer | RW | `obj.stackingBonusMin = <value>` |
| stackingBonusMult | stackingBonusMult | number | RW | `obj.stackingBonusMult = <value>` |
| itemsLimit | itemsLimit | integer | RW | `obj.itemsLimit = <value>` |
| weightMultiplier | weightMultiplier | number | RW | `obj.weightMultiplier = <value>` |
| totalWeight | totalWeight | number | R | `obj.totalWeight` |
| isAnEquippedItemSection | isAnEquippedItemSection | boolean | RW | `obj.isAnEquippedItemSection = <value>` |
| containerSlot | containerSlot | boolean | RW | `obj.containerSlot = <value>` |
| enabled | enabled | boolean | RW | `obj.enabled = <value>` |
| x | x | integer | RW | `obj.x = <value>` |
| y | y | integer | RW | `obj.y = <value>` |
| w | w | integer | RW | `obj.w = <value>` |
| h | h | integer | RW | `obj.h = <value>` |
| item | item | unknown | W | `obj.item = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| clearAll | clearAll | `obj:clearAll(...)` |
| notifyModified | notifyModified | `obj:notifyModified(...)` |
| removeAllSections | removeAllSections | `obj:removeAllSections(...)` |
| hasStolenItems | hasStolenItems | `obj:hasStolenItems(...)` |
| hasWeaponEquipped | hasWeaponEquipped | `obj:hasWeaponEquipped(...)` |
| isAContainer | isAContainer | `obj:isAContainer(...)` |
| isEmpty | isEmpty | `obj:isEmpty(...)` |
| recalculateTotalWeight | recalculateTotalWeight | `obj:recalculateTotalWeight(...)` |
| getTotalWeight | getTotalWeight | `obj:getTotalWeight(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| isVisible | isVisible | `obj:isVisible(...)` |
| refreshGui | refreshGui | `obj:refreshGui(...)` |
| _NV_refreshGui | _NV_refreshGui | `obj:_NV_refreshGui(...)` |
| autoArrange | autoArrange | `obj:autoArrange(...)` |

## Item
**Header:** `extern/KenshiLib/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isResearchArtifact | isResearchArtifact | boolean | R | `obj.isResearchArtifact` |
| isEquipped | isEquipped | boolean | RW | `obj.isEquipped = <value>` |
| onGround | onGround | boolean | R | `obj.onGround` |
| isValid | isValid | boolean | R | `obj.isValid` |
| isInInventory | isInInventory | boolean | RW | `obj.isInInventory = <value>` |
| isTradeItem | isTradeItem | boolean | RW | `obj.isTradeItem = <value>` |
| isUnique | isUnique | boolean | RW | `obj.isUnique = <value>` |
| deathItem | deathItem | boolean | RW | `obj.deathItem = <value>` |
| quality | quality | number | RW | `obj.quality = <value>` |
| itemWeight | getItemWeight | number | R | `obj.itemWeight` |
| itemWeightSingle | getItemWeightSingle | number | R | `obj.itemWeightSingle` |
| originalFullChargeAmount | originalFullChargeAmount | number | RW | `obj.originalFullChargeAmount = <value>` |
| chargesLeft | chargesLeft | number | RW | `obj.chargesLeft = <value>` |
| level | getLevel | integer | R | `obj.level` |
| quantity | quantity | integer | RW | `obj.quantity = <value>` |
| slotType | slotType | integer | RW | `obj.slotType = <value>` |
| itemFunction | itemFunction | integer | RW | `obj.itemFunction = <value>` |
| itemWidth | itemWidth | integer | RW | `obj.itemWidth = <value>` |
| itemHeight | itemHeight | integer | RW | `obj.itemHeight = <value>` |
| objectType | objectType | integer | RW | `obj.objectType = <value>` |
| inventorySection | inventorySection | string | RW | `obj.inventorySection = <value>` |
| inventoryPos | inventoryPos | integer | R | `obj.inventoryPos` |
| visible | getVisible | boolean | R | `obj.visible` |
| athleticsMult | val | number | R | `obj.athleticsMult` |
| stealthMult | val | number | R | `obj.stealthMult` |
| combatSpeedMult | val | number | R | `obj.combatSpeedMult` |
| classType | getClassType | integer | R | `obj.classType` |
| combatSkillBonus | val | integer | R | `obj.combatSkillBonus` |
| modelName | getModelName | string | R | `obj.modelName` |
| isResearchArtifact | _isResearchArtifact | unknown | W | `obj.isResearchArtifact = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| resetCharges | resetCharges | `obj:resetCharges(...)` |
| getItemType | getItemType | `obj:getItemType(...)` |
| getItemWeight | getItemWeight | `obj:getItemWeight(...)` |
| getItemWeightSingle | getItemWeightSingle | `obj:getItemWeightSingle(...)` |
| getAvgPrice | getAvgPrice | `obj:getAvgPrice(...)` |
| addQuantity | addQuantity | `obj:addQuantity(...)` |
| subtractQuantity | subtractQuantity | `obj:subtractQuantity(...)` |
| getValueSingle | getValueSingle | `obj:getValueSingle(...)` |
| getValueAll | getValueAll | `obj:getValueAll(...)` |
| isStackable | isStackable | `obj:isStackable(...)` |
| canStackWith | canStackWith | `obj:canStackWith(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| getProperOwner | getProperOwner | `obj:getProperOwner(...)` |
| setProperOwner | setProperOwner | `obj:setProperOwner(...)` |
| getQuantity | getQuantity | `obj:getQuantity(...)` |
| getQuality | getQuality | `obj:getQuality(...)` |
| isResearchArtifact | isResearchArtifact | `obj:isResearchArtifact(...)` |
| onGround | onGround | `obj:onGround(...)` |
| isStolen | isStolen | `obj:isStolen(...)` |
| getLevel | getLevel | `obj:getLevel(...)` |
| getMaxAffordable | getMaxAffordable | `obj:getMaxAffordable(...)` |

## MedicalSystem
**Header:** `extern/KenshiLib/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| blood | blood | number | RW | `obj.blood = <value>` |
| hunger | hunger | number | RW | `obj.hunger = <value>` |
| fed | fed | number | RW | `obj.fed = <value>` |
| extra_bloodloss_from_bodyparts | extraBloodLossFromBodyparts | number | RW | `obj.extra_bloodloss_from_bodyparts = <value>` |
| current_bleed_rate | currentBleedRate | number | RW | `obj.current_bleed_rate = <value>` |
| knockout_timer | knockoutTimer | number | RW | `obj.knockout_timer = <value>` |
| worst_damage | worstDamage | number | RW | `obj.worst_damage = <value>` |
| needs_firstaid_scoretotal_robot | needsFirstAidScoreTotal_robot | number | RW | `obj.needs_firstaid_scoretotal_robot = <value>` |
| needs_firstaid_scoretotal_fleshy | needsFirstAidScoreTotal_fleshy | number | RW | `obj.needs_firstaid_scoretotal_fleshy = <value>` |
| rested_state | restedState | number | RW | `obj.rested_state = <value>` |
| stealth_hinderance | stealthHinderance | number | RW | `obj.stealth_hinderance = <value>` |
| part_best_arm | partBestArm | number | RW | `obj.part_best_arm = <value>` |
| part_head | partHead | number | RW | `obj.part_head = <value>` |
| part_worst_torso | partWorstTorso | number | RW | `obj.part_worst_torso = <value>` |
| dazed_or_alert | dazedOrAlert | number | RW | `obj.dazed_or_alert = <value>` |
| current_weather_affect_strength | currentWeatherAffectStrength | number | RW | `obj.current_weather_affect_strength = <value>` |
| next_KO_time | nextKOTime | number | RW | `obj.next_KO_time = <value>` |
| extraBloodLossFromBodyparts | extraBloodLossFromBodyparts | number | RW | `obj.extraBloodLossFromBodyparts = <value>` |
| currentBleedRate | currentBleedRate | number | RW | `obj.currentBleedRate = <value>` |
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
| currentWeatherAffectStrength | currentWeatherAffectStrength | number | RW | `obj.currentWeatherAffectStrength = <value>` |
| nextKOTime | nextKOTime | number | RW | `obj.nextKOTime = <value>` |
| eaten_death_delay | _eatenDeathDelay | integer | RW | `obj.eaten_death_delay = <value>` |
| _eatenDeathDelay | _eatenDeathDelay | integer | RW | `obj._eatenDeathDelay = <value>` |
| eatenDeathDelay | _eatenDeathDelay | integer | RW | `obj.eatenDeathDelay = <value>` |
| is_bloodyness_changed | bloodynessChanged | boolean | RW | `obj.is_bloodyness_changed = <value>` |
| is_bloodyness_cleaned_up | bloodynessCleanedUp | boolean | RW | `obj.is_bloodyness_cleaned_up = <value>` |
| is_crippled | crippled | boolean | RW | `obj.is_crippled = <value>` |
| is_unconcious | unconcious | boolean | RW | `obj.is_unconcious = <value>` |
| is_sub50_KO | sub50KO | boolean | RW | `obj.is_sub50_KO = <value>` |
| has_bloodloss_trauma | bloodlossTrauma | boolean | RW | `obj.has_bloodloss_trauma = <value>` |
| is_dead | dead | boolean | RW | `obj.is_dead = <value>` |
| is_right_arm_ok | rightArmOk | boolean | RW | `obj.is_right_arm_ok = <value>` |
| is_left_arm_ok | leftArmOk | boolean | RW | `obj.is_left_arm_ok = <value>` |
| bloodynessChanged | bloodynessChanged | boolean | RW | `obj.bloodynessChanged = <value>` |
| bloodynessCleanedUp | bloodynessCleanedUp | boolean | RW | `obj.bloodynessCleanedUp = <value>` |
| crippled | crippled | boolean | RW | `obj.crippled = <value>` |
| unconcious | unconcious | boolean | RW | `obj.unconcious = <value>` |
| sub50KO | sub50KO | boolean | RW | `obj.sub50KO = <value>` |
| bloodlossTrauma | bloodlossTrauma | boolean | RW | `obj.bloodlossTrauma = <value>` |
| dead | dead | boolean | RW | `obj.dead = <value>` |
| rightArmOk | rightArmOk | boolean | RW | `obj.rightArmOk = <value>` |
| leftArmOk | leftArmOk | boolean | RW | `obj.leftArmOk = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getBlood | getBlood | `obj:getBlood(...)` |
| getMaxBlood | getMaxBlood | `obj:getMaxBlood(...)` |
| getHunger | getHunger | `obj:getHunger(...)` |
| isFed | isFed | `obj:isFed(...)` |
| isReallyHungry | isReallyHungry | `obj:isReallyHungry(...)` |
| getKnockoutTimer | getKnockoutTimer | `obj:getKnockoutTimer(...)` |
| getOverallHealthRating | getOverallHealthRating | `obj:getOverallHealthRating(...)` |
| getStealthHinderance | getStealthHinderance | `obj:getStealthHinderance(...)` |
| isUnconcious | isUnconcious | `obj:isUnconcious(...)` |
| isCrippled | isCrippled | `obj:isCrippled(...)` |
| isDead | isDead | `obj:isDead(...)` |
| isInBloodlossTrauma | isInBloodlossTrauma | `obj:isInBloodlossTrauma(...)` |
| isLeftArmOk | isLeftArmOk | `obj:isLeftArmOk(...)` |
| isRightArmOk | isRightArmOk | `obj:isRightArmOk(...)` |
| hasRobotics | hasRobotics | `obj:hasRobotics(...)` |
| hasFreshlySeveredALimb | hasFreshlySeveredALimb | `obj:hasFreshlySeveredALimb(...)` |
| isProbablyDying | isProbablyDying | `obj:isProbablyDying(...)` |
| isFullyRested | isFullyRested | `obj:isFullyRested(...)` |
| knockoutForceTimer | knockoutForceTimer | `obj:knockoutForceTimer(...)` |
| gettingBurnt | gettingBurnt | `obj:gettingBurnt(...)` |
| gettingGassed | gettingGassed | `obj:gettingGassed(...)` |
| gettingEaten | gettingEaten | `obj:gettingEaten(...)` |
| gettingAcidRain | gettingAcidRain | `obj:gettingAcidRain(...)` |
| gettingAcidWater | gettingAcidWater | `obj:gettingAcidWater(...)` |
| gettingAcidFeet | gettingAcidFeet | `obj:gettingAcidFeet(...)` |
| gettingWindyFace | gettingWindyFace | `obj:gettingWindyFace(...)` |
| getToughnessXPBonus | getToughnessXPBonus | `obj:getToughnessXPBonus(...)` |
| getMissingArmPenalty | getMissingArmPenalty | `obj:getMissingArmPenalty(...)` |
| getHungerSpeedModifier | getHungerSpeedModifer | `obj:getHungerSpeedModifier(...)` |
| setHealth | setHealth | `obj:setHealth(...)` |
| getWeatherStatPenalty | getWeatherStatPenalty | `obj:getWeatherStatPenalty(...)` |

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

## Platoon
**Header:** `extern/KenshiLib/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | getName | string | R | `obj.name` |
| stringID | stringID | string | RW | `obj.stringID = <value>` |
| squadSize | getSquadSize | integer | R | `obj.squadSize` |
| characterCount | getCharacterCount | integer | R | `obj.characterCount` |
| characterCountCurrent | _characterCountCurrent | integer | RW | `obj.characterCountCurrent = <value>` |
| characterCountOriginal | _characterCountOriginal | integer | RW | `obj.characterCountOriginal = <value>` |
| squadType | squadType | integer | RW | `obj.squadType = <value>` |
| hasUniques | hasUniques | integer | RW | `obj.hasUniques = <value>` |
| speedOverride | speedOverride | integer | RW | `obj.speedOverride = <value>` |
| messageOnActivation | messageOnActivation | integer | RW | `obj.messageOnActivation = <value>` |
| index | index | integer | RW | `obj.index = <value>` |
| isValid | ap != 0 ? 1 : 0 | boolean | R | `obj.isValid` |
| isLoaded | isLoaded | boolean | R | `obj.isLoaded` |
| isTrader | getIsTrader | boolean | R | `obj.isTrader` |
| canRefresh | canRefresh | boolean | RW | `obj.canRefresh = <value>` |
| regenerates | regenerates | boolean | RW | `obj.regenerates = <value>` |
| iBuyStolenGoods | _iBuyStolenGoods | boolean | RW | `obj.iBuyStolenGoods = <value>` |
| iBuyIllegalGoods | _iBuyIllegalGoods | boolean | RW | `obj.iBuyIllegalGoods = <value>` |
| isIntact | _isIntact | boolean | RW | `obj.isIntact = <value>` |
| hasNeverBeenActivated | hasNeverBeenActivated | boolean | RW | `obj.hasNeverBeenActivated = <value>` |
| isResidentSquad | isResidentSquad | boolean | RW | `obj.isResidentSquad = <value>` |
| isDead | isDead | boolean | RW | `obj.isDead = <value>` |
| imprisoned | imprisoned | boolean | RW | `obj.imprisoned = <value>` |
| priceMultWhenITrade | priceMultWhenITrade | number | RW | `obj.priceMultWhenITrade = <value>` |
| malnourishedLevel | malnourishedLevel | number | RW | `obj.malnourishedLevel = <value>` |
| traderInventoryRefreshTime | traderInventoryRefreshTime | number | R | `obj.traderInventoryRefreshTime` |
| isSeparatedSquad | isSeparatedSquad | unknown | W | `obj.isSeparatedSquad = <value>` |
| squadleader | squadleader | unknown | W | `obj.squadleader = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isValid | isValid | `obj:isValid(...)` |
| getName | getName | `obj:getName(...)` |
| getSquadSize | getSquadSize | `obj:getSquadSize(...)` |
| getCharacterCount | getCharacterCount | `obj:getCharacterCount(...)` |
| getSquadLeader | getSquadLeader | `obj:getSquadLeader(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| isPersistentSquad | isPersistentSquad | `obj:isPersistentSquad(...)` |
| setPersistent | setPersistent | `obj:setPersistent(...)` |
| isLoaded | isLoaded | `obj:isLoaded(...)` |
| isTrader | isTrader | `obj:isTrader(...)` |
| teleport | teleport | `obj:teleport(...)` |
| activate | activate | `obj:activate(...)` |
| deactivate | deactivate | `obj:deactivate(...)` |
| declareDead | declareDead | `obj:declareDead(...)` |
| undeclareDead | undeclareDead | `obj:undeclareDead(...)` |
| isFullyLoaded | isFullyLoaded | `obj:isFullyLoaded(...)` |
| setupPatrolSettings | setupPatrolSettings | `obj:setupPatrolSettings(...)` |
| swapCharacters | swapCharacters | `obj:swapCharacters(...)` |
| clearAllTheUniqueNPCStates | clearAllTheUniqueNPCStates | `obj:clearAllTheUniqueNPCStates(...)` |
| refreshInventory | refreshInventory | `obj:refreshInventory(...)` |

## PlayerInterface
**Header:** `extern/KenshiLib/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isBuildMode | isBuildMode | boolean | R | `obj.isBuildMode` |
| characterEditorMode | characterEditorMode | boolean | RW | `obj.characterEditorMode = <value>` |
| mouseRightTargetSet | mouseRightTargetSet | boolean | RW | `obj.mouseRightTargetSet = <value>` |
| onlyAnimalsSelected | onlyAnimalsSelected | boolean | RW | `obj.onlyAnimalsSelected = <value>` |
| currentFloor | currentFloor | integer | RW | `obj.currentFloor = <value>` |
| currentMouseTask | currentMouseTask | integer | RW | `obj.currentMouseTask = <value>` |
| mouseTaskTypeRestriction | mouseTaskTypeRestriction | integer | RW | `obj.mouseTaskTypeRestriction = <value>` |
| rmouseTimer | rmouseTimer | number | RW | `obj.rmouseTimer = <value>` |
| selectedLoadedLeft | selectedLoadedLeft | integer | RW | `obj.selectedLoadedLeft = <value>` |
| trackedCharacterFloor | trackedCharacterFloor | integer | RW | `obj.trackedCharacterFloor = <value>` |
| factionName | factionName | string | RW | `obj.factionName = <value>` |
| technology | technology | lightuserdata | R | `obj.technology` |
| placementObject | placementObject | lightuserdata | RW | `obj.placementObject = <value>` |
| deadPlayerSquad | deadPlayerSquad | unknown | W | `obj.deadPlayerSquad = <value>` |
| mouseRightTarget | mouseRightTarget | unknown | W | `obj.mouseRightTarget = <value>` |
| selectedObject | selectedObject | unknown | W | `obj.selectedObject = <value>` |
| trackedCharacterHandle | trackedCharacterHandle | unknown | W | `obj.trackedCharacterHandle = <value>` |
| participant | participant | unknown | W | `obj.participant = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getFaction | getFaction | `obj:getFaction(...)` |
| setFaction | setFaction | `obj:setFaction(...)` |
| getCurrentPlatoon | getCurrentPlatoon | `obj:getCurrentPlatoon(...)` |
| setCurrentPlatoon | setCurrentPlatoon | `obj:setCurrentPlatoon(...)` |
| getCurrentActivePlatoon | getCurrentActivePlatoon | `obj:getCurrentActivePlatoon(...)` |
| recruit | recruit | `obj:recruit(...)` |
| selectObject | selectObject | `obj:selectObject(...)` |
| selectPlayerCharacter | selectPlayerCharacter | `obj:selectPlayerCharacter(...)` |
| selectPlayerCharacterByIndex | selectPlayerCharacterByIndex | `obj:selectPlayerCharacterByIndex(...)` |
| getNearestSelectedCharacterTo | getNearestSelectedCharacterTo | `obj:getNearestSelectedCharacterTo(...)` |
| getNearestCharacterTo | getNearestCharacterTo | `obj:getNearestCharacterTo(...)` |
| unselectPlayerCharacter | unselectPlayerCharacter | `obj:unselectPlayerCharacter(...)` |
| startTrackCharacter | startTrackCharacter | `obj:startTrackCharacter(...)` |
| stopTrackCharacter | stopTrackCharacter | `obj:stopTrackCharacter(...)` |
| isTrackingCharacter | isTrackingCharacter | `obj:isTrackingCharacter(...)` |
| getAnyPlayerCharacter | getAnyPlayerCharacter | `obj:getAnyPlayerCharacter(...)` |
| isBuildMode | isBuildMode | `obj:isBuildMode(...)` |
| unselectAll | unselectAll | `obj:unselectAll(...)` |
| getSelectedCharacterHandle | getSelectedCharacterHandle | `obj:getSelectedCharacterHandle(...)` |
| focusCamera | focusCamera | `obj:focusCamera(...)` |
| focusCameraSelectedCharacter | focusCameraSelectedCharacter | `obj:focusCameraSelectedCharacter(...)` |
| manuallyOrientCamera | manuallyOrientCamera | `obj:manuallyOrientCamera(...)` |
| getDistanceFromCamera | getDistanceFromCamera | `obj:getDistanceFromCamera(...)` |
| getCameraCenter | getCameraCenter | `obj:getCameraCenter(...)` |
| toggleLevelEditorOnSelectedTown | toggleLevelEditorOnSelectedTown | `obj:toggleLevelEditorOnSelectedTown(...)` |
| newPlayerTaskSelectedCharacters | newPlayerTaskSelectedCharacters | `obj:newPlayerTaskSelectedCharacters(...)` |
| getPlayerTaskProbability | getPlayerTaskProbability | `obj:getPlayerTaskProbability(...)` |
| addOrderSelectedCharacters | addOrderSelectedCharacters | `obj:addOrderSelectedCharacters(...)` |
| addJobSelectedCharacters | addJobSelectedCharacters | `obj:addJobSelectedCharacters(...)` |
| removeJobSelectedCharacters | removeJobSelectedCharacters | `obj:removeJobSelectedCharacters(...)` |
| removePermaJobSelectedCharacters | removePermaJobSelectedCharacters | `obj:removePermaJobSelectedCharacters(...)` |
| isFactionKnown | isFactionKnown | `obj:isFactionKnown(...)` |
| encounterFaction | encounterFaction | `obj:encounterFaction(...)` |
| pickupItem | pickupItem | `obj:pickupItem(...)` |
| characterSelected | characterSelected | `obj:characterSelected(...)` |
| itemSelected | itemSelected | `obj:itemSelected(...)` |
| buildingSelected | buildingSelected | `obj:buildingSelected(...)` |
| playerMove | playerMove | `obj:playerMove(...)` |
| _isPlayerCharacter | _isPlayerCharacter | `obj:_isPlayerCharacter(...)` |

## RaceData
**Header:** `extern/KenshiLib/Include/kenshi/RaceData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| runSpeedMaxSkill | runSpeedMaxSkill | number | RW | `obj.runSpeedMaxSkill = <value>` |
| runSpeedMinSkill | runSpeedMinSkill | number | RW | `obj.runSpeedMinSkill = <value>` |
| originalBloodMin | originalBloodMin | number | RW | `obj.originalBloodMin = <value>` |
| originalBloodMax | originalBloodMax | number | RW | `obj.originalBloodMax = <value>` |
| healRate | healRate | number | RW | `obj.healRate = <value>` |
| bleedRate | bleedRate | number | RW | `obj.bleedRate = <value>` |
| swimSpeed | swimSpeed | number | RW | `obj.swimSpeed = <value>` |
| walkSpeed | walkSpeed | number | RW | `obj.walkSpeed = <value>` |
| hungerRate | hungerRate | number | RW | `obj.hungerRate = <value>` |
| visionMultiplier | visionMultiplier | number | RW | `obj.visionMultiplier = <value>` |
| extraAttackSlots | extraAttackSlots | integer | RW | `obj.extraAttackSlots = <value>` |
| gigantic | gigantic | boolean | RW | `obj.gigantic = <value>` |
| swims | swims | boolean | RW | `obj.swims = <value>` |
| carriable | carriable | boolean | RW | `obj.carriable = <value>` |
| singleGender | singleGender | boolean | RW | `obj.singleGender = <value>` |
| robot | robot | boolean | RW | `obj.robot = <value>` |
| vampiric | vampiric | boolean | RW | `obj.vampiric = <value>` |
| noHats | noHats | boolean | RW | `obj.noHats = <value>` |
| noShirts | noShirts | boolean | RW | `obj.noShirts = <value>` |
| noShoes | noShoes | boolean | RW | `obj.noShoes = <value>` |
| canGoIndoors | canGoIndoors | boolean | RW | `obj.canGoIndoors = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isRelatedRace | isRelatedRace | `obj:isRelatedRace(...)` |
| canEat | canEat | `obj:canEat(...)` |
| isImmune | isImmune | `obj:isImmune(...)` |

## RootObject
**Header:** `extern/KenshiLib/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | getVisible | boolean | R | `obj.visible` |
| classType | getDataType | integer | R | `obj.classType` |
| money | getMoney | integer | R | `obj.money` |
| name | getName | string | R | `obj.name` |
| modelName | getModelName | string | R | `obj.modelName` |
| rotation | q.w | number | R | `obj.rotation` |
| inventory | (void*)inv | lightuserdata | R | `obj.inventory` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getName | getName | `obj:getName(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| getRotation | getRotation | `obj:getRotation(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| getModelName | getModelName | `obj:getModelName(...)` |
| getMoney | getMoney | `obj:getMoney(...)` |
| getTown | getTown | `obj:getTown(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| takeMoney | takeMoney | `obj:takeMoney(...)` |
| say | say | `obj:say(...)` |

## ShopTrader
**Header:** `extern/KenshiLib/Include/kenshi/ShopTrader.h`

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
| getFloor | getFloor | `obj:getFloor(...)` |
| _NV_getFloor | _NV_getFloor | `obj:_NV_getFloor(...)` |
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

## Town
**Header:** `extern/KenshiLib/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isActive | isActive | boolean | R | `obj.isActive` |
| isDead | isDead | boolean | R | `obj.isDead` |
| isOutpost | isOutpost | boolean | R | `obj.isOutpost` |
| isPublic | isPublic | boolean | R | `obj.isPublic` |
| hasGates | hasGates | boolean | R | `obj.hasGates` |
| isValid | isValid | boolean | R | `obj.isValid` |
| isNotFriendly | isNotFriendly | boolean | R | `obj.isNotFriendly` |
| alarmState | getAlarmState | integer | R | `obj.alarmState` |
| townType | townType | integer | RW | `obj.townType = <value>` |
| playerTownLevel | playerTownLevel | integer | RW | `obj.playerTownLevel = <value>` |
| name | getKnownName | string | R | `obj.name` |
| unexploredName | unexploredName | string | RW | `obj.unexploredName = <value>` |
| discovered | discovered | boolean | RW | `obj.discovered = <value>` |
| explored | explored | boolean | RW | `obj.explored = <value>` |
| openToPublic | openToPublic | boolean | RW | `obj.openToPublic = <value>` |
| power_Stat | power_Stat | number | RW | `obj.power_Stat = <value>` |
| maxPower_Stat | maxPower_Stat | number | RW | `obj.maxPower_Stat = <value>` |
| townRangeMultiplier | townRangeMultiplier | number | RW | `obj.townRangeMultiplier = <value>` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getName | getName | `obj:getName(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| getFaction | getFaction | `obj:getFaction(...)` |
| setFaction | setFaction | `obj:setFaction(...)` |
| getAlarmState | getAlarmState | `obj:getAlarmState(...)` |
| setAlarmState | setAlarmState | `obj:setAlarmState(...)` |
| isActive | isActive | `obj:isActive(...)` |
| isDead | isDead | `obj:isDead(...)` |
| isOutpost | isOutpost | `obj:isOutpost(...)` |
| isPublic | isPublic | `obj:isPublic(...)` |
| hasGates | hasGates | `obj:hasGates(...)` |
| isValid | isValid | `obj:isValid(...)` |
| isNotFriendly | isNotFriendly | `obj:isNotFriendly(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| setRecentlyDiscovered | setRecentlyDiscovered | `obj:setRecentlyDiscovered(...)` |
| distanceTo | distanceTo | `obj:distanceTo(...)` |
| withinBordersRange | withinBordersRange | `obj:withinBordersRange(...)` |
| getPowerStats | getPowerStats | `obj:getPowerStats(...)` |
| isMyTown | isMyTown | `obj:isMyTown(...)` |

## Enums

### BuildingDesignation
| Name | Value |
|---|---|
| BD_NONE | BuildingDesignation::BD_NONE |
| BD_SHOP | BuildingDesignation::BD_SHOP |
| BD_BARRACKS | BuildingDesignation::BD_BARRACKS |
| BD_BAR | BuildingDesignation::BD_BAR |
| BD_HOSPITAL | BuildingDesignation::BD_HOSPITAL |
| BD_ARMOURY | BuildingDesignation::BD_ARMOURY |
| BD_TREASURE | BuildingDesignation::BD_TREASURE |
| BD_PRISON | BuildingDesignation::BD_PRISON |
| BD_HQ | BuildingDesignation::BD_HQ |
| BD_RESIDENTIAL | BuildingDesignation::BD_RESIDENTIAL |
| BD_SLAVE_STORAGE | BuildingDesignation::BD_SLAVE_STORAGE |
| BD_RESIDENTIAL_SMALL | BuildingDesignation::BD_RESIDENTIAL_SMALL |
#### or
| NONE | BuildingDesignation::BD_NONE |
| SHOP | BuildingDesignation::BD_SHOP |
| BARRACKS | BuildingDesignation::BD_BARRACKS |
| BAR | BuildingDesignation::BD_BAR |
| HOSPITAL | BuildingDesignation::BD_HOSPITAL |
| ARMOURY | BuildingDesignation::BD_ARMOURY |
| TREASURE | BuildingDesignation::BD_TREASURE |
| PRISON | BuildingDesignation::BD_PRISON |
| HQ | BuildingDesignation::BD_HQ |
| RESIDENTIAL | BuildingDesignation::BD_RESIDENTIAL |
| SLAVE_STORAGE | BuildingDesignation::BD_SLAVE_STORAGE |
| RESIDENTIAL_SMALL | BuildingDesignation::BD_RESIDENTIAL_SMALL |

### BuildingClassType
| Name | Value |
|---|---|
| BCTYPE_FLUFF | BuildingClassType::BCTYPE_FLUFF |
| BCTYPE_DOOR | BuildingClassType::BCTYPE_DOOR |
| BCTYPE_USABLE | BuildingClassType::BCTYPE_USABLE |
| BCTYPE_STORAGE | BuildingClassType::BCTYPE_STORAGE |
| BCTYPE_PRODUCTION | BuildingClassType::BCTYPE_PRODUCTION |
| BCTYPE_RESEARCH | BuildingClassType::BCTYPE_RESEARCH |
| BCTYPE_CRAFTING | BuildingClassType::BCTYPE_CRAFTING |
| BCTYPE_GATEWAY | BuildingClassType::BCTYPE_GATEWAY |
| BCTYPE_TURRET | BuildingClassType::BCTYPE_TURRET |
| BCTYPE_WALL | BuildingClassType::BCTYPE_WALL |
| BCTYPE_ITEM_FURNACE | BuildingClassType::BCTYPE_ITEM_FURNACE |
| BCTYPE_LIGHT | BuildingClassType::BCTYPE_LIGHT |
| BCTYPE_SHELL_WITH_INTERIOR | BuildingClassType::BCTYPE_SHELL_WITH_INTERIOR |
| BCTYPE_FARM | BuildingClassType::BCTYPE_FARM |
#### or
| FLUFF | BuildingClassType::BCTYPE_FLUFF |
| DOOR | BuildingClassType::BCTYPE_DOOR |
| USABLE | BuildingClassType::BCTYPE_USABLE |
| STORAGE | BuildingClassType::BCTYPE_STORAGE |
| PRODUCTION | BuildingClassType::BCTYPE_PRODUCTION |
| RESEARCH | BuildingClassType::BCTYPE_RESEARCH |
| CRAFTING | BuildingClassType::BCTYPE_CRAFTING |
| GATEWAY | BuildingClassType::BCTYPE_GATEWAY |
| TURRET | BuildingClassType::BCTYPE_TURRET |
| WALL | BuildingClassType::BCTYPE_WALL |
| ITEM_FURNACE | BuildingClassType::BCTYPE_ITEM_FURNACE |
| LIGHT | BuildingClassType::BCTYPE_LIGHT |
| SHELL_WITH_INTERIOR | BuildingClassType::BCTYPE_SHELL_WITH_INTERIOR |
| FARM | BuildingClassType::BCTYPE_FARM |

### BuildingPlacementGroundType
| Name | Value |
|---|---|
| ANY | BuildingPlacementGroundType::Enum::ANY |
| LAND | BuildingPlacementGroundType::Enum::LAND |
| WATER | BuildingPlacementGroundType::Enum::WATER |

### PreviewBuildingPlacementResult
| Name | Value |
|---|---|
| PLACEMENT_VALID | PreviewBuilding::PlacementResult::PLACEMENT_VALID |
| PLACEMENT_OUTSIDE | PreviewBuilding::PlacementResult::PLACEMENT_OUTSIDE |
| PLACEMENT_INVALID | PreviewBuilding::PlacementResult::PLACEMENT_INVALID |
#### or
| VALID | PreviewBuilding::PlacementResult::PLACEMENT_VALID |
| OUTSIDE | PreviewBuilding::PlacementResult::PLACEMENT_OUTSIDE |
| INVALID | PreviewBuilding::PlacementResult::PLACEMENT_INVALID |

### PreviewBuildingClassType
| Name | Value |
|---|---|
| PREVIEW_NORMAL | PreviewBuilding::PreviewBuildingClassType::PREVIEW_NORMAL |
| PREVIEW_WALL | PreviewBuilding::PreviewBuildingClassType::PREVIEW_WALL |
#### or
| NORMAL | PreviewBuilding::PreviewBuildingClassType::PREVIEW_NORMAL |
| WALL | PreviewBuilding::PreviewBuildingClassType::PREVIEW_WALL |

### ProneState
| Name | Value |
|---|---|
| PS_NORMAL | ProneState::PS_NORMAL |
| PS_STAYING_LOW | ProneState::PS_STAYING_LOW |
| PS_CRIPPLED | ProneState::PS_CRIPPLED |
| PS_PLAYING_DEAD | ProneState::PS_PLAYING_DEAD |
| PS_KO | ProneState::PS_KO |
#### or
| NORMAL | PS_NORMAL |
| STAYING_LOW | PS_STAYING_LOW |
| CRIPPLED | PS_CRIPPLED |
| PLAYING_DEAD | PS_PLAYING_DEAD |
| KO | ProneState::PS_KO |

### WaterState
| Name | Value |
|---|---|
| NO_WATER | WaterState::NO_WATER |
| VERY_SHALLOW_WATER | WaterState::VERY_SHALLOW_WATER |
| THIGH_DEEP_WATER | WaterState::THIGH_DEEP_WATER |
| DEEP_WATER | WaterState::DEEP_WATER |

### RagdollPart
| Name | Value |
|---|---|
| NONE | RagdollPart::Enum::NONE |
| WHOLE | RagdollPart::Enum::WHOLE |
| RIGHT_ARM | RagdollPart::Enum::RIGHT_ARM |
| LEFT_ARM | RagdollPart::Enum::LEFT_ARM |
| HEAD | RagdollPart::Enum::HEAD |
| RIGHT_LEG | RagdollPart::Enum::RIGHT_LEG |
| LEFT_LEG | RagdollPart::Enum::LEFT_LEG |
| CARRY_MODE | RagdollPart::Enum::CARRY_MODE |
| ARMS | RagdollPart::Enum::ARMS |
| LEGS | RagdollPart::Enum::LEGS |
| ALL | RagdollPart::Enum::ALL |

### CharacterPerceptionTags_ShortTerm
| Name | Value |
|---|---|
| ST_NONE | ST_NONE |
| ST_INTRUDER | ST_INTRUDER |
| ST_AGGRESSOR | ST_AGGRESSOR |
| ST_TEMPORARY_ALLY | ST_TEMPORARY_ALLY |
| ST_TEMPORARY_ENEMY | ST_TEMPORARY_ENEMY |
| ST_PRISONER | ST_PRISONER |
| ST_HAS_BEEN_LOOTED | ST_HAS_BEEN_LOOTED |
| ST_CRIMINAL | ST_CRIMINAL |
#### or
| NONE | ST_NONE |
| INTRUDER | ST_INTRUDER |
| AGGRESSOR | ST_AGGRESSOR |
| TEMPORARY_ALLY | ST_TEMPORARY_ALLY |
| TEMPORARY_ENEMY | ST_TEMPORARY_ENEMY |
| PRISONER | ST_PRISONER |
| HAS_BEEN_LOOTED | ST_HAS_BEEN_LOOTED |
| CRIMINAL | ST_CRIMINAL |

### CharacterPerceptionTags_LongTerm
| Name | Value |
|---|---|
| LT_NONE | LT_NONE |
| LT_MY_INTRUDER | LT_MY_INTRUDER |
| LT_MY_LIFESAVER | LT_MY_LIFESAVER |
| LT_FREED_ME | LT_FREED_ME |
| LT_STOLE_FROM_ME | LT_STOLE_FROM_ME |
| LT_MY_CAPTOR | LT_MY_CAPTOR |
| LT_FRIENDLY_AQUAINTANCE | LT_FRIENDLY_AQUAINTANCE |
| LT_DEFEATED_MY_SQUAD_ONCE | LT_DEFEATED_MY_SQUAD_ONCE |
| LT_SQUAD_LOST_TO_ME_ONCE | LT_SQUAD_LOST_TO_ME_ONCE |
| LT_KILLED_MY_FRIEND | LT_KILLED_MY_FRIEND |
| LT_I_SCREWED_THIS_GUY | LT_I_SCREWED_THIS_GUY |
| LT_MAX | LT_MAX |
#### or
| NONE | LT_NONE |
| MY_INTRUDER | LT_MY_INTRUDER |
| MY_LIFESAVER | LT_MY_LIFESAVER |
| FREED_ME | LT_FREED_ME |
| STOLE_FROM_ME | LT_STOLE_FROM_ME |
| MY_CAPTOR | LT_MY_CAPTOR |
| FRIENDLY_AQUAINTANCE | LT_FRIENDLY_AQUAINTANCE |
| DEFEATED_MY_SQUAD_ONCE | LT_DEFEATED_MY_SQUAD_ONCE |
| SQUAD_LOST_TO_ME_ONCE | LT_SQUAD_LOST_TO_ME_ONCE |
| KILLED_MY_FRIEND | LT_KILLED_MY_FRIEND |
| I_SCREWED_THIS_GUY | LT_I_SCREWED_THIS_GUY |
| MAX | LT_MAX |

### SoundRange
| Name | Value |
|---|---|
| SOUNDRANGE_SHORT | SOUNDRANGE_SHORT |
| SOUNDRANGE_LONG | SOUNDRANGE_LONG |
| SOUNDRANGE_ALWAYS | SOUNDRANGE_ALWAYS |
#### or
| SHORT | SOUNDRANGE_SHORT |
| LONG | SOUNDRANGE_LONG |
| ALWAYS | SOUNDRANGE_ALWAYS |

### SquadMemberType
| Name | Value |
|---|---|
| SQUAD_1 | SQUAD_1 |
| SQUAD_2 | SQUAD_2 |
| SQUAD_LEADER | SQUAD_LEADER |
| SQUAD_SIGNALS_PLAN | SQUAD_SIGNALS_PLAN |
| SQUAD_SLAVE | SQUAD_SLAVE |
#### or
| 1 | SQUAD_1 |
| 2 | SQUAD_2 |
| LEADER | SQUAD_LEADER |
| SIGNALS_PLAN | SQUAD_SIGNALS_PLAN |
| SLAVE | SQUAD_SLAVE |

### CharacterMessage
| Name | Value |
|---|
| ATTACKING_MELEE | ATTACKING_MELEE |

### Talker
| Name | Value |
|---|---|
| T_ME | T_ME |
| T_TARGET | T_TARGET |
| T_TARGET_IF_PLAYER | T_TARGET_IF_PLAYER |
| T_INTERJECTOR1 | T_INTERJECTOR1 |
| T_INTERJECTOR2 | T_INTERJECTOR2 |
| T_INTERJECTOR3 | T_INTERJECTOR3 |
| T_WHOLE_SQUAD | T_WHOLE_SQUAD |
| T_TARGET_WITH_RACE | T_TARGET_WITH_RACE |
#### or
| ME | T_ME |
| TARGET | T_TARGET |
| TARGET_IF_PLAYER | T_TARGET_IF_PLAYER |
| INTERJECTOR1 | T_INTERJECTOR1 |
| INTERJECTOR2 | T_INTERJECTOR2 |
| INTERJECTOR3 | T_INTERJECTOR3 |
| WHOLE_SQUAD | T_WHOLE_SQUAD |
| TARGET_WITH_RACE | T_TARGET_WITH_RACE |

### DialogueAction
| Name | Value |
|---|---|
| DA_NONE | DA_NONE |
| DA_TRADE | DA_TRADE |
| DA_TALK_TO_LEADER | DA_TALK_TO_LEADER |
| DA_JOIN_SQUAD_WITH_EDIT | DA_JOIN_SQUAD_WITH_EDIT |
| DA_AFFECT_RELATIONS | DA_AFFECT_RELATIONS |
| DA_AFFECT_REPUTATION | DA_AFFECT_REPUTATION |
| DA_ATTACK_CHASE_FOREVER | DA_ATTACK_CHASE_FOREVER |
| DA_GO_HOME | DA_GO_HOME |
| DA_TAKE_MONEY | DA_TAKE_MONEY |
| DA_GIVE_MONEY | DA_GIVE_MONEY |
| DA_PAY_BOUNTY | DA_PAY_BOUNTY |
| DA_CHARACTER_EDITOR | DA_CHARACTER_EDITOR |
| DA_FORCE_SPEECH_TIMER | DA_FORCE_SPEECH_TIMER |
| DA_DECLARE_WAR | DA_DECLARE_WAR |
| DA_END_WAR | DA_END_WAR |
| DA_CLEAR_AI | DA_CLEAR_AI |
| DA_FOLLOW_WHILE_TALKING | DA_FOLLOW_WHILE_TALKING |
| DA_THUG_HUNTER | DA_THUG_HUNTER |
| DA_JOIN_SQUAD_FAST | DA_JOIN_SQUAD_FAST |
| DA_REMEMBER_CHARACTER | DA_REMEMBER_CHARACTER |
| DA_FLAG_TEMP_ALLY | DA_FLAG_TEMP_ALLY |
| DA_FLAG_TEMP_ENEMY | DA_FLAG_TEMP_ENEMY |
| DA_MATES_KILL_ME | DA_MATES_KILL_ME |
| DA_MAKE_TARGET_RUN_FASTER | DA_MAKE_TARGET_RUN_FASTER |
| DA_GIVE_TARGET_MY_SLAVES | DA_GIVE_TARGET_MY_SLAVES |
| DA_TAG_ESCAPED_SLAVE | DA_TAG_ESCAPED_SLAVE |
| DA_FREE_TARGET_SLAVE | DA_FREE_TARGET_SLAVE |
| DA_MERGE_WITH_SIMILAR_SQUADS | DA_MERGE_WITH_SIMILAR_SQUADS |
| DA_SEPARATE_TO_MY_OWN_SQUAD | DA_SEPARATE_TO_MY_OWN_SQUAD |
| DA_ARREST_TARGET | DA_ARREST_TARGET |
| DA_ARREST_TARGETS_CARRIED_PERSON | DA_ARREST_TARGETS_CARRIED_PERSON |
| DA_ATTACK_TOWN | DA_ATTACK_TOWN |
| DA_ASSIGN_BOUNTY | DA_ASSIGN_BOUNTY |
| DA_CRIME_ALARM | DA_CRIME_ALARM |
| DA_RUN_AWAY | DA_RUN_AWAY |
| DA_INCREASE_FACTION_RANK | DA_INCREASE_FACTION_RANK |
| DA_LOCK_THIS_DIALOG | DA_LOCK_THIS_DIALOG |
| DA_ASSAULT_PHASE | DA_ASSAULT_PHASE |
| DA_RETREAT_PHASE | DA_RETREAT_PHASE |
| DA_VICTORY_PHASE | DA_VICTORY_PHASE |
| DA_ENSLAVE_TARGETS_CARRIED_PERSON | DA_ENSLAVE_TARGETS_CARRIED_PERSON |
| DA_CLEAR_BOUNTY | DA_CLEAR_BOUNTY |
| DA_PLAYER_SELL_PRISONERS | DA_PLAYER_SELL_PRISONERS |
| DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE | DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE |
| DA_SUMMON_MY_SQUAD | DA_SUMMON_MY_SQUAD |
| DA_REMOVE_SLAVE_STATUS | DA_REMOVE_SLAVE_STATUS |
| DA_OPEN_NEAREST_GATE | DA_OPEN_NEAREST_GATE |
| DA_ATTACK_STAY_NEAR_HOME | DA_ATTACK_STAY_NEAR_HOME |
| DA_MASSIVE_ALARM | DA_MASSIVE_ALARM |
| DA_ATTACK_IF_NO_COEXIST | DA_ATTACK_IF_NO_COEXIST |
| DA_KNOCKOUT | DA_KNOCKOUT |
| DA_END | DA_END |
#### or
| NONE | DA_NONE |
| TRADE | DA_TRADE |
| TALK_TO_LEADER | DA_TALK_TO_LEADER |
| JOIN_SQUAD_WITH_EDIT | DA_JOIN_SQUAD_WITH_EDIT |
| AFFECT_RELATIONS | DA_AFFECT_RELATIONS |
| AFFECT_REPUTATION | DA_AFFECT_REPUTATION |
| ATTACK_CHASE_FOREVER | DA_ATTACK_CHASE_FOREVER |
| GO_HOME | DA_GO_HOME |
| TAKE_MONEY | DA_TAKE_MONEY |
| GIVE_MONEY | DA_GIVE_MONEY |
| PAY_BOUNTY | DA_PAY_BOUNTY |
| CHARACTER_EDITOR | DA_CHARACTER_EDITOR |
| FORCE_SPEECH_TIMER | DA_FORCE_SPEECH_TIMER |
| DECLARE_WAR | DA_DECLARE_WAR |
| END_WAR | DA_END_WAR |
| CLEAR_AI | DA_CLEAR_AI |
| FOLLOW_WHILE_TALKING | DA_FOLLOW_WHILE_TALKING |
| THUG_HUNTER | DA_THUG_HUNTER |
| JOIN_SQUAD_FAST | DA_JOIN_SQUAD_FAST |
| REMEMBER_CHARACTER | DA_REMEMBER_CHARACTER |
| FLAG_TEMP_ALLY | DA_FLAG_TEMP_ALLY |
| FLAG_TEMP_ENEMY | DA_FLAG_TEMP_ENEMY |
| MATES_KILL_ME | DA_MATES_KILL_ME |
| MAKE_TARGET_RUN_FASTER | DA_MAKE_TARGET_RUN_FASTER |
| GIVE_TARGET_MY_SLAVES | DA_GIVE_TARGET_MY_SLAVES |
| TAG_ESCAPED_SLAVE | DA_TAG_ESCAPED_SLAVE |
| FREE_TARGET_SLAVE | DA_FREE_TARGET_SLAVE |
| MERGE_WITH_SIMILAR_SQUADS | DA_MERGE_WITH_SIMILAR_SQUADS |
| SEPARATE_TO_MY_OWN_SQUAD | DA_SEPARATE_TO_MY_OWN_SQUAD |
| ARREST_TARGET | DA_ARREST_TARGET |
| ARREST_TARGETS_CARRIED_PERSON | DA_ARREST_TARGETS_CARRIED_PERSON |
| ATTACK_TOWN | DA_ATTACK_TOWN |
| ASSIGN_BOUNTY | DA_ASSIGN_BOUNTY |
| CRIME_ALARM | DA_CRIME_ALARM |
| RUN_AWAY | DA_RUN_AWAY |
| INCREASE_FACTION_RANK | DA_INCREASE_FACTION_RANK |
| LOCK_THIS_DIALOG | DA_LOCK_THIS_DIALOG |
| ASSAULT_PHASE | DA_ASSAULT_PHASE |
| RETREAT_PHASE | DA_RETREAT_PHASE |
| VICTORY_PHASE | DA_VICTORY_PHASE |
| ENSLAVE_TARGETS_CARRIED_PERSON | DA_ENSLAVE_TARGETS_CARRIED_PERSON |
| CLEAR_BOUNTY | DA_CLEAR_BOUNTY |
| PLAYER_SELL_PRISONERS | DA_PLAYER_SELL_PRISONERS |
| PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE | DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE |
| SUMMON_MY_SQUAD | DA_SUMMON_MY_SQUAD |
| REMOVE_SLAVE_STATUS | DA_REMOVE_SLAVE_STATUS |
| OPEN_NEAREST_GATE | DA_OPEN_NEAREST_GATE |
| ATTACK_STAY_NEAR_HOME | DA_ATTACK_STAY_NEAR_HOME |
| MASSIVE_ALARM | DA_MASSIVE_ALARM |
| ATTACK_IF_NO_COEXIST | DA_ATTACK_IF_NO_COEXIST |
| KNOCKOUT | DA_KNOCKOUT |
| END | DA_END |

### itemType
| Name | Value |
|---|---|
| BUILDING | itemType::BUILDING |
| CHARACTER | itemType::CHARACTER |
| WEAPON | itemType::WEAPON |
| ARMOUR | itemType::ARMOUR |
| ITEM | itemType::ITEM |
| ANIMAL_ANIMATION | itemType::ANIMAL_ANIMATION |
| ATTACHMENT | itemType::ATTACHMENT |
| RACE | itemType::RACE |
| LOCATION | itemType::LOCATION |
| WAR_SAVESTATE | itemType::WAR_SAVESTATE |
| FACTION | itemType::FACTION |
| NULL_ITEM | itemType::NULL_ITEM |
| ZONE_MAP | itemType::ZONE_MAP |
| TOWN | itemType::TOWN |
| WORLDMAP_CHARACTER | itemType::WORLDMAP_CHARACTER |
| CHARACTER_APPEARANCE_OLD | itemType::CHARACTER_APPEARANCE_OLD |
| LOCATIONAL_DAMAGE | itemType::LOCATIONAL_DAMAGE |
| COMBAT_TECHNIQUE | itemType::COMBAT_TECHNIQUE |
| DIALOGUE | itemType::DIALOGUE |
| DIALOGUE_LINE | itemType::DIALOGUE_LINE |
| TECHTREE | itemType::TECHTREE |
| RESEARCH | itemType::RESEARCH |
| AI_TASK | itemType::AI_TASK |
| AI_STATE | itemType::AI_STATE |
| ANIMATION | itemType::ANIMATION |
| STATS | itemType::STATS |
| PERSONALITY | itemType::PERSONALITY |
| CONSTANTS | itemType::CONSTANTS |
| BIOMES | itemType::BIOMES |
| BUILDING_PART | itemType::BUILDING_PART |
| INSTANCE_COLLECTION | itemType::INSTANCE_COLLECTION |
| DIALOG_ACTION | itemType::DIALOG_ACTION |
| TEMPORARY_INFO | itemType::TEMPORARY_INFO |
| MOD_FILENAME | itemType::MOD_FILENAME |
| PLATOON | itemType::PLATOON |
| GAMESTATE_BUILDING | itemType::GAMESTATE_BUILDING |
| GAMESTATE_CHARACTER | itemType::GAMESTATE_CHARACTER |
| GAMESTATE_FACTION | itemType::GAMESTATE_FACTION |
| GAMESTATE_TOWN_INSTANCE_LIST | itemType::GAMESTATE_TOWN_INSTANCE_LIST |
| STATE | itemType::STATE |
| SAVED_STATE | itemType::SAVED_STATE |
| INVENTORY_STATE | itemType::INVENTORY_STATE |
| INVENTORY_ITEM_STATE | itemType::INVENTORY_ITEM_STATE |
| REPEATABLE_BUILDING_PART_SLOT | itemType::REPEATABLE_BUILDING_PART_SLOT |
| MATERIAL_SPEC | itemType::MATERIAL_SPEC |
| MATERIAL_SPECS_COLLECTION | itemType::MATERIAL_SPECS_COLLECTION |
| CONTAINER | itemType::CONTAINER |
| MATERIAL_SPECS_CLOTHING | itemType::MATERIAL_SPECS_CLOTHING |
| GAMESTATE_BUILDING_INTERIOR | itemType::GAMESTATE_BUILDING_INTERIOR |
| VENDOR_LIST | itemType::VENDOR_LIST |
| MATERIAL_SPECS_WEAPON | itemType::MATERIAL_SPECS_WEAPON |
| WEAPON_MANUFACTURER | itemType::WEAPON_MANUFACTURER |
| SQUAD_TEMPLATE | itemType::SQUAD_TEMPLATE |
| ROAD | itemType::ROAD |
| LOCATION_NODE | itemType::LOCATION_NODE |
| COLOR_DATA | itemType::COLOR_DATA |
| CAMERA | itemType::CAMERA |
| MEDICAL_STATE | itemType::MEDICAL_STATE |
| MEDICAL_PART_STATE | itemType::MEDICAL_PART_STATE |
| FOLIAGE_LAYER | itemType::FOLIAGE_LAYER |
| FOLIAGE_MESH | itemType::FOLIAGE_MESH |
| GRASS | itemType::GRASS |
| BUILDING_FUNCTIONALITY | itemType::BUILDING_FUNCTIONALITY |
| DAY_SCHEDULE | itemType::DAY_SCHEDULE |
| NEW_GAME_STARTOFF | itemType::NEW_GAME_STARTOFF |
| GAMESTATE_CRAFTING | itemType::GAMESTATE_CRAFTING |
| CHARACTER_APPEARANCE | itemType::CHARACTER_APPEARANCE |
| GAMESTATE_AI | itemType::GAMESTATE_AI |
| WILDLIFE_BIRDS | itemType::WILDLIFE_BIRDS |
| MAP_FEATURES | itemType::MAP_FEATURES |
| DIPLOMATIC_ASSAULTS | itemType::DIPLOMATIC_ASSAULTS |
| SINGLE_DIPLOMATIC_ASSAULT | itemType::SINGLE_DIPLOMATIC_ASSAULT |
| AI_PACKAGE | itemType::AI_PACKAGE |
| DIALOGUE_PACKAGE | itemType::DIALOGUE_PACKAGE |
| GUN_DATA | itemType::GUN_DATA |
| HUMAN_CHARACTER | itemType::HUMAN_CHARACTER |
| ANIMAL_CHARACTER | itemType::ANIMAL_CHARACTER |
| UNIQUE_SQUAD_TEMPLATE | itemType::UNIQUE_SQUAD_TEMPLATE |
| FACTION_TEMPLATE | itemType::FACTION_TEMPLATE |
| AI_SCHEDULE | itemType::AI_SCHEDULE |
| WEATHER | itemType::WEATHER |
| SEASON | itemType::SEASON |
| EFFECT | itemType::EFFECT |
| ITEM_PLACEMENT_GROUP | itemType::ITEM_PLACEMENT_GROUP |
| WORD_SWAPS | itemType::WORD_SWAPS |
| NEST | itemType::NEST |
| NEST_ITEM | itemType::NEST_ITEM |
| CHARACTER_PHYSICS_ATTACHMENT | itemType::CHARACTER_PHYSICS_ATTACHMENT |
| LIGHT | itemType::LIGHT |
| HEAD | itemType::HEAD |
| BLUEPRINT | itemType::BLUEPRINT |
| SHOP_TRADER_CLASS | itemType::SHOP_TRADER_CLASS |
| FOLIAGE_BUILDING | itemType::FOLIAGE_BUILDING |
| FACTION_CAMPAIGN | itemType::FACTION_CAMPAIGN |
| GAMESTATE_TOWN | itemType::GAMESTATE_TOWN |
| BIOME_GROUP | itemType::BIOME_GROUP |
| EFFECT_FOG_VOLUME | itemType::EFFECT_FOG_VOLUME |
| FARM_DATA | itemType::FARM_DATA |
| FARM_PART | itemType::FARM_PART |
| ENVIRONMENT_RESOURCES | itemType::ENVIRONMENT_RESOURCES |
| RACE_GROUP | itemType::RACE_GROUP |
| ARTIFACTS | itemType::ARTIFACTS |
| MAP_ITEM | itemType::MAP_ITEM |
| BUILDINGS_SWAP | itemType::BUILDINGS_SWAP |
| ITEMS_CULTURE | itemType::ITEMS_CULTURE |
| ANIMATION_EVENT | itemType::ANIMATION_EVENT |
| TUTORIAL | itemType::TUTORIAL |
| CROSSBOW | itemType::CROSSBOW |
| TERRAIN_DECALS | itemType::TERRAIN_DECALS |
| AMBIENT_SOUND | itemType::AMBIENT_SOUND |
| WORLD_EVENT_STATE | itemType::WORLD_EVENT_STATE |
| LIMB_REPLACEMENT | itemType::LIMB_REPLACEMENT |
| ANIMATION_FILE | itemType::ANIMATION_FILE |
| ___XXX___ | itemType::____XXX___ |
| OBJECT_TYPE_MAX | itemType::OBJECT_TYPE_MAX |

### BuildingFunction
| Name | Value |
|---|---|
| BF_ANY | BuildingFunction::BF_ANY |
| BF_MINE | BuildingFunction::BF_MINE |
| BF_RESOURCE_STORAGE | BuildingFunction::BF_RESOURCE_STORAGE |
| BF_RESEARCH | BuildingFunction::BF_RESEARCH |
| BF_REFINERY | BuildingFunction::BF_REFINERY |
| BF_GENERATOR | BuildingFunction::BF_GENERATOR |
| BF_BED | BuildingFunction::BF_BED |
| BF_TRAINING | BuildingFunction::BF_TRAINING |
| BF_CAGE | BuildingFunction::BF_CAGE |
| BF_SHOP | BuildingFunction::BF_SHOP |
| BF_CRAFTING | BuildingFunction::BF_CRAFTING |
| BF_CORPSE_DISPOSAL | BuildingFunction::BF_CORPSE_DISPOSAL |
| BF_TURRET | BuildingFunction::BF_TURRET |
| BF_GENERAL_STORAGE | BuildingFunction::BF_GENERAL_STORAGE |
| BF_ITEM_FURNACE | BuildingFunction::BF_ITEM_FURNACE |
| BF_LIGHT | BuildingFunction::BF_LIGHT |
| BF_TABLE | BuildingFunction::BF_TABLE |
| BF_CHAIR | BuildingFunction::BF_CHAIR |
| BF_FLUFF | BuildingFunction::BF_FLUFF |
| BF_SHELL_WITH_INTERIOR | BuildingFunction::BF_SHELL_WITH_INTERIOR |
| BF_WALL | BuildingFunction::BF_WALL |
| BF_GATE | BuildingFunction::BF_GATE |
| BF_DOOR | BuildingFunction::BF_DOOR |
| BF_BATTERY | BuildingFunction::BF_BATTERY |
| BF_THRONE | BuildingFunction::BF_THRONE |
| BF_SKELETON_BED | BuildingFunction::BF_SKELETON_BED |
| BF_RAIN_COLLECTOR | BuildingFunction::BF_RAIN_COLLECTOR |
| BF_MINE_NATURAL | BuildingFunction::BF_MINE_NATURAL |
| BF_STEERING | BuildingFunction::BF_STEERING |
| BF_ENGINE | BuildingFunction::BF_ENGINE |
| BF_LIQUID_TANK | BuildingFunction::BF_LIQUID_TANK |
#### or
| ANY | BuildingFunction::BF_ANY |
| MINE | BuildingFunction::BF_MINE |
| RESOURCE_STORAGE | BuildingFunction::BF_RESOURCE_STORAGE |
| RESEARCH | BuildingFunction::BF_RESEARCH |
| REFINERY | BuildingFunction::BF_REFINERY |
| GENERATOR | BuildingFunction::BF_GENERATOR |
| BED | BuildingFunction::BF_BED |
| TRAINING | BuildingFunction::BF_TRAINING |
| CAGE | BuildingFunction::BF_CAGE |
| SHOP | BuildingFunction::BF_SHOP |
| CRAFTING | BuildingFunction::BF_CRAFTING |
| CORPSE_DISPOSAL | BuildingFunction::BF_CORPSE_DISPOSAL |
| TURRET | BuildingFunction::BF_TURRET |
| GENERAL_STORAGE | BuildingFunction::BF_GENERAL_STORAGE |
| ITEM_FURNACE | BuildingFunction::BF_ITEM_FURNACE |
| LIGHT | BuildingFunction::BF_LIGHT |
| TABLE | BuildingFunction::BF_TABLE |
| CHAIR | BuildingFunction::BF_CHAIR |
| FLUFF | BuildingFunction::BF_FLUFF |
| SHELL_WITH_INTERIOR | BuildingFunction::BF_SHELL_WITH_INTERIOR |
| WALL | BuildingFunction::BF_WALL |
| GATE | BuildingFunction::BF_GATE |
| DOOR | BuildingFunction::BF_DOOR |
| BATTERY | BuildingFunction::BF_BATTERY |
| THRONE | BuildingFunction::BF_THRONE |
| SKELETON_BED | BuildingFunction::BF_SKELETON_BED |
| RAIN_COLLECTOR | BuildingFunction::BF_RAIN_COLLECTOR |
| MINE_NATURAL | BuildingFunction::BF_MINE_NATURAL |
| STEERING | BuildingFunction::BF_STEERING |
| ENGINE | BuildingFunction::BF_ENGINE |
| LIQUID_TANK | BuildingFunction::BF_LIQUID_TANK |

### CutDirection
| Name | Value |
|---|---|
| CUT_DEFAULT | CutDirection::CUT_DEFAULT |
| CUT_DOWNWARD | CutDirection::CUT_DOWNWARD |
| CUT_LEFT | CutDirection::CUT_LEFT |
| CUT_RIGHT | CutDirection::CUT_RIGHT |
| CUT_THRUST | CutDirection::CUT_THRUST |
| CUT_UPWARDS | CutDirection::CUT_UPWARDS |
| CUT_PIERCED | CutDirection::CUT_PIERCED |
| CUT_REAR_DOWNWARD | CutDirection::CUT_REAR_DOWNWARD |
| CUT_REAR_LEFT | CutDirection::CUT_REAR_LEFT |
| CUT_REAR_RIGHT | CutDirection::CUT_REAR_RIGHT |
#### or
| DEFAULT | CutDirection::CUT_DEFAULT |
| DOWNWARD | CutDirection::CUT_DOWNWARD |
| LEFT | CutDirection::CUT_LEFT |
| RIGHT | CutDirection::CUT_RIGHT |
| THRUST | CutDirection::CUT_THRUST |
| UPWARDS | CutDirection::CUT_UPWARDS |
| PIERCED | CutDirection::CUT_PIERCED |
| REAR_DOWNWARD | CutDirection::CUT_REAR_DOWNWARD |
| REAR_LEFT | CutDirection::CUT_REAR_LEFT |
| REAR_RIGHT | CutDirection::CUT_REAR_RIGHT |

### CutOrigination
| Name | Value |
|---|---|
| FRONT | CutOrigination::FRONT |
| REAR | CutOrigination::REAR |
| LEFTSIDE | CutOrigination::LEFTSIDE |
| RIGHTSIDE | CutOrigination::RIGHTSIDE |

### HitMaterialType
| Name | Value |
|---|---|
| HIT_MISSED | HitMaterialType::HIT_MISSED |
| HIT_METAL | HitMaterialType::HIT_METAL |
| HIT_FLESH | HitMaterialType::HIT_FLESH |
| HIT_SAND | HitMaterialType::HIT_SAND |
| HIT_WOOD | HitMaterialType::HIT_WOOD |
| HIT_SWORD | HitMaterialType::HIT_SWORD |
| HIT_CHAIN | HitMaterialType::HIT_CHAIN |
#### or
| MISSED | HitMaterialType::HIT_MISSED |
| METAL | HitMaterialType::HIT_METAL |
| FLESH | HitMaterialType::HIT_FLESH |
| SAND | HitMaterialType::HIT_SAND |
| WOOD | HitMaterialType::HIT_WOOD |
| SWORD | HitMaterialType::HIT_SWORD |
| CHAIN | HitMaterialType::HIT_CHAIN |

### WeatherAffecting
| Name | Value |
|---|---|
| WA_NONE | WeatherAffecting::WA_NONE |
| WA_DUSTSTORM | WeatherAffecting::WA_DUSTSTORM |
| WA_ACID | WeatherAffecting::WA_ACID |
| WA_BURNING | WeatherAffecting::WA_BURNING |
| WA_GAS | WeatherAffecting::WA_GAS |
| WA_RAIN | WeatherAffecting::WA_RAIN |
#### or
| NONE | WeatherAffecting::WA_NONE |
| DUSTSTORM | WeatherAffecting::WA_DUSTSTORM |
| ACID | WeatherAffecting::WA_ACID |
| BURNING | WeatherAffecting::WA_BURNING |
| GAS | WeatherAffecting::WA_GAS |
| RAIN | WeatherAffecting::WA_RAIN |

### AttachSlot
| Name | Value |
|---|---|
| ATTACH_WEAPON | AttachSlot::ATTACH_WEAPON |
| ATTACH_BACK | AttachSlot::ATTACH_BACK |
| ATTACH_HAIR | AttachSlot::ATTACH_HAIR |
| ATTACH_HAT | AttachSlot::ATTACH_HAT |
| ATTACH_EYES | AttachSlot::ATTACH_EYES |
| ATTACH_BODY | AttachSlot::ATTACH_BODY |
| ATTACH_LEGS | AttachSlot::ATTACH_LEGS |
| ATTACH_NONE | AttachSlot::ATTACH_NONE |
| ATTACH_SHIRT | AttachSlot::ATTACH_SHIRT |
| ATTACH_BOOTS | AttachSlot::ATTACH_BOOTS |
| ATTACH_GLOVES | AttachSlot::ATTACH_GLOVES |
| ATTACH_NECK | AttachSlot::ATTACH_NECK |
| ATTACH_BACKPACK | AttachSlot::ATTACH_BACKPACK |
| ATTACH_BEARD | AttachSlot::ATTACH_BEARD |
| ATTACH_BELT | AttachSlot::ATTACH_BELT |
| ATTACH_LEFT_ARM | AttachSlot::ATTACH_LEFT_ARM |
| ATTACH_RIGHT_ARM | AttachSlot::ATTACH_RIGHT_ARM |
| ATTACH_LEFT_LEG | AttachSlot::ATTACH_LEFT_LEG |
| ATTACH_RIGHT_LEG | AttachSlot::ATTACH_RIGHT_LEG |
#### or
| WEAPON | AttachSlot::ATTACH_WEAPON |
| BACK | AttachSlot::ATTACH_BACK |
| HAIR | AttachSlot::ATTACH_HAIR |
| HAT | AttachSlot::ATTACH_HAT |
| EYES | AttachSlot::ATTACH_EYES |
| BODY | AttachSlot::ATTACH_BODY |
| LEGS | AttachSlot::ATTACH_LEGS |
| NONE | AttachSlot::ATTACH_NONE |
| SHIRT | AttachSlot::ATTACH_SHIRT |
| BOOTS | AttachSlot::ATTACH_BOOTS |
| GLOVES | AttachSlot::ATTACH_GLOVES |
| NECK | AttachSlot::ATTACH_NECK |
| BACKPACK | AttachSlot::ATTACH_BACKPACK |
| BEARD | AttachSlot::ATTACH_BEARD |
| BELT | AttachSlot::ATTACH_BELT |
| LEFT_ARM | AttachSlot::ATTACH_LEFT_ARM |
| RIGHT_ARM | AttachSlot::ATTACH_RIGHT_ARM |
| LEFT_LEG | AttachSlot::ATTACH_LEFT_LEG |
| RIGHT_LEG | AttachSlot::ATTACH_RIGHT_LEG |

### ItemFunction
| Name | Value |
|---|---|
| ITEM_NO_FUNCTION | ItemFunction::ITEM_NO_FUNCTION |
| NO_FUNCTION | ItemFunction::ITEM_NO_FUNCTION |
| ITEM_FIRSTAID | ItemFunction::ITEM_FIRSTAID |
| FIRSTAID | ItemFunction::ITEM_FIRSTAID |
| ITEM_MEDRIGGING | ItemFunction::ITEM_MEDRIGGING |
| MEDRIGGING | ItemFunction::ITEM_MEDRIGGING |
| ITEM_FOOD | ItemFunction::ITEM_FOOD |
| FOOD | ItemFunction::ITEM_FOOD |
| ITEM_CONTAINER | ItemFunction::ITEM_CONTAINER |
| CONTAINER | ItemFunction::ITEM_CONTAINER |
| ITEM_WEAPON | ItemFunction::ITEM_WEAPON |
| WEAPON | ItemFunction::ITEM_WEAPON |
| ITEM_CLOTHING | ItemFunction::ITEM_CLOTHING |
| CLOTHING | ItemFunction::ITEM_CLOTHING |
| ITEM____ | ItemFunction::ITEM____ |
| ___ | ItemFunction::ITEM____ |
| ITEM_NARCOTIC | ItemFunction::ITEM_NARCOTIC |
| NARCOTIC | ItemFunction::ITEM_NARCOTIC |
| ITEM_TOOL | ItemFunction::ITEM_TOOL |
| TOOL | ItemFunction::ITEM_TOOL |
| ITEM_ANYTHING | ItemFunction::ITEM_ANYTHING |
| ANYTHING | ItemFunction::ITEM_ANYTHING |
| ITEM_BLUEPRINT | ItemFunction::ITEM_BLUEPRINT |
| BLUEPRINT | ItemFunction::ITEM_BLUEPRINT |
| ITEM_ROBOTREPAIR | ItemFunction::ITEM_ROBOTREPAIR |
| ROBOTREPAIR | ItemFunction::ITEM_ROBOTREPAIR |
| ITEM_BOOK | ItemFunction::ITEM_BOOK |
| BOOK | ItemFunction::ITEM_BOOK |
| ITEM_MONEY | ItemFunction::ITEM_MONEY |
| MONEY | ItemFunction::ITEM_MONEY |
| ITEM_FOOD_RESTRICTED | ItemFunction::ITEM_FOOD_RESTRICTED |
| FOOD_RESTRICTED | ItemFunction::ITEM_FOOD_RESTRICTED |
| ITEM_AMMO | ItemFunction::ITEM_AMMO |
| AMMO | ItemFunction::ITEM_AMMO |
| ITEM_SEVERED_LIMB | ItemFunction::ITEM_SEVERED_LIMB |
| SEVERED_LIMB | ItemFunction::ITEM_SEVERED_LIMB |

### ArmourType
| Name | Value |
|---|---|
| CLOTH | ArmourType::CLOTH |
| LEATHER | ArmourType::LEATHER |
| CHAIN | ArmourType::CHAIN |
| METAL_PLATE | ArmourType::METAL_PLATE |

### CharacterTypeEnum
| Name | Value |
|---|---|
| OT_NONE | CharacterTypeEnum::OT_NONE |
| OT_LAW_ENFORCEMENT | CharacterTypeEnum::OT_LAW_ENFORCEMENT |
| OT_MILITARY | CharacterTypeEnum::OT_MILITARY |
| OT_TRADER | CharacterTypeEnum::OT_TRADER |
| OT_CIVILIAN | CharacterTypeEnum::OT_CIVILIAN |
| OT_DIPLOMAT | CharacterTypeEnum::OT_DIPLOMAT |
| OT_SLAVE | CharacterTypeEnum::OT_SLAVE |
| OT_SLAVER | CharacterTypeEnum::OT_SLAVER |
| OT_BANDIT | CharacterTypeEnum::OT_BANDIT |
| OT_ADVENTURER | CharacterTypeEnum::OT_ADVENTURER |
| OT_END | CharacterTypeEnum::OT_END |
#### or
| NONE | CharacterTypeEnum::OT_NONE |
| LAW_ENFORCEMENT | CharacterTypeEnum::OT_LAW_ENFORCEMENT |
| MILITARY | CharacterTypeEnum::OT_MILITARY |
| TRADER | CharacterTypeEnum::OT_TRADER |
| CIVILIAN | CharacterTypeEnum::OT_CIVILIAN |
| DIPLOMAT | CharacterTypeEnum::OT_DIPLOMAT |
| SLAVE | CharacterTypeEnum::OT_SLAVE |
| SLAVER | CharacterTypeEnum::OT_SLAVER |
| BANDIT | CharacterTypeEnum::OT_BANDIT |
| ADVENTURER | CharacterTypeEnum::OT_ADVENTURER |
| END | CharacterTypeEnum::OT_END |

### SlaveStateEnum
| Name | Value |
|---|---|
| NOT_SLAVE | SlaveStateEnum::NOT_SLAVE |
| IS_SLAVE | SlaveStateEnum::IS_SLAVE |
| ESCAPING_SLAVE | SlaveStateEnum::ESCAPING_SLAVE |
| EX_SLAVE | SlaveStateEnum::EX_SLAVE |

### TaskType
| Name | Value |
|---|---|
| NULL_TASK | TaskType::NULL_TASK |
| MOVE_ON_FREE_WILL | TaskType::MOVE_ON_FREE_WILL |
| BUILD | TaskType::BUILD |
| PICKUP | TaskType::PICKUP |
| MELEE_ATTACK | TaskType::MELEE_ATTACK |
| FOCUSED_MELEE_ATTACK | TaskType::FOCUSED_MELEE_ATTACK |
| EQUIP_WEAPON | TaskType::EQUIP_WEAPON |
| UNEQUIP_WEAPON | TaskType::UNEQUIP_WEAPON |
| FIND_WEAPON | TaskType::FIND_WEAPON |
| CHOOSE_ENEMY_AND_ATTACK | TaskType::CHOOSE_ENEMY_AND_ATTACK |
| CHOOSE_ATTACKER_OF_ALLY | TaskType::CHOOSE_ATTACKER_OF_ALLY |
| ATTACK_CHARACTERS_ATTACKER | TaskType::ATTACK_CHARACTERS_ATTACKER |
| PLAYER_TALK_TO | TaskType::PLAYER_TALK_TO |
| ATTACK_ATTACKERS_OF | TaskType::ATTACK_ATTACKERS_OF |
| IDLE | TaskType::IDLE |
| PROTECT_ALLIES | TaskType::PROTECT_ALLIES |
| ATTACK_ENEMIES | TaskType::ATTACK_ENEMIES |
| PROTECTION | TaskType::PROTECTION |
| RAID_TOWN | TaskType::RAID_TOWN |
| GO_HOMEBUILDING | TaskType::GO_HOMEBUILDING |
| STAND_AT_SHOPKEEPER_NODE | TaskType::STAND_AT_SHOPKEEPER_NODE |
| ATTACK_ENEMIES_AND_NEUTRALS | TaskType::ATTACK_ENEMIES_AND_NEUTRALS |
| PATROL | TaskType::PATROL |
| ATTACK_TOWN | TaskType::ATTACK_TOWN |
| WANDERER | TaskType::WANDERER |
| FIRST_AID_ORDER | TaskType::FIRST_AID_ORDER |
| LOOT_TARGET | TaskType::LOOT_TARGET |
| CROUCH | TaskType::CROUCH |
| STAND_UP | TaskType::STAND_UP |
| MOVE_CUS_ORDERED | TaskType::MOVE_CUS_ORDERED |
| HOLD_POSITION | TaskType::HOLD_POSITION |
| STAY_CLOSE_TO_TARGET | TaskType::STAY_CLOSE_TO_TARGET |
| SELF_PRESERVATION | TaskType::SELF_PRESERVATION |
| QUELL_AGGRESSION | TaskType::QUELL_AGGRESSION |
| ATTACK_TROUBLE_MAKERS | TaskType::ATTACK_TROUBLE_MAKERS |
| RUN_AWAY | TaskType::RUN_AWAY |
| PATROL_TOWN | TaskType::PATROL_TOWN |
| WANDER_TOWN | TaskType::WANDER_TOWN |
| STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT | TaskType::STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT |
| WANDERING_TRADER | TaskType::WANDERING_TRADER |
| GET_NEAR_TO | TaskType::GET_NEAR_TO |
| ATTACK_ENEMIES_OF_MY_SLAVEMASTER | TaskType::ATTACK_ENEMIES_OF_MY_SLAVEMASTER |
| NOT_BE_UNARMED | TaskType::NOT_BE_UNARMED |
| STAY_IN_HOME | TaskType::STAY_IN_HOME |
| FOLLOW_PLAYER_ORDER | TaskType::FOLLOW_PLAYER_ORDER |
| BODYGUARD | TaskType::BODYGUARD |
| CHASE | TaskType::CHASE |
| STAND_AT_GENERAL_NODE | TaskType::STAND_AT_GENERAL_NODE |
| STAND_AT_DEFENSIVE_NODE | TaskType::STAND_AT_DEFENSIVE_NODE |
| STAND_AT_BUILDING_GUARD_NODE | TaskType::STAND_AT_BUILDING_GUARD_NODE |
| STAND_AT_BUILDING_DEFENSIVE_NODE | TaskType::STAND_AT_BUILDING_DEFENSIVE_NODE |
| STAND_AT_NODE | TaskType::STAND_AT_NODE |
| GET_UP_STAY_DOWN_THOUGH | TaskType::GET_UP_STAY_DOWN_THOUGH |
| TRAVEL_TO_TARGET_TOWN | TaskType::TRAVEL_TO_TARGET_TOWN |
| REST | TaskType::REST |
| RECRUIT_AT_JOBCENTER | TaskType::RECRUIT_AT_JOBCENTER |
| SWITCH_FOLLOW_ME_MODE_ON | TaskType::SWITCH_FOLLOW_ME_MODE_ON |
| JOB_REPAIR_ROBOT | TaskType::JOB_REPAIR_ROBOT |
| JOB_MEDIC | TaskType::JOB_MEDIC |
| GET_READY_FOR_ACTION | TaskType::GET_READY_FOR_ACTION |
| FIRST_AID_ROBOT | TaskType::FIRST_AID_ROBOT |
| UNPROVOKED_FOCUSED_MELEE_ATTACK | TaskType::UNPROVOKED_FOCUSED_MELEE_ATTACK |
| STAND_STILL | TaskType::STAND_STILL |
| SQUAD_WAIT_FOR_ME | TaskType::SQUAD_WAIT_FOR_ME |
| MAKE_TARGET_STAND_STILL | TaskType::MAKE_TARGET_STAND_STILL |
| GET_UP_STAND_UP | TaskType::GET_UP_STAND_UP |
| FORCE_GET_UP | TaskType::FORCE_GET_UP |
| MOVE_ON_FREE_WILL_FAST | TaskType::MOVE_ON_FREE_WILL_FAST |
| LIFT_PERSON | TaskType::LIFT_PERSON |
| PUT_DOWN_OBJECT | TaskType::PUT_DOWN_OBJECT |
| PUT_DOWN_CHARACTER_IN_BED | TaskType::PUT_DOWN_CHARACTER_IN_BED |
| ADD_MATERIALS_TO_BUILDING | TaskType::ADD_MATERIALS_TO_BUILDING |
| OPEN_DOOR | TaskType::OPEN_DOOR |
| CLOSE_DOOR | TaskType::CLOSE_DOOR |
| OPEN_DOOR_HERE | TaskType::OPEN_DOOR_HERE |
| CLOSE_DOOR_HERE | TaskType::CLOSE_DOOR_HERE |
| PICK_LOCK | TaskType::PICK_LOCK |
| LOCK_DOOR | TaskType::LOCK_DOOR |
| UNLOCK_DOOR | TaskType::UNLOCK_DOOR |
| LOCK_DOOR_HERE | TaskType::LOCK_DOOR_HERE |
| UNLOCK_DOOR_HERE | TaskType::UNLOCK_DOOR_HERE |
| BASH_DOOR | TaskType::BASH_DOOR |
| MOVE_TO_BUILDING_DOOR | TaskType::MOVE_TO_BUILDING_DOOR |
| MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR | TaskType::MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR |
| OPEN_DOOR_FOR_CURRENT_LOCATION | TaskType::OPEN_DOOR_FOR_CURRENT_LOCATION |
| OPEN_DOOR_FOR_DESTINATION | TaskType::OPEN_DOOR_FOR_DESTINATION |
| OPEN_UP_SHOP_DOORS | TaskType::OPEN_UP_SHOP_DOORS |
| OPERATE_MACHINERY | TaskType::OPERATE_MACHINERY |
| DELIVER_RESOURCES | TaskType::DELIVER_RESOURCES |
| JOB_KEEP_EVERYTHING_RUNNING | TaskType::JOB_KEEP_EVERYTHING_RUNNING |
| UNJAM_ALL_MACHINES | TaskType::UNJAM_ALL_MACHINES |
| UNJAM_MACHINE | TaskType::UNJAM_MACHINE |
| COLLECT_OUTPUT_RESOURCE | TaskType::COLLECT_OUTPUT_RESOURCE |
| FILL_MACHINE | TaskType::FILL_MACHINE |
| WANT_TO_FILL_MACHINE | TaskType::WANT_TO_FILL_MACHINE |
| REPAIR | TaskType::REPAIR |
| DISMANTLE | TaskType::DISMANTLE |
| USE_TRAINING_DUMMY | TaskType::USE_TRAINING_DUMMY |
| USE_BED | TaskType::USE_BED |
| PUT_SOMEONE_IN_BED | TaskType::PUT_SOMEONE_IN_BED |
| GET_PUT_IN_BED | TaskType::GET_PUT_IN_BED |
| DEFEAT_SQUAD | TaskType::DEFEAT_SQUAD |
| SEEK_AND_TALK_AND_SEND_SIGNAL | TaskType::SEEK_AND_TALK_AND_SEND_SIGNAL |
| MAKE_ANNOUNCEMENT | TaskType::MAKE_ANNOUNCEMENT |
| ALWAYS_IMPOSSIBLE_TASK | TaskType::ALWAYS_IMPOSSIBLE_TASK |
| FIND_AND_RESCUE | TaskType::FIND_AND_RESCUE |
| FIND_BED_AND_PUT_IN | TaskType::FIND_BED_AND_PUT_IN |
| USE_CAGE | TaskType::USE_CAGE |
| PUT_IN_CAGE | TaskType::PUT_IN_CAGE |
| KNOCKOUT_PRISONER | TaskType::KNOCKOUT_PRISONER |
| RELEASE_PRISONER | TaskType::RELEASE_PRISONER |
| BREAKOUT_PRISONER | TaskType::BREAKOUT_PRISONER |
| FIND_CAGE_AND_PUT_IN | TaskType::FIND_CAGE_AND_PUT_IN |
| EMPTY_MACHINE_OUTPUTS | TaskType::EMPTY_MACHINE_OUTPUTS |
| GET_RID_OF_RESOURCES_IN_MY_INVENTORY | TaskType::GET_RID_OF_RESOURCES_IN_MY_INVENTORY |
| FIND_SOME_BUILDING_MATERIALS | TaskType::FIND_SOME_BUILDING_MATERIALS |
| GET_OUT_OF_BED | TaskType::GET_OUT_OF_BED |
| FIND_A_SHOP | TaskType::FIND_A_SHOP |
| SHOPPING | TaskType::SHOPPING |
| BUY_SHIT | TaskType::BUY_SHIT |
| MOVE_INSIDE_BUILDING | TaskType::MOVE_INSIDE_BUILDING |
| MOVE_TO_FORTIFICATION_GATE | TaskType::MOVE_TO_FORTIFICATION_GATE |
| OPEN_FORTIFICATION_GATE | TaskType::OPEN_FORTIFICATION_GATE |
| BASH_GATE | TaskType::BASH_GATE |
| OPERATE_STORAGE | TaskType::OPERATE_STORAGE |
| JOB_BUILDER | TaskType::JOB_BUILDER |
| TALKTO_NEAREST_PLAYER_CHARACTER | TaskType::TALKTO_NEAREST_PLAYER_CHARACTER |
| RUN_AWAY_HOMETOWN | TaskType::RUN_AWAY_HOMETOWN |
| RETREAT_HOMETOWN | TaskType::RETREAT_HOMETOWN |
| MAKE_ANNOUNCEMENT_FAST | TaskType::MAKE_ANNOUNCEMENT_FAST |
| TRAVEL_TO_TARGET_TOWN_FAST | TaskType::TRAVEL_TO_TARGET_TOWN_FAST |
| LOOT_FOOD_AND_STUFF | TaskType::LOOT_FOOD_AND_STUFF |
| FIND_AND_KIDNAP | TaskType::FIND_AND_KIDNAP |
| GET_OUT_OF_CAGE_LEGIT | TaskType::GET_OUT_OF_CAGE_LEGIT |
| KILL_CAGE_OCCUPANT | TaskType::KILL_CAGE_OCCUPANT |
| KILL_A_RANDOM_CAGE_OCCUPANT | TaskType::KILL_A_RANDOM_CAGE_OCCUPANT |
| FEED_CORPSE_INTO_MACHINE | TaskType::FEED_CORPSE_INTO_MACHINE |
| DEAD_GUYS_GO_IN_THE_POT | TaskType::DEAD_GUYS_GO_IN_THE_POT |
| FIND_A_DEAD_GUY | TaskType::FIND_A_DEAD_GUY |
| EAT_A_RANDOM_CAGE_OCCUPANT | TaskType::EAT_A_RANDOM_CAGE_OCCUPANT |
| UNLOCK_DOOR_PLAYER_ORDER | TaskType::UNLOCK_DOOR_PLAYER_ORDER |
| FOLLOW_SQUADLEADER | TaskType::FOLLOW_SQUADLEADER |
| FIND_AND_RESCUE_LEADER | TaskType::FIND_AND_RESCUE_LEADER |
| PROTECT_OWN_SQUAD | TaskType::PROTECT_OWN_SQUAD |
| TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME | TaskType::TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME |
| GET_RE_EQUIPPED | TaskType::GET_RE_EQUIPPED |
| USE_TURRET | TaskType::USE_TURRET |
| STUMBLE_TASK_FORCED | TaskType::STUMBLE_TASK_FORCED |
| FIND_AND_RESCUE_IF_THERES_BEDS | TaskType::FIND_AND_RESCUE_IF_THERES_BEDS |
| MAN_A_TURRET | TaskType::MAN_A_TURRET |
| PROSPECTING | TaskType::PROSPECTING |
| EMPTYING_MACHINE | TaskType::EMPTYING_MACHINE |
| OPERATE_AUTOMATIC_MACHINERY | TaskType::OPERATE_AUTOMATIC_MACHINERY |
| GO_HOME_AND_GO_TO_BED | TaskType::GO_HOME_AND_GO_TO_BED |
| GO_TO_THE_BAR_AND_DRINK | TaskType::GO_TO_THE_BAR_AND_DRINK |
| LOCK_ALL_MY_DOORS | TaskType::LOCK_ALL_MY_DOORS |
| ENTER_BUILDING | TaskType::ENTER_BUILDING |
| STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE | TaskType::STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE |
| SHOO_STRANGERS_OUT_OF_MY_BUILDING | TaskType::SHOO_STRANGERS_OUT_OF_MY_BUILDING |
| SEND_DIALOGUE_SIGNAL | TaskType::SEND_DIALOGUE_SIGNAL |
| SEND_DIALOGUE_SIGNAL_REPEAT | TaskType::SEND_DIALOGUE_SIGNAL_REPEAT |
| SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING | TaskType::SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING |
| LOCK_DOOR_FROM_INSIDE | TaskType::LOCK_DOOR_FROM_INSIDE |
| MOVE_TO_BUILDING_DOOR_INSIDEPOS | TaskType::MOVE_TO_BUILDING_DOOR_INSIDEPOS |
| FOLLOW_WHILE_TALKING | TaskType::FOLLOW_WHILE_TALKING |
| TOWN_STALKER | TaskType::TOWN_STALKER |
| CHAIN_TARGET | TaskType::CHAIN_TARGET |
| CAPTURE_NEW_SLAVES | TaskType::CAPTURE_NEW_SLAVES |
| CARRY_WOUNDED_SLAVES | TaskType::CARRY_WOUNDED_SLAVES |
| PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK | TaskType::PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK |
| LIFT_OBJECT_BUT_HEAL_FIRST | TaskType::LIFT_OBJECT_BUT_HEAL_FIRST |
| FOLLOW_SLAVEMASTER | TaskType::FOLLOW_SLAVEMASTER |
| SLAVE_GET_IN_MY_MASTERS_CAGE | TaskType::SLAVE_GET_IN_MY_MASTERS_CAGE |
| GATHER_SLAVES_FROM_CAGES | TaskType::GATHER_SLAVES_FROM_CAGES |
| GET_SLAVE | TaskType::GET_SLAVE |
| SLEEP_ON_FLOOR | TaskType::SLEEP_ON_FLOOR |
| HUNTING_BLOODSMELL | TaskType::HUNTING_BLOODSMELL |
| LOOT_THE_DEAD | TaskType::LOOT_THE_DEAD |
| LOOT_TO_REPLACE_MISSING_WEAPON | TaskType::LOOT_TO_REPLACE_MISSING_WEAPON |
| HUNT_MY_THIEF | TaskType::HUNT_MY_THIEF |
| MAN_THE_GATE | TaskType::MAN_THE_GATE |
| STRIP_TARGETS_WEAPONS | TaskType::STRIP_TARGETS_WEAPONS |
| PROCESS_AND_STRIP_NEW_SLAVE | TaskType::PROCESS_AND_STRIP_NEW_SLAVE |
| SLAVE_WATCHING | TaskType::SLAVE_WATCHING |
| PUT_LOOT_IN_STORAGE | TaskType::PUT_LOOT_IN_STORAGE |
| SHACKLES | TaskType::CUT_SHACKLES |
| BRUTE_FORCE_SHACKLES | TaskType::BRUTE_FORCE_SHACKLES |
| SLAVE_OBEDIENCE | TaskType::_SLAVE_OBEDIENCE |
| WORK_THE_SLAVES | TaskType::WORK_THE_SLAVES |
| AUTO_LABOURING_MINES | TaskType::AUTO_LABOURING_MINES |
| AUTO_LABOURING_MINES_PRETEND | TaskType::AUTO_LABOURING_MINES_PRETEND |
| GO_TO_NEAREST_HQ | TaskType::GO_TO_NEAREST_HQ |
| GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES | TaskType::GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES |
| CAPTURE_ESCAPING_SLAVES | TaskType::CAPTURE_ESCAPING_SLAVES |
| GIVE_ALL_MY_SLAVES_TO | TaskType::GIVE_ALL_MY_SLAVES_TO |
| LOCK_ALL_THE_CAGES | TaskType::LOCK_ALL_THE_CAGES |
| BEAT_CAGE_OCCUPANT | TaskType::BEAT_CAGE_OCCUPANT |
| LOCK_ALL_MY_DOORS_FROM_OUTSIDE | TaskType::LOCK_ALL_MY_DOORS_FROM_OUTSIDE |
| LOCK_DOOR_FROM_OUTSIDE | TaskType::LOCK_DOOR_FROM_OUTSIDE |
| MOVE_TO_BUILDING_DOOR_OUTSIDEPOS | TaskType::MOVE_TO_BUILDING_DOOR_OUTSIDEPOS |
| LEAVE_BUILDING | TaskType::LEAVE_BUILDING |
| PICK_LOCK_ON_SHACKLES | TaskType::PICK_LOCK_ON_SHACKLES |
| TOTAL_ESCAPE | TaskType::TOTAL_ESCAPE |
| ARREST_TARGET | TaskType::ARREST_TARGET |
| HUNT_BOUNTIES | TaskType::HUNT_BOUNTIES |
| ARREST_TARGETS_CARRIED_PERSON | TaskType::ARREST_TARGETS_CARRIED_PERSON |
| FIND_CAGE_AND_PUT_IN_IF_BOUNTY | TaskType::FIND_CAGE_AND_PUT_IN_IF_BOUNTY |
| GET_OUT_OF_CAGE_ESCAPE | TaskType::GET_OUT_OF_CAGE_ESCAPE |
| GET_OUT_OF_BED_IF_ITS_EMERGENCY | TaskType::GET_OUT_OF_BED_IF_ITS_EMERGENCY |
| INVESTIGATE_ALARMS | TaskType::INVESTIGATE_ALARMS |
| INVESTIGATE_ALARMS_ALLIES_ONLY | TaskType::INVESTIGATE_ALARMS_ALLIES_ONLY |
| POLICE_FREE_PRISONERS_WHEN_DONE | TaskType::POLICE_FREE_PRISONERS_WHEN_DONE |
| LOOT_STOLEN_GOODS | TaskType::LOOT_STOLEN_GOODS |
| LIFT_PERSON_SNATCHING_ALLOWED | TaskType::LIFT_PERSON_SNATCHING_ALLOWED |
| RELAX_IN_TOWN_PACKAGE | TaskType::RELAX_IN_TOWN_PACKAGE |
| TRAVEL_TO_TARGET_PACKAGE | TaskType::TRAVEL_TO_TARGET_PACKAGE |
| RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE | TaskType::RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE |
| GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN | TaskType::GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN |
| GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN | TaskType::GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN |
| TAKE_OFF_MY_SHACKLES | TaskType::TAKE_OFF_MY_SHACKLES |
| EAT_TARGET_ALIVE | TaskType::EAT_TARGET_ALIVE |
| PRETEND_TO_OPERATE_MACHINERY | TaskType::PRETEND_TO_OPERATE_MACHINERY |
| MAN_A_TURRET_ON_BUILDING | TaskType::MAN_A_TURRET_ON_BUILDING |
| PICKUP_INTRUDERS_BUILDING | TaskType::PICKUP_INTRUDERS_BUILDING |
| TAKE_INTRUDER_OUTSIDE | TaskType::TAKE_INTRUDER_OUTSIDE |
| LIFT_PERSON_PLAYER_ORDER | TaskType::LIFT_PERSON_PLAYER_ORDER |
| BASH_DOOR_PLAYER_ORDER | TaskType::BASH_DOOR_PLAYER_ORDER |
| MELEE_ATTACK_ANIMAL | TaskType::MELEE_ATTACK_ANIMAL |
| STEALTH_KNOCKOUT | TaskType::STEALTH_KNOCKOUT |
| STEALTH_KILL | TaskType::STEALTH_KILL |
| EAT_A_RANDOM_DEAD_BODY | TaskType::EAT_A_RANDOM_DEAD_BODY |
| EAT_CROPS | TaskType::EAT_CROPS |
| FIND_CROPS_TO_EAT | TaskType::FIND_CROPS_TO_EAT |
| EAT_A_RANDOM_KO_BODY | TaskType::EAT_A_RANDOM_KO_BODY |
| MAN_A_TURRET_PLAYER_JOB | TaskType::MAN_A_TURRET_PLAYER_JOB |
| SHOOT_AT_TARGET | TaskType::SHOOT_AT_TARGET |
| WORSHIP_TARGET | TaskType::WORSHIP_TARGET |
| FOGMAN_WORSHIP_VICTIM | TaskType::FOGMAN_WORSHIP_VICTIM |
| LOOT_ANIMALS_JOB | TaskType::LOOT_ANIMALS_JOB |
| GO_HOME_AND_GO_TO_BED_SECURE | TaskType::GO_HOME_AND_GO_TO_BED_SECURE |
| LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY | TaskType::LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY |
| LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR | TaskType::LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR |
| DITCH_ALL_RESOURCES | TaskType::DITCH_ALL_RESOURCES |
| AQUIRE_FOOD_AT_HOMEBASE | TaskType::AQUIRE_FOOD_AT_HOMEBASE |
| GRAB_ONE_FOOD | TaskType::GRAB_ONE_FOOD |
| GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST | TaskType::GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST |
| KIDNAP_ORDER | TaskType::KIDNAP_ORDER |
| COLLECT_OUTPUT_RESOURCE_BUILD_MATS | TaskType::COLLECT_OUTPUT_RESOURCE_BUILD_MATS |
| DEFEAT_SQUAD_LIMIT_CHASE_RANGE | TaskType::DEFEAT_SQUAD_LIMIT_CHASE_RANGE |
| SPLINT_ORDER | TaskType::SPLINT_ORDER |
| SPLINT_JOB | TaskType::SPLINT_JOB |
| ESCAPE_KIDNAP | TaskType::ESCAPE_KIDNAP |
| ESCAPE_KIDNAP_STR | TaskType::ESCAPE_KIDNAP_STR |
| FOLLOW_URGENT_ESCAPE | TaskType::FOLLOW_URGENT_ESCAPE |
| FINAL_KIDNAPPER_CAGE_JOB | TaskType::FINAL_KIDNAPPER_CAGE_JOB |
| SIT_ON_THRONE | TaskType::SIT_ON_THRONE |
| GET_OUT_OF_CAGE_OPPORTUNISTIC | TaskType::GET_OUT_OF_CAGE_OPPORTUNISTIC |
| GET_OUT_OF_BED_ONCE_HEALED | TaskType::GET_OUT_OF_BED_ONCE_HEALED |
| USE_BED_ORDER | TaskType::USE_BED_ORDER |
| EAT_FOOD_ON_GROUND | TaskType::EAT_FOOD_ON_GROUND |
| NEW_SLAVE_PROCESSING | TaskType::NEW_SLAVE_PROCESSING |
| SLEEP_ON_FLOOR_FAKE_AMBUSH | TaskType::SLEEP_ON_FLOOR_FAKE_AMBUSH |
| RANGED_ATTACK | TaskType::RANGED_ATTACK |
| RANGED_ATTACK_FOCUSED | TaskType::RANGED_ATTACK_FOCUSED |
| EQUIP_CROSSBOW | TaskType::EQUIP_CROSSBOW |
| UNEQUIP_CROSSBOW | TaskType::UNEQUIP_CROSSBOW |
| RANGED_ATTACK_FOCUSED_UNPROVOKED | TaskType::RANGED_ATTACK_FOCUSED_UNPROVOKED |
| MOVE_IN_BOW_RANGE | TaskType::MOVE_IN_BOW_RANGE |
| STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY | TaskType::STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY |
| HEAL_MY_LEGS | TaskType::HEAL_MY_LEGS |
| ASSAULT_FORTIFICATIONS_PREFER_GATES | TaskType::ASSAULT_FORTIFICATIONS_PREFER_GATES |
| ASSAULT_FORTIFICATIONS_PREFER_WALLS | TaskType::ASSAULT_FORTIFICATIONS_PREFER_WALLS |
| SMASH_BUILDING | TaskType::SMASH_BUILDING |
| PICKUP_INTRUDERS_TOWN | TaskType::PICKUP_INTRUDERS_TOWN |
| TAKE_INTRUDER_OUTSIDE_TOWN | TaskType::TAKE_INTRUDER_OUTSIDE_TOWN |
| SIT_AROUND | TaskType::SIT_AROUND |
| LIBERATE_ALL_THE_PRISONERS | TaskType::LIBERATE_ALL_THE_PRISONERS |
| ANIMAL_FETCH_A_LIMB | TaskType::ANIMAL_FETCH_A_LIMB |
| PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH | TaskType::PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH |
| CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS | TaskType::CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS |
| RUN_AWAY_FORCED | TaskType::RUN_AWAY_FORCED |
| FIND_CAGE_AND_PUT_DEADGUY_IN | TaskType::FIND_CAGE_AND_PUT_DEADGUY_IN |
| EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE | TaskType::EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE |
| SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE | TaskType::SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE |
| LOOT_CONTAINER | TaskType::LOOT_CONTAINER |
| LOCK | TaskType::CUT_LOCK |
| BRUTE_FORCE_LOCK | TaskType::BRUTE_FORCE_LOCK |
| BASH_DOOR_HERE | TaskType::BASH_DOOR_HERE |
| PROTECT_ALLIES_STAY_IN_TOWN | TaskType::PROTECT_ALLIES_STAY_IN_TOWN |
| STAY_CLOSE_TO_TARGET_ANIMAL | TaskType::STAY_CLOSE_TO_TARGET_ANIMAL |
| BASH_GATE_PLAYER_ORDER | TaskType::BASH_GATE_PLAYER_ORDER |

### WeaponCategory
| Name | Value |
|---|---|
| SKILL_KATANAS | WeaponCategory::SKILL_KATANAS |
| SKILL_SABRES | WeaponCategory::SKILL_SABRES |
| SKILL_BLUNT | WeaponCategory::SKILL_BLUNT |
| SKILL_HEAVY | WeaponCategory::SKILL_HEAVY |
| SKILL_HACKERS | WeaponCategory::SKILL_HACKERS |
| SKILL_UNARMED | WeaponCategory::SKILL_UNARMED |
| SKILL_BOW | WeaponCategory::SKILL_BOW |
| SKILL_TURRET | WeaponCategory::SKILL_TURRET |
| ATTACK_POLEARMS | WeaponCategory::ATTACK_POLEARMS |
| ATTACK_ELEPHANT | WeaponCategory::ATTACK_ELEPHANT |
| ATTACK_DOG | WeaponCategory::ATTACK_DOG |
| ATTACK_BULL | WeaponCategory::ATTACK_BULL |
| ATTACK_ROBOTSPIDER | WeaponCategory::ATTACK_ROBOTSPIDER |
| ATTACK_SPIDER | WeaponCategory::ATTACK_SPIDER |
| ATTACK_CAGEBEAST | WeaponCategory::ATTACK_CAGEBEAST |
| ATTACK_DUCK | WeaponCategory::ATTACK_DUCK |
| ATTACK_GORILLA | WeaponCategory::ATTACK_GORILLA |
| ATTACK_GAR | WeaponCategory::ATTACK_GAR |
| ATTACK_FROG | WeaponCategory::ATTACK_FROG |
| ATTACK_GOAT | WeaponCategory::ATTACK_GOAT |
| ATTACK_GIRAFFE | WeaponCategory::ATTACK_GIRAFFE |
| ATTACK_NULL | WeaponCategory::ATTACK_NULL |
| NUM_SKILL_TYPES | WeaponCategory::NUM_SKILL_TYPES |
#### or
| KATANAS | WeaponCategory::SKILL_KATANAS |
| SABRES | WeaponCategory::SKILL_SABRES |
| BLUNT | WeaponCategory::SKILL_BLUNT |
| HEAVY | WeaponCategory::SKILL_HEAVY |
| HACKERS | WeaponCategory::SKILL_HACKERS |
| UNARMED | WeaponCategory::SKILL_UNARMED |
| BOW | WeaponCategory::SKILL_BOW |
| TURRET | WeaponCategory::SKILL_TURRET |
| POLEARMS | WeaponCategory::ATTACK_POLEARMS |
| ELEPHANT | WeaponCategory::ATTACK_ELEPHANT |
| DOG | WeaponCategory::ATTACK_DOG |
| BULL | WeaponCategory::ATTACK_BULL |
| ROBOTSPIDER | WeaponCategory::ATTACK_ROBOTSPIDER |
| SPIDER | WeaponCategory::ATTACK_SPIDER |
| CAGEBEAST | WeaponCategory::ATTACK_CAGEBEAST |
| DUCK | WeaponCategory::ATTACK_DUCK |
| GORILLA | WeaponCategory::ATTACK_GORILLA |
| GAR | WeaponCategory::ATTACK_GAR |
| FROG | WeaponCategory::ATTACK_FROG |
| GOAT | WeaponCategory::ATTACK_GOAT |
| GIRAFFE | WeaponCategory::ATTACK_GIRAFFE |
| NULL | WeaponCategory::ATTACK_NULL |
| NUM_SKILL_TYPES | WeaponCategory::NUM_SKILL_TYPES |

### LeftRight
| Name | Value |
|---|---|
| SIDE_NEITHER | LeftRight::SIDE_NEITHER |
| SIDE_LEFT | LeftRight::SIDE_LEFT |
| SIDE_RIGHT | LeftRight::SIDE_RIGHT |
| SIDE_BOTH | LeftRight::SIDE_BOTH |
#### or
| NEITHER | LeftRight::SIDE_NEITHER |
| LEFT | LeftRight::SIDE_LEFT |
| RIGHT | LeftRight::SIDE_RIGHT |
| BOTH | LeftRight::SIDE_BOTH |

### MessageType
| Name | Value |
|---|---|
| M_UNSELECT_ALL | MessageForB::MessageType::M_UNSELECT_ALL |
| M_GIVE_TASK | MessageForB::MessageType::M_GIVE_TASK |
#### or
| UNSELECT_ALL | MessageForB::MessageType::M_UNSELECT_ALL |
| GIVE_TASK | MessageForB::MessageType::M_GIVE_TASK |

### MessageB::StandingOrder
| Name | Value |
|---|---|
| M_SET_ORDER_RUN | MessageForB::StandingOrder::M_SET_ORDER_RUN |
| M_SET_ORDER_JOG | MessageForB::StandingOrder::M_SET_ORDER_JOG |
| M_SET_ORDER_WALK | MessageForB::StandingOrder::M_SET_ORDER_WALK |
| M_SET_ORDER_STEALTH_ON | MessageForB::StandingOrder::M_SET_ORDER_STEALTH_ON |
| M_SET_ORDER_STEALTH_OFF | MessageForB::StandingOrder::M_SET_ORDER_STEALTH_OFF |
| M_SET_ORDER_AGG | MessageForB::StandingOrder::M_SET_ORDER_AGG |
| M_SET_ORDER_DEF | MessageForB::StandingOrder::M_SET_ORDER_DEF |
| M_SET_ORDER_EVADE | MessageForB::StandingOrder::M_SET_ORDER_EVADE |
| M_SET_ORDER_FAR | MessageForB::StandingOrder::M_SET_ORDER_FAR |
| M_SET_ORDER_NEAR | MessageForB::StandingOrder::M_SET_ORDER_NEAR |
| M__TOGGLEORDERS__AFTER__THIS_ | MessageForB::StandingOrder::M__TOGGLEORDERS__AFTER__THIS_ |
| M_SET_ORDER_DEFENSIVE_COMBAT | MessageForB::StandingOrder::M_SET_ORDER_DEFENSIVE_COMBAT |
| M_SET_ORDER_HOLD | MessageForB::StandingOrder::M_SET_ORDER_HOLD |
| M_SET_ORDER_PASSIVE | MessageForB::StandingOrder::M_SET_ORDER_PASSIVE |
| M_SET_ORDER_TAUNT | MessageForB::StandingOrder::M_SET_ORDER_TAUNT |
| M_SET_ORDER_CHASE | MessageForB::StandingOrder::M_SET_ORDER_CHASE |
| M_SET_ORDER_GROUP_SPEED | MessageForB::StandingOrder::M_SET_ORDER_GROUP_SPEED |
| M_SET_ORDER_RANGED | MessageForB::StandingOrder::M_SET_ORDER_RANGED |

### StatsEnumerated
| Name | Value |
|---|---|
| STAT_NONE | StatsEnumerated::STAT_NONE |
| STAT_STRENGTH | StatsEnumerated::STAT_STRENGTH |
| STAT_MELEE_ATTACK | StatsEnumerated::STAT_MELEE_ATTACK |
| STAT_LABOURING | StatsEnumerated::STAT_LABOURING |
| STAT_SCIENCE | StatsEnumerated::STAT_SCIENCE |
| STAT_ENGINEERING | StatsEnumerated::STAT_ENGINEERING |
| STAT_ROBOTICS | StatsEnumerated::STAT_ROBOTICS |
| STAT_SMITHING_WEAPON | StatsEnumerated::STAT_SMITHING_WEAPON |
| STAT_SMITHING_ARMOUR | StatsEnumerated::STAT_SMITHING_ARMOUR |
| STAT_MEDIC | StatsEnumerated::STAT_MEDIC |
| STAT_THIEVING | StatsEnumerated::STAT_THIEVING |
| STAT_TURRETS | StatsEnumerated::STAT_TURRETS |
| STAT_FARMING | StatsEnumerated::STAT_FARMING |
| STAT_COOKING | StatsEnumerated::STAT_COOKING |
| STAT_HIVEMEDIC | StatsEnumerated::STAT_HIVEMEDIC |
| STAT_VET | StatsEnumerated::STAT_VET |
| STAT_STEALTH | StatsEnumerated::STAT_STEALTH |
| STAT_ATHLETICS | StatsEnumerated::STAT_ATHLETICS |
| STAT_DEXTERITY | StatsEnumerated::STAT_DEXTERITY |
| STAT_MELEE_DEFENCE | StatsEnumerated::STAT_MELEE_DEFENCE |
| STAT_WEAPONS | StatsEnumerated::STAT_WEAPONS |
| STAT_TOUGHNESS | StatsEnumerated::STAT_TOUGHNESS |
| STAT_ASSASSINATION | StatsEnumerated::STAT_ASSASSINATION |
| STAT_SWIMMING | StatsEnumerated::STAT_SWIMMING |
| STAT_PERCEPTION | StatsEnumerated::STAT_PERCEPTION |
| STAT_KATANAS | StatsEnumerated::STAT_KATANAS |
| STAT_SABRES | StatsEnumerated::STAT_SABRES |
| STAT_HACKERS | StatsEnumerated::STAT_HACKERS |
| STAT_HEAVYWEAPONS | StatsEnumerated::STAT_HEAVYWEAPONS |
| STAT_BLUNT | StatsEnumerated::STAT_BLUNT |
| STAT_MARTIALARTS | StatsEnumerated::STAT_MARTIALARTS |
| STAT_MASSCOMBAT | StatsEnumerated::STAT_MASSCOMBAT |
| STAT_DODGE | StatsEnumerated::STAT_DODGE |
| STAT_SURVIVAL | StatsEnumerated::STAT_SURVIVAL |
| STAT_POLEARMS | StatsEnumerated::STAT_POLEARMS |
| STAT_CROSSBOWS | StatsEnumerated::STAT_CROSSBOWS |
| STAT_FRIENDLY_FIRE | StatsEnumerated::STAT_FRIENDLY_FIRE |
| STAT_LOCKPICKING | StatsEnumerated::STAT_LOCKPICKING |
| STAT_SMITHING_BOW | StatsEnumerated::STAT_SMITHING_BOW |
| STAT_END | StatsEnumerated::STAT_END |
| _PrimaryWeaponDamage | StatsEnumerated::_PrimaryWeaponDamage |
| _PrimaryWeaponSpeed | StatsEnumerated::_PrimaryWeaponSpeed |
| _SecondaryWeaponDamage | StatsEnumerated::_SecondaryWeaponDamage |
| _SecondaryWeaponSpeed | StatsEnumerated::_SecondaryWeaponSpeed |
| _MaxCarryWeight | StatsEnumerated::_MaxCarryWeight |
| _StrengthXPRateWalk | StatsEnumerated::_StrengthXPRateWalk |
| _StrengthXPRateCombat | StatsEnumerated::_StrengthXPRateCombat |
| _AttackSpeedHeavyWeapons | StatsEnumerated::_AttackSpeedHeavyWeapons |
| _DamageResistance | StatsEnumerated::_DamageResistance |
| _ToughnessXPRate | StatsEnumerated::_ToughnessXPRate |
| _KnockoutTime | StatsEnumerated::_KnockoutTime |
| _ToughnessKnockoutPoint | StatsEnumerated::_ToughnessKnockoutPoint |
| _WoundDeteriorationSpeed | StatsEnumerated::_WoundDeteriorationSpeed |
| _MaxRunSpeed | StatsEnumerated::_MaxRunSpeed |
| _CurrentRunSpeed | StatsEnumerated::_CurrentRunSpeed |
| _AthleticsXPBonus | StatsEnumerated::_AthleticsXPBonus |
| _TurretAccuracy | StatsEnumerated::_TurretAccuracy |
| _TurretRateOfFire | StatsEnumerated::_TurretRateOfFire |
| _TurretFriendlyFireAvoidance | StatsEnumerated::_TurretFriendlyFireAvoidance |
| _BuildingRate | StatsEnumerated::_BuildingRate |
| _RepairingRate | StatsEnumerated::_RepairingRate |
| _Mining | StatsEnumerated::_Mining |
| _Farming | StatsEnumerated::_Farming |
| _UsingMachinery | StatsEnumerated::_UsingMachinery |
| _encumbrance | StatsEnumerated::_encumbrance |
| _combatSpeed | StatsEnumerated::_combatSpeed |
#### or
| NONE | StatsEnumerated::STAT_NONE |
| STRENGTH | StatsEnumerated::STAT_STRENGTH |
| MELEE_ATTACK | StatsEnumerated::STAT_MELEE_ATTACK |
| LABOURING | StatsEnumerated::STAT_LABOURING |
| SCIENCE | StatsEnumerated::STAT_SCIENCE |
| ENGINEERING | StatsEnumerated::STAT_ENGINEERING |
| ROBOTICS | StatsEnumerated::STAT_ROBOTICS |
| SMITHING_WEAPON | StatsEnumerated::STAT_SMITHING_WEAPON |
| SMITHING_ARMOUR | StatsEnumerated::STAT_SMITHING_ARMOUR |
| MEDIC | StatsEnumerated::STAT_MEDIC |
| THIEVING | StatsEnumerated::STAT_THIEVING |
| TURRETS | StatsEnumerated::STAT_TURRETS |
| FARMING | StatsEnumerated::STAT_FARMING |
| COOKING | StatsEnumerated::STAT_COOKING |
| HIVEMEDIC | StatsEnumerated::STAT_HIVEMEDIC |
| VET | StatsEnumerated::STAT_VET |
| STEALTH | StatsEnumerated::STAT_STEALTH |
| ATHLETICS | StatsEnumerated::STAT_ATHLETICS |
| DEXTERITY | StatsEnumerated::STAT_DEXTERITY |
| MELEE_DEFENCE | StatsEnumerated::STAT_MELEE_DEFENCE |
| WEAPONS | StatsEnumerated::STAT_WEAPONS |
| TOUGHNESS | StatsEnumerated::STAT_TOUGHNESS |
| ASSASSINATION | StatsEnumerated::STAT_ASSASSINATION |
| SWIMMING | StatsEnumerated::STAT_SWIMMING |
| PERCEPTION | StatsEnumerated::STAT_PERCEPTION |
| KATANAS | StatsEnumerated::STAT_KATANAS |
| SABRES | StatsEnumerated::STAT_SABRES |
| HACKERS | StatsEnumerated::STAT_HACKERS |
| HEAVYWEAPONS | StatsEnumerated::STAT_HEAVYWEAPONS |
| BLUNT | StatsEnumerated::STAT_BLUNT |
| MARTIALARTS | StatsEnumerated::STAT_MARTIALARTS |
| MASSCOMBAT | StatsEnumerated::STAT_MASSCOMBAT |
| DODGE | StatsEnumerated::STAT_DODGE |
| SURVIVAL | StatsEnumerated::STAT_SURVIVAL |
| POLEARMS | StatsEnumerated::STAT_POLEARMS |
| CROSSBOWS | StatsEnumerated::STAT_CROSSBOWS |
| FRIENDLY_FIRE | StatsEnumerated::STAT_FRIENDLY_FIRE |
| LOCKPICKING | StatsEnumerated::STAT_LOCKPICKING |
| SMITHING_BOW | StatsEnumerated::STAT_SMITHING_BOW |
| END | StatsEnumerated::STAT_END |
| PrimaryWeaponDamage | StatsEnumerated::_PrimaryWeaponDamage |
| PrimaryWeaponSpeed | StatsEnumerated::_PrimaryWeaponSpeed |
| SecondaryWeaponDamage | StatsEnumerated::_SecondaryWeaponDamage |
| SecondaryWeaponSpeed | StatsEnumerated::_SecondaryWeaponSpeed |
| MaxCarryWeight | StatsEnumerated::_MaxCarryWeight |
| StrengthXPRateWalk | StatsEnumerated::_StrengthXPRateWalk |
| StrengthXPRateCombat | StatsEnumerated::_StrengthXPRateCombat |
| AttackSpeedHeavyWeapons | StatsEnumerated::_AttackSpeedHeavyWeapons |
| DamageResistance | StatsEnumerated::_DamageResistance |
| ToughnessXPRate | StatsEnumerated::_ToughnessXPRate |
| KnockoutTime | StatsEnumerated::_KnockoutTime |
| ToughnessKnockoutPoint | StatsEnumerated::_ToughnessKnockoutPoint |
| WoundDeteriorationSpeed | StatsEnumerated::_WoundDeteriorationSpeed |
| MaxRunSpeed | StatsEnumerated::_MaxRunSpeed |
| CurrentRunSpeed | StatsEnumerated::_CurrentRunSpeed |
| AthleticsXPBonus | StatsEnumerated::_AthleticsXPBonus |
| TurretAccuracy | StatsEnumerated::_TurretAccuracy |
| TurretRateOfFire | StatsEnumerated::_TurretRateOfFire |
| TurretFriendlyFireAvoidance | StatsEnumerated::_TurretFriendlyFireAvoidance |
| BuildingRate | StatsEnumerated::_BuildingRate |
| RepairingRate | StatsEnumerated::_RepairingRate |
| Mining | StatsEnumerated::_Mining |
| Farming | StatsEnumerated::_Farming |
| UsingMachinery | StatsEnumerated::_UsingMachinery |
| Encumbrance | StatsEnumerated::_encumbrance |
| CombatSpeed | StatsEnumerated::_combatSpeed |

| encumbrance | StatsEnumerated::_encumbrance |
| combatSpeed | StatsEnumerated::_combatSpeed |

### EventTriggerEnum
| Name | Value |
|---|---|
| EV_NONE | EventTriggerEnum::EV_NONE |
| EV_PLAYER_TALK_TO_ME | EventTriggerEnum::EV_PLAYER_TALK_TO_ME |
| EV_ANNOUNCEMENT | EventTriggerEnum::EV_ANNOUNCEMENT |
| EV_I_SEE_NEUTRAL_SQUAD | EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD |
| EV_I_SEE_RAGDOLL | EventTriggerEnum::EV_I_SEE_RAGDOLL |
| EV_______ | EventTriggerEnum::EV_______ |
| EV_I_________ | EventTriggerEnum::EV_I_________ |
| EV_SHOO_FROM_MY_BUILDING | EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING |
| EV_MARKED_FOR_DEATH | EventTriggerEnum::EV_MARKED_FOR_DEATH |
| EV_SCREAMING_TORTURE | EventTriggerEnum::EV_SCREAMING_TORTURE |
| EV_BAR_TALK | EventTriggerEnum::EV_BAR_TALK |
| EV_UNLOCK_MY_CAGE_OR_SHACKLES | EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES |
| EV_UNLOCK_MY_CAGE_ATTEMPT | EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT |
| EV_I_DEFEATED_SQUAD | EventTriggerEnum::EV_I_DEFEATED_SQUAD |
| EV_LAUNCH_ATTACK | EventTriggerEnum::EV_LAUNCH_ATTACK |
| EV_INTRUDER_FOUND | EventTriggerEnum::EV_INTRUDER_FOUND |
| EV_HEALING_OTHER_START | EventTriggerEnum::EV_HEALING_OTHER_START |
| EV_BEING_HEALED_START | EventTriggerEnum::EV_BEING_HEALED_START |
| EV_HEALING_OTHER_FINISHED | EventTriggerEnum::EV_HEALING_OTHER_FINISHED |
| EV_BEING_HEALED_FINISHED | EventTriggerEnum::EV_BEING_HEALED_FINISHED |
| EV_FIRSTAID_KIT_EMPTY | EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY |
| EV_GET_UP_PEACE | EventTriggerEnum::EV_GET_UP_PEACE |
| EV_GET_UP_FIGHT | EventTriggerEnum::EV_GET_UP_FIGHT |
| EV_GET_UP_UNNECCESSARY_FIGHT | EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT |
| EV_HARRASSMENT_SHOUTS | EventTriggerEnum::EV_HARRASSMENT_SHOUTS |
| EV_I_SEE_ANIMAL_SQUAD | EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD |
| EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET | EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET |
| EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS | EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS |
| EV_CONTRACT_JOB_ENDED | EventTriggerEnum::EV_CONTRACT_JOB_ENDED |
| EV_BETRAYAL | EventTriggerEnum::EV_BETRAYAL |
| EV_LOOTING_WEAPON_ONLY | EventTriggerEnum::EV_LOOTING_WEAPON_ONLY |
| EV_LOOTING_EVERYTHING | EventTriggerEnum::EV_LOOTING_EVERYTHING |
| EV_I_SEE_UNIFORM_IMPOSTER | EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER |
| EV_INTRODUCING_NEW_SLAVE | EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE |
| EV_ESCAPING_SLAVE_SPOTTED | EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED |
| EV_RECAPTURED_A_SLAVE | EventTriggerEnum::EV_RECAPTURED_A_SLAVE |
| EV_SHOUT_AT_SLAVE_WORKER | EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER |
| EV_SLAVE_DELIVERY | EventTriggerEnum::EV_SLAVE_DELIVERY |
| EV_ESCAPED_EX_SLAVE_SPOTTED | EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED |
| EV_WITNESS_GENERIC_ASSAULT | EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT |
| EV_WITNESS_LOOTING_ALLY | EventTriggerEnum::EV_WITNESS_LOOTING_ALLY |
| EV_WITNESS_THIEF_OR_LOCKPICK | EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK |
| EV_BOUNTY_SPOTTED | EventTriggerEnum::EV_BOUNTY_SPOTTED |
| EV_ESCAPED_PRISONER_SPOTTED | EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED |
| EV_PRISONER_FREE_TO_GO | EventTriggerEnum::EV_PRISONER_FREE_TO_GO |
| EV_ALMOST_WOKE_UP | EventTriggerEnum::EV_ALMOST_WOKE_UP |
| EV_ENTER_BIOME | EventTriggerEnum::EV_ENTER_BIOME |
| EV_ENTER_TOWN | EventTriggerEnum::EV_ENTER_TOWN |
| EV_SQUAD_BROKEN | EventTriggerEnum::EV_SQUAD_BROKEN |
| EV_BOUGHT_ME_FROM_SLAVERY | EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY |
| EV_EATING_SOMETHING_SOUNDS | EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS |
| EV_WORSHIPING_SOMETHING | EventTriggerEnum::EV_WORSHIPING_SOMETHING |
| EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR | EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR |
| EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE | EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE |
| EV_ASSASSINATION_FAILED | EventTriggerEnum::EV_ASSASSINATION_FAILED |
| EV_EATING_MY_CROPS | EventTriggerEnum::EV_EATING_MY_CROPS |
| EV_KIDNAPPING_MY_ALLY | EventTriggerEnum::EV_KIDNAPPING_MY_ALLY |
| EV_USING_MY_TRAINING_EQUIPMENT | EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT |
| EV_GIVE_UP_CHASE | EventTriggerEnum::EV_GIVE_UP_CHASE |
| EV_ACID_FEET | EventTriggerEnum::EV_ACID_FEET |
| EV_ACID_RAIN | EventTriggerEnum::EV_ACID_RAIN |
| EV_ACID_WATER | EventTriggerEnum::EV_ACID_WATER |
| EV_WINDY | EventTriggerEnum::EV_WINDY |
| EV_POISON_GAS | EventTriggerEnum::EV_POISON_GAS |
| EV_I_SEE_ENEMY_PLAYER | EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER |
| EV_I_SEE_ALLY_PLAYER | EventTriggerEnum::EV_I_SEE_ALLY_PLAYER |
| EV_I_SEE_ILLEGAL_PLAYER_BUILDING | EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING |
| EV_BURNING | EventTriggerEnum::EV_BURNING |
| EV_LOST_LEG | EventTriggerEnum::EV_LOST_LEG |
| EV_LOST_ARM | EventTriggerEnum::EV_LOST_ARM |
| EV_I_SEE_PLAYER_NICE_BUILDING | EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING |
| EV_TAKEN_OVER_PLAYER_TOWN | EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN |
| EV_CROWD_TRIGGERED | EventTriggerEnum::EV_CROWD_TRIGGERED |
| EV_MAX | EventTriggerEnum::EV_MAX |
#### or
| NONE | EventTriggerEnum::EV_NONE |
| PLAYER_TALK_TO_ME | EventTriggerEnum::EV_PLAYER_TALK_TO_ME |
| ANNOUNCEMENT | EventTriggerEnum::EV_ANNOUNCEMENT |
| I_SEE_NEUTRAL_SQUAD | EventTriggerEnum::EV_I_SEE_NEUTRAL_SQUAD |
| I_SEE_RAGDOLL | EventTriggerEnum::EV_I_SEE_RAGDOLL |
| ______ | EventTriggerEnum::EV_______ |
| I_________ | EventTriggerEnum::EV_I_________ |
| SHOO_FROM_MY_BUILDING | EventTriggerEnum::EV_SHOO_FROM_MY_BUILDING |
| MARKED_FOR_DEATH | EventTriggerEnum::EV_MARKED_FOR_DEATH |
| SCREAMING_TORTURE | EventTriggerEnum::EV_SCREAMING_TORTURE |
| BAR_TALK | EventTriggerEnum::EV_BAR_TALK |
| UNLOCK_MY_CAGE_OR_SHACKLES | EventTriggerEnum::EV_UNLOCK_MY_CAGE_OR_SHACKLES |
| UNLOCK_MY_CAGE_ATTEMPT | EventTriggerEnum::EV_UNLOCK_MY_CAGE_ATTEMPT |
| I_DEFEATED_SQUAD | EventTriggerEnum::EV_I_DEFEATED_SQUAD |
| LAUNCH_ATTACK | EventTriggerEnum::EV_LAUNCH_ATTACK |
| INTRUDER_FOUND | EventTriggerEnum::EV_INTRUDER_FOUND |
| HEALING_OTHER_START | EventTriggerEnum::EV_HEALING_OTHER_START |
| BEING_HEALED_START | EventTriggerEnum::EV_BEING_HEALED_START |
| HEALING_OTHER_FINISHED | EventTriggerEnum::EV_HEALING_OTHER_FINISHED |
| BEING_HEALED_FINISHED | EventTriggerEnum::EV_BEING_HEALED_FINISHED |
| FIRSTAID_KIT_EMPTY | EventTriggerEnum::EV_FIRSTAID_KIT_EMPTY |
| GET_UP_PEACE | EventTriggerEnum::EV_GET_UP_PEACE |
| GET_UP_FIGHT | EventTriggerEnum::EV_GET_UP_FIGHT |
| GET_UP_UNNECCESSARY_FIGHT | EventTriggerEnum::EV_GET_UP_UNNECCESSARY_FIGHT |
| HARRASSMENT_SHOUTS | EventTriggerEnum::EV_HARRASSMENT_SHOUTS |
| I_SEE_ANIMAL_SQUAD | EventTriggerEnum::EV_I_SEE_ANIMAL_SQUAD |
| SPEECH_INTERRUPTED_ATTACKED_BY_TARGET | EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET |
| SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS | EventTriggerEnum::EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS |
| CONTRACT_JOB_ENDED | EventTriggerEnum::EV_CONTRACT_JOB_ENDED |
| BETRAYAL | EventTriggerEnum::EV_BETRAYAL |
| LOOTING_WEAPON_ONLY | EventTriggerEnum::EV_LOOTING_WEAPON_ONLY |
| LOOTING_EVERYTHING | EventTriggerEnum::EV_LOOTING_EVERYTHING |
| I_SEE_UNIFORM_IMPOSTER | EventTriggerEnum::EV_I_SEE_UNIFORM_IMPOSTER |
| INTRODUCING_NEW_SLAVE | EventTriggerEnum::EV_INTRODUCING_NEW_SLAVE |
| ESCAPING_SLAVE_SPOTTED | EventTriggerEnum::EV_ESCAPING_SLAVE_SPOTTED |
| RECAPTURED_A_SLAVE | EventTriggerEnum::EV_RECAPTURED_A_SLAVE |
| SHOUT_AT_SLAVE_WORKER | EventTriggerEnum::EV_SHOUT_AT_SLAVE_WORKER |
| SLAVE_DELIVERY | EventTriggerEnum::EV_SLAVE_DELIVERY |
| ESCAPED_EX_SLAVE_SPOTTED | EventTriggerEnum::EV_ESCAPED_EX_SLAVE_SPOTTED |
| WITNESS_GENERIC_ASSAULT | EventTriggerEnum::EV_WITNESS_GENERIC_ASSAULT |
| WITNESS_LOOTING_ALLY | EventTriggerEnum::EV_WITNESS_LOOTING_ALLY |
| WITNESS_THIEF_OR_LOCKPICK | EventTriggerEnum::EV_WITNESS_THIEF_OR_LOCKPICK |
| BOUNTY_SPOTTED | EventTriggerEnum::EV_BOUNTY_SPOTTED |
| ESCAPED_PRISONER_SPOTTED | EventTriggerEnum::EV_ESCAPED_PRISONER_SPOTTED |
| PRISONER_FREE_TO_GO | EventTriggerEnum::EV_PRISONER_FREE_TO_GO |
| ALMOST_WOKE_UP | EventTriggerEnum::EV_ALMOST_WOKE_UP |
| ENTER_BIOME | EventTriggerEnum::EV_ENTER_BIOME |
| ENTER_TOWN | EventTriggerEnum::EV_ENTER_TOWN |
| SQUAD_BROKEN | EventTriggerEnum::EV_SQUAD_BROKEN |
| BOUGHT_ME_FROM_SLAVERY | EventTriggerEnum::EV_BOUGHT_ME_FROM_SLAVERY |
| EATING_SOMETHING_SOUNDS | EventTriggerEnum::EV_EATING_SOMETHING_SOUNDS |
| WORSHIPING_SOMETHING | EventTriggerEnum::EV_WORSHIPING_SOMETHING |
| SLAVE_ESCAPE_OPPORTUNITY_SAVIOR | EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR |
| SLAVE_ESCAPE_OPPORTUNITY_ALONE | EventTriggerEnum::EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE |
| ASSASSINATION_FAILED | EventTriggerEnum::EV_ASSASSINATION_FAILED |
| EATING_MY_CROPS | EventTriggerEnum::EV_EATING_MY_CROPS |
| KIDNAPPING_MY_ALLY | EventTriggerEnum::EV_KIDNAPPING_MY_ALLY |
| USING_MY_TRAINING_EQUIPMENT | EventTriggerEnum::EV_USING_MY_TRAINING_EQUIPMENT |
| GIVE_UP_CHASE | EventTriggerEnum::EV_GIVE_UP_CHASE |
| ACID_FEET | EventTriggerEnum::EV_ACID_FEET |
| ACID_RAIN | EventTriggerEnum::EV_ACID_RAIN |
| ACID_WATER | EventTriggerEnum::EV_ACID_WATER |
| WINDY | EventTriggerEnum::EV_WINDY |
| POISON_GAS | EventTriggerEnum::EV_POISON_GAS |
| I_SEE_ENEMY_PLAYER | EventTriggerEnum::EV_I_SEE_ENEMY_PLAYER |
| I_SEE_ALLY_PLAYER | EventTriggerEnum::EV_I_SEE_ALLY_PLAYER |
| I_SEE_ILLEGAL_PLAYER_BUILDING | EventTriggerEnum::EV_I_SEE_ILLEGAL_PLAYER_BUILDING |
| BURNING | EventTriggerEnum::EV_BURNING |
| LOST_LEG | EventTriggerEnum::EV_LOST_LEG |
| LOST_ARM | EventTriggerEnum::EV_LOST_ARM |
| I_SEE_PLAYER_NICE_BUILDING | EventTriggerEnum::EV_I_SEE_PLAYER_NICE_BUILDING |
| TAKEN_OVER_PLAYER_TOWN | EventTriggerEnum::EV_TAKEN_OVER_PLAYER_TOWN |
| CROWD_TRIGGERED | EventTriggerEnum::EV_CROWD_TRIGGERED |
| MAX | EventTriggerEnum::EV_MAX |

### DialogConditionEnum
| Name | Value |
|---|---|
| DC_NONE | DialogConditionEnum::DC_NONE |
| DC_RELATIONS | DialogConditionEnum::DC_RELATIONS |
| DC_PLAYERMONEY | DialogConditionEnum::DC_PLAYERMONEY |
| DC_REPUTATION | DialogConditionEnum::DC_REPUTATION |
| DC_CARRYING_BOUNTY_ALIVE | DialogConditionEnum::DC_CARRYING_BOUNTY_ALIVE |
| DC_CARRYING_BOUNTY_DEAD | DialogConditionEnum::DC_CARRYING_BOUNTY_DEAD |
| DC_FACTION_VARIABLE | DialogConditionEnum::DC_FACTION_VARIABLE |
| DC_IMPRISONED_BY_TARGET | DialogConditionEnum::DC_IMPRISONED_BY_TARGET |
| DC_IMPRISONED_BY_OTHER | DialogConditionEnum::DC_IMPRISONED_BY_OTHER |
| DC_IS_A_TRADER | DialogConditionEnum::DC_IS_A_TRADER |
| DC_FACTION_RANK | DialogConditionEnum::DC_FACTION_RANK |
| DC_BUILDING_IS_CLOSED_AND_SECURED | DialogConditionEnum::DC_BUILDING_IS_CLOSED_AND_SECURED |
| DC_PLAYER_TECH_LEVEL | DialogConditionEnum::DC_PLAYER_TECH_LEVEL |
| DC_NUM_DIALOG_EVENT_REPEATS | DialogConditionEnum::DC_NUM_DIALOG_EVENT_REPEATS |
| DC_IS_IMPRISONED | DialogConditionEnum::DC_IS_IMPRISONED |
| DC_IMPRISONMENT_IS_DEATHROW | DialogConditionEnum::DC_IMPRISONMENT_IS_DEATHROW |
| DC_TARGET_IN_TALKING_RANGE | DialogConditionEnum::DC_TARGET_IN_TALKING_RANGE |
| DC_IN_MY_BUILDING | DialogConditionEnum::DC_IN_MY_BUILDING |
| DC_TARGET_LAST_SEEN_X_HOURS_AGO | DialogConditionEnum::DC_TARGET_LAST_SEEN_X_HOURS_AGO |
| DC_IS_LEADER | DialogConditionEnum::DC_IS_LEADER |
| DC_MET_TARGET_BEFORE | DialogConditionEnum::DC_MET_TARGET_BEFORE |
| DC_WEAKER_THAN_ME | DialogConditionEnum::DC_WEAKER_THAN_ME |
| DC_STRONGER_THAN_ME | DialogConditionEnum::DC_STRONGER_THAN_ME |
| DC_HAS_TAG | DialogConditionEnum::DC_HAS_TAG |
| DC_IS_ALLY | DialogConditionEnum::DC_IS_ALLY |
| DC_IS_ENEMY | DialogConditionEnum::DC_IS_ENEMY |
| DC_PERSONALITY_TAG | DialogConditionEnum::DC_PERSONALITY_TAG |
| DC_BROKEN_LEG | DialogConditionEnum::DC_BROKEN_LEG |
| DC_BROKEN_ARM | DialogConditionEnum::DC_BROKEN_ARM |
| DC_DAMAGED_HEAD | DialogConditionEnum::DC_DAMAGED_HEAD |
| DC_NEARLY_KO | DialogConditionEnum::DC_NEARLY_KO |
| DC_IN_A_NON_PLAYER_TOWN | DialogConditionEnum::DC_IN_A_NON_PLAYER_TOWN |
| DC_IS_RUNNING | DialogConditionEnum::DC_IS_RUNNING |
| DC_COPS_AROUND | DialogConditionEnum::DC_COPS_AROUND |
| DC_SQUAD_SIZE | DialogConditionEnum::DC_SQUAD_SIZE |
| DC_IS_PLAYER | DialogConditionEnum::DC_IS_PLAYER |
| DC_NUM_BACKPACKS | DialogConditionEnum::DC_NUM_BACKPACKS |
| DC_SQUAD_ONLY_ANIMALS | DialogConditionEnum::DC_SQUAD_ONLY_ANIMALS |
| DC_IS_OUTNUMBERED | DialogConditionEnum::DC_IS_OUTNUMBERED |
| DC_BOUNTY_AMOUNT_PERCEIVED | DialogConditionEnum::DC_BOUNTY_AMOUNT_PERCEIVED |
| DC_IS_KO | DialogConditionEnum::DC_IS_KO |
| DC_IS_NEARLY_KO | DialogConditionEnum::DC_IS_NEARLY_KO |
| DC_SQUAD_IS_DOWN | DialogConditionEnum::DC_SQUAD_IS_DOWN |
| DC_IS_DEAD | DialogConditionEnum::DC_IS_DEAD |
| DC_IS_FEMALE | DialogConditionEnum::DC_IS_FEMALE |
| DC_CARRYING_SOMEONE_TO_ENSLAVE | DialogConditionEnum::DC_CARRYING_SOMEONE_TO_ENSLAVE |
| DC_BOUNTY_AMOUNT_ACTUAL | DialogConditionEnum::DC_BOUNTY_AMOUNT_ACTUAL |
| DC_IM_UNARMED | DialogConditionEnum::DC_IM_UNARMED |
| DC_TOWN_HAS_FORTIFICATIONS_WALLS | DialogConditionEnum::DC_TOWN_HAS_FORTIFICATIONS_WALLS |
| DC_TARGET_IS_MY_MISSION_TARGET | DialogConditionEnum::DC_TARGET_IS_MY_MISSION_TARGET |
| DC_MY_MISSION_IS_FRIENDLY | DialogConditionEnum::DC_MY_MISSION_IS_FRIENDLY |
| DC_I_LOVE_THIS_GUY | DialogConditionEnum::DC_I_LOVE_THIS_GUY |
| DC_I_HATE_THIS_GUY | DialogConditionEnum::DC_I_HATE_THIS_GUY |
| DC_I_SHOULD_SCREW_THIS_GUY_OVER | DialogConditionEnum::DC_I_SHOULD_SCREW_THIS_GUY_OVER |
| DC_I_SHOULD_HELP_THIS_GUY | DialogConditionEnum::DC_I_SHOULD_HELP_THIS_GUY |
| DC_IN_COMBAT | DialogConditionEnum::DC_IN_COMBAT |
| DC_WITHIN_TOWN_WALLS | DialogConditionEnum::DC_WITHIN_TOWN_WALLS |
| DC_TOWN_WALLS_LOCKED_UP | DialogConditionEnum::DC_TOWN_WALLS_LOCKED_UP |
| DC_IS_SLAVE | DialogConditionEnum::DC_IS_SLAVE |
| DC_HAS_A_BASE_NEARBY | DialogConditionEnum::DC_HAS_A_BASE_NEARBY |
| DC_TARGET_IS_SLAVE_OF_MY_FACTION | DialogConditionEnum::DC_TARGET_IS_SLAVE_OF_MY_FACTION |
| DC_IS_ESCAPED_SLAVE | DialogConditionEnum::DC_IS_ESCAPED_SLAVE |
| DC_IS_IN_LOCKED_CAGE | DialogConditionEnum::DC_IS_IN_LOCKED_CAGE |
| DC_WEARING_LOCKED_SHACKLES | DialogConditionEnum::DC_WEARING_LOCKED_SHACKLES |
| DC_IS_SAME_RACE_AS_ME | DialogConditionEnum::DC_IS_SAME_RACE_AS_ME |
| DC_CAN_AFFORD_BOUNTY | DialogConditionEnum::DC_CAN_AFFORD_BOUNTY |
| DC_IS_SNEAKING | DialogConditionEnum::DC_IS_SNEAKING |
| DC_IS_INDOORS | DialogConditionEnum::DC_IS_INDOORS |
| DC_HAS_ILLEGAL_ITEM | DialogConditionEnum::DC_HAS_ILLEGAL_ITEM |
| DC_USING_MY_TRAINING_EQUIPMENT | DialogConditionEnum::DC_USING_MY_TRAINING_EQUIPMENT |
| DC_STARVING | DialogConditionEnum::DC_STARVING |
| DC_MIXED_GENDER_GROUP | DialogConditionEnum::DC_MIXED_GENDER_GROUP |
| DC_TOWN_LEVEL_CURRENT_LOCATION | DialogConditionEnum::DC_TOWN_LEVEL_CURRENT_LOCATION |
| DC_PLAYERS_BEST_TOWN_LEVEL | DialogConditionEnum::DC_PLAYERS_BEST_TOWN_LEVEL |
| DC_IN_A_PLAYER_TOWN | DialogConditionEnum::DC_IN_A_PLAYER_TOWN |
| DC_TARGET_CHARACTER_EXISTS | DialogConditionEnum::DC_TARGET_CHARACTER_EXISTS |
| DC_IS_RECRUITABLE | DialogConditionEnum::DC_IS_RECRUITABLE |
| DC_HAS_AI_CONTRACT | DialogConditionEnum::DC_HAS_AI_CONTRACT |
| DC_HAS_ROBOT_LIMBS | DialogConditionEnum::DC_HAS_ROBOT_LIMBS |
| DC_END | DialogConditionEnum::DC_END |
#### or
| NONE | DialogConditionEnum::DC_NONE |
| RELATIONS | DialogConditionEnum::DC_RELATIONS |
| PLAYERMONEY | DialogConditionEnum::DC_PLAYERMONEY |
| REPUTATION | DialogConditionEnum::DC_REPUTATION |
| CARRYING_BOUNTY_ALIVE | DialogConditionEnum::DC_CARRYING_BOUNTY_ALIVE |
| CARRYING_BOUNTY_DEAD | DialogConditionEnum::DC_CARRYING_BOUNTY_DEAD |
| FACTION_VARIABLE | DialogConditionEnum::DC_FACTION_VARIABLE |
| IMPRISONED_BY_TARGET | DialogConditionEnum::DC_IMPRISONED_BY_TARGET |
| IMPRISONED_BY_OTHER | DialogConditionEnum::DC_IMPRISONED_BY_OTHER |
| IS_A_TRADER | DialogConditionEnum::DC_IS_A_TRADER |
| FACTION_RANK | DialogConditionEnum::DC_FACTION_RANK |
| BUILDING_IS_CLOSED_AND_SECURED | DialogConditionEnum::DC_BUILDING_IS_CLOSED_AND_SECURED |
| PLAYER_TECH_LEVEL | DialogConditionEnum::DC_PLAYER_TECH_LEVEL |
| NUM_DIALOG_EVENT_REPEATS | DialogConditionEnum::DC_NUM_DIALOG_EVENT_REPEATS |
| IS_IMPRISONED | DialogConditionEnum::DC_IS_IMPRISONED |
| IMPRISONMENT_IS_DEATHROW | DialogConditionEnum::DC_IMPRISONMENT_IS_DEATHROW |
| TARGET_IN_TALKING_RANGE | DialogConditionEnum::DC_TARGET_IN_TALKING_RANGE |
| IN_MY_BUILDING | DialogConditionEnum::DC_IN_MY_BUILDING |
| TARGET_LAST_SEEN_X_HOURS_AGO | DialogConditionEnum::DC_TARGET_LAST_SEEN_X_HOURS_AGO |
| IS_LEADER | DialogConditionEnum::DC_IS_LEADER |
| MET_TARGET_BEFORE | DialogConditionEnum::DC_MET_TARGET_BEFORE |
| WEAKER_THAN_ME | DialogConditionEnum::DC_WEAKER_THAN_ME |
| STRONGER_THAN_ME | DialogConditionEnum::DC_STRONGER_THAN_ME |
| HAS_TAG | DialogConditionEnum::DC_HAS_TAG |
| IS_ALLY | DialogConditionEnum::DC_IS_ALLY |
| IS_ENEMY | DialogConditionEnum::DC_IS_ENEMY |
| PERSONALITY_TAG | DialogConditionEnum::DC_PERSONALITY_TAG |
| BROKEN_LEG | DialogConditionEnum::DC_BROKEN_LEG |
| BROKEN_ARM | DialogConditionEnum::DC_BROKEN_ARM |
| DAMAGED_HEAD | DialogConditionEnum::DC_DAMAGED_HEAD |
| NEARLY_KO | DialogConditionEnum::DC_NEARLY_KO |
| IN_A_NON_PLAYER_TOWN | DialogConditionEnum::DC_IN_A_NON_PLAYER_TOWN |
| IS_RUNNING | DialogConditionEnum::DC_IS_RUNNING |
| COPS_AROUND | DialogConditionEnum::DC_COPS_AROUND |
| SQUAD_SIZE | DialogConditionEnum::DC_SQUAD_SIZE |
| IS_PLAYER | DialogConditionEnum::DC_IS_PLAYER |
| NUM_BACKPACKS | DialogConditionEnum::DC_NUM_BACKPACKS |
| SQUAD_ONLY_ANIMALS | DialogConditionEnum::DC_SQUAD_ONLY_ANIMALS |
| IS_OUTNUMBERED | DialogConditionEnum::DC_IS_OUTNUMBERED |
| BOUNTY_AMOUNT_PERCEIVED | DialogConditionEnum::DC_BOUNTY_AMOUNT_PERCEIVED |
| IS_KO | DialogConditionEnum::DC_IS_KO |
| IS_NEARLY_KO | DialogConditionEnum::DC_IS_NEARLY_KO |
| SQUAD_IS_DOWN | DialogConditionEnum::DC_SQUAD_IS_DOWN |
| IS_DEAD | DialogConditionEnum::DC_IS_DEAD |
| IS_FEMALE | DialogConditionEnum::DC_IS_FEMALE |
| CARRYING_SOMEONE_TO_ENSLAVE | DialogConditionEnum::DC_CARRYING_SOMEONE_TO_ENSLAVE |
| BOUNTY_AMOUNT_ACTUAL | DialogConditionEnum::DC_BOUNTY_AMOUNT_ACTUAL |
| IM_UNARMED | DialogConditionEnum::DC_IM_UNARMED |
| TOWN_HAS_FORTIFICATIONS_WALLS | DialogConditionEnum::DC_TOWN_HAS_FORTIFICATIONS_WALLS |
| TARGET_IS_MY_MISSION_TARGET | DialogConditionEnum::DC_TARGET_IS_MY_MISSION_TARGET |
| MY_MISSION_IS_FRIENDLY | DialogConditionEnum::DC_MY_MISSION_IS_FRIENDLY |
| I_LOVE_THIS_GUY | DialogConditionEnum::DC_I_LOVE_THIS_GUY |
| I_HATE_THIS_GUY | DialogConditionEnum::DC_I_HATE_THIS_GUY |
| I_SHOULD_SCREW_THIS_GUY_OVER | DialogConditionEnum::DC_I_SHOULD_SCREW_THIS_GUY_OVER |
| I_SHOULD_HELP_THIS_GUY | DialogConditionEnum::DC_I_SHOULD_HELP_THIS_GUY |
| IN_COMBAT | DialogConditionEnum::DC_IN_COMBAT |
| WITHIN_TOWN_WALLS | DialogConditionEnum::DC_WITHIN_TOWN_WALLS |
| TOWN_WALLS_LOCKED_UP | DialogConditionEnum::DC_TOWN_WALLS_LOCKED_UP |
| IS_SLAVE | DialogConditionEnum::DC_IS_SLAVE |
| HAS_A_BASE_NEARBY | DialogConditionEnum::DC_HAS_A_BASE_NEARBY |
| TARGET_IS_SLAVE_OF_MY_FACTION | DialogConditionEnum::DC_TARGET_IS_SLAVE_OF_MY_FACTION |
| IS_ESCAPED_SLAVE | DialogConditionEnum::DC_IS_ESCAPED_SLAVE |
| IS_IN_LOCKED_CAGE | DialogConditionEnum::DC_IS_IN_LOCKED_CAGE |
| WEARING_LOCKED_SHACKLES | DialogConditionEnum::DC_WEARING_LOCKED_SHACKLES |
| IS_SAME_RACE_AS_ME | DialogConditionEnum::DC_IS_SAME_RACE_AS_ME |
| CAN_AFFORD_BOUNTY | DialogConditionEnum::DC_CAN_AFFORD_BOUNTY |
| IS_SNEAKING | DialogConditionEnum::DC_IS_SNEAKING |
| IS_INDOORS | DialogConditionEnum::DC_IS_INDOORS |
| HAS_ILLEGAL_ITEM | DialogConditionEnum::DC_HAS_ILLEGAL_ITEM |
| USING_MY_TRAINING_EQUIPMENT | DialogConditionEnum::DC_USING_MY_TRAINING_EQUIPMENT |
| STARVING | DialogConditionEnum::DC_STARVING |
| MIXED_GENDER_GROUP | DialogConditionEnum::DC_MIXED_GENDER_GROUP |
| TOWN_LEVEL_CURRENT_LOCATION | DialogConditionEnum::DC_TOWN_LEVEL_CURRENT_LOCATION |
| PLAYERS_BEST_TOWN_LEVEL | DialogConditionEnum::DC_PLAYERS_BEST_TOWN_LEVEL |
| IN_A_PLAYER_TOWN | DialogConditionEnum::DC_IN_A_PLAYER_TOWN |
| TARGET_CHARACTER_EXISTS | DialogConditionEnum::DC_TARGET_CHARACTER_EXISTS |
| IS_RECRUITABLE | DialogConditionEnum::DC_IS_RECRUITABLE |
| HAS_AI_CONTRACT | DialogConditionEnum::DC_HAS_AI_CONTRACT |
| HAS_ROBOT_LIMBS | DialogConditionEnum::DC_HAS_ROBOT_LIMBS |
| END | DialogConditionEnum::DC_END |

### ComparisonEnum
| Name | Value |
|---|---|
| CE_EQUALS | ComparisonEnum::CE_EQUALS |
| CE_LESS_THAN | ComparisonEnum::CE_LESS_THAN |
| CE_MORE_THAN | ComparisonEnum::CE_MORE_THAN |
#### or
| EQUALS | ComparisonEnum::CE_EQUALS |
| LESS_THAN | ComparisonEnum::CE_LESS_THAN |
| MORE_THAN | ComparisonEnum::CE_MORE_THAN |

### GroundType
| Name | Value |
|---|---|
| GROUND_SAND | GroundType::GROUND_SAND |
| GROUND_GRASS | GroundType::GROUND_GRASS |
| GROUND_CONCRETE | GroundType::GROUND_CONCRETE |
| GROUND_WOOD | GroundType::GROUND_WOOD |
| GROUND_METAL | GroundType::GROUND_METAL |
| GROUND_WATER | GroundType::GROUND_WATER |
| GROUND_MUD | GroundType::GROUND_MUD |
| GROUND_SNOW | GroundType::GROUND_SNOW |
| GROUND_DIRT | GroundType::GROUND_DIRT |
#### or
| SAND | GroundType::GROUND_SAND |
| GRASS | GroundType::GROUND_GRASS |
| CONCRETE | GroundType::GROUND_CONCRETE |
| WOOD | GroundType::GROUND_WOOD |
| METAL | GroundType::GROUND_METAL |
| WATER | GroundType::GROUND_WATER |
| MUD | GroundType::GROUND_MUD |
| SNOW | GroundType::GROUND_SNOW |
| DIRT | GroundType::GROUND_DIRT |

### EffectType
| Name | Value |
|---|---|
| NONE | EffectType::Enum::NONE |
| CAMERA | EffectType::Enum::CAMERA |
| POINT | EffectType::Enum::POINT |
| WANDERING | EffectType::Enum::WANDERING |
| GLOBAL | EffectType::Enum::GLOBAL |
| CAMERA_RAIN | EffectType::Enum::CAMERA_RAIN |
| CAMERA_ACID_RAIN | EffectType::Enum::CAMERA_ACID_RAIN |
| POINT_LIGHTING | EffectType::Enum::POINT_LIGHTING |
| WANDERING_STORM | EffectType::Enum::WANDERING_STORM |
| WANDERING_GAS | EffectType::Enum::WANDERING_GAS |
| GLOBAL_POINT | EffectType::Enum::GLOBAL_POINT |

### SquadType
| Name | Value |
|---|---|
| SQ_UNKNOWN | SquadType::SQ_UNKNOWN |
| SQ_RESIDENT | SquadType::SQ_RESIDENT |
| SQ_ROAMING | SquadType::SQ_ROAMING |

### MoveSpeed
| Name | Value |
|---|---|
| WALK | MoveSpeed::WALK |
| JOG | MoveSpeed::JOG |
| RUN | MoveSpeed::RUN |
| GROUPED | MoveSpeed::GROUPED |
| NO_SPEED_CHANGE | MoveSpeed::NO_SPEED_CHANGE |

### SwordStateEnum
| Name | Value |
|---|---|
| CHOP_WEAPON | swordStateEnum::CHOP_WEAPON |
| BLOCK | swordStateEnum::BLOCK |
| REACTION_BLOCK | swordStateEnum::REACTION_BLOCK |
| STARTUP_STATE | swordStateEnum::STARTUP_STATE |
| DECISION | swordStateEnum::DECISION |
| CIRCLE_MENACINGLY | swordStateEnum::CIRCLE_MENACINGLY |
| WAIT_MENACINGLY | swordStateEnum::WAIT_MENACINGLY |
| HESITATE | swordStateEnum::HESITATE |
| STUMBLE | swordStateEnum::STUMBLE |
| COMBAT_FINISHED | swordStateEnum::COMBAT_FINISHED |
| TARGET_PATHFINDING_STARTUP | swordStateEnum::TARGET_PATHFINDING_STARTUP |
| TARGET_PATHFINDING | swordStateEnum::TARGET_PATHFINDING |

### MiningResource
| Name | Value |
|---|---|
| NONE | MiningResource::NONE |
| IRON | MiningResource::IRON |
| STONE | MiningResource::STONE |
| COPPER | MiningResource::COPPER |
| CARBON | MiningResource::CARBON |
| WATER | MiningResource::WATER |
| GROUND | MiningResource::GROUND |

### CursorType
| Name | Value |
|---|---|
| DEFAULT_CURSOR | CursorType::DEFAULT_CURSOR |
| MEDIC_CURSOR | CursorType::MEDIC_CURSOR |
| LOOT_CURSOR | CursorType::LOOT_CURSOR |
| LIFT_CURSOR | CursorType::LIFT_CURSOR |
| PICKUP_ITEM_CURSOR | CursorType::PICKUP_ITEM_CURSOR |
| ATTACK_CURSOR | CursorType::ATTACK_CURSOR |
| GUARD_CURSOR | CursorType::GUARD_CURSOR |
| TALK_CURSOR | CursorType::TALK_CURSOR |
| SPECIAL_TALK_CURSOR | CursorType::SPECIAL_TALK_CURSOR |
| USE_CURSOR | CursorType::USE_CURSOR |
| TRADER_CURSOR | CursorType::TRADER_CURSOR |
| BUILD_CURSOR | CursorType::BUILD_CURSOR |
| OPEN_DOOR_CURSOR | CursorType::OPEN_DOOR_CURSOR |
| DOOR_ESCAPE_CURSOR | CursorType::DOOR_ESCAPE_CURSOR |
| LOCKED_CURSOR | CursorType::LOCKED_CURSOR |
| PICK_LOCK_CURSOR | CursorType::PICK_LOCK_CURSOR |
| BUY_HOUSE_CURSOR | CursorType::BUY_HOUSE_CURSOR |
| GREEN_CURSOR | CursorType::GREEN_CURSOR |
| MINE_CURSOR | CursorType::MINE_CURSOR |
| REPAIR_CURSOR | CursorType::REPAIR_CURSOR |
| LIGHT_CURSOR | CursorType::LIGHT_CURSOR |
| STEAL_CURSOR | CursorType::STEAL_CURSOR |
| HAND_CURSOR | CursorType::HAND_CURSOR |
| INVALID_MOVEMENT_CURSOR | CursorType::INVALID_MOVEMENT_CURSOR |
| LOOT_CURSOR_RED | CursorType::LOOT_CURSOR_RED |
| KNOCKOUT_CURSOR | CursorType::KNOCKOUT_CURSOR |

### MapZoomLevel
| Name | Value |
|---|---|
| ZOOM_MIN | MapZoomLevel::ZOOM_MIN |
| ZOOM_MID | MapZoomLevel::ZOOM_MID |
| ZOOM_MAX | MapZoomLevel::ZOOM_MAX |
| ZOOM_CHARACTERS | MapZoomLevel::ZOOM_CHARACTERS |
#### or
| MIN | MapZoomLevel::ZOOM_MIN |
| MID | MapZoomLevel::ZOOM_MID |
| MAX | MapZoomLevel::ZOOM_MAX |
| CHARACTERS | MapZoomLevel::ZOOM_CHARACTERS |