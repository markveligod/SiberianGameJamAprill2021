// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamWelcomeWidget.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Components/Button.h"

void UGameJamWelcomeWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (this->ConfGameButton)
	{
		this->ConfGameButton->OnClicked.AddDynamic(this, &UGameJamWelcomeWidget::OnSendStateInProgress);
	}
}

void UGameJamWelcomeWidget::OnSendStateInProgress()
{

	const auto TempGameMode = GetGameJamGameMode();
	if (TempGameMode)
	{
		TempGameMode->SetGameStat(EGameState::InProgress);
	}
}
