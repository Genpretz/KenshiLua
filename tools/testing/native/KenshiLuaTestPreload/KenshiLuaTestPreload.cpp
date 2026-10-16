#ifdef _WINDOWS_
class GameLauncher
{
public:
    int _NV_OnInitDialog();
    void OnBnClickedLauncherOk();
};
#else
#include <kenshi/GameLauncher.h>
#endif
#include <kenshi/Kenshi.h>
#include <core/Functions.h>
#include <cstdio>
#include <cstdarg>
#include <cstring>

static const int kLauncherOkControlId = 1003;
static HANDLE g_runEvent = NULL;
static char g_eventName[256] = "Local\\KenshiLuaTestPreloadRun";
static char g_logPath[MAX_PATH] = {0};
static void (*g_okOriginal)(GameLauncher*) = NULL;
static HWND g_launcherHwnd = NULL;
static HWND g_okButtonHwnd = NULL;

static void trimLine(char* line)
{
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\r' || line[len - 1] == '\n' || line[len - 1] == ' ' || line[len - 1] == '\t')) {
        line[--len] = '\0';
    }
}

static void loadPreloadConfig(const char* dllDir)
{
    _snprintf(g_logPath, sizeof(g_logPath) - 1, "%s\\KenshiLuaTestPreload.log", dllDir);
    char cfgPath[MAX_PATH] = {0};
    _snprintf(cfgPath, sizeof(cfgPath) - 1, "%s\\preload.cfg", dllDir);

    FILE* cfg = fopen(cfgPath, "rb");
    if (!cfg) return;

    char line[1024];
    while (fgets(line, sizeof(line), cfg)) {
        trimLine(line);
        if (strncmp(line, "event_name=", 11) == 0 && line[11] != '\0') {
            strncpy(g_eventName, line + 11, sizeof(g_eventName) - 1);
            g_eventName[sizeof(g_eventName) - 1] = '\0';
        } else if (strncmp(line, "log_path=", 9) == 0 && line[9] != '\0') {
            strncpy(g_logPath, line + 9, sizeof(g_logPath) - 1);
            g_logPath[sizeof(g_logPath) - 1] = '\0';
        }
    }
    fclose(cfg);
}

static void record(const char* format, ...)
{
    if (g_logPath[0] == '\0') return;
    FILE* file = fopen(g_logPath, "ab");
    if (!file) return;
    fprintf(file, "%llu pid=%lu tid=%lu ",
        (unsigned long long)GetTickCount64(),
        (unsigned long)GetCurrentProcessId(),
        (unsigned long)GetCurrentThreadId());
    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    va_end(args);
    fprintf(file, "\n");
    fflush(file);
    fclose(file);
}

static BOOL CALLBACK describeChild(HWND window, LPARAM)
{
    char caption[256] = {0};
    char cls[128] = {0};
    GetWindowTextA(window, caption, sizeof(caption));
    GetClassNameA(window, cls, sizeof(cls));
    if (strcmp(cls, "Button") == 0) {
        record("BUTTON hwnd=%p id=%d class=%s text=%s enabled=%d",
            window, GetDlgCtrlID(window), cls, caption, (int)IsWindowEnabled(window));
    }
    return TRUE;
}

static BOOL CALLBACK describeWindow(HWND window, LPARAM)
{
    char caption[256] = {0};
    char cls[128] = {0};
    GetWindowTextA(window, caption, sizeof(caption));
    GetClassNameA(window, cls, sizeof(cls));
    record("WINDOW hwnd=%p class=%s text=%s visible=%d",
        window, cls, caption, (int)IsWindowVisible(window));
    EnumChildWindows(window, describeChild, 0);
    if (strcmp(cls, "#32770") == 0) {
        HWND okBtn = GetDlgItem(window, kLauncherOkControlId);
        if (okBtn && IsWindowEnabled(okBtn)) {
            g_launcherHwnd = window;
            g_okButtonHwnd = okBtn;
        }
    }
    return TRUE;
}

static void CALLBACK observeLauncher(HWND, UINT, UINT_PTR timer, DWORD)
{
    KillTimer(NULL, timer);
    record("OBSERVE_AFTER_PRELOAD");
    g_launcherHwnd = NULL;
    g_okButtonHwnd = NULL;
    EnumThreadWindows(GetCurrentThreadId(), describeWindow, 0);
    if (g_launcherHwnd && g_okButtonHwnd && g_runEvent && WaitForSingleObject(g_runEvent, 0) == WAIT_OBJECT_0) {
        BOOL posted = PostMessageA(
            g_launcherHwnd,
            WM_COMMAND,
            MAKEWPARAM(kLauncherOkControlId, BN_CLICKED),
            (LPARAM)g_okButtonHwnd);
        record("POST_OK dialog=%p button=%p id=%d posted=%d",
            g_launcherHwnd, g_okButtonHwnd, kLauncherOkControlId, (int)posted);
    }
}

static void okHook(GameLauncher* self)
{
    record("OK_ENTER self=%p", self);
    g_okOriginal(self);
    record("OK_RETURN");
}

__declspec(dllexport) void startPlugin()
{
    HMODULE module = NULL;
    if (!GetModuleHandleExA(
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            reinterpret_cast<LPCSTR>(&startPlugin),
            &module)) {
        return;
    }

    char modulePath[MAX_PATH] = {0};
    if (GetModuleFileNameA(module, modulePath, MAX_PATH) == 0) return;
    char* slash = strrchr(modulePath, '\\');
    if (!slash) return;
    *slash = '\0';

    loadPreloadConfig(modulePath);

    g_runEvent = OpenEventA(SYNCHRONIZE, FALSE, g_eventName);
    if (!g_runEvent || WaitForSingleObject(g_runEvent, 0) != WAIT_OBJECT_0) {
        if (g_runEvent) {
            CloseHandle(g_runEvent);
            g_runEvent = NULL;
        }
        return;
    }

    record("START version=%s event=%s",
        KenshiLib::GetKenshiVersion().ToString().c_str(),
        g_eventName);
    EnumThreadWindows(GetCurrentThreadId(), describeWindow, 0);

    intptr_t okAddress = KenshiLib::GetRealAddress(&GameLauncher::OnBnClickedLauncherOk);
    record("ADDRESSES ok=%p", (void*)okAddress);
    if (!okAddress) {
        record("INVALID_ADDRESS");
        return;
    }

    KenshiLib::HookStatus okStatus = KenshiLib::AddHook(okAddress, &okHook, &g_okOriginal);
    record("HOOK_OK status=%d", (int)okStatus);
    SetTimer(NULL, 0, 500, observeLauncher);
}
