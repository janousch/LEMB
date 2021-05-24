// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "LEMBSettingsConfig.generated.h"

class ULEMBModeWidget;

// Plugin configuration page in Project Settings
UCLASS(config=Editor, defaultconfig)
class LEVELEDITORMODEWITHBLUEPRINTS_API ULEMBSettingsConfig : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	ULEMBSettingsConfig();

	/* Mode Widget class for the Level Editor Tool. */
	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	TSubclassOf<ULEMBModeWidget> WidgetClass;

protected:

	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
#endif

};