import argparse
import datetime as dt
import json
import shutil
import subprocess
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional

from kenshi_install import (
    KenshiInstallation,
    find_processes_under_root,
    find_running_kenshi_processes,
    resolve_installation,
    sha256_file,
)
from launcher_windows import (
    NamedRunEvent,
    inspect_process_windows,
    post_wm_close_to_pids,
    try_dismiss_launcher_external,
)
from results import (
    format_run_report,
    load_events_ndjson,
    load_result_json,
    synthesize_partial_result_from_events,
    write_junit_xml,
)
from staging import StagingTransaction, get_user_kenshi_save_root, replay_journal

EXIT_OK = 0
EXIT_TEST_FAILED = 1
EXIT_SETUP_ERROR = 2
EXIT_CRASH_OR_TIMEOUT = 3

DEFAULT_SAVE_FIXTURE_NAME = "kltest_vanilla_1065"
SAVE_DEPENDENT_SUITES = {"world-smoke", "binding-smoke", "all"}


def _stop_pids(pids: List[int], grace_seconds: float = 5.0) -> None:
    if not pids:
        return
    deadline = time.time() + grace_seconds
    while time.time() < deadline:
        alive = [p for p in pids if _is_pid_alive(p)]
        if not alive:
            return
        time.sleep(0.25)

    alive = [p for p in pids if _is_pid_alive(p)]
    if alive:
        post_wm_close_to_pids(alive)
        close_deadline = time.time() + 3.0
        while time.time() < close_deadline:
            alive = [p for p in pids if _is_pid_alive(p)]
            if not alive:
                return
            time.sleep(0.25)

    for pid in [p for p in pids if _is_pid_alive(p)]:
        subprocess.run(
            ["taskkill", "/PID", str(pid), "/F"],
            capture_output=True,
            text=True,
            check=False,
        )
    final_deadline = time.time() + 5.0
    while time.time() < final_deadline:
        if not any(_is_pid_alive(p) for p in pids):
            return
        time.sleep(0.2)


def _is_pid_alive(pid: int) -> bool:
    res = subprocess.run(
        ["powershell", "-NoProfile", "-Command", f"if (Get-Process -Id {pid} -ErrorAction SilentlyContinue) {{ '1' }}"],
        capture_output=True,
        text=True,
        check=False,
    )
    return res.stdout.strip() == "1"


