// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TEST_ACTION_MENUStyle.h"

class FTEST_ACTION_MENUCommands : public TCommands<FTEST_ACTION_MENUCommands>
{
public:

	FTEST_ACTION_MENUCommands()
		: TCommands<FTEST_ACTION_MENUCommands>(TEXT("TEST_ACTION_MENU"), NSLOCTEXT("Contexts", "TEST_ACTION_MENU", "TEST_ACTION_MENU Plugin"), NAME_None, FTEST_ACTION_MENUStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
	TSharedPtr< FUICommandInfo > OpenActionWindow;
};