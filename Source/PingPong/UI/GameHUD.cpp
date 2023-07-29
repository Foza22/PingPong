// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

#include "ScoreWidget.h"
#include "Blueprint/UserWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	ScoreWidget = CreateWidget<UScoreWidget>(GetOwningPlayerController(), ScoreWidgetClass);
	if(ScoreWidget)
	{
		ScoreWidget->AddToViewport();
	}
}