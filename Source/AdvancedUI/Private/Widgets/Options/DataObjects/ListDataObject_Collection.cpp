// Vince Petrelli All Rights Reserved


#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"

void UListDataObject_Collection::AddChildListData(UListDataObject_Base* ChildListData)
{
	//Notify the child list data to initialize itself
	ChildListData->InitializeDataObject();
	//Set the child list data's parent to this
	ChildListData->SetParentData(this);

	ChildListDataArray.Add(ChildListData);
}

TArray<UListDataObject_Base*> UListDataObject_Collection::GetAllChildListData() const
{
	return ChildListDataArray;
}

bool UListDataObject_Collection::HasAnyChildListData() const
{
	return !ChildListDataArray.IsEmpty();
}
