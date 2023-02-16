// Fill out your copyright notice in the Description page of Project Settings.


#include "udpsensor.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"
#include "Gameframework/Actor.h"
// Sets default values
FSocket* ListenSocket;
FUdpSocketReceiver* UDPReceiver = nullptr;

Audpsensor::Audpsensor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void Audpsensor::BeginPlay()
{
    Super::BeginPlay();

    // ...

    FString TheIP = "192.168.0.105";
    FString Name = "whogivesa";
    int ThePort = 9005;
    FIPv4Address Addr; // = FIPv4Addre ss(127,0,0,1);
    FIPv4Address::Parse(TheIP, Addr);

    //Create Socket
    FIPv4Endpoint EndPoint(Addr, ThePort);
    UE_LOG(LogTemp, Warning, TEXT("csefffffff %s "), *Addr.ToString());

    //BUFFER SIZE
    int32 BufferSize = 2 * 1024 * 1024;

    ListenSocket = FUdpSocketBuilder(*Name)
        .AsNonBlocking()
        .AsReusable()
        .BoundToAddress(FIPv4Address::Any)
        .BoundToPort(9005)
        .WithReceiveBufferSize(BufferSize);

    FTimespan ThreadWaitTime = FTimespan::FromMilliseconds(100);

    UDPReceiver = new FUdpSocketReceiver(ListenSocket, ThreadWaitTime, TEXT("Udp Receiver"));

    UDPReceiver->OnDataReceived().BindUObject(this, &Audpsensor::RecvData);
    UDPReceiver->Start();
}

void Audpsensor::RecvData(const FArrayReaderPtr& ArrayReadPrt, const FIPv4Endpoint& EndPt)
{
    //FString msg;
    UE_LOG(LogTemp, Warning, TEXT("Data Recived "));

    uint8 data[512];
    FMemory::Memzero(data, 512);
    FMemory::Memcpy(data, ArrayReadPrt->GetData(), ArrayReadPrt->Num());
    FString str = ((const char*)data);
    TArray<FString> Parsed;
    const TCHAR* divide = TEXT(",");
    str.ParseIntoArray(Parsed, divide, false);
    FString  trimed0 = Parsed[0].TrimStartAndEnd();
    FString str_yaw = Parsed[1].TrimStartAndEnd();
    FString str_pitch = Parsed[2].TrimStartAndEnd();
    FString str_roll = Parsed[3].TrimStartAndEnd();

    yaw = FCString::Atoi(*str_yaw);
    pitch = FCString::Atoi(*str_pitch);
    roll = FCString::Atoi(*str_roll);


    //  UE_LOG(LogTemp, Warning, TEXT("%s"), *trimed);


}
void Audpsensor::DestroySocket()
{
    UDPReceiver->Stop();
    ListenSocket->Close();
    UE_LOG(LogTemp, Warning, TEXT("Socket Destroy"));
}

// Called every frame
void Audpsensor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

