#ifndef SKELETONWARRIOR_H
#define SKELETONWARRIOR_H

#include "Entity.h"

class SkeletonWarrior : public Entity
{
public:
	SkeletonWarrior();
	~SkeletonWarrior();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime, sf::Vector2f &aPosition);
	void Render(sf::RenderWindow &aWindow) override;
	bool myTargetAcquired;
	sf::Vector2f myDirection;

	float myRecogDistance; //Recognition Distance
	float myHitDistance;
};

#endif