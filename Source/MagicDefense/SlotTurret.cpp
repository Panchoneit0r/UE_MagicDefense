// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotTurret.h"

#include "PawnTurret.h"
#include "PlayerMaster.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerState.h"

// Sets default values
ASlotTurret::ASlotTurret()
{
	
	Slot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SlotCompoent"));
	SetRootComponent(Slot);
	Slot->OnBeginCursorOver.AddDynamic(this,&ThisClass::OnBeginMouseOver);
	Slot->OnEndCursorOver.AddDynamic(this,&ThisClass::OnEndMouseOver);
	Slot->OnClicked.AddDynamic(this,&ThisClass::OnClickedMouse);

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseCompoent"));
	Base->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlotTurret::BeginPlay()
{
	Super::BeginPlay();

	DefaultMaterial = Slot->GetMaterial(0);
	
}

void ASlotTurret::OnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{

	if(Turret){
		return;
	}
	
	Slot->SetMaterial(0, OnMaterial);
}

void ASlotTurret::OnEndMouseOver(UPrimitiveComponent* TouchedComponent)
{
	if(Turret){
		return;
	}
	
	Slot->SetMaterial(0, DefaultMaterial);
}

void ASlotTurret::OnClickedMouse(UPrimitiveComponent* TouchedComponent, FKey ButtonPresed)
{
		UWorld* World = GetWorld();
		FVector spawnLocation = Base->GetComponentLocation();
		FRotator spawnRotation =Base->GetComponentRotation();

		FActorSpawnParameters spawnParameters;
		spawnParameters.Instigator = GetInstigator();
		spawnParameters.Owner = this;
	
		Turret = World->SpawnActor<APawnTurret>(GetMaster()->GetTurret(),spawnLocation, spawnRotation, spawnParameters );

		if( Turret->CostMoney > Master->Money )
		{
			Turret->Destroy();
			Turret = nullptr;
		}
		else
		{
			Master->Money -= Turret->CostMoney;
			Slot->SetMaterial(0, UsedMaterial);
			Used = true;
		}
	
/*
	if(Turret )
	{
		Master->Money -= Turret->CostMoney/2;
		Turret->SetDesiadia(0.0f);
	}
*/
	
}



// Called every frame
void ASlotTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlotTurret::SetMaster(APlayerMaster*  masterValue)
{
	Master = masterValue;
}

