// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisGM.h"
#include "MapActor.h"
#include "BlockActor.h"

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

	if (nullptr == Block)
	{
		SpawnBlock();
	}

}

void ATetrisGM::SetMapOutliner(int width, int height)
{
	FVector Location = { 0.0, 0.0, 0.0 };
	MapWidth = width;
	MapHeight = height;

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


void ATetrisGM::SpawnBlock()
{
	FVector StartLocation = { 0.0, MapWidth * 50.0, MapHeight * 100.0 };

	Block = GetWorld()->SpawnActor<ABlockActor>();
	Block->SetActorLocation(StartLocation);
}