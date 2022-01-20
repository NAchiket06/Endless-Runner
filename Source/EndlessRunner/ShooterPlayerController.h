// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;

private:
	
	#pragma region HUDS

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	UUserWidget* Hud;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> EndGameClass;

	UUserWidget* EndGame;
	/*
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	UUserWidget* Hud;
	*/
	#pragma endregion

	#pragma  region FUNCTIONS
	
};
