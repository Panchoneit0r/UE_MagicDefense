// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretProjectile.h"

#include "EnemmieDummy.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATurretProjectile::ATurretProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Definition for the SphereComponent that will serve as the Root component for the projectile and its collision.
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	SphereComponent->InitSphereRadius(37.5f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapBegin);
	RootComponent = SphereComponent;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	//Definition for the Projectile Movement Component.
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->SetUpdatedComponent(SphereComponent);
	ProjectileMovementComponent->InitialSpeed = 1500.0f;
	ProjectileMovementComponent->MaxSpeed = 1500.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	DamageType = UDamageType::StaticClass();
	Damage = 100;
}

// Called when the game starts or when spawned
void ATurretProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATurretProjectile::Destroyed()
{
	FVector spawnLocation = GetActorLocation();

	
	if (ExplosionEffect != nullptr){
		UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
	}
	if(AOE != nullptr)
	{
		UWorld* World = GetWorld();
		FRotator spawnRotation = GetActorRotation();

		FActorSpawnParameters spawnParameters;
		spawnParameters.Instigator = GetInstigator();
		spawnParameters.Owner = this;
		
		World->SpawnActor<AActor>(AOE,spawnLocation, spawnRotation, spawnParameters );
	}
	//Super::Destroyed();
}

void ATurretProjectile::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEnemmieDummy* Enemy = Cast<AEnemmieDummy>(OtherActor);

	if(Enemy != nullptr)
	{
		Enemy->Damaged(Damage);
		Destroyed();
	}
}


// Called every frame
void ATurretProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

