using UnrealBuildTool;

public class DigimonMMOFramework : ModuleRules
{
    public DigimonMMOFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "NetCore",
            "UMG",
            "Slate",
            "SlateCore",
            "DeveloperSettings",
            "Niagara",
            "AIModule",
            "NavigationSystem"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "InputCore"
        });
    }
}
