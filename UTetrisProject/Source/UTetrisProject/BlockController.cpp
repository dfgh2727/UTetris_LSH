// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockController.h"


ABlockController::ABlockController()
{

}


void ABlockController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnly;
	SetInputMode(GameOnly);
}

void ABlockController::SetupInputComponent()
{
	Super::SetupInputComponent();

}

//void ABlockController::ActorGoDown()
//{
//
//}
