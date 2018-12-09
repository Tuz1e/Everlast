#include "pch.h"
#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
	for (Entity* entityptr : myEntities)
	{
		PtrDelete(entityptr);
	}
	printf("\nDeleted ObjectEntityPointers");
}

void Object::LoadContent(TextureContainer * aTxtrContainer)
{
	SetEntityObject(BARREL, 0, aTxtrContainer);
	AddEntityObject(0, BARREL_BROKEN, 1, aTxtrContainer);

	for (size_t i = 0; i < myEntities.size(); i++)
	{
		myEntities[i]->myPosition = sf::Vector2f(100, 100);
	}

	myEntities[0]->mySprite.SetTexture(myEntities[0]->GetSpriteSheets()[0]->myTexture);
	myEntities[0]->mySprite.SetScale(3.0f, 3.0f);
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
	std::cout << "Object Count: " << myEntities.size() << std::endl;
	for (size_t i = 0; i < myEntities.size(); i++)
	{
		std::cout << "\n X: " << myEntities[i]->GetPosition().x << " Y: " << myEntities[i]->GetPosition().y << std::endl;
		myEntities[i]->mySprite.UpdateAnimation
		(
			aDeltaTime,
			myPosition,
			true
		);
	}
}

void Object::Render(sf::RenderWindow & aWindow)
{
	for (size_t i = 0; i < myEntities.size(); i++)
	{
		myEntities[i]->mySprite.Render(aWindow);
	}
}

void Object::SetEntityObject(unsigned aTxtrIndex, unsigned aSheetIndex, TextureContainer * aTxtrContainer)
{
	myEntities.push_back(new Entity());
	int tempValue = myEntities.size() - 1;
	myEntities[tempValue]->SetSpriteSheet(aTxtrIndex, aSheetIndex, aTxtrContainer);
	myEntities[tempValue]->mySprite.SetPosition(0, 0);
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