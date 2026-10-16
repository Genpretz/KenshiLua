import hashlib
import os
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional

SUPPORTED_HASHES: Dict[str, str] = {
    "gog": "2DEFC287C813798B9682B93ACF68D340DA895CF5164D342145BA0FAEB9024681",
    "steam": "504B362CDE850D56AFB1CEA6F5B7B0EE014D9DD7B47E188599D91C804502CD3E",
}

DEFAULT_GOG_ROOTS: List[Path] = [
    Path(r"C:\GOG Games\Kenshi"),
    Path(r"C:\Program Files (x86)\GOG Galaxy\Games\Kenshi"),
]

DEFAULT_STEAM_ROOTS: List[Path] = [
    Path(r"C:\Program Files (x86)\Steam\steamapps\common\Kenshi"),
    Path(r"C:\Program Files\Steam\steamapps\common\Kenshi"),
]

STEAM_APP_ID = "233860"
CONSUMER_MOD_NAME = "KenshiLua Tests"
CONSUMER_MOD_FILE = "KenshiLua Tests.mod"
PROVIDER_MOD_FILE = "KenshiLua.mod"


@dataclass
class KenshiInstallation:
    platform: str
    game_root: Path
    executable_path: Path
    executable_sha256: str
    hash_supported: bool
    provider_root: Path
    consumer_root: Path
    mods_cfg_path: Path
    re_kenshi_log_path: Path
    kenshi_log_path: Path


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        while True:
            chunk = handle.read(1024 * 1024)
            if not chunk:
                break
            digest.update(chunk)
    return digest.hexdigest().upper()


def find_running_kenshi_processes() -> List[Dict[str, str]]:
    cmd = [
        "powershell",
        "-NoProfile",
        "-Command",
        (
            "Get-Process | Where-Object { $_.ProcessName -match '^kenshi.*x64$' } | "
            "ForEach-Object { \"$($_.Id)|$($_.ProcessName)|$($_.Path)\" }"
        ),
    ]
    res = subprocess.run(cmd, capture_output=True, text=True, check=False)
    processes: List[Dict[str, str]] = []
    for raw in res.stdout.splitlines():
        line = raw.strip()
        if not line:
            continue
        parts = line.split("|", 2)
        processes.append(
            {
                "pid": parts[0],
                "name": parts[1] if len(parts) > 1 else "",
                "path": parts[2] if len(parts) > 2 else "",
            }
        )
    return processes


def find_processes_under_root(game_root: Path, launched_after_epoch: float) -> List[int]:
    root_prefix = os.path.normcase(os.path.abspath(str(game_root))) + os.sep
    cmd = [
        "powershell",
        "-NoProfile",
        "-Command",
        (
            "Get-Process | Where-Object { $_.ProcessName -match '^kenshi.*x64$' } | "
            "ForEach-Object { "
            "$st = if ($_.StartTime) { [DateTimeOffset]$_.StartTime } else { $null }; "
            "$ep = if ($st) { $st.ToUnixTimeMilliseconds() / 1000.0 } else { 0 }; "
            "\"$($_.Id)|$ep|$($_.Path)\" "
            "}"
        ),
    ]
    res = subprocess.run(cmd, capture_output=True, text=True, check=False)
    pids: List[int] = []
    for raw in res.stdout.splitlines():
        line = raw.strip()
        if not line:
            continue
        parts = line.split("|", 2)
        if len(parts) < 3:
            continue
        try:
            pid = int(parts[0])
            start_epoch = float(parts[1])
        except ValueError:
            continue
        proc_path = parts[2].strip()
        if not proc_path:
            continue
        norm_path = os.path.normcase(os.path.abspath(proc_path))
        if norm_path.startswith(root_prefix) and start_epoch >= (launched_after_epoch - 2.0):
            pids.append(pid)
    return pids


def _discover_steam_workshop_provider(game_root: Path) -> Optional[Path]:
    # game_root is <steamapps>/common/Kenshi
    common_dir = game_root.parent
    steamapps_dir = common_dir.parent
    workshop_root = steamapps_dir / "workshop" / "content" / STEAM_APP_ID
    if not workshop_root.is_dir():
        return None
    for child in sorted(workshop_root.iterdir()):
        if child.is_dir() and (child / PROVIDER_MOD_FILE).is_file():
            return child
    return None


def resolve_installation(
    platform: str,
    game_root_override: Optional[Path] = None,
    allow_unsupported_hash: bool = False,
) -> KenshiInstallation:
    platform = platform.lower()
    if platform not in ("gog", "steam"):
        raise ValueError(f"Unsupported platform: {platform}")

    game_root: Optional[Path] = None
    if game_root_override is not None:
        if not game_root_override.is_dir():
            raise FileNotFoundError(f"Game root does not exist: {game_root_override}")
        game_root = game_root_override.resolve()
    else:
        candidates = DEFAULT_GOG_ROOTS if platform == "gog" else DEFAULT_STEAM_ROOTS
        for candidate in candidates:
            if candidate.is_dir():
                game_root = candidate.resolve()
                break
        if game_root is None:
            raise FileNotFoundError(f"Could not discover {platform.upper()} Kenshi installation")

    if platform == "gog":
        exe_path = game_root / "kenshi_GOG_x64.exe"
        provider_root = game_root / "mods" / "KenshiLua"
    else:
        re_exe = game_root / "RE_Kenshi" / "kenshi_x64.exe"
        exe_path = re_exe if re_exe.is_file() else (game_root / "kenshi_x64.exe")
        workshop_provider = _discover_steam_workshop_provider(game_root)
        provider_root = workshop_provider if workshop_provider is not None else (game_root / "mods" / "KenshiLua")

    if not exe_path.is_file():
        raise FileNotFoundError(f"Kenshi executable not found: {exe_path}")
    if not provider_root.is_dir() or not (provider_root / PROVIDER_MOD_FILE).is_file():
        raise FileNotFoundError(f"Active KenshiLua provider mod not found at: {provider_root}")

    exe_hash = sha256_file(exe_path)
    expected_hash = SUPPORTED_HASHES[platform]
    hash_supported = exe_hash == expected_hash
    if not hash_supported and not allow_unsupported_hash:
        raise RuntimeError(
            f"Unsupported {platform.upper()} executable SHA-256: {exe_hash} "
            f"(expected {expected_hash} for {exe_path})"
        )

    consumer_root = game_root / "mods" / CONSUMER_MOD_NAME
    return KenshiInstallation(
        platform=platform,
        game_root=game_root,
        executable_path=exe_path,
        executable_sha256=exe_hash,
        hash_supported=hash_supported,
        provider_root=provider_root,
        consumer_root=consumer_root,
        mods_cfg_path=game_root / "data" / "mods.cfg",
        re_kenshi_log_path=game_root / "RE_Kenshi_log.txt",
        kenshi_log_path=game_root / "kenshi.log",
    )

