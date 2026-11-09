# Animal Husbandry (Lua Example Mod)

Breed animals, harvest milk, wool, hair, fur, horns, and eggs, process animal products, assign automated husbandry jobs, and sell livestock to traders and shopkeepers.

Animal_Husbandry-Lua uses KenshiLua for gameplay logic and FCS records for animal-specific settings. Other mods can configure compatible animals without changing these scripts.

## Requirements

- RE_Kenshi
- KenshiLua
- [FCS Extended](https://www.nexusmods.com/kenshi/mods/1825) for mod authors who want to edit Animal_Husbandry-Lua records

The mod has no gameplay mod dependencies.

## Installation

1. Install RE_Kenshi and KenshiLua.
2. Copy the `Animal_Husbandry-Lua` folder into Kenshi's `mods` folder.
3. Enable KenshiLua and Animal_Husbandry-Lua in the launcher.

## Features

### Breeding

Once per in-game day, each eligible female in the player faction can become pregnant when a compatible male is nearby.

- Both animals must be Adult or older (age ≥ 0.6), fertile, healthy, fed, conscious, out of combat, and within 200 units of each other.
- Animals can mate when they share a race, character record, or non-empty `mating group`.
- Pregnancy chance, duration, offspring count, and recovery time come from the mother's `ANIMAL_CHARACTER` record.
- Birth waits when the mother's squad or the player faction has no room.
- Pregnancy and recovery state are saved on the animal and remain with it if ownership changes.
- Spiders (such as Skin Spiders and Blood Spiders) are not included in breeding or husbandry.

### Harvesting

Select one of your humanoid characters, right-click an animal in the player faction, and choose **Husbandry**. While the window is open, selecting another animal in your faction switches its portrait, details, and products. Selecting a humanoid leaves the displayed animal unchanged.

The character who opened the window remains its harvester and must be within 200 units of the displayed animal to harvest. Close the window and open it with another humanoid to change harvesters.

The Husbandry window shows the animal's sex, age, value, breeding state, and available products. A product can be harvested when the animal meets its minimum age (Teen, age ≥ 0.4) and sex requirements, is out of combat, and its cooldown has expired. Items go into the harvester's inventory or drop beside them if the inventory is full.

The window scales uniformly from its compact 1920x1080 design size, stays within the screen, and keeps a readable minimum size on lower resolutions. Growth above 1080p is restrained so the window does not occupy excessive space at high resolutions. Its portrait, sections, and product rows preserve their proportions across aspect ratios. The product list fits two rows and adds vertical scrolling only when more rows overflow; it never uses horizontal scrolling.

### Automated Husbandry jobs

Shift-clicking **Husbandry** from the right-click menu assigns a permanent automated Husbandry job to the selected character.

- Workers search for matching ready animals in their outpost within 75 units, harvest available products, and haul them to dedicated storage containers.
- The worker keeps one edible food stack for personal nutrition and will not deposit it as deliverable cargo.
- Workers evaluate container space before harvesting batches to avoid hauling to full storage.
- The job appears in the Orders panel with the animal group name (such as `Animal Husbandry: Goats` or `Animal Husbandry: Bonedogs`).
- Background worker-thread scoring, task registration, and save persistence are handled by the included native plugin (`plugin/AnimalHusbandryNative.dll`).

### Item stacking

Inventory stacking follows the base game's material conventions. Consumables (milk and cheese), raw wool, hair, fur, horns, eggs, and other animal parts do not stack. Processed textiles (such as Cashmere and Yarn) stack to 4, matching vanilla Leather.

### Included products

| Animal | Products | Producer sex | Cooldown |
|---|---|---|---:|
| Goat, Cornelius | Goat Milk, Goat Wool | Milk: female; Wool: both | 1 day |
| Garru, Pack Beast | Garru Milk | Female | 1 day |
| Wild Bull, Domesticated Bull, Pack Bull | Bull Milk | Female | 1 day |
| Leviathan | Leviathan Milk | Female | 1 day |
| Bonedog, Mountain Dog, Pet Dog, Settler's Pup | Bonedog Hair | Both | 1–2 days |
| Boneyard Wolf | Boneyard Wolf Hair | Both | 2 days |
| Gorillo | Gorillo Fur | Both | 1 day |
| Black Gorillo, King Gorillo, War Gorillo | Black Gorillo Fur | Both | 1 day |
| Landbat | Landbat Fur | Both | 1 day |
| Beak Thing | Beak Thing Egg | Female | 7 days |
| Crab | Crab Egg | Female | 1 day |
| River Raptor | River Raptor Egg, Raptor Horn | Egg: female (qty 1); Horn: male (qty 1) | Egg: 2 days; Horn: 3 days |
| Swamp Raptor | Swamp Raptor Egg, Raptor Horn | Egg: female (qty 1); Horn: male (qty 2) | Egg: 2 days; Horn: 3 days |
| Megaraptor | Horn of the Megaraptor | Both | 7 days |
| Skimmer | Skimmer Eggs | Female | 1 day |
| Swamp Turtle | Swamp Turtle Egg | Female | 1 day |

> Cage Beasts, Great White Gorillos, and Megacrabs can breed when male and female pairs are present, but do not produce harvestable items. Spiders (Skin Spiders, Blood Spiders) are not included.

### Processing

Researching husbandry technologies unlocks processing buildings and storage:

- **Processed Dairy Products:** unlocks the manual **Cheese Processor** (turns Goat, Garru, Bull, and Leviathan Milk into cheese) and dedicated storage for milk and cheese.
- **Automatic Cheese Processing:** unlocks powered **Automatic Cheese Processors** for Goat, Garru, Bull, and Leviathan Milk.
- **Processed Animal Fibres:** unlocks the manual **Cashmere Loom** (turns Goat Wool into Cashmere), manual **Fabric Looms** (turns Goat Wool, Bonedog Hair, Boneyard Wolf Hair, Gorillo Fur, Black Gorillo Fur, and Landbat Fur into Fabric), and dedicated fiber storage.
- **Automatic Loom (Animal Fibres):** powered upgrade unlocking the **Cashmere Auto-Loom** and **Animal Fibre Auto-Looms** for each fiber type.
- **Storage Boxes: Exotic Animal Products:** unlocks dedicated storage containers for eggs and horns (Beak Thing Eggs, Crab Eggs, River Raptor Eggs, Swamp Raptor Eggs, Skimmer Eggs, Swamp Turtle Eggs, and Raptor Horns).

### Food prices

Milk and cheese target approximately **10.43 cats per nutrition point**, the median of nine everyday vanilla foods: Bread, Chewsticks, Cooked Vegetables, Dried Meat, Dustwich, Foodcube, Gohan, Meatwrap, and Rice Bowl. Nutrition amounts and ingredient quantities are unchanged.

| Food | Nutrition | Calculated average value (cats) |
|---|---:|---:|
| Goat Milk | 25 | 261 |
| Bull Milk | 30 | 313 |
| Garru Milk | 35 | 365 |
| Goat Cheese | 50 | 521 |
| Bull Cheese | 55 | 574 |
| Garru Cheese | 60 | 626 |
| Leviathan Milk | 100 | 1,044 |
| Leviathan Cheese | 100 | 1,044 |

These calculations use vanilla price and food-quality multipliers for a full item. Town prices, trader modifiers, resale discounts, and partially consumed items affect actual transactions. Integer price rounding causes small differences in the ratios.

For mod authors: vanilla's `food quality mult` of `0.5` halves the FCS `charges` to produce the nutrition shown above. Milk prices use `value` and the global trade-price multiplier. Cheese prices use the milk ingredient's calculated price and the cheese's `profitability`; the cheese's own `value` field is ignored when ingredients are present.

### Selling animals

Supported traders have dialogue options for buying nearby animals. The sale window shows each accepted animal's price, the selected total, and the buyer's available money. Confirming a sale pays the player and transfers the animals to the buyer's faction and squad.

Animals qualify when they are alive, belong to the player, and are within 200 units of the seller, buyer, or the building containing the buyer. Individual dialogue scripts can further restrict which animal records a buyer accepts.

The sale price is `(age + 0.1) × base price × resaleMultiplier`, scaling base price by age and applying the resale multiplier (default 0.50, matching player-crafted weapon production). The animal's `base price` comes from its record or defaults to 14,000 cats.

## Configuration

Global defaults are defined in [`scripts/ah/config.lua`](scripts/ah/config.lua). Values set under `[CONSTANTS]` in `fcs.def` can be edited in FCS under **Game Constants** and override the Lua defaults.

| Setting | Default | Purpose |
|---|---:|---|
| `breeding.babyAge` | 0.0 | Newborn age on the engine's 0.0–1.1 scale |
| `breeding.checkIntervalDays` | 1.0 | Days between pregnancy checks |
| `breeding.maxPairDistance` | 200.0 | Maximum distance between potential parents |
| `breeding.minAge` | 0.6 | Minimum age for both parents |
| `harvest.minAge` | 0.4 | Minimum harvesting age (Teen) |
| `harvest.maxDistance` | 200.0 | Maximum harvesting distance for manual window |
| `harvest.jobMaxDistance` | 75.0 | Maximum distance for automated Husbandry jobs |
| `sales.defaultBasePrice` | 14000 | Price base when an animal record has none |
| `sales.maxDistance` | 200.0 | Maximum sale distance |
| `sales.resaleMultiplier` | 0.50 | Resale multiplier applied when selling animals to vendors |

Life stages use the engine age scale: Pup begins at 0.0, Teen at 0.4, Adult at 0.6, and Elder at 1.1.

## Modding support

Animal settings are fields on each `ANIMAL_CHARACTER` record. Add `Animal_Husbandry-Lua.mod` as a dependency, then configure these fields with FCS Extended:

| Field | Default | Purpose |
|---|---:|---|
| `sterile` | True | Prevents breeding when enabled |
| `number of offspring` | 1 | Newborns per birth |
| `pregnancy period` | 10.0 | In-game days from pregnancy to birth |
| `chance of pregnancy` | 10.0 | Percent chance during each breeding check |
| `time between pregnancy` | 1.0 | Recovery days after birth |
| `animal products` | None | Product references: val0 quantity, val1 cooldown days, val2 sex (`0` both, `1` male, `2` female) |
| `base price` | 14000 | Base used by the sale-price formula |
| `mating group` | Empty | Case-insensitive group for mating across different races or records |

Fields omitted from an animal record use these defaults. Because `sterile` defaults to True, breeding must be enabled explicitly for new animal records.

The dialogue scripts provide three sale filters:

| Script | Accepted animals |
|---|---|
| `ah_open_animal_sale.lua` | Every eligible animal |
| `ah_open_goat_sale.lua` | Goats |
| `ah_open_holy_livestock_sale.lua` | Wild Bulls, Goats, Pack Beasts, Bonedogs, Domesticated Bulls, Garru, and Pack Bulls |

To create another filter, pass a predicate to `AnimalHusbandryLua.sales.open(currentDialogue, filter)`. The predicate receives an entry with `char`, `animal`, `raceID`, `raceName`, `templateID`, and `def` fields.

The only automatic entry point is [`scripts/init/00_ah_startup.lua`](scripts/init/00_ah_startup.lua). It loads the modules under `scripts/ah/` and exposes the dialogue and console interface through `AnimalHusbandryLua`.

## Console tools

These commands are available in the KenshiLua console:

| Command | Purpose |
|---|---|
| `AnimalHusbandryLua.printConstants()` | Print active constants and their source |
| `AnimalHusbandryLua.listDefs()` | Print husbandry fields for animal records in the player faction |
| `AnimalHusbandryLua.status()` | Print age, sex, breeding eligibility, pregnancy, and cooldown state |
| `AnimalHusbandryLua.debugPairs()` | Explain pairing and distance results for breeding candidates |
| `AnimalHusbandryLua.setDebug(true)` | Enable detailed logging; pass `false` to disable it |
| `AnimalHusbandryLua.forcePregnant(days)` | Make the selected female animal pregnant |
| `AnimalHusbandryLua.clearBreedingState()` | Clear pregnancy and recovery state on the selected animal |
| `AnimalHusbandryLua.resetProductCooldowns()` | Reset harvesting cooldowns on all player animal products |
| `AnimalHusbandryLua.clearDefCache()` | Reload animal definitions on their next use |

## Assets

Item icons use the item's full string ID as the file name, such as `icons/15-Animal_Husbandry-Lua.mod.png`.
