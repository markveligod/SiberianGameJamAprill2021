// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamDialsWidget.generated.h"


/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamDialsWidget : public UGameJamBaseWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	float GetPrecentWaterDial() const;
	UFUNCTION(BlueprintCallable)
	float GetPrecentFrogsDial() const;
	UFUNCTION(BlueprintCallable)
	float GetPrecentCultsDial() const;
	UFUNCTION(BlueprintCallable)
		float GetPrecentEcoDial() const;

private:
	
	
};
