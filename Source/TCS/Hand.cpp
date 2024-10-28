#include "Hand.h"
#include "Card.h"
#include "CardData.h"

AHand::AHand()
{
	PrimaryActorTick.bCanEverTick = true; // ������ �ð��� ȿ�� ������Ʈ ƽ Ȱ��ȭ
	MaxHandSize = 7;
}

bool AHand::AddCardToHand(ACard* NewCard)
{
	if (NewCard && !IsHandFull())
	{
		CardsInHand.Add(NewCard);
		ArrangeCardsInHand(); // ���� ī�� ��ġ ����
		return true;
	}
	return false;
}

bool AHand::RemoveCardFromHand(ACard* CardToRemove)
{
	if (CardToRemove && CardsInHand.Contains(CardToRemove))
	{
		CardsInHand.Remove(CardToRemove);
		ArrangeCardsInHand();
		return true;
	}
	return false;
}

bool AHand::IsHandFull() const
{
	return CardsInHand.Num() >= MaxHandSize;
}

void AHand::ArrangeCardsInHand()
{
	// ������ ī�带 ȭ�鿡 ���� ���� ��ġ�ϴ� ���� ����
	const float CardSpacing = 100.0f; // ī�� ����
	const FVector StartPosition = FVector(-CardSpacing * CardsInHand.Num() / 2, 0, 0);

	for (int32 i = 0; i < CardsInHand.Num(); ++i)
	{
		if (CardsInHand[i])
		{
			FVector NewPosition = StartPosition + FVector(i * CardSpacing, 0, 0);
			CardsInHand[i]->SetActorLocation(NewPosition);
		}
	}
}

void AHand::PrintHandInfo() const
{
	UE_LOG(LogTemp, Log, TEXT("Hand contains %d cards:"), CardsInHand.Num());
	for (const ACard* Card : CardsInHand)
	{
		if (Card && Card->CardData)
		{
			UE_LOG(LogTemp, Log, TEXT(" - %s (Mana Cost: %d)"), *Card->CardData->CardName,
				Card->CardData->ManaCost);
		}
	}
}