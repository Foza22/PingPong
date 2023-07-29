// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"


class UTextBlock;

UCLASS()
class PINGPONG_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RedScoreTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BlueScoreTextBlock;
};
