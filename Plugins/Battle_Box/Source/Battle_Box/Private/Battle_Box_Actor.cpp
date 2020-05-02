// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Battle_Box_Actor.h"
#include "../Public/ActionClasses/UCommandAction.h"
#include "../Public/ActionClasses/UItemAction.h"
#include "../Public/ActionClasses/UAbilityAction.h"
#include "../Public/ActionClasses/UBaseAction.h"
#include "Templates/Casts.h"


// Sets default values
ABattle_Box_Actor::ABattle_Box_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattle_Box_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}
//Creates and sends a order object to the receiver

void ABattle_Box_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UStatSheetObject* ABattle_Box_Actor::GetStatSheet() const
{
	return statSheet;
}

void ABattle_Box_Actor::SetStatSheet(UStatSheetObject* other_)
{
	statSheet = other_;
}