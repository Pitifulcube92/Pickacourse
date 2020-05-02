// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UCommandAction.generated.h"
class UActorComponent;
/************************************
* Command Action Class
*
* This is a derived action class that
* contains information specified for command
* like actions. This specializes in containing
* Actor components that can be executed when called
* through an interaction.
*

************************************/

UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UCommandAction : public UBaseAction
{
	GENERATED_BODY()

public:
	///Command component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintType)
		TSubclassOf<UActionAlgorithmComponent> command;
};	
