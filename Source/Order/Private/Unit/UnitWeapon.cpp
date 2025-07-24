// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/UnitWeapon.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AUnitWeapon::AUnitWeapon()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}