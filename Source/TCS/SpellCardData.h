// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "SpellCardData.generated.h"

// 효과 유형 정의 열거형
UENUM(BlueprintType)
enum class ESpellEffectType : uint8
{
	Damage,
	Heal,
	Buff,
	Debuff
};
// 타겟 유형 정의 열거형
UENUM(BlueprintType)
enum class ESpellTargetType : uint8
{
	SingleEnemy,
	SingleAlly,
	AllEnemies,
	AllAllies,
	Self
};

UCLASS()
class TCS_API USpellCardData : public UCardData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	FString EffectDescription; // 마법 효과 설명

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	ESpellEffectType EffectType; // 효과 유형 (피해, 회복 등)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	ESpellTargetType TargetType; // 타겟 유형 (단일 적, 전체 아군 등)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	int32 EffectAmount; // 효과의 강도 (피해량, 회복량 등)

	virtual void ApplyEffect_Implementation(AActor* Target) override;

protected:
	void ApplyDamegeEffect(AActor* Target);
	void ApplyHealEffect(AActor* Target);
	void ApplyBuffEffect(AActor* Target);
	void ApplyDebuffEffect(AActor* Target);
};
