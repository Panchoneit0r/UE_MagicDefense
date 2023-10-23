// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretProjectile.generated.h"

UCLASS()
class MAGICDEFENSE_API ATurretProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sphere component used to test collision.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class USphereComponent* SphereComponent;

	// Static Mesh used to provide a visual representation of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UStaticMeshComponent* StaticMesh;

	// Movement component for handling projectile movement.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	// Particle used when the projectile impacts against another object and explodes.
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* ExplosionEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawner")
	TSubclassOf<AActor> AOE;

	//The damage type and damage that will be done by this projectile
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	TSubclassOf<class UDamageType> DamageType;

	//The damage dealt by this projectile.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")
	float Damage;
	// Sets default values for this actor's properties
	ATurretProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
