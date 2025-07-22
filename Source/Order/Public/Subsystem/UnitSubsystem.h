// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Type/OrderStructs.h"
#include "UnitSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemySpawn, int32, StageLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowUnitSelectedUI);

class ABaseUnit;

UCLASS(Abstract, Blueprintable)
class ORDER_API UUnitSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
private:
#pragma region EnemySpawn
	UPROPERTY(EditDefaultsOnly, Category = "Unit | Enemy Spawn DataTable", meta = (AllowPrivateAccess = "true"))
	UDataTable* EnemySpawnerDataTable = nullptr;

	FEnemyUnitSpawnInfoTableRaw* GetCurrentStageSpanwerTableRow(int32 StageNum) const;

	UFUNCTION()
	void SpawnEnemyUnit(int32 StageLevel);
#pragma endregion

#pragma region PlayerSpawn
	UPROPERTY(EditDefaultsOnly, Category = "Unit | Player Spawn", meta = (AllowPrivateAccess = "true"))
	TArray<FPlayerUnitSelectInfo> SelectInfos;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<FPlayerUnitSelectInfo> CurrentSelectInfos;

	UFUNCTION()
	void SelectedUnit();

#pragma endregion

#pragma region Unit Mangement
	UPROPERTY(VisibleAnywhere, Category = "Unit | Mangement")
	TArray<ABaseUnit*>EnemyUnits;
#pragma endregion

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	FOnEnemySpawn OnEnemySpawn;
	FOnShowUnitSelectedUI OnShowUnitSelectUI;
};
