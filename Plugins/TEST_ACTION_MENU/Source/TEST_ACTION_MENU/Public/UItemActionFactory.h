#pragma once

#include "CoreMinimal.h"
#include "UnrealEd.h"
#include "UItemActionFactory.generated.h"


/**
 *
 */
UCLASS()
class UItemActionFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
		virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
