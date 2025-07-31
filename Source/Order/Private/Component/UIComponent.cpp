// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UIComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/OrderUnitWidget.h"
#include "Unit/BaseUnit.h"

#include "DebugHelper.h"

void UUIComponent::ShowHoverUI()
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		float MouseX, MouseY;
		if (PC->GetMousePosition(MouseX, MouseY))
		{
			if (HoverUIClass)
			{
				HoverUI = CreateWidget<UOrderUnitWidget>(PC, HoverUIClass);
				if (HoverUI)
				{
					HoverUI->InitAndCreateUnitWidget(GetOwningUnit());
					HoverUI->AddToViewport();
				}
			}
			if (HoverUI)
			{
				HoverUI->SetPositionInViewport(FVector2D(MouseX, MouseY), true);
			}
		}
	}
}

void UUIComponent::RemoveHoverUI()
{
	if (HoverUI)
	{
		HoverUI->RemoveFromParent();
		HoverUI = nullptr;
	}
}