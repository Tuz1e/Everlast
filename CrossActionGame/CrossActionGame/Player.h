#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Subscriber.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void Initialize();
	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);
	void Attacking(float &aDeltaTime);
	sf::Vector2f GetVelocity();
	bool GetPickupFlag();


private:
	int myIdleCounter;
	int myAttackAnimationLength;
	bool myPressFlag,
		myPickupFlag;
};

#endif