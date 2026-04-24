#include "AIProgramming/Player/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h" 

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
		
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent()); 
	check(SpringArm->GetAttachParent() == GetCapsuleComponent());	
	UE_LOG(LogTemp, Log, TEXT("PlayerCharacter constructor created SpringArmComponent: SpringArm and attached it to the capsule component"));
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(SpringArm);
	check(Camera->GetAttachParent() != nullptr);
	UE_LOG(LogTemp, Log, TEXT("PlayerCharacter constructor created CameraComponent: Camera and attached it to the SpringArm"));
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

