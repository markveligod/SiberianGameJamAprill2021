// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameJamGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMPROJECT_API UGameJamGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	const FName& GetNameStartUpLevel() const;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Name Levels")
		FName StartUpLevel = NAME_None;
};
