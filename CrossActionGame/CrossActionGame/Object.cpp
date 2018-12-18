#include "pch.h"
#include "Object.h"
#include <math.h>


Object::Object()
{
}


Object::~Object()
{
}

void Object::Update(float & aDeltaTime, const sf::RectangleShape &aHitbox, const sf::Vector2f & aVelocity, bool aPickupFlag)
{
}

void Object::CalcMove(float &aDeltaTime, const sf::Vector2f & aVelocity)
{
	//Friction is none existant in this scenario.
	//Testing out a little physics, hopefully I got it right, anyway, movement should work.
	//myVelocity = sf::Vector2f(0.0f, 0.0f);
	//myArea = mySprite.GetTexture()->getSize().x*mySprite.GetTexture()->getSize().y;
	//if (myMass > 0.0f) 
	//{
	//	if (aVelocity.x != 0.0f) 
	//	{
	//		myVelocity.x += sqrt((2 * (myMass*myAcceleration)) / (myDensity * myDrag*myArea));
	//		if (aVelocity.x < 0.0f) 
	//		{
	//			myVelocity.x *= -1;
	//		}
	//	}
	//	if (aVelocity.y != 0) 
	//	{
	//		myVelocity.y += sqrt((2 * (myMass*myAcceleration)) / (myDensity * myDrag*myArea));
	//		if (aVelocity.y < 0.0f)
	//		{
	//			myVelocity.y *= -1;
	//		}
	//	}
	//}
	//else if (myMass == 0.0f)
	//{
	//	myVelocity += (aVelocity * myAcceleration);
	//}
	//else if (myMass < 0.0f) 
	//{
	//	//lul, why tf do you want negative mass? heh
	//	//I won't even bother doing this rn, I don't need it lul
	//}
	myPosition += aVelocity * aDeltaTime;
}