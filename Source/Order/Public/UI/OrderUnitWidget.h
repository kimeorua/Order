// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OrderUnitWidget.generated.h"

class UUIComponent;

UCLASS()
class ORDER_API UOrderUnitWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Unit UIComponent Initalized"))
	void BP_OnUnitUIComponentInitalized(UUIComponent* UnitUIComponent);

public:
	UFUNCTION(BlueprintCallable)
	void InitAndCreateUnitWidget(AActor* OwningActor);
};