#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

// ACard Ŭ������ ���� ī���� �ν��Ͻ��� ��Ÿ���� ���� �Դϴ�.
// UCardData�� ������ �����Ͽ� �� ī���� �Ӽ��� �ʱ�ȭ�ϰ� ������ �Լ��� �����մϴ�.
class UCardData;
UCLASS()
class TCS_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	ACard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
	UCardData* CardData;

	// ī�带 UCardData�� ������ �ʱ�ȭ�ϴ� �Լ�
	void InitializeCard(UCardData* InCardData);

	// ī���� ������ �ֿܼ� ����Ͽ� ������ϴ� �Լ�
	void PrintCardInfo() const;

	// ���� ��η� ī�� �����͸� �ε��ϴ� �Լ� �߰�
	void LoadAndInitializeCard(const FString& AssetPath);
};
