// Silver Gamer


#include "AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	if (!HitResult.bBlockingHit) return;

	lastActor = currentActor;
	currentActor = Cast<IEnemiesInterface>(HitResult.GetActor());

	if (lastActor == nullptr) {
		if (currentActor != nullptr) {
			currentActor->Highlight();
		}
		else {
			return;
		}
	}
	else {
		if (currentActor == nullptr) {
			lastActor->UnHighlight();
		}
		else {
			if (lastActor != currentActor) {
				lastActor->UnHighlight();
				currentActor->Highlight();
			}
			else
			{
				//pass
			}
		}
	}
}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//assert the aura context is setted
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(subsystem);

	subsystem->AddMappingContext(AuraContext, 0);
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* inputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); 


	inputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);

}

void AAuraPlayerController::Move(const FInputActionValue& Value)
{
	//access X and Y
	const FVector2D InputAxisVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);


	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.X);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.Y);
	}

}

