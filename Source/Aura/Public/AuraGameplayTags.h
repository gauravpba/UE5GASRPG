// Copyright Gaurav Prativadi

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WorldPartition/ContentBundle/ContentBundleEditorSubsystemInterface.h"

/**
 *  Aura Gameplay Tags
 *
 *  Singleton containing native Gameplay Tags
 */
struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	/** Primary Attributes*/
	FGameplayTag Attribute_Primary_Strength;
	FGameplayTag Attribute_Primary_Intelligence;
	FGameplayTag Attribute_Primary_Resilience;
	FGameplayTag Attribute_Primary_Vigor;
	/** End Primary Attributes*/
	
	/** Secondary Attributes*/
	FGameplayTag Attribute_Secondary_Armor;
	FGameplayTag Attribute_Secondary_ArmorPenetration;
	FGameplayTag Attribute_Secondary_BlockChance;
	FGameplayTag Attribute_Secondary_CriticalHitChance;
	FGameplayTag Attribute_Secondary_CriticalHitDamage;
	FGameplayTag Attribute_Secondary_CriticalHitResistance;
	FGameplayTag Attribute_Secondary_HealthRegeneration;
	FGameplayTag Attribute_Secondary_ManaRegeneration;
	FGameplayTag Attribute_Secondary_MaxHealth;
	FGameplayTag Attribute_Secondary_MaxMana;
	/** End Secondary Attributes*/
	
	/** Vital Attributes*/
	FGameplayTag Attribute_Vital_Heath;
	FGameplayTag Attribute_Vital_Mana;
	/** End Vital Attributes*/

	/** Input */
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
	/** End Input */
	
private:
	static FAuraGameplayTags GameplayTags;
	
};