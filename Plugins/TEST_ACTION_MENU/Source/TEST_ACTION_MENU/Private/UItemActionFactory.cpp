#include "UItemActionFactory.h"
#include "../ActionClasses/UItemAction.h"
#define LOCTEXT_NAMESPACE "UItemAction"


UItemActionFactory::UItemActionFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UItemAction::StaticClass();

}

UObject* UItemActionFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UItemAction* NewObjectAsset = NewObject<UItemAction>(InParent, Name, Flags);
	return NewObjectAsset;
}

#undef LOCTEXT_NAMESPACE