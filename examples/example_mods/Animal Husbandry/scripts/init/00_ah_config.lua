-- Animal Husbandry: configuration.
--
-- Loaded first (scripts load in sorted path order). Every Animal Husbandry script
-- shares the global table _G.AnimalHusbandry, because each init script runs in its
-- own sandbox environment and plain assignments would stay private to one file.

local AH = _G.AnimalHusbandry or {}
_G.AnimalHusbandry = AH

AH.config = {
    -- Log extra detail to the KenshiLua log. Toggle in the console with
    -- AnimalHusbandry.setDebug(true).
    debug = false,

    -- Life stages by CharacterAnimal:getAge0to1(). Measured in game: the engine ages
    -- animals by 1 / lifespanInDays per in-game day and stops at exactly 1.1.
    stages = {
        teen = 0.4,
        adult = 0.6,
        elder = 1.1,
    },
    maxAge = 1.1,

    -- Each animal's breeding values, products, and mates come from its ANIMAL_CHARACTER
    -- record in FCS (the "animal husbandry" fields from fcs.def), so they can be edited
    -- there and added to animals from other mods. Run AnimalHusbandry.listDefs() in the
    -- console to see the values read for the player's animals.
    --
    -- The breeding, harvest, and sales constants below are fallback defaults.
    -- They can be configured in FCS under Game Constants (fcs.def [CONSTANTS]) using dot
    -- notation (e.g. breeding.minAge). When set in FCS, they override these values.
    -- Run AnimalHusbandry.printConstants() in the console to inspect active values.
    --
    -- A pair is a male and a female that can mate (see AnimalHusbandry.canMate) and are
    -- both not sterile. The mother's record sets the chance, pregnancy period, time
    -- between pregnancies, and number of offspring.
    breeding = {
        -- How often the breeding check runs, in in-game hours. Each check rolls the
        -- record's "chance of pregnancy" once for every eligible female.
        checkIntervalHours = 1,
        -- Minimum getAge0to1() for both parents: Adult or Elder.
        minAge = 0.6,
        -- Maximum distance between the parents, in world units. Run
        -- AnimalHusbandry.debugPairs() in the console to see real distances and tune it.
        maxPairDistance = 50,
        -- getAge0to1() of a newborn.
        babyAge = 0,
    },

    -- Harvesting from the Husbandry window, opened from the right-click menu on an
    -- animal while a person in the player faction is selected. That person harvests
    -- and receives the items. Products come from the animal's "animal products" list
    -- in FCS.
    harvest = {
        -- Minimum getAge0to1() of the animal: Adult or Elder.
        minAge = 0.6,
        -- Maximum distance between the harvester and the animal, in world units.
        maxDistance = 50,
        -- Maximum number of product rows visible in the Husbandry window before scrolling.
        maxVisibleProducts = 4,
    },

    -- The animal sale window, opened by scripts/dialogue/ah_open_animal_sale.lua when
    -- a dialogue line runs it through FCS "run lua script". The NPC in the conversation
    -- buys; the player's animals near that NPC are offered.
    sales = {
        -- Maximum distance, in world units, between an animal and either the buyer (or
        -- the building the buyer is in) or the player character selling. Turn on
        -- AnimalHusbandry.setDebug(true) to log each animal's distance when the window opens.
        maxDistance = 250,
        -- Each animal's base price is the "base price" field of its ANIMAL_CHARACTER
        -- record in FCS. Animals whose record does not set it use defaultBasePrice,
        -- the vanilla animal trader's base. The price is (getAge0to1() + 0.1) x base,
        -- the same formula the trader uses, from 0.1 x base at birth to 1.2 x base
        -- for elders.
        defaultBasePrice = 14000,
    },
}

if _G.AnimalHusbandry and _G.AnimalHusbandry.syncConstantsFromFCS then
    _G.AnimalHusbandry.syncConstantsFromFCS()
end
if _G.AnimalHusbandry and _G.AnimalHusbandry.rearmEvents then
    _G.AnimalHusbandry.rearmEvents()
end
