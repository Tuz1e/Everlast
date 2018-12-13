#ifndef SKELETONWARRIOR_H
#define SKELETONWARRIOR_H

#include "Entity.h"
#include "Subscriber.h"

class SkeletonWarrior : public Entity, public Subscriber
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

	void ReceiveMessage(const Memorandum &aMemorandum, const MessageType &aMessage) override;

	float myRecogDistance; //Recognition Distance
	float myHitDistance;
};

#endif