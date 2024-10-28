// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "SpellCardData.generated.h"

/**
 * 
 */
UCLASS()
class TCS_API USpellCardData : public UCardData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell")
	FString EffectDescription; // 마법 효과 설명
};
