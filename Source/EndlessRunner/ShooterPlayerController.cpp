// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"

#include "PlayerCharacter.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Hud = CreateWidget(this, HUDClass);
	if(Hud != nullptr)
	{
		Hud->AddToViewport();
	}
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	Hud->RemoveFromViewport();
	EndGame = CreateWidget(this, EndGameClass);
	if(EndGame != nullptr)
	{
		EndGame->AddToViewport();
	}
}


