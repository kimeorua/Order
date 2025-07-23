// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/OrderExtensionComponent.h"
#include "UIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChangeHP, float, Persent, int32, CurrentHP, int32, MaxHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChangeAP, float, Persent, float, CurrentAP, float, MaxAP);

UCLASS()
class ORDER_API UUIComponent : public UOrderExtensionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnChangeHP OnChangeHP;

	UPROPERTY(BlueprintAssignable)
	FOnChangeAP OnChangeAP;
};
