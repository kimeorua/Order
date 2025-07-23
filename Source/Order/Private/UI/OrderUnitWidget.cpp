// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OrderUnitWidget.h"
#include "Interface/UIInterface.h"

void UOrderUnitWidget::InitAndCreateUnitWidget(AActor* OwningActor)
{
	if (IUIInterface* UnitUIInterface = Cast<IUIInterface>(OwningActor))
	{
		UUIComponent* UnitUIComponent = UnitUIInterface->GetUIComponent();

		BP_OnUnitUIComponentInitalized(UnitUIComponent);
	}
}