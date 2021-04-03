// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamWelcomeWidget.generated.h"

class UButton;
class UTextBlock;
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
	UPROPERTY(meta = (BindWidget))
		UTextBlock* WelcomeTextBlock;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text");
	TArray<FText> ArrayText;

	virtual void NativeOnInitialized() override;

private:
	int32 NumTextArray = 0;
	UFUNCTION()
	void OnSendStateInProgress();

};
