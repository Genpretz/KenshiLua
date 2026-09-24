# Containers Reference

KenshiLua exposes native C++ and engine-specific containers directly to Lua. These containers serve as the primary conduits for exchanging collections of objects, components, and state between Lua scripts and Kenshi's engine.

---

## Architecture, Ownership, and Memory Rules

### 1. Engine-Owned vs. Script-Owned Containers
* **Engine-Owned (Borrowed)**:
  Containers accessed through object fields or method returns (e.g., [`Character.threats`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/extern/kenshilib/Include/kenshi/SensoryData.h), [`GameData.data_string`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/extern/kenshilib/Include/kenshi/GameData.h), [`Inventory.getAllItems`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/src/Bindings/Kenshi/InventoryBinding.cpp#L871)) point directly into live engine memory.
  * Their memory lifecycle is managed entirely by the game engine.
  * Lua GC uses a no-op destructor (`noopGc`) when collecting the userdata handle.
* **Script-Owned (Factory Created)**:
  Containers created in Lua via factory methods (e.g., `lektor.new(...)`, `ogre_unordered_set.new(...)`, `ogre_unordered_map.new(...)`) allocate a container wrapper on the CRT heap.
  * The container wrapper is owned and managed by Lua's Garbage Collector.
  * When garbage collected, only the container's structural allocations are freed.

### 2. Element Safety (No Entity Destruction)
Game entities held inside containers (e.g. `Character*`, `RootObject*`, `Item*`, `GameData*`, `TownBase*`) are **borrowed references**:
* When a container is cleared or collected by Lua GC, **only the container structure and pointer references are freed**.
* The underlying game entities in the Kenshi game world are **never destroyed** by container cleanup.

### 3. Allocation and High-Frequency Loops
* **Do not allocate containers every frame**: Avoid creating new containers with `.new(...)` inside high-frequency frame events or tick hooks (e.g., `onFrame`, `onUpdate`).
* **Reuse scratch containers**: Allocate a persistent module-level container, clear it with `:clear()`, and pass it to engine query methods. This avoids triggering unnecessary GC cycles and prevents virtual memory arena exhaustion under LuaJIT's 2GB memory model.

---

## Container Overview

| Container | Underlying C++ Type | Key/Index Style | Typical Engine Usage |
| :--- | :--- | :--- | :--- |
| **`lektor<T>`** | [`lektor<T>`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/extern/kenshilib/Include/kenshi/util/lektor.h) | 1-based integer | General entity lists, spatial queries, inventory section items |
| **`ogre_unordered_set<T>`** | `ogre_unordered_set<T>` | Value existence | Entity sets, active zone sets, town query filters |
| **`ogre_unordered_map<K, V>`** | `ogre_unordered_map<K, V>` | Hash key lookup | World state maps, threat assessment maps, entity weights |
| **`boost_unordered_map<K, V>`** | `boost::unordered_map<K, V>` | Hash key lookup | GameData properties (`data_string`, `data_int`, `data_float`) |
| **`boost_unordered_set<T>`** | `boost::unordered_set<T>` | Hash key existence | Entity collections, GameData sets |
| **`std::map<K, V>`** | `std::map<K, V>` | Ordered key lookup | Combat technique selectors, fitness evaluators, GUI layouts |
| **`std::set<T>`** | `std::set<T>` | Ordered key existence | Faction membership, race limiter sets, distinct hand handles |
| **`std::deque<T>`** | `std::deque<T>` | 1-based integer | Ragdoll message queues, crafting items, root object queues |
| **`Ogre::FastArray<T>`** | `Ogre::FastArray<T>` | 1-based integer | Wound lists, appearance data ranges, portrait tab elements |
| **`ogre_vector<T>`** | `std::vector<T, OgreAlloc>` | 1-based integer | GameData reference lists, string pairs, trade sections |
| **`Array2d<T>`** | `Array2d<T>` | 0-based row/col | Inventory grid slot matrix (`InventorySection.items`) |

---

## 1. `lektor<T>`

The primary dynamic array container used across Kenshi's engine.

### Factory Creation
```lua
-- Standard syntax
local charList = lektor.new("Character*")

-- Callable table syntax
local intList = lektor("int")

-- From class tables or userdata
local rootList = lektor.new(RootObject)
```

#### Supported Types
* **Pointers**: `"RootObject*"`, `"Character*"`, `"Building*"`, `"FarmBuilding*"`, `"Item*"`, `"InventorySection*"`, `"CombatTechniqueData*"`, `"GameData*"`, `"ModInfo*"`, `"DialogLineData*"`, `"DialogCondition*"`, `"DialogAction*"`
* **Primitives and Values**: `"int"`, `"string"`, `"std::string"`, `"hand"`, `"ModInfo"`, `"SaveInfo"`
* **Short Type Names**: Passing `"Character"`, `"Item"`, or `"RootObject"` automatically maps to pointer collections.

### Methods and Operators
| Operation | Syntax | Description |
| :--- | :--- | :--- |
| **Length** | `#lek` or `lek:size()` | Returns element count. |
| **Index Access** | `lek[i]` | Returns 1-based element, or `nil` if out of bounds. |
| **Index Assignment** | `lek[i] = val` | Assigns existing index `1..#lek`, or appends at `#lek + 1`. |
| **Push** | `lek:push(val)` | Appends `val` to the end. |
| **Pop** | `local val = lek:pop()` | Removes and returns the last element. Errors if empty. |
| **Remove At** | `lek:removeAt(i)` | Removes element at 1-based index `i`, shifting left. |
| **Clear** | `lek:clear()` | Clears all elements, resetting count to 0. |
| **Table Conversion** | `local tbl = lek:toTable()` | Converts contents to a standard Lua array table. |
| **Iteration** | `ipairs(lek)` / `pairs(lek)` | Iterates from index `1` to `#lek`. |

---

## 2. `ogre_unordered_set<T>` and `boost_unordered_set<T>`

Hash sets backed by Ogre or Boost allocators.

### Factory Creation
```lua
local factionSet = ogre_unordered_set.new("Character*")
local handSet = ogre_unordered_set.new("hand")
```

#### Supported Types
`"hand"`, `"GameData*"`, `"TownBase*"`, `"Character*"`, `"RootObject*"`, `"ZoneMap*"`, `"TownBuildingsManager*"`

### Methods and Operators
| Operation | Syntax | Description |
| :--- | :--- | :--- |
| **Length** | `#set` or `set:size()` | Returns element count. |
| **Membership Check** | `set:has(elem)` or `set[elem]` | Returns `true` if present, `false` otherwise. |
| **Add** | `set:add(elem)` or `set[elem] = true` | Adds element to set. Returns `true` if newly inserted. |
| **Remove** | `set:remove(elem)` or `set[elem] = nil` | Removes element from set. Returns `true` if removed. |
| **Clear** | `set:clear()` | Removes all elements from the set. |
| **Table Conversion** | `local tbl = set:toTable()` | Returns an array table of all elements in the set. |
| **Iteration** | `for elem in pairs(set) do` | Iterates over all elements. |

---

## 3. `ogre_unordered_map<K, V>` and `boost_unordered_map<K, V>`

High-performance hash maps. Widely used for GameData values, threat maps, and entity property associations.

### Factory Creation
```lua
local threatWeights = ogre_unordered_map.new("RootObject*", "float")
local factionState = ogre_unordered_map.new("Faction*", "bool")
```

#### Common Engine Map Types
* `ogre_unordered_map.new("RootObject*", "float")`
* `ogre_unordered_map.new("Character*", "float")`
* `ogre_unordered_map.new("hand", "float")`
* `ogre_unordered_map.new("hand", "Character*")`
* `ogre_unordered_map.new("GameData*", "float")`
* `ogre_unordered_map.new("GameData*", "int")`
* `ogre_unordered_map.new("Faction*", "bool")`
* `ogre_unordered_map.new("ZoneMap*", "bool")`

### Methods and Operators
| Operation | Syntax | Description |
| :--- | :--- | :--- |
| **Length** | `#map` or `map:size()` | Returns number of key-value pairs. |
| **Lookup** | `map[key]` | Retrieves value associated with `key`, or `nil`. |
| **Assignment** | `map[key] = val` | Sets value for `key`. Setting to `nil` removes key. |
| **Key Check** | `map:has(key)` | Returns `true` if `key` exists in map. |
| **Remove** | `map:remove(key)` | Erases `key`. Returns `true` if key existed. |
| **Clear** | `map:clear()` | Clears all entries from map. |
| **Table Conversion** | `local tbl = map:toTable()` | Converts map to a Lua key-value table. |
| **Iteration** | `for k, v in pairs(map) do` | Iterates over all key-value pairs. |

---

## 4. `std::set<T>` and `std::map<K, V>`

Standard C++ sorted associative containers (red-black tree). Typically encountered on subsystem managers, faction relations, or GUI layout bindings.

### Methods and Operators
* **`std::set<T>`**:
  * Check: `set:has(elem)` or `set[elem]`
  * Insert: `set:insert(elem)` or `set[elem] = true`
  * Remove: `set:remove(elem)` or `set[elem] = nil`
  * Clear: `set:clear()`
  * Size: `#set` or `set:size()`
  * Iteration: `pairs(set)`
  * Table Conversion: `set:toTable()`
* **`std::map<K, V>`**:
  * Lookup: `map[key]`
  * Assign: `map[key] = val` (or `map[key] = nil` to erase)
  * Check: `map:has(key)`
  * Remove: `map:remove(key)`
  * Clear: `map:clear()`
  * Size: `#map` or `map:size()`
  * Iteration: `pairs(map)`
  * Table Conversion: `map:toTable()`

---

## 5. `std::deque<T>`

Standard C++ double-ended queue. Used in engine subsystems for message queuing (e.g. [`Character.ragdollQueue`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/src/Bindings/Kenshi/CharacterBinding.cpp), crafting order buffers, root object processing queues).

### Methods and Operators
| Operation | Syntax | Description |
| :--- | :--- | :--- |
| **Length** | `#deq` or `deq:size()` | Returns number of elements. |
| **Empty Check** | `deq:empty()` | Returns `true` if empty. |
| **1-Based Indexing** | `deq[i]` / `deq[i] = val` | Accesses or modifies element at index `i`. |
| **Head Access** | `deq:front()` | Returns the first element without removing it. |
| **Tail Access** | `deq:back()` | Returns the last element without removing it. |
| **Push Tail** | `deq:push_back(val)` | Appends `val` to the back. |
| **Push Head** | `deq:push_front(val)` | Inserts `val` at the front. |
| **Pop Tail** | `local val = deq:pop_back()` | Removes and returns the back element. |
| **Pop Head** | `local val = deq:pop_front()` | Removes and returns the front element. |
| **Remove At** | `deq:removeAt(i)` | Removes element at 1-based index `i`. |
| **Clear** | `deq:clear()` | Clears the deque. |
| **Iteration** | `ipairs(deq)` / `pairs(deq)` | Iterates sequentially from head to tail. |
| **Table Conversion** | `local tbl = deq:toTable()` | Converts deque to a Lua array table. |

---

## 6. `Ogre::FastArray<T>` and `ogre_vector<T>`

Contiguous arrays optimized for high cache locality. Commonly exposed on appearance data ([`AppearanceManager`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/src/Bindings/Kenshi/AppearanceManagerBinding.cpp)), medical wounds, and GUI widget arrays.

### Methods and Operators
* **Length**: `#arr` or `arr:size()`
* **Empty Check**: `arr:empty()`
* **Reserve**: `arr:reserve(capacity)` (preallocates memory buffer)
* **1-Based Indexing**: `arr[i]` and `arr[i] = val`
* **Ends Access**: `arr:front()` and `arr:back()`
* **Push/Pop**: `arr:push_back(val)` and `arr:pop_back()`
* **Remove**: `arr:removeAt(i)`
* **Clear**: `arr:clear()`
* **Iteration**: `ipairs(arr)` and `pairs(arr)`
* **Table Conversion**: `arr:toTable()`

---

## 7. `Array2d<T>`

Two-dimensional grid representation used by Kenshi for grid-based inventory layouts ([`InventorySection.items`](file:///C:/Users/Genpretz/source/repos/Genpretz/KenshiLua/src/Bindings/Kenshi/InventorySectionBinding.cpp)).

### Properties
* `grid.nRows`: Number of vertical grid rows (height).
* `grid.nCols`: Number of horizontal grid columns (width).

---

## Common Patterns and Idioms

### Pattern 1: Engine Spatial Query with Reusable `lektor`

```lua
local gw = getGameWorld()
if not gw then return end

-- Allocate container once outside hot loop
local searchBuffer = lektor.new("RootObject*")

local function findNearbyEnemies(position, searchRadius)
    -- Reset count without releasing underlying memory buffer
    searchBuffer:clear()

    -- Engine populates searchBuffer in-place
    gw:getObjectsWithinSphere(searchBuffer, position, searchRadius, 0, 50, nil)

    local enemies = {}
    for i, obj in ipairs(searchBuffer) do
        -- Safe downcast check via bound methods
        if obj.isCharacter and obj:isCharacter() then
            table.insert(enemies, obj)
        end
    end
    return enemies
end
```

### Pattern 2: Inspecting and Filtering GameData Hash Maps

```lua
-- Retrieve GameData string dictionary directly from engine
local itemData = getItemGameData()
if itemData and itemData.data_string then
    local stringProps = itemData.data_string

    -- Table syntax lookup
    local desc = stringProps["description"]
    KenshiLua.log("Item description: " .. tostring(desc))

    -- Iterate all key-value entries
    for key, value in pairs(stringProps) do
        KenshiLua.log(string.format("  Key: %s = %s", key, value))
    end
end
```

### Pattern 3: Set Filtering for Exclusions

```lua
-- Maintain an exclusion set of distinct Character pointers
local ignoredTargets = ogre_unordered_set.new("Character*")
ignoredTargets:add(myLeader)
ignoredTargets:add(myPet)

for i, character in ipairs(nearbyCharacters) do
    if not ignoredTargets:has(character) then
        processTarget(character)
    end
end
```

### Pattern 4: Safe Conversion to Lua Table

When passing container results to external Lua libraries or scripts where C++ userdata wrappers should not be retained, convert to pure Lua tables:

```lua
local results = lektor.new("Item*")
inventory:getAllItems(results)

-- Convert to standard 1-based Lua table
local pureTable = results:toTable()
table.sort(pureTable, function(a, b)
    return a:getValue() > b:getValue()
end)
```
