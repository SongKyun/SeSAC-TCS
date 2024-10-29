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

	// ��� ī�� ����Ʈ
	// ��ü ��� X -> �����߿� ����� ����� �迭
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Secret")
	TArray<USecretCardData*> ActiveSecrets;

	// ��������Ʈ ���� (�̺�Ʈ ��� �ߵ�)
	UPROPERTY(BlueprintAssignable, Category = "Secret Events")
	FOnHeroAttacked OnHeroAttacked;

	UPROPERTY(BlueprintAssignable, Category = "Secret Events")
	FOnMinionSummoned OnMinionSummoned;

	UPROPERTY(BlueprintAssignable, Category = "Secret Events")
	FOnManaCostCardPlayed OnManaCostCardPlayed;

	// ��� ī�� ���� �˻� �Լ�
	UFUNCTION()
	void CheckAndTriggerSecrets(FString EventName, AActor* Target);
};
