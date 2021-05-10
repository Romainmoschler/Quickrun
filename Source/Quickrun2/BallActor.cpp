// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "Components/InputComponent.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	MyMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	MyMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABallActor::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("shoot", this, &ABallActor::shootBall)
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABallActor::shootBall(float value)
{
	if (value != 0.0f)
	{
		Fvector
	}
}