// Fill out your copyright notice in the Description page of Project Settings.


#include "VBall.h"
#include "Components/SphereComponent.h"

// Sets default values
AVBall::AVBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>("CollisionSphere");
	RootComponent = CollisionSphere;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>("BallMesh");
	BallMesh->SetupAttachment(RootComponent);
}

void AVBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

