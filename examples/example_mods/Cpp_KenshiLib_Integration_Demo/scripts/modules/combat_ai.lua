-- combat_ai.lua
-- Private Lua module demonstrating native C++ module import (require) and character evaluation.

local native = require("CppDemoNative")

Events.on("CppDemo_OnCharacterSelected", function(character, bonus)
    print(string.format(
        "[CppDemo private module] evaluating %s with bonus %.1f",
        native.describeCharacter(character), bonus))
end)
