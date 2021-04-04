// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnderWaterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAMPROJECT_API UUnderWaterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnderWaterComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Param Water")
		float GamePosZStart;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Param Water")
		float GamePosZEnd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Param Water")
		float PowerWater;
	
private:
	bool bUnderWater = false;
	float CurrentActorZ;

	void OnUnderWater();
	void GetUpUnderWater(float DeltaTime);
};
