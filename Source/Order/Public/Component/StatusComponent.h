// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/OrderExtensionComponent.h"
#include "Type/OrderStructs.h"
#include "StatusComponent.generated.h"

UCLASS()
class ORDER_API UStatusComponent : public UOrderExtensionComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit | Status", meta = (AllowPrivateAccess = "true"))
	FUnitStatus UnitStatus;
};
