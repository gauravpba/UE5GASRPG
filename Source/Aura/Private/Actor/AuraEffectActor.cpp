// Copyright Gaurav Prativadi


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
}


void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent( TargetActor );
	if ( TargetASC == nullptr ) return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle =  TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject( this );
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec( GameplayEffectClass, ActorLevel ,EffectContextHandle );
	TargetASC->ApplyGameplayEffectSpecToSelf( *EffectSpecHandle.Data.Get() );
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	if ( InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap )
	{
		ApplyEffectToTarget (TargetActor, InstantGameplayEffectClass);
	}
	if ( DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap )
	{
		ApplyEffectToTarget (TargetActor, DurationGameplayEffectClass);
	}
	if ( InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap )
	{
		ApplyEffectToTarget (TargetActor, InfiniteGameplayEffectClass);
	}
}

void AAuraEffectActor::EndOverlap(AActor* TargetActor)
{
	if ( InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap )
	{
		ApplyEffectToTarget (TargetActor, InstantGameplayEffectClass);
	}
	if ( DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap )
	{
		ApplyEffectToTarget (TargetActor, DurationGameplayEffectClass);
	}
	if ( InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap )
	{
		ApplyEffectToTarget (TargetActor, InfiniteGameplayEffectClass);
	}
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent( TargetActor );
		if ( !IsValid(TargetASC) ) return;
		TargetASC->RemoveActiveGameplayEffectBySourceEffect(InfiniteGameplayEffectClass, TargetASC , 1);
		
	}
	
}

