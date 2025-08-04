// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/CombatInterface.h"
#include "Interface/UIInterface.h"
#include "Interface/StatusInterface.h"
#include "Type/OrderEnums.h"
#include "Unit/UnitWeapon.h"
#include "BaseUnit.generated.h"

class UCombatComponent;
class UStatusComponent;
class UUIComponent;
class AUnitWeapon;
class USpringArmComponent;
class UCameraComponent;


USTRUCT(BlueprintType)
struct FUnitWeaponInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsDual = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AUnitWeapon>MainWeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName MainEquipSocket = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "bIsDual == true"))
	TSubclassOf<AUnitWeapon>SubWeaponClass;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bIsDual == true"))
	FName SubEquipSocket = "";
};

UCLASS()
class ORDER_API ABaseUnit : public ACharacter, public ICombatInterface, public IStatusInterface, public IUIInterface
{
	GENERATED_BODY()

public:
	ABaseUnit();

	//~ Begin ICombatInterface
	virtual UCombatComponent* GetCombatComponent() override;
	//~  End ICombatInterface

	//~ Begin IStatusInterface
	virtual UStatusComponent* GetStatusComponent() override;
	// ~~End IStatusInterface

	//~ Begin IUIInterface
	virtual UUIComponent* GetUIComponent() override;
	//~ End IUIInterface

	UFUNCTION()
	virtual void UnitMouseOver(UPrimitiveComponent* TouchedComp);

	UFUNCTION()
	virtual void UnitMouseEnd(UPrimitiveComponent* TouchedComp);

	UFUNCTION()
	virtual void UnitClick(AActor* TouchedActor, FKey ButtonPressed);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Icon", meta = (AllowPrivateAccess = "true"))
	UTexture2D* UnitIcon;

private:

#pragma region Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Component", meta = (AllowPrivateAccess = "true"))
	UCombatComponent* CombatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Component", meta = (AllowPrivateAccess = "true"))
	UStatusComponent* StatusComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Component", meta = (AllowPrivateAccess = "true"))
	UUIComponent* UIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
#pragma endregion

#pragma region Weapon
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Weapon", meta = (AllowPrivateAccess = "true"))
	FUnitWeaponInfo UnitWeaponInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Weapon", meta = (AllowPrivateAccess = "true"))
	AUnitWeapon* MainWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Weapon", meta = (AllowPrivateAccess = "true"))
	AUnitWeapon* SubWeapon;

	AUnitWeapon* SpawnAndAttachWeapon(bool bIsMain = false);
#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|TeamType", meta = (AllowPrivateAccess = "true"))
	EOrderTeamType Team = EOrderTeamType::Player;
};