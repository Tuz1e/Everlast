#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Enemy.h"
#include "Player.h"
#include "Object.h"
#include "Instance.h"

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
	void Update(Player *aPlayer, std::vector<Enemy*> someEnemies, std::vector<Object*> someObjects, Instance &anInstance, Locale &aLocale);
	bool GetOpenPortalFlag();
	bool GetNextLocaleFlag();
	void SetOpenPortalFlag(bool aStatement);
	void SetNextLocaleFlag(bool aStatement);
	
private:
	int myXBarrelAmount;
	bool
		myOpenPortalFlag,
		myNextLocaleFlag;
};

#endif