// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "GoalVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScored, EColors, ScoredToColor);

enum class EColors : uint8;

UCLASS()
class PINGPONG_API AGoalVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void AssignColor(EColors Color);

	FOnScored OnScored;

protected:
	EColors PlayerColor;
};
