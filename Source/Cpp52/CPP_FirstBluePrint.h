// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_FirstBluePrint.generated.h"

UCLASS()
class CPP52_API ACPP_FirstBluePrint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_FirstBluePrint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,Category = "AAA",BlueprintReadOnly)
	TArray<int32>ArrayInt;
	UPROPERTY(EditAnywhere,Category = "AAA")
	int32 IntVar;
	UPROPERTY(EditAnywhere,Category = "AAA")
	bool boolVar;

};
