#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Subscriber.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;
	void Attacking(float &aDeltaTime);


private:
	int myIdleCounter;
	int myAttackAnimationLength;
	bool myPressFlag;
};

#endif