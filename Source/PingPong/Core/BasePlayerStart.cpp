// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerStart.h"

#include "GoalVolume.h"

void ABasePlayerStart::BeginPlay()
{
	Super::BeginPlay();

	if(GoalVolume)
	{
		GoalVolume->AssignColor(PlayerColor);
	}
}
