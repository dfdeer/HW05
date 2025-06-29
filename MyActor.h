// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
private:
	FVector start = FVector(0, 0, 0);

public:	
	// Sets default values for this actor's properties
	AMyActor();

	int32 Step();
	void Move();
	float Distance(FVector first, FVector second);	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
