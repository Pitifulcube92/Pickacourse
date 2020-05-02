// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#ifndef BATTLEBOXFILEMANAGER_H
#define BATTLEBOXFILEMANAGER_H

#include "CoreMinimal.h"

/**
 * 
 */
class BattleBoxFileManager
{
public:
	BattleBoxFileManager(const BattleBoxFileManager&) = delete;
	BattleBoxFileManager(BattleBoxFileManager&&) = delete;
	BattleBoxFileManager& operator=(const BattleBoxFileManager&) = delete;
	BattleBoxFileManager& operator=(BattleBoxFileManager&&) = delete;
	BattleBoxFileManager() = delete;

	///Check and creates if there is a directory.
	static bool VerifyOnCreateDirectory(const FString& testDir_);
	///Gets the file size.
	static void GetFileSize(const FString& sourcePath_);
	///Deletes a file.
	static void DeleteFile(const FString& sourcePath_);
	///writes to a text file. 
	static void WriteTextFile(const FString& saveDirectory_, const FString context_, const FString& FileName_, bool const IsOverWrite_);
	///write multiple lines of string to a txt file.
	static void WriteTextArrayToFile(const FString& saveDirectory_, const TArray<FString> textArray_, const FString& FileName_, bool const IsOverWrite_);
};
#endif // !
