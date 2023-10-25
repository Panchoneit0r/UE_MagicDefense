// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APawnTurret::APawnTurret()
{

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox);
	
	Golem = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Golem"));
	Golem->SetupAttachment(RootComponent);

	FirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompoent"));
	FirePoint->SetupAttachment(Golem);
	

	bReplicates = true;
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnTurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APawnTurret::SetDesiadia(float NewDesidia)
{
	Desidia = NewDesidia;
}

void APawnTurret::Attack()
{
	Golem->GetAnimInstance()->Montage_Play(AttackAnimation, 1.0f);

	UWorld* World = GetWorld();
	FVector spawnLocation = FirePoint->GetComponentLocation();
	FRotator spawnRotation =FirePoint->GetComponentRotation();

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = GetInstigator();
	spawnParameters.Owner = this;
	
	World->SpawnActor<ATurretProjectile>(ProjectileClass,spawnLocation, spawnRotation, spawnParameters );
	
}

void APawnTurret::Angry()
{
	Golem->GetAnimInstance()->Montage_Play(AttackAnimation, 1.0f);

	UWorld* World = GetWorld();
	FVector spawnLocation = FirePoint->GetComponentLocation();
	FRotator spawnRotation =FirePoint->GetComponentRotation();

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = GetInstigator();
	spawnParameters.Owner = this;
	
	World->SpawnActor<ATurretProjectile>(ProjectileClass,spawnLocation, spawnRotation, spawnParameters );
}

