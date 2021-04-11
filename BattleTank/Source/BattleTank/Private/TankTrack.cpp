// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) 
{
	auto Name = GetName();

	//Use throttle as accelaration and clamp for a top speed.
	

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxForce;
	auto ForceLocation = GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s track has Throttle %s"), *Name, *(ForceLocation).ToString());
	//auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}