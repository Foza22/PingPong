// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

class UScoreWidget;
enum class EColors : uint8;

UCLASS()
class PINGPONG_API AGameHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UUserWidget> ScoreWidgetClass;

	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	UScoreWidget* ScoreWidget;
};
