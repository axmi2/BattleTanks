// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
// Holds the Barrel properties and elevate method
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	


public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditDefaultsOnly, Category= "Setup")
	float MaxDegreesPerSecond = 10.; // Sensible max value
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevation = 20.; //Sensible Max Value
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevation = -2.; //Sensible Min Value to prevent self collision
};
