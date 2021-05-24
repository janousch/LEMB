// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "LEMBEdModeToolkit.h"
#include "LEMBEdMode.h"
#include "Settings/SLEMBSettings.h"
#include <EditorModeManager.h>

FLEMBEdModeToolkit::FLEMBEdModeToolkit()
{
}

void FLEMBEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	LEMBSettingsWidget = SNew(SLEMBSettings, SharedThis(this));

	FModeToolkit::Init(InitToolkitHost);
}

FName FLEMBEdModeToolkit::GetToolkitFName() const
{
	return FName("LEMBEdMode");
}

FText FLEMBEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("LEMBEdModeToolkit", "DisplayName", "LEMBEdMode Tool");
}

class FEdMode* FLEMBEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FLEMBEdMode::EM_LEMBEdModeId);
}

TSharedPtr<class SWidget> FLEMBEdModeToolkit::GetInlineContent() const
{
	return LEMBSettingsWidget;
}
