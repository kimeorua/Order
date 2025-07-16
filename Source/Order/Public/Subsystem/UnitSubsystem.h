// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/OrderBaseSubsystem.h"
#include "UnitSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class ORDER_API UUnitSubsystem : public UOrderBaseSubsystem
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float tset = 0.0f;
};
