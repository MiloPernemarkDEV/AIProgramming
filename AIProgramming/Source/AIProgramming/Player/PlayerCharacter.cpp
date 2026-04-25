#include "AIProgramming/Player/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h" 
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "../GameUtil/InputPriorities.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
		
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent()); 
	check(SpringArm->GetAttachParent() == GetCapsuleComponent());	
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(SpringArm);
	check(Camera->GetAttachParent() != nullptr);
	
	/* Deprecated
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));
	PlayerMesh->SetupAttachment(GetCapsuleComponent());
	check(PlayerMesh->GetAttachParent() == GetCapsuleComponent());
	UE_LOG(LogTemp, Log, TEXT("PlayerCharacter constructor created MeshComponent and attached it to the CapsuleComponent"));
	*/
	
	KatanaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Katana Mesh"));
	KatanaMesh->SetupAttachment(GetCapsuleComponent());
	check(KatanaMesh->GetAttachParent() == GetCapsuleComponent());
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		const auto LocalEnhancedSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

		if (UEnhancedInputLocalPlayerSubsystem* Input = LocalEnhancedSubsystem)
		{
			Input->AddMappingContext(InputMappingContext, InputPriorities::BasePriority);
		}
		
		//Todo Add input actions 
	}
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

