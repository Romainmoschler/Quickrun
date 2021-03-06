// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "DrawDebugHelpers.h"
#include "Math/Color.h"
#include "Engine/World.h"
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

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}