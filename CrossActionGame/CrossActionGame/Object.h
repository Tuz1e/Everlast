#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"

class Object : public Entity
{
public:
	Object();
	~Object();

	void LoadContent(TextureContainer *aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow &aWindow) override;
	//void Break();

	std::map<int, Entity*> myEntities;

	float myBrokenFlag;
};

#endif 