def run_single_platform(
    repo_root: Path,
    platform: str,
    suites: List[str],
    dll_path: Path,
    preload_dll_path: Path,
    game_root_override: Optional[Path],
    save_name: Optional[str],
    save_fixture_dir: Optional[Path],
    save_snapshot_as: Optional[str],
    filter_pattern: Optional[str],
    launcher_timeout: float,
    startup_timeout: float,
    suite_timeout: float,
    test_timeout: float,
    world_timeout: float,
    dry_run: bool,
    allow_unsupported_hash: bool,
) -> int:
    running = find_running_kenshi_processes()
    if running:
        print(f"[ERROR] Kenshi is already running ({running}); refusing to stage.", file=sys.stderr)
        return EXIT_SETUP_ERROR

    try:
        install: KenshiInstallation = resolve_installation(
            platform=platform,
            game_root_override=game_root_override,
            allow_unsupported_hash=allow_unsupported_hash,
        )
    except Exception as exc:
        print(f"[ERROR] Installation preflight failed for {platform}: {exc}", file=sys.stderr)
        return EXIT_SETUP_ERROR

    effective_save_name = save_name
    if effective_save_name is None and any(s in SAVE_DEPENDENT_SUITES for s in suites):
        effective_save_name = DEFAULT_SAVE_FIXTURE_NAME

    timestamp = dt.datetime.now().strftime("%Y%m%d-%H%M%S")
    run_id = f"{platform}-{timestamp}"
    artifact_dir = (repo_root / "scratch" / "kenshi-tests" / run_id).resolve()
    event_name = f"Local\\KenshiLuaTestPreloadRun_{run_id}"

    tx = StagingTransaction(
        repo_root=repo_root,
        install=install,
        artifact_dir=artifact_dir,
        run_id=run_id,
        dll_under_test=dll_path,
        preload_dll=preload_dll_path,
        suites=suites,
        save_name=effective_save_name,
        event_name=event_name,
        filter_pattern=filter_pattern,
        test_timeout_s=test_timeout,
        world_timeout_s=world_timeout,
        save_fixture_dir=save_fixture_dir,
        save_snapshot_as=save_snapshot_as,
    )

    if dry_run:
        print(json.dumps(tx.plan_summary(), indent=2))
        return EXIT_OK

    artifact_dir.mkdir(parents=True, exist_ok=True)
    metadata = {
        **tx.plan_summary(),
        "dll_sha256": sha256_file(dll_path),
        "preload_dll_sha256": sha256_file(preload_dll_path),
        "hash_supported": install.hash_supported,
    }
    (artifact_dir / "run_metadata.json").write_text(json.dumps(metadata, indent=2), encoding="utf-8")

    run_event = NamedRunEvent(event_name)
    owned_pids: List[int] = []
    launched_epoch = time.time()
    launcher_mode = "unknown"
    termination_reason = "timeout"
    preload_log_path = artifact_dir / "preload.log"
    result_path = artifact_dir / "result.json"
    events_path = artifact_dir / "events.ndjson"
    window_snapshots: List[Dict[str, Any]] = []

    try:
        run_event.create_signaled()
        tx.apply()

        launched_epoch = time.time()
        if platform == "gog":
            startupinfo = subprocess.STARTUPINFO()
            startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
            startupinfo.wShowWindow = 0  # SW_HIDE
            proc = subprocess.Popen(
                [str(install.executable_path)],
                cwd=str(install.game_root),
                startupinfo=startupinfo,
            )
            owned_pids.append(proc.pid)
        else:
            subprocess.run(
                ["powershell", "-NoProfile", "-Command", "Start-Process 'steam://rungameid/233860'"],
                check=True,
            )

        extra_world_budget = world_timeout if effective_save_name else 0.0
        total_deadline = launched_epoch + launcher_timeout + startup_timeout + suite_timeout + extra_world_budget
        launcher_dismissed = False

        while time.time() < total_deadline:
            discovered = find_processes_under_root(install.game_root, launched_epoch)
            for pid in discovered:
                if pid not in owned_pids:
                    owned_pids.append(pid)

            if preload_log_path.is_file():
                preload_text = preload_log_path.read_text(encoding="utf-8", errors="replace")
                if "OK_RETURN" in preload_text and not launcher_dismissed:
                    launcher_dismissed = True
                    launcher_mode = "preload_helper (ID 1003)"

            # External Win32 fallback if launcher dialog is still open after 3.5s
            if not launcher_dismissed and owned_pids and (time.time() - launched_epoch) >= 3.5:
                snap = inspect_process_windows(owned_pids)
                if snap:
                    window_snapshots.extend(snap)
                ext = try_dismiss_launcher_external(owned_pids)
                if ext and ext.get("posted"):
                    launcher_dismissed = True
                    launcher_mode = f"external_win32_fallback ({ext['dialog_hwnd']} ID 1003)"

            if result_path.is_file():
                termination_reason = "completed"
                break

            # Detect RE_Kenshi crash dialog immediately without waiting for full timeout
            if install.re_kenshi_log_path.is_file():
                try:
                    if install.re_kenshi_log_path.stat().st_mtime >= (launched_epoch - 1.0):
                        re_log_text = install.re_kenshi_log_path.read_text(encoding="utf-8", errors="replace")
                        if "Crash detected" in re_log_text or "probably crashing" in re_log_text:
                            termination_reason = "engine_crash_detected"
                            break
                except OSError:
                    pass

            # Detect early exit before result.json was written
            if owned_pids and (time.time() - launched_epoch) > 5.0:
                if not any(_is_pid_alive(p) for p in owned_pids) and not result_path.is_file():
                    termination_reason = "process_exited_without_result"
                    break

            time.sleep(0.5)

    finally:
        run_event.reset_and_close()
        discovered = find_processes_under_root(install.game_root, launched_epoch)
        for pid in discovered:
            if pid not in owned_pids:
                owned_pids.append(pid)

        _stop_pids(owned_pids, grace_seconds=4.0)

        # Collect logs before restoring files
        kenshilua_log = install.provider_root / "logs" / "KenshiLua.log"
        for src_log, dst_name in (
            (install.re_kenshi_log_path, "RE_Kenshi_log.txt"),
            (install.kenshi_log_path, "kenshi.log"),
            (kenshilua_log, "KenshiLua.log"),
        ):
            if src_log.is_file():
                try:
                    shutil.copy2(src_log, artifact_dir / dst_name)
                except OSError:
                    pass

        if window_snapshots:
            (artifact_dir / "window_diagnostics.json").write_text(
                json.dumps(window_snapshots, indent=2),
                encoding="utf-8",
            )

        restore_errors = tx.restore()

    if restore_errors:
        print(f"[ERROR] Restoration errors for {platform}: {restore_errors}", file=sys.stderr)
        return EXIT_SETUP_ERROR

    result = load_result_json(result_path)
    events = load_events_ndjson(events_path)
    if result is None and events:
        result = synthesize_partial_result_from_events(
            events=events,
            run_id=run_id,
            platform=platform,
            reason=termination_reason,
        )
        (artifact_dir / "partial_result.json").write_text(
            json.dumps(result, indent=2),
            encoding="utf-8",
        )

    if result is not None:
        write_junit_xml(result, artifact_dir / "junit.xml", platform, install.executable_sha256)

    report = format_run_report(
        platform=platform,
        exe_path=install.executable_path,
        exe_hash=install.executable_sha256,
        hash_supported=install.hash_supported,
        provider_root=install.provider_root,
        consumer_root=install.consumer_root,
        artifact_dir=artifact_dir,
        result=result,
        launcher_mode=launcher_mode,
    )
    print(report)

    if result is None or result.get("partial"):
        return EXIT_CRASH_OR_TIMEOUT
    if result.get("status") == "passed" and int(result.get("failed", 0)) == 0:
        return EXIT_OK
    if result.get("status") == "failed":
        return EXIT_TEST_FAILED
    return EXIT_CRASH_OR_TIMEOUT


