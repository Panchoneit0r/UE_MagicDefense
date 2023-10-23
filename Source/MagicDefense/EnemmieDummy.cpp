// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemmieDummy.h"

#include "Net/UnrealNetwork.h"


void AEnemmieDummy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//Replicate current health.
	DOREPLIFETIME(AEnemmieDummy, CurrentHealth);
}

void AEnemmieDummy::OnRep_CurrentHealth()
{
	OnHealthUpdate();
}
 
 void AEnemmieDummy::OnHealthUpdate()
{
	//Client-specific functionality
	if (IsLocallyControlled())
	{
		FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), CurrentHealth);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

		if (CurrentHealth <= 0)
		{
			FString deathMessage = FString::Printf(TEXT("You have been killed."));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);

		}
	}

	//Server-specific functionality
	if (GetLocalRole() == ROLE_Authority)
	{
		FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), CurrentHealth);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);
	}
	if (CurrentHealth <= 0)
	{
	 Destroy();
	}
}

// Sets default values
AEnemmieDummy::AEnemmieDummy()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

// Called when the game starts or when spawned
void AEnemmieDummy::BeginPlay()
{
	Super::BeginPlay();
	
}



void AEnemmieDummy::SetCurrentHealth(float healthValue)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		CurrentHealth = FMath::Clamp(healthValue, 0.f, MaxHealth);
		OnHealthUpdate();
	}
}

float AEnemmieDummy::Damaged(float DamageTaken)
{
	//return Super::TakeDamage(DamageTaken, DamageEvent, EventInstigator, DamageCauser);
	float damageApplied = CurrentHealth - DamageTaken;
	SetCurrentHealth(damageApplied);
	return damageApplied;
}

// Called every frame
void AEnemmieDummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

