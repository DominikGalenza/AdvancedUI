// Vince Petrelli All Rights Reserved


#include "Widgets/Options/OptionsDataInteractionHelper.h"
#include "FrontendSettings/FrontendGameUserSettings.h"

FOptionsDataInteractionHelper::FOptionsDataInteractionHelper(const FString& SetterOrGetterFunctionPath)
	: CachedDynamicFunctionPath(SetterOrGetterFunctionPath)
{
	CachedWeakGameUserSettings = UFrontendGameUserSettings::Get();
}

FString FOptionsDataInteractionHelper::GetValueAsString() const
{
	FString OutStringValue;
	PropertyPathHelpers::GetPropertyValueAsString(
		CachedWeakGameUserSettings.Get(),
		CachedDynamicFunctionPath,
		OutStringValue
	);

	return OutStringValue;
}

void FOptionsDataInteractionHelper::SetValueFromString(const FString& StringValue)
{
	PropertyPathHelpers::SetPropertyValueFromString(
		CachedWeakGameUserSettings.Get(),
		CachedDynamicFunctionPath,
		StringValue
	);
}
