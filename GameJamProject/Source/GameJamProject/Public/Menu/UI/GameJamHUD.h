// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameJamHUD.generated.h"

/**
 *
 */
UCLASS()
class GAMEJAMPROJECT_API AGameJamHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widget")
		TSubclassOf<UUserWidget> MenuWidget;
	
};
