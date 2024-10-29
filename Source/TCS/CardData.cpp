
#include "CardData.h"

void UCardData::ApplyEffect_Implementation(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("%s: 기본 카드 효과가 적용되었습니다. (별도 효과 없음)"), *CardName);
}