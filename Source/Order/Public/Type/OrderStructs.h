// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Type/OrderEnums.h"
#include "OrderStructs.generated.h"


USTRUCT(BlueprintType)
struct FUnitStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,  BlueprintReadOnly)
	float HP = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHP = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AP = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ATK = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DEF = 100.0f;

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

	static  constexpr float LevelUpStat = 200.0f;

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