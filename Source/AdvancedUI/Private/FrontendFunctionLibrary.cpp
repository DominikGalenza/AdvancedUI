// Vince Petrelli All Rights Reserved


#include "FrontendFunctionLibrary.h"
#include "FrontendSettings/FrontendDeveloperSettings.h"

TSoftClassPtr<UWidget_ActivatableBase> UFrontendFunctionLibrary::GetFrontendSoftWidgetClassByTag(UPARAM(meta = (Categories = "Frontend.Widget")) FGameplayTag WidgetTag)
{
	const UFrontendDeveloperSettings* FrontendDeveloperSettings = GetDefault<UFrontendDeveloperSettings>();
	checkf(FrontendDeveloperSettings->FrontendWidgetMap.Contains(WidgetTag), TEXT("Could not find the corresponding widget under the tag %s"), *WidgetTag.ToString());

	return FrontendDeveloperSettings->FrontendWidgetMap.FindRef(WidgetTag);
}
