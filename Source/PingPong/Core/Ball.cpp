// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "Components/SphereComponent.h"
#include "Engine/TriggerVolume.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	MakeVelocity();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveBall(DeltaTime);
}

void ABall::MoveBall(float DeltaSeconds)
{
	AddActorWorldOffset(DeltaSeconds * Speed * Velocity);

	const FVector TraceStart = GetActorLocation();
	const FVector TraceEnd = TraceStart + Velocity * Collision->GetUnscaledSphereRadius();

	FHitResult Hit;
	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility);

	if (!Hit.bBlockingHit)
	{
		return;
	}

	FVector TargetVector = UKismetMathLibrary::MirrorVectorByNormal(Velocity, Hit.ImpactNormal);
	TargetVector.Z = Velocity.Z;
	Velocity = TargetVector;
}

void ABall::MakeVelocity()
{
	Velocity.X = FMath::RandBool() ? 1.f : -1.f;
	Velocity.Y = FMath::RandBool() ? 1.f : -1.f;
}
