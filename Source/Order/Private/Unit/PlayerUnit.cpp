// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/PlayerUnit.h"
#include "Components/CapsuleComponent.h"

#include "DebugHelper.h"

void APlayerUnit::BeginPlay()
{
	Super::BeginPlay();
}
void APlayerUnit::UnitMouseOver(UPrimitiveComponent* TouchedComp)
{
	Super::UnitMouseOver(TouchedComp);
	GetMesh()->SetCustomDepthStencilValue(0);
}

void APlayerUnit::UnitClick(AActor* TouchedActor, FKey ButtonPressed)
{
	Super::UnitClick(TouchedActor, ButtonPressed);

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	PC->SetViewTargetWithBlend(this, 0.45f);

	FTimerHandle BlendFinishTimer;
	GetWorld()->GetTimerManager().SetTimer(BlendFinishTimer, this, &APlayerUnit::ShowUnitUI, 0.45f, false);

}