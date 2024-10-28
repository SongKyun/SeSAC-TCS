#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hand.generated.h"

class ACard;
UCLASS()
class TCS_API AHand : public AActor
{
	GENERATED_BODY()
	
public:	
	AHand();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hand")
	TArray<ACard*> CardsInHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hand")
	int32 MaxHandSize;

	// 손패에 카드를 추가하는 함수
	bool AddCardToHand(ACard* NewCard);

	// 손패에서 특정 카드를 제거하는 함수
	bool RemoveCardFromHand(ACard* CardToRemove);

	// 손패가 가득 찼는지 확인하는 함수
	bool IsHandFull() const;

	// 손패의 카드를 시각적으로 정리하는 함수
	void ArrangeCardsInHand();

	// 손패의 현재 상태를 출력하는 디버깅용 함수
	void PrintHandInfo() const;
};
