// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
//#include "Components/SceneComponent.h"
void UTankBarrel::Elevate(float DegreesPerSecond) {
	auto ElevationChange = DegreesPerSecond * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = FMath::Clamp(GetRelativeRotation().Pitch + ElevationChange, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}