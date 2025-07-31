// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/OrderExtensionComponent.h"
#include "UIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChangeHP, float, Persent, int32, CurrentHP, int32, MaxHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowUnitStatusBar, float, Persent);

class UOrderUnitWidget;

UCLASS()
class ORDER_API UUIComponent : public UOrderExtensionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnChangeHP OnChangeHP;

	UPROPERTY(BlueprintAssignable)
	FOnShowUnitStatusBar OnShowUnitStatusBar;

	void ShowHoverUI();
	void RemoveHoverUI();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Unit | UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UOrderUnitWidget> HoverUIClass;

	UOrderUnitWidget* HoverUI = nullptr;
};
