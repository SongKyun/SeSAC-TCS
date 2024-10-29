// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "MinionCardData.generated.h"

UENUM(BlueprintType)
enum class EMinionEffectType : uint8
{
	Battlecry,
	Deathrattle,
	Windfury,
	Taunt,
	DivineShield
};

UCLASS()
class TCS_API UMinionCardData : public UCardData
{
	GENERATED_BODY()
	
public:
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Minion")
	//int32 AttackPower;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Minion")
	//int32 Health;

	// �ϼ����� ���� ȿ�� Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	EMinionEffectType EffectType;

	// �ϼ��� ȿ���� ���� �Ǵ� ��ġ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	int32 EffectAmount;

	virtual void ApplyEffect_Implementation(AActor* Target) override;

protected:
	void ApplyBattlecryEffect(AActor* Target);
	// �߰� �Լ��� ...
};
