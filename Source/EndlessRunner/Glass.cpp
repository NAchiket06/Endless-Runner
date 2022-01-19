// Fill out your copyright notice in the Description page of Project Settings.


#include "Glass.h"

#include "Bullet.h"
#include "PlayerCharacter.h"

// Sets default values
AGlass::AGlass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GlassMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Glass Mesh"));
	GlassMesh->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void AGlass::BeginPlay()
{
	Super::BeginPlay();
	GlassMesh->OnComponentHit.AddUniqueDynamic(this,&AGlass::OnCollision);
	//GlassMesh->OnComponentBeginOverlap.AddDynamic(this,&AGlass::OnOverlap);
}

// Called every frame
void AGlass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Rotate)
	{
		FRotator CurrentRotation = GetActorRotation();
		SetActorRotation(CurrentRotation + RotationValue * DeltaTime);
	}
}

void AGlass::OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	GlassMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetLifeSpan(5);

	// CHECK IF THE ACTOR THAT HIT WAS BULLET
	ABullet* BulletComponent = Cast<ABullet>(OtherActor);
	if(BulletComponent != nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Glass hit Bullet."));
		Destroy();
		
		// TODO PLAY GLASS DESTROYED ANIMATION

		return;
	}

	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	if(Player != nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Glass hit Player."));

		Player->OnPlayerCollidedWithObstacles();

		// REDUCE PLAYER BULLET COUNT

		// PLAYER PLAYER HIT EFFECTS

	}

	

}


