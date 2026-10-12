#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/SplashScreen.h>

// ---------------------------------------------------------------------------
// Hooks for SplashScreen.h
//
// All address-bearing non-virtual members. Events fire after the original call
// except for the destructor. Scalar getters supply the engine result as the Lua
// default and accept an override.
// ---------------------------------------------------------------------------

static SplashScreen* (*SplashScreen_CONSTRUCTOR_orig)(SplashScreen*) = NULL;
static SplashScreen* SplashScreen_CONSTRUCTOR_hook(SplashScreen* thisptr)
{
    SplashScreen* res = SplashScreen_CONSTRUCTOR_orig(thisptr);
    CallSplashScreenConstructedCallbacks(thisptr);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_CONSTRUCTOR,
    "SplashScreen::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&SplashScreen::_CONSTRUCTOR),
    SplashScreen_CONSTRUCTOR_hook, SplashScreen_CONSTRUCTOR_orig)

static void (*SplashScreen_DESTRUCTOR_orig)(SplashScreen*) = NULL;
static void SplashScreen_DESTRUCTOR_hook(SplashScreen* thisptr)
{
    CallSplashScreenDestructorCallbacks(thisptr);
    SplashScreen_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_DESTRUCTOR,
    "SplashScreen::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&SplashScreen::_DESTRUCTOR),
    SplashScreen_DESTRUCTOR_hook, SplashScreen_DESTRUCTOR_orig)

static void (*SplashScreen_update_orig)(SplashScreen*) = NULL;
static void SplashScreen_update_hook(SplashScreen* thisptr)
{
    SplashScreen_update_orig(thisptr);
    CallSplashScreenUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_update,
    "SplashScreen::update",
    KenshiLib::GetRealAddress(&SplashScreen::update),
    SplashScreen_update_hook, SplashScreen_update_orig)

static char (*SplashScreen_getState_orig)(const SplashScreen*) = NULL;
static char SplashScreen_getState_hook(const SplashScreen* thisptr)
{
    char res = SplashScreen_getState_orig(thisptr);
    return static_cast<char>(CallSplashScreenGetStateCallbacks(
        const_cast<SplashScreen*>(thisptr), static_cast<int>(res)));
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_getState,
    "SplashScreen::getState",
    KenshiLib::GetRealAddress(&SplashScreen::getState),
    SplashScreen_getState_hook, SplashScreen_getState_orig)

static bool (*SplashScreen_getEnded_orig)(const SplashScreen*) = NULL;
static bool SplashScreen_getEnded_hook(const SplashScreen* thisptr)
{
    bool res = SplashScreen_getEnded_orig(thisptr);
    return CallSplashScreenGetEndedCallbacks(const_cast<SplashScreen*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_getEnded,
    "SplashScreen::getEnded",
    KenshiLib::GetRealAddress(&SplashScreen::getEnded),
    SplashScreen_getEnded_hook, SplashScreen_getEnded_orig)

static void (*SplashScreen_skip_orig)(SplashScreen*) = NULL;
static void SplashScreen_skip_hook(SplashScreen* thisptr)
{
    SplashScreen_skip_orig(thisptr);
    CallSplashScreenSkipCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_skip,
    "SplashScreen::skip",
    KenshiLib::GetRealAddress(&SplashScreen::skip),
    SplashScreen_skip_hook, SplashScreen_skip_orig)

static void (*SplashScreen_addLogo_orig)(SplashScreen*, const std::string&, float) = NULL;
static void SplashScreen_addLogo_hook(SplashScreen* thisptr, const std::string& file, float scale)
{
    SplashScreen_addLogo_orig(thisptr, file, scale);
    CallSplashScreenAddLogoCallbacks(thisptr, file, scale);
}
DEFINE_HOOK_INSTALLER(InstallHook_SplashScreen_addLogo,
    "SplashScreen::addLogo",
    KenshiLib::GetRealAddress(&SplashScreen::addLogo),
    SplashScreen_addLogo_hook, SplashScreen_addLogo_orig)
