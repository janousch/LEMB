// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include <Blueprint/UserWidget.h>
#include "LEMBModeWidget.generated.h"

UCLASS(Blueprintable)
class LEVELEDITORMODEWITHBLUEPRINTS_API ULEMBModeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "LEMB")
	FHitResult ViewportTrace(const FVector& Start, const FVector& Direction);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB|Viewport")
	void ActorSelectionChangeNotify(AActor* FirstSelectedActorInstance);

	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB|Viewport")
	void ViewportMouseMove(const FHitResult& ViewportTraceResult);
	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB|Viewport")
    void ViewportCapturedMouseMove(const FHitResult& ViewportTraceResult);

	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB|Viewport")
	void ViewportMouseEnter();
	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB|Viewport")
	void ViewportMouseLeave();

	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB")
	void SelectActor(AActor* Actor, const bool bSelected);

	UFUNCTION(BlueprintImplementableEvent, Category = "LEMB|Input")
    void InputKey(FKey Key, EInputEvent Event, bool& bOutHandled);

	UFUNCTION(BlueprintNativeEvent, Category = "LEMB")
	bool IsSelectionAllowed(AActor* InActor, bool bInSelection);

	FViewport* Viewport;

protected:
	/* TRUE if control is down and the user clicked in the viewport before pressing control. */
	UFUNCTION(BlueprintCallable, Category = "LEMB|Viewport")
    bool IsCtrlDown() const;
    /* TRUE if alt is down and the user clicked in the viewport before pressing alt. */
	UFUNCTION(BlueprintCallable, Category = "LEMB|Viewport")
    bool IsAltDown() const;
    /* TRUE if shift is down and the user clicked in the viewport before pressing shift. */
	UFUNCTION(BlueprintCallable, Category = "LEMB|Viewport")
	bool IsShiftDown() const;
	UFUNCTION(BlueprintCallable, Category = "LEMB|Viewport")
	bool IsKeyDown(FKey Key) const;
};