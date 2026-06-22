// Vince Petrelli All Rights Reserved


#include "Widgets/Options/ListEntries/Widget_ListEntry_Base.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "CommonTextBlock.h"

void UWidget_ListEntry_Base::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	OnOwningListDataObjectSet(CastChecked<UListDataObject_Base>(ListItemObject));
}

void UWidget_ListEntry_Base::OnOwningListDataObjectSet(UListDataObject_Base* OwningListDataObject)
{
	if (CommonText_SettingsDisplayName)
	{
		CommonText_SettingsDisplayName->SetText(OwningListDataObject->GetDataDisplayName());
	}
}
