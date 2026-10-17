local helper = require("api.internal.helper")
local theme = require("mygui.theme")

ProviderRequireCount = (ProviderRequireCount or 0) + 1

return {
    origin = "provider",
    helper = helper.marker,
    libraryFallback = theme.Windows.Default,
    loadCount = ProviderRequireCount,
}
