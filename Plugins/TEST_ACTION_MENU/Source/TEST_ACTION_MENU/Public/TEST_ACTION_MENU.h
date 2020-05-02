// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SSpinBox.h"
//#include "Battle_Box_Enums.h"


class FToolBarBuilder;
class FMenuBuilder;
typedef TSharedPtr <FString>  FComboItemType;

class FTEST_ACTION_MENUModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();

private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	FReply OpenStatSheetTab();
	FReply OpenActionTab();
	FReply OpenActorTab();
	//
	TSharedPtr<FUICommandList> CommandList;

	TSharedPtr<const FExtender> Extender;
	ISlateStyle* slateStyle;

	/// Main Menu
	// Buttons
	TSharedPtr<SButton> ActionButton;
	TSharedPtr<SButton> StatSheetButton;
	//Button Text
	TSharedPtr<STextBlock> ActionButtonText;
	TSharedPtr<STextBlock> StatSheetButtonText;
	//Horisontal Box
	TSharedPtr<SHorizontalBox> ContentBox;
	TSharedPtr<SHorizontalBox> FillBox1;
	TSharedPtr<SHorizontalBox> FillBox2;
	/// </Main Menu

	//SComboBox 


	class ActionWindow* actionWindowRef;
	class StatSheetWindow* statSheetWindowRef;
	class Battle_Box_Actor_Windows* actorWindowRef;
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};