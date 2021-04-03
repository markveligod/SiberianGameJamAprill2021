// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamPauseWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamPauseWidget : public UGameJamBaseWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ContinueGameButton;
	UPROPERTY(meta = (BindWidget))
		UButton* MenuGameButton;
	
	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnContinueGame();
	UFUNCTION()
	void OnMenuGameLevel();
};
