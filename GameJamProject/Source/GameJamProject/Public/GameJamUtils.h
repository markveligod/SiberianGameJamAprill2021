#pragma once

#include "Engine/World.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"

class GameJamUtils
{
public:
	static AGameJamProjectGameModeBase* GetGameJamGameMode();
};

inline AGameJamProjectGameModeBase* GameJamUtils::GetGameJamGameMode()
{
	return (GetWorld() ? Cast<AGameJamProjectGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr);
}
