// Copyright ArcherX project 2018

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

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

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PLayerViewPointRotation;
	// we added (defined) OUT so we can remind ourselves that this is out_location\out_rotaton, that is will change out parametars
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation,OUT PLayerViewPointRotation); 
	
	
	// Log out to test
	UE_LOG(LogTemp, Warning, TEXT("Position: %s, Direction: %s"), *PlayerViewPointLocation.ToString(), *PLayerViewPointRotation.ToString());
	// Ray-cast out to reach distance

	// See what we hit
}

