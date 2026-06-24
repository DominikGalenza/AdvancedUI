// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PropertyPathHelpers.h"

class UFrontendGameUserSettings;

/**
 * 
 */
class ADVANCEDUI_API FOptionsDataInteractionHelper
{

public:
	FOptionsDataInteractionHelper(const FString& SetterOrGetterFunctionPath);

	FString GetValueAsString() const;
	void SetValueFromString(const FString& StringValue);

private:
	FCachedPropertyPath CachedDynamicFunctionPath;
	TWeakObjectPtr<UFrontendGameUserSettings> CachedWeakGameUserSettings;
};
