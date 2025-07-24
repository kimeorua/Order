// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitWeapon.generated.h"

class UStaticMeshComponent;

UCLASS()
class ORDER_API AUnitWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitWeapon();

	FORCEINLINE UStaticMeshComponent* GetMesh() { return Mesh; }

private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
};
