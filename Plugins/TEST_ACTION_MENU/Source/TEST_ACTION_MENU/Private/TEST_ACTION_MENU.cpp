// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TEST_ACTION_MENU.h"
#include "TEST_ACTION_MENUStyle.h"
#include "TEST_ACTION_MENUCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "SlateBasics.h"
// Window Files
#include "StatSheetWindow.h"
#include "Battle_Box_Actor_Windows.h"
#include "ActionWindow.h"



static const FName TEST_ACTION_MENUTabName("Battle Box Creation Menus");


#define LOCTEXT_NAMESPACE "FTEST_ACTION_MENUModule"

//Start up Moduel
void FTEST_ACTION_MENUModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FTEST_ACTION_MENUStyle::Initialize();
	FTEST_ACTION_MENUStyle::ReloadTextures();

	FTEST_ACTION_MENUCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTEST_ACTION_MENUCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTEST_ACTION_MENUModule::PluginButtonClicked),
		FCanExecuteAction());

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FTEST_ACTION_MENUModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FTEST_ACTION_MENUModule::AddToolbarExtension));

		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TEST_ACTION_MENUTabName, FOnSpawnTab::CreateRaw(this, &FTEST_ACTION_MENUModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTEST_ACTION_MENUTabTitle", "Battle Box Creation Menu"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	actionWindowRef = new ActionWindow();
	statSheetWindowRef = new StatSheetWindow();
	actorWindowRef = new Battle_Box_Actor_Windows();
	actionWindowRef->StartupModule();
	statSheetWindowRef->StartupModule();
	actorWindowRef->StartupModule();

}
//Shutdown Moduel
void FTEST_ACTION_MENUModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FTEST_ACTION_MENUStyle::Shutdown();

	FTEST_ACTION_MENUCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TEST_ACTION_MENUTabName);
	actionWindowRef->ShutdownModule();
	statSheetWindowRef->ShutdownModule();
	actorWindowRef->ShutdownModule();
}
//Stat window 
TSharedRef<SDockTab> FTEST_ACTION_MENUModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FTEST_ACTION_MENUModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("TEST_ACTION_MENU.cpp"))
	);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			//.Padding(1.0f, 1.0f)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.Padding(10,0,10,10)
				[
					SNew(SVerticalBox)

					+SVerticalBox::Slot()
					.Padding(0,0,0,10)
					//.FillHeight()
						[
						SAssignNew(ActionButton, SButton) // Action Button
						.OnClicked_Raw(this,  &FTEST_ACTION_MENUModule::OpenActionTab)
							[
							SNew(SBorder)
							.Padding(FMargin(3))
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Content()
								[
								SAssignNew(ActionButtonText, STextBlock)
								.Text(LOCTEXT("Action", "Create Action Menu"))
								.AutoWrapText(true)
								] // Border content end

							]// Button end

						]// vertical box slot end
					+ SVerticalBox::Slot()
					.Padding(0, 0, 0, 10)
						[
						SAssignNew(StatSheetButton, SButton)
						.OnClicked_Raw(this, &FTEST_ACTION_MENUModule::OpenStatSheetTab)
							[
							SNew(SBorder)
							.Padding(FMargin(3))
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Content()
								[
								SAssignNew(StatSheetButtonText, STextBlock)
								.Text(LOCTEXT("StatSheet", "Create StatSheet Menu"))
								.AutoWrapText(true)
								] // Border content end

							]// Button end
						]// Vertical Box Slot
					+ SVerticalBox::Slot()
						.Padding(0, 0, 0, 10)
						[
							SNew(SButton)
							.OnClicked_Raw(this, &FTEST_ACTION_MENUModule::OpenActorTab)
						[
							SNew(SBorder)
							.Padding(FMargin(3))
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Content()
						[
							SAssignNew(StatSheetButtonText, STextBlock)
							.Text(FText::FromString("Create Battle Box Actor"))
						.AutoWrapText(true)
						] // Border content end

						]// Button end
						]// Vertical Box Slot
				]// horisontal box end
			]// Horisontal Box end
		];
}
// if the plugin button is click open modlue window 
void FTEST_ACTION_MENUModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(TEST_ACTION_MENUTabName);
}
// Builds the First window used in Start up
void FTEST_ACTION_MENUModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FTEST_ACTION_MENUCommands::Get().OpenActionWindow);
}
//toolBar extion call Used in start up
void FTEST_ACTION_MENUModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FTEST_ACTION_MENUCommands::Get().OpenPluginWindow);
}

///  

//Creation of the other two windows

///
//StatSheetWindow Creation
FReply FTEST_ACTION_MENUModule::OpenStatSheetTab()
{
	statSheetWindowRef->Button_Clicked();
	return FReply::Handled();
}
//actionwindow creation calls Generate Window Transfer code from genrate window to this function call once completed dropDowns
FReply FTEST_ACTION_MENUModule::OpenActionTab() {
//	auto action = new ActionWindow();
	actionWindowRef->Button_Clicked();
	//FSlateApplication::Get().AddWindow(actionWindow, true);
	return FReply::Handled();
}
//Actor Tab window Creation
FReply FTEST_ACTION_MENUModule::OpenActorTab() {
	actorWindowRef->Button_Clicked();
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTEST_ACTION_MENUModule, TEST_ACTION_MENU)