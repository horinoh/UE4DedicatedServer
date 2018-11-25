// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4DedicatedServer.h"
#include "ServerCharacter.h"

AServerCharacter::AServerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	const auto CapsuleComp = GetCapsuleComponent();
	if (nullptr != CapsuleComp)
	{
		SpringArmComp = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("SpringArmComp"));
		if (nullptr != SpringArmComp)
		{
			SpringArmComp->SetupAttachment(CapsuleComp);
			SpringArmComp->bUsePawnControlRotation = true;
			SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 100.0f, 50.0f), FRotator(-20.0f, 0.0f, 0.0f));

			CameraComp = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("Camera"));
			if (nullptr != CameraComp)
			{
				CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
				CameraComp->bUsePawnControlRotation = false;
			}
		}

		CapsuleComp->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
		CapsuleComp->bLightAttachmentsAsGroup = true;
	}

	const auto SkelMeshComp = GetMesh();
	if (nullptr != SkelMeshComp)
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("SkeletalMesh'/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin.SK_Mannequin'"));
		if (SkeletalMesh.Succeeded())
		{
			SkelMeshComp->SetSkeletalMesh(SkeletalMesh.Object);
		}
		SkelMeshComp->SetRelativeLocationAndRotation(FVector::UpVector * -90.0f, FRotator(0.0f, -90.0f, 0.0f));

		SkelMeshComp->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;

		SkelMeshComp->bReceivesDecals = false;

		SkelMeshComp->SetCollisionObjectType(ECC_Pawn);
		SkelMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SkelMeshComp->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

		static ConstructorHelpers::FObjectFinder<UClass> AnimBPClass(TEXT("Class'/Game/AnimStarterPack/UE4ASP_HeroTPP_AnimBlueprint.UE4ASP_HeroTPP_AnimBlueprint_C'"));
		if (AnimBPClass.Succeeded())
		{
			SkelMeshComp->SetAnimInstanceClass(AnimBPClass.Object);
		}
	}

	const auto MovementComp = GetCharacterMovement();
	if (nullptr != MovementComp)
	{
		MovementComp->bCrouchMaintainsBaseLocation = true;
		MovementComp->bMaintainHorizontalGroundVelocity = false;

		MovementComp->GetNavAgentPropertiesRef().bCanCrouch = true;
	}
}

void AServerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (nullptr != PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &AServerCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AServerCharacter::MoveRight);
		PlayerInputComponent->BindAxis("Turn", this, &AServerCharacter::AddControllerYawInput);
		PlayerInputComponent->BindAxis("LookUp", this, &AServerCharacter::AddControllerPitchInput);

		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AServerCharacter::StartJump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &AServerCharacter::EndJump);
		PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AServerCharacter::StartCrouch);
		PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AServerCharacter::EndCrouch);
	}
}