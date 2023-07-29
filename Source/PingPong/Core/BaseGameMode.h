// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameMode.generated.h"


UCLASS()
class PINGPONG_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<APlayerController*> Players;

	void StartCountdown();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartGameCountdown = 5.f;

private:
	FTimerHandle FStartGameTimerHandle;
};
