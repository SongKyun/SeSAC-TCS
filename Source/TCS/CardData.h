#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardData.generated.h"

// UCardData 클래스는 카드의 데이터를 정의하는 데이터 에셋입니다.
// 카드의 이름, 마나비용, 공격력, 체력, 타입, 이미지 등 기본 속성을 포함
// 
// 캐스팅하면 ENUM 을 쓸 필요가 없기에 지워준다.
//UENUM(BlueprintType)
//enum class ECardType : uint8 {
//	Minion,		// 몬스터 카드
//	Spell,		// 마법 카드
//	Secret,		// 비밀 카드
//	Weapon,		// 무기 카드
//	HeroPower	// 영웅 능력 카드
//};

UCLASS()
class TCS_API UCardData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	int32 ManaCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	int32 Health;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	//ECardType CardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card")
	UTexture2D* CardImage;

	// 카드 효과를 적용하는 함수 자식 클래스에서 재정의 가능
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Effect")
	void ApplyEffect(AActor* Target);

	virtual void ApplyEffect_Implementation(AActor* Target);
};
