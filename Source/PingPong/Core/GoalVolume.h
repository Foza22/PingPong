// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "GoalVolume.generated.h"

UENUM(BlueprintType)
enum class EColors
{
	BLUE	UMETA(DisplayName = "Blue"),
	RED		UMETA(DisplayName = "Red")
};

UCLASS()
class PINGPONG_API AGoalVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColors PlayerColor;
};
