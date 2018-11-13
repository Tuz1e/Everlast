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
		myTextures[TILE_00]->loadFromFile(TILE_TEXTURE_00); //Load Tile Texture
		std::cout << "Loaded Textures." << std::endl;
	}
	catch (std::string e)
	{
		std::cout << "Unable to load Textures: " << e << std::endl;
	}
}

TextureContainer::~TextureContainer()
{
}

sf::Texture *TextureContainer::GetTexture(unsigned anIndex)
{
	return myTextures.at(anIndex);
}