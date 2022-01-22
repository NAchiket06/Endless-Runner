// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Glass.h"
#include "GameFramework/Actor.h"
#include "LevelModuleCreator.generated.h"

UCLASS()
class ENDLESSRUNNER_API ALevelModuleCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelModuleCreator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGlass> Glass1;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AGlass> Glass2;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cone1;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cone2;
	

};
