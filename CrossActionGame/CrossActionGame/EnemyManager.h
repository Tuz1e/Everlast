#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H


#include "Enemy.h"
#include "SkeletonWarrior.h"

enum EnemyTypes 
{
	SKW,

	SIZE
};

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void Initialize();
	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float &aDeltaTime, sf::Vector2f &aPosition);
	void Render(sf::RenderWindow &aWindow);
	std::vector<Enemy*> GetEnemies();

private:
	void GetEnemy(EnemyTypes anEnemy);
	std::vector<Enemy*> myEnemies;
};

#endif