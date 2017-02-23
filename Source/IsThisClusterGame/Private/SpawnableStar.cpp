// Fill out your copyright notice in the Description page of Project Settings.

#include "IsThisClusterGame.h"
#include "SpawnableStar.h"


// Sets default values
ASpawnableStar::ASpawnableStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Star"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeRefrence(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	cube->SetStaticMesh(cubeRefrence.Object);
	cube->SetWorldScale3D(FVector(0.5f));

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> DefaultMaterial(TEXT("MaterialInstanceConstant'/Game/Textures/materials/GLOWING_STAR.GLOWING_STAR'"));
	cube->SetMaterial(0, DefaultMaterial.Object);

	RootComponent = cube;

}

// Called when the game starts or when spawned
void ASpawnableStar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnableStar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpawnableStar::SpawnCube(FVector Locaion) {

	UWorld* const World = GetWorld();
	ASpawnableStar* NewActor = GetWorld()->SpawnActor<ASpawnableStar>(GetClass(), Locaion, FRotator::ZeroRotator);

}