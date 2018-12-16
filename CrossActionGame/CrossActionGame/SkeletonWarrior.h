#ifndef SKELETONWARRIOR_H
#define SKELETONWARRIOR_H

#include "Enemy.h"

class SkeletonWarrior : public Enemy
{
public:
	SkeletonWarrior();
	~SkeletonWarrior();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime, sf::Vector2f &aPosition) override;
	void Render(sf::RenderWindow &aWindow) override;

};

#endif