// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/BaseUnit.h"
#include "Component/CombatComponent.h"
#include "Component/StatusComponent.h"
#include "Component/UIComponent.h"
#include "Components/CapsuleComponent.h"
#include "UI/OrderUnitWidget.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "OrderFunctionLibrary.h"
#include "Player/PlayerPawn.h"

#include "DebugHelper.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
	UIComponent = CreateDefaultSubobject<UUIComponent>(TEXT("UIComponent"));

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 130.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 120.0f, 80.0f);
	CameraBoom->SetupAttachment(GetRootComponent());

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
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
	GetUIComponent()->ShowHoverUI();
	float HPPsersent = GetStatusComponent()->GetUnitStat().HP / GetStatusComponent()->GetUnitStat().MaxHP;
	GetUIComponent()->OnChangeHP.Broadcast(HPPsersent, GetStatusComponent()->GetUnitStat().HP, GetStatusComponent()->GetUnitStat().MaxHP);
}

void ABaseUnit::UnitMouseEnd(UPrimitiveComponent* TouchedComp)
{
	GetMesh()->SetRenderCustomDepth(false);

	if (MainWeapon) { MainWeapon->GetMesh()->SetRenderCustomDepth(false); }
	if (SubWeapon) { SubWeapon->GetMesh()->SetRenderCustomDepth(false); }

	GetUIComponent()->RemoveHoverUI();
}

void ABaseUnit::UnitClick(AActor* TouchedActor, FKey ButtonPressed)
{
	UOrderFunctionLibrary::ToggleInputMode(this, EOrderInputMode::UIOnly);

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	APlayerPawn* Pawn = Cast<APlayerPawn>(PC->GetPawn());
	Pawn->OnShowBackButton.Broadcast();

	GetMesh()->SetRenderCustomDepth(false);

	if (MainWeapon) { MainWeapon->GetMesh()->SetRenderCustomDepth(false); }
	if (SubWeapon) { SubWeapon->GetMesh()->SetRenderCustomDepth(false); }

	GetUIComponent()->RemoveHoverUI();

	UOrderFunctionLibrary::ToggleMouseEvent(this, false);
}

void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();

	OnClicked.AddDynamic(this, &ABaseUnit::UnitClick);
	GetCapsuleComponent()->OnBeginCursorOver.AddDynamic(this, &ABaseUnit::UnitMouseOver);
	GetCapsuleComponent()->OnEndCursorOver.AddDynamic(this, &ABaseUnit::UnitMouseEnd);

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
