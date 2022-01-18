// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class ENDLESSRUNNER_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
		
	UPROPERTY(EditAnywhere)
	float InitialForce = 1000.f;

	UPROPERTY(EditAnywhere)
	FVector HitForce = FVector(50,50,50);
	
	UFUNCTION()
	void OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

	void CheckIfGlassHit(AActor* OtherActor);
};
