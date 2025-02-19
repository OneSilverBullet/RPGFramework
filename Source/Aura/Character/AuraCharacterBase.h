// Silver Gamer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();

	TObjectPtr<USkeletalMeshComponent> GetWeapon() const { return Weapon; }	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;


};
