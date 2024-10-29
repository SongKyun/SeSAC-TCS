#include "SecretCardData.h"

bool USecretCardData::IsConditionMet(const FString& EventName) const
{
	// 비밀 카드의 조건을 EventName으로 체크
	if (EventName == "HeroAttacked" && CardName == "Explosive Trap")
	{
		return true;
	}
	if (EventName == "MinionSummoned" && CardName == "Snake Trap")
	{
		return true;
	}

	// 추가 조건을 여기에 작성
	return false;
}

void USecretCardData::ActivateSecret(AActor* Target)
{
	// 비밀 카드의 고유 효과를 여기에 구현
	switch (EffectType)
	{
	case ESecretEffectType::DamageEnemyHero:
		if (Target)
		{
			// 적 영웅에게 이펙트어마운트만큼 피해를 입힘
			// 로그
			// Target->TakeDamage(EffectAmount, ...);
		}
		break;

		//...

	default:
		// 로그
		break;
	}
}
