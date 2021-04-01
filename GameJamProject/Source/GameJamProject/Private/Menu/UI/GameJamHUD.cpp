// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/GameJamHUD.h"
#include "Blueprint/UserWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameJamHUD, All, All);

void AGameJamHUD::BeginPlay()
{
	Super::BeginPlay();

	if (this->MenuWidget)
	{
		const auto TempWidget = CreateWidget<UUserWidget>(GetWorld(), this->MenuWidget);
		if (TempWidget)
		{
			TempWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogGameJamHUD, Error, TEXT("Temp Widget not ptr!"));
		}
	}
	else
	{
		UE_LOG(LogGameJamHUD, Error, TEXT("Menu Widget doesn't found"));
	}
}
