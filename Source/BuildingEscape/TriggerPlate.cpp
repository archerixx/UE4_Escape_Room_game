// Copyright ArcherX project 2018

#include "TriggerPlate.h"
#include "Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UTriggerPlate::UTriggerPlate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTriggerPlate::BeginPlay()
{
	Super::BeginPlay();
	
	Owner = GetOwner();
	if (!PressurePlate)
	{
	UE_LOG(LogTemp, Error, TEXT("%s is missing Pressure Plate"), *Owner->GetName());
	}
}

// Called every frame
void UTriggerPlate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		PullDown.Broadcast();
	}
	else 
	{
		PushUp.Broadcast();
	}
}

float UTriggerPlate::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	// Iterate trough them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}
	return TotalMass;
}