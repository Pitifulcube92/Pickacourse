// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#ifndef DEBUGER_H
#define DEBUGER_H
#include "CoreMinimal.h"
#include "../Public/Battle_Box_Enums.h"
/**
 *
 */
class BATTLE_BOX_API Debugger
{
private:
	static void Log(const MessageType type_, const FString& message_, const FString& fileName_, const int32 line_);
	static TArray<FString> LogArray;
	static MessageType currentType;
	static FString DebugDirectory;
public:
	Debugger(const Debugger&) = delete;
	Debugger(Debugger&&) = delete;
	Debugger& operator =(const Debugger&) = delete;
	Debugger& operator =(Debugger&&) = delete;
	Debugger() = delete;

	///Initiates the debugger.
	static void InitDebug();
	///Sets the severity.
	static void SetSeverity(const MessageType type_);
	///Sends a info log to the debugger txt file.
	static void Info(const FString& message_, const FString& fileName_, const int32 line_);
	///Sends a error  log to the debugger txt file.
	static void Error(const FString& message_, const FString& fileName_, const int32 line_);
	///Sends a warrning log to the debugger txt file.
	static void Warrning(const FString& message_, const FString& fileName_, const int32 line_);
	///Sends a warning log to the dugger txt file.
	static void FatalError(const FString& message_, const FString& fileName_, const int32 line_);
};
#endif // !1
