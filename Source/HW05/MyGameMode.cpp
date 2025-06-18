// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

#include "MyActor.h"

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

	UClass* ActorClassToSpawn = AMyActor::StaticClass();

	FVector SpawnLocation = FVector(0.f, 0.f, 0.f);
	FRotator SpawnRotation = FRotator::ZeroRotator;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	GetWorld()->SpawnActor<AMyActor>(SpawnLocation, SpawnRotation, SpawnParams);
}
