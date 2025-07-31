// Vince Petrelli All Rights Reserved


#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"

void UOptionsDataRegistry::InitializeOptionsDataRegistry(ULocalPlayer* OwningLocalPlayer)
{
	InitializeGameplayCollectionTab();
	InitializeAudioCollectionTab();
	InitializeVideoCollectionTab();
	InitializeControlsCollectionTab();
}

void UOptionsDataRegistry::InitializeGameplayCollectionTab()
{
	UListDataObject_Collection* GameplayTabCollection = NewObject<UListDataObject_Collection>();
	GameplayTabCollection->SetDataID(FName("GameplayTabCollection"));
	GameplayTabCollection->SetDataDisplayName(FText::FromString(TEXT("Gameplay")));
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
