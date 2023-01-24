// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("start game"));
	UE_LOG(LogTemp, Warning, TEXT("configured move distance, %f"), MovedDistanceCheck);
	UE_LOG(LogTemp, Error, TEXT("test error"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved > MovedDistanceCheck ){
		float OverShoot = DistanceMoved - MovedDistanceCheck;
		UE_LOG(LogTemp, Display, TEXT("Platform overshot by %f"), OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection*MovedDistanceCheck;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}


}

