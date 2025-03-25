// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockActor.h"

// Sets default values
ABlockActor::ABlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockActor::AddMesh()
{
	/*UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}

	UStaticMesh* Mesh2 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh2)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}

	UStaticMesh* Mesh3 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh3)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}

	UStaticMesh* Mesh4 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh4)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}

	UStaticMesh* Mesh5 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh5)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}

	UStaticMesh* Mesh6 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh6)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}

	UStaticMesh* Mesh7 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Outline.SM_Outline"));
	if (nullptr != Mesh7)
	{
		StaticMeshComponent->SetStaticMesh(Mesh);
	}*/

}
