#ifndef SKELETONWARRIOR_H
#define SKELETONWARRIOR_H

#include "Entity.h"

class SkeletonWarrior : public Entity
{
public:
	SkeletonWarrior();
	~SkeletonWarrior();

	void Initialize();
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime, sf::Vector2f &aPosition);
	void Render(sf::RenderWindow &aWindow) override;

	bool WithinRecogDistance(sf::Vector2f aPlayerPos, sf::Vector2f aIsMyPos);

	float myRecogDistance; //Recognition Distance
};

#endif