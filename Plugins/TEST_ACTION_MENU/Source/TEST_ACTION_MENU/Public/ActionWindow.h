// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/SWindow.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "AssetThumbnail.h"
#include "ActionAlgorithmComponent.h"
#include "UStatSheetObject.h"


//File Management 
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"
#include "SlateBasics.h"
#include "Editor/EditorWidgets/Public/SDropTarget.h"
/**
 * 
 */
typedef TSharedPtr <FString>  FComboItemType;
class TEST_ACTION_MENU_API ActionWindow : public IModuleInterface
{
public:
	// Nomad Tab Shenenigans
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void Button_Clicked();

	/// Action Menu
	// SEditable Name
	TSharedPtr<SEditableTextBox> actionName;
	// SEditable Desciption
	TSharedPtr<SEditableTextBox> actionDescription;

	//////////////////////////////////////////////////////////////////
	//// the Action Type ComboBox  
	TSharedPtr<SComboBox<FComboItemType>> actionTypeComboBox;
	//// options in the Action Type sarray
	TArray<FComboItemType> actionTypeArray;
	//// Current Action Type
	FComboItemType currentActionType;
	////changes selection 
	void ActionTypeOnSelectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// 
	FText GetCurrentActionTypeLabel() const;
	//////////////////////////////////////////////////////////////////
	//// interaction Type ComboBox
	TSharedPtr<SComboBox<FComboItemType>> interactionTypeComboBox;
	//// options in the interaction Type Array;
	TArray<FComboItemType> interactionTypeArray;
	//// Current interaction Type 
	FComboItemType currentinteractionType;
	//// Changes selection
	void InteractionTypeOnSectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// Updates Lable
	FText GetCurrentInteractionTypeLabel() const;
	//////////////////////////////////////////////////////////////////
	// SpinBox For Action ID 
	TSharedPtr<SSpinBox<uint32>> actionID;

	TSharedPtr<SScrollBox> algorithmPanel;
	TSharedPtr<SScrollBox> statusPanel;

	////Generate widgets 
	TSharedRef<SWidget> generateDropDownWidget(FComboItemType inOption);
	TSharedRef<SWidget> GenerateAlgorithmItemDrop();

	TSharedRef<class SDockTab> generateWidow(const class FSpawnTabArgs& TabSpawnArgs);




	TSharedPtr<SDropTarget> dropTargetTest;

	bool OnDropTargetAllowDrop(TSharedPtr<FDragDropOperation> DragDropOperation);

	FReply OnDropTargetInputDrop(TSharedPtr<FDragDropOperation> DragDropOperation);
	
	FReply CreateActionObject();

	//Finds all the files in root
	void FindFiles();
	//Array of All Files
	TArray<FString> contentFiles;

	TArray<FAssetData> assetDrop;
	//FName className = "ActionAlgorithmComponent";
	//FAsset Thumbnail 
	TSharedPtr<FAssetThumbnailPool> MyThumbnailPool;
	TSharedPtr<FAssetThumbnail> MyThumbnail;

	UActionAlgorithmComponent* Asset;


};
