// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VoleyballGame : ModuleRules
{
	public VoleyballGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OnlineSubSystem", "OnlineSubsystemUtils", "SteamWorks", "Networking" });

		DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

		PrivateDependencyModuleNames.Add("OnlineSubsystem");
	}
}
