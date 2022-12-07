// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicSky.h"

#include <string>

#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/SkyLightComponent.h"
#include "Engine/Engine.h"
#include "Materials/MaterialExpressionChannelMaskParameter.h"

// Sets default values
ADynamicSky::ADynamicSky()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PitchValue = 0.1f;
	YawValue = 0.1f;
	RollValue = 0.1f;

	//Open or Close day and night cycle
	timeRunning = false;

	//Set Volume Cloud
	volumeCloud=CreateDefaultSubobject<UVolumetricCloudComponent>(TEXT("Volume Cloud"));
	//Set Sun light
	Sun=CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun"));
	//Create Sky Light
	skyLight=CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight"));
	//Create SkyAtmosphereComponent
	skyAtmosphereComponent = CreateDefaultSubobject<USkyAtmosphereComponent>(TEXT("SkyAtmosphere"));
	//Create SkySphere
	skySphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkySphere"));
	//Create ExponentialHeightFogComponent
	heightFog = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("HeightFog"));
	//Create PostProcess
	processComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
}

// Called when the game starts or when spawned
void ADynamicSky::BeginPlay()
{
	Super::BeginPlay();
	NewRotation = Sun->GetRelativeRotation();
}

// Called every frame
void ADynamicSky::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ChangeTime();
	
}

void ADynamicSky::ChangeTime()
{

	if(timeRunning==true)
	{
		NewRotation.Pitch += PitchValue;
        	NewRotation.Yaw += YawValue;
        	NewRotation.Roll += RollValue;
        
        	Sun->SetWorldRotation(NewRotation);
	}
	
	
}




