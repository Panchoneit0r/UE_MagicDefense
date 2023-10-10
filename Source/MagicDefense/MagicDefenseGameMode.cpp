// Copyright Epic Games, Inc. All Rights Reserved.

#include "MagicDefenseGameMode.h"
#include "MagicDefenseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMagicDefenseGameMode::AMagicDefenseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
