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

	// 하수인의 고유 효과 타입
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	EMinionEffectType EffectType;

	// 하수인 효과의 강도 또는 수치
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	int32 EffectAmount;

	virtual void ApplyEffect_Implementation(AActor* Target) override;

protected:
	void ApplyBattlecryEffect(AActor* Target);
	// 추가 함수들 ...
};
