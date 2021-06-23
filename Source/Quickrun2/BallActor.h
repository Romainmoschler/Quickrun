// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Engine/StaticMesh.h"
#include "BallActor.generated.h"

UCLASS()
class QUICKRUN2_API ABallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MyMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/*virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;*/


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void shootBall(float value);
	
};
