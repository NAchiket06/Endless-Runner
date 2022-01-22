// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:

	AEndlessRunnerGameModeBase();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
public:
	
	/**
	 * @brief HANDLES WHAT OCCURS WHEN PLAYER COLLIDES WITH GLASS PANES 
	 * @param RemainingBullets REMAINING BULLET COUNT OF PLAYER
	 */
	void OnPlayerCollidedWithGlass(int RemainingBullets);

	/**
	 * @brief SETS GAME END CONDITIONS FOR ACTORS
	 */
	void EndGame();

	/**
	 * @brief SPAWNS THE LEVEL MODULES CREATED AT REGUALAR INTERVALS
	 */
	void SpawnLevelModules();

	APawn* Player;

	/**
	 * @brief GETS THE PLAYER PAWN REFERENCE AT THE START OF THE LEVEL
	 */
	void GetPlayerPawn();

	#pragma  region Level Modules Spawning

	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = true;
	
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> LevelModules;

	int LevelModulesLength;
	
	FTimerHandle SpawnTimer;

	float TimeSinceLastSpawn;

	UPROPERTY(EditAnywhere)
	float SpawnDelay = 1.f;

	UPROPERTY(EditAnywhere)
	float ModuleLifeSpan = 40.f;

	UPROPERTY(EditAnywhere)
	FVector StartSpawnLocation = FVector(4400,0,0);

	UPROPERTY(EditAnywhere)
	float SpawnOffset = 2000;
	
	UPROPERTY(EditAnywhere)
	FRotator SpawnRotation = FRotator(0,0,0);
	
	FActorSpawnParameters SpawnParams;

	#pragma endregion 
};
