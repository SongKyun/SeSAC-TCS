// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "HeroPowerCardData.generated.h"

/**
 * 
 */
UCLASS()
class TCS_API UHeroPowerCardData : public UCardData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HeroPower")
	FString EffectDescription; // 영웅 능력 효과 설명
};
