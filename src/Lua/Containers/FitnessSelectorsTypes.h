#pragma once
#include "kenshi/Tasker.h"
#include "kenshi/Dialogue.h"
#include "Bindings/Kenshi/FitnessSelectorBinding.h"

namespace KenshiLua
{
namespace Containers
{
typedef FitnessSelectorBinding<CampaignTriggerData*> FitnessSelector_CampaignTriggerDataPtrBinding;
typedef FitnessSelectorBinding<CombatTechniqueData*> FitnessSelector_CombatTechniqueDataPtrBinding;
typedef FitnessSelectorBinding<GameData*> FitnessSelector_GameDataPtrBinding;
}
} // namespace KenshiLua
