#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

#define IDLE 0
#define RUN 1

class Player : public Entity
{
public:
	Player();
	~Player();

	void LoadContent(TextureContainer *aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;

	int myIdleCounter;
	float myAnimationSpeed;
};

#endif