// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/BaseUnit.h"
#include "Component/CombatComponent.h"
#include "Component/StatusComponent.h"
#include "Component/UIComponent.h"
#include "Components/CapsuleComponent.h"
#include "UI/OrderUnitWidget.h"
#include "Components/WidgetComponent.h"

#include "DebugHelper.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
	UIComponent = CreateDefaultSubobject<UUIComponent>(TEXT("UIComponent"));

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	UnitStatsBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("UnitStatsBar"));
	UnitStatsBar->SetupAttachment(GetMesh());
}

UCombatComponent* ABaseUnit::GetCombatComponent()
{
	return CombatComponent;
}

UStatusComponent* ABaseUnit::GetStatusComponent()
{
	return StatusComponent;
}

UUIComponent* ABaseUnit::GetUIComponent()
{
	return UIComponent;
}

void ABaseUnit::UnitMouseOver(UPrimitiveComponent* TouchedComp)
{
	GetMesh()->SetRenderCustomDepth(true);

	if (MainWeapon) 
	{
		MainWeapon->GetMesh()->SetRenderCustomDepth(true); 
		if (Team == EOrderTeamType::Player)
		{
			MainWeapon->GetMesh()->SetCustomDepthStencilValue(0);
		}
		else
		{
			MainWeapon->GetMesh()->SetCustomDepthStencilValue(1);
		}
	}
	if (SubWeapon) 
	{ 
		SubWeapon->GetMesh()->SetRenderCustomDepth(true);	
		if (Team == EOrderTeamType::Player)
		{
			SubWeapon->GetMesh()->SetCustomDepthStencilValue(0);
		}
		else
		{
			SubWeapon->GetMesh()->SetCustomDepthStencilValue(1);
		}
	}
}

void ABaseUnit::UnitMouseEnd(UPrimitiveComponent* TouchedComp)
{
	GetMesh()->SetRenderCustomDepth(false);

	if (MainWeapon) { MainWeapon->GetMesh()->SetRenderCustomDepth(false); }
	if (SubWeapon) { SubWeapon->GetMesh()->SetRenderCustomDepth(false); }
}

void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnBeginCursorOver.AddDynamic(this, &ABaseUnit::UnitMouseOver);
	GetCapsuleComponent()->OnEndCursorOver.AddDynamic(this, &ABaseUnit::UnitMouseEnd);

	if (UOrderUnitWidget* StatusWidget = Cast<UOrderUnitWidget>(UnitStatsBar->GetUserWidgetObject()))
	{
		StatusWidget->InitAndCreateUnitWidget(this);

		float HPPsersent = GetStatusComponent()->GetUnitStat().HP / GetStatusComponent()->GetUnitStat().MaxHP;
		float APPersent = GetStatusComponent()->GetUnitStat().AP / GetStatusComponent()->GetUnitStat().MaxAP;

		GetUIComponent()->OnChangeHP.Broadcast(HPPsersent, GetStatusComponent()->GetUnitStat().HP, GetStatusComponent()->GetUnitStat().MaxHP);
		GetUIComponent()->OnChangeAP.Broadcast(APPersent, GetStatusComponent()->GetUnitStat().AP, GetStatusComponent()->GetUnitStat().MaxAP);
	}

	MainWeapon = SpawnAndAttachWeapon(true);
	if (UnitWeaponInfo.bIsDual)
	{
		SubWeapon = SpawnAndAttachWeapon(false);
	}
}

AUnitWeapon* ABaseUnit::SpawnAndAttachWeapon(bool bIsMain)
{
	AUnitWeapon* Weapon = nullptr;

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if (bIsMain)
	{
		if (! UnitWeaponInfo.MainWeaponClass) { return nullptr; }
		Weapon = GetWorld()->SpawnActor<AUnitWeapon>(UnitWeaponInfo.MainWeaponClass, Parameters);
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, UnitWeaponInfo.MainEquipSocket);
	}
	else
	{
		if (!UnitWeaponInfo.SubWeaponClass) { return nullptr; }
		Weapon = GetWorld()->SpawnActor<AUnitWeapon>(UnitWeaponInfo.SubWeaponClass, Parameters);
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, UnitWeaponInfo.SubEquipSocket);
	}

	return Weapon;
}
