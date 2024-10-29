// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "SpellCardData.generated.h"

// ȿ�� ���� ���� ������
UENUM(BlueprintType)
enum class ESpellEffectType : uint8
{
	Damage,
	Heal,
	Buff,
	Debuff
};
// Ÿ�� ���� ���� ������
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
	FString EffectDescription; // ���� ȿ�� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	ESpellEffectType EffectType; // ȿ�� ���� (����, ȸ�� ��)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	ESpellTargetType TargetType; // Ÿ�� ���� (���� ��, ��ü �Ʊ� ��)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	int32 EffectAmount; // ȿ���� ���� (���ط�, ȸ���� ��)

	virtual void ApplyEffect_Implementation(AActor* Target) override;

protected:
	void ApplyDamegeEffect(AActor* Target);
	void ApplyHealEffect(AActor* Target);
	void ApplyBuffEffect(AActor* Target);
	void ApplyDebuffEffect(AActor* Target);
};
