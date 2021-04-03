// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamGameOverWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "GameJamProject/Public/GameJamGameInstance.h"

void UGameJamGameOverWidget::SetTextGameOver(FText NewText)
{
	if (this->ReasonGameTextBlock)
	{
		this->ReasonGameTextBlock->SetText(NewText);
	}
}

void UGameJamGameOverWidget::NativeOnInitialized()
{
	if (this->MainMenuGameButton)
	{
		this->MainMenuGameButton->OnClicked.AddDynamic(this, &UGameJamGameOverWidget::OnGameOver);
	}
}

void UGameJamGameOverWidget::OnGameOver()
{
	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		const auto TempGameInstance = Cast<UGameJamGameInstance>(GetWorld()->GetGameInstance());
		if (TempGameInstance)
			UGameplayStatics::OpenLevel(GetWorld(), TempGameInstance->GetNameStartMenuLevel());
	}
}
