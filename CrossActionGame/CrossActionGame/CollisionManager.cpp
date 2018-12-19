#include "pch.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::Initialize()
{
}

void CollisionManager::Update(Player *aPlayer, std::vector<Enemy*> someEnemies, std::vector<Object*> someObjects, Instance &anInstance, Locale &aLocale)
{
	for (size_t i = 0; i < someEnemies.size(); i++)
	{
		if (someEnemies[i]->GetExistingFlag())
		{
			if (aPlayer->GetAttackingFlag())
			{
				if (aPlayer->GetWeaponBB().getGlobalBounds().intersects(someEnemies[i]->GetSprite().GetSprite().getGlobalBounds()))
				{
					someEnemies[i]->HealthModifier(aPlayer->GetDamage() * -1); //*-1 Makes the number negative, hence making the enemy take damage.
				}
			}

			if (someEnemies[i]->GetAttackingFlag())
			{
				if (someEnemies[i]->GetWeaponBB().getGlobalBounds().intersects(aPlayer->GetHitbox().getGlobalBounds()))
				{
					aPlayer->HealthModifier(someEnemies[i]->GetDamage() * -1); //*-1 Makes the number negative, hence making the enemy take damage.
				}
			}
		}
	}

	for (size_t i = 0; i < someObjects.size(); i++)
	{
		if (aPlayer->GetPickupFlag())
		{
			if (someObjects[i]->GetPickupFlag())
			{
				if (aPlayer->GetWeaponBB().getGlobalBounds().intersects(someObjects[i]->GetHitbox().getGlobalBounds())) 
				{
					someObjects[i]->SetPickedUpFlag(true);
				}
				else 
				{
					someObjects[i]->SetPickedUpFlag(false);
				}
			}
		}
		else 
		{
			someObjects[i]->SetPickedUpFlag(false);
		}
	}

	if (aLocale == Locale::PUZZLE_00) 
	{
		if (!myOpenPortalFlag) 
		{
			myXBarrelAmount = 0;
			for (size_t i = 0; i < someObjects.size(); i++)
			{
				for (size_t j = 0; j < someObjects.size(); j++)
				{
					if (someObjects[i]->GetType() == ObjectTypes::BARREL && someObjects[j]->GetType() == ObjectTypes::XMARK)
					{
						if (someObjects[j]->GetHitbox().getGlobalBounds().intersects(someObjects[i]->GetHitbox().getGlobalBounds()))
						{
							myXBarrelAmount++;
						}
					}
				}
			}
			if (myXBarrelAmount >= 3)
			{
				printf("Puzzle Solved!");
				myOpenPortalFlag = true;
			}
		}
	}

	if (myOpenPortalFlag || aLocale == Locale::START)
	{
		if (aPlayer->GetHitbox().getGlobalBounds().intersects(anInstance.GetHitbox().getGlobalBounds()))
		{
			myNextLocaleFlag = true;
		}
	}
}

bool CollisionManager::GetOpenPortalFlag()
{
	return myOpenPortalFlag;
}

bool CollisionManager::GetNextLocaleFlag()
{
	return myNextLocaleFlag;
}

void CollisionManager::SetOpenPortalFlag(bool aStatement)
{
	myOpenPortalFlag = aStatement;
}

void CollisionManager::SetNextLocaleFlag(bool aStatement)
{
	myNextLocaleFlag = aStatement;
}
