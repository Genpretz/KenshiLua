import json
import os
import shutil
from pathlib import Path
from typing import Any, Dict, List, Optional

from kenshi_install import (
    CONSUMER_MOD_FILE,
    PROVIDER_MOD_FILE,
    KenshiInstallation,
    sha256_file,
)


def _lua_quote(value: str) -> str:
    escaped = (
        value.replace("\\", "\\\\")
        .replace('"', '\\"')
        .replace("\r", "\\r")
        .replace("\n", "\\n")
    )
    return f'"{escaped}"'


def generate_lua_run_config(
    run_id: str,
    artifact_dir: Path,
    suites: List[str],
    provider_mod: str,
    save_name: Optional[str],
    request_exit: bool,
    filter_pattern: Optional[str] = None,
    test_timeout_s: float = 10.0,
    world_timeout_s: float = 45.0,
    save_snapshot_as: Optional[str] = None,
) -> str:
    events_path = artifact_dir / "events.ndjson"
    result_path = artifact_dir / "result.json"
    suite_items = ", ".join(_lua_quote(s) for s in suites)
    save_literal = _lua_quote(save_name) if save_name else "nil"
    filter_literal = _lua_quote(filter_pattern) if filter_pattern else '""'
    snapshot_literal = _lua_quote(save_snapshot_as) if save_snapshot_as else "nil"
    exit_literal = "true" if request_exit else "false"
    return (
        "return {\n"
        f"    run_id = {_lua_quote(run_id)},\n"
        f"    artifact_dir = {_lua_quote(str(artifact_dir))},\n"
        f"    events_path = {_lua_quote(str(events_path))},\n"
        f"    result_path = {_lua_quote(str(result_path))},\n"
        f"    provider_mod = {_lua_quote(provider_mod)},\n"
        f"    suites = {{ {suite_items} }},\n"
        f"    filter = {filter_literal},\n"
        f"    save_name = {save_literal},\n"
        f"    save_snapshot_as = {snapshot_literal},\n"
        f"    test_timeout_s = {float(test_timeout_s):.3f},\n"
        f"    world_timeout_s = {float(world_timeout_s):.3f},\n"
        f"    request_exit = {exit_literal},\n"
        "}\n"
    )


def get_user_kenshi_save_root() -> Path:
    local_app_data = os.environ.get("LOCALAPPDATA")
    if local_app_data:
        return Path(local_app_data) / "kenshi" / "save"
    return Path.home() / "AppData" / "Local" / "kenshi" / "save"


