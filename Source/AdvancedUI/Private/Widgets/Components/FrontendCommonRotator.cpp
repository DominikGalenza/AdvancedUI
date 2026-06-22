// Vince Petrelli All Rights Reserved


#include "Widgets/Components/FrontendCommonRotator.h"
#include "CommonTextBlock.h"

void UFrontendCommonRotator::SetSelectedOptionByText(const FText& TextOption)
{
	const int32 FoundIndex = TextLabels.IndexOfByPredicate(
		[TextOption](const FText& TextItem)->bool
		{
			return TextItem.EqualTo(TextOption);
		}
	);

	if (FoundIndex != INDEX_NONE)
	{
		SetSelectedItem(FoundIndex);
	}
	else
	{
		MyText->SetText(TextOption);
	}
}
