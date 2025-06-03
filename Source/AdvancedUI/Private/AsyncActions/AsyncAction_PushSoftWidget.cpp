// Vince Petrelli All Rights Reserved


#include "AsyncActions/AsyncAction_PushSoftWidget.h"
#include "Subsystems/FrontendUISubsystem.h"
#include "Widgets/Widget_ActivatableBase.h"

UAsyncAction_PushSoftWidget* UAsyncAction_PushSoftWidget::PushSoftWidget(const UObject* WorldContextObject, APlayerController* OwningPlayerController, TSoftClassPtr<UWidget_ActivatableBase> SoftWidgetClass, UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag WidgetStackTag, bool bFocusOnNewlyPushedWidget)
{
	checkf(!SoftWidgetClass.IsNull(), TEXT("PushSoftWisgetToStack was passed a null soft widget class"));

	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UAsyncAction_PushSoftWidget* Node = NewObject<UAsyncAction_PushSoftWidget>();
			Node->CachedOwningWorld = World;
			Node->CachedOwningPlayerController = OwningPlayerController;
			Node->CachedSoftWidgetClass = SoftWidgetClass;
			Node->CachedWidgetStackTag = WidgetStackTag;
			Node->bCachedFocusOnNewlyPushedWidget = bFocusOnNewlyPushedWidget;

			Node->RegisterWithGameInstance(World);
			return Node;
		}
	}
	return nullptr;
}

void UAsyncAction_PushSoftWidget::Activate()
{
	UFrontendUISubsystem* FrontendUISubsystem = UFrontendUISubsystem::Get(CachedOwningWorld.Get());
	FrontendUISubsystem->PushSoftWidgetToStackAsync(CachedWidgetStackTag, CachedSoftWidgetClass,
		[this](EAsyncPushWidgetState PushState, UWidget_ActivatableBase* PushedWidget)
		{
			switch (PushState)
			{
			case EAsyncPushWidgetState::OnCreatedBeforePush:
				PushedWidget->SetOwningPlayer(CachedOwningPlayerController.Get());
				OnWidgetCreatedBeforePush.Broadcast(PushedWidget);
				break;
			case EAsyncPushWidgetState::AfterPush:
				AfterPush.Broadcast(PushedWidget);
				if (bCachedFocusOnNewlyPushedWidget)
				{
					if (UWidget* WidgetToFocus = PushedWidget->GetDesiredFocusTarget())
					{
						WidgetToFocus->SetFocus();
					}
				}
				SetReadyToDestroy();
				break;
			default:
				break;
			}
		}
	);
}
