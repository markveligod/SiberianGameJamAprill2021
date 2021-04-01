// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameBaseHUD.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class MatchState : uint8
{
    InProgress = 0,
    Pause,
    GameOver
};

UCLASS()
class GAMEJAMPROJECT_API AGameBaseHUD : public AHUD
{
	GENERATED_BODY()
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> PlayerHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> PauseHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> GameOverHudWidgetClass;

	virtual void BeginPlay() override;

private:
    UPROPERTY()
        TMap<MatchState, UUserWidget*> GameWidgets;

    UPROPERTY()
        UUserWidget* CurrentWidget;
};
