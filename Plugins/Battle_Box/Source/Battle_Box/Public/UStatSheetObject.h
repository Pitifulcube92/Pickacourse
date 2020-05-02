// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "Engine/DataAsset.h"
#include "UStatSheetObject.generated.h"

class UItemAction;
class UCommandAction;
class UAbilityAction;
struct StatSheetData;
/*
*
* StatSheetObject Class
*
* This class is one of the key data structs that contains all the 
* info needed. It contains to major Structures: Action Info & General Info
*
* Action Info: Conatins all the action refrences and action data 
* that this stat sheet have.
*
* General Info: Contains all the general refrences of the stat sheet.
*
*/

UCLASS(Blueprintable, BlueprintType, Category = "StatSheet")
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
public:
	///StatSheetObject Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Info")
		FString name;
	///StatSheetObject Tag
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Info")
		FString tag;
	///StatSheetObject additional Stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Info")
		TMap<FString, float> additionlStats;
	///Command Action Map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UCommandAction*> commandMap;
	///Item Action Map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UItemAction*> itemMap;
	///Ability Action Map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UAbilityAction*> abilityMap;
	///Equipment Map (Sub Item Action map)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UItemAction*> equipmentMap;
};
