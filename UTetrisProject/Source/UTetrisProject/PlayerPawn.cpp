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

	//FHitResult Result
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
		if (true == CheckCollisionWithBlock() || CurLocation.Z <= 100.0)
		{
			CollisionCheck = false;
			SpawnedBlockMap.Add(Index, Block);
			Index++;
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

bool APlayerPawn::CheckCollisionWithBlock()
{
	if (Index > 0 && nullptr != Block)
	{
		for (int i = 0; i < Index ; ++i)
		{
			CollisionCheck = Block->IsOverlappingActor(SpawnedBlockMap[i]);
			if (true == CollisionCheck)
			{
				Block = nullptr;
			}
		}
	}
	return CollisionCheck;
}


void APlayerPawn::BlockGoDown()
{
	if (nullptr != Block)
	{
		PrevLocation = Block->GetActorLocation();
		Block->AddActorWorldOffset(Down);
		BlockTheBlock(PrevLocation);
	}
}

void APlayerPawn::BlockGoLeft()
{
	if (nullptr != Block)
	{
		PrevLocation = Block->GetActorLocation();
		Block->AddActorWorldOffset(Left);
		BlockTheBlock(PrevLocation);
	}
}

void APlayerPawn::BlockGoRight()
{
	if (nullptr != Block)
	{
		PrevLocation = Block->GetActorLocation();
		Block->AddActorWorldOffset(Right);
		BlockTheBlock(PrevLocation);
	}
}

void APlayerPawn::BlockTurnAround()
{
	if (nullptr != Block)
	{
		PrevLocation = Block->GetActorLocation();
		Block->AddActorWorldRotation(Rotation);
		BlockTheBlock(PrevLocation);
	}
}

void APlayerPawn::BlockTheBlock(FVector Vector)
{
	FVector BlockPos = Block->GetActorLocation();
	if (BlockPos.Y < 100.0 || BlockPos.Y >= (MapWidth - 1) * 100.0)
	{
		Block->SetActorLocation(Vector);
	}
	if (BlockPos.Z < 100.0 || BlockPos.Z >= (MapHeight - 1) * 100.0)
	{
		Block->SetActorLocation(Vector);
	}
}

