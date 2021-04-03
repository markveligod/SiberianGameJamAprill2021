// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamResultWidget.h"
#include "Components/Button.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Components/TextBlock.h"

void UGameJamResultWidget::SetTextResult(FText NewText)
{
	if (this->ResultTextBlock)
	{
		this->ResultTextBlock->SetText(NewText);
	}
}

void UGameJamResultWidget::NativeOnInitialized()
{
	if(this->NextEventButton)
	{
		this->NextEventButton->OnClicked.AddDynamic(this, &UGameJamResultWidget::OnSendStateInProgress);
	}
}

void UGameJamResultWidget::OnSendStateInProgress()
{
	const auto TempGameMode = GetGameJamGameMode();
	if (TempGameMode)
	{
		TempGameMode->UpCurrentIndex();
		TempGameMode->ClearPause();
	}
}
