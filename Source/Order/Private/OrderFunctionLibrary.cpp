// Fill out your copyright notice in the Description page of Project Settings.


#include "OrderFunctionLibrary.h"

void UOrderFunctionLibrary::ToggleInputMode(const UObject* WorldContextObject, EOrderInputMode InInputMode)
{
	APlayerController* PlayerController = nullptr;
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (World)
		{
			PlayerController = World->GetFirstPlayerController();
		}
	}
	if (!PlayerController) { return; }

	FInputModeGameOnly GameOnlyMode;
	GameOnlyMode.SetConsumeCaptureMouseDown(false);

	FInputModeUIOnly UIOnly;

	switch (InInputMode)
	{
	case EOrderInputMode::GameOnly:
		PlayerController->SetInputMode(GameOnlyMode);
		break;
	case EOrderInputMode::UIOnly:
		PlayerController->SetInputMode(UIOnly);
		break;
	default:
		break;
	}
}
