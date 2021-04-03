// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameJamBaseWidget.generated.h"

class AGameJamProjectGameModeBase;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamBaseWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	AGameJamProjectGameModeBase* GetGameJamGameMode() const;
	
};
