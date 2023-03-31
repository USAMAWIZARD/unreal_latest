// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"
#include "udpsensor.generated.h"

UCLASS()
class GAMEDAMO_API Audpsensor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Audpsensor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 float roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "pitch")
		 float yaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "yaw")
		 float pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "fire")
		bool fire = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "run")
		int run = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable, Category = "destroyfunction")
		static void DestroySocket();
	virtual void RecvData(const FArrayReaderPtr& ArrayReadPrt, const FIPv4Endpoint& EndPt);

};
