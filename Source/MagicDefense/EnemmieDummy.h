// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemmieDummy.generated.h"

UCLASS()
class MAGICDEFENSE_API AEnemmieDummy : public ACharacter
{
	GENERATED_BODY()

public:
	/** Property replication */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// Sets default values for this actor's properties
	AEnemmieDummy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** RepNotify for changes made to current health.*/
	UFUNCTION()
	void OnRep_CurrentHealth();
	/** Response to health being updated. Called on the server immediately after modification, and on clients in response to a RepNotify*/
	void OnHealthUpdate();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth)
	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth;

	/** Getter for Max Health.*/
	UFUNCTION(BlueprintPure, Category="Health")
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; } 
    
	/** Getter for Current Health.*/
	UFUNCTION(BlueprintPure, Category="Health")
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category="Health")
	void SetCurrentHealth(float healthValue);

	/** Event for taking damage. Overridden from APawn.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
	float Damaged( float DamageTaken) ;

};