// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include "LEMBEdModeToolkit.h"
#include <CoreMinimal.h>
#include <Widgets/DeclarativeSyntaxSupport.h>
//#include <Styling/WidgetStyle.h>
#include <Widgets/SCompoundWidget.h>

class ULEMBModeWidget;
//struct FPropertyAndParent;

class LEVELEDITORMODEWITHBLUEPRINTS_API SLEMBSettings : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLEMBSettings) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedRef<FLEMBEdModeToolkit> InParentToolkit);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

protected:

	class FLEMBEdMode* GetEditorMode() const;

private:

	void ConstructModeWidget();
	
	TWeakObjectPtr<ULEMBModeWidget> ModeWidget;
};
