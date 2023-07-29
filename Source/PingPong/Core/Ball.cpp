// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "GoalVolume.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Utils.h"

// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

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
	
	InitialLocation = GetActorLocation();

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGoalVolume::StaticClass(), OutActors);
	for(AActor* Actor : OutActors)
	{
		AGoalVolume* GoalVolume = Cast<AGoalVolume>(Actor);
		if(GoalVolume)
		{
			GoalVolume->OnScored.AddDynamic(this, &ABall::ScoreGoal);
		}
	}
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveBall(DeltaTime);
}

void ABall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABall, Velocity);
}

void ABall::ScoreGoal(EColors Color)
{
	Reactivate(false);
}

void ABall::Reactivate(bool bInstant)
{
	SetActorLocation(InitialLocation);
	Velocity = FVector::ZeroVector;

	float Delay = bInstant ? 0.1f : TimeToReactivate;
	
	GetWorldTimerManager().SetTimer(FReactivateBallTimerHandle, this, &ABall::MakeVelocity, Delay, false);
}

void ABall::MoveBall(float DeltaSeconds)
{
	FVector TargetLocation = GetActorLocation() + DeltaSeconds * Speed * Velocity;
	SetActorLocation(TargetLocation, true);

	FHitResult Hit;
	const FVector TraceStart = GetActorLocation();
	const FVector TraceEnd = TraceStart + Velocity * Collision->GetUnscaledSphereRadius();
	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility);
	
	if (Hit.bBlockingHit)
	{
		FVector TargetVector = UKismetMathLibrary::MirrorVectorByNormal(Velocity, Hit.ImpactNormal);
		TargetVector.Z = Velocity.Z;
		Velocity = TargetVector;
	}
}

void ABall::MakeVelocity()
{
	Velocity.X = FMath::RandBool() ? 1.f : -1.f;
	Velocity.Y = FMath::RandBool() ? 1.f : -1.f;
}
