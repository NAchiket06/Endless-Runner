// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	// When Bullet is initialized, set its initial force
	Mesh->AddForce(GetActorForwardVector() * InitialForce);

	// HIT EVENTS OF THE BULLET
	Mesh->OnComponentHit.AddDynamic(this,&ABullet::OnBulletHit);

	SetLifeSpan(5);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit)
{
	CheckIfGlassHit(OtherActor);
	UE_LOG(LogTemp,Warning,TEXT("Hit: %s"),*OtherActor->GetName());
}

void ABullet::CheckIfGlassHit(AActor* OtherActor)
{
	
}