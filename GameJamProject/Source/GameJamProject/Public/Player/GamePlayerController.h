// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DataArray.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	void OnGameState(EGameState GameState);
	void OnPauseGame();
};
