#include "pch.h"
#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::LoadContent(TextureContainer * aTxtrContainer)
{
	SetEntityObject(BARREL, 0, aTxtrContainer);
	AddEntityObject(0, BARREL_BROKEN, 1, aTxtrContainer);

	//myEntities[0]->SetTexture(myEntities[0]->mySpriteSheets)
	myEntities[0]->SetPosition(sf::Vector2f(250, 250));
}

void Object::Update(float & aDeltaTime)
{
}

void Object::Render(sf::RenderWindow & aWindow)
{
	for (Entity* eptr : myEntities)
	{
		eptr->Render(aWindow);
	}
}

void Object::SetEntityObject(unsigned aTxtrIndex, unsigned aSheetIndex, TextureContainer * aTxtrContainer)
{
	myEntities.push_back(new Entity());

	int tempValue = myEntities.size() - 1;
	myEntities[tempValue]->SetSpriteSheet(aTxtrIndex, aSheetIndex, aTxtrContainer);
}

void Object::AddEntityObject(unsigned anEntityIndex, unsigned aTxtrIndex, unsigned aSheetIndex, TextureContainer * aTxtrContainer)
{
	try
	{
		myEntities[anEntityIndex]->SetSpriteSheet(aTxtrIndex, aSheetIndex, aTxtrContainer);
	}
	catch (...)
	{
		//ErrorMessage("Object.cpp", 40, "Failed AddEntityObject");
	}
}