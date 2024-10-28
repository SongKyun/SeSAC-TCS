// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardData.generated.h"

// UCardData Ŭ������ ī���� �����͸� �����ϴ� ������ �����Դϴ�.
// ī���� �̸�, �������, ���ݷ�, ü��, Ÿ��, �̹��� �� �⺻ �Ӽ��� ����
UENUM(BlueprintType)
enum class ECardType : uint8 {
	Minion,		// ���� ī��
	Spell,		// ���� ī��
	Secret,		// ��� ī��
	Weapon,		// ���� ī��
	HeroPower	// ���� �ɷ� ī��
};
 
UCLASS()
class TCS_API UCardData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	int32 ManaCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	ECardType CardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	UTexture2D* CardImage;
};
