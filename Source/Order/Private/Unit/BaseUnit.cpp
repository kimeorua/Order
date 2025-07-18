// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/BaseUnit.h"
#include "Component/CombatComponent.h"
#include "Component/StatusComponent.h"
#include "Component/UIComponent.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
	UIComponent = CreateDefaultSubobject<UUIComponent>(TEXT("UIComponent"));
}

UCombatComponent* ABaseUnit::GetCombatComponent()
{
	return CombatComponent;
}

UStatusComponent* ABaseUnit::GetStatusComponent()
{
	return StatusComponent;
}

UUIComponent* ABaseUnit::GetUIComponent()
{
	return UIComponent;
}

void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();
}
