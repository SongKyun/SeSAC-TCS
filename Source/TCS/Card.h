// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

// ACard 클래스는 개별 카드의 인스턴스를 나타내는 액터 입니다.
// UCardData의 정보를 참조하여 각 카드의 속성을 초기화하고 디버깅용 함수를 포함합니다.
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

	// 카드를 UCardData의 정보로 초기화하는 함수
	void InitializeCard(UCardData* InCardData);

	// 카드의 정보를 콘솔에 출력하여 디버깅하는 함수
	void PrintCardInfo() const;
};
