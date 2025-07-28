// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"
#include "DebugHelper.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "OrderFunctionLibrary.h"

APlayerPawn::APlayerPawn()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	SetRootComponent(CameraBoom);
	CameraBoom->TargetArmLength = 200.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 55.0f, 65.0f);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	UOrderFunctionLibrary::ToggleInputMode(GetWorld(), EOrderInputMode::GameOnly);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		PlayerController->SetShowMouseCursor(true);
		PlayerController->bEnableMouseOverEvents = true;
		PlayerController->bEnableClickEvents = true;
	}

	AP = MaxAP;
	OnChangedAP.Broadcast(AP);
}
