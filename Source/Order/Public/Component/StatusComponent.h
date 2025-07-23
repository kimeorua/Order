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
	
public:
	FORCEINLINE FUnitStat GetUnitStat() const { return UnitStatus.UnitStat; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit | Status", meta = (AllowPrivateAccess = "true"))
	FUnitStatus UnitStatus;
};