// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpHramComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAMPROJECT_API UUpHramComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UUpHramComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OnUnderWater();
	void GetUpUnderWater(float DeltaTime);
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


		
};
