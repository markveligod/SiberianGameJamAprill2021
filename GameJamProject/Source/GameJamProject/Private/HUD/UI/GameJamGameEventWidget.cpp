// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamGameEventWidget.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"


DEFINE_LOG_CATEGORY_STATIC(LogGameEventWidget, All, All);

void UGameJamGameEventWidget::SetNewTextEvent(FText NewText)
{
	if (this->TextEventGame)
	{
		this->TextEventGame->SetText(NewText);
	}
}

void UGameJamGameEventWidget::SetNewImageEvent(UTexture2D* NewImageGame)
{
	if (this->ImageEvent)
	{
		this->ImageEvent->SetBrushFromTexture(NewImageGame);
	}
}

void UGameJamGameEventWidget::NativeOnInitialized()
{
	if (!this->ConfirmEventButton || !this->DecressEventButton)
	{
		UE_LOG(LogGameEventWidget, Error, TEXT("Button nullptr"));
		return;
	}

	this->ConfirmEventButton->OnClicked.AddDynamic(this, &UGameJamGameEventWidget::OnConfirmEvent);
	this->DecressEventButton->OnClicked.AddDynamic(this, &UGameJamGameEventWidget::OnDecressEvent);
}

void UGameJamGameEventWidget::OnConfirmEvent()
{
	const auto TempGameMode = GetGameJamGameMode();
	if (TempGameMode)
	{
		const auto TempData = TempGameMode->GetCurrentEventData();
		TempGameMode->ChangeCultsDialData(TempData.AmountConfirmCult);
		TempGameMode->ChangeEcoDialData(TempData.AmountConfirmEco);
		TempGameMode->ChangeFrogsDialData(TempData.AmountConfirmFrog);
		TempGameMode->ChangeWaterDialData(TempData.AmountConfirmWater);
		TempGameMode->ChangeResultOne();
		TempGameMode->SetGameStat(EGameState::ResultEvent);
		
	}
}

void UGameJamGameEventWidget::OnDecressEvent()
{
	const auto TempGameMode = GetGameJamGameMode();
	if (TempGameMode)
	{
		const auto TempData = TempGameMode->GetCurrentEventData();
		TempGameMode->ChangeCultsDialData(TempData.AmountDecressCult);
		TempGameMode->ChangeEcoDialData(TempData.AmountDecressEco);
		TempGameMode->ChangeFrogsDialData(TempData.AmountDecressFrog);
		TempGameMode->ChangeWaterDialData(TempData.AmountDecressWater);
		TempGameMode->ChangeResultTwo();
		TempGameMode->SetGameStat(EGameState::ResultEvent);
	}
}
