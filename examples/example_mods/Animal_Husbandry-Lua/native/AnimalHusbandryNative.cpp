#include <windows.h>
// Preserve the game's unresolved-inheritance member-pointer layout.
#include <kenshi/Tasker.h>
#include <kenshi/AI/AI.h>
#include <kenshi/AI/AITaskSystem.h>
#include <kenshi/CharBody.h>
#include <kenshi/Character.h>
#include <kenshi/GameData.h>
#include <kenshi/Building/StorageBuilding.h>
#include <kenshi/gui/TitleScreen.h>
#include <core/Functions.h>
#include <Debug.h>
#include <kenshi/Kenshi.h>
#include <KenshiLua.h>
#include "Storage.h"
#include <map>
#include <vector>
#include <cstddef>
#include <cmath>
#include <sstream>
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace
{
    // A mod-defined ID cast to TaskType; KenshiLib's enum is not extended.
    const TaskType Husbandry = static_cast<TaskType>(0x41480001);
    const DWORD ScoreRefreshMilliseconds = 500;

    enum JobEvent
    {
        NoJobEvent = -1,
        ScoreJob = 0,
        StartJob = 1,
        RunJob = 2,
        StopJob = 3
    };

    static_assert(sizeof(TaskData) == 0x178, "TaskData ABI mismatch");
    static_assert(sizeof(Tasker) == 0x78, "Tasker ABI mismatch");
    static_assert(offsetof(TaskData, scoreFunction) == 0x108, "TaskData score offset mismatch");

    class Mutex
    {
    public:
        Mutex() { InitializeCriticalSection(&value); }
        ~Mutex() { DeleteCriticalSection(&value); }
        CRITICAL_SECTION value;
    } stateMutex;
    class ScopedLock
    {
    public:
        ScopedLock() { EnterCriticalSection(&stateMutex.value); }
        ~ScopedLock() { LeaveCriticalSection(&stateMutex.value); }
    };

    // Matches the engine's three-word member-function pointer representation.
    struct ScoreFunction
    {
        intptr_t entry;
        intptr_t adjustment;
        intptr_t virtualAdjustment;
    };
    typedef TaskData* (*RegisterTaskFn)(TaskType, const ScoreFunction&, bool, bool,
        const std::string&, unsigned int);
    typedef Tasker* (*GetTaskFn)(void*, TaskType, const hand&, taskPriority, float,
        const Ogre::Vector3&, int, int);
    RegisterTaskFn registerTask = NULL;
    GetTaskFn originalGetTask = NULL;
    float (*originalScore)(Tasker*, AI*) = NULL;
    void (*originalAddJob)(OrdersReceiver*, TaskType, const hand&, const Ogre::Vector3&, bool) = NULL;
    void (*originalLoad)(OrdersReceiver*, GameData*) = NULL;
    void (*originalSave)(OrdersReceiver*, GameData*) = NULL;
    void (*originalTitleUpdate)(TitleScreen*) = NULL;
    const std::string& (*originalJobName)(const OrdersReceiver*, int) = NULL;
    TaskData* taskDefinition = NULL;
    // Script activation/reload expires queued work from earlier generations.
    volatile LONG currentGeneration = 0;
    volatile LONG scriptActive = 0;
    bool moduleRegistered = false;
    bool hooksInstalled = false;

    struct ScoreKey
    {
        hand worker, subject;
        bool operator<(const ScoreKey& other) const
        {
            if (worker != other.worker) return worker < other.worker;
            return subject < other.subject;
        }
    };
    struct ScoreCache
    {
        LONG generation;
        float score;
        bool pending;
        DWORD lastUpdated;
        ScoreCache() : generation(-1), score(0), pending(false), lastUpdated(0) {}
    };
    std::map<ScoreKey, ScoreCache> scoreCache;
    typedef std::pair<ScoreKey, ScoreCache> ScoreRequest;

    // The executing Tasker and queued events each hold a reference. Queued work
    // must remain valid even if Kenshi destroys the Tasker before the next update.
    struct ActionState
    {
        LONG generation, references;
        volatile LONG complete;
        hand worker, subject;
        bool pending, ended;
        float elapsed;
        ActionState() : generation(currentGeneration), references(1), complete(0),
            pending(false), ended(false), elapsed(0) {}
        void retain() { InterlockedIncrement(&references); }
        void release()
        {
            if (!InterlockedDecrement(&references))
            {
                delete this;
            }
        }
    };
    struct QueuedActionEvent
    {
        ActionState* action;
        JobEvent event;
        // Copies transfer this logical queue reference without another retain.
        // processActionEvent releases it, even when the event is discarded.
        QueuedActionEvent(ActionState* state, JobEvent kind) : action(state), event(kind)
        {
            action->retain();
        }
    };
    std::vector<QueuedActionEvent> actionEvents;

    bool hasJob(const OrdersReceiver* orders, const hand& subject)
    {
        for (int i = 0; i < orders->getPermajobCount(); ++i)
        {
            const Tasker* job = orders->getPermajobData(i);
            if (job->taskData->key == Husbandry && job->subject == subject) return true;
        }
        return false;
    }

    struct Delivery
    {
        hand worker, storage, subject;
        GameData* product;
        Tasker* goal;
        LONG generation;
    };
    std::map<hand, Delivery> deliveries;

    void cleanDeliveries()
    {
        for (std::map<hand, Delivery>::iterator it = deliveries.begin(); it != deliveries.end();)
        {
            Delivery& delivery = it->second;
            Character* worker = delivery.worker.getCharacter();
            OrdersReceiver* orders = worker ? worker->getOrdersReciever() : NULL;
            unsigned int slot = 0;
            if (orders)
            {
                while (slot < orders->jobs.size() && orders->jobs[slot] != delivery.goal)
                {
                    ++slot;
                }
            }
            bool found = orders && slot < orders->jobs.size();
            Building* building = delivery.storage.getBuilding();
            StorageBuilding* storage = building ? building->getFunctionStuff() : NULL;
            if (found && scriptActive && delivery.generation == currentGeneration &&
                hasJob(orders, delivery.subject) && orders->isJobsEnabled() && !orders->hasPlayerOrders() &&
                HusbandryStorage::deliverableCount(worker, delivery.product) > 0 && storage &&
                storage->canHaveSomeOfThese(delivery.product) &&
                worker->getAI()->haveSomeResourcesFor(delivery.storage, building->getPosition()) &&
                !worker->getAI()->getTaskSystem()->isPathImpossible(delivery.storage))
            {
                ++it;
                continue;
            }
            if (found)
            {
                // Remove only the goal this DLL inserted. Executing actions are
                // separate factory instances; the shared TaskData stays engine-owned.
                for (unsigned int i = slot + 1; i < orders->jobs.size(); ++i)
                {
                    orders->jobs[i - 1] = orders->jobs[i];
                }
                --orders->jobs.count;
                delete delivery.goal;
                orders->_NV_setNeedGOAP();
            }
            std::map<hand, Delivery>::iterator old = it++;
            deliveries.erase(old);
        }
    }

    int deliverLua(lua_State* L)
    {
        // These typed extension operations use KenshiLua's main Lua state.
        if (L != KenshiLua::GetState()) return luaL_error(L, "deliver requires the main Lua state");
        Character* worker = KenshiLua::Test<Character>(L, 1);
        Building* building = KenshiLua::Test<Building>(L, 2);
        GameData* product = KenshiLua::Test<GameData>(L, 3);
        hand subject;
        if (lua_gettop(L) >= 4)
        {
            subject.fromString(luaL_checkstring(L, 4));
        }
        else if (worker)
        {
            subject = worker->handle;
        }
        StorageBuilding* storage = building ? building->getFunctionStuff() : NULL;
        if (!worker || !storage || !product || HusbandryStorage::deliverableCount(worker, product) == 0 ||
            !storage->canHaveSomeOfThese(product) ||
            !worker->getAI()->haveSomeResourcesFor(building->handle, building->getPosition()))
        {
            lua_pushboolean(L, false);
            return 1;
        }
        OrdersReceiver* orders = worker->getOrdersReciever();
        if (!hasJob(orders, subject))
        {
            lua_pushboolean(L, false);
            return 1;
        }
        if (deliveries.find(worker->handle) != deliveries.end())
        {
            lua_pushboolean(L, true);
            return 1;
        }
        // Preserve an equivalent temporary job supplied by the player or another mod.
        for (unsigned int i = 0; i < orders->jobs.size(); ++i)
        {
            if (orders->jobs[i]->key() == FILL_MACHINE && orders->jobs[i]->subject == building->handle)
            {
                lua_pushboolean(L, true);
                return 1;
            }
        }
        unsigned int before = orders->jobs.size();
        orders->addJob(FILL_MACHINE, building->handle, building->getPosition(), false);
        if (orders->jobs.size() == before + 1)
        {
            Delivery delivery;
            delivery.worker = worker->handle;
            delivery.storage = building->handle;
            delivery.subject = subject;
            delivery.product = product;
            delivery.goal = orders->jobs[before];
            delivery.generation = currentGeneration;
            deliveries[worker->handle] = delivery;
            lua_pushboolean(L, true);
        }
        else
        {
            lua_pushboolean(L, false);
        }
        return 1;
    }

    // Called by AI threads. Only copy handles and update shared state here;
    // engine-object resolution and Lua callbacks happen in pump() on the main thread.
    void enqueue(ActionState* action, JobEvent event, CharBody* body)
    {
        ScopedLock lock;
        if (event == StartJob)
        {
            action->worker = body->character->handle;
        }
        if (event == RunJob)
        {
            action->elapsed += body->frameTIME;
            if (action->pending || action->ended) return;
            action->pending = true;
        }
        if (event == StopJob)
        {
            action->ended = true;
        }
        actionEvents.push_back(QueuedActionEvent(action, event));
    }

    void ensureDefinition()
    {
        if (taskDefinition || !registerTask) return;
        ScoreFunction score = { KenshiLib::GetRealAddress(&AI::_NV_score10), 0, 0 };
        taskDefinition = registerTask(Husbandry, score, true, false, "Animal Husbandry", 0x21);
        taskDefinition->setPermaJob(PERMAJOB_NORMAL, true, Husbandry, NULL_TASK);
        taskDefinition->setSelfRegulation(false, true);
        taskDefinition->forDirectPlayerOrdersOnly = true;
    }

    class HusbandryTask : public Tasker
    {
    public:
        HusbandryTask() : label("Animal Husbandry"), action(new ActionState()), finished(false) {}
        virtual ~HusbandryTask() { action->release(); }
        virtual void startAction(CharBody* body)
        {
            action->subject = subject;
            enqueue(action, StartJob, body);
        }
        virtual void runAction(CharBody* body)
        {
            if (action->generation != currentGeneration || !scriptActive ||
                !body->character->getOrdersReciever()->isJobsEnabled() ||
                InterlockedCompareExchange(&action->complete, 0, 0))
            {
                finished = true;
                // notifyTaskComplete can delete this instance.
                body->notifyTaskComplete();
                return;
            }
            enqueue(action, RunJob, body);
        }
        virtual void endAction(CharBody* body)
        {
            enqueue(action, StopJob, body);
        }
        virtual bool taskSaysItsFinished(Character*) const { return finished; }
        std::string label;
    private:
        ActionState* action;
        bool finished;
    };

    const std::string& jobNameHook(const OrdersReceiver* orders, int slot)
    {
        if (slot >= 0 && slot < orders->getPermajobCount())
        {
            const Tasker* task = orders->getPermajobData(slot);
            if (task->taskData->key == Husbandry)
                return static_cast<const HusbandryTask*>(task)->label;
        }
        return originalJobName(orders, slot);
    }

    Tasker* getTaskHook(void* repertoire, TaskType id, const hand& subject,
        taskPriority priority, float weight, const Ogre::Vector3& location,
        int startTime, int endTime)
    {
        if (id != Husbandry)
            return originalGetTask(repertoire, id, subject, priority, weight, location, startTime, endTime);
        typedef bool (*HasTaskFn)(void*, TaskType);
        HasTaskFn hasTask = (HasTaskFn)((void**)*(void**)repertoire)[1];
        if (!taskDefinition || !hasTask(repertoire, id)) return NULL;
        HusbandryTask* task = new HusbandryTask();
        task->taskData = taskDefinition;
        task->subject = subject;
        task->location = location;
        task->priority = priority;
        task->weight = weight;
        task->startTime = startTime;
        task->endTime = endTime;
        return task;
    }

    float scoreHook(Tasker* task, AI* ai)
    {
        if (!task->taskData || task->taskData->key != Husbandry) return originalScore(task, ai);
        if (!scriptActive || !ai->me->getOrdersReciever()->isJobsEnabled()) return 0;
        ScopedLock lock;
        ScoreKey key;
        key.worker = ai->me->handle;
        key.subject = task->subject;
        ScoreCache& cached = scoreCache[key];
        if (cached.generation != currentGeneration) cached.score = 0;
        cached.generation = currentGeneration;
        cached.pending = true;
        return cached.score;
    }

    void addJobHook(OrdersReceiver* receiver, TaskType id, const hand& subject,
        const Ogre::Vector3& location, bool shift)
    {
        if (id == Husbandry) ensureDefinition();
        originalAddJob(receiver, id, subject, location, shift);
    }
    void loadHook(OrdersReceiver* receiver, GameData* data)
    {
        // Saved jobs dereference TaskData before entering the task factory.
        ensureDefinition();
        originalLoad(receiver, data);
    }
    void saveHook(OrdersReceiver* receiver, GameData* data)
    {
        originalSave(receiver, data);
        if (!data) return;
        for (int i = 0; i < receiver->getPermajobCount(); ++i)
        {
            const Tasker* job = receiver->getPermajobData(i);
            if (job->taskData->key != Husbandry) continue;
            std::ostringstream field;
            field << "pjobT" << i;
            // The subject is an assignment identity, not a live animal target.
            // Keep it unchanged when the animal moves squads, dies, or is sold.
            data->storeHandle(job->subject, field.str(), false);
        }
    }

    // A Lua response is accepted only while dispatching its matching request.
    int requestSequence = 0;
    int currentRequest = 0;
    JobEvent requestKind = NoJobEvent;
    double response = 0;
    bool answered = false;
    int taskTypeLua(lua_State* L)
    {
        ensureDefinition();
        lua_pushinteger(L, static_cast<int>(Husbandry));
        return 1;
    }
    int deliverableCountLua(lua_State* L)
    {
        if (L != KenshiLua::GetState()) return luaL_error(L, "deliverableCount requires the main Lua state");
        Character* worker = KenshiLua::Test<Character>(L, 1);
        GameData* product = KenshiLua::Test<GameData>(L, 2);
        if (!worker || !product) return luaL_error(L, "deliverableCount expects Character and GameData");
        lua_pushinteger(L, HusbandryStorage::deliverableCount(worker, product));
        return 1;
    }
    int storageRoomLua(lua_State* L)
    {
        if (L != KenshiLua::GetState()) return luaL_error(L, "storageRoom requires the main Lua state");
        Character* worker = KenshiLua::Test<Character>(L, 1);
        Building* building = KenshiLua::Test<Building>(L, 2);
        GameData* product = KenshiLua::Test<GameData>(L, 3);
        StorageBuilding* storage = building ? building->getFunctionStuff() : NULL;
        if (!worker || !storage || !product) return luaL_error(L, "storageRoom expects Character, storage Building and GameData");
        lua_pushboolean(L, HusbandryStorage::hasRoomForBatch(worker, storage, product));
        return 1;
    }
    int deliveryPendingLua(lua_State* L)
    {
        if (L != KenshiLua::GetState()) return luaL_error(L, "deliveryPending requires the main Lua state");
        Character* worker = KenshiLua::Test<Character>(L, 1);
        if (!worker) return luaL_error(L, "deliveryPending expects a Character");
        lua_pushboolean(L, deliveries.find(worker->handle) != deliveries.end());
        return 1;
    }
    int setJobLabelLua(lua_State* L)
    {
        if (L != KenshiLua::GetState()) return luaL_error(L, "setJobLabel requires the main Lua state");
        Character* worker = KenshiLua::Test<Character>(L, 1);
        const char* subjectText = luaL_checkstring(L, 2);
        const char* label = luaL_checkstring(L, 3);
        if (!worker) return luaL_error(L, "setJobLabel expects a Character");
        hand subject;
        subject.fromString(subjectText);
        OrdersReceiver* orders = worker->getOrdersReciever();
        for (int i = 0; i < orders->getPermajobCount(); ++i)
        {
            const Tasker* task = orders->getPermajobData(i);
            if (task->taskData->key == Husbandry && task->subject == subject)
            {
                HusbandryTask* job = static_cast<HusbandryTask*>(const_cast<Tasker*>(task));
                bool changed = job->label != label;
                job->label = label;
                lua_pushboolean(L, changed);
                return 1;
            }
        }
        lua_pushboolean(L, false);
        return 1;
    }
    int setActiveLua(lua_State* L)
    {
        InterlockedExchange(&scriptActive, 0);
        InterlockedIncrement(&currentGeneration);
        {
            ScopedLock lock;
            scoreCache.clear();
        }
        if (lua_toboolean(L, 1)) InterlockedExchange(&scriptActive, 1);
        return 0;
    }
    int getJobLabelLua(lua_State* L)
    {
        if (L != KenshiLua::GetState()) return luaL_error(L, "getJobLabel requires the main Lua state");
        Tasker* task = KenshiLua::Test<Tasker>(L, 1);
        if (task && task->taskData && task->taskData->key == Husbandry)
            lua_pushstring(L, static_cast<HusbandryTask*>(task)->label.c_str());
        else
            lua_pushnil(L);
        return 1;
    }

    void pump();
    int updateLua(lua_State* L)
    {
        if (L != KenshiLua::GetState()) return luaL_error(L, "update requires the main Lua state");
        pump();
        return 0;
    }
    int setScoreLua(lua_State* L)
    {
        double value = luaL_checknumber(L, 2);
        if (requestKind == ScoreJob && luaL_checkint(L, 1) == currentRequest &&
            _finite(value) && value >= 0 && value <= 1000000)
        {
            response = value;
            answered = true;
        }
        return 0;
    }
    int setCompleteLua(lua_State* L)
    {
        if (requestKind == RunJob && luaL_checkint(L, 1) == currentRequest)
        {
            response = lua_toboolean(L, 2) ? 1 : 0;
            answered = true;
        }
        return 0;
    }
    const luaL_Reg moduleFunctions[] = {
        { "taskType", taskTypeLua },
        { "setActive", setActiveLua },
        { "deliver", deliverLua },
        { "setJobLabel", setJobLabelLua },
        { "getJobLabel", getJobLabelLua },
        { "update", updateLua },
        { "deliverableCount", deliverableCountLua },
        { "storageRoom", storageRoomLua },
        { "deliveryPending", deliveryPendingLua },
        { "setScore", setScoreLua },
        { "setComplete", setCompleteLua },
        { NULL, NULL }
    };
    int openModule(lua_State* L)
    {
        ensureDefinition();
        lua_newtable(L);
        luaL_register(L, NULL, moduleFunctions);
        return 1;
    }
    void ensureRegistered()
    {
        if (moduleRegistered || !hooksInstalled || !KenshiLua::GetState()) return;
        moduleRegistered = KenshiLua::RegisterModule("AnimalHusbandryNative", openModule) == KenshiLua::STATUS_OK;
        if (moduleRegistered) KenshiLua::LogInfo("[AnimalHusbandryNative] module registered");
    }

    bool dispatch(JobEvent event, const hand& worker, const hand& subject, float elapsed, double& result)
    {
        result = 0;
        lua_State* L = KenshiLua::GetState();
        Character* character = worker.getCharacter();
        if (!L || !character || requestKind != NoJobEvent) return false;
        const char* names[] = {
            "AnimalHusbandry_JobScore",
            "AnimalHusbandry_JobStart",
            "AnimalHusbandry_JobRun",
            "AnimalHusbandry_JobStop"
        };
        int top = KenshiLua::GetTop(L);
        if (requestSequence == 0x7FFFFFFF) requestSequence = 0;
        currentRequest = ++requestSequence;
        KenshiLua::Push(L, currentRequest);
        if (KenshiLua::Push(L, character) != KenshiLua::STATUS_OK)
        {
            KenshiLua::SetTop(L, top);
            return false;
        }
        // A string copies the handle; no borrowed pointer into a queued message.
        KenshiLua::Push(L, subject.toString());
        KenshiLua::Push(L, elapsed);
        response = 0;
        answered = false;
        requestKind = event;
        LONG before = currentGeneration;
        std::string error;
        KenshiLua::Status status = KenshiLua::DispatchEvent(names[event], 4, &error);
        requestKind = NoJobEvent;
        KenshiLua::SetTop(L, top);
        if (status != KenshiLua::STATUS_OK)
            KenshiLua::LogError("[AnimalHusbandryNative] " + error);
        result = response;
        return status == KenshiLua::STATUS_OK && before == currentGeneration && answered;
    }

    void takePendingWork(std::vector<ScoreRequest>& pendingScores,
        std::vector<QueuedActionEvent>& pendingEvents)
    {
        ScopedLock lock;
        DWORD now = GetTickCount();
        for (std::map<ScoreKey, ScoreCache>::iterator it = scoreCache.begin(); it != scoreCache.end(); ++it)
        {
            if (it->second.pending ||
                (scriptActive && now - it->second.lastUpdated >= ScoreRefreshMilliseconds))
            {
                pendingScores.push_back(*it);
                it->second.pending = false;
                it->second.lastUpdated = now;
            }
        }
        pendingEvents.swap(actionEvents);
    }

    void processScoreRequest(ScoreRequest& request)
    {
        ScoreKey& key = request.first;
        LONG generation = request.second.generation;
        Character* worker = key.worker.getCharacter();
        if (!worker || !hasJob(worker->getOrdersReciever(), key.subject))
        {
            ScopedLock lock;
            scoreCache.erase(key);
            return;
        }

        double score = 0;
        if (scriptActive && generation == currentGeneration &&
            !dispatch(ScoreJob, key.worker, key.subject, 0, score))
        {
            score = 0;
        }

        bool availabilityChanged = false;
        {
            ScopedLock lock;
            if (generation == currentGeneration)
            {
                availabilityChanged = (scoreCache[key].score > 0) != (score > 0);
                scoreCache[key].score = static_cast<float>(score);
            }
        }
        if (availabilityChanged && worker && worker->getOrdersReciever()->isJobsEnabled())
        {
            worker->getAI()->getTaskSystem()->callForUpdate(true);
        }
    }

    void processActionEvent(const QueuedActionEvent& message)
    {
        ActionState* action = message.action;
        JobEvent event = message.event;
        float elapsed;
        bool ended;
        {
            ScopedLock lock;
            elapsed = action->elapsed;
            ended = action->ended;
            if (event == RunJob)
            {
                action->pending = false;
                action->elapsed = 0;
            }
        }

        double complete = 0;
        Character* worker = action->worker.getCharacter();
        if (event == RunJob && worker && (!worker->getOrdersReciever()->isJobsEnabled() ||
            !hasJob(worker->getOrdersReciever(), action->subject)))
        {
            InterlockedExchange(&action->complete, 1);
        }
        else if (scriptActive && action->generation == currentGeneration && (!ended || event == StopJob))
        {
            bool ok = dispatch(event, action->worker, action->subject, elapsed, complete);
            if (event == RunJob && (!ok || complete != 0))
            {
                InterlockedExchange(&action->complete, 1);
            }
        }
        action->release();
    }

    void pump()
    {
        ensureRegistered();
        if (!KenshiLua::GetState()) return;
        cleanDeliveries();

        // Release the queue lock before Lua runs: callbacks can change job state.
        std::vector<ScoreRequest> pendingScores;
        std::vector<QueuedActionEvent> pendingEvents;
        takePendingWork(pendingScores, pendingEvents);
        for (size_t i = 0; i < pendingScores.size(); ++i)
        {
            processScoreRequest(pendingScores[i]);
        }
        for (size_t i = 0; i < pendingEvents.size(); ++i)
        {
            processActionEvent(pendingEvents[i]);
        }
    }

    void titleUpdateHook(TitleScreen* title)
    {
        originalTitleUpdate(title);
        ensureRegistered();
    }

    bool install()
    {
        KenshiLib::BinaryVersion version = KenshiLib::GetKenshiVersion();
        if (version.GetVersion() != "1.0.65") return false;
        intptr_t registerRva = 0, factoryRva = 0;
        if (version.GetPlatform() == KenshiLib::BinaryVersion::GOG)
        {
            registerRva = 0x60E280;
            factoryRva = 0x32E720;
        }
        else if (version.GetPlatform() == KenshiLib::BinaryVersion::STEAM)
        {
            registerRva = 0x60DF70;
            factoryRva = 0x32EB90;
        }
        else return false;
        const unsigned char registrationPrefix[] = {
            0x48, 0x8B, 0xC4, 0x89, 0x48, 0x08, 0x55, 0x57, 0x41,
            0x54, 0x48, 0x8B, 0xEC, 0x48, 0x83, 0xEC, 0x60
        };
        const unsigned char factoryPrefix[] = {
            0x40, 0x55, 0x56, 0x57, 0x41, 0x54, 0x41, 0x55, 0x48, 0x8D,
            0x6C, 0x24, 0xE9, 0x48, 0x81, 0xEC, 0x90, 0, 0, 0
        };
        intptr_t base = (intptr_t)GetModuleHandleW(NULL);
        if (memcmp((void*)(base + registerRva), registrationPrefix, sizeof(registrationPrefix)) ||
            memcmp((void*)(base + factoryRva), factoryPrefix, sizeof(factoryPrefix))) return false;
        registerTask = (RegisterTaskFn)(base + registerRva);
        if (KenshiLib::AddHook(base + factoryRva, &getTaskHook, &originalGetTask) != KenshiLib::SUCCESS ||
            KenshiLib::AddHook(KenshiLib::GetRealAddress(&Tasker::score), &scoreHook, &originalScore) != KenshiLib::SUCCESS ||
            KenshiLib::AddHook(KenshiLib::GetRealAddress(&OrdersReceiver::addJob), &addJobHook, &originalAddJob) != KenshiLib::SUCCESS ||
            KenshiLib::AddHook(KenshiLib::GetRealAddress(&OrdersReceiver::_NV_loadFromSerialise), &loadHook, &originalLoad) != KenshiLib::SUCCESS ||
            KenshiLib::AddHook(KenshiLib::GetRealAddress(&OrdersReceiver::_NV_serialise), &saveHook, &originalSave) != KenshiLib::SUCCESS ||
            KenshiLib::AddHook(KenshiLib::GetRealAddress(&TitleScreen::_NV_update), &titleUpdateHook, &originalTitleUpdate) != KenshiLib::SUCCESS ||
            KenshiLib::AddHook(KenshiLib::GetRealAddress(&OrdersReceiver::getPermajobName), &jobNameHook, &originalJobName) != KenshiLib::SUCCESS)
            return false;
        hooksInstalled = true;
        return true;
    }
}

__declspec(dllexport) void startPlugin()
{
    if (!install())
    {
        ErrorLog("[AnimalHusbandryNative] Unsupported executable or failed task hook installation");
        return;
    }
    ensureRegistered();
}
