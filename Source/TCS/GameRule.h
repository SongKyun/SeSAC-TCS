// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// 게임의 Phase를 정의하는 전역 열거형
UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	GameStart,
	TurnStart,
	CardDraw,
	SummonMinion,
	CastSpell,
	TurnEnd,
	GameEnd
};

class TCS_API GameRule
{
public:
	GameRule();
	~GameRule();
};
