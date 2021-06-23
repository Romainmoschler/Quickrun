// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TriggerBox.h"
#include "CPP_MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class QUICKRUN2_API ACPP_MyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();

public:
	ACPP_MyTriggerBox();

	UFUNCTION()
		void Event(class AActor* overlapActor, class AActor* otherActor);

	UPROPERTY(EditAnywhere)
		AActor* ball;

	int scoreBlue = 0;
	int scoreRed = 0;
};
