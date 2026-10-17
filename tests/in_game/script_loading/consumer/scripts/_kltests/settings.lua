local moduleName = ...
LocalSettingsLoadCount = (LocalSettingsLoadCount or 0) + 1
return {
    moduleName = moduleName,
    loadCount = LocalSettingsLoadCount,
}
