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
	FString TriggerCondition; // 비밀 카드 발동 조건 설명

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Secret")
	int32 EffectDescription; // 비밀 카드의 효과 설명
};
