// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyTriggerBox.h"

ACPP_MyTriggerBox::ACPP_MyTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ACPP_MyTriggerBox::Event);
}


void ACPP_MyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_MyTriggerBox::Event(AActor * overlapActor, AActor * otherActor)
{
	if (otherActor && otherActor != this)
	{
		ball->FindComponentByClass<UStaticMeshComponent>();
		if (otherActor == ball)
		{
			UE_LOG(LogTemp, Error, TEXT("ACTOR is : %s"), *this->GetName());
			if (this->GetName() == "CPP_MyTriggerBox2")
			{
				scoreRed = scoreRed + 1;
			}
			else
			{
				scoreBlue = scoreBlue + 1;
			}
		}
	}
}

