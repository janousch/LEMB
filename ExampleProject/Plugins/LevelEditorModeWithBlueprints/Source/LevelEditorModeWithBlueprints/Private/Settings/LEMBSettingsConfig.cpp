// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "Settings/LEMBSettingsConfig.h"
#include "GameFramework/InputSettings.h"

#define LOCTEXT_NAMESPACE "FLEMBSettingsModule"

ULEMBSettingsConfig::ULEMBSettingsConfig()
{
	CategoryName = "Plugins";
}

void ULEMBSettingsConfig::PostInitProperties()
{
	Super::PostInitProperties();
}

#if WITH_EDITOR
FText ULEMBSettingsConfig::GetSectionText() const
{
	return LOCTEXT("LEMBSettingsName", "LEMB Settings");
}

FText ULEMBSettingsConfig::GetSectionDescription() const
{
	return LOCTEXT("LEMBSettingsDescription", "Configure the LEMB Settings plugin.");
}
#endif

#undef LOCTEXT_NAMESPACE