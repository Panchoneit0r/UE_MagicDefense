// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemmieDummy.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class MAGICDEFENSE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AEnemmieDummy> EnemyClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float SpawnInterval;

	UPROPERTY(EditAnywhere, Category = "Horde")
	int HordeCount = 1;

	int MaxSpawnCount = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void PreparationForHorde();

	UFUNCTION()
	void StartNextHorde();

	UFUNCTION()
	void SpawnHorde();
	
	UFUNCTION()
	void EndHorde();

	int CurrentSpawnCount;
	
	FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Horde")
	bool HordeInProgress;  // Flag to control starting the next horde
	UPROPERTY(EditAnywhere, Category = "Horde")
	bool StartNextHordeFlag;  // Flag to control starting the next horde
	
	
	
	bool IsPressed(char key);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Handle the key press for starting the next horde
};




// "C:\Program Files\Epic Games\UE_5.2\Engine\Source\Runtime\Engine\Private\Character.cpp"