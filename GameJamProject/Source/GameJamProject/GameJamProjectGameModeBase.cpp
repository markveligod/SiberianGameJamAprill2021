// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameJamProjectGameModeBase.h"
#include "Player/PlayerPawn.h"
#include "HUD/GameBaseHUD.h"
#include "Player/GamePlayerController.h"

AGameJamProjectGameModeBase::AGameJamProjectGameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	HUDClass = AGameBaseHUD::StaticClass();
	PlayerControllerClass = AGamePlayerController::StaticClass();
}

void AGameJamProjectGameModeBase::StartPlay()
{
	Super::StartPlay();
}
