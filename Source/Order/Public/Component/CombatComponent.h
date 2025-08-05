// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/OrderExtensionComponent.h"
#include "CombatComponent.generated.h"

/**
 * 
 */
UCLASS()
class ORDER_API UCombatComponent : public UOrderExtensionComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Icon", meta = (AllowPrivateAccess = "true"))
	UTexture2D* SkillIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unit|Icon", meta = (AllowPrivateAccess = "true"))
	UTexture2D* AttackIcon;

public:
	UTexture2D* GetSkillIcon() const { return SkillIcon;}
	UTexture2D* GetAttackIcon() const { return AttackIcon; }
};
