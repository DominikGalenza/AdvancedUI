// Vince Petrelli All Rights Reserved


#include "Widgets/Components/FrontendButtonBase.h"
#include "CommonTextBlock.h"

void UFrontendButtonBase::SetButtonText(FText Text)
{
	if (CommonTextBlock_ButtonText && !Text.IsEmpty())
	{
		CommonTextBlock_ButtonText->SetText(bUseUpperCaseForButtonText ? Text.ToUpper() : Text);
	}
}

void UFrontendButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	SetButtonText(ButtonDisplayText);
}
