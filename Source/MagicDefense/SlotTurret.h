// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "SlotTurret.generated.h"

UCLASS()
class MAGICDEFENSE_API ASlotTurret : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Slot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Materials, meta = (AllowPrivateAccess = "true"))
	class UMaterialInterface* OnMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Materials, meta = (AllowPrivateAccess = "true"))
	class UMaterialInterface* UsedMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Materials, meta = (AllowPrivateAccess = "true"))
	class UMaterialInterface* DefaultMaterial;
	
public:	
	// Sets default values for this actor's properties
	ASlotTurret();

	bool Used = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginMouseOver(UPrimitiveComponent* TouchedComponent);
	
	UFUNCTION()
	void OnEndMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void OnClickedMouse(UPrimitiveComponent* TouchedComponent, FKey ButtonPresed);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,  meta = (AllowPrivateAccess = "true"))
	class APlayerMaster* Master;

	UFUNCTION(BlueprintPure, Category="Master")
	FORCEINLINE APlayerMaster* GetMaster() const{return Master;}

	UFUNCTION(BlueprintCallable, Category="Master")
	void SetMaster(APlayerMaster* masterValue);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,  meta = (AllowPrivateAccess = "true"))
	class APawnTurret* Turret;

	UFUNCTION(BlueprintCallable, Category="Master")
	void Recharge();
};



