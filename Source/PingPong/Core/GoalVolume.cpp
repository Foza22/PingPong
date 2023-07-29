// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalVolume.h"

#include "Ball.h"

void AGoalVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->IsA(ABall::StaticClass()))
	{
		switch (PlayerColor)
		{
		case EColors::RED:
			
			break;
		case EColors::BLUE:
			
			break;
		default:
			break;
		}
	}
}
