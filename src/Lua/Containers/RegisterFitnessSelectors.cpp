#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/Dialogue.h"
#include "Bindings/Kenshi/CampaignTriggerDataBinding.h"
#include "Bindings/Kenshi/Combat/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/FitnessSelectorBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Lua/LuaBindings.h"

#include "Lua/ContainerBinding.h"
#include "Lua/Containers/FitnessSelectorsTypes.h"

namespace KenshiLua
{

KENSHILUA_DEFINE_CONTAINER(Containers::FitnessSelector_CampaignTriggerDataPtrBinding, "FitnessSelector<CampaignTriggerData*>",
    CampaignTriggerDataBinding::getMetatableName(), nullptr, nullptr,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::FitnessSelector_CombatTechniqueDataPtrBinding, "FitnessSelector<CombatTechniqueData*>",
    CombatTechniqueDataBinding::getMetatableName(), "std::map<float, CombatTechniqueData*>", "std::map<CombatTechniqueData*, float>",
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::FitnessSelector_GameDataPtrBinding, "FitnessSelector<GameData*>",
    GameDataBinding::getMetatableName(), "std::map<float, GameData*>", "std::map<GameData*, float>",
    ContainerFactoryDefinition())

void LuaBindings::collectFitnessSelectors(ContainerBindingList& definitions)
{
    definitions.push_back(&containerBindingDefinition<Containers::FitnessSelector_CampaignTriggerDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::FitnessSelector_CombatTechniqueDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::FitnessSelector_GameDataPtrBinding::MetadataType>());
}

} // namespace KenshiLua
