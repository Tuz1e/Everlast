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

	myEntities[0]->mySprite.SetPosition(sf::Vector2f(250, 250));
	myEntities[0]->mySprite.SetTexture(myEntities[0]->GetSpriteSheets()[0]->myTexture);

	myEntities[0]->mySprite.SetAnimation
	(
		myEntities[0]->GetSpriteSheets()[0]->myRows,
		myEntities[0]->GetSpriteSheets()[0]->myColumns,
		myEntities[0]->GetSpriteSheets()[0]->myFrames,
		4.5f
	);
}

void Object::Update(float & aDeltaTime)
{
	for (size_t i = 0; i < myEntities.size(); i++)
	{
		myEntities[i]->mySprite.UpdateAnimation
		(
			aDeltaTime, 
			myEntities[i]->GetPosition(),
			true
		);
	}
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