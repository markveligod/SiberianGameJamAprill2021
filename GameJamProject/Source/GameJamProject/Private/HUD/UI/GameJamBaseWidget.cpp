// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamBaseWidget.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"

AGameJamProjectGameModeBase* UGameJamBaseWidget::GetGameJamGameMode() const
{
	return (GetWorld() ? Cast<AGameJamProjectGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr);
}
