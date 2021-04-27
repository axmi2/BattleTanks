// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Tick tick tick"));
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	if (PlayerTank) {
		

		MoveToActor(PlayerTank,AcceptanceRadius);

		
		//Aim towards the player
		
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
		AimingComponent->Fire();


		//Fire when ready
	}
}