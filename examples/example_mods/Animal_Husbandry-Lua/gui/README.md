# Animal_Husbandry-Lua GUI

`layout/AH_HusbandryWindow.layout` is the Husbandry window loaded by `scripts/ah/harvest.lua`. The other layout files are optional design references and are not loaded by the mod.

The active layout must provide these widgets:

| Widget | Type | Purpose |
|---|---|---|
| `AH_HusbandryWindow` | `Window` | Root window |
| `AH_Portrait` | `ImageBox` | Animal portrait |
| `AH_Name` | `TextBox` | Animal name |
| `AH_GeneralInfoArea` | `Widget` | Race, sex, age, and value panel host |
| `AH_BreedingInfoArea` | `Widget` | Group, breeding state, and harvester panel host |
| `AH_ProductsScrollView` | `ScrollView` | Dynamic product rows |

The script creates the product labels and Harvest buttons at runtime. Keep these widget names and types when replacing the active layout.

The 465 by 507 pixel layout places the portrait and animal profile above separate husbandry and products boxes. Both lower content areas span their boxes with an 8-pixel inset on either side. The products viewport fits two rows; longer lists use a vertical scrollbar, with 20 pixels reserved for it by the script. Horizontal scrolling is disabled.

Child coordinates are relative to the window's client area. The standard `Kenshi_WindowCX` template places that area at `(3, 41)` and makes it 6 pixels narrower and 45 pixels shorter than the window. The products box ends at client y=442, leaving 20 pixels below it.
