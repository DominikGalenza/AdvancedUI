// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widget_ActivatableBase.generated.h"

class AFrontendPlayerController;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class ADVANCEDUI_API UWidget_ActivatableBase : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintPure)
	AFrontendPlayerController* GetOwningFrontendPlayerController();

private:
	TWeakObjectPtr<AFrontendPlayerController> CachedOwningFrontendPlayerController;
};
