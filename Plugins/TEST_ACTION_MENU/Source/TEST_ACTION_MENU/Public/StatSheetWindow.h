#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/SWindow.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Layout/SScrollBox.h"
// File Management
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"


typedef TSharedPtr <FString>  FStatSheetItemType;
class StatSheetWindow : public IModuleInterface {
public:
	TSharedRef<class SDockTab> generateWidow(const class FSpawnTabArgs& TabSpawnArgs);
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void Button_Clicked();
private:
	TSharedPtr<SEditableTextBox> StatSheetName;
	TSharedPtr<SEditableTextBox> StatSheetTag;
	TSharedPtr<SScrollBox> ItemPanel;
	TArray<TSharedRef<SEditableTextBox>> StatNames;
	TArray<TSharedRef<SSpinBox<float>>> StatValues;

	/// StatSheet Widgets
	//Stat Map Variables;
	///Slate widget Combo Box;
	TSharedPtr<SComboBox<FStatSheetItemType>> StatMapWidget;
	/// ComboBox Array;
	TArray<FStatSheetItemType> StatMapArray;
	///StatMap Current Selection;
	FStatSheetItemType currentStatMapItem;
	///Stat Map On selection Change
	void StatMapOnSecctionChanged(FStatSheetItemType NewValue, ESelectInfo::Type selectionInfo);
	/// C++ Stat Map
	TMap<FString, float> StatMap;

	FReply CreateNewEntry();
	TSharedRef<SWidget> generateDropDownWidget(FStatSheetItemType inOption);
	TSharedRef<SWidget> genreateStatMapline();
	FReply createObject();
	// clears the block and the arrays for the statmap
	FReply ResetStatMap();

	TSharedPtr<SVerticalBox> StatSheetStatInfo;


	//Finds all the files in root
	void FindFiles();
	//Array of All Files
	TArray<FString> contentFiles;
};