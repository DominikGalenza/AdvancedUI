// Vince Petrelli All Rights Reserved


#include "Widgets/Components/FrontendTabListWidgetBase.h"
#include "Editor/WidgetCompilerLog.h"
#include "Widgets/Components/FrontendButtonBase.h"

#if WITH_EDITOR	
void UFrontendTabListWidgetBase::ValidateCompiledDefaults(IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (!TabButtonEntryWidgetClass)
	{
		CompileLog.Error(FText::FromString(
			TEXT("The variable TabButtonEntryWidgetClass has no valid entry specified. ") +
			GetClass()->GetName() +
			TEXT(" needs a valid entry widget class to function properly.")
		));
	}
}
#endif