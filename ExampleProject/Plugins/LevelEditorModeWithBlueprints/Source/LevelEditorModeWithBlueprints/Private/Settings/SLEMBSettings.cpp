// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "Settings/SLEMBSettings.h"
#include "LEMBEdMode.h"
#include "Settings/LEMBSettingsConfig.h"
#include "Widgets/LEMBModeWidget.h"
#include <SlateOptMacros.h>
#include <Widgets/Layout/SScrollBox.h>
#include <EditorModeManager.h>

#define LOCTEXT_NAMESPACE "LevelEditorModeWithBlueprints"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLEMBSettings::Construct(const FArguments& InArgs,
                             TSharedRef<FLEMBEdModeToolkit> InParentToolkit)
{
    ConstructModeWidget();
}

void SLEMBSettings::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
    SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

    if (ModeWidget.IsStale() || ModeWidget == nullptr)
    {
        ConstructModeWidget();
    }
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FLEMBEdMode* SLEMBSettings::GetEditorMode() const
{
    return (FLEMBEdMode*)GLevelEditorModeTools().GetActiveMode(FLEMBEdMode::EM_LEMBEdModeId);
}

void SLEMBSettings::ConstructModeWidget()
{
    const ULEMBSettingsConfig* Config = GetDefault<ULEMBSettingsConfig>();
    if (Config->WidgetClass == nullptr)
    {
        return;
    }
    if (!Config->WidgetClass->IsChildOf(ULEMBModeWidget::StaticClass()))
    {
        return;
    }

    //~ We need da world
    UWorld* World = GEditor->GetEditorWorldContext().World();
    check(World);
    /** Create the widget of our UUserWidget type (UGUserWidget) from the class we loaded from the Content Browser */
    ModeWidget = CreateWidget<ULEMBModeWidget>(World, Config->WidgetClass);
    if (ModeWidget.IsStale())
    {
        return;
    }
    GetEditorMode()->SetModeWidget(ModeWidget.GetEvenIfUnreachable());

    /** Make sure widget was created */
    ChildSlot
    [
        SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .FillHeight(1.f)
        [
			SNew(SScrollBox)
            + SScrollBox::Slot()
			[
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
	            .AutoHeight()
	            [
	                ModeWidget->TakeWidget()
	            ]
            ]
        ]
    ];
}
