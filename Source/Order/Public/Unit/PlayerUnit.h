// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit/BaseUnit.h"
#include "PlayerUnit.generated.h"

/**
 * 
 */
UCLASS()
class ORDER_API APlayerUnit : public ABaseUnit
{
	GENERATED_BODY()

public:
	virtual void UnitMouseOver(UPrimitiveComponent* TouchedComp) override;
	virtual void UnitClick(AActor* TouchedActor, FKey ButtonPressed) override;
protected:
	virtual void BeginPlay() override;
};
