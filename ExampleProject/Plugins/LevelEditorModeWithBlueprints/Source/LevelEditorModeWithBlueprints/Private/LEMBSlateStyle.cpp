// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "LEMBSlateStyle.h"
#include <Styling/SlateStyle.h>
#include <Styling/SlateStyleRegistry.h>
#include <HAL/FileManager.h>
#include <Interfaces/IPluginManager.h>

FString FLEMBSlateStyle::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
	const auto ThisPlugin = IPluginManager::Get().FindPlugin(TEXT("LevelEditorModeWithBlueprints"));
    check(ThisPlugin.IsValid());
    static FString ContentDir = ThisPlugin->GetBaseDir() / TEXT("Resources");
	return (ContentDir / RelativePath) + Extension;
}

TSharedPtr<FSlateStyleSet> FLEMBSlateStyle::StyleSet = nullptr;
TSharedPtr<class ISlateStyle> FLEMBSlateStyle::Get() { return StyleSet; }

void FLEMBSlateStyle::Initialize()
{
	// Only register once
	if (StyleSet.IsValid())
	{
		return;
	}

	StyleSet = MakeShareable(new FSlateStyleSet("LEMBSlateStyle"));

	const FString ProjectResourceDir = FPaths::ProjectPluginsDir() / TEXT("LevelEditorModeWithBlueprints/Resources");
	const FString EngineResourceDir = FPaths::EnginePluginsDir() / TEXT("LevelEditorModeWithBlueprints/Resources");

	if (IFileManager::Get().DirectoryExists(*ProjectResourceDir)) //Is the plugin in the project? In that case, use those resources
	{
		StyleSet->SetContentRoot(ProjectResourceDir);
		StyleSet->SetCoreContentRoot(ProjectResourceDir);
	}
	else //Otherwise, use the global ones
	{
		StyleSet->SetContentRoot(EngineResourceDir);
		StyleSet->SetCoreContentRoot(EngineResourceDir);
	}

	StyleSet->Set("LEMB.Icon", new FSlateImageBrush(FLEMBSlateStyle::InContent("Icon40", ".png"), FVector2D(40.0f, 40.0f)));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
};

void FLEMBSlateStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}
