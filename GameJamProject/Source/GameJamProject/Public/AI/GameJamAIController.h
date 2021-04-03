// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameJamAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API AGameJamAIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void OnPossess(APawn* InPawn) override;
};
