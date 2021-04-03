// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamResultWidget.generated.h"

class UButton;
class UTextBlock;
/**
 *
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamResultWidget : public UGameJamBaseWidget
{
	GENERATED_BODY()
public:
	void SetTextResult(FText NewText);
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* NextEventButton;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* ResultTextBlock;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnSendStateInProgress();
};
