// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Blueprint/UserWidget.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	GameMode = GetWorld()->GetAuthGameMode<AEndlessRunnerGameModeBase>();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	AddMovementInput(FVector(1,0,0) * MovementSpeed * DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("LookRight"),this,&APlayerCharacter::LookRightRotation);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&APlayerCharacter::LookUpRotation);

	PlayerInputComponent->BindAction(TEXT("Fire"),EInputEvent::IE_Pressed,this,&APlayerCharacter::FireBullet);

}

void APlayerCharacter::LookRightRotation(float value)
{
	if(IsGameOver)
	{
		return;
	}
	AddControllerYawInput(value * RotationSpeed);
}

void APlayerCharacter::LookUpRotation(float value)
{
	if(IsGameOver)
	{
		return;
	}
	AddControllerPitchInput(-value * RotationSpeed);
}

void APlayerCharacter::FireBullet()
{
	if(IsGameOver)
	{
		return;
	}
	if(BulletCount == 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("No bullets left."));
		return;
	}

	if(Bullet == nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Bullet not assigned to player."));
	}
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AActor>(Bullet,BulletSpawnPoint->GetComponentLocation(),GetControlRotation(),SpawnParams);
	ReduceBullets(1);
}


void APlayerCharacter::OnPlayerCollidedWithObstacles()
{
	if(IsGameOver)
	{
		return;
	}
	ReduceBullets(5);

	if(GameMode != nullptr)
	{
		GameMode->OnPlayerCollidedWithGlass(BulletCount);
	}
}

void APlayerCharacter::ReduceBullets(int count)
{
	BulletCount-= count;

	if(BulletCount <=0 )
	{
		BulletCount = 0;
		EndGame();
	}
}

void APlayerCharacter::IncreaseBullets(int count)
{
	BulletCount += count;
}


int APlayerCharacter::ReturnBulletCount() const
{
	return BulletCount;
}

void APlayerCharacter::EndGame()
{
	IsGameOver = true;
	GameMode->EndGame();
	MovementSpeed = 0;
}

