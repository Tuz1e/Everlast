#include "pch.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Initialize()
{
	for (size_t i = 0; i < 1; i++)
	{
		GetEnemy((EnemyTypes)Randomize(0, EnemyTypes::Size-1)); //-1 because of "Size"
		myEnemies[i]->Initialize();
	}
}

void EnemyManager::LoadContent(TextureContainer & aTxtrContainer)
{
	for (size_t i = 0; i < myEnemies.size(); i++)
	{
		myEnemies[i]->LoadContent(aTxtrContainer);
	}
}

/// aPosition = Target Position
void EnemyManager::Update(float & aDeltaTime, sf::Vector2f & aPosition)
{
	for (size_t i = 0; i < myEnemies.size(); i++)
	{
		if (myEnemies[i]->GetHealth() <= 0) 
		{
			PtrDelete(myEnemies[i]);
			RemoveAt(myEnemies, i);
		}
		else 
		{
			myEnemies[i]->Update(aDeltaTime, aPosition);

		}
	}
}

void EnemyManager::Render(sf::RenderWindow & aWindow)
{
	for (size_t i = 0; i < myEnemies.size(); i++)
	{
		myEnemies[i]->Render(aWindow);
	}
}

std::vector<Enemy*> EnemyManager::GetEnemies()
{
	return myEnemies;
}

void EnemyManager::GetEnemy(EnemyTypes anEnemy)
{
	switch (anEnemy) 
	{
	case SKW:
		myEnemies.push_back(new SkeletonWarrior());
		break;
	}
}
