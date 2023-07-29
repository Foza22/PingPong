// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "PlayerPlatform.h"
#include "Net/UnrealNetwork.h"

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &ABasePlayerController::OnTriggerMove);
}

void ABasePlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABasePlayerController, Speed)
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePlayerController::OnTriggerMove(float Value)
{
	UpdateVelocity(Speed * Value);
}

void ABasePlayerController::UpdateVelocity_Implementation(float UpdatedValue)
{
	if(APlayerPlatform* PlayerPawn = Cast<APlayerPlatform>(GetPawn()))
	{
		PlayerPawn->SetVelocity(UpdatedValue);
	}
}
