// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StageSubsystem.generated.h"

UCLASS()
class ORDER_API UStageSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	int32 StageLevel = 0;

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION()
	void OnMapLoaded(UWorld* LoadedWorld);

	UFUNCTION(BlueprintCallable)
	void StageStart();
};
