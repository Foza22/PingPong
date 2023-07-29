// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"

#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "PingPong/Core/GoalVolume.h"
#include "PingPong/Core/Utils.h"

void UScoreWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGoalVolume::StaticClass(), OutActors);
	for(AActor* Actor : OutActors)
	{
		AGoalVolume* GoalVolume = Cast<AGoalVolume>(Actor);
		if(GoalVolume)
		{
			GoalVolume->OnScored.AddDynamic(this, &UScoreWidget::ScoreGoal);
		}
	}
}

void UScoreWidget::ScoreGoal(EColors Color)
{
	if(Color == EColors::RED)
	{
		BlueScoreTextBlock->SetText(FText::AsNumber(++BlueScored));
	}
	else if(Color == EColors::BLUE)
	{
		RedScoreTextBlock->SetText(FText::AsNumber(++RedScored));
	}
}
