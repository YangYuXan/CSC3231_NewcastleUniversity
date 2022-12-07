// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SkyMode.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum  class ESkyMode: uint8
{
	VE_VolumeCloud	UMETA(Displayname = "VolumeCloud"),
	VE_NoCloud	UMETA(Displayname = "NoCloud"),
	VE_2D_Cloud UMETA(Displayname = "2D Cloud")
};