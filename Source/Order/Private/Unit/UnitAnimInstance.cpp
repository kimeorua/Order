// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/UnitAnimInstance.h"
#include "Unit/BaseUnit.h"

void UUnitAnimInstance::NativeInitializeAnimation()
{
	OwningUnit = Cast<ABaseUnit>(TryGetPawnOwner());
}

void UUnitAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningUnit) { return; }
}
