// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "UObject/UObjectBaseUtility.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"



// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();

	SetUpInput();
	
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerLocation;
	FRotator PlayerRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);

	

	//set Player reach
	

	//If the physics handle is attach
		//then moove object we are holding

	
		if (PhysicsHandle->GrabbedComponent)
		{
			PhysicsHandle->SetTargetLocation(PlayerLocation + PlayerRotation.Vector() *(reach / 2));
		}
	
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab is PRESSED"));

	//TODO only ray cast when key is pressed
	FVector PlayerLocation;
	FRotator PlayerRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);

	//set Player reach
	FVector LineTraceEnd = PlayerLocation + PlayerRotation.Vector() *reach;

	FHitResult hitResult = GetFirstPhysicsBodyInReach();


	//if true attach to physic handle
	if(hitResult.GetActor())
	{
		UPrimitiveComponent* componentToGrab = hitResult.GetComponent();
		PhysicsHandle->GrabComponentAtLocation(componentToGrab, NAME_None, LineTraceEnd);
	}
}

void UGrabber::Shoot()
{
	if (PhysicsHandle->GetGrabbedComponent())
	{
		UE_LOG(LogTemp, Warning, TEXT("Shoot the ball !"));
		PhysicsHandle->ReleaseComponent();
		//TODO Shot physics handle
	}
}

void UGrabber::FindPhysicsHandle()
{
	// Check for PhysicsHandleComponent
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{ 
		UE_LOG(LogTemp, Error, TEXT("No PhysicsHandle Found on : %s !"), *GetOwner()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No PhysicsHandle Found on : %s !"), *GetOwner()->GetName());
	}

}

void UGrabber::SetUpInput()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("InputComponent FOUND"), *GetOwner()->GetName());
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Shoot",IE_Released, this, &UGrabber::Shoot);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("InputComponent MISSING"));
	}

}
 
FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	//get Player Posiion and rotation
	FVector PlayerLocation;
	FRotator PlayerRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);

	//set Player reach
	FVector LineTraceEnd = PlayerLocation + PlayerRotation.Vector() *reach;

	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Object HIT is : %s"), *(ActorHit->GetName()));
	}
	return Hit;
}