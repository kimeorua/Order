// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/UnitSubsystem.h"
#include "OrderGameModeBase.h"
#include "Player/PlayerPawn.h"
#include "Unit/EnemyUnit.h"

#include "DebugHelper.h"

FEnemyUnitSpawnInfoTableRaw* UUnitSubsystem::GetCurrentStageSpanwerTableRow(int32 StageNum) const
{
	const FName RowName = FName(TEXT("Stage") + FString::FromInt(StageNum));
	FEnemyUnitSpawnInfoTableRaw* FoundRow = EnemySpawnerDataTable->FindRow<FEnemyUnitSpawnInfoTableRaw>(RowName, FString());

	if (!FoundRow) { return nullptr; }
	return FoundRow;
}

void UUnitSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Debug::Print("Init Unit Subsystem");

	OnEnemySpawn.AddDynamic(this, &UUnitSubsystem::SpawnEnemyUnit);
	OnShowUnitSelectUI.AddDynamic(this, &UUnitSubsystem::SelectedUnit);
}

void UUnitSubsystem::Deinitialize()
{
	OnEnemySpawn.RemoveAll(this);
	OnShowUnitSelectUI.RemoveAll(this);
}

void UUnitSubsystem::SpawnEnemyUnit(int32 StageLevel)
{
	for (const FEnemyUnitSpawnInfo& SpawnInfo : GetCurrentStageSpanwerTableRow(StageLevel)->EnemySpawnerInfo)
	{
		if (!SpawnInfo.EnemyUnitClass) { continue; }

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		for (int i = 0; i < SpawnInfo.SpawnedEnemyNum; i++)
		{
			AEnemyUnit* SpawnedEnemyUnit = GetWorld()->SpawnActor<AEnemyUnit>(SpawnInfo.EnemyUnitClass, SpawnInfo.SpawnLocation[i], FRotator::ZeroRotator, SpawnParams);
			if (SpawnedEnemyUnit)
			{
				FRotator Rot = FRotator(0.0f, -90.0f, 0.0f);
				SpawnedEnemyUnit->SetActorRotation(Rot);

				EnemyUnits.Add(SpawnedEnemyUnit);
			}
		}
	}
}

void UUnitSubsystem::SelectedUnit()
{
	CurrentSelectInfos.Empty();

	TArray<FPlayerUnitSelectInfo> TempPool = SelectInfos;

	for (int32 i = 0; i < 3 && TempPool.Num() > 0; ++i)
	{
		int32 RandIndex = FMath::RandRange(0, TempPool.Num() - 1);
		FPlayerUnitSelectInfo Picked = TempPool[RandIndex];
		CurrentSelectInfos.Add(Picked);
		TempPool.RemoveAt(RandIndex);
	}

	if (const UWorld* World = GetWorld())
	{
		if (APlayerController* PC = World->GetFirstPlayerController())
		{
			if (APlayerPawn* PlayerPawn = Cast<APlayerPawn>(PC->GetPawn()))
			{
				PlayerPawn->OnShowUnitSelectUI.Broadcast(CurrentSelectInfos[0], CurrentSelectInfos[1], CurrentSelectInfos[2]);
			}
		}
	}
}
