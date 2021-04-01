// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GamePlayerController.h"

void AGamePlayerController::BeginPlay()
{
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
