local ok_cfg, config = pcall(require, "kltest.run_config")
if not ok_cfg or type(config) ~= "table" then
    KenshiLua.logWarn("[KLTest] kltest.run_config not found or invalid; skipping automated test bootstrap")
    return
end

local runner = require("kltest.runner")
_G.KLTestRunner = runner
runner.bootstrap(config)

require("kltest.suites.harness_self_test")
require("kltest.suites.world_smoke")
require("kltest.suites.binding_smoke")
