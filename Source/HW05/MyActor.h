// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(HW05, Log, All);

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	FVector2D Start;
	int32 EvCnt = 0;
	float TotDist = 0;

	int32 Step();
	int32 CreateEvent();
	float Distance(FVector2D First, FVector2D Second);
	void Move();

	UPROPERTY()
	FRandomStream RandomStream;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
