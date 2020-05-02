// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAlgorithmComponent.h"
UActionAlgorithmComponent::UActionAlgorithmComponent()
{

}

void UActionAlgorithmComponent::Init(FString actionName_, UStatSheetObject* target_, UStatSheetObject* owner_)
{
	target = target_;
	actionName = actionName_;
	owner = owner_;
}