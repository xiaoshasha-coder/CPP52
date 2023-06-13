 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputActionValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_TestEnhancedIpnutPawn.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class CPP52_API ACPP_TestEnhancedIpnutPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPP_TestEnhancedIpnutPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//必须加上UInputMappingContext/UInputAction的前置引用,否则报错
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "EnhancedInput")
	TObjectPtr<UInputMappingContext>IMC_MyMappingContext;
	//必须加上UInputMappingContext/UInputAction的前置引用,否则报错
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "EnhancedInput")
	TObjectPtr<UInputAction>IA_MyForwardMove;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "EnhancedInput")
	TObjectPtr<UInputAction>IA_MyRightMove;
	
public:
	//触发函数
	void MoveForward(const FInputActionValue &ActionValue);

	void MoveRight(const FInputActionValue &ActionValue);
};
 