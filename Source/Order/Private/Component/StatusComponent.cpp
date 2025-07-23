// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/StatusComponent.h"

void UStatusComponent::BeginPlay()
{
	Super::BeginPlay();
	UnitStatus.UnitStat.Init();
}
