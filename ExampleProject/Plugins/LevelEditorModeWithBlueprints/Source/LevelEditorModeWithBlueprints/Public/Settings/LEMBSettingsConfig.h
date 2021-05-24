// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "LEMBSettingsConfig.generated.h"

class ULEMBModeWidget;

// Plugin configuration page in Project Settings
UCLASS(config=Game, defaultconfig)
class LEVELEDITORMODEWITHBLUEPRINTS_API ULEMBSettingsConfig : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	ULEMBSettingsConfig();

	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	TSubclassOf<ULEMBModeWidget> WidgetClass;
	
	// Config ini file (without extension) that settings are saved to.
	// Requires engine restart for changes to take effect.
	UPROPERTY(Config, EditAnywhere, Category = Settings)
	FString SettingsIniName = "LEMB";

	// Config section that settings are saved to within the config ini file
	UPROPERTY(Config, EditAnywhere, Category = Settings)
	FString SettingsSectionName = "LEMB";

protected:

	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
#endif

};