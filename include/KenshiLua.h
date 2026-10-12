#pragma once

#include <stddef.h>
#include <string>
#include <cstring>
#include <windows.h>

#ifndef lua_h
struct lua_State;
typedef int (*lua_CFunction)(struct lua_State* L);
#endif

#if defined(_MSC_VER)
#define KENSHILUA_CALL __cdecl
#else
#define KENSHILUA_CALL
#endif

#define KENSHILUA_ABI_VERSION 1u

enum KenshiLua_StatusCode
{
    KENSHILUA_STATUS_OK = 0,
    KENSHILUA_STATUS_NOT_INITIALIZED = 1,
    KENSHILUA_STATUS_INVALID_ARGUMENT = 2,
    KENSHILUA_STATUS_FILE_NOT_FOUND = 3,
    KENSHILUA_STATUS_LUA_SYNTAX_ERROR = 4,
    KENSHILUA_STATUS_LUA_RUNTIME_ERROR = 5,
    KENSHILUA_STATUS_LUA_MEMORY_ERROR = 6,
    KENSHILUA_STATUS_UNSUPPORTED_VERSION = 7,
    KENSHILUA_STATUS_WRONG_THREAD = 8,
    KENSHILUA_STATUS_UNKNOWN_ERROR = 99
};

#pragma pack(push, 8)

struct KenshiLua_Reg
{
    const char* name;
    lua_CFunction function;
};

struct KenshiLua_ApiV1
{
    unsigned int abiVersion;
    unsigned int structSize;

    int (KENSHILUA_CALL *isInitialized)(void);
    struct lua_State* (KENSHILUA_CALL *getState)(void);
    const char* (KENSHILUA_CALL *getVersion)(void);
    int (KENSHILUA_CALL *getVersionMajor)(void);
    int (KENSHILUA_CALL *getVersionMinor)(void);
    int (KENSHILUA_CALL *getVersionPatch)(void);

    int (KENSHILUA_CALL *runScript)(const char*, char*, size_t);
    int (KENSHILUA_CALL *runString)(const char*, const char*, char*, size_t);
    int (KENSHILUA_CALL *dispatchEvent)(const char*, int, char*, size_t);
    int (KENSHILUA_CALL *registerFunction)(const char*, lua_CFunction, char*, size_t);
    int (KENSHILUA_CALL *registerModule)(const char*, lua_CFunction, char*, size_t);

    int (KENSHILUA_CALL *pushObject)(struct lua_State*, void*, const char*);
    void* (KENSHILUA_CALL *checkObject)(struct lua_State*, int, const char*);
    void* (KENSHILUA_CALL *testObject)(struct lua_State*, int, const char*);
    int (KENSHILUA_CALL *resolveScriptPath)(const char*, char*, size_t);

    void (KENSHILUA_CALL *logInfo)(const char*);
    void (KENSHILUA_CALL *logWarning)(const char*);
    void (KENSHILUA_CALL *logError)(const char*);
    void (KENSHILUA_CALL *logDebug)(const char*);

    void (KENSHILUA_CALL *pushNil)(struct lua_State*);
    void (KENSHILUA_CALL *pushNumber)(struct lua_State*, double);
    void (KENSHILUA_CALL *pushInteger)(struct lua_State*, ptrdiff_t);
    void (KENSHILUA_CALL *pushString)(struct lua_State*, const char*);
    void (KENSHILUA_CALL *pushLString)(struct lua_State*, const char*, size_t);
    void (KENSHILUA_CALL *pushBoolean)(struct lua_State*, int);
    double (KENSHILUA_CALL *toNumber)(struct lua_State*, int);
    ptrdiff_t (KENSHILUA_CALL *toInteger)(struct lua_State*, int);
    int (KENSHILUA_CALL *toBoolean)(struct lua_State*, int);
    const char* (KENSHILUA_CALL *toLString)(struct lua_State*, int, size_t*);
    int (KENSHILUA_CALL *type)(struct lua_State*, int);
    int (KENSHILUA_CALL *getTop)(struct lua_State*);
    void (KENSHILUA_CALL *setTop)(struct lua_State*, int);
    void (KENSHILUA_CALL *newTable)(struct lua_State*);
    void (KENSHILUA_CALL *pushCFunction)(struct lua_State*, lua_CFunction);
    void (KENSHILUA_CALL *pushValue)(struct lua_State*, int);
    void (KENSHILUA_CALL *getField)(struct lua_State*, int, const char*);
    void (KENSHILUA_CALL *setField)(struct lua_State*, int, const char*);
    void (KENSHILUA_CALL *getGlobal)(struct lua_State*, const char*);
    void (KENSHILUA_CALL *setGlobal)(struct lua_State*, const char*);
    void (KENSHILUA_CALL *registerFunctions)(struct lua_State*, const KenshiLua_Reg*);
};

#pragma pack(pop)

typedef int (KENSHILUA_CALL *KenshiLua_GetApiFunction)(
    unsigned int requestedVersion,
    KenshiLua_ApiV1* outApi,
    size_t outApiSize);

#ifdef KENSHILUA_BUILDING_DLL
extern "C" __declspec(dllexport) int KENSHILUA_CALL KenshiLua_GetApi(
    unsigned int requestedVersion,
    KenshiLua_ApiV1* outApi,
    size_t outApiSize);
#endif

