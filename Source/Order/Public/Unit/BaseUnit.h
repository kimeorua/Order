// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseUnit.generated.h"

UCLASS()
class ORDER_API ABaseUnit : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseUnit();

protected:
	virtual void BeginPlay() override;
};
