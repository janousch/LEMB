// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include <Styling/ISlateStyle.h>

class FLEMBSlateStyle
{
public:
	static void Initialize();
	static void Shutdown();
	static TSharedPtr<class ISlateStyle> Get();

private:
	static FString InContent(const FString& RelativePath, const ANSICHAR* Extension);

private:
	static TSharedPtr<class FSlateStyleSet> StyleSet;
};