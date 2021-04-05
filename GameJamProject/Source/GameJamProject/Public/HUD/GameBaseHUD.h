// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DataArray.h"
#include "GameBaseHUD.generated.h"

class UGameJamBaseWidget;
class USoundCue;
/**
 * 
 */

UCLASS()
class GAMEJAMPROJECT_API AGameBaseHUD : public AHUD
{
	GENERATED_BODY()
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UGameJamBaseWidget> PlayerHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UGameJamBaseWidget> GameWelcomeHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UGameJamBaseWidget> GameEventHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UGameJamBaseWidget> ResultHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UGameJamBaseWidget> PauseHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UGameJamBaseWidget> GameOverHudWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
        USoundCue* WinSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
        USoundCue* LoseSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
        USoundCue* ResultSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
        USoundCue* PickPuck;

	virtual void BeginPlay() override;

private:
    UPROPERTY()
        TMap<EGameState, UGameJamBaseWidget*> GameWidgets;

    UPROPERTY()
        UGameJamBaseWidget* CurrentWidget;

    void OnGameState(EGameState GameState);
};
