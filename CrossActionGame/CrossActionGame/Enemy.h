#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

//TODO: Create more enemies

//For enemy specific things
class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	virtual void Update(float &aDeltaTime, sf::Vector2f &aPosition);
	virtual bool *GetExistingFlag();
	virtual void SetExistingFlag(bool *aStatement);

protected:
	bool 
		myTargetAcquired,
		*myExistingFlag = false;
	sf::Vector2f myDirection;
	float myRecogDistance; //Recognition Distance
	int myHitDistance,
		myAnimateLength;
	
};

#endif