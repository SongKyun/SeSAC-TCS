#include "SecretCardData.h"

bool USecretCardData::IsConditionMet(const FString& EventName) const
{
	// ��� ī���� ������ EventName���� üũ
	if (EventName == "HeroAttacked" && CardName == "Explosive Trap")
	{
		return true;
	}
	if (EventName == "MinionSummoned" && CardName == "Snake Trap")
	{
		return true;
	}

	// �߰� ������ ���⿡ �ۼ�
	return false;
}

void USecretCardData::ActivateSecret(AActor* Target)
{
	// ��� ī���� ���� ȿ���� ���⿡ ����
	switch (EffectType)
	{
	case ESecretEffectType::DamageEnemyHero:
		if (Target)
		{
			// �� �������� ����Ʈ���Ʈ��ŭ ���ظ� ����
			// �α�
			// Target->TakeDamage(EffectAmount, ...);
		}
		break;

		//...

	default:
		// �α�
		break;
	}
}
