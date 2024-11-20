// Silver Gamer


#include "AuraEnemy.h"

void AAuraEnemy::Highlight()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(252);
	
	GetWeapon()->SetRenderCustomDepth(true);
	GetWeapon()->SetCustomDepthStencilValue(252);
}

void AAuraEnemy::UnHighlight()
{
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->SetCustomDepthStencilValue(0);

	GetWeapon()->SetRenderCustomDepth(false);
	GetWeapon()->SetCustomDepthStencilValue(0);
}

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}
