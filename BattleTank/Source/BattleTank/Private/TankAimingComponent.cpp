// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation) {
	auto Time = GetWorld()->GetTimeSeconds();
	if (!ensure(Barrel)) { return; }
	if (!ensure(Turret)) { return; }
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();
	FVector OutLaunchVelocity{ 0 };
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate out Launch Velocity
	bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
	
	}
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();

	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch); //Remove Magic Number

}

void UTankAimingComponent::MoveTurret(FVector AimDirection) {

	auto TurretRotator = Turret->GetForwardVector().Rotation();

	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	Turret->RotateTurret(DeltaRotator.Yaw);
	
}


void UTankAimingComponent::Initialise_Aiming(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet) {

	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::Fire() {


	if (!ensure(Barrel)) { return; }
	
	UE_LOG(LogTemp, Warning, TEXT("Called Fire"));
	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{


		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		if (!ensure(Projectile)) { return; }
		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = GetWorld()->GetTimeSeconds();
	}




}