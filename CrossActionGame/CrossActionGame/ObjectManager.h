#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Object.h"
#include "Barrel.h"

enum ObjectTypes
{
	BARREL,

	LENGTH
};

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float & aDeltaTime, const sf::RectangleShape &aHitbox, const sf::Vector2f & aVelocity, bool aPickupFlag);
	void Render(sf::RenderWindow &aWindow);
	std::vector<Object*> GetObjects();

private:
	void GetObject(ObjectTypes anObject);
	std::vector<Object*> myObjects;
};

#endif