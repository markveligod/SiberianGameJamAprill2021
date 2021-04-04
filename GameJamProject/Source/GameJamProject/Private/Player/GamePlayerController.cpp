// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GamePlayerController.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Player/PlayerPawn.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogGamePlayerController, All, All);

AGamePlayerController::AGamePlayerController()
{
	
}

void AGamePlayerController::BeginPlay()
{
	if (GetWorld())
	{
		const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
		if (TempGameMode)
		{
			TempGameMode->OnGame.AddUObject(this, &AGamePlayerController::OnGameState);
		}
	}
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
	
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!InputComponent)
		return;

	InputComponent->BindAction("Pause", IE_Pressed, this, &AGamePlayerController::OnPauseGame);
}

void AGamePlayerController::OnGameState(EGameState GameState)
{
	const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
	if (GameState == EGameState::InProgress)
	{
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
		TempGameMode->ClearPause();
	}
	else if (GameState == EGameState::Pause)
	{
		if (TempGameMode)
		{
			TempGameMode->SetPause(this);
		}
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
	}
	else
	{
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
	}
}


void AGamePlayerController::OnPauseGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
		return;
	const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
	TempGameMode->SetGameStat(EGameState::Pause);
}
