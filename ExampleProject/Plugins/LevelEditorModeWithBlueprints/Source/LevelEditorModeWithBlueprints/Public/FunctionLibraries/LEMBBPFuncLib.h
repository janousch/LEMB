// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include <Kismet/KismetSystemLibrary.h>
#include <Engine/EngineTypes.h>
#include <Kismet/BlueprintFunctionLibrary.h>
#include "LEMBBPFuncLib.generated.h"

UCLASS(MinimalAPI)
class ULEMBBPFuncLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Level Editor Mode|Collision",
              meta = (bIgnoreSelf = "true", WorldContext = "WorldContextObject",
                      AutoCreateRefTerm = "ActorsToIgnore", DisplayName = "LEMB LineTraceByChannel",
                      Keywords = "raycast"))
    static bool LEMBLineTrace(UObject* WorldContextObject, const FVector& Start,
                              const FVector& Direction, ETraceTypeQuery TraceChannel,
                              bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore,
                              EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit);

    UFUNCTION(BlueprintCallable, Category = "Level Editor Mode|Collision",
              meta = (bIgnoreSelf = "true", WorldContext = "WorldContextObject",
                      AutoCreateRefTerm = "ActorsToIgnore", DisplayName = "LEMB SphereTraceByChannel",
                      Keywords = "raycast"))
    static bool LEMBSphereTrace(UObject* WorldContextObject, const FVector& Start,
                                const FVector& Direction, const float Radius,
                                const ETraceTypeQuery TraceChannel, const bool bTraceComplex,
                                const TArray<AActor*>& ActorsToIgnore,
                                EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit);

    UFUNCTION(BlueprintCallable, Category = "Level Editor Mode|Collision",
              meta = (bIgnoreSelf = "true", WorldContext = "WorldContextObject",
                      AutoCreateRefTerm = "ActorsToIgnore", DisplayName = "LEMB BoxTraceByChannel",
                      Keywords = "raycast"))
    static bool LEMBBoxTrace(UObject* WorldContextObject, const FVector& Start,
                             const FVector& Direction, const FVector& HalfSize,
                             const FRotator& Orientation, const ETraceTypeQuery TraceChannel,
                             const bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore,
                             EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit);

    UFUNCTION(BlueprintCallable, Category = "Level Editor Mode|Collision",
              meta = (bIgnoreSelf = "true", WorldContext = "WorldContextObject",
                      AutoCreateRefTerm = "ActorsToIgnore", DisplayName = "LEMB CapsuleTraceByChannel",
                      Keywords = "raycast"))
    static bool LEMBCapsuleTrace(UObject* WorldContextObject, const FVector& Start,
                                 const FVector& Direction, const float Radius,
                                 const float HalfHeight, const ETraceTypeQuery TraceChannel,
                                 const bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore,
                                 EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit);

};
