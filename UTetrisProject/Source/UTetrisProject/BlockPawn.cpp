// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockPawn.h"

// Sets default values
ABlockPawn::ABlockPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlockPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABlockPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void ABlockPawn::TurnTheBlock()
//{
//	FRotator Rotation = { 90.0, 0.0, 0.0 };
//	AddActorWorldRotation(Rotation);
//}
