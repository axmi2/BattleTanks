// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void RotateTurret(float DegreesPerSecond);
	

private:
	UPROPERTY(EditDefaultsOnly, Category = SETUP)
		float MaxDegreesPerSecond = 4.; // Sensible max value
};
