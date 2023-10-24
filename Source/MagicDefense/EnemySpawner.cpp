// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include <Windows.h>



// Sets default values
AEnemySpawner::AEnemySpawner()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
	HordeInProgress = false;
	StartNextHordeFlag = false;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	PreparationForHorde();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AEnemySpawner::PreparationForHorde()
{
	CurrentSpawnCount = 0;
	//if (IsPressed('n'))
	//{
	StartNextHordeFlag = true;
	//}
	if (StartNextHordeFlag == true)
	{
		StartNextHorde();
	}
}

// Function to spawn enemies
void AEnemySpawner::StartNextHorde()
{
	HordeInProgress = true;
	StartNextHordeFlag = false;
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AEnemySpawner::SpawnHorde, SpawnInterval, true);
}


void AEnemySpawner::SpawnHorde()
{
	if (CurrentSpawnCount < MaxSpawnCount)
	{
		FString MyString = FString::Printf(TEXT("%i\n enemies Spawned "), CurrentSpawnCount);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, MyString);
		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();

		AEnemmieDummy* NewEnemy = GetWorld()->SpawnActor<AEnemmieDummy>(EnemyClass, SpawnLocation, SpawnRotation);
		
		if (NewEnemy)
		{
			CurrentSpawnCount++;
		}
	}
	else
	{
		EndHorde();
	}
}

void AEnemySpawner::EndHorde()
{
	HordeInProgress = false;
	FString MyString = FString::Printf(TEXT("End of Horde Number %i\n"), HordeCount);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, MyString);
	CurrentSpawnCount = 0;
	HordeCount ++;
	MaxSpawnCount = HordeCount * 3;
}



bool AEnemySpawner::IsPressed(char key)
{
	return GetAsyncKeyState(key) & 0x8000;
}
