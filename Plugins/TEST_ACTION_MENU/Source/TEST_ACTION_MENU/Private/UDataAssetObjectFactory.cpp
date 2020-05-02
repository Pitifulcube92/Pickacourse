//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "UDataAssetObjectFactory.h"
//#include "UDataAssetObject.h"
//#define LOCTEXT_NAMESPACE "DataAssetObject"
///////////////////////////////////////////////////////
//// UMyObjectFactory
//
//
//UDataAssetObjectFactory::UDataAssetObjectFactory(const FObjectInitializer& ObjectInitializer)
//	: Super(ObjectInitializer)
//{
//	bCreateNew = true;
//	bEditAfterNew = true;	
//	SupportedClass = UDataAssetObject::StaticClass();
//
//}
//
//UObject* UDataAssetObjectFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
//{
//	UDataAssetObject* NewObjectAsset = NewObject<UDataAssetObject>( InParent, Name, Flags);
//	//NewObject(Class,InParent)
//	return NewObjectAsset;
//	//ConstrucObject(UDataAssetObject::StaticClass(), InParent, Name, Flags);
//}
//
//#undef LOCTEXT_NAMESPACE