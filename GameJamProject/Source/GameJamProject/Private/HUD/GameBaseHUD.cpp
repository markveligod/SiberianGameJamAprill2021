// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/GameBaseHUD.h"
#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "HUD/UI/GameJamGameEventWidget.h"
#include "HUD/UI/GameJamGameOverWidget.h"


DEFINE_LOG_CATEGORY_STATIC(LogGameBaseHUD, All, All);

void AGameBaseHUD::BeginPlay()
{
	Super::BeginPlay();
	if (this->PlayerHudWidgetClass)
		this->GameWidgets.Add(EGameState::Welcome, CreateWidget<UGameJamBaseWidget>(GetWorld(), this->GameWelcomeHudWidgetClass));
	
	if (this->PlayerHudWidgetClass)
		this->GameWidgets.Add(EGameState::InProgress, CreateWidget<UGameJamBaseWidget>(GetWorld(), this->PlayerHudWidgetClass));

	if (this->GameEventHudWidgetClass)
		this->GameWidgets.Add(EGameState::GameEvent, CreateWidget<UGameJamBaseWidget>(GetWorld(), this->GameEventHudWidgetClass));

	if (this->PauseHudWidgetClass)
		this->GameWidgets.Add(EGameState::Pause, CreateWidget<UGameJamBaseWidget>(GetWorld(), this->PauseHudWidgetClass));

	if (this->GameOverHudWidgetClass)
		this->GameWidgets.Add(EGameState::GameOver, CreateWidget<UGameJamBaseWidget>(GetWorld(), this->GameOverHudWidgetClass));
	
	for(const auto TempWigetPair : this->GameWidgets)
	{
		const auto TempWidget = TempWigetPair.Value;
		TempWidget->AddToViewport();
		TempWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (GetWorld())
	{
		const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
		if (TempGameMode)
		{
			TempGameMode->OnGame.AddUObject(this, &AGameBaseHUD::OnGameState);
		}
	}
}

void AGameBaseHUD::OnGameState(EGameState GameStat)
{
	if (!GetWorld())
		return;

	
	if (this->CurrentWidget)
	{
		this->CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (this->GameWidgets.Contains(GameStat))
	{
		this->CurrentWidget = this->GameWidgets[GameStat];
		if (GameStat == EGameState::GameEvent)
		{
			const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
			const auto TempWidget = Cast<UGameJamGameEventWidget>(this->CurrentWidget);
			if (TempGameMode && TempWidget)
			{
					TempWidget->SetNewTextEvent(TempGameMode->GetCurrentEventData().TextEvent);
				UE_LOG(LogGameBaseHUD, Display, TEXT("New Event Call"));
			}
		}
		else if (GameStat == EGameState::GameOver)
		{
			const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
			const auto TempWidget = Cast<UGameJamGameOverWidget>(this->CurrentWidget);
			if (TempGameMode && TempWidget)
			{
				if (TempGameMode->IsCriticalDialsValue())
				{
					TempWidget->SetTextGameOver(TempGameMode->GetFailText());
				}
				else if (TempGameMode->IsWinnerDialsValue())
				{
					TempWidget->SetTextGameOver(TempGameMode->GetWinnerText());
				}
				else
				{
					TempWidget->SetTextGameOver(TempGameMode->GetFailText());
				}
				
			}
		}
	}

	if (this->CurrentWidget)
	{
		this->CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}
	
	UE_LOG(LogGameBaseHUD, Display, TEXT("Match State: %s"), *UEnum::GetValueAsString(GameStat))
}
