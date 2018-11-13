#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void LoadContent(sf::Texture *aTexture) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;

	bool myAnimateFlag;
};

#endif