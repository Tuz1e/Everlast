#include "pch.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::Update(Player * aPlayer, EnemyManager &anEnemyManager)
{
	for (size_t i = 0; i < anEnemyManager.GetEnemies().size(); i++)
	{
		if (aPlayer->GetAttackingFlag())
		{
			if (aPlayer->GetWeaponBB().getGlobalBounds().intersects(anEnemyManager.GetEnemies()[i]->GetSprite().GetSprite().getGlobalBounds()))
			{
				printf("\nPlayer Hit");
				anEnemyManager.GetEnemies()[i]->HealthModifier(aPlayer->GetDamage() * -1); //*-1 Makes the number negative, hence making the enemy take damage.
			}
		}

		if (anEnemyManager.GetEnemies()[i]->GetAttackingFlag())
		{
			if (anEnemyManager.GetEnemies()[i]->GetWeaponBB().getGlobalBounds().intersects(aPlayer->GetHitbox().getGlobalBounds()))
			{
				printf("\nEnemy Hit");
				aPlayer->HealthModifier(anEnemyManager.GetEnemies()[i]->GetDamage() * -1); //*-1 Makes the number negative, hence making the enemy take damage.
			}
		}
	}
}