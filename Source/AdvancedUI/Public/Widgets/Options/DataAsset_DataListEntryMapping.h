// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_DataListEntryMapping.generated.h"

class UListDataObject_Base;
class UWidget_ListEntry_Base;
/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UDataAsset_DataListEntryMapping : public UDataAsset
{
	GENERATED_BODY()
	
public:
	TSubclassOf<UWidget_ListEntry_Base> FindEntryWidgetClassByDataObject(UListDataObject_Base* DataObject) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<TSubclassOf<UListDataObject_Base>, TSubclassOf<UWidget_ListEntry_Base>> DataObjectListEntryMap;
};
