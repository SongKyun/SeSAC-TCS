// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

// ACard Ŭ������ ���� ī���� �ν��Ͻ��� ��Ÿ���� ���� �Դϴ�.
// UCardData�� ������ �����Ͽ� �� ī���� �Ӽ��� �ʱ�ȭ�ϰ� ������ �Լ��� �����մϴ�.
class UCardData;
UCLASS()
class TCS_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
	UCardData* CardData;

	// ī�带 UCardData�� ������ �ʱ�ȭ�ϴ� �Լ�
	void InitializeCard(UCardData* InCardData);

	// ī���� ������ �ֿܼ� ����Ͽ� ������ϴ� �Լ�
	void PrintCardInfo() const;
};
