#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;

	void SetActionState(const float &anAnimationSpeed);

	int myIdleCounter;
};

#endif