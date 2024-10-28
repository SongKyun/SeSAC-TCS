// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "CardData.h"
#include "Hand.h"

// Sets default values
ACard::ACard()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ACard::InitializeCard(UCardData* InCardData)
{
	CardData = InCardData;
	// 필요한 경우 초기화 시, CardData에서 속성을 복사
}

void ACard::PrintCardInfo() const
{
	if (CardData)
	{
		UE_LOG(LogTemp, Log, TEXT("Card Name : %s, Mana Cost: %d, Attack Power: %d, Health: %d"),
			*CardData->CardName, CardData->ManaCost, CardData->AttackPower, CardData->Health);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Card Data is not initialized"));
	}
}



