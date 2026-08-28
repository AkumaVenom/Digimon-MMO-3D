#include "Utility/DMFDigimonPresentationLibrary.h"

FText UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(const EDMFDigimonStage Stage)
{
    switch (Stage)
    {
    case EDMFDigimonStage::BabyI:
        return NSLOCTEXT("DMF", "DigimonStageFresh", "Fresh");
    case EDMFDigimonStage::BabyII:
        return NSLOCTEXT("DMF", "DigimonStageInTraining", "In-Training");
    case EDMFDigimonStage::Rookie:
        return NSLOCTEXT("DMF", "DigimonStageRookie", "Rookie");
    case EDMFDigimonStage::Champion:
        return NSLOCTEXT("DMF", "DigimonStageChampion", "Champion");
    case EDMFDigimonStage::Ultimate:
        return NSLOCTEXT("DMF", "DigimonStageUltimate", "Ultimate");
    case EDMFDigimonStage::Mega:
        return NSLOCTEXT("DMF", "DigimonStageMega", "Mega");
    case EDMFDigimonStage::Ultra:
        return NSLOCTEXT("DMF", "DigimonStageUltra", "Ultra");
    case EDMFDigimonStage::Armor:
        return NSLOCTEXT("DMF", "DigimonStageArmor", "Armor");
    case EDMFDigimonStage::Hybrid:
        return NSLOCTEXT("DMF", "DigimonStageHybrid", "Hybrid");
    case EDMFDigimonStage::Unknown:
    default:
        return NSLOCTEXT("DMF", "DigimonStageUnknown", "Unknown");
    }
}
