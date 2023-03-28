// Fill out your copyright notice in the Description page of Project Settings.


#include "reobj.h"

// Sets default values
Areobj::Areobj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void Areobj::setupMesh() {
	StaticMeshComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), TEXT("Static Renderer "));
	if (StaticMeshComponent) {
		StaticMeshComponent->RegisterComponent();
		StaticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		StaticMeshComponent->CreationMethod = EComponentCreationMethod::Instance;
		if (staticmesh) {
			StaticMeshComponent->SetStaticMesh(staticmesh);
		}
	}
}

void Areobj::spawnNewChar() {

	//AMyActor* NewMyActor = GetWorld()->SpawnActor<AMyActor>();

	
}
// Called when the game starts or when spawned
void Areobj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Areobj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

