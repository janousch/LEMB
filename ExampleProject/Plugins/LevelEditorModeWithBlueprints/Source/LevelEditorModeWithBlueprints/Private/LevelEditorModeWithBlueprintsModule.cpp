// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "LevelEditorModeWithBlueprintsModule.h"
#include "LEMBEdMode.h"
#include "LEMBSlateStyle.h"

#define LOCTEXT_NAMESPACE "FLevelEditorModeWithBlueprintsModule"

void FLevelEditorModeWithBlueprintsModule::StartupModule()
{
    FLEMBSlateStyle::Initialize();

    FSlateIcon LevelEditorModeWithBlueprintsIcon =
        FSlateIcon(FLEMBSlateStyle::Get()->GetStyleSetName(), "LEMB.Icon");

    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    FEditorModeRegistry::Get().RegisterMode<FLEMBEdMode>(FLEMBEdMode::EM_LEMBEdModeId,
                                                             LOCTEXT("LevelEditorModeWithBlueprintsName",
                                                                     "Level Editor Mode with Blueprints"),
                                                             LevelEditorModeWithBlueprintsIcon, true, 100);
}

void FLevelEditorModeWithBlueprintsModule::ShutdownModule()
{
	FLEMBSlateStyle::Shutdown();

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FLEMBEdMode::EM_LEMBEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLevelEditorModeWithBlueprintsModule, LevelEditorModeWithBlueprints)
