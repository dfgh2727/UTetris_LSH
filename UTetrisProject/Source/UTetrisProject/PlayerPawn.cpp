// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "BlockActor.h"

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
		FVector CurLocation = Block->GetActorLocation();
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
	FVector StartLocation = { 0.0, 0.0, 1000.0 };

	Block = GetWorld()->SpawnActor<ABlockActor>();
	Block->SetActorLocation(StartLocation);
}

void APlayerPawn::ControlBlock()
{
	if (nullptr != Block)
	{

	}
}

void APlayerPawn::BlockGoDown()
{
	if (nullptr != Block)
	{
		Block->AddActorWorldOffset(Down);
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

