// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OrderBaseSubsystem.generated.h"

UCLASS(Abstract)
class ORDER_API UOrderBaseSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void OnPostWorldInit(UWorld* World, const UWorld::InitializationValues IVS);
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return GetClass() != StaticClass(); }
};
