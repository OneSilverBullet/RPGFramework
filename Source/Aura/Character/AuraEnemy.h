// Silver Gamer

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "../Interface/EnemiesInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemiesInterface
{
	GENERATED_BODY()
	
public:
	virtual void Highlight() override;
	virtual void UnHighlight() override;

	AAuraEnemy();

};
