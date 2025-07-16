// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"
#include "DebugHelper.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print("Player Pawn BeginPlay()");

	Debug::Print("Hi");
}
