// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

#include "EngineUtils.h"
#include "PlayerCharacter.h"
#include "ShooterPlayerController.h"

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,TEXT("Endless Runner Game mode active."));
}

void AEndlessRunnerGameModeBase::OnPlayerCollidedWithGlass(int RemainingBullets)
{
	UE_LOG(LogTemp,Warning,TEXT("Player Collided with Glass."));

	if(RemainingBullets == 0)
	{
		EndGame();
	}
}

void AEndlessRunnerGameModeBase::EndGame()
{
	UE_LOG(LogTemp,Warning,TEXT("Game Over"));

	for(APlayerController* PlayerController : TActorRange<APlayerController>(GetWorld()))
	{
		PlayerController->GameHasEnded(PlayerController->GetPawn(),true);
	}
}
