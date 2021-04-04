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
		AGamePlayerController();
public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	
private:

	void OnGameState(EGameState GameState);

	void OnPauseGame();
};
