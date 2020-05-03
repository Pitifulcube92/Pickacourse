// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UBaseStatusEffect.generated.h"

/**
* 
* Base Status Effect Class
*
* This is a base class that will contain effect status,
* the effect status is similar to base action algorithm but 
* is used to make a effects specifically for statsheet stats.
*
*
* NOTE: Using the name of the status effect to comapare with the 
* stat map in the statsheet helps confirm that the system can use that 
* value.
*
 */
UCLASS(Blueprintable, BlueprintType, Category= "Status_Effect")
class BATTLE_BOX_API UBaseStatusEffect : public UObject
{
	GENERATED_BODY()
public:
	///Effect's name 
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		FString effectName;
	///Effects's given value, used for any additional methods or as a default status
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		float effectValue;
	///Effect's given multiplier, used for any additional methods or as a default status
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		float effectMultipler;
	///This is the discription of the effect
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		FString effectDiscription;
	///This is a callback method for any methods given to the derived class;
	UFUNCTION(BlueprintCallable)
		virtual void CallEffect() PURE_VIRTUAL(UBaseStatusEffect::CallEffect, ;);
};
	
