// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/StageSubsystem.h"

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
	Debug::Print("Game Map Is Load");
	//TODO 스테이지 시작 구현 하기.
}