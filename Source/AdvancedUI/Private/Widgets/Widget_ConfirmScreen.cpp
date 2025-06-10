// Vince Petrelli All Rights Reserved


#include "Widgets/Widget_ConfirmScreen.h"

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
