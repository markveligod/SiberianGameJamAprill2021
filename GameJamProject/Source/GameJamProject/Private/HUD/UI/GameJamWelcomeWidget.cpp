// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamWelcomeWidget.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

DEFINE_LOG_CATEGORY_STATIC(LogWidgetWelcome, All, All);

void UGameJamWelcomeWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (this->ConfGameButton)
	{
		this->ConfGameButton->OnClicked.AddDynamic(this, &UGameJamWelcomeWidget::OnSendStateInProgress);
	}
	if (this->ArrayText.Num() == 0)
	{
		UE_LOG(LogWidgetWelcome, Error, TEXT("Num Array widget welcome equal 0"));
	}
	
}

void UGameJamWelcomeWidget::OnSendStateInProgress()
{

	const auto TempGameMode = GetGameJamGameMode();
	if (TempGameMode)
	{
		if (this->NumTextArray != this->ArrayText.Num())
		{
			this->WelcomeTextBlock->SetText(this->ArrayText[this->NumTextArray]);
			this->NumTextArray++;
		}
		else
		{
			TempGameMode->SetGameStat(EGameState::InProgress);
		}
	}
}
