// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "SecretCardData.generated.h"

/**
 * 
 */
UCLASS()
class TCS_API USecretCardData : public UCardData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	FString TriggerCondition; // ��� ī�� �ߵ� ���� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	int32 EffectDescription; // ��� ī���� ȿ�� ����
};
