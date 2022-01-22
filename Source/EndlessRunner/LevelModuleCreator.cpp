// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelModuleCreator.h"

// Sets default values
ALevelModuleCreator::ALevelModuleCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(Root);

	

}

// Called when the game starts or when spawned
void ALevelModuleCreator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALevelModuleCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

