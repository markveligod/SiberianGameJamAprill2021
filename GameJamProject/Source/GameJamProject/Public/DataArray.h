#pragma once
#include "DataArray.generated.h"

//Status Visible Widget and proccess game

UENUM(BlueprintType)
enum class EGameState : uint8
{
    WaitingToStart = 0,
	Welcome,
    InProgress ,
	GameEvent,
    Pause,
    GameOver
};

// Delegat for call change State
DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameState, EGameState);

//Struct Dials data

USTRUCT(BlueprintType)
struct FDialsData
{
    GENERATED_USTRUCT_BODY();
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dials", meta = (ClampMin = "0.0", ClampMax = "100.0"))
        float WaterDials = 25.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dials", meta = (ClampMin = "0.0", ClampMax = "100.0"))
        float FrogsDials = 25.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dials", meta = (ClampMin = "0.0", ClampMax = "100.0"))
        float CultDials = 25.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dials", meta = (ClampMin = "0.0", ClampMax = "100.0"))
        float EcoDials = 25.f;

};


//Struct Event
USTRUCT(BlueprintType)
struct FEventData
{
    GENERATED_USTRUCT_BODY();
	
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Text Event")
    FText TextEvent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Confirm", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountConfirmEco = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Confirm", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountConfirmWater = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Confirm", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountConfirmCult = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Confirm", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountConfirmFrog = 5.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Decress", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountDecressEco = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Decress", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountDecressWater = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Decress", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountDecressCult = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Value Decress", meta = (ClampMin = "-25.0", ClampMax = "25.0"))
        float AmountDecressFrog = 5.f;
};
