#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "SecretCardData.generated.h"

UENUM(BlueprintType)
enum class ESecretEffectType : uint8
{
	DamageEnemyHero,
	SummonMinions,
	CounterSpell,
	ProtectFriendlyHero,
	DamageAllEnemies
};

UCLASS()
class TCS_API USecretCardData : public UCardData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	FString TriggerCondition; // ��� ī�� �ߵ� ���� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	int32 EffectDescription; // ��� ī���� ȿ�� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	ESecretEffectType EffectType; // ��� ī�� ȿ�� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	int32 EffectAmount; // ȿ���� ����

	// ��� �ߵ� ������ �Ǻ��ϴ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "Secret")
	bool IsConditionMet(const FString& EventName) const;

	// ��� �ߵ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "Secret")
	void ActivateSecret(AActor* Target);
};
