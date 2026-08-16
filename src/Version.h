#pragma once

#define KENSHILUA_VERSION_MAJOR 0
#define KENSHILUA_VERSION_MINOR 2
#define KENSHILUA_VERSION_PATCH 8
#define KENSHILUA_VERSION_SUFFIX "" // e.g. "-alpha", "-beta", "-prerelease", or ""

#define KENSHILUA_STR_HELPER(x) #x
#define KENSHILUA_STR(x) KENSHILUA_STR_HELPER(x)

#define KENSHILUA_VERSION_STRING \
    KENSHILUA_STR(KENSHILUA_VERSION_MAJOR) "." \
    KENSHILUA_STR(KENSHILUA_VERSION_MINOR) "." \
    KENSHILUA_STR(KENSHILUA_VERSION_PATCH) \
    KENSHILUA_VERSION_SUFFIX

#define KENSHILUA_VERSION_NAME "KenshiLua"
#define KENSHILUA_VERSION_FULL KENSHILUA_VERSION_NAME " " KENSHILUA_VERSION_STRING

namespace KenshiLua
{
    namespace Version
    {
        static const int Major = KENSHILUA_VERSION_MAJOR;
        static const int Minor = KENSHILUA_VERSION_MINOR;
        static const int Patch = KENSHILUA_VERSION_PATCH;
        static const char* const Suffix = KENSHILUA_VERSION_SUFFIX;
        static const char* const String = KENSHILUA_VERSION_STRING;
        static const char* const Name = KENSHILUA_VERSION_NAME;
        static const char* const Full = KENSHILUA_VERSION_FULL;
    }
}