/* KENSHILUA_GENERATED_FORWARD_DECLARATIONS_BEGIN */
class AABB2D;
class AbstractMovementBase;
class ActivePlatoon;
struct AkSoundPosition;
struct AkVector;
class AnimalInventoryLayout;
class AppearanceAnimal;
class AppearanceBase;
class AppearanceHuman;
class Armour;
class BackThreadMessagesToMainT;
class BackpackInventoryLayout;
class Bounty;
class BountyManager;
class BuildInventoryLayout;
class BuildModeWindow;
class Building;
class BuildingContainerInventoryLayout;
class BuildingPlacementGroundType;
class CPerfTimer;
class CPerfTimerT;
class CameraClass;
class CampaignTriggerData;
class CharBody;
class CharMovement;
class CharStats;
class Character;
class CharacterAnimal;
class CharacterEditWindow;
class CharacterHuman;
class CharacterInventoryLayout;
class CharacterStatsWindow;
class CharacterTradingWindow;
class CombatClass;
class CombatMovementController;
class CombatTechniqueData;
class ContainerItem;
class ContextMenu;
class ContextMenuGUI;
class CraftingBuilding;
class CraftingInventoryLayout;
class Crossbow;
class Damages;
class DataObjectContainer;
class DataPanelLine;
class DataPanelLine_Button;
class DataPanelLine_CheckBox;
class DataPanelLine_DropBox;
class DataPanelLine_Faction;
class DataPanelLine_KeyConfig;
class DataPanelLine_Progress;
class DataPanelLine_Research;
class DataPanelLine_Slider;
class DataPanelLine_SliderEditable;
class DataPanelLine_Text;
class DataPanelLine_TextEditable;
class DatapanelGUI;
class DialogChoiceList;
class DialogDataManager;
class DialogLineData;
class Dialogue;
class DialogueSpeechBubble;
class DialogueWindow;
class DoorStuff;
struct EdgeCache;
struct EdgePathNode;
class Faction;
class FactionLeader;
class FactionManager;
class FactionRelations;
class FactionUniqueSquadManager;
class FactionWarMgr;
class FactionsScreen;
class FactoryCallbackInterface;
class FarmBuilding;
class FloatingProgressBar;
class FlockingTools;
class FogEditor;
class FoliageSystem;
class ForgottenGUI;
class FormationMover;
class FurnaceBuilding;
class FurnaceInventoryLayout;
class GUIWindow;
class GameData;
class GameDataContainer;
class GameDataCopyStandalone;
class GameDataEditorWindow;
class GameDataGroup;
class GameDataHeader;
class GameDataManager;
class GameDataReference;
class GameDataValuePair;
class GameSaveState;
class GameWorld;
class GameplayOptions;
class GatewayBuilding;
class Gear;
class GeneratorBuilding;
class GenericFixedInventoryLayout;
class GenericInventoryLayout;
class GlobalConstants;
class HavokCharacter;
class ImportGameMenu;
class InputHandler;
class InstanceID;
class InteriorModeButtonWindow;
class Inventory;
class InventoryGUI;
class InventoryIcon;
class InventoryItemBase;
class InventoryLayout;
class InventorySection;
class InventorySectionGUI;
class InventoryTraderGUI;
class Item;
class LevelEditor;
class LightBuilding;
class LimbsInventoryLayout;
class LoadSaveWindow;
class LockedArmour;
class Logger;
class MainBarGUI;
class MainTabPortraitPlatoon;
class MainthreadStateReaderT;
class ManagementScreen;
class MapScreen;
class MedianFilter;
class MedianFilter2DVector;
class MedicalSystem;
class MeshDataLookup;
class MessageBoxManager;
class MessageForB;
class ModInfo;
class MotionFilter;
struct NavInstance;
class NavMesh;
class NavMeshGenerator;
class NavMeshSeeds;
class NewGameOptionsWindow;
class NewGameWindow;
class Nx9Real;
class NxBox;
class NxMat33;
class NxUserControllerHitReport;
class NxUserTriggerReport;
class NxVec3;
class OpenSaveFileDialog;
class OptionsHolder;
class OptionsWindow;
class OrderCellView;
class OrderData;
class OrdersItemBox;
class OrdersPanel;
class Ownerships;
class ParticlePool;
class PhysicalEntity;
class PhysicsActual;
class PhysicsCollection;
class PhysicsInterface;
class Platoon;
class PlayerInterface;
class PortraitData;
class PortraitImage;
class PortraitMainCellView;
class PreviewBuilding;
class ProductionBuilding;
class ProductionInventoryLayout;
class ProspectingWindow;
class ProsperityManager;
class RaceData;
class RaceLimiter;
class RainCollectorBuilding;
class ReorderableList;
class ResearchBuilding;
class ResearchBuildingInventoryLayout;
class RobotLimbs;
class RootObject;
class RootObjectBase;
class RootObjectContainer;
class RootObjectFactory;
class SaveFileSystem;
struct SaveInfo;
class SaveManager;
class ScreenLabel;
class ScreenLabelDebug;
class ScreenLabelInterface;
class SeenSomeone;
class SelectionBox;
class SenseItr;
class SensoryData;
class ShopTrader;
class ShopTraderInventory;
class ShopTraderInventorySection;
class SimpleTimeStamper;
class SpeedGroup;
class SplashScreen;
class SquadManagementScreen;
class StorageBuilding;
class StringPair;
class Sword;
class TaskData;
class TaskStateData;
class Tasker;
class Terrain;
class ThreadClass;
class ThreadWannabe;
class TimeOfDay;
class TimerClass;
class TitleScreen;
class ToolTip;
class ToolTipDynamic;
class ToolTipFixed;
class ToolTipInventory;
class ToolTipStatic;
class TortureBuilding;
class Town;
class TownBase;
class TownBuildingsManager;
class TradeCulture;
class TraderInventoryLayout;
class TransformWindow;
class TripleInt;
class TurretBuilding;
class TutorialGUI;
class TutorialItem;
class TutorialSubItem;
class TutorialpediaGUI;
class UseableStuff;
class UtilityT;
class VisibleObjectInfo;
class WallBuilding;
class Weapon;
class WeatherRegion;
class WindGeneratorBuilding;
class WorldEventStateQuery;
class WorldEventStateQueryList;
class YesNoMaybe;
class ZoneManager;
class ZoneManagerInterfaceT;
class ZoneMap;
class ZoneSpacialGrid;
class hkBool;
struct hkContainerHeapAllocator;
class hkMemoryAllocator;
struct hkResult;
class hkVector4f;
class hkVector4fComparison;
class iVector2;
class physHit;
class rendHit;
namespace KenshiLib
{
    class BinaryVersion;
}
namespace MyGUI
{
    class ListScrollBar;
    class MultiSlider;
    class Slider;
}
namespace wraps
{
    class BaseLayout;
}
/* KENSHILUA_GENERATED_FORWARD_DECLARATIONS_END */

namespace KenshiLua
{
    enum Status
    {
        STATUS_OK = KENSHILUA_STATUS_OK,
        STATUS_NOT_INITIALIZED = KENSHILUA_STATUS_NOT_INITIALIZED,
        STATUS_INVALID_ARGUMENT = KENSHILUA_STATUS_INVALID_ARGUMENT,
        STATUS_FILE_NOT_FOUND = KENSHILUA_STATUS_FILE_NOT_FOUND,
        STATUS_LUA_SYNTAX_ERROR = KENSHILUA_STATUS_LUA_SYNTAX_ERROR,
        STATUS_LUA_RUNTIME_ERROR = KENSHILUA_STATUS_LUA_RUNTIME_ERROR,
        STATUS_LUA_MEMORY_ERROR = KENSHILUA_STATUS_LUA_MEMORY_ERROR,
        STATUS_UNSUPPORTED_VERSION = KENSHILUA_STATUS_UNSUPPORTED_VERSION,
        STATUS_WRONG_THREAD = KENSHILUA_STATUS_WRONG_THREAD,
        STATUS_UNKNOWN_ERROR = KENSHILUA_STATUS_UNKNOWN_ERROR
    };

    typedef KenshiLua_Reg Reg;

    namespace Detail
    {
        struct ApiCache
        {
            volatile LONG lock;
            HMODULE module;
            KenshiLua_ApiV1 api;
            bool available;
            int lastStatus;
        };

        class CacheLock
        {
        public:
            explicit CacheLock(ApiCache& cache) : m_cache(cache)
            {
                while (InterlockedCompareExchange(&m_cache.lock, 1, 0) != 0)
                    Sleep(0);
            }

            ~CacheLock()
            {
                InterlockedExchange(&m_cache.lock, 0);
            }

        private:
            CacheLock(const CacheLock&);
            CacheLock& operator=(const CacheLock&);
            ApiCache& m_cache;
        };

        inline ApiCache& GetCache()
        {
            static ApiCache cache = {
                0, NULL, { 0 }, false, KENSHILUA_STATUS_NOT_INITIALIZED
            };
            return cache;
        }

        inline void ClearCache(ApiCache& cache)
        {
            cache.module = NULL;
            cache.available = false;
            cache.lastStatus = KENSHILUA_STATUS_NOT_INITIALIZED;
            std::memset(&cache.api, 0, sizeof(cache.api));
        }

