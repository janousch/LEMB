// Copyright 2021 Ramon Janousch. All Rights Reserved.

#include "LEMBEdMode.h"
#include "LEMBEdModeToolkit.h"
#include "Settings/LEMBModeWidget.h"
#include <Toolkits/ToolkitManager.h>
#include <EditorModeManager.h>
#include <EditorViewportClient.h>

const FEditorModeID FLEMBEdMode::EM_LEMBEdModeId = TEXT("EM_LEMBEdMode");

FLEMBEdMode::FLEMBEdMode()
{
    
}

FLEMBEdMode::~FLEMBEdMode()
{
    
}

void FLEMBEdMode::AddReferencedObjects(FReferenceCollector& Collector)
{
    // Call parent implementation
    FEdMode::AddReferencedObjects(Collector);
}

TSharedPtr<class FModeToolkit> FLEMBEdMode::GetToolkit()
{
    return Toolkit;
}

void FLEMBEdMode::Enter()
{
    FEdMode::Enter();

    if (!Toolkit.IsValid() && UsesToolkits())
    {
        Toolkit = MakeShareable(new FLEMBEdModeToolkit);
        Toolkit->Init(Owner->GetToolkitHost());
    }
}

void FLEMBEdMode::Exit()
{
    if (Toolkit.IsValid())
    {
        FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
        Toolkit.Reset();
    }

    GEditor->SelectNone(true, true, false);

    // Call base Exit method to ensure proper cleanup
    FEdMode::Exit();
}

bool FLEMBEdMode::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x,
                           int32 y)
{
    // Runs twice each tick if the mouse is inside the viewport.

    if (!ModeWidget.IsStale())
    {
        const FHitResult HitResult = ViewportTrace(ViewportClient, Viewport);
        ModeWidget->ViewportMouseMove(HitResult);
    }
	
    return FEdMode::MouseMove(ViewportClient, Viewport, x, y);
}

bool FLEMBEdMode::LostFocus(FEditorViewportClient* ViewportClient, FViewport* Viewport)
{
    const bool bHandled = FEdMode::LostFocus(ViewportClient, Viewport);

    return bHandled;
}

bool FLEMBEdMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key,
                          EInputEvent Event)
{
    if (!ModeWidget.IsStale())
    {
        ModeWidget->InputKey(Key, Event);
    }

    return FEdMode::InputKey(ViewportClient, Viewport, Key, Event);
}

bool FLEMBEdMode::HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy,
                             const FViewportClick& Click)
{
    return false;
}

bool FLEMBEdMode::IsSelectionAllowed(AActor* InActor, bool bInSelection) const
{
    // This function is called many times in a single tick.

    if (!ModeWidget.IsStale())
    {
        return ModeWidget->IsSelectionAllowed(InActor, bInSelection);
    }
    
    return true;
}

bool FLEMBEdMode::UsesToolkits() const
{
    return true;
}

bool FLEMBEdMode::StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
    if (!ModeWidget.IsStale())
    {
        ModeWidget->Viewport = InViewport;
    }

    return true;
}

bool FLEMBEdMode::EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
    if (!ModeWidget.IsStale())
    {
        ModeWidget->Viewport = nullptr;
    }
	
    return false;
}

void FLEMBEdMode::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{
    // Runs every tick.

    FEdMode::Render(View, Viewport, PDI);
}

bool FLEMBEdMode::Select(AActor* InActor, bool bInSelected)
{
    if (!ModeWidget.IsStale())
    {
        ModeWidget->SelectActor(InActor, bInSelected);
    }
	
    return false;
}

void FLEMBEdMode::ActorSelectionChangeNotify()
{
    if (ModeWidget.IsStale())
    {
        return;
    }
    ModeWidget->ActorSelectionChangeNotify(GetFirstSelectedActorInstance());
}

bool FLEMBEdMode::ShouldDrawWidget() const
{
    // Runs twice each tick.

    return false;
}

bool FLEMBEdMode::MouseEnter(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x,
                            int32 y)
{
    // Called when the mouse enters the viewport.

    if (!ModeWidget.IsStale())
    {
        ModeWidget->ViewportMouseEnter();
    }
	
    return false;
}

bool FLEMBEdMode::MouseLeave(FEditorViewportClient* ViewportClient, FViewport* Viewport)
{
    // Called when the mouse leaves the viewport.

    if (!ModeWidget.IsStale())
    {
        ModeWidget->ViewportMouseLeave();
    }
	
    return false;
}

bool FLEMBEdMode::CapturedMouseMove(FEditorViewportClient* InViewportClient, FViewport* InViewport,
                                   int32 InMouseX, int32 InMouseY)
{
    // Called every when the mouse is inside the viewport and any mouse button is down and the mouse moved (multiple times per tick).
    
    if (!ModeWidget.IsStale())
    {
        const FHitResult HitResult = ViewportTrace(InViewportClient, InViewport);
        ModeWidget->ViewportCapturedMouseMove(HitResult);
    }
	
    return false;
}

void FLEMBEdMode::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
    if (IsEditorInPlayMode())
    {
        RequestDeletion();
        return;
    }

    FEdMode::Tick(ViewportClient, DeltaTime);
}

bool FLEMBEdMode::ProcessEditDelete()
{
    return false;
}

void FLEMBEdMode::SetModeWidget(ULEMBModeWidget* NewModeWidget)
{
    ModeWidget = NewModeWidget;
}

FHitResult FLEMBEdMode::ViewportTrace(FEditorViewportClient* ViewportClient,
                                          FViewport* Viewport) const
{
    if (ModeWidget.IsStale())
    {
        return FHitResult();
    }

    // Compute a world space ray from the screen space mouse coordinates
    FSceneViewFamilyContext ViewFamily(
        FSceneViewFamily::ConstructionValues(ViewportClient->Viewport, ViewportClient->GetScene(),
            ViewportClient->EngineShowFlags)
        .SetRealtimeUpdate(ViewportClient->IsRealtime()));

    FSceneView* View = ViewportClient->CalcSceneView(&ViewFamily);
    const FViewportCursorLocation MouseViewportRay(View,
        static_cast<FEditorViewportClient*>(Viewport->GetClient()),
        Viewport->GetMouseX(), Viewport->GetMouseY());
    const FVector TraceStart = MouseViewportRay.GetOrigin();
	
    FHitResult HitResult = ModeWidget->ViewportTrace(GetWorld(), TraceStart, MouseViewportRay.GetDirection());

    return HitResult;
}

bool FLEMBEdMode::IsEditorInPlayMode()
{
    if (GEditor->PlayWorld || GIsPlayInEditorWorld)
    {
        return true;
    }

    return false;
}
