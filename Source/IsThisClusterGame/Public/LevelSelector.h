// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LevelSelector.generated.h"

UCLASS()
class ISTHISCLUSTERGAME_API ALevelSelector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelSelector();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	USceneComponent* root;
	UPROPERTY(EditAnywhere) UStaticMeshComponent* Levels[11];
	UPROPERTY(EditAnywhere) UStaticMeshComponent* LevelStars[33];

	//Star Actor
	UPROPERTY(EditAnywhere) UStaticMeshComponent* StarCube;
	UMaterialInstance* SelectedMaterial_m;
	UMaterialInstance* DefaultMaterial_m;
	UFUNCTION(BlueprintCallable, Category = "LevelChanger") void ChangeLevel(int32 level);
	UFUNCTION(BlueprintCallable, Category = "LevelChanger") void ChangeLevel_Mouse(int32 level);
	UPROPERTY() class UPaperSpriteComponent* LevelImage[11];
	UFUNCTION(BlueprintCallable, Category = "LevelChanger") void SpawnStar(int32 level,int32 stars);

	
	
};
