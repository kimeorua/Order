// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OrderWidget.h"
#include "Player/PlayerPawn.h"
#include "Subsystem/StageSubsystem.h"

void UOrderWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (APlayerPawn* Pawn = Cast<APlayerPawn>(GetOwningPlayerPawn()))
	{
		BP_OnPlayerPawnInitalized(Pawn);
	}
}