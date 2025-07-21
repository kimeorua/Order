// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/StageSubsystem.h"
#include "Subsystem/UnitSubsystem.h"
#include "DebugHelper.h"

void UStageSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Debug::Print("Init Stage Subsystem");

	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UStageSubsystem::OnMapLoaded);
}

void UStageSubsystem::Deinitialize()
{
	FCoreUObjectDelegates::PostLoadMapWithWorld.RemoveAll(this);
}

void UStageSubsystem::OnMapLoaded(UWorld* LoadedWorld)
{
	StageStart();
}

void UStageSubsystem::StageStart()
{
	if (StageLevel < 5)
	{ 
		StageLevel++; 
		if (UUnitSubsystem* UnitSubsystem = GetGameInstance()->GetSubsystem<UUnitSubsystem>()) { UnitSubsystem->OnEnemySpawn.Broadcast(StageLevel); }
	}
}