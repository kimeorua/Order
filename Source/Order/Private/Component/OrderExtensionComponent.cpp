// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/OrderExtensionComponent.h"

UOrderExtensionComponent::UOrderExtensionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOrderExtensionComponent::BeginPlay()
{
	Super::BeginPlay();
}