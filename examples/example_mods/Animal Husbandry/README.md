# Animal Husbandry

Breed your animals, harvest milk, wool and eggs from them, process those products into cheese and fine textiles, and sell animals to traders and shopkeepers.

Animal Husbandry runs on KenshiLua. Its behaviour is defined in FCS, so you can change the values for any animal and add animals from other mods without editing scripts.

## Requirements

- RE_Kenshi
- KenshiLua, a release newer than 0.3.6-alpha. The sale window uses `ForgottenGUI:createDatapanel`, which 0.3.6-alpha does not have.
- To edit the mod: [FCS Extended](https://www.nexusmods.com/kenshi/mods/1825) ([GitHub](https://github.com/BFrizzleFoShizzle/FCS_extended))

The mod uses records from the base game data files only (`gamedata.base`, `Newwworld.mod`, `rebirth.mod` and `Dialogue.mod`), so it needs no other mods.

## Installation

1. Install RE_Kenshi and KenshiLua.
2. Copy the `Animal Husbandry` folder into Kenshi's `mods` folder.
3. Enable both KenshiLua and Animal Husbandry in the launcher.

Do not rename `Animal Husbandry.mod`. Kenshi builds each record's string ID from the mod file name, for example `15-Animal Husbandry.mod`, so renaming the file breaks references to its items, icons and dialogue.

## Features

### Breeding

Once every in-game hour, each fertile female in your faction may become pregnant if a fertile male she can mate with is close by.

- **Who can mate:** a male and a female of the same race or character record. Animals with different races or records can be grouped in FCS using the `mating group` field (see [Editing and adding animals](#editing-and-adding-animals)).
- **Conditions:** both animals must be Adult or older, not sterile, and within 50 units of each other. Neither can be dead, unconscious, injured, very hungry or in combat.
- **Pregnancy:** each check rolls the mother's `chance of pregnancy`. A pregnancy lasts her `pregnancy period` in days. The newborns, as many as her `number of offspring`, appear beside her in her squad.
- **After a birth:** the mother cannot become pregnant again for her `time between pregnancy` in days.
- **Full squad:** if the squad or faction is full, the birth waits until there is room.

The engine assigns each newborn's sex and ages it like any other animal. Pregnancy and cooldown are saved with the animal and travel with it if it is sold.

### Harvesting animal products

1. Select one of your own characters, not an animal.
2. Right-click an animal in your faction and choose **Husbandry**.
3. The window shows the animal's sex, life stage, value in cats, and breeding state, and lists the products it gives, each with a **Harvest** button.

Harvesting needs:

- an animal that is Adult or older, not in combat, and of the right sex for the product;
- the product's cooldown to have passed;
- the selected character to be standing within 50 units of the animal.

The items go into the selected character's inventory. If it is full, they are dropped on the ground.

Products included:

| Animal | Products |
|---|---|
| Goat | Goat Milk (females), Wool (both sexes) |
| Garru, Pack Beast | Garru Milk (females) |
| Wild Bull, Domesticated Bull, Pack Bull | Bull Milk (females) |
| Beak Thing | Beak Thing Egg (females) |
| Crab | Crab Egg (females) |
| River Raptor | River Raptor Egg (females) |
| Swamp Raptor | Swamp Raptor Egg (females) |
| Landbat | Landbat Milk(?) |
| Leviathan | Leviathan Milk (females) |
| Skimmer | Skimmer Eggs (females) |
| Blood Spider | Blood Spider Egg(?) |
| Skin Spider | Skin Spider Egg(?) |
| Gorillo | Gorillo Fur |

### Processing

Researching **Animal Products** unlocks three buildings:

- **Cheese Processor:** makes Goat, Garru and Bull Cheese from milk.
- **Wool Loom:** makes Cashmere or Mohair from Wool. It upgrades to the Wool Auto-Loom.
- **Wool Auto-Loom:** a powered upgrade of the Wool Loom.

### Selling animals

Bartenders, shopkeepers and animal traders have new dialogue for buying animals. Choosing it opens a sale window that lists your living animals that are near the buyer or near you. If the buyer is inside a building, distance is measured from the building, so animals waiting outside are included.

- Tick the animals to sell. The window shows the total and the buyer's money.
- If the total is more than the buyer can pay, it turns red and **Confirm** is disabled.
- **Confirm** pays you and moves the sold animals into the buyer's faction and squad, so they leave with the buyer.
- **Confirm** and **Cancel** both end the conversation.

**Price:** the same formula vanilla animal traders use when they sell to you: (age + 0.1) × the animal's `base price`. A newborn sells for 0.1 × base and an elder for 1.2 × base, so elders sell for the most. Vanilla traders use a base of 14,000.

## Console commands

Run these in the KenshiLua console.

| Command | What it does |
|---|---|
| `AnimalHusbandry.printConstants()` | Displays active mod constants and indicates whether each is loaded from FCS or falls back to default. |
| `AnimalHusbandry.listDefs()` | Prints the FCS values read for each type of animal in your faction. Values not set in FCS are marked "(default)". |
| `AnimalHusbandry.status()` | Lists every animal in your faction with its race, record, sex, age, whether it can breed, and any pregnancy or cooldown. |
| `AnimalHusbandry.debugPairs()` | Lists every female and male that can mate, with their distance and the reason a pair cannot breed. |
| `AnimalHusbandry.setDebug(true)` | Logs breeding rolls, sale window candidates and other detail to the KenshiLua log. `setDebug(false)` turns it off. |
| `AnimalHusbandry.forcePregnant(days)` | Select a female first. Makes her pregnant, due in `days` (default 0.01). For testing. |
| `AnimalHusbandry.clearBreedingState()` | Select an animal first. Removes its pregnancy and cooldown. For testing. |
| `AnimalHusbandry.clearDefCache()` | Clears the cached FCS values so they are read again. |

## Configuration

Constants are defined in `fcs.def` under `[CONSTANTS]` and can be configured in FCS under **Game Constants** using dot notation. When defined in FCS, the scripts read those values automatically in-game. Fallback defaults are defined in `scripts/init/00_ah_config.lua`:

| Constant (FCS / Config) | Default | Meaning |
|---|---|---|
| `breeding.babyAge` | 0.0 | Age of a newborn animal (0.0 to 1.1 scale, where 0.0 is Newborn) |
| `breeding.checkIntervalHours` | 1.0 | In-game hours between breeding checks |
| `breeding.maxPairDistance` | 50.0 | Maximum distance between potential parents, in world units |
| `breeding.minAge` | 0.6 | Minimum age for both parents (0.6 is Adult) |
| `harvest.minAge` | 0.6 | Minimum age of an animal before its products can be harvested (0.6 is Adult) |
| `harvest.maxDistance` | 50.0 | Maximum distance between the harvester and the animal, in world units |
| `harvest.maxVisibleProducts` | 4 | Maximum product rows visible in the Husbandry window before scrolling |
| `sales.defaultBasePrice` | 14000 | Fallback base price in cats for animals whose record has no `base price` |
| `sales.maxDistance` | 250.0 | Maximum distance between an animal and the buyer (or their building) or seller |

Ages are on the engine's 0 to 1.1 scale: Pup from 0, Teen from 0.4, Adult from 0.6, Elder at 1.1. Run `AnimalHusbandry.printConstants()` in the console to inspect active values and verify their source (`FCS` or `default`).

## Editing and adding animals

Each animal's values are fields on its `ANIMAL_CHARACTER` record. The fields are defined in `fcs.def`, which adds an **animal husbandry** section to `ANIMAL_CHARACTER` in FCS.

- **Use FCS Extended to edit the mod.** The standard FCS does not read `fcs.def`, so it does not show these fields or the `LUA_SCRIPT` records that the sale dialogue runs.
- **To add animals from your own mod**, add `Animal Husbandry.mod` as a dependency of your mod, then fill in the animal husbandry fields on your `ANIMAL_CHARACTER` records. The scripts read the fields from whichever record an animal uses, so no script changes are needed.

| Field | Default | Meaning |
|---|---|---|
| `sterile` | True | If True, the animal never breeds. Set it to False to enable breeding. |
| `number of offspring` | 1 | Newborns per birth |
| `pregnancy period` | 1.0 | Days from pregnancy to birth |
| `chance of pregnancy` | 1.0 | Percent chance of pregnancy at each breeding check |
| `time between pregnancy` | 1.0 | Days after a birth before the mother can become pregnant again |
| `animal products` | `ITEM`| References the animal products that can be harvested. val0 is items per harvest, val1 is days between harvests, val2 is which sex gives it (0 male, 1 female, 2 both). |
| `base price` | 14000 | Base of the sale price, (age + 0.1) × base price |
| `mating group` | `""` | Optional group name allowing animals with different races or records to mate (e.g. "Bulls") |

The game does not read `fcs.def`. A field you never set in FCS is missing from the record, and the scripts then use the default above. Note that `sterile` defaults to True, so an animal does not breed until you set it to False.

Animals of the same RACE or ANIMAL_CHARACTER can always mate. Use `mating group` for animals with different races or records that should be able to mate, such as Domesticated Bull and Wild Bull. Both animals must share the same non-empty mating group name (case-insensitive).

### Item icons

An item's icon is a PNG in the `icons` folder named after the item's string ID, for example `icons/15-Animal Husbandry.mod.png` for Goat Milk.
