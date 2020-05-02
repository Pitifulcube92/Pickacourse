

#include "UCommandActionFactory.h"
#include "../ActionClasses/UCommandAction.h"
#define LOCTEXT_NAMESPACE "UCommandAction"
/////////////////////////////////////////////////////
// UMyObjectFactory


UCommandActionFactory::UCommandActionFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UCommandAction::StaticClass();

}

UObject* UCommandActionFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UCommandAction* NewObjectAsset = NewObject<UCommandAction>(InParent, Name, Flags);
	return NewObjectAsset;
}

#undef LOCTEXT_NAMESPACE