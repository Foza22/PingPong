// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"


enum class EColors : uint8;
class UTextBlock;

UCLASS()
class PINGPONG_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeOnInitialized() override;

	UFUNCTION()
	void ScoreGoal(EColors Color);
	
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RedScoreTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BlueScoreTextBlock;

private:
	int32 RedScored = 0;
	int32 BlueScored = 0;
};
