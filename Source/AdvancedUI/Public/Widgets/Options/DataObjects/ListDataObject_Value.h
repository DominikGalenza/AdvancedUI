// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "ListDataObject_Value.generated.h"

class FOptionsDataInteractionHelper;
/**
 * 
 */
UCLASS(Abstract)
class ADVANCEDUI_API UListDataObject_Value : public UListDataObject_Base
{
	GENERATED_BODY()
	
public:
	void SetDataDynamicGetter(const TSharedPtr<FOptionsDataInteractionHelper> DynamicGetter);
	void SetDataDynamicSetter(const TSharedPtr<FOptionsDataInteractionHelper> DynamicSetter);

protected:
	TSharedPtr<FOptionsDataInteractionHelper> DataDynamicGetter;
	TSharedPtr<FOptionsDataInteractionHelper> DataDynamicSetter;		
};
