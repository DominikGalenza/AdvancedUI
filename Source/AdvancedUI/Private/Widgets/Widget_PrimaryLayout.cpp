// Vince Petrelli All Rights Reserved


#include "Widgets/Widget_PrimaryLayout.h"
#include "FrontendDebugHelper.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& Tag) const
{
	checkf(RegisteredWidgetStackMap.Contains(Tag), TEXT("Can not find the widget stack by the tag %s"), *Tag.ToString());

	return RegisteredWidgetStackMap.FindRef(Tag);
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag StackTag, UCommonActivatableWidgetContainerBase* Stack)
{
	if (!IsDesignTime())
	{
		if (!RegisteredWidgetStackMap.Contains(StackTag))
		{
			RegisteredWidgetStackMap.Add(StackTag, Stack);

			Debug::Print(TEXT("Widget stack registered under the tag ") + StackTag.ToString());
		}
	}
}
