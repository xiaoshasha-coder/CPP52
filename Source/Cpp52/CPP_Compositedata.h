// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPP_Compositedata.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EDirectEnum:uint8
{
  East UMETA(DispalyerName = "东"),
  West UMETA(DispalyerName = "西"),
  South UMETA(DispalyerName = "南"),
  North UMETA(DispalyerName = "北")
};


USTRUCT(BlueprintType)
struct FPersonInfoStruct
{
 GENERATED_BODY();
 UPROPERTY(EditAnywhere,BlueprintReadWrite)
 FString Name;
 UPROPERTY(EditAnywhere,BlueprintReadWrite)
 int32 Age;
 UPROPERTY(EditAnywhere,BlueprintReadWrite)
 bool bIsMan;
 
};
