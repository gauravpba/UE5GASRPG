// Copyright Gaurav Prativadi


#include "AbilitySystem/Data/AuraAttributeInfo.h"

FAttributeInfo UAuraAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag,
	bool bLogNotFound) const
{
	for (const FAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find Info for attribute tag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
	}
	return FAttributeInfo();
}
