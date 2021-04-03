// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameJamProjectGameModeBase.h"
#include "Player/PlayerPawn.h"
#include "HUD/GameBaseHUD.h"
#include "Player/GamePlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameJamProjectGameModeBase, All, All);

AGameJamProjectGameModeBase::AGameJamProjectGameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	HUDClass = AGameBaseHUD::StaticClass();
	PlayerControllerClass = AGamePlayerController::StaticClass();
}

void AGameJamProjectGameModeBase::StartPlay()
{
	Super::StartPlay();
	this->ArrayEventNum = this->EventArray.Num();
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(this->GameTimeHandler, this, &AGameJamProjectGameModeBase::StartEvent, this->TimeEvent, true);
	}
	this->SetGameStat(EGameState::Welcome);
	
}

void AGameJamProjectGameModeBase::ChangeWaterDialData(float amount)
{
	const auto TempWaterDial = this->DialsData.WaterDials;
	this->DialsData.WaterDials = FMath::Clamp(TempWaterDial + amount, 0.f, 100.f);
	//Check if WaterDial > 80.f or < 20.f
}

void AGameJamProjectGameModeBase::ChangeFrogsDialData(float amount)
{
	const auto TempFrogsDial = this->DialsData.FrogsDials;
	this->DialsData.FrogsDials = FMath::Clamp(TempFrogsDial + amount, 0.f, 100.f);
	//Check if FrogsDial > 80.f or < 20.f
}

void AGameJamProjectGameModeBase::ChangeCultsDialData(float amount)
{
	const auto TempCultsDial = this->DialsData.CultDials;
	this->DialsData.CultDials = FMath::Clamp(TempCultsDial + amount, 0.f, 100.f);
	//Check if CultDial > 80.f or < 20.f
}

void AGameJamProjectGameModeBase::ChangeEcoDialData(float amount)
{
	const auto TempEcoDial = this->DialsData.EcoDials;
	this->DialsData.EcoDials = FMath::Clamp(TempEcoDial + amount, 0.f, 100.f);
	//Check if EcoDial > 80.f or < 20.f
}

const FDialsData& AGameJamProjectGameModeBase::GetDialsData() const
{
	return (this->DialsData);
}

FEventData AGameJamProjectGameModeBase::GetCurrentEventData() const
{
	if (this->CurrentEvent >= this->ArrayEventNum)
	{
		UE_LOG(LogGameJamProjectGameModeBase, Error, TEXT("Index Fail"));
		FEventData defaultData;
		return (defaultData);
	}
	return (this->EventArray[this->CurrentEvent]);
}

void AGameJamProjectGameModeBase::UpCurrentIndex()
{
	this->CurrentEvent++;
}

bool AGameJamProjectGameModeBase::IsCriticalDialsValue() const
{
	if (this->DialsData.FrogsDials <= 19.f || this->DialsData.FrogsDials >= 91.f)
		return (true);
	if (this->DialsData.WaterDials <= 19.f || this->DialsData.WaterDials >= 91.f)
		return (true);
	if (this->DialsData.CultDials <= 19.f || this->DialsData.CultDials >= 91.f)
		return (true);
	if (this->DialsData.EcoDials <= 19.f || this->DialsData.EcoDials >= 91.f)
		return (true);
	return (false);
}

bool AGameJamProjectGameModeBase::IsWinnerDialsValue() const
{
	if ((this->DialsData.EcoDials >= 80.f && this->DialsData.EcoDials <= 90.f) &&
		(this->DialsData.CultDials >= 80.f && this->DialsData.CultDials <= 90.f) &&
		(this->DialsData.WaterDials >= 80.f && this->DialsData.WaterDials <= 90.f) &&
		(this->DialsData.FrogsDials >= 80.f && this->DialsData.FrogsDials <= 90.f))
		return (true);
	return (false);
}

FText AGameJamProjectGameModeBase::GetWinnerText() const
{
	return (this->WinnerText);
}

FText AGameJamProjectGameModeBase::GetFailText() const
{
	return (this->FailText);
}

bool AGameJamProjectGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
	const auto TempResPause = Super::SetPause(PC, CanUnpauseDelegate);

	
	
	return (TempResPause);
}

bool AGameJamProjectGameModeBase::ClearPause()
{
	const auto TempResPause = Super::ClearPause();

	if (TempResPause)
		this->SetGameStat(EGameState::InProgress);

	return (TempResPause);
}

void AGameJamProjectGameModeBase::SetGameStat(EGameState GameStat)
{
	if (this->TempWaitToStart == GameStat) return;

	this->TempWaitToStart = GameStat;
	this->OnGame.Broadcast(GameStat);
}

void AGameJamProjectGameModeBase::StartEvent()
{
	if (this->ArrayEventNum == this->CurrentEvent || this->IsCriticalDialsValue() || this->IsWinnerDialsValue())
	{
		UE_LOG(LogGameJamProjectGameModeBase, Display, TEXT("====GAME OVER====="));
		if (GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(this->GameTimeHandler);
		}
		this->SetGameStat(EGameState::GameOver);
		return;
	}
	this->SetGameStat(EGameState::GameEvent);
}

