// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "GameJamProject/GameJamProjectGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/GamePlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(LogPlayerPawn, All, All);

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create sphere, camera and spring arm component
	this->SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere Component");
	SetRootComponent(this->SphereComponent);
	this->SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring arm Component");
	this->SpringArmComponent->SetupAttachment(GetRootComponent());
	this->CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	this->CameraComponent->SetupAttachment(this->SpringArmComponent);
	UE_LOG(LogPlayerPawn, Display, TEXT("Create Sphere, Camera and Spring Arm Component"));
	
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	check(this->SpringArmComponent);
	check(this->CameraComponent);
}



// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("RightButton",this, &APlayerPawn::MoveRight);
	}
}

void APlayerPawn::MoveRight(float amount)
{
	const auto TempTransform = this->SpringArmComponent->GetComponentTransform();
	const auto TempRotator = TempTransform.Rotator();
	const auto NewRotator = FRotator(TempRotator.Pitch, TempRotator.Yaw + amount, TempRotator.Roll);
	this->SpringArmComponent->SetRelativeRotation(NewRotator);
}



