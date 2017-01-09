// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ServerCharacter.generated.h"

UCLASS()
class AServerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AServerCharacter(const FObjectInitializer& ObjectInitializer);

	//!< APawn
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE void MoveForward(float Value) { if (Value != 0.0f) { AddMovementInput(GetActorForwardVector(), Value); } }
	FORCEINLINE void MoveRight(float Value) { if (Value != 0.0f) { AddMovementInput(GetActorRightVector(), Value); } }
	FORCEINLINE void StartJump() { Jump(); }
	FORCEINLINE void EndJump() { StopJumping(); }
	FORCEINLINE void StartCrouch() { Crouch(); }
	FORCEINLINE void EndCrouch() { UnCrouch(); }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* CameraComp;
};
