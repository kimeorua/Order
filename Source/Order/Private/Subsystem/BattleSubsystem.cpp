// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/BattleSubsystem.h"
#include "OrderFunctionLibrary.h"

#include "DebugHelper.h"

void UBattleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Debug::Print("Init Battle Subsystem");
}

void UBattleSubsystem::Deinitialize()
{
}

void UBattleSubsystem::ActivateCurrentTurn()
{
	switch (CurrentTurnType)
	{
	case EOrderTurnType::Begin :
		UOrderFunctionLibrary::ToggleMouseEvent(this, false);

		Debug::Print("Begin Turn Activate");

		break;
	case EOrderTurnType::Player:
		UOrderFunctionLibrary::ToggleMouseEvent(this, true);
		break;
	case EOrderTurnType::Enemy:
		break;
	case EOrderTurnType::Battle:
		break;
	case EOrderTurnType::End:
		break;
	default:
		break;
	}
}

void UBattleSubsystem::TurnChange(EOrderTurnType TurnType)
{
	CurrentTurnType = TurnType;

	ActivateCurrentTurn();
	OnChangeTurn.Broadcast(CurrentTurnType);
}
