# generate_callbacks_reference.py
"""
Generates docs/CallbacksReference.md by scanning src/Callbacks.h and src/Hooks.cpp.

Usage:
    python tools/generate_callbacks_reference.py
"""

import os
import re
import pathlib

PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[1]
CALLBACKS_HEADER = PROJECT_ROOT / "src" / "Callbacks.h"
HOOKS_CPP = PROJECT_ROOT / "src" / "Hooks.cpp"
OUTPUT_MD = PROJECT_ROOT / "docs" / "CallbacksReference.md"

TYPE_MAP = {
    'int': 'integer',
    'short': 'integer',
    'long': 'integer',
    'unsigned int': 'integer',
    'size_t': 'integer',
    'int64_t': 'integer',
    'float': 'number',
    'double': 'number',
    'bool': 'boolean',
    'std::string': 'string',
    'const std::string&': 'string',
    'const std::string &': 'string',
    'const Ogre::Vector3&': 'Vector3',
    'const Ogre::Vector3 &': 'Vector3',
    'Ogre::Vector3': 'Vector3',
    'const hand&': 'hand',
    'const hand &': 'hand',
    'hand': 'hand',
    'void*': 'lightuserdata',
    'void *': 'lightuserdata',
}

def clean_cpp_type(raw_type):
    t = raw_type.strip()
    t = re.sub(r'=\s*[^,)]+', '', t).strip()
    if t in TYPE_MAP:
        return TYPE_MAP[t]
    
    t_clean = re.sub(r'\bconst\s+', '', t).strip()
    t_clean = t_clean.replace('wraps::', '').replace('MyGUI::', '').replace('Ogre::', '')
    
    m_lek = re.match(r'lektor<([^>]+)>\s*&?', t_clean)
    if m_lek:
        inner = clean_cpp_type(m_lek.group(1))
        return f"lektor<{inner}>"
        
    base = t_clean.replace('*', '').replace('&', '').strip()
    
    if base in TYPE_MAP:
        return TYPE_MAP[base]
    if base:
        return base
    return raw_type

def parse_params(params_str):
    if not params_str or params_str.strip() == 'void':
        return []
    
    parts = []
    current = []
    depth = 0
    for char in params_str:
        if char in '<(':
            depth += 1
            current.append(char)
        elif char in '>)':
            depth -= 1
            current.append(char)
        elif char == ',' and depth == 0:
            parts.append(''.join(current).strip())
            current = []
        else:
            current.append(char)
    if current:
        parts.append(''.join(current).strip())
    
    parsed = []
    for p in parts:
        p = p.strip()
        if '=' in p:
            p = p.split('=')[0].strip()
        
        m = re.match(r'^(.*?)([\*\&\s])([A-Za-z0-9_]+)$', p)
        if m:
            raw_type = (m.group(1) + m.group(2)).strip()
            name = m.group(3).strip()
            lua_type = clean_cpp_type(raw_type)
            parsed.append((name, lua_type, raw_type))
        else:
            parsed.append((p, clean_cpp_type(p), p))
    return parsed

def get_typed_lua_sig(lua_sig, params_list, ret_type_clean):
    m = re.match(r'function\s*\((.*?)\)(?:\s*->\s*(.*))?', lua_sig) if lua_sig else None
    if m:
        lua_param_names = [x.strip() for x in m.group(1).split(',') if x.strip()]
        typed_parts = []
        for i, pname in enumerate(lua_param_names):
            if i < len(params_list):
                ptype = params_list[i][1]
            else:
                ptype = "any"
            typed_parts.append(f"{pname}: {ptype}")
        sig_str = f"function({', '.join(typed_parts)})"
    else:
        typed_parts = [f"{name}: {ptype}" for name, ptype, _ in params_list]
        sig_str = f"function({', '.join(typed_parts)})"

    if ret_type_clean and ret_type_clean != 'void':
        sig_str += f" -> {ret_type_clean}"
    return sig_str

