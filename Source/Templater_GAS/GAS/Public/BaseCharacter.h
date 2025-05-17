// GAS Template by Julien SOUM. Github : https://github.com/IjulienI

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"
#include "BaseCharacter.generated.h"

UCLASS()
class TEMPLATER_GAS_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//--AbilitySystemInterface--
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//Blueprint event for UI update
	UFUNCTION(BlueprintImplementableEvent, Category = "Health")
	void OnHealthChanged(float DeltaValue, const FGameplayTagContainer& EventTag);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//--Attributes--	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", Replicated, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", Replicated, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBaseAttributeSet> AttributeSet;

	void InitilizeAttributes();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//--AttributesChanged--
	
	void HandleHealthChanged(const FOnAttributeChangeData& Data);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
