// Vince Petrelli All Rights Reserved


#include "Widgets/Widget_ConfirmScreen.h"
#include "CommonTextBlock.h"
#include "Components/DynamicEntryBox.h"
#include "Widgets/Components/FrontendButtonBase.h"
#include "ICommonInputModule.h"

UConfirmScreenInfoObject* UConfirmScreenInfoObject::CreateOkScreen(const FText& ScreenTitleToShow, const FText& ScreenMessageToShow)
{
    UConfirmScreenInfoObject* InfoObject = NewObject<UConfirmScreenInfoObject>();
    InfoObject->ScreenTitle = ScreenTitleToShow;
    InfoObject->ScreenMessage = ScreenMessageToShow;

    FConfirmScreenButtonInfo OkButtonInfo;
    OkButtonInfo.ConfirmScreenButtonType = EConfirmScreenButtonType::Closed;
    OkButtonInfo.ButtonTextToDisplay = FText::FromString(TEXT("Ok"));

    InfoObject->AvailableScreenButtons.Add(OkButtonInfo);

    return InfoObject;
}

UConfirmScreenInfoObject* UConfirmScreenInfoObject::CreateYesNoScreen(const FText& ScreenTitleToShow, const FText& ScreenMessageToShow)
{
    UConfirmScreenInfoObject* InfoObject = NewObject<UConfirmScreenInfoObject>();
    InfoObject->ScreenTitle = ScreenTitleToShow;
    InfoObject->ScreenMessage = ScreenMessageToShow;

    FConfirmScreenButtonInfo YesButtonInfo;
    YesButtonInfo.ConfirmScreenButtonType = EConfirmScreenButtonType::Confirmed;
    YesButtonInfo.ButtonTextToDisplay = FText::FromString(TEXT("Yes"));

    FConfirmScreenButtonInfo NoButtonInfo;
    NoButtonInfo.ConfirmScreenButtonType = EConfirmScreenButtonType::Cancelled;
    NoButtonInfo.ButtonTextToDisplay = FText::FromString(TEXT("No"));

    InfoObject->AvailableScreenButtons.Add(YesButtonInfo);
    InfoObject->AvailableScreenButtons.Add(NoButtonInfo);

    return InfoObject;
}

UConfirmScreenInfoObject* UConfirmScreenInfoObject::CreateOkCancelScreen(const FText& ScreenTitleToShow, const FText& ScreenMessageToShow)
{
    UConfirmScreenInfoObject* InfoObject = NewObject<UConfirmScreenInfoObject>();
    InfoObject->ScreenTitle = ScreenTitleToShow;
    InfoObject->ScreenMessage = ScreenMessageToShow;

    FConfirmScreenButtonInfo OkButtonInfo;
    OkButtonInfo.ConfirmScreenButtonType = EConfirmScreenButtonType::Confirmed;
    OkButtonInfo.ButtonTextToDisplay = FText::FromString(TEXT("Ok"));

    FConfirmScreenButtonInfo CancelButtonInfo;
    CancelButtonInfo.ConfirmScreenButtonType = EConfirmScreenButtonType::Cancelled;
    CancelButtonInfo.ButtonTextToDisplay = FText::FromString(TEXT("Cancel"));

    InfoObject->AvailableScreenButtons.Add(OkButtonInfo);
    InfoObject->AvailableScreenButtons.Add(CancelButtonInfo);

    return InfoObject;
}

void UWidget_ConfirmScreen::InitConfirmScreen(UConfirmScreenInfoObject* ScreenInfoObject, TFunction<void(EConfirmScreenButtonType)> ClickedButtonCallback)
{
    check(ScreenInfoObject && CommonTextBlock_Title && CommonTextBlock_Message && DynamicEntryBox_Buttons);

    CommonTextBlock_Title->SetText(ScreenInfoObject->ScreenTitle);
    CommonTextBlock_Message->SetText(ScreenInfoObject->ScreenMessage);

    //Checking if the entry box has old buttons created previously
    if (DynamicEntryBox_Buttons->GetNumEntries() != 0)
    {
        /*
        *   Clearing the old buttons the entry box has. The widget type for the entry box
        *   is specified in the child widget blueprint.
        */
        DynamicEntryBox_Buttons->Reset<UFrontendButtonBase>(
            [](UFrontendButtonBase& ExistingButton)
            {
                ExistingButton.OnClicked().Clear();
            }
        );
    }

    check(!ScreenInfoObject->AvailableScreenButtons.IsEmpty());

    for (const FConfirmScreenButtonInfo& AvailableButtonInfo : ScreenInfoObject->AvailableScreenButtons)
    {
        FDataTableRowHandle InputActionRowHandle;

        switch (AvailableButtonInfo.ConfirmScreenButtonType)
        {
        case EConfirmScreenButtonType::Confirmed:
            InputActionRowHandle = ICommonInputModule::GetSettings().GetDefaultClickAction();
            break;
        case EConfirmScreenButtonType::Cancelled:
            InputActionRowHandle = ICommonInputModule::GetSettings().GetDefaultBackAction();
            break;
        case EConfirmScreenButtonType::Closed:
            InputActionRowHandle = ICommonInputModule::GetSettings().GetDefaultBackAction();
            break;
        default:
            break;
        }

        UFrontendButtonBase* AddedButton = DynamicEntryBox_Buttons->CreateEntry<UFrontendButtonBase>();
        AddedButton->SetButtonText(AvailableButtonInfo.ButtonTextToDisplay);
        AddedButton->SetTriggeredInputAction(InputActionRowHandle);
        AddedButton->OnClicked().AddLambda(
            [ClickedButtonCallback, AvailableButtonInfo, this]()
            {
                ClickedButtonCallback(AvailableButtonInfo.ConfirmScreenButtonType);

                DeactivateWidget();
            }
        );

        if (DynamicEntryBox_Buttons->GetNumEntries() != 0)
        {
            DynamicEntryBox_Buttons->GetAllEntries().Last()->SetFocus();
        }
    }
}
