// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/ListEntries/Widget_ListEntry_Base.h"
#include "Widget_ListEntry_String.generated.h"

class UFrontendButtonBase;
class UFrontendCommonRotator;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class ADVANCEDUI_API UWidget_ListEntry_String : public UWidget_ListEntry_Base
{
	GENERATED_BODY()

private:
	//Bound Widgets
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	UFrontendButtonBase* CommonButton_PreviousOption;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	UFrontendButtonBase* CommonButton_NextOption;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	UFrontendCommonRotator* CommonRotator_AvailableOption;
	//Bound Widgets
};
