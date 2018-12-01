#include "pch.h"
#include "TextureContainer.h"

TextureContainer::TextureContainer()
{
	for (size_t i = 0; i < 2; i++)
	{
		myTextures.push_back(new sf::Texture());
	}

	try
	{
		myTextures[PLAYER_RUN]->loadFromFile(PLAYER_RUN_TEXTURE); //Load player run texture
		myTextures[PLAYER_IDLE]->loadFromFile(PLAYER_IDLE_TEXTURE); //Load player idle texture
		printf("\nLoaded textures.");
	}
	catch (std::string e)
	{
		printf("\nUnable to load textures.");
	}
}

TextureContainer::~TextureContainer()
{
	for (sf::Texture* txtrptr : myTextures)
	{
		txtrptr = nullptr;
		delete[](txtrptr);
	}
	printf("\nRemoved TxtrContainr TxtrPtr.");
}

sf::Texture *TextureContainer::GetTexture(unsigned anIndex)
{
	return myTextures.at(anIndex);
}