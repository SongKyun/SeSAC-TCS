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
	FString TriggerCondition; // 비밀 카드 발동 조건 설명

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	int32 EffectDescription; // 비밀 카드의 효과 설명

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	ESecretEffectType EffectType; // 비밀 카드 효과 유형

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	int32 EffectAmount; // 효과의 강도

	// 비밀 발동 조건을 판별하는 함수
	UFUNCTION(BlueprintCallable, Category = "Secret")
	bool IsConditionMet(const FString& EventName) const;

	// 비밀 발동 함수
	UFUNCTION(BlueprintCallable, Category = "Secret")
	void ActivateSecret(AActor* Target);
};
