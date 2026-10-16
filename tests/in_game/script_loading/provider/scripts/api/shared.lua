local helper = require("api.internal.helper")
local theme = require("mygui.theme")

providerRequireCount = (providerRequireCount or 0) + 1

return {
    origin = "provider",
    helper = helper.marker,
    libraryFallback = theme.Windows.Default,
    loadCount = providerRequireCount,
}
