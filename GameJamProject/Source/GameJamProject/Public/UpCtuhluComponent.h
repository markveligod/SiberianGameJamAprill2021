// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpCtuhluComponent.generated.h"

class USoundCue;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAMPROJECT_API UUpCtuhluComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	UUpCtuhluComponent();
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* Blewanul;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Anim")
		UAnimMontage* AnimStandUp;
	
private:
	bool bUnderWater = false;
	float CurrentActorZ;
	bool bIsStandUp = false;


	
};
