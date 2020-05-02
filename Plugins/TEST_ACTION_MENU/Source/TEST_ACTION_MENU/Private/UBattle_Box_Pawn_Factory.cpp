// Fill out your copyright notice in the Description page of Project Settings.


#include "UBattle_Box_Pawn_Factory.h"
#include "../Battle_Box_Pawn.h"
#define LOCTEXT_NAMESPACE "Battle_Box_Pawn"


UBattle_Box_Pawn_Factory::UBattle_Box_Pawn_Factory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = LOCTEXT("Name", "BattleBoxPawn");
	NewActorClass = ABattle_Box_Pawn::StaticClass();
	SpawnPositionOffset = FVector(50, 0, 0);
	bUseSurfaceOrientation = true;
}

#undef LOCTEXT_NAMESPACE
