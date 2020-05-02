#include "UAbiltiyActionFactory.h"
#include "ActionClasses/UAbilityAction.h"
#define LOCTEXT_NAMESPACE "UAbilityAction"
/////////////////////////////////////////////////////
// UMyObjectFactory


UAblityActionFactory::UAblityActionFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UAbilityAction::StaticClass();

}

UObject* UAblityActionFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UAbilityAction* NewObjectAsset = NewObject<UAbilityAction>(InParent, Name, Flags);
	return NewObjectAsset;
}

#undef LOCTEXT_NAMESPACE