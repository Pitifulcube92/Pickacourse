// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle_Box_Character.h"
#include "UStatSheetObject.h"

// Sets default values
ABattle_Box_Character::ABattle_Box_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattle_Box_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattle_Box_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattle_Box_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UStatSheetObject* ABattle_Box_Character::GetStatSheet() const
{
	return statSheet;
}

void ABattle_Box_Character::SetStatSheet(UStatSheetObject* other_)
{
	statSheet = other_;
}