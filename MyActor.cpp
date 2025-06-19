// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <cmath>

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	Move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyActor::Step() {
	return FMath::RandRange(0, 1);
}

void AMyActor::Move() {
	for (int i = 0; i < 10; i++){
		FVector first;
		FVector second;

		int32 dx = Step();
		int32 dy = Step();

		first = start;
		start.X += dx;
		start.Y += dy;
		second = start;

		UE_LOG(LogTemp, Warning, TEXT("Step %d: Current Position(%.0f, %.0f), Distance: %.1f"), i + 1, start.X, start.Y, Distance(first, second));
	}
	FVector zero = FVector(0, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT("Total Distance: %.1f"), Distance(zero, start));
}

float AMyActor::Distance(FVector first, FVector second) {

	float dx = first.X - second.X;
	float dy = first.Y - second.Y;

	return FMath::Sqrt(dx * dx + dy * dy);
}
