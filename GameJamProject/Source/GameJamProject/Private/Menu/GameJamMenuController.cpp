// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/GameJamMenuController.h"

void AGameJamMenuController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}