def prepare_save_fixture(
    repo_root: Path,
    platform: str,
    from_save: str,
    target_fixture_dir: Path,
    dll_path: Path,
    preload_dll_path: Path,
    game_root_override: Optional[Path],
    allow_unsupported_hash: bool,
) -> int:
    snapshot_name = "_kltest_tmp_snapshot"
    user_save_root = get_user_kenshi_save_root()
    snapshot_dir = user_save_root / snapshot_name
    if snapshot_dir.exists():
        shutil.rmtree(snapshot_dir, ignore_errors=True)

    try:
        code = run_single_platform(
            repo_root=repo_root,
            platform=platform,
            suites=["world-smoke"],
            dll_path=dll_path,
            preload_dll_path=preload_dll_path,
            game_root_override=game_root_override,
            save_name=from_save,
            save_fixture_dir=None,
            save_snapshot_as=snapshot_name,
            filter_pattern=None,
            launcher_timeout=15.0,
            startup_timeout=30.0,
            suite_timeout=45.0,
            test_timeout=15.0,
            world_timeout=60.0,
            dry_run=False,
            allow_unsupported_hash=allow_unsupported_hash,
        )
        if code != EXIT_OK:
            return code
        if not snapshot_dir.is_dir():
            print(f"[ERROR] Snapshot save directory was not created at {snapshot_dir}", file=sys.stderr)
            return EXIT_SETUP_ERROR

        if target_fixture_dir.exists():
            shutil.rmtree(target_fixture_dir)
        target_fixture_dir.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(snapshot_dir, target_fixture_dir)

        files_manifest: List[Dict[str, Any]] = []
        total_bytes = 0
        for item in sorted(target_fixture_dir.rglob("*")):
            if item.is_file():
                rel = str(item.relative_to(target_fixture_dir)).replace("\\", "/")
                size = item.stat().st_size
                total_bytes += size
                files_manifest.append(
                    {
                        "path": rel,
                        "size": size,
                        "sha256": sha256_file(item),
                    }
                )

        manifest_path = repo_root / "tests" / "in_game" / "fixtures" / "save_fixture_manifest.json"
        manifest = {
            "fixture_name": DEFAULT_SAVE_FIXTURE_NAME,
            "source_save": from_save,
            "created_on_platform": platform,
            "kenshi_version": "1.0.65",
            "file_count": len(files_manifest),
            "total_bytes": total_bytes,
            "files": files_manifest,
        }
        manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
        print(f"Prepared save fixture at: {target_fixture_dir} ({len(files_manifest)} files, {total_bytes} bytes)")
        print(f"Wrote fixture manifest : {manifest_path}")
        return EXIT_OK
    finally:
        if snapshot_dir.exists():
            shutil.rmtree(snapshot_dir, ignore_errors=True)


