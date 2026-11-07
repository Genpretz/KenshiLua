#include <windows.h>
// Keep the same member-pointer ABI as the task implementation.
#include <kenshi/Tasker.h>
#include <kenshi/Character.h>
#include <kenshi/GameData.h>
#include <kenshi/Inventory.h>
#include <kenshi/Item.h>
#include <kenshi/Building/StorageBuilding.h>
#include <vector>
#include "Storage.h"

namespace
{
    Inventory* backpackInventory(Character* worker)
    {
        Item* backpack = worker->hasABackpackOn();
        return backpack ? backpack->getInventory() : NULL;
    }

    int productCount(Character* worker, GameData* product)
    {
        Inventory* inventory = worker->getInventory();
        Inventory* backpack = backpackInventory(worker);
        return (inventory ? inventory->countItems(product) : 0) +
            (backpack ? backpack->countItems(product) : 0);
    }

    template <typename Map>
    int itemInteger(const Map& values, const char* name, int fallback)
    {
        typename Map::const_iterator it = values.find(name);
        return it == values.end() ? fallback : it->second;
    }

    bool acceptsProduct(StorageBuilding* storage, GameData* product)
    {
        const Ogre::vector<GameDataReference>::type* refs =
            storage->getGameData()->getReferenceListIfExists("limit inventory");
        if (!refs) return false;
        for (size_t i = 0; i < refs->size(); ++i)
        {
            if ((*refs)[i].sid == product->stringID) return true;
        }
        return false;
    }

    struct PackedStack
    {
        Item* item;
        int quantity;
        PackedStack(Item* value, int amount) : item(value), quantity(amount) {}
    };
    struct PackingSection
    {
        InventorySection* section;
        std::vector<unsigned char> occupied;
        std::vector<PackedStack> stacks;
        int stackCount;
        explicit PackingSection(InventorySection* value) : section(value), stackCount(0)
        {
            if (value->width <= 0 || value->height <= 0) return;
            occupied.resize(value->width * value->height, 0);
            const Ogre::vector<InventorySection::SectionItem>::type& items = value->getItems();
            stackCount = static_cast<int>(items.size());
            for (size_t i = 0; i < items.size(); ++i)
            {
                const InventorySection::SectionItem& item = items[i];
                if (!item.item) continue;
                stacks.push_back(PackedStack(item.item, item.item->quantity));
                for (int y = item.y; y < item.y + item.h && y < value->height; ++y)
                {
                    for (int x = item.x; x < item.x + item.w && x < value->width; ++x)
                    {
                        occupied[y * value->width + x] = 1;
                    }
                }
            }
        }

        // Simulate insertion and return the quantity that could not fit.
        int add(Item* specimen, GameData* data, int quantity)
        {
            if (occupied.empty() || !section->getEnabled() ||
                !section->isLimitedSlotCompatible(data) || !section->hasRoomForItem(data, 1)) return quantity;
            int width = specimen ? specimen->itemWidth : itemInteger(data->idata, "inventory footprint width", 0);
            int height = specimen ? specimen->itemHeight : itemInteger(data->idata, "inventory footprint height", 0);
            if (width <= 0 || height <= 0) return quantity;
            int capacity = specimen ? specimen->isStackable(section) :
                section->applyStackingBonuses(itemInteger(data->idata, "stackable", 1));
            if (capacity < 1) capacity = 1;

            // Fill compatible stacks before allocating new grid footprints.
            if (specimen)
            {
                for (size_t i = 0; i < stacks.size() && quantity > 0; ++i)
                {
                    if (stacks[i].item && stacks[i].item->canStackWith(specimen))
                    {
                        int room = capacity - stacks[i].quantity;
                        if (room <= 0) continue;
                        int amount = room < quantity ? room : quantity;
                        stacks[i].quantity += amount;
                        quantity -= amount;
                    }
                }
            }
            for (int x = 0; x + width <= section->width && quantity > 0; ++x)
            {
                for (int y = 0; y + height <= section->height && quantity > 0; ++y)
                {
                    if (section->itemsLimit > 0 && stackCount >= section->itemsLimit) return quantity;
                    bool free = true;
                    for (int yy = y; yy < y + height && free; ++yy)
                    {
                        for (int xx = x; xx < x + width; ++xx)
                        {
                            if (occupied[yy * section->width + xx])
                            {
                                free = false;
                                break;
                            }
                        }
                    }
                    if (!free) continue;
                    for (int yy = y; yy < y + height; ++yy)
                    {
                        for (int xx = x; xx < x + width; ++xx)
                        {
                            occupied[yy * section->width + xx] = 1;
                        }
                    }
                    int amount = capacity < quantity ? capacity : quantity;
                    stacks.push_back(PackedStack(specimen, amount));
                    ++stackCount;
                    quantity -= amount;
                }
            }
            return quantity;
        }
    };
}

namespace HusbandryStorage
{
    int deliverableCount(Character* worker, GameData* product)
    {
        int quantity = productCount(worker, product);
        if (quantity && Item::isFood(product))
        {
            Inventory* inventory = worker->getInventory();
            Inventory* backpack = backpackInventory(worker);
            int food = (inventory ? inventory->getNumFoodItems(worker) : 0) +
                (backpack ? backpack->getNumFoodItems(worker) : 0);
            // Match AI::haveSomeResourcesFor: its count is edible food stacks.
            if (food == 1) return 0;
        }
        return quantity;
    }

    // InventorySection::hasRoomForItem's quantity parameter does not reserve
    // multiple footprints. Pack carried cargo into local grids without changing
    // engine inventories, then check one more freshly harvested item.
    bool hasRoomForBatch(Character* worker, StorageBuilding* storage, GameData* product)
    {
        if (!storage->canHaveSomeOfThese(product) || !acceptsProduct(storage, product)) return false;
        std::vector<Item*> cargo;
        Inventory* inventories[] = { worker->getInventory(), backpackInventory(worker) };
        Item* specimen = NULL;
        for (int inv = 0; inv < 2; ++inv)
        {
            if (!inventories[inv]) continue;
            const lektor<Item*>& items = inventories[inv]->getAllItems();
            for (unsigned int i = 0; i < items.size(); ++i)
            {
                Item* item = items[i];
                if (item->isEquipped || !acceptsProduct(storage, item->getGameData())) continue;
                cargo.push_back(item);
                if (item->getGameData() == product && item->chargesLeft >= item->originalFullChargeAmount)
                    specimen = item;
            }
        }
        if (cargo.empty()) return true;
        std::vector<PackingSection> sections;
        lektor<InventorySection*>& all = storage->getInventory()->getAllSections();
        for (unsigned int i = 0; i < all.size(); ++i)
        {
            sections.push_back(PackingSection(all[i]));
        }
        for (size_t i = 0; i < cargo.size(); ++i)
        {
            int left = cargo[i]->quantity;
            for (size_t s = 0; s < sections.size() && left > 0; ++s)
            {
                left = sections[s].add(cargo[i], cargo[i]->getGameData(), left);
            }
            if (left) return false;
        }
        int left = 1;
        for (size_t s = 0; s < sections.size() && left > 0; ++s)
        {
            left = sections[s].add(specimen, product, left);
        }
        return left == 0;
    }
}
