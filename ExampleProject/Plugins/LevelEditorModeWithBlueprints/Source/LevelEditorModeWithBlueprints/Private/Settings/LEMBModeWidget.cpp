// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "Settings/LEMBModeWidget.h"
#include <Kismet/KismetSystemLibrary.h>


FHitResult ULEMBModeWidget::ViewportTrace_Implementation(UObject* WorldContext, const FVector& Start,
                                                         const FVector& Direction)
{
    static constexpr float TraceDistance = HALF_WORLD_MAX;
    FHitResult HitResult;
    const FVector End = Start + Direction * TraceDistance;
    UKismetSystemLibrary::LineTraceSingle(WorldContext, Start, End, ETraceTypeQuery::TraceTypeQuery1, true, TArray<AActor*>(), EDrawDebugTrace::None, HitResult, true);

    return HitResult;
}

bool ULEMBModeWidget::IsSelectionAllowed_Implementation(AActor* InActor, bool bInSelection)
{
    return true;
}

bool ULEMBModeWidget::IsCtrlDown() const
{
    return IsKeyDown(EKeys::LeftControl) || IsKeyDown(EKeys::RightControl);
}

bool ULEMBModeWidget::IsAltDown() const
{
    return IsKeyDown(EKeys::LeftAlt) || IsKeyDown(EKeys::RightAlt);
}

bool ULEMBModeWidget::IsShiftDown() const
{
    return IsKeyDown(EKeys::LeftShift) || IsKeyDown(EKeys::RightShift);
}

bool ULEMBModeWidget::IsKeyDown(FKey Key) const
{
    if (Viewport == nullptr)
    {
        return false;
    }

    return Viewport->KeyState(Key);
}
