// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	float MyFloat = 6.66;

	UPROPERTY(EditAnywhere)
	bool MyBool = true;
	
	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(1,2,3);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(VisibleAnywhere, Category="Distance")
	float DistanceMoved = 1.0;
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MovedDistanceCheck = 100;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldPlatformReturn();
	float GetDistanceMoved();
};
