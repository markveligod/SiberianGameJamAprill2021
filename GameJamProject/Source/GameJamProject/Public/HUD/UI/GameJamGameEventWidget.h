// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamGameEventWidget.generated.h"

class UTextBlock;
class UButton;
class UImage;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamGameEventWidget : public UGameJamBaseWidget
{
	GENERATED_BODY()

public:
	void SetNewTextEvent(FText NewText);
	void SetNewImageEvent(UTexture2D* NewImageGame);
protected:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* TextEventGame;
	UPROPERTY(meta = (BindWidget))
		UButton* ConfirmEventButton;
	UPROPERTY(meta = (BindWidget))
		UButton* DecressEventButton;
	UPROPERTY(meta = (BindWidget))
		UImage* ImageEvent;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnConfirmEvent();
	UFUNCTION()
		void OnDecressEvent();
};
