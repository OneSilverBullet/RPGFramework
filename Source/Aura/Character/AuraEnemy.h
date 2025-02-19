// Silver Gamer

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "AbilitySystemInterface.h"
#include "../Interface/EnemiesInterface.h"
#include "AuraEnemy.generated.h"


class UAuraAbilitySystemComponent;
class UAuraAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemiesInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	virtual void Highlight() override;
	virtual void UnHighlight() override;

	AAuraEnemy();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAuraAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAuraAttributeSet> AttributeSet;

};
