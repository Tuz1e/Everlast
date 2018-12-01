#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void LoadContent(TextureContainer *aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;

	std::map<int, sf::Texture*> mySpriteSheets;

	int myIdleCounter;
	float myAnimationSpeed;

	bool myIdleFlag;
};

#endif