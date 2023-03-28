// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "reobj.generated.h"

UCLASS()
class GAMEDAMO_API Areobj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Areobj();
	UFUNCTION(BlueprintCallable, Category = "setupmesh")
	void setupMesh();
	UFUNCTION(BlueprintCallable, Category = "setupmesh")
	void spawnNewChar();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "randomCharSpawn")
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "randomConfig")
		UStaticMesh* staticmesh;
};
