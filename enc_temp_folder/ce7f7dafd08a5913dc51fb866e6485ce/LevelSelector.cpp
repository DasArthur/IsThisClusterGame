// Fill out your copyright notice in the Description page of Project Settings.

#include "IsThisClusterGame.h"
#include "LevelSelector.h"
#include "Engine.h"


// Sets default values
ALevelSelector::ALevelSelector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void ALevelSelector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelSelector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

