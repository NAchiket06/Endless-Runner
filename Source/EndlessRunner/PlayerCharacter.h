// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class ENDLESSRUNNER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	#pragma region Virtual Funtions
        	
    virtual void Tick(float DeltaTime) override;
    
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    #pragma endregion
    
    #pragma region FUNCTIONS

    /**
     * @brief Sets the Sideways/Yaw rotation of the player
     * @param value Amount by which player rotates. This is set by the axis vakue from inputComponent
     */
    void LookRightRotation(float value);
    
    /**
     * @brief Sets the Pitch rotation of the player
     * @param value Amount by which player rotates. This is set by the axis vakue from inputComponent
     */
    void LookUpRotation(float value);
    
    /**
     * @brief CHECKS THE CONDITIONS FOR BULLET TO BE FIRED. IF TRUE, FIRES THE BULLET 
     */
    void FireBullet();
    
    #pragma endregion 

    #pragma region MOVEMENT
    UPROPERTY(EditAnywhere,Category="Movement")
    float MovementSpeed = 100.f;
    
    UPROPERTY(EditAnywhere,Category="Movement")
    float RotationSpeed = 10.f;

    #pragma endregion

    #pragma region BulletProperties
    
    UPROPERTY(EditAnywhere,Category="Bullet")
    int BulletCount= 100;
    
    UPROPERTY(EditAnywhere,Category="Bullet")
    TSubclassOf<AActor> Bullet;

    UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
    USceneComponent* BulletSpawnPoint;

    #pragma endregion 
    	

};
