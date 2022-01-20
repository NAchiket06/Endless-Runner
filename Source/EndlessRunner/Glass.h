// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Glass.generated.h"

UCLASS()
class ENDLESSRUNNER_API AGlass : public AActor
{
	GENERATED_BODY()
	
public:	
	AGlass();
	
	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* GlassMesh;

	

#pragma region ROTATION PARAMETERS

	UPROPERTY(EditAnywhere)
	bool Rotate = false;

	UPROPERTY(EditAnywhere)
	FRotator RotationValue;
	
#pragma endregion 
	
	#pragma region FUNCTIONS
	UFUNCTION()
	void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult );

	#pragma endregion 
	
};
