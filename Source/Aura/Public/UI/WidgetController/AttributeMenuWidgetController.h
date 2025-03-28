// Copyright Gaurav Prativadi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/AuraAttributeInfo.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

struct FAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FAttributeInfo&, Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable,Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UAuraAttributeInfo> AttributeInfo;

private:
	void BroadcastAttribute(const FGameplayTag& Tag, const FGameplayAttribute& Attribute) const;
	
};
