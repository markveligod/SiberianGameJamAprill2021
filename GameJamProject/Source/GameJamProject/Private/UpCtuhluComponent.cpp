// Fill out your copyright notice in the Description page of Project Settings.


#include "UpCtuhluComponent.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "GameJamProject/Public/AI/GameJamAICharacter.h"

// Sets default values for this component's properties
UUpCtuhluComponent::UUpCtuhluComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	this->CurrentActorZ = this->GamePosZStart;
}


// Called when the game starts
void UUpCtuhluComponent::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		const auto TempGameMode = GetWorld()->GetAuthGameMode<AGameJamProjectGameModeBase>();
		if (TempGameMode)
		{
			TempGameMode->UpCtuhlu.AddUObject(this, &UUpCtuhluComponent::OnUnderWater);
		}
	}
	
}

void UUpCtuhluComponent::OnUnderWater()
{
	UGameplayStatics::PlaySound2D(GetWorld(), this->Blewanul);
	this->bUnderWater = true;
	UE_LOG(LogTemp, Display, TEXT("BRODCAST IS DONE GO KTUHLU!!!"));
}

void UUpCtuhluComponent::GetUpUnderWater(float DeltaTime)
{
	FVector TempVectorLocal = GetOwner()->GetActorLocation();
	this->CurrentActorZ = FMath::Lerp(this->CurrentActorZ, this->GamePosZEnd, DeltaTime * this->PowerWater);
	FVector NewVectorLocal = FVector(TempVectorLocal.X, TempVectorLocal.Y, this->CurrentActorZ);
	GetOwner()->SetActorLocation(NewVectorLocal);
	if (this->CurrentActorZ >= this->GamePosZEnd)
	{
		this->bUnderWater = false;
		this->bIsStandUp = true;
	}
}


// Called every frame
void UUpCtuhluComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->bUnderWater)
	{
		this->GetUpUnderWater(DeltaTime);
	}
	if (this->bIsStandUp)
	{
		const auto CharacterKtuhlu = Cast<AGameJamAICharacter>(GetOwner());
		if (CharacterKtuhlu)
			CharacterKtuhlu->PlayAnimMontage(this->AnimStandUp);
		this->bIsStandUp = false;
	}
}

