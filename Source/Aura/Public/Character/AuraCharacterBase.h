// Copyright Gaurav Prativadi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "MotionWarpingComponent.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UAuraAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter , public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet ;}

	virtual FVector GetCombatSocketLocation() override;
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY( EditAnywhere, Category= "Combat" )
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY( EditAnywhere, Category = "Combat" )
	FName WeaponTipSocketName;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, const float Level) const;
		
	void InitializeDefaultAttributes() const;

	void AddCharacterAbilities() const;
	
private:
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;	


};
