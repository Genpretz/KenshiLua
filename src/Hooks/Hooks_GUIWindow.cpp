#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/GUIWindow.h>

// ---------------------------------------------------------------------------
// Hooks for GUIWindow.h
//
// Non-virtual members and the _NV_ bodies of virtual members. Events fire after
// the original call unless noted; getters pass the original result as
// defaultVal and accept an override from Lua.
//
// Not hooked:
//   GUIWindow::_CONSTRUCTOR()
//     abstract base-class constructor; the derived object is not constructed yet when it returns
//   GUIWindow::_DESTRUCTOR()
//     abstract base-class destructor; the derived object is already destroyed when it runs
//   GUIWindow::_NV_clear()
//     RVA 0x402A20 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
// ---------------------------------------------------------------------------

static void (*GUIWindow_NV_setPositionReal_orig)(GUIWindow*, float, float) = NULL;
static void GUIWindow_NV_setPositionReal_hook(GUIWindow* thisptr, float x, float y)
{
    GUIWindow_NV_setPositionReal_orig(thisptr, x, y);
    CallGUIWindowSetPositionRealCallbacks(thisptr, x, y);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_setPositionReal,
    "GUIWindow::_NV_setPositionReal",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_setPositionReal),
    GUIWindow_NV_setPositionReal_hook, GUIWindow_NV_setPositionReal_orig)

static void (*GUIWindow_NV_setPosition_orig)(GUIWindow*, int, int) = NULL;
static void GUIWindow_NV_setPosition_hook(GUIWindow* thisptr, int x, int y)
{
    GUIWindow_NV_setPosition_orig(thisptr, x, y);
    CallGUIWindowSetPositionCallbacks(thisptr, x, y);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_setPosition,
    "GUIWindow::_NV_setPosition",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_setPosition),
    GUIWindow_NV_setPosition_hook, GUIWindow_NV_setPosition_orig)

static int (*GUIWindow_NV_getWidth_orig)(const GUIWindow*) = NULL;
static int GUIWindow_NV_getWidth_hook(const GUIWindow* thisptr)
{
    int res = GUIWindow_NV_getWidth_orig(thisptr);
    return CallGUIWindowGetWidthCallbacks(const_cast<GUIWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_getWidth,
    "GUIWindow::_NV_getWidth",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_getWidth),
    GUIWindow_NV_getWidth_hook, GUIWindow_NV_getWidth_orig)

static int (*GUIWindow_NV_getHeight_orig)(const GUIWindow*) = NULL;
static int GUIWindow_NV_getHeight_hook(const GUIWindow* thisptr)
{
    int res = GUIWindow_NV_getHeight_orig(thisptr);
    return CallGUIWindowGetHeightCallbacks(const_cast<GUIWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_getHeight,
    "GUIWindow::_NV_getHeight",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_getHeight),
    GUIWindow_NV_getHeight_hook, GUIWindow_NV_getHeight_orig)

static float (*GUIWindow_NV_getWidthReal_orig)(const GUIWindow*) = NULL;
static float GUIWindow_NV_getWidthReal_hook(const GUIWindow* thisptr)
{
    float res = GUIWindow_NV_getWidthReal_orig(thisptr);
    return CallGUIWindowGetWidthRealCallbacks(const_cast<GUIWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_getWidthReal,
    "GUIWindow::_NV_getWidthReal",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_getWidthReal),
    GUIWindow_NV_getWidthReal_hook, GUIWindow_NV_getWidthReal_orig)

static float (*GUIWindow_NV_getHeightReal_orig)(const GUIWindow*) = NULL;
static float GUIWindow_NV_getHeightReal_hook(const GUIWindow* thisptr)
{
    float res = GUIWindow_NV_getHeightReal_orig(thisptr);
    return CallGUIWindowGetHeightRealCallbacks(const_cast<GUIWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_getHeightReal,
    "GUIWindow::_NV_getHeightReal",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_getHeightReal),
    GUIWindow_NV_getHeightReal_hook, GUIWindow_NV_getHeightReal_orig)

static bool (*GUIWindow_NV_isVisible_orig)(const GUIWindow*) = NULL;
static bool GUIWindow_NV_isVisible_hook(const GUIWindow* thisptr)
{
    bool res = GUIWindow_NV_isVisible_orig(thisptr);
    return CallGUIWindowIsVisibleCallbacks(const_cast<GUIWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_isVisible,
    "GUIWindow::_NV_isVisible",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_isVisible),
    GUIWindow_NV_isVisible_hook, GUIWindow_NV_isVisible_orig)

static void (*GUIWindow_NV_update_orig)(GUIWindow*) = NULL;
static void GUIWindow_NV_update_hook(GUIWindow* thisptr)
{
    GUIWindow_NV_update_orig(thisptr);
    CallGUIWindowUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_update,
    "GUIWindow::_NV_update",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_update),
    GUIWindow_NV_update_hook, GUIWindow_NV_update_orig)

static void (*GUIWindow_NV_autoChangeSelectedObject_orig)(GUIWindow*, const hand&) = NULL;
static void GUIWindow_NV_autoChangeSelectedObject_hook(GUIWindow* thisptr, const hand& obj)
{
    GUIWindow_NV_autoChangeSelectedObject_orig(thisptr, obj);
    CallGUIWindowAutoChangeSelectedObjectCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_autoChangeSelectedObject,
    "GUIWindow::_NV_autoChangeSelectedObject",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_autoChangeSelectedObject),
    GUIWindow_NV_autoChangeSelectedObject_hook, GUIWindow_NV_autoChangeSelectedObject_orig)

static MyGUI::Widget* (*GUIWindow_getWidget_orig)(GUIWindow*) = NULL;
static MyGUI::Widget* GUIWindow_getWidget_hook(GUIWindow* thisptr)
{
    MyGUI::Widget* res = GUIWindow_getWidget_orig(thisptr);
    CallGUIWindowGetWidgetCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_getWidget,
    "GUIWindow::getWidget",
    KenshiLib::GetRealAddress(&GUIWindow::getWidget),
    GUIWindow_getWidget_hook, GUIWindow_getWidget_orig)

static void (*GUIWindow_NV_resize_orig)(GUIWindow*, int, int) = NULL;
static void GUIWindow_NV_resize_hook(GUIWindow* thisptr, int w, int h)
{
    GUIWindow_NV_resize_orig(thisptr, w, h);
    CallGUIWindowResizeCallbacks(thisptr, w, h);
}
DEFINE_HOOK_INSTALLER(InstallHook_GUIWindow_NV_resize,
    "GUIWindow::_NV_resize",
    KenshiLib::GetRealAddress(&GUIWindow::_NV_resize),
    GUIWindow_NV_resize_hook, GUIWindow_NV_resize_orig)
