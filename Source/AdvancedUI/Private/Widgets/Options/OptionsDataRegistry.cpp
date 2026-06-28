// Vince Petrelli All Rights Reserved


#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"
#include "Widgets/Options/DataObjects/ListDataObject_String.h"
#include "Widgets/Options/OptionsDataInteractionHelper.h"
#include "FrontendSettings/FrontendGameUserSettings.h"

#define MAKE_OPTIONS_DATA_CONTROL(SetterOrGetterFunctionName) \
	MakeShared<FOptionsDataInteractionHelper>(GET_FUNCTION_NAME_STRING_CHECKED(UFrontendGameUserSettings, SetterOrGetterFunctionName))

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

	//This is the full code for contructor data interactor helper.
	//TSharedPtr<FOptionsDataInteractionHelper> ConstructedHelper = 
	//	MakeShared<FOptionsDataInteractionHelper>(
	//		GET_FUNCTION_NAME_CHECKED(UFrontendGameUserSettings, GetCurrentGameDifficulty)
	//	);

	UListDataObject_String* GameDifficulty = NewObject<UListDataObject_String>();
	GameDifficulty->SetDataID(FName("GameDifficulty"));
	GameDifficulty->SetDataDisplayName(FText::FromString(TEXT("Difficulty")));
	GameDifficulty->SetDescriptionRichText(FText::FromString(TEXT("Adjusts the difficulty of the game expierence.\n\n<Bold>Easy:</> Focuses on the story experience. Provides the most relaxing combat.\n\n<Bold>Normal:</> Offers slightly harder combat expierence.\n\n<Bold>Hard:</> Offers a much more challenging combat expierence.\n\n<Bold>Very Hard:</> Provides the most challenging combat expierence. Not recommended for first playthrough.")));
	GameDifficulty->AddDynamicOption(TEXT("Easy"), FText::FromString(TEXT("Easy")));
	GameDifficulty->AddDynamicOption(TEXT("Normal"), FText::FromString(TEXT("Normal")));
	GameDifficulty->AddDynamicOption(TEXT("Hard"), FText::FromString(TEXT("Hard")));
	GameDifficulty->AddDynamicOption(TEXT("Very Hard"), FText::FromString(TEXT("Very Hard")));
	GameDifficulty->SetDataDynamicGetter(MAKE_OPTIONS_DATA_CONTROL(GetCurrentGameDifficulty));
	GameDifficulty->SetDataDynamicSetter(MAKE_OPTIONS_DATA_CONTROL(SetCurrentGameDifficulty));
	GameDifficulty->SetShouldApplySettingsImmediately(true);
	GameplayTabCollection->AddChildListData(GameDifficulty);

	UListDataObject_String* TestItem = NewObject<UListDataObject_String>();
	TestItem->SetDataID(FName("TestItem"));
	TestItem->SetDataDisplayName(FText::FromString(TEXT("Test Item")));
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
