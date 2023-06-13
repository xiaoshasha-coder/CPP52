// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FirstBluePrint.h"

#include <string>

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPP_FirstBluePrint::ACPP_FirstBluePrint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArrayInt.Emplace(10);
	ArrayInt.Emplace(0);
	ArrayInt.Emplace(0);
	ArrayInt.Emplace(36);

}

// Called when the game starts or when spawned
void ACPP_FirstBluePrint::BeginPlay()
{
	Super::BeginPlay();

	if (boolVar)
	{
		UE_LOG(LogTemp,Error,TEXT("真"));	
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("假"));	
	}
	
	
}

// Called every frame
void ACPP_FirstBluePrint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

