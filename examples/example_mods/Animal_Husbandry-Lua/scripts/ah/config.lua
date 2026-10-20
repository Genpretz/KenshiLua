-- config.lua
-- Fallback configuration for Animal_Husbandry-Lua. FCS values override these defaults.

return {
    -- Extra KenshiLua log output; can also be changed with AnimalHusbandryLua.setDebug().
    debug = false,

    -- Life stages on the CharacterAnimal:getAge0to1() scale.
    stages = {
        teen = 0.4,
        adult = 0.6,
        elder = 1.1,
    },
    maxAge = 1.1,

    -- FCS Game Constants override these fallback values. Per-animal breeding values,
    -- products, prices, and mating groups come from ANIMAL_CHARACTER records.
    breeding = {
        -- In-game hours between pregnancy rolls.
        checkIntervalHours = 1,
        -- Minimum age for both parents.
        minAge = 0.6,
        -- Maximum distance between parents.
        maxPairDistance = 200,
        -- Age assigned to a newborn.
        babyAge = 0,
    },

    harvest = {
        -- Minimum harvesting age.
        minAge = 0.6,
        -- Maximum distance between the harvester and animal.
        maxDistance = 200,
        -- Product rows visible before scrolling.
        maxVisibleProducts = 4,
    },

    sales = {
        -- Maximum distance from either the buyer (or their building) or seller.
        maxDistance = 250,
        -- Used when an ANIMAL_CHARACTER record has no base price.
        defaultBasePrice = 14000,
    },
}
