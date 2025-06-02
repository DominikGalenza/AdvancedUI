// Vince Petrelli All Rights Reserved


#include "Subsystems/FrontendUISubsystem.h"
#include "Engine/AssetManager.h"
#include "Widgets/Widget_PrimaryLayout.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widgets/Widget_ActivatableBase.h"
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

void UFrontendUISubsystem::PushSoftWidgetToStackAsync(const FGameplayTag& WidgetStackTag, TSoftClassPtr<UWidget_ActivatableBase> SoftWidgetClass, TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)> AsyncPushStateCallback)
{
    check(!SoftWidgetClass.IsNull());

    UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
        SoftWidgetClass.ToSoftObjectPath(),
        FStreamableDelegate::CreateLambda(
            [SoftWidgetClass, this, WidgetStackTag, AsyncPushStateCallback]()
            {
                UClass* LoadedWidgetClass = SoftWidgetClass.Get();
                check(LoadedWidgetClass && CreatedPrimaryLayout);

                UCommonActivatableWidgetContainerBase* FoundWidgetStack = CreatedPrimaryLayout->FindWidgetStackByTag(WidgetStackTag);  
                UWidget_ActivatableBase* CreatedWidget = FoundWidgetStack->AddWidget<UWidget_ActivatableBase>(
                    LoadedWidgetClass,
                    [AsyncPushStateCallback](UWidget_ActivatableBase& CreatedWidgetInstance)
                    {
                        AsyncPushStateCallback(EAsyncPushWidgetState::OnCreatedBeforePush, &CreatedWidgetInstance);
                    }
                );

                AsyncPushStateCallback(EAsyncPushWidgetState::AfterPush, CreatedWidget);
            }
        )
    );
}
