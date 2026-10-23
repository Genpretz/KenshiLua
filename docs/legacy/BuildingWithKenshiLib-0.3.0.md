# Building KenshiLua with KenshiLib 0.3.0

KenshiLua releases `v0.2.0-alpha` through `v0.3.9-alpha`, and `main` up to commit `15129e7`, pin the `extern/KenshiLib` submodule at `30e582b`, which reports itself as KenshiLib 0.3.0. Those headers do not compile with KenshiLua unchanged. This page lists the changes needed to build those versions.

Later KenshiLua versions use KenshiLib 0.5.0, the version RE_Kenshi ships. Follow the [README](../../README.md#building-kenshilua) and the [development guide](../in_progress/Development.md) for those versions.

## Verification status

The changes below come from the local setup that last built KenshiLua from `main` at `15129e7`, with binding work that was then still uncommitted. That build ran in Kenshi 1.0.65 GOG on 2026-10-22. Each required change is backed by one of these:

- KenshiLib later made the same fix upstream (commit noted).
- The unchanged header causes a link or load failure (reason noted).
- KenshiLua's code at `15129e7` depends on it.

The required set has not been rebuilt on its own from a clean checkout. Older tags may need only a subset. For example, `kenshi/ParticlePool.h` is only needed once KenshiLua has a `ParticlePool` binding.

## 1. Check out the version

Use the same toolchain as current KenshiLua, the Release x64 configuration with the `Windows7.1SDK` (MSVC2010) toolset.

```powershell
git clone --recursive https://github.com/Genpretz/KenshiLua.git
cd KenshiLua
git checkout v0.3.9-alpha
git submodule update --init
git -C extern/KenshiLib rev-parse --short HEAD   # expect 30e582b
```

## 2. Change the KenshiLib headers

All paths are relative to `extern/KenshiLib/Include/`.

### Fixed upstream after 0.3.0

| File | Change | Upstream fix |
| --- | --- | --- |
| `kenshi/Building/FarmBuilding.h` | Add `#pragma once` as the first line. | `b0d7665` |
| `kenshi/CharMovement.h` | Add `#pragma once` as the first line. | `50c4394` |
| `kenshi/gui/DataPanelLine.h` | Add `#pragma once` as the first line. | `50c4394` |
| `kenshi/gui/MainBarGUI.h` | Add `class MainBarGUI;` before `class MainTabPortraitPlatoon`. | `59adcea` |
| `kenshi/gui/OrdersPanel.h` | Add `class OrderData;` before `class OrderCellView`. | `7c8bbfa` |
| `kenshi/gui/ManagementScreen.h` | Add `#include <mygui/common/itembox/BaseItemBox.h>` before the `BaseLayout.h` include. Add `template<typename T> class ReorderableListItem;` before `template<typename T1, typename T2> class ReorderableList`. Change `virtual ~ReorderableList() override;` to `virtual ~ReorderableList();`. | `01b61a2` |
| `kenshi/NavMesh.h` | In `class MessageQueue`, replace `MessageQueue<T>::Node*` with `Node*` for the `next`, `root`, `split`, and `back` members. | `6f9168d` |
| `kenshi/Platoon.h` | Delete the `enum BuildingDesignation { ... };` definition, which `Building/Building.h` also defines. Add `#include "Building/Building.h"` to the includes and `enum BuildingDesignation;` where the definition was. | `0e0ded7` (moved the enum to `Enums.h`) |

### Duplicate definitions, still present in 0.5.0

Each duplicate below is identical to the copy it conflicts with, so keep one and include it.

| File | Change |
| --- | --- |
| `kenshi/Globals.h` | Delete the `// TODO` comment and the `namespace FoliageSystem { class EntData; }` block, which conflicts with `class FoliageSystem`. Add `#include <kenshi/FoliageSystem.h>` to the includes. |
| `kenshi/SaveInfo.h` | Delete `class GameplayOptions { ... };`, which duplicates `GameplayOptions.h`. Add `#include "GameplayOptions.h"`. |
| `kenshi/PlayerInterface.h` | Delete `class ContextMenu { ... };`, which duplicates `gui/ContextMenu.h`. Add `#include "kenshi/gui/ContextMenu.h"`. |
| `kenshi/ZoneManager.h` | Delete `class ParticlePool { ... };`. Add `#include <kenshi/ParticlePool.h>`. |
| `kenshi/CombatClass.h` | Delete the `// TODO move?` comment and `class ParticlePool { ... };`. Add `#include "kenshi/ParticlePool.h"`. |

`ParticlePool` is defined in both `ZoneManager.h` and `CombatClass.h`, and KenshiLua's `ParticlePoolBinding.h` includes `kenshi/ParticlePool.h`. Create `kenshi/ParticlePool.h` with the class from either header:

```cpp
#pragma once

#include <OgreVector3.h>
#include <OgreQuaternion.h>
#include <OgreSceneNode.h>
#include <OgreMemoryAllocatedObject.h>

class GameData;
class ParticleSystemHandler;

class ParticlePool : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    struct ParticleData
    {
        ParticleData();// public RVA = 0x409300
        ParticleData* _CONSTRUCTOR();// public RVA = 0x409300
        ParticleSystemHandler* particle; // 0x0 Member
        GameData* effectData; // 0x8 Member
        Ogre::SceneNode* node; // 0x10 Member
    };
    ParticlePool(int limit, float ttl);// public RVA = 0x409650
    ParticlePool* _CONSTRUCTOR(int limit, float ttl);// public RVA = 0x409650
    ~ParticlePool();// public RVA = 0x40B810
    void _DESTRUCTOR();// public RVA = 0x40B810
    void init();// public RVA = 0x409320
    void destroy();// public RVA = 0x40B460
    int getSize() const;// public RVA = 0x4093A0
    bool addParticle(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, Ogre::SceneNode* parentNode);// public RVA = 0x40B540
    void update();// public RVA = 0x40B680
    void shiftParticles(const Ogre::Vector3& shift);// public RVA = 0x4093B0
    unsigned int limit; // 0x0 Member
    unsigned int lastIndex; // 0x4 Member
    ParticlePool::ParticleData* particles; // 0x8 Member
    float maxTTL; // 0x10 Member
};
```

### Signatures that disagree with the exported symbols

`kenshi/Havok.h` declares `enum Mask` inside `hkVector4fComparison`. KenshiLib exports that class's methods with `enum hkVector4ComparisonMask::Mask` instead (`W4Mask@hkVector4ComparisonMask@@` in `Source/kenshi/functions/hkVector4fComparison.inc`), so calls fail to link. KenshiLua at `15129e7` also uses both `hkVector4ComparisonMask::Mask` and `hkVector4fComparison::MASK_NONE`.

Move the enum into `struct hkVector4ComparisonMask` and give `hkVector4fComparison` an alias for it:

1. Change `class hkVector4fComparison` (the class holding `enum Mask`) to `struct hkVector4ComparisonMask`.
2. Close it with `};` right after the `enum Mask { ... };` block.
3. Reopen the class below it, keeping the `operator new` and `operator delete` comments and `MustEndWithSemiColon` from the original class, and add the alias and constants:

```cpp
class hkVector4fComparison
{
public:
    class MustEndWithSemiColon
    {
    public:
    };
    typedef hkVector4ComparisonMask::Mask Mask;
    static const Mask INDEX_W = hkVector4ComparisonMask::INDEX_W;
    static const Mask INDEX_Z = hkVector4ComparisonMask::INDEX_Z;
    static const Mask INDEX_Y = hkVector4ComparisonMask::INDEX_Y;
    static const Mask INDEX_X = hkVector4ComparisonMask::INDEX_X;
    static const Mask MASK_NONE = hkVector4ComparisonMask::MASK_NONE;
    static const Mask MASK_W = hkVector4ComparisonMask::MASK_W;
    static const Mask MASK_Z = hkVector4ComparisonMask::MASK_Z;
    static const Mask MASK_ZW = hkVector4ComparisonMask::MASK_ZW;
    static const Mask MASK_Y = hkVector4ComparisonMask::MASK_Y;
    static const Mask MASK_YW = hkVector4ComparisonMask::MASK_YW;
    static const Mask MASK_YZ = hkVector4ComparisonMask::MASK_YZ;
    static const Mask MASK_YZW = hkVector4ComparisonMask::MASK_YZW;
    static const Mask MASK_X = hkVector4ComparisonMask::MASK_X;
    static const Mask MASK_XW = hkVector4ComparisonMask::MASK_XW;
    static const Mask MASK_XZ = hkVector4ComparisonMask::MASK_XZ;
    static const Mask MASK_XZW = hkVector4ComparisonMask::MASK_XZW;
    static const Mask MASK_XY = hkVector4ComparisonMask::MASK_XY;
    static const Mask MASK_XYW = hkVector4ComparisonMask::MASK_XYW;
    static const Mask MASK_XYZ = hkVector4ComparisonMask::MASK_XYZ;
    static const Mask MASK_XYZW = hkVector4ComparisonMask::MASK_XYZW;

    // the rest of the original class body, starting with convert()
};
```

`mygui/MyGUI_ItemBox.h` declares three methods without the trailing `bool` parameter that Kenshi's `MyGUIEngine_x64.dll` exports (`?addItem@ItemBox@MyGUI@@QEAAXVAny@2@_N@Z` and similar). Without it, KenshiLua imports symbols the game's DLL does not have and fails to load. Add the parameter:

```cpp
void insertItemAt(size_t _index, Any _data = Any::Null, bool update = true);
void addItem(Any _data = Any::Null, bool update = true);
void removeItemAt(size_t _index, bool update = true);
```

## 3. Regenerate the MyGUI import library

Kenshi uses a customized MyGUI build. The `Libraries/mygui/MyGUIEngine_x64.lib` in the KenshiLib repository does not match it: it lists 220 symbols the game's DLL does not export and lacks 214 that it does, including the three `ItemBox` methods above. Generate the import library from the game's own `MyGUIEngine_x64.dll` instead. KenshiLib 0.5.0 needs the same library.

1. Open a Visual Studio 2010 x64 command prompt, where `dumpbin` and `lib` are on the path, and dump the DLL's section headers and exports. Use `cmd` rather than PowerShell, whose redirection writes UTF-16.

   ```bat
   dumpbin /headers "<Kenshi>\MyGUIEngine_x64.dll" > headers.txt
   dumpbin /exports "<Kenshi>\MyGUIEngine_x64.dll" > exports.txt
   ```

2. Write `MyGUIEngine_x64.def`, listing every export and marking those in non-executable sections, such as vtables and static data, as `DATA`:

   ```python
   import re

   sections, current = [], None
   for line in open("headers.txt", errors="ignore"):
       if line.startswith("SECTION HEADER #"):
           current = {"va": 0, "size": 0, "exec": False}
           sections.append(current)
       elif current is not None:
           m = re.match(r"^\s+([0-9A-F]+) virtual (size|address)", line)
           if m:
               current["size" if m.group(2) == "size" else "va"] = int(m.group(1), 16)
           elif re.match(r"^\s+Execute", line):
               current["exec"] = True

   def is_data(rva):
       return any(s["va"] <= rva < s["va"] + s["size"] and not s["exec"] for s in sections)

   with open("MyGUIEngine_x64.def", "w") as out:
       out.write("LIBRARY MyGUIEngine_x64.dll\nEXPORTS\n")
       for line in open("exports.txt", errors="ignore"):
           m = re.match(r"^\s+\d+\s+[0-9A-F]+\s+([0-9A-F]{8})\s+(\S+)", line)
           if m:
               rva = int(m.group(1), 16)
               out.write("    %s%s\n" % (m.group(2), " DATA" if is_data(rva) else ""))
   ```

3. Build the import library and replace the repository copy:

   ```bat
   lib /def:MyGUIEngine_x64.def /machine:x64 /out:MyGUIEngine_x64.lib
   copy /Y MyGUIEngine_x64.lib extern\KenshiLib\Libraries\mygui\MyGUIEngine_x64.lib
   ```

For the Kenshi 1.0.65 `MyGUIEngine_x64.dll` (SHA-256 `fea6f1f9...`, unchanged from a clean install), this produces 3598 exports, 496 marked `DATA`. The resulting library's symbols match the DLL's exports exactly.

## 4. Build

1. Build `extern/KenshiLib/KenshiLib.vcxproj` (Release x64). KenshiLua's Release configuration links the resulting `extern/KenshiLib/x64/Release/KenshiLib.lib`.
2. Build `KenshiLua.vcxproj` (Release x64). Debug builds do not work with the release game or KenshiLib.

At runtime, KenshiLua loads its KenshiLib functions from the `KenshiLib.dll` that RE_Kenshi installs in the game folder, not the one you built. The build loads only if that DLL exports every symbol KenshiLua imports. Compare `dumpbin /imports` of `KenshiLua.dll` with `dumpbin /exports` of the game's `KenshiLib.dll` to check. On 2026-10-22, the build described above loaded with the `KenshiLib.dll` installed at the time, which reported KenshiLib 0.5.1.

## Changes that are not needed

The last local setup also contained these changes. They are not part of the required set:

- **Removing `__declspec(dllimport)` from `mygui/common/baselayout/BaseLayout.h`:** at 0.3.0 the specifier sits before `class`, where MSVC ignores it with warning C4091. KenshiLib 0.5.0 moves it to where it takes effect, and there it must be removed.
- **Switching forward declarations between `struct` and `class`:** in `kenshi/NavMesh.h` (`EdgePathNode`, `EdgeCache`, `NavInstance`) and `kenshi/util/UtilityT.h` (`NxShape`, `NxMat33`, `NxBox`), the mismatch only produces warning C4099.
- **A post-build copy step in `KenshiLib.vcxproj`:** it copies outputs into `Libraries/` for convenience.
- **Other `Include/mygui/` header edits:** these were copied from a newer MyGUI release. Kenshi's MyGUI is customized, and apart from the three `ItemBox` signatures above, none of them were checked against the game's DLL. Do not apply them.
