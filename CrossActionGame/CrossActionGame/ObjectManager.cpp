#include "pch.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Initialize()
{
	for (size_t i = 0; i < 3; i++)
	{
		GetObject(ObjectTypes::XMARK);
		myObjects[i]->Initialize();
		myObjects[i]->SetPosition(sf::Vector2f(Randomize(100.0f, 1000.0f), Randomize(100.0f, 550.0f)));
	}
	for (size_t i = 3; i < 7; i++)
	{
		GetObject(ObjectTypes::BARREL);
		myObjects[i]->Initialize();
		myObjects[i]->SetPosition(sf::Vector2f(Randomize(100.0f, 1000.0f), Randomize(100.0f, 550.0f)));
	}
}

void ObjectManager::LoadContent(TextureContainer & aTxtrContainer)
{
	for (size_t i = 0; i < myObjects.size(); i++)
	{
		myObjects[i]->LoadContent(aTxtrContainer);
	}
}

void ObjectManager::Update(float & aDeltaTime, const sf::Vector2f &aVelocity)
{
	for (size_t i = 0; i < myObjects.size(); i++)
	{
		myObjects[i]->Update(aDeltaTime, aVelocity);
	}
}

void ObjectManager::Render(sf::RenderWindow & aWindow)
{
	for (size_t i = 0; i < myObjects.size(); i++)
	{
		myObjects[i]->Render(aWindow);
	}
}

std::vector<Object*> ObjectManager::GetObjects()
{
	return myObjects;
}

void ObjectManager::GetObject(ObjectTypes anObject)
{
	switch (anObject)
	{
	case ObjectTypes::BARREL:
		myObjects.push_back(new Barrel());
		break;
	case ObjectTypes::XMARK:
		myObjects.push_back(new XMark());
		break;
	}
}