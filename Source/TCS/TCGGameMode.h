// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameRule.h"

#include "TCGGameMode.generated.h"

// GameRule.h �� �̵�
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
	// Phase�� ���� Getter
	EGamePhase GetCurrentPhase() const;

	// Phase�� ���� Setter (��ȯ ���� ����)
	void SetCurrentPhase(EGamePhase NewPhase);
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnTurnStart OnTurnStart;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnTurnEnd OnTurnEnd;
	
private:
	// ���� Phase�� ��Ÿ���� ���� (Private�� ĸ��ȭ)
	EGamePhase CurrentPhase;

	// Phase�� ó�� �Լ���

	void HandleGameStartPhase();
	void HandleTurnStartPhase();
	void HandleCardDrawPhase();
	void HandleSummonMinionPhase();

	// ���

};
