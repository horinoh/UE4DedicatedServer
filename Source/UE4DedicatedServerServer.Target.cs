// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4DedicatedServerServerTarget : TargetRules
{
	public UE4DedicatedServerServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;

		ExtraModuleNames.Add("UE4DedicatedServer");
	}
}
