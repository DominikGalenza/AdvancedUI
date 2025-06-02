// Vince Petrelli All Rights Reserved


#include "AsyncActions/AsyncAction_PushSoftWidget.h"

UAsyncAction_PushSoftWidget* UAsyncAction_PushSoftWidget::PushSoftWidget(const UObject* WorldContextObject, APlayerController* OwningPlayerController, TSoftClassPtr<UWidget_ActivatableBase> SoftWidgetClass, UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag WidgetStackTag, bool bFocusOnNewlyPushedWidget)
{
	checkf(!SoftWidgetClass.IsNull(), TEXT("PushSoftWisgetToStack was passed a null soft widget class"));

	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UAsyncAction_PushSoftWidget* Node = NewObject<UAsyncAction_PushSoftWidget>();
			Node->RegisterWithGameInstance(World);
			return Node;
		}
	}
	return nullptr;
}
