// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "BlockActor.h"
#include "MapActor.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	SetMapOutliner();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr == Block)
	{
		SpawnBlock();
	}
	else
	{
		CurLocation = Block->GetActorLocation();
		if (CurLocation.Z < 0.0)
		{
			Block->Destroy();
			Block = nullptr;
		}
	}
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPawn::SpawnBlock()
{
	FVector StartLocation = { 0.0, MapWidth * 50.0, (MapHeight - 2) * 100.0};

	Block = GetWorld()->SpawnActor<ABlockActor>();
	Block->SetActorLocation(StartLocation);
}

void APlayerPawn::SetMapOutliner()
{
	FVector Location = { 0.0, 0.0, 0.0 };

	for (int j = 0; j < MapHeight; ++j)
	{
		if (j == 0 || j == MapHeight - 1)
		{
			for (int i = 0; i < MapWidth; i++)
			{
				Location = { 0.0, i * 100.0, j * 100.0 };
				MapOutliner = GetWorld()->SpawnActor<AMapActor>();
				MapOutliner->SetActorLocation(Location);
			}
		}
		else
		{
			for (int i = 0; i < MapWidth; i = i + MapWidth - 1)
			{
				Location = { 0.0, i * 100.0, j * 100.0 };
				MapOutliner = GetWorld()->SpawnActor<AMapActor>();
				MapOutliner->SetActorLocation(Location);
			}
		}

	}
}


void APlayerPawn::BlockGoDown()
{
	if (nullptr != Block)
	{
		//PrevLocation = CurLocation;
		Block->AddActorWorldOffset(Down);
		//CurLocation = Block->GetActorLocation();
	}
}

void APlayerPawn::BlockGoLeft()
{
	if (nullptr != Block)
	{
		Block->AddActorWorldOffset(Left);
	}
}

void APlayerPawn::BlockGoRight()
{
	if (nullptr != Block)
	{
		Block->AddActorWorldOffset(Right);
	}
}

void APlayerPawn::BlockTurnAround()
{
	if (nullptr != Block)
	{
		Block->AddActorWorldRotation(Rotation);
	}
}

