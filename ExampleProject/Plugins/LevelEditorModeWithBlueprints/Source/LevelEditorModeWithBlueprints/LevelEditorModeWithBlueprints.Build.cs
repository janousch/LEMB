// Copyright 2021 Ramon Janousch. All Rights Reserved.

using UnrealBuildTool;

public class LevelEditorModeWithBlueprints : ModuleRules
{
	public LevelEditorModeWithBlueprints(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				
			}
            );
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"LevelEditorModeWithBlueprints/Private"
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "EditorScriptingUtilities"
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG",
				"InputCore",
				"UnrealEd",
				"LevelEditor",
                "EditorStyle",

                // IPluginManager
                "Projects",

                "AppFramework",
                "Core",
                "DesktopPlatform",
                "RenderCore",
                "RHI",
                "SourceControl",
                "ViewportInteraction",
                "VREditor",
                "PropertyEditor",
                "MainFrame",
                "InteractiveToolsFramework",
                "EditorInteractiveToolsFramework",
                "EditorScriptingUtilities",
				"Blutility",
				"DeveloperSettings"
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
                
            }
			);
    }
}
