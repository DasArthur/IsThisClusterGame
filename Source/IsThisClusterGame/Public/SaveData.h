// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "SaveData.generated.h"

/**
 * 
 */
UCLASS()
class ISTHISCLUSTERGAME_API USaveData : public USaveGame
{
	GENERATED_BODY()

public:
		UPROPERTY(BlueprintReadWrite,VisibleAnywhere, Category = Basic) FString PlayerName;

		UPROPERTY(BlueprintReadWrite,VisibleAnywhere, Category = "FirstLoad")
		bool fl;
		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "FirstLoad")
			int32 fl2;


//	UPROPERTY(VisibleAnywhere, Category = "Level")
//		TArray<float> LevelTime[11];

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere, Category = Basic)
		FString SaveSlotName;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere, Category = Basic)
		int32 UserIndex;

		USaveData();

	
};
