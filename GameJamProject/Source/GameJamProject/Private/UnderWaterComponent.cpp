// Fill out your copyright notice in the Description page of Project Settings.


#include "UnderWaterComponent.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values for this component's properties
UUnderWaterComponent::UUnderWaterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	this->CurrentActorZ = this->GamePosZStart;
}

// Called when the game starts
void UUnderWaterComponent::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
		if (TempGameMode)
		{
			TempGameMode->UnderWater.AddUObject(this, &UUnderWaterComponent::OnUnderWater);
		}
	}
	
}

void UUnderWaterComponent::OnUnderWater()
{
	this->bUnderWater = true;
	UE_LOG(LogTemp, Display, TEXT("BRODCAST IS DONE GO UNDER WATER!!!"));
	UGameplayStatics::PlaySound2D(GetWorld(), this->WaterDownSound);

}

void UUnderWaterComponent::GetUpUnderWater(float DeltaTime)
{
	FVector TempVectorLocal = GetOwner()->GetActorLocation();
	this->CurrentActorZ = TempVectorLocal.Z;
	this->CurrentActorZ = FMath::Lerp(this->CurrentActorZ, this->GamePosZEnd, DeltaTime * this->PowerWater);
	FVector NewVectorLocal = FVector(TempVectorLocal.X, TempVectorLocal.Y, this->CurrentActorZ);
	GetOwner()->SetActorLocation(NewVectorLocal);
	if (this->CurrentActorZ >= this->GamePosZEnd)
		this->bUnderWater = false;
}

// Called every frame
void UUnderWaterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->bUnderWater)
	{
		this->GetUpUnderWater(DeltaTime);
	}
}

