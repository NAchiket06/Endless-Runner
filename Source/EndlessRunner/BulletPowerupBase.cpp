// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletPowerupBase.h"

#include "PlayerCharacter.h"

// Sets default values
ABulletPowerupBase::ABulletPowerupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABulletPowerupBase::BeginPlay()
{
	Super::BeginPlay();
	
	BaseMesh->OnComponentHit.AddDynamic(this,&ABulletPowerupBase::OnBulletHit);
}

// Called every frame
void ABulletPowerupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletPowerupBase::OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit )
{
	GetWorld()->DestroyActor(this);

	APlayerCharacter* Player = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if(Player != nullptr)
	{
		Player->IncreaseBullets(5);
	}
}

