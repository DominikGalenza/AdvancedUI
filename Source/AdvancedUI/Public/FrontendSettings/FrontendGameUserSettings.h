// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "FrontendGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UFrontendGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
	
public:
	static UFrontendGameUserSettings* Get();

	//Gameplay Collection Tab//
	UFUNCTION()
	FString GetCurrentGameDifficulty() const { return CurrentGameDifficulty; }

	UFUNCTION()
	void SetCurrentGameDifficulty(const FString& NewDifficulty) { CurrentGameDifficulty = NewDifficulty; }
	//Gameplay Collection Tab//
	
private:
	UPROPERTY(Config)
	FString CurrentGameDifficulty;
};
