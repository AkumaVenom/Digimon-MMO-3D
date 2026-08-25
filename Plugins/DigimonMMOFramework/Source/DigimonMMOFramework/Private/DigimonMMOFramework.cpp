#include "DigimonMMOFramework.h"

DEFINE_LOG_CATEGORY(LogDigimonMMOFramework);

void FDigimonMMOFrameworkModule::StartupModule()
{
    UE_LOG(LogDigimonMMOFramework, Log, TEXT("Digimon MMO Framework 0.5.2-alpha loaded."));
}

void FDigimonMMOFrameworkModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FDigimonMMOFrameworkModule, DigimonMMOFramework)
