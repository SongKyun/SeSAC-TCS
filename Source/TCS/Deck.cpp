// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "Card.h"
#include "CardData.h"
#include "Hand.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ADeck::ShuffleDeck()
{
	const int32 NumCards = Cards.Num();
	for (int32 i = NumCards - 1; i > 0; --i)
	{
		int32 j = FMath::RandRange(0, i);
		if (Cards.IsValidIndex(i) && Cards.IsValidIndex(j))
		{
			Cards.Swap(i, j);
		}
	}
}

ACard* ADeck::DrawCard(AHand* PlayerHand)
{
	if (Cards.Num() > 0)
	{
		ACard* DrawnCard = Cards[0];
		Cards.RemoveAt(0);
		if (PlayerHand && PlayerHand->AddCardToHand(DrawnCard))
		{
			return DrawnCard;
		}
		else
		{
			// 드로우 실패 시 처리 기능 추가
		}
	}
	return nullptr;
}

ACard* ADeck::FindCardByName(const FString& Name) const
{
	for (ACard* Card : Cards)
	{
		if (Card && Card->CardData && Card->CardData->CardName == Name)
		{
			return Card;
		}
	}
	return nullptr;
}

void ADeck::PrintDeckInfo() const
{
	UE_LOG(LogTemp, Log, TEXT("Deck contains %d cards: "), Cards.Num());
	for (const ACard* Card : Cards)
	{
		if (Card && Card->CardData)
		{
			UE_LOG(LogTemp, Log, TEXT(" - %s (Mana Cost : %d)"), *Card->CardData->CardName,
				Card->CardData->ManaCost);
		}
	}
}




