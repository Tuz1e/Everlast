#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Object.h"

#define OBJECT_BARREL 0

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void LoadContent(TextureContainer &aTxtrContainer);
	void Update(float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);
	void CreateObject
	(
		Textures *aTexture,
		const sf::Vector2f &aPosition,
		const sf::Vector2f &aSpeed,
		sf::Vector2f aScale = sf::Vector2f(1.0f, 1.0f)
	);
	void SetObjectAnimation(int anObjectIndex, int aRowCount, int aColumnCount, int aFrameCount, int aFramerate);

	std::vector<Object*> myObjects;
};

#endif