        inline KenshiLua_ApiV1* GetApi()
        {
            ApiCache& cache = GetCache();
            CacheLock lock(cache);
            HMODULE module = GetModuleHandleA("KenshiLua.dll");
            if (!module)
            {
                ClearCache(cache);
                return NULL;
            }

            if (cache.available && cache.module == module)
                return &cache.api;

            KenshiLua_GetApiFunction getApi = reinterpret_cast<KenshiLua_GetApiFunction>(
                GetProcAddress(module, "KenshiLua_GetApi"));
            if (!getApi)
            {
                ClearCache(cache);
                cache.module = module;
                cache.lastStatus = KENSHILUA_STATUS_UNSUPPORTED_VERSION;
                return NULL;
            }

            KenshiLua_ApiV1 candidate;
            std::memset(&candidate, 0, sizeof(candidate));
            int status = getApi(KENSHILUA_ABI_VERSION, &candidate, sizeof(candidate));
            if (status != KENSHILUA_STATUS_OK ||
                candidate.abiVersion != KENSHILUA_ABI_VERSION ||
                candidate.structSize < sizeof(KenshiLua_ApiV1))
            {
                ClearCache(cache);
                cache.module = module;
                cache.lastStatus = status == KENSHILUA_STATUS_OK ?
                    KENSHILUA_STATUS_UNSUPPORTED_VERSION : status;
                return NULL;
            }

            cache.module = module;
            cache.api = candidate;
            cache.available = true;
            cache.lastStatus = KENSHILUA_STATUS_OK;
            return &cache.api;
        }

        inline int GetLastStatus()
        {
            ApiCache& cache = GetCache();
            CacheLock lock(cache);
            return cache.lastStatus;
        }

        inline void SetError(std::string* outError, const char* message)
        {
            if (outError)
                *outError = message ? message : "";
        }

        inline Status Unavailable(std::string* outError)
        {
            if (GetLastStatus() == KENSHILUA_STATUS_UNSUPPORTED_VERSION)
            {
                SetError(outError, "KenshiLua does not support this SDK ABI version");
                return STATUS_UNSUPPORTED_VERSION;
            }
            SetError(outError, "KenshiLua is not available or is not initialized");
            return STATUS_NOT_INITIALIZED;
        }
    }

