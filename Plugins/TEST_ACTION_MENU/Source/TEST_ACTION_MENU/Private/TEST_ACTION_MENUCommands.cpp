// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TEST_ACTION_MENUCommands.h"

#define LOCTEXT_NAMESPACE "FTEST_ACTION_MENUModule"

void FTEST_ACTION_MENUCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Battle Box Creation Menu", "Bring up TEST_ACTION_MENU window", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(OpenActionWindow, "Action Window Creator", "Bring up Action Window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
