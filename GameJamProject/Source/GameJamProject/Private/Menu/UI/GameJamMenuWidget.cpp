// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/GameJamMenuWidget.h"
#include "Components/Button.h"
#include "GameJamGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameJamMenuWidget, All, All);

void UGameJamMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!this->StartGameButton || !this->AboutGameButton || !this->QuitGameButton)
    {
        UE_LOG(LogGameJamMenuWidget, Error, TEXT("Func: NativeOnInitialized nullptr"));
        return;
    }

    this->StartGameButton->OnClicked.AddDynamic(this, &UGameJamMenuWidget::OnStartGame);
    this->AboutGameButton->OnClicked.AddDynamic(this, &UGameJamMenuWidget::OnAboutGame);
    this->QuitGameButton->OnClicked.AddDynamic(this, &UGameJamMenuWidget::OnQuitGame);
}

void UGameJamMenuWidget::OnStartGame()
{
    if (!GetWorld())
        return;

    const auto GameInstance = GetWorld()->GetGameInstance<UGameJamGameInstance>();

    if (!GameInstance)
        return;

    if (GameInstance->GetNameStartUpLevel().IsNone())
    {
        UE_LOG(LogGameJamMenuWidget, Error, TEXT("Level name is NONE"));
        return;
    }
    UGameplayStatics::OpenLevel(this, GameInstance->GetNameStartUpLevel());
    UE_LOG(LogGameJamMenuWidget, Display, TEXT("Open Level is Done!"));
}

void UGameJamMenuWidget::OnAboutGame()
{
    this->bIsAboutVisible = true;
    UE_LOG(LogGameJamMenuWidget, Display, TEXT("bIsAboutVisible is true!"));
}

void UGameJamMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
    UE_LOG(LogGameJamMenuWidget, Display, TEXT("GoodBye!"));
}

