#include "StatSheetWindow.h"
#include "SlateBasics.h"
//Widgets
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SNumericDropDown.h"
#include "Widgets/Input/SSpinbox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SOverlay.h"
#include "SDockTab.h"
#include "SDockableTab.h"
//#include "Editor/EditorWidgets/Public/SDropTarget.h"
#include "AssetRegistryModule.h"
#include "../UStatSheetObject.h"
#include "UStatSheetFactory.h"

static const FName StatSheetTabName("StatSheet Creation Menu");
void StatSheetWindow::StartupModule() {
	// Local Reffrence for the global Tab Manager
	TSharedRef<class FGlobalTabmanager> tabManager = FGlobalTabmanager::Get();
	tabManager->RegisterTabSpawner(StatSheetTabName, FOnSpawnTab::CreateRaw(this, &StatSheetWindow::generateWidow))
		.SetDisplayName(FText::FromString(TEXT("StatSheet Creation Menu")));
}

void StatSheetWindow::ShutdownModule() {
	TSharedRef<class FGlobalTabmanager> tabManager = FGlobalTabmanager::Get();
	tabManager->UnregisterTabSpawner(StatSheetTabName);
}

void StatSheetWindow::Button_Clicked() {
	TSharedRef<class FGlobalTabmanager> tabManager = FGlobalTabmanager::Get();
	tabManager->InvokeTab(StatSheetTabName);
}


TSharedRef<SDockTab> StatSheetWindow::generateWidow(const FSpawnTabArgs& TabSpawnArgs)
{
	auto window =  SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(FText::FromString("Name: "))
		.AutoWrapText(true)
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SAssignNew(StatSheetName,SEditableTextBox)

		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(FText::FromString("Tag: "))
		.AutoWrapText(true)

		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SAssignNew(StatSheetTag, SEditableTextBox)
		]
		]
	+ SVerticalBox::Slot()
		[
			SAssignNew(StatSheetStatInfo, SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock).Text(FText::FromString("Stat Map"))
					]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
					[
						SNew(SButton).Text(FText::FromString("Add Stat")).OnClicked_Raw(this, &StatSheetWindow::CreateNewEntry)
					]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
					[
						SNew(SButton).Text(FText::FromString("Reset Map")).OnClicked_Raw(this, &StatSheetWindow::ResetStatMap)
					]
			]
			+SVerticalBox::Slot()
			[
				SAssignNew(ItemPanel, SScrollBox)
			]
			+SVerticalBox::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center)
			[
				SNew(SButton).OnClicked_Raw(this,&StatSheetWindow::createObject)
				[
					SNew(STextBlock).Text(FText::FromString("Create"))
				]
			]
		]
		];
	UE_LOG(LogTemp, Log, TEXT("Stat Window Open"));
	return window;
}

FReply StatSheetWindow::CreateNewEntry() {
	ItemPanel.Get()->AddSlot().AttachWidget(StatSheetWindow::genreateStatMapline());
	return FReply::Handled();
}

void StatSheetWindow::FindFiles() {
	IFileManager& FileManager = IFileManager::Get();
	FString FilePath = FPaths::ProjectContentDir() + "*.uasset";
	FileManager.FindFiles(contentFiles, *FilePath, true, false);
}
TSharedRef<SWidget> StatSheetWindow::generateDropDownWidget(FStatSheetItemType inOption)
{
	auto test = SNew(STextBlock).Text(FText::FromString(*inOption));
	return test;
}

TSharedRef<SWidget> StatSheetWindow::genreateStatMapline() {
	auto text = SNew(SEditableTextBox);
	auto spinner = SNew(SSpinBox<float>).MaxValue(10000000000);
	StatNames.Add(text);
	StatValues.Add(spinner);

	auto sendWidget = SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
				SNew(STextBlock).Text(FText::FromString("StatName"))
			]
			+SHorizontalBox::Slot()
			[
				text
			]
		]
		+SHorizontalBox::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
				SNew(STextBlock).Text(FText::FromString("Stat Value"))
			]
			+SHorizontalBox::Slot()
			[
				spinner
			]
		];
		return sendWidget;
}

void StatSheetWindow::StatMapOnSecctionChanged(FStatSheetItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentStatMapItem = NewValue;
}

// create stat sheet object
FReply StatSheetWindow::createObject() {
	FindFiles();
	FString Filename = StatSheetName.Get()->GetText().ToString();
	if (!contentFiles.Contains((Filename + ".uasset"))) {
		FString PackageName = "/Game/";
		PackageName += Filename;
		UPackage* Package = CreatePackage(NULL, *PackageName);
		auto UDataAssetFactory = NewObject<UStatSheetFactory>();
		UStatSheetObject* newDataAssetObject = (UStatSheetObject*)UDataAssetFactory->FactoryCreateNew(UStatSheetObject::StaticClass(), Package, *Filename, RF_Standalone | RF_Public, NULL, GWarn);
		Package->MarkPackageDirty();
		//ADDS THE ASSET TO THE CONTENT
		FAssetRegistryModule::AssetCreated(newDataAssetObject);
		Package->SetDirtyFlag(true);

		// Fill Assets
		newDataAssetObject->name = StatSheetName.Get()->GetText().ToString();
		newDataAssetObject->tag = StatSheetTag.Get()->GetText().ToString();
		int counter = StatNames.Num();
		UE_LOG(LogTemp, Log, TEXT("Numbers %d"), counter);
		for (int i = 0; i < counter; i++) {
			FString fill = StatNames[i].Get().GetText().ToString();
			float amount = StatValues[i].Get().GetValue();
			newDataAssetObject->additionlStats.Add(fill, amount);

			UE_LOG(LogTemp, Log, TEXT("Value Name %s"), *fill);
			UE_LOG(LogTemp, Log, TEXT("Value %d"), amount);
		}
		// Clear The Stat Arrays
		StatNames.Empty();
		StatValues.Empty();
		ItemPanel.Get()->ClearChildren();


		//Save The Package
		FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
		Package->SavePackage(Package, newDataAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);

		newDataAssetObject->PreEditChange(NULL);
		newDataAssetObject->PostEditChange();
		UE_LOG(LogTemp, Log, TEXT("Create Object"));

	}

	return FReply::Handled();
}
// Clears the Array
FReply StatSheetWindow::ResetStatMap() {
	StatNames.Empty();
	StatValues.Empty();
	ItemPanel.Get()->ClearChildren();
	return FReply::Handled();
}