    inline bool IsAvailable()
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->isInitialized && api->isInitialized() != 0;
    }

    inline struct lua_State* GetState()
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->getState ? api->getState() : NULL;
    }

    inline std::string GetVersion()
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        const char* version = api && api->getVersion ? api->getVersion() : NULL;
        return version ? std::string(version) : std::string();
    }

    inline int GetVersionMajor()
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->getVersionMajor ? api->getVersionMajor() : -1;
    }

    inline int GetVersionMinor()
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->getVersionMinor ? api->getVersionMinor() : -1;
    }

    inline int GetVersionPatch()
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->getVersionPatch ? api->getVersionPatch() : -1;
    }

    inline Status RunScript(const std::string& scriptPath, std::string* outError = NULL)
    {
        if (outError) outError->clear();
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->runScript) return Detail::Unavailable(outError);
        char error[4096] = { 0 };
        int status = api->runScript(scriptPath.c_str(), error, sizeof(error));
        if (status != STATUS_OK) Detail::SetError(outError, error);
        return static_cast<Status>(status);
    }

    inline Status DoString(const std::string& code, const std::string& chunkName = "eval",
        std::string* outError = NULL)
    {
        if (outError) outError->clear();
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->runString) return Detail::Unavailable(outError);
        char error[4096] = { 0 };
        int status = api->runString(code.c_str(), chunkName.c_str(), error, sizeof(error));
        if (status != STATUS_OK) Detail::SetError(outError, error);
        return static_cast<Status>(status);
    }

    inline Status DispatchEvent(const std::string& eventName, int nargs = 0,
        std::string* outError = NULL)
    {
        if (outError) outError->clear();
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->dispatchEvent) return Detail::Unavailable(outError);
        char error[4096] = { 0 };
        int status = api->dispatchEvent(eventName.c_str(), nargs, error, sizeof(error));
        if (status != STATUS_OK) Detail::SetError(outError, error);
        return static_cast<Status>(status);
    }

    inline Status RegisterFunction(const std::string& name, lua_CFunction function,
        std::string* outError = NULL)
    {
        if (outError) outError->clear();
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->registerFunction) return Detail::Unavailable(outError);
        char error[4096] = { 0 };
        int status = api->registerFunction(name.c_str(), function, error, sizeof(error));
        if (status != STATUS_OK) Detail::SetError(outError, error);
        return static_cast<Status>(status);
    }

    inline Status RegisterModule(const std::string& name, lua_CFunction openFunction,
        std::string* outError = NULL)
    {
        if (outError) outError->clear();
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->registerModule) return Detail::Unavailable(outError);
        char error[4096] = { 0 };
        int status = api->registerModule(name.c_str(), openFunction, error, sizeof(error));
        if (status != STATUS_OK) Detail::SetError(outError, error);
        return static_cast<Status>(status);
    }

    inline std::string ResolveScriptPath(const std::string& scriptPath)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->resolveScriptPath) return std::string();
        char path[4096] = { 0 };
        int status = api->resolveScriptPath(scriptPath.c_str(), path, sizeof(path));
        return status == STATUS_OK ? std::string(path) : std::string();
    }

    inline void LogInfo(const std::string& message)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->logInfo) api->logInfo(message.c_str());
    }

    inline void LogWarning(const std::string& message)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->logWarning) api->logWarning(message.c_str());
    }

    inline void LogError(const std::string& message)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->logError) api->logError(message.c_str());
    }

    inline void LogDebug(const std::string& message)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->logDebug) api->logDebug(message.c_str());
    }

    inline Status PushObject(struct lua_State* L, void* pointer, const char* metatableName)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->pushObject) return STATUS_NOT_INITIALIZED;
        return static_cast<Status>(api->pushObject(L, pointer, metatableName));
    }

    inline void* CheckObject(struct lua_State* L, int index, const char* metatableName)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->checkObject ? api->checkObject(L, index, metatableName) : NULL;
    }

    inline void* TestObject(struct lua_State* L, int index, const char* metatableName)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->testObject ? api->testObject(L, index, metatableName) : NULL;
    }

    inline void PushNil(struct lua_State* L)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushNil && L) api->pushNil(L);
    }

    inline void Push(struct lua_State* L, double value)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushNumber && L) api->pushNumber(L, value);
    }

    inline void Push(struct lua_State* L, float value) { Push(L, static_cast<double>(value)); }

    inline void Push(struct lua_State* L, int value)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushInteger && L) api->pushInteger(L, value);
    }

    inline void Push(struct lua_State* L, bool value)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushBoolean && L) api->pushBoolean(L, value ? 1 : 0);
    }

    inline void Push(struct lua_State* L, const char* value)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !L) return;
        if (value)
        {
            if (api->pushString) api->pushString(L, value);
        }
        else if (api->pushNil)
        {
            api->pushNil(L);
        }
    }

    inline void Push(struct lua_State* L, char* value)
    {
        Push(L, static_cast<const char*>(value));
    }

    inline void Push(struct lua_State* L, const std::string& value)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushLString && L) api->pushLString(L, value.data(), value.size());
    }

    inline double GetNumber(struct lua_State* L, int index)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->toNumber && L ? api->toNumber(L, index) : 0.0;
    }

    inline int GetInteger(struct lua_State* L, int index)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->toInteger && L ? static_cast<int>(api->toInteger(L, index)) : 0;
    }

    inline bool GetBoolean(struct lua_State* L, int index)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->toBoolean && L ? api->toBoolean(L, index) != 0 : false;
    }

    inline std::string GetString(struct lua_State* L, int index)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (!api || !api->toLString || !L) return std::string();
        size_t length = 0;
        const char* value = api->toLString(L, index, &length);
        return value ? std::string(value, length) : std::string();
    }

    inline int GetTop(struct lua_State* L)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        return api && api->getTop && L ? api->getTop(L) : 0;
    }

    inline void SetTop(struct lua_State* L, int index)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->setTop && L) api->setTop(L, index);
    }

    inline void Pop(struct lua_State* L, int count)
    {
        if (count > 0) SetTop(L, -count - 1);
    }

    inline void NewTable(struct lua_State* L)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->newTable && L) api->newTable(L);
    }

    inline void PushFunction(struct lua_State* L, lua_CFunction function)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushCFunction && L && function) api->pushCFunction(L, function);
    }

    inline void PushValue(struct lua_State* L, int index)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->pushValue && L) api->pushValue(L, index);
    }

    inline void GetField(struct lua_State* L, int index, const char* name)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->getField && L && name) api->getField(L, index, name);
    }

    inline void SetField(struct lua_State* L, int index, const char* name)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->setField && L && name) api->setField(L, index, name);
    }

    inline void GetGlobal(struct lua_State* L, const char* name)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->getGlobal && L && name) api->getGlobal(L, name);
    }

    inline void SetGlobal(struct lua_State* L, const char* name)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->setGlobal && L && name) api->setGlobal(L, name);
    }

    inline void RegisterFunctions(struct lua_State* L, const Reg* functions)
    {
        KenshiLua_ApiV1* api = Detail::GetApi();
        if (api && api->registerFunctions && L && functions)
            api->registerFunctions(L, functions);
    }

    template <typename T>
    struct TypeTraits
    {
        static const char* Metatable() { return NULL; }
    };

    /* KENSHILUA_GENERATED_TYPE_TRAITS_BEGIN */
    template <> struct TypeTraits<AABB2D> { static const char* Metatable() { return "KenshiLua.AABB2D"; } };
    template <> struct TypeTraits<AbstractMovementBase> { static const char* Metatable() { return "KenshiLua.AbstractMovementBase"; } };
    template <> struct TypeTraits<ActivePlatoon> { static const char* Metatable() { return "KenshiLua.ActivePlatoon"; } };
    template <> struct TypeTraits<AkSoundPosition> { static const char* Metatable() { return "KenshiLua.AkSoundPosition"; } };
    template <> struct TypeTraits<AkVector> { static const char* Metatable() { return "KenshiLua.AkVector"; } };
    template <> struct TypeTraits<AnimalInventoryLayout> { static const char* Metatable() { return "KenshiLua.AnimalInventoryLayout"; } };
    template <> struct TypeTraits<AppearanceAnimal> { static const char* Metatable() { return "KenshiLua.AppearanceAnimal"; } };
    template <> struct TypeTraits<AppearanceBase> { static const char* Metatable() { return "KenshiLua.AppearanceBase"; } };
    template <> struct TypeTraits<AppearanceHuman> { static const char* Metatable() { return "KenshiLua.AppearanceHuman"; } };
    template <> struct TypeTraits<Armour> { static const char* Metatable() { return "KenshiLua.Armour"; } };
    template <> struct TypeTraits<BackThreadMessagesToMainT> { static const char* Metatable() { return "KenshiLua.BackThreadMessagesToMainT"; } };
    template <> struct TypeTraits<BackpackInventoryLayout> { static const char* Metatable() { return "KenshiLua.BackpackInventoryLayout"; } };
    template <> struct TypeTraits<Bounty> { static const char* Metatable() { return "KenshiLua.Bounty"; } };
    template <> struct TypeTraits<BountyManager> { static const char* Metatable() { return "KenshiLua.BountyManager"; } };
    template <> struct TypeTraits<BuildInventoryLayout> { static const char* Metatable() { return "KenshiLua.BuildInventoryLayout"; } };
    template <> struct TypeTraits<BuildModeWindow> { static const char* Metatable() { return "KenshiLua.BuildModeWindow"; } };
    template <> struct TypeTraits<Building> { static const char* Metatable() { return "KenshiLua.Building"; } };
    template <> struct TypeTraits<BuildingContainerInventoryLayout> { static const char* Metatable() { return "KenshiLua.BuildingContainerInventoryLayout"; } };
    template <> struct TypeTraits<BuildingPlacementGroundType> { static const char* Metatable() { return "KenshiLua.BuildingPlacementGroundType"; } };
    template <> struct TypeTraits<CPerfTimer> { static const char* Metatable() { return "KenshiLua.CPerfTimer"; } };
    template <> struct TypeTraits<CPerfTimerT> { static const char* Metatable() { return "KenshiLua.CPerfTimerT"; } };
    template <> struct TypeTraits<CameraClass> { static const char* Metatable() { return "KenshiLua.CameraClass"; } };
    template <> struct TypeTraits<CampaignTriggerData> { static const char* Metatable() { return "KenshiLua.CampaignTriggerData"; } };
    template <> struct TypeTraits<CharBody> { static const char* Metatable() { return "KenshiLua.CharBody"; } };
    template <> struct TypeTraits<CharMovement> { static const char* Metatable() { return "KenshiLua.CharMovement"; } };
    template <> struct TypeTraits<CharStats> { static const char* Metatable() { return "KenshiLua.CharStats"; } };
    template <> struct TypeTraits<Character> { static const char* Metatable() { return "KenshiLua.Character"; } };
    template <> struct TypeTraits<CharacterAnimal> { static const char* Metatable() { return "KenshiLua.CharacterAnimal"; } };
    template <> struct TypeTraits<CharacterEditWindow> { static const char* Metatable() { return "KenshiLua.CharacterEditWindow"; } };
    template <> struct TypeTraits<CharacterHuman> { static const char* Metatable() { return "KenshiLua.CharacterHuman"; } };
    template <> struct TypeTraits<CharacterInventoryLayout> { static const char* Metatable() { return "KenshiLua.CharacterInventoryLayout"; } };
    template <> struct TypeTraits<CharacterStatsWindow> { static const char* Metatable() { return "KenshiLua.CharacterStatsWindow"; } };
    template <> struct TypeTraits<CharacterTradingWindow> { static const char* Metatable() { return "KenshiLua.CharacterTradingWindow"; } };
    template <> struct TypeTraits<CombatClass> { static const char* Metatable() { return "KenshiLua.CombatClass"; } };
    template <> struct TypeTraits<CombatMovementController> { static const char* Metatable() { return "KenshiLua.CombatMovementController"; } };
    template <> struct TypeTraits<CombatTechniqueData> { static const char* Metatable() { return "KenshiLua.CombatTechniqueData"; } };
    template <> struct TypeTraits<ContainerItem> { static const char* Metatable() { return "KenshiLua.ContainerItem"; } };
    template <> struct TypeTraits<ContextMenu> { static const char* Metatable() { return "KenshiLua.ContextMenu"; } };
    template <> struct TypeTraits<ContextMenuGUI> { static const char* Metatable() { return "KenshiLua.ContextMenuGUI"; } };
    template <> struct TypeTraits<CraftingBuilding> { static const char* Metatable() { return "KenshiLua.CraftingBuilding"; } };
    template <> struct TypeTraits<CraftingInventoryLayout> { static const char* Metatable() { return "KenshiLua.CraftingInventoryLayout"; } };
    template <> struct TypeTraits<Crossbow> { static const char* Metatable() { return "KenshiLua.Crossbow"; } };
    template <> struct TypeTraits<Damages> { static const char* Metatable() { return "KenshiLua.Damages"; } };
    template <> struct TypeTraits<DataObjectContainer> { static const char* Metatable() { return "KenshiLua.DataObjectContainer"; } };
    template <> struct TypeTraits<DataPanelLine> { static const char* Metatable() { return "KenshiLua.DataPanelLine"; } };
    template <> struct TypeTraits<DataPanelLine_Button> { static const char* Metatable() { return "KenshiLua.DataPanelLine_Button"; } };
    template <> struct TypeTraits<DataPanelLine_CheckBox> { static const char* Metatable() { return "KenshiLua.DataPanelLine_CheckBox"; } };
    template <> struct TypeTraits<DataPanelLine_DropBox> { static const char* Metatable() { return "KenshiLua.DataPanelLine_DropBox"; } };
    template <> struct TypeTraits<DataPanelLine_Faction> { static const char* Metatable() { return "KenshiLua.DataPanelLine_Faction"; } };
    template <> struct TypeTraits<DataPanelLine_KeyConfig> { static const char* Metatable() { return "KenshiLua.DataPanelLine_KeyConfig"; } };
    template <> struct TypeTraits<DataPanelLine_Progress> { static const char* Metatable() { return "KenshiLua.DataPanelLine_Progress"; } };
    template <> struct TypeTraits<DataPanelLine_Research> { static const char* Metatable() { return "KenshiLua.DataPanelLine_Research"; } };
    template <> struct TypeTraits<DataPanelLine_Slider> { static const char* Metatable() { return "KenshiLua.DataPanelLine_Slider"; } };
    template <> struct TypeTraits<DataPanelLine_SliderEditable> { static const char* Metatable() { return "KenshiLua.DataPanelLine_SliderEditable"; } };
    template <> struct TypeTraits<DataPanelLine_Text> { static const char* Metatable() { return "KenshiLua.DataPanelLine_Text"; } };
    template <> struct TypeTraits<DataPanelLine_TextEditable> { static const char* Metatable() { return "KenshiLua.DataPanelLine_TextEditable"; } };
    template <> struct TypeTraits<DatapanelGUI> { static const char* Metatable() { return "KenshiLua.DatapanelGUI"; } };
    template <> struct TypeTraits<DialogChoiceList> { static const char* Metatable() { return "KenshiLua.DialogChoiceList"; } };
    template <> struct TypeTraits<DialogDataManager> { static const char* Metatable() { return "KenshiLua.DialogDataManager"; } };
    template <> struct TypeTraits<DialogLineData> { static const char* Metatable() { return "KenshiLua.DialogLineData"; } };
    template <> struct TypeTraits<Dialogue> { static const char* Metatable() { return "KenshiLua.Dialogue"; } };
    template <> struct TypeTraits<DialogueSpeechBubble> { static const char* Metatable() { return "KenshiLua.DialogueSpeechBubble"; } };
    template <> struct TypeTraits<DialogueWindow> { static const char* Metatable() { return "KenshiLua.DialogueWindow"; } };
    template <> struct TypeTraits<DoorStuff> { static const char* Metatable() { return "KenshiLua.DoorStuff"; } };
    template <> struct TypeTraits<EdgeCache> { static const char* Metatable() { return "KenshiLua.EdgeCache"; } };
    template <> struct TypeTraits<EdgePathNode> { static const char* Metatable() { return "KenshiLua.EdgePathNode"; } };
    template <> struct TypeTraits<Faction> { static const char* Metatable() { return "KenshiLua.Faction"; } };
    template <> struct TypeTraits<FactionLeader> { static const char* Metatable() { return "KenshiLua.FactionLeader"; } };
    template <> struct TypeTraits<FactionManager> { static const char* Metatable() { return "KenshiLua.FactionManager"; } };
    template <> struct TypeTraits<FactionRelations> { static const char* Metatable() { return "KenshiLua.FactionRelations"; } };
    template <> struct TypeTraits<FactionUniqueSquadManager> { static const char* Metatable() { return "KenshiLua.FactionUniqueSquadManager"; } };
    template <> struct TypeTraits<FactionWarMgr> { static const char* Metatable() { return "KenshiLua.FactionWarMgr"; } };
    template <> struct TypeTraits<FactionsScreen> { static const char* Metatable() { return "KenshiLua.FactionsScreen"; } };
    template <> struct TypeTraits<FactoryCallbackInterface> { static const char* Metatable() { return "KenshiLua.FactoryCallbackInterface"; } };
    template <> struct TypeTraits<FarmBuilding> { static const char* Metatable() { return "KenshiLua.FarmBuilding"; } };
    template <> struct TypeTraits<FloatingProgressBar> { static const char* Metatable() { return "KenshiLua.FloatingProgressBar"; } };
    template <> struct TypeTraits<FlockingTools> { static const char* Metatable() { return "KenshiLua.FlockingTools"; } };
    template <> struct TypeTraits<FogEditor> { static const char* Metatable() { return "KenshiLua.FogEditor"; } };
    template <> struct TypeTraits<FoliageSystem> { static const char* Metatable() { return "KenshiLua.FoliageSystem"; } };
    template <> struct TypeTraits<ForgottenGUI> { static const char* Metatable() { return "KenshiLua.ForgottenGUI"; } };
    template <> struct TypeTraits<FormationMover> { static const char* Metatable() { return "KenshiLua.FormationMover"; } };
    template <> struct TypeTraits<FurnaceBuilding> { static const char* Metatable() { return "KenshiLua.FurnaceBuilding"; } };
    template <> struct TypeTraits<FurnaceInventoryLayout> { static const char* Metatable() { return "KenshiLua.FurnaceInventoryLayout"; } };
    template <> struct TypeTraits<GUIWindow> { static const char* Metatable() { return "KenshiLua.GUIWindow"; } };
    template <> struct TypeTraits<GameData> { static const char* Metatable() { return "KenshiLua.GameData"; } };
    template <> struct TypeTraits<GameDataContainer> { static const char* Metatable() { return "KenshiLua.GameDataContainer"; } };
    template <> struct TypeTraits<GameDataCopyStandalone> { static const char* Metatable() { return "KenshiLua.GameDataCopyStandalone"; } };
    template <> struct TypeTraits<GameDataEditorWindow> { static const char* Metatable() { return "KenshiLua.GameDataEditorWindow"; } };
    template <> struct TypeTraits<GameDataGroup> { static const char* Metatable() { return "KenshiLua.GameDataGroup"; } };
    template <> struct TypeTraits<GameDataHeader> { static const char* Metatable() { return "KenshiLua.GameDataHeader"; } };
    template <> struct TypeTraits<GameDataManager> { static const char* Metatable() { return "KenshiLua.GameDataManager"; } };
    template <> struct TypeTraits<GameDataReference> { static const char* Metatable() { return "KenshiLua.GameDataReference"; } };
    template <> struct TypeTraits<GameDataValuePair> { static const char* Metatable() { return "KenshiLua.GameDataValuePair"; } };
    template <> struct TypeTraits<GameSaveState> { static const char* Metatable() { return "KenshiLua.GameSaveState"; } };
    template <> struct TypeTraits<GameWorld> { static const char* Metatable() { return "KenshiLua.GameWorld"; } };
    template <> struct TypeTraits<GameplayOptions> { static const char* Metatable() { return "KenshiLua.GameplayOptions"; } };
    template <> struct TypeTraits<GatewayBuilding> { static const char* Metatable() { return "KenshiLua.GatewayBuilding"; } };
    template <> struct TypeTraits<Gear> { static const char* Metatable() { return "KenshiLua.Gear"; } };
    template <> struct TypeTraits<GeneratorBuilding> { static const char* Metatable() { return "KenshiLua.GeneratorBuilding"; } };
    template <> struct TypeTraits<GenericFixedInventoryLayout> { static const char* Metatable() { return "KenshiLua.GenericFixedInventoryLayout"; } };
    template <> struct TypeTraits<GenericInventoryLayout> { static const char* Metatable() { return "KenshiLua.GenericInventoryLayout"; } };
    template <> struct TypeTraits<GlobalConstants> { static const char* Metatable() { return "KenshiLua.GlobalConstants"; } };
    template <> struct TypeTraits<HavokCharacter> { static const char* Metatable() { return "KenshiLua.HavokCharacter"; } };
    template <> struct TypeTraits<ImportGameMenu> { static const char* Metatable() { return "KenshiLua.ImportGameMenu"; } };
    template <> struct TypeTraits<InputHandler> { static const char* Metatable() { return "KenshiLua.InputHandler"; } };
    template <> struct TypeTraits<InstanceID> { static const char* Metatable() { return "KenshiLua.InstanceID"; } };
    template <> struct TypeTraits<InteriorModeButtonWindow> { static const char* Metatable() { return "KenshiLua.InteriorModeButtonWindow"; } };
    template <> struct TypeTraits<Inventory> { static const char* Metatable() { return "KenshiLua.Inventory"; } };
    template <> struct TypeTraits<InventoryGUI> { static const char* Metatable() { return "KenshiLua.InventoryGUI"; } };
    template <> struct TypeTraits<InventoryIcon> { static const char* Metatable() { return "KenshiLua.InventoryIcon"; } };
    template <> struct TypeTraits<InventoryItemBase> { static const char* Metatable() { return "KenshiLua.InventoryItemBase"; } };
    template <> struct TypeTraits<InventoryLayout> { static const char* Metatable() { return "KenshiLua.InventoryLayout"; } };
    template <> struct TypeTraits<InventorySection> { static const char* Metatable() { return "KenshiLua.InventorySection"; } };
    template <> struct TypeTraits<InventorySectionGUI> { static const char* Metatable() { return "KenshiLua.InventorySectionGUI"; } };
    template <> struct TypeTraits<InventoryTraderGUI> { static const char* Metatable() { return "KenshiLua.InventoryTraderGUI"; } };
    template <> struct TypeTraits<Item> { static const char* Metatable() { return "KenshiLua.Item"; } };
    template <> struct TypeTraits<KenshiLib::BinaryVersion> { static const char* Metatable() { return "KenshiLua.BinaryVersion"; } };
    template <> struct TypeTraits<LevelEditor> { static const char* Metatable() { return "KenshiLua.LevelEditor"; } };
    template <> struct TypeTraits<LightBuilding> { static const char* Metatable() { return "KenshiLua.LightBuilding"; } };
    template <> struct TypeTraits<LimbsInventoryLayout> { static const char* Metatable() { return "KenshiLua.LimbsInventoryLayout"; } };
    template <> struct TypeTraits<LoadSaveWindow> { static const char* Metatable() { return "KenshiLua.LoadSaveWindow"; } };
    template <> struct TypeTraits<LockedArmour> { static const char* Metatable() { return "KenshiLua.LockedArmour"; } };
    template <> struct TypeTraits<Logger> { static const char* Metatable() { return "KenshiLua.Logger"; } };
    template <> struct TypeTraits<MainBarGUI> { static const char* Metatable() { return "KenshiLua.MainBarGUI"; } };
    template <> struct TypeTraits<MainTabPortraitPlatoon> { static const char* Metatable() { return "KenshiLua.MainTabPortraitPlatoon"; } };
    template <> struct TypeTraits<MainthreadStateReaderT> { static const char* Metatable() { return "KenshiLua.MainthreadStateReaderT"; } };
    template <> struct TypeTraits<ManagementScreen> { static const char* Metatable() { return "KenshiLua.ManagementScreen"; } };
    template <> struct TypeTraits<MapScreen> { static const char* Metatable() { return "KenshiLua.MapScreen"; } };
    template <> struct TypeTraits<MedianFilter> { static const char* Metatable() { return "KenshiLua.MedianFilter"; } };
    template <> struct TypeTraits<MedianFilter2DVector> { static const char* Metatable() { return "KenshiLua.MedianFilter2DVector"; } };
    template <> struct TypeTraits<MedicalSystem> { static const char* Metatable() { return "KenshiLua.MedicalSystem"; } };
    template <> struct TypeTraits<MeshDataLookup> { static const char* Metatable() { return "KenshiLua.MeshDataLookup"; } };
    template <> struct TypeTraits<MessageBoxManager> { static const char* Metatable() { return "KenshiLua.MessageBoxManager"; } };
    template <> struct TypeTraits<MessageForB> { static const char* Metatable() { return "KenshiLua.MessageForB"; } };
    template <> struct TypeTraits<ModInfo> { static const char* Metatable() { return "KenshiLua.ModInfo"; } };
    template <> struct TypeTraits<MotionFilter> { static const char* Metatable() { return "KenshiLua.MotionFilter"; } };
    template <> struct TypeTraits<MyGUI::ListScrollBar> { static const char* Metatable() { return "KenshiLua.ListScrollBar"; } };
    template <> struct TypeTraits<MyGUI::MultiSlider> { static const char* Metatable() { return "KenshiLua.MultiSlider"; } };
    template <> struct TypeTraits<MyGUI::Slider> { static const char* Metatable() { return "KenshiLua.Slider"; } };
    template <> struct TypeTraits<NavInstance> { static const char* Metatable() { return "KenshiLua.NavInstance"; } };
    template <> struct TypeTraits<NavMesh> { static const char* Metatable() { return "KenshiLua.NavMesh"; } };
    template <> struct TypeTraits<NavMeshGenerator> { static const char* Metatable() { return "KenshiLua.NavMeshGenerator"; } };
    template <> struct TypeTraits<NavMeshSeeds> { static const char* Metatable() { return "KenshiLua.NavMeshSeeds"; } };
    template <> struct TypeTraits<NewGameOptionsWindow> { static const char* Metatable() { return "KenshiLua.NewGameOptionsWindow"; } };
    template <> struct TypeTraits<NewGameWindow> { static const char* Metatable() { return "KenshiLua.NewGameWindow"; } };
    template <> struct TypeTraits<Nx9Real> { static const char* Metatable() { return "KenshiLua.Nx9Real"; } };
    template <> struct TypeTraits<NxBox> { static const char* Metatable() { return "KenshiLua.NxBox"; } };
    template <> struct TypeTraits<NxMat33> { static const char* Metatable() { return "KenshiLua.NxMat33"; } };
    template <> struct TypeTraits<NxUserControllerHitReport> { static const char* Metatable() { return "KenshiLua.NxUserControllerHitReport"; } };
    template <> struct TypeTraits<NxUserTriggerReport> { static const char* Metatable() { return "KenshiLua.NxUserTriggerReport"; } };
    template <> struct TypeTraits<NxVec3> { static const char* Metatable() { return "KenshiLua.NxVec3"; } };
    template <> struct TypeTraits<OpenSaveFileDialog> { static const char* Metatable() { return "KenshiLua.OpenSaveFileDialog"; } };
    template <> struct TypeTraits<OptionsHolder> { static const char* Metatable() { return "KenshiLua.OptionsHolder"; } };
    template <> struct TypeTraits<OptionsWindow> { static const char* Metatable() { return "KenshiLua.OptionsWindow"; } };
    template <> struct TypeTraits<OrderCellView> { static const char* Metatable() { return "KenshiLua.OrderCellView"; } };
    template <> struct TypeTraits<OrderData> { static const char* Metatable() { return "KenshiLua.OrderData"; } };
    template <> struct TypeTraits<OrdersItemBox> { static const char* Metatable() { return "KenshiLua.OrdersItemBox"; } };
    template <> struct TypeTraits<OrdersPanel> { static const char* Metatable() { return "KenshiLua.OrdersPanel"; } };
    template <> struct TypeTraits<Ownerships> { static const char* Metatable() { return "KenshiLua.Ownerships"; } };
    template <> struct TypeTraits<ParticlePool> { static const char* Metatable() { return "KenshiLua.ParticlePool"; } };
    template <> struct TypeTraits<PhysicalEntity> { static const char* Metatable() { return "KenshiLua.PhysicalEntity"; } };
    template <> struct TypeTraits<PhysicsActual> { static const char* Metatable() { return "KenshiLua.PhysicsActual"; } };
    template <> struct TypeTraits<PhysicsCollection> { static const char* Metatable() { return "KenshiLua.PhysicsCollection"; } };
    template <> struct TypeTraits<PhysicsInterface> { static const char* Metatable() { return "KenshiLua.PhysicsInterface"; } };
    template <> struct TypeTraits<Platoon> { static const char* Metatable() { return "KenshiLua.Platoon"; } };
    template <> struct TypeTraits<PlayerInterface> { static const char* Metatable() { return "KenshiLua.PlayerInterface"; } };
    template <> struct TypeTraits<PortraitData> { static const char* Metatable() { return "KenshiLua.PortraitData"; } };
    template <> struct TypeTraits<PortraitImage> { static const char* Metatable() { return "KenshiLua.PortraitImage"; } };
    template <> struct TypeTraits<PortraitMainCellView> { static const char* Metatable() { return "KenshiLua.PortraitMainCellView"; } };
    template <> struct TypeTraits<PreviewBuilding> { static const char* Metatable() { return "KenshiLua.PreviewBuilding"; } };
    template <> struct TypeTraits<ProductionBuilding> { static const char* Metatable() { return "KenshiLua.ProductionBuilding"; } };
    template <> struct TypeTraits<ProductionInventoryLayout> { static const char* Metatable() { return "KenshiLua.ProductionInventoryLayout"; } };
    template <> struct TypeTraits<ProspectingWindow> { static const char* Metatable() { return "KenshiLua.ProspectingWindow"; } };
    template <> struct TypeTraits<ProsperityManager> { static const char* Metatable() { return "KenshiLua.ProsperityManager"; } };
    template <> struct TypeTraits<RaceData> { static const char* Metatable() { return "KenshiLua.RaceData"; } };
    template <> struct TypeTraits<RaceLimiter> { static const char* Metatable() { return "KenshiLua.RaceLimiter"; } };
    template <> struct TypeTraits<RainCollectorBuilding> { static const char* Metatable() { return "KenshiLua.RainCollectorBuilding"; } };
    template <> struct TypeTraits<ReorderableList> { static const char* Metatable() { return "KenshiLua.ReorderableList"; } };
    template <> struct TypeTraits<ResearchBuilding> { static const char* Metatable() { return "KenshiLua.ResearchBuilding"; } };
    template <> struct TypeTraits<ResearchBuildingInventoryLayout> { static const char* Metatable() { return "KenshiLua.ResearchBuildingInventoryLayout"; } };
    template <> struct TypeTraits<RobotLimbs> { static const char* Metatable() { return "KenshiLua.RobotLimbs"; } };
    template <> struct TypeTraits<RootObject> { static const char* Metatable() { return "KenshiLua.RootObject"; } };
    template <> struct TypeTraits<RootObjectBase> { static const char* Metatable() { return "KenshiLua.RootObjectBase"; } };
    template <> struct TypeTraits<RootObjectContainer> { static const char* Metatable() { return "KenshiLua.RootObjectContainer"; } };
    template <> struct TypeTraits<RootObjectFactory> { static const char* Metatable() { return "KenshiLua.RootObjectFactory"; } };
    template <> struct TypeTraits<SaveFileSystem> { static const char* Metatable() { return "KenshiLua.SaveFileSystem"; } };
    template <> struct TypeTraits<SaveInfo> { static const char* Metatable() { return "KenshiLua.SaveInfo"; } };
    template <> struct TypeTraits<SaveManager> { static const char* Metatable() { return "KenshiLua.SaveManager"; } };
    template <> struct TypeTraits<ScreenLabel> { static const char* Metatable() { return "KenshiLua.ScreenLabel"; } };
    template <> struct TypeTraits<ScreenLabelDebug> { static const char* Metatable() { return "KenshiLua.ScreenLabelDebug"; } };
    template <> struct TypeTraits<ScreenLabelInterface> { static const char* Metatable() { return "KenshiLua.ScreenLabelInterface"; } };
    template <> struct TypeTraits<SeenSomeone> { static const char* Metatable() { return "KenshiLua.SeenSomeone"; } };
    template <> struct TypeTraits<SelectionBox> { static const char* Metatable() { return "KenshiLua.SelectionBox"; } };
    template <> struct TypeTraits<SenseItr> { static const char* Metatable() { return "KenshiLua.SenseItr"; } };
    template <> struct TypeTraits<SensoryData> { static const char* Metatable() { return "KenshiLua.SensoryData"; } };
    template <> struct TypeTraits<ShopTrader> { static const char* Metatable() { return "KenshiLua.ShopTrader"; } };
    template <> struct TypeTraits<ShopTraderInventory> { static const char* Metatable() { return "KenshiLua.ShopTraderInventory"; } };
    template <> struct TypeTraits<ShopTraderInventorySection> { static const char* Metatable() { return "KenshiLua.ShopTraderInventorySection"; } };
    template <> struct TypeTraits<SimpleTimeStamper> { static const char* Metatable() { return "KenshiLua.SimpleTimeStamper"; } };
    template <> struct TypeTraits<SpeedGroup> { static const char* Metatable() { return "KenshiLua.SpeedGroup"; } };
    template <> struct TypeTraits<SplashScreen> { static const char* Metatable() { return "KenshiLua.SplashScreen"; } };
    template <> struct TypeTraits<SquadManagementScreen> { static const char* Metatable() { return "KenshiLua.SquadManagementScreen"; } };
    template <> struct TypeTraits<StorageBuilding> { static const char* Metatable() { return "KenshiLua.StorageBuilding"; } };
    template <> struct TypeTraits<StringPair> { static const char* Metatable() { return "KenshiLua.StringPair"; } };
    template <> struct TypeTraits<Sword> { static const char* Metatable() { return "KenshiLua.Sword"; } };
    template <> struct TypeTraits<TaskData> { static const char* Metatable() { return "KenshiLua.TaskData"; } };
    template <> struct TypeTraits<TaskStateData> { static const char* Metatable() { return "KenshiLua.TaskStateData"; } };
    template <> struct TypeTraits<Tasker> { static const char* Metatable() { return "KenshiLua.Tasker"; } };
    template <> struct TypeTraits<Terrain> { static const char* Metatable() { return "KenshiLua.Terrain"; } };
    template <> struct TypeTraits<ThreadClass> { static const char* Metatable() { return "KenshiLua.ThreadClass"; } };
    template <> struct TypeTraits<ThreadWannabe> { static const char* Metatable() { return "KenshiLua.ThreadWannabe"; } };
    template <> struct TypeTraits<TimeOfDay> { static const char* Metatable() { return "KenshiLua.TimeOfDay"; } };
    template <> struct TypeTraits<TimerClass> { static const char* Metatable() { return "KenshiLua.TimerClass"; } };
    template <> struct TypeTraits<TitleScreen> { static const char* Metatable() { return "KenshiLua.TitleScreen"; } };
    template <> struct TypeTraits<ToolTip> { static const char* Metatable() { return "KenshiLua.ToolTip"; } };
    template <> struct TypeTraits<ToolTipDynamic> { static const char* Metatable() { return "KenshiLua.ToolTipDynamic"; } };
    template <> struct TypeTraits<ToolTipFixed> { static const char* Metatable() { return "KenshiLua.ToolTipFixed"; } };
    template <> struct TypeTraits<ToolTipInventory> { static const char* Metatable() { return "KenshiLua.ToolTipInventory"; } };
    template <> struct TypeTraits<ToolTipStatic> { static const char* Metatable() { return "KenshiLua.ToolTipStatic"; } };
    template <> struct TypeTraits<TortureBuilding> { static const char* Metatable() { return "KenshiLua.TortureBuilding"; } };
    template <> struct TypeTraits<Town> { static const char* Metatable() { return "KenshiLua.Town"; } };
    template <> struct TypeTraits<TownBase> { static const char* Metatable() { return "KenshiLua.TownBase"; } };
    template <> struct TypeTraits<TownBuildingsManager> { static const char* Metatable() { return "KenshiLua.TownBuildingsManager"; } };
    template <> struct TypeTraits<TradeCulture> { static const char* Metatable() { return "KenshiLua.TradeCulture"; } };
    template <> struct TypeTraits<TraderInventoryLayout> { static const char* Metatable() { return "KenshiLua.TraderInventoryLayout"; } };
    template <> struct TypeTraits<TransformWindow> { static const char* Metatable() { return "KenshiLua.TransformWindow"; } };
    template <> struct TypeTraits<TripleInt> { static const char* Metatable() { return "KenshiLua.TripleInt"; } };
    template <> struct TypeTraits<TurretBuilding> { static const char* Metatable() { return "KenshiLua.TurretBuilding"; } };
    template <> struct TypeTraits<TutorialGUI> { static const char* Metatable() { return "KenshiLua.TutorialGUI"; } };
    template <> struct TypeTraits<TutorialItem> { static const char* Metatable() { return "KenshiLua.TutorialItem"; } };
    template <> struct TypeTraits<TutorialSubItem> { static const char* Metatable() { return "KenshiLua.TutorialSubItem"; } };
    template <> struct TypeTraits<TutorialpediaGUI> { static const char* Metatable() { return "KenshiLua.TutorialpediaGUI"; } };
    template <> struct TypeTraits<UseableStuff> { static const char* Metatable() { return "KenshiLua.UseableStuff"; } };
    template <> struct TypeTraits<UtilityT> { static const char* Metatable() { return "KenshiLua.UtilityT"; } };
    template <> struct TypeTraits<VisibleObjectInfo> { static const char* Metatable() { return "KenshiLua.VisibleObjectInfo"; } };
    template <> struct TypeTraits<WallBuilding> { static const char* Metatable() { return "KenshiLua.WallBuilding"; } };
    template <> struct TypeTraits<Weapon> { static const char* Metatable() { return "KenshiLua.Weapon"; } };
    template <> struct TypeTraits<WeatherRegion> { static const char* Metatable() { return "KenshiLua.WeatherRegion"; } };
    template <> struct TypeTraits<WindGeneratorBuilding> { static const char* Metatable() { return "KenshiLua.WindGeneratorBuilding"; } };
    template <> struct TypeTraits<WorldEventStateQuery> { static const char* Metatable() { return "KenshiLua.WorldEventStateQuery"; } };
    template <> struct TypeTraits<WorldEventStateQueryList> { static const char* Metatable() { return "KenshiLua.WorldEventStateQueryList"; } };
    template <> struct TypeTraits<YesNoMaybe> { static const char* Metatable() { return "KenshiLua.YesNoMaybe"; } };
    template <> struct TypeTraits<ZoneManager> { static const char* Metatable() { return "KenshiLua.ZoneManager"; } };
    template <> struct TypeTraits<ZoneManagerInterfaceT> { static const char* Metatable() { return "KenshiLua.ZoneManagerInterfaceT"; } };
    template <> struct TypeTraits<ZoneMap> { static const char* Metatable() { return "KenshiLua.ZoneMap"; } };
    template <> struct TypeTraits<ZoneSpacialGrid> { static const char* Metatable() { return "KenshiLua.ZoneSpacialGrid"; } };
    template <> struct TypeTraits<hkBool> { static const char* Metatable() { return "KenshiLua.hkBool"; } };
    template <> struct TypeTraits<hkContainerHeapAllocator> { static const char* Metatable() { return "KenshiLua.hkContainerHeapAllocator"; } };
    template <> struct TypeTraits<hkMemoryAllocator> { static const char* Metatable() { return "KenshiLua.hkMemoryAllocator"; } };
    template <> struct TypeTraits<hkResult> { static const char* Metatable() { return "KenshiLua.hkResult"; } };
    template <> struct TypeTraits<hkVector4f> { static const char* Metatable() { return "KenshiLua.hkVector4f"; } };
    template <> struct TypeTraits<hkVector4fComparison> { static const char* Metatable() { return "KenshiLua.hkVector4fComparison"; } };
    template <> struct TypeTraits<iVector2> { static const char* Metatable() { return "KenshiLua.iVector2"; } };
    template <> struct TypeTraits<physHit> { static const char* Metatable() { return "KenshiLua.physHit"; } };
    template <> struct TypeTraits<rendHit> { static const char* Metatable() { return "KenshiLua.rendHit"; } };
    template <> struct TypeTraits<wraps::BaseLayout> { static const char* Metatable() { return "KenshiLua.BaseLayout"; } };
    /* KENSHILUA_GENERATED_TYPE_TRAITS_END */

    template <typename T>
    inline Status Push(struct lua_State* L, T* pointer)
    {
        return PushObject(L, pointer, TypeTraits<T>::Metatable());
    }

    template <typename T>
    inline T* Check(struct lua_State* L, int index)
    {
        return static_cast<T*>(CheckObject(L, index, TypeTraits<T>::Metatable()));
    }

    template <typename T>
    inline T* Test(struct lua_State* L, int index)
    {
        return static_cast<T*>(TestObject(L, index, TypeTraits<T>::Metatable()));
    }
}

#define KENSHILUA_REGISTER_TYPE_TRAIT(Type, MetatableName) \
    namespace KenshiLua { \
        template <> struct TypeTraits<Type> { \
            static const char* Metatable() { return MetatableName; } \
        }; \
    }
