#pragma once

class Character;
class GameData;
class StorageBuilding;

namespace HusbandryStorage
{
    // Main-thread queries over borrowed engine objects. Neither changes inventory.
    int deliverableCount(Character* worker, GameData* product);
    bool hasRoomForBatch(Character* worker, StorageBuilding* storage, GameData* product);
}
