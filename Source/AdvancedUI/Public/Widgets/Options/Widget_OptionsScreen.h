// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_OptionsScreen.generated.h"

class UOptionsDataRegistry;
class UFrontendTabListWidgetBase;
class UFrontendCommonListView;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class ADVANCEDUI_API UWidget_OptionsScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()

protected:
	//~ Begin UUserWidget interface
	virtual void NativeOnInitialized() override;
	//~ End UUserWidget interface

	//~ Begin UCommonActivatableWidget interface
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
	//~ End UCommonActivatableWidget interface

private:
	UOptionsDataRegistry* GetOrCreateDataRegistry();

	void OnResetBoundActionTriggered();
	void OnBackBoundActionTriggered();
	void OnListViewItemHovered(UObject* HoveredItem, bool bWasHovered);
	void OnListViewItemSelected(UObject* SelectedItem);

	UFUNCTION()
	void OnOptionsTabSelected(FName TabID);

	//Bound widgets//
	UPROPERTY(meta = (BindWidget))
	UFrontendTabListWidgetBase* TabListWidget_OptionsTabs;

	UPROPERTY(meta = (BindWidget))
	UFrontendCommonListView* CommonListView_OptionsList;
	//Bound widgets//

	//Handle creation of data in the options screen. Direct access to this variable is forbidden
	UPROPERTY(Transient)
	UOptionsDataRegistry* CreatedOwningDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category = "Frontend Options Screen", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;

	FUIActionBindingHandle ResetActionHandle;
};
