// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/PlayerUnit.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Component/UIComponent.h"
#include "Component/StatusComponent.h"
#include "UI/OrderUnitWidget.h"

#include "DebugHelper.h"

APlayerUnit::APlayerUnit()
{
	StatusWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("StatusWidget"));
	StatusWidget->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("HP_UI_Socket"));
}

void APlayerUnit::ShowUnitClickUI()
{
	float HPPsersent = GetStatusComponent()->GetUnitStat().HP / GetStatusComponent()->GetUnitStat().MaxHP;
	GetUIComponent()->OnShowUnitStatusBar.Broadcast(HPPsersent);
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

	ShowUnitClickUI();
}

void APlayerUnit::BeginPlay()
{
	Super::BeginPlay();

	if (UOrderUnitWidget* UnitUI = Cast<UOrderUnitWidget>(StatusWidget->GetUserWidgetObject())) { UnitUI->InitAndCreateUnitWidget(this); }
}