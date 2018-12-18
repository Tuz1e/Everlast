#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "EnemyManager.h"
#include "Player.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void Update(Player *aPlayer, EnemyManager &anEnemyManager);
};

#endif