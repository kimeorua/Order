// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/OrderBaseSubsystem.h"
#include "OrderGameModeBase.h"
#include "DebugHelper.h"

void UOrderBaseSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &UOrderBaseSubsystem::OnPostWorldInit);
}

void UOrderBaseSubsystem::Deinitialize()
{
}

void UOrderBaseSubsystem::OnPostWorldInit(UWorld* World, const UWorld::InitializationValues IVS)
{
	if (!World || !World->IsGameWorld()) { return; }

	TSubclassOf<AGameModeBase>GameModeClass = World->GetWorldSettings()->DefaultGameMode;

	if (GameModeClass->IsChildOf(AOrderGameModeBase::StaticClass())) 
	{
		Debug::Print("GameMode Is OrderGameModeBase Class");
	}
	else
	{ 
		Debug::Print("GameMode Is Not OrderGameModeBase Class");
	}
}