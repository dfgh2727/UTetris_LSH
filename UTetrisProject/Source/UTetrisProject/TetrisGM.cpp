// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisGM.h"
#include "MapActor.h"

ATetrisGM::ATetrisGM()
{

}

void ATetrisGM::BeginPlay()
{
	Super::BeginPlay();
}

void ATetrisGM::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ATetrisGM::SetMapOutliner(int width, int height)
{
	FVector Location = { 0.0, 0.0, 0.0 };


	for (int j = 0; j < height; ++j)
	{
		if (j == 0 || j == height - 1)
		{
			for (int i = 0; i < width; i++)
			{
				Location = { 0.0, i * 100.0, j * 100.0 };
				MapOutliner = GetWorld()->SpawnActor<AMapActor>();
				MapOutliner->SetActorLocation(Location);
			}
		}
		else
		{
			for (int i = 0; i < width; i = i + width - 1)
			{
				Location = { 0.0, i * 100.0, j * 100.0 };
				MapOutliner = GetWorld()->SpawnActor<AMapActor>();
				MapOutliner->SetActorLocation(Location);
			}
		}
	
	}

}
