#include "pch.h"
#include "ScriptQueue.h"
#include "EventSystem.h"
#include <boost/thread/lock_guard.hpp>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

bool ScriptQueue::RingBuffer::init(size_t cap)
{
    if (cap == 0) return false;
    tasks.resize(cap);
    writeIndex = 0;
    readIndex = 0;
    capacity = cap;
    return true;
}

size_t ScriptQueue::RingBuffer::available() const
{
    if (writeIndex >= readIndex) return writeIndex - readIndex;
    return capacity - readIndex + writeIndex;
}

size_t ScriptQueue::RingBuffer::capacityRemaining() const
{
    if (writeIndex >= readIndex) return capacity - (writeIndex - readIndex) - 1;
    return readIndex - writeIndex - 1;
}

bool ScriptQueue::RingBuffer::push(const ScriptTask& task)
{
    if (capacityRemaining() == 0) return false;
    tasks[writeIndex] = task;
    writeIndex = (writeIndex + 1) % capacity;
    return true;
}

bool ScriptQueue::RingBuffer::pop(ScriptTask& outTask)
{
    if (available() == 0) return false;
    outTask = tasks[readIndex];
    readIndex = (readIndex + 1) % capacity;
    return true;
}

void ScriptQueue::RingBuffer::clear()
{
    writeIndex = 0;
    readIndex = 0;
}

ScriptQueue::ScriptQueue() : m_running(false) {}
ScriptQueue::~ScriptQueue() { shutdown(); }

ScriptQueue::ScriptQueue(const ScriptQueue&) : m_running(false) {}
ScriptQueue& ScriptQueue::operator=(const ScriptQueue&) { return *this; }

bool ScriptQueue::initialize(size_t capacity)
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    if (!m_ringBuffer.init(capacity)) return false;
    m_running = true;
    return true;
}

void ScriptQueue::shutdown()
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    m_running = false;
    m_ringBuffer.clear();
}

bool ScriptQueue::enqueue(const ScriptTask& task)
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    if (!m_running) return false;
    return m_ringBuffer.push(task);
}

bool ScriptQueue::tryDequeue(ScriptTask& outTask)
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    if (!m_running) return false;
    return m_ringBuffer.pop(outTask);
}

size_t ScriptQueue::pendingCount() const
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    return m_ringBuffer.available();
}

void ScriptQueue::processQueue(lua_State* L)
{
    if (!L || !m_running) return;

    ScriptTask task;
    while (tryDequeue(task)) {
        switch (task.type) {
        case ScriptTask::ExecuteString: {
            const char* cn = task.chunkname.empty() ? "=(execute)" : task.chunkname.c_str();
            if (luaL_loadbuffer(L, task.payload.data(), task.payload.size(), cn) == LUA_OK) {
                task.result = lua_pcall(L, 0, 0, 0);
                if (task.result != LUA_OK) {
                    const char* e = lua_tostring(L, -1);
                    task.errorMessage = e ? e : "runtime error";
                    lua_pop(L, 1);
                }
            } else {
                task.result = LUA_ERRSYNTAX;
                const char* e = lua_tostring(L, -1);
                task.errorMessage = e ? e : "syntax error";
                lua_pop(L, 1);
            }
            break;
        }
        case ScriptTask::ExecuteFile:
            task.result = luaL_dofile(L, task.payload.c_str());
            if (task.result != LUA_OK) {
                const char* e = lua_tostring(L, -1);
                task.errorMessage = e ? e : "file error";
                lua_pop(L, 1);
            }
            break;
        case ScriptTask::CallHandler:
            task.result = EventSystem::get().callHandlers(task.eventName.c_str());
            break;
        }
    }
}

} // namespace KenshiLua
