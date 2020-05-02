// Fill out your copyright notice in the Description page of Project Settings.

#include "UBattle_Box_Actor_Factory.h"
#include "../Battle_Box_Actor.h"
#define LOCTEXT_NAMESPACE "Battle_Box_Actor"


UBattle_Box_Actor_Factory::UBattle_Box_Actor_Factory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = LOCTEXT("Name", "BattleBoxActor");
	NewActorClass = ABattle_Box_Actor::StaticClass();
	SpawnPositionOffset = FVector(50, 0, 0);
	bUseSurfaceOrientation = true;
}

#undef LOCTEXT_NAMESPACE