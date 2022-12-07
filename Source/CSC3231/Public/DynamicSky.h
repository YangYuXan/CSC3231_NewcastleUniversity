// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SkyMode.h"
#include "CoreMinimal.h"
#include "Components/VolumetricCloudComponent.h"
#include "GameFramework/Actor.h"
#include "DynamicSky.generated.h"

UCLASS()
class CSC3231_API ADynamicSky : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamicSky();
	
	ESkyMode skyMode=ESkyMode::VE_VolumeCloud;

	UPROPERTY(EditAnywhere)
	float PitchValue;

	UPROPERTY(EditAnywhere)
	float YawValue;

	UPROPERTY(EditAnywhere)
	float RollValue;
	
	UPROPERTY(EditAnywhere)
	FRotator NewRotation;

	UPROPERTY(EditAnywhere)
	bool timeRunning;

	void ChangeTime();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	

	UPROPERTY(VisibleAnywhere)
	class UVolumetricCloudComponent* volumeCloud;

	UPROPERTY(VisibleAnywhere)
	class UDirectionalLightComponent* Sun;

	UPROPERTY(VisibleAnywhere)
	class USkyLightComponent* skyLight;

	UPROPERTY(VisibleAnywhere)
	class USkyAtmosphereComponent* skyAtmosphereComponent;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* skySphere;

	UPROPERTY(VisibleAnywhere)
	class UExponentialHeightFogComponent * heightFog;

	UPROPERTY(VisibleAnywhere)
	class UPostProcessComponent * processComponent;
	
	
	
	

};
