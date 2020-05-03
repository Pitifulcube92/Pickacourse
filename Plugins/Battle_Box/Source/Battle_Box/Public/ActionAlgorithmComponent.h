// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionAlgorithmComponent.generated.h"
class UStatSheetObject;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_BOX_API UActionAlgorithmComponent : public UObject 
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionAlgorithmComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Algorithm")
		UStatSheetObject* target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Algorithm")
		UStatSheetObject* owner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Algorithm")
		FString actionName;
public:	
///This calls the whole algorithm 
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Action Algorithm")
		void CallAlgorithm();
///This initialize the algorithum
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		void Init(FString actionName_, UStatSheetObject* target_, UStatSheetObject* owner_);
};
