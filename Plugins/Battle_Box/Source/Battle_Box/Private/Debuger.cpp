// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Debugger.h"
#include "BattleBoxFileManager.h"
///destroy all this
#include "ActionClasses/UBaseAction.h"
#include "UStatSheetObject.h"
#include "ActionClasses/UAbilityAction.h"
#include "ActionClasses/UItemAction.h"
#include "ActionClasses/UCommandAction.h"
#include "../Public/Battle_Box_Enums.h"
#include <string>

///destroy all this
#include "Misc/Paths.h"

MessageType Debugger::currentType = MessageType::E_NONE;
FString Debugger::DebugDirectory = "";
TArray<FString> Debugger::LogArray = TArray<FString>();

void Debugger::InitDebug()
{
	DebugDirectory = FPaths::ProjectPluginsDir() + "/Battle_Box/Debug";
	if (!BattleBoxFileManager::VerifyOnCreateDirectory(DebugDirectory))
	{
		UE_LOG(LogTemp, Warning, TEXT("Something went wrong with the directory!"));
		return;
	}
	currentType = MessageType::E_FATAL_ERROR;
	UE_LOG(LogTemp, Log, TEXT("Debug Directory has been made!"));
}
void Debugger::Log(const MessageType type_, const FString& message_, const FString& fileName_, const int32 line_)
{
	UE_LOG(LogTemp, Log, TEXT("This Works!"));
	if (type_ <= currentType && currentType > MessageType::E_NONE)
	{
		UE_LOG(LogTemp, Log, TEXT("This Works!"));
		FString LogMessage = message_ + " in " + fileName_ + ". " + "Line: " + FString::FromInt(line_);
		FString LogFileName = "Logger.txt";
		LogArray.Add(LogMessage);
		BattleBoxFileManager::WriteTextArrayToFile(DebugDirectory, LogArray, LogFileName, true);
	}
}
void Debugger::SetSeverity(const MessageType type_)
{
	currentType = type_;
}
void Debugger::Info(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_INFO,"INFO: " + message_, fileName_, line_);
}
void Debugger::Error(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_ERROR,"ERROR: " + message_, fileName_, line_);
}
void Debugger::Warrning(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_WARNING,"WARNING: " + message_, fileName_, line_);
}
void Debugger::FatalError(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_FATAL_ERROR,"FATALERROR: " + message_, fileName_, line_);
}
