// Fill out your copyright notice in the Description page of Project Settings.


#include "UStatSheetFactory.h"
#include "../UStatSheetObject.h"
#define LOCTEXT_NAMESPACE "UStatSheetObject"
/////////////////////////////////////////////////////
// UMyObjectFactory


UStatSheetFactory::UStatSheetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UStatSheetObject::StaticClass();

}

UObject* UStatSheetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UStatSheetObject* NewObjectAsset = NewObject<UStatSheetObject>(InParent, Name, Flags);
	//NewObject(Class,InParent)
	return NewObjectAsset;
	//ConstrucObject(UDataAssetObject::StaticClass(), InParent, Name, Flags);
}

#undef LOCTEXT_NAMESPACE