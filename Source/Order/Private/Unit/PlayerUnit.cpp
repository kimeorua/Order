// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/PlayerUnit.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Component/UIComponent.h"
#include "Component/StatusComponent.h"
#include "UI/OrderUnitWidget.h"
#include "Player/PlayerPawn.h"
#include "Component/CombatComponent.h"

#include "DebugHelper.h"

APlayerUnit::APlayerUnit()
{
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

	APlayerPawn* Pawn = Cast<APlayerPawn>(PC->GetPawn());

	float HPPsersent = GetStatusComponent()->GetUnitStat().HP / GetStatusComponent()->GetUnitStat().MaxHP;
	Pawn->OnShowPlayerUnitStatus.Broadcast(UnitIcon, HPPsersent);
	
	Pawn->OnInitButtonIcon.Broadcast(GetCombatComponent()->GetSkillIcon(), GetCombatComponent()->GetAttackIcon());
	Pawn->OnCommand.Broadcast(this);
}

void APlayerUnit::BeginPlay()
{
	Super::BeginPlay();
}