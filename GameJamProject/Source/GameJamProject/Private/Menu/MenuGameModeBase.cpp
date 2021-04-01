// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/MenuGameModeBase.h"
#include "Menu/GameJamMenuController.h"
#include "Menu/UI/GameJamHUD.h"

AMenuGameModeBase::AMenuGameModeBase()
{
	PlayerControllerClass = AGameJamMenuController::StaticClass();
	HUDClass = AGameJamHUD::StaticClass();
}
