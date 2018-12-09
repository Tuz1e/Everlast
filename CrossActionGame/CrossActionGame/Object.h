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
	void SetEntityObject(unsigned aTxtrIndex, unsigned aSheetIndex, TextureContainer * aTxtrContainer);
	void AddEntityObject(unsigned anEntityIndex, unsigned aTxtrIndex, unsigned aSheetIndex, TextureContainer *aTxtrContainer);
	//void Break();

	int myEntityAmount;
	std::vector<Entity*> myEntities;

	float myBrokenFlag;
};

#endif 