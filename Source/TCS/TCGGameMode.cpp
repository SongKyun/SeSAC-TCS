// Fill out your copyright notice in the Description page of Project Settings.


#include "TCGGameMode.h"
#include "GameRule.h"

EGamePhase ATCGGameMode::GetCurrentPhase() const
{
	return CurrentPhase;
}

void ATCGGameMode::SetCurrentPhase(EGamePhase NewPhase)
{
	if (CurrentPhase != NewPhase)
	{
		CurrentPhase = NewPhase;

		switch (CurrentPhase)
		{
		case EGamePhase::GameStart:
			HandleGameStartPhase();
			break;

		case EGamePhase::TurnStart:
			HandleTurnStartPhase();
			break;

		case EGamePhase::CardDraw:
			HandleCardDrawPhase();
			break;

		case EGamePhase::SummonMinion:
			HandleSummonMinionPhase();
			break;

		default:
			break;
		}
	}
}

// Phase 별 처리 함수들

void ATCGGameMode::HandleGameStartPhase()
{
	// 선공 및 후공 카드 설정, 동전 제공 등 초기화 작업 수행

	// 턴 시작 시 효과 발동
	OnTurnStart.Broadcast();

	// 다음 Phase로 전환
	SetCurrentPhase(EGamePhase::TurnStart);
}

void ATCGGameMode::HandleTurnStartPhase()
{
	// 마나 수정 충전, "턴 시작 시" 효과 발동 등 처리

	SetCurrentPhase(EGamePhase::CardDraw); // 카드 드로우로 이동
}

void ATCGGameMode::HandleCardDrawPhase()
{
	// 카드 드로우 처리

	// 카드가 10장 이상일 때 폐기, 탈진 처리 등
	SetCurrentPhase(EGamePhase::SummonMinion); // 하수인 소환으로 이동
}

void ATCGGameMode::HandleSummonMinionPhase()
{
	// 하수인 소환 시 효과 발동 처리 (전투의 함성 등)

	SetCurrentPhase(EGamePhase::CastSpell); // 주문 시전으로 이동
}

// HandleTurnEndPhase() 함수에서
// OnturnEnd.Broadcast();

// 등등