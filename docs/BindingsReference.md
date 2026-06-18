# Lua Bindings Reference

## Table of Contents
- [Bounty](#bounty)
- [BountyManager](#bountymanager)
- [Building](#building)
- [CameraClass](#cameraclass)
- [CharStats](#charstats)
- [Character](#character)
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
- [InventorySection](#inventorysection)
- [Item](#item)
- [MedicalSystem](#medicalsystem)
- [Platoon](#platoon)
- [PlayerInterface](#playerinterface)
- [RaceData](#racedata)
- [RootObject](#rootobject)
- [SectionItem](#sectionitem)
- [Town](#town)

## Bounty
**Header:** `extern/kenshilib-030/Include/kenshi/Bounty.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| amount | amount | integer | R | `obj.amount` |
| crimes | crimes | integer | R | `obj.crimes` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| addCrime | addCrime | `obj:addCrime(...)` |
| hasCrime | hasCrime | `obj:hasCrime(...)` |

## BountyManager
**Header:** `extern/kenshilib-030/Include/kenshi/BountyManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isCommittingCrime | isCommittingCrime() | boolean | R | `obj.isCommittingCrime` |
| crimeExpiry | crimeExpiry | number | R | `obj.crimeExpiry` |
| prisonSentenceToServe | prisonSentenceToServe | number | R | `obj.prisonSentenceToServe` |
| committingCrime | committingCrime | integer | R | `obj.committingCrime` |
| totalBounty | getTotalBounty() | integer | R | `obj.totalBounty` |
| accessPassExpirationTime | accessPassExpirationTime.time | number | R | `obj.accessPassExpirationTime` |
| prisonSentenceBeganTime | prisonSentenceBeganTime.time | number | R | `obj.prisonSentenceBeganTime` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| justBeenUpgraded | justBeenUpgradedFlag | boolean | R | `obj.justBeenUpgraded` |
| isOutsideFurniture | isOutsideFurniture | boolean | R | `obj.isOutsideFurniture` |
| lightsVisible | lightsVisible | boolean | R | `obj.lightsVisible` |
| heightAboveGround | heightAboveGround | number | R | `obj.heightAboveGround` |
| designation | designation | integer | R | `obj.designation` |
| materialName | materialName | string | R | `obj.materialName` |
| isFurnitureOf | isFurnitureOf | lightuserdata | R | `obj.isFurnitureOf` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/CameraClass.h`

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

## CharStats
**Header:** `extern/kenshilib-030/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| athleticsMultiplier | athleticsMultiplier | number | R | `obj.athleticsMultiplier` |
| combatSpeedMultiplier | combatSpeedMultiplier | number | R | `obj.combatSpeedMultiplier` |
| _skillBonusAttack | _skillBonusAttack | integer | R | `obj._skillBonusAttack` |
| _skillBonusDefence | _skillBonusDefence | integer | R | `obj._skillBonusDefence` |
| skillBonusIndoors | skillBonusIndoors | integer | R | `obj.skillBonusIndoors` |
| skillBonusUnarmed | skillBonusUnarmed | integer | R | `obj.skillBonusUnarmed` |
| skillBonusPerception | skillBonusPerception | integer | R | `obj.skillBonusPerception` |
| ageMult | ageMult | number | R | `obj.ageMult` |
| skillMultDodge | skillMultDodge | number | R | `obj.skillMultDodge` |
| skillMultStealth | skillMultStealth | number | R | `obj.skillMultStealth` |
| skillMultAssassin | skillMultAssassin | number | R | `obj.skillMultAssassin` |
| skillMultDexterity | skillMultDexterity | number | R | `obj.skillMultDexterity` |
| skillMultDamage | skillMultDamage | number | R | `obj.skillMultDamage` |
| fistInjuryEquipmentMult | fistInjuryEquipmentMult | number | R | `obj.fistInjuryEquipmentMult` |
| skillMultRanged | skillMultRanged | number | R | `obj.skillMultRanged` |
| _strength | _strength | number | R | `obj._strength` |
| fitness | fitness | number | R | `obj.fitness` |
| _dexterity | _dexterity | number | R | `obj._dexterity` |
| perception | perception | number | R | `obj.perception` |
| _toughness | _toughness | number | R | `obj._toughness` |
| _athletics | _athletics | number | R | `obj._athletics` |
| medic | medic | number | R | `obj.medic` |
| massCombat | massCombat | number | R | `obj.massCombat` |
| arrowDefence | arrowDefence | number | R | `obj.arrowDefence` |
| stealth | stealth | number | R | `obj.stealth` |
| swimming | swimming | number | R | `obj.swimming` |
| thieving | thieving | number | R | `obj.thieving` |
| lockpicking | lockpicking | number | R | `obj.lockpicking` |
| bluff | bluff | number | R | `obj.bluff` |
| assassin | assassin | number | R | `obj.assassin` |
| survival | survival | number | R | `obj.survival` |
| tracking | tracking | number | R | `obj.tracking` |
| climbing | climbing | number | R | `obj.climbing` |
| doctor | doctor | number | R | `obj.doctor` |
| engineer | engineer | number | R | `obj.engineer` |
| weaponSmith | weaponSmith | number | R | `obj.weaponSmith` |
| armourSmith | armourSmith | number | R | `obj.armourSmith` |
| bowSmith | bowSmith | number | R | `obj.bowSmith` |
| robotics | robotics | number | R | `obj.robotics` |
| science | science | number | R | `obj.science` |
| labouring | labouring | number | R | `obj.labouring` |
| farming | farming | number | R | `obj.farming` |
| cooking | cooking | number | R | `obj.cooking` |
| dodging | dodging | number | R | `obj.dodging` |
| friendlyFire | friendlyFire | number | R | `obj.friendlyFire` |
| katanas | katanas | number | R | `obj.katanas` |
| sabres | sabres | number | R | `obj.sabres` |
| hackers | hackers | number | R | `obj.hackers` |
| blunt | blunt | number | R | `obj.blunt` |
| heavyWeapons | heavyWeapons | number | R | `obj.heavyWeapons` |
| unarmed | unarmed | number | R | `obj.unarmed` |
| bows | bows | number | R | `obj.bows` |
| turrets | turrets | number | R | `obj.turrets` |
| polearms | polearms | number | R | `obj.polearms` |
| currentItemMaximumJuryRig | currentItemMaximumJuryRig | number | R | `obj.currentItemMaximumJuryRig` |
| __meleeAttack | __meleeAttack | number | R | `obj.__meleeAttack` |
| _meleeDefence | _meleeDefence | number | R | `obj._meleeDefence` |
| warriorSpirit | warriorSpirit | number | R | `obj.warriorSpirit` |
| derivedSpirit | derivedSpirit | number | R | `obj.derivedSpirit` |
| aggression | aggression | number | R | `obj.aggression` |
| goodness | goodness | number | R | `obj.goodness` |
| evilness | evilness | number | R | `obj.evilness` |
| longestReachingAttack | longestReachingAttack | number | R | `obj.longestReachingAttack` |
| STUBBOURNESS | STUBBOURNESS | number | R | `obj.STUBBOURNESS` |
| PROFESSIONALNESS | PROFESSIONALNESS | number | R | `obj.PROFESSIONALNESS` |
| HOLDING_POSITION | HOLDING_POSITION | number | R | `obj.HOLDING_POSITION` |
| IMMEDIACY | IMMEDIACY | number | R | `obj.IMMEDIACY` |
| IMMEDIACY_MAX_RANGE | IMMEDIACY_MAX_RANGE | number | R | `obj.IMMEDIACY_MAX_RANGE` |
| MANLINESS | MANLINESS | number | R | `obj.MANLINESS` |
| MURDEROUS | MURDEROUS | number | R | `obj.MURDEROUS` |
| _stealthXPMultForGUI | _stealthXPMultForGUI | number | R | `obj._stealthXPMultForGUI` |
| stealthXPTooManyCooksPenalty | stealthXPTooManyCooksPenalty | number | R | `obj.stealthXPTooManyCooksPenalty` |
| currentOperatingMachineHungerRate | currentOperatingMachineHungerRate | number | R | `obj.currentOperatingMachineHungerRate` |
| moveSpeed | moveSpeed | number | R | `obj.moveSpeed` |
| weaponWeightSpeedMult | weaponWeightSpeedMult | number | R | `obj.weaponWeightSpeedMult` |
| weaponWeightXPMult | weaponWeightXPMult | number | R | `obj.weaponWeightXPMult` |
| attackSpeed | attackSpeed | number | R | `obj.attackSpeed` |
| blockSpeed | blockSpeed | number | R | `obj.blockSpeed` |
| encumbranceMult | encumbranceMult | number | R | `obj.encumbranceMult` |
| xp | xp | number | R | `obj.xp` |
| cutDamageMult | cutDamageMult | number | R | `obj.cutDamageMult` |
| bluntDamageMult | bluntDamageMult | number | R | `obj.bluntDamageMult` |
| bleedDamageMult | bleedDamageMult | number | R | `obj.bleedDamageMult` |
| pierceDamageMult | pierceDamageMult | number | R | `obj.pierceDamageMult` |
| cutDamageMin | cutDamageMin | number | R | `obj.cutDamageMin` |
| bluntDamageMin | bluntDamageMin | number | R | `obj.bluntDamageMin` |
| bonusRobots | bonusRobots | number | R | `obj.bonusRobots` |
| bonusHumans | bonusHumans | number | R | `obj.bonusHumans` |
| bonusAnimals | bonusAnimals | number | R | `obj.bonusAnimals` |
| bonusArmourPenetration | bonusArmourPenetration | number | R | `obj.bonusArmourPenetration` |
| currentWeaponLength | currentWeaponLength | number | R | `obj.currentWeaponLength` |
| weaponWeight | weaponWeight | number | R | `obj.weaponWeight` |
| _defensiveMode | _defensiveMode | boolean | R | `obj._defensiveMode` |
| rangedMode | rangedMode | boolean | R | `obj.rangedMode` |
| tauntMode | tauntMode | boolean | R | `obj.tauntMode` |
| _holdPositionMode | _holdPositionMode | boolean | R | `obj._holdPositionMode` |
| passiveCombatMode | passiveCombatMode | boolean | R | `obj.passiveCombatMode` |
| freeAttributePoints | freeAttributePoints | integer | R | `obj.freeAttributePoints` |
| currentWeaponType | currentWeaponType | integer | R | `obj.currentWeaponType` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/Appearance.h`

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

## Damages
**Header:** `extern/kenshilib-030/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| cut | cut | number | R | `obj.cut` |
| blunt | blunt | number | R | `obj.blunt` |
| pierce | pierce | number | R | `obj.pierce` |
| extraStun | extraStun | number | R | `obj.extraStun` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| new | createNew | `obj:new(...)` |
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
**Header:** `extern/kenshilib-030/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| shouting | shouting | boolean | R | `obj.shouting` |
| staysOnScreen | staysOnScreen | boolean | R | `obj.staysOnScreen` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/AppearanceManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isThePlayer | isThePlayer() | boolean | R | `obj.isThePlayer` |
| isAntiSlavery | isAntiSlavery() | boolean | R | `obj.isAntiSlavery` |
| isALawEnforcementFaction | isALawEnforcementFaction | boolean | R | `obj.isALawEnforcementFaction` |
| prosperityMultiplier | getProsperityMultiplier() | number | R | `obj.prosperityMultiplier` |
| roadPreference | getRoadPreference() | number | R | `obj.roadPreference` |
| factionSize | getFactionSize() | integer | R | `obj.factionSize` |
| name | name | string | R | `obj.name` |
| allowSlavesWeapons | allowSlavesWeapons | boolean | R | `obj.allowSlavesWeapons` |
| diplomatTimeStamp | diplomatTimeStamp | integer | R | `obj.diplomatTimeStamp` |
| fundamentalNPCType | fundamentalNPCType | integer | R | `obj.fundamentalNPCType` |
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
**Header:** `extern/kenshilib-030/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | visible | boolean | R | `obj.visible` |
| category | category | string | R | `obj.category` |
| description | description | string | R | `obj.description` |
| fileTypes | fileTypes | string | R | `obj.fileTypes` |
| maxSize | maxSize | integer | R | `obj.maxSize` |
| maxValue | maxValue | integer | R | `obj.maxValue` |
| minValue | minValue | integer | R | `obj.minValue` |
| isSlider | isSlider | boolean | R | `obj.isSlider` |
| refID | refID | string | R | `obj.refID` |
| created | created | integer | R | `obj.created` |
| modified | modified | integer | R | `obj.modified` |
| validity | validity | integer | R | `obj.validity` |
| isStandalone | isStandalone | boolean | R | `obj.isStandalone` |
| id | id | integer | R | `obj.id` |
| readOnly | readOnly | boolean | R | `obj.readOnly` |
| name | name | string | R | `obj.name` |
| stringID | stringID | string | R | `obj.stringID` |
| isFromActiveFile | isFromActiveFile | boolean | R | `obj.isFromActiveFile` |
| currentID | currentID | integer | R | `obj.currentID` |
| createdIndex | createdIndex | integer | R | `obj.createdIndex` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/GameWorld.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isPaused | g->isPaused() | boolean | R | `obj.isPaused` |
| frameSpeedMultiplier | g->getFrameSpeedMultiplier() | number | R | `obj.frameSpeedMultiplier` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/Gear.h`

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
| isValid | isValid() | boolean | R | `obj.isValid` |
| isNull | isNull() | boolean | R | `obj.isNull` |
| type | type | integer | R | `obj.type` |
| index | index | integer | R | `obj.index` |
| serial | serial | integer | R | `obj.serial` |
| container | container | integer | R | `obj.container` |
| containerSerial | containerSerial | integer | R | `obj.containerSerial` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/Globals.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| ctrl | ctrl | boolean | R | `obj.ctrl` |
| shift | shift | boolean | R | `obj.shift` |
| alt | alt | boolean | R | `obj.alt` |
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
**Header:** `extern/kenshilib-030/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| hasRoomCache | (lua_Integer)hasRoomCache | integer | R | `obj.hasRoomCache` |
| totalWeight | totalWeight | number | R | `obj.totalWeight` |

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

## InventorySection
**Header:** `extern/kenshilib-030/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | name | string | R | `obj.name` |
| width | width | integer | R | `obj.width` |
| height | height | integer | R | `obj.height` |
| armourOnly | armourOnly | boolean | R | `obj.armourOnly` |
| stackingBonusMin | stackingBonusMin | integer | R | `obj.stackingBonusMin` |
| stackingBonusMult | stackingBonusMult | number | R | `obj.stackingBonusMult` |
| itemsLimit | itemsLimit | integer | R | `obj.itemsLimit` |
| weightMultiplier | weightMultiplier | number | R | `obj.weightMultiplier` |
| totalWeight | totalWeight | number | R | `obj.totalWeight` |
| isAnEquippedItemSection | isAnEquippedItemSection | boolean | R | `obj.isAnEquippedItemSection` |
| containerSlot | containerSlot | boolean | R | `obj.containerSlot` |
| enabled | enabled | boolean | R | `obj.enabled` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| _DESTRUCTOR | _DESTRUCTOR | `obj:_DESTRUCTOR(...)` |
| notifyModified | notifyModified | `obj:notifyModified(...)` |
| autoArrange | autoArrange | `obj:autoArrange(...)` |
| _NV_autoArrange | _NV_autoArrange | `obj:_NV_autoArrange(...)` |
| getNumItems | getNumItems | `obj:getNumItems(...)` |
| isEmpty | isEmpty | `obj:isEmpty(...)` |
| clearAllItems | clearAllItems | `obj:clearAllItems(...)` |
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
| getFillPercentage | getFillPercentage | `obj:getFillPercentage(...)` |
| resize | resize | `obj:resize(...)` |

## Item
**Header:** `extern/kenshilib-030/Include/kenshi/Appearance.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | getVisible() | boolean | R | `obj.visible` |
| isResearchArtifact | isResearchArtifact() | boolean | R | `obj.isResearchArtifact` |
| isEquipped | isEquipped | boolean | R | `obj.isEquipped` |
| onGround | onGround() | boolean | R | `obj.onGround` |
| isValid | isValid() | boolean | R | `obj.isValid` |
| isInInventory | isInInventory | boolean | R | `obj.isInInventory` |
| isTradeItem | isTradeItem | boolean | R | `obj.isTradeItem` |
| isUnique | isUnique | boolean | R | `obj.isUnique` |
| deathItem | deathItem | boolean | R | `obj.deathItem` |
| quality | quality | number | R | `obj.quality` |
| itemWeight | getItemWeight() | number | R | `obj.itemWeight` |
| itemWeightSingle | getItemWeightSingle() | number | R | `obj.itemWeightSingle` |
| originalFullChargeAmount | originalFullChargeAmount | number | R | `obj.originalFullChargeAmount` |
| chargesLeft | chargesLeft | number | R | `obj.chargesLeft` |
| athleticsMult | val | number | R | `obj.athleticsMult` |
| stealthMult | val | number | R | `obj.stealthMult` |
| combatSpeedMult | val | number | R | `obj.combatSpeedMult` |
| classType | getClassType() | integer | R | `obj.classType` |
| level | getLevel() | integer | R | `obj.level` |
| quantity | quantity | integer | R | `obj.quantity` |
| slotType | slotType | integer | R | `obj.slotType` |
| itemFunction | itemFunction | integer | R | `obj.itemFunction` |
| itemWidth | itemWidth | integer | R | `obj.itemWidth` |
| itemHeight | itemHeight | integer | R | `obj.itemHeight` |
| combatSkillBonus | val | integer | R | `obj.combatSkillBonus` |
| name | getName() | string | R | `obj.name` |
| modelName | getModelName() | string | R | `obj.modelName` |
| inventorySection | inventorySection | string | R | `obj.inventorySection` |
| inventory | inv | lightuserdata | R | `obj.inventory` |
| inventoryPos | inventoryPos.x | integer | R | `obj.inventoryPos` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getName | getName | `obj:getName(...)` |
| getPosition | getPosition | `obj:getPosition(...)` |
| getClassType | getClassType | `obj:getClassType(...)` |
| getVisible | getVisible | `obj:getVisible(...)` |
| getInventory | getInventory | `obj:getInventory(...)` |
| getLevel | getLevel | `obj:getLevel(...)` |
| getModelName | getModelName | `obj:getModelName(...)` |
| getItemWeight | getItemWeight | `obj:getItemWeight(...)` |
| getItemWeightSingle | getItemWeightSingle | `obj:getItemWeightSingle(...)` |
| getValueSingle | getValueSingle | `obj:getValueSingle(...)` |
| getValueAll | getValueAll | `obj:getValueAll(...)` |
| getQuality | getQuality | `obj:getQuality(...)` |
| getQuantity | getQuantity | `obj:getQuantity(...)` |
| getMaxAffordable | getMaxAffordable | `obj:getMaxAffordable(...)` |
| isStolen | isStolen | `obj:isStolen(...)` |
| isPersistant | isPersistant | `obj:isPersistant(...)` |
| isResearchArtifact | isResearchArtifact | `obj:isResearchArtifact(...)` |
| isEquipped | isEquipped | `obj:isEquipped(...)` |
| onGround | onGround | `obj:onGround(...)` |
| isValid | isValid | `obj:isValid(...)` |
| setVisible | setVisible | `obj:setVisible(...)` |
| setPositionRotation | setPositionRotation | `obj:setPositionRotation(...)` |
| setInventoryWeAreIn | setInventoryWeAreIn | `obj:setInventoryWeAreIn(...)` |
| setPersistant | setPersistant | `obj:setPersistant(...)` |
| stolenGoodsDetectionCheck | stolenGoodsDetectionCheck | `obj:stolenGoodsDetectionCheck(...)` |

## MedicalSystem
**Header:** `extern/kenshilib-030/Include/kenshi/CharStats.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| blood | blood | number | R | `obj.blood` |
| hunger | hunger | number | R | `obj.hunger` |
| fed | fed | number | R | `obj.fed` |
| extra_bloodloss_from_bodyparts | extraBloodLossFromBodyparts | number | R | `obj.extra_bloodloss_from_bodyparts` |
| current_bleed_rate | currentBleedRate | number | R | `obj.current_bleed_rate` |
| knockout_timer | knockoutTimer | number | R | `obj.knockout_timer` |
| worst_damage | worstDamage | number | R | `obj.worst_damage` |
| needs_firstaid_scoretotal_robot | needsFirstAidScoreTotal_robot | number | R | `obj.needs_firstaid_scoretotal_robot` |
| needs_firstaid_scoretotal_fleshy | needsFirstAidScoreTotal_fleshy | number | R | `obj.needs_firstaid_scoretotal_fleshy` |
| rested_state | restedState | number | R | `obj.rested_state` |
| stealth_hinderance | stealthHinderance | number | R | `obj.stealth_hinderance` |
| part_best_arm | partBestArm | number | R | `obj.part_best_arm` |
| part_head | partHead | number | R | `obj.part_head` |
| part_worst_torso | partWorstTorso | number | R | `obj.part_worst_torso` |
| dazed_or_alert | dazedOrAlert | number | R | `obj.dazed_or_alert` |
| current_weather_affect_strength | currentWeatherAffectStrength | number | R | `obj.current_weather_affect_strength` |
| next_KO_time | nextKOTime | number | R | `obj.next_KO_time` |
| extraBloodLossFromBodyparts | extraBloodLossFromBodyparts | number | R | `obj.extraBloodLossFromBodyparts` |
| currentBleedRate | currentBleedRate | number | R | `obj.currentBleedRate` |
| knockoutTimer | knockoutTimer | number | R | `obj.knockoutTimer` |
| worstDamage | worstDamage | number | R | `obj.worstDamage` |
| needsFirstAidScoreTotal_robot | needsFirstAidScoreTotal_robot | number | R | `obj.needsFirstAidScoreTotal_robot` |
| needsFirstAidScoreTotal_fleshy | needsFirstAidScoreTotal_fleshy | number | R | `obj.needsFirstAidScoreTotal_fleshy` |
| restedState | restedState | number | R | `obj.restedState` |
| stealthHinderance | stealthHinderance | number | R | `obj.stealthHinderance` |
| partBestArm | partBestArm | number | R | `obj.partBestArm` |
| partHead | partHead | number | R | `obj.partHead` |
| partWorstTorso | partWorstTorso | number | R | `obj.partWorstTorso` |
| dazedOrAlert | dazedOrAlert | number | R | `obj.dazedOrAlert` |
| currentWeatherAffectStrength | currentWeatherAffectStrength | number | R | `obj.currentWeatherAffectStrength` |
| nextKOTime | nextKOTime | number | R | `obj.nextKOTime` |
| eaten_death_delay | _eatenDeathDelay | integer | R | `obj.eaten_death_delay` |
| _eatenDeathDelay | _eatenDeathDelay | integer | R | `obj._eatenDeathDelay` |
| eatenDeathDelay | _eatenDeathDelay | integer | R | `obj.eatenDeathDelay` |
| is_bloodyness_changed | bloodynessChanged | boolean | R | `obj.is_bloodyness_changed` |
| is_bloodyness_cleaned_up | bloodynessCleanedUp | boolean | R | `obj.is_bloodyness_cleaned_up` |
| is_crippled | crippled | boolean | R | `obj.is_crippled` |
| is_unconcious | unconcious | boolean | R | `obj.is_unconcious` |
| is_sub50_KO | sub50KO | boolean | R | `obj.is_sub50_KO` |
| has_bloodloss_trauma | bloodlossTrauma | boolean | R | `obj.has_bloodloss_trauma` |
| is_dead | dead | boolean | R | `obj.is_dead` |
| is_right_arm_ok | rightArmOk | boolean | R | `obj.is_right_arm_ok` |
| is_left_arm_ok | leftArmOk | boolean | R | `obj.is_left_arm_ok` |
| bloodynessChanged | bloodynessChanged | boolean | R | `obj.bloodynessChanged` |
| bloodynessCleanedUp | bloodynessCleanedUp | boolean | R | `obj.bloodynessCleanedUp` |
| crippled | crippled | boolean | R | `obj.crippled` |
| unconcious | unconcious | boolean | R | `obj.unconcious` |
| sub50KO | sub50KO | boolean | R | `obj.sub50KO` |
| bloodlossTrauma | bloodlossTrauma | boolean | R | `obj.bloodlossTrauma` |
| dead | dead | boolean | R | `obj.dead` |
| rightArmOk | rightArmOk | boolean | R | `obj.rightArmOk` |
| leftArmOk | leftArmOk | boolean | R | `obj.leftArmOk` |

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

## Platoon
**Header:** `extern/kenshilib-030/Include/kenshi/Character.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| name | agetName() | string | R | `obj.name` |
| stringID | stringID | string | R | `obj.stringID` |
| squadSize | a agetSquadSize() | integer | R | `obj.squadSize` |
| characterCount | getCharacterCount() | integer | R | `obj.characterCount` |
| characterCountCurrent | _characterCountCurrent | integer | R | `obj.characterCountCurrent` |
| characterCountOriginal | _characterCountOriginal | integer | R | `obj.characterCountOriginal` |
| squadType | squadType | integer | R | `obj.squadType` |
| hasUniques | hasUniques | integer | R | `obj.hasUniques` |
| speedOverride | speedOverride | integer | R | `obj.speedOverride` |
| messageOnActivation | messageOnActivation | integer | R | `obj.messageOnActivation` |
| index | index | integer | R | `obj.index` |
| isValid | | boolean | R | `obj.isValid` |
| isLoaded | aisLoaded() | boolean | R | `obj.isLoaded` |
| isTrader | agetIsTrader() | boolean | R | `obj.isTrader` |
| canRefresh | canRefresh | boolean | R | `obj.canRefresh` |
| regenerates | regenerates | boolean | R | `obj.regenerates` |
| iBuyStolenGoods | _iBuyStolenGoods | boolean | R | `obj.iBuyStolenGoods` |
| iBuyIllegalGoods | _iBuyIllegalGoods | boolean | R | `obj.iBuyIllegalGoods` |
| isIntact | _isIntact | boolean | R | `obj.isIntact` |
| hasNeverBeenActivated | hasNeverBeenActivated | boolean | R | `obj.hasNeverBeenActivated` |
| isResidentSquad | isResidentSquad | boolean | R | `obj.isResidentSquad` |
| isDead | isDead | boolean | R | `obj.isDead` |
| imprisoned | imprisoned | boolean | R | `obj.imprisoned` |
| priceMultWhenITrade | priceMultWhenITrade | number | R | `obj.priceMultWhenITrade` |
| malnourishedLevel | malnourishedLevel | number | R | `obj.malnourishedLevel` |
| traderInventoryRefreshTime | traderInventoryRefreshTime.time | number | R | `obj.traderInventoryRefreshTime` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/Faction.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isBuildMode | isBuildMode() | boolean | R | `obj.isBuildMode` |
| characterEditorMode | characterEditorMode | boolean | R | `obj.characterEditorMode` |
| mouseRightTargetSet | mouseRightTargetSet | boolean | R | `obj.mouseRightTargetSet` |
| onlyAnimalsSelected | onlyAnimalsSelected | boolean | R | `obj.onlyAnimalsSelected` |
| currentFloor | currentFloor | integer | R | `obj.currentFloor` |
| currentMouseTask | currentMouseTask | integer | R | `obj.currentMouseTask` |
| mouseTaskTypeRestriction | mouseTaskTypeRestriction | integer | R | `obj.mouseTaskTypeRestriction` |
| rmouseTimer | rmouseTimer | number | R | `obj.rmouseTimer` |
| selectedLoadedLeft | selectedLoadedLeft | integer | R | `obj.selectedLoadedLeft` |
| trackedCharacterFloor | trackedCharacterFloor | integer | R | `obj.trackedCharacterFloor` |
| factionName | factionName | string | R | `obj.factionName` |
| technology | technology | lightuserdata | R | `obj.technology` |
| placementObject | placementObject | lightuserdata | R | `obj.placementObject` |

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
**Header:** `extern/kenshilib-030/Include/kenshi/RaceData.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| runSpeedMaxSkill | runSpeedMaxSkill | number | R | `obj.runSpeedMaxSkill` |
| runSpeedMinSkill | runSpeedMinSkill | number | R | `obj.runSpeedMinSkill` |
| originalBloodMin | originalBloodMin | number | R | `obj.originalBloodMin` |
| originalBloodMax | originalBloodMax | number | R | `obj.originalBloodMax` |
| healRate | healRate | number | R | `obj.healRate` |
| bleedRate | bleedRate | number | R | `obj.bleedRate` |
| swimSpeed | swimSpeed | number | R | `obj.swimSpeed` |
| walkSpeed | walkSpeed | number | R | `obj.walkSpeed` |
| hungerRate | hungerRate | number | R | `obj.hungerRate` |
| visionMultiplier | visionMultiplier | number | R | `obj.visionMultiplier` |
| extraAttackSlots | extraAttackSlots | integer | R | `obj.extraAttackSlots` |
| gigantic | gigantic | boolean | R | `obj.gigantic` |
| swims | swims | boolean | R | `obj.swims` |
| carriable | carriable | boolean | R | `obj.carriable` |
| singleGender | singleGender | boolean | R | `obj.singleGender` |
| robot | robot | boolean | R | `obj.robot` |
| vampiric | vampiric | boolean | R | `obj.vampiric` |
| noHats | noHats | boolean | R | `obj.noHats` |
| noShirts | noShirts | boolean | R | `obj.noShirts` |
| noShoes | noShoes | boolean | R | `obj.noShoes` |
| canGoIndoors | canGoIndoors | boolean | R | `obj.canGoIndoors` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| isRelatedRace | isRelatedRace | `obj:isRelatedRace(...)` |
| canEat | canEat | `obj:canEat(...)` |
| isImmune | isImmune | `obj:isImmune(...)` |

## RootObject
**Header:** `extern/kenshilib-030/Include/kenshi/CameraClass.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| visible | getVisible() | boolean | R | `obj.visible` |
| classType | getDataType() | integer | R | `obj.classType` |
| money | getMoney() | integer | R | `obj.money` |
| name | getName() | string | R | `obj.name` |
| modelName | itegetModelName() | string | R | `obj.modelName` |
| rotation | q.w | number | R | `obj.rotation` |
| inventory | inv | lightuserdata | R | `obj.inventory` |

### Methods
| Lua Name | C++ Method | Example |
|---|---|---|
| getName | getName() | `obj:getName(...)` |
| getPosition | getPosition() | `obj:getPosition(...)` |
| getRotation | getRotation() | `obj:getRotation(...)` |
| getVisible | getVisible() | `obj:getVisible(...)` |
| getModelName | getModelName() | `obj:getModelName(...)` |
| getMoney | getMoney() | `obj:getMoney(...)` |
| getTown | getTown() | `obj:getTown(...)` |
| getInventory | getInventory() | `obj:getInventory(...)` |
| setVisible | setVisible() | `obj:setVisible(...)` |
| takeMoney | takeMoney() | `obj:takeMoney(...)` |
| say | say() | `obj:say(...)` |

## SectionItem
**Header:** `extern/kenshilib-030/Include/kenshi/Inventory.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| x | x | integer | R | `obj.x` |
| y | y | integer | R | `obj.y` |
| w | w | integer | R | `obj.w` |
| h | h | integer | R | `obj.h` |

## Town
**Header:** `extern/kenshilib-030/Include/kenshi/FactionUniqueSquadManager.h`

### Fields
| Lua Name | C++ Member | Type | R/W | Example |
|---|---|---|---|---|
| isActive | isActive() | boolean | R | `obj.isActive` |
| isDead | isDead() | boolean | R | `obj.isDead` |
| isOutpost | isOutpost() | boolean | R | `obj.isOutpost` |
| isPublic | isPublic() | boolean | R | `obj.isPublic` |
| hasGates | hasGates() | boolean | R | `obj.hasGates` |
| isValid | isValid() | boolean | R | `obj.isValid` |
| isNotFriendly | isNotFriendly() | boolean | R | `obj.isNotFriendly` |
| alarmState | getAlarmState() | integer | R | `obj.alarmState` |
| townType | townType | integer | R | `obj.townType` |
| playerTownLevel | playerTownLevel | integer | R | `obj.playerTownLevel` |
| name | getKnownName() | string | R | `obj.name` |
| unexploredName | unexploredName | string | R | `obj.unexploredName` |
| discovered | discovered | boolean | R | `obj.discovered` |
| explored | explored | boolean | R | `obj.explored` |
| openToPublic | realTown && openToPublic | boolean | R | `obj.openToPublic` |
| power_Stat | power_Stat | number | R | `obj.power_Stat` |
| maxPower_Stat | maxPower_Stat | number | R | `obj.maxPower_Stat` |
| townRangeMultiplier | townRangeMultiplier | number | R | `obj.townRangeMultiplier` |

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

