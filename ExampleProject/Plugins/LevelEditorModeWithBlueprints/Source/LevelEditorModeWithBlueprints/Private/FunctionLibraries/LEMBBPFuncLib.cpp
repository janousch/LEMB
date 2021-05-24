// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "FunctionLibraries/LEMBBPFuncLib.h"
#include <Kismet/KismetSystemLibrary.h>

bool ULEMBBPFuncLib::LEMBLineTrace(UObject* WorldContextObject, const FVector& Start,
                                   const FVector& Direction, ETraceTypeQuery TraceChannel,
                                   bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore,
                                   EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
    const FVector End = Start + (Direction * HALF_WORLD_MAX);
    return UKismetSystemLibrary::LineTraceSingle(WorldContextObject, Start, End, TraceChannel,
                                                 bTraceComplex, ActorsToIgnore, DrawDebugType,
                                                 OutHit, true);
}

bool ULEMBBPFuncLib::LEMBSphereTrace(UObject* WorldContextObject, const FVector& Start,
                                     const FVector& Direction, const float Radius,
                                     const ETraceTypeQuery TraceChannel, const bool bTraceComplex,
                                     const TArray<AActor*>& ActorsToIgnore,
                                     EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
    const FVector End = Start + (Direction * HALF_WORLD_MAX);
    return UKismetSystemLibrary::SphereTraceSingle(WorldContextObject, Start, End, Radius,
                                                   TraceChannel, bTraceComplex, ActorsToIgnore,
                                                   DrawDebugType, OutHit, true);
}

bool ULEMBBPFuncLib::LEMBBoxTrace(UObject* WorldContextObject, const FVector& Start,
                                  const FVector& Direction, const FVector& HalfSize,
                                  const FRotator& Orientation, const ETraceTypeQuery TraceChannel,
                                  const bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore,
                                  EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
    const FVector End = Start + (Direction * HALF_WORLD_MAX);
    return UKismetSystemLibrary::BoxTraceSingle(WorldContextObject, Start, End, HalfSize,
                                                Orientation, TraceChannel, bTraceComplex,
                                                ActorsToIgnore, DrawDebugType, OutHit, true);
}

bool ULEMBBPFuncLib::LEMBCapsuleTrace(UObject* WorldContextObject, const FVector& Start,
                                      const FVector& Direction, const float Radius,
                                      const float HalfHeight, const ETraceTypeQuery TraceChannel,
                                      const bool bTraceComplex,
                                      const TArray<AActor*>& ActorsToIgnore,
                                      EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit)
{
    const FVector End = Start + (Direction * HALF_WORLD_MAX);
    return UKismetSystemLibrary::CapsuleTraceSingle(WorldContextObject, Start, End, Radius,
                                                    HalfHeight, TraceChannel, bTraceComplex,
                                                    ActorsToIgnore, DrawDebugType, OutHit, true);
}
