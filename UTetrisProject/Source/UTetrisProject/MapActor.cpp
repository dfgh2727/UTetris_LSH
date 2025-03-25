// Fill out your copyright notice in the Description page of Project Settings.


#include "MapActor.h"

// Sets default values
AMapActor::AMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMapActor::BeginPlay()
{
	Super::BeginPlay();

	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}
}

// Called every frame
void AMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

