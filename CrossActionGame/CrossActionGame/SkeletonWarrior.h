#ifndef SKELETONWARRIOR_H
#define SKELETONWARRIOR_H

#include "Entity.h"

#define WALK 0

class SkeletonWarrior : public Entity
{
public:
	SkeletonWarrior();
	~SkeletonWarrior();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;
};

#endif