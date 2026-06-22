// Vince Petrelli All Rights Reserved


#include "Widgets/Options/ListEntries/Widget_ListEntry_String.h"
#include "Widgets/Options/DataObjects/ListDataObject_String.h"
#include "Widgets/Components/FrontendCommonRotator.h"

void UWidget_ListEntry_String::OnOwningListDataObjectSet(UListDataObject_Base* OwningListDataObject)
{
	Super::OnOwningListDataObjectSet(OwningListDataObject);

	CachedOwningStringDataObject = CastChecked<UListDataObject_String>(OwningListDataObject);

	CommonRotator_AvailableOption->PopulateTextLabels(CachedOwningStringDataObject->GetAvailableOptionsTextArray());
	CommonRotator_AvailableOption->SetSelectedOptionByText(CachedOwningStringDataObject->GetCurrentDisplayText());
}
