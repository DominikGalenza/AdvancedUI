// Vince Petrelli All Rights Reserved


#include "Widgets/Options/DataObjects/ListDataObject_Value.h"

void UListDataObject_Value::SetDataDynamicGetter(const TSharedPtr<FOptionsDataInteractionHelper> DynamicGetter)
{
	DataDynamicGetter = DynamicGetter;
}

void UListDataObject_Value::SetDataDynamicSetter(const TSharedPtr<FOptionsDataInteractionHelper> DynamicSetter)
{
	DataDynamicSetter = DynamicSetter;
}
