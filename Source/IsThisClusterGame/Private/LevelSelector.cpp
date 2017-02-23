// Fill out your copyright notice in the Description page of Project Settings.

#include "IsThisClusterGame.h"
#include "LevelSelector.h"
#include "Engine.h"
#include "PaperSpriteComponent.h"
#include "SpawnableStar.h"


// Sets default values
ALevelSelector::ALevelSelector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = root;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeRefrence(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> DefaultMaterial(TEXT("MaterialInstanceConstant'/Game/Textures/materials/DissapearAnimation_Inst_Inst.DissapearAnimation_Inst_Inst'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> SelectedMaterial(TEXT("MaterialInstanceConstant'/Game/Textures/materials/DissapearAnimation_Inst_Inst_2.DissapearAnimation_Inst_Inst_2'"));
	SelectedMaterial_m = SelectedMaterial.Object;
	DefaultMaterial_m = DefaultMaterial.Object;
	
	for (int i = 0; i < 11; i++) {
	
		//NAME FOR THE CUBE
			FName name = *FString::FromInt((i+1));
			////NAME FOR THE PAPER SPRITE
			FString PaperSpriteNameLookup = *FString("PaperSprite'/Game/Textures/Sprites/Level"
				+ FString::FromInt((i + 1)) + ".Level"+ FString::FromInt((i + 1))+"'");
		
			const TCHAR* lovelytext[52] = { *PaperSpriteNameLookup };

			FString CollisionBoxString = *FString("CollisionBox " + FString::FromInt((i + 1)));
			const TCHAR* CollisionBoxName[52] = { *CollisionBoxString };
			//INITILIZATION OF CUBES
			Levels[i] = CreateDefaultSubobject<UStaticMeshComponent>(name);
			Levels[i]->SetStaticMesh(CubeRefrence.Object);
			Levels[i]->SetMaterial(0, DefaultMaterial.Object);
			Levels[i]->SetWorldScale3D(FVector(1.7f));
			Levels[i]->SetupAttachment(root);

			//AUTOMATIC IMAGE FINDER
			 ConstructorHelpers::FObjectFinder<UPaperSprite> LevelImageObject(*lovelytext);
			FName imageName = *PaperSpriteNameLookup;

			//Level Number sprite initilization
			LevelImage[i] = CreateDefaultSubobject<UPaperSpriteComponent>(imageName);
			LevelImage[i]->SetSprite(LevelImageObject.Object);
			LevelImage[i]->SetupAttachment(root);
			LevelImage[i]->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			//BoxCollision

		

			
			if (i == 0 || i == 1 || i == 2) {
				Levels[i]->SetWorldLocation(FVector(GetActorLocation().X + (i * 560), GetActorLocation().Y, GetActorLocation().Z));
				LevelImage[i]->SetWorldLocation(FVector(GetActorLocation().X + (i * 560), GetActorLocation().Y+100, GetActorLocation().Z + 90));
			}else if (i == 1000) {
				Levels[i]->SetWorldLocation(FVector(GetActorLocation().X + (i * 560), GetActorLocation().Y, GetActorLocation().Z));
				LevelImage[i]->SetWorldLocation(FVector(GetActorLocation().X + (i * 560), GetActorLocation().Y + 100, GetActorLocation().Z + 90));
			}
			else if ((i == 3 || i == 4 || i == 5 || i == 6 || i == 7)) {
				Levels[i]->SetWorldLocation(FVector(GetActorLocation().X + ((i - 3) * 560) - 560, GetActorLocation().Y, GetActorLocation().Z - 450));
				LevelImage[i]->SetWorldLocation(FVector(GetActorLocation().X + ((i - 3) * 560) - 560, GetActorLocation().Y + 100, GetActorLocation().Z - 450 + 90));

			}
			else if ((i == 8 || i == 9 || i == 10)) {
				Levels[i]->SetWorldLocation(FVector(GetActorLocation().X + ((i - 9) * 560) + 560, GetActorLocation().Y, GetActorLocation().Z - 900));
				LevelImage[i]->SetWorldLocation(FVector(GetActorLocation().X + ((i - 9) * 560) + 560, GetActorLocation().Y + 100, GetActorLocation().Z - 900 + 90));

			}
		
			LevelImage[i]->SetVisibility(true);
	}

	int counter = -1;
	int levelStar_Location = 0;
	for (int i = 0; i < 33; i++) {


		counter++;
		if (counter == 3) {
			levelStar_Location++;
			counter = 0;
		}

		FString NameForTheStar = *FString("'LEVEL STARS' " + FString::FromInt((levelStar_Location + 1))+" " +FString::FromInt((counter + 1)));
		
		LevelStars[i] = CreateDefaultSubobject<UStaticMeshComponent>(*NameForTheStar);
		LevelStars[i]->SetStaticMesh(CubeRefrence.Object);
		LevelStars[i]->SetMaterial(0, SelectedMaterial.Object);
		LevelStars[i]->SetWorldScale3D(FVector(0.5f));
		LevelStars[i]->SetupAttachment(root);
		LevelStars[i]->SetVisibility(false);


		
		if (levelStar_Location == 0 || levelStar_Location == 1 || levelStar_Location == 2) {
			LevelStars[i]->SetWorldLocation(FVector(GetActorLocation().X + (levelStar_Location * 560), GetActorLocation().Y, GetActorLocation().Z - 80));
			
		}
		else if (levelStar_Location == 1000) {
			LevelStars[i]->SetWorldLocation(FVector(GetActorLocation().X + (levelStar_Location * 560), GetActorLocation().Y, GetActorLocation().Z));
	
		}
		else if ((levelStar_Location == 3 || levelStar_Location == 4 || levelStar_Location == 5 || levelStar_Location == 6 || levelStar_Location == 7)) {
			LevelStars[i]->SetWorldLocation(FVector(GetActorLocation().X + ((levelStar_Location - 3) * 560) - 560, GetActorLocation().Y, GetActorLocation().Z - 530));
			

		}
		else if ((levelStar_Location == 8 || levelStar_Location == 9 || levelStar_Location == 10))  {
			LevelStars[i]->SetWorldLocation(FVector(GetActorLocation().X + ((levelStar_Location - 9) * 560) + 560, GetActorLocation().Y, GetActorLocation().Z - 980));
		

		}

	}

}

// Called when the game starts or when spawned
void ALevelSelector::BeginPlay()
{
	Super::BeginPlay();
	//Levels[0]->SetMaterial(0, SelectedMaterial_m);
}

// Called every frame
void ALevelSelector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
//	if (SelectedMaterial_m != nullptr) {
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Hety");
//		
//		Levels[0]->SetMaterial(0, SelectedMaterial_m);
//	}




	
}

void ALevelSelector::ChangeLevel( int32 level ) {

	if (level >= 0 && level < 11) {
		if (level == 0) {
			Levels[level]->SetMaterial(0, SelectedMaterial_m);
			Levels[level+1]->SetMaterial(0, DefaultMaterial_m);
		}
		else if (level == 10) {
			Levels[level]->SetMaterial(0, SelectedMaterial_m);
			Levels[level - 1]->SetMaterial(0, DefaultMaterial_m);
		}
		else {
			Levels[level + 1]->SetMaterial(0, DefaultMaterial_m);
			Levels[level]->SetMaterial(0, SelectedMaterial_m);
			Levels[level - 1]->SetMaterial(0, DefaultMaterial_m);
		}
		
	}

}

void ALevelSelector::ChangeLevel_Mouse(int32 level) {
	
	for (int i = 0; i < 11; i++) {
		Levels[i]->SetMaterial(0, DefaultMaterial_m);
	}
	Levels[level]->SetMaterial(0, SelectedMaterial_m);

}



void ALevelSelector::SpawnStar(int32 level, int32 stars) {
	
	int32 ArrayStartingPos = ((level) * 3)-3;
	int32 ArrayEndPos = ArrayStartingPos + stars;

	if (stars == 1) {
		LevelStars[ArrayStartingPos]->SetVisibility(true);
	}
	else if (stars == 2) {
		LevelStars[ArrayStartingPos]->SetVisibility(true);
		LevelStars[ArrayStartingPos+1]->SetVisibility(true);

		LevelStars[ArrayStartingPos + 1]->SetRelativeLocation(FVector(LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().X - 40, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Y, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Z));
		LevelStars[ArrayStartingPos]->SetRelativeLocation(FVector(LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().X + 40, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Y, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Z));
	
	}
	else if (stars == 3) {
		
			LevelStars[ArrayStartingPos + 1]->SetVisibility(true);
			LevelStars[ArrayStartingPos + 2]->SetVisibility(true);
			LevelStars[ArrayStartingPos]->SetVisibility(true);

			LevelStars[ArrayStartingPos + 2]->SetRelativeLocation(FVector(LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().X - 80, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Y, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Z));
			LevelStars[ArrayStartingPos + 1]->SetRelativeLocation(FVector(LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().X, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Y, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Z));
			LevelStars[ArrayStartingPos]->SetRelativeLocation(FVector(LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().X + 80, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Y, LevelStars[ArrayStartingPos]->GetRelativeTransform().GetLocation().Z));
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(ArrayStartingPos));
		
	}
	


}