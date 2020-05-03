// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealEd.h"
#include "UStatSheetFactory.generated.h"


/**
 *
 */
UCLASS()
class UStatSheetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
		virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
