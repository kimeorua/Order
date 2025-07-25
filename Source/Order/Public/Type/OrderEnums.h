// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class EOrderInputMode : uint8
{
	GameOnly,
	UIOnly
};

UENUM(BlueprintType)
enum class EOrderTeamType : uint8
{
	Player UMETA(DisplayName = "Player"),
	Enemy UMETA(DisplayName = "Enemy")
};

UENUM(BlueprintType)
enum class EOrderUnitType : uint8
{
	Buffer UMETA(DisplayName = "Buffer"),
	Dealer UMETA(DisplayName = "Dealer"),
	Mage UMETA(DisplayName = "Mage")
};
