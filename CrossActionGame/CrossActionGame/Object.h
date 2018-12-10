#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"

#define BARREL_OBJECT 0

class Object
{
public:
	Object();
	~Object();

	void LoadContent(TextureContainer *aTxtrContainer);
	void Update(float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);
	void SetEntityObject(unsigned aTxtrIndex, unsigned aSpriteSheetIndex, unsigned anIndex, TextureContainer * aTxtrContainer);
	void AddEntityObject(unsigned anEntityIndex, unsigned aTxtrIndex, unsigned aSheetIndex, TextureContainer *aTxtrContainer);

	int myEntityAmount;
	std::vector<Entity*> myEntities;
};

#endif 