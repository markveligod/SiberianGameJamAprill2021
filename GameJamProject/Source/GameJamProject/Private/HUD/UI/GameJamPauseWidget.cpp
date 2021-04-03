// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamPauseWidget.h"
#include "Components/Button.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameJamProject/Public/GameJamGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameJamPauseWidget, All, All);

void UGameJamPauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (!this->ContinueGameButton || !this->MenuGameButton)
	{
		UE_LOG(LogGameJamPauseWidget, Error, TEXT("Button is nullptr"));
		return;
	}

	this->ContinueGameButton->OnClicked.AddDynamic(this, &UGameJamPauseWidget::OnContinueGame);
	this->MenuGameButton->OnClicked.AddDynamic(this, &UGameJamPauseWidget::OnMenuGameLevel);
}

void UGameJamPauseWidget::OnContinueGame()
{
	const auto TempGameMode = GetGameJamGameMode();
	if (TempGameMode)
	{
		TempGameMode->ClearPause();
	}
}

void UGameJamPauseWidget::OnMenuGameLevel()
{
	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		const auto TempGameInstance = Cast<UGameJamGameInstance>(GetWorld()->GetGameInstance());
		if (TempGameInstance)
			UGameplayStatics::OpenLevel(GetWorld(), TempGameInstance->GetNameStartMenuLevel());
	}
}
