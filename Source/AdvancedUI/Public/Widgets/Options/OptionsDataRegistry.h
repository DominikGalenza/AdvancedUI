// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptionsDataRegistry.generated.h"

class UListDataObject_Collection;
class UListDataObject_Base;

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UOptionsDataRegistry : public UObject
{
	GENERATED_BODY()
	
public:
	//Gets called by options screen right after the object of type UOptionsDataRegistry is created
	void InitializeOptionsDataRegistry(ULocalPlayer* OwningLocalPlayer);

	const TArray<UListDataObject_Collection*>& GetRegisteredOptionsTabCollections() const { return RegisteredOptionsTabCollections; }

	TArray<UListDataObject_Base*> GetListSourceItemsBySelectedTabID(const FName& SelectedTabID) const;

private:
	void InitializeGameplayCollectionTab();
	void InitializeAudioCollectionTab();
	void InitializeVideoCollectionTab();
	void InitializeControlsCollectionTab();

	UPROPERTY(Transient)
	TArray<UListDataObject_Collection*> RegisteredOptionsTabCollections;
};
