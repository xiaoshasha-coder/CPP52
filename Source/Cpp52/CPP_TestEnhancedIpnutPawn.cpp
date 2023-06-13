// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TestEnhancedIpnutPawn.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"



// Sets default values
ACPP_TestEnhancedIpnutPawn::ACPP_TestEnhancedIpnutPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
//不在C++设置玩家0,就在蓝图设置;如果这个Pawn不是玩家0就会崩溃
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ACPP_TestEnhancedIpnutPawn::BeginPlay()
{
	Super::BeginPlay();

	

	
	
}

// Called every frame
void ACPP_TestEnhancedIpnutPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_TestEnhancedIpnutPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
//添加输入映射想下文
	if(APlayerController* PC = CastChecked<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_MyMappingContext, 0);
		}
	}
	//绑定触发函数
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if(IA_MyForwardMove)
		{
			EnhancedInputComponent->BindAction(IA_MyForwardMove, ETriggerEvent::Triggered, this, &ACPP_TestEnhancedIpnutPawn::MoveForward);
		}
		if(IA_MyRightMove)
		{
			EnhancedInputComponent->BindAction(IA_MyRightMove, ETriggerEvent::Triggered, this, &ACPP_TestEnhancedIpnutPawn::MoveRight);
		}

	}
}
//实现绑定函数
void ACPP_TestEnhancedIpnutPawn::MoveForward(const FInputActionValue& ActionValue)
{
	FVector WorldDirection = UKismetMathLibrary::GetForwardVector(FRotator(0.f,0.f,GetControlRotation().Yaw));
	AddMovementInput(WorldDirection,ActionValue.GetMagnitude(),false);
}

void ACPP_TestEnhancedIpnutPawn::MoveRight(const FInputActionValue& ActionValue)
{
	AddMovementInput(GetActorRightVector(),ActionValue.GetMagnitude(),false);
}

