// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"

#include "Ball.h"
#include "Kismet/GameplayStatics.h"

void ABaseGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	Players.Emplace(NewPlayer);

	if(GetNumPlayers() == 2)
	{
		GetWorldTimerManager().SetTimer(FStartGameTimerHandle, this, &ABaseGameMode::StartCountdown, 1.f, true);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 999, FColor::Blue, TEXT("Waiting for second player"));
	}
}

void ABaseGameMode::StartCountdown()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Blue, FString::FromInt(StartGameCountdown));

	if(StartGameCountdown-- <= 1)
	{
		TArray<AActor*> OutActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABall::StaticClass(), OutActors);
		if(OutActors.Num() > 0)
		{
			ABall* Ball = Cast<ABall>(OutActors[0]);
			Ball->Reactivate(true);
		}
		GetWorldTimerManager().ClearTimer(FStartGameTimerHandle);
	}
}
