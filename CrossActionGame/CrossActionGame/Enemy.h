#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

//For enemy specific things
class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	virtual void Update(float &aDeltaTime, sf::Vector2f &aPosition);

protected:
	bool myTargetAcquired;
	sf::Vector2f myDirection;
	float myRecogDistance; //Recognition Distance
	int myHitDistance;
};

#endif