import ctypes
from ctypes import wintypes
from typing import Any, Dict, List, Optional

user32 = ctypes.windll.user32
kernel32 = ctypes.windll.kernel32

WM_COMMAND = 0x0111
WM_CLOSE = 0x0010
BM_CLICK = 0x00F5
BN_CLICKED = 0
LAUNCHER_OK_CONTROL_ID = 1003
LAUNCHER_DIALOG_CLASS = "#32770"

WNDENUMPROC = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)

kernel32.CreateEventW.argtypes = [wintypes.LPVOID, wintypes.BOOL, wintypes.BOOL, wintypes.LPCWSTR]
kernel32.CreateEventW.restype = wintypes.HANDLE
kernel32.SetEvent.argtypes = [wintypes.HANDLE]
kernel32.SetEvent.restype = wintypes.BOOL
kernel32.ResetEvent.argtypes = [wintypes.HANDLE]
kernel32.ResetEvent.restype = wintypes.BOOL
kernel32.CloseHandle.argtypes = [wintypes.HANDLE]
kernel32.CloseHandle.restype = wintypes.BOOL

user32.EnumWindows.argtypes = [WNDENUMPROC, wintypes.LPARAM]
user32.EnumWindows.restype = wintypes.BOOL
user32.EnumChildWindows.argtypes = [wintypes.HWND, WNDENUMPROC, wintypes.LPARAM]
user32.EnumChildWindows.restype = wintypes.BOOL
user32.GetWindowThreadProcessId.argtypes = [wintypes.HWND, ctypes.POINTER(wintypes.DWORD)]
user32.GetWindowThreadProcessId.restype = wintypes.DWORD
user32.GetWindowTextW.argtypes = [wintypes.HWND, wintypes.LPWSTR, ctypes.c_int]
user32.GetWindowTextW.restype = ctypes.c_int
user32.GetClassNameW.argtypes = [wintypes.HWND, wintypes.LPWSTR, ctypes.c_int]
user32.GetClassNameW.restype = ctypes.c_int
user32.GetDlgItem.argtypes = [wintypes.HWND, ctypes.c_int]
user32.GetDlgItem.restype = wintypes.HWND
user32.GetDlgCtrlID.argtypes = [wintypes.HWND]
user32.GetDlgCtrlID.restype = ctypes.c_int
user32.IsWindowEnabled.argtypes = [wintypes.HWND]
user32.IsWindowEnabled.restype = wintypes.BOOL
user32.IsWindowVisible.argtypes = [wintypes.HWND]
user32.IsWindowVisible.restype = wintypes.BOOL
user32.PostMessageW.argtypes = [wintypes.HWND, wintypes.UINT, wintypes.WPARAM, wintypes.LPARAM]
user32.PostMessageW.restype = wintypes.BOOL


class NamedRunEvent:
    def __init__(self, name: str) -> None:
        self.name = name
        self.handle: Optional[int] = None

    def create_signaled(self) -> None:
        handle = kernel32.CreateEventW(None, True, True, self.name)
        if not handle:
            raise OSError(f"Failed to create named event {self.name}")
        kernel32.SetEvent(handle)
        self.handle = handle

    def reset_and_close(self) -> None:
        if self.handle:
            kernel32.ResetEvent(self.handle)
            kernel32.CloseHandle(self.handle)
            self.handle = None


def _get_window_text(hwnd: int) -> str:
    buf = ctypes.create_unicode_buffer(256)
    user32.GetWindowTextW(hwnd, buf, 256)
    return buf.value


def _get_class_name(hwnd: int) -> str:
    buf = ctypes.create_unicode_buffer(128)
    user32.GetClassNameW(hwnd, buf, 128)
    return buf.value


def inspect_process_windows(pids: List[int]) -> List[Dict[str, Any]]:
    pid_set = set(pids)
    if not pid_set:
        return []

    windows: List[Dict[str, Any]] = []

    def enum_top(hwnd: int, _lparam: int) -> bool:
        pid = wintypes.DWORD(0)
        user32.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        if pid.value not in pid_set:
            return True

        cls = _get_class_name(hwnd)
        title = _get_window_text(hwnd)
        visible = bool(user32.IsWindowVisible(hwnd))
        children: List[Dict[str, Any]] = []

        def enum_child(child_hwnd: int, _child_lparam: int) -> bool:
            c_cls = _get_class_name(child_hwnd)
            if c_cls == "Button":
                children.append(
                    {
                        "hwnd": f"0x{child_hwnd:08X}",
                        "raw_hwnd": int(child_hwnd),
                        "id": int(user32.GetDlgCtrlID(child_hwnd)),
                        "class": c_cls,
                        "text": _get_window_text(child_hwnd),
                        "enabled": bool(user32.IsWindowEnabled(child_hwnd)),
                    }
                )
            return True

        child_cb = WNDENUMPROC(enum_child)
        user32.EnumChildWindows(hwnd, child_cb, 0)
        windows.append(
            {
                "pid": int(pid.value),
                "hwnd": f"0x{hwnd:08X}",
                "raw_hwnd": int(hwnd),
                "class": cls,
                "title": title,
                "visible": visible,
                "buttons": children,
            }
        )
        return True

    top_cb = WNDENUMPROC(enum_top)
    user32.EnumWindows(top_cb, 0)
    return windows


def try_dismiss_launcher_external(pids: List[int]) -> Optional[Dict[str, Any]]:
    for win in inspect_process_windows(pids):
        if win["class"] != LAUNCHER_DIALOG_CLASS:
            continue
        dialog_hwnd = win["raw_hwnd"]
        ok_hwnd = user32.GetDlgItem(dialog_hwnd, LAUNCHER_OK_CONTROL_ID)
        if ok_hwnd and user32.IsWindowEnabled(ok_hwnd):
            wparam = (BN_CLICKED << 16) | (LAUNCHER_OK_CONTROL_ID & 0xFFFF)
            posted = bool(user32.PostMessageW(dialog_hwnd, WM_COMMAND, wparam, ok_hwnd))
            return {
                "pid": win["pid"],
                "dialog_hwnd": win["hwnd"],
                "button_hwnd": f"0x{int(ok_hwnd):08X}",
                "control_id": LAUNCHER_OK_CONTROL_ID,
                "posted": posted,
            }
    return None


def post_wm_close_to_pids(pids: List[int]) -> int:
    closed = 0
    for win in inspect_process_windows(pids):
        if user32.PostMessageW(win["raw_hwnd"], WM_CLOSE, 0, 0):
            closed += 1
    return closed
