// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameJamMenuWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* StartGameButton;

	UPROPERTY(meta = (BindWidget))
		UButton* QuitGameButton;
	
	virtual void NativeOnInitialized() override;

private:
	bool bIsAboutVisible = false;

	UFUNCTION()
	void OnStartGame();

	UFUNCTION()
	void OnQuitGame();
};
