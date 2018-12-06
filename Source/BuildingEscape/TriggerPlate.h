// Copyright ArcherX project 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "TriggerPlate.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTriggerPlateEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTriggerPlate : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTriggerPlate();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable)
		FTriggerPlateEvent PullDown;
	UPROPERTY(BlueprintAssignable)
		FTriggerPlateEvent PushUp ;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere)
		float TriggerMass = 20.f;

	AActor* Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();
};
