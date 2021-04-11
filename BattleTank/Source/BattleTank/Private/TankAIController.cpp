// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Tick tick tick"));
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank) {
		//TO Move towards the player

		
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		
		//ControlledTank->Fire();


		//Fire when ready
	}
}