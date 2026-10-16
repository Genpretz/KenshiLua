local moduleName = ...
localSettingsLoadCount = (localSettingsLoadCount or 0) + 1
return {
    moduleName = moduleName,
    loadCount = localSettingsLoadCount,
}
