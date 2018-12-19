#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Object.h"
#include "Barrel.h"
#include "XMark.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float & aDeltaTime, const sf::Vector2f &aVelocity);
	void Render(sf::RenderWindow &aWindow);
	std::vector<Object*> GetObjects();

private:
	void GetObject(ObjectTypes anObject);

	std::vector<Object*> myObjects;
};

#endif