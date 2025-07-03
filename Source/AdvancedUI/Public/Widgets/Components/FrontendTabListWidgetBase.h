// Vince Petrelli All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "FrontendTabListWidgetBase.generated.h"

class UFrontendButtonBase;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class ADVANCEDUI_API UFrontendTabListWidgetBase : public UCommonTabListWidgetBase
{
	GENERATED_BODY()
	
private:
	//~ Begin UWidget Interface
#if WITH_EDITOR	
	virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
#endif
	//~ End UWidget Interface

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Frontend Tab List Settings", meta = (AllowPrivateAccess = "true", ClampMin = "1", CLampMax = "10"))
	int32 DebugEditorPreviewTabCount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Frontend Tab List Settings", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UFrontendButtonBase> TabButtonEntryWidgetClass;
};
