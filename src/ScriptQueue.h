#pragma once

#include <string>
#include <vector>
#include <cstddef>
#include <boost/thread/mutex.hpp>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

class ScriptQueue;
extern ScriptQueue* g_scriptQueue;


// Tasks own their string payloads so producers don't have to keep buffers
// alive until the worker drains them.  The previous design used raw const
// char* into the union, which was leak-prone.
struct ScriptTask
{
    enum Type
    {
        ExecuteString,
        ExecuteFile,
        CallHandler
    };

    Type        type;
    int         taskId;

    // All payload fields are deep-copied; producers can free their inputs
    // immediately after enqueue() returns.
    std::string payload;     // script source (ExecuteString) or file path (ExecuteFile)
    std::string chunkname;   // optional, ExecuteString only
    std::string eventName;   // CallHandler only

    int         result;      // populated by the worker
    std::string errorMessage;

    ScriptTask() : type(ExecuteString), taskId(0), result(0) {}
};

class ScriptQueue
{
public:
    ScriptQueue();
    ~ScriptQueue();

    ScriptQueue(const ScriptQueue&);
    ScriptQueue& operator=(const ScriptQueue&);

    bool initialize(size_t capacity);
    void shutdown();

    bool enqueue(const ScriptTask& task);
    bool tryDequeue(ScriptTask& outTask);

    size_t pendingCount() const;

    void processQueue(lua_State* L);

    static const size_t DEFAULT_CAPACITY = 256;

private:
    struct RingBuffer
    {
        std::vector<ScriptTask> tasks;
        size_t writeIndex;
        size_t readIndex;
        size_t capacity;

        RingBuffer() : writeIndex(0), readIndex(0), capacity(0) {}

        bool init(size_t cap);
        size_t available() const;
        size_t capacityRemaining() const;
        bool push(const ScriptTask& task);
        bool pop(ScriptTask& outTask);
        void clear();
    };

    RingBuffer m_ringBuffer;
    bool       m_running;
    mutable boost::mutex m_mutex;
};

} // namespace KenshiLua
