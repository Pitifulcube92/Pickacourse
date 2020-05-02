// Fill out your copyright notice in the Description page of Project Settings.


#include "UBattle_Box_Character_Factory.h"
#include "../Battle_Box_Character.h"
#define LOCTEXT_NAMESPACE "Battle_Box_Character"


UBattle_Box_Character_Factory::UBattle_Box_Character_Factory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = LOCTEXT("Name", "BattleBoxCharacter");
	NewActorClass = ABattle_Box_Character::StaticClass();
	SpawnPositionOffset = FVector(50, 0, 0);
	bUseSurfaceOrientation = true;
}

#undef LOCTEXT_NAMESPACE