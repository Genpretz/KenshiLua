# Animal_Husbandry-Lua GUI

`layout/AH_HusbandryWindow.layout` is the Husbandry window loaded by `scripts/ah/harvest.lua`.

The layout must provide these widgets:

| Widget | Type | Purpose |
|---|---|---|
| `AH_HusbandryWindow` | `Window` | Root window |
| `AH_Portrait` | `ImageBox` | Animal portrait |
| `AH_Name` | `TextBox` | Animal name |
| `AH_GeneralInfoArea` | `Widget` | Race, sex, age, and value panel host |
| `AH_BreedingInfoArea` | `Widget` | Group, breeding state, and harvester panel host |
| `AH_ProductsScrollView` | `ScrollView` | Dynamic product rows |

The script creates the product labels and Harvest buttons at runtime. Keep these widget names and types when replacing the layout.

The 465 by 507 pixel layout places the portrait and animal profile above separate husbandry and products boxes. The products viewport fits two rows; longer lists use a vertical scrollbar, with 20 pixels reserved for it by the script.

Child coordinates are relative to the window's client area. The standard `Kenshi_WindowCX` template places that area at `(3, 41)` and makes it 6 pixels narrower and 45 pixels shorter than the window.
