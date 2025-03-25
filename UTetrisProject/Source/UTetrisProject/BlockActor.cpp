// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockActor.h"

// Sets default values
ABlockActor::ABlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	AddMesh();
	RandInt = FMath::RandRange(1, 7);
}

// Called when the game starts or when spawned
void ABlockActor::BeginPlay()
{
	Super::BeginPlay();

	SetBlockMesh(RandInt);
}

// Called every frame
void ABlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockActor::AddMesh()
{
	/*for (int i = 1; i < 8; i++)
	{
		UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block" + i + ".SM_Block" + i));
		if (nullptr != Mesh)
		{
			MeshMap.Add(i, Mesh);
		}
	}*/

	UStaticMesh* Mesh1 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block1.SM_Block1"));
	if (nullptr != Mesh1)
	{
		MeshMap.Add(1, Mesh1);
	}
	UStaticMesh* Mesh2 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block2.SM_Block2"));
	if (nullptr != Mesh2)
	{
		MeshMap.Add(2, Mesh2);
	}
	UStaticMesh* Mesh3 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block3.SM_Block3"));
	if (nullptr != Mesh3)
	{
		MeshMap.Add(3, Mesh3);
	}
	UStaticMesh* Mesh4 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block4.SM_Block4"));
	if (nullptr != Mesh4)
	{
		MeshMap.Add(4, Mesh4);
	}
	UStaticMesh* Mesh5 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block5.SM_Block5"));
	if (nullptr != Mesh5)
	{
		MeshMap.Add(5, Mesh5);
	}
	UStaticMesh* Mesh6 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block6.SM_Block6"));
	if (nullptr != Mesh6)
	{
		MeshMap.Add(6, Mesh6);
	}
	UStaticMesh* Mesh7 = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Block/SM_Block7.SM_Block7"));
	if (nullptr != Mesh7)
	{
		MeshMap.Add(7, Mesh7);
	}
}

void ABlockActor::SetBlockMesh(int key)
{
	UStaticMesh* BlockMesh = MeshMap[key];
	if (nullptr != BlockMesh)
	{
		StaticMeshComponent->SetStaticMesh(BlockMesh);
	}
}
