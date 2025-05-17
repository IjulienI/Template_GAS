// GAS Template by Julien SOUM. Github : https://github.com/IjulienI

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Templater_GAS/GAS/GPreprocesor.h"
#include "BaseAttributeSet.generated.h"

	
UCLASS()
class TEMPLATER_GAS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	//--Constructor--
	UBaseAttributeSet();

	//--Attributes--

	ATTRIBUTE_INIT(UBaseAttributeSet);

	//Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health", ReplicatedUsing= OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(Health)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health", ReplicatedUsing= OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(MaxHealth)

protected:
	//--ReplicationNotifies--

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	

	//--AttributeChange--

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;


	//--GameplayEffectExecution--

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	
};
