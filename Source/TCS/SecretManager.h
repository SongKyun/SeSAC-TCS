#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SecretManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeroAttacked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMinionSummoned);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnManaCostCardPlayed);

class USecretCardData;
UCLASS()
class TCS_API ASecretManager : public AActor
{
	GENERATED_BODY()
	
public:

	// 비밀 카드 리스트
	// 전체 비밀 X -> 게임중에 생기는 비밀을 배열
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Secret")
	TArray<USecretCardData*> ActiveSecrets;

	// 델리게이트 선언 (이벤트 기반 발동)
	UPROPERTY(BlueprintAssignable, Category = "Secret Events")
	FOnHeroAttacked OnHeroAttacked;

	UPROPERTY(BlueprintAssignable, Category = "Secret Events")
	FOnMinionSummoned OnMinionSummoned;

	UPROPERTY(BlueprintAssignable, Category = "Secret Events")
	FOnManaCostCardPlayed OnManaCostCardPlayed;

	// 비밀 카드 조건 검사 함수
	UFUNCTION()
	void CheckAndTriggerSecrets(FString EventName, AActor* Target);
};
