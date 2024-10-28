#include "Card.h"
#include "CardData.h"
#include "Hand.h"
#include "MinionCardData.h"

ACard::ACard()
{
	PrimaryActorTick.bCanEverTick = false;

	FString AssetPath = "/Game/MinionCardData.MinionCardData";
	LoadAndInitializeCard(AssetPath);
}

void ACard::InitializeCard(UCardData* InCardData)
{
	CardData = InCardData;
	// �ʿ��� ��� �ʱ�ȭ ��, CardData���� �Ӽ��� ����
}

void ACard::PrintCardInfo() const
{
	/*if (CardData)
	{
		UE_LOG(LogTemp, Log, TEXT("Card Name : %s, Mana Cost: %d, Attack Power: %d, Health: %d"),
			*CardData->CardName, CardData->ManaCost, CardData->AttackPower, CardData->Health);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Card Data is not initialized"));
	}*/

	if (!CardData)
	{
		UE_LOG(LogTemp, Warning, TEXT("Card Data is not initialized"));
		return;
	}

	if (const UMinionCardData* MinionCard = Cast<UMinionCardData>(CardData))
	{
		UE_LOG(LogTemp, Log, TEXT("Minion Card - Name : %s, Mana: %d, Attack: %d, Health: %d"),
			*MinionCard->CardName, MinionCard->ManaCost, MinionCard->AttackPower, MinionCard->Health);
	}

	// ����Ʈ ī�� ����...
}

void ACard::LoadAndInitializeCard(const FString& AssetPath)
{
	// FString�� FSoftObjectPath�� ��ȯ
	FSoftObjectPath SoftObjectPath(AssetPath);
	TSoftObjectPtr<UCardData> CardDataAsset(SoftObjectPath);

	// ���������� �ε��մϴ� (�񵿱� �ε� �ʿ� �� LoadAsync ��� ����)
	if (CardDataAsset.IsValid() || CardDataAsset.LoadSynchronous())
	{
		UCardData* LoadedCardData = CardDataAsset.Get();
		InitializeCard(LoadedCardData); // ī�� ������ �ʱ�ȭ
		UE_LOG(LogTemp, Log, TEXT("Card initialized with data asset: %s"), *LoadedCardData->CardName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load card data from asset path: %s"), *AssetPath);
	}
}

