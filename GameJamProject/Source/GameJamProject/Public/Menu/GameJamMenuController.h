// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameJamMenuController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API AGameJamMenuController : public APlayerController
{
	GENERATED_BODY()
public:
		virtual void BeginPlay() override;
};
