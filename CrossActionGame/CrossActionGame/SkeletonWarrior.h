#ifndef SKELETONWARRIOR_H
#define SKELETONWARRIOR_H

#include "Enemy.h"

class SkeletonWarrior : public Enemy
{
public:
	SkeletonWarrior();
	~SkeletonWarrior();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float &aDeltaTime, sf::Vector2f &aPosition);
	void Render(sf::RenderWindow &aWindow);

};

#endif