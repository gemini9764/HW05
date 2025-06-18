// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math/RandomStream.h"
#include "Misc/DateTime.h"

DEFINE_LOG_CATEGORY(HW05);

// Sets default values
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Start = FVector2D(0, 0);
	Move();

	UE_LOG(LogTemp, Warning, TEXT("총 이동 거리: %.2f"), TotDist);
	UE_LOG(LogTemp, Warning, TEXT("이벤트 발생 횟수: %d"), EvCnt);
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

int32 AMyActor::CreateEvent()
{
	return FMath::RandRange(0, 1); // 50% 확률
}

float AMyActor::Distance(FVector2D First, FVector2D Second)
{
	return FVector2D::Distance(First, Second);
}

void AMyActor::Move()
{
	for (int i = 0; i < 10; i++)
	{
		FVector2D Prev = Start;

		Start.X += Step();
		Start.Y += Step();

		float Dist = Distance(Prev, Start);
		TotDist += Dist;

		UE_LOG(LogTemp, Warning, TEXT("이동 %d: (%.0f, %.0f)"), i + 1, Start.X, Start.Y);
		UE_LOG(LogTemp, Warning, TEXT("거리: %.2f"), Dist);

		if (CreateEvent())
		{
			EvCnt++;
			UE_LOG(LogTemp, Warning, TEXT("이벤트 발생"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("이벤트 없음"));
		}
	}
}
