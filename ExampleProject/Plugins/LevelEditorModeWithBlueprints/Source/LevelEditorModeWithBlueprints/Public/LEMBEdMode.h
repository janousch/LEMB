// Copyright 2021 Ramon Janousch. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <EdMode.h>

class ULEMBModeWidget;

class FLEMBEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_LEMBEdModeId;
    
public:
	FLEMBEdMode();
	virtual ~FLEMBEdMode();

	/** FGCObject interface */
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	TSharedPtr<class FModeToolkit> GetToolkit();

	virtual void Enter() override;
	virtual void Exit() override;
    virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;
		
	bool LostFocus(FEditorViewportClient * ViewportClient, FViewport * Viewport) override;
    bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key,
                  EInputEvent Event) override;

	virtual bool HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy,
                             const FViewportClick& Click) override;

	/** Check to see if an actor can be selected in this mode - no side effects */
    virtual bool IsSelectionAllowed(AActor* InActor, bool bInSelection) const override;
	
	/** True if this mode uses a toolkit mode (eventually they all should) */
	bool UsesToolkits() const override;

    virtual bool CapturedMouseMove(FEditorViewportClient* InViewportClient, FViewport* InViewport,
                                   int32 InMouseX, int32 InMouseY) override;
    virtual void Render(const FSceneView* View, FViewport* Viewport,
                        FPrimitiveDrawInterface* PDI) override;
    virtual bool Select(AActor* InActor, bool bInSelected) override;
    virtual void ActorSelectionChangeNotify() override;
    virtual bool ShouldDrawWidget() const override;

    virtual bool MouseEnter(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x,
                            int32 y) override;
    virtual bool MouseLeave(FEditorViewportClient* ViewportClient, FViewport* Viewport) override;
    virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
    virtual bool ProcessEditDelete() override;

    void SetModeWidget(ULEMBModeWidget* NewModeWidget);

private:
    TWeakObjectPtr<ULEMBModeWidget> ModeWidget;

    FHitResult ViewportTrace(FEditorViewportClient* ViewportClient, FViewport* Viewport) const;

    bool IsEditorInPlayMode();

    bool HasValidModeWidget() const;
};
