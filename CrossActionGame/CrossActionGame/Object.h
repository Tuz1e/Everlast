#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "Player.h"

enum ObjectTypes
{
	BARREL,
	XMARK,
	PORTAL,

	LENGTH
};

//For object specific things
class Object : public Entity
{
public:
	Object();
	~Object();

	virtual void Update(float & aDeltaTime, const sf::Vector2f & aVelocity);
	virtual void CalcMove(float &aDeltaTime, const sf::Vector2f &aVelocity);
	virtual void SetPickedUpFlag(bool aStatement);
	virtual bool GetPickedUpFlag();
	virtual bool GetPickupFlag();
	virtual ObjectTypes GetType();

protected:
	bool
		myPickupFlag = false, //True, if object is supposed to be picked up
		myPickedUpFlag = false; //True, if player is pressing the pickup-key
	ObjectTypes myObjType;

	//float
	//	myMass = 0.0f,
	//	myAcceleration = 1.0f,
	//	myDrag = 0.9, // 0.9 is actually the drag coefficient of a bike
	//	myDensity = 1.0f,
	//	myArea = 1.0f; //m^2

};

#endif