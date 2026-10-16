# Script loading integration test

This two-root fixture verifies local and cross-mod Lua loading inside Kenshi. It intentionally uses an existing active `KenshiLua.mod` as the provider so the same suite can exercise a local GOG installation and a Steam Workshop installation.

## Layout

- Copy `provider/scripts/` into the root of the active `KenshiLua.mod` installation.
- Copy `consumer/scripts/` into a different active local mod.
- Install the KenshiLua build under test and start Kenshi.

The consumer's `scripts/init/99_script_loading_tests.lua` runs automatically and writes one line per case plus this summary to `KenshiLua.log`:

```text
[KLScriptLoadingTest] RESULT 15 passed, 0 failed
```

The suite covers:

- `<module>.lua` and `<module>/init.lua` local resolution;
- per-sandbox local `require` caching;
- exact relative `dofile` and `loadfile` paths and multiple return values;
- rejection of recursive basename searches;
- fallback from mod-local `require` to KenshiLua's `lib/` directory;
- explicit provider lookup with `KenshiLua.requireFromMod`;
- provider-rooted nested `require` and shared provider state;
- isolation of equal module basenames in consumer and provider mods;
- cross-mod `dofile` and `loadfile` result/environment behavior;
- missing-provider, traversal, and absolute-path errors.

## Installation matrix used by the project

| Build | Provider | Consumer |
| --- | --- | --- |
| GOG | `Kenshi/mods/KenshiLua/` | any other active local mod |
| Steam | `steamapps/workshop/content/233860/<KenshiLua workshop id>/` | any active mod under `Kenshi/mods/` |

Using a Workshop provider and local consumer on Steam verifies that both mod roots participate in the same active-mod resolution pass. Restart Kenshi between runs so Lua caches and provider globals begin empty.
