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
	// 필요한 경우 초기화 시, CardData에서 속성을 복사
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

	// 프린트 카드 인포...
}

void ACard::LoadAndInitializeCard(const FString& AssetPath)
{
	// FString을 FSoftObjectPath로 변환
	FSoftObjectPath SoftObjectPath(AssetPath);
	TSoftObjectPtr<UCardData> CardDataAsset(SoftObjectPath);

	// 동기적으로 로드합니다 (비동기 로드 필요 시 LoadAsync 사용 가능)
	if (CardDataAsset.IsValid() || CardDataAsset.LoadSynchronous())
	{
		UCardData* LoadedCardData = CardDataAsset.Get();
		InitializeCard(LoadedCardData); // 카드 데이터 초기화
		UE_LOG(LogTemp, Log, TEXT("Card initialized with data asset: %s"), *LoadedCardData->CardName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load card data from asset path: %s"), *AssetPath);
	}
}

