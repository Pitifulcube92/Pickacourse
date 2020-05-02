// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"

UENUM(BlueprintType)
enum class  ACTIONTYPE : uint8
{
	E_NONE ,
	E_COMMAND ,
	E_ITEM ,
	E_ABILITY
};

UENUM(BlueprintType)
enum class  TARGETTYPE : uint8
{
	E_NONE,
	E_TARGET_ENEMY,
	E_ALL_ENEMIES,
	E_RANDOM_ENEMY,
	E_ALLY,
	E_ALL_ALLY,
	E_ALLY_KO,
	E_ALL_ALLY_KO,
	E_USER
};

UENUM(BlueprintType)
enum class  INTERACTIONTYPE : uint8
{
	E_NONE,
	E_PHYSICAL,
	E_ABILITY,
	E_PHYSICAL_AND_ABILITY
};

UENUM(BlueprintType)
enum class STATACTION : uint8
{
	E_NONE,
	E_ADD,
	E_REMOVE,
	E_TMP_ADD,
	E_TMP_REMOVE
};


UENUM(BlueprintType)
enum class  ITEMTYPE : uint8
{
	E_NONE,
	E_CONSUMABLE,
	E_ARMOR,
	E_WEAPON,
	E_KEY_ITEM
};

UENUM(BlueprintType)
enum class  MessageType : uint8
{
	E_NONE,
	E_INFO,
	E_WARNING,
	E_ERROR,
	E_FATAL_ERROR
};
