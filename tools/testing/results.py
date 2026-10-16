import json
import xml.etree.ElementTree as ET
from pathlib import Path
from typing import Any, Dict, List, Optional


def load_events_ndjson(events_path: Path) -> List[Dict[str, Any]]:
    if not events_path.is_file():
        return []
    events: List[Dict[str, Any]] = []
    for raw in events_path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = raw.strip()
        if not line:
            continue
        try:
            events.append(json.loads(line))
        except json.JSONDecodeError:
            events.append({"type": "malformed_line", "raw": line})
    return events


def load_result_json(result_path: Path) -> Optional[Dict[str, Any]]:
    if not result_path.is_file():
        return None
    try:
        return json.loads(result_path.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return None


def synthesize_partial_result_from_events(
    events: List[Dict[str, Any]],
    run_id: str,
    platform: str,
    reason: str,
) -> Dict[str, Any]:
    last_phase = "UNINITIALIZED"
    kenshi_version = "unknown"
    kenshilua_version = "unknown"
    elapsed_s = 0.0
    cases: List[Dict[str, Any]] = []
    in_flight: Optional[Dict[str, Any]] = None
    passed = 0
    failed = 0
    skipped = 0

    for ev in events:
        if "elapsed_s" in ev:
            try:
                elapsed_s = max(elapsed_s, float(ev["elapsed_s"]))
            except (TypeError, ValueError):
                pass
        ev_type = ev.get("type")
        if ev_type == "phase":
            last_phase = str(ev.get("phase", last_phase))
            if ev.get("kenshi_version"):
                kenshi_version = str(ev["kenshi_version"])
            if ev.get("kenshilua_version"):
                kenshilua_version = str(ev["kenshilua_version"])
        elif ev_type == "test_start":
            in_flight = {
                "suite": ev.get("suite", "unknown"),
                "name": ev.get("name", "unknown"),
                "phase": ev.get("phase", last_phase),
                "start_elapsed_s": float(ev.get("elapsed_s", 0.0)),
            }
        elif ev_type == "test_result":
            status = str(ev.get("status", "failed"))
            if status == "passed":
                passed += 1
            else:
                failed += 1
            cases.append(
                {
                    "suite": ev.get("suite", "unknown"),
                    "name": ev.get("name", "unknown"),
                    "phase": ev.get("phase", last_phase),
                    "status": status,
                    "duration_s": float(ev.get("duration_s", 0.0)),
                    "frames": int(ev.get("frames", 0)),
                    "error": ev.get("error"),
                }
            )
            in_flight = None
        elif ev_type == "test_skipped":
            skipped += 1
            cases.append(
                {
                    "suite": ev.get("suite", "unknown"),
                    "name": ev.get("name", "unknown"),
                    "phase": ev.get("phase", last_phase),
                    "status": "skipped",
                    "duration_s": 0.0,
                    "frames": 0,
                }
            )

    if in_flight is not None:
        failed += 1
        cases.append(
            {
                "suite": in_flight["suite"],
                "name": in_flight["name"],
                "phase": in_flight["phase"],
                "status": "error",
                "duration_s": max(0.0, elapsed_s - in_flight["start_elapsed_s"]),
                "error": f"Process terminated during test execution ({reason}) in phase {last_phase}",
            }
        )

    return {
        "run_id": run_id,
        "status": "error",
        "partial": True,
        "last_phase": last_phase,
        "passed": passed,
        "failed": failed,
        "skipped": skipped,
        "total": passed + failed,
        "elapsed_s": elapsed_s,
        "kenshi_version": kenshi_version,
        "kenshilua_version": kenshilua_version,
        "kenshi_platform": platform,
        "fatal_error": f"{reason} (last observed phase: {last_phase})",
        "cases": cases,
    }


def write_junit_xml(result: Dict[str, Any], junit_path: Path, platform: str, exe_hash: str) -> None:
    cases = result.get("cases", [])
    total = int(result.get("total", len(cases)))
    failed = int(result.get("failed", 0))
    skipped = int(result.get("skipped", 0))
    status = result.get("status", "unknown")
    errors = 1 if status == "error" else 0
    elapsed = float(result.get("elapsed_s", 0.0))

    suite_el = ET.Element(
        "testsuite",
        attrib={
            "name": f"KenshiLua.{platform}",
            "tests": str(total + skipped),
            "failures": str(failed),
            "skipped": str(skipped),
            "errors": str(errors),
            "time": f"{elapsed:.4f}",
        },
    )

    props_el = ET.SubElement(suite_el, "properties")
    for k, v in (
        ("platform", platform),
        ("executable_sha256", exe_hash),
        ("kenshi_version", str(result.get("kenshi_version", ""))),
        ("kenshilua_version", str(result.get("kenshilua_version", ""))),
        ("run_id", str(result.get("run_id", ""))),
    ):
        ET.SubElement(props_el, "property", attrib={"name": k, "value": v})

    for case in cases:
        suite_name = str(case.get("suite", "default"))
        case_name = str(case.get("name", "unnamed"))
        duration = float(case.get("duration_s", 0.0))
        tc_el = ET.SubElement(
            suite_el,
            "testcase",
            attrib={
                "classname": f"KenshiLua.{platform}.{suite_name}",
                "name": case_name,
                "time": f"{duration:.4f}",
            },
        )
        case_status = str(case.get("status", "passed"))
        if case_status == "skipped":
            ET.SubElement(tc_el, "skipped")
        elif case_status != "passed":
            err_msg = str(case.get("error", "Test failed"))
            first_line = err_msg.splitlines()[0] if err_msg else "Test failed"
            fail_el = ET.SubElement(
                tc_el,
                "failure",
                attrib={"type": case_status, "message": first_line},
            )
            fail_el.text = err_msg

    if status == "error" and result.get("fatal_error"):
        tc_el = ET.SubElement(
            suite_el,
            "testcase",
            attrib={
                "classname": f"KenshiLua.{platform}.harness",
                "name": "fatal_error",
                "time": "0.0000",
            },
        )
        err_el = ET.SubElement(tc_el, "error", attrib={"message": str(result["fatal_error"])})
        err_el.text = str(result["fatal_error"])

    tree = ET.ElementTree(suite_el)
    junit_path.parent.mkdir(parents=True, exist_ok=True)
    tree.write(junit_path, encoding="utf-8", xml_declaration=True)


def format_run_report(
    platform: str,
    exe_path: Path,
    exe_hash: str,
    hash_supported: bool,
    provider_root: Path,
    consumer_root: Path,
    artifact_dir: Path,
    result: Optional[Dict[str, Any]],
    launcher_mode: str,
) -> str:
    lines: List[str] = []
    support_label = "SUPPORTED" if hash_supported else "UNSUPPORTED_HASH"
    lines.append(f"=== KenshiLua In-Game Test Report ({platform.upper()}) ===")
    lines.append(f"Executable : {exe_path}")
    lines.append(f"SHA-256    : {exe_hash} ({support_label})")
    lines.append(f"Provider   : {provider_root}")
    lines.append(f"Consumer   : {consumer_root}")
    lines.append(f"Launcher   : {launcher_mode}")
    lines.append(f"Artifacts  : {artifact_dir}")

    if result is None:
        lines.append("Result     : MISSING (no result.json or events.ndjson produced)")
        return "\n".join(lines)

    lines.append(
        f"Engine     : {result.get('kenshi_version', 'unknown')} | "
        f"KenshiLua {result.get('kenshilua_version', 'unknown')}"
    )
    lines.append(
        f"Summary    : status={result.get('status')} "
        f"passed={result.get('passed', 0)} "
        f"failed={result.get('failed', 0)} "
        f"skipped={result.get('skipped', 0)} "
        f"total={result.get('total', 0)} "
        f"elapsed={result.get('elapsed_s', 0)}s"
    )
    if result.get("fatal_error"):
        lines.append(f"FatalError : {result.get('fatal_error')}")
    for case in result.get("cases", []):
        c_status = str(case.get("status", "passed"))
        if c_status == "passed":
            tag = "PASS"
        elif c_status == "skipped":
            tag = "SKIP"
        elif c_status == "timeout":
            tag = "TIME"
        else:
            tag = "FAIL"
        frames_info = f", {case.get('frames', 0)}f" if case.get("frames") else ""
        lines.append(
            f"  [{tag}] {case.get('suite')}: {case.get('name')} ({case.get('duration_s', 0)}s{frames_info})"
        )
        if c_status not in ("passed", "skipped") and case.get("error"):
            for err_line in str(case["error"]).splitlines():
                lines.append(f"         {err_line}")
    return "\n".join(lines)
