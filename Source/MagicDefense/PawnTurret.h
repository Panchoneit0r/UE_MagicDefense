// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretProjectile.h"
#include "GameFramework/Pawn.h"
#include "PawnTurret.generated.h"

UCLASS()
class MAGICDEFENSE_API APawnTurret : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Slot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

public:
	// Sets default values for this pawn's properties
	APawnTurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosas")
	float CostMoney;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawner")
	TSubclassOf<ATurretProjectile> ProjectileClass;

	TSubclassOf<class ATurretProjectile> GetTurret() const {return ProjectileClass;}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosas")
	float Desidia;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosas")
	bool used;

	
};