def parse_hooks_registry():
    """Extract eventName -> installer map from g_eventHookRegistry in Hooks.cpp."""
    event_map = {}
    if not HOOKS_CPP.exists():
        return event_map

    content = HOOKS_CPP.read_text(encoding="utf-8", errors="ignore")
    match = re.search(r"g_eventHookRegistry\[\]\s*=\s*\{([^\}]+)\};", content, re.DOTALL)
    if match:
        body = match.group(1)
        entries = re.findall(r'\{\s*"([^"]+)"\s*,\s*([^\s,\}]+)\s*\}', body)
        for event_name, installer in entries:
            event_map[event_name] = installer
    return event_map

def parse_callbacks_header():
    """Parse src/Callbacks.h for callback dispatcher functions and their comment metadata."""
    if not CALLBACKS_HEADER.exists():
        return []

    content = CALLBACKS_HEADER.read_text(encoding="utf-8", errors="ignore")
    lines = content.splitlines()

    callbacks = []
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        
        # Look for dispatcher function declaration
        if line.endswith(';') and ('Call' in line) and ('Callbacks(' in line):
            # Parse function signature
            func_sig = line
            
            # Extract return type and function name
            match = re.match(r"^([\w<>:\*\&\s]+?)\s+(Call\w+Callbacks)\s*\((.*)\);$", func_sig)
            if match:
                ret_type = match.group(1).strip()
                func_name = match.group(2).strip()
                params = match.group(3).strip()

                # Gather preceding comments
                comments = []
                j = i - 1
                while j >= 0 and lines[j].strip().startswith('//'):
                    comments.insert(0, lines[j].strip()[2:].strip())
                    j -= 1

                fired_by = ""
                lua_event = ""
                lua_sig = ""
                extra_notes = []

                for c in comments:
                    if c.startswith("Fired by"):
                        fired_by = c.replace("Fired by", "").strip().rstrip('.')
                    elif c.startswith("Lua event name:"):
                        ev = c.replace("Lua event name:", "").strip().strip('"')
                        if ev:
                            lua_event = ev
                    elif c.startswith("Lua signature:"):
                        lua_sig = c.replace("Lua signature:", "").strip()
                    else:
                        extra_notes.append(c)

                parsed_params = parse_params(params)
                ret_clean = clean_cpp_type(ret_type)

                # Use parameter names from lua_sig if available and parameter count matches
                m_sig = re.match(r'function\s*\((.*?)\)', lua_sig) if lua_sig else None
                if m_sig:
                    sig_names = [x.strip() for x in m_sig.group(1).split(',') if x.strip()]
                    if len(sig_names) == len(parsed_params):
                        effective_params = [(sig_names[idx], p[1]) for idx, p in enumerate(parsed_params)]
                    else:
                        effective_params = [(p[0], p[1]) for p in parsed_params]
                else:
                    effective_params = [(p[0], p[1]) for p in parsed_params]

                typed_parts = [f"{pname}: {ptype}" for pname, ptype in effective_params]
                typed_sig = f"function({', '.join(typed_parts)})"
                if ret_clean != 'void':
                    typed_sig += f" -> {ret_clean}"

                callbacks.append({
                    'func_name': func_name,
                    'ret_type': ret_type,
                    'ret_type_clean': ret_clean,
                    'params': params,
                    'parsed_params': effective_params,
                    'fired_by': fired_by,
                    'lua_event': lua_event,
                    'lua_sig': lua_sig,
                    'typed_sig': typed_sig,
                    'notes': " ".join(extra_notes).strip()
                })
        i += 1

    return callbacks

