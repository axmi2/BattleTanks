// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {



	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
		
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing %s"), *(ControlledTank->GetName()));
	}

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is: %s"), *(PlayerTank->GetName()));
	}


}