// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/BaseUnit.h"
#include "Component/CombatComponent.h"
#include "Component/StatusComponent.h"
#include "Component/UIComponent.h"
#include "Components/CapsuleComponent.h"


#include "DebugHelper.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
	UIComponent = CreateDefaultSubobject<UUIComponent>(TEXT("UIComponent"));

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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

void ABaseUnit::UnitMouseOver(UPrimitiveComponent* TouchedComp)
{
	GetMesh()->SetRenderCustomDepth(true);
}

void ABaseUnit::UnitMouseEnd(UPrimitiveComponent* TouchedComp)
{
	GetMesh()->SetRenderCustomDepth(false);
}

void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnBeginCursorOver.AddDynamic(this, &ABaseUnit::UnitMouseOver);
	GetCapsuleComponent()->OnEndCursorOver.AddDynamic(this, &ABaseUnit::UnitMouseEnd);
}