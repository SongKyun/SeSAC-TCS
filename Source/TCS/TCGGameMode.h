// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameRule.h"

#include "TCGGameMode.generated.h"

// GameRule.h 로 이동
//UENUM(BlueprintType)
//enum class EGamePhase : uint8
//{
//	GameStart,
//	TurnStart,
//	CardDraw,
//	SummonMinion,
//	CastSpell,
//	TurnEnd,
//	GameEnd
//};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEnd);

UCLASS()
class TCS_API ATCGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Phase에 대한 Getter
	EGamePhase GetCurrentPhase() const;

	// Phase에 대한 Setter (전환 로직 포함)
	void SetCurrentPhase(EGamePhase NewPhase);
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnTurnStart OnTurnStart;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnTurnEnd OnTurnEnd;
	
private:
	// 현재 Phase를 나타내는 변수 (Private로 캡슐화)
	EGamePhase CurrentPhase;

	// Phase별 처리 함수들

	void HandleGameStartPhase();
	void HandleTurnStartPhase();
	void HandleCardDrawPhase();
	void HandleSummonMinionPhase();

	// 등등

};
