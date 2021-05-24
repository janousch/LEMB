// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>

class SLEMBSettings;

class FLEMBEdModeToolkit : public FModeToolkit
{
public:

	FLEMBEdModeToolkit();
	
	TSharedPtr<SLEMBSettings> LEMBSettingsWidget;

	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override;
};
