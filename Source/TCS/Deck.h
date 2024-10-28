#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deck.generated.h"

class ACard;
UCLASS()
class TCS_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:
	ADeck();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
	TArray<ACard*> Cards;

	// 덱 셔플하는 함수
	void ShuffleDeck();

	// 덱에서 카드를 드로우하여 손패에 추가하는 함수
	ACard* DrawCard(class AHand* PlayerHand);

	// 이름을 통해 특정 카드를 찾는 함수
	ACard* FindCardByName(const FString& Name) const;

	// 덱의 현재 상태를 출력하는 디버깅용 함수
	void PrintDeckInfo() const;
};