def generate_markdown(callbacks, registry_map):
    output = []
    output.append("# Kenshi LuaJIT Callbacks Reference")
    output.append("")
    output.append("This document is automatically generated by `tools/generate_callbacks_reference.py` based on `src/Callbacks.h` and `src/Hooks.cpp`.")
    output.append("")
    output.append("## Overview")
    output.append("")
    output.append("KenshiLuaJIT provides an event-driven callback system allowing Lua scripts to subscribe to in-game events using `registerHandler` and `unregisterHandler` globals.")
    output.append("")
    output.append("```lua")
    output.append("-- Registering an event handler")
    output.append("local handlerId = registerHandler(\"onCharacterDeath\", function(character)")
    output.append("    print(\"Character died: \", character)")
    output.append("end)")
    output.append("")
    output.append("-- Unregistering when done")
    output.append("unregisterHandler(handlerId)")
    output.append("```")
    output.append("")
    output.append("### Two Types of Callbacks")
    output.append("")
    output.append("1. **Notification Callbacks (Observer Pattern)**: Fired when an event occurs in the game. Handlers observe the event with typed arguments. Returning `false` from a handler suppresses execution of subsequent Lua handlers for that event, but does not interrupt C++ engine logic.")
    output.append("2. **Override Callbacks (Interceptor Pattern)**: Fired when the engine queries a value or object pointer (e.g. food selection, stat calculation, building availability). Handlers receive arguments (and default values). If a handler returns a non-nil value matching the expected return type, the C++ hook uses the returned value to override the engine's original calculation.")
    output.append("")

    # Split into Notifications and Overrides
    notifications = []
    overrides = []

    for cb in callbacks:
        is_override = cb['ret_type'] != 'void'
        if is_override:
            overrides.append(cb)
        else:
            notifications.append(cb)

    output.append(f"## 1. Notification Callbacks ({len(notifications)})")
    output.append("")
    output.append("| Event Name | Source Engine Hook | Lua Signature |")
    output.append("| :--- | :--- | :--- |")
    for cb in notifications:
        ev_name = f"`{cb['lua_event']}`" if cb['lua_event'] else "*(Unmapped)*"
        fired = f"`{cb['fired_by']}`" if cb['fired_by'] else "*(Engine Hook)*"
        sig = f"`{cb['typed_sig']}`"
        output.append(f"| {ev_name} | {fired} | {sig} |")
    output.append("")

    output.append(f"## 2. Override Callbacks ({len(overrides)})")
    output.append("")
    output.append("| Event Name | Source Engine Hook | Lua Signature & Expected Return |")
    output.append("| :--- | :--- | :--- |")
    for cb in overrides:
        ev_name = f"`{cb['lua_event']}`" if cb['lua_event'] else "*(Unmapped)*"
        fired = f"`{cb['fired_by']}`" if cb['fired_by'] else "*(Engine Hook)*"
        sig = f"`{cb['typed_sig']}`"
        output.append(f"| {ev_name} | {fired} | {sig} |")
    output.append("")

    output.append("## Detailed Callback Documentation")
    output.append("")

    all_cbs = notifications + overrides
    all_cbs.sort(key=lambda x: x['lua_event'] or x['func_name'])

    for cb in all_cbs:
        ev_title = cb['lua_event'] if cb['lua_event'] else cb['func_name']
        plain_sig = f"function({', '.join([pname for pname, _ in cb['parsed_params']])})"
        output.append(f"### `{ev_title}`")
        output.append("")
        output.append(f"- **Category**: {'Override / Interceptor' if cb['ret_type'] != 'void' else 'Notification / Observer'}")
        if cb['fired_by']:
            output.append(f"- **Engine Hook**: `{cb['fired_by']}`")
        output.append(f"- **Lua Signature**: `{plain_sig}`")
        
        if cb['parsed_params']:
            output.append("- **Parameters**:")
            for pname, ptype in cb['parsed_params']:
                output.append(f"  - `{pname}`: `{ptype}`")
        else:
            output.append("- **Parameters**: None")
            
        if cb['ret_type_clean'] != 'void':
            output.append(f"- **Returns**: `{cb['ret_type_clean']}`")
            
        if cb['notes']:
            output.append(f"- **Notes**: {cb['notes']}")
        output.append("")

    OUTPUT_MD.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT_MD.write_text("\n".join(output), encoding="utf-8")
    print(f"Successfully generated {OUTPUT_MD} with {len(callbacks)} callbacks.")

def main():
    registry_map = parse_hooks_registry()
    callbacks = parse_callbacks_header()
    generate_markdown(callbacks, registry_map)

if __name__ == "__main__":
    main()
