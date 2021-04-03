// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamWelcomeWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamWelcomeWidget : public UGameJamBaseWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ConfGameButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnSendStateInProgress();

};
