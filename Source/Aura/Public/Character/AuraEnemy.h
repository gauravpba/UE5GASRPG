// Copyright Gaurav Prativadi

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase , public IEnemyInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	
	/**Enemy Interface**/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/**End Enemy Interface**/

	/** Combat Interface**/
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface**/
protected:
	
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "CharacterClassDefaults")
	int32 Level = 1;
	
};
