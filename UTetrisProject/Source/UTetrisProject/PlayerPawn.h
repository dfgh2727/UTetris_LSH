// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class UTETRISPROJECT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SpawnBlock();

	UFUNCTION(BlueprintCallable)
	void BlockGoDown();

	UFUNCTION(BlueprintCallable)
	void BlockGoLeft();

	UFUNCTION(BlueprintCallable)
	void BlockGoRight();

	UFUNCTION(BlueprintCallable)
	void BlockTurnAround();

	class ABlockActor* Block = nullptr;
	class AMapActor* MapOutliner = nullptr;

	void SetMapOutliner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapSetting")
	int MapHeight = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapSetting")
	int MapWidth = 0;

	FVector Down = { 0.0, 0.0, -100.0 };
	FVector Left = { 0.0, -100.0, 0.0 };
	FVector Right = { 0.0, 100.0, 0.0 };

	FRotator Rotation = { 0.0, 0.0, 90.0 };

	FVector PrevLocation = { 0.0, 0.0, 0.0 };
	FVector CurLocation = { 0.0, 0.0, 0.0 };

};
