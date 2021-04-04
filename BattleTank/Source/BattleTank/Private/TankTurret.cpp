// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::RotateTurret(float DegreesPerSecond) {
	auto RotationChange = DegreesPerSecond * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}