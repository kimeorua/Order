// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/CombatInterface.h"
#include "Interface/UIInterface.h"
#include "Interface/StatusInterface.h"
#include "Type/OrderEnums.h"
#include "BaseUnit.generated.h"

class UCombatComponent;
class UStatusComponent;
class UUIComponent;

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

protected:
	virtual void BeginPlay() override;

private:

#pragma region Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Component", meta = (AllowPrivateAccess = "true"))
	UCombatComponent* CombatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Component", meta = (AllowPrivateAccess = "true"))
	UStatusComponent* StatusComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Component", meta = (AllowPrivateAccess = "true"))
	UUIComponent* UIComponent;
#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|TeamType", meta = (AllowPrivateAccess = "true"))
	EOrderTeamType Team = EOrderTeamType::Player;
};