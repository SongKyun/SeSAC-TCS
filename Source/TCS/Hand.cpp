#include "Hand.h"
#include "Card.h"
#include "CardData.h"

AHand::AHand()
{
	PrimaryActorTick.bCanEverTick = true; // 손패의 시각적 효과 업데이트 틱 활성화
	MaxHandSize = 7;
}

bool AHand::AddCardToHand(ACard* NewCard)
{
	if (NewCard && !IsHandFull())
	{
		CardsInHand.Add(NewCard);
		ArrangeCardsInHand(); // 손패 카드 배치 갱신
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
	// 손패의 카드를 화면에 보기 좋게 배치하는 로직 구현
	const float CardSpacing = 100.0f; // 카드 간격
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