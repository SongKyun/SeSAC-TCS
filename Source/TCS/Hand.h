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

	// ���п� ī�带 �߰��ϴ� �Լ�
	bool AddCardToHand(ACard* NewCard);

	// ���п��� Ư�� ī�带 �����ϴ� �Լ�
	bool RemoveCardFromHand(ACard* CardToRemove);

	// ���а� ���� á���� Ȯ���ϴ� �Լ�
	bool IsHandFull() const;

	// ������ ī�带 �ð������� �����ϴ� �Լ�
	void ArrangeCardsInHand();

	// ������ ���� ���¸� ����ϴ� ������ �Լ�
	void PrintHandInfo() const;
};
