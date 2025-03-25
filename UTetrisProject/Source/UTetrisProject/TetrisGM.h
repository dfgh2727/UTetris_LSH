// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TetrisGM.generated.h"

/**
 * 
 */
UCLASS()
class UTETRISPROJECT_API ATetrisGM : public AGameMode
{
	GENERATED_BODY()

public:

	ATetrisGM();

	void BeginPlay();

	void Tick(float _DeltaTime);

	UFUNCTION(BlueprintCallable)
	void SetMapOutliner(int width, int height);

	class AMapActor* MapOutliner = nullptr;
};
