// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Type/OrderEnums.h"
#include "Unit/PlayerUnit.h"
#include "OrderStructs.generated.h"

class AEnemyUnit;
class APlayerUnit;

USTRUCT(BlueprintType)
struct FUnitStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,  BlueprintReadOnly)
	int32 HP = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxHP = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AP = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ATK = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 DEF = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float APResilience = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CriticalChance = 30.0f;

	static  constexpr float MaxAP = 2.0f;

	void Init();
};

USTRUCT(BlueprintType)
struct FUnitLevelStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ATK_RiseRate = 0.5f;

	static  constexpr float MaxRiseRate = 1.0f;

	static  constexpr int32 LevelUpStat = 200;

	static  constexpr int32 MaxLevel = 5;
};

USTRUCT(BlueprintType)
struct FUnitStatus
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EOrderUnitType UnitType = EOrderUnitType::Tanker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUnitStat UnitStat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUnitLevelStat UnitLevelStat;
};

USTRUCT(BlueprintType)
struct FEnemyUnitSpawnInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemyUnit> EnemyUnitClass;

	UPROPERTY(EditAnywhere)
	TArray<FVector> SpawnLocation;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "3", UIMin = "0", UIMax = "3"))
	int32 SpawnedEnemyNum = 1;
};

USTRUCT(BlueprintType)
struct FEnemyUnitSpawnInfoTableRaw : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FEnemyUnitSpawnInfo>EnemySpawnerInfo;
};

USTRUCT(BlueprintType)
struct FPlayerUnitSelectInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* UnitIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APlayerUnit> PlayerUnitClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EOrderUnitType UnitType;

	bool operator==(const FPlayerUnitSelectInfo& Other) const
	{
		return UnitIcon == Other.UnitIcon && PlayerUnitClass == Other.PlayerUnitClass && UnitType == Other.UnitType;
	}
};