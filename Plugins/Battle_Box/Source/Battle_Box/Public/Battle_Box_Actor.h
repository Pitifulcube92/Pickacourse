// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/Delegate.h"
#include "Battle_Box_Actor.generated.h"

class UStatSheetObject;

UCLASS(config=Engine, meta = (ShortTooltip = "Testing if this works."))
class BATTLE_BOX_API ABattle_Box_Actor : public AActor
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStatSheetObject* statSheet;

	// Sets default values for this actor's properties
	ABattle_Box_Actor();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	///Returns StatSheetObject
	UFUNCTION(BlueprintCallable, Category = "Battle_Box Actor")
		UStatSheetObject* GetStatSheet() const;
	///Sets StatSheetObject
	UFUNCTION(BlueprintCallable, Category = "Battle_Box Actor")
		void SetStatSheet(UStatSheetObject* other_);
};
