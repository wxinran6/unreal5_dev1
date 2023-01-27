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


	FString MyString = GetName();

	UE_LOG(LogTemp, Display, TEXT("Here's My String: %s"), *MyString);
	// UE_LOG(LogTemp, Display, TEXT("start game"));
	// UE_LOG(LogTemp, Warning, TEXT("configured move distance, %f"), MovedDistanceCheck);
	// UE_LOG(LogTemp, Error, TEXT("test error"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn()){
		float OverShoot = DistanceMoved - MovedDistanceCheck;
		FString MyString = GetName();
		// UE_LOG(LogTemp, Display, TEXT("Platform overshot by %f from actor %s"), OverShoot, *MyString);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection*MovedDistanceCheck;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{

		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{	
	UE_LOG(LogTemp, Display, TEXT("%s Rotating..."), *GetName());
	FRotator CurrentRotation = GetActorRotation();
	// CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	// SetActorRotation(CurrentRotation);
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MovedDistanceCheck;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}