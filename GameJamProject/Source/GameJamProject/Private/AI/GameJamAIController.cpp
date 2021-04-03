// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GameJamAIController.h"
#include "AI/GameJamAICharacter.h"

void AGameJamAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const auto GameCharacter = Cast<AGameJamAICharacter>(InPawn);
	if (GameCharacter)
	{
		RunBehaviorTree(GameCharacter->Tree);
	}
}
