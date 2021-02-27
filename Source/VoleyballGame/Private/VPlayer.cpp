// Fill out your copyright notice in the Description page of Project Settings.


#include "VPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AVPlayer::AVPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetMesh());

	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>("PlayerMesh");
	PlayerMesh->SetupAttachment(Camera);

	ArmMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ArmMesh");
	ArmMesh->SetupAttachment(Camera);

	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandMesh");
	HandMesh->SetupAttachment(Camera);

	Collision = CreateDefaultSubobject<USphereComponent>("Collision");
	Collision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AVPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->SetActive(false);
}

void AVPlayer::MoveForward(float Value)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AVPlayer::MoveRight(float Value)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AVPlayer::Throw()
{
	/*Collision->SetActive(true);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AVPlayer::OnThrow, 2.0f, false);*/
}

void AVPlayer::OnThrow()
{
	/*Collision->SetActive(false);*/
}

// Called every frame
void AVPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void AVPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AVPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AVPlayer::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &AVPlayer::Throw);
}

