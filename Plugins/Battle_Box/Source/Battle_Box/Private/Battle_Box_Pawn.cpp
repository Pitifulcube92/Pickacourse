// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle_Box_Pawn.h"
#include "UStatSheetObject.h"

// Sets default values
ABattle_Box_Pawn::ABattle_Box_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattle_Box_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattle_Box_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattle_Box_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UStatSheetObject* ABattle_Box_Pawn::GetStatSheet() const
{
	return statSheet;
}

void ABattle_Box_Pawn::SetStatSheet(UStatSheetObject* other_)
{
	statSheet = other_;
}