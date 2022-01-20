// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
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
