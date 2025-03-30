// Copyright Gaurav Prativadi


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"


void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	const bool bIsServer = HasAuthority(&ActivationInfo);
	if (!bIsServer) return;
	
	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		APawn* InstigatingPawn = Cast<APawn>(GetOwningActorFromActorInfo());

		// TODO: Set projectile rotation
		
		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
        		ProjectileClass,
        		SpawnTransform,
        		GetOwningActorFromActorInfo(),
        		InstigatingPawn,
        		ESpawnActorCollisionHandlingMethod::AlwaysSpawn );

		// TODO: Give projectile a gameplay effect spec for causing damage.
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}
