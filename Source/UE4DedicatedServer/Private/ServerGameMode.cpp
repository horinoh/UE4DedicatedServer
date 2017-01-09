// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4DedicatedServer.h"
#include "ServerGameMode.h"

#include "ServerCharacter.h"

AServerGameMode::AServerGameMode()
{
	DefaultPawnClass = AServerCharacter::StaticClass();
}
