// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCardData.h"

void USpellCardData::ApplyEffect_Implementation(AActor* Target)
{
	switch (EffectType)
	{
	case ESpellEffectType::Damage:
		ApplyDamegeEffect(Target);
		break;
	case ESpellEffectType::Heal:
		ApplyHealEffect(Target);
		break;
	case ESpellEffectType::Buff:
		ApplyBuffEffect(Target);
		break;
	case ESpellEffectType::Debuff:
		ApplyDebuffEffect(Target);
		break;
	default:
		// 로그
		break;
	}
}
// 1가지만 구현
void USpellCardData::ApplyDamegeEffect(AActor* Target)
{
	switch (TargetType)
	{
	case ESpellTargetType::SingleEnemy:
		// 단일 적에게 피해를 입힙니다.
		if (Target)
		{
			// Target에 EffectAmount만큼 피해 적용
			// 로그
		}
		break;
	case ESpellTargetType::AllEnemies:
		// 모든 적에게 피해를 입힘
		// 로그
		
		// 모든 적을 대상으로 EffectAmount 만큼 피해 적용 로직 추가
		break;
	default:
		// 로그
		break;
	}
}

void USpellCardData::ApplyHealEffect(AActor* Target)
{
}

void USpellCardData::ApplyBuffEffect(AActor* Target)
{
}

void USpellCardData::ApplyDebuffEffect(AActor* Target)
{
}



