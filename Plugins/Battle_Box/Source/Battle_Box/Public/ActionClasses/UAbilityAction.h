// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UAbilityAction.generated.h"
class UBaseStatusEffect;
/************************************
*
* Ability Action Class
*
* This is a derived class that contains information
* for ability like actions. Within a Ability action,
* it conatins a mix of command action and item action like features,
* however is used for specificly for stat based
* abilities
*
* Ability Actions are uniqe because they can be used
* within a Command Action or Item Action.
*
************************************/

UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UAbilityAction : public UBaseAction
{
	GENERATED_BODY()

public:
	///Duration value (can used if needed)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Action")
		float duration;
	///An array that contains the status effect objects.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Action")
		TArray<UBaseStatusEffect*> effects;
};
