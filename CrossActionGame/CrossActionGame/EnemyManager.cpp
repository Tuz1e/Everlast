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
	for (size_t i = 0; i < Randomize(6, 10); i++)
	{
		GetEnemy((EnemyTypes)Randomize(0, EnemyTypes::SIZE)); //-1 because of "Size"
		myEnemies[i]->Initialize();
		myEnemies[i]->SetPosition(sf::Vector2f(Randomize(100.0f, 1000.0f), Randomize(100.0f, 550.0f)));
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
		if (!myEnemies[i]->GetAliveFlag()) 
		{
			RemoveAt(myEnemies, i);
			return;
		}
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
		case EnemyTypes::SKW:
			myEnemies.push_back(new SkeletonWarrior());
			break;
		case EnemyTypes::MiniSKW:
			myEnemies.push_back(new MiniSkeletonWarrior());
			break;
	}
}
