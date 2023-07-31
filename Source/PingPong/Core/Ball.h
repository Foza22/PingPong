// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utils.h"
#include "Ball.generated.h"

class USphereComponent;

UCLASS()
class PINGPONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void ScoreGoal(EColors Color);
	
	void Reactivate(bool bInstant);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* DefaultRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeToReactivate = 3.f;

	UPROPERTY(Replicated)
	FVector Velocity;

	void MoveBall(float DeltaSeconds);

	void MakeVelocity();

	FVector InitialLocation;

private:
	FTimerHandle FReactivateBallTimerHandle;
};
