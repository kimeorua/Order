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

protected:
	virtual void BeginPlay() override;
};
