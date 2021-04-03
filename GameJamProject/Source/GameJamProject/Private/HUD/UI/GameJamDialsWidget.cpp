// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/UI/GameJamDialsWidget.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameJamDialsWidget, All, All);

float UGameJamDialsWidget::GetPrecentWaterDial() const
{
	const auto TempGameModeBase = GetGameJamGameMode();
	if (TempGameModeBase)
	{
		return (TempGameModeBase->GetDialsData().WaterDials);
	}
	else
	{
		UE_LOG(LogGameJamDialsWidget, Error, TEXT("TempGameModeBase is nullptr"));
	}
	return (0.f);
}

float UGameJamDialsWidget::GetPrecentFrogsDial() const
{
	const auto TempGameModeBase = GetGameJamGameMode();
	if (TempGameModeBase)
	{
		return (TempGameModeBase->GetDialsData().FrogsDials);
	}
	else
	{
		UE_LOG(LogGameJamDialsWidget, Error, TEXT("TempGameModeBase is nullptr"));
	}
	return (0.f);
}

float UGameJamDialsWidget::GetPrecentCultsDial() const
{
	const auto TempGameModeBase = GetGameJamGameMode();
	if (TempGameModeBase)
	{
		return (TempGameModeBase->GetDialsData().CultDials);
	}
	else
	{
		UE_LOG(LogGameJamDialsWidget, Error, TEXT("TempGameModeBase is nullptr"));
	}
	return (0.f);
}

float UGameJamDialsWidget::GetPrecentEcoDial() const
{
	const auto TempGameModeBase = GetGameJamGameMode();
	if (TempGameModeBase)
	{
		return (TempGameModeBase->GetDialsData().EcoDials);
	}
	else
	{
		UE_LOG(LogGameJamDialsWidget, Error, TEXT("TempGameModeBase is nullptr"));
	}
	return (0.f);
}

