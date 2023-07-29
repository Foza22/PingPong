// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class APlayerPlatform;

UCLASS()
class PINGPONG_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void BeginPlay() override;

protected:
	void OnTriggerMove(float Value);

	UFUNCTION(Server, Unreliable)
	void UpdateVelocity(float UpdatedValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float Speed = 1000.f;
};
