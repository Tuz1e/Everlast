#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Enemy.h"
#include "Player.h"
#include "Object.h"

/*
	Could send Entitys Velocity with objects SetPickedUpFlag but that is irrelevant since
	there are no plans on including objects and enemies in the same locale.
*/

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void Initialize();
	void Update(Player *aPlayer, std::vector<Enemy*> someEnemies, std::vector<Object*> someObjects, Locale &aLocale);
	
private:
	int myXBarrelAmount;
	bool myOpenPortalFlag;
};

#endif