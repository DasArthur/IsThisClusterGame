// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnableStar.generated.h"

UCLASS()
class ISTHISCLUSTERGAME_API ASpawnableStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnableStar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UStaticMeshComponent*  cube;
	UFUNCTION(BlueprintCallable, Category = "LevelChanger") void SpawnCube(FVector Locaion);
	
};
