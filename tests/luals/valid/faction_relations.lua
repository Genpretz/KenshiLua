-- LuaLS regression fixture: registered faction lookup and relation bindings.

local world = getGameWorld()
if world and world.factionMgr then
    local firstFaction = world.factionMgr:getFactionByName("Starving Bandits")
    local secondFaction = world.factionMgr:getFactionByName("Dust Bandits")
    if firstFaction and secondFaction and firstFaction.relations and secondFaction.relations then
        local relation = firstFaction.relations:getFactionRelation(secondFaction)
        secondFaction.relations:setRelation(firstFaction, relation)
        KenshiLua.logDebug(firstFaction:getName())
    end
end
