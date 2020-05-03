// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Battle_Box_Character.generated.h"

class UStatSheetObject;

UCLASS()
class BATTLE_BOX_API ABattle_Box_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABattle_Box_Character();
public: 
	///StatSheetObject
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStatSheetObject* statSheet;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	///Returns StatSheetObject
	UFUNCTION(BlueprintCallable, Category = "Battle_Box_Character")
		UStatSheetObject* GetStatSheet() const;
	///Sets  StatSheetObject 
	UFUNCTION(BlueprintCallable, Category = "Battle_Box Actor")
		void SetStatSheet(UStatSheetObject* other_);
};
