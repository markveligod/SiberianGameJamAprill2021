// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Public/DataArray.h"
#include "GameJamProjectGameModeBase.generated.h"

class AGameJamAICharacter;
/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API AGameJamProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	FOnGameState OnGame;
	
	AGameJamProjectGameModeBase();

	virtual void StartPlay() override;

	void ChangeWaterDialData(float amount);
	void ChangeFrogsDialData(float amount);
	void ChangeCultsDialData(float amount);
	void ChangeEcoDialData(float amount);
	const FDialsData& GetDialsData() const;
	FEventData GetCurrentEventData() const;
	void UpCurrentIndex();
	bool IsCriticalDialsValue() const;
	bool IsWinnerDialsValue() const;
	FText GetWinnerText() const;
	FText GetFailText() const;
	void ChangeResultOne();
	void ChangeResultTwo();

	void SetGameStat(EGameState GameStat);

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	virtual bool ClearPause() override;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Dials Data")
	FDialsData DialsData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Array Text Block")
		TArray<FEventData> EventArray;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Time Event", meta = (ClampMin = "1.0", ClampMax = "120.0"))
		float TimeEvent = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Param")
		FText DefaultText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Param")
		FText WinnerText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Param")
		FText FailText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CTUHLU")
		AGameJamAICharacter* CtuhluCharacter;

private:
	EGameState TempWaitToStart = EGameState::WaitingToStart;
	FTimerHandle GameTimeHandler;
	int32 ArrayEventNum = 0;
	int32 CurrentEvent = 0;

	void StartEvent();
};


