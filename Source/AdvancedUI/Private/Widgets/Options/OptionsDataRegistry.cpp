// Vince Petrelli All Rights Reserved


#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"
#include "Widgets/Options/DataObjects/ListDataObject_String.h"

void UOptionsDataRegistry::InitializeOptionsDataRegistry(ULocalPlayer* OwningLocalPlayer)
{
	InitializeGameplayCollectionTab();
	InitializeAudioCollectionTab();
	InitializeVideoCollectionTab();
	InitializeControlsCollectionTab();
}

TArray<UListDataObject_Base*> UOptionsDataRegistry::GetListSourceItemsBySelectedTabID(const FName& SelectedTabID) const
{
	UListDataObject_Collection* const* FoundTabCollectionPtr = RegisteredOptionsTabCollections.FindByPredicate(
		[SelectedTabID](UListDataObject_Collection* AvailableTabCollection)->bool
		{
			return AvailableTabCollection->GetDataID() == SelectedTabID;
		}
	);

	checkf(FoundTabCollectionPtr, TEXT("No valid tab found under the ID %s"), *SelectedTabID.ToString());

	UListDataObject_Collection* FoundTabCollection = *FoundTabCollectionPtr;
	return FoundTabCollection->GetAllChildListData();
}

void UOptionsDataRegistry::InitializeGameplayCollectionTab()
{
	UListDataObject_Collection* GameplayTabCollection = NewObject<UListDataObject_Collection>();
	GameplayTabCollection->SetDataID(FName("GameplayTabCollection"));
	GameplayTabCollection->SetDataDisplayName(FText::FromString(TEXT("Gameplay")));

	UListDataObject_String* GameDifficulty = NewObject<UListDataObject_String>();
	GameDifficulty->SetDataID(FName("GameDifficulty"));
	GameDifficulty->SetDataDisplayName(FText::FromString("Difficulty"));
	GameplayTabCollection->AddChildListData(GameDifficulty);

	UListDataObject_String* TestItem = NewObject<UListDataObject_String>();
	TestItem->SetDataID(FName("TestItem"));
	TestItem->SetDataDisplayName(FText::FromString("Test Item"));
	GameplayTabCollection->AddChildListData(TestItem);

	RegisteredOptionsTabCollections.Add(GameplayTabCollection);
}

void UOptionsDataRegistry::InitializeAudioCollectionTab()
{
	UListDataObject_Collection* AudioTabCollection = NewObject<UListDataObject_Collection>();
	AudioTabCollection->SetDataID(FName("AudioTabCollection"));
	AudioTabCollection->SetDataDisplayName(FText::FromString(TEXT("Audio")));
	RegisteredOptionsTabCollections.Add(AudioTabCollection);
}

void UOptionsDataRegistry::InitializeVideoCollectionTab()
{
	UListDataObject_Collection* VideoTabCollection = NewObject<UListDataObject_Collection>();
	VideoTabCollection->SetDataID(FName("VideoTabCollection"));
	VideoTabCollection->SetDataDisplayName(FText::FromString(TEXT("Video")));
	RegisteredOptionsTabCollections.Add(VideoTabCollection);
}

void UOptionsDataRegistry::InitializeControlsCollectionTab()
{
	UListDataObject_Collection* ControlsTabCollection = NewObject<UListDataObject_Collection>();
	ControlsTabCollection->SetDataID(FName("ControlsTabCollection"));
	ControlsTabCollection->SetDataDisplayName(FText::FromString(TEXT("Controls")));
	RegisteredOptionsTabCollections.Add(ControlsTabCollection);
}
