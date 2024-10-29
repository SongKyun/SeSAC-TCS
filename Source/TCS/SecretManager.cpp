#include "SecretManager.h"
#include "SecretCardData.h"

void ASecretManager::CheckAndTriggerSecrets(FString EventName, AActor* Target)
{
	// ActiveSecrets �迭�� ����� ��� ��� ī�带 ��ȸ�ϸ鼭 �ϳ� �� Secret�� �Ҵ���
	for (USecretCardData* Secret : ActiveSecrets)
	{
		// ���� �˻� �� ��� ī�尡 nullptr�� �ƴϰ�
		// IsconditionsMet �Լ��� ���� �־��� EventName ������ �����ϴ��� Ȯ��
		if (Secret && Secret->IsConditionMet(EventName)) // Secret && null üũ �κ�
		{
			Secret->ActivateSecret(Target); // ȣ�� �� Ȱ��ȭ
			ActiveSecrets.Remove(Secret); // Ȱ��ȭ ī�� ����
			break; // ������ �����ϴ� ù ��� ī�� �ߵ� �� ����
		}
	}
}