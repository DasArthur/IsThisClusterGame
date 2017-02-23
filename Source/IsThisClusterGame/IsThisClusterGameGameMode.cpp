// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "IsThisClusterGame.h"
#include "IsThisClusterGameGameMode.h"
#include "IsThisClusterGameCharacter.h"

AIsThisClusterGameGameMode::AIsThisClusterGameGameMode()
{
	// set default pawn class to our character
	DefaultPawnClass = AIsThisClusterGameCharacter::StaticClass();	
}
