// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlockController.generated.h"

/**
 * 
 */
UCLASS()
class UTETRISPROJECT_API ABlockController : public APlayerController
{
	GENERATED_BODY()

public:
	ABlockController();

	void BeginPlay() override;
	void SetupInputComponent() override;

	/*void ActorGoDown();*/

	
};
