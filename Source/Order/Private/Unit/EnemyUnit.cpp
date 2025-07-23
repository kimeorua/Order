// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/EnemyUnit.h"
#include "Components/CapsuleComponent.h"

void AEnemyUnit::BeginPlay()
{
	Super::BeginPlay();
}
void AEnemyUnit::UnitMouseOver(UPrimitiveComponent* TouchedComp)
{
	Super::UnitMouseOver(TouchedComp);
	GetMesh()->SetCustomDepthStencilValue(1);
}