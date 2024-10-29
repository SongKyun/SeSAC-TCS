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
		// �α�
		break;
	}
}
// 1������ ����
void USpellCardData::ApplyDamegeEffect(AActor* Target)
{
	switch (TargetType)
	{
	case ESpellTargetType::SingleEnemy:
		// ���� ������ ���ظ� �����ϴ�.
		if (Target)
		{
			// Target�� EffectAmount��ŭ ���� ����
			// �α�
		}
		break;
	case ESpellTargetType::AllEnemies:
		// ��� ������ ���ظ� ����
		// �α�
		
		// ��� ���� ������� EffectAmount ��ŭ ���� ���� ���� �߰�
		break;
	default:
		// �α�
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



