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
	class USkeletalMeshComponent* Golem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* FirePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* AttackAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* AngryAtackAnimation;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Golem")
	float CostMoney;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Golem")
	TSubclassOf<ATurretProjectile> ProjectileClass;

	TSubclassOf<class ATurretProjectile> GetTurret() const {return ProjectileClass;}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Golem")
	float Desidia;

	/** Getter for Current Health.*/
	UFUNCTION(BlueprintPure, Category="Golem")
	FORCEINLINE float GetDesidia() const { return Desidia; }

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category="Golem")
	void SetDesiadia(float NewDesidia);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Golem")
	bool used;

	UFUNCTION(BlueprintCallable)
	void Attack();

	UFUNCTION(BlueprintCallable)
	void Angry();

	
};
