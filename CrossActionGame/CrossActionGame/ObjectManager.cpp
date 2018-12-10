#include "pch.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	for (Object* objptr : myObjects)
	{
		objptr->~Object;
		PtrDelete(objptr);
	}
}

void ObjectManager::LoadContent(TextureContainer & aTxtrContainer)
{
	CreateObject(aTxtrContainer.GetTextures(BARREL), sf::Vector2f(100, 100), sf::Vector2f(0, 0), sf::Vector2f(3.0f, 3.0f));
	SetObjectAnimation
	(
		OBJECT_BARREL,
		myObjects[OBJECT_BARREL]->GetTextures()->myRows,
		myObjects[OBJECT_BARREL]->GetTextures()->myColumns,
		myObjects[OBJECT_BARREL]->GetTextures()->myFrames,
		4.5f
	);
}

void ObjectManager::Update(float & aDeltaTime)
{
}

void ObjectManager::Render(sf::RenderWindow & aWindow)
{
	for (Object* objptr : myObjects)
	{
		objptr->Render(aWindow);
	}
}

void ObjectManager::CreateObject(Textures * aTexture, const sf::Vector2f & aPosition, const sf::Vector2f & aSpeed, sf::Vector2f aScale)
{
	myObjects.push_back(new Object(aTexture, aPosition, aSpeed, aScale));
}

void ObjectManager::SetObjectAnimation(int anObjectIndex, int aRowCount, int aColumnCount, int aFrameCount, int aFramerate)
{
	myObjects[anObjectIndex]->SetAnimation(aRowCount, aColumnCount, aFrameCount, aFramerate);
}