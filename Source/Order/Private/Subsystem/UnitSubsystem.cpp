// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/UnitSubsystem.h"
#include "OrderGameModeBase.h"

#include "DebugHelper.h"

void UUnitSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Debug::Print("Init Unit Subsystem");
}

void UUnitSubsystem::Deinitialize()
{
}