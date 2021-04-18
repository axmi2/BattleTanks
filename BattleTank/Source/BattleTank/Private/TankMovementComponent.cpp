// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	if (!LeftTrackToSet || !RightTrackToSet) {
		UE_LOG(LogTemp, Error, TEXT("Not tracks set"));
		return;
	}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {


	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

//Method for the AI Tanks to move. Uses Nav Mesh to navigate using A* Pathfinding
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

	
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	// Forward movement of the AI Tanks
	auto Forward_Throw=FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(Forward_Throw);

	auto Sideways_Throw = FVector::CrossProduct(TankForward, AIForwardIntention).Z;

	IntendTurnRight(Sideways_Throw);

	
}