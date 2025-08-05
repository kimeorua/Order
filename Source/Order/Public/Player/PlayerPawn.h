// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Type/OrderStructs.h"
#include "PlayerPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnShowUnitSelectUI, FPlayerUnitSelectInfo, Unit_Info_1, FPlayerUnitSelectInfo, Unit_Info_2, FPlayerUnitSelectInfo, Unit_Info_3);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedAP, int32, CurrentAP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowBackButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShowPlayerUnitStatus, UTexture2D*, Icon, float, Percent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInitButtonIcon, UTexture2D*, SkillIcon, UTexture2D*, AttackIcon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCommand, ABaseUnit*, Unit);

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ORDER_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

	UPROPERTY(BlueprintAssignable)
	FOnShowUnitSelectUI OnShowUnitSelectUI;

	UPROPERTY(BlueprintAssignable)
	FOnChangedAP OnChangedAP;

	UPROPERTY(BlueprintAssignable)
	FOnShowBackButton OnShowBackButton;

	UPROPERTY(BlueprintAssignable)
	FOnShowPlayerUnitStatus OnShowPlayerUnitStatus;

	UPROPERTY(BlueprintAssignable)
	FOnInitButtonIcon OnInitButtonIcon;

	UPROPERTY(BlueprintAssignable)
	FOnCommand OnCommand;

protected:
	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
#pragma endregion

#pragma region Game
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AP", meta = (AllowPrivateAccess = "true"))
	int32 AP = 0;

	static constexpr int32 MaxAP = 10;
};