// Vince Petrelli All Rights Reserved


#include "Widgets/Options/DataObjects/ListDataObject_String.h"

void UListDataObject_String::AddDynamicOption(const FString& StringValue, const FText& DisplayText)
{
	AvailableOptionsStringArray.Add(StringValue);
	AvailableOptionsTextArray.Add(DisplayText);
}

void UListDataObject_String::OnDataObjectInitialized()
{
	if (!AvailableOptionsStringArray.IsEmpty())
	{
		CurrentStringValue = AvailableOptionsStringArray[0];
	}

	//TODO::Read from the saved string value and use it to set the CurrentStringValue

	if (!TrySetDisplayTextFromStringValue(CurrentStringValue))
	{
		CurrentDisplayText = FText::FromString(TEXT("Invalid Option"));
	}
}

bool UListDataObject_String::TrySetDisplayTextFromStringValue(const FString& StringValue)
{
	const int32 CurrentFoundIndex = AvailableOptionsStringArray.IndexOfByKey(StringValue);

	if (AvailableOptionsTextArray.IsValidIndex(CurrentFoundIndex))
	{
		CurrentDisplayText = AvailableOptionsTextArray[CurrentFoundIndex];

		return true;
	}

	return false;
}
