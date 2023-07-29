// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "BasePlayerStart.generated.h"

class ABasePlayerController;
enum class EColors : uint8;
class AGoalVolume;

UCLASS()
class PINGPONG_API ABasePlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AGoalVolume* GoalVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColors PlayerColor;
};
