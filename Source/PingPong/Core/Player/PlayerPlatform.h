// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPlatform.generated.h"

enum class EColors : uint8;

UCLASS()
class PINGPONG_API APlayerPlatform : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPlatform();

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetVelocity(float Value);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void UpdateLocation(float DeltaTime);

	UPROPERTY(Replicated)
	float Velocity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};