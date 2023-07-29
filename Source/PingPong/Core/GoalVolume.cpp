// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalVolume.h"

#include "Ball.h"
#include "Utils.h"

void AGoalVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (ABall* Ball = Cast<ABall>(OtherActor))
	{
		OnScored.Broadcast(PlayerColor);
	}
}

void AGoalVolume::AssignColor(EColors Color)
{
	PlayerColor = Color;
}
