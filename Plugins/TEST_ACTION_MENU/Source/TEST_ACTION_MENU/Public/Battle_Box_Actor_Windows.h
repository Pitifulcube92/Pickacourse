// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/SWindow.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"


/**
 * 
 */
class TEST_ACTION_MENU_API Battle_Box_Actor_Windows : public IModuleInterface
{
public:
	TSharedRef<class SDockTab> generateWidow(const class FSpawnTabArgs& TabSpawnArgs);
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void Button_Clicked();
	TSharedPtr<SEditableTextBox>actorName;

	FReply CreateCharacterObject();
	FReply CreatePawnObject();
	FReply CreateActorObject();
	TArray<FString> contentFiles;

	//search function to find all the files in directory
	void FindFiles();
};
