// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrderExtensionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ORDER_API UOrderExtensionComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	template<class T>
	T* GetOwningUnit() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AActor>::Value, "T Template Parmeter get  GetPawn must be derived form APawn");
		return CastChecked<T>(GetOwner());
	}
};
