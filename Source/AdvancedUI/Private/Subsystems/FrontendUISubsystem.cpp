// Vince Petrelli All Rights Reserved


#include "Subsystems/FrontendUISubsystem.h"
#include "FrontendDebugHelper.h"

UFrontendUISubsystem* UFrontendUISubsystem::Get(const UObject* WorldContextObject)
{
    if (GEngine)
    {
        UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);

        return UGameInstance::GetSubsystem<UFrontendUISubsystem>(World->GetGameInstance());
    }

    return nullptr;
}

bool UFrontendUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
    {
        TArray<UClass*> FoundClasses;
        GetDerivedClasses(GetClass(), FoundClasses);

        return FoundClasses.IsEmpty();
    }

    return false;
}

void UFrontendUISubsystem::RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* CreatedWidget)
{
    check(CreatedWidget);
    CreatedPrimaryLayout = CreatedWidget;

    Debug::Print(TEXT("Primary layout widget stored"));
}
