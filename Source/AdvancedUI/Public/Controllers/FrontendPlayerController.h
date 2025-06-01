// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FrontendPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API AFrontendPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	//~ Begin APlayerController interface
	virtual void OnPossess(APawn* aPawn) override;
	//~ End APlayerController interface
};
