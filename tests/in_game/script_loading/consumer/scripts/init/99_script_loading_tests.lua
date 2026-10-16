local PREFIX = "[KLScriptLoadingTest] "
local PROVIDER = "KenshiLua.mod"

local function describe(value)
    if type(value) == "string" then return string.format("%q", value) end
    return tostring(value)
end

local function eq(actual, expected, label)
    if actual ~= expected then
        error(string.format("%s: expected %s, got %s", label, describe(expected), describe(actual)), 2)
    end
end

local function check(condition, message)
    if not condition then error(message or "check failed", 2) end
end

local function run_script_loading_suite(ctx)
    local passed = 0
    local failed = 0
    local failures = {}

    local function test(name, fn)
        local ok, err
        if ctx and ctx.test then
            ok, err = ctx.test(name, fn)
        else
            ok, err = xpcall(fn, function(value)
                return debug and debug.traceback and debug.traceback(tostring(value), 2) or tostring(value)
            end)
        end
        if ok then
            passed = passed + 1
            KenshiLua.log(PREFIX .. "PASS " .. name)
        else
            failed = failed + 1
            failures[#failures + 1] = name
            KenshiLua.logError(PREFIX .. "FAIL " .. name .. "\n    " .. tostring(err))
        end
    end

    test("local require resolves module.lua and passes module name", function()
        local settings = require("_kltests.settings")
        eq(settings.moduleName, "_kltests.settings", "module name")
        eq(settings.loadCount, 1, "first load count")
    end)

    test("local require resolves package/init.lua", function()
        local packageModule = require("_kltests.package")
        eq(packageModule.moduleName, "_kltests.package", "module name")
        eq(packageModule.loadedFrom, "init.lua", "loaded file")
    end)

    test("local require caches by sandbox and module name", function()
        local first = require("_kltests.settings")
        local second = require("_kltests.settings")
        check(first == second, "require returned different tables")
        eq(second.loadCount, 1, "cached load count")
    end)

    test("local dofile uses an exact scripts-relative path", function()
        local label1, count1 = dofile("_kltests/values.lua")
        local label2, count2 = dofile("_kltests/values.lua")
        eq(label1, "local-dofile", "first label")
        eq(label2, "local-dofile", "second label")
        eq(count1, 1, "first execution")
        eq(count2, 2, "second execution")
    end)

    test("local loadfile returns a reusable chunk in the caller sandbox", function()
        local chunk, err = loadfile("_kltests/task.lua")
        check(type(chunk) == "function", err)
        local label1, count1 = chunk()
        local label2, count2 = chunk()
        eq(label1, "local-loadfile", "first label")
        eq(label2, "local-loadfile", "second label")
        eq(count1, 1, "first execution")
        eq(count2, 2, "second execution")
    end)

    test("require does not recursively scan for a basename", function()
        local ok = pcall(require, "_kltests.deep_only")
        check(not ok, "require unexpectedly found nested/deep_only.lua")
    end)

    test("ordinary require falls back to KenshiLua lib", function()
        local theme = require("mygui.theme")
        eq(theme.Windows.Default, "Kenshi_WindowCX", "theme value")
    end)

    test("cross-mod require resolves provider and nested modules", function()
        local shared = KenshiLua.requireFromMod(PROVIDER, "api.shared")
        eq(shared.origin, "provider", "origin")
        eq(shared.helper, "provider-helper", "nested require")
        eq(shared.libraryFallback, "Kenshi_WindowCX", "provider lib fallback")
        eq(shared.loadCount, 1, "provider load count")
    end)

    test("cross-mod require has a provider-scoped cache", function()
        local first = KenshiLua.requireFromMod(PROVIDER, "api.shared")
        local second = KenshiLua.requireFromMod(PROVIDER, "api.shared")
        check(first == second, "requireFromMod returned different tables")
        eq(second.loadCount, 1, "cached provider load count")
    end)

    test("same module basename remains isolated between mods", function()
        local localModule = require("_kltests.collision")
        local providerModule = KenshiLua.requireFromMod(PROVIDER, "api.collision")
        eq(localModule.origin, "consumer", "local origin")
        eq(providerModule.origin, "provider", "provider origin")
    end)

    test("cross-mod dofile preserves multiple results and shared environment", function()
        local label1, count1 = KenshiLua.dofileFromMod(PROVIDER, "api/values.lua")
        local label2, count2 = KenshiLua.dofileFromMod(PROVIDER, "api/values.lua")
        eq(label1, "provider-dofile", "first label")
        eq(label2, "provider-dofile", "second label")
        eq(count1, 1, "first execution")
        eq(count2, 2, "second execution")
    end)

    test("cross-mod loadfile returns a chunk in the provider environment", function()
        local chunk, err = KenshiLua.loadfileFromMod(PROVIDER, "api/task.lua")
        check(type(chunk) == "function", err)
        local label1, count1 = chunk()
        local label2, count2 = chunk()
        eq(label1, "provider-loadfile", "first label")
        eq(label2, "provider-loadfile", "second label")
        eq(count1, 1, "first execution")
        eq(count2, 2, "second execution")
    end)

    test("missing provider raises an explicit error", function()
        local ok, err = pcall(KenshiLua.requireFromMod, "Missing Provider.mod", "api.shared")
        check(not ok, "missing provider unexpectedly succeeded")
        check(tostring(err):find("is not active", 1, true) ~= nil, "unexpected error: " .. tostring(err))
    end)

    test("cross-mod dofile rejects traversal outside scripts", function()
        local ok, err = pcall(KenshiLua.dofileFromMod, PROVIDER, "../KenshiLua.mod")
        check(not ok, "path traversal unexpectedly succeeded")
        check(tostring(err):find("was not found", 1, true) ~= nil, "unexpected error: " .. tostring(err))
    end)

    test("cross-mod loadfile rejects absolute paths with loadfile semantics", function()
        local chunk, err = KenshiLua.loadfileFromMod(PROVIDER, "C:/not-allowed.lua")
        eq(chunk, nil, "chunk")
        check(type(err) == "string" and err:find("must be relative", 1, true) ~= nil,
            "unexpected error: " .. tostring(err))
    end)

    _G.KLScriptLoadingTest = {
        passed = passed,
        failed = failed,
        failures = failures,
    }

    KenshiLua.log(string.format(PREFIX .. "RESULT %d passed, %d failed", passed, failed))
end

if _G.KLTestRunner and type(_G.KLTestRunner.register_menu_suite) == "function" then
    _G.KLTestRunner.register_menu_suite("script-loading", run_script_loading_suite)
else
    run_script_loading_suite(nil)
end
