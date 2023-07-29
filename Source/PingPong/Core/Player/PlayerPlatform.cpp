// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPlatform.h"

#include "Net/UnrealNetwork.h"

// Sets default values
APlayerPlatform::APlayerPlatform()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void APlayerPlatform::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Called when the game starts or when spawned
void APlayerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateLocation(DeltaTime);
}

void APlayerPlatform::SetVelocity(float Value)
{
	Velocity = Value;
}

void APlayerPlatform::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayerPlatform, Velocity);
}

void APlayerPlatform::UpdateLocation(float DeltaTime)
{
	FVector TargetLocation = GetActorLocation() + GetActorRightVector() * (Velocity * DeltaTime);
	SetActorLocation(TargetLocation, true);
}