def main() -> int:
    repo_root = Path(__file__).resolve().parents[2]
    default_dll = repo_root / "bin" / "KenshiLua" / "plugin" / "KenshiLua.dll"
    default_preload_dll = (
        repo_root
        / "tools"
        / "testing"
        / "native"
        / "KenshiLuaTestPreload"
        / "bin"
        / "KenshiLuaTestPreload.dll"
    )
    default_fixture_dir = repo_root / "scratch" / "kenshi-tests" / "fixtures" / DEFAULT_SAVE_FIXTURE_NAME

    parser = argparse.ArgumentParser(description="Run automated in-game KenshiLua test suites.")
    parser.add_argument("--platform", choices=["gog", "steam", "all"], default="gog")
    parser.add_argument("--suite", default="script-loading", help="Suite name or comma-separated list")
    parser.add_argument("--filter", default=None, help="Filter test cases by substring or pattern")
    parser.add_argument("--game-root", type=Path, default=None, help="Override Kenshi installation root")
    parser.add_argument("--dll", type=Path, default=default_dll, help="Path to KenshiLua.dll under test")
    parser.add_argument(
        "--preload-dll",
        type=Path,
        default=default_preload_dll,
        help="Path to KenshiLuaTestPreload.dll helper",
    )
    parser.add_argument("--save", default=None, help="Save fixture name for save-dependent suites")
    parser.add_argument(
        "--save-fixture-dir",
        type=Path,
        default=default_fixture_dir,
        help="Local directory containing the staged save fixture",
    )
    parser.add_argument(
        "--prepare-save-fixture",
        action="store_true",
        help="Bootstrap a clean save fixture under --save-fixture-dir from --from-save",
    )
    parser.add_argument(
        "--from-save",
        default="@newgame",
        help="Save name or @newgame[:startId] to snapshot when --prepare-save-fixture is used",
    )
    parser.add_argument("--launcher-timeout", type=float, default=15.0)
    parser.add_argument("--startup-timeout", type=float, default=30.0)
    parser.add_argument("--suite-timeout", type=float, default=30.0)
    parser.add_argument("--test-timeout", type=float, default=10.0)
    parser.add_argument("--world-timeout", type=float, default=45.0)
    parser.add_argument("--keep-artifacts", action="store_true", default=True)
    parser.add_argument("--dry-run", action="store_true", help="Print staging transaction without modifying files")
    parser.add_argument("--allow-unsupported-hash", action="store_true")
    parser.add_argument("--recover-journal", type=Path, default=None, help="Replay an incomplete journal.json")
    args = parser.parse_args()

    if args.recover_journal is not None:
        errors = replay_journal(args.recover_journal.resolve())
        if errors:
            print(f"[ERROR] Journal replay errors: {errors}", file=sys.stderr)
            return EXIT_SETUP_ERROR
        print(f"Successfully replayed journal: {args.recover_journal}")
        return EXIT_OK

    dll_path = args.dll.resolve()
    preload_dll_path = args.preload_dll.resolve()
    if not dll_path.is_file():
        print(f"[ERROR] KenshiLua DLL not found: {dll_path}", file=sys.stderr)
        return EXIT_SETUP_ERROR
    if not preload_dll_path.is_file():
        print(f"[ERROR] Preload helper DLL not found: {preload_dll_path}", file=sys.stderr)
        return EXIT_SETUP_ERROR

    if args.prepare_save_fixture:
        plat = "gog" if args.platform == "all" else args.platform
        return prepare_save_fixture(
            repo_root=repo_root,
            platform=plat,
            from_save=args.from_save,
            target_fixture_dir=args.save_fixture_dir.resolve(),
            dll_path=dll_path,
            preload_dll_path=preload_dll_path,
            game_root_override=args.game_root,
            allow_unsupported_hash=args.allow_unsupported_hash,
        )

    suites = [s.strip() for s in args.suite.split(",") if s.strip()]
    platforms = ["gog", "steam"] if args.platform == "all" else [args.platform]

    needs_save = (args.save is not None) or any(s in SAVE_DEPENDENT_SUITES for s in suites)
    effective_fixture_name = args.save or DEFAULT_SAVE_FIXTURE_NAME
    target_fixture_dir = args.save_fixture_dir.resolve()
    if needs_save and effective_fixture_name == DEFAULT_SAVE_FIXTURE_NAME and not args.dry_run:
        has_files = target_fixture_dir.is_dir() and any(target_fixture_dir.iterdir())
        if not has_files:
            bootstrap_plat = "gog" if "gog" in platforms else platforms[0]
            print(f"[INFO] Save fixture '{DEFAULT_SAVE_FIXTURE_NAME}' not found; auto-bootstrapping on {bootstrap_plat}...")
            prep_code = prepare_save_fixture(
                repo_root=repo_root,
                platform=bootstrap_plat,
                from_save=args.from_save,
                target_fixture_dir=target_fixture_dir,
                dll_path=dll_path,
                preload_dll_path=preload_dll_path,
                game_root_override=args.game_root,
                allow_unsupported_hash=args.allow_unsupported_hash,
            )
            if prep_code != EXIT_OK:
                print(f"[ERROR] Auto-bootstrap of save fixture failed with code {prep_code}", file=sys.stderr)
                return prep_code

    overall_code = EXIT_OK
    for plat in platforms:
        code = run_single_platform(
            repo_root=repo_root,
            platform=plat,
            suites=suites,
            dll_path=dll_path,
            preload_dll_path=preload_dll_path,
            game_root_override=args.game_root,
            save_name=args.save,
            save_fixture_dir=args.save_fixture_dir.resolve(),
            save_snapshot_as=None,
            filter_pattern=args.filter,
            launcher_timeout=args.launcher_timeout,
            startup_timeout=args.startup_timeout,
            suite_timeout=args.suite_timeout,
            test_timeout=args.test_timeout,
            world_timeout=args.world_timeout,
            dry_run=args.dry_run,
            allow_unsupported_hash=args.allow_unsupported_hash,
        )
        if code != EXIT_OK:
            overall_code = max(overall_code, code)

    return overall_code


if __name__ == "__main__":
    sys.exit(main())
