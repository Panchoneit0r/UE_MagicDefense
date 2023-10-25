// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APawnTurret::APawnTurret()
{

	Golem = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Golem"));
	SetRootComponent(Golem);

	FirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompoent"));
	FirePoint->SetupAttachment(RootComponent);
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);

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
	
	//Golem()->Montage_Play(AttackAnimation, 1.0f);

	UWorld* World = GetWorld();
	FVector spawnLocation = FirePoint->GetComponentLocation();
	FRotator spawnRotation =FirePoint->GetComponentRotation();

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = GetInstigator();
	spawnParameters.Owner = this;
	
	World->SpawnActor<APawnTurret>(ProjectileClass,spawnLocation, spawnRotation, spawnParameters );
}

void APawnTurret::Angry()
{
	//Golem()->Montage_Play(AngryAnimation, 1.0f);
}

