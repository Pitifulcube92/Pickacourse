#pragma once

#include "CoreMinimal.h"
#include "UnrealEd.h"
#include "UCommandActionFactory.generated.h"


/**
 *
 */
UCLASS()
class UCommandActionFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
		virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
