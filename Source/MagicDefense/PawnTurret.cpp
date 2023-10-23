// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Components/BoxComponent.h"

// Sets default values
APawnTurret::APawnTurret()
{

	Slot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SlotCompoent"));
	SetRootComponent(Slot);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);
	
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

