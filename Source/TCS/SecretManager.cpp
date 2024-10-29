#include "SecretManager.h"
#include "SecretCardData.h"

void ASecretManager::CheckAndTriggerSecrets(FString EventName, AActor* Target)
{
	// ActiveSecrets 배열에 저장된 모든 비밀 카드를 순회하면서 하나 씩 Secret에 할당함
	for (USecretCardData* Secret : ActiveSecrets)
	{
		// 조건 검사 각 비밀 카드가 nullptr이 아니고
		// IsconditionsMet 함수를 통해 주어진 EventName 조건을 만족하는지 확인
		if (Secret && Secret->IsConditionMet(EventName)) // Secret && null 체크 부분
		{
			Secret->ActivateSecret(Target); // 호출 및 활성화
			ActiveSecrets.Remove(Secret); // 활성화 카드 제거
			break; // 조건을 만족하는 첫 비밀 카드 발동 후 종료
		}
	}
}