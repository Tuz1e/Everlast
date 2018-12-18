#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "Player.h"

//For object specific things
class Object : public Entity
{
public:
	Object();
	~Object();

	virtual void Update(float & aDeltaTime, const sf::RectangleShape &aHitbox, const sf::Vector2f & aVelocity, bool aPickupFlag);
	virtual void CalcMove(float &aDeltaTime, const sf::Vector2f &aVelocity);

	bool myPushedFlag,
		myPickupFlag;

	//float
	//	myMass = 0.0f,
	//	myAcceleration = 1.0f,
	//	myDrag = 0.9, // 0.9 is actually the drag coefficient of a bike
	//	myDensity = 1.0f,
	//	myArea = 1.0f; //m^2

};

#endif