class StagingTransaction:
    def __init__(
        self,
        repo_root: Path,
        install: KenshiInstallation,
        artifact_dir: Path,
        run_id: str,
        dll_under_test: Path,
        preload_dll: Path,
        suites: List[str],
        save_name: Optional[str],
        event_name: str,
        filter_pattern: Optional[str] = None,
        test_timeout_s: float = 10.0,
        world_timeout_s: float = 45.0,
        save_fixture_dir: Optional[Path] = None,
        save_snapshot_as: Optional[str] = None,
    ) -> None:
        self.repo_root = repo_root
        self.install = install
        self.artifact_dir = artifact_dir
        self.backup_dir = artifact_dir / "backups"
        self.journal_path = artifact_dir / "journal.json"
        self.run_id = run_id
        self.dll_under_test = dll_under_test
        self.preload_dll = preload_dll
        self.suites = suites
        self.save_name = save_name
        self.event_name = event_name
        self.filter_pattern = filter_pattern
        self.test_timeout_s = test_timeout_s
        self.world_timeout_s = world_timeout_s
        self.save_fixture_dir = save_fixture_dir
        self.save_snapshot_as = save_snapshot_as
        self.entries: List[Dict[str, Any]] = []
        self._tracked_paths: set[str] = set()

    def _norm(self, path: Path) -> str:
        return str(path.resolve()).lower()

    def _save_journal(self) -> None:
        self.artifact_dir.mkdir(parents=True, exist_ok=True)
        payload = {
            "run_id": self.run_id,
            "platform": self.install.platform,
            "game_root": str(self.install.game_root),
            "entries": self.entries,
        }
        self.journal_path.write_text(json.dumps(payload, indent=2), encoding="utf-8")

    def _record_file(self, target: Path) -> None:
        key = self._norm(target)
        if key in self._tracked_paths:
            return
        self._tracked_paths.add(key)
        self.backup_dir.mkdir(parents=True, exist_ok=True)
        existed = target.exists()
        backup_file: Optional[Path] = None
        original_hash: Optional[str] = None
        if existed:
            if target.is_dir():
                raise IsADirectoryError(f"Expected file path but found directory: {target}")
            backup_file = self.backup_dir / f"backup_{len(self.entries):03d}_{target.name}"
            shutil.copy2(target, backup_file)
            original_hash = sha256_file(target)

        self.entries.append(
            {
                "kind": "file",
                "target": str(target),
                "existed": existed,
                "backup": str(backup_file) if backup_file else None,
                "sha256": original_hash,
            }
        )
        self._save_journal()

    def _ensure_dir(self, directory: Path) -> None:
        missing: List[Path] = []
        cur = directory
        while not cur.exists():
            missing.append(cur)
            parent = cur.parent
            if parent == cur:
                break
            cur = parent
        for d in reversed(missing):
            key = self._norm(d)
            if key not in self._tracked_paths:
                self._tracked_paths.add(key)
                self.entries.append(
                    {
                        "kind": "dir",
                        "target": str(d),
                        "existed": False,
                        "backup": None,
                        "sha256": None,
                    }
                )
                self._save_journal()
            d.mkdir(parents=True, exist_ok=True)

    def _stage_copy(self, src: Path, dst: Path) -> None:
        self._ensure_dir(dst.parent)
        self._record_file(dst)
        shutil.copy2(src, dst)

    def _stage_text(self, dst: Path, content: str, encoding: str = "utf-8") -> None:
        self._ensure_dir(dst.parent)
        self._record_file(dst)
        dst.write_text(content, encoding=encoding)

    def _stage_tree(self, src_root: Path, dst_root: Path) -> None:
        for item in sorted(src_root.rglob("*")):
            rel = item.relative_to(src_root)
            target = dst_root / rel
            if item.is_dir():
                self._ensure_dir(target)
            elif item.is_file():
                self._stage_copy(item, target)

    def plan_summary(self) -> Dict[str, Any]:
        return {
            "run_id": self.run_id,
            "platform": self.install.platform,
            "game_root": str(self.install.game_root),
            "executable_path": str(self.install.executable_path),
            "executable_sha256": self.install.executable_sha256,
            "provider_root": str(self.install.provider_root),
            "consumer_root": str(self.install.consumer_root),
            "dll_under_test": str(self.dll_under_test),
            "preload_dll": str(self.preload_dll),
            "mods_cfg": str(self.install.mods_cfg_path),
            "suites": self.suites,
            "filter": self.filter_pattern or "",
            "save_name": self.save_name,
            "save_fixture_dir": str(self.save_fixture_dir) if self.save_fixture_dir else None,
        }

    def apply(self) -> None:
        # 1. Backup baseline game config files that Kenshi launcher or game may touch
        for baseline in (
            self.install.mods_cfg_path,
            self.install.game_root / "settings.cfg",
            self.install.game_root / "ogre.cfg",
            self.install.game_root / "RE_Kenshi.ini",
        ):
            self._record_file(baseline)

        # 2. Stage KenshiLua.dll under test into provider mod
        provider_plugin_dir = self.install.provider_root / "plugin"
        self._stage_copy(self.dll_under_test, provider_plugin_dir / "KenshiLua.dll")

        # 3. Stage preload helper DLL and preload.cfg into provider mod and register in RE_Kenshi.json
        preload_target = provider_plugin_dir / "KenshiLuaTestPreload.dll"
        preload_cfg_target = provider_plugin_dir / "preload.cfg"
        preload_log_path = self.artifact_dir / "preload.log"
        self._stage_copy(self.preload_dll, preload_target)
        self._stage_text(
            preload_cfg_target,
            f"event_name={self.event_name}\nlog_path={preload_log_path}\n",
            encoding="ascii",
        )

        re_json_path = self.install.provider_root / "RE_Kenshi.json"
        if not re_json_path.is_file():
            raise FileNotFoundError(f"Provider RE_Kenshi.json not found: {re_json_path}")
        re_cfg = json.loads(re_json_path.read_text(encoding="utf-8"))
        if "PreloadPlugins" in re_cfg:
            raise RuntimeError(f"Existing PreloadPlugins entry in {re_json_path}; refusing to overwrite")
        re_cfg["PreloadPlugins"] = ["plugin/KenshiLuaTestPreload.dll"]
        self._stage_text(re_json_path, json.dumps(re_cfg, indent=4) + "\n", encoding="ascii")

        # 3b. Neutralize third-party PreloadPlugins in other mods' RE_Kenshi.json
        # RE_Kenshi loads PreloadPlugins from all mods before reading mods.cfg.
        mods_root = self.install.game_root / "mods"
        if mods_root.is_dir():
            for other_re_json in sorted(mods_root.rglob("RE_Kenshi.json")):
                if self._norm(other_re_json) == self._norm(re_json_path):
                    continue
                try:
                    other_cfg = json.loads(other_re_json.read_text(encoding="utf-8"))
                except Exception:
                    continue
                if isinstance(other_cfg, dict) and other_cfg.get("PreloadPlugins"):
                    other_cfg["PreloadPlugins"] = []
                    self._stage_text(other_re_json, json.dumps(other_cfg, indent=4) + "\n", encoding="utf-8")

        # 4. Stage provider fixture scripts when script-loading/smoke/all suite is selected
        fixtures_root = self.repo_root / "tests" / "in_game"
        if any(s in ("script-loading", "smoke", "all") for s in self.suites):
            provider_fixture = fixtures_root / "script_loading" / "provider" / "scripts"
            self._stage_tree(provider_fixture, self.install.provider_root / "scripts")

        # 5. Stage dedicated consumer mod ("KenshiLua Tests")
        mod_descriptor_src = fixtures_root / "fixtures" / CONSUMER_MOD_FILE
        self._stage_copy(mod_descriptor_src, self.install.consumer_root / CONSUMER_MOD_FILE)

        harness_scripts = fixtures_root / "harness" / "scripts"
        self._stage_tree(harness_scripts, self.install.consumer_root / "scripts")

        if any(s in ("script-loading", "smoke", "all") for s in self.suites):
            consumer_fixture = fixtures_root / "script_loading" / "consumer" / "scripts"
            self._stage_tree(consumer_fixture, self.install.consumer_root / "scripts")

        # 6. Stage save fixture directory if requested and present on disk
        if (
            self.save_name
            and not self.save_name.startswith("@newgame")
            and self.save_fixture_dir
            and self.save_fixture_dir.is_dir()
        ):
            user_save_target = get_user_kenshi_save_root() / self.save_name
            self._stage_tree(self.save_fixture_dir, user_save_target)
            local_save_root = self.install.game_root / "save"
            if local_save_root.is_dir():
                self._stage_tree(self.save_fixture_dir, local_save_root / self.save_name)

        run_cfg_lua = generate_lua_run_config(
            run_id=self.run_id,
            artifact_dir=self.artifact_dir,
            suites=self.suites,
            provider_mod=PROVIDER_MOD_FILE,
            save_name=self.save_name,
            request_exit=True,
            filter_pattern=self.filter_pattern,
            test_timeout_s=self.test_timeout_s,
            world_timeout_s=self.world_timeout_s,
            save_snapshot_as=self.save_snapshot_as,
        )
        self._stage_text(
            self.install.consumer_root / "scripts" / "kltest" / "run_config.lua",
            run_cfg_lua,
            encoding="utf-8",
        )

        # 7. Write deterministic data/mods.cfg enabling provider and consumer mods
        mods_cfg_content = f"{PROVIDER_MOD_FILE}\n{CONSUMER_MOD_FILE}\n"
        self._stage_text(self.install.mods_cfg_path, mods_cfg_content, encoding="ascii")

    def restore(self) -> List[str]:
        return replay_journal(self.journal_path)


def replay_journal(journal_path: Path) -> List[str]:
    if not journal_path.is_file():
        return []
    data = json.loads(journal_path.read_text(encoding="utf-8"))
    entries: List[Dict[str, Any]] = data.get("entries", [])
    errors: List[str] = []

    for entry in reversed(entries):
        kind = entry.get("kind")
        target = Path(entry["target"])
        existed = bool(entry.get("existed"))
        backup_str = entry.get("backup")
        expected_hash = entry.get("sha256")

        try:
            if kind == "file":
                if existed:
                    if not backup_str or not Path(backup_str).is_file():
                        errors.append(f"Missing backup for {target}: {backup_str}")
                        continue
                    target.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(Path(backup_str), target)
                    actual_hash = sha256_file(target)
                    if expected_hash and actual_hash != expected_hash:
                        errors.append(
                            f"SHA-256 mismatch restoring {target}: expected {expected_hash}, got {actual_hash}"
                        )
                else:
                    if target.exists() or target.is_symlink():
                        target.unlink()
            elif kind == "dir":
                if not existed and target.is_dir():
                    try:
                        target.rmdir()
                    except OSError:
                        shutil.rmtree(target, ignore_errors=True)
        except Exception as exc:
            errors.append(f"Failed restoring {target}: {exc}")

    return errors
