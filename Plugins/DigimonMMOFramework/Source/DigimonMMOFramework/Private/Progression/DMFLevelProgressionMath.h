#pragma once

#include "CoreMinimal.h"
#include "Data/DMFDigimonSpeciesData.h"

/** Internal deterministic progression math shared by authoritative mutation and owner-local UI presentation. */
namespace DMFLevelProgressionMath
{
    FORCEINLINE int64 GetExperienceRequiredForLevel(const UDMFDigimonSpeciesData& Species, const int32 CurrentLevel)
    {
        const int32 SafeLevel = FMath::Max(1, CurrentLevel);
        const double Base = static_cast<double>(FMath::Max<int64>(1, Species.BaseExperienceRequired));
        const double GrowthMultiplier = static_cast<double>(FMath::Clamp(Species.ExperienceGrowthMultiplierPerLevel, 1.0f, 10.0f));
        const double SafeMaximum = static_cast<double>(MAX_int64 / 4);
        double Requirement = FMath::Clamp(Base, 1.0, SafeMaximum);

        // Multiply one level step at a time so extreme designer values can never overflow before clamping.
        for (int32 LevelStep = 1; LevelStep < SafeLevel && Requirement < SafeMaximum; ++LevelStep)
        {
            Requirement = FMath::Min(Requirement * GrowthMultiplier, SafeMaximum);
        }

        return FMath::Max<int64>(1, static_cast<int64>(Requirement + 0.5));
    }
}
