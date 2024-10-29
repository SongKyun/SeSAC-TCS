// Fill out your copyright notice in the Description page of Project Settings.


#include "MinionCardData.h"

void UMinionCardData::ApplyEffect_Implementation(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("Minion Card Effect - Name : %s, Attack : %d, Health : %d"), *CardName, AttackPower, Health);

	switch (EffectType)
	{
	case EMinionEffectType::Battlecry:
		ApplyBattlecryEffect(Target);
		break;

	// �߰� ���̽���

	default:
		// �α�
		break;
	}
}

void UMinionCardData::ApplyBattlecryEffect(AActor* Target)
{

}

