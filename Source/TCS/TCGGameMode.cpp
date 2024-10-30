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

// Phase �� ó�� �Լ���

void ATCGGameMode::HandleGameStartPhase()
{
	// ���� �� �İ� ī�� ����, ���� ���� �� �ʱ�ȭ �۾� ����

	// �� ���� �� ȿ�� �ߵ�
	OnTurnStart.Broadcast();

	// ���� Phase�� ��ȯ
	SetCurrentPhase(EGamePhase::TurnStart);
}

void ATCGGameMode::HandleTurnStartPhase()
{
	// ���� ���� ����, "�� ���� ��" ȿ�� �ߵ� �� ó��

	SetCurrentPhase(EGamePhase::CardDraw); // ī�� ��ο�� �̵�
}

void ATCGGameMode::HandleCardDrawPhase()
{
	// ī�� ��ο� ó��

	// ī�尡 10�� �̻��� �� ���, Ż�� ó�� ��
	SetCurrentPhase(EGamePhase::SummonMinion); // �ϼ��� ��ȯ���� �̵�
}

void ATCGGameMode::HandleSummonMinionPhase()
{
	// �ϼ��� ��ȯ �� ȿ�� �ߵ� ó�� (������ �Լ� ��)

	SetCurrentPhase(EGamePhase::CastSpell); // �ֹ� �������� �̵�
}

// HandleTurnEndPhase() �Լ�����
// OnturnEnd.Broadcast();

// ���