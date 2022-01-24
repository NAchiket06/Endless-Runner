// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

#include "EngineUtils.h"
#include "PlayerCharacter.h"
#include "ShooterPlayerController.h"

AEndlessRunnerGameModeBase::AEndlessRunnerGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,TEXT("Endless Runner Game mode active."));
	
	GetPlayerPawn();
	
	LevelModulesLength = LevelModules.Num();

	for(int i=0;i<10;i++)
	{
		SpawnLevelModules();
	}
}

void AEndlessRunnerGameModeBase::GetPlayerPawn()
{
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();

	if(Player == nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Player not found."));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Player found."));
	}
}

void AEndlessRunnerGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if(Player != nullptr && ShouldSpawn)
	{
		TimeSinceLastSpawn += DeltaSeconds;
		
		if(TimeSinceLastSpawn >= SpawnDelay)
		{
			SpawnLevelModules();
			TimeSinceLastSpawn =0;
		}
	}
}
void AEndlessRunnerGameModeBase::SpawnLevelModules()
{
	if(!ShouldSpawn) return;
	
	if(LevelModulesLength == 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("No modules to spawn."));
	}
	int Random = FMath::RandRange(0,LevelModulesLength-1);

	AActor* SpawnedModule = GetWorld()->SpawnActor<AActor>(LevelModules[Random],StartSpawnLocation,SpawnRotation,SpawnParams);
	SpawnedModule->SetLifeSpan(ModuleLifeSpan);

	StartSpawnLocation.X += SpawnOffset;
	
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

	ShouldSpawn = false;
}

