// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	ADeck();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
	TArray<ACard*> Cards;

	// �� �����ϴ� �Լ�
	void ShuffleDeck();

	// ������ ī�带 ��ο��Ͽ� ���п� �߰��ϴ� �Լ�
	ACard* DrawCard(class AHand* PlayerHand);

	// �̸��� ���� Ư�� ī�带 ã�� �Լ�
	ACard* FindCardByName(const FString& Name) const;

	// ���� ���� ���¸� ����ϴ� ������ �Լ�
	void PrintDeckInfo() const;
};
