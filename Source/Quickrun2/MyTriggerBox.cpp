// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerBox::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Object TRIGGER is : %s"), *(OtherActor->GetName()));
		
}