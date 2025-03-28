// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockActor.generated.h"

//enum class EBlockType
//{
//	EBlock1,
//	EBlock2,
//	EBlock3,
//	EBlock4,
//	EBlock5,
//	EBlock6,
//	EBlock7
//};

UCLASS()
class UTETRISPROJECT_API ABlockActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddMesh();

	void SetBlockMesh(int key);

	//virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	//UFUNCTION(BlueprintCallable)
	//void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	TMap<int, UStaticMesh*> MeshMap;

	UStaticMeshComponent* StaticMeshComponent = nullptr;
	
	int RandInt = 0;

	bool CollisionCheck = false;
};
