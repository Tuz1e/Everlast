#include "pch.h"
#include "WorldManager.h"
#include "TextureContainer.h"

WorldManager::WorldManager()
{
}

WorldManager::~WorldManager()
{
}

void WorldManager::Initialize()
{
}

void WorldManager::LoadContent(TextureContainer &aContainer, sf::RenderWindow &aWindow, World aLocation)
{
	for (size_t i = 0; i < 25; i++)
	{
		myWorldSprites[i].SetTexture(aTexture);
		myWorldSprites[i].SetScale(3.0f, 3.0f);
		myWorldSprites[i].SetPosition
		(
			sf::Vector2f
			(
			(i == 0) ? 0 : (myWorldSprites[i - 1].GetSprite().getTextureRect().width * i * 3.0f),
				0
			)
		);
	}
}

void WorldManager::Update()
{
}

void WorldManager::Render(sf::RenderWindow & aWindow)
{
	for (size_t i = 0; i < myWorldSprites.size(); i++)
	{
		myWorldSprites[i].Render(aWindow);
	}
}