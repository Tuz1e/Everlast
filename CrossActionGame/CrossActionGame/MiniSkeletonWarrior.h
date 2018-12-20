#ifndef MINISKELETONWARRIOR_H
#define MINISKELETONWARRIOR_H

#include "Enemy.h"

class MiniSkeletonWarrior : public Enemy
{
public:
	MiniSkeletonWarrior();
	~MiniSkeletonWarrior();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float &aDeltaTime, sf::Vector2f &aPosition);
	void Render(sf::RenderWindow &aWindow);
};

#endif