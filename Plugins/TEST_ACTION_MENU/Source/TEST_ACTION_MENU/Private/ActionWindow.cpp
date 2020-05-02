// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionWindow.h"
//Widgets
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Input/SButton.h"
#include "SDockTab.h"
#include "SDockableTab.h"
#include "SlateBasics.h"
#include "Editor/EditorWidgets/Public/SDropTarget.h"
#include "../ActionAlgorithmComponent.h"
#include "DragAndDrop/AssetDragDropOp.h"



//Create Objects
#include "AssetRegistryModule.h"
#include "UAbiltiyActionFactory.h"
#include "UCommandActionFactory.h"
#include "UItemActionFactory.h"
#include "../ActionClasses/UAbilityAction.h"
#include "../ActionClasses/UCommandAction.h"
#include "../ActionClasses/UItemAction.h"
#include "../Battle_Box_Enums.h"
#include "..\Public\ActionWindow.h"
#include "../ActionAlgorithmComponent.h"
#include "CoreUObject.h"

static const FName ActionMenuTabName("Action Creation Menu");

void ActionWindow::StartupModule() {
	// Local Reffrence for the global Tab Manager
	TSharedRef<class FGlobalTabmanager> tabManager = FGlobalTabmanager::Get();
	tabManager->RegisterTabSpawner(ActionMenuTabName, FOnSpawnTab::CreateRaw(this, &ActionWindow::generateWidow))
		.SetDisplayName(FText::FromString(TEXT("Action Creation Menu")));
}

void ActionWindow::ShutdownModule() {
	TSharedRef<class FGlobalTabmanager> tabManager = FGlobalTabmanager::Get();
	tabManager->UnregisterTabSpawner(ActionMenuTabName);
}

void ActionWindow::Button_Clicked() {
	TSharedRef<class FGlobalTabmanager> tabManager = FGlobalTabmanager::Get();
	tabManager->InvokeTab(ActionMenuTabName);
}
TSharedRef<SDockTab> ActionWindow::generateWidow(const FSpawnTabArgs& TabSpawnArgs)
{
	MyThumbnailPool = MakeShareable(new FAssetThumbnailPool(16, false));
	MyThumbnail = MakeShareable(new FAssetThumbnail(Asset, 16, 16 , MyThumbnailPool));

	// Action Type
	actionTypeArray.Add(MakeShareable(new FString("E_NONE")));
	actionTypeArray.Add(MakeShareable(new FString("E_ABILITY")));
	actionTypeArray.Add(MakeShareable(new FString("E_COMMAND")));
	actionTypeArray.Add(MakeShareable(new FString("E_ITEM")));
	currentActionType = actionTypeArray[0];
	// interaction Type
	interactionTypeArray.Add(MakeShareable(new FString("E_NONE")));
	interactionTypeArray.Add(MakeShareable(new FString("E_ABILITY")));
	interactionTypeArray.Add(MakeShareable(new FString("E_PHYSICAL_AND_ABILITY")));
	currentinteractionType = interactionTypeArray[0];
	auto myWindow = SNew(SDockTab).TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SNew(STextBlock).Text(FText::FromString("Action Name"))
				]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SAssignNew(actionName, SEditableTextBox)
				]
			]
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SNew(STextBlock).Text(FText::FromString("Action Descption"))
				]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SAssignNew(actionDescription, SEditableTextBox)
				]
			]
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Choose Action Type"))
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SAssignNew(actionTypeComboBox, SComboBox<FComboItemType>)
					.OptionsSource(&actionTypeArray)
					.OnGenerateWidget_Raw(this, &ActionWindow::generateDropDownWidget)
					.OnSelectionChanged_Raw(this, &ActionWindow::ActionTypeOnSelectionChanged)
					.InitiallySelectedItem(currentActionType)
					[
						SNew(STextBlock).Text_Raw(this, &ActionWindow::GetCurrentActionTypeLabel)
						//.Text(FText::FromString("Failed"))

					]
				]
			]
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Choose Interaction Type"))
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SAssignNew(interactionTypeComboBox, SComboBox<FComboItemType>)
					.OptionsSource(&interactionTypeArray)
					.OnGenerateWidget_Raw(this, &ActionWindow::generateDropDownWidget)
					.OnSelectionChanged_Raw(this, &ActionWindow::InteractionTypeOnSectionChanged)
					.InitiallySelectedItem(currentinteractionType)
					[
						SNew(STextBlock).Text_Raw(this, &ActionWindow::GetCurrentInteractionTypeLabel)
					]
				]
			]
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Choose Action ID"))
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SAssignNew(actionID,SSpinBox<uint32>).MaxValue(10000000000)
				]
			]
			+SVerticalBox::Slot() // Algorithm map 
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Algorithm"))
				]
				+ SHorizontalBox::Slot()
				[
					SAssignNew(dropTargetTest, SDropTarget)
					.OnAllowDrop_Raw(this, &ActionWindow::OnDropTargetAllowDrop)
					.OnDrop_Raw(this, &ActionWindow::OnDropTargetInputDrop)
					[
						MyThumbnail->MakeThumbnailWidget()
					]
				]
			]
	
			//+ SVerticalBox::Slot() // status effect map 
			//[
			//	SNew(SHorizontalBox)
			//	+ SHorizontalBox::Slot().VAlign(VAlign_Center)
			//	[
			//		SNew(STextBlock)
			//		.Text(FText::FromString("Status Effect Map"))
			//	]
			//	+ SHorizontalBox::Slot().VAlign(VAlign_Center)
			//	[
			//		SNew(SButton).Text(FText::FromString("Add Status")) //.OnClicked_Raw(this, &StatSheetWindow::CreateNewEntry)
			//	]
			//	+ SHorizontalBox::Slot().VAlign(VAlign_Center)
			//	[
			//		SNew(SButton).Text(FText::FromString("Reset Map")) //.OnClicked_Raw(this, &StatSheetWindow::ResetStatMap)
			//	]
			//]
			//+SVerticalBox::Slot() // status scroll box
			//[
			//	SNew(SHorizontalBox)
			//	+SHorizontalBox::Slot().VAlign(VAlign_Center)
			//	[
			//		SAssignNew(statusPanel, SScrollBox)
			//	]
			//]
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Bottom)
				.HAlign(HAlign_Right)
				[
					SNew(SButton)
					.Text(FText::FromString("Create"))
					.OnClicked_Raw(this, &ActionWindow::CreateActionObject)
				]
			]
			//+SVerticalBox::Slot()
			//[
			//	SNew(SDropTarget).OnAllowDrop_Raw(this, &ActionWindow::OnDropTargetAllowDrop)
			//	.OnDrop_Raw(this, &ActionWindow::OnDropTargetInputDrop)
			//]
		];
	return myWindow;
}
FReply ActionWindow::CreateActionObject()
{
	FindFiles();
	FString Filename = actionName.Get()->GetText().ToString();
	//FBaseAction_Info assetInfo;
	MyThumbnail->GetAsset();
	if (!contentFiles.Contains((Filename + ".uasset"))) {
		FString PackageName = "/Game/";
		PackageName += Filename;
		UPackage* Package = CreatePackage(NULL, *PackageName);
		//interaction Determination
		INTERACTIONTYPE interactionType;
		if (*currentinteractionType.Get() == FString("E_NONE")) { interactionType = INTERACTIONTYPE::E_NONE; }
		else if (*currentinteractionType.Get() == FString("E_ABILITY")) { interactionType = INTERACTIONTYPE::E_ABILITY; }
		else if (*currentinteractionType.Get() == FString("E_PHYSICAL")) { interactionType = INTERACTIONTYPE::E_PHYSICAL; }
		else { interactionType = INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY; }
		//Setting the Action Agorithm
		UActionAlgorithmComponent* Algorithm = (UActionAlgorithmComponent*)MyThumbnail.Get()->GetAsset();
		TSubclassOf<UActionAlgorithmComponent> actionAlgorithm(Algorithm->StaticClass());


		if (*currentActionType.Get() == FString("E_NONE")) {
			auto UAssetFactory = NewObject<UAblityActionFactory>();
			UAbilityAction* newDataAssetObject = (UAbilityAction*)UAssetFactory->FactoryCreateNew(UAbilityAction::StaticClass(), Package, *Filename, RF_Standalone | RF_Public, NULL, GWarn);
			Package->MarkPackageDirty();
			//ADDS THE ASSET TO THE CONTENT
			FAssetRegistryModule::AssetCreated(newDataAssetObject);
			Package->SetDirtyFlag(true);

	
			// Changing the Contents of the Object
			newDataAssetObject->name = Filename;
			newDataAssetObject->discription = actionDescription.Get()->GetText().ToString();
			newDataAssetObject->action = ACTIONTYPE::E_ABILITY;
			newDataAssetObject->interaction = interactionType;
			newDataAssetObject->actionID = actionID.Get()->GetValue();
			newDataAssetObject->actionAlgorithms = actionAlgorithm;

			//Save The Package
			FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
			Package->SavePackage(Package, newDataAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);

			newDataAssetObject->PreEditChange(NULL);
			newDataAssetObject->PostEditChange();
	
		}
		else if (*currentActionType.Get() == FString("E_ABILITY")) {
			auto UAssetFactory = NewObject<UAblityActionFactory>();
			UAbilityAction* newDataAssetObject = (UAbilityAction*)UAssetFactory->FactoryCreateNew(UAbilityAction::StaticClass(), Package, *Filename, RF_Standalone | RF_Public, NULL, GWarn);
			Package->MarkPackageDirty();
			//ADDS THE ASSET TO THE CONTENT
			FAssetRegistryModule::AssetCreated(newDataAssetObject);
			Package->SetDirtyFlag(true);

			// Changing the Contents of the Object
			newDataAssetObject->name = Filename;
			newDataAssetObject->discription = actionDescription.Get()->GetText().ToString();
			newDataAssetObject->action = ACTIONTYPE::E_ABILITY;
			newDataAssetObject->interaction = interactionType;
			newDataAssetObject->actionID = actionID.Get()->GetValue();
			newDataAssetObject->actionAlgorithms = actionAlgorithm;

			//Save The Package
			FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
			Package->SavePackage(Package, newDataAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);

			newDataAssetObject->PreEditChange(NULL);
			newDataAssetObject->PostEditChange();
		}
		else if (*currentActionType.Get() == FString("E_COMMAND")) {
			auto UAssetFactory = NewObject<UCommandActionFactory>();
			UCommandAction* newDataAssetObject = (UCommandAction*)UAssetFactory->FactoryCreateNew(UCommandAction::StaticClass(), Package, *Filename, RF_Standalone | RF_Public, NULL, GWarn);
			Package->MarkPackageDirty();
			//ADDS THE ASSET TO THE CONTENT
			FAssetRegistryModule::AssetCreated(newDataAssetObject);
			Package->SetDirtyFlag(true);

			// Changing the Contents of the Object
			newDataAssetObject->name = Filename;
			newDataAssetObject->discription = actionDescription.Get()->GetText().ToString();
			newDataAssetObject->action = ACTIONTYPE::E_COMMAND;
			newDataAssetObject->interaction = interactionType;
			newDataAssetObject->actionID = actionID.Get()->GetValue();
			newDataAssetObject->actionAlgorithms = actionAlgorithm;

			//Save The Package
			FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
			Package->SavePackage(Package, newDataAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);

			newDataAssetObject->PreEditChange(NULL);
			newDataAssetObject->PostEditChange();
		}
		else if (*currentActionType.Get() == FString("E_ITEM")) {
			auto UAssetFactory = NewObject<UItemActionFactory>();
			UItemAction* newDataAssetObject = (UItemAction*)UAssetFactory->FactoryCreateNew(UItemAction::StaticClass(), Package, *Filename, RF_Standalone | RF_Public, NULL, GWarn);
			Package->MarkPackageDirty();
			//ADDS THE ASSET TO THE CONTENT
			FAssetRegistryModule::AssetCreated(newDataAssetObject);
			Package->SetDirtyFlag(true);

			// Changing the Contents of the Object
			newDataAssetObject->name = Filename; 
			newDataAssetObject->discription = actionDescription.Get()->GetText().ToString();
			newDataAssetObject->action = ACTIONTYPE::E_ITEM;
			newDataAssetObject->interaction = interactionType;
			newDataAssetObject->actionID = actionID.Get()->GetValue();
			newDataAssetObject->actionAlgorithms = actionAlgorithm;

			////Save The Package
			FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
			Package->SavePackage(Package, newDataAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);

			newDataAssetObject->PreEditChange(NULL);
			newDataAssetObject->PostEditChange();
		}
	}
	return FReply::Handled();
}
void ActionWindow::FindFiles()
{
	IFileManager& FileManager = IFileManager::Get();
	FString FilePath = FPaths::ProjectContentDir() + "*.uasset";
	FileManager.FindFiles(contentFiles, *FilePath, true, false);
}
//Section changes the current Action Type once a slection is changed
void ActionWindow::ActionTypeOnSelectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentActionType = NewValue;
	UE_LOG(LogTemp, Warning, TEXT("Current Item is: %s"), **currentActionType);
}
// gets the action type name
FText ActionWindow::GetCurrentActionTypeLabel() const
{
	if (currentActionType.IsValid()) {
		return FText::FromString(**currentActionType);
	}
	else {
		return FText::FromString("Failed");
	}
}
// On Selection Changed 
void ActionWindow::InteractionTypeOnSectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentinteractionType = NewValue;
}
// Gets current Inteaction Label 
FText ActionWindow::GetCurrentInteractionTypeLabel() const
{
	if (currentinteractionType.IsValid()) {
		return FText::FromString(**currentinteractionType);
	}
	return FText::FromString("Failed");
}
//Genreates a STextBlock based on a FComboItemType array
TSharedRef<SWidget> ActionWindow::generateDropDownWidget(FComboItemType inOption)
{
	auto dropDown = SNew(STextBlock).Text(FText::FromString(*inOption));
	return dropDown;
}
//Generates widget item for the Algorithm panel to use
TSharedRef<SWidget> ActionWindow::GenerateAlgorithmItemDrop() {

	auto sendWidget = SNew(SHorizontalBox);
	//	+ SHorizontalBox::Slot()
	//	[
	//		SNew(SHorizontalBox)
	//		+ SHorizontalBox::Slot()
	//	[
	//		SNew(STextBlock).Text(FText::FromString("StatName"))
	//	]
	//+ SHorizontalBox::Slot()
	//	[
	//		text
	//	]
	//	]
	//+ SHorizontalBox::Slot()
	//	[
	//		SNew(SHorizontalBox)
	//		+ SHorizontalBox::Slot()
	//	[
	//		SNew(STextBlock).Text(FText::FromString("Stat Value"))
	//	]
	//+ SHorizontalBox::Slot()
	//	[
	//		spinner
	//	]
	//	];
	return sendWidget;
}

bool ActionWindow::OnDropTargetAllowDrop(TSharedPtr<FDragDropOperation> DragDropOperation)
{
	return true;
}

FReply ActionWindow::OnDropTargetInputDrop(TSharedPtr<FDragDropOperation> DragDropOperation)
{

	if (DragDropOperation->IsOfType<FAssetDragDropOp>()) {
		const auto& AssetDragDropOp = StaticCastSharedPtr<FAssetDragDropOp>(DragDropOperation);
		assetDrop = AssetDragDropOp.Get()->GetAssets();

		UActionAlgorithmComponent* receive = (UActionAlgorithmComponent*)assetDrop[0].GetAsset();
		MyThumbnail.Get()->SetAsset(receive);
		UE_LOG(LogTemp, Warning, TEXT("Drop operation detected!"));
	}
	return FReply::Handled();
}