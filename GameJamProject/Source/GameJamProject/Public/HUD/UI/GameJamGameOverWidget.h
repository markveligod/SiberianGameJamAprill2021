// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamGameOverWidget.generated.h"

class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamGameOverWidget : public UGameJamBaseWidget
{
	GENERATED_BODY()
public:
	void SetTextGameOver(FText NewText);
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* MainMenuGameButton;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* ReasonGameTextBlock;

	virtual void NativeOnInitialized() override;
private:
	UFUNCTION()
		void OnGameOver();
	
};
