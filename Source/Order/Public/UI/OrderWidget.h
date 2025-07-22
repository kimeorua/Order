// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OrderWidget.generated.h"

class APlayerPawn;

UCLASS()
class ORDER_API UOrderWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On PlayerPawn Setting"))
	void BP_OnPlayerPawnInitalized(APlayerPawn* Pawn);
};