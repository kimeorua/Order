// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Type/OrderEnums.h"
#include "BattleSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeTurn, EOrderTurnType, CurrentTurn);

class ABaseUnit;

UENUM(BlueprintType)
enum class EOrderCommandType : uint8
{
	Attack UMETA(DisplayName = "Attack"),
	Skill UMETA(DisplayName = "Skill")
};

USTRUCT(BlueprintType)
struct FUnitBattleCommand
{
	GENERATED_BODY()

	ABaseUnit* Unit;
	EOrderCommandType CommandType = EOrderCommandType::Attack;
};


UCLASS()
class ORDER_API UBattleSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	void TurnChange(EOrderTurnType TurnType);

	UPROPERTY(BlueprintAssignable)
	FOnChangeTurn OnChangeTurn;

	UFUNCTION(BlueprintCallable)
	void AddUnitSequence(ABaseUnit* Unit, EOrderCommandType CommandType);

private:
	UPROPERTY()
	EOrderTurnType CurrentTurnType = EOrderTurnType::None;

	void ActivateCurrentTurn();

	UPROPERTY()
	TArray<FUnitBattleCommand>UnitBattleSequence;